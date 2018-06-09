/*
 * Copyright 2018 Fabian Maurer
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <windows.h>
#include <stdio.h>

#include "wine/heap.h"
#include "wine/test.h"

void read_all_from_handle(HANDLE handle, BYTE **str, int *len)
{
    char buffer[4096];
    DWORD bytes_read;
    DWORD length = 0;
    BOOL success;
    BYTE *ret = heap_alloc_zero(1);

    for (;;)
    {
        success = ReadFile(handle, buffer, sizeof(buffer), &bytes_read, NULL);
        if (!success || !bytes_read)
            break;
        ret = heap_realloc(ret, length + bytes_read);
        memcpy((char *)ret + length, buffer, bytes_read);
        length += bytes_read;
    }

    *str = ret;
    *len = length;
}

void write_to_handle(HANDLE handle, const BYTE *str, int len)
{
    DWORD bytes_written_sum = 0;

    do
    {
        DWORD bytes_written;
        WriteFile(handle, str, len, &bytes_written, NULL);
        bytes_written_sum += bytes_written;
    } while (bytes_written_sum < len);
}

void check_find_output(const BYTE *child_output, int child_output_len, const BYTE *out_expected, int out_expected_len, const char *file, int line)
{
    BOOL strings_are_equal;
    char *child_output_copy;
    char *out_expected_copy;
    int i, pos;

    if (child_output_len != out_expected_len)
        strings_are_equal = FALSE;
    else
    {
        strings_are_equal = memcmp(child_output, out_expected, out_expected_len) == 0;
    }

    /* Format strings for debug printing */
    child_output_copy = heap_alloc_zero(child_output_len * 4 + 1);
    out_expected_copy = heap_alloc_zero(out_expected_len * 4 + 1);

    for (i = 0, pos = 0; i < child_output_len; i++)
    {
        if (child_output[i] && child_output[i] != '\r' && child_output[i] < 128)
            child_output_copy[pos++] = child_output[i];
        else
        {
            sprintf(&child_output_copy[pos], "\\x%02x", child_output[i]);
            pos += 4;
        }
    }

    for (i = 0, pos = 0; i < out_expected_len; i++)
    {
        if (out_expected[i] && out_expected[i] != '\r' && out_expected[i] < 128)
            out_expected_copy[pos++] = out_expected[i];
        else
        {
            sprintf(&out_expected_copy[pos], "\\x%02x", out_expected[i]);
            pos += 4;
        }

    }

    todo_wine_if(out_expected_len != 0)
    ok_(file, line)(strings_are_equal, "\n#################### Expected:\n"
                                       "%s\n"
                                       "#################### But got:\n"
                                       "%s\n"
                                       "####################\n",
                                       out_expected_copy, child_output_copy);

    heap_free(child_output_copy);
    heap_free(out_expected_copy);
}

#define run_find_stdin_bytes(commandline, input, out_expected, exitcode_expected) \
        run_find_stdin_(commandline, input, sizeof(input), out_expected, sizeof(out_expected), exitcode_expected, __FILE__, __LINE__)

static void run_find_stdin_(const WCHAR *commandline, const BYTE *input, int input_len, const BYTE *out_expected, int out_expected_len, int exitcode_expected, const char *file, int line)
{
    static const WCHAR find_exe[] = { 'f','i','n','d','.','e','x','e',' ','%','s' };
    HANDLE child_stdin_read;
    HANDLE child_stdout_write;
    HANDLE parent_stdin_write;
    HANDLE parent_stdout_read;
    STARTUPINFOW startup_info = {0};
    SECURITY_ATTRIBUTES security_attributes;
    PROCESS_INFORMATION process_info = {0};
    BYTE *child_output = NULL;
    int child_output_len;
    WCHAR cmd[4096];
    DWORD exitcode;

    security_attributes.nLength = sizeof(SECURITY_ATTRIBUTES);
    security_attributes.bInheritHandle = TRUE;
    security_attributes.lpSecurityDescriptor = NULL;

    CreatePipe(&parent_stdout_read, &child_stdout_write, &security_attributes, 0);
    CreatePipe(&child_stdin_read,   &parent_stdin_write, &security_attributes, 0);

    SetHandleInformation(parent_stdout_read, HANDLE_FLAG_INHERIT, 0);
    SetHandleInformation(parent_stdin_write, HANDLE_FLAG_INHERIT, 0);

    startup_info.cb = sizeof(STARTUPINFOW);
    startup_info.hStdInput = child_stdin_read;
    startup_info.hStdOutput = child_stdout_write;
    startup_info.hStdError = NULL;
    startup_info.dwFlags |= STARTF_USESTDHANDLES;

    wsprintfW(cmd, find_exe, commandline);

    CreateProcessW(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &startup_info, &process_info);
    CloseHandle(child_stdin_read);
    CloseHandle(child_stdout_write);

    write_to_handle(parent_stdin_write, input, input_len);
    CloseHandle(parent_stdin_write);

    read_all_from_handle(parent_stdout_read, &child_output, &child_output_len);
    CloseHandle(parent_stdout_read);

    GetExitCodeProcess(process_info.hProcess, &exitcode);
    CloseHandle(process_info.hProcess);
    CloseHandle(process_info.hThread);

    check_find_output(child_output, child_output_len, out_expected, out_expected_len, file, line);

    todo_wine_if(exitcode_expected  != 0)
    ok_(file, line)(exitcode == exitcode_expected, "Expected exitcode %d, got %d\n", exitcode_expected, exitcode);

    heap_free(child_output);
}

