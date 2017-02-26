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

static HRESULT (WINAPI *pTaskDialogIndirect)(const TASKDIALOGCONFIG *, int *, int *, BOOL *);

static struct msg_sequence *sequences[NUM_MSG_SEQUENCES];

/* Message lists to test against */

static const struct message mes_simple_show[] = {
    { WM_TD_CALLBACK, sent|id, 0, 0, TDN_DIALOG_CONSTRUCTED },
    { WM_TD_CALLBACK, sent|id, 0, 0, TDN_CREATED },
    { WM_TD_CALLBACK, sent|id|wparam, IDOK, 0, TDN_BUTTON_CLICKED },
    { WM_TD_CALLBACK, sent|id, 0, 0, TDN_DESTROYED },
    { 0 }
};


static LONG_PTR backup_ref_data; /* Copy of dwRefData to test against */

static HRESULT CALLBACK TaskDialogCallbackProc(HWND hwnd, UINT uNotification, WPARAM wParam,
                                               LPARAM lParam, LONG_PTR dwRefData)
{
    struct message msg;

    msg.message = WM_TD_CALLBACK;
    msg.flags   = sent|wparam|lparam|id;
    msg.wParam  = wParam;
    msg.lParam  = lParam;
    msg.id      = uNotification;
    add_message(sequences, TASKDIALOG_SEQ_INDEX, &msg);

    ok(backup_ref_data == dwRefData, "dwRefData is wrong, expected %lu, got %lu\n", backup_ref_data, dwRefData);

    if(uNotification == TDN_CREATED)
    {
        PostMessageW(hwnd, WM_KEYDOWN, VK_RETURN, 0);
    }
    return S_OK;
}

static void test_TaskDialogIndirect(void)
{
    TASKDIALOGCONFIG info = {0};
    HRESULT ret;

    ret = pTaskDialogIndirect(NULL, NULL, NULL, NULL);
    ok(ret == E_INVALIDARG, "Expected E_INVALIDARG, got %x\n", ret);

    ret = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(ret == E_INVALIDARG, "Expected E_INVALIDARG, got %x\n", ret);

    info.cbSize = sizeof(TASKDIALOGCONFIG);
    info.pfCallback = TaskDialogCallbackProc;
    info.lpCallbackData = backup_ref_data = 0x12345678; /* Set data for callback tests */

    ret = pTaskDialogIndirect(&info, NULL, NULL, NULL);
    ok(ret == S_OK, "Expected S_OK, got %x\n", ret);
    ok_sequence(sequences, TASKDIALOG_SEQ_INDEX, mes_simple_show, "Simple test with parameters null", FALSE);
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
