#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

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

static BOOL initialized = FALSE;

void wine_thunk_initialize_user32(void)
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
	initialized = TRUE;
}

void* wine_thunk_get_for_user32(void *func)
{
	if (!initialized)
		return NULL;

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

	ERR("Missing thunk!\n");
	return NULL;
}