#define run_find_stdin_str(commandline, input, out_expected, exitcode_expected) \
        run_find_stdin_str_(commandline, input, lstrlenA(input), out_expected, lstrlenA(out_expected), exitcode_expected, __FILE__, __LINE__)

static void run_find_stdin_str_(const char *commandline, const char *input, int input_len, const char *out_expected, int out_expected_len, int exitcode_expected, const char *file, int line)
{
    WCHAR *commandlineW;
    int len_commandlineW;

    len_commandlineW = MultiByteToWideChar(CP_UTF8, 0, commandline, -1, 0, 0);
    commandlineW = heap_alloc(len_commandlineW * sizeof(WCHAR));
    MultiByteToWideChar(CP_UTF8, 0, commandline, -1, commandlineW, len_commandlineW);

    run_find_stdin_(commandlineW, (BYTE *)input, lstrlenA(input), (BYTE *)out_expected, lstrlenA(out_expected), exitcode_expected, file, line);

    heap_free(commandlineW);
}

#define run_find_unicode(commandline, input, exitcode_expected) \
        run_find_unicode_(commandline, input, sizeof(input), exitcode_expected, __FILE__, __LINE__)

static void run_find_unicode_(const WCHAR *commandline, const BYTE *input, int input_len, int exitcode_expected, const char* file, int line)
{
    WCHAR buffer[200];
    BYTE expected[200];
    int count_wchar;
    int count_expected;

    count_wchar = MultiByteToWideChar(GetConsoleCP(), 0, (char *)input, input_len, buffer, ARRAY_SIZE(expected));
    count_expected = WideCharToMultiByte(GetConsoleCP(), 0, buffer, count_wchar, (char *)expected, ARRAY_SIZE(expected), NULL, NULL);

    run_find_stdin_(commandline, input, input_len, expected, count_expected, exitcode_expected, file, line);
}

#define run_find_unicode16(commandline, input) \
        run_find_unicode16_(commandline, input, sizeof(input), __FILE__, __LINE__)

static void run_find_unicode16_(const WCHAR *commandline, const BYTE *input, int input_len, const char* file, int line)
{
    BYTE expected[200];
    WCHAR buffer[200];
    int count_expected;
    int buffer_count = 0;
    int i;

    /* Copy utf16le into a WCHAR array, stripping the BOM */
    for (i = 2; i < input_len; i += 2)
    {
        buffer[buffer_count++] = input[i] + (input[i + 1] << 8);
    }

    count_expected = WideCharToMultiByte(GetConsoleCP(), 0, buffer, buffer_count, (char *)expected, ARRAY_SIZE(expected), NULL, NULL);
    run_find_stdin_(commandline, input, input_len, expected, count_expected, 0, file, line);
}

static void test_errors(void)
{
    run_find_stdin_str("",       "", "FIND: Parameter format not correct\r\n", 2);
    run_find_stdin_str("test",   "", "FIND: Parameter format not correct\r\n", 2);
    run_find_stdin_str("\"test", "", "FIND: Parameter format not correct\r\n", 2);
    run_find_stdin_str("\"test\" /XYZ", "", "FIND: Invalid switch\r\n", 2);
}

static void test_singleline_without_switches(void)
{
    run_find_stdin_str("\"\"",      "test",  "",          1);
    run_find_stdin_str("\"test\"",  "",      "",          1);
    run_find_stdin_str("\"test\"",  "test",  "test\r\n",  0);
    run_find_stdin_str("\"test\"",  "test2", "test2\r\n", 0);
    run_find_stdin_str("\"test2\"", "test",  "",          1);
}

