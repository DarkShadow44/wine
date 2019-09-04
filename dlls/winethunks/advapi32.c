#define WIN32_NO_STATUS
#include "ntstatus.h"
#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

#include "../../include/windef.h"
#include "../../include/winbase.h"
#include "../../include/winnls.h"
#include "../../include/winreg.h"
#include "../../include/winternl.h"
#include "../../include/wincred.h"
#include "../../include/wct.h"
#include "../../include/wine/library.h"
#include "../../include/wine/unicode.h"
#include "../../include/wine/debug.h"
#include "../../dlls/advapi32/advapi32_misc.h"
#include "../../dlls/advapi32/crypt.h"
#include "../../include/ntstatus.h"
#include "../../include/rpc.h"
#include "../../include/wmistr.h"
#include "../../include/evntrace.h"
#include "../../include/evntprov.h"
#include "../../include/wine/list.h"
#include "../../include/winsafer.h"
#include "../../include/winioctl.h"
#include "../../include/accctrl.h"
#include "../../include/sddl.h"
#include "../../include/winsvc.h"
#include "../../include/aclapi.h"
#include "../../include/objbase.h"
#include "../../include/lmcons.h"
#include "../../include/lmserver.h"
#include "../../include/wine/exception.h"
#include "../../include/wmium.h"

static WINAPI BOOL (*pGetUserNameA)(LPSTR lpszName, LPDWORD lpSize);
static WINAPI BOOL (*pGetUserNameW)(LPWSTR lpszName, LPDWORD lpSize);
static WINAPI BOOL (*pGetCurrentHwProfileA)(LPHW_PROFILE_INFOA pInfo);
static WINAPI BOOL (*pGetCurrentHwProfileW)(LPHW_PROFILE_INFOW pInfo);
static WINAPI BOOL (*pIsTextUnicode)(LPCVOID buf, INT len, LPINT flags);
static WINAPI BOOL (*pAbortSystemShutdownA)(LPSTR lpMachineName);
static WINAPI BOOL (*pAbortSystemShutdownW)(LPWSTR lpMachineName);
static WINAPI BOOL (*pInitiateSystemShutdownExA)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownExW)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownA)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
static WINAPI BOOL (*pInitiateSystemShutdownW)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
static WINAPI DWORD (*pInitiateShutdownA)(char * name, char * message, DWORD seconds, DWORD flags, DWORD reason);
static WINAPI DWORD (*pInitiateShutdownW)(WCHAR * name, WCHAR * message, DWORD seconds, DWORD flags, DWORD reason);
static WINAPI BOOL (*pLogonUserA)(LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken);
static WINAPI BOOL (*pLogonUserW)(LPCWSTR lpszUsername, LPCWSTR lpszDomain, LPCWSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken);
static WINAPI DWORD (*pCommandLineFromMsiDescriptor)(WCHAR * szDescriptor, WCHAR * szCommandLine, DWORD * pcchCommandLine);
static WINAPI void (*pRegisterWaitChainCOMCallback)(PCOGETCALLSTATE call_state_cb, PCOGETACTIVATIONSTATE activation_state_cb);

extern WINAPI BOOL wine32b_GetUserNameA(LPSTR lpszName, LPDWORD lpSize)
{
	TRACE("Enter GetUserNameA\n");
	return pGetUserNameA(lpszName, lpSize);
}

extern WINAPI void wine32a_GetUserNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetUserNameW(LPWSTR lpszName, LPDWORD lpSize)
{
	TRACE("Enter GetUserNameW\n");
	return pGetUserNameW(lpszName, lpSize);
}

extern WINAPI void wine32a_GetUserNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetUserNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetUserNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCurrentHwProfileA(LPHW_PROFILE_INFOA pInfo)
{
	TRACE("Enter GetCurrentHwProfileA\n");
	return pGetCurrentHwProfileA(pInfo);
}

