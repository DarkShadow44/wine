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

#include "wine/test.h"
#include "v6util.h"

static HRESULT (WINAPI *pTaskDialogIndirect)(const TASKDIALOGCONFIG *, int *, int *, BOOL *);

static HRESULT CALLBACK TaskDialogCallbackProc(HWND hwnd, UINT uNotification, WPARAM wParam,
                                               LPARAM lParam, LONG_PTR dwRefData)
{
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

    /* Skip this test on wine, because it doesn't really fail,
     * it would displays a dialog that doesn't automatically close */
    if (strcmp(winetest_platform, "wine"))
    {
        ret = pTaskDialogIndirect(&info, NULL, NULL, NULL);
        ok(ret == S_OK, "Expected S_OK, got %x\n", ret);
    }

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

    test_TaskDialogIndirect();

    unload_v6_module(ctx_cookie, hCtx);
}
