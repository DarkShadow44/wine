/* Unit tests for the task dialog control.
 *
 * Copyright 2017 Fabian Maurer for the Wine project
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

#include <stdarg.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "commctrl.h"

#include "wine/list.h"
#include "wine/test.h"
#include "v6util.h"
#include "msg.h"

#define WM_TD_CALLBACK (WM_APP) /* Custom dummy message to wrap callback notifications */

#define NUM_MSG_SEQUENCES     1
#define TASKDIALOG_SEQ_INDEX  0

#define TEST_NUM_BUTTONS 20 /* Number of custom buttons to test with */

#define ID_START 20 /* Lower IDs might be used by the system */
#define ID_START_BUTTON (ID_START + 0)
#define ID_START_RADIO (ID_START + 1000)

static HRESULT (WINAPI *pTaskDialogIndirect)(const TASKDIALOGCONFIG *, int *, int *, BOOL *);

static struct msg_sequence *sequences[NUM_MSG_SEQUENCES];

/* Message lists to test against */

struct message_send_info
{
    UINT send_message;
    WPARAM send_wparam;
    LPARAM send_lparam;

    BOOL post; /* post instead of send */
    const CHAR *title_target; /* control text, 0 means it's send to the dialog form instead */
};

struct message_info
{
    UINT recv_message; /* Message the callback receives */
    WPARAM recv_wparam;
    LPARAM recv_lparam;

    HRESULT ret; /* Value the callback should return */

    struct message_send_info send[9];  /* Message to send to trigger the next callback message */
};

static const struct message_info *current_message_info;


static const struct message_info mes_return_press_ok[] = {
    { TDN_CREATED, 0, 0, S_OK, {
        { WM_KEYDOWN, VK_RETURN, 0, TRUE },
        { 0 }}},
    { TDN_BUTTON_CLICKED, IDOK, 0, S_OK, {{ 0 }}},
    { 0 }
};

static const struct message_info mes_cancel_button_press[] = {
    { TDN_CREATED, 0, 0, S_OK, {
        { TDM_CLICK_BUTTON, IDOK, 0, TRUE },
        { TDM_CLICK_BUTTON, IDOK, 0, TRUE },
        { TDM_CLICK_BUTTON, IDOK, 0, TRUE },
        { 0 }}},
    { TDN_BUTTON_CLICKED, IDOK, 0, S_FALSE, {{ 0 }}},
    { TDN_BUTTON_CLICKED, IDOK, 0, 0xFF, {{ 0 }}}, /* Random return value tested here */
    { TDN_BUTTON_CLICKED, IDOK, 0, S_OK, {{ 0 }}},
    { 0 }
};

static const struct message_info mes_return_press_custom1[] = {
    { TDN_CREATED, 0, 0, S_OK, {
        { WM_KEYDOWN, VK_RETURN, 0, TRUE },
        { 0 }}},
    { TDN_BUTTON_CLICKED, ID_START_BUTTON, 0, S_OK, {{ 0 }}},
    { 0 }
};

static const struct message_info mes_return_press_custom4[] = {
    { TDN_CREATED, 0, 0, S_OK, {
        { WM_KEYDOWN, VK_RETURN, 0, TRUE },
        { 0 }}},
    { TDN_BUTTON_CLICKED, ID_START_BUTTON + 3, 0, S_OK, {{ 0 }}},
    { 0 }
};

static const struct message_info mes_return_press_retry[] = {
    { TDN_CREATED, 0, 0, S_OK, {
        { WM_KEYDOWN, VK_RETURN, 0, TRUE },
        { 0 }}},
    { TDN_BUTTON_CLICKED, IDRETRY, 0, S_OK, {{ 0 }}},
    { 0 }
};


/* Create a message to test against */
static struct message create_test_message(UINT message, WPARAM wParam, LPARAM lParam)
{
    struct message mes;

    mes.message = WM_TD_CALLBACK;
    mes.id = message;
    mes.flags = sent|wparam|lparam|id;
    mes.wParam = wParam;
    mes.lParam = lParam;

    return mes;
}

/* Our only way to get a button handle, since GetDlgItem and FindWindowEx don't work for the official taskdialog */

