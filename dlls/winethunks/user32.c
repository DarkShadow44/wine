#define WIN32_NO_STATUS
#include "ntstatus.h"
#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

#include "../../include/windef.h"
#include "../../include/winbase.h"
#include "../../include/wingdi.h"
#include "../../dlls/user32/controls.h"
#include "../../dlls/user32/win.h"
#include "../../include/wine/debug.h"
#include "../../include/winuser.h"
#include "../../include/wine/server.h"
#include "../../include/winerror.h"
#include "../../include/wine/unicode.h"
#include "../../include/wine/list.h"
#include "../../include/ntstatus.h"
#include "../../dlls/user32/user_private.h"
#include "../../include/winnls.h"
#include "../../include/wine/exception.h"
#include "../../include/wine/library.h"
#include "../../include/dde.h"
#include "../../include/ddeml.h"
#include "../../dlls/user32/dde_private.h"
#include "../../include/imm.h"
#include "../../include/wine/gdi_driver.h"
#include "../../include/usp10.h"
#include "../../include/pshpack1.h"
#include "../../include/poppack.h"
#include "../../include/wine/asm.h"
#include "../../include/winternl.h"
#include "../../include/wownt32.h"
#include "../../include/dbt.h"
#include "../../include/ddk/imm.h"
#include "../../include/wine/windef16.h"
#include "../../include/dlgs.h"
#include "../../dlls/user32/resources.h"
#include "../../include/winreg.h"
#include "../../include/setupapi.h"
#include "../../include/ddk/hidsdi.h"
#include "../../include/commctrl.h"
#include "../../include/commdlg.h"
#include "../../include/richedit.h"
#include "../../include/wine/wingdi16.h"
#include "../../include/initguid.h"
#include "../../include/devguid.h"
#include "../../include/winver.h"
#include "../../include/ddk/wdm.h"


static WINAPI BOOL (*pCreateCaret)(HWND hwnd, HBITMAP bitmap, INT width, INT height);
static WINAPI BOOL (*pDestroyCaret)(void);
static WINAPI BOOL (*pSetCaretPos)(INT x, INT y);
static WINAPI BOOL (*pHideCaret)(HWND hwnd);
static WINAPI BOOL (*pShowCaret)(HWND hwnd);
static WINAPI BOOL (*pGetCaretPos)(LPPOINT pt);
static WINAPI BOOL (*pSetCaretBlinkTime)(UINT msecs);
static WINAPI UINT (*pGetCaretBlinkTime)(void);

extern WINAPI BOOL wine32b_CreateCaret(HWND hwnd, HBITMAP bitmap, INT width, INT height)
{
	TRACE("Enter CreateCaret\n");
	return pCreateCaret(hwnd, bitmap, width, height);
}

extern WINAPI void wine32a_CreateCaret(void);
__ASM_GLOBAL_FUNC(wine32a_CreateCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateCaret") "\n"
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

extern WINAPI BOOL wine32b_DestroyCaret(void)
{
	TRACE("Enter DestroyCaret\n");
	return pDestroyCaret();
}

extern WINAPI void wine32a_DestroyCaret(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyCaret") "\n"
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

extern WINAPI BOOL wine32b_SetCaretPos(INT x, INT y)
{
	TRACE("Enter SetCaretPos\n");
	return pSetCaretPos(x, y);
}

extern WINAPI void wine32a_SetCaretPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetCaretPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCaretPos") "\n"
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

extern WINAPI BOOL wine32b_HideCaret(HWND hwnd)
{
	TRACE("Enter HideCaret\n");
	return pHideCaret(hwnd);
}

extern WINAPI void wine32a_HideCaret(void);
__ASM_GLOBAL_FUNC(wine32a_HideCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HideCaret") "\n"
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

extern WINAPI BOOL wine32b_ShowCaret(HWND hwnd)
{
	TRACE("Enter ShowCaret\n");
	return pShowCaret(hwnd);
}

extern WINAPI void wine32a_ShowCaret(void);
__ASM_GLOBAL_FUNC(wine32a_ShowCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowCaret") "\n"
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

extern WINAPI BOOL wine32b_GetCaretPos(LPPOINT pt)
{
	TRACE("Enter GetCaretPos\n");
	return pGetCaretPos(pt);
}

extern WINAPI void wine32a_GetCaretPos(void);
__ASM_GLOBAL_FUNC(wine32a_GetCaretPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCaretPos") "\n"
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

extern WINAPI BOOL wine32b_SetCaretBlinkTime(UINT msecs)
{
	TRACE("Enter SetCaretBlinkTime\n");
	return pSetCaretBlinkTime(msecs);
}

extern WINAPI void wine32a_SetCaretBlinkTime(void);
__ASM_GLOBAL_FUNC(wine32a_SetCaretBlinkTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCaretBlinkTime") "\n"
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

extern WINAPI UINT wine32b_GetCaretBlinkTime(void)
{
	TRACE("Enter GetCaretBlinkTime\n");
	return pGetCaretBlinkTime();
}

extern WINAPI void wine32a_GetCaretBlinkTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetCaretBlinkTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCaretBlinkTime") "\n"
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

static WINAPI ATOM (*pRegisterClassA)(const WNDCLASSA * wc);
static WINAPI ATOM (*pRegisterClassW)(const WNDCLASSW * wc);
static WINAPI ATOM (*pRegisterClassExA)(const WNDCLASSEXA * wc);
static WINAPI ATOM (*pRegisterClassExW)(const WNDCLASSEXW * wc);
static WINAPI BOOL (*pUnregisterClassA)(LPCSTR className, HINSTANCE hInstance);
static WINAPI BOOL (*pUnregisterClassW)(LPCWSTR className, HINSTANCE hInstance);
static WINAPI WORD (*pGetClassWord)(HWND hwnd, INT offset);
static WINAPI DWORD (*pGetClassLongW)(HWND hwnd, INT offset);
static WINAPI DWORD (*pGetClassLongA)(HWND hwnd, INT offset);
static WINAPI WORD (*pSetClassWord)(HWND hwnd, INT offset, WORD newval);
static WINAPI DWORD (*pSetClassLongW)(HWND hwnd, INT offset, LONG newval);
static WINAPI DWORD (*pSetClassLongA)(HWND hwnd, INT offset, LONG newval);
static WINAPI INT (*pGetClassNameA)(HWND hwnd, LPSTR buffer, INT count);
static WINAPI INT (*pGetClassNameW)(HWND hwnd, LPWSTR buffer, INT count);
static WINAPI UINT (*pRealGetWindowClassA)(HWND hwnd, LPSTR buffer, UINT count);
static WINAPI UINT (*pRealGetWindowClassW)(HWND hwnd, LPWSTR buffer, UINT count);
static WINAPI BOOL (*pGetClassInfoA)(HINSTANCE hInstance, LPCSTR name, WNDCLASSA * wc);
static WINAPI BOOL (*pGetClassInfoW)(HINSTANCE hInstance, LPCWSTR name, WNDCLASSW * wc);
static WINAPI BOOL (*pGetClassInfoExA)(HINSTANCE hInstance, LPCSTR name, WNDCLASSEXA * wc);
static WINAPI BOOL (*pGetClassInfoExW)(HINSTANCE hInstance, LPCWSTR name, WNDCLASSEXW * wc);
static WINAPI ULONG_PTR (*pGetClassLongPtrA)(HWND hwnd, INT offset);
static WINAPI ULONG_PTR (*pGetClassLongPtrW)(HWND hwnd, INT offset);
static WINAPI ULONG_PTR (*pSetClassLongPtrW)(HWND hwnd, INT offset, LONG_PTR newval);
static WINAPI ULONG_PTR (*pSetClassLongPtrA)(HWND hwnd, INT offset, LONG_PTR newval);

extern WINAPI ATOM wine32b_RegisterClassA(const WNDCLASSA * wc)
{
	TRACE("Enter RegisterClassA\n");
	return pRegisterClassA(wc);
}

extern WINAPI void wine32a_RegisterClassA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClassA") "\n"
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

extern WINAPI ATOM wine32b_RegisterClassW(const WNDCLASSW * wc)
{
	TRACE("Enter RegisterClassW\n");
	return pRegisterClassW(wc);
}

extern WINAPI void wine32a_RegisterClassW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClassW") "\n"
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

extern WINAPI ATOM wine32b_RegisterClassExA(const WNDCLASSEXA * wc)
{
	TRACE("Enter RegisterClassExA\n");
	return pRegisterClassExA(wc);
}

extern WINAPI void wine32a_RegisterClassExA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClassExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClassExA") "\n"
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

extern WINAPI ATOM wine32b_RegisterClassExW(const WNDCLASSEXW * wc)
{
	TRACE("Enter RegisterClassExW\n");
	return pRegisterClassExW(wc);
}

extern WINAPI void wine32a_RegisterClassExW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClassExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClassExW") "\n"
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

extern WINAPI BOOL wine32b_UnregisterClassA(LPCSTR className, HINSTANCE hInstance)
{
	TRACE("Enter UnregisterClassA\n");
	return pUnregisterClassA(className, hInstance);
}

extern WINAPI void wine32a_UnregisterClassA(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterClassA") "\n"
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

extern WINAPI BOOL wine32b_UnregisterClassW(LPCWSTR className, HINSTANCE hInstance)
{
	TRACE("Enter UnregisterClassW\n");
	return pUnregisterClassW(className, hInstance);
}

extern WINAPI void wine32a_UnregisterClassW(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterClassW") "\n"
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

extern WINAPI WORD wine32b_GetClassWord(HWND hwnd, INT offset)
{
	TRACE("Enter GetClassWord\n");
	return pGetClassWord(hwnd, offset);
}

extern WINAPI void wine32a_GetClassWord(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassWord") "\n"
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

extern WINAPI DWORD wine32b_GetClassLongW(HWND hwnd, INT offset)
{
	TRACE("Enter GetClassLongW\n");
	return pGetClassLongW(hwnd, offset);
}

extern WINAPI void wine32a_GetClassLongW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassLongW") "\n"
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

extern WINAPI DWORD wine32b_GetClassLongA(HWND hwnd, INT offset)
{
	TRACE("Enter GetClassLongA\n");
	return pGetClassLongA(hwnd, offset);
}

extern WINAPI void wine32a_GetClassLongA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassLongA") "\n"
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

extern WINAPI WORD wine32b_SetClassWord(HWND hwnd, INT offset, WORD newval)
{
	TRACE("Enter SetClassWord\n");
	return pSetClassWord(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetClassWord(void);
__ASM_GLOBAL_FUNC(wine32a_SetClassWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClassWord") "\n"
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

extern WINAPI DWORD wine32b_SetClassLongW(HWND hwnd, INT offset, LONG newval)
{
	TRACE("Enter SetClassLongW\n");
	return pSetClassLongW(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetClassLongW(void);
__ASM_GLOBAL_FUNC(wine32a_SetClassLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClassLongW") "\n"
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

extern WINAPI DWORD wine32b_SetClassLongA(HWND hwnd, INT offset, LONG newval)
{
	TRACE("Enter SetClassLongA\n");
	return pSetClassLongA(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetClassLongA(void);
__ASM_GLOBAL_FUNC(wine32a_SetClassLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClassLongA") "\n"
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

extern WINAPI INT wine32b_GetClassNameA(HWND hwnd, LPSTR buffer, INT count)
{
	TRACE("Enter GetClassNameA\n");
	return pGetClassNameA(hwnd, buffer, count);
}

extern WINAPI void wine32a_GetClassNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassNameA") "\n"
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

extern WINAPI INT wine32b_GetClassNameW(HWND hwnd, LPWSTR buffer, INT count)
{
	TRACE("Enter GetClassNameW\n");
	return pGetClassNameW(hwnd, buffer, count);
}

extern WINAPI void wine32a_GetClassNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassNameW") "\n"
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

extern WINAPI UINT wine32b_RealGetWindowClassA(HWND hwnd, LPSTR buffer, UINT count)
{
	TRACE("Enter RealGetWindowClassA\n");
	return pRealGetWindowClassA(hwnd, buffer, count);
}

extern WINAPI void wine32a_RealGetWindowClassA(void);
__ASM_GLOBAL_FUNC(wine32a_RealGetWindowClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RealGetWindowClassA") "\n"
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

extern WINAPI UINT wine32b_RealGetWindowClassW(HWND hwnd, LPWSTR buffer, UINT count)
{
	TRACE("Enter RealGetWindowClassW\n");
	return pRealGetWindowClassW(hwnd, buffer, count);
}

extern WINAPI void wine32a_RealGetWindowClassW(void);
__ASM_GLOBAL_FUNC(wine32a_RealGetWindowClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RealGetWindowClassW") "\n"
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

extern WINAPI BOOL wine32b_GetClassInfoA(HINSTANCE hInstance, LPCSTR name, WNDCLASSA * wc)
{
	TRACE("Enter GetClassInfoA\n");
	return pGetClassInfoA(hInstance, name, wc);
}

extern WINAPI void wine32a_GetClassInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassInfoA") "\n"
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

extern WINAPI BOOL wine32b_GetClassInfoW(HINSTANCE hInstance, LPCWSTR name, WNDCLASSW * wc)
{
	TRACE("Enter GetClassInfoW\n");
	return pGetClassInfoW(hInstance, name, wc);
}

extern WINAPI void wine32a_GetClassInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassInfoW") "\n"
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

extern WINAPI BOOL wine32b_GetClassInfoExA(HINSTANCE hInstance, LPCSTR name, WNDCLASSEXA * wc)
{
	TRACE("Enter GetClassInfoExA\n");
	return pGetClassInfoExA(hInstance, name, wc);
}

extern WINAPI void wine32a_GetClassInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassInfoExA") "\n"
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

extern WINAPI BOOL wine32b_GetClassInfoExW(HINSTANCE hInstance, LPCWSTR name, WNDCLASSEXW * wc)
{
	TRACE("Enter GetClassInfoExW\n");
	return pGetClassInfoExW(hInstance, name, wc);
}

extern WINAPI void wine32a_GetClassInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassInfoExW") "\n"
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

extern WINAPI ULONG_PTR wine32b_GetClassLongPtrA(HWND hwnd, INT offset)
{
	TRACE("Enter GetClassLongPtrA\n");
	return pGetClassLongPtrA(hwnd, offset);
}

extern WINAPI void wine32a_GetClassLongPtrA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassLongPtrA") "\n"
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

extern WINAPI ULONG_PTR wine32b_GetClassLongPtrW(HWND hwnd, INT offset)
{
	TRACE("Enter GetClassLongPtrW\n");
	return pGetClassLongPtrW(hwnd, offset);
}

extern WINAPI void wine32a_GetClassLongPtrW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClassLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClassLongPtrW") "\n"
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

extern WINAPI ULONG_PTR wine32b_SetClassLongPtrW(HWND hwnd, INT offset, LONG_PTR newval)
{
	TRACE("Enter SetClassLongPtrW\n");
	return pSetClassLongPtrW(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetClassLongPtrW(void);
__ASM_GLOBAL_FUNC(wine32a_SetClassLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClassLongPtrW") "\n"
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

extern WINAPI ULONG_PTR wine32b_SetClassLongPtrA(HWND hwnd, INT offset, LONG_PTR newval)
{
	TRACE("Enter SetClassLongPtrA\n");
	return pSetClassLongPtrA(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetClassLongPtrA(void);
__ASM_GLOBAL_FUNC(wine32a_SetClassLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClassLongPtrA") "\n"
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

static WINAPI UINT (*pRegisterClipboardFormatW)(LPCWSTR name);
static WINAPI UINT (*pRegisterClipboardFormatA)(LPCSTR name);
static WINAPI INT (*pGetClipboardFormatNameW)(UINT format, LPWSTR buffer, INT maxlen);
static WINAPI INT (*pGetClipboardFormatNameA)(UINT format, LPSTR buffer, INT maxlen);
static WINAPI BOOL (*pOpenClipboard)(HWND hwnd);
static WINAPI BOOL (*pCloseClipboard)(void);
static WINAPI BOOL (*pEmptyClipboard)(void);
static WINAPI HWND (*pGetClipboardOwner)(void);
static WINAPI HWND (*pGetOpenClipboardWindow)(void);
static WINAPI HWND (*pSetClipboardViewer)(HWND hwnd);
static WINAPI HWND (*pGetClipboardViewer)(void);
static WINAPI BOOL (*pChangeClipboardChain)(HWND hwnd, HWND next);
static WINAPI HANDLE (*pSetClipboardData)(UINT format, HANDLE data);
static WINAPI INT (*pCountClipboardFormats)(void);
static WINAPI UINT (*pEnumClipboardFormats)(UINT format);
static WINAPI BOOL (*pIsClipboardFormatAvailable)(UINT format);
static WINAPI BOOL (*pGetUpdatedClipboardFormats)(UINT * formats, UINT size, UINT * out_size);
static WINAPI HANDLE (*pGetClipboardData)(UINT format);
static WINAPI INT (*pGetPriorityClipboardFormat)(UINT * list, INT nCount);
static WINAPI DWORD (*pGetClipboardSequenceNumber)(void);
static WINAPI BOOL (*pAddClipboardFormatListener)(HWND hwnd);
static WINAPI BOOL (*pRemoveClipboardFormatListener)(HWND hwnd);

extern WINAPI UINT wine32b_RegisterClipboardFormatW(LPCWSTR name)
{
	TRACE("Enter RegisterClipboardFormatW\n");
	return pRegisterClipboardFormatW(name);
}

extern WINAPI void wine32a_RegisterClipboardFormatW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClipboardFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClipboardFormatW") "\n"
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

extern WINAPI UINT wine32b_RegisterClipboardFormatA(LPCSTR name)
{
	TRACE("Enter RegisterClipboardFormatA\n");
	return pRegisterClipboardFormatA(name);
}

extern WINAPI void wine32a_RegisterClipboardFormatA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterClipboardFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterClipboardFormatA") "\n"
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

extern WINAPI INT wine32b_GetClipboardFormatNameW(UINT format, LPWSTR buffer, INT maxlen)
{
	TRACE("Enter GetClipboardFormatNameW\n");
	return pGetClipboardFormatNameW(format, buffer, maxlen);
}

extern WINAPI void wine32a_GetClipboardFormatNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardFormatNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardFormatNameW") "\n"
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

extern WINAPI INT wine32b_GetClipboardFormatNameA(UINT format, LPSTR buffer, INT maxlen)
{
	TRACE("Enter GetClipboardFormatNameA\n");
	return pGetClipboardFormatNameA(format, buffer, maxlen);
}

extern WINAPI void wine32a_GetClipboardFormatNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardFormatNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardFormatNameA") "\n"
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

extern WINAPI BOOL wine32b_OpenClipboard(HWND hwnd)
{
	TRACE("Enter OpenClipboard\n");
	return pOpenClipboard(hwnd);
}

extern WINAPI void wine32a_OpenClipboard(void);
__ASM_GLOBAL_FUNC(wine32a_OpenClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenClipboard") "\n"
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

extern WINAPI BOOL wine32b_CloseClipboard(void)
{
	TRACE("Enter CloseClipboard\n");
	return pCloseClipboard();
}

extern WINAPI void wine32a_CloseClipboard(void);
__ASM_GLOBAL_FUNC(wine32a_CloseClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseClipboard") "\n"
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

extern WINAPI BOOL wine32b_EmptyClipboard(void)
{
	TRACE("Enter EmptyClipboard\n");
	return pEmptyClipboard();
}

extern WINAPI void wine32a_EmptyClipboard(void);
__ASM_GLOBAL_FUNC(wine32a_EmptyClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EmptyClipboard") "\n"
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

extern WINAPI HWND wine32b_GetClipboardOwner(void)
{
	TRACE("Enter GetClipboardOwner\n");
	return pGetClipboardOwner();
}

extern WINAPI void wine32a_GetClipboardOwner(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardOwner,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardOwner") "\n"
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

extern WINAPI HWND wine32b_GetOpenClipboardWindow(void)
{
	TRACE("Enter GetOpenClipboardWindow\n");
	return pGetOpenClipboardWindow();
}

extern WINAPI void wine32a_GetOpenClipboardWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetOpenClipboardWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetOpenClipboardWindow") "\n"
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

extern WINAPI HWND wine32b_SetClipboardViewer(HWND hwnd)
{
	TRACE("Enter SetClipboardViewer\n");
	return pSetClipboardViewer(hwnd);
}

extern WINAPI void wine32a_SetClipboardViewer(void);
__ASM_GLOBAL_FUNC(wine32a_SetClipboardViewer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClipboardViewer") "\n"
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

extern WINAPI HWND wine32b_GetClipboardViewer(void)
{
	TRACE("Enter GetClipboardViewer\n");
	return pGetClipboardViewer();
}

extern WINAPI void wine32a_GetClipboardViewer(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardViewer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardViewer") "\n"
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

extern WINAPI BOOL wine32b_ChangeClipboardChain(HWND hwnd, HWND next)
{
	TRACE("Enter ChangeClipboardChain\n");
	return pChangeClipboardChain(hwnd, next);
}

extern WINAPI void wine32a_ChangeClipboardChain(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeClipboardChain,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeClipboardChain") "\n"
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

extern WINAPI HANDLE wine32b_SetClipboardData(UINT format, HANDLE data)
{
	TRACE("Enter SetClipboardData\n");
	return pSetClipboardData(format, data);
}

extern WINAPI void wine32a_SetClipboardData(void);
__ASM_GLOBAL_FUNC(wine32a_SetClipboardData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetClipboardData") "\n"
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

extern WINAPI INT wine32b_CountClipboardFormats(void)
{
	TRACE("Enter CountClipboardFormats\n");
	return pCountClipboardFormats();
}

extern WINAPI void wine32a_CountClipboardFormats(void);
__ASM_GLOBAL_FUNC(wine32a_CountClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CountClipboardFormats") "\n"
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

extern WINAPI UINT wine32b_EnumClipboardFormats(UINT format)
{
	TRACE("Enter EnumClipboardFormats\n");
	return pEnumClipboardFormats(format);
}

extern WINAPI void wine32a_EnumClipboardFormats(void);
__ASM_GLOBAL_FUNC(wine32a_EnumClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumClipboardFormats") "\n"
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

extern WINAPI BOOL wine32b_IsClipboardFormatAvailable(UINT format)
{
	TRACE("Enter IsClipboardFormatAvailable\n");
	return pIsClipboardFormatAvailable(format);
}

extern WINAPI void wine32a_IsClipboardFormatAvailable(void);
__ASM_GLOBAL_FUNC(wine32a_IsClipboardFormatAvailable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsClipboardFormatAvailable") "\n"
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

extern WINAPI BOOL wine32b_GetUpdatedClipboardFormats(UINT * formats, UINT size, UINT * out_size)
{
	TRACE("Enter GetUpdatedClipboardFormats\n");
	return pGetUpdatedClipboardFormats(formats, size, out_size);
}

extern WINAPI void wine32a_GetUpdatedClipboardFormats(void);
__ASM_GLOBAL_FUNC(wine32a_GetUpdatedClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUpdatedClipboardFormats") "\n"
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

extern WINAPI HANDLE wine32b_GetClipboardData(UINT format)
{
	TRACE("Enter GetClipboardData\n");
	return pGetClipboardData(format);
}

extern WINAPI void wine32a_GetClipboardData(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardData") "\n"
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

extern WINAPI INT wine32b_GetPriorityClipboardFormat(UINT * list, INT nCount)
{
	TRACE("Enter GetPriorityClipboardFormat\n");
	return pGetPriorityClipboardFormat(list, nCount);
}

extern WINAPI void wine32a_GetPriorityClipboardFormat(void);
__ASM_GLOBAL_FUNC(wine32a_GetPriorityClipboardFormat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPriorityClipboardFormat") "\n"
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

extern WINAPI DWORD wine32b_GetClipboardSequenceNumber(void)
{
	TRACE("Enter GetClipboardSequenceNumber\n");
	return pGetClipboardSequenceNumber();
}

extern WINAPI void wine32a_GetClipboardSequenceNumber(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipboardSequenceNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipboardSequenceNumber") "\n"
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

extern WINAPI BOOL wine32b_AddClipboardFormatListener(HWND hwnd)
{
	TRACE("Enter AddClipboardFormatListener\n");
	return pAddClipboardFormatListener(hwnd);
}

extern WINAPI void wine32a_AddClipboardFormatListener(void);
__ASM_GLOBAL_FUNC(wine32a_AddClipboardFormatListener,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddClipboardFormatListener") "\n"
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

extern WINAPI BOOL wine32b_RemoveClipboardFormatListener(HWND hwnd)
{
	TRACE("Enter RemoveClipboardFormatListener\n");
	return pRemoveClipboardFormatListener(hwnd);
}

extern WINAPI void wine32a_RemoveClipboardFormatListener(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveClipboardFormatListener,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveClipboardFormatListener") "\n"
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

static WINAPI BOOL (*pGetComboBoxInfo)(HWND hwndCombo, PCOMBOBOXINFO pcbi);

extern WINAPI BOOL wine32b_GetComboBoxInfo(HWND hwndCombo, PCOMBOBOXINFO pcbi)
{
	TRACE("Enter GetComboBoxInfo\n");
	return pGetComboBoxInfo(hwndCombo, pcbi);
}

extern WINAPI void wine32a_GetComboBoxInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetComboBoxInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetComboBoxInfo") "\n"
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

static WINAPI HICON (*pCreateIconFromResourceEx)(LPBYTE bits, UINT cbSize, BOOL bIcon, DWORD dwVersion, INT width, INT height, UINT cFlag);
static WINAPI HICON (*pCreateIconFromResource)(LPBYTE bits, UINT cbSize, BOOL bIcon, DWORD dwVersion);
static WINAPI HCURSOR (*pCreateCursor)(HINSTANCE hInstance, INT xHotSpot, INT yHotSpot, INT nWidth, INT nHeight, LPCVOID lpANDbits, LPCVOID lpXORbits);
static WINAPI HICON (*pCreateIcon)(HINSTANCE hInstance, INT nWidth, INT nHeight, BYTE bPlanes, BYTE bBitsPixel, LPCVOID lpANDbits, LPCVOID lpXORbits);
static WINAPI HICON (*pCopyIcon)(HICON hIcon);
static WINAPI BOOL (*pDestroyIcon)(HICON hIcon);
static WINAPI BOOL (*pDestroyCursor)(HCURSOR hCursor);
static WINAPI BOOL (*pDrawIcon)(HDC hdc, INT x, INT y, HICON hIcon);
static WINAPI HCURSOR (*pSetCursor)(HCURSOR hCursor);
static WINAPI INT (*pShowCursor)(BOOL bShow);
static WINAPI HCURSOR (*pGetCursor)(void);
static WINAPI BOOL (*pClipCursor)(const RECT * rect);
static WINAPI BOOL (*pGetClipCursor)(RECT * rect);
static WINAPI BOOL (*pSetSystemCursor)(HCURSOR hcur, DWORD id);
static WINAPI INT (*pLookupIconIdFromDirectoryEx)(LPBYTE xdir, BOOL bIcon, INT width, INT height, UINT cFlag);
static WINAPI INT (*pLookupIconIdFromDirectory)(LPBYTE dir, BOOL bIcon);
static WINAPI HCURSOR (*pLoadCursorW)(HINSTANCE hInstance, LPCWSTR name);
static WINAPI HCURSOR (*pLoadCursorA)(HINSTANCE hInstance, LPCSTR name);
static WINAPI HCURSOR (*pLoadCursorFromFileW)(LPCWSTR name);
static WINAPI HCURSOR (*pLoadCursorFromFileA)(LPCSTR name);
static WINAPI HICON (*pLoadIconW)(HINSTANCE hInstance, LPCWSTR name);
static WINAPI HICON (*pLoadIconA)(HINSTANCE hInstance, LPCSTR name);
static WINAPI HCURSOR (*pGetCursorFrameInfo)(HCURSOR hCursor, DWORD reserved, DWORD istep, DWORD * rate_jiffies, DWORD * num_steps);
static WINAPI BOOL (*pGetIconInfo)(HICON hIcon, PICONINFO iconinfo);
static WINAPI BOOL (*pGetIconInfoExA)(HICON icon, ICONINFOEXA * info);
static WINAPI BOOL (*pGetIconInfoExW)(HICON icon, ICONINFOEXW * info);
static WINAPI HICON (*pCreateIconIndirect)(PICONINFO iconinfo);
static WINAPI BOOL (*pDrawIconEx)(HDC hdc, INT x0, INT y0, HICON hIcon, INT cxWidth, INT cyWidth, UINT istep, HBRUSH hbr, UINT flags);
static WINAPI HANDLE (*pLoadImageA)(HINSTANCE hinst, LPCSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags);
static WINAPI HANDLE (*pLoadImageW)(HINSTANCE hinst, LPCWSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags);
static WINAPI HANDLE (*pCopyImage)(HANDLE hnd, UINT type, INT desiredx, INT desiredy, UINT flags);
static WINAPI HBITMAP (*pLoadBitmapW)(HINSTANCE instance, LPCWSTR name);
static WINAPI HBITMAP (*pLoadBitmapA)(HINSTANCE instance, LPCSTR name);

extern WINAPI HICON wine32b_CreateIconFromResourceEx(LPBYTE bits, UINT cbSize, BOOL bIcon, DWORD dwVersion, INT width, INT height, UINT cFlag)
{
	TRACE("Enter CreateIconFromResourceEx\n");
	return pCreateIconFromResourceEx(bits, cbSize, bIcon, dwVersion, width, height, cFlag);
}

extern WINAPI void wine32a_CreateIconFromResourceEx(void);
__ASM_GLOBAL_FUNC(wine32a_CreateIconFromResourceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateIconFromResourceEx") "\n"
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

extern WINAPI HICON wine32b_CreateIconFromResource(LPBYTE bits, UINT cbSize, BOOL bIcon, DWORD dwVersion)
{
	TRACE("Enter CreateIconFromResource\n");
	return pCreateIconFromResource(bits, cbSize, bIcon, dwVersion);
}

extern WINAPI void wine32a_CreateIconFromResource(void);
__ASM_GLOBAL_FUNC(wine32a_CreateIconFromResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateIconFromResource") "\n"
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

extern WINAPI HCURSOR wine32b_CreateCursor(HINSTANCE hInstance, INT xHotSpot, INT yHotSpot, INT nWidth, INT nHeight, LPCVOID lpANDbits, LPCVOID lpXORbits)
{
	TRACE("Enter CreateCursor\n");
	return pCreateCursor(hInstance, xHotSpot, yHotSpot, nWidth, nHeight, lpANDbits, lpXORbits);
}

extern WINAPI void wine32a_CreateCursor(void);
__ASM_GLOBAL_FUNC(wine32a_CreateCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateCursor") "\n"
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

extern WINAPI HICON wine32b_CreateIcon(HINSTANCE hInstance, INT nWidth, INT nHeight, BYTE bPlanes, BYTE bBitsPixel, LPCVOID lpANDbits, LPCVOID lpXORbits)
{
	TRACE("Enter CreateIcon\n");
	return pCreateIcon(hInstance, nWidth, nHeight, bPlanes, bBitsPixel, lpANDbits, lpXORbits);
}

extern WINAPI void wine32a_CreateIcon(void);
__ASM_GLOBAL_FUNC(wine32a_CreateIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateIcon") "\n"
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

extern WINAPI HICON wine32b_CopyIcon(HICON hIcon)
{
	TRACE("Enter CopyIcon\n");
	return pCopyIcon(hIcon);
}

extern WINAPI void wine32a_CopyIcon(void);
__ASM_GLOBAL_FUNC(wine32a_CopyIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyIcon") "\n"
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

extern WINAPI BOOL wine32b_DestroyIcon(HICON hIcon)
{
	TRACE("Enter DestroyIcon\n");
	return pDestroyIcon(hIcon);
}

extern WINAPI void wine32a_DestroyIcon(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyIcon") "\n"
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

extern WINAPI BOOL wine32b_DestroyCursor(HCURSOR hCursor)
{
	TRACE("Enter DestroyCursor\n");
	return pDestroyCursor(hCursor);
}

extern WINAPI void wine32a_DestroyCursor(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyCursor") "\n"
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

extern WINAPI BOOL wine32b_DrawIcon(HDC hdc, INT x, INT y, HICON hIcon)
{
	TRACE("Enter DrawIcon\n");
	return pDrawIcon(hdc, x, y, hIcon);
}

extern WINAPI void wine32a_DrawIcon(void);
__ASM_GLOBAL_FUNC(wine32a_DrawIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawIcon") "\n"
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

extern WINAPI HCURSOR wine32b_SetCursor(HCURSOR hCursor)
{
	TRACE("Enter SetCursor\n");
	return pSetCursor(hCursor);
}

extern WINAPI void wine32a_SetCursor(void);
__ASM_GLOBAL_FUNC(wine32a_SetCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCursor") "\n"
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

extern WINAPI INT wine32b_ShowCursor(BOOL bShow)
{
	TRACE("Enter ShowCursor\n");
	return pShowCursor(bShow);
}

extern WINAPI void wine32a_ShowCursor(void);
__ASM_GLOBAL_FUNC(wine32a_ShowCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowCursor") "\n"
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

extern WINAPI HCURSOR wine32b_GetCursor(void)
{
	TRACE("Enter GetCursor\n");
	return pGetCursor();
}

extern WINAPI void wine32a_GetCursor(void);
__ASM_GLOBAL_FUNC(wine32a_GetCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCursor") "\n"
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

extern WINAPI BOOL wine32b_ClipCursor(const RECT * rect)
{
	TRACE("Enter ClipCursor\n");
	return pClipCursor(rect);
}

extern WINAPI void wine32a_ClipCursor(void);
__ASM_GLOBAL_FUNC(wine32a_ClipCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClipCursor") "\n"
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

extern WINAPI BOOL wine32b_GetClipCursor(RECT * rect)
{
	TRACE("Enter GetClipCursor\n");
	return pGetClipCursor(rect);
}

extern WINAPI void wine32a_GetClipCursor(void);
__ASM_GLOBAL_FUNC(wine32a_GetClipCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClipCursor") "\n"
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

extern WINAPI BOOL wine32b_SetSystemCursor(HCURSOR hcur, DWORD id)
{
	TRACE("Enter SetSystemCursor\n");
	return pSetSystemCursor(hcur, id);
}

extern WINAPI void wine32a_SetSystemCursor(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemCursor") "\n"
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

extern WINAPI INT wine32b_LookupIconIdFromDirectoryEx(LPBYTE xdir, BOOL bIcon, INT width, INT height, UINT cFlag)
{
	TRACE("Enter LookupIconIdFromDirectoryEx\n");
	return pLookupIconIdFromDirectoryEx(xdir, bIcon, width, height, cFlag);
}

extern WINAPI void wine32a_LookupIconIdFromDirectoryEx(void);
__ASM_GLOBAL_FUNC(wine32a_LookupIconIdFromDirectoryEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupIconIdFromDirectoryEx") "\n"
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

extern WINAPI INT wine32b_LookupIconIdFromDirectory(LPBYTE dir, BOOL bIcon)
{
	TRACE("Enter LookupIconIdFromDirectory\n");
	return pLookupIconIdFromDirectory(dir, bIcon);
}

extern WINAPI void wine32a_LookupIconIdFromDirectory(void);
__ASM_GLOBAL_FUNC(wine32a_LookupIconIdFromDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupIconIdFromDirectory") "\n"
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

extern WINAPI HCURSOR wine32b_LoadCursorW(HINSTANCE hInstance, LPCWSTR name)
{
	TRACE("Enter LoadCursorW\n");
	return pLoadCursorW(hInstance, name);
}

extern WINAPI void wine32a_LoadCursorW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadCursorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadCursorW") "\n"
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

extern WINAPI HCURSOR wine32b_LoadCursorA(HINSTANCE hInstance, LPCSTR name)
{
	TRACE("Enter LoadCursorA\n");
	return pLoadCursorA(hInstance, name);
}

extern WINAPI void wine32a_LoadCursorA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadCursorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadCursorA") "\n"
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

extern WINAPI HCURSOR wine32b_LoadCursorFromFileW(LPCWSTR name)
{
	TRACE("Enter LoadCursorFromFileW\n");
	return pLoadCursorFromFileW(name);
}

extern WINAPI void wine32a_LoadCursorFromFileW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadCursorFromFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadCursorFromFileW") "\n"
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

extern WINAPI HCURSOR wine32b_LoadCursorFromFileA(LPCSTR name)
{
	TRACE("Enter LoadCursorFromFileA\n");
	return pLoadCursorFromFileA(name);
}

extern WINAPI void wine32a_LoadCursorFromFileA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadCursorFromFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadCursorFromFileA") "\n"
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

extern WINAPI HICON wine32b_LoadIconW(HINSTANCE hInstance, LPCWSTR name)
{
	TRACE("Enter LoadIconW\n");
	return pLoadIconW(hInstance, name);
}

extern WINAPI void wine32a_LoadIconW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadIconW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadIconW") "\n"
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

extern WINAPI HICON wine32b_LoadIconA(HINSTANCE hInstance, LPCSTR name)
{
	TRACE("Enter LoadIconA\n");
	return pLoadIconA(hInstance, name);
}

extern WINAPI void wine32a_LoadIconA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadIconA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadIconA") "\n"
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

extern WINAPI HCURSOR wine32b_GetCursorFrameInfo(HCURSOR hCursor, DWORD reserved, DWORD istep, DWORD * rate_jiffies, DWORD * num_steps)
{
	TRACE("Enter GetCursorFrameInfo\n");
	return pGetCursorFrameInfo(hCursor, reserved, istep, rate_jiffies, num_steps);
}

extern WINAPI void wine32a_GetCursorFrameInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetCursorFrameInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCursorFrameInfo") "\n"
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

extern WINAPI BOOL wine32b_GetIconInfo(HICON hIcon, PICONINFO iconinfo)
{
	TRACE("Enter GetIconInfo\n");
	return pGetIconInfo(hIcon, iconinfo);
}

extern WINAPI void wine32a_GetIconInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetIconInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetIconInfo") "\n"
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

extern WINAPI BOOL wine32b_GetIconInfoExA(HICON icon, ICONINFOEXA * info)
{
	TRACE("Enter GetIconInfoExA\n");
	return pGetIconInfoExA(icon, info);
}

extern WINAPI void wine32a_GetIconInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetIconInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetIconInfoExA") "\n"
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

extern WINAPI BOOL wine32b_GetIconInfoExW(HICON icon, ICONINFOEXW * info)
{
	TRACE("Enter GetIconInfoExW\n");
	return pGetIconInfoExW(icon, info);
}

extern WINAPI void wine32a_GetIconInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetIconInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetIconInfoExW") "\n"
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

extern WINAPI HICON wine32b_CreateIconIndirect(PICONINFO iconinfo)
{
	TRACE("Enter CreateIconIndirect\n");
	return pCreateIconIndirect(iconinfo);
}

extern WINAPI void wine32a_CreateIconIndirect(void);
__ASM_GLOBAL_FUNC(wine32a_CreateIconIndirect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateIconIndirect") "\n"
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

extern WINAPI BOOL wine32b_DrawIconEx(HDC hdc, INT x0, INT y0, HICON hIcon, INT cxWidth, INT cyWidth, UINT istep, HBRUSH hbr, UINT flags)
{
	TRACE("Enter DrawIconEx\n");
	return pDrawIconEx(hdc, x0, y0, hIcon, cxWidth, cyWidth, istep, hbr, flags);
}

extern WINAPI void wine32a_DrawIconEx(void);
__ASM_GLOBAL_FUNC(wine32a_DrawIconEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawIconEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_LoadImageA(HINSTANCE hinst, LPCSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags)
{
	TRACE("Enter LoadImageA\n");
	return pLoadImageA(hinst, name, type, desiredx, desiredy, loadflags);
}

extern WINAPI void wine32a_LoadImageA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadImageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadImageA") "\n"
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

extern WINAPI HANDLE wine32b_LoadImageW(HINSTANCE hinst, LPCWSTR name, UINT type, INT desiredx, INT desiredy, UINT loadflags)
{
	TRACE("Enter LoadImageW\n");
	return pLoadImageW(hinst, name, type, desiredx, desiredy, loadflags);
}

extern WINAPI void wine32a_LoadImageW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadImageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadImageW") "\n"
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

extern WINAPI HANDLE wine32b_CopyImage(HANDLE hnd, UINT type, INT desiredx, INT desiredy, UINT flags)
{
	TRACE("Enter CopyImage\n");
	return pCopyImage(hnd, type, desiredx, desiredy, flags);
}

extern WINAPI void wine32a_CopyImage(void);
__ASM_GLOBAL_FUNC(wine32a_CopyImage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyImage") "\n"
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

extern WINAPI HBITMAP wine32b_LoadBitmapW(HINSTANCE instance, LPCWSTR name)
{
	TRACE("Enter LoadBitmapW\n");
	return pLoadBitmapW(instance, name);
}

extern WINAPI void wine32a_LoadBitmapW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadBitmapW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadBitmapW") "\n"
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

extern WINAPI HBITMAP wine32b_LoadBitmapA(HINSTANCE instance, LPCSTR name)
{
	TRACE("Enter LoadBitmapA\n");
	return pLoadBitmapA(instance, name);
}

extern WINAPI void wine32a_LoadBitmapA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadBitmapA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadBitmapA") "\n"
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

static WINAPI HCONVLIST (*pDdeConnectList)(DWORD idInst, HSZ hszService, HSZ hszTopic, HCONVLIST hConvList, PCONVCONTEXT pCC);
static WINAPI HCONV (*pDdeQueryNextServer)(HCONVLIST hConvList, HCONV hConvPrev);
static WINAPI BOOL (*pDdeDisconnectList)(HCONVLIST hConvList);
static WINAPI HCONV (*pDdeConnect)(DWORD idInst, HSZ hszService, HSZ hszTopic, PCONVCONTEXT pCC);
static WINAPI HCONV (*pDdeReconnect)(HCONV hConv);
static WINAPI HDDEDATA (*pDdeClientTransaction)(LPBYTE pData, DWORD cbData, HCONV hConv, HSZ hszItem, UINT wFmt, UINT wType, DWORD dwTimeout, LPDWORD pdwResult);
static WINAPI BOOL (*pDdeAbandonTransaction)(DWORD idInst, HCONV hConv, DWORD idTransaction);
static WINAPI BOOL (*pDdeDisconnect)(HCONV hConv);
static WINAPI BOOL (*pDdeImpersonateClient)(HCONV hConv);

extern WINAPI HCONVLIST wine32b_DdeConnectList(DWORD idInst, HSZ hszService, HSZ hszTopic, HCONVLIST hConvList, PCONVCONTEXT pCC)
{
	TRACE("Enter DdeConnectList\n");
	return pDdeConnectList(idInst, hszService, hszTopic, hConvList, pCC);
}

extern WINAPI void wine32a_DdeConnectList(void);
__ASM_GLOBAL_FUNC(wine32a_DdeConnectList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeConnectList") "\n"
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

extern WINAPI HCONV wine32b_DdeQueryNextServer(HCONVLIST hConvList, HCONV hConvPrev)
{
	TRACE("Enter DdeQueryNextServer\n");
	return pDdeQueryNextServer(hConvList, hConvPrev);
}

extern WINAPI void wine32a_DdeQueryNextServer(void);
__ASM_GLOBAL_FUNC(wine32a_DdeQueryNextServer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeQueryNextServer") "\n"
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

extern WINAPI BOOL wine32b_DdeDisconnectList(HCONVLIST hConvList)
{
	TRACE("Enter DdeDisconnectList\n");
	return pDdeDisconnectList(hConvList);
}

extern WINAPI void wine32a_DdeDisconnectList(void);
__ASM_GLOBAL_FUNC(wine32a_DdeDisconnectList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeDisconnectList") "\n"
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

extern WINAPI HCONV wine32b_DdeConnect(DWORD idInst, HSZ hszService, HSZ hszTopic, PCONVCONTEXT pCC)
{
	TRACE("Enter DdeConnect\n");
	return pDdeConnect(idInst, hszService, hszTopic, pCC);
}

extern WINAPI void wine32a_DdeConnect(void);
__ASM_GLOBAL_FUNC(wine32a_DdeConnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeConnect") "\n"
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

extern WINAPI HCONV wine32b_DdeReconnect(HCONV hConv)
{
	TRACE("Enter DdeReconnect\n");
	return pDdeReconnect(hConv);
}

extern WINAPI void wine32a_DdeReconnect(void);
__ASM_GLOBAL_FUNC(wine32a_DdeReconnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeReconnect") "\n"
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

extern WINAPI HDDEDATA wine32b_DdeClientTransaction(LPBYTE pData, DWORD cbData, HCONV hConv, HSZ hszItem, UINT wFmt, UINT wType, DWORD dwTimeout, LPDWORD pdwResult)
{
	TRACE("Enter DdeClientTransaction\n");
	return pDdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult);
}

extern WINAPI void wine32a_DdeClientTransaction(void);
__ASM_GLOBAL_FUNC(wine32a_DdeClientTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeClientTransaction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DdeAbandonTransaction(DWORD idInst, HCONV hConv, DWORD idTransaction)
{
	TRACE("Enter DdeAbandonTransaction\n");
	return pDdeAbandonTransaction(idInst, hConv, idTransaction);
}

extern WINAPI void wine32a_DdeAbandonTransaction(void);
__ASM_GLOBAL_FUNC(wine32a_DdeAbandonTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeAbandonTransaction") "\n"
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

extern WINAPI BOOL wine32b_DdeDisconnect(HCONV hConv)
{
	TRACE("Enter DdeDisconnect\n");
	return pDdeDisconnect(hConv);
}

extern WINAPI void wine32a_DdeDisconnect(void);
__ASM_GLOBAL_FUNC(wine32a_DdeDisconnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeDisconnect") "\n"
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

extern WINAPI BOOL wine32b_DdeImpersonateClient(HCONV hConv)
{
	TRACE("Enter DdeImpersonateClient\n");
	return pDdeImpersonateClient(hConv);
}

extern WINAPI void wine32a_DdeImpersonateClient(void);
__ASM_GLOBAL_FUNC(wine32a_DdeImpersonateClient,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeImpersonateClient") "\n"
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

static WINAPI LPARAM (*pPackDDElParam)(UINT msg, UINT_PTR uiLo, UINT_PTR uiHi);
static WINAPI BOOL (*pUnpackDDElParam)(UINT msg, LPARAM lParam, PUINT_PTR uiLo, PUINT_PTR uiHi);
static WINAPI BOOL (*pFreeDDElParam)(UINT msg, LPARAM lParam);
static WINAPI LPARAM (*pReuseDDElParam)(LPARAM lParam, UINT msgIn, UINT msgOut, UINT_PTR uiLo, UINT_PTR uiHi);
static WINAPI BOOL (*pImpersonateDdeClientWindow)(HWND hWndClient, HWND hWndServer);
static WINAPI BOOL (*pDdeSetQualityOfService)(HWND hwndClient, const SECURITY_QUALITY_OF_SERVICE * pqosNew, PSECURITY_QUALITY_OF_SERVICE pqosPrev);
static WINAPI UINT (*pDdeGetLastError)(DWORD idInst);
static WINAPI DWORD (*pDdeQueryStringA)(DWORD idInst, HSZ hsz, LPSTR psz, DWORD cchMax, INT iCodePage);
static WINAPI DWORD (*pDdeQueryStringW)(DWORD idInst, HSZ hsz, LPWSTR psz, DWORD cchMax, INT iCodePage);
static WINAPI HSZ (*pDdeCreateStringHandleA)(DWORD idInst, LPCSTR psz, INT codepage);
static WINAPI HSZ (*pDdeCreateStringHandleW)(DWORD idInst, LPCWSTR psz, INT codepage);
static WINAPI BOOL (*pDdeFreeStringHandle)(DWORD idInst, HSZ hsz);
static WINAPI BOOL (*pDdeKeepStringHandle)(DWORD idInst, HSZ hsz);
static WINAPI INT (*pDdeCmpStringHandles)(HSZ hsz1, HSZ hsz2);
static WINAPI UINT (*pDdeInitializeA)(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes);
static WINAPI UINT (*pDdeInitializeW)(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes);
static WINAPI BOOL (*pDdeUninitialize)(DWORD idInst);
static WINAPI HDDEDATA (*pDdeCreateDataHandle)(DWORD idInst, LPBYTE pSrc, DWORD cb, DWORD cbOff, HSZ hszItem, UINT wFmt, UINT afCmd);
static WINAPI HDDEDATA (*pDdeAddData)(HDDEDATA hData, LPBYTE pSrc, DWORD cb, DWORD cbOff);
static WINAPI DWORD (*pDdeGetData)(HDDEDATA hData, LPBYTE pDst, DWORD cbMax, DWORD cbOff);
static WINAPI LPBYTE (*pDdeAccessData)(HDDEDATA hData, LPDWORD pcbDataSize);
static WINAPI BOOL (*pDdeUnaccessData)(HDDEDATA hData);
static WINAPI BOOL (*pDdeFreeDataHandle)(HDDEDATA hData);
static WINAPI BOOL (*pDdeEnableCallback)(DWORD idInst, HCONV hConv, UINT wCmd);
static WINAPI BOOL (*pDdeSetUserHandle)(HCONV hConv, DWORD id, DWORD hUser);
static WINAPI UINT (*pDdeQueryConvInfo)(HCONV hConv, DWORD id, PCONVINFO lpConvInfo);

extern WINAPI LPARAM wine32b_PackDDElParam(UINT msg, UINT_PTR uiLo, UINT_PTR uiHi)
{
	TRACE("Enter PackDDElParam\n");
	return pPackDDElParam(msg, uiLo, uiHi);
}

extern WINAPI void wine32a_PackDDElParam(void);
__ASM_GLOBAL_FUNC(wine32a_PackDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PackDDElParam") "\n"
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

extern WINAPI BOOL wine32b_UnpackDDElParam(UINT msg, LPARAM lParam, PUINT_PTR uiLo, PUINT_PTR uiHi)
{
	TRACE("Enter UnpackDDElParam\n");
	return pUnpackDDElParam(msg, lParam, uiLo, uiHi);
}

extern WINAPI void wine32a_UnpackDDElParam(void);
__ASM_GLOBAL_FUNC(wine32a_UnpackDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnpackDDElParam") "\n"
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

extern WINAPI BOOL wine32b_FreeDDElParam(UINT msg, LPARAM lParam)
{
	TRACE("Enter FreeDDElParam\n");
	return pFreeDDElParam(msg, lParam);
}

extern WINAPI void wine32a_FreeDDElParam(void);
__ASM_GLOBAL_FUNC(wine32a_FreeDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeDDElParam") "\n"
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

extern WINAPI LPARAM wine32b_ReuseDDElParam(LPARAM lParam, UINT msgIn, UINT msgOut, UINT_PTR uiLo, UINT_PTR uiHi)
{
	TRACE("Enter ReuseDDElParam\n");
	return pReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi);
}

extern WINAPI void wine32a_ReuseDDElParam(void);
__ASM_GLOBAL_FUNC(wine32a_ReuseDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReuseDDElParam") "\n"
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

extern WINAPI BOOL wine32b_ImpersonateDdeClientWindow(HWND hWndClient, HWND hWndServer)
{
	TRACE("Enter ImpersonateDdeClientWindow\n");
	return pImpersonateDdeClientWindow(hWndClient, hWndServer);
}

extern WINAPI void wine32a_ImpersonateDdeClientWindow(void);
__ASM_GLOBAL_FUNC(wine32a_ImpersonateDdeClientWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ImpersonateDdeClientWindow") "\n"
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

extern WINAPI BOOL wine32b_DdeSetQualityOfService(HWND hwndClient, const SECURITY_QUALITY_OF_SERVICE * pqosNew, PSECURITY_QUALITY_OF_SERVICE pqosPrev)
{
	TRACE("Enter DdeSetQualityOfService\n");
	return pDdeSetQualityOfService(hwndClient, pqosNew, pqosPrev);
}

extern WINAPI void wine32a_DdeSetQualityOfService(void);
__ASM_GLOBAL_FUNC(wine32a_DdeSetQualityOfService,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeSetQualityOfService") "\n"
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

extern WINAPI UINT wine32b_DdeGetLastError(DWORD idInst)
{
	TRACE("Enter DdeGetLastError\n");
	return pDdeGetLastError(idInst);
}

extern WINAPI void wine32a_DdeGetLastError(void);
__ASM_GLOBAL_FUNC(wine32a_DdeGetLastError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeGetLastError") "\n"
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

extern WINAPI DWORD wine32b_DdeQueryStringA(DWORD idInst, HSZ hsz, LPSTR psz, DWORD cchMax, INT iCodePage)
{
	TRACE("Enter DdeQueryStringA\n");
	return pDdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage);
}

extern WINAPI void wine32a_DdeQueryStringA(void);
__ASM_GLOBAL_FUNC(wine32a_DdeQueryStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeQueryStringA") "\n"
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

extern WINAPI DWORD wine32b_DdeQueryStringW(DWORD idInst, HSZ hsz, LPWSTR psz, DWORD cchMax, INT iCodePage)
{
	TRACE("Enter DdeQueryStringW\n");
	return pDdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage);
}

extern WINAPI void wine32a_DdeQueryStringW(void);
__ASM_GLOBAL_FUNC(wine32a_DdeQueryStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeQueryStringW") "\n"
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

extern WINAPI HSZ wine32b_DdeCreateStringHandleA(DWORD idInst, LPCSTR psz, INT codepage)
{
	TRACE("Enter DdeCreateStringHandleA\n");
	return pDdeCreateStringHandleA(idInst, psz, codepage);
}

extern WINAPI void wine32a_DdeCreateStringHandleA(void);
__ASM_GLOBAL_FUNC(wine32a_DdeCreateStringHandleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeCreateStringHandleA") "\n"
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

extern WINAPI HSZ wine32b_DdeCreateStringHandleW(DWORD idInst, LPCWSTR psz, INT codepage)
{
	TRACE("Enter DdeCreateStringHandleW\n");
	return pDdeCreateStringHandleW(idInst, psz, codepage);
}

extern WINAPI void wine32a_DdeCreateStringHandleW(void);
__ASM_GLOBAL_FUNC(wine32a_DdeCreateStringHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeCreateStringHandleW") "\n"
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

extern WINAPI BOOL wine32b_DdeFreeStringHandle(DWORD idInst, HSZ hsz)
{
	TRACE("Enter DdeFreeStringHandle\n");
	return pDdeFreeStringHandle(idInst, hsz);
}

extern WINAPI void wine32a_DdeFreeStringHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DdeFreeStringHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeFreeStringHandle") "\n"
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

extern WINAPI BOOL wine32b_DdeKeepStringHandle(DWORD idInst, HSZ hsz)
{
	TRACE("Enter DdeKeepStringHandle\n");
	return pDdeKeepStringHandle(idInst, hsz);
}

extern WINAPI void wine32a_DdeKeepStringHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DdeKeepStringHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeKeepStringHandle") "\n"
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

extern WINAPI INT wine32b_DdeCmpStringHandles(HSZ hsz1, HSZ hsz2)
{
	TRACE("Enter DdeCmpStringHandles\n");
	return pDdeCmpStringHandles(hsz1, hsz2);
}

extern WINAPI void wine32a_DdeCmpStringHandles(void);
__ASM_GLOBAL_FUNC(wine32a_DdeCmpStringHandles,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeCmpStringHandles") "\n"
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

extern WINAPI UINT wine32b_DdeInitializeA(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes)
{
	TRACE("Enter DdeInitializeA\n");
	return pDdeInitializeA(pidInst, pfnCallback, afCmd, ulRes);
}

extern WINAPI void wine32a_DdeInitializeA(void);
__ASM_GLOBAL_FUNC(wine32a_DdeInitializeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeInitializeA") "\n"
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

extern WINAPI UINT wine32b_DdeInitializeW(LPDWORD pidInst, PFNCALLBACK pfnCallback, DWORD afCmd, DWORD ulRes)
{
	TRACE("Enter DdeInitializeW\n");
	return pDdeInitializeW(pidInst, pfnCallback, afCmd, ulRes);
}

extern WINAPI void wine32a_DdeInitializeW(void);
__ASM_GLOBAL_FUNC(wine32a_DdeInitializeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeInitializeW") "\n"
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

extern WINAPI BOOL wine32b_DdeUninitialize(DWORD idInst)
{
	TRACE("Enter DdeUninitialize\n");
	return pDdeUninitialize(idInst);
}

extern WINAPI void wine32a_DdeUninitialize(void);
__ASM_GLOBAL_FUNC(wine32a_DdeUninitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeUninitialize") "\n"
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

extern WINAPI HDDEDATA wine32b_DdeCreateDataHandle(DWORD idInst, LPBYTE pSrc, DWORD cb, DWORD cbOff, HSZ hszItem, UINT wFmt, UINT afCmd)
{
	TRACE("Enter DdeCreateDataHandle\n");
	return pDdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd);
}

extern WINAPI void wine32a_DdeCreateDataHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DdeCreateDataHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeCreateDataHandle") "\n"
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

extern WINAPI HDDEDATA wine32b_DdeAddData(HDDEDATA hData, LPBYTE pSrc, DWORD cb, DWORD cbOff)
{
	TRACE("Enter DdeAddData\n");
	return pDdeAddData(hData, pSrc, cb, cbOff);
}

extern WINAPI void wine32a_DdeAddData(void);
__ASM_GLOBAL_FUNC(wine32a_DdeAddData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeAddData") "\n"
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

extern WINAPI DWORD wine32b_DdeGetData(HDDEDATA hData, LPBYTE pDst, DWORD cbMax, DWORD cbOff)
{
	TRACE("Enter DdeGetData\n");
	return pDdeGetData(hData, pDst, cbMax, cbOff);
}

extern WINAPI void wine32a_DdeGetData(void);
__ASM_GLOBAL_FUNC(wine32a_DdeGetData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeGetData") "\n"
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

extern WINAPI LPBYTE wine32b_DdeAccessData(HDDEDATA hData, LPDWORD pcbDataSize)
{
	TRACE("Enter DdeAccessData\n");
	return pDdeAccessData(hData, pcbDataSize);
}

extern WINAPI void wine32a_DdeAccessData(void);
__ASM_GLOBAL_FUNC(wine32a_DdeAccessData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeAccessData") "\n"
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

extern WINAPI BOOL wine32b_DdeUnaccessData(HDDEDATA hData)
{
	TRACE("Enter DdeUnaccessData\n");
	return pDdeUnaccessData(hData);
}

extern WINAPI void wine32a_DdeUnaccessData(void);
__ASM_GLOBAL_FUNC(wine32a_DdeUnaccessData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeUnaccessData") "\n"
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

extern WINAPI BOOL wine32b_DdeFreeDataHandle(HDDEDATA hData)
{
	TRACE("Enter DdeFreeDataHandle\n");
	return pDdeFreeDataHandle(hData);
}

extern WINAPI void wine32a_DdeFreeDataHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DdeFreeDataHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeFreeDataHandle") "\n"
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

extern WINAPI BOOL wine32b_DdeEnableCallback(DWORD idInst, HCONV hConv, UINT wCmd)
{
	TRACE("Enter DdeEnableCallback\n");
	return pDdeEnableCallback(idInst, hConv, wCmd);
}

extern WINAPI void wine32a_DdeEnableCallback(void);
__ASM_GLOBAL_FUNC(wine32a_DdeEnableCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeEnableCallback") "\n"
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

extern WINAPI BOOL wine32b_DdeSetUserHandle(HCONV hConv, DWORD id, DWORD hUser)
{
	TRACE("Enter DdeSetUserHandle\n");
	return pDdeSetUserHandle(hConv, id, hUser);
}

extern WINAPI void wine32a_DdeSetUserHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DdeSetUserHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeSetUserHandle") "\n"
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

extern WINAPI UINT wine32b_DdeQueryConvInfo(HCONV hConv, DWORD id, PCONVINFO lpConvInfo)
{
	TRACE("Enter DdeQueryConvInfo\n");
	return pDdeQueryConvInfo(hConv, id, lpConvInfo);
}

extern WINAPI void wine32a_DdeQueryConvInfo(void);
__ASM_GLOBAL_FUNC(wine32a_DdeQueryConvInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeQueryConvInfo") "\n"
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

static WINAPI BOOL (*pDdePostAdvise)(DWORD idInst, HSZ hszTopic, HSZ hszItem);
static WINAPI HDDEDATA (*pDdeNameService)(DWORD idInst, HSZ hsz1, HSZ hsz2, UINT afCmd);

extern WINAPI BOOL wine32b_DdePostAdvise(DWORD idInst, HSZ hszTopic, HSZ hszItem)
{
	TRACE("Enter DdePostAdvise\n");
	return pDdePostAdvise(idInst, hszTopic, hszItem);
}

extern WINAPI void wine32a_DdePostAdvise(void);
__ASM_GLOBAL_FUNC(wine32a_DdePostAdvise,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdePostAdvise") "\n"
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

extern WINAPI HDDEDATA wine32b_DdeNameService(DWORD idInst, HSZ hsz1, HSZ hsz2, UINT afCmd)
{
	TRACE("Enter DdeNameService\n");
	return pDdeNameService(idInst, hsz1, hsz2, afCmd);
}

extern WINAPI void wine32a_DdeNameService(void);
__ASM_GLOBAL_FUNC(wine32a_DdeNameService,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DdeNameService") "\n"
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

static WINAPI LRESULT (*pDefDlgProcA)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pDefDlgProcW)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern WINAPI LRESULT wine32b_DefDlgProcA(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefDlgProcA\n");
	return pDefDlgProcA(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_DefDlgProcA(void);
__ASM_GLOBAL_FUNC(wine32a_DefDlgProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefDlgProcA") "\n"
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

extern WINAPI LRESULT wine32b_DefDlgProcW(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefDlgProcW\n");
	return pDefDlgProcW(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_DefDlgProcW(void);
__ASM_GLOBAL_FUNC(wine32a_DefDlgProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefDlgProcW") "\n"
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

static WINAPI LRESULT (*pDefWindowProcA)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pDefWindowProcW)(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern WINAPI LRESULT wine32b_DefWindowProcA(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefWindowProcA\n");
	return pDefWindowProcA(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_DefWindowProcA(void);
__ASM_GLOBAL_FUNC(wine32a_DefWindowProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefWindowProcA") "\n"
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

extern WINAPI LRESULT wine32b_DefWindowProcW(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefWindowProcW\n");
	return pDefWindowProcW(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_DefWindowProcW(void);
__ASM_GLOBAL_FUNC(wine32a_DefWindowProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefWindowProcW") "\n"
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

static WINAPI BOOL (*pPaintDesktop)(HDC hdc);
static WINAPI BOOL (*pSetDeskWallPaper)(LPCSTR filename);

extern WINAPI BOOL wine32b_PaintDesktop(HDC hdc)
{
	TRACE("Enter PaintDesktop\n");
	return pPaintDesktop(hdc);
}

extern WINAPI void wine32a_PaintDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_PaintDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PaintDesktop") "\n"
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

extern WINAPI BOOL wine32b_SetDeskWallPaper(LPCSTR filename)
{
	TRACE("Enter SetDeskWallPaper\n");
	return pSetDeskWallPaper(filename);
}

extern WINAPI void wine32a_SetDeskWallPaper(void);
__ASM_GLOBAL_FUNC(wine32a_SetDeskWallPaper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDeskWallPaper") "\n"
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

static WINAPI HWND (*pCreateDialogParamA)(HINSTANCE hInst, LPCSTR name, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI HWND (*pCreateDialogParamW)(HINSTANCE hInst, LPCWSTR name, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI HWND (*pCreateDialogIndirectParamAorW)(HINSTANCE hInst, LPCVOID dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param, DWORD flags);
static WINAPI HWND (*pCreateDialogIndirectParamA)(HINSTANCE hInst, LPCDLGTEMPLATEA dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI HWND (*pCreateDialogIndirectParamW)(HINSTANCE hInst, LPCDLGTEMPLATEW dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI INT_PTR (*pDialogBoxParamA)(HINSTANCE hInst, LPCSTR name, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI INT_PTR (*pDialogBoxParamW)(HINSTANCE hInst, LPCWSTR name, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI INT_PTR (*pDialogBoxIndirectParamAorW)(HINSTANCE hInstance, LPCVOID template, HWND owner, DLGPROC dlgProc, LPARAM param, DWORD flags);
static WINAPI INT_PTR (*pDialogBoxIndirectParamA)(HINSTANCE hInstance, LPCDLGTEMPLATEA template, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI INT_PTR (*pDialogBoxIndirectParamW)(HINSTANCE hInstance, LPCDLGTEMPLATEW template, HWND owner, DLGPROC dlgProc, LPARAM param);
static WINAPI BOOL (*pEndDialog)(HWND hwnd, INT_PTR retval);
static WINAPI BOOL (*pIsDialogMessageW)(HWND hwndDlg, LPMSG msg);
static WINAPI INT (*pGetDlgCtrlID)(HWND hwnd);
static WINAPI HWND (*pGetDlgItem)(HWND hwndDlg, INT id);
static WINAPI LRESULT (*pSendDlgItemMessageA)(HWND hwnd, INT id, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pSendDlgItemMessageW)(HWND hwnd, INT id, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI BOOL (*pSetDlgItemTextA)(HWND hwnd, INT id, LPCSTR lpString);
static WINAPI BOOL (*pSetDlgItemTextW)(HWND hwnd, INT id, LPCWSTR lpString);
static WINAPI UINT (*pGetDlgItemTextA)(HWND hwnd, INT id, LPSTR str, INT len);
static WINAPI UINT (*pGetDlgItemTextW)(HWND hwnd, INT id, LPWSTR str, INT len);
static WINAPI BOOL (*pSetDlgItemInt)(HWND hwnd, INT id, UINT value, BOOL fSigned);
static WINAPI UINT (*pGetDlgItemInt)(HWND hwnd, INT id, BOOL * translated, BOOL fSigned);
static WINAPI BOOL (*pCheckDlgButton)(HWND hwnd, INT id, UINT check);
static WINAPI UINT (*pIsDlgButtonChecked)(HWND hwnd, int id);
static WINAPI BOOL (*pCheckRadioButton)(HWND hwndDlg, int firstID, int lastID, int checkID);
static WINAPI DWORD (*pGetDialogBaseUnits)(void);
static WINAPI BOOL (*pMapDialogRect)(HWND hwnd, LPRECT rect);
static WINAPI HWND (*pGetNextDlgGroupItem)(HWND hwndDlg, HWND hwndCtrl, BOOL fPrevious);
static WINAPI HWND (*pGetNextDlgTabItem)(HWND hwndDlg, HWND hwndCtrl, BOOL fPrevious);
static WINAPI BOOL (*pDlgDirSelectExA)(HWND hwnd, LPSTR str, INT len, INT id);
static WINAPI BOOL (*pDlgDirSelectExW)(HWND hwnd, LPWSTR str, INT len, INT id);
static WINAPI BOOL (*pDlgDirSelectComboBoxExA)(HWND hwnd, LPSTR str, INT len, INT id);
static WINAPI BOOL (*pDlgDirSelectComboBoxExW)(HWND hwnd, LPWSTR str, INT len, INT id);
static WINAPI INT (*pDlgDirListA)(HWND hDlg, LPSTR spec, INT idLBox, INT idStatic, UINT attrib);
static WINAPI INT (*pDlgDirListW)(HWND hDlg, LPWSTR spec, INT idLBox, INT idStatic, UINT attrib);
static WINAPI INT (*pDlgDirListComboBoxA)(HWND hDlg, LPSTR spec, INT idCBox, INT idStatic, UINT attrib);
static WINAPI INT (*pDlgDirListComboBoxW)(HWND hDlg, LPWSTR spec, INT idCBox, INT idStatic, UINT attrib);

extern WINAPI HWND wine32b_CreateDialogParamA(HINSTANCE hInst, LPCSTR name, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter CreateDialogParamA\n");
	return pCreateDialogParamA(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_CreateDialogParamA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDialogParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDialogParamA") "\n"
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

extern WINAPI HWND wine32b_CreateDialogParamW(HINSTANCE hInst, LPCWSTR name, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter CreateDialogParamW\n");
	return pCreateDialogParamW(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_CreateDialogParamW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDialogParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDialogParamW") "\n"
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

extern WINAPI HWND wine32b_CreateDialogIndirectParamAorW(HINSTANCE hInst, LPCVOID dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param, DWORD flags)
{
	TRACE("Enter CreateDialogIndirectParamAorW\n");
	return pCreateDialogIndirectParamAorW(hInst, dlgTemplate, owner, dlgProc, param, flags);
}

extern WINAPI void wine32a_CreateDialogIndirectParamAorW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDialogIndirectParamAorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDialogIndirectParamAorW") "\n"
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

extern WINAPI HWND wine32b_CreateDialogIndirectParamA(HINSTANCE hInst, LPCDLGTEMPLATEA dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter CreateDialogIndirectParamA\n");
	return pCreateDialogIndirectParamA(hInst, dlgTemplate, owner, dlgProc, param);
}

extern WINAPI void wine32a_CreateDialogIndirectParamA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDialogIndirectParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDialogIndirectParamA") "\n"
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

extern WINAPI HWND wine32b_CreateDialogIndirectParamW(HINSTANCE hInst, LPCDLGTEMPLATEW dlgTemplate, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter CreateDialogIndirectParamW\n");
	return pCreateDialogIndirectParamW(hInst, dlgTemplate, owner, dlgProc, param);
}

extern WINAPI void wine32a_CreateDialogIndirectParamW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDialogIndirectParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDialogIndirectParamW") "\n"
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

extern WINAPI INT_PTR wine32b_DialogBoxParamA(HINSTANCE hInst, LPCSTR name, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter DialogBoxParamA\n");
	return pDialogBoxParamA(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_DialogBoxParamA(void);
__ASM_GLOBAL_FUNC(wine32a_DialogBoxParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DialogBoxParamA") "\n"
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

extern WINAPI INT_PTR wine32b_DialogBoxParamW(HINSTANCE hInst, LPCWSTR name, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter DialogBoxParamW\n");
	return pDialogBoxParamW(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_DialogBoxParamW(void);
__ASM_GLOBAL_FUNC(wine32a_DialogBoxParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DialogBoxParamW") "\n"
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

extern WINAPI INT_PTR wine32b_DialogBoxIndirectParamAorW(HINSTANCE hInstance, LPCVOID template, HWND owner, DLGPROC dlgProc, LPARAM param, DWORD flags)
{
	TRACE("Enter DialogBoxIndirectParamAorW\n");
	return pDialogBoxIndirectParamAorW(hInstance, template, owner, dlgProc, param, flags);
}

extern WINAPI void wine32a_DialogBoxIndirectParamAorW(void);
__ASM_GLOBAL_FUNC(wine32a_DialogBoxIndirectParamAorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DialogBoxIndirectParamAorW") "\n"
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

extern WINAPI INT_PTR wine32b_DialogBoxIndirectParamA(HINSTANCE hInstance, LPCDLGTEMPLATEA template, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter DialogBoxIndirectParamA\n");
	return pDialogBoxIndirectParamA(hInstance, template, owner, dlgProc, param);
}

extern WINAPI void wine32a_DialogBoxIndirectParamA(void);
__ASM_GLOBAL_FUNC(wine32a_DialogBoxIndirectParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DialogBoxIndirectParamA") "\n"
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

extern WINAPI INT_PTR wine32b_DialogBoxIndirectParamW(HINSTANCE hInstance, LPCDLGTEMPLATEW template, HWND owner, DLGPROC dlgProc, LPARAM param)
{
	TRACE("Enter DialogBoxIndirectParamW\n");
	return pDialogBoxIndirectParamW(hInstance, template, owner, dlgProc, param);
}

extern WINAPI void wine32a_DialogBoxIndirectParamW(void);
__ASM_GLOBAL_FUNC(wine32a_DialogBoxIndirectParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DialogBoxIndirectParamW") "\n"
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

extern WINAPI BOOL wine32b_EndDialog(HWND hwnd, INT_PTR retval)
{
	TRACE("Enter EndDialog\n");
	return pEndDialog(hwnd, retval);
}

extern WINAPI void wine32a_EndDialog(void);
__ASM_GLOBAL_FUNC(wine32a_EndDialog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndDialog") "\n"
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

extern WINAPI BOOL wine32b_IsDialogMessageW(HWND hwndDlg, LPMSG msg)
{
	TRACE("Enter IsDialogMessageW\n");
	return pIsDialogMessageW(hwndDlg, msg);
}

extern WINAPI void wine32a_IsDialogMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_IsDialogMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDialogMessageW") "\n"
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

extern WINAPI INT wine32b_GetDlgCtrlID(HWND hwnd)
{
	TRACE("Enter GetDlgCtrlID\n");
	return pGetDlgCtrlID(hwnd);
}

extern WINAPI void wine32a_GetDlgCtrlID(void);
__ASM_GLOBAL_FUNC(wine32a_GetDlgCtrlID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDlgCtrlID") "\n"
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

extern WINAPI HWND wine32b_GetDlgItem(HWND hwndDlg, INT id)
{
	TRACE("Enter GetDlgItem\n");
	return pGetDlgItem(hwndDlg, id);
}

extern WINAPI void wine32a_GetDlgItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetDlgItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDlgItem") "\n"
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

extern WINAPI LRESULT wine32b_SendDlgItemMessageA(HWND hwnd, INT id, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter SendDlgItemMessageA\n");
	return pSendDlgItemMessageA(hwnd, id, msg, wParam, lParam);
}

extern WINAPI void wine32a_SendDlgItemMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_SendDlgItemMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendDlgItemMessageA") "\n"
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

extern WINAPI LRESULT wine32b_SendDlgItemMessageW(HWND hwnd, INT id, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter SendDlgItemMessageW\n");
	return pSendDlgItemMessageW(hwnd, id, msg, wParam, lParam);
}

extern WINAPI void wine32a_SendDlgItemMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_SendDlgItemMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendDlgItemMessageW") "\n"
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

extern WINAPI BOOL wine32b_SetDlgItemTextA(HWND hwnd, INT id, LPCSTR lpString)
{
	TRACE("Enter SetDlgItemTextA\n");
	return pSetDlgItemTextA(hwnd, id, lpString);
}

extern WINAPI void wine32a_SetDlgItemTextA(void);
__ASM_GLOBAL_FUNC(wine32a_SetDlgItemTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDlgItemTextA") "\n"
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

extern WINAPI BOOL wine32b_SetDlgItemTextW(HWND hwnd, INT id, LPCWSTR lpString)
{
	TRACE("Enter SetDlgItemTextW\n");
	return pSetDlgItemTextW(hwnd, id, lpString);
}

extern WINAPI void wine32a_SetDlgItemTextW(void);
__ASM_GLOBAL_FUNC(wine32a_SetDlgItemTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDlgItemTextW") "\n"
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

extern WINAPI UINT wine32b_GetDlgItemTextA(HWND hwnd, INT id, LPSTR str, INT len)
{
	TRACE("Enter GetDlgItemTextA\n");
	return pGetDlgItemTextA(hwnd, id, str, len);
}

extern WINAPI void wine32a_GetDlgItemTextA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDlgItemTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDlgItemTextA") "\n"
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

extern WINAPI UINT wine32b_GetDlgItemTextW(HWND hwnd, INT id, LPWSTR str, INT len)
{
	TRACE("Enter GetDlgItemTextW\n");
	return pGetDlgItemTextW(hwnd, id, str, len);
}

extern WINAPI void wine32a_GetDlgItemTextW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDlgItemTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDlgItemTextW") "\n"
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

extern WINAPI BOOL wine32b_SetDlgItemInt(HWND hwnd, INT id, UINT value, BOOL fSigned)
{
	TRACE("Enter SetDlgItemInt\n");
	return pSetDlgItemInt(hwnd, id, value, fSigned);
}

extern WINAPI void wine32a_SetDlgItemInt(void);
__ASM_GLOBAL_FUNC(wine32a_SetDlgItemInt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDlgItemInt") "\n"
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

extern WINAPI UINT wine32b_GetDlgItemInt(HWND hwnd, INT id, BOOL * translated, BOOL fSigned)
{
	TRACE("Enter GetDlgItemInt\n");
	return pGetDlgItemInt(hwnd, id, translated, fSigned);
}

extern WINAPI void wine32a_GetDlgItemInt(void);
__ASM_GLOBAL_FUNC(wine32a_GetDlgItemInt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDlgItemInt") "\n"
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

extern WINAPI BOOL wine32b_CheckDlgButton(HWND hwnd, INT id, UINT check)
{
	TRACE("Enter CheckDlgButton\n");
	return pCheckDlgButton(hwnd, id, check);
}

extern WINAPI void wine32a_CheckDlgButton(void);
__ASM_GLOBAL_FUNC(wine32a_CheckDlgButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckDlgButton") "\n"
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

extern WINAPI UINT wine32b_IsDlgButtonChecked(HWND hwnd, int id)
{
	TRACE("Enter IsDlgButtonChecked\n");
	return pIsDlgButtonChecked(hwnd, id);
}

extern WINAPI void wine32a_IsDlgButtonChecked(void);
__ASM_GLOBAL_FUNC(wine32a_IsDlgButtonChecked,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDlgButtonChecked") "\n"
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

extern WINAPI BOOL wine32b_CheckRadioButton(HWND hwndDlg, int firstID, int lastID, int checkID)
{
	TRACE("Enter CheckRadioButton\n");
	return pCheckRadioButton(hwndDlg, firstID, lastID, checkID);
}

extern WINAPI void wine32a_CheckRadioButton(void);
__ASM_GLOBAL_FUNC(wine32a_CheckRadioButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckRadioButton") "\n"
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

extern WINAPI DWORD wine32b_GetDialogBaseUnits(void)
{
	TRACE("Enter GetDialogBaseUnits\n");
	return pGetDialogBaseUnits();
}

extern WINAPI void wine32a_GetDialogBaseUnits(void);
__ASM_GLOBAL_FUNC(wine32a_GetDialogBaseUnits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDialogBaseUnits") "\n"
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

extern WINAPI BOOL wine32b_MapDialogRect(HWND hwnd, LPRECT rect)
{
	TRACE("Enter MapDialogRect\n");
	return pMapDialogRect(hwnd, rect);
}

extern WINAPI void wine32a_MapDialogRect(void);
__ASM_GLOBAL_FUNC(wine32a_MapDialogRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapDialogRect") "\n"
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

extern WINAPI HWND wine32b_GetNextDlgGroupItem(HWND hwndDlg, HWND hwndCtrl, BOOL fPrevious)
{
	TRACE("Enter GetNextDlgGroupItem\n");
	return pGetNextDlgGroupItem(hwndDlg, hwndCtrl, fPrevious);
}

extern WINAPI void wine32a_GetNextDlgGroupItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetNextDlgGroupItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNextDlgGroupItem") "\n"
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

extern WINAPI HWND wine32b_GetNextDlgTabItem(HWND hwndDlg, HWND hwndCtrl, BOOL fPrevious)
{
	TRACE("Enter GetNextDlgTabItem\n");
	return pGetNextDlgTabItem(hwndDlg, hwndCtrl, fPrevious);
}

extern WINAPI void wine32a_GetNextDlgTabItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetNextDlgTabItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNextDlgTabItem") "\n"
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

extern WINAPI BOOL wine32b_DlgDirSelectExA(HWND hwnd, LPSTR str, INT len, INT id)
{
	TRACE("Enter DlgDirSelectExA\n");
	return pDlgDirSelectExA(hwnd, str, len, id);
}

extern WINAPI void wine32a_DlgDirSelectExA(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirSelectExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirSelectExA") "\n"
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

extern WINAPI BOOL wine32b_DlgDirSelectExW(HWND hwnd, LPWSTR str, INT len, INT id)
{
	TRACE("Enter DlgDirSelectExW\n");
	return pDlgDirSelectExW(hwnd, str, len, id);
}

extern WINAPI void wine32a_DlgDirSelectExW(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirSelectExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirSelectExW") "\n"
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

extern WINAPI BOOL wine32b_DlgDirSelectComboBoxExA(HWND hwnd, LPSTR str, INT len, INT id)
{
	TRACE("Enter DlgDirSelectComboBoxExA\n");
	return pDlgDirSelectComboBoxExA(hwnd, str, len, id);
}

extern WINAPI void wine32a_DlgDirSelectComboBoxExA(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirSelectComboBoxExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirSelectComboBoxExA") "\n"
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

extern WINAPI BOOL wine32b_DlgDirSelectComboBoxExW(HWND hwnd, LPWSTR str, INT len, INT id)
{
	TRACE("Enter DlgDirSelectComboBoxExW\n");
	return pDlgDirSelectComboBoxExW(hwnd, str, len, id);
}

extern WINAPI void wine32a_DlgDirSelectComboBoxExW(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirSelectComboBoxExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirSelectComboBoxExW") "\n"
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

extern WINAPI INT wine32b_DlgDirListA(HWND hDlg, LPSTR spec, INT idLBox, INT idStatic, UINT attrib)
{
	TRACE("Enter DlgDirListA\n");
	return pDlgDirListA(hDlg, spec, idLBox, idStatic, attrib);
}

extern WINAPI void wine32a_DlgDirListA(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirListA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirListA") "\n"
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

extern WINAPI INT wine32b_DlgDirListW(HWND hDlg, LPWSTR spec, INT idLBox, INT idStatic, UINT attrib)
{
	TRACE("Enter DlgDirListW\n");
	return pDlgDirListW(hDlg, spec, idLBox, idStatic, attrib);
}

extern WINAPI void wine32a_DlgDirListW(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirListW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirListW") "\n"
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

extern WINAPI INT wine32b_DlgDirListComboBoxA(HWND hDlg, LPSTR spec, INT idCBox, INT idStatic, UINT attrib)
{
	TRACE("Enter DlgDirListComboBoxA\n");
	return pDlgDirListComboBoxA(hDlg, spec, idCBox, idStatic, attrib);
}

extern WINAPI void wine32a_DlgDirListComboBoxA(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirListComboBoxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirListComboBoxA") "\n"
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

extern WINAPI INT wine32b_DlgDirListComboBoxW(HWND hDlg, LPWSTR spec, INT idCBox, INT idStatic, UINT attrib)
{
	TRACE("Enter DlgDirListComboBoxW\n");
	return pDlgDirListComboBoxW(hDlg, spec, idCBox, idStatic, attrib);
}

extern WINAPI void wine32a_DlgDirListComboBoxW(void);
__ASM_GLOBAL_FUNC(wine32a_DlgDirListComboBoxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DlgDirListComboBoxW") "\n"
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



static WINAPI UINT (*pPrivateExtractIconsW)(LPCWSTR lpwstrFile, int nIndex, int sizeX, int sizeY, HICON * phicon, UINT * pIconId, UINT nIcons, UINT flags);
static WINAPI UINT (*pPrivateExtractIconsA)(LPCSTR lpstrFile, int nIndex, int sizeX, int sizeY, HICON * phicon, UINT * piconid, UINT nIcons, UINT flags);
static WINAPI UINT (*pPrivateExtractIconExW)(LPCWSTR lpwstrFile, int nIndex, HICON * phIconLarge, HICON * phIconSmall, UINT nIcons);
static WINAPI UINT (*pPrivateExtractIconExA)(LPCSTR lpstrFile, int nIndex, HICON * phIconLarge, HICON * phIconSmall, UINT nIcons);

extern WINAPI UINT wine32b_PrivateExtractIconsW(LPCWSTR lpwstrFile, int nIndex, int sizeX, int sizeY, HICON * phicon, UINT * pIconId, UINT nIcons, UINT flags)
{
	TRACE("Enter PrivateExtractIconsW\n");
	return pPrivateExtractIconsW(lpwstrFile, nIndex, sizeX, sizeY, phicon, pIconId, nIcons, flags);
}

extern WINAPI void wine32a_PrivateExtractIconsW(void);
__ASM_GLOBAL_FUNC(wine32a_PrivateExtractIconsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrivateExtractIconsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_PrivateExtractIconsA(LPCSTR lpstrFile, int nIndex, int sizeX, int sizeY, HICON * phicon, UINT * piconid, UINT nIcons, UINT flags)
{
	TRACE("Enter PrivateExtractIconsA\n");
	return pPrivateExtractIconsA(lpstrFile, nIndex, sizeX, sizeY, phicon, piconid, nIcons, flags);
}

extern WINAPI void wine32a_PrivateExtractIconsA(void);
__ASM_GLOBAL_FUNC(wine32a_PrivateExtractIconsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrivateExtractIconsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_PrivateExtractIconExW(LPCWSTR lpwstrFile, int nIndex, HICON * phIconLarge, HICON * phIconSmall, UINT nIcons)
{
	TRACE("Enter PrivateExtractIconExW\n");
	return pPrivateExtractIconExW(lpwstrFile, nIndex, phIconLarge, phIconSmall, nIcons);
}

extern WINAPI void wine32a_PrivateExtractIconExW(void);
__ASM_GLOBAL_FUNC(wine32a_PrivateExtractIconExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrivateExtractIconExW") "\n"
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

extern WINAPI UINT wine32b_PrivateExtractIconExA(LPCSTR lpstrFile, int nIndex, HICON * phIconLarge, HICON * phIconSmall, UINT nIcons)
{
	TRACE("Enter PrivateExtractIconExA\n");
	return pPrivateExtractIconExA(lpstrFile, nIndex, phIconLarge, phIconSmall, nIcons);
}

extern WINAPI void wine32a_PrivateExtractIconExA(void);
__ASM_GLOBAL_FUNC(wine32a_PrivateExtractIconExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrivateExtractIconExA") "\n"
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

static WINAPI HWND (*pSetActiveWindow)(HWND hwnd);
static WINAPI HWND (*pSetFocus)(HWND hwnd);
static WINAPI BOOL (*pSetForegroundWindow)(HWND hwnd);
static WINAPI HWND (*pGetActiveWindow)(void);
static WINAPI HWND (*pGetFocus)(void);
static WINAPI HWND (*pGetForegroundWindow)(void);
static WINAPI BOOL (*pSetShellWindowEx)(HWND hwndShell, HWND hwndListView);
static WINAPI BOOL (*pSetShellWindow)(HWND hwndShell);
static WINAPI HWND (*pGetShellWindow)(void);
static WINAPI HWND (*pSetProgmanWindow)(HWND hwnd);
static WINAPI HWND (*pGetProgmanWindow)(void);
static WINAPI HWND (*pSetTaskmanWindow)(HWND hwnd);
static WINAPI HWND (*pGetTaskmanWindow)(void);

extern WINAPI HWND wine32b_SetActiveWindow(HWND hwnd)
{
	TRACE("Enter SetActiveWindow\n");
	return pSetActiveWindow(hwnd);
}

extern WINAPI void wine32a_SetActiveWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetActiveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetActiveWindow") "\n"
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

extern WINAPI HWND wine32b_SetFocus(HWND hwnd)
{
	TRACE("Enter SetFocus\n");
	return pSetFocus(hwnd);
}

extern WINAPI void wine32a_SetFocus(void);
__ASM_GLOBAL_FUNC(wine32a_SetFocus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetFocus") "\n"
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

extern WINAPI BOOL wine32b_SetForegroundWindow(HWND hwnd)
{
	TRACE("Enter SetForegroundWindow\n");
	return pSetForegroundWindow(hwnd);
}

extern WINAPI void wine32a_SetForegroundWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetForegroundWindow") "\n"
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

extern WINAPI HWND wine32b_GetActiveWindow(void)
{
	TRACE("Enter GetActiveWindow\n");
	return pGetActiveWindow();
}

extern WINAPI void wine32a_GetActiveWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetActiveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetActiveWindow") "\n"
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

extern WINAPI HWND wine32b_GetFocus(void)
{
	TRACE("Enter GetFocus\n");
	return pGetFocus();
}

extern WINAPI void wine32a_GetFocus(void);
__ASM_GLOBAL_FUNC(wine32a_GetFocus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFocus") "\n"
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

extern WINAPI HWND wine32b_GetForegroundWindow(void)
{
	TRACE("Enter GetForegroundWindow\n");
	return pGetForegroundWindow();
}

extern WINAPI void wine32a_GetForegroundWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetForegroundWindow") "\n"
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

extern WINAPI BOOL wine32b_SetShellWindowEx(HWND hwndShell, HWND hwndListView)
{
	TRACE("Enter SetShellWindowEx\n");
	return pSetShellWindowEx(hwndShell, hwndListView);
}

extern WINAPI void wine32a_SetShellWindowEx(void);
__ASM_GLOBAL_FUNC(wine32a_SetShellWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetShellWindowEx") "\n"
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

extern WINAPI BOOL wine32b_SetShellWindow(HWND hwndShell)
{
	TRACE("Enter SetShellWindow\n");
	return pSetShellWindow(hwndShell);
}

extern WINAPI void wine32a_SetShellWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetShellWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetShellWindow") "\n"
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

extern WINAPI HWND wine32b_GetShellWindow(void)
{
	TRACE("Enter GetShellWindow\n");
	return pGetShellWindow();
}

extern WINAPI void wine32a_GetShellWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetShellWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetShellWindow") "\n"
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

extern WINAPI HWND wine32b_SetProgmanWindow(HWND hwnd)
{
	TRACE("Enter SetProgmanWindow\n");
	return pSetProgmanWindow(hwnd);
}

extern WINAPI void wine32a_SetProgmanWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetProgmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProgmanWindow") "\n"
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

extern WINAPI HWND wine32b_GetProgmanWindow(void)
{
	TRACE("Enter GetProgmanWindow\n");
	return pGetProgmanWindow();
}

extern WINAPI void wine32a_GetProgmanWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetProgmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProgmanWindow") "\n"
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

extern WINAPI HWND wine32b_SetTaskmanWindow(HWND hwnd)
{
	TRACE("Enter SetTaskmanWindow\n");
	return pSetTaskmanWindow(hwnd);
}

extern WINAPI void wine32a_SetTaskmanWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetTaskmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTaskmanWindow") "\n"
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

extern WINAPI HWND wine32b_GetTaskmanWindow(void)
{
	TRACE("Enter GetTaskmanWindow\n");
	return pGetTaskmanWindow();
}

extern WINAPI void wine32a_GetTaskmanWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetTaskmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTaskmanWindow") "\n"
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

static WINAPI HHOOK (*pSetWindowsHookA)(INT id, HOOKPROC proc);
static WINAPI HHOOK (*pSetWindowsHookW)(INT id, HOOKPROC proc);
static WINAPI HHOOK (*pSetWindowsHookExA)(INT id, HOOKPROC proc, HINSTANCE inst, DWORD tid);
static WINAPI HHOOK (*pSetWindowsHookExW)(INT id, HOOKPROC proc, HINSTANCE inst, DWORD tid);
static WINAPI BOOL (*pUnhookWindowsHook)(INT id, HOOKPROC proc);
static WINAPI BOOL (*pUnhookWindowsHookEx)(HHOOK hhook);
static WINAPI LRESULT (*pCallNextHookEx)(HHOOK hhook, INT code, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pCallMsgFilterA)(LPMSG msg, INT code);
static WINAPI BOOL (*pCallMsgFilterW)(LPMSG msg, INT code);
static WINAPI HWINEVENTHOOK (*pSetWinEventHook)(DWORD event_min, DWORD event_max, HMODULE inst, WINEVENTPROC proc, DWORD pid, DWORD tid, DWORD flags);
static WINAPI BOOL (*pUnhookWinEvent)(HWINEVENTHOOK hEventHook);
static WINAPI void (*pNotifyWinEvent)(DWORD event, HWND hwnd, LONG object_id, LONG child_id);
static WINAPI BOOL (*pIsWinEventHookInstalled)(DWORD dwEvent);

extern WINAPI HHOOK wine32b_SetWindowsHookA(INT id, HOOKPROC proc)
{
	TRACE("Enter SetWindowsHookA\n");
	return pSetWindowsHookA(id, proc);
}

extern WINAPI void wine32a_SetWindowsHookA(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowsHookA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowsHookA") "\n"
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

extern WINAPI HHOOK wine32b_SetWindowsHookW(INT id, HOOKPROC proc)
{
	TRACE("Enter SetWindowsHookW\n");
	return pSetWindowsHookW(id, proc);
}

extern WINAPI void wine32a_SetWindowsHookW(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowsHookW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowsHookW") "\n"
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

extern WINAPI HHOOK wine32b_SetWindowsHookExA(INT id, HOOKPROC proc, HINSTANCE inst, DWORD tid)
{
	TRACE("Enter SetWindowsHookExA\n");
	return pSetWindowsHookExA(id, proc, inst, tid);
}

extern WINAPI void wine32a_SetWindowsHookExA(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowsHookExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowsHookExA") "\n"
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

extern WINAPI HHOOK wine32b_SetWindowsHookExW(INT id, HOOKPROC proc, HINSTANCE inst, DWORD tid)
{
	TRACE("Enter SetWindowsHookExW\n");
	return pSetWindowsHookExW(id, proc, inst, tid);
}

extern WINAPI void wine32a_SetWindowsHookExW(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowsHookExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowsHookExW") "\n"
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

extern WINAPI BOOL wine32b_UnhookWindowsHook(INT id, HOOKPROC proc)
{
	TRACE("Enter UnhookWindowsHook\n");
	return pUnhookWindowsHook(id, proc);
}

extern WINAPI void wine32a_UnhookWindowsHook(void);
__ASM_GLOBAL_FUNC(wine32a_UnhookWindowsHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnhookWindowsHook") "\n"
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

extern WINAPI BOOL wine32b_UnhookWindowsHookEx(HHOOK hhook)
{
	TRACE("Enter UnhookWindowsHookEx\n");
	return pUnhookWindowsHookEx(hhook);
}

extern WINAPI void wine32a_UnhookWindowsHookEx(void);
__ASM_GLOBAL_FUNC(wine32a_UnhookWindowsHookEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnhookWindowsHookEx") "\n"
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

extern WINAPI LRESULT wine32b_CallNextHookEx(HHOOK hhook, INT code, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter CallNextHookEx\n");
	return pCallNextHookEx(hhook, code, wparam, lparam);
}

extern WINAPI void wine32a_CallNextHookEx(void);
__ASM_GLOBAL_FUNC(wine32a_CallNextHookEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallNextHookEx") "\n"
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

extern WINAPI BOOL wine32b_CallMsgFilterA(LPMSG msg, INT code)
{
	TRACE("Enter CallMsgFilterA\n");
	return pCallMsgFilterA(msg, code);
}

extern WINAPI void wine32a_CallMsgFilterA(void);
__ASM_GLOBAL_FUNC(wine32a_CallMsgFilterA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallMsgFilterA") "\n"
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

extern WINAPI BOOL wine32b_CallMsgFilterW(LPMSG msg, INT code)
{
	TRACE("Enter CallMsgFilterW\n");
	return pCallMsgFilterW(msg, code);
}

extern WINAPI void wine32a_CallMsgFilterW(void);
__ASM_GLOBAL_FUNC(wine32a_CallMsgFilterW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallMsgFilterW") "\n"
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

extern WINAPI HWINEVENTHOOK wine32b_SetWinEventHook(DWORD event_min, DWORD event_max, HMODULE inst, WINEVENTPROC proc, DWORD pid, DWORD tid, DWORD flags)
{
	TRACE("Enter SetWinEventHook\n");
	return pSetWinEventHook(event_min, event_max, inst, proc, pid, tid, flags);
}

extern WINAPI void wine32a_SetWinEventHook(void);
__ASM_GLOBAL_FUNC(wine32a_SetWinEventHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWinEventHook") "\n"
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

extern WINAPI BOOL wine32b_UnhookWinEvent(HWINEVENTHOOK hEventHook)
{
	TRACE("Enter UnhookWinEvent\n");
	return pUnhookWinEvent(hEventHook);
}

extern WINAPI void wine32a_UnhookWinEvent(void);
__ASM_GLOBAL_FUNC(wine32a_UnhookWinEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnhookWinEvent") "\n"
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

extern WINAPI void wine32b_NotifyWinEvent(DWORD event, HWND hwnd, LONG object_id, LONG child_id)
{
	TRACE("Enter NotifyWinEvent\n");
	return pNotifyWinEvent(event, hwnd, object_id, child_id);
}

extern WINAPI void wine32a_NotifyWinEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NotifyWinEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NotifyWinEvent") "\n"
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

extern WINAPI BOOL wine32b_IsWinEventHookInstalled(DWORD dwEvent)
{
	TRACE("Enter IsWinEventHookInstalled\n");
	return pIsWinEventHookInstalled(dwEvent);
}

extern WINAPI void wine32a_IsWinEventHookInstalled(void);
__ASM_GLOBAL_FUNC(wine32a_IsWinEventHookInstalled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWinEventHookInstalled") "\n"
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


static WINAPI BOOL (*p__wine_send_input)(HWND hwnd, const INPUT * input);
static WINAPI UINT (*pSendInput)(UINT count, LPINPUT inputs, int size);
static WINAPI void (*pkeybd_event)(BYTE bVk, BYTE bScan, DWORD dwFlags, ULONG_PTR dwExtraInfo);
static WINAPI void (*pmouse_event)(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo);
static WINAPI BOOL (*pGetCursorPos)(POINT * pt);
static WINAPI BOOL (*pGetCursorInfo)(PCURSORINFO pci);
static WINAPI BOOL (*pSetCursorPos)(INT x, INT y);
static WINAPI HWND (*pSetCapture)(HWND hwnd);
static WINAPI BOOL (*pReleaseCapture)(void);
static WINAPI HWND (*pGetCapture)(void);
static WINAPI SHORT (*pGetAsyncKeyState)(INT key);
static WINAPI DWORD (*pGetQueueStatus)(UINT flags);
static WINAPI BOOL (*pGetInputState)(void);
static WINAPI BOOL (*pGetLastInputInfo)(PLASTINPUTINFO plii);
static WINAPI BOOL (*pAttachThreadInput)(DWORD from, DWORD to, BOOL attach);
static WINAPI SHORT (*pGetKeyState)(INT vkey);
static WINAPI BOOL (*pGetKeyboardState)(LPBYTE state);
static WINAPI BOOL (*pSetKeyboardState)(LPBYTE state);
static WINAPI SHORT (*pVkKeyScanA)(CHAR cChar);
static WINAPI SHORT (*pVkKeyScanW)(WCHAR cChar);
static WINAPI WORD (*pVkKeyScanExA)(CHAR cChar, HKL dwhkl);
static WINAPI WORD (*pVkKeyScanExW)(WCHAR cChar, HKL dwhkl);
static WINAPI DWORD (*pOemKeyScan)(WORD oem);
static WINAPI INT (*pGetKeyboardType)(INT nTypeFlag);
static WINAPI UINT (*pMapVirtualKeyA)(UINT code, UINT maptype);
static WINAPI UINT (*pMapVirtualKeyW)(UINT code, UINT maptype);
static WINAPI UINT (*pMapVirtualKeyExA)(UINT code, UINT maptype, HKL hkl);
static WINAPI UINT (*pMapVirtualKeyExW)(UINT code, UINT maptype, HKL hkl);
static WINAPI UINT (*pGetKBCodePage)(void);
static WINAPI HKL (*pGetKeyboardLayout)(DWORD thread_id);
static WINAPI BOOL (*pGetKeyboardLayoutNameA)(LPSTR pszKLID);
static WINAPI BOOL (*pGetKeyboardLayoutNameW)(LPWSTR pwszKLID);
static WINAPI INT (*pGetKeyNameTextA)(LONG lParam, LPSTR lpBuffer, INT nSize);
static WINAPI INT (*pGetKeyNameTextW)(LONG lParam, LPWSTR lpBuffer, INT nSize);
static WINAPI INT (*pToUnicode)(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWSTR lpwStr, int size, UINT flags);
static WINAPI INT (*pToUnicodeEx)(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWSTR lpwStr, int size, UINT flags, HKL hkl);
static WINAPI INT (*pToAscii)(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWORD lpChar, UINT flags);
static WINAPI INT (*pToAsciiEx)(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWORD lpChar, UINT flags, HKL dwhkl);
static WINAPI HKL (*pActivateKeyboardLayout)(HKL hLayout, UINT flags);
static WINAPI BOOL (*pBlockInput)(BOOL fBlockIt);
static WINAPI UINT (*pGetKeyboardLayoutList)(INT nBuff, HKL * layouts);
static WINAPI BOOL (*pRegisterHotKey)(HWND hwnd, INT id, UINT modifiers, UINT vk);
static WINAPI BOOL (*pUnregisterHotKey)(HWND hwnd, INT id);
static WINAPI HKL (*pLoadKeyboardLayoutW)(LPCWSTR pwszKLID, UINT Flags);
static WINAPI HKL (*pLoadKeyboardLayoutA)(LPCSTR pwszKLID, UINT Flags);
static WINAPI BOOL (*pUnloadKeyboardLayout)(HKL hkl);
static WINAPI BOOL (*pTrackMouseEvent)(TRACKMOUSEEVENT * ptme);
static WINAPI int (*pGetMouseMovePointsEx)(UINT size, LPMOUSEMOVEPOINT ptin, LPMOUSEMOVEPOINT ptout, int count, DWORD res);
static WINAPI BOOL (*pEnableMouseInPointer)(BOOL enable);

extern WINAPI BOOL wine32b___wine_send_input(HWND hwnd, const INPUT * input)
{
	TRACE("Enter __wine_send_input\n");
	return p__wine_send_input(hwnd, input);
}

extern WINAPI void wine32a___wine_send_input(void);
__ASM_GLOBAL_FUNC(wine32a___wine_send_input,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_send_input") "\n"
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

extern WINAPI UINT wine32b_SendInput(UINT count, LPINPUT inputs, int size)
{
	TRACE("Enter SendInput\n");
	return pSendInput(count, inputs, size);
}

extern WINAPI void wine32a_SendInput(void);
__ASM_GLOBAL_FUNC(wine32a_SendInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendInput") "\n"
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

extern WINAPI void wine32b_keybd_event(BYTE bVk, BYTE bScan, DWORD dwFlags, ULONG_PTR dwExtraInfo)
{
	TRACE("Enter keybd_event\n");
	return pkeybd_event(bVk, bScan, dwFlags, dwExtraInfo);
}

extern WINAPI void wine32a_keybd_event(void);
__ASM_GLOBAL_FUNC(wine32a_keybd_event,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_keybd_event") "\n"
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

extern WINAPI void wine32b_mouse_event(DWORD dwFlags, DWORD dx, DWORD dy, DWORD dwData, ULONG_PTR dwExtraInfo)
{
	TRACE("Enter mouse_event\n");
	return pmouse_event(dwFlags, dx, dy, dwData, dwExtraInfo);
}

extern WINAPI void wine32a_mouse_event(void);
__ASM_GLOBAL_FUNC(wine32a_mouse_event,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_mouse_event") "\n"
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

extern WINAPI BOOL wine32b_GetCursorPos(POINT * pt)
{
	TRACE("Enter GetCursorPos\n");
	return pGetCursorPos(pt);
}

extern WINAPI void wine32a_GetCursorPos(void);
__ASM_GLOBAL_FUNC(wine32a_GetCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCursorPos") "\n"
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

extern WINAPI BOOL wine32b_GetCursorInfo(PCURSORINFO pci)
{
	TRACE("Enter GetCursorInfo\n");
	return pGetCursorInfo(pci);
}

extern WINAPI void wine32a_GetCursorInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetCursorInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCursorInfo") "\n"
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

extern WINAPI BOOL wine32b_SetCursorPos(INT x, INT y)
{
	TRACE("Enter SetCursorPos\n");
	return pSetCursorPos(x, y);
}

extern WINAPI void wine32a_SetCursorPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCursorPos") "\n"
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

extern WINAPI HWND wine32b_SetCapture(HWND hwnd)
{
	TRACE("Enter SetCapture\n");
	return pSetCapture(hwnd);
}

extern WINAPI void wine32a_SetCapture(void);
__ASM_GLOBAL_FUNC(wine32a_SetCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCapture") "\n"
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

extern WINAPI BOOL wine32b_ReleaseCapture(void)
{
	TRACE("Enter ReleaseCapture\n");
	return pReleaseCapture();
}

extern WINAPI void wine32a_ReleaseCapture(void);
__ASM_GLOBAL_FUNC(wine32a_ReleaseCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReleaseCapture") "\n"
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

extern WINAPI HWND wine32b_GetCapture(void)
{
	TRACE("Enter GetCapture\n");
	return pGetCapture();
}

extern WINAPI void wine32a_GetCapture(void);
__ASM_GLOBAL_FUNC(wine32a_GetCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCapture") "\n"
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

extern WINAPI SHORT wine32b_GetAsyncKeyState(INT key)
{
	TRACE("Enter GetAsyncKeyState\n");
	return pGetAsyncKeyState(key);
}

extern WINAPI void wine32a_GetAsyncKeyState(void);
__ASM_GLOBAL_FUNC(wine32a_GetAsyncKeyState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAsyncKeyState") "\n"
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

extern WINAPI DWORD wine32b_GetQueueStatus(UINT flags)
{
	TRACE("Enter GetQueueStatus\n");
	return pGetQueueStatus(flags);
}

extern WINAPI void wine32a_GetQueueStatus(void);
__ASM_GLOBAL_FUNC(wine32a_GetQueueStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetQueueStatus") "\n"
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

extern WINAPI BOOL wine32b_GetInputState(void)
{
	TRACE("Enter GetInputState\n");
	return pGetInputState();
}

extern WINAPI void wine32a_GetInputState(void);
__ASM_GLOBAL_FUNC(wine32a_GetInputState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetInputState") "\n"
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

extern WINAPI BOOL wine32b_GetLastInputInfo(PLASTINPUTINFO plii)
{
	TRACE("Enter GetLastInputInfo\n");
	return pGetLastInputInfo(plii);
}

extern WINAPI void wine32a_GetLastInputInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetLastInputInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLastInputInfo") "\n"
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

extern WINAPI BOOL wine32b_AttachThreadInput(DWORD from, DWORD to, BOOL attach)
{
	TRACE("Enter AttachThreadInput\n");
	return pAttachThreadInput(from, to, attach);
}

extern WINAPI void wine32a_AttachThreadInput(void);
__ASM_GLOBAL_FUNC(wine32a_AttachThreadInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AttachThreadInput") "\n"
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

extern WINAPI SHORT wine32b_GetKeyState(INT vkey)
{
	TRACE("Enter GetKeyState\n");
	return pGetKeyState(vkey);
}

extern WINAPI void wine32a_GetKeyState(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyState") "\n"
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

extern WINAPI BOOL wine32b_GetKeyboardState(LPBYTE state)
{
	TRACE("Enter GetKeyboardState\n");
	return pGetKeyboardState(state);
}

extern WINAPI void wine32a_GetKeyboardState(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardState") "\n"
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

extern WINAPI BOOL wine32b_SetKeyboardState(LPBYTE state)
{
	TRACE("Enter SetKeyboardState\n");
	return pSetKeyboardState(state);
}

extern WINAPI void wine32a_SetKeyboardState(void);
__ASM_GLOBAL_FUNC(wine32a_SetKeyboardState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetKeyboardState") "\n"
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

extern WINAPI SHORT wine32b_VkKeyScanA(CHAR cChar)
{
	TRACE("Enter VkKeyScanA\n");
	return pVkKeyScanA(cChar);
}

extern WINAPI void wine32a_VkKeyScanA(void);
__ASM_GLOBAL_FUNC(wine32a_VkKeyScanA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VkKeyScanA") "\n"
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

extern WINAPI SHORT wine32b_VkKeyScanW(WCHAR cChar)
{
	TRACE("Enter VkKeyScanW\n");
	return pVkKeyScanW(cChar);
}

extern WINAPI void wine32a_VkKeyScanW(void);
__ASM_GLOBAL_FUNC(wine32a_VkKeyScanW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VkKeyScanW") "\n"
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

extern WINAPI WORD wine32b_VkKeyScanExA(CHAR cChar, HKL dwhkl)
{
	TRACE("Enter VkKeyScanExA\n");
	return pVkKeyScanExA(cChar, dwhkl);
}

extern WINAPI void wine32a_VkKeyScanExA(void);
__ASM_GLOBAL_FUNC(wine32a_VkKeyScanExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VkKeyScanExA") "\n"
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

extern WINAPI WORD wine32b_VkKeyScanExW(WCHAR cChar, HKL dwhkl)
{
	TRACE("Enter VkKeyScanExW\n");
	return pVkKeyScanExW(cChar, dwhkl);
}

extern WINAPI void wine32a_VkKeyScanExW(void);
__ASM_GLOBAL_FUNC(wine32a_VkKeyScanExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VkKeyScanExW") "\n"
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

extern WINAPI DWORD wine32b_OemKeyScan(WORD oem)
{
	TRACE("Enter OemKeyScan\n");
	return pOemKeyScan(oem);
}

extern WINAPI void wine32a_OemKeyScan(void);
__ASM_GLOBAL_FUNC(wine32a_OemKeyScan,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OemKeyScan") "\n"
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

extern WINAPI INT wine32b_GetKeyboardType(INT nTypeFlag)
{
	TRACE("Enter GetKeyboardType\n");
	return pGetKeyboardType(nTypeFlag);
}

extern WINAPI void wine32a_GetKeyboardType(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardType") "\n"
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

extern WINAPI UINT wine32b_MapVirtualKeyA(UINT code, UINT maptype)
{
	TRACE("Enter MapVirtualKeyA\n");
	return pMapVirtualKeyA(code, maptype);
}

extern WINAPI void wine32a_MapVirtualKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_MapVirtualKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapVirtualKeyA") "\n"
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

extern WINAPI UINT wine32b_MapVirtualKeyW(UINT code, UINT maptype)
{
	TRACE("Enter MapVirtualKeyW\n");
	return pMapVirtualKeyW(code, maptype);
}

extern WINAPI void wine32a_MapVirtualKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_MapVirtualKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapVirtualKeyW") "\n"
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

extern WINAPI UINT wine32b_MapVirtualKeyExA(UINT code, UINT maptype, HKL hkl)
{
	TRACE("Enter MapVirtualKeyExA\n");
	return pMapVirtualKeyExA(code, maptype, hkl);
}

extern WINAPI void wine32a_MapVirtualKeyExA(void);
__ASM_GLOBAL_FUNC(wine32a_MapVirtualKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapVirtualKeyExA") "\n"
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

extern WINAPI UINT wine32b_MapVirtualKeyExW(UINT code, UINT maptype, HKL hkl)
{
	TRACE("Enter MapVirtualKeyExW\n");
	return pMapVirtualKeyExW(code, maptype, hkl);
}

extern WINAPI void wine32a_MapVirtualKeyExW(void);
__ASM_GLOBAL_FUNC(wine32a_MapVirtualKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapVirtualKeyExW") "\n"
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

extern WINAPI UINT wine32b_GetKBCodePage(void)
{
	TRACE("Enter GetKBCodePage\n");
	return pGetKBCodePage();
}

extern WINAPI void wine32a_GetKBCodePage(void);
__ASM_GLOBAL_FUNC(wine32a_GetKBCodePage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKBCodePage") "\n"
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

extern WINAPI HKL wine32b_GetKeyboardLayout(DWORD thread_id)
{
	TRACE("Enter GetKeyboardLayout\n");
	return pGetKeyboardLayout(thread_id);
}

extern WINAPI void wine32a_GetKeyboardLayout(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardLayout") "\n"
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

extern WINAPI BOOL wine32b_GetKeyboardLayoutNameA(LPSTR pszKLID)
{
	TRACE("Enter GetKeyboardLayoutNameA\n");
	return pGetKeyboardLayoutNameA(pszKLID);
}

extern WINAPI void wine32a_GetKeyboardLayoutNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardLayoutNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardLayoutNameA") "\n"
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

extern WINAPI BOOL wine32b_GetKeyboardLayoutNameW(LPWSTR pwszKLID)
{
	TRACE("Enter GetKeyboardLayoutNameW\n");
	return pGetKeyboardLayoutNameW(pwszKLID);
}

extern WINAPI void wine32a_GetKeyboardLayoutNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardLayoutNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardLayoutNameW") "\n"
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

extern WINAPI INT wine32b_GetKeyNameTextA(LONG lParam, LPSTR lpBuffer, INT nSize)
{
	TRACE("Enter GetKeyNameTextA\n");
	return pGetKeyNameTextA(lParam, lpBuffer, nSize);
}

extern WINAPI void wine32a_GetKeyNameTextA(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyNameTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyNameTextA") "\n"
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

extern WINAPI INT wine32b_GetKeyNameTextW(LONG lParam, LPWSTR lpBuffer, INT nSize)
{
	TRACE("Enter GetKeyNameTextW\n");
	return pGetKeyNameTextW(lParam, lpBuffer, nSize);
}

extern WINAPI void wine32a_GetKeyNameTextW(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyNameTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyNameTextW") "\n"
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

extern WINAPI INT wine32b_ToUnicode(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWSTR lpwStr, int size, UINT flags)
{
	TRACE("Enter ToUnicode\n");
	return pToUnicode(virtKey, scanCode, lpKeyState, lpwStr, size, flags);
}

extern WINAPI void wine32a_ToUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_ToUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ToUnicode") "\n"
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

extern WINAPI INT wine32b_ToUnicodeEx(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWSTR lpwStr, int size, UINT flags, HKL hkl)
{
	TRACE("Enter ToUnicodeEx\n");
	return pToUnicodeEx(virtKey, scanCode, lpKeyState, lpwStr, size, flags, hkl);
}

extern WINAPI void wine32a_ToUnicodeEx(void);
__ASM_GLOBAL_FUNC(wine32a_ToUnicodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ToUnicodeEx") "\n"
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

extern WINAPI INT wine32b_ToAscii(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWORD lpChar, UINT flags)
{
	TRACE("Enter ToAscii\n");
	return pToAscii(virtKey, scanCode, lpKeyState, lpChar, flags);
}

extern WINAPI void wine32a_ToAscii(void);
__ASM_GLOBAL_FUNC(wine32a_ToAscii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ToAscii") "\n"
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

extern WINAPI INT wine32b_ToAsciiEx(UINT virtKey, UINT scanCode, const BYTE * lpKeyState, LPWORD lpChar, UINT flags, HKL dwhkl)
{
	TRACE("Enter ToAsciiEx\n");
	return pToAsciiEx(virtKey, scanCode, lpKeyState, lpChar, flags, dwhkl);
}

extern WINAPI void wine32a_ToAsciiEx(void);
__ASM_GLOBAL_FUNC(wine32a_ToAsciiEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ToAsciiEx") "\n"
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

extern WINAPI HKL wine32b_ActivateKeyboardLayout(HKL hLayout, UINT flags)
{
	TRACE("Enter ActivateKeyboardLayout\n");
	return pActivateKeyboardLayout(hLayout, flags);
}

extern WINAPI void wine32a_ActivateKeyboardLayout(void);
__ASM_GLOBAL_FUNC(wine32a_ActivateKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ActivateKeyboardLayout") "\n"
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

extern WINAPI BOOL wine32b_BlockInput(BOOL fBlockIt)
{
	TRACE("Enter BlockInput\n");
	return pBlockInput(fBlockIt);
}

extern WINAPI void wine32a_BlockInput(void);
__ASM_GLOBAL_FUNC(wine32a_BlockInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BlockInput") "\n"
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

extern WINAPI UINT wine32b_GetKeyboardLayoutList(INT nBuff, HKL * layouts)
{
	TRACE("Enter GetKeyboardLayoutList\n");
	return pGetKeyboardLayoutList(nBuff, layouts);
}

extern WINAPI void wine32a_GetKeyboardLayoutList(void);
__ASM_GLOBAL_FUNC(wine32a_GetKeyboardLayoutList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetKeyboardLayoutList") "\n"
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

extern WINAPI BOOL wine32b_RegisterHotKey(HWND hwnd, INT id, UINT modifiers, UINT vk)
{
	TRACE("Enter RegisterHotKey\n");
	return pRegisterHotKey(hwnd, id, modifiers, vk);
}

extern WINAPI void wine32a_RegisterHotKey(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterHotKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterHotKey") "\n"
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

extern WINAPI BOOL wine32b_UnregisterHotKey(HWND hwnd, INT id)
{
	TRACE("Enter UnregisterHotKey\n");
	return pUnregisterHotKey(hwnd, id);
}

extern WINAPI void wine32a_UnregisterHotKey(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterHotKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterHotKey") "\n"
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

extern WINAPI HKL wine32b_LoadKeyboardLayoutW(LPCWSTR pwszKLID, UINT Flags)
{
	TRACE("Enter LoadKeyboardLayoutW\n");
	return pLoadKeyboardLayoutW(pwszKLID, Flags);
}

extern WINAPI void wine32a_LoadKeyboardLayoutW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadKeyboardLayoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadKeyboardLayoutW") "\n"
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

extern WINAPI HKL wine32b_LoadKeyboardLayoutA(LPCSTR pwszKLID, UINT Flags)
{
	TRACE("Enter LoadKeyboardLayoutA\n");
	return pLoadKeyboardLayoutA(pwszKLID, Flags);
}

extern WINAPI void wine32a_LoadKeyboardLayoutA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadKeyboardLayoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadKeyboardLayoutA") "\n"
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

extern WINAPI BOOL wine32b_UnloadKeyboardLayout(HKL hkl)
{
	TRACE("Enter UnloadKeyboardLayout\n");
	return pUnloadKeyboardLayout(hkl);
}

extern WINAPI void wine32a_UnloadKeyboardLayout(void);
__ASM_GLOBAL_FUNC(wine32a_UnloadKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnloadKeyboardLayout") "\n"
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

extern WINAPI BOOL wine32b_TrackMouseEvent(TRACKMOUSEEVENT * ptme)
{
	TRACE("Enter TrackMouseEvent\n");
	return pTrackMouseEvent(ptme);
}

extern WINAPI void wine32a_TrackMouseEvent(void);
__ASM_GLOBAL_FUNC(wine32a_TrackMouseEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TrackMouseEvent") "\n"
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

extern WINAPI int wine32b_GetMouseMovePointsEx(UINT size, LPMOUSEMOVEPOINT ptin, LPMOUSEMOVEPOINT ptout, int count, DWORD res)
{
	TRACE("Enter GetMouseMovePointsEx\n");
	return pGetMouseMovePointsEx(size, ptin, ptout, count, res);
}

extern WINAPI void wine32a_GetMouseMovePointsEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetMouseMovePointsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMouseMovePointsEx") "\n"
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

extern WINAPI BOOL wine32b_EnableMouseInPointer(BOOL enable)
{
	TRACE("Enter EnableMouseInPointer\n");
	return pEnableMouseInPointer(enable);
}

extern WINAPI void wine32a_EnableMouseInPointer(void);
__ASM_GLOBAL_FUNC(wine32a_EnableMouseInPointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableMouseInPointer") "\n"
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

static WINAPI DWORD (*pGetListBoxInfo)(HWND hwnd);

extern WINAPI DWORD wine32b_GetListBoxInfo(HWND hwnd)
{
	TRACE("Enter GetListBoxInfo\n");
	return pGetListBoxInfo(hwnd);
}

extern WINAPI void wine32a_GetListBoxInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetListBoxInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetListBoxInfo") "\n"
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

static WINAPI LPSTR (*pCharNextA)(LPCSTR ptr);
static WINAPI LPSTR (*pCharNextExA)(WORD codepage, LPCSTR ptr, DWORD flags);
static WINAPI LPWSTR (*pCharNextExW)(WORD codepage, LPCWSTR ptr, DWORD flags);
static WINAPI LPWSTR (*pCharNextW)(LPCWSTR x);
static WINAPI LPSTR (*pCharPrevA)(LPCSTR start, LPCSTR ptr);
static WINAPI LPSTR (*pCharPrevExA)(WORD codepage, LPCSTR start, LPCSTR ptr, DWORD flags);
static WINAPI LPSTR (*pCharPrevExW)(WORD codepage, LPCWSTR start, LPCWSTR ptr, DWORD flags);
static WINAPI LPWSTR (*pCharPrevW)(LPCWSTR start, LPCWSTR x);
static WINAPI BOOL (*pCharToOemA)(LPCSTR s, LPSTR d);
static WINAPI BOOL (*pCharToOemBuffA)(LPCSTR s, LPSTR d, DWORD len);
static WINAPI BOOL (*pCharToOemBuffW)(LPCWSTR s, LPSTR d, DWORD len);
static WINAPI BOOL (*pCharToOemW)(LPCWSTR s, LPSTR d);
static WINAPI BOOL (*pOemToCharA)(LPCSTR s, LPSTR d);
static WINAPI BOOL (*pOemToCharBuffA)(LPCSTR s, LPSTR d, DWORD len);
static WINAPI BOOL (*pOemToCharBuffW)(LPCSTR s, LPWSTR d, DWORD len);
static WINAPI BOOL (*pOemToCharW)(LPCSTR s, LPWSTR d);
static WINAPI LPSTR (*pCharLowerA)(LPSTR str);
static WINAPI LPSTR (*pCharUpperA)(LPSTR str);
static WINAPI LPWSTR (*pCharLowerW)(LPWSTR str);
static WINAPI LPWSTR (*pCharUpperW)(LPWSTR str);
static WINAPI DWORD (*pCharLowerBuffA)(LPSTR str, DWORD len);
static WINAPI DWORD (*pCharLowerBuffW)(LPWSTR str, DWORD len);
static WINAPI DWORD (*pCharUpperBuffA)(LPSTR str, DWORD len);
static WINAPI DWORD (*pCharUpperBuffW)(LPWSTR str, DWORD len);
static WINAPI BOOL (*pIsCharLowerA)(CHAR x);
static WINAPI BOOL (*pIsCharLowerW)(WCHAR ch);
static WINAPI BOOL (*pIsCharUpperA)(CHAR x);
static WINAPI BOOL (*pIsCharUpperW)(WCHAR ch);
static WINAPI BOOL (*pIsCharAlphaNumericA)(CHAR x);
static WINAPI BOOL (*pIsCharAlphaNumericW)(WCHAR ch);
static WINAPI BOOL (*pIsCharAlphaA)(CHAR x);
static WINAPI BOOL (*pIsCharAlphaW)(WCHAR ch);

extern WINAPI LPSTR wine32b_CharNextA(LPCSTR ptr)
{
	TRACE("Enter CharNextA\n");
	return pCharNextA(ptr);
}

extern WINAPI void wine32a_CharNextA(void);
__ASM_GLOBAL_FUNC(wine32a_CharNextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharNextA") "\n"
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

extern WINAPI LPSTR wine32b_CharNextExA(WORD codepage, LPCSTR ptr, DWORD flags)
{
	TRACE("Enter CharNextExA\n");
	return pCharNextExA(codepage, ptr, flags);
}

extern WINAPI void wine32a_CharNextExA(void);
__ASM_GLOBAL_FUNC(wine32a_CharNextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharNextExA") "\n"
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

extern WINAPI LPWSTR wine32b_CharNextExW(WORD codepage, LPCWSTR ptr, DWORD flags)
{
	TRACE("Enter CharNextExW\n");
	return pCharNextExW(codepage, ptr, flags);
}

extern WINAPI void wine32a_CharNextExW(void);
__ASM_GLOBAL_FUNC(wine32a_CharNextExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharNextExW") "\n"
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

extern WINAPI LPWSTR wine32b_CharNextW(LPCWSTR x)
{
	TRACE("Enter CharNextW\n");
	return pCharNextW(x);
}

extern WINAPI void wine32a_CharNextW(void);
__ASM_GLOBAL_FUNC(wine32a_CharNextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharNextW") "\n"
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

extern WINAPI LPSTR wine32b_CharPrevA(LPCSTR start, LPCSTR ptr)
{
	TRACE("Enter CharPrevA\n");
	return pCharPrevA(start, ptr);
}

extern WINAPI void wine32a_CharPrevA(void);
__ASM_GLOBAL_FUNC(wine32a_CharPrevA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharPrevA") "\n"
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

extern WINAPI LPSTR wine32b_CharPrevExA(WORD codepage, LPCSTR start, LPCSTR ptr, DWORD flags)
{
	TRACE("Enter CharPrevExA\n");
	return pCharPrevExA(codepage, start, ptr, flags);
}

extern WINAPI void wine32a_CharPrevExA(void);
__ASM_GLOBAL_FUNC(wine32a_CharPrevExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharPrevExA") "\n"
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

extern WINAPI LPSTR wine32b_CharPrevExW(WORD codepage, LPCWSTR start, LPCWSTR ptr, DWORD flags)
{
	TRACE("Enter CharPrevExW\n");
	return pCharPrevExW(codepage, start, ptr, flags);
}

extern WINAPI void wine32a_CharPrevExW(void);
__ASM_GLOBAL_FUNC(wine32a_CharPrevExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharPrevExW") "\n"
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

extern WINAPI LPWSTR wine32b_CharPrevW(LPCWSTR start, LPCWSTR x)
{
	TRACE("Enter CharPrevW\n");
	return pCharPrevW(start, x);
}

extern WINAPI void wine32a_CharPrevW(void);
__ASM_GLOBAL_FUNC(wine32a_CharPrevW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharPrevW") "\n"
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

extern WINAPI BOOL wine32b_CharToOemA(LPCSTR s, LPSTR d)
{
	TRACE("Enter CharToOemA\n");
	return pCharToOemA(s, d);
}

extern WINAPI void wine32a_CharToOemA(void);
__ASM_GLOBAL_FUNC(wine32a_CharToOemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharToOemA") "\n"
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

extern WINAPI BOOL wine32b_CharToOemBuffA(LPCSTR s, LPSTR d, DWORD len)
{
	TRACE("Enter CharToOemBuffA\n");
	return pCharToOemBuffA(s, d, len);
}

extern WINAPI void wine32a_CharToOemBuffA(void);
__ASM_GLOBAL_FUNC(wine32a_CharToOemBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharToOemBuffA") "\n"
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

extern WINAPI BOOL wine32b_CharToOemBuffW(LPCWSTR s, LPSTR d, DWORD len)
{
	TRACE("Enter CharToOemBuffW\n");
	return pCharToOemBuffW(s, d, len);
}

extern WINAPI void wine32a_CharToOemBuffW(void);
__ASM_GLOBAL_FUNC(wine32a_CharToOemBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharToOemBuffW") "\n"
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

extern WINAPI BOOL wine32b_CharToOemW(LPCWSTR s, LPSTR d)
{
	TRACE("Enter CharToOemW\n");
	return pCharToOemW(s, d);
}

extern WINAPI void wine32a_CharToOemW(void);
__ASM_GLOBAL_FUNC(wine32a_CharToOemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharToOemW") "\n"
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

extern WINAPI BOOL wine32b_OemToCharA(LPCSTR s, LPSTR d)
{
	TRACE("Enter OemToCharA\n");
	return pOemToCharA(s, d);
}

extern WINAPI void wine32a_OemToCharA(void);
__ASM_GLOBAL_FUNC(wine32a_OemToCharA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OemToCharA") "\n"
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

extern WINAPI BOOL wine32b_OemToCharBuffA(LPCSTR s, LPSTR d, DWORD len)
{
	TRACE("Enter OemToCharBuffA\n");
	return pOemToCharBuffA(s, d, len);
}

extern WINAPI void wine32a_OemToCharBuffA(void);
__ASM_GLOBAL_FUNC(wine32a_OemToCharBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OemToCharBuffA") "\n"
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

extern WINAPI BOOL wine32b_OemToCharBuffW(LPCSTR s, LPWSTR d, DWORD len)
{
	TRACE("Enter OemToCharBuffW\n");
	return pOemToCharBuffW(s, d, len);
}

extern WINAPI void wine32a_OemToCharBuffW(void);
__ASM_GLOBAL_FUNC(wine32a_OemToCharBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OemToCharBuffW") "\n"
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

extern WINAPI BOOL wine32b_OemToCharW(LPCSTR s, LPWSTR d)
{
	TRACE("Enter OemToCharW\n");
	return pOemToCharW(s, d);
}

extern WINAPI void wine32a_OemToCharW(void);
__ASM_GLOBAL_FUNC(wine32a_OemToCharW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OemToCharW") "\n"
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

extern WINAPI LPSTR wine32b_CharLowerA(LPSTR str)
{
	TRACE("Enter CharLowerA\n");
	return pCharLowerA(str);
}

extern WINAPI void wine32a_CharLowerA(void);
__ASM_GLOBAL_FUNC(wine32a_CharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharLowerA") "\n"
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

extern WINAPI LPSTR wine32b_CharUpperA(LPSTR str)
{
	TRACE("Enter CharUpperA\n");
	return pCharUpperA(str);
}

extern WINAPI void wine32a_CharUpperA(void);
__ASM_GLOBAL_FUNC(wine32a_CharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharUpperA") "\n"
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

extern WINAPI LPWSTR wine32b_CharLowerW(LPWSTR str)
{
	TRACE("Enter CharLowerW\n");
	return pCharLowerW(str);
}

extern WINAPI void wine32a_CharLowerW(void);
__ASM_GLOBAL_FUNC(wine32a_CharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharLowerW") "\n"
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

extern WINAPI LPWSTR wine32b_CharUpperW(LPWSTR str)
{
	TRACE("Enter CharUpperW\n");
	return pCharUpperW(str);
}

extern WINAPI void wine32a_CharUpperW(void);
__ASM_GLOBAL_FUNC(wine32a_CharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharUpperW") "\n"
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

extern WINAPI DWORD wine32b_CharLowerBuffA(LPSTR str, DWORD len)
{
	TRACE("Enter CharLowerBuffA\n");
	return pCharLowerBuffA(str, len);
}

extern WINAPI void wine32a_CharLowerBuffA(void);
__ASM_GLOBAL_FUNC(wine32a_CharLowerBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharLowerBuffA") "\n"
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

extern WINAPI DWORD wine32b_CharLowerBuffW(LPWSTR str, DWORD len)
{
	TRACE("Enter CharLowerBuffW\n");
	return pCharLowerBuffW(str, len);
}

extern WINAPI void wine32a_CharLowerBuffW(void);
__ASM_GLOBAL_FUNC(wine32a_CharLowerBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharLowerBuffW") "\n"
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

extern WINAPI DWORD wine32b_CharUpperBuffA(LPSTR str, DWORD len)
{
	TRACE("Enter CharUpperBuffA\n");
	return pCharUpperBuffA(str, len);
}

extern WINAPI void wine32a_CharUpperBuffA(void);
__ASM_GLOBAL_FUNC(wine32a_CharUpperBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharUpperBuffA") "\n"
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

extern WINAPI DWORD wine32b_CharUpperBuffW(LPWSTR str, DWORD len)
{
	TRACE("Enter CharUpperBuffW\n");
	return pCharUpperBuffW(str, len);
}

extern WINAPI void wine32a_CharUpperBuffW(void);
__ASM_GLOBAL_FUNC(wine32a_CharUpperBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CharUpperBuffW") "\n"
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

extern WINAPI BOOL wine32b_IsCharLowerA(CHAR x)
{
	TRACE("Enter IsCharLowerA\n");
	return pIsCharLowerA(x);
}

extern WINAPI void wine32a_IsCharLowerA(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharLowerA") "\n"
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

extern WINAPI BOOL wine32b_IsCharLowerW(WCHAR ch)
{
	TRACE("Enter IsCharLowerW\n");
	return pIsCharLowerW(ch);
}

extern WINAPI void wine32a_IsCharLowerW(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharLowerW") "\n"
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

extern WINAPI BOOL wine32b_IsCharUpperA(CHAR x)
{
	TRACE("Enter IsCharUpperA\n");
	return pIsCharUpperA(x);
}

extern WINAPI void wine32a_IsCharUpperA(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharUpperA") "\n"
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

extern WINAPI BOOL wine32b_IsCharUpperW(WCHAR ch)
{
	TRACE("Enter IsCharUpperW\n");
	return pIsCharUpperW(ch);
}

extern WINAPI void wine32a_IsCharUpperW(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharUpperW") "\n"
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

extern WINAPI BOOL wine32b_IsCharAlphaNumericA(CHAR x)
{
	TRACE("Enter IsCharAlphaNumericA\n");
	return pIsCharAlphaNumericA(x);
}

extern WINAPI void wine32a_IsCharAlphaNumericA(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharAlphaNumericA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharAlphaNumericA") "\n"
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

extern WINAPI BOOL wine32b_IsCharAlphaNumericW(WCHAR ch)
{
	TRACE("Enter IsCharAlphaNumericW\n");
	return pIsCharAlphaNumericW(ch);
}

extern WINAPI void wine32a_IsCharAlphaNumericW(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharAlphaNumericW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharAlphaNumericW") "\n"
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

extern WINAPI BOOL wine32b_IsCharAlphaA(CHAR x)
{
	TRACE("Enter IsCharAlphaA\n");
	return pIsCharAlphaA(x);
}

extern WINAPI void wine32a_IsCharAlphaA(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharAlphaA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharAlphaA") "\n"
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

extern WINAPI BOOL wine32b_IsCharAlphaW(WCHAR ch)
{
	TRACE("Enter IsCharAlphaW\n");
	return pIsCharAlphaW(ch);
}

extern WINAPI void wine32a_IsCharAlphaW(void);
__ASM_GLOBAL_FUNC(wine32a_IsCharAlphaW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsCharAlphaW") "\n"
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

static WINAPI LRESULT (*pDefFrameProcA)(HWND hwnd, HWND hwndMDIClient, UINT message, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pDefFrameProcW)(HWND hwnd, HWND hwndMDIClient, UINT message, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pDefMDIChildProcA)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pDefMDIChildProcW)(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
static WINAPI HWND (*pCreateMDIWindowA)(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, INT X, INT Y, INT nWidth, INT nHeight, HWND hWndParent, HINSTANCE hInstance, LPARAM lParam);
static WINAPI HWND (*pCreateMDIWindowW)(LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, INT X, INT Y, INT nWidth, INT nHeight, HWND hWndParent, HINSTANCE hInstance, LPARAM lParam);
static WINAPI BOOL (*pTranslateMDISysAccel)(HWND hwndClient, LPMSG msg);
static WINAPI void (*pCalcChildScroll)(HWND hwnd, INT scroll);
static WINAPI void (*pScrollChildren)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
static WINAPI WORD (*pCascadeWindows)(HWND hwndParent, UINT wFlags, const RECT * lpRect, UINT cKids, const HWND * lpKids);
static WINAPI WORD (*pCascadeChildWindows)(HWND parent, UINT flags);
static WINAPI WORD (*pTileWindows)(HWND hwndParent, UINT wFlags, const RECT * lpRect, UINT cKids, const HWND * lpKids);
static WINAPI WORD (*pTileChildWindows)(HWND parent, UINT flags);

extern WINAPI LRESULT wine32b_DefFrameProcA(HWND hwnd, HWND hwndMDIClient, UINT message, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefFrameProcA\n");
	return pDefFrameProcA(hwnd, hwndMDIClient, message, wParam, lParam);
}

extern WINAPI void wine32a_DefFrameProcA(void);
__ASM_GLOBAL_FUNC(wine32a_DefFrameProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefFrameProcA") "\n"
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

extern WINAPI LRESULT wine32b_DefFrameProcW(HWND hwnd, HWND hwndMDIClient, UINT message, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefFrameProcW\n");
	return pDefFrameProcW(hwnd, hwndMDIClient, message, wParam, lParam);
}

extern WINAPI void wine32a_DefFrameProcW(void);
__ASM_GLOBAL_FUNC(wine32a_DefFrameProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefFrameProcW") "\n"
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

extern WINAPI LRESULT wine32b_DefMDIChildProcA(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefMDIChildProcA\n");
	return pDefMDIChildProcA(hwnd, message, wParam, lParam);
}

extern WINAPI void wine32a_DefMDIChildProcA(void);
__ASM_GLOBAL_FUNC(wine32a_DefMDIChildProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefMDIChildProcA") "\n"
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

extern WINAPI LRESULT wine32b_DefMDIChildProcW(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter DefMDIChildProcW\n");
	return pDefMDIChildProcW(hwnd, message, wParam, lParam);
}

extern WINAPI void wine32a_DefMDIChildProcW(void);
__ASM_GLOBAL_FUNC(wine32a_DefMDIChildProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefMDIChildProcW") "\n"
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

extern WINAPI HWND wine32b_CreateMDIWindowA(LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, INT X, INT Y, INT nWidth, INT nHeight, HWND hWndParent, HINSTANCE hInstance, LPARAM lParam)
{
	TRACE("Enter CreateMDIWindowA\n");
	return pCreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam);
}

extern WINAPI void wine32a_CreateMDIWindowA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMDIWindowA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMDIWindowA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_CreateMDIWindowW(LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, INT X, INT Y, INT nWidth, INT nHeight, HWND hWndParent, HINSTANCE hInstance, LPARAM lParam)
{
	TRACE("Enter CreateMDIWindowW\n");
	return pCreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam);
}

extern WINAPI void wine32a_CreateMDIWindowW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMDIWindowW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMDIWindowW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TranslateMDISysAccel(HWND hwndClient, LPMSG msg)
{
	TRACE("Enter TranslateMDISysAccel\n");
	return pTranslateMDISysAccel(hwndClient, msg);
}

extern WINAPI void wine32a_TranslateMDISysAccel(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateMDISysAccel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateMDISysAccel") "\n"
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

extern WINAPI void wine32b_CalcChildScroll(HWND hwnd, INT scroll)
{
	TRACE("Enter CalcChildScroll\n");
	return pCalcChildScroll(hwnd, scroll);
}

extern WINAPI void wine32a_CalcChildScroll(void);
__ASM_GLOBAL_FUNC(wine32a_CalcChildScroll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CalcChildScroll") "\n"
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

extern WINAPI void wine32b_ScrollChildren(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter ScrollChildren\n");
	return pScrollChildren(hWnd, uMsg, wParam, lParam);
}

extern WINAPI void wine32a_ScrollChildren(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollChildren,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollChildren") "\n"
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

extern WINAPI WORD wine32b_CascadeWindows(HWND hwndParent, UINT wFlags, const RECT * lpRect, UINT cKids, const HWND * lpKids)
{
	TRACE("Enter CascadeWindows\n");
	return pCascadeWindows(hwndParent, wFlags, lpRect, cKids, lpKids);
}

extern WINAPI void wine32a_CascadeWindows(void);
__ASM_GLOBAL_FUNC(wine32a_CascadeWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CascadeWindows") "\n"
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

extern WINAPI WORD wine32b_CascadeChildWindows(HWND parent, UINT flags)
{
	TRACE("Enter CascadeChildWindows\n");
	return pCascadeChildWindows(parent, flags);
}

extern WINAPI void wine32a_CascadeChildWindows(void);
__ASM_GLOBAL_FUNC(wine32a_CascadeChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CascadeChildWindows") "\n"
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

extern WINAPI WORD wine32b_TileWindows(HWND hwndParent, UINT wFlags, const RECT * lpRect, UINT cKids, const HWND * lpKids)
{
	TRACE("Enter TileWindows\n");
	return pTileWindows(hwndParent, wFlags, lpRect, cKids, lpKids);
}

extern WINAPI void wine32a_TileWindows(void);
__ASM_GLOBAL_FUNC(wine32a_TileWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TileWindows") "\n"
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

extern WINAPI WORD wine32b_TileChildWindows(HWND parent, UINT flags)
{
	TRACE("Enter TileChildWindows\n");
	return pTileChildWindows(parent, flags);
}

extern WINAPI void wine32a_TileChildWindows(void);
__ASM_GLOBAL_FUNC(wine32a_TileChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TileChildWindows") "\n"
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

static WINAPI DWORD (*pDrawMenuBarTemp)(HWND hwnd, HDC hDC, LPRECT lprect, HMENU hMenu, HFONT hFont);
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

static WINAPI LRESULT (*pSendMessageTimeoutW)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, UINT flags, UINT timeout, PDWORD_PTR res_ptr);
static WINAPI LRESULT (*pSendMessageTimeoutA)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, UINT flags, UINT timeout, PDWORD_PTR res_ptr);
static WINAPI LRESULT (*pSendMessageW)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI LRESULT (*pSendMessageA)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pSendNotifyMessageA)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pSendNotifyMessageW)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pSendMessageCallbackA)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, SENDASYNCPROC callback, ULONG_PTR data);
static WINAPI BOOL (*pSendMessageCallbackW)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, SENDASYNCPROC callback, ULONG_PTR data);
static WINAPI BOOL (*pReplyMessage)(LRESULT result);
static WINAPI BOOL (*pInSendMessage)(void);
static WINAPI DWORD (*pInSendMessageEx)(LPVOID reserved);
static WINAPI BOOL (*pPostMessageA)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pPostMessageW)(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pPostThreadMessageA)(DWORD thread, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI BOOL (*pPostThreadMessageW)(DWORD thread, UINT msg, WPARAM wparam, LPARAM lparam);
static WINAPI void (*pPostQuitMessage)(INT exit_code);
static WINAPI BOOL (*pPeekMessageW)(MSG * msg_out, HWND hwnd, UINT first, UINT last, UINT flags);
static WINAPI BOOL (*pPeekMessageA)(MSG * msg, HWND hwnd, UINT first, UINT last, UINT flags);
static WINAPI BOOL (*pGetMessageW)(MSG * msg, HWND hwnd, UINT first, UINT last);
static WINAPI BOOL (*pGetMessageA)(MSG * msg, HWND hwnd, UINT first, UINT last);
static WINAPI BOOL (*pIsDialogMessageA)(HWND hwndDlg, LPMSG pmsg);
static WINAPI BOOL (*pTranslateMessage)(const MSG * msg);
static WINAPI LRESULT (*pDispatchMessageA)(const MSG * msg);
static WINAPI LRESULT (*pDispatchMessageW)(const MSG * msg);
static WINAPI DWORD (*pGetMessagePos)(void);
static WINAPI LONG (*pGetMessageTime)(void);
static WINAPI LPARAM (*pGetMessageExtraInfo)(void);
static WINAPI LPARAM (*pSetMessageExtraInfo)(LPARAM lParam);
static WINAPI BOOL (*pGetCurrentInputMessageSource)(INPUT_MESSAGE_SOURCE * source);
static WINAPI BOOL (*pWaitMessage)(void);
static WINAPI DWORD (*pMsgWaitForMultipleObjectsEx)(DWORD count, const HANDLE * pHandles, DWORD timeout, DWORD mask, DWORD flags);
static WINAPI DWORD (*pMsgWaitForMultipleObjects)(DWORD count, const HANDLE * handles, BOOL wait_all, DWORD timeout, DWORD mask);
static WINAPI DWORD (*pWaitForInputIdle)(HANDLE hProcess, DWORD dwTimeOut);
static WINAPI UINT (*pRegisterWindowMessageA)(LPCSTR str);
static WINAPI UINT (*pRegisterWindowMessageW)(LPCWSTR str);
static WINAPI LONG (*pBroadcastSystemMessageA)(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp);
static WINAPI LONG (*pBroadcastSystemMessageW)(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp);
static WINAPI LONG (*pBroadcastSystemMessageExA)(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp, PBSMINFO pinfo);
static WINAPI LONG (*pBroadcastSystemMessageExW)(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp, PBSMINFO pinfo);
static WINAPI BOOL (*pSetMessageQueue)(INT size);
static WINAPI BOOL (*pMessageBeep)(UINT i);
static WINAPI UINT_PTR (*pSetCoalescableTimer)(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc, ULONG tolerance);
static WINAPI UINT_PTR (*pSetTimer)(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc);
static WINAPI UINT_PTR (*pSetSystemTimer)(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc);
static WINAPI BOOL (*pKillTimer)(HWND hwnd, UINT_PTR id);
static WINAPI BOOL (*pKillSystemTimer)(HWND hwnd, UINT_PTR id);
static WINAPI BOOL (*pIsGUIThread)(BOOL convert);
static WINAPI BOOL (*pGetGUIThreadInfo)(DWORD id, GUITHREADINFO * info);
static WINAPI BOOL (*pIsHungAppWindow)(HWND hWnd);
static WINAPI BOOL (*pChangeWindowMessageFilter)(UINT message, DWORD flag);
static WINAPI BOOL (*pChangeWindowMessageFilterEx)(HWND hwnd, UINT message, DWORD action, CHANGEFILTERSTRUCT * changefilter);

extern WINAPI LRESULT wine32b_SendMessageTimeoutW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, UINT flags, UINT timeout, PDWORD_PTR res_ptr)
{
	TRACE("Enter SendMessageTimeoutW\n");
	return pSendMessageTimeoutW(hwnd, msg, wparam, lparam, flags, timeout, res_ptr);
}

extern WINAPI void wine32a_SendMessageTimeoutW(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageTimeoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageTimeoutW") "\n"
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

extern WINAPI LRESULT wine32b_SendMessageTimeoutA(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, UINT flags, UINT timeout, PDWORD_PTR res_ptr)
{
	TRACE("Enter SendMessageTimeoutA\n");
	return pSendMessageTimeoutA(hwnd, msg, wparam, lparam, flags, timeout, res_ptr);
}

extern WINAPI void wine32a_SendMessageTimeoutA(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageTimeoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageTimeoutA") "\n"
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

extern WINAPI LRESULT wine32b_SendMessageW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter SendMessageW\n");
	return pSendMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_SendMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageW") "\n"
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

extern WINAPI LRESULT wine32b_SendMessageA(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter SendMessageA\n");
	return pSendMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_SendMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageA") "\n"
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

extern WINAPI BOOL wine32b_SendNotifyMessageA(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter SendNotifyMessageA\n");
	return pSendNotifyMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_SendNotifyMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_SendNotifyMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendNotifyMessageA") "\n"
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

extern WINAPI BOOL wine32b_SendNotifyMessageW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter SendNotifyMessageW\n");
	return pSendNotifyMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_SendNotifyMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_SendNotifyMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendNotifyMessageW") "\n"
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

extern WINAPI BOOL wine32b_SendMessageCallbackA(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, SENDASYNCPROC callback, ULONG_PTR data)
{
	TRACE("Enter SendMessageCallbackA\n");
	return pSendMessageCallbackA(hwnd, msg, wparam, lparam, callback, data);
}

extern WINAPI void wine32a_SendMessageCallbackA(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageCallbackA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageCallbackA") "\n"
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

extern WINAPI BOOL wine32b_SendMessageCallbackW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam, SENDASYNCPROC callback, ULONG_PTR data)
{
	TRACE("Enter SendMessageCallbackW\n");
	return pSendMessageCallbackW(hwnd, msg, wparam, lparam, callback, data);
}

extern WINAPI void wine32a_SendMessageCallbackW(void);
__ASM_GLOBAL_FUNC(wine32a_SendMessageCallbackW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendMessageCallbackW") "\n"
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

extern WINAPI BOOL wine32b_ReplyMessage(LRESULT result)
{
	TRACE("Enter ReplyMessage\n");
	return pReplyMessage(result);
}

extern WINAPI void wine32a_ReplyMessage(void);
__ASM_GLOBAL_FUNC(wine32a_ReplyMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReplyMessage") "\n"
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

extern WINAPI BOOL wine32b_InSendMessage(void)
{
	TRACE("Enter InSendMessage\n");
	return pInSendMessage();
}

extern WINAPI void wine32a_InSendMessage(void);
__ASM_GLOBAL_FUNC(wine32a_InSendMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InSendMessage") "\n"
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

extern WINAPI DWORD wine32b_InSendMessageEx(LPVOID reserved)
{
	TRACE("Enter InSendMessageEx\n");
	return pInSendMessageEx(reserved);
}

extern WINAPI void wine32a_InSendMessageEx(void);
__ASM_GLOBAL_FUNC(wine32a_InSendMessageEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InSendMessageEx") "\n"
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

extern WINAPI BOOL wine32b_PostMessageA(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter PostMessageA\n");
	return pPostMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_PostMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_PostMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PostMessageA") "\n"
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

extern WINAPI BOOL wine32b_PostMessageW(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter PostMessageW\n");
	return pPostMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_PostMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_PostMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PostMessageW") "\n"
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

extern WINAPI BOOL wine32b_PostThreadMessageA(DWORD thread, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter PostThreadMessageA\n");
	return pPostThreadMessageA(thread, msg, wparam, lparam);
}

extern WINAPI void wine32a_PostThreadMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_PostThreadMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PostThreadMessageA") "\n"
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

extern WINAPI BOOL wine32b_PostThreadMessageW(DWORD thread, UINT msg, WPARAM wparam, LPARAM lparam)
{
	TRACE("Enter PostThreadMessageW\n");
	return pPostThreadMessageW(thread, msg, wparam, lparam);
}

extern WINAPI void wine32a_PostThreadMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_PostThreadMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PostThreadMessageW") "\n"
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

extern WINAPI void wine32b_PostQuitMessage(INT exit_code)
{
	TRACE("Enter PostQuitMessage\n");
	return pPostQuitMessage(exit_code);
}

extern WINAPI void wine32a_PostQuitMessage(void);
__ASM_GLOBAL_FUNC(wine32a_PostQuitMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PostQuitMessage") "\n"
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

extern WINAPI BOOL wine32b_PeekMessageW(MSG * msg_out, HWND hwnd, UINT first, UINT last, UINT flags)
{
	TRACE("Enter PeekMessageW\n");
	return pPeekMessageW(msg_out, hwnd, first, last, flags);
}

extern WINAPI void wine32a_PeekMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_PeekMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PeekMessageW") "\n"
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

extern WINAPI BOOL wine32b_PeekMessageA(MSG * msg, HWND hwnd, UINT first, UINT last, UINT flags)
{
	TRACE("Enter PeekMessageA\n");
	return pPeekMessageA(msg, hwnd, first, last, flags);
}

extern WINAPI void wine32a_PeekMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_PeekMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PeekMessageA") "\n"
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

extern WINAPI BOOL wine32b_GetMessageW(MSG * msg, HWND hwnd, UINT first, UINT last)
{
	TRACE("Enter GetMessageW\n");
	return pGetMessageW(msg, hwnd, first, last);
}

extern WINAPI void wine32a_GetMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMessageW") "\n"
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

extern WINAPI BOOL wine32b_GetMessageA(MSG * msg, HWND hwnd, UINT first, UINT last)
{
	TRACE("Enter GetMessageA\n");
	return pGetMessageA(msg, hwnd, first, last);
}

extern WINAPI void wine32a_GetMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMessageA") "\n"
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

extern WINAPI BOOL wine32b_IsDialogMessageA(HWND hwndDlg, LPMSG pmsg)
{
	TRACE("Enter IsDialogMessageA\n");
	return pIsDialogMessageA(hwndDlg, pmsg);
}

extern WINAPI void wine32a_IsDialogMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_IsDialogMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDialogMessageA") "\n"
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

extern WINAPI BOOL wine32b_TranslateMessage(const MSG * msg)
{
	TRACE("Enter TranslateMessage\n");
	return pTranslateMessage(msg);
}

extern WINAPI void wine32a_TranslateMessage(void);
__ASM_GLOBAL_FUNC(wine32a_TranslateMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TranslateMessage") "\n"
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

extern WINAPI LRESULT wine32b_DispatchMessageA(const MSG * msg)
{
	TRACE("Enter DispatchMessageA\n");
	return pDispatchMessageA(msg);
}

extern WINAPI void wine32a_DispatchMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_DispatchMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DispatchMessageA") "\n"
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

extern WINAPI LRESULT wine32b_DispatchMessageW(const MSG * msg)
{
	TRACE("Enter DispatchMessageW\n");
	return pDispatchMessageW(msg);
}

extern WINAPI void wine32a_DispatchMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_DispatchMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DispatchMessageW") "\n"
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

extern WINAPI DWORD wine32b_GetMessagePos(void)
{
	TRACE("Enter GetMessagePos\n");
	return pGetMessagePos();
}

extern WINAPI void wine32a_GetMessagePos(void);
__ASM_GLOBAL_FUNC(wine32a_GetMessagePos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMessagePos") "\n"
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

extern WINAPI LONG wine32b_GetMessageTime(void)
{
	TRACE("Enter GetMessageTime\n");
	return pGetMessageTime();
}

extern WINAPI void wine32a_GetMessageTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetMessageTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMessageTime") "\n"
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

extern WINAPI LPARAM wine32b_GetMessageExtraInfo(void)
{
	TRACE("Enter GetMessageExtraInfo\n");
	return pGetMessageExtraInfo();
}

extern WINAPI void wine32a_GetMessageExtraInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMessageExtraInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMessageExtraInfo") "\n"
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

extern WINAPI LPARAM wine32b_SetMessageExtraInfo(LPARAM lParam)
{
	TRACE("Enter SetMessageExtraInfo\n");
	return pSetMessageExtraInfo(lParam);
}

extern WINAPI void wine32a_SetMessageExtraInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetMessageExtraInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMessageExtraInfo") "\n"
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

extern WINAPI BOOL wine32b_GetCurrentInputMessageSource(INPUT_MESSAGE_SOURCE * source)
{
	TRACE("Enter GetCurrentInputMessageSource\n");
	return pGetCurrentInputMessageSource(source);
}

extern WINAPI void wine32a_GetCurrentInputMessageSource(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentInputMessageSource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentInputMessageSource") "\n"
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

extern WINAPI BOOL wine32b_WaitMessage(void)
{
	TRACE("Enter WaitMessage\n");
	return pWaitMessage();
}

extern WINAPI void wine32a_WaitMessage(void);
__ASM_GLOBAL_FUNC(wine32a_WaitMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WaitMessage") "\n"
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

extern WINAPI DWORD wine32b_MsgWaitForMultipleObjectsEx(DWORD count, const HANDLE * pHandles, DWORD timeout, DWORD mask, DWORD flags)
{
	TRACE("Enter MsgWaitForMultipleObjectsEx\n");
	return pMsgWaitForMultipleObjectsEx(count, pHandles, timeout, mask, flags);
}

extern WINAPI void wine32a_MsgWaitForMultipleObjectsEx(void);
__ASM_GLOBAL_FUNC(wine32a_MsgWaitForMultipleObjectsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MsgWaitForMultipleObjectsEx") "\n"
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

extern WINAPI DWORD wine32b_MsgWaitForMultipleObjects(DWORD count, const HANDLE * handles, BOOL wait_all, DWORD timeout, DWORD mask)
{
	TRACE("Enter MsgWaitForMultipleObjects\n");
	return pMsgWaitForMultipleObjects(count, handles, wait_all, timeout, mask);
}

extern WINAPI void wine32a_MsgWaitForMultipleObjects(void);
__ASM_GLOBAL_FUNC(wine32a_MsgWaitForMultipleObjects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MsgWaitForMultipleObjects") "\n"
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

extern WINAPI DWORD wine32b_WaitForInputIdle(HANDLE hProcess, DWORD dwTimeOut)
{
	TRACE("Enter WaitForInputIdle\n");
	return pWaitForInputIdle(hProcess, dwTimeOut);
}

extern WINAPI void wine32a_WaitForInputIdle(void);
__ASM_GLOBAL_FUNC(wine32a_WaitForInputIdle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WaitForInputIdle") "\n"
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

extern WINAPI UINT wine32b_RegisterWindowMessageA(LPCSTR str)
{
	TRACE("Enter RegisterWindowMessageA\n");
	return pRegisterWindowMessageA(str);
}

extern WINAPI void wine32a_RegisterWindowMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterWindowMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterWindowMessageA") "\n"
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

extern WINAPI UINT wine32b_RegisterWindowMessageW(LPCWSTR str)
{
	TRACE("Enter RegisterWindowMessageW\n");
	return pRegisterWindowMessageW(str);
}

extern WINAPI void wine32a_RegisterWindowMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterWindowMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterWindowMessageW") "\n"
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

extern WINAPI LONG wine32b_BroadcastSystemMessageA(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp)
{
	TRACE("Enter BroadcastSystemMessageA\n");
	return pBroadcastSystemMessageA(flags, recipients, msg, wp, lp);
}

extern WINAPI void wine32a_BroadcastSystemMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_BroadcastSystemMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BroadcastSystemMessageA") "\n"
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

extern WINAPI LONG wine32b_BroadcastSystemMessageW(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp)
{
	TRACE("Enter BroadcastSystemMessageW\n");
	return pBroadcastSystemMessageW(flags, recipients, msg, wp, lp);
}

extern WINAPI void wine32a_BroadcastSystemMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_BroadcastSystemMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BroadcastSystemMessageW") "\n"
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

extern WINAPI LONG wine32b_BroadcastSystemMessageExA(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp, PBSMINFO pinfo)
{
	TRACE("Enter BroadcastSystemMessageExA\n");
	return pBroadcastSystemMessageExA(flags, recipients, msg, wp, lp, pinfo);
}

extern WINAPI void wine32a_BroadcastSystemMessageExA(void);
__ASM_GLOBAL_FUNC(wine32a_BroadcastSystemMessageExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BroadcastSystemMessageExA") "\n"
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

extern WINAPI LONG wine32b_BroadcastSystemMessageExW(DWORD flags, LPDWORD recipients, UINT msg, WPARAM wp, LPARAM lp, PBSMINFO pinfo)
{
	TRACE("Enter BroadcastSystemMessageExW\n");
	return pBroadcastSystemMessageExW(flags, recipients, msg, wp, lp, pinfo);
}

extern WINAPI void wine32a_BroadcastSystemMessageExW(void);
__ASM_GLOBAL_FUNC(wine32a_BroadcastSystemMessageExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BroadcastSystemMessageExW") "\n"
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

extern WINAPI BOOL wine32b_SetMessageQueue(INT size)
{
	TRACE("Enter SetMessageQueue\n");
	return pSetMessageQueue(size);
}

extern WINAPI void wine32a_SetMessageQueue(void);
__ASM_GLOBAL_FUNC(wine32a_SetMessageQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMessageQueue") "\n"
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

extern WINAPI BOOL wine32b_MessageBeep(UINT i)
{
	TRACE("Enter MessageBeep\n");
	return pMessageBeep(i);
}

extern WINAPI void wine32a_MessageBeep(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBeep,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBeep") "\n"
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

extern WINAPI UINT_PTR wine32b_SetCoalescableTimer(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc, ULONG tolerance)
{
	TRACE("Enter SetCoalescableTimer\n");
	return pSetCoalescableTimer(hwnd, id, timeout, proc, tolerance);
}

extern WINAPI void wine32a_SetCoalescableTimer(void);
__ASM_GLOBAL_FUNC(wine32a_SetCoalescableTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCoalescableTimer") "\n"
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

extern WINAPI UINT_PTR wine32b_SetTimer(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc)
{
	TRACE("Enter SetTimer\n");
	return pSetTimer(hwnd, id, timeout, proc);
}

extern WINAPI void wine32a_SetTimer(void);
__ASM_GLOBAL_FUNC(wine32a_SetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTimer") "\n"
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

extern WINAPI UINT_PTR wine32b_SetSystemTimer(HWND hwnd, UINT_PTR id, UINT timeout, TIMERPROC proc)
{
	TRACE("Enter SetSystemTimer\n");
	return pSetSystemTimer(hwnd, id, timeout, proc);
}

extern WINAPI void wine32a_SetSystemTimer(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemTimer") "\n"
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

extern WINAPI BOOL wine32b_KillTimer(HWND hwnd, UINT_PTR id)
{
	TRACE("Enter KillTimer\n");
	return pKillTimer(hwnd, id);
}

extern WINAPI void wine32a_KillTimer(void);
__ASM_GLOBAL_FUNC(wine32a_KillTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_KillTimer") "\n"
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

extern WINAPI BOOL wine32b_KillSystemTimer(HWND hwnd, UINT_PTR id)
{
	TRACE("Enter KillSystemTimer\n");
	return pKillSystemTimer(hwnd, id);
}

extern WINAPI void wine32a_KillSystemTimer(void);
__ASM_GLOBAL_FUNC(wine32a_KillSystemTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_KillSystemTimer") "\n"
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

extern WINAPI BOOL wine32b_IsGUIThread(BOOL convert)
{
	TRACE("Enter IsGUIThread\n");
	return pIsGUIThread(convert);
}

extern WINAPI void wine32a_IsGUIThread(void);
__ASM_GLOBAL_FUNC(wine32a_IsGUIThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsGUIThread") "\n"
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

extern WINAPI BOOL wine32b_GetGUIThreadInfo(DWORD id, GUITHREADINFO * info)
{
	TRACE("Enter GetGUIThreadInfo\n");
	return pGetGUIThreadInfo(id, info);
}

extern WINAPI void wine32a_GetGUIThreadInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetGUIThreadInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGUIThreadInfo") "\n"
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

extern WINAPI BOOL wine32b_IsHungAppWindow(HWND hWnd)
{
	TRACE("Enter IsHungAppWindow\n");
	return pIsHungAppWindow(hWnd);
}

extern WINAPI void wine32a_IsHungAppWindow(void);
__ASM_GLOBAL_FUNC(wine32a_IsHungAppWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsHungAppWindow") "\n"
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

extern WINAPI BOOL wine32b_ChangeWindowMessageFilter(UINT message, DWORD flag)
{
	TRACE("Enter ChangeWindowMessageFilter\n");
	return pChangeWindowMessageFilter(message, flag);
}

extern WINAPI void wine32a_ChangeWindowMessageFilter(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeWindowMessageFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeWindowMessageFilter") "\n"
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

extern WINAPI BOOL wine32b_ChangeWindowMessageFilterEx(HWND hwnd, UINT message, DWORD action, CHANGEFILTERSTRUCT * changefilter)
{
	TRACE("Enter ChangeWindowMessageFilterEx\n");
	return pChangeWindowMessageFilterEx(hwnd, message, action, changefilter);
}

extern WINAPI void wine32a_ChangeWindowMessageFilterEx(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeWindowMessageFilterEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeWindowMessageFilterEx") "\n"
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

static WINAPI WORD (*pUserSignalProc)(UINT uCode, DWORD dwThreadOrProcessID, DWORD dwFlags, HMODULE16 hModule);
static WINAPI void (*pSetLastErrorEx)(DWORD error, DWORD type);
static WINAPI BOOL (*pGetAltTabInfoA)(HWND hwnd, int iItem, PALTTABINFO pati, LPSTR pszItemText, UINT cchItemText);
static WINAPI BOOL (*pGetAltTabInfoW)(HWND hwnd, int iItem, PALTTABINFO pati, LPWSTR pszItemText, UINT cchItemText);
static WINAPI void (*pSetDebugErrorLevel)(DWORD dwLevel);
static WINAPI DWORD (*pSetWindowStationUser)(DWORD x1, DWORD x2);
static WINAPI DWORD (*pRegisterLogonProcess)(HANDLE hprocess, BOOL x);
static WINAPI DWORD (*pSetLogonNotifyWindow)(HWINSTA hwinsta, HWND hwnd);
static WINAPI LONG (*pQueryDisplayConfig)(UINT32 flags, UINT32 * numpathelements, DISPLAYCONFIG_PATH_INFO * pathinfo, UINT32 * numinfoelements, DISPLAYCONFIG_MODE_INFO * modeinfo, DISPLAYCONFIG_TOPOLOGY_ID * topologyid);
static WINAPI void (*pRegisterSystemThread)(DWORD flags, DWORD reserved);
static WINAPI BOOL (*pRegisterShellHookWindow)(HWND hWnd);
static WINAPI BOOL (*pDeregisterShellHookWindow)(HWND hWnd);
static WINAPI DWORD (*pRegisterTasklist)(DWORD x);
static WINAPI HDEVNOTIFY (*pRegisterDeviceNotificationA)(HANDLE hnd, LPVOID notifyfilter, DWORD flags);
static WINAPI HDEVNOTIFY (*pRegisterDeviceNotificationW)(HANDLE hRecipient, LPVOID pNotificationFilter, DWORD dwFlags);
static WINAPI BOOL (*pUnregisterDeviceNotification)(HDEVNOTIFY hnd);
static WINAPI DWORD (*pGetAppCompatFlags)(HTASK hTask);
static WINAPI DWORD (*pGetAppCompatFlags2)(HTASK hTask);
static WINAPI BOOL (*pAlignRects)(LPRECT rect, DWORD b, DWORD c, DWORD d);
static WINAPI void (*pLoadLocalFonts)(void);
static WINAPI BOOL (*pUser32InitializeImmEntryTable)(DWORD magic);
static WINAPI UINT (*pWINNLSGetIMEHotkey)(HWND hwnd);
static WINAPI BOOL (*pWINNLSEnableIME)(HWND hwnd, BOOL enable);
static WINAPI BOOL (*pWINNLSGetEnableStatus)(HWND hwnd);
static WINAPI LRESULT (*pSendIMEMessageExA)(HWND hwnd, LPARAM lparam);
static WINAPI LRESULT (*pSendIMEMessageExW)(HWND hwnd, LPARAM lparam);
static WINAPI void (*pDisableProcessWindowsGhosting)(void);
static WINAPI BOOL (*pUserHandleGrantAccess)(HANDLE handle, HANDLE job, BOOL grant);
static WINAPI HPOWERNOTIFY (*pRegisterPowerSettingNotification)(HANDLE recipient, const GUID * guid, DWORD flags);
static WINAPI BOOL (*pUnregisterPowerSettingNotification)(HPOWERNOTIFY handle);
static WINAPI BOOL (*pGetGestureConfig)(HWND hwnd, DWORD reserved, DWORD flags, UINT * count, GESTURECONFIG * config, UINT size);
static WINAPI BOOL (*pSetGestureConfig)(HWND hwnd, DWORD reserved, UINT id, PGESTURECONFIG config, UINT size);
static WINAPI BOOL (*pIsTouchWindow)(HWND hwnd, PULONG flags);
static WINAPI BOOL (*pIsWindowRedirectedForPrint)(HWND hwnd);
static WINAPI LONG (*pGetDisplayConfigBufferSizes)(UINT32 flags, UINT32 * num_path_info, UINT32 * num_mode_info);
static WINAPI BOOL (*pRegisterPointerDeviceNotifications)(HWND hwnd, BOOL notifyrange);
static WINAPI BOOL (*pGetPointerDevices)(UINT32 * device_count, POINTER_DEVICE_INFO * devices);
static WINAPI BOOL (*pRegisterTouchHitTestingWindow)(HWND hwnd, ULONG value);
static WINAPI BOOL (*pGetPointerType)(UINT32 id, POINTER_INPUT_TYPE * type);

extern WINAPI WORD wine32b_UserSignalProc(UINT uCode, DWORD dwThreadOrProcessID, DWORD dwFlags, HMODULE16 hModule)
{
	TRACE("Enter UserSignalProc\n");
	return pUserSignalProc(uCode, dwThreadOrProcessID, dwFlags, hModule);
}

extern WINAPI void wine32a_UserSignalProc(void);
__ASM_GLOBAL_FUNC(wine32a_UserSignalProc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UserSignalProc") "\n"
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

extern WINAPI void wine32b_SetLastErrorEx(DWORD error, DWORD type)
{
	TRACE("Enter SetLastErrorEx\n");
	return pSetLastErrorEx(error, type);
}

extern WINAPI void wine32a_SetLastErrorEx(void);
__ASM_GLOBAL_FUNC(wine32a_SetLastErrorEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLastErrorEx") "\n"
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

extern WINAPI BOOL wine32b_GetAltTabInfoA(HWND hwnd, int iItem, PALTTABINFO pati, LPSTR pszItemText, UINT cchItemText)
{
	TRACE("Enter GetAltTabInfoA\n");
	return pGetAltTabInfoA(hwnd, iItem, pati, pszItemText, cchItemText);
}

extern WINAPI void wine32a_GetAltTabInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetAltTabInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAltTabInfoA") "\n"
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

extern WINAPI BOOL wine32b_GetAltTabInfoW(HWND hwnd, int iItem, PALTTABINFO pati, LPWSTR pszItemText, UINT cchItemText)
{
	TRACE("Enter GetAltTabInfoW\n");
	return pGetAltTabInfoW(hwnd, iItem, pati, pszItemText, cchItemText);
}

extern WINAPI void wine32a_GetAltTabInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetAltTabInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAltTabInfoW") "\n"
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

extern WINAPI void wine32b_SetDebugErrorLevel(DWORD dwLevel)
{
	TRACE("Enter SetDebugErrorLevel\n");
	return pSetDebugErrorLevel(dwLevel);
}

extern WINAPI void wine32a_SetDebugErrorLevel(void);
__ASM_GLOBAL_FUNC(wine32a_SetDebugErrorLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDebugErrorLevel") "\n"
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

extern WINAPI DWORD wine32b_SetWindowStationUser(DWORD x1, DWORD x2)
{
	TRACE("Enter SetWindowStationUser\n");
	return pSetWindowStationUser(x1, x2);
}

extern WINAPI void wine32a_SetWindowStationUser(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowStationUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowStationUser") "\n"
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

extern WINAPI DWORD wine32b_RegisterLogonProcess(HANDLE hprocess, BOOL x)
{
	TRACE("Enter RegisterLogonProcess\n");
	return pRegisterLogonProcess(hprocess, x);
}

extern WINAPI void wine32a_RegisterLogonProcess(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterLogonProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterLogonProcess") "\n"
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

extern WINAPI DWORD wine32b_SetLogonNotifyWindow(HWINSTA hwinsta, HWND hwnd)
{
	TRACE("Enter SetLogonNotifyWindow\n");
	return pSetLogonNotifyWindow(hwinsta, hwnd);
}

extern WINAPI void wine32a_SetLogonNotifyWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SetLogonNotifyWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLogonNotifyWindow") "\n"
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

extern WINAPI LONG wine32b_QueryDisplayConfig(UINT32 flags, UINT32 * numpathelements, DISPLAYCONFIG_PATH_INFO * pathinfo, UINT32 * numinfoelements, DISPLAYCONFIG_MODE_INFO * modeinfo, DISPLAYCONFIG_TOPOLOGY_ID * topologyid)
{
	TRACE("Enter QueryDisplayConfig\n");
	return pQueryDisplayConfig(flags, numpathelements, pathinfo, numinfoelements, modeinfo, topologyid);
}

extern WINAPI void wine32a_QueryDisplayConfig(void);
__ASM_GLOBAL_FUNC(wine32a_QueryDisplayConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryDisplayConfig") "\n"
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

extern WINAPI void wine32b_RegisterSystemThread(DWORD flags, DWORD reserved)
{
	TRACE("Enter RegisterSystemThread\n");
	return pRegisterSystemThread(flags, reserved);
}

extern WINAPI void wine32a_RegisterSystemThread(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterSystemThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterSystemThread") "\n"
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

extern WINAPI BOOL wine32b_RegisterShellHookWindow(HWND hWnd)
{
	TRACE("Enter RegisterShellHookWindow\n");
	return pRegisterShellHookWindow(hWnd);
}

extern WINAPI void wine32a_RegisterShellHookWindow(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterShellHookWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterShellHookWindow") "\n"
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

extern WINAPI BOOL wine32b_DeregisterShellHookWindow(HWND hWnd)
{
	TRACE("Enter DeregisterShellHookWindow\n");
	return pDeregisterShellHookWindow(hWnd);
}

extern WINAPI void wine32a_DeregisterShellHookWindow(void);
__ASM_GLOBAL_FUNC(wine32a_DeregisterShellHookWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeregisterShellHookWindow") "\n"
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

extern WINAPI DWORD wine32b_RegisterTasklist(DWORD x)
{
	TRACE("Enter RegisterTasklist\n");
	return pRegisterTasklist(x);
}

extern WINAPI void wine32a_RegisterTasklist(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterTasklist,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterTasklist") "\n"
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

extern WINAPI HDEVNOTIFY wine32b_RegisterDeviceNotificationA(HANDLE hnd, LPVOID notifyfilter, DWORD flags)
{
	TRACE("Enter RegisterDeviceNotificationA\n");
	return pRegisterDeviceNotificationA(hnd, notifyfilter, flags);
}

extern WINAPI void wine32a_RegisterDeviceNotificationA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterDeviceNotificationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterDeviceNotificationA") "\n"
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

extern WINAPI HDEVNOTIFY wine32b_RegisterDeviceNotificationW(HANDLE hRecipient, LPVOID pNotificationFilter, DWORD dwFlags)
{
	TRACE("Enter RegisterDeviceNotificationW\n");
	return pRegisterDeviceNotificationW(hRecipient, pNotificationFilter, dwFlags);
}

extern WINAPI void wine32a_RegisterDeviceNotificationW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterDeviceNotificationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterDeviceNotificationW") "\n"
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

extern WINAPI BOOL wine32b_UnregisterDeviceNotification(HDEVNOTIFY hnd)
{
	TRACE("Enter UnregisterDeviceNotification\n");
	return pUnregisterDeviceNotification(hnd);
}

extern WINAPI void wine32a_UnregisterDeviceNotification(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterDeviceNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterDeviceNotification") "\n"
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

extern WINAPI DWORD wine32b_GetAppCompatFlags(HTASK hTask)
{
	TRACE("Enter GetAppCompatFlags\n");
	return pGetAppCompatFlags(hTask);
}

extern WINAPI void wine32a_GetAppCompatFlags(void);
__ASM_GLOBAL_FUNC(wine32a_GetAppCompatFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAppCompatFlags") "\n"
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

extern WINAPI DWORD wine32b_GetAppCompatFlags2(HTASK hTask)
{
	TRACE("Enter GetAppCompatFlags2\n");
	return pGetAppCompatFlags2(hTask);
}

extern WINAPI void wine32a_GetAppCompatFlags2(void);
__ASM_GLOBAL_FUNC(wine32a_GetAppCompatFlags2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAppCompatFlags2") "\n"
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

extern WINAPI BOOL wine32b_AlignRects(LPRECT rect, DWORD b, DWORD c, DWORD d)
{
	TRACE("Enter AlignRects\n");
	return pAlignRects(rect, b, c, d);
}

extern WINAPI void wine32a_AlignRects(void);
__ASM_GLOBAL_FUNC(wine32a_AlignRects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AlignRects") "\n"
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

extern WINAPI void wine32b_LoadLocalFonts(void)
{
	TRACE("Enter LoadLocalFonts\n");
	return pLoadLocalFonts();
}

extern WINAPI void wine32a_LoadLocalFonts(void);
__ASM_GLOBAL_FUNC(wine32a_LoadLocalFonts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadLocalFonts") "\n"
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

extern WINAPI BOOL wine32b_User32InitializeImmEntryTable(DWORD magic)
{
	TRACE("Enter User32InitializeImmEntryTable\n");
	return pUser32InitializeImmEntryTable(magic);
}

extern WINAPI void wine32a_User32InitializeImmEntryTable(void);
__ASM_GLOBAL_FUNC(wine32a_User32InitializeImmEntryTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_User32InitializeImmEntryTable") "\n"
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

extern WINAPI UINT wine32b_WINNLSGetIMEHotkey(HWND hwnd)
{
	TRACE("Enter WINNLSGetIMEHotkey\n");
	return pWINNLSGetIMEHotkey(hwnd);
}

extern WINAPI void wine32a_WINNLSGetIMEHotkey(void);
__ASM_GLOBAL_FUNC(wine32a_WINNLSGetIMEHotkey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WINNLSGetIMEHotkey") "\n"
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

extern WINAPI BOOL wine32b_WINNLSEnableIME(HWND hwnd, BOOL enable)
{
	TRACE("Enter WINNLSEnableIME\n");
	return pWINNLSEnableIME(hwnd, enable);
}

extern WINAPI void wine32a_WINNLSEnableIME(void);
__ASM_GLOBAL_FUNC(wine32a_WINNLSEnableIME,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WINNLSEnableIME") "\n"
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

extern WINAPI BOOL wine32b_WINNLSGetEnableStatus(HWND hwnd)
{
	TRACE("Enter WINNLSGetEnableStatus\n");
	return pWINNLSGetEnableStatus(hwnd);
}

extern WINAPI void wine32a_WINNLSGetEnableStatus(void);
__ASM_GLOBAL_FUNC(wine32a_WINNLSGetEnableStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WINNLSGetEnableStatus") "\n"
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

extern WINAPI LRESULT wine32b_SendIMEMessageExA(HWND hwnd, LPARAM lparam)
{
	TRACE("Enter SendIMEMessageExA\n");
	return pSendIMEMessageExA(hwnd, lparam);
}

extern WINAPI void wine32a_SendIMEMessageExA(void);
__ASM_GLOBAL_FUNC(wine32a_SendIMEMessageExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendIMEMessageExA") "\n"
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

extern WINAPI LRESULT wine32b_SendIMEMessageExW(HWND hwnd, LPARAM lparam)
{
	TRACE("Enter SendIMEMessageExW\n");
	return pSendIMEMessageExW(hwnd, lparam);
}

extern WINAPI void wine32a_SendIMEMessageExW(void);
__ASM_GLOBAL_FUNC(wine32a_SendIMEMessageExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SendIMEMessageExW") "\n"
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

extern WINAPI void wine32b_DisableProcessWindowsGhosting(void)
{
	TRACE("Enter DisableProcessWindowsGhosting\n");
	return pDisableProcessWindowsGhosting();
}

extern WINAPI void wine32a_DisableProcessWindowsGhosting(void);
__ASM_GLOBAL_FUNC(wine32a_DisableProcessWindowsGhosting,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DisableProcessWindowsGhosting") "\n"
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

extern WINAPI BOOL wine32b_UserHandleGrantAccess(HANDLE handle, HANDLE job, BOOL grant)
{
	TRACE("Enter UserHandleGrantAccess\n");
	return pUserHandleGrantAccess(handle, job, grant);
}

extern WINAPI void wine32a_UserHandleGrantAccess(void);
__ASM_GLOBAL_FUNC(wine32a_UserHandleGrantAccess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UserHandleGrantAccess") "\n"
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

extern WINAPI HPOWERNOTIFY wine32b_RegisterPowerSettingNotification(HANDLE recipient, const GUID * guid, DWORD flags)
{
	TRACE("Enter RegisterPowerSettingNotification\n");
	return pRegisterPowerSettingNotification(recipient, guid, flags);
}

extern WINAPI void wine32a_RegisterPowerSettingNotification(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterPowerSettingNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterPowerSettingNotification") "\n"
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

extern WINAPI BOOL wine32b_UnregisterPowerSettingNotification(HPOWERNOTIFY handle)
{
	TRACE("Enter UnregisterPowerSettingNotification\n");
	return pUnregisterPowerSettingNotification(handle);
}

extern WINAPI void wine32a_UnregisterPowerSettingNotification(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterPowerSettingNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterPowerSettingNotification") "\n"
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

extern WINAPI BOOL wine32b_GetGestureConfig(HWND hwnd, DWORD reserved, DWORD flags, UINT * count, GESTURECONFIG * config, UINT size)
{
	TRACE("Enter GetGestureConfig\n");
	return pGetGestureConfig(hwnd, reserved, flags, count, config, size);
}

extern WINAPI void wine32a_GetGestureConfig(void);
__ASM_GLOBAL_FUNC(wine32a_GetGestureConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGestureConfig") "\n"
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

extern WINAPI BOOL wine32b_SetGestureConfig(HWND hwnd, DWORD reserved, UINT id, PGESTURECONFIG config, UINT size)
{
	TRACE("Enter SetGestureConfig\n");
	return pSetGestureConfig(hwnd, reserved, id, config, size);
}

extern WINAPI void wine32a_SetGestureConfig(void);
__ASM_GLOBAL_FUNC(wine32a_SetGestureConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetGestureConfig") "\n"
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

extern WINAPI BOOL wine32b_IsTouchWindow(HWND hwnd, PULONG flags)
{
	TRACE("Enter IsTouchWindow\n");
	return pIsTouchWindow(hwnd, flags);
}

extern WINAPI void wine32a_IsTouchWindow(void);
__ASM_GLOBAL_FUNC(wine32a_IsTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsTouchWindow") "\n"
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

extern WINAPI BOOL wine32b_IsWindowRedirectedForPrint(HWND hwnd)
{
	TRACE("Enter IsWindowRedirectedForPrint\n");
	return pIsWindowRedirectedForPrint(hwnd);
}

extern WINAPI void wine32a_IsWindowRedirectedForPrint(void);
__ASM_GLOBAL_FUNC(wine32a_IsWindowRedirectedForPrint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWindowRedirectedForPrint") "\n"
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

extern WINAPI LONG wine32b_GetDisplayConfigBufferSizes(UINT32 flags, UINT32 * num_path_info, UINT32 * num_mode_info)
{
	TRACE("Enter GetDisplayConfigBufferSizes\n");
	return pGetDisplayConfigBufferSizes(flags, num_path_info, num_mode_info);
}

extern WINAPI void wine32a_GetDisplayConfigBufferSizes(void);
__ASM_GLOBAL_FUNC(wine32a_GetDisplayConfigBufferSizes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDisplayConfigBufferSizes") "\n"
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

extern WINAPI BOOL wine32b_RegisterPointerDeviceNotifications(HWND hwnd, BOOL notifyrange)
{
	TRACE("Enter RegisterPointerDeviceNotifications\n");
	return pRegisterPointerDeviceNotifications(hwnd, notifyrange);
}

extern WINAPI void wine32a_RegisterPointerDeviceNotifications(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterPointerDeviceNotifications,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterPointerDeviceNotifications") "\n"
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

extern WINAPI BOOL wine32b_GetPointerDevices(UINT32 * device_count, POINTER_DEVICE_INFO * devices)
{
	TRACE("Enter GetPointerDevices\n");
	return pGetPointerDevices(device_count, devices);
}

extern WINAPI void wine32a_GetPointerDevices(void);
__ASM_GLOBAL_FUNC(wine32a_GetPointerDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPointerDevices") "\n"
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

extern WINAPI BOOL wine32b_RegisterTouchHitTestingWindow(HWND hwnd, ULONG value)
{
	TRACE("Enter RegisterTouchHitTestingWindow\n");
	return pRegisterTouchHitTestingWindow(hwnd, value);
}

extern WINAPI void wine32a_RegisterTouchHitTestingWindow(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterTouchHitTestingWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterTouchHitTestingWindow") "\n"
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

extern WINAPI BOOL wine32b_GetPointerType(UINT32 id, POINTER_INPUT_TYPE * type)
{
	TRACE("Enter GetPointerType\n");
	return pGetPointerType(id, type);
}

extern WINAPI void wine32a_GetPointerType(void);
__ASM_GLOBAL_FUNC(wine32a_GetPointerType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPointerType") "\n"
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

static WINAPI INT (*pMessageBoxA)(HWND hWnd, LPCSTR text, LPCSTR title, UINT type);
static WINAPI INT (*pMessageBoxW)(HWND hwnd, LPCWSTR text, LPCWSTR title, UINT type);
static WINAPI INT (*pMessageBoxExA)(HWND hWnd, LPCSTR text, LPCSTR title, UINT type, WORD langid);
static WINAPI INT (*pMessageBoxExW)(HWND hWnd, LPCWSTR text, LPCWSTR title, UINT type, WORD langid);
static WINAPI INT (*pMessageBoxTimeoutA)(HWND hWnd, LPCSTR text, LPCSTR title, UINT type, WORD langid, DWORD timeout);
static WINAPI INT (*pMessageBoxTimeoutW)(HWND hWnd, LPCWSTR text, LPCWSTR title, UINT type, WORD langid, DWORD timeout);
static WINAPI INT (*pMessageBoxIndirectA)(LPMSGBOXPARAMSA msgbox);
static WINAPI INT (*pMessageBoxIndirectW)(LPMSGBOXPARAMSW msgbox);

extern WINAPI INT wine32b_MessageBoxA(HWND hWnd, LPCSTR text, LPCSTR title, UINT type)
{
	TRACE("Enter MessageBoxA\n");
	return pMessageBoxA(hWnd, text, title, type);
}

extern WINAPI void wine32a_MessageBoxA(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxA") "\n"
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

extern WINAPI INT wine32b_MessageBoxW(HWND hwnd, LPCWSTR text, LPCWSTR title, UINT type)
{
	TRACE("Enter MessageBoxW\n");
	return pMessageBoxW(hwnd, text, title, type);
}

extern WINAPI void wine32a_MessageBoxW(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxW") "\n"
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

extern WINAPI INT wine32b_MessageBoxExA(HWND hWnd, LPCSTR text, LPCSTR title, UINT type, WORD langid)
{
	TRACE("Enter MessageBoxExA\n");
	return pMessageBoxExA(hWnd, text, title, type, langid);
}

extern WINAPI void wine32a_MessageBoxExA(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxExA") "\n"
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

extern WINAPI INT wine32b_MessageBoxExW(HWND hWnd, LPCWSTR text, LPCWSTR title, UINT type, WORD langid)
{
	TRACE("Enter MessageBoxExW\n");
	return pMessageBoxExW(hWnd, text, title, type, langid);
}

extern WINAPI void wine32a_MessageBoxExW(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxExW") "\n"
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

extern WINAPI INT wine32b_MessageBoxTimeoutA(HWND hWnd, LPCSTR text, LPCSTR title, UINT type, WORD langid, DWORD timeout)
{
	TRACE("Enter MessageBoxTimeoutA\n");
	return pMessageBoxTimeoutA(hWnd, text, title, type, langid, timeout);
}

extern WINAPI void wine32a_MessageBoxTimeoutA(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxTimeoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxTimeoutA") "\n"
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

extern WINAPI INT wine32b_MessageBoxTimeoutW(HWND hWnd, LPCWSTR text, LPCWSTR title, UINT type, WORD langid, DWORD timeout)
{
	TRACE("Enter MessageBoxTimeoutW\n");
	return pMessageBoxTimeoutW(hWnd, text, title, type, langid, timeout);
}

extern WINAPI void wine32a_MessageBoxTimeoutW(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxTimeoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxTimeoutW") "\n"
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

extern WINAPI INT wine32b_MessageBoxIndirectA(LPMSGBOXPARAMSA msgbox)
{
	TRACE("Enter MessageBoxIndirectA\n");
	return pMessageBoxIndirectA(msgbox);
}

extern WINAPI void wine32a_MessageBoxIndirectA(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxIndirectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxIndirectA") "\n"
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

extern WINAPI INT wine32b_MessageBoxIndirectW(LPMSGBOXPARAMSW msgbox)
{
	TRACE("Enter MessageBoxIndirectW\n");
	return pMessageBoxIndirectW(msgbox);
}

extern WINAPI void wine32a_MessageBoxIndirectW(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxIndirectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxIndirectW") "\n"
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

static WINAPI BOOL (*pDrawCaption)(HWND hwnd, HDC hdc, const RECT * lpRect, UINT uFlags);
static WINAPI BOOL (*pDrawCaptionTempA)(HWND hwnd, HDC hdc, const RECT * rect, HFONT hFont, HICON hIcon, LPCSTR str, UINT uFlags);
static WINAPI BOOL (*pDrawCaptionTempW)(HWND hwnd, HDC hdc, const RECT * rect, HFONT hFont, HICON hIcon, LPCWSTR str, UINT uFlags);
static WINAPI BOOL (*pAdjustWindowRect)(LPRECT rect, DWORD style, BOOL menu);
static WINAPI BOOL (*pAdjustWindowRectEx)(LPRECT rect, DWORD style, BOOL menu, DWORD exStyle);
static WINAPI BOOL (*pAdjustWindowRectExForDpi)(LPRECT rect, DWORD style, BOOL menu, DWORD exStyle, UINT dpi);
static WINAPI BOOL (*pGetTitleBarInfo)(HWND hwnd, PTITLEBARINFO tbi);

extern WINAPI BOOL wine32b_DrawCaption(HWND hwnd, HDC hdc, const RECT * lpRect, UINT uFlags)
{
	TRACE("Enter DrawCaption\n");
	return pDrawCaption(hwnd, hdc, lpRect, uFlags);
}

extern WINAPI void wine32a_DrawCaption(void);
__ASM_GLOBAL_FUNC(wine32a_DrawCaption,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawCaption") "\n"
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

extern WINAPI BOOL wine32b_DrawCaptionTempA(HWND hwnd, HDC hdc, const RECT * rect, HFONT hFont, HICON hIcon, LPCSTR str, UINT uFlags)
{
	TRACE("Enter DrawCaptionTempA\n");
	return pDrawCaptionTempA(hwnd, hdc, rect, hFont, hIcon, str, uFlags);
}

extern WINAPI void wine32a_DrawCaptionTempA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawCaptionTempA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawCaptionTempA") "\n"
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

extern WINAPI BOOL wine32b_DrawCaptionTempW(HWND hwnd, HDC hdc, const RECT * rect, HFONT hFont, HICON hIcon, LPCWSTR str, UINT uFlags)
{
	TRACE("Enter DrawCaptionTempW\n");
	return pDrawCaptionTempW(hwnd, hdc, rect, hFont, hIcon, str, uFlags);
}

extern WINAPI void wine32a_DrawCaptionTempW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawCaptionTempW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawCaptionTempW") "\n"
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

extern WINAPI BOOL wine32b_AdjustWindowRect(LPRECT rect, DWORD style, BOOL menu)
{
	TRACE("Enter AdjustWindowRect\n");
	return pAdjustWindowRect(rect, style, menu);
}

extern WINAPI void wine32a_AdjustWindowRect(void);
__ASM_GLOBAL_FUNC(wine32a_AdjustWindowRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AdjustWindowRect") "\n"
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

extern WINAPI BOOL wine32b_AdjustWindowRectEx(LPRECT rect, DWORD style, BOOL menu, DWORD exStyle)
{
	TRACE("Enter AdjustWindowRectEx\n");
	return pAdjustWindowRectEx(rect, style, menu, exStyle);
}

extern WINAPI void wine32a_AdjustWindowRectEx(void);
__ASM_GLOBAL_FUNC(wine32a_AdjustWindowRectEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AdjustWindowRectEx") "\n"
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

extern WINAPI BOOL wine32b_AdjustWindowRectExForDpi(LPRECT rect, DWORD style, BOOL menu, DWORD exStyle, UINT dpi)
{
	TRACE("Enter AdjustWindowRectExForDpi\n");
	return pAdjustWindowRectExForDpi(rect, style, menu, exStyle, dpi);
}

extern WINAPI void wine32a_AdjustWindowRectExForDpi(void);
__ASM_GLOBAL_FUNC(wine32a_AdjustWindowRectExForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AdjustWindowRectExForDpi") "\n"
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

extern WINAPI BOOL wine32b_GetTitleBarInfo(HWND hwnd, PTITLEBARINFO tbi)
{
	TRACE("Enter GetTitleBarInfo\n");
	return pGetTitleBarInfo(hwnd, tbi);
}

extern WINAPI void wine32a_GetTitleBarInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetTitleBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTitleBarInfo") "\n"
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

static WINAPI HDC (*pBeginPaint)(HWND hwnd, PAINTSTRUCT * lps);
static WINAPI BOOL (*pEndPaint)(HWND hwnd, const PAINTSTRUCT * lps);
static WINAPI HDC (*pGetDCEx)(HWND hwnd, HRGN hrgnClip, DWORD flags);
static WINAPI HDC (*pGetDC)(HWND hwnd);
static WINAPI HDC (*pGetWindowDC)(HWND hwnd);
static WINAPI INT (*pReleaseDC)(HWND hwnd, HDC hdc);
static WINAPI HWND (*pWindowFromDC)(HDC hdc);
static WINAPI BOOL (*pLockWindowUpdate)(HWND hwnd);
static WINAPI BOOL (*pRedrawWindow)(HWND hwnd, const RECT * rect, HRGN hrgn, UINT flags);
static WINAPI BOOL (*pUpdateWindow)(HWND hwnd);
static WINAPI BOOL (*pInvalidateRgn)(HWND hwnd, HRGN hrgn, BOOL erase);
static WINAPI BOOL (*pInvalidateRect)(HWND hwnd, const RECT * rect, BOOL erase);
static WINAPI BOOL (*pValidateRgn)(HWND hwnd, HRGN hrgn);
static WINAPI BOOL (*pValidateRect)(HWND hwnd, const RECT * rect);
static WINAPI INT (*pGetUpdateRgn)(HWND hwnd, HRGN hrgn, BOOL erase);
static WINAPI BOOL (*pGetUpdateRect)(HWND hwnd, LPRECT rect, BOOL erase);
static WINAPI INT (*pExcludeUpdateRgn)(HDC hdc, HWND hwnd);
static WINAPI INT (*pScrollWindowEx)(HWND hwnd, INT dx, INT dy, const RECT * rect, const RECT * clipRect, HRGN hrgnUpdate, LPRECT rcUpdate, UINT flags);
static WINAPI BOOL (*pScrollWindow)(HWND hwnd, INT dx, INT dy, const RECT * rect, const RECT * clipRect);
static WINAPI BOOL (*pScrollDC)(HDC hdc, INT dx, INT dy, const RECT * scroll, const RECT * clip, HRGN ret_update_rgn, LPRECT update_rect);
static WINAPI BOOL (*pPrintWindow)(HWND hwnd, HDC hdcBlt, UINT nFlags);

extern WINAPI HDC wine32b_BeginPaint(HWND hwnd, PAINTSTRUCT * lps)
{
	TRACE("Enter BeginPaint\n");
	return pBeginPaint(hwnd, lps);
}

extern WINAPI void wine32a_BeginPaint(void);
__ASM_GLOBAL_FUNC(wine32a_BeginPaint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BeginPaint") "\n"
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

extern WINAPI BOOL wine32b_EndPaint(HWND hwnd, const PAINTSTRUCT * lps)
{
	TRACE("Enter EndPaint\n");
	return pEndPaint(hwnd, lps);
}

extern WINAPI void wine32a_EndPaint(void);
__ASM_GLOBAL_FUNC(wine32a_EndPaint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndPaint") "\n"
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

extern WINAPI HDC wine32b_GetDCEx(HWND hwnd, HRGN hrgnClip, DWORD flags)
{
	TRACE("Enter GetDCEx\n");
	return pGetDCEx(hwnd, hrgnClip, flags);
}

extern WINAPI void wine32a_GetDCEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetDCEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDCEx") "\n"
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

extern WINAPI HDC wine32b_GetDC(HWND hwnd)
{
	TRACE("Enter GetDC\n");
	return pGetDC(hwnd);
}

extern WINAPI void wine32a_GetDC(void);
__ASM_GLOBAL_FUNC(wine32a_GetDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDC") "\n"
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

extern WINAPI HDC wine32b_GetWindowDC(HWND hwnd)
{
	TRACE("Enter GetWindowDC\n");
	return pGetWindowDC(hwnd);
}

extern WINAPI void wine32a_GetWindowDC(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowDC") "\n"
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

extern WINAPI INT wine32b_ReleaseDC(HWND hwnd, HDC hdc)
{
	TRACE("Enter ReleaseDC\n");
	return pReleaseDC(hwnd, hdc);
}

extern WINAPI void wine32a_ReleaseDC(void);
__ASM_GLOBAL_FUNC(wine32a_ReleaseDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReleaseDC") "\n"
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

extern WINAPI HWND wine32b_WindowFromDC(HDC hdc)
{
	TRACE("Enter WindowFromDC\n");
	return pWindowFromDC(hdc);
}

extern WINAPI void wine32a_WindowFromDC(void);
__ASM_GLOBAL_FUNC(wine32a_WindowFromDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WindowFromDC") "\n"
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

extern WINAPI BOOL wine32b_LockWindowUpdate(HWND hwnd)
{
	TRACE("Enter LockWindowUpdate\n");
	return pLockWindowUpdate(hwnd);
}

extern WINAPI void wine32a_LockWindowUpdate(void);
__ASM_GLOBAL_FUNC(wine32a_LockWindowUpdate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LockWindowUpdate") "\n"
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

extern WINAPI BOOL wine32b_RedrawWindow(HWND hwnd, const RECT * rect, HRGN hrgn, UINT flags)
{
	TRACE("Enter RedrawWindow\n");
	return pRedrawWindow(hwnd, rect, hrgn, flags);
}

extern WINAPI void wine32a_RedrawWindow(void);
__ASM_GLOBAL_FUNC(wine32a_RedrawWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RedrawWindow") "\n"
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

extern WINAPI BOOL wine32b_UpdateWindow(HWND hwnd)
{
	TRACE("Enter UpdateWindow\n");
	return pUpdateWindow(hwnd);
}

extern WINAPI void wine32a_UpdateWindow(void);
__ASM_GLOBAL_FUNC(wine32a_UpdateWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UpdateWindow") "\n"
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

extern WINAPI BOOL wine32b_InvalidateRgn(HWND hwnd, HRGN hrgn, BOOL erase)
{
	TRACE("Enter InvalidateRgn\n");
	return pInvalidateRgn(hwnd, hrgn, erase);
}

extern WINAPI void wine32a_InvalidateRgn(void);
__ASM_GLOBAL_FUNC(wine32a_InvalidateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InvalidateRgn") "\n"
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

extern WINAPI BOOL wine32b_InvalidateRect(HWND hwnd, const RECT * rect, BOOL erase)
{
	TRACE("Enter InvalidateRect\n");
	return pInvalidateRect(hwnd, rect, erase);
}

extern WINAPI void wine32a_InvalidateRect(void);
__ASM_GLOBAL_FUNC(wine32a_InvalidateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InvalidateRect") "\n"
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

extern WINAPI BOOL wine32b_ValidateRgn(HWND hwnd, HRGN hrgn)
{
	TRACE("Enter ValidateRgn\n");
	return pValidateRgn(hwnd, hrgn);
}

extern WINAPI void wine32a_ValidateRgn(void);
__ASM_GLOBAL_FUNC(wine32a_ValidateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ValidateRgn") "\n"
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

extern WINAPI BOOL wine32b_ValidateRect(HWND hwnd, const RECT * rect)
{
	TRACE("Enter ValidateRect\n");
	return pValidateRect(hwnd, rect);
}

extern WINAPI void wine32a_ValidateRect(void);
__ASM_GLOBAL_FUNC(wine32a_ValidateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ValidateRect") "\n"
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

extern WINAPI INT wine32b_GetUpdateRgn(HWND hwnd, HRGN hrgn, BOOL erase)
{
	TRACE("Enter GetUpdateRgn\n");
	return pGetUpdateRgn(hwnd, hrgn, erase);
}

extern WINAPI void wine32a_GetUpdateRgn(void);
__ASM_GLOBAL_FUNC(wine32a_GetUpdateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUpdateRgn") "\n"
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

extern WINAPI BOOL wine32b_GetUpdateRect(HWND hwnd, LPRECT rect, BOOL erase)
{
	TRACE("Enter GetUpdateRect\n");
	return pGetUpdateRect(hwnd, rect, erase);
}

extern WINAPI void wine32a_GetUpdateRect(void);
__ASM_GLOBAL_FUNC(wine32a_GetUpdateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUpdateRect") "\n"
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

extern WINAPI INT wine32b_ExcludeUpdateRgn(HDC hdc, HWND hwnd)
{
	TRACE("Enter ExcludeUpdateRgn\n");
	return pExcludeUpdateRgn(hdc, hwnd);
}

extern WINAPI void wine32a_ExcludeUpdateRgn(void);
__ASM_GLOBAL_FUNC(wine32a_ExcludeUpdateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExcludeUpdateRgn") "\n"
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

extern WINAPI INT wine32b_ScrollWindowEx(HWND hwnd, INT dx, INT dy, const RECT * rect, const RECT * clipRect, HRGN hrgnUpdate, LPRECT rcUpdate, UINT flags)
{
	TRACE("Enter ScrollWindowEx\n");
	return pScrollWindowEx(hwnd, dx, dy, rect, clipRect, hrgnUpdate, rcUpdate, flags);
}

extern WINAPI void wine32a_ScrollWindowEx(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollWindowEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ScrollWindow(HWND hwnd, INT dx, INT dy, const RECT * rect, const RECT * clipRect)
{
	TRACE("Enter ScrollWindow\n");
	return pScrollWindow(hwnd, dx, dy, rect, clipRect);
}

extern WINAPI void wine32a_ScrollWindow(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollWindow") "\n"
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

extern WINAPI BOOL wine32b_ScrollDC(HDC hdc, INT dx, INT dy, const RECT * scroll, const RECT * clip, HRGN ret_update_rgn, LPRECT update_rect)
{
	TRACE("Enter ScrollDC\n");
	return pScrollDC(hdc, dx, dy, scroll, clip, ret_update_rgn, update_rect);
}

extern WINAPI void wine32a_ScrollDC(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollDC") "\n"
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

extern WINAPI BOOL wine32b_PrintWindow(HWND hwnd, HDC hdcBlt, UINT nFlags)
{
	TRACE("Enter PrintWindow\n");
	return pPrintWindow(hwnd, hdcBlt, nFlags);
}

extern WINAPI void wine32a_PrintWindow(void);
__ASM_GLOBAL_FUNC(wine32a_PrintWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrintWindow") "\n"
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

static WINAPI INT (*pEnumPropsA)(HWND hwnd, PROPENUMPROCA func);
static WINAPI INT (*pEnumPropsW)(HWND hwnd, PROPENUMPROCW func);
static WINAPI HANDLE (*pGetPropA)(HWND hwnd, LPCSTR str);
static WINAPI HANDLE (*pGetPropW)(HWND hwnd, LPCWSTR str);
static WINAPI BOOL (*pSetPropA)(HWND hwnd, LPCSTR str, HANDLE handle);
static WINAPI BOOL (*pSetPropW)(HWND hwnd, LPCWSTR str, HANDLE handle);
static WINAPI HANDLE (*pRemovePropA)(HWND hwnd, LPCSTR str);
static WINAPI HANDLE (*pRemovePropW)(HWND hwnd, LPCWSTR str);
static WINAPI INT (*pEnumPropsExA)(HWND hwnd, PROPENUMPROCEXA func, LPARAM lParam);
static WINAPI INT (*pEnumPropsExW)(HWND hwnd, PROPENUMPROCEXW func, LPARAM lParam);

extern WINAPI INT wine32b_EnumPropsA(HWND hwnd, PROPENUMPROCA func)
{
	TRACE("Enter EnumPropsA\n");
	return pEnumPropsA(hwnd, func);
}

extern WINAPI void wine32a_EnumPropsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumPropsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumPropsA") "\n"
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

extern WINAPI INT wine32b_EnumPropsW(HWND hwnd, PROPENUMPROCW func)
{
	TRACE("Enter EnumPropsW\n");
	return pEnumPropsW(hwnd, func);
}

extern WINAPI void wine32a_EnumPropsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumPropsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumPropsW") "\n"
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

extern WINAPI HANDLE wine32b_GetPropA(HWND hwnd, LPCSTR str)
{
	TRACE("Enter GetPropA\n");
	return pGetPropA(hwnd, str);
}

extern WINAPI void wine32a_GetPropA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPropA") "\n"
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

extern WINAPI HANDLE wine32b_GetPropW(HWND hwnd, LPCWSTR str)
{
	TRACE("Enter GetPropW\n");
	return pGetPropW(hwnd, str);
}

extern WINAPI void wine32a_GetPropW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPropW") "\n"
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

extern WINAPI BOOL wine32b_SetPropA(HWND hwnd, LPCSTR str, HANDLE handle)
{
	TRACE("Enter SetPropA\n");
	return pSetPropA(hwnd, str, handle);
}

extern WINAPI void wine32a_SetPropA(void);
__ASM_GLOBAL_FUNC(wine32a_SetPropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetPropA") "\n"
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

extern WINAPI BOOL wine32b_SetPropW(HWND hwnd, LPCWSTR str, HANDLE handle)
{
	TRACE("Enter SetPropW\n");
	return pSetPropW(hwnd, str, handle);
}

extern WINAPI void wine32a_SetPropW(void);
__ASM_GLOBAL_FUNC(wine32a_SetPropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetPropW") "\n"
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

extern WINAPI HANDLE wine32b_RemovePropA(HWND hwnd, LPCSTR str)
{
	TRACE("Enter RemovePropA\n");
	return pRemovePropA(hwnd, str);
}

extern WINAPI void wine32a_RemovePropA(void);
__ASM_GLOBAL_FUNC(wine32a_RemovePropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemovePropA") "\n"
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

extern WINAPI HANDLE wine32b_RemovePropW(HWND hwnd, LPCWSTR str)
{
	TRACE("Enter RemovePropW\n");
	return pRemovePropW(hwnd, str);
}

extern WINAPI void wine32a_RemovePropW(void);
__ASM_GLOBAL_FUNC(wine32a_RemovePropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemovePropW") "\n"
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

extern WINAPI INT wine32b_EnumPropsExA(HWND hwnd, PROPENUMPROCEXA func, LPARAM lParam)
{
	TRACE("Enter EnumPropsExA\n");
	return pEnumPropsExA(hwnd, func, lParam);
}

extern WINAPI void wine32a_EnumPropsExA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumPropsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumPropsExA") "\n"
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

extern WINAPI INT wine32b_EnumPropsExW(HWND hwnd, PROPENUMPROCEXW func, LPARAM lParam)
{
	TRACE("Enter EnumPropsExW\n");
	return pEnumPropsExW(hwnd, func, lParam);
}

extern WINAPI void wine32a_EnumPropsExW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumPropsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumPropsExW") "\n"
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

static WINAPI UINT (*pGetRawInputDeviceList)(RAWINPUTDEVICELIST * devices, UINT * device_count, UINT size);
static WINAPI BOOL (*pRegisterRawInputDevices)(RAWINPUTDEVICE * devices, UINT device_count, UINT size);
static WINAPI UINT (*pGetRawInputData)(HRAWINPUT rawinput, UINT command, void * data, UINT * data_size, UINT header_size);
static WINAPI UINT (*pGetRawInputBuffer)(RAWINPUT * data, UINT * data_size, UINT header_size);
static WINAPI UINT (*pGetRawInputDeviceInfoA)(HANDLE device, UINT command, void * data, UINT * data_size);
static WINAPI UINT (*pGetRawInputDeviceInfoW)(HANDLE device, UINT command, void * data, UINT * data_size);
static WINAPI UINT (*pGetRegisteredRawInputDevices)(RAWINPUTDEVICE * devices, UINT * device_count, UINT size);
static WINAPI LRESULT (*pDefRawInputProc)(RAWINPUT ** data, INT data_count, UINT header_size);

extern WINAPI UINT wine32b_GetRawInputDeviceList(RAWINPUTDEVICELIST * devices, UINT * device_count, UINT size)
{
	TRACE("Enter GetRawInputDeviceList\n");
	return pGetRawInputDeviceList(devices, device_count, size);
}

extern WINAPI void wine32a_GetRawInputDeviceList(void);
__ASM_GLOBAL_FUNC(wine32a_GetRawInputDeviceList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRawInputDeviceList") "\n"
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

extern WINAPI BOOL wine32b_RegisterRawInputDevices(RAWINPUTDEVICE * devices, UINT device_count, UINT size)
{
	TRACE("Enter RegisterRawInputDevices\n");
	return pRegisterRawInputDevices(devices, device_count, size);
}

extern WINAPI void wine32a_RegisterRawInputDevices(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterRawInputDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterRawInputDevices") "\n"
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

extern WINAPI UINT wine32b_GetRawInputData(HRAWINPUT rawinput, UINT command, void * data, UINT * data_size, UINT header_size)
{
	TRACE("Enter GetRawInputData\n");
	return pGetRawInputData(rawinput, command, data, data_size, header_size);
}

extern WINAPI void wine32a_GetRawInputData(void);
__ASM_GLOBAL_FUNC(wine32a_GetRawInputData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRawInputData") "\n"
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

extern WINAPI UINT wine32b_GetRawInputBuffer(RAWINPUT * data, UINT * data_size, UINT header_size)
{
	TRACE("Enter GetRawInputBuffer\n");
	return pGetRawInputBuffer(data, data_size, header_size);
}

extern WINAPI void wine32a_GetRawInputBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_GetRawInputBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRawInputBuffer") "\n"
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

extern WINAPI UINT wine32b_GetRawInputDeviceInfoA(HANDLE device, UINT command, void * data, UINT * data_size)
{
	TRACE("Enter GetRawInputDeviceInfoA\n");
	return pGetRawInputDeviceInfoA(device, command, data, data_size);
}

extern WINAPI void wine32a_GetRawInputDeviceInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetRawInputDeviceInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRawInputDeviceInfoA") "\n"
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

extern WINAPI UINT wine32b_GetRawInputDeviceInfoW(HANDLE device, UINT command, void * data, UINT * data_size)
{
	TRACE("Enter GetRawInputDeviceInfoW\n");
	return pGetRawInputDeviceInfoW(device, command, data, data_size);
}

extern WINAPI void wine32a_GetRawInputDeviceInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetRawInputDeviceInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRawInputDeviceInfoW") "\n"
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

extern WINAPI UINT wine32b_GetRegisteredRawInputDevices(RAWINPUTDEVICE * devices, UINT * device_count, UINT size)
{
	TRACE("Enter GetRegisteredRawInputDevices\n");
	return pGetRegisteredRawInputDevices(devices, device_count, size);
}

extern WINAPI void wine32a_GetRegisteredRawInputDevices(void);
__ASM_GLOBAL_FUNC(wine32a_GetRegisteredRawInputDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetRegisteredRawInputDevices") "\n"
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

extern WINAPI LRESULT wine32b_DefRawInputProc(RAWINPUT ** data, INT data_count, UINT header_size)
{
	TRACE("Enter DefRawInputProc\n");
	return pDefRawInputProc(data, data_count, header_size);
}

extern WINAPI void wine32a_DefRawInputProc(void);
__ASM_GLOBAL_FUNC(wine32a_DefRawInputProc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefRawInputProc") "\n"
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

static WINAPI HACCEL (*pLoadAcceleratorsW)(HINSTANCE instance, LPCWSTR name);
static WINAPI HACCEL (*pLoadAcceleratorsA)(HINSTANCE instance, LPCSTR lpTableName);
static WINAPI INT (*pCopyAcceleratorTableA)(HACCEL src, LPACCEL dst, INT count);
static WINAPI INT (*pCopyAcceleratorTableW)(HACCEL src, LPACCEL dst, INT count);
static WINAPI HACCEL (*pCreateAcceleratorTableA)(LPACCEL lpaccel, INT count);
static WINAPI HACCEL (*pCreateAcceleratorTableW)(LPACCEL lpaccel, INT count);
static WINAPI BOOL (*pDestroyAcceleratorTable)(HACCEL handle);
static WINAPI INT (*pLoadStringW)(HINSTANCE instance, UINT resource_id, LPWSTR buffer, INT buflen);
static WINAPI INT (*pLoadStringA)(HINSTANCE instance, UINT resource_id, LPSTR buffer, INT buflen);
static WINAPI DWORD (*pGetGuiResources)(HANDLE hProcess, DWORD uiFlags);

extern WINAPI HACCEL wine32b_LoadAcceleratorsW(HINSTANCE instance, LPCWSTR name)
{
	TRACE("Enter LoadAcceleratorsW\n");
	return pLoadAcceleratorsW(instance, name);
}

extern WINAPI void wine32a_LoadAcceleratorsW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadAcceleratorsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadAcceleratorsW") "\n"
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

extern WINAPI HACCEL wine32b_LoadAcceleratorsA(HINSTANCE instance, LPCSTR lpTableName)
{
	TRACE("Enter LoadAcceleratorsA\n");
	return pLoadAcceleratorsA(instance, lpTableName);
}

extern WINAPI void wine32a_LoadAcceleratorsA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadAcceleratorsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadAcceleratorsA") "\n"
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

extern WINAPI INT wine32b_CopyAcceleratorTableA(HACCEL src, LPACCEL dst, INT count)
{
	TRACE("Enter CopyAcceleratorTableA\n");
	return pCopyAcceleratorTableA(src, dst, count);
}

extern WINAPI void wine32a_CopyAcceleratorTableA(void);
__ASM_GLOBAL_FUNC(wine32a_CopyAcceleratorTableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyAcceleratorTableA") "\n"
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

extern WINAPI INT wine32b_CopyAcceleratorTableW(HACCEL src, LPACCEL dst, INT count)
{
	TRACE("Enter CopyAcceleratorTableW\n");
	return pCopyAcceleratorTableW(src, dst, count);
}

extern WINAPI void wine32a_CopyAcceleratorTableW(void);
__ASM_GLOBAL_FUNC(wine32a_CopyAcceleratorTableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyAcceleratorTableW") "\n"
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

extern WINAPI HACCEL wine32b_CreateAcceleratorTableA(LPACCEL lpaccel, INT count)
{
	TRACE("Enter CreateAcceleratorTableA\n");
	return pCreateAcceleratorTableA(lpaccel, count);
}

extern WINAPI void wine32a_CreateAcceleratorTableA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateAcceleratorTableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateAcceleratorTableA") "\n"
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

extern WINAPI HACCEL wine32b_CreateAcceleratorTableW(LPACCEL lpaccel, INT count)
{
	TRACE("Enter CreateAcceleratorTableW\n");
	return pCreateAcceleratorTableW(lpaccel, count);
}

extern WINAPI void wine32a_CreateAcceleratorTableW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateAcceleratorTableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateAcceleratorTableW") "\n"
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

extern WINAPI BOOL wine32b_DestroyAcceleratorTable(HACCEL handle)
{
	TRACE("Enter DestroyAcceleratorTable\n");
	return pDestroyAcceleratorTable(handle);
}

extern WINAPI void wine32a_DestroyAcceleratorTable(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyAcceleratorTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyAcceleratorTable") "\n"
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

extern WINAPI INT wine32b_LoadStringW(HINSTANCE instance, UINT resource_id, LPWSTR buffer, INT buflen)
{
	TRACE("Enter LoadStringW\n");
	return pLoadStringW(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_LoadStringW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadStringW") "\n"
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

extern WINAPI INT wine32b_LoadStringA(HINSTANCE instance, UINT resource_id, LPSTR buffer, INT buflen)
{
	TRACE("Enter LoadStringA\n");
	return pLoadStringA(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_LoadStringA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadStringA") "\n"
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

extern WINAPI DWORD wine32b_GetGuiResources(HANDLE hProcess, DWORD uiFlags)
{
	TRACE("Enter GetGuiResources\n");
	return pGetGuiResources(hProcess, uiFlags);
}

extern WINAPI void wine32a_GetGuiResources(void);
__ASM_GLOBAL_FUNC(wine32a_GetGuiResources,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGuiResources") "\n"
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

static WINAPI INT (*pSetScrollInfo)(HWND hwnd, INT nBar, const SCROLLINFO * info, BOOL bRedraw);
static WINAPI BOOL (*pGetScrollInfo)(HWND hwnd, INT nBar, LPSCROLLINFO info);
static WINAPI BOOL (*pGetScrollBarInfo)(HWND hwnd, LONG idObject, LPSCROLLBARINFO info);
static WINAPI INT (*pSetScrollPos)(HWND hwnd, INT nBar, INT nPos, BOOL bRedraw);
static WINAPI INT (*pGetScrollPos)(HWND hwnd, INT nBar);
static WINAPI BOOL (*pSetScrollRange)(HWND hwnd, INT nBar, INT minVal, INT maxVal, BOOL bRedraw);
static WINAPI BOOL (*pGetScrollRange)(HWND hwnd, INT nBar, LPINT lpMin, LPINT lpMax);
static WINAPI BOOL (*pShowScrollBar)(HWND hwnd, INT nBar, BOOL fShow);
static WINAPI BOOL (*pEnableScrollBar)(HWND hwnd, UINT nBar, UINT flags);

extern WINAPI INT wine32b_SetScrollInfo(HWND hwnd, INT nBar, const SCROLLINFO * info, BOOL bRedraw)
{
	TRACE("Enter SetScrollInfo\n");
	return pSetScrollInfo(hwnd, nBar, info, bRedraw);
}

extern WINAPI void wine32a_SetScrollInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetScrollInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetScrollInfo") "\n"
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

extern WINAPI BOOL wine32b_GetScrollInfo(HWND hwnd, INT nBar, LPSCROLLINFO info)
{
	TRACE("Enter GetScrollInfo\n");
	return pGetScrollInfo(hwnd, nBar, info);
}

extern WINAPI void wine32a_GetScrollInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetScrollInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetScrollInfo") "\n"
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

extern WINAPI BOOL wine32b_GetScrollBarInfo(HWND hwnd, LONG idObject, LPSCROLLBARINFO info)
{
	TRACE("Enter GetScrollBarInfo\n");
	return pGetScrollBarInfo(hwnd, idObject, info);
}

extern WINAPI void wine32a_GetScrollBarInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetScrollBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetScrollBarInfo") "\n"
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

extern WINAPI INT wine32b_SetScrollPos(HWND hwnd, INT nBar, INT nPos, BOOL bRedraw)
{
	TRACE("Enter SetScrollPos\n");
	return pSetScrollPos(hwnd, nBar, nPos, bRedraw);
}

extern WINAPI void wine32a_SetScrollPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetScrollPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetScrollPos") "\n"
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

extern WINAPI INT wine32b_GetScrollPos(HWND hwnd, INT nBar)
{
	TRACE("Enter GetScrollPos\n");
	return pGetScrollPos(hwnd, nBar);
}

extern WINAPI void wine32a_GetScrollPos(void);
__ASM_GLOBAL_FUNC(wine32a_GetScrollPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetScrollPos") "\n"
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

extern WINAPI BOOL wine32b_SetScrollRange(HWND hwnd, INT nBar, INT minVal, INT maxVal, BOOL bRedraw)
{
	TRACE("Enter SetScrollRange\n");
	return pSetScrollRange(hwnd, nBar, minVal, maxVal, bRedraw);
}

extern WINAPI void wine32a_SetScrollRange(void);
__ASM_GLOBAL_FUNC(wine32a_SetScrollRange,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetScrollRange") "\n"
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

extern WINAPI BOOL wine32b_GetScrollRange(HWND hwnd, INT nBar, LPINT lpMin, LPINT lpMax)
{
	TRACE("Enter GetScrollRange\n");
	return pGetScrollRange(hwnd, nBar, lpMin, lpMax);
}

extern WINAPI void wine32a_GetScrollRange(void);
__ASM_GLOBAL_FUNC(wine32a_GetScrollRange,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetScrollRange") "\n"
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

extern WINAPI BOOL wine32b_ShowScrollBar(HWND hwnd, INT nBar, BOOL fShow)
{
	TRACE("Enter ShowScrollBar\n");
	return pShowScrollBar(hwnd, nBar, fShow);
}

extern WINAPI void wine32a_ShowScrollBar(void);
__ASM_GLOBAL_FUNC(wine32a_ShowScrollBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowScrollBar") "\n"
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

extern WINAPI BOOL wine32b_EnableScrollBar(HWND hwnd, UINT nBar, UINT flags)
{
	TRACE("Enter EnableScrollBar\n");
	return pEnableScrollBar(hwnd, nBar, flags);
}

extern WINAPI void wine32a_EnableScrollBar(void);
__ASM_GLOBAL_FUNC(wine32a_EnableScrollBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableScrollBar") "\n"
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



static WINAPI BOOL (*pSystemParametersInfoForDpi)(UINT action, UINT val, PVOID ptr, UINT winini, UINT dpi);
static WINAPI BOOL (*pSystemParametersInfoW)(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni);
static WINAPI BOOL (*pSystemParametersInfoA)(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fuWinIni);
static WINAPI INT (*pGetSystemMetrics)(INT index);
static WINAPI INT (*pGetSystemMetricsForDpi)(INT index, UINT dpi);
static WINAPI BOOL (*pSwapMouseButton)(BOOL fSwap);
static WINAPI BOOL (*pSetDoubleClickTime)(UINT interval);
static WINAPI UINT (*pGetDoubleClickTime)(void);
static WINAPI COLORREF (*pGetSysColor)(INT nIndex);
static WINAPI BOOL (*pSetSysColors)(INT count, const INT * colors, const COLORREF * values);
static WINAPI DWORD_PTR (*pSetSysColorsTemp)(const COLORREF * pPens, const HBRUSH * pBrushes, DWORD_PTR n);
static WINAPI HBRUSH (*pGetSysColorBrush)(INT index);
static WINAPI LONG (*pChangeDisplaySettingsA)(LPDEVMODEA devmode, DWORD flags);
static WINAPI LONG (*pChangeDisplaySettingsW)(LPDEVMODEW devmode, DWORD flags);
static WINAPI LONG (*pChangeDisplaySettingsExA)(LPCSTR devname, LPDEVMODEA devmode, HWND hwnd, DWORD flags, LPVOID lparam);
static WINAPI LONG (*pChangeDisplaySettingsExW)(LPCWSTR devname, LPDEVMODEW devmode, HWND hwnd, DWORD flags, LPVOID lparam);
static WINAPI LONG (*pDisplayConfigGetDeviceInfo)(DISPLAYCONFIG_DEVICE_INFO_HEADER * packet);
static WINAPI BOOL (*pEnumDisplaySettingsW)(LPCWSTR name, DWORD n, LPDEVMODEW devmode);
static WINAPI BOOL (*pEnumDisplaySettingsA)(LPCSTR name, DWORD n, LPDEVMODEA devmode);
static WINAPI BOOL (*pEnumDisplaySettingsExA)(LPCSTR lpszDeviceName, DWORD iModeNum, LPDEVMODEA lpDevMode, DWORD dwFlags);
static WINAPI BOOL (*pEnumDisplaySettingsExW)(LPCWSTR lpszDeviceName, DWORD iModeNum, LPDEVMODEW lpDevMode, DWORD dwFlags);
static WINAPI BOOL (*pSetProcessDpiAwarenessContext)(DPI_AWARENESS_CONTEXT context);
static WINAPI BOOL (*pGetProcessDpiAwarenessInternal)(HANDLE process, DPI_AWARENESS * awareness);
static WINAPI BOOL (*pSetProcessDpiAwarenessInternal)(DPI_AWARENESS awareness);
static WINAPI BOOL (*pAreDpiAwarenessContextsEqual)(DPI_AWARENESS_CONTEXT ctx1, DPI_AWARENESS_CONTEXT ctx2);
static WINAPI DPI_AWARENESS (*pGetAwarenessFromDpiAwarenessContext)(DPI_AWARENESS_CONTEXT context);
static WINAPI BOOL (*pIsValidDpiAwarenessContext)(DPI_AWARENESS_CONTEXT context);
static WINAPI BOOL (*pSetProcessDPIAware)(void);
static WINAPI BOOL (*pIsProcessDPIAware)(void);
static WINAPI UINT (*pGetDpiForSystem)(void);
static WINAPI BOOL (*pGetDpiForMonitorInternal)(HMONITOR monitor, UINT type, UINT * x, UINT * y);
static WINAPI DPI_AWARENESS_CONTEXT (*pGetThreadDpiAwarenessContext)(void);
static WINAPI DPI_AWARENESS_CONTEXT (*pSetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT context);
static WINAPI BOOL (*pLogicalToPhysicalPointForPerMonitorDPI)(HWND hwnd, POINT * pt);
static WINAPI BOOL (*pPhysicalToLogicalPointForPerMonitorDPI)(HWND hwnd, POINT * pt);
static WINAPI HMONITOR (*pMonitorFromRect)(const RECT * rect, DWORD flags);
static WINAPI HMONITOR (*pMonitorFromPoint)(POINT pt, DWORD flags);
static WINAPI HMONITOR (*pMonitorFromWindow)(HWND hWnd, DWORD dwFlags);
static WINAPI BOOL (*pGetMonitorInfoA)(HMONITOR monitor, LPMONITORINFO info);
static WINAPI BOOL (*pGetMonitorInfoW)(HMONITOR monitor, LPMONITORINFO info);
static WINAPI BOOL (*pEnumDisplayMonitors)(HDC hdc, LPRECT rect, MONITORENUMPROC proc, LPARAM lp);
static WINAPI BOOL (*pEnumDisplayDevicesA)(LPCSTR device, DWORD index, DISPLAY_DEVICEA * info, DWORD flags);
static WINAPI BOOL (*pEnumDisplayDevicesW)(LPCWSTR device, DWORD index, DISPLAY_DEVICEW * info, DWORD flags);
static WINAPI BOOL (*pGetAutoRotationState)(AR_STATE * state);
static WINAPI BOOL (*pGetDisplayAutoRotationPreferences)(ORIENTATION_PREFERENCE * orientation);
static WINAPI BOOL (*pGetPhysicalCursorPos)(POINT * point);
static WINAPI BOOL (*pSetPhysicalCursorPos)(INT x, INT y);
static WINAPI BOOL (*pLogicalToPhysicalPoint)(HWND hwnd, POINT * point);
static WINAPI BOOL (*pPhysicalToLogicalPoint)(HWND hwnd, POINT * point);

extern WINAPI BOOL wine32b_SystemParametersInfoForDpi(UINT action, UINT val, PVOID ptr, UINT winini, UINT dpi)
{
	TRACE("Enter SystemParametersInfoForDpi\n");
	return pSystemParametersInfoForDpi(action, val, ptr, winini, dpi);
}

extern WINAPI void wine32a_SystemParametersInfoForDpi(void);
__ASM_GLOBAL_FUNC(wine32a_SystemParametersInfoForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemParametersInfoForDpi") "\n"
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

extern WINAPI BOOL wine32b_SystemParametersInfoW(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fWinIni)
{
	TRACE("Enter SystemParametersInfoW\n");
	return pSystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
}

extern WINAPI void wine32a_SystemParametersInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SystemParametersInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemParametersInfoW") "\n"
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

extern WINAPI BOOL wine32b_SystemParametersInfoA(UINT uiAction, UINT uiParam, PVOID pvParam, UINT fuWinIni)
{
	TRACE("Enter SystemParametersInfoA\n");
	return pSystemParametersInfoA(uiAction, uiParam, pvParam, fuWinIni);
}

extern WINAPI void wine32a_SystemParametersInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SystemParametersInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemParametersInfoA") "\n"
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

extern WINAPI INT wine32b_GetSystemMetrics(INT index)
{
	TRACE("Enter GetSystemMetrics\n");
	return pGetSystemMetrics(index);
}

extern WINAPI void wine32a_GetSystemMetrics(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemMetrics,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemMetrics") "\n"
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

extern WINAPI INT wine32b_GetSystemMetricsForDpi(INT index, UINT dpi)
{
	TRACE("Enter GetSystemMetricsForDpi\n");
	return pGetSystemMetricsForDpi(index, dpi);
}

extern WINAPI void wine32a_GetSystemMetricsForDpi(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemMetricsForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemMetricsForDpi") "\n"
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

extern WINAPI BOOL wine32b_SwapMouseButton(BOOL fSwap)
{
	TRACE("Enter SwapMouseButton\n");
	return pSwapMouseButton(fSwap);
}

extern WINAPI void wine32a_SwapMouseButton(void);
__ASM_GLOBAL_FUNC(wine32a_SwapMouseButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SwapMouseButton") "\n"
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

extern WINAPI BOOL wine32b_SetDoubleClickTime(UINT interval)
{
	TRACE("Enter SetDoubleClickTime\n");
	return pSetDoubleClickTime(interval);
}

extern WINAPI void wine32a_SetDoubleClickTime(void);
__ASM_GLOBAL_FUNC(wine32a_SetDoubleClickTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDoubleClickTime") "\n"
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

extern WINAPI UINT wine32b_GetDoubleClickTime(void)
{
	TRACE("Enter GetDoubleClickTime\n");
	return pGetDoubleClickTime();
}

extern WINAPI void wine32a_GetDoubleClickTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetDoubleClickTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDoubleClickTime") "\n"
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

extern WINAPI COLORREF wine32b_GetSysColor(INT nIndex)
{
	TRACE("Enter GetSysColor\n");
	return pGetSysColor(nIndex);
}

extern WINAPI void wine32a_GetSysColor(void);
__ASM_GLOBAL_FUNC(wine32a_GetSysColor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSysColor") "\n"
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

extern WINAPI BOOL wine32b_SetSysColors(INT count, const INT * colors, const COLORREF * values)
{
	TRACE("Enter SetSysColors\n");
	return pSetSysColors(count, colors, values);
}

extern WINAPI void wine32a_SetSysColors(void);
__ASM_GLOBAL_FUNC(wine32a_SetSysColors,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSysColors") "\n"
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

extern WINAPI DWORD_PTR wine32b_SetSysColorsTemp(const COLORREF * pPens, const HBRUSH * pBrushes, DWORD_PTR n)
{
	TRACE("Enter SetSysColorsTemp\n");
	return pSetSysColorsTemp(pPens, pBrushes, n);
}

extern WINAPI void wine32a_SetSysColorsTemp(void);
__ASM_GLOBAL_FUNC(wine32a_SetSysColorsTemp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSysColorsTemp") "\n"
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

extern WINAPI HBRUSH wine32b_GetSysColorBrush(INT index)
{
	TRACE("Enter GetSysColorBrush\n");
	return pGetSysColorBrush(index);
}

extern WINAPI void wine32a_GetSysColorBrush(void);
__ASM_GLOBAL_FUNC(wine32a_GetSysColorBrush,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSysColorBrush") "\n"
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

extern WINAPI LONG wine32b_ChangeDisplaySettingsA(LPDEVMODEA devmode, DWORD flags)
{
	TRACE("Enter ChangeDisplaySettingsA\n");
	return pChangeDisplaySettingsA(devmode, flags);
}

extern WINAPI void wine32a_ChangeDisplaySettingsA(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeDisplaySettingsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeDisplaySettingsA") "\n"
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

extern WINAPI LONG wine32b_ChangeDisplaySettingsW(LPDEVMODEW devmode, DWORD flags)
{
	TRACE("Enter ChangeDisplaySettingsW\n");
	return pChangeDisplaySettingsW(devmode, flags);
}

extern WINAPI void wine32a_ChangeDisplaySettingsW(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeDisplaySettingsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeDisplaySettingsW") "\n"
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

extern WINAPI LONG wine32b_ChangeDisplaySettingsExA(LPCSTR devname, LPDEVMODEA devmode, HWND hwnd, DWORD flags, LPVOID lparam)
{
	TRACE("Enter ChangeDisplaySettingsExA\n");
	return pChangeDisplaySettingsExA(devname, devmode, hwnd, flags, lparam);
}

extern WINAPI void wine32a_ChangeDisplaySettingsExA(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeDisplaySettingsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeDisplaySettingsExA") "\n"
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

extern WINAPI LONG wine32b_ChangeDisplaySettingsExW(LPCWSTR devname, LPDEVMODEW devmode, HWND hwnd, DWORD flags, LPVOID lparam)
{
	TRACE("Enter ChangeDisplaySettingsExW\n");
	return pChangeDisplaySettingsExW(devname, devmode, hwnd, flags, lparam);
}

extern WINAPI void wine32a_ChangeDisplaySettingsExW(void);
__ASM_GLOBAL_FUNC(wine32a_ChangeDisplaySettingsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChangeDisplaySettingsExW") "\n"
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

extern WINAPI LONG wine32b_DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER * packet)
{
	TRACE("Enter DisplayConfigGetDeviceInfo\n");
	return pDisplayConfigGetDeviceInfo(packet);
}

extern WINAPI void wine32a_DisplayConfigGetDeviceInfo(void);
__ASM_GLOBAL_FUNC(wine32a_DisplayConfigGetDeviceInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DisplayConfigGetDeviceInfo") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplaySettingsW(LPCWSTR name, DWORD n, LPDEVMODEW devmode)
{
	TRACE("Enter EnumDisplaySettingsW\n");
	return pEnumDisplaySettingsW(name, n, devmode);
}

extern WINAPI void wine32a_EnumDisplaySettingsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplaySettingsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplaySettingsW") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplaySettingsA(LPCSTR name, DWORD n, LPDEVMODEA devmode)
{
	TRACE("Enter EnumDisplaySettingsA\n");
	return pEnumDisplaySettingsA(name, n, devmode);
}

extern WINAPI void wine32a_EnumDisplaySettingsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplaySettingsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplaySettingsA") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplaySettingsExA(LPCSTR lpszDeviceName, DWORD iModeNum, LPDEVMODEA lpDevMode, DWORD dwFlags)
{
	TRACE("Enter EnumDisplaySettingsExA\n");
	return pEnumDisplaySettingsExA(lpszDeviceName, iModeNum, lpDevMode, dwFlags);
}

extern WINAPI void wine32a_EnumDisplaySettingsExA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplaySettingsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplaySettingsExA") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplaySettingsExW(LPCWSTR lpszDeviceName, DWORD iModeNum, LPDEVMODEW lpDevMode, DWORD dwFlags)
{
	TRACE("Enter EnumDisplaySettingsExW\n");
	return pEnumDisplaySettingsExW(lpszDeviceName, iModeNum, lpDevMode, dwFlags);
}

extern WINAPI void wine32a_EnumDisplaySettingsExW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplaySettingsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplaySettingsExW") "\n"
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

extern WINAPI BOOL wine32b_SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT context)
{
	TRACE("Enter SetProcessDpiAwarenessContext\n");
	return pSetProcessDpiAwarenessContext(context);
}

extern WINAPI void wine32a_SetProcessDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessDpiAwarenessContext") "\n"
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

extern WINAPI BOOL wine32b_GetProcessDpiAwarenessInternal(HANDLE process, DPI_AWARENESS * awareness)
{
	TRACE("Enter GetProcessDpiAwarenessInternal\n");
	return pGetProcessDpiAwarenessInternal(process, awareness);
}

extern WINAPI void wine32a_GetProcessDpiAwarenessInternal(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessDpiAwarenessInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessDpiAwarenessInternal") "\n"
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

extern WINAPI BOOL wine32b_SetProcessDpiAwarenessInternal(DPI_AWARENESS awareness)
{
	TRACE("Enter SetProcessDpiAwarenessInternal\n");
	return pSetProcessDpiAwarenessInternal(awareness);
}

extern WINAPI void wine32a_SetProcessDpiAwarenessInternal(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessDpiAwarenessInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessDpiAwarenessInternal") "\n"
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

extern WINAPI BOOL wine32b_AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT ctx1, DPI_AWARENESS_CONTEXT ctx2)
{
	TRACE("Enter AreDpiAwarenessContextsEqual\n");
	return pAreDpiAwarenessContextsEqual(ctx1, ctx2);
}

extern WINAPI void wine32a_AreDpiAwarenessContextsEqual(void);
__ASM_GLOBAL_FUNC(wine32a_AreDpiAwarenessContextsEqual,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AreDpiAwarenessContextsEqual") "\n"
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

extern WINAPI DPI_AWARENESS wine32b_GetAwarenessFromDpiAwarenessContext(DPI_AWARENESS_CONTEXT context)
{
	TRACE("Enter GetAwarenessFromDpiAwarenessContext\n");
	return pGetAwarenessFromDpiAwarenessContext(context);
}

extern WINAPI void wine32a_GetAwarenessFromDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_GetAwarenessFromDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAwarenessFromDpiAwarenessContext") "\n"
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

extern WINAPI BOOL wine32b_IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT context)
{
	TRACE("Enter IsValidDpiAwarenessContext\n");
	return pIsValidDpiAwarenessContext(context);
}

extern WINAPI void wine32a_IsValidDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_IsValidDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsValidDpiAwarenessContext") "\n"
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

extern WINAPI BOOL wine32b_SetProcessDPIAware(void)
{
	TRACE("Enter SetProcessDPIAware\n");
	return pSetProcessDPIAware();
}

extern WINAPI void wine32a_SetProcessDPIAware(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessDPIAware,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessDPIAware") "\n"
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

extern WINAPI BOOL wine32b_IsProcessDPIAware(void)
{
	TRACE("Enter IsProcessDPIAware\n");
	return pIsProcessDPIAware();
}

extern WINAPI void wine32a_IsProcessDPIAware(void);
__ASM_GLOBAL_FUNC(wine32a_IsProcessDPIAware,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsProcessDPIAware") "\n"
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

extern WINAPI UINT wine32b_GetDpiForSystem(void)
{
	TRACE("Enter GetDpiForSystem\n");
	return pGetDpiForSystem();
}

extern WINAPI void wine32a_GetDpiForSystem(void);
__ASM_GLOBAL_FUNC(wine32a_GetDpiForSystem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDpiForSystem") "\n"
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

extern WINAPI BOOL wine32b_GetDpiForMonitorInternal(HMONITOR monitor, UINT type, UINT * x, UINT * y)
{
	TRACE("Enter GetDpiForMonitorInternal\n");
	return pGetDpiForMonitorInternal(monitor, type, x, y);
}

extern WINAPI void wine32a_GetDpiForMonitorInternal(void);
__ASM_GLOBAL_FUNC(wine32a_GetDpiForMonitorInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDpiForMonitorInternal") "\n"
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

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_GetThreadDpiAwarenessContext(void)
{
	TRACE("Enter GetThreadDpiAwarenessContext\n");
	return pGetThreadDpiAwarenessContext();
}

extern WINAPI void wine32a_GetThreadDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_GetThreadDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetThreadDpiAwarenessContext") "\n"
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

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT context)
{
	TRACE("Enter SetThreadDpiAwarenessContext\n");
	return pSetThreadDpiAwarenessContext(context);
}

extern WINAPI void wine32a_SetThreadDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadDpiAwarenessContext") "\n"
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

extern WINAPI BOOL wine32b_LogicalToPhysicalPointForPerMonitorDPI(HWND hwnd, POINT * pt)
{
	TRACE("Enter LogicalToPhysicalPointForPerMonitorDPI\n");
	return pLogicalToPhysicalPointForPerMonitorDPI(hwnd, pt);
}

extern WINAPI void wine32a_LogicalToPhysicalPointForPerMonitorDPI(void);
__ASM_GLOBAL_FUNC(wine32a_LogicalToPhysicalPointForPerMonitorDPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LogicalToPhysicalPointForPerMonitorDPI") "\n"
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

extern WINAPI BOOL wine32b_PhysicalToLogicalPointForPerMonitorDPI(HWND hwnd, POINT * pt)
{
	TRACE("Enter PhysicalToLogicalPointForPerMonitorDPI\n");
	return pPhysicalToLogicalPointForPerMonitorDPI(hwnd, pt);
}

extern WINAPI void wine32a_PhysicalToLogicalPointForPerMonitorDPI(void);
__ASM_GLOBAL_FUNC(wine32a_PhysicalToLogicalPointForPerMonitorDPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PhysicalToLogicalPointForPerMonitorDPI") "\n"
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

extern WINAPI HMONITOR wine32b_MonitorFromRect(const RECT * rect, DWORD flags)
{
	TRACE("Enter MonitorFromRect\n");
	return pMonitorFromRect(rect, flags);
}

extern WINAPI void wine32a_MonitorFromRect(void);
__ASM_GLOBAL_FUNC(wine32a_MonitorFromRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MonitorFromRect") "\n"
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

extern WINAPI HMONITOR wine32b_MonitorFromPoint(POINT pt, DWORD flags)
{
	TRACE("Enter MonitorFromPoint\n");
	return pMonitorFromPoint(pt, flags);
}

extern WINAPI void wine32a_MonitorFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_MonitorFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MonitorFromPoint") "\n"
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

extern WINAPI HMONITOR wine32b_MonitorFromWindow(HWND hWnd, DWORD dwFlags)
{
	TRACE("Enter MonitorFromWindow\n");
	return pMonitorFromWindow(hWnd, dwFlags);
}

extern WINAPI void wine32a_MonitorFromWindow(void);
__ASM_GLOBAL_FUNC(wine32a_MonitorFromWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MonitorFromWindow") "\n"
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

extern WINAPI BOOL wine32b_GetMonitorInfoA(HMONITOR monitor, LPMONITORINFO info)
{
	TRACE("Enter GetMonitorInfoA\n");
	return pGetMonitorInfoA(monitor, info);
}

extern WINAPI void wine32a_GetMonitorInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetMonitorInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMonitorInfoA") "\n"
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

extern WINAPI BOOL wine32b_GetMonitorInfoW(HMONITOR monitor, LPMONITORINFO info)
{
	TRACE("Enter GetMonitorInfoW\n");
	return pGetMonitorInfoW(monitor, info);
}

extern WINAPI void wine32a_GetMonitorInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetMonitorInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMonitorInfoW") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplayMonitors(HDC hdc, LPRECT rect, MONITORENUMPROC proc, LPARAM lp)
{
	TRACE("Enter EnumDisplayMonitors\n");
	return pEnumDisplayMonitors(hdc, rect, proc, lp);
}

extern WINAPI void wine32a_EnumDisplayMonitors(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplayMonitors,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplayMonitors") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplayDevicesA(LPCSTR device, DWORD index, DISPLAY_DEVICEA * info, DWORD flags)
{
	TRACE("Enter EnumDisplayDevicesA\n");
	return pEnumDisplayDevicesA(device, index, info, flags);
}

extern WINAPI void wine32a_EnumDisplayDevicesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplayDevicesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplayDevicesA") "\n"
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

extern WINAPI BOOL wine32b_EnumDisplayDevicesW(LPCWSTR device, DWORD index, DISPLAY_DEVICEW * info, DWORD flags)
{
	TRACE("Enter EnumDisplayDevicesW\n");
	return pEnumDisplayDevicesW(device, index, info, flags);
}

extern WINAPI void wine32a_EnumDisplayDevicesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDisplayDevicesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDisplayDevicesW") "\n"
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

extern WINAPI BOOL wine32b_GetAutoRotationState(AR_STATE * state)
{
	TRACE("Enter GetAutoRotationState\n");
	return pGetAutoRotationState(state);
}

extern WINAPI void wine32a_GetAutoRotationState(void);
__ASM_GLOBAL_FUNC(wine32a_GetAutoRotationState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAutoRotationState") "\n"
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

extern WINAPI BOOL wine32b_GetDisplayAutoRotationPreferences(ORIENTATION_PREFERENCE * orientation)
{
	TRACE("Enter GetDisplayAutoRotationPreferences\n");
	return pGetDisplayAutoRotationPreferences(orientation);
}

extern WINAPI void wine32a_GetDisplayAutoRotationPreferences(void);
__ASM_GLOBAL_FUNC(wine32a_GetDisplayAutoRotationPreferences,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDisplayAutoRotationPreferences") "\n"
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

extern WINAPI BOOL wine32b_GetPhysicalCursorPos(POINT * point)
{
	TRACE("Enter GetPhysicalCursorPos\n");
	return pGetPhysicalCursorPos(point);
}

extern WINAPI void wine32a_GetPhysicalCursorPos(void);
__ASM_GLOBAL_FUNC(wine32a_GetPhysicalCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPhysicalCursorPos") "\n"
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

extern WINAPI BOOL wine32b_SetPhysicalCursorPos(INT x, INT y)
{
	TRACE("Enter SetPhysicalCursorPos\n");
	return pSetPhysicalCursorPos(x, y);
}

extern WINAPI void wine32a_SetPhysicalCursorPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetPhysicalCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetPhysicalCursorPos") "\n"
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

extern WINAPI BOOL wine32b_LogicalToPhysicalPoint(HWND hwnd, POINT * point)
{
	TRACE("Enter LogicalToPhysicalPoint\n");
	return pLogicalToPhysicalPoint(hwnd, point);
}

extern WINAPI void wine32a_LogicalToPhysicalPoint(void);
__ASM_GLOBAL_FUNC(wine32a_LogicalToPhysicalPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LogicalToPhysicalPoint") "\n"
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

extern WINAPI BOOL wine32b_PhysicalToLogicalPoint(HWND hwnd, POINT * point)
{
	TRACE("Enter PhysicalToLogicalPoint\n");
	return pPhysicalToLogicalPoint(hwnd, point);
}

extern WINAPI void wine32a_PhysicalToLogicalPoint(void);
__ASM_GLOBAL_FUNC(wine32a_PhysicalToLogicalPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PhysicalToLogicalPoint") "\n"
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

static WINAPI INT (*pDrawTextExW)(HDC hdc, LPWSTR str, INT i_count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp);
static WINAPI INT (*pDrawTextExA)(HDC hdc, LPSTR str, INT count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp);
static WINAPI INT (*pDrawTextW)(HDC hdc, LPCWSTR str, INT count, LPRECT rect, UINT flags);
static WINAPI INT (*pDrawTextA)(HDC hdc, LPCSTR str, INT count, LPRECT rect, UINT flags);
static WINAPI BOOL (*pGrayStringA)(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy);
static WINAPI BOOL (*pGrayStringW)(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy);
static WINAPI LONG (*pTabbedTextOutA)(HDC hdc, INT x, INT y, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg);
static WINAPI LONG (*pTabbedTextOutW)(HDC hdc, INT x, INT y, LPCWSTR str, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg);
static WINAPI DWORD (*pGetTabbedTextExtentA)(HDC hdc, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos);
static WINAPI DWORD (*pGetTabbedTextExtentW)(HDC hdc, LPCWSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos);

extern WINAPI INT wine32b_DrawTextExW(HDC hdc, LPWSTR str, INT i_count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp)
{
	TRACE("Enter DrawTextExW\n");
	return pDrawTextExW(hdc, str, i_count, rect, flags, dtp);
}

extern WINAPI void wine32a_DrawTextExW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextExW") "\n"
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

extern WINAPI INT wine32b_DrawTextExA(HDC hdc, LPSTR str, INT count, LPRECT rect, UINT flags, LPDRAWTEXTPARAMS dtp)
{
	TRACE("Enter DrawTextExA\n");
	return pDrawTextExA(hdc, str, count, rect, flags, dtp);
}

extern WINAPI void wine32a_DrawTextExA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextExA") "\n"
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

extern WINAPI INT wine32b_DrawTextW(HDC hdc, LPCWSTR str, INT count, LPRECT rect, UINT flags)
{
	TRACE("Enter DrawTextW\n");
	return pDrawTextW(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_DrawTextW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextW") "\n"
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

extern WINAPI INT wine32b_DrawTextA(HDC hdc, LPCSTR str, INT count, LPRECT rect, UINT flags)
{
	TRACE("Enter DrawTextA\n");
	return pDrawTextA(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_DrawTextA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawTextA") "\n"
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

extern WINAPI BOOL wine32b_GrayStringA(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy)
{
	TRACE("Enter GrayStringA\n");
	return pGrayStringA(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_GrayStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GrayStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GrayStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GrayStringW(HDC hdc, HBRUSH hbr, GRAYSTRINGPROC gsprc, LPARAM lParam, INT cch, INT x, INT y, INT cx, INT cy)
{
	TRACE("Enter GrayStringW\n");
	return pGrayStringW(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_GrayStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GrayStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GrayStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_TabbedTextOutA(HDC hdc, INT x, INT y, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg)
{
	TRACE("Enter TabbedTextOutA\n");
	return pTabbedTextOutA(hdc, x, y, lpstr, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_TabbedTextOutA(void);
__ASM_GLOBAL_FUNC(wine32a_TabbedTextOutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TabbedTextOutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_TabbedTextOutW(HDC hdc, INT x, INT y, LPCWSTR str, INT count, INT cTabStops, const INT * lpTabPos, INT nTabOrg)
{
	TRACE("Enter TabbedTextOutW\n");
	return pTabbedTextOutW(hdc, x, y, str, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_TabbedTextOutW(void);
__ASM_GLOBAL_FUNC(wine32a_TabbedTextOutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TabbedTextOutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetTabbedTextExtentA(HDC hdc, LPCSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos)
{
	TRACE("Enter GetTabbedTextExtentA\n");
	return pGetTabbedTextExtentA(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_GetTabbedTextExtentA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTabbedTextExtentA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTabbedTextExtentA") "\n"
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

extern WINAPI DWORD wine32b_GetTabbedTextExtentW(HDC hdc, LPCWSTR lpstr, INT count, INT cTabStops, const INT * lpTabPos)
{
	TRACE("Enter GetTabbedTextExtentW\n");
	return pGetTabbedTextExtentW(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_GetTabbedTextExtentW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTabbedTextExtentW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTabbedTextExtentW") "\n"
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

static WINAPI BOOL (*pDrawEdge)(HDC hdc, LPRECT rc, UINT edge, UINT flags);
static WINAPI BOOL (*pDrawFrameControl)(HDC hdc, LPRECT rc, UINT uType, UINT uState);
static WINAPI BOOL (*pSetRect)(LPRECT rect, INT left, INT top, INT right, INT bottom);
static WINAPI BOOL (*pSetRectEmpty)(LPRECT rect);
static WINAPI BOOL (*pCopyRect)(RECT * dest, const RECT * src);
static WINAPI BOOL (*pIsRectEmpty)(const RECT * rect);
static WINAPI BOOL (*pPtInRect)(const RECT * rect, POINT pt);
static WINAPI BOOL (*pOffsetRect)(LPRECT rect, INT x, INT y);
static WINAPI BOOL (*pInflateRect)(LPRECT rect, INT x, INT y);
static WINAPI BOOL (*pIntersectRect)(LPRECT dest, const RECT * src1, const RECT * src2);
static WINAPI BOOL (*pUnionRect)(LPRECT dest, const RECT * src1, const RECT * src2);
static WINAPI BOOL (*pEqualRect)(const RECT * rect1, const RECT * rect2);
static WINAPI BOOL (*pSubtractRect)(LPRECT dest, const RECT * src1, const RECT * src2);
static WINAPI INT (*pFillRect)(HDC hdc, const RECT * rect, HBRUSH hbrush);
static WINAPI BOOL (*pInvertRect)(HDC hdc, const RECT * rect);
static WINAPI INT (*pFrameRect)(HDC hdc, const RECT * rect, HBRUSH hbrush);
static WINAPI BOOL (*pDrawFocusRect)(HDC hdc, const RECT * rc);
static WINAPI BOOL (*pDrawAnimatedRects)(HWND hwnd, INT idAni, const RECT * lprcFrom, const RECT * lprcTo);
static WINAPI BOOL (*pDrawStateA)(HDC hdc, HBRUSH hbr, DRAWSTATEPROC func, LPARAM ldata, WPARAM wdata, INT x, INT y, INT cx, INT cy, UINT flags);
static WINAPI BOOL (*pDrawStateW)(HDC hdc, HBRUSH hbr, DRAWSTATEPROC func, LPARAM ldata, WPARAM wdata, INT x, INT y, INT cx, INT cy, UINT flags);

extern WINAPI BOOL wine32b_DrawEdge(HDC hdc, LPRECT rc, UINT edge, UINT flags)
{
	TRACE("Enter DrawEdge\n");
	return pDrawEdge(hdc, rc, edge, flags);
}

extern WINAPI void wine32a_DrawEdge(void);
__ASM_GLOBAL_FUNC(wine32a_DrawEdge,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawEdge") "\n"
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

extern WINAPI BOOL wine32b_DrawFrameControl(HDC hdc, LPRECT rc, UINT uType, UINT uState)
{
	TRACE("Enter DrawFrameControl\n");
	return pDrawFrameControl(hdc, rc, uType, uState);
}

extern WINAPI void wine32a_DrawFrameControl(void);
__ASM_GLOBAL_FUNC(wine32a_DrawFrameControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawFrameControl") "\n"
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

extern WINAPI BOOL wine32b_SetRect(LPRECT rect, INT left, INT top, INT right, INT bottom)
{
	TRACE("Enter SetRect\n");
	return pSetRect(rect, left, top, right, bottom);
}

extern WINAPI void wine32a_SetRect(void);
__ASM_GLOBAL_FUNC(wine32a_SetRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetRect") "\n"
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

extern WINAPI BOOL wine32b_SetRectEmpty(LPRECT rect)
{
	TRACE("Enter SetRectEmpty\n");
	return pSetRectEmpty(rect);
}

extern WINAPI void wine32a_SetRectEmpty(void);
__ASM_GLOBAL_FUNC(wine32a_SetRectEmpty,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetRectEmpty") "\n"
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

extern WINAPI BOOL wine32b_CopyRect(RECT * dest, const RECT * src)
{
	TRACE("Enter CopyRect\n");
	return pCopyRect(dest, src);
}

extern WINAPI void wine32a_CopyRect(void);
__ASM_GLOBAL_FUNC(wine32a_CopyRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyRect") "\n"
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

extern WINAPI BOOL wine32b_IsRectEmpty(const RECT * rect)
{
	TRACE("Enter IsRectEmpty\n");
	return pIsRectEmpty(rect);
}

extern WINAPI void wine32a_IsRectEmpty(void);
__ASM_GLOBAL_FUNC(wine32a_IsRectEmpty,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsRectEmpty") "\n"
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

extern WINAPI BOOL wine32b_PtInRect(const RECT * rect, POINT pt)
{
	TRACE("Enter PtInRect\n");
	return pPtInRect(rect, pt);
}

extern WINAPI void wine32a_PtInRect(void);
__ASM_GLOBAL_FUNC(wine32a_PtInRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PtInRect") "\n"
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

extern WINAPI BOOL wine32b_OffsetRect(LPRECT rect, INT x, INT y)
{
	TRACE("Enter OffsetRect\n");
	return pOffsetRect(rect, x, y);
}

extern WINAPI void wine32a_OffsetRect(void);
__ASM_GLOBAL_FUNC(wine32a_OffsetRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OffsetRect") "\n"
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

extern WINAPI BOOL wine32b_InflateRect(LPRECT rect, INT x, INT y)
{
	TRACE("Enter InflateRect\n");
	return pInflateRect(rect, x, y);
}

extern WINAPI void wine32a_InflateRect(void);
__ASM_GLOBAL_FUNC(wine32a_InflateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InflateRect") "\n"
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

extern WINAPI BOOL wine32b_IntersectRect(LPRECT dest, const RECT * src1, const RECT * src2)
{
	TRACE("Enter IntersectRect\n");
	return pIntersectRect(dest, src1, src2);
}

extern WINAPI void wine32a_IntersectRect(void);
__ASM_GLOBAL_FUNC(wine32a_IntersectRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IntersectRect") "\n"
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

extern WINAPI BOOL wine32b_UnionRect(LPRECT dest, const RECT * src1, const RECT * src2)
{
	TRACE("Enter UnionRect\n");
	return pUnionRect(dest, src1, src2);
}

extern WINAPI void wine32a_UnionRect(void);
__ASM_GLOBAL_FUNC(wine32a_UnionRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnionRect") "\n"
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

extern WINAPI BOOL wine32b_EqualRect(const RECT * rect1, const RECT * rect2)
{
	TRACE("Enter EqualRect\n");
	return pEqualRect(rect1, rect2);
}

extern WINAPI void wine32a_EqualRect(void);
__ASM_GLOBAL_FUNC(wine32a_EqualRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EqualRect") "\n"
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

extern WINAPI BOOL wine32b_SubtractRect(LPRECT dest, const RECT * src1, const RECT * src2)
{
	TRACE("Enter SubtractRect\n");
	return pSubtractRect(dest, src1, src2);
}

extern WINAPI void wine32a_SubtractRect(void);
__ASM_GLOBAL_FUNC(wine32a_SubtractRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SubtractRect") "\n"
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

extern WINAPI INT wine32b_FillRect(HDC hdc, const RECT * rect, HBRUSH hbrush)
{
	TRACE("Enter FillRect\n");
	return pFillRect(hdc, rect, hbrush);
}

extern WINAPI void wine32a_FillRect(void);
__ASM_GLOBAL_FUNC(wine32a_FillRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FillRect") "\n"
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

extern WINAPI BOOL wine32b_InvertRect(HDC hdc, const RECT * rect)
{
	TRACE("Enter InvertRect\n");
	return pInvertRect(hdc, rect);
}

extern WINAPI void wine32a_InvertRect(void);
__ASM_GLOBAL_FUNC(wine32a_InvertRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InvertRect") "\n"
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

extern WINAPI INT wine32b_FrameRect(HDC hdc, const RECT * rect, HBRUSH hbrush)
{
	TRACE("Enter FrameRect\n");
	return pFrameRect(hdc, rect, hbrush);
}

extern WINAPI void wine32a_FrameRect(void);
__ASM_GLOBAL_FUNC(wine32a_FrameRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FrameRect") "\n"
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

extern WINAPI BOOL wine32b_DrawFocusRect(HDC hdc, const RECT * rc)
{
	TRACE("Enter DrawFocusRect\n");
	return pDrawFocusRect(hdc, rc);
}

extern WINAPI void wine32a_DrawFocusRect(void);
__ASM_GLOBAL_FUNC(wine32a_DrawFocusRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawFocusRect") "\n"
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

extern WINAPI BOOL wine32b_DrawAnimatedRects(HWND hwnd, INT idAni, const RECT * lprcFrom, const RECT * lprcTo)
{
	TRACE("Enter DrawAnimatedRects\n");
	return pDrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo);
}

extern WINAPI void wine32a_DrawAnimatedRects(void);
__ASM_GLOBAL_FUNC(wine32a_DrawAnimatedRects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawAnimatedRects") "\n"
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

extern WINAPI BOOL wine32b_DrawStateA(HDC hdc, HBRUSH hbr, DRAWSTATEPROC func, LPARAM ldata, WPARAM wdata, INT x, INT y, INT cx, INT cy, UINT flags)
{
	TRACE("Enter DrawStateA\n");
	return pDrawStateA(hdc, hbr, func, ldata, wdata, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_DrawStateA(void);
__ASM_GLOBAL_FUNC(wine32a_DrawStateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawStateA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DrawStateW(HDC hdc, HBRUSH hbr, DRAWSTATEPROC func, LPARAM ldata, WPARAM wdata, INT x, INT y, INT cx, INT cy, UINT flags)
{
	TRACE("Enter DrawStateW\n");
	return pDrawStateW(hdc, hbr, func, ldata, wdata, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_DrawStateW(void);
__ASM_GLOBAL_FUNC(wine32a_DrawStateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DrawStateW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI UINT (*pUserRealizePalette)(HDC hDC);
static WINAPI BOOL (*pExitWindowsEx)(UINT flags, DWORD reason);
static WINAPI BOOL (*pLockWorkStation)(void);
static WINAPI int (*pRegisterServicesProcess)(DWORD ServicesProcessId);
static WINAPI BOOL (*pShutdownBlockReasonCreate)(HWND hwnd, LPCWSTR reason);
static WINAPI BOOL (*pShutdownBlockReasonDestroy)(HWND hwnd);

extern WINAPI UINT wine32b_UserRealizePalette(HDC hDC)
{
	TRACE("Enter UserRealizePalette\n");
	return pUserRealizePalette(hDC);
}

extern WINAPI void wine32a_UserRealizePalette(void);
__ASM_GLOBAL_FUNC(wine32a_UserRealizePalette,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UserRealizePalette") "\n"
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

extern WINAPI BOOL wine32b_ExitWindowsEx(UINT flags, DWORD reason)
{
	TRACE("Enter ExitWindowsEx\n");
	return pExitWindowsEx(flags, reason);
}

extern WINAPI void wine32a_ExitWindowsEx(void);
__ASM_GLOBAL_FUNC(wine32a_ExitWindowsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExitWindowsEx") "\n"
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

extern WINAPI BOOL wine32b_LockWorkStation(void)
{
	TRACE("Enter LockWorkStation\n");
	return pLockWorkStation();
}

extern WINAPI void wine32a_LockWorkStation(void);
__ASM_GLOBAL_FUNC(wine32a_LockWorkStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LockWorkStation") "\n"
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

extern WINAPI int wine32b_RegisterServicesProcess(DWORD ServicesProcessId)
{
	TRACE("Enter RegisterServicesProcess\n");
	return pRegisterServicesProcess(ServicesProcessId);
}

extern WINAPI void wine32a_RegisterServicesProcess(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterServicesProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterServicesProcess") "\n"
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

extern WINAPI BOOL wine32b_ShutdownBlockReasonCreate(HWND hwnd, LPCWSTR reason)
{
	TRACE("Enter ShutdownBlockReasonCreate\n");
	return pShutdownBlockReasonCreate(hwnd, reason);
}

extern WINAPI void wine32a_ShutdownBlockReasonCreate(void);
__ASM_GLOBAL_FUNC(wine32a_ShutdownBlockReasonCreate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShutdownBlockReasonCreate") "\n"
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

extern WINAPI BOOL wine32b_ShutdownBlockReasonDestroy(HWND hwnd)
{
	TRACE("Enter ShutdownBlockReasonDestroy\n");
	return pShutdownBlockReasonDestroy(hwnd);
}

extern WINAPI void wine32a_ShutdownBlockReasonDestroy(void);
__ASM_GLOBAL_FUNC(wine32a_ShutdownBlockReasonDestroy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShutdownBlockReasonDestroy") "\n"
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

static WINAPI HWND (*pCreateWindowExA)(DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data);
static WINAPI HWND (*pCreateWindowExW)(DWORD exStyle, LPCWSTR className, LPCWSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data);
static WINAPI BOOL (*pDestroyWindow)(HWND hwnd);
static WINAPI BOOL (*pCloseWindow)(HWND hwnd);
static WINAPI BOOL (*pOpenIcon)(HWND hwnd);
static WINAPI HWND (*pFindWindowExW)(HWND parent, HWND child, LPCWSTR className, LPCWSTR title);
static WINAPI HWND (*pFindWindowA)(LPCSTR className, LPCSTR title);
static WINAPI HWND (*pFindWindowExA)(HWND parent, HWND child, LPCSTR className, LPCSTR title);
static WINAPI HWND (*pFindWindowW)(LPCWSTR className, LPCWSTR title);
static WINAPI HWND (*pGetDesktopWindow)(void);
static WINAPI BOOL (*pEnableWindow)(HWND hwnd, BOOL enable);
static WINAPI BOOL (*pIsWindowEnabled)(HWND hWnd);
static WINAPI BOOL (*pIsWindowUnicode)(HWND hwnd);
static WINAPI DPI_AWARENESS_CONTEXT (*pGetWindowDpiAwarenessContext)(HWND hwnd);
static WINAPI UINT (*pGetDpiForWindow)(HWND hwnd);
static WINAPI WORD (*pGetWindowWord)(HWND hwnd, INT offset);
static WINAPI LONG (*pGetWindowLongA)(HWND hwnd, INT offset);
static WINAPI LONG (*pGetWindowLongW)(HWND hwnd, INT offset);
static WINAPI WORD (*pSetWindowWord)(HWND hwnd, INT offset, WORD newval);
static WINAPI LONG (*pSetWindowLongA)(HWND hwnd, INT offset, LONG newval);
static WINAPI LONG (*pSetWindowLongW)(HWND hwnd, INT offset, LONG newval);
static WINAPI INT (*pGetWindowTextA)(HWND hwnd, LPSTR lpString, INT nMaxCount);
static WINAPI INT (*pInternalGetWindowText)(HWND hwnd, LPWSTR lpString, INT nMaxCount);
static WINAPI INT (*pGetWindowTextW)(HWND hwnd, LPWSTR lpString, INT nMaxCount);
static WINAPI BOOL (*pSetWindowTextA)(HWND hwnd, LPCSTR lpString);
static WINAPI BOOL (*pSetWindowTextW)(HWND hwnd, LPCWSTR lpString);
static WINAPI INT (*pGetWindowTextLengthA)(HWND hwnd);
static WINAPI INT (*pGetWindowTextLengthW)(HWND hwnd);
static WINAPI BOOL (*pIsWindow)(HWND hwnd);
static WINAPI DWORD (*pGetWindowThreadProcessId)(HWND hwnd, LPDWORD process);
static WINAPI HWND (*pGetParent)(HWND hwnd);
static WINAPI HWND (*pGetAncestor)(HWND hwnd, UINT type);
static WINAPI HWND (*pSetParent)(HWND hwnd, HWND parent);
static WINAPI BOOL (*pIsChild)(HWND parent, HWND child);
static WINAPI BOOL (*pIsWindowVisible)(HWND hwnd);
static WINAPI HWND (*pGetTopWindow)(HWND hwnd);
static WINAPI HWND (*pGetWindow)(HWND hwnd, UINT rel);
static WINAPI BOOL (*pShowOwnedPopups)(HWND owner, BOOL fShow);
static WINAPI HWND (*pGetLastActivePopup)(HWND hwnd);
static WINAPI BOOL (*pEnumWindows)(WNDENUMPROC lpEnumFunc, LPARAM lParam);
static WINAPI BOOL (*pEnumThreadWindows)(DWORD id, WNDENUMPROC func, LPARAM lParam);
static WINAPI BOOL (*pEnumDesktopWindows)(HDESK desktop, WNDENUMPROC func, LPARAM lparam);
static WINAPI BOOL (*pEnumChildWindows)(HWND parent, WNDENUMPROC func, LPARAM lParam);
static WINAPI BOOL (*pAnyPopup)(void);
static WINAPI BOOL (*pFlashWindow)(HWND hWnd, BOOL bInvert);
static WINAPI BOOL (*pFlashWindowEx)(PFLASHWINFO pfinfo);
static WINAPI DWORD (*pGetWindowContextHelpId)(HWND hwnd);
static WINAPI BOOL (*pSetWindowContextHelpId)(HWND hwnd, DWORD id);
static WINAPI BOOL (*pDragDetect)(HWND hWnd, POINT pt);
static WINAPI UINT (*pGetWindowModuleFileNameA)(HWND hwnd, LPSTR module, UINT size);
static WINAPI UINT (*pGetWindowModuleFileNameW)(HWND hwnd, LPWSTR module, UINT size);
static WINAPI BOOL (*pGetWindowInfo)(HWND hwnd, PWINDOWINFO pwi);
static WINAPI BOOL (*pSwitchDesktop)(HDESK hDesktop);
static WINAPI BOOL (*p__wine_set_pixel_format)(HWND hwnd, int format);
static WINAPI BOOL (*pSetLayeredWindowAttributes)(HWND hwnd, COLORREF key, BYTE alpha, DWORD flags);
static WINAPI BOOL (*pGetLayeredWindowAttributes)(HWND hwnd, COLORREF * key, BYTE * alpha, DWORD * flags);
static WINAPI BOOL (*pUpdateLayeredWindowIndirect)(HWND hwnd, const UPDATELAYEREDWINDOWINFO * info);
static WINAPI BOOL (*pUpdateLayeredWindow)(HWND hwnd, HDC hdcDst, POINT * pptDst, SIZE * psize, HDC hdcSrc, POINT * pptSrc, COLORREF crKey, BLENDFUNCTION * pblend, DWORD flags);
static WINAPI BOOL (*pGetProcessDefaultLayout)(DWORD * layout);
static WINAPI BOOL (*pSetProcessDefaultLayout)(DWORD layout);
static WINAPI LONG_PTR (*pGetWindowLongPtrW)(HWND hwnd, INT offset);
static WINAPI LONG_PTR (*pGetWindowLongPtrA)(HWND hwnd, INT offset);
static WINAPI LONG_PTR (*pSetWindowLongPtrW)(HWND hwnd, INT offset, LONG_PTR newval);
static WINAPI LONG_PTR (*pSetWindowLongPtrA)(HWND hwnd, INT offset, LONG_PTR newval);
static WINAPI BOOL (*pRegisterTouchWindow)(HWND hwnd, ULONG flags);
static WINAPI BOOL (*pUnregisterTouchWindow)(HWND hwnd);
static WINAPI BOOL (*pCloseTouchInputHandle)(HTOUCHINPUT handle);
static WINAPI BOOL (*pGetTouchInputInfo)(HTOUCHINPUT handle, UINT count, TOUCHINPUT * ptr, int size);
static WINAPI BOOL (*pGetGestureInfo)(HGESTUREINFO handle, PGESTUREINFO ptr);
static WINAPI BOOL (*pGetWindowDisplayAffinity)(HWND hwnd, DWORD * affinity);
static WINAPI BOOL (*pSetWindowDisplayAffinity)(HWND hwnd, DWORD affinity);
static WINAPI BOOL (*pSetWindowCompositionAttribute)(HWND hwnd, void * data);

extern WINAPI HWND wine32b_CreateWindowExA(DWORD exStyle, LPCSTR className, LPCSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data)
{
	TRACE("Enter CreateWindowExA\n");
	return pCreateWindowExA(exStyle, className, windowName, style, x, y, width, height, parent, menu, instance, data);
}

extern WINAPI void wine32a_CreateWindowExA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWindowExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWindowExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $48, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_CreateWindowExW(DWORD exStyle, LPCWSTR className, LPCWSTR windowName, DWORD style, INT x, INT y, INT width, INT height, HWND parent, HMENU menu, HINSTANCE instance, LPVOID data)
{
	TRACE("Enter CreateWindowExW\n");
	return pCreateWindowExW(exStyle, className, windowName, style, x, y, width, height, parent, menu, instance, data);
}

extern WINAPI void wine32a_CreateWindowExW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWindowExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWindowExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $48, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DestroyWindow(HWND hwnd)
{
	TRACE("Enter DestroyWindow\n");
	return pDestroyWindow(hwnd);
}

extern WINAPI void wine32a_DestroyWindow(void);
__ASM_GLOBAL_FUNC(wine32a_DestroyWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DestroyWindow") "\n"
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

extern WINAPI BOOL wine32b_CloseWindow(HWND hwnd)
{
	TRACE("Enter CloseWindow\n");
	return pCloseWindow(hwnd);
}

extern WINAPI void wine32a_CloseWindow(void);
__ASM_GLOBAL_FUNC(wine32a_CloseWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseWindow") "\n"
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

extern WINAPI BOOL wine32b_OpenIcon(HWND hwnd)
{
	TRACE("Enter OpenIcon\n");
	return pOpenIcon(hwnd);
}

extern WINAPI void wine32a_OpenIcon(void);
__ASM_GLOBAL_FUNC(wine32a_OpenIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenIcon") "\n"
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

extern WINAPI HWND wine32b_FindWindowExW(HWND parent, HWND child, LPCWSTR className, LPCWSTR title)
{
	TRACE("Enter FindWindowExW\n");
	return pFindWindowExW(parent, child, className, title);
}

extern WINAPI void wine32a_FindWindowExW(void);
__ASM_GLOBAL_FUNC(wine32a_FindWindowExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindWindowExW") "\n"
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

extern WINAPI HWND wine32b_FindWindowA(LPCSTR className, LPCSTR title)
{
	TRACE("Enter FindWindowA\n");
	return pFindWindowA(className, title);
}

extern WINAPI void wine32a_FindWindowA(void);
__ASM_GLOBAL_FUNC(wine32a_FindWindowA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindWindowA") "\n"
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

extern WINAPI HWND wine32b_FindWindowExA(HWND parent, HWND child, LPCSTR className, LPCSTR title)
{
	TRACE("Enter FindWindowExA\n");
	return pFindWindowExA(parent, child, className, title);
}

extern WINAPI void wine32a_FindWindowExA(void);
__ASM_GLOBAL_FUNC(wine32a_FindWindowExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindWindowExA") "\n"
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

extern WINAPI HWND wine32b_FindWindowW(LPCWSTR className, LPCWSTR title)
{
	TRACE("Enter FindWindowW\n");
	return pFindWindowW(className, title);
}

extern WINAPI void wine32a_FindWindowW(void);
__ASM_GLOBAL_FUNC(wine32a_FindWindowW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindWindowW") "\n"
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

extern WINAPI HWND wine32b_GetDesktopWindow(void)
{
	TRACE("Enter GetDesktopWindow\n");
	return pGetDesktopWindow();
}

extern WINAPI void wine32a_GetDesktopWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetDesktopWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDesktopWindow") "\n"
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

extern WINAPI BOOL wine32b_EnableWindow(HWND hwnd, BOOL enable)
{
	TRACE("Enter EnableWindow\n");
	return pEnableWindow(hwnd, enable);
}

extern WINAPI void wine32a_EnableWindow(void);
__ASM_GLOBAL_FUNC(wine32a_EnableWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableWindow") "\n"
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

extern WINAPI BOOL wine32b_IsWindowEnabled(HWND hWnd)
{
	TRACE("Enter IsWindowEnabled\n");
	return pIsWindowEnabled(hWnd);
}

extern WINAPI void wine32a_IsWindowEnabled(void);
__ASM_GLOBAL_FUNC(wine32a_IsWindowEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWindowEnabled") "\n"
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

extern WINAPI BOOL wine32b_IsWindowUnicode(HWND hwnd)
{
	TRACE("Enter IsWindowUnicode\n");
	return pIsWindowUnicode(hwnd);
}

extern WINAPI void wine32a_IsWindowUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_IsWindowUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWindowUnicode") "\n"
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

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_GetWindowDpiAwarenessContext(HWND hwnd)
{
	TRACE("Enter GetWindowDpiAwarenessContext\n");
	return pGetWindowDpiAwarenessContext(hwnd);
}

extern WINAPI void wine32a_GetWindowDpiAwarenessContext(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowDpiAwarenessContext") "\n"
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

extern WINAPI UINT wine32b_GetDpiForWindow(HWND hwnd)
{
	TRACE("Enter GetDpiForWindow\n");
	return pGetDpiForWindow(hwnd);
}

extern WINAPI void wine32a_GetDpiForWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetDpiForWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDpiForWindow") "\n"
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

extern WINAPI WORD wine32b_GetWindowWord(HWND hwnd, INT offset)
{
	TRACE("Enter GetWindowWord\n");
	return pGetWindowWord(hwnd, offset);
}

extern WINAPI void wine32a_GetWindowWord(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowWord") "\n"
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

extern WINAPI LONG wine32b_GetWindowLongA(HWND hwnd, INT offset)
{
	TRACE("Enter GetWindowLongA\n");
	return pGetWindowLongA(hwnd, offset);
}

extern WINAPI void wine32a_GetWindowLongA(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowLongA") "\n"
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

extern WINAPI LONG wine32b_GetWindowLongW(HWND hwnd, INT offset)
{
	TRACE("Enter GetWindowLongW\n");
	return pGetWindowLongW(hwnd, offset);
}

extern WINAPI void wine32a_GetWindowLongW(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowLongW") "\n"
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

extern WINAPI WORD wine32b_SetWindowWord(HWND hwnd, INT offset, WORD newval)
{
	TRACE("Enter SetWindowWord\n");
	return pSetWindowWord(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetWindowWord(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowWord") "\n"
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

extern WINAPI LONG wine32b_SetWindowLongA(HWND hwnd, INT offset, LONG newval)
{
	TRACE("Enter SetWindowLongA\n");
	return pSetWindowLongA(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetWindowLongA(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowLongA") "\n"
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

extern WINAPI LONG wine32b_SetWindowLongW(HWND hwnd, INT offset, LONG newval)
{
	TRACE("Enter SetWindowLongW\n");
	return pSetWindowLongW(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetWindowLongW(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowLongW") "\n"
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

extern WINAPI INT wine32b_GetWindowTextA(HWND hwnd, LPSTR lpString, INT nMaxCount)
{
	TRACE("Enter GetWindowTextA\n");
	return pGetWindowTextA(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_GetWindowTextA(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowTextA") "\n"
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

extern WINAPI INT wine32b_InternalGetWindowText(HWND hwnd, LPWSTR lpString, INT nMaxCount)
{
	TRACE("Enter InternalGetWindowText\n");
	return pInternalGetWindowText(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_InternalGetWindowText(void);
__ASM_GLOBAL_FUNC(wine32a_InternalGetWindowText,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InternalGetWindowText") "\n"
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

extern WINAPI INT wine32b_GetWindowTextW(HWND hwnd, LPWSTR lpString, INT nMaxCount)
{
	TRACE("Enter GetWindowTextW\n");
	return pGetWindowTextW(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_GetWindowTextW(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowTextW") "\n"
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

extern WINAPI BOOL wine32b_SetWindowTextA(HWND hwnd, LPCSTR lpString)
{
	TRACE("Enter SetWindowTextA\n");
	return pSetWindowTextA(hwnd, lpString);
}

extern WINAPI void wine32a_SetWindowTextA(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowTextA") "\n"
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

extern WINAPI BOOL wine32b_SetWindowTextW(HWND hwnd, LPCWSTR lpString)
{
	TRACE("Enter SetWindowTextW\n");
	return pSetWindowTextW(hwnd, lpString);
}

extern WINAPI void wine32a_SetWindowTextW(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowTextW") "\n"
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

extern WINAPI INT wine32b_GetWindowTextLengthA(HWND hwnd)
{
	TRACE("Enter GetWindowTextLengthA\n");
	return pGetWindowTextLengthA(hwnd);
}

extern WINAPI void wine32a_GetWindowTextLengthA(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowTextLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowTextLengthA") "\n"
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

extern WINAPI INT wine32b_GetWindowTextLengthW(HWND hwnd)
{
	TRACE("Enter GetWindowTextLengthW\n");
	return pGetWindowTextLengthW(hwnd);
}

extern WINAPI void wine32a_GetWindowTextLengthW(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowTextLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowTextLengthW") "\n"
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

extern WINAPI BOOL wine32b_IsWindow(HWND hwnd)
{
	TRACE("Enter IsWindow\n");
	return pIsWindow(hwnd);
}

extern WINAPI void wine32a_IsWindow(void);
__ASM_GLOBAL_FUNC(wine32a_IsWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWindow") "\n"
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

extern WINAPI DWORD wine32b_GetWindowThreadProcessId(HWND hwnd, LPDWORD process)
{
	TRACE("Enter GetWindowThreadProcessId\n");
	return pGetWindowThreadProcessId(hwnd, process);
}

extern WINAPI void wine32a_GetWindowThreadProcessId(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowThreadProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowThreadProcessId") "\n"
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

extern WINAPI HWND wine32b_GetParent(HWND hwnd)
{
	TRACE("Enter GetParent\n");
	return pGetParent(hwnd);
}

extern WINAPI void wine32a_GetParent(void);
__ASM_GLOBAL_FUNC(wine32a_GetParent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetParent") "\n"
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

extern WINAPI HWND wine32b_GetAncestor(HWND hwnd, UINT type)
{
	TRACE("Enter GetAncestor\n");
	return pGetAncestor(hwnd, type);
}

extern WINAPI void wine32a_GetAncestor(void);
__ASM_GLOBAL_FUNC(wine32a_GetAncestor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAncestor") "\n"
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

extern WINAPI HWND wine32b_SetParent(HWND hwnd, HWND parent)
{
	TRACE("Enter SetParent\n");
	return pSetParent(hwnd, parent);
}

extern WINAPI void wine32a_SetParent(void);
__ASM_GLOBAL_FUNC(wine32a_SetParent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetParent") "\n"
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

extern WINAPI BOOL wine32b_IsChild(HWND parent, HWND child)
{
	TRACE("Enter IsChild\n");
	return pIsChild(parent, child);
}

extern WINAPI void wine32a_IsChild(void);
__ASM_GLOBAL_FUNC(wine32a_IsChild,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsChild") "\n"
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

extern WINAPI BOOL wine32b_IsWindowVisible(HWND hwnd)
{
	TRACE("Enter IsWindowVisible\n");
	return pIsWindowVisible(hwnd);
}

extern WINAPI void wine32a_IsWindowVisible(void);
__ASM_GLOBAL_FUNC(wine32a_IsWindowVisible,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsWindowVisible") "\n"
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

extern WINAPI HWND wine32b_GetTopWindow(HWND hwnd)
{
	TRACE("Enter GetTopWindow\n");
	return pGetTopWindow(hwnd);
}

extern WINAPI void wine32a_GetTopWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetTopWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTopWindow") "\n"
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

extern WINAPI HWND wine32b_GetWindow(HWND hwnd, UINT rel)
{
	TRACE("Enter GetWindow\n");
	return pGetWindow(hwnd, rel);
}

extern WINAPI void wine32a_GetWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindow") "\n"
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

extern WINAPI BOOL wine32b_ShowOwnedPopups(HWND owner, BOOL fShow)
{
	TRACE("Enter ShowOwnedPopups\n");
	return pShowOwnedPopups(owner, fShow);
}

extern WINAPI void wine32a_ShowOwnedPopups(void);
__ASM_GLOBAL_FUNC(wine32a_ShowOwnedPopups,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowOwnedPopups") "\n"
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

extern WINAPI HWND wine32b_GetLastActivePopup(HWND hwnd)
{
	TRACE("Enter GetLastActivePopup\n");
	return pGetLastActivePopup(hwnd);
}

extern WINAPI void wine32a_GetLastActivePopup(void);
__ASM_GLOBAL_FUNC(wine32a_GetLastActivePopup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLastActivePopup") "\n"
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

extern WINAPI BOOL wine32b_EnumWindows(WNDENUMPROC lpEnumFunc, LPARAM lParam)
{
	TRACE("Enter EnumWindows\n");
	return pEnumWindows(lpEnumFunc, lParam);
}

extern WINAPI void wine32a_EnumWindows(void);
__ASM_GLOBAL_FUNC(wine32a_EnumWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumWindows") "\n"
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

extern WINAPI BOOL wine32b_EnumThreadWindows(DWORD id, WNDENUMPROC func, LPARAM lParam)
{
	TRACE("Enter EnumThreadWindows\n");
	return pEnumThreadWindows(id, func, lParam);
}

extern WINAPI void wine32a_EnumThreadWindows(void);
__ASM_GLOBAL_FUNC(wine32a_EnumThreadWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumThreadWindows") "\n"
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

extern WINAPI BOOL wine32b_EnumDesktopWindows(HDESK desktop, WNDENUMPROC func, LPARAM lparam)
{
	TRACE("Enter EnumDesktopWindows\n");
	return pEnumDesktopWindows(desktop, func, lparam);
}

extern WINAPI void wine32a_EnumDesktopWindows(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDesktopWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDesktopWindows") "\n"
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

extern WINAPI BOOL wine32b_EnumChildWindows(HWND parent, WNDENUMPROC func, LPARAM lParam)
{
	TRACE("Enter EnumChildWindows\n");
	return pEnumChildWindows(parent, func, lParam);
}

extern WINAPI void wine32a_EnumChildWindows(void);
__ASM_GLOBAL_FUNC(wine32a_EnumChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumChildWindows") "\n"
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

extern WINAPI BOOL wine32b_AnyPopup(void)
{
	TRACE("Enter AnyPopup\n");
	return pAnyPopup();
}

extern WINAPI void wine32a_AnyPopup(void);
__ASM_GLOBAL_FUNC(wine32a_AnyPopup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AnyPopup") "\n"
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

extern WINAPI BOOL wine32b_FlashWindow(HWND hWnd, BOOL bInvert)
{
	TRACE("Enter FlashWindow\n");
	return pFlashWindow(hWnd, bInvert);
}

extern WINAPI void wine32a_FlashWindow(void);
__ASM_GLOBAL_FUNC(wine32a_FlashWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlashWindow") "\n"
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

extern WINAPI BOOL wine32b_FlashWindowEx(PFLASHWINFO pfinfo)
{
	TRACE("Enter FlashWindowEx\n");
	return pFlashWindowEx(pfinfo);
}

extern WINAPI void wine32a_FlashWindowEx(void);
__ASM_GLOBAL_FUNC(wine32a_FlashWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlashWindowEx") "\n"
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

extern WINAPI DWORD wine32b_GetWindowContextHelpId(HWND hwnd)
{
	TRACE("Enter GetWindowContextHelpId\n");
	return pGetWindowContextHelpId(hwnd);
}

extern WINAPI void wine32a_GetWindowContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowContextHelpId") "\n"
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

extern WINAPI BOOL wine32b_SetWindowContextHelpId(HWND hwnd, DWORD id)
{
	TRACE("Enter SetWindowContextHelpId\n");
	return pSetWindowContextHelpId(hwnd, id);
}

extern WINAPI void wine32a_SetWindowContextHelpId(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowContextHelpId") "\n"
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

extern WINAPI BOOL wine32b_DragDetect(HWND hWnd, POINT pt)
{
	TRACE("Enter DragDetect\n");
	return pDragDetect(hWnd, pt);
}

extern WINAPI void wine32a_DragDetect(void);
__ASM_GLOBAL_FUNC(wine32a_DragDetect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DragDetect") "\n"
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

extern WINAPI UINT wine32b_GetWindowModuleFileNameA(HWND hwnd, LPSTR module, UINT size)
{
	TRACE("Enter GetWindowModuleFileNameA\n");
	return pGetWindowModuleFileNameA(hwnd, module, size);
}

extern WINAPI void wine32a_GetWindowModuleFileNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowModuleFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowModuleFileNameA") "\n"
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

extern WINAPI UINT wine32b_GetWindowModuleFileNameW(HWND hwnd, LPWSTR module, UINT size)
{
	TRACE("Enter GetWindowModuleFileNameW\n");
	return pGetWindowModuleFileNameW(hwnd, module, size);
}

extern WINAPI void wine32a_GetWindowModuleFileNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowModuleFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowModuleFileNameW") "\n"
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

extern WINAPI BOOL wine32b_GetWindowInfo(HWND hwnd, PWINDOWINFO pwi)
{
	TRACE("Enter GetWindowInfo\n");
	return pGetWindowInfo(hwnd, pwi);
}

extern WINAPI void wine32a_GetWindowInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowInfo") "\n"
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

extern WINAPI BOOL wine32b_SwitchDesktop(HDESK hDesktop)
{
	TRACE("Enter SwitchDesktop\n");
	return pSwitchDesktop(hDesktop);
}

extern WINAPI void wine32a_SwitchDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_SwitchDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SwitchDesktop") "\n"
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

extern WINAPI BOOL wine32b___wine_set_pixel_format(HWND hwnd, int format)
{
	TRACE("Enter __wine_set_pixel_format\n");
	return p__wine_set_pixel_format(hwnd, format);
}

extern WINAPI void wine32a___wine_set_pixel_format(void);
__ASM_GLOBAL_FUNC(wine32a___wine_set_pixel_format,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_set_pixel_format") "\n"
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

extern WINAPI BOOL wine32b_SetLayeredWindowAttributes(HWND hwnd, COLORREF key, BYTE alpha, DWORD flags)
{
	TRACE("Enter SetLayeredWindowAttributes\n");
	return pSetLayeredWindowAttributes(hwnd, key, alpha, flags);
}

extern WINAPI void wine32a_SetLayeredWindowAttributes(void);
__ASM_GLOBAL_FUNC(wine32a_SetLayeredWindowAttributes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLayeredWindowAttributes") "\n"
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

extern WINAPI BOOL wine32b_GetLayeredWindowAttributes(HWND hwnd, COLORREF * key, BYTE * alpha, DWORD * flags)
{
	TRACE("Enter GetLayeredWindowAttributes\n");
	return pGetLayeredWindowAttributes(hwnd, key, alpha, flags);
}

extern WINAPI void wine32a_GetLayeredWindowAttributes(void);
__ASM_GLOBAL_FUNC(wine32a_GetLayeredWindowAttributes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLayeredWindowAttributes") "\n"
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

extern WINAPI BOOL wine32b_UpdateLayeredWindowIndirect(HWND hwnd, const UPDATELAYEREDWINDOWINFO * info)
{
	TRACE("Enter UpdateLayeredWindowIndirect\n");
	return pUpdateLayeredWindowIndirect(hwnd, info);
}

extern WINAPI void wine32a_UpdateLayeredWindowIndirect(void);
__ASM_GLOBAL_FUNC(wine32a_UpdateLayeredWindowIndirect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UpdateLayeredWindowIndirect") "\n"
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

extern WINAPI BOOL wine32b_UpdateLayeredWindow(HWND hwnd, HDC hdcDst, POINT * pptDst, SIZE * psize, HDC hdcSrc, POINT * pptSrc, COLORREF crKey, BLENDFUNCTION * pblend, DWORD flags)
{
	TRACE("Enter UpdateLayeredWindow\n");
	return pUpdateLayeredWindow(hwnd, hdcDst, pptDst, psize, hdcSrc, pptSrc, crKey, pblend, flags);
}

extern WINAPI void wine32a_UpdateLayeredWindow(void);
__ASM_GLOBAL_FUNC(wine32a_UpdateLayeredWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UpdateLayeredWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessDefaultLayout(DWORD * layout)
{
	TRACE("Enter GetProcessDefaultLayout\n");
	return pGetProcessDefaultLayout(layout);
}

extern WINAPI void wine32a_GetProcessDefaultLayout(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessDefaultLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessDefaultLayout") "\n"
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

extern WINAPI BOOL wine32b_SetProcessDefaultLayout(DWORD layout)
{
	TRACE("Enter SetProcessDefaultLayout\n");
	return pSetProcessDefaultLayout(layout);
}

extern WINAPI void wine32a_SetProcessDefaultLayout(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessDefaultLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessDefaultLayout") "\n"
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

extern WINAPI LONG_PTR wine32b_GetWindowLongPtrW(HWND hwnd, INT offset)
{
	TRACE("Enter GetWindowLongPtrW\n");
	return pGetWindowLongPtrW(hwnd, offset);
}

extern WINAPI void wine32a_GetWindowLongPtrW(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowLongPtrW") "\n"
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

extern WINAPI LONG_PTR wine32b_GetWindowLongPtrA(HWND hwnd, INT offset)
{
	TRACE("Enter GetWindowLongPtrA\n");
	return pGetWindowLongPtrA(hwnd, offset);
}

extern WINAPI void wine32a_GetWindowLongPtrA(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowLongPtrA") "\n"
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

extern WINAPI LONG_PTR wine32b_SetWindowLongPtrW(HWND hwnd, INT offset, LONG_PTR newval)
{
	TRACE("Enter SetWindowLongPtrW\n");
	return pSetWindowLongPtrW(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetWindowLongPtrW(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowLongPtrW") "\n"
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

extern WINAPI LONG_PTR wine32b_SetWindowLongPtrA(HWND hwnd, INT offset, LONG_PTR newval)
{
	TRACE("Enter SetWindowLongPtrA\n");
	return pSetWindowLongPtrA(hwnd, offset, newval);
}

extern WINAPI void wine32a_SetWindowLongPtrA(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowLongPtrA") "\n"
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

extern WINAPI BOOL wine32b_RegisterTouchWindow(HWND hwnd, ULONG flags)
{
	TRACE("Enter RegisterTouchWindow\n");
	return pRegisterTouchWindow(hwnd, flags);
}

extern WINAPI void wine32a_RegisterTouchWindow(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterTouchWindow") "\n"
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

extern WINAPI BOOL wine32b_UnregisterTouchWindow(HWND hwnd)
{
	TRACE("Enter UnregisterTouchWindow\n");
	return pUnregisterTouchWindow(hwnd);
}

extern WINAPI void wine32a_UnregisterTouchWindow(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterTouchWindow") "\n"
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

extern WINAPI BOOL wine32b_CloseTouchInputHandle(HTOUCHINPUT handle)
{
	TRACE("Enter CloseTouchInputHandle\n");
	return pCloseTouchInputHandle(handle);
}

extern WINAPI void wine32a_CloseTouchInputHandle(void);
__ASM_GLOBAL_FUNC(wine32a_CloseTouchInputHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseTouchInputHandle") "\n"
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

extern WINAPI BOOL wine32b_GetTouchInputInfo(HTOUCHINPUT handle, UINT count, TOUCHINPUT * ptr, int size)
{
	TRACE("Enter GetTouchInputInfo\n");
	return pGetTouchInputInfo(handle, count, ptr, size);
}

extern WINAPI void wine32a_GetTouchInputInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetTouchInputInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTouchInputInfo") "\n"
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

extern WINAPI BOOL wine32b_GetGestureInfo(HGESTUREINFO handle, PGESTUREINFO ptr)
{
	TRACE("Enter GetGestureInfo\n");
	return pGetGestureInfo(handle, ptr);
}

extern WINAPI void wine32a_GetGestureInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetGestureInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGestureInfo") "\n"
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

extern WINAPI BOOL wine32b_GetWindowDisplayAffinity(HWND hwnd, DWORD * affinity)
{
	TRACE("Enter GetWindowDisplayAffinity\n");
	return pGetWindowDisplayAffinity(hwnd, affinity);
}

extern WINAPI void wine32a_GetWindowDisplayAffinity(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowDisplayAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowDisplayAffinity") "\n"
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

extern WINAPI BOOL wine32b_SetWindowDisplayAffinity(HWND hwnd, DWORD affinity)
{
	TRACE("Enter SetWindowDisplayAffinity\n");
	return pSetWindowDisplayAffinity(hwnd, affinity);
}

extern WINAPI void wine32a_SetWindowDisplayAffinity(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowDisplayAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowDisplayAffinity") "\n"
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

extern WINAPI BOOL wine32b_SetWindowCompositionAttribute(HWND hwnd, void * data)
{
	TRACE("Enter SetWindowCompositionAttribute\n");
	return pSetWindowCompositionAttribute(hwnd, data);
}

extern WINAPI void wine32a_SetWindowCompositionAttribute(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowCompositionAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowCompositionAttribute") "\n"
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

static WINAPI BOOL (*pWinHelpA)(HWND hWnd, LPCSTR lpHelpFile, UINT wCommand, ULONG_PTR dwData);
static WINAPI BOOL (*pWinHelpW)(HWND hWnd, LPCWSTR helpFile, UINT command, ULONG_PTR dwData);

extern WINAPI BOOL wine32b_WinHelpA(HWND hWnd, LPCSTR lpHelpFile, UINT wCommand, ULONG_PTR dwData)
{
	TRACE("Enter WinHelpA\n");
	return pWinHelpA(hWnd, lpHelpFile, wCommand, dwData);
}

extern WINAPI void wine32a_WinHelpA(void);
__ASM_GLOBAL_FUNC(wine32a_WinHelpA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinHelpA") "\n"
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

extern WINAPI BOOL wine32b_WinHelpW(HWND hWnd, LPCWSTR helpFile, UINT command, ULONG_PTR dwData)
{
	TRACE("Enter WinHelpW\n");
	return pWinHelpW(hWnd, helpFile, command, dwData);
}

extern WINAPI void wine32a_WinHelpW(void);
__ASM_GLOBAL_FUNC(wine32a_WinHelpW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinHelpW") "\n"
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

static WINAPI void (*pSwitchToThisWindow)(HWND hwnd, BOOL alt_tab);
static WINAPI BOOL (*pGetWindowRect)(HWND hwnd, LPRECT rect);
static WINAPI INT (*pGetWindowRgn)(HWND hwnd, HRGN hrgn);
static WINAPI INT (*pGetWindowRgnBox)(HWND hwnd, LPRECT prect);
static WINAPI INT (*pSetWindowRgn)(HWND hwnd, HRGN hrgn, BOOL bRedraw);
static WINAPI BOOL (*pGetClientRect)(HWND hwnd, LPRECT rect);
static WINAPI HWND (*pWindowFromPoint)(POINT pt);
static WINAPI HWND (*pChildWindowFromPoint)(HWND hwndParent, POINT pt);
static WINAPI HWND (*pRealChildWindowFromPoint)(HWND hwndParent, POINT pt);
static WINAPI HWND (*pChildWindowFromPointEx)(HWND hwndParent, POINT pt, UINT uFlags);
static WINAPI INT (*pMapWindowPoints)(HWND hwndFrom, HWND hwndTo, LPPOINT lppt, UINT count);
static WINAPI BOOL (*pClientToScreen)(HWND hwnd, LPPOINT lppnt);
static WINAPI BOOL (*pScreenToClient)(HWND hwnd, LPPOINT lppnt);
static WINAPI BOOL (*pIsIconic)(HWND hWnd);
static WINAPI BOOL (*pIsZoomed)(HWND hWnd);
static WINAPI BOOL (*pAllowSetForegroundWindow)(DWORD procid);
static WINAPI BOOL (*pLockSetForegroundWindow)(UINT lockcode);
static WINAPI BOOL (*pBringWindowToTop)(HWND hwnd);
static WINAPI BOOL (*pMoveWindow)(HWND hwnd, INT x, INT y, INT cx, INT cy, BOOL repaint);
static WINAPI BOOL (*pShowWindowAsync)(HWND hwnd, INT cmd);
static WINAPI BOOL (*pShowWindow)(HWND hwnd, INT cmd);
static WINAPI UINT (*pGetInternalWindowPos)(HWND hwnd, LPRECT rectWnd, LPPOINT ptIcon);
static WINAPI BOOL (*pGetWindowPlacement)(HWND hwnd, WINDOWPLACEMENT * wndpl);
static WINAPI BOOL (*pSetWindowPlacement)(HWND hwnd, const WINDOWPLACEMENT * wpl);
static WINAPI BOOL (*pAnimateWindow)(HWND hwnd, DWORD dwTime, DWORD dwFlags);
static WINAPI void (*pSetInternalWindowPos)(HWND hwnd, UINT showCmd, LPRECT rect, LPPOINT pt);
static WINAPI BOOL (*pSetWindowPos)(HWND hwnd, HWND hwndInsertAfter, INT x, INT y, INT cx, INT cy, UINT flags);
static WINAPI HDWP (*pBeginDeferWindowPos)(INT count);
static WINAPI HDWP (*pDeferWindowPos)(HDWP hdwp, HWND hwnd, HWND hwndAfter, INT x, INT y, INT cx, INT cy, UINT flags);
static WINAPI BOOL (*pEndDeferWindowPos)(HDWP hdwp);
static WINAPI UINT (*pArrangeIconicWindows)(HWND parent);

extern WINAPI void wine32b_SwitchToThisWindow(HWND hwnd, BOOL alt_tab)
{
	TRACE("Enter SwitchToThisWindow\n");
	return pSwitchToThisWindow(hwnd, alt_tab);
}

extern WINAPI void wine32a_SwitchToThisWindow(void);
__ASM_GLOBAL_FUNC(wine32a_SwitchToThisWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SwitchToThisWindow") "\n"
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

extern WINAPI BOOL wine32b_GetWindowRect(HWND hwnd, LPRECT rect)
{
	TRACE("Enter GetWindowRect\n");
	return pGetWindowRect(hwnd, rect);
}

extern WINAPI void wine32a_GetWindowRect(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowRect") "\n"
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

extern WINAPI INT wine32b_GetWindowRgn(HWND hwnd, HRGN hrgn)
{
	TRACE("Enter GetWindowRgn\n");
	return pGetWindowRgn(hwnd, hrgn);
}

extern WINAPI void wine32a_GetWindowRgn(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowRgn") "\n"
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

extern WINAPI INT wine32b_GetWindowRgnBox(HWND hwnd, LPRECT prect)
{
	TRACE("Enter GetWindowRgnBox\n");
	return pGetWindowRgnBox(hwnd, prect);
}

extern WINAPI void wine32a_GetWindowRgnBox(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowRgnBox,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowRgnBox") "\n"
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

extern WINAPI INT wine32b_SetWindowRgn(HWND hwnd, HRGN hrgn, BOOL bRedraw)
{
	TRACE("Enter SetWindowRgn\n");
	return pSetWindowRgn(hwnd, hrgn, bRedraw);
}

extern WINAPI void wine32a_SetWindowRgn(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowRgn") "\n"
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

extern WINAPI BOOL wine32b_GetClientRect(HWND hwnd, LPRECT rect)
{
	TRACE("Enter GetClientRect\n");
	return pGetClientRect(hwnd, rect);
}

extern WINAPI void wine32a_GetClientRect(void);
__ASM_GLOBAL_FUNC(wine32a_GetClientRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetClientRect") "\n"
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

extern WINAPI HWND wine32b_WindowFromPoint(POINT pt)
{
	TRACE("Enter WindowFromPoint\n");
	return pWindowFromPoint(pt);
}

extern WINAPI void wine32a_WindowFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_WindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WindowFromPoint") "\n"
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

extern WINAPI HWND wine32b_ChildWindowFromPoint(HWND hwndParent, POINT pt)
{
	TRACE("Enter ChildWindowFromPoint\n");
	return pChildWindowFromPoint(hwndParent, pt);
}

extern WINAPI void wine32a_ChildWindowFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_ChildWindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChildWindowFromPoint") "\n"
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

extern WINAPI HWND wine32b_RealChildWindowFromPoint(HWND hwndParent, POINT pt)
{
	TRACE("Enter RealChildWindowFromPoint\n");
	return pRealChildWindowFromPoint(hwndParent, pt);
}

extern WINAPI void wine32a_RealChildWindowFromPoint(void);
__ASM_GLOBAL_FUNC(wine32a_RealChildWindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RealChildWindowFromPoint") "\n"
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

extern WINAPI HWND wine32b_ChildWindowFromPointEx(HWND hwndParent, POINT pt, UINT uFlags)
{
	TRACE("Enter ChildWindowFromPointEx\n");
	return pChildWindowFromPointEx(hwndParent, pt, uFlags);
}

extern WINAPI void wine32a_ChildWindowFromPointEx(void);
__ASM_GLOBAL_FUNC(wine32a_ChildWindowFromPointEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ChildWindowFromPointEx") "\n"
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

extern WINAPI INT wine32b_MapWindowPoints(HWND hwndFrom, HWND hwndTo, LPPOINT lppt, UINT count)
{
	TRACE("Enter MapWindowPoints\n");
	return pMapWindowPoints(hwndFrom, hwndTo, lppt, count);
}

extern WINAPI void wine32a_MapWindowPoints(void);
__ASM_GLOBAL_FUNC(wine32a_MapWindowPoints,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapWindowPoints") "\n"
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

extern WINAPI BOOL wine32b_ClientToScreen(HWND hwnd, LPPOINT lppnt)
{
	TRACE("Enter ClientToScreen\n");
	return pClientToScreen(hwnd, lppnt);
}

extern WINAPI void wine32a_ClientToScreen(void);
__ASM_GLOBAL_FUNC(wine32a_ClientToScreen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClientToScreen") "\n"
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

extern WINAPI BOOL wine32b_ScreenToClient(HWND hwnd, LPPOINT lppnt)
{
	TRACE("Enter ScreenToClient\n");
	return pScreenToClient(hwnd, lppnt);
}

extern WINAPI void wine32a_ScreenToClient(void);
__ASM_GLOBAL_FUNC(wine32a_ScreenToClient,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScreenToClient") "\n"
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

extern WINAPI BOOL wine32b_IsIconic(HWND hWnd)
{
	TRACE("Enter IsIconic\n");
	return pIsIconic(hWnd);
}

extern WINAPI void wine32a_IsIconic(void);
__ASM_GLOBAL_FUNC(wine32a_IsIconic,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsIconic") "\n"
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

extern WINAPI BOOL wine32b_IsZoomed(HWND hWnd)
{
	TRACE("Enter IsZoomed\n");
	return pIsZoomed(hWnd);
}

extern WINAPI void wine32a_IsZoomed(void);
__ASM_GLOBAL_FUNC(wine32a_IsZoomed,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsZoomed") "\n"
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

extern WINAPI BOOL wine32b_AllowSetForegroundWindow(DWORD procid)
{
	TRACE("Enter AllowSetForegroundWindow\n");
	return pAllowSetForegroundWindow(procid);
}

extern WINAPI void wine32a_AllowSetForegroundWindow(void);
__ASM_GLOBAL_FUNC(wine32a_AllowSetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AllowSetForegroundWindow") "\n"
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

extern WINAPI BOOL wine32b_LockSetForegroundWindow(UINT lockcode)
{
	TRACE("Enter LockSetForegroundWindow\n");
	return pLockSetForegroundWindow(lockcode);
}

extern WINAPI void wine32a_LockSetForegroundWindow(void);
__ASM_GLOBAL_FUNC(wine32a_LockSetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LockSetForegroundWindow") "\n"
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

extern WINAPI BOOL wine32b_BringWindowToTop(HWND hwnd)
{
	TRACE("Enter BringWindowToTop\n");
	return pBringWindowToTop(hwnd);
}

extern WINAPI void wine32a_BringWindowToTop(void);
__ASM_GLOBAL_FUNC(wine32a_BringWindowToTop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BringWindowToTop") "\n"
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

extern WINAPI BOOL wine32b_MoveWindow(HWND hwnd, INT x, INT y, INT cx, INT cy, BOOL repaint)
{
	TRACE("Enter MoveWindow\n");
	return pMoveWindow(hwnd, x, y, cx, cy, repaint);
}

extern WINAPI void wine32a_MoveWindow(void);
__ASM_GLOBAL_FUNC(wine32a_MoveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveWindow") "\n"
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

extern WINAPI BOOL wine32b_ShowWindowAsync(HWND hwnd, INT cmd)
{
	TRACE("Enter ShowWindowAsync\n");
	return pShowWindowAsync(hwnd, cmd);
}

extern WINAPI void wine32a_ShowWindowAsync(void);
__ASM_GLOBAL_FUNC(wine32a_ShowWindowAsync,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowWindowAsync") "\n"
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

extern WINAPI BOOL wine32b_ShowWindow(HWND hwnd, INT cmd)
{
	TRACE("Enter ShowWindow\n");
	return pShowWindow(hwnd, cmd);
}

extern WINAPI void wine32a_ShowWindow(void);
__ASM_GLOBAL_FUNC(wine32a_ShowWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ShowWindow") "\n"
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

extern WINAPI UINT wine32b_GetInternalWindowPos(HWND hwnd, LPRECT rectWnd, LPPOINT ptIcon)
{
	TRACE("Enter GetInternalWindowPos\n");
	return pGetInternalWindowPos(hwnd, rectWnd, ptIcon);
}

extern WINAPI void wine32a_GetInternalWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_GetInternalWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetInternalWindowPos") "\n"
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

extern WINAPI BOOL wine32b_GetWindowPlacement(HWND hwnd, WINDOWPLACEMENT * wndpl)
{
	TRACE("Enter GetWindowPlacement\n");
	return pGetWindowPlacement(hwnd, wndpl);
}

extern WINAPI void wine32a_GetWindowPlacement(void);
__ASM_GLOBAL_FUNC(wine32a_GetWindowPlacement,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWindowPlacement") "\n"
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

extern WINAPI BOOL wine32b_SetWindowPlacement(HWND hwnd, const WINDOWPLACEMENT * wpl)
{
	TRACE("Enter SetWindowPlacement\n");
	return pSetWindowPlacement(hwnd, wpl);
}

extern WINAPI void wine32a_SetWindowPlacement(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowPlacement,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowPlacement") "\n"
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

extern WINAPI BOOL wine32b_AnimateWindow(HWND hwnd, DWORD dwTime, DWORD dwFlags)
{
	TRACE("Enter AnimateWindow\n");
	return pAnimateWindow(hwnd, dwTime, dwFlags);
}

extern WINAPI void wine32a_AnimateWindow(void);
__ASM_GLOBAL_FUNC(wine32a_AnimateWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AnimateWindow") "\n"
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

extern WINAPI void wine32b_SetInternalWindowPos(HWND hwnd, UINT showCmd, LPRECT rect, LPPOINT pt)
{
	TRACE("Enter SetInternalWindowPos\n");
	return pSetInternalWindowPos(hwnd, showCmd, rect, pt);
}

extern WINAPI void wine32a_SetInternalWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetInternalWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetInternalWindowPos") "\n"
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

extern WINAPI BOOL wine32b_SetWindowPos(HWND hwnd, HWND hwndInsertAfter, INT x, INT y, INT cx, INT cy, UINT flags)
{
	TRACE("Enter SetWindowPos\n");
	return pSetWindowPos(hwnd, hwndInsertAfter, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_SetWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_SetWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetWindowPos") "\n"
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

extern WINAPI HDWP wine32b_BeginDeferWindowPos(INT count)
{
	TRACE("Enter BeginDeferWindowPos\n");
	return pBeginDeferWindowPos(count);
}

extern WINAPI void wine32a_BeginDeferWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_BeginDeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BeginDeferWindowPos") "\n"
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

extern WINAPI HDWP wine32b_DeferWindowPos(HDWP hdwp, HWND hwnd, HWND hwndAfter, INT x, INT y, INT cx, INT cy, UINT flags)
{
	TRACE("Enter DeferWindowPos\n");
	return pDeferWindowPos(hdwp, hwnd, hwndAfter, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_DeferWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_DeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeferWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EndDeferWindowPos(HDWP hdwp)
{
	TRACE("Enter EndDeferWindowPos\n");
	return pEndDeferWindowPos(hdwp);
}

extern WINAPI void wine32a_EndDeferWindowPos(void);
__ASM_GLOBAL_FUNC(wine32a_EndDeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndDeferWindowPos") "\n"
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

extern WINAPI UINT wine32b_ArrangeIconicWindows(HWND parent)
{
	TRACE("Enter ArrangeIconicWindows\n");
	return pArrangeIconicWindows(parent);
}

extern WINAPI void wine32a_ArrangeIconicWindows(void);
__ASM_GLOBAL_FUNC(wine32a_ArrangeIconicWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ArrangeIconicWindows") "\n"
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

static WINAPI LRESULT (*pCallWindowProcA)(WNDPROC func, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI LRESULT (*pCallWindowProcW)(WNDPROC func, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
static WINAPI void (*pUserRegisterWowHandlers)(const struct wow_handlers16 * new, struct wow_handlers32 * orig);

extern WINAPI LRESULT wine32b_CallWindowProcA(WNDPROC func, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter CallWindowProcA\n");
	return pCallWindowProcA(func, hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_CallWindowProcA(void);
__ASM_GLOBAL_FUNC(wine32a_CallWindowProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallWindowProcA") "\n"
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

extern WINAPI LRESULT wine32b_CallWindowProcW(WNDPROC func, HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	TRACE("Enter CallWindowProcW\n");
	return pCallWindowProcW(func, hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_CallWindowProcW(void);
__ASM_GLOBAL_FUNC(wine32a_CallWindowProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallWindowProcW") "\n"
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

extern WINAPI void wine32b_UserRegisterWowHandlers(const struct wow_handlers16 * new, struct wow_handlers32 * orig)
{
	TRACE("Enter UserRegisterWowHandlers\n");
	return pUserRegisterWowHandlers(new, orig);
}

extern WINAPI void wine32a_UserRegisterWowHandlers(void);
__ASM_GLOBAL_FUNC(wine32a_UserRegisterWowHandlers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UserRegisterWowHandlers") "\n"
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

static WINAPI HWINSTA (*pCreateWindowStationA)(LPCSTR name, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa);
static WINAPI HWINSTA (*pCreateWindowStationW)(LPCWSTR name, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa);
static WINAPI HWINSTA (*pOpenWindowStationA)(LPCSTR name, BOOL inherit, ACCESS_MASK access);
static WINAPI HWINSTA (*pOpenWindowStationW)(LPCWSTR name, BOOL inherit, ACCESS_MASK access);
static WINAPI BOOL (*pCloseWindowStation)(HWINSTA handle);
static WINAPI HWINSTA (*pGetProcessWindowStation)(void);
static WINAPI BOOL (*pSetProcessWindowStation)(HWINSTA handle);
static WINAPI BOOL (*pEnumWindowStationsA)(WINSTAENUMPROCA func, LPARAM lparam);
static WINAPI BOOL (*pEnumWindowStationsW)(WINSTAENUMPROCW func, LPARAM lparam);
static WINAPI HDESK (*pCreateDesktopA)(LPCSTR name, LPCSTR device, LPDEVMODEA devmode, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa);
static WINAPI HDESK (*pCreateDesktopW)(LPCWSTR name, LPCWSTR device, LPDEVMODEW devmode, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa);
static WINAPI HDESK (*pOpenDesktopA)(LPCSTR name, DWORD flags, BOOL inherit, ACCESS_MASK access);
static WINAPI HDESK (*pOpenDesktopW)(LPCWSTR name, DWORD flags, BOOL inherit, ACCESS_MASK access);
static WINAPI BOOL (*pCloseDesktop)(HDESK handle);
static WINAPI HDESK (*pGetThreadDesktop)(DWORD thread);
static WINAPI BOOL (*pSetThreadDesktop)(HDESK handle);
static WINAPI BOOL (*pEnumDesktopsA)(HWINSTA winsta, DESKTOPENUMPROCA func, LPARAM lparam);
static WINAPI BOOL (*pEnumDesktopsW)(HWINSTA winsta, DESKTOPENUMPROCW func, LPARAM lparam);
static WINAPI HDESK (*pOpenInputDesktop)(DWORD flags, BOOL inherit, ACCESS_MASK access);
static WINAPI BOOL (*pGetUserObjectInformationA)(HANDLE handle, INT index, LPVOID info, DWORD len, LPDWORD needed);
static WINAPI BOOL (*pGetUserObjectInformationW)(HANDLE handle, INT index, LPVOID info, DWORD len, LPDWORD needed);
static WINAPI BOOL (*pSetUserObjectInformationA)(HANDLE handle, INT index, LPVOID info, DWORD len);
static WINAPI BOOL (*pSetUserObjectInformationW)(HANDLE handle, INT index, LPVOID info, DWORD len);
static WINAPI BOOL (*pGetUserObjectSecurity)(HANDLE handle, PSECURITY_INFORMATION info, PSECURITY_DESCRIPTOR sid, DWORD len, LPDWORD needed);
static WINAPI BOOL (*pSetUserObjectSecurity)(HANDLE handle, PSECURITY_INFORMATION info, PSECURITY_DESCRIPTOR sid);

extern WINAPI HWINSTA wine32b_CreateWindowStationA(LPCSTR name, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateWindowStationA\n");
	return pCreateWindowStationA(name, flags, access, sa);
}

extern WINAPI void wine32a_CreateWindowStationA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWindowStationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWindowStationA") "\n"
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

extern WINAPI HWINSTA wine32b_CreateWindowStationW(LPCWSTR name, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateWindowStationW\n");
	return pCreateWindowStationW(name, flags, access, sa);
}

extern WINAPI void wine32a_CreateWindowStationW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWindowStationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWindowStationW") "\n"
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

extern WINAPI HWINSTA wine32b_OpenWindowStationA(LPCSTR name, BOOL inherit, ACCESS_MASK access)
{
	TRACE("Enter OpenWindowStationA\n");
	return pOpenWindowStationA(name, inherit, access);
}

extern WINAPI void wine32a_OpenWindowStationA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenWindowStationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenWindowStationA") "\n"
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

extern WINAPI HWINSTA wine32b_OpenWindowStationW(LPCWSTR name, BOOL inherit, ACCESS_MASK access)
{
	TRACE("Enter OpenWindowStationW\n");
	return pOpenWindowStationW(name, inherit, access);
}

extern WINAPI void wine32a_OpenWindowStationW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenWindowStationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenWindowStationW") "\n"
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

extern WINAPI BOOL wine32b_CloseWindowStation(HWINSTA handle)
{
	TRACE("Enter CloseWindowStation\n");
	return pCloseWindowStation(handle);
}

extern WINAPI void wine32a_CloseWindowStation(void);
__ASM_GLOBAL_FUNC(wine32a_CloseWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseWindowStation") "\n"
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

extern WINAPI HWINSTA wine32b_GetProcessWindowStation(void)
{
	TRACE("Enter GetProcessWindowStation\n");
	return pGetProcessWindowStation();
}

extern WINAPI void wine32a_GetProcessWindowStation(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessWindowStation") "\n"
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

extern WINAPI BOOL wine32b_SetProcessWindowStation(HWINSTA handle)
{
	TRACE("Enter SetProcessWindowStation\n");
	return pSetProcessWindowStation(handle);
}

extern WINAPI void wine32a_SetProcessWindowStation(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessWindowStation") "\n"
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

extern WINAPI BOOL wine32b_EnumWindowStationsA(WINSTAENUMPROCA func, LPARAM lparam)
{
	TRACE("Enter EnumWindowStationsA\n");
	return pEnumWindowStationsA(func, lparam);
}

extern WINAPI void wine32a_EnumWindowStationsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumWindowStationsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumWindowStationsA") "\n"
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

extern WINAPI BOOL wine32b_EnumWindowStationsW(WINSTAENUMPROCW func, LPARAM lparam)
{
	TRACE("Enter EnumWindowStationsW\n");
	return pEnumWindowStationsW(func, lparam);
}

extern WINAPI void wine32a_EnumWindowStationsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumWindowStationsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumWindowStationsW") "\n"
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

extern WINAPI HDESK wine32b_CreateDesktopA(LPCSTR name, LPCSTR device, LPDEVMODEA devmode, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateDesktopA\n");
	return pCreateDesktopA(name, device, devmode, flags, access, sa);
}

extern WINAPI void wine32a_CreateDesktopA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDesktopA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDesktopA") "\n"
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

extern WINAPI HDESK wine32b_CreateDesktopW(LPCWSTR name, LPCWSTR device, LPDEVMODEW devmode, DWORD flags, ACCESS_MASK access, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateDesktopW\n");
	return pCreateDesktopW(name, device, devmode, flags, access, sa);
}

extern WINAPI void wine32a_CreateDesktopW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDesktopW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDesktopW") "\n"
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

extern WINAPI HDESK wine32b_OpenDesktopA(LPCSTR name, DWORD flags, BOOL inherit, ACCESS_MASK access)
{
	TRACE("Enter OpenDesktopA\n");
	return pOpenDesktopA(name, flags, inherit, access);
}

extern WINAPI void wine32a_OpenDesktopA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenDesktopA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenDesktopA") "\n"
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

extern WINAPI HDESK wine32b_OpenDesktopW(LPCWSTR name, DWORD flags, BOOL inherit, ACCESS_MASK access)
{
	TRACE("Enter OpenDesktopW\n");
	return pOpenDesktopW(name, flags, inherit, access);
}

extern WINAPI void wine32a_OpenDesktopW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenDesktopW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenDesktopW") "\n"
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

extern WINAPI BOOL wine32b_CloseDesktop(HDESK handle)
{
	TRACE("Enter CloseDesktop\n");
	return pCloseDesktop(handle);
}

extern WINAPI void wine32a_CloseDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_CloseDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseDesktop") "\n"
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

extern WINAPI HDESK wine32b_GetThreadDesktop(DWORD thread)
{
	TRACE("Enter GetThreadDesktop\n");
	return pGetThreadDesktop(thread);
}

extern WINAPI void wine32a_GetThreadDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_GetThreadDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetThreadDesktop") "\n"
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

extern WINAPI BOOL wine32b_SetThreadDesktop(HDESK handle)
{
	TRACE("Enter SetThreadDesktop\n");
	return pSetThreadDesktop(handle);
}

extern WINAPI void wine32a_SetThreadDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadDesktop") "\n"
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

extern WINAPI BOOL wine32b_EnumDesktopsA(HWINSTA winsta, DESKTOPENUMPROCA func, LPARAM lparam)
{
	TRACE("Enter EnumDesktopsA\n");
	return pEnumDesktopsA(winsta, func, lparam);
}

extern WINAPI void wine32a_EnumDesktopsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDesktopsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDesktopsA") "\n"
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

extern WINAPI BOOL wine32b_EnumDesktopsW(HWINSTA winsta, DESKTOPENUMPROCW func, LPARAM lparam)
{
	TRACE("Enter EnumDesktopsW\n");
	return pEnumDesktopsW(winsta, func, lparam);
}

extern WINAPI void wine32a_EnumDesktopsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDesktopsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDesktopsW") "\n"
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

extern WINAPI HDESK wine32b_OpenInputDesktop(DWORD flags, BOOL inherit, ACCESS_MASK access)
{
	TRACE("Enter OpenInputDesktop\n");
	return pOpenInputDesktop(flags, inherit, access);
}

extern WINAPI void wine32a_OpenInputDesktop(void);
__ASM_GLOBAL_FUNC(wine32a_OpenInputDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenInputDesktop") "\n"
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

extern WINAPI BOOL wine32b_GetUserObjectInformationA(HANDLE handle, INT index, LPVOID info, DWORD len, LPDWORD needed)
{
	TRACE("Enter GetUserObjectInformationA\n");
	return pGetUserObjectInformationA(handle, index, info, len, needed);
}

extern WINAPI void wine32a_GetUserObjectInformationA(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserObjectInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserObjectInformationA") "\n"
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

extern WINAPI BOOL wine32b_GetUserObjectInformationW(HANDLE handle, INT index, LPVOID info, DWORD len, LPDWORD needed)
{
	TRACE("Enter GetUserObjectInformationW\n");
	return pGetUserObjectInformationW(handle, index, info, len, needed);
}

extern WINAPI void wine32a_GetUserObjectInformationW(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserObjectInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserObjectInformationW") "\n"
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

extern WINAPI BOOL wine32b_SetUserObjectInformationA(HANDLE handle, INT index, LPVOID info, DWORD len)
{
	TRACE("Enter SetUserObjectInformationA\n");
	return pSetUserObjectInformationA(handle, index, info, len);
}

extern WINAPI void wine32a_SetUserObjectInformationA(void);
__ASM_GLOBAL_FUNC(wine32a_SetUserObjectInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUserObjectInformationA") "\n"
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

extern WINAPI BOOL wine32b_SetUserObjectInformationW(HANDLE handle, INT index, LPVOID info, DWORD len)
{
	TRACE("Enter SetUserObjectInformationW\n");
	return pSetUserObjectInformationW(handle, index, info, len);
}

extern WINAPI void wine32a_SetUserObjectInformationW(void);
__ASM_GLOBAL_FUNC(wine32a_SetUserObjectInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUserObjectInformationW") "\n"
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

extern WINAPI BOOL wine32b_GetUserObjectSecurity(HANDLE handle, PSECURITY_INFORMATION info, PSECURITY_DESCRIPTOR sid, DWORD len, LPDWORD needed)
{
	TRACE("Enter GetUserObjectSecurity\n");
	return pGetUserObjectSecurity(handle, info, sid, len, needed);
}

extern WINAPI void wine32a_GetUserObjectSecurity(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserObjectSecurity") "\n"
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

extern WINAPI BOOL wine32b_SetUserObjectSecurity(HANDLE handle, PSECURITY_INFORMATION info, PSECURITY_DESCRIPTOR sid)
{
	TRACE("Enter SetUserObjectSecurity\n");
	return pSetUserObjectSecurity(handle, info, sid);
}

extern WINAPI void wine32a_SetUserObjectSecurity(void);
__ASM_GLOBAL_FUNC(wine32a_SetUserObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUserObjectSecurity") "\n"
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

static WINAPI INT (*pwvsprintfA)(LPSTR buffer, LPCSTR spec, __builtin_ms_va_list args);
static WINAPI INT (*pwvsprintfW)(LPWSTR buffer, LPCWSTR spec, __builtin_ms_va_list args);
static WINAPI INT (*pwsprintfA)(LPSTR buffer, LPCSTR spec);
static WINAPI INT (*pwsprintfW)(LPWSTR buffer, LPCWSTR spec);

extern WINAPI INT wine32b_wvsprintfA(LPSTR buffer, LPCSTR spec, __builtin_ms_va_list args)
{
	TRACE("Enter wvsprintfA\n");
	return pwvsprintfA(buffer, spec, args);
}

extern WINAPI void wine32a_wvsprintfA(void);
__ASM_GLOBAL_FUNC(wine32a_wvsprintfA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wvsprintfA") "\n"
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

extern WINAPI INT wine32b_wvsprintfW(LPWSTR buffer, LPCWSTR spec, __builtin_ms_va_list args)
{
	TRACE("Enter wvsprintfW\n");
	return pwvsprintfW(buffer, spec, args);
}

extern WINAPI void wine32a_wvsprintfW(void);
__ASM_GLOBAL_FUNC(wine32a_wvsprintfW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wvsprintfW") "\n"
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

extern WINAPI INT wine32b_wsprintfA(LPSTR buffer, LPCSTR spec)
{
	TRACE("Enter wsprintfA\n");
	return pwsprintfA(buffer, spec);
}

extern WINAPI void wine32a_wsprintfA(void);
__ASM_GLOBAL_FUNC(wine32a_wsprintfA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wsprintfA") "\n"
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

extern WINAPI INT wine32b_wsprintfW(LPWSTR buffer, LPCWSTR spec)
{
	TRACE("Enter wsprintfW\n");
	return pwsprintfW(buffer, spec);
}

extern WINAPI void wine32a_wsprintfW(void);
__ASM_GLOBAL_FUNC(wine32a_wsprintfW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wsprintfW") "\n"
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

static BOOL initialized = FALSE;

void wine_thunk_initialize_user32(void)
{
	HMODULE library = LoadLibraryA("user32.dll");
	pCreateCaret = (void *)GetProcAddress(library, "CreateCaret");
	pDestroyCaret = (void *)GetProcAddress(library, "DestroyCaret");
	pSetCaretPos = (void *)GetProcAddress(library, "SetCaretPos");
	pHideCaret = (void *)GetProcAddress(library, "HideCaret");
	pShowCaret = (void *)GetProcAddress(library, "ShowCaret");
	pGetCaretPos = (void *)GetProcAddress(library, "GetCaretPos");
	pSetCaretBlinkTime = (void *)GetProcAddress(library, "SetCaretBlinkTime");
	pGetCaretBlinkTime = (void *)GetProcAddress(library, "GetCaretBlinkTime");
	pRegisterClassA = (void *)GetProcAddress(library, "RegisterClassA");
	pRegisterClassW = (void *)GetProcAddress(library, "RegisterClassW");
	pRegisterClassExA = (void *)GetProcAddress(library, "RegisterClassExA");
	pRegisterClassExW = (void *)GetProcAddress(library, "RegisterClassExW");
	pUnregisterClassA = (void *)GetProcAddress(library, "UnregisterClassA");
	pUnregisterClassW = (void *)GetProcAddress(library, "UnregisterClassW");
	pGetClassWord = (void *)GetProcAddress(library, "GetClassWord");
	pGetClassLongW = (void *)GetProcAddress(library, "GetClassLongW");
	pGetClassLongA = (void *)GetProcAddress(library, "GetClassLongA");
	pSetClassWord = (void *)GetProcAddress(library, "SetClassWord");
	pSetClassLongW = (void *)GetProcAddress(library, "SetClassLongW");
	pSetClassLongA = (void *)GetProcAddress(library, "SetClassLongA");
	pGetClassNameA = (void *)GetProcAddress(library, "GetClassNameA");
	pGetClassNameW = (void *)GetProcAddress(library, "GetClassNameW");
	pRealGetWindowClassA = (void *)GetProcAddress(library, "RealGetWindowClassA");
	pRealGetWindowClassW = (void *)GetProcAddress(library, "RealGetWindowClassW");
	pGetClassInfoA = (void *)GetProcAddress(library, "GetClassInfoA");
	pGetClassInfoW = (void *)GetProcAddress(library, "GetClassInfoW");
	pGetClassInfoExA = (void *)GetProcAddress(library, "GetClassInfoExA");
	pGetClassInfoExW = (void *)GetProcAddress(library, "GetClassInfoExW");
	pGetClassLongPtrA = (void *)GetProcAddress(library, "GetClassLongPtrA");
	pGetClassLongPtrW = (void *)GetProcAddress(library, "GetClassLongPtrW");
	pSetClassLongPtrW = (void *)GetProcAddress(library, "SetClassLongPtrW");
	pSetClassLongPtrA = (void *)GetProcAddress(library, "SetClassLongPtrA");
	pRegisterClipboardFormatW = (void *)GetProcAddress(library, "RegisterClipboardFormatW");
	pRegisterClipboardFormatA = (void *)GetProcAddress(library, "RegisterClipboardFormatA");
	pGetClipboardFormatNameW = (void *)GetProcAddress(library, "GetClipboardFormatNameW");
	pGetClipboardFormatNameA = (void *)GetProcAddress(library, "GetClipboardFormatNameA");
	pOpenClipboard = (void *)GetProcAddress(library, "OpenClipboard");
	pCloseClipboard = (void *)GetProcAddress(library, "CloseClipboard");
	pEmptyClipboard = (void *)GetProcAddress(library, "EmptyClipboard");
	pGetClipboardOwner = (void *)GetProcAddress(library, "GetClipboardOwner");
	pGetOpenClipboardWindow = (void *)GetProcAddress(library, "GetOpenClipboardWindow");
	pSetClipboardViewer = (void *)GetProcAddress(library, "SetClipboardViewer");
	pGetClipboardViewer = (void *)GetProcAddress(library, "GetClipboardViewer");
	pChangeClipboardChain = (void *)GetProcAddress(library, "ChangeClipboardChain");
	pSetClipboardData = (void *)GetProcAddress(library, "SetClipboardData");
	pCountClipboardFormats = (void *)GetProcAddress(library, "CountClipboardFormats");
	pEnumClipboardFormats = (void *)GetProcAddress(library, "EnumClipboardFormats");
	pIsClipboardFormatAvailable = (void *)GetProcAddress(library, "IsClipboardFormatAvailable");
	pGetUpdatedClipboardFormats = (void *)GetProcAddress(library, "GetUpdatedClipboardFormats");
	pGetClipboardData = (void *)GetProcAddress(library, "GetClipboardData");
	pGetPriorityClipboardFormat = (void *)GetProcAddress(library, "GetPriorityClipboardFormat");
	pGetClipboardSequenceNumber = (void *)GetProcAddress(library, "GetClipboardSequenceNumber");
	pAddClipboardFormatListener = (void *)GetProcAddress(library, "AddClipboardFormatListener");
	pRemoveClipboardFormatListener = (void *)GetProcAddress(library, "RemoveClipboardFormatListener");
	pGetComboBoxInfo = (void *)GetProcAddress(library, "GetComboBoxInfo");
	pCreateIconFromResourceEx = (void *)GetProcAddress(library, "CreateIconFromResourceEx");
	pCreateIconFromResource = (void *)GetProcAddress(library, "CreateIconFromResource");
	pCreateCursor = (void *)GetProcAddress(library, "CreateCursor");
	pCreateIcon = (void *)GetProcAddress(library, "CreateIcon");
	pCopyIcon = (void *)GetProcAddress(library, "CopyIcon");
	pDestroyIcon = (void *)GetProcAddress(library, "DestroyIcon");
	pDestroyCursor = (void *)GetProcAddress(library, "DestroyCursor");
	pDrawIcon = (void *)GetProcAddress(library, "DrawIcon");
	pSetCursor = (void *)GetProcAddress(library, "SetCursor");
	pShowCursor = (void *)GetProcAddress(library, "ShowCursor");
	pGetCursor = (void *)GetProcAddress(library, "GetCursor");
	pClipCursor = (void *)GetProcAddress(library, "ClipCursor");
	pGetClipCursor = (void *)GetProcAddress(library, "GetClipCursor");
	pSetSystemCursor = (void *)GetProcAddress(library, "SetSystemCursor");
	pLookupIconIdFromDirectoryEx = (void *)GetProcAddress(library, "LookupIconIdFromDirectoryEx");
	pLookupIconIdFromDirectory = (void *)GetProcAddress(library, "LookupIconIdFromDirectory");
	pLoadCursorW = (void *)GetProcAddress(library, "LoadCursorW");
	pLoadCursorA = (void *)GetProcAddress(library, "LoadCursorA");
	pLoadCursorFromFileW = (void *)GetProcAddress(library, "LoadCursorFromFileW");
	pLoadCursorFromFileA = (void *)GetProcAddress(library, "LoadCursorFromFileA");
	pLoadIconW = (void *)GetProcAddress(library, "LoadIconW");
	pLoadIconA = (void *)GetProcAddress(library, "LoadIconA");
	pGetCursorFrameInfo = (void *)GetProcAddress(library, "GetCursorFrameInfo");
	pGetIconInfo = (void *)GetProcAddress(library, "GetIconInfo");
	pGetIconInfoExA = (void *)GetProcAddress(library, "GetIconInfoExA");
	pGetIconInfoExW = (void *)GetProcAddress(library, "GetIconInfoExW");
	pCreateIconIndirect = (void *)GetProcAddress(library, "CreateIconIndirect");
	pDrawIconEx = (void *)GetProcAddress(library, "DrawIconEx");
	pLoadImageA = (void *)GetProcAddress(library, "LoadImageA");
	pLoadImageW = (void *)GetProcAddress(library, "LoadImageW");
	pCopyImage = (void *)GetProcAddress(library, "CopyImage");
	pLoadBitmapW = (void *)GetProcAddress(library, "LoadBitmapW");
	pLoadBitmapA = (void *)GetProcAddress(library, "LoadBitmapA");
	pDdeConnectList = (void *)GetProcAddress(library, "DdeConnectList");
	pDdeQueryNextServer = (void *)GetProcAddress(library, "DdeQueryNextServer");
	pDdeDisconnectList = (void *)GetProcAddress(library, "DdeDisconnectList");
	pDdeConnect = (void *)GetProcAddress(library, "DdeConnect");
	pDdeReconnect = (void *)GetProcAddress(library, "DdeReconnect");
	pDdeClientTransaction = (void *)GetProcAddress(library, "DdeClientTransaction");
	pDdeAbandonTransaction = (void *)GetProcAddress(library, "DdeAbandonTransaction");
	pDdeDisconnect = (void *)GetProcAddress(library, "DdeDisconnect");
	pDdeImpersonateClient = (void *)GetProcAddress(library, "DdeImpersonateClient");
	pPackDDElParam = (void *)GetProcAddress(library, "PackDDElParam");
	pUnpackDDElParam = (void *)GetProcAddress(library, "UnpackDDElParam");
	pFreeDDElParam = (void *)GetProcAddress(library, "FreeDDElParam");
	pReuseDDElParam = (void *)GetProcAddress(library, "ReuseDDElParam");
	pImpersonateDdeClientWindow = (void *)GetProcAddress(library, "ImpersonateDdeClientWindow");
	pDdeSetQualityOfService = (void *)GetProcAddress(library, "DdeSetQualityOfService");
	pDdeGetLastError = (void *)GetProcAddress(library, "DdeGetLastError");
	pDdeQueryStringA = (void *)GetProcAddress(library, "DdeQueryStringA");
	pDdeQueryStringW = (void *)GetProcAddress(library, "DdeQueryStringW");
	pDdeCreateStringHandleA = (void *)GetProcAddress(library, "DdeCreateStringHandleA");
	pDdeCreateStringHandleW = (void *)GetProcAddress(library, "DdeCreateStringHandleW");
	pDdeFreeStringHandle = (void *)GetProcAddress(library, "DdeFreeStringHandle");
	pDdeKeepStringHandle = (void *)GetProcAddress(library, "DdeKeepStringHandle");
	pDdeCmpStringHandles = (void *)GetProcAddress(library, "DdeCmpStringHandles");
	pDdeInitializeA = (void *)GetProcAddress(library, "DdeInitializeA");
	pDdeInitializeW = (void *)GetProcAddress(library, "DdeInitializeW");
	pDdeUninitialize = (void *)GetProcAddress(library, "DdeUninitialize");
	pDdeCreateDataHandle = (void *)GetProcAddress(library, "DdeCreateDataHandle");
	pDdeAddData = (void *)GetProcAddress(library, "DdeAddData");
	pDdeGetData = (void *)GetProcAddress(library, "DdeGetData");
	pDdeAccessData = (void *)GetProcAddress(library, "DdeAccessData");
	pDdeUnaccessData = (void *)GetProcAddress(library, "DdeUnaccessData");
	pDdeFreeDataHandle = (void *)GetProcAddress(library, "DdeFreeDataHandle");
	pDdeEnableCallback = (void *)GetProcAddress(library, "DdeEnableCallback");
	pDdeSetUserHandle = (void *)GetProcAddress(library, "DdeSetUserHandle");
	pDdeQueryConvInfo = (void *)GetProcAddress(library, "DdeQueryConvInfo");
	pDdePostAdvise = (void *)GetProcAddress(library, "DdePostAdvise");
	pDdeNameService = (void *)GetProcAddress(library, "DdeNameService");
	pDefDlgProcA = (void *)GetProcAddress(library, "DefDlgProcA");
	pDefDlgProcW = (void *)GetProcAddress(library, "DefDlgProcW");
	pDefWindowProcA = (void *)GetProcAddress(library, "DefWindowProcA");
	pDefWindowProcW = (void *)GetProcAddress(library, "DefWindowProcW");
	pPaintDesktop = (void *)GetProcAddress(library, "PaintDesktop");
	pSetDeskWallPaper = (void *)GetProcAddress(library, "SetDeskWallPaper");
	pCreateDialogParamA = (void *)GetProcAddress(library, "CreateDialogParamA");
	pCreateDialogParamW = (void *)GetProcAddress(library, "CreateDialogParamW");
	pCreateDialogIndirectParamAorW = (void *)GetProcAddress(library, "CreateDialogIndirectParamAorW");
	pCreateDialogIndirectParamA = (void *)GetProcAddress(library, "CreateDialogIndirectParamA");
	pCreateDialogIndirectParamW = (void *)GetProcAddress(library, "CreateDialogIndirectParamW");
	pDialogBoxParamA = (void *)GetProcAddress(library, "DialogBoxParamA");
	pDialogBoxParamW = (void *)GetProcAddress(library, "DialogBoxParamW");
	pDialogBoxIndirectParamAorW = (void *)GetProcAddress(library, "DialogBoxIndirectParamAorW");
	pDialogBoxIndirectParamA = (void *)GetProcAddress(library, "DialogBoxIndirectParamA");
	pDialogBoxIndirectParamW = (void *)GetProcAddress(library, "DialogBoxIndirectParamW");
	pEndDialog = (void *)GetProcAddress(library, "EndDialog");
	pIsDialogMessageW = (void *)GetProcAddress(library, "IsDialogMessageW");
	pGetDlgCtrlID = (void *)GetProcAddress(library, "GetDlgCtrlID");
	pGetDlgItem = (void *)GetProcAddress(library, "GetDlgItem");
	pSendDlgItemMessageA = (void *)GetProcAddress(library, "SendDlgItemMessageA");
	pSendDlgItemMessageW = (void *)GetProcAddress(library, "SendDlgItemMessageW");
	pSetDlgItemTextA = (void *)GetProcAddress(library, "SetDlgItemTextA");
	pSetDlgItemTextW = (void *)GetProcAddress(library, "SetDlgItemTextW");
	pGetDlgItemTextA = (void *)GetProcAddress(library, "GetDlgItemTextA");
	pGetDlgItemTextW = (void *)GetProcAddress(library, "GetDlgItemTextW");
	pSetDlgItemInt = (void *)GetProcAddress(library, "SetDlgItemInt");
	pGetDlgItemInt = (void *)GetProcAddress(library, "GetDlgItemInt");
	pCheckDlgButton = (void *)GetProcAddress(library, "CheckDlgButton");
	pIsDlgButtonChecked = (void *)GetProcAddress(library, "IsDlgButtonChecked");
	pCheckRadioButton = (void *)GetProcAddress(library, "CheckRadioButton");
	pGetDialogBaseUnits = (void *)GetProcAddress(library, "GetDialogBaseUnits");
	pMapDialogRect = (void *)GetProcAddress(library, "MapDialogRect");
	pGetNextDlgGroupItem = (void *)GetProcAddress(library, "GetNextDlgGroupItem");
	pGetNextDlgTabItem = (void *)GetProcAddress(library, "GetNextDlgTabItem");
	pDlgDirSelectExA = (void *)GetProcAddress(library, "DlgDirSelectExA");
	pDlgDirSelectExW = (void *)GetProcAddress(library, "DlgDirSelectExW");
	pDlgDirSelectComboBoxExA = (void *)GetProcAddress(library, "DlgDirSelectComboBoxExA");
	pDlgDirSelectComboBoxExW = (void *)GetProcAddress(library, "DlgDirSelectComboBoxExW");
	pDlgDirListA = (void *)GetProcAddress(library, "DlgDirListA");
	pDlgDirListW = (void *)GetProcAddress(library, "DlgDirListW");
	pDlgDirListComboBoxA = (void *)GetProcAddress(library, "DlgDirListComboBoxA");
	pDlgDirListComboBoxW = (void *)GetProcAddress(library, "DlgDirListComboBoxW");
	pPrivateExtractIconsW = (void *)GetProcAddress(library, "PrivateExtractIconsW");
	pPrivateExtractIconsA = (void *)GetProcAddress(library, "PrivateExtractIconsA");
	pPrivateExtractIconExW = (void *)GetProcAddress(library, "PrivateExtractIconExW");
	pPrivateExtractIconExA = (void *)GetProcAddress(library, "PrivateExtractIconExA");
	pSetActiveWindow = (void *)GetProcAddress(library, "SetActiveWindow");
	pSetFocus = (void *)GetProcAddress(library, "SetFocus");
	pSetForegroundWindow = (void *)GetProcAddress(library, "SetForegroundWindow");
	pGetActiveWindow = (void *)GetProcAddress(library, "GetActiveWindow");
	pGetFocus = (void *)GetProcAddress(library, "GetFocus");
	pGetForegroundWindow = (void *)GetProcAddress(library, "GetForegroundWindow");
	pSetShellWindowEx = (void *)GetProcAddress(library, "SetShellWindowEx");
	pSetShellWindow = (void *)GetProcAddress(library, "SetShellWindow");
	pGetShellWindow = (void *)GetProcAddress(library, "GetShellWindow");
	pSetProgmanWindow = (void *)GetProcAddress(library, "SetProgmanWindow");
	pGetProgmanWindow = (void *)GetProcAddress(library, "GetProgmanWindow");
	pSetTaskmanWindow = (void *)GetProcAddress(library, "SetTaskmanWindow");
	pGetTaskmanWindow = (void *)GetProcAddress(library, "GetTaskmanWindow");
	pSetWindowsHookA = (void *)GetProcAddress(library, "SetWindowsHookA");
	pSetWindowsHookW = (void *)GetProcAddress(library, "SetWindowsHookW");
	pSetWindowsHookExA = (void *)GetProcAddress(library, "SetWindowsHookExA");
	pSetWindowsHookExW = (void *)GetProcAddress(library, "SetWindowsHookExW");
	pUnhookWindowsHook = (void *)GetProcAddress(library, "UnhookWindowsHook");
	pUnhookWindowsHookEx = (void *)GetProcAddress(library, "UnhookWindowsHookEx");
	pCallNextHookEx = (void *)GetProcAddress(library, "CallNextHookEx");
	pCallMsgFilterA = (void *)GetProcAddress(library, "CallMsgFilterA");
	pCallMsgFilterW = (void *)GetProcAddress(library, "CallMsgFilterW");
	pSetWinEventHook = (void *)GetProcAddress(library, "SetWinEventHook");
	pUnhookWinEvent = (void *)GetProcAddress(library, "UnhookWinEvent");
	pNotifyWinEvent = (void *)GetProcAddress(library, "NotifyWinEvent");
	pIsWinEventHookInstalled = (void *)GetProcAddress(library, "IsWinEventHookInstalled");
	p__wine_send_input = (void *)GetProcAddress(library, "__wine_send_input");
	pSendInput = (void *)GetProcAddress(library, "SendInput");
	pkeybd_event = (void *)GetProcAddress(library, "keybd_event");
	pmouse_event = (void *)GetProcAddress(library, "mouse_event");
	pGetCursorPos = (void *)GetProcAddress(library, "GetCursorPos");
	pGetCursorInfo = (void *)GetProcAddress(library, "GetCursorInfo");
	pSetCursorPos = (void *)GetProcAddress(library, "SetCursorPos");
	pSetCapture = (void *)GetProcAddress(library, "SetCapture");
	pReleaseCapture = (void *)GetProcAddress(library, "ReleaseCapture");
	pGetCapture = (void *)GetProcAddress(library, "GetCapture");
	pGetAsyncKeyState = (void *)GetProcAddress(library, "GetAsyncKeyState");
	pGetQueueStatus = (void *)GetProcAddress(library, "GetQueueStatus");
	pGetInputState = (void *)GetProcAddress(library, "GetInputState");
	pGetLastInputInfo = (void *)GetProcAddress(library, "GetLastInputInfo");
	pAttachThreadInput = (void *)GetProcAddress(library, "AttachThreadInput");
	pGetKeyState = (void *)GetProcAddress(library, "GetKeyState");
	pGetKeyboardState = (void *)GetProcAddress(library, "GetKeyboardState");
	pSetKeyboardState = (void *)GetProcAddress(library, "SetKeyboardState");
	pVkKeyScanA = (void *)GetProcAddress(library, "VkKeyScanA");
	pVkKeyScanW = (void *)GetProcAddress(library, "VkKeyScanW");
	pVkKeyScanExA = (void *)GetProcAddress(library, "VkKeyScanExA");
	pVkKeyScanExW = (void *)GetProcAddress(library, "VkKeyScanExW");
	pOemKeyScan = (void *)GetProcAddress(library, "OemKeyScan");
	pGetKeyboardType = (void *)GetProcAddress(library, "GetKeyboardType");
	pMapVirtualKeyA = (void *)GetProcAddress(library, "MapVirtualKeyA");
	pMapVirtualKeyW = (void *)GetProcAddress(library, "MapVirtualKeyW");
	pMapVirtualKeyExA = (void *)GetProcAddress(library, "MapVirtualKeyExA");
	pMapVirtualKeyExW = (void *)GetProcAddress(library, "MapVirtualKeyExW");
	pGetKBCodePage = (void *)GetProcAddress(library, "GetKBCodePage");
	pGetKeyboardLayout = (void *)GetProcAddress(library, "GetKeyboardLayout");
	pGetKeyboardLayoutNameA = (void *)GetProcAddress(library, "GetKeyboardLayoutNameA");
	pGetKeyboardLayoutNameW = (void *)GetProcAddress(library, "GetKeyboardLayoutNameW");
	pGetKeyNameTextA = (void *)GetProcAddress(library, "GetKeyNameTextA");
	pGetKeyNameTextW = (void *)GetProcAddress(library, "GetKeyNameTextW");
	pToUnicode = (void *)GetProcAddress(library, "ToUnicode");
	pToUnicodeEx = (void *)GetProcAddress(library, "ToUnicodeEx");
	pToAscii = (void *)GetProcAddress(library, "ToAscii");
	pToAsciiEx = (void *)GetProcAddress(library, "ToAsciiEx");
	pActivateKeyboardLayout = (void *)GetProcAddress(library, "ActivateKeyboardLayout");
	pBlockInput = (void *)GetProcAddress(library, "BlockInput");
	pGetKeyboardLayoutList = (void *)GetProcAddress(library, "GetKeyboardLayoutList");
	pRegisterHotKey = (void *)GetProcAddress(library, "RegisterHotKey");
	pUnregisterHotKey = (void *)GetProcAddress(library, "UnregisterHotKey");
	pLoadKeyboardLayoutW = (void *)GetProcAddress(library, "LoadKeyboardLayoutW");
	pLoadKeyboardLayoutA = (void *)GetProcAddress(library, "LoadKeyboardLayoutA");
	pUnloadKeyboardLayout = (void *)GetProcAddress(library, "UnloadKeyboardLayout");
	pTrackMouseEvent = (void *)GetProcAddress(library, "TrackMouseEvent");
	pGetMouseMovePointsEx = (void *)GetProcAddress(library, "GetMouseMovePointsEx");
	pEnableMouseInPointer = (void *)GetProcAddress(library, "EnableMouseInPointer");
	pGetListBoxInfo = (void *)GetProcAddress(library, "GetListBoxInfo");
	pCharNextA = (void *)GetProcAddress(library, "CharNextA");
	pCharNextExA = (void *)GetProcAddress(library, "CharNextExA");
	pCharNextExW = (void *)GetProcAddress(library, "CharNextExW");
	pCharNextW = (void *)GetProcAddress(library, "CharNextW");
	pCharPrevA = (void *)GetProcAddress(library, "CharPrevA");
	pCharPrevExA = (void *)GetProcAddress(library, "CharPrevExA");
	pCharPrevExW = (void *)GetProcAddress(library, "CharPrevExW");
	pCharPrevW = (void *)GetProcAddress(library, "CharPrevW");
	pCharToOemA = (void *)GetProcAddress(library, "CharToOemA");
	pCharToOemBuffA = (void *)GetProcAddress(library, "CharToOemBuffA");
	pCharToOemBuffW = (void *)GetProcAddress(library, "CharToOemBuffW");
	pCharToOemW = (void *)GetProcAddress(library, "CharToOemW");
	pOemToCharA = (void *)GetProcAddress(library, "OemToCharA");
	pOemToCharBuffA = (void *)GetProcAddress(library, "OemToCharBuffA");
	pOemToCharBuffW = (void *)GetProcAddress(library, "OemToCharBuffW");
	pOemToCharW = (void *)GetProcAddress(library, "OemToCharW");
	pCharLowerA = (void *)GetProcAddress(library, "CharLowerA");
	pCharUpperA = (void *)GetProcAddress(library, "CharUpperA");
	pCharLowerW = (void *)GetProcAddress(library, "CharLowerW");
	pCharUpperW = (void *)GetProcAddress(library, "CharUpperW");
	pCharLowerBuffA = (void *)GetProcAddress(library, "CharLowerBuffA");
	pCharLowerBuffW = (void *)GetProcAddress(library, "CharLowerBuffW");
	pCharUpperBuffA = (void *)GetProcAddress(library, "CharUpperBuffA");
	pCharUpperBuffW = (void *)GetProcAddress(library, "CharUpperBuffW");
	pIsCharLowerA = (void *)GetProcAddress(library, "IsCharLowerA");
	pIsCharLowerW = (void *)GetProcAddress(library, "IsCharLowerW");
	pIsCharUpperA = (void *)GetProcAddress(library, "IsCharUpperA");
	pIsCharUpperW = (void *)GetProcAddress(library, "IsCharUpperW");
	pIsCharAlphaNumericA = (void *)GetProcAddress(library, "IsCharAlphaNumericA");
	pIsCharAlphaNumericW = (void *)GetProcAddress(library, "IsCharAlphaNumericW");
	pIsCharAlphaA = (void *)GetProcAddress(library, "IsCharAlphaA");
	pIsCharAlphaW = (void *)GetProcAddress(library, "IsCharAlphaW");
	pDefFrameProcA = (void *)GetProcAddress(library, "DefFrameProcA");
	pDefFrameProcW = (void *)GetProcAddress(library, "DefFrameProcW");
	pDefMDIChildProcA = (void *)GetProcAddress(library, "DefMDIChildProcA");
	pDefMDIChildProcW = (void *)GetProcAddress(library, "DefMDIChildProcW");
	pCreateMDIWindowA = (void *)GetProcAddress(library, "CreateMDIWindowA");
	pCreateMDIWindowW = (void *)GetProcAddress(library, "CreateMDIWindowW");
	pTranslateMDISysAccel = (void *)GetProcAddress(library, "TranslateMDISysAccel");
	pCalcChildScroll = (void *)GetProcAddress(library, "CalcChildScroll");
	pScrollChildren = (void *)GetProcAddress(library, "ScrollChildren");
	pCascadeWindows = (void *)GetProcAddress(library, "CascadeWindows");
	pCascadeChildWindows = (void *)GetProcAddress(library, "CascadeChildWindows");
	pTileWindows = (void *)GetProcAddress(library, "TileWindows");
	pTileChildWindows = (void *)GetProcAddress(library, "TileChildWindows");
	pDrawMenuBarTemp = (void *)GetProcAddress(library, "DrawMenuBarTemp");
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
	pSendMessageTimeoutW = (void *)GetProcAddress(library, "SendMessageTimeoutW");
	pSendMessageTimeoutA = (void *)GetProcAddress(library, "SendMessageTimeoutA");
	pSendMessageW = (void *)GetProcAddress(library, "SendMessageW");
	pSendMessageA = (void *)GetProcAddress(library, "SendMessageA");
	pSendNotifyMessageA = (void *)GetProcAddress(library, "SendNotifyMessageA");
	pSendNotifyMessageW = (void *)GetProcAddress(library, "SendNotifyMessageW");
	pSendMessageCallbackA = (void *)GetProcAddress(library, "SendMessageCallbackA");
	pSendMessageCallbackW = (void *)GetProcAddress(library, "SendMessageCallbackW");
	pReplyMessage = (void *)GetProcAddress(library, "ReplyMessage");
	pInSendMessage = (void *)GetProcAddress(library, "InSendMessage");
	pInSendMessageEx = (void *)GetProcAddress(library, "InSendMessageEx");
	pPostMessageA = (void *)GetProcAddress(library, "PostMessageA");
	pPostMessageW = (void *)GetProcAddress(library, "PostMessageW");
	pPostThreadMessageA = (void *)GetProcAddress(library, "PostThreadMessageA");
	pPostThreadMessageW = (void *)GetProcAddress(library, "PostThreadMessageW");
	pPostQuitMessage = (void *)GetProcAddress(library, "PostQuitMessage");
	pPeekMessageW = (void *)GetProcAddress(library, "PeekMessageW");
	pPeekMessageA = (void *)GetProcAddress(library, "PeekMessageA");
	pGetMessageW = (void *)GetProcAddress(library, "GetMessageW");
	pGetMessageA = (void *)GetProcAddress(library, "GetMessageA");
	pIsDialogMessageA = (void *)GetProcAddress(library, "IsDialogMessageA");
	pTranslateMessage = (void *)GetProcAddress(library, "TranslateMessage");
	pDispatchMessageA = (void *)GetProcAddress(library, "DispatchMessageA");
	pDispatchMessageW = (void *)GetProcAddress(library, "DispatchMessageW");
	pGetMessagePos = (void *)GetProcAddress(library, "GetMessagePos");
	pGetMessageTime = (void *)GetProcAddress(library, "GetMessageTime");
	pGetMessageExtraInfo = (void *)GetProcAddress(library, "GetMessageExtraInfo");
	pSetMessageExtraInfo = (void *)GetProcAddress(library, "SetMessageExtraInfo");
	pGetCurrentInputMessageSource = (void *)GetProcAddress(library, "GetCurrentInputMessageSource");
	pWaitMessage = (void *)GetProcAddress(library, "WaitMessage");
	pMsgWaitForMultipleObjectsEx = (void *)GetProcAddress(library, "MsgWaitForMultipleObjectsEx");
	pMsgWaitForMultipleObjects = (void *)GetProcAddress(library, "MsgWaitForMultipleObjects");
	pWaitForInputIdle = (void *)GetProcAddress(library, "WaitForInputIdle");
	pRegisterWindowMessageA = (void *)GetProcAddress(library, "RegisterWindowMessageA");
	pRegisterWindowMessageW = (void *)GetProcAddress(library, "RegisterWindowMessageW");
	pBroadcastSystemMessageA = (void *)GetProcAddress(library, "BroadcastSystemMessageA");
	pBroadcastSystemMessageW = (void *)GetProcAddress(library, "BroadcastSystemMessageW");
	pBroadcastSystemMessageExA = (void *)GetProcAddress(library, "BroadcastSystemMessageExA");
	pBroadcastSystemMessageExW = (void *)GetProcAddress(library, "BroadcastSystemMessageExW");
	pSetMessageQueue = (void *)GetProcAddress(library, "SetMessageQueue");
	pMessageBeep = (void *)GetProcAddress(library, "MessageBeep");
	pSetCoalescableTimer = (void *)GetProcAddress(library, "SetCoalescableTimer");
	pSetTimer = (void *)GetProcAddress(library, "SetTimer");
	pSetSystemTimer = (void *)GetProcAddress(library, "SetSystemTimer");
	pKillTimer = (void *)GetProcAddress(library, "KillTimer");
	pKillSystemTimer = (void *)GetProcAddress(library, "KillSystemTimer");
	pIsGUIThread = (void *)GetProcAddress(library, "IsGUIThread");
	pGetGUIThreadInfo = (void *)GetProcAddress(library, "GetGUIThreadInfo");
	pIsHungAppWindow = (void *)GetProcAddress(library, "IsHungAppWindow");
	pChangeWindowMessageFilter = (void *)GetProcAddress(library, "ChangeWindowMessageFilter");
	pChangeWindowMessageFilterEx = (void *)GetProcAddress(library, "ChangeWindowMessageFilterEx");
	pUserSignalProc = (void *)GetProcAddress(library, "UserSignalProc");
	pSetLastErrorEx = (void *)GetProcAddress(library, "SetLastErrorEx");
	pGetAltTabInfoA = (void *)GetProcAddress(library, "GetAltTabInfoA");
	pGetAltTabInfoW = (void *)GetProcAddress(library, "GetAltTabInfoW");
	pSetDebugErrorLevel = (void *)GetProcAddress(library, "SetDebugErrorLevel");
	pSetWindowStationUser = (void *)GetProcAddress(library, "SetWindowStationUser");
	pRegisterLogonProcess = (void *)GetProcAddress(library, "RegisterLogonProcess");
	pSetLogonNotifyWindow = (void *)GetProcAddress(library, "SetLogonNotifyWindow");
	pQueryDisplayConfig = (void *)GetProcAddress(library, "QueryDisplayConfig");
	pRegisterSystemThread = (void *)GetProcAddress(library, "RegisterSystemThread");
	pRegisterShellHookWindow = (void *)GetProcAddress(library, "RegisterShellHookWindow");
	pDeregisterShellHookWindow = (void *)GetProcAddress(library, "DeregisterShellHookWindow");
	pRegisterTasklist = (void *)GetProcAddress(library, "RegisterTasklist");
	pRegisterDeviceNotificationA = (void *)GetProcAddress(library, "RegisterDeviceNotificationA");
	pRegisterDeviceNotificationW = (void *)GetProcAddress(library, "RegisterDeviceNotificationW");
	pUnregisterDeviceNotification = (void *)GetProcAddress(library, "UnregisterDeviceNotification");
	pGetAppCompatFlags = (void *)GetProcAddress(library, "GetAppCompatFlags");
	pGetAppCompatFlags2 = (void *)GetProcAddress(library, "GetAppCompatFlags2");
	pAlignRects = (void *)GetProcAddress(library, "AlignRects");
	pLoadLocalFonts = (void *)GetProcAddress(library, "LoadLocalFonts");
	pUser32InitializeImmEntryTable = (void *)GetProcAddress(library, "User32InitializeImmEntryTable");
	pWINNLSGetIMEHotkey = (void *)GetProcAddress(library, "WINNLSGetIMEHotkey");
	pWINNLSEnableIME = (void *)GetProcAddress(library, "WINNLSEnableIME");
	pWINNLSGetEnableStatus = (void *)GetProcAddress(library, "WINNLSGetEnableStatus");
	pSendIMEMessageExA = (void *)GetProcAddress(library, "SendIMEMessageExA");
	pSendIMEMessageExW = (void *)GetProcAddress(library, "SendIMEMessageExW");
	pDisableProcessWindowsGhosting = (void *)GetProcAddress(library, "DisableProcessWindowsGhosting");
	pUserHandleGrantAccess = (void *)GetProcAddress(library, "UserHandleGrantAccess");
	pRegisterPowerSettingNotification = (void *)GetProcAddress(library, "RegisterPowerSettingNotification");
	pUnregisterPowerSettingNotification = (void *)GetProcAddress(library, "UnregisterPowerSettingNotification");
	pGetGestureConfig = (void *)GetProcAddress(library, "GetGestureConfig");
	pSetGestureConfig = (void *)GetProcAddress(library, "SetGestureConfig");
	pIsTouchWindow = (void *)GetProcAddress(library, "IsTouchWindow");
	pIsWindowRedirectedForPrint = (void *)GetProcAddress(library, "IsWindowRedirectedForPrint");
	pGetDisplayConfigBufferSizes = (void *)GetProcAddress(library, "GetDisplayConfigBufferSizes");
	pRegisterPointerDeviceNotifications = (void *)GetProcAddress(library, "RegisterPointerDeviceNotifications");
	pGetPointerDevices = (void *)GetProcAddress(library, "GetPointerDevices");
	pRegisterTouchHitTestingWindow = (void *)GetProcAddress(library, "RegisterTouchHitTestingWindow");
	pGetPointerType = (void *)GetProcAddress(library, "GetPointerType");
	pMessageBoxA = (void *)GetProcAddress(library, "MessageBoxA");
	pMessageBoxW = (void *)GetProcAddress(library, "MessageBoxW");
	pMessageBoxExA = (void *)GetProcAddress(library, "MessageBoxExA");
	pMessageBoxExW = (void *)GetProcAddress(library, "MessageBoxExW");
	pMessageBoxTimeoutA = (void *)GetProcAddress(library, "MessageBoxTimeoutA");
	pMessageBoxTimeoutW = (void *)GetProcAddress(library, "MessageBoxTimeoutW");
	pMessageBoxIndirectA = (void *)GetProcAddress(library, "MessageBoxIndirectA");
	pMessageBoxIndirectW = (void *)GetProcAddress(library, "MessageBoxIndirectW");
	pDrawCaption = (void *)GetProcAddress(library, "DrawCaption");
	pDrawCaptionTempA = (void *)GetProcAddress(library, "DrawCaptionTempA");
	pDrawCaptionTempW = (void *)GetProcAddress(library, "DrawCaptionTempW");
	pAdjustWindowRect = (void *)GetProcAddress(library, "AdjustWindowRect");
	pAdjustWindowRectEx = (void *)GetProcAddress(library, "AdjustWindowRectEx");
	pAdjustWindowRectExForDpi = (void *)GetProcAddress(library, "AdjustWindowRectExForDpi");
	pGetTitleBarInfo = (void *)GetProcAddress(library, "GetTitleBarInfo");
	pBeginPaint = (void *)GetProcAddress(library, "BeginPaint");
	pEndPaint = (void *)GetProcAddress(library, "EndPaint");
	pGetDCEx = (void *)GetProcAddress(library, "GetDCEx");
	pGetDC = (void *)GetProcAddress(library, "GetDC");
	pGetWindowDC = (void *)GetProcAddress(library, "GetWindowDC");
	pReleaseDC = (void *)GetProcAddress(library, "ReleaseDC");
	pWindowFromDC = (void *)GetProcAddress(library, "WindowFromDC");
	pLockWindowUpdate = (void *)GetProcAddress(library, "LockWindowUpdate");
	pRedrawWindow = (void *)GetProcAddress(library, "RedrawWindow");
	pUpdateWindow = (void *)GetProcAddress(library, "UpdateWindow");
	pInvalidateRgn = (void *)GetProcAddress(library, "InvalidateRgn");
	pInvalidateRect = (void *)GetProcAddress(library, "InvalidateRect");
	pValidateRgn = (void *)GetProcAddress(library, "ValidateRgn");
	pValidateRect = (void *)GetProcAddress(library, "ValidateRect");
	pGetUpdateRgn = (void *)GetProcAddress(library, "GetUpdateRgn");
	pGetUpdateRect = (void *)GetProcAddress(library, "GetUpdateRect");
	pExcludeUpdateRgn = (void *)GetProcAddress(library, "ExcludeUpdateRgn");
	pScrollWindowEx = (void *)GetProcAddress(library, "ScrollWindowEx");
	pScrollWindow = (void *)GetProcAddress(library, "ScrollWindow");
	pScrollDC = (void *)GetProcAddress(library, "ScrollDC");
	pPrintWindow = (void *)GetProcAddress(library, "PrintWindow");
	pEnumPropsA = (void *)GetProcAddress(library, "EnumPropsA");
	pEnumPropsW = (void *)GetProcAddress(library, "EnumPropsW");
	pGetPropA = (void *)GetProcAddress(library, "GetPropA");
	pGetPropW = (void *)GetProcAddress(library, "GetPropW");
	pSetPropA = (void *)GetProcAddress(library, "SetPropA");
	pSetPropW = (void *)GetProcAddress(library, "SetPropW");
	pRemovePropA = (void *)GetProcAddress(library, "RemovePropA");
	pRemovePropW = (void *)GetProcAddress(library, "RemovePropW");
	pEnumPropsExA = (void *)GetProcAddress(library, "EnumPropsExA");
	pEnumPropsExW = (void *)GetProcAddress(library, "EnumPropsExW");
	pGetRawInputDeviceList = (void *)GetProcAddress(library, "GetRawInputDeviceList");
	pRegisterRawInputDevices = (void *)GetProcAddress(library, "RegisterRawInputDevices");
	pGetRawInputData = (void *)GetProcAddress(library, "GetRawInputData");
	pGetRawInputBuffer = (void *)GetProcAddress(library, "GetRawInputBuffer");
	pGetRawInputDeviceInfoA = (void *)GetProcAddress(library, "GetRawInputDeviceInfoA");
	pGetRawInputDeviceInfoW = (void *)GetProcAddress(library, "GetRawInputDeviceInfoW");
	pGetRegisteredRawInputDevices = (void *)GetProcAddress(library, "GetRegisteredRawInputDevices");
	pDefRawInputProc = (void *)GetProcAddress(library, "DefRawInputProc");
	pLoadAcceleratorsW = (void *)GetProcAddress(library, "LoadAcceleratorsW");
	pLoadAcceleratorsA = (void *)GetProcAddress(library, "LoadAcceleratorsA");
	pCopyAcceleratorTableA = (void *)GetProcAddress(library, "CopyAcceleratorTableA");
	pCopyAcceleratorTableW = (void *)GetProcAddress(library, "CopyAcceleratorTableW");
	pCreateAcceleratorTableA = (void *)GetProcAddress(library, "CreateAcceleratorTableA");
	pCreateAcceleratorTableW = (void *)GetProcAddress(library, "CreateAcceleratorTableW");
	pDestroyAcceleratorTable = (void *)GetProcAddress(library, "DestroyAcceleratorTable");
	pLoadStringW = (void *)GetProcAddress(library, "LoadStringW");
	pLoadStringA = (void *)GetProcAddress(library, "LoadStringA");
	pGetGuiResources = (void *)GetProcAddress(library, "GetGuiResources");
	pSetScrollInfo = (void *)GetProcAddress(library, "SetScrollInfo");
	pGetScrollInfo = (void *)GetProcAddress(library, "GetScrollInfo");
	pGetScrollBarInfo = (void *)GetProcAddress(library, "GetScrollBarInfo");
	pSetScrollPos = (void *)GetProcAddress(library, "SetScrollPos");
	pGetScrollPos = (void *)GetProcAddress(library, "GetScrollPos");
	pSetScrollRange = (void *)GetProcAddress(library, "SetScrollRange");
	pGetScrollRange = (void *)GetProcAddress(library, "GetScrollRange");
	pShowScrollBar = (void *)GetProcAddress(library, "ShowScrollBar");
	pEnableScrollBar = (void *)GetProcAddress(library, "EnableScrollBar");
	pSystemParametersInfoForDpi = (void *)GetProcAddress(library, "SystemParametersInfoForDpi");
	pSystemParametersInfoW = (void *)GetProcAddress(library, "SystemParametersInfoW");
	pSystemParametersInfoA = (void *)GetProcAddress(library, "SystemParametersInfoA");
	pGetSystemMetrics = (void *)GetProcAddress(library, "GetSystemMetrics");
	pGetSystemMetricsForDpi = (void *)GetProcAddress(library, "GetSystemMetricsForDpi");
	pSwapMouseButton = (void *)GetProcAddress(library, "SwapMouseButton");
	pSetDoubleClickTime = (void *)GetProcAddress(library, "SetDoubleClickTime");
	pGetDoubleClickTime = (void *)GetProcAddress(library, "GetDoubleClickTime");
	pGetSysColor = (void *)GetProcAddress(library, "GetSysColor");
	pSetSysColors = (void *)GetProcAddress(library, "SetSysColors");
	pSetSysColorsTemp = (void *)GetProcAddress(library, "SetSysColorsTemp");
	pGetSysColorBrush = (void *)GetProcAddress(library, "GetSysColorBrush");
	pChangeDisplaySettingsA = (void *)GetProcAddress(library, "ChangeDisplaySettingsA");
	pChangeDisplaySettingsW = (void *)GetProcAddress(library, "ChangeDisplaySettingsW");
	pChangeDisplaySettingsExA = (void *)GetProcAddress(library, "ChangeDisplaySettingsExA");
	pChangeDisplaySettingsExW = (void *)GetProcAddress(library, "ChangeDisplaySettingsExW");
	pDisplayConfigGetDeviceInfo = (void *)GetProcAddress(library, "DisplayConfigGetDeviceInfo");
	pEnumDisplaySettingsW = (void *)GetProcAddress(library, "EnumDisplaySettingsW");
	pEnumDisplaySettingsA = (void *)GetProcAddress(library, "EnumDisplaySettingsA");
	pEnumDisplaySettingsExA = (void *)GetProcAddress(library, "EnumDisplaySettingsExA");
	pEnumDisplaySettingsExW = (void *)GetProcAddress(library, "EnumDisplaySettingsExW");
	pSetProcessDpiAwarenessContext = (void *)GetProcAddress(library, "SetProcessDpiAwarenessContext");
	pGetProcessDpiAwarenessInternal = (void *)GetProcAddress(library, "GetProcessDpiAwarenessInternal");
	pSetProcessDpiAwarenessInternal = (void *)GetProcAddress(library, "SetProcessDpiAwarenessInternal");
	pAreDpiAwarenessContextsEqual = (void *)GetProcAddress(library, "AreDpiAwarenessContextsEqual");
	pGetAwarenessFromDpiAwarenessContext = (void *)GetProcAddress(library, "GetAwarenessFromDpiAwarenessContext");
	pIsValidDpiAwarenessContext = (void *)GetProcAddress(library, "IsValidDpiAwarenessContext");
	pSetProcessDPIAware = (void *)GetProcAddress(library, "SetProcessDPIAware");
	pIsProcessDPIAware = (void *)GetProcAddress(library, "IsProcessDPIAware");
	pGetDpiForSystem = (void *)GetProcAddress(library, "GetDpiForSystem");
	pGetDpiForMonitorInternal = (void *)GetProcAddress(library, "GetDpiForMonitorInternal");
	pGetThreadDpiAwarenessContext = (void *)GetProcAddress(library, "GetThreadDpiAwarenessContext");
	pSetThreadDpiAwarenessContext = (void *)GetProcAddress(library, "SetThreadDpiAwarenessContext");
	pLogicalToPhysicalPointForPerMonitorDPI = (void *)GetProcAddress(library, "LogicalToPhysicalPointForPerMonitorDPI");
	pPhysicalToLogicalPointForPerMonitorDPI = (void *)GetProcAddress(library, "PhysicalToLogicalPointForPerMonitorDPI");
	pMonitorFromRect = (void *)GetProcAddress(library, "MonitorFromRect");
	pMonitorFromPoint = (void *)GetProcAddress(library, "MonitorFromPoint");
	pMonitorFromWindow = (void *)GetProcAddress(library, "MonitorFromWindow");
	pGetMonitorInfoA = (void *)GetProcAddress(library, "GetMonitorInfoA");
	pGetMonitorInfoW = (void *)GetProcAddress(library, "GetMonitorInfoW");
	pEnumDisplayMonitors = (void *)GetProcAddress(library, "EnumDisplayMonitors");
	pEnumDisplayDevicesA = (void *)GetProcAddress(library, "EnumDisplayDevicesA");
	pEnumDisplayDevicesW = (void *)GetProcAddress(library, "EnumDisplayDevicesW");
	pGetAutoRotationState = (void *)GetProcAddress(library, "GetAutoRotationState");
	pGetDisplayAutoRotationPreferences = (void *)GetProcAddress(library, "GetDisplayAutoRotationPreferences");
	pGetPhysicalCursorPos = (void *)GetProcAddress(library, "GetPhysicalCursorPos");
	pSetPhysicalCursorPos = (void *)GetProcAddress(library, "SetPhysicalCursorPos");
	pLogicalToPhysicalPoint = (void *)GetProcAddress(library, "LogicalToPhysicalPoint");
	pPhysicalToLogicalPoint = (void *)GetProcAddress(library, "PhysicalToLogicalPoint");
	pDrawTextExW = (void *)GetProcAddress(library, "DrawTextExW");
	pDrawTextExA = (void *)GetProcAddress(library, "DrawTextExA");
	pDrawTextW = (void *)GetProcAddress(library, "DrawTextW");
	pDrawTextA = (void *)GetProcAddress(library, "DrawTextA");
	pGrayStringA = (void *)GetProcAddress(library, "GrayStringA");
	pGrayStringW = (void *)GetProcAddress(library, "GrayStringW");
	pTabbedTextOutA = (void *)GetProcAddress(library, "TabbedTextOutA");
	pTabbedTextOutW = (void *)GetProcAddress(library, "TabbedTextOutW");
	pGetTabbedTextExtentA = (void *)GetProcAddress(library, "GetTabbedTextExtentA");
	pGetTabbedTextExtentW = (void *)GetProcAddress(library, "GetTabbedTextExtentW");
	pDrawEdge = (void *)GetProcAddress(library, "DrawEdge");
	pDrawFrameControl = (void *)GetProcAddress(library, "DrawFrameControl");
	pSetRect = (void *)GetProcAddress(library, "SetRect");
	pSetRectEmpty = (void *)GetProcAddress(library, "SetRectEmpty");
	pCopyRect = (void *)GetProcAddress(library, "CopyRect");
	pIsRectEmpty = (void *)GetProcAddress(library, "IsRectEmpty");
	pPtInRect = (void *)GetProcAddress(library, "PtInRect");
	pOffsetRect = (void *)GetProcAddress(library, "OffsetRect");
	pInflateRect = (void *)GetProcAddress(library, "InflateRect");
	pIntersectRect = (void *)GetProcAddress(library, "IntersectRect");
	pUnionRect = (void *)GetProcAddress(library, "UnionRect");
	pEqualRect = (void *)GetProcAddress(library, "EqualRect");
	pSubtractRect = (void *)GetProcAddress(library, "SubtractRect");
	pFillRect = (void *)GetProcAddress(library, "FillRect");
	pInvertRect = (void *)GetProcAddress(library, "InvertRect");
	pFrameRect = (void *)GetProcAddress(library, "FrameRect");
	pDrawFocusRect = (void *)GetProcAddress(library, "DrawFocusRect");
	pDrawAnimatedRects = (void *)GetProcAddress(library, "DrawAnimatedRects");
	pDrawStateA = (void *)GetProcAddress(library, "DrawStateA");
	pDrawStateW = (void *)GetProcAddress(library, "DrawStateW");
	pUserRealizePalette = (void *)GetProcAddress(library, "UserRealizePalette");
	pExitWindowsEx = (void *)GetProcAddress(library, "ExitWindowsEx");
	pLockWorkStation = (void *)GetProcAddress(library, "LockWorkStation");
	pRegisterServicesProcess = (void *)GetProcAddress(library, "RegisterServicesProcess");
	pShutdownBlockReasonCreate = (void *)GetProcAddress(library, "ShutdownBlockReasonCreate");
	pShutdownBlockReasonDestroy = (void *)GetProcAddress(library, "ShutdownBlockReasonDestroy");
	pCreateWindowExA = (void *)GetProcAddress(library, "CreateWindowExA");
	pCreateWindowExW = (void *)GetProcAddress(library, "CreateWindowExW");
	pDestroyWindow = (void *)GetProcAddress(library, "DestroyWindow");
	pCloseWindow = (void *)GetProcAddress(library, "CloseWindow");
	pOpenIcon = (void *)GetProcAddress(library, "OpenIcon");
	pFindWindowExW = (void *)GetProcAddress(library, "FindWindowExW");
	pFindWindowA = (void *)GetProcAddress(library, "FindWindowA");
	pFindWindowExA = (void *)GetProcAddress(library, "FindWindowExA");
	pFindWindowW = (void *)GetProcAddress(library, "FindWindowW");
	pGetDesktopWindow = (void *)GetProcAddress(library, "GetDesktopWindow");
	pEnableWindow = (void *)GetProcAddress(library, "EnableWindow");
	pIsWindowEnabled = (void *)GetProcAddress(library, "IsWindowEnabled");
	pIsWindowUnicode = (void *)GetProcAddress(library, "IsWindowUnicode");
	pGetWindowDpiAwarenessContext = (void *)GetProcAddress(library, "GetWindowDpiAwarenessContext");
	pGetDpiForWindow = (void *)GetProcAddress(library, "GetDpiForWindow");
	pGetWindowWord = (void *)GetProcAddress(library, "GetWindowWord");
	pGetWindowLongA = (void *)GetProcAddress(library, "GetWindowLongA");
	pGetWindowLongW = (void *)GetProcAddress(library, "GetWindowLongW");
	pSetWindowWord = (void *)GetProcAddress(library, "SetWindowWord");
	pSetWindowLongA = (void *)GetProcAddress(library, "SetWindowLongA");
	pSetWindowLongW = (void *)GetProcAddress(library, "SetWindowLongW");
	pGetWindowTextA = (void *)GetProcAddress(library, "GetWindowTextA");
	pInternalGetWindowText = (void *)GetProcAddress(library, "InternalGetWindowText");
	pGetWindowTextW = (void *)GetProcAddress(library, "GetWindowTextW");
	pSetWindowTextA = (void *)GetProcAddress(library, "SetWindowTextA");
	pSetWindowTextW = (void *)GetProcAddress(library, "SetWindowTextW");
	pGetWindowTextLengthA = (void *)GetProcAddress(library, "GetWindowTextLengthA");
	pGetWindowTextLengthW = (void *)GetProcAddress(library, "GetWindowTextLengthW");
	pIsWindow = (void *)GetProcAddress(library, "IsWindow");
	pGetWindowThreadProcessId = (void *)GetProcAddress(library, "GetWindowThreadProcessId");
	pGetParent = (void *)GetProcAddress(library, "GetParent");
	pGetAncestor = (void *)GetProcAddress(library, "GetAncestor");
	pSetParent = (void *)GetProcAddress(library, "SetParent");
	pIsChild = (void *)GetProcAddress(library, "IsChild");
	pIsWindowVisible = (void *)GetProcAddress(library, "IsWindowVisible");
	pGetTopWindow = (void *)GetProcAddress(library, "GetTopWindow");
	pGetWindow = (void *)GetProcAddress(library, "GetWindow");
	pShowOwnedPopups = (void *)GetProcAddress(library, "ShowOwnedPopups");
	pGetLastActivePopup = (void *)GetProcAddress(library, "GetLastActivePopup");
	pEnumWindows = (void *)GetProcAddress(library, "EnumWindows");
	pEnumThreadWindows = (void *)GetProcAddress(library, "EnumThreadWindows");
	pEnumDesktopWindows = (void *)GetProcAddress(library, "EnumDesktopWindows");
	pEnumChildWindows = (void *)GetProcAddress(library, "EnumChildWindows");
	pAnyPopup = (void *)GetProcAddress(library, "AnyPopup");
	pFlashWindow = (void *)GetProcAddress(library, "FlashWindow");
	pFlashWindowEx = (void *)GetProcAddress(library, "FlashWindowEx");
	pGetWindowContextHelpId = (void *)GetProcAddress(library, "GetWindowContextHelpId");
	pSetWindowContextHelpId = (void *)GetProcAddress(library, "SetWindowContextHelpId");
	pDragDetect = (void *)GetProcAddress(library, "DragDetect");
	pGetWindowModuleFileNameA = (void *)GetProcAddress(library, "GetWindowModuleFileNameA");
	pGetWindowModuleFileNameW = (void *)GetProcAddress(library, "GetWindowModuleFileNameW");
	pGetWindowInfo = (void *)GetProcAddress(library, "GetWindowInfo");
	pSwitchDesktop = (void *)GetProcAddress(library, "SwitchDesktop");
	p__wine_set_pixel_format = (void *)GetProcAddress(library, "__wine_set_pixel_format");
	pSetLayeredWindowAttributes = (void *)GetProcAddress(library, "SetLayeredWindowAttributes");
	pGetLayeredWindowAttributes = (void *)GetProcAddress(library, "GetLayeredWindowAttributes");
	pUpdateLayeredWindowIndirect = (void *)GetProcAddress(library, "UpdateLayeredWindowIndirect");
	pUpdateLayeredWindow = (void *)GetProcAddress(library, "UpdateLayeredWindow");
	pGetProcessDefaultLayout = (void *)GetProcAddress(library, "GetProcessDefaultLayout");
	pSetProcessDefaultLayout = (void *)GetProcAddress(library, "SetProcessDefaultLayout");
	pGetWindowLongPtrW = (void *)GetProcAddress(library, "GetWindowLongPtrW");
	pGetWindowLongPtrA = (void *)GetProcAddress(library, "GetWindowLongPtrA");
	pSetWindowLongPtrW = (void *)GetProcAddress(library, "SetWindowLongPtrW");
	pSetWindowLongPtrA = (void *)GetProcAddress(library, "SetWindowLongPtrA");
	pRegisterTouchWindow = (void *)GetProcAddress(library, "RegisterTouchWindow");
	pUnregisterTouchWindow = (void *)GetProcAddress(library, "UnregisterTouchWindow");
	pCloseTouchInputHandle = (void *)GetProcAddress(library, "CloseTouchInputHandle");
	pGetTouchInputInfo = (void *)GetProcAddress(library, "GetTouchInputInfo");
	pGetGestureInfo = (void *)GetProcAddress(library, "GetGestureInfo");
	pGetWindowDisplayAffinity = (void *)GetProcAddress(library, "GetWindowDisplayAffinity");
	pSetWindowDisplayAffinity = (void *)GetProcAddress(library, "SetWindowDisplayAffinity");
	pSetWindowCompositionAttribute = (void *)GetProcAddress(library, "SetWindowCompositionAttribute");
	pWinHelpA = (void *)GetProcAddress(library, "WinHelpA");
	pWinHelpW = (void *)GetProcAddress(library, "WinHelpW");
	pSwitchToThisWindow = (void *)GetProcAddress(library, "SwitchToThisWindow");
	pGetWindowRect = (void *)GetProcAddress(library, "GetWindowRect");
	pGetWindowRgn = (void *)GetProcAddress(library, "GetWindowRgn");
	pGetWindowRgnBox = (void *)GetProcAddress(library, "GetWindowRgnBox");
	pSetWindowRgn = (void *)GetProcAddress(library, "SetWindowRgn");
	pGetClientRect = (void *)GetProcAddress(library, "GetClientRect");
	pWindowFromPoint = (void *)GetProcAddress(library, "WindowFromPoint");
	pChildWindowFromPoint = (void *)GetProcAddress(library, "ChildWindowFromPoint");
	pRealChildWindowFromPoint = (void *)GetProcAddress(library, "RealChildWindowFromPoint");
	pChildWindowFromPointEx = (void *)GetProcAddress(library, "ChildWindowFromPointEx");
	pMapWindowPoints = (void *)GetProcAddress(library, "MapWindowPoints");
	pClientToScreen = (void *)GetProcAddress(library, "ClientToScreen");
	pScreenToClient = (void *)GetProcAddress(library, "ScreenToClient");
	pIsIconic = (void *)GetProcAddress(library, "IsIconic");
	pIsZoomed = (void *)GetProcAddress(library, "IsZoomed");
	pAllowSetForegroundWindow = (void *)GetProcAddress(library, "AllowSetForegroundWindow");
	pLockSetForegroundWindow = (void *)GetProcAddress(library, "LockSetForegroundWindow");
	pBringWindowToTop = (void *)GetProcAddress(library, "BringWindowToTop");
	pMoveWindow = (void *)GetProcAddress(library, "MoveWindow");
	pShowWindowAsync = (void *)GetProcAddress(library, "ShowWindowAsync");
	pShowWindow = (void *)GetProcAddress(library, "ShowWindow");
	pGetInternalWindowPos = (void *)GetProcAddress(library, "GetInternalWindowPos");
	pGetWindowPlacement = (void *)GetProcAddress(library, "GetWindowPlacement");
	pSetWindowPlacement = (void *)GetProcAddress(library, "SetWindowPlacement");
	pAnimateWindow = (void *)GetProcAddress(library, "AnimateWindow");
	pSetInternalWindowPos = (void *)GetProcAddress(library, "SetInternalWindowPos");
	pSetWindowPos = (void *)GetProcAddress(library, "SetWindowPos");
	pBeginDeferWindowPos = (void *)GetProcAddress(library, "BeginDeferWindowPos");
	pDeferWindowPos = (void *)GetProcAddress(library, "DeferWindowPos");
	pEndDeferWindowPos = (void *)GetProcAddress(library, "EndDeferWindowPos");
	pArrangeIconicWindows = (void *)GetProcAddress(library, "ArrangeIconicWindows");
	pCallWindowProcA = (void *)GetProcAddress(library, "CallWindowProcA");
	pCallWindowProcW = (void *)GetProcAddress(library, "CallWindowProcW");
	pUserRegisterWowHandlers = (void *)GetProcAddress(library, "UserRegisterWowHandlers");
	pCreateWindowStationA = (void *)GetProcAddress(library, "CreateWindowStationA");
	pCreateWindowStationW = (void *)GetProcAddress(library, "CreateWindowStationW");
	pOpenWindowStationA = (void *)GetProcAddress(library, "OpenWindowStationA");
	pOpenWindowStationW = (void *)GetProcAddress(library, "OpenWindowStationW");
	pCloseWindowStation = (void *)GetProcAddress(library, "CloseWindowStation");
	pGetProcessWindowStation = (void *)GetProcAddress(library, "GetProcessWindowStation");
	pSetProcessWindowStation = (void *)GetProcAddress(library, "SetProcessWindowStation");
	pEnumWindowStationsA = (void *)GetProcAddress(library, "EnumWindowStationsA");
	pEnumWindowStationsW = (void *)GetProcAddress(library, "EnumWindowStationsW");
	pCreateDesktopA = (void *)GetProcAddress(library, "CreateDesktopA");
	pCreateDesktopW = (void *)GetProcAddress(library, "CreateDesktopW");
	pOpenDesktopA = (void *)GetProcAddress(library, "OpenDesktopA");
	pOpenDesktopW = (void *)GetProcAddress(library, "OpenDesktopW");
	pCloseDesktop = (void *)GetProcAddress(library, "CloseDesktop");
	pGetThreadDesktop = (void *)GetProcAddress(library, "GetThreadDesktop");
	pSetThreadDesktop = (void *)GetProcAddress(library, "SetThreadDesktop");
	pEnumDesktopsA = (void *)GetProcAddress(library, "EnumDesktopsA");
	pEnumDesktopsW = (void *)GetProcAddress(library, "EnumDesktopsW");
	pOpenInputDesktop = (void *)GetProcAddress(library, "OpenInputDesktop");
	pGetUserObjectInformationA = (void *)GetProcAddress(library, "GetUserObjectInformationA");
	pGetUserObjectInformationW = (void *)GetProcAddress(library, "GetUserObjectInformationW");
	pSetUserObjectInformationA = (void *)GetProcAddress(library, "SetUserObjectInformationA");
	pSetUserObjectInformationW = (void *)GetProcAddress(library, "SetUserObjectInformationW");
	pGetUserObjectSecurity = (void *)GetProcAddress(library, "GetUserObjectSecurity");
	pSetUserObjectSecurity = (void *)GetProcAddress(library, "SetUserObjectSecurity");
	pwvsprintfA = (void *)GetProcAddress(library, "wvsprintfA");
	pwvsprintfW = (void *)GetProcAddress(library, "wvsprintfW");
	pwsprintfA = (void *)GetProcAddress(library, "wsprintfA");
	pwsprintfW = (void *)GetProcAddress(library, "wsprintfW");
	initialized = TRUE;
}

void* wine_thunk_get_for_user32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pCreateCaret)
		return wine32a_CreateCaret;
	if (func == pDestroyCaret)
		return wine32a_DestroyCaret;
	if (func == pSetCaretPos)
		return wine32a_SetCaretPos;
	if (func == pHideCaret)
		return wine32a_HideCaret;
	if (func == pShowCaret)
		return wine32a_ShowCaret;
	if (func == pGetCaretPos)
		return wine32a_GetCaretPos;
	if (func == pSetCaretBlinkTime)
		return wine32a_SetCaretBlinkTime;
	if (func == pGetCaretBlinkTime)
		return wine32a_GetCaretBlinkTime;
	if (func == pRegisterClassA)
		return wine32a_RegisterClassA;
	if (func == pRegisterClassW)
		return wine32a_RegisterClassW;
	if (func == pRegisterClassExA)
		return wine32a_RegisterClassExA;
	if (func == pRegisterClassExW)
		return wine32a_RegisterClassExW;
	if (func == pUnregisterClassA)
		return wine32a_UnregisterClassA;
	if (func == pUnregisterClassW)
		return wine32a_UnregisterClassW;
	if (func == pGetClassWord)
		return wine32a_GetClassWord;
	if (func == pGetClassLongW)
		return wine32a_GetClassLongW;
	if (func == pGetClassLongA)
		return wine32a_GetClassLongA;
	if (func == pSetClassWord)
		return wine32a_SetClassWord;
	if (func == pSetClassLongW)
		return wine32a_SetClassLongW;
	if (func == pSetClassLongA)
		return wine32a_SetClassLongA;
	if (func == pGetClassNameA)
		return wine32a_GetClassNameA;
	if (func == pGetClassNameW)
		return wine32a_GetClassNameW;
	if (func == pRealGetWindowClassA)
		return wine32a_RealGetWindowClassA;
	if (func == pRealGetWindowClassW)
		return wine32a_RealGetWindowClassW;
	if (func == pGetClassInfoA)
		return wine32a_GetClassInfoA;
	if (func == pGetClassInfoW)
		return wine32a_GetClassInfoW;
	if (func == pGetClassInfoExA)
		return wine32a_GetClassInfoExA;
	if (func == pGetClassInfoExW)
		return wine32a_GetClassInfoExW;
	if (func == pGetClassLongPtrA)
		return wine32a_GetClassLongPtrA;
	if (func == pGetClassLongPtrW)
		return wine32a_GetClassLongPtrW;
	if (func == pSetClassLongPtrW)
		return wine32a_SetClassLongPtrW;
	if (func == pSetClassLongPtrA)
		return wine32a_SetClassLongPtrA;
	if (func == pRegisterClipboardFormatW)
		return wine32a_RegisterClipboardFormatW;
	if (func == pRegisterClipboardFormatA)
		return wine32a_RegisterClipboardFormatA;
	if (func == pGetClipboardFormatNameW)
		return wine32a_GetClipboardFormatNameW;
	if (func == pGetClipboardFormatNameA)
		return wine32a_GetClipboardFormatNameA;
	if (func == pOpenClipboard)
		return wine32a_OpenClipboard;
	if (func == pCloseClipboard)
		return wine32a_CloseClipboard;
	if (func == pEmptyClipboard)
		return wine32a_EmptyClipboard;
	if (func == pGetClipboardOwner)
		return wine32a_GetClipboardOwner;
	if (func == pGetOpenClipboardWindow)
		return wine32a_GetOpenClipboardWindow;
	if (func == pSetClipboardViewer)
		return wine32a_SetClipboardViewer;
	if (func == pGetClipboardViewer)
		return wine32a_GetClipboardViewer;
	if (func == pChangeClipboardChain)
		return wine32a_ChangeClipboardChain;
	if (func == pSetClipboardData)
		return wine32a_SetClipboardData;
	if (func == pCountClipboardFormats)
		return wine32a_CountClipboardFormats;
	if (func == pEnumClipboardFormats)
		return wine32a_EnumClipboardFormats;
	if (func == pIsClipboardFormatAvailable)
		return wine32a_IsClipboardFormatAvailable;
	if (func == pGetUpdatedClipboardFormats)
		return wine32a_GetUpdatedClipboardFormats;
	if (func == pGetClipboardData)
		return wine32a_GetClipboardData;
	if (func == pGetPriorityClipboardFormat)
		return wine32a_GetPriorityClipboardFormat;
	if (func == pGetClipboardSequenceNumber)
		return wine32a_GetClipboardSequenceNumber;
	if (func == pAddClipboardFormatListener)
		return wine32a_AddClipboardFormatListener;
	if (func == pRemoveClipboardFormatListener)
		return wine32a_RemoveClipboardFormatListener;
	if (func == pGetComboBoxInfo)
		return wine32a_GetComboBoxInfo;
	if (func == pCreateIconFromResourceEx)
		return wine32a_CreateIconFromResourceEx;
	if (func == pCreateIconFromResource)
		return wine32a_CreateIconFromResource;
	if (func == pCreateCursor)
		return wine32a_CreateCursor;
	if (func == pCreateIcon)
		return wine32a_CreateIcon;
	if (func == pCopyIcon)
		return wine32a_CopyIcon;
	if (func == pDestroyIcon)
		return wine32a_DestroyIcon;
	if (func == pDestroyCursor)
		return wine32a_DestroyCursor;
	if (func == pDrawIcon)
		return wine32a_DrawIcon;
	if (func == pSetCursor)
		return wine32a_SetCursor;
	if (func == pShowCursor)
		return wine32a_ShowCursor;
	if (func == pGetCursor)
		return wine32a_GetCursor;
	if (func == pClipCursor)
		return wine32a_ClipCursor;
	if (func == pGetClipCursor)
		return wine32a_GetClipCursor;
	if (func == pSetSystemCursor)
		return wine32a_SetSystemCursor;
	if (func == pLookupIconIdFromDirectoryEx)
		return wine32a_LookupIconIdFromDirectoryEx;
	if (func == pLookupIconIdFromDirectory)
		return wine32a_LookupIconIdFromDirectory;
	if (func == pLoadCursorW)
		return wine32a_LoadCursorW;
	if (func == pLoadCursorA)
		return wine32a_LoadCursorA;
	if (func == pLoadCursorFromFileW)
		return wine32a_LoadCursorFromFileW;
	if (func == pLoadCursorFromFileA)
		return wine32a_LoadCursorFromFileA;
	if (func == pLoadIconW)
		return wine32a_LoadIconW;
	if (func == pLoadIconA)
		return wine32a_LoadIconA;
	if (func == pGetCursorFrameInfo)
		return wine32a_GetCursorFrameInfo;
	if (func == pGetIconInfo)
		return wine32a_GetIconInfo;
	if (func == pGetIconInfoExA)
		return wine32a_GetIconInfoExA;
	if (func == pGetIconInfoExW)
		return wine32a_GetIconInfoExW;
	if (func == pCreateIconIndirect)
		return wine32a_CreateIconIndirect;
	if (func == pDrawIconEx)
		return wine32a_DrawIconEx;
	if (func == pLoadImageA)
		return wine32a_LoadImageA;
	if (func == pLoadImageW)
		return wine32a_LoadImageW;
	if (func == pCopyImage)
		return wine32a_CopyImage;
	if (func == pLoadBitmapW)
		return wine32a_LoadBitmapW;
	if (func == pLoadBitmapA)
		return wine32a_LoadBitmapA;
	if (func == pDdeConnectList)
		return wine32a_DdeConnectList;
	if (func == pDdeQueryNextServer)
		return wine32a_DdeQueryNextServer;
	if (func == pDdeDisconnectList)
		return wine32a_DdeDisconnectList;
	if (func == pDdeConnect)
		return wine32a_DdeConnect;
	if (func == pDdeReconnect)
		return wine32a_DdeReconnect;
	if (func == pDdeClientTransaction)
		return wine32a_DdeClientTransaction;
	if (func == pDdeAbandonTransaction)
		return wine32a_DdeAbandonTransaction;
	if (func == pDdeDisconnect)
		return wine32a_DdeDisconnect;
	if (func == pDdeImpersonateClient)
		return wine32a_DdeImpersonateClient;
	if (func == pPackDDElParam)
		return wine32a_PackDDElParam;
	if (func == pUnpackDDElParam)
		return wine32a_UnpackDDElParam;
	if (func == pFreeDDElParam)
		return wine32a_FreeDDElParam;
	if (func == pReuseDDElParam)
		return wine32a_ReuseDDElParam;
	if (func == pImpersonateDdeClientWindow)
		return wine32a_ImpersonateDdeClientWindow;
	if (func == pDdeSetQualityOfService)
		return wine32a_DdeSetQualityOfService;
	if (func == pDdeGetLastError)
		return wine32a_DdeGetLastError;
	if (func == pDdeQueryStringA)
		return wine32a_DdeQueryStringA;
	if (func == pDdeQueryStringW)
		return wine32a_DdeQueryStringW;
	if (func == pDdeCreateStringHandleA)
		return wine32a_DdeCreateStringHandleA;
	if (func == pDdeCreateStringHandleW)
		return wine32a_DdeCreateStringHandleW;
	if (func == pDdeFreeStringHandle)
		return wine32a_DdeFreeStringHandle;
	if (func == pDdeKeepStringHandle)
		return wine32a_DdeKeepStringHandle;
	if (func == pDdeCmpStringHandles)
		return wine32a_DdeCmpStringHandles;
	if (func == pDdeInitializeA)
		return wine32a_DdeInitializeA;
	if (func == pDdeInitializeW)
		return wine32a_DdeInitializeW;
	if (func == pDdeUninitialize)
		return wine32a_DdeUninitialize;
	if (func == pDdeCreateDataHandle)
		return wine32a_DdeCreateDataHandle;
	if (func == pDdeAddData)
		return wine32a_DdeAddData;
	if (func == pDdeGetData)
		return wine32a_DdeGetData;
	if (func == pDdeAccessData)
		return wine32a_DdeAccessData;
	if (func == pDdeUnaccessData)
		return wine32a_DdeUnaccessData;
	if (func == pDdeFreeDataHandle)
		return wine32a_DdeFreeDataHandle;
	if (func == pDdeEnableCallback)
		return wine32a_DdeEnableCallback;
	if (func == pDdeSetUserHandle)
		return wine32a_DdeSetUserHandle;
	if (func == pDdeQueryConvInfo)
		return wine32a_DdeQueryConvInfo;
	if (func == pDdePostAdvise)
		return wine32a_DdePostAdvise;
	if (func == pDdeNameService)
		return wine32a_DdeNameService;
	if (func == pDefDlgProcA)
		return wine32a_DefDlgProcA;
	if (func == pDefDlgProcW)
		return wine32a_DefDlgProcW;
	if (func == pDefWindowProcA)
		return wine32a_DefWindowProcA;
	if (func == pDefWindowProcW)
		return wine32a_DefWindowProcW;
	if (func == pPaintDesktop)
		return wine32a_PaintDesktop;
	if (func == pSetDeskWallPaper)
		return wine32a_SetDeskWallPaper;
	if (func == pCreateDialogParamA)
		return wine32a_CreateDialogParamA;
	if (func == pCreateDialogParamW)
		return wine32a_CreateDialogParamW;
	if (func == pCreateDialogIndirectParamAorW)
		return wine32a_CreateDialogIndirectParamAorW;
	if (func == pCreateDialogIndirectParamA)
		return wine32a_CreateDialogIndirectParamA;
	if (func == pCreateDialogIndirectParamW)
		return wine32a_CreateDialogIndirectParamW;
	if (func == pDialogBoxParamA)
		return wine32a_DialogBoxParamA;
	if (func == pDialogBoxParamW)
		return wine32a_DialogBoxParamW;
	if (func == pDialogBoxIndirectParamAorW)
		return wine32a_DialogBoxIndirectParamAorW;
	if (func == pDialogBoxIndirectParamA)
		return wine32a_DialogBoxIndirectParamA;
	if (func == pDialogBoxIndirectParamW)
		return wine32a_DialogBoxIndirectParamW;
	if (func == pEndDialog)
		return wine32a_EndDialog;
	if (func == pIsDialogMessageW)
		return wine32a_IsDialogMessageW;
	if (func == pGetDlgCtrlID)
		return wine32a_GetDlgCtrlID;
	if (func == pGetDlgItem)
		return wine32a_GetDlgItem;
	if (func == pSendDlgItemMessageA)
		return wine32a_SendDlgItemMessageA;
	if (func == pSendDlgItemMessageW)
		return wine32a_SendDlgItemMessageW;
	if (func == pSetDlgItemTextA)
		return wine32a_SetDlgItemTextA;
	if (func == pSetDlgItemTextW)
		return wine32a_SetDlgItemTextW;
	if (func == pGetDlgItemTextA)
		return wine32a_GetDlgItemTextA;
	if (func == pGetDlgItemTextW)
		return wine32a_GetDlgItemTextW;
	if (func == pSetDlgItemInt)
		return wine32a_SetDlgItemInt;
	if (func == pGetDlgItemInt)
		return wine32a_GetDlgItemInt;
	if (func == pCheckDlgButton)
		return wine32a_CheckDlgButton;
	if (func == pIsDlgButtonChecked)
		return wine32a_IsDlgButtonChecked;
	if (func == pCheckRadioButton)
		return wine32a_CheckRadioButton;
	if (func == pGetDialogBaseUnits)
		return wine32a_GetDialogBaseUnits;
	if (func == pMapDialogRect)
		return wine32a_MapDialogRect;
	if (func == pGetNextDlgGroupItem)
		return wine32a_GetNextDlgGroupItem;
	if (func == pGetNextDlgTabItem)
		return wine32a_GetNextDlgTabItem;
	if (func == pDlgDirSelectExA)
		return wine32a_DlgDirSelectExA;
	if (func == pDlgDirSelectExW)
		return wine32a_DlgDirSelectExW;
	if (func == pDlgDirSelectComboBoxExA)
		return wine32a_DlgDirSelectComboBoxExA;
	if (func == pDlgDirSelectComboBoxExW)
		return wine32a_DlgDirSelectComboBoxExW;
	if (func == pDlgDirListA)
		return wine32a_DlgDirListA;
	if (func == pDlgDirListW)
		return wine32a_DlgDirListW;
	if (func == pDlgDirListComboBoxA)
		return wine32a_DlgDirListComboBoxA;
	if (func == pDlgDirListComboBoxW)
		return wine32a_DlgDirListComboBoxW;
	if (func == pPrivateExtractIconsW)
		return wine32a_PrivateExtractIconsW;
	if (func == pPrivateExtractIconsA)
		return wine32a_PrivateExtractIconsA;
	if (func == pPrivateExtractIconExW)
		return wine32a_PrivateExtractIconExW;
	if (func == pPrivateExtractIconExA)
		return wine32a_PrivateExtractIconExA;
	if (func == pSetActiveWindow)
		return wine32a_SetActiveWindow;
	if (func == pSetFocus)
		return wine32a_SetFocus;
	if (func == pSetForegroundWindow)
		return wine32a_SetForegroundWindow;
	if (func == pGetActiveWindow)
		return wine32a_GetActiveWindow;
	if (func == pGetFocus)
		return wine32a_GetFocus;
	if (func == pGetForegroundWindow)
		return wine32a_GetForegroundWindow;
	if (func == pSetShellWindowEx)
		return wine32a_SetShellWindowEx;
	if (func == pSetShellWindow)
		return wine32a_SetShellWindow;
	if (func == pGetShellWindow)
		return wine32a_GetShellWindow;
	if (func == pSetProgmanWindow)
		return wine32a_SetProgmanWindow;
	if (func == pGetProgmanWindow)
		return wine32a_GetProgmanWindow;
	if (func == pSetTaskmanWindow)
		return wine32a_SetTaskmanWindow;
	if (func == pGetTaskmanWindow)
		return wine32a_GetTaskmanWindow;
	if (func == pSetWindowsHookA)
		return wine32a_SetWindowsHookA;
	if (func == pSetWindowsHookW)
		return wine32a_SetWindowsHookW;
	if (func == pSetWindowsHookExA)
		return wine32a_SetWindowsHookExA;
	if (func == pSetWindowsHookExW)
		return wine32a_SetWindowsHookExW;
	if (func == pUnhookWindowsHook)
		return wine32a_UnhookWindowsHook;
	if (func == pUnhookWindowsHookEx)
		return wine32a_UnhookWindowsHookEx;
	if (func == pCallNextHookEx)
		return wine32a_CallNextHookEx;
	if (func == pCallMsgFilterA)
		return wine32a_CallMsgFilterA;
	if (func == pCallMsgFilterW)
		return wine32a_CallMsgFilterW;
	if (func == pSetWinEventHook)
		return wine32a_SetWinEventHook;
	if (func == pUnhookWinEvent)
		return wine32a_UnhookWinEvent;
	if (func == pNotifyWinEvent)
		return wine32a_NotifyWinEvent;
	if (func == pIsWinEventHookInstalled)
		return wine32a_IsWinEventHookInstalled;
	if (func == p__wine_send_input)
		return wine32a___wine_send_input;
	if (func == pSendInput)
		return wine32a_SendInput;
	if (func == pkeybd_event)
		return wine32a_keybd_event;
	if (func == pmouse_event)
		return wine32a_mouse_event;
	if (func == pGetCursorPos)
		return wine32a_GetCursorPos;
	if (func == pGetCursorInfo)
		return wine32a_GetCursorInfo;
	if (func == pSetCursorPos)
		return wine32a_SetCursorPos;
	if (func == pSetCapture)
		return wine32a_SetCapture;
	if (func == pReleaseCapture)
		return wine32a_ReleaseCapture;
	if (func == pGetCapture)
		return wine32a_GetCapture;
	if (func == pGetAsyncKeyState)
		return wine32a_GetAsyncKeyState;
	if (func == pGetQueueStatus)
		return wine32a_GetQueueStatus;
	if (func == pGetInputState)
		return wine32a_GetInputState;
	if (func == pGetLastInputInfo)
		return wine32a_GetLastInputInfo;
	if (func == pAttachThreadInput)
		return wine32a_AttachThreadInput;
	if (func == pGetKeyState)
		return wine32a_GetKeyState;
	if (func == pGetKeyboardState)
		return wine32a_GetKeyboardState;
	if (func == pSetKeyboardState)
		return wine32a_SetKeyboardState;
	if (func == pVkKeyScanA)
		return wine32a_VkKeyScanA;
	if (func == pVkKeyScanW)
		return wine32a_VkKeyScanW;
	if (func == pVkKeyScanExA)
		return wine32a_VkKeyScanExA;
	if (func == pVkKeyScanExW)
		return wine32a_VkKeyScanExW;
	if (func == pOemKeyScan)
		return wine32a_OemKeyScan;
	if (func == pGetKeyboardType)
		return wine32a_GetKeyboardType;
	if (func == pMapVirtualKeyA)
		return wine32a_MapVirtualKeyA;
	if (func == pMapVirtualKeyW)
		return wine32a_MapVirtualKeyW;
	if (func == pMapVirtualKeyExA)
		return wine32a_MapVirtualKeyExA;
	if (func == pMapVirtualKeyExW)
		return wine32a_MapVirtualKeyExW;
	if (func == pGetKBCodePage)
		return wine32a_GetKBCodePage;
	if (func == pGetKeyboardLayout)
		return wine32a_GetKeyboardLayout;
	if (func == pGetKeyboardLayoutNameA)
		return wine32a_GetKeyboardLayoutNameA;
	if (func == pGetKeyboardLayoutNameW)
		return wine32a_GetKeyboardLayoutNameW;
	if (func == pGetKeyNameTextA)
		return wine32a_GetKeyNameTextA;
	if (func == pGetKeyNameTextW)
		return wine32a_GetKeyNameTextW;
	if (func == pToUnicode)
		return wine32a_ToUnicode;
	if (func == pToUnicodeEx)
		return wine32a_ToUnicodeEx;
	if (func == pToAscii)
		return wine32a_ToAscii;
	if (func == pToAsciiEx)
		return wine32a_ToAsciiEx;
	if (func == pActivateKeyboardLayout)
		return wine32a_ActivateKeyboardLayout;
	if (func == pBlockInput)
		return wine32a_BlockInput;
	if (func == pGetKeyboardLayoutList)
		return wine32a_GetKeyboardLayoutList;
	if (func == pRegisterHotKey)
		return wine32a_RegisterHotKey;
	if (func == pUnregisterHotKey)
		return wine32a_UnregisterHotKey;
	if (func == pLoadKeyboardLayoutW)
		return wine32a_LoadKeyboardLayoutW;
	if (func == pLoadKeyboardLayoutA)
		return wine32a_LoadKeyboardLayoutA;
	if (func == pUnloadKeyboardLayout)
		return wine32a_UnloadKeyboardLayout;
	if (func == pTrackMouseEvent)
		return wine32a_TrackMouseEvent;
	if (func == pGetMouseMovePointsEx)
		return wine32a_GetMouseMovePointsEx;
	if (func == pEnableMouseInPointer)
		return wine32a_EnableMouseInPointer;
	if (func == pGetListBoxInfo)
		return wine32a_GetListBoxInfo;
	if (func == pCharNextA)
		return wine32a_CharNextA;
	if (func == pCharNextExA)
		return wine32a_CharNextExA;
	if (func == pCharNextExW)
		return wine32a_CharNextExW;
	if (func == pCharNextW)
		return wine32a_CharNextW;
	if (func == pCharPrevA)
		return wine32a_CharPrevA;
	if (func == pCharPrevExA)
		return wine32a_CharPrevExA;
	if (func == pCharPrevExW)
		return wine32a_CharPrevExW;
	if (func == pCharPrevW)
		return wine32a_CharPrevW;
	if (func == pCharToOemA)
		return wine32a_CharToOemA;
	if (func == pCharToOemBuffA)
		return wine32a_CharToOemBuffA;
	if (func == pCharToOemBuffW)
		return wine32a_CharToOemBuffW;
	if (func == pCharToOemW)
		return wine32a_CharToOemW;
	if (func == pOemToCharA)
		return wine32a_OemToCharA;
	if (func == pOemToCharBuffA)
		return wine32a_OemToCharBuffA;
	if (func == pOemToCharBuffW)
		return wine32a_OemToCharBuffW;
	if (func == pOemToCharW)
		return wine32a_OemToCharW;
	if (func == pCharLowerA)
		return wine32a_CharLowerA;
	if (func == pCharUpperA)
		return wine32a_CharUpperA;
	if (func == pCharLowerW)
		return wine32a_CharLowerW;
	if (func == pCharUpperW)
		return wine32a_CharUpperW;
	if (func == pCharLowerBuffA)
		return wine32a_CharLowerBuffA;
	if (func == pCharLowerBuffW)
		return wine32a_CharLowerBuffW;
	if (func == pCharUpperBuffA)
		return wine32a_CharUpperBuffA;
	if (func == pCharUpperBuffW)
		return wine32a_CharUpperBuffW;
	if (func == pIsCharLowerA)
		return wine32a_IsCharLowerA;
	if (func == pIsCharLowerW)
		return wine32a_IsCharLowerW;
	if (func == pIsCharUpperA)
		return wine32a_IsCharUpperA;
	if (func == pIsCharUpperW)
		return wine32a_IsCharUpperW;
	if (func == pIsCharAlphaNumericA)
		return wine32a_IsCharAlphaNumericA;
	if (func == pIsCharAlphaNumericW)
		return wine32a_IsCharAlphaNumericW;
	if (func == pIsCharAlphaA)
		return wine32a_IsCharAlphaA;
	if (func == pIsCharAlphaW)
		return wine32a_IsCharAlphaW;
	if (func == pDefFrameProcA)
		return wine32a_DefFrameProcA;
	if (func == pDefFrameProcW)
		return wine32a_DefFrameProcW;
	if (func == pDefMDIChildProcA)
		return wine32a_DefMDIChildProcA;
	if (func == pDefMDIChildProcW)
		return wine32a_DefMDIChildProcW;
	if (func == pCreateMDIWindowA)
		return wine32a_CreateMDIWindowA;
	if (func == pCreateMDIWindowW)
		return wine32a_CreateMDIWindowW;
	if (func == pTranslateMDISysAccel)
		return wine32a_TranslateMDISysAccel;
	if (func == pCalcChildScroll)
		return wine32a_CalcChildScroll;
	if (func == pScrollChildren)
		return wine32a_ScrollChildren;
	if (func == pCascadeWindows)
		return wine32a_CascadeWindows;
	if (func == pCascadeChildWindows)
		return wine32a_CascadeChildWindows;
	if (func == pTileWindows)
		return wine32a_TileWindows;
	if (func == pTileChildWindows)
		return wine32a_TileChildWindows;
	if (func == pDrawMenuBarTemp)
		return wine32a_DrawMenuBarTemp;
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
	if (func == pSendMessageTimeoutW)
		return wine32a_SendMessageTimeoutW;
	if (func == pSendMessageTimeoutA)
		return wine32a_SendMessageTimeoutA;
	if (func == pSendMessageW)
		return wine32a_SendMessageW;
	if (func == pSendMessageA)
		return wine32a_SendMessageA;
	if (func == pSendNotifyMessageA)
		return wine32a_SendNotifyMessageA;
	if (func == pSendNotifyMessageW)
		return wine32a_SendNotifyMessageW;
	if (func == pSendMessageCallbackA)
		return wine32a_SendMessageCallbackA;
	if (func == pSendMessageCallbackW)
		return wine32a_SendMessageCallbackW;
	if (func == pReplyMessage)
		return wine32a_ReplyMessage;
	if (func == pInSendMessage)
		return wine32a_InSendMessage;
	if (func == pInSendMessageEx)
		return wine32a_InSendMessageEx;
	if (func == pPostMessageA)
		return wine32a_PostMessageA;
	if (func == pPostMessageW)
		return wine32a_PostMessageW;
	if (func == pPostThreadMessageA)
		return wine32a_PostThreadMessageA;
	if (func == pPostThreadMessageW)
		return wine32a_PostThreadMessageW;
	if (func == pPostQuitMessage)
		return wine32a_PostQuitMessage;
	if (func == pPeekMessageW)
		return wine32a_PeekMessageW;
	if (func == pPeekMessageA)
		return wine32a_PeekMessageA;
	if (func == pGetMessageW)
		return wine32a_GetMessageW;
	if (func == pGetMessageA)
		return wine32a_GetMessageA;
	if (func == pIsDialogMessageA)
		return wine32a_IsDialogMessageA;
	if (func == pTranslateMessage)
		return wine32a_TranslateMessage;
	if (func == pDispatchMessageA)
		return wine32a_DispatchMessageA;
	if (func == pDispatchMessageW)
		return wine32a_DispatchMessageW;
	if (func == pGetMessagePos)
		return wine32a_GetMessagePos;
	if (func == pGetMessageTime)
		return wine32a_GetMessageTime;
	if (func == pGetMessageExtraInfo)
		return wine32a_GetMessageExtraInfo;
	if (func == pSetMessageExtraInfo)
		return wine32a_SetMessageExtraInfo;
	if (func == pGetCurrentInputMessageSource)
		return wine32a_GetCurrentInputMessageSource;
	if (func == pWaitMessage)
		return wine32a_WaitMessage;
	if (func == pMsgWaitForMultipleObjectsEx)
		return wine32a_MsgWaitForMultipleObjectsEx;
	if (func == pMsgWaitForMultipleObjects)
		return wine32a_MsgWaitForMultipleObjects;
	if (func == pWaitForInputIdle)
		return wine32a_WaitForInputIdle;
	if (func == pRegisterWindowMessageA)
		return wine32a_RegisterWindowMessageA;
	if (func == pRegisterWindowMessageW)
		return wine32a_RegisterWindowMessageW;
	if (func == pBroadcastSystemMessageA)
		return wine32a_BroadcastSystemMessageA;
	if (func == pBroadcastSystemMessageW)
		return wine32a_BroadcastSystemMessageW;
	if (func == pBroadcastSystemMessageExA)
		return wine32a_BroadcastSystemMessageExA;
	if (func == pBroadcastSystemMessageExW)
		return wine32a_BroadcastSystemMessageExW;
	if (func == pSetMessageQueue)
		return wine32a_SetMessageQueue;
	if (func == pMessageBeep)
		return wine32a_MessageBeep;
	if (func == pSetCoalescableTimer)
		return wine32a_SetCoalescableTimer;
	if (func == pSetTimer)
		return wine32a_SetTimer;
	if (func == pSetSystemTimer)
		return wine32a_SetSystemTimer;
	if (func == pKillTimer)
		return wine32a_KillTimer;
	if (func == pKillSystemTimer)
		return wine32a_KillSystemTimer;
	if (func == pIsGUIThread)
		return wine32a_IsGUIThread;
	if (func == pGetGUIThreadInfo)
		return wine32a_GetGUIThreadInfo;
	if (func == pIsHungAppWindow)
		return wine32a_IsHungAppWindow;
	if (func == pChangeWindowMessageFilter)
		return wine32a_ChangeWindowMessageFilter;
	if (func == pChangeWindowMessageFilterEx)
		return wine32a_ChangeWindowMessageFilterEx;
	if (func == pUserSignalProc)
		return wine32a_UserSignalProc;
	if (func == pSetLastErrorEx)
		return wine32a_SetLastErrorEx;
	if (func == pGetAltTabInfoA)
		return wine32a_GetAltTabInfoA;
	if (func == pGetAltTabInfoW)
		return wine32a_GetAltTabInfoW;
	if (func == pSetDebugErrorLevel)
		return wine32a_SetDebugErrorLevel;
	if (func == pSetWindowStationUser)
		return wine32a_SetWindowStationUser;
	if (func == pRegisterLogonProcess)
		return wine32a_RegisterLogonProcess;
	if (func == pSetLogonNotifyWindow)
		return wine32a_SetLogonNotifyWindow;
	if (func == pQueryDisplayConfig)
		return wine32a_QueryDisplayConfig;
	if (func == pRegisterSystemThread)
		return wine32a_RegisterSystemThread;
	if (func == pRegisterShellHookWindow)
		return wine32a_RegisterShellHookWindow;
	if (func == pDeregisterShellHookWindow)
		return wine32a_DeregisterShellHookWindow;
	if (func == pRegisterTasklist)
		return wine32a_RegisterTasklist;
	if (func == pRegisterDeviceNotificationA)
		return wine32a_RegisterDeviceNotificationA;
	if (func == pRegisterDeviceNotificationW)
		return wine32a_RegisterDeviceNotificationW;
	if (func == pUnregisterDeviceNotification)
		return wine32a_UnregisterDeviceNotification;
	if (func == pGetAppCompatFlags)
		return wine32a_GetAppCompatFlags;
	if (func == pGetAppCompatFlags2)
		return wine32a_GetAppCompatFlags2;
	if (func == pAlignRects)
		return wine32a_AlignRects;
	if (func == pLoadLocalFonts)
		return wine32a_LoadLocalFonts;
	if (func == pUser32InitializeImmEntryTable)
		return wine32a_User32InitializeImmEntryTable;
	if (func == pWINNLSGetIMEHotkey)
		return wine32a_WINNLSGetIMEHotkey;
	if (func == pWINNLSEnableIME)
		return wine32a_WINNLSEnableIME;
	if (func == pWINNLSGetEnableStatus)
		return wine32a_WINNLSGetEnableStatus;
	if (func == pSendIMEMessageExA)
		return wine32a_SendIMEMessageExA;
	if (func == pSendIMEMessageExW)
		return wine32a_SendIMEMessageExW;
	if (func == pDisableProcessWindowsGhosting)
		return wine32a_DisableProcessWindowsGhosting;
	if (func == pUserHandleGrantAccess)
		return wine32a_UserHandleGrantAccess;
	if (func == pRegisterPowerSettingNotification)
		return wine32a_RegisterPowerSettingNotification;
	if (func == pUnregisterPowerSettingNotification)
		return wine32a_UnregisterPowerSettingNotification;
	if (func == pGetGestureConfig)
		return wine32a_GetGestureConfig;
	if (func == pSetGestureConfig)
		return wine32a_SetGestureConfig;
	if (func == pIsTouchWindow)
		return wine32a_IsTouchWindow;
	if (func == pIsWindowRedirectedForPrint)
		return wine32a_IsWindowRedirectedForPrint;
	if (func == pGetDisplayConfigBufferSizes)
		return wine32a_GetDisplayConfigBufferSizes;
	if (func == pRegisterPointerDeviceNotifications)
		return wine32a_RegisterPointerDeviceNotifications;
	if (func == pGetPointerDevices)
		return wine32a_GetPointerDevices;
	if (func == pRegisterTouchHitTestingWindow)
		return wine32a_RegisterTouchHitTestingWindow;
	if (func == pGetPointerType)
		return wine32a_GetPointerType;
	if (func == pMessageBoxA)
		return wine32a_MessageBoxA;
	if (func == pMessageBoxW)
		return wine32a_MessageBoxW;
	if (func == pMessageBoxExA)
		return wine32a_MessageBoxExA;
	if (func == pMessageBoxExW)
		return wine32a_MessageBoxExW;
	if (func == pMessageBoxTimeoutA)
		return wine32a_MessageBoxTimeoutA;
	if (func == pMessageBoxTimeoutW)
		return wine32a_MessageBoxTimeoutW;
	if (func == pMessageBoxIndirectA)
		return wine32a_MessageBoxIndirectA;
	if (func == pMessageBoxIndirectW)
		return wine32a_MessageBoxIndirectW;
	if (func == pDrawCaption)
		return wine32a_DrawCaption;
	if (func == pDrawCaptionTempA)
		return wine32a_DrawCaptionTempA;
	if (func == pDrawCaptionTempW)
		return wine32a_DrawCaptionTempW;
	if (func == pAdjustWindowRect)
		return wine32a_AdjustWindowRect;
	if (func == pAdjustWindowRectEx)
		return wine32a_AdjustWindowRectEx;
	if (func == pAdjustWindowRectExForDpi)
		return wine32a_AdjustWindowRectExForDpi;
	if (func == pGetTitleBarInfo)
		return wine32a_GetTitleBarInfo;
	if (func == pBeginPaint)
		return wine32a_BeginPaint;
	if (func == pEndPaint)
		return wine32a_EndPaint;
	if (func == pGetDCEx)
		return wine32a_GetDCEx;
	if (func == pGetDC)
		return wine32a_GetDC;
	if (func == pGetWindowDC)
		return wine32a_GetWindowDC;
	if (func == pReleaseDC)
		return wine32a_ReleaseDC;
	if (func == pWindowFromDC)
		return wine32a_WindowFromDC;
	if (func == pLockWindowUpdate)
		return wine32a_LockWindowUpdate;
	if (func == pRedrawWindow)
		return wine32a_RedrawWindow;
	if (func == pUpdateWindow)
		return wine32a_UpdateWindow;
	if (func == pInvalidateRgn)
		return wine32a_InvalidateRgn;
	if (func == pInvalidateRect)
		return wine32a_InvalidateRect;
	if (func == pValidateRgn)
		return wine32a_ValidateRgn;
	if (func == pValidateRect)
		return wine32a_ValidateRect;
	if (func == pGetUpdateRgn)
		return wine32a_GetUpdateRgn;
	if (func == pGetUpdateRect)
		return wine32a_GetUpdateRect;
	if (func == pExcludeUpdateRgn)
		return wine32a_ExcludeUpdateRgn;
	if (func == pScrollWindowEx)
		return wine32a_ScrollWindowEx;
	if (func == pScrollWindow)
		return wine32a_ScrollWindow;
	if (func == pScrollDC)
		return wine32a_ScrollDC;
	if (func == pPrintWindow)
		return wine32a_PrintWindow;
	if (func == pEnumPropsA)
		return wine32a_EnumPropsA;
	if (func == pEnumPropsW)
		return wine32a_EnumPropsW;
	if (func == pGetPropA)
		return wine32a_GetPropA;
	if (func == pGetPropW)
		return wine32a_GetPropW;
	if (func == pSetPropA)
		return wine32a_SetPropA;
	if (func == pSetPropW)
		return wine32a_SetPropW;
	if (func == pRemovePropA)
		return wine32a_RemovePropA;
	if (func == pRemovePropW)
		return wine32a_RemovePropW;
	if (func == pEnumPropsExA)
		return wine32a_EnumPropsExA;
	if (func == pEnumPropsExW)
		return wine32a_EnumPropsExW;
	if (func == pGetRawInputDeviceList)
		return wine32a_GetRawInputDeviceList;
	if (func == pRegisterRawInputDevices)
		return wine32a_RegisterRawInputDevices;
	if (func == pGetRawInputData)
		return wine32a_GetRawInputData;
	if (func == pGetRawInputBuffer)
		return wine32a_GetRawInputBuffer;
	if (func == pGetRawInputDeviceInfoA)
		return wine32a_GetRawInputDeviceInfoA;
	if (func == pGetRawInputDeviceInfoW)
		return wine32a_GetRawInputDeviceInfoW;
	if (func == pGetRegisteredRawInputDevices)
		return wine32a_GetRegisteredRawInputDevices;
	if (func == pDefRawInputProc)
		return wine32a_DefRawInputProc;
	if (func == pLoadAcceleratorsW)
		return wine32a_LoadAcceleratorsW;
	if (func == pLoadAcceleratorsA)
		return wine32a_LoadAcceleratorsA;
	if (func == pCopyAcceleratorTableA)
		return wine32a_CopyAcceleratorTableA;
	if (func == pCopyAcceleratorTableW)
		return wine32a_CopyAcceleratorTableW;
	if (func == pCreateAcceleratorTableA)
		return wine32a_CreateAcceleratorTableA;
	if (func == pCreateAcceleratorTableW)
		return wine32a_CreateAcceleratorTableW;
	if (func == pDestroyAcceleratorTable)
		return wine32a_DestroyAcceleratorTable;
	if (func == pLoadStringW)
		return wine32a_LoadStringW;
	if (func == pLoadStringA)
		return wine32a_LoadStringA;
	if (func == pGetGuiResources)
		return wine32a_GetGuiResources;
	if (func == pSetScrollInfo)
		return wine32a_SetScrollInfo;
	if (func == pGetScrollInfo)
		return wine32a_GetScrollInfo;
	if (func == pGetScrollBarInfo)
		return wine32a_GetScrollBarInfo;
	if (func == pSetScrollPos)
		return wine32a_SetScrollPos;
	if (func == pGetScrollPos)
		return wine32a_GetScrollPos;
	if (func == pSetScrollRange)
		return wine32a_SetScrollRange;
	if (func == pGetScrollRange)
		return wine32a_GetScrollRange;
	if (func == pShowScrollBar)
		return wine32a_ShowScrollBar;
	if (func == pEnableScrollBar)
		return wine32a_EnableScrollBar;
	if (func == pSystemParametersInfoForDpi)
		return wine32a_SystemParametersInfoForDpi;
	if (func == pSystemParametersInfoW)
		return wine32a_SystemParametersInfoW;
	if (func == pSystemParametersInfoA)
		return wine32a_SystemParametersInfoA;
	if (func == pGetSystemMetrics)
		return wine32a_GetSystemMetrics;
	if (func == pGetSystemMetricsForDpi)
		return wine32a_GetSystemMetricsForDpi;
	if (func == pSwapMouseButton)
		return wine32a_SwapMouseButton;
	if (func == pSetDoubleClickTime)
		return wine32a_SetDoubleClickTime;
	if (func == pGetDoubleClickTime)
		return wine32a_GetDoubleClickTime;
	if (func == pGetSysColor)
		return wine32a_GetSysColor;
	if (func == pSetSysColors)
		return wine32a_SetSysColors;
	if (func == pSetSysColorsTemp)
		return wine32a_SetSysColorsTemp;
	if (func == pGetSysColorBrush)
		return wine32a_GetSysColorBrush;
	if (func == pChangeDisplaySettingsA)
		return wine32a_ChangeDisplaySettingsA;
	if (func == pChangeDisplaySettingsW)
		return wine32a_ChangeDisplaySettingsW;
	if (func == pChangeDisplaySettingsExA)
		return wine32a_ChangeDisplaySettingsExA;
	if (func == pChangeDisplaySettingsExW)
		return wine32a_ChangeDisplaySettingsExW;
	if (func == pDisplayConfigGetDeviceInfo)
		return wine32a_DisplayConfigGetDeviceInfo;
	if (func == pEnumDisplaySettingsW)
		return wine32a_EnumDisplaySettingsW;
	if (func == pEnumDisplaySettingsA)
		return wine32a_EnumDisplaySettingsA;
	if (func == pEnumDisplaySettingsExA)
		return wine32a_EnumDisplaySettingsExA;
	if (func == pEnumDisplaySettingsExW)
		return wine32a_EnumDisplaySettingsExW;
	if (func == pSetProcessDpiAwarenessContext)
		return wine32a_SetProcessDpiAwarenessContext;
	if (func == pGetProcessDpiAwarenessInternal)
		return wine32a_GetProcessDpiAwarenessInternal;
	if (func == pSetProcessDpiAwarenessInternal)
		return wine32a_SetProcessDpiAwarenessInternal;
	if (func == pAreDpiAwarenessContextsEqual)
		return wine32a_AreDpiAwarenessContextsEqual;
	if (func == pGetAwarenessFromDpiAwarenessContext)
		return wine32a_GetAwarenessFromDpiAwarenessContext;
	if (func == pIsValidDpiAwarenessContext)
		return wine32a_IsValidDpiAwarenessContext;
	if (func == pSetProcessDPIAware)
		return wine32a_SetProcessDPIAware;
	if (func == pIsProcessDPIAware)
		return wine32a_IsProcessDPIAware;
	if (func == pGetDpiForSystem)
		return wine32a_GetDpiForSystem;
	if (func == pGetDpiForMonitorInternal)
		return wine32a_GetDpiForMonitorInternal;
	if (func == pGetThreadDpiAwarenessContext)
		return wine32a_GetThreadDpiAwarenessContext;
	if (func == pSetThreadDpiAwarenessContext)
		return wine32a_SetThreadDpiAwarenessContext;
	if (func == pLogicalToPhysicalPointForPerMonitorDPI)
		return wine32a_LogicalToPhysicalPointForPerMonitorDPI;
	if (func == pPhysicalToLogicalPointForPerMonitorDPI)
		return wine32a_PhysicalToLogicalPointForPerMonitorDPI;
	if (func == pMonitorFromRect)
		return wine32a_MonitorFromRect;
	if (func == pMonitorFromPoint)
		return wine32a_MonitorFromPoint;
	if (func == pMonitorFromWindow)
		return wine32a_MonitorFromWindow;
	if (func == pGetMonitorInfoA)
		return wine32a_GetMonitorInfoA;
	if (func == pGetMonitorInfoW)
		return wine32a_GetMonitorInfoW;
	if (func == pEnumDisplayMonitors)
		return wine32a_EnumDisplayMonitors;
	if (func == pEnumDisplayDevicesA)
		return wine32a_EnumDisplayDevicesA;
	if (func == pEnumDisplayDevicesW)
		return wine32a_EnumDisplayDevicesW;
	if (func == pGetAutoRotationState)
		return wine32a_GetAutoRotationState;
	if (func == pGetDisplayAutoRotationPreferences)
		return wine32a_GetDisplayAutoRotationPreferences;
	if (func == pGetPhysicalCursorPos)
		return wine32a_GetPhysicalCursorPos;
	if (func == pSetPhysicalCursorPos)
		return wine32a_SetPhysicalCursorPos;
	if (func == pLogicalToPhysicalPoint)
		return wine32a_LogicalToPhysicalPoint;
	if (func == pPhysicalToLogicalPoint)
		return wine32a_PhysicalToLogicalPoint;
	if (func == pDrawTextExW)
		return wine32a_DrawTextExW;
	if (func == pDrawTextExA)
		return wine32a_DrawTextExA;
	if (func == pDrawTextW)
		return wine32a_DrawTextW;
	if (func == pDrawTextA)
		return wine32a_DrawTextA;
	if (func == pGrayStringA)
		return wine32a_GrayStringA;
	if (func == pGrayStringW)
		return wine32a_GrayStringW;
	if (func == pTabbedTextOutA)
		return wine32a_TabbedTextOutA;
	if (func == pTabbedTextOutW)
		return wine32a_TabbedTextOutW;
	if (func == pGetTabbedTextExtentA)
		return wine32a_GetTabbedTextExtentA;
	if (func == pGetTabbedTextExtentW)
		return wine32a_GetTabbedTextExtentW;
	if (func == pDrawEdge)
		return wine32a_DrawEdge;
	if (func == pDrawFrameControl)
		return wine32a_DrawFrameControl;
	if (func == pSetRect)
		return wine32a_SetRect;
	if (func == pSetRectEmpty)
		return wine32a_SetRectEmpty;
	if (func == pCopyRect)
		return wine32a_CopyRect;
	if (func == pIsRectEmpty)
		return wine32a_IsRectEmpty;
	if (func == pPtInRect)
		return wine32a_PtInRect;
	if (func == pOffsetRect)
		return wine32a_OffsetRect;
	if (func == pInflateRect)
		return wine32a_InflateRect;
	if (func == pIntersectRect)
		return wine32a_IntersectRect;
	if (func == pUnionRect)
		return wine32a_UnionRect;
	if (func == pEqualRect)
		return wine32a_EqualRect;
	if (func == pSubtractRect)
		return wine32a_SubtractRect;
	if (func == pFillRect)
		return wine32a_FillRect;
	if (func == pInvertRect)
		return wine32a_InvertRect;
	if (func == pFrameRect)
		return wine32a_FrameRect;
	if (func == pDrawFocusRect)
		return wine32a_DrawFocusRect;
	if (func == pDrawAnimatedRects)
		return wine32a_DrawAnimatedRects;
	if (func == pDrawStateA)
		return wine32a_DrawStateA;
	if (func == pDrawStateW)
		return wine32a_DrawStateW;
	if (func == pUserRealizePalette)
		return wine32a_UserRealizePalette;
	if (func == pExitWindowsEx)
		return wine32a_ExitWindowsEx;
	if (func == pLockWorkStation)
		return wine32a_LockWorkStation;
	if (func == pRegisterServicesProcess)
		return wine32a_RegisterServicesProcess;
	if (func == pShutdownBlockReasonCreate)
		return wine32a_ShutdownBlockReasonCreate;
	if (func == pShutdownBlockReasonDestroy)
		return wine32a_ShutdownBlockReasonDestroy;
	if (func == pCreateWindowExA)
		return wine32a_CreateWindowExA;
	if (func == pCreateWindowExW)
		return wine32a_CreateWindowExW;
	if (func == pDestroyWindow)
		return wine32a_DestroyWindow;
	if (func == pCloseWindow)
		return wine32a_CloseWindow;
	if (func == pOpenIcon)
		return wine32a_OpenIcon;
	if (func == pFindWindowExW)
		return wine32a_FindWindowExW;
	if (func == pFindWindowA)
		return wine32a_FindWindowA;
	if (func == pFindWindowExA)
		return wine32a_FindWindowExA;
	if (func == pFindWindowW)
		return wine32a_FindWindowW;
	if (func == pGetDesktopWindow)
		return wine32a_GetDesktopWindow;
	if (func == pEnableWindow)
		return wine32a_EnableWindow;
	if (func == pIsWindowEnabled)
		return wine32a_IsWindowEnabled;
	if (func == pIsWindowUnicode)
		return wine32a_IsWindowUnicode;
	if (func == pGetWindowDpiAwarenessContext)
		return wine32a_GetWindowDpiAwarenessContext;
	if (func == pGetDpiForWindow)
		return wine32a_GetDpiForWindow;
	if (func == pGetWindowWord)
		return wine32a_GetWindowWord;
	if (func == pGetWindowLongA)
		return wine32a_GetWindowLongA;
	if (func == pGetWindowLongW)
		return wine32a_GetWindowLongW;
	if (func == pSetWindowWord)
		return wine32a_SetWindowWord;
	if (func == pSetWindowLongA)
		return wine32a_SetWindowLongA;
	if (func == pSetWindowLongW)
		return wine32a_SetWindowLongW;
	if (func == pGetWindowTextA)
		return wine32a_GetWindowTextA;
	if (func == pInternalGetWindowText)
		return wine32a_InternalGetWindowText;
	if (func == pGetWindowTextW)
		return wine32a_GetWindowTextW;
	if (func == pSetWindowTextA)
		return wine32a_SetWindowTextA;
	if (func == pSetWindowTextW)
		return wine32a_SetWindowTextW;
	if (func == pGetWindowTextLengthA)
		return wine32a_GetWindowTextLengthA;
	if (func == pGetWindowTextLengthW)
		return wine32a_GetWindowTextLengthW;
	if (func == pIsWindow)
		return wine32a_IsWindow;
	if (func == pGetWindowThreadProcessId)
		return wine32a_GetWindowThreadProcessId;
	if (func == pGetParent)
		return wine32a_GetParent;
	if (func == pGetAncestor)
		return wine32a_GetAncestor;
	if (func == pSetParent)
		return wine32a_SetParent;
	if (func == pIsChild)
		return wine32a_IsChild;
	if (func == pIsWindowVisible)
		return wine32a_IsWindowVisible;
	if (func == pGetTopWindow)
		return wine32a_GetTopWindow;
	if (func == pGetWindow)
		return wine32a_GetWindow;
	if (func == pShowOwnedPopups)
		return wine32a_ShowOwnedPopups;
	if (func == pGetLastActivePopup)
		return wine32a_GetLastActivePopup;
	if (func == pEnumWindows)
		return wine32a_EnumWindows;
	if (func == pEnumThreadWindows)
		return wine32a_EnumThreadWindows;
	if (func == pEnumDesktopWindows)
		return wine32a_EnumDesktopWindows;
	if (func == pEnumChildWindows)
		return wine32a_EnumChildWindows;
	if (func == pAnyPopup)
		return wine32a_AnyPopup;
	if (func == pFlashWindow)
		return wine32a_FlashWindow;
	if (func == pFlashWindowEx)
		return wine32a_FlashWindowEx;
	if (func == pGetWindowContextHelpId)
		return wine32a_GetWindowContextHelpId;
	if (func == pSetWindowContextHelpId)
		return wine32a_SetWindowContextHelpId;
	if (func == pDragDetect)
		return wine32a_DragDetect;
	if (func == pGetWindowModuleFileNameA)
		return wine32a_GetWindowModuleFileNameA;
	if (func == pGetWindowModuleFileNameW)
		return wine32a_GetWindowModuleFileNameW;
	if (func == pGetWindowInfo)
		return wine32a_GetWindowInfo;
	if (func == pSwitchDesktop)
		return wine32a_SwitchDesktop;
	if (func == p__wine_set_pixel_format)
		return wine32a___wine_set_pixel_format;
	if (func == pSetLayeredWindowAttributes)
		return wine32a_SetLayeredWindowAttributes;
	if (func == pGetLayeredWindowAttributes)
		return wine32a_GetLayeredWindowAttributes;
	if (func == pUpdateLayeredWindowIndirect)
		return wine32a_UpdateLayeredWindowIndirect;
	if (func == pUpdateLayeredWindow)
		return wine32a_UpdateLayeredWindow;
	if (func == pGetProcessDefaultLayout)
		return wine32a_GetProcessDefaultLayout;
	if (func == pSetProcessDefaultLayout)
		return wine32a_SetProcessDefaultLayout;
	if (func == pGetWindowLongPtrW)
		return wine32a_GetWindowLongPtrW;
	if (func == pGetWindowLongPtrA)
		return wine32a_GetWindowLongPtrA;
	if (func == pSetWindowLongPtrW)
		return wine32a_SetWindowLongPtrW;
	if (func == pSetWindowLongPtrA)
		return wine32a_SetWindowLongPtrA;
	if (func == pRegisterTouchWindow)
		return wine32a_RegisterTouchWindow;
	if (func == pUnregisterTouchWindow)
		return wine32a_UnregisterTouchWindow;
	if (func == pCloseTouchInputHandle)
		return wine32a_CloseTouchInputHandle;
	if (func == pGetTouchInputInfo)
		return wine32a_GetTouchInputInfo;
	if (func == pGetGestureInfo)
		return wine32a_GetGestureInfo;
	if (func == pGetWindowDisplayAffinity)
		return wine32a_GetWindowDisplayAffinity;
	if (func == pSetWindowDisplayAffinity)
		return wine32a_SetWindowDisplayAffinity;
	if (func == pSetWindowCompositionAttribute)
		return wine32a_SetWindowCompositionAttribute;
	if (func == pWinHelpA)
		return wine32a_WinHelpA;
	if (func == pWinHelpW)
		return wine32a_WinHelpW;
	if (func == pSwitchToThisWindow)
		return wine32a_SwitchToThisWindow;
	if (func == pGetWindowRect)
		return wine32a_GetWindowRect;
	if (func == pGetWindowRgn)
		return wine32a_GetWindowRgn;
	if (func == pGetWindowRgnBox)
		return wine32a_GetWindowRgnBox;
	if (func == pSetWindowRgn)
		return wine32a_SetWindowRgn;
	if (func == pGetClientRect)
		return wine32a_GetClientRect;
	if (func == pWindowFromPoint)
		return wine32a_WindowFromPoint;
	if (func == pChildWindowFromPoint)
		return wine32a_ChildWindowFromPoint;
	if (func == pRealChildWindowFromPoint)
		return wine32a_RealChildWindowFromPoint;
	if (func == pChildWindowFromPointEx)
		return wine32a_ChildWindowFromPointEx;
	if (func == pMapWindowPoints)
		return wine32a_MapWindowPoints;
	if (func == pClientToScreen)
		return wine32a_ClientToScreen;
	if (func == pScreenToClient)
		return wine32a_ScreenToClient;
	if (func == pIsIconic)
		return wine32a_IsIconic;
	if (func == pIsZoomed)
		return wine32a_IsZoomed;
	if (func == pAllowSetForegroundWindow)
		return wine32a_AllowSetForegroundWindow;
	if (func == pLockSetForegroundWindow)
		return wine32a_LockSetForegroundWindow;
	if (func == pBringWindowToTop)
		return wine32a_BringWindowToTop;
	if (func == pMoveWindow)
		return wine32a_MoveWindow;
	if (func == pShowWindowAsync)
		return wine32a_ShowWindowAsync;
	if (func == pShowWindow)
		return wine32a_ShowWindow;
	if (func == pGetInternalWindowPos)
		return wine32a_GetInternalWindowPos;
	if (func == pGetWindowPlacement)
		return wine32a_GetWindowPlacement;
	if (func == pSetWindowPlacement)
		return wine32a_SetWindowPlacement;
	if (func == pAnimateWindow)
		return wine32a_AnimateWindow;
	if (func == pSetInternalWindowPos)
		return wine32a_SetInternalWindowPos;
	if (func == pSetWindowPos)
		return wine32a_SetWindowPos;
	if (func == pBeginDeferWindowPos)
		return wine32a_BeginDeferWindowPos;
	if (func == pDeferWindowPos)
		return wine32a_DeferWindowPos;
	if (func == pEndDeferWindowPos)
		return wine32a_EndDeferWindowPos;
	if (func == pArrangeIconicWindows)
		return wine32a_ArrangeIconicWindows;
	if (func == pCallWindowProcA)
		return wine32a_CallWindowProcA;
	if (func == pCallWindowProcW)
		return wine32a_CallWindowProcW;
	if (func == pUserRegisterWowHandlers)
		return wine32a_UserRegisterWowHandlers;
	if (func == pCreateWindowStationA)
		return wine32a_CreateWindowStationA;
	if (func == pCreateWindowStationW)
		return wine32a_CreateWindowStationW;
	if (func == pOpenWindowStationA)
		return wine32a_OpenWindowStationA;
	if (func == pOpenWindowStationW)
		return wine32a_OpenWindowStationW;
	if (func == pCloseWindowStation)
		return wine32a_CloseWindowStation;
	if (func == pGetProcessWindowStation)
		return wine32a_GetProcessWindowStation;
	if (func == pSetProcessWindowStation)
		return wine32a_SetProcessWindowStation;
	if (func == pEnumWindowStationsA)
		return wine32a_EnumWindowStationsA;
	if (func == pEnumWindowStationsW)
		return wine32a_EnumWindowStationsW;
	if (func == pCreateDesktopA)
		return wine32a_CreateDesktopA;
	if (func == pCreateDesktopW)
		return wine32a_CreateDesktopW;
	if (func == pOpenDesktopA)
		return wine32a_OpenDesktopA;
	if (func == pOpenDesktopW)
		return wine32a_OpenDesktopW;
	if (func == pCloseDesktop)
		return wine32a_CloseDesktop;
	if (func == pGetThreadDesktop)
		return wine32a_GetThreadDesktop;
	if (func == pSetThreadDesktop)
		return wine32a_SetThreadDesktop;
	if (func == pEnumDesktopsA)
		return wine32a_EnumDesktopsA;
	if (func == pEnumDesktopsW)
		return wine32a_EnumDesktopsW;
	if (func == pOpenInputDesktop)
		return wine32a_OpenInputDesktop;
	if (func == pGetUserObjectInformationA)
		return wine32a_GetUserObjectInformationA;
	if (func == pGetUserObjectInformationW)
		return wine32a_GetUserObjectInformationW;
	if (func == pSetUserObjectInformationA)
		return wine32a_SetUserObjectInformationA;
	if (func == pSetUserObjectInformationW)
		return wine32a_SetUserObjectInformationW;
	if (func == pGetUserObjectSecurity)
		return wine32a_GetUserObjectSecurity;
	if (func == pSetUserObjectSecurity)
		return wine32a_SetUserObjectSecurity;
	if (func == pwvsprintfA)
		return wine32a_wvsprintfA;
	if (func == pwvsprintfW)
		return wine32a_wvsprintfW;
	if (func == pwsprintfA)
		return wine32a_wsprintfA;
	if (func == pwsprintfW)
		return wine32a_wsprintfW;

	return NULL;
}
