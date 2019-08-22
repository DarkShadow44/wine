#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DECLARE_DEBUG_CHANNEL(thunks);

static WINAPI INT (*pMessageBoxA)(HWND, LPCSTR, LPCSTR, UINT);
static WINAPI INT (*pMessageBoxW)(HWND, LPCWSTR, LPCWSTR, UINT);
static WINAPI INT (*pMessageBoxExA)(HWND, LPCSTR, LPCSTR, UINT, WORD);
static WINAPI INT (*pMessageBoxExW)(HWND, LPCWSTR, LPCWSTR, UINT, WORD);
static WINAPI INT (*pMessageBoxTimeoutA)(HWND, LPCSTR, LPCSTR, UINT, WORD, DWORD);
static WINAPI INT (*pMessageBoxTimeoutW)(HWND, LPCWSTR, LPCWSTR, UINT, WORD, DWORD);
static WINAPI INT (*pMessageBoxIndirectA)(LPMSGBOXPARAMSA);
static WINAPI INT (*pMessageBoxIndirectW)(LPMSGBOXPARAMSW);

extern WINAPI INT wine32b_MessageBoxA(HWND hWnd, LPCSTR text, LPCSTR title, UINT type)
{
	TRACE_(thunks)("Enter MessageBoxA\n");
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
	TRACE_(thunks)("Enter\n");
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
	TRACE_(thunks)("Enter MessageBoxExA\n");
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
	TRACE_(thunks)("Enter MessageBoxExW\n");
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
	TRACE_(thunks)("Enter MessageBoxTimeoutA\n");
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
	TRACE_(thunks)("Enter MessageBoxTimeoutW\n");
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
	TRACE_(thunks)("Enter MessageBoxIndirectA\n");
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
	TRACE_(thunks)("Enter MessageBoxIndirectW\n");
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

void init_user32(void)
{
	HMODULE library = LoadLibraryA("user32.dll");
	pMessageBoxA = (void *)GetProcAddress(library, "MessageBoxA");
	pMessageBoxW = (void *)GetProcAddress(library, "MessageBoxW");
	pMessageBoxExA = (void *)GetProcAddress(library, "MessageBoxExA");
	pMessageBoxExW = (void *)GetProcAddress(library, "MessageBoxExW");
	pMessageBoxTimeoutA = (void *)GetProcAddress(library, "MessageBoxTimeoutA");
	pMessageBoxTimeoutW = (void *)GetProcAddress(library, "MessageBoxTimeoutW");
	pMessageBoxIndirectA = (void *)GetProcAddress(library, "MessageBoxIndirectA");
	pMessageBoxIndirectW = (void *)GetProcAddress(library, "MessageBoxIndirectW");
}