static HWND taskdialog_child;
BOOL CALLBACK enum_taskdialog_children_proc(HWND hwnd, LPARAM lParam)
{
    CHAR text[100];
    const CHAR *title = (const CHAR *)lParam;

    GetWindowTextA(hwnd, text, sizeof(text));

    if(lstrcmpA(text, title) == 0)
    {
        taskdialog_child = hwnd;
        return FALSE;
    }

    return TRUE;
}

static HWND get_child_from_title(HWND hwnd_parent, const CHAR *title)
{
    taskdialog_child = NULL;
    EnumChildWindows(hwnd_parent, enum_taskdialog_children_proc, (LPARAM)title);
    return taskdialog_child;
}

#define run_test(info, expect_button, expect_radio, expect_checkbox, seq, context) \
        run_test_(info, expect_button, expect_radio, expect_checkbox, seq, context, \
                  sizeof(seq)/sizeof(seq[0]) - 1 , __FILE__, __LINE__)

void run_test_(TASKDIALOGCONFIG *info, int expect_button, int expect_radio, BOOL expect_checkbox,
               const struct message_info *test_messages, const char* context,
               int test_messages_len, const char *file, int line)
{
    HRESULT ret;
    int ret_button = 0;
    int ret_radio = 0;
    BOOL ret_checkbox = 0;

    struct message *mes, *mes_start;
    int i;

    /* Allocate messages to test against, plus 2 implicit and 1 empty */
    mes_start = mes = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(struct message) * (test_messages_len + 3));

    *mes++ = create_test_message(TDN_DIALOG_CONSTRUCTED, 0, 0); /* Always needed, thus made implicit */
    for(i = 0; i < test_messages_len; i++)
    {
        *mes++ = create_test_message(test_messages[i].recv_message,
                                     test_messages[i].recv_wparam, test_messages[i].recv_lparam);
    }
    *mes++ = create_test_message(TDN_DESTROYED, 0, 0); /* Always needed, thus made implicit */

    current_message_info = test_messages;
    flush_sequences(sequences, NUM_MSG_SEQUENCES);
    ret = pTaskDialogIndirect(info, &ret_button, &ret_radio, &ret_checkbox);

    ok_( file, line)(ret == S_OK, "Expected S_OK, got %x\n", ret);
    ok_sequence_(sequences, TASKDIALOG_SEQ_INDEX, mes_start, context, FALSE, file, line);
    ok_( file, line)(ret_button == expect_button,
                     "Wrong button. Expected %d, got %d\n", expect_button, ret_button);
    ok_( file, line)(ret_radio == expect_radio,
                     "Wrong radio button. Expected %d, got %d\n", expect_radio, ret_radio);
    ok_( file, line)(ret_checkbox == expect_checkbox,
                     "Wrong checkbox state. Expected %d, got %d\n", expect_checkbox, ret_checkbox);

    HeapFree(GetProcessHeap(), 0, mes_start);
}

static LONG_PTR backup_ref_data; /* Copy of dwRefData to test against */

static HRESULT CALLBACK TaskDialogCallbackProc(HWND hwnd, UINT uNotification, WPARAM wParam,
                                               LPARAM lParam, LONG_PTR dwRefData)
{
    struct message msg;

    ok(backup_ref_data == dwRefData, "dwRefData is wrong, expected %lu, got %lu\n", backup_ref_data, dwRefData);

    msg = create_test_message(uNotification, wParam, lParam);
    add_message(sequences, TASKDIALOG_SEQ_INDEX, &msg);

    if(uNotification != TDN_DIALOG_CONSTRUCTED && uNotification != TDN_DESTROYED) /* Skip implicit messages */
    {
        int mes_pos = sequences[TASKDIALOG_SEQ_INDEX]->count - 2; /* Skip implicit message and the current one */
        const struct message_send_info *msg_send = current_message_info[mes_pos].send;
        while(msg_send->send_message)
        {
            if(msg_send->title_target)
            {
                hwnd = get_child_from_title(hwnd, msg_send->title_target);
                ok(hwnd != NULL, "Can't find child window.\n");
            }

            if(msg_send->post)
                PostMessageW(hwnd, msg_send->send_message, msg_send->send_wparam, msg_send->send_lparam);
            else
                SendMessageW(hwnd, msg_send->send_message, msg_send->send_wparam, msg_send->send_lparam);

            msg_send++;
        }

        return current_message_info[mes_pos].ret;
    }

    return S_OK;
}



