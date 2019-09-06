#include "wine/asm.h"

WINE_DEFAULT_DEBUG_CHANNEL(thunks);

static WINAPI BOOL (*pTrackPopupMenuEx)(HMENU hMenu, UINT wFlags, INT x, INT y, HWND hWnd, LPTPMPARAMS lpTpm);
static WINAPI BOOL (*pTrackPopupMenu)(HMENU hMenu, UINT wFlags, INT x, INT y, INT nReserved, HWND hWnd, const RECT * lpRect);
static WINAPI BOOL (*pChangeMenuA)(HMENU hMenu, UINT pos, LPCSTR data, UINT id, UINT flags);
static WINAPI BOOL (*pChangeMenuW)(HMENU hMenu, UINT pos, LPCWSTR data, UINT id, UINT flags);
static WINAPI DWORD (*pCheckMenuItem)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pEnableMenuItem)(HMENU hMenu, UINT id, UINT wFlags);
static WINAPI INT (*pGetMenuStringA)(HMENU hMenu, UINT wItemID, LPSTR str, INT nMaxSiz, UINT wFlags);
static WINAPI INT (*pGetMenuStringW)(HMENU hMenu, UINT wItemID, LPWSTR str, INT nMaxSiz, UINT wFlags);
static WINAPI BOOL (*pHiliteMenuItem)(HWND hWnd, HMENU hMenu, UINT wItemID, UINT wHilite);
static WINAPI UINT (*pGetMenuState)(HMENU hMenu, UINT wItemID, UINT wFlags);
static WINAPI INT (*pGetMenuItemCount)(HMENU hMenu);
static WINAPI UINT (*pGetMenuItemID)(HMENU hMenu, INT nPos);
static WINAPI BOOL (*pInsertMenuW)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str);
static WINAPI BOOL (*pInsertMenuA)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str);
static WINAPI BOOL (*pAppendMenuA)(HMENU hMenu, UINT flags, UINT_PTR id, LPCSTR data);
static WINAPI BOOL (*pAppendMenuW)(HMENU hMenu, UINT flags, UINT_PTR id, LPCWSTR data);
static WINAPI BOOL (*pRemoveMenu)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pDeleteMenu)(HMENU hMenu, UINT id, UINT flags);
static WINAPI BOOL (*pModifyMenuW)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str);
static WINAPI BOOL (*pModifyMenuA)(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str);
static WINAPI HMENU (*pCreatePopupMenu)(void);
static WINAPI DWORD (*pGetMenuCheckMarkDimensions)(void);
static WINAPI BOOL (*pSetMenuItemBitmaps)(HMENU hMenu, UINT nPos, UINT wFlags, HBITMAP hNewUnCheck, HBITMAP hNewCheck);
static WINAPI HMENU (*pCreateMenu)(void);
static WINAPI BOOL (*pDestroyMenu)(HMENU hMenu);
static WINAPI HMENU (*pGetSystemMenu)(HWND hWnd, BOOL bRevert);
static WINAPI BOOL (*pSetSystemMenu)(HWND hwnd, HMENU hMenu);
static WINAPI HMENU (*pGetMenu)(HWND hWnd);
static WINAPI BOOL (*pGetMenuBarInfo)(HWND hwnd, LONG idObject, LONG idItem, PMENUBARINFO pmbi);
static WINAPI BOOL (*pSetMenu)(HWND hWnd, HMENU hMenu);
static WINAPI HMENU (*pGetSubMenu)(HMENU hMenu, INT nPos);
static WINAPI BOOL (*pDrawMenuBar)(HWND hWnd);
static WINAPI DWORD (*pDrawMenuBarTemp)(HWND hwnd, HDC hDC, LPRECT lprect, HMENU hMenu, HFONT hFont);
static WINAPI BOOL (*pEndMenu)(void);
static WINAPI HMENU (*pLoadMenuA)(HINSTANCE instance, LPCSTR name);
static WINAPI HMENU (*pLoadMenuW)(HINSTANCE instance, LPCWSTR name);
static WINAPI HMENU (*pLoadMenuIndirectW)(LPCVOID template);
static WINAPI HMENU (*pLoadMenuIndirectA)(LPCVOID template);
static WINAPI BOOL (*pIsMenu)(HMENU hmenu);
static WINAPI BOOL (*pGetMenuItemInfoA)(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOA lpmii);
static WINAPI BOOL (*pGetMenuItemInfoW)(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOW lpmii);
static WINAPI BOOL (*pSetMenuItemInfoA)(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOA * lpmii);
static WINAPI BOOL (*pSetMenuItemInfoW)(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOW * lpmii);
static WINAPI BOOL (*pSetMenuDefaultItem)(HMENU hmenu, UINT uItem, UINT bypos);
static WINAPI UINT (*pGetMenuDefaultItem)(HMENU hmenu, UINT bypos, UINT flags);
static WINAPI BOOL (*pInsertMenuItemA)(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOA * lpmii);
static WINAPI BOOL (*pInsertMenuItemW)(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOW * lpmii);
static WINAPI BOOL (*pCheckMenuRadioItem)(HMENU hMenu, UINT first, UINT last, UINT check, UINT flags);
static WINAPI BOOL (*pGetMenuItemRect)(HWND hwnd, HMENU hMenu, UINT uItem, RECT * rect);
static WINAPI BOOL (*pSetMenuInfo)(HMENU hMenu, LPCMENUINFO lpmi);
static WINAPI BOOL (*pGetMenuInfo)(HMENU hMenu, LPMENUINFO lpmi);
static WINAPI BOOL (*pSetMenuContextHelpId)(HMENU hMenu, DWORD dwContextHelpID);
static WINAPI DWORD (*pGetMenuContextHelpId)(HMENU hMenu);
static WINAPI INT (*pMenuItemFromPoint)(HWND hWnd, HMENU hMenu, POINT ptScreen);
static WINAPI DWORD (*pCalcMenuBar)(HWND hwnd, DWORD left, DWORD right, DWORD top, RECT * rect);
static WINAPI INT (*pTranslateAcceleratorA)(HWND hWnd, HACCEL hAccel, LPMSG msg);
static WINAPI INT (*pTranslateAcceleratorW)(HWND hWnd, HACCEL hAccel, LPMSG msg);

