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

/* Fonts according to MSDN UI Guidelines:
 * Main Instructions      - Segoe UI, blue  (#003399), 12pt
 * Secondary Instructions - Segoe UI, black (#000000),  9pt
 * Normal Text            - Segoe UI, black (#000000),  9pt
 */

#include <stdarg.h>
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "wingdi.h"
#include "winuser.h"
#include "commctrl.h"
#include "winerror.h"
#include "comctl32.h"

#include "wine/list.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(commctrl);

/* Roughly fitting TaskDialog size */
static const UINT DIALOG_DEFAULT_WIDTH = 180;

static const UINT DIALOG_SPACING = 5;

#define ID_START 0xF000

static const int ID_TEXTMAIN    = ID_START + 1;
static const int ID_TEXTCONTENT = ID_START + 2;

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
    HFONT font_default, font_main;
}taskdialog_info;

#define MEMCPY_MOVEPTR(target, source, size) memcpy(target, source, size); target += size;
#define STR_EMPTY(str) (str == NULL || str[0] == 0)

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

/* used to calculate size for the static controls */
static RECT text_get_rect(HDC hdc, const WCHAR *text, UINT dialog_width)
{
    RECT rect = {0, 0, dialog_width - DIALOG_SPACING*2, 0}; /* padding left and right of the control */

    dialogunits_to_pixels(&rect.right, NULL);

    DrawTextW(hdc, text, -1, &rect, DT_LEFT | DT_EXPANDTABS | DT_CALCRECT | DT_WORDBREAK);

    pixels_to_dialogunits(&rect.right, &rect.bottom);

    rect.bottom += DIALOG_SPACING;

    return rect;
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

static BOOL CALLBACK SetFont(HWND window, LPARAM font_default)
{
    SendMessageW(window, WM_SETFONT, font_default, TRUE);
    return TRUE;
}

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

            EnumChildWindows(hwndDlg, (WNDENUMPROC)SetFont, (LPARAM)dialog_info->font_default);
            SendDlgItemMessageW(hwndDlg, ID_TEXTMAIN, WM_SETFONT, (WPARAM)dialog_info->font_main, TRUE);

            callback(dialog_info, TDN_DIALOG_CONSTRUCTED, 0, 0);
            callback(dialog_info, TDN_CREATED, 0, 0);

            return TRUE;
        case WM_CTLCOLORSTATIC:
               if((HWND)lParam == GetDlgItem(hwndDlg, ID_TEXTMAIN))
               {
                   HDC hdc = (HDC) wParam;

                   SetTextColor(hdc, RGB(0, 0x33, 0x99));
                   SetBkColor(hdc, GetSysColor(COLOR_3DFACE));

                   return (INT_PTR)GetSysColorBrush(COLOR_3DFACE);
               }
               break;
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

static void taskdialog_info_init(taskdialog_info *dialog_info, const TASKDIALOGCONFIG *task_config, HDC dc_dummy)
{
    NONCLIENTMETRICSW ncm;
    int font_size_default;
    int font_size_main;

    ncm.cbSize = sizeof(ncm);
    SystemParametersInfoW(SPI_GETNONCLIENTMETRICS, ncm.cbSize, &ncm, 0);

    /* Convert pt size to font height needed for CreateFontW */
    font_size_default = -MulDiv ( 9, GetDeviceCaps (dc_dummy, LOGPIXELSY), 72);
    font_size_main    = -MulDiv (12, GetDeviceCaps (dc_dummy, LOGPIXELSY), 72);

    dialog_info->task_config = task_config;
    dialog_info->font_default = CreateFontW (font_size_default, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    0, 0, CLEARTYPE_QUALITY,  FF_DONTCARE, ncm.lfMessageFont.lfFaceName);
    dialog_info->font_main    = CreateFontW (font_size_main,    0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                    0, 0, CLEARTYPE_QUALITY,  FF_DONTCARE, ncm.lfMessageFont.lfFaceName);
}

static void taskdialog_info_destroy(taskdialog_info *dialog_info)
{
    DeleteObject(dialog_info->font_main);
    DeleteObject(dialog_info->font_default);
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
    HDC dc_dummy;

    TRACE("%p, %p, %p, %p\n", pTaskConfig, pnButton, pnRadioButton, pfVerificationFlagChecked);

    if (!pTaskConfig || pTaskConfig->cbSize != sizeof(TASKDIALOGCONFIG))
        return E_INVALIDARG;

    dc_dummy = CreateCompatibleDC(NULL);
    list_init(&controls);
    taskdialog_info_init(&dialog_info, pTaskConfig, dc_dummy);

    SelectObject(dc_dummy, dialog_info.font_default);

    get_desktop_size(&desktop, pTaskConfig->hwndParent);
    dialog_height = DIALOG_SPACING;
    dialog_width = pTaskConfig->cxWidth;

    /* Dialog can't be smaller than default size and not bigger than screen
     * Note: Long text doesn't seem to make the dialog grow in width */
    if(dialog_width < DIALOG_DEFAULT_WIDTH)
        dialog_width = DIALOG_DEFAULT_WIDTH;
    if(dialog_width > desktop.right)
        dialog_width = desktop.right;

    /* Start creating controls */

    if(!IS_INTRESOURCE(pTaskConfig->pszContent) && !STR_EMPTY(pTaskConfig->pszMainInstruction))
    {
        RECT rect;

        SelectObject(dc_dummy, dialog_info.font_main);
        rect = text_get_rect(dc_dummy, pTaskConfig->pszMainInstruction, dialog_width);

        controls_add(&controls, ID_TEXTMAIN, WC_STATICW, pTaskConfig->pszMainInstruction,
                     WS_CHILD | WS_VISIBLE, DIALOG_SPACING, dialog_height, rect.right, rect.bottom);

        dialog_height += rect.bottom;
        SelectObject(dc_dummy, dialog_info.font_default);
    }

    if(!IS_INTRESOURCE(pTaskConfig->pszContent) && !STR_EMPTY(pTaskConfig->pszContent))
    {
        RECT rect = text_get_rect(dc_dummy, pTaskConfig->pszContent, dialog_width);

        controls_add(&controls, ID_TEXTCONTENT, WC_STATICW, pTaskConfig->pszContent,
                     WS_CHILD | WS_VISIBLE, DIALOG_SPACING, dialog_height, rect.right, rect.bottom);

        dialog_height += rect.bottom;
    }

    controls_add(&controls, IDOK, WC_BUTTONW, text_ok,
                 WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, dialog_width - 40 - 10, dialog_height, 40, 10);
    dialog_height += DIALOG_SPACING*2;

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

    DialogBoxIndirectParamW(pTaskConfig->hInstance, template_data, pTaskConfig->hwndParent, DialogProc, (LPARAM)&dialog_info);

    /* Cleanup */

    Free(template_data);
    controls_destroy(&controls);
    DeleteDC(dc_dummy);

    taskdialog_info_destroy(&dialog_info);

    return S_OK;
}
