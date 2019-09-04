#define WIN32_NO_STATUS
#include "ntstatus.h"
#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

#include "../../dlls/msvcrt/msvcrt.h"
#include "../../include/winnls.h"
#include "../../include/wincon.h"
#include "../../dlls/msvcrt/mtdll.h"
#include "../../include/wine/debug.h"
#include "../../include/windef.h"
#include "../../include/winternl.h"
#include "../../include/wine/exception.h"
#include "../../dlls/msvcrt/cppexcept.h"
#include "../../dlls/msvcrt/cxx.h"
#include "../../include/wine/unicode.h"
#include "../../include/wine/library.h"
#include "../../include/winbase.h"
#include "../../include/ntstatus.h"
#include "../../include/winuser.h"
#include "../../include/wine/heap.h"
#include "../../include/wine/asm.h"
#include "../../include/ntsecapi.h"
#include "../../include/windows.h"
#include "../../dlls/msvcrt/scanf.h"
#include "../../dlls/msvcrt/printf.h"

static WINAPI int (*p_cputs)(const char * str);
static WINAPI int (*p_cputws)(const MSVCRT_wchar_t * str);
static WINAPI int (*p_getch)(void);
static WINAPI MSVCRT_wchar_t (*p_getwch)(void);
static WINAPI int (*p_putch)(int c);
static WINAPI MSVCRT_wchar_t (*p_putwch)(MSVCRT_wchar_t c);
static WINAPI int (*p_getche)(void);
static WINAPI MSVCRT_wchar_t (*p_getwche)(void);
static WINAPI char * (*p_cgets)(char * str);
static WINAPI int (*p_ungetch)(int c);
static WINAPI MSVCRT_wchar_t (*p_ungetwch)(MSVCRT_wchar_t c);
static WINAPI int (*p_kbhit)(void);
static WINAPI int (*p_vcprintf)(const char * format, __builtin_ms_va_list valist);
static WINAPI int (*p_cprintf)(const char * format);
static WINAPI int (*p_vcwprintf)(const MSVCRT_wchar_t * format, __builtin_ms_va_list valist);
static WINAPI int (*p_cwprintf)(const MSVCRT_wchar_t * format);

extern WINAPI int wine32b__cputs(const char * str)
{
	TRACE("Enter _cputs\n");
	return p_cputs(str);
}