extern WINAPI BOOL wine32b_TrackPopupMenuEx(HMENU hMenu, UINT wFlags, INT x, INT y, HWND hWnd, LPTPMPARAMS lpTpm)
{
	TRACE("Enter TrackPopupMenuEx\n");
	return pTrackPopupMenuEx(hMenu, wFlags, x, y, hWnd, lpTpm);
}

extern WINAPI void wine32a_TrackPopupMenuEx(void);
__ASM_GLOBAL_FUNC(wine32a_TrackPopupMenuEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TrackPopupMenuEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TrackPopupMenu(HMENU hMenu, UINT wFlags, INT x, INT y, INT nReserved, HWND hWnd, const RECT * lpRect)
{
	TRACE("Enter TrackPopupMenu\n");
	return pTrackPopupMenu(hMenu, wFlags, x, y, nReserved, hWnd, lpRect);
}

extern WINAPI void wine32a_TrackPopupMenu(void);
__ASM_GLOBAL_FUNC(wine32a_TrackPopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TrackPopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ChangeMenuA(HMENU hMenu, UINT pos, LPCSTR data, UINT id, UINT flags)
{
	TRACE("Enter ChangeMenuA\n");
	return pChangeMenuA(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_ChangeMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ChangeMenuW(HMENU hMenu, UINT pos, LPCWSTR data, UINT id, UINT flags)
{
	TRACE("Enter ChangeMenuW\n");
	return pChangeMenuW(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_ChangeMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_CheckMenuItem(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter CheckMenuItem\n");
	return pCheckMenuItem(hMenu, id, flags);
}

extern WINAPI void wine32a_CheckMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_CheckMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnableMenuItem(HMENU hMenu, UINT id, UINT wFlags)
{
	TRACE("Enter EnableMenuItem\n");
	return pEnableMenuItem(hMenu, id, wFlags);
}

extern WINAPI void wine32a_EnableMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_EnableMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuStringA(HMENU hMenu, UINT wItemID, LPSTR str, INT nMaxSiz, UINT wFlags)
{
	TRACE("Enter GetMenuStringA\n");
	return pGetMenuStringA(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_GetMenuStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuStringW(HMENU hMenu, UINT wItemID, LPWSTR str, INT nMaxSiz, UINT wFlags)
{
	TRACE("Enter GetMenuStringW\n");
	return pGetMenuStringW(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_GetMenuStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_HiliteMenuItem(HWND hWnd, HMENU hMenu, UINT wItemID, UINT wHilite)
{
	TRACE("Enter HiliteMenuItem\n");
	return pHiliteMenuItem(hWnd, hMenu, wItemID, wHilite);
}

extern WINAPI void wine32a_HiliteMenuItem(void);
__ASM_GLOBAL_FUNC(wine32a_HiliteMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HiliteMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuState(HMENU hMenu, UINT wItemID, UINT wFlags)
{
	TRACE("Enter GetMenuState\n");
	return pGetMenuState(hMenu, wItemID, wFlags);
}

extern WINAPI void wine32a_GetMenuState(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetMenuItemCount(HMENU hMenu)
{
	TRACE("Enter GetMenuItemCount\n");
	return pGetMenuItemCount(hMenu);
}

extern WINAPI void wine32a_GetMenuItemCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuItemID(HMENU hMenu, INT nPos)
{
	TRACE("Enter GetMenuItemID\n");
	return pGetMenuItemID(hMenu, nPos);
}

extern WINAPI void wine32a_GetMenuItemID(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuW(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str)
{
	TRACE("Enter InsertMenuW\n");
	return pInsertMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_InsertMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuA(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str)
{
	TRACE("Enter InsertMenuA\n");
	return pInsertMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_InsertMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AppendMenuA(HMENU hMenu, UINT flags, UINT_PTR id, LPCSTR data)
{
	TRACE("Enter AppendMenuA\n");
	return pAppendMenuA(hMenu, flags, id, data);
}

extern WINAPI void wine32a_AppendMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_AppendMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AppendMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AppendMenuW(HMENU hMenu, UINT flags, UINT_PTR id, LPCWSTR data)
{
	TRACE("Enter AppendMenuW\n");
	return pAppendMenuW(hMenu, flags, id, data);
}

extern WINAPI void wine32a_AppendMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_AppendMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AppendMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RemoveMenu(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter RemoveMenu\n");
	return pRemoveMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_RemoveMenu(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteMenu(HMENU hMenu, UINT id, UINT flags)
{
	TRACE("Enter DeleteMenu\n");
	return pDeleteMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_DeleteMenu(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ModifyMenuW(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCWSTR str)
{
	TRACE("Enter ModifyMenuW\n");
	return pModifyMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_ModifyMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_ModifyMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ModifyMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ModifyMenuA(HMENU hMenu, UINT pos, UINT flags, UINT_PTR id, LPCSTR str)
{
	TRACE("Enter ModifyMenuA\n");
	return pModifyMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_ModifyMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_ModifyMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ModifyMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_CreatePopupMenu(void)
{
	TRACE("Enter CreatePopupMenu\n");
	return pCreatePopupMenu();
}

extern WINAPI void wine32a_CreatePopupMenu(void);
__ASM_GLOBAL_FUNC(wine32a_CreatePopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreatePopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetMenuCheckMarkDimensions(void)
{
	TRACE("Enter GetMenuCheckMarkDimensions\n");
	return pGetMenuCheckMarkDimensions();
}

extern WINAPI void wine32a_GetMenuCheckMarkDimensions(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuCheckMarkDimensions,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuCheckMarkDimensions") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemBitmaps(HMENU hMenu, UINT nPos, UINT wFlags, HBITMAP hNewUnCheck, HBITMAP hNewCheck)
{
	TRACE("Enter SetMenuItemBitmaps\n");
	return pSetMenuItemBitmaps(hMenu, nPos, wFlags, hNewUnCheck, hNewCheck);
}

extern WINAPI void wine32a_SetMenuItemBitmaps(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemBitmaps,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemBitmaps") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_CreateMenu(void)
{
	TRACE("Enter CreateMenu\n");
	return pCreateMenu();
}

extern WINAPI void wine32a_CreateMenu(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DestroyMenu(HMENU hMenu)
{
	TRACE("Enter DestroyMenu\n");
	return pDestroyMenu(hMenu);
}

extern WINAPI void wine32a_DestroyMenu(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetSystemMenu(HWND hWnd, BOOL bRevert)
{
	TRACE("Enter GetSystemMenu\n");
	return pGetSystemMenu(hWnd, bRevert);
}

extern WINAPI void wine32a_GetSystemMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetSystemMenu(HWND hwnd, HMENU hMenu)
{
	TRACE("Enter SetSystemMenu\n");
	return pSetSystemMenu(hwnd, hMenu);
}

extern WINAPI void wine32a_SetSystemMenu(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetMenu(HWND hWnd)
{
	TRACE("Enter GetMenu\n");
	return pGetMenu(hWnd);
}

extern WINAPI void wine32a_GetMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuBarInfo(HWND hwnd, LONG idObject, LONG idItem, PMENUBARINFO pmbi)
{
	TRACE("Enter GetMenuBarInfo\n");
	return pGetMenuBarInfo(hwnd, idObject, idItem, pmbi);
}

extern WINAPI void wine32a_GetMenuBarInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuBarInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenu(HWND hWnd, HMENU hMenu)
{
	TRACE("Enter SetMenu\n");
	return pSetMenu(hWnd, hMenu);
}

extern WINAPI void wine32a_SetMenu(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_GetSubMenu(HMENU hMenu, INT nPos)
{
	TRACE("Enter GetSubMenu\n");
	return pGetSubMenu(hMenu, nPos);
}

extern WINAPI void wine32a_GetSubMenu(void);
__ASM_GLOBAL_FUNC(wine32a_GetSubMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSubMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DrawMenuBar(HWND hWnd)
{
	TRACE("Enter DrawMenuBar\n");
	return pDrawMenuBar(hWnd);
}

extern WINAPI void wine32a_DrawMenuBar(void);
__ASM_GLOBAL_FUNC(wine32a_DrawMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_DrawMenuBarTemp(HWND hwnd, HDC hDC, LPRECT lprect, HMENU hMenu, HFONT hFont)
{
	TRACE("Enter DrawMenuBarTemp\n");
	return pDrawMenuBarTemp(hwnd, hDC, lprect, hMenu, hFont);
}

extern WINAPI void wine32a_DrawMenuBarTemp(void);
__ASM_GLOBAL_FUNC(wine32a_DrawMenuBarTemp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawMenuBarTemp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EndMenu(void)
{
	TRACE("Enter EndMenu\n");
	return pEndMenu();
}

extern WINAPI void wine32a_EndMenu(void);
__ASM_GLOBAL_FUNC(wine32a_EndMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuA(HINSTANCE instance, LPCSTR name)
{
	TRACE("Enter LoadMenuA\n");
	return pLoadMenuA(instance, name);
}

extern WINAPI void wine32a_LoadMenuA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuW(HINSTANCE instance, LPCWSTR name)
{
	TRACE("Enter LoadMenuW\n");
	return pLoadMenuW(instance, name);
}

extern WINAPI void wine32a_LoadMenuW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuIndirectW(LPCVOID template)
{
	TRACE("Enter LoadMenuIndirectW\n");
	return pLoadMenuIndirectW(template);
}

extern WINAPI void wine32a_LoadMenuIndirectW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuIndirectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuIndirectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_LoadMenuIndirectA(LPCVOID template)
{
	TRACE("Enter LoadMenuIndirectA\n");
	return pLoadMenuIndirectA(template);
}

extern WINAPI void wine32a_LoadMenuIndirectA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadMenuIndirectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadMenuIndirectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsMenu(HMENU hmenu)
{
	TRACE("Enter IsMenu\n");
	return pIsMenu(hmenu);
}

extern WINAPI void wine32a_IsMenu(void);
__ASM_GLOBAL_FUNC(wine32a_IsMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemInfoA(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOA lpmii)
{
	TRACE("Enter GetMenuItemInfoA\n");
	return pGetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_GetMenuItemInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemInfoW(HMENU hmenu, UINT item, BOOL bypos, LPMENUITEMINFOW lpmii)
{
	TRACE("Enter GetMenuItemInfoW\n");
	return pGetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_GetMenuItemInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemInfoA(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOA * lpmii)
{
	TRACE("Enter SetMenuItemInfoA\n");
	return pSetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_SetMenuItemInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuItemInfoW(HMENU hmenu, UINT item, BOOL bypos, const MENUITEMINFOW * lpmii)
{
	TRACE("Enter SetMenuItemInfoW\n");
	return pSetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_SetMenuItemInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuDefaultItem(HMENU hmenu, UINT uItem, UINT bypos)
{
	TRACE("Enter SetMenuDefaultItem\n");
	return pSetMenuDefaultItem(hmenu, uItem, bypos);
}

extern WINAPI void wine32a_SetMenuDefaultItem(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetMenuDefaultItem(HMENU hmenu, UINT bypos, UINT flags)
{
	TRACE("Enter GetMenuDefaultItem\n");
	return pGetMenuDefaultItem(hmenu, bypos, flags);
}

extern WINAPI void wine32a_GetMenuDefaultItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuItemA(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOA * lpmii)
{
	TRACE("Enter InsertMenuItemA\n");
	return pInsertMenuItemA(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_InsertMenuItemA(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuItemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuItemA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InsertMenuItemW(HMENU hMenu, UINT uItem, BOOL bypos, const MENUITEMINFOW * lpmii)
{
	TRACE("Enter InsertMenuItemW\n");
	return pInsertMenuItemW(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_InsertMenuItemW(void);
__ASM_GLOBAL_FUNC(wine32a_InsertMenuItemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InsertMenuItemW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CheckMenuRadioItem(HMENU hMenu, UINT first, UINT last, UINT check, UINT flags)
{
	TRACE("Enter CheckMenuRadioItem\n");
	return pCheckMenuRadioItem(hMenu, first, last, check, flags);
}

extern WINAPI void wine32a_CheckMenuRadioItem(void);
__ASM_GLOBAL_FUNC(wine32a_CheckMenuRadioItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckMenuRadioItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuItemRect(HWND hwnd, HMENU hMenu, UINT uItem, RECT * rect)
{
	TRACE("Enter GetMenuItemRect\n");
	return pGetMenuItemRect(hwnd, hMenu, uItem, rect);
}

extern WINAPI void wine32a_GetMenuItemRect(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuItemRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuItemRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuInfo(HMENU hMenu, LPCMENUINFO lpmi)
{
	TRACE("Enter SetMenuInfo\n");
	return pSetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_SetMenuInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetMenuInfo(HMENU hMenu, LPMENUINFO lpmi)
{
	TRACE("Enter GetMenuInfo\n");
	return pGetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_GetMenuInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetMenuContextHelpId(HMENU hMenu, DWORD dwContextHelpID)
{
	TRACE("Enter SetMenuContextHelpId\n");
	return pSetMenuContextHelpId(hMenu, dwContextHelpID);
}

extern WINAPI void wine32a_SetMenuContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_SetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetMenuContextHelpId(HMENU hMenu)
{
	TRACE("Enter GetMenuContextHelpId\n");
	return pGetMenuContextHelpId(hMenu);
}

extern WINAPI void wine32a_GetMenuContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_GetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_MenuItemFromPoint(HWND hWnd, HMENU hMenu, POINT ptScreen)
{
	TRACE("Enter MenuItemFromPoint\n");
	return pMenuItemFromPoint(hWnd, hMenu, ptScreen);
}

extern WINAPI void wine32a_MenuItemFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_MenuItemFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MenuItemFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_CalcMenuBar(HWND hwnd, DWORD left, DWORD right, DWORD top, RECT * rect)
{
	TRACE("Enter CalcMenuBar\n");
	return pCalcMenuBar(hwnd, left, right, top, rect);
}

extern WINAPI void wine32a_CalcMenuBar(void);
__ASM_GLOBAL_FUNC(wine32a_CalcMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CalcMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_TranslateAcceleratorA(HWND hWnd, HACCEL hAccel, LPMSG msg)
{
	TRACE("Enter TranslateAcceleratorA\n");
	return pTranslateAcceleratorA(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_TranslateAcceleratorA(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateAcceleratorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateAcceleratorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_TranslateAcceleratorW(HWND hWnd, HACCEL hAccel, LPMSG msg)
{
	TRACE("Enter TranslateAcceleratorW\n");
	return pTranslateAcceleratorW(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_TranslateAcceleratorW(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateAcceleratorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateAcceleratorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static BOOL initialized = FALSE;

void wine_thunk_initialize_user32(void)
{
	HMODULE library = LoadLibraryA("user32.dll");
	pTrackPopupMenuEx = (void *)GetProcAddress(library, "TrackPopupMenuEx");
	pTrackPopupMenu = (void *)GetProcAddress(library, "TrackPopupMenu");
	pChangeMenuA = (void *)GetProcAddress(library, "ChangeMenuA");
	pChangeMenuW = (void *)GetProcAddress(library, "ChangeMenuW");
	pCheckMenuItem = (void *)GetProcAddress(library, "CheckMenuItem");
	pEnableMenuItem = (void *)GetProcAddress(library, "EnableMenuItem");
	pGetMenuStringA = (void *)GetProcAddress(library, "GetMenuStringA");
	pGetMenuStringW = (void *)GetProcAddress(library, "GetMenuStringW");
	pHiliteMenuItem = (void *)GetProcAddress(library, "HiliteMenuItem");
	pGetMenuState = (void *)GetProcAddress(library, "GetMenuState");
	pGetMenuItemCount = (void *)GetProcAddress(library, "GetMenuItemCount");
	pGetMenuItemID = (void *)GetProcAddress(library, "GetMenuItemID");
	pInsertMenuW = (void *)GetProcAddress(library, "InsertMenuW");
	pInsertMenuA = (void *)GetProcAddress(library, "InsertMenuA");
	pAppendMenuA = (void *)GetProcAddress(library, "AppendMenuA");
	pAppendMenuW = (void *)GetProcAddress(library, "AppendMenuW");
	pRemoveMenu = (void *)GetProcAddress(library, "RemoveMenu");
	pDeleteMenu = (void *)GetProcAddress(library, "DeleteMenu");
	pModifyMenuW = (void *)GetProcAddress(library, "ModifyMenuW");
	pModifyMenuA = (void *)GetProcAddress(library, "ModifyMenuA");
	pCreatePopupMenu = (void *)GetProcAddress(library, "CreatePopupMenu");
	pGetMenuCheckMarkDimensions = (void *)GetProcAddress(library, "GetMenuCheckMarkDimensions");
	pSetMenuItemBitmaps = (void *)GetProcAddress(library, "SetMenuItemBitmaps");
	pCreateMenu = (void *)GetProcAddress(library, "CreateMenu");
	pDestroyMenu = (void *)GetProcAddress(library, "DestroyMenu");
	pGetSystemMenu = (void *)GetProcAddress(library, "GetSystemMenu");
	pSetSystemMenu = (void *)GetProcAddress(library, "SetSystemMenu");
	pGetMenu = (void *)GetProcAddress(library, "GetMenu");
	pGetMenuBarInfo = (void *)GetProcAddress(library, "GetMenuBarInfo");
	pSetMenu = (void *)GetProcAddress(library, "SetMenu");
	pGetSubMenu = (void *)GetProcAddress(library, "GetSubMenu");
	pDrawMenuBar = (void *)GetProcAddress(library, "DrawMenuBar");
	pDrawMenuBarTemp = (void *)GetProcAddress(library, "DrawMenuBarTemp");
	pEndMenu = (void *)GetProcAddress(library, "EndMenu");
	pLoadMenuA = (void *)GetProcAddress(library, "LoadMenuA");
	pLoadMenuW = (void *)GetProcAddress(library, "LoadMenuW");
	pLoadMenuIndirectW = (void *)GetProcAddress(library, "LoadMenuIndirectW");
	pLoadMenuIndirectA = (void *)GetProcAddress(library, "LoadMenuIndirectA");
	pIsMenu = (void *)GetProcAddress(library, "IsMenu");
	pGetMenuItemInfoA = (void *)GetProcAddress(library, "GetMenuItemInfoA");
	pGetMenuItemInfoW = (void *)GetProcAddress(library, "GetMenuItemInfoW");
	pSetMenuItemInfoA = (void *)GetProcAddress(library, "SetMenuItemInfoA");
	pSetMenuItemInfoW = (void *)GetProcAddress(library, "SetMenuItemInfoW");
	pSetMenuDefaultItem = (void *)GetProcAddress(library, "SetMenuDefaultItem");
	pGetMenuDefaultItem = (void *)GetProcAddress(library, "GetMenuDefaultItem");
	pInsertMenuItemA = (void *)GetProcAddress(library, "InsertMenuItemA");
	pInsertMenuItemW = (void *)GetProcAddress(library, "InsertMenuItemW");
	pCheckMenuRadioItem = (void *)GetProcAddress(library, "CheckMenuRadioItem");
	pGetMenuItemRect = (void *)GetProcAddress(library, "GetMenuItemRect");
	pSetMenuInfo = (void *)GetProcAddress(library, "SetMenuInfo");
	pGetMenuInfo = (void *)GetProcAddress(library, "GetMenuInfo");
	pSetMenuContextHelpId = (void *)GetProcAddress(library, "SetMenuContextHelpId");
	pGetMenuContextHelpId = (void *)GetProcAddress(library, "GetMenuContextHelpId");
	pMenuItemFromPoint = (void *)GetProcAddress(library, "MenuItemFromPoint");
	pCalcMenuBar = (void *)GetProcAddress(library, "CalcMenuBar");
	pTranslateAcceleratorA = (void *)GetProcAddress(library, "TranslateAcceleratorA");
	pTranslateAcceleratorW = (void *)GetProcAddress(library, "TranslateAcceleratorW");
	initialized = TRUE;
}

void* wine_thunk_get_for_user32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pTrackPopupMenuEx)
		return wine32a_TrackPopupMenuEx;
	if (func == pTrackPopupMenu)
		return wine32a_TrackPopupMenu;
	if (func == pChangeMenuA)
		return wine32a_ChangeMenuA;
	if (func == pChangeMenuW)
		return wine32a_ChangeMenuW;
	if (func == pCheckMenuItem)
		return wine32a_CheckMenuItem;
	if (func == pEnableMenuItem)
		return wine32a_EnableMenuItem;
	if (func == pGetMenuStringA)
		return wine32a_GetMenuStringA;
	if (func == pGetMenuStringW)
		return wine32a_GetMenuStringW;
	if (func == pHiliteMenuItem)
		return wine32a_HiliteMenuItem;
	if (func == pGetMenuState)
		return wine32a_GetMenuState;
	if (func == pGetMenuItemCount)
		return wine32a_GetMenuItemCount;
	if (func == pGetMenuItemID)
		return wine32a_GetMenuItemID;
	if (func == pInsertMenuW)
		return wine32a_InsertMenuW;
	if (func == pInsertMenuA)
		return wine32a_InsertMenuA;
	if (func == pAppendMenuA)
		return wine32a_AppendMenuA;
	if (func == pAppendMenuW)
		return wine32a_AppendMenuW;
	if (func == pRemoveMenu)
		return wine32a_RemoveMenu;
	if (func == pDeleteMenu)
		return wine32a_DeleteMenu;
	if (func == pModifyMenuW)
		return wine32a_ModifyMenuW;
	if (func == pModifyMenuA)
		return wine32a_ModifyMenuA;
	if (func == pCreatePopupMenu)
		return wine32a_CreatePopupMenu;
	if (func == pGetMenuCheckMarkDimensions)
		return wine32a_GetMenuCheckMarkDimensions;
	if (func == pSetMenuItemBitmaps)
		return wine32a_SetMenuItemBitmaps;
	if (func == pCreateMenu)
		return wine32a_CreateMenu;
	if (func == pDestroyMenu)
		return wine32a_DestroyMenu;
	if (func == pGetSystemMenu)
		return wine32a_GetSystemMenu;
	if (func == pSetSystemMenu)
		return wine32a_SetSystemMenu;
	if (func == pGetMenu)
		return wine32a_GetMenu;
	if (func == pGetMenuBarInfo)
		return wine32a_GetMenuBarInfo;
	if (func == pSetMenu)
		return wine32a_SetMenu;
	if (func == pGetSubMenu)
		return wine32a_GetSubMenu;
	if (func == pDrawMenuBar)
		return wine32a_DrawMenuBar;
	if (func == pDrawMenuBarTemp)
		return wine32a_DrawMenuBarTemp;
	if (func == pEndMenu)
		return wine32a_EndMenu;
	if (func == pLoadMenuA)
		return wine32a_LoadMenuA;
	if (func == pLoadMenuW)
		return wine32a_LoadMenuW;
	if (func == pLoadMenuIndirectW)
		return wine32a_LoadMenuIndirectW;
	if (func == pLoadMenuIndirectA)
		return wine32a_LoadMenuIndirectA;
	if (func == pIsMenu)
		return wine32a_IsMenu;
	if (func == pGetMenuItemInfoA)
		return wine32a_GetMenuItemInfoA;
	if (func == pGetMenuItemInfoW)
		return wine32a_GetMenuItemInfoW;
	if (func == pSetMenuItemInfoA)
		return wine32a_SetMenuItemInfoA;
	if (func == pSetMenuItemInfoW)
		return wine32a_SetMenuItemInfoW;
	if (func == pSetMenuDefaultItem)
		return wine32a_SetMenuDefaultItem;
	if (func == pGetMenuDefaultItem)
		return wine32a_GetMenuDefaultItem;
	if (func == pInsertMenuItemA)
		return wine32a_InsertMenuItemA;
	if (func == pInsertMenuItemW)
		return wine32a_InsertMenuItemW;
	if (func == pCheckMenuRadioItem)
		return wine32a_CheckMenuRadioItem;
	if (func == pGetMenuItemRect)
		return wine32a_GetMenuItemRect;
	if (func == pSetMenuInfo)
		return wine32a_SetMenuInfo;
	if (func == pGetMenuInfo)
		return wine32a_GetMenuInfo;
	if (func == pSetMenuContextHelpId)
		return wine32a_SetMenuContextHelpId;
	if (func == pGetMenuContextHelpId)
		return wine32a_GetMenuContextHelpId;
	if (func == pMenuItemFromPoint)
		return wine32a_MenuItemFromPoint;
	if (func == pCalcMenuBar)
		return wine32a_CalcMenuBar;
	if (func == pTranslateAcceleratorA)
		return wine32a_TranslateAcceleratorA;
	if (func == pTranslateAcceleratorW)
		return wine32a_TranslateAcceleratorW;

	return NULL;
}
