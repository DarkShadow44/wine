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
#include "shlwapi.h"

#include "wine/heap.h"
#include "wine/test.h"
#include "v6util.h"
#include "msg.h"
#include "resources.h"

#define WM_TD_CALLBACK (WM_APP) /* Custom dummy message to wrap callback notifications */

#define NUM_MSG_SEQUENCES     1
#define TASKDIALOG_SEQ_INDEX  0

#define TEST_NUM_BUTTONS 10 /* Number of custom buttons to test with */

#define ID_START 20 /* Lower IDs might be used by the system */
#define ID_START_BUTTON (ID_START + 0)

static HRESULT (WINAPI *pTaskDialogIndirect)(const TASKDIALOGCONFIG *, int *, int *, BOOL *);
static HRESULT (WINAPI *pTaskDialog)(HWND, HINSTANCE, const WCHAR *, const WCHAR *, const WCHAR *,
        TASKDIALOG_COMMON_BUTTON_FLAGS, const WCHAR *, int *);

static struct msg_sequence *sequences[NUM_MSG_SEQUENCES];

struct message_info
{
    UINT message;
    WPARAM wparam;
    LPARAM lparam;

    HRESULT callback_retval;
    const struct message_info *send;  /* Message to send to trigger the next callback message */
};

static const struct message_info *current_message_info;

/* Messages to send */
static const struct message_info msg_send_return[] =
{
    { WM_KEYDOWN, VK_RETURN, 0 },
    { 0 }
};

