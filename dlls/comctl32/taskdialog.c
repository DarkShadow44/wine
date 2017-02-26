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

#define MEMCPY_MOVEPTR(target, source, size) memcpy(target, source, size); target += size;

static void* align_pointer(void *ptr, unsigned int boundary)
{
    boundary--;
    return (void *)(((UINT_PTR)ptr + boundary) & ~boundary);
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

/* FIXME: Make thread safe */
static const TASKDIALOGCONFIG *task_config = 0;
static HRESULT callback(HWND hwnd, UINT uNotification, WPARAM wParam, LPARAM lParam)
{
    if(task_config->pfCallback)
        return task_config->pfCallback(hwnd, uNotification, wParam, lParam, task_config->lpCallbackData);
    return S_OK;
}

static INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HRESULT ret_callback;

    switch (uMsg)
    {
        case WM_INITDIALOG:
            callback(hwndDlg, TDN_DIALOG_CONSTRUCTED, 0, 0);
            callback(hwndDlg, TDN_CREATED, 0, 0);
            return TRUE;
        case WM_COMMAND:
            if(HIWORD(wParam) == BN_CLICKED)
            {
                WORD command_id = LOWORD(wParam);

                ret_callback = callback(hwndDlg, TDN_BUTTON_CLICKED, command_id, 0);
                if(ret_callback == S_OK) /* FIXME */
                {
                    EndDialog(hwndDlg, command_id);
                }
                return TRUE;
            }
            break;
        case WM_DESTROY:
            callback(hwndDlg, TDN_DESTROYED, 0, 0);
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
    LPDLGTEMPLATEW template_data;
    dialog_header header = {0};
    struct list controls;

    TRACE("%p, %p, %p, %p\n", pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);

    if (!pTaskConfig || pTaskConfig->cbSize != sizeof(TASKDIALOGCONFIG))
        return E_INVALIDARG;

    task_config = pTaskConfig;
    list_init(&controls);

    /* Start creating controls */

    controls_add(&controls, IDOK, WC_BUTTONW, text_ok, WS_CHILD | WS_VISIBLE, 105, 85, 40, 10);

    header.title = pTaskConfig->pszWindowTitle;
    if(!header.title)
        header.title = empty_string; /* FIXME: Set to exe path instead */
    header.titleSize = (lstrlenW(header.title) + 1) * sizeof(WCHAR);

    header.template.style = DS_MODALFRAME | WS_CAPTION | WS_VISIBLE;
    header.template.cdit = list_count(&controls);
    header.template.x = 10;
    header.template.y = 10;
    header.template.cx = 150;
    header.template.cy = 100;

    /* Turn template information into a dialog template to display it */
    template_data = dialog_template_create(header, &controls);

    DialogBoxIndirectParamW(pTaskConfig->hInstance, template_data, pTaskConfig->hwndParent, DialogProc, 0);

    /* Cleanup */

    Free(template_data);
    controls_destroy(&controls);

    return S_OK;
}