static void test_multiline(void)
{
    /* Newline in input shouldn't work */
    run_find_stdin_str("\"t1\r\nt1\"", "t1\r\nt1", "", 1);
    run_find_stdin_str("\"t1\nt1\"",   "t1\nt1",   "", 1);

    /* Newline should always be displayed as \r\n */
    run_find_stdin_str("\"test1\"", "test1\ntest2", "test1\r\n", 0);
    run_find_stdin_str("\"test1\"", "test1\r\ntest2", "test1\r\n", 0);

    /* Test with empty line */
    run_find_stdin_str("\"test1\"", "test1\n\ntest2", "test1\r\n", 0);

    /* Two strings to be found */
    run_find_stdin_str("\"test\"", "junk1\ntest1\ntest2\r\njunk", "test1\r\ntest2\r\n", 0);
}

static const BYTE str_empty[] = {};
static const BYTE str_jap_shiftjis[]      = { 0x8E,0x84,0x82,0xCD,'t','e','s','t','!','\r','\n' };
static const BYTE str_jap_utf8_bom[]      = { 0xEF,0xBB,0xBF,0xE7,0xA7,0x81,0xE3,0x81,0xAF,'j','a','p','t','e','s','t','!','\r','\n' };
static const BYTE str_jap_utf8_nobom[]    = {                0xE7,0xA7,0x81,0xE3,0x81,0xAF,'j','a','p','t','e','s','t','!','\r','\n' };
static const BYTE str_jap_utf16le_bom[]   = { 0xFF,0xFE,0xC1,0x79,0x6F,0x30,'t',0,'e',0,'s',0,'t',0,'!',0,'\r',0,'\n',0 };
static const BYTE str_jap_utf16le_nobom[] = {           0xC1,0x79,0x6F,0x30,'t',0,'e',0,'s',0,'t',0,'!',0 };
static const BYTE str_jap_utf16be_bom[]   = { 0xFE,0xFF,0x79,0xC1,0x30,0x6F,0,'t',0,'e',0,'s',0,'t',0,'!' };
static const BYTE str_jap_utf16be_nobom[] = {           0x79,0xC1,0x30,0x6F,0,'t',0,'e',0,'s',0,'t',0,'!' };
static const BYTE str_rus_utf8_bom[]      = { 0xEF,0xBB,0xBF,0xD0,0xBF,0xD1,0x80,0xD0,0xB8,0xD0,0xB2,0xD0,0xB5,0xD1,0x82,0x20,'t','e','s','t','!','\r','\n' };
static const BYTE str_rus_utf8_nobom[]    = {                0xD0,0xBF,0xD1,0x80,0xD0,0xB8,0xD0,0xB2,0xD0,0xB5,0xD1,0x82,0x20,'t','e','s','t','!','\r','\n' };
static const BYTE str_en_utf8_bom[]       = { 0xEF,0xBB,0xBF,'e','n','t','e','s','t','\r','\n' };
static const BYTE str_en_utf8_nobom[]     = {                't','e','s','t','\r','\n' };

static const WCHAR wstr_quoted_test[] = { '"','t', 'e', 's', 't','"',0 };
static const WCHAR wstr_quoted_watashi_utf8[] = {'"',0xE7,0xA7,0x81,'"' };


static void test_unicode_support(void)
{
    /* Test unicode support on STDIN */

    /* Test UTF-8 BOM */
    run_find_unicode(wstr_quoted_test, str_en_utf8_nobom, 0);
    run_find_unicode(wstr_quoted_test, str_en_utf8_bom,   0);

    /* Test russian character */
    run_find_unicode(wstr_quoted_test, str_rus_utf8_bom,   0);
    run_find_unicode(wstr_quoted_test, str_rus_utf8_nobom, 0);

    /* Test japanese characters */
    run_find_unicode(wstr_quoted_test, str_jap_utf8_nobom,  0);
    run_find_unicode(wstr_quoted_test, str_jap_utf8_bom,    0);
    run_find_unicode(wstr_quoted_test, str_jap_shiftjis,    0);

    /* Test unsupported encodings */
    run_find_stdin_bytes(wstr_quoted_test, str_jap_utf16le_nobom, str_empty, 1);
    run_find_stdin_bytes(wstr_quoted_test, str_jap_utf16be_bom,   str_empty, 1);
    run_find_stdin_bytes(wstr_quoted_test, str_jap_utf16be_nobom, str_empty, 1);

    /* Test utf16le */
    run_find_unicode16(wstr_quoted_test, str_jap_utf16le_bom);

    /* Test unicode search parameter */
    run_find_unicode(wstr_quoted_watashi_utf8, str_empty, 1);
    run_find_unicode(wstr_quoted_watashi_utf8, str_empty, 1);
    run_find_unicode(wstr_quoted_watashi_utf8, str_empty, 1);
}

START_TEST(find)
{
    if (PRIMARYLANGID(GetUserDefaultUILanguage()) != LANG_ENGLISH)
    {
        skip("Error tests only work with english locale.\n");
    }
    else
    {
        test_errors();
    }
    test_singleline_without_switches();
    test_multiline();
    test_unicode_support();
}