static TASKDIALOG_BUTTON* buttons_make(void)
{
    static const WCHAR str_format[] = {'%','0','2','d',0};
    static TASKDIALOG_BUTTON buttons[TEST_NUM_BUTTONS];
    static WCHAR titles[TEST_NUM_BUTTONS * 3]; /* Each button has two digits as title, plus null-terminator */
    int i;

    for(i=0; i<TEST_NUM_BUTTONS; i++)
    {
        WCHAR *text = &titles[i * 3];
        wsprintfW(text, str_format, i);

        buttons[i].pszButtonText = text;
        buttons[i].nButtonID = ID_START_BUTTON + i;
    }
    return buttons;
}

static void test_TaskDialogIndirect(void)
{
    TASKDIALOGCONFIG info = {0};
    TASKDIALOG_BUTTON *custom_buttons;
    HRESULT ret;

    custom_buttons = buttons_make();

    ret = pTaskDialogIndirect(NULL, NULL, NULL, NULL);
    ok(ret == E_INVALIDARG, "Expected E_INVALIDARG, got %x\n", ret);

    ret = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(ret == E_INVALIDARG, "Expected E_INVALIDARG, got %x\n", ret);

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = TaskDialogCallbackProc;
    info.lpCallbackData = backup_ref_data = 0x12345678; /* Set data for callback tests */

    run_test(&info, IDOK, 0, FALSE, mes_return_press_ok, "Simple test with parameters null");
    run_test(&info, IDOK, 0, FALSE, mes_cancel_button_press, "Simple test for cancelling button press");

     /* Test nDefaultButton */

    /* Test with all common buttons and invalid default ID */
    info.nDefaultButton = 0; /* Should default to first created button */
    info.dwCommonButtons = TDCBF_OK_BUTTON | TDCBF_YES_BUTTON | TDCBF_NO_BUTTON
                           | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDOK, 0, FALSE, mes_return_press_ok, "");

    /* Test with all common and custom buttons and invalid default ID */
    info.nDefaultButton = 0xff; /* Random ID, should also default to first created button */
    info.cButtons = 10;
    info.pButtons = custom_buttons;
    run_test(&info, ID_START_BUTTON, 0, FALSE, mes_return_press_custom1, "nDefaultButton: all buttons, invalid default");

    /* Test with only custom buttons and invalid default ID */
    info.dwCommonButtons = 0;
    run_test(&info, ID_START_BUTTON, 0, FALSE, mes_return_press_custom1, "nDefaultButton: custom buttons, invalid default");

    /* Test with common and custom buttons and valid default ID */
    info.dwCommonButtons = TDCBF_OK_BUTTON | TDCBF_YES_BUTTON | TDCBF_NO_BUTTON
                               | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    info.nDefaultButton = IDRETRY;
    run_test(&info, IDRETRY, 0, FALSE, mes_return_press_retry, "nDefaultButton: all buttons, valid default 1");

    /* Test with common and custom buttons and valid default ID */
    info.nDefaultButton = ID_START_BUTTON + 3;
    run_test(&info, ID_START_BUTTON + 3, 0, FALSE, mes_return_press_custom4, "nDefaultButton: all buttons, valid default 2");
}

START_TEST(taskdialog)
{
    ULONG_PTR ctx_cookie;
    HANDLE hCtx;
    HINSTANCE hinst;
    void *ptr_ordinal;

    if (!load_v6_module(&ctx_cookie, &hCtx))
        return;

    /* Check if task dialogs are available */
    hinst = LoadLibraryA("comctl32.dll");

    pTaskDialogIndirect = (void *)GetProcAddress(hinst, "TaskDialogIndirect");
    if (!pTaskDialogIndirect)
    {
        win_skip("TaskDialogIndirect not exported by name\n");
        return;
    }

    ptr_ordinal = GetProcAddress(hinst, (const CHAR*)345);
    ok(pTaskDialogIndirect == ptr_ordinal, "got wrong pointer for ordinal 345, %p expected %p\n",
                                            ptr_ordinal, pTaskDialogIndirect);

    init_msg_sequences(sequences, NUM_MSG_SEQUENCES);
    test_TaskDialogIndirect();

    unload_v6_module(ctx_cookie, hCtx);
}
