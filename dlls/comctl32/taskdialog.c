/*
 * Task dialog control
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
 *
 */

#include <stdarg.h>
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "commctrl.h"
#include "winerror.h"
#include "comctl32.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(commctrl);

/***********************************************************************
 * TaskDialogIndirect [COMCTL32.@]
 */
HRESULT WINAPI TaskDialogIndirect(const TASKDIALOGCONFIG *pTaskConfig, int *pnButton,
                                  int *pnRadioButton, BOOL *pfVerificationFlagChecked)
{
    UINT uType = 0;
    INT  ret;
    TRACE("%p, %p, %p, %p\n", pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);

    if (pTaskConfig->dwCommonButtons & TDCBF_YES_BUTTON &&
        pTaskConfig->dwCommonButtons & TDCBF_NO_BUTTON &&
        pTaskConfig->dwCommonButtons & TDCBF_CANCEL_BUTTON)
        uType |= MB_YESNOCANCEL;
    else
    if (pTaskConfig->dwCommonButtons & TDCBF_YES_BUTTON &&
        pTaskConfig->dwCommonButtons & TDCBF_NO_BUTTON)
        uType |= MB_YESNO;
    else
    if (pTaskConfig->dwCommonButtons & TDCBF_RETRY_BUTTON &&
        pTaskConfig->dwCommonButtons & TDCBF_CANCEL_BUTTON)
        uType |= MB_RETRYCANCEL;
    else
    if (pTaskConfig->dwCommonButtons & TDCBF_OK_BUTTON &&
        pTaskConfig->dwCommonButtons & TDCBF_CANCEL_BUTTON)
        uType |= MB_OKCANCEL;
    else
    if (pTaskConfig->dwCommonButtons & TDCBF_OK_BUTTON)
        uType |= MB_OK;
    ret = MessageBoxW(pTaskConfig->hwndParent, pTaskConfig->pszMainInstruction,
                      pTaskConfig->pszWindowTitle, uType);
    FIXME("dwCommonButtons=%x uType=%x ret=%x\n", pTaskConfig->dwCommonButtons, uType, ret);

    if (pnButton) *pnButton = ret;
    if (pnRadioButton) *pnRadioButton = pTaskConfig->nDefaultButton;
    if (pfVerificationFlagChecked) *pfVerificationFlagChecked = TRUE;
    return S_OK;
}
