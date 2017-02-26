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

#include "wine/list.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(commctrl);

/* Roughly fitting TaskDialog size */
static const UINT DIALOG_DEFAULT_WIDTH = 180;

typedef struct
{
    DLGITEMTEMPLATE template;
    const WCHAR *class; /* For simplicity, we don't use ordinals but only the class name */
    const WCHAR *text;
    WORD creation_data;

    /* not part of actual template */
    UINT text_size;  /* Length in bytes including null-terminator */
    UINT class_size; /* Length in bytes including null-terminator */
    struct list entry;
}control_info;

typedef struct
{
    DLGTEMPLATE template;
    WORD menu;
    WORD class;
    const WCHAR *title;

    /* Not part of actual template */
    UINT titleSize; /* Length in bytes including null-terminator */
}dialog_header;

typedef struct
{
    int id;
    const WCHAR *text;
    UINT width;
    UINT x;
    UINT y;
}button_info;

typedef struct
{
    const TASKDIALOGCONFIG *task_config;
    HWND hwnd;
}taskdialog_info;

#define MEMCPY_MOVEPTR(target, source, size) memcpy(target, source, size); target += size;

static void* align_pointer(void *ptr, unsigned int boundary)
{
    boundary--;
    return (void *)(((UINT_PTR)ptr + boundary) & ~boundary);
}

static void pixels_to_dialogunits(LONG *width, LONG *height)
{
    UINT baseunits = GetDialogBaseUnits();

    if(width)
        *width = MulDiv(*width, 4, LOWORD(baseunits));
    if(height)
        *height = MulDiv(*height, 8, HIWORD(baseunits));
}

static void dialogunits_to_pixels(LONG *width, LONG *height)
{
    UINT baseunits = GetDialogBaseUnits();

    if(width)
        *width = MulDiv(*width, LOWORD(baseunits), 4);
    if(height)
        *height = MulDiv(*height, HIWORD(baseunits), 8);
}

static void get_desktop_size(RECT *desktop, HWND hwndWindow)
{
    HMONITOR monitor;
    MONITORINFO mon_info;

    monitor = MonitorFromWindow(hwndWindow ? hwndWindow : GetActiveWindow(), MONITOR_DEFAULTTOPRIMARY);
    mon_info.cbSize = sizeof(mon_info);
    GetMonitorInfoW(monitor, &mon_info);
    *desktop = mon_info.rcWork;

    /* Convert pixels to dialog units */
    pixels_to_dialogunits(&desktop->right, &desktop->bottom);
}

/* Functions for turning our dialog structures into a usable dialog template
 * We don't load the dialog template from a resource, we instead create it in memory
 * This way we can easily handle variable control numbers */
LPDLGTEMPLATEW dialog_template_create(dialog_header header, struct list *controls)
{
    control_info *control;
    void *template_data_start;
    char *template_data;
    int data_size = sizeof(WORD); /* Alignment at WORD boundaries is needed for strings, allocate a bit of padding */

    data_size += sizeof(DLGTEMPLATE);
    data_size += sizeof(WORD)*2 + header.titleSize;
    LIST_FOR_EACH_ENTRY(control, controls, control_info, entry)
    {
        data_size += sizeof(DWORD); /* Each item is aligned on DWORD boundary, allocate a bit of padding */
        data_size += sizeof(DLGITEMTEMPLATE);
        data_size += control->text_size;
        data_size += control->class_size;
        data_size += sizeof(WORD);
    }

    template_data_start = Alloc(data_size);
    template_data = template_data_start;

    /* Align on WORD boundary for the strings */
    template_data = align_pointer(template_data, 2);

    /* Copy header data */
    MEMCPY_MOVEPTR(template_data, &header.template, sizeof(DLGTEMPLATE));
    MEMCPY_MOVEPTR(template_data, &header.menu, sizeof(WORD));
    MEMCPY_MOVEPTR(template_data, &header.class, sizeof(WORD));
    MEMCPY_MOVEPTR(template_data, header.title, header.titleSize);

    /* Copy dialog member data */
    LIST_FOR_EACH_ENTRY(control, controls, control_info, entry)
    {
        /* Align on DWORD boundary for each new control */
        template_data = align_pointer(template_data, 4);

        MEMCPY_MOVEPTR(template_data, &control->template, sizeof(DLGITEMTEMPLATE));
        MEMCPY_MOVEPTR(template_data, control->class, control->class_size);
        MEMCPY_MOVEPTR(template_data, control->text, control->text_size);
        MEMCPY_MOVEPTR(template_data, &control->creation_data, sizeof(WORD));
    }

    return template_data_start;
}

/* Functions to handle the dialog control list */

static void controls_destroy(struct list *controls)
{
    control_info *control, *control2;
    LIST_FOR_EACH_ENTRY_SAFE(control, control2, controls, control_info, entry)
    {
        list_remove(&control->entry);
        Free(control);
    }
}