/* Messages to test against */
static const struct message_info msg_return_press_ok[] =
{
    { TDN_CREATED,        0,    0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, IDOK, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_yes[] =
{
    { TDN_CREATED,        0,    0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, IDYES, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_no[] =
{
    { TDN_CREATED,        0,    0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, IDNO, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_cancel[] =
{
    { TDN_CREATED,        0,    0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, IDCANCEL, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_retry[] =
{
    { TDN_CREATED,        0,       0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, IDRETRY, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_custom1[] =
{
    { TDN_CREATED,        0,               0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, ID_START_BUTTON, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_custom4[] =
{
    { TDN_CREATED,        0,                   0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, ID_START_BUTTON + 3, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_return_press_custom10[] =
{
    { TDN_CREATED,        0,                   0, S_OK, msg_send_return },
    { TDN_BUTTON_CLICKED, -1, 0, S_OK, NULL },
    { 0 }
};

static const struct message_info msg_send_click_ok[] =
{
    { TDM_CLICK_BUTTON, IDOK, 0 },
    { 0 }
};

static const struct message_info msg_send_f1[] =
{
    { WM_KEYF1, 0, 0, 0},
    { 0 }
};

static const struct message_info msg_got_tdn_help[] =
{
    { TDN_CREATED, 0, 0, S_OK, msg_send_f1 },
    { TDN_HELP, 0, 0, S_OK, msg_send_click_ok },
    { TDN_BUTTON_CLICKED, IDOK, 0, S_OK, NULL },
    { 0 }
};

static void init_test_message(UINT message, WPARAM wParam, LPARAM lParam, struct message *msg)
{
    msg->message = WM_TD_CALLBACK;
    msg->flags = sent|wparam|lparam|id;
    msg->wParam = wParam;
    msg->lParam = lParam;
    msg->id = message;
    msg->stage = 0;
}

#define run_test(info, expect_button, seq, context) \
        run_test_(info, expect_button, seq, context, \
                  sizeof(seq)/sizeof(seq[0]) - 1, __FILE__, __LINE__)

static void run_test_(TASKDIALOGCONFIG *info, int expect_button, const struct message_info *test_messages,
    const char *context, int test_messages_len, const char *file, int line)
{
    struct message *msg, *msg_start;
    int ret_button = 0;
    int ret_radio = 0;
    HRESULT hr;
    int i;

    /* Allocate messages to test against, plus 2 implicit and 1 empty */
    msg_start = msg = heap_alloc_zero(sizeof(*msg) * (test_messages_len + 3));

    /* Always needed, thus made implicit */
    init_test_message(TDN_DIALOG_CONSTRUCTED, 0, 0, msg++);
    for (i = 0; i < test_messages_len; i++)
        init_test_message(test_messages[i].message, test_messages[i].wparam, test_messages[i].lparam, msg++);
    /* Always needed, thus made implicit */
    init_test_message(TDN_DESTROYED, 0, 0, msg++);

    current_message_info = test_messages;
    flush_sequences(sequences, NUM_MSG_SEQUENCES);

    hr = pTaskDialogIndirect(info, &ret_button, &ret_radio, NULL);
    ok_(file, line)(hr == S_OK, "TaskDialogIndirect() failed, got %#x.\n", hr);

    ok_sequence_(sequences, TASKDIALOG_SEQ_INDEX, msg_start, context, FALSE, file, line);
    ok_(file, line)(ret_button == expect_button,
                     "Wrong button. Expected %d, got %d\n", expect_button, ret_button);

    heap_free(msg_start);
}

static const LONG_PTR test_ref_data = 123456;

static HRESULT CALLBACK taskdialog_callback_proc(HWND hwnd, UINT notification,
    WPARAM wParam, LPARAM lParam, LONG_PTR ref_data)
{
    int msg_pos = sequences[TASKDIALOG_SEQ_INDEX]->count - 1; /* Skip implicit message */
    const struct message_info *msg_send;
    struct message msg;

    ok(test_ref_data == ref_data, "Unexpected ref data %lu.\n", ref_data);

    init_test_message(notification, (short)wParam, lParam, &msg);
    add_message(sequences, TASKDIALOG_SEQ_INDEX, &msg);

    if (notification == TDN_DIALOG_CONSTRUCTED || notification == TDN_DESTROYED) /* Skip implicit messages */
        return S_OK;

    msg_send = current_message_info[msg_pos].send;
    for(; msg_send && msg_send->message; msg_send++)
        PostMessageW(hwnd, msg_send->message, msg_send->wparam, msg_send->lparam);

    return current_message_info[msg_pos].callback_retval;
}

static void test_invalid_parameters(void)
{
    TASKDIALOGCONFIG info = { 0 };
    HRESULT hr;

    hr = pTaskDialogIndirect(NULL, NULL, NULL, NULL);
    ok(hr == E_INVALIDARG, "Unexpected return value %#x.\n", hr);

    info.cbSize = 0;
    hr = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(hr == E_INVALIDARG, "Unexpected return value %#x.\n", hr);

    info.cbSize = sizeof(TASKDIALOGCONFIG) - 1;
    hr = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(hr == E_INVALIDARG, "Unexpected return value %#x.\n", hr);

    info.cbSize = sizeof(TASKDIALOGCONFIG) + 1;
    hr = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(hr == E_INVALIDARG, "Unexpected return value %#x.\n", hr);
}

static void test_callback(void)
{
    TASKDIALOGCONFIG info = {0};

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = taskdialog_callback_proc;
    info.lpCallbackData = test_ref_data;

    run_test(&info, IDOK, msg_return_press_ok, "Press VK_RETURN.");
}

static void test_buttons(void)
{
    TASKDIALOGCONFIG info = {0};

    TASKDIALOG_BUTTON custom_buttons[TEST_NUM_BUTTONS];
    const WCHAR button_format[] = {'%','0','2','d',0};
    WCHAR button_titles[TEST_NUM_BUTTONS * 3]; /* Each button has two digits as title, plus null-terminator */
    int i;

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = taskdialog_callback_proc;
    info.lpCallbackData = test_ref_data;

    /* Init custom buttons */
    for (i = 0; i < TEST_NUM_BUTTONS; i++)
    {
        WCHAR *text = &button_titles[i * 3];
        wsprintfW(text, button_format, i);

        custom_buttons[i].pszButtonText = text;
        custom_buttons[i].nButtonID = ID_START_BUTTON + i;
    }
    custom_buttons[TEST_NUM_BUTTONS - 1].nButtonID = -1;

    /* Test nDefaultButton */

    /* Test common buttons with invalid default ID */
    info.nDefaultButton = 0; /* Should default to first created button */
    info.dwCommonButtons = TDCBF_OK_BUTTON | TDCBF_YES_BUTTON | TDCBF_NO_BUTTON
            | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDOK, msg_return_press_ok, "default button: unset default");
    info.dwCommonButtons = TDCBF_YES_BUTTON | TDCBF_NO_BUTTON
            | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDYES, msg_return_press_yes, "default button: unset default");
    info.dwCommonButtons = TDCBF_NO_BUTTON | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDNO, msg_return_press_no, "default button: unset default");
    info.dwCommonButtons = TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDRETRY, msg_return_press_retry, "default button: unset default");
    info.dwCommonButtons = TDCBF_CANCEL_BUTTON | TDCBF_CLOSE_BUTTON;
    run_test(&info, IDCANCEL, msg_return_press_cancel, "default button: unset default");

    /* Test with all common and custom buttons and invalid default ID */
    info.nDefaultButton = 0xff; /* Random ID, should also default to first created button */
    info.cButtons = TEST_NUM_BUTTONS;
    info.pButtons = custom_buttons;
    run_test(&info, ID_START_BUTTON, msg_return_press_custom1, "default button: invalid default, with common buttons - 1");

    info.nDefaultButton = -1; /* Should work despite button ID -1 */
    run_test(&info, -1, msg_return_press_custom10, "default button: invalid default, with common buttons - 2");

    info.nDefaultButton = -2; /* Should also default to first created button */
    run_test(&info, ID_START_BUTTON, msg_return_press_custom1, "default button: invalid default, with common buttons - 3");

    /* Test with only custom buttons and invalid default ID */
    info.dwCommonButtons = 0;
    run_test(&info, ID_START_BUTTON, msg_return_press_custom1, "default button: invalid default, no common buttons");

    /* Test with common and custom buttons and valid default ID */
    info.dwCommonButtons = TDCBF_OK_BUTTON | TDCBF_YES_BUTTON | TDCBF_NO_BUTTON
                               | TDCBF_CANCEL_BUTTON | TDCBF_RETRY_BUTTON | TDCBF_CLOSE_BUTTON;
    info.nDefaultButton = IDRETRY;
    run_test(&info, IDRETRY, msg_return_press_retry, "default button: valid default - 1");

    /* Test with common and custom buttons and valid default ID */
    info.nDefaultButton = ID_START_BUTTON + 3;
    run_test(&info, ID_START_BUTTON + 3, msg_return_press_custom4, "default button: valid default - 2");
}

static void test_help(void)
{
    TASKDIALOGCONFIG info = {0};

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = taskdialog_callback_proc;
    info.lpCallbackData = test_ref_data;
    info.dwCommonButtons = TDCBF_OK_BUTTON;

    run_test(&info, IDOK, msg_got_tdn_help, "send f1");
}

struct timer_notification_data
{
    DWORD last_elapsed_ms;
    DWORD num_fired;
};

static HRESULT CALLBACK taskdialog_callback_proc_timer(HWND hwnd, UINT notification,
        WPARAM wParam, LPARAM lParam, LONG_PTR ref_data)
{
    struct timer_notification_data *data = (struct timer_notification_data *)ref_data;

    if (notification == TDN_TIMER)
    {
        DWORD elapsed_ms;
        int delta;

        elapsed_ms = (DWORD)wParam;

        if (data->num_fired == 3)
            ok(data->last_elapsed_ms > elapsed_ms, "Expected reference time update.\n");
        else
        {
            delta = elapsed_ms - data->last_elapsed_ms;
            ok(delta > 0, "Expected positive time tick difference.\n");
        }
        data->last_elapsed_ms = elapsed_ms;

        if (data->num_fired == 3)
            PostMessageW(hwnd, TDM_CLICK_BUTTON, IDOK, 0);

        ++data->num_fired;
        return data->num_fired == 3 ? S_FALSE : S_OK;
    }

    return S_OK;
}

static void test_timer(void)
{
    struct timer_notification_data data = { 0 };
    TASKDIALOGCONFIG info = { 0 };

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = taskdialog_callback_proc_timer;
    info.lpCallbackData = (LONG_PTR)&data;
    info.dwFlags = TDF_CALLBACK_TIMER;
    info.dwCommonButtons = TDCBF_OK_BUTTON;

    pTaskDialogIndirect(&info, NULL, NULL, NULL);
}

/* Caller must free the string */
static WCHAR* control_get_text(HWND hdlg, int id_control)
{
    HWND hwnd_control = GetDlgItem(hdlg, id_control);
    int text_length = GetWindowTextLengthW(hwnd_control);
    WCHAR *text = heap_alloc((text_length + 1) * sizeof(WCHAR));
    GetWindowTextW(hwnd_control, text, text_length + 1);
    return text;
}

static int control_get_int(HWND hdlg, int id_control)
{
    int ret;
    WCHAR *text = control_get_text(hdlg, id_control);

    StrToIntExW(text, 0, &ret);
    heap_free(text);

    return ret;
}

/* Caller must free the structure */
static TASKDIALOG_BUTTON* taskdialog_creator_make_buttons(HWND hdlg, DWORD listview_id, UINT *count)
{
    HWND listview = GetDlgItem(hdlg, listview_id);
    TASKDIALOG_BUTTON *buttons;
    int i;

    *count = ListView_GetItemCount(listview);
    buttons = heap_alloc(*count * sizeof(TASKDIALOG_BUTTON));

    for (i = 0; i < *count; i++)
    {
        WCHAR *id = heap_alloc(10 * sizeof(WCHAR));
        WCHAR *text = heap_alloc(4096 * sizeof(WCHAR));

        ListView_GetItemTextW(listview, i, 0, id, 10);
        ListView_GetItemTextW(listview, i, 1, text, 4096);

        StrToIntExW(id, 0, &buttons[i].nButtonID);
        buttons[i].pszButtonText = text;

        heap_free(id);
    }
    return buttons;
}

static void taskdialog_creator_create(HWND hdlg)
{
    TASKDIALOGCONFIG info = { 0 };
    WCHAR *text_title;
    WCHAR *text_main_instruction;
    WCHAR *text_content;
    int i;
    int selected_button_style;

    text_title = control_get_text(hdlg, IDC_TASKDIALOG_TEXT_TITLE);
    text_main_instruction = control_get_text(hdlg, IDC_TASKDIALOG_TEXT_MAIN);
    text_content = control_get_text(hdlg, IDC_TASKDIALOG_TEXT_CONTENT);

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.hwndParent = hdlg;
    info.pszWindowTitle = text_title;
    info.pszMainInstruction = text_main_instruction;
    info.pszContent = text_content;
    info.pButtons = taskdialog_creator_make_buttons(hdlg, IDC_TASKDIALOG_TEXT_LIST_BUTTONS, &info.cButtons);

#define COMMONBUTTON(id, flag) \
        IsDlgButtonChecked(hdlg, id) == BST_CHECKED ? flag : 0

    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_OK,     TDCBF_OK_BUTTON);
    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_YES,    TDCBF_YES_BUTTON);
    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_NO,     TDCBF_NO_BUTTON);
    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_CANCEL, TDCBF_CANCEL_BUTTON);
    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_RETRY,  TDCBF_RETRY_BUTTON);
    info.dwCommonButtons |= COMMONBUTTON(IDC_TASKDIALOG_CHECKBOX_CLOSE,  TDCBF_CLOSE_BUTTON);

    selected_button_style = SendMessageA(GetDlgItem(hdlg, IDC_TASKDIALOG_COMBO_BUTTONSTYLE), CB_GETCURSEL, 0, 0);
    info.dwFlags |= selected_button_style == 1 ? TDF_USE_COMMAND_LINKS : 0;
    info.dwFlags |= selected_button_style == 2 ? TDF_USE_COMMAND_LINKS_NO_ICON : 0;
    info.nDefaultButton = control_get_int(hdlg, IDC_TASKDIALOG_TEXT_BUTTONDEFAULT);

    pTaskDialogIndirect(&info, NULL, NULL, NULL);

    heap_free(text_title);
    heap_free(text_main_instruction);
    heap_free(text_content);
    for (i = 0; i< info.cButtons; i++)
        heap_free((void*)info.pButtons[i].pszButtonText);
    heap_free((void*)info.pButtons);
}

static void taskdialog_creator_addbutton(HWND hdlg)
{
    LVITEMW item;
    HWND listview = GetDlgItem(hdlg, IDC_TASKDIALOG_TEXT_LIST_BUTTONS);
    DWORD index = ListView_GetItemCount(listview);
    WCHAR *button_text = control_get_text(hdlg, IDC_TASKDIALOG_TEXT_BUTTONTEXT);
    WCHAR *button_id = control_get_text(hdlg, IDC_TASKDIALOG_TEXT_BUTTONID);

    item.mask = LVIF_TEXT;
    item.iItem = index;

    item.iSubItem = 0;
    item.pszText = button_id;
    ListView_InsertItemW(listview, &item);

    item.iSubItem = 1;
    item.pszText = button_text;
    ListView_SetItemW(listview, &item);

    heap_free(button_text);
    heap_free(button_id);
}

static void taskdialog_creator_removebutton(HWND hdlg)
{
    HWND listview = GetDlgItem(hdlg, IDC_TASKDIALOG_TEXT_LIST_BUTTONS);
    int selected_index = ListView_GetNextItem(listview, -1, LVNI_SELECTED);
    if (selected_index != -1)
        ListView_DeleteItem(listview, selected_index);
}

static INT_PTR CALLBACK taskdialog_creator_proc(HWND hdlg, UINT msg, WPARAM wparam, LPARAM lparam)
{
    HWND list_buttons = GetDlgItem(hdlg, IDC_TASKDIALOG_TEXT_LIST_BUTTONS);
    HWND combo_buttonstyle = GetDlgItem(hdlg, IDC_TASKDIALOG_COMBO_BUTTONSTYLE);
    LVCOLUMNW listview_column;
    static WCHAR column_id[] = {'I', 'D',0};
    static WCHAR column_text[] = {'T', 'e','x','t',0};

    switch (msg)
    {
        case WM_INITDIALOG:
            listview_column.mask = LVCF_WIDTH | LVCF_TEXT;
            listview_column.cx = 50;
            listview_column.pszText = column_id;
            ListView_InsertColumnW(list_buttons, 0, &listview_column);
            listview_column.cx = 300;
            listview_column.pszText = column_text;
            ListView_InsertColumnW(list_buttons, 1, &listview_column);
            ListView_SetExtendedListViewStyle(list_buttons, LVS_EX_FULLROWSELECT);

            SendMessageA(combo_buttonstyle, CB_ADDSTRING, 0, (LPARAM)"Normal");
            SendMessageA(combo_buttonstyle, CB_ADDSTRING, 0, (LPARAM)"Commandlink (with icon)");
            SendMessageA(combo_buttonstyle, CB_ADDSTRING, 0, (LPARAM)"Commandlink (without icon)");
            SendMessageA(combo_buttonstyle, CB_SETCURSEL, 0, 0);
            break;
        case WM_COMMAND:
            if (HIWORD(wparam) == BN_CLICKED)
            {
                switch(LOWORD(wparam))
                {
                    case IDC_TASKDIALOG_BUTTON_CREATE:
                        taskdialog_creator_create(hdlg);
                        break;

                    case IDC_TASKDIALOG_BUTTON_ADDBUTTON:
                        taskdialog_creator_addbutton(hdlg);
                        break;
                    case IDC_TASKDIALOG_BUTTON_REMOVEBUTTON:
                        taskdialog_creator_removebutton(hdlg);
                        break;
                }

            }
            break;
        case WM_CLOSE:
            EndDialog(hdlg, 0);
            break;

        default:
            break;
    }

    return FALSE;
}

START_TEST(taskdialog)
{
    ULONG_PTR ctx_cookie;
    void *ptr_ordinal;
    HINSTANCE hinst;
    HANDLE hCtx;

    if (!load_v6_module(&ctx_cookie, &hCtx))
        return;

    /* Check if task dialogs are available */
    hinst = LoadLibraryA("comctl32.dll");

    pTaskDialogIndirect = (void *)GetProcAddress(hinst, "TaskDialogIndirect");
    if (!pTaskDialogIndirect)
    {
        win_skip("TaskDialogIndirect not exported by name\n");
        unload_v6_module(ctx_cookie, hCtx);
        return;
    }

    pTaskDialog = (void *)GetProcAddress(hinst, "TaskDialog");

    ptr_ordinal = GetProcAddress(hinst, (const char *)344);
    ok(pTaskDialog == ptr_ordinal, "got wrong pointer for ordinal 344, %p expected %p\n",
                                            ptr_ordinal, pTaskDialog);

    ptr_ordinal = GetProcAddress(hinst, (const char *)345);
    ok(pTaskDialogIndirect == ptr_ordinal, "got wrong pointer for ordinal 345, %p expected %p\n",
                                            ptr_ordinal, pTaskDialogIndirect);

    if (winetest_interactive)
    {
        DialogBoxParamA(GetModuleHandleA(NULL), "TAKDIALOG_CREATOR", NULL, taskdialog_creator_proc, 0);
        return;
    }

    init_msg_sequences(sequences, NUM_MSG_SEQUENCES);

    test_invalid_parameters();
    test_callback();
    test_buttons();
    test_help();
    test_timer();

    unload_v6_module(ctx_cookie, hCtx);
}