extern WINAPI void wine32a_GetCurrentHwProfileA(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentHwProfileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentHwProfileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetCurrentHwProfileW(LPHW_PROFILE_INFOW pInfo)
{
	TRACE("Enter GetCurrentHwProfileW\n");
	return pGetCurrentHwProfileW(pInfo);
}

extern WINAPI void wine32a_GetCurrentHwProfileW(void);
__ASM_GLOBAL_FUNC(wine32a_GetCurrentHwProfileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetCurrentHwProfileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_IsTextUnicode(LPCVOID buf, INT len, LPINT flags)
{
	TRACE("Enter IsTextUnicode\n");
	return pIsTextUnicode(buf, len, flags);
}

extern WINAPI void wine32a_IsTextUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_IsTextUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_IsTextUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AbortSystemShutdownA(LPSTR lpMachineName)
{
	TRACE("Enter AbortSystemShutdownA\n");
	return pAbortSystemShutdownA(lpMachineName);
}

extern WINAPI void wine32a_AbortSystemShutdownA(void);
__ASM_GLOBAL_FUNC(wine32a_AbortSystemShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AbortSystemShutdownA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_AbortSystemShutdownW(LPWSTR lpMachineName)
{
	TRACE("Enter AbortSystemShutdownW\n");
	return pAbortSystemShutdownW(lpMachineName);
}

extern WINAPI void wine32a_AbortSystemShutdownW(void);
__ASM_GLOBAL_FUNC(wine32a_AbortSystemShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AbortSystemShutdownW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_InitiateSystemShutdownExA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason)
{
	TRACE("Enter InitiateSystemShutdownExA\n");
	return pInitiateSystemShutdownExA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
}

extern WINAPI void wine32a_InitiateSystemShutdownExA(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateSystemShutdownExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateSystemShutdownExA") "\n"
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

extern WINAPI BOOL wine32b_InitiateSystemShutdownExW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason)
{
	TRACE("Enter InitiateSystemShutdownExW\n");
	return pInitiateSystemShutdownExW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
}

extern WINAPI void wine32a_InitiateSystemShutdownExW(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateSystemShutdownExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateSystemShutdownExW") "\n"
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

extern WINAPI BOOL wine32b_InitiateSystemShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown)
{
	TRACE("Enter InitiateSystemShutdownA\n");
	return pInitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
}

extern WINAPI void wine32a_InitiateSystemShutdownA(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateSystemShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateSystemShutdownA") "\n"
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

extern WINAPI BOOL wine32b_InitiateSystemShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown)
{
	TRACE("Enter InitiateSystemShutdownW\n");
	return pInitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
}

extern WINAPI void wine32a_InitiateSystemShutdownW(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateSystemShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateSystemShutdownW") "\n"
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

extern WINAPI DWORD wine32b_InitiateShutdownA(char * name, char * message, DWORD seconds, DWORD flags, DWORD reason)
{
	TRACE("Enter InitiateShutdownA\n");
	return pInitiateShutdownA(name, message, seconds, flags, reason);
}

extern WINAPI void wine32a_InitiateShutdownA(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateShutdownA") "\n"
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

extern WINAPI DWORD wine32b_InitiateShutdownW(WCHAR * name, WCHAR * message, DWORD seconds, DWORD flags, DWORD reason)
{
	TRACE("Enter InitiateShutdownW\n");
	return pInitiateShutdownW(name, message, seconds, flags, reason);
}

extern WINAPI void wine32a_InitiateShutdownW(void);
__ASM_GLOBAL_FUNC(wine32a_InitiateShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_InitiateShutdownW") "\n"
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

extern WINAPI BOOL wine32b_LogonUserA(LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken)
{
	TRACE("Enter LogonUserA\n");
	return pLogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
}

extern WINAPI void wine32a_LogonUserA(void);
__ASM_GLOBAL_FUNC(wine32a_LogonUserA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LogonUserA") "\n"
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

extern WINAPI BOOL wine32b_LogonUserW(LPCWSTR lpszUsername, LPCWSTR lpszDomain, LPCWSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken)
{
	TRACE("Enter LogonUserW\n");
	return pLogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
}

extern WINAPI void wine32a_LogonUserW(void);
__ASM_GLOBAL_FUNC(wine32a_LogonUserW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LogonUserW") "\n"
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

extern WINAPI DWORD wine32b_CommandLineFromMsiDescriptor(WCHAR * szDescriptor, WCHAR * szCommandLine, DWORD * pcchCommandLine)
{
	TRACE("Enter CommandLineFromMsiDescriptor\n");
	return pCommandLineFromMsiDescriptor(szDescriptor, szCommandLine, pcchCommandLine);
}

extern WINAPI void wine32a_CommandLineFromMsiDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_CommandLineFromMsiDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CommandLineFromMsiDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RegisterWaitChainCOMCallback(PCOGETCALLSTATE call_state_cb, PCOGETACTIVATIONSTATE activation_state_cb)
{
	TRACE("Enter RegisterWaitChainCOMCallback\n");
	return pRegisterWaitChainCOMCallback(call_state_cb, activation_state_cb);
}

extern WINAPI void wine32a_RegisterWaitChainCOMCallback(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterWaitChainCOMCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterWaitChainCOMCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOL (*pCredDeleteA)(LPCSTR TargetName, DWORD Type, DWORD Flags);
static WINAPI BOOL (*pCredDeleteW)(LPCWSTR TargetName, DWORD Type, DWORD Flags);
static WINAPI BOOL (*pCredEnumerateA)(LPCSTR Filter, DWORD Flags, DWORD * Count, PCREDENTIALA ** Credentials);
static WINAPI BOOL (*pCredEnumerateW)(LPCWSTR Filter, DWORD Flags, DWORD * Count, PCREDENTIALW ** Credentials);
static WINAPI void (*pCredFree)(PVOID Buffer);
static WINAPI BOOL (*pCredReadA)(LPCSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALA * Credential);
static WINAPI BOOL (*pCredReadW)(LPCWSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALW * Credential);
static WINAPI BOOL (*pCredReadDomainCredentialsA)(PCREDENTIAL_TARGET_INFORMATIONA TargetInformation, DWORD Flags, DWORD * Size, PCREDENTIALA ** Credentials);
static WINAPI BOOL (*pCredReadDomainCredentialsW)(PCREDENTIAL_TARGET_INFORMATIONW TargetInformation, DWORD Flags, DWORD * Size, PCREDENTIALW ** Credentials);
static WINAPI BOOL (*pCredWriteA)(PCREDENTIALA Credential, DWORD Flags);
static WINAPI BOOL (*pCredWriteW)(PCREDENTIALW Credential, DWORD Flags);
static WINAPI BOOL (*pCredGetSessionTypes)(DWORD persistCount, LPDWORD persists);
static WINAPI BOOL (*pCredMarshalCredentialA)(CRED_MARSHAL_TYPE type, PVOID cred, LPSTR * out);
static WINAPI BOOL (*pCredMarshalCredentialW)(CRED_MARSHAL_TYPE type, PVOID cred, LPWSTR * out);
static WINAPI BOOL (*pCredUnmarshalCredentialA)(LPCSTR cred, PCRED_MARSHAL_TYPE type, PVOID * out);
static WINAPI BOOL (*pCredUnmarshalCredentialW)(LPCWSTR cred, PCRED_MARSHAL_TYPE type, PVOID * out);
static WINAPI BOOL (*pCredIsMarshaledCredentialW)(LPCWSTR name);
static WINAPI BOOL (*pCredIsMarshaledCredentialA)(LPCSTR name);

extern WINAPI BOOL wine32b_CredDeleteA(LPCSTR TargetName, DWORD Type, DWORD Flags)
{
	TRACE("Enter CredDeleteA\n");
	return pCredDeleteA(TargetName, Type, Flags);
}

extern WINAPI void wine32a_CredDeleteA(void);
__ASM_GLOBAL_FUNC(wine32a_CredDeleteA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredDeleteA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredDeleteW(LPCWSTR TargetName, DWORD Type, DWORD Flags)
{
	TRACE("Enter CredDeleteW\n");
	return pCredDeleteW(TargetName, Type, Flags);
}

extern WINAPI void wine32a_CredDeleteW(void);
__ASM_GLOBAL_FUNC(wine32a_CredDeleteW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredDeleteW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredEnumerateA(LPCSTR Filter, DWORD Flags, DWORD * Count, PCREDENTIALA ** Credentials)
{
	TRACE("Enter CredEnumerateA\n");
	return pCredEnumerateA(Filter, Flags, Count, Credentials);
}

extern WINAPI void wine32a_CredEnumerateA(void);
__ASM_GLOBAL_FUNC(wine32a_CredEnumerateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredEnumerateA") "\n"
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

extern WINAPI BOOL wine32b_CredEnumerateW(LPCWSTR Filter, DWORD Flags, DWORD * Count, PCREDENTIALW ** Credentials)
{
	TRACE("Enter CredEnumerateW\n");
	return pCredEnumerateW(Filter, Flags, Count, Credentials);
}

extern WINAPI void wine32a_CredEnumerateW(void);
__ASM_GLOBAL_FUNC(wine32a_CredEnumerateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredEnumerateW") "\n"
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

extern WINAPI void wine32b_CredFree(PVOID Buffer)
{
	TRACE("Enter CredFree\n");
	return pCredFree(Buffer);
}

extern WINAPI void wine32a_CredFree(void);
__ASM_GLOBAL_FUNC(wine32a_CredFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredReadA(LPCSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALA * Credential)
{
	TRACE("Enter CredReadA\n");
	return pCredReadA(TargetName, Type, Flags, Credential);
}

extern WINAPI void wine32a_CredReadA(void);
__ASM_GLOBAL_FUNC(wine32a_CredReadA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredReadA") "\n"
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

extern WINAPI BOOL wine32b_CredReadW(LPCWSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALW * Credential)
{
	TRACE("Enter CredReadW\n");
	return pCredReadW(TargetName, Type, Flags, Credential);
}

extern WINAPI void wine32a_CredReadW(void);
__ASM_GLOBAL_FUNC(wine32a_CredReadW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredReadW") "\n"
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

extern WINAPI BOOL wine32b_CredReadDomainCredentialsA(PCREDENTIAL_TARGET_INFORMATIONA TargetInformation, DWORD Flags, DWORD * Size, PCREDENTIALA ** Credentials)
{
	TRACE("Enter CredReadDomainCredentialsA\n");
	return pCredReadDomainCredentialsA(TargetInformation, Flags, Size, Credentials);
}

extern WINAPI void wine32a_CredReadDomainCredentialsA(void);
__ASM_GLOBAL_FUNC(wine32a_CredReadDomainCredentialsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredReadDomainCredentialsA") "\n"
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

extern WINAPI BOOL wine32b_CredReadDomainCredentialsW(PCREDENTIAL_TARGET_INFORMATIONW TargetInformation, DWORD Flags, DWORD * Size, PCREDENTIALW ** Credentials)
{
	TRACE("Enter CredReadDomainCredentialsW\n");
	return pCredReadDomainCredentialsW(TargetInformation, Flags, Size, Credentials);
}

extern WINAPI void wine32a_CredReadDomainCredentialsW(void);
__ASM_GLOBAL_FUNC(wine32a_CredReadDomainCredentialsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredReadDomainCredentialsW") "\n"
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

extern WINAPI BOOL wine32b_CredWriteA(PCREDENTIALA Credential, DWORD Flags)
{
	TRACE("Enter CredWriteA\n");
	return pCredWriteA(Credential, Flags);
}

extern WINAPI void wine32a_CredWriteA(void);
__ASM_GLOBAL_FUNC(wine32a_CredWriteA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredWriteA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredWriteW(PCREDENTIALW Credential, DWORD Flags)
{
	TRACE("Enter CredWriteW\n");
	return pCredWriteW(Credential, Flags);
}

extern WINAPI void wine32a_CredWriteW(void);
__ASM_GLOBAL_FUNC(wine32a_CredWriteW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredWriteW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredGetSessionTypes(DWORD persistCount, LPDWORD persists)
{
	TRACE("Enter CredGetSessionTypes\n");
	return pCredGetSessionTypes(persistCount, persists);
}

extern WINAPI void wine32a_CredGetSessionTypes(void);
__ASM_GLOBAL_FUNC(wine32a_CredGetSessionTypes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredGetSessionTypes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredMarshalCredentialA(CRED_MARSHAL_TYPE type, PVOID cred, LPSTR * out)
{
	TRACE("Enter CredMarshalCredentialA\n");
	return pCredMarshalCredentialA(type, cred, out);
}

extern WINAPI void wine32a_CredMarshalCredentialA(void);
__ASM_GLOBAL_FUNC(wine32a_CredMarshalCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredMarshalCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredMarshalCredentialW(CRED_MARSHAL_TYPE type, PVOID cred, LPWSTR * out)
{
	TRACE("Enter CredMarshalCredentialW\n");
	return pCredMarshalCredentialW(type, cred, out);
}

extern WINAPI void wine32a_CredMarshalCredentialW(void);
__ASM_GLOBAL_FUNC(wine32a_CredMarshalCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredMarshalCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredUnmarshalCredentialA(LPCSTR cred, PCRED_MARSHAL_TYPE type, PVOID * out)
{
	TRACE("Enter CredUnmarshalCredentialA\n");
	return pCredUnmarshalCredentialA(cred, type, out);
}

extern WINAPI void wine32a_CredUnmarshalCredentialA(void);
__ASM_GLOBAL_FUNC(wine32a_CredUnmarshalCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredUnmarshalCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredUnmarshalCredentialW(LPCWSTR cred, PCRED_MARSHAL_TYPE type, PVOID * out)
{
	TRACE("Enter CredUnmarshalCredentialW\n");
	return pCredUnmarshalCredentialW(cred, type, out);
}

extern WINAPI void wine32a_CredUnmarshalCredentialW(void);
__ASM_GLOBAL_FUNC(wine32a_CredUnmarshalCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredUnmarshalCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredIsMarshaledCredentialW(LPCWSTR name)
{
	TRACE("Enter CredIsMarshaledCredentialW\n");
	return pCredIsMarshaledCredentialW(name);
}

extern WINAPI void wine32a_CredIsMarshaledCredentialW(void);
__ASM_GLOBAL_FUNC(wine32a_CredIsMarshaledCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredIsMarshaledCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CredIsMarshaledCredentialA(LPCSTR name)
{
	TRACE("Enter CredIsMarshaledCredentialA\n");
	return pCredIsMarshaledCredentialA(name);
}

extern WINAPI void wine32a_CredIsMarshaledCredentialA(void);
__ASM_GLOBAL_FUNC(wine32a_CredIsMarshaledCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CredIsMarshaledCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*pCloseEncryptedFileRaw)(PVOID context);
static WINAPI BOOL (*pCryptAcquireContextW)(HCRYPTPROV * phProv, LPCWSTR pszContainer, LPCWSTR pszProvider, DWORD dwProvType, DWORD dwFlags);
static WINAPI BOOL (*pCryptAcquireContextA)(HCRYPTPROV * phProv, LPCSTR pszContainer, LPCSTR pszProvider, DWORD dwProvType, DWORD dwFlags);
static WINAPI BOOL (*pCryptContextAddRef)(HCRYPTPROV hProv, DWORD * pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptReleaseContext)(HCRYPTPROV hProv, ULONG_PTR dwFlags);
static WINAPI BOOL (*pCryptGenRandom)(HCRYPTPROV hProv, DWORD dwLen, BYTE * pbBuffer);
static WINAPI BOOL (*pCryptCreateHash)(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH * phHash);
static WINAPI BOOL (*pCryptDecrypt)(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen);
static WINAPI BOOL (*pCryptDeriveKey)(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY * phKey);
static WINAPI BOOL (*pCryptDestroyHash)(HCRYPTHASH hHash);
static WINAPI BOOL (*pCryptDestroyKey)(HCRYPTKEY hKey);
static WINAPI BOOL (*pCryptDuplicateHash)(HCRYPTHASH hHash, DWORD * pdwReserved, DWORD dwFlags, HCRYPTHASH * phHash);
static WINAPI BOOL (*pCryptDuplicateKey)(HCRYPTKEY hKey, DWORD * pdwReserved, DWORD dwFlags, HCRYPTKEY * phKey);
static WINAPI BOOL (*pCryptEncrypt)(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen, DWORD dwBufLen);
static WINAPI BOOL (*pCryptEnumProvidersW)(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPWSTR pszProvName, DWORD * pcbProvName);
static WINAPI BOOL (*pCryptEnumProvidersA)(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPSTR pszProvName, DWORD * pcbProvName);
static WINAPI BOOL (*pCryptEnumProviderTypesW)(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPWSTR pszTypeName, DWORD * pcbTypeName);
static WINAPI BOOL (*pCryptEnumProviderTypesA)(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPSTR pszTypeName, DWORD * pcbTypeName);
static WINAPI BOOL (*pCryptExportKey)(HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen);
static WINAPI BOOL (*pCryptGenKey)(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY * phKey);
static WINAPI BOOL (*pCryptGetDefaultProviderW)(DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD * pcbProvName);
static WINAPI BOOL (*pCryptGetDefaultProviderA)(DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags, LPSTR pszProvName, DWORD * pcbProvName);
static WINAPI BOOL (*pCryptGetHashParam)(HCRYPTHASH hHash, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetKeyParam)(HCRYPTKEY hKey, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetProvParam)(HCRYPTPROV hProv, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetUserKey)(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY * phUserKey);
static WINAPI BOOL (*pCryptHashData)(HCRYPTHASH hHash, const BYTE * pbData, DWORD dwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptHashSessionKey)(HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags);
static WINAPI BOOL (*pCryptImportKey)(HCRYPTPROV hProv, const BYTE * pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY * phKey);
static WINAPI BOOL (*pCryptSignHashW)(HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE * pbSignature, DWORD * pdwSigLen);
static WINAPI BOOL (*pCryptSignHashA)(HCRYPTHASH hHash, DWORD dwKeySpec, LPCSTR sDescription, DWORD dwFlags, BYTE * pbSignature, DWORD * pdwSigLen);
static WINAPI BOOL (*pCryptSetHashParam)(HCRYPTHASH hHash, DWORD dwParam, const BYTE * pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetKeyParam)(HCRYPTKEY hKey, DWORD dwParam, const BYTE * pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProviderA)(LPCSTR pszProvName, DWORD dwProvType);
static WINAPI BOOL (*pCryptSetProviderW)(LPCWSTR pszProvName, DWORD dwProvType);
static WINAPI BOOL (*pCryptSetProviderExW)(LPCWSTR pszProvName, DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProviderExA)(LPCSTR pszProvName, DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProvParam)(HCRYPTPROV hProv, DWORD dwParam, const BYTE * pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptVerifySignatureW)(HCRYPTHASH hHash, const BYTE * pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags);
static WINAPI BOOL (*pCryptVerifySignatureA)(HCRYPTHASH hHash, const BYTE * pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR sDescription, DWORD dwFlags);
static WINAPI DWORD (*pOpenEncryptedFileRawA)(LPCSTR filename, ULONG flags, PVOID * context);
static WINAPI DWORD (*pOpenEncryptedFileRawW)(LPCWSTR filename, ULONG flags, PVOID * context);
static WINAPI DWORD (*pReadEncryptedFileRaw)(PFE_EXPORT_FUNC export, PVOID callback, PVOID context);
static WINAPI NTSTATUS (*pSystemFunction007)(const UNICODE_STRING * string, LPBYTE hash);
static WINAPI NTSTATUS (*pSystemFunction010)(LPVOID unknown, const BYTE * data, LPBYTE hash);
static WINAPI BOOL (*pSystemFunction030)(LPCVOID b1, LPCVOID b2);
static WINAPI BOOL (*pSystemFunction035)(LPCSTR lpszDllFilePath);
static WINAPI BOOLEAN (*pSystemFunction036)(PVOID pbBuffer, ULONG dwLen);
static WINAPI NTSTATUS (*pSystemFunction040)(PVOID memory, ULONG length, ULONG flags);
static WINAPI NTSTATUS (*pSystemFunction041)(PVOID memory, ULONG length, ULONG flags);
static WINAPI DWORD (*pWriteEncryptedFileRaw)(PFE_IMPORT_FUNC import, PVOID callback, PVOID context);

extern WINAPI void wine32b_CloseEncryptedFileRaw(PVOID context)
{
	TRACE("Enter CloseEncryptedFileRaw\n");
	return pCloseEncryptedFileRaw(context);
}

extern WINAPI void wine32a_CloseEncryptedFileRaw(void);
__ASM_GLOBAL_FUNC(wine32a_CloseEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptAcquireContextW(HCRYPTPROV * phProv, LPCWSTR pszContainer, LPCWSTR pszProvider, DWORD dwProvType, DWORD dwFlags)
{
	TRACE("Enter CryptAcquireContextW\n");
	return pCryptAcquireContextW(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}

extern WINAPI void wine32a_CryptAcquireContextW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptAcquireContextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptAcquireContextW") "\n"
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

extern WINAPI BOOL wine32b_CryptAcquireContextA(HCRYPTPROV * phProv, LPCSTR pszContainer, LPCSTR pszProvider, DWORD dwProvType, DWORD dwFlags)
{
	TRACE("Enter CryptAcquireContextA\n");
	return pCryptAcquireContextA(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}

extern WINAPI void wine32a_CryptAcquireContextA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptAcquireContextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptAcquireContextA") "\n"
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

extern WINAPI BOOL wine32b_CryptContextAddRef(HCRYPTPROV hProv, DWORD * pdwReserved, DWORD dwFlags)
{
	TRACE("Enter CryptContextAddRef\n");
	return pCryptContextAddRef(hProv, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_CryptContextAddRef(void);
__ASM_GLOBAL_FUNC(wine32a_CryptContextAddRef,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptContextAddRef") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptReleaseContext(HCRYPTPROV hProv, ULONG_PTR dwFlags)
{
	TRACE("Enter CryptReleaseContext\n");
	return pCryptReleaseContext(hProv, dwFlags);
}

extern WINAPI void wine32a_CryptReleaseContext(void);
__ASM_GLOBAL_FUNC(wine32a_CryptReleaseContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptReleaseContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptGenRandom(HCRYPTPROV hProv, DWORD dwLen, BYTE * pbBuffer)
{
	TRACE("Enter CryptGenRandom\n");
	return pCryptGenRandom(hProv, dwLen, pbBuffer);
}

extern WINAPI void wine32a_CryptGenRandom(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGenRandom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGenRandom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptCreateHash(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH * phHash)
{
	TRACE("Enter CryptCreateHash\n");
	return pCryptCreateHash(hProv, Algid, hKey, dwFlags, phHash);
}

extern WINAPI void wine32a_CryptCreateHash(void);
__ASM_GLOBAL_FUNC(wine32a_CryptCreateHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptCreateHash") "\n"
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

extern WINAPI BOOL wine32b_CryptDecrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen)
{
	TRACE("Enter CryptDecrypt\n");
	return pCryptDecrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen);
}

extern WINAPI void wine32a_CryptDecrypt(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDecrypt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDecrypt") "\n"
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

extern WINAPI BOOL wine32b_CryptDeriveKey(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY * phKey)
{
	TRACE("Enter CryptDeriveKey\n");
	return pCryptDeriveKey(hProv, Algid, hBaseData, dwFlags, phKey);
}

extern WINAPI void wine32a_CryptDeriveKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDeriveKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDeriveKey") "\n"
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

extern WINAPI BOOL wine32b_CryptDestroyHash(HCRYPTHASH hHash)
{
	TRACE("Enter CryptDestroyHash\n");
	return pCryptDestroyHash(hHash);
}

extern WINAPI void wine32a_CryptDestroyHash(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDestroyHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDestroyHash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptDestroyKey(HCRYPTKEY hKey)
{
	TRACE("Enter CryptDestroyKey\n");
	return pCryptDestroyKey(hKey);
}

extern WINAPI void wine32a_CryptDestroyKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDestroyKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDestroyKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptDuplicateHash(HCRYPTHASH hHash, DWORD * pdwReserved, DWORD dwFlags, HCRYPTHASH * phHash)
{
	TRACE("Enter CryptDuplicateHash\n");
	return pCryptDuplicateHash(hHash, pdwReserved, dwFlags, phHash);
}

extern WINAPI void wine32a_CryptDuplicateHash(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDuplicateHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDuplicateHash") "\n"
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

extern WINAPI BOOL wine32b_CryptDuplicateKey(HCRYPTKEY hKey, DWORD * pdwReserved, DWORD dwFlags, HCRYPTKEY * phKey)
{
	TRACE("Enter CryptDuplicateKey\n");
	return pCryptDuplicateKey(hKey, pdwReserved, dwFlags, phKey);
}

extern WINAPI void wine32a_CryptDuplicateKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptDuplicateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptDuplicateKey") "\n"
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

extern WINAPI BOOL wine32b_CryptEncrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen, DWORD dwBufLen)
{
	TRACE("Enter CryptEncrypt\n");
	return pCryptEncrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen);
}

extern WINAPI void wine32a_CryptEncrypt(void);
__ASM_GLOBAL_FUNC(wine32a_CryptEncrypt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptEncrypt") "\n"
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

extern WINAPI BOOL wine32b_CryptEnumProvidersW(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPWSTR pszProvName, DWORD * pcbProvName)
{
	TRACE("Enter CryptEnumProvidersW\n");
	return pCryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_CryptEnumProvidersW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptEnumProvidersW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptEnumProvidersW") "\n"
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

extern WINAPI BOOL wine32b_CryptEnumProvidersA(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPSTR pszProvName, DWORD * pcbProvName)
{
	TRACE("Enter CryptEnumProvidersA\n");
	return pCryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_CryptEnumProvidersA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptEnumProvidersA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptEnumProvidersA") "\n"
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

extern WINAPI BOOL wine32b_CryptEnumProviderTypesW(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPWSTR pszTypeName, DWORD * pcbTypeName)
{
	TRACE("Enter CryptEnumProviderTypesW\n");
	return pCryptEnumProviderTypesW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
}

extern WINAPI void wine32a_CryptEnumProviderTypesW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptEnumProviderTypesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptEnumProviderTypesW") "\n"
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

extern WINAPI BOOL wine32b_CryptEnumProviderTypesA(DWORD dwIndex, DWORD * pdwReserved, DWORD dwFlags, DWORD * pdwProvType, LPSTR pszTypeName, DWORD * pcbTypeName)
{
	TRACE("Enter CryptEnumProviderTypesA\n");
	return pCryptEnumProviderTypesA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
}

extern WINAPI void wine32a_CryptEnumProviderTypesA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptEnumProviderTypesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptEnumProviderTypesA") "\n"
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

extern WINAPI BOOL wine32b_CryptExportKey(HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE * pbData, DWORD * pdwDataLen)
{
	TRACE("Enter CryptExportKey\n");
	return pCryptExportKey(hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen);
}

extern WINAPI void wine32a_CryptExportKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptExportKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptExportKey") "\n"
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

extern WINAPI BOOL wine32b_CryptGenKey(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY * phKey)
{
	TRACE("Enter CryptGenKey\n");
	return pCryptGenKey(hProv, Algid, dwFlags, phKey);
}

extern WINAPI void wine32a_CryptGenKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGenKey") "\n"
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

extern WINAPI BOOL wine32b_CryptGetDefaultProviderW(DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD * pcbProvName)
{
	TRACE("Enter CryptGetDefaultProviderW\n");
	return pCryptGetDefaultProviderW(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_CryptGetDefaultProviderW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetDefaultProviderW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetDefaultProviderW") "\n"
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

extern WINAPI BOOL wine32b_CryptGetDefaultProviderA(DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags, LPSTR pszProvName, DWORD * pcbProvName)
{
	TRACE("Enter CryptGetDefaultProviderA\n");
	return pCryptGetDefaultProviderA(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_CryptGetDefaultProviderA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetDefaultProviderA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetDefaultProviderA") "\n"
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

extern WINAPI BOOL wine32b_CryptGetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags)
{
	TRACE("Enter CryptGetHashParam\n");
	return pCryptGetHashParam(hHash, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_CryptGetHashParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetHashParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetHashParam") "\n"
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

extern WINAPI BOOL wine32b_CryptGetKeyParam(HCRYPTKEY hKey, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags)
{
	TRACE("Enter CryptGetKeyParam\n");
	return pCryptGetKeyParam(hKey, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_CryptGetKeyParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetKeyParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetKeyParam") "\n"
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

extern WINAPI BOOL wine32b_CryptGetProvParam(HCRYPTPROV hProv, DWORD dwParam, BYTE * pbData, DWORD * pdwDataLen, DWORD dwFlags)
{
	TRACE("Enter CryptGetProvParam\n");
	return pCryptGetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_CryptGetProvParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetProvParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetProvParam") "\n"
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

extern WINAPI BOOL wine32b_CryptGetUserKey(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY * phUserKey)
{
	TRACE("Enter CryptGetUserKey\n");
	return pCryptGetUserKey(hProv, dwKeySpec, phUserKey);
}

extern WINAPI void wine32a_CryptGetUserKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptGetUserKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptGetUserKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptHashData(HCRYPTHASH hHash, const BYTE * pbData, DWORD dwDataLen, DWORD dwFlags)
{
	TRACE("Enter CryptHashData\n");
	return pCryptHashData(hHash, pbData, dwDataLen, dwFlags);
}

extern WINAPI void wine32a_CryptHashData(void);
__ASM_GLOBAL_FUNC(wine32a_CryptHashData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptHashData") "\n"
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

extern WINAPI BOOL wine32b_CryptHashSessionKey(HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags)
{
	TRACE("Enter CryptHashSessionKey\n");
	return pCryptHashSessionKey(hHash, hKey, dwFlags);
}

extern WINAPI void wine32a_CryptHashSessionKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptHashSessionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptHashSessionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptImportKey(HCRYPTPROV hProv, const BYTE * pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY * phKey)
{
	TRACE("Enter CryptImportKey\n");
	return pCryptImportKey(hProv, pbData, dwDataLen, hPubKey, dwFlags, phKey);
}

extern WINAPI void wine32a_CryptImportKey(void);
__ASM_GLOBAL_FUNC(wine32a_CryptImportKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptImportKey") "\n"
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

extern WINAPI BOOL wine32b_CryptSignHashW(HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE * pbSignature, DWORD * pdwSigLen)
{
	TRACE("Enter CryptSignHashW\n");
	return pCryptSignHashW(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
}

extern WINAPI void wine32a_CryptSignHashW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSignHashW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSignHashW") "\n"
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

extern WINAPI BOOL wine32b_CryptSignHashA(HCRYPTHASH hHash, DWORD dwKeySpec, LPCSTR sDescription, DWORD dwFlags, BYTE * pbSignature, DWORD * pdwSigLen)
{
	TRACE("Enter CryptSignHashA\n");
	return pCryptSignHashA(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
}

extern WINAPI void wine32a_CryptSignHashA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSignHashA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSignHashA") "\n"
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

extern WINAPI BOOL wine32b_CryptSetHashParam(HCRYPTHASH hHash, DWORD dwParam, const BYTE * pbData, DWORD dwFlags)
{
	TRACE("Enter CryptSetHashParam\n");
	return pCryptSetHashParam(hHash, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_CryptSetHashParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetHashParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetHashParam") "\n"
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

extern WINAPI BOOL wine32b_CryptSetKeyParam(HCRYPTKEY hKey, DWORD dwParam, const BYTE * pbData, DWORD dwFlags)
{
	TRACE("Enter CryptSetKeyParam\n");
	return pCryptSetKeyParam(hKey, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_CryptSetKeyParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetKeyParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetKeyParam") "\n"
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

extern WINAPI BOOL wine32b_CryptSetProviderA(LPCSTR pszProvName, DWORD dwProvType)
{
	TRACE("Enter CryptSetProviderA\n");
	return pCryptSetProviderA(pszProvName, dwProvType);
}

extern WINAPI void wine32a_CryptSetProviderA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetProviderA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetProviderA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptSetProviderW(LPCWSTR pszProvName, DWORD dwProvType)
{
	TRACE("Enter CryptSetProviderW\n");
	return pCryptSetProviderW(pszProvName, dwProvType);
}

extern WINAPI void wine32a_CryptSetProviderW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetProviderW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetProviderW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CryptSetProviderExW(LPCWSTR pszProvName, DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags)
{
	TRACE("Enter CryptSetProviderExW\n");
	return pCryptSetProviderExW(pszProvName, dwProvType, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_CryptSetProviderExW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetProviderExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetProviderExW") "\n"
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

extern WINAPI BOOL wine32b_CryptSetProviderExA(LPCSTR pszProvName, DWORD dwProvType, DWORD * pdwReserved, DWORD dwFlags)
{
	TRACE("Enter CryptSetProviderExA\n");
	return pCryptSetProviderExA(pszProvName, dwProvType, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_CryptSetProviderExA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetProviderExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetProviderExA") "\n"
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

extern WINAPI BOOL wine32b_CryptSetProvParam(HCRYPTPROV hProv, DWORD dwParam, const BYTE * pbData, DWORD dwFlags)
{
	TRACE("Enter CryptSetProvParam\n");
	return pCryptSetProvParam(hProv, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_CryptSetProvParam(void);
__ASM_GLOBAL_FUNC(wine32a_CryptSetProvParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptSetProvParam") "\n"
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

extern WINAPI BOOL wine32b_CryptVerifySignatureW(HCRYPTHASH hHash, const BYTE * pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags)
{
	TRACE("Enter CryptVerifySignatureW\n");
	return pCryptVerifySignatureW(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
}

extern WINAPI void wine32a_CryptVerifySignatureW(void);
__ASM_GLOBAL_FUNC(wine32a_CryptVerifySignatureW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptVerifySignatureW") "\n"
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

extern WINAPI BOOL wine32b_CryptVerifySignatureA(HCRYPTHASH hHash, const BYTE * pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR sDescription, DWORD dwFlags)
{
	TRACE("Enter CryptVerifySignatureA\n");
	return pCryptVerifySignatureA(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
}

extern WINAPI void wine32a_CryptVerifySignatureA(void);
__ASM_GLOBAL_FUNC(wine32a_CryptVerifySignatureA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CryptVerifySignatureA") "\n"
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

extern WINAPI DWORD wine32b_OpenEncryptedFileRawA(LPCSTR filename, ULONG flags, PVOID * context)
{
	TRACE("Enter OpenEncryptedFileRawA\n");
	return pOpenEncryptedFileRawA(filename, flags, context);
}

extern WINAPI void wine32a_OpenEncryptedFileRawA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenEncryptedFileRawA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenEncryptedFileRawA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_OpenEncryptedFileRawW(LPCWSTR filename, ULONG flags, PVOID * context)
{
	TRACE("Enter OpenEncryptedFileRawW\n");
	return pOpenEncryptedFileRawW(filename, flags, context);
}

extern WINAPI void wine32a_OpenEncryptedFileRawW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenEncryptedFileRawW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenEncryptedFileRawW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_ReadEncryptedFileRaw(PFE_EXPORT_FUNC export, PVOID callback, PVOID context)
{
	TRACE("Enter ReadEncryptedFileRaw\n");
	return pReadEncryptedFileRaw(export, callback, context);
}

extern WINAPI void wine32a_ReadEncryptedFileRaw(void);
__ASM_GLOBAL_FUNC(wine32a_ReadEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction007(const UNICODE_STRING * string, LPBYTE hash)
{
	TRACE("Enter SystemFunction007\n");
	return pSystemFunction007(string, hash);
}

extern WINAPI void wine32a_SystemFunction007(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction007,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction007") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction010(LPVOID unknown, const BYTE * data, LPBYTE hash)
{
	TRACE("Enter SystemFunction010\n");
	return pSystemFunction010(unknown, data, hash);
}

extern WINAPI void wine32a_SystemFunction010(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction010,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction010") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SystemFunction030(LPCVOID b1, LPCVOID b2)
{
	TRACE("Enter SystemFunction030\n");
	return pSystemFunction030(b1, b2);
}

extern WINAPI void wine32a_SystemFunction030(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction030,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction030") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SystemFunction035(LPCSTR lpszDllFilePath)
{
	TRACE("Enter SystemFunction035\n");
	return pSystemFunction035(lpszDllFilePath);
}

extern WINAPI void wine32a_SystemFunction035(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction035,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction035") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_SystemFunction036(PVOID pbBuffer, ULONG dwLen)
{
	TRACE("Enter SystemFunction036\n");
	return pSystemFunction036(pbBuffer, dwLen);
}

extern WINAPI void wine32a_SystemFunction036(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction036,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction036") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction040(PVOID memory, ULONG length, ULONG flags)
{
	TRACE("Enter SystemFunction040\n");
	return pSystemFunction040(memory, length, flags);
}

extern WINAPI void wine32a_SystemFunction040(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction040,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction040") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction041(PVOID memory, ULONG length, ULONG flags)
{
	TRACE("Enter SystemFunction041\n");
	return pSystemFunction041(memory, length, flags);
}

extern WINAPI void wine32a_SystemFunction041(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction041,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction041") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_WriteEncryptedFileRaw(PFE_IMPORT_FUNC import, PVOID callback, PVOID context)
{
	TRACE("Enter WriteEncryptedFileRaw\n");
	return pWriteEncryptedFileRaw(import, callback, context);
}

extern WINAPI void wine32a_WriteEncryptedFileRaw(void);
__ASM_GLOBAL_FUNC(wine32a_WriteEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WriteEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pSystemFunction032)(struct ustring * data, const struct ustring * key);

extern WINAPI NTSTATUS wine32b_SystemFunction032(struct ustring * data, const struct ustring * key)
{
	TRACE("Enter SystemFunction032\n");
	return pSystemFunction032(data, key);
}

extern WINAPI void wine32a_SystemFunction032(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction032,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction032") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)


static WINAPI NTSTATUS (*pSystemFunction006)(LPCSTR password, LPSTR hash);
static WINAPI NTSTATUS (*pSystemFunction008)(const BYTE * challenge, const BYTE * hash, LPBYTE response);
static WINAPI NTSTATUS (*pSystemFunction009)(const BYTE * challenge, const BYTE * hash, LPBYTE response);
static WINAPI NTSTATUS (*pSystemFunction001)(const BYTE * data, const BYTE * key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction002)(const BYTE * data, const BYTE * key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction003)(const BYTE * key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction004)(const struct ustring * in, const struct ustring * key, struct ustring * out);
static WINAPI NTSTATUS (*pSystemFunction005)(const struct ustring * in, const struct ustring * key, struct ustring * out);
static WINAPI NTSTATUS (*pSystemFunction012)(const BYTE * in, const BYTE * key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction013)(const BYTE * in, const BYTE * key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction024)(const BYTE * in, const BYTE * key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction025)(const BYTE * in, const BYTE * key, LPBYTE out);

extern WINAPI NTSTATUS wine32b_SystemFunction006(LPCSTR password, LPSTR hash)
{
	TRACE("Enter SystemFunction006\n");
	return pSystemFunction006(password, hash);
}

extern WINAPI void wine32a_SystemFunction006(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction006,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction006") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction008(const BYTE * challenge, const BYTE * hash, LPBYTE response)
{
	TRACE("Enter SystemFunction008\n");
	return pSystemFunction008(challenge, hash, response);
}

extern WINAPI void wine32a_SystemFunction008(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction008,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction008") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction009(const BYTE * challenge, const BYTE * hash, LPBYTE response)
{
	TRACE("Enter SystemFunction009\n");
	return pSystemFunction009(challenge, hash, response);
}

extern WINAPI void wine32a_SystemFunction009(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction009,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction009") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction001(const BYTE * data, const BYTE * key, LPBYTE output)
{
	TRACE("Enter SystemFunction001\n");
	return pSystemFunction001(data, key, output);
}

extern WINAPI void wine32a_SystemFunction001(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction001,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction001") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction002(const BYTE * data, const BYTE * key, LPBYTE output)
{
	TRACE("Enter SystemFunction002\n");
	return pSystemFunction002(data, key, output);
}

extern WINAPI void wine32a_SystemFunction002(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction002,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction002") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction003(const BYTE * key, LPBYTE output)
{
	TRACE("Enter SystemFunction003\n");
	return pSystemFunction003(key, output);
}

extern WINAPI void wine32a_SystemFunction003(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction003,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction003") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction004(const struct ustring * in, const struct ustring * key, struct ustring * out)
{
	TRACE("Enter SystemFunction004\n");
	return pSystemFunction004(in, key, out);
}

extern WINAPI void wine32a_SystemFunction004(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction004,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction004") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction005(const struct ustring * in, const struct ustring * key, struct ustring * out)
{
	TRACE("Enter SystemFunction005\n");
	return pSystemFunction005(in, key, out);
}

extern WINAPI void wine32a_SystemFunction005(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction005,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction005") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction012(const BYTE * in, const BYTE * key, LPBYTE out)
{
	TRACE("Enter SystemFunction012\n");
	return pSystemFunction012(in, key, out);
}

extern WINAPI void wine32a_SystemFunction012(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction012,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction012") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction013(const BYTE * in, const BYTE * key, LPBYTE out)
{
	TRACE("Enter SystemFunction013\n");
	return pSystemFunction013(in, key, out);
}

extern WINAPI void wine32a_SystemFunction013(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction013,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction013") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction024(const BYTE * in, const BYTE * key, LPBYTE out)
{
	TRACE("Enter SystemFunction024\n");
	return pSystemFunction024(in, key, out);
}

extern WINAPI void wine32a_SystemFunction024(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction024,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction024") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_SystemFunction025(const BYTE * in, const BYTE * key, LPBYTE out)
{
	TRACE("Enter SystemFunction025\n");
	return pSystemFunction025(in, key, out);
}

extern WINAPI void wine32a_SystemFunction025(void);
__ASM_GLOBAL_FUNC(wine32a_SystemFunction025,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SystemFunction025") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOL (*pBackupEventLogA)(HANDLE hEventLog, LPCSTR lpBackupFileName);
static WINAPI BOOL (*pBackupEventLogW)(HANDLE hEventLog, LPCWSTR lpBackupFileName);
static WINAPI BOOL (*pClearEventLogA)(HANDLE hEventLog, LPCSTR lpBackupFileName);
static WINAPI BOOL (*pClearEventLogW)(HANDLE hEventLog, LPCWSTR lpBackupFileName);
static WINAPI BOOL (*pCloseEventLog)(HANDLE hEventLog);
static WINAPI ULONG (*pControlTraceW)(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control);
static WINAPI ULONG (*pControlTraceA)(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control);
static WINAPI ULONG (*pFlushTraceA)(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pFlushTraceW)(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI BOOL (*pDeregisterEventSource)(HANDLE hEventLog);
static WINAPI ULONG (*pEnableTraceEx)(LPCGUID provider, LPCGUID source, TRACEHANDLE hSession, ULONG enable, UCHAR level, ULONGLONG anykeyword, ULONGLONG allkeyword, ULONG enableprop, PEVENT_FILTER_DESCRIPTOR filterdesc);
static WINAPI ULONG (*pEnableTraceEx2)(TRACEHANDLE handle, LPCGUID provider, ULONG control, UCHAR level, ULONGLONG match_any, ULONGLONG match_all, ULONG timeout, PENABLE_TRACE_PARAMETERS params);
static WINAPI ULONG (*pEnableTrace)(ULONG enable, ULONG flag, ULONG level, LPCGUID guid, TRACEHANDLE hSession);
static WINAPI BOOL (*pGetEventLogInformation)(HANDLE hEventLog, DWORD dwInfoLevel, LPVOID lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
static WINAPI BOOL (*pGetNumberOfEventLogRecords)(HANDLE hEventLog, PDWORD NumberOfRecords);
static WINAPI BOOL (*pGetOldestEventLogRecord)(HANDLE hEventLog, PDWORD OldestRecord);
static WINAPI BOOL (*pNotifyChangeEventLog)(HANDLE hEventLog, HANDLE hEvent);
static WINAPI HANDLE (*pOpenBackupEventLogA)(LPCSTR lpUNCServerName, LPCSTR lpFileName);
static WINAPI HANDLE (*pOpenBackupEventLogW)(LPCWSTR lpUNCServerName, LPCWSTR lpFileName);
static WINAPI HANDLE (*pOpenEventLogA)(LPCSTR uncname, LPCSTR source);
static WINAPI HANDLE (*pOpenEventLogW)(LPCWSTR uncname, LPCWSTR source);
static WINAPI ULONG (*pQueryAllTracesW)(PEVENT_TRACE_PROPERTIES * parray, ULONG arraycount, PULONG psessioncount);
static WINAPI ULONG (*pQueryAllTracesA)(PEVENT_TRACE_PROPERTIES * parray, ULONG arraycount, PULONG psessioncount);
static WINAPI BOOL (*pReadEventLogA)(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD * pnBytesRead, DWORD * pnMinNumberOfBytesNeeded);
static WINAPI BOOL (*pReadEventLogW)(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD * pnBytesRead, DWORD * pnMinNumberOfBytesNeeded);
static WINAPI HANDLE (*pRegisterEventSourceA)(LPCSTR lpUNCServerName, LPCSTR lpSourceName);
static WINAPI HANDLE (*pRegisterEventSourceW)(LPCWSTR lpUNCServerName, LPCWSTR lpSourceName);
static WINAPI BOOL (*pReportEventA)(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCSTR * lpStrings, LPVOID lpRawData);
static WINAPI BOOL (*pReportEventW)(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCWSTR * lpStrings, LPVOID lpRawData);
static WINAPI ULONG (*pStartTraceW)(PTRACEHANDLE pSessionHandle, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pStartTraceA)(PTRACEHANDLE pSessionHandle, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pStopTraceW)(TRACEHANDLE session, LPCWSTR session_name, PEVENT_TRACE_PROPERTIES properties);
static WINAPI ULONG (*pStopTraceA)(TRACEHANDLE session, LPCSTR session_name, PEVENT_TRACE_PROPERTIES properties);
static WINAPI ULONG (*pQueryTraceW)(TRACEHANDLE handle, LPCWSTR sessionname, PEVENT_TRACE_PROPERTIES properties);
static WINAPI TRACEHANDLE (*pOpenTraceA)(PEVENT_TRACE_LOGFILEA logfile);
static WINAPI TRACEHANDLE (*pOpenTraceW)(PEVENT_TRACE_LOGFILEW logfile);
static WINAPI ULONG (*pProcessTrace)(PTRACEHANDLE HandleArray, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime);
static WINAPI ULONG (*pCloseTrace)(TRACEHANDLE handle);
static WINAPI ULONG (*pEnumerateTraceGuids)(PTRACE_GUID_PROPERTIES * propertiesarray, ULONG arraycount, PULONG guidcount);
static WINAPI ULONG (*pTraceSetInformation)(TRACEHANDLE handle, TRACE_INFO_CLASS infoclass, void * info, ULONG len);

extern WINAPI BOOL wine32b_BackupEventLogA(HANDLE hEventLog, LPCSTR lpBackupFileName)
{
	TRACE("Enter BackupEventLogA\n");
	return pBackupEventLogA(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_BackupEventLogA(void);
__ASM_GLOBAL_FUNC(wine32a_BackupEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BackupEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_BackupEventLogW(HANDLE hEventLog, LPCWSTR lpBackupFileName)
{
	TRACE("Enter BackupEventLogW\n");
	return pBackupEventLogW(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_BackupEventLogW(void);
__ASM_GLOBAL_FUNC(wine32a_BackupEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BackupEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ClearEventLogA(HANDLE hEventLog, LPCSTR lpBackupFileName)
{
	TRACE("Enter ClearEventLogA\n");
	return pClearEventLogA(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_ClearEventLogA(void);
__ASM_GLOBAL_FUNC(wine32a_ClearEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClearEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ClearEventLogW(HANDLE hEventLog, LPCWSTR lpBackupFileName)
{
	TRACE("Enter ClearEventLogW\n");
	return pClearEventLogW(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_ClearEventLogW(void);
__ASM_GLOBAL_FUNC(wine32a_ClearEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ClearEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CloseEventLog(HANDLE hEventLog)
{
	TRACE("Enter CloseEventLog\n");
	return pCloseEventLog(hEventLog);
}

extern WINAPI void wine32a_CloseEventLog(void);
__ASM_GLOBAL_FUNC(wine32a_CloseEventLog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseEventLog") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_ControlTraceW(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control)
{
	TRACE("Enter ControlTraceW\n");
	return pControlTraceW(hSession, SessionName, Properties, control);
}

extern WINAPI void wine32a_ControlTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_ControlTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ControlTraceW") "\n"
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

extern WINAPI ULONG wine32b_ControlTraceA(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control)
{
	TRACE("Enter ControlTraceA\n");
	return pControlTraceA(hSession, SessionName, Properties, control);
}

extern WINAPI void wine32a_ControlTraceA(void);
__ASM_GLOBAL_FUNC(wine32a_ControlTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ControlTraceA") "\n"
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

extern WINAPI ULONG wine32b_FlushTraceA(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties)
{
	TRACE("Enter FlushTraceA\n");
	return pFlushTraceA(hSession, SessionName, Properties);
}

extern WINAPI void wine32a_FlushTraceA(void);
__ASM_GLOBAL_FUNC(wine32a_FlushTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlushTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_FlushTraceW(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties)
{
	TRACE("Enter FlushTraceW\n");
	return pFlushTraceW(hSession, SessionName, Properties);
}

extern WINAPI void wine32a_FlushTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_FlushTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FlushTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DeregisterEventSource(HANDLE hEventLog)
{
	TRACE("Enter DeregisterEventSource\n");
	return pDeregisterEventSource(hEventLog);
}

extern WINAPI void wine32a_DeregisterEventSource(void);
__ASM_GLOBAL_FUNC(wine32a_DeregisterEventSource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DeregisterEventSource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EnableTraceEx(LPCGUID provider, LPCGUID source, TRACEHANDLE hSession, ULONG enable, UCHAR level, ULONGLONG anykeyword, ULONGLONG allkeyword, ULONG enableprop, PEVENT_FILTER_DESCRIPTOR filterdesc)
{
	TRACE("Enter EnableTraceEx\n");
	return pEnableTraceEx(provider, source, hSession, enable, level, anykeyword, allkeyword, enableprop, filterdesc);
}

extern WINAPI void wine32a_EnableTraceEx(void);
__ASM_GLOBAL_FUNC(wine32a_EnableTraceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableTraceEx") "\n"
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

extern WINAPI ULONG wine32b_EnableTraceEx2(TRACEHANDLE handle, LPCGUID provider, ULONG control, UCHAR level, ULONGLONG match_any, ULONGLONG match_all, ULONG timeout, PENABLE_TRACE_PARAMETERS params)
{
	TRACE("Enter EnableTraceEx2\n");
	return pEnableTraceEx2(handle, provider, control, level, match_any, match_all, timeout, params);
}

extern WINAPI void wine32a_EnableTraceEx2(void);
__ASM_GLOBAL_FUNC(wine32a_EnableTraceEx2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableTraceEx2") "\n"
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

extern WINAPI ULONG wine32b_EnableTrace(ULONG enable, ULONG flag, ULONG level, LPCGUID guid, TRACEHANDLE hSession)
{
	TRACE("Enter EnableTrace\n");
	return pEnableTrace(enable, flag, level, guid, hSession);
}

extern WINAPI void wine32a_EnableTrace(void);
__ASM_GLOBAL_FUNC(wine32a_EnableTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnableTrace") "\n"
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

extern WINAPI BOOL wine32b_GetEventLogInformation(HANDLE hEventLog, DWORD dwInfoLevel, LPVOID lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded)
{
	TRACE("Enter GetEventLogInformation\n");
	return pGetEventLogInformation(hEventLog, dwInfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded);
}

extern WINAPI void wine32a_GetEventLogInformation(void);
__ASM_GLOBAL_FUNC(wine32a_GetEventLogInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEventLogInformation") "\n"
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

extern WINAPI BOOL wine32b_GetNumberOfEventLogRecords(HANDLE hEventLog, PDWORD NumberOfRecords)
{
	TRACE("Enter GetNumberOfEventLogRecords\n");
	return pGetNumberOfEventLogRecords(hEventLog, NumberOfRecords);
}

extern WINAPI void wine32a_GetNumberOfEventLogRecords(void);
__ASM_GLOBAL_FUNC(wine32a_GetNumberOfEventLogRecords,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNumberOfEventLogRecords") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_GetOldestEventLogRecord(HANDLE hEventLog, PDWORD OldestRecord)
{
	TRACE("Enter GetOldestEventLogRecord\n");
	return pGetOldestEventLogRecord(hEventLog, OldestRecord);
}

extern WINAPI void wine32a_GetOldestEventLogRecord(void);
__ASM_GLOBAL_FUNC(wine32a_GetOldestEventLogRecord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetOldestEventLogRecord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_NotifyChangeEventLog(HANDLE hEventLog, HANDLE hEvent)
{
	TRACE("Enter NotifyChangeEventLog\n");
	return pNotifyChangeEventLog(hEventLog, hEvent);
}

extern WINAPI void wine32a_NotifyChangeEventLog(void);
__ASM_GLOBAL_FUNC(wine32a_NotifyChangeEventLog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NotifyChangeEventLog") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenBackupEventLogA(LPCSTR lpUNCServerName, LPCSTR lpFileName)
{
	TRACE("Enter OpenBackupEventLogA\n");
	return pOpenBackupEventLogA(lpUNCServerName, lpFileName);
}

extern WINAPI void wine32a_OpenBackupEventLogA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenBackupEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenBackupEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenBackupEventLogW(LPCWSTR lpUNCServerName, LPCWSTR lpFileName)
{
	TRACE("Enter OpenBackupEventLogW\n");
	return pOpenBackupEventLogW(lpUNCServerName, lpFileName);
}

extern WINAPI void wine32a_OpenBackupEventLogW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenBackupEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenBackupEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenEventLogA(LPCSTR uncname, LPCSTR source)
{
	TRACE("Enter OpenEventLogA\n");
	return pOpenEventLogA(uncname, source);
}

extern WINAPI void wine32a_OpenEventLogA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_OpenEventLogW(LPCWSTR uncname, LPCWSTR source)
{
	TRACE("Enter OpenEventLogW\n");
	return pOpenEventLogW(uncname, source);
}

extern WINAPI void wine32a_OpenEventLogW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_QueryAllTracesW(PEVENT_TRACE_PROPERTIES * parray, ULONG arraycount, PULONG psessioncount)
{
	TRACE("Enter QueryAllTracesW\n");
	return pQueryAllTracesW(parray, arraycount, psessioncount);
}

extern WINAPI void wine32a_QueryAllTracesW(void);
__ASM_GLOBAL_FUNC(wine32a_QueryAllTracesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryAllTracesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_QueryAllTracesA(PEVENT_TRACE_PROPERTIES * parray, ULONG arraycount, PULONG psessioncount)
{
	TRACE("Enter QueryAllTracesA\n");
	return pQueryAllTracesA(parray, arraycount, psessioncount);
}

extern WINAPI void wine32a_QueryAllTracesA(void);
__ASM_GLOBAL_FUNC(wine32a_QueryAllTracesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryAllTracesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ReadEventLogA(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD * pnBytesRead, DWORD * pnMinNumberOfBytesNeeded)
{
	TRACE("Enter ReadEventLogA\n");
	return pReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
}

extern WINAPI void wine32a_ReadEventLogA(void);
__ASM_GLOBAL_FUNC(wine32a_ReadEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadEventLogA") "\n"
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

extern WINAPI BOOL wine32b_ReadEventLogW(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD * pnBytesRead, DWORD * pnMinNumberOfBytesNeeded)
{
	TRACE("Enter ReadEventLogW\n");
	return pReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
}

extern WINAPI void wine32a_ReadEventLogW(void);
__ASM_GLOBAL_FUNC(wine32a_ReadEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReadEventLogW") "\n"
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

extern WINAPI HANDLE wine32b_RegisterEventSourceA(LPCSTR lpUNCServerName, LPCSTR lpSourceName)
{
	TRACE("Enter RegisterEventSourceA\n");
	return pRegisterEventSourceA(lpUNCServerName, lpSourceName);
}

extern WINAPI void wine32a_RegisterEventSourceA(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterEventSourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterEventSourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_RegisterEventSourceW(LPCWSTR lpUNCServerName, LPCWSTR lpSourceName)
{
	TRACE("Enter RegisterEventSourceW\n");
	return pRegisterEventSourceW(lpUNCServerName, lpSourceName);
}

extern WINAPI void wine32a_RegisterEventSourceW(void);
__ASM_GLOBAL_FUNC(wine32a_RegisterEventSourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegisterEventSourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ReportEventA(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCSTR * lpStrings, LPVOID lpRawData)
{
	TRACE("Enter ReportEventA\n");
	return pReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
}

extern WINAPI void wine32a_ReportEventA(void);
__ASM_GLOBAL_FUNC(wine32a_ReportEventA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReportEventA") "\n"
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

extern WINAPI BOOL wine32b_ReportEventW(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCWSTR * lpStrings, LPVOID lpRawData)
{
	TRACE("Enter ReportEventW\n");
	return pReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
}

extern WINAPI void wine32a_ReportEventW(void);
__ASM_GLOBAL_FUNC(wine32a_ReportEventW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ReportEventW") "\n"
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

extern WINAPI ULONG wine32b_StartTraceW(PTRACEHANDLE pSessionHandle, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties)
{
	TRACE("Enter StartTraceW\n");
	return pStartTraceW(pSessionHandle, SessionName, Properties);
}

extern WINAPI void wine32a_StartTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_StartTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_StartTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_StartTraceA(PTRACEHANDLE pSessionHandle, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties)
{
	TRACE("Enter StartTraceA\n");
	return pStartTraceA(pSessionHandle, SessionName, Properties);
}

extern WINAPI void wine32a_StartTraceA(void);
__ASM_GLOBAL_FUNC(wine32a_StartTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_StartTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_StopTraceW(TRACEHANDLE session, LPCWSTR session_name, PEVENT_TRACE_PROPERTIES properties)
{
	TRACE("Enter StopTraceW\n");
	return pStopTraceW(session, session_name, properties);
}

extern WINAPI void wine32a_StopTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_StopTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_StopTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_StopTraceA(TRACEHANDLE session, LPCSTR session_name, PEVENT_TRACE_PROPERTIES properties)
{
	TRACE("Enter StopTraceA\n");
	return pStopTraceA(session, session_name, properties);
}

extern WINAPI void wine32a_StopTraceA(void);
__ASM_GLOBAL_FUNC(wine32a_StopTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_StopTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_QueryTraceW(TRACEHANDLE handle, LPCWSTR sessionname, PEVENT_TRACE_PROPERTIES properties)
{
	TRACE("Enter QueryTraceW\n");
	return pQueryTraceW(handle, sessionname, properties);
}

extern WINAPI void wine32a_QueryTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_QueryTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRACEHANDLE wine32b_OpenTraceA(PEVENT_TRACE_LOGFILEA logfile)
{
	TRACE("Enter OpenTraceA\n");
	return pOpenTraceA(logfile);
}

extern WINAPI void wine32a_OpenTraceA(void);
__ASM_GLOBAL_FUNC(wine32a_OpenTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRACEHANDLE wine32b_OpenTraceW(PEVENT_TRACE_LOGFILEW logfile)
{
	TRACE("Enter OpenTraceW\n");
	return pOpenTraceW(logfile);
}

extern WINAPI void wine32a_OpenTraceW(void);
__ASM_GLOBAL_FUNC(wine32a_OpenTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_OpenTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_ProcessTrace(PTRACEHANDLE HandleArray, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime)
{
	TRACE("Enter ProcessTrace\n");
	return pProcessTrace(HandleArray, HandleCount, StartTime, EndTime);
}

extern WINAPI void wine32a_ProcessTrace(void);
__ASM_GLOBAL_FUNC(wine32a_ProcessTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ProcessTrace") "\n"
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

extern WINAPI ULONG wine32b_CloseTrace(TRACEHANDLE handle)
{
	TRACE("Enter CloseTrace\n");
	return pCloseTrace(handle);
}

extern WINAPI void wine32a_CloseTrace(void);
__ASM_GLOBAL_FUNC(wine32a_CloseTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CloseTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EnumerateTraceGuids(PTRACE_GUID_PROPERTIES * propertiesarray, ULONG arraycount, PULONG guidcount)
{
	TRACE("Enter EnumerateTraceGuids\n");
	return pEnumerateTraceGuids(propertiesarray, arraycount, guidcount);
}

extern WINAPI void wine32a_EnumerateTraceGuids(void);
__ASM_GLOBAL_FUNC(wine32a_EnumerateTraceGuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EnumerateTraceGuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_TraceSetInformation(TRACEHANDLE handle, TRACE_INFO_CLASS infoclass, void * info, ULONG len)
{
	TRACE("Enter TraceSetInformation\n");
	return pTraceSetInformation(handle, infoclass, info, len);
}

extern WINAPI void wine32a_TraceSetInformation(void);
__ASM_GLOBAL_FUNC(wine32a_TraceSetInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TraceSetInformation") "\n"
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

static WINAPI NTSTATUS (*pLsaAddAccountRights)(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING rights, ULONG count);
static WINAPI NTSTATUS (*pLsaClose)(LSA_HANDLE ObjectHandle);
static WINAPI NTSTATUS (*pLsaCreateTrustedDomainEx)(LSA_HANDLE policy, PTRUSTED_DOMAIN_INFORMATION_EX domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION auth_info, ACCESS_MASK access, PLSA_HANDLE domain);
static WINAPI NTSTATUS (*pLsaDeleteTrustedDomain)(LSA_HANDLE policy, PSID sid);
static WINAPI NTSTATUS (*pLsaEnumerateAccountRights)(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING * rights, PULONG count);
static WINAPI NTSTATUS (*pLsaEnumerateAccountsWithUserRight)(LSA_HANDLE policy, PLSA_UNICODE_STRING rights, PVOID * buffer, PULONG count);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomains)(LSA_HANDLE PolicyHandle, PLSA_ENUMERATION_HANDLE EnumerationContext, PVOID * Buffer, ULONG PreferredMaximumLength, PULONG CountReturned);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomainsEx)(LSA_HANDLE policy, PLSA_ENUMERATION_HANDLE context, PVOID * buffer, ULONG length, PULONG count);
static WINAPI NTSTATUS (*pLsaFreeMemory)(PVOID Buffer);
static WINAPI NTSTATUS (*pLsaLookupNames)(LSA_HANDLE PolicyHandle, ULONG Count, PLSA_UNICODE_STRING Names, PLSA_REFERENCED_DOMAIN_LIST * ReferencedDomains, PLSA_TRANSLATED_SID * Sids);
static WINAPI NTSTATUS (*pLsaLookupNames2)(LSA_HANDLE policy, ULONG flags, ULONG count, PLSA_UNICODE_STRING names, PLSA_REFERENCED_DOMAIN_LIST * domains, PLSA_TRANSLATED_SID2 * sids);
static WINAPI NTSTATUS (*pLsaLookupSids)(LSA_HANDLE PolicyHandle, ULONG Count, PSID * Sids, LSA_REFERENCED_DOMAIN_LIST ** ReferencedDomains, LSA_TRANSLATED_NAME ** Names);
static WINAPI ULONG (*pLsaNtStatusToWinError)(NTSTATUS Status);
static WINAPI NTSTATUS (*pLsaOpenPolicy)(PLSA_UNICODE_STRING SystemName, PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle);
static WINAPI NTSTATUS (*pLsaOpenTrustedDomainByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, ACCESS_MASK access, PLSA_HANDLE handle);
static WINAPI NTSTATUS (*pLsaQueryInformationPolicy)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID * Buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfo)(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID * buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfoByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID * buffer);
static WINAPI NTSTATUS (*pLsaRegisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event);
static WINAPI NTSTATUS (*pLsaRemoveAccountRights)(LSA_HANDLE policy, PSID sid, BOOLEAN all, PLSA_UNICODE_STRING rights, ULONG count);
static WINAPI NTSTATUS (*pLsaRetrievePrivateData)(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING * PrivateData);
static WINAPI NTSTATUS (*pLsaSetInformationPolicy)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID Buffer);
static WINAPI NTSTATUS (*pLsaSetSecret)(LSA_HANDLE SecretHandle, PLSA_UNICODE_STRING EncryptedCurrentValue, PLSA_UNICODE_STRING EncryptedOldValue);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInfoByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID buffer);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInformation)(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID buffer);
static WINAPI NTSTATUS (*pLsaStorePrivateData)(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING PrivateData);
static WINAPI NTSTATUS (*pLsaUnregisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeName)(LSA_HANDLE handle, LUID * luid, LSA_UNICODE_STRING ** name);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeDisplayName)(LSA_HANDLE handle, LSA_UNICODE_STRING * name, LSA_UNICODE_STRING ** display_name, SHORT * language);
static WINAPI BOOLEAN (*pAuditQuerySystemPolicy)(const GUID * guids, ULONG count, AUDIT_POLICY_INFORMATION ** policy);

extern WINAPI NTSTATUS wine32b_LsaAddAccountRights(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING rights, ULONG count)
{
	TRACE("Enter LsaAddAccountRights\n");
	return pLsaAddAccountRights(policy, sid, rights, count);
}

extern WINAPI void wine32a_LsaAddAccountRights(void);
__ASM_GLOBAL_FUNC(wine32a_LsaAddAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaAddAccountRights") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaClose(LSA_HANDLE ObjectHandle)
{
	TRACE("Enter LsaClose\n");
	return pLsaClose(ObjectHandle);
}

extern WINAPI void wine32a_LsaClose(void);
__ASM_GLOBAL_FUNC(wine32a_LsaClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaCreateTrustedDomainEx(LSA_HANDLE policy, PTRUSTED_DOMAIN_INFORMATION_EX domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION auth_info, ACCESS_MASK access, PLSA_HANDLE domain)
{
	TRACE("Enter LsaCreateTrustedDomainEx\n");
	return pLsaCreateTrustedDomainEx(policy, domain_info, auth_info, access, domain);
}

extern WINAPI void wine32a_LsaCreateTrustedDomainEx(void);
__ASM_GLOBAL_FUNC(wine32a_LsaCreateTrustedDomainEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaCreateTrustedDomainEx") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaDeleteTrustedDomain(LSA_HANDLE policy, PSID sid)
{
	TRACE("Enter LsaDeleteTrustedDomain\n");
	return pLsaDeleteTrustedDomain(policy, sid);
}

extern WINAPI void wine32a_LsaDeleteTrustedDomain(void);
__ASM_GLOBAL_FUNC(wine32a_LsaDeleteTrustedDomain,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaDeleteTrustedDomain") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaEnumerateAccountRights(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING * rights, PULONG count)
{
	TRACE("Enter LsaEnumerateAccountRights\n");
	return pLsaEnumerateAccountRights(policy, sid, rights, count);
}

extern WINAPI void wine32a_LsaEnumerateAccountRights(void);
__ASM_GLOBAL_FUNC(wine32a_LsaEnumerateAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaEnumerateAccountRights") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaEnumerateAccountsWithUserRight(LSA_HANDLE policy, PLSA_UNICODE_STRING rights, PVOID * buffer, PULONG count)
{
	TRACE("Enter LsaEnumerateAccountsWithUserRight\n");
	return pLsaEnumerateAccountsWithUserRight(policy, rights, buffer, count);
}

extern WINAPI void wine32a_LsaEnumerateAccountsWithUserRight(void);
__ASM_GLOBAL_FUNC(wine32a_LsaEnumerateAccountsWithUserRight,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaEnumerateAccountsWithUserRight") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaEnumerateTrustedDomains(LSA_HANDLE PolicyHandle, PLSA_ENUMERATION_HANDLE EnumerationContext, PVOID * Buffer, ULONG PreferredMaximumLength, PULONG CountReturned)
{
	TRACE("Enter LsaEnumerateTrustedDomains\n");
	return pLsaEnumerateTrustedDomains(PolicyHandle, EnumerationContext, Buffer, PreferredMaximumLength, CountReturned);
}

extern WINAPI void wine32a_LsaEnumerateTrustedDomains(void);
__ASM_GLOBAL_FUNC(wine32a_LsaEnumerateTrustedDomains,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaEnumerateTrustedDomains") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaEnumerateTrustedDomainsEx(LSA_HANDLE policy, PLSA_ENUMERATION_HANDLE context, PVOID * buffer, ULONG length, PULONG count)
{
	TRACE("Enter LsaEnumerateTrustedDomainsEx\n");
	return pLsaEnumerateTrustedDomainsEx(policy, context, buffer, length, count);
}

extern WINAPI void wine32a_LsaEnumerateTrustedDomainsEx(void);
__ASM_GLOBAL_FUNC(wine32a_LsaEnumerateTrustedDomainsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaEnumerateTrustedDomainsEx") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaFreeMemory(PVOID Buffer)
{
	TRACE("Enter LsaFreeMemory\n");
	return pLsaFreeMemory(Buffer);
}

extern WINAPI void wine32a_LsaFreeMemory(void);
__ASM_GLOBAL_FUNC(wine32a_LsaFreeMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaFreeMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaLookupNames(LSA_HANDLE PolicyHandle, ULONG Count, PLSA_UNICODE_STRING Names, PLSA_REFERENCED_DOMAIN_LIST * ReferencedDomains, PLSA_TRANSLATED_SID * Sids)
{
	TRACE("Enter LsaLookupNames\n");
	return pLsaLookupNames(PolicyHandle, Count, Names, ReferencedDomains, Sids);
}

extern WINAPI void wine32a_LsaLookupNames(void);
__ASM_GLOBAL_FUNC(wine32a_LsaLookupNames,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaLookupNames") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaLookupNames2(LSA_HANDLE policy, ULONG flags, ULONG count, PLSA_UNICODE_STRING names, PLSA_REFERENCED_DOMAIN_LIST * domains, PLSA_TRANSLATED_SID2 * sids)
{
	TRACE("Enter LsaLookupNames2\n");
	return pLsaLookupNames2(policy, flags, count, names, domains, sids);
}

extern WINAPI void wine32a_LsaLookupNames2(void);
__ASM_GLOBAL_FUNC(wine32a_LsaLookupNames2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaLookupNames2") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaLookupSids(LSA_HANDLE PolicyHandle, ULONG Count, PSID * Sids, LSA_REFERENCED_DOMAIN_LIST ** ReferencedDomains, LSA_TRANSLATED_NAME ** Names)
{
	TRACE("Enter LsaLookupSids\n");
	return pLsaLookupSids(PolicyHandle, Count, Sids, ReferencedDomains, Names);
}

extern WINAPI void wine32a_LsaLookupSids(void);
__ASM_GLOBAL_FUNC(wine32a_LsaLookupSids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaLookupSids") "\n"
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

extern WINAPI ULONG wine32b_LsaNtStatusToWinError(NTSTATUS Status)
{
	TRACE("Enter LsaNtStatusToWinError\n");
	return pLsaNtStatusToWinError(Status);
}

extern WINAPI void wine32a_LsaNtStatusToWinError(void);
__ASM_GLOBAL_FUNC(wine32a_LsaNtStatusToWinError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaNtStatusToWinError") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaOpenPolicy(PLSA_UNICODE_STRING SystemName, PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle)
{
	TRACE("Enter LsaOpenPolicy\n");
	return pLsaOpenPolicy(SystemName, ObjectAttributes, DesiredAccess, PolicyHandle);
}

extern WINAPI void wine32a_LsaOpenPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_LsaOpenPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaOpenPolicy") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaOpenTrustedDomainByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, ACCESS_MASK access, PLSA_HANDLE handle)
{
	TRACE("Enter LsaOpenTrustedDomainByName\n");
	return pLsaOpenTrustedDomainByName(policy, name, access, handle);
}

extern WINAPI void wine32a_LsaOpenTrustedDomainByName(void);
__ASM_GLOBAL_FUNC(wine32a_LsaOpenTrustedDomainByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaOpenTrustedDomainByName") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaQueryInformationPolicy(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID * Buffer)
{
	TRACE("Enter LsaQueryInformationPolicy\n");
	return pLsaQueryInformationPolicy(PolicyHandle, InformationClass, Buffer);
}

extern WINAPI void wine32a_LsaQueryInformationPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_LsaQueryInformationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaQueryInformationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaQueryTrustedDomainInfo(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID * buffer)
{
	TRACE("Enter LsaQueryTrustedDomainInfo\n");
	return pLsaQueryTrustedDomainInfo(policy, sid, class, buffer);
}

extern WINAPI void wine32a_LsaQueryTrustedDomainInfo(void);
__ASM_GLOBAL_FUNC(wine32a_LsaQueryTrustedDomainInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaQueryTrustedDomainInfo") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaQueryTrustedDomainInfoByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID * buffer)
{
	TRACE("Enter LsaQueryTrustedDomainInfoByName\n");
	return pLsaQueryTrustedDomainInfoByName(policy, name, class, buffer);
}

extern WINAPI void wine32a_LsaQueryTrustedDomainInfoByName(void);
__ASM_GLOBAL_FUNC(wine32a_LsaQueryTrustedDomainInfoByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaQueryTrustedDomainInfoByName") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaRegisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event)
{
	TRACE("Enter LsaRegisterPolicyChangeNotification\n");
	return pLsaRegisterPolicyChangeNotification(class, event);
}

extern WINAPI void wine32a_LsaRegisterPolicyChangeNotification(void);
__ASM_GLOBAL_FUNC(wine32a_LsaRegisterPolicyChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaRegisterPolicyChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaRemoveAccountRights(LSA_HANDLE policy, PSID sid, BOOLEAN all, PLSA_UNICODE_STRING rights, ULONG count)
{
	TRACE("Enter LsaRemoveAccountRights\n");
	return pLsaRemoveAccountRights(policy, sid, all, rights, count);
}

extern WINAPI void wine32a_LsaRemoveAccountRights(void);
__ASM_GLOBAL_FUNC(wine32a_LsaRemoveAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaRemoveAccountRights") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaRetrievePrivateData(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING * PrivateData)
{
	TRACE("Enter LsaRetrievePrivateData\n");
	return pLsaRetrievePrivateData(PolicyHandle, KeyName, PrivateData);
}

extern WINAPI void wine32a_LsaRetrievePrivateData(void);
__ASM_GLOBAL_FUNC(wine32a_LsaRetrievePrivateData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaRetrievePrivateData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaSetInformationPolicy(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID Buffer)
{
	TRACE("Enter LsaSetInformationPolicy\n");
	return pLsaSetInformationPolicy(PolicyHandle, InformationClass, Buffer);
}

extern WINAPI void wine32a_LsaSetInformationPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_LsaSetInformationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaSetInformationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaSetSecret(LSA_HANDLE SecretHandle, PLSA_UNICODE_STRING EncryptedCurrentValue, PLSA_UNICODE_STRING EncryptedOldValue)
{
	TRACE("Enter LsaSetSecret\n");
	return pLsaSetSecret(SecretHandle, EncryptedCurrentValue, EncryptedOldValue);
}

extern WINAPI void wine32a_LsaSetSecret(void);
__ASM_GLOBAL_FUNC(wine32a_LsaSetSecret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaSetSecret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaSetTrustedDomainInfoByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID buffer)
{
	TRACE("Enter LsaSetTrustedDomainInfoByName\n");
	return pLsaSetTrustedDomainInfoByName(policy, name, class, buffer);
}

extern WINAPI void wine32a_LsaSetTrustedDomainInfoByName(void);
__ASM_GLOBAL_FUNC(wine32a_LsaSetTrustedDomainInfoByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaSetTrustedDomainInfoByName") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaSetTrustedDomainInformation(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID buffer)
{
	TRACE("Enter LsaSetTrustedDomainInformation\n");
	return pLsaSetTrustedDomainInformation(policy, sid, class, buffer);
}

extern WINAPI void wine32a_LsaSetTrustedDomainInformation(void);
__ASM_GLOBAL_FUNC(wine32a_LsaSetTrustedDomainInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaSetTrustedDomainInformation") "\n"
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

extern WINAPI NTSTATUS wine32b_LsaStorePrivateData(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING PrivateData)
{
	TRACE("Enter LsaStorePrivateData\n");
	return pLsaStorePrivateData(PolicyHandle, KeyName, PrivateData);
}

extern WINAPI void wine32a_LsaStorePrivateData(void);
__ASM_GLOBAL_FUNC(wine32a_LsaStorePrivateData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaStorePrivateData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaUnregisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event)
{
	TRACE("Enter LsaUnregisterPolicyChangeNotification\n");
	return pLsaUnregisterPolicyChangeNotification(class, event);
}

extern WINAPI void wine32a_LsaUnregisterPolicyChangeNotification(void);
__ASM_GLOBAL_FUNC(wine32a_LsaUnregisterPolicyChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaUnregisterPolicyChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaLookupPrivilegeName(LSA_HANDLE handle, LUID * luid, LSA_UNICODE_STRING ** name)
{
	TRACE("Enter LsaLookupPrivilegeName\n");
	return pLsaLookupPrivilegeName(handle, luid, name);
}

extern WINAPI void wine32a_LsaLookupPrivilegeName(void);
__ASM_GLOBAL_FUNC(wine32a_LsaLookupPrivilegeName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaLookupPrivilegeName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LsaLookupPrivilegeDisplayName(LSA_HANDLE handle, LSA_UNICODE_STRING * name, LSA_UNICODE_STRING ** display_name, SHORT * language)
{
	TRACE("Enter LsaLookupPrivilegeDisplayName\n");
	return pLsaLookupPrivilegeDisplayName(handle, name, display_name, language);
}

extern WINAPI void wine32a_LsaLookupPrivilegeDisplayName(void);
__ASM_GLOBAL_FUNC(wine32a_LsaLookupPrivilegeDisplayName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LsaLookupPrivilegeDisplayName") "\n"
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

extern WINAPI BOOLEAN wine32b_AuditQuerySystemPolicy(const GUID * guids, ULONG count, AUDIT_POLICY_INFORMATION ** policy)
{
	TRACE("Enter AuditQuerySystemPolicy\n");
	return pAuditQuerySystemPolicy(guids, count, policy);
}

extern WINAPI void wine32a_AuditQuerySystemPolicy(void);
__ASM_GLOBAL_FUNC(wine32a_AuditQuerySystemPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AuditQuerySystemPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI LSTATUS (*pRegOverridePredefKey)(HKEY hkey, HKEY override);
static WINAPI LSTATUS (*pRegCreateKeyW)(HKEY hkey, LPCWSTR lpSubKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegCreateKeyA)(HKEY hkey, LPCSTR lpSubKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegCreateKeyTransactedW)(HKEY hkey, LPCWSTR name, DWORD reserved, LPWSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES * sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2);
static WINAPI LSTATUS (*pRegCreateKeyTransactedA)(HKEY hkey, LPCSTR name, DWORD reserved, LPSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES * sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2);
static WINAPI LSTATUS (*pRegOpenKeyW)(HKEY hkey, LPCWSTR name, PHKEY retkey);
static WINAPI LSTATUS (*pRegOpenKeyA)(HKEY hkey, LPCSTR name, PHKEY retkey);
static WINAPI LSTATUS (*pRegEnumKeyW)(HKEY hkey, DWORD index, LPWSTR name, DWORD name_len);
static WINAPI LSTATUS (*pRegEnumKeyA)(HKEY hkey, DWORD index, LPSTR name, DWORD name_len);
static WINAPI LSTATUS (*pRegQueryMultipleValuesA)(HKEY hkey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
static WINAPI LSTATUS (*pRegQueryMultipleValuesW)(HKEY hkey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
static WINAPI LONG (*pRegQueryReflectionKey)(HKEY hkey, BOOL * is_reflection_disabled);
static WINAPI LSTATUS (*pRegDeleteKeyW)(HKEY hkey, LPCWSTR name);
static WINAPI LSTATUS (*pRegDeleteKeyA)(HKEY hkey, LPCSTR name);
static WINAPI LSTATUS (*pRegSetValueW)(HKEY hkey, LPCWSTR subkey, DWORD type, LPCWSTR data, DWORD count);
static WINAPI LSTATUS (*pRegSetValueA)(HKEY hkey, LPCSTR subkey, DWORD type, LPCSTR data, DWORD count);
static WINAPI LSTATUS (*pRegQueryValueW)(HKEY hkey, LPCWSTR name, LPWSTR data, LPLONG count);
static WINAPI LSTATUS (*pRegQueryValueA)(HKEY hkey, LPCSTR name, LPSTR data, LPLONG count);
static WINAPI LSTATUS (*pRegSaveKeyW)(HKEY hkey, LPCWSTR file, LPSECURITY_ATTRIBUTES sa);
static WINAPI LSTATUS (*pRegSaveKeyA)(HKEY hkey, LPCSTR file, LPSECURITY_ATTRIBUTES sa);
static WINAPI LSTATUS (*pRegReplaceKeyW)(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
static WINAPI LSTATUS (*pRegReplaceKeyA)(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
static WINAPI LSTATUS (*pRegConnectRegistryW)(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegConnectRegistryA)(LPCSTR machine, HKEY hkey, PHKEY reskey);
static WINAPI LSTATUS (*pRegDisablePredefinedCache)(void);
static WINAPI LSTATUS (*pRegCopyTreeA)(HKEY hsrc, const char * subkey, HKEY hdst);
static WINAPI LONG (*pRegDisableReflectionKey)(HKEY base);

extern WINAPI LSTATUS wine32b_RegOverridePredefKey(HKEY hkey, HKEY override)
{
	TRACE("Enter RegOverridePredefKey\n");
	return pRegOverridePredefKey(hkey, override);
}

extern WINAPI void wine32a_RegOverridePredefKey(void);
__ASM_GLOBAL_FUNC(wine32a_RegOverridePredefKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegOverridePredefKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegCreateKeyW(HKEY hkey, LPCWSTR lpSubKey, PHKEY phkResult)
{
	TRACE("Enter RegCreateKeyW\n");
	return pRegCreateKeyW(hkey, lpSubKey, phkResult);
}

extern WINAPI void wine32a_RegCreateKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegCreateKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegCreateKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegCreateKeyA(HKEY hkey, LPCSTR lpSubKey, PHKEY phkResult)
{
	TRACE("Enter RegCreateKeyA\n");
	return pRegCreateKeyA(hkey, lpSubKey, phkResult);
}

extern WINAPI void wine32a_RegCreateKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegCreateKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegCreateKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegCreateKeyTransactedW(HKEY hkey, LPCWSTR name, DWORD reserved, LPWSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES * sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2)
{
	TRACE("Enter RegCreateKeyTransactedW\n");
	return pRegCreateKeyTransactedW(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
}

extern WINAPI void wine32a_RegCreateKeyTransactedW(void);
__ASM_GLOBAL_FUNC(wine32a_RegCreateKeyTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegCreateKeyTransactedW") "\n"
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

extern WINAPI LSTATUS wine32b_RegCreateKeyTransactedA(HKEY hkey, LPCSTR name, DWORD reserved, LPSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES * sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2)
{
	TRACE("Enter RegCreateKeyTransactedA\n");
	return pRegCreateKeyTransactedA(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
}

extern WINAPI void wine32a_RegCreateKeyTransactedA(void);
__ASM_GLOBAL_FUNC(wine32a_RegCreateKeyTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegCreateKeyTransactedA") "\n"
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

extern WINAPI LSTATUS wine32b_RegOpenKeyW(HKEY hkey, LPCWSTR name, PHKEY retkey)
{
	TRACE("Enter RegOpenKeyW\n");
	return pRegOpenKeyW(hkey, name, retkey);
}

extern WINAPI void wine32a_RegOpenKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegOpenKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegOpenKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegOpenKeyA(HKEY hkey, LPCSTR name, PHKEY retkey)
{
	TRACE("Enter RegOpenKeyA\n");
	return pRegOpenKeyA(hkey, name, retkey);
}

extern WINAPI void wine32a_RegOpenKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegOpenKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegOpenKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegEnumKeyW(HKEY hkey, DWORD index, LPWSTR name, DWORD name_len)
{
	TRACE("Enter RegEnumKeyW\n");
	return pRegEnumKeyW(hkey, index, name, name_len);
}

extern WINAPI void wine32a_RegEnumKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegEnumKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegEnumKeyW") "\n"
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

extern WINAPI LSTATUS wine32b_RegEnumKeyA(HKEY hkey, DWORD index, LPSTR name, DWORD name_len)
{
	TRACE("Enter RegEnumKeyA\n");
	return pRegEnumKeyA(hkey, index, name, name_len);
}

extern WINAPI void wine32a_RegEnumKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegEnumKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegEnumKeyA") "\n"
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

extern WINAPI LSTATUS wine32b_RegQueryMultipleValuesA(HKEY hkey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize)
{
	TRACE("Enter RegQueryMultipleValuesA\n");
	return pRegQueryMultipleValuesA(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
}

extern WINAPI void wine32a_RegQueryMultipleValuesA(void);
__ASM_GLOBAL_FUNC(wine32a_RegQueryMultipleValuesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegQueryMultipleValuesA") "\n"
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

extern WINAPI LSTATUS wine32b_RegQueryMultipleValuesW(HKEY hkey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize)
{
	TRACE("Enter RegQueryMultipleValuesW\n");
	return pRegQueryMultipleValuesW(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
}

extern WINAPI void wine32a_RegQueryMultipleValuesW(void);
__ASM_GLOBAL_FUNC(wine32a_RegQueryMultipleValuesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegQueryMultipleValuesW") "\n"
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

extern WINAPI LONG wine32b_RegQueryReflectionKey(HKEY hkey, BOOL * is_reflection_disabled)
{
	TRACE("Enter RegQueryReflectionKey\n");
	return pRegQueryReflectionKey(hkey, is_reflection_disabled);
}

extern WINAPI void wine32a_RegQueryReflectionKey(void);
__ASM_GLOBAL_FUNC(wine32a_RegQueryReflectionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegQueryReflectionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegDeleteKeyW(HKEY hkey, LPCWSTR name)
{
	TRACE("Enter RegDeleteKeyW\n");
	return pRegDeleteKeyW(hkey, name);
}

extern WINAPI void wine32a_RegDeleteKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegDeleteKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegDeleteKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegDeleteKeyA(HKEY hkey, LPCSTR name)
{
	TRACE("Enter RegDeleteKeyA\n");
	return pRegDeleteKeyA(hkey, name);
}

extern WINAPI void wine32a_RegDeleteKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegDeleteKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegDeleteKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegSetValueW(HKEY hkey, LPCWSTR subkey, DWORD type, LPCWSTR data, DWORD count)
{
	TRACE("Enter RegSetValueW\n");
	return pRegSetValueW(hkey, subkey, type, data, count);
}

extern WINAPI void wine32a_RegSetValueW(void);
__ASM_GLOBAL_FUNC(wine32a_RegSetValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegSetValueW") "\n"
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

extern WINAPI LSTATUS wine32b_RegSetValueA(HKEY hkey, LPCSTR subkey, DWORD type, LPCSTR data, DWORD count)
{
	TRACE("Enter RegSetValueA\n");
	return pRegSetValueA(hkey, subkey, type, data, count);
}

extern WINAPI void wine32a_RegSetValueA(void);
__ASM_GLOBAL_FUNC(wine32a_RegSetValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegSetValueA") "\n"
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

extern WINAPI LSTATUS wine32b_RegQueryValueW(HKEY hkey, LPCWSTR name, LPWSTR data, LPLONG count)
{
	TRACE("Enter RegQueryValueW\n");
	return pRegQueryValueW(hkey, name, data, count);
}

extern WINAPI void wine32a_RegQueryValueW(void);
__ASM_GLOBAL_FUNC(wine32a_RegQueryValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegQueryValueW") "\n"
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

extern WINAPI LSTATUS wine32b_RegQueryValueA(HKEY hkey, LPCSTR name, LPSTR data, LPLONG count)
{
	TRACE("Enter RegQueryValueA\n");
	return pRegQueryValueA(hkey, name, data, count);
}

extern WINAPI void wine32a_RegQueryValueA(void);
__ASM_GLOBAL_FUNC(wine32a_RegQueryValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegQueryValueA") "\n"
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

extern WINAPI LSTATUS wine32b_RegSaveKeyW(HKEY hkey, LPCWSTR file, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter RegSaveKeyW\n");
	return pRegSaveKeyW(hkey, file, sa);
}

extern WINAPI void wine32a_RegSaveKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegSaveKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegSaveKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegSaveKeyA(HKEY hkey, LPCSTR file, LPSECURITY_ATTRIBUTES sa)
{
	TRACE("Enter RegSaveKeyA\n");
	return pRegSaveKeyA(hkey, file, sa);
}

extern WINAPI void wine32a_RegSaveKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegSaveKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegSaveKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegReplaceKeyW(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile)
{
	TRACE("Enter RegReplaceKeyW\n");
	return pRegReplaceKeyW(hkey, lpSubKey, lpNewFile, lpOldFile);
}

extern WINAPI void wine32a_RegReplaceKeyW(void);
__ASM_GLOBAL_FUNC(wine32a_RegReplaceKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegReplaceKeyW") "\n"
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

extern WINAPI LSTATUS wine32b_RegReplaceKeyA(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile)
{
	TRACE("Enter RegReplaceKeyA\n");
	return pRegReplaceKeyA(hkey, lpSubKey, lpNewFile, lpOldFile);
}

extern WINAPI void wine32a_RegReplaceKeyA(void);
__ASM_GLOBAL_FUNC(wine32a_RegReplaceKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegReplaceKeyA") "\n"
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

extern WINAPI LSTATUS wine32b_RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult)
{
	TRACE("Enter RegConnectRegistryW\n");
	return pRegConnectRegistryW(lpMachineName, hKey, phkResult);
}

extern WINAPI void wine32a_RegConnectRegistryW(void);
__ASM_GLOBAL_FUNC(wine32a_RegConnectRegistryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegConnectRegistryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegConnectRegistryA(LPCSTR machine, HKEY hkey, PHKEY reskey)
{
	TRACE("Enter RegConnectRegistryA\n");
	return pRegConnectRegistryA(machine, hkey, reskey);
}

extern WINAPI void wine32a_RegConnectRegistryA(void);
__ASM_GLOBAL_FUNC(wine32a_RegConnectRegistryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegConnectRegistryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_RegDisablePredefinedCache(void)
{
	TRACE("Enter RegDisablePredefinedCache\n");
	return pRegDisablePredefinedCache();
}

extern WINAPI void wine32a_RegDisablePredefinedCache(void);
__ASM_GLOBAL_FUNC(wine32a_RegDisablePredefinedCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegDisablePredefinedCache") "\n"
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

extern WINAPI LSTATUS wine32b_RegCopyTreeA(HKEY hsrc, const char * subkey, HKEY hdst)
{
	TRACE("Enter RegCopyTreeA\n");
	return pRegCopyTreeA(hsrc, subkey, hdst);
}

extern WINAPI void wine32a_RegCopyTreeA(void);
__ASM_GLOBAL_FUNC(wine32a_RegCopyTreeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegCopyTreeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_RegDisableReflectionKey(HKEY base)
{
	TRACE("Enter RegDisableReflectionKey\n");
	return pRegDisableReflectionKey(base);
}

extern WINAPI void wine32a_RegDisableReflectionKey(void);
__ASM_GLOBAL_FUNC(wine32a_RegDisableReflectionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RegDisableReflectionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI DWORD (*pGetEffectiveRightsFromAclA)(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pAccessRights);
static WINAPI DWORD (*pGetEffectiveRightsFromAclW)(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pAccessRights);
static WINAPI DWORD (*pBuildSecurityDescriptorA)(PTRUSTEEA pOwner, PTRUSTEEA pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSA pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSA pListofAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR * pNewSD);
static WINAPI DWORD (*pBuildSecurityDescriptorW)(PTRUSTEEW pOwner, PTRUSTEEW pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSW pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSW pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR * pNewSD);
static WINAPI BOOL (*pLookupPrivilegeValueW)(LPCWSTR lpSystemName, LPCWSTR lpName, PLUID lpLuid);
static WINAPI BOOL (*pLookupPrivilegeValueA)(LPCSTR lpSystemName, LPCSTR lpName, PLUID lpLuid);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameA)(LPCSTR lpSystemName, LPCSTR lpName, LPSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameW)(LPCWSTR lpSystemName, LPCWSTR lpName, LPWSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeNameA)(LPCSTR lpSystemName, PLUID lpLuid, LPSTR lpName, LPDWORD cchName);
static WINAPI BOOL (*pLookupPrivilegeNameW)(LPCWSTR lpSystemName, PLUID lpLuid, LPWSTR lpName, LPDWORD cchName);
static WINAPI BOOL (*pGetFileSecurityA)(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded);
static WINAPI BOOL (*pLookupAccountSidA)(LPCSTR system, PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidLocalA)(PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidW)(LPCWSTR system, PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidLocalW)(PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pSetFileSecurityA)(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
static WINAPI BOOL (*pQueryWindows31FilesMigration)(DWORD x1);
static WINAPI BOOL (*pSynchronizeWindows31FilesAndWindowsNTRegistry)(DWORD x1, DWORD x2, DWORD x3, DWORD x4);
static WINAPI BOOL (*pNotifyBootConfigStatus)(BOOL x1);
static WINAPI BOOL (*pLookupAccountNameA)(LPCSTR system, LPCSTR account, PSID sid, LPDWORD cbSid, LPSTR ReferencedDomainName, LPDWORD cbReferencedDomainName, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountNameW)(LPCWSTR lpSystemName, LPCWSTR lpAccountName, PSID Sid, LPDWORD cbSid, LPWSTR ReferencedDomainName, LPDWORD cchReferencedDomainName, PSID_NAME_USE peUse);
static WINAPI BOOL (*pAccessCheckAndAuditAlarmA)(LPCSTR Subsystem, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose);
static WINAPI BOOL (*pObjectCloseAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose);
static WINAPI BOOL (*pObjectOpenAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose);
static WINAPI BOOL (*pObjectPrivilegeAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted);
static WINAPI BOOL (*pPrivilegedServiceAuditAlarmA)(LPCSTR SubsystemName, LPCSTR ServiceName, HANDLE ClientToken, PPRIVILEGE_SET Privileges, BOOL AccessGranted);
static WINAPI DWORD (*pGetSecurityInfo)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID * ppsidOwner, PSID * ppsidGroup, PACL * ppDacl, PACL * ppSacl, PSECURITY_DESCRIPTOR * ppSecurityDescriptor);
static WINAPI DWORD (*pGetSecurityInfoExA)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCSTR lpProvider, LPCSTR lpProperty, PACTRL_ACCESSA * ppAccessList, PACTRL_AUDITA * ppAuditList, LPSTR * lppOwner, LPSTR * lppGroup);
static WINAPI DWORD (*pGetSecurityInfoExW)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCWSTR lpProvider, LPCWSTR lpProperty, PACTRL_ACCESSW * ppAccessList, PACTRL_AUDITW * ppAuditList, LPWSTR * lppOwner, LPWSTR * lppGroup);
static WINAPI void (*pBuildExplicitAccessWithNameA)(PEXPLICIT_ACCESSA pExplicitAccess, LPSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance);
static WINAPI void (*pBuildExplicitAccessWithNameW)(PEXPLICIT_ACCESSW pExplicitAccess, LPWSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameA)(PTRUSTEEA pTrustee, POBJECTS_AND_NAME_A pObjName, SE_OBJECT_TYPE ObjectType, LPSTR ObjectTypeName, LPSTR InheritedObjectTypeName, LPSTR Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameW)(PTRUSTEEW pTrustee, POBJECTS_AND_NAME_W pObjName, SE_OBJECT_TYPE ObjectType, LPWSTR ObjectTypeName, LPWSTR InheritedObjectTypeName, LPWSTR Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidA)(PTRUSTEEA pTrustee, POBJECTS_AND_SID pObjSid, GUID * pObjectGuid, GUID * pInheritedObjectGuid, PSID pSid);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidW)(PTRUSTEEW pTrustee, POBJECTS_AND_SID pObjSid, GUID * pObjectGuid, GUID * pInheritedObjectGuid, PSID pSid);
static WINAPI void (*pBuildTrusteeWithSidA)(PTRUSTEEA pTrustee, PSID pSid);
static WINAPI void (*pBuildTrusteeWithSidW)(PTRUSTEEW pTrustee, PSID pSid);
static WINAPI void (*pBuildTrusteeWithNameA)(PTRUSTEEA pTrustee, LPSTR name);
static WINAPI void (*pBuildTrusteeWithNameW)(PTRUSTEEW pTrustee, LPWSTR name);
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormA)(PTRUSTEEA pTrustee);
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormW)(PTRUSTEEW pTrustee);
static WINAPI LPSTR (*pGetTrusteeNameA)(PTRUSTEEA pTrustee);
static WINAPI LPWSTR (*pGetTrusteeNameW)(PTRUSTEEW pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeA)(PTRUSTEEA pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeW)(PTRUSTEEW pTrustee);
static WINAPI DWORD (*pSetEntriesInAclA)(ULONG count, PEXPLICIT_ACCESSA pEntries, PACL OldAcl, PACL * NewAcl);
static WINAPI DWORD (*pSetEntriesInAclW)(ULONG count, PEXPLICIT_ACCESSW pEntries, PACL OldAcl, PACL * NewAcl);
static WINAPI DWORD (*pSetNamedSecurityInfoA)(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI DWORD (*pSetNamedSecurityInfoW)(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI DWORD (*pGetExplicitEntriesFromAclA)(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESSA * pListOfExplicitEntries);
static WINAPI DWORD (*pGetExplicitEntriesFromAclW)(PACL pacl, PULONG count, PEXPLICIT_ACCESSW * list);
static WINAPI DWORD (*pGetAuditedPermissionsFromAclA)(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights);
static WINAPI DWORD (*pGetAuditedPermissionsFromAclW)(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorA)(LPCSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR * SecurityDescriptor, PULONG SecurityDescriptorSize);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorW)(LPCWSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR * SecurityDescriptor, PULONG SecurityDescriptorSize);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorW)(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION RequestedInformation, LPWSTR * OutputString, PULONG OutputLen);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorA)(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION Information, LPSTR * OutputString, PULONG OutputLen);
static WINAPI BOOL (*pConvertStringSidToSidW)(LPCWSTR StringSid, PSID * Sid);
static WINAPI BOOL (*pConvertStringSidToSidA)(LPCSTR StringSid, PSID * Sid);
static WINAPI BOOL (*pConvertSidToStringSidW)(PSID pSid, LPWSTR * pstr);
static WINAPI BOOL (*pConvertSidToStringSidA)(PSID pSid, LPSTR * pstr);
static WINAPI BOOL (*pCreateProcessWithLogonW)(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static WINAPI BOOL (*pCreateProcessWithTokenW)(HANDLE token, DWORD logon_flags, LPCWSTR application_name, LPWSTR command_line, DWORD creation_flags, void * environment, LPCWSTR current_directory, STARTUPINFOW * startup_info, PROCESS_INFORMATION * process_information);
static WINAPI DWORD (*pGetNamedSecurityInfoA)(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID * ppsidOwner, PSID * ppsidGroup, PACL * ppDacl, PACL * ppSacl, PSECURITY_DESCRIPTOR * ppSecurityDescriptor);
static WINAPI DWORD (*pGetNamedSecurityInfoW)(LPWSTR name, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, PSID * owner, PSID * group, PACL * dacl, PACL * sacl, PSECURITY_DESCRIPTOR * descriptor);
static WINAPI DWORD (*pGetNamedSecurityInfoExW)(LPCWSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCWSTR provider, LPCWSTR property, PACTRL_ACCESSW * access_list, PACTRL_AUDITW * audit_list, LPWSTR * owner, LPWSTR * group);
static WINAPI DWORD (*pGetNamedSecurityInfoExA)(LPCSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCSTR provider, LPCSTR property, PACTRL_ACCESSA * access_list, PACTRL_AUDITA * audit_list, LPSTR * owner, LPSTR * group);
static WINAPI BOOL (*pDecryptFileW)(LPCWSTR lpFileName, DWORD dwReserved);
static WINAPI BOOL (*pDecryptFileA)(LPCSTR lpFileName, DWORD dwReserved);
static WINAPI BOOL (*pEncryptFileW)(LPCWSTR lpFileName);
static WINAPI BOOL (*pEncryptFileA)(LPCSTR lpFileName);
static WINAPI BOOL (*pFileEncryptionStatusW)(LPCWSTR lpFileName, LPDWORD lpStatus);
static WINAPI BOOL (*pFileEncryptionStatusA)(LPCSTR lpFileName, LPDWORD lpStatus);
static WINAPI DWORD (*pSetSecurityInfo)(HANDLE handle, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI BOOL (*pSaferCreateLevel)(DWORD ScopeId, DWORD LevelId, DWORD OpenFlags, SAFER_LEVEL_HANDLE * LevelHandle, LPVOID lpReserved);
static WINAPI BOOL (*pSaferComputeTokenFromLevel)(SAFER_LEVEL_HANDLE handle, HANDLE token, PHANDLE access_token, DWORD flags, LPVOID reserved);
static WINAPI BOOL (*pSaferCloseLevel)(SAFER_LEVEL_HANDLE handle);
static WINAPI DWORD (*pTreeResetNamedSecurityInfoW)(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args);
static WINAPI BOOL (*pSaferGetPolicyInformation)(DWORD scope, SAFER_POLICY_INFO_CLASS class, DWORD size, PVOID buffer, PDWORD required, LPVOID lpReserved);
static WINAPI BOOL (*pSaferIdentifyLevel)(DWORD count, SAFER_CODE_PROPERTIES * properties, SAFER_LEVEL_HANDLE * handle, void * reserved);
static WINAPI BOOL (*pSaferSetLevelInformation)(SAFER_LEVEL_HANDLE handle, SAFER_OBJECT_INFO_CLASS infotype, LPVOID buffer, DWORD size);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsA)(TRUSTEEA * owner, TRUSTEEA * group, ULONG * access_count, EXPLICIT_ACCESSA * access_list, ULONG * audit_count, EXPLICIT_ACCESSA * audit_list, SECURITY_DESCRIPTOR * descriptor);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsW)(TRUSTEEW * owner, TRUSTEEW * group, ULONG * access_count, EXPLICIT_ACCESSW * access_list, ULONG * audit_count, EXPLICIT_ACCESSW * audit_list, SECURITY_DESCRIPTOR * descriptor);

extern WINAPI DWORD wine32b_GetEffectiveRightsFromAclA(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pAccessRights)
{
	TRACE("Enter GetEffectiveRightsFromAclA\n");
	return pGetEffectiveRightsFromAclA(pacl, pTrustee, pAccessRights);
}

extern WINAPI void wine32a_GetEffectiveRightsFromAclA(void);
__ASM_GLOBAL_FUNC(wine32a_GetEffectiveRightsFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEffectiveRightsFromAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetEffectiveRightsFromAclW(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pAccessRights)
{
	TRACE("Enter GetEffectiveRightsFromAclW\n");
	return pGetEffectiveRightsFromAclW(pacl, pTrustee, pAccessRights);
}

extern WINAPI void wine32a_GetEffectiveRightsFromAclW(void);
__ASM_GLOBAL_FUNC(wine32a_GetEffectiveRightsFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetEffectiveRightsFromAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_BuildSecurityDescriptorA(PTRUSTEEA pOwner, PTRUSTEEA pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSA pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSA pListofAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR * pNewSD)
{
	TRACE("Enter BuildSecurityDescriptorA\n");
	return pBuildSecurityDescriptorA(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListofAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
}

extern WINAPI void wine32a_BuildSecurityDescriptorA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildSecurityDescriptorA") "\n"
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

extern WINAPI DWORD wine32b_BuildSecurityDescriptorW(PTRUSTEEW pOwner, PTRUSTEEW pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSW pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSW pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR * pNewSD)
{
	TRACE("Enter BuildSecurityDescriptorW\n");
	return pBuildSecurityDescriptorW(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListOfAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
}

extern WINAPI void wine32a_BuildSecurityDescriptorW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildSecurityDescriptorW") "\n"
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

extern WINAPI BOOL wine32b_LookupPrivilegeValueW(LPCWSTR lpSystemName, LPCWSTR lpName, PLUID lpLuid)
{
	TRACE("Enter LookupPrivilegeValueW\n");
	return pLookupPrivilegeValueW(lpSystemName, lpName, lpLuid);
}

extern WINAPI void wine32a_LookupPrivilegeValueW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_LookupPrivilegeValueA(LPCSTR lpSystemName, LPCSTR lpName, PLUID lpLuid)
{
	TRACE("Enter LookupPrivilegeValueA\n");
	return pLookupPrivilegeValueA(lpSystemName, lpName, lpLuid);
}

extern WINAPI void wine32a_LookupPrivilegeValueA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_LookupPrivilegeDisplayNameA(LPCSTR lpSystemName, LPCSTR lpName, LPSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId)
{
	TRACE("Enter LookupPrivilegeDisplayNameA\n");
	return pLookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
}

extern WINAPI void wine32a_LookupPrivilegeDisplayNameA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeDisplayNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeDisplayNameA") "\n"
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

extern WINAPI BOOL wine32b_LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName, LPCWSTR lpName, LPWSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId)
{
	TRACE("Enter LookupPrivilegeDisplayNameW\n");
	return pLookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
}

extern WINAPI void wine32a_LookupPrivilegeDisplayNameW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeDisplayNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeDisplayNameW") "\n"
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

extern WINAPI BOOL wine32b_LookupPrivilegeNameA(LPCSTR lpSystemName, PLUID lpLuid, LPSTR lpName, LPDWORD cchName)
{
	TRACE("Enter LookupPrivilegeNameA\n");
	return pLookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cchName);
}

extern WINAPI void wine32a_LookupPrivilegeNameA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeNameA") "\n"
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

extern WINAPI BOOL wine32b_LookupPrivilegeNameW(LPCWSTR lpSystemName, PLUID lpLuid, LPWSTR lpName, LPDWORD cchName)
{
	TRACE("Enter LookupPrivilegeNameW\n");
	return pLookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cchName);
}

extern WINAPI void wine32a_LookupPrivilegeNameW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupPrivilegeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupPrivilegeNameW") "\n"
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

extern WINAPI BOOL wine32b_GetFileSecurityA(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded)
{
	TRACE("Enter GetFileSecurityA\n");
	return pGetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded);
}

extern WINAPI void wine32a_GetFileSecurityA(void);
__ASM_GLOBAL_FUNC(wine32a_GetFileSecurityA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetFileSecurityA") "\n"
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

extern WINAPI BOOL wine32b_LookupAccountSidA(LPCSTR system, PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use)
{
	TRACE("Enter LookupAccountSidA\n");
	return pLookupAccountSidA(system, sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_LookupAccountSidA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountSidA") "\n"
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

extern WINAPI BOOL wine32b_LookupAccountSidLocalA(PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use)
{
	TRACE("Enter LookupAccountSidLocalA\n");
	return pLookupAccountSidLocalA(sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_LookupAccountSidLocalA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountSidLocalA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountSidLocalA") "\n"
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

extern WINAPI BOOL wine32b_LookupAccountSidW(LPCWSTR system, PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use)
{
	TRACE("Enter LookupAccountSidW\n");
	return pLookupAccountSidW(system, sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_LookupAccountSidW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountSidW") "\n"
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

extern WINAPI BOOL wine32b_LookupAccountSidLocalW(PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use)
{
	TRACE("Enter LookupAccountSidLocalW\n");
	return pLookupAccountSidLocalW(sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_LookupAccountSidLocalW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountSidLocalW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountSidLocalW") "\n"
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

extern WINAPI BOOL wine32b_SetFileSecurityA(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor)
{
	TRACE("Enter SetFileSecurityA\n");
	return pSetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor);
}

extern WINAPI void wine32a_SetFileSecurityA(void);
__ASM_GLOBAL_FUNC(wine32a_SetFileSecurityA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetFileSecurityA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_QueryWindows31FilesMigration(DWORD x1)
{
	TRACE("Enter QueryWindows31FilesMigration\n");
	return pQueryWindows31FilesMigration(x1);
}

extern WINAPI void wine32a_QueryWindows31FilesMigration(void);
__ASM_GLOBAL_FUNC(wine32a_QueryWindows31FilesMigration,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_QueryWindows31FilesMigration") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_SynchronizeWindows31FilesAndWindowsNTRegistry(DWORD x1, DWORD x2, DWORD x3, DWORD x4)
{
	TRACE("Enter SynchronizeWindows31FilesAndWindowsNTRegistry\n");
	return pSynchronizeWindows31FilesAndWindowsNTRegistry(x1, x2, x3, x4);
}

extern WINAPI void wine32a_SynchronizeWindows31FilesAndWindowsNTRegistry(void);
__ASM_GLOBAL_FUNC(wine32a_SynchronizeWindows31FilesAndWindowsNTRegistry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SynchronizeWindows31FilesAndWindowsNTRegistry") "\n"
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

extern WINAPI BOOL wine32b_NotifyBootConfigStatus(BOOL x1)
{
	TRACE("Enter NotifyBootConfigStatus\n");
	return pNotifyBootConfigStatus(x1);
}

extern WINAPI void wine32a_NotifyBootConfigStatus(void);
__ASM_GLOBAL_FUNC(wine32a_NotifyBootConfigStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NotifyBootConfigStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_LookupAccountNameA(LPCSTR system, LPCSTR account, PSID sid, LPDWORD cbSid, LPSTR ReferencedDomainName, LPDWORD cbReferencedDomainName, PSID_NAME_USE name_use)
{
	TRACE("Enter LookupAccountNameA\n");
	return pLookupAccountNameA(system, account, sid, cbSid, ReferencedDomainName, cbReferencedDomainName, name_use);
}

extern WINAPI void wine32a_LookupAccountNameA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountNameA") "\n"
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

extern WINAPI BOOL wine32b_LookupAccountNameW(LPCWSTR lpSystemName, LPCWSTR lpAccountName, PSID Sid, LPDWORD cbSid, LPWSTR ReferencedDomainName, LPDWORD cchReferencedDomainName, PSID_NAME_USE peUse)
{
	TRACE("Enter LookupAccountNameW\n");
	return pLookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cchReferencedDomainName, peUse);
}

extern WINAPI void wine32a_LookupAccountNameW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupAccountNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupAccountNameW") "\n"
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

extern WINAPI BOOL wine32b_AccessCheckAndAuditAlarmA(LPCSTR Subsystem, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose)
{
	TRACE("Enter AccessCheckAndAuditAlarmA\n");
	return pAccessCheckAndAuditAlarmA(Subsystem, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose);
}

extern WINAPI void wine32a_AccessCheckAndAuditAlarmA(void);
__ASM_GLOBAL_FUNC(wine32a_AccessCheckAndAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_AccessCheckAndAuditAlarmA") "\n"
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

extern WINAPI BOOL wine32b_ObjectCloseAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose)
{
	TRACE("Enter ObjectCloseAuditAlarmA\n");
	return pObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose);
}

extern WINAPI void wine32a_ObjectCloseAuditAlarmA(void);
__ASM_GLOBAL_FUNC(wine32a_ObjectCloseAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ObjectCloseAuditAlarmA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ObjectOpenAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose)
{
	TRACE("Enter ObjectOpenAuditAlarmA\n");
	return pObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose);
}

extern WINAPI void wine32a_ObjectOpenAuditAlarmA(void);
__ASM_GLOBAL_FUNC(wine32a_ObjectOpenAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ObjectOpenAuditAlarmA") "\n"
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

extern WINAPI BOOL wine32b_ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
{
	TRACE("Enter ObjectPrivilegeAuditAlarmA\n");
	return pObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted);
}

extern WINAPI void wine32a_ObjectPrivilegeAuditAlarmA(void);
__ASM_GLOBAL_FUNC(wine32a_ObjectPrivilegeAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ObjectPrivilegeAuditAlarmA") "\n"
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

extern WINAPI BOOL wine32b_PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName, LPCSTR ServiceName, HANDLE ClientToken, PPRIVILEGE_SET Privileges, BOOL AccessGranted)
{
	TRACE("Enter PrivilegedServiceAuditAlarmA\n");
	return pPrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted);
}

extern WINAPI void wine32a_PrivilegedServiceAuditAlarmA(void);
__ASM_GLOBAL_FUNC(wine32a_PrivilegedServiceAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_PrivilegedServiceAuditAlarmA") "\n"
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

extern WINAPI DWORD wine32b_GetSecurityInfo(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID * ppsidOwner, PSID * ppsidGroup, PACL * ppDacl, PACL * ppSacl, PSECURITY_DESCRIPTOR * ppSecurityDescriptor)
{
	TRACE("Enter GetSecurityInfo\n");
	return pGetSecurityInfo(hObject, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
}

extern WINAPI void wine32a_GetSecurityInfo(void);
__ASM_GLOBAL_FUNC(wine32a_GetSecurityInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSecurityInfo") "\n"
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

extern WINAPI DWORD wine32b_GetSecurityInfoExA(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCSTR lpProvider, LPCSTR lpProperty, PACTRL_ACCESSA * ppAccessList, PACTRL_AUDITA * ppAuditList, LPSTR * lppOwner, LPSTR * lppGroup)
{
	TRACE("Enter GetSecurityInfoExA\n");
	return pGetSecurityInfoExA(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
}

extern WINAPI void wine32a_GetSecurityInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetSecurityInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSecurityInfoExA") "\n"
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

extern WINAPI DWORD wine32b_GetSecurityInfoExW(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCWSTR lpProvider, LPCWSTR lpProperty, PACTRL_ACCESSW * ppAccessList, PACTRL_AUDITW * ppAuditList, LPWSTR * lppOwner, LPWSTR * lppGroup)
{
	TRACE("Enter GetSecurityInfoExW\n");
	return pGetSecurityInfoExW(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
}

extern WINAPI void wine32a_GetSecurityInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetSecurityInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetSecurityInfoExW") "\n"
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

extern WINAPI void wine32b_BuildExplicitAccessWithNameA(PEXPLICIT_ACCESSA pExplicitAccess, LPSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance)
{
	TRACE("Enter BuildExplicitAccessWithNameA\n");
	return pBuildExplicitAccessWithNameA(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
}

extern WINAPI void wine32a_BuildExplicitAccessWithNameA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildExplicitAccessWithNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildExplicitAccessWithNameA") "\n"
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

extern WINAPI void wine32b_BuildExplicitAccessWithNameW(PEXPLICIT_ACCESSW pExplicitAccess, LPWSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance)
{
	TRACE("Enter BuildExplicitAccessWithNameW\n");
	return pBuildExplicitAccessWithNameW(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
}

extern WINAPI void wine32a_BuildExplicitAccessWithNameW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildExplicitAccessWithNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildExplicitAccessWithNameW") "\n"
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

extern WINAPI void wine32b_BuildTrusteeWithObjectsAndNameA(PTRUSTEEA pTrustee, POBJECTS_AND_NAME_A pObjName, SE_OBJECT_TYPE ObjectType, LPSTR ObjectTypeName, LPSTR InheritedObjectTypeName, LPSTR Name)
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameA\n");
	return pBuildTrusteeWithObjectsAndNameA(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
}

extern WINAPI void wine32a_BuildTrusteeWithObjectsAndNameA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithObjectsAndNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithObjectsAndNameA") "\n"
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

extern WINAPI void wine32b_BuildTrusteeWithObjectsAndNameW(PTRUSTEEW pTrustee, POBJECTS_AND_NAME_W pObjName, SE_OBJECT_TYPE ObjectType, LPWSTR ObjectTypeName, LPWSTR InheritedObjectTypeName, LPWSTR Name)
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameW\n");
	return pBuildTrusteeWithObjectsAndNameW(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
}

extern WINAPI void wine32a_BuildTrusteeWithObjectsAndNameW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithObjectsAndNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithObjectsAndNameW") "\n"
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

extern WINAPI void wine32b_BuildTrusteeWithObjectsAndSidA(PTRUSTEEA pTrustee, POBJECTS_AND_SID pObjSid, GUID * pObjectGuid, GUID * pInheritedObjectGuid, PSID pSid)
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidA\n");
	return pBuildTrusteeWithObjectsAndSidA(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
}

extern WINAPI void wine32a_BuildTrusteeWithObjectsAndSidA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithObjectsAndSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithObjectsAndSidA") "\n"
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

extern WINAPI void wine32b_BuildTrusteeWithObjectsAndSidW(PTRUSTEEW pTrustee, POBJECTS_AND_SID pObjSid, GUID * pObjectGuid, GUID * pInheritedObjectGuid, PSID pSid)
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidW\n");
	return pBuildTrusteeWithObjectsAndSidW(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
}

extern WINAPI void wine32a_BuildTrusteeWithObjectsAndSidW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithObjectsAndSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithObjectsAndSidW") "\n"
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

extern WINAPI void wine32b_BuildTrusteeWithSidA(PTRUSTEEA pTrustee, PSID pSid)
{
	TRACE("Enter BuildTrusteeWithSidA\n");
	return pBuildTrusteeWithSidA(pTrustee, pSid);
}

extern WINAPI void wine32a_BuildTrusteeWithSidA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_BuildTrusteeWithSidW(PTRUSTEEW pTrustee, PSID pSid)
{
	TRACE("Enter BuildTrusteeWithSidW\n");
	return pBuildTrusteeWithSidW(pTrustee, pSid);
}

extern WINAPI void wine32a_BuildTrusteeWithSidW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_BuildTrusteeWithNameA(PTRUSTEEA pTrustee, LPSTR name)
{
	TRACE("Enter BuildTrusteeWithNameA\n");
	return pBuildTrusteeWithNameA(pTrustee, name);
}

extern WINAPI void wine32a_BuildTrusteeWithNameA(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_BuildTrusteeWithNameW(PTRUSTEEW pTrustee, LPWSTR name)
{
	TRACE("Enter BuildTrusteeWithNameW\n");
	return pBuildTrusteeWithNameW(pTrustee, name);
}

extern WINAPI void wine32a_BuildTrusteeWithNameW(void);
__ASM_GLOBAL_FUNC(wine32a_BuildTrusteeWithNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_BuildTrusteeWithNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_FORM wine32b_GetTrusteeFormA(PTRUSTEEA pTrustee)
{
	TRACE("Enter GetTrusteeFormA\n");
	return pGetTrusteeFormA(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeFormA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeFormA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeFormA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_FORM wine32b_GetTrusteeFormW(PTRUSTEEW pTrustee)
{
	TRACE("Enter GetTrusteeFormW\n");
	return pGetTrusteeFormW(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeFormW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeFormW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeFormW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_GetTrusteeNameA(PTRUSTEEA pTrustee)
{
	TRACE("Enter GetTrusteeNameA\n");
	return pGetTrusteeNameA(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeNameA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_GetTrusteeNameW(PTRUSTEEW pTrustee)
{
	TRACE("Enter GetTrusteeNameW\n");
	return pGetTrusteeNameW(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeNameW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_TYPE wine32b_GetTrusteeTypeA(PTRUSTEEA pTrustee)
{
	TRACE("Enter GetTrusteeTypeA\n");
	return pGetTrusteeTypeA(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeTypeA(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_TYPE wine32b_GetTrusteeTypeW(PTRUSTEEW pTrustee)
{
	TRACE("Enter GetTrusteeTypeW\n");
	return pGetTrusteeTypeW(pTrustee);
}

extern WINAPI void wine32a_GetTrusteeTypeW(void);
__ASM_GLOBAL_FUNC(wine32a_GetTrusteeTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetTrusteeTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_SetEntriesInAclA(ULONG count, PEXPLICIT_ACCESSA pEntries, PACL OldAcl, PACL * NewAcl)
{
	TRACE("Enter SetEntriesInAclA\n");
	return pSetEntriesInAclA(count, pEntries, OldAcl, NewAcl);
}

extern WINAPI void wine32a_SetEntriesInAclA(void);
__ASM_GLOBAL_FUNC(wine32a_SetEntriesInAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetEntriesInAclA") "\n"
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

extern WINAPI DWORD wine32b_SetEntriesInAclW(ULONG count, PEXPLICIT_ACCESSW pEntries, PACL OldAcl, PACL * NewAcl)
{
	TRACE("Enter SetEntriesInAclW\n");
	return pSetEntriesInAclW(count, pEntries, OldAcl, NewAcl);
}

extern WINAPI void wine32a_SetEntriesInAclW(void);
__ASM_GLOBAL_FUNC(wine32a_SetEntriesInAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetEntriesInAclW") "\n"
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

extern WINAPI DWORD wine32b_SetNamedSecurityInfoA(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl)
{
	TRACE("Enter SetNamedSecurityInfoA\n");
	return pSetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_SetNamedSecurityInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_SetNamedSecurityInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetNamedSecurityInfoA") "\n"
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

extern WINAPI DWORD wine32b_SetNamedSecurityInfoW(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl)
{
	TRACE("Enter SetNamedSecurityInfoW\n");
	return pSetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_SetNamedSecurityInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_SetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetNamedSecurityInfoW") "\n"
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

extern WINAPI DWORD wine32b_GetExplicitEntriesFromAclA(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESSA * pListOfExplicitEntries)
{
	TRACE("Enter GetExplicitEntriesFromAclA\n");
	return pGetExplicitEntriesFromAclA(pacl, pcCountOfExplicitEntries, pListOfExplicitEntries);
}

extern WINAPI void wine32a_GetExplicitEntriesFromAclA(void);
__ASM_GLOBAL_FUNC(wine32a_GetExplicitEntriesFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetExplicitEntriesFromAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetExplicitEntriesFromAclW(PACL pacl, PULONG count, PEXPLICIT_ACCESSW * list)
{
	TRACE("Enter GetExplicitEntriesFromAclW\n");
	return pGetExplicitEntriesFromAclW(pacl, count, list);
}

extern WINAPI void wine32a_GetExplicitEntriesFromAclW(void);
__ASM_GLOBAL_FUNC(wine32a_GetExplicitEntriesFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetExplicitEntriesFromAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_GetAuditedPermissionsFromAclA(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights)
{
	TRACE("Enter GetAuditedPermissionsFromAclA\n");
	return pGetAuditedPermissionsFromAclA(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
}

extern WINAPI void wine32a_GetAuditedPermissionsFromAclA(void);
__ASM_GLOBAL_FUNC(wine32a_GetAuditedPermissionsFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAuditedPermissionsFromAclA") "\n"
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

extern WINAPI DWORD wine32b_GetAuditedPermissionsFromAclW(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights)
{
	TRACE("Enter GetAuditedPermissionsFromAclW\n");
	return pGetAuditedPermissionsFromAclW(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
}

extern WINAPI void wine32a_GetAuditedPermissionsFromAclW(void);
__ASM_GLOBAL_FUNC(wine32a_GetAuditedPermissionsFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetAuditedPermissionsFromAclW") "\n"
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

extern WINAPI BOOL wine32b_ConvertStringSecurityDescriptorToSecurityDescriptorA(LPCSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR * SecurityDescriptor, PULONG SecurityDescriptorSize)
{
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorA\n");
	return pConvertStringSecurityDescriptorToSecurityDescriptorA(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
}

extern WINAPI void wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorA(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertStringSecurityDescriptorToSecurityDescriptorA") "\n"
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

extern WINAPI BOOL wine32b_ConvertStringSecurityDescriptorToSecurityDescriptorW(LPCWSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR * SecurityDescriptor, PULONG SecurityDescriptorSize)
{
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorW\n");
	return pConvertStringSecurityDescriptorToSecurityDescriptorW(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
}

extern WINAPI void wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorW(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertStringSecurityDescriptorToSecurityDescriptorW") "\n"
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

extern WINAPI BOOL wine32b_ConvertSecurityDescriptorToStringSecurityDescriptorW(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION RequestedInformation, LPWSTR * OutputString, PULONG OutputLen)
{
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorW\n");
	return pConvertSecurityDescriptorToStringSecurityDescriptorW(SecurityDescriptor, SDRevision, RequestedInformation, OutputString, OutputLen);
}

extern WINAPI void wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorW(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertSecurityDescriptorToStringSecurityDescriptorW") "\n"
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

extern WINAPI BOOL wine32b_ConvertSecurityDescriptorToStringSecurityDescriptorA(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION Information, LPSTR * OutputString, PULONG OutputLen)
{
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorA\n");
	return pConvertSecurityDescriptorToStringSecurityDescriptorA(SecurityDescriptor, SDRevision, Information, OutputString, OutputLen);
}

extern WINAPI void wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorA(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertSecurityDescriptorToStringSecurityDescriptorA") "\n"
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

extern WINAPI BOOL wine32b_ConvertStringSidToSidW(LPCWSTR StringSid, PSID * Sid)
{
	TRACE("Enter ConvertStringSidToSidW\n");
	return pConvertStringSidToSidW(StringSid, Sid);
}

extern WINAPI void wine32a_ConvertStringSidToSidW(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertStringSidToSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertStringSidToSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ConvertStringSidToSidA(LPCSTR StringSid, PSID * Sid)
{
	TRACE("Enter ConvertStringSidToSidA\n");
	return pConvertStringSidToSidA(StringSid, Sid);
}

extern WINAPI void wine32a_ConvertStringSidToSidA(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertStringSidToSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertStringSidToSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ConvertSidToStringSidW(PSID pSid, LPWSTR * pstr)
{
	TRACE("Enter ConvertSidToStringSidW\n");
	return pConvertSidToStringSidW(pSid, pstr);
}

extern WINAPI void wine32a_ConvertSidToStringSidW(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertSidToStringSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertSidToStringSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_ConvertSidToStringSidA(PSID pSid, LPSTR * pstr)
{
	TRACE("Enter ConvertSidToStringSidA\n");
	return pConvertSidToStringSidA(pSid, pstr);
}

extern WINAPI void wine32a_ConvertSidToStringSidA(void);
__ASM_GLOBAL_FUNC(wine32a_ConvertSidToStringSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ConvertSidToStringSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_CreateProcessWithLogonW(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation)
{
	TRACE("Enter CreateProcessWithLogonW\n");
	return pCreateProcessWithLogonW(lpUsername, lpDomain, lpPassword, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
}

extern WINAPI void wine32a_CreateProcessWithLogonW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessWithLogonW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessWithLogonW") "\n"
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

extern WINAPI BOOL wine32b_CreateProcessWithTokenW(HANDLE token, DWORD logon_flags, LPCWSTR application_name, LPWSTR command_line, DWORD creation_flags, void * environment, LPCWSTR current_directory, STARTUPINFOW * startup_info, PROCESS_INFORMATION * process_information)
{
	TRACE("Enter CreateProcessWithTokenW\n");
	return pCreateProcessWithTokenW(token, logon_flags, application_name, command_line, creation_flags, environment, current_directory, startup_info, process_information);
}

extern WINAPI void wine32a_CreateProcessWithTokenW(void);
__ASM_GLOBAL_FUNC(wine32a_CreateProcessWithTokenW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_CreateProcessWithTokenW") "\n"
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

extern WINAPI DWORD wine32b_GetNamedSecurityInfoA(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID * ppsidOwner, PSID * ppsidGroup, PACL * ppDacl, PACL * ppSacl, PSECURITY_DESCRIPTOR * ppSecurityDescriptor)
{
	TRACE("Enter GetNamedSecurityInfoA\n");
	return pGetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
}

extern WINAPI void wine32a_GetNamedSecurityInfoA(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedSecurityInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedSecurityInfoA") "\n"
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

extern WINAPI DWORD wine32b_GetNamedSecurityInfoW(LPWSTR name, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, PSID * owner, PSID * group, PACL * dacl, PACL * sacl, PSECURITY_DESCRIPTOR * descriptor)
{
	TRACE("Enter GetNamedSecurityInfoW\n");
	return pGetNamedSecurityInfoW(name, type, info, owner, group, dacl, sacl, descriptor);
}

extern WINAPI void wine32a_GetNamedSecurityInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedSecurityInfoW") "\n"
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

extern WINAPI DWORD wine32b_GetNamedSecurityInfoExW(LPCWSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCWSTR provider, LPCWSTR property, PACTRL_ACCESSW * access_list, PACTRL_AUDITW * audit_list, LPWSTR * owner, LPWSTR * group)
{
	TRACE("Enter GetNamedSecurityInfoExW\n");
	return pGetNamedSecurityInfoExW(object, type, info, provider, property, access_list, audit_list, owner, group);
}

extern WINAPI void wine32a_GetNamedSecurityInfoExW(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedSecurityInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedSecurityInfoExW") "\n"
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

extern WINAPI DWORD wine32b_GetNamedSecurityInfoExA(LPCSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCSTR provider, LPCSTR property, PACTRL_ACCESSA * access_list, PACTRL_AUDITA * audit_list, LPSTR * owner, LPSTR * group)
{
	TRACE("Enter GetNamedSecurityInfoExA\n");
	return pGetNamedSecurityInfoExA(object, type, info, provider, property, access_list, audit_list, owner, group);
}

extern WINAPI void wine32a_GetNamedSecurityInfoExA(void);
__ASM_GLOBAL_FUNC(wine32a_GetNamedSecurityInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_GetNamedSecurityInfoExA") "\n"
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

extern WINAPI BOOL wine32b_DecryptFileW(LPCWSTR lpFileName, DWORD dwReserved)
{
	TRACE("Enter DecryptFileW\n");
	return pDecryptFileW(lpFileName, dwReserved);
}

extern WINAPI void wine32a_DecryptFileW(void);
__ASM_GLOBAL_FUNC(wine32a_DecryptFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DecryptFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_DecryptFileA(LPCSTR lpFileName, DWORD dwReserved)
{
	TRACE("Enter DecryptFileA\n");
	return pDecryptFileA(lpFileName, dwReserved);
}

extern WINAPI void wine32a_DecryptFileA(void);
__ASM_GLOBAL_FUNC(wine32a_DecryptFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DecryptFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EncryptFileW(LPCWSTR lpFileName)
{
	TRACE("Enter EncryptFileW\n");
	return pEncryptFileW(lpFileName);
}

extern WINAPI void wine32a_EncryptFileW(void);
__ASM_GLOBAL_FUNC(wine32a_EncryptFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EncryptFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_EncryptFileA(LPCSTR lpFileName)
{
	TRACE("Enter EncryptFileA\n");
	return pEncryptFileA(lpFileName);
}

extern WINAPI void wine32a_EncryptFileA(void);
__ASM_GLOBAL_FUNC(wine32a_EncryptFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EncryptFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FileEncryptionStatusW(LPCWSTR lpFileName, LPDWORD lpStatus)
{
	TRACE("Enter FileEncryptionStatusW\n");
	return pFileEncryptionStatusW(lpFileName, lpStatus);
}

extern WINAPI void wine32a_FileEncryptionStatusW(void);
__ASM_GLOBAL_FUNC(wine32a_FileEncryptionStatusW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FileEncryptionStatusW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_FileEncryptionStatusA(LPCSTR lpFileName, LPDWORD lpStatus)
{
	TRACE("Enter FileEncryptionStatusA\n");
	return pFileEncryptionStatusA(lpFileName, lpStatus);
}

extern WINAPI void wine32a_FileEncryptionStatusA(void);
__ASM_GLOBAL_FUNC(wine32a_FileEncryptionStatusA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_FileEncryptionStatusA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_SetSecurityInfo(HANDLE handle, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl)
{
	TRACE("Enter SetSecurityInfo\n");
	return pSetSecurityInfo(handle, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_SetSecurityInfo(void);
__ASM_GLOBAL_FUNC(wine32a_SetSecurityInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SetSecurityInfo") "\n"
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

extern WINAPI BOOL wine32b_SaferCreateLevel(DWORD ScopeId, DWORD LevelId, DWORD OpenFlags, SAFER_LEVEL_HANDLE * LevelHandle, LPVOID lpReserved)
{
	TRACE("Enter SaferCreateLevel\n");
	return pSaferCreateLevel(ScopeId, LevelId, OpenFlags, LevelHandle, lpReserved);
}

extern WINAPI void wine32a_SaferCreateLevel(void);
__ASM_GLOBAL_FUNC(wine32a_SaferCreateLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferCreateLevel") "\n"
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

extern WINAPI BOOL wine32b_SaferComputeTokenFromLevel(SAFER_LEVEL_HANDLE handle, HANDLE token, PHANDLE access_token, DWORD flags, LPVOID reserved)
{
	TRACE("Enter SaferComputeTokenFromLevel\n");
	return pSaferComputeTokenFromLevel(handle, token, access_token, flags, reserved);
}

extern WINAPI void wine32a_SaferComputeTokenFromLevel(void);
__ASM_GLOBAL_FUNC(wine32a_SaferComputeTokenFromLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferComputeTokenFromLevel") "\n"
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

extern WINAPI BOOL wine32b_SaferCloseLevel(SAFER_LEVEL_HANDLE handle)
{
	TRACE("Enter SaferCloseLevel\n");
	return pSaferCloseLevel(handle);
}

extern WINAPI void wine32a_SaferCloseLevel(void);
__ASM_GLOBAL_FUNC(wine32a_SaferCloseLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferCloseLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_TreeResetNamedSecurityInfoW(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args)
{
	TRACE("Enter TreeResetNamedSecurityInfoW\n");
	return pTreeResetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, KeepExplicit, fnProgress, ProgressInvokeSetting, Args);
}

extern WINAPI void wine32a_TreeResetNamedSecurityInfoW(void);
__ASM_GLOBAL_FUNC(wine32a_TreeResetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TreeResetNamedSecurityInfoW") "\n"
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

extern WINAPI BOOL wine32b_SaferGetPolicyInformation(DWORD scope, SAFER_POLICY_INFO_CLASS class, DWORD size, PVOID buffer, PDWORD required, LPVOID lpReserved)
{
	TRACE("Enter SaferGetPolicyInformation\n");
	return pSaferGetPolicyInformation(scope, class, size, buffer, required, lpReserved);
}

extern WINAPI void wine32a_SaferGetPolicyInformation(void);
__ASM_GLOBAL_FUNC(wine32a_SaferGetPolicyInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferGetPolicyInformation") "\n"
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

extern WINAPI BOOL wine32b_SaferIdentifyLevel(DWORD count, SAFER_CODE_PROPERTIES * properties, SAFER_LEVEL_HANDLE * handle, void * reserved)
{
	TRACE("Enter SaferIdentifyLevel\n");
	return pSaferIdentifyLevel(count, properties, handle, reserved);
}

extern WINAPI void wine32a_SaferIdentifyLevel(void);
__ASM_GLOBAL_FUNC(wine32a_SaferIdentifyLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferIdentifyLevel") "\n"
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

extern WINAPI BOOL wine32b_SaferSetLevelInformation(SAFER_LEVEL_HANDLE handle, SAFER_OBJECT_INFO_CLASS infotype, LPVOID buffer, DWORD size)
{
	TRACE("Enter SaferSetLevelInformation\n");
	return pSaferSetLevelInformation(handle, infotype, buffer, size);
}

extern WINAPI void wine32a_SaferSetLevelInformation(void);
__ASM_GLOBAL_FUNC(wine32a_SaferSetLevelInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_SaferSetLevelInformation") "\n"
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

extern WINAPI DWORD wine32b_LookupSecurityDescriptorPartsA(TRUSTEEA * owner, TRUSTEEA * group, ULONG * access_count, EXPLICIT_ACCESSA * access_list, ULONG * audit_count, EXPLICIT_ACCESSA * audit_list, SECURITY_DESCRIPTOR * descriptor)
{
	TRACE("Enter LookupSecurityDescriptorPartsA\n");
	return pLookupSecurityDescriptorPartsA(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
}

extern WINAPI void wine32a_LookupSecurityDescriptorPartsA(void);
__ASM_GLOBAL_FUNC(wine32a_LookupSecurityDescriptorPartsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupSecurityDescriptorPartsA") "\n"
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

extern WINAPI DWORD wine32b_LookupSecurityDescriptorPartsW(TRUSTEEW * owner, TRUSTEEW * group, ULONG * access_count, EXPLICIT_ACCESSW * access_list, ULONG * audit_count, EXPLICIT_ACCESSW * audit_list, SECURITY_DESCRIPTOR * descriptor)
{
	TRACE("Enter LookupSecurityDescriptorPartsW\n");
	return pLookupSecurityDescriptorPartsW(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
}

extern WINAPI void wine32a_LookupSecurityDescriptorPartsW(void);
__ASM_GLOBAL_FUNC(wine32a_LookupSecurityDescriptorPartsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LookupSecurityDescriptorPartsW") "\n"
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


static WINAPI ULONG (*pWmiExecuteMethodA)(WMIHANDLE handle, const char * name, ULONG method, ULONG inputsize, void * inputbuffer, ULONG * outputsize, void * outputbuffer);
static WINAPI ULONG (*pWmiExecuteMethodW)(WMIHANDLE handle, const WCHAR * name, ULONG method, ULONG inputsize, void * inputbuffer, ULONG * outputsize, void * outputbuffer);
static WINAPI void (*pWmiFreeBuffer)(void * buffer);
static WINAPI ULONG (*pWmiMofEnumerateResourcesA)(MOFHANDLE handle, ULONG * count, MOFRESOURCEINFOA ** resource);
static WINAPI ULONG (*pWmiMofEnumerateResourcesW)(MOFHANDLE handle, ULONG * count, MOFRESOURCEINFOW ** resource);
static WINAPI ULONG (*pWmiNotificationRegistrationA)(GUID * guid, BOOLEAN enable, void * info, ULONG_PTR context, ULONG flags);
static WINAPI ULONG (*pWmiNotificationRegistrationW)(GUID * guid, BOOLEAN enable, void * info, ULONG_PTR context, ULONG flags);
static WINAPI ULONG (*pWmiOpenBlock)(GUID * guid, ULONG access, WMIHANDLE * handle);
static WINAPI ULONG (*pWmiQueryAllDataA)(WMIHANDLE handle, ULONG * size, void * buffer);
static WINAPI ULONG (*pWmiQueryAllDataW)(WMIHANDLE handle, ULONG * size, void * buffer);
static WINAPI ULONG (*pWmiQueryGuidInformation)(WMIHANDLE handle, WMIGUIDINFORMATION * info);
static WINAPI ULONG (*pWmiSetSingleInstanceA)(WMIHANDLE handle, const char * name, ULONG reserved, ULONG size, void * buffer);
static WINAPI ULONG (*pWmiSetSingleInstanceW)(WMIHANDLE handle, const WCHAR * name, ULONG reserved, ULONG size, void * buffer);
static WINAPI ULONG (*pWmiSetSingleItemA)(WMIHANDLE handle, const char * name, ULONG id, ULONG reserved, ULONG size, void * buffer);
static WINAPI ULONG (*pWmiSetSingleItemW)(WMIHANDLE handle, const WCHAR * name, ULONG id, ULONG reserved, ULONG size, void * buffer);

extern WINAPI ULONG wine32b_WmiExecuteMethodA(WMIHANDLE handle, const char * name, ULONG method, ULONG inputsize, void * inputbuffer, ULONG * outputsize, void * outputbuffer)
{
	TRACE("Enter WmiExecuteMethodA\n");
	return pWmiExecuteMethodA(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
}

extern WINAPI void wine32a_WmiExecuteMethodA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiExecuteMethodA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiExecuteMethodA") "\n"
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

extern WINAPI ULONG wine32b_WmiExecuteMethodW(WMIHANDLE handle, const WCHAR * name, ULONG method, ULONG inputsize, void * inputbuffer, ULONG * outputsize, void * outputbuffer)
{
	TRACE("Enter WmiExecuteMethodW\n");
	return pWmiExecuteMethodW(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
}

extern WINAPI void wine32a_WmiExecuteMethodW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiExecuteMethodW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiExecuteMethodW") "\n"
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

extern WINAPI void wine32b_WmiFreeBuffer(void * buffer)
{
	TRACE("Enter WmiFreeBuffer\n");
	return pWmiFreeBuffer(buffer);
}

extern WINAPI void wine32a_WmiFreeBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_WmiFreeBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiFreeBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiMofEnumerateResourcesA(MOFHANDLE handle, ULONG * count, MOFRESOURCEINFOA ** resource)
{
	TRACE("Enter WmiMofEnumerateResourcesA\n");
	return pWmiMofEnumerateResourcesA(handle, count, resource);
}

extern WINAPI void wine32a_WmiMofEnumerateResourcesA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiMofEnumerateResourcesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiMofEnumerateResourcesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiMofEnumerateResourcesW(MOFHANDLE handle, ULONG * count, MOFRESOURCEINFOW ** resource)
{
	TRACE("Enter WmiMofEnumerateResourcesW\n");
	return pWmiMofEnumerateResourcesW(handle, count, resource);
}

extern WINAPI void wine32a_WmiMofEnumerateResourcesW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiMofEnumerateResourcesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiMofEnumerateResourcesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiNotificationRegistrationA(GUID * guid, BOOLEAN enable, void * info, ULONG_PTR context, ULONG flags)
{
	TRACE("Enter WmiNotificationRegistrationA\n");
	return pWmiNotificationRegistrationA(guid, enable, info, context, flags);
}

extern WINAPI void wine32a_WmiNotificationRegistrationA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiNotificationRegistrationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiNotificationRegistrationA") "\n"
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

extern WINAPI ULONG wine32b_WmiNotificationRegistrationW(GUID * guid, BOOLEAN enable, void * info, ULONG_PTR context, ULONG flags)
{
	TRACE("Enter WmiNotificationRegistrationW\n");
	return pWmiNotificationRegistrationW(guid, enable, info, context, flags);
}

extern WINAPI void wine32a_WmiNotificationRegistrationW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiNotificationRegistrationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiNotificationRegistrationW") "\n"
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

extern WINAPI ULONG wine32b_WmiOpenBlock(GUID * guid, ULONG access, WMIHANDLE * handle)
{
	TRACE("Enter WmiOpenBlock\n");
	return pWmiOpenBlock(guid, access, handle);
}

extern WINAPI void wine32a_WmiOpenBlock(void);
__ASM_GLOBAL_FUNC(wine32a_WmiOpenBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiOpenBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiQueryAllDataA(WMIHANDLE handle, ULONG * size, void * buffer)
{
	TRACE("Enter WmiQueryAllDataA\n");
	return pWmiQueryAllDataA(handle, size, buffer);
}

extern WINAPI void wine32a_WmiQueryAllDataA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiQueryAllDataA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiQueryAllDataA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiQueryAllDataW(WMIHANDLE handle, ULONG * size, void * buffer)
{
	TRACE("Enter WmiQueryAllDataW\n");
	return pWmiQueryAllDataW(handle, size, buffer);
}

extern WINAPI void wine32a_WmiQueryAllDataW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiQueryAllDataW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiQueryAllDataW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiQueryGuidInformation(WMIHANDLE handle, WMIGUIDINFORMATION * info)
{
	TRACE("Enter WmiQueryGuidInformation\n");
	return pWmiQueryGuidInformation(handle, info);
}

extern WINAPI void wine32a_WmiQueryGuidInformation(void);
__ASM_GLOBAL_FUNC(wine32a_WmiQueryGuidInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiQueryGuidInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_WmiSetSingleInstanceA(WMIHANDLE handle, const char * name, ULONG reserved, ULONG size, void * buffer)
{
	TRACE("Enter WmiSetSingleInstanceA\n");
	return pWmiSetSingleInstanceA(handle, name, reserved, size, buffer);
}

extern WINAPI void wine32a_WmiSetSingleInstanceA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiSetSingleInstanceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiSetSingleInstanceA") "\n"
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

extern WINAPI ULONG wine32b_WmiSetSingleInstanceW(WMIHANDLE handle, const WCHAR * name, ULONG reserved, ULONG size, void * buffer)
{
	TRACE("Enter WmiSetSingleInstanceW\n");
	return pWmiSetSingleInstanceW(handle, name, reserved, size, buffer);
}

extern WINAPI void wine32a_WmiSetSingleInstanceW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiSetSingleInstanceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiSetSingleInstanceW") "\n"
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

extern WINAPI ULONG wine32b_WmiSetSingleItemA(WMIHANDLE handle, const char * name, ULONG id, ULONG reserved, ULONG size, void * buffer)
{
	TRACE("Enter WmiSetSingleItemA\n");
	return pWmiSetSingleItemA(handle, name, id, reserved, size, buffer);
}

extern WINAPI void wine32a_WmiSetSingleItemA(void);
__ASM_GLOBAL_FUNC(wine32a_WmiSetSingleItemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiSetSingleItemA") "\n"
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

extern WINAPI ULONG wine32b_WmiSetSingleItemW(WMIHANDLE handle, const WCHAR * name, ULONG id, ULONG reserved, ULONG size, void * buffer)
{
	TRACE("Enter WmiSetSingleItemW\n");
	return pWmiSetSingleItemW(handle, name, id, reserved, size, buffer);
}

extern WINAPI void wine32a_WmiSetSingleItemW(void);
__ASM_GLOBAL_FUNC(wine32a_WmiSetSingleItemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WmiSetSingleItemW") "\n"
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

void wine_thunk_initialize_advapi32(void)
{
	HMODULE library = LoadLibraryA("advapi32.dll");
	pGetUserNameA = (void *)GetProcAddress(library, "GetUserNameA");
	pGetUserNameW = (void *)GetProcAddress(library, "GetUserNameW");
	pGetCurrentHwProfileA = (void *)GetProcAddress(library, "GetCurrentHwProfileA");
	pGetCurrentHwProfileW = (void *)GetProcAddress(library, "GetCurrentHwProfileW");
	pIsTextUnicode = (void *)GetProcAddress(library, "IsTextUnicode");
	pAbortSystemShutdownA = (void *)GetProcAddress(library, "AbortSystemShutdownA");
	pAbortSystemShutdownW = (void *)GetProcAddress(library, "AbortSystemShutdownW");
	pInitiateSystemShutdownExA = (void *)GetProcAddress(library, "InitiateSystemShutdownExA");
	pInitiateSystemShutdownExW = (void *)GetProcAddress(library, "InitiateSystemShutdownExW");
	pInitiateSystemShutdownA = (void *)GetProcAddress(library, "InitiateSystemShutdownA");
	pInitiateSystemShutdownW = (void *)GetProcAddress(library, "InitiateSystemShutdownW");
	pInitiateShutdownA = (void *)GetProcAddress(library, "InitiateShutdownA");
	pInitiateShutdownW = (void *)GetProcAddress(library, "InitiateShutdownW");
	pLogonUserA = (void *)GetProcAddress(library, "LogonUserA");
	pLogonUserW = (void *)GetProcAddress(library, "LogonUserW");
	pCommandLineFromMsiDescriptor = (void *)GetProcAddress(library, "CommandLineFromMsiDescriptor");
	pRegisterWaitChainCOMCallback = (void *)GetProcAddress(library, "RegisterWaitChainCOMCallback");
	pCredDeleteA = (void *)GetProcAddress(library, "CredDeleteA");
	pCredDeleteW = (void *)GetProcAddress(library, "CredDeleteW");
	pCredEnumerateA = (void *)GetProcAddress(library, "CredEnumerateA");
	pCredEnumerateW = (void *)GetProcAddress(library, "CredEnumerateW");
	pCredFree = (void *)GetProcAddress(library, "CredFree");
	pCredReadA = (void *)GetProcAddress(library, "CredReadA");
	pCredReadW = (void *)GetProcAddress(library, "CredReadW");
	pCredReadDomainCredentialsA = (void *)GetProcAddress(library, "CredReadDomainCredentialsA");
	pCredReadDomainCredentialsW = (void *)GetProcAddress(library, "CredReadDomainCredentialsW");
	pCredWriteA = (void *)GetProcAddress(library, "CredWriteA");
	pCredWriteW = (void *)GetProcAddress(library, "CredWriteW");
	pCredGetSessionTypes = (void *)GetProcAddress(library, "CredGetSessionTypes");
	pCredMarshalCredentialA = (void *)GetProcAddress(library, "CredMarshalCredentialA");
	pCredMarshalCredentialW = (void *)GetProcAddress(library, "CredMarshalCredentialW");
	pCredUnmarshalCredentialA = (void *)GetProcAddress(library, "CredUnmarshalCredentialA");
	pCredUnmarshalCredentialW = (void *)GetProcAddress(library, "CredUnmarshalCredentialW");
	pCredIsMarshaledCredentialW = (void *)GetProcAddress(library, "CredIsMarshaledCredentialW");
	pCredIsMarshaledCredentialA = (void *)GetProcAddress(library, "CredIsMarshaledCredentialA");
	pCloseEncryptedFileRaw = (void *)GetProcAddress(library, "CloseEncryptedFileRaw");
	pCryptAcquireContextW = (void *)GetProcAddress(library, "CryptAcquireContextW");
	pCryptAcquireContextA = (void *)GetProcAddress(library, "CryptAcquireContextA");
	pCryptContextAddRef = (void *)GetProcAddress(library, "CryptContextAddRef");
	pCryptReleaseContext = (void *)GetProcAddress(library, "CryptReleaseContext");
	pCryptGenRandom = (void *)GetProcAddress(library, "CryptGenRandom");
	pCryptCreateHash = (void *)GetProcAddress(library, "CryptCreateHash");
	pCryptDecrypt = (void *)GetProcAddress(library, "CryptDecrypt");
	pCryptDeriveKey = (void *)GetProcAddress(library, "CryptDeriveKey");
	pCryptDestroyHash = (void *)GetProcAddress(library, "CryptDestroyHash");
	pCryptDestroyKey = (void *)GetProcAddress(library, "CryptDestroyKey");
	pCryptDuplicateHash = (void *)GetProcAddress(library, "CryptDuplicateHash");
	pCryptDuplicateKey = (void *)GetProcAddress(library, "CryptDuplicateKey");
	pCryptEncrypt = (void *)GetProcAddress(library, "CryptEncrypt");
	pCryptEnumProvidersW = (void *)GetProcAddress(library, "CryptEnumProvidersW");
	pCryptEnumProvidersA = (void *)GetProcAddress(library, "CryptEnumProvidersA");
	pCryptEnumProviderTypesW = (void *)GetProcAddress(library, "CryptEnumProviderTypesW");
	pCryptEnumProviderTypesA = (void *)GetProcAddress(library, "CryptEnumProviderTypesA");
	pCryptExportKey = (void *)GetProcAddress(library, "CryptExportKey");
	pCryptGenKey = (void *)GetProcAddress(library, "CryptGenKey");
	pCryptGetDefaultProviderW = (void *)GetProcAddress(library, "CryptGetDefaultProviderW");
	pCryptGetDefaultProviderA = (void *)GetProcAddress(library, "CryptGetDefaultProviderA");
	pCryptGetHashParam = (void *)GetProcAddress(library, "CryptGetHashParam");
	pCryptGetKeyParam = (void *)GetProcAddress(library, "CryptGetKeyParam");
	pCryptGetProvParam = (void *)GetProcAddress(library, "CryptGetProvParam");
	pCryptGetUserKey = (void *)GetProcAddress(library, "CryptGetUserKey");
	pCryptHashData = (void *)GetProcAddress(library, "CryptHashData");
	pCryptHashSessionKey = (void *)GetProcAddress(library, "CryptHashSessionKey");
	pCryptImportKey = (void *)GetProcAddress(library, "CryptImportKey");
	pCryptSignHashW = (void *)GetProcAddress(library, "CryptSignHashW");
	pCryptSignHashA = (void *)GetProcAddress(library, "CryptSignHashA");
	pCryptSetHashParam = (void *)GetProcAddress(library, "CryptSetHashParam");
	pCryptSetKeyParam = (void *)GetProcAddress(library, "CryptSetKeyParam");
	pCryptSetProviderA = (void *)GetProcAddress(library, "CryptSetProviderA");
	pCryptSetProviderW = (void *)GetProcAddress(library, "CryptSetProviderW");
	pCryptSetProviderExW = (void *)GetProcAddress(library, "CryptSetProviderExW");
	pCryptSetProviderExA = (void *)GetProcAddress(library, "CryptSetProviderExA");
	pCryptSetProvParam = (void *)GetProcAddress(library, "CryptSetProvParam");
	pCryptVerifySignatureW = (void *)GetProcAddress(library, "CryptVerifySignatureW");
	pCryptVerifySignatureA = (void *)GetProcAddress(library, "CryptVerifySignatureA");
	pOpenEncryptedFileRawA = (void *)GetProcAddress(library, "OpenEncryptedFileRawA");
	pOpenEncryptedFileRawW = (void *)GetProcAddress(library, "OpenEncryptedFileRawW");
	pReadEncryptedFileRaw = (void *)GetProcAddress(library, "ReadEncryptedFileRaw");
	pSystemFunction007 = (void *)GetProcAddress(library, "SystemFunction007");
	pSystemFunction010 = (void *)GetProcAddress(library, "SystemFunction010");
	pSystemFunction030 = (void *)GetProcAddress(library, "SystemFunction030");
	pSystemFunction035 = (void *)GetProcAddress(library, "SystemFunction035");
	pSystemFunction036 = (void *)GetProcAddress(library, "SystemFunction036");
	pSystemFunction040 = (void *)GetProcAddress(library, "SystemFunction040");
	pSystemFunction041 = (void *)GetProcAddress(library, "SystemFunction041");
	pWriteEncryptedFileRaw = (void *)GetProcAddress(library, "WriteEncryptedFileRaw");
	pSystemFunction032 = (void *)GetProcAddress(library, "SystemFunction032");
	pSystemFunction006 = (void *)GetProcAddress(library, "SystemFunction006");
	pSystemFunction008 = (void *)GetProcAddress(library, "SystemFunction008");
	pSystemFunction009 = (void *)GetProcAddress(library, "SystemFunction009");
	pSystemFunction001 = (void *)GetProcAddress(library, "SystemFunction001");
	pSystemFunction002 = (void *)GetProcAddress(library, "SystemFunction002");
	pSystemFunction003 = (void *)GetProcAddress(library, "SystemFunction003");
	pSystemFunction004 = (void *)GetProcAddress(library, "SystemFunction004");
	pSystemFunction005 = (void *)GetProcAddress(library, "SystemFunction005");
	pSystemFunction012 = (void *)GetProcAddress(library, "SystemFunction012");
	pSystemFunction013 = (void *)GetProcAddress(library, "SystemFunction013");
	pSystemFunction024 = (void *)GetProcAddress(library, "SystemFunction024");
	pSystemFunction025 = (void *)GetProcAddress(library, "SystemFunction025");
	pBackupEventLogA = (void *)GetProcAddress(library, "BackupEventLogA");
	pBackupEventLogW = (void *)GetProcAddress(library, "BackupEventLogW");
	pClearEventLogA = (void *)GetProcAddress(library, "ClearEventLogA");
	pClearEventLogW = (void *)GetProcAddress(library, "ClearEventLogW");
	pCloseEventLog = (void *)GetProcAddress(library, "CloseEventLog");
	pControlTraceW = (void *)GetProcAddress(library, "ControlTraceW");
	pControlTraceA = (void *)GetProcAddress(library, "ControlTraceA");
	pFlushTraceA = (void *)GetProcAddress(library, "FlushTraceA");
	pFlushTraceW = (void *)GetProcAddress(library, "FlushTraceW");
	pDeregisterEventSource = (void *)GetProcAddress(library, "DeregisterEventSource");
	pEnableTraceEx = (void *)GetProcAddress(library, "EnableTraceEx");
	pEnableTraceEx2 = (void *)GetProcAddress(library, "EnableTraceEx2");
	pEnableTrace = (void *)GetProcAddress(library, "EnableTrace");
	pGetEventLogInformation = (void *)GetProcAddress(library, "GetEventLogInformation");
	pGetNumberOfEventLogRecords = (void *)GetProcAddress(library, "GetNumberOfEventLogRecords");
	pGetOldestEventLogRecord = (void *)GetProcAddress(library, "GetOldestEventLogRecord");
	pNotifyChangeEventLog = (void *)GetProcAddress(library, "NotifyChangeEventLog");
	pOpenBackupEventLogA = (void *)GetProcAddress(library, "OpenBackupEventLogA");
	pOpenBackupEventLogW = (void *)GetProcAddress(library, "OpenBackupEventLogW");
	pOpenEventLogA = (void *)GetProcAddress(library, "OpenEventLogA");
	pOpenEventLogW = (void *)GetProcAddress(library, "OpenEventLogW");
	pQueryAllTracesW = (void *)GetProcAddress(library, "QueryAllTracesW");
	pQueryAllTracesA = (void *)GetProcAddress(library, "QueryAllTracesA");
	pReadEventLogA = (void *)GetProcAddress(library, "ReadEventLogA");
	pReadEventLogW = (void *)GetProcAddress(library, "ReadEventLogW");
	pRegisterEventSourceA = (void *)GetProcAddress(library, "RegisterEventSourceA");
	pRegisterEventSourceW = (void *)GetProcAddress(library, "RegisterEventSourceW");
	pReportEventA = (void *)GetProcAddress(library, "ReportEventA");
	pReportEventW = (void *)GetProcAddress(library, "ReportEventW");
	pStartTraceW = (void *)GetProcAddress(library, "StartTraceW");
	pStartTraceA = (void *)GetProcAddress(library, "StartTraceA");
	pStopTraceW = (void *)GetProcAddress(library, "StopTraceW");
	pStopTraceA = (void *)GetProcAddress(library, "StopTraceA");
	pQueryTraceW = (void *)GetProcAddress(library, "QueryTraceW");
	pOpenTraceA = (void *)GetProcAddress(library, "OpenTraceA");
	pOpenTraceW = (void *)GetProcAddress(library, "OpenTraceW");
	pProcessTrace = (void *)GetProcAddress(library, "ProcessTrace");
	pCloseTrace = (void *)GetProcAddress(library, "CloseTrace");
	pEnumerateTraceGuids = (void *)GetProcAddress(library, "EnumerateTraceGuids");
	pTraceSetInformation = (void *)GetProcAddress(library, "TraceSetInformation");
	pLsaAddAccountRights = (void *)GetProcAddress(library, "LsaAddAccountRights");
	pLsaClose = (void *)GetProcAddress(library, "LsaClose");
	pLsaCreateTrustedDomainEx = (void *)GetProcAddress(library, "LsaCreateTrustedDomainEx");
	pLsaDeleteTrustedDomain = (void *)GetProcAddress(library, "LsaDeleteTrustedDomain");
	pLsaEnumerateAccountRights = (void *)GetProcAddress(library, "LsaEnumerateAccountRights");
	pLsaEnumerateAccountsWithUserRight = (void *)GetProcAddress(library, "LsaEnumerateAccountsWithUserRight");
	pLsaEnumerateTrustedDomains = (void *)GetProcAddress(library, "LsaEnumerateTrustedDomains");
	pLsaEnumerateTrustedDomainsEx = (void *)GetProcAddress(library, "LsaEnumerateTrustedDomainsEx");
	pLsaFreeMemory = (void *)GetProcAddress(library, "LsaFreeMemory");
	pLsaLookupNames = (void *)GetProcAddress(library, "LsaLookupNames");
	pLsaLookupNames2 = (void *)GetProcAddress(library, "LsaLookupNames2");
	pLsaLookupSids = (void *)GetProcAddress(library, "LsaLookupSids");
	pLsaNtStatusToWinError = (void *)GetProcAddress(library, "LsaNtStatusToWinError");
	pLsaOpenPolicy = (void *)GetProcAddress(library, "LsaOpenPolicy");
	pLsaOpenTrustedDomainByName = (void *)GetProcAddress(library, "LsaOpenTrustedDomainByName");
	pLsaQueryInformationPolicy = (void *)GetProcAddress(library, "LsaQueryInformationPolicy");
	pLsaQueryTrustedDomainInfo = (void *)GetProcAddress(library, "LsaQueryTrustedDomainInfo");
	pLsaQueryTrustedDomainInfoByName = (void *)GetProcAddress(library, "LsaQueryTrustedDomainInfoByName");
	pLsaRegisterPolicyChangeNotification = (void *)GetProcAddress(library, "LsaRegisterPolicyChangeNotification");
	pLsaRemoveAccountRights = (void *)GetProcAddress(library, "LsaRemoveAccountRights");
	pLsaRetrievePrivateData = (void *)GetProcAddress(library, "LsaRetrievePrivateData");
	pLsaSetInformationPolicy = (void *)GetProcAddress(library, "LsaSetInformationPolicy");
	pLsaSetSecret = (void *)GetProcAddress(library, "LsaSetSecret");
	pLsaSetTrustedDomainInfoByName = (void *)GetProcAddress(library, "LsaSetTrustedDomainInfoByName");
	pLsaSetTrustedDomainInformation = (void *)GetProcAddress(library, "LsaSetTrustedDomainInformation");
	pLsaStorePrivateData = (void *)GetProcAddress(library, "LsaStorePrivateData");
	pLsaUnregisterPolicyChangeNotification = (void *)GetProcAddress(library, "LsaUnregisterPolicyChangeNotification");
	pLsaLookupPrivilegeName = (void *)GetProcAddress(library, "LsaLookupPrivilegeName");
	pLsaLookupPrivilegeDisplayName = (void *)GetProcAddress(library, "LsaLookupPrivilegeDisplayName");
	pAuditQuerySystemPolicy = (void *)GetProcAddress(library, "AuditQuerySystemPolicy");
	pRegOverridePredefKey = (void *)GetProcAddress(library, "RegOverridePredefKey");
	pRegCreateKeyW = (void *)GetProcAddress(library, "RegCreateKeyW");
	pRegCreateKeyA = (void *)GetProcAddress(library, "RegCreateKeyA");
	pRegCreateKeyTransactedW = (void *)GetProcAddress(library, "RegCreateKeyTransactedW");
	pRegCreateKeyTransactedA = (void *)GetProcAddress(library, "RegCreateKeyTransactedA");
	pRegOpenKeyW = (void *)GetProcAddress(library, "RegOpenKeyW");
	pRegOpenKeyA = (void *)GetProcAddress(library, "RegOpenKeyA");
	pRegEnumKeyW = (void *)GetProcAddress(library, "RegEnumKeyW");
	pRegEnumKeyA = (void *)GetProcAddress(library, "RegEnumKeyA");
	pRegQueryMultipleValuesA = (void *)GetProcAddress(library, "RegQueryMultipleValuesA");
	pRegQueryMultipleValuesW = (void *)GetProcAddress(library, "RegQueryMultipleValuesW");
	pRegQueryReflectionKey = (void *)GetProcAddress(library, "RegQueryReflectionKey");
	pRegDeleteKeyW = (void *)GetProcAddress(library, "RegDeleteKeyW");
	pRegDeleteKeyA = (void *)GetProcAddress(library, "RegDeleteKeyA");
	pRegSetValueW = (void *)GetProcAddress(library, "RegSetValueW");
	pRegSetValueA = (void *)GetProcAddress(library, "RegSetValueA");
	pRegQueryValueW = (void *)GetProcAddress(library, "RegQueryValueW");
	pRegQueryValueA = (void *)GetProcAddress(library, "RegQueryValueA");
	pRegSaveKeyW = (void *)GetProcAddress(library, "RegSaveKeyW");
	pRegSaveKeyA = (void *)GetProcAddress(library, "RegSaveKeyA");
	pRegReplaceKeyW = (void *)GetProcAddress(library, "RegReplaceKeyW");
	pRegReplaceKeyA = (void *)GetProcAddress(library, "RegReplaceKeyA");
	pRegConnectRegistryW = (void *)GetProcAddress(library, "RegConnectRegistryW");
	pRegConnectRegistryA = (void *)GetProcAddress(library, "RegConnectRegistryA");
	pRegDisablePredefinedCache = (void *)GetProcAddress(library, "RegDisablePredefinedCache");
	pRegCopyTreeA = (void *)GetProcAddress(library, "RegCopyTreeA");
	pRegDisableReflectionKey = (void *)GetProcAddress(library, "RegDisableReflectionKey");
	pGetEffectiveRightsFromAclA = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclA");
	pGetEffectiveRightsFromAclW = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclW");
	pBuildSecurityDescriptorA = (void *)GetProcAddress(library, "BuildSecurityDescriptorA");
	pBuildSecurityDescriptorW = (void *)GetProcAddress(library, "BuildSecurityDescriptorW");
	pLookupPrivilegeValueW = (void *)GetProcAddress(library, "LookupPrivilegeValueW");
	pLookupPrivilegeValueA = (void *)GetProcAddress(library, "LookupPrivilegeValueA");
	pLookupPrivilegeDisplayNameA = (void *)GetProcAddress(library, "LookupPrivilegeDisplayNameA");
	pLookupPrivilegeDisplayNameW = (void *)GetProcAddress(library, "LookupPrivilegeDisplayNameW");
	pLookupPrivilegeNameA = (void *)GetProcAddress(library, "LookupPrivilegeNameA");
	pLookupPrivilegeNameW = (void *)GetProcAddress(library, "LookupPrivilegeNameW");
	pGetFileSecurityA = (void *)GetProcAddress(library, "GetFileSecurityA");
	pLookupAccountSidA = (void *)GetProcAddress(library, "LookupAccountSidA");
	pLookupAccountSidLocalA = (void *)GetProcAddress(library, "LookupAccountSidLocalA");
	pLookupAccountSidW = (void *)GetProcAddress(library, "LookupAccountSidW");
	pLookupAccountSidLocalW = (void *)GetProcAddress(library, "LookupAccountSidLocalW");
	pSetFileSecurityA = (void *)GetProcAddress(library, "SetFileSecurityA");
	pQueryWindows31FilesMigration = (void *)GetProcAddress(library, "QueryWindows31FilesMigration");
	pSynchronizeWindows31FilesAndWindowsNTRegistry = (void *)GetProcAddress(library, "SynchronizeWindows31FilesAndWindowsNTRegistry");
	pNotifyBootConfigStatus = (void *)GetProcAddress(library, "NotifyBootConfigStatus");
	pLookupAccountNameA = (void *)GetProcAddress(library, "LookupAccountNameA");
	pLookupAccountNameW = (void *)GetProcAddress(library, "LookupAccountNameW");
	pAccessCheckAndAuditAlarmA = (void *)GetProcAddress(library, "AccessCheckAndAuditAlarmA");
	pObjectCloseAuditAlarmA = (void *)GetProcAddress(library, "ObjectCloseAuditAlarmA");
	pObjectOpenAuditAlarmA = (void *)GetProcAddress(library, "ObjectOpenAuditAlarmA");
	pObjectPrivilegeAuditAlarmA = (void *)GetProcAddress(library, "ObjectPrivilegeAuditAlarmA");
	pPrivilegedServiceAuditAlarmA = (void *)GetProcAddress(library, "PrivilegedServiceAuditAlarmA");
	pGetSecurityInfo = (void *)GetProcAddress(library, "GetSecurityInfo");
	pGetSecurityInfoExA = (void *)GetProcAddress(library, "GetSecurityInfoExA");
	pGetSecurityInfoExW = (void *)GetProcAddress(library, "GetSecurityInfoExW");
	pBuildExplicitAccessWithNameA = (void *)GetProcAddress(library, "BuildExplicitAccessWithNameA");
	pBuildExplicitAccessWithNameW = (void *)GetProcAddress(library, "BuildExplicitAccessWithNameW");
	pBuildTrusteeWithObjectsAndNameA = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndNameA");
	pBuildTrusteeWithObjectsAndNameW = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndNameW");
	pBuildTrusteeWithObjectsAndSidA = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndSidA");
	pBuildTrusteeWithObjectsAndSidW = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndSidW");
	pBuildTrusteeWithSidA = (void *)GetProcAddress(library, "BuildTrusteeWithSidA");
	pBuildTrusteeWithSidW = (void *)GetProcAddress(library, "BuildTrusteeWithSidW");
	pBuildTrusteeWithNameA = (void *)GetProcAddress(library, "BuildTrusteeWithNameA");
	pBuildTrusteeWithNameW = (void *)GetProcAddress(library, "BuildTrusteeWithNameW");
	pGetTrusteeFormA = (void *)GetProcAddress(library, "GetTrusteeFormA");
	pGetTrusteeFormW = (void *)GetProcAddress(library, "GetTrusteeFormW");
	pGetTrusteeNameA = (void *)GetProcAddress(library, "GetTrusteeNameA");
	pGetTrusteeNameW = (void *)GetProcAddress(library, "GetTrusteeNameW");
	pGetTrusteeTypeA = (void *)GetProcAddress(library, "GetTrusteeTypeA");
	pGetTrusteeTypeW = (void *)GetProcAddress(library, "GetTrusteeTypeW");
	pSetEntriesInAclA = (void *)GetProcAddress(library, "SetEntriesInAclA");
	pSetEntriesInAclW = (void *)GetProcAddress(library, "SetEntriesInAclW");
	pSetNamedSecurityInfoA = (void *)GetProcAddress(library, "SetNamedSecurityInfoA");
	pSetNamedSecurityInfoW = (void *)GetProcAddress(library, "SetNamedSecurityInfoW");
	pGetExplicitEntriesFromAclA = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclA");
	pGetExplicitEntriesFromAclW = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclW");
	pGetAuditedPermissionsFromAclA = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclA");
	pGetAuditedPermissionsFromAclW = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclW");
	pConvertStringSecurityDescriptorToSecurityDescriptorA = (void *)GetProcAddress(library, "ConvertStringSecurityDescriptorToSecurityDescriptorA");
	pConvertStringSecurityDescriptorToSecurityDescriptorW = (void *)GetProcAddress(library, "ConvertStringSecurityDescriptorToSecurityDescriptorW");
	pConvertSecurityDescriptorToStringSecurityDescriptorW = (void *)GetProcAddress(library, "ConvertSecurityDescriptorToStringSecurityDescriptorW");
	pConvertSecurityDescriptorToStringSecurityDescriptorA = (void *)GetProcAddress(library, "ConvertSecurityDescriptorToStringSecurityDescriptorA");
	pConvertStringSidToSidW = (void *)GetProcAddress(library, "ConvertStringSidToSidW");
	pConvertStringSidToSidA = (void *)GetProcAddress(library, "ConvertStringSidToSidA");
	pConvertSidToStringSidW = (void *)GetProcAddress(library, "ConvertSidToStringSidW");
	pConvertSidToStringSidA = (void *)GetProcAddress(library, "ConvertSidToStringSidA");
	pCreateProcessWithLogonW = (void *)GetProcAddress(library, "CreateProcessWithLogonW");
	pCreateProcessWithTokenW = (void *)GetProcAddress(library, "CreateProcessWithTokenW");
	pGetNamedSecurityInfoA = (void *)GetProcAddress(library, "GetNamedSecurityInfoA");
	pGetNamedSecurityInfoW = (void *)GetProcAddress(library, "GetNamedSecurityInfoW");
	pGetNamedSecurityInfoExW = (void *)GetProcAddress(library, "GetNamedSecurityInfoExW");
	pGetNamedSecurityInfoExA = (void *)GetProcAddress(library, "GetNamedSecurityInfoExA");
	pDecryptFileW = (void *)GetProcAddress(library, "DecryptFileW");
	pDecryptFileA = (void *)GetProcAddress(library, "DecryptFileA");
	pEncryptFileW = (void *)GetProcAddress(library, "EncryptFileW");
	pEncryptFileA = (void *)GetProcAddress(library, "EncryptFileA");
	pFileEncryptionStatusW = (void *)GetProcAddress(library, "FileEncryptionStatusW");
	pFileEncryptionStatusA = (void *)GetProcAddress(library, "FileEncryptionStatusA");
	pSetSecurityInfo = (void *)GetProcAddress(library, "SetSecurityInfo");
	pSaferCreateLevel = (void *)GetProcAddress(library, "SaferCreateLevel");
	pSaferComputeTokenFromLevel = (void *)GetProcAddress(library, "SaferComputeTokenFromLevel");
	pSaferCloseLevel = (void *)GetProcAddress(library, "SaferCloseLevel");
	pTreeResetNamedSecurityInfoW = (void *)GetProcAddress(library, "TreeResetNamedSecurityInfoW");
	pSaferGetPolicyInformation = (void *)GetProcAddress(library, "SaferGetPolicyInformation");
	pSaferIdentifyLevel = (void *)GetProcAddress(library, "SaferIdentifyLevel");
	pSaferSetLevelInformation = (void *)GetProcAddress(library, "SaferSetLevelInformation");
	pLookupSecurityDescriptorPartsA = (void *)GetProcAddress(library, "LookupSecurityDescriptorPartsA");
	pLookupSecurityDescriptorPartsW = (void *)GetProcAddress(library, "LookupSecurityDescriptorPartsW");
	pWmiExecuteMethodA = (void *)GetProcAddress(library, "WmiExecuteMethodA");
	pWmiExecuteMethodW = (void *)GetProcAddress(library, "WmiExecuteMethodW");
	pWmiFreeBuffer = (void *)GetProcAddress(library, "WmiFreeBuffer");
	pWmiMofEnumerateResourcesA = (void *)GetProcAddress(library, "WmiMofEnumerateResourcesA");
	pWmiMofEnumerateResourcesW = (void *)GetProcAddress(library, "WmiMofEnumerateResourcesW");
	pWmiNotificationRegistrationA = (void *)GetProcAddress(library, "WmiNotificationRegistrationA");
	pWmiNotificationRegistrationW = (void *)GetProcAddress(library, "WmiNotificationRegistrationW");
	pWmiOpenBlock = (void *)GetProcAddress(library, "WmiOpenBlock");
	pWmiQueryAllDataA = (void *)GetProcAddress(library, "WmiQueryAllDataA");
	pWmiQueryAllDataW = (void *)GetProcAddress(library, "WmiQueryAllDataW");
	pWmiQueryGuidInformation = (void *)GetProcAddress(library, "WmiQueryGuidInformation");
	pWmiSetSingleInstanceA = (void *)GetProcAddress(library, "WmiSetSingleInstanceA");
	pWmiSetSingleInstanceW = (void *)GetProcAddress(library, "WmiSetSingleInstanceW");
	pWmiSetSingleItemA = (void *)GetProcAddress(library, "WmiSetSingleItemA");
	pWmiSetSingleItemW = (void *)GetProcAddress(library, "WmiSetSingleItemW");
	initialized = TRUE;
}

void* wine_thunk_get_for_advapi32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pGetUserNameA)
		return wine32a_GetUserNameA;
	if (func == pGetUserNameW)
		return wine32a_GetUserNameW;
	if (func == pGetCurrentHwProfileA)
		return wine32a_GetCurrentHwProfileA;
	if (func == pGetCurrentHwProfileW)
		return wine32a_GetCurrentHwProfileW;
	if (func == pIsTextUnicode)
		return wine32a_IsTextUnicode;
	if (func == pAbortSystemShutdownA)
		return wine32a_AbortSystemShutdownA;
	if (func == pAbortSystemShutdownW)
		return wine32a_AbortSystemShutdownW;
	if (func == pInitiateSystemShutdownExA)
		return wine32a_InitiateSystemShutdownExA;
	if (func == pInitiateSystemShutdownExW)
		return wine32a_InitiateSystemShutdownExW;
	if (func == pInitiateSystemShutdownA)
		return wine32a_InitiateSystemShutdownA;
	if (func == pInitiateSystemShutdownW)
		return wine32a_InitiateSystemShutdownW;
	if (func == pInitiateShutdownA)
		return wine32a_InitiateShutdownA;
	if (func == pInitiateShutdownW)
		return wine32a_InitiateShutdownW;
	if (func == pLogonUserA)
		return wine32a_LogonUserA;
	if (func == pLogonUserW)
		return wine32a_LogonUserW;
	if (func == pCommandLineFromMsiDescriptor)
		return wine32a_CommandLineFromMsiDescriptor;
	if (func == pRegisterWaitChainCOMCallback)
		return wine32a_RegisterWaitChainCOMCallback;
	if (func == pCredDeleteA)
		return wine32a_CredDeleteA;
	if (func == pCredDeleteW)
		return wine32a_CredDeleteW;
	if (func == pCredEnumerateA)
		return wine32a_CredEnumerateA;
	if (func == pCredEnumerateW)
		return wine32a_CredEnumerateW;
	if (func == pCredFree)
		return wine32a_CredFree;
	if (func == pCredReadA)
		return wine32a_CredReadA;
	if (func == pCredReadW)
		return wine32a_CredReadW;
	if (func == pCredReadDomainCredentialsA)
		return wine32a_CredReadDomainCredentialsA;
	if (func == pCredReadDomainCredentialsW)
		return wine32a_CredReadDomainCredentialsW;
	if (func == pCredWriteA)
		return wine32a_CredWriteA;
	if (func == pCredWriteW)
		return wine32a_CredWriteW;
	if (func == pCredGetSessionTypes)
		return wine32a_CredGetSessionTypes;
	if (func == pCredMarshalCredentialA)
		return wine32a_CredMarshalCredentialA;
	if (func == pCredMarshalCredentialW)
		return wine32a_CredMarshalCredentialW;
	if (func == pCredUnmarshalCredentialA)
		return wine32a_CredUnmarshalCredentialA;
	if (func == pCredUnmarshalCredentialW)
		return wine32a_CredUnmarshalCredentialW;
	if (func == pCredIsMarshaledCredentialW)
		return wine32a_CredIsMarshaledCredentialW;
	if (func == pCredIsMarshaledCredentialA)
		return wine32a_CredIsMarshaledCredentialA;
	if (func == pCloseEncryptedFileRaw)
		return wine32a_CloseEncryptedFileRaw;
	if (func == pCryptAcquireContextW)
		return wine32a_CryptAcquireContextW;
	if (func == pCryptAcquireContextA)
		return wine32a_CryptAcquireContextA;
	if (func == pCryptContextAddRef)
		return wine32a_CryptContextAddRef;
	if (func == pCryptReleaseContext)
		return wine32a_CryptReleaseContext;
	if (func == pCryptGenRandom)
		return wine32a_CryptGenRandom;
	if (func == pCryptCreateHash)
		return wine32a_CryptCreateHash;
	if (func == pCryptDecrypt)
		return wine32a_CryptDecrypt;
	if (func == pCryptDeriveKey)
		return wine32a_CryptDeriveKey;
	if (func == pCryptDestroyHash)
		return wine32a_CryptDestroyHash;
	if (func == pCryptDestroyKey)
		return wine32a_CryptDestroyKey;
	if (func == pCryptDuplicateHash)
		return wine32a_CryptDuplicateHash;
	if (func == pCryptDuplicateKey)
		return wine32a_CryptDuplicateKey;
	if (func == pCryptEncrypt)
		return wine32a_CryptEncrypt;
	if (func == pCryptEnumProvidersW)
		return wine32a_CryptEnumProvidersW;
	if (func == pCryptEnumProvidersA)
		return wine32a_CryptEnumProvidersA;
	if (func == pCryptEnumProviderTypesW)
		return wine32a_CryptEnumProviderTypesW;
	if (func == pCryptEnumProviderTypesA)
		return wine32a_CryptEnumProviderTypesA;
	if (func == pCryptExportKey)
		return wine32a_CryptExportKey;
	if (func == pCryptGenKey)
		return wine32a_CryptGenKey;
	if (func == pCryptGetDefaultProviderW)
		return wine32a_CryptGetDefaultProviderW;
	if (func == pCryptGetDefaultProviderA)
		return wine32a_CryptGetDefaultProviderA;
	if (func == pCryptGetHashParam)
		return wine32a_CryptGetHashParam;
	if (func == pCryptGetKeyParam)
		return wine32a_CryptGetKeyParam;
	if (func == pCryptGetProvParam)
		return wine32a_CryptGetProvParam;
	if (func == pCryptGetUserKey)
		return wine32a_CryptGetUserKey;
	if (func == pCryptHashData)
		return wine32a_CryptHashData;
	if (func == pCryptHashSessionKey)
		return wine32a_CryptHashSessionKey;
	if (func == pCryptImportKey)
		return wine32a_CryptImportKey;
	if (func == pCryptSignHashW)
		return wine32a_CryptSignHashW;
	if (func == pCryptSignHashA)
		return wine32a_CryptSignHashA;
	if (func == pCryptSetHashParam)
		return wine32a_CryptSetHashParam;
	if (func == pCryptSetKeyParam)
		return wine32a_CryptSetKeyParam;
	if (func == pCryptSetProviderA)
		return wine32a_CryptSetProviderA;
	if (func == pCryptSetProviderW)
		return wine32a_CryptSetProviderW;
	if (func == pCryptSetProviderExW)
		return wine32a_CryptSetProviderExW;
	if (func == pCryptSetProviderExA)
		return wine32a_CryptSetProviderExA;
	if (func == pCryptSetProvParam)
		return wine32a_CryptSetProvParam;
	if (func == pCryptVerifySignatureW)
		return wine32a_CryptVerifySignatureW;
	if (func == pCryptVerifySignatureA)
		return wine32a_CryptVerifySignatureA;
	if (func == pOpenEncryptedFileRawA)
		return wine32a_OpenEncryptedFileRawA;
	if (func == pOpenEncryptedFileRawW)
		return wine32a_OpenEncryptedFileRawW;
	if (func == pReadEncryptedFileRaw)
		return wine32a_ReadEncryptedFileRaw;
	if (func == pSystemFunction007)
		return wine32a_SystemFunction007;
	if (func == pSystemFunction010)
		return wine32a_SystemFunction010;
	if (func == pSystemFunction030)
		return wine32a_SystemFunction030;
	if (func == pSystemFunction035)
		return wine32a_SystemFunction035;
	if (func == pSystemFunction036)
		return wine32a_SystemFunction036;
	if (func == pSystemFunction040)
		return wine32a_SystemFunction040;
	if (func == pSystemFunction041)
		return wine32a_SystemFunction041;
	if (func == pWriteEncryptedFileRaw)
		return wine32a_WriteEncryptedFileRaw;
	if (func == pSystemFunction032)
		return wine32a_SystemFunction032;
	if (func == pSystemFunction006)
		return wine32a_SystemFunction006;
	if (func == pSystemFunction008)
		return wine32a_SystemFunction008;
	if (func == pSystemFunction009)
		return wine32a_SystemFunction009;
	if (func == pSystemFunction001)
		return wine32a_SystemFunction001;
	if (func == pSystemFunction002)
		return wine32a_SystemFunction002;
	if (func == pSystemFunction003)
		return wine32a_SystemFunction003;
	if (func == pSystemFunction004)
		return wine32a_SystemFunction004;
	if (func == pSystemFunction005)
		return wine32a_SystemFunction005;
	if (func == pSystemFunction012)
		return wine32a_SystemFunction012;
	if (func == pSystemFunction013)
		return wine32a_SystemFunction013;
	if (func == pSystemFunction024)
		return wine32a_SystemFunction024;
	if (func == pSystemFunction025)
		return wine32a_SystemFunction025;
	if (func == pBackupEventLogA)
		return wine32a_BackupEventLogA;
	if (func == pBackupEventLogW)
		return wine32a_BackupEventLogW;
	if (func == pClearEventLogA)
		return wine32a_ClearEventLogA;
	if (func == pClearEventLogW)
		return wine32a_ClearEventLogW;
	if (func == pCloseEventLog)
		return wine32a_CloseEventLog;
	if (func == pControlTraceW)
		return wine32a_ControlTraceW;
	if (func == pControlTraceA)
		return wine32a_ControlTraceA;
	if (func == pFlushTraceA)
		return wine32a_FlushTraceA;
	if (func == pFlushTraceW)
		return wine32a_FlushTraceW;
	if (func == pDeregisterEventSource)
		return wine32a_DeregisterEventSource;
	if (func == pEnableTraceEx)
		return wine32a_EnableTraceEx;
	if (func == pEnableTraceEx2)
		return wine32a_EnableTraceEx2;
	if (func == pEnableTrace)
		return wine32a_EnableTrace;
	if (func == pGetEventLogInformation)
		return wine32a_GetEventLogInformation;
	if (func == pGetNumberOfEventLogRecords)
		return wine32a_GetNumberOfEventLogRecords;
	if (func == pGetOldestEventLogRecord)
		return wine32a_GetOldestEventLogRecord;
	if (func == pNotifyChangeEventLog)
		return wine32a_NotifyChangeEventLog;
	if (func == pOpenBackupEventLogA)
		return wine32a_OpenBackupEventLogA;
	if (func == pOpenBackupEventLogW)
		return wine32a_OpenBackupEventLogW;
	if (func == pOpenEventLogA)
		return wine32a_OpenEventLogA;
	if (func == pOpenEventLogW)
		return wine32a_OpenEventLogW;
	if (func == pQueryAllTracesW)
		return wine32a_QueryAllTracesW;
	if (func == pQueryAllTracesA)
		return wine32a_QueryAllTracesA;
	if (func == pReadEventLogA)
		return wine32a_ReadEventLogA;
	if (func == pReadEventLogW)
		return wine32a_ReadEventLogW;
	if (func == pRegisterEventSourceA)
		return wine32a_RegisterEventSourceA;
	if (func == pRegisterEventSourceW)
		return wine32a_RegisterEventSourceW;
	if (func == pReportEventA)
		return wine32a_ReportEventA;
	if (func == pReportEventW)
		return wine32a_ReportEventW;
	if (func == pStartTraceW)
		return wine32a_StartTraceW;
	if (func == pStartTraceA)
		return wine32a_StartTraceA;
	if (func == pStopTraceW)
		return wine32a_StopTraceW;
	if (func == pStopTraceA)
		return wine32a_StopTraceA;
	if (func == pQueryTraceW)
		return wine32a_QueryTraceW;
	if (func == pOpenTraceA)
		return wine32a_OpenTraceA;
	if (func == pOpenTraceW)
		return wine32a_OpenTraceW;
	if (func == pProcessTrace)
		return wine32a_ProcessTrace;
	if (func == pCloseTrace)
		return wine32a_CloseTrace;
	if (func == pEnumerateTraceGuids)
		return wine32a_EnumerateTraceGuids;
	if (func == pTraceSetInformation)
		return wine32a_TraceSetInformation;
	if (func == pLsaAddAccountRights)
		return wine32a_LsaAddAccountRights;
	if (func == pLsaClose)
		return wine32a_LsaClose;
	if (func == pLsaCreateTrustedDomainEx)
		return wine32a_LsaCreateTrustedDomainEx;
	if (func == pLsaDeleteTrustedDomain)
		return wine32a_LsaDeleteTrustedDomain;
	if (func == pLsaEnumerateAccountRights)
		return wine32a_LsaEnumerateAccountRights;
	if (func == pLsaEnumerateAccountsWithUserRight)
		return wine32a_LsaEnumerateAccountsWithUserRight;
	if (func == pLsaEnumerateTrustedDomains)
		return wine32a_LsaEnumerateTrustedDomains;
	if (func == pLsaEnumerateTrustedDomainsEx)
		return wine32a_LsaEnumerateTrustedDomainsEx;
	if (func == pLsaFreeMemory)
		return wine32a_LsaFreeMemory;
	if (func == pLsaLookupNames)
		return wine32a_LsaLookupNames;
	if (func == pLsaLookupNames2)
		return wine32a_LsaLookupNames2;
	if (func == pLsaLookupSids)
		return wine32a_LsaLookupSids;
	if (func == pLsaNtStatusToWinError)
		return wine32a_LsaNtStatusToWinError;
	if (func == pLsaOpenPolicy)
		return wine32a_LsaOpenPolicy;
	if (func == pLsaOpenTrustedDomainByName)
		return wine32a_LsaOpenTrustedDomainByName;
	if (func == pLsaQueryInformationPolicy)
		return wine32a_LsaQueryInformationPolicy;
	if (func == pLsaQueryTrustedDomainInfo)
		return wine32a_LsaQueryTrustedDomainInfo;
	if (func == pLsaQueryTrustedDomainInfoByName)
		return wine32a_LsaQueryTrustedDomainInfoByName;
	if (func == pLsaRegisterPolicyChangeNotification)
		return wine32a_LsaRegisterPolicyChangeNotification;
	if (func == pLsaRemoveAccountRights)
		return wine32a_LsaRemoveAccountRights;
	if (func == pLsaRetrievePrivateData)
		return wine32a_LsaRetrievePrivateData;
	if (func == pLsaSetInformationPolicy)
		return wine32a_LsaSetInformationPolicy;
	if (func == pLsaSetSecret)
		return wine32a_LsaSetSecret;
	if (func == pLsaSetTrustedDomainInfoByName)
		return wine32a_LsaSetTrustedDomainInfoByName;
	if (func == pLsaSetTrustedDomainInformation)
		return wine32a_LsaSetTrustedDomainInformation;
	if (func == pLsaStorePrivateData)
		return wine32a_LsaStorePrivateData;
	if (func == pLsaUnregisterPolicyChangeNotification)
		return wine32a_LsaUnregisterPolicyChangeNotification;
	if (func == pLsaLookupPrivilegeName)
		return wine32a_LsaLookupPrivilegeName;
	if (func == pLsaLookupPrivilegeDisplayName)
		return wine32a_LsaLookupPrivilegeDisplayName;
	if (func == pAuditQuerySystemPolicy)
		return wine32a_AuditQuerySystemPolicy;
	if (func == pRegOverridePredefKey)
		return wine32a_RegOverridePredefKey;
	if (func == pRegCreateKeyW)
		return wine32a_RegCreateKeyW;
	if (func == pRegCreateKeyA)
		return wine32a_RegCreateKeyA;
	if (func == pRegCreateKeyTransactedW)
		return wine32a_RegCreateKeyTransactedW;
	if (func == pRegCreateKeyTransactedA)
		return wine32a_RegCreateKeyTransactedA;
	if (func == pRegOpenKeyW)
		return wine32a_RegOpenKeyW;
	if (func == pRegOpenKeyA)
		return wine32a_RegOpenKeyA;
	if (func == pRegEnumKeyW)
		return wine32a_RegEnumKeyW;
	if (func == pRegEnumKeyA)
		return wine32a_RegEnumKeyA;
	if (func == pRegQueryMultipleValuesA)
		return wine32a_RegQueryMultipleValuesA;
	if (func == pRegQueryMultipleValuesW)
		return wine32a_RegQueryMultipleValuesW;
	if (func == pRegQueryReflectionKey)
		return wine32a_RegQueryReflectionKey;
	if (func == pRegDeleteKeyW)
		return wine32a_RegDeleteKeyW;
	if (func == pRegDeleteKeyA)
		return wine32a_RegDeleteKeyA;
	if (func == pRegSetValueW)
		return wine32a_RegSetValueW;
	if (func == pRegSetValueA)
		return wine32a_RegSetValueA;
	if (func == pRegQueryValueW)
		return wine32a_RegQueryValueW;
	if (func == pRegQueryValueA)
		return wine32a_RegQueryValueA;
	if (func == pRegSaveKeyW)
		return wine32a_RegSaveKeyW;
	if (func == pRegSaveKeyA)
		return wine32a_RegSaveKeyA;
	if (func == pRegReplaceKeyW)
		return wine32a_RegReplaceKeyW;
	if (func == pRegReplaceKeyA)
		return wine32a_RegReplaceKeyA;
	if (func == pRegConnectRegistryW)
		return wine32a_RegConnectRegistryW;
	if (func == pRegConnectRegistryA)
		return wine32a_RegConnectRegistryA;
	if (func == pRegDisablePredefinedCache)
		return wine32a_RegDisablePredefinedCache;
	if (func == pRegCopyTreeA)
		return wine32a_RegCopyTreeA;
	if (func == pRegDisableReflectionKey)
		return wine32a_RegDisableReflectionKey;
	if (func == pGetEffectiveRightsFromAclA)
		return wine32a_GetEffectiveRightsFromAclA;
	if (func == pGetEffectiveRightsFromAclW)
		return wine32a_GetEffectiveRightsFromAclW;
	if (func == pBuildSecurityDescriptorA)
		return wine32a_BuildSecurityDescriptorA;
	if (func == pBuildSecurityDescriptorW)
		return wine32a_BuildSecurityDescriptorW;
	if (func == pLookupPrivilegeValueW)
		return wine32a_LookupPrivilegeValueW;
	if (func == pLookupPrivilegeValueA)
		return wine32a_LookupPrivilegeValueA;
	if (func == pLookupPrivilegeDisplayNameA)
		return wine32a_LookupPrivilegeDisplayNameA;
	if (func == pLookupPrivilegeDisplayNameW)
		return wine32a_LookupPrivilegeDisplayNameW;
	if (func == pLookupPrivilegeNameA)
		return wine32a_LookupPrivilegeNameA;
	if (func == pLookupPrivilegeNameW)
		return wine32a_LookupPrivilegeNameW;
	if (func == pGetFileSecurityA)
		return wine32a_GetFileSecurityA;
	if (func == pLookupAccountSidA)
		return wine32a_LookupAccountSidA;
	if (func == pLookupAccountSidLocalA)
		return wine32a_LookupAccountSidLocalA;
	if (func == pLookupAccountSidW)
		return wine32a_LookupAccountSidW;
	if (func == pLookupAccountSidLocalW)
		return wine32a_LookupAccountSidLocalW;
	if (func == pSetFileSecurityA)
		return wine32a_SetFileSecurityA;
	if (func == pQueryWindows31FilesMigration)
		return wine32a_QueryWindows31FilesMigration;
	if (func == pSynchronizeWindows31FilesAndWindowsNTRegistry)
		return wine32a_SynchronizeWindows31FilesAndWindowsNTRegistry;
	if (func == pNotifyBootConfigStatus)
		return wine32a_NotifyBootConfigStatus;
	if (func == pLookupAccountNameA)
		return wine32a_LookupAccountNameA;
	if (func == pLookupAccountNameW)
		return wine32a_LookupAccountNameW;
	if (func == pAccessCheckAndAuditAlarmA)
		return wine32a_AccessCheckAndAuditAlarmA;
	if (func == pObjectCloseAuditAlarmA)
		return wine32a_ObjectCloseAuditAlarmA;
	if (func == pObjectOpenAuditAlarmA)
		return wine32a_ObjectOpenAuditAlarmA;
	if (func == pObjectPrivilegeAuditAlarmA)
		return wine32a_ObjectPrivilegeAuditAlarmA;
	if (func == pPrivilegedServiceAuditAlarmA)
		return wine32a_PrivilegedServiceAuditAlarmA;
	if (func == pGetSecurityInfo)
		return wine32a_GetSecurityInfo;
	if (func == pGetSecurityInfoExA)
		return wine32a_GetSecurityInfoExA;
	if (func == pGetSecurityInfoExW)
		return wine32a_GetSecurityInfoExW;
	if (func == pBuildExplicitAccessWithNameA)
		return wine32a_BuildExplicitAccessWithNameA;
	if (func == pBuildExplicitAccessWithNameW)
		return wine32a_BuildExplicitAccessWithNameW;
	if (func == pBuildTrusteeWithObjectsAndNameA)
		return wine32a_BuildTrusteeWithObjectsAndNameA;
	if (func == pBuildTrusteeWithObjectsAndNameW)
		return wine32a_BuildTrusteeWithObjectsAndNameW;
	if (func == pBuildTrusteeWithObjectsAndSidA)
		return wine32a_BuildTrusteeWithObjectsAndSidA;
	if (func == pBuildTrusteeWithObjectsAndSidW)
		return wine32a_BuildTrusteeWithObjectsAndSidW;
	if (func == pBuildTrusteeWithSidA)
		return wine32a_BuildTrusteeWithSidA;
	if (func == pBuildTrusteeWithSidW)
		return wine32a_BuildTrusteeWithSidW;
	if (func == pBuildTrusteeWithNameA)
		return wine32a_BuildTrusteeWithNameA;
	if (func == pBuildTrusteeWithNameW)
		return wine32a_BuildTrusteeWithNameW;
	if (func == pGetTrusteeFormA)
		return wine32a_GetTrusteeFormA;
	if (func == pGetTrusteeFormW)
		return wine32a_GetTrusteeFormW;
	if (func == pGetTrusteeNameA)
		return wine32a_GetTrusteeNameA;
	if (func == pGetTrusteeNameW)
		return wine32a_GetTrusteeNameW;
	if (func == pGetTrusteeTypeA)
		return wine32a_GetTrusteeTypeA;
	if (func == pGetTrusteeTypeW)
		return wine32a_GetTrusteeTypeW;
	if (func == pSetEntriesInAclA)
		return wine32a_SetEntriesInAclA;
	if (func == pSetEntriesInAclW)
		return wine32a_SetEntriesInAclW;
	if (func == pSetNamedSecurityInfoA)
		return wine32a_SetNamedSecurityInfoA;
	if (func == pSetNamedSecurityInfoW)
		return wine32a_SetNamedSecurityInfoW;
	if (func == pGetExplicitEntriesFromAclA)
		return wine32a_GetExplicitEntriesFromAclA;
	if (func == pGetExplicitEntriesFromAclW)
		return wine32a_GetExplicitEntriesFromAclW;
	if (func == pGetAuditedPermissionsFromAclA)
		return wine32a_GetAuditedPermissionsFromAclA;
	if (func == pGetAuditedPermissionsFromAclW)
		return wine32a_GetAuditedPermissionsFromAclW;
	if (func == pConvertStringSecurityDescriptorToSecurityDescriptorA)
		return wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorA;
	if (func == pConvertStringSecurityDescriptorToSecurityDescriptorW)
		return wine32a_ConvertStringSecurityDescriptorToSecurityDescriptorW;
	if (func == pConvertSecurityDescriptorToStringSecurityDescriptorW)
		return wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorW;
	if (func == pConvertSecurityDescriptorToStringSecurityDescriptorA)
		return wine32a_ConvertSecurityDescriptorToStringSecurityDescriptorA;
	if (func == pConvertStringSidToSidW)
		return wine32a_ConvertStringSidToSidW;
	if (func == pConvertStringSidToSidA)
		return wine32a_ConvertStringSidToSidA;
	if (func == pConvertSidToStringSidW)
		return wine32a_ConvertSidToStringSidW;
	if (func == pConvertSidToStringSidA)
		return wine32a_ConvertSidToStringSidA;
	if (func == pCreateProcessWithLogonW)
		return wine32a_CreateProcessWithLogonW;
	if (func == pCreateProcessWithTokenW)
		return wine32a_CreateProcessWithTokenW;
	if (func == pGetNamedSecurityInfoA)
		return wine32a_GetNamedSecurityInfoA;
	if (func == pGetNamedSecurityInfoW)
		return wine32a_GetNamedSecurityInfoW;
	if (func == pGetNamedSecurityInfoExW)
		return wine32a_GetNamedSecurityInfoExW;
	if (func == pGetNamedSecurityInfoExA)
		return wine32a_GetNamedSecurityInfoExA;
	if (func == pDecryptFileW)
		return wine32a_DecryptFileW;
	if (func == pDecryptFileA)
		return wine32a_DecryptFileA;
	if (func == pEncryptFileW)
		return wine32a_EncryptFileW;
	if (func == pEncryptFileA)
		return wine32a_EncryptFileA;
	if (func == pFileEncryptionStatusW)
		return wine32a_FileEncryptionStatusW;
	if (func == pFileEncryptionStatusA)
		return wine32a_FileEncryptionStatusA;
	if (func == pSetSecurityInfo)
		return wine32a_SetSecurityInfo;
	if (func == pSaferCreateLevel)
		return wine32a_SaferCreateLevel;
	if (func == pSaferComputeTokenFromLevel)
		return wine32a_SaferComputeTokenFromLevel;
	if (func == pSaferCloseLevel)
		return wine32a_SaferCloseLevel;
	if (func == pTreeResetNamedSecurityInfoW)
		return wine32a_TreeResetNamedSecurityInfoW;
	if (func == pSaferGetPolicyInformation)
		return wine32a_SaferGetPolicyInformation;
	if (func == pSaferIdentifyLevel)
		return wine32a_SaferIdentifyLevel;
	if (func == pSaferSetLevelInformation)
		return wine32a_SaferSetLevelInformation;
	if (func == pLookupSecurityDescriptorPartsA)
		return wine32a_LookupSecurityDescriptorPartsA;
	if (func == pLookupSecurityDescriptorPartsW)
		return wine32a_LookupSecurityDescriptorPartsW;
	if (func == pWmiExecuteMethodA)
		return wine32a_WmiExecuteMethodA;
	if (func == pWmiExecuteMethodW)
		return wine32a_WmiExecuteMethodW;
	if (func == pWmiFreeBuffer)
		return wine32a_WmiFreeBuffer;
	if (func == pWmiMofEnumerateResourcesA)
		return wine32a_WmiMofEnumerateResourcesA;
	if (func == pWmiMofEnumerateResourcesW)
		return wine32a_WmiMofEnumerateResourcesW;
	if (func == pWmiNotificationRegistrationA)
		return wine32a_WmiNotificationRegistrationA;
	if (func == pWmiNotificationRegistrationW)
		return wine32a_WmiNotificationRegistrationW;
	if (func == pWmiOpenBlock)
		return wine32a_WmiOpenBlock;
	if (func == pWmiQueryAllDataA)
		return wine32a_WmiQueryAllDataA;
	if (func == pWmiQueryAllDataW)
		return wine32a_WmiQueryAllDataW;
	if (func == pWmiQueryGuidInformation)
		return wine32a_WmiQueryGuidInformation;
	if (func == pWmiSetSingleInstanceA)
		return wine32a_WmiSetSingleInstanceA;
	if (func == pWmiSetSingleInstanceW)
		return wine32a_WmiSetSingleInstanceW;
	if (func == pWmiSetSingleItemA)
		return wine32a_WmiSetSingleItemA;
	if (func == pWmiSetSingleItemW)
		return wine32a_WmiSetSingleItemW;

	return NULL;
}