extern WINAPI void wine32a__cputs(void);
__ASM_GLOBAL_FUNC(wine32a__cputs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cputs") "\n"
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

extern WINAPI int wine32b__cputws(const MSVCRT_wchar_t * str)
{
	TRACE("Enter _cputws\n");
	return p_cputws(str);
}

extern WINAPI void wine32a__cputws(void);
__ASM_GLOBAL_FUNC(wine32a__cputws,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cputws") "\n"
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

extern WINAPI int wine32b__getch(void)
{
	TRACE("Enter _getch\n");
	return p_getch();
}

extern WINAPI void wine32a__getch(void);
__ASM_GLOBAL_FUNC(wine32a__getch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getch") "\n"
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

extern WINAPI MSVCRT_wchar_t wine32b__getwch(void)
{
	TRACE("Enter _getwch\n");
	return p_getwch();
}

extern WINAPI void wine32a__getwch(void);
__ASM_GLOBAL_FUNC(wine32a__getwch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getwch") "\n"
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

extern WINAPI int wine32b__putch(int c)
{
	TRACE("Enter _putch\n");
	return p_putch(c);
}

extern WINAPI void wine32a__putch(void);
__ASM_GLOBAL_FUNC(wine32a__putch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__putch") "\n"
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

extern WINAPI MSVCRT_wchar_t wine32b__putwch(MSVCRT_wchar_t c)
{
	TRACE("Enter _putwch\n");
	return p_putwch(c);
}

extern WINAPI void wine32a__putwch(void);
__ASM_GLOBAL_FUNC(wine32a__putwch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__putwch") "\n"
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

extern WINAPI int wine32b__getche(void)
{
	TRACE("Enter _getche\n");
	return p_getche();
}

extern WINAPI void wine32a__getche(void);
__ASM_GLOBAL_FUNC(wine32a__getche,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getche") "\n"
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

extern WINAPI MSVCRT_wchar_t wine32b__getwche(void)
{
	TRACE("Enter _getwche\n");
	return p_getwche();
}

extern WINAPI void wine32a__getwche(void);
__ASM_GLOBAL_FUNC(wine32a__getwche,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getwche") "\n"
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

extern WINAPI char * wine32b__cgets(char * str)
{
	TRACE("Enter _cgets\n");
	return p_cgets(str);
}

extern WINAPI void wine32a__cgets(void);
__ASM_GLOBAL_FUNC(wine32a__cgets,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cgets") "\n"
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

extern WINAPI int wine32b__ungetch(int c)
{
	TRACE("Enter _ungetch\n");
	return p_ungetch(c);
}

extern WINAPI void wine32a__ungetch(void);
__ASM_GLOBAL_FUNC(wine32a__ungetch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ungetch") "\n"
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

extern WINAPI MSVCRT_wchar_t wine32b__ungetwch(MSVCRT_wchar_t c)
{
	TRACE("Enter _ungetwch\n");
	return p_ungetwch(c);
}

extern WINAPI void wine32a__ungetwch(void);
__ASM_GLOBAL_FUNC(wine32a__ungetwch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ungetwch") "\n"
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

extern WINAPI int wine32b__kbhit(void)
{
	TRACE("Enter _kbhit\n");
	return p_kbhit();
}

extern WINAPI void wine32a__kbhit(void);
__ASM_GLOBAL_FUNC(wine32a__kbhit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__kbhit") "\n"
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

extern WINAPI int wine32b__vcprintf(const char * format, __builtin_ms_va_list valist)
{
	TRACE("Enter _vcprintf\n");
	return p_vcprintf(format, valist);
}

extern WINAPI void wine32a__vcprintf(void);
__ASM_GLOBAL_FUNC(wine32a__vcprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__vcprintf") "\n"
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

extern WINAPI int wine32b__cprintf(const char * format)
{
	TRACE("Enter _cprintf\n");
	return p_cprintf(format);
}

extern WINAPI void wine32a__cprintf(void);
__ASM_GLOBAL_FUNC(wine32a__cprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cprintf") "\n"
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

extern WINAPI int wine32b__vcwprintf(const MSVCRT_wchar_t * format, __builtin_ms_va_list valist)
{
	TRACE("Enter _vcwprintf\n");
	return p_vcwprintf(format, valist);
}

extern WINAPI void wine32a__vcwprintf(void);
__ASM_GLOBAL_FUNC(wine32a__vcwprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__vcwprintf") "\n"
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

extern WINAPI int wine32b__cwprintf(const MSVCRT_wchar_t * format)
{
	TRACE("Enter _cwprintf\n");
	return p_cwprintf(format);
}

extern WINAPI void wine32a__cwprintf(void);
__ASM_GLOBAL_FUNC(wine32a__cwprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwprintf") "\n"
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

static WINAPI void (*p_CxxThrowException)(exception * object, const cxx_exception_type * type);

extern WINAPI void wine32b__CxxThrowException(exception * object, const cxx_exception_type * type)
{
	TRACE("Enter _CxxThrowException\n");
	return p_CxxThrowException(object, type);
}

extern WINAPI void wine32a__CxxThrowException(void);
__ASM_GLOBAL_FUNC(wine32a__CxxThrowException,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__CxxThrowException") "\n"
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


static WINAPI unsigned int * (*p__p__commode)(void);
static WINAPI int (*p_get_pgmptr)(char ** p);
static WINAPI int (*p_get_wpgmptr)(WCHAR ** p);
static WINAPI unsigned int * (*p__p__osver)(void);
static WINAPI unsigned int * (*p__p__winmajor)(void);
static WINAPI unsigned int * (*p__p__winminor)(void);
static WINAPI unsigned int * (*p__p__winver)(void);
static WINAPI char *** (*p__p___initenv)(void);
static WINAPI MSVCRT_wchar_t *** (*p__p___winitenv)(void);
static WINAPI int (*p__getmainargs)(int * argc, char *** argv, char *** envp, int expand_wildcards, int * new_mode);
static WINAPI int (*p__wgetmainargs)(int * argc, MSVCRT_wchar_t *** wargv, MSVCRT_wchar_t *** wenvp, int expand_wildcards, int * new_mode);
static WINAPI void (*p_initterm)(_INITTERMFUN * start, _INITTERMFUN * end);
static WINAPI int (*p_initterm_e)(_INITTERM_E_FN * table, _INITTERM_E_FN * end);

extern WINAPI unsigned int * wine32b___p__commode(void)
{
	TRACE("Enter __p__commode\n");
	return p__p__commode();
}

extern WINAPI void wine32a___p__commode(void);
__ASM_GLOBAL_FUNC(wine32a___p__commode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__commode") "\n"
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

extern WINAPI int wine32b__get_pgmptr(char ** p)
{
	TRACE("Enter _get_pgmptr\n");
	return p_get_pgmptr(p);
}

extern WINAPI void wine32a__get_pgmptr(void);
__ASM_GLOBAL_FUNC(wine32a__get_pgmptr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_pgmptr") "\n"
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

extern WINAPI int wine32b__get_wpgmptr(WCHAR ** p)
{
	TRACE("Enter _get_wpgmptr\n");
	return p_get_wpgmptr(p);
}

extern WINAPI void wine32a__get_wpgmptr(void);
__ASM_GLOBAL_FUNC(wine32a__get_wpgmptr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_wpgmptr") "\n"
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

extern WINAPI unsigned int * wine32b___p__osver(void)
{
	TRACE("Enter __p__osver\n");
	return p__p__osver();
}

extern WINAPI void wine32a___p__osver(void);
__ASM_GLOBAL_FUNC(wine32a___p__osver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__osver") "\n"
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

extern WINAPI unsigned int * wine32b___p__winmajor(void)
{
	TRACE("Enter __p__winmajor\n");
	return p__p__winmajor();
}

extern WINAPI void wine32a___p__winmajor(void);
__ASM_GLOBAL_FUNC(wine32a___p__winmajor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__winmajor") "\n"
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

extern WINAPI unsigned int * wine32b___p__winminor(void)
{
	TRACE("Enter __p__winminor\n");
	return p__p__winminor();
}

extern WINAPI void wine32a___p__winminor(void);
__ASM_GLOBAL_FUNC(wine32a___p__winminor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__winminor") "\n"
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

extern WINAPI unsigned int * wine32b___p__winver(void)
{
	TRACE("Enter __p__winver\n");
	return p__p__winver();
}

extern WINAPI void wine32a___p__winver(void);
__ASM_GLOBAL_FUNC(wine32a___p__winver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__winver") "\n"
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

extern WINAPI char *** wine32b___p___initenv(void)
{
	TRACE("Enter __p___initenv\n");
	return p__p___initenv();
}

extern WINAPI void wine32a___p___initenv(void);
__ASM_GLOBAL_FUNC(wine32a___p___initenv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p___initenv") "\n"
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

extern WINAPI MSVCRT_wchar_t *** wine32b___p___winitenv(void)
{
	TRACE("Enter __p___winitenv\n");
	return p__p___winitenv();
}

extern WINAPI void wine32a___p___winitenv(void);
__ASM_GLOBAL_FUNC(wine32a___p___winitenv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p___winitenv") "\n"
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

extern WINAPI int wine32b___getmainargs(int * argc, char *** argv, char *** envp, int expand_wildcards, int * new_mode)
{
	TRACE("Enter __getmainargs\n");
	return p__getmainargs(argc, argv, envp, expand_wildcards, new_mode);
}

extern WINAPI void wine32a___getmainargs(void);
__ASM_GLOBAL_FUNC(wine32a___getmainargs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___getmainargs") "\n"
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

extern WINAPI int wine32b___wgetmainargs(int * argc, MSVCRT_wchar_t *** wargv, MSVCRT_wchar_t *** wenvp, int expand_wildcards, int * new_mode)
{
	TRACE("Enter __wgetmainargs\n");
	return p__wgetmainargs(argc, wargv, wenvp, expand_wildcards, new_mode);
}

extern WINAPI void wine32a___wgetmainargs(void);
__ASM_GLOBAL_FUNC(wine32a___wgetmainargs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wgetmainargs") "\n"
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

extern WINAPI void wine32b__initterm(_INITTERMFUN * start, _INITTERMFUN * end)
{
	TRACE("Enter _initterm\n");
	return p_initterm(start, end);
}

extern WINAPI void wine32a__initterm(void);
__ASM_GLOBAL_FUNC(wine32a__initterm,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__initterm") "\n"
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

extern WINAPI int wine32b__initterm_e(_INITTERM_E_FN * table, _INITTERM_E_FN * end)
{
	TRACE("Enter _initterm_e\n");
	return p_initterm_e(table, end);
}

extern WINAPI void wine32a__initterm_e(void);
__ASM_GLOBAL_FUNC(wine32a__initterm_e,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__initterm_e") "\n"
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


static WINAPI int (*p_putenv)(const char * str);
static WINAPI int (*p_wputenv)(const MSVCRT_wchar_t * str);
static WINAPI int (*p_putenv_s)(const char * name, const char * value);
static WINAPI int (*p_wputenv_s)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * value);
static WINAPI int (*pgetenv_s)(MSVCRT_size_t * pReturnValue, char * buffer, MSVCRT_size_t numberOfElements, const char * varname);
static WINAPI int (*p_wgetenv_s)(MSVCRT_size_t * pReturnValue, MSVCRT_wchar_t * buffer, MSVCRT_size_t numberOfElements, const MSVCRT_wchar_t * varname);

extern WINAPI int wine32b__putenv(const char * str)
{
	TRACE("Enter _putenv\n");
	return p_putenv(str);
}

extern WINAPI void wine32a__putenv(void);
__ASM_GLOBAL_FUNC(wine32a__putenv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__putenv") "\n"
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

extern WINAPI int wine32b__wputenv(const MSVCRT_wchar_t * str)
{
	TRACE("Enter _wputenv\n");
	return p_wputenv(str);
}

extern WINAPI void wine32a__wputenv(void);
__ASM_GLOBAL_FUNC(wine32a__wputenv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wputenv") "\n"
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

extern WINAPI int wine32b__putenv_s(const char * name, const char * value)
{
	TRACE("Enter _putenv_s\n");
	return p_putenv_s(name, value);
}

extern WINAPI void wine32a__putenv_s(void);
__ASM_GLOBAL_FUNC(wine32a__putenv_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__putenv_s") "\n"
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

extern WINAPI int wine32b__wputenv_s(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * value)
{
	TRACE("Enter _wputenv_s\n");
	return p_wputenv_s(name, value);
}

extern WINAPI void wine32a__wputenv_s(void);
__ASM_GLOBAL_FUNC(wine32a__wputenv_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wputenv_s") "\n"
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

extern WINAPI int wine32b_getenv_s(MSVCRT_size_t * pReturnValue, char * buffer, MSVCRT_size_t numberOfElements, const char * varname)
{
	TRACE("Enter getenv_s\n");
	return pgetenv_s(pReturnValue, buffer, numberOfElements, varname);
}

extern WINAPI void wine32a_getenv_s(void);
__ASM_GLOBAL_FUNC(wine32a_getenv_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_getenv_s") "\n"
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

extern WINAPI int wine32b__wgetenv_s(MSVCRT_size_t * pReturnValue, MSVCRT_wchar_t * buffer, MSVCRT_size_t numberOfElements, const MSVCRT_wchar_t * varname)
{
	TRACE("Enter _wgetenv_s\n");
	return p_wgetenv_s(pReturnValue, buffer, numberOfElements, varname);
}

extern WINAPI void wine32a__wgetenv_s(void);
__ASM_GLOBAL_FUNC(wine32a__wgetenv_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wgetenv_s") "\n"
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

static WINAPI int (*p_get_errno)(int * pValue);
static WINAPI int (*p_get_doserrno)(int * pValue);
static WINAPI int (*p_set_errno)(int value);
static WINAPI int (*p_set_doserrno)(int value);
static WINAPI void (*p_seterrormode)(int mode);

extern WINAPI int wine32b__get_errno(int * pValue)
{
	TRACE("Enter _get_errno\n");
	return p_get_errno(pValue);
}

extern WINAPI void wine32a__get_errno(void);
__ASM_GLOBAL_FUNC(wine32a__get_errno,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_errno") "\n"
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

extern WINAPI int wine32b__get_doserrno(int * pValue)
{
	TRACE("Enter _get_doserrno\n");
	return p_get_doserrno(pValue);
}

extern WINAPI void wine32a__get_doserrno(void);
__ASM_GLOBAL_FUNC(wine32a__get_doserrno,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_doserrno") "\n"
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

extern WINAPI int wine32b__set_errno(int value)
{
	TRACE("Enter _set_errno\n");
	return p_set_errno(value);
}

extern WINAPI void wine32a__set_errno(void);
__ASM_GLOBAL_FUNC(wine32a__set_errno,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__set_errno") "\n"
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

extern WINAPI int wine32b__set_doserrno(int value)
{
	TRACE("Enter _set_doserrno\n");
	return p_set_doserrno(value);
}

extern WINAPI void wine32a__set_doserrno(void);
__ASM_GLOBAL_FUNC(wine32a__set_doserrno,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__set_doserrno") "\n"
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

extern WINAPI void wine32b__seterrormode(int mode)
{
	TRACE("Enter _seterrormode\n");
	return p_seterrormode(mode);
}

extern WINAPI void wine32a__seterrormode(void);
__ASM_GLOBAL_FUNC(wine32a__seterrormode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__seterrormode") "\n"
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

static WINAPI int (*p_XcptFilter)(NTSTATUS ex, PEXCEPTION_POINTERS ptr);
static WINAPI int (*p_abnormal_termination)(void);
static WINAPI void (*p__DestructExceptionObject)(EXCEPTION_RECORD * rec);
static WINAPI BOOL (*p__CxxRegisterExceptionObject)(EXCEPTION_POINTERS * ep, cxx_frame_info * frame_info);
static WINAPI void (*p__CxxUnregisterExceptionObject)(cxx_frame_info * frame_info, BOOL in_use);

extern WINAPI int wine32b__XcptFilter(NTSTATUS ex, PEXCEPTION_POINTERS ptr)
{
	TRACE("Enter _XcptFilter\n");
	return p_XcptFilter(ex, ptr);
}

extern WINAPI void wine32a__XcptFilter(void);
__ASM_GLOBAL_FUNC(wine32a__XcptFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__XcptFilter") "\n"
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

extern WINAPI int wine32b__abnormal_termination(void)
{
	TRACE("Enter _abnormal_termination\n");
	return p_abnormal_termination();
}

extern WINAPI void wine32a__abnormal_termination(void);
__ASM_GLOBAL_FUNC(wine32a__abnormal_termination,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__abnormal_termination") "\n"
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

extern WINAPI void wine32b___DestructExceptionObject(EXCEPTION_RECORD * rec)
{
	TRACE("Enter __DestructExceptionObject\n");
	return p__DestructExceptionObject(rec);
}

extern WINAPI void wine32a___DestructExceptionObject(void);
__ASM_GLOBAL_FUNC(wine32a___DestructExceptionObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___DestructExceptionObject") "\n"
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

extern WINAPI BOOL wine32b___CxxRegisterExceptionObject(EXCEPTION_POINTERS * ep, cxx_frame_info * frame_info)
{
	TRACE("Enter __CxxRegisterExceptionObject\n");
	return p__CxxRegisterExceptionObject(ep, frame_info);
}

extern WINAPI void wine32a___CxxRegisterExceptionObject(void);
__ASM_GLOBAL_FUNC(wine32a___CxxRegisterExceptionObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CxxRegisterExceptionObject") "\n"
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

extern WINAPI void wine32b___CxxUnregisterExceptionObject(cxx_frame_info * frame_info, BOOL in_use)
{
	TRACE("Enter __CxxUnregisterExceptionObject\n");
	return p__CxxUnregisterExceptionObject(frame_info, in_use);
}

extern WINAPI void wine32a___CxxUnregisterExceptionObject(void);
__ASM_GLOBAL_FUNC(wine32a___CxxUnregisterExceptionObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CxxUnregisterExceptionObject") "\n"
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




static WINAPI int (*p__CxxExceptionFilter)(PEXCEPTION_POINTERS ptrs, const type_info * ti, int flags, void ** copy);
static WINAPI int (*p__CppXcptFilter)(NTSTATUS ex, PEXCEPTION_POINTERS ptr);
static WINAPI BOOL (*p__CxxDetectRethrow)(PEXCEPTION_POINTERS ptrs);
static WINAPI unsigned int (*p__CxxQueryExceptionSize)(void);
static WINAPI void (*p_local_unwind)(void * frame, void * target);
static WINAPI int (*p_fpieee_flt)(ULONG exception_code, EXCEPTION_POINTERS * ep, int (*)(_FPIEEE_RECORD *) __attribute__((ms_abi)) handler);

extern WINAPI int wine32b___CxxExceptionFilter(PEXCEPTION_POINTERS ptrs, const type_info * ti, int flags, void ** copy)
{
	TRACE("Enter __CxxExceptionFilter\n");
	return p__CxxExceptionFilter(ptrs, ti, flags, copy);
}

extern WINAPI void wine32a___CxxExceptionFilter(void);
__ASM_GLOBAL_FUNC(wine32a___CxxExceptionFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CxxExceptionFilter") "\n"
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

extern WINAPI int wine32b___CppXcptFilter(NTSTATUS ex, PEXCEPTION_POINTERS ptr)
{
	TRACE("Enter __CppXcptFilter\n");
	return p__CppXcptFilter(ex, ptr);
}

extern WINAPI void wine32a___CppXcptFilter(void);
__ASM_GLOBAL_FUNC(wine32a___CppXcptFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CppXcptFilter") "\n"
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

extern WINAPI BOOL wine32b___CxxDetectRethrow(PEXCEPTION_POINTERS ptrs)
{
	TRACE("Enter __CxxDetectRethrow\n");
	return p__CxxDetectRethrow(ptrs);
}

extern WINAPI void wine32a___CxxDetectRethrow(void);
__ASM_GLOBAL_FUNC(wine32a___CxxDetectRethrow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CxxDetectRethrow") "\n"
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

extern WINAPI unsigned int wine32b___CxxQueryExceptionSize(void)
{
	TRACE("Enter __CxxQueryExceptionSize\n");
	return p__CxxQueryExceptionSize();
}

extern WINAPI void wine32a___CxxQueryExceptionSize(void);
__ASM_GLOBAL_FUNC(wine32a___CxxQueryExceptionSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___CxxQueryExceptionSize") "\n"
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

extern WINAPI void wine32b__local_unwind(void * frame, void * target)
{
	TRACE("Enter _local_unwind\n");
	return p_local_unwind(frame, target);
}

extern WINAPI void wine32a__local_unwind(void);
__ASM_GLOBAL_FUNC(wine32a__local_unwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__local_unwind") "\n"
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

extern WINAPI int wine32b__fpieee_flt(ULONG exception_code, EXCEPTION_POINTERS * ep, int (*)(_FPIEEE_RECORD *) __attribute__((ms_abi)) handler)
{
	TRACE("Enter _fpieee_flt\n");
	return p_fpieee_flt(exception_code, ep, handler);
}

extern WINAPI void wine32a__fpieee_flt(void);
__ASM_GLOBAL_FUNC(wine32a__fpieee_flt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__fpieee_flt") "\n"
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

static WINAPI MSVCRT__onexit_t (*p__dllonexit)(MSVCRT__onexit_t func, MSVCRT__onexit_t ** start, MSVCRT__onexit_t ** end);
static WINAPI void (*p_amsg_exit)(int errnum);
static WINAPI void (*p_purecall)(void);
static WINAPI int (*p_set_error_mode)(int mode);

extern WINAPI MSVCRT__onexit_t wine32b___dllonexit(MSVCRT__onexit_t func, MSVCRT__onexit_t ** start, MSVCRT__onexit_t ** end)
{
	TRACE("Enter __dllonexit\n");
	return p__dllonexit(func, start, end);
}

extern WINAPI void wine32a___dllonexit(void);
__ASM_GLOBAL_FUNC(wine32a___dllonexit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___dllonexit") "\n"
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

extern WINAPI void wine32b__amsg_exit(int errnum)
{
	TRACE("Enter _amsg_exit\n");
	return p_amsg_exit(errnum);
}

extern WINAPI void wine32a__amsg_exit(void);
__ASM_GLOBAL_FUNC(wine32a__amsg_exit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__amsg_exit") "\n"
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

extern WINAPI void wine32b__purecall(void)
{
	TRACE("Enter _purecall\n");
	return p_purecall();
}

extern WINAPI void wine32a__purecall(void);
__ASM_GLOBAL_FUNC(wine32a__purecall,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__purecall") "\n"
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

extern WINAPI int wine32b__set_error_mode(int mode)
{
	TRACE("Enter _set_error_mode\n");
	return p_set_error_mode(mode);
}

extern WINAPI void wine32a__set_error_mode(void);
__ASM_GLOBAL_FUNC(wine32a__set_error_mode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__set_error_mode") "\n"
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

static WINAPI MSVCRT_FILE * (*p__iob_func)(void);
static WINAPI int (*p_futime64)(int fd, struct MSVCRT___utimbuf64 * t);
static WINAPI int (*p_futime32)(int fd, struct MSVCRT___utimbuf32 * t);
static WINAPI int (*p_futime)(int fd, struct MSVCRT___utimbuf64 * t);
static WINAPI long (*p_telli64)(int fd);
static WINAPI int (*p_utime64)(const char * path, struct MSVCRT___utimbuf64 * t);
static WINAPI int (*p_utime32)(const char * path, struct MSVCRT___utimbuf32 * t);
static WINAPI int (*p_utime)(const char * path, struct MSVCRT___utimbuf64 * t);
static WINAPI int (*p_wutime64)(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf64 * t);
static WINAPI int (*p_wutime32)(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf32 * t);
static WINAPI int (*p_wutime)(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf64 * t);

extern WINAPI MSVCRT_FILE * wine32b___iob_func(void)
{
	TRACE("Enter __iob_func\n");
	return p__iob_func();
}

extern WINAPI void wine32a___iob_func(void);
__ASM_GLOBAL_FUNC(wine32a___iob_func,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___iob_func") "\n"
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

extern WINAPI int wine32b__futime64(int fd, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _futime64\n");
	return p_futime64(fd, t);
}

extern WINAPI void wine32a__futime64(void);
__ASM_GLOBAL_FUNC(wine32a__futime64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__futime64") "\n"
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

extern WINAPI int wine32b__futime32(int fd, struct MSVCRT___utimbuf32 * t)
{
	TRACE("Enter _futime32\n");
	return p_futime32(fd, t);
}

extern WINAPI void wine32a__futime32(void);
__ASM_GLOBAL_FUNC(wine32a__futime32,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__futime32") "\n"
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

extern WINAPI int wine32b__futime(int fd, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _futime\n");
	return p_futime(fd, t);
}

extern WINAPI void wine32a__futime(void);
__ASM_GLOBAL_FUNC(wine32a__futime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__futime") "\n"
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

extern WINAPI long wine32b__telli64(int fd)
{
	TRACE("Enter _telli64\n");
	return p_telli64(fd);
}

extern WINAPI void wine32a__telli64(void);
__ASM_GLOBAL_FUNC(wine32a__telli64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__telli64") "\n"
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

extern WINAPI int wine32b__utime64(const char * path, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _utime64\n");
	return p_utime64(path, t);
}

extern WINAPI void wine32a__utime64(void);
__ASM_GLOBAL_FUNC(wine32a__utime64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__utime64") "\n"
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

extern WINAPI int wine32b__utime32(const char * path, struct MSVCRT___utimbuf32 * t)
{
	TRACE("Enter _utime32\n");
	return p_utime32(path, t);
}

extern WINAPI void wine32a__utime32(void);
__ASM_GLOBAL_FUNC(wine32a__utime32,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__utime32") "\n"
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

extern WINAPI int wine32b__utime(const char * path, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _utime\n");
	return p_utime(path, t);
}

extern WINAPI void wine32a__utime(void);
__ASM_GLOBAL_FUNC(wine32a__utime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__utime") "\n"
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

extern WINAPI int wine32b__wutime64(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _wutime64\n");
	return p_wutime64(path, t);
}

extern WINAPI void wine32a__wutime64(void);
__ASM_GLOBAL_FUNC(wine32a__wutime64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wutime64") "\n"
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

extern WINAPI int wine32b__wutime32(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf32 * t)
{
	TRACE("Enter _wutime32\n");
	return p_wutime32(path, t);
}

extern WINAPI void wine32a__wutime32(void);
__ASM_GLOBAL_FUNC(wine32a__wutime32,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wutime32") "\n"
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

extern WINAPI int wine32b__wutime(const MSVCRT_wchar_t * path, struct MSVCRT___utimbuf64 * t)
{
	TRACE("Enter _wutime\n");
	return p_wutime(path, t);
}

extern WINAPI void wine32a__wutime(void);
__ASM_GLOBAL_FUNC(wine32a__wutime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wutime") "\n"
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

static WINAPI int (*p_callnewh)(MSVCRT_size_t size);
static WINAPI void * (*p_expand)(void * mem, MSVCRT_size_t size);
static WINAPI int (*p_heapchk)(void);
static WINAPI int (*p_heapmin)(void);
static WINAPI int (*p_heapwalk)(struct MSVCRT__heapinfo * next);
static WINAPI int (*p_heapset)(unsigned int value);
static WINAPI int (*p_heapadd)(void * mem, MSVCRT_size_t size);
static WINAPI MSVCRT_intptr_t (*p_get_heap_handle)(void);
static WINAPI MSVCRT_size_t (*p_msize)(void * mem);
static WINAPI unsigned int * (*p__p__amblksiz)(void);
static WINAPI MSVCRT_size_t (*p_get_sbh_threshold)(void);
static WINAPI int (*p_set_sbh_threshold)(MSVCRT_size_t threshold);
static WINAPI void (*p_aligned_free)(void * memblock);
static WINAPI void * (*p_aligned_offset_malloc)(MSVCRT_size_t size, MSVCRT_size_t alignment, MSVCRT_size_t offset);
static WINAPI void * (*p_aligned_malloc)(MSVCRT_size_t size, MSVCRT_size_t alignment);
static WINAPI void * (*p_aligned_offset_realloc)(void * memblock, MSVCRT_size_t size, MSVCRT_size_t alignment, MSVCRT_size_t offset);
static WINAPI void * (*p_aligned_realloc)(void * memblock, MSVCRT_size_t size, MSVCRT_size_t alignment);

extern WINAPI int wine32b__callnewh(MSVCRT_size_t size)
{
	TRACE("Enter _callnewh\n");
	return p_callnewh(size);
}

extern WINAPI void wine32a__callnewh(void);
__ASM_GLOBAL_FUNC(wine32a__callnewh,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__callnewh") "\n"
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

extern WINAPI void * wine32b__expand(void * mem, MSVCRT_size_t size)
{
	TRACE("Enter _expand\n");
	return p_expand(mem, size);
}

extern WINAPI void wine32a__expand(void);
__ASM_GLOBAL_FUNC(wine32a__expand,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__expand") "\n"
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

extern WINAPI int wine32b__heapchk(void)
{
	TRACE("Enter _heapchk\n");
	return p_heapchk();
}

extern WINAPI void wine32a__heapchk(void);
__ASM_GLOBAL_FUNC(wine32a__heapchk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__heapchk") "\n"
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

extern WINAPI int wine32b__heapmin(void)
{
	TRACE("Enter _heapmin\n");
	return p_heapmin();
}

extern WINAPI void wine32a__heapmin(void);
__ASM_GLOBAL_FUNC(wine32a__heapmin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__heapmin") "\n"
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

extern WINAPI int wine32b__heapwalk(struct MSVCRT__heapinfo * next)
{
	TRACE("Enter _heapwalk\n");
	return p_heapwalk(next);
}

extern WINAPI void wine32a__heapwalk(void);
__ASM_GLOBAL_FUNC(wine32a__heapwalk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__heapwalk") "\n"
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

extern WINAPI int wine32b__heapset(unsigned int value)
{
	TRACE("Enter _heapset\n");
	return p_heapset(value);
}

extern WINAPI void wine32a__heapset(void);
__ASM_GLOBAL_FUNC(wine32a__heapset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__heapset") "\n"
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

extern WINAPI int wine32b__heapadd(void * mem, MSVCRT_size_t size)
{
	TRACE("Enter _heapadd\n");
	return p_heapadd(mem, size);
}

extern WINAPI void wine32a__heapadd(void);
__ASM_GLOBAL_FUNC(wine32a__heapadd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__heapadd") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__get_heap_handle(void)
{
	TRACE("Enter _get_heap_handle\n");
	return p_get_heap_handle();
}

extern WINAPI void wine32a__get_heap_handle(void);
__ASM_GLOBAL_FUNC(wine32a__get_heap_handle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_heap_handle") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__msize(void * mem)
{
	TRACE("Enter _msize\n");
	return p_msize(mem);
}

extern WINAPI void wine32a__msize(void);
__ASM_GLOBAL_FUNC(wine32a__msize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__msize") "\n"
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

extern WINAPI unsigned int * wine32b___p__amblksiz(void)
{
	TRACE("Enter __p__amblksiz\n");
	return p__p__amblksiz();
}

extern WINAPI void wine32a___p__amblksiz(void);
__ASM_GLOBAL_FUNC(wine32a___p__amblksiz,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__amblksiz") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__get_sbh_threshold(void)
{
	TRACE("Enter _get_sbh_threshold\n");
	return p_get_sbh_threshold();
}

extern WINAPI void wine32a__get_sbh_threshold(void);
__ASM_GLOBAL_FUNC(wine32a__get_sbh_threshold,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__get_sbh_threshold") "\n"
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

extern WINAPI int wine32b__set_sbh_threshold(MSVCRT_size_t threshold)
{
	TRACE("Enter _set_sbh_threshold\n");
	return p_set_sbh_threshold(threshold);
}

extern WINAPI void wine32a__set_sbh_threshold(void);
__ASM_GLOBAL_FUNC(wine32a__set_sbh_threshold,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__set_sbh_threshold") "\n"
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

extern WINAPI void wine32b__aligned_free(void * memblock)
{
	TRACE("Enter _aligned_free\n");
	return p_aligned_free(memblock);
}

extern WINAPI void wine32a__aligned_free(void);
__ASM_GLOBAL_FUNC(wine32a__aligned_free,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__aligned_free") "\n"
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

extern WINAPI void * wine32b__aligned_offset_malloc(MSVCRT_size_t size, MSVCRT_size_t alignment, MSVCRT_size_t offset)
{
	TRACE("Enter _aligned_offset_malloc\n");
	return p_aligned_offset_malloc(size, alignment, offset);
}

extern WINAPI void wine32a__aligned_offset_malloc(void);
__ASM_GLOBAL_FUNC(wine32a__aligned_offset_malloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__aligned_offset_malloc") "\n"
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

extern WINAPI void * wine32b__aligned_malloc(MSVCRT_size_t size, MSVCRT_size_t alignment)
{
	TRACE("Enter _aligned_malloc\n");
	return p_aligned_malloc(size, alignment);
}

extern WINAPI void wine32a__aligned_malloc(void);
__ASM_GLOBAL_FUNC(wine32a__aligned_malloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__aligned_malloc") "\n"
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

extern WINAPI void * wine32b__aligned_offset_realloc(void * memblock, MSVCRT_size_t size, MSVCRT_size_t alignment, MSVCRT_size_t offset)
{
	TRACE("Enter _aligned_offset_realloc\n");
	return p_aligned_offset_realloc(memblock, size, alignment, offset);
}

extern WINAPI void wine32a__aligned_offset_realloc(void);
__ASM_GLOBAL_FUNC(wine32a__aligned_offset_realloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__aligned_offset_realloc") "\n"
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

extern WINAPI void * wine32b__aligned_realloc(void * memblock, MSVCRT_size_t size, MSVCRT_size_t alignment)
{
	TRACE("Enter _aligned_realloc\n");
	return p_aligned_realloc(memblock, size, alignment);
}

extern WINAPI void wine32a__aligned_realloc(void);
__ASM_GLOBAL_FUNC(wine32a__aligned_realloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__aligned_realloc") "\n"
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


static WINAPI char * (*p_Getdays)(void);
static WINAPI char * (*p_Getmonths)(void);
static WINAPI void * (*p_Gettnames)(void);
static WINAPI int (*p__crtLCMapStringA)(LCID lcid, DWORD mapflags, const char * src, int srclen, char * dst, int dstlen, unsigned int codepage, int xflag);
static WINAPI int (*p__crtLCMapStringW)(LCID lcid, DWORD mapflags, const MSVCRT_wchar_t * src, int srclen, MSVCRT_wchar_t * dst, int dstlen, unsigned int codepage, int xflag);
static WINAPI int (*p__crtCompareStringA)(LCID lcid, DWORD flags, const char * src1, int len1, const char * src2, int len2);
static WINAPI int (*p__crtCompareStringW)(LCID lcid, DWORD flags, const MSVCRT_wchar_t * src1, int len1, const MSVCRT_wchar_t * src2, int len2);
static WINAPI int (*p__crtGetLocaleInfoW)(LCID lcid, LCTYPE type, MSVCRT_wchar_t * buffer, int len);
static WINAPI BOOL (*p__crtGetStringTypeW)(DWORD unk, DWORD type, MSVCRT_wchar_t * buffer, int len, WORD * out);
static WINAPI int (*p__lconv_init)(void);
static WINAPI LCID * (*p___lc_handle_func)(void);
static WINAPI unsigned int (*p___lc_codepage_func)(void);
static WINAPI int (*p___lc_collate_cp_func)(void);

extern WINAPI char * wine32b__Getdays(void)
{
	TRACE("Enter _Getdays\n");
	return p_Getdays();
}

extern WINAPI void wine32a__Getdays(void);
__ASM_GLOBAL_FUNC(wine32a__Getdays,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__Getdays") "\n"
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

extern WINAPI char * wine32b__Getmonths(void)
{
	TRACE("Enter _Getmonths\n");
	return p_Getmonths();
}

extern WINAPI void wine32a__Getmonths(void);
__ASM_GLOBAL_FUNC(wine32a__Getmonths,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__Getmonths") "\n"
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

extern WINAPI void * wine32b__Gettnames(void)
{
	TRACE("Enter _Gettnames\n");
	return p_Gettnames();
}

extern WINAPI void wine32a__Gettnames(void);
__ASM_GLOBAL_FUNC(wine32a__Gettnames,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__Gettnames") "\n"
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

extern WINAPI int wine32b___crtLCMapStringA(LCID lcid, DWORD mapflags, const char * src, int srclen, char * dst, int dstlen, unsigned int codepage, int xflag)
{
	TRACE("Enter __crtLCMapStringA\n");
	return p__crtLCMapStringA(lcid, mapflags, src, srclen, dst, dstlen, codepage, xflag);
}

extern WINAPI void wine32a___crtLCMapStringA(void);
__ASM_GLOBAL_FUNC(wine32a___crtLCMapStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtLCMapStringA") "\n"
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

extern WINAPI int wine32b___crtLCMapStringW(LCID lcid, DWORD mapflags, const MSVCRT_wchar_t * src, int srclen, MSVCRT_wchar_t * dst, int dstlen, unsigned int codepage, int xflag)
{
	TRACE("Enter __crtLCMapStringW\n");
	return p__crtLCMapStringW(lcid, mapflags, src, srclen, dst, dstlen, codepage, xflag);
}

extern WINAPI void wine32a___crtLCMapStringW(void);
__ASM_GLOBAL_FUNC(wine32a___crtLCMapStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtLCMapStringW") "\n"
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

extern WINAPI int wine32b___crtCompareStringA(LCID lcid, DWORD flags, const char * src1, int len1, const char * src2, int len2)
{
	TRACE("Enter __crtCompareStringA\n");
	return p__crtCompareStringA(lcid, flags, src1, len1, src2, len2);
}

extern WINAPI void wine32a___crtCompareStringA(void);
__ASM_GLOBAL_FUNC(wine32a___crtCompareStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtCompareStringA") "\n"
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

extern WINAPI int wine32b___crtCompareStringW(LCID lcid, DWORD flags, const MSVCRT_wchar_t * src1, int len1, const MSVCRT_wchar_t * src2, int len2)
{
	TRACE("Enter __crtCompareStringW\n");
	return p__crtCompareStringW(lcid, flags, src1, len1, src2, len2);
}

extern WINAPI void wine32a___crtCompareStringW(void);
__ASM_GLOBAL_FUNC(wine32a___crtCompareStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtCompareStringW") "\n"
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

extern WINAPI int wine32b___crtGetLocaleInfoW(LCID lcid, LCTYPE type, MSVCRT_wchar_t * buffer, int len)
{
	TRACE("Enter __crtGetLocaleInfoW\n");
	return p__crtGetLocaleInfoW(lcid, type, buffer, len);
}

extern WINAPI void wine32a___crtGetLocaleInfoW(void);
__ASM_GLOBAL_FUNC(wine32a___crtGetLocaleInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtGetLocaleInfoW") "\n"
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

extern WINAPI BOOL wine32b___crtGetStringTypeW(DWORD unk, DWORD type, MSVCRT_wchar_t * buffer, int len, WORD * out)
{
	TRACE("Enter __crtGetStringTypeW\n");
	return p__crtGetStringTypeW(unk, type, buffer, len, out);
}

extern WINAPI void wine32a___crtGetStringTypeW(void);
__ASM_GLOBAL_FUNC(wine32a___crtGetStringTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___crtGetStringTypeW") "\n"
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

extern WINAPI int wine32b___lconv_init(void)
{
	TRACE("Enter __lconv_init\n");
	return p__lconv_init();
}

extern WINAPI void wine32a___lconv_init(void);
__ASM_GLOBAL_FUNC(wine32a___lconv_init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___lconv_init") "\n"
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

extern WINAPI LCID * wine32b____lc_handle_func(void)
{
	TRACE("Enter ___lc_handle_func\n");
	return p___lc_handle_func();
}

extern WINAPI void wine32a____lc_handle_func(void);
__ASM_GLOBAL_FUNC(wine32a____lc_handle_func,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b____lc_handle_func") "\n"
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

extern WINAPI unsigned int wine32b____lc_codepage_func(void)
{
	TRACE("Enter ___lc_codepage_func\n");
	return p___lc_codepage_func();
}

extern WINAPI void wine32a____lc_codepage_func(void);
__ASM_GLOBAL_FUNC(wine32a____lc_codepage_func,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b____lc_codepage_func") "\n"
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

extern WINAPI int wine32b____lc_collate_cp_func(void)
{
	TRACE("Enter ___lc_collate_cp_func\n");
	return p___lc_collate_cp_func();
}

extern WINAPI void wine32a____lc_collate_cp_func(void);
__ASM_GLOBAL_FUNC(wine32a____lc_collate_cp_func,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b____lc_collate_cp_func") "\n"
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

static WINAPI void (*p_lock)(int locknum);
static WINAPI void (*p_unlock)(int locknum);

extern WINAPI void wine32b__lock(int locknum)
{
	TRACE("Enter _lock\n");
	return p_lock(locknum);
}

extern WINAPI void wine32a__lock(void);
__ASM_GLOBAL_FUNC(wine32a__lock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lock") "\n"
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

extern WINAPI void wine32b__unlock(int locknum)
{
	TRACE("Enter _unlock\n");
	return p_unlock(locknum);
}

extern WINAPI void wine32a__unlock(void);
__ASM_GLOBAL_FUNC(wine32a__unlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__unlock") "\n"
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


static WINAPI unsigned int (*p_rotl)(unsigned int num, int shift);
static WINAPI unsigned int (*p_rotr)(unsigned int num, int shift);
static WINAPI unsigned long (*p_rotl64)(unsigned long num, int shift);
static WINAPI unsigned long (*p_rotr64)(unsigned long num, int shift);
static WINAPI long (*p_abs64)(long n);
static WINAPI double (*p_hypot)(double x, double y);
static WINAPI unsigned int (*p_statusfp)(void);
static WINAPI unsigned int (*p_clearfp)(void);
static WINAPI int * (*p__fpecode)(void);
static WINAPI unsigned int (*p_control87)(unsigned int newval, unsigned int mask);
static WINAPI unsigned int (*p_controlfp)(unsigned int newval, unsigned int mask);
static WINAPI void (*p_set_controlfp)(unsigned int newval, unsigned int mask);
static WINAPI int (*p_controlfp_s)(unsigned int * cur, unsigned int newval, unsigned int mask);
static WINAPI void (*p_fpreset)(void);

extern WINAPI unsigned int wine32b__rotl(unsigned int num, int shift)
{
	TRACE("Enter _rotl\n");
	return p_rotl(num, shift);
}

extern WINAPI void wine32a__rotl(void);
__ASM_GLOBAL_FUNC(wine32a__rotl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__rotl") "\n"
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

extern WINAPI unsigned int wine32b__rotr(unsigned int num, int shift)
{
	TRACE("Enter _rotr\n");
	return p_rotr(num, shift);
}

extern WINAPI void wine32a__rotr(void);
__ASM_GLOBAL_FUNC(wine32a__rotr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__rotr") "\n"
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

extern WINAPI unsigned long wine32b__rotl64(unsigned long num, int shift)
{
	TRACE("Enter _rotl64\n");
	return p_rotl64(num, shift);
}

extern WINAPI void wine32a__rotl64(void);
__ASM_GLOBAL_FUNC(wine32a__rotl64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__rotl64") "\n"
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

extern WINAPI unsigned long wine32b__rotr64(unsigned long num, int shift)
{
	TRACE("Enter _rotr64\n");
	return p_rotr64(num, shift);
}

extern WINAPI void wine32a__rotr64(void);
__ASM_GLOBAL_FUNC(wine32a__rotr64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__rotr64") "\n"
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

extern WINAPI long wine32b__abs64(long n)
{
	TRACE("Enter _abs64\n");
	return p_abs64(n);
}

extern WINAPI void wine32a__abs64(void);
__ASM_GLOBAL_FUNC(wine32a__abs64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__abs64") "\n"
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

extern WINAPI double wine32b__hypot(double x, double y)
{
	TRACE("Enter _hypot\n");
	return p_hypot(x, y);
}

extern WINAPI void wine32a__hypot(void);
__ASM_GLOBAL_FUNC(wine32a__hypot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__hypot") "\n"
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

extern WINAPI unsigned int wine32b__statusfp(void)
{
	TRACE("Enter _statusfp\n");
	return p_statusfp();
}

extern WINAPI void wine32a__statusfp(void);
__ASM_GLOBAL_FUNC(wine32a__statusfp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__statusfp") "\n"
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

extern WINAPI unsigned int wine32b__clearfp(void)
{
	TRACE("Enter _clearfp\n");
	return p_clearfp();
}

extern WINAPI void wine32a__clearfp(void);
__ASM_GLOBAL_FUNC(wine32a__clearfp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__clearfp") "\n"
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

extern WINAPI int * wine32b___fpecode(void)
{
	TRACE("Enter __fpecode\n");
	return p__fpecode();
}

extern WINAPI void wine32a___fpecode(void);
__ASM_GLOBAL_FUNC(wine32a___fpecode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___fpecode") "\n"
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

extern WINAPI unsigned int wine32b__control87(unsigned int newval, unsigned int mask)
{
	TRACE("Enter _control87\n");
	return p_control87(newval, mask);
}

extern WINAPI void wine32a__control87(void);
__ASM_GLOBAL_FUNC(wine32a__control87,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__control87") "\n"
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

extern WINAPI unsigned int wine32b__controlfp(unsigned int newval, unsigned int mask)
{
	TRACE("Enter _controlfp\n");
	return p_controlfp(newval, mask);
}

extern WINAPI void wine32a__controlfp(void);
__ASM_GLOBAL_FUNC(wine32a__controlfp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__controlfp") "\n"
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

extern WINAPI void wine32b__set_controlfp(unsigned int newval, unsigned int mask)
{
	TRACE("Enter _set_controlfp\n");
	return p_set_controlfp(newval, mask);
}

extern WINAPI void wine32a__set_controlfp(void);
__ASM_GLOBAL_FUNC(wine32a__set_controlfp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__set_controlfp") "\n"
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

extern WINAPI int wine32b__controlfp_s(unsigned int * cur, unsigned int newval, unsigned int mask)
{
	TRACE("Enter _controlfp_s\n");
	return p_controlfp_s(cur, newval, mask);
}

extern WINAPI void wine32a__controlfp_s(void);
__ASM_GLOBAL_FUNC(wine32a__controlfp_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__controlfp_s") "\n"
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

extern WINAPI void wine32b__fpreset(void)
{
	TRACE("Enter _fpreset\n");
	return p_fpreset();
}

extern WINAPI void wine32a__fpreset(void);
__ASM_GLOBAL_FUNC(wine32a__fpreset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__fpreset") "\n"
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


static WINAPI unsigned char * (*p__p__mbctype)(void);
static WINAPI int * (*p__p___mb_cur_max)(void);
static WINAPI int (*p_setmbcp)(int cp);
static WINAPI int (*p_getmbcp)(void);
static WINAPI unsigned int (*p_mbsnextc)(const unsigned char * str);
static WINAPI unsigned int (*p_mbctolower)(unsigned int c);
static WINAPI unsigned int (*p_mbctoupper)(unsigned int c);
static WINAPI unsigned int (*p_mbctombb)(unsigned int c);
static WINAPI unsigned int (*p_mbcjistojms)(unsigned int c);
static WINAPI unsigned int (*p_mbcjmstojis)(unsigned int c);
static WINAPI unsigned char * (*p_mbsdec)(const unsigned char * start, const unsigned char * cur);
static WINAPI unsigned int (*p_mbclen)(const unsigned char * str);
static WINAPI unsigned char * (*p_mbsinc)(const unsigned char * str);
static WINAPI unsigned char * (*p_mbsninc)(const unsigned char * str, MSVCRT_size_t num);
static WINAPI MSVCRT_size_t (*p_mbsnlen_l)(const unsigned char * str, MSVCRT_size_t maxsize, MSVCRT__locale_t locale);
static WINAPI MSVCRT_size_t (*p_mbslen)(const unsigned char * str);
static WINAPI MSVCRT_size_t (*p_mbslen_l)(const unsigned char * str, MSVCRT__locale_t locale);
static WINAPI MSVCRT_size_t (*p_mbsnlen)(const unsigned char * str, MSVCRT_size_t maxsize);
static WINAPI int (*p_mbccpy_s_l)(unsigned char * dest, MSVCRT_size_t maxsize, int * copied, const unsigned char * src, MSVCRT__locale_t locale);
static WINAPI void (*p_mbccpy)(unsigned char * dest, const unsigned char * src);
static WINAPI void (*p_mbccpy_l)(unsigned char * dest, const unsigned char * src, MSVCRT__locale_t locale);
static WINAPI int (*p_mbccpy_s)(unsigned char * dest, MSVCRT_size_t maxsize, int * copied, const unsigned char * src);
static WINAPI unsigned char * (*p_mbsncpy)(unsigned char * dst, const unsigned char * src, MSVCRT_size_t n);
static WINAPI int (*p_mbsnbcpy_s_l)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t n, MSVCRT__locale_t locale);
static WINAPI int (*p_mbsnbcpy_s)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t n);
static WINAPI int (*p_mbscpy_s_l)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT__locale_t locale);
static WINAPI int (*p_mbscpy_s)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src);
static WINAPI unsigned char * (*p_mbsnbcpy)(unsigned char * dst, const unsigned char * src, MSVCRT_size_t n);
static WINAPI int (*p_mbscmp)(const unsigned char * str, const unsigned char * cmp);
static WINAPI int (*p_mbsnbicoll_l)(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len, MSVCRT__locale_t locale);
static WINAPI int (*p_mbsicoll_l)(const unsigned char * str1, const unsigned char * str2, MSVCRT__locale_t locale);
static WINAPI int (*p_mbsnbicoll)(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len);
static WINAPI int (*p_mbsicoll)(const unsigned char * str, const unsigned char * cmp);
static WINAPI int (*p_mbsnbcoll_l)(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len, MSVCRT__locale_t locale);
static WINAPI int (*p_mbscoll_l)(const unsigned char * str1, const unsigned char * str2, MSVCRT__locale_t locale);
static WINAPI int (*p_mbsnbcoll)(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len);
static WINAPI int (*p_mbscoll)(const unsigned char * str, const unsigned char * cmp);
static WINAPI int (*p_mbsicmp)(const unsigned char * str, const unsigned char * cmp);
static WINAPI int (*p_mbsncmp)(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len);
static WINAPI int (*p_mbsnbcmp)(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len);
static WINAPI int (*p_mbsnicmp)(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len);
static WINAPI int (*p_mbsnbicmp)(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbscat)(unsigned char * dst, const unsigned char * src);
static WINAPI int (*p_mbscat_s_l)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT__locale_t locale);
static WINAPI int (*p_mbscat_s)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src);
static WINAPI unsigned char * (*p_mbscpy)(unsigned char * dst, const unsigned char * src);
static WINAPI unsigned char * (*p_mbsstr)(const unsigned char * haystack, const unsigned char * needle);
static WINAPI unsigned char * (*p_mbschr)(const unsigned char * s, unsigned int x);
static WINAPI unsigned char * (*p_mbsrchr)(const unsigned char * s, unsigned int x);
static WINAPI unsigned char * (*p_mbstok_s_l)(unsigned char * str, const unsigned char * delim, unsigned char ** ctx, MSVCRT__locale_t locale);
static WINAPI unsigned char * (*p_mbstok_s)(unsigned char * str, const unsigned char * delim, unsigned char ** ctx);
static WINAPI unsigned char * (*p_mbstok_l)(unsigned char * str, const unsigned char * delim, MSVCRT__locale_t locale);
static WINAPI unsigned char * (*p_mbstok)(unsigned char * str, const unsigned char * delim);
static WINAPI unsigned int (*p_mbbtombc)(unsigned int c);
static WINAPI int (*p_mbbtype)(unsigned char c, int type);
static WINAPI int (*p_ismbbkana)(unsigned int c);
static WINAPI int (*p_ismbcdigit)(unsigned int ch);
static WINAPI int (*p_ismbcgraph)(unsigned int ch);
static WINAPI int (*p_ismbcalpha)(unsigned int ch);
static WINAPI int (*p_ismbclower)(unsigned int ch);
static WINAPI int (*p_ismbcupper)(unsigned int ch);
static WINAPI int (*p_ismbcsymbol)(unsigned int ch);
static WINAPI int (*p_ismbcalnum)(unsigned int ch);
static WINAPI int (*p_ismbcspace)(unsigned int ch);
static WINAPI int (*p_ismbcprint)(unsigned int ch);
static WINAPI int (*p_ismbcpunct)(unsigned int ch);
static WINAPI int (*p_ismbchira)(unsigned int c);
static WINAPI int (*p_ismbckata)(unsigned int c);
static WINAPI int (*p_ismbblead_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbblead)(unsigned int c);
static WINAPI int (*p_ismbbtrail_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbbtrail)(unsigned int c);
static WINAPI int (*p_ismbclegal_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbclegal)(unsigned int c);
static WINAPI int (*p_ismbslead)(const unsigned char * start, const unsigned char * str);
static WINAPI int (*p_ismbstrail)(const unsigned char * start, const unsigned char * str);
static WINAPI int (*p_mbsbtype)(const unsigned char * str, MSVCRT_size_t count);
static WINAPI unsigned char * (*p_mbsset)(unsigned char * str, unsigned int c);
static WINAPI unsigned char * (*p_mbsnbset)(unsigned char * str, unsigned int c, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbsnset)(unsigned char * str, unsigned int c, MSVCRT_size_t len);
static WINAPI MSVCRT_size_t (*p_mbsnccnt)(const unsigned char * str, MSVCRT_size_t len);
static WINAPI MSVCRT_size_t (*p_mbsnbcnt)(const unsigned char * str, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbsnbcat)(unsigned char * dst, const unsigned char * src, MSVCRT_size_t len);
static WINAPI int (*p_mbsnbcat_s)(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbsncat)(unsigned char * dst, const unsigned char * src, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbslwr)(unsigned char * s);
static WINAPI int (*p_mbslwr_s)(unsigned char * s, MSVCRT_size_t len);
static WINAPI unsigned char * (*p_mbsupr)(unsigned char * s);
static WINAPI int (*p_mbsupr_s)(unsigned char * s, MSVCRT_size_t len);
static WINAPI MSVCRT_size_t (*p_mbsspn)(const unsigned char * string, const unsigned char * set);
static WINAPI unsigned char * (*p_mbsspnp)(const unsigned char * string, const unsigned char * set);
static WINAPI MSVCRT_size_t (*p_mbscspn)(const unsigned char * str, const unsigned char * cmp);
static WINAPI unsigned char * (*p_mbsrev)(unsigned char * str);
static WINAPI unsigned char * (*p_mbspbrk)(const unsigned char * str, const unsigned char * accept);
static WINAPI MSVCRT_size_t (*p_mbstrlen_l)(const char * str, MSVCRT__locale_t locale);
static WINAPI MSVCRT_size_t (*p_mbstrlen)(const char * str);
static WINAPI unsigned int (*p_mbctohira)(unsigned int c);
static WINAPI unsigned int (*p_mbctokata)(unsigned int c);
static WINAPI int (*p_ismbcl0_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbcl0)(unsigned int c);
static WINAPI int (*p_ismbcl1_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbcl1)(unsigned int c);
static WINAPI int (*p_ismbcl2_l)(unsigned int c, MSVCRT__locale_t locale);
static WINAPI int (*p_ismbcl2)(unsigned int c);

extern WINAPI unsigned char * wine32b___p__mbctype(void)
{
	TRACE("Enter __p__mbctype\n");
	return p__p__mbctype();
}

extern WINAPI void wine32a___p__mbctype(void);
__ASM_GLOBAL_FUNC(wine32a___p__mbctype,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__mbctype") "\n"
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

extern WINAPI int * wine32b___p___mb_cur_max(void)
{
	TRACE("Enter __p___mb_cur_max\n");
	return p__p___mb_cur_max();
}

extern WINAPI void wine32a___p___mb_cur_max(void);
__ASM_GLOBAL_FUNC(wine32a___p___mb_cur_max,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p___mb_cur_max") "\n"
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

extern WINAPI int wine32b__setmbcp(int cp)
{
	TRACE("Enter _setmbcp\n");
	return p_setmbcp(cp);
}

extern WINAPI void wine32a__setmbcp(void);
__ASM_GLOBAL_FUNC(wine32a__setmbcp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__setmbcp") "\n"
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

extern WINAPI int wine32b__getmbcp(void)
{
	TRACE("Enter _getmbcp\n");
	return p_getmbcp();
}

extern WINAPI void wine32a__getmbcp(void);
__ASM_GLOBAL_FUNC(wine32a__getmbcp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getmbcp") "\n"
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

extern WINAPI unsigned int wine32b__mbsnextc(const unsigned char * str)
{
	TRACE("Enter _mbsnextc\n");
	return p_mbsnextc(str);
}

extern WINAPI void wine32a__mbsnextc(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnextc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnextc") "\n"
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

extern WINAPI unsigned int wine32b__mbctolower(unsigned int c)
{
	TRACE("Enter _mbctolower\n");
	return p_mbctolower(c);
}

extern WINAPI void wine32a__mbctolower(void);
__ASM_GLOBAL_FUNC(wine32a__mbctolower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbctolower") "\n"
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

extern WINAPI unsigned int wine32b__mbctoupper(unsigned int c)
{
	TRACE("Enter _mbctoupper\n");
	return p_mbctoupper(c);
}

extern WINAPI void wine32a__mbctoupper(void);
__ASM_GLOBAL_FUNC(wine32a__mbctoupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbctoupper") "\n"
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

extern WINAPI unsigned int wine32b__mbctombb(unsigned int c)
{
	TRACE("Enter _mbctombb\n");
	return p_mbctombb(c);
}

extern WINAPI void wine32a__mbctombb(void);
__ASM_GLOBAL_FUNC(wine32a__mbctombb,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbctombb") "\n"
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

extern WINAPI unsigned int wine32b__mbcjistojms(unsigned int c)
{
	TRACE("Enter _mbcjistojms\n");
	return p_mbcjistojms(c);
}

extern WINAPI void wine32a__mbcjistojms(void);
__ASM_GLOBAL_FUNC(wine32a__mbcjistojms,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbcjistojms") "\n"
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

extern WINAPI unsigned int wine32b__mbcjmstojis(unsigned int c)
{
	TRACE("Enter _mbcjmstojis\n");
	return p_mbcjmstojis(c);
}

extern WINAPI void wine32a__mbcjmstojis(void);
__ASM_GLOBAL_FUNC(wine32a__mbcjmstojis,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbcjmstojis") "\n"
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

extern WINAPI unsigned char * wine32b__mbsdec(const unsigned char * start, const unsigned char * cur)
{
	TRACE("Enter _mbsdec\n");
	return p_mbsdec(start, cur);
}

extern WINAPI void wine32a__mbsdec(void);
__ASM_GLOBAL_FUNC(wine32a__mbsdec,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsdec") "\n"
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

extern WINAPI unsigned int wine32b__mbclen(const unsigned char * str)
{
	TRACE("Enter _mbclen\n");
	return p_mbclen(str);
}

extern WINAPI void wine32a__mbclen(void);
__ASM_GLOBAL_FUNC(wine32a__mbclen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbclen") "\n"
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

extern WINAPI unsigned char * wine32b__mbsinc(const unsigned char * str)
{
	TRACE("Enter _mbsinc\n");
	return p_mbsinc(str);
}

extern WINAPI void wine32a__mbsinc(void);
__ASM_GLOBAL_FUNC(wine32a__mbsinc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsinc") "\n"
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

extern WINAPI unsigned char * wine32b__mbsninc(const unsigned char * str, MSVCRT_size_t num)
{
	TRACE("Enter _mbsninc\n");
	return p_mbsninc(str, num);
}

extern WINAPI void wine32a__mbsninc(void);
__ASM_GLOBAL_FUNC(wine32a__mbsninc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsninc") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbsnlen_l(const unsigned char * str, MSVCRT_size_t maxsize, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbsnlen_l\n");
	return p_mbsnlen_l(str, maxsize, locale);
}

extern WINAPI void wine32a__mbsnlen_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnlen_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnlen_l") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbslen(const unsigned char * str)
{
	TRACE("Enter _mbslen\n");
	return p_mbslen(str);
}

extern WINAPI void wine32a__mbslen(void);
__ASM_GLOBAL_FUNC(wine32a__mbslen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbslen") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbslen_l(const unsigned char * str, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbslen_l\n");
	return p_mbslen_l(str, locale);
}

extern WINAPI void wine32a__mbslen_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbslen_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbslen_l") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbsnlen(const unsigned char * str, MSVCRT_size_t maxsize)
{
	TRACE("Enter _mbsnlen\n");
	return p_mbsnlen(str, maxsize);
}

extern WINAPI void wine32a__mbsnlen(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnlen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnlen") "\n"
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

extern WINAPI int wine32b__mbccpy_s_l(unsigned char * dest, MSVCRT_size_t maxsize, int * copied, const unsigned char * src, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbccpy_s_l\n");
	return p_mbccpy_s_l(dest, maxsize, copied, src, locale);
}

extern WINAPI void wine32a__mbccpy_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbccpy_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbccpy_s_l") "\n"
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

extern WINAPI void wine32b__mbccpy(unsigned char * dest, const unsigned char * src)
{
	TRACE("Enter _mbccpy\n");
	return p_mbccpy(dest, src);
}

extern WINAPI void wine32a__mbccpy(void);
__ASM_GLOBAL_FUNC(wine32a__mbccpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbccpy") "\n"
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

extern WINAPI void wine32b__mbccpy_l(unsigned char * dest, const unsigned char * src, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbccpy_l\n");
	return p_mbccpy_l(dest, src, locale);
}

extern WINAPI void wine32a__mbccpy_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbccpy_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbccpy_l") "\n"
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

extern WINAPI int wine32b__mbccpy_s(unsigned char * dest, MSVCRT_size_t maxsize, int * copied, const unsigned char * src)
{
	TRACE("Enter _mbccpy_s\n");
	return p_mbccpy_s(dest, maxsize, copied, src);
}

extern WINAPI void wine32a__mbccpy_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbccpy_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbccpy_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbsncpy(unsigned char * dst, const unsigned char * src, MSVCRT_size_t n)
{
	TRACE("Enter _mbsncpy\n");
	return p_mbsncpy(dst, src, n);
}

extern WINAPI void wine32a__mbsncpy(void);
__ASM_GLOBAL_FUNC(wine32a__mbsncpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsncpy") "\n"
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

extern WINAPI int wine32b__mbsnbcpy_s_l(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t n, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbsnbcpy_s_l\n");
	return p_mbsnbcpy_s_l(dst, size, src, n, locale);
}

extern WINAPI void wine32a__mbsnbcpy_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcpy_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcpy_s_l") "\n"
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

extern WINAPI int wine32b__mbsnbcpy_s(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t n)
{
	TRACE("Enter _mbsnbcpy_s\n");
	return p_mbsnbcpy_s(dst, size, src, n);
}

extern WINAPI void wine32a__mbsnbcpy_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcpy_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcpy_s") "\n"
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

extern WINAPI int wine32b__mbscpy_s_l(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbscpy_s_l\n");
	return p_mbscpy_s_l(dst, size, src, locale);
}

extern WINAPI void wine32a__mbscpy_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbscpy_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscpy_s_l") "\n"
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

extern WINAPI int wine32b__mbscpy_s(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src)
{
	TRACE("Enter _mbscpy_s\n");
	return p_mbscpy_s(dst, size, src);
}

extern WINAPI void wine32a__mbscpy_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbscpy_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscpy_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbsnbcpy(unsigned char * dst, const unsigned char * src, MSVCRT_size_t n)
{
	TRACE("Enter _mbsnbcpy\n");
	return p_mbsnbcpy(dst, src, n);
}

extern WINAPI void wine32a__mbsnbcpy(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcpy") "\n"
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

extern WINAPI int wine32b__mbscmp(const unsigned char * str, const unsigned char * cmp)
{
	TRACE("Enter _mbscmp\n");
	return p_mbscmp(str, cmp);
}

extern WINAPI void wine32a__mbscmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbscmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscmp") "\n"
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

extern WINAPI int wine32b__mbsnbicoll_l(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbsnbicoll_l\n");
	return p_mbsnbicoll_l(str1, str2, len, locale);
}

extern WINAPI void wine32a__mbsnbicoll_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbicoll_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbicoll_l") "\n"
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

extern WINAPI int wine32b__mbsicoll_l(const unsigned char * str1, const unsigned char * str2, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbsicoll_l\n");
	return p_mbsicoll_l(str1, str2, locale);
}

extern WINAPI void wine32a__mbsicoll_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbsicoll_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsicoll_l") "\n"
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

extern WINAPI int wine32b__mbsnbicoll(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbicoll\n");
	return p_mbsnbicoll(str1, str2, len);
}

extern WINAPI void wine32a__mbsnbicoll(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbicoll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbicoll") "\n"
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

extern WINAPI int wine32b__mbsicoll(const unsigned char * str, const unsigned char * cmp)
{
	TRACE("Enter _mbsicoll\n");
	return p_mbsicoll(str, cmp);
}

extern WINAPI void wine32a__mbsicoll(void);
__ASM_GLOBAL_FUNC(wine32a__mbsicoll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsicoll") "\n"
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

extern WINAPI int wine32b__mbsnbcoll_l(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbsnbcoll_l\n");
	return p_mbsnbcoll_l(str1, str2, len, locale);
}

extern WINAPI void wine32a__mbsnbcoll_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcoll_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcoll_l") "\n"
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

extern WINAPI int wine32b__mbscoll_l(const unsigned char * str1, const unsigned char * str2, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbscoll_l\n");
	return p_mbscoll_l(str1, str2, locale);
}

extern WINAPI void wine32a__mbscoll_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbscoll_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscoll_l") "\n"
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

extern WINAPI int wine32b__mbsnbcoll(const unsigned char * str1, const unsigned char * str2, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbcoll\n");
	return p_mbsnbcoll(str1, str2, len);
}

extern WINAPI void wine32a__mbsnbcoll(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcoll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcoll") "\n"
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

extern WINAPI int wine32b__mbscoll(const unsigned char * str, const unsigned char * cmp)
{
	TRACE("Enter _mbscoll\n");
	return p_mbscoll(str, cmp);
}

extern WINAPI void wine32a__mbscoll(void);
__ASM_GLOBAL_FUNC(wine32a__mbscoll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscoll") "\n"
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

extern WINAPI int wine32b__mbsicmp(const unsigned char * str, const unsigned char * cmp)
{
	TRACE("Enter _mbsicmp\n");
	return p_mbsicmp(str, cmp);
}

extern WINAPI void wine32a__mbsicmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsicmp") "\n"
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

extern WINAPI int wine32b__mbsncmp(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len)
{
	TRACE("Enter _mbsncmp\n");
	return p_mbsncmp(str, cmp, len);
}

extern WINAPI void wine32a__mbsncmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsncmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsncmp") "\n"
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

extern WINAPI int wine32b__mbsnbcmp(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbcmp\n");
	return p_mbsnbcmp(str, cmp, len);
}

extern WINAPI void wine32a__mbsnbcmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcmp") "\n"
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

extern WINAPI int wine32b__mbsnicmp(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnicmp\n");
	return p_mbsnicmp(str, cmp, len);
}

extern WINAPI void wine32a__mbsnicmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnicmp") "\n"
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

extern WINAPI int wine32b__mbsnbicmp(const unsigned char * str, const unsigned char * cmp, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbicmp\n");
	return p_mbsnbicmp(str, cmp, len);
}

extern WINAPI void wine32a__mbsnbicmp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbicmp") "\n"
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

extern WINAPI unsigned char * wine32b__mbscat(unsigned char * dst, const unsigned char * src)
{
	TRACE("Enter _mbscat\n");
	return p_mbscat(dst, src);
}

extern WINAPI void wine32a__mbscat(void);
__ASM_GLOBAL_FUNC(wine32a__mbscat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscat") "\n"
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

extern WINAPI int wine32b__mbscat_s_l(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbscat_s_l\n");
	return p_mbscat_s_l(dst, size, src, locale);
}

extern WINAPI void wine32a__mbscat_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbscat_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscat_s_l") "\n"
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

extern WINAPI int wine32b__mbscat_s(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src)
{
	TRACE("Enter _mbscat_s\n");
	return p_mbscat_s(dst, size, src);
}

extern WINAPI void wine32a__mbscat_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbscat_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscat_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbscpy(unsigned char * dst, const unsigned char * src)
{
	TRACE("Enter _mbscpy\n");
	return p_mbscpy(dst, src);
}

extern WINAPI void wine32a__mbscpy(void);
__ASM_GLOBAL_FUNC(wine32a__mbscpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscpy") "\n"
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

extern WINAPI unsigned char * wine32b__mbsstr(const unsigned char * haystack, const unsigned char * needle)
{
	TRACE("Enter _mbsstr\n");
	return p_mbsstr(haystack, needle);
}

extern WINAPI void wine32a__mbsstr(void);
__ASM_GLOBAL_FUNC(wine32a__mbsstr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsstr") "\n"
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

extern WINAPI unsigned char * wine32b__mbschr(const unsigned char * s, unsigned int x)
{
	TRACE("Enter _mbschr\n");
	return p_mbschr(s, x);
}

extern WINAPI void wine32a__mbschr(void);
__ASM_GLOBAL_FUNC(wine32a__mbschr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbschr") "\n"
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

extern WINAPI unsigned char * wine32b__mbsrchr(const unsigned char * s, unsigned int x)
{
	TRACE("Enter _mbsrchr\n");
	return p_mbsrchr(s, x);
}

extern WINAPI void wine32a__mbsrchr(void);
__ASM_GLOBAL_FUNC(wine32a__mbsrchr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsrchr") "\n"
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

extern WINAPI unsigned char * wine32b__mbstok_s_l(unsigned char * str, const unsigned char * delim, unsigned char ** ctx, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbstok_s_l\n");
	return p_mbstok_s_l(str, delim, ctx, locale);
}

extern WINAPI void wine32a__mbstok_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbstok_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstok_s_l") "\n"
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

extern WINAPI unsigned char * wine32b__mbstok_s(unsigned char * str, const unsigned char * delim, unsigned char ** ctx)
{
	TRACE("Enter _mbstok_s\n");
	return p_mbstok_s(str, delim, ctx);
}

extern WINAPI void wine32a__mbstok_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbstok_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstok_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbstok_l(unsigned char * str, const unsigned char * delim, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbstok_l\n");
	return p_mbstok_l(str, delim, locale);
}

extern WINAPI void wine32a__mbstok_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbstok_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstok_l") "\n"
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

extern WINAPI unsigned char * wine32b__mbstok(unsigned char * str, const unsigned char * delim)
{
	TRACE("Enter _mbstok\n");
	return p_mbstok(str, delim);
}

extern WINAPI void wine32a__mbstok(void);
__ASM_GLOBAL_FUNC(wine32a__mbstok,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstok") "\n"
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

extern WINAPI unsigned int wine32b__mbbtombc(unsigned int c)
{
	TRACE("Enter _mbbtombc\n");
	return p_mbbtombc(c);
}

extern WINAPI void wine32a__mbbtombc(void);
__ASM_GLOBAL_FUNC(wine32a__mbbtombc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbbtombc") "\n"
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

extern WINAPI int wine32b__mbbtype(unsigned char c, int type)
{
	TRACE("Enter _mbbtype\n");
	return p_mbbtype(c, type);
}

extern WINAPI void wine32a__mbbtype(void);
__ASM_GLOBAL_FUNC(wine32a__mbbtype,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbbtype") "\n"
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

extern WINAPI int wine32b__ismbbkana(unsigned int c)
{
	TRACE("Enter _ismbbkana\n");
	return p_ismbbkana(c);
}

extern WINAPI void wine32a__ismbbkana(void);
__ASM_GLOBAL_FUNC(wine32a__ismbbkana,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbbkana") "\n"
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

extern WINAPI int wine32b__ismbcdigit(unsigned int ch)
{
	TRACE("Enter _ismbcdigit\n");
	return p_ismbcdigit(ch);
}

extern WINAPI void wine32a__ismbcdigit(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcdigit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcdigit") "\n"
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

extern WINAPI int wine32b__ismbcgraph(unsigned int ch)
{
	TRACE("Enter _ismbcgraph\n");
	return p_ismbcgraph(ch);
}

extern WINAPI void wine32a__ismbcgraph(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcgraph,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcgraph") "\n"
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

extern WINAPI int wine32b__ismbcalpha(unsigned int ch)
{
	TRACE("Enter _ismbcalpha\n");
	return p_ismbcalpha(ch);
}

extern WINAPI void wine32a__ismbcalpha(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcalpha,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcalpha") "\n"
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

extern WINAPI int wine32b__ismbclower(unsigned int ch)
{
	TRACE("Enter _ismbclower\n");
	return p_ismbclower(ch);
}

extern WINAPI void wine32a__ismbclower(void);
__ASM_GLOBAL_FUNC(wine32a__ismbclower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbclower") "\n"
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

extern WINAPI int wine32b__ismbcupper(unsigned int ch)
{
	TRACE("Enter _ismbcupper\n");
	return p_ismbcupper(ch);
}

extern WINAPI void wine32a__ismbcupper(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcupper") "\n"
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

extern WINAPI int wine32b__ismbcsymbol(unsigned int ch)
{
	TRACE("Enter _ismbcsymbol\n");
	return p_ismbcsymbol(ch);
}

extern WINAPI void wine32a__ismbcsymbol(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcsymbol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcsymbol") "\n"
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

extern WINAPI int wine32b__ismbcalnum(unsigned int ch)
{
	TRACE("Enter _ismbcalnum\n");
	return p_ismbcalnum(ch);
}

extern WINAPI void wine32a__ismbcalnum(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcalnum,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcalnum") "\n"
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

extern WINAPI int wine32b__ismbcspace(unsigned int ch)
{
	TRACE("Enter _ismbcspace\n");
	return p_ismbcspace(ch);
}

extern WINAPI void wine32a__ismbcspace(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcspace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcspace") "\n"
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

extern WINAPI int wine32b__ismbcprint(unsigned int ch)
{
	TRACE("Enter _ismbcprint\n");
	return p_ismbcprint(ch);
}

extern WINAPI void wine32a__ismbcprint(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcprint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcprint") "\n"
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

extern WINAPI int wine32b__ismbcpunct(unsigned int ch)
{
	TRACE("Enter _ismbcpunct\n");
	return p_ismbcpunct(ch);
}

extern WINAPI void wine32a__ismbcpunct(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcpunct,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcpunct") "\n"
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

extern WINAPI int wine32b__ismbchira(unsigned int c)
{
	TRACE("Enter _ismbchira\n");
	return p_ismbchira(c);
}

extern WINAPI void wine32a__ismbchira(void);
__ASM_GLOBAL_FUNC(wine32a__ismbchira,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbchira") "\n"
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

extern WINAPI int wine32b__ismbckata(unsigned int c)
{
	TRACE("Enter _ismbckata\n");
	return p_ismbckata(c);
}

extern WINAPI void wine32a__ismbckata(void);
__ASM_GLOBAL_FUNC(wine32a__ismbckata,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbckata") "\n"
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

extern WINAPI int wine32b__ismbblead_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbblead_l\n");
	return p_ismbblead_l(c, locale);
}

extern WINAPI void wine32a__ismbblead_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbblead_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbblead_l") "\n"
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

extern WINAPI int wine32b__ismbblead(unsigned int c)
{
	TRACE("Enter _ismbblead\n");
	return p_ismbblead(c);
}

extern WINAPI void wine32a__ismbblead(void);
__ASM_GLOBAL_FUNC(wine32a__ismbblead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbblead") "\n"
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

extern WINAPI int wine32b__ismbbtrail_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbbtrail_l\n");
	return p_ismbbtrail_l(c, locale);
}

extern WINAPI void wine32a__ismbbtrail_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbbtrail_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbbtrail_l") "\n"
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

extern WINAPI int wine32b__ismbbtrail(unsigned int c)
{
	TRACE("Enter _ismbbtrail\n");
	return p_ismbbtrail(c);
}

extern WINAPI void wine32a__ismbbtrail(void);
__ASM_GLOBAL_FUNC(wine32a__ismbbtrail,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbbtrail") "\n"
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

extern WINAPI int wine32b__ismbclegal_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbclegal_l\n");
	return p_ismbclegal_l(c, locale);
}

extern WINAPI void wine32a__ismbclegal_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbclegal_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbclegal_l") "\n"
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

extern WINAPI int wine32b__ismbclegal(unsigned int c)
{
	TRACE("Enter _ismbclegal\n");
	return p_ismbclegal(c);
}

extern WINAPI void wine32a__ismbclegal(void);
__ASM_GLOBAL_FUNC(wine32a__ismbclegal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbclegal") "\n"
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

extern WINAPI int wine32b__ismbslead(const unsigned char * start, const unsigned char * str)
{
	TRACE("Enter _ismbslead\n");
	return p_ismbslead(start, str);
}

extern WINAPI void wine32a__ismbslead(void);
__ASM_GLOBAL_FUNC(wine32a__ismbslead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbslead") "\n"
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

extern WINAPI int wine32b__ismbstrail(const unsigned char * start, const unsigned char * str)
{
	TRACE("Enter _ismbstrail\n");
	return p_ismbstrail(start, str);
}

extern WINAPI void wine32a__ismbstrail(void);
__ASM_GLOBAL_FUNC(wine32a__ismbstrail,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbstrail") "\n"
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

extern WINAPI int wine32b__mbsbtype(const unsigned char * str, MSVCRT_size_t count)
{
	TRACE("Enter _mbsbtype\n");
	return p_mbsbtype(str, count);
}

extern WINAPI void wine32a__mbsbtype(void);
__ASM_GLOBAL_FUNC(wine32a__mbsbtype,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsbtype") "\n"
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

extern WINAPI unsigned char * wine32b__mbsset(unsigned char * str, unsigned int c)
{
	TRACE("Enter _mbsset\n");
	return p_mbsset(str, c);
}

extern WINAPI void wine32a__mbsset(void);
__ASM_GLOBAL_FUNC(wine32a__mbsset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsset") "\n"
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

extern WINAPI unsigned char * wine32b__mbsnbset(unsigned char * str, unsigned int c, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbset\n");
	return p_mbsnbset(str, c, len);
}

extern WINAPI void wine32a__mbsnbset(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbset") "\n"
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

extern WINAPI unsigned char * wine32b__mbsnset(unsigned char * str, unsigned int c, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnset\n");
	return p_mbsnset(str, c, len);
}

extern WINAPI void wine32a__mbsnset(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnset") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbsnccnt(const unsigned char * str, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnccnt\n");
	return p_mbsnccnt(str, len);
}

extern WINAPI void wine32a__mbsnccnt(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnccnt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnccnt") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbsnbcnt(const unsigned char * str, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbcnt\n");
	return p_mbsnbcnt(str, len);
}

extern WINAPI void wine32a__mbsnbcnt(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcnt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcnt") "\n"
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

extern WINAPI unsigned char * wine32b__mbsnbcat(unsigned char * dst, const unsigned char * src, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbcat\n");
	return p_mbsnbcat(dst, src, len);
}

extern WINAPI void wine32a__mbsnbcat(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcat") "\n"
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

extern WINAPI int wine32b__mbsnbcat_s(unsigned char * dst, MSVCRT_size_t size, const unsigned char * src, MSVCRT_size_t len)
{
	TRACE("Enter _mbsnbcat_s\n");
	return p_mbsnbcat_s(dst, size, src, len);
}

extern WINAPI void wine32a__mbsnbcat_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbsnbcat_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsnbcat_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbsncat(unsigned char * dst, const unsigned char * src, MSVCRT_size_t len)
{
	TRACE("Enter _mbsncat\n");
	return p_mbsncat(dst, src, len);
}

extern WINAPI void wine32a__mbsncat(void);
__ASM_GLOBAL_FUNC(wine32a__mbsncat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsncat") "\n"
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

extern WINAPI unsigned char * wine32b__mbslwr(unsigned char * s)
{
	TRACE("Enter _mbslwr\n");
	return p_mbslwr(s);
}

extern WINAPI void wine32a__mbslwr(void);
__ASM_GLOBAL_FUNC(wine32a__mbslwr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbslwr") "\n"
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

extern WINAPI int wine32b__mbslwr_s(unsigned char * s, MSVCRT_size_t len)
{
	TRACE("Enter _mbslwr_s\n");
	return p_mbslwr_s(s, len);
}

extern WINAPI void wine32a__mbslwr_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbslwr_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbslwr_s") "\n"
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

extern WINAPI unsigned char * wine32b__mbsupr(unsigned char * s)
{
	TRACE("Enter _mbsupr\n");
	return p_mbsupr(s);
}

extern WINAPI void wine32a__mbsupr(void);
__ASM_GLOBAL_FUNC(wine32a__mbsupr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsupr") "\n"
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

extern WINAPI int wine32b__mbsupr_s(unsigned char * s, MSVCRT_size_t len)
{
	TRACE("Enter _mbsupr_s\n");
	return p_mbsupr_s(s, len);
}

extern WINAPI void wine32a__mbsupr_s(void);
__ASM_GLOBAL_FUNC(wine32a__mbsupr_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsupr_s") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbsspn(const unsigned char * string, const unsigned char * set)
{
	TRACE("Enter _mbsspn\n");
	return p_mbsspn(string, set);
}

extern WINAPI void wine32a__mbsspn(void);
__ASM_GLOBAL_FUNC(wine32a__mbsspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsspn") "\n"
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

extern WINAPI unsigned char * wine32b__mbsspnp(const unsigned char * string, const unsigned char * set)
{
	TRACE("Enter _mbsspnp\n");
	return p_mbsspnp(string, set);
}

extern WINAPI void wine32a__mbsspnp(void);
__ASM_GLOBAL_FUNC(wine32a__mbsspnp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsspnp") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbscspn(const unsigned char * str, const unsigned char * cmp)
{
	TRACE("Enter _mbscspn\n");
	return p_mbscspn(str, cmp);
}

extern WINAPI void wine32a__mbscspn(void);
__ASM_GLOBAL_FUNC(wine32a__mbscspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbscspn") "\n"
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

extern WINAPI unsigned char * wine32b__mbsrev(unsigned char * str)
{
	TRACE("Enter _mbsrev\n");
	return p_mbsrev(str);
}

extern WINAPI void wine32a__mbsrev(void);
__ASM_GLOBAL_FUNC(wine32a__mbsrev,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbsrev") "\n"
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

extern WINAPI unsigned char * wine32b__mbspbrk(const unsigned char * str, const unsigned char * accept)
{
	TRACE("Enter _mbspbrk\n");
	return p_mbspbrk(str, accept);
}

extern WINAPI void wine32a__mbspbrk(void);
__ASM_GLOBAL_FUNC(wine32a__mbspbrk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbspbrk") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbstrlen_l(const char * str, MSVCRT__locale_t locale)
{
	TRACE("Enter _mbstrlen_l\n");
	return p_mbstrlen_l(str, locale);
}

extern WINAPI void wine32a__mbstrlen_l(void);
__ASM_GLOBAL_FUNC(wine32a__mbstrlen_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstrlen_l") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__mbstrlen(const char * str)
{
	TRACE("Enter _mbstrlen\n");
	return p_mbstrlen(str);
}

extern WINAPI void wine32a__mbstrlen(void);
__ASM_GLOBAL_FUNC(wine32a__mbstrlen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbstrlen") "\n"
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

extern WINAPI unsigned int wine32b__mbctohira(unsigned int c)
{
	TRACE("Enter _mbctohira\n");
	return p_mbctohira(c);
}

extern WINAPI void wine32a__mbctohira(void);
__ASM_GLOBAL_FUNC(wine32a__mbctohira,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbctohira") "\n"
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

extern WINAPI unsigned int wine32b__mbctokata(unsigned int c)
{
	TRACE("Enter _mbctokata\n");
	return p_mbctokata(c);
}

extern WINAPI void wine32a__mbctokata(void);
__ASM_GLOBAL_FUNC(wine32a__mbctokata,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__mbctokata") "\n"
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

extern WINAPI int wine32b__ismbcl0_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbcl0_l\n");
	return p_ismbcl0_l(c, locale);
}

extern WINAPI void wine32a__ismbcl0_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl0_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl0_l") "\n"
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

extern WINAPI int wine32b__ismbcl0(unsigned int c)
{
	TRACE("Enter _ismbcl0\n");
	return p_ismbcl0(c);
}

extern WINAPI void wine32a__ismbcl0(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl0,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl0") "\n"
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

extern WINAPI int wine32b__ismbcl1_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbcl1_l\n");
	return p_ismbcl1_l(c, locale);
}

extern WINAPI void wine32a__ismbcl1_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl1_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl1_l") "\n"
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

extern WINAPI int wine32b__ismbcl1(unsigned int c)
{
	TRACE("Enter _ismbcl1\n");
	return p_ismbcl1(c);
}

extern WINAPI void wine32a__ismbcl1(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl1,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl1") "\n"
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

extern WINAPI int wine32b__ismbcl2_l(unsigned int c, MSVCRT__locale_t locale)
{
	TRACE("Enter _ismbcl2_l\n");
	return p_ismbcl2_l(c, locale);
}

extern WINAPI void wine32a__ismbcl2_l(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl2_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl2_l") "\n"
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

extern WINAPI int wine32b__ismbcl2(unsigned int c)
{
	TRACE("Enter _ismbcl2\n");
	return p_ismbcl2(c);
}

extern WINAPI void wine32a__ismbcl2(void);
__ASM_GLOBAL_FUNC(wine32a__ismbcl2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ismbcl2") "\n"
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

static WINAPI void * (*p_lfind)(const void * match, const void * start, unsigned int * array_size, unsigned int elem_size, int (*)(const void *, const void *) __attribute__((ms_abi)) cf);
static WINAPI void * (*p_lfind_s)(const void * match, const void * start, unsigned int * array_size, unsigned int elem_size, int (*)(void *, const void *, const void *) __attribute__((ms_abi)) cf, void * context);
static WINAPI void * (*p_lsearch)(const void * match, void * start, unsigned int * array_size, unsigned int elem_size, int (*)(const void *, const void *) __attribute__((ms_abi)) cf);

extern WINAPI void * wine32b__lfind(const void * match, const void * start, unsigned int * array_size, unsigned int elem_size, int (*)(const void *, const void *) __attribute__((ms_abi)) cf)
{
	TRACE("Enter _lfind\n");
	return p_lfind(match, start, array_size, elem_size, cf);
}

extern WINAPI void wine32a__lfind(void);
__ASM_GLOBAL_FUNC(wine32a__lfind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lfind") "\n"
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

extern WINAPI void * wine32b__lfind_s(const void * match, const void * start, unsigned int * array_size, unsigned int elem_size, int (*)(void *, const void *, const void *) __attribute__((ms_abi)) cf, void * context)
{
	TRACE("Enter _lfind_s\n");
	return p_lfind_s(match, start, array_size, elem_size, cf, context);
}

extern WINAPI void wine32a__lfind_s(void);
__ASM_GLOBAL_FUNC(wine32a__lfind_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lfind_s") "\n"
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

extern WINAPI void * wine32b__lsearch(const void * match, void * start, unsigned int * array_size, unsigned int elem_size, int (*)(const void *, const void *) __attribute__((ms_abi)) cf)
{
	TRACE("Enter _lsearch\n");
	return p_lsearch(match, start, array_size, elem_size, cf);
}

extern WINAPI void wine32a__lsearch(void);
__ASM_GLOBAL_FUNC(wine32a__lsearch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lsearch") "\n"
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


static WINAPI MSVCRT_intptr_t (*p_cwait)(int * status, MSVCRT_intptr_t pid, int action);
static WINAPI MSVCRT_intptr_t (*p_wexecl)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0);
static WINAPI MSVCRT_intptr_t (*p_execl)(const char * name, const char * arg0);
static WINAPI MSVCRT_intptr_t (*p_wexecle)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0);
static WINAPI MSVCRT_intptr_t (*p_execle)(const char * name, const char * arg0);
static WINAPI MSVCRT_intptr_t (*p_wexeclp)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0);
static WINAPI MSVCRT_intptr_t (*p_execlp)(const char * name, const char * arg0);
static WINAPI MSVCRT_intptr_t (*p_wexeclpe)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0);
static WINAPI MSVCRT_intptr_t (*p_execlpe)(const char * name, const char * arg0);
static WINAPI MSVCRT_intptr_t (*p_wexecv)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv);
static WINAPI MSVCRT_intptr_t (*p_execv)(const char * name, const char *const * argv);
static WINAPI MSVCRT_intptr_t (*p_wexecve)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv, const MSVCRT_wchar_t *const * envv);
static WINAPI MSVCRT_intptr_t (*p_wexecvpe)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv, const MSVCRT_wchar_t *const * envv);
static WINAPI MSVCRT_intptr_t (*p_execvpe)(const char * name, const char *const * argv, const char *const * envv);
static WINAPI MSVCRT_intptr_t (*p_wexecvp)(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv);
static WINAPI MSVCRT_intptr_t (*p_execvp)(const char * name, const char *const * argv);
static WINAPI int (*p_wsystem)(const MSVCRT_wchar_t * cmd);
static WINAPI MSVCRT_intptr_t (*p_loaddll)(const char * dllname);
static WINAPI int (*p_unloaddll)(MSVCRT_intptr_t dll);
static WINAPI void * (*p_getdllprocaddr)(MSVCRT_intptr_t dll, const char * name, int ordinal);
static WINAPI int (*p_getpid)(void);

extern WINAPI MSVCRT_intptr_t wine32b__cwait(int * status, MSVCRT_intptr_t pid, int action)
{
	TRACE("Enter _cwait\n");
	return p_cwait(status, pid, action);
}

extern WINAPI void wine32a__cwait(void);
__ASM_GLOBAL_FUNC(wine32a__cwait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwait") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecl(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0)
{
	TRACE("Enter _wexecl\n");
	return p_wexecl(name, arg0);
}

extern WINAPI void wine32a__wexecl(void);
__ASM_GLOBAL_FUNC(wine32a__wexecl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecl") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execl(const char * name, const char * arg0)
{
	TRACE("Enter _execl\n");
	return p_execl(name, arg0);
}

extern WINAPI void wine32a__execl(void);
__ASM_GLOBAL_FUNC(wine32a__execl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execl") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecle(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0)
{
	TRACE("Enter _wexecle\n");
	return p_wexecle(name, arg0);
}

extern WINAPI void wine32a__wexecle(void);
__ASM_GLOBAL_FUNC(wine32a__wexecle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecle") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execle(const char * name, const char * arg0)
{
	TRACE("Enter _execle\n");
	return p_execle(name, arg0);
}

extern WINAPI void wine32a__execle(void);
__ASM_GLOBAL_FUNC(wine32a__execle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execle") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexeclp(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0)
{
	TRACE("Enter _wexeclp\n");
	return p_wexeclp(name, arg0);
}

extern WINAPI void wine32a__wexeclp(void);
__ASM_GLOBAL_FUNC(wine32a__wexeclp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexeclp") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execlp(const char * name, const char * arg0)
{
	TRACE("Enter _execlp\n");
	return p_execlp(name, arg0);
}

extern WINAPI void wine32a__execlp(void);
__ASM_GLOBAL_FUNC(wine32a__execlp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execlp") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexeclpe(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t * arg0)
{
	TRACE("Enter _wexeclpe\n");
	return p_wexeclpe(name, arg0);
}

extern WINAPI void wine32a__wexeclpe(void);
__ASM_GLOBAL_FUNC(wine32a__wexeclpe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexeclpe") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execlpe(const char * name, const char * arg0)
{
	TRACE("Enter _execlpe\n");
	return p_execlpe(name, arg0);
}

extern WINAPI void wine32a__execlpe(void);
__ASM_GLOBAL_FUNC(wine32a__execlpe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execlpe") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecv(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv)
{
	TRACE("Enter _wexecv\n");
	return p_wexecv(name, argv);
}

extern WINAPI void wine32a__wexecv(void);
__ASM_GLOBAL_FUNC(wine32a__wexecv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecv") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execv(const char * name, const char *const * argv)
{
	TRACE("Enter _execv\n");
	return p_execv(name, argv);
}

extern WINAPI void wine32a__execv(void);
__ASM_GLOBAL_FUNC(wine32a__execv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execv") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecve(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv, const MSVCRT_wchar_t *const * envv)
{
	TRACE("Enter _wexecve\n");
	return p_wexecve(name, argv, envv);
}

extern WINAPI void wine32a__wexecve(void);
__ASM_GLOBAL_FUNC(wine32a__wexecve,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecve") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecvpe(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv, const MSVCRT_wchar_t *const * envv)
{
	TRACE("Enter _wexecvpe\n");
	return p_wexecvpe(name, argv, envv);
}

extern WINAPI void wine32a__wexecvpe(void);
__ASM_GLOBAL_FUNC(wine32a__wexecvpe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecvpe") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execvpe(const char * name, const char *const * argv, const char *const * envv)
{
	TRACE("Enter _execvpe\n");
	return p_execvpe(name, argv, envv);
}

extern WINAPI void wine32a__execvpe(void);
__ASM_GLOBAL_FUNC(wine32a__execvpe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execvpe") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__wexecvp(const MSVCRT_wchar_t * name, const MSVCRT_wchar_t *const * argv)
{
	TRACE("Enter _wexecvp\n");
	return p_wexecvp(name, argv);
}

extern WINAPI void wine32a__wexecvp(void);
__ASM_GLOBAL_FUNC(wine32a__wexecvp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wexecvp") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__execvp(const char * name, const char *const * argv)
{
	TRACE("Enter _execvp\n");
	return p_execvp(name, argv);
}

extern WINAPI void wine32a__execvp(void);
__ASM_GLOBAL_FUNC(wine32a__execvp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__execvp") "\n"
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

extern WINAPI int wine32b__wsystem(const MSVCRT_wchar_t * cmd)
{
	TRACE("Enter _wsystem\n");
	return p_wsystem(cmd);
}

extern WINAPI void wine32a__wsystem(void);
__ASM_GLOBAL_FUNC(wine32a__wsystem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wsystem") "\n"
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

extern WINAPI MSVCRT_intptr_t wine32b__loaddll(const char * dllname)
{
	TRACE("Enter _loaddll\n");
	return p_loaddll(dllname);
}

extern WINAPI void wine32a__loaddll(void);
__ASM_GLOBAL_FUNC(wine32a__loaddll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__loaddll") "\n"
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

extern WINAPI int wine32b__unloaddll(MSVCRT_intptr_t dll)
{
	TRACE("Enter _unloaddll\n");
	return p_unloaddll(dll);
}

extern WINAPI void wine32a__unloaddll(void);
__ASM_GLOBAL_FUNC(wine32a__unloaddll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__unloaddll") "\n"
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

extern WINAPI void * wine32b__getdllprocaddr(MSVCRT_intptr_t dll, const char * name, int ordinal)
{
	TRACE("Enter _getdllprocaddr\n");
	return p_getdllprocaddr(dll, name, ordinal);
}

extern WINAPI void wine32a__getdllprocaddr(void);
__ASM_GLOBAL_FUNC(wine32a__getdllprocaddr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getdllprocaddr") "\n"
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

extern WINAPI int wine32b__getpid(void)
{
	TRACE("Enter _getpid\n");
	return p_getpid();
}

extern WINAPI void wine32a__getpid(void);
__ASM_GLOBAL_FUNC(wine32a__getpid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__getpid") "\n"
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

static WINAPI int (*p_cscanf)(const char * format);
static WINAPI int (*p_cscanf_l)(const char * format, MSVCRT__locale_t locale);
static WINAPI int (*p_cscanf_s)(const char * format);
static WINAPI int (*p_cscanf_s_l)(const char * format, MSVCRT__locale_t locale);
static WINAPI int (*p_cwscanf)(const MSVCRT_wchar_t * format);
static WINAPI int (*p_cwscanf_l)(const MSVCRT_wchar_t * format, MSVCRT__locale_t locale);
static WINAPI int (*p_cwscanf_s)(const MSVCRT_wchar_t * format);
static WINAPI int (*p_cwscanf_s_l)(const MSVCRT_wchar_t * format, MSVCRT__locale_t locale);

extern WINAPI int wine32b__cscanf(const char * format)
{
	TRACE("Enter _cscanf\n");
	return p_cscanf(format);
}

extern WINAPI void wine32a__cscanf(void);
__ASM_GLOBAL_FUNC(wine32a__cscanf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cscanf") "\n"
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

extern WINAPI int wine32b__cscanf_l(const char * format, MSVCRT__locale_t locale)
{
	TRACE("Enter _cscanf_l\n");
	return p_cscanf_l(format, locale);
}

extern WINAPI void wine32a__cscanf_l(void);
__ASM_GLOBAL_FUNC(wine32a__cscanf_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cscanf_l") "\n"
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

extern WINAPI int wine32b__cscanf_s(const char * format)
{
	TRACE("Enter _cscanf_s\n");
	return p_cscanf_s(format);
}

extern WINAPI void wine32a__cscanf_s(void);
__ASM_GLOBAL_FUNC(wine32a__cscanf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cscanf_s") "\n"
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

extern WINAPI int wine32b__cscanf_s_l(const char * format, MSVCRT__locale_t locale)
{
	TRACE("Enter _cscanf_s_l\n");
	return p_cscanf_s_l(format, locale);
}

extern WINAPI void wine32a__cscanf_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__cscanf_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cscanf_s_l") "\n"
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

extern WINAPI int wine32b__cwscanf(const MSVCRT_wchar_t * format)
{
	TRACE("Enter _cwscanf\n");
	return p_cwscanf(format);
}

extern WINAPI void wine32a__cwscanf(void);
__ASM_GLOBAL_FUNC(wine32a__cwscanf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwscanf") "\n"
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

extern WINAPI int wine32b__cwscanf_l(const MSVCRT_wchar_t * format, MSVCRT__locale_t locale)
{
	TRACE("Enter _cwscanf_l\n");
	return p_cwscanf_l(format, locale);
}

extern WINAPI void wine32a__cwscanf_l(void);
__ASM_GLOBAL_FUNC(wine32a__cwscanf_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwscanf_l") "\n"
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

extern WINAPI int wine32b__cwscanf_s(const MSVCRT_wchar_t * format)
{
	TRACE("Enter _cwscanf_s\n");
	return p_cwscanf_s(format);
}

extern WINAPI void wine32a__cwscanf_s(void);
__ASM_GLOBAL_FUNC(wine32a__cwscanf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwscanf_s") "\n"
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

extern WINAPI int wine32b__cwscanf_s_l(const MSVCRT_wchar_t * format, MSVCRT__locale_t locale)
{
	TRACE("Enter _cwscanf_s_l\n");
	return p_cwscanf_s_l(format, locale);
}

extern WINAPI void wine32a__cwscanf_s_l(void);
__ASM_GLOBAL_FUNC(wine32a__cwscanf_s_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__cwscanf_s_l") "\n"
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


static WINAPI char * (*p_strlwr_l)(char * str, MSVCRT__locale_t locale);
static WINAPI char * (*p_strset)(char * str, int value);
static WINAPI int (*p__STRINGTOLD)(MSVCRT__LDOUBLE * value, char ** endptr, const char * str, int flags);

extern WINAPI char * wine32b__strlwr_l(char * str, MSVCRT__locale_t locale)
{
	TRACE("Enter _strlwr_l\n");
	return p_strlwr_l(str, locale);
}

extern WINAPI void wine32a__strlwr_l(void);
__ASM_GLOBAL_FUNC(wine32a__strlwr_l,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strlwr_l") "\n"
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

extern WINAPI char * wine32b__strset(char * str, int value)
{
	TRACE("Enter _strset\n");
	return p_strset(str, value);
}

extern WINAPI void wine32a__strset(void);
__ASM_GLOBAL_FUNC(wine32a__strset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strset") "\n"
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

extern WINAPI int wine32b___STRINGTOLD(MSVCRT__LDOUBLE * value, char ** endptr, const char * str, int flags)
{
	TRACE("Enter __STRINGTOLD\n");
	return p__STRINGTOLD(value, endptr, str, flags);
}

extern WINAPI void wine32a___STRINGTOLD(void);
__ASM_GLOBAL_FUNC(wine32a___STRINGTOLD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___STRINGTOLD") "\n"
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

static WINAPI void (*p_endthread)(void);
static WINAPI void (*p_endthreadex)(unsigned int retval);
static WINAPI MSVCRT_uintptr_t (*p_beginthread)(MSVCRT__beginthread_start_routine_t start_address, unsigned int stack_size, void * arglist);
static WINAPI MSVCRT_uintptr_t (*p_beginthreadex)(void * security, unsigned int stack_size, MSVCRT__beginthreadex_start_routine_t start_address, void * arglist, unsigned int initflag, unsigned int * thrdaddr);

extern WINAPI void wine32b__endthread(void)
{
	TRACE("Enter _endthread\n");
	return p_endthread();
}

extern WINAPI void wine32a__endthread(void);
__ASM_GLOBAL_FUNC(wine32a__endthread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__endthread") "\n"
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

extern WINAPI void wine32b__endthreadex(unsigned int retval)
{
	TRACE("Enter _endthreadex\n");
	return p_endthreadex(retval);
}

extern WINAPI void wine32a__endthreadex(void);
__ASM_GLOBAL_FUNC(wine32a__endthreadex,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__endthreadex") "\n"
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

extern WINAPI MSVCRT_uintptr_t wine32b__beginthread(MSVCRT__beginthread_start_routine_t start_address, unsigned int stack_size, void * arglist)
{
	TRACE("Enter _beginthread\n");
	return p_beginthread(start_address, stack_size, arglist);
}

extern WINAPI void wine32a__beginthread(void);
__ASM_GLOBAL_FUNC(wine32a__beginthread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__beginthread") "\n"
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

extern WINAPI MSVCRT_uintptr_t wine32b__beginthreadex(void * security, unsigned int stack_size, MSVCRT__beginthreadex_start_routine_t start_address, void * arglist, unsigned int initflag, unsigned int * thrdaddr)
{
	TRACE("Enter _beginthreadex\n");
	return p_beginthreadex(security, stack_size, start_address, arglist, initflag, thrdaddr);
}

extern WINAPI void wine32a__beginthreadex(void);
__ASM_GLOBAL_FUNC(wine32a__beginthreadex,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__beginthreadex") "\n"
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

static WINAPI int (*p_localtime64_s)(struct MSVCRT_tm * res, const MSVCRT___time64_t * secs);
static WINAPI int (*p_localtime32_s)(struct MSVCRT_tm * time, const MSVCRT___time32_t * secs);
static WINAPI int (*p_strdate_s)(char * date, MSVCRT_size_t size);
static WINAPI int (*p_wstrdate_s)(MSVCRT_wchar_t * date, MSVCRT_size_t size);
static WINAPI int (*p_strtime_s)(char * time, MSVCRT_size_t size);
static WINAPI int (*p_wstrtime_s)(MSVCRT_wchar_t * time, MSVCRT_size_t size);
static WINAPI char ** (*p__p__tzname)(void);
static WINAPI MSVCRT_size_t (*p_Strftime)(char * str, MSVCRT_size_t max, const char * format, const struct MSVCRT_tm * mstm, MSVCRT___lc_time_data * time_data);

extern WINAPI int wine32b__localtime64_s(struct MSVCRT_tm * res, const MSVCRT___time64_t * secs)
{
	TRACE("Enter _localtime64_s\n");
	return p_localtime64_s(res, secs);
}

extern WINAPI void wine32a__localtime64_s(void);
__ASM_GLOBAL_FUNC(wine32a__localtime64_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__localtime64_s") "\n"
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

extern WINAPI int wine32b__localtime32_s(struct MSVCRT_tm * time, const MSVCRT___time32_t * secs)
{
	TRACE("Enter _localtime32_s\n");
	return p_localtime32_s(time, secs);
}

extern WINAPI void wine32a__localtime32_s(void);
__ASM_GLOBAL_FUNC(wine32a__localtime32_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__localtime32_s") "\n"
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

extern WINAPI int wine32b__strdate_s(char * date, MSVCRT_size_t size)
{
	TRACE("Enter _strdate_s\n");
	return p_strdate_s(date, size);
}

extern WINAPI void wine32a__strdate_s(void);
__ASM_GLOBAL_FUNC(wine32a__strdate_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strdate_s") "\n"
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

extern WINAPI int wine32b__wstrdate_s(MSVCRT_wchar_t * date, MSVCRT_size_t size)
{
	TRACE("Enter _wstrdate_s\n");
	return p_wstrdate_s(date, size);
}

extern WINAPI void wine32a__wstrdate_s(void);
__ASM_GLOBAL_FUNC(wine32a__wstrdate_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wstrdate_s") "\n"
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

extern WINAPI int wine32b__strtime_s(char * time, MSVCRT_size_t size)
{
	TRACE("Enter _strtime_s\n");
	return p_strtime_s(time, size);
}

extern WINAPI void wine32a__strtime_s(void);
__ASM_GLOBAL_FUNC(wine32a__strtime_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strtime_s") "\n"
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

extern WINAPI int wine32b__wstrtime_s(MSVCRT_wchar_t * time, MSVCRT_size_t size)
{
	TRACE("Enter _wstrtime_s\n");
	return p_wstrtime_s(time, size);
}

extern WINAPI void wine32a__wstrtime_s(void);
__ASM_GLOBAL_FUNC(wine32a__wstrtime_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wstrtime_s") "\n"
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

extern WINAPI char ** wine32b___p__tzname(void)
{
	TRACE("Enter __p__tzname\n");
	return p__p__tzname();
}

extern WINAPI void wine32a___p__tzname(void);
__ASM_GLOBAL_FUNC(wine32a___p__tzname,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___p__tzname") "\n"
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

extern WINAPI MSVCRT_size_t wine32b__Strftime(char * str, MSVCRT_size_t max, const char * format, const struct MSVCRT_tm * mstm, MSVCRT___lc_time_data * time_data)
{
	TRACE("Enter _Strftime\n");
	return p_Strftime(str, max, format, mstm, time_data);
}

extern WINAPI void wine32a__Strftime(void);
__ASM_GLOBAL_FUNC(wine32a__Strftime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__Strftime") "\n"
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

static WINAPI char * (*p__unDNameEx)(char * buffer, const char * mangled, int buflen, malloc_func_t memget, free_func_t memfree, void * unknown, unsigned short flags);
static WINAPI char * (*p__unDName)(char * buffer, const char * mangled, int buflen, malloc_func_t memget, free_func_t memfree, unsigned short flags);

extern WINAPI char * wine32b___unDNameEx(char * buffer, const char * mangled, int buflen, malloc_func_t memget, free_func_t memfree, void * unknown, unsigned short flags)
{
	TRACE("Enter __unDNameEx\n");
	return p__unDNameEx(buffer, mangled, buflen, memget, memfree, unknown, flags);
}

extern WINAPI void wine32a___unDNameEx(void);
__ASM_GLOBAL_FUNC(wine32a___unDNameEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___unDNameEx") "\n"
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

extern WINAPI char * wine32b___unDName(char * buffer, const char * mangled, int buflen, malloc_func_t memget, free_func_t memfree, unsigned short flags)
{
	TRACE("Enter __unDName\n");
	return p__unDName(buffer, mangled, buflen, memget, memfree, flags);
}

extern WINAPI void wine32a___unDName(void);
__ASM_GLOBAL_FUNC(wine32a___unDName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___unDName") "\n"
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


static BOOL initialized = FALSE;

void wine_thunk_initialize_msvcrt(void)
{
	HMODULE library = LoadLibraryA("msvcrt.dll");
	p_cputs = (void *)GetProcAddress(library, "_cputs");
	p_cputws = (void *)GetProcAddress(library, "_cputws");
	p_getch = (void *)GetProcAddress(library, "_getch");
	p_getwch = (void *)GetProcAddress(library, "_getwch");
	p_putch = (void *)GetProcAddress(library, "_putch");
	p_putwch = (void *)GetProcAddress(library, "_putwch");
	p_getche = (void *)GetProcAddress(library, "_getche");
	p_getwche = (void *)GetProcAddress(library, "_getwche");
	p_cgets = (void *)GetProcAddress(library, "_cgets");
	p_ungetch = (void *)GetProcAddress(library, "_ungetch");
	p_ungetwch = (void *)GetProcAddress(library, "_ungetwch");
	p_kbhit = (void *)GetProcAddress(library, "_kbhit");
	p_vcprintf = (void *)GetProcAddress(library, "_vcprintf");
	p_cprintf = (void *)GetProcAddress(library, "_cprintf");
	p_vcwprintf = (void *)GetProcAddress(library, "_vcwprintf");
	p_cwprintf = (void *)GetProcAddress(library, "_cwprintf");
	p_CxxThrowException = (void *)GetProcAddress(library, "_CxxThrowException");
	p__p__commode = (void *)GetProcAddress(library, "__p__commode");
	p_get_pgmptr = (void *)GetProcAddress(library, "_get_pgmptr");
	p_get_wpgmptr = (void *)GetProcAddress(library, "_get_wpgmptr");
	p__p__osver = (void *)GetProcAddress(library, "__p__osver");
	p__p__winmajor = (void *)GetProcAddress(library, "__p__winmajor");
	p__p__winminor = (void *)GetProcAddress(library, "__p__winminor");
	p__p__winver = (void *)GetProcAddress(library, "__p__winver");
	p__p___initenv = (void *)GetProcAddress(library, "__p___initenv");
	p__p___winitenv = (void *)GetProcAddress(library, "__p___winitenv");
	p__getmainargs = (void *)GetProcAddress(library, "__getmainargs");
	p__wgetmainargs = (void *)GetProcAddress(library, "__wgetmainargs");
	p_initterm = (void *)GetProcAddress(library, "_initterm");
	p_initterm_e = (void *)GetProcAddress(library, "_initterm_e");
	p_putenv = (void *)GetProcAddress(library, "_putenv");
	p_wputenv = (void *)GetProcAddress(library, "_wputenv");
	p_putenv_s = (void *)GetProcAddress(library, "_putenv_s");
	p_wputenv_s = (void *)GetProcAddress(library, "_wputenv_s");
	pgetenv_s = (void *)GetProcAddress(library, "getenv_s");
	p_wgetenv_s = (void *)GetProcAddress(library, "_wgetenv_s");
	p_get_errno = (void *)GetProcAddress(library, "_get_errno");
	p_get_doserrno = (void *)GetProcAddress(library, "_get_doserrno");
	p_set_errno = (void *)GetProcAddress(library, "_set_errno");
	p_set_doserrno = (void *)GetProcAddress(library, "_set_doserrno");
	p_seterrormode = (void *)GetProcAddress(library, "_seterrormode");
	p_XcptFilter = (void *)GetProcAddress(library, "_XcptFilter");
	p_abnormal_termination = (void *)GetProcAddress(library, "_abnormal_termination");
	p__DestructExceptionObject = (void *)GetProcAddress(library, "__DestructExceptionObject");
	p__CxxRegisterExceptionObject = (void *)GetProcAddress(library, "__CxxRegisterExceptionObject");
	p__CxxUnregisterExceptionObject = (void *)GetProcAddress(library, "__CxxUnregisterExceptionObject");
	p__CxxExceptionFilter = (void *)GetProcAddress(library, "__CxxExceptionFilter");
	p__CppXcptFilter = (void *)GetProcAddress(library, "__CppXcptFilter");
	p__CxxDetectRethrow = (void *)GetProcAddress(library, "__CxxDetectRethrow");
	p__CxxQueryExceptionSize = (void *)GetProcAddress(library, "__CxxQueryExceptionSize");
	p_local_unwind = (void *)GetProcAddress(library, "_local_unwind");
	p_fpieee_flt = (void *)GetProcAddress(library, "_fpieee_flt");
	p__dllonexit = (void *)GetProcAddress(library, "__dllonexit");
	p_amsg_exit = (void *)GetProcAddress(library, "_amsg_exit");
	p_purecall = (void *)GetProcAddress(library, "_purecall");
	p_set_error_mode = (void *)GetProcAddress(library, "_set_error_mode");
	p__iob_func = (void *)GetProcAddress(library, "__iob_func");
	p_futime64 = (void *)GetProcAddress(library, "_futime64");
	p_futime32 = (void *)GetProcAddress(library, "_futime32");
	p_futime = (void *)GetProcAddress(library, "_futime");
	p_telli64 = (void *)GetProcAddress(library, "_telli64");
	p_utime64 = (void *)GetProcAddress(library, "_utime64");
	p_utime32 = (void *)GetProcAddress(library, "_utime32");
	p_utime = (void *)GetProcAddress(library, "_utime");
	p_wutime64 = (void *)GetProcAddress(library, "_wutime64");
	p_wutime32 = (void *)GetProcAddress(library, "_wutime32");
	p_wutime = (void *)GetProcAddress(library, "_wutime");
	p_callnewh = (void *)GetProcAddress(library, "_callnewh");
	p_expand = (void *)GetProcAddress(library, "_expand");
	p_heapchk = (void *)GetProcAddress(library, "_heapchk");
	p_heapmin = (void *)GetProcAddress(library, "_heapmin");
	p_heapwalk = (void *)GetProcAddress(library, "_heapwalk");
	p_heapset = (void *)GetProcAddress(library, "_heapset");
	p_heapadd = (void *)GetProcAddress(library, "_heapadd");
	p_get_heap_handle = (void *)GetProcAddress(library, "_get_heap_handle");
	p_msize = (void *)GetProcAddress(library, "_msize");
	p__p__amblksiz = (void *)GetProcAddress(library, "__p__amblksiz");
	p_get_sbh_threshold = (void *)GetProcAddress(library, "_get_sbh_threshold");
	p_set_sbh_threshold = (void *)GetProcAddress(library, "_set_sbh_threshold");
	p_aligned_free = (void *)GetProcAddress(library, "_aligned_free");
	p_aligned_offset_malloc = (void *)GetProcAddress(library, "_aligned_offset_malloc");
	p_aligned_malloc = (void *)GetProcAddress(library, "_aligned_malloc");
	p_aligned_offset_realloc = (void *)GetProcAddress(library, "_aligned_offset_realloc");
	p_aligned_realloc = (void *)GetProcAddress(library, "_aligned_realloc");
	p_Getdays = (void *)GetProcAddress(library, "_Getdays");
	p_Getmonths = (void *)GetProcAddress(library, "_Getmonths");
	p_Gettnames = (void *)GetProcAddress(library, "_Gettnames");
	p__crtLCMapStringA = (void *)GetProcAddress(library, "__crtLCMapStringA");
	p__crtLCMapStringW = (void *)GetProcAddress(library, "__crtLCMapStringW");
	p__crtCompareStringA = (void *)GetProcAddress(library, "__crtCompareStringA");
	p__crtCompareStringW = (void *)GetProcAddress(library, "__crtCompareStringW");
	p__crtGetLocaleInfoW = (void *)GetProcAddress(library, "__crtGetLocaleInfoW");
	p__crtGetStringTypeW = (void *)GetProcAddress(library, "__crtGetStringTypeW");
	p__lconv_init = (void *)GetProcAddress(library, "__lconv_init");
	p___lc_handle_func = (void *)GetProcAddress(library, "___lc_handle_func");
	p___lc_codepage_func = (void *)GetProcAddress(library, "___lc_codepage_func");
	p___lc_collate_cp_func = (void *)GetProcAddress(library, "___lc_collate_cp_func");
	p_lock = (void *)GetProcAddress(library, "_lock");
	p_unlock = (void *)GetProcAddress(library, "_unlock");
	p_rotl = (void *)GetProcAddress(library, "_rotl");
	p_rotr = (void *)GetProcAddress(library, "_rotr");
	p_rotl64 = (void *)GetProcAddress(library, "_rotl64");
	p_rotr64 = (void *)GetProcAddress(library, "_rotr64");
	p_abs64 = (void *)GetProcAddress(library, "_abs64");
	p_hypot = (void *)GetProcAddress(library, "_hypot");
	p_statusfp = (void *)GetProcAddress(library, "_statusfp");
	p_clearfp = (void *)GetProcAddress(library, "_clearfp");
	p__fpecode = (void *)GetProcAddress(library, "__fpecode");
	p_control87 = (void *)GetProcAddress(library, "_control87");
	p_controlfp = (void *)GetProcAddress(library, "_controlfp");
	p_set_controlfp = (void *)GetProcAddress(library, "_set_controlfp");
	p_controlfp_s = (void *)GetProcAddress(library, "_controlfp_s");
	p_fpreset = (void *)GetProcAddress(library, "_fpreset");
	p__p__mbctype = (void *)GetProcAddress(library, "__p__mbctype");
	p__p___mb_cur_max = (void *)GetProcAddress(library, "__p___mb_cur_max");
	p_setmbcp = (void *)GetProcAddress(library, "_setmbcp");
	p_getmbcp = (void *)GetProcAddress(library, "_getmbcp");
	p_mbsnextc = (void *)GetProcAddress(library, "_mbsnextc");
	p_mbctolower = (void *)GetProcAddress(library, "_mbctolower");
	p_mbctoupper = (void *)GetProcAddress(library, "_mbctoupper");
	p_mbctombb = (void *)GetProcAddress(library, "_mbctombb");
	p_mbcjistojms = (void *)GetProcAddress(library, "_mbcjistojms");
	p_mbcjmstojis = (void *)GetProcAddress(library, "_mbcjmstojis");
	p_mbsdec = (void *)GetProcAddress(library, "_mbsdec");
	p_mbclen = (void *)GetProcAddress(library, "_mbclen");
	p_mbsinc = (void *)GetProcAddress(library, "_mbsinc");
	p_mbsninc = (void *)GetProcAddress(library, "_mbsninc");
	p_mbsnlen_l = (void *)GetProcAddress(library, "_mbsnlen_l");
	p_mbslen = (void *)GetProcAddress(library, "_mbslen");
	p_mbslen_l = (void *)GetProcAddress(library, "_mbslen_l");
	p_mbsnlen = (void *)GetProcAddress(library, "_mbsnlen");
	p_mbccpy_s_l = (void *)GetProcAddress(library, "_mbccpy_s_l");
	p_mbccpy = (void *)GetProcAddress(library, "_mbccpy");
	p_mbccpy_l = (void *)GetProcAddress(library, "_mbccpy_l");
	p_mbccpy_s = (void *)GetProcAddress(library, "_mbccpy_s");
	p_mbsncpy = (void *)GetProcAddress(library, "_mbsncpy");
	p_mbsnbcpy_s_l = (void *)GetProcAddress(library, "_mbsnbcpy_s_l");
	p_mbsnbcpy_s = (void *)GetProcAddress(library, "_mbsnbcpy_s");
	p_mbscpy_s_l = (void *)GetProcAddress(library, "_mbscpy_s_l");
	p_mbscpy_s = (void *)GetProcAddress(library, "_mbscpy_s");
	p_mbsnbcpy = (void *)GetProcAddress(library, "_mbsnbcpy");
	p_mbscmp = (void *)GetProcAddress(library, "_mbscmp");
	p_mbsnbicoll_l = (void *)GetProcAddress(library, "_mbsnbicoll_l");
	p_mbsicoll_l = (void *)GetProcAddress(library, "_mbsicoll_l");
	p_mbsnbicoll = (void *)GetProcAddress(library, "_mbsnbicoll");
	p_mbsicoll = (void *)GetProcAddress(library, "_mbsicoll");
	p_mbsnbcoll_l = (void *)GetProcAddress(library, "_mbsnbcoll_l");
	p_mbscoll_l = (void *)GetProcAddress(library, "_mbscoll_l");
	p_mbsnbcoll = (void *)GetProcAddress(library, "_mbsnbcoll");
	p_mbscoll = (void *)GetProcAddress(library, "_mbscoll");
	p_mbsicmp = (void *)GetProcAddress(library, "_mbsicmp");
	p_mbsncmp = (void *)GetProcAddress(library, "_mbsncmp");
	p_mbsnbcmp = (void *)GetProcAddress(library, "_mbsnbcmp");
	p_mbsnicmp = (void *)GetProcAddress(library, "_mbsnicmp");
	p_mbsnbicmp = (void *)GetProcAddress(library, "_mbsnbicmp");
	p_mbscat = (void *)GetProcAddress(library, "_mbscat");
	p_mbscat_s_l = (void *)GetProcAddress(library, "_mbscat_s_l");
	p_mbscat_s = (void *)GetProcAddress(library, "_mbscat_s");
	p_mbscpy = (void *)GetProcAddress(library, "_mbscpy");
	p_mbsstr = (void *)GetProcAddress(library, "_mbsstr");
	p_mbschr = (void *)GetProcAddress(library, "_mbschr");
	p_mbsrchr = (void *)GetProcAddress(library, "_mbsrchr");
	p_mbstok_s_l = (void *)GetProcAddress(library, "_mbstok_s_l");
	p_mbstok_s = (void *)GetProcAddress(library, "_mbstok_s");
	p_mbstok_l = (void *)GetProcAddress(library, "_mbstok_l");
	p_mbstok = (void *)GetProcAddress(library, "_mbstok");
	p_mbbtombc = (void *)GetProcAddress(library, "_mbbtombc");
	p_mbbtype = (void *)GetProcAddress(library, "_mbbtype");
	p_ismbbkana = (void *)GetProcAddress(library, "_ismbbkana");
	p_ismbcdigit = (void *)GetProcAddress(library, "_ismbcdigit");
	p_ismbcgraph = (void *)GetProcAddress(library, "_ismbcgraph");
	p_ismbcalpha = (void *)GetProcAddress(library, "_ismbcalpha");
	p_ismbclower = (void *)GetProcAddress(library, "_ismbclower");
	p_ismbcupper = (void *)GetProcAddress(library, "_ismbcupper");
	p_ismbcsymbol = (void *)GetProcAddress(library, "_ismbcsymbol");
	p_ismbcalnum = (void *)GetProcAddress(library, "_ismbcalnum");
	p_ismbcspace = (void *)GetProcAddress(library, "_ismbcspace");
	p_ismbcprint = (void *)GetProcAddress(library, "_ismbcprint");
	p_ismbcpunct = (void *)GetProcAddress(library, "_ismbcpunct");
	p_ismbchira = (void *)GetProcAddress(library, "_ismbchira");
	p_ismbckata = (void *)GetProcAddress(library, "_ismbckata");
	p_ismbblead_l = (void *)GetProcAddress(library, "_ismbblead_l");
	p_ismbblead = (void *)GetProcAddress(library, "_ismbblead");
	p_ismbbtrail_l = (void *)GetProcAddress(library, "_ismbbtrail_l");
	p_ismbbtrail = (void *)GetProcAddress(library, "_ismbbtrail");
	p_ismbclegal_l = (void *)GetProcAddress(library, "_ismbclegal_l");
	p_ismbclegal = (void *)GetProcAddress(library, "_ismbclegal");
	p_ismbslead = (void *)GetProcAddress(library, "_ismbslead");
	p_ismbstrail = (void *)GetProcAddress(library, "_ismbstrail");
	p_mbsbtype = (void *)GetProcAddress(library, "_mbsbtype");
	p_mbsset = (void *)GetProcAddress(library, "_mbsset");
	p_mbsnbset = (void *)GetProcAddress(library, "_mbsnbset");
	p_mbsnset = (void *)GetProcAddress(library, "_mbsnset");
	p_mbsnccnt = (void *)GetProcAddress(library, "_mbsnccnt");
	p_mbsnbcnt = (void *)GetProcAddress(library, "_mbsnbcnt");
	p_mbsnbcat = (void *)GetProcAddress(library, "_mbsnbcat");
	p_mbsnbcat_s = (void *)GetProcAddress(library, "_mbsnbcat_s");
	p_mbsncat = (void *)GetProcAddress(library, "_mbsncat");
	p_mbslwr = (void *)GetProcAddress(library, "_mbslwr");
	p_mbslwr_s = (void *)GetProcAddress(library, "_mbslwr_s");
	p_mbsupr = (void *)GetProcAddress(library, "_mbsupr");
	p_mbsupr_s = (void *)GetProcAddress(library, "_mbsupr_s");
	p_mbsspn = (void *)GetProcAddress(library, "_mbsspn");
	p_mbsspnp = (void *)GetProcAddress(library, "_mbsspnp");
	p_mbscspn = (void *)GetProcAddress(library, "_mbscspn");
	p_mbsrev = (void *)GetProcAddress(library, "_mbsrev");
	p_mbspbrk = (void *)GetProcAddress(library, "_mbspbrk");
	p_mbstrlen_l = (void *)GetProcAddress(library, "_mbstrlen_l");
	p_mbstrlen = (void *)GetProcAddress(library, "_mbstrlen");
	p_mbctohira = (void *)GetProcAddress(library, "_mbctohira");
	p_mbctokata = (void *)GetProcAddress(library, "_mbctokata");
	p_ismbcl0_l = (void *)GetProcAddress(library, "_ismbcl0_l");
	p_ismbcl0 = (void *)GetProcAddress(library, "_ismbcl0");
	p_ismbcl1_l = (void *)GetProcAddress(library, "_ismbcl1_l");
	p_ismbcl1 = (void *)GetProcAddress(library, "_ismbcl1");
	p_ismbcl2_l = (void *)GetProcAddress(library, "_ismbcl2_l");
	p_ismbcl2 = (void *)GetProcAddress(library, "_ismbcl2");
	p_lfind = (void *)GetProcAddress(library, "_lfind");
	p_lfind_s = (void *)GetProcAddress(library, "_lfind_s");
	p_lsearch = (void *)GetProcAddress(library, "_lsearch");
	p_cwait = (void *)GetProcAddress(library, "_cwait");
	p_wexecl = (void *)GetProcAddress(library, "_wexecl");
	p_execl = (void *)GetProcAddress(library, "_execl");
	p_wexecle = (void *)GetProcAddress(library, "_wexecle");
	p_execle = (void *)GetProcAddress(library, "_execle");
	p_wexeclp = (void *)GetProcAddress(library, "_wexeclp");
	p_execlp = (void *)GetProcAddress(library, "_execlp");
	p_wexeclpe = (void *)GetProcAddress(library, "_wexeclpe");
	p_execlpe = (void *)GetProcAddress(library, "_execlpe");
	p_wexecv = (void *)GetProcAddress(library, "_wexecv");
	p_execv = (void *)GetProcAddress(library, "_execv");
	p_wexecve = (void *)GetProcAddress(library, "_wexecve");
	p_wexecvpe = (void *)GetProcAddress(library, "_wexecvpe");
	p_execvpe = (void *)GetProcAddress(library, "_execvpe");
	p_wexecvp = (void *)GetProcAddress(library, "_wexecvp");
	p_execvp = (void *)GetProcAddress(library, "_execvp");
	p_wsystem = (void *)GetProcAddress(library, "_wsystem");
	p_loaddll = (void *)GetProcAddress(library, "_loaddll");
	p_unloaddll = (void *)GetProcAddress(library, "_unloaddll");
	p_getdllprocaddr = (void *)GetProcAddress(library, "_getdllprocaddr");
	p_getpid = (void *)GetProcAddress(library, "_getpid");
	p_cscanf = (void *)GetProcAddress(library, "_cscanf");
	p_cscanf_l = (void *)GetProcAddress(library, "_cscanf_l");
	p_cscanf_s = (void *)GetProcAddress(library, "_cscanf_s");
	p_cscanf_s_l = (void *)GetProcAddress(library, "_cscanf_s_l");
	p_cwscanf = (void *)GetProcAddress(library, "_cwscanf");
	p_cwscanf_l = (void *)GetProcAddress(library, "_cwscanf_l");
	p_cwscanf_s = (void *)GetProcAddress(library, "_cwscanf_s");
	p_cwscanf_s_l = (void *)GetProcAddress(library, "_cwscanf_s_l");
	p_strlwr_l = (void *)GetProcAddress(library, "_strlwr_l");
	p_strset = (void *)GetProcAddress(library, "_strset");
	p__STRINGTOLD = (void *)GetProcAddress(library, "__STRINGTOLD");
	p_endthread = (void *)GetProcAddress(library, "_endthread");
	p_endthreadex = (void *)GetProcAddress(library, "_endthreadex");
	p_beginthread = (void *)GetProcAddress(library, "_beginthread");
	p_beginthreadex = (void *)GetProcAddress(library, "_beginthreadex");
	p_localtime64_s = (void *)GetProcAddress(library, "_localtime64_s");
	p_localtime32_s = (void *)GetProcAddress(library, "_localtime32_s");
	p_strdate_s = (void *)GetProcAddress(library, "_strdate_s");
	p_wstrdate_s = (void *)GetProcAddress(library, "_wstrdate_s");
	p_strtime_s = (void *)GetProcAddress(library, "_strtime_s");
	p_wstrtime_s = (void *)GetProcAddress(library, "_wstrtime_s");
	p__p__tzname = (void *)GetProcAddress(library, "__p__tzname");
	p_Strftime = (void *)GetProcAddress(library, "_Strftime");
	p__unDNameEx = (void *)GetProcAddress(library, "__unDNameEx");
	p__unDName = (void *)GetProcAddress(library, "__unDName");
	initialized = TRUE;
}

void* wine_thunk_get_for_msvcrt(void *func)
{
	if (!initialized)
		return NULL;

	if (func == p_cputs)
		return wine32a__cputs;
	if (func == p_cputws)
		return wine32a__cputws;
	if (func == p_getch)
		return wine32a__getch;
	if (func == p_getwch)
		return wine32a__getwch;
	if (func == p_putch)
		return wine32a__putch;
	if (func == p_putwch)
		return wine32a__putwch;
	if (func == p_getche)
		return wine32a__getche;
	if (func == p_getwche)
		return wine32a__getwche;
	if (func == p_cgets)
		return wine32a__cgets;
	if (func == p_ungetch)
		return wine32a__ungetch;
	if (func == p_ungetwch)
		return wine32a__ungetwch;
	if (func == p_kbhit)
		return wine32a__kbhit;
	if (func == p_vcprintf)
		return wine32a__vcprintf;
	if (func == p_cprintf)
		return wine32a__cprintf;
	if (func == p_vcwprintf)
		return wine32a__vcwprintf;
	if (func == p_cwprintf)
		return wine32a__cwprintf;
	if (func == p_CxxThrowException)
		return wine32a__CxxThrowException;
	if (func == p__p__commode)
		return wine32a___p__commode;
	if (func == p_get_pgmptr)
		return wine32a__get_pgmptr;
	if (func == p_get_wpgmptr)
		return wine32a__get_wpgmptr;
	if (func == p__p__osver)
		return wine32a___p__osver;
	if (func == p__p__winmajor)
		return wine32a___p__winmajor;
	if (func == p__p__winminor)
		return wine32a___p__winminor;
	if (func == p__p__winver)
		return wine32a___p__winver;
	if (func == p__p___initenv)
		return wine32a___p___initenv;
	if (func == p__p___winitenv)
		return wine32a___p___winitenv;
	if (func == p__getmainargs)
		return wine32a___getmainargs;
	if (func == p__wgetmainargs)
		return wine32a___wgetmainargs;
	if (func == p_initterm)
		return wine32a__initterm;
	if (func == p_initterm_e)
		return wine32a__initterm_e;
	if (func == p_putenv)
		return wine32a__putenv;
	if (func == p_wputenv)
		return wine32a__wputenv;
	if (func == p_putenv_s)
		return wine32a__putenv_s;
	if (func == p_wputenv_s)
		return wine32a__wputenv_s;
	if (func == pgetenv_s)
		return wine32a_getenv_s;
	if (func == p_wgetenv_s)
		return wine32a__wgetenv_s;
	if (func == p_get_errno)
		return wine32a__get_errno;
	if (func == p_get_doserrno)
		return wine32a__get_doserrno;
	if (func == p_set_errno)
		return wine32a__set_errno;
	if (func == p_set_doserrno)
		return wine32a__set_doserrno;
	if (func == p_seterrormode)
		return wine32a__seterrormode;
	if (func == p_XcptFilter)
		return wine32a__XcptFilter;
	if (func == p_abnormal_termination)
		return wine32a__abnormal_termination;
	if (func == p__DestructExceptionObject)
		return wine32a___DestructExceptionObject;
	if (func == p__CxxRegisterExceptionObject)
		return wine32a___CxxRegisterExceptionObject;
	if (func == p__CxxUnregisterExceptionObject)
		return wine32a___CxxUnregisterExceptionObject;
	if (func == p__CxxExceptionFilter)
		return wine32a___CxxExceptionFilter;
	if (func == p__CppXcptFilter)
		return wine32a___CppXcptFilter;
	if (func == p__CxxDetectRethrow)
		return wine32a___CxxDetectRethrow;
	if (func == p__CxxQueryExceptionSize)
		return wine32a___CxxQueryExceptionSize;
	if (func == p_local_unwind)
		return wine32a__local_unwind;
	if (func == p_fpieee_flt)
		return wine32a__fpieee_flt;
	if (func == p__dllonexit)
		return wine32a___dllonexit;
	if (func == p_amsg_exit)
		return wine32a__amsg_exit;
	if (func == p_purecall)
		return wine32a__purecall;
	if (func == p_set_error_mode)
		return wine32a__set_error_mode;
	if (func == p__iob_func)
		return wine32a___iob_func;
	if (func == p_futime64)
		return wine32a__futime64;
	if (func == p_futime32)
		return wine32a__futime32;
	if (func == p_futime)
		return wine32a__futime;
	if (func == p_telli64)
		return wine32a__telli64;
	if (func == p_utime64)
		return wine32a__utime64;
	if (func == p_utime32)
		return wine32a__utime32;
	if (func == p_utime)
		return wine32a__utime;
	if (func == p_wutime64)
		return wine32a__wutime64;
	if (func == p_wutime32)
		return wine32a__wutime32;
	if (func == p_wutime)
		return wine32a__wutime;
	if (func == p_callnewh)
		return wine32a__callnewh;
	if (func == p_expand)
		return wine32a__expand;
	if (func == p_heapchk)
		return wine32a__heapchk;
	if (func == p_heapmin)
		return wine32a__heapmin;
	if (func == p_heapwalk)
		return wine32a__heapwalk;
	if (func == p_heapset)
		return wine32a__heapset;
	if (func == p_heapadd)
		return wine32a__heapadd;
	if (func == p_get_heap_handle)
		return wine32a__get_heap_handle;
	if (func == p_msize)
		return wine32a__msize;
	if (func == p__p__amblksiz)
		return wine32a___p__amblksiz;
	if (func == p_get_sbh_threshold)
		return wine32a__get_sbh_threshold;
	if (func == p_set_sbh_threshold)
		return wine32a__set_sbh_threshold;
	if (func == p_aligned_free)
		return wine32a__aligned_free;
	if (func == p_aligned_offset_malloc)
		return wine32a__aligned_offset_malloc;
	if (func == p_aligned_malloc)
		return wine32a__aligned_malloc;
	if (func == p_aligned_offset_realloc)
		return wine32a__aligned_offset_realloc;
	if (func == p_aligned_realloc)
		return wine32a__aligned_realloc;
	if (func == p_Getdays)
		return wine32a__Getdays;
	if (func == p_Getmonths)
		return wine32a__Getmonths;
	if (func == p_Gettnames)
		return wine32a__Gettnames;
	if (func == p__crtLCMapStringA)
		return wine32a___crtLCMapStringA;
	if (func == p__crtLCMapStringW)
		return wine32a___crtLCMapStringW;
	if (func == p__crtCompareStringA)
		return wine32a___crtCompareStringA;
	if (func == p__crtCompareStringW)
		return wine32a___crtCompareStringW;
	if (func == p__crtGetLocaleInfoW)
		return wine32a___crtGetLocaleInfoW;
	if (func == p__crtGetStringTypeW)
		return wine32a___crtGetStringTypeW;
	if (func == p__lconv_init)
		return wine32a___lconv_init;
	if (func == p___lc_handle_func)
		return wine32a____lc_handle_func;
	if (func == p___lc_codepage_func)
		return wine32a____lc_codepage_func;
	if (func == p___lc_collate_cp_func)
		return wine32a____lc_collate_cp_func;
	if (func == p_lock)
		return wine32a__lock;
	if (func == p_unlock)
		return wine32a__unlock;
	if (func == p_rotl)
		return wine32a__rotl;
	if (func == p_rotr)
		return wine32a__rotr;
	if (func == p_rotl64)
		return wine32a__rotl64;
	if (func == p_rotr64)
		return wine32a__rotr64;
	if (func == p_abs64)
		return wine32a__abs64;
	if (func == p_hypot)
		return wine32a__hypot;
	if (func == p_statusfp)
		return wine32a__statusfp;
	if (func == p_clearfp)
		return wine32a__clearfp;
	if (func == p__fpecode)
		return wine32a___fpecode;
	if (func == p_control87)
		return wine32a__control87;
	if (func == p_controlfp)
		return wine32a__controlfp;
	if (func == p_set_controlfp)
		return wine32a__set_controlfp;
	if (func == p_controlfp_s)
		return wine32a__controlfp_s;
	if (func == p_fpreset)
		return wine32a__fpreset;
	if (func == p__p__mbctype)
		return wine32a___p__mbctype;
	if (func == p__p___mb_cur_max)
		return wine32a___p___mb_cur_max;
	if (func == p_setmbcp)
		return wine32a__setmbcp;
	if (func == p_getmbcp)
		return wine32a__getmbcp;
	if (func == p_mbsnextc)
		return wine32a__mbsnextc;
	if (func == p_mbctolower)
		return wine32a__mbctolower;
	if (func == p_mbctoupper)
		return wine32a__mbctoupper;
	if (func == p_mbctombb)
		return wine32a__mbctombb;
	if (func == p_mbcjistojms)
		return wine32a__mbcjistojms;
	if (func == p_mbcjmstojis)
		return wine32a__mbcjmstojis;
	if (func == p_mbsdec)
		return wine32a__mbsdec;
	if (func == p_mbclen)
		return wine32a__mbclen;
	if (func == p_mbsinc)
		return wine32a__mbsinc;
	if (func == p_mbsninc)
		return wine32a__mbsninc;
	if (func == p_mbsnlen_l)
		return wine32a__mbsnlen_l;
	if (func == p_mbslen)
		return wine32a__mbslen;
	if (func == p_mbslen_l)
		return wine32a__mbslen_l;
	if (func == p_mbsnlen)
		return wine32a__mbsnlen;
	if (func == p_mbccpy_s_l)
		return wine32a__mbccpy_s_l;
	if (func == p_mbccpy)
		return wine32a__mbccpy;
	if (func == p_mbccpy_l)
		return wine32a__mbccpy_l;
	if (func == p_mbccpy_s)
		return wine32a__mbccpy_s;
	if (func == p_mbsncpy)
		return wine32a__mbsncpy;
	if (func == p_mbsnbcpy_s_l)
		return wine32a__mbsnbcpy_s_l;
	if (func == p_mbsnbcpy_s)
		return wine32a__mbsnbcpy_s;
	if (func == p_mbscpy_s_l)
		return wine32a__mbscpy_s_l;
	if (func == p_mbscpy_s)
		return wine32a__mbscpy_s;
	if (func == p_mbsnbcpy)
		return wine32a__mbsnbcpy;
	if (func == p_mbscmp)
		return wine32a__mbscmp;
	if (func == p_mbsnbicoll_l)
		return wine32a__mbsnbicoll_l;
	if (func == p_mbsicoll_l)
		return wine32a__mbsicoll_l;
	if (func == p_mbsnbicoll)
		return wine32a__mbsnbicoll;
	if (func == p_mbsicoll)
		return wine32a__mbsicoll;
	if (func == p_mbsnbcoll_l)
		return wine32a__mbsnbcoll_l;
	if (func == p_mbscoll_l)
		return wine32a__mbscoll_l;
	if (func == p_mbsnbcoll)
		return wine32a__mbsnbcoll;
	if (func == p_mbscoll)
		return wine32a__mbscoll;
	if (func == p_mbsicmp)
		return wine32a__mbsicmp;
	if (func == p_mbsncmp)
		return wine32a__mbsncmp;
	if (func == p_mbsnbcmp)
		return wine32a__mbsnbcmp;
	if (func == p_mbsnicmp)
		return wine32a__mbsnicmp;
	if (func == p_mbsnbicmp)
		return wine32a__mbsnbicmp;
	if (func == p_mbscat)
		return wine32a__mbscat;
	if (func == p_mbscat_s_l)
		return wine32a__mbscat_s_l;
	if (func == p_mbscat_s)
		return wine32a__mbscat_s;
	if (func == p_mbscpy)
		return wine32a__mbscpy;
	if (func == p_mbsstr)
		return wine32a__mbsstr;
	if (func == p_mbschr)
		return wine32a__mbschr;
	if (func == p_mbsrchr)
		return wine32a__mbsrchr;
	if (func == p_mbstok_s_l)
		return wine32a__mbstok_s_l;
	if (func == p_mbstok_s)
		return wine32a__mbstok_s;
	if (func == p_mbstok_l)
		return wine32a__mbstok_l;
	if (func == p_mbstok)
		return wine32a__mbstok;
	if (func == p_mbbtombc)
		return wine32a__mbbtombc;
	if (func == p_mbbtype)
		return wine32a__mbbtype;
	if (func == p_ismbbkana)
		return wine32a__ismbbkana;
	if (func == p_ismbcdigit)
		return wine32a__ismbcdigit;
	if (func == p_ismbcgraph)
		return wine32a__ismbcgraph;
	if (func == p_ismbcalpha)
		return wine32a__ismbcalpha;
	if (func == p_ismbclower)
		return wine32a__ismbclower;
	if (func == p_ismbcupper)
		return wine32a__ismbcupper;
	if (func == p_ismbcsymbol)
		return wine32a__ismbcsymbol;
	if (func == p_ismbcalnum)
		return wine32a__ismbcalnum;
	if (func == p_ismbcspace)
		return wine32a__ismbcspace;
	if (func == p_ismbcprint)
		return wine32a__ismbcprint;
	if (func == p_ismbcpunct)
		return wine32a__ismbcpunct;
	if (func == p_ismbchira)
		return wine32a__ismbchira;
	if (func == p_ismbckata)
		return wine32a__ismbckata;
	if (func == p_ismbblead_l)
		return wine32a__ismbblead_l;
	if (func == p_ismbblead)
		return wine32a__ismbblead;
	if (func == p_ismbbtrail_l)
		return wine32a__ismbbtrail_l;
	if (func == p_ismbbtrail)
		return wine32a__ismbbtrail;
	if (func == p_ismbclegal_l)
		return wine32a__ismbclegal_l;
	if (func == p_ismbclegal)
		return wine32a__ismbclegal;
	if (func == p_ismbslead)
		return wine32a__ismbslead;
	if (func == p_ismbstrail)
		return wine32a__ismbstrail;
	if (func == p_mbsbtype)
		return wine32a__mbsbtype;
	if (func == p_mbsset)
		return wine32a__mbsset;
	if (func == p_mbsnbset)
		return wine32a__mbsnbset;
	if (func == p_mbsnset)
		return wine32a__mbsnset;
	if (func == p_mbsnccnt)
		return wine32a__mbsnccnt;
	if (func == p_mbsnbcnt)
		return wine32a__mbsnbcnt;
	if (func == p_mbsnbcat)
		return wine32a__mbsnbcat;
	if (func == p_mbsnbcat_s)
		return wine32a__mbsnbcat_s;
	if (func == p_mbsncat)
		return wine32a__mbsncat;
	if (func == p_mbslwr)
		return wine32a__mbslwr;
	if (func == p_mbslwr_s)
		return wine32a__mbslwr_s;
	if (func == p_mbsupr)
		return wine32a__mbsupr;
	if (func == p_mbsupr_s)
		return wine32a__mbsupr_s;
	if (func == p_mbsspn)
		return wine32a__mbsspn;
	if (func == p_mbsspnp)
		return wine32a__mbsspnp;
	if (func == p_mbscspn)
		return wine32a__mbscspn;
	if (func == p_mbsrev)
		return wine32a__mbsrev;
	if (func == p_mbspbrk)
		return wine32a__mbspbrk;
	if (func == p_mbstrlen_l)
		return wine32a__mbstrlen_l;
	if (func == p_mbstrlen)
		return wine32a__mbstrlen;
	if (func == p_mbctohira)
		return wine32a__mbctohira;
	if (func == p_mbctokata)
		return wine32a__mbctokata;
	if (func == p_ismbcl0_l)
		return wine32a__ismbcl0_l;
	if (func == p_ismbcl0)
		return wine32a__ismbcl0;
	if (func == p_ismbcl1_l)
		return wine32a__ismbcl1_l;
	if (func == p_ismbcl1)
		return wine32a__ismbcl1;
	if (func == p_ismbcl2_l)
		return wine32a__ismbcl2_l;
	if (func == p_ismbcl2)
		return wine32a__ismbcl2;
	if (func == p_lfind)
		return wine32a__lfind;
	if (func == p_lfind_s)
		return wine32a__lfind_s;
	if (func == p_lsearch)
		return wine32a__lsearch;
	if (func == p_cwait)
		return wine32a__cwait;
	if (func == p_wexecl)
		return wine32a__wexecl;
	if (func == p_execl)
		return wine32a__execl;
	if (func == p_wexecle)
		return wine32a__wexecle;
	if (func == p_execle)
		return wine32a__execle;
	if (func == p_wexeclp)
		return wine32a__wexeclp;
	if (func == p_execlp)
		return wine32a__execlp;
	if (func == p_wexeclpe)
		return wine32a__wexeclpe;
	if (func == p_execlpe)
		return wine32a__execlpe;
	if (func == p_wexecv)
		return wine32a__wexecv;
	if (func == p_execv)
		return wine32a__execv;
	if (func == p_wexecve)
		return wine32a__wexecve;
	if (func == p_wexecvpe)
		return wine32a__wexecvpe;
	if (func == p_execvpe)
		return wine32a__execvpe;
	if (func == p_wexecvp)
		return wine32a__wexecvp;
	if (func == p_execvp)
		return wine32a__execvp;
	if (func == p_wsystem)
		return wine32a__wsystem;
	if (func == p_loaddll)
		return wine32a__loaddll;
	if (func == p_unloaddll)
		return wine32a__unloaddll;
	if (func == p_getdllprocaddr)
		return wine32a__getdllprocaddr;
	if (func == p_getpid)
		return wine32a__getpid;
	if (func == p_cscanf)
		return wine32a__cscanf;
	if (func == p_cscanf_l)
		return wine32a__cscanf_l;
	if (func == p_cscanf_s)
		return wine32a__cscanf_s;
	if (func == p_cscanf_s_l)
		return wine32a__cscanf_s_l;
	if (func == p_cwscanf)
		return wine32a__cwscanf;
	if (func == p_cwscanf_l)
		return wine32a__cwscanf_l;
	if (func == p_cwscanf_s)
		return wine32a__cwscanf_s;
	if (func == p_cwscanf_s_l)
		return wine32a__cwscanf_s_l;
	if (func == p_strlwr_l)
		return wine32a__strlwr_l;
	if (func == p_strset)
		return wine32a__strset;
	if (func == p__STRINGTOLD)
		return wine32a___STRINGTOLD;
	if (func == p_endthread)
		return wine32a__endthread;
	if (func == p_endthreadex)
		return wine32a__endthreadex;
	if (func == p_beginthread)
		return wine32a__beginthread;
	if (func == p_beginthreadex)
		return wine32a__beginthreadex;
	if (func == p_localtime64_s)
		return wine32a__localtime64_s;
	if (func == p_localtime32_s)
		return wine32a__localtime32_s;
	if (func == p_strdate_s)
		return wine32a__strdate_s;
	if (func == p_wstrdate_s)
		return wine32a__wstrdate_s;
	if (func == p_strtime_s)
		return wine32a__strtime_s;
	if (func == p_wstrtime_s)
		return wine32a__wstrtime_s;
	if (func == p__p__tzname)
		return wine32a___p__tzname;
	if (func == p_Strftime)
		return wine32a__Strftime;
	if (func == p__unDNameEx)
		return wine32a___unDNameEx;
	if (func == p__unDName)
		return wine32a___unDName;

	return NULL;
}
