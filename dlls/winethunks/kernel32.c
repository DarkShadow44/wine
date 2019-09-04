#define WIN32_NO_STATUS
#include "ntstatus.h"
#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

#include "../../include/windef.h"
#include "../../include/winbase.h"
#include "../../include/winnls.h"
#include "../../include/winternl.h"
#include "../../include/wine/debug.h"
#include "../../include/wine/exception.h"
#include "../../include/wine/unicode.h"
#include "../../dlls/kernel32/kernel_private.h"
#include "../../include/ntstatus.h"
#include "../../include/winioctl.h"
#include "../../include/ddk/ntddser.h"
#include "../../include/wine/server.h"
#include "../../include/wincon.h"
#include "../../dlls/kernel32/console_private.h"
#include "../../include/psapi.h"
#include "../../include/ddk/wdm.h"
#include "../../include/winerror.h"
#include "../../include/wine/asm.h"
#include "../../include/wine/library.h"
#include "../../include/wingdi.h"
#include "../../include/winuser.h"
#include "../../include/ddk/ntddk.h"
#include "../../include/fileapi.h"
#include "../../include/pshpack1.h"
#include "../../include/poppack.h"
#include "../../include/winver.h"
#include "../../include/wine/heap.h"
#include "../../include/lzexpand.h"
#include "../../include/wine/list.h"
#include "../../include/ntddscsi.h"
#include "../../include/wine/winethunks.h"
#include "../../include/ddk/ntddtape.h"
#include "../../include/tlhelp32.h"
#include "../../include/ntddcdrm.h"
#include "../../include/ddk/mountmgr.h"
#include "../../include/werapi.h"

static WINAPI HANDLE (*pCreateActCtxA)(PCACTCTXA pActCtx);
static WINAPI BOOL (*pFindActCtxSectionStringA)(DWORD dwFlags, const GUID * lpExtGuid, ULONG ulId, LPCSTR lpSearchStr, PACTCTX_SECTION_KEYED_DATA pInfo);

extern WINAPI HANDLE wine32b_CreateActCtxA(PCACTCTXA pActCtx)
{
	TRACE("Enter CreateActCtxA\n");
	return pCreateActCtxA(pActCtx);
}

extern WINAPI void wine32a_CreateActCtxA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateActCtxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateActCtxA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FindActCtxSectionStringA(DWORD dwFlags, const GUID * lpExtGuid, ULONG ulId, LPCSTR lpSearchStr, PACTCTX_SECTION_KEYED_DATA pInfo)
{
	TRACE("Enter FindActCtxSectionStringA\n");
	return pFindActCtxSectionStringA(dwFlags, lpExtGuid, ulId, lpSearchStr, pInfo);
}

extern WINAPI void wine32a_FindActCtxSectionStringA(void);
__ASM_GLOBAL_FUNC(wine32a_FindActCtxSectionStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindActCtxSectionStringA") "\n"
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

static WINAPI BOOL (*pInitAtomTable)(DWORD entries);
static WINAPI ATOM (*pGlobalAddAtomA)(LPCSTR str);
static WINAPI ATOM (*pAddAtomA)(LPCSTR str);
static WINAPI ATOM (*pGlobalAddAtomW)(LPCWSTR str);
static WINAPI ATOM (*pAddAtomW)(LPCWSTR str);
static WINAPI ATOM (*pGlobalDeleteAtom)(ATOM atom);
static WINAPI ATOM (*pDeleteAtom)(ATOM atom);
static WINAPI ATOM (*pGlobalFindAtomA)(LPCSTR str);
static WINAPI ATOM (*pFindAtomA)(LPCSTR str);
static WINAPI ATOM (*pGlobalFindAtomW)(LPCWSTR str);
static WINAPI ATOM (*pFindAtomW)(LPCWSTR str);
static WINAPI UINT (*pGlobalGetAtomNameA)(ATOM atom, LPSTR buffer, INT count);
static WINAPI UINT (*pGetAtomNameA)(ATOM atom, LPSTR buffer, INT count);
static WINAPI UINT (*pGlobalGetAtomNameW)(ATOM atom, LPWSTR buffer, INT count);
static WINAPI UINT (*pGetAtomNameW)(ATOM atom, LPWSTR buffer, INT count);

extern WINAPI BOOL wine32b_InitAtomTable(DWORD entries)
{
	TRACE("Enter InitAtomTable\n");
	return pInitAtomTable(entries);
}

extern WINAPI void wine32a_InitAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_InitAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_GlobalAddAtomA(LPCSTR str)
{
	TRACE("Enter GlobalAddAtomA\n");
	return pGlobalAddAtomA(str);
}

extern WINAPI void wine32a_GlobalAddAtomA(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalAddAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalAddAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_AddAtomA(LPCSTR str)
{
	TRACE("Enter AddAtomA\n");
	return pAddAtomA(str);
}

extern WINAPI void wine32a_AddAtomA(void);
__ASM_GLOBAL_FUNC(wine32a_AddAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_GlobalAddAtomW(LPCWSTR str)
{
	TRACE("Enter GlobalAddAtomW\n");
	return pGlobalAddAtomW(str);
}

extern WINAPI void wine32a_GlobalAddAtomW(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalAddAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalAddAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_AddAtomW(LPCWSTR str)
{
	TRACE("Enter AddAtomW\n");
	return pAddAtomW(str);
}

extern WINAPI void wine32a_AddAtomW(void);
__ASM_GLOBAL_FUNC(wine32a_AddAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_GlobalDeleteAtom(ATOM atom)
{
	TRACE("Enter GlobalDeleteAtom\n");
	return pGlobalDeleteAtom(atom);
}

extern WINAPI void wine32a_GlobalDeleteAtom(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalDeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalDeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_DeleteAtom(ATOM atom)
{
	TRACE("Enter DeleteAtom\n");
	return pDeleteAtom(atom);
}

extern WINAPI void wine32a_DeleteAtom(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_GlobalFindAtomA(LPCSTR str)
{
	TRACE("Enter GlobalFindAtomA\n");
	return pGlobalFindAtomA(str);
}

extern WINAPI void wine32a_GlobalFindAtomA(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalFindAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalFindAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_FindAtomA(LPCSTR str)
{
	TRACE("Enter FindAtomA\n");
	return pFindAtomA(str);
}

extern WINAPI void wine32a_FindAtomA(void);
__ASM_GLOBAL_FUNC(wine32a_FindAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_GlobalFindAtomW(LPCWSTR str)
{
	TRACE("Enter GlobalFindAtomW\n");
	return pGlobalFindAtomW(str);
}

extern WINAPI void wine32a_GlobalFindAtomW(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalFindAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalFindAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_FindAtomW(LPCWSTR str)
{
	TRACE("Enter FindAtomW\n");
	return pFindAtomW(str);
}

extern WINAPI void wine32a_FindAtomW(void);
__ASM_GLOBAL_FUNC(wine32a_FindAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GlobalGetAtomNameA(ATOM atom, LPSTR buffer, INT count)
{
	TRACE("Enter GlobalGetAtomNameA\n");
	return pGlobalGetAtomNameA(atom, buffer, count);
}

extern WINAPI void wine32a_GlobalGetAtomNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalGetAtomNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalGetAtomNameA") "\n"
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

extern WINAPI UINT wine32b_GetAtomNameA(ATOM atom, LPSTR buffer, INT count)
{
	TRACE("Enter GetAtomNameA\n");
	return pGetAtomNameA(atom, buffer, count);
}

extern WINAPI void wine32a_GetAtomNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetAtomNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAtomNameA") "\n"
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

extern WINAPI UINT wine32b_GlobalGetAtomNameW(ATOM atom, LPWSTR buffer, INT count)
{
	TRACE("Enter GlobalGetAtomNameW\n");
	return pGlobalGetAtomNameW(atom, buffer, count);
}

extern WINAPI void wine32a_GlobalGetAtomNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalGetAtomNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalGetAtomNameW") "\n"
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

extern WINAPI UINT wine32b_GetAtomNameW(ATOM atom, LPWSTR buffer, INT count)
{
	TRACE("Enter GetAtomNameW\n");
	return pGetAtomNameW(atom, buffer, count);
}

extern WINAPI void wine32a_GetAtomNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetAtomNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAtomNameW") "\n"
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

static WINAPI HANDLE (*pFindFirstChangeNotificationA)(LPCSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter);
static WINAPI HANDLE (*pFindFirstChangeNotificationW)(LPCWSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter);
static WINAPI BOOL (*pFindNextChangeNotification)(HANDLE handle);
static WINAPI BOOL (*pFindCloseChangeNotification)(HANDLE handle);
static WINAPI BOOL (*pReadDirectoryChangesW)(HANDLE handle, LPVOID buffer, DWORD len, BOOL subtree, DWORD filter, LPDWORD returned, LPOVERLAPPED overlapped, LPOVERLAPPED_COMPLETION_ROUTINE completion);

extern WINAPI HANDLE wine32b_FindFirstChangeNotificationA(LPCSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter)
{
	TRACE("Enter FindFirstChangeNotificationA\n");
	return pFindFirstChangeNotificationA(lpPathName, bWatchSubtree, dwNotifyFilter);
}

extern WINAPI void wine32a_FindFirstChangeNotificationA(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstChangeNotificationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstChangeNotificationA") "\n"
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

extern WINAPI HANDLE wine32b_FindFirstChangeNotificationW(LPCWSTR lpPathName, BOOL bWatchSubtree, DWORD dwNotifyFilter)
{
	TRACE("Enter FindFirstChangeNotificationW\n");
	return pFindFirstChangeNotificationW(lpPathName, bWatchSubtree, dwNotifyFilter);
}

extern WINAPI void wine32a_FindFirstChangeNotificationW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstChangeNotificationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstChangeNotificationW") "\n"
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

extern WINAPI BOOL wine32b_FindNextChangeNotification(HANDLE handle)
{
	TRACE("Enter FindNextChangeNotification\n");
	return pFindNextChangeNotification(handle);
}

extern WINAPI void wine32a_FindNextChangeNotification(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FindCloseChangeNotification(HANDLE handle)
{
	TRACE("Enter FindCloseChangeNotification\n");
	return pFindCloseChangeNotification(handle);
}

extern WINAPI void wine32a_FindCloseChangeNotification(void);
__ASM_GLOBAL_FUNC(wine32a_FindCloseChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindCloseChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ReadDirectoryChangesW(HANDLE handle, LPVOID buffer, DWORD len, BOOL subtree, DWORD filter, LPDWORD returned, LPOVERLAPPED overlapped, LPOVERLAPPED_COMPLETION_ROUTINE completion)
{
	TRACE("Enter ReadDirectoryChangesW\n");
	return pReadDirectoryChangesW(handle, buffer, len, subtree, filter, returned, overlapped, completion);
}

extern WINAPI void wine32a_ReadDirectoryChangesW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadDirectoryChangesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadDirectoryChangesW") "\n"
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

static WINAPI BOOL (*pBuildCommDCBA)(LPCSTR device, LPDCB lpdcb);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsA)(LPCSTR device, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsW)(LPCWSTR devid, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pBuildCommDCBW)(LPCWSTR devid, LPDCB lpdcb);
static WINAPI BOOL (*pSetCommBreak)(HANDLE handle);
static WINAPI BOOL (*pClearCommBreak)(HANDLE handle);
static WINAPI BOOL (*pEscapeCommFunction)(HANDLE handle, DWORD func);
static WINAPI BOOL (*pPurgeComm)(HANDLE handle, DWORD flags);
static WINAPI BOOL (*pClearCommError)(HANDLE handle, LPDWORD errors, LPCOMSTAT lpStat);
static WINAPI BOOL (*pSetupComm)(HANDLE handle, DWORD insize, DWORD outsize);
static WINAPI BOOL (*pGetCommMask)(HANDLE handle, LPDWORD evtmask);
static WINAPI BOOL (*pSetCommMask)(HANDLE handle, DWORD evtmask);
static WINAPI BOOL (*pSetCommState)(HANDLE handle, LPDCB lpdcb);
static WINAPI BOOL (*pGetCommState)(HANDLE handle, LPDCB lpdcb);
static WINAPI BOOL (*pTransmitCommChar)(HANDLE hComm, CHAR chTransmit);
static WINAPI BOOL (*pGetCommTimeouts)(HANDLE hComm, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pSetCommTimeouts)(HANDLE hComm, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pGetCommModemStatus)(HANDLE hFile, LPDWORD lpModemStat);
static WINAPI BOOL (*pWaitCommEvent)(HANDLE hFile, LPDWORD lpdwEvents, LPOVERLAPPED lpOverlapped);
static WINAPI BOOL (*pGetCommProperties)(HANDLE hFile, LPCOMMPROP lpCommProp);
static WINAPI BOOL (*pCommConfigDialogA)(LPCSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig);
static WINAPI BOOL (*pCommConfigDialogW)(LPCWSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig);
static WINAPI BOOL (*pGetCommConfig)(HANDLE hFile, LPCOMMCONFIG lpCommConfig, LPDWORD lpdwSize);
static WINAPI BOOL (*pSetCommConfig)(HANDLE hFile, LPCOMMCONFIG lpCommConfig, DWORD dwSize);
static WINAPI BOOL (*pSetDefaultCommConfigW)(LPCWSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize);
static WINAPI BOOL (*pSetDefaultCommConfigA)(LPCSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize);
static WINAPI BOOL (*pGetDefaultCommConfigW)(LPCWSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize);
static WINAPI BOOL (*pGetDefaultCommConfigA)(LPCSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize);

extern WINAPI BOOL wine32b_BuildCommDCBA(LPCSTR device, LPDCB lpdcb)
{
	TRACE("Enter BuildCommDCBA\n");
	return pBuildCommDCBA(device, lpdcb);
}

extern WINAPI void wine32a_BuildCommDCBA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildCommDCBA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildCommDCBA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_BuildCommDCBAndTimeoutsA(LPCSTR device, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts)
{
	TRACE("Enter BuildCommDCBAndTimeoutsA\n");
	return pBuildCommDCBAndTimeoutsA(device, lpdcb, lptimeouts);
}

extern WINAPI void wine32a_BuildCommDCBAndTimeoutsA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildCommDCBAndTimeoutsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildCommDCBAndTimeoutsA") "\n"
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

extern WINAPI BOOL wine32b_BuildCommDCBAndTimeoutsW(LPCWSTR devid, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts)
{
	TRACE("Enter BuildCommDCBAndTimeoutsW\n");
	return pBuildCommDCBAndTimeoutsW(devid, lpdcb, lptimeouts);
}

extern WINAPI void wine32a_BuildCommDCBAndTimeoutsW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildCommDCBAndTimeoutsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildCommDCBAndTimeoutsW") "\n"
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

extern WINAPI BOOL wine32b_BuildCommDCBW(LPCWSTR devid, LPDCB lpdcb)
{
	TRACE("Enter BuildCommDCBW\n");
	return pBuildCommDCBW(devid, lpdcb);
}

extern WINAPI void wine32a_BuildCommDCBW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildCommDCBW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildCommDCBW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCommBreak(HANDLE handle)
{
	TRACE("Enter SetCommBreak\n");
	return pSetCommBreak(handle);
}

extern WINAPI void wine32a_SetCommBreak(void);
__ASM_GLOBAL_FUNC(wine32a_SetCommBreak,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCommBreak") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ClearCommBreak(HANDLE handle)
{
	TRACE("Enter ClearCommBreak\n");
	return pClearCommBreak(handle);
}

extern WINAPI void wine32a_ClearCommBreak(void);
__ASM_GLOBAL_FUNC(wine32a_ClearCommBreak,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClearCommBreak") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EscapeCommFunction(HANDLE handle, DWORD func)
{
	TRACE("Enter EscapeCommFunction\n");
	return pEscapeCommFunction(handle, func);
}

extern WINAPI void wine32a_EscapeCommFunction(void);
__ASM_GLOBAL_FUNC(wine32a_EscapeCommFunction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EscapeCommFunction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_PurgeComm(HANDLE handle, DWORD flags)
{
	TRACE("Enter PurgeComm\n");
	return pPurgeComm(handle, flags);
}

extern WINAPI void wine32a_PurgeComm(void);
__ASM_GLOBAL_FUNC(wine32a_PurgeComm,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PurgeComm") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ClearCommError(HANDLE handle, LPDWORD errors, LPCOMSTAT lpStat)
{
	TRACE("Enter ClearCommError\n");
	return pClearCommError(handle, errors, lpStat);
}

extern WINAPI void wine32a_ClearCommError(void);
__ASM_GLOBAL_FUNC(wine32a_ClearCommError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClearCommError") "\n"
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

extern WINAPI BOOL wine32b_SetupComm(HANDLE handle, DWORD insize, DWORD outsize)
{
	TRACE("Enter SetupComm\n");
	return pSetupComm(handle, insize, outsize);
}

extern WINAPI void wine32a_SetupComm(void);
__ASM_GLOBAL_FUNC(wine32a_SetupComm,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetupComm") "\n"
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

extern WINAPI BOOL wine32b_GetCommMask(HANDLE handle, LPDWORD evtmask)
{
	TRACE("Enter GetCommMask\n");
	return pGetCommMask(handle, evtmask);
}

extern WINAPI void wine32a_GetCommMask(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCommMask(HANDLE handle, DWORD evtmask)
{
	TRACE("Enter SetCommMask\n");
	return pSetCommMask(handle, evtmask);
}

extern WINAPI void wine32a_SetCommMask(void);
__ASM_GLOBAL_FUNC(wine32a_SetCommMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCommMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCommState(HANDLE handle, LPDCB lpdcb)
{
	TRACE("Enter SetCommState\n");
	return pSetCommState(handle, lpdcb);
}

extern WINAPI void wine32a_SetCommState(void);
__ASM_GLOBAL_FUNC(wine32a_SetCommState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCommState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCommState(HANDLE handle, LPDCB lpdcb)
{
	TRACE("Enter GetCommState\n");
	return pGetCommState(handle, lpdcb);
}

extern WINAPI void wine32a_GetCommState(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TransmitCommChar(HANDLE hComm, CHAR chTransmit)
{
	TRACE("Enter TransmitCommChar\n");
	return pTransmitCommChar(hComm, chTransmit);
}

extern WINAPI void wine32a_TransmitCommChar(void);
__ASM_GLOBAL_FUNC(wine32a_TransmitCommChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TransmitCommChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCommTimeouts(HANDLE hComm, LPCOMMTIMEOUTS lptimeouts)
{
	TRACE("Enter GetCommTimeouts\n");
	return pGetCommTimeouts(hComm, lptimeouts);
}

extern WINAPI void wine32a_GetCommTimeouts(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommTimeouts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommTimeouts") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCommTimeouts(HANDLE hComm, LPCOMMTIMEOUTS lptimeouts)
{
	TRACE("Enter SetCommTimeouts\n");
	return pSetCommTimeouts(hComm, lptimeouts);
}

extern WINAPI void wine32a_SetCommTimeouts(void);
__ASM_GLOBAL_FUNC(wine32a_SetCommTimeouts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCommTimeouts") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCommModemStatus(HANDLE hFile, LPDWORD lpModemStat)
{
	TRACE("Enter GetCommModemStatus\n");
	return pGetCommModemStatus(hFile, lpModemStat);
}

extern WINAPI void wine32a_GetCommModemStatus(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommModemStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommModemStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_WaitCommEvent(HANDLE hFile, LPDWORD lpdwEvents, LPOVERLAPPED lpOverlapped)
{
	TRACE("Enter WaitCommEvent\n");
	return pWaitCommEvent(hFile, lpdwEvents, lpOverlapped);
}

extern WINAPI void wine32a_WaitCommEvent(void);
__ASM_GLOBAL_FUNC(wine32a_WaitCommEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WaitCommEvent") "\n"
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

extern WINAPI BOOL wine32b_GetCommProperties(HANDLE hFile, LPCOMMPROP lpCommProp)
{
	TRACE("Enter GetCommProperties\n");
	return pGetCommProperties(hFile, lpCommProp);
}

extern WINAPI void wine32a_GetCommProperties(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommProperties,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommProperties") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CommConfigDialogA(LPCSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig)
{
	TRACE("Enter CommConfigDialogA\n");
	return pCommConfigDialogA(lpszDevice, hWnd, lpCommConfig);
}

extern WINAPI void wine32a_CommConfigDialogA(void);
__ASM_GLOBAL_FUNC(wine32a_CommConfigDialogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CommConfigDialogA") "\n"
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

extern WINAPI BOOL wine32b_CommConfigDialogW(LPCWSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig)
{
	TRACE("Enter CommConfigDialogW\n");
	return pCommConfigDialogW(lpszDevice, hWnd, lpCommConfig);
}

extern WINAPI void wine32a_CommConfigDialogW(void);
__ASM_GLOBAL_FUNC(wine32a_CommConfigDialogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CommConfigDialogW") "\n"
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

extern WINAPI BOOL wine32b_GetCommConfig(HANDLE hFile, LPCOMMCONFIG lpCommConfig, LPDWORD lpdwSize)
{
	TRACE("Enter GetCommConfig\n");
	return pGetCommConfig(hFile, lpCommConfig, lpdwSize);
}

extern WINAPI void wine32a_GetCommConfig(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommConfig") "\n"
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

extern WINAPI BOOL wine32b_SetCommConfig(HANDLE hFile, LPCOMMCONFIG lpCommConfig, DWORD dwSize)
{
	TRACE("Enter SetCommConfig\n");
	return pSetCommConfig(hFile, lpCommConfig, dwSize);
}

extern WINAPI void wine32a_SetCommConfig(void);
__ASM_GLOBAL_FUNC(wine32a_SetCommConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCommConfig") "\n"
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

extern WINAPI BOOL wine32b_SetDefaultCommConfigW(LPCWSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize)
{
	TRACE("Enter SetDefaultCommConfigW\n");
	return pSetDefaultCommConfigW(lpszDevice, lpCommConfig, dwSize);
}

extern WINAPI void wine32a_SetDefaultCommConfigW(void);
__ASM_GLOBAL_FUNC(wine32a_SetDefaultCommConfigW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDefaultCommConfigW") "\n"
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

extern WINAPI BOOL wine32b_SetDefaultCommConfigA(LPCSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize)
{
	TRACE("Enter SetDefaultCommConfigA\n");
	return pSetDefaultCommConfigA(lpszDevice, lpCommConfig, dwSize);
}

extern WINAPI void wine32a_SetDefaultCommConfigA(void);
__ASM_GLOBAL_FUNC(wine32a_SetDefaultCommConfigA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDefaultCommConfigA") "\n"
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

extern WINAPI BOOL wine32b_GetDefaultCommConfigW(LPCWSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize)
{
	TRACE("Enter GetDefaultCommConfigW\n");
	return pGetDefaultCommConfigW(lpszName, lpCC, lpdwSize);
}

extern WINAPI void wine32a_GetDefaultCommConfigW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDefaultCommConfigW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDefaultCommConfigW") "\n"
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

extern WINAPI BOOL wine32b_GetDefaultCommConfigA(LPCSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize)
{
	TRACE("Enter GetDefaultCommConfigA\n");
	return pGetDefaultCommConfigA(lpszName, lpCC, lpdwSize);
}

extern WINAPI void wine32a_GetDefaultCommConfigA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDefaultCommConfigA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDefaultCommConfigA") "\n"
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

static WINAPI BOOL (*pGetComputerNameW)(LPWSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameA)(LPSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameExA)(COMPUTER_NAME_FORMAT type, LPSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameExW)(COMPUTER_NAME_FORMAT type, LPWSTR name, LPDWORD size);
static WINAPI BOOL (*pSetComputerNameW)(LPCWSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameA)(LPCSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameExW)(COMPUTER_NAME_FORMAT type, LPCWSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameExA)(COMPUTER_NAME_FORMAT type, LPCSTR lpComputerName);
static WINAPI BOOL (*pDnsHostnameToComputerNameA)(LPCSTR hostname, LPSTR computername, LPDWORD size);
static WINAPI BOOL (*pDnsHostnameToComputerNameW)(LPCWSTR hostname, LPWSTR computername, LPDWORD size);

extern WINAPI BOOL wine32b_GetComputerNameW(LPWSTR name, LPDWORD size)
{
	TRACE("Enter GetComputerNameW\n");
	return pGetComputerNameW(name, size);
}

extern WINAPI void wine32a_GetComputerNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetComputerNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetComputerNameA(LPSTR name, LPDWORD size)
{
	TRACE("Enter GetComputerNameA\n");
	return pGetComputerNameA(name, size);
}

extern WINAPI void wine32a_GetComputerNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetComputerNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetComputerNameExA(COMPUTER_NAME_FORMAT type, LPSTR name, LPDWORD size)
{
	TRACE("Enter GetComputerNameExA\n");
	return pGetComputerNameExA(type, name, size);
}

extern WINAPI void wine32a_GetComputerNameExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetComputerNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetComputerNameExA") "\n"
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

extern WINAPI BOOL wine32b_GetComputerNameExW(COMPUTER_NAME_FORMAT type, LPWSTR name, LPDWORD size)
{
	TRACE("Enter GetComputerNameExW\n");
	return pGetComputerNameExW(type, name, size);
}

extern WINAPI void wine32a_GetComputerNameExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetComputerNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetComputerNameExW") "\n"
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

extern WINAPI BOOL wine32b_SetComputerNameW(LPCWSTR lpComputerName)
{
	TRACE("Enter SetComputerNameW\n");
	return pSetComputerNameW(lpComputerName);
}

extern WINAPI void wine32a_SetComputerNameW(void);
__ASM_GLOBAL_FUNC(wine32a_SetComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetComputerNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetComputerNameA(LPCSTR lpComputerName)
{
	TRACE("Enter SetComputerNameA\n");
	return pSetComputerNameA(lpComputerName);
}

extern WINAPI void wine32a_SetComputerNameA(void);
__ASM_GLOBAL_FUNC(wine32a_SetComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetComputerNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetComputerNameExW(COMPUTER_NAME_FORMAT type, LPCWSTR lpComputerName)
{
	TRACE("Enter SetComputerNameExW\n");
	return pSetComputerNameExW(type, lpComputerName);
}

extern WINAPI void wine32a_SetComputerNameExW(void);
__ASM_GLOBAL_FUNC(wine32a_SetComputerNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetComputerNameExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetComputerNameExA(COMPUTER_NAME_FORMAT type, LPCSTR lpComputerName)
{
	TRACE("Enter SetComputerNameExA\n");
	return pSetComputerNameExA(type, lpComputerName);
}

extern WINAPI void wine32a_SetComputerNameExA(void);
__ASM_GLOBAL_FUNC(wine32a_SetComputerNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetComputerNameExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DnsHostnameToComputerNameA(LPCSTR hostname, LPSTR computername, LPDWORD size)
{
	TRACE("Enter DnsHostnameToComputerNameA\n");
	return pDnsHostnameToComputerNameA(hostname, computername, size);
}

extern WINAPI void wine32a_DnsHostnameToComputerNameA(void);
__ASM_GLOBAL_FUNC(wine32a_DnsHostnameToComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DnsHostnameToComputerNameA") "\n"
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

extern WINAPI BOOL wine32b_DnsHostnameToComputerNameW(LPCWSTR hostname, LPWSTR computername, LPDWORD size)
{
	TRACE("Enter DnsHostnameToComputerNameW\n");
	return pDnsHostnameToComputerNameW(hostname, computername, size);
}

extern WINAPI void wine32a_DnsHostnameToComputerNameW(void);
__ASM_GLOBAL_FUNC(wine32a_DnsHostnameToComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DnsHostnameToComputerNameW") "\n"
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

static WINAPI HWND (*pGetConsoleWindow)(void);
static WINAPI UINT (*pGetConsoleCP)(void);
static WINAPI BOOL (*pSetConsoleCP)(UINT cp);
static WINAPI UINT (*pGetConsoleOutputCP)(void);
static WINAPI BOOL (*pSetConsoleOutputCP)(UINT cp);
static WINAPI BOOL (*pBeep)(DWORD dwFreq, DWORD dwDur);
static WINAPI HANDLE (*pOpenConsoleW)(LPCWSTR name, DWORD access, BOOL inherit, DWORD creation);
static WINAPI BOOL (*pVerifyConsoleIoHandle)(HANDLE handle);
static WINAPI HANDLE (*pDuplicateConsoleHandle)(HANDLE handle, DWORD access, BOOL inherit, DWORD options);
static WINAPI BOOL (*pCloseConsoleHandle)(HANDLE handle);
static WINAPI HANDLE (*pGetConsoleInputWaitHandle)(void);
static WINAPI BOOL (*pWriteConsoleInputA)(HANDLE handle, const INPUT_RECORD * buffer, DWORD count, LPDWORD written);
static WINAPI BOOL (*pWriteConsoleInputW)(HANDLE handle, const INPUT_RECORD * buffer, DWORD count, LPDWORD written);
static WINAPI BOOL (*pWriteConsoleOutputA)(HANDLE hConsoleOutput, const CHAR_INFO * lpBuffer, COORD size, COORD coord, LPSMALL_RECT region);
static WINAPI BOOL (*pWriteConsoleOutputW)(HANDLE hConsoleOutput, const CHAR_INFO * lpBuffer, COORD size, COORD coord, LPSMALL_RECT region);
static WINAPI BOOL (*pWriteConsoleOutputCharacterA)(HANDLE hConsoleOutput, LPCSTR str, DWORD length, COORD coord, LPDWORD lpNumCharsWritten);
static WINAPI BOOL (*pWriteConsoleOutputAttribute)(HANDLE hConsoleOutput, const WORD * attr, DWORD length, COORD coord, LPDWORD lpNumAttrsWritten);
static WINAPI BOOL (*pFillConsoleOutputCharacterA)(HANDLE hConsoleOutput, CHAR ch, DWORD length, COORD coord, LPDWORD lpNumCharsWritten);
static WINAPI BOOL (*pFillConsoleOutputCharacterW)(HANDLE hConsoleOutput, WCHAR ch, DWORD length, COORD coord, LPDWORD lpNumCharsWritten);
static WINAPI BOOL (*pFillConsoleOutputAttribute)(HANDLE hConsoleOutput, WORD attr, DWORD length, COORD coord, LPDWORD lpNumAttrsWritten);
static WINAPI BOOL (*pReadConsoleOutputCharacterA)(HANDLE hConsoleOutput, LPSTR lpstr, DWORD count, COORD coord, LPDWORD read_count);
static WINAPI BOOL (*pReadConsoleOutputCharacterW)(HANDLE hConsoleOutput, LPWSTR buffer, DWORD count, COORD coord, LPDWORD read_count);
static WINAPI BOOL (*pReadConsoleOutputAttribute)(HANDLE hConsoleOutput, LPWORD lpAttribute, DWORD length, COORD coord, LPDWORD read_count);
static WINAPI BOOL (*pReadConsoleOutputA)(HANDLE hConsoleOutput, LPCHAR_INFO lpBuffer, COORD size, COORD coord, LPSMALL_RECT region);
static WINAPI BOOL (*pReadConsoleOutputW)(HANDLE hConsoleOutput, LPCHAR_INFO lpBuffer, COORD size, COORD coord, LPSMALL_RECT region);
static WINAPI BOOL (*pReadConsoleInputA)(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD pRead);
static WINAPI BOOL (*pPeekConsoleInputA)(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD pRead);
static WINAPI BOOL (*pPeekConsoleInputW)(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD read);
static WINAPI BOOL (*pGetNumberOfConsoleInputEvents)(HANDLE handle, LPDWORD nrofevents);
static WINAPI BOOL (*pFlushConsoleInputBuffer)(HANDLE handle);
static WINAPI BOOL (*pSetConsoleTitleA)(LPCSTR title);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameA)(LPSTR layoutName);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameW)(LPWSTR layoutName);
static WINAPI BOOL (*pGetConsoleInputExeNameW)(DWORD buflen, LPWSTR buffer);
static WINAPI BOOL (*pGetConsoleInputExeNameA)(DWORD buflen, LPSTR buffer);
static WINAPI DWORD (*pGetConsoleTitleA)(LPSTR title, DWORD size);
static WINAPI DWORD (*pGetConsoleTitleW)(LPWSTR title, DWORD size);
static WINAPI COORD (*pGetLargestConsoleWindowSize)(HANDLE hConsoleOutput);
static WINAPI BOOL (*pFreeConsole)(void);
static WINAPI BOOL (*pAllocConsole)(void);
static WINAPI BOOL (*pReadConsoleA)(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved);
static WINAPI BOOL (*pReadConsoleW)(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved);
static WINAPI BOOL (*pReadConsoleInputW)(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead);
static WINAPI BOOL (*pWriteConsoleOutputCharacterW)(HANDLE hConsoleOutput, LPCWSTR str, DWORD length, COORD coord, LPDWORD lpNumCharsWritten);
static WINAPI BOOL (*pSetConsoleTitleW)(LPCWSTR title);
static WINAPI BOOL (*pGetNumberOfConsoleMouseButtons)(LPDWORD nrofbuttons);
static WINAPI BOOL (*pSetConsoleInputExeNameW)(LPCWSTR name);
static WINAPI BOOL (*pSetConsoleInputExeNameA)(LPCSTR name);
static WINAPI BOOL (*pSetConsoleCtrlHandler)(PHANDLER_ROUTINE func, BOOL add);
static WINAPI BOOL (*pGenerateConsoleCtrlEvent)(DWORD dwCtrlEvent, DWORD dwProcessGroupID);
static WINAPI HANDLE (*pCreateConsoleScreenBuffer)(DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES sa, DWORD dwFlags, LPVOID lpScreenBufferData);
static WINAPI BOOL (*pGetConsoleScreenBufferInfo)(HANDLE hConsoleOutput, LPCONSOLE_SCREEN_BUFFER_INFO csbi);
static WINAPI BOOL (*pSetConsoleActiveScreenBuffer)(HANDLE hConsoleOutput);
static WINAPI BOOL (*pGetConsoleMode)(HANDLE hcon, LPDWORD mode);
static WINAPI BOOL (*pSetConsoleMode)(HANDLE hcon, DWORD mode);
static WINAPI BOOL (*pWriteConsoleW)(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
static WINAPI BOOL (*pWriteConsoleA)(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
static WINAPI BOOL (*pSetConsoleCursorPosition)(HANDLE hcon, COORD pos);
static WINAPI BOOL (*pGetConsoleCursorInfo)(HANDLE hCon, LPCONSOLE_CURSOR_INFO cinfo);
static WINAPI BOOL (*pSetConsoleCursorInfo)(HANDLE hCon, LPCONSOLE_CURSOR_INFO cinfo);
static WINAPI BOOL (*pSetConsoleWindowInfo)(HANDLE hCon, BOOL bAbsolute, LPSMALL_RECT window);
static WINAPI BOOL (*pSetConsoleTextAttribute)(HANDLE hConsoleOutput, WORD wAttr);
static WINAPI BOOL (*pSetConsoleScreenBufferSize)(HANDLE hConsoleOutput, COORD dwSize);
static WINAPI BOOL (*pScrollConsoleScreenBufferA)(HANDLE hConsoleOutput, LPSMALL_RECT lpScrollRect, LPSMALL_RECT lpClipRect, COORD dwDestOrigin, LPCHAR_INFO lpFill);
static WINAPI BOOL (*pScrollConsoleScreenBufferW)(HANDLE hConsoleOutput, LPSMALL_RECT lpScrollRect, LPSMALL_RECT lpClipRect, COORD dwDestOrigin, LPCHAR_INFO lpFill);
static WINAPI BOOL (*pAttachConsole)(DWORD dwProcessId);
static WINAPI BOOL (*pGetConsoleDisplayMode)(LPDWORD lpModeFlags);
static WINAPI BOOL (*pSetConsoleDisplayMode)(HANDLE hConsoleOutput, DWORD dwFlags, COORD * lpNewScreenBufferDimensions);
static WINAPI DWORD (*pGetConsoleAliasW)(LPWSTR lpSource, LPWSTR lpTargetBuffer, DWORD TargetBufferLength, LPWSTR lpExename);
static WINAPI DWORD (*pGetConsoleProcessList)(LPDWORD processlist, DWORD processcount);
static WINAPI DWORD (*pGetConsoleCommandHistoryA)(DWORD unknown1, DWORD unknown2, DWORD unknown3);
static WINAPI DWORD (*pGetConsoleCommandHistoryW)(DWORD unknown1, DWORD unknown2, DWORD unknown3);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthA)(LPCSTR unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthW)(LPCWSTR unknown);
static WINAPI DWORD (*pGetConsoleAliasesLengthA)(LPSTR unknown);
static WINAPI DWORD (*pGetConsoleAliasesLengthW)(LPWSTR unknown);
static WINAPI DWORD (*pGetConsoleAliasExesLengthA)(void);
static WINAPI DWORD (*pGetConsoleAliasExesLengthW)(void);
static WINAPI void (*pExpungeConsoleCommandHistoryA)(LPCSTR unknown);
static WINAPI void (*pExpungeConsoleCommandHistoryW)(LPCWSTR unknown);
static WINAPI BOOL (*pAddConsoleAliasA)(LPSTR source, LPSTR target, LPSTR exename);
static WINAPI BOOL (*pAddConsoleAliasW)(LPWSTR source, LPWSTR target, LPWSTR exename);
static WINAPI BOOL (*pSetConsoleIcon)(HICON icon);
static WINAPI DWORD (*pGetNumberOfConsoleFonts)(void);
static WINAPI BOOL (*pSetConsoleFont)(HANDLE hConsole, DWORD index);
static WINAPI BOOL (*pSetConsoleKeyShortcuts)(BOOL set, BYTE keys, void * a, DWORD b);
static WINAPI BOOL (*pGetCurrentConsoleFont)(HANDLE hConsole, BOOL maxwindow, LPCONSOLE_FONT_INFO fontinfo);
static WINAPI COORD (*pGetConsoleFontSize)(HANDLE hConsole, DWORD index);
static WINAPI BOOL (*pGetConsoleFontInfo)(HANDLE hConsole, BOOL maximize, DWORD numfonts, CONSOLE_FONT_INFO * info);
static WINAPI BOOL (*pGetConsoleScreenBufferInfoEx)(HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFOEX * csbix);
static WINAPI BOOL (*pSetConsoleScreenBufferInfoEx)(HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFOEX * csbix);
static WINAPI BOOL (*pSetCurrentConsoleFontEx)(HANDLE hConsole, BOOL maxwindow, CONSOLE_FONT_INFOEX * cfix);

extern WINAPI HWND wine32b_GetConsoleWindow(void)
{
	TRACE("Enter GetConsoleWindow\n");
	return pGetConsoleWindow();
}

extern WINAPI void wine32a_GetConsoleWindow(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleWindow") "\n"
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

extern WINAPI UINT wine32b_GetConsoleCP(void)
{
	TRACE("Enter GetConsoleCP\n");
	return pGetConsoleCP();
}

extern WINAPI void wine32a_GetConsoleCP(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCP") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleCP(UINT cp)
{
	TRACE("Enter SetConsoleCP\n");
	return pSetConsoleCP(cp);
}

extern WINAPI void wine32a_SetConsoleCP(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleCP") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetConsoleOutputCP(void)
{
	TRACE("Enter GetConsoleOutputCP\n");
	return pGetConsoleOutputCP();
}

extern WINAPI void wine32a_GetConsoleOutputCP(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleOutputCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleOutputCP") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleOutputCP(UINT cp)
{
	TRACE("Enter SetConsoleOutputCP\n");
	return pSetConsoleOutputCP(cp);
}

extern WINAPI void wine32a_SetConsoleOutputCP(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleOutputCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleOutputCP") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Beep(DWORD dwFreq, DWORD dwDur)
{
	TRACE("Enter Beep\n");
	return pBeep(dwFreq, dwDur);
}

extern WINAPI void wine32a_Beep(void);
__ASM_GLOBAL_FUNC(wine32a_Beep,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Beep") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenConsoleW(LPCWSTR name, DWORD access, BOOL inherit, DWORD creation)
{
	TRACE("Enter OpenConsoleW\n");
	return pOpenConsoleW(name, access, inherit, creation);
}

extern WINAPI void wine32a_OpenConsoleW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenConsoleW") "\n"
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

extern WINAPI BOOL wine32b_VerifyConsoleIoHandle(HANDLE handle)
{
	TRACE("Enter VerifyConsoleIoHandle\n");
	return pVerifyConsoleIoHandle(handle);
}

extern WINAPI void wine32a_VerifyConsoleIoHandle(void);
__ASM_GLOBAL_FUNC(wine32a_VerifyConsoleIoHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerifyConsoleIoHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_DuplicateConsoleHandle(HANDLE handle, DWORD access, BOOL inherit, DWORD options)
{
	TRACE("Enter DuplicateConsoleHandle\n");
	return pDuplicateConsoleHandle(handle, access, inherit, options);
}

extern WINAPI void wine32a_DuplicateConsoleHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DuplicateConsoleHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DuplicateConsoleHandle") "\n"
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

extern WINAPI BOOL wine32b_CloseConsoleHandle(HANDLE handle)
{
	TRACE("Enter CloseConsoleHandle\n");
	return pCloseConsoleHandle(handle);
}

extern WINAPI void wine32a_CloseConsoleHandle(void);
__ASM_GLOBAL_FUNC(wine32a_CloseConsoleHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseConsoleHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_GetConsoleInputWaitHandle(void)
{
	TRACE("Enter GetConsoleInputWaitHandle\n");
	return pGetConsoleInputWaitHandle();
}

extern WINAPI void wine32a_GetConsoleInputWaitHandle(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleInputWaitHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleInputWaitHandle") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleInputA(HANDLE handle, const INPUT_RECORD * buffer, DWORD count, LPDWORD written)
{
	TRACE("Enter WriteConsoleInputA\n");
	return pWriteConsoleInputA(handle, buffer, count, written);
}

extern WINAPI void wine32a_WriteConsoleInputA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleInputA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleInputA") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleInputW(HANDLE handle, const INPUT_RECORD * buffer, DWORD count, LPDWORD written)
{
	TRACE("Enter WriteConsoleInputW\n");
	return pWriteConsoleInputW(handle, buffer, count, written);
}

extern WINAPI void wine32a_WriteConsoleInputW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleInputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleInputW") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleOutputA(HANDLE hConsoleOutput, const CHAR_INFO * lpBuffer, COORD size, COORD coord, LPSMALL_RECT region)
{
	TRACE("Enter WriteConsoleOutputA\n");
	return pWriteConsoleOutputA(hConsoleOutput, lpBuffer, size, coord, region);
}

extern WINAPI void wine32a_WriteConsoleOutputA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleOutputA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleOutputA") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleOutputW(HANDLE hConsoleOutput, const CHAR_INFO * lpBuffer, COORD size, COORD coord, LPSMALL_RECT region)
{
	TRACE("Enter WriteConsoleOutputW\n");
	return pWriteConsoleOutputW(hConsoleOutput, lpBuffer, size, coord, region);
}

extern WINAPI void wine32a_WriteConsoleOutputW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleOutputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleOutputW") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleOutputCharacterA(HANDLE hConsoleOutput, LPCSTR str, DWORD length, COORD coord, LPDWORD lpNumCharsWritten)
{
	TRACE("Enter WriteConsoleOutputCharacterA\n");
	return pWriteConsoleOutputCharacterA(hConsoleOutput, str, length, coord, lpNumCharsWritten);
}

extern WINAPI void wine32a_WriteConsoleOutputCharacterA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleOutputCharacterA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleOutputCharacterA") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleOutputAttribute(HANDLE hConsoleOutput, const WORD * attr, DWORD length, COORD coord, LPDWORD lpNumAttrsWritten)
{
	TRACE("Enter WriteConsoleOutputAttribute\n");
	return pWriteConsoleOutputAttribute(hConsoleOutput, attr, length, coord, lpNumAttrsWritten);
}

extern WINAPI void wine32a_WriteConsoleOutputAttribute(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleOutputAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleOutputAttribute") "\n"
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

extern WINAPI BOOL wine32b_FillConsoleOutputCharacterA(HANDLE hConsoleOutput, CHAR ch, DWORD length, COORD coord, LPDWORD lpNumCharsWritten)
{
	TRACE("Enter FillConsoleOutputCharacterA\n");
	return pFillConsoleOutputCharacterA(hConsoleOutput, ch, length, coord, lpNumCharsWritten);
}

extern WINAPI void wine32a_FillConsoleOutputCharacterA(void);
__ASM_GLOBAL_FUNC(wine32a_FillConsoleOutputCharacterA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FillConsoleOutputCharacterA") "\n"
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

extern WINAPI BOOL wine32b_FillConsoleOutputCharacterW(HANDLE hConsoleOutput, WCHAR ch, DWORD length, COORD coord, LPDWORD lpNumCharsWritten)
{
	TRACE("Enter FillConsoleOutputCharacterW\n");
	return pFillConsoleOutputCharacterW(hConsoleOutput, ch, length, coord, lpNumCharsWritten);
}

extern WINAPI void wine32a_FillConsoleOutputCharacterW(void);
__ASM_GLOBAL_FUNC(wine32a_FillConsoleOutputCharacterW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FillConsoleOutputCharacterW") "\n"
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

extern WINAPI BOOL wine32b_FillConsoleOutputAttribute(HANDLE hConsoleOutput, WORD attr, DWORD length, COORD coord, LPDWORD lpNumAttrsWritten)
{
	TRACE("Enter FillConsoleOutputAttribute\n");
	return pFillConsoleOutputAttribute(hConsoleOutput, attr, length, coord, lpNumAttrsWritten);
}

extern WINAPI void wine32a_FillConsoleOutputAttribute(void);
__ASM_GLOBAL_FUNC(wine32a_FillConsoleOutputAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FillConsoleOutputAttribute") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleOutputCharacterA(HANDLE hConsoleOutput, LPSTR lpstr, DWORD count, COORD coord, LPDWORD read_count)
{
	TRACE("Enter ReadConsoleOutputCharacterA\n");
	return pReadConsoleOutputCharacterA(hConsoleOutput, lpstr, count, coord, read_count);
}

extern WINAPI void wine32a_ReadConsoleOutputCharacterA(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleOutputCharacterA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleOutputCharacterA") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleOutputCharacterW(HANDLE hConsoleOutput, LPWSTR buffer, DWORD count, COORD coord, LPDWORD read_count)
{
	TRACE("Enter ReadConsoleOutputCharacterW\n");
	return pReadConsoleOutputCharacterW(hConsoleOutput, buffer, count, coord, read_count);
}

extern WINAPI void wine32a_ReadConsoleOutputCharacterW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleOutputCharacterW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleOutputCharacterW") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleOutputAttribute(HANDLE hConsoleOutput, LPWORD lpAttribute, DWORD length, COORD coord, LPDWORD read_count)
{
	TRACE("Enter ReadConsoleOutputAttribute\n");
	return pReadConsoleOutputAttribute(hConsoleOutput, lpAttribute, length, coord, read_count);
}

extern WINAPI void wine32a_ReadConsoleOutputAttribute(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleOutputAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleOutputAttribute") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleOutputA(HANDLE hConsoleOutput, LPCHAR_INFO lpBuffer, COORD size, COORD coord, LPSMALL_RECT region)
{
	TRACE("Enter ReadConsoleOutputA\n");
	return pReadConsoleOutputA(hConsoleOutput, lpBuffer, size, coord, region);
}

extern WINAPI void wine32a_ReadConsoleOutputA(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleOutputA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleOutputA") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleOutputW(HANDLE hConsoleOutput, LPCHAR_INFO lpBuffer, COORD size, COORD coord, LPSMALL_RECT region)
{
	TRACE("Enter ReadConsoleOutputW\n");
	return pReadConsoleOutputW(hConsoleOutput, lpBuffer, size, coord, region);
}

extern WINAPI void wine32a_ReadConsoleOutputW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleOutputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleOutputW") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleInputA(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD pRead)
{
	TRACE("Enter ReadConsoleInputA\n");
	return pReadConsoleInputA(handle, buffer, count, pRead);
}

extern WINAPI void wine32a_ReadConsoleInputA(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleInputA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleInputA") "\n"
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

extern WINAPI BOOL wine32b_PeekConsoleInputA(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD pRead)
{
	TRACE("Enter PeekConsoleInputA\n");
	return pPeekConsoleInputA(handle, buffer, count, pRead);
}

extern WINAPI void wine32a_PeekConsoleInputA(void);
__ASM_GLOBAL_FUNC(wine32a_PeekConsoleInputA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PeekConsoleInputA") "\n"
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

extern WINAPI BOOL wine32b_PeekConsoleInputW(HANDLE handle, PINPUT_RECORD buffer, DWORD count, LPDWORD read)
{
	TRACE("Enter PeekConsoleInputW\n");
	return pPeekConsoleInputW(handle, buffer, count, read);
}

extern WINAPI void wine32a_PeekConsoleInputW(void);
__ASM_GLOBAL_FUNC(wine32a_PeekConsoleInputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PeekConsoleInputW") "\n"
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

extern WINAPI BOOL wine32b_GetNumberOfConsoleInputEvents(HANDLE handle, LPDWORD nrofevents)
{
	TRACE("Enter GetNumberOfConsoleInputEvents\n");
	return pGetNumberOfConsoleInputEvents(handle, nrofevents);
}

extern WINAPI void wine32a_GetNumberOfConsoleInputEvents(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberOfConsoleInputEvents,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberOfConsoleInputEvents") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FlushConsoleInputBuffer(HANDLE handle)
{
	TRACE("Enter FlushConsoleInputBuffer\n");
	return pFlushConsoleInputBuffer(handle);
}

extern WINAPI void wine32a_FlushConsoleInputBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_FlushConsoleInputBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlushConsoleInputBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleTitleA(LPCSTR title)
{
	TRACE("Enter SetConsoleTitleA\n");
	return pSetConsoleTitleA(title);
}

extern WINAPI void wine32a_SetConsoleTitleA(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleTitleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleTitleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleKeyboardLayoutNameA(LPSTR layoutName)
{
	TRACE("Enter GetConsoleKeyboardLayoutNameA\n");
	return pGetConsoleKeyboardLayoutNameA(layoutName);
}

extern WINAPI void wine32a_GetConsoleKeyboardLayoutNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleKeyboardLayoutNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleKeyboardLayoutNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleKeyboardLayoutNameW(LPWSTR layoutName)
{
	TRACE("Enter GetConsoleKeyboardLayoutNameW\n");
	return pGetConsoleKeyboardLayoutNameW(layoutName);
}

extern WINAPI void wine32a_GetConsoleKeyboardLayoutNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleKeyboardLayoutNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleKeyboardLayoutNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleInputExeNameW(DWORD buflen, LPWSTR buffer)
{
	TRACE("Enter GetConsoleInputExeNameW\n");
	return pGetConsoleInputExeNameW(buflen, buffer);
}

extern WINAPI void wine32a_GetConsoleInputExeNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleInputExeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleInputExeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleInputExeNameA(DWORD buflen, LPSTR buffer)
{
	TRACE("Enter GetConsoleInputExeNameA\n");
	return pGetConsoleInputExeNameA(buflen, buffer);
}

extern WINAPI void wine32a_GetConsoleInputExeNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleInputExeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleInputExeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleTitleA(LPSTR title, DWORD size)
{
	TRACE("Enter GetConsoleTitleA\n");
	return pGetConsoleTitleA(title, size);
}

extern WINAPI void wine32a_GetConsoleTitleA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleTitleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleTitleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleTitleW(LPWSTR title, DWORD size)
{
	TRACE("Enter GetConsoleTitleW\n");
	return pGetConsoleTitleW(title, size);
}

extern WINAPI void wine32a_GetConsoleTitleW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleTitleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleTitleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI COORD wine32b_GetLargestConsoleWindowSize(HANDLE hConsoleOutput)
{
	TRACE("Enter GetLargestConsoleWindowSize\n");
	return pGetLargestConsoleWindowSize(hConsoleOutput);
}

extern WINAPI void wine32a_GetLargestConsoleWindowSize(void);
__ASM_GLOBAL_FUNC(wine32a_GetLargestConsoleWindowSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLargestConsoleWindowSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FreeConsole(void)
{
	TRACE("Enter FreeConsole\n");
	return pFreeConsole();
}

extern WINAPI void wine32a_FreeConsole(void);
__ASM_GLOBAL_FUNC(wine32a_FreeConsole,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeConsole") "\n"
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

extern WINAPI BOOL wine32b_AllocConsole(void)
{
	TRACE("Enter AllocConsole\n");
	return pAllocConsole();
}

extern WINAPI void wine32a_AllocConsole(void);
__ASM_GLOBAL_FUNC(wine32a_AllocConsole,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AllocConsole") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleA(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved)
{
	TRACE("Enter ReadConsoleA\n");
	return pReadConsoleA(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved);
}

extern WINAPI void wine32a_ReadConsoleA(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleA") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleW(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved)
{
	TRACE("Enter ReadConsoleW\n");
	return pReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved);
}

extern WINAPI void wine32a_ReadConsoleW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleW") "\n"
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

extern WINAPI BOOL wine32b_ReadConsoleInputW(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead)
{
	TRACE("Enter ReadConsoleInputW\n");
	return pReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead);
}

extern WINAPI void wine32a_ReadConsoleInputW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadConsoleInputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadConsoleInputW") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleOutputCharacterW(HANDLE hConsoleOutput, LPCWSTR str, DWORD length, COORD coord, LPDWORD lpNumCharsWritten)
{
	TRACE("Enter WriteConsoleOutputCharacterW\n");
	return pWriteConsoleOutputCharacterW(hConsoleOutput, str, length, coord, lpNumCharsWritten);
}

extern WINAPI void wine32a_WriteConsoleOutputCharacterW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleOutputCharacterW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleOutputCharacterW") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleTitleW(LPCWSTR title)
{
	TRACE("Enter SetConsoleTitleW\n");
	return pSetConsoleTitleW(title);
}

extern WINAPI void wine32a_SetConsoleTitleW(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleTitleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleTitleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumberOfConsoleMouseButtons(LPDWORD nrofbuttons)
{
	TRACE("Enter GetNumberOfConsoleMouseButtons\n");
	return pGetNumberOfConsoleMouseButtons(nrofbuttons);
}

extern WINAPI void wine32a_GetNumberOfConsoleMouseButtons(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberOfConsoleMouseButtons,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberOfConsoleMouseButtons") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleInputExeNameW(LPCWSTR name)
{
	TRACE("Enter SetConsoleInputExeNameW\n");
	return pSetConsoleInputExeNameW(name);
}

extern WINAPI void wine32a_SetConsoleInputExeNameW(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleInputExeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleInputExeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleInputExeNameA(LPCSTR name)
{
	TRACE("Enter SetConsoleInputExeNameA\n");
	return pSetConsoleInputExeNameA(name);
}

extern WINAPI void wine32a_SetConsoleInputExeNameA(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleInputExeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleInputExeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleCtrlHandler(PHANDLER_ROUTINE func, BOOL add)
{
	TRACE("Enter SetConsoleCtrlHandler\n");
	return pSetConsoleCtrlHandler(func, add);
}

extern WINAPI void wine32a_SetConsoleCtrlHandler(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleCtrlHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleCtrlHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GenerateConsoleCtrlEvent(DWORD dwCtrlEvent, DWORD dwProcessGroupID)
{
	TRACE("Enter GenerateConsoleCtrlEvent\n");
	return pGenerateConsoleCtrlEvent(dwCtrlEvent, dwProcessGroupID);
}

extern WINAPI void wine32a_GenerateConsoleCtrlEvent(void);
__ASM_GLOBAL_FUNC(wine32a_GenerateConsoleCtrlEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GenerateConsoleCtrlEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_CreateConsoleScreenBuffer(DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES sa, DWORD dwFlags, LPVOID lpScreenBufferData)
{
	TRACE("Enter CreateConsoleScreenBuffer\n");
	return pCreateConsoleScreenBuffer(dwDesiredAccess, dwShareMode, sa, dwFlags, lpScreenBufferData);
}

extern WINAPI void wine32a_CreateConsoleScreenBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_CreateConsoleScreenBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateConsoleScreenBuffer") "\n"
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

extern WINAPI BOOL wine32b_GetConsoleScreenBufferInfo(HANDLE hConsoleOutput, LPCONSOLE_SCREEN_BUFFER_INFO csbi)
{
	TRACE("Enter GetConsoleScreenBufferInfo\n");
	return pGetConsoleScreenBufferInfo(hConsoleOutput, csbi);
}

extern WINAPI void wine32a_GetConsoleScreenBufferInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleScreenBufferInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleScreenBufferInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput)
{
	TRACE("Enter SetConsoleActiveScreenBuffer\n");
	return pSetConsoleActiveScreenBuffer(hConsoleOutput);
}

extern WINAPI void wine32a_SetConsoleActiveScreenBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleActiveScreenBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleActiveScreenBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleMode(HANDLE hcon, LPDWORD mode)
{
	TRACE("Enter GetConsoleMode\n");
	return pGetConsoleMode(hcon, mode);
}

extern WINAPI void wine32a_GetConsoleMode(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleMode(HANDLE hcon, DWORD mode)
{
	TRACE("Enter SetConsoleMode\n");
	return pSetConsoleMode(hcon, mode);
}

extern WINAPI void wine32a_SetConsoleMode(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_WriteConsoleW(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
{
	TRACE("Enter WriteConsoleW\n");
	return pWriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
}

extern WINAPI void wine32a_WriteConsoleW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleW") "\n"
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

extern WINAPI BOOL wine32b_WriteConsoleA(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved)
{
	TRACE("Enter WriteConsoleA\n");
	return pWriteConsoleA(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
}

extern WINAPI void wine32a_WriteConsoleA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteConsoleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteConsoleA") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleCursorPosition(HANDLE hcon, COORD pos)
{
	TRACE("Enter SetConsoleCursorPosition\n");
	return pSetConsoleCursorPosition(hcon, pos);
}

extern WINAPI void wine32a_SetConsoleCursorPosition(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleCursorPosition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleCursorPosition") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleCursorInfo(HANDLE hCon, LPCONSOLE_CURSOR_INFO cinfo)
{
	TRACE("Enter GetConsoleCursorInfo\n");
	return pGetConsoleCursorInfo(hCon, cinfo);
}

extern WINAPI void wine32a_GetConsoleCursorInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCursorInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCursorInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleCursorInfo(HANDLE hCon, LPCONSOLE_CURSOR_INFO cinfo)
{
	TRACE("Enter SetConsoleCursorInfo\n");
	return pSetConsoleCursorInfo(hCon, cinfo);
}

extern WINAPI void wine32a_SetConsoleCursorInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleCursorInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleCursorInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleWindowInfo(HANDLE hCon, BOOL bAbsolute, LPSMALL_RECT window)
{
	TRACE("Enter SetConsoleWindowInfo\n");
	return pSetConsoleWindowInfo(hCon, bAbsolute, window);
}

extern WINAPI void wine32a_SetConsoleWindowInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleWindowInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleWindowInfo") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleTextAttribute(HANDLE hConsoleOutput, WORD wAttr)
{
	TRACE("Enter SetConsoleTextAttribute\n");
	return pSetConsoleTextAttribute(hConsoleOutput, wAttr);
}

extern WINAPI void wine32a_SetConsoleTextAttribute(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleTextAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleTextAttribute") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleScreenBufferSize(HANDLE hConsoleOutput, COORD dwSize)
{
	TRACE("Enter SetConsoleScreenBufferSize\n");
	return pSetConsoleScreenBufferSize(hConsoleOutput, dwSize);
}

extern WINAPI void wine32a_SetConsoleScreenBufferSize(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleScreenBufferSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleScreenBufferSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ScrollConsoleScreenBufferA(HANDLE hConsoleOutput, LPSMALL_RECT lpScrollRect, LPSMALL_RECT lpClipRect, COORD dwDestOrigin, LPCHAR_INFO lpFill)
{
	TRACE("Enter ScrollConsoleScreenBufferA\n");
	return pScrollConsoleScreenBufferA(hConsoleOutput, lpScrollRect, lpClipRect, dwDestOrigin, lpFill);
}

extern WINAPI void wine32a_ScrollConsoleScreenBufferA(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollConsoleScreenBufferA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollConsoleScreenBufferA") "\n"
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

extern WINAPI BOOL wine32b_ScrollConsoleScreenBufferW(HANDLE hConsoleOutput, LPSMALL_RECT lpScrollRect, LPSMALL_RECT lpClipRect, COORD dwDestOrigin, LPCHAR_INFO lpFill)
{
	TRACE("Enter ScrollConsoleScreenBufferW\n");
	return pScrollConsoleScreenBufferW(hConsoleOutput, lpScrollRect, lpClipRect, dwDestOrigin, lpFill);
}

extern WINAPI void wine32a_ScrollConsoleScreenBufferW(void);
__ASM_GLOBAL_FUNC(wine32a_ScrollConsoleScreenBufferW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ScrollConsoleScreenBufferW") "\n"
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

extern WINAPI BOOL wine32b_AttachConsole(DWORD dwProcessId)
{
	TRACE("Enter AttachConsole\n");
	return pAttachConsole(dwProcessId);
}

extern WINAPI void wine32a_AttachConsole(void);
__ASM_GLOBAL_FUNC(wine32a_AttachConsole,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AttachConsole") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleDisplayMode(LPDWORD lpModeFlags)
{
	TRACE("Enter GetConsoleDisplayMode\n");
	return pGetConsoleDisplayMode(lpModeFlags);
}

extern WINAPI void wine32a_GetConsoleDisplayMode(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleDisplayMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleDisplayMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleDisplayMode(HANDLE hConsoleOutput, DWORD dwFlags, COORD * lpNewScreenBufferDimensions)
{
	TRACE("Enter SetConsoleDisplayMode\n");
	return pSetConsoleDisplayMode(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
}

extern WINAPI void wine32a_SetConsoleDisplayMode(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleDisplayMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleDisplayMode") "\n"
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

extern WINAPI DWORD wine32b_GetConsoleAliasW(LPWSTR lpSource, LPWSTR lpTargetBuffer, DWORD TargetBufferLength, LPWSTR lpExename)
{
	TRACE("Enter GetConsoleAliasW\n");
	return pGetConsoleAliasW(lpSource, lpTargetBuffer, TargetBufferLength, lpExename);
}

extern WINAPI void wine32a_GetConsoleAliasW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleAliasW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleAliasW") "\n"
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

extern WINAPI DWORD wine32b_GetConsoleProcessList(LPDWORD processlist, DWORD processcount)
{
	TRACE("Enter GetConsoleProcessList\n");
	return pGetConsoleProcessList(processlist, processcount);
}

extern WINAPI void wine32a_GetConsoleProcessList(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleProcessList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleProcessList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleCommandHistoryA(DWORD unknown1, DWORD unknown2, DWORD unknown3)
{
	TRACE("Enter GetConsoleCommandHistoryA\n");
	return pGetConsoleCommandHistoryA(unknown1, unknown2, unknown3);
}

extern WINAPI void wine32a_GetConsoleCommandHistoryA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCommandHistoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCommandHistoryA") "\n"
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

extern WINAPI DWORD wine32b_GetConsoleCommandHistoryW(DWORD unknown1, DWORD unknown2, DWORD unknown3)
{
	TRACE("Enter GetConsoleCommandHistoryW\n");
	return pGetConsoleCommandHistoryW(unknown1, unknown2, unknown3);
}

extern WINAPI void wine32a_GetConsoleCommandHistoryW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCommandHistoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCommandHistoryW") "\n"
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

extern WINAPI DWORD wine32b_GetConsoleCommandHistoryLengthA(LPCSTR unknown)
{
	TRACE("Enter GetConsoleCommandHistoryLengthA\n");
	return pGetConsoleCommandHistoryLengthA(unknown);
}

extern WINAPI void wine32a_GetConsoleCommandHistoryLengthA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCommandHistoryLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCommandHistoryLengthA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleCommandHistoryLengthW(LPCWSTR unknown)
{
	TRACE("Enter GetConsoleCommandHistoryLengthW\n");
	return pGetConsoleCommandHistoryLengthW(unknown);
}

extern WINAPI void wine32a_GetConsoleCommandHistoryLengthW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleCommandHistoryLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleCommandHistoryLengthW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleAliasesLengthA(LPSTR unknown)
{
	TRACE("Enter GetConsoleAliasesLengthA\n");
	return pGetConsoleAliasesLengthA(unknown);
}

extern WINAPI void wine32a_GetConsoleAliasesLengthA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleAliasesLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleAliasesLengthA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleAliasesLengthW(LPWSTR unknown)
{
	TRACE("Enter GetConsoleAliasesLengthW\n");
	return pGetConsoleAliasesLengthW(unknown);
}

extern WINAPI void wine32a_GetConsoleAliasesLengthW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleAliasesLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleAliasesLengthW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetConsoleAliasExesLengthA(void)
{
	TRACE("Enter GetConsoleAliasExesLengthA\n");
	return pGetConsoleAliasExesLengthA();
}

extern WINAPI void wine32a_GetConsoleAliasExesLengthA(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleAliasExesLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleAliasExesLengthA") "\n"
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

extern WINAPI DWORD wine32b_GetConsoleAliasExesLengthW(void)
{
	TRACE("Enter GetConsoleAliasExesLengthW\n");
	return pGetConsoleAliasExesLengthW();
}

extern WINAPI void wine32a_GetConsoleAliasExesLengthW(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleAliasExesLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleAliasExesLengthW") "\n"
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

extern WINAPI void wine32b_ExpungeConsoleCommandHistoryA(LPCSTR unknown)
{
	TRACE("Enter ExpungeConsoleCommandHistoryA\n");
	return pExpungeConsoleCommandHistoryA(unknown);
}

extern WINAPI void wine32a_ExpungeConsoleCommandHistoryA(void);
__ASM_GLOBAL_FUNC(wine32a_ExpungeConsoleCommandHistoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExpungeConsoleCommandHistoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_ExpungeConsoleCommandHistoryW(LPCWSTR unknown)
{
	TRACE("Enter ExpungeConsoleCommandHistoryW\n");
	return pExpungeConsoleCommandHistoryW(unknown);
}

extern WINAPI void wine32a_ExpungeConsoleCommandHistoryW(void);
__ASM_GLOBAL_FUNC(wine32a_ExpungeConsoleCommandHistoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExpungeConsoleCommandHistoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AddConsoleAliasA(LPSTR source, LPSTR target, LPSTR exename)
{
	TRACE("Enter AddConsoleAliasA\n");
	return pAddConsoleAliasA(source, target, exename);
}

extern WINAPI void wine32a_AddConsoleAliasA(void);
__ASM_GLOBAL_FUNC(wine32a_AddConsoleAliasA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddConsoleAliasA") "\n"
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

extern WINAPI BOOL wine32b_AddConsoleAliasW(LPWSTR source, LPWSTR target, LPWSTR exename)
{
	TRACE("Enter AddConsoleAliasW\n");
	return pAddConsoleAliasW(source, target, exename);
}

extern WINAPI void wine32a_AddConsoleAliasW(void);
__ASM_GLOBAL_FUNC(wine32a_AddConsoleAliasW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddConsoleAliasW") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleIcon(HICON icon)
{
	TRACE("Enter SetConsoleIcon\n");
	return pSetConsoleIcon(icon);
}

extern WINAPI void wine32a_SetConsoleIcon(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetNumberOfConsoleFonts(void)
{
	TRACE("Enter GetNumberOfConsoleFonts\n");
	return pGetNumberOfConsoleFonts();
}

extern WINAPI void wine32a_GetNumberOfConsoleFonts(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberOfConsoleFonts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberOfConsoleFonts") "\n"
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

extern WINAPI BOOL wine32b_SetConsoleFont(HANDLE hConsole, DWORD index)
{
	TRACE("Enter SetConsoleFont\n");
	return pSetConsoleFont(hConsole, index);
}

extern WINAPI void wine32a_SetConsoleFont(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleFont,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleFont") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleKeyShortcuts(BOOL set, BYTE keys, void * a, DWORD b)
{
	TRACE("Enter SetConsoleKeyShortcuts\n");
	return pSetConsoleKeyShortcuts(set, keys, a, b);
}

extern WINAPI void wine32a_SetConsoleKeyShortcuts(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleKeyShortcuts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleKeyShortcuts") "\n"
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

extern WINAPI BOOL wine32b_GetCurrentConsoleFont(HANDLE hConsole, BOOL maxwindow, LPCONSOLE_FONT_INFO fontinfo)
{
	TRACE("Enter GetCurrentConsoleFont\n");
	return pGetCurrentConsoleFont(hConsole, maxwindow, fontinfo);
}

extern WINAPI void wine32a_GetCurrentConsoleFont(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentConsoleFont,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentConsoleFont") "\n"
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

extern WINAPI COORD wine32b_GetConsoleFontSize(HANDLE hConsole, DWORD index)
{
	TRACE("Enter GetConsoleFontSize\n");
	return pGetConsoleFontSize(hConsole, index);
}

extern WINAPI void wine32a_GetConsoleFontSize(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleFontSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleFontSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetConsoleFontInfo(HANDLE hConsole, BOOL maximize, DWORD numfonts, CONSOLE_FONT_INFO * info)
{
	TRACE("Enter GetConsoleFontInfo\n");
	return pGetConsoleFontInfo(hConsole, maximize, numfonts, info);
}

extern WINAPI void wine32a_GetConsoleFontInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleFontInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleFontInfo") "\n"
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

extern WINAPI BOOL wine32b_GetConsoleScreenBufferInfoEx(HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFOEX * csbix)
{
	TRACE("Enter GetConsoleScreenBufferInfoEx\n");
	return pGetConsoleScreenBufferInfoEx(hConsole, csbix);
}

extern WINAPI void wine32a_GetConsoleScreenBufferInfoEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetConsoleScreenBufferInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetConsoleScreenBufferInfoEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetConsoleScreenBufferInfoEx(HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFOEX * csbix)
{
	TRACE("Enter SetConsoleScreenBufferInfoEx\n");
	return pSetConsoleScreenBufferInfoEx(hConsole, csbix);
}

extern WINAPI void wine32a_SetConsoleScreenBufferInfoEx(void);
__ASM_GLOBAL_FUNC(wine32a_SetConsoleScreenBufferInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetConsoleScreenBufferInfoEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCurrentConsoleFontEx(HANDLE hConsole, BOOL maxwindow, CONSOLE_FONT_INFOEX * cfix)
{
	TRACE("Enter SetCurrentConsoleFontEx\n");
	return pSetCurrentConsoleFontEx(hConsole, maxwindow, cfix);
}

extern WINAPI void wine32a_SetCurrentConsoleFontEx(void);
__ASM_GLOBAL_FUNC(wine32a_SetCurrentConsoleFontEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCurrentConsoleFontEx") "\n"
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

static WINAPI BOOL (*pQueryPerformanceCounter)(PLARGE_INTEGER counter);
static WINAPI BOOL (*pQueryPerformanceFrequency)(PLARGE_INTEGER frequency);
static WINAPI void (*pGetSystemInfo)(LPSYSTEM_INFO si);
static WINAPI void (*pGetNativeSystemInfo)(LPSYSTEM_INFO si);
static WINAPI BOOL (*pIsProcessorFeaturePresent)(DWORD feature);
static WINAPI BOOL (*pK32GetPerformanceInfo)(PPERFORMANCE_INFORMATION info, DWORD size);
static WINAPI SIZE_T (*pGetLargePageMinimum)(void);
static WINAPI WORD (*pGetActiveProcessorGroupCount)(void);
static WINAPI DWORD (*pGetActiveProcessorCount)(WORD group);
static WINAPI DWORD (*pGetMaximumProcessorCount)(WORD group);
static WINAPI UINT (*pGetSystemFirmwareTable)(DWORD provider, DWORD id, void * buffer, DWORD size);
static WINAPI UINT (*pEnumSystemFirmwareTables)(DWORD provider, void * buffer, DWORD size);

extern WINAPI BOOL wine32b_QueryPerformanceCounter(PLARGE_INTEGER counter)
{
	TRACE("Enter QueryPerformanceCounter\n");
	return pQueryPerformanceCounter(counter);
}

extern WINAPI void wine32a_QueryPerformanceCounter(void);
__ASM_GLOBAL_FUNC(wine32a_QueryPerformanceCounter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryPerformanceCounter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryPerformanceFrequency(PLARGE_INTEGER frequency)
{
	TRACE("Enter QueryPerformanceFrequency\n");
	return pQueryPerformanceFrequency(frequency);
}

extern WINAPI void wine32a_QueryPerformanceFrequency(void);
__ASM_GLOBAL_FUNC(wine32a_QueryPerformanceFrequency,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryPerformanceFrequency") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetSystemInfo(LPSYSTEM_INFO si)
{
	TRACE("Enter GetSystemInfo\n");
	return pGetSystemInfo(si);
}

extern WINAPI void wine32a_GetSystemInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetNativeSystemInfo(LPSYSTEM_INFO si)
{
	TRACE("Enter GetNativeSystemInfo\n");
	return pGetNativeSystemInfo(si);
}

extern WINAPI void wine32a_GetNativeSystemInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetNativeSystemInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNativeSystemInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsProcessorFeaturePresent(DWORD feature)
{
	TRACE("Enter IsProcessorFeaturePresent\n");
	return pIsProcessorFeaturePresent(feature);
}

extern WINAPI void wine32a_IsProcessorFeaturePresent(void);
__ASM_GLOBAL_FUNC(wine32a_IsProcessorFeaturePresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsProcessorFeaturePresent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_K32GetPerformanceInfo(PPERFORMANCE_INFORMATION info, DWORD size)
{
	TRACE("Enter K32GetPerformanceInfo\n");
	return pK32GetPerformanceInfo(info, size);
}

extern WINAPI void wine32a_K32GetPerformanceInfo(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetPerformanceInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetPerformanceInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_GetLargePageMinimum(void)
{
	TRACE("Enter GetLargePageMinimum\n");
	return pGetLargePageMinimum();
}

extern WINAPI void wine32a_GetLargePageMinimum(void);
__ASM_GLOBAL_FUNC(wine32a_GetLargePageMinimum,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLargePageMinimum") "\n"
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

extern WINAPI WORD wine32b_GetActiveProcessorGroupCount(void)
{
	TRACE("Enter GetActiveProcessorGroupCount\n");
	return pGetActiveProcessorGroupCount();
}

extern WINAPI void wine32a_GetActiveProcessorGroupCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetActiveProcessorGroupCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetActiveProcessorGroupCount") "\n"
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

extern WINAPI DWORD wine32b_GetActiveProcessorCount(WORD group)
{
	TRACE("Enter GetActiveProcessorCount\n");
	return pGetActiveProcessorCount(group);
}

extern WINAPI void wine32a_GetActiveProcessorCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetActiveProcessorCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetActiveProcessorCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetMaximumProcessorCount(WORD group)
{
	TRACE("Enter GetMaximumProcessorCount\n");
	return pGetMaximumProcessorCount(group);
}

extern WINAPI void wine32a_GetMaximumProcessorCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetMaximumProcessorCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMaximumProcessorCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetSystemFirmwareTable(DWORD provider, DWORD id, void * buffer, DWORD size)
{
	TRACE("Enter GetSystemFirmwareTable\n");
	return pGetSystemFirmwareTable(provider, id, buffer, size);
}

extern WINAPI void wine32a_GetSystemFirmwareTable(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemFirmwareTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemFirmwareTable") "\n"
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

extern WINAPI UINT wine32b_EnumSystemFirmwareTables(DWORD provider, void * buffer, DWORD size)
{
	TRACE("Enter EnumSystemFirmwareTables\n");
	return pEnumSystemFirmwareTables(provider, buffer, size);
}

extern WINAPI void wine32a_EnumSystemFirmwareTables(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemFirmwareTables,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemFirmwareTables") "\n"
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

static WINAPI BOOL (*pWaitForDebugEvent)(LPDEBUG_EVENT event, DWORD timeout);
static WINAPI BOOL (*pContinueDebugEvent)(DWORD pid, DWORD tid, DWORD status);
static WINAPI BOOL (*pDebugActiveProcess)(DWORD pid);
static WINAPI BOOL (*pDebugActiveProcessStop)(DWORD pid);
static WINAPI void (*pOutputDebugStringA)(LPCSTR str);
static WINAPI void (*pOutputDebugStringW)(LPCWSTR str);
static WINAPI BOOL (*pDebugBreakProcess)(HANDLE process);
static WINAPI BOOL (*pIsDebuggerPresent)(void);
static WINAPI BOOL (*pCheckRemoteDebuggerPresent)(HANDLE process, PBOOL DebuggerPresent);
static WINAPI BOOL (*pDebugSetProcessKillOnExit)(BOOL kill);

extern WINAPI BOOL wine32b_WaitForDebugEvent(LPDEBUG_EVENT event, DWORD timeout)
{
	TRACE("Enter WaitForDebugEvent\n");
	return pWaitForDebugEvent(event, timeout);
}

extern WINAPI void wine32a_WaitForDebugEvent(void);
__ASM_GLOBAL_FUNC(wine32a_WaitForDebugEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WaitForDebugEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ContinueDebugEvent(DWORD pid, DWORD tid, DWORD status)
{
	TRACE("Enter ContinueDebugEvent\n");
	return pContinueDebugEvent(pid, tid, status);
}

extern WINAPI void wine32a_ContinueDebugEvent(void);
__ASM_GLOBAL_FUNC(wine32a_ContinueDebugEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ContinueDebugEvent") "\n"
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

extern WINAPI BOOL wine32b_DebugActiveProcess(DWORD pid)
{
	TRACE("Enter DebugActiveProcess\n");
	return pDebugActiveProcess(pid);
}

extern WINAPI void wine32a_DebugActiveProcess(void);
__ASM_GLOBAL_FUNC(wine32a_DebugActiveProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DebugActiveProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DebugActiveProcessStop(DWORD pid)
{
	TRACE("Enter DebugActiveProcessStop\n");
	return pDebugActiveProcessStop(pid);
}

extern WINAPI void wine32a_DebugActiveProcessStop(void);
__ASM_GLOBAL_FUNC(wine32a_DebugActiveProcessStop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DebugActiveProcessStop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_OutputDebugStringA(LPCSTR str)
{
	TRACE("Enter OutputDebugStringA\n");
	return pOutputDebugStringA(str);
}

extern WINAPI void wine32a_OutputDebugStringA(void);
__ASM_GLOBAL_FUNC(wine32a_OutputDebugStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OutputDebugStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_OutputDebugStringW(LPCWSTR str)
{
	TRACE("Enter OutputDebugStringW\n");
	return pOutputDebugStringW(str);
}

extern WINAPI void wine32a_OutputDebugStringW(void);
__ASM_GLOBAL_FUNC(wine32a_OutputDebugStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OutputDebugStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DebugBreakProcess(HANDLE process)
{
	TRACE("Enter DebugBreakProcess\n");
	return pDebugBreakProcess(process);
}

extern WINAPI void wine32a_DebugBreakProcess(void);
__ASM_GLOBAL_FUNC(wine32a_DebugBreakProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DebugBreakProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsDebuggerPresent(void)
{
	TRACE("Enter IsDebuggerPresent\n");
	return pIsDebuggerPresent();
}

extern WINAPI void wine32a_IsDebuggerPresent(void);
__ASM_GLOBAL_FUNC(wine32a_IsDebuggerPresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDebuggerPresent") "\n"
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

extern WINAPI BOOL wine32b_CheckRemoteDebuggerPresent(HANDLE process, PBOOL DebuggerPresent)
{
	TRACE("Enter CheckRemoteDebuggerPresent\n");
	return pCheckRemoteDebuggerPresent(process, DebuggerPresent);
}

extern WINAPI void wine32a_CheckRemoteDebuggerPresent(void);
__ASM_GLOBAL_FUNC(wine32a_CheckRemoteDebuggerPresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckRemoteDebuggerPresent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DebugSetProcessKillOnExit(BOOL kill)
{
	TRACE("Enter DebugSetProcessKillOnExit\n");
	return pDebugSetProcessKillOnExit(kill);
}

extern WINAPI void wine32a_DebugSetProcessKillOnExit(void);
__ASM_GLOBAL_FUNC(wine32a_DebugSetProcessKillOnExit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DebugSetProcessKillOnExit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)


static WINAPI LPSTR (*pGetCommandLineA)(void);
static WINAPI LPWSTR (*pGetCommandLineW)(void);
static WINAPI LPSTR (*pGetEnvironmentStringsA)(void);
static WINAPI LPWSTR (*pGetEnvironmentStringsW)(void);
static WINAPI BOOL (*pFreeEnvironmentStringsA)(LPSTR ptr);
static WINAPI BOOL (*pFreeEnvironmentStringsW)(LPWSTR ptr);
static WINAPI DWORD (*pGetEnvironmentVariableA)(LPCSTR name, LPSTR value, DWORD size);
static WINAPI DWORD (*pGetEnvironmentVariableW)(LPCWSTR name, LPWSTR val, DWORD size);
static WINAPI BOOL (*pSetEnvironmentVariableA)(LPCSTR name, LPCSTR value);
static WINAPI BOOL (*pSetEnvironmentVariableW)(LPCWSTR name, LPCWSTR value);
static WINAPI DWORD (*pExpandEnvironmentStringsA)(LPCSTR src, LPSTR dst, DWORD count);
static WINAPI DWORD (*pExpandEnvironmentStringsW)(LPCWSTR src, LPWSTR dst, DWORD len);
static WINAPI HANDLE (*pGetStdHandle)(DWORD std_handle);
static WINAPI BOOL (*pSetStdHandle)(DWORD std_handle, HANDLE handle);
static WINAPI void (*pGetStartupInfoA)(LPSTARTUPINFOA info);
static WINAPI void (*pGetStartupInfoW)(LPSTARTUPINFOW info);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableA)(LPCSTR name, LPCSTR guid, PVOID buffer, DWORD size);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableW)(LPCWSTR name, LPCWSTR guid, PVOID buffer, DWORD size);

extern WINAPI LPSTR wine32b_GetCommandLineA(void)
{
	TRACE("Enter GetCommandLineA\n");
	return pGetCommandLineA();
}

extern WINAPI void wine32a_GetCommandLineA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommandLineA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommandLineA") "\n"
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

extern WINAPI LPWSTR wine32b_GetCommandLineW(void)
{
	TRACE("Enter GetCommandLineW\n");
	return pGetCommandLineW();
}

extern WINAPI void wine32a_GetCommandLineW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCommandLineW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCommandLineW") "\n"
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

extern WINAPI LPSTR wine32b_GetEnvironmentStringsA(void)
{
	TRACE("Enter GetEnvironmentStringsA\n");
	return pGetEnvironmentStringsA();
}

extern WINAPI void wine32a_GetEnvironmentStringsA(void);
__ASM_GLOBAL_FUNC(wine32a_GetEnvironmentStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEnvironmentStringsA") "\n"
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

extern WINAPI LPWSTR wine32b_GetEnvironmentStringsW(void)
{
	TRACE("Enter GetEnvironmentStringsW\n");
	return pGetEnvironmentStringsW();
}

extern WINAPI void wine32a_GetEnvironmentStringsW(void);
__ASM_GLOBAL_FUNC(wine32a_GetEnvironmentStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEnvironmentStringsW") "\n"
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

extern WINAPI BOOL wine32b_FreeEnvironmentStringsA(LPSTR ptr)
{
	TRACE("Enter FreeEnvironmentStringsA\n");
	return pFreeEnvironmentStringsA(ptr);
}

extern WINAPI void wine32a_FreeEnvironmentStringsA(void);
__ASM_GLOBAL_FUNC(wine32a_FreeEnvironmentStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeEnvironmentStringsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FreeEnvironmentStringsW(LPWSTR ptr)
{
	TRACE("Enter FreeEnvironmentStringsW\n");
	return pFreeEnvironmentStringsW(ptr);
}

extern WINAPI void wine32a_FreeEnvironmentStringsW(void);
__ASM_GLOBAL_FUNC(wine32a_FreeEnvironmentStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeEnvironmentStringsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetEnvironmentVariableA(LPCSTR name, LPSTR value, DWORD size)
{
	TRACE("Enter GetEnvironmentVariableA\n");
	return pGetEnvironmentVariableA(name, value, size);
}

extern WINAPI void wine32a_GetEnvironmentVariableA(void);
__ASM_GLOBAL_FUNC(wine32a_GetEnvironmentVariableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEnvironmentVariableA") "\n"
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

extern WINAPI DWORD wine32b_GetEnvironmentVariableW(LPCWSTR name, LPWSTR val, DWORD size)
{
	TRACE("Enter GetEnvironmentVariableW\n");
	return pGetEnvironmentVariableW(name, val, size);
}

extern WINAPI void wine32a_GetEnvironmentVariableW(void);
__ASM_GLOBAL_FUNC(wine32a_GetEnvironmentVariableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEnvironmentVariableW") "\n"
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

extern WINAPI BOOL wine32b_SetEnvironmentVariableA(LPCSTR name, LPCSTR value)
{
	TRACE("Enter SetEnvironmentVariableA\n");
	return pSetEnvironmentVariableA(name, value);
}

extern WINAPI void wine32a_SetEnvironmentVariableA(void);
__ASM_GLOBAL_FUNC(wine32a_SetEnvironmentVariableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetEnvironmentVariableA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetEnvironmentVariableW(LPCWSTR name, LPCWSTR value)
{
	TRACE("Enter SetEnvironmentVariableW\n");
	return pSetEnvironmentVariableW(name, value);
}

extern WINAPI void wine32a_SetEnvironmentVariableW(void);
__ASM_GLOBAL_FUNC(wine32a_SetEnvironmentVariableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetEnvironmentVariableW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_ExpandEnvironmentStringsA(LPCSTR src, LPSTR dst, DWORD count)
{
	TRACE("Enter ExpandEnvironmentStringsA\n");
	return pExpandEnvironmentStringsA(src, dst, count);
}

extern WINAPI void wine32a_ExpandEnvironmentStringsA(void);
__ASM_GLOBAL_FUNC(wine32a_ExpandEnvironmentStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExpandEnvironmentStringsA") "\n"
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

extern WINAPI DWORD wine32b_ExpandEnvironmentStringsW(LPCWSTR src, LPWSTR dst, DWORD len)
{
	TRACE("Enter ExpandEnvironmentStringsW\n");
	return pExpandEnvironmentStringsW(src, dst, len);
}

extern WINAPI void wine32a_ExpandEnvironmentStringsW(void);
__ASM_GLOBAL_FUNC(wine32a_ExpandEnvironmentStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExpandEnvironmentStringsW") "\n"
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

extern WINAPI HANDLE wine32b_GetStdHandle(DWORD std_handle)
{
	TRACE("Enter GetStdHandle\n");
	return pGetStdHandle(std_handle);
}

extern WINAPI void wine32a_GetStdHandle(void);
__ASM_GLOBAL_FUNC(wine32a_GetStdHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStdHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetStdHandle(DWORD std_handle, HANDLE handle)
{
	TRACE("Enter SetStdHandle\n");
	return pSetStdHandle(std_handle, handle);
}

extern WINAPI void wine32a_SetStdHandle(void);
__ASM_GLOBAL_FUNC(wine32a_SetStdHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetStdHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetStartupInfoA(LPSTARTUPINFOA info)
{
	TRACE("Enter GetStartupInfoA\n");
	return pGetStartupInfoA(info);
}

extern WINAPI void wine32a_GetStartupInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetStartupInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStartupInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetStartupInfoW(LPSTARTUPINFOW info)
{
	TRACE("Enter GetStartupInfoW\n");
	return pGetStartupInfoW(info);
}

extern WINAPI void wine32a_GetStartupInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetStartupInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStartupInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetFirmwareEnvironmentVariableA(LPCSTR name, LPCSTR guid, PVOID buffer, DWORD size)
{
	TRACE("Enter GetFirmwareEnvironmentVariableA\n");
	return pGetFirmwareEnvironmentVariableA(name, guid, buffer, size);
}

extern WINAPI void wine32a_GetFirmwareEnvironmentVariableA(void);
__ASM_GLOBAL_FUNC(wine32a_GetFirmwareEnvironmentVariableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFirmwareEnvironmentVariableA") "\n"
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

extern WINAPI DWORD wine32b_GetFirmwareEnvironmentVariableW(LPCWSTR name, LPCWSTR guid, PVOID buffer, DWORD size)
{
	TRACE("Enter GetFirmwareEnvironmentVariableW\n");
	return pGetFirmwareEnvironmentVariableW(name, guid, buffer, size);
}

extern WINAPI void wine32a_GetFirmwareEnvironmentVariableW(void);
__ASM_GLOBAL_FUNC(wine32a_GetFirmwareEnvironmentVariableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFirmwareEnvironmentVariableW") "\n"
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

static WINAPI void (*pRaiseException)(DWORD code, DWORD flags, DWORD nbargs, const ULONG_PTR * args);
static WINAPI LONG (*pUnhandledExceptionFilter)(PEXCEPTION_POINTERS epointers);
static WINAPI LPTOP_LEVEL_EXCEPTION_FILTER (*pSetUnhandledExceptionFilter)(LPTOP_LEVEL_EXCEPTION_FILTER filter);
static WINAPI void (*pFatalAppExitA)(UINT action, LPCSTR str);
static WINAPI void (*pFatalAppExitW)(UINT action, LPCWSTR str);
static WINAPI void (*pFatalExit)(int ExitCode);

extern WINAPI void wine32b_RaiseException(DWORD code, DWORD flags, DWORD nbargs, const ULONG_PTR * args)
{
	TRACE("Enter RaiseException\n");
	return pRaiseException(code, flags, nbargs, args);
}

extern WINAPI void wine32a_RaiseException(void);
__ASM_GLOBAL_FUNC(wine32a_RaiseException,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RaiseException") "\n"
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

extern WINAPI LONG wine32b_UnhandledExceptionFilter(PEXCEPTION_POINTERS epointers)
{
	TRACE("Enter UnhandledExceptionFilter\n");
	return pUnhandledExceptionFilter(epointers);
}

extern WINAPI void wine32a_UnhandledExceptionFilter(void);
__ASM_GLOBAL_FUNC(wine32a_UnhandledExceptionFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnhandledExceptionFilter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPTOP_LEVEL_EXCEPTION_FILTER wine32b_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER filter)
{
	TRACE("Enter SetUnhandledExceptionFilter\n");
	return pSetUnhandledExceptionFilter(filter);
}

extern WINAPI void wine32a_SetUnhandledExceptionFilter(void);
__ASM_GLOBAL_FUNC(wine32a_SetUnhandledExceptionFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUnhandledExceptionFilter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_FatalAppExitA(UINT action, LPCSTR str)
{
	TRACE("Enter FatalAppExitA\n");
	return pFatalAppExitA(action, str);
}

extern WINAPI void wine32a_FatalAppExitA(void);
__ASM_GLOBAL_FUNC(wine32a_FatalAppExitA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FatalAppExitA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_FatalAppExitW(UINT action, LPCWSTR str)
{
	TRACE("Enter FatalAppExitW\n");
	return pFatalAppExitW(action, str);
}

extern WINAPI void wine32a_FatalAppExitW(void);
__ASM_GLOBAL_FUNC(wine32a_FatalAppExitW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FatalAppExitW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_FatalExit(int ExitCode)
{
	TRACE("Enter FatalExit\n");
	return pFatalExit(ExitCode);
}

extern WINAPI void wine32a_FatalExit(void);
__ASM_GLOBAL_FUNC(wine32a_FatalExit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FatalExit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI LONG (*p_hread)(HFILE hFile, LPVOID buffer, LONG count);
static WINAPI LONG (*p_hwrite)(HFILE handle, LPCSTR buffer, LONG count);
static WINAPI HFILE (*p_lclose)(HFILE hFile);
static WINAPI HFILE (*p_lcreat)(LPCSTR path, INT attr);
static WINAPI HFILE (*p_lopen)(LPCSTR path, INT mode);
static WINAPI UINT (*p_lread)(HFILE handle, LPVOID buffer, UINT count);
static WINAPI LONG (*p_llseek)(HFILE hFile, LONG lOffset, INT nOrigin);
static WINAPI UINT (*p_lwrite)(HFILE hFile, LPCSTR buffer, UINT count);
static WINAPI BOOL (*pSetFileCompletionNotificationModes)(HANDLE file, UCHAR flags);
static WINAPI UINT (*pSetHandleCount)(UINT count);
static WINAPI BOOL (*pReplaceFileW)(LPCWSTR lpReplacedFileName, LPCWSTR lpReplacementFileName, LPCWSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved);
static WINAPI BOOL (*pReplaceFileA)(LPCSTR lpReplacedFileName, LPCSTR lpReplacementFileName, LPCSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved);
static WINAPI HANDLE (*pFindFirstFileExW)(LPCWSTR filename, FINDEX_INFO_LEVELS level, LPVOID data, FINDEX_SEARCH_OPS search_op, LPVOID filter, DWORD flags);
static WINAPI BOOL (*pFindNextFileW)(HANDLE handle, WIN32_FIND_DATAW * data);
static WINAPI BOOL (*pFindClose)(HANDLE handle);
static WINAPI HANDLE (*pFindFirstFileA)(LPCSTR lpFileName, WIN32_FIND_DATAA * lpFindData);
static WINAPI HANDLE (*pFindFirstFileExA)(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
static WINAPI HANDLE (*pFindFirstFileW)(LPCWSTR lpFileName, WIN32_FIND_DATAW * lpFindData);
static WINAPI BOOL (*pFindNextFileA)(HANDLE handle, WIN32_FIND_DATAA * data);
static WINAPI HANDLE (*pFindFirstStreamW)(LPCWSTR filename, STREAM_INFO_LEVELS infolevel, void * data, DWORD flags);
static WINAPI BOOL (*pFindNextStreamW)(HANDLE handle, void * data);
static WINAPI HANDLE (*pOpenVxDHandle)(HANDLE hHandleRing3);
static WINAPI BOOL (*pDeviceIoControl)(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPOVERLAPPED lpOverlapped);
static WINAPI HFILE (*pOpenFile)(LPCSTR name, OFSTRUCT * ofs, UINT mode);
static WINAPI BOOL (*pK32EnumDeviceDrivers)(void ** image_base, DWORD cb, DWORD * needed);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameA)(void * image_base, LPSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameW)(void * image_base, LPWSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameA)(void * image_base, LPSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameW)(void * image_base, LPWSTR file_name, DWORD size);
static WINAPI DWORD (*pGetFinalPathNameByHandleW)(HANDLE file, LPWSTR path, DWORD charcount, DWORD flags);
static WINAPI DWORD (*pGetFinalPathNameByHandleA)(HANDLE file, LPSTR path, DWORD charcount, DWORD flags);

extern WINAPI LONG wine32b__hread(HFILE hFile, LPVOID buffer, LONG count)
{
	TRACE("Enter _hread\n");
	return p_hread(hFile, buffer, count);
}

extern WINAPI void wine32a__hread(void);
__ASM_GLOBAL_FUNC(wine32a__hread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__hread") "\n"
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

extern WINAPI LONG wine32b__hwrite(HFILE handle, LPCSTR buffer, LONG count)
{
	TRACE("Enter _hwrite\n");
	return p_hwrite(handle, buffer, count);
}

extern WINAPI void wine32a__hwrite(void);
__ASM_GLOBAL_FUNC(wine32a__hwrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__hwrite") "\n"
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

extern WINAPI HFILE wine32b__lclose(HFILE hFile)
{
	TRACE("Enter _lclose\n");
	return p_lclose(hFile);
}

extern WINAPI void wine32a__lclose(void);
__ASM_GLOBAL_FUNC(wine32a__lclose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lclose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b__lcreat(LPCSTR path, INT attr)
{
	TRACE("Enter _lcreat\n");
	return p_lcreat(path, attr);
}

extern WINAPI void wine32a__lcreat(void);
__ASM_GLOBAL_FUNC(wine32a__lcreat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lcreat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b__lopen(LPCSTR path, INT mode)
{
	TRACE("Enter _lopen\n");
	return p_lopen(path, mode);
}

extern WINAPI void wine32a__lopen(void);
__ASM_GLOBAL_FUNC(wine32a__lopen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lopen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b__lread(HFILE handle, LPVOID buffer, UINT count)
{
	TRACE("Enter _lread\n");
	return p_lread(handle, buffer, count);
}

extern WINAPI void wine32a__lread(void);
__ASM_GLOBAL_FUNC(wine32a__lread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lread") "\n"
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

extern WINAPI LONG wine32b__llseek(HFILE hFile, LONG lOffset, INT nOrigin)
{
	TRACE("Enter _llseek\n");
	return p_llseek(hFile, lOffset, nOrigin);
}

extern WINAPI void wine32a__llseek(void);
__ASM_GLOBAL_FUNC(wine32a__llseek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__llseek") "\n"
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

extern WINAPI UINT wine32b__lwrite(HFILE hFile, LPCSTR buffer, UINT count)
{
	TRACE("Enter _lwrite\n");
	return p_lwrite(hFile, buffer, count);
}

extern WINAPI void wine32a__lwrite(void);
__ASM_GLOBAL_FUNC(wine32a__lwrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__lwrite") "\n"
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

extern WINAPI BOOL wine32b_SetFileCompletionNotificationModes(HANDLE file, UCHAR flags)
{
	TRACE("Enter SetFileCompletionNotificationModes\n");
	return pSetFileCompletionNotificationModes(file, flags);
}

extern WINAPI void wine32a_SetFileCompletionNotificationModes(void);
__ASM_GLOBAL_FUNC(wine32a_SetFileCompletionNotificationModes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetFileCompletionNotificationModes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_SetHandleCount(UINT count)
{
	TRACE("Enter SetHandleCount\n");
	return pSetHandleCount(count);
}

extern WINAPI void wine32a_SetHandleCount(void);
__ASM_GLOBAL_FUNC(wine32a_SetHandleCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetHandleCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ReplaceFileW(LPCWSTR lpReplacedFileName, LPCWSTR lpReplacementFileName, LPCWSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved)
{
	TRACE("Enter ReplaceFileW\n");
	return pReplaceFileW(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
}

extern WINAPI void wine32a_ReplaceFileW(void);
__ASM_GLOBAL_FUNC(wine32a_ReplaceFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReplaceFileW") "\n"
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

extern WINAPI BOOL wine32b_ReplaceFileA(LPCSTR lpReplacedFileName, LPCSTR lpReplacementFileName, LPCSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved)
{
	TRACE("Enter ReplaceFileA\n");
	return pReplaceFileA(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
}

extern WINAPI void wine32a_ReplaceFileA(void);
__ASM_GLOBAL_FUNC(wine32a_ReplaceFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReplaceFileA") "\n"
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

extern WINAPI HANDLE wine32b_FindFirstFileExW(LPCWSTR filename, FINDEX_INFO_LEVELS level, LPVOID data, FINDEX_SEARCH_OPS search_op, LPVOID filter, DWORD flags)
{
	TRACE("Enter FindFirstFileExW\n");
	return pFindFirstFileExW(filename, level, data, search_op, filter, flags);
}

extern WINAPI void wine32a_FindFirstFileExW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstFileExW") "\n"
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

extern WINAPI BOOL wine32b_FindNextFileW(HANDLE handle, WIN32_FIND_DATAW * data)
{
	TRACE("Enter FindNextFileW\n");
	return pFindNextFileW(handle, data);
}

extern WINAPI void wine32a_FindNextFileW(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FindClose(HANDLE handle)
{
	TRACE("Enter FindClose\n");
	return pFindClose(handle);
}

extern WINAPI void wine32a_FindClose(void);
__ASM_GLOBAL_FUNC(wine32a_FindClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_FindFirstFileA(LPCSTR lpFileName, WIN32_FIND_DATAA * lpFindData)
{
	TRACE("Enter FindFirstFileA\n");
	return pFindFirstFileA(lpFileName, lpFindData);
}

extern WINAPI void wine32a_FindFirstFileA(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_FindFirstFileExA(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags)
{
	TRACE("Enter FindFirstFileExA\n");
	return pFindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags);
}

extern WINAPI void wine32a_FindFirstFileExA(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstFileExA") "\n"
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

extern WINAPI HANDLE wine32b_FindFirstFileW(LPCWSTR lpFileName, WIN32_FIND_DATAW * lpFindData)
{
	TRACE("Enter FindFirstFileW\n");
	return pFindFirstFileW(lpFileName, lpFindData);
}

extern WINAPI void wine32a_FindFirstFileW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FindNextFileA(HANDLE handle, WIN32_FIND_DATAA * data)
{
	TRACE("Enter FindNextFileA\n");
	return pFindNextFileA(handle, data);
}

extern WINAPI void wine32a_FindNextFileA(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_FindFirstStreamW(LPCWSTR filename, STREAM_INFO_LEVELS infolevel, void * data, DWORD flags)
{
	TRACE("Enter FindFirstStreamW\n");
	return pFindFirstStreamW(filename, infolevel, data, flags);
}

extern WINAPI void wine32a_FindFirstStreamW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstStreamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstStreamW") "\n"
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

extern WINAPI BOOL wine32b_FindNextStreamW(HANDLE handle, void * data)
{
	TRACE("Enter FindNextStreamW\n");
	return pFindNextStreamW(handle, data);
}

extern WINAPI void wine32a_FindNextStreamW(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextStreamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextStreamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenVxDHandle(HANDLE hHandleRing3)
{
	TRACE("Enter OpenVxDHandle\n");
	return pOpenVxDHandle(hHandleRing3);
}

extern WINAPI void wine32a_OpenVxDHandle(void);
__ASM_GLOBAL_FUNC(wine32a_OpenVxDHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenVxDHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPOVERLAPPED lpOverlapped)
{
	TRACE("Enter DeviceIoControl\n");
	return pDeviceIoControl(hDevice, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped);
}

extern WINAPI void wine32a_DeviceIoControl(void);
__ASM_GLOBAL_FUNC(wine32a_DeviceIoControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeviceIoControl") "\n"
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

extern WINAPI HFILE wine32b_OpenFile(LPCSTR name, OFSTRUCT * ofs, UINT mode)
{
	TRACE("Enter OpenFile\n");
	return pOpenFile(name, ofs, mode);
}

extern WINAPI void wine32a_OpenFile(void);
__ASM_GLOBAL_FUNC(wine32a_OpenFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenFile") "\n"
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

extern WINAPI BOOL wine32b_K32EnumDeviceDrivers(void ** image_base, DWORD cb, DWORD * needed)
{
	TRACE("Enter K32EnumDeviceDrivers\n");
	return pK32EnumDeviceDrivers(image_base, cb, needed);
}

extern WINAPI void wine32a_K32EnumDeviceDrivers(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumDeviceDrivers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumDeviceDrivers") "\n"
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

extern WINAPI DWORD wine32b_K32GetDeviceDriverBaseNameA(void * image_base, LPSTR base_name, DWORD size)
{
	TRACE("Enter K32GetDeviceDriverBaseNameA\n");
	return pK32GetDeviceDriverBaseNameA(image_base, base_name, size);
}

extern WINAPI void wine32a_K32GetDeviceDriverBaseNameA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetDeviceDriverBaseNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetDeviceDriverBaseNameA") "\n"
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

extern WINAPI DWORD wine32b_K32GetDeviceDriverBaseNameW(void * image_base, LPWSTR base_name, DWORD size)
{
	TRACE("Enter K32GetDeviceDriverBaseNameW\n");
	return pK32GetDeviceDriverBaseNameW(image_base, base_name, size);
}

extern WINAPI void wine32a_K32GetDeviceDriverBaseNameW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetDeviceDriverBaseNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetDeviceDriverBaseNameW") "\n"
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

extern WINAPI DWORD wine32b_K32GetDeviceDriverFileNameA(void * image_base, LPSTR file_name, DWORD size)
{
	TRACE("Enter K32GetDeviceDriverFileNameA\n");
	return pK32GetDeviceDriverFileNameA(image_base, file_name, size);
}

extern WINAPI void wine32a_K32GetDeviceDriverFileNameA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetDeviceDriverFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetDeviceDriverFileNameA") "\n"
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

extern WINAPI DWORD wine32b_K32GetDeviceDriverFileNameW(void * image_base, LPWSTR file_name, DWORD size)
{
	TRACE("Enter K32GetDeviceDriverFileNameW\n");
	return pK32GetDeviceDriverFileNameW(image_base, file_name, size);
}

extern WINAPI void wine32a_K32GetDeviceDriverFileNameW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetDeviceDriverFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetDeviceDriverFileNameW") "\n"
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

extern WINAPI DWORD wine32b_GetFinalPathNameByHandleW(HANDLE file, LPWSTR path, DWORD charcount, DWORD flags)
{
	TRACE("Enter GetFinalPathNameByHandleW\n");
	return pGetFinalPathNameByHandleW(file, path, charcount, flags);
}

extern WINAPI void wine32a_GetFinalPathNameByHandleW(void);
__ASM_GLOBAL_FUNC(wine32a_GetFinalPathNameByHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFinalPathNameByHandleW") "\n"
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

extern WINAPI DWORD wine32b_GetFinalPathNameByHandleA(HANDLE file, LPSTR path, DWORD charcount, DWORD flags)
{
	TRACE("Enter GetFinalPathNameByHandleA\n");
	return pGetFinalPathNameByHandleA(file, path, charcount, flags);
}

extern WINAPI void wine32a_GetFinalPathNameByHandleA(void);
__ASM_GLOBAL_FUNC(wine32a_GetFinalPathNameByHandleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFinalPathNameByHandleA") "\n"
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

static WINAPI DWORD (*pFormatMessageA)(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, __builtin_ms_va_list * args);
static WINAPI DWORD (*pFormatMessageW)(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, __builtin_ms_va_list * args);

extern WINAPI DWORD wine32b_FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, __builtin_ms_va_list * args)
{
	TRACE("Enter FormatMessageA\n");
	return pFormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
}

extern WINAPI void wine32a_FormatMessageA(void);
__ASM_GLOBAL_FUNC(wine32a_FormatMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FormatMessageA") "\n"
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

extern WINAPI DWORD wine32b_FormatMessageW(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, __builtin_ms_va_list * args)
{
	TRACE("Enter FormatMessageW\n");
	return pFormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
}

extern WINAPI void wine32a_FormatMessageW(void);
__ASM_GLOBAL_FUNC(wine32a_FormatMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FormatMessageW") "\n"
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

static WINAPI HANDLE (*pHeapCreate)(DWORD flags, SIZE_T initialSize, SIZE_T maxSize);
static WINAPI BOOL (*pHeapDestroy)(HANDLE heap);
static WINAPI SIZE_T (*pHeapCompact)(HANDLE heap, DWORD flags);
static WINAPI BOOL (*pHeapValidate)(HANDLE heap, DWORD flags, LPCVOID block);
static WINAPI BOOL (*pHeapWalk)(HANDLE heap, LPPROCESS_HEAP_ENTRY entry);
static WINAPI BOOL (*pHeapLock)(HANDLE heap);
static WINAPI BOOL (*pHeapUnlock)(HANDLE heap);
static WINAPI LPVOID (*pHeapAlloc)(HANDLE heap, DWORD flags, SIZE_T size);
static WINAPI BOOL (*pHeapFree)(HANDLE heap, DWORD flags, LPVOID ptr);
static WINAPI LPVOID (*pHeapReAlloc)(HANDLE heap, DWORD flags, LPVOID ptr, SIZE_T size);
static WINAPI SIZE_T (*pHeapSize)(HANDLE heap, DWORD flags, LPCVOID ptr);
static WINAPI BOOL (*pHeapQueryInformation)(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size_in, PSIZE_T size_out);
static WINAPI BOOL (*pHeapSetInformation)(HANDLE heap, HEAP_INFORMATION_CLASS infoclass, PVOID info, SIZE_T size);
static WINAPI HGLOBAL (*pGlobalAlloc)(UINT flags, SIZE_T size);
static WINAPI LPVOID (*pGlobalLock)(HGLOBAL hmem);
static WINAPI BOOL (*pGlobalUnlock)(HGLOBAL hmem);
static WINAPI HGLOBAL (*pGlobalHandle)(LPCVOID pmem);
static WINAPI HGLOBAL (*pGlobalReAlloc)(HGLOBAL hmem, SIZE_T size, UINT flags);
static WINAPI HGLOBAL (*pGlobalFree)(HGLOBAL hmem);
static WINAPI SIZE_T (*pGlobalSize)(HGLOBAL hmem);
static WINAPI LPVOID (*pGlobalWire)(HGLOBAL hmem);
static WINAPI BOOL (*pGlobalUnWire)(HGLOBAL hmem);
static WINAPI void (*pGlobalFix)(HGLOBAL hmem);
static WINAPI void (*pGlobalUnfix)(HGLOBAL hmem);
static WINAPI UINT (*pGlobalFlags)(HGLOBAL hmem);
static WINAPI SIZE_T (*pGlobalCompact)(DWORD minfree);
static WINAPI HLOCAL (*pLocalAlloc)(UINT flags, SIZE_T size);
static WINAPI SIZE_T (*pLocalCompact)(UINT minfree);
static WINAPI UINT (*pLocalFlags)(HLOCAL handle);
static WINAPI HLOCAL (*pLocalFree)(HLOCAL handle);
static WINAPI HLOCAL (*pLocalHandle)(LPCVOID ptr);
static WINAPI LPVOID (*pLocalLock)(HLOCAL handle);
static WINAPI HLOCAL (*pLocalReAlloc)(HLOCAL handle, SIZE_T size, UINT flags);
static WINAPI SIZE_T (*pLocalShrink)(HGLOBAL handle, UINT newsize);
static WINAPI SIZE_T (*pLocalSize)(HLOCAL handle);
static WINAPI BOOL (*pLocalUnlock)(HLOCAL handle);
static WINAPI BOOL (*pGlobalMemoryStatusEx)(LPMEMORYSTATUSEX lpmemex);
static WINAPI void (*pGlobalMemoryStatus)(LPMEMORYSTATUS lpBuffer);
static WINAPI BOOL (*pGetPhysicallyInstalledSystemMemory)(ULONGLONG * total_memory);
static WINAPI BOOL (*pGetSystemFileCacheSize)(PSIZE_T mincache, PSIZE_T maxcache, PDWORD flags);
static WINAPI BOOL (*pSetSystemFileCacheSize)(SIZE_T mincache, SIZE_T maxcache, DWORD flags);
static WINAPI BOOL (*pAllocateUserPhysicalPages)(HANDLE process, ULONG_PTR * pages, ULONG_PTR * userarray);
static WINAPI BOOL (*pFreeUserPhysicalPages)(HANDLE process, ULONG_PTR * pages, ULONG_PTR * userarray);
static WINAPI BOOL (*pMapUserPhysicalPages)(PVOID addr, ULONG_PTR page_count, PULONG_PTR pages);

extern WINAPI HANDLE wine32b_HeapCreate(DWORD flags, SIZE_T initialSize, SIZE_T maxSize)
{
	TRACE("Enter HeapCreate\n");
	return pHeapCreate(flags, initialSize, maxSize);
}

extern WINAPI void wine32a_HeapCreate(void);
__ASM_GLOBAL_FUNC(wine32a_HeapCreate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapCreate") "\n"
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

extern WINAPI BOOL wine32b_HeapDestroy(HANDLE heap)
{
	TRACE("Enter HeapDestroy\n");
	return pHeapDestroy(heap);
}

extern WINAPI void wine32a_HeapDestroy(void);
__ASM_GLOBAL_FUNC(wine32a_HeapDestroy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapDestroy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_HeapCompact(HANDLE heap, DWORD flags)
{
	TRACE("Enter HeapCompact\n");
	return pHeapCompact(heap, flags);
}

extern WINAPI void wine32a_HeapCompact(void);
__ASM_GLOBAL_FUNC(wine32a_HeapCompact,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapCompact") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_HeapValidate(HANDLE heap, DWORD flags, LPCVOID block)
{
	TRACE("Enter HeapValidate\n");
	return pHeapValidate(heap, flags, block);
}

extern WINAPI void wine32a_HeapValidate(void);
__ASM_GLOBAL_FUNC(wine32a_HeapValidate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapValidate") "\n"
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

extern WINAPI BOOL wine32b_HeapWalk(HANDLE heap, LPPROCESS_HEAP_ENTRY entry)
{
	TRACE("Enter HeapWalk\n");
	return pHeapWalk(heap, entry);
}

extern WINAPI void wine32a_HeapWalk(void);
__ASM_GLOBAL_FUNC(wine32a_HeapWalk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapWalk") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_HeapLock(HANDLE heap)
{
	TRACE("Enter HeapLock\n");
	return pHeapLock(heap);
}

extern WINAPI void wine32a_HeapLock(void);
__ASM_GLOBAL_FUNC(wine32a_HeapLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_HeapUnlock(HANDLE heap)
{
	TRACE("Enter HeapUnlock\n");
	return pHeapUnlock(heap);
}

extern WINAPI void wine32a_HeapUnlock(void);
__ASM_GLOBAL_FUNC(wine32a_HeapUnlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapUnlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_HeapAlloc(HANDLE heap, DWORD flags, SIZE_T size)
{
	TRACE("Enter HeapAlloc\n");
	return pHeapAlloc(heap, flags, size);
}

extern WINAPI void wine32a_HeapAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_HeapAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapAlloc") "\n"
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

extern WINAPI BOOL wine32b_HeapFree(HANDLE heap, DWORD flags, LPVOID ptr)
{
	TRACE("Enter HeapFree\n");
	return pHeapFree(heap, flags, ptr);
}

extern WINAPI void wine32a_HeapFree(void);
__ASM_GLOBAL_FUNC(wine32a_HeapFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapFree") "\n"
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

extern WINAPI LPVOID wine32b_HeapReAlloc(HANDLE heap, DWORD flags, LPVOID ptr, SIZE_T size)
{
	TRACE("Enter HeapReAlloc\n");
	return pHeapReAlloc(heap, flags, ptr, size);
}

extern WINAPI void wine32a_HeapReAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_HeapReAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapReAlloc") "\n"
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

extern WINAPI SIZE_T wine32b_HeapSize(HANDLE heap, DWORD flags, LPCVOID ptr)
{
	TRACE("Enter HeapSize\n");
	return pHeapSize(heap, flags, ptr);
}

extern WINAPI void wine32a_HeapSize(void);
__ASM_GLOBAL_FUNC(wine32a_HeapSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapSize") "\n"
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

extern WINAPI BOOL wine32b_HeapQueryInformation(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size_in, PSIZE_T size_out)
{
	TRACE("Enter HeapQueryInformation\n");
	return pHeapQueryInformation(heap, info_class, info, size_in, size_out);
}

extern WINAPI void wine32a_HeapQueryInformation(void);
__ASM_GLOBAL_FUNC(wine32a_HeapQueryInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapQueryInformation") "\n"
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

extern WINAPI BOOL wine32b_HeapSetInformation(HANDLE heap, HEAP_INFORMATION_CLASS infoclass, PVOID info, SIZE_T size)
{
	TRACE("Enter HeapSetInformation\n");
	return pHeapSetInformation(heap, infoclass, info, size);
}

extern WINAPI void wine32a_HeapSetInformation(void);
__ASM_GLOBAL_FUNC(wine32a_HeapSetInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_HeapSetInformation") "\n"
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

extern WINAPI HGLOBAL wine32b_GlobalAlloc(UINT flags, SIZE_T size)
{
	TRACE("Enter GlobalAlloc\n");
	return pGlobalAlloc(flags, size);
}

extern WINAPI void wine32a_GlobalAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalAlloc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_GlobalLock(HGLOBAL hmem)
{
	TRACE("Enter GlobalLock\n");
	return pGlobalLock(hmem);
}

extern WINAPI void wine32a_GlobalLock(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GlobalUnlock(HGLOBAL hmem)
{
	TRACE("Enter GlobalUnlock\n");
	return pGlobalUnlock(hmem);
}

extern WINAPI void wine32a_GlobalUnlock(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalUnlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalUnlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HGLOBAL wine32b_GlobalHandle(LPCVOID pmem)
{
	TRACE("Enter GlobalHandle\n");
	return pGlobalHandle(pmem);
}

extern WINAPI void wine32a_GlobalHandle(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HGLOBAL wine32b_GlobalReAlloc(HGLOBAL hmem, SIZE_T size, UINT flags)
{
	TRACE("Enter GlobalReAlloc\n");
	return pGlobalReAlloc(hmem, size, flags);
}

extern WINAPI void wine32a_GlobalReAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalReAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalReAlloc") "\n"
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

extern WINAPI HGLOBAL wine32b_GlobalFree(HGLOBAL hmem)
{
	TRACE("Enter GlobalFree\n");
	return pGlobalFree(hmem);
}

extern WINAPI void wine32a_GlobalFree(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_GlobalSize(HGLOBAL hmem)
{
	TRACE("Enter GlobalSize\n");
	return pGlobalSize(hmem);
}

extern WINAPI void wine32a_GlobalSize(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_GlobalWire(HGLOBAL hmem)
{
	TRACE("Enter GlobalWire\n");
	return pGlobalWire(hmem);
}

extern WINAPI void wine32a_GlobalWire(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalWire,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalWire") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GlobalUnWire(HGLOBAL hmem)
{
	TRACE("Enter GlobalUnWire\n");
	return pGlobalUnWire(hmem);
}

extern WINAPI void wine32a_GlobalUnWire(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalUnWire,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalUnWire") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GlobalFix(HGLOBAL hmem)
{
	TRACE("Enter GlobalFix\n");
	return pGlobalFix(hmem);
}

extern WINAPI void wine32a_GlobalFix(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalFix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalFix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GlobalUnfix(HGLOBAL hmem)
{
	TRACE("Enter GlobalUnfix\n");
	return pGlobalUnfix(hmem);
}

extern WINAPI void wine32a_GlobalUnfix(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalUnfix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalUnfix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GlobalFlags(HGLOBAL hmem)
{
	TRACE("Enter GlobalFlags\n");
	return pGlobalFlags(hmem);
}

extern WINAPI void wine32a_GlobalFlags(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_GlobalCompact(DWORD minfree)
{
	TRACE("Enter GlobalCompact\n");
	return pGlobalCompact(minfree);
}

extern WINAPI void wine32a_GlobalCompact(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalCompact,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalCompact") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HLOCAL wine32b_LocalAlloc(UINT flags, SIZE_T size)
{
	TRACE("Enter LocalAlloc\n");
	return pLocalAlloc(flags, size);
}

extern WINAPI void wine32a_LocalAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_LocalAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalAlloc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_LocalCompact(UINT minfree)
{
	TRACE("Enter LocalCompact\n");
	return pLocalCompact(minfree);
}

extern WINAPI void wine32a_LocalCompact(void);
__ASM_GLOBAL_FUNC(wine32a_LocalCompact,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalCompact") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_LocalFlags(HLOCAL handle)
{
	TRACE("Enter LocalFlags\n");
	return pLocalFlags(handle);
}

extern WINAPI void wine32a_LocalFlags(void);
__ASM_GLOBAL_FUNC(wine32a_LocalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HLOCAL wine32b_LocalFree(HLOCAL handle)
{
	TRACE("Enter LocalFree\n");
	return pLocalFree(handle);
}

extern WINAPI void wine32a_LocalFree(void);
__ASM_GLOBAL_FUNC(wine32a_LocalFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HLOCAL wine32b_LocalHandle(LPCVOID ptr)
{
	TRACE("Enter LocalHandle\n");
	return pLocalHandle(ptr);
}

extern WINAPI void wine32a_LocalHandle(void);
__ASM_GLOBAL_FUNC(wine32a_LocalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_LocalLock(HLOCAL handle)
{
	TRACE("Enter LocalLock\n");
	return pLocalLock(handle);
}

extern WINAPI void wine32a_LocalLock(void);
__ASM_GLOBAL_FUNC(wine32a_LocalLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HLOCAL wine32b_LocalReAlloc(HLOCAL handle, SIZE_T size, UINT flags)
{
	TRACE("Enter LocalReAlloc\n");
	return pLocalReAlloc(handle, size, flags);
}

extern WINAPI void wine32a_LocalReAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_LocalReAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalReAlloc") "\n"
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

extern WINAPI SIZE_T wine32b_LocalShrink(HGLOBAL handle, UINT newsize)
{
	TRACE("Enter LocalShrink\n");
	return pLocalShrink(handle, newsize);
}

extern WINAPI void wine32a_LocalShrink(void);
__ASM_GLOBAL_FUNC(wine32a_LocalShrink,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalShrink") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_LocalSize(HLOCAL handle)
{
	TRACE("Enter LocalSize\n");
	return pLocalSize(handle);
}

extern WINAPI void wine32a_LocalSize(void);
__ASM_GLOBAL_FUNC(wine32a_LocalSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_LocalUnlock(HLOCAL handle)
{
	TRACE("Enter LocalUnlock\n");
	return pLocalUnlock(handle);
}

extern WINAPI void wine32a_LocalUnlock(void);
__ASM_GLOBAL_FUNC(wine32a_LocalUnlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalUnlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpmemex)
{
	TRACE("Enter GlobalMemoryStatusEx\n");
	return pGlobalMemoryStatusEx(lpmemex);
}

extern WINAPI void wine32a_GlobalMemoryStatusEx(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalMemoryStatusEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalMemoryStatusEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer)
{
	TRACE("Enter GlobalMemoryStatus\n");
	return pGlobalMemoryStatus(lpBuffer);
}

extern WINAPI void wine32a_GlobalMemoryStatus(void);
__ASM_GLOBAL_FUNC(wine32a_GlobalMemoryStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GlobalMemoryStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetPhysicallyInstalledSystemMemory(ULONGLONG * total_memory)
{
	TRACE("Enter GetPhysicallyInstalledSystemMemory\n");
	return pGetPhysicallyInstalledSystemMemory(total_memory);
}

extern WINAPI void wine32a_GetPhysicallyInstalledSystemMemory(void);
__ASM_GLOBAL_FUNC(wine32a_GetPhysicallyInstalledSystemMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPhysicallyInstalledSystemMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetSystemFileCacheSize(PSIZE_T mincache, PSIZE_T maxcache, PDWORD flags)
{
	TRACE("Enter GetSystemFileCacheSize\n");
	return pGetSystemFileCacheSize(mincache, maxcache, flags);
}

extern WINAPI void wine32a_GetSystemFileCacheSize(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemFileCacheSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemFileCacheSize") "\n"
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

extern WINAPI BOOL wine32b_SetSystemFileCacheSize(SIZE_T mincache, SIZE_T maxcache, DWORD flags)
{
	TRACE("Enter SetSystemFileCacheSize\n");
	return pSetSystemFileCacheSize(mincache, maxcache, flags);
}

extern WINAPI void wine32a_SetSystemFileCacheSize(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemFileCacheSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemFileCacheSize") "\n"
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

extern WINAPI BOOL wine32b_AllocateUserPhysicalPages(HANDLE process, ULONG_PTR * pages, ULONG_PTR * userarray)
{
	TRACE("Enter AllocateUserPhysicalPages\n");
	return pAllocateUserPhysicalPages(process, pages, userarray);
}

extern WINAPI void wine32a_AllocateUserPhysicalPages(void);
__ASM_GLOBAL_FUNC(wine32a_AllocateUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AllocateUserPhysicalPages") "\n"
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

extern WINAPI BOOL wine32b_FreeUserPhysicalPages(HANDLE process, ULONG_PTR * pages, ULONG_PTR * userarray)
{
	TRACE("Enter FreeUserPhysicalPages\n");
	return pFreeUserPhysicalPages(process, pages, userarray);
}

extern WINAPI void wine32a_FreeUserPhysicalPages(void);
__ASM_GLOBAL_FUNC(wine32a_FreeUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeUserPhysicalPages") "\n"
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

extern WINAPI BOOL wine32b_MapUserPhysicalPages(PVOID addr, ULONG_PTR page_count, PULONG_PTR pages)
{
	TRACE("Enter MapUserPhysicalPages\n");
	return pMapUserPhysicalPages(addr, page_count, pages);
}

extern WINAPI void wine32a_MapUserPhysicalPages(void);
__ASM_GLOBAL_FUNC(wine32a_MapUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapUserPhysicalPages") "\n"
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

static WINAPI INT (*pMulDiv)(INT nMultiplicand, INT nMultiplier, INT nDivisor);
static WINAPI BOOL (*pGetSystemRegistryQuota)(PDWORD pdwQuotaAllowed, PDWORD pdwQuotaUsed);

extern WINAPI INT wine32b_MulDiv(INT nMultiplicand, INT nMultiplier, INT nDivisor)
{
	TRACE("Enter MulDiv\n");
	return pMulDiv(nMultiplicand, nMultiplier, nDivisor);
}

extern WINAPI void wine32a_MulDiv(void);
__ASM_GLOBAL_FUNC(wine32a_MulDiv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MulDiv") "\n"
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

extern WINAPI BOOL wine32b_GetSystemRegistryQuota(PDWORD pdwQuotaAllowed, PDWORD pdwQuotaUsed)
{
	TRACE("Enter GetSystemRegistryQuota\n");
	return pGetSystemRegistryQuota(pdwQuotaAllowed, pdwQuotaUsed);
}

extern WINAPI void wine32a_GetSystemRegistryQuota(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemRegistryQuota,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemRegistryQuota") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI INT (*pGetDateFormatA)(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCSTR lpFormat, LPSTR lpDateStr, INT cchOut);
static WINAPI INT (*pGetDateFormatEx)(LPCWSTR localename, DWORD flags, const SYSTEMTIME * date, LPCWSTR format, LPWSTR outbuf, INT bufsize, LPCWSTR calendar);
static WINAPI INT (*pGetDateFormatW)(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCWSTR lpFormat, LPWSTR lpDateStr, INT cchOut);
static WINAPI INT (*pGetTimeFormatA)(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, INT cchOut);
static WINAPI INT (*pGetTimeFormatEx)(LPCWSTR localename, DWORD flags, const SYSTEMTIME * time, LPCWSTR format, LPWSTR outbuf, INT bufsize);
static WINAPI INT (*pGetTimeFormatW)(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, INT cchOut);
static WINAPI INT (*pGetNumberFormatA)(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, const NUMBERFMTA * lpFormat, LPSTR lpNumberStr, int cchOut);
static WINAPI INT (*pGetNumberFormatW)(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, const NUMBERFMTW * lpFormat, LPWSTR lpNumberStr, int cchOut);
static WINAPI INT (*pGetNumberFormatEx)(LPCWSTR name, DWORD flags, LPCWSTR value, const NUMBERFMTW * format, LPWSTR number, int numout);
static WINAPI INT (*pGetCurrencyFormatA)(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, const CURRENCYFMTA * lpFormat, LPSTR lpCurrencyStr, int cchOut);
static WINAPI INT (*pGetCurrencyFormatW)(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, const CURRENCYFMTW * lpFormat, LPWSTR lpCurrencyStr, int cchOut);
static WINAPI INT (*pGetCurrencyFormatEx)(LPCWSTR localename, DWORD flags, LPCWSTR value, const CURRENCYFMTW * format, LPWSTR str, int len);
static WINAPI BOOL (*pEnumDateFormatsExA)(DATEFMT_ENUMPROCEXA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsExW)(DATEFMT_ENUMPROCEXW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsA)(DATEFMT_ENUMPROCA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsW)(DATEFMT_ENUMPROCW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsExEx)(DATEFMT_ENUMPROCEXEX proc, const WCHAR * locale, DWORD flags, LPARAM lParam);
static WINAPI BOOL (*pEnumTimeFormatsA)(TIMEFMT_ENUMPROCA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumTimeFormatsW)(TIMEFMT_ENUMPROCW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumTimeFormatsEx)(TIMEFMT_ENUMPROCEX proc, const WCHAR * locale, DWORD flags, LPARAM lParam);
static WINAPI BOOL (*pEnumCalendarInfoA)(CALINFO_ENUMPROCA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoW)(CALINFO_ENUMPROCW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoExA)(CALINFO_ENUMPROCEXA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoExW)(CALINFO_ENUMPROCEXW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoExEx)(CALINFO_ENUMPROCEXEX calinfoproc, LPCWSTR locale, CALID calendar, LPCWSTR reserved, CALTYPE caltype, LPARAM lParam);

extern WINAPI INT wine32b_GetDateFormatA(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCSTR lpFormat, LPSTR lpDateStr, INT cchOut)
{
	TRACE("Enter GetDateFormatA\n");
	return pGetDateFormatA(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
}

extern WINAPI void wine32a_GetDateFormatA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDateFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDateFormatA") "\n"
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

extern WINAPI INT wine32b_GetDateFormatEx(LPCWSTR localename, DWORD flags, const SYSTEMTIME * date, LPCWSTR format, LPWSTR outbuf, INT bufsize, LPCWSTR calendar)
{
	TRACE("Enter GetDateFormatEx\n");
	return pGetDateFormatEx(localename, flags, date, format, outbuf, bufsize, calendar);
}

extern WINAPI void wine32a_GetDateFormatEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetDateFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDateFormatEx") "\n"
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

extern WINAPI INT wine32b_GetDateFormatW(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCWSTR lpFormat, LPWSTR lpDateStr, INT cchOut)
{
	TRACE("Enter GetDateFormatW\n");
	return pGetDateFormatW(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
}

extern WINAPI void wine32a_GetDateFormatW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDateFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDateFormatW") "\n"
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

extern WINAPI INT wine32b_GetTimeFormatA(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, INT cchOut)
{
	TRACE("Enter GetTimeFormatA\n");
	return pGetTimeFormatA(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
}

extern WINAPI void wine32a_GetTimeFormatA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTimeFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTimeFormatA") "\n"
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

extern WINAPI INT wine32b_GetTimeFormatEx(LPCWSTR localename, DWORD flags, const SYSTEMTIME * time, LPCWSTR format, LPWSTR outbuf, INT bufsize)
{
	TRACE("Enter GetTimeFormatEx\n");
	return pGetTimeFormatEx(localename, flags, time, format, outbuf, bufsize);
}

extern WINAPI void wine32a_GetTimeFormatEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetTimeFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTimeFormatEx") "\n"
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

extern WINAPI INT wine32b_GetTimeFormatW(LCID lcid, DWORD dwFlags, const SYSTEMTIME * lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, INT cchOut)
{
	TRACE("Enter GetTimeFormatW\n");
	return pGetTimeFormatW(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
}

extern WINAPI void wine32a_GetTimeFormatW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTimeFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTimeFormatW") "\n"
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

extern WINAPI INT wine32b_GetNumberFormatA(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, const NUMBERFMTA * lpFormat, LPSTR lpNumberStr, int cchOut)
{
	TRACE("Enter GetNumberFormatA\n");
	return pGetNumberFormatA(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
}

extern WINAPI void wine32a_GetNumberFormatA(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberFormatA") "\n"
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

extern WINAPI INT wine32b_GetNumberFormatW(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, const NUMBERFMTW * lpFormat, LPWSTR lpNumberStr, int cchOut)
{
	TRACE("Enter GetNumberFormatW\n");
	return pGetNumberFormatW(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
}

extern WINAPI void wine32a_GetNumberFormatW(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberFormatW") "\n"
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

extern WINAPI INT wine32b_GetNumberFormatEx(LPCWSTR name, DWORD flags, LPCWSTR value, const NUMBERFMTW * format, LPWSTR number, int numout)
{
	TRACE("Enter GetNumberFormatEx\n");
	return pGetNumberFormatEx(name, flags, value, format, number, numout);
}

extern WINAPI void wine32a_GetNumberFormatEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberFormatEx") "\n"
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

extern WINAPI INT wine32b_GetCurrencyFormatA(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, const CURRENCYFMTA * lpFormat, LPSTR lpCurrencyStr, int cchOut)
{
	TRACE("Enter GetCurrencyFormatA\n");
	return pGetCurrencyFormatA(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
}

extern WINAPI void wine32a_GetCurrencyFormatA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrencyFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrencyFormatA") "\n"
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

extern WINAPI INT wine32b_GetCurrencyFormatW(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, const CURRENCYFMTW * lpFormat, LPWSTR lpCurrencyStr, int cchOut)
{
	TRACE("Enter GetCurrencyFormatW\n");
	return pGetCurrencyFormatW(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
}

extern WINAPI void wine32a_GetCurrencyFormatW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrencyFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrencyFormatW") "\n"
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

extern WINAPI INT wine32b_GetCurrencyFormatEx(LPCWSTR localename, DWORD flags, LPCWSTR value, const CURRENCYFMTW * format, LPWSTR str, int len)
{
	TRACE("Enter GetCurrencyFormatEx\n");
	return pGetCurrencyFormatEx(localename, flags, value, format, str, len);
}

extern WINAPI void wine32a_GetCurrencyFormatEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrencyFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrencyFormatEx") "\n"
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

extern WINAPI BOOL wine32b_EnumDateFormatsExA(DATEFMT_ENUMPROCEXA proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumDateFormatsExA\n");
	return pEnumDateFormatsExA(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumDateFormatsExA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDateFormatsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDateFormatsExA") "\n"
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

extern WINAPI BOOL wine32b_EnumDateFormatsExW(DATEFMT_ENUMPROCEXW proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumDateFormatsExW\n");
	return pEnumDateFormatsExW(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumDateFormatsExW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDateFormatsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDateFormatsExW") "\n"
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

extern WINAPI BOOL wine32b_EnumDateFormatsA(DATEFMT_ENUMPROCA proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumDateFormatsA\n");
	return pEnumDateFormatsA(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumDateFormatsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDateFormatsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDateFormatsA") "\n"
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

extern WINAPI BOOL wine32b_EnumDateFormatsW(DATEFMT_ENUMPROCW proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumDateFormatsW\n");
	return pEnumDateFormatsW(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumDateFormatsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDateFormatsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDateFormatsW") "\n"
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

extern WINAPI BOOL wine32b_EnumDateFormatsExEx(DATEFMT_ENUMPROCEXEX proc, const WCHAR * locale, DWORD flags, LPARAM lParam)
{
	TRACE("Enter EnumDateFormatsExEx\n");
	return pEnumDateFormatsExEx(proc, locale, flags, lParam);
}

extern WINAPI void wine32a_EnumDateFormatsExEx(void);
__ASM_GLOBAL_FUNC(wine32a_EnumDateFormatsExEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumDateFormatsExEx") "\n"
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

extern WINAPI BOOL wine32b_EnumTimeFormatsA(TIMEFMT_ENUMPROCA proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumTimeFormatsA\n");
	return pEnumTimeFormatsA(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumTimeFormatsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumTimeFormatsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumTimeFormatsA") "\n"
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

extern WINAPI BOOL wine32b_EnumTimeFormatsW(TIMEFMT_ENUMPROCW proc, LCID lcid, DWORD flags)
{
	TRACE("Enter EnumTimeFormatsW\n");
	return pEnumTimeFormatsW(proc, lcid, flags);
}

extern WINAPI void wine32a_EnumTimeFormatsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumTimeFormatsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumTimeFormatsW") "\n"
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

extern WINAPI BOOL wine32b_EnumTimeFormatsEx(TIMEFMT_ENUMPROCEX proc, const WCHAR * locale, DWORD flags, LPARAM lParam)
{
	TRACE("Enter EnumTimeFormatsEx\n");
	return pEnumTimeFormatsEx(proc, locale, flags, lParam);
}

extern WINAPI void wine32a_EnumTimeFormatsEx(void);
__ASM_GLOBAL_FUNC(wine32a_EnumTimeFormatsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumTimeFormatsEx") "\n"
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

extern WINAPI BOOL wine32b_EnumCalendarInfoA(CALINFO_ENUMPROCA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype)
{
	TRACE("Enter EnumCalendarInfoA\n");
	return pEnumCalendarInfoA(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_EnumCalendarInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumCalendarInfoA") "\n"
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

extern WINAPI BOOL wine32b_EnumCalendarInfoW(CALINFO_ENUMPROCW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype)
{
	TRACE("Enter EnumCalendarInfoW\n");
	return pEnumCalendarInfoW(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_EnumCalendarInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumCalendarInfoW") "\n"
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

extern WINAPI BOOL wine32b_EnumCalendarInfoExA(CALINFO_ENUMPROCEXA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype)
{
	TRACE("Enter EnumCalendarInfoExA\n");
	return pEnumCalendarInfoExA(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_EnumCalendarInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumCalendarInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumCalendarInfoExA") "\n"
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

extern WINAPI BOOL wine32b_EnumCalendarInfoExW(CALINFO_ENUMPROCEXW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype)
{
	TRACE("Enter EnumCalendarInfoExW\n");
	return pEnumCalendarInfoExW(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_EnumCalendarInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumCalendarInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumCalendarInfoExW") "\n"
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

extern WINAPI BOOL wine32b_EnumCalendarInfoExEx(CALINFO_ENUMPROCEXEX calinfoproc, LPCWSTR locale, CALID calendar, LPCWSTR reserved, CALTYPE caltype, LPARAM lParam)
{
	TRACE("Enter EnumCalendarInfoExEx\n");
	return pEnumCalendarInfoExEx(calinfoproc, locale, calendar, reserved, caltype, lParam);
}

extern WINAPI void wine32a_EnumCalendarInfoExEx(void);
__ASM_GLOBAL_FUNC(wine32a_EnumCalendarInfoExEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumCalendarInfoExEx") "\n"
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

static WINAPI LANGID (*pGetUserDefaultLangID)(void);
static WINAPI LANGID (*pGetSystemDefaultLangID)(void);
static WINAPI LCID (*pGetUserDefaultLCID)(void);
static WINAPI LCID (*pGetSystemDefaultLCID)(void);
static WINAPI INT (*pGetSystemDefaultLocaleName)(LPWSTR localename, INT len);
static WINAPI BOOL (*pGetProcessPreferredUILanguages)(DWORD flags, ULONG * count, WCHAR * buf, ULONG * size);
static WINAPI BOOL (*pGetSystemPreferredUILanguages)(DWORD flags, ULONG * count, WCHAR * buffer, ULONG * size);
static WINAPI BOOL (*pSetProcessPreferredUILanguages)(DWORD flags, PCZZWSTR buffer, PULONG count);
static WINAPI BOOL (*pSetThreadPreferredUILanguages)(DWORD flags, PCZZWSTR buffer, PULONG count);
static WINAPI BOOL (*pGetThreadPreferredUILanguages)(DWORD flags, ULONG * count, WCHAR * buf, ULONG * size);
static WINAPI BOOL (*pGetUserPreferredUILanguages)(DWORD flags, ULONG * count, WCHAR * buffer, ULONG * size);
static WINAPI LANGID (*pGetUserDefaultUILanguage)(void);
static WINAPI LANGID (*pGetSystemDefaultUILanguage)(void);
static WINAPI LCID (*pLocaleNameToLCID)(LPCWSTR name, DWORD flags);
static WINAPI INT (*pLCIDToLocaleName)(LCID lcid, LPWSTR name, INT count, DWORD flags);
static WINAPI INT (*pGetLocaleInfoA)(LCID lcid, LCTYPE lctype, LPSTR buffer, INT len);
static WINAPI INT (*pGetLocaleInfoW)(LCID lcid, LCTYPE lctype, LPWSTR buffer, INT len);
static WINAPI INT (*pGetLocaleInfoEx)(LPCWSTR locale, LCTYPE info, LPWSTR buffer, INT len);
static WINAPI BOOL (*pSetLocaleInfoA)(LCID lcid, LCTYPE lctype, LPCSTR data);
static WINAPI BOOL (*pSetLocaleInfoW)(LCID lcid, LCTYPE lctype, LPCWSTR data);
static WINAPI UINT (*pGetACP)(void);
static WINAPI UINT (*pSetCPGlobal)(UINT acp);
static WINAPI UINT (*pGetOEMCP)(void);
static WINAPI BOOL (*pIsValidCodePage)(UINT codepage);
static WINAPI BOOL (*pIsDBCSLeadByteEx)(UINT codepage, BYTE testchar);
static WINAPI BOOL (*pIsDBCSLeadByte)(BYTE testchar);
static WINAPI BOOL (*pGetCPInfo)(UINT codepage, LPCPINFO cpinfo);
static WINAPI BOOL (*pGetCPInfoExA)(UINT codepage, DWORD dwFlags, LPCPINFOEXA cpinfo);
static WINAPI BOOL (*pGetCPInfoExW)(UINT codepage, DWORD dwFlags, LPCPINFOEXW cpinfo);
static WINAPI BOOL (*pEnumSystemCodePagesA)(CODEPAGE_ENUMPROCA lpfnCodePageEnum, DWORD flags);
static WINAPI BOOL (*pEnumSystemCodePagesW)(CODEPAGE_ENUMPROCW lpfnCodePageEnum, DWORD flags);
static WINAPI INT (*pMultiByteToWideChar)(UINT page, DWORD flags, LPCSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI INT (*pWideCharToMultiByte)(UINT page, DWORD flags, LPCWSTR src, INT srclen, LPSTR dst, INT dstlen, LPCSTR defchar, BOOL * used);
static WINAPI LCID (*pGetThreadLocale)(void);
static WINAPI BOOL (*pSetThreadLocale)(LCID lcid);
static WINAPI LANGID (*pSetThreadUILanguage)(LANGID langid);
static WINAPI LCID (*pConvertDefaultLocale)(LCID lcid);
static WINAPI BOOL (*pIsValidLocale)(LCID lcid, DWORD flags);
static WINAPI BOOL (*pIsValidLocaleName)(LPCWSTR locale);
static WINAPI BOOL (*pEnumSystemLocalesA)(LOCALE_ENUMPROCA lpfnLocaleEnum, DWORD dwFlags);
static WINAPI BOOL (*pEnumSystemLocalesW)(LOCALE_ENUMPROCW lpfnLocaleEnum, DWORD dwFlags);
static WINAPI BOOL (*pEnumSystemLocalesEx)(LOCALE_ENUMPROCEX proc, DWORD flags, LPARAM lparam, LPVOID reserved);
static WINAPI DWORD (*pVerLanguageNameA)(DWORD wLang, LPSTR szLang, DWORD nSize);
static WINAPI DWORD (*pVerLanguageNameW)(DWORD wLang, LPWSTR szLang, DWORD nSize);
static WINAPI BOOL (*pGetStringTypeW)(DWORD type, LPCWSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeExW)(LCID locale, DWORD type, LPCWSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeA)(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeExA)(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype);
static WINAPI INT (*pLCMapStringEx)(LPCWSTR name, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lparam);
static WINAPI INT (*pLCMapStringW)(LCID lcid, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI INT (*pLCMapStringA)(LCID lcid, DWORD flags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen);
static WINAPI INT (*pFoldStringA)(DWORD dwFlags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen);
static WINAPI INT (*pFoldStringW)(DWORD dwFlags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI INT (*pCompareStringW)(LCID lcid, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2);
static WINAPI INT (*pCompareStringEx)(LPCWSTR locale, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lParam);
static WINAPI INT (*pCompareStringA)(LCID lcid, DWORD flags, LPCSTR str1, INT len1, LPCSTR str2, INT len2);
static WINAPI INT (*pCompareStringOrdinal)(const WCHAR * str1, INT len1, const WCHAR * str2, INT len2, BOOL ignore_case);
static WINAPI BOOL (*pEnumSystemLanguageGroupsA)(LANGUAGEGROUP_ENUMPROCA pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumSystemLanguageGroupsW)(LANGUAGEGROUP_ENUMPROCW pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pIsValidLanguageGroup)(LGRPID lgrpid, DWORD dwFlags);
static WINAPI BOOL (*pEnumLanguageGroupLocalesA)(LANGGROUPLOCALE_ENUMPROCA pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumLanguageGroupLocalesW)(LANGGROUPLOCALE_ENUMPROCW pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pInvalidateNLSCache)(void);
static WINAPI GEOID (*pGetUserGeoID)(GEOCLASS GeoClass);
static WINAPI BOOL (*pSetUserGeoID)(GEOID GeoID);
static WINAPI BOOL (*pEnumUILanguagesA)(UILANGUAGE_ENUMPROCA pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumUILanguagesW)(UILANGUAGE_ENUMPROCW pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI INT (*pGetGeoInfoW)(GEOID geoid, GEOTYPE geotype, LPWSTR data, int data_len, LANGID lang);
static WINAPI INT (*pGetGeoInfoA)(GEOID geoid, GEOTYPE geotype, LPSTR data, int data_len, LANGID lang);
static WINAPI BOOL (*pEnumSystemGeoID)(GEOCLASS geoclass, GEOID parent, GEO_ENUMPROC enumproc);
static WINAPI INT (*pGetUserDefaultLocaleName)(LPWSTR localename, int buffersize);
static WINAPI INT (*pNormalizeString)(NORM_FORM form, const WCHAR * src, INT src_len, WCHAR * dst, INT dst_len);
static WINAPI BOOL (*pIsNormalizedString)(NORM_FORM NormForm, LPCWSTR lpString, INT cwLength);
static WINAPI INT (*pIdnToAscii)(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpASCIICharStr, INT cchASCIIChar);
static WINAPI INT (*pIdnToNameprepUnicode)(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpNameprepCharStr, INT cchNameprepChar);
static WINAPI INT (*pIdnToUnicode)(DWORD dwFlags, LPCWSTR lpASCIICharStr, INT cchASCIIChar, LPWSTR lpUnicodeCharStr, INT cchUnicodeChar);
static WINAPI BOOL (*pGetFileMUIPath)(DWORD flags, PCWSTR filepath, PWSTR language, PULONG languagelen, PWSTR muipath, PULONG muipathlen, PULONGLONG enumerator);
static WINAPI BOOL (*pGetFileMUIInfo)(DWORD flags, PCWSTR path, FILEMUIINFO * info, DWORD * size);
static WINAPI INT (*pResolveLocaleName)(LPCWSTR name, LPWSTR localename, INT len);
static WINAPI INT (*pFindNLSStringEx)(const WCHAR * localename, DWORD flags, const WCHAR * src, INT src_size, const WCHAR * value, INT value_size, INT * found, NLSVERSIONINFO * version_info, void * reserved, LPARAM sort_handle);
static WINAPI INT (*pFindStringOrdinal)(DWORD flag, const WCHAR * src, INT src_size, const WCHAR * val, INT val_size, BOOL ignore_case);

extern WINAPI LANGID wine32b_GetUserDefaultLangID(void)
{
	TRACE("Enter GetUserDefaultLangID\n");
	return pGetUserDefaultLangID();
}

extern WINAPI void wine32a_GetUserDefaultLangID(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserDefaultLangID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserDefaultLangID") "\n"
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

extern WINAPI LANGID wine32b_GetSystemDefaultLangID(void)
{
	TRACE("Enter GetSystemDefaultLangID\n");
	return pGetSystemDefaultLangID();
}

extern WINAPI void wine32a_GetSystemDefaultLangID(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDefaultLangID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDefaultLangID") "\n"
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

extern WINAPI LCID wine32b_GetUserDefaultLCID(void)
{
	TRACE("Enter GetUserDefaultLCID\n");
	return pGetUserDefaultLCID();
}

extern WINAPI void wine32a_GetUserDefaultLCID(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserDefaultLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserDefaultLCID") "\n"
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

extern WINAPI LCID wine32b_GetSystemDefaultLCID(void)
{
	TRACE("Enter GetSystemDefaultLCID\n");
	return pGetSystemDefaultLCID();
}

extern WINAPI void wine32a_GetSystemDefaultLCID(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDefaultLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDefaultLCID") "\n"
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

extern WINAPI INT wine32b_GetSystemDefaultLocaleName(LPWSTR localename, INT len)
{
	TRACE("Enter GetSystemDefaultLocaleName\n");
	return pGetSystemDefaultLocaleName(localename, len);
}

extern WINAPI void wine32a_GetSystemDefaultLocaleName(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDefaultLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDefaultLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessPreferredUILanguages(DWORD flags, ULONG * count, WCHAR * buf, ULONG * size)
{
	TRACE("Enter GetProcessPreferredUILanguages\n");
	return pGetProcessPreferredUILanguages(flags, count, buf, size);
}

extern WINAPI void wine32a_GetProcessPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessPreferredUILanguages") "\n"
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

extern WINAPI BOOL wine32b_GetSystemPreferredUILanguages(DWORD flags, ULONG * count, WCHAR * buffer, ULONG * size)
{
	TRACE("Enter GetSystemPreferredUILanguages\n");
	return pGetSystemPreferredUILanguages(flags, count, buffer, size);
}

extern WINAPI void wine32a_GetSystemPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemPreferredUILanguages") "\n"
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

extern WINAPI BOOL wine32b_SetProcessPreferredUILanguages(DWORD flags, PCZZWSTR buffer, PULONG count)
{
	TRACE("Enter SetProcessPreferredUILanguages\n");
	return pSetProcessPreferredUILanguages(flags, buffer, count);
}

extern WINAPI void wine32a_SetProcessPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessPreferredUILanguages") "\n"
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

extern WINAPI BOOL wine32b_SetThreadPreferredUILanguages(DWORD flags, PCZZWSTR buffer, PULONG count)
{
	TRACE("Enter SetThreadPreferredUILanguages\n");
	return pSetThreadPreferredUILanguages(flags, buffer, count);
}

extern WINAPI void wine32a_SetThreadPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadPreferredUILanguages") "\n"
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

extern WINAPI BOOL wine32b_GetThreadPreferredUILanguages(DWORD flags, ULONG * count, WCHAR * buf, ULONG * size)
{
	TRACE("Enter GetThreadPreferredUILanguages\n");
	return pGetThreadPreferredUILanguages(flags, count, buf, size);
}

extern WINAPI void wine32a_GetThreadPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_GetThreadPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetThreadPreferredUILanguages") "\n"
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

extern WINAPI BOOL wine32b_GetUserPreferredUILanguages(DWORD flags, ULONG * count, WCHAR * buffer, ULONG * size)
{
	TRACE("Enter GetUserPreferredUILanguages\n");
	return pGetUserPreferredUILanguages(flags, count, buffer, size);
}

extern WINAPI void wine32a_GetUserPreferredUILanguages(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserPreferredUILanguages") "\n"
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

extern WINAPI LANGID wine32b_GetUserDefaultUILanguage(void)
{
	TRACE("Enter GetUserDefaultUILanguage\n");
	return pGetUserDefaultUILanguage();
}

extern WINAPI void wine32a_GetUserDefaultUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserDefaultUILanguage") "\n"
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

extern WINAPI LANGID wine32b_GetSystemDefaultUILanguage(void)
{
	TRACE("Enter GetSystemDefaultUILanguage\n");
	return pGetSystemDefaultUILanguage();
}

extern WINAPI void wine32a_GetSystemDefaultUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDefaultUILanguage") "\n"
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

extern WINAPI LCID wine32b_LocaleNameToLCID(LPCWSTR name, DWORD flags)
{
	TRACE("Enter LocaleNameToLCID\n");
	return pLocaleNameToLCID(name, flags);
}

extern WINAPI void wine32a_LocaleNameToLCID(void);
__ASM_GLOBAL_FUNC(wine32a_LocaleNameToLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocaleNameToLCID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_LCIDToLocaleName(LCID lcid, LPWSTR name, INT count, DWORD flags)
{
	TRACE("Enter LCIDToLocaleName\n");
	return pLCIDToLocaleName(lcid, name, count, flags);
}

extern WINAPI void wine32a_LCIDToLocaleName(void);
__ASM_GLOBAL_FUNC(wine32a_LCIDToLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LCIDToLocaleName") "\n"
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

extern WINAPI INT wine32b_GetLocaleInfoA(LCID lcid, LCTYPE lctype, LPSTR buffer, INT len)
{
	TRACE("Enter GetLocaleInfoA\n");
	return pGetLocaleInfoA(lcid, lctype, buffer, len);
}

extern WINAPI void wine32a_GetLocaleInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetLocaleInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLocaleInfoA") "\n"
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

extern WINAPI INT wine32b_GetLocaleInfoW(LCID lcid, LCTYPE lctype, LPWSTR buffer, INT len)
{
	TRACE("Enter GetLocaleInfoW\n");
	return pGetLocaleInfoW(lcid, lctype, buffer, len);
}

extern WINAPI void wine32a_GetLocaleInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetLocaleInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLocaleInfoW") "\n"
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

extern WINAPI INT wine32b_GetLocaleInfoEx(LPCWSTR locale, LCTYPE info, LPWSTR buffer, INT len)
{
	TRACE("Enter GetLocaleInfoEx\n");
	return pGetLocaleInfoEx(locale, info, buffer, len);
}

extern WINAPI void wine32a_GetLocaleInfoEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetLocaleInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLocaleInfoEx") "\n"
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

extern WINAPI BOOL wine32b_SetLocaleInfoA(LCID lcid, LCTYPE lctype, LPCSTR data)
{
	TRACE("Enter SetLocaleInfoA\n");
	return pSetLocaleInfoA(lcid, lctype, data);
}

extern WINAPI void wine32a_SetLocaleInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SetLocaleInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLocaleInfoA") "\n"
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

extern WINAPI BOOL wine32b_SetLocaleInfoW(LCID lcid, LCTYPE lctype, LPCWSTR data)
{
	TRACE("Enter SetLocaleInfoW\n");
	return pSetLocaleInfoW(lcid, lctype, data);
}

extern WINAPI void wine32a_SetLocaleInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SetLocaleInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLocaleInfoW") "\n"
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

extern WINAPI UINT wine32b_GetACP(void)
{
	TRACE("Enter GetACP\n");
	return pGetACP();
}

extern WINAPI void wine32a_GetACP(void);
__ASM_GLOBAL_FUNC(wine32a_GetACP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetACP") "\n"
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

extern WINAPI UINT wine32b_SetCPGlobal(UINT acp)
{
	TRACE("Enter SetCPGlobal\n");
	return pSetCPGlobal(acp);
}

extern WINAPI void wine32a_SetCPGlobal(void);
__ASM_GLOBAL_FUNC(wine32a_SetCPGlobal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCPGlobal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetOEMCP(void)
{
	TRACE("Enter GetOEMCP\n");
	return pGetOEMCP();
}

extern WINAPI void wine32a_GetOEMCP(void);
__ASM_GLOBAL_FUNC(wine32a_GetOEMCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetOEMCP") "\n"
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

extern WINAPI BOOL wine32b_IsValidCodePage(UINT codepage)
{
	TRACE("Enter IsValidCodePage\n");
	return pIsValidCodePage(codepage);
}

extern WINAPI void wine32a_IsValidCodePage(void);
__ASM_GLOBAL_FUNC(wine32a_IsValidCodePage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsValidCodePage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsDBCSLeadByteEx(UINT codepage, BYTE testchar)
{
	TRACE("Enter IsDBCSLeadByteEx\n");
	return pIsDBCSLeadByteEx(codepage, testchar);
}

extern WINAPI void wine32a_IsDBCSLeadByteEx(void);
__ASM_GLOBAL_FUNC(wine32a_IsDBCSLeadByteEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDBCSLeadByteEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsDBCSLeadByte(BYTE testchar)
{
	TRACE("Enter IsDBCSLeadByte\n");
	return pIsDBCSLeadByte(testchar);
}

extern WINAPI void wine32a_IsDBCSLeadByte(void);
__ASM_GLOBAL_FUNC(wine32a_IsDBCSLeadByte,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsDBCSLeadByte") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCPInfo(UINT codepage, LPCPINFO cpinfo)
{
	TRACE("Enter GetCPInfo\n");
	return pGetCPInfo(codepage, cpinfo);
}

extern WINAPI void wine32a_GetCPInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetCPInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCPInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCPInfoExA(UINT codepage, DWORD dwFlags, LPCPINFOEXA cpinfo)
{
	TRACE("Enter GetCPInfoExA\n");
	return pGetCPInfoExA(codepage, dwFlags, cpinfo);
}

extern WINAPI void wine32a_GetCPInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCPInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCPInfoExA") "\n"
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

extern WINAPI BOOL wine32b_GetCPInfoExW(UINT codepage, DWORD dwFlags, LPCPINFOEXW cpinfo)
{
	TRACE("Enter GetCPInfoExW\n");
	return pGetCPInfoExW(codepage, dwFlags, cpinfo);
}

extern WINAPI void wine32a_GetCPInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCPInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCPInfoExW") "\n"
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

extern WINAPI BOOL wine32b_EnumSystemCodePagesA(CODEPAGE_ENUMPROCA lpfnCodePageEnum, DWORD flags)
{
	TRACE("Enter EnumSystemCodePagesA\n");
	return pEnumSystemCodePagesA(lpfnCodePageEnum, flags);
}

extern WINAPI void wine32a_EnumSystemCodePagesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemCodePagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemCodePagesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumSystemCodePagesW(CODEPAGE_ENUMPROCW lpfnCodePageEnum, DWORD flags)
{
	TRACE("Enter EnumSystemCodePagesW\n");
	return pEnumSystemCodePagesW(lpfnCodePageEnum, flags);
}

extern WINAPI void wine32a_EnumSystemCodePagesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemCodePagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemCodePagesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_MultiByteToWideChar(UINT page, DWORD flags, LPCSTR src, INT srclen, LPWSTR dst, INT dstlen)
{
	TRACE("Enter MultiByteToWideChar\n");
	return pMultiByteToWideChar(page, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_MultiByteToWideChar(void);
__ASM_GLOBAL_FUNC(wine32a_MultiByteToWideChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MultiByteToWideChar") "\n"
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

extern WINAPI INT wine32b_WideCharToMultiByte(UINT page, DWORD flags, LPCWSTR src, INT srclen, LPSTR dst, INT dstlen, LPCSTR defchar, BOOL * used)
{
	TRACE("Enter WideCharToMultiByte\n");
	return pWideCharToMultiByte(page, flags, src, srclen, dst, dstlen, defchar, used);
}

extern WINAPI void wine32a_WideCharToMultiByte(void);
__ASM_GLOBAL_FUNC(wine32a_WideCharToMultiByte,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WideCharToMultiByte") "\n"
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

extern WINAPI LCID wine32b_GetThreadLocale(void)
{
	TRACE("Enter GetThreadLocale\n");
	return pGetThreadLocale();
}

extern WINAPI void wine32a_GetThreadLocale(void);
__ASM_GLOBAL_FUNC(wine32a_GetThreadLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetThreadLocale") "\n"
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

extern WINAPI BOOL wine32b_SetThreadLocale(LCID lcid)
{
	TRACE("Enter SetThreadLocale\n");
	return pSetThreadLocale(lcid);
}

extern WINAPI void wine32a_SetThreadLocale(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LANGID wine32b_SetThreadUILanguage(LANGID langid)
{
	TRACE("Enter SetThreadUILanguage\n");
	return pSetThreadUILanguage(langid);
}

extern WINAPI void wine32a_SetThreadUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_ConvertDefaultLocale(LCID lcid)
{
	TRACE("Enter ConvertDefaultLocale\n");
	return pConvertDefaultLocale(lcid);
}

extern WINAPI void wine32a_ConvertDefaultLocale(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsValidLocale(LCID lcid, DWORD flags)
{
	TRACE("Enter IsValidLocale\n");
	return pIsValidLocale(lcid, flags);
}

extern WINAPI void wine32a_IsValidLocale(void);
__ASM_GLOBAL_FUNC(wine32a_IsValidLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsValidLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsValidLocaleName(LPCWSTR locale)
{
	TRACE("Enter IsValidLocaleName\n");
	return pIsValidLocaleName(locale);
}

extern WINAPI void wine32a_IsValidLocaleName(void);
__ASM_GLOBAL_FUNC(wine32a_IsValidLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsValidLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumSystemLocalesA(LOCALE_ENUMPROCA lpfnLocaleEnum, DWORD dwFlags)
{
	TRACE("Enter EnumSystemLocalesA\n");
	return pEnumSystemLocalesA(lpfnLocaleEnum, dwFlags);
}

extern WINAPI void wine32a_EnumSystemLocalesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemLocalesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemLocalesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumSystemLocalesW(LOCALE_ENUMPROCW lpfnLocaleEnum, DWORD dwFlags)
{
	TRACE("Enter EnumSystemLocalesW\n");
	return pEnumSystemLocalesW(lpfnLocaleEnum, dwFlags);
}

extern WINAPI void wine32a_EnumSystemLocalesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemLocalesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemLocalesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumSystemLocalesEx(LOCALE_ENUMPROCEX proc, DWORD flags, LPARAM lparam, LPVOID reserved)
{
	TRACE("Enter EnumSystemLocalesEx\n");
	return pEnumSystemLocalesEx(proc, flags, lparam, reserved);
}

extern WINAPI void wine32a_EnumSystemLocalesEx(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemLocalesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemLocalesEx") "\n"
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

extern WINAPI DWORD wine32b_VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD nSize)
{
	TRACE("Enter VerLanguageNameA\n");
	return pVerLanguageNameA(wLang, szLang, nSize);
}

extern WINAPI void wine32a_VerLanguageNameA(void);
__ASM_GLOBAL_FUNC(wine32a_VerLanguageNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerLanguageNameA") "\n"
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

extern WINAPI DWORD wine32b_VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD nSize)
{
	TRACE("Enter VerLanguageNameW\n");
	return pVerLanguageNameW(wLang, szLang, nSize);
}

extern WINAPI void wine32a_VerLanguageNameW(void);
__ASM_GLOBAL_FUNC(wine32a_VerLanguageNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerLanguageNameW") "\n"
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

extern WINAPI BOOL wine32b_GetStringTypeW(DWORD type, LPCWSTR src, INT count, LPWORD chartype)
{
	TRACE("Enter GetStringTypeW\n");
	return pGetStringTypeW(type, src, count, chartype);
}

extern WINAPI void wine32a_GetStringTypeW(void);
__ASM_GLOBAL_FUNC(wine32a_GetStringTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStringTypeW") "\n"
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

extern WINAPI BOOL wine32b_GetStringTypeExW(LCID locale, DWORD type, LPCWSTR src, INT count, LPWORD chartype)
{
	TRACE("Enter GetStringTypeExW\n");
	return pGetStringTypeExW(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_GetStringTypeExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetStringTypeExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStringTypeExW") "\n"
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

extern WINAPI BOOL wine32b_GetStringTypeA(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype)
{
	TRACE("Enter GetStringTypeA\n");
	return pGetStringTypeA(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_GetStringTypeA(void);
__ASM_GLOBAL_FUNC(wine32a_GetStringTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStringTypeA") "\n"
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

extern WINAPI BOOL wine32b_GetStringTypeExA(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype)
{
	TRACE("Enter GetStringTypeExA\n");
	return pGetStringTypeExA(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_GetStringTypeExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetStringTypeExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetStringTypeExA") "\n"
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

extern WINAPI INT wine32b_LCMapStringEx(LPCWSTR name, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lparam)
{
	TRACE("Enter LCMapStringEx\n");
	return pLCMapStringEx(name, flags, src, srclen, dst, dstlen, version, reserved, lparam);
}

extern WINAPI void wine32a_LCMapStringEx(void);
__ASM_GLOBAL_FUNC(wine32a_LCMapStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LCMapStringEx") "\n"
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

extern WINAPI INT wine32b_LCMapStringW(LCID lcid, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen)
{
	TRACE("Enter LCMapStringW\n");
	return pLCMapStringW(lcid, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_LCMapStringW(void);
__ASM_GLOBAL_FUNC(wine32a_LCMapStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LCMapStringW") "\n"
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

extern WINAPI INT wine32b_LCMapStringA(LCID lcid, DWORD flags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen)
{
	TRACE("Enter LCMapStringA\n");
	return pLCMapStringA(lcid, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_LCMapStringA(void);
__ASM_GLOBAL_FUNC(wine32a_LCMapStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LCMapStringA") "\n"
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

extern WINAPI INT wine32b_FoldStringA(DWORD dwFlags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen)
{
	TRACE("Enter FoldStringA\n");
	return pFoldStringA(dwFlags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_FoldStringA(void);
__ASM_GLOBAL_FUNC(wine32a_FoldStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FoldStringA") "\n"
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

extern WINAPI INT wine32b_FoldStringW(DWORD dwFlags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen)
{
	TRACE("Enter FoldStringW\n");
	return pFoldStringW(dwFlags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_FoldStringW(void);
__ASM_GLOBAL_FUNC(wine32a_FoldStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FoldStringW") "\n"
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

extern WINAPI INT wine32b_CompareStringW(LCID lcid, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2)
{
	TRACE("Enter CompareStringW\n");
	return pCompareStringW(lcid, flags, str1, len1, str2, len2);
}

extern WINAPI void wine32a_CompareStringW(void);
__ASM_GLOBAL_FUNC(wine32a_CompareStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CompareStringW") "\n"
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

extern WINAPI INT wine32b_CompareStringEx(LPCWSTR locale, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lParam)
{
	TRACE("Enter CompareStringEx\n");
	return pCompareStringEx(locale, flags, str1, len1, str2, len2, version, reserved, lParam);
}

extern WINAPI void wine32a_CompareStringEx(void);
__ASM_GLOBAL_FUNC(wine32a_CompareStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CompareStringEx") "\n"
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

extern WINAPI INT wine32b_CompareStringA(LCID lcid, DWORD flags, LPCSTR str1, INT len1, LPCSTR str2, INT len2)
{
	TRACE("Enter CompareStringA\n");
	return pCompareStringA(lcid, flags, str1, len1, str2, len2);
}

extern WINAPI void wine32a_CompareStringA(void);
__ASM_GLOBAL_FUNC(wine32a_CompareStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CompareStringA") "\n"
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

extern WINAPI INT wine32b_CompareStringOrdinal(const WCHAR * str1, INT len1, const WCHAR * str2, INT len2, BOOL ignore_case)
{
	TRACE("Enter CompareStringOrdinal\n");
	return pCompareStringOrdinal(str1, len1, str2, len2, ignore_case);
}

extern WINAPI void wine32a_CompareStringOrdinal(void);
__ASM_GLOBAL_FUNC(wine32a_CompareStringOrdinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CompareStringOrdinal") "\n"
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

extern WINAPI BOOL wine32b_EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumSystemLanguageGroupsA\n");
	return pEnumSystemLanguageGroupsA(pLangGrpEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumSystemLanguageGroupsA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemLanguageGroupsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemLanguageGroupsA") "\n"
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

extern WINAPI BOOL wine32b_EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumSystemLanguageGroupsW\n");
	return pEnumSystemLanguageGroupsW(pLangGrpEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumSystemLanguageGroupsW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemLanguageGroupsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemLanguageGroupsW") "\n"
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

extern WINAPI BOOL wine32b_IsValidLanguageGroup(LGRPID lgrpid, DWORD dwFlags)
{
	TRACE("Enter IsValidLanguageGroup\n");
	return pIsValidLanguageGroup(lgrpid, dwFlags);
}

extern WINAPI void wine32a_IsValidLanguageGroup(void);
__ASM_GLOBAL_FUNC(wine32a_IsValidLanguageGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsValidLanguageGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumLanguageGroupLocalesA(LANGGROUPLOCALE_ENUMPROCA pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumLanguageGroupLocalesA\n");
	return pEnumLanguageGroupLocalesA(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumLanguageGroupLocalesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumLanguageGroupLocalesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumLanguageGroupLocalesA") "\n"
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

extern WINAPI BOOL wine32b_EnumLanguageGroupLocalesW(LANGGROUPLOCALE_ENUMPROCW pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumLanguageGroupLocalesW\n");
	return pEnumLanguageGroupLocalesW(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumLanguageGroupLocalesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumLanguageGroupLocalesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumLanguageGroupLocalesW") "\n"
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

extern WINAPI BOOL wine32b_InvalidateNLSCache(void)
{
	TRACE("Enter InvalidateNLSCache\n");
	return pInvalidateNLSCache();
}

extern WINAPI void wine32a_InvalidateNLSCache(void);
__ASM_GLOBAL_FUNC(wine32a_InvalidateNLSCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InvalidateNLSCache") "\n"
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

extern WINAPI GEOID wine32b_GetUserGeoID(GEOCLASS GeoClass)
{
	TRACE("Enter GetUserGeoID\n");
	return pGetUserGeoID(GeoClass);
}

extern WINAPI void wine32a_GetUserGeoID(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserGeoID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetUserGeoID(GEOID GeoID)
{
	TRACE("Enter SetUserGeoID\n");
	return pSetUserGeoID(GeoID);
}

extern WINAPI void wine32a_SetUserGeoID(void);
__ASM_GLOBAL_FUNC(wine32a_SetUserGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUserGeoID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EnumUILanguagesA(UILANGUAGE_ENUMPROCA pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumUILanguagesA\n");
	return pEnumUILanguagesA(pUILangEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumUILanguagesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumUILanguagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumUILanguagesA") "\n"
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

extern WINAPI BOOL wine32b_EnumUILanguagesW(UILANGUAGE_ENUMPROCW pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam)
{
	TRACE("Enter EnumUILanguagesW\n");
	return pEnumUILanguagesW(pUILangEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_EnumUILanguagesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumUILanguagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumUILanguagesW") "\n"
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

extern WINAPI INT wine32b_GetGeoInfoW(GEOID geoid, GEOTYPE geotype, LPWSTR data, int data_len, LANGID lang)
{
	TRACE("Enter GetGeoInfoW\n");
	return pGetGeoInfoW(geoid, geotype, data, data_len, lang);
}

extern WINAPI void wine32a_GetGeoInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetGeoInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGeoInfoW") "\n"
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

extern WINAPI INT wine32b_GetGeoInfoA(GEOID geoid, GEOTYPE geotype, LPSTR data, int data_len, LANGID lang)
{
	TRACE("Enter GetGeoInfoA\n");
	return pGetGeoInfoA(geoid, geotype, data, data_len, lang);
}

extern WINAPI void wine32a_GetGeoInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetGeoInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetGeoInfoA") "\n"
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

extern WINAPI BOOL wine32b_EnumSystemGeoID(GEOCLASS geoclass, GEOID parent, GEO_ENUMPROC enumproc)
{
	TRACE("Enter EnumSystemGeoID\n");
	return pEnumSystemGeoID(geoclass, parent, enumproc);
}

extern WINAPI void wine32a_EnumSystemGeoID(void);
__ASM_GLOBAL_FUNC(wine32a_EnumSystemGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumSystemGeoID") "\n"
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

extern WINAPI INT wine32b_GetUserDefaultLocaleName(LPWSTR localename, int buffersize)
{
	TRACE("Enter GetUserDefaultLocaleName\n");
	return pGetUserDefaultLocaleName(localename, buffersize);
}

extern WINAPI void wine32a_GetUserDefaultLocaleName(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserDefaultLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserDefaultLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_NormalizeString(NORM_FORM form, const WCHAR * src, INT src_len, WCHAR * dst, INT dst_len)
{
	TRACE("Enter NormalizeString\n");
	return pNormalizeString(form, src, src_len, dst, dst_len);
}

extern WINAPI void wine32a_NormalizeString(void);
__ASM_GLOBAL_FUNC(wine32a_NormalizeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NormalizeString") "\n"
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

extern WINAPI BOOL wine32b_IsNormalizedString(NORM_FORM NormForm, LPCWSTR lpString, INT cwLength)
{
	TRACE("Enter IsNormalizedString\n");
	return pIsNormalizedString(NormForm, lpString, cwLength);
}

extern WINAPI void wine32a_IsNormalizedString(void);
__ASM_GLOBAL_FUNC(wine32a_IsNormalizedString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsNormalizedString") "\n"
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

extern WINAPI INT wine32b_IdnToAscii(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpASCIICharStr, INT cchASCIIChar)
{
	TRACE("Enter IdnToAscii\n");
	return pIdnToAscii(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpASCIICharStr, cchASCIIChar);
}

extern WINAPI void wine32a_IdnToAscii(void);
__ASM_GLOBAL_FUNC(wine32a_IdnToAscii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IdnToAscii") "\n"
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

extern WINAPI INT wine32b_IdnToNameprepUnicode(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpNameprepCharStr, INT cchNameprepChar)
{
	TRACE("Enter IdnToNameprepUnicode\n");
	return pIdnToNameprepUnicode(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpNameprepCharStr, cchNameprepChar);
}

extern WINAPI void wine32a_IdnToNameprepUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_IdnToNameprepUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IdnToNameprepUnicode") "\n"
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

extern WINAPI INT wine32b_IdnToUnicode(DWORD dwFlags, LPCWSTR lpASCIICharStr, INT cchASCIIChar, LPWSTR lpUnicodeCharStr, INT cchUnicodeChar)
{
	TRACE("Enter IdnToUnicode\n");
	return pIdnToUnicode(dwFlags, lpASCIICharStr, cchASCIIChar, lpUnicodeCharStr, cchUnicodeChar);
}

extern WINAPI void wine32a_IdnToUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_IdnToUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IdnToUnicode") "\n"
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

extern WINAPI BOOL wine32b_GetFileMUIPath(DWORD flags, PCWSTR filepath, PWSTR language, PULONG languagelen, PWSTR muipath, PULONG muipathlen, PULONGLONG enumerator)
{
	TRACE("Enter GetFileMUIPath\n");
	return pGetFileMUIPath(flags, filepath, language, languagelen, muipath, muipathlen, enumerator);
}

extern WINAPI void wine32a_GetFileMUIPath(void);
__ASM_GLOBAL_FUNC(wine32a_GetFileMUIPath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFileMUIPath") "\n"
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

extern WINAPI BOOL wine32b_GetFileMUIInfo(DWORD flags, PCWSTR path, FILEMUIINFO * info, DWORD * size)
{
	TRACE("Enter GetFileMUIInfo\n");
	return pGetFileMUIInfo(flags, path, info, size);
}

extern WINAPI void wine32a_GetFileMUIInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetFileMUIInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFileMUIInfo") "\n"
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

extern WINAPI INT wine32b_ResolveLocaleName(LPCWSTR name, LPWSTR localename, INT len)
{
	TRACE("Enter ResolveLocaleName\n");
	return pResolveLocaleName(name, localename, len);
}

extern WINAPI void wine32a_ResolveLocaleName(void);
__ASM_GLOBAL_FUNC(wine32a_ResolveLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ResolveLocaleName") "\n"
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

extern WINAPI INT wine32b_FindNLSStringEx(const WCHAR * localename, DWORD flags, const WCHAR * src, INT src_size, const WCHAR * value, INT value_size, INT * found, NLSVERSIONINFO * version_info, void * reserved, LPARAM sort_handle)
{
	TRACE("Enter FindNLSStringEx\n");
	return pFindNLSStringEx(localename, flags, src, src_size, value, value_size, found, version_info, reserved, sort_handle);
}

extern WINAPI void wine32a_FindNLSStringEx(void);
__ASM_GLOBAL_FUNC(wine32a_FindNLSStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNLSStringEx") "\n"
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

extern WINAPI INT wine32b_FindStringOrdinal(DWORD flag, const WCHAR * src, INT src_size, const WCHAR * val, INT val_size, BOOL ignore_case)
{
	TRACE("Enter FindStringOrdinal\n");
	return pFindStringOrdinal(flag, src, src_size, val, val_size, ignore_case);
}

extern WINAPI void wine32a_FindStringOrdinal(void);
__ASM_GLOBAL_FUNC(wine32a_FindStringOrdinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindStringOrdinal") "\n"
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

static WINAPI INT (*pLZStart)(void);
static WINAPI HFILE (*pLZInit)(HFILE hfSrc);
static WINAPI void (*pLZDone)(void);
static WINAPI INT (*pGetExpandedNameA)(LPSTR in, LPSTR out);
static WINAPI INT (*pGetExpandedNameW)(LPWSTR in, LPWSTR out);
static WINAPI INT (*pLZRead)(HFILE fd, LPSTR vbuf, INT toread);
static WINAPI LONG (*pLZSeek)(HFILE fd, LONG off, INT type);
static WINAPI LONG (*pLZCopy)(HFILE src, HFILE dest);
static WINAPI HFILE (*pLZOpenFileA)(LPSTR fn, LPOFSTRUCT ofs, WORD mode);
static WINAPI HFILE (*pLZOpenFileW)(LPWSTR fn, LPOFSTRUCT ofs, WORD mode);
static WINAPI void (*pLZClose)(HFILE fd);

extern WINAPI INT wine32b_LZStart(void)
{
	TRACE("Enter LZStart\n");
	return pLZStart();
}

extern WINAPI void wine32a_LZStart(void);
__ASM_GLOBAL_FUNC(wine32a_LZStart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZStart") "\n"
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

extern WINAPI HFILE wine32b_LZInit(HFILE hfSrc)
{
	TRACE("Enter LZInit\n");
	return pLZInit(hfSrc);
}

extern WINAPI void wine32a_LZInit(void);
__ASM_GLOBAL_FUNC(wine32a_LZInit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZInit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_LZDone(void)
{
	TRACE("Enter LZDone\n");
	return pLZDone();
}

extern WINAPI void wine32a_LZDone(void);
__ASM_GLOBAL_FUNC(wine32a_LZDone,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZDone") "\n"
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

extern WINAPI INT wine32b_GetExpandedNameA(LPSTR in, LPSTR out)
{
	TRACE("Enter GetExpandedNameA\n");
	return pGetExpandedNameA(in, out);
}

extern WINAPI void wine32a_GetExpandedNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetExpandedNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetExpandedNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_GetExpandedNameW(LPWSTR in, LPWSTR out)
{
	TRACE("Enter GetExpandedNameW\n");
	return pGetExpandedNameW(in, out);
}

extern WINAPI void wine32a_GetExpandedNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetExpandedNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetExpandedNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_LZRead(HFILE fd, LPSTR vbuf, INT toread)
{
	TRACE("Enter LZRead\n");
	return pLZRead(fd, vbuf, toread);
}

extern WINAPI void wine32a_LZRead(void);
__ASM_GLOBAL_FUNC(wine32a_LZRead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZRead") "\n"
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

extern WINAPI LONG wine32b_LZSeek(HFILE fd, LONG off, INT type)
{
	TRACE("Enter LZSeek\n");
	return pLZSeek(fd, off, type);
}

extern WINAPI void wine32a_LZSeek(void);
__ASM_GLOBAL_FUNC(wine32a_LZSeek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZSeek") "\n"
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

extern WINAPI LONG wine32b_LZCopy(HFILE src, HFILE dest)
{
	TRACE("Enter LZCopy\n");
	return pLZCopy(src, dest);
}

extern WINAPI void wine32a_LZCopy(void);
__ASM_GLOBAL_FUNC(wine32a_LZCopy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZCopy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_LZOpenFileA(LPSTR fn, LPOFSTRUCT ofs, WORD mode)
{
	TRACE("Enter LZOpenFileA\n");
	return pLZOpenFileA(fn, ofs, mode);
}

extern WINAPI void wine32a_LZOpenFileA(void);
__ASM_GLOBAL_FUNC(wine32a_LZOpenFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZOpenFileA") "\n"
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

extern WINAPI HFILE wine32b_LZOpenFileW(LPWSTR fn, LPOFSTRUCT ofs, WORD mode)
{
	TRACE("Enter LZOpenFileW\n");
	return pLZOpenFileW(fn, ofs, mode);
}

extern WINAPI void wine32a_LZOpenFileW(void);
__ASM_GLOBAL_FUNC(wine32a_LZOpenFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZOpenFileW") "\n"
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

extern WINAPI void wine32b_LZClose(HFILE fd)
{
	TRACE("Enter LZClose\n");
	return pLZClose(fd);
}

extern WINAPI void wine32a_LZClose(void);
__ASM_GLOBAL_FUNC(wine32a_LZClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LZClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI DWORD (*pGetDllDirectoryA)(DWORD buf_len, LPSTR buffer);
static WINAPI DWORD (*pGetDllDirectoryW)(DWORD buf_len, LPWSTR buffer);
static WINAPI BOOL (*pSetDllDirectoryA)(LPCSTR dir);
static WINAPI BOOL (*pSetDllDirectoryW)(LPCWSTR dir);
static WINAPI DLL_DIRECTORY_COOKIE (*pAddDllDirectory)(const WCHAR * dir);
static WINAPI BOOL (*pRemoveDllDirectory)(DLL_DIRECTORY_COOKIE cookie);
static WINAPI BOOL (*pSetDefaultDllDirectories)(DWORD flags);
static WINAPI BOOL (*pGetBinaryTypeW)(LPCWSTR name, LPDWORD type);
static WINAPI BOOL (*pGetBinaryTypeA)(LPCSTR lpApplicationName, LPDWORD lpBinaryType);
static WINAPI HMODULE (*pLoadLibraryExA)(LPCSTR libname, HANDLE hfile, DWORD flags);
static WINAPI HMODULE (*pLoadLibraryExW)(LPCWSTR libnameW, HANDLE hfile, DWORD flags);
static WINAPI HMODULE (*pLoadLibraryA)(LPCSTR libname);
static WINAPI HMODULE (*pLoadLibraryW)(LPCWSTR libnameW);
static WINAPI BOOL (*pFreeLibrary)(HINSTANCE hLibModule);
static WINAPI FARPROC (*pGetProcAddress)(HMODULE hModule, LPCSTR function);
static WINAPI FARPROC (*pDelayLoadFailureHook)(LPCSTR name, LPCSTR function);
static WINAPI BOOL (*pK32EnumProcessModules)(HANDLE process, HMODULE * lphModule, DWORD cb, DWORD * needed);
static WINAPI BOOL (*pK32EnumProcessModulesEx)(HANDLE process, HMODULE * lphModule, DWORD cb, DWORD * needed, DWORD filter);
static WINAPI DWORD (*pK32GetModuleBaseNameW)(HANDLE process, HMODULE module, LPWSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleBaseNameA)(HANDLE process, HMODULE module, LPSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleFileNameExW)(HANDLE process, HMODULE module, LPWSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleFileNameExA)(HANDLE process, HMODULE module, LPSTR file_name, DWORD size);
static WINAPI BOOL (*pK32GetModuleInformation)(HANDLE process, HMODULE module, MODULEINFO * modinfo, DWORD cb);

extern WINAPI DWORD wine32b_GetDllDirectoryA(DWORD buf_len, LPSTR buffer)
{
	TRACE("Enter GetDllDirectoryA\n");
	return pGetDllDirectoryA(buf_len, buffer);
}

extern WINAPI void wine32a_GetDllDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDllDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDllDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetDllDirectoryW(DWORD buf_len, LPWSTR buffer)
{
	TRACE("Enter GetDllDirectoryW\n");
	return pGetDllDirectoryW(buf_len, buffer);
}

extern WINAPI void wine32a_GetDllDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDllDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDllDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetDllDirectoryA(LPCSTR dir)
{
	TRACE("Enter SetDllDirectoryA\n");
	return pSetDllDirectoryA(dir);
}

extern WINAPI void wine32a_SetDllDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_SetDllDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDllDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetDllDirectoryW(LPCWSTR dir)
{
	TRACE("Enter SetDllDirectoryW\n");
	return pSetDllDirectoryW(dir);
}

extern WINAPI void wine32a_SetDllDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_SetDllDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDllDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DLL_DIRECTORY_COOKIE wine32b_AddDllDirectory(const WCHAR * dir)
{
	TRACE("Enter AddDllDirectory\n");
	return pAddDllDirectory(dir);
}

extern WINAPI void wine32a_AddDllDirectory(void);
__ASM_GLOBAL_FUNC(wine32a_AddDllDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AddDllDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RemoveDllDirectory(DLL_DIRECTORY_COOKIE cookie)
{
	TRACE("Enter RemoveDllDirectory\n");
	return pRemoveDllDirectory(cookie);
}

extern WINAPI void wine32a_RemoveDllDirectory(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveDllDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveDllDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetDefaultDllDirectories(DWORD flags)
{
	TRACE("Enter SetDefaultDllDirectories\n");
	return pSetDefaultDllDirectories(flags);
}

extern WINAPI void wine32a_SetDefaultDllDirectories(void);
__ASM_GLOBAL_FUNC(wine32a_SetDefaultDllDirectories,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetDefaultDllDirectories") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetBinaryTypeW(LPCWSTR name, LPDWORD type)
{
	TRACE("Enter GetBinaryTypeW\n");
	return pGetBinaryTypeW(name, type);
}

extern WINAPI void wine32a_GetBinaryTypeW(void);
__ASM_GLOBAL_FUNC(wine32a_GetBinaryTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetBinaryTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetBinaryTypeA(LPCSTR lpApplicationName, LPDWORD lpBinaryType)
{
	TRACE("Enter GetBinaryTypeA\n");
	return pGetBinaryTypeA(lpApplicationName, lpBinaryType);
}

extern WINAPI void wine32a_GetBinaryTypeA(void);
__ASM_GLOBAL_FUNC(wine32a_GetBinaryTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetBinaryTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_LoadLibraryExA(LPCSTR libname, HANDLE hfile, DWORD flags)
{
	TRACE("Enter LoadLibraryExA\n");
	return pLoadLibraryExA(libname, hfile, flags);
}

extern WINAPI void wine32a_LoadLibraryExA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadLibraryExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadLibraryExA") "\n"
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

extern WINAPI HMODULE wine32b_LoadLibraryExW(LPCWSTR libnameW, HANDLE hfile, DWORD flags)
{
	TRACE("Enter LoadLibraryExW\n");
	return pLoadLibraryExW(libnameW, hfile, flags);
}

extern WINAPI void wine32a_LoadLibraryExW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadLibraryExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadLibraryExW") "\n"
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

extern WINAPI HMODULE wine32b_LoadLibraryA(LPCSTR libname)
{
	TRACE("Enter LoadLibraryA\n");
	return pLoadLibraryA(libname);
}

extern WINAPI void wine32a_LoadLibraryA(void);
__ASM_GLOBAL_FUNC(wine32a_LoadLibraryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadLibraryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_LoadLibraryW(LPCWSTR libnameW)
{
	TRACE("Enter LoadLibraryW\n");
	return pLoadLibraryW(libnameW);
}

extern WINAPI void wine32a_LoadLibraryW(void);
__ASM_GLOBAL_FUNC(wine32a_LoadLibraryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadLibraryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FreeLibrary(HINSTANCE hLibModule)
{
	TRACE("Enter FreeLibrary\n");
	return pFreeLibrary(hLibModule);
}

extern WINAPI void wine32a_FreeLibrary(void);
__ASM_GLOBAL_FUNC(wine32a_FreeLibrary,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeLibrary") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI FARPROC wine32b_GetProcAddress(HMODULE hModule, LPCSTR function)
{
	TRACE("Enter GetProcAddress\n");
	return pGetProcAddress(hModule, function);
}

extern WINAPI void wine32a_GetProcAddress(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI FARPROC wine32b_DelayLoadFailureHook(LPCSTR name, LPCSTR function)
{
	TRACE("Enter DelayLoadFailureHook\n");
	return pDelayLoadFailureHook(name, function);
}

extern WINAPI void wine32a_DelayLoadFailureHook(void);
__ASM_GLOBAL_FUNC(wine32a_DelayLoadFailureHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DelayLoadFailureHook") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_K32EnumProcessModules(HANDLE process, HMODULE * lphModule, DWORD cb, DWORD * needed)
{
	TRACE("Enter K32EnumProcessModules\n");
	return pK32EnumProcessModules(process, lphModule, cb, needed);
}

extern WINAPI void wine32a_K32EnumProcessModules(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumProcessModules,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumProcessModules") "\n"
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

extern WINAPI BOOL wine32b_K32EnumProcessModulesEx(HANDLE process, HMODULE * lphModule, DWORD cb, DWORD * needed, DWORD filter)
{
	TRACE("Enter K32EnumProcessModulesEx\n");
	return pK32EnumProcessModulesEx(process, lphModule, cb, needed, filter);
}

extern WINAPI void wine32a_K32EnumProcessModulesEx(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumProcessModulesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumProcessModulesEx") "\n"
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

extern WINAPI DWORD wine32b_K32GetModuleBaseNameW(HANDLE process, HMODULE module, LPWSTR base_name, DWORD size)
{
	TRACE("Enter K32GetModuleBaseNameW\n");
	return pK32GetModuleBaseNameW(process, module, base_name, size);
}

extern WINAPI void wine32a_K32GetModuleBaseNameW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetModuleBaseNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetModuleBaseNameW") "\n"
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

extern WINAPI DWORD wine32b_K32GetModuleBaseNameA(HANDLE process, HMODULE module, LPSTR base_name, DWORD size)
{
	TRACE("Enter K32GetModuleBaseNameA\n");
	return pK32GetModuleBaseNameA(process, module, base_name, size);
}

extern WINAPI void wine32a_K32GetModuleBaseNameA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetModuleBaseNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetModuleBaseNameA") "\n"
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

extern WINAPI DWORD wine32b_K32GetModuleFileNameExW(HANDLE process, HMODULE module, LPWSTR file_name, DWORD size)
{
	TRACE("Enter K32GetModuleFileNameExW\n");
	return pK32GetModuleFileNameExW(process, module, file_name, size);
}

extern WINAPI void wine32a_K32GetModuleFileNameExW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetModuleFileNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetModuleFileNameExW") "\n"
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

extern WINAPI DWORD wine32b_K32GetModuleFileNameExA(HANDLE process, HMODULE module, LPSTR file_name, DWORD size)
{
	TRACE("Enter K32GetModuleFileNameExA\n");
	return pK32GetModuleFileNameExA(process, module, file_name, size);
}

extern WINAPI void wine32a_K32GetModuleFileNameExA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetModuleFileNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetModuleFileNameExA") "\n"
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

extern WINAPI BOOL wine32b_K32GetModuleInformation(HANDLE process, HMODULE module, MODULEINFO * modinfo, DWORD cb)
{
	TRACE("Enter K32GetModuleInformation\n");
	return pK32GetModuleInformation(process, module, modinfo, cb);
}

extern WINAPI void wine32a_K32GetModuleInformation(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetModuleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetModuleInformation") "\n"
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



static WINAPI DWORD (*pGetFullPathNameW)(LPCWSTR name, DWORD len, LPWSTR buffer, LPWSTR * lastpart);
static WINAPI DWORD (*pGetFullPathNameA)(LPCSTR name, DWORD len, LPSTR buffer, LPSTR * lastpart);
static WINAPI DWORD (*pGetLongPathNameW)(LPCWSTR shortpath, LPWSTR longpath, DWORD longlen);
static WINAPI DWORD (*pGetLongPathNameA)(LPCSTR shortpath, LPSTR longpath, DWORD longlen);
static WINAPI DWORD (*pGetShortPathNameW)(LPCWSTR longpath, LPWSTR shortpath, DWORD shortlen);
static WINAPI DWORD (*pGetShortPathNameA)(LPCSTR longpath, LPSTR shortpath, DWORD shortlen);
static WINAPI DWORD (*pGetTempPathA)(DWORD count, LPSTR path);
static WINAPI DWORD (*pGetTempPathW)(DWORD count, LPWSTR path);
static WINAPI UINT (*pGetTempFileNameA)(LPCSTR path, LPCSTR prefix, UINT unique, LPSTR buffer);
static WINAPI UINT (*pGetTempFileNameW)(LPCWSTR path, LPCWSTR prefix, UINT unique, LPWSTR buffer);
static WINAPI DWORD (*pSearchPathW)(LPCWSTR path, LPCWSTR name, LPCWSTR ext, DWORD buflen, LPWSTR buffer, LPWSTR * lastpart);
static WINAPI DWORD (*pSearchPathA)(LPCSTR path, LPCSTR name, LPCSTR ext, DWORD buflen, LPSTR buffer, LPSTR * lastpart);
static WINAPI BOOL (*pCopyFileW)(LPCWSTR source, LPCWSTR dest, BOOL fail_if_exists);
static WINAPI BOOL (*pCopyFileA)(LPCSTR source, LPCSTR dest, BOOL fail_if_exists);
static WINAPI BOOL (*pCopyFileExW)(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE progress, LPVOID param, LPBOOL cancel_ptr, DWORD flags);
static WINAPI BOOL (*pCopyFileExA)(LPCSTR sourceFilename, LPCSTR destFilename, LPPROGRESS_ROUTINE progressRoutine, LPVOID appData, LPBOOL cancelFlagPointer, DWORD copyFlags);
static WINAPI BOOL (*pMoveFileTransactedA)(const char * source, const char * dest, LPPROGRESS_ROUTINE progress, void * data, DWORD flags, HANDLE handle);
static WINAPI BOOL (*pMoveFileTransactedW)(const WCHAR * source, const WCHAR * dest, LPPROGRESS_ROUTINE progress, void * data, DWORD flags, HANDLE handle);
static WINAPI BOOL (*pMoveFileWithProgressW)(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag);
static WINAPI BOOL (*pMoveFileWithProgressA)(LPCSTR source, LPCSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag);
static WINAPI BOOL (*pMoveFileExW)(LPCWSTR source, LPCWSTR dest, DWORD flag);
static WINAPI BOOL (*pMoveFileExA)(LPCSTR source, LPCSTR dest, DWORD flag);
static WINAPI BOOL (*pMoveFileW)(LPCWSTR source, LPCWSTR dest);
static WINAPI BOOL (*pMoveFileA)(LPCSTR source, LPCSTR dest);
static WINAPI BOOL (*pCreateHardLinkW)(LPCWSTR lpFileName, LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
static WINAPI BOOL (*pCreateHardLinkA)(LPCSTR lpFileName, LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
static WINAPI BOOL (*pCreateDirectoryExA)(LPCSTR template, LPCSTR path, LPSECURITY_ATTRIBUTES sa);
static WINAPI BOOL (*pRemoveDirectoryW)(LPCWSTR path);
static WINAPI BOOL (*pRemoveDirectoryA)(LPCSTR path);
static WINAPI UINT (*pGetCurrentDirectoryW)(UINT buflen, LPWSTR buf);
static WINAPI UINT (*pGetCurrentDirectoryA)(UINT buflen, LPSTR buf);
static WINAPI BOOL (*pSetCurrentDirectoryW)(LPCWSTR dir);
static WINAPI BOOL (*pSetCurrentDirectoryA)(LPCSTR dir);
static WINAPI UINT (*pGetSystemDirectoryW)(LPWSTR path, UINT count);
static WINAPI UINT (*pGetSystemDirectoryA)(LPSTR path, UINT count);
static WINAPI UINT (*pGetSystemWow64DirectoryW)(LPWSTR path, UINT count);
static WINAPI UINT (*pGetSystemWow64DirectoryA)(LPSTR path, UINT count);
static WINAPI BOOLEAN (*pWow64EnableWow64FsRedirection)(BOOLEAN enable);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathW)(LPCWSTR name);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathA)(LPCSTR name);
static WINAPI char * (*pwine_get_unix_file_name)(LPCWSTR dosW);
static WINAPI WCHAR * (*pwine_get_dos_file_name)(LPCSTR str);
static WINAPI BOOLEAN (*pCreateSymbolicLinkW)(LPCWSTR link, LPCWSTR target, DWORD flags);
static WINAPI BOOLEAN (*pCreateSymbolicLinkA)(LPCSTR link, LPCSTR target, DWORD flags);
static WINAPI BOOL (*pCreateHardLinkTransactedA)(LPCSTR link, LPCSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction);
static WINAPI BOOL (*pCreateHardLinkTransactedW)(LPCWSTR link, LPCWSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction);
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3A)(const char * name, char * oemname, DWORD oemname_len, BOOL * contains_spaces, BOOL * is_legal);
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3W)(const WCHAR * name, char * oemname, DWORD oemname_len, BOOL * contains_spaces_ret, BOOL * is_legal);
static WINAPI BOOL (*pSetSearchPathMode)(DWORD flags);

extern WINAPI DWORD wine32b_GetFullPathNameW(LPCWSTR name, DWORD len, LPWSTR buffer, LPWSTR * lastpart)
{
	TRACE("Enter GetFullPathNameW\n");
	return pGetFullPathNameW(name, len, buffer, lastpart);
}

extern WINAPI void wine32a_GetFullPathNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetFullPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFullPathNameW") "\n"
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

extern WINAPI DWORD wine32b_GetFullPathNameA(LPCSTR name, DWORD len, LPSTR buffer, LPSTR * lastpart)
{
	TRACE("Enter GetFullPathNameA\n");
	return pGetFullPathNameA(name, len, buffer, lastpart);
}

extern WINAPI void wine32a_GetFullPathNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetFullPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFullPathNameA") "\n"
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

extern WINAPI DWORD wine32b_GetLongPathNameW(LPCWSTR shortpath, LPWSTR longpath, DWORD longlen)
{
	TRACE("Enter GetLongPathNameW\n");
	return pGetLongPathNameW(shortpath, longpath, longlen);
}

extern WINAPI void wine32a_GetLongPathNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetLongPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLongPathNameW") "\n"
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

extern WINAPI DWORD wine32b_GetLongPathNameA(LPCSTR shortpath, LPSTR longpath, DWORD longlen)
{
	TRACE("Enter GetLongPathNameA\n");
	return pGetLongPathNameA(shortpath, longpath, longlen);
}

extern WINAPI void wine32a_GetLongPathNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetLongPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLongPathNameA") "\n"
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

extern WINAPI DWORD wine32b_GetShortPathNameW(LPCWSTR longpath, LPWSTR shortpath, DWORD shortlen)
{
	TRACE("Enter GetShortPathNameW\n");
	return pGetShortPathNameW(longpath, shortpath, shortlen);
}

extern WINAPI void wine32a_GetShortPathNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetShortPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetShortPathNameW") "\n"
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

extern WINAPI DWORD wine32b_GetShortPathNameA(LPCSTR longpath, LPSTR shortpath, DWORD shortlen)
{
	TRACE("Enter GetShortPathNameA\n");
	return pGetShortPathNameA(longpath, shortpath, shortlen);
}

extern WINAPI void wine32a_GetShortPathNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetShortPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetShortPathNameA") "\n"
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

extern WINAPI DWORD wine32b_GetTempPathA(DWORD count, LPSTR path)
{
	TRACE("Enter GetTempPathA\n");
	return pGetTempPathA(count, path);
}

extern WINAPI void wine32a_GetTempPathA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTempPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTempPathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetTempPathW(DWORD count, LPWSTR path)
{
	TRACE("Enter GetTempPathW\n");
	return pGetTempPathW(count, path);
}

extern WINAPI void wine32a_GetTempPathW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTempPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTempPathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetTempFileNameA(LPCSTR path, LPCSTR prefix, UINT unique, LPSTR buffer)
{
	TRACE("Enter GetTempFileNameA\n");
	return pGetTempFileNameA(path, prefix, unique, buffer);
}

extern WINAPI void wine32a_GetTempFileNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTempFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTempFileNameA") "\n"
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

extern WINAPI UINT wine32b_GetTempFileNameW(LPCWSTR path, LPCWSTR prefix, UINT unique, LPWSTR buffer)
{
	TRACE("Enter GetTempFileNameW\n");
	return pGetTempFileNameW(path, prefix, unique, buffer);
}

extern WINAPI void wine32a_GetTempFileNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTempFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTempFileNameW") "\n"
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

extern WINAPI DWORD wine32b_SearchPathW(LPCWSTR path, LPCWSTR name, LPCWSTR ext, DWORD buflen, LPWSTR buffer, LPWSTR * lastpart)
{
	TRACE("Enter SearchPathW\n");
	return pSearchPathW(path, name, ext, buflen, buffer, lastpart);
}

extern WINAPI void wine32a_SearchPathW(void);
__ASM_GLOBAL_FUNC(wine32a_SearchPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SearchPathW") "\n"
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

extern WINAPI DWORD wine32b_SearchPathA(LPCSTR path, LPCSTR name, LPCSTR ext, DWORD buflen, LPSTR buffer, LPSTR * lastpart)
{
	TRACE("Enter SearchPathA\n");
	return pSearchPathA(path, name, ext, buflen, buffer, lastpart);
}

extern WINAPI void wine32a_SearchPathA(void);
__ASM_GLOBAL_FUNC(wine32a_SearchPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SearchPathA") "\n"
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

extern WINAPI BOOL wine32b_CopyFileW(LPCWSTR source, LPCWSTR dest, BOOL fail_if_exists)
{
	TRACE("Enter CopyFileW\n");
	return pCopyFileW(source, dest, fail_if_exists);
}

extern WINAPI void wine32a_CopyFileW(void);
__ASM_GLOBAL_FUNC(wine32a_CopyFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyFileW") "\n"
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

extern WINAPI BOOL wine32b_CopyFileA(LPCSTR source, LPCSTR dest, BOOL fail_if_exists)
{
	TRACE("Enter CopyFileA\n");
	return pCopyFileA(source, dest, fail_if_exists);
}

extern WINAPI void wine32a_CopyFileA(void);
__ASM_GLOBAL_FUNC(wine32a_CopyFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyFileA") "\n"
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

extern WINAPI BOOL wine32b_CopyFileExW(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE progress, LPVOID param, LPBOOL cancel_ptr, DWORD flags)
{
	TRACE("Enter CopyFileExW\n");
	return pCopyFileExW(source, dest, progress, param, cancel_ptr, flags);
}

extern WINAPI void wine32a_CopyFileExW(void);
__ASM_GLOBAL_FUNC(wine32a_CopyFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyFileExW") "\n"
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

extern WINAPI BOOL wine32b_CopyFileExA(LPCSTR sourceFilename, LPCSTR destFilename, LPPROGRESS_ROUTINE progressRoutine, LPVOID appData, LPBOOL cancelFlagPointer, DWORD copyFlags)
{
	TRACE("Enter CopyFileExA\n");
	return pCopyFileExA(sourceFilename, destFilename, progressRoutine, appData, cancelFlagPointer, copyFlags);
}

extern WINAPI void wine32a_CopyFileExA(void);
__ASM_GLOBAL_FUNC(wine32a_CopyFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CopyFileExA") "\n"
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

extern WINAPI BOOL wine32b_MoveFileTransactedA(const char * source, const char * dest, LPPROGRESS_ROUTINE progress, void * data, DWORD flags, HANDLE handle)
{
	TRACE("Enter MoveFileTransactedA\n");
	return pMoveFileTransactedA(source, dest, progress, data, flags, handle);
}

extern WINAPI void wine32a_MoveFileTransactedA(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileTransactedA") "\n"
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

extern WINAPI BOOL wine32b_MoveFileTransactedW(const WCHAR * source, const WCHAR * dest, LPPROGRESS_ROUTINE progress, void * data, DWORD flags, HANDLE handle)
{
	TRACE("Enter MoveFileTransactedW\n");
	return pMoveFileTransactedW(source, dest, progress, data, flags, handle);
}

extern WINAPI void wine32a_MoveFileTransactedW(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileTransactedW") "\n"
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

extern WINAPI BOOL wine32b_MoveFileWithProgressW(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag)
{
	TRACE("Enter MoveFileWithProgressW\n");
	return pMoveFileWithProgressW(source, dest, fnProgress, param, flag);
}

extern WINAPI void wine32a_MoveFileWithProgressW(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileWithProgressW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileWithProgressW") "\n"
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

extern WINAPI BOOL wine32b_MoveFileWithProgressA(LPCSTR source, LPCSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag)
{
	TRACE("Enter MoveFileWithProgressA\n");
	return pMoveFileWithProgressA(source, dest, fnProgress, param, flag);
}

extern WINAPI void wine32a_MoveFileWithProgressA(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileWithProgressA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileWithProgressA") "\n"
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

extern WINAPI BOOL wine32b_MoveFileExW(LPCWSTR source, LPCWSTR dest, DWORD flag)
{
	TRACE("Enter MoveFileExW\n");
	return pMoveFileExW(source, dest, flag);
}

extern WINAPI void wine32a_MoveFileExW(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileExW") "\n"
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

extern WINAPI BOOL wine32b_MoveFileExA(LPCSTR source, LPCSTR dest, DWORD flag)
{
	TRACE("Enter MoveFileExA\n");
	return pMoveFileExA(source, dest, flag);
}

extern WINAPI void wine32a_MoveFileExA(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileExA") "\n"
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

extern WINAPI BOOL wine32b_MoveFileW(LPCWSTR source, LPCWSTR dest)
{
	TRACE("Enter MoveFileW\n");
	return pMoveFileW(source, dest);
}

extern WINAPI void wine32a_MoveFileW(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_MoveFileA(LPCSTR source, LPCSTR dest)
{
	TRACE("Enter MoveFileA\n");
	return pMoveFileA(source, dest);
}

extern WINAPI void wine32a_MoveFileA(void);
__ASM_GLOBAL_FUNC(wine32a_MoveFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MoveFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CreateHardLinkW(LPCWSTR lpFileName, LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	TRACE("Enter CreateHardLinkW\n");
	return pCreateHardLinkW(lpFileName, lpExistingFileName, lpSecurityAttributes);
}

extern WINAPI void wine32a_CreateHardLinkW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateHardLinkW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateHardLinkW") "\n"
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

extern WINAPI BOOL wine32b_CreateHardLinkA(LPCSTR lpFileName, LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
	TRACE("Enter CreateHardLinkA\n");
	return pCreateHardLinkA(lpFileName, lpExistingFileName, lpSecurityAttributes);
}

extern WINAPI void wine32a_CreateHardLinkA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateHardLinkA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateHardLinkA") "\n"
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

extern WINAPI BOOL wine32b_CreateDirectoryExA(LPCSTR template, LPCSTR path, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateDirectoryExA\n");
	return pCreateDirectoryExA(template, path, sa);
}

extern WINAPI void wine32a_CreateDirectoryExA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateDirectoryExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateDirectoryExA") "\n"
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

extern WINAPI BOOL wine32b_RemoveDirectoryW(LPCWSTR path)
{
	TRACE("Enter RemoveDirectoryW\n");
	return pRemoveDirectoryW(path);
}

extern WINAPI void wine32a_RemoveDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RemoveDirectoryA(LPCSTR path)
{
	TRACE("Enter RemoveDirectoryA\n");
	return pRemoveDirectoryA(path);
}

extern WINAPI void wine32a_RemoveDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_RemoveDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RemoveDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetCurrentDirectoryW(UINT buflen, LPWSTR buf)
{
	TRACE("Enter GetCurrentDirectoryW\n");
	return pGetCurrentDirectoryW(buflen, buf);
}

extern WINAPI void wine32a_GetCurrentDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetCurrentDirectoryA(UINT buflen, LPSTR buf)
{
	TRACE("Enter GetCurrentDirectoryA\n");
	return pGetCurrentDirectoryA(buflen, buf);
}

extern WINAPI void wine32a_GetCurrentDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCurrentDirectoryW(LPCWSTR dir)
{
	TRACE("Enter SetCurrentDirectoryW\n");
	return pSetCurrentDirectoryW(dir);
}

extern WINAPI void wine32a_SetCurrentDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_SetCurrentDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCurrentDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetCurrentDirectoryA(LPCSTR dir)
{
	TRACE("Enter SetCurrentDirectoryA\n");
	return pSetCurrentDirectoryA(dir);
}

extern WINAPI void wine32a_SetCurrentDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_SetCurrentDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCurrentDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetSystemDirectoryW(LPWSTR path, UINT count)
{
	TRACE("Enter GetSystemDirectoryW\n");
	return pGetSystemDirectoryW(path, count);
}

extern WINAPI void wine32a_GetSystemDirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetSystemDirectoryA(LPSTR path, UINT count)
{
	TRACE("Enter GetSystemDirectoryA\n");
	return pGetSystemDirectoryA(path, count);
}

extern WINAPI void wine32a_GetSystemDirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetSystemWow64DirectoryW(LPWSTR path, UINT count)
{
	TRACE("Enter GetSystemWow64DirectoryW\n");
	return pGetSystemWow64DirectoryW(path, count);
}

extern WINAPI void wine32a_GetSystemWow64DirectoryW(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemWow64DirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemWow64DirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetSystemWow64DirectoryA(LPSTR path, UINT count)
{
	TRACE("Enter GetSystemWow64DirectoryA\n");
	return pGetSystemWow64DirectoryA(path, count);
}

extern WINAPI void wine32a_GetSystemWow64DirectoryA(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemWow64DirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemWow64DirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_Wow64EnableWow64FsRedirection(BOOLEAN enable)
{
	TRACE("Enter Wow64EnableWow64FsRedirection\n");
	return pWow64EnableWow64FsRedirection(enable);
}

extern WINAPI void wine32a_Wow64EnableWow64FsRedirection(void);
__ASM_GLOBAL_FUNC(wine32a_Wow64EnableWow64FsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Wow64EnableWow64FsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_NeedCurrentDirectoryForExePathW(LPCWSTR name)
{
	TRACE("Enter NeedCurrentDirectoryForExePathW\n");
	return pNeedCurrentDirectoryForExePathW(name);
}

extern WINAPI void wine32a_NeedCurrentDirectoryForExePathW(void);
__ASM_GLOBAL_FUNC(wine32a_NeedCurrentDirectoryForExePathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NeedCurrentDirectoryForExePathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_NeedCurrentDirectoryForExePathA(LPCSTR name)
{
	TRACE("Enter NeedCurrentDirectoryForExePathA\n");
	return pNeedCurrentDirectoryForExePathA(name);
}

extern WINAPI void wine32a_NeedCurrentDirectoryForExePathA(void);
__ASM_GLOBAL_FUNC(wine32a_NeedCurrentDirectoryForExePathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NeedCurrentDirectoryForExePathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b_wine_get_unix_file_name(LPCWSTR dosW)
{
	TRACE("Enter wine_get_unix_file_name\n");
	return pwine_get_unix_file_name(dosW);
}

extern WINAPI void wine32a_wine_get_unix_file_name(void);
__ASM_GLOBAL_FUNC(wine32a_wine_get_unix_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_get_unix_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR * wine32b_wine_get_dos_file_name(LPCSTR str)
{
	TRACE("Enter wine_get_dos_file_name\n");
	return pwine_get_dos_file_name(str);
}

extern WINAPI void wine32a_wine_get_dos_file_name(void);
__ASM_GLOBAL_FUNC(wine32a_wine_get_dos_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_get_dos_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_CreateSymbolicLinkW(LPCWSTR link, LPCWSTR target, DWORD flags)
{
	TRACE("Enter CreateSymbolicLinkW\n");
	return pCreateSymbolicLinkW(link, target, flags);
}

extern WINAPI void wine32a_CreateSymbolicLinkW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateSymbolicLinkW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateSymbolicLinkW") "\n"
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

extern WINAPI BOOLEAN wine32b_CreateSymbolicLinkA(LPCSTR link, LPCSTR target, DWORD flags)
{
	TRACE("Enter CreateSymbolicLinkA\n");
	return pCreateSymbolicLinkA(link, target, flags);
}

extern WINAPI void wine32a_CreateSymbolicLinkA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateSymbolicLinkA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateSymbolicLinkA") "\n"
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

extern WINAPI BOOL wine32b_CreateHardLinkTransactedA(LPCSTR link, LPCSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction)
{
	TRACE("Enter CreateHardLinkTransactedA\n");
	return pCreateHardLinkTransactedA(link, target, sa, transaction);
}

extern WINAPI void wine32a_CreateHardLinkTransactedA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateHardLinkTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateHardLinkTransactedA") "\n"
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

extern WINAPI BOOL wine32b_CreateHardLinkTransactedW(LPCWSTR link, LPCWSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction)
{
	TRACE("Enter CreateHardLinkTransactedW\n");
	return pCreateHardLinkTransactedW(link, target, sa, transaction);
}

extern WINAPI void wine32a_CreateHardLinkTransactedW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateHardLinkTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateHardLinkTransactedW") "\n"
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

extern WINAPI BOOL wine32b_CheckNameLegalDOS8Dot3A(const char * name, char * oemname, DWORD oemname_len, BOOL * contains_spaces, BOOL * is_legal)
{
	TRACE("Enter CheckNameLegalDOS8Dot3A\n");
	return pCheckNameLegalDOS8Dot3A(name, oemname, oemname_len, contains_spaces, is_legal);
}

extern WINAPI void wine32a_CheckNameLegalDOS8Dot3A(void);
__ASM_GLOBAL_FUNC(wine32a_CheckNameLegalDOS8Dot3A,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckNameLegalDOS8Dot3A") "\n"
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

extern WINAPI BOOL wine32b_CheckNameLegalDOS8Dot3W(const WCHAR * name, char * oemname, DWORD oemname_len, BOOL * contains_spaces_ret, BOOL * is_legal)
{
	TRACE("Enter CheckNameLegalDOS8Dot3W\n");
	return pCheckNameLegalDOS8Dot3W(name, oemname, oemname_len, contains_spaces_ret, is_legal);
}

extern WINAPI void wine32a_CheckNameLegalDOS8Dot3W(void);
__ASM_GLOBAL_FUNC(wine32a_CheckNameLegalDOS8Dot3W,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CheckNameLegalDOS8Dot3W") "\n"
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

extern WINAPI BOOL wine32b_SetSearchPathMode(DWORD flags)
{
	TRACE("Enter SetSearchPathMode\n");
	return pSetSearchPathMode(flags);
}

extern WINAPI void wine32a_SetSearchPathMode(void);
__ASM_GLOBAL_FUNC(wine32a_SetSearchPathMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSearchPathMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOL (*pGetDevicePowerState)(HANDLE hDevice, BOOL * pfOn);
static WINAPI BOOL (*pGetSystemPowerStatus)(LPSYSTEM_POWER_STATUS ps);
static WINAPI BOOL (*pIsSystemResumeAutomatic)(void);
static WINAPI BOOL (*pRequestWakeupLatency)(LATENCY_TIME latency);
static WINAPI BOOL (*pRequestDeviceWakeup)(HANDLE device);
static WINAPI BOOL (*pSetSystemPowerState)(BOOL suspend_or_hibernate, BOOL force_flag);
static WINAPI DWORD (*pSetThreadExecutionState)(EXECUTION_STATE flags);
static WINAPI HANDLE (*pPowerCreateRequest)(REASON_CONTEXT * context);
static WINAPI BOOL (*pPowerSetRequest)(HANDLE request, POWER_REQUEST_TYPE type);
static WINAPI BOOL (*pPowerClearRequest)(HANDLE request, POWER_REQUEST_TYPE type);

extern WINAPI BOOL wine32b_GetDevicePowerState(HANDLE hDevice, BOOL * pfOn)
{
	TRACE("Enter GetDevicePowerState\n");
	return pGetDevicePowerState(hDevice, pfOn);
}

extern WINAPI void wine32a_GetDevicePowerState(void);
__ASM_GLOBAL_FUNC(wine32a_GetDevicePowerState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDevicePowerState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetSystemPowerStatus(LPSYSTEM_POWER_STATUS ps)
{
	TRACE("Enter GetSystemPowerStatus\n");
	return pGetSystemPowerStatus(ps);
}

extern WINAPI void wine32a_GetSystemPowerStatus(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemPowerStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemPowerStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsSystemResumeAutomatic(void)
{
	TRACE("Enter IsSystemResumeAutomatic\n");
	return pIsSystemResumeAutomatic();
}

extern WINAPI void wine32a_IsSystemResumeAutomatic(void);
__ASM_GLOBAL_FUNC(wine32a_IsSystemResumeAutomatic,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsSystemResumeAutomatic") "\n"
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

extern WINAPI BOOL wine32b_RequestWakeupLatency(LATENCY_TIME latency)
{
	TRACE("Enter RequestWakeupLatency\n");
	return pRequestWakeupLatency(latency);
}

extern WINAPI void wine32a_RequestWakeupLatency(void);
__ASM_GLOBAL_FUNC(wine32a_RequestWakeupLatency,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RequestWakeupLatency") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RequestDeviceWakeup(HANDLE device)
{
	TRACE("Enter RequestDeviceWakeup\n");
	return pRequestDeviceWakeup(device);
}

extern WINAPI void wine32a_RequestDeviceWakeup(void);
__ASM_GLOBAL_FUNC(wine32a_RequestDeviceWakeup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RequestDeviceWakeup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetSystemPowerState(BOOL suspend_or_hibernate, BOOL force_flag)
{
	TRACE("Enter SetSystemPowerState\n");
	return pSetSystemPowerState(suspend_or_hibernate, force_flag);
}

extern WINAPI void wine32a_SetSystemPowerState(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemPowerState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemPowerState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_SetThreadExecutionState(EXECUTION_STATE flags)
{
	TRACE("Enter SetThreadExecutionState\n");
	return pSetThreadExecutionState(flags);
}

extern WINAPI void wine32a_SetThreadExecutionState(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadExecutionState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadExecutionState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_PowerCreateRequest(REASON_CONTEXT * context)
{
	TRACE("Enter PowerCreateRequest\n");
	return pPowerCreateRequest(context);
}

extern WINAPI void wine32a_PowerCreateRequest(void);
__ASM_GLOBAL_FUNC(wine32a_PowerCreateRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PowerCreateRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_PowerSetRequest(HANDLE request, POWER_REQUEST_TYPE type)
{
	TRACE("Enter PowerSetRequest\n");
	return pPowerSetRequest(request, type);
}

extern WINAPI void wine32a_PowerSetRequest(void);
__ASM_GLOBAL_FUNC(wine32a_PowerSetRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PowerSetRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_PowerClearRequest(HANDLE request, POWER_REQUEST_TYPE type)
{
	TRACE("Enter PowerClearRequest\n");
	return pPowerClearRequest(request, type);
}

extern WINAPI void wine32a_PowerClearRequest(void);
__ASM_GLOBAL_FUNC(wine32a_PowerClearRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PowerClearRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void * (*p__wine_kernel_init)(void);
static WINAPI BOOL (*pCreateProcessInternalW)(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info, HANDLE * new_token);
static WINAPI BOOL (*pCreateProcessInternalA)(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info, HANDLE * new_token);
static WINAPI BOOL (*pCreateProcessA)(LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessW)(LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessAsUserA)(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessAsUserW)(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info);
static WINAPI UINT (*pWinExec)(LPCSTR lpCmdLine, UINT nCmdShow);
static WINAPI DWORD (*pLoadModule)(LPCSTR name, LPVOID paramBlock);
static WINAPI void (*pExitProcess)(DWORD status);
static WINAPI BOOL (*pGetExitCodeProcess)(HANDLE hProcess, LPDWORD lpExitCode);
static WINAPI DWORD (*pGetProcessFlags)(DWORD processid);
static WINAPI BOOL (*pCloseHandle)(HANDLE handle);
static WINAPI BOOL (*pGetHandleInformation)(HANDLE handle, LPDWORD flags);
static WINAPI BOOL (*pSetHandleInformation)(HANDLE handle, DWORD mask, DWORD flags);
static WINAPI BOOL (*pDuplicateHandle)(HANDLE source_process, HANDLE source, HANDLE dest_process, HANDLE * dest, DWORD access, BOOL inherit, DWORD options);
static WINAPI HANDLE (*pConvertToGlobalHandle)(HANDLE hSrc);
static WINAPI BOOL (*pSetHandleContext)(HANDLE hnd, DWORD context);
static WINAPI DWORD (*pGetHandleContext)(HANDLE hnd);
static WINAPI HANDLE (*pCreateSocketHandle)(void);
static WINAPI BOOL (*pSetProcessAffinityMask)(HANDLE hProcess, DWORD_PTR affmask);
static WINAPI BOOL (*pGetProcessAffinityMask)(HANDLE hProcess, PDWORD_PTR process_mask, PDWORD_PTR system_mask);
static WINAPI DWORD (*pGetProcessVersion)(DWORD pid);
static WINAPI BOOL (*pSetProcessWorkingSetSize)(HANDLE process, SIZE_T minset, SIZE_T maxset);
static WINAPI BOOL (*pK32EmptyWorkingSet)(HANDLE hProcess);
static WINAPI BOOL (*pGetProcessWorkingSetSize)(HANDLE process, SIZE_T * minset, SIZE_T * maxset);
static WINAPI BOOL (*pReadProcessMemory)(HANDLE process, LPCVOID addr, LPVOID buffer, SIZE_T size, SIZE_T * bytes_read);
static WINAPI BOOL (*pWriteProcessMemory)(HANDLE process, LPVOID addr, LPCVOID buffer, SIZE_T size, SIZE_T * bytes_written);
static WINAPI BOOL (*pGetProcessIoCounters)(HANDLE hProcess, PIO_COUNTERS ioc);
static WINAPI BOOL (*pQueryFullProcessImageNameA)(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD pdwSize);
static WINAPI BOOL (*pQueryFullProcessImageNameW)(HANDLE hProcess, DWORD dwFlags, LPWSTR lpExeName, PDWORD pdwSize);
static WINAPI DWORD (*pK32GetProcessImageFileNameA)(HANDLE process, LPSTR file, DWORD size);
static WINAPI DWORD (*pK32GetProcessImageFileNameW)(HANDLE process, LPWSTR file, DWORD size);
static WINAPI BOOL (*pK32EnumProcesses)(DWORD * lpdwProcessIDs, DWORD cb, DWORD * lpcbUsed);
static WINAPI BOOL (*pK32QueryWorkingSet)(HANDLE process, LPVOID buffer, DWORD size);
static WINAPI BOOL (*pK32QueryWorkingSetEx)(HANDLE process, LPVOID buffer, DWORD size);
static WINAPI BOOL (*pK32GetProcessMemoryInfo)(HANDLE process, PPROCESS_MEMORY_COUNTERS pmc, DWORD cb);
static WINAPI BOOL (*pProcessIdToSessionId)(DWORD procid, DWORD * sessionid_ptr);
static WINAPI DWORD (*pRegisterServiceProcess)(DWORD dwProcessId, DWORD dwType);
static WINAPI BOOL (*pGetLogicalProcessorInformation)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer, PDWORD pBufLen);
static WINAPI BOOL (*pGetLogicalProcessorInformationEx)(LOGICAL_PROCESSOR_RELATIONSHIP relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX * buffer, DWORD * len);
static WINAPI BOOL (*pCmdBatNotification)(BOOL bBatchRunning);
static WINAPI HRESULT (*pRegisterApplicationRestart)(PCWSTR pwzCommandLine, DWORD dwFlags);
static WINAPI DWORD (*pWTSGetActiveConsoleSessionId)(void);
static WINAPI DEP_SYSTEM_POLICY_TYPE (*pGetSystemDEPPolicy)(void);
static WINAPI BOOL (*pSetProcessDEPPolicy)(DWORD newDEP);
static WINAPI void (*pApplicationRecoveryFinished)(BOOL success);
static WINAPI HRESULT (*pApplicationRecoveryInProgress)(PBOOL canceled);
static WINAPI HRESULT (*pRegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK callback, PVOID param, DWORD pingint, DWORD flags);
static WINAPI HRESULT (*pGetApplicationRestartSettings)(HANDLE process, WCHAR * cmdline, DWORD * size, DWORD * flags);
static WINAPI BOOL (*pGetNumaHighestNodeNumber)(PULONG highestnode);
static WINAPI BOOL (*pGetNumaNodeProcessorMask)(UCHAR node, PULONGLONG mask);
static WINAPI BOOL (*pGetNumaNodeProcessorMaskEx)(USHORT node, PGROUP_AFFINITY mask);
static WINAPI BOOL (*pGetNumaAvailableMemoryNode)(UCHAR node, PULONGLONG available_bytes);
static WINAPI BOOL (*pGetNumaAvailableMemoryNodeEx)(USHORT node, PULONGLONG available_bytes);
static WINAPI BOOL (*pGetNumaProcessorNode)(UCHAR processor, PUCHAR node);
static WINAPI BOOL (*pGetNumaProcessorNodeEx)(PPROCESSOR_NUMBER processor, PUSHORT node_number);
static WINAPI BOOL (*pGetNumaProximityNode)(ULONG proximity_id, PUCHAR node_number);
static WINAPI BOOL (*pGetNumaProximityNodeEx)(ULONG proximity_id, PUSHORT node_number);
static WINAPI BOOL (*pGetProcessDEPPolicy)(HANDLE process, LPDWORD flags, PBOOL permanent);
static WINAPI void (*pFlushProcessWriteBuffers)(void);
static WINAPI HRESULT (*pUnregisterApplicationRestart)(void);
static WINAPI BOOL (*pCreateUmsCompletionList)(PUMS_COMPLETION_LIST * list);
static WINAPI BOOL (*pCreateUmsThreadContext)(PUMS_CONTEXT * ctx);
static WINAPI BOOL (*pDeleteUmsCompletionList)(PUMS_COMPLETION_LIST list);
static WINAPI BOOL (*pDeleteUmsThreadContext)(PUMS_CONTEXT ctx);
static WINAPI BOOL (*pDequeueUmsCompletionListItems)(void * list, DWORD timeout, PUMS_CONTEXT * ctx);
static WINAPI BOOL (*pEnterUmsSchedulingMode)(UMS_SCHEDULER_STARTUP_INFO * info);
static WINAPI BOOL (*pExecuteUmsThread)(PUMS_CONTEXT ctx);
static WINAPI PUMS_CONTEXT (*pGetCurrentUmsThread)(void);
static WINAPI PUMS_CONTEXT (*pGetNextUmsListItem)(PUMS_CONTEXT ctx);
static WINAPI BOOL (*pGetUmsCompletionListEvent)(PUMS_COMPLETION_LIST list, HANDLE * event);
static WINAPI BOOL (*pQueryUmsThreadInformation)(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void * buf, ULONG length, ULONG * ret_length);
static WINAPI BOOL (*pSetUmsThreadInformation)(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void * buf, ULONG length);
static WINAPI BOOL (*pUmsThreadYield)(void * param);
static WINAPI BOOL (*pBaseFlushAppcompatCache)(void);

extern WINAPI void * wine32b___wine_kernel_init(void)
{
	TRACE("Enter __wine_kernel_init\n");
	return p__wine_kernel_init();
}

extern WINAPI void wine32a___wine_kernel_init(void);
__ASM_GLOBAL_FUNC(wine32a___wine_kernel_init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_kernel_init") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessInternalW(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info, HANDLE * new_token)
{
	TRACE("Enter CreateProcessInternalW\n");
	return pCreateProcessInternalW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
}

extern WINAPI void wine32a_CreateProcessInternalW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessInternalW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessInternalW") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessInternalA(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info, HANDLE * new_token)
{
	TRACE("Enter CreateProcessInternalA\n");
	return pCreateProcessInternalA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
}

extern WINAPI void wine32a_CreateProcessInternalA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessInternalA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessInternalA") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessA(LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info)
{
	TRACE("Enter CreateProcessA\n");
	return pCreateProcessA(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_CreateProcessA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessA") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessW(LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info)
{
	TRACE("Enter CreateProcessW\n");
	return pCreateProcessW(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_CreateProcessW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessW") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessAsUserA(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info)
{
	TRACE("Enter CreateProcessAsUserA\n");
	return pCreateProcessAsUserA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_CreateProcessAsUserA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessAsUserA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessAsUserA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $44, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CreateProcessAsUserW(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info)
{
	TRACE("Enter CreateProcessAsUserW\n");
	return pCreateProcessAsUserW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_CreateProcessAsUserW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessAsUserW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessAsUserW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $44, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_WinExec(LPCSTR lpCmdLine, UINT nCmdShow)
{
	TRACE("Enter WinExec\n");
	return pWinExec(lpCmdLine, nCmdShow);
}

extern WINAPI void wine32a_WinExec(void);
__ASM_GLOBAL_FUNC(wine32a_WinExec,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinExec") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_LoadModule(LPCSTR name, LPVOID paramBlock)
{
	TRACE("Enter LoadModule\n");
	return pLoadModule(name, paramBlock);
}

extern WINAPI void wine32a_LoadModule(void);
__ASM_GLOBAL_FUNC(wine32a_LoadModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LoadModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_ExitProcess(DWORD status)
{
	TRACE("Enter ExitProcess\n");
	return pExitProcess(status);
}

extern WINAPI void wine32a_ExitProcess(void);
__ASM_GLOBAL_FUNC(wine32a_ExitProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExitProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode)
{
	TRACE("Enter GetExitCodeProcess\n");
	return pGetExitCodeProcess(hProcess, lpExitCode);
}

extern WINAPI void wine32a_GetExitCodeProcess(void);
__ASM_GLOBAL_FUNC(wine32a_GetExitCodeProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetExitCodeProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetProcessFlags(DWORD processid)
{
	TRACE("Enter GetProcessFlags\n");
	return pGetProcessFlags(processid);
}

extern WINAPI void wine32a_GetProcessFlags(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CloseHandle(HANDLE handle)
{
	TRACE("Enter CloseHandle\n");
	return pCloseHandle(handle);
}

extern WINAPI void wine32a_CloseHandle(void);
__ASM_GLOBAL_FUNC(wine32a_CloseHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetHandleInformation(HANDLE handle, LPDWORD flags)
{
	TRACE("Enter GetHandleInformation\n");
	return pGetHandleInformation(handle, flags);
}

extern WINAPI void wine32a_GetHandleInformation(void);
__ASM_GLOBAL_FUNC(wine32a_GetHandleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetHandleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetHandleInformation(HANDLE handle, DWORD mask, DWORD flags)
{
	TRACE("Enter SetHandleInformation\n");
	return pSetHandleInformation(handle, mask, flags);
}

extern WINAPI void wine32a_SetHandleInformation(void);
__ASM_GLOBAL_FUNC(wine32a_SetHandleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetHandleInformation") "\n"
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

extern WINAPI BOOL wine32b_DuplicateHandle(HANDLE source_process, HANDLE source, HANDLE dest_process, HANDLE * dest, DWORD access, BOOL inherit, DWORD options)
{
	TRACE("Enter DuplicateHandle\n");
	return pDuplicateHandle(source_process, source, dest_process, dest, access, inherit, options);
}

extern WINAPI void wine32a_DuplicateHandle(void);
__ASM_GLOBAL_FUNC(wine32a_DuplicateHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DuplicateHandle") "\n"
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

extern WINAPI HANDLE wine32b_ConvertToGlobalHandle(HANDLE hSrc)
{
	TRACE("Enter ConvertToGlobalHandle\n");
	return pConvertToGlobalHandle(hSrc);
}

extern WINAPI void wine32a_ConvertToGlobalHandle(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertToGlobalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertToGlobalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetHandleContext(HANDLE hnd, DWORD context)
{
	TRACE("Enter SetHandleContext\n");
	return pSetHandleContext(hnd, context);
}

extern WINAPI void wine32a_SetHandleContext(void);
__ASM_GLOBAL_FUNC(wine32a_SetHandleContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetHandleContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetHandleContext(HANDLE hnd)
{
	TRACE("Enter GetHandleContext\n");
	return pGetHandleContext(hnd);
}

extern WINAPI void wine32a_GetHandleContext(void);
__ASM_GLOBAL_FUNC(wine32a_GetHandleContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetHandleContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_CreateSocketHandle(void)
{
	TRACE("Enter CreateSocketHandle\n");
	return pCreateSocketHandle();
}

extern WINAPI void wine32a_CreateSocketHandle(void);
__ASM_GLOBAL_FUNC(wine32a_CreateSocketHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateSocketHandle") "\n"
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

extern WINAPI BOOL wine32b_SetProcessAffinityMask(HANDLE hProcess, DWORD_PTR affmask)
{
	TRACE("Enter SetProcessAffinityMask\n");
	return pSetProcessAffinityMask(hProcess, affmask);
}

extern WINAPI void wine32a_SetProcessAffinityMask(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessAffinityMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessAffinityMask(HANDLE hProcess, PDWORD_PTR process_mask, PDWORD_PTR system_mask)
{
	TRACE("Enter GetProcessAffinityMask\n");
	return pGetProcessAffinityMask(hProcess, process_mask, system_mask);
}

extern WINAPI void wine32a_GetProcessAffinityMask(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessAffinityMask") "\n"
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

extern WINAPI DWORD wine32b_GetProcessVersion(DWORD pid)
{
	TRACE("Enter GetProcessVersion\n");
	return pGetProcessVersion(pid);
}

extern WINAPI void wine32a_GetProcessVersion(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessVersion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessVersion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetProcessWorkingSetSize(HANDLE process, SIZE_T minset, SIZE_T maxset)
{
	TRACE("Enter SetProcessWorkingSetSize\n");
	return pSetProcessWorkingSetSize(process, minset, maxset);
}

extern WINAPI void wine32a_SetProcessWorkingSetSize(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessWorkingSetSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessWorkingSetSize") "\n"
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

extern WINAPI BOOL wine32b_K32EmptyWorkingSet(HANDLE hProcess)
{
	TRACE("Enter K32EmptyWorkingSet\n");
	return pK32EmptyWorkingSet(hProcess);
}

extern WINAPI void wine32a_K32EmptyWorkingSet(void);
__ASM_GLOBAL_FUNC(wine32a_K32EmptyWorkingSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EmptyWorkingSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessWorkingSetSize(HANDLE process, SIZE_T * minset, SIZE_T * maxset)
{
	TRACE("Enter GetProcessWorkingSetSize\n");
	return pGetProcessWorkingSetSize(process, minset, maxset);
}

extern WINAPI void wine32a_GetProcessWorkingSetSize(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessWorkingSetSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessWorkingSetSize") "\n"
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

extern WINAPI BOOL wine32b_ReadProcessMemory(HANDLE process, LPCVOID addr, LPVOID buffer, SIZE_T size, SIZE_T * bytes_read)
{
	TRACE("Enter ReadProcessMemory\n");
	return pReadProcessMemory(process, addr, buffer, size, bytes_read);
}

extern WINAPI void wine32a_ReadProcessMemory(void);
__ASM_GLOBAL_FUNC(wine32a_ReadProcessMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadProcessMemory") "\n"
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

extern WINAPI BOOL wine32b_WriteProcessMemory(HANDLE process, LPVOID addr, LPCVOID buffer, SIZE_T size, SIZE_T * bytes_written)
{
	TRACE("Enter WriteProcessMemory\n");
	return pWriteProcessMemory(process, addr, buffer, size, bytes_written);
}

extern WINAPI void wine32a_WriteProcessMemory(void);
__ASM_GLOBAL_FUNC(wine32a_WriteProcessMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteProcessMemory") "\n"
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

extern WINAPI BOOL wine32b_GetProcessIoCounters(HANDLE hProcess, PIO_COUNTERS ioc)
{
	TRACE("Enter GetProcessIoCounters\n");
	return pGetProcessIoCounters(hProcess, ioc);
}

extern WINAPI void wine32a_GetProcessIoCounters(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessIoCounters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessIoCounters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryFullProcessImageNameA(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD pdwSize)
{
	TRACE("Enter QueryFullProcessImageNameA\n");
	return pQueryFullProcessImageNameA(hProcess, dwFlags, lpExeName, pdwSize);
}

extern WINAPI void wine32a_QueryFullProcessImageNameA(void);
__ASM_GLOBAL_FUNC(wine32a_QueryFullProcessImageNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryFullProcessImageNameA") "\n"
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

extern WINAPI BOOL wine32b_QueryFullProcessImageNameW(HANDLE hProcess, DWORD dwFlags, LPWSTR lpExeName, PDWORD pdwSize)
{
	TRACE("Enter QueryFullProcessImageNameW\n");
	return pQueryFullProcessImageNameW(hProcess, dwFlags, lpExeName, pdwSize);
}

extern WINAPI void wine32a_QueryFullProcessImageNameW(void);
__ASM_GLOBAL_FUNC(wine32a_QueryFullProcessImageNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryFullProcessImageNameW") "\n"
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

extern WINAPI DWORD wine32b_K32GetProcessImageFileNameA(HANDLE process, LPSTR file, DWORD size)
{
	TRACE("Enter K32GetProcessImageFileNameA\n");
	return pK32GetProcessImageFileNameA(process, file, size);
}

extern WINAPI void wine32a_K32GetProcessImageFileNameA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetProcessImageFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetProcessImageFileNameA") "\n"
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

extern WINAPI DWORD wine32b_K32GetProcessImageFileNameW(HANDLE process, LPWSTR file, DWORD size)
{
	TRACE("Enter K32GetProcessImageFileNameW\n");
	return pK32GetProcessImageFileNameW(process, file, size);
}

extern WINAPI void wine32a_K32GetProcessImageFileNameW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetProcessImageFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetProcessImageFileNameW") "\n"
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

extern WINAPI BOOL wine32b_K32EnumProcesses(DWORD * lpdwProcessIDs, DWORD cb, DWORD * lpcbUsed)
{
	TRACE("Enter K32EnumProcesses\n");
	return pK32EnumProcesses(lpdwProcessIDs, cb, lpcbUsed);
}

extern WINAPI void wine32a_K32EnumProcesses(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumProcesses,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumProcesses") "\n"
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

extern WINAPI BOOL wine32b_K32QueryWorkingSet(HANDLE process, LPVOID buffer, DWORD size)
{
	TRACE("Enter K32QueryWorkingSet\n");
	return pK32QueryWorkingSet(process, buffer, size);
}

extern WINAPI void wine32a_K32QueryWorkingSet(void);
__ASM_GLOBAL_FUNC(wine32a_K32QueryWorkingSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32QueryWorkingSet") "\n"
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

extern WINAPI BOOL wine32b_K32QueryWorkingSetEx(HANDLE process, LPVOID buffer, DWORD size)
{
	TRACE("Enter K32QueryWorkingSetEx\n");
	return pK32QueryWorkingSetEx(process, buffer, size);
}

extern WINAPI void wine32a_K32QueryWorkingSetEx(void);
__ASM_GLOBAL_FUNC(wine32a_K32QueryWorkingSetEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32QueryWorkingSetEx") "\n"
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

extern WINAPI BOOL wine32b_K32GetProcessMemoryInfo(HANDLE process, PPROCESS_MEMORY_COUNTERS pmc, DWORD cb)
{
	TRACE("Enter K32GetProcessMemoryInfo\n");
	return pK32GetProcessMemoryInfo(process, pmc, cb);
}

extern WINAPI void wine32a_K32GetProcessMemoryInfo(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetProcessMemoryInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetProcessMemoryInfo") "\n"
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

extern WINAPI BOOL wine32b_ProcessIdToSessionId(DWORD procid, DWORD * sessionid_ptr)
{
	TRACE("Enter ProcessIdToSessionId\n");
	return pProcessIdToSessionId(procid, sessionid_ptr);
}

extern WINAPI void wine32a_ProcessIdToSessionId(void);
__ASM_GLOBAL_FUNC(wine32a_ProcessIdToSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ProcessIdToSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RegisterServiceProcess(DWORD dwProcessId, DWORD dwType)
{
	TRACE("Enter RegisterServiceProcess\n");
	return pRegisterServiceProcess(dwProcessId, dwType);
}

extern WINAPI void wine32a_RegisterServiceProcess(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterServiceProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterServiceProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer, PDWORD pBufLen)
{
	TRACE("Enter GetLogicalProcessorInformation\n");
	return pGetLogicalProcessorInformation(buffer, pBufLen);
}

extern WINAPI void wine32a_GetLogicalProcessorInformation(void);
__ASM_GLOBAL_FUNC(wine32a_GetLogicalProcessorInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLogicalProcessorInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX * buffer, DWORD * len)
{
	TRACE("Enter GetLogicalProcessorInformationEx\n");
	return pGetLogicalProcessorInformationEx(relationship, buffer, len);
}

extern WINAPI void wine32a_GetLogicalProcessorInformationEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetLogicalProcessorInformationEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLogicalProcessorInformationEx") "\n"
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

extern WINAPI BOOL wine32b_CmdBatNotification(BOOL bBatchRunning)
{
	TRACE("Enter CmdBatNotification\n");
	return pCmdBatNotification(bBatchRunning);
}

extern WINAPI void wine32a_CmdBatNotification(void);
__ASM_GLOBAL_FUNC(wine32a_CmdBatNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CmdBatNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_RegisterApplicationRestart(PCWSTR pwzCommandLine, DWORD dwFlags)
{
	TRACE("Enter RegisterApplicationRestart\n");
	return pRegisterApplicationRestart(pwzCommandLine, dwFlags);
}

extern WINAPI void wine32a_RegisterApplicationRestart(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterApplicationRestart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterApplicationRestart") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_WTSGetActiveConsoleSessionId(void)
{
	TRACE("Enter WTSGetActiveConsoleSessionId\n");
	return pWTSGetActiveConsoleSessionId();
}

extern WINAPI void wine32a_WTSGetActiveConsoleSessionId(void);
__ASM_GLOBAL_FUNC(wine32a_WTSGetActiveConsoleSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WTSGetActiveConsoleSessionId") "\n"
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

extern WINAPI DEP_SYSTEM_POLICY_TYPE wine32b_GetSystemDEPPolicy(void)
{
	TRACE("Enter GetSystemDEPPolicy\n");
	return pGetSystemDEPPolicy();
}

extern WINAPI void wine32a_GetSystemDEPPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemDEPPolicy") "\n"
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

extern WINAPI BOOL wine32b_SetProcessDEPPolicy(DWORD newDEP)
{
	TRACE("Enter SetProcessDEPPolicy\n");
	return pSetProcessDEPPolicy(newDEP);
}

extern WINAPI void wine32a_SetProcessDEPPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_SetProcessDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetProcessDEPPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_ApplicationRecoveryFinished(BOOL success)
{
	TRACE("Enter ApplicationRecoveryFinished\n");
	return pApplicationRecoveryFinished(success);
}

extern WINAPI void wine32a_ApplicationRecoveryFinished(void);
__ASM_GLOBAL_FUNC(wine32a_ApplicationRecoveryFinished,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ApplicationRecoveryFinished") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_ApplicationRecoveryInProgress(PBOOL canceled)
{
	TRACE("Enter ApplicationRecoveryInProgress\n");
	return pApplicationRecoveryInProgress(canceled);
}

extern WINAPI void wine32a_ApplicationRecoveryInProgress(void);
__ASM_GLOBAL_FUNC(wine32a_ApplicationRecoveryInProgress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ApplicationRecoveryInProgress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK callback, PVOID param, DWORD pingint, DWORD flags)
{
	TRACE("Enter RegisterApplicationRecoveryCallback\n");
	return pRegisterApplicationRecoveryCallback(callback, param, pingint, flags);
}

extern WINAPI void wine32a_RegisterApplicationRecoveryCallback(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterApplicationRecoveryCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterApplicationRecoveryCallback") "\n"
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

extern WINAPI HRESULT wine32b_GetApplicationRestartSettings(HANDLE process, WCHAR * cmdline, DWORD * size, DWORD * flags)
{
	TRACE("Enter GetApplicationRestartSettings\n");
	return pGetApplicationRestartSettings(process, cmdline, size, flags);
}

extern WINAPI void wine32a_GetApplicationRestartSettings(void);
__ASM_GLOBAL_FUNC(wine32a_GetApplicationRestartSettings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetApplicationRestartSettings") "\n"
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

extern WINAPI BOOL wine32b_GetNumaHighestNodeNumber(PULONG highestnode)
{
	TRACE("Enter GetNumaHighestNodeNumber\n");
	return pGetNumaHighestNodeNumber(highestnode);
}

extern WINAPI void wine32a_GetNumaHighestNodeNumber(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaHighestNodeNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaHighestNodeNumber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaNodeProcessorMask(UCHAR node, PULONGLONG mask)
{
	TRACE("Enter GetNumaNodeProcessorMask\n");
	return pGetNumaNodeProcessorMask(node, mask);
}

extern WINAPI void wine32a_GetNumaNodeProcessorMask(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaNodeProcessorMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaNodeProcessorMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaNodeProcessorMaskEx(USHORT node, PGROUP_AFFINITY mask)
{
	TRACE("Enter GetNumaNodeProcessorMaskEx\n");
	return pGetNumaNodeProcessorMaskEx(node, mask);
}

extern WINAPI void wine32a_GetNumaNodeProcessorMaskEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaNodeProcessorMaskEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaNodeProcessorMaskEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaAvailableMemoryNode(UCHAR node, PULONGLONG available_bytes)
{
	TRACE("Enter GetNumaAvailableMemoryNode\n");
	return pGetNumaAvailableMemoryNode(node, available_bytes);
}

extern WINAPI void wine32a_GetNumaAvailableMemoryNode(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaAvailableMemoryNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaAvailableMemoryNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaAvailableMemoryNodeEx(USHORT node, PULONGLONG available_bytes)
{
	TRACE("Enter GetNumaAvailableMemoryNodeEx\n");
	return pGetNumaAvailableMemoryNodeEx(node, available_bytes);
}

extern WINAPI void wine32a_GetNumaAvailableMemoryNodeEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaAvailableMemoryNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaAvailableMemoryNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaProcessorNode(UCHAR processor, PUCHAR node)
{
	TRACE("Enter GetNumaProcessorNode\n");
	return pGetNumaProcessorNode(processor, node);
}

extern WINAPI void wine32a_GetNumaProcessorNode(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaProcessorNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaProcessorNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaProcessorNodeEx(PPROCESSOR_NUMBER processor, PUSHORT node_number)
{
	TRACE("Enter GetNumaProcessorNodeEx\n");
	return pGetNumaProcessorNodeEx(processor, node_number);
}

extern WINAPI void wine32a_GetNumaProcessorNodeEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaProcessorNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaProcessorNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaProximityNode(ULONG proximity_id, PUCHAR node_number)
{
	TRACE("Enter GetNumaProximityNode\n");
	return pGetNumaProximityNode(proximity_id, node_number);
}

extern WINAPI void wine32a_GetNumaProximityNode(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaProximityNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaProximityNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNumaProximityNodeEx(ULONG proximity_id, PUSHORT node_number)
{
	TRACE("Enter GetNumaProximityNodeEx\n");
	return pGetNumaProximityNodeEx(proximity_id, node_number);
}

extern WINAPI void wine32a_GetNumaProximityNodeEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumaProximityNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumaProximityNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessDEPPolicy(HANDLE process, LPDWORD flags, PBOOL permanent)
{
	TRACE("Enter GetProcessDEPPolicy\n");
	return pGetProcessDEPPolicy(process, flags, permanent);
}

extern WINAPI void wine32a_GetProcessDEPPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessDEPPolicy") "\n"
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

extern WINAPI void wine32b_FlushProcessWriteBuffers(void)
{
	TRACE("Enter FlushProcessWriteBuffers\n");
	return pFlushProcessWriteBuffers();
}

extern WINAPI void wine32a_FlushProcessWriteBuffers(void);
__ASM_GLOBAL_FUNC(wine32a_FlushProcessWriteBuffers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlushProcessWriteBuffers") "\n"
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

extern WINAPI HRESULT wine32b_UnregisterApplicationRestart(void)
{
	TRACE("Enter UnregisterApplicationRestart\n");
	return pUnregisterApplicationRestart();
}

extern WINAPI void wine32a_UnregisterApplicationRestart(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterApplicationRestart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterApplicationRestart") "\n"
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

extern WINAPI BOOL wine32b_CreateUmsCompletionList(PUMS_COMPLETION_LIST * list)
{
	TRACE("Enter CreateUmsCompletionList\n");
	return pCreateUmsCompletionList(list);
}

extern WINAPI void wine32a_CreateUmsCompletionList(void);
__ASM_GLOBAL_FUNC(wine32a_CreateUmsCompletionList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateUmsCompletionList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CreateUmsThreadContext(PUMS_CONTEXT * ctx)
{
	TRACE("Enter CreateUmsThreadContext\n");
	return pCreateUmsThreadContext(ctx);
}

extern WINAPI void wine32a_CreateUmsThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_CreateUmsThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateUmsThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteUmsCompletionList(PUMS_COMPLETION_LIST list)
{
	TRACE("Enter DeleteUmsCompletionList\n");
	return pDeleteUmsCompletionList(list);
}

extern WINAPI void wine32a_DeleteUmsCompletionList(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteUmsCompletionList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteUmsCompletionList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteUmsThreadContext(PUMS_CONTEXT ctx)
{
	TRACE("Enter DeleteUmsThreadContext\n");
	return pDeleteUmsThreadContext(ctx);
}

extern WINAPI void wine32a_DeleteUmsThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteUmsThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteUmsThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DequeueUmsCompletionListItems(void * list, DWORD timeout, PUMS_CONTEXT * ctx)
{
	TRACE("Enter DequeueUmsCompletionListItems\n");
	return pDequeueUmsCompletionListItems(list, timeout, ctx);
}

extern WINAPI void wine32a_DequeueUmsCompletionListItems(void);
__ASM_GLOBAL_FUNC(wine32a_DequeueUmsCompletionListItems,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DequeueUmsCompletionListItems") "\n"
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

extern WINAPI BOOL wine32b_EnterUmsSchedulingMode(UMS_SCHEDULER_STARTUP_INFO * info)
{
	TRACE("Enter EnterUmsSchedulingMode\n");
	return pEnterUmsSchedulingMode(info);
}

extern WINAPI void wine32a_EnterUmsSchedulingMode(void);
__ASM_GLOBAL_FUNC(wine32a_EnterUmsSchedulingMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnterUmsSchedulingMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ExecuteUmsThread(PUMS_CONTEXT ctx)
{
	TRACE("Enter ExecuteUmsThread\n");
	return pExecuteUmsThread(ctx);
}

extern WINAPI void wine32a_ExecuteUmsThread(void);
__ASM_GLOBAL_FUNC(wine32a_ExecuteUmsThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ExecuteUmsThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PUMS_CONTEXT wine32b_GetCurrentUmsThread(void)
{
	TRACE("Enter GetCurrentUmsThread\n");
	return pGetCurrentUmsThread();
}

extern WINAPI void wine32a_GetCurrentUmsThread(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentUmsThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentUmsThread") "\n"
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

extern WINAPI PUMS_CONTEXT wine32b_GetNextUmsListItem(PUMS_CONTEXT ctx)
{
	TRACE("Enter GetNextUmsListItem\n");
	return pGetNextUmsListItem(ctx);
}

extern WINAPI void wine32a_GetNextUmsListItem(void);
__ASM_GLOBAL_FUNC(wine32a_GetNextUmsListItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNextUmsListItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetUmsCompletionListEvent(PUMS_COMPLETION_LIST list, HANDLE * event)
{
	TRACE("Enter GetUmsCompletionListEvent\n");
	return pGetUmsCompletionListEvent(list, event);
}

extern WINAPI void wine32a_GetUmsCompletionListEvent(void);
__ASM_GLOBAL_FUNC(wine32a_GetUmsCompletionListEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUmsCompletionListEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryUmsThreadInformation(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void * buf, ULONG length, ULONG * ret_length)
{
	TRACE("Enter QueryUmsThreadInformation\n");
	return pQueryUmsThreadInformation(ctx, class, buf, length, ret_length);
}

extern WINAPI void wine32a_QueryUmsThreadInformation(void);
__ASM_GLOBAL_FUNC(wine32a_QueryUmsThreadInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryUmsThreadInformation") "\n"
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

extern WINAPI BOOL wine32b_SetUmsThreadInformation(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void * buf, ULONG length)
{
	TRACE("Enter SetUmsThreadInformation\n");
	return pSetUmsThreadInformation(ctx, class, buf, length);
}

extern WINAPI void wine32a_SetUmsThreadInformation(void);
__ASM_GLOBAL_FUNC(wine32a_SetUmsThreadInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetUmsThreadInformation") "\n"
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

extern WINAPI BOOL wine32b_UmsThreadYield(void * param)
{
	TRACE("Enter UmsThreadYield\n");
	return pUmsThreadYield(param);
}

extern WINAPI void wine32a_UmsThreadYield(void);
__ASM_GLOBAL_FUNC(wine32a_UmsThreadYield,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UmsThreadYield") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_BaseFlushAppcompatCache(void)
{
	TRACE("Enter BaseFlushAppcompatCache\n");
	return pBaseFlushAppcompatCache();
}

extern WINAPI void wine32a_BaseFlushAppcompatCache(void);
__ASM_GLOBAL_FUNC(wine32a_BaseFlushAppcompatCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BaseFlushAppcompatCache") "\n"
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

static WINAPI UINT (*pGetProfileIntA)(LPCSTR section, LPCSTR entry, INT def_val);
static WINAPI UINT (*pGetProfileIntW)(LPCWSTR section, LPCWSTR entry, INT def_val);
static WINAPI INT (*pGetPrivateProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len, LPCWSTR filename);
static WINAPI INT (*pGetPrivateProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len, LPCSTR filename);
static WINAPI INT (*pGetProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len);
static WINAPI INT (*pGetProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len);
static WINAPI BOOL (*pWriteProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR string);
static WINAPI BOOL (*pWriteProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR string);
static WINAPI UINT (*pGetPrivateProfileIntW)(LPCWSTR section, LPCWSTR entry, INT def_val, LPCWSTR filename);
static WINAPI UINT (*pGetPrivateProfileIntA)(LPCSTR section, LPCSTR entry, INT def_val, LPCSTR filename);
static WINAPI INT (*pGetPrivateProfileSectionW)(LPCWSTR section, LPWSTR buffer, DWORD len, LPCWSTR filename);
static WINAPI INT (*pGetPrivateProfileSectionA)(LPCSTR section, LPSTR buffer, DWORD len, LPCSTR filename);
static WINAPI INT (*pGetProfileSectionA)(LPCSTR section, LPSTR buffer, DWORD len);
static WINAPI INT (*pGetProfileSectionW)(LPCWSTR section, LPWSTR buffer, DWORD len);
static WINAPI BOOL (*pWritePrivateProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR string, LPCWSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR string, LPCSTR filename);
static WINAPI BOOL (*pWritePrivateProfileSectionW)(LPCWSTR section, LPCWSTR string, LPCWSTR filename);
static WINAPI BOOL (*pWritePrivateProfileSectionA)(LPCSTR section, LPCSTR string, LPCSTR filename);
static WINAPI BOOL (*pWriteProfileSectionA)(LPCSTR section, LPCSTR keys_n_values);
static WINAPI BOOL (*pWriteProfileSectionW)(LPCWSTR section, LPCWSTR keys_n_values);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesW)(LPWSTR buffer, DWORD size, LPCWSTR filename);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesA)(LPSTR buffer, DWORD size, LPCSTR filename);
static WINAPI BOOL (*pGetPrivateProfileStructW)(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT len, LPCWSTR filename);
static WINAPI BOOL (*pGetPrivateProfileStructA)(LPCSTR section, LPCSTR key, LPVOID buffer, UINT len, LPCSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStructW)(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT bufsize, LPCWSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStructA)(LPCSTR section, LPCSTR key, LPVOID buf, UINT bufsize, LPCSTR filename);
static WINAPI BOOL (*pOpenProfileUserMapping)(void);
static WINAPI BOOL (*pCloseProfileUserMapping)(void);

extern WINAPI UINT wine32b_GetProfileIntA(LPCSTR section, LPCSTR entry, INT def_val)
{
	TRACE("Enter GetProfileIntA\n");
	return pGetProfileIntA(section, entry, def_val);
}

extern WINAPI void wine32a_GetProfileIntA(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileIntA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileIntA") "\n"
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

extern WINAPI UINT wine32b_GetProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val)
{
	TRACE("Enter GetProfileIntW\n");
	return pGetProfileIntW(section, entry, def_val);
}

extern WINAPI void wine32a_GetProfileIntW(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileIntW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileIntW") "\n"
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

extern WINAPI INT wine32b_GetPrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len, LPCWSTR filename)
{
	TRACE("Enter GetPrivateProfileStringW\n");
	return pGetPrivateProfileStringW(section, entry, def_val, buffer, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileStringW") "\n"
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

extern WINAPI INT wine32b_GetPrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len, LPCSTR filename)
{
	TRACE("Enter GetPrivateProfileStringA\n");
	return pGetPrivateProfileStringA(section, entry, def_val, buffer, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileStringA") "\n"
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

extern WINAPI INT wine32b_GetProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len)
{
	TRACE("Enter GetProfileStringA\n");
	return pGetProfileStringA(section, entry, def_val, buffer, len);
}

extern WINAPI void wine32a_GetProfileStringA(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileStringA") "\n"
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

extern WINAPI INT wine32b_GetProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len)
{
	TRACE("Enter GetProfileStringW\n");
	return pGetProfileStringW(section, entry, def_val, buffer, len);
}

extern WINAPI void wine32a_GetProfileStringW(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileStringW") "\n"
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

extern WINAPI BOOL wine32b_WriteProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string)
{
	TRACE("Enter WriteProfileStringA\n");
	return pWriteProfileStringA(section, entry, string);
}

extern WINAPI void wine32a_WriteProfileStringA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteProfileStringA") "\n"
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

extern WINAPI BOOL wine32b_WriteProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string)
{
	TRACE("Enter WriteProfileStringW\n");
	return pWriteProfileStringW(section, entry, string);
}

extern WINAPI void wine32a_WriteProfileStringW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteProfileStringW") "\n"
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

extern WINAPI UINT wine32b_GetPrivateProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val, LPCWSTR filename)
{
	TRACE("Enter GetPrivateProfileIntW\n");
	return pGetPrivateProfileIntW(section, entry, def_val, filename);
}

extern WINAPI void wine32a_GetPrivateProfileIntW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileIntW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileIntW") "\n"
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

extern WINAPI UINT wine32b_GetPrivateProfileIntA(LPCSTR section, LPCSTR entry, INT def_val, LPCSTR filename)
{
	TRACE("Enter GetPrivateProfileIntA\n");
	return pGetPrivateProfileIntA(section, entry, def_val, filename);
}

extern WINAPI void wine32a_GetPrivateProfileIntA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileIntA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileIntA") "\n"
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

extern WINAPI INT wine32b_GetPrivateProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len, LPCWSTR filename)
{
	TRACE("Enter GetPrivateProfileSectionW\n");
	return pGetPrivateProfileSectionW(section, buffer, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileSectionW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileSectionW") "\n"
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

extern WINAPI INT wine32b_GetPrivateProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len, LPCSTR filename)
{
	TRACE("Enter GetPrivateProfileSectionA\n");
	return pGetPrivateProfileSectionA(section, buffer, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileSectionA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileSectionA") "\n"
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

extern WINAPI INT wine32b_GetProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len)
{
	TRACE("Enter GetProfileSectionA\n");
	return pGetProfileSectionA(section, buffer, len);
}

extern WINAPI void wine32a_GetProfileSectionA(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileSectionA") "\n"
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

extern WINAPI INT wine32b_GetProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len)
{
	TRACE("Enter GetProfileSectionW\n");
	return pGetProfileSectionW(section, buffer, len);
}

extern WINAPI void wine32a_GetProfileSectionW(void);
__ASM_GLOBAL_FUNC(wine32a_GetProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProfileSectionW") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string, LPCWSTR filename)
{
	TRACE("Enter WritePrivateProfileStringW\n");
	return pWritePrivateProfileStringW(section, entry, string, filename);
}

extern WINAPI void wine32a_WritePrivateProfileStringW(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileStringW") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string, LPCSTR filename)
{
	TRACE("Enter WritePrivateProfileStringA\n");
	return pWritePrivateProfileStringA(section, entry, string, filename);
}

extern WINAPI void wine32a_WritePrivateProfileStringA(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileStringA") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileSectionW(LPCWSTR section, LPCWSTR string, LPCWSTR filename)
{
	TRACE("Enter WritePrivateProfileSectionW\n");
	return pWritePrivateProfileSectionW(section, string, filename);
}

extern WINAPI void wine32a_WritePrivateProfileSectionW(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileSectionW") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileSectionA(LPCSTR section, LPCSTR string, LPCSTR filename)
{
	TRACE("Enter WritePrivateProfileSectionA\n");
	return pWritePrivateProfileSectionA(section, string, filename);
}

extern WINAPI void wine32a_WritePrivateProfileSectionA(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileSectionA") "\n"
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

extern WINAPI BOOL wine32b_WriteProfileSectionA(LPCSTR section, LPCSTR keys_n_values)
{
	TRACE("Enter WriteProfileSectionA\n");
	return pWriteProfileSectionA(section, keys_n_values);
}

extern WINAPI void wine32a_WriteProfileSectionA(void);
__ASM_GLOBAL_FUNC(wine32a_WriteProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteProfileSectionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_WriteProfileSectionW(LPCWSTR section, LPCWSTR keys_n_values)
{
	TRACE("Enter WriteProfileSectionW\n");
	return pWriteProfileSectionW(section, keys_n_values);
}

extern WINAPI void wine32a_WriteProfileSectionW(void);
__ASM_GLOBAL_FUNC(wine32a_WriteProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteProfileSectionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetPrivateProfileSectionNamesW(LPWSTR buffer, DWORD size, LPCWSTR filename)
{
	TRACE("Enter GetPrivateProfileSectionNamesW\n");
	return pGetPrivateProfileSectionNamesW(buffer, size, filename);
}

extern WINAPI void wine32a_GetPrivateProfileSectionNamesW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileSectionNamesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileSectionNamesW") "\n"
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

extern WINAPI DWORD wine32b_GetPrivateProfileSectionNamesA(LPSTR buffer, DWORD size, LPCSTR filename)
{
	TRACE("Enter GetPrivateProfileSectionNamesA\n");
	return pGetPrivateProfileSectionNamesA(buffer, size, filename);
}

extern WINAPI void wine32a_GetPrivateProfileSectionNamesA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileSectionNamesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileSectionNamesA") "\n"
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

extern WINAPI BOOL wine32b_GetPrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT len, LPCWSTR filename)
{
	TRACE("Enter GetPrivateProfileStructW\n");
	return pGetPrivateProfileStructW(section, key, buf, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileStructW(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileStructW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileStructW") "\n"
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

extern WINAPI BOOL wine32b_GetPrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buffer, UINT len, LPCSTR filename)
{
	TRACE("Enter GetPrivateProfileStructA\n");
	return pGetPrivateProfileStructA(section, key, buffer, len, filename);
}

extern WINAPI void wine32a_GetPrivateProfileStructA(void);
__ASM_GLOBAL_FUNC(wine32a_GetPrivateProfileStructA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPrivateProfileStructA") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT bufsize, LPCWSTR filename)
{
	TRACE("Enter WritePrivateProfileStructW\n");
	return pWritePrivateProfileStructW(section, key, buf, bufsize, filename);
}

extern WINAPI void wine32a_WritePrivateProfileStructW(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileStructW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileStructW") "\n"
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

extern WINAPI BOOL wine32b_WritePrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buf, UINT bufsize, LPCSTR filename)
{
	TRACE("Enter WritePrivateProfileStructA\n");
	return pWritePrivateProfileStructA(section, key, buf, bufsize, filename);
}

extern WINAPI void wine32a_WritePrivateProfileStructA(void);
__ASM_GLOBAL_FUNC(wine32a_WritePrivateProfileStructA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WritePrivateProfileStructA") "\n"
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

extern WINAPI BOOL wine32b_OpenProfileUserMapping(void)
{
	TRACE("Enter OpenProfileUserMapping\n");
	return pOpenProfileUserMapping();
}

extern WINAPI void wine32a_OpenProfileUserMapping(void);
__ASM_GLOBAL_FUNC(wine32a_OpenProfileUserMapping,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenProfileUserMapping") "\n"
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

extern WINAPI BOOL wine32b_CloseProfileUserMapping(void)
{
	TRACE("Enter CloseProfileUserMapping\n");
	return pCloseProfileUserMapping();
}

extern WINAPI void wine32a_CloseProfileUserMapping(void);
__ASM_GLOBAL_FUNC(wine32a_CloseProfileUserMapping,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseProfileUserMapping") "\n"
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

static WINAPI HRSRC (*pFindResourceExA)(HMODULE module, LPCSTR type, LPCSTR name, WORD lang);
static WINAPI HRSRC (*pFindResourceA)(HMODULE hModule, LPCSTR name, LPCSTR type);
static WINAPI BOOL (*pEnumResourceTypesA)(HMODULE hmod, ENUMRESTYPEPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceTypesW)(HMODULE hmod, ENUMRESTYPEPROCW lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceNamesA)(HMODULE hmod, LPCSTR type, ENUMRESNAMEPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceLanguagesA)(HMODULE hmod, LPCSTR type, LPCSTR name, ENUMRESLANGPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceLanguagesW)(HMODULE hmod, LPCWSTR type, LPCWSTR name, ENUMRESLANGPROCW lpfun, LONG_PTR lparam);
static WINAPI HANDLE (*pBeginUpdateResourceW)(LPCWSTR pFileName, BOOL bDeleteExistingResources);
static WINAPI HANDLE (*pBeginUpdateResourceA)(LPCSTR pFileName, BOOL bDeleteExistingResources);
static WINAPI BOOL (*pEndUpdateResourceW)(HANDLE hUpdate, BOOL fDiscard);
static WINAPI BOOL (*pEndUpdateResourceA)(HANDLE hUpdate, BOOL fDiscard);
static WINAPI BOOL (*pUpdateResourceW)(HANDLE hUpdate, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData);
static WINAPI BOOL (*pUpdateResourceA)(HANDLE hUpdate, LPCSTR lpType, LPCSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData);

extern WINAPI HRSRC wine32b_FindResourceExA(HMODULE module, LPCSTR type, LPCSTR name, WORD lang)
{
	TRACE("Enter FindResourceExA\n");
	return pFindResourceExA(module, type, name, lang);
}

extern WINAPI void wine32a_FindResourceExA(void);
__ASM_GLOBAL_FUNC(wine32a_FindResourceExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindResourceExA") "\n"
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

extern WINAPI HRSRC wine32b_FindResourceA(HMODULE hModule, LPCSTR name, LPCSTR type)
{
	TRACE("Enter FindResourceA\n");
	return pFindResourceA(hModule, name, type);
}

extern WINAPI void wine32a_FindResourceA(void);
__ASM_GLOBAL_FUNC(wine32a_FindResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindResourceA") "\n"
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

extern WINAPI BOOL wine32b_EnumResourceTypesA(HMODULE hmod, ENUMRESTYPEPROCA lpfun, LONG_PTR lparam)
{
	TRACE("Enter EnumResourceTypesA\n");
	return pEnumResourceTypesA(hmod, lpfun, lparam);
}

extern WINAPI void wine32a_EnumResourceTypesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumResourceTypesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumResourceTypesA") "\n"
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

extern WINAPI BOOL wine32b_EnumResourceTypesW(HMODULE hmod, ENUMRESTYPEPROCW lpfun, LONG_PTR lparam)
{
	TRACE("Enter EnumResourceTypesW\n");
	return pEnumResourceTypesW(hmod, lpfun, lparam);
}

extern WINAPI void wine32a_EnumResourceTypesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumResourceTypesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumResourceTypesW") "\n"
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

extern WINAPI BOOL wine32b_EnumResourceNamesA(HMODULE hmod, LPCSTR type, ENUMRESNAMEPROCA lpfun, LONG_PTR lparam)
{
	TRACE("Enter EnumResourceNamesA\n");
	return pEnumResourceNamesA(hmod, type, lpfun, lparam);
}

extern WINAPI void wine32a_EnumResourceNamesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumResourceNamesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumResourceNamesA") "\n"
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

extern WINAPI BOOL wine32b_EnumResourceLanguagesA(HMODULE hmod, LPCSTR type, LPCSTR name, ENUMRESLANGPROCA lpfun, LONG_PTR lparam)
{
	TRACE("Enter EnumResourceLanguagesA\n");
	return pEnumResourceLanguagesA(hmod, type, name, lpfun, lparam);
}

extern WINAPI void wine32a_EnumResourceLanguagesA(void);
__ASM_GLOBAL_FUNC(wine32a_EnumResourceLanguagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumResourceLanguagesA") "\n"
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

extern WINAPI BOOL wine32b_EnumResourceLanguagesW(HMODULE hmod, LPCWSTR type, LPCWSTR name, ENUMRESLANGPROCW lpfun, LONG_PTR lparam)
{
	TRACE("Enter EnumResourceLanguagesW\n");
	return pEnumResourceLanguagesW(hmod, type, name, lpfun, lparam);
}

extern WINAPI void wine32a_EnumResourceLanguagesW(void);
__ASM_GLOBAL_FUNC(wine32a_EnumResourceLanguagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumResourceLanguagesW") "\n"
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

extern WINAPI HANDLE wine32b_BeginUpdateResourceW(LPCWSTR pFileName, BOOL bDeleteExistingResources)
{
	TRACE("Enter BeginUpdateResourceW\n");
	return pBeginUpdateResourceW(pFileName, bDeleteExistingResources);
}

extern WINAPI void wine32a_BeginUpdateResourceW(void);
__ASM_GLOBAL_FUNC(wine32a_BeginUpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BeginUpdateResourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_BeginUpdateResourceA(LPCSTR pFileName, BOOL bDeleteExistingResources)
{
	TRACE("Enter BeginUpdateResourceA\n");
	return pBeginUpdateResourceA(pFileName, bDeleteExistingResources);
}

extern WINAPI void wine32a_BeginUpdateResourceA(void);
__ASM_GLOBAL_FUNC(wine32a_BeginUpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BeginUpdateResourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EndUpdateResourceW(HANDLE hUpdate, BOOL fDiscard)
{
	TRACE("Enter EndUpdateResourceW\n");
	return pEndUpdateResourceW(hUpdate, fDiscard);
}

extern WINAPI void wine32a_EndUpdateResourceW(void);
__ASM_GLOBAL_FUNC(wine32a_EndUpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndUpdateResourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EndUpdateResourceA(HANDLE hUpdate, BOOL fDiscard)
{
	TRACE("Enter EndUpdateResourceA\n");
	return pEndUpdateResourceA(hUpdate, fDiscard);
}

extern WINAPI void wine32a_EndUpdateResourceA(void);
__ASM_GLOBAL_FUNC(wine32a_EndUpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EndUpdateResourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_UpdateResourceW(HANDLE hUpdate, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData)
{
	TRACE("Enter UpdateResourceW\n");
	return pUpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
}

extern WINAPI void wine32a_UpdateResourceW(void);
__ASM_GLOBAL_FUNC(wine32a_UpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UpdateResourceW") "\n"
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

extern WINAPI BOOL wine32b_UpdateResourceA(HANDLE hUpdate, LPCSTR lpType, LPCSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData)
{
	TRACE("Enter UpdateResourceA\n");
	return pUpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
}

extern WINAPI void wine32a_UpdateResourceA(void);
__ASM_GLOBAL_FUNC(wine32a_UpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UpdateResourceA") "\n"
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

static WINAPI LPSTR (*plstrcatA)(LPSTR dst, LPCSTR src);
static WINAPI LPWSTR (*plstrcatW)(LPWSTR dst, LPCWSTR src);
static WINAPI LPSTR (*plstrcpyA)(LPSTR dst, LPCSTR src);
static WINAPI LPWSTR (*plstrcpyW)(LPWSTR dst, LPCWSTR src);

extern WINAPI LPSTR wine32b_lstrcatA(LPSTR dst, LPCSTR src)
{
	TRACE("Enter lstrcatA\n");
	return plstrcatA(dst, src);
}

extern WINAPI void wine32a_lstrcatA(void);
__ASM_GLOBAL_FUNC(wine32a_lstrcatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_lstrcatA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_lstrcatW(LPWSTR dst, LPCWSTR src)
{
	TRACE("Enter lstrcatW\n");
	return plstrcatW(dst, src);
}

extern WINAPI void wine32a_lstrcatW(void);
__ASM_GLOBAL_FUNC(wine32a_lstrcatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_lstrcatW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_lstrcpyA(LPSTR dst, LPCSTR src)
{
	TRACE("Enter lstrcpyA\n");
	return plstrcpyA(dst, src);
}

extern WINAPI void wine32a_lstrcpyA(void);
__ASM_GLOBAL_FUNC(wine32a_lstrcpyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_lstrcpyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_lstrcpyW(LPWSTR dst, LPCWSTR src)
{
	TRACE("Enter lstrcpyW\n");
	return plstrcpyW(dst, src);
}

extern WINAPI void wine32a_lstrcpyW(void);
__ASM_GLOBAL_FUNC(wine32a_lstrcpyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_lstrcpyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOL (*pRegisterWaitForSingleObject)(PHANDLE phNewWaitObject, HANDLE hObject, WAITORTIMERCALLBACK Callback, PVOID Context, ULONG dwMilliseconds, ULONG dwFlags);
static WINAPI BOOL (*pUnregisterWait)(HANDLE WaitHandle);
static WINAPI void (*pMakeCriticalSectionGlobal)(CRITICAL_SECTION * crit);
static WINAPI void (*pReinitializeCriticalSection)(CRITICAL_SECTION * crit);
static WINAPI void (*pUninitializeCriticalSection)(CRITICAL_SECTION * crit);
static WINAPI HANDLE (*pOpenMutexA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pCreateSemaphoreA)(SECURITY_ATTRIBUTES * sa, LONG initial, LONG max, LPCSTR name);
static WINAPI HANDLE (*pCreateSemaphoreExA)(SECURITY_ATTRIBUTES * sa, LONG initial, LONG max, LPCSTR name, DWORD flags, DWORD access);
static WINAPI HANDLE (*pOpenSemaphoreA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pCreateJobObjectW)(LPSECURITY_ATTRIBUTES sa, LPCWSTR name);
static WINAPI HANDLE (*pCreateJobObjectA)(LPSECURITY_ATTRIBUTES attr, LPCSTR name);
static WINAPI HANDLE (*pOpenJobObjectW)(DWORD access, BOOL inherit, LPCWSTR name);
static WINAPI HANDLE (*pOpenJobObjectA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI BOOL (*pTerminateJobObject)(HANDLE job, UINT exit_code);
static WINAPI BOOL (*pQueryInformationJobObject)(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len, DWORD * ret_len);
static WINAPI BOOL (*pSetInformationJobObject)(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len);
static WINAPI BOOL (*pAssignProcessToJobObject)(HANDLE job, HANDLE process);
static WINAPI BOOL (*pIsProcessInJob)(HANDLE process, HANDLE job, PBOOL result);
static WINAPI HANDLE (*pCreateWaitableTimerA)(SECURITY_ATTRIBUTES * sa, BOOL manual, LPCSTR name);
static WINAPI HANDLE (*pCreateWaitableTimerExA)(SECURITY_ATTRIBUTES * sa, LPCSTR name, DWORD flags, DWORD access);
static WINAPI HANDLE (*pOpenWaitableTimerA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI BOOL (*pDeleteTimerQueue)(HANDLE TimerQueue);
static WINAPI BOOL (*pCancelTimerQueueTimer)(HANDLE queue, HANDLE timer);
static WINAPI HANDLE (*pCreateFileMappingA)(HANDLE file, SECURITY_ATTRIBUTES * sa, DWORD protect, DWORD size_high, DWORD size_low, LPCSTR name);
static WINAPI HANDLE (*pOpenFileMappingA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pCreateNamedPipeA)(LPCSTR name, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES attr);
static WINAPI BOOL (*pWaitNamedPipeA)(LPCSTR name, DWORD nTimeOut);
static WINAPI BOOL (*pGetNamedPipeClientProcessId)(HANDLE pipe, ULONG * id);
static WINAPI BOOL (*pGetNamedPipeServerProcessId)(HANDLE pipe, ULONG * id);
static WINAPI BOOL (*pGetNamedPipeClientSessionId)(HANDLE pipe, ULONG * id);
static WINAPI BOOL (*pGetNamedPipeServerSessionId)(HANDLE pipe, ULONG * id);
static WINAPI BOOL (*pGetNamedPipeHandleStateA)(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPSTR lpUsername, DWORD nUsernameMaxSize);
static WINAPI BOOL (*pGetNamedPipeHandleStateW)(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPWSTR lpUsername, DWORD nUsernameMaxSize);
static WINAPI BOOL (*pCallNamedPipeA)(LPCSTR lpNamedPipeName, LPVOID lpInput, DWORD dwInputSize, LPVOID lpOutput, DWORD dwOutputSize, LPDWORD lpBytesRead, DWORD nTimeout);
static WINAPI BOOL (*pCreatePipe)(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES sa, DWORD size);
static WINAPI HANDLE (*pCreateMailslotA)(LPCSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa);
static WINAPI HANDLE (*pCreateMailslotW)(LPCWSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa);
static WINAPI BOOL (*pGetMailslotInfo)(HANDLE hMailslot, LPDWORD lpMaxMessageSize, LPDWORD lpNextSize, LPDWORD lpMessageCount, LPDWORD lpReadTimeout);
static WINAPI BOOL (*pSetMailslotInfo)(HANDLE hMailslot, DWORD dwReadTimeout);
static WINAPI BOOL (*pBindIoCompletionCallback)(HANDLE FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags);
static WINAPI HANDLE (*pCreateMemoryResourceNotification)(MEMORY_RESOURCE_NOTIFICATION_TYPE type);
static WINAPI BOOL (*pQueryMemoryResourceNotification)(HANDLE handle, PBOOL state);
static WINAPI BOOL (*pInitOnceBeginInitialize)(INIT_ONCE * once, DWORD flags, BOOL * pending, void ** context);
static WINAPI BOOL (*pInitOnceComplete)(INIT_ONCE * once, DWORD flags, void * context);
static WINAPI BOOL (*pInitOnceExecuteOnce)(INIT_ONCE * once, PINIT_ONCE_FN func, void * param, void ** context);

extern WINAPI BOOL wine32b_RegisterWaitForSingleObject(PHANDLE phNewWaitObject, HANDLE hObject, WAITORTIMERCALLBACK Callback, PVOID Context, ULONG dwMilliseconds, ULONG dwFlags)
{
	TRACE("Enter RegisterWaitForSingleObject\n");
	return pRegisterWaitForSingleObject(phNewWaitObject, hObject, Callback, Context, dwMilliseconds, dwFlags);
}

extern WINAPI void wine32a_RegisterWaitForSingleObject(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterWaitForSingleObject") "\n"
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

extern WINAPI BOOL wine32b_UnregisterWait(HANDLE WaitHandle)
{
	TRACE("Enter UnregisterWait\n");
	return pUnregisterWait(WaitHandle);
}

extern WINAPI void wine32a_UnregisterWait(void);
__ASM_GLOBAL_FUNC(wine32a_UnregisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnregisterWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MakeCriticalSectionGlobal(CRITICAL_SECTION * crit)
{
	TRACE("Enter MakeCriticalSectionGlobal\n");
	return pMakeCriticalSectionGlobal(crit);
}

extern WINAPI void wine32a_MakeCriticalSectionGlobal(void);
__ASM_GLOBAL_FUNC(wine32a_MakeCriticalSectionGlobal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MakeCriticalSectionGlobal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_ReinitializeCriticalSection(CRITICAL_SECTION * crit)
{
	TRACE("Enter ReinitializeCriticalSection\n");
	return pReinitializeCriticalSection(crit);
}

extern WINAPI void wine32a_ReinitializeCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_ReinitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReinitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_UninitializeCriticalSection(CRITICAL_SECTION * crit)
{
	TRACE("Enter UninitializeCriticalSection\n");
	return pUninitializeCriticalSection(crit);
}

extern WINAPI void wine32a_UninitializeCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_UninitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UninitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenMutexA(DWORD access, BOOL inherit, LPCSTR name)
{
	TRACE("Enter OpenMutexA\n");
	return pOpenMutexA(access, inherit, name);
}

extern WINAPI void wine32a_OpenMutexA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenMutexA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenMutexA") "\n"
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

extern WINAPI HANDLE wine32b_CreateSemaphoreA(SECURITY_ATTRIBUTES * sa, LONG initial, LONG max, LPCSTR name)
{
	TRACE("Enter CreateSemaphoreA\n");
	return pCreateSemaphoreA(sa, initial, max, name);
}

extern WINAPI void wine32a_CreateSemaphoreA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateSemaphoreA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateSemaphoreA") "\n"
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

extern WINAPI HANDLE wine32b_CreateSemaphoreExA(SECURITY_ATTRIBUTES * sa, LONG initial, LONG max, LPCSTR name, DWORD flags, DWORD access)
{
	TRACE("Enter CreateSemaphoreExA\n");
	return pCreateSemaphoreExA(sa, initial, max, name, flags, access);
}

extern WINAPI void wine32a_CreateSemaphoreExA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateSemaphoreExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateSemaphoreExA") "\n"
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

extern WINAPI HANDLE wine32b_OpenSemaphoreA(DWORD access, BOOL inherit, LPCSTR name)
{
	TRACE("Enter OpenSemaphoreA\n");
	return pOpenSemaphoreA(access, inherit, name);
}

extern WINAPI void wine32a_OpenSemaphoreA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenSemaphoreA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenSemaphoreA") "\n"
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

extern WINAPI HANDLE wine32b_CreateJobObjectW(LPSECURITY_ATTRIBUTES sa, LPCWSTR name)
{
	TRACE("Enter CreateJobObjectW\n");
	return pCreateJobObjectW(sa, name);
}

extern WINAPI void wine32a_CreateJobObjectW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateJobObjectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateJobObjectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_CreateJobObjectA(LPSECURITY_ATTRIBUTES attr, LPCSTR name)
{
	TRACE("Enter CreateJobObjectA\n");
	return pCreateJobObjectA(attr, name);
}

extern WINAPI void wine32a_CreateJobObjectA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateJobObjectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateJobObjectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenJobObjectW(DWORD access, BOOL inherit, LPCWSTR name)
{
	TRACE("Enter OpenJobObjectW\n");
	return pOpenJobObjectW(access, inherit, name);
}

extern WINAPI void wine32a_OpenJobObjectW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenJobObjectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenJobObjectW") "\n"
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

extern WINAPI HANDLE wine32b_OpenJobObjectA(DWORD access, BOOL inherit, LPCSTR name)
{
	TRACE("Enter OpenJobObjectA\n");
	return pOpenJobObjectA(access, inherit, name);
}

extern WINAPI void wine32a_OpenJobObjectA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenJobObjectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenJobObjectA") "\n"
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

extern WINAPI BOOL wine32b_TerminateJobObject(HANDLE job, UINT exit_code)
{
	TRACE("Enter TerminateJobObject\n");
	return pTerminateJobObject(job, exit_code);
}

extern WINAPI void wine32a_TerminateJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_TerminateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TerminateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryInformationJobObject(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len, DWORD * ret_len)
{
	TRACE("Enter QueryInformationJobObject\n");
	return pQueryInformationJobObject(job, class, info, len, ret_len);
}

extern WINAPI void wine32a_QueryInformationJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_QueryInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryInformationJobObject") "\n"
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

extern WINAPI BOOL wine32b_SetInformationJobObject(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len)
{
	TRACE("Enter SetInformationJobObject\n");
	return pSetInformationJobObject(job, class, info, len);
}

extern WINAPI void wine32a_SetInformationJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_SetInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetInformationJobObject") "\n"
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

extern WINAPI BOOL wine32b_AssignProcessToJobObject(HANDLE job, HANDLE process)
{
	TRACE("Enter AssignProcessToJobObject\n");
	return pAssignProcessToJobObject(job, process);
}

extern WINAPI void wine32a_AssignProcessToJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_AssignProcessToJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AssignProcessToJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsProcessInJob(HANDLE process, HANDLE job, PBOOL result)
{
	TRACE("Enter IsProcessInJob\n");
	return pIsProcessInJob(process, job, result);
}

extern WINAPI void wine32a_IsProcessInJob(void);
__ASM_GLOBAL_FUNC(wine32a_IsProcessInJob,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsProcessInJob") "\n"
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

extern WINAPI HANDLE wine32b_CreateWaitableTimerA(SECURITY_ATTRIBUTES * sa, BOOL manual, LPCSTR name)
{
	TRACE("Enter CreateWaitableTimerA\n");
	return pCreateWaitableTimerA(sa, manual, name);
}

extern WINAPI void wine32a_CreateWaitableTimerA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWaitableTimerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWaitableTimerA") "\n"
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

extern WINAPI HANDLE wine32b_CreateWaitableTimerExA(SECURITY_ATTRIBUTES * sa, LPCSTR name, DWORD flags, DWORD access)
{
	TRACE("Enter CreateWaitableTimerExA\n");
	return pCreateWaitableTimerExA(sa, name, flags, access);
}

extern WINAPI void wine32a_CreateWaitableTimerExA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateWaitableTimerExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateWaitableTimerExA") "\n"
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

extern WINAPI HANDLE wine32b_OpenWaitableTimerA(DWORD access, BOOL inherit, LPCSTR name)
{
	TRACE("Enter OpenWaitableTimerA\n");
	return pOpenWaitableTimerA(access, inherit, name);
}

extern WINAPI void wine32a_OpenWaitableTimerA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenWaitableTimerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenWaitableTimerA") "\n"
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

extern WINAPI BOOL wine32b_DeleteTimerQueue(HANDLE TimerQueue)
{
	TRACE("Enter DeleteTimerQueue\n");
	return pDeleteTimerQueue(TimerQueue);
}

extern WINAPI void wine32a_DeleteTimerQueue(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteTimerQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteTimerQueue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CancelTimerQueueTimer(HANDLE queue, HANDLE timer)
{
	TRACE("Enter CancelTimerQueueTimer\n");
	return pCancelTimerQueueTimer(queue, timer);
}

extern WINAPI void wine32a_CancelTimerQueueTimer(void);
__ASM_GLOBAL_FUNC(wine32a_CancelTimerQueueTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CancelTimerQueueTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_CreateFileMappingA(HANDLE file, SECURITY_ATTRIBUTES * sa, DWORD protect, DWORD size_high, DWORD size_low, LPCSTR name)
{
	TRACE("Enter CreateFileMappingA\n");
	return pCreateFileMappingA(file, sa, protect, size_high, size_low, name);
}

extern WINAPI void wine32a_CreateFileMappingA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateFileMappingA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateFileMappingA") "\n"
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

extern WINAPI HANDLE wine32b_OpenFileMappingA(DWORD access, BOOL inherit, LPCSTR name)
{
	TRACE("Enter OpenFileMappingA\n");
	return pOpenFileMappingA(access, inherit, name);
}

extern WINAPI void wine32a_OpenFileMappingA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenFileMappingA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenFileMappingA") "\n"
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

extern WINAPI HANDLE wine32b_CreateNamedPipeA(LPCSTR name, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES attr)
{
	TRACE("Enter CreateNamedPipeA\n");
	return pCreateNamedPipeA(name, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, attr);
}

extern WINAPI void wine32a_CreateNamedPipeA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateNamedPipeA") "\n"
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

extern WINAPI BOOL wine32b_WaitNamedPipeA(LPCSTR name, DWORD nTimeOut)
{
	TRACE("Enter WaitNamedPipeA\n");
	return pWaitNamedPipeA(name, nTimeOut);
}

extern WINAPI void wine32a_WaitNamedPipeA(void);
__ASM_GLOBAL_FUNC(wine32a_WaitNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WaitNamedPipeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNamedPipeClientProcessId(HANDLE pipe, ULONG * id)
{
	TRACE("Enter GetNamedPipeClientProcessId\n");
	return pGetNamedPipeClientProcessId(pipe, id);
}

extern WINAPI void wine32a_GetNamedPipeClientProcessId(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeClientProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeClientProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNamedPipeServerProcessId(HANDLE pipe, ULONG * id)
{
	TRACE("Enter GetNamedPipeServerProcessId\n");
	return pGetNamedPipeServerProcessId(pipe, id);
}

extern WINAPI void wine32a_GetNamedPipeServerProcessId(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeServerProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeServerProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNamedPipeClientSessionId(HANDLE pipe, ULONG * id)
{
	TRACE("Enter GetNamedPipeClientSessionId\n");
	return pGetNamedPipeClientSessionId(pipe, id);
}

extern WINAPI void wine32a_GetNamedPipeClientSessionId(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeClientSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeClientSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNamedPipeServerSessionId(HANDLE pipe, ULONG * id)
{
	TRACE("Enter GetNamedPipeServerSessionId\n");
	return pGetNamedPipeServerSessionId(pipe, id);
}

extern WINAPI void wine32a_GetNamedPipeServerSessionId(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeServerSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeServerSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetNamedPipeHandleStateA(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPSTR lpUsername, DWORD nUsernameMaxSize)
{
	TRACE("Enter GetNamedPipeHandleStateA\n");
	return pGetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
}

extern WINAPI void wine32a_GetNamedPipeHandleStateA(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeHandleStateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeHandleStateA") "\n"
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

extern WINAPI BOOL wine32b_GetNamedPipeHandleStateW(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPWSTR lpUsername, DWORD nUsernameMaxSize)
{
	TRACE("Enter GetNamedPipeHandleStateW\n");
	return pGetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
}

extern WINAPI void wine32a_GetNamedPipeHandleStateW(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedPipeHandleStateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedPipeHandleStateW") "\n"
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

extern WINAPI BOOL wine32b_CallNamedPipeA(LPCSTR lpNamedPipeName, LPVOID lpInput, DWORD dwInputSize, LPVOID lpOutput, DWORD dwOutputSize, LPDWORD lpBytesRead, DWORD nTimeout)
{
	TRACE("Enter CallNamedPipeA\n");
	return pCallNamedPipeA(lpNamedPipeName, lpInput, dwInputSize, lpOutput, dwOutputSize, lpBytesRead, nTimeout);
}

extern WINAPI void wine32a_CallNamedPipeA(void);
__ASM_GLOBAL_FUNC(wine32a_CallNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CallNamedPipeA") "\n"
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

extern WINAPI BOOL wine32b_CreatePipe(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES sa, DWORD size)
{
	TRACE("Enter CreatePipe\n");
	return pCreatePipe(hReadPipe, hWritePipe, sa, size);
}

extern WINAPI void wine32a_CreatePipe(void);
__ASM_GLOBAL_FUNC(wine32a_CreatePipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreatePipe") "\n"
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

extern WINAPI HANDLE wine32b_CreateMailslotA(LPCSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateMailslotA\n");
	return pCreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, sa);
}

extern WINAPI void wine32a_CreateMailslotA(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMailslotA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMailslotA") "\n"
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

extern WINAPI HANDLE wine32b_CreateMailslotW(LPCWSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter CreateMailslotW\n");
	return pCreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, sa);
}

extern WINAPI void wine32a_CreateMailslotW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMailslotW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMailslotW") "\n"
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

extern WINAPI BOOL wine32b_GetMailslotInfo(HANDLE hMailslot, LPDWORD lpMaxMessageSize, LPDWORD lpNextSize, LPDWORD lpMessageCount, LPDWORD lpReadTimeout)
{
	TRACE("Enter GetMailslotInfo\n");
	return pGetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout);
}

extern WINAPI void wine32a_GetMailslotInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetMailslotInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetMailslotInfo") "\n"
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

extern WINAPI BOOL wine32b_SetMailslotInfo(HANDLE hMailslot, DWORD dwReadTimeout)
{
	TRACE("Enter SetMailslotInfo\n");
	return pSetMailslotInfo(hMailslot, dwReadTimeout);
}

extern WINAPI void wine32a_SetMailslotInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetMailslotInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetMailslotInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_BindIoCompletionCallback(HANDLE FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags)
{
	TRACE("Enter BindIoCompletionCallback\n");
	return pBindIoCompletionCallback(FileHandle, Function, Flags);
}

extern WINAPI void wine32a_BindIoCompletionCallback(void);
__ASM_GLOBAL_FUNC(wine32a_BindIoCompletionCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BindIoCompletionCallback") "\n"
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

extern WINAPI HANDLE wine32b_CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE type)
{
	TRACE("Enter CreateMemoryResourceNotification\n");
	return pCreateMemoryResourceNotification(type);
}

extern WINAPI void wine32a_CreateMemoryResourceNotification(void);
__ASM_GLOBAL_FUNC(wine32a_CreateMemoryResourceNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateMemoryResourceNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryMemoryResourceNotification(HANDLE handle, PBOOL state)
{
	TRACE("Enter QueryMemoryResourceNotification\n");
	return pQueryMemoryResourceNotification(handle, state);
}

extern WINAPI void wine32a_QueryMemoryResourceNotification(void);
__ASM_GLOBAL_FUNC(wine32a_QueryMemoryResourceNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryMemoryResourceNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InitOnceBeginInitialize(INIT_ONCE * once, DWORD flags, BOOL * pending, void ** context)
{
	TRACE("Enter InitOnceBeginInitialize\n");
	return pInitOnceBeginInitialize(once, flags, pending, context);
}

extern WINAPI void wine32a_InitOnceBeginInitialize(void);
__ASM_GLOBAL_FUNC(wine32a_InitOnceBeginInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitOnceBeginInitialize") "\n"
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

extern WINAPI BOOL wine32b_InitOnceComplete(INIT_ONCE * once, DWORD flags, void * context)
{
	TRACE("Enter InitOnceComplete\n");
	return pInitOnceComplete(once, flags, context);
}

extern WINAPI void wine32a_InitOnceComplete(void);
__ASM_GLOBAL_FUNC(wine32a_InitOnceComplete,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitOnceComplete") "\n"
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

extern WINAPI BOOL wine32b_InitOnceExecuteOnce(INIT_ONCE * once, PINIT_ONCE_FN func, void * param, void ** context)
{
	TRACE("Enter InitOnceExecuteOnce\n");
	return pInitOnceExecuteOnce(once, func, param, context);
}

extern WINAPI void wine32a_InitOnceExecuteOnce(void);
__ASM_GLOBAL_FUNC(wine32a_InitOnceExecuteOnce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitOnceExecuteOnce") "\n"
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

static WINAPI BOOL (*pBackupRead)(HANDLE file, LPBYTE buffer, DWORD to_read, LPDWORD read, BOOL abort, BOOL security, LPVOID * context);
static WINAPI BOOL (*pBackupSeek)(HANDLE file, DWORD seek_low, DWORD seek_high, LPDWORD seeked_low, LPDWORD seeked_high, LPVOID * context);
static WINAPI BOOL (*pBackupWrite)(HANDLE file, LPBYTE buffer, DWORD to_write, LPDWORD written, BOOL abort, BOOL security, LPVOID * context);
static WINAPI DWORD (*pCreateTapePartition)(HANDLE device, DWORD method, DWORD count, DWORD size);
static WINAPI DWORD (*pEraseTape)(HANDLE device, DWORD type, BOOL immediate);
static WINAPI DWORD (*pGetTapeParameters)(HANDLE device, DWORD operation, LPDWORD size, LPVOID info);
static WINAPI DWORD (*pGetTapePosition)(HANDLE device, DWORD type, LPDWORD partition, LPDWORD offset_low, LPDWORD offset_high);
static WINAPI DWORD (*pGetTapeStatus)(HANDLE device);
static WINAPI DWORD (*pPrepareTape)(HANDLE device, DWORD operation, BOOL immediate);
static WINAPI DWORD (*pSetTapeParameters)(HANDLE device, DWORD operation, LPVOID info);
static WINAPI DWORD (*pSetTapePosition)(HANDLE device, DWORD method, DWORD partition, DWORD offset_low, DWORD offset_high, BOOL immediate);
static WINAPI DWORD (*pWriteTapemark)(HANDLE device, DWORD type, DWORD count, BOOL immediate);

extern WINAPI BOOL wine32b_BackupRead(HANDLE file, LPBYTE buffer, DWORD to_read, LPDWORD read, BOOL abort, BOOL security, LPVOID * context)
{
	TRACE("Enter BackupRead\n");
	return pBackupRead(file, buffer, to_read, read, abort, security, context);
}

extern WINAPI void wine32a_BackupRead(void);
__ASM_GLOBAL_FUNC(wine32a_BackupRead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BackupRead") "\n"
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

extern WINAPI BOOL wine32b_BackupSeek(HANDLE file, DWORD seek_low, DWORD seek_high, LPDWORD seeked_low, LPDWORD seeked_high, LPVOID * context)
{
	TRACE("Enter BackupSeek\n");
	return pBackupSeek(file, seek_low, seek_high, seeked_low, seeked_high, context);
}

extern WINAPI void wine32a_BackupSeek(void);
__ASM_GLOBAL_FUNC(wine32a_BackupSeek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BackupSeek") "\n"
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

extern WINAPI BOOL wine32b_BackupWrite(HANDLE file, LPBYTE buffer, DWORD to_write, LPDWORD written, BOOL abort, BOOL security, LPVOID * context)
{
	TRACE("Enter BackupWrite\n");
	return pBackupWrite(file, buffer, to_write, written, abort, security, context);
}

extern WINAPI void wine32a_BackupWrite(void);
__ASM_GLOBAL_FUNC(wine32a_BackupWrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BackupWrite") "\n"
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

extern WINAPI DWORD wine32b_CreateTapePartition(HANDLE device, DWORD method, DWORD count, DWORD size)
{
	TRACE("Enter CreateTapePartition\n");
	return pCreateTapePartition(device, method, count, size);
}

extern WINAPI void wine32a_CreateTapePartition(void);
__ASM_GLOBAL_FUNC(wine32a_CreateTapePartition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateTapePartition") "\n"
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

extern WINAPI DWORD wine32b_EraseTape(HANDLE device, DWORD type, BOOL immediate)
{
	TRACE("Enter EraseTape\n");
	return pEraseTape(device, type, immediate);
}

extern WINAPI void wine32a_EraseTape(void);
__ASM_GLOBAL_FUNC(wine32a_EraseTape,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EraseTape") "\n"
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

extern WINAPI DWORD wine32b_GetTapeParameters(HANDLE device, DWORD operation, LPDWORD size, LPVOID info)
{
	TRACE("Enter GetTapeParameters\n");
	return pGetTapeParameters(device, operation, size, info);
}

extern WINAPI void wine32a_GetTapeParameters(void);
__ASM_GLOBAL_FUNC(wine32a_GetTapeParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTapeParameters") "\n"
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

extern WINAPI DWORD wine32b_GetTapePosition(HANDLE device, DWORD type, LPDWORD partition, LPDWORD offset_low, LPDWORD offset_high)
{
	TRACE("Enter GetTapePosition\n");
	return pGetTapePosition(device, type, partition, offset_low, offset_high);
}

extern WINAPI void wine32a_GetTapePosition(void);
__ASM_GLOBAL_FUNC(wine32a_GetTapePosition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTapePosition") "\n"
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

extern WINAPI DWORD wine32b_GetTapeStatus(HANDLE device)
{
	TRACE("Enter GetTapeStatus\n");
	return pGetTapeStatus(device);
}

extern WINAPI void wine32a_GetTapeStatus(void);
__ASM_GLOBAL_FUNC(wine32a_GetTapeStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTapeStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_PrepareTape(HANDLE device, DWORD operation, BOOL immediate)
{
	TRACE("Enter PrepareTape\n");
	return pPrepareTape(device, operation, immediate);
}

extern WINAPI void wine32a_PrepareTape(void);
__ASM_GLOBAL_FUNC(wine32a_PrepareTape,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrepareTape") "\n"
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

extern WINAPI DWORD wine32b_SetTapeParameters(HANDLE device, DWORD operation, LPVOID info)
{
	TRACE("Enter SetTapeParameters\n");
	return pSetTapeParameters(device, operation, info);
}

extern WINAPI void wine32a_SetTapeParameters(void);
__ASM_GLOBAL_FUNC(wine32a_SetTapeParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTapeParameters") "\n"
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

extern WINAPI DWORD wine32b_SetTapePosition(HANDLE device, DWORD method, DWORD partition, DWORD offset_low, DWORD offset_high, BOOL immediate)
{
	TRACE("Enter SetTapePosition\n");
	return pSetTapePosition(device, method, partition, offset_low, offset_high, immediate);
}

extern WINAPI void wine32a_SetTapePosition(void);
__ASM_GLOBAL_FUNC(wine32a_SetTapePosition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTapePosition") "\n"
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

extern WINAPI DWORD wine32b_WriteTapemark(HANDLE device, DWORD type, DWORD count, BOOL immediate)
{
	TRACE("Enter WriteTapemark\n");
	return pWriteTapemark(device, type, count, immediate);
}

extern WINAPI void wine32a_WriteTapemark(void);
__ASM_GLOBAL_FUNC(wine32a_WriteTapemark,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteTapemark") "\n"
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


static WINAPI void (*pFreeLibraryAndExitThread)(HINSTANCE hLibModule, DWORD dwExitCode);
static WINAPI BOOL (*pWow64SetThreadContext)(HANDLE handle, const WOW64_CONTEXT * context);
static WINAPI BOOL (*pWow64GetThreadContext)(HANDLE handle, WOW64_CONTEXT * context);
static WINAPI DWORD_PTR (*pSetThreadAffinityMask)(HANDLE hThread, DWORD_PTR dwThreadAffinityMask);
static WINAPI BOOL (*pGetThreadSelectorEntry)(HANDLE hthread, DWORD sel, LPLDT_ENTRY ldtent);

extern WINAPI void wine32b_FreeLibraryAndExitThread(HINSTANCE hLibModule, DWORD dwExitCode)
{
	TRACE("Enter FreeLibraryAndExitThread\n");
	return pFreeLibraryAndExitThread(hLibModule, dwExitCode);
}

extern WINAPI void wine32a_FreeLibraryAndExitThread(void);
__ASM_GLOBAL_FUNC(wine32a_FreeLibraryAndExitThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FreeLibraryAndExitThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Wow64SetThreadContext(HANDLE handle, const WOW64_CONTEXT * context)
{
	TRACE("Enter Wow64SetThreadContext\n");
	return pWow64SetThreadContext(handle, context);
}

extern WINAPI void wine32a_Wow64SetThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_Wow64SetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Wow64SetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Wow64GetThreadContext(HANDLE handle, WOW64_CONTEXT * context)
{
	TRACE("Enter Wow64GetThreadContext\n");
	return pWow64GetThreadContext(handle, context);
}

extern WINAPI void wine32a_Wow64GetThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_Wow64GetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Wow64GetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD_PTR wine32b_SetThreadAffinityMask(HANDLE hThread, DWORD_PTR dwThreadAffinityMask)
{
	TRACE("Enter SetThreadAffinityMask\n");
	return pSetThreadAffinityMask(hThread, dwThreadAffinityMask);
}

extern WINAPI void wine32a_SetThreadAffinityMask(void);
__ASM_GLOBAL_FUNC(wine32a_SetThreadAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetThreadAffinityMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetThreadSelectorEntry(HANDLE hthread, DWORD sel, LPLDT_ENTRY ldtent)
{
	TRACE("Enter GetThreadSelectorEntry\n");
	return pGetThreadSelectorEntry(hthread, sel, ldtent);
}

extern WINAPI void wine32a_GetThreadSelectorEntry(void);
__ASM_GLOBAL_FUNC(wine32a_GetThreadSelectorEntry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetThreadSelectorEntry") "\n"
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

static WINAPI BOOL (*pSetLocalTime)(const SYSTEMTIME * systime);
static WINAPI BOOL (*pGetSystemTimeAdjustment)(PDWORD lpTimeAdjustment, PDWORD lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled);
static WINAPI BOOL (*pSetSystemTime)(const SYSTEMTIME * systime);
static WINAPI BOOL (*pSetSystemTimeAdjustment)(DWORD dwTimeAdjustment, BOOL bTimeAdjustmentDisabled);
static WINAPI DWORD (*pGetTimeZoneInformation)(LPTIME_ZONE_INFORMATION ret);
static WINAPI BOOL (*pGetTimeZoneInformationForYear)(USHORT wYear, PDYNAMIC_TIME_ZONE_INFORMATION pdtzi, LPTIME_ZONE_INFORMATION ptzi);
static WINAPI BOOL (*pSetTimeZoneInformation)(const TIME_ZONE_INFORMATION * tzinfo);
static WINAPI BOOL (*pSystemTimeToTzSpecificLocalTime)(const TIME_ZONE_INFORMATION * lpTimeZoneInformation, const SYSTEMTIME * lpUniversalTime, LPSYSTEMTIME lpLocalTime);
static WINAPI BOOL (*pTzSpecificLocalTimeToSystemTime)(const TIME_ZONE_INFORMATION * lpTimeZoneInformation, const SYSTEMTIME * lpLocalTime, LPSYSTEMTIME lpUniversalTime);
static WINAPI void (*pGetSystemTimePreciseAsFileTime)(FILETIME * time);
static WINAPI BOOL (*pGetProcessTimes)(HANDLE hprocess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
static WINAPI INT (*pGetCalendarInfoA)(LCID lcid, CALID Calendar, CALTYPE CalType, LPSTR lpCalData, int cchData, LPDWORD lpValue);
static WINAPI INT (*pGetCalendarInfoW)(LCID Locale, CALID Calendar, CALTYPE CalType, LPWSTR lpCalData, int cchData, LPDWORD lpValue);
static WINAPI int (*pGetCalendarInfoEx)(LPCWSTR locale, CALID calendar, LPCWSTR lpReserved, CALTYPE caltype, LPWSTR data, int len, DWORD * value);
static WINAPI INT (*pSetCalendarInfoA)(LCID Locale, CALID Calendar, CALTYPE CalType, LPCSTR lpCalData);
static WINAPI INT (*pSetCalendarInfoW)(LCID Locale, CALID Calendar, CALTYPE CalType, LPCWSTR lpCalData);
static WINAPI BOOL (*pLocalFileTimeToFileTime)(const FILETIME * localft, LPFILETIME utcft);
static WINAPI BOOL (*pFileTimeToLocalFileTime)(const FILETIME * utcft, LPFILETIME localft);
static WINAPI BOOL (*pFileTimeToSystemTime)(const FILETIME * ft, LPSYSTEMTIME syst);
static WINAPI BOOL (*pSystemTimeToFileTime)(const SYSTEMTIME * syst, LPFILETIME ft);
static WINAPI INT (*pCompareFileTime)(const FILETIME * x, const FILETIME * y);
static WINAPI void (*pGetLocalTime)(LPSYSTEMTIME systime);
static WINAPI void (*pGetSystemTime)(LPSYSTEMTIME systime);
static WINAPI BOOL (*pGetDaylightFlag)(void);
static WINAPI BOOL (*pDosDateTimeToFileTime)(WORD fatdate, WORD fattime, LPFILETIME ft);
static WINAPI BOOL (*pFileTimeToDosDateTime)(const FILETIME * ft, LPWORD fatdate, LPWORD fattime);
static WINAPI BOOL (*pGetSystemTimes)(LPFILETIME lpIdleTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
static WINAPI DWORD (*pGetDynamicTimeZoneInformation)(DYNAMIC_TIME_ZONE_INFORMATION * tzinfo);
static WINAPI DWORD (*pGetDynamicTimeZoneInformationEffectiveYears)(DYNAMIC_TIME_ZONE_INFORMATION * tzinfo, DWORD * first_year, DWORD * last_year);
static WINAPI BOOL (*pQueryProcessCycleTime)(HANDLE process, PULONG64 cycle);
static WINAPI BOOL (*pQueryThreadCycleTime)(HANDLE thread, PULONG64 cycle);
static WINAPI BOOL (*pQueryUnbiasedInterruptTime)(ULONGLONG * time);
static WINAPI ULONGLONG (*pGetTickCount64)(void);
static WINAPI DWORD (*pGetTickCount)(void);

extern WINAPI BOOL wine32b_SetLocalTime(const SYSTEMTIME * systime)
{
	TRACE("Enter SetLocalTime\n");
	return pSetLocalTime(systime);
}

extern WINAPI void wine32a_SetLocalTime(void);
__ASM_GLOBAL_FUNC(wine32a_SetLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetSystemTimeAdjustment(PDWORD lpTimeAdjustment, PDWORD lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled)
{
	TRACE("Enter GetSystemTimeAdjustment\n");
	return pGetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled);
}

extern WINAPI void wine32a_GetSystemTimeAdjustment(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemTimeAdjustment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemTimeAdjustment") "\n"
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

extern WINAPI BOOL wine32b_SetSystemTime(const SYSTEMTIME * systime)
{
	TRACE("Enter SetSystemTime\n");
	return pSetSystemTime(systime);
}

extern WINAPI void wine32a_SetSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetSystemTimeAdjustment(DWORD dwTimeAdjustment, BOOL bTimeAdjustmentDisabled)
{
	TRACE("Enter SetSystemTimeAdjustment\n");
	return pSetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled);
}

extern WINAPI void wine32a_SetSystemTimeAdjustment(void);
__ASM_GLOBAL_FUNC(wine32a_SetSystemTimeAdjustment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSystemTimeAdjustment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION ret)
{
	TRACE("Enter GetTimeZoneInformation\n");
	return pGetTimeZoneInformation(ret);
}

extern WINAPI void wine32a_GetTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_GetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetTimeZoneInformationForYear(USHORT wYear, PDYNAMIC_TIME_ZONE_INFORMATION pdtzi, LPTIME_ZONE_INFORMATION ptzi)
{
	TRACE("Enter GetTimeZoneInformationForYear\n");
	return pGetTimeZoneInformationForYear(wYear, pdtzi, ptzi);
}

extern WINAPI void wine32a_GetTimeZoneInformationForYear(void);
__ASM_GLOBAL_FUNC(wine32a_GetTimeZoneInformationForYear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTimeZoneInformationForYear") "\n"
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

extern WINAPI BOOL wine32b_SetTimeZoneInformation(const TIME_ZONE_INFORMATION * tzinfo)
{
	TRACE("Enter SetTimeZoneInformation\n");
	return pSetTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_SetTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_SetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SystemTimeToTzSpecificLocalTime(const TIME_ZONE_INFORMATION * lpTimeZoneInformation, const SYSTEMTIME * lpUniversalTime, LPSYSTEMTIME lpLocalTime)
{
	TRACE("Enter SystemTimeToTzSpecificLocalTime\n");
	return pSystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime);
}

extern WINAPI void wine32a_SystemTimeToTzSpecificLocalTime(void);
__ASM_GLOBAL_FUNC(wine32a_SystemTimeToTzSpecificLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemTimeToTzSpecificLocalTime") "\n"
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

extern WINAPI BOOL wine32b_TzSpecificLocalTimeToSystemTime(const TIME_ZONE_INFORMATION * lpTimeZoneInformation, const SYSTEMTIME * lpLocalTime, LPSYSTEMTIME lpUniversalTime)
{
	TRACE("Enter TzSpecificLocalTimeToSystemTime\n");
	return pTzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime);
}

extern WINAPI void wine32a_TzSpecificLocalTimeToSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_TzSpecificLocalTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TzSpecificLocalTimeToSystemTime") "\n"
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

extern WINAPI void wine32b_GetSystemTimePreciseAsFileTime(FILETIME * time)
{
	TRACE("Enter GetSystemTimePreciseAsFileTime\n");
	return pGetSystemTimePreciseAsFileTime(time);
}

extern WINAPI void wine32a_GetSystemTimePreciseAsFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemTimePreciseAsFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemTimePreciseAsFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProcessTimes(HANDLE hprocess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	TRACE("Enter GetProcessTimes\n");
	return pGetProcessTimes(hprocess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime);
}

extern WINAPI void wine32a_GetProcessTimes(void);
__ASM_GLOBAL_FUNC(wine32a_GetProcessTimes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProcessTimes") "\n"
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

extern WINAPI INT wine32b_GetCalendarInfoA(LCID lcid, CALID Calendar, CALTYPE CalType, LPSTR lpCalData, int cchData, LPDWORD lpValue)
{
	TRACE("Enter GetCalendarInfoA\n");
	return pGetCalendarInfoA(lcid, Calendar, CalType, lpCalData, cchData, lpValue);
}

extern WINAPI void wine32a_GetCalendarInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCalendarInfoA") "\n"
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

extern WINAPI INT wine32b_GetCalendarInfoW(LCID Locale, CALID Calendar, CALTYPE CalType, LPWSTR lpCalData, int cchData, LPDWORD lpValue)
{
	TRACE("Enter GetCalendarInfoW\n");
	return pGetCalendarInfoW(Locale, Calendar, CalType, lpCalData, cchData, lpValue);
}

extern WINAPI void wine32a_GetCalendarInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCalendarInfoW") "\n"
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

extern WINAPI int wine32b_GetCalendarInfoEx(LPCWSTR locale, CALID calendar, LPCWSTR lpReserved, CALTYPE caltype, LPWSTR data, int len, DWORD * value)
{
	TRACE("Enter GetCalendarInfoEx\n");
	return pGetCalendarInfoEx(locale, calendar, lpReserved, caltype, data, len, value);
}

extern WINAPI void wine32a_GetCalendarInfoEx(void);
__ASM_GLOBAL_FUNC(wine32a_GetCalendarInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCalendarInfoEx") "\n"
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

extern WINAPI INT wine32b_SetCalendarInfoA(LCID Locale, CALID Calendar, CALTYPE CalType, LPCSTR lpCalData)
{
	TRACE("Enter SetCalendarInfoA\n");
	return pSetCalendarInfoA(Locale, Calendar, CalType, lpCalData);
}

extern WINAPI void wine32a_SetCalendarInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SetCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCalendarInfoA") "\n"
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

extern WINAPI INT wine32b_SetCalendarInfoW(LCID Locale, CALID Calendar, CALTYPE CalType, LPCWSTR lpCalData)
{
	TRACE("Enter SetCalendarInfoW\n");
	return pSetCalendarInfoW(Locale, Calendar, CalType, lpCalData);
}

extern WINAPI void wine32a_SetCalendarInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SetCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetCalendarInfoW") "\n"
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

extern WINAPI BOOL wine32b_LocalFileTimeToFileTime(const FILETIME * localft, LPFILETIME utcft)
{
	TRACE("Enter LocalFileTimeToFileTime\n");
	return pLocalFileTimeToFileTime(localft, utcft);
}

extern WINAPI void wine32a_LocalFileTimeToFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_LocalFileTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LocalFileTimeToFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FileTimeToLocalFileTime(const FILETIME * utcft, LPFILETIME localft)
{
	TRACE("Enter FileTimeToLocalFileTime\n");
	return pFileTimeToLocalFileTime(utcft, localft);
}

extern WINAPI void wine32a_FileTimeToLocalFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_FileTimeToLocalFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FileTimeToLocalFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FileTimeToSystemTime(const FILETIME * ft, LPSYSTEMTIME syst)
{
	TRACE("Enter FileTimeToSystemTime\n");
	return pFileTimeToSystemTime(ft, syst);
}

extern WINAPI void wine32a_FileTimeToSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_FileTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FileTimeToSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SystemTimeToFileTime(const SYSTEMTIME * syst, LPFILETIME ft)
{
	TRACE("Enter SystemTimeToFileTime\n");
	return pSystemTimeToFileTime(syst, ft);
}

extern WINAPI void wine32a_SystemTimeToFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_SystemTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemTimeToFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_CompareFileTime(const FILETIME * x, const FILETIME * y)
{
	TRACE("Enter CompareFileTime\n");
	return pCompareFileTime(x, y);
}

extern WINAPI void wine32a_CompareFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_CompareFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CompareFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetLocalTime(LPSYSTEMTIME systime)
{
	TRACE("Enter GetLocalTime\n");
	return pGetLocalTime(systime);
}

extern WINAPI void wine32a_GetLocalTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_GetSystemTime(LPSYSTEMTIME systime)
{
	TRACE("Enter GetSystemTime\n");
	return pGetSystemTime(systime);
}

extern WINAPI void wine32a_GetSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetDaylightFlag(void)
{
	TRACE("Enter GetDaylightFlag\n");
	return pGetDaylightFlag();
}

extern WINAPI void wine32a_GetDaylightFlag(void);
__ASM_GLOBAL_FUNC(wine32a_GetDaylightFlag,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDaylightFlag") "\n"
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

extern WINAPI BOOL wine32b_DosDateTimeToFileTime(WORD fatdate, WORD fattime, LPFILETIME ft)
{
	TRACE("Enter DosDateTimeToFileTime\n");
	return pDosDateTimeToFileTime(fatdate, fattime, ft);
}

extern WINAPI void wine32a_DosDateTimeToFileTime(void);
__ASM_GLOBAL_FUNC(wine32a_DosDateTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DosDateTimeToFileTime") "\n"
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

extern WINAPI BOOL wine32b_FileTimeToDosDateTime(const FILETIME * ft, LPWORD fatdate, LPWORD fattime)
{
	TRACE("Enter FileTimeToDosDateTime\n");
	return pFileTimeToDosDateTime(ft, fatdate, fattime);
}

extern WINAPI void wine32a_FileTimeToDosDateTime(void);
__ASM_GLOBAL_FUNC(wine32a_FileTimeToDosDateTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FileTimeToDosDateTime") "\n"
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

extern WINAPI BOOL wine32b_GetSystemTimes(LPFILETIME lpIdleTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime)
{
	TRACE("Enter GetSystemTimes\n");
	return pGetSystemTimes(lpIdleTime, lpKernelTime, lpUserTime);
}

extern WINAPI void wine32a_GetSystemTimes(void);
__ASM_GLOBAL_FUNC(wine32a_GetSystemTimes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSystemTimes") "\n"
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

extern WINAPI DWORD wine32b_GetDynamicTimeZoneInformation(DYNAMIC_TIME_ZONE_INFORMATION * tzinfo)
{
	TRACE("Enter GetDynamicTimeZoneInformation\n");
	return pGetDynamicTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_GetDynamicTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_GetDynamicTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDynamicTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetDynamicTimeZoneInformationEffectiveYears(DYNAMIC_TIME_ZONE_INFORMATION * tzinfo, DWORD * first_year, DWORD * last_year)
{
	TRACE("Enter GetDynamicTimeZoneInformationEffectiveYears\n");
	return pGetDynamicTimeZoneInformationEffectiveYears(tzinfo, first_year, last_year);
}

extern WINAPI void wine32a_GetDynamicTimeZoneInformationEffectiveYears(void);
__ASM_GLOBAL_FUNC(wine32a_GetDynamicTimeZoneInformationEffectiveYears,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDynamicTimeZoneInformationEffectiveYears") "\n"
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

extern WINAPI BOOL wine32b_QueryProcessCycleTime(HANDLE process, PULONG64 cycle)
{
	TRACE("Enter QueryProcessCycleTime\n");
	return pQueryProcessCycleTime(process, cycle);
}

extern WINAPI void wine32a_QueryProcessCycleTime(void);
__ASM_GLOBAL_FUNC(wine32a_QueryProcessCycleTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryProcessCycleTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryThreadCycleTime(HANDLE thread, PULONG64 cycle)
{
	TRACE("Enter QueryThreadCycleTime\n");
	return pQueryThreadCycleTime(thread, cycle);
}

extern WINAPI void wine32a_QueryThreadCycleTime(void);
__ASM_GLOBAL_FUNC(wine32a_QueryThreadCycleTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryThreadCycleTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryUnbiasedInterruptTime(ULONGLONG * time)
{
	TRACE("Enter QueryUnbiasedInterruptTime\n");
	return pQueryUnbiasedInterruptTime(time);
}

extern WINAPI void wine32a_QueryUnbiasedInterruptTime(void);
__ASM_GLOBAL_FUNC(wine32a_QueryUnbiasedInterruptTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryUnbiasedInterruptTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONGLONG wine32b_GetTickCount64(void)
{
	TRACE("Enter GetTickCount64\n");
	return pGetTickCount64();
}

extern WINAPI void wine32a_GetTickCount64(void);
__ASM_GLOBAL_FUNC(wine32a_GetTickCount64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTickCount64") "\n"
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

extern WINAPI DWORD wine32b_GetTickCount(void)
{
	TRACE("Enter GetTickCount\n");
	return pGetTickCount();
}

extern WINAPI void wine32a_GetTickCount(void);
__ASM_GLOBAL_FUNC(wine32a_GetTickCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTickCount") "\n"
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

static WINAPI HANDLE (*pCreateToolhelp32Snapshot)(DWORD flags, DWORD process);
static WINAPI BOOL (*pThread32First)(HANDLE hSnapShot, LPTHREADENTRY32 lpte);
static WINAPI BOOL (*pThread32Next)(HANDLE hSnapShot, LPTHREADENTRY32 lpte);
static WINAPI BOOL (*pProcess32First)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
static WINAPI BOOL (*pProcess32Next)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
static WINAPI BOOL (*pProcess32FirstW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
static WINAPI BOOL (*pProcess32NextW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
static WINAPI BOOL (*pModule32FirstW)(HANDLE hSnapshot, LPMODULEENTRY32W lpme);
static WINAPI BOOL (*pModule32NextW)(HANDLE hSnapshot, LPMODULEENTRY32W lpme);
static WINAPI BOOL (*pModule32First)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
static WINAPI BOOL (*pModule32Next)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
static WINAPI BOOL (*pHeap32ListFirst)(HANDLE hSnapshot, LPHEAPLIST32 lphl);
static WINAPI BOOL (*pToolhelp32ReadProcessMemory)(DWORD pid, const void * base, void * buf, SIZE_T len, SIZE_T * r);

extern WINAPI HANDLE wine32b_CreateToolhelp32Snapshot(DWORD flags, DWORD process)
{
	TRACE("Enter CreateToolhelp32Snapshot\n");
	return pCreateToolhelp32Snapshot(flags, process);
}

extern WINAPI void wine32a_CreateToolhelp32Snapshot(void);
__ASM_GLOBAL_FUNC(wine32a_CreateToolhelp32Snapshot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateToolhelp32Snapshot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Thread32First(HANDLE hSnapShot, LPTHREADENTRY32 lpte)
{
	TRACE("Enter Thread32First\n");
	return pThread32First(hSnapShot, lpte);
}

extern WINAPI void wine32a_Thread32First(void);
__ASM_GLOBAL_FUNC(wine32a_Thread32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Thread32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Thread32Next(HANDLE hSnapShot, LPTHREADENTRY32 lpte)
{
	TRACE("Enter Thread32Next\n");
	return pThread32Next(hSnapShot, lpte);
}

extern WINAPI void wine32a_Thread32Next(void);
__ASM_GLOBAL_FUNC(wine32a_Thread32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Thread32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
	TRACE("Enter Process32First\n");
	return pProcess32First(hSnapshot, lppe);
}

extern WINAPI void wine32a_Process32First(void);
__ASM_GLOBAL_FUNC(wine32a_Process32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Process32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe)
{
	TRACE("Enter Process32Next\n");
	return pProcess32Next(hSnapshot, lppe);
}

extern WINAPI void wine32a_Process32Next(void);
__ASM_GLOBAL_FUNC(wine32a_Process32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Process32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
	TRACE("Enter Process32FirstW\n");
	return pProcess32FirstW(hSnapshot, lppe);
}

extern WINAPI void wine32a_Process32FirstW(void);
__ASM_GLOBAL_FUNC(wine32a_Process32FirstW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Process32FirstW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe)
{
	TRACE("Enter Process32NextW\n");
	return pProcess32NextW(hSnapshot, lppe);
}

extern WINAPI void wine32a_Process32NextW(void);
__ASM_GLOBAL_FUNC(wine32a_Process32NextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Process32NextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Module32FirstW(HANDLE hSnapshot, LPMODULEENTRY32W lpme)
{
	TRACE("Enter Module32FirstW\n");
	return pModule32FirstW(hSnapshot, lpme);
}

extern WINAPI void wine32a_Module32FirstW(void);
__ASM_GLOBAL_FUNC(wine32a_Module32FirstW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Module32FirstW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Module32NextW(HANDLE hSnapshot, LPMODULEENTRY32W lpme)
{
	TRACE("Enter Module32NextW\n");
	return pModule32NextW(hSnapshot, lpme);
}

extern WINAPI void wine32a_Module32NextW(void);
__ASM_GLOBAL_FUNC(wine32a_Module32NextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Module32NextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Module32First(HANDLE hSnapshot, LPMODULEENTRY32 lpme)
{
	TRACE("Enter Module32First\n");
	return pModule32First(hSnapshot, lpme);
}

extern WINAPI void wine32a_Module32First(void);
__ASM_GLOBAL_FUNC(wine32a_Module32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Module32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Module32Next(HANDLE hSnapshot, LPMODULEENTRY32 lpme)
{
	TRACE("Enter Module32Next\n");
	return pModule32Next(hSnapshot, lpme);
}

extern WINAPI void wine32a_Module32Next(void);
__ASM_GLOBAL_FUNC(wine32a_Module32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Module32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Heap32ListFirst(HANDLE hSnapshot, LPHEAPLIST32 lphl)
{
	TRACE("Enter Heap32ListFirst\n");
	return pHeap32ListFirst(hSnapshot, lphl);
}

extern WINAPI void wine32a_Heap32ListFirst(void);
__ASM_GLOBAL_FUNC(wine32a_Heap32ListFirst,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Heap32ListFirst") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_Toolhelp32ReadProcessMemory(DWORD pid, const void * base, void * buf, SIZE_T len, SIZE_T * r)
{
	TRACE("Enter Toolhelp32ReadProcessMemory\n");
	return pToolhelp32ReadProcessMemory(pid, base, buf, len, r);
}

extern WINAPI void wine32a_Toolhelp32ReadProcessMemory(void);
__ASM_GLOBAL_FUNC(wine32a_Toolhelp32ReadProcessMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_Toolhelp32ReadProcessMemory") "\n"
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

static WINAPI DWORD (*pGetVersion)(void);
static WINAPI BOOL (*pGetVersionExA)(OSVERSIONINFOA * v);
static WINAPI BOOL (*pGetVersionExW)(OSVERSIONINFOW * info);
static WINAPI BOOL (*pVerifyVersionInfoA)(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
static WINAPI BOOL (*pVerifyVersionInfoW)(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
static WINAPI BOOL (*pTermsrvAppInstallMode)(void);
static WINAPI DWORD (*pSetTermsrvAppInstallMode)(BOOL bInstallMode);
static WINAPI BOOL (*pGetProductInfo)(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
static WINAPI LONG (*pGetCurrentPackageId)(UINT32 * len, BYTE * buffer);
static WINAPI LONG (*pGetCurrentPackageFamilyName)(UINT32 * length, PWSTR name);
static WINAPI LONG (*pGetCurrentPackageFullName)(UINT32 * length, PWSTR name);
static WINAPI LONG (*pGetPackageFullName)(HANDLE process, UINT32 * length, PWSTR name);

extern WINAPI DWORD wine32b_GetVersion(void)
{
	TRACE("Enter GetVersion\n");
	return pGetVersion();
}

extern WINAPI void wine32a_GetVersion(void);
__ASM_GLOBAL_FUNC(wine32a_GetVersion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVersion") "\n"
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

extern WINAPI BOOL wine32b_GetVersionExA(OSVERSIONINFOA * v)
{
	TRACE("Enter GetVersionExA\n");
	return pGetVersionExA(v);
}

extern WINAPI void wine32a_GetVersionExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetVersionExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVersionExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetVersionExW(OSVERSIONINFOW * info)
{
	TRACE("Enter GetVersionExW\n");
	return pGetVersionExW(info);
}

extern WINAPI void wine32a_GetVersionExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVersionExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVersionExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
{
	TRACE("Enter VerifyVersionInfoA\n");
	return pVerifyVersionInfoA(lpVersionInfo, dwTypeMask, dwlConditionMask);
}

extern WINAPI void wine32a_VerifyVersionInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_VerifyVersionInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerifyVersionInfoA") "\n"
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

extern WINAPI BOOL wine32b_VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
{
	TRACE("Enter VerifyVersionInfoW\n");
	return pVerifyVersionInfoW(lpVersionInfo, dwTypeMask, dwlConditionMask);
}

extern WINAPI void wine32a_VerifyVersionInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_VerifyVersionInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerifyVersionInfoW") "\n"
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

extern WINAPI BOOL wine32b_TermsrvAppInstallMode(void)
{
	TRACE("Enter TermsrvAppInstallMode\n");
	return pTermsrvAppInstallMode();
}

extern WINAPI void wine32a_TermsrvAppInstallMode(void);
__ASM_GLOBAL_FUNC(wine32a_TermsrvAppInstallMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TermsrvAppInstallMode") "\n"
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

extern WINAPI DWORD wine32b_SetTermsrvAppInstallMode(BOOL bInstallMode)
{
	TRACE("Enter SetTermsrvAppInstallMode\n");
	return pSetTermsrvAppInstallMode(bInstallMode);
}

extern WINAPI void wine32a_SetTermsrvAppInstallMode(void);
__ASM_GLOBAL_FUNC(wine32a_SetTermsrvAppInstallMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetTermsrvAppInstallMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetProductInfo(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType)
{
	TRACE("Enter GetProductInfo\n");
	return pGetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
}

extern WINAPI void wine32a_GetProductInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetProductInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetProductInfo") "\n"
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

extern WINAPI LONG wine32b_GetCurrentPackageId(UINT32 * len, BYTE * buffer)
{
	TRACE("Enter GetCurrentPackageId\n");
	return pGetCurrentPackageId(len, buffer);
}

extern WINAPI void wine32a_GetCurrentPackageId(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentPackageId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentPackageId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_GetCurrentPackageFamilyName(UINT32 * length, PWSTR name)
{
	TRACE("Enter GetCurrentPackageFamilyName\n");
	return pGetCurrentPackageFamilyName(length, name);
}

extern WINAPI void wine32a_GetCurrentPackageFamilyName(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentPackageFamilyName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentPackageFamilyName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_GetCurrentPackageFullName(UINT32 * length, PWSTR name)
{
	TRACE("Enter GetCurrentPackageFullName\n");
	return pGetCurrentPackageFullName(length, name);
}

extern WINAPI void wine32a_GetCurrentPackageFullName(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentPackageFullName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentPackageFullName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_GetPackageFullName(HANDLE process, UINT32 * length, PWSTR name)
{
	TRACE("Enter GetPackageFullName\n");
	return pGetPackageFullName(process, length, name);
}

extern WINAPI void wine32a_GetPackageFullName(void);
__ASM_GLOBAL_FUNC(wine32a_GetPackageFullName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetPackageFullName") "\n"
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

static WINAPI LPVOID (*pVirtualAlloc)(void * addr, SIZE_T size, DWORD type, DWORD protect);
static WINAPI LPVOID (*pVirtualAllocEx)(HANDLE hProcess, LPVOID addr, SIZE_T size, DWORD type, DWORD protect);
static WINAPI LPVOID (*pVirtualAllocExNuma)(HANDLE process, void * addr, SIZE_T size, DWORD type, DWORD protect, DWORD numa_node);
static WINAPI BOOL (*pVirtualFree)(LPVOID addr, SIZE_T size, DWORD type);
static WINAPI BOOL (*pVirtualFreeEx)(HANDLE process, LPVOID addr, SIZE_T size, DWORD type);
static WINAPI BOOL (*pVirtualLock)(LPVOID addr, SIZE_T size);
static WINAPI BOOL (*pVirtualUnlock)(LPVOID addr, SIZE_T size);
static WINAPI BOOL (*pVirtualProtect)(LPVOID addr, SIZE_T size, DWORD new_prot, LPDWORD old_prot);
static WINAPI BOOL (*pVirtualProtectEx)(HANDLE process, LPVOID addr, SIZE_T size, DWORD new_prot, LPDWORD old_prot);
static WINAPI SIZE_T (*pVirtualQuery)(LPCVOID addr, PMEMORY_BASIC_INFORMATION info, SIZE_T len);
static WINAPI SIZE_T (*pVirtualQueryEx)(HANDLE process, LPCVOID addr, PMEMORY_BASIC_INFORMATION info, SIZE_T len);
static WINAPI LPVOID (*pMapViewOfFile)(HANDLE mapping, DWORD access, DWORD offset_high, DWORD offset_low, SIZE_T count);
static WINAPI LPVOID (*pMapViewOfFileEx)(HANDLE handle, DWORD access, DWORD offset_high, DWORD offset_low, SIZE_T count, LPVOID addr);
static WINAPI BOOL (*pUnmapViewOfFile)(const void * addr);
static WINAPI BOOL (*pFlushViewOfFile)(LPCVOID base, SIZE_T size);
static WINAPI UINT (*pGetWriteWatch)(DWORD flags, LPVOID base, SIZE_T size, LPVOID * addresses, ULONG_PTR * count, ULONG * granularity);
static WINAPI UINT (*pResetWriteWatch)(LPVOID base, SIZE_T size);
static WINAPI BOOL (*pIsBadReadPtr)(LPCVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadWritePtr)(LPVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadHugeReadPtr)(LPCVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadHugeWritePtr)(LPVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadCodePtr)(FARPROC ptr);
static WINAPI BOOL (*pIsBadStringPtrA)(LPCSTR str, UINT_PTR max);
static WINAPI BOOL (*pIsBadStringPtrW)(LPCWSTR str, UINT_PTR max);
static WINAPI DWORD (*pK32GetMappedFileNameA)(HANDLE process, LPVOID lpv, LPSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetMappedFileNameW)(HANDLE process, LPVOID lpv, LPWSTR file_name, DWORD size);
static WINAPI BOOL (*pK32EnumPageFilesA)(PENUM_PAGE_FILE_CALLBACKA callback, LPVOID context);
static WINAPI BOOL (*pK32EnumPageFilesW)(PENUM_PAGE_FILE_CALLBACKW callback, LPVOID context);
static WINAPI BOOL (*pK32GetWsChanges)(HANDLE process, PPSAPI_WS_WATCH_INFORMATION watchinfo, DWORD size);
static WINAPI BOOL (*pK32GetWsChangesEx)(HANDLE process, PSAPI_WS_WATCH_INFORMATION_EX * watchinfoex, DWORD * size);
static WINAPI BOOL (*pK32InitializeProcessForWsWatch)(HANDLE process);

extern WINAPI LPVOID wine32b_VirtualAlloc(void * addr, SIZE_T size, DWORD type, DWORD protect)
{
	TRACE("Enter VirtualAlloc\n");
	return pVirtualAlloc(addr, size, type, protect);
}

extern WINAPI void wine32a_VirtualAlloc(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualAlloc") "\n"
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

extern WINAPI LPVOID wine32b_VirtualAllocEx(HANDLE hProcess, LPVOID addr, SIZE_T size, DWORD type, DWORD protect)
{
	TRACE("Enter VirtualAllocEx\n");
	return pVirtualAllocEx(hProcess, addr, size, type, protect);
}

extern WINAPI void wine32a_VirtualAllocEx(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualAllocEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualAllocEx") "\n"
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

extern WINAPI LPVOID wine32b_VirtualAllocExNuma(HANDLE process, void * addr, SIZE_T size, DWORD type, DWORD protect, DWORD numa_node)
{
	TRACE("Enter VirtualAllocExNuma\n");
	return pVirtualAllocExNuma(process, addr, size, type, protect, numa_node);
}

extern WINAPI void wine32a_VirtualAllocExNuma(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualAllocExNuma,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualAllocExNuma") "\n"
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

extern WINAPI BOOL wine32b_VirtualFree(LPVOID addr, SIZE_T size, DWORD type)
{
	TRACE("Enter VirtualFree\n");
	return pVirtualFree(addr, size, type);
}

extern WINAPI void wine32a_VirtualFree(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualFree") "\n"
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

extern WINAPI BOOL wine32b_VirtualFreeEx(HANDLE process, LPVOID addr, SIZE_T size, DWORD type)
{
	TRACE("Enter VirtualFreeEx\n");
	return pVirtualFreeEx(process, addr, size, type);
}

extern WINAPI void wine32a_VirtualFreeEx(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualFreeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualFreeEx") "\n"
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

extern WINAPI BOOL wine32b_VirtualLock(LPVOID addr, SIZE_T size)
{
	TRACE("Enter VirtualLock\n");
	return pVirtualLock(addr, size);
}

extern WINAPI void wine32a_VirtualLock(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_VirtualUnlock(LPVOID addr, SIZE_T size)
{
	TRACE("Enter VirtualUnlock\n");
	return pVirtualUnlock(addr, size);
}

extern WINAPI void wine32a_VirtualUnlock(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualUnlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualUnlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_VirtualProtect(LPVOID addr, SIZE_T size, DWORD new_prot, LPDWORD old_prot)
{
	TRACE("Enter VirtualProtect\n");
	return pVirtualProtect(addr, size, new_prot, old_prot);
}

extern WINAPI void wine32a_VirtualProtect(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualProtect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualProtect") "\n"
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

extern WINAPI BOOL wine32b_VirtualProtectEx(HANDLE process, LPVOID addr, SIZE_T size, DWORD new_prot, LPDWORD old_prot)
{
	TRACE("Enter VirtualProtectEx\n");
	return pVirtualProtectEx(process, addr, size, new_prot, old_prot);
}

extern WINAPI void wine32a_VirtualProtectEx(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualProtectEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualProtectEx") "\n"
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

extern WINAPI SIZE_T wine32b_VirtualQuery(LPCVOID addr, PMEMORY_BASIC_INFORMATION info, SIZE_T len)
{
	TRACE("Enter VirtualQuery\n");
	return pVirtualQuery(addr, info, len);
}

extern WINAPI void wine32a_VirtualQuery(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualQuery,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualQuery") "\n"
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

extern WINAPI SIZE_T wine32b_VirtualQueryEx(HANDLE process, LPCVOID addr, PMEMORY_BASIC_INFORMATION info, SIZE_T len)
{
	TRACE("Enter VirtualQueryEx\n");
	return pVirtualQueryEx(process, addr, info, len);
}

extern WINAPI void wine32a_VirtualQueryEx(void);
__ASM_GLOBAL_FUNC(wine32a_VirtualQueryEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VirtualQueryEx") "\n"
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

extern WINAPI LPVOID wine32b_MapViewOfFile(HANDLE mapping, DWORD access, DWORD offset_high, DWORD offset_low, SIZE_T count)
{
	TRACE("Enter MapViewOfFile\n");
	return pMapViewOfFile(mapping, access, offset_high, offset_low, count);
}

extern WINAPI void wine32a_MapViewOfFile(void);
__ASM_GLOBAL_FUNC(wine32a_MapViewOfFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapViewOfFile") "\n"
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

extern WINAPI LPVOID wine32b_MapViewOfFileEx(HANDLE handle, DWORD access, DWORD offset_high, DWORD offset_low, SIZE_T count, LPVOID addr)
{
	TRACE("Enter MapViewOfFileEx\n");
	return pMapViewOfFileEx(handle, access, offset_high, offset_low, count, addr);
}

extern WINAPI void wine32a_MapViewOfFileEx(void);
__ASM_GLOBAL_FUNC(wine32a_MapViewOfFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MapViewOfFileEx") "\n"
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

extern WINAPI BOOL wine32b_UnmapViewOfFile(const void * addr)
{
	TRACE("Enter UnmapViewOfFile\n");
	return pUnmapViewOfFile(addr);
}

extern WINAPI void wine32a_UnmapViewOfFile(void);
__ASM_GLOBAL_FUNC(wine32a_UnmapViewOfFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_UnmapViewOfFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FlushViewOfFile(LPCVOID base, SIZE_T size)
{
	TRACE("Enter FlushViewOfFile\n");
	return pFlushViewOfFile(base, size);
}

extern WINAPI void wine32a_FlushViewOfFile(void);
__ASM_GLOBAL_FUNC(wine32a_FlushViewOfFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlushViewOfFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetWriteWatch(DWORD flags, LPVOID base, SIZE_T size, LPVOID * addresses, ULONG_PTR * count, ULONG * granularity)
{
	TRACE("Enter GetWriteWatch\n");
	return pGetWriteWatch(flags, base, size, addresses, count, granularity);
}

extern WINAPI void wine32a_GetWriteWatch(void);
__ASM_GLOBAL_FUNC(wine32a_GetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetWriteWatch") "\n"
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

extern WINAPI UINT wine32b_ResetWriteWatch(LPVOID base, SIZE_T size)
{
	TRACE("Enter ResetWriteWatch\n");
	return pResetWriteWatch(base, size);
}

extern WINAPI void wine32a_ResetWriteWatch(void);
__ASM_GLOBAL_FUNC(wine32a_ResetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ResetWriteWatch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadReadPtr(LPCVOID ptr, UINT_PTR size)
{
	TRACE("Enter IsBadReadPtr\n");
	return pIsBadReadPtr(ptr, size);
}

extern WINAPI void wine32a_IsBadReadPtr(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadReadPtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadReadPtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadWritePtr(LPVOID ptr, UINT_PTR size)
{
	TRACE("Enter IsBadWritePtr\n");
	return pIsBadWritePtr(ptr, size);
}

extern WINAPI void wine32a_IsBadWritePtr(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadWritePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadWritePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadHugeReadPtr(LPCVOID ptr, UINT_PTR size)
{
	TRACE("Enter IsBadHugeReadPtr\n");
	return pIsBadHugeReadPtr(ptr, size);
}

extern WINAPI void wine32a_IsBadHugeReadPtr(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadHugeReadPtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadHugeReadPtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadHugeWritePtr(LPVOID ptr, UINT_PTR size)
{
	TRACE("Enter IsBadHugeWritePtr\n");
	return pIsBadHugeWritePtr(ptr, size);
}

extern WINAPI void wine32a_IsBadHugeWritePtr(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadHugeWritePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadHugeWritePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadCodePtr(FARPROC ptr)
{
	TRACE("Enter IsBadCodePtr\n");
	return pIsBadCodePtr(ptr);
}

extern WINAPI void wine32a_IsBadCodePtr(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadCodePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadCodePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadStringPtrA(LPCSTR str, UINT_PTR max)
{
	TRACE("Enter IsBadStringPtrA\n");
	return pIsBadStringPtrA(str, max);
}

extern WINAPI void wine32a_IsBadStringPtrA(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadStringPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadStringPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsBadStringPtrW(LPCWSTR str, UINT_PTR max)
{
	TRACE("Enter IsBadStringPtrW\n");
	return pIsBadStringPtrW(str, max);
}

extern WINAPI void wine32a_IsBadStringPtrW(void);
__ASM_GLOBAL_FUNC(wine32a_IsBadStringPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsBadStringPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_K32GetMappedFileNameA(HANDLE process, LPVOID lpv, LPSTR file_name, DWORD size)
{
	TRACE("Enter K32GetMappedFileNameA\n");
	return pK32GetMappedFileNameA(process, lpv, file_name, size);
}

extern WINAPI void wine32a_K32GetMappedFileNameA(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetMappedFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetMappedFileNameA") "\n"
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

extern WINAPI DWORD wine32b_K32GetMappedFileNameW(HANDLE process, LPVOID lpv, LPWSTR file_name, DWORD size)
{
	TRACE("Enter K32GetMappedFileNameW\n");
	return pK32GetMappedFileNameW(process, lpv, file_name, size);
}

extern WINAPI void wine32a_K32GetMappedFileNameW(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetMappedFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetMappedFileNameW") "\n"
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

extern WINAPI BOOL wine32b_K32EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA callback, LPVOID context)
{
	TRACE("Enter K32EnumPageFilesA\n");
	return pK32EnumPageFilesA(callback, context);
}

extern WINAPI void wine32a_K32EnumPageFilesA(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumPageFilesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumPageFilesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_K32EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW callback, LPVOID context)
{
	TRACE("Enter K32EnumPageFilesW\n");
	return pK32EnumPageFilesW(callback, context);
}

extern WINAPI void wine32a_K32EnumPageFilesW(void);
__ASM_GLOBAL_FUNC(wine32a_K32EnumPageFilesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32EnumPageFilesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_K32GetWsChanges(HANDLE process, PPSAPI_WS_WATCH_INFORMATION watchinfo, DWORD size)
{
	TRACE("Enter K32GetWsChanges\n");
	return pK32GetWsChanges(process, watchinfo, size);
}

extern WINAPI void wine32a_K32GetWsChanges(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetWsChanges,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetWsChanges") "\n"
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

extern WINAPI BOOL wine32b_K32GetWsChangesEx(HANDLE process, PSAPI_WS_WATCH_INFORMATION_EX * watchinfoex, DWORD * size)
{
	TRACE("Enter K32GetWsChangesEx\n");
	return pK32GetWsChangesEx(process, watchinfoex, size);
}

extern WINAPI void wine32a_K32GetWsChangesEx(void);
__ASM_GLOBAL_FUNC(wine32a_K32GetWsChangesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32GetWsChangesEx") "\n"
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

extern WINAPI BOOL wine32b_K32InitializeProcessForWsWatch(HANDLE process)
{
	TRACE("Enter K32InitializeProcessForWsWatch\n");
	return pK32InitializeProcessForWsWatch(process);
}

extern WINAPI void wine32a_K32InitializeProcessForWsWatch(void);
__ASM_GLOBAL_FUNC(wine32a_K32InitializeProcessForWsWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_K32InitializeProcessForWsWatch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOL (*pGetVolumeInformationW)(LPCWSTR root, LPWSTR label, DWORD label_len, DWORD * serial, DWORD * filename_len, DWORD * flags, LPWSTR fsname, DWORD fsname_len);
static WINAPI BOOL (*pGetVolumeInformationA)(LPCSTR root, LPSTR label, DWORD label_len, DWORD * serial, DWORD * filename_len, DWORD * flags, LPSTR fsname, DWORD fsname_len);
static WINAPI BOOL (*pSetVolumeLabelW)(LPCWSTR root, LPCWSTR label);
static WINAPI BOOL (*pSetVolumeLabelA)(LPCSTR root, LPCSTR volname);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointA)(LPCSTR path, LPSTR volume, DWORD size);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointW)(LPCWSTR path, LPWSTR volume, DWORD size);
static WINAPI BOOL (*pDefineDosDeviceW)(DWORD flags, LPCWSTR devname, LPCWSTR targetpath);
static WINAPI BOOL (*pDefineDosDeviceA)(DWORD flags, LPCSTR devname, LPCSTR targetpath);
static WINAPI DWORD (*pQueryDosDeviceW)(LPCWSTR devname, LPWSTR target, DWORD bufsize);
static WINAPI DWORD (*pQueryDosDeviceA)(LPCSTR devname, LPSTR target, DWORD bufsize);
static WINAPI DWORD (*pGetLogicalDrives)(void);
static WINAPI UINT (*pGetLogicalDriveStringsA)(UINT len, LPSTR buffer);
static WINAPI UINT (*pGetLogicalDriveStringsW)(UINT len, LPWSTR buffer);
static WINAPI UINT (*pGetDriveTypeW)(LPCWSTR root);
static WINAPI UINT (*pGetDriveTypeA)(LPCSTR root);
static WINAPI BOOL (*pGetDiskFreeSpaceExW)(LPCWSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceExA)(LPCSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceW)(LPCWSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters);
static WINAPI BOOL (*pGetDiskFreeSpaceA)(LPCSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters);
static WINAPI BOOL (*pGetVolumePathNameA)(LPCSTR filename, LPSTR volumepathname, DWORD buflen);
static WINAPI BOOL (*pGetVolumePathNameW)(LPCWSTR filename, LPWSTR volumepathname, DWORD buflen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameA)(LPCSTR volumename, LPSTR volumepathname, DWORD buflen, PDWORD returnlen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameW)(LPCWSTR volumename, LPWSTR volumepathname, DWORD buflen, PDWORD returnlen);
static WINAPI HANDLE (*pFindFirstVolumeA)(LPSTR volume, DWORD len);
static WINAPI HANDLE (*pFindFirstVolumeW)(LPWSTR volume, DWORD len);
static WINAPI BOOL (*pFindNextVolumeA)(HANDLE handle, LPSTR volume, DWORD len);
static WINAPI BOOL (*pFindNextVolumeW)(HANDLE handle, LPWSTR volume, DWORD len);
static WINAPI BOOL (*pFindVolumeClose)(HANDLE handle);
static WINAPI HANDLE (*pFindFirstVolumeMountPointA)(LPCSTR root, LPSTR mount_point, DWORD len);
static WINAPI HANDLE (*pFindFirstVolumeMountPointW)(LPCWSTR root, LPWSTR mount_point, DWORD len);
static WINAPI BOOL (*pFindVolumeMountPointClose)(HANDLE h);
static WINAPI BOOL (*pDeleteVolumeMountPointA)(LPCSTR mountpoint);
static WINAPI BOOL (*pDeleteVolumeMountPointW)(LPCWSTR mountpoint);
static WINAPI BOOL (*pSetVolumeMountPointA)(LPCSTR path, LPCSTR volume);
static WINAPI BOOL (*pSetVolumeMountPointW)(LPCWSTR path, LPCWSTR volume);
static WINAPI BOOL (*pGetVolumeInformationByHandleW)(HANDLE handle, WCHAR * volnamebuf, DWORD volnamesize, DWORD * volserial, DWORD * maxlength, DWORD * flags, WCHAR * fsnamebuf, DWORD fsnamesize);

extern WINAPI BOOL wine32b_GetVolumeInformationW(LPCWSTR root, LPWSTR label, DWORD label_len, DWORD * serial, DWORD * filename_len, DWORD * flags, LPWSTR fsname, DWORD fsname_len)
{
	TRACE("Enter GetVolumeInformationW\n");
	return pGetVolumeInformationW(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
}

extern WINAPI void wine32a_GetVolumeInformationW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumeInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumeInformationW") "\n"
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

extern WINAPI BOOL wine32b_GetVolumeInformationA(LPCSTR root, LPSTR label, DWORD label_len, DWORD * serial, DWORD * filename_len, DWORD * flags, LPSTR fsname, DWORD fsname_len)
{
	TRACE("Enter GetVolumeInformationA\n");
	return pGetVolumeInformationA(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
}

extern WINAPI void wine32a_GetVolumeInformationA(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumeInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumeInformationA") "\n"
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

extern WINAPI BOOL wine32b_SetVolumeLabelW(LPCWSTR root, LPCWSTR label)
{
	TRACE("Enter SetVolumeLabelW\n");
	return pSetVolumeLabelW(root, label);
}

extern WINAPI void wine32a_SetVolumeLabelW(void);
__ASM_GLOBAL_FUNC(wine32a_SetVolumeLabelW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetVolumeLabelW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetVolumeLabelA(LPCSTR root, LPCSTR volname)
{
	TRACE("Enter SetVolumeLabelA\n");
	return pSetVolumeLabelA(root, volname);
}

extern WINAPI void wine32a_SetVolumeLabelA(void);
__ASM_GLOBAL_FUNC(wine32a_SetVolumeLabelA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetVolumeLabelA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetVolumeNameForVolumeMountPointA(LPCSTR path, LPSTR volume, DWORD size)
{
	TRACE("Enter GetVolumeNameForVolumeMountPointA\n");
	return pGetVolumeNameForVolumeMountPointA(path, volume, size);
}

extern WINAPI void wine32a_GetVolumeNameForVolumeMountPointA(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumeNameForVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumeNameForVolumeMountPointA") "\n"
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

extern WINAPI BOOL wine32b_GetVolumeNameForVolumeMountPointW(LPCWSTR path, LPWSTR volume, DWORD size)
{
	TRACE("Enter GetVolumeNameForVolumeMountPointW\n");
	return pGetVolumeNameForVolumeMountPointW(path, volume, size);
}

extern WINAPI void wine32a_GetVolumeNameForVolumeMountPointW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumeNameForVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumeNameForVolumeMountPointW") "\n"
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

extern WINAPI BOOL wine32b_DefineDosDeviceW(DWORD flags, LPCWSTR devname, LPCWSTR targetpath)
{
	TRACE("Enter DefineDosDeviceW\n");
	return pDefineDosDeviceW(flags, devname, targetpath);
}

extern WINAPI void wine32a_DefineDosDeviceW(void);
__ASM_GLOBAL_FUNC(wine32a_DefineDosDeviceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefineDosDeviceW") "\n"
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

extern WINAPI BOOL wine32b_DefineDosDeviceA(DWORD flags, LPCSTR devname, LPCSTR targetpath)
{
	TRACE("Enter DefineDosDeviceA\n");
	return pDefineDosDeviceA(flags, devname, targetpath);
}

extern WINAPI void wine32a_DefineDosDeviceA(void);
__ASM_GLOBAL_FUNC(wine32a_DefineDosDeviceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DefineDosDeviceA") "\n"
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

extern WINAPI DWORD wine32b_QueryDosDeviceW(LPCWSTR devname, LPWSTR target, DWORD bufsize)
{
	TRACE("Enter QueryDosDeviceW\n");
	return pQueryDosDeviceW(devname, target, bufsize);
}

extern WINAPI void wine32a_QueryDosDeviceW(void);
__ASM_GLOBAL_FUNC(wine32a_QueryDosDeviceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryDosDeviceW") "\n"
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

extern WINAPI DWORD wine32b_QueryDosDeviceA(LPCSTR devname, LPSTR target, DWORD bufsize)
{
	TRACE("Enter QueryDosDeviceA\n");
	return pQueryDosDeviceA(devname, target, bufsize);
}

extern WINAPI void wine32a_QueryDosDeviceA(void);
__ASM_GLOBAL_FUNC(wine32a_QueryDosDeviceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryDosDeviceA") "\n"
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

extern WINAPI DWORD wine32b_GetLogicalDrives(void)
{
	TRACE("Enter GetLogicalDrives\n");
	return pGetLogicalDrives();
}

extern WINAPI void wine32a_GetLogicalDrives(void);
__ASM_GLOBAL_FUNC(wine32a_GetLogicalDrives,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLogicalDrives") "\n"
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

extern WINAPI UINT wine32b_GetLogicalDriveStringsA(UINT len, LPSTR buffer)
{
	TRACE("Enter GetLogicalDriveStringsA\n");
	return pGetLogicalDriveStringsA(len, buffer);
}

extern WINAPI void wine32a_GetLogicalDriveStringsA(void);
__ASM_GLOBAL_FUNC(wine32a_GetLogicalDriveStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLogicalDriveStringsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetLogicalDriveStringsW(UINT len, LPWSTR buffer)
{
	TRACE("Enter GetLogicalDriveStringsW\n");
	return pGetLogicalDriveStringsW(len, buffer);
}

extern WINAPI void wine32a_GetLogicalDriveStringsW(void);
__ASM_GLOBAL_FUNC(wine32a_GetLogicalDriveStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetLogicalDriveStringsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetDriveTypeW(LPCWSTR root)
{
	TRACE("Enter GetDriveTypeW\n");
	return pGetDriveTypeW(root);
}

extern WINAPI void wine32a_GetDriveTypeW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDriveTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDriveTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_GetDriveTypeA(LPCSTR root)
{
	TRACE("Enter GetDriveTypeA\n");
	return pGetDriveTypeA(root);
}

extern WINAPI void wine32a_GetDriveTypeA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDriveTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDriveTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetDiskFreeSpaceExW(LPCWSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree)
{
	TRACE("Enter GetDiskFreeSpaceExW\n");
	return pGetDiskFreeSpaceExW(root, avail, total, totalfree);
}

extern WINAPI void wine32a_GetDiskFreeSpaceExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDiskFreeSpaceExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDiskFreeSpaceExW") "\n"
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

extern WINAPI BOOL wine32b_GetDiskFreeSpaceExA(LPCSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree)
{
	TRACE("Enter GetDiskFreeSpaceExA\n");
	return pGetDiskFreeSpaceExA(root, avail, total, totalfree);
}

extern WINAPI void wine32a_GetDiskFreeSpaceExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDiskFreeSpaceExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDiskFreeSpaceExA") "\n"
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

extern WINAPI BOOL wine32b_GetDiskFreeSpaceW(LPCWSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters)
{
	TRACE("Enter GetDiskFreeSpaceW\n");
	return pGetDiskFreeSpaceW(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
}

extern WINAPI void wine32a_GetDiskFreeSpaceW(void);
__ASM_GLOBAL_FUNC(wine32a_GetDiskFreeSpaceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDiskFreeSpaceW") "\n"
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

extern WINAPI BOOL wine32b_GetDiskFreeSpaceA(LPCSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters)
{
	TRACE("Enter GetDiskFreeSpaceA\n");
	return pGetDiskFreeSpaceA(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
}

extern WINAPI void wine32a_GetDiskFreeSpaceA(void);
__ASM_GLOBAL_FUNC(wine32a_GetDiskFreeSpaceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetDiskFreeSpaceA") "\n"
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

extern WINAPI BOOL wine32b_GetVolumePathNameA(LPCSTR filename, LPSTR volumepathname, DWORD buflen)
{
	TRACE("Enter GetVolumePathNameA\n");
	return pGetVolumePathNameA(filename, volumepathname, buflen);
}

extern WINAPI void wine32a_GetVolumePathNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumePathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumePathNameA") "\n"
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

extern WINAPI BOOL wine32b_GetVolumePathNameW(LPCWSTR filename, LPWSTR volumepathname, DWORD buflen)
{
	TRACE("Enter GetVolumePathNameW\n");
	return pGetVolumePathNameW(filename, volumepathname, buflen);
}

extern WINAPI void wine32a_GetVolumePathNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumePathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumePathNameW") "\n"
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

extern WINAPI BOOL wine32b_GetVolumePathNamesForVolumeNameA(LPCSTR volumename, LPSTR volumepathname, DWORD buflen, PDWORD returnlen)
{
	TRACE("Enter GetVolumePathNamesForVolumeNameA\n");
	return pGetVolumePathNamesForVolumeNameA(volumename, volumepathname, buflen, returnlen);
}

extern WINAPI void wine32a_GetVolumePathNamesForVolumeNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumePathNamesForVolumeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumePathNamesForVolumeNameA") "\n"
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

extern WINAPI BOOL wine32b_GetVolumePathNamesForVolumeNameW(LPCWSTR volumename, LPWSTR volumepathname, DWORD buflen, PDWORD returnlen)
{
	TRACE("Enter GetVolumePathNamesForVolumeNameW\n");
	return pGetVolumePathNamesForVolumeNameW(volumename, volumepathname, buflen, returnlen);
}

extern WINAPI void wine32a_GetVolumePathNamesForVolumeNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumePathNamesForVolumeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumePathNamesForVolumeNameW") "\n"
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

extern WINAPI HANDLE wine32b_FindFirstVolumeA(LPSTR volume, DWORD len)
{
	TRACE("Enter FindFirstVolumeA\n");
	return pFindFirstVolumeA(volume, len);
}

extern WINAPI void wine32a_FindFirstVolumeA(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstVolumeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstVolumeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_FindFirstVolumeW(LPWSTR volume, DWORD len)
{
	TRACE("Enter FindFirstVolumeW\n");
	return pFindFirstVolumeW(volume, len);
}

extern WINAPI void wine32a_FindFirstVolumeW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstVolumeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstVolumeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FindNextVolumeA(HANDLE handle, LPSTR volume, DWORD len)
{
	TRACE("Enter FindNextVolumeA\n");
	return pFindNextVolumeA(handle, volume, len);
}

extern WINAPI void wine32a_FindNextVolumeA(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextVolumeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextVolumeA") "\n"
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

extern WINAPI BOOL wine32b_FindNextVolumeW(HANDLE handle, LPWSTR volume, DWORD len)
{
	TRACE("Enter FindNextVolumeW\n");
	return pFindNextVolumeW(handle, volume, len);
}

extern WINAPI void wine32a_FindNextVolumeW(void);
__ASM_GLOBAL_FUNC(wine32a_FindNextVolumeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindNextVolumeW") "\n"
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

extern WINAPI BOOL wine32b_FindVolumeClose(HANDLE handle)
{
	TRACE("Enter FindVolumeClose\n");
	return pFindVolumeClose(handle);
}

extern WINAPI void wine32a_FindVolumeClose(void);
__ASM_GLOBAL_FUNC(wine32a_FindVolumeClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindVolumeClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_FindFirstVolumeMountPointA(LPCSTR root, LPSTR mount_point, DWORD len)
{
	TRACE("Enter FindFirstVolumeMountPointA\n");
	return pFindFirstVolumeMountPointA(root, mount_point, len);
}

extern WINAPI void wine32a_FindFirstVolumeMountPointA(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstVolumeMountPointA") "\n"
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

extern WINAPI HANDLE wine32b_FindFirstVolumeMountPointW(LPCWSTR root, LPWSTR mount_point, DWORD len)
{
	TRACE("Enter FindFirstVolumeMountPointW\n");
	return pFindFirstVolumeMountPointW(root, mount_point, len);
}

extern WINAPI void wine32a_FindFirstVolumeMountPointW(void);
__ASM_GLOBAL_FUNC(wine32a_FindFirstVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindFirstVolumeMountPointW") "\n"
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

extern WINAPI BOOL wine32b_FindVolumeMountPointClose(HANDLE h)
{
	TRACE("Enter FindVolumeMountPointClose\n");
	return pFindVolumeMountPointClose(h);
}

extern WINAPI void wine32a_FindVolumeMountPointClose(void);
__ASM_GLOBAL_FUNC(wine32a_FindVolumeMountPointClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FindVolumeMountPointClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteVolumeMountPointA(LPCSTR mountpoint)
{
	TRACE("Enter DeleteVolumeMountPointA\n");
	return pDeleteVolumeMountPointA(mountpoint);
}

extern WINAPI void wine32a_DeleteVolumeMountPointA(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeleteVolumeMountPointW(LPCWSTR mountpoint)
{
	TRACE("Enter DeleteVolumeMountPointW\n");
	return pDeleteVolumeMountPointW(mountpoint);
}

extern WINAPI void wine32a_DeleteVolumeMountPointW(void);
__ASM_GLOBAL_FUNC(wine32a_DeleteVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeleteVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetVolumeMountPointA(LPCSTR path, LPCSTR volume)
{
	TRACE("Enter SetVolumeMountPointA\n");
	return pSetVolumeMountPointA(path, volume);
}

extern WINAPI void wine32a_SetVolumeMountPointA(void);
__ASM_GLOBAL_FUNC(wine32a_SetVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SetVolumeMountPointW(LPCWSTR path, LPCWSTR volume)
{
	TRACE("Enter SetVolumeMountPointW\n");
	return pSetVolumeMountPointW(path, volume);
}

extern WINAPI void wine32a_SetVolumeMountPointW(void);
__ASM_GLOBAL_FUNC(wine32a_SetVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetVolumeInformationByHandleW(HANDLE handle, WCHAR * volnamebuf, DWORD volnamesize, DWORD * volserial, DWORD * maxlength, DWORD * flags, WCHAR * fsnamebuf, DWORD fsnamesize)
{
	TRACE("Enter GetVolumeInformationByHandleW\n");
	return pGetVolumeInformationByHandleW(handle, volnamebuf, volnamesize, volserial, maxlength, flags, fsnamebuf, fsnamesize);
}

extern WINAPI void wine32a_GetVolumeInformationByHandleW(void);
__ASM_GLOBAL_FUNC(wine32a_GetVolumeInformationByHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetVolumeInformationByHandleW") "\n"
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


static WINAPI HRESULT (*pWerRegisterFile)(PCWSTR file, WER_REGISTER_FILE_TYPE regfiletype, DWORD flags);
static WINAPI HRESULT (*pWerRegisterRuntimeExceptionModule)(PCWSTR callbackdll, PVOID context);
static WINAPI HRESULT (*pWerSetFlags)(DWORD flags);
static WINAPI HRESULT (*pWerRegisterMemoryBlock)(void * block, DWORD size);
static WINAPI HRESULT (*pWerUnregisterMemoryBlock)(void * block);
static WINAPI HRESULT (*pWerUnregisterRuntimeExceptionModule)(PCWSTR callbackdll, PVOID context);

extern WINAPI HRESULT wine32b_WerRegisterFile(PCWSTR file, WER_REGISTER_FILE_TYPE regfiletype, DWORD flags)
{
	TRACE("Enter WerRegisterFile\n");
	return pWerRegisterFile(file, regfiletype, flags);
}

extern WINAPI void wine32a_WerRegisterFile(void);
__ASM_GLOBAL_FUNC(wine32a_WerRegisterFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerRegisterFile") "\n"
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

extern WINAPI HRESULT wine32b_WerRegisterRuntimeExceptionModule(PCWSTR callbackdll, PVOID context)
{
	TRACE("Enter WerRegisterRuntimeExceptionModule\n");
	return pWerRegisterRuntimeExceptionModule(callbackdll, context);
}

extern WINAPI void wine32a_WerRegisterRuntimeExceptionModule(void);
__ASM_GLOBAL_FUNC(wine32a_WerRegisterRuntimeExceptionModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerRegisterRuntimeExceptionModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_WerSetFlags(DWORD flags)
{
	TRACE("Enter WerSetFlags\n");
	return pWerSetFlags(flags);
}

extern WINAPI void wine32a_WerSetFlags(void);
__ASM_GLOBAL_FUNC(wine32a_WerSetFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerSetFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_WerRegisterMemoryBlock(void * block, DWORD size)
{
	TRACE("Enter WerRegisterMemoryBlock\n");
	return pWerRegisterMemoryBlock(block, size);
}

extern WINAPI void wine32a_WerRegisterMemoryBlock(void);
__ASM_GLOBAL_FUNC(wine32a_WerRegisterMemoryBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerRegisterMemoryBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_WerUnregisterMemoryBlock(void * block)
{
	TRACE("Enter WerUnregisterMemoryBlock\n");
	return pWerUnregisterMemoryBlock(block);
}

extern WINAPI void wine32a_WerUnregisterMemoryBlock(void);
__ASM_GLOBAL_FUNC(wine32a_WerUnregisterMemoryBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerUnregisterMemoryBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_WerUnregisterRuntimeExceptionModule(PCWSTR callbackdll, PVOID context)
{
	TRACE("Enter WerUnregisterRuntimeExceptionModule\n");
	return pWerUnregisterRuntimeExceptionModule(callbackdll, context);
}

extern WINAPI void wine32a_WerUnregisterRuntimeExceptionModule(void);
__ASM_GLOBAL_FUNC(wine32a_WerUnregisterRuntimeExceptionModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WerUnregisterRuntimeExceptionModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
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

void wine_thunk_initialize_kernel32(void)
{
	HMODULE library = LoadLibraryA("kernel32.dll");
	pCreateActCtxA = (void *)GetProcAddress(library, "CreateActCtxA");
	pFindActCtxSectionStringA = (void *)GetProcAddress(library, "FindActCtxSectionStringA");
	pInitAtomTable = (void *)GetProcAddress(library, "InitAtomTable");
	pGlobalAddAtomA = (void *)GetProcAddress(library, "GlobalAddAtomA");
	pAddAtomA = (void *)GetProcAddress(library, "AddAtomA");
	pGlobalAddAtomW = (void *)GetProcAddress(library, "GlobalAddAtomW");
	pAddAtomW = (void *)GetProcAddress(library, "AddAtomW");
	pGlobalDeleteAtom = (void *)GetProcAddress(library, "GlobalDeleteAtom");
	pDeleteAtom = (void *)GetProcAddress(library, "DeleteAtom");
	pGlobalFindAtomA = (void *)GetProcAddress(library, "GlobalFindAtomA");
	pFindAtomA = (void *)GetProcAddress(library, "FindAtomA");
	pGlobalFindAtomW = (void *)GetProcAddress(library, "GlobalFindAtomW");
	pFindAtomW = (void *)GetProcAddress(library, "FindAtomW");
	pGlobalGetAtomNameA = (void *)GetProcAddress(library, "GlobalGetAtomNameA");
	pGetAtomNameA = (void *)GetProcAddress(library, "GetAtomNameA");
	pGlobalGetAtomNameW = (void *)GetProcAddress(library, "GlobalGetAtomNameW");
	pGetAtomNameW = (void *)GetProcAddress(library, "GetAtomNameW");
	pFindFirstChangeNotificationA = (void *)GetProcAddress(library, "FindFirstChangeNotificationA");
	pFindFirstChangeNotificationW = (void *)GetProcAddress(library, "FindFirstChangeNotificationW");
	pFindNextChangeNotification = (void *)GetProcAddress(library, "FindNextChangeNotification");
	pFindCloseChangeNotification = (void *)GetProcAddress(library, "FindCloseChangeNotification");
	pReadDirectoryChangesW = (void *)GetProcAddress(library, "ReadDirectoryChangesW");
	pBuildCommDCBA = (void *)GetProcAddress(library, "BuildCommDCBA");
	pBuildCommDCBAndTimeoutsA = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsA");
	pBuildCommDCBAndTimeoutsW = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsW");
	pBuildCommDCBW = (void *)GetProcAddress(library, "BuildCommDCBW");
	pSetCommBreak = (void *)GetProcAddress(library, "SetCommBreak");
	pClearCommBreak = (void *)GetProcAddress(library, "ClearCommBreak");
	pEscapeCommFunction = (void *)GetProcAddress(library, "EscapeCommFunction");
	pPurgeComm = (void *)GetProcAddress(library, "PurgeComm");
	pClearCommError = (void *)GetProcAddress(library, "ClearCommError");
	pSetupComm = (void *)GetProcAddress(library, "SetupComm");
	pGetCommMask = (void *)GetProcAddress(library, "GetCommMask");
	pSetCommMask = (void *)GetProcAddress(library, "SetCommMask");
	pSetCommState = (void *)GetProcAddress(library, "SetCommState");
	pGetCommState = (void *)GetProcAddress(library, "GetCommState");
	pTransmitCommChar = (void *)GetProcAddress(library, "TransmitCommChar");
	pGetCommTimeouts = (void *)GetProcAddress(library, "GetCommTimeouts");
	pSetCommTimeouts = (void *)GetProcAddress(library, "SetCommTimeouts");
	pGetCommModemStatus = (void *)GetProcAddress(library, "GetCommModemStatus");
	pWaitCommEvent = (void *)GetProcAddress(library, "WaitCommEvent");
	pGetCommProperties = (void *)GetProcAddress(library, "GetCommProperties");
	pCommConfigDialogA = (void *)GetProcAddress(library, "CommConfigDialogA");
	pCommConfigDialogW = (void *)GetProcAddress(library, "CommConfigDialogW");
	pGetCommConfig = (void *)GetProcAddress(library, "GetCommConfig");
	pSetCommConfig = (void *)GetProcAddress(library, "SetCommConfig");
	pSetDefaultCommConfigW = (void *)GetProcAddress(library, "SetDefaultCommConfigW");
	pSetDefaultCommConfigA = (void *)GetProcAddress(library, "SetDefaultCommConfigA");
	pGetDefaultCommConfigW = (void *)GetProcAddress(library, "GetDefaultCommConfigW");
	pGetDefaultCommConfigA = (void *)GetProcAddress(library, "GetDefaultCommConfigA");
	pGetComputerNameW = (void *)GetProcAddress(library, "GetComputerNameW");
	pGetComputerNameA = (void *)GetProcAddress(library, "GetComputerNameA");
	pGetComputerNameExA = (void *)GetProcAddress(library, "GetComputerNameExA");
	pGetComputerNameExW = (void *)GetProcAddress(library, "GetComputerNameExW");
	pSetComputerNameW = (void *)GetProcAddress(library, "SetComputerNameW");
	pSetComputerNameA = (void *)GetProcAddress(library, "SetComputerNameA");
	pSetComputerNameExW = (void *)GetProcAddress(library, "SetComputerNameExW");
	pSetComputerNameExA = (void *)GetProcAddress(library, "SetComputerNameExA");
	pDnsHostnameToComputerNameA = (void *)GetProcAddress(library, "DnsHostnameToComputerNameA");
	pDnsHostnameToComputerNameW = (void *)GetProcAddress(library, "DnsHostnameToComputerNameW");
	pGetConsoleWindow = (void *)GetProcAddress(library, "GetConsoleWindow");
	pGetConsoleCP = (void *)GetProcAddress(library, "GetConsoleCP");
	pSetConsoleCP = (void *)GetProcAddress(library, "SetConsoleCP");
	pGetConsoleOutputCP = (void *)GetProcAddress(library, "GetConsoleOutputCP");
	pSetConsoleOutputCP = (void *)GetProcAddress(library, "SetConsoleOutputCP");
	pBeep = (void *)GetProcAddress(library, "Beep");
	pOpenConsoleW = (void *)GetProcAddress(library, "OpenConsoleW");
	pVerifyConsoleIoHandle = (void *)GetProcAddress(library, "VerifyConsoleIoHandle");
	pDuplicateConsoleHandle = (void *)GetProcAddress(library, "DuplicateConsoleHandle");
	pCloseConsoleHandle = (void *)GetProcAddress(library, "CloseConsoleHandle");
	pGetConsoleInputWaitHandle = (void *)GetProcAddress(library, "GetConsoleInputWaitHandle");
	pWriteConsoleInputA = (void *)GetProcAddress(library, "WriteConsoleInputA");
	pWriteConsoleInputW = (void *)GetProcAddress(library, "WriteConsoleInputW");
	pWriteConsoleOutputA = (void *)GetProcAddress(library, "WriteConsoleOutputA");
	pWriteConsoleOutputW = (void *)GetProcAddress(library, "WriteConsoleOutputW");
	pWriteConsoleOutputCharacterA = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterA");
	pWriteConsoleOutputAttribute = (void *)GetProcAddress(library, "WriteConsoleOutputAttribute");
	pFillConsoleOutputCharacterA = (void *)GetProcAddress(library, "FillConsoleOutputCharacterA");
	pFillConsoleOutputCharacterW = (void *)GetProcAddress(library, "FillConsoleOutputCharacterW");
	pFillConsoleOutputAttribute = (void *)GetProcAddress(library, "FillConsoleOutputAttribute");
	pReadConsoleOutputCharacterA = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterA");
	pReadConsoleOutputCharacterW = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterW");
	pReadConsoleOutputAttribute = (void *)GetProcAddress(library, "ReadConsoleOutputAttribute");
	pReadConsoleOutputA = (void *)GetProcAddress(library, "ReadConsoleOutputA");
	pReadConsoleOutputW = (void *)GetProcAddress(library, "ReadConsoleOutputW");
	pReadConsoleInputA = (void *)GetProcAddress(library, "ReadConsoleInputA");
	pPeekConsoleInputA = (void *)GetProcAddress(library, "PeekConsoleInputA");
	pPeekConsoleInputW = (void *)GetProcAddress(library, "PeekConsoleInputW");
	pGetNumberOfConsoleInputEvents = (void *)GetProcAddress(library, "GetNumberOfConsoleInputEvents");
	pFlushConsoleInputBuffer = (void *)GetProcAddress(library, "FlushConsoleInputBuffer");
	pSetConsoleTitleA = (void *)GetProcAddress(library, "SetConsoleTitleA");
	pGetConsoleKeyboardLayoutNameA = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameA");
	pGetConsoleKeyboardLayoutNameW = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameW");
	pGetConsoleInputExeNameW = (void *)GetProcAddress(library, "GetConsoleInputExeNameW");
	pGetConsoleInputExeNameA = (void *)GetProcAddress(library, "GetConsoleInputExeNameA");
	pGetConsoleTitleA = (void *)GetProcAddress(library, "GetConsoleTitleA");
	pGetConsoleTitleW = (void *)GetProcAddress(library, "GetConsoleTitleW");
	pGetLargestConsoleWindowSize = (void *)GetProcAddress(library, "GetLargestConsoleWindowSize");
	pFreeConsole = (void *)GetProcAddress(library, "FreeConsole");
	pAllocConsole = (void *)GetProcAddress(library, "AllocConsole");
	pReadConsoleA = (void *)GetProcAddress(library, "ReadConsoleA");
	pReadConsoleW = (void *)GetProcAddress(library, "ReadConsoleW");
	pReadConsoleInputW = (void *)GetProcAddress(library, "ReadConsoleInputW");
	pWriteConsoleOutputCharacterW = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterW");
	pSetConsoleTitleW = (void *)GetProcAddress(library, "SetConsoleTitleW");
	pGetNumberOfConsoleMouseButtons = (void *)GetProcAddress(library, "GetNumberOfConsoleMouseButtons");
	pSetConsoleInputExeNameW = (void *)GetProcAddress(library, "SetConsoleInputExeNameW");
	pSetConsoleInputExeNameA = (void *)GetProcAddress(library, "SetConsoleInputExeNameA");
	pSetConsoleCtrlHandler = (void *)GetProcAddress(library, "SetConsoleCtrlHandler");
	pGenerateConsoleCtrlEvent = (void *)GetProcAddress(library, "GenerateConsoleCtrlEvent");
	pCreateConsoleScreenBuffer = (void *)GetProcAddress(library, "CreateConsoleScreenBuffer");
	pGetConsoleScreenBufferInfo = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfo");
	pSetConsoleActiveScreenBuffer = (void *)GetProcAddress(library, "SetConsoleActiveScreenBuffer");
	pGetConsoleMode = (void *)GetProcAddress(library, "GetConsoleMode");
	pSetConsoleMode = (void *)GetProcAddress(library, "SetConsoleMode");
	pWriteConsoleW = (void *)GetProcAddress(library, "WriteConsoleW");
	pWriteConsoleA = (void *)GetProcAddress(library, "WriteConsoleA");
	pSetConsoleCursorPosition = (void *)GetProcAddress(library, "SetConsoleCursorPosition");
	pGetConsoleCursorInfo = (void *)GetProcAddress(library, "GetConsoleCursorInfo");
	pSetConsoleCursorInfo = (void *)GetProcAddress(library, "SetConsoleCursorInfo");
	pSetConsoleWindowInfo = (void *)GetProcAddress(library, "SetConsoleWindowInfo");
	pSetConsoleTextAttribute = (void *)GetProcAddress(library, "SetConsoleTextAttribute");
	pSetConsoleScreenBufferSize = (void *)GetProcAddress(library, "SetConsoleScreenBufferSize");
	pScrollConsoleScreenBufferA = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferA");
	pScrollConsoleScreenBufferW = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferW");
	pAttachConsole = (void *)GetProcAddress(library, "AttachConsole");
	pGetConsoleDisplayMode = (void *)GetProcAddress(library, "GetConsoleDisplayMode");
	pSetConsoleDisplayMode = (void *)GetProcAddress(library, "SetConsoleDisplayMode");
	pGetConsoleAliasW = (void *)GetProcAddress(library, "GetConsoleAliasW");
	pGetConsoleProcessList = (void *)GetProcAddress(library, "GetConsoleProcessList");
	pGetConsoleCommandHistoryA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryA");
	pGetConsoleCommandHistoryW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryW");
	pGetConsoleCommandHistoryLengthA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthA");
	pGetConsoleCommandHistoryLengthW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthW");
	pGetConsoleAliasesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasesLengthA");
	pGetConsoleAliasesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasesLengthW");
	pGetConsoleAliasExesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthA");
	pGetConsoleAliasExesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthW");
	pExpungeConsoleCommandHistoryA = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryA");
	pExpungeConsoleCommandHistoryW = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryW");
	pAddConsoleAliasA = (void *)GetProcAddress(library, "AddConsoleAliasA");
	pAddConsoleAliasW = (void *)GetProcAddress(library, "AddConsoleAliasW");
	pSetConsoleIcon = (void *)GetProcAddress(library, "SetConsoleIcon");
	pGetNumberOfConsoleFonts = (void *)GetProcAddress(library, "GetNumberOfConsoleFonts");
	pSetConsoleFont = (void *)GetProcAddress(library, "SetConsoleFont");
	pSetConsoleKeyShortcuts = (void *)GetProcAddress(library, "SetConsoleKeyShortcuts");
	pGetCurrentConsoleFont = (void *)GetProcAddress(library, "GetCurrentConsoleFont");
	pGetConsoleFontSize = (void *)GetProcAddress(library, "GetConsoleFontSize");
	pGetConsoleFontInfo = (void *)GetProcAddress(library, "GetConsoleFontInfo");
	pGetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfoEx");
	pSetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "SetConsoleScreenBufferInfoEx");
	pSetCurrentConsoleFontEx = (void *)GetProcAddress(library, "SetCurrentConsoleFontEx");
	pQueryPerformanceCounter = (void *)GetProcAddress(library, "QueryPerformanceCounter");
	pQueryPerformanceFrequency = (void *)GetProcAddress(library, "QueryPerformanceFrequency");
	pGetSystemInfo = (void *)GetProcAddress(library, "GetSystemInfo");
	pGetNativeSystemInfo = (void *)GetProcAddress(library, "GetNativeSystemInfo");
	pIsProcessorFeaturePresent = (void *)GetProcAddress(library, "IsProcessorFeaturePresent");
	pK32GetPerformanceInfo = (void *)GetProcAddress(library, "K32GetPerformanceInfo");
	pGetLargePageMinimum = (void *)GetProcAddress(library, "GetLargePageMinimum");
	pGetActiveProcessorGroupCount = (void *)GetProcAddress(library, "GetActiveProcessorGroupCount");
	pGetActiveProcessorCount = (void *)GetProcAddress(library, "GetActiveProcessorCount");
	pGetMaximumProcessorCount = (void *)GetProcAddress(library, "GetMaximumProcessorCount");
	pGetSystemFirmwareTable = (void *)GetProcAddress(library, "GetSystemFirmwareTable");
	pEnumSystemFirmwareTables = (void *)GetProcAddress(library, "EnumSystemFirmwareTables");
	pWaitForDebugEvent = (void *)GetProcAddress(library, "WaitForDebugEvent");
	pContinueDebugEvent = (void *)GetProcAddress(library, "ContinueDebugEvent");
	pDebugActiveProcess = (void *)GetProcAddress(library, "DebugActiveProcess");
	pDebugActiveProcessStop = (void *)GetProcAddress(library, "DebugActiveProcessStop");
	pOutputDebugStringA = (void *)GetProcAddress(library, "OutputDebugStringA");
	pOutputDebugStringW = (void *)GetProcAddress(library, "OutputDebugStringW");
	pDebugBreakProcess = (void *)GetProcAddress(library, "DebugBreakProcess");
	pIsDebuggerPresent = (void *)GetProcAddress(library, "IsDebuggerPresent");
	pCheckRemoteDebuggerPresent = (void *)GetProcAddress(library, "CheckRemoteDebuggerPresent");
	pDebugSetProcessKillOnExit = (void *)GetProcAddress(library, "DebugSetProcessKillOnExit");
	pGetCommandLineA = (void *)GetProcAddress(library, "GetCommandLineA");
	pGetCommandLineW = (void *)GetProcAddress(library, "GetCommandLineW");
	pGetEnvironmentStringsA = (void *)GetProcAddress(library, "GetEnvironmentStringsA");
	pGetEnvironmentStringsW = (void *)GetProcAddress(library, "GetEnvironmentStringsW");
	pFreeEnvironmentStringsA = (void *)GetProcAddress(library, "FreeEnvironmentStringsA");
	pFreeEnvironmentStringsW = (void *)GetProcAddress(library, "FreeEnvironmentStringsW");
	pGetEnvironmentVariableA = (void *)GetProcAddress(library, "GetEnvironmentVariableA");
	pGetEnvironmentVariableW = (void *)GetProcAddress(library, "GetEnvironmentVariableW");
	pSetEnvironmentVariableA = (void *)GetProcAddress(library, "SetEnvironmentVariableA");
	pSetEnvironmentVariableW = (void *)GetProcAddress(library, "SetEnvironmentVariableW");
	pExpandEnvironmentStringsA = (void *)GetProcAddress(library, "ExpandEnvironmentStringsA");
	pExpandEnvironmentStringsW = (void *)GetProcAddress(library, "ExpandEnvironmentStringsW");
	pGetStdHandle = (void *)GetProcAddress(library, "GetStdHandle");
	pSetStdHandle = (void *)GetProcAddress(library, "SetStdHandle");
	pGetStartupInfoA = (void *)GetProcAddress(library, "GetStartupInfoA");
	pGetStartupInfoW = (void *)GetProcAddress(library, "GetStartupInfoW");
	pGetFirmwareEnvironmentVariableA = (void *)GetProcAddress(library, "GetFirmwareEnvironmentVariableA");
	pGetFirmwareEnvironmentVariableW = (void *)GetProcAddress(library, "GetFirmwareEnvironmentVariableW");
	pRaiseException = (void *)GetProcAddress(library, "RaiseException");
	pUnhandledExceptionFilter = (void *)GetProcAddress(library, "UnhandledExceptionFilter");
	pSetUnhandledExceptionFilter = (void *)GetProcAddress(library, "SetUnhandledExceptionFilter");
	pFatalAppExitA = (void *)GetProcAddress(library, "FatalAppExitA");
	pFatalAppExitW = (void *)GetProcAddress(library, "FatalAppExitW");
	pFatalExit = (void *)GetProcAddress(library, "FatalExit");
	p_hread = (void *)GetProcAddress(library, "_hread");
	p_hwrite = (void *)GetProcAddress(library, "_hwrite");
	p_lclose = (void *)GetProcAddress(library, "_lclose");
	p_lcreat = (void *)GetProcAddress(library, "_lcreat");
	p_lopen = (void *)GetProcAddress(library, "_lopen");
	p_lread = (void *)GetProcAddress(library, "_lread");
	p_llseek = (void *)GetProcAddress(library, "_llseek");
	p_lwrite = (void *)GetProcAddress(library, "_lwrite");
	pSetFileCompletionNotificationModes = (void *)GetProcAddress(library, "SetFileCompletionNotificationModes");
	pSetHandleCount = (void *)GetProcAddress(library, "SetHandleCount");
	pReplaceFileW = (void *)GetProcAddress(library, "ReplaceFileW");
	pReplaceFileA = (void *)GetProcAddress(library, "ReplaceFileA");
	pFindFirstFileExW = (void *)GetProcAddress(library, "FindFirstFileExW");
	pFindNextFileW = (void *)GetProcAddress(library, "FindNextFileW");
	pFindClose = (void *)GetProcAddress(library, "FindClose");
	pFindFirstFileA = (void *)GetProcAddress(library, "FindFirstFileA");
	pFindFirstFileExA = (void *)GetProcAddress(library, "FindFirstFileExA");
	pFindFirstFileW = (void *)GetProcAddress(library, "FindFirstFileW");
	pFindNextFileA = (void *)GetProcAddress(library, "FindNextFileA");
	pFindFirstStreamW = (void *)GetProcAddress(library, "FindFirstStreamW");
	pFindNextStreamW = (void *)GetProcAddress(library, "FindNextStreamW");
	pOpenVxDHandle = (void *)GetProcAddress(library, "OpenVxDHandle");
	pDeviceIoControl = (void *)GetProcAddress(library, "DeviceIoControl");
	pOpenFile = (void *)GetProcAddress(library, "OpenFile");
	pK32EnumDeviceDrivers = (void *)GetProcAddress(library, "K32EnumDeviceDrivers");
	pK32GetDeviceDriverBaseNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameA");
	pK32GetDeviceDriverBaseNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameW");
	pK32GetDeviceDriverFileNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameA");
	pK32GetDeviceDriverFileNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameW");
	pGetFinalPathNameByHandleW = (void *)GetProcAddress(library, "GetFinalPathNameByHandleW");
	pGetFinalPathNameByHandleA = (void *)GetProcAddress(library, "GetFinalPathNameByHandleA");
	pFormatMessageA = (void *)GetProcAddress(library, "FormatMessageA");
	pFormatMessageW = (void *)GetProcAddress(library, "FormatMessageW");
	pHeapCreate = (void *)GetProcAddress(library, "HeapCreate");
	pHeapDestroy = (void *)GetProcAddress(library, "HeapDestroy");
	pHeapCompact = (void *)GetProcAddress(library, "HeapCompact");
	pHeapValidate = (void *)GetProcAddress(library, "HeapValidate");
	pHeapWalk = (void *)GetProcAddress(library, "HeapWalk");
	pHeapLock = (void *)GetProcAddress(library, "HeapLock");
	pHeapUnlock = (void *)GetProcAddress(library, "HeapUnlock");
	pHeapAlloc = (void *)GetProcAddress(library, "HeapAlloc");
	pHeapFree = (void *)GetProcAddress(library, "HeapFree");
	pHeapReAlloc = (void *)GetProcAddress(library, "HeapReAlloc");
	pHeapSize = (void *)GetProcAddress(library, "HeapSize");
	pHeapQueryInformation = (void *)GetProcAddress(library, "HeapQueryInformation");
	pHeapSetInformation = (void *)GetProcAddress(library, "HeapSetInformation");
	pGlobalAlloc = (void *)GetProcAddress(library, "GlobalAlloc");
	pGlobalLock = (void *)GetProcAddress(library, "GlobalLock");
	pGlobalUnlock = (void *)GetProcAddress(library, "GlobalUnlock");
	pGlobalHandle = (void *)GetProcAddress(library, "GlobalHandle");
	pGlobalReAlloc = (void *)GetProcAddress(library, "GlobalReAlloc");
	pGlobalFree = (void *)GetProcAddress(library, "GlobalFree");
	pGlobalSize = (void *)GetProcAddress(library, "GlobalSize");
	pGlobalWire = (void *)GetProcAddress(library, "GlobalWire");
	pGlobalUnWire = (void *)GetProcAddress(library, "GlobalUnWire");
	pGlobalFix = (void *)GetProcAddress(library, "GlobalFix");
	pGlobalUnfix = (void *)GetProcAddress(library, "GlobalUnfix");
	pGlobalFlags = (void *)GetProcAddress(library, "GlobalFlags");
	pGlobalCompact = (void *)GetProcAddress(library, "GlobalCompact");
	pLocalAlloc = (void *)GetProcAddress(library, "LocalAlloc");
	pLocalCompact = (void *)GetProcAddress(library, "LocalCompact");
	pLocalFlags = (void *)GetProcAddress(library, "LocalFlags");
	pLocalFree = (void *)GetProcAddress(library, "LocalFree");
	pLocalHandle = (void *)GetProcAddress(library, "LocalHandle");
	pLocalLock = (void *)GetProcAddress(library, "LocalLock");
	pLocalReAlloc = (void *)GetProcAddress(library, "LocalReAlloc");
	pLocalShrink = (void *)GetProcAddress(library, "LocalShrink");
	pLocalSize = (void *)GetProcAddress(library, "LocalSize");
	pLocalUnlock = (void *)GetProcAddress(library, "LocalUnlock");
	pGlobalMemoryStatusEx = (void *)GetProcAddress(library, "GlobalMemoryStatusEx");
	pGlobalMemoryStatus = (void *)GetProcAddress(library, "GlobalMemoryStatus");
	pGetPhysicallyInstalledSystemMemory = (void *)GetProcAddress(library, "GetPhysicallyInstalledSystemMemory");
	pGetSystemFileCacheSize = (void *)GetProcAddress(library, "GetSystemFileCacheSize");
	pSetSystemFileCacheSize = (void *)GetProcAddress(library, "SetSystemFileCacheSize");
	pAllocateUserPhysicalPages = (void *)GetProcAddress(library, "AllocateUserPhysicalPages");
	pFreeUserPhysicalPages = (void *)GetProcAddress(library, "FreeUserPhysicalPages");
	pMapUserPhysicalPages = (void *)GetProcAddress(library, "MapUserPhysicalPages");
	pMulDiv = (void *)GetProcAddress(library, "MulDiv");
	pGetSystemRegistryQuota = (void *)GetProcAddress(library, "GetSystemRegistryQuota");
	pGetDateFormatA = (void *)GetProcAddress(library, "GetDateFormatA");
	pGetDateFormatEx = (void *)GetProcAddress(library, "GetDateFormatEx");
	pGetDateFormatW = (void *)GetProcAddress(library, "GetDateFormatW");
	pGetTimeFormatA = (void *)GetProcAddress(library, "GetTimeFormatA");
	pGetTimeFormatEx = (void *)GetProcAddress(library, "GetTimeFormatEx");
	pGetTimeFormatW = (void *)GetProcAddress(library, "GetTimeFormatW");
	pGetNumberFormatA = (void *)GetProcAddress(library, "GetNumberFormatA");
	pGetNumberFormatW = (void *)GetProcAddress(library, "GetNumberFormatW");
	pGetNumberFormatEx = (void *)GetProcAddress(library, "GetNumberFormatEx");
	pGetCurrencyFormatA = (void *)GetProcAddress(library, "GetCurrencyFormatA");
	pGetCurrencyFormatW = (void *)GetProcAddress(library, "GetCurrencyFormatW");
	pGetCurrencyFormatEx = (void *)GetProcAddress(library, "GetCurrencyFormatEx");
	pEnumDateFormatsExA = (void *)GetProcAddress(library, "EnumDateFormatsExA");
	pEnumDateFormatsExW = (void *)GetProcAddress(library, "EnumDateFormatsExW");
	pEnumDateFormatsA = (void *)GetProcAddress(library, "EnumDateFormatsA");
	pEnumDateFormatsW = (void *)GetProcAddress(library, "EnumDateFormatsW");
	pEnumDateFormatsExEx = (void *)GetProcAddress(library, "EnumDateFormatsExEx");
	pEnumTimeFormatsA = (void *)GetProcAddress(library, "EnumTimeFormatsA");
	pEnumTimeFormatsW = (void *)GetProcAddress(library, "EnumTimeFormatsW");
	pEnumTimeFormatsEx = (void *)GetProcAddress(library, "EnumTimeFormatsEx");
	pEnumCalendarInfoA = (void *)GetProcAddress(library, "EnumCalendarInfoA");
	pEnumCalendarInfoW = (void *)GetProcAddress(library, "EnumCalendarInfoW");
	pEnumCalendarInfoExA = (void *)GetProcAddress(library, "EnumCalendarInfoExA");
	pEnumCalendarInfoExW = (void *)GetProcAddress(library, "EnumCalendarInfoExW");
	pEnumCalendarInfoExEx = (void *)GetProcAddress(library, "EnumCalendarInfoExEx");
	pGetUserDefaultLangID = (void *)GetProcAddress(library, "GetUserDefaultLangID");
	pGetSystemDefaultLangID = (void *)GetProcAddress(library, "GetSystemDefaultLangID");
	pGetUserDefaultLCID = (void *)GetProcAddress(library, "GetUserDefaultLCID");
	pGetSystemDefaultLCID = (void *)GetProcAddress(library, "GetSystemDefaultLCID");
	pGetSystemDefaultLocaleName = (void *)GetProcAddress(library, "GetSystemDefaultLocaleName");
	pGetProcessPreferredUILanguages = (void *)GetProcAddress(library, "GetProcessPreferredUILanguages");
	pGetSystemPreferredUILanguages = (void *)GetProcAddress(library, "GetSystemPreferredUILanguages");
	pSetProcessPreferredUILanguages = (void *)GetProcAddress(library, "SetProcessPreferredUILanguages");
	pSetThreadPreferredUILanguages = (void *)GetProcAddress(library, "SetThreadPreferredUILanguages");
	pGetThreadPreferredUILanguages = (void *)GetProcAddress(library, "GetThreadPreferredUILanguages");
	pGetUserPreferredUILanguages = (void *)GetProcAddress(library, "GetUserPreferredUILanguages");
	pGetUserDefaultUILanguage = (void *)GetProcAddress(library, "GetUserDefaultUILanguage");
	pGetSystemDefaultUILanguage = (void *)GetProcAddress(library, "GetSystemDefaultUILanguage");
	pLocaleNameToLCID = (void *)GetProcAddress(library, "LocaleNameToLCID");
	pLCIDToLocaleName = (void *)GetProcAddress(library, "LCIDToLocaleName");
	pGetLocaleInfoA = (void *)GetProcAddress(library, "GetLocaleInfoA");
	pGetLocaleInfoW = (void *)GetProcAddress(library, "GetLocaleInfoW");
	pGetLocaleInfoEx = (void *)GetProcAddress(library, "GetLocaleInfoEx");
	pSetLocaleInfoA = (void *)GetProcAddress(library, "SetLocaleInfoA");
	pSetLocaleInfoW = (void *)GetProcAddress(library, "SetLocaleInfoW");
	pGetACP = (void *)GetProcAddress(library, "GetACP");
	pSetCPGlobal = (void *)GetProcAddress(library, "SetCPGlobal");
	pGetOEMCP = (void *)GetProcAddress(library, "GetOEMCP");
	pIsValidCodePage = (void *)GetProcAddress(library, "IsValidCodePage");
	pIsDBCSLeadByteEx = (void *)GetProcAddress(library, "IsDBCSLeadByteEx");
	pIsDBCSLeadByte = (void *)GetProcAddress(library, "IsDBCSLeadByte");
	pGetCPInfo = (void *)GetProcAddress(library, "GetCPInfo");
	pGetCPInfoExA = (void *)GetProcAddress(library, "GetCPInfoExA");
	pGetCPInfoExW = (void *)GetProcAddress(library, "GetCPInfoExW");
	pEnumSystemCodePagesA = (void *)GetProcAddress(library, "EnumSystemCodePagesA");
	pEnumSystemCodePagesW = (void *)GetProcAddress(library, "EnumSystemCodePagesW");
	pMultiByteToWideChar = (void *)GetProcAddress(library, "MultiByteToWideChar");
	pWideCharToMultiByte = (void *)GetProcAddress(library, "WideCharToMultiByte");
	pGetThreadLocale = (void *)GetProcAddress(library, "GetThreadLocale");
	pSetThreadLocale = (void *)GetProcAddress(library, "SetThreadLocale");
	pSetThreadUILanguage = (void *)GetProcAddress(library, "SetThreadUILanguage");
	pConvertDefaultLocale = (void *)GetProcAddress(library, "ConvertDefaultLocale");
	pIsValidLocale = (void *)GetProcAddress(library, "IsValidLocale");
	pIsValidLocaleName = (void *)GetProcAddress(library, "IsValidLocaleName");
	pEnumSystemLocalesA = (void *)GetProcAddress(library, "EnumSystemLocalesA");
	pEnumSystemLocalesW = (void *)GetProcAddress(library, "EnumSystemLocalesW");
	pEnumSystemLocalesEx = (void *)GetProcAddress(library, "EnumSystemLocalesEx");
	pVerLanguageNameA = (void *)GetProcAddress(library, "VerLanguageNameA");
	pVerLanguageNameW = (void *)GetProcAddress(library, "VerLanguageNameW");
	pGetStringTypeW = (void *)GetProcAddress(library, "GetStringTypeW");
	pGetStringTypeExW = (void *)GetProcAddress(library, "GetStringTypeExW");
	pGetStringTypeA = (void *)GetProcAddress(library, "GetStringTypeA");
	pGetStringTypeExA = (void *)GetProcAddress(library, "GetStringTypeExA");
	pLCMapStringEx = (void *)GetProcAddress(library, "LCMapStringEx");
	pLCMapStringW = (void *)GetProcAddress(library, "LCMapStringW");
	pLCMapStringA = (void *)GetProcAddress(library, "LCMapStringA");
	pFoldStringA = (void *)GetProcAddress(library, "FoldStringA");
	pFoldStringW = (void *)GetProcAddress(library, "FoldStringW");
	pCompareStringW = (void *)GetProcAddress(library, "CompareStringW");
	pCompareStringEx = (void *)GetProcAddress(library, "CompareStringEx");
	pCompareStringA = (void *)GetProcAddress(library, "CompareStringA");
	pCompareStringOrdinal = (void *)GetProcAddress(library, "CompareStringOrdinal");
	pEnumSystemLanguageGroupsA = (void *)GetProcAddress(library, "EnumSystemLanguageGroupsA");
	pEnumSystemLanguageGroupsW = (void *)GetProcAddress(library, "EnumSystemLanguageGroupsW");
	pIsValidLanguageGroup = (void *)GetProcAddress(library, "IsValidLanguageGroup");
	pEnumLanguageGroupLocalesA = (void *)GetProcAddress(library, "EnumLanguageGroupLocalesA");
	pEnumLanguageGroupLocalesW = (void *)GetProcAddress(library, "EnumLanguageGroupLocalesW");
	pInvalidateNLSCache = (void *)GetProcAddress(library, "InvalidateNLSCache");
	pGetUserGeoID = (void *)GetProcAddress(library, "GetUserGeoID");
	pSetUserGeoID = (void *)GetProcAddress(library, "SetUserGeoID");
	pEnumUILanguagesA = (void *)GetProcAddress(library, "EnumUILanguagesA");
	pEnumUILanguagesW = (void *)GetProcAddress(library, "EnumUILanguagesW");
	pGetGeoInfoW = (void *)GetProcAddress(library, "GetGeoInfoW");
	pGetGeoInfoA = (void *)GetProcAddress(library, "GetGeoInfoA");
	pEnumSystemGeoID = (void *)GetProcAddress(library, "EnumSystemGeoID");
	pGetUserDefaultLocaleName = (void *)GetProcAddress(library, "GetUserDefaultLocaleName");
	pNormalizeString = (void *)GetProcAddress(library, "NormalizeString");
	pIsNormalizedString = (void *)GetProcAddress(library, "IsNormalizedString");
	pIdnToAscii = (void *)GetProcAddress(library, "IdnToAscii");
	pIdnToNameprepUnicode = (void *)GetProcAddress(library, "IdnToNameprepUnicode");
	pIdnToUnicode = (void *)GetProcAddress(library, "IdnToUnicode");
	pGetFileMUIPath = (void *)GetProcAddress(library, "GetFileMUIPath");
	pGetFileMUIInfo = (void *)GetProcAddress(library, "GetFileMUIInfo");
	pResolveLocaleName = (void *)GetProcAddress(library, "ResolveLocaleName");
	pFindNLSStringEx = (void *)GetProcAddress(library, "FindNLSStringEx");
	pFindStringOrdinal = (void *)GetProcAddress(library, "FindStringOrdinal");
	pLZStart = (void *)GetProcAddress(library, "LZStart");
	pLZInit = (void *)GetProcAddress(library, "LZInit");
	pLZDone = (void *)GetProcAddress(library, "LZDone");
	pGetExpandedNameA = (void *)GetProcAddress(library, "GetExpandedNameA");
	pGetExpandedNameW = (void *)GetProcAddress(library, "GetExpandedNameW");
	pLZRead = (void *)GetProcAddress(library, "LZRead");
	pLZSeek = (void *)GetProcAddress(library, "LZSeek");
	pLZCopy = (void *)GetProcAddress(library, "LZCopy");
	pLZOpenFileA = (void *)GetProcAddress(library, "LZOpenFileA");
	pLZOpenFileW = (void *)GetProcAddress(library, "LZOpenFileW");
	pLZClose = (void *)GetProcAddress(library, "LZClose");
	pGetDllDirectoryA = (void *)GetProcAddress(library, "GetDllDirectoryA");
	pGetDllDirectoryW = (void *)GetProcAddress(library, "GetDllDirectoryW");
	pSetDllDirectoryA = (void *)GetProcAddress(library, "SetDllDirectoryA");
	pSetDllDirectoryW = (void *)GetProcAddress(library, "SetDllDirectoryW");
	pAddDllDirectory = (void *)GetProcAddress(library, "AddDllDirectory");
	pRemoveDllDirectory = (void *)GetProcAddress(library, "RemoveDllDirectory");
	pSetDefaultDllDirectories = (void *)GetProcAddress(library, "SetDefaultDllDirectories");
	pGetBinaryTypeW = (void *)GetProcAddress(library, "GetBinaryTypeW");
	pGetBinaryTypeA = (void *)GetProcAddress(library, "GetBinaryTypeA");
	pLoadLibraryExA = (void *)GetProcAddress(library, "LoadLibraryExA");
	pLoadLibraryExW = (void *)GetProcAddress(library, "LoadLibraryExW");
	pLoadLibraryA = (void *)GetProcAddress(library, "LoadLibraryA");
	pLoadLibraryW = (void *)GetProcAddress(library, "LoadLibraryW");
	pFreeLibrary = (void *)GetProcAddress(library, "FreeLibrary");
	pGetProcAddress = (void *)GetProcAddress(library, "GetProcAddress");
	pDelayLoadFailureHook = (void *)GetProcAddress(library, "DelayLoadFailureHook");
	pK32EnumProcessModules = (void *)GetProcAddress(library, "K32EnumProcessModules");
	pK32EnumProcessModulesEx = (void *)GetProcAddress(library, "K32EnumProcessModulesEx");
	pK32GetModuleBaseNameW = (void *)GetProcAddress(library, "K32GetModuleBaseNameW");
	pK32GetModuleBaseNameA = (void *)GetProcAddress(library, "K32GetModuleBaseNameA");
	pK32GetModuleFileNameExW = (void *)GetProcAddress(library, "K32GetModuleFileNameExW");
	pK32GetModuleFileNameExA = (void *)GetProcAddress(library, "K32GetModuleFileNameExA");
	pK32GetModuleInformation = (void *)GetProcAddress(library, "K32GetModuleInformation");
	pGetFullPathNameW = (void *)GetProcAddress(library, "GetFullPathNameW");
	pGetFullPathNameA = (void *)GetProcAddress(library, "GetFullPathNameA");
	pGetLongPathNameW = (void *)GetProcAddress(library, "GetLongPathNameW");
	pGetLongPathNameA = (void *)GetProcAddress(library, "GetLongPathNameA");
	pGetShortPathNameW = (void *)GetProcAddress(library, "GetShortPathNameW");
	pGetShortPathNameA = (void *)GetProcAddress(library, "GetShortPathNameA");
	pGetTempPathA = (void *)GetProcAddress(library, "GetTempPathA");
	pGetTempPathW = (void *)GetProcAddress(library, "GetTempPathW");
	pGetTempFileNameA = (void *)GetProcAddress(library, "GetTempFileNameA");
	pGetTempFileNameW = (void *)GetProcAddress(library, "GetTempFileNameW");
	pSearchPathW = (void *)GetProcAddress(library, "SearchPathW");
	pSearchPathA = (void *)GetProcAddress(library, "SearchPathA");
	pCopyFileW = (void *)GetProcAddress(library, "CopyFileW");
	pCopyFileA = (void *)GetProcAddress(library, "CopyFileA");
	pCopyFileExW = (void *)GetProcAddress(library, "CopyFileExW");
	pCopyFileExA = (void *)GetProcAddress(library, "CopyFileExA");
	pMoveFileTransactedA = (void *)GetProcAddress(library, "MoveFileTransactedA");
	pMoveFileTransactedW = (void *)GetProcAddress(library, "MoveFileTransactedW");
	pMoveFileWithProgressW = (void *)GetProcAddress(library, "MoveFileWithProgressW");
	pMoveFileWithProgressA = (void *)GetProcAddress(library, "MoveFileWithProgressA");
	pMoveFileExW = (void *)GetProcAddress(library, "MoveFileExW");
	pMoveFileExA = (void *)GetProcAddress(library, "MoveFileExA");
	pMoveFileW = (void *)GetProcAddress(library, "MoveFileW");
	pMoveFileA = (void *)GetProcAddress(library, "MoveFileA");
	pCreateHardLinkW = (void *)GetProcAddress(library, "CreateHardLinkW");
	pCreateHardLinkA = (void *)GetProcAddress(library, "CreateHardLinkA");
	pCreateDirectoryExA = (void *)GetProcAddress(library, "CreateDirectoryExA");
	pRemoveDirectoryW = (void *)GetProcAddress(library, "RemoveDirectoryW");
	pRemoveDirectoryA = (void *)GetProcAddress(library, "RemoveDirectoryA");
	pGetCurrentDirectoryW = (void *)GetProcAddress(library, "GetCurrentDirectoryW");
	pGetCurrentDirectoryA = (void *)GetProcAddress(library, "GetCurrentDirectoryA");
	pSetCurrentDirectoryW = (void *)GetProcAddress(library, "SetCurrentDirectoryW");
	pSetCurrentDirectoryA = (void *)GetProcAddress(library, "SetCurrentDirectoryA");
	pGetSystemDirectoryW = (void *)GetProcAddress(library, "GetSystemDirectoryW");
	pGetSystemDirectoryA = (void *)GetProcAddress(library, "GetSystemDirectoryA");
	pGetSystemWow64DirectoryW = (void *)GetProcAddress(library, "GetSystemWow64DirectoryW");
	pGetSystemWow64DirectoryA = (void *)GetProcAddress(library, "GetSystemWow64DirectoryA");
	pWow64EnableWow64FsRedirection = (void *)GetProcAddress(library, "Wow64EnableWow64FsRedirection");
	pNeedCurrentDirectoryForExePathW = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathW");
	pNeedCurrentDirectoryForExePathA = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathA");
	pwine_get_unix_file_name = (void *)GetProcAddress(library, "wine_get_unix_file_name");
	pwine_get_dos_file_name = (void *)GetProcAddress(library, "wine_get_dos_file_name");
	pCreateSymbolicLinkW = (void *)GetProcAddress(library, "CreateSymbolicLinkW");
	pCreateSymbolicLinkA = (void *)GetProcAddress(library, "CreateSymbolicLinkA");
	pCreateHardLinkTransactedA = (void *)GetProcAddress(library, "CreateHardLinkTransactedA");
	pCreateHardLinkTransactedW = (void *)GetProcAddress(library, "CreateHardLinkTransactedW");
	pCheckNameLegalDOS8Dot3A = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3A");
	pCheckNameLegalDOS8Dot3W = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3W");
	pSetSearchPathMode = (void *)GetProcAddress(library, "SetSearchPathMode");
	pGetDevicePowerState = (void *)GetProcAddress(library, "GetDevicePowerState");
	pGetSystemPowerStatus = (void *)GetProcAddress(library, "GetSystemPowerStatus");
	pIsSystemResumeAutomatic = (void *)GetProcAddress(library, "IsSystemResumeAutomatic");
	pRequestWakeupLatency = (void *)GetProcAddress(library, "RequestWakeupLatency");
	pRequestDeviceWakeup = (void *)GetProcAddress(library, "RequestDeviceWakeup");
	pSetSystemPowerState = (void *)GetProcAddress(library, "SetSystemPowerState");
	pSetThreadExecutionState = (void *)GetProcAddress(library, "SetThreadExecutionState");
	pPowerCreateRequest = (void *)GetProcAddress(library, "PowerCreateRequest");
	pPowerSetRequest = (void *)GetProcAddress(library, "PowerSetRequest");
	pPowerClearRequest = (void *)GetProcAddress(library, "PowerClearRequest");
	p__wine_kernel_init = (void *)GetProcAddress(library, "__wine_kernel_init");
	pCreateProcessInternalW = (void *)GetProcAddress(library, "CreateProcessInternalW");
	pCreateProcessInternalA = (void *)GetProcAddress(library, "CreateProcessInternalA");
	pCreateProcessA = (void *)GetProcAddress(library, "CreateProcessA");
	pCreateProcessW = (void *)GetProcAddress(library, "CreateProcessW");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pWinExec = (void *)GetProcAddress(library, "WinExec");
	pLoadModule = (void *)GetProcAddress(library, "LoadModule");
	pExitProcess = (void *)GetProcAddress(library, "ExitProcess");
	pGetExitCodeProcess = (void *)GetProcAddress(library, "GetExitCodeProcess");
	pGetProcessFlags = (void *)GetProcAddress(library, "GetProcessFlags");
	pCloseHandle = (void *)GetProcAddress(library, "CloseHandle");
	pGetHandleInformation = (void *)GetProcAddress(library, "GetHandleInformation");
	pSetHandleInformation = (void *)GetProcAddress(library, "SetHandleInformation");
	pDuplicateHandle = (void *)GetProcAddress(library, "DuplicateHandle");
	pConvertToGlobalHandle = (void *)GetProcAddress(library, "ConvertToGlobalHandle");
	pSetHandleContext = (void *)GetProcAddress(library, "SetHandleContext");
	pGetHandleContext = (void *)GetProcAddress(library, "GetHandleContext");
	pCreateSocketHandle = (void *)GetProcAddress(library, "CreateSocketHandle");
	pSetProcessAffinityMask = (void *)GetProcAddress(library, "SetProcessAffinityMask");
	pGetProcessAffinityMask = (void *)GetProcAddress(library, "GetProcessAffinityMask");
	pGetProcessVersion = (void *)GetProcAddress(library, "GetProcessVersion");
	pSetProcessWorkingSetSize = (void *)GetProcAddress(library, "SetProcessWorkingSetSize");
	pK32EmptyWorkingSet = (void *)GetProcAddress(library, "K32EmptyWorkingSet");
	pGetProcessWorkingSetSize = (void *)GetProcAddress(library, "GetProcessWorkingSetSize");
	pReadProcessMemory = (void *)GetProcAddress(library, "ReadProcessMemory");
	pWriteProcessMemory = (void *)GetProcAddress(library, "WriteProcessMemory");
	pGetProcessIoCounters = (void *)GetProcAddress(library, "GetProcessIoCounters");
	pQueryFullProcessImageNameA = (void *)GetProcAddress(library, "QueryFullProcessImageNameA");
	pQueryFullProcessImageNameW = (void *)GetProcAddress(library, "QueryFullProcessImageNameW");
	pK32GetProcessImageFileNameA = (void *)GetProcAddress(library, "K32GetProcessImageFileNameA");
	pK32GetProcessImageFileNameW = (void *)GetProcAddress(library, "K32GetProcessImageFileNameW");
	pK32EnumProcesses = (void *)GetProcAddress(library, "K32EnumProcesses");
	pK32QueryWorkingSet = (void *)GetProcAddress(library, "K32QueryWorkingSet");
	pK32QueryWorkingSetEx = (void *)GetProcAddress(library, "K32QueryWorkingSetEx");
	pK32GetProcessMemoryInfo = (void *)GetProcAddress(library, "K32GetProcessMemoryInfo");
	pProcessIdToSessionId = (void *)GetProcAddress(library, "ProcessIdToSessionId");
	pRegisterServiceProcess = (void *)GetProcAddress(library, "RegisterServiceProcess");
	pGetLogicalProcessorInformation = (void *)GetProcAddress(library, "GetLogicalProcessorInformation");
	pGetLogicalProcessorInformationEx = (void *)GetProcAddress(library, "GetLogicalProcessorInformationEx");
	pCmdBatNotification = (void *)GetProcAddress(library, "CmdBatNotification");
	pRegisterApplicationRestart = (void *)GetProcAddress(library, "RegisterApplicationRestart");
	pWTSGetActiveConsoleSessionId = (void *)GetProcAddress(library, "WTSGetActiveConsoleSessionId");
	pGetSystemDEPPolicy = (void *)GetProcAddress(library, "GetSystemDEPPolicy");
	pSetProcessDEPPolicy = (void *)GetProcAddress(library, "SetProcessDEPPolicy");
	pApplicationRecoveryFinished = (void *)GetProcAddress(library, "ApplicationRecoveryFinished");
	pApplicationRecoveryInProgress = (void *)GetProcAddress(library, "ApplicationRecoveryInProgress");
	pRegisterApplicationRecoveryCallback = (void *)GetProcAddress(library, "RegisterApplicationRecoveryCallback");
	pGetApplicationRestartSettings = (void *)GetProcAddress(library, "GetApplicationRestartSettings");
	pGetNumaHighestNodeNumber = (void *)GetProcAddress(library, "GetNumaHighestNodeNumber");
	pGetNumaNodeProcessorMask = (void *)GetProcAddress(library, "GetNumaNodeProcessorMask");
	pGetNumaNodeProcessorMaskEx = (void *)GetProcAddress(library, "GetNumaNodeProcessorMaskEx");
	pGetNumaAvailableMemoryNode = (void *)GetProcAddress(library, "GetNumaAvailableMemoryNode");
	pGetNumaAvailableMemoryNodeEx = (void *)GetProcAddress(library, "GetNumaAvailableMemoryNodeEx");
	pGetNumaProcessorNode = (void *)GetProcAddress(library, "GetNumaProcessorNode");
	pGetNumaProcessorNodeEx = (void *)GetProcAddress(library, "GetNumaProcessorNodeEx");
	pGetNumaProximityNode = (void *)GetProcAddress(library, "GetNumaProximityNode");
	pGetNumaProximityNodeEx = (void *)GetProcAddress(library, "GetNumaProximityNodeEx");
	pGetProcessDEPPolicy = (void *)GetProcAddress(library, "GetProcessDEPPolicy");
	pFlushProcessWriteBuffers = (void *)GetProcAddress(library, "FlushProcessWriteBuffers");
	pUnregisterApplicationRestart = (void *)GetProcAddress(library, "UnregisterApplicationRestart");
	pCreateUmsCompletionList = (void *)GetProcAddress(library, "CreateUmsCompletionList");
	pCreateUmsThreadContext = (void *)GetProcAddress(library, "CreateUmsThreadContext");
	pDeleteUmsCompletionList = (void *)GetProcAddress(library, "DeleteUmsCompletionList");
	pDeleteUmsThreadContext = (void *)GetProcAddress(library, "DeleteUmsThreadContext");
	pDequeueUmsCompletionListItems = (void *)GetProcAddress(library, "DequeueUmsCompletionListItems");
	pEnterUmsSchedulingMode = (void *)GetProcAddress(library, "EnterUmsSchedulingMode");
	pExecuteUmsThread = (void *)GetProcAddress(library, "ExecuteUmsThread");
	pGetCurrentUmsThread = (void *)GetProcAddress(library, "GetCurrentUmsThread");
	pGetNextUmsListItem = (void *)GetProcAddress(library, "GetNextUmsListItem");
	pGetUmsCompletionListEvent = (void *)GetProcAddress(library, "GetUmsCompletionListEvent");
	pQueryUmsThreadInformation = (void *)GetProcAddress(library, "QueryUmsThreadInformation");
	pSetUmsThreadInformation = (void *)GetProcAddress(library, "SetUmsThreadInformation");
	pUmsThreadYield = (void *)GetProcAddress(library, "UmsThreadYield");
	pBaseFlushAppcompatCache = (void *)GetProcAddress(library, "BaseFlushAppcompatCache");
	pGetProfileIntA = (void *)GetProcAddress(library, "GetProfileIntA");
	pGetProfileIntW = (void *)GetProcAddress(library, "GetProfileIntW");
	pGetPrivateProfileStringW = (void *)GetProcAddress(library, "GetPrivateProfileStringW");
	pGetPrivateProfileStringA = (void *)GetProcAddress(library, "GetPrivateProfileStringA");
	pGetProfileStringA = (void *)GetProcAddress(library, "GetProfileStringA");
	pGetProfileStringW = (void *)GetProcAddress(library, "GetProfileStringW");
	pWriteProfileStringA = (void *)GetProcAddress(library, "WriteProfileStringA");
	pWriteProfileStringW = (void *)GetProcAddress(library, "WriteProfileStringW");
	pGetPrivateProfileIntW = (void *)GetProcAddress(library, "GetPrivateProfileIntW");
	pGetPrivateProfileIntA = (void *)GetProcAddress(library, "GetPrivateProfileIntA");
	pGetPrivateProfileSectionW = (void *)GetProcAddress(library, "GetPrivateProfileSectionW");
	pGetPrivateProfileSectionA = (void *)GetProcAddress(library, "GetPrivateProfileSectionA");
	pGetProfileSectionA = (void *)GetProcAddress(library, "GetProfileSectionA");
	pGetProfileSectionW = (void *)GetProcAddress(library, "GetProfileSectionW");
	pWritePrivateProfileStringW = (void *)GetProcAddress(library, "WritePrivateProfileStringW");
	pWritePrivateProfileStringA = (void *)GetProcAddress(library, "WritePrivateProfileStringA");
	pWritePrivateProfileSectionW = (void *)GetProcAddress(library, "WritePrivateProfileSectionW");
	pWritePrivateProfileSectionA = (void *)GetProcAddress(library, "WritePrivateProfileSectionA");
	pWriteProfileSectionA = (void *)GetProcAddress(library, "WriteProfileSectionA");
	pWriteProfileSectionW = (void *)GetProcAddress(library, "WriteProfileSectionW");
	pGetPrivateProfileSectionNamesW = (void *)GetProcAddress(library, "GetPrivateProfileSectionNamesW");
	pGetPrivateProfileSectionNamesA = (void *)GetProcAddress(library, "GetPrivateProfileSectionNamesA");
	pGetPrivateProfileStructW = (void *)GetProcAddress(library, "GetPrivateProfileStructW");
	pGetPrivateProfileStructA = (void *)GetProcAddress(library, "GetPrivateProfileStructA");
	pWritePrivateProfileStructW = (void *)GetProcAddress(library, "WritePrivateProfileStructW");
	pWritePrivateProfileStructA = (void *)GetProcAddress(library, "WritePrivateProfileStructA");
	pOpenProfileUserMapping = (void *)GetProcAddress(library, "OpenProfileUserMapping");
	pCloseProfileUserMapping = (void *)GetProcAddress(library, "CloseProfileUserMapping");
	pFindResourceExA = (void *)GetProcAddress(library, "FindResourceExA");
	pFindResourceA = (void *)GetProcAddress(library, "FindResourceA");
	pEnumResourceTypesA = (void *)GetProcAddress(library, "EnumResourceTypesA");
	pEnumResourceTypesW = (void *)GetProcAddress(library, "EnumResourceTypesW");
	pEnumResourceNamesA = (void *)GetProcAddress(library, "EnumResourceNamesA");
	pEnumResourceLanguagesA = (void *)GetProcAddress(library, "EnumResourceLanguagesA");
	pEnumResourceLanguagesW = (void *)GetProcAddress(library, "EnumResourceLanguagesW");
	pBeginUpdateResourceW = (void *)GetProcAddress(library, "BeginUpdateResourceW");
	pBeginUpdateResourceA = (void *)GetProcAddress(library, "BeginUpdateResourceA");
	pEndUpdateResourceW = (void *)GetProcAddress(library, "EndUpdateResourceW");
	pEndUpdateResourceA = (void *)GetProcAddress(library, "EndUpdateResourceA");
	pUpdateResourceW = (void *)GetProcAddress(library, "UpdateResourceW");
	pUpdateResourceA = (void *)GetProcAddress(library, "UpdateResourceA");
	plstrcatA = (void *)GetProcAddress(library, "lstrcatA");
	plstrcatW = (void *)GetProcAddress(library, "lstrcatW");
	plstrcpyA = (void *)GetProcAddress(library, "lstrcpyA");
	plstrcpyW = (void *)GetProcAddress(library, "lstrcpyW");
	pRegisterWaitForSingleObject = (void *)GetProcAddress(library, "RegisterWaitForSingleObject");
	pUnregisterWait = (void *)GetProcAddress(library, "UnregisterWait");
	pMakeCriticalSectionGlobal = (void *)GetProcAddress(library, "MakeCriticalSectionGlobal");
	pReinitializeCriticalSection = (void *)GetProcAddress(library, "ReinitializeCriticalSection");
	pUninitializeCriticalSection = (void *)GetProcAddress(library, "UninitializeCriticalSection");
	pOpenMutexA = (void *)GetProcAddress(library, "OpenMutexA");
	pCreateSemaphoreA = (void *)GetProcAddress(library, "CreateSemaphoreA");
	pCreateSemaphoreExA = (void *)GetProcAddress(library, "CreateSemaphoreExA");
	pOpenSemaphoreA = (void *)GetProcAddress(library, "OpenSemaphoreA");
	pCreateJobObjectW = (void *)GetProcAddress(library, "CreateJobObjectW");
	pCreateJobObjectA = (void *)GetProcAddress(library, "CreateJobObjectA");
	pOpenJobObjectW = (void *)GetProcAddress(library, "OpenJobObjectW");
	pOpenJobObjectA = (void *)GetProcAddress(library, "OpenJobObjectA");
	pTerminateJobObject = (void *)GetProcAddress(library, "TerminateJobObject");
	pQueryInformationJobObject = (void *)GetProcAddress(library, "QueryInformationJobObject");
	pSetInformationJobObject = (void *)GetProcAddress(library, "SetInformationJobObject");
	pAssignProcessToJobObject = (void *)GetProcAddress(library, "AssignProcessToJobObject");
	pIsProcessInJob = (void *)GetProcAddress(library, "IsProcessInJob");
	pCreateWaitableTimerA = (void *)GetProcAddress(library, "CreateWaitableTimerA");
	pCreateWaitableTimerExA = (void *)GetProcAddress(library, "CreateWaitableTimerExA");
	pOpenWaitableTimerA = (void *)GetProcAddress(library, "OpenWaitableTimerA");
	pDeleteTimerQueue = (void *)GetProcAddress(library, "DeleteTimerQueue");
	pCancelTimerQueueTimer = (void *)GetProcAddress(library, "CancelTimerQueueTimer");
	pCreateFileMappingA = (void *)GetProcAddress(library, "CreateFileMappingA");
	pOpenFileMappingA = (void *)GetProcAddress(library, "OpenFileMappingA");
	pCreateNamedPipeA = (void *)GetProcAddress(library, "CreateNamedPipeA");
	pWaitNamedPipeA = (void *)GetProcAddress(library, "WaitNamedPipeA");
	pGetNamedPipeClientProcessId = (void *)GetProcAddress(library, "GetNamedPipeClientProcessId");
	pGetNamedPipeServerProcessId = (void *)GetProcAddress(library, "GetNamedPipeServerProcessId");
	pGetNamedPipeClientSessionId = (void *)GetProcAddress(library, "GetNamedPipeClientSessionId");
	pGetNamedPipeServerSessionId = (void *)GetProcAddress(library, "GetNamedPipeServerSessionId");
	pGetNamedPipeHandleStateA = (void *)GetProcAddress(library, "GetNamedPipeHandleStateA");
	pGetNamedPipeHandleStateW = (void *)GetProcAddress(library, "GetNamedPipeHandleStateW");
	pCallNamedPipeA = (void *)GetProcAddress(library, "CallNamedPipeA");
	pCreatePipe = (void *)GetProcAddress(library, "CreatePipe");
	pCreateMailslotA = (void *)GetProcAddress(library, "CreateMailslotA");
	pCreateMailslotW = (void *)GetProcAddress(library, "CreateMailslotW");
	pGetMailslotInfo = (void *)GetProcAddress(library, "GetMailslotInfo");
	pSetMailslotInfo = (void *)GetProcAddress(library, "SetMailslotInfo");
	pBindIoCompletionCallback = (void *)GetProcAddress(library, "BindIoCompletionCallback");
	pCreateMemoryResourceNotification = (void *)GetProcAddress(library, "CreateMemoryResourceNotification");
	pQueryMemoryResourceNotification = (void *)GetProcAddress(library, "QueryMemoryResourceNotification");
	pInitOnceBeginInitialize = (void *)GetProcAddress(library, "InitOnceBeginInitialize");
	pInitOnceComplete = (void *)GetProcAddress(library, "InitOnceComplete");
	pInitOnceExecuteOnce = (void *)GetProcAddress(library, "InitOnceExecuteOnce");
	pBackupRead = (void *)GetProcAddress(library, "BackupRead");
	pBackupSeek = (void *)GetProcAddress(library, "BackupSeek");
	pBackupWrite = (void *)GetProcAddress(library, "BackupWrite");
	pCreateTapePartition = (void *)GetProcAddress(library, "CreateTapePartition");
	pEraseTape = (void *)GetProcAddress(library, "EraseTape");
	pGetTapeParameters = (void *)GetProcAddress(library, "GetTapeParameters");
	pGetTapePosition = (void *)GetProcAddress(library, "GetTapePosition");
	pGetTapeStatus = (void *)GetProcAddress(library, "GetTapeStatus");
	pPrepareTape = (void *)GetProcAddress(library, "PrepareTape");
	pSetTapeParameters = (void *)GetProcAddress(library, "SetTapeParameters");
	pSetTapePosition = (void *)GetProcAddress(library, "SetTapePosition");
	pWriteTapemark = (void *)GetProcAddress(library, "WriteTapemark");
	pFreeLibraryAndExitThread = (void *)GetProcAddress(library, "FreeLibraryAndExitThread");
	pWow64SetThreadContext = (void *)GetProcAddress(library, "Wow64SetThreadContext");
	pWow64GetThreadContext = (void *)GetProcAddress(library, "Wow64GetThreadContext");
	pSetThreadAffinityMask = (void *)GetProcAddress(library, "SetThreadAffinityMask");
	pGetThreadSelectorEntry = (void *)GetProcAddress(library, "GetThreadSelectorEntry");
	pSetLocalTime = (void *)GetProcAddress(library, "SetLocalTime");
	pGetSystemTimeAdjustment = (void *)GetProcAddress(library, "GetSystemTimeAdjustment");
	pSetSystemTime = (void *)GetProcAddress(library, "SetSystemTime");
	pSetSystemTimeAdjustment = (void *)GetProcAddress(library, "SetSystemTimeAdjustment");
	pGetTimeZoneInformation = (void *)GetProcAddress(library, "GetTimeZoneInformation");
	pGetTimeZoneInformationForYear = (void *)GetProcAddress(library, "GetTimeZoneInformationForYear");
	pSetTimeZoneInformation = (void *)GetProcAddress(library, "SetTimeZoneInformation");
	pSystemTimeToTzSpecificLocalTime = (void *)GetProcAddress(library, "SystemTimeToTzSpecificLocalTime");
	pTzSpecificLocalTimeToSystemTime = (void *)GetProcAddress(library, "TzSpecificLocalTimeToSystemTime");
	pGetSystemTimePreciseAsFileTime = (void *)GetProcAddress(library, "GetSystemTimePreciseAsFileTime");
	pGetProcessTimes = (void *)GetProcAddress(library, "GetProcessTimes");
	pGetCalendarInfoA = (void *)GetProcAddress(library, "GetCalendarInfoA");
	pGetCalendarInfoW = (void *)GetProcAddress(library, "GetCalendarInfoW");
	pGetCalendarInfoEx = (void *)GetProcAddress(library, "GetCalendarInfoEx");
	pSetCalendarInfoA = (void *)GetProcAddress(library, "SetCalendarInfoA");
	pSetCalendarInfoW = (void *)GetProcAddress(library, "SetCalendarInfoW");
	pLocalFileTimeToFileTime = (void *)GetProcAddress(library, "LocalFileTimeToFileTime");
	pFileTimeToLocalFileTime = (void *)GetProcAddress(library, "FileTimeToLocalFileTime");
	pFileTimeToSystemTime = (void *)GetProcAddress(library, "FileTimeToSystemTime");
	pSystemTimeToFileTime = (void *)GetProcAddress(library, "SystemTimeToFileTime");
	pCompareFileTime = (void *)GetProcAddress(library, "CompareFileTime");
	pGetLocalTime = (void *)GetProcAddress(library, "GetLocalTime");
	pGetSystemTime = (void *)GetProcAddress(library, "GetSystemTime");
	pGetDaylightFlag = (void *)GetProcAddress(library, "GetDaylightFlag");
	pDosDateTimeToFileTime = (void *)GetProcAddress(library, "DosDateTimeToFileTime");
	pFileTimeToDosDateTime = (void *)GetProcAddress(library, "FileTimeToDosDateTime");
	pGetSystemTimes = (void *)GetProcAddress(library, "GetSystemTimes");
	pGetDynamicTimeZoneInformation = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformation");
	pGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformationEffectiveYears");
	pQueryProcessCycleTime = (void *)GetProcAddress(library, "QueryProcessCycleTime");
	pQueryThreadCycleTime = (void *)GetProcAddress(library, "QueryThreadCycleTime");
	pQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "QueryUnbiasedInterruptTime");
	pGetTickCount64 = (void *)GetProcAddress(library, "GetTickCount64");
	pGetTickCount = (void *)GetProcAddress(library, "GetTickCount");
	pCreateToolhelp32Snapshot = (void *)GetProcAddress(library, "CreateToolhelp32Snapshot");
	pThread32First = (void *)GetProcAddress(library, "Thread32First");
	pThread32Next = (void *)GetProcAddress(library, "Thread32Next");
	pProcess32First = (void *)GetProcAddress(library, "Process32First");
	pProcess32Next = (void *)GetProcAddress(library, "Process32Next");
	pProcess32FirstW = (void *)GetProcAddress(library, "Process32FirstW");
	pProcess32NextW = (void *)GetProcAddress(library, "Process32NextW");
	pModule32FirstW = (void *)GetProcAddress(library, "Module32FirstW");
	pModule32NextW = (void *)GetProcAddress(library, "Module32NextW");
	pModule32First = (void *)GetProcAddress(library, "Module32First");
	pModule32Next = (void *)GetProcAddress(library, "Module32Next");
	pHeap32ListFirst = (void *)GetProcAddress(library, "Heap32ListFirst");
	pToolhelp32ReadProcessMemory = (void *)GetProcAddress(library, "Toolhelp32ReadProcessMemory");
	pGetVersion = (void *)GetProcAddress(library, "GetVersion");
	pGetVersionExA = (void *)GetProcAddress(library, "GetVersionExA");
	pGetVersionExW = (void *)GetProcAddress(library, "GetVersionExW");
	pVerifyVersionInfoA = (void *)GetProcAddress(library, "VerifyVersionInfoA");
	pVerifyVersionInfoW = (void *)GetProcAddress(library, "VerifyVersionInfoW");
	pTermsrvAppInstallMode = (void *)GetProcAddress(library, "TermsrvAppInstallMode");
	pSetTermsrvAppInstallMode = (void *)GetProcAddress(library, "SetTermsrvAppInstallMode");
	pGetProductInfo = (void *)GetProcAddress(library, "GetProductInfo");
	pGetCurrentPackageId = (void *)GetProcAddress(library, "GetCurrentPackageId");
	pGetCurrentPackageFamilyName = (void *)GetProcAddress(library, "GetCurrentPackageFamilyName");
	pGetCurrentPackageFullName = (void *)GetProcAddress(library, "GetCurrentPackageFullName");
	pGetPackageFullName = (void *)GetProcAddress(library, "GetPackageFullName");
	pVirtualAlloc = (void *)GetProcAddress(library, "VirtualAlloc");
	pVirtualAllocEx = (void *)GetProcAddress(library, "VirtualAllocEx");
	pVirtualAllocExNuma = (void *)GetProcAddress(library, "VirtualAllocExNuma");
	pVirtualFree = (void *)GetProcAddress(library, "VirtualFree");
	pVirtualFreeEx = (void *)GetProcAddress(library, "VirtualFreeEx");
	pVirtualLock = (void *)GetProcAddress(library, "VirtualLock");
	pVirtualUnlock = (void *)GetProcAddress(library, "VirtualUnlock");
	pVirtualProtect = (void *)GetProcAddress(library, "VirtualProtect");
	pVirtualProtectEx = (void *)GetProcAddress(library, "VirtualProtectEx");
	pVirtualQuery = (void *)GetProcAddress(library, "VirtualQuery");
	pVirtualQueryEx = (void *)GetProcAddress(library, "VirtualQueryEx");
	pMapViewOfFile = (void *)GetProcAddress(library, "MapViewOfFile");
	pMapViewOfFileEx = (void *)GetProcAddress(library, "MapViewOfFileEx");
	pUnmapViewOfFile = (void *)GetProcAddress(library, "UnmapViewOfFile");
	pFlushViewOfFile = (void *)GetProcAddress(library, "FlushViewOfFile");
	pGetWriteWatch = (void *)GetProcAddress(library, "GetWriteWatch");
	pResetWriteWatch = (void *)GetProcAddress(library, "ResetWriteWatch");
	pIsBadReadPtr = (void *)GetProcAddress(library, "IsBadReadPtr");
	pIsBadWritePtr = (void *)GetProcAddress(library, "IsBadWritePtr");
	pIsBadHugeReadPtr = (void *)GetProcAddress(library, "IsBadHugeReadPtr");
	pIsBadHugeWritePtr = (void *)GetProcAddress(library, "IsBadHugeWritePtr");
	pIsBadCodePtr = (void *)GetProcAddress(library, "IsBadCodePtr");
	pIsBadStringPtrA = (void *)GetProcAddress(library, "IsBadStringPtrA");
	pIsBadStringPtrW = (void *)GetProcAddress(library, "IsBadStringPtrW");
	pK32GetMappedFileNameA = (void *)GetProcAddress(library, "K32GetMappedFileNameA");
	pK32GetMappedFileNameW = (void *)GetProcAddress(library, "K32GetMappedFileNameW");
	pK32EnumPageFilesA = (void *)GetProcAddress(library, "K32EnumPageFilesA");
	pK32EnumPageFilesW = (void *)GetProcAddress(library, "K32EnumPageFilesW");
	pK32GetWsChanges = (void *)GetProcAddress(library, "K32GetWsChanges");
	pK32GetWsChangesEx = (void *)GetProcAddress(library, "K32GetWsChangesEx");
	pK32InitializeProcessForWsWatch = (void *)GetProcAddress(library, "K32InitializeProcessForWsWatch");
	pGetVolumeInformationW = (void *)GetProcAddress(library, "GetVolumeInformationW");
	pGetVolumeInformationA = (void *)GetProcAddress(library, "GetVolumeInformationA");
	pSetVolumeLabelW = (void *)GetProcAddress(library, "SetVolumeLabelW");
	pSetVolumeLabelA = (void *)GetProcAddress(library, "SetVolumeLabelA");
	pGetVolumeNameForVolumeMountPointA = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointA");
	pGetVolumeNameForVolumeMountPointW = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointW");
	pDefineDosDeviceW = (void *)GetProcAddress(library, "DefineDosDeviceW");
	pDefineDosDeviceA = (void *)GetProcAddress(library, "DefineDosDeviceA");
	pQueryDosDeviceW = (void *)GetProcAddress(library, "QueryDosDeviceW");
	pQueryDosDeviceA = (void *)GetProcAddress(library, "QueryDosDeviceA");
	pGetLogicalDrives = (void *)GetProcAddress(library, "GetLogicalDrives");
	pGetLogicalDriveStringsA = (void *)GetProcAddress(library, "GetLogicalDriveStringsA");
	pGetLogicalDriveStringsW = (void *)GetProcAddress(library, "GetLogicalDriveStringsW");
	pGetDriveTypeW = (void *)GetProcAddress(library, "GetDriveTypeW");
	pGetDriveTypeA = (void *)GetProcAddress(library, "GetDriveTypeA");
	pGetDiskFreeSpaceExW = (void *)GetProcAddress(library, "GetDiskFreeSpaceExW");
	pGetDiskFreeSpaceExA = (void *)GetProcAddress(library, "GetDiskFreeSpaceExA");
	pGetDiskFreeSpaceW = (void *)GetProcAddress(library, "GetDiskFreeSpaceW");
	pGetDiskFreeSpaceA = (void *)GetProcAddress(library, "GetDiskFreeSpaceA");
	pGetVolumePathNameA = (void *)GetProcAddress(library, "GetVolumePathNameA");
	pGetVolumePathNameW = (void *)GetProcAddress(library, "GetVolumePathNameW");
	pGetVolumePathNamesForVolumeNameA = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameA");
	pGetVolumePathNamesForVolumeNameW = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameW");
	pFindFirstVolumeA = (void *)GetProcAddress(library, "FindFirstVolumeA");
	pFindFirstVolumeW = (void *)GetProcAddress(library, "FindFirstVolumeW");
	pFindNextVolumeA = (void *)GetProcAddress(library, "FindNextVolumeA");
	pFindNextVolumeW = (void *)GetProcAddress(library, "FindNextVolumeW");
	pFindVolumeClose = (void *)GetProcAddress(library, "FindVolumeClose");
	pFindFirstVolumeMountPointA = (void *)GetProcAddress(library, "FindFirstVolumeMountPointA");
	pFindFirstVolumeMountPointW = (void *)GetProcAddress(library, "FindFirstVolumeMountPointW");
	pFindVolumeMountPointClose = (void *)GetProcAddress(library, "FindVolumeMountPointClose");
	pDeleteVolumeMountPointA = (void *)GetProcAddress(library, "DeleteVolumeMountPointA");
	pDeleteVolumeMountPointW = (void *)GetProcAddress(library, "DeleteVolumeMountPointW");
	pSetVolumeMountPointA = (void *)GetProcAddress(library, "SetVolumeMountPointA");
	pSetVolumeMountPointW = (void *)GetProcAddress(library, "SetVolumeMountPointW");
	pGetVolumeInformationByHandleW = (void *)GetProcAddress(library, "GetVolumeInformationByHandleW");
	pWerRegisterFile = (void *)GetProcAddress(library, "WerRegisterFile");
	pWerRegisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerRegisterRuntimeExceptionModule");
	pWerSetFlags = (void *)GetProcAddress(library, "WerSetFlags");
	pWerRegisterMemoryBlock = (void *)GetProcAddress(library, "WerRegisterMemoryBlock");
	pWerUnregisterMemoryBlock = (void *)GetProcAddress(library, "WerUnregisterMemoryBlock");
	pWerUnregisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerUnregisterRuntimeExceptionModule");
	initialized = TRUE;
}

void* wine_thunk_get_for_kernel32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pCreateActCtxA)
		return wine32a_CreateActCtxA;
	if (func == pFindActCtxSectionStringA)
		return wine32a_FindActCtxSectionStringA;
	if (func == pInitAtomTable)
		return wine32a_InitAtomTable;
	if (func == pGlobalAddAtomA)
		return wine32a_GlobalAddAtomA;
	if (func == pAddAtomA)
		return wine32a_AddAtomA;
	if (func == pGlobalAddAtomW)
		return wine32a_GlobalAddAtomW;
	if (func == pAddAtomW)
		return wine32a_AddAtomW;
	if (func == pGlobalDeleteAtom)
		return wine32a_GlobalDeleteAtom;
	if (func == pDeleteAtom)
		return wine32a_DeleteAtom;
	if (func == pGlobalFindAtomA)
		return wine32a_GlobalFindAtomA;
	if (func == pFindAtomA)
		return wine32a_FindAtomA;
	if (func == pGlobalFindAtomW)
		return wine32a_GlobalFindAtomW;
	if (func == pFindAtomW)
		return wine32a_FindAtomW;
	if (func == pGlobalGetAtomNameA)
		return wine32a_GlobalGetAtomNameA;
	if (func == pGetAtomNameA)
		return wine32a_GetAtomNameA;
	if (func == pGlobalGetAtomNameW)
		return wine32a_GlobalGetAtomNameW;
	if (func == pGetAtomNameW)
		return wine32a_GetAtomNameW;
	if (func == pFindFirstChangeNotificationA)
		return wine32a_FindFirstChangeNotificationA;
	if (func == pFindFirstChangeNotificationW)
		return wine32a_FindFirstChangeNotificationW;
	if (func == pFindNextChangeNotification)
		return wine32a_FindNextChangeNotification;
	if (func == pFindCloseChangeNotification)
		return wine32a_FindCloseChangeNotification;
	if (func == pReadDirectoryChangesW)
		return wine32a_ReadDirectoryChangesW;
	if (func == pBuildCommDCBA)
		return wine32a_BuildCommDCBA;
	if (func == pBuildCommDCBAndTimeoutsA)
		return wine32a_BuildCommDCBAndTimeoutsA;
	if (func == pBuildCommDCBAndTimeoutsW)
		return wine32a_BuildCommDCBAndTimeoutsW;
	if (func == pBuildCommDCBW)
		return wine32a_BuildCommDCBW;
	if (func == pSetCommBreak)
		return wine32a_SetCommBreak;
	if (func == pClearCommBreak)
		return wine32a_ClearCommBreak;
	if (func == pEscapeCommFunction)
		return wine32a_EscapeCommFunction;
	if (func == pPurgeComm)
		return wine32a_PurgeComm;
	if (func == pClearCommError)
		return wine32a_ClearCommError;
	if (func == pSetupComm)
		return wine32a_SetupComm;
	if (func == pGetCommMask)
		return wine32a_GetCommMask;
	if (func == pSetCommMask)
		return wine32a_SetCommMask;
	if (func == pSetCommState)
		return wine32a_SetCommState;
	if (func == pGetCommState)
		return wine32a_GetCommState;
	if (func == pTransmitCommChar)
		return wine32a_TransmitCommChar;
	if (func == pGetCommTimeouts)
		return wine32a_GetCommTimeouts;
	if (func == pSetCommTimeouts)
		return wine32a_SetCommTimeouts;
	if (func == pGetCommModemStatus)
		return wine32a_GetCommModemStatus;
	if (func == pWaitCommEvent)
		return wine32a_WaitCommEvent;
	if (func == pGetCommProperties)
		return wine32a_GetCommProperties;
	if (func == pCommConfigDialogA)
		return wine32a_CommConfigDialogA;
	if (func == pCommConfigDialogW)
		return wine32a_CommConfigDialogW;
	if (func == pGetCommConfig)
		return wine32a_GetCommConfig;
	if (func == pSetCommConfig)
		return wine32a_SetCommConfig;
	if (func == pSetDefaultCommConfigW)
		return wine32a_SetDefaultCommConfigW;
	if (func == pSetDefaultCommConfigA)
		return wine32a_SetDefaultCommConfigA;
	if (func == pGetDefaultCommConfigW)
		return wine32a_GetDefaultCommConfigW;
	if (func == pGetDefaultCommConfigA)
		return wine32a_GetDefaultCommConfigA;
	if (func == pGetComputerNameW)
		return wine32a_GetComputerNameW;
	if (func == pGetComputerNameA)
		return wine32a_GetComputerNameA;
	if (func == pGetComputerNameExA)
		return wine32a_GetComputerNameExA;
	if (func == pGetComputerNameExW)
		return wine32a_GetComputerNameExW;
	if (func == pSetComputerNameW)
		return wine32a_SetComputerNameW;
	if (func == pSetComputerNameA)
		return wine32a_SetComputerNameA;
	if (func == pSetComputerNameExW)
		return wine32a_SetComputerNameExW;
	if (func == pSetComputerNameExA)
		return wine32a_SetComputerNameExA;
	if (func == pDnsHostnameToComputerNameA)
		return wine32a_DnsHostnameToComputerNameA;
	if (func == pDnsHostnameToComputerNameW)
		return wine32a_DnsHostnameToComputerNameW;
	if (func == pGetConsoleWindow)
		return wine32a_GetConsoleWindow;
	if (func == pGetConsoleCP)
		return wine32a_GetConsoleCP;
	if (func == pSetConsoleCP)
		return wine32a_SetConsoleCP;
	if (func == pGetConsoleOutputCP)
		return wine32a_GetConsoleOutputCP;
	if (func == pSetConsoleOutputCP)
		return wine32a_SetConsoleOutputCP;
	if (func == pBeep)
		return wine32a_Beep;
	if (func == pOpenConsoleW)
		return wine32a_OpenConsoleW;
	if (func == pVerifyConsoleIoHandle)
		return wine32a_VerifyConsoleIoHandle;
	if (func == pDuplicateConsoleHandle)
		return wine32a_DuplicateConsoleHandle;
	if (func == pCloseConsoleHandle)
		return wine32a_CloseConsoleHandle;
	if (func == pGetConsoleInputWaitHandle)
		return wine32a_GetConsoleInputWaitHandle;
	if (func == pWriteConsoleInputA)
		return wine32a_WriteConsoleInputA;
	if (func == pWriteConsoleInputW)
		return wine32a_WriteConsoleInputW;
	if (func == pWriteConsoleOutputA)
		return wine32a_WriteConsoleOutputA;
	if (func == pWriteConsoleOutputW)
		return wine32a_WriteConsoleOutputW;
	if (func == pWriteConsoleOutputCharacterA)
		return wine32a_WriteConsoleOutputCharacterA;
	if (func == pWriteConsoleOutputAttribute)
		return wine32a_WriteConsoleOutputAttribute;
	if (func == pFillConsoleOutputCharacterA)
		return wine32a_FillConsoleOutputCharacterA;
	if (func == pFillConsoleOutputCharacterW)
		return wine32a_FillConsoleOutputCharacterW;
	if (func == pFillConsoleOutputAttribute)
		return wine32a_FillConsoleOutputAttribute;
	if (func == pReadConsoleOutputCharacterA)
		return wine32a_ReadConsoleOutputCharacterA;
	if (func == pReadConsoleOutputCharacterW)
		return wine32a_ReadConsoleOutputCharacterW;
	if (func == pReadConsoleOutputAttribute)
		return wine32a_ReadConsoleOutputAttribute;
	if (func == pReadConsoleOutputA)
		return wine32a_ReadConsoleOutputA;
	if (func == pReadConsoleOutputW)
		return wine32a_ReadConsoleOutputW;
	if (func == pReadConsoleInputA)
		return wine32a_ReadConsoleInputA;
	if (func == pPeekConsoleInputA)
		return wine32a_PeekConsoleInputA;
	if (func == pPeekConsoleInputW)
		return wine32a_PeekConsoleInputW;
	if (func == pGetNumberOfConsoleInputEvents)
		return wine32a_GetNumberOfConsoleInputEvents;
	if (func == pFlushConsoleInputBuffer)
		return wine32a_FlushConsoleInputBuffer;
	if (func == pSetConsoleTitleA)
		return wine32a_SetConsoleTitleA;
	if (func == pGetConsoleKeyboardLayoutNameA)
		return wine32a_GetConsoleKeyboardLayoutNameA;
	if (func == pGetConsoleKeyboardLayoutNameW)
		return wine32a_GetConsoleKeyboardLayoutNameW;
	if (func == pGetConsoleInputExeNameW)
		return wine32a_GetConsoleInputExeNameW;
	if (func == pGetConsoleInputExeNameA)
		return wine32a_GetConsoleInputExeNameA;
	if (func == pGetConsoleTitleA)
		return wine32a_GetConsoleTitleA;
	if (func == pGetConsoleTitleW)
		return wine32a_GetConsoleTitleW;
	if (func == pGetLargestConsoleWindowSize)
		return wine32a_GetLargestConsoleWindowSize;
	if (func == pFreeConsole)
		return wine32a_FreeConsole;
	if (func == pAllocConsole)
		return wine32a_AllocConsole;
	if (func == pReadConsoleA)
		return wine32a_ReadConsoleA;
	if (func == pReadConsoleW)
		return wine32a_ReadConsoleW;
	if (func == pReadConsoleInputW)
		return wine32a_ReadConsoleInputW;
	if (func == pWriteConsoleOutputCharacterW)
		return wine32a_WriteConsoleOutputCharacterW;
	if (func == pSetConsoleTitleW)
		return wine32a_SetConsoleTitleW;
	if (func == pGetNumberOfConsoleMouseButtons)
		return wine32a_GetNumberOfConsoleMouseButtons;
	if (func == pSetConsoleInputExeNameW)
		return wine32a_SetConsoleInputExeNameW;
	if (func == pSetConsoleInputExeNameA)
		return wine32a_SetConsoleInputExeNameA;
	if (func == pSetConsoleCtrlHandler)
		return wine32a_SetConsoleCtrlHandler;
	if (func == pGenerateConsoleCtrlEvent)
		return wine32a_GenerateConsoleCtrlEvent;
	if (func == pCreateConsoleScreenBuffer)
		return wine32a_CreateConsoleScreenBuffer;
	if (func == pGetConsoleScreenBufferInfo)
		return wine32a_GetConsoleScreenBufferInfo;
	if (func == pSetConsoleActiveScreenBuffer)
		return wine32a_SetConsoleActiveScreenBuffer;
	if (func == pGetConsoleMode)
		return wine32a_GetConsoleMode;
	if (func == pSetConsoleMode)
		return wine32a_SetConsoleMode;
	if (func == pWriteConsoleW)
		return wine32a_WriteConsoleW;
	if (func == pWriteConsoleA)
		return wine32a_WriteConsoleA;
	if (func == pSetConsoleCursorPosition)
		return wine32a_SetConsoleCursorPosition;
	if (func == pGetConsoleCursorInfo)
		return wine32a_GetConsoleCursorInfo;
	if (func == pSetConsoleCursorInfo)
		return wine32a_SetConsoleCursorInfo;
	if (func == pSetConsoleWindowInfo)
		return wine32a_SetConsoleWindowInfo;
	if (func == pSetConsoleTextAttribute)
		return wine32a_SetConsoleTextAttribute;
	if (func == pSetConsoleScreenBufferSize)
		return wine32a_SetConsoleScreenBufferSize;
	if (func == pScrollConsoleScreenBufferA)
		return wine32a_ScrollConsoleScreenBufferA;
	if (func == pScrollConsoleScreenBufferW)
		return wine32a_ScrollConsoleScreenBufferW;
	if (func == pAttachConsole)
		return wine32a_AttachConsole;
	if (func == pGetConsoleDisplayMode)
		return wine32a_GetConsoleDisplayMode;
	if (func == pSetConsoleDisplayMode)
		return wine32a_SetConsoleDisplayMode;
	if (func == pGetConsoleAliasW)
		return wine32a_GetConsoleAliasW;
	if (func == pGetConsoleProcessList)
		return wine32a_GetConsoleProcessList;
	if (func == pGetConsoleCommandHistoryA)
		return wine32a_GetConsoleCommandHistoryA;
	if (func == pGetConsoleCommandHistoryW)
		return wine32a_GetConsoleCommandHistoryW;
	if (func == pGetConsoleCommandHistoryLengthA)
		return wine32a_GetConsoleCommandHistoryLengthA;
	if (func == pGetConsoleCommandHistoryLengthW)
		return wine32a_GetConsoleCommandHistoryLengthW;
	if (func == pGetConsoleAliasesLengthA)
		return wine32a_GetConsoleAliasesLengthA;
	if (func == pGetConsoleAliasesLengthW)
		return wine32a_GetConsoleAliasesLengthW;
	if (func == pGetConsoleAliasExesLengthA)
		return wine32a_GetConsoleAliasExesLengthA;
	if (func == pGetConsoleAliasExesLengthW)
		return wine32a_GetConsoleAliasExesLengthW;
	if (func == pExpungeConsoleCommandHistoryA)
		return wine32a_ExpungeConsoleCommandHistoryA;
	if (func == pExpungeConsoleCommandHistoryW)
		return wine32a_ExpungeConsoleCommandHistoryW;
	if (func == pAddConsoleAliasA)
		return wine32a_AddConsoleAliasA;
	if (func == pAddConsoleAliasW)
		return wine32a_AddConsoleAliasW;
	if (func == pSetConsoleIcon)
		return wine32a_SetConsoleIcon;
	if (func == pGetNumberOfConsoleFonts)
		return wine32a_GetNumberOfConsoleFonts;
	if (func == pSetConsoleFont)
		return wine32a_SetConsoleFont;
	if (func == pSetConsoleKeyShortcuts)
		return wine32a_SetConsoleKeyShortcuts;
	if (func == pGetCurrentConsoleFont)
		return wine32a_GetCurrentConsoleFont;
	if (func == pGetConsoleFontSize)
		return wine32a_GetConsoleFontSize;
	if (func == pGetConsoleFontInfo)
		return wine32a_GetConsoleFontInfo;
	if (func == pGetConsoleScreenBufferInfoEx)
		return wine32a_GetConsoleScreenBufferInfoEx;
	if (func == pSetConsoleScreenBufferInfoEx)
		return wine32a_SetConsoleScreenBufferInfoEx;
	if (func == pSetCurrentConsoleFontEx)
		return wine32a_SetCurrentConsoleFontEx;
	if (func == pQueryPerformanceCounter)
		return wine32a_QueryPerformanceCounter;
	if (func == pQueryPerformanceFrequency)
		return wine32a_QueryPerformanceFrequency;
	if (func == pGetSystemInfo)
		return wine32a_GetSystemInfo;
	if (func == pGetNativeSystemInfo)
		return wine32a_GetNativeSystemInfo;
	if (func == pIsProcessorFeaturePresent)
		return wine32a_IsProcessorFeaturePresent;
	if (func == pK32GetPerformanceInfo)
		return wine32a_K32GetPerformanceInfo;
	if (func == pGetLargePageMinimum)
		return wine32a_GetLargePageMinimum;
	if (func == pGetActiveProcessorGroupCount)
		return wine32a_GetActiveProcessorGroupCount;
	if (func == pGetActiveProcessorCount)
		return wine32a_GetActiveProcessorCount;
	if (func == pGetMaximumProcessorCount)
		return wine32a_GetMaximumProcessorCount;
	if (func == pGetSystemFirmwareTable)
		return wine32a_GetSystemFirmwareTable;
	if (func == pEnumSystemFirmwareTables)
		return wine32a_EnumSystemFirmwareTables;
	if (func == pWaitForDebugEvent)
		return wine32a_WaitForDebugEvent;
	if (func == pContinueDebugEvent)
		return wine32a_ContinueDebugEvent;
	if (func == pDebugActiveProcess)
		return wine32a_DebugActiveProcess;
	if (func == pDebugActiveProcessStop)
		return wine32a_DebugActiveProcessStop;
	if (func == pOutputDebugStringA)
		return wine32a_OutputDebugStringA;
	if (func == pOutputDebugStringW)
		return wine32a_OutputDebugStringW;
	if (func == pDebugBreakProcess)
		return wine32a_DebugBreakProcess;
	if (func == pIsDebuggerPresent)
		return wine32a_IsDebuggerPresent;
	if (func == pCheckRemoteDebuggerPresent)
		return wine32a_CheckRemoteDebuggerPresent;
	if (func == pDebugSetProcessKillOnExit)
		return wine32a_DebugSetProcessKillOnExit;
	if (func == pGetCommandLineA)
		return wine32a_GetCommandLineA;
	if (func == pGetCommandLineW)
		return wine32a_GetCommandLineW;
	if (func == pGetEnvironmentStringsA)
		return wine32a_GetEnvironmentStringsA;
	if (func == pGetEnvironmentStringsW)
		return wine32a_GetEnvironmentStringsW;
	if (func == pFreeEnvironmentStringsA)
		return wine32a_FreeEnvironmentStringsA;
	if (func == pFreeEnvironmentStringsW)
		return wine32a_FreeEnvironmentStringsW;
	if (func == pGetEnvironmentVariableA)
		return wine32a_GetEnvironmentVariableA;
	if (func == pGetEnvironmentVariableW)
		return wine32a_GetEnvironmentVariableW;
	if (func == pSetEnvironmentVariableA)
		return wine32a_SetEnvironmentVariableA;
	if (func == pSetEnvironmentVariableW)
		return wine32a_SetEnvironmentVariableW;
	if (func == pExpandEnvironmentStringsA)
		return wine32a_ExpandEnvironmentStringsA;
	if (func == pExpandEnvironmentStringsW)
		return wine32a_ExpandEnvironmentStringsW;
	if (func == pGetStdHandle)
		return wine32a_GetStdHandle;
	if (func == pSetStdHandle)
		return wine32a_SetStdHandle;
	if (func == pGetStartupInfoA)
		return wine32a_GetStartupInfoA;
	if (func == pGetStartupInfoW)
		return wine32a_GetStartupInfoW;
	if (func == pGetFirmwareEnvironmentVariableA)
		return wine32a_GetFirmwareEnvironmentVariableA;
	if (func == pGetFirmwareEnvironmentVariableW)
		return wine32a_GetFirmwareEnvironmentVariableW;
	if (func == pRaiseException)
		return wine32a_RaiseException;
	if (func == pUnhandledExceptionFilter)
		return wine32a_UnhandledExceptionFilter;
	if (func == pSetUnhandledExceptionFilter)
		return wine32a_SetUnhandledExceptionFilter;
	if (func == pFatalAppExitA)
		return wine32a_FatalAppExitA;
	if (func == pFatalAppExitW)
		return wine32a_FatalAppExitW;
	if (func == pFatalExit)
		return wine32a_FatalExit;
	if (func == p_hread)
		return wine32a__hread;
	if (func == p_hwrite)
		return wine32a__hwrite;
	if (func == p_lclose)
		return wine32a__lclose;
	if (func == p_lcreat)
		return wine32a__lcreat;
	if (func == p_lopen)
		return wine32a__lopen;
	if (func == p_lread)
		return wine32a__lread;
	if (func == p_llseek)
		return wine32a__llseek;
	if (func == p_lwrite)
		return wine32a__lwrite;
	if (func == pSetFileCompletionNotificationModes)
		return wine32a_SetFileCompletionNotificationModes;
	if (func == pSetHandleCount)
		return wine32a_SetHandleCount;
	if (func == pReplaceFileW)
		return wine32a_ReplaceFileW;
	if (func == pReplaceFileA)
		return wine32a_ReplaceFileA;
	if (func == pFindFirstFileExW)
		return wine32a_FindFirstFileExW;
	if (func == pFindNextFileW)
		return wine32a_FindNextFileW;
	if (func == pFindClose)
		return wine32a_FindClose;
	if (func == pFindFirstFileA)
		return wine32a_FindFirstFileA;
	if (func == pFindFirstFileExA)
		return wine32a_FindFirstFileExA;
	if (func == pFindFirstFileW)
		return wine32a_FindFirstFileW;
	if (func == pFindNextFileA)
		return wine32a_FindNextFileA;
	if (func == pFindFirstStreamW)
		return wine32a_FindFirstStreamW;
	if (func == pFindNextStreamW)
		return wine32a_FindNextStreamW;
	if (func == pOpenVxDHandle)
		return wine32a_OpenVxDHandle;
	if (func == pDeviceIoControl)
		return wine32a_DeviceIoControl;
	if (func == pOpenFile)
		return wine32a_OpenFile;
	if (func == pK32EnumDeviceDrivers)
		return wine32a_K32EnumDeviceDrivers;
	if (func == pK32GetDeviceDriverBaseNameA)
		return wine32a_K32GetDeviceDriverBaseNameA;
	if (func == pK32GetDeviceDriverBaseNameW)
		return wine32a_K32GetDeviceDriverBaseNameW;
	if (func == pK32GetDeviceDriverFileNameA)
		return wine32a_K32GetDeviceDriverFileNameA;
	if (func == pK32GetDeviceDriverFileNameW)
		return wine32a_K32GetDeviceDriverFileNameW;
	if (func == pGetFinalPathNameByHandleW)
		return wine32a_GetFinalPathNameByHandleW;
	if (func == pGetFinalPathNameByHandleA)
		return wine32a_GetFinalPathNameByHandleA;
	if (func == pFormatMessageA)
		return wine32a_FormatMessageA;
	if (func == pFormatMessageW)
		return wine32a_FormatMessageW;
	if (func == pHeapCreate)
		return wine32a_HeapCreate;
	if (func == pHeapDestroy)
		return wine32a_HeapDestroy;
	if (func == pHeapCompact)
		return wine32a_HeapCompact;
	if (func == pHeapValidate)
		return wine32a_HeapValidate;
	if (func == pHeapWalk)
		return wine32a_HeapWalk;
	if (func == pHeapLock)
		return wine32a_HeapLock;
	if (func == pHeapUnlock)
		return wine32a_HeapUnlock;
	if (func == pHeapAlloc)
		return wine32a_HeapAlloc;
	if (func == pHeapFree)
		return wine32a_HeapFree;
	if (func == pHeapReAlloc)
		return wine32a_HeapReAlloc;
	if (func == pHeapSize)
		return wine32a_HeapSize;
	if (func == pHeapQueryInformation)
		return wine32a_HeapQueryInformation;
	if (func == pHeapSetInformation)
		return wine32a_HeapSetInformation;
	if (func == pGlobalAlloc)
		return wine32a_GlobalAlloc;
	if (func == pGlobalLock)
		return wine32a_GlobalLock;
	if (func == pGlobalUnlock)
		return wine32a_GlobalUnlock;
	if (func == pGlobalHandle)
		return wine32a_GlobalHandle;
	if (func == pGlobalReAlloc)
		return wine32a_GlobalReAlloc;
	if (func == pGlobalFree)
		return wine32a_GlobalFree;
	if (func == pGlobalSize)
		return wine32a_GlobalSize;
	if (func == pGlobalWire)
		return wine32a_GlobalWire;
	if (func == pGlobalUnWire)
		return wine32a_GlobalUnWire;
	if (func == pGlobalFix)
		return wine32a_GlobalFix;
	if (func == pGlobalUnfix)
		return wine32a_GlobalUnfix;
	if (func == pGlobalFlags)
		return wine32a_GlobalFlags;
	if (func == pGlobalCompact)
		return wine32a_GlobalCompact;
	if (func == pLocalAlloc)
		return wine32a_LocalAlloc;
	if (func == pLocalCompact)
		return wine32a_LocalCompact;
	if (func == pLocalFlags)
		return wine32a_LocalFlags;
	if (func == pLocalFree)
		return wine32a_LocalFree;
	if (func == pLocalHandle)
		return wine32a_LocalHandle;
	if (func == pLocalLock)
		return wine32a_LocalLock;
	if (func == pLocalReAlloc)
		return wine32a_LocalReAlloc;
	if (func == pLocalShrink)
		return wine32a_LocalShrink;
	if (func == pLocalSize)
		return wine32a_LocalSize;
	if (func == pLocalUnlock)
		return wine32a_LocalUnlock;
	if (func == pGlobalMemoryStatusEx)
		return wine32a_GlobalMemoryStatusEx;
	if (func == pGlobalMemoryStatus)
		return wine32a_GlobalMemoryStatus;
	if (func == pGetPhysicallyInstalledSystemMemory)
		return wine32a_GetPhysicallyInstalledSystemMemory;
	if (func == pGetSystemFileCacheSize)
		return wine32a_GetSystemFileCacheSize;
	if (func == pSetSystemFileCacheSize)
		return wine32a_SetSystemFileCacheSize;
	if (func == pAllocateUserPhysicalPages)
		return wine32a_AllocateUserPhysicalPages;
	if (func == pFreeUserPhysicalPages)
		return wine32a_FreeUserPhysicalPages;
	if (func == pMapUserPhysicalPages)
		return wine32a_MapUserPhysicalPages;
	if (func == pMulDiv)
		return wine32a_MulDiv;
	if (func == pGetSystemRegistryQuota)
		return wine32a_GetSystemRegistryQuota;
	if (func == pGetDateFormatA)
		return wine32a_GetDateFormatA;
	if (func == pGetDateFormatEx)
		return wine32a_GetDateFormatEx;
	if (func == pGetDateFormatW)
		return wine32a_GetDateFormatW;
	if (func == pGetTimeFormatA)
		return wine32a_GetTimeFormatA;
	if (func == pGetTimeFormatEx)
		return wine32a_GetTimeFormatEx;
	if (func == pGetTimeFormatW)
		return wine32a_GetTimeFormatW;
	if (func == pGetNumberFormatA)
		return wine32a_GetNumberFormatA;
	if (func == pGetNumberFormatW)
		return wine32a_GetNumberFormatW;
	if (func == pGetNumberFormatEx)
		return wine32a_GetNumberFormatEx;
	if (func == pGetCurrencyFormatA)
		return wine32a_GetCurrencyFormatA;
	if (func == pGetCurrencyFormatW)
		return wine32a_GetCurrencyFormatW;
	if (func == pGetCurrencyFormatEx)
		return wine32a_GetCurrencyFormatEx;
	if (func == pEnumDateFormatsExA)
		return wine32a_EnumDateFormatsExA;
	if (func == pEnumDateFormatsExW)
		return wine32a_EnumDateFormatsExW;
	if (func == pEnumDateFormatsA)
		return wine32a_EnumDateFormatsA;
	if (func == pEnumDateFormatsW)
		return wine32a_EnumDateFormatsW;
	if (func == pEnumDateFormatsExEx)
		return wine32a_EnumDateFormatsExEx;
	if (func == pEnumTimeFormatsA)
		return wine32a_EnumTimeFormatsA;
	if (func == pEnumTimeFormatsW)
		return wine32a_EnumTimeFormatsW;
	if (func == pEnumTimeFormatsEx)
		return wine32a_EnumTimeFormatsEx;
	if (func == pEnumCalendarInfoA)
		return wine32a_EnumCalendarInfoA;
	if (func == pEnumCalendarInfoW)
		return wine32a_EnumCalendarInfoW;
	if (func == pEnumCalendarInfoExA)
		return wine32a_EnumCalendarInfoExA;
	if (func == pEnumCalendarInfoExW)
		return wine32a_EnumCalendarInfoExW;
	if (func == pEnumCalendarInfoExEx)
		return wine32a_EnumCalendarInfoExEx;
	if (func == pGetUserDefaultLangID)
		return wine32a_GetUserDefaultLangID;
	if (func == pGetSystemDefaultLangID)
		return wine32a_GetSystemDefaultLangID;
	if (func == pGetUserDefaultLCID)
		return wine32a_GetUserDefaultLCID;
	if (func == pGetSystemDefaultLCID)
		return wine32a_GetSystemDefaultLCID;
	if (func == pGetSystemDefaultLocaleName)
		return wine32a_GetSystemDefaultLocaleName;
	if (func == pGetProcessPreferredUILanguages)
		return wine32a_GetProcessPreferredUILanguages;
	if (func == pGetSystemPreferredUILanguages)
		return wine32a_GetSystemPreferredUILanguages;
	if (func == pSetProcessPreferredUILanguages)
		return wine32a_SetProcessPreferredUILanguages;
	if (func == pSetThreadPreferredUILanguages)
		return wine32a_SetThreadPreferredUILanguages;
	if (func == pGetThreadPreferredUILanguages)
		return wine32a_GetThreadPreferredUILanguages;
	if (func == pGetUserPreferredUILanguages)
		return wine32a_GetUserPreferredUILanguages;
	if (func == pGetUserDefaultUILanguage)
		return wine32a_GetUserDefaultUILanguage;
	if (func == pGetSystemDefaultUILanguage)
		return wine32a_GetSystemDefaultUILanguage;
	if (func == pLocaleNameToLCID)
		return wine32a_LocaleNameToLCID;
	if (func == pLCIDToLocaleName)
		return wine32a_LCIDToLocaleName;
	if (func == pGetLocaleInfoA)
		return wine32a_GetLocaleInfoA;
	if (func == pGetLocaleInfoW)
		return wine32a_GetLocaleInfoW;
	if (func == pGetLocaleInfoEx)
		return wine32a_GetLocaleInfoEx;
	if (func == pSetLocaleInfoA)
		return wine32a_SetLocaleInfoA;
	if (func == pSetLocaleInfoW)
		return wine32a_SetLocaleInfoW;
	if (func == pGetACP)
		return wine32a_GetACP;
	if (func == pSetCPGlobal)
		return wine32a_SetCPGlobal;
	if (func == pGetOEMCP)
		return wine32a_GetOEMCP;
	if (func == pIsValidCodePage)
		return wine32a_IsValidCodePage;
	if (func == pIsDBCSLeadByteEx)
		return wine32a_IsDBCSLeadByteEx;
	if (func == pIsDBCSLeadByte)
		return wine32a_IsDBCSLeadByte;
	if (func == pGetCPInfo)
		return wine32a_GetCPInfo;
	if (func == pGetCPInfoExA)
		return wine32a_GetCPInfoExA;
	if (func == pGetCPInfoExW)
		return wine32a_GetCPInfoExW;
	if (func == pEnumSystemCodePagesA)
		return wine32a_EnumSystemCodePagesA;
	if (func == pEnumSystemCodePagesW)
		return wine32a_EnumSystemCodePagesW;
	if (func == pMultiByteToWideChar)
		return wine32a_MultiByteToWideChar;
	if (func == pWideCharToMultiByte)
		return wine32a_WideCharToMultiByte;
	if (func == pGetThreadLocale)
		return wine32a_GetThreadLocale;
	if (func == pSetThreadLocale)
		return wine32a_SetThreadLocale;
	if (func == pSetThreadUILanguage)
		return wine32a_SetThreadUILanguage;
	if (func == pConvertDefaultLocale)
		return wine32a_ConvertDefaultLocale;
	if (func == pIsValidLocale)
		return wine32a_IsValidLocale;
	if (func == pIsValidLocaleName)
		return wine32a_IsValidLocaleName;
	if (func == pEnumSystemLocalesA)
		return wine32a_EnumSystemLocalesA;
	if (func == pEnumSystemLocalesW)
		return wine32a_EnumSystemLocalesW;
	if (func == pEnumSystemLocalesEx)
		return wine32a_EnumSystemLocalesEx;
	if (func == pVerLanguageNameA)
		return wine32a_VerLanguageNameA;
	if (func == pVerLanguageNameW)
		return wine32a_VerLanguageNameW;
	if (func == pGetStringTypeW)
		return wine32a_GetStringTypeW;
	if (func == pGetStringTypeExW)
		return wine32a_GetStringTypeExW;
	if (func == pGetStringTypeA)
		return wine32a_GetStringTypeA;
	if (func == pGetStringTypeExA)
		return wine32a_GetStringTypeExA;
	if (func == pLCMapStringEx)
		return wine32a_LCMapStringEx;
	if (func == pLCMapStringW)
		return wine32a_LCMapStringW;
	if (func == pLCMapStringA)
		return wine32a_LCMapStringA;
	if (func == pFoldStringA)
		return wine32a_FoldStringA;
	if (func == pFoldStringW)
		return wine32a_FoldStringW;
	if (func == pCompareStringW)
		return wine32a_CompareStringW;
	if (func == pCompareStringEx)
		return wine32a_CompareStringEx;
	if (func == pCompareStringA)
		return wine32a_CompareStringA;
	if (func == pCompareStringOrdinal)
		return wine32a_CompareStringOrdinal;
	if (func == pEnumSystemLanguageGroupsA)
		return wine32a_EnumSystemLanguageGroupsA;
	if (func == pEnumSystemLanguageGroupsW)
		return wine32a_EnumSystemLanguageGroupsW;
	if (func == pIsValidLanguageGroup)
		return wine32a_IsValidLanguageGroup;
	if (func == pEnumLanguageGroupLocalesA)
		return wine32a_EnumLanguageGroupLocalesA;
	if (func == pEnumLanguageGroupLocalesW)
		return wine32a_EnumLanguageGroupLocalesW;
	if (func == pInvalidateNLSCache)
		return wine32a_InvalidateNLSCache;
	if (func == pGetUserGeoID)
		return wine32a_GetUserGeoID;
	if (func == pSetUserGeoID)
		return wine32a_SetUserGeoID;
	if (func == pEnumUILanguagesA)
		return wine32a_EnumUILanguagesA;
	if (func == pEnumUILanguagesW)
		return wine32a_EnumUILanguagesW;
	if (func == pGetGeoInfoW)
		return wine32a_GetGeoInfoW;
	if (func == pGetGeoInfoA)
		return wine32a_GetGeoInfoA;
	if (func == pEnumSystemGeoID)
		return wine32a_EnumSystemGeoID;
	if (func == pGetUserDefaultLocaleName)
		return wine32a_GetUserDefaultLocaleName;
	if (func == pNormalizeString)
		return wine32a_NormalizeString;
	if (func == pIsNormalizedString)
		return wine32a_IsNormalizedString;
	if (func == pIdnToAscii)
		return wine32a_IdnToAscii;
	if (func == pIdnToNameprepUnicode)
		return wine32a_IdnToNameprepUnicode;
	if (func == pIdnToUnicode)
		return wine32a_IdnToUnicode;
	if (func == pGetFileMUIPath)
		return wine32a_GetFileMUIPath;
	if (func == pGetFileMUIInfo)
		return wine32a_GetFileMUIInfo;
	if (func == pResolveLocaleName)
		return wine32a_ResolveLocaleName;
	if (func == pFindNLSStringEx)
		return wine32a_FindNLSStringEx;
	if (func == pFindStringOrdinal)
		return wine32a_FindStringOrdinal;
	if (func == pLZStart)
		return wine32a_LZStart;
	if (func == pLZInit)
		return wine32a_LZInit;
	if (func == pLZDone)
		return wine32a_LZDone;
	if (func == pGetExpandedNameA)
		return wine32a_GetExpandedNameA;
	if (func == pGetExpandedNameW)
		return wine32a_GetExpandedNameW;
	if (func == pLZRead)
		return wine32a_LZRead;
	if (func == pLZSeek)
		return wine32a_LZSeek;
	if (func == pLZCopy)
		return wine32a_LZCopy;
	if (func == pLZOpenFileA)
		return wine32a_LZOpenFileA;
	if (func == pLZOpenFileW)
		return wine32a_LZOpenFileW;
	if (func == pLZClose)
		return wine32a_LZClose;
	if (func == pGetDllDirectoryA)
		return wine32a_GetDllDirectoryA;
	if (func == pGetDllDirectoryW)
		return wine32a_GetDllDirectoryW;
	if (func == pSetDllDirectoryA)
		return wine32a_SetDllDirectoryA;
	if (func == pSetDllDirectoryW)
		return wine32a_SetDllDirectoryW;
	if (func == pAddDllDirectory)
		return wine32a_AddDllDirectory;
	if (func == pRemoveDllDirectory)
		return wine32a_RemoveDllDirectory;
	if (func == pSetDefaultDllDirectories)
		return wine32a_SetDefaultDllDirectories;
	if (func == pGetBinaryTypeW)
		return wine32a_GetBinaryTypeW;
	if (func == pGetBinaryTypeA)
		return wine32a_GetBinaryTypeA;
	if (func == pLoadLibraryExA)
		return wine32a_LoadLibraryExA;
	if (func == pLoadLibraryExW)
		return wine32a_LoadLibraryExW;
	if (func == pLoadLibraryA)
		return wine32a_LoadLibraryA;
	if (func == pLoadLibraryW)
		return wine32a_LoadLibraryW;
	if (func == pFreeLibrary)
		return wine32a_FreeLibrary;
	if (func == pGetProcAddress)
		return wine32a_GetProcAddress;
	if (func == pDelayLoadFailureHook)
		return wine32a_DelayLoadFailureHook;
	if (func == pK32EnumProcessModules)
		return wine32a_K32EnumProcessModules;
	if (func == pK32EnumProcessModulesEx)
		return wine32a_K32EnumProcessModulesEx;
	if (func == pK32GetModuleBaseNameW)
		return wine32a_K32GetModuleBaseNameW;
	if (func == pK32GetModuleBaseNameA)
		return wine32a_K32GetModuleBaseNameA;
	if (func == pK32GetModuleFileNameExW)
		return wine32a_K32GetModuleFileNameExW;
	if (func == pK32GetModuleFileNameExA)
		return wine32a_K32GetModuleFileNameExA;
	if (func == pK32GetModuleInformation)
		return wine32a_K32GetModuleInformation;
	if (func == pGetFullPathNameW)
		return wine32a_GetFullPathNameW;
	if (func == pGetFullPathNameA)
		return wine32a_GetFullPathNameA;
	if (func == pGetLongPathNameW)
		return wine32a_GetLongPathNameW;
	if (func == pGetLongPathNameA)
		return wine32a_GetLongPathNameA;
	if (func == pGetShortPathNameW)
		return wine32a_GetShortPathNameW;
	if (func == pGetShortPathNameA)
		return wine32a_GetShortPathNameA;
	if (func == pGetTempPathA)
		return wine32a_GetTempPathA;
	if (func == pGetTempPathW)
		return wine32a_GetTempPathW;
	if (func == pGetTempFileNameA)
		return wine32a_GetTempFileNameA;
	if (func == pGetTempFileNameW)
		return wine32a_GetTempFileNameW;
	if (func == pSearchPathW)
		return wine32a_SearchPathW;
	if (func == pSearchPathA)
		return wine32a_SearchPathA;
	if (func == pCopyFileW)
		return wine32a_CopyFileW;
	if (func == pCopyFileA)
		return wine32a_CopyFileA;
	if (func == pCopyFileExW)
		return wine32a_CopyFileExW;
	if (func == pCopyFileExA)
		return wine32a_CopyFileExA;
	if (func == pMoveFileTransactedA)
		return wine32a_MoveFileTransactedA;
	if (func == pMoveFileTransactedW)
		return wine32a_MoveFileTransactedW;
	if (func == pMoveFileWithProgressW)
		return wine32a_MoveFileWithProgressW;
	if (func == pMoveFileWithProgressA)
		return wine32a_MoveFileWithProgressA;
	if (func == pMoveFileExW)
		return wine32a_MoveFileExW;
	if (func == pMoveFileExA)
		return wine32a_MoveFileExA;
	if (func == pMoveFileW)
		return wine32a_MoveFileW;
	if (func == pMoveFileA)
		return wine32a_MoveFileA;
	if (func == pCreateHardLinkW)
		return wine32a_CreateHardLinkW;
	if (func == pCreateHardLinkA)
		return wine32a_CreateHardLinkA;
	if (func == pCreateDirectoryExA)
		return wine32a_CreateDirectoryExA;
	if (func == pRemoveDirectoryW)
		return wine32a_RemoveDirectoryW;
	if (func == pRemoveDirectoryA)
		return wine32a_RemoveDirectoryA;
	if (func == pGetCurrentDirectoryW)
		return wine32a_GetCurrentDirectoryW;
	if (func == pGetCurrentDirectoryA)
		return wine32a_GetCurrentDirectoryA;
	if (func == pSetCurrentDirectoryW)
		return wine32a_SetCurrentDirectoryW;
	if (func == pSetCurrentDirectoryA)
		return wine32a_SetCurrentDirectoryA;
	if (func == pGetSystemDirectoryW)
		return wine32a_GetSystemDirectoryW;
	if (func == pGetSystemDirectoryA)
		return wine32a_GetSystemDirectoryA;
	if (func == pGetSystemWow64DirectoryW)
		return wine32a_GetSystemWow64DirectoryW;
	if (func == pGetSystemWow64DirectoryA)
		return wine32a_GetSystemWow64DirectoryA;
	if (func == pWow64EnableWow64FsRedirection)
		return wine32a_Wow64EnableWow64FsRedirection;
	if (func == pNeedCurrentDirectoryForExePathW)
		return wine32a_NeedCurrentDirectoryForExePathW;
	if (func == pNeedCurrentDirectoryForExePathA)
		return wine32a_NeedCurrentDirectoryForExePathA;
	if (func == pwine_get_unix_file_name)
		return wine32a_wine_get_unix_file_name;
	if (func == pwine_get_dos_file_name)
		return wine32a_wine_get_dos_file_name;
	if (func == pCreateSymbolicLinkW)
		return wine32a_CreateSymbolicLinkW;
	if (func == pCreateSymbolicLinkA)
		return wine32a_CreateSymbolicLinkA;
	if (func == pCreateHardLinkTransactedA)
		return wine32a_CreateHardLinkTransactedA;
	if (func == pCreateHardLinkTransactedW)
		return wine32a_CreateHardLinkTransactedW;
	if (func == pCheckNameLegalDOS8Dot3A)
		return wine32a_CheckNameLegalDOS8Dot3A;
	if (func == pCheckNameLegalDOS8Dot3W)
		return wine32a_CheckNameLegalDOS8Dot3W;
	if (func == pSetSearchPathMode)
		return wine32a_SetSearchPathMode;
	if (func == pGetDevicePowerState)
		return wine32a_GetDevicePowerState;
	if (func == pGetSystemPowerStatus)
		return wine32a_GetSystemPowerStatus;
	if (func == pIsSystemResumeAutomatic)
		return wine32a_IsSystemResumeAutomatic;
	if (func == pRequestWakeupLatency)
		return wine32a_RequestWakeupLatency;
	if (func == pRequestDeviceWakeup)
		return wine32a_RequestDeviceWakeup;
	if (func == pSetSystemPowerState)
		return wine32a_SetSystemPowerState;
	if (func == pSetThreadExecutionState)
		return wine32a_SetThreadExecutionState;
	if (func == pPowerCreateRequest)
		return wine32a_PowerCreateRequest;
	if (func == pPowerSetRequest)
		return wine32a_PowerSetRequest;
	if (func == pPowerClearRequest)
		return wine32a_PowerClearRequest;
	if (func == p__wine_kernel_init)
		return wine32a___wine_kernel_init;
	if (func == pCreateProcessInternalW)
		return wine32a_CreateProcessInternalW;
	if (func == pCreateProcessInternalA)
		return wine32a_CreateProcessInternalA;
	if (func == pCreateProcessA)
		return wine32a_CreateProcessA;
	if (func == pCreateProcessW)
		return wine32a_CreateProcessW;
	if (func == pCreateProcessAsUserA)
		return wine32a_CreateProcessAsUserA;
	if (func == pCreateProcessAsUserW)
		return wine32a_CreateProcessAsUserW;
	if (func == pWinExec)
		return wine32a_WinExec;
	if (func == pLoadModule)
		return wine32a_LoadModule;
	if (func == pExitProcess)
		return wine32a_ExitProcess;
	if (func == pGetExitCodeProcess)
		return wine32a_GetExitCodeProcess;
	if (func == pGetProcessFlags)
		return wine32a_GetProcessFlags;
	if (func == pCloseHandle)
		return wine32a_CloseHandle;
	if (func == pGetHandleInformation)
		return wine32a_GetHandleInformation;
	if (func == pSetHandleInformation)
		return wine32a_SetHandleInformation;
	if (func == pDuplicateHandle)
		return wine32a_DuplicateHandle;
	if (func == pConvertToGlobalHandle)
		return wine32a_ConvertToGlobalHandle;
	if (func == pSetHandleContext)
		return wine32a_SetHandleContext;
	if (func == pGetHandleContext)
		return wine32a_GetHandleContext;
	if (func == pCreateSocketHandle)
		return wine32a_CreateSocketHandle;
	if (func == pSetProcessAffinityMask)
		return wine32a_SetProcessAffinityMask;
	if (func == pGetProcessAffinityMask)
		return wine32a_GetProcessAffinityMask;
	if (func == pGetProcessVersion)
		return wine32a_GetProcessVersion;
	if (func == pSetProcessWorkingSetSize)
		return wine32a_SetProcessWorkingSetSize;
	if (func == pK32EmptyWorkingSet)
		return wine32a_K32EmptyWorkingSet;
	if (func == pGetProcessWorkingSetSize)
		return wine32a_GetProcessWorkingSetSize;
	if (func == pReadProcessMemory)
		return wine32a_ReadProcessMemory;
	if (func == pWriteProcessMemory)
		return wine32a_WriteProcessMemory;
	if (func == pGetProcessIoCounters)
		return wine32a_GetProcessIoCounters;
	if (func == pQueryFullProcessImageNameA)
		return wine32a_QueryFullProcessImageNameA;
	if (func == pQueryFullProcessImageNameW)
		return wine32a_QueryFullProcessImageNameW;
	if (func == pK32GetProcessImageFileNameA)
		return wine32a_K32GetProcessImageFileNameA;
	if (func == pK32GetProcessImageFileNameW)
		return wine32a_K32GetProcessImageFileNameW;
	if (func == pK32EnumProcesses)
		return wine32a_K32EnumProcesses;
	if (func == pK32QueryWorkingSet)
		return wine32a_K32QueryWorkingSet;
	if (func == pK32QueryWorkingSetEx)
		return wine32a_K32QueryWorkingSetEx;
	if (func == pK32GetProcessMemoryInfo)
		return wine32a_K32GetProcessMemoryInfo;
	if (func == pProcessIdToSessionId)
		return wine32a_ProcessIdToSessionId;
	if (func == pRegisterServiceProcess)
		return wine32a_RegisterServiceProcess;
	if (func == pGetLogicalProcessorInformation)
		return wine32a_GetLogicalProcessorInformation;
	if (func == pGetLogicalProcessorInformationEx)
		return wine32a_GetLogicalProcessorInformationEx;
	if (func == pCmdBatNotification)
		return wine32a_CmdBatNotification;
	if (func == pRegisterApplicationRestart)
		return wine32a_RegisterApplicationRestart;
	if (func == pWTSGetActiveConsoleSessionId)
		return wine32a_WTSGetActiveConsoleSessionId;
	if (func == pGetSystemDEPPolicy)
		return wine32a_GetSystemDEPPolicy;
	if (func == pSetProcessDEPPolicy)
		return wine32a_SetProcessDEPPolicy;
	if (func == pApplicationRecoveryFinished)
		return wine32a_ApplicationRecoveryFinished;
	if (func == pApplicationRecoveryInProgress)
		return wine32a_ApplicationRecoveryInProgress;
	if (func == pRegisterApplicationRecoveryCallback)
		return wine32a_RegisterApplicationRecoveryCallback;
	if (func == pGetApplicationRestartSettings)
		return wine32a_GetApplicationRestartSettings;
	if (func == pGetNumaHighestNodeNumber)
		return wine32a_GetNumaHighestNodeNumber;
	if (func == pGetNumaNodeProcessorMask)
		return wine32a_GetNumaNodeProcessorMask;
	if (func == pGetNumaNodeProcessorMaskEx)
		return wine32a_GetNumaNodeProcessorMaskEx;
	if (func == pGetNumaAvailableMemoryNode)
		return wine32a_GetNumaAvailableMemoryNode;
	if (func == pGetNumaAvailableMemoryNodeEx)
		return wine32a_GetNumaAvailableMemoryNodeEx;
	if (func == pGetNumaProcessorNode)
		return wine32a_GetNumaProcessorNode;
	if (func == pGetNumaProcessorNodeEx)
		return wine32a_GetNumaProcessorNodeEx;
	if (func == pGetNumaProximityNode)
		return wine32a_GetNumaProximityNode;
	if (func == pGetNumaProximityNodeEx)
		return wine32a_GetNumaProximityNodeEx;
	if (func == pGetProcessDEPPolicy)
		return wine32a_GetProcessDEPPolicy;
	if (func == pFlushProcessWriteBuffers)
		return wine32a_FlushProcessWriteBuffers;
	if (func == pUnregisterApplicationRestart)
		return wine32a_UnregisterApplicationRestart;
	if (func == pCreateUmsCompletionList)
		return wine32a_CreateUmsCompletionList;
	if (func == pCreateUmsThreadContext)
		return wine32a_CreateUmsThreadContext;
	if (func == pDeleteUmsCompletionList)
		return wine32a_DeleteUmsCompletionList;
	if (func == pDeleteUmsThreadContext)
		return wine32a_DeleteUmsThreadContext;
	if (func == pDequeueUmsCompletionListItems)
		return wine32a_DequeueUmsCompletionListItems;
	if (func == pEnterUmsSchedulingMode)
		return wine32a_EnterUmsSchedulingMode;
	if (func == pExecuteUmsThread)
		return wine32a_ExecuteUmsThread;
	if (func == pGetCurrentUmsThread)
		return wine32a_GetCurrentUmsThread;
	if (func == pGetNextUmsListItem)
		return wine32a_GetNextUmsListItem;
	if (func == pGetUmsCompletionListEvent)
		return wine32a_GetUmsCompletionListEvent;
	if (func == pQueryUmsThreadInformation)
		return wine32a_QueryUmsThreadInformation;
	if (func == pSetUmsThreadInformation)
		return wine32a_SetUmsThreadInformation;
	if (func == pUmsThreadYield)
		return wine32a_UmsThreadYield;
	if (func == pBaseFlushAppcompatCache)
		return wine32a_BaseFlushAppcompatCache;
	if (func == pGetProfileIntA)
		return wine32a_GetProfileIntA;
	if (func == pGetProfileIntW)
		return wine32a_GetProfileIntW;
	if (func == pGetPrivateProfileStringW)
		return wine32a_GetPrivateProfileStringW;
	if (func == pGetPrivateProfileStringA)
		return wine32a_GetPrivateProfileStringA;
	if (func == pGetProfileStringA)
		return wine32a_GetProfileStringA;
	if (func == pGetProfileStringW)
		return wine32a_GetProfileStringW;
	if (func == pWriteProfileStringA)
		return wine32a_WriteProfileStringA;
	if (func == pWriteProfileStringW)
		return wine32a_WriteProfileStringW;
	if (func == pGetPrivateProfileIntW)
		return wine32a_GetPrivateProfileIntW;
	if (func == pGetPrivateProfileIntA)
		return wine32a_GetPrivateProfileIntA;
	if (func == pGetPrivateProfileSectionW)
		return wine32a_GetPrivateProfileSectionW;
	if (func == pGetPrivateProfileSectionA)
		return wine32a_GetPrivateProfileSectionA;
	if (func == pGetProfileSectionA)
		return wine32a_GetProfileSectionA;
	if (func == pGetProfileSectionW)
		return wine32a_GetProfileSectionW;
	if (func == pWritePrivateProfileStringW)
		return wine32a_WritePrivateProfileStringW;
	if (func == pWritePrivateProfileStringA)
		return wine32a_WritePrivateProfileStringA;
	if (func == pWritePrivateProfileSectionW)
		return wine32a_WritePrivateProfileSectionW;
	if (func == pWritePrivateProfileSectionA)
		return wine32a_WritePrivateProfileSectionA;
	if (func == pWriteProfileSectionA)
		return wine32a_WriteProfileSectionA;
	if (func == pWriteProfileSectionW)
		return wine32a_WriteProfileSectionW;
	if (func == pGetPrivateProfileSectionNamesW)
		return wine32a_GetPrivateProfileSectionNamesW;
	if (func == pGetPrivateProfileSectionNamesA)
		return wine32a_GetPrivateProfileSectionNamesA;
	if (func == pGetPrivateProfileStructW)
		return wine32a_GetPrivateProfileStructW;
	if (func == pGetPrivateProfileStructA)
		return wine32a_GetPrivateProfileStructA;
	if (func == pWritePrivateProfileStructW)
		return wine32a_WritePrivateProfileStructW;
	if (func == pWritePrivateProfileStructA)
		return wine32a_WritePrivateProfileStructA;
	if (func == pOpenProfileUserMapping)
		return wine32a_OpenProfileUserMapping;
	if (func == pCloseProfileUserMapping)
		return wine32a_CloseProfileUserMapping;
	if (func == pFindResourceExA)
		return wine32a_FindResourceExA;
	if (func == pFindResourceA)
		return wine32a_FindResourceA;
	if (func == pEnumResourceTypesA)
		return wine32a_EnumResourceTypesA;
	if (func == pEnumResourceTypesW)
		return wine32a_EnumResourceTypesW;
	if (func == pEnumResourceNamesA)
		return wine32a_EnumResourceNamesA;
	if (func == pEnumResourceLanguagesA)
		return wine32a_EnumResourceLanguagesA;
	if (func == pEnumResourceLanguagesW)
		return wine32a_EnumResourceLanguagesW;
	if (func == pBeginUpdateResourceW)
		return wine32a_BeginUpdateResourceW;
	if (func == pBeginUpdateResourceA)
		return wine32a_BeginUpdateResourceA;
	if (func == pEndUpdateResourceW)
		return wine32a_EndUpdateResourceW;
	if (func == pEndUpdateResourceA)
		return wine32a_EndUpdateResourceA;
	if (func == pUpdateResourceW)
		return wine32a_UpdateResourceW;
	if (func == pUpdateResourceA)
		return wine32a_UpdateResourceA;
	if (func == plstrcatA)
		return wine32a_lstrcatA;
	if (func == plstrcatW)
		return wine32a_lstrcatW;
	if (func == plstrcpyA)
		return wine32a_lstrcpyA;
	if (func == plstrcpyW)
		return wine32a_lstrcpyW;
	if (func == pRegisterWaitForSingleObject)
		return wine32a_RegisterWaitForSingleObject;
	if (func == pUnregisterWait)
		return wine32a_UnregisterWait;
	if (func == pMakeCriticalSectionGlobal)
		return wine32a_MakeCriticalSectionGlobal;
	if (func == pReinitializeCriticalSection)
		return wine32a_ReinitializeCriticalSection;
	if (func == pUninitializeCriticalSection)
		return wine32a_UninitializeCriticalSection;
	if (func == pOpenMutexA)
		return wine32a_OpenMutexA;
	if (func == pCreateSemaphoreA)
		return wine32a_CreateSemaphoreA;
	if (func == pCreateSemaphoreExA)
		return wine32a_CreateSemaphoreExA;
	if (func == pOpenSemaphoreA)
		return wine32a_OpenSemaphoreA;
	if (func == pCreateJobObjectW)
		return wine32a_CreateJobObjectW;
	if (func == pCreateJobObjectA)
		return wine32a_CreateJobObjectA;
	if (func == pOpenJobObjectW)
		return wine32a_OpenJobObjectW;
	if (func == pOpenJobObjectA)
		return wine32a_OpenJobObjectA;
	if (func == pTerminateJobObject)
		return wine32a_TerminateJobObject;
	if (func == pQueryInformationJobObject)
		return wine32a_QueryInformationJobObject;
	if (func == pSetInformationJobObject)
		return wine32a_SetInformationJobObject;
	if (func == pAssignProcessToJobObject)
		return wine32a_AssignProcessToJobObject;
	if (func == pIsProcessInJob)
		return wine32a_IsProcessInJob;
	if (func == pCreateWaitableTimerA)
		return wine32a_CreateWaitableTimerA;
	if (func == pCreateWaitableTimerExA)
		return wine32a_CreateWaitableTimerExA;
	if (func == pOpenWaitableTimerA)
		return wine32a_OpenWaitableTimerA;
	if (func == pDeleteTimerQueue)
		return wine32a_DeleteTimerQueue;
	if (func == pCancelTimerQueueTimer)
		return wine32a_CancelTimerQueueTimer;
	if (func == pCreateFileMappingA)
		return wine32a_CreateFileMappingA;
	if (func == pOpenFileMappingA)
		return wine32a_OpenFileMappingA;
	if (func == pCreateNamedPipeA)
		return wine32a_CreateNamedPipeA;
	if (func == pWaitNamedPipeA)
		return wine32a_WaitNamedPipeA;
	if (func == pGetNamedPipeClientProcessId)
		return wine32a_GetNamedPipeClientProcessId;
	if (func == pGetNamedPipeServerProcessId)
		return wine32a_GetNamedPipeServerProcessId;
	if (func == pGetNamedPipeClientSessionId)
		return wine32a_GetNamedPipeClientSessionId;
	if (func == pGetNamedPipeServerSessionId)
		return wine32a_GetNamedPipeServerSessionId;
	if (func == pGetNamedPipeHandleStateA)
		return wine32a_GetNamedPipeHandleStateA;
	if (func == pGetNamedPipeHandleStateW)
		return wine32a_GetNamedPipeHandleStateW;
	if (func == pCallNamedPipeA)
		return wine32a_CallNamedPipeA;
	if (func == pCreatePipe)
		return wine32a_CreatePipe;
	if (func == pCreateMailslotA)
		return wine32a_CreateMailslotA;
	if (func == pCreateMailslotW)
		return wine32a_CreateMailslotW;
	if (func == pGetMailslotInfo)
		return wine32a_GetMailslotInfo;
	if (func == pSetMailslotInfo)
		return wine32a_SetMailslotInfo;
	if (func == pBindIoCompletionCallback)
		return wine32a_BindIoCompletionCallback;
	if (func == pCreateMemoryResourceNotification)
		return wine32a_CreateMemoryResourceNotification;
	if (func == pQueryMemoryResourceNotification)
		return wine32a_QueryMemoryResourceNotification;
	if (func == pInitOnceBeginInitialize)
		return wine32a_InitOnceBeginInitialize;
	if (func == pInitOnceComplete)
		return wine32a_InitOnceComplete;
	if (func == pInitOnceExecuteOnce)
		return wine32a_InitOnceExecuteOnce;
	if (func == pBackupRead)
		return wine32a_BackupRead;
	if (func == pBackupSeek)
		return wine32a_BackupSeek;
	if (func == pBackupWrite)
		return wine32a_BackupWrite;
	if (func == pCreateTapePartition)
		return wine32a_CreateTapePartition;
	if (func == pEraseTape)
		return wine32a_EraseTape;
	if (func == pGetTapeParameters)
		return wine32a_GetTapeParameters;
	if (func == pGetTapePosition)
		return wine32a_GetTapePosition;
	if (func == pGetTapeStatus)
		return wine32a_GetTapeStatus;
	if (func == pPrepareTape)
		return wine32a_PrepareTape;
	if (func == pSetTapeParameters)
		return wine32a_SetTapeParameters;
	if (func == pSetTapePosition)
		return wine32a_SetTapePosition;
	if (func == pWriteTapemark)
		return wine32a_WriteTapemark;
	if (func == pFreeLibraryAndExitThread)
		return wine32a_FreeLibraryAndExitThread;
	if (func == pWow64SetThreadContext)
		return wine32a_Wow64SetThreadContext;
	if (func == pWow64GetThreadContext)
		return wine32a_Wow64GetThreadContext;
	if (func == pSetThreadAffinityMask)
		return wine32a_SetThreadAffinityMask;
	if (func == pGetThreadSelectorEntry)
		return wine32a_GetThreadSelectorEntry;
	if (func == pSetLocalTime)
		return wine32a_SetLocalTime;
	if (func == pGetSystemTimeAdjustment)
		return wine32a_GetSystemTimeAdjustment;
	if (func == pSetSystemTime)
		return wine32a_SetSystemTime;
	if (func == pSetSystemTimeAdjustment)
		return wine32a_SetSystemTimeAdjustment;
	if (func == pGetTimeZoneInformation)
		return wine32a_GetTimeZoneInformation;
	if (func == pGetTimeZoneInformationForYear)
		return wine32a_GetTimeZoneInformationForYear;
	if (func == pSetTimeZoneInformation)
		return wine32a_SetTimeZoneInformation;
	if (func == pSystemTimeToTzSpecificLocalTime)
		return wine32a_SystemTimeToTzSpecificLocalTime;
	if (func == pTzSpecificLocalTimeToSystemTime)
		return wine32a_TzSpecificLocalTimeToSystemTime;
	if (func == pGetSystemTimePreciseAsFileTime)
		return wine32a_GetSystemTimePreciseAsFileTime;
	if (func == pGetProcessTimes)
		return wine32a_GetProcessTimes;
	if (func == pGetCalendarInfoA)
		return wine32a_GetCalendarInfoA;
	if (func == pGetCalendarInfoW)
		return wine32a_GetCalendarInfoW;
	if (func == pGetCalendarInfoEx)
		return wine32a_GetCalendarInfoEx;
	if (func == pSetCalendarInfoA)
		return wine32a_SetCalendarInfoA;
	if (func == pSetCalendarInfoW)
		return wine32a_SetCalendarInfoW;
	if (func == pLocalFileTimeToFileTime)
		return wine32a_LocalFileTimeToFileTime;
	if (func == pFileTimeToLocalFileTime)
		return wine32a_FileTimeToLocalFileTime;
	if (func == pFileTimeToSystemTime)
		return wine32a_FileTimeToSystemTime;
	if (func == pSystemTimeToFileTime)
		return wine32a_SystemTimeToFileTime;
	if (func == pCompareFileTime)
		return wine32a_CompareFileTime;
	if (func == pGetLocalTime)
		return wine32a_GetLocalTime;
	if (func == pGetSystemTime)
		return wine32a_GetSystemTime;
	if (func == pGetDaylightFlag)
		return wine32a_GetDaylightFlag;
	if (func == pDosDateTimeToFileTime)
		return wine32a_DosDateTimeToFileTime;
	if (func == pFileTimeToDosDateTime)
		return wine32a_FileTimeToDosDateTime;
	if (func == pGetSystemTimes)
		return wine32a_GetSystemTimes;
	if (func == pGetDynamicTimeZoneInformation)
		return wine32a_GetDynamicTimeZoneInformation;
	if (func == pGetDynamicTimeZoneInformationEffectiveYears)
		return wine32a_GetDynamicTimeZoneInformationEffectiveYears;
	if (func == pQueryProcessCycleTime)
		return wine32a_QueryProcessCycleTime;
	if (func == pQueryThreadCycleTime)
		return wine32a_QueryThreadCycleTime;
	if (func == pQueryUnbiasedInterruptTime)
		return wine32a_QueryUnbiasedInterruptTime;
	if (func == pGetTickCount64)
		return wine32a_GetTickCount64;
	if (func == pGetTickCount)
		return wine32a_GetTickCount;
	if (func == pCreateToolhelp32Snapshot)
		return wine32a_CreateToolhelp32Snapshot;
	if (func == pThread32First)
		return wine32a_Thread32First;
	if (func == pThread32Next)
		return wine32a_Thread32Next;
	if (func == pProcess32First)
		return wine32a_Process32First;
	if (func == pProcess32Next)
		return wine32a_Process32Next;
	if (func == pProcess32FirstW)
		return wine32a_Process32FirstW;
	if (func == pProcess32NextW)
		return wine32a_Process32NextW;
	if (func == pModule32FirstW)
		return wine32a_Module32FirstW;
	if (func == pModule32NextW)
		return wine32a_Module32NextW;
	if (func == pModule32First)
		return wine32a_Module32First;
	if (func == pModule32Next)
		return wine32a_Module32Next;
	if (func == pHeap32ListFirst)
		return wine32a_Heap32ListFirst;
	if (func == pToolhelp32ReadProcessMemory)
		return wine32a_Toolhelp32ReadProcessMemory;
	if (func == pGetVersion)
		return wine32a_GetVersion;
	if (func == pGetVersionExA)
		return wine32a_GetVersionExA;
	if (func == pGetVersionExW)
		return wine32a_GetVersionExW;
	if (func == pVerifyVersionInfoA)
		return wine32a_VerifyVersionInfoA;
	if (func == pVerifyVersionInfoW)
		return wine32a_VerifyVersionInfoW;
	if (func == pTermsrvAppInstallMode)
		return wine32a_TermsrvAppInstallMode;
	if (func == pSetTermsrvAppInstallMode)
		return wine32a_SetTermsrvAppInstallMode;
	if (func == pGetProductInfo)
		return wine32a_GetProductInfo;
	if (func == pGetCurrentPackageId)
		return wine32a_GetCurrentPackageId;
	if (func == pGetCurrentPackageFamilyName)
		return wine32a_GetCurrentPackageFamilyName;
	if (func == pGetCurrentPackageFullName)
		return wine32a_GetCurrentPackageFullName;
	if (func == pGetPackageFullName)
		return wine32a_GetPackageFullName;
	if (func == pVirtualAlloc)
		return wine32a_VirtualAlloc;
	if (func == pVirtualAllocEx)
		return wine32a_VirtualAllocEx;
	if (func == pVirtualAllocExNuma)
		return wine32a_VirtualAllocExNuma;
	if (func == pVirtualFree)
		return wine32a_VirtualFree;
	if (func == pVirtualFreeEx)
		return wine32a_VirtualFreeEx;
	if (func == pVirtualLock)
		return wine32a_VirtualLock;
	if (func == pVirtualUnlock)
		return wine32a_VirtualUnlock;
	if (func == pVirtualProtect)
		return wine32a_VirtualProtect;
	if (func == pVirtualProtectEx)
		return wine32a_VirtualProtectEx;
	if (func == pVirtualQuery)
		return wine32a_VirtualQuery;
	if (func == pVirtualQueryEx)
		return wine32a_VirtualQueryEx;
	if (func == pMapViewOfFile)
		return wine32a_MapViewOfFile;
	if (func == pMapViewOfFileEx)
		return wine32a_MapViewOfFileEx;
	if (func == pUnmapViewOfFile)
		return wine32a_UnmapViewOfFile;
	if (func == pFlushViewOfFile)
		return wine32a_FlushViewOfFile;
	if (func == pGetWriteWatch)
		return wine32a_GetWriteWatch;
	if (func == pResetWriteWatch)
		return wine32a_ResetWriteWatch;
	if (func == pIsBadReadPtr)
		return wine32a_IsBadReadPtr;
	if (func == pIsBadWritePtr)
		return wine32a_IsBadWritePtr;
	if (func == pIsBadHugeReadPtr)
		return wine32a_IsBadHugeReadPtr;
	if (func == pIsBadHugeWritePtr)
		return wine32a_IsBadHugeWritePtr;
	if (func == pIsBadCodePtr)
		return wine32a_IsBadCodePtr;
	if (func == pIsBadStringPtrA)
		return wine32a_IsBadStringPtrA;
	if (func == pIsBadStringPtrW)
		return wine32a_IsBadStringPtrW;
	if (func == pK32GetMappedFileNameA)
		return wine32a_K32GetMappedFileNameA;
	if (func == pK32GetMappedFileNameW)
		return wine32a_K32GetMappedFileNameW;
	if (func == pK32EnumPageFilesA)
		return wine32a_K32EnumPageFilesA;
	if (func == pK32EnumPageFilesW)
		return wine32a_K32EnumPageFilesW;
	if (func == pK32GetWsChanges)
		return wine32a_K32GetWsChanges;
	if (func == pK32GetWsChangesEx)
		return wine32a_K32GetWsChangesEx;
	if (func == pK32InitializeProcessForWsWatch)
		return wine32a_K32InitializeProcessForWsWatch;
	if (func == pGetVolumeInformationW)
		return wine32a_GetVolumeInformationW;
	if (func == pGetVolumeInformationA)
		return wine32a_GetVolumeInformationA;
	if (func == pSetVolumeLabelW)
		return wine32a_SetVolumeLabelW;
	if (func == pSetVolumeLabelA)
		return wine32a_SetVolumeLabelA;
	if (func == pGetVolumeNameForVolumeMountPointA)
		return wine32a_GetVolumeNameForVolumeMountPointA;
	if (func == pGetVolumeNameForVolumeMountPointW)
		return wine32a_GetVolumeNameForVolumeMountPointW;
	if (func == pDefineDosDeviceW)
		return wine32a_DefineDosDeviceW;
	if (func == pDefineDosDeviceA)
		return wine32a_DefineDosDeviceA;
	if (func == pQueryDosDeviceW)
		return wine32a_QueryDosDeviceW;
	if (func == pQueryDosDeviceA)
		return wine32a_QueryDosDeviceA;
	if (func == pGetLogicalDrives)
		return wine32a_GetLogicalDrives;
	if (func == pGetLogicalDriveStringsA)
		return wine32a_GetLogicalDriveStringsA;
	if (func == pGetLogicalDriveStringsW)
		return wine32a_GetLogicalDriveStringsW;
	if (func == pGetDriveTypeW)
		return wine32a_GetDriveTypeW;
	if (func == pGetDriveTypeA)
		return wine32a_GetDriveTypeA;
	if (func == pGetDiskFreeSpaceExW)
		return wine32a_GetDiskFreeSpaceExW;
	if (func == pGetDiskFreeSpaceExA)
		return wine32a_GetDiskFreeSpaceExA;
	if (func == pGetDiskFreeSpaceW)
		return wine32a_GetDiskFreeSpaceW;
	if (func == pGetDiskFreeSpaceA)
		return wine32a_GetDiskFreeSpaceA;
	if (func == pGetVolumePathNameA)
		return wine32a_GetVolumePathNameA;
	if (func == pGetVolumePathNameW)
		return wine32a_GetVolumePathNameW;
	if (func == pGetVolumePathNamesForVolumeNameA)
		return wine32a_GetVolumePathNamesForVolumeNameA;
	if (func == pGetVolumePathNamesForVolumeNameW)
		return wine32a_GetVolumePathNamesForVolumeNameW;
	if (func == pFindFirstVolumeA)
		return wine32a_FindFirstVolumeA;
	if (func == pFindFirstVolumeW)
		return wine32a_FindFirstVolumeW;
	if (func == pFindNextVolumeA)
		return wine32a_FindNextVolumeA;
	if (func == pFindNextVolumeW)
		return wine32a_FindNextVolumeW;
	if (func == pFindVolumeClose)
		return wine32a_FindVolumeClose;
	if (func == pFindFirstVolumeMountPointA)
		return wine32a_FindFirstVolumeMountPointA;
	if (func == pFindFirstVolumeMountPointW)
		return wine32a_FindFirstVolumeMountPointW;
	if (func == pFindVolumeMountPointClose)
		return wine32a_FindVolumeMountPointClose;
	if (func == pDeleteVolumeMountPointA)
		return wine32a_DeleteVolumeMountPointA;
	if (func == pDeleteVolumeMountPointW)
		return wine32a_DeleteVolumeMountPointW;
	if (func == pSetVolumeMountPointA)
		return wine32a_SetVolumeMountPointA;
	if (func == pSetVolumeMountPointW)
		return wine32a_SetVolumeMountPointW;
	if (func == pGetVolumeInformationByHandleW)
		return wine32a_GetVolumeInformationByHandleW;
	if (func == pWerRegisterFile)
		return wine32a_WerRegisterFile;
	if (func == pWerRegisterRuntimeExceptionModule)
		return wine32a_WerRegisterRuntimeExceptionModule;
	if (func == pWerSetFlags)
		return wine32a_WerSetFlags;
	if (func == pWerRegisterMemoryBlock)
		return wine32a_WerRegisterMemoryBlock;
	if (func == pWerUnregisterMemoryBlock)
		return wine32a_WerUnregisterMemoryBlock;
	if (func == pWerUnregisterRuntimeExceptionModule)
		return wine32a_WerUnregisterRuntimeExceptionModule;

	return NULL;
}