/* Adds a control for the TaskDialog into our list */
static void controls_add(struct list *controls, WORD id, const WCHAR *class, const WCHAR *text,
                       DWORD style, short x, short y, short cx, short cy)
{
    control_info *data = Alloc(sizeof(control_info));

    data->template.x = x;
    data->template.y = y;
    data->template.cx = cx;
    data->template.cy = cy;
    data->template.id = id;
    data->template.style = style;

    data->class = class;
    data->class_size = (lstrlenW(class) + 1) * sizeof(WCHAR);
    data->text = text;
    data->text_size = (lstrlenW(text) + 1) * sizeof(WCHAR);

    list_add_tail(controls, &data->entry);
}

/* DialogProc and helper functions */

static HRESULT callback(taskdialog_info *dialog_info, UINT uNotification, WPARAM wParam, LPARAM lParam)
{
    const TASKDIALOGCONFIG *task_config = dialog_info->task_config;

    if(task_config->pfCallback)
        return task_config->pfCallback(dialog_info->hwnd, uNotification, wParam, lParam, task_config->lpCallbackData);
    return S_OK;
}

static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static const WCHAR taskdialog_info_propnameW[] = {'T','a','s','k','D','i','a','l','o','g','I','n','f','o',0};
    HRESULT ret_callback;
    taskdialog_info *dialog_info;

    if(uMsg != WM_INITDIALOG && uMsg != WM_NCDESTROY)
        dialog_info = GetPropW(hwndDlg, taskdialog_info_propnameW);

    switch (uMsg)
    {
        case WM_INITDIALOG:
            dialog_info = (taskdialog_info *)lParam;
            dialog_info->hwnd = hwndDlg;
            SetPropW(hwndDlg, taskdialog_info_propnameW, dialog_info);

            callback(dialog_info, TDN_DIALOG_CONSTRUCTED, 0, 0);
            callback(dialog_info, TDN_CREATED, 0, 0);

            return TRUE;
        case WM_COMMAND:
            if(HIWORD(wParam) == BN_CLICKED)
            {
                WORD command_id = LOWORD(wParam);

                ret_callback = callback(dialog_info, TDN_BUTTON_CLICKED, command_id, 0);
                if(ret_callback == S_OK) /* FIXME */
                {
                    EndDialog(hwndDlg, command_id);
                }
                return TRUE;
            }
            break;
        case WM_DESTROY:
            callback(dialog_info, TDN_DESTROYED, 0, 0);
            RemovePropW(hwndDlg, taskdialog_info_propnameW);
            break;
    }
    return FALSE;
}

/***********************************************************************
 * TaskDialogIndirect [COMCTL32.@]
 */
HRESULT WINAPI TaskDialogIndirect(const TASKDIALOGCONFIG *pTaskConfig, int *pnButton,
                                  int *pnRadioButton, BOOL *pfVerificationFlagChecked)
{
    static const WCHAR empty_string[] = {0};
    static const WCHAR text_ok[] = {'O','K',0};
    taskdialog_info dialog_info;
    RECT desktop;
    UINT dialog_width; /* In dialog units */
    UINT dialog_height; /* In dialog units */
    LPDLGTEMPLATEW template_data;
    dialog_header header = {0};
    struct list controls;

    TRACE("%p, %p, %p, %p\n", pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);

    if (!pTaskConfig || pTaskConfig->cbSize != sizeof(TASKDIALOGCONFIG))
        return E_INVALIDARG;

    list_init(&controls);

    get_desktop_size(&desktop, pTaskConfig->hwndParent);
    dialog_height = 100;
    dialog_width = pTaskConfig->cxWidth;

    /* Dialog can't be smaller than default size and not bigger than screen
     * Note: Long text doesn't seem to make the dialog grow in width */
    if(dialog_width < DIALOG_DEFAULT_WIDTH)
        dialog_width = DIALOG_DEFAULT_WIDTH;
    if(dialog_width > desktop.right)
        dialog_width = desktop.right;

    /* Start creating controls */

    controls_add(&controls, IDOK, WC_BUTTONW, text_ok, WS_CHILD | WS_VISIBLE, 105, 85, 40, 10);

    header.title = pTaskConfig->pszWindowTitle;
    if(!header.title)
        header.title = empty_string; /* FIXME: Set to exe path instead */
    header.titleSize = (lstrlenW(header.title) + 1) * sizeof(WCHAR);

    header.template.style = DS_MODALFRAME | WS_CAPTION | WS_VISIBLE;
    header.template.cdit = list_count(&controls);

    /* TaskDialogs are always desktop centered */
    header.template.cx = dialog_width;
    header.template.cy = dialog_height;
    header.template.x = (desktop.right - dialog_width)/2;
    header.template.y = (desktop.bottom - dialog_height)/2;

    /* Turn template information into a dialog template to display it */
    template_data = dialog_template_create(header, &controls);

    dialog_info.task_config = pTaskConfig;
    DialogBoxIndirectParamW(pTaskConfig->hInstance, template_data, pTaskConfig->hwndParent, DialogProc, (LPARAM)&dialog_info);

    /* Cleanup */

    Free(template_data);
    controls_destroy(&controls);

    return S_OK;
}
