#define WIN32_NO_STATUS
#include "ntstatus.h"
#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

#include "../../include/ntstatus.h"
#include "../../include/winternl.h"
#include "../../include/ddk/wdm.h"
#include "../../dlls/ntdll/ntdll_misc.h"
#include "../../include/wine/exception.h"
#include "../../include/wine/debug.h"
#include "../../include/wine/unicode.h"
#include "../../include/windef.h"
#include "../../include/wine/server.h"
#include "../../include/winioctl.h"
#include "../../include/ntddstor.h"
#include "../../include/ntddcdrm.h"
#include "../../include/ddk/ntddcdvd.h"
#include "../../include/ntddscsi.h"
#include "../../include/wine/library.h"
#include "../../include/wine/list.h"
#include "../../include/winerror.h"
#include "../../include/ddk/ntddk.h"
#include "../../include/ddk/ntddser.h"
#include "../../include/wine/asm.h"
#include "../../include/delayloadhandler.h"
#include "../../include/wine/winethunks.h"
#include "../../include/pshpack1.h"
#include "../../include/poppack.h"
#include "../../include/wmistr.h"
#include "../../include/evntrace.h"
#include "../../include/evntprov.h"
#include "../../include/winbase.h"
#include "../../include/inaddr.h"
#include "../../include/in6addr.h"
#include "../../include/ddk/ntddtape.h"
#include "../../include/wine/rbtree.h"

static WINAPI NTSTATUS (*pRtlCreateActivationContext)(HANDLE * handle, const void * ptr);
static WINAPI void (*pRtlAddRefActivationContext)(HANDLE handle);
static WINAPI void (*pRtlReleaseActivationContext)(HANDLE handle);
static WINAPI NTSTATUS (*pRtlZombifyActivationContext)(HANDLE handle);
static WINAPI NTSTATUS (*pRtlActivateActivationContext)(ULONG unknown, HANDLE handle, PULONG_PTR cookie);
static WINAPI void (*pRtlDeactivateActivationContext)(ULONG flags, ULONG_PTR cookie);
static WINAPI void (*pRtlFreeThreadActivationContextStack)(void);
static WINAPI NTSTATUS (*pRtlGetActiveActivationContext)(HANDLE * handle);
static WINAPI BOOLEAN (*pRtlIsActivationContextActive)(HANDLE handle);
static WINAPI NTSTATUS (*pRtlQueryInformationActivationContext)(ULONG flags, HANDLE handle, PVOID subinst, ULONG class, PVOID buffer, SIZE_T bufsize, SIZE_T * retlen);
static WINAPI NTSTATUS (*pRtlFindActivationContextSectionString)(ULONG flags, const GUID * guid, ULONG section_kind, const UNICODE_STRING * section_name, PVOID ptr);
static WINAPI NTSTATUS (*pRtlFindActivationContextSectionGuid)(ULONG flags, const GUID * extguid, ULONG section_kind, const GUID * guid, void * ptr);
static WINAPI NTSTATUS (*pRtlQueryActivationContextApplicationSettings)(DWORD flags, HANDLE handle, const WCHAR * ns, const WCHAR * settings, WCHAR * buffer, SIZE_T size, SIZE_T * written);

extern WINAPI NTSTATUS wine32b_RtlCreateActivationContext(HANDLE * handle, const void * ptr)
{
	TRACE("Enter RtlCreateActivationContext\n");
	return pRtlCreateActivationContext(handle, ptr);
}

extern WINAPI void wine32a_RtlCreateActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlAddRefActivationContext(HANDLE handle)
{
	TRACE("Enter RtlAddRefActivationContext\n");
	return pRtlAddRefActivationContext(handle);
}

extern WINAPI void wine32a_RtlAddRefActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddRefActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddRefActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlReleaseActivationContext(HANDLE handle)
{
	TRACE("Enter RtlReleaseActivationContext\n");
	return pRtlReleaseActivationContext(handle);
}

extern WINAPI void wine32a_RtlReleaseActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleaseActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleaseActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlZombifyActivationContext(HANDLE handle)
{
	TRACE("Enter RtlZombifyActivationContext\n");
	return pRtlZombifyActivationContext(handle);
}

extern WINAPI void wine32a_RtlZombifyActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlZombifyActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlZombifyActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlActivateActivationContext(ULONG unknown, HANDLE handle, PULONG_PTR cookie)
{
	TRACE("Enter RtlActivateActivationContext\n");
	return pRtlActivateActivationContext(unknown, handle, cookie);
}

extern WINAPI void wine32a_RtlActivateActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlActivateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlActivateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlDeactivateActivationContext(ULONG flags, ULONG_PTR cookie)
{
	TRACE("Enter RtlDeactivateActivationContext\n");
	return pRtlDeactivateActivationContext(flags, cookie);
}

extern WINAPI void wine32a_RtlDeactivateActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeactivateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeactivateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFreeThreadActivationContextStack(void)
{
	TRACE("Enter RtlFreeThreadActivationContextStack\n");
	return pRtlFreeThreadActivationContextStack();
}

extern WINAPI void wine32a_RtlFreeThreadActivationContextStack(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeThreadActivationContextStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeThreadActivationContextStack") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlGetActiveActivationContext(HANDLE * handle)
{
	TRACE("Enter RtlGetActiveActivationContext\n");
	return pRtlGetActiveActivationContext(handle);
}

extern WINAPI void wine32a_RtlGetActiveActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetActiveActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetActiveActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlIsActivationContextActive(HANDLE handle)
{
	TRACE("Enter RtlIsActivationContextActive\n");
	return pRtlIsActivationContextActive(handle);
}

extern WINAPI void wine32a_RtlIsActivationContextActive(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsActivationContextActive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsActivationContextActive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryInformationActivationContext(ULONG flags, HANDLE handle, PVOID subinst, ULONG class, PVOID buffer, SIZE_T bufsize, SIZE_T * retlen)
{
	TRACE("Enter RtlQueryInformationActivationContext\n");
	return pRtlQueryInformationActivationContext(flags, handle, subinst, class, buffer, bufsize, retlen);
}

extern WINAPI void wine32a_RtlQueryInformationActivationContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryInformationActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryInformationActivationContext") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlFindActivationContextSectionString(ULONG flags, const GUID * guid, ULONG section_kind, const UNICODE_STRING * section_name, PVOID ptr)
{
	TRACE("Enter RtlFindActivationContextSectionString\n");
	return pRtlFindActivationContextSectionString(flags, guid, section_kind, section_name, ptr);
}

extern WINAPI void wine32a_RtlFindActivationContextSectionString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindActivationContextSectionString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindActivationContextSectionString") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlFindActivationContextSectionGuid(ULONG flags, const GUID * extguid, ULONG section_kind, const GUID * guid, void * ptr)
{
	TRACE("Enter RtlFindActivationContextSectionGuid\n");
	return pRtlFindActivationContextSectionGuid(flags, extguid, section_kind, guid, ptr);
}

extern WINAPI void wine32a_RtlFindActivationContextSectionGuid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindActivationContextSectionGuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindActivationContextSectionGuid") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlQueryActivationContextApplicationSettings(DWORD flags, HANDLE handle, const WCHAR * ns, const WCHAR * settings, WCHAR * buffer, SIZE_T size, SIZE_T * written)
{
	TRACE("Enter RtlQueryActivationContextApplicationSettings\n");
	return pRtlQueryActivationContextApplicationSettings(flags, handle, ns, settings, buffer, size, written);
}

extern WINAPI void wine32a_RtlQueryActivationContextApplicationSettings(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryActivationContextApplicationSettings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryActivationContextApplicationSettings") "\n"
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

static WINAPI NTSTATUS (*pRtlDeleteAtomFromAtomTable)(RTL_ATOM_TABLE table, RTL_ATOM atom);
static WINAPI NTSTATUS (*pRtlQueryAtomInAtomTable)(RTL_ATOM_TABLE table, RTL_ATOM atom, ULONG * ref, ULONG * pin, WCHAR * name, ULONG * len);
static WINAPI NTSTATUS (*pRtlCreateAtomTable)(ULONG size, RTL_ATOM_TABLE * table);
static WINAPI NTSTATUS (*pRtlDestroyAtomTable)(RTL_ATOM_TABLE table);
static WINAPI NTSTATUS (*pRtlAddAtomToAtomTable)(RTL_ATOM_TABLE table, const WCHAR * name, RTL_ATOM * atom);
static WINAPI NTSTATUS (*pRtlLookupAtomInAtomTable)(RTL_ATOM_TABLE table, const WCHAR * name, RTL_ATOM * atom);
static WINAPI NTSTATUS (*pRtlEmptyAtomTable)(RTL_ATOM_TABLE table, BOOLEAN delete_pinned);
static WINAPI NTSTATUS (*pRtlPinAtomInAtomTable)(RTL_ATOM_TABLE table, RTL_ATOM atom);
static WINAPI NTSTATUS (*pNtAddAtom)(const WCHAR * name, ULONG length, RTL_ATOM * atom);
static WINAPI NTSTATUS (*pNtDeleteAtom)(RTL_ATOM atom);
static WINAPI NTSTATUS (*pNtFindAtom)(const WCHAR * name, ULONG length, RTL_ATOM * atom);
static WINAPI NTSTATUS (*pNtQueryInformationAtom)(RTL_ATOM atom, ATOM_INFORMATION_CLASS class, PVOID ptr, ULONG size, PULONG psize);

extern WINAPI NTSTATUS wine32b_RtlDeleteAtomFromAtomTable(RTL_ATOM_TABLE table, RTL_ATOM atom)
{
	TRACE("Enter RtlDeleteAtomFromAtomTable\n");
	return pRtlDeleteAtomFromAtomTable(table, atom);
}

extern WINAPI void wine32a_RtlDeleteAtomFromAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteAtomFromAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteAtomFromAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryAtomInAtomTable(RTL_ATOM_TABLE table, RTL_ATOM atom, ULONG * ref, ULONG * pin, WCHAR * name, ULONG * len)
{
	TRACE("Enter RtlQueryAtomInAtomTable\n");
	return pRtlQueryAtomInAtomTable(table, atom, ref, pin, name, len);
}

extern WINAPI void wine32a_RtlQueryAtomInAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryAtomInAtomTable") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlCreateAtomTable(ULONG size, RTL_ATOM_TABLE * table)
{
	TRACE("Enter RtlCreateAtomTable\n");
	return pRtlCreateAtomTable(size, table);
}

extern WINAPI void wine32a_RtlCreateAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDestroyAtomTable(RTL_ATOM_TABLE table)
{
	TRACE("Enter RtlDestroyAtomTable\n");
	return pRtlDestroyAtomTable(table);
}

extern WINAPI void wine32a_RtlDestroyAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAddAtomToAtomTable(RTL_ATOM_TABLE table, const WCHAR * name, RTL_ATOM * atom)
{
	TRACE("Enter RtlAddAtomToAtomTable\n");
	return pRtlAddAtomToAtomTable(table, name, atom);
}

extern WINAPI void wine32a_RtlAddAtomToAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAtomToAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAtomToAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlLookupAtomInAtomTable(RTL_ATOM_TABLE table, const WCHAR * name, RTL_ATOM * atom)
{
	TRACE("Enter RtlLookupAtomInAtomTable\n");
	return pRtlLookupAtomInAtomTable(table, name, atom);
}

extern WINAPI void wine32a_RtlLookupAtomInAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLookupAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLookupAtomInAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlEmptyAtomTable(RTL_ATOM_TABLE table, BOOLEAN delete_pinned)
{
	TRACE("Enter RtlEmptyAtomTable\n");
	return pRtlEmptyAtomTable(table, delete_pinned);
}

extern WINAPI void wine32a_RtlEmptyAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEmptyAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEmptyAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlPinAtomInAtomTable(RTL_ATOM_TABLE table, RTL_ATOM atom)
{
	TRACE("Enter RtlPinAtomInAtomTable\n");
	return pRtlPinAtomInAtomTable(table, atom);
}

extern WINAPI void wine32a_RtlPinAtomInAtomTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPinAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPinAtomInAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAddAtom(const WCHAR * name, ULONG length, RTL_ATOM * atom)
{
	TRACE("Enter NtAddAtom\n");
	return pNtAddAtom(name, length, atom);
}

extern WINAPI void wine32a_NtAddAtom(void);
__ASM_GLOBAL_FUNC(wine32a_NtAddAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAddAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtDeleteAtom(RTL_ATOM atom)
{
	TRACE("Enter NtDeleteAtom\n");
	return pNtDeleteAtom(atom);
}

extern WINAPI void wine32a_NtDeleteAtom(void);
__ASM_GLOBAL_FUNC(wine32a_NtDeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtFindAtom(const WCHAR * name, ULONG length, RTL_ATOM * atom)
{
	TRACE("Enter NtFindAtom\n");
	return pNtFindAtom(name, length, atom);
}

extern WINAPI void wine32a_NtFindAtom(void);
__ASM_GLOBAL_FUNC(wine32a_NtFindAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFindAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryInformationAtom(RTL_ATOM atom, ATOM_INFORMATION_CLASS class, PVOID ptr, ULONG size, PULONG psize)
{
	TRACE("Enter NtQueryInformationAtom\n");
	return pNtQueryInformationAtom(atom, class, ptr, size, psize);
}

extern WINAPI void wine32a_NtQueryInformationAtom(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationAtom") "\n"
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


static WINAPI NTSTATUS (*pRtlInitializeCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pRtlInitializeCriticalSectionAndSpinCount)(RTL_CRITICAL_SECTION * crit, ULONG spincount);
static WINAPI NTSTATUS (*pRtlInitializeCriticalSectionEx)(RTL_CRITICAL_SECTION * crit, ULONG spincount, ULONG flags);
static WINAPI ULONG (*pRtlSetCriticalSectionSpinCount)(RTL_CRITICAL_SECTION * crit, ULONG spincount);
static WINAPI NTSTATUS (*pRtlDeleteCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pRtlpWaitForCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pRtlpUnWaitCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pRtlEnterCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI BOOL (*pRtlTryEnterCriticalSection)(RTL_CRITICAL_SECTION * crit);
static WINAPI BOOL (*pRtlIsCriticalSectionLocked)(RTL_CRITICAL_SECTION * crit);
static WINAPI BOOL (*pRtlIsCriticalSectionLockedByThread)(RTL_CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pRtlLeaveCriticalSection)(RTL_CRITICAL_SECTION * crit);

extern WINAPI NTSTATUS wine32b_RtlInitializeCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlInitializeCriticalSection\n");
	return pRtlInitializeCriticalSection(crit);
}

extern WINAPI void wine32a_RtlInitializeCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlInitializeCriticalSectionAndSpinCount(RTL_CRITICAL_SECTION * crit, ULONG spincount)
{
	TRACE("Enter RtlInitializeCriticalSectionAndSpinCount\n");
	return pRtlInitializeCriticalSectionAndSpinCount(crit, spincount);
}

extern WINAPI void wine32a_RtlInitializeCriticalSectionAndSpinCount(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeCriticalSectionAndSpinCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeCriticalSectionAndSpinCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlInitializeCriticalSectionEx(RTL_CRITICAL_SECTION * crit, ULONG spincount, ULONG flags)
{
	TRACE("Enter RtlInitializeCriticalSectionEx\n");
	return pRtlInitializeCriticalSectionEx(crit, spincount, flags);
}

extern WINAPI void wine32a_RtlInitializeCriticalSectionEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeCriticalSectionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeCriticalSectionEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlSetCriticalSectionSpinCount(RTL_CRITICAL_SECTION * crit, ULONG spincount)
{
	TRACE("Enter RtlSetCriticalSectionSpinCount\n");
	return pRtlSetCriticalSectionSpinCount(crit, spincount);
}

extern WINAPI void wine32a_RtlSetCriticalSectionSpinCount(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetCriticalSectionSpinCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetCriticalSectionSpinCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDeleteCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlDeleteCriticalSection\n");
	return pRtlDeleteCriticalSection(crit);
}

extern WINAPI void wine32a_RtlDeleteCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlpWaitForCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlpWaitForCriticalSection\n");
	return pRtlpWaitForCriticalSection(crit);
}

extern WINAPI void wine32a_RtlpWaitForCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpWaitForCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpWaitForCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlpUnWaitCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlpUnWaitCriticalSection\n");
	return pRtlpUnWaitCriticalSection(crit);
}

extern WINAPI void wine32a_RtlpUnWaitCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpUnWaitCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpUnWaitCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlEnterCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlEnterCriticalSection\n");
	return pRtlEnterCriticalSection(crit);
}

extern WINAPI void wine32a_RtlEnterCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEnterCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEnterCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlTryEnterCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlTryEnterCriticalSection\n");
	return pRtlTryEnterCriticalSection(crit);
}

extern WINAPI void wine32a_RtlTryEnterCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTryEnterCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTryEnterCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlIsCriticalSectionLocked(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlIsCriticalSectionLocked\n");
	return pRtlIsCriticalSectionLocked(crit);
}

extern WINAPI void wine32a_RtlIsCriticalSectionLocked(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsCriticalSectionLocked,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsCriticalSectionLocked") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlIsCriticalSectionLockedByThread(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlIsCriticalSectionLockedByThread\n");
	return pRtlIsCriticalSectionLockedByThread(crit);
}

extern WINAPI void wine32a_RtlIsCriticalSectionLockedByThread(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsCriticalSectionLockedByThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsCriticalSectionLockedByThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlLeaveCriticalSection(RTL_CRITICAL_SECTION * crit)
{
	TRACE("Enter RtlLeaveCriticalSection\n");
	return pRtlLeaveCriticalSection(crit);
}

extern WINAPI void wine32a_RtlLeaveCriticalSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLeaveCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLeaveCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*pA_SHAInit)(PSHA_CTX Context);
static WINAPI void (*pA_SHAUpdate)(PSHA_CTX Context, const unsigned char * Buffer, UINT BufferSize);
static WINAPI void (*pA_SHAFinal)(PSHA_CTX Context, PULONG Result);
static WINAPI void (*pMD4Init)(MD4_CTX * ctx);
static WINAPI void (*pMD4Update)(MD4_CTX * ctx, const unsigned char * buf, unsigned int len);
static WINAPI void (*pMD4Final)(MD4_CTX * ctx);
static WINAPI void (*pMD5Init)(MD5_CTX * ctx);
static WINAPI void (*pMD5Update)(MD5_CTX * ctx, const unsigned char * buf, unsigned int len);
static WINAPI void (*pMD5Final)(MD5_CTX * ctx);

extern WINAPI void wine32b_A_SHAInit(PSHA_CTX Context)
{
	TRACE("Enter A_SHAInit\n");
	return pA_SHAInit(Context);
}

extern WINAPI void wine32a_A_SHAInit(void);
__ASM_GLOBAL_FUNC(wine32a_A_SHAInit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_A_SHAInit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_A_SHAUpdate(PSHA_CTX Context, const unsigned char * Buffer, UINT BufferSize)
{
	TRACE("Enter A_SHAUpdate\n");
	return pA_SHAUpdate(Context, Buffer, BufferSize);
}

extern WINAPI void wine32a_A_SHAUpdate(void);
__ASM_GLOBAL_FUNC(wine32a_A_SHAUpdate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_A_SHAUpdate") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_A_SHAFinal(PSHA_CTX Context, PULONG Result)
{
	TRACE("Enter A_SHAFinal\n");
	return pA_SHAFinal(Context, Result);
}

extern WINAPI void wine32a_A_SHAFinal(void);
__ASM_GLOBAL_FUNC(wine32a_A_SHAFinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_A_SHAFinal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD4Init(MD4_CTX * ctx)
{
	TRACE("Enter MD4Init\n");
	return pMD4Init(ctx);
}

extern WINAPI void wine32a_MD4Init(void);
__ASM_GLOBAL_FUNC(wine32a_MD4Init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD4Init") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD4Update(MD4_CTX * ctx, const unsigned char * buf, unsigned int len)
{
	TRACE("Enter MD4Update\n");
	return pMD4Update(ctx, buf, len);
}

extern WINAPI void wine32a_MD4Update(void);
__ASM_GLOBAL_FUNC(wine32a_MD4Update,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD4Update") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD4Final(MD4_CTX * ctx)
{
	TRACE("Enter MD4Final\n");
	return pMD4Final(ctx);
}

extern WINAPI void wine32a_MD4Final(void);
__ASM_GLOBAL_FUNC(wine32a_MD4Final,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD4Final") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD5Init(MD5_CTX * ctx)
{
	TRACE("Enter MD5Init\n");
	return pMD5Init(ctx);
}

extern WINAPI void wine32a_MD5Init(void);
__ASM_GLOBAL_FUNC(wine32a_MD5Init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD5Init") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD5Update(MD5_CTX * ctx, const unsigned char * buf, unsigned int len)
{
	TRACE("Enter MD5Update\n");
	return pMD5Update(ctx, buf, len);
}

extern WINAPI void wine32a_MD5Update(void);
__ASM_GLOBAL_FUNC(wine32a_MD5Update,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD5Update") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_MD5Final(MD5_CTX * ctx)
{
	TRACE("Enter MD5Final\n");
	return pMD5Final(ctx);
}

extern WINAPI void wine32a_MD5Final(void);
__ASM_GLOBAL_FUNC(wine32a_MD5Final,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MD5Final") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI PDEBUG_BUFFER (*pRtlCreateQueryDebugBuffer)(ULONG iSize, BOOLEAN iEventPair);
static WINAPI NTSTATUS (*pRtlDestroyQueryDebugBuffer)(PDEBUG_BUFFER iBuf);
static WINAPI NTSTATUS (*pRtlQueryProcessDebugInformation)(ULONG iProcessId, ULONG iDebugInfoMask, PDEBUG_BUFFER iBuf);

extern WINAPI PDEBUG_BUFFER wine32b_RtlCreateQueryDebugBuffer(ULONG iSize, BOOLEAN iEventPair)
{
	TRACE("Enter RtlCreateQueryDebugBuffer\n");
	return pRtlCreateQueryDebugBuffer(iSize, iEventPair);
}

extern WINAPI void wine32a_RtlCreateQueryDebugBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateQueryDebugBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateQueryDebugBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDestroyQueryDebugBuffer(PDEBUG_BUFFER iBuf)
{
	TRACE("Enter RtlDestroyQueryDebugBuffer\n");
	return pRtlDestroyQueryDebugBuffer(iBuf);
}

extern WINAPI void wine32a_RtlDestroyQueryDebugBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyQueryDebugBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyQueryDebugBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryProcessDebugInformation(ULONG iProcessId, ULONG iDebugInfoMask, PDEBUG_BUFFER iBuf)
{
	TRACE("Enter RtlQueryProcessDebugInformation\n");
	return pRtlQueryProcessDebugInformation(iProcessId, iDebugInfoMask, iBuf);
}

extern WINAPI void wine32a_RtlQueryProcessDebugInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryProcessDebugInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryProcessDebugInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI unsigned char (*p__wine_dbg_get_channel_flags)(struct __wine_debug_channel * channel);
static WINAPI const char * (*p__wine_dbg_strdup)(const char * str);
static WINAPI int (*p__wine_dbg_output)(const char * str);
static WINAPI int (*p__wine_dbg_header)(enum __wine_debug_class cls, struct __wine_debug_channel * channel, const char * function);

extern WINAPI unsigned char wine32b___wine_dbg_get_channel_flags(struct __wine_debug_channel * channel)
{
	TRACE("Enter __wine_dbg_get_channel_flags\n");
	return p__wine_dbg_get_channel_flags(channel);
}

extern WINAPI void wine32a___wine_dbg_get_channel_flags(void);
__ASM_GLOBAL_FUNC(wine32a___wine_dbg_get_channel_flags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_dbg_get_channel_flags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI const char * wine32b___wine_dbg_strdup(const char * str)
{
	TRACE("Enter __wine_dbg_strdup\n");
	return p__wine_dbg_strdup(str);
}

extern WINAPI void wine32a___wine_dbg_strdup(void);
__ASM_GLOBAL_FUNC(wine32a___wine_dbg_strdup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_dbg_strdup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b___wine_dbg_output(const char * str)
{
	TRACE("Enter __wine_dbg_output\n");
	return p__wine_dbg_output(str);
}

extern WINAPI void wine32a___wine_dbg_output(void);
__ASM_GLOBAL_FUNC(wine32a___wine_dbg_output,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_dbg_output") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b___wine_dbg_header(enum __wine_debug_class cls, struct __wine_debug_channel * channel, const char * function)
{
	TRACE("Enter __wine_dbg_header\n");
	return p__wine_dbg_header(cls, channel, function);
}

extern WINAPI void wine32a___wine_dbg_header(void);
__ASM_GLOBAL_FUNC(wine32a___wine_dbg_header,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_dbg_header") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtQueryDirectoryFile)(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc_routine, PVOID apc_context, PIO_STATUS_BLOCK io, PVOID buffer, ULONG length, FILE_INFORMATION_CLASS info_class, BOOLEAN single_entry, PUNICODE_STRING mask, BOOLEAN restart_scan);
static WINAPI NTSTATUS (*pwine_nt_to_unix_file_name)(const UNICODE_STRING * nameW, ANSI_STRING * unix_name_ret, UINT disposition, BOOLEAN check_case);
static WINAPI NTSTATUS (*pRtlWow64EnableFsRedirection)(BOOLEAN enable);
static WINAPI NTSTATUS (*pRtlWow64EnableFsRedirectionEx)(ULONG disable, ULONG * old_value);
static WINAPI BOOLEAN (*pRtlDoesFileExists_U)(LPCWSTR file_name);

extern WINAPI NTSTATUS wine32b_NtQueryDirectoryFile(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc_routine, PVOID apc_context, PIO_STATUS_BLOCK io, PVOID buffer, ULONG length, FILE_INFORMATION_CLASS info_class, BOOLEAN single_entry, PUNICODE_STRING mask, BOOLEAN restart_scan)
{
	TRACE("Enter NtQueryDirectoryFile\n");
	return pNtQueryDirectoryFile(handle, event, apc_routine, apc_context, io, buffer, length, info_class, single_entry, mask, restart_scan);
}

extern WINAPI void wine32a_NtQueryDirectoryFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryDirectoryFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryDirectoryFile") "\n"
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

extern WINAPI NTSTATUS wine32b_wine_nt_to_unix_file_name(const UNICODE_STRING * nameW, ANSI_STRING * unix_name_ret, UINT disposition, BOOLEAN check_case)
{
	TRACE("Enter wine_nt_to_unix_file_name\n");
	return pwine_nt_to_unix_file_name(nameW, unix_name_ret, disposition, check_case);
}

extern WINAPI void wine32a_wine_nt_to_unix_file_name(void);
__ASM_GLOBAL_FUNC(wine32a_wine_nt_to_unix_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_nt_to_unix_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWow64EnableFsRedirection(BOOLEAN enable)
{
	TRACE("Enter RtlWow64EnableFsRedirection\n");
	return pRtlWow64EnableFsRedirection(enable);
}

extern WINAPI void wine32a_RtlWow64EnableFsRedirection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWow64EnableFsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWow64EnableFsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWow64EnableFsRedirectionEx(ULONG disable, ULONG * old_value)
{
	TRACE("Enter RtlWow64EnableFsRedirectionEx\n");
	return pRtlWow64EnableFsRedirectionEx(disable, old_value);
}

extern WINAPI void wine32a_RtlWow64EnableFsRedirectionEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWow64EnableFsRedirectionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWow64EnableFsRedirectionEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlDoesFileExists_U(LPCWSTR file_name)
{
	TRACE("Enter RtlDoesFileExists_U\n");
	return pRtlDoesFileExists_U(file_name);
}

extern WINAPI void wine32a_RtlDoesFileExists_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDoesFileExists_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDoesFileExists_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtQuerySystemEnvironmentValue)(PUNICODE_STRING VariableName, PWCHAR Value, ULONG ValueBufferLength, PULONG RequiredLength);
static WINAPI NTSTATUS (*pNtQuerySystemEnvironmentValueEx)(PUNICODE_STRING name, LPGUID vendor, PVOID value, PULONG retlength, PULONG attrib);
static WINAPI NTSTATUS (*pRtlCreateEnvironment)(BOOLEAN inherit, PWSTR * env);
static WINAPI NTSTATUS (*pRtlDestroyEnvironment)(PWSTR env);
static WINAPI NTSTATUS (*pRtlQueryEnvironmentVariable_U)(PWSTR env, PUNICODE_STRING name, PUNICODE_STRING value);
static WINAPI void (*pRtlSetCurrentEnvironment)(PWSTR new_env, PWSTR * old_env);
static WINAPI NTSTATUS (*pRtlSetEnvironmentVariable)(PWSTR * penv, PUNICODE_STRING name, PUNICODE_STRING value);
static WINAPI NTSTATUS (*pRtlExpandEnvironmentStrings)(const WCHAR * renv, WCHAR * src, SIZE_T src_len, WCHAR * dst, SIZE_T count, SIZE_T * plen);
static WINAPI NTSTATUS (*pRtlExpandEnvironmentStrings_U)(const WCHAR * env, const UNICODE_STRING * src, UNICODE_STRING * dst, ULONG * plen);
static WINAPI PRTL_USER_PROCESS_PARAMETERS (*pRtlNormalizeProcessParams)(RTL_USER_PROCESS_PARAMETERS * params);
static WINAPI PRTL_USER_PROCESS_PARAMETERS (*pRtlDeNormalizeProcessParams)(RTL_USER_PROCESS_PARAMETERS * params);
static WINAPI NTSTATUS (*pRtlCreateProcessParametersEx)(RTL_USER_PROCESS_PARAMETERS ** result, const UNICODE_STRING * ImagePathName, const UNICODE_STRING * DllPath, const UNICODE_STRING * CurrentDirectoryName, const UNICODE_STRING * CommandLine, PWSTR Environment, const UNICODE_STRING * WindowTitle, const UNICODE_STRING * Desktop, const UNICODE_STRING * ShellInfo, const UNICODE_STRING * RuntimeInfo, ULONG flags);
static WINAPI NTSTATUS (*pRtlCreateProcessParameters)(RTL_USER_PROCESS_PARAMETERS ** result, const UNICODE_STRING * image, const UNICODE_STRING * dllpath, const UNICODE_STRING * curdir, const UNICODE_STRING * cmdline, PWSTR env, const UNICODE_STRING * title, const UNICODE_STRING * desktop, const UNICODE_STRING * shellinfo, const UNICODE_STRING * runtime);
static WINAPI void (*pRtlDestroyProcessParameters)(RTL_USER_PROCESS_PARAMETERS * params);

extern WINAPI NTSTATUS wine32b_NtQuerySystemEnvironmentValue(PUNICODE_STRING VariableName, PWCHAR Value, ULONG ValueBufferLength, PULONG RequiredLength)
{
	TRACE("Enter NtQuerySystemEnvironmentValue\n");
	return pNtQuerySystemEnvironmentValue(VariableName, Value, ValueBufferLength, RequiredLength);
}

extern WINAPI void wine32a_NtQuerySystemEnvironmentValue(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySystemEnvironmentValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySystemEnvironmentValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySystemEnvironmentValueEx(PUNICODE_STRING name, LPGUID vendor, PVOID value, PULONG retlength, PULONG attrib)
{
	TRACE("Enter NtQuerySystemEnvironmentValueEx\n");
	return pNtQuerySystemEnvironmentValueEx(name, vendor, value, retlength, attrib);
}

extern WINAPI void wine32a_NtQuerySystemEnvironmentValueEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySystemEnvironmentValueEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySystemEnvironmentValueEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlCreateEnvironment(BOOLEAN inherit, PWSTR * env)
{
	TRACE("Enter RtlCreateEnvironment\n");
	return pRtlCreateEnvironment(inherit, env);
}

extern WINAPI void wine32a_RtlCreateEnvironment(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDestroyEnvironment(PWSTR env)
{
	TRACE("Enter RtlDestroyEnvironment\n");
	return pRtlDestroyEnvironment(env);
}

extern WINAPI void wine32a_RtlDestroyEnvironment(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryEnvironmentVariable_U(PWSTR env, PUNICODE_STRING name, PUNICODE_STRING value)
{
	TRACE("Enter RtlQueryEnvironmentVariable_U\n");
	return pRtlQueryEnvironmentVariable_U(env, name, value);
}

extern WINAPI void wine32a_RtlQueryEnvironmentVariable_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryEnvironmentVariable_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryEnvironmentVariable_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSetCurrentEnvironment(PWSTR new_env, PWSTR * old_env)
{
	TRACE("Enter RtlSetCurrentEnvironment\n");
	return pRtlSetCurrentEnvironment(new_env, old_env);
}

extern WINAPI void wine32a_RtlSetCurrentEnvironment(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetCurrentEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetCurrentEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetEnvironmentVariable(PWSTR * penv, PUNICODE_STRING name, PUNICODE_STRING value)
{
	TRACE("Enter RtlSetEnvironmentVariable\n");
	return pRtlSetEnvironmentVariable(penv, name, value);
}

extern WINAPI void wine32a_RtlSetEnvironmentVariable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetEnvironmentVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetEnvironmentVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlExpandEnvironmentStrings(const WCHAR * renv, WCHAR * src, SIZE_T src_len, WCHAR * dst, SIZE_T count, SIZE_T * plen)
{
	TRACE("Enter RtlExpandEnvironmentStrings\n");
	return pRtlExpandEnvironmentStrings(renv, src, src_len, dst, count, plen);
}

extern WINAPI void wine32a_RtlExpandEnvironmentStrings(void);
__ASM_GLOBAL_FUNC(wine32a_RtlExpandEnvironmentStrings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlExpandEnvironmentStrings") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlExpandEnvironmentStrings_U(const WCHAR * env, const UNICODE_STRING * src, UNICODE_STRING * dst, ULONG * plen)
{
	TRACE("Enter RtlExpandEnvironmentStrings_U\n");
	return pRtlExpandEnvironmentStrings_U(env, src, dst, plen);
}

extern WINAPI void wine32a_RtlExpandEnvironmentStrings_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlExpandEnvironmentStrings_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlExpandEnvironmentStrings_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PRTL_USER_PROCESS_PARAMETERS wine32b_RtlNormalizeProcessParams(RTL_USER_PROCESS_PARAMETERS * params)
{
	TRACE("Enter RtlNormalizeProcessParams\n");
	return pRtlNormalizeProcessParams(params);
}

extern WINAPI void wine32a_RtlNormalizeProcessParams(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNormalizeProcessParams,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNormalizeProcessParams") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PRTL_USER_PROCESS_PARAMETERS wine32b_RtlDeNormalizeProcessParams(RTL_USER_PROCESS_PARAMETERS * params)
{
	TRACE("Enter RtlDeNormalizeProcessParams\n");
	return pRtlDeNormalizeProcessParams(params);
}

extern WINAPI void wine32a_RtlDeNormalizeProcessParams(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeNormalizeProcessParams,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeNormalizeProcessParams") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateProcessParametersEx(RTL_USER_PROCESS_PARAMETERS ** result, const UNICODE_STRING * ImagePathName, const UNICODE_STRING * DllPath, const UNICODE_STRING * CurrentDirectoryName, const UNICODE_STRING * CommandLine, PWSTR Environment, const UNICODE_STRING * WindowTitle, const UNICODE_STRING * Desktop, const UNICODE_STRING * ShellInfo, const UNICODE_STRING * RuntimeInfo, ULONG flags)
{
	TRACE("Enter RtlCreateProcessParametersEx\n");
	return pRtlCreateProcessParametersEx(result, ImagePathName, DllPath, CurrentDirectoryName, CommandLine, Environment, WindowTitle, Desktop, ShellInfo, RuntimeInfo, flags);
}

extern WINAPI void wine32a_RtlCreateProcessParametersEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateProcessParametersEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateProcessParametersEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlCreateProcessParameters(RTL_USER_PROCESS_PARAMETERS ** result, const UNICODE_STRING * image, const UNICODE_STRING * dllpath, const UNICODE_STRING * curdir, const UNICODE_STRING * cmdline, PWSTR env, const UNICODE_STRING * title, const UNICODE_STRING * desktop, const UNICODE_STRING * shellinfo, const UNICODE_STRING * runtime)
{
	TRACE("Enter RtlCreateProcessParameters\n");
	return pRtlCreateProcessParameters(result, image, dllpath, curdir, cmdline, env, title, desktop, shellinfo, runtime);
}

extern WINAPI void wine32a_RtlCreateProcessParameters(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateProcessParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateProcessParameters") "\n"
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

extern WINAPI void wine32b_RtlDestroyProcessParameters(RTL_USER_PROCESS_PARAMETERS * params)
{
	TRACE("Enter RtlDestroyProcessParameters\n");
	return pRtlDestroyProcessParameters(params);
}

extern WINAPI void wine32a_RtlDestroyProcessParameters(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyProcessParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyProcessParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI ULONG (*pRtlNtStatusToDosErrorNoTeb)(NTSTATUS status);
static WINAPI ULONG (*pRtlNtStatusToDosError)(NTSTATUS status);
static WINAPI NTSTATUS (*pRtlGetLastNtStatus)(void);
static WINAPI DWORD (*pRtlGetLastWin32Error)(void);
static WINAPI NTSTATUS (*pNtRaiseHardError)(NTSTATUS ErrorStatus, ULONG NumberOfParameters, PUNICODE_STRING UnicodeStringParameterMask, PVOID * Parameters, HARDERROR_RESPONSE_OPTION ResponseOption, PHARDERROR_RESPONSE Response);
static WINAPI void (*pRtlSetLastWin32Error)(DWORD err);
static WINAPI void (*pRtlSetLastWin32ErrorAndNtStatusFromNtStatus)(NTSTATUS status);

extern WINAPI ULONG wine32b_RtlNtStatusToDosErrorNoTeb(NTSTATUS status)
{
	TRACE("Enter RtlNtStatusToDosErrorNoTeb\n");
	return pRtlNtStatusToDosErrorNoTeb(status);
}

extern WINAPI void wine32a_RtlNtStatusToDosErrorNoTeb(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNtStatusToDosErrorNoTeb,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNtStatusToDosErrorNoTeb") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlNtStatusToDosError(NTSTATUS status)
{
	TRACE("Enter RtlNtStatusToDosError\n");
	return pRtlNtStatusToDosError(status);
}

extern WINAPI void wine32a_RtlNtStatusToDosError(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNtStatusToDosError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNtStatusToDosError") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetLastNtStatus(void)
{
	TRACE("Enter RtlGetLastNtStatus\n");
	return pRtlGetLastNtStatus();
}

extern WINAPI void wine32a_RtlGetLastNtStatus(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetLastNtStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetLastNtStatus") "\n"
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

extern WINAPI DWORD wine32b_RtlGetLastWin32Error(void)
{
	TRACE("Enter RtlGetLastWin32Error\n");
	return pRtlGetLastWin32Error();
}

extern WINAPI void wine32a_RtlGetLastWin32Error(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetLastWin32Error,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetLastWin32Error") "\n"
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

extern WINAPI NTSTATUS wine32b_NtRaiseHardError(NTSTATUS ErrorStatus, ULONG NumberOfParameters, PUNICODE_STRING UnicodeStringParameterMask, PVOID * Parameters, HARDERROR_RESPONSE_OPTION ResponseOption, PHARDERROR_RESPONSE Response)
{
	TRACE("Enter NtRaiseHardError\n");
	return pNtRaiseHardError(ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ResponseOption, Response);
}

extern WINAPI void wine32a_NtRaiseHardError(void);
__ASM_GLOBAL_FUNC(wine32a_NtRaiseHardError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRaiseHardError") "\n"
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

extern WINAPI void wine32b_RtlSetLastWin32Error(DWORD err)
{
	TRACE("Enter RtlSetLastWin32Error\n");
	return pRtlSetLastWin32Error(err);
}

extern WINAPI void wine32a_RtlSetLastWin32Error(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetLastWin32Error,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetLastWin32Error") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSetLastWin32ErrorAndNtStatusFromNtStatus(NTSTATUS status)
{
	TRACE("Enter RtlSetLastWin32ErrorAndNtStatusFromNtStatus\n");
	return pRtlSetLastWin32ErrorAndNtStatusFromNtStatus(status);
}

extern WINAPI void wine32a_RtlSetLastWin32ErrorAndNtStatusFromNtStatus(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetLastWin32ErrorAndNtStatusFromNtStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetLastWin32ErrorAndNtStatusFromNtStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*pRtlRaiseStatus)(NTSTATUS status);
static WINAPI PVOID (*pRtlAddVectoredContinueHandler)(ULONG first, PVECTORED_EXCEPTION_HANDLER func);
static WINAPI ULONG (*pRtlRemoveVectoredContinueHandler)(PVOID handler);
static WINAPI PVOID (*pRtlAddVectoredExceptionHandler)(ULONG first, PVECTORED_EXCEPTION_HANDLER func);
static WINAPI ULONG (*pRtlRemoveVectoredExceptionHandler)(PVOID handler);
static WINAPI void (*pRtlSetUnhandledExceptionFilter)(PRTL_EXCEPTION_FILTER filter);
static WINAPI BOOLEAN (*pRtlAddFunctionTable)(RUNTIME_FUNCTION * table, DWORD count, ULONG_PTR addr);
static WINAPI BOOLEAN (*pRtlInstallFunctionTableCallback)(ULONG_PTR table, ULONG_PTR base, DWORD length, PGET_RUNTIME_FUNCTION_CALLBACK callback, PVOID context, PCWSTR dll);
static WINAPI DWORD (*pRtlAddGrowableFunctionTable)(void ** table, RUNTIME_FUNCTION * functions, DWORD count, DWORD max_count, ULONG_PTR base, ULONG_PTR end);
static WINAPI void (*pRtlGrowFunctionTable)(void * table, DWORD count);
static WINAPI void (*pRtlDeleteGrowableFunctionTable)(void * table);
static WINAPI BOOLEAN (*pRtlDeleteFunctionTable)(RUNTIME_FUNCTION * table);
static WINAPI PRUNTIME_FUNCTION (*pRtlLookupFunctionEntry)(ULONG_PTR pc, ULONG_PTR * base, UNWIND_HISTORY_TABLE * table);

extern WINAPI void wine32b_RtlRaiseStatus(NTSTATUS status)
{
	TRACE("Enter RtlRaiseStatus\n");
	return pRtlRaiseStatus(status);
}

extern WINAPI void wine32a_RtlRaiseStatus(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRaiseStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRaiseStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlAddVectoredContinueHandler(ULONG first, PVECTORED_EXCEPTION_HANDLER func)
{
	TRACE("Enter RtlAddVectoredContinueHandler\n");
	return pRtlAddVectoredContinueHandler(first, func);
}

extern WINAPI void wine32a_RtlAddVectoredContinueHandler(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddVectoredContinueHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddVectoredContinueHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlRemoveVectoredContinueHandler(PVOID handler)
{
	TRACE("Enter RtlRemoveVectoredContinueHandler\n");
	return pRtlRemoveVectoredContinueHandler(handler);
}

extern WINAPI void wine32a_RtlRemoveVectoredContinueHandler(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRemoveVectoredContinueHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRemoveVectoredContinueHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlAddVectoredExceptionHandler(ULONG first, PVECTORED_EXCEPTION_HANDLER func)
{
	TRACE("Enter RtlAddVectoredExceptionHandler\n");
	return pRtlAddVectoredExceptionHandler(first, func);
}

extern WINAPI void wine32a_RtlAddVectoredExceptionHandler(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddVectoredExceptionHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddVectoredExceptionHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlRemoveVectoredExceptionHandler(PVOID handler)
{
	TRACE("Enter RtlRemoveVectoredExceptionHandler\n");
	return pRtlRemoveVectoredExceptionHandler(handler);
}

extern WINAPI void wine32a_RtlRemoveVectoredExceptionHandler(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRemoveVectoredExceptionHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRemoveVectoredExceptionHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSetUnhandledExceptionFilter(PRTL_EXCEPTION_FILTER filter)
{
	TRACE("Enter RtlSetUnhandledExceptionFilter\n");
	return pRtlSetUnhandledExceptionFilter(filter);
}

extern WINAPI void wine32a_RtlSetUnhandledExceptionFilter(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetUnhandledExceptionFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetUnhandledExceptionFilter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlAddFunctionTable(RUNTIME_FUNCTION * table, DWORD count, ULONG_PTR addr)
{
	TRACE("Enter RtlAddFunctionTable\n");
	return pRtlAddFunctionTable(table, count, addr);
}

extern WINAPI void wine32a_RtlAddFunctionTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlInstallFunctionTableCallback(ULONG_PTR table, ULONG_PTR base, DWORD length, PGET_RUNTIME_FUNCTION_CALLBACK callback, PVOID context, PCWSTR dll)
{
	TRACE("Enter RtlInstallFunctionTableCallback\n");
	return pRtlInstallFunctionTableCallback(table, base, length, callback, context, dll);
}

extern WINAPI void wine32a_RtlInstallFunctionTableCallback(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInstallFunctionTableCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInstallFunctionTableCallback") "\n"
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

extern WINAPI DWORD wine32b_RtlAddGrowableFunctionTable(void ** table, RUNTIME_FUNCTION * functions, DWORD count, DWORD max_count, ULONG_PTR base, ULONG_PTR end)
{
	TRACE("Enter RtlAddGrowableFunctionTable\n");
	return pRtlAddGrowableFunctionTable(table, functions, count, max_count, base, end);
}

extern WINAPI void wine32a_RtlAddGrowableFunctionTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddGrowableFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddGrowableFunctionTable") "\n"
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

extern WINAPI void wine32b_RtlGrowFunctionTable(void * table, DWORD count)
{
	TRACE("Enter RtlGrowFunctionTable\n");
	return pRtlGrowFunctionTable(table, count);
}

extern WINAPI void wine32a_RtlGrowFunctionTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGrowFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGrowFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlDeleteGrowableFunctionTable(void * table)
{
	TRACE("Enter RtlDeleteGrowableFunctionTable\n");
	return pRtlDeleteGrowableFunctionTable(table);
}

extern WINAPI void wine32a_RtlDeleteGrowableFunctionTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteGrowableFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteGrowableFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlDeleteFunctionTable(RUNTIME_FUNCTION * table)
{
	TRACE("Enter RtlDeleteFunctionTable\n");
	return pRtlDeleteFunctionTable(table);
}

extern WINAPI void wine32a_RtlDeleteFunctionTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PRUNTIME_FUNCTION wine32b_RtlLookupFunctionEntry(ULONG_PTR pc, ULONG_PTR * base, UNWIND_HISTORY_TABLE * table)
{
	TRACE("Enter RtlLookupFunctionEntry\n");
	return pRtlLookupFunctionEntry(pc, base, table);
}

extern WINAPI void wine32a_RtlLookupFunctionEntry(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLookupFunctionEntry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLookupFunctionEntry") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtOpenFile)(PHANDLE handle, ACCESS_MASK access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK io, ULONG sharing, ULONG options);
static WINAPI NTSTATUS (*pNtCreateFile)(PHANDLE handle, ACCESS_MASK access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK io, PLARGE_INTEGER alloc_size, ULONG attributes, ULONG sharing, ULONG disposition, ULONG options, PVOID ea_buffer, ULONG ea_length);
static WINAPI NTSTATUS (*pNtReadFile)(HANDLE hFile, HANDLE hEvent, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, void * buffer, ULONG length, PLARGE_INTEGER offset, PULONG key);
static WINAPI NTSTATUS (*pNtReadFileScatter)(HANDLE file, HANDLE event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, FILE_SEGMENT_ELEMENT * segments, ULONG length, PLARGE_INTEGER offset, PULONG key);
static WINAPI NTSTATUS (*pNtWriteFile)(HANDLE hFile, HANDLE hEvent, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, const void * buffer, ULONG length, PLARGE_INTEGER offset, PULONG key);
static WINAPI NTSTATUS (*pNtWriteFileGather)(HANDLE file, HANDLE event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, FILE_SEGMENT_ELEMENT * segments, ULONG length, PLARGE_INTEGER offset, PULONG key);
static WINAPI NTSTATUS (*pNtDeviceIoControlFile)(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, PVOID apc_context, PIO_STATUS_BLOCK io, ULONG code, PVOID in_buffer, ULONG in_size, PVOID out_buffer, ULONG out_size);
static WINAPI NTSTATUS (*pNtFsControlFile)(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, PVOID apc_context, PIO_STATUS_BLOCK io, ULONG code, PVOID in_buffer, ULONG in_size, PVOID out_buffer, ULONG out_size);
static WINAPI NTSTATUS (*pNtNotifyChangeDirectoryFile)(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, void * apc_context, PIO_STATUS_BLOCK iosb, void * buffer, ULONG buffer_size, ULONG filter, BOOLEAN subtree);
static WINAPI NTSTATUS (*pNtSetVolumeInformationFile)(HANDLE FileHandle, PIO_STATUS_BLOCK IoStatusBlock, PVOID FsInformation, ULONG Length, FS_INFORMATION_CLASS FsInformationClass);
static WINAPI NTSTATUS (*pNtQueryInformationFile)(HANDLE hFile, PIO_STATUS_BLOCK io, PVOID ptr, LONG len, FILE_INFORMATION_CLASS class);
static WINAPI NTSTATUS (*pNtSetInformationFile)(HANDLE handle, PIO_STATUS_BLOCK io, PVOID ptr, ULONG len, FILE_INFORMATION_CLASS class);
static WINAPI NTSTATUS (*pNtQueryFullAttributesFile)(const OBJECT_ATTRIBUTES * attr, FILE_NETWORK_OPEN_INFORMATION * info);
static WINAPI NTSTATUS (*pNtQueryAttributesFile)(const OBJECT_ATTRIBUTES * attr, FILE_BASIC_INFORMATION * info);
static WINAPI NTSTATUS (*pNtQueryVolumeInformationFile)(HANDLE handle, PIO_STATUS_BLOCK io, PVOID buffer, ULONG length, FS_INFORMATION_CLASS info_class);
static WINAPI NTSTATUS (*pNtQueryEaFile)(HANDLE hFile, PIO_STATUS_BLOCK iosb, PVOID buffer, ULONG length, BOOLEAN single_entry, PVOID ea_list, ULONG ea_list_len, PULONG ea_index, BOOLEAN restart);
static WINAPI NTSTATUS (*pNtSetEaFile)(HANDLE hFile, PIO_STATUS_BLOCK iosb, PVOID buffer, ULONG length);
static WINAPI NTSTATUS (*pNtFlushBuffersFile)(HANDLE hFile, IO_STATUS_BLOCK * io);
static WINAPI NTSTATUS (*pNtLockFile)(HANDLE hFile, HANDLE lock_granted_event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, PLARGE_INTEGER offset, PLARGE_INTEGER count, ULONG * key, BOOLEAN dont_wait, BOOLEAN exclusive);
static WINAPI NTSTATUS (*pNtUnlockFile)(HANDLE hFile, PIO_STATUS_BLOCK io_status, PLARGE_INTEGER offset, PLARGE_INTEGER count, PULONG key);
static WINAPI NTSTATUS (*pNtCreateNamedPipeFile)(PHANDLE handle, ULONG access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK iosb, ULONG sharing, ULONG dispo, ULONG options, ULONG pipe_type, ULONG read_mode, ULONG completion_mode, ULONG max_inst, ULONG inbound_quota, ULONG outbound_quota, PLARGE_INTEGER timeout);
static WINAPI NTSTATUS (*pNtDeleteFile)(POBJECT_ATTRIBUTES ObjectAttributes);
static WINAPI NTSTATUS (*pNtCancelIoFileEx)(HANDLE hFile, PIO_STATUS_BLOCK iosb, PIO_STATUS_BLOCK io_status);
static WINAPI NTSTATUS (*pNtCancelIoFile)(HANDLE hFile, PIO_STATUS_BLOCK io_status);
static WINAPI NTSTATUS (*pNtCreateMailslotFile)(PHANDLE pHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK IoStatusBlock, ULONG CreateOptions, ULONG MailslotQuota, ULONG MaxMessageSize, PLARGE_INTEGER TimeOut);

extern WINAPI NTSTATUS wine32b_NtOpenFile(PHANDLE handle, ACCESS_MASK access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK io, ULONG sharing, ULONG options)
{
	TRACE("Enter NtOpenFile\n");
	return pNtOpenFile(handle, access, attr, io, sharing, options);
}

extern WINAPI void wine32a_NtOpenFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCreateFile(PHANDLE handle, ACCESS_MASK access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK io, PLARGE_INTEGER alloc_size, ULONG attributes, ULONG sharing, ULONG disposition, ULONG options, PVOID ea_buffer, ULONG ea_length)
{
	TRACE("Enter NtCreateFile\n");
	return pNtCreateFile(handle, access, attr, io, alloc_size, attributes, sharing, disposition, options, ea_buffer, ea_length);
}

extern WINAPI void wine32a_NtCreateFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtReadFile(HANDLE hFile, HANDLE hEvent, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, void * buffer, ULONG length, PLARGE_INTEGER offset, PULONG key)
{
	TRACE("Enter NtReadFile\n");
	return pNtReadFile(hFile, hEvent, apc, apc_user, io_status, buffer, length, offset, key);
}

extern WINAPI void wine32a_NtReadFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtReadFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReadFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtReadFileScatter(HANDLE file, HANDLE event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, FILE_SEGMENT_ELEMENT * segments, ULONG length, PLARGE_INTEGER offset, PULONG key)
{
	TRACE("Enter NtReadFileScatter\n");
	return pNtReadFileScatter(file, event, apc, apc_user, io_status, segments, length, offset, key);
}

extern WINAPI void wine32a_NtReadFileScatter(void);
__ASM_GLOBAL_FUNC(wine32a_NtReadFileScatter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReadFileScatter") "\n"
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

extern WINAPI NTSTATUS wine32b_NtWriteFile(HANDLE hFile, HANDLE hEvent, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, const void * buffer, ULONG length, PLARGE_INTEGER offset, PULONG key)
{
	TRACE("Enter NtWriteFile\n");
	return pNtWriteFile(hFile, hEvent, apc, apc_user, io_status, buffer, length, offset, key);
}

extern WINAPI void wine32a_NtWriteFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtWriteFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWriteFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtWriteFileGather(HANDLE file, HANDLE event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, FILE_SEGMENT_ELEMENT * segments, ULONG length, PLARGE_INTEGER offset, PULONG key)
{
	TRACE("Enter NtWriteFileGather\n");
	return pNtWriteFileGather(file, event, apc, apc_user, io_status, segments, length, offset, key);
}

extern WINAPI void wine32a_NtWriteFileGather(void);
__ASM_GLOBAL_FUNC(wine32a_NtWriteFileGather,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWriteFileGather") "\n"
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

extern WINAPI NTSTATUS wine32b_NtDeviceIoControlFile(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, PVOID apc_context, PIO_STATUS_BLOCK io, ULONG code, PVOID in_buffer, ULONG in_size, PVOID out_buffer, ULONG out_size)
{
	TRACE("Enter NtDeviceIoControlFile\n");
	return pNtDeviceIoControlFile(handle, event, apc, apc_context, io, code, in_buffer, in_size, out_buffer, out_size);
}

extern WINAPI void wine32a_NtDeviceIoControlFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtDeviceIoControlFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDeviceIoControlFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtFsControlFile(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, PVOID apc_context, PIO_STATUS_BLOCK io, ULONG code, PVOID in_buffer, ULONG in_size, PVOID out_buffer, ULONG out_size)
{
	TRACE("Enter NtFsControlFile\n");
	return pNtFsControlFile(handle, event, apc, apc_context, io, code, in_buffer, in_size, out_buffer, out_size);
}

extern WINAPI void wine32a_NtFsControlFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtFsControlFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFsControlFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtNotifyChangeDirectoryFile(HANDLE handle, HANDLE event, PIO_APC_ROUTINE apc, void * apc_context, PIO_STATUS_BLOCK iosb, void * buffer, ULONG buffer_size, ULONG filter, BOOLEAN subtree)
{
	TRACE("Enter NtNotifyChangeDirectoryFile\n");
	return pNtNotifyChangeDirectoryFile(handle, event, apc, apc_context, iosb, buffer, buffer_size, filter, subtree);
}

extern WINAPI void wine32a_NtNotifyChangeDirectoryFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtNotifyChangeDirectoryFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtNotifyChangeDirectoryFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetVolumeInformationFile(HANDLE FileHandle, PIO_STATUS_BLOCK IoStatusBlock, PVOID FsInformation, ULONG Length, FS_INFORMATION_CLASS FsInformationClass)
{
	TRACE("Enter NtSetVolumeInformationFile\n");
	return pNtSetVolumeInformationFile(FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass);
}

extern WINAPI void wine32a_NtSetVolumeInformationFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetVolumeInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetVolumeInformationFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryInformationFile(HANDLE hFile, PIO_STATUS_BLOCK io, PVOID ptr, LONG len, FILE_INFORMATION_CLASS class)
{
	TRACE("Enter NtQueryInformationFile\n");
	return pNtQueryInformationFile(hFile, io, ptr, len, class);
}

extern WINAPI void wine32a_NtQueryInformationFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationFile(HANDLE handle, PIO_STATUS_BLOCK io, PVOID ptr, ULONG len, FILE_INFORMATION_CLASS class)
{
	TRACE("Enter NtSetInformationFile\n");
	return pNtSetInformationFile(handle, io, ptr, len, class);
}

extern WINAPI void wine32a_NtSetInformationFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryFullAttributesFile(const OBJECT_ATTRIBUTES * attr, FILE_NETWORK_OPEN_INFORMATION * info)
{
	TRACE("Enter NtQueryFullAttributesFile\n");
	return pNtQueryFullAttributesFile(attr, info);
}

extern WINAPI void wine32a_NtQueryFullAttributesFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryFullAttributesFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryFullAttributesFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryAttributesFile(const OBJECT_ATTRIBUTES * attr, FILE_BASIC_INFORMATION * info)
{
	TRACE("Enter NtQueryAttributesFile\n");
	return pNtQueryAttributesFile(attr, info);
}

extern WINAPI void wine32a_NtQueryAttributesFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryAttributesFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryAttributesFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryVolumeInformationFile(HANDLE handle, PIO_STATUS_BLOCK io, PVOID buffer, ULONG length, FS_INFORMATION_CLASS info_class)
{
	TRACE("Enter NtQueryVolumeInformationFile\n");
	return pNtQueryVolumeInformationFile(handle, io, buffer, length, info_class);
}

extern WINAPI void wine32a_NtQueryVolumeInformationFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryVolumeInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryVolumeInformationFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryEaFile(HANDLE hFile, PIO_STATUS_BLOCK iosb, PVOID buffer, ULONG length, BOOLEAN single_entry, PVOID ea_list, ULONG ea_list_len, PULONG ea_index, BOOLEAN restart)
{
	TRACE("Enter NtQueryEaFile\n");
	return pNtQueryEaFile(hFile, iosb, buffer, length, single_entry, ea_list, ea_list_len, ea_index, restart);
}

extern WINAPI void wine32a_NtQueryEaFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryEaFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryEaFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetEaFile(HANDLE hFile, PIO_STATUS_BLOCK iosb, PVOID buffer, ULONG length)
{
	TRACE("Enter NtSetEaFile\n");
	return pNtSetEaFile(hFile, iosb, buffer, length);
}

extern WINAPI void wine32a_NtSetEaFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetEaFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetEaFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtFlushBuffersFile(HANDLE hFile, IO_STATUS_BLOCK * io)
{
	TRACE("Enter NtFlushBuffersFile\n");
	return pNtFlushBuffersFile(hFile, io);
}

extern WINAPI void wine32a_NtFlushBuffersFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtFlushBuffersFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFlushBuffersFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtLockFile(HANDLE hFile, HANDLE lock_granted_event, PIO_APC_ROUTINE apc, void * apc_user, PIO_STATUS_BLOCK io_status, PLARGE_INTEGER offset, PLARGE_INTEGER count, ULONG * key, BOOLEAN dont_wait, BOOLEAN exclusive)
{
	TRACE("Enter NtLockFile\n");
	return pNtLockFile(hFile, lock_granted_event, apc, apc_user, io_status, offset, count, key, dont_wait, exclusive);
}

extern WINAPI void wine32a_NtLockFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtLockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtLockFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtUnlockFile(HANDLE hFile, PIO_STATUS_BLOCK io_status, PLARGE_INTEGER offset, PLARGE_INTEGER count, PULONG key)
{
	TRACE("Enter NtUnlockFile\n");
	return pNtUnlockFile(hFile, io_status, offset, count, key);
}

extern WINAPI void wine32a_NtUnlockFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtUnlockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtUnlockFile") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCreateNamedPipeFile(PHANDLE handle, ULONG access, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK iosb, ULONG sharing, ULONG dispo, ULONG options, ULONG pipe_type, ULONG read_mode, ULONG completion_mode, ULONG max_inst, ULONG inbound_quota, ULONG outbound_quota, PLARGE_INTEGER timeout)
{
	TRACE("Enter NtCreateNamedPipeFile\n");
	return pNtCreateNamedPipeFile(handle, access, attr, iosb, sharing, dispo, options, pipe_type, read_mode, completion_mode, max_inst, inbound_quota, outbound_quota, timeout);
}

extern WINAPI void wine32a_NtCreateNamedPipeFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateNamedPipeFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateNamedPipeFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $56, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtDeleteFile(POBJECT_ATTRIBUTES ObjectAttributes)
{
	TRACE("Enter NtDeleteFile\n");
	return pNtDeleteFile(ObjectAttributes);
}

extern WINAPI void wine32a_NtDeleteFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtDeleteFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDeleteFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCancelIoFileEx(HANDLE hFile, PIO_STATUS_BLOCK iosb, PIO_STATUS_BLOCK io_status)
{
	TRACE("Enter NtCancelIoFileEx\n");
	return pNtCancelIoFileEx(hFile, iosb, io_status);
}

extern WINAPI void wine32a_NtCancelIoFileEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtCancelIoFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCancelIoFileEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCancelIoFile(HANDLE hFile, PIO_STATUS_BLOCK io_status)
{
	TRACE("Enter NtCancelIoFile\n");
	return pNtCancelIoFile(hFile, io_status);
}

extern WINAPI void wine32a_NtCancelIoFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtCancelIoFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCancelIoFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateMailslotFile(PHANDLE pHandle, ULONG DesiredAccess, POBJECT_ATTRIBUTES attr, PIO_STATUS_BLOCK IoStatusBlock, ULONG CreateOptions, ULONG MailslotQuota, ULONG MaxMessageSize, PLARGE_INTEGER TimeOut)
{
	TRACE("Enter NtCreateMailslotFile\n");
	return pNtCreateMailslotFile(pHandle, DesiredAccess, attr, IoStatusBlock, CreateOptions, MailslotQuota, MaxMessageSize, TimeOut);
}

extern WINAPI void wine32a_NtCreateMailslotFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateMailslotFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateMailslotFile") "\n"
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

static WINAPI void (*pRtlInitializeHandleTable)(ULONG MaxHandleCount, ULONG HandleSize, RTL_HANDLE_TABLE * HandleTable);
static WINAPI NTSTATUS (*pRtlDestroyHandleTable)(RTL_HANDLE_TABLE * HandleTable);
static WINAPI RTL_HANDLE * (*pRtlAllocateHandle)(RTL_HANDLE_TABLE * HandleTable, ULONG * HandleIndex);
static WINAPI BOOLEAN (*pRtlFreeHandle)(RTL_HANDLE_TABLE * HandleTable, RTL_HANDLE * Handle);
static WINAPI BOOLEAN (*pRtlIsValidHandle)(const RTL_HANDLE_TABLE * HandleTable, const RTL_HANDLE * Handle);
static WINAPI BOOLEAN (*pRtlIsValidIndexHandle)(const RTL_HANDLE_TABLE * HandleTable, ULONG Index, RTL_HANDLE ** ValidHandle);

extern WINAPI void wine32b_RtlInitializeHandleTable(ULONG MaxHandleCount, ULONG HandleSize, RTL_HANDLE_TABLE * HandleTable)
{
	TRACE("Enter RtlInitializeHandleTable\n");
	return pRtlInitializeHandleTable(MaxHandleCount, HandleSize, HandleTable);
}

extern WINAPI void wine32a_RtlInitializeHandleTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeHandleTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeHandleTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDestroyHandleTable(RTL_HANDLE_TABLE * HandleTable)
{
	TRACE("Enter RtlDestroyHandleTable\n");
	return pRtlDestroyHandleTable(HandleTable);
}

extern WINAPI void wine32a_RtlDestroyHandleTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyHandleTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyHandleTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI RTL_HANDLE * wine32b_RtlAllocateHandle(RTL_HANDLE_TABLE * HandleTable, ULONG * HandleIndex)
{
	TRACE("Enter RtlAllocateHandle\n");
	return pRtlAllocateHandle(HandleTable, HandleIndex);
}

extern WINAPI void wine32a_RtlAllocateHandle(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAllocateHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAllocateHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlFreeHandle(RTL_HANDLE_TABLE * HandleTable, RTL_HANDLE * Handle)
{
	TRACE("Enter RtlFreeHandle\n");
	return pRtlFreeHandle(HandleTable, Handle);
}

extern WINAPI void wine32a_RtlFreeHandle(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlIsValidHandle(const RTL_HANDLE_TABLE * HandleTable, const RTL_HANDLE * Handle)
{
	TRACE("Enter RtlIsValidHandle\n");
	return pRtlIsValidHandle(HandleTable, Handle);
}

extern WINAPI void wine32a_RtlIsValidHandle(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsValidHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsValidHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlIsValidIndexHandle(const RTL_HANDLE_TABLE * HandleTable, ULONG Index, RTL_HANDLE ** ValidHandle)
{
	TRACE("Enter RtlIsValidIndexHandle\n");
	return pRtlIsValidIndexHandle(HandleTable, Index, ValidHandle);
}

extern WINAPI void wine32a_RtlIsValidIndexHandle(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsValidIndexHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsValidIndexHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI HANDLE (*pRtlCreateHeap)(ULONG flags, PVOID addr, SIZE_T totalSize, SIZE_T commitSize, PVOID unknown, PRTL_HEAP_DEFINITION definition);
static WINAPI HANDLE (*pRtlDestroyHeap)(HANDLE heap);
static WINAPI PVOID (*pRtlAllocateHeap)(HANDLE heap, ULONG flags, SIZE_T size);
static WINAPI BOOLEAN (*pRtlFreeHeap)(HANDLE heap, ULONG flags, void * ptr);
static WINAPI PVOID (*pRtlReAllocateHeap)(HANDLE heap, ULONG flags, PVOID ptr, SIZE_T size);
static WINAPI ULONG (*pRtlCompactHeap)(HANDLE heap, ULONG flags);
static WINAPI BOOLEAN (*pRtlLockHeap)(HANDLE heap);
static WINAPI BOOLEAN (*pRtlUnlockHeap)(HANDLE heap);
static WINAPI SIZE_T (*pRtlSizeHeap)(HANDLE heap, ULONG flags, const void * ptr);
static WINAPI BOOLEAN (*pRtlValidateHeap)(HANDLE heap, ULONG flags, LPCVOID ptr);
static WINAPI NTSTATUS (*pRtlWalkHeap)(HANDLE heap, PVOID entry_ptr);
static WINAPI ULONG (*pRtlGetProcessHeaps)(ULONG count, HANDLE * heaps);
static WINAPI NTSTATUS (*pRtlQueryHeapInformation)(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size_in, PSIZE_T size_out);
static WINAPI NTSTATUS (*pRtlSetHeapInformation)(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size);

extern WINAPI HANDLE wine32b_RtlCreateHeap(ULONG flags, PVOID addr, SIZE_T totalSize, SIZE_T commitSize, PVOID unknown, PRTL_HEAP_DEFINITION definition)
{
	TRACE("Enter RtlCreateHeap\n");
	return pRtlCreateHeap(flags, addr, totalSize, commitSize, unknown, definition);
}

extern WINAPI void wine32a_RtlCreateHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateHeap") "\n"
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

extern WINAPI HANDLE wine32b_RtlDestroyHeap(HANDLE heap)
{
	TRACE("Enter RtlDestroyHeap\n");
	return pRtlDestroyHeap(heap);
}

extern WINAPI void wine32a_RtlDestroyHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDestroyHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDestroyHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlAllocateHeap(HANDLE heap, ULONG flags, SIZE_T size)
{
	TRACE("Enter RtlAllocateHeap\n");
	return pRtlAllocateHeap(heap, flags, size);
}

extern WINAPI void wine32a_RtlAllocateHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAllocateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAllocateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlFreeHeap(HANDLE heap, ULONG flags, void * ptr)
{
	TRACE("Enter RtlFreeHeap\n");
	return pRtlFreeHeap(heap, flags, ptr);
}

extern WINAPI void wine32a_RtlFreeHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlReAllocateHeap(HANDLE heap, ULONG flags, PVOID ptr, SIZE_T size)
{
	TRACE("Enter RtlReAllocateHeap\n");
	return pRtlReAllocateHeap(heap, flags, ptr, size);
}

extern WINAPI void wine32a_RtlReAllocateHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReAllocateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReAllocateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlCompactHeap(HANDLE heap, ULONG flags)
{
	TRACE("Enter RtlCompactHeap\n");
	return pRtlCompactHeap(heap, flags);
}

extern WINAPI void wine32a_RtlCompactHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompactHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompactHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlLockHeap(HANDLE heap)
{
	TRACE("Enter RtlLockHeap\n");
	return pRtlLockHeap(heap);
}

extern WINAPI void wine32a_RtlLockHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLockHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLockHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlUnlockHeap(HANDLE heap)
{
	TRACE("Enter RtlUnlockHeap\n");
	return pRtlUnlockHeap(heap);
}

extern WINAPI void wine32a_RtlUnlockHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnlockHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnlockHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_RtlSizeHeap(HANDLE heap, ULONG flags, const void * ptr)
{
	TRACE("Enter RtlSizeHeap\n");
	return pRtlSizeHeap(heap, flags, ptr);
}

extern WINAPI void wine32a_RtlSizeHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSizeHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSizeHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlValidateHeap(HANDLE heap, ULONG flags, LPCVOID ptr)
{
	TRACE("Enter RtlValidateHeap\n");
	return pRtlValidateHeap(heap, flags, ptr);
}

extern WINAPI void wine32a_RtlValidateHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlValidateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlValidateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWalkHeap(HANDLE heap, PVOID entry_ptr)
{
	TRACE("Enter RtlWalkHeap\n");
	return pRtlWalkHeap(heap, entry_ptr);
}

extern WINAPI void wine32a_RtlWalkHeap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWalkHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWalkHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlGetProcessHeaps(ULONG count, HANDLE * heaps)
{
	TRACE("Enter RtlGetProcessHeaps\n");
	return pRtlGetProcessHeaps(count, heaps);
}

extern WINAPI void wine32a_RtlGetProcessHeaps(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetProcessHeaps,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetProcessHeaps") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryHeapInformation(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size_in, PSIZE_T size_out)
{
	TRACE("Enter RtlQueryHeapInformation\n");
	return pRtlQueryHeapInformation(heap, info_class, info, size_in, size_out);
}

extern WINAPI void wine32a_RtlQueryHeapInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryHeapInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryHeapInformation") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlSetHeapInformation(HANDLE heap, HEAP_INFORMATION_CLASS info_class, PVOID info, SIZE_T size)
{
	TRACE("Enter RtlSetHeapInformation\n");
	return pRtlSetHeapInformation(heap, info_class, info, size);
}

extern WINAPI void wine32a_RtlSetHeapInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetHeapInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetHeapInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pRtlLargeIntegerToChar)(const ULONGLONG * value_ptr, ULONG base, ULONG length, PCHAR str);
static WINAPI NTSTATUS (*pRtlInt64ToUnicodeString)(ULONGLONG value, ULONG base, UNICODE_STRING * str);

extern WINAPI NTSTATUS wine32b_RtlLargeIntegerToChar(const ULONGLONG * value_ptr, ULONG base, ULONG length, PCHAR str)
{
	TRACE("Enter RtlLargeIntegerToChar\n");
	return pRtlLargeIntegerToChar(value_ptr, base, length, str);
}

extern WINAPI void wine32a_RtlLargeIntegerToChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLargeIntegerToChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLargeIntegerToChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlInt64ToUnicodeString(ULONGLONG value, ULONG base, UNICODE_STRING * str)
{
	TRACE("Enter RtlInt64ToUnicodeString\n");
	return pRtlInt64ToUnicodeString(value, base, str);
}

extern WINAPI void wine32a_RtlInt64ToUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInt64ToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInt64ToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI RTL_UNLOAD_EVENT_TRACE * (*pRtlGetUnloadEventTrace)(void);
static WINAPI void (*pRtlGetUnloadEventTraceEx)(ULONG ** size, ULONG ** count, void ** trace);
static WINAPI NTSTATUS (*pLdrDisableThreadCalloutsForDll)(HMODULE hModule);
static WINAPI NTSTATUS (*pLdrFindEntryForAddress)(const void * addr, PLDR_MODULE * pmod);
static WINAPI NTSTATUS (*pLdrEnumerateLoadedModules)(void * unknown, LDRENUMPROC callback, void * context);
static WINAPI NTSTATUS (*pLdrRegisterDllNotification)(ULONG flags, PLDR_DLL_NOTIFICATION_FUNCTION callback, void * context, void ** cookie);
static WINAPI NTSTATUS (*pLdrUnregisterDllNotification)(void * cookie);
static WINAPI NTSTATUS (*pLdrLockLoaderLock)(ULONG flags, ULONG * result, ULONG_PTR * magic);
static WINAPI NTSTATUS (*pLdrUnlockLoaderLock)(ULONG flags, ULONG_PTR magic);
static WINAPI NTSTATUS (*pLdrGetProcedureAddress)(HMODULE module, const ANSI_STRING * name, ULONG ord, PVOID * address);
static WINAPI NTSTATUS (*pLdrLoadDll)(LPCWSTR path_name, DWORD flags, const UNICODE_STRING * libname, HMODULE * hModule);
static WINAPI NTSTATUS (*pLdrGetDllHandle)(LPCWSTR load_path, ULONG flags, const UNICODE_STRING * name, HMODULE * base);
static WINAPI NTSTATUS (*pLdrAddRefDll)(ULONG flags, HMODULE module);
static WINAPI IMAGE_BASE_RELOCATION * (*pLdrProcessRelocationBlock)(void * page, UINT count, USHORT * relocs, INT_PTR delta);
static WINAPI NTSTATUS (*pLdrQueryProcessModuleInformation)(PSYSTEM_MODULE_INFORMATION smi, ULONG buf_size, ULONG * req_size);
static WINAPI NTSTATUS (*pLdrQueryImageFileExecutionOptions)(const UNICODE_STRING * key, LPCWSTR value, ULONG type, void * data, ULONG in_size, ULONG * out_size);
static WINAPI BOOLEAN (*pRtlDllShutdownInProgress)(void);
static WINAPI void * (*pLdrResolveDelayLoadedAPI)(void * base, const IMAGE_DELAYLOAD_DESCRIPTOR * desc, PDELAYLOAD_FAILURE_DLL_CALLBACK dllhook, PDELAYLOAD_FAILURE_SYSTEM_ROUTINE syshook, IMAGE_THUNK_DATA * addr, ULONG flags);
static WINAPI void (*pLdrShutdownProcess)(void);
static WINAPI void (*pRtlExitUserProcess)(DWORD status);
static WINAPI void (*pLdrShutdownThread)(void);
static WINAPI NTSTATUS (*pLdrUnloadDll)(HMODULE hModule);
static WINAPI PIMAGE_NT_HEADERS (*pRtlImageNtHeader)(HMODULE hModule);
static WINAPI void (*pLdrInitializeThunk)(CONTEXT * context, void ** entry, ULONG_PTR unknown3, ULONG_PTR unknown4);
static WINAPI PVOID (*pRtlImageDirectoryEntryToData)(HMODULE module, BOOL image, WORD dir, ULONG * size);
static WINAPI PIMAGE_SECTION_HEADER (*pRtlImageRvaToSection)(const IMAGE_NT_HEADERS * nt, HMODULE module, DWORD rva);
static WINAPI PVOID (*pRtlImageRvaToVa)(const IMAGE_NT_HEADERS * nt, HMODULE module, DWORD rva, IMAGE_SECTION_HEADER ** section);
static WINAPI PVOID (*pRtlPcToFileHeader)(PVOID pc, PVOID * address);
static WINAPI NTSTATUS (*pNtLoadDriver)(const UNICODE_STRING * DriverServiceName);
static WINAPI NTSTATUS (*pNtUnloadDriver)(const UNICODE_STRING * DriverServiceName);

extern WINAPI RTL_UNLOAD_EVENT_TRACE * wine32b_RtlGetUnloadEventTrace(void)
{
	TRACE("Enter RtlGetUnloadEventTrace\n");
	return pRtlGetUnloadEventTrace();
}

extern WINAPI void wine32a_RtlGetUnloadEventTrace(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetUnloadEventTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetUnloadEventTrace") "\n"
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

extern WINAPI void wine32b_RtlGetUnloadEventTraceEx(ULONG ** size, ULONG ** count, void ** trace)
{
	TRACE("Enter RtlGetUnloadEventTraceEx\n");
	return pRtlGetUnloadEventTraceEx(size, count, trace);
}

extern WINAPI void wine32a_RtlGetUnloadEventTraceEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetUnloadEventTraceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetUnloadEventTraceEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrDisableThreadCalloutsForDll(HMODULE hModule)
{
	TRACE("Enter LdrDisableThreadCalloutsForDll\n");
	return pLdrDisableThreadCalloutsForDll(hModule);
}

extern WINAPI void wine32a_LdrDisableThreadCalloutsForDll(void);
__ASM_GLOBAL_FUNC(wine32a_LdrDisableThreadCalloutsForDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrDisableThreadCalloutsForDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrFindEntryForAddress(const void * addr, PLDR_MODULE * pmod)
{
	TRACE("Enter LdrFindEntryForAddress\n");
	return pLdrFindEntryForAddress(addr, pmod);
}

extern WINAPI void wine32a_LdrFindEntryForAddress(void);
__ASM_GLOBAL_FUNC(wine32a_LdrFindEntryForAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrFindEntryForAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrEnumerateLoadedModules(void * unknown, LDRENUMPROC callback, void * context)
{
	TRACE("Enter LdrEnumerateLoadedModules\n");
	return pLdrEnumerateLoadedModules(unknown, callback, context);
}

extern WINAPI void wine32a_LdrEnumerateLoadedModules(void);
__ASM_GLOBAL_FUNC(wine32a_LdrEnumerateLoadedModules,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrEnumerateLoadedModules") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrRegisterDllNotification(ULONG flags, PLDR_DLL_NOTIFICATION_FUNCTION callback, void * context, void ** cookie)
{
	TRACE("Enter LdrRegisterDllNotification\n");
	return pLdrRegisterDllNotification(flags, callback, context, cookie);
}

extern WINAPI void wine32a_LdrRegisterDllNotification(void);
__ASM_GLOBAL_FUNC(wine32a_LdrRegisterDllNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrRegisterDllNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrUnregisterDllNotification(void * cookie)
{
	TRACE("Enter LdrUnregisterDllNotification\n");
	return pLdrUnregisterDllNotification(cookie);
}

extern WINAPI void wine32a_LdrUnregisterDllNotification(void);
__ASM_GLOBAL_FUNC(wine32a_LdrUnregisterDllNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrUnregisterDllNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrLockLoaderLock(ULONG flags, ULONG * result, ULONG_PTR * magic)
{
	TRACE("Enter LdrLockLoaderLock\n");
	return pLdrLockLoaderLock(flags, result, magic);
}

extern WINAPI void wine32a_LdrLockLoaderLock(void);
__ASM_GLOBAL_FUNC(wine32a_LdrLockLoaderLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrLockLoaderLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrUnlockLoaderLock(ULONG flags, ULONG_PTR magic)
{
	TRACE("Enter LdrUnlockLoaderLock\n");
	return pLdrUnlockLoaderLock(flags, magic);
}

extern WINAPI void wine32a_LdrUnlockLoaderLock(void);
__ASM_GLOBAL_FUNC(wine32a_LdrUnlockLoaderLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrUnlockLoaderLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrGetProcedureAddress(HMODULE module, const ANSI_STRING * name, ULONG ord, PVOID * address)
{
	TRACE("Enter LdrGetProcedureAddress\n");
	return pLdrGetProcedureAddress(module, name, ord, address);
}

extern WINAPI void wine32a_LdrGetProcedureAddress(void);
__ASM_GLOBAL_FUNC(wine32a_LdrGetProcedureAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrGetProcedureAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrLoadDll(LPCWSTR path_name, DWORD flags, const UNICODE_STRING * libname, HMODULE * hModule)
{
	TRACE("Enter LdrLoadDll\n");
	return pLdrLoadDll(path_name, flags, libname, hModule);
}

extern WINAPI void wine32a_LdrLoadDll(void);
__ASM_GLOBAL_FUNC(wine32a_LdrLoadDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrLoadDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrGetDllHandle(LPCWSTR load_path, ULONG flags, const UNICODE_STRING * name, HMODULE * base)
{
	TRACE("Enter LdrGetDllHandle\n");
	return pLdrGetDllHandle(load_path, flags, name, base);
}

extern WINAPI void wine32a_LdrGetDllHandle(void);
__ASM_GLOBAL_FUNC(wine32a_LdrGetDllHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrGetDllHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrAddRefDll(ULONG flags, HMODULE module)
{
	TRACE("Enter LdrAddRefDll\n");
	return pLdrAddRefDll(flags, module);
}

extern WINAPI void wine32a_LdrAddRefDll(void);
__ASM_GLOBAL_FUNC(wine32a_LdrAddRefDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrAddRefDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI IMAGE_BASE_RELOCATION * wine32b_LdrProcessRelocationBlock(void * page, UINT count, USHORT * relocs, INT_PTR delta)
{
	TRACE("Enter LdrProcessRelocationBlock\n");
	return pLdrProcessRelocationBlock(page, count, relocs, delta);
}

extern WINAPI void wine32a_LdrProcessRelocationBlock(void);
__ASM_GLOBAL_FUNC(wine32a_LdrProcessRelocationBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrProcessRelocationBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrQueryProcessModuleInformation(PSYSTEM_MODULE_INFORMATION smi, ULONG buf_size, ULONG * req_size)
{
	TRACE("Enter LdrQueryProcessModuleInformation\n");
	return pLdrQueryProcessModuleInformation(smi, buf_size, req_size);
}

extern WINAPI void wine32a_LdrQueryProcessModuleInformation(void);
__ASM_GLOBAL_FUNC(wine32a_LdrQueryProcessModuleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrQueryProcessModuleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrQueryImageFileExecutionOptions(const UNICODE_STRING * key, LPCWSTR value, ULONG type, void * data, ULONG in_size, ULONG * out_size)
{
	TRACE("Enter LdrQueryImageFileExecutionOptions\n");
	return pLdrQueryImageFileExecutionOptions(key, value, type, data, in_size, out_size);
}

extern WINAPI void wine32a_LdrQueryImageFileExecutionOptions(void);
__ASM_GLOBAL_FUNC(wine32a_LdrQueryImageFileExecutionOptions,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrQueryImageFileExecutionOptions") "\n"
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

extern WINAPI BOOLEAN wine32b_RtlDllShutdownInProgress(void)
{
	TRACE("Enter RtlDllShutdownInProgress\n");
	return pRtlDllShutdownInProgress();
}

extern WINAPI void wine32a_RtlDllShutdownInProgress(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDllShutdownInProgress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDllShutdownInProgress") "\n"
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

extern WINAPI void * wine32b_LdrResolveDelayLoadedAPI(void * base, const IMAGE_DELAYLOAD_DESCRIPTOR * desc, PDELAYLOAD_FAILURE_DLL_CALLBACK dllhook, PDELAYLOAD_FAILURE_SYSTEM_ROUTINE syshook, IMAGE_THUNK_DATA * addr, ULONG flags)
{
	TRACE("Enter LdrResolveDelayLoadedAPI\n");
	return pLdrResolveDelayLoadedAPI(base, desc, dllhook, syshook, addr, flags);
}

extern WINAPI void wine32a_LdrResolveDelayLoadedAPI(void);
__ASM_GLOBAL_FUNC(wine32a_LdrResolveDelayLoadedAPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrResolveDelayLoadedAPI") "\n"
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

extern WINAPI void wine32b_LdrShutdownProcess(void)
{
	TRACE("Enter LdrShutdownProcess\n");
	return pLdrShutdownProcess();
}

extern WINAPI void wine32a_LdrShutdownProcess(void);
__ASM_GLOBAL_FUNC(wine32a_LdrShutdownProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrShutdownProcess") "\n"
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

extern WINAPI void wine32b_RtlExitUserProcess(DWORD status)
{
	TRACE("Enter RtlExitUserProcess\n");
	return pRtlExitUserProcess(status);
}

extern WINAPI void wine32a_RtlExitUserProcess(void);
__ASM_GLOBAL_FUNC(wine32a_RtlExitUserProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlExitUserProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_LdrShutdownThread(void)
{
	TRACE("Enter LdrShutdownThread\n");
	return pLdrShutdownThread();
}

extern WINAPI void wine32a_LdrShutdownThread(void);
__ASM_GLOBAL_FUNC(wine32a_LdrShutdownThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrShutdownThread") "\n"
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

extern WINAPI NTSTATUS wine32b_LdrUnloadDll(HMODULE hModule)
{
	TRACE("Enter LdrUnloadDll\n");
	return pLdrUnloadDll(hModule);
}

extern WINAPI void wine32a_LdrUnloadDll(void);
__ASM_GLOBAL_FUNC(wine32a_LdrUnloadDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrUnloadDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PIMAGE_NT_HEADERS wine32b_RtlImageNtHeader(HMODULE hModule)
{
	TRACE("Enter RtlImageNtHeader\n");
	return pRtlImageNtHeader(hModule);
}

extern WINAPI void wine32a_RtlImageNtHeader(void);
__ASM_GLOBAL_FUNC(wine32a_RtlImageNtHeader,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlImageNtHeader") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_LdrInitializeThunk(CONTEXT * context, void ** entry, ULONG_PTR unknown3, ULONG_PTR unknown4)
{
	TRACE("Enter LdrInitializeThunk\n");
	return pLdrInitializeThunk(context, entry, unknown3, unknown4);
}

extern WINAPI void wine32a_LdrInitializeThunk(void);
__ASM_GLOBAL_FUNC(wine32a_LdrInitializeThunk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrInitializeThunk") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlImageDirectoryEntryToData(HMODULE module, BOOL image, WORD dir, ULONG * size)
{
	TRACE("Enter RtlImageDirectoryEntryToData\n");
	return pRtlImageDirectoryEntryToData(module, image, dir, size);
}

extern WINAPI void wine32a_RtlImageDirectoryEntryToData(void);
__ASM_GLOBAL_FUNC(wine32a_RtlImageDirectoryEntryToData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlImageDirectoryEntryToData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PIMAGE_SECTION_HEADER wine32b_RtlImageRvaToSection(const IMAGE_NT_HEADERS * nt, HMODULE module, DWORD rva)
{
	TRACE("Enter RtlImageRvaToSection\n");
	return pRtlImageRvaToSection(nt, module, rva);
}

extern WINAPI void wine32a_RtlImageRvaToSection(void);
__ASM_GLOBAL_FUNC(wine32a_RtlImageRvaToSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlImageRvaToSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlImageRvaToVa(const IMAGE_NT_HEADERS * nt, HMODULE module, DWORD rva, IMAGE_SECTION_HEADER ** section)
{
	TRACE("Enter RtlImageRvaToVa\n");
	return pRtlImageRvaToVa(nt, module, rva, section);
}

extern WINAPI void wine32a_RtlImageRvaToVa(void);
__ASM_GLOBAL_FUNC(wine32a_RtlImageRvaToVa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlImageRvaToVa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlPcToFileHeader(PVOID pc, PVOID * address)
{
	TRACE("Enter RtlPcToFileHeader\n");
	return pRtlPcToFileHeader(pc, address);
}

extern WINAPI void wine32a_RtlPcToFileHeader(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPcToFileHeader,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPcToFileHeader") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtLoadDriver(const UNICODE_STRING * DriverServiceName)
{
	TRACE("Enter NtLoadDriver\n");
	return pNtLoadDriver(DriverServiceName);
}

extern WINAPI void wine32a_NtLoadDriver(void);
__ASM_GLOBAL_FUNC(wine32a_NtLoadDriver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtLoadDriver") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtUnloadDriver(const UNICODE_STRING * DriverServiceName)
{
	TRACE("Enter NtUnloadDriver\n");
	return pNtUnloadDriver(DriverServiceName);
}

extern WINAPI void wine32a_NtUnloadDriver(void);
__ASM_GLOBAL_FUNC(wine32a_NtUnloadDriver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtUnloadDriver") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)


static WINAPI void * (*p_lfind)(const void * key, const void * base, unsigned int * nmemb, size_t size, int (*)(const void *, const void *) __attribute__((ms_abi)) compar);
static WINAPI NTSTATUS (*pWinSqmEndSession)(HANDLE session);
static WINAPI void (*pWinSqmIncrementDWORD)(DWORD unk1, DWORD unk2, DWORD unk3);
static WINAPI BOOL (*pWinSqmIsOptedIn)(void);
static WINAPI HANDLE (*pWinSqmStartSession)(GUID * sessionguid, DWORD sessionid, DWORD unknown1);
static WINAPI void (*pWinSqmSetDWORD)(HANDLE session, DWORD datapoint_id, DWORD datapoint_value);
static WINAPI ULONG (*pEtwEventActivityIdControl)(ULONG code, GUID * guid);
static WINAPI BOOLEAN (*pEtwEventProviderEnabled)(REGHANDLE handle, UCHAR level, ULONGLONG keyword);
static WINAPI ULONG (*pEtwEventRegister)(LPCGUID provider, PENABLECALLBACK callback, PVOID context, PREGHANDLE handle);
static WINAPI ULONG (*pEtwEventUnregister)(REGHANDLE handle);
static WINAPI ULONG (*pEtwEventSetInformation)(REGHANDLE handle, EVENT_INFO_CLASS class, void * info, ULONG length);
static WINAPI ULONG (*pEtwEventWriteTransfer)(REGHANDLE handle, PCEVENT_DESCRIPTOR descriptor, LPCGUID activity, LPCGUID related, ULONG count, PEVENT_DATA_DESCRIPTOR data);
static WINAPI ULONG (*pEtwRegisterTraceGuidsW)(WMIDPREQUEST RequestAddress, void * RequestContext, const GUID * ControlGuid, ULONG GuidCount, TRACE_GUID_REGISTRATION * TraceGuidReg, const WCHAR * MofImagePath, const WCHAR * MofResourceName, TRACEHANDLE * RegistrationHandle);
static WINAPI ULONG (*pEtwRegisterTraceGuidsA)(WMIDPREQUEST RequestAddress, void * RequestContext, const GUID * ControlGuid, ULONG GuidCount, TRACE_GUID_REGISTRATION * TraceGuidReg, const char * MofImagePath, const char * MofResourceName, TRACEHANDLE * RegistrationHandle);
static WINAPI ULONG (*pEtwUnregisterTraceGuids)(TRACEHANDLE RegistrationHandle);
static WINAPI BOOLEAN (*pEtwEventEnabled)(REGHANDLE handle, const EVENT_DESCRIPTOR * descriptor);
static WINAPI ULONG (*pEtwEventWrite)(REGHANDLE handle, const EVENT_DESCRIPTOR * descriptor, ULONG count, EVENT_DATA_DESCRIPTOR * data);
static WINAPI ULONG (*pEtwGetTraceEnableFlags)(TRACEHANDLE handle);
static WINAPI UCHAR (*pEtwGetTraceEnableLevel)(TRACEHANDLE handle);
static WINAPI TRACEHANDLE (*pEtwGetTraceLoggerHandle)(PVOID buf);
static WINAPI ULONG (*pEtwLogTraceEvent)(TRACEHANDLE SessionHandle, PEVENT_TRACE_HEADER EventTrace);
static WINAPI ULONG (*pEtwTraceMessageVa)(TRACEHANDLE handle, ULONG flags, LPGUID guid, USHORT number, __builtin_ms_va_list args);
static WINAPI ULONG (*pEtwTraceMessage)(TRACEHANDLE handle, ULONG flags, LPGUID guid, USHORT number);
static WINAPI NTSTATUS (*pNtCreateLowBoxToken)(HANDLE * token_handle, HANDLE existing_token_handle, ACCESS_MASK desired_access, OBJECT_ATTRIBUTES * object_attributes, SID * package_sid, ULONG capability_count, SID_AND_ATTRIBUTES * capabilities, ULONG handle_count, HANDLE * handle);
static WINAPI BOOL (*pApiSetQueryApiSetPresence)(const UNICODE_STRING * namespace, BOOLEAN * present);

extern WINAPI void * wine32b__lfind(const void * key, const void * base, unsigned int * nmemb, size_t size, int (*)(const void *, const void *) __attribute__((ms_abi)) compar)
{
	TRACE("Enter _lfind\n");
	return p_lfind(key, base, nmemb, size, compar);
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

extern WINAPI NTSTATUS wine32b_WinSqmEndSession(HANDLE session)
{
	TRACE("Enter WinSqmEndSession\n");
	return pWinSqmEndSession(session);
}

extern WINAPI void wine32a_WinSqmEndSession(void);
__ASM_GLOBAL_FUNC(wine32a_WinSqmEndSession,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinSqmEndSession") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_WinSqmIncrementDWORD(DWORD unk1, DWORD unk2, DWORD unk3)
{
	TRACE("Enter WinSqmIncrementDWORD\n");
	return pWinSqmIncrementDWORD(unk1, unk2, unk3);
}

extern WINAPI void wine32a_WinSqmIncrementDWORD(void);
__ASM_GLOBAL_FUNC(wine32a_WinSqmIncrementDWORD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinSqmIncrementDWORD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_WinSqmIsOptedIn(void)
{
	TRACE("Enter WinSqmIsOptedIn\n");
	return pWinSqmIsOptedIn();
}

extern WINAPI void wine32a_WinSqmIsOptedIn(void);
__ASM_GLOBAL_FUNC(wine32a_WinSqmIsOptedIn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinSqmIsOptedIn") "\n"
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

extern WINAPI HANDLE wine32b_WinSqmStartSession(GUID * sessionguid, DWORD sessionid, DWORD unknown1)
{
	TRACE("Enter WinSqmStartSession\n");
	return pWinSqmStartSession(sessionguid, sessionid, unknown1);
}

extern WINAPI void wine32a_WinSqmStartSession(void);
__ASM_GLOBAL_FUNC(wine32a_WinSqmStartSession,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinSqmStartSession") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_WinSqmSetDWORD(HANDLE session, DWORD datapoint_id, DWORD datapoint_value)
{
	TRACE("Enter WinSqmSetDWORD\n");
	return pWinSqmSetDWORD(session, datapoint_id, datapoint_value);
}

extern WINAPI void wine32a_WinSqmSetDWORD(void);
__ASM_GLOBAL_FUNC(wine32a_WinSqmSetDWORD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_WinSqmSetDWORD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventActivityIdControl(ULONG code, GUID * guid)
{
	TRACE("Enter EtwEventActivityIdControl\n");
	return pEtwEventActivityIdControl(code, guid);
}

extern WINAPI void wine32a_EtwEventActivityIdControl(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventActivityIdControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventActivityIdControl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_EtwEventProviderEnabled(REGHANDLE handle, UCHAR level, ULONGLONG keyword)
{
	TRACE("Enter EtwEventProviderEnabled\n");
	return pEtwEventProviderEnabled(handle, level, keyword);
}

extern WINAPI void wine32a_EtwEventProviderEnabled(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventProviderEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventProviderEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventRegister(LPCGUID provider, PENABLECALLBACK callback, PVOID context, PREGHANDLE handle)
{
	TRACE("Enter EtwEventRegister\n");
	return pEtwEventRegister(provider, callback, context, handle);
}

extern WINAPI void wine32a_EtwEventRegister(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventRegister,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventRegister") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventUnregister(REGHANDLE handle)
{
	TRACE("Enter EtwEventUnregister\n");
	return pEtwEventUnregister(handle);
}

extern WINAPI void wine32a_EtwEventUnregister(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventUnregister,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventUnregister") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventSetInformation(REGHANDLE handle, EVENT_INFO_CLASS class, void * info, ULONG length)
{
	TRACE("Enter EtwEventSetInformation\n");
	return pEtwEventSetInformation(handle, class, info, length);
}

extern WINAPI void wine32a_EtwEventSetInformation(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventSetInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventSetInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventWriteTransfer(REGHANDLE handle, PCEVENT_DESCRIPTOR descriptor, LPCGUID activity, LPCGUID related, ULONG count, PEVENT_DATA_DESCRIPTOR data)
{
	TRACE("Enter EtwEventWriteTransfer\n");
	return pEtwEventWriteTransfer(handle, descriptor, activity, related, count, data);
}

extern WINAPI void wine32a_EtwEventWriteTransfer(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventWriteTransfer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventWriteTransfer") "\n"
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

extern WINAPI ULONG wine32b_EtwRegisterTraceGuidsW(WMIDPREQUEST RequestAddress, void * RequestContext, const GUID * ControlGuid, ULONG GuidCount, TRACE_GUID_REGISTRATION * TraceGuidReg, const WCHAR * MofImagePath, const WCHAR * MofResourceName, TRACEHANDLE * RegistrationHandle)
{
	TRACE("Enter EtwRegisterTraceGuidsW\n");
	return pEtwRegisterTraceGuidsW(RequestAddress, RequestContext, ControlGuid, GuidCount, TraceGuidReg, MofImagePath, MofResourceName, RegistrationHandle);
}

extern WINAPI void wine32a_EtwRegisterTraceGuidsW(void);
__ASM_GLOBAL_FUNC(wine32a_EtwRegisterTraceGuidsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwRegisterTraceGuidsW") "\n"
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

extern WINAPI ULONG wine32b_EtwRegisterTraceGuidsA(WMIDPREQUEST RequestAddress, void * RequestContext, const GUID * ControlGuid, ULONG GuidCount, TRACE_GUID_REGISTRATION * TraceGuidReg, const char * MofImagePath, const char * MofResourceName, TRACEHANDLE * RegistrationHandle)
{
	TRACE("Enter EtwRegisterTraceGuidsA\n");
	return pEtwRegisterTraceGuidsA(RequestAddress, RequestContext, ControlGuid, GuidCount, TraceGuidReg, MofImagePath, MofResourceName, RegistrationHandle);
}

extern WINAPI void wine32a_EtwRegisterTraceGuidsA(void);
__ASM_GLOBAL_FUNC(wine32a_EtwRegisterTraceGuidsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwRegisterTraceGuidsA") "\n"
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

extern WINAPI ULONG wine32b_EtwUnregisterTraceGuids(TRACEHANDLE RegistrationHandle)
{
	TRACE("Enter EtwUnregisterTraceGuids\n");
	return pEtwUnregisterTraceGuids(RegistrationHandle);
}

extern WINAPI void wine32a_EtwUnregisterTraceGuids(void);
__ASM_GLOBAL_FUNC(wine32a_EtwUnregisterTraceGuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwUnregisterTraceGuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_EtwEventEnabled(REGHANDLE handle, const EVENT_DESCRIPTOR * descriptor)
{
	TRACE("Enter EtwEventEnabled\n");
	return pEtwEventEnabled(handle, descriptor);
}

extern WINAPI void wine32a_EtwEventEnabled(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwEventWrite(REGHANDLE handle, const EVENT_DESCRIPTOR * descriptor, ULONG count, EVENT_DATA_DESCRIPTOR * data)
{
	TRACE("Enter EtwEventWrite\n");
	return pEtwEventWrite(handle, descriptor, count, data);
}

extern WINAPI void wine32a_EtwEventWrite(void);
__ASM_GLOBAL_FUNC(wine32a_EtwEventWrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwEventWrite") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwGetTraceEnableFlags(TRACEHANDLE handle)
{
	TRACE("Enter EtwGetTraceEnableFlags\n");
	return pEtwGetTraceEnableFlags(handle);
}

extern WINAPI void wine32a_EtwGetTraceEnableFlags(void);
__ASM_GLOBAL_FUNC(wine32a_EtwGetTraceEnableFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwGetTraceEnableFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UCHAR wine32b_EtwGetTraceEnableLevel(TRACEHANDLE handle)
{
	TRACE("Enter EtwGetTraceEnableLevel\n");
	return pEtwGetTraceEnableLevel(handle);
}

extern WINAPI void wine32a_EtwGetTraceEnableLevel(void);
__ASM_GLOBAL_FUNC(wine32a_EtwGetTraceEnableLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwGetTraceEnableLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRACEHANDLE wine32b_EtwGetTraceLoggerHandle(PVOID buf)
{
	TRACE("Enter EtwGetTraceLoggerHandle\n");
	return pEtwGetTraceLoggerHandle(buf);
}

extern WINAPI void wine32a_EtwGetTraceLoggerHandle(void);
__ASM_GLOBAL_FUNC(wine32a_EtwGetTraceLoggerHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwGetTraceLoggerHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwLogTraceEvent(TRACEHANDLE SessionHandle, PEVENT_TRACE_HEADER EventTrace)
{
	TRACE("Enter EtwLogTraceEvent\n");
	return pEtwLogTraceEvent(SessionHandle, EventTrace);
}

extern WINAPI void wine32a_EtwLogTraceEvent(void);
__ASM_GLOBAL_FUNC(wine32a_EtwLogTraceEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwLogTraceEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_EtwTraceMessageVa(TRACEHANDLE handle, ULONG flags, LPGUID guid, USHORT number, __builtin_ms_va_list args)
{
	TRACE("Enter EtwTraceMessageVa\n");
	return pEtwTraceMessageVa(handle, flags, guid, number, args);
}

extern WINAPI void wine32a_EtwTraceMessageVa(void);
__ASM_GLOBAL_FUNC(wine32a_EtwTraceMessageVa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwTraceMessageVa") "\n"
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

extern WINAPI ULONG wine32b_EtwTraceMessage(TRACEHANDLE handle, ULONG flags, LPGUID guid, USHORT number)
{
	TRACE("Enter EtwTraceMessage\n");
	return pEtwTraceMessage(handle, flags, guid, number);
}

extern WINAPI void wine32a_EtwTraceMessage(void);
__ASM_GLOBAL_FUNC(wine32a_EtwTraceMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_EtwTraceMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateLowBoxToken(HANDLE * token_handle, HANDLE existing_token_handle, ACCESS_MASK desired_access, OBJECT_ATTRIBUTES * object_attributes, SID * package_sid, ULONG capability_count, SID_AND_ATTRIBUTES * capabilities, ULONG handle_count, HANDLE * handle)
{
	TRACE("Enter NtCreateLowBoxToken\n");
	return pNtCreateLowBoxToken(token_handle, existing_token_handle, desired_access, object_attributes, package_sid, capability_count, capabilities, handle_count, handle);
}

extern WINAPI void wine32a_NtCreateLowBoxToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateLowBoxToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateLowBoxToken") "\n"
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

extern WINAPI BOOL wine32b_ApiSetQueryApiSetPresence(const UNICODE_STRING * namespace, BOOLEAN * present)
{
	TRACE("Enter ApiSetQueryApiSetPresence\n");
	return pApiSetQueryApiSetPresence(namespace, present);
}

extern WINAPI void wine32a_ApiSetQueryApiSetPresence(void);
__ASM_GLOBAL_FUNC(wine32a_ApiSetQueryApiSetPresence,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ApiSetQueryApiSetPresence") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtDuplicateToken)(HANDLE ExistingToken, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, SECURITY_IMPERSONATION_LEVEL ImpersonationLevel, TOKEN_TYPE TokenType, PHANDLE NewToken);
static WINAPI NTSTATUS (*pNtOpenProcessToken)(HANDLE ProcessHandle, DWORD DesiredAccess, HANDLE * TokenHandle);
static WINAPI NTSTATUS (*pNtOpenProcessTokenEx)(HANDLE process, DWORD access, DWORD attributes, HANDLE * handle);
static WINAPI NTSTATUS (*pNtOpenThreadToken)(HANDLE ThreadHandle, DWORD DesiredAccess, BOOLEAN OpenAsSelf, HANDLE * TokenHandle);
static WINAPI NTSTATUS (*pNtOpenThreadTokenEx)(HANDLE thread, DWORD access, BOOLEAN as_self, DWORD attributes, HANDLE * handle);
static WINAPI NTSTATUS (*pNtAdjustPrivilegesToken)(HANDLE TokenHandle, BOOLEAN DisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength);
static WINAPI NTSTATUS (*pNtQueryInformationToken)(HANDLE token, TOKEN_INFORMATION_CLASS tokeninfoclass, PVOID tokeninfo, ULONG tokeninfolength, PULONG retlen);
static WINAPI NTSTATUS (*pNtSetInformationToken)(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, PVOID TokenInformation, ULONG TokenInformationLength);
static WINAPI NTSTATUS (*pNtAdjustGroupsToken)(HANDLE TokenHandle, BOOLEAN ResetToDefault, PTOKEN_GROUPS NewState, ULONG BufferLength, PTOKEN_GROUPS PreviousState, PULONG ReturnLength);
static WINAPI NTSTATUS (*pNtPrivilegeCheck)(HANDLE ClientToken, PPRIVILEGE_SET RequiredPrivileges, PBOOLEAN Result);
static WINAPI NTSTATUS (*pNtCreatePort)(PHANDLE PortHandle, POBJECT_ATTRIBUTES ObjectAttributes, ULONG MaxConnectInfoLength, ULONG MaxDataLength, PULONG reserved);
static WINAPI NTSTATUS (*pNtConnectPort)(PHANDLE PortHandle, PUNICODE_STRING PortName, PSECURITY_QUALITY_OF_SERVICE SecurityQos, PLPC_SECTION_WRITE WriteSection, PLPC_SECTION_READ ReadSection, PULONG MaximumMessageLength, PVOID ConnectInfo, PULONG pConnectInfoLength);
static WINAPI NTSTATUS (*pNtSecureConnectPort)(PHANDLE PortHandle, PUNICODE_STRING PortName, PSECURITY_QUALITY_OF_SERVICE SecurityQos, PLPC_SECTION_WRITE WriteSection, PSID pSid, PLPC_SECTION_READ ReadSection, PULONG MaximumMessageLength, PVOID ConnectInfo, PULONG pConnectInfoLength);
static WINAPI NTSTATUS (*pNtListenPort)(HANDLE PortHandle, PLPC_MESSAGE pLpcMessage);
static WINAPI NTSTATUS (*pNtAcceptConnectPort)(PHANDLE PortHandle, ULONG PortIdentifier, PLPC_MESSAGE pLpcMessage, BOOLEAN Accept, PLPC_SECTION_WRITE WriteSection, PLPC_SECTION_READ ReadSection);
static WINAPI NTSTATUS (*pNtCompleteConnectPort)(HANDLE PortHandle);
static WINAPI NTSTATUS (*pNtRegisterThreadTerminatePort)(HANDLE PortHandle);
static WINAPI NTSTATUS (*pNtRequestWaitReplyPort)(HANDLE PortHandle, PLPC_MESSAGE pLpcMessageIn, PLPC_MESSAGE pLpcMessageOut);
static WINAPI NTSTATUS (*pNtReplyWaitReceivePort)(HANDLE PortHandle, PULONG PortIdentifier, PLPC_MESSAGE ReplyMessage, PLPC_MESSAGE Message);
static WINAPI NTSTATUS (*pNtSetIntervalProfile)(ULONG Interval, KPROFILE_SOURCE Source);
static WINAPI BOOLEAN (*pRtlIsProcessorFeaturePresent)(UINT feature);
static WINAPI NTSTATUS (*pNtQuerySystemInformation)(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG Length, PULONG ResultLength);
static WINAPI NTSTATUS (*pNtQuerySystemInformationEx)(SYSTEM_INFORMATION_CLASS SystemInformationClass, void * Query, ULONG QueryLength, void * SystemInformation, ULONG Length, ULONG * ResultLength);
static WINAPI NTSTATUS (*pNtSetSystemInformation)(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG Length);
static WINAPI NTSTATUS (*pNtCreatePagingFile)(PUNICODE_STRING PageFileName, PLARGE_INTEGER MinimumSize, PLARGE_INTEGER MaximumSize, PLARGE_INTEGER ActualSize);
static WINAPI NTSTATUS (*pNtDisplayString)(PUNICODE_STRING string);
static WINAPI NTSTATUS (*pNtInitiatePowerAction)(POWER_ACTION SystemAction, SYSTEM_POWER_STATE MinSystemState, ULONG Flags, BOOLEAN Asynchronous);
static WINAPI NTSTATUS (*pNtSetThreadExecutionState)(EXECUTION_STATE new_state, EXECUTION_STATE * old_state);
static WINAPI NTSTATUS (*pNtCreatePowerRequest)(HANDLE * handle, COUNTED_REASON_CONTEXT * context);
static WINAPI NTSTATUS (*pNtSetPowerRequest)(HANDLE handle, POWER_REQUEST_TYPE type);
static WINAPI NTSTATUS (*pNtClearPowerRequest)(HANDLE handle, POWER_REQUEST_TYPE type);
static WINAPI NTSTATUS (*pNtPowerInformation)(POWER_INFORMATION_LEVEL InformationLevel, PVOID lpInputBuffer, ULONG nInputBufferSize, PVOID lpOutputBuffer, ULONG nOutputBufferSize);
static WINAPI NTSTATUS (*pNtShutdownSystem)(SHUTDOWN_ACTION Action);
static WINAPI NTSTATUS (*pNtAllocateLocallyUniqueId)(PLUID Luid);
static WINAPI ULONGLONG (*pVerSetConditionMask)(ULONGLONG dwlConditionMask, DWORD dwTypeBitMask, BYTE dwConditionMask);
static WINAPI NTSTATUS (*pNtAccessCheckAndAuditAlarm)(PUNICODE_STRING SubsystemName, HANDLE HandleId, PUNICODE_STRING ObjectTypeName, PUNICODE_STRING ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, ACCESS_MASK DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOLEAN ObjectCreation, PACCESS_MASK GrantedAccess, PBOOLEAN AccessStatus, PBOOLEAN GenerateOnClose);
static WINAPI NTSTATUS (*pNtSystemDebugControl)(SYSDBG_COMMAND command, PVOID inbuffer, ULONG inbuflength, PVOID outbuffer, ULONG outbuflength, PULONG retlength);
static WINAPI NTSTATUS (*pNtSetLdtEntries)(ULONG selector1, ULONG entry1_low, ULONG entry1_high, ULONG selector2, ULONG entry2_low, ULONG entry2_high);

extern WINAPI NTSTATUS wine32b_NtDuplicateToken(HANDLE ExistingToken, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes, SECURITY_IMPERSONATION_LEVEL ImpersonationLevel, TOKEN_TYPE TokenType, PHANDLE NewToken)
{
	TRACE("Enter NtDuplicateToken\n");
	return pNtDuplicateToken(ExistingToken, DesiredAccess, ObjectAttributes, ImpersonationLevel, TokenType, NewToken);
}

extern WINAPI void wine32a_NtDuplicateToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtDuplicateToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDuplicateToken") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenProcessToken(HANDLE ProcessHandle, DWORD DesiredAccess, HANDLE * TokenHandle)
{
	TRACE("Enter NtOpenProcessToken\n");
	return pNtOpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle);
}

extern WINAPI void wine32a_NtOpenProcessToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenProcessToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenProcessToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenProcessTokenEx(HANDLE process, DWORD access, DWORD attributes, HANDLE * handle)
{
	TRACE("Enter NtOpenProcessTokenEx\n");
	return pNtOpenProcessTokenEx(process, access, attributes, handle);
}

extern WINAPI void wine32a_NtOpenProcessTokenEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenProcessTokenEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenProcessTokenEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenThreadToken(HANDLE ThreadHandle, DWORD DesiredAccess, BOOLEAN OpenAsSelf, HANDLE * TokenHandle)
{
	TRACE("Enter NtOpenThreadToken\n");
	return pNtOpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle);
}

extern WINAPI void wine32a_NtOpenThreadToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenThreadToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenThreadToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenThreadTokenEx(HANDLE thread, DWORD access, BOOLEAN as_self, DWORD attributes, HANDLE * handle)
{
	TRACE("Enter NtOpenThreadTokenEx\n");
	return pNtOpenThreadTokenEx(thread, access, as_self, attributes, handle);
}

extern WINAPI void wine32a_NtOpenThreadTokenEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenThreadTokenEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenThreadTokenEx") "\n"
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

extern WINAPI NTSTATUS wine32b_NtAdjustPrivilegesToken(HANDLE TokenHandle, BOOLEAN DisableAllPrivileges, PTOKEN_PRIVILEGES NewState, DWORD BufferLength, PTOKEN_PRIVILEGES PreviousState, PDWORD ReturnLength)
{
	TRACE("Enter NtAdjustPrivilegesToken\n");
	return pNtAdjustPrivilegesToken(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength);
}

extern WINAPI void wine32a_NtAdjustPrivilegesToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtAdjustPrivilegesToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAdjustPrivilegesToken") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryInformationToken(HANDLE token, TOKEN_INFORMATION_CLASS tokeninfoclass, PVOID tokeninfo, ULONG tokeninfolength, PULONG retlen)
{
	TRACE("Enter NtQueryInformationToken\n");
	return pNtQueryInformationToken(token, tokeninfoclass, tokeninfo, tokeninfolength, retlen);
}

extern WINAPI void wine32a_NtQueryInformationToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationToken") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationToken(HANDLE TokenHandle, TOKEN_INFORMATION_CLASS TokenInformationClass, PVOID TokenInformation, ULONG TokenInformationLength)
{
	TRACE("Enter NtSetInformationToken\n");
	return pNtSetInformationToken(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength);
}

extern WINAPI void wine32a_NtSetInformationToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAdjustGroupsToken(HANDLE TokenHandle, BOOLEAN ResetToDefault, PTOKEN_GROUPS NewState, ULONG BufferLength, PTOKEN_GROUPS PreviousState, PULONG ReturnLength)
{
	TRACE("Enter NtAdjustGroupsToken\n");
	return pNtAdjustGroupsToken(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength);
}

extern WINAPI void wine32a_NtAdjustGroupsToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtAdjustGroupsToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAdjustGroupsToken") "\n"
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

extern WINAPI NTSTATUS wine32b_NtPrivilegeCheck(HANDLE ClientToken, PPRIVILEGE_SET RequiredPrivileges, PBOOLEAN Result)
{
	TRACE("Enter NtPrivilegeCheck\n");
	return pNtPrivilegeCheck(ClientToken, RequiredPrivileges, Result);
}

extern WINAPI void wine32a_NtPrivilegeCheck(void);
__ASM_GLOBAL_FUNC(wine32a_NtPrivilegeCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtPrivilegeCheck") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreatePort(PHANDLE PortHandle, POBJECT_ATTRIBUTES ObjectAttributes, ULONG MaxConnectInfoLength, ULONG MaxDataLength, PULONG reserved)
{
	TRACE("Enter NtCreatePort\n");
	return pNtCreatePort(PortHandle, ObjectAttributes, MaxConnectInfoLength, MaxDataLength, reserved);
}

extern WINAPI void wine32a_NtCreatePort(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreatePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreatePort") "\n"
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

extern WINAPI NTSTATUS wine32b_NtConnectPort(PHANDLE PortHandle, PUNICODE_STRING PortName, PSECURITY_QUALITY_OF_SERVICE SecurityQos, PLPC_SECTION_WRITE WriteSection, PLPC_SECTION_READ ReadSection, PULONG MaximumMessageLength, PVOID ConnectInfo, PULONG pConnectInfoLength)
{
	TRACE("Enter NtConnectPort\n");
	return pNtConnectPort(PortHandle, PortName, SecurityQos, WriteSection, ReadSection, MaximumMessageLength, ConnectInfo, pConnectInfoLength);
}

extern WINAPI void wine32a_NtConnectPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtConnectPort") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSecureConnectPort(PHANDLE PortHandle, PUNICODE_STRING PortName, PSECURITY_QUALITY_OF_SERVICE SecurityQos, PLPC_SECTION_WRITE WriteSection, PSID pSid, PLPC_SECTION_READ ReadSection, PULONG MaximumMessageLength, PVOID ConnectInfo, PULONG pConnectInfoLength)
{
	TRACE("Enter NtSecureConnectPort\n");
	return pNtSecureConnectPort(PortHandle, PortName, SecurityQos, WriteSection, pSid, ReadSection, MaximumMessageLength, ConnectInfo, pConnectInfoLength);
}

extern WINAPI void wine32a_NtSecureConnectPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtSecureConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSecureConnectPort") "\n"
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

extern WINAPI NTSTATUS wine32b_NtListenPort(HANDLE PortHandle, PLPC_MESSAGE pLpcMessage)
{
	TRACE("Enter NtListenPort\n");
	return pNtListenPort(PortHandle, pLpcMessage);
}

extern WINAPI void wine32a_NtListenPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtListenPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtListenPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAcceptConnectPort(PHANDLE PortHandle, ULONG PortIdentifier, PLPC_MESSAGE pLpcMessage, BOOLEAN Accept, PLPC_SECTION_WRITE WriteSection, PLPC_SECTION_READ ReadSection)
{
	TRACE("Enter NtAcceptConnectPort\n");
	return pNtAcceptConnectPort(PortHandle, PortIdentifier, pLpcMessage, Accept, WriteSection, ReadSection);
}

extern WINAPI void wine32a_NtAcceptConnectPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtAcceptConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAcceptConnectPort") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCompleteConnectPort(HANDLE PortHandle)
{
	TRACE("Enter NtCompleteConnectPort\n");
	return pNtCompleteConnectPort(PortHandle);
}

extern WINAPI void wine32a_NtCompleteConnectPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtCompleteConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCompleteConnectPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtRegisterThreadTerminatePort(HANDLE PortHandle)
{
	TRACE("Enter NtRegisterThreadTerminatePort\n");
	return pNtRegisterThreadTerminatePort(PortHandle);
}

extern WINAPI void wine32a_NtRegisterThreadTerminatePort(void);
__ASM_GLOBAL_FUNC(wine32a_NtRegisterThreadTerminatePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRegisterThreadTerminatePort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtRequestWaitReplyPort(HANDLE PortHandle, PLPC_MESSAGE pLpcMessageIn, PLPC_MESSAGE pLpcMessageOut)
{
	TRACE("Enter NtRequestWaitReplyPort\n");
	return pNtRequestWaitReplyPort(PortHandle, pLpcMessageIn, pLpcMessageOut);
}

extern WINAPI void wine32a_NtRequestWaitReplyPort(void);
__ASM_GLOBAL_FUNC(wine32a_NtRequestWaitReplyPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRequestWaitReplyPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtReplyWaitReceivePort(HANDLE PortHandle, PULONG PortIdentifier, PLPC_MESSAGE ReplyMessage, PLPC_MESSAGE Message)
{
	TRACE("Enter NtReplyWaitReceivePort\n");
	return pNtReplyWaitReceivePort(PortHandle, PortIdentifier, ReplyMessage, Message);
}

extern WINAPI void wine32a_NtReplyWaitReceivePort(void);
__ASM_GLOBAL_FUNC(wine32a_NtReplyWaitReceivePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReplyWaitReceivePort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetIntervalProfile(ULONG Interval, KPROFILE_SOURCE Source)
{
	TRACE("Enter NtSetIntervalProfile\n");
	return pNtSetIntervalProfile(Interval, Source);
}

extern WINAPI void wine32a_NtSetIntervalProfile(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetIntervalProfile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetIntervalProfile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlIsProcessorFeaturePresent(UINT feature)
{
	TRACE("Enter RtlIsProcessorFeaturePresent\n");
	return pRtlIsProcessorFeaturePresent(feature);
}

extern WINAPI void wine32a_RtlIsProcessorFeaturePresent(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsProcessorFeaturePresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsProcessorFeaturePresent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG Length, PULONG ResultLength)
{
	TRACE("Enter NtQuerySystemInformation\n");
	return pNtQuerySystemInformation(SystemInformationClass, SystemInformation, Length, ResultLength);
}

extern WINAPI void wine32a_NtQuerySystemInformation(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySystemInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySystemInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySystemInformationEx(SYSTEM_INFORMATION_CLASS SystemInformationClass, void * Query, ULONG QueryLength, void * SystemInformation, ULONG Length, ULONG * ResultLength)
{
	TRACE("Enter NtQuerySystemInformationEx\n");
	return pNtQuerySystemInformationEx(SystemInformationClass, Query, QueryLength, SystemInformation, Length, ResultLength);
}

extern WINAPI void wine32a_NtQuerySystemInformationEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySystemInformationEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySystemInformationEx") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetSystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass, PVOID SystemInformation, ULONG Length)
{
	TRACE("Enter NtSetSystemInformation\n");
	return pNtSetSystemInformation(SystemInformationClass, SystemInformation, Length);
}

extern WINAPI void wine32a_NtSetSystemInformation(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetSystemInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetSystemInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreatePagingFile(PUNICODE_STRING PageFileName, PLARGE_INTEGER MinimumSize, PLARGE_INTEGER MaximumSize, PLARGE_INTEGER ActualSize)
{
	TRACE("Enter NtCreatePagingFile\n");
	return pNtCreatePagingFile(PageFileName, MinimumSize, MaximumSize, ActualSize);
}

extern WINAPI void wine32a_NtCreatePagingFile(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreatePagingFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreatePagingFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtDisplayString(PUNICODE_STRING string)
{
	TRACE("Enter NtDisplayString\n");
	return pNtDisplayString(string);
}

extern WINAPI void wine32a_NtDisplayString(void);
__ASM_GLOBAL_FUNC(wine32a_NtDisplayString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDisplayString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtInitiatePowerAction(POWER_ACTION SystemAction, SYSTEM_POWER_STATE MinSystemState, ULONG Flags, BOOLEAN Asynchronous)
{
	TRACE("Enter NtInitiatePowerAction\n");
	return pNtInitiatePowerAction(SystemAction, MinSystemState, Flags, Asynchronous);
}

extern WINAPI void wine32a_NtInitiatePowerAction(void);
__ASM_GLOBAL_FUNC(wine32a_NtInitiatePowerAction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtInitiatePowerAction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetThreadExecutionState(EXECUTION_STATE new_state, EXECUTION_STATE * old_state)
{
	TRACE("Enter NtSetThreadExecutionState\n");
	return pNtSetThreadExecutionState(new_state, old_state);
}

extern WINAPI void wine32a_NtSetThreadExecutionState(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetThreadExecutionState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetThreadExecutionState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreatePowerRequest(HANDLE * handle, COUNTED_REASON_CONTEXT * context)
{
	TRACE("Enter NtCreatePowerRequest\n");
	return pNtCreatePowerRequest(handle, context);
}

extern WINAPI void wine32a_NtCreatePowerRequest(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreatePowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreatePowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetPowerRequest(HANDLE handle, POWER_REQUEST_TYPE type)
{
	TRACE("Enter NtSetPowerRequest\n");
	return pNtSetPowerRequest(handle, type);
}

extern WINAPI void wine32a_NtSetPowerRequest(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetPowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetPowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtClearPowerRequest(HANDLE handle, POWER_REQUEST_TYPE type)
{
	TRACE("Enter NtClearPowerRequest\n");
	return pNtClearPowerRequest(handle, type);
}

extern WINAPI void wine32a_NtClearPowerRequest(void);
__ASM_GLOBAL_FUNC(wine32a_NtClearPowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtClearPowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtPowerInformation(POWER_INFORMATION_LEVEL InformationLevel, PVOID lpInputBuffer, ULONG nInputBufferSize, PVOID lpOutputBuffer, ULONG nOutputBufferSize)
{
	TRACE("Enter NtPowerInformation\n");
	return pNtPowerInformation(InformationLevel, lpInputBuffer, nInputBufferSize, lpOutputBuffer, nOutputBufferSize);
}

extern WINAPI void wine32a_NtPowerInformation(void);
__ASM_GLOBAL_FUNC(wine32a_NtPowerInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtPowerInformation") "\n"
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

extern WINAPI NTSTATUS wine32b_NtShutdownSystem(SHUTDOWN_ACTION Action)
{
	TRACE("Enter NtShutdownSystem\n");
	return pNtShutdownSystem(Action);
}

extern WINAPI void wine32a_NtShutdownSystem(void);
__ASM_GLOBAL_FUNC(wine32a_NtShutdownSystem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtShutdownSystem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAllocateLocallyUniqueId(PLUID Luid)
{
	TRACE("Enter NtAllocateLocallyUniqueId\n");
	return pNtAllocateLocallyUniqueId(Luid);
}

extern WINAPI void wine32a_NtAllocateLocallyUniqueId(void);
__ASM_GLOBAL_FUNC(wine32a_NtAllocateLocallyUniqueId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAllocateLocallyUniqueId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONGLONG wine32b_VerSetConditionMask(ULONGLONG dwlConditionMask, DWORD dwTypeBitMask, BYTE dwConditionMask)
{
	TRACE("Enter VerSetConditionMask\n");
	return pVerSetConditionMask(dwlConditionMask, dwTypeBitMask, dwConditionMask);
}

extern WINAPI void wine32a_VerSetConditionMask(void);
__ASM_GLOBAL_FUNC(wine32a_VerSetConditionMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_VerSetConditionMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAccessCheckAndAuditAlarm(PUNICODE_STRING SubsystemName, HANDLE HandleId, PUNICODE_STRING ObjectTypeName, PUNICODE_STRING ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, ACCESS_MASK DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOLEAN ObjectCreation, PACCESS_MASK GrantedAccess, PBOOLEAN AccessStatus, PBOOLEAN GenerateOnClose)
{
	TRACE("Enter NtAccessCheckAndAuditAlarm\n");
	return pNtAccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
}

extern WINAPI void wine32a_NtAccessCheckAndAuditAlarm(void);
__ASM_GLOBAL_FUNC(wine32a_NtAccessCheckAndAuditAlarm,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAccessCheckAndAuditAlarm") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSystemDebugControl(SYSDBG_COMMAND command, PVOID inbuffer, ULONG inbuflength, PVOID outbuffer, ULONG outbuflength, PULONG retlength)
{
	TRACE("Enter NtSystemDebugControl\n");
	return pNtSystemDebugControl(command, inbuffer, inbuflength, outbuffer, outbuflength, retlength);
}

extern WINAPI void wine32a_NtSystemDebugControl(void);
__ASM_GLOBAL_FUNC(wine32a_NtSystemDebugControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSystemDebugControl") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetLdtEntries(ULONG selector1, ULONG entry1_low, ULONG entry1_high, ULONG selector2, ULONG entry2_low, ULONG entry2_high)
{
	TRACE("Enter NtSetLdtEntries\n");
	return pNtSetLdtEntries(selector1, entry1_low, entry1_high, selector2, entry2_low, entry2_high);
}

extern WINAPI void wine32a_NtSetLdtEntries(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetLdtEntries,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetLdtEntries") "\n"
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

static WINAPI NTSTATUS (*pNtQueryObject)(HANDLE handle, OBJECT_INFORMATION_CLASS info_class, PVOID ptr, ULONG len, PULONG used_len);
static WINAPI NTSTATUS (*pNtSetInformationObject)(HANDLE handle, OBJECT_INFORMATION_CLASS info_class, PVOID ptr, ULONG len);
static WINAPI NTSTATUS (*pNtQuerySecurityObject)(HANDLE Object, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, ULONG Length, PULONG ResultLength);
static WINAPI NTSTATUS (*pNtDuplicateObject)(HANDLE source_process, HANDLE source, HANDLE dest_process, PHANDLE dest, ACCESS_MASK access, ULONG attributes, ULONG options);
static WINAPI NTSTATUS (*pNtClose)(HANDLE Handle);
static WINAPI NTSTATUS (*pNtOpenDirectoryObject)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtCreateDirectoryObject)(PHANDLE DirectoryHandle, ACCESS_MASK DesiredAccess, OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtQueryDirectoryObject)(HANDLE handle, PDIRECTORY_BASIC_INFORMATION buffer, ULONG size, BOOLEAN single_entry, BOOLEAN restart, PULONG context, PULONG ret_size);
static WINAPI NTSTATUS (*pNtOpenSymbolicLinkObject)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtCreateSymbolicLinkObject)(PHANDLE SymbolicLinkHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES attr, PUNICODE_STRING TargetName);
static WINAPI NTSTATUS (*pNtQuerySymbolicLinkObject)(HANDLE handle, PUNICODE_STRING target, PULONG length);
static WINAPI NTSTATUS (*pNtAllocateUuids)(ULARGE_INTEGER * time, ULONG * delta, ULONG * sequence, UCHAR * seed);
static WINAPI NTSTATUS (*pNtMakeTemporaryObject)(HANDLE Handle);

extern WINAPI NTSTATUS wine32b_NtQueryObject(HANDLE handle, OBJECT_INFORMATION_CLASS info_class, PVOID ptr, ULONG len, PULONG used_len)
{
	TRACE("Enter NtQueryObject\n");
	return pNtQueryObject(handle, info_class, ptr, len, used_len);
}

extern WINAPI void wine32a_NtQueryObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryObject") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationObject(HANDLE handle, OBJECT_INFORMATION_CLASS info_class, PVOID ptr, ULONG len)
{
	TRACE("Enter NtSetInformationObject\n");
	return pNtSetInformationObject(handle, info_class, ptr, len);
}

extern WINAPI void wine32a_NtSetInformationObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySecurityObject(HANDLE Object, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, ULONG Length, PULONG ResultLength)
{
	TRACE("Enter NtQuerySecurityObject\n");
	return pNtQuerySecurityObject(Object, RequestedInformation, pSecurityDescriptor, Length, ResultLength);
}

extern WINAPI void wine32a_NtQuerySecurityObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySecurityObject") "\n"
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

extern WINAPI NTSTATUS wine32b_NtDuplicateObject(HANDLE source_process, HANDLE source, HANDLE dest_process, PHANDLE dest, ACCESS_MASK access, ULONG attributes, ULONG options)
{
	TRACE("Enter NtDuplicateObject\n");
	return pNtDuplicateObject(source_process, source, dest_process, dest, access, attributes, options);
}

extern WINAPI void wine32a_NtDuplicateObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtDuplicateObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDuplicateObject") "\n"
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

extern WINAPI NTSTATUS wine32b_NtClose(HANDLE Handle)
{
	TRACE("Enter NtClose\n");
	return pNtClose(Handle);
}

extern WINAPI void wine32a_NtClose(void);
__ASM_GLOBAL_FUNC(wine32a_NtClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenDirectoryObject(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenDirectoryObject\n");
	return pNtOpenDirectoryObject(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenDirectoryObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenDirectoryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateDirectoryObject(PHANDLE DirectoryHandle, ACCESS_MASK DesiredAccess, OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtCreateDirectoryObject\n");
	return pNtCreateDirectoryObject(DirectoryHandle, DesiredAccess, attr);
}

extern WINAPI void wine32a_NtCreateDirectoryObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateDirectoryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryDirectoryObject(HANDLE handle, PDIRECTORY_BASIC_INFORMATION buffer, ULONG size, BOOLEAN single_entry, BOOLEAN restart, PULONG context, PULONG ret_size)
{
	TRACE("Enter NtQueryDirectoryObject\n");
	return pNtQueryDirectoryObject(handle, buffer, size, single_entry, restart, context, ret_size);
}

extern WINAPI void wine32a_NtQueryDirectoryObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryDirectoryObject") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenSymbolicLinkObject(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenSymbolicLinkObject\n");
	return pNtOpenSymbolicLinkObject(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenSymbolicLinkObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenSymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenSymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateSymbolicLinkObject(PHANDLE SymbolicLinkHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES attr, PUNICODE_STRING TargetName)
{
	TRACE("Enter NtCreateSymbolicLinkObject\n");
	return pNtCreateSymbolicLinkObject(SymbolicLinkHandle, DesiredAccess, attr, TargetName);
}

extern WINAPI void wine32a_NtCreateSymbolicLinkObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateSymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateSymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySymbolicLinkObject(HANDLE handle, PUNICODE_STRING target, PULONG length)
{
	TRACE("Enter NtQuerySymbolicLinkObject\n");
	return pNtQuerySymbolicLinkObject(handle, target, length);
}

extern WINAPI void wine32a_NtQuerySymbolicLinkObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAllocateUuids(ULARGE_INTEGER * time, ULONG * delta, ULONG * sequence, UCHAR * seed)
{
	TRACE("Enter NtAllocateUuids\n");
	return pNtAllocateUuids(time, delta, sequence, seed);
}

extern WINAPI void wine32a_NtAllocateUuids(void);
__ASM_GLOBAL_FUNC(wine32a_NtAllocateUuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAllocateUuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtMakeTemporaryObject(HANDLE Handle)
{
	TRACE("Enter NtMakeTemporaryObject\n");
	return pNtMakeTemporaryObject(Handle);
}

extern WINAPI void wine32a_NtMakeTemporaryObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtMakeTemporaryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtMakeTemporaryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI DOS_PATHNAME_TYPE (*pRtlDetermineDosPathNameType_U)(PCWSTR path);
static WINAPI ULONG (*pRtlIsDosDeviceName_U)(PCWSTR dos_name);
static WINAPI NTSTATUS (*pRtlDosPathNameToNtPathName_U_WithStatus)(const WCHAR * dos_path, UNICODE_STRING * ntpath, WCHAR ** file_part, CURDIR * cd);
static WINAPI BOOLEAN (*pRtlDosPathNameToNtPathName_U)(PCWSTR dos_path, PUNICODE_STRING ntpath, PWSTR * file_part, CURDIR * cd);
static WINAPI NTSTATUS (*pRtlDosPathNameToRelativeNtPathName_U_WithStatus)(const WCHAR * dos_path, UNICODE_STRING * ntpath, WCHAR ** file_part, RTL_RELATIVE_NAME * relative);
static WINAPI void (*pRtlReleaseRelativeName)(RTL_RELATIVE_NAME * relative);
static WINAPI ULONG (*pRtlDosSearchPath_U)(LPCWSTR paths, LPCWSTR search, LPCWSTR ext, ULONG buffer_size, LPWSTR buffer, LPWSTR * file_part);
static WINAPI ULONG (*pRtlGetFullPathName_U)(const WCHAR * name, ULONG size, WCHAR * buffer, WCHAR ** file_part);
static WINAPI DWORD (*pRtlGetLongestNtPathLength)(void);
static WINAPI BOOLEAN (*pRtlIsNameLegalDOS8Dot3)(const UNICODE_STRING * unicode, OEM_STRING * oem, BOOLEAN * spaces);
static WINAPI ULONG (*pRtlGetCurrentDirectory_U)(ULONG buflen, LPWSTR buf);
static WINAPI NTSTATUS (*pRtlSetCurrentDirectory_U)(const UNICODE_STRING * dir);
static WINAPI NTSTATUS (*pwine_unix_to_nt_file_name)(const ANSI_STRING * name, UNICODE_STRING * nt);

extern WINAPI DOS_PATHNAME_TYPE wine32b_RtlDetermineDosPathNameType_U(PCWSTR path)
{
	TRACE("Enter RtlDetermineDosPathNameType_U\n");
	return pRtlDetermineDosPathNameType_U(path);
}

extern WINAPI void wine32a_RtlDetermineDosPathNameType_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDetermineDosPathNameType_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDetermineDosPathNameType_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlIsDosDeviceName_U(PCWSTR dos_name)
{
	TRACE("Enter RtlIsDosDeviceName_U\n");
	return pRtlIsDosDeviceName_U(dos_name);
}

extern WINAPI void wine32a_RtlIsDosDeviceName_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsDosDeviceName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsDosDeviceName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDosPathNameToNtPathName_U_WithStatus(const WCHAR * dos_path, UNICODE_STRING * ntpath, WCHAR ** file_part, CURDIR * cd)
{
	TRACE("Enter RtlDosPathNameToNtPathName_U_WithStatus\n");
	return pRtlDosPathNameToNtPathName_U_WithStatus(dos_path, ntpath, file_part, cd);
}

extern WINAPI void wine32a_RtlDosPathNameToNtPathName_U_WithStatus(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDosPathNameToNtPathName_U_WithStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDosPathNameToNtPathName_U_WithStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlDosPathNameToNtPathName_U(PCWSTR dos_path, PUNICODE_STRING ntpath, PWSTR * file_part, CURDIR * cd)
{
	TRACE("Enter RtlDosPathNameToNtPathName_U\n");
	return pRtlDosPathNameToNtPathName_U(dos_path, ntpath, file_part, cd);
}

extern WINAPI void wine32a_RtlDosPathNameToNtPathName_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDosPathNameToNtPathName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDosPathNameToNtPathName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDosPathNameToRelativeNtPathName_U_WithStatus(const WCHAR * dos_path, UNICODE_STRING * ntpath, WCHAR ** file_part, RTL_RELATIVE_NAME * relative)
{
	TRACE("Enter RtlDosPathNameToRelativeNtPathName_U_WithStatus\n");
	return pRtlDosPathNameToRelativeNtPathName_U_WithStatus(dos_path, ntpath, file_part, relative);
}

extern WINAPI void wine32a_RtlDosPathNameToRelativeNtPathName_U_WithStatus(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDosPathNameToRelativeNtPathName_U_WithStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDosPathNameToRelativeNtPathName_U_WithStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlReleaseRelativeName(RTL_RELATIVE_NAME * relative)
{
	TRACE("Enter RtlReleaseRelativeName\n");
	return pRtlReleaseRelativeName(relative);
}

extern WINAPI void wine32a_RtlReleaseRelativeName(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleaseRelativeName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleaseRelativeName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlDosSearchPath_U(LPCWSTR paths, LPCWSTR search, LPCWSTR ext, ULONG buffer_size, LPWSTR buffer, LPWSTR * file_part)
{
	TRACE("Enter RtlDosSearchPath_U\n");
	return pRtlDosSearchPath_U(paths, search, ext, buffer_size, buffer, file_part);
}

extern WINAPI void wine32a_RtlDosSearchPath_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDosSearchPath_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDosSearchPath_U") "\n"
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

extern WINAPI ULONG wine32b_RtlGetFullPathName_U(const WCHAR * name, ULONG size, WCHAR * buffer, WCHAR ** file_part)
{
	TRACE("Enter RtlGetFullPathName_U\n");
	return pRtlGetFullPathName_U(name, size, buffer, file_part);
}

extern WINAPI void wine32a_RtlGetFullPathName_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetFullPathName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetFullPathName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlGetLongestNtPathLength(void)
{
	TRACE("Enter RtlGetLongestNtPathLength\n");
	return pRtlGetLongestNtPathLength();
}

extern WINAPI void wine32a_RtlGetLongestNtPathLength(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetLongestNtPathLength,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetLongestNtPathLength") "\n"
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

extern WINAPI BOOLEAN wine32b_RtlIsNameLegalDOS8Dot3(const UNICODE_STRING * unicode, OEM_STRING * oem, BOOLEAN * spaces)
{
	TRACE("Enter RtlIsNameLegalDOS8Dot3\n");
	return pRtlIsNameLegalDOS8Dot3(unicode, oem, spaces);
}

extern WINAPI void wine32a_RtlIsNameLegalDOS8Dot3(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsNameLegalDOS8Dot3,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsNameLegalDOS8Dot3") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlGetCurrentDirectory_U(ULONG buflen, LPWSTR buf)
{
	TRACE("Enter RtlGetCurrentDirectory_U\n");
	return pRtlGetCurrentDirectory_U(buflen, buf);
}

extern WINAPI void wine32a_RtlGetCurrentDirectory_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetCurrentDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetCurrentDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetCurrentDirectory_U(const UNICODE_STRING * dir)
{
	TRACE("Enter RtlSetCurrentDirectory_U\n");
	return pRtlSetCurrentDirectory_U(dir);
}

extern WINAPI void wine32a_RtlSetCurrentDirectory_U(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetCurrentDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetCurrentDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_wine_unix_to_nt_file_name(const ANSI_STRING * name, UNICODE_STRING * nt)
{
	TRACE("Enter wine_unix_to_nt_file_name\n");
	return pwine_unix_to_nt_file_name(name, nt);
}

extern WINAPI void wine32a_wine_unix_to_nt_file_name(void);
__ASM_GLOBAL_FUNC(wine32a_wine_unix_to_nt_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_unix_to_nt_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI int (*p_vsnprintf_s)(char * str, SIZE_T size, SIZE_T len, const char * format, __builtin_ms_va_list args);
static WINAPI int (*p_snprintf_s)(char * str, SIZE_T size, SIZE_T len, const char * format);

extern WINAPI int wine32b__vsnprintf_s(char * str, SIZE_T size, SIZE_T len, const char * format, __builtin_ms_va_list args)
{
	TRACE("Enter _vsnprintf_s\n");
	return p_vsnprintf_s(str, size, len, format, args);
}

extern WINAPI void wine32a__vsnprintf_s(void);
__ASM_GLOBAL_FUNC(wine32a__vsnprintf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__vsnprintf_s") "\n"
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

extern WINAPI int wine32b__snprintf_s(char * str, SIZE_T size, SIZE_T len, const char * format)
{
	TRACE("Enter _snprintf_s\n");
	return p_snprintf_s(str, size, len, format);
}

extern WINAPI void wine32a__snprintf_s(void);
__ASM_GLOBAL_FUNC(wine32a__snprintf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__snprintf_s") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtTerminateProcess)(HANDLE handle, LONG exit_code);
static WINAPI PEB * (*pRtlGetCurrentPeb)(void);
static WINAPI HANDLE (*p__wine_make_process_system)(void);
static WINAPI NTSTATUS (*pNtQueryInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength);
static WINAPI NTSTATUS (*pNtSetInformationProcess)(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength);
static WINAPI NTSTATUS (*pNtFlushInstructionCache)(HANDLE handle, const void * addr, SIZE_T size);
static WINAPI NTSTATUS (*pNtOpenProcess)(PHANDLE handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const CLIENT_ID * cid);
static WINAPI NTSTATUS (*pNtResumeProcess)(HANDLE handle);
static WINAPI NTSTATUS (*pNtSuspendProcess)(HANDLE handle);
static WINAPI NTSTATUS (*pRtlCreateUserProcess)(UNICODE_STRING * path, ULONG attributes, RTL_USER_PROCESS_PARAMETERS * params, SECURITY_DESCRIPTOR * process_descr, SECURITY_DESCRIPTOR * thread_descr, HANDLE parent, BOOLEAN inherit, HANDLE debug, HANDLE exception, RTL_USER_PROCESS_INFORMATION * info);
static WINAPI void (*pDbgUiRemoteBreakin)(void * arg);
static WINAPI NTSTATUS (*pDbgUiIssueRemoteBreakin)(HANDLE process);

extern WINAPI NTSTATUS wine32b_NtTerminateProcess(HANDLE handle, LONG exit_code)
{
	TRACE("Enter NtTerminateProcess\n");
	return pNtTerminateProcess(handle, exit_code);
}

extern WINAPI void wine32a_NtTerminateProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtTerminateProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtTerminateProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PEB * wine32b_RtlGetCurrentPeb(void)
{
	TRACE("Enter RtlGetCurrentPeb\n");
	return pRtlGetCurrentPeb();
}

extern WINAPI void wine32a_RtlGetCurrentPeb(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetCurrentPeb,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetCurrentPeb") "\n"
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

extern WINAPI HANDLE wine32b___wine_make_process_system(void)
{
	TRACE("Enter __wine_make_process_system\n");
	return p__wine_make_process_system();
}

extern WINAPI void wine32a___wine_make_process_system(void);
__ASM_GLOBAL_FUNC(wine32a___wine_make_process_system,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_make_process_system") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength, PULONG ReturnLength)
{
	TRACE("Enter NtQueryInformationProcess\n");
	return pNtQueryInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);
}

extern WINAPI void wine32a_NtQueryInformationProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationProcess") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationProcess(HANDLE ProcessHandle, PROCESSINFOCLASS ProcessInformationClass, PVOID ProcessInformation, ULONG ProcessInformationLength)
{
	TRACE("Enter NtSetInformationProcess\n");
	return pNtSetInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength);
}

extern WINAPI void wine32a_NtSetInformationProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtFlushInstructionCache(HANDLE handle, const void * addr, SIZE_T size)
{
	TRACE("Enter NtFlushInstructionCache\n");
	return pNtFlushInstructionCache(handle, addr, size);
}

extern WINAPI void wine32a_NtFlushInstructionCache(void);
__ASM_GLOBAL_FUNC(wine32a_NtFlushInstructionCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFlushInstructionCache") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenProcess(PHANDLE handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const CLIENT_ID * cid)
{
	TRACE("Enter NtOpenProcess\n");
	return pNtOpenProcess(handle, access, attr, cid);
}

extern WINAPI void wine32a_NtOpenProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtResumeProcess(HANDLE handle)
{
	TRACE("Enter NtResumeProcess\n");
	return pNtResumeProcess(handle);
}

extern WINAPI void wine32a_NtResumeProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtResumeProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtResumeProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSuspendProcess(HANDLE handle)
{
	TRACE("Enter NtSuspendProcess\n");
	return pNtSuspendProcess(handle);
}

extern WINAPI void wine32a_NtSuspendProcess(void);
__ASM_GLOBAL_FUNC(wine32a_NtSuspendProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSuspendProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateUserProcess(UNICODE_STRING * path, ULONG attributes, RTL_USER_PROCESS_PARAMETERS * params, SECURITY_DESCRIPTOR * process_descr, SECURITY_DESCRIPTOR * thread_descr, HANDLE parent, BOOLEAN inherit, HANDLE debug, HANDLE exception, RTL_USER_PROCESS_INFORMATION * info)
{
	TRACE("Enter RtlCreateUserProcess\n");
	return pRtlCreateUserProcess(path, attributes, params, process_descr, thread_descr, parent, inherit, debug, exception, info);
}

extern WINAPI void wine32a_RtlCreateUserProcess(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateUserProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateUserProcess") "\n"
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

extern WINAPI void wine32b_DbgUiRemoteBreakin(void * arg)
{
	TRACE("Enter DbgUiRemoteBreakin\n");
	return pDbgUiRemoteBreakin(arg);
}

extern WINAPI void wine32a_DbgUiRemoteBreakin(void);
__ASM_GLOBAL_FUNC(wine32a_DbgUiRemoteBreakin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DbgUiRemoteBreakin") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_DbgUiIssueRemoteBreakin(HANDLE process)
{
	TRACE("Enter DbgUiIssueRemoteBreakin\n");
	return pDbgUiIssueRemoteBreakin(process);
}

extern WINAPI void wine32a_DbgUiIssueRemoteBreakin(void);
__ASM_GLOBAL_FUNC(wine32a_DbgUiIssueRemoteBreakin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DbgUiIssueRemoteBreakin") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pNtCreateKey)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, PULONG dispos);
static WINAPI NTSTATUS (*pNtCreateKeyTransacted)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, HANDLE transacted, ULONG * dispos);
static WINAPI NTSTATUS (*pNtRenameKey)(HANDLE handle, UNICODE_STRING * name);
static WINAPI NTSTATUS (*pRtlpNtCreateKey)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, PULONG dispos);
static WINAPI NTSTATUS (*pNtOpenKeyEx)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG options);
static WINAPI NTSTATUS (*pNtOpenKey)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtOpenKeyTransactedEx)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG options, HANDLE transaction);
static WINAPI NTSTATUS (*pNtOpenKeyTransacted)(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, HANDLE transaction);
static WINAPI NTSTATUS (*pRtlpNtOpenKey)(PHANDLE retkey, ACCESS_MASK access, OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtDeleteKey)(HANDLE hkey);
static WINAPI NTSTATUS (*pRtlpNtMakeTemporaryKey)(HANDLE hkey);
static WINAPI NTSTATUS (*pNtDeleteValueKey)(HANDLE hkey, const UNICODE_STRING * name);
static WINAPI NTSTATUS (*pNtEnumerateKey)(HANDLE handle, ULONG index, KEY_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len);
static WINAPI NTSTATUS (*pRtlpNtEnumerateSubKey)(HANDLE handle, UNICODE_STRING * out, ULONG index);
static WINAPI NTSTATUS (*pNtQueryKey)(HANDLE handle, KEY_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len);
static WINAPI NTSTATUS (*pNtEnumerateValueKey)(HANDLE handle, ULONG index, KEY_VALUE_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len);
static WINAPI NTSTATUS (*pNtQueryValueKey)(HANDLE handle, const UNICODE_STRING * name, KEY_VALUE_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len);
static WINAPI NTSTATUS (*pRtlpNtQueryValueKey)(HANDLE handle, ULONG * result_type, PBYTE dest, DWORD * result_len, void * unknown);
static WINAPI NTSTATUS (*pNtFlushKey)(HANDLE key);
static WINAPI NTSTATUS (*pNtLoadKey)(const OBJECT_ATTRIBUTES * attr, OBJECT_ATTRIBUTES * file);
static WINAPI NTSTATUS (*pNtLoadKey2)(OBJECT_ATTRIBUTES * attr, OBJECT_ATTRIBUTES * file, ULONG flags);
static WINAPI NTSTATUS (*pNtNotifyChangeMultipleKeys)(HANDLE KeyHandle, ULONG Count, OBJECT_ATTRIBUTES * SubordinateObjects, HANDLE Event, PIO_APC_ROUTINE ApcRoutine, PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG CompletionFilter, BOOLEAN WatchSubtree, PVOID ChangeBuffer, ULONG Length, BOOLEAN Asynchronous);
static WINAPI NTSTATUS (*pNtNotifyChangeKey)(HANDLE KeyHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine, PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG CompletionFilter, BOOLEAN WatchSubtree, PVOID ChangeBuffer, ULONG Length, BOOLEAN Asynchronous);
static WINAPI NTSTATUS (*pNtQueryMultipleValueKey)(HANDLE KeyHandle, PKEY_MULTIPLE_VALUE_INFORMATION ListOfValuesToQuery, ULONG NumberOfItems, PVOID MultipleValueInformation, ULONG Length, PULONG ReturnLength);
static WINAPI NTSTATUS (*pNtReplaceKey)(POBJECT_ATTRIBUTES ObjectAttributes, HANDLE Key, POBJECT_ATTRIBUTES ReplacedObjectAttributes);
static WINAPI NTSTATUS (*pNtRestoreKey)(HANDLE KeyHandle, HANDLE FileHandle, ULONG RestoreFlags);
static WINAPI NTSTATUS (*pNtSaveKey)(HANDLE KeyHandle, HANDLE FileHandle);
static WINAPI NTSTATUS (*pNtSetInformationKey)(HANDLE KeyHandle, const int KeyInformationClass, PVOID KeyInformation, ULONG KeyInformationLength);
static WINAPI NTSTATUS (*pNtSetValueKey)(HANDLE hkey, const UNICODE_STRING * name, ULONG TitleIndex, ULONG type, const void * data, ULONG count);
static WINAPI NTSTATUS (*pRtlpNtSetValueKey)(HANDLE hkey, ULONG type, const void * data, ULONG count);
static WINAPI NTSTATUS (*pNtUnloadKey)(POBJECT_ATTRIBUTES attr);
static WINAPI NTSTATUS (*pRtlFormatCurrentUserKeyPath)(PUNICODE_STRING KeyPath);
static WINAPI NTSTATUS (*pRtlOpenCurrentUser)(ACCESS_MASK DesiredAccess, PHANDLE KeyHandle);
static WINAPI NTSTATUS (*pRtlQueryRegistryValues)(ULONG RelativeTo, PCWSTR Path, PRTL_QUERY_REGISTRY_TABLE QueryTable, PVOID Context, PVOID Environment);
static WINAPI NTSTATUS (*pRtlCheckRegistryKey)(ULONG RelativeTo, PWSTR Path);
static WINAPI NTSTATUS (*pRtlCreateRegistryKey)(ULONG RelativeTo, PWSTR path);
static WINAPI NTSTATUS (*pRtlDeleteRegistryValue)(ULONG RelativeTo, PCWSTR Path, PCWSTR ValueName);
static WINAPI NTSTATUS (*pRtlWriteRegistryValue)(ULONG RelativeTo, PCWSTR path, PCWSTR name, ULONG type, PVOID data, ULONG length);
static WINAPI NTSTATUS (*pNtQueryLicenseValue)(const UNICODE_STRING * name, ULONG * result_type, PVOID data, ULONG length, ULONG * result_len);

extern WINAPI NTSTATUS wine32b_NtCreateKey(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, PULONG dispos)
{
	TRACE("Enter NtCreateKey\n");
	return pNtCreateKey(retkey, access, attr, TitleIndex, class, options, dispos);
}

extern WINAPI void wine32a_NtCreateKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCreateKeyTransacted(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, HANDLE transacted, ULONG * dispos)
{
	TRACE("Enter NtCreateKeyTransacted\n");
	return pNtCreateKeyTransacted(retkey, access, attr, TitleIndex, class, options, transacted, dispos);
}

extern WINAPI void wine32a_NtCreateKeyTransacted(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateKeyTransacted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateKeyTransacted") "\n"
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

extern WINAPI NTSTATUS wine32b_NtRenameKey(HANDLE handle, UNICODE_STRING * name)
{
	TRACE("Enter NtRenameKey\n");
	return pNtRenameKey(handle, name);
}

extern WINAPI void wine32a_NtRenameKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtRenameKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRenameKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlpNtCreateKey(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG TitleIndex, const UNICODE_STRING * class, ULONG options, PULONG dispos)
{
	TRACE("Enter RtlpNtCreateKey\n");
	return pRtlpNtCreateKey(retkey, access, attr, TitleIndex, class, options, dispos);
}

extern WINAPI void wine32a_RtlpNtCreateKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtCreateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtCreateKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenKeyEx(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG options)
{
	TRACE("Enter NtOpenKeyEx\n");
	return pNtOpenKeyEx(retkey, access, attr, options);
}

extern WINAPI void wine32a_NtOpenKeyEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenKeyEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenKeyEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenKey(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenKey\n");
	return pNtOpenKey(retkey, access, attr);
}

extern WINAPI void wine32a_NtOpenKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenKeyTransactedEx(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG options, HANDLE transaction)
{
	TRACE("Enter NtOpenKeyTransactedEx\n");
	return pNtOpenKeyTransactedEx(retkey, access, attr, options, transaction);
}

extern WINAPI void wine32a_NtOpenKeyTransactedEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenKeyTransactedEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenKeyTransactedEx") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenKeyTransacted(PHANDLE retkey, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, HANDLE transaction)
{
	TRACE("Enter NtOpenKeyTransacted\n");
	return pNtOpenKeyTransacted(retkey, access, attr, transaction);
}

extern WINAPI void wine32a_NtOpenKeyTransacted(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenKeyTransacted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenKeyTransacted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlpNtOpenKey(PHANDLE retkey, ACCESS_MASK access, OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter RtlpNtOpenKey\n");
	return pRtlpNtOpenKey(retkey, access, attr);
}

extern WINAPI void wine32a_RtlpNtOpenKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtOpenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtOpenKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtDeleteKey(HANDLE hkey)
{
	TRACE("Enter NtDeleteKey\n");
	return pNtDeleteKey(hkey);
}

extern WINAPI void wine32a_NtDeleteKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtDeleteKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDeleteKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlpNtMakeTemporaryKey(HANDLE hkey)
{
	TRACE("Enter RtlpNtMakeTemporaryKey\n");
	return pRtlpNtMakeTemporaryKey(hkey);
}

extern WINAPI void wine32a_RtlpNtMakeTemporaryKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtMakeTemporaryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtMakeTemporaryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtDeleteValueKey(HANDLE hkey, const UNICODE_STRING * name)
{
	TRACE("Enter NtDeleteValueKey\n");
	return pNtDeleteValueKey(hkey, name);
}

extern WINAPI void wine32a_NtDeleteValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtDeleteValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDeleteValueKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtEnumerateKey(HANDLE handle, ULONG index, KEY_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len)
{
	TRACE("Enter NtEnumerateKey\n");
	return pNtEnumerateKey(handle, index, info_class, info, length, result_len);
}

extern WINAPI void wine32a_NtEnumerateKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtEnumerateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtEnumerateKey") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlpNtEnumerateSubKey(HANDLE handle, UNICODE_STRING * out, ULONG index)
{
	TRACE("Enter RtlpNtEnumerateSubKey\n");
	return pRtlpNtEnumerateSubKey(handle, out, index);
}

extern WINAPI void wine32a_RtlpNtEnumerateSubKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtEnumerateSubKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtEnumerateSubKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryKey(HANDLE handle, KEY_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len)
{
	TRACE("Enter NtQueryKey\n");
	return pNtQueryKey(handle, info_class, info, length, result_len);
}

extern WINAPI void wine32a_NtQueryKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtEnumerateValueKey(HANDLE handle, ULONG index, KEY_VALUE_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len)
{
	TRACE("Enter NtEnumerateValueKey\n");
	return pNtEnumerateValueKey(handle, index, info_class, info, length, result_len);
}

extern WINAPI void wine32a_NtEnumerateValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtEnumerateValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtEnumerateValueKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryValueKey(HANDLE handle, const UNICODE_STRING * name, KEY_VALUE_INFORMATION_CLASS info_class, void * info, DWORD length, DWORD * result_len)
{
	TRACE("Enter NtQueryValueKey\n");
	return pNtQueryValueKey(handle, name, info_class, info, length, result_len);
}

extern WINAPI void wine32a_NtQueryValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryValueKey") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlpNtQueryValueKey(HANDLE handle, ULONG * result_type, PBYTE dest, DWORD * result_len, void * unknown)
{
	TRACE("Enter RtlpNtQueryValueKey\n");
	return pRtlpNtQueryValueKey(handle, result_type, dest, result_len, unknown);
}

extern WINAPI void wine32a_RtlpNtQueryValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtQueryValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtQueryValueKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtFlushKey(HANDLE key)
{
	TRACE("Enter NtFlushKey\n");
	return pNtFlushKey(key);
}

extern WINAPI void wine32a_NtFlushKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtFlushKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFlushKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtLoadKey(const OBJECT_ATTRIBUTES * attr, OBJECT_ATTRIBUTES * file)
{
	TRACE("Enter NtLoadKey\n");
	return pNtLoadKey(attr, file);
}

extern WINAPI void wine32a_NtLoadKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtLoadKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtLoadKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtLoadKey2(OBJECT_ATTRIBUTES * attr, OBJECT_ATTRIBUTES * file, ULONG flags)
{
	TRACE("Enter NtLoadKey2\n");
	return pNtLoadKey2(attr, file, flags);
}

extern WINAPI void wine32a_NtLoadKey2(void);
__ASM_GLOBAL_FUNC(wine32a_NtLoadKey2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtLoadKey2") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtNotifyChangeMultipleKeys(HANDLE KeyHandle, ULONG Count, OBJECT_ATTRIBUTES * SubordinateObjects, HANDLE Event, PIO_APC_ROUTINE ApcRoutine, PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG CompletionFilter, BOOLEAN WatchSubtree, PVOID ChangeBuffer, ULONG Length, BOOLEAN Asynchronous)
{
	TRACE("Enter NtNotifyChangeMultipleKeys\n");
	return pNtNotifyChangeMultipleKeys(KeyHandle, Count, SubordinateObjects, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchSubtree, ChangeBuffer, Length, Asynchronous);
}

extern WINAPI void wine32a_NtNotifyChangeMultipleKeys(void);
__ASM_GLOBAL_FUNC(wine32a_NtNotifyChangeMultipleKeys,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtNotifyChangeMultipleKeys") "\n"
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

extern WINAPI NTSTATUS wine32b_NtNotifyChangeKey(HANDLE KeyHandle, HANDLE Event, PIO_APC_ROUTINE ApcRoutine, PVOID ApcContext, PIO_STATUS_BLOCK IoStatusBlock, ULONG CompletionFilter, BOOLEAN WatchSubtree, PVOID ChangeBuffer, ULONG Length, BOOLEAN Asynchronous)
{
	TRACE("Enter NtNotifyChangeKey\n");
	return pNtNotifyChangeKey(KeyHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchSubtree, ChangeBuffer, Length, Asynchronous);
}

extern WINAPI void wine32a_NtNotifyChangeKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtNotifyChangeKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtNotifyChangeKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryMultipleValueKey(HANDLE KeyHandle, PKEY_MULTIPLE_VALUE_INFORMATION ListOfValuesToQuery, ULONG NumberOfItems, PVOID MultipleValueInformation, ULONG Length, PULONG ReturnLength)
{
	TRACE("Enter NtQueryMultipleValueKey\n");
	return pNtQueryMultipleValueKey(KeyHandle, ListOfValuesToQuery, NumberOfItems, MultipleValueInformation, Length, ReturnLength);
}

extern WINAPI void wine32a_NtQueryMultipleValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryMultipleValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryMultipleValueKey") "\n"
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

extern WINAPI NTSTATUS wine32b_NtReplaceKey(POBJECT_ATTRIBUTES ObjectAttributes, HANDLE Key, POBJECT_ATTRIBUTES ReplacedObjectAttributes)
{
	TRACE("Enter NtReplaceKey\n");
	return pNtReplaceKey(ObjectAttributes, Key, ReplacedObjectAttributes);
}

extern WINAPI void wine32a_NtReplaceKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtReplaceKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReplaceKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtRestoreKey(HANDLE KeyHandle, HANDLE FileHandle, ULONG RestoreFlags)
{
	TRACE("Enter NtRestoreKey\n");
	return pNtRestoreKey(KeyHandle, FileHandle, RestoreFlags);
}

extern WINAPI void wine32a_NtRestoreKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtRestoreKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRestoreKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSaveKey(HANDLE KeyHandle, HANDLE FileHandle)
{
	TRACE("Enter NtSaveKey\n");
	return pNtSaveKey(KeyHandle, FileHandle);
}

extern WINAPI void wine32a_NtSaveKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtSaveKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSaveKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetInformationKey(HANDLE KeyHandle, const int KeyInformationClass, PVOID KeyInformation, ULONG KeyInformationLength)
{
	TRACE("Enter NtSetInformationKey\n");
	return pNtSetInformationKey(KeyHandle, KeyInformationClass, KeyInformation, KeyInformationLength);
}

extern WINAPI void wine32a_NtSetInformationKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetValueKey(HANDLE hkey, const UNICODE_STRING * name, ULONG TitleIndex, ULONG type, const void * data, ULONG count)
{
	TRACE("Enter NtSetValueKey\n");
	return pNtSetValueKey(hkey, name, TitleIndex, type, data, count);
}

extern WINAPI void wine32a_NtSetValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetValueKey") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlpNtSetValueKey(HANDLE hkey, ULONG type, const void * data, ULONG count)
{
	TRACE("Enter RtlpNtSetValueKey\n");
	return pRtlpNtSetValueKey(hkey, type, data, count);
}

extern WINAPI void wine32a_RtlpNtSetValueKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlpNtSetValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlpNtSetValueKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtUnloadKey(POBJECT_ATTRIBUTES attr)
{
	TRACE("Enter NtUnloadKey\n");
	return pNtUnloadKey(attr);
}

extern WINAPI void wine32a_NtUnloadKey(void);
__ASM_GLOBAL_FUNC(wine32a_NtUnloadKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtUnloadKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlFormatCurrentUserKeyPath(PUNICODE_STRING KeyPath)
{
	TRACE("Enter RtlFormatCurrentUserKeyPath\n");
	return pRtlFormatCurrentUserKeyPath(KeyPath);
}

extern WINAPI void wine32a_RtlFormatCurrentUserKeyPath(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFormatCurrentUserKeyPath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFormatCurrentUserKeyPath") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlOpenCurrentUser(ACCESS_MASK DesiredAccess, PHANDLE KeyHandle)
{
	TRACE("Enter RtlOpenCurrentUser\n");
	return pRtlOpenCurrentUser(DesiredAccess, KeyHandle);
}

extern WINAPI void wine32a_RtlOpenCurrentUser(void);
__ASM_GLOBAL_FUNC(wine32a_RtlOpenCurrentUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlOpenCurrentUser") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryRegistryValues(ULONG RelativeTo, PCWSTR Path, PRTL_QUERY_REGISTRY_TABLE QueryTable, PVOID Context, PVOID Environment)
{
	TRACE("Enter RtlQueryRegistryValues\n");
	return pRtlQueryRegistryValues(RelativeTo, Path, QueryTable, Context, Environment);
}

extern WINAPI void wine32a_RtlQueryRegistryValues(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryRegistryValues,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryRegistryValues") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlCheckRegistryKey(ULONG RelativeTo, PWSTR Path)
{
	TRACE("Enter RtlCheckRegistryKey\n");
	return pRtlCheckRegistryKey(RelativeTo, Path);
}

extern WINAPI void wine32a_RtlCheckRegistryKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCheckRegistryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCheckRegistryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateRegistryKey(ULONG RelativeTo, PWSTR path)
{
	TRACE("Enter RtlCreateRegistryKey\n");
	return pRtlCreateRegistryKey(RelativeTo, path);
}

extern WINAPI void wine32a_RtlCreateRegistryKey(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateRegistryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateRegistryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDeleteRegistryValue(ULONG RelativeTo, PCWSTR Path, PCWSTR ValueName)
{
	TRACE("Enter RtlDeleteRegistryValue\n");
	return pRtlDeleteRegistryValue(RelativeTo, Path, ValueName);
}

extern WINAPI void wine32a_RtlDeleteRegistryValue(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteRegistryValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteRegistryValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWriteRegistryValue(ULONG RelativeTo, PCWSTR path, PCWSTR name, ULONG type, PVOID data, ULONG length)
{
	TRACE("Enter RtlWriteRegistryValue\n");
	return pRtlWriteRegistryValue(RelativeTo, path, name, type, data, length);
}

extern WINAPI void wine32a_RtlWriteRegistryValue(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWriteRegistryValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWriteRegistryValue") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryLicenseValue(const UNICODE_STRING * name, ULONG * result_type, PVOID data, ULONG length, ULONG * result_len)
{
	TRACE("Enter NtQueryLicenseValue\n");
	return pNtQueryLicenseValue(name, result_type, data, length, result_len);
}

extern WINAPI void wine32a_NtQueryLicenseValue(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryLicenseValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryLicenseValue") "\n"
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


static WINAPI NTSTATUS (*pLdrFindResourceDirectory_U)(HMODULE hmod, const LDR_RESOURCE_INFO * info, ULONG level, const IMAGE_RESOURCE_DIRECTORY ** dir);
static WINAPI NTSTATUS (*pLdrFindResource_U)(HMODULE hmod, const LDR_RESOURCE_INFO * info, ULONG level, const IMAGE_RESOURCE_DATA_ENTRY ** entry);
static WINAPI NTSTATUS (*pLdrAccessResource)(HMODULE hmod, const IMAGE_RESOURCE_DATA_ENTRY * entry, void ** ptr, ULONG * size);
static WINAPI NTSTATUS (*pRtlFindMessage)(HMODULE hmod, ULONG type, ULONG lang, ULONG msg_id, const MESSAGE_RESOURCE_ENTRY ** ret);
static WINAPI NTSTATUS (*pRtlFormatMessage)(LPWSTR Message, UCHAR MaxWidth, BOOLEAN IgnoreInserts, BOOLEAN Ansi, BOOLEAN ArgumentIsArray, __builtin_ms_va_list * Arguments, LPWSTR Buffer, ULONG BufferSize);
static WINAPI NTSTATUS (*pNtQueryDefaultLocale)(BOOLEAN user, LCID * lcid);
static WINAPI NTSTATUS (*pNtSetDefaultLocale)(BOOLEAN user, LCID lcid);
static WINAPI NTSTATUS (*pNtQueryDefaultUILanguage)(LANGID * lang);
static WINAPI NTSTATUS (*pNtSetDefaultUILanguage)(LANGID lang);
static WINAPI NTSTATUS (*pNtQueryInstallUILanguage)(LANGID * lang);

extern WINAPI NTSTATUS wine32b_LdrFindResourceDirectory_U(HMODULE hmod, const LDR_RESOURCE_INFO * info, ULONG level, const IMAGE_RESOURCE_DIRECTORY ** dir)
{
	TRACE("Enter LdrFindResourceDirectory_U\n");
	return pLdrFindResourceDirectory_U(hmod, info, level, dir);
}

extern WINAPI void wine32a_LdrFindResourceDirectory_U(void);
__ASM_GLOBAL_FUNC(wine32a_LdrFindResourceDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrFindResourceDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrFindResource_U(HMODULE hmod, const LDR_RESOURCE_INFO * info, ULONG level, const IMAGE_RESOURCE_DATA_ENTRY ** entry)
{
	TRACE("Enter LdrFindResource_U\n");
	return pLdrFindResource_U(hmod, info, level, entry);
}

extern WINAPI void wine32a_LdrFindResource_U(void);
__ASM_GLOBAL_FUNC(wine32a_LdrFindResource_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrFindResource_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_LdrAccessResource(HMODULE hmod, const IMAGE_RESOURCE_DATA_ENTRY * entry, void ** ptr, ULONG * size)
{
	TRACE("Enter LdrAccessResource\n");
	return pLdrAccessResource(hmod, entry, ptr, size);
}

extern WINAPI void wine32a_LdrAccessResource(void);
__ASM_GLOBAL_FUNC(wine32a_LdrAccessResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_LdrAccessResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlFindMessage(HMODULE hmod, ULONG type, ULONG lang, ULONG msg_id, const MESSAGE_RESOURCE_ENTRY ** ret)
{
	TRACE("Enter RtlFindMessage\n");
	return pRtlFindMessage(hmod, type, lang, msg_id, ret);
}

extern WINAPI void wine32a_RtlFindMessage(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindMessage") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlFormatMessage(LPWSTR Message, UCHAR MaxWidth, BOOLEAN IgnoreInserts, BOOLEAN Ansi, BOOLEAN ArgumentIsArray, __builtin_ms_va_list * Arguments, LPWSTR Buffer, ULONG BufferSize)
{
	TRACE("Enter RtlFormatMessage\n");
	return pRtlFormatMessage(Message, MaxWidth, IgnoreInserts, Ansi, ArgumentIsArray, Arguments, Buffer, BufferSize);
}

extern WINAPI void wine32a_RtlFormatMessage(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFormatMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFormatMessage") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryDefaultLocale(BOOLEAN user, LCID * lcid)
{
	TRACE("Enter NtQueryDefaultLocale\n");
	return pNtQueryDefaultLocale(user, lcid);
}

extern WINAPI void wine32a_NtQueryDefaultLocale(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetDefaultLocale(BOOLEAN user, LCID lcid)
{
	TRACE("Enter NtSetDefaultLocale\n");
	return pNtSetDefaultLocale(user, lcid);
}

extern WINAPI void wine32a_NtSetDefaultLocale(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryDefaultUILanguage(LANGID * lang)
{
	TRACE("Enter NtQueryDefaultUILanguage\n");
	return pNtQueryDefaultUILanguage(lang);
}

extern WINAPI void wine32a_NtQueryDefaultUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryDefaultUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetDefaultUILanguage(LANGID lang)
{
	TRACE("Enter NtSetDefaultUILanguage\n");
	return pNtSetDefaultUILanguage(lang);
}

extern WINAPI void wine32a_NtSetDefaultUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetDefaultUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryInstallUILanguage(LANGID * lang)
{
	TRACE("Enter NtQueryInstallUILanguage\n");
	return pNtQueryInstallUILanguage(lang);
}

extern WINAPI void wine32a_NtQueryInstallUILanguage(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInstallUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInstallUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*pRtlInitializeResource)(LPRTL_RWLOCK rwl);
static WINAPI void (*pRtlDeleteResource)(LPRTL_RWLOCK rwl);
static WINAPI BYTE (*pRtlAcquireResourceExclusive)(LPRTL_RWLOCK rwl, BYTE fWait);
static WINAPI BYTE (*pRtlAcquireResourceShared)(LPRTL_RWLOCK rwl, BYTE fWait);
static WINAPI void (*pRtlReleaseResource)(LPRTL_RWLOCK rwl);
static WINAPI void (*pRtlDumpResource)(LPRTL_RWLOCK rwl);
static WINAPI NTSTATUS (*pDbgPrint)(LPCSTR fmt);
static WINAPI NTSTATUS (*pDbgPrintEx)(ULONG iComponentId, ULONG Level, LPCSTR fmt);
static WINAPI NTSTATUS (*pvDbgPrintEx)(ULONG id, ULONG level, LPCSTR fmt, __builtin_ms_va_list args);
static WINAPI NTSTATUS (*pvDbgPrintExWithPrefix)(LPCSTR prefix, ULONG id, ULONG level, LPCSTR fmt, __builtin_ms_va_list args);
static WINAPI void (*pRtlAcquirePebLock)(void);
static WINAPI void (*pRtlReleasePebLock)(void);
static WINAPI NTSTATUS (*pRtlNewSecurityObject)(PSECURITY_DESCRIPTOR ParentDescriptor, PSECURITY_DESCRIPTOR CreatorDescriptor, PSECURITY_DESCRIPTOR * NewDescriptor, BOOLEAN IsDirectoryObject, HANDLE Token, PGENERIC_MAPPING GenericMapping);
static WINAPI NTSTATUS (*pRtlDeleteSecurityObject)(PSECURITY_DESCRIPTOR * ObjectDescriptor);
static WINAPI PVOID (*pRtlInitializeGenericTable)(PVOID pTable, PVOID arg2, PVOID arg3, PVOID arg4, PVOID arg5);
static WINAPI PVOID (*pRtlEnumerateGenericTableWithoutSplaying)(PVOID pTable, PVOID * RestartKey);
static WINAPI ULONG (*pRtlNumberGenericTableElements)(PVOID pTable);
static WINAPI void (*pRtlMoveMemory)(void * Destination, const void * Source, SIZE_T Length);
static WINAPI void (*pRtlFillMemory)(void * Destination, SIZE_T Length, BYTE Fill);
static WINAPI void (*pRtlZeroMemory)(void * Destination, SIZE_T Length);
static WINAPI SIZE_T (*pRtlCompareMemory)(const void * Source1, const void * Source2, SIZE_T Length);
static WINAPI SIZE_T (*pRtlCompareMemoryUlong)(const ULONG * Source1, SIZE_T Length, ULONG dwVal);
static WINAPI void (*pRtlCopyMemory)(void * dest, const void * src, SIZE_T len);
static WINAPI void (*pRtlAssert)(void * assertion, void * filename, ULONG linenumber, char * message);
static WINAPI void (*pRtlFillMemoryUlong)(ULONG * lpDest, ULONG ulCount, ULONG ulValue);
static WINAPI DWORD (*pRtlComputeCrc32)(DWORD dwInitial, const BYTE * pData, INT iLen);
static WINAPI ULONGLONG (*pRtlUlonglongByteSwap)(ULONGLONG i);
static WINAPI ULONG (*pRtlUniform)(PULONG seed);
static WINAPI ULONG (*pRtlRandom)(PULONG seed);
static WINAPI ULONG (*pRtlRandomEx)(ULONG * seed);
static WINAPI BOOLEAN (*pRtlAreAllAccessesGranted)(ACCESS_MASK GrantedAccess, ACCESS_MASK DesiredAccess);
static WINAPI BOOLEAN (*pRtlAreAnyAccessesGranted)(ACCESS_MASK GrantedAccess, ACCESS_MASK DesiredAccess);
static WINAPI void (*pRtlMapGenericMask)(PACCESS_MASK AccessMask, const GENERIC_MAPPING * GenericMapping);
static WINAPI void (*pRtlCopyLuid)(PLUID LuidDest, const LUID * LuidSrc);
static WINAPI BOOLEAN (*pRtlEqualLuid)(const LUID * Luid1, const LUID * Luid2);
static WINAPI void (*pRtlCopyLuidAndAttributesArray)(ULONG Count, const LUID_AND_ATTRIBUTES * Src, PLUID_AND_ATTRIBUTES Dest);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressExW)(const WCHAR * str, BOOLEAN strict, IN_ADDR * address, USHORT * port);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressW)(const WCHAR * str, BOOLEAN strict, const WCHAR ** terminator, IN_ADDR * address);
static WINAPI NTSTATUS (*pRtlIpv6StringToAddressExW)(const WCHAR * str, IN6_ADDR * address, ULONG * scope, USHORT * port);
static WINAPI NTSTATUS (*pRtlIpv4AddressToStringExW)(const IN_ADDR * pin, USHORT port, LPWSTR buffer, PULONG psize);
static WINAPI NTSTATUS (*pRtlIpv4AddressToStringExA)(const IN_ADDR * pin, USHORT port, LPSTR buffer, PULONG psize);
static WINAPI WCHAR * (*pRtlIpv4AddressToStringW)(const IN_ADDR * pin, LPWSTR buffer);
static WINAPI CHAR * (*pRtlIpv4AddressToStringA)(const IN_ADDR * pin, LPSTR buffer);
static WINAPI PVOID (*pRtlEncodePointer)(PVOID ptr);
static WINAPI PVOID (*pRtlDecodePointer)(PVOID ptr);
static WINAPI void (*pRtlInitializeSListHead)(PSLIST_HEADER list);
static WINAPI WORD (*pRtlQueryDepthSList)(PSLIST_HEADER list);
static WINAPI PSLIST_ENTRY (*pRtlFirstEntrySList)(const SLIST_HEADER * list);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedFlushSList)(PSLIST_HEADER list);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushEntrySList)(PSLIST_HEADER list, PSLIST_ENTRY entry);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPopEntrySList)(PSLIST_HEADER list);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushListSListEx)(PSLIST_HEADER list, PSLIST_ENTRY first, PSLIST_ENTRY last, ULONG count);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushListSList)(PSLIST_HEADER list, PSLIST_ENTRY first, PSLIST_ENTRY last, ULONG count);
static WINAPI NTSTATUS (*pRtlGetCompressionWorkSpaceSize)(USHORT format, PULONG compress_workspace, PULONG decompress_workspace);
static WINAPI NTSTATUS (*pRtlCompressBuffer)(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, ULONG chunk_size, PULONG final_size, PVOID workspace);
static WINAPI NTSTATUS (*pRtlDecompressFragment)(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, ULONG offset, PULONG final_size, PVOID workspace);
static WINAPI NTSTATUS (*pRtlDecompressBuffer)(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, PULONG final_size);
static WINAPI NTSTATUS (*pRtlSetThreadErrorMode)(DWORD mode, LPDWORD oldmode);
static WINAPI DWORD (*pRtlGetThreadErrorMode)(void);
static WINAPI HANDLE (*pRtlGetCurrentTransaction)(void);
static WINAPI BOOL (*pRtlSetCurrentTransaction)(HANDLE new_transaction);
static WINAPI void (*pRtlGetCurrentProcessorNumberEx)(PROCESSOR_NUMBER * processor);
static WINAPI void (*pRtlInitializeGenericTableAvl)(PRTL_AVL_TABLE table, PRTL_AVL_COMPARE_ROUTINE compare, PRTL_AVL_ALLOCATE_ROUTINE allocate, PRTL_AVL_FREE_ROUTINE free, void * context);
static WINAPI void (*pRtlInsertElementGenericTableAvl)(PRTL_AVL_TABLE table, void * buffer, ULONG size, BOOL * element);
static WINAPI NTSTATUS (*pRtlQueryPackageIdentity)(HANDLE token, WCHAR * fullname, SIZE_T * fullname_size, WCHAR * appid, SIZE_T * appid_size, BOOLEAN * packaged);

extern WINAPI void wine32b_RtlInitializeResource(LPRTL_RWLOCK rwl)
{
	TRACE("Enter RtlInitializeResource\n");
	return pRtlInitializeResource(rwl);
}

extern WINAPI void wine32a_RtlInitializeResource(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlDeleteResource(LPRTL_RWLOCK rwl)
{
	TRACE("Enter RtlDeleteResource\n");
	return pRtlDeleteResource(rwl);
}

extern WINAPI void wine32a_RtlDeleteResource(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BYTE wine32b_RtlAcquireResourceExclusive(LPRTL_RWLOCK rwl, BYTE fWait)
{
	TRACE("Enter RtlAcquireResourceExclusive\n");
	return pRtlAcquireResourceExclusive(rwl, fWait);
}

extern WINAPI void wine32a_RtlAcquireResourceExclusive(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAcquireResourceExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAcquireResourceExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BYTE wine32b_RtlAcquireResourceShared(LPRTL_RWLOCK rwl, BYTE fWait)
{
	TRACE("Enter RtlAcquireResourceShared\n");
	return pRtlAcquireResourceShared(rwl, fWait);
}

extern WINAPI void wine32a_RtlAcquireResourceShared(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAcquireResourceShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAcquireResourceShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlReleaseResource(LPRTL_RWLOCK rwl)
{
	TRACE("Enter RtlReleaseResource\n");
	return pRtlReleaseResource(rwl);
}

extern WINAPI void wine32a_RtlReleaseResource(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleaseResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleaseResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlDumpResource(LPRTL_RWLOCK rwl)
{
	TRACE("Enter RtlDumpResource\n");
	return pRtlDumpResource(rwl);
}

extern WINAPI void wine32a_RtlDumpResource(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDumpResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDumpResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_DbgPrint(LPCSTR fmt)
{
	TRACE("Enter DbgPrint\n");
	return pDbgPrint(fmt);
}

extern WINAPI void wine32a_DbgPrint(void);
__ASM_GLOBAL_FUNC(wine32a_DbgPrint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DbgPrint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_DbgPrintEx(ULONG iComponentId, ULONG Level, LPCSTR fmt)
{
	TRACE("Enter DbgPrintEx\n");
	return pDbgPrintEx(iComponentId, Level, fmt);
}

extern WINAPI void wine32a_DbgPrintEx(void);
__ASM_GLOBAL_FUNC(wine32a_DbgPrintEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_DbgPrintEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_vDbgPrintEx(ULONG id, ULONG level, LPCSTR fmt, __builtin_ms_va_list args)
{
	TRACE("Enter vDbgPrintEx\n");
	return pvDbgPrintEx(id, level, fmt, args);
}

extern WINAPI void wine32a_vDbgPrintEx(void);
__ASM_GLOBAL_FUNC(wine32a_vDbgPrintEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_vDbgPrintEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_vDbgPrintExWithPrefix(LPCSTR prefix, ULONG id, ULONG level, LPCSTR fmt, __builtin_ms_va_list args)
{
	TRACE("Enter vDbgPrintExWithPrefix\n");
	return pvDbgPrintExWithPrefix(prefix, id, level, fmt, args);
}

extern WINAPI void wine32a_vDbgPrintExWithPrefix(void);
__ASM_GLOBAL_FUNC(wine32a_vDbgPrintExWithPrefix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_vDbgPrintExWithPrefix") "\n"
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

extern WINAPI void wine32b_RtlAcquirePebLock(void)
{
	TRACE("Enter RtlAcquirePebLock\n");
	return pRtlAcquirePebLock();
}

extern WINAPI void wine32a_RtlAcquirePebLock(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAcquirePebLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAcquirePebLock") "\n"
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

extern WINAPI void wine32b_RtlReleasePebLock(void)
{
	TRACE("Enter RtlReleasePebLock\n");
	return pRtlReleasePebLock();
}

extern WINAPI void wine32a_RtlReleasePebLock(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleasePebLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleasePebLock") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlNewSecurityObject(PSECURITY_DESCRIPTOR ParentDescriptor, PSECURITY_DESCRIPTOR CreatorDescriptor, PSECURITY_DESCRIPTOR * NewDescriptor, BOOLEAN IsDirectoryObject, HANDLE Token, PGENERIC_MAPPING GenericMapping)
{
	TRACE("Enter RtlNewSecurityObject\n");
	return pRtlNewSecurityObject(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping);
}

extern WINAPI void wine32a_RtlNewSecurityObject(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNewSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNewSecurityObject") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlDeleteSecurityObject(PSECURITY_DESCRIPTOR * ObjectDescriptor)
{
	TRACE("Enter RtlDeleteSecurityObject\n");
	return pRtlDeleteSecurityObject(ObjectDescriptor);
}

extern WINAPI void wine32a_RtlDeleteSecurityObject(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteSecurityObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlInitializeGenericTable(PVOID pTable, PVOID arg2, PVOID arg3, PVOID arg4, PVOID arg5)
{
	TRACE("Enter RtlInitializeGenericTable\n");
	return pRtlInitializeGenericTable(pTable, arg2, arg3, arg4, arg5);
}

extern WINAPI void wine32a_RtlInitializeGenericTable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeGenericTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeGenericTable") "\n"
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

extern WINAPI PVOID wine32b_RtlEnumerateGenericTableWithoutSplaying(PVOID pTable, PVOID * RestartKey)
{
	TRACE("Enter RtlEnumerateGenericTableWithoutSplaying\n");
	return pRtlEnumerateGenericTableWithoutSplaying(pTable, RestartKey);
}

extern WINAPI void wine32a_RtlEnumerateGenericTableWithoutSplaying(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEnumerateGenericTableWithoutSplaying,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEnumerateGenericTableWithoutSplaying") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlNumberGenericTableElements(PVOID pTable)
{
	TRACE("Enter RtlNumberGenericTableElements\n");
	return pRtlNumberGenericTableElements(pTable);
}

extern WINAPI void wine32a_RtlNumberGenericTableElements(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNumberGenericTableElements,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNumberGenericTableElements") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlMoveMemory(void * Destination, const void * Source, SIZE_T Length)
{
	TRACE("Enter RtlMoveMemory\n");
	return pRtlMoveMemory(Destination, Source, Length);
}

extern WINAPI void wine32a_RtlMoveMemory(void);
__ASM_GLOBAL_FUNC(wine32a_RtlMoveMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlMoveMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFillMemory(void * Destination, SIZE_T Length, BYTE Fill)
{
	TRACE("Enter RtlFillMemory\n");
	return pRtlFillMemory(Destination, Length, Fill);
}

extern WINAPI void wine32a_RtlFillMemory(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFillMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFillMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlZeroMemory(void * Destination, SIZE_T Length)
{
	TRACE("Enter RtlZeroMemory\n");
	return pRtlZeroMemory(Destination, Length);
}

extern WINAPI void wine32a_RtlZeroMemory(void);
__ASM_GLOBAL_FUNC(wine32a_RtlZeroMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlZeroMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_RtlCompareMemory(const void * Source1, const void * Source2, SIZE_T Length)
{
	TRACE("Enter RtlCompareMemory\n");
	return pRtlCompareMemory(Source1, Source2, Length);
}

extern WINAPI void wine32a_RtlCompareMemory(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompareMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompareMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_RtlCompareMemoryUlong(const ULONG * Source1, SIZE_T Length, ULONG dwVal)
{
	TRACE("Enter RtlCompareMemoryUlong\n");
	return pRtlCompareMemoryUlong(Source1, Length, dwVal);
}

extern WINAPI void wine32a_RtlCompareMemoryUlong(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompareMemoryUlong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompareMemoryUlong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlCopyMemory(void * dest, const void * src, SIZE_T len)
{
	TRACE("Enter RtlCopyMemory\n");
	return pRtlCopyMemory(dest, src, len);
}

extern WINAPI void wine32a_RtlCopyMemory(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopyMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopyMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlAssert(void * assertion, void * filename, ULONG linenumber, char * message)
{
	TRACE("Enter RtlAssert\n");
	return pRtlAssert(assertion, filename, linenumber, message);
}

extern WINAPI void wine32a_RtlAssert(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAssert,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAssert") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFillMemoryUlong(ULONG * lpDest, ULONG ulCount, ULONG ulValue)
{
	TRACE("Enter RtlFillMemoryUlong\n");
	return pRtlFillMemoryUlong(lpDest, ulCount, ulValue);
}

extern WINAPI void wine32a_RtlFillMemoryUlong(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFillMemoryUlong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFillMemoryUlong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlComputeCrc32(DWORD dwInitial, const BYTE * pData, INT iLen)
{
	TRACE("Enter RtlComputeCrc32\n");
	return pRtlComputeCrc32(dwInitial, pData, iLen);
}

extern WINAPI void wine32a_RtlComputeCrc32(void);
__ASM_GLOBAL_FUNC(wine32a_RtlComputeCrc32,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlComputeCrc32") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONGLONG wine32b_RtlUlonglongByteSwap(ULONGLONG i)
{
	TRACE("Enter RtlUlonglongByteSwap\n");
	return pRtlUlonglongByteSwap(i);
}

extern WINAPI void wine32a_RtlUlonglongByteSwap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUlonglongByteSwap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUlonglongByteSwap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlUniform(PULONG seed)
{
	TRACE("Enter RtlUniform\n");
	return pRtlUniform(seed);
}

extern WINAPI void wine32a_RtlUniform(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUniform,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUniform") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlRandom(PULONG seed)
{
	TRACE("Enter RtlRandom\n");
	return pRtlRandom(seed);
}

extern WINAPI void wine32a_RtlRandom(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRandom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRandom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlRandomEx(ULONG * seed)
{
	TRACE("Enter RtlRandomEx\n");
	return pRtlRandomEx(seed);
}

extern WINAPI void wine32a_RtlRandomEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRandomEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRandomEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlAreAllAccessesGranted(ACCESS_MASK GrantedAccess, ACCESS_MASK DesiredAccess)
{
	TRACE("Enter RtlAreAllAccessesGranted\n");
	return pRtlAreAllAccessesGranted(GrantedAccess, DesiredAccess);
}

extern WINAPI void wine32a_RtlAreAllAccessesGranted(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAreAllAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAreAllAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlAreAnyAccessesGranted(ACCESS_MASK GrantedAccess, ACCESS_MASK DesiredAccess)
{
	TRACE("Enter RtlAreAnyAccessesGranted\n");
	return pRtlAreAnyAccessesGranted(GrantedAccess, DesiredAccess);
}

extern WINAPI void wine32a_RtlAreAnyAccessesGranted(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAreAnyAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAreAnyAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlMapGenericMask(PACCESS_MASK AccessMask, const GENERIC_MAPPING * GenericMapping)
{
	TRACE("Enter RtlMapGenericMask\n");
	return pRtlMapGenericMask(AccessMask, GenericMapping);
}

extern WINAPI void wine32a_RtlMapGenericMask(void);
__ASM_GLOBAL_FUNC(wine32a_RtlMapGenericMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlMapGenericMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlCopyLuid(PLUID LuidDest, const LUID * LuidSrc)
{
	TRACE("Enter RtlCopyLuid\n");
	return pRtlCopyLuid(LuidDest, LuidSrc);
}

extern WINAPI void wine32a_RtlCopyLuid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopyLuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopyLuid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlEqualLuid(const LUID * Luid1, const LUID * Luid2)
{
	TRACE("Enter RtlEqualLuid\n");
	return pRtlEqualLuid(Luid1, Luid2);
}

extern WINAPI void wine32a_RtlEqualLuid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualLuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualLuid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlCopyLuidAndAttributesArray(ULONG Count, const LUID_AND_ATTRIBUTES * Src, PLUID_AND_ATTRIBUTES Dest)
{
	TRACE("Enter RtlCopyLuidAndAttributesArray\n");
	return pRtlCopyLuidAndAttributesArray(Count, Src, Dest);
}

extern WINAPI void wine32a_RtlCopyLuidAndAttributesArray(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopyLuidAndAttributesArray,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopyLuidAndAttributesArray") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIpv4StringToAddressExW(const WCHAR * str, BOOLEAN strict, IN_ADDR * address, USHORT * port)
{
	TRACE("Enter RtlIpv4StringToAddressExW\n");
	return pRtlIpv4StringToAddressExW(str, strict, address, port);
}

extern WINAPI void wine32a_RtlIpv4StringToAddressExW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4StringToAddressExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4StringToAddressExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIpv4StringToAddressW(const WCHAR * str, BOOLEAN strict, const WCHAR ** terminator, IN_ADDR * address)
{
	TRACE("Enter RtlIpv4StringToAddressW\n");
	return pRtlIpv4StringToAddressW(str, strict, terminator, address);
}

extern WINAPI void wine32a_RtlIpv4StringToAddressW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4StringToAddressW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4StringToAddressW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIpv6StringToAddressExW(const WCHAR * str, IN6_ADDR * address, ULONG * scope, USHORT * port)
{
	TRACE("Enter RtlIpv6StringToAddressExW\n");
	return pRtlIpv6StringToAddressExW(str, address, scope, port);
}

extern WINAPI void wine32a_RtlIpv6StringToAddressExW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv6StringToAddressExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv6StringToAddressExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIpv4AddressToStringExW(const IN_ADDR * pin, USHORT port, LPWSTR buffer, PULONG psize)
{
	TRACE("Enter RtlIpv4AddressToStringExW\n");
	return pRtlIpv4AddressToStringExW(pin, port, buffer, psize);
}

extern WINAPI void wine32a_RtlIpv4AddressToStringExW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4AddressToStringExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4AddressToStringExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIpv4AddressToStringExA(const IN_ADDR * pin, USHORT port, LPSTR buffer, PULONG psize)
{
	TRACE("Enter RtlIpv4AddressToStringExA\n");
	return pRtlIpv4AddressToStringExA(pin, port, buffer, psize);
}

extern WINAPI void wine32a_RtlIpv4AddressToStringExA(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4AddressToStringExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4AddressToStringExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR * wine32b_RtlIpv4AddressToStringW(const IN_ADDR * pin, LPWSTR buffer)
{
	TRACE("Enter RtlIpv4AddressToStringW\n");
	return pRtlIpv4AddressToStringW(pin, buffer);
}

extern WINAPI void wine32a_RtlIpv4AddressToStringW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4AddressToStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4AddressToStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI CHAR * wine32b_RtlIpv4AddressToStringA(const IN_ADDR * pin, LPSTR buffer)
{
	TRACE("Enter RtlIpv4AddressToStringA\n");
	return pRtlIpv4AddressToStringA(pin, buffer);
}

extern WINAPI void wine32a_RtlIpv4AddressToStringA(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIpv4AddressToStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIpv4AddressToStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlEncodePointer(PVOID ptr)
{
	TRACE("Enter RtlEncodePointer\n");
	return pRtlEncodePointer(ptr);
}

extern WINAPI void wine32a_RtlEncodePointer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEncodePointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEncodePointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlDecodePointer(PVOID ptr)
{
	TRACE("Enter RtlDecodePointer\n");
	return pRtlDecodePointer(ptr);
}

extern WINAPI void wine32a_RtlDecodePointer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDecodePointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDecodePointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitializeSListHead(PSLIST_HEADER list)
{
	TRACE("Enter RtlInitializeSListHead\n");
	return pRtlInitializeSListHead(list);
}

extern WINAPI void wine32a_RtlInitializeSListHead(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeSListHead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeSListHead") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_RtlQueryDepthSList(PSLIST_HEADER list)
{
	TRACE("Enter RtlQueryDepthSList\n");
	return pRtlQueryDepthSList(list);
}

extern WINAPI void wine32a_RtlQueryDepthSList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryDepthSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryDepthSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlFirstEntrySList(const SLIST_HEADER * list)
{
	TRACE("Enter RtlFirstEntrySList\n");
	return pRtlFirstEntrySList(list);
}

extern WINAPI void wine32a_RtlFirstEntrySList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFirstEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFirstEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlInterlockedFlushSList(PSLIST_HEADER list)
{
	TRACE("Enter RtlInterlockedFlushSList\n");
	return pRtlInterlockedFlushSList(list);
}

extern WINAPI void wine32a_RtlInterlockedFlushSList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInterlockedFlushSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInterlockedFlushSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlInterlockedPushEntrySList(PSLIST_HEADER list, PSLIST_ENTRY entry)
{
	TRACE("Enter RtlInterlockedPushEntrySList\n");
	return pRtlInterlockedPushEntrySList(list, entry);
}

extern WINAPI void wine32a_RtlInterlockedPushEntrySList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInterlockedPushEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInterlockedPushEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlInterlockedPopEntrySList(PSLIST_HEADER list)
{
	TRACE("Enter RtlInterlockedPopEntrySList\n");
	return pRtlInterlockedPopEntrySList(list);
}

extern WINAPI void wine32a_RtlInterlockedPopEntrySList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInterlockedPopEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInterlockedPopEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlInterlockedPushListSListEx(PSLIST_HEADER list, PSLIST_ENTRY first, PSLIST_ENTRY last, ULONG count)
{
	TRACE("Enter RtlInterlockedPushListSListEx\n");
	return pRtlInterlockedPushListSListEx(list, first, last, count);
}

extern WINAPI void wine32a_RtlInterlockedPushListSListEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInterlockedPushListSListEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInterlockedPushListSListEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSLIST_ENTRY wine32b_RtlInterlockedPushListSList(PSLIST_HEADER list, PSLIST_ENTRY first, PSLIST_ENTRY last, ULONG count)
{
	TRACE("Enter RtlInterlockedPushListSList\n");
	return pRtlInterlockedPushListSList(list, first, last, count);
}

extern WINAPI void wine32a_RtlInterlockedPushListSList(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInterlockedPushListSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInterlockedPushListSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetCompressionWorkSpaceSize(USHORT format, PULONG compress_workspace, PULONG decompress_workspace)
{
	TRACE("Enter RtlGetCompressionWorkSpaceSize\n");
	return pRtlGetCompressionWorkSpaceSize(format, compress_workspace, decompress_workspace);
}

extern WINAPI void wine32a_RtlGetCompressionWorkSpaceSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetCompressionWorkSpaceSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetCompressionWorkSpaceSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCompressBuffer(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, ULONG chunk_size, PULONG final_size, PVOID workspace)
{
	TRACE("Enter RtlCompressBuffer\n");
	return pRtlCompressBuffer(format, uncompressed, uncompressed_size, compressed, compressed_size, chunk_size, final_size, workspace);
}

extern WINAPI void wine32a_RtlCompressBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompressBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompressBuffer") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlDecompressFragment(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, ULONG offset, PULONG final_size, PVOID workspace)
{
	TRACE("Enter RtlDecompressFragment\n");
	return pRtlDecompressFragment(format, uncompressed, uncompressed_size, compressed, compressed_size, offset, final_size, workspace);
}

extern WINAPI void wine32a_RtlDecompressFragment(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDecompressFragment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDecompressFragment") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlDecompressBuffer(USHORT format, PUCHAR uncompressed, ULONG uncompressed_size, PUCHAR compressed, ULONG compressed_size, PULONG final_size)
{
	TRACE("Enter RtlDecompressBuffer\n");
	return pRtlDecompressBuffer(format, uncompressed, uncompressed_size, compressed, compressed_size, final_size);
}

extern WINAPI void wine32a_RtlDecompressBuffer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDecompressBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDecompressBuffer") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlSetThreadErrorMode(DWORD mode, LPDWORD oldmode)
{
	TRACE("Enter RtlSetThreadErrorMode\n");
	return pRtlSetThreadErrorMode(mode, oldmode);
}

extern WINAPI void wine32a_RtlSetThreadErrorMode(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetThreadErrorMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlGetThreadErrorMode(void)
{
	TRACE("Enter RtlGetThreadErrorMode\n");
	return pRtlGetThreadErrorMode();
}

extern WINAPI void wine32a_RtlGetThreadErrorMode(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetThreadErrorMode") "\n"
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

extern WINAPI HANDLE wine32b_RtlGetCurrentTransaction(void)
{
	TRACE("Enter RtlGetCurrentTransaction\n");
	return pRtlGetCurrentTransaction();
}

extern WINAPI void wine32a_RtlGetCurrentTransaction(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetCurrentTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetCurrentTransaction") "\n"
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

extern WINAPI BOOL wine32b_RtlSetCurrentTransaction(HANDLE new_transaction)
{
	TRACE("Enter RtlSetCurrentTransaction\n");
	return pRtlSetCurrentTransaction(new_transaction);
}

extern WINAPI void wine32a_RtlSetCurrentTransaction(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetCurrentTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetCurrentTransaction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlGetCurrentProcessorNumberEx(PROCESSOR_NUMBER * processor)
{
	TRACE("Enter RtlGetCurrentProcessorNumberEx\n");
	return pRtlGetCurrentProcessorNumberEx(processor);
}

extern WINAPI void wine32a_RtlGetCurrentProcessorNumberEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetCurrentProcessorNumberEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetCurrentProcessorNumberEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitializeGenericTableAvl(PRTL_AVL_TABLE table, PRTL_AVL_COMPARE_ROUTINE compare, PRTL_AVL_ALLOCATE_ROUTINE allocate, PRTL_AVL_FREE_ROUTINE free, void * context)
{
	TRACE("Enter RtlInitializeGenericTableAvl\n");
	return pRtlInitializeGenericTableAvl(table, compare, allocate, free, context);
}

extern WINAPI void wine32a_RtlInitializeGenericTableAvl(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeGenericTableAvl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeGenericTableAvl") "\n"
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

extern WINAPI void wine32b_RtlInsertElementGenericTableAvl(PRTL_AVL_TABLE table, void * buffer, ULONG size, BOOL * element)
{
	TRACE("Enter RtlInsertElementGenericTableAvl\n");
	return pRtlInsertElementGenericTableAvl(table, buffer, size, element);
}

extern WINAPI void wine32a_RtlInsertElementGenericTableAvl(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInsertElementGenericTableAvl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInsertElementGenericTableAvl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryPackageIdentity(HANDLE token, WCHAR * fullname, SIZE_T * fullname_size, WCHAR * appid, SIZE_T * appid_size, BOOLEAN * packaged)
{
	TRACE("Enter RtlQueryPackageIdentity\n");
	return pRtlQueryPackageIdentity(token, fullname, fullname_size, appid, appid_size, packaged);
}

extern WINAPI void wine32a_RtlQueryPackageIdentity(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryPackageIdentity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryPackageIdentity") "\n"
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

static WINAPI void (*pRtlInitializeBitMap)(PRTL_BITMAP lpBits, PULONG lpBuff, ULONG ulSize);
static WINAPI void (*pRtlSetAllBits)(PRTL_BITMAP lpBits);
static WINAPI void (*pRtlClearAllBits)(PRTL_BITMAP lpBits);
static WINAPI void (*pRtlSetBits)(PRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount);
static WINAPI void (*pRtlClearBits)(PRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount);
static WINAPI BOOLEAN (*pRtlAreBitsSet)(PCRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount);
static WINAPI BOOLEAN (*pRtlAreBitsClear)(PCRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount);
static WINAPI ULONG (*pRtlFindSetBits)(PCRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint);
static WINAPI ULONG (*pRtlFindClearBits)(PCRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint);
static WINAPI ULONG (*pRtlFindSetBitsAndClear)(PRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint);
static WINAPI ULONG (*pRtlFindClearBitsAndSet)(PRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint);
static WINAPI ULONG (*pRtlNumberOfSetBits)(PCRTL_BITMAP lpBits);
static WINAPI ULONG (*pRtlNumberOfClearBits)(PCRTL_BITMAP lpBits);
static WINAPI CCHAR (*pRtlFindMostSignificantBit)(ULONGLONG ulLong);
static WINAPI CCHAR (*pRtlFindLeastSignificantBit)(ULONGLONG ulLong);
static WINAPI ULONG (*pRtlFindNextForwardRunSet)(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos);
static WINAPI ULONG (*pRtlFindNextForwardRunClear)(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos);
static WINAPI ULONG (*pRtlFindLastBackwardRunSet)(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos);
static WINAPI ULONG (*pRtlFindLastBackwardRunClear)(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos);
static WINAPI ULONG (*pRtlFindSetRuns)(PCRTL_BITMAP lpBits, PRTL_BITMAP_RUN lpSeries, ULONG ulCount, BOOLEAN bLongest);
static WINAPI ULONG (*pRtlFindClearRuns)(PCRTL_BITMAP lpBits, PRTL_BITMAP_RUN lpSeries, ULONG ulCount, BOOLEAN bLongest);
static WINAPI ULONG (*pRtlFindLongestRunSet)(PCRTL_BITMAP lpBits, PULONG pulStart);
static WINAPI ULONG (*pRtlFindLongestRunClear)(PCRTL_BITMAP lpBits, PULONG pulStart);

extern WINAPI void wine32b_RtlInitializeBitMap(PRTL_BITMAP lpBits, PULONG lpBuff, ULONG ulSize)
{
	TRACE("Enter RtlInitializeBitMap\n");
	return pRtlInitializeBitMap(lpBits, lpBuff, ulSize);
}

extern WINAPI void wine32a_RtlInitializeBitMap(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeBitMap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeBitMap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSetAllBits(PRTL_BITMAP lpBits)
{
	TRACE("Enter RtlSetAllBits\n");
	return pRtlSetAllBits(lpBits);
}

extern WINAPI void wine32a_RtlSetAllBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetAllBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetAllBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlClearAllBits(PRTL_BITMAP lpBits)
{
	TRACE("Enter RtlClearAllBits\n");
	return pRtlClearAllBits(lpBits);
}

extern WINAPI void wine32a_RtlClearAllBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlClearAllBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlClearAllBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSetBits(PRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount)
{
	TRACE("Enter RtlSetBits\n");
	return pRtlSetBits(lpBits, ulStart, ulCount);
}

extern WINAPI void wine32a_RtlSetBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlClearBits(PRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount)
{
	TRACE("Enter RtlClearBits\n");
	return pRtlClearBits(lpBits, ulStart, ulCount);
}

extern WINAPI void wine32a_RtlClearBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlAreBitsSet(PCRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount)
{
	TRACE("Enter RtlAreBitsSet\n");
	return pRtlAreBitsSet(lpBits, ulStart, ulCount);
}

extern WINAPI void wine32a_RtlAreBitsSet(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAreBitsSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAreBitsSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlAreBitsClear(PCRTL_BITMAP lpBits, ULONG ulStart, ULONG ulCount)
{
	TRACE("Enter RtlAreBitsClear\n");
	return pRtlAreBitsClear(lpBits, ulStart, ulCount);
}

extern WINAPI void wine32a_RtlAreBitsClear(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAreBitsClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAreBitsClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindSetBits(PCRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint)
{
	TRACE("Enter RtlFindSetBits\n");
	return pRtlFindSetBits(lpBits, ulCount, ulHint);
}

extern WINAPI void wine32a_RtlFindSetBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindClearBits(PCRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint)
{
	TRACE("Enter RtlFindClearBits\n");
	return pRtlFindClearBits(lpBits, ulCount, ulHint);
}

extern WINAPI void wine32a_RtlFindClearBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindSetBitsAndClear(PRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint)
{
	TRACE("Enter RtlFindSetBitsAndClear\n");
	return pRtlFindSetBitsAndClear(lpBits, ulCount, ulHint);
}

extern WINAPI void wine32a_RtlFindSetBitsAndClear(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindSetBitsAndClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindSetBitsAndClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindClearBitsAndSet(PRTL_BITMAP lpBits, ULONG ulCount, ULONG ulHint)
{
	TRACE("Enter RtlFindClearBitsAndSet\n");
	return pRtlFindClearBitsAndSet(lpBits, ulCount, ulHint);
}

extern WINAPI void wine32a_RtlFindClearBitsAndSet(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindClearBitsAndSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindClearBitsAndSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlNumberOfSetBits(PCRTL_BITMAP lpBits)
{
	TRACE("Enter RtlNumberOfSetBits\n");
	return pRtlNumberOfSetBits(lpBits);
}

extern WINAPI void wine32a_RtlNumberOfSetBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNumberOfSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNumberOfSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlNumberOfClearBits(PCRTL_BITMAP lpBits)
{
	TRACE("Enter RtlNumberOfClearBits\n");
	return pRtlNumberOfClearBits(lpBits);
}

extern WINAPI void wine32a_RtlNumberOfClearBits(void);
__ASM_GLOBAL_FUNC(wine32a_RtlNumberOfClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlNumberOfClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI CCHAR wine32b_RtlFindMostSignificantBit(ULONGLONG ulLong)
{
	TRACE("Enter RtlFindMostSignificantBit\n");
	return pRtlFindMostSignificantBit(ulLong);
}

extern WINAPI void wine32a_RtlFindMostSignificantBit(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindMostSignificantBit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindMostSignificantBit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI CCHAR wine32b_RtlFindLeastSignificantBit(ULONGLONG ulLong)
{
	TRACE("Enter RtlFindLeastSignificantBit\n");
	return pRtlFindLeastSignificantBit(ulLong);
}

extern WINAPI void wine32a_RtlFindLeastSignificantBit(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindLeastSignificantBit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindLeastSignificantBit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindNextForwardRunSet(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos)
{
	TRACE("Enter RtlFindNextForwardRunSet\n");
	return pRtlFindNextForwardRunSet(lpBits, ulStart, lpPos);
}

extern WINAPI void wine32a_RtlFindNextForwardRunSet(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindNextForwardRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindNextForwardRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindNextForwardRunClear(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos)
{
	TRACE("Enter RtlFindNextForwardRunClear\n");
	return pRtlFindNextForwardRunClear(lpBits, ulStart, lpPos);
}

extern WINAPI void wine32a_RtlFindNextForwardRunClear(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindNextForwardRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindNextForwardRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindLastBackwardRunSet(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos)
{
	TRACE("Enter RtlFindLastBackwardRunSet\n");
	return pRtlFindLastBackwardRunSet(lpBits, ulStart, lpPos);
}

extern WINAPI void wine32a_RtlFindLastBackwardRunSet(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindLastBackwardRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindLastBackwardRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindLastBackwardRunClear(PCRTL_BITMAP lpBits, ULONG ulStart, PULONG lpPos)
{
	TRACE("Enter RtlFindLastBackwardRunClear\n");
	return pRtlFindLastBackwardRunClear(lpBits, ulStart, lpPos);
}

extern WINAPI void wine32a_RtlFindLastBackwardRunClear(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindLastBackwardRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindLastBackwardRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindSetRuns(PCRTL_BITMAP lpBits, PRTL_BITMAP_RUN lpSeries, ULONG ulCount, BOOLEAN bLongest)
{
	TRACE("Enter RtlFindSetRuns\n");
	return pRtlFindSetRuns(lpBits, lpSeries, ulCount, bLongest);
}

extern WINAPI void wine32a_RtlFindSetRuns(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindSetRuns,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindSetRuns") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindClearRuns(PCRTL_BITMAP lpBits, PRTL_BITMAP_RUN lpSeries, ULONG ulCount, BOOLEAN bLongest)
{
	TRACE("Enter RtlFindClearRuns\n");
	return pRtlFindClearRuns(lpBits, lpSeries, ulCount, bLongest);
}

extern WINAPI void wine32a_RtlFindClearRuns(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindClearRuns,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindClearRuns") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindLongestRunSet(PCRTL_BITMAP lpBits, PULONG pulStart)
{
	TRACE("Enter RtlFindLongestRunSet\n");
	return pRtlFindLongestRunSet(lpBits, pulStart);
}

extern WINAPI void wine32a_RtlFindLongestRunSet(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindLongestRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindLongestRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlFindLongestRunClear(PCRTL_BITMAP lpBits, PULONG pulStart)
{
	TRACE("Enter RtlFindLongestRunClear\n");
	return pRtlFindLongestRunClear(lpBits, pulStart);
}

extern WINAPI void wine32a_RtlFindLongestRunClear(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindLongestRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindLongestRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*p__wine_init_codepages)(const union cptable * ansi, const union cptable * oem, const union cptable * ucp);
static WINAPI void (*pRtlInitAnsiString)(PANSI_STRING target, PCSZ source);
static WINAPI NTSTATUS (*pRtlInitAnsiStringEx)(PANSI_STRING target, PCSZ source);
static WINAPI void (*pRtlInitString)(PSTRING target, PCSZ source);
static WINAPI void (*pRtlFreeAnsiString)(PSTRING str);
static WINAPI void (*pRtlFreeOemString)(PSTRING str);
static WINAPI void (*pRtlCopyString)(STRING * dst, const STRING * src);
static WINAPI void (*pRtlInitUnicodeString)(PUNICODE_STRING target, PCWSTR source);
static WINAPI NTSTATUS (*pRtlInitUnicodeStringEx)(PUNICODE_STRING target, PCWSTR source);
static WINAPI BOOLEAN (*pRtlCreateUnicodeString)(PUNICODE_STRING target, LPCWSTR src);
static WINAPI BOOLEAN (*pRtlCreateUnicodeStringFromAsciiz)(PUNICODE_STRING target, LPCSTR src);
static WINAPI void (*pRtlFreeUnicodeString)(PUNICODE_STRING str);
static WINAPI void (*pRtlCopyUnicodeString)(UNICODE_STRING * dst, const UNICODE_STRING * src);
static WINAPI NTSTATUS (*pRtlDuplicateUnicodeString)(int add_nul, const UNICODE_STRING * source, UNICODE_STRING * destination);
static WINAPI void (*pRtlEraseUnicodeString)(UNICODE_STRING * str);
static WINAPI LONG (*pRtlCompareString)(const STRING * s1, const STRING * s2, BOOLEAN CaseInsensitive);
static WINAPI LONG (*pRtlCompareUnicodeStrings)(const WCHAR * s1, SIZE_T len1, const WCHAR * s2, SIZE_T len2, BOOLEAN case_insensitive);
static WINAPI LONG (*pRtlCompareUnicodeString)(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN CaseInsensitive);
static WINAPI BOOLEAN (*pRtlEqualString)(const STRING * s1, const STRING * s2, BOOLEAN CaseInsensitive);
static WINAPI BOOLEAN (*pRtlEqualUnicodeString)(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN CaseInsensitive);
static WINAPI BOOLEAN (*pRtlPrefixString)(const STRING * s1, const STRING * s2, BOOLEAN ignore_case);
static WINAPI BOOLEAN (*pRtlPrefixUnicodeString)(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN ignore_case);
static WINAPI NTSTATUS (*pRtlEqualComputerName)(const UNICODE_STRING * left, const UNICODE_STRING * right);
static WINAPI NTSTATUS (*pRtlEqualDomainName)(const UNICODE_STRING * left, const UNICODE_STRING * right);
static WINAPI WCHAR (*pRtlAnsiCharToUnicodeChar)(LPSTR * ansi);
static WINAPI NTSTATUS (*pRtlAnsiStringToUnicodeString)(PUNICODE_STRING uni, PCANSI_STRING ansi, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlOemStringToUnicodeString)(UNICODE_STRING * uni, const STRING * oem, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUnicodeStringToAnsiString)(STRING * ansi, const UNICODE_STRING * uni, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUnicodeStringToOemString)(STRING * oem, const UNICODE_STRING * uni, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlMultiByteToUnicodeN)(LPWSTR dst, DWORD dstlen, LPDWORD reslen, LPCSTR src, DWORD srclen);
static WINAPI NTSTATUS (*pRtlOemToUnicodeN)(LPWSTR dst, DWORD dstlen, LPDWORD reslen, LPCSTR src, DWORD srclen);
static WINAPI NTSTATUS (*pRtlUnicodeToMultiByteN)(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen);
static WINAPI NTSTATUS (*pRtlUnicodeToOemN)(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen);
static WINAPI CHAR (*pRtlUpperChar)(CHAR ch);
static WINAPI void (*pRtlUpperString)(STRING * dst, const STRING * src);
static WINAPI WCHAR (*pRtlUpcaseUnicodeChar)(WCHAR wch);
static WINAPI WCHAR (*pRtlDowncaseUnicodeChar)(WCHAR wch);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeString)(UNICODE_STRING * dest, const UNICODE_STRING * src, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlDowncaseUnicodeString)(UNICODE_STRING * dest, const UNICODE_STRING * src, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToAnsiString)(STRING * dst, const UNICODE_STRING * src, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToOemString)(STRING * dst, const UNICODE_STRING * src, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToCountedOemString)(STRING * oem, const UNICODE_STRING * uni, BOOLEAN doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeToMultiByteN)(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeToOemN)(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen);
static WINAPI UINT (*pRtlOemStringToUnicodeSize)(const STRING * str);
static WINAPI DWORD (*pRtlAnsiStringToUnicodeSize)(const STRING * str);
static WINAPI NTSTATUS (*pRtlMultiByteToUnicodeSize)(DWORD * size, LPCSTR str, UINT len);
static WINAPI NTSTATUS (*pRtlUnicodeToMultiByteSize)(PULONG size, LPCWSTR str, ULONG len);
static WINAPI DWORD (*pRtlUnicodeStringToAnsiSize)(const UNICODE_STRING * str);
static WINAPI DWORD (*pRtlUnicodeStringToOemSize)(const UNICODE_STRING * str);
static WINAPI NTSTATUS (*pRtlAppendAsciizToString)(STRING * dest, LPCSTR src);
static WINAPI NTSTATUS (*pRtlAppendStringToString)(STRING * dest, const STRING * src);
static WINAPI NTSTATUS (*pRtlAppendUnicodeToString)(UNICODE_STRING * dest, LPCWSTR src);
static WINAPI NTSTATUS (*pRtlAppendUnicodeStringToString)(UNICODE_STRING * dest, const UNICODE_STRING * src);
static WINAPI NTSTATUS (*pRtlFindCharInUnicodeString)(int flags, const UNICODE_STRING * main_str, const UNICODE_STRING * search_chars, USHORT * pos);
static WINAPI BOOLEAN (*pRtlIsTextUnicode)(LPCVOID buf, INT len, INT * pf);
static WINAPI NTSTATUS (*pRtlCharToInteger)(PCSZ str, ULONG base, ULONG * value);
static WINAPI NTSTATUS (*pRtlIntegerToChar)(ULONG value, ULONG base, ULONG length, PCHAR str);
static WINAPI NTSTATUS (*pRtlUnicodeStringToInteger)(const UNICODE_STRING * str, ULONG base, ULONG * value);
static WINAPI NTSTATUS (*pRtlIntegerToUnicodeString)(ULONG value, ULONG base, UNICODE_STRING * str);
static WINAPI NTSTATUS (*pRtlGUIDFromString)(PUNICODE_STRING str, GUID * guid);
static WINAPI NTSTATUS (*pRtlStringFromGUID)(const GUID * guid, UNICODE_STRING * str);
static WINAPI NTSTATUS (*pRtlHashUnicodeString)(PCUNICODE_STRING string, BOOLEAN case_insensitive, ULONG alg, ULONG * hash);

extern WINAPI void wine32b___wine_init_codepages(const union cptable * ansi, const union cptable * oem, const union cptable * ucp)
{
	TRACE("Enter __wine_init_codepages\n");
	return p__wine_init_codepages(ansi, oem, ucp);
}

extern WINAPI void wine32a___wine_init_codepages(void);
__ASM_GLOBAL_FUNC(wine32a___wine_init_codepages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_init_codepages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitAnsiString(PANSI_STRING target, PCSZ source)
{
	TRACE("Enter RtlInitAnsiString\n");
	return pRtlInitAnsiString(target, source);
}

extern WINAPI void wine32a_RtlInitAnsiString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlInitAnsiStringEx(PANSI_STRING target, PCSZ source)
{
	TRACE("Enter RtlInitAnsiStringEx\n");
	return pRtlInitAnsiStringEx(target, source);
}

extern WINAPI void wine32a_RtlInitAnsiStringEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitAnsiStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitAnsiStringEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitString(PSTRING target, PCSZ source)
{
	TRACE("Enter RtlInitString\n");
	return pRtlInitString(target, source);
}

extern WINAPI void wine32a_RtlInitString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFreeAnsiString(PSTRING str)
{
	TRACE("Enter RtlFreeAnsiString\n");
	return pRtlFreeAnsiString(str);
}

extern WINAPI void wine32a_RtlFreeAnsiString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFreeOemString(PSTRING str)
{
	TRACE("Enter RtlFreeOemString\n");
	return pRtlFreeOemString(str);
}

extern WINAPI void wine32a_RtlFreeOemString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlCopyString(STRING * dst, const STRING * src)
{
	TRACE("Enter RtlCopyString\n");
	return pRtlCopyString(dst, src);
}

extern WINAPI void wine32a_RtlCopyString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopyString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopyString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitUnicodeString(PUNICODE_STRING target, PCWSTR source)
{
	TRACE("Enter RtlInitUnicodeString\n");
	return pRtlInitUnicodeString(target, source);
}

extern WINAPI void wine32a_RtlInitUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlInitUnicodeStringEx(PUNICODE_STRING target, PCWSTR source)
{
	TRACE("Enter RtlInitUnicodeStringEx\n");
	return pRtlInitUnicodeStringEx(target, source);
}

extern WINAPI void wine32a_RtlInitUnicodeStringEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitUnicodeStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitUnicodeStringEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlCreateUnicodeString(PUNICODE_STRING target, LPCWSTR src)
{
	TRACE("Enter RtlCreateUnicodeString\n");
	return pRtlCreateUnicodeString(target, src);
}

extern WINAPI void wine32a_RtlCreateUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlCreateUnicodeStringFromAsciiz(PUNICODE_STRING target, LPCSTR src)
{
	TRACE("Enter RtlCreateUnicodeStringFromAsciiz\n");
	return pRtlCreateUnicodeStringFromAsciiz(target, src);
}

extern WINAPI void wine32a_RtlCreateUnicodeStringFromAsciiz(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateUnicodeStringFromAsciiz,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateUnicodeStringFromAsciiz") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlFreeUnicodeString(PUNICODE_STRING str)
{
	TRACE("Enter RtlFreeUnicodeString\n");
	return pRtlFreeUnicodeString(str);
}

extern WINAPI void wine32a_RtlFreeUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlCopyUnicodeString(UNICODE_STRING * dst, const UNICODE_STRING * src)
{
	TRACE("Enter RtlCopyUnicodeString\n");
	return pRtlCopyUnicodeString(dst, src);
}

extern WINAPI void wine32a_RtlCopyUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopyUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopyUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDuplicateUnicodeString(int add_nul, const UNICODE_STRING * source, UNICODE_STRING * destination)
{
	TRACE("Enter RtlDuplicateUnicodeString\n");
	return pRtlDuplicateUnicodeString(add_nul, source, destination);
}

extern WINAPI void wine32a_RtlDuplicateUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDuplicateUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDuplicateUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlEraseUnicodeString(UNICODE_STRING * str)
{
	TRACE("Enter RtlEraseUnicodeString\n");
	return pRtlEraseUnicodeString(str);
}

extern WINAPI void wine32a_RtlEraseUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEraseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEraseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_RtlCompareString(const STRING * s1, const STRING * s2, BOOLEAN CaseInsensitive)
{
	TRACE("Enter RtlCompareString\n");
	return pRtlCompareString(s1, s2, CaseInsensitive);
}

extern WINAPI void wine32a_RtlCompareString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompareString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompareString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_RtlCompareUnicodeStrings(const WCHAR * s1, SIZE_T len1, const WCHAR * s2, SIZE_T len2, BOOLEAN case_insensitive)
{
	TRACE("Enter RtlCompareUnicodeStrings\n");
	return pRtlCompareUnicodeStrings(s1, len1, s2, len2, case_insensitive);
}

extern WINAPI void wine32a_RtlCompareUnicodeStrings(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompareUnicodeStrings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompareUnicodeStrings") "\n"
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

extern WINAPI LONG wine32b_RtlCompareUnicodeString(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN CaseInsensitive)
{
	TRACE("Enter RtlCompareUnicodeString\n");
	return pRtlCompareUnicodeString(s1, s2, CaseInsensitive);
}

extern WINAPI void wine32a_RtlCompareUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCompareUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCompareUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlEqualString(const STRING * s1, const STRING * s2, BOOLEAN CaseInsensitive)
{
	TRACE("Enter RtlEqualString\n");
	return pRtlEqualString(s1, s2, CaseInsensitive);
}

extern WINAPI void wine32a_RtlEqualString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlEqualUnicodeString(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN CaseInsensitive)
{
	TRACE("Enter RtlEqualUnicodeString\n");
	return pRtlEqualUnicodeString(s1, s2, CaseInsensitive);
}

extern WINAPI void wine32a_RtlEqualUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlPrefixString(const STRING * s1, const STRING * s2, BOOLEAN ignore_case)
{
	TRACE("Enter RtlPrefixString\n");
	return pRtlPrefixString(s1, s2, ignore_case);
}

extern WINAPI void wine32a_RtlPrefixString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPrefixString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPrefixString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlPrefixUnicodeString(const UNICODE_STRING * s1, const UNICODE_STRING * s2, BOOLEAN ignore_case)
{
	TRACE("Enter RtlPrefixUnicodeString\n");
	return pRtlPrefixUnicodeString(s1, s2, ignore_case);
}

extern WINAPI void wine32a_RtlPrefixUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPrefixUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPrefixUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlEqualComputerName(const UNICODE_STRING * left, const UNICODE_STRING * right)
{
	TRACE("Enter RtlEqualComputerName\n");
	return pRtlEqualComputerName(left, right);
}

extern WINAPI void wine32a_RtlEqualComputerName(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualComputerName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualComputerName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlEqualDomainName(const UNICODE_STRING * left, const UNICODE_STRING * right)
{
	TRACE("Enter RtlEqualDomainName\n");
	return pRtlEqualDomainName(left, right);
}

extern WINAPI void wine32a_RtlEqualDomainName(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualDomainName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualDomainName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR wine32b_RtlAnsiCharToUnicodeChar(LPSTR * ansi)
{
	TRACE("Enter RtlAnsiCharToUnicodeChar\n");
	return pRtlAnsiCharToUnicodeChar(ansi);
}

extern WINAPI void wine32a_RtlAnsiCharToUnicodeChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAnsiCharToUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAnsiCharToUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAnsiStringToUnicodeString(PUNICODE_STRING uni, PCANSI_STRING ansi, BOOLEAN doalloc)
{
	TRACE("Enter RtlAnsiStringToUnicodeString\n");
	return pRtlAnsiStringToUnicodeString(uni, ansi, doalloc);
}

extern WINAPI void wine32a_RtlAnsiStringToUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAnsiStringToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAnsiStringToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlOemStringToUnicodeString(UNICODE_STRING * uni, const STRING * oem, BOOLEAN doalloc)
{
	TRACE("Enter RtlOemStringToUnicodeString\n");
	return pRtlOemStringToUnicodeString(uni, oem, doalloc);
}

extern WINAPI void wine32a_RtlOemStringToUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlOemStringToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlOemStringToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUnicodeStringToAnsiString(STRING * ansi, const UNICODE_STRING * uni, BOOLEAN doalloc)
{
	TRACE("Enter RtlUnicodeStringToAnsiString\n");
	return pRtlUnicodeStringToAnsiString(ansi, uni, doalloc);
}

extern WINAPI void wine32a_RtlUnicodeStringToAnsiString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeStringToAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeStringToAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUnicodeStringToOemString(STRING * oem, const UNICODE_STRING * uni, BOOLEAN doalloc)
{
	TRACE("Enter RtlUnicodeStringToOemString\n");
	return pRtlUnicodeStringToOemString(oem, uni, doalloc);
}

extern WINAPI void wine32a_RtlUnicodeStringToOemString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeStringToOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeStringToOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlMultiByteToUnicodeN(LPWSTR dst, DWORD dstlen, LPDWORD reslen, LPCSTR src, DWORD srclen)
{
	TRACE("Enter RtlMultiByteToUnicodeN\n");
	return pRtlMultiByteToUnicodeN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlMultiByteToUnicodeN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlMultiByteToUnicodeN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlMultiByteToUnicodeN") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlOemToUnicodeN(LPWSTR dst, DWORD dstlen, LPDWORD reslen, LPCSTR src, DWORD srclen)
{
	TRACE("Enter RtlOemToUnicodeN\n");
	return pRtlOemToUnicodeN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlOemToUnicodeN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlOemToUnicodeN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlOemToUnicodeN") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlUnicodeToMultiByteN(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen)
{
	TRACE("Enter RtlUnicodeToMultiByteN\n");
	return pRtlUnicodeToMultiByteN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlUnicodeToMultiByteN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeToMultiByteN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeToMultiByteN") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlUnicodeToOemN(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen)
{
	TRACE("Enter RtlUnicodeToOemN\n");
	return pRtlUnicodeToOemN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlUnicodeToOemN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeToOemN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeToOemN") "\n"
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

extern WINAPI CHAR wine32b_RtlUpperChar(CHAR ch)
{
	TRACE("Enter RtlUpperChar\n");
	return pRtlUpperChar(ch);
}

extern WINAPI void wine32a_RtlUpperChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpperChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpperChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlUpperString(STRING * dst, const STRING * src)
{
	TRACE("Enter RtlUpperString\n");
	return pRtlUpperString(dst, src);
}

extern WINAPI void wine32a_RtlUpperString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpperString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpperString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR wine32b_RtlUpcaseUnicodeChar(WCHAR wch)
{
	TRACE("Enter RtlUpcaseUnicodeChar\n");
	return pRtlUpcaseUnicodeChar(wch);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR wine32b_RtlDowncaseUnicodeChar(WCHAR wch)
{
	TRACE("Enter RtlDowncaseUnicodeChar\n");
	return pRtlDowncaseUnicodeChar(wch);
}

extern WINAPI void wine32a_RtlDowncaseUnicodeChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDowncaseUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDowncaseUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeString(UNICODE_STRING * dest, const UNICODE_STRING * src, BOOLEAN doalloc)
{
	TRACE("Enter RtlUpcaseUnicodeString\n");
	return pRtlUpcaseUnicodeString(dest, src, doalloc);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDowncaseUnicodeString(UNICODE_STRING * dest, const UNICODE_STRING * src, BOOLEAN doalloc)
{
	TRACE("Enter RtlDowncaseUnicodeString\n");
	return pRtlDowncaseUnicodeString(dest, src, doalloc);
}

extern WINAPI void wine32a_RtlDowncaseUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDowncaseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDowncaseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeStringToAnsiString(STRING * dst, const UNICODE_STRING * src, BOOLEAN doalloc)
{
	TRACE("Enter RtlUpcaseUnicodeStringToAnsiString\n");
	return pRtlUpcaseUnicodeStringToAnsiString(dst, src, doalloc);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeStringToAnsiString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeStringToAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeStringToAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeStringToOemString(STRING * dst, const UNICODE_STRING * src, BOOLEAN doalloc)
{
	TRACE("Enter RtlUpcaseUnicodeStringToOemString\n");
	return pRtlUpcaseUnicodeStringToOemString(dst, src, doalloc);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeStringToOemString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeStringToOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeStringToOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeStringToCountedOemString(STRING * oem, const UNICODE_STRING * uni, BOOLEAN doalloc)
{
	TRACE("Enter RtlUpcaseUnicodeStringToCountedOemString\n");
	return pRtlUpcaseUnicodeStringToCountedOemString(oem, uni, doalloc);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeStringToCountedOemString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeStringToCountedOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeStringToCountedOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeToMultiByteN(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen)
{
	TRACE("Enter RtlUpcaseUnicodeToMultiByteN\n");
	return pRtlUpcaseUnicodeToMultiByteN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeToMultiByteN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeToMultiByteN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeToMultiByteN") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlUpcaseUnicodeToOemN(LPSTR dst, DWORD dstlen, LPDWORD reslen, LPCWSTR src, DWORD srclen)
{
	TRACE("Enter RtlUpcaseUnicodeToOemN\n");
	return pRtlUpcaseUnicodeToOemN(dst, dstlen, reslen, src, srclen);
}

extern WINAPI void wine32a_RtlUpcaseUnicodeToOemN(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpcaseUnicodeToOemN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpcaseUnicodeToOemN") "\n"
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

extern WINAPI UINT wine32b_RtlOemStringToUnicodeSize(const STRING * str)
{
	TRACE("Enter RtlOemStringToUnicodeSize\n");
	return pRtlOemStringToUnicodeSize(str);
}

extern WINAPI void wine32a_RtlOemStringToUnicodeSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlOemStringToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlOemStringToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlAnsiStringToUnicodeSize(const STRING * str)
{
	TRACE("Enter RtlAnsiStringToUnicodeSize\n");
	return pRtlAnsiStringToUnicodeSize(str);
}

extern WINAPI void wine32a_RtlAnsiStringToUnicodeSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAnsiStringToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAnsiStringToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlMultiByteToUnicodeSize(DWORD * size, LPCSTR str, UINT len)
{
	TRACE("Enter RtlMultiByteToUnicodeSize\n");
	return pRtlMultiByteToUnicodeSize(size, str, len);
}

extern WINAPI void wine32a_RtlMultiByteToUnicodeSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlMultiByteToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlMultiByteToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUnicodeToMultiByteSize(PULONG size, LPCWSTR str, ULONG len)
{
	TRACE("Enter RtlUnicodeToMultiByteSize\n");
	return pRtlUnicodeToMultiByteSize(size, str, len);
}

extern WINAPI void wine32a_RtlUnicodeToMultiByteSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeToMultiByteSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeToMultiByteSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlUnicodeStringToAnsiSize(const UNICODE_STRING * str)
{
	TRACE("Enter RtlUnicodeStringToAnsiSize\n");
	return pRtlUnicodeStringToAnsiSize(str);
}

extern WINAPI void wine32a_RtlUnicodeStringToAnsiSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeStringToAnsiSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeStringToAnsiSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlUnicodeStringToOemSize(const UNICODE_STRING * str)
{
	TRACE("Enter RtlUnicodeStringToOemSize\n");
	return pRtlUnicodeStringToOemSize(str);
}

extern WINAPI void wine32a_RtlUnicodeStringToOemSize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeStringToOemSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeStringToOemSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAppendAsciizToString(STRING * dest, LPCSTR src)
{
	TRACE("Enter RtlAppendAsciizToString\n");
	return pRtlAppendAsciizToString(dest, src);
}

extern WINAPI void wine32a_RtlAppendAsciizToString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAppendAsciizToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAppendAsciizToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAppendStringToString(STRING * dest, const STRING * src)
{
	TRACE("Enter RtlAppendStringToString\n");
	return pRtlAppendStringToString(dest, src);
}

extern WINAPI void wine32a_RtlAppendStringToString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAppendStringToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAppendStringToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAppendUnicodeToString(UNICODE_STRING * dest, LPCWSTR src)
{
	TRACE("Enter RtlAppendUnicodeToString\n");
	return pRtlAppendUnicodeToString(dest, src);
}

extern WINAPI void wine32a_RtlAppendUnicodeToString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAppendUnicodeToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAppendUnicodeToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAppendUnicodeStringToString(UNICODE_STRING * dest, const UNICODE_STRING * src)
{
	TRACE("Enter RtlAppendUnicodeStringToString\n");
	return pRtlAppendUnicodeStringToString(dest, src);
}

extern WINAPI void wine32a_RtlAppendUnicodeStringToString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAppendUnicodeStringToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAppendUnicodeStringToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlFindCharInUnicodeString(int flags, const UNICODE_STRING * main_str, const UNICODE_STRING * search_chars, USHORT * pos)
{
	TRACE("Enter RtlFindCharInUnicodeString\n");
	return pRtlFindCharInUnicodeString(flags, main_str, search_chars, pos);
}

extern WINAPI void wine32a_RtlFindCharInUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFindCharInUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFindCharInUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlIsTextUnicode(LPCVOID buf, INT len, INT * pf)
{
	TRACE("Enter RtlIsTextUnicode\n");
	return pRtlIsTextUnicode(buf, len, pf);
}

extern WINAPI void wine32a_RtlIsTextUnicode(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIsTextUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIsTextUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCharToInteger(PCSZ str, ULONG base, ULONG * value)
{
	TRACE("Enter RtlCharToInteger\n");
	return pRtlCharToInteger(str, base, value);
}

extern WINAPI void wine32a_RtlCharToInteger(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCharToInteger,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCharToInteger") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIntegerToChar(ULONG value, ULONG base, ULONG length, PCHAR str)
{
	TRACE("Enter RtlIntegerToChar\n");
	return pRtlIntegerToChar(value, base, length, str);
}

extern WINAPI void wine32a_RtlIntegerToChar(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIntegerToChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIntegerToChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlUnicodeStringToInteger(const UNICODE_STRING * str, ULONG base, ULONG * value)
{
	TRACE("Enter RtlUnicodeStringToInteger\n");
	return pRtlUnicodeStringToInteger(str, base, value);
}

extern WINAPI void wine32a_RtlUnicodeStringToInteger(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnicodeStringToInteger,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnicodeStringToInteger") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlIntegerToUnicodeString(ULONG value, ULONG base, UNICODE_STRING * str)
{
	TRACE("Enter RtlIntegerToUnicodeString\n");
	return pRtlIntegerToUnicodeString(value, base, str);
}

extern WINAPI void wine32a_RtlIntegerToUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIntegerToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIntegerToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGUIDFromString(PUNICODE_STRING str, GUID * guid)
{
	TRACE("Enter RtlGUIDFromString\n");
	return pRtlGUIDFromString(str, guid);
}

extern WINAPI void wine32a_RtlGUIDFromString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGUIDFromString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGUIDFromString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlStringFromGUID(const GUID * guid, UNICODE_STRING * str)
{
	TRACE("Enter RtlStringFromGUID\n");
	return pRtlStringFromGUID(guid, str);
}

extern WINAPI void wine32a_RtlStringFromGUID(void);
__ASM_GLOBAL_FUNC(wine32a_RtlStringFromGUID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlStringFromGUID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlHashUnicodeString(PCUNICODE_STRING string, BOOLEAN case_insensitive, ULONG alg, ULONG * hash)
{
	TRACE("Enter RtlHashUnicodeString\n");
	return pRtlHashUnicodeString(string, case_insensitive, alg, hash);
}

extern WINAPI void wine32a_RtlHashUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlHashUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlHashUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pRtlAllocateAndInitializeSid)(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority, BYTE nSubAuthorityCount, DWORD nSubAuthority0, DWORD nSubAuthority1, DWORD nSubAuthority2, DWORD nSubAuthority3, DWORD nSubAuthority4, DWORD nSubAuthority5, DWORD nSubAuthority6, DWORD nSubAuthority7, PSID * pSid);
static WINAPI BOOL (*pRtlEqualSid)(PSID pSid1, PSID pSid2);
static WINAPI BOOL (*pRtlEqualPrefixSid)(PSID pSid1, PSID pSid2);
static WINAPI DWORD (*pRtlFreeSid)(PSID pSid);
static WINAPI DWORD (*pRtlLengthRequiredSid)(DWORD nrofsubauths);
static WINAPI DWORD (*pRtlLengthSid)(PSID pSid);
static WINAPI BOOL (*pRtlInitializeSid)(PSID pSid, PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority, BYTE nSubAuthorityCount);
static WINAPI LPDWORD (*pRtlSubAuthoritySid)(PSID pSid, DWORD nSubAuthority);
static WINAPI PSID_IDENTIFIER_AUTHORITY (*pRtlIdentifierAuthoritySid)(PSID pSid);
static WINAPI LPBYTE (*pRtlSubAuthorityCountSid)(PSID pSid);
static WINAPI BOOLEAN (*pRtlCopySid)(DWORD nDestinationSidLength, PSID pDestinationSid, PSID pSourceSid);
static WINAPI BOOLEAN (*pRtlValidSid)(PSID pSid);
static WINAPI NTSTATUS (*pRtlCreateSecurityDescriptor)(PSECURITY_DESCRIPTOR lpsd, DWORD rev);
static WINAPI NTSTATUS (*pRtlCopySecurityDescriptor)(PSECURITY_DESCRIPTOR pSourceSD, PSECURITY_DESCRIPTOR pDestinationSD);
static WINAPI NTSTATUS (*pRtlValidSecurityDescriptor)(PSECURITY_DESCRIPTOR SecurityDescriptor);
static WINAPI BOOLEAN (*pRtlValidRelativeSecurityDescriptor)(PSECURITY_DESCRIPTOR descriptor, ULONG length, SECURITY_INFORMATION info);
static WINAPI ULONG (*pRtlLengthSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor);
static WINAPI NTSTATUS (*pRtlGetDaclSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PBOOLEAN lpbDaclPresent, PACL * pDacl, PBOOLEAN lpbDaclDefaulted);
static WINAPI NTSTATUS (*pRtlSetDaclSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, BOOLEAN daclpresent, PACL dacl, BOOLEAN dacldefaulted);
static WINAPI NTSTATUS (*pRtlGetSaclSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PBOOLEAN lpbSaclPresent, PACL * pSacl, PBOOLEAN lpbSaclDefaulted);
static WINAPI NTSTATUS (*pRtlSetSaclSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, BOOLEAN saclpresent, PACL sacl, BOOLEAN sacldefaulted);
static WINAPI NTSTATUS (*pRtlGetOwnerSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID * Owner, PBOOLEAN OwnerDefaulted);
static WINAPI NTSTATUS (*pRtlSetOwnerSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID owner, BOOLEAN ownerdefaulted);
static WINAPI NTSTATUS (*pRtlSetGroupSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID group, BOOLEAN groupdefaulted);
static WINAPI NTSTATUS (*pRtlGetGroupSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID * Group, PBOOLEAN GroupDefaulted);
static WINAPI NTSTATUS (*pRtlMakeSelfRelativeSD)(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor, LPDWORD lpdwBufferLength);
static WINAPI NTSTATUS (*pRtlSelfRelativeToAbsoluteSD)(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor, PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor, LPDWORD lpdwAbsoluteSecurityDescriptorSize, PACL pDacl, LPDWORD lpdwDaclSize, PACL pSacl, LPDWORD lpdwSaclSize, PSID pOwner, LPDWORD lpdwOwnerSize, PSID pPrimaryGroup, LPDWORD lpdwPrimaryGroupSize);
static WINAPI NTSTATUS (*pRtlGetControlSecurityDescriptor)(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSECURITY_DESCRIPTOR_CONTROL pControl, LPDWORD lpdwRevision);
static WINAPI NTSTATUS (*pRtlSetControlSecurityDescriptor)(PSECURITY_DESCRIPTOR SecurityDescriptor, SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest, SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet);
static WINAPI NTSTATUS (*pRtlAbsoluteToSelfRelativeSD)(PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor, PULONG BufferLength);
static WINAPI NTSTATUS (*pRtlCreateAcl)(PACL acl, DWORD size, DWORD rev);
static WINAPI BOOLEAN (*pRtlFirstFreeAce)(PACL acl, PACE_HEADER * x);
static WINAPI NTSTATUS (*pRtlAddAce)(PACL acl, DWORD rev, DWORD xnrofaces, PACE_HEADER acestart, DWORD acelen);
static WINAPI NTSTATUS (*pRtlDeleteAce)(PACL pAcl, DWORD dwAceIndex);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedAce)(PACL pAcl, DWORD dwAceRevision, DWORD AccessMask, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedAceEx)(PACL pAcl, DWORD dwAceRevision, DWORD AceFlags, DWORD AccessMask, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedObjectAce)(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedAce)(PACL pAcl, DWORD dwAceRevision, DWORD AccessMask, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedAceEx)(PACL pAcl, DWORD dwAceRevision, DWORD AceFlags, DWORD AccessMask, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedObjectAce)(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid);
static WINAPI NTSTATUS (*pRtlAddAuditAccessAceEx)(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddAuditAccessAce)(PACL pAcl, DWORD dwAceRevision, DWORD dwAccessMask, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddAuditAccessObjectAce)(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddMandatoryAce)(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwMandatoryFlags, DWORD dwAceType, PSID pSid);
static WINAPI BOOLEAN (*pRtlValidAcl)(PACL pAcl);
static WINAPI NTSTATUS (*pRtlGetAce)(PACL pAcl, DWORD dwAceIndex, LPVOID * pAce);
static WINAPI NTSTATUS (*pRtlAdjustPrivilege)(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled);
static WINAPI NTSTATUS (*pRtlImpersonateSelf)(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
static WINAPI NTSTATUS (*pNtImpersonateAnonymousToken)(HANDLE thread);
static WINAPI NTSTATUS (*pNtAccessCheck)(PSECURITY_DESCRIPTOR SecurityDescriptor, HANDLE ClientToken, ACCESS_MASK DesiredAccess, PGENERIC_MAPPING GenericMapping, PPRIVILEGE_SET PrivilegeSet, PULONG ReturnLength, PULONG GrantedAccess, NTSTATUS * AccessStatus);
static WINAPI NTSTATUS (*pNtSetSecurityObject)(HANDLE Handle, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR SecurityDescriptor);
static WINAPI NTSTATUS (*pRtlConvertSidToUnicodeString)(PUNICODE_STRING String, PSID pSid, BOOLEAN AllocateString);
static WINAPI NTSTATUS (*pRtlQueryInformationAcl)(PACL pAcl, LPVOID pAclInformation, DWORD nAclInformationLength, ACL_INFORMATION_CLASS dwAclInformationClass);
static WINAPI BOOL (*pRtlConvertToAutoInheritSecurityObject)(PSECURITY_DESCRIPTOR pdesc, PSECURITY_DESCRIPTOR cdesc, PSECURITY_DESCRIPTOR * ndesc, GUID * objtype, BOOL isdir, PGENERIC_MAPPING genmap);

extern WINAPI NTSTATUS wine32b_RtlAllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority, BYTE nSubAuthorityCount, DWORD nSubAuthority0, DWORD nSubAuthority1, DWORD nSubAuthority2, DWORD nSubAuthority3, DWORD nSubAuthority4, DWORD nSubAuthority5, DWORD nSubAuthority6, DWORD nSubAuthority7, PSID * pSid)
{
	TRACE("Enter RtlAllocateAndInitializeSid\n");
	return pRtlAllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid);
}

extern WINAPI void wine32a_RtlAllocateAndInitializeSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAllocateAndInitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAllocateAndInitializeSid") "\n"
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

extern WINAPI BOOL wine32b_RtlEqualSid(PSID pSid1, PSID pSid2)
{
	TRACE("Enter RtlEqualSid\n");
	return pRtlEqualSid(pSid1, pSid2);
}

extern WINAPI void wine32a_RtlEqualSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlEqualPrefixSid(PSID pSid1, PSID pSid2)
{
	TRACE("Enter RtlEqualPrefixSid\n");
	return pRtlEqualPrefixSid(pSid1, pSid2);
}

extern WINAPI void wine32a_RtlEqualPrefixSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlEqualPrefixSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlEqualPrefixSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlFreeSid(PSID pSid)
{
	TRACE("Enter RtlFreeSid\n");
	return pRtlFreeSid(pSid);
}

extern WINAPI void wine32a_RtlFreeSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlLengthRequiredSid(DWORD nrofsubauths)
{
	TRACE("Enter RtlLengthRequiredSid\n");
	return pRtlLengthRequiredSid(nrofsubauths);
}

extern WINAPI void wine32a_RtlLengthRequiredSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLengthRequiredSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLengthRequiredSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlLengthSid(PSID pSid)
{
	TRACE("Enter RtlLengthSid\n");
	return pRtlLengthSid(pSid);
}

extern WINAPI void wine32a_RtlLengthSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLengthSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLengthSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlInitializeSid(PSID pSid, PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority, BYTE nSubAuthorityCount)
{
	TRACE("Enter RtlInitializeSid\n");
	return pRtlInitializeSid(pSid, pIdentifierAuthority, nSubAuthorityCount);
}

extern WINAPI void wine32a_RtlInitializeSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPDWORD wine32b_RtlSubAuthoritySid(PSID pSid, DWORD nSubAuthority)
{
	TRACE("Enter RtlSubAuthoritySid\n");
	return pRtlSubAuthoritySid(pSid, nSubAuthority);
}

extern WINAPI void wine32a_RtlSubAuthoritySid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSubAuthoritySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSubAuthoritySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSID_IDENTIFIER_AUTHORITY wine32b_RtlIdentifierAuthoritySid(PSID pSid)
{
	TRACE("Enter RtlIdentifierAuthoritySid\n");
	return pRtlIdentifierAuthoritySid(pSid);
}

extern WINAPI void wine32a_RtlIdentifierAuthoritySid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlIdentifierAuthoritySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlIdentifierAuthoritySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPBYTE wine32b_RtlSubAuthorityCountSid(PSID pSid)
{
	TRACE("Enter RtlSubAuthorityCountSid\n");
	return pRtlSubAuthorityCountSid(pSid);
}

extern WINAPI void wine32a_RtlSubAuthorityCountSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSubAuthorityCountSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSubAuthorityCountSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlCopySid(DWORD nDestinationSidLength, PSID pDestinationSid, PSID pSourceSid)
{
	TRACE("Enter RtlCopySid\n");
	return pRtlCopySid(nDestinationSidLength, pDestinationSid, pSourceSid);
}

extern WINAPI void wine32a_RtlCopySid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlValidSid(PSID pSid)
{
	TRACE("Enter RtlValidSid\n");
	return pRtlValidSid(pSid);
}

extern WINAPI void wine32a_RtlValidSid(void);
__ASM_GLOBAL_FUNC(wine32a_RtlValidSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlValidSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateSecurityDescriptor(PSECURITY_DESCRIPTOR lpsd, DWORD rev)
{
	TRACE("Enter RtlCreateSecurityDescriptor\n");
	return pRtlCreateSecurityDescriptor(lpsd, rev);
}

extern WINAPI void wine32a_RtlCreateSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCopySecurityDescriptor(PSECURITY_DESCRIPTOR pSourceSD, PSECURITY_DESCRIPTOR pDestinationSD)
{
	TRACE("Enter RtlCopySecurityDescriptor\n");
	return pRtlCopySecurityDescriptor(pSourceSD, pDestinationSD);
}

extern WINAPI void wine32a_RtlCopySecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCopySecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCopySecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlValidSecurityDescriptor(PSECURITY_DESCRIPTOR SecurityDescriptor)
{
	TRACE("Enter RtlValidSecurityDescriptor\n");
	return pRtlValidSecurityDescriptor(SecurityDescriptor);
}

extern WINAPI void wine32a_RtlValidSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlValidSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlValidSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlValidRelativeSecurityDescriptor(PSECURITY_DESCRIPTOR descriptor, ULONG length, SECURITY_INFORMATION info)
{
	TRACE("Enter RtlValidRelativeSecurityDescriptor\n");
	return pRtlValidRelativeSecurityDescriptor(descriptor, length, info);
}

extern WINAPI void wine32a_RtlValidRelativeSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlValidRelativeSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlValidRelativeSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_RtlLengthSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor)
{
	TRACE("Enter RtlLengthSecurityDescriptor\n");
	return pRtlLengthSecurityDescriptor(pSecurityDescriptor);
}

extern WINAPI void wine32a_RtlLengthSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLengthSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLengthSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetDaclSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PBOOLEAN lpbDaclPresent, PACL * pDacl, PBOOLEAN lpbDaclDefaulted)
{
	TRACE("Enter RtlGetDaclSecurityDescriptor\n");
	return pRtlGetDaclSecurityDescriptor(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted);
}

extern WINAPI void wine32a_RtlGetDaclSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetDaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetDaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetDaclSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, BOOLEAN daclpresent, PACL dacl, BOOLEAN dacldefaulted)
{
	TRACE("Enter RtlSetDaclSecurityDescriptor\n");
	return pRtlSetDaclSecurityDescriptor(pSecurityDescriptor, daclpresent, dacl, dacldefaulted);
}

extern WINAPI void wine32a_RtlSetDaclSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetDaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetDaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetSaclSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PBOOLEAN lpbSaclPresent, PACL * pSacl, PBOOLEAN lpbSaclDefaulted)
{
	TRACE("Enter RtlGetSaclSecurityDescriptor\n");
	return pRtlGetSaclSecurityDescriptor(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted);
}

extern WINAPI void wine32a_RtlGetSaclSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetSaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetSaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetSaclSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, BOOLEAN saclpresent, PACL sacl, BOOLEAN sacldefaulted)
{
	TRACE("Enter RtlSetSaclSecurityDescriptor\n");
	return pRtlSetSaclSecurityDescriptor(pSecurityDescriptor, saclpresent, sacl, sacldefaulted);
}

extern WINAPI void wine32a_RtlSetSaclSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetSaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetSaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetOwnerSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID * Owner, PBOOLEAN OwnerDefaulted)
{
	TRACE("Enter RtlGetOwnerSecurityDescriptor\n");
	return pRtlGetOwnerSecurityDescriptor(pSecurityDescriptor, Owner, OwnerDefaulted);
}

extern WINAPI void wine32a_RtlGetOwnerSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetOwnerSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetOwnerSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetOwnerSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID owner, BOOLEAN ownerdefaulted)
{
	TRACE("Enter RtlSetOwnerSecurityDescriptor\n");
	return pRtlSetOwnerSecurityDescriptor(pSecurityDescriptor, owner, ownerdefaulted);
}

extern WINAPI void wine32a_RtlSetOwnerSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetOwnerSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetOwnerSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetGroupSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID group, BOOLEAN groupdefaulted)
{
	TRACE("Enter RtlSetGroupSecurityDescriptor\n");
	return pRtlSetGroupSecurityDescriptor(pSecurityDescriptor, group, groupdefaulted);
}

extern WINAPI void wine32a_RtlSetGroupSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetGroupSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetGroupSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetGroupSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSID * Group, PBOOLEAN GroupDefaulted)
{
	TRACE("Enter RtlGetGroupSecurityDescriptor\n");
	return pRtlGetGroupSecurityDescriptor(pSecurityDescriptor, Group, GroupDefaulted);
}

extern WINAPI void wine32a_RtlGetGroupSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetGroupSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetGroupSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlMakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor, LPDWORD lpdwBufferLength)
{
	TRACE("Enter RtlMakeSelfRelativeSD\n");
	return pRtlMakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength);
}

extern WINAPI void wine32a_RtlMakeSelfRelativeSD(void);
__ASM_GLOBAL_FUNC(wine32a_RtlMakeSelfRelativeSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlMakeSelfRelativeSD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSelfRelativeToAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor, PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor, LPDWORD lpdwAbsoluteSecurityDescriptorSize, PACL pDacl, LPDWORD lpdwDaclSize, PACL pSacl, LPDWORD lpdwSaclSize, PSID pOwner, LPDWORD lpdwOwnerSize, PSID pPrimaryGroup, LPDWORD lpdwPrimaryGroupSize)
{
	TRACE("Enter RtlSelfRelativeToAbsoluteSD\n");
	return pRtlSelfRelativeToAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize);
}

extern WINAPI void wine32a_RtlSelfRelativeToAbsoluteSD(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSelfRelativeToAbsoluteSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSelfRelativeToAbsoluteSD") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlGetControlSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor, PSECURITY_DESCRIPTOR_CONTROL pControl, LPDWORD lpdwRevision)
{
	TRACE("Enter RtlGetControlSecurityDescriptor\n");
	return pRtlGetControlSecurityDescriptor(pSecurityDescriptor, pControl, lpdwRevision);
}

extern WINAPI void wine32a_RtlGetControlSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetControlSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetControlSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetControlSecurityDescriptor(PSECURITY_DESCRIPTOR SecurityDescriptor, SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest, SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet)
{
	TRACE("Enter RtlSetControlSecurityDescriptor\n");
	return pRtlSetControlSecurityDescriptor(SecurityDescriptor, ControlBitsOfInterest, ControlBitsToSet);
}

extern WINAPI void wine32a_RtlSetControlSecurityDescriptor(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetControlSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetControlSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAbsoluteToSelfRelativeSD(PSECURITY_DESCRIPTOR AbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR SelfRelativeSecurityDescriptor, PULONG BufferLength)
{
	TRACE("Enter RtlAbsoluteToSelfRelativeSD\n");
	return pRtlAbsoluteToSelfRelativeSD(AbsoluteSecurityDescriptor, SelfRelativeSecurityDescriptor, BufferLength);
}

extern WINAPI void wine32a_RtlAbsoluteToSelfRelativeSD(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAbsoluteToSelfRelativeSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAbsoluteToSelfRelativeSD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateAcl(PACL acl, DWORD size, DWORD rev)
{
	TRACE("Enter RtlCreateAcl\n");
	return pRtlCreateAcl(acl, size, rev);
}

extern WINAPI void wine32a_RtlCreateAcl(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlFirstFreeAce(PACL acl, PACE_HEADER * x)
{
	TRACE("Enter RtlFirstFreeAce\n");
	return pRtlFirstFreeAce(acl, x);
}

extern WINAPI void wine32a_RtlFirstFreeAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFirstFreeAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFirstFreeAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAddAce(PACL acl, DWORD rev, DWORD xnrofaces, PACE_HEADER acestart, DWORD acelen)
{
	TRACE("Enter RtlAddAce\n");
	return pRtlAddAce(acl, rev, xnrofaces, acestart, acelen);
}

extern WINAPI void wine32a_RtlAddAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAce") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlDeleteAce(PACL pAcl, DWORD dwAceIndex)
{
	TRACE("Enter RtlDeleteAce\n");
	return pRtlDeleteAce(pAcl, dwAceIndex);
}

extern WINAPI void wine32a_RtlDeleteAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAddAccessAllowedAce(PACL pAcl, DWORD dwAceRevision, DWORD AccessMask, PSID pSid)
{
	TRACE("Enter RtlAddAccessAllowedAce\n");
	return pRtlAddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid);
}

extern WINAPI void wine32a_RtlAddAccessAllowedAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessAllowedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessAllowedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAddAccessAllowedAceEx(PACL pAcl, DWORD dwAceRevision, DWORD AceFlags, DWORD AccessMask, PSID pSid)
{
	TRACE("Enter RtlAddAccessAllowedAceEx\n");
	return pRtlAddAccessAllowedAceEx(pAcl, dwAceRevision, AceFlags, AccessMask, pSid);
}

extern WINAPI void wine32a_RtlAddAccessAllowedAceEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessAllowedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessAllowedAceEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAccessAllowedObjectAce(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid)
{
	TRACE("Enter RtlAddAccessAllowedObjectAce\n");
	return pRtlAddAccessAllowedObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid);
}

extern WINAPI void wine32a_RtlAddAccessAllowedObjectAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessAllowedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessAllowedObjectAce") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAccessDeniedAce(PACL pAcl, DWORD dwAceRevision, DWORD AccessMask, PSID pSid)
{
	TRACE("Enter RtlAddAccessDeniedAce\n");
	return pRtlAddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid);
}

extern WINAPI void wine32a_RtlAddAccessDeniedAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessDeniedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessDeniedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAddAccessDeniedAceEx(PACL pAcl, DWORD dwAceRevision, DWORD AceFlags, DWORD AccessMask, PSID pSid)
{
	TRACE("Enter RtlAddAccessDeniedAceEx\n");
	return pRtlAddAccessDeniedAceEx(pAcl, dwAceRevision, AceFlags, AccessMask, pSid);
}

extern WINAPI void wine32a_RtlAddAccessDeniedAceEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessDeniedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessDeniedAceEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAccessDeniedObjectAce(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid)
{
	TRACE("Enter RtlAddAccessDeniedObjectAce\n");
	return pRtlAddAccessDeniedObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid);
}

extern WINAPI void wine32a_RtlAddAccessDeniedObjectAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAccessDeniedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAccessDeniedObjectAce") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAuditAccessAceEx(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure)
{
	TRACE("Enter RtlAddAuditAccessAceEx\n");
	return pRtlAddAuditAccessAceEx(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pSid, bAuditSuccess, bAuditFailure);
}

extern WINAPI void wine32a_RtlAddAuditAccessAceEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAuditAccessAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAuditAccessAceEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAuditAccessAce(PACL pAcl, DWORD dwAceRevision, DWORD dwAccessMask, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure)
{
	TRACE("Enter RtlAddAuditAccessAce\n");
	return pRtlAddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure);
}

extern WINAPI void wine32a_RtlAddAuditAccessAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAuditAccessAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAuditAccessAce") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddAuditAccessObjectAce(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwAccessMask, GUID * pObjectTypeGuid, GUID * pInheritedObjectTypeGuid, PSID pSid, BOOL bAuditSuccess, BOOL bAuditFailure)
{
	TRACE("Enter RtlAddAuditAccessObjectAce\n");
	return pRtlAddAuditAccessObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid, bAuditSuccess, bAuditFailure);
}

extern WINAPI void wine32a_RtlAddAuditAccessObjectAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddAuditAccessObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddAuditAccessObjectAce") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlAddMandatoryAce(PACL pAcl, DWORD dwAceRevision, DWORD dwAceFlags, DWORD dwMandatoryFlags, DWORD dwAceType, PSID pSid)
{
	TRACE("Enter RtlAddMandatoryAce\n");
	return pRtlAddMandatoryAce(pAcl, dwAceRevision, dwAceFlags, dwMandatoryFlags, dwAceType, pSid);
}

extern WINAPI void wine32a_RtlAddMandatoryAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAddMandatoryAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAddMandatoryAce") "\n"
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

extern WINAPI BOOLEAN wine32b_RtlValidAcl(PACL pAcl)
{
	TRACE("Enter RtlValidAcl\n");
	return pRtlValidAcl(pAcl);
}

extern WINAPI void wine32a_RtlValidAcl(void);
__ASM_GLOBAL_FUNC(wine32a_RtlValidAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlValidAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlGetAce(PACL pAcl, DWORD dwAceIndex, LPVOID * pAce)
{
	TRACE("Enter RtlGetAce\n");
	return pRtlGetAce(pAcl, dwAceIndex, pAce);
}

extern WINAPI void wine32a_RtlGetAce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlAdjustPrivilege(ULONG Privilege, BOOLEAN Enable, BOOLEAN CurrentThread, PBOOLEAN Enabled)
{
	TRACE("Enter RtlAdjustPrivilege\n");
	return pRtlAdjustPrivilege(Privilege, Enable, CurrentThread, Enabled);
}

extern WINAPI void wine32a_RtlAdjustPrivilege(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAdjustPrivilege,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAdjustPrivilege") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel)
{
	TRACE("Enter RtlImpersonateSelf\n");
	return pRtlImpersonateSelf(ImpersonationLevel);
}

extern WINAPI void wine32a_RtlImpersonateSelf(void);
__ASM_GLOBAL_FUNC(wine32a_RtlImpersonateSelf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlImpersonateSelf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtImpersonateAnonymousToken(HANDLE thread)
{
	TRACE("Enter NtImpersonateAnonymousToken\n");
	return pNtImpersonateAnonymousToken(thread);
}

extern WINAPI void wine32a_NtImpersonateAnonymousToken(void);
__ASM_GLOBAL_FUNC(wine32a_NtImpersonateAnonymousToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtImpersonateAnonymousToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAccessCheck(PSECURITY_DESCRIPTOR SecurityDescriptor, HANDLE ClientToken, ACCESS_MASK DesiredAccess, PGENERIC_MAPPING GenericMapping, PPRIVILEGE_SET PrivilegeSet, PULONG ReturnLength, PULONG GrantedAccess, NTSTATUS * AccessStatus)
{
	TRACE("Enter NtAccessCheck\n");
	return pNtAccessCheck(SecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, ReturnLength, GrantedAccess, AccessStatus);
}

extern WINAPI void wine32a_NtAccessCheck(void);
__ASM_GLOBAL_FUNC(wine32a_NtAccessCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAccessCheck") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetSecurityObject(HANDLE Handle, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR SecurityDescriptor)
{
	TRACE("Enter NtSetSecurityObject\n");
	return pNtSetSecurityObject(Handle, SecurityInformation, SecurityDescriptor);
}

extern WINAPI void wine32a_NtSetSecurityObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetSecurityObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlConvertSidToUnicodeString(PUNICODE_STRING String, PSID pSid, BOOLEAN AllocateString)
{
	TRACE("Enter RtlConvertSidToUnicodeString\n");
	return pRtlConvertSidToUnicodeString(String, pSid, AllocateString);
}

extern WINAPI void wine32a_RtlConvertSidToUnicodeString(void);
__ASM_GLOBAL_FUNC(wine32a_RtlConvertSidToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlConvertSidToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryInformationAcl(PACL pAcl, LPVOID pAclInformation, DWORD nAclInformationLength, ACL_INFORMATION_CLASS dwAclInformationClass)
{
	TRACE("Enter RtlQueryInformationAcl\n");
	return pRtlQueryInformationAcl(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass);
}

extern WINAPI void wine32a_RtlQueryInformationAcl(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryInformationAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryInformationAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_RtlConvertToAutoInheritSecurityObject(PSECURITY_DESCRIPTOR pdesc, PSECURITY_DESCRIPTOR cdesc, PSECURITY_DESCRIPTOR * ndesc, GUID * objtype, BOOL isdir, PGENERIC_MAPPING genmap)
{
	TRACE("Enter RtlConvertToAutoInheritSecurityObject\n");
	return pRtlConvertToAutoInheritSecurityObject(pdesc, cdesc, ndesc, objtype, isdir, genmap);
}

extern WINAPI void wine32a_RtlConvertToAutoInheritSecurityObject(void);
__ASM_GLOBAL_FUNC(wine32a_RtlConvertToAutoInheritSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlConvertToAutoInheritSecurityObject") "\n"
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


static WINAPI unsigned int (*pwine_server_call)(void * req_ptr);
static WINAPI void (*pwine_server_send_fd)(int fd);
static WINAPI int (*pwine_server_fd_to_handle)(int fd, unsigned int access, unsigned int attributes, HANDLE * handle);
static WINAPI int (*pwine_server_handle_to_fd)(HANDLE handle, unsigned int access, int * unix_fd, unsigned int * options);
static WINAPI void (*pwine_server_release_fd)(HANDLE handle, int unix_fd);

extern WINAPI unsigned int wine32b_wine_server_call(void * req_ptr)
{
	TRACE("Enter wine_server_call\n");
	return pwine_server_call(req_ptr);
}

extern WINAPI void wine32a_wine_server_call(void);
__ASM_GLOBAL_FUNC(wine32a_wine_server_call,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_server_call") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_wine_server_send_fd(int fd)
{
	TRACE("Enter wine_server_send_fd\n");
	return pwine_server_send_fd(fd);
}

extern WINAPI void wine32a_wine_server_send_fd(void);
__ASM_GLOBAL_FUNC(wine32a_wine_server_send_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_server_send_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_wine_server_fd_to_handle(int fd, unsigned int access, unsigned int attributes, HANDLE * handle)
{
	TRACE("Enter wine_server_fd_to_handle\n");
	return pwine_server_fd_to_handle(fd, access, attributes, handle);
}

extern WINAPI void wine32a_wine_server_fd_to_handle(void);
__ASM_GLOBAL_FUNC(wine32a_wine_server_fd_to_handle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_server_fd_to_handle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_wine_server_handle_to_fd(HANDLE handle, unsigned int access, int * unix_fd, unsigned int * options)
{
	TRACE("Enter wine_server_handle_to_fd\n");
	return pwine_server_handle_to_fd(handle, access, unix_fd, options);
}

extern WINAPI void wine32a_wine_server_handle_to_fd(void);
__ASM_GLOBAL_FUNC(wine32a_wine_server_handle_to_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_server_handle_to_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_wine_server_release_fd(HANDLE handle, int unix_fd)
{
	TRACE("Enter wine_server_release_fd\n");
	return pwine_server_release_fd(handle, unix_fd);
}

extern WINAPI void wine32a_wine_server_release_fd(void);
__ASM_GLOBAL_FUNC(wine32a_wine_server_release_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_wine_server_release_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)





static WINAPI NTSTATUS (*pNtSetContextThread)(HANDLE handle, const CONTEXT * context);
static WINAPI NTSTATUS (*pNtGetContextThread)(HANDLE handle, CONTEXT * context);
static WINAPI NTSTATUS (*pRtlWow64GetThreadContext)(HANDLE handle, WOW64_CONTEXT * context);
static WINAPI NTSTATUS (*pRtlWow64SetThreadContext)(HANDLE handle, const WOW64_CONTEXT * context);
static WINAPI NTSTATUS (*pNtRaiseException)(EXCEPTION_RECORD * rec, CONTEXT * context, BOOL first_chance);
static WINAPI int (*p__wine_set_signal_handler)(unsigned int sig, wine_signal_handler wsh);
static WINAPI PVOID (*pRtlVirtualUnwind)(ULONG type, ULONG64 base, ULONG64 pc, RUNTIME_FUNCTION * function, CONTEXT * context, PVOID * data, ULONG64 * frame_ret, KNONVOLATILE_CONTEXT_POINTERS * ctx_ptr);
static WINAPI void (*pRtlRestoreContext)(CONTEXT * context, EXCEPTION_RECORD * rec);
static WINAPI void (*pRtlUnwindEx)(PVOID end_frame, PVOID target_ip, EXCEPTION_RECORD * rec, PVOID retval, CONTEXT * context, UNWIND_HISTORY_TABLE * table);
static WINAPI void (*pRtlUnwind)(void * frame, void * target_ip, EXCEPTION_RECORD * rec, void * retval);
static WINAPI void (*p_local_unwind)(void * frame, void * target_ip);
static WINAPI EXCEPTION_DISPOSITION (*p__C_specific_handler)(EXCEPTION_RECORD * rec, void * frame, CONTEXT * context, struct _DISPATCHER_CONTEXT * dispatch);
static WINAPI USHORT (*pRtlCaptureStackBackTrace)(ULONG skip, ULONG count, PVOID * buffer, ULONG * hash);

extern WINAPI NTSTATUS wine32b_NtSetContextThread(HANDLE handle, const CONTEXT * context)
{
	TRACE("Enter NtSetContextThread\n");
	return pNtSetContextThread(handle, context);
}

extern WINAPI void wine32a_NtSetContextThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetContextThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetContextThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtGetContextThread(HANDLE handle, CONTEXT * context)
{
	TRACE("Enter NtGetContextThread\n");
	return pNtGetContextThread(handle, context);
}

extern WINAPI void wine32a_NtGetContextThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtGetContextThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtGetContextThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWow64GetThreadContext(HANDLE handle, WOW64_CONTEXT * context)
{
	TRACE("Enter RtlWow64GetThreadContext\n");
	return pRtlWow64GetThreadContext(handle, context);
}

extern WINAPI void wine32a_RtlWow64GetThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWow64GetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWow64GetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWow64SetThreadContext(HANDLE handle, const WOW64_CONTEXT * context)
{
	TRACE("Enter RtlWow64SetThreadContext\n");
	return pRtlWow64SetThreadContext(handle, context);
}

extern WINAPI void wine32a_RtlWow64SetThreadContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWow64SetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWow64SetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtRaiseException(EXCEPTION_RECORD * rec, CONTEXT * context, BOOL first_chance)
{
	TRACE("Enter NtRaiseException\n");
	return pNtRaiseException(rec, context, first_chance);
}

extern WINAPI void wine32a_NtRaiseException(void);
__ASM_GLOBAL_FUNC(wine32a_NtRaiseException,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRaiseException") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b___wine_set_signal_handler(unsigned int sig, wine_signal_handler wsh)
{
	TRACE("Enter __wine_set_signal_handler\n");
	return p__wine_set_signal_handler(sig, wsh);
}

extern WINAPI void wine32a___wine_set_signal_handler(void);
__ASM_GLOBAL_FUNC(wine32a___wine_set_signal_handler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_set_signal_handler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_RtlVirtualUnwind(ULONG type, ULONG64 base, ULONG64 pc, RUNTIME_FUNCTION * function, CONTEXT * context, PVOID * data, ULONG64 * frame_ret, KNONVOLATILE_CONTEXT_POINTERS * ctx_ptr)
{
	TRACE("Enter RtlVirtualUnwind\n");
	return pRtlVirtualUnwind(type, base, pc, function, context, data, frame_ret, ctx_ptr);
}

extern WINAPI void wine32a_RtlVirtualUnwind(void);
__ASM_GLOBAL_FUNC(wine32a_RtlVirtualUnwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlVirtualUnwind") "\n"
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

extern WINAPI void wine32b_RtlRestoreContext(CONTEXT * context, EXCEPTION_RECORD * rec)
{
	TRACE("Enter RtlRestoreContext\n");
	return pRtlRestoreContext(context, rec);
}

extern WINAPI void wine32a_RtlRestoreContext(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRestoreContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRestoreContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlUnwindEx(PVOID end_frame, PVOID target_ip, EXCEPTION_RECORD * rec, PVOID retval, CONTEXT * context, UNWIND_HISTORY_TABLE * table)
{
	TRACE("Enter RtlUnwindEx\n");
	return pRtlUnwindEx(end_frame, target_ip, rec, retval, context, table);
}

extern WINAPI void wine32a_RtlUnwindEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnwindEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnwindEx") "\n"
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

extern WINAPI void wine32b_RtlUnwind(void * frame, void * target_ip, EXCEPTION_RECORD * rec, void * retval)
{
	TRACE("Enter RtlUnwind\n");
	return pRtlUnwind(frame, target_ip, rec, retval);
}

extern WINAPI void wine32a_RtlUnwind(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUnwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUnwind") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b__local_unwind(void * frame, void * target_ip)
{
	TRACE("Enter _local_unwind\n");
	return p_local_unwind(frame, target_ip);
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

extern WINAPI EXCEPTION_DISPOSITION wine32b___C_specific_handler(EXCEPTION_RECORD * rec, void * frame, CONTEXT * context, struct _DISPATCHER_CONTEXT * dispatch)
{
	TRACE("Enter __C_specific_handler\n");
	return p__C_specific_handler(rec, frame, context, dispatch);
}

extern WINAPI void wine32a___C_specific_handler(void);
__ASM_GLOBAL_FUNC(wine32a___C_specific_handler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___C_specific_handler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI USHORT wine32b_RtlCaptureStackBackTrace(ULONG skip, ULONG count, PVOID * buffer, ULONG * hash)
{
	TRACE("Enter RtlCaptureStackBackTrace\n");
	return pRtlCaptureStackBackTrace(skip, count, buffer, hash);
}

extern WINAPI void wine32a_RtlCaptureStackBackTrace(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCaptureStackBackTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCaptureStackBackTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void * (*p_memccpy)(void * dst, const void * src, int c, size_t n);
static WINAPI INT (*p_memicmp)(LPCSTR s1, LPCSTR s2, DWORD len);
static WINAPI int (*p_strnicmp)(LPCSTR str1, LPCSTR str2, size_t n);
static WINAPI int (*p_stricmp)(LPCSTR str1, LPCSTR str2);
static WINAPI LPSTR (*p_strupr)(LPSTR str);
static WINAPI LPSTR (*p_strlwr)(LPSTR str);
static WINAPI char * (*p_ultoa)(ULONG value, char * str, int radix);
static WINAPI char * (*p_ltoa)(LONG value, char * str, int radix);
static WINAPI char * (*p_itoa)(int value, char * str, int radix);
static WINAPI char * (*p_ui64toa)(ULONGLONG value, char * str, int radix);
static WINAPI char * (*p_i64toa)(LONGLONG value, char * str, int radix);
static WINAPI LONGLONG (*p_atoi64)(const char * str);
static WINAPI void (*p_splitpath)(const char * inpath, char * drv, char * dir, char * fname, char * ext);

extern WINAPI void * wine32b__memccpy(void * dst, const void * src, int c, size_t n)
{
	TRACE("Enter _memccpy\n");
	return p_memccpy(dst, src, c, n);
}

extern WINAPI void wine32a__memccpy(void);
__ASM_GLOBAL_FUNC(wine32a__memccpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__memccpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b__memicmp(LPCSTR s1, LPCSTR s2, DWORD len)
{
	TRACE("Enter _memicmp\n");
	return p_memicmp(s1, s2, len);
}

extern WINAPI void wine32a__memicmp(void);
__ASM_GLOBAL_FUNC(wine32a__memicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__memicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b__strnicmp(LPCSTR str1, LPCSTR str2, size_t n)
{
	TRACE("Enter _strnicmp\n");
	return p_strnicmp(str1, str2, n);
}

extern WINAPI void wine32a__strnicmp(void);
__ASM_GLOBAL_FUNC(wine32a__strnicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strnicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b__stricmp(LPCSTR str1, LPCSTR str2)
{
	TRACE("Enter _stricmp\n");
	return p_stricmp(str1, str2);
}

extern WINAPI void wine32a__stricmp(void);
__ASM_GLOBAL_FUNC(wine32a__stricmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__stricmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b__strupr(LPSTR str)
{
	TRACE("Enter _strupr\n");
	return p_strupr(str);
}

extern WINAPI void wine32a__strupr(void);
__ASM_GLOBAL_FUNC(wine32a__strupr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strupr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b__strlwr(LPSTR str)
{
	TRACE("Enter _strlwr\n");
	return p_strlwr(str);
}

extern WINAPI void wine32a__strlwr(void);
__ASM_GLOBAL_FUNC(wine32a__strlwr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__strlwr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b__ultoa(ULONG value, char * str, int radix)
{
	TRACE("Enter _ultoa\n");
	return p_ultoa(value, str, radix);
}

extern WINAPI void wine32a__ultoa(void);
__ASM_GLOBAL_FUNC(wine32a__ultoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ultoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b__ltoa(LONG value, char * str, int radix)
{
	TRACE("Enter _ltoa\n");
	return p_ltoa(value, str, radix);
}

extern WINAPI void wine32a__ltoa(void);
__ASM_GLOBAL_FUNC(wine32a__ltoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ltoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b__itoa(int value, char * str, int radix)
{
	TRACE("Enter _itoa\n");
	return p_itoa(value, str, radix);
}

extern WINAPI void wine32a__itoa(void);
__ASM_GLOBAL_FUNC(wine32a__itoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__itoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b__ui64toa(ULONGLONG value, char * str, int radix)
{
	TRACE("Enter _ui64toa\n");
	return p_ui64toa(value, str, radix);
}

extern WINAPI void wine32a__ui64toa(void);
__ASM_GLOBAL_FUNC(wine32a__ui64toa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ui64toa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char * wine32b__i64toa(LONGLONG value, char * str, int radix)
{
	TRACE("Enter _i64toa\n");
	return p_i64toa(value, str, radix);
}

extern WINAPI void wine32a__i64toa(void);
__ASM_GLOBAL_FUNC(wine32a__i64toa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__i64toa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONGLONG wine32b__atoi64(const char * str)
{
	TRACE("Enter _atoi64\n");
	return p_atoi64(str);
}

extern WINAPI void wine32a__atoi64(void);
__ASM_GLOBAL_FUNC(wine32a__atoi64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__atoi64") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b__splitpath(const char * inpath, char * drv, char * dir, char * fname, char * ext)
{
	TRACE("Enter _splitpath\n");
	return p_splitpath(inpath, drv, dir, fname, ext);
}

extern WINAPI void wine32a__splitpath(void);
__ASM_GLOBAL_FUNC(wine32a__splitpath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__splitpath") "\n"
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

static WINAPI NTSTATUS (*pNtCreateSemaphore)(PHANDLE SemaphoreHandle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, LONG InitialCount, LONG MaximumCount);
static WINAPI NTSTATUS (*pNtOpenSemaphore)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtQuerySemaphore)(HANDLE handle, SEMAPHORE_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len);
static WINAPI NTSTATUS (*pNtReleaseSemaphore)(HANDLE handle, ULONG count, PULONG previous);
static WINAPI NTSTATUS (*pNtCreateEvent)(PHANDLE EventHandle, ACCESS_MASK DesiredAccess, const OBJECT_ATTRIBUTES * attr, EVENT_TYPE type, BOOLEAN InitialState);
static WINAPI NTSTATUS (*pNtOpenEvent)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtSetEvent)(HANDLE handle, LONG * prev_state);
static WINAPI NTSTATUS (*pNtResetEvent)(HANDLE handle, LONG * prev_state);
static WINAPI NTSTATUS (*pNtClearEvent)(HANDLE handle);
static WINAPI NTSTATUS (*pNtPulseEvent)(HANDLE handle, LONG * prev_state);
static WINAPI NTSTATUS (*pNtQueryEvent)(HANDLE handle, EVENT_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len);
static WINAPI NTSTATUS (*pNtCreateMutant)(HANDLE * MutantHandle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, BOOLEAN InitialOwner);
static WINAPI NTSTATUS (*pNtOpenMutant)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtReleaseMutant)(HANDLE handle, PLONG prev_count);
static WINAPI NTSTATUS (*pNtQueryMutant)(HANDLE handle, MUTANT_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len);
static WINAPI NTSTATUS (*pNtCreateJobObject)(PHANDLE handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtOpenJobObject)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtTerminateJobObject)(HANDLE handle, NTSTATUS status);
static WINAPI NTSTATUS (*pNtQueryInformationJobObject)(HANDLE handle, JOBOBJECTINFOCLASS class, PVOID info, ULONG len, PULONG ret_len);
static WINAPI NTSTATUS (*pNtSetInformationJobObject)(HANDLE handle, JOBOBJECTINFOCLASS class, PVOID info, ULONG len);
static WINAPI NTSTATUS (*pNtIsProcessInJob)(HANDLE process, HANDLE job);
static WINAPI NTSTATUS (*pNtAssignProcessToJobObject)(HANDLE job, HANDLE process);
static WINAPI NTSTATUS (*pNtCreateTimer)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, TIMER_TYPE timer_type);
static WINAPI NTSTATUS (*pNtOpenTimer)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtSetTimer)(HANDLE handle, const LARGE_INTEGER * when, PTIMER_APC_ROUTINE callback, PVOID callback_arg, BOOLEAN resume, ULONG period, PBOOLEAN state);
static WINAPI NTSTATUS (*pNtCancelTimer)(HANDLE handle, BOOLEAN * state);
static WINAPI NTSTATUS (*pNtQueryTimer)(HANDLE TimerHandle, TIMER_INFORMATION_CLASS TimerInformationClass, PVOID TimerInformation, ULONG Length, PULONG ReturnLength);
static WINAPI NTSTATUS (*pNtQueryTimerResolution)(ULONG * min_resolution, ULONG * max_resolution, ULONG * current_resolution);
static WINAPI NTSTATUS (*pNtSetTimerResolution)(ULONG resolution, BOOLEAN set_resolution, ULONG * current_resolution);
static WINAPI NTSTATUS (*pNtWaitForMultipleObjects)(DWORD count, const HANDLE * handles, BOOLEAN wait_any, BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtWaitForSingleObject)(HANDLE handle, BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtSignalAndWaitForSingleObject)(HANDLE hSignalObject, HANDLE hWaitObject, BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtYieldExecution)(void);
static WINAPI NTSTATUS (*pNtDelayExecution)(BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtCreateKeyedEvent)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG flags);
static WINAPI NTSTATUS (*pNtOpenKeyedEvent)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtWaitForKeyedEvent)(HANDLE handle, const void * key, BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtReleaseKeyedEvent)(HANDLE handle, const void * key, BOOLEAN alertable, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pNtCreateIoCompletion)(PHANDLE CompletionPort, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES attr, ULONG NumberOfConcurrentThreads);
static WINAPI NTSTATUS (*pNtSetIoCompletion)(HANDLE CompletionPort, ULONG_PTR CompletionKey, ULONG_PTR CompletionValue, NTSTATUS Status, SIZE_T NumberOfBytesTransferred);
static WINAPI NTSTATUS (*pNtRemoveIoCompletion)(HANDLE CompletionPort, PULONG_PTR CompletionKey, PULONG_PTR CompletionValue, PIO_STATUS_BLOCK iosb, PLARGE_INTEGER WaitTime);
static WINAPI NTSTATUS (*pNtRemoveIoCompletionEx)(HANDLE port, FILE_IO_COMPLETION_INFORMATION * info, ULONG count, ULONG * written, LARGE_INTEGER * timeout, BOOLEAN alertable);
static WINAPI NTSTATUS (*pNtOpenIoCompletion)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtQueryIoCompletion)(HANDLE CompletionPort, IO_COMPLETION_INFORMATION_CLASS InformationClass, PVOID CompletionInformation, ULONG BufferLength, PULONG RequiredLength);
static WINAPI void (*pRtlRunOnceInitialize)(RTL_RUN_ONCE * once);
static WINAPI DWORD (*pRtlRunOnceBeginInitialize)(RTL_RUN_ONCE * once, ULONG flags, void ** context);
static WINAPI DWORD (*pRtlRunOnceComplete)(RTL_RUN_ONCE * once, ULONG flags, void * context);
static WINAPI DWORD (*pRtlRunOnceExecuteOnce)(RTL_RUN_ONCE * once, PRTL_RUN_ONCE_INIT_FN func, void * param, void ** context);
static WINAPI void (*pRtlInitializeSRWLock)(RTL_SRWLOCK * lock);
static WINAPI void (*pRtlAcquireSRWLockExclusive)(RTL_SRWLOCK * lock);
static WINAPI void (*pRtlAcquireSRWLockShared)(RTL_SRWLOCK * lock);
static WINAPI void (*pRtlReleaseSRWLockExclusive)(RTL_SRWLOCK * lock);
static WINAPI void (*pRtlReleaseSRWLockShared)(RTL_SRWLOCK * lock);
static WINAPI BOOLEAN (*pRtlTryAcquireSRWLockExclusive)(RTL_SRWLOCK * lock);
static WINAPI BOOLEAN (*pRtlTryAcquireSRWLockShared)(RTL_SRWLOCK * lock);
static WINAPI void (*pRtlInitializeConditionVariable)(RTL_CONDITION_VARIABLE * variable);
static WINAPI void (*pRtlWakeConditionVariable)(RTL_CONDITION_VARIABLE * variable);
static WINAPI void (*pRtlWakeAllConditionVariable)(RTL_CONDITION_VARIABLE * variable);
static WINAPI NTSTATUS (*pRtlSleepConditionVariableCS)(RTL_CONDITION_VARIABLE * variable, RTL_CRITICAL_SECTION * crit, const LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pRtlSleepConditionVariableSRW)(RTL_CONDITION_VARIABLE * variable, RTL_SRWLOCK * lock, const LARGE_INTEGER * timeout, ULONG flags);
static WINAPI NTSTATUS (*pRtlWaitOnAddress)(const void * addr, const void * cmp, SIZE_T size, const LARGE_INTEGER * timeout);
static WINAPI void (*pRtlWakeAddressAll)(const void * addr);
static WINAPI void (*pRtlWakeAddressSingle)(const void * addr);

extern WINAPI NTSTATUS wine32b_NtCreateSemaphore(PHANDLE SemaphoreHandle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, LONG InitialCount, LONG MaximumCount)
{
	TRACE("Enter NtCreateSemaphore\n");
	return pNtCreateSemaphore(SemaphoreHandle, access, attr, InitialCount, MaximumCount);
}

extern WINAPI void wine32a_NtCreateSemaphore(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateSemaphore") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenSemaphore(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenSemaphore\n");
	return pNtOpenSemaphore(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenSemaphore(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySemaphore(HANDLE handle, SEMAPHORE_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len)
{
	TRACE("Enter NtQuerySemaphore\n");
	return pNtQuerySemaphore(handle, class, info, len, ret_len);
}

extern WINAPI void wine32a_NtQuerySemaphore(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySemaphore") "\n"
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

extern WINAPI NTSTATUS wine32b_NtReleaseSemaphore(HANDLE handle, ULONG count, PULONG previous)
{
	TRACE("Enter NtReleaseSemaphore\n");
	return pNtReleaseSemaphore(handle, count, previous);
}

extern WINAPI void wine32a_NtReleaseSemaphore(void);
__ASM_GLOBAL_FUNC(wine32a_NtReleaseSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReleaseSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateEvent(PHANDLE EventHandle, ACCESS_MASK DesiredAccess, const OBJECT_ATTRIBUTES * attr, EVENT_TYPE type, BOOLEAN InitialState)
{
	TRACE("Enter NtCreateEvent\n");
	return pNtCreateEvent(EventHandle, DesiredAccess, attr, type, InitialState);
}

extern WINAPI void wine32a_NtCreateEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateEvent") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenEvent(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenEvent\n");
	return pNtOpenEvent(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetEvent(HANDLE handle, LONG * prev_state)
{
	TRACE("Enter NtSetEvent\n");
	return pNtSetEvent(handle, prev_state);
}

extern WINAPI void wine32a_NtSetEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtResetEvent(HANDLE handle, LONG * prev_state)
{
	TRACE("Enter NtResetEvent\n");
	return pNtResetEvent(handle, prev_state);
}

extern WINAPI void wine32a_NtResetEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtResetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtResetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtClearEvent(HANDLE handle)
{
	TRACE("Enter NtClearEvent\n");
	return pNtClearEvent(handle);
}

extern WINAPI void wine32a_NtClearEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtClearEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtClearEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtPulseEvent(HANDLE handle, LONG * prev_state)
{
	TRACE("Enter NtPulseEvent\n");
	return pNtPulseEvent(handle, prev_state);
}

extern WINAPI void wine32a_NtPulseEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtPulseEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtPulseEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryEvent(HANDLE handle, EVENT_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len)
{
	TRACE("Enter NtQueryEvent\n");
	return pNtQueryEvent(handle, class, info, len, ret_len);
}

extern WINAPI void wine32a_NtQueryEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryEvent") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCreateMutant(HANDLE * MutantHandle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, BOOLEAN InitialOwner)
{
	TRACE("Enter NtCreateMutant\n");
	return pNtCreateMutant(MutantHandle, access, attr, InitialOwner);
}

extern WINAPI void wine32a_NtCreateMutant(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenMutant(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenMutant\n");
	return pNtOpenMutant(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenMutant(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtReleaseMutant(HANDLE handle, PLONG prev_count)
{
	TRACE("Enter NtReleaseMutant\n");
	return pNtReleaseMutant(handle, prev_count);
}

extern WINAPI void wine32a_NtReleaseMutant(void);
__ASM_GLOBAL_FUNC(wine32a_NtReleaseMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReleaseMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryMutant(HANDLE handle, MUTANT_INFORMATION_CLASS class, void * info, ULONG len, ULONG * ret_len)
{
	TRACE("Enter NtQueryMutant\n");
	return pNtQueryMutant(handle, class, info, len, ret_len);
}

extern WINAPI void wine32a_NtQueryMutant(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryMutant") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCreateJobObject(PHANDLE handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtCreateJobObject\n");
	return pNtCreateJobObject(handle, access, attr);
}

extern WINAPI void wine32a_NtCreateJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenJobObject(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenJobObject\n");
	return pNtOpenJobObject(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtTerminateJobObject(HANDLE handle, NTSTATUS status)
{
	TRACE("Enter NtTerminateJobObject\n");
	return pNtTerminateJobObject(handle, status);
}

extern WINAPI void wine32a_NtTerminateJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtTerminateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtTerminateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryInformationJobObject(HANDLE handle, JOBOBJECTINFOCLASS class, PVOID info, ULONG len, PULONG ret_len)
{
	TRACE("Enter NtQueryInformationJobObject\n");
	return pNtQueryInformationJobObject(handle, class, info, len, ret_len);
}

extern WINAPI void wine32a_NtQueryInformationJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationJobObject") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationJobObject(HANDLE handle, JOBOBJECTINFOCLASS class, PVOID info, ULONG len)
{
	TRACE("Enter NtSetInformationJobObject\n");
	return pNtSetInformationJobObject(handle, class, info, len);
}

extern WINAPI void wine32a_NtSetInformationJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtIsProcessInJob(HANDLE process, HANDLE job)
{
	TRACE("Enter NtIsProcessInJob\n");
	return pNtIsProcessInJob(process, job);
}

extern WINAPI void wine32a_NtIsProcessInJob(void);
__ASM_GLOBAL_FUNC(wine32a_NtIsProcessInJob,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtIsProcessInJob") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAssignProcessToJobObject(HANDLE job, HANDLE process)
{
	TRACE("Enter NtAssignProcessToJobObject\n");
	return pNtAssignProcessToJobObject(job, process);
}

extern WINAPI void wine32a_NtAssignProcessToJobObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtAssignProcessToJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAssignProcessToJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateTimer(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, TIMER_TYPE timer_type)
{
	TRACE("Enter NtCreateTimer\n");
	return pNtCreateTimer(handle, access, attr, timer_type);
}

extern WINAPI void wine32a_NtCreateTimer(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenTimer(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenTimer\n");
	return pNtOpenTimer(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenTimer(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetTimer(HANDLE handle, const LARGE_INTEGER * when, PTIMER_APC_ROUTINE callback, PVOID callback_arg, BOOLEAN resume, ULONG period, PBOOLEAN state)
{
	TRACE("Enter NtSetTimer\n");
	return pNtSetTimer(handle, when, callback, callback_arg, resume, period, state);
}

extern WINAPI void wine32a_NtSetTimer(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetTimer") "\n"
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

extern WINAPI NTSTATUS wine32b_NtCancelTimer(HANDLE handle, BOOLEAN * state)
{
	TRACE("Enter NtCancelTimer\n");
	return pNtCancelTimer(handle, state);
}

extern WINAPI void wine32a_NtCancelTimer(void);
__ASM_GLOBAL_FUNC(wine32a_NtCancelTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCancelTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryTimer(HANDLE TimerHandle, TIMER_INFORMATION_CLASS TimerInformationClass, PVOID TimerInformation, ULONG Length, PULONG ReturnLength)
{
	TRACE("Enter NtQueryTimer\n");
	return pNtQueryTimer(TimerHandle, TimerInformationClass, TimerInformation, Length, ReturnLength);
}

extern WINAPI void wine32a_NtQueryTimer(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryTimer") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryTimerResolution(ULONG * min_resolution, ULONG * max_resolution, ULONG * current_resolution)
{
	TRACE("Enter NtQueryTimerResolution\n");
	return pNtQueryTimerResolution(min_resolution, max_resolution, current_resolution);
}

extern WINAPI void wine32a_NtQueryTimerResolution(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryTimerResolution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryTimerResolution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetTimerResolution(ULONG resolution, BOOLEAN set_resolution, ULONG * current_resolution)
{
	TRACE("Enter NtSetTimerResolution\n");
	return pNtSetTimerResolution(resolution, set_resolution, current_resolution);
}

extern WINAPI void wine32a_NtSetTimerResolution(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetTimerResolution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetTimerResolution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtWaitForMultipleObjects(DWORD count, const HANDLE * handles, BOOLEAN wait_any, BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtWaitForMultipleObjects\n");
	return pNtWaitForMultipleObjects(count, handles, wait_any, alertable, timeout);
}

extern WINAPI void wine32a_NtWaitForMultipleObjects(void);
__ASM_GLOBAL_FUNC(wine32a_NtWaitForMultipleObjects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWaitForMultipleObjects") "\n"
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

extern WINAPI NTSTATUS wine32b_NtWaitForSingleObject(HANDLE handle, BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtWaitForSingleObject\n");
	return pNtWaitForSingleObject(handle, alertable, timeout);
}

extern WINAPI void wine32a_NtWaitForSingleObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWaitForSingleObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSignalAndWaitForSingleObject(HANDLE hSignalObject, HANDLE hWaitObject, BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtSignalAndWaitForSingleObject\n");
	return pNtSignalAndWaitForSingleObject(hSignalObject, hWaitObject, alertable, timeout);
}

extern WINAPI void wine32a_NtSignalAndWaitForSingleObject(void);
__ASM_GLOBAL_FUNC(wine32a_NtSignalAndWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSignalAndWaitForSingleObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtYieldExecution(void)
{
	TRACE("Enter NtYieldExecution\n");
	return pNtYieldExecution();
}

extern WINAPI void wine32a_NtYieldExecution(void);
__ASM_GLOBAL_FUNC(wine32a_NtYieldExecution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtYieldExecution") "\n"
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

extern WINAPI NTSTATUS wine32b_NtDelayExecution(BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtDelayExecution\n");
	return pNtDelayExecution(alertable, timeout);
}

extern WINAPI void wine32a_NtDelayExecution(void);
__ASM_GLOBAL_FUNC(wine32a_NtDelayExecution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtDelayExecution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateKeyedEvent(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, ULONG flags)
{
	TRACE("Enter NtCreateKeyedEvent\n");
	return pNtCreateKeyedEvent(handle, access, attr, flags);
}

extern WINAPI void wine32a_NtCreateKeyedEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtOpenKeyedEvent(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenKeyedEvent\n");
	return pNtOpenKeyedEvent(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenKeyedEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtWaitForKeyedEvent(HANDLE handle, const void * key, BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtWaitForKeyedEvent\n");
	return pNtWaitForKeyedEvent(handle, key, alertable, timeout);
}

extern WINAPI void wine32a_NtWaitForKeyedEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtWaitForKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWaitForKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtReleaseKeyedEvent(HANDLE handle, const void * key, BOOLEAN alertable, const LARGE_INTEGER * timeout)
{
	TRACE("Enter NtReleaseKeyedEvent\n");
	return pNtReleaseKeyedEvent(handle, key, alertable, timeout);
}

extern WINAPI void wine32a_NtReleaseKeyedEvent(void);
__ASM_GLOBAL_FUNC(wine32a_NtReleaseKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReleaseKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateIoCompletion(PHANDLE CompletionPort, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES attr, ULONG NumberOfConcurrentThreads)
{
	TRACE("Enter NtCreateIoCompletion\n");
	return pNtCreateIoCompletion(CompletionPort, DesiredAccess, attr, NumberOfConcurrentThreads);
}

extern WINAPI void wine32a_NtCreateIoCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetIoCompletion(HANDLE CompletionPort, ULONG_PTR CompletionKey, ULONG_PTR CompletionValue, NTSTATUS Status, SIZE_T NumberOfBytesTransferred)
{
	TRACE("Enter NtSetIoCompletion\n");
	return pNtSetIoCompletion(CompletionPort, CompletionKey, CompletionValue, Status, NumberOfBytesTransferred);
}

extern WINAPI void wine32a_NtSetIoCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetIoCompletion") "\n"
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

extern WINAPI NTSTATUS wine32b_NtRemoveIoCompletion(HANDLE CompletionPort, PULONG_PTR CompletionKey, PULONG_PTR CompletionValue, PIO_STATUS_BLOCK iosb, PLARGE_INTEGER WaitTime)
{
	TRACE("Enter NtRemoveIoCompletion\n");
	return pNtRemoveIoCompletion(CompletionPort, CompletionKey, CompletionValue, iosb, WaitTime);
}

extern WINAPI void wine32a_NtRemoveIoCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_NtRemoveIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRemoveIoCompletion") "\n"
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

extern WINAPI NTSTATUS wine32b_NtRemoveIoCompletionEx(HANDLE port, FILE_IO_COMPLETION_INFORMATION * info, ULONG count, ULONG * written, LARGE_INTEGER * timeout, BOOLEAN alertable)
{
	TRACE("Enter NtRemoveIoCompletionEx\n");
	return pNtRemoveIoCompletionEx(port, info, count, written, timeout, alertable);
}

extern WINAPI void wine32a_NtRemoveIoCompletionEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtRemoveIoCompletionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtRemoveIoCompletionEx") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenIoCompletion(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenIoCompletion\n");
	return pNtOpenIoCompletion(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenIoCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueryIoCompletion(HANDLE CompletionPort, IO_COMPLETION_INFORMATION_CLASS InformationClass, PVOID CompletionInformation, ULONG BufferLength, PULONG RequiredLength)
{
	TRACE("Enter NtQueryIoCompletion\n");
	return pNtQueryIoCompletion(CompletionPort, InformationClass, CompletionInformation, BufferLength, RequiredLength);
}

extern WINAPI void wine32a_NtQueryIoCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryIoCompletion") "\n"
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

extern WINAPI void wine32b_RtlRunOnceInitialize(RTL_RUN_ONCE * once)
{
	TRACE("Enter RtlRunOnceInitialize\n");
	return pRtlRunOnceInitialize(once);
}

extern WINAPI void wine32a_RtlRunOnceInitialize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRunOnceInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRunOnceInitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlRunOnceBeginInitialize(RTL_RUN_ONCE * once, ULONG flags, void ** context)
{
	TRACE("Enter RtlRunOnceBeginInitialize\n");
	return pRtlRunOnceBeginInitialize(once, flags, context);
}

extern WINAPI void wine32a_RtlRunOnceBeginInitialize(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRunOnceBeginInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRunOnceBeginInitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlRunOnceComplete(RTL_RUN_ONCE * once, ULONG flags, void * context)
{
	TRACE("Enter RtlRunOnceComplete\n");
	return pRtlRunOnceComplete(once, flags, context);
}

extern WINAPI void wine32a_RtlRunOnceComplete(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRunOnceComplete,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRunOnceComplete") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_RtlRunOnceExecuteOnce(RTL_RUN_ONCE * once, PRTL_RUN_ONCE_INIT_FN func, void * param, void ** context)
{
	TRACE("Enter RtlRunOnceExecuteOnce\n");
	return pRtlRunOnceExecuteOnce(once, func, param, context);
}

extern WINAPI void wine32a_RtlRunOnceExecuteOnce(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRunOnceExecuteOnce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRunOnceExecuteOnce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitializeSRWLock(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlInitializeSRWLock\n");
	return pRtlInitializeSRWLock(lock);
}

extern WINAPI void wine32a_RtlInitializeSRWLock(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeSRWLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeSRWLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlAcquireSRWLockExclusive(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlAcquireSRWLockExclusive\n");
	return pRtlAcquireSRWLockExclusive(lock);
}

extern WINAPI void wine32a_RtlAcquireSRWLockExclusive(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAcquireSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAcquireSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlAcquireSRWLockShared(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlAcquireSRWLockShared\n");
	return pRtlAcquireSRWLockShared(lock);
}

extern WINAPI void wine32a_RtlAcquireSRWLockShared(void);
__ASM_GLOBAL_FUNC(wine32a_RtlAcquireSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlAcquireSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlReleaseSRWLockExclusive(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlReleaseSRWLockExclusive\n");
	return pRtlReleaseSRWLockExclusive(lock);
}

extern WINAPI void wine32a_RtlReleaseSRWLockExclusive(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleaseSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleaseSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlReleaseSRWLockShared(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlReleaseSRWLockShared\n");
	return pRtlReleaseSRWLockShared(lock);
}

extern WINAPI void wine32a_RtlReleaseSRWLockShared(void);
__ASM_GLOBAL_FUNC(wine32a_RtlReleaseSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlReleaseSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlTryAcquireSRWLockExclusive(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlTryAcquireSRWLockExclusive\n");
	return pRtlTryAcquireSRWLockExclusive(lock);
}

extern WINAPI void wine32a_RtlTryAcquireSRWLockExclusive(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTryAcquireSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTryAcquireSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlTryAcquireSRWLockShared(RTL_SRWLOCK * lock)
{
	TRACE("Enter RtlTryAcquireSRWLockShared\n");
	return pRtlTryAcquireSRWLockShared(lock);
}

extern WINAPI void wine32a_RtlTryAcquireSRWLockShared(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTryAcquireSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTryAcquireSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlInitializeConditionVariable(RTL_CONDITION_VARIABLE * variable)
{
	TRACE("Enter RtlInitializeConditionVariable\n");
	return pRtlInitializeConditionVariable(variable);
}

extern WINAPI void wine32a_RtlInitializeConditionVariable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlInitializeConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlInitializeConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlWakeConditionVariable(RTL_CONDITION_VARIABLE * variable)
{
	TRACE("Enter RtlWakeConditionVariable\n");
	return pRtlWakeConditionVariable(variable);
}

extern WINAPI void wine32a_RtlWakeConditionVariable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWakeConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWakeConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlWakeAllConditionVariable(RTL_CONDITION_VARIABLE * variable)
{
	TRACE("Enter RtlWakeAllConditionVariable\n");
	return pRtlWakeAllConditionVariable(variable);
}

extern WINAPI void wine32a_RtlWakeAllConditionVariable(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWakeAllConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWakeAllConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSleepConditionVariableCS(RTL_CONDITION_VARIABLE * variable, RTL_CRITICAL_SECTION * crit, const LARGE_INTEGER * timeout)
{
	TRACE("Enter RtlSleepConditionVariableCS\n");
	return pRtlSleepConditionVariableCS(variable, crit, timeout);
}

extern WINAPI void wine32a_RtlSleepConditionVariableCS(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSleepConditionVariableCS,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSleepConditionVariableCS") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSleepConditionVariableSRW(RTL_CONDITION_VARIABLE * variable, RTL_SRWLOCK * lock, const LARGE_INTEGER * timeout, ULONG flags)
{
	TRACE("Enter RtlSleepConditionVariableSRW\n");
	return pRtlSleepConditionVariableSRW(variable, lock, timeout, flags);
}

extern WINAPI void wine32a_RtlSleepConditionVariableSRW(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSleepConditionVariableSRW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSleepConditionVariableSRW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlWaitOnAddress(const void * addr, const void * cmp, SIZE_T size, const LARGE_INTEGER * timeout)
{
	TRACE("Enter RtlWaitOnAddress\n");
	return pRtlWaitOnAddress(addr, cmp, size, timeout);
}

extern WINAPI void wine32a_RtlWaitOnAddress(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWaitOnAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWaitOnAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlWakeAddressAll(const void * addr)
{
	TRACE("Enter RtlWakeAddressAll\n");
	return pRtlWakeAddressAll(addr);
}

extern WINAPI void wine32a_RtlWakeAddressAll(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWakeAddressAll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWakeAddressAll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlWakeAddressSingle(const void * addr)
{
	TRACE("Enter RtlWakeAddressSingle\n");
	return pRtlWakeAddressSingle(addr);
}

extern WINAPI void wine32a_RtlWakeAddressSingle(void);
__ASM_GLOBAL_FUNC(wine32a_RtlWakeAddressSingle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlWakeAddressSingle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)


static WINAPI void (*pRtlExitUserThread)(ULONG status);
static WINAPI NTSTATUS (*pNtCreateThreadEx)(HANDLE * handle_ptr, ACCESS_MASK access, OBJECT_ATTRIBUTES * attr, HANDLE process, LPTHREAD_START_ROUTINE start, void * param, ULONG flags, ULONG zero_bits, ULONG stack_commit, ULONG stack_reserve, void * attribute_list);
static WINAPI NTSTATUS (*pRtlCreateUserThread)(HANDLE process, SECURITY_DESCRIPTOR * descr, BOOLEAN suspended, PVOID stack_addr, SIZE_T stack_reserve, SIZE_T stack_commit, PRTL_THREAD_START_ROUTINE start, void * param, HANDLE * handle_ptr, CLIENT_ID * id);
static WINAPI ULONG (*pRtlGetNtGlobalFlags)(void);
static WINAPI NTSTATUS (*pNtOpenThread)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const CLIENT_ID * id);
static WINAPI NTSTATUS (*pNtSuspendThread)(HANDLE handle, PULONG count);
static WINAPI NTSTATUS (*pNtResumeThread)(HANDLE handle, PULONG count);
static WINAPI NTSTATUS (*pNtAlertResumeThread)(HANDLE handle, PULONG count);
static WINAPI NTSTATUS (*pNtAlertThread)(HANDLE handle);
static WINAPI NTSTATUS (*pNtTerminateThread)(HANDLE handle, LONG exit_code);
static WINAPI NTSTATUS (*pNtQueueApcThread)(HANDLE handle, PNTAPCFUNC func, ULONG_PTR arg1, ULONG_PTR arg2, ULONG_PTR arg3);
static WINAPI void (*pRtlPushFrame)(TEB_ACTIVE_FRAME * frame);
static WINAPI void (*pRtlPopFrame)(TEB_ACTIVE_FRAME * frame);
static WINAPI TEB_ACTIVE_FRAME * (*pRtlGetFrame)(void);
static WINAPI NTSTATUS (*pNtQueryInformationThread)(HANDLE handle, THREADINFOCLASS class, void * data, ULONG length, ULONG * ret_len);
static WINAPI NTSTATUS (*pNtSetInformationThread)(HANDLE handle, THREADINFOCLASS class, LPCVOID data, ULONG length);
static WINAPI ULONG (*pNtGetCurrentProcessorNumber)(void);

extern WINAPI void wine32b_RtlExitUserThread(ULONG status)
{
	TRACE("Enter RtlExitUserThread\n");
	return pRtlExitUserThread(status);
}

extern WINAPI void wine32a_RtlExitUserThread(void);
__ASM_GLOBAL_FUNC(wine32a_RtlExitUserThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlExitUserThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateThreadEx(HANDLE * handle_ptr, ACCESS_MASK access, OBJECT_ATTRIBUTES * attr, HANDLE process, LPTHREAD_START_ROUTINE start, void * param, ULONG flags, ULONG zero_bits, ULONG stack_commit, ULONG stack_reserve, void * attribute_list)
{
	TRACE("Enter NtCreateThreadEx\n");
	return pNtCreateThreadEx(handle_ptr, access, attr, process, start, param, flags, zero_bits, stack_commit, stack_reserve, attribute_list);
}

extern WINAPI void wine32a_NtCreateThreadEx(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateThreadEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateThreadEx") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlCreateUserThread(HANDLE process, SECURITY_DESCRIPTOR * descr, BOOLEAN suspended, PVOID stack_addr, SIZE_T stack_reserve, SIZE_T stack_commit, PRTL_THREAD_START_ROUTINE start, void * param, HANDLE * handle_ptr, CLIENT_ID * id)
{
	TRACE("Enter RtlCreateUserThread\n");
	return pRtlCreateUserThread(process, descr, suspended, stack_addr, stack_reserve, stack_commit, start, param, handle_ptr, id);
}

extern WINAPI void wine32a_RtlCreateUserThread(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateUserThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateUserThread") "\n"
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

extern WINAPI ULONG wine32b_RtlGetNtGlobalFlags(void)
{
	TRACE("Enter RtlGetNtGlobalFlags\n");
	return pRtlGetNtGlobalFlags();
}

extern WINAPI void wine32a_RtlGetNtGlobalFlags(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetNtGlobalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetNtGlobalFlags") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenThread(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const CLIENT_ID * id)
{
	TRACE("Enter NtOpenThread\n");
	return pNtOpenThread(handle, access, attr, id);
}

extern WINAPI void wine32a_NtOpenThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSuspendThread(HANDLE handle, PULONG count)
{
	TRACE("Enter NtSuspendThread\n");
	return pNtSuspendThread(handle, count);
}

extern WINAPI void wine32a_NtSuspendThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtSuspendThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSuspendThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtResumeThread(HANDLE handle, PULONG count)
{
	TRACE("Enter NtResumeThread\n");
	return pNtResumeThread(handle, count);
}

extern WINAPI void wine32a_NtResumeThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtResumeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtResumeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAlertResumeThread(HANDLE handle, PULONG count)
{
	TRACE("Enter NtAlertResumeThread\n");
	return pNtAlertResumeThread(handle, count);
}

extern WINAPI void wine32a_NtAlertResumeThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtAlertResumeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAlertResumeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAlertThread(HANDLE handle)
{
	TRACE("Enter NtAlertThread\n");
	return pNtAlertThread(handle);
}

extern WINAPI void wine32a_NtAlertThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtAlertThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAlertThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtTerminateThread(HANDLE handle, LONG exit_code)
{
	TRACE("Enter NtTerminateThread\n");
	return pNtTerminateThread(handle, exit_code);
}

extern WINAPI void wine32a_NtTerminateThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtTerminateThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtTerminateThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQueueApcThread(HANDLE handle, PNTAPCFUNC func, ULONG_PTR arg1, ULONG_PTR arg2, ULONG_PTR arg3)
{
	TRACE("Enter NtQueueApcThread\n");
	return pNtQueueApcThread(handle, func, arg1, arg2, arg3);
}

extern WINAPI void wine32a_NtQueueApcThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueueApcThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueueApcThread") "\n"
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

extern WINAPI void wine32b_RtlPushFrame(TEB_ACTIVE_FRAME * frame)
{
	TRACE("Enter RtlPushFrame\n");
	return pRtlPushFrame(frame);
}

extern WINAPI void wine32a_RtlPushFrame(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPushFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPushFrame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlPopFrame(TEB_ACTIVE_FRAME * frame)
{
	TRACE("Enter RtlPopFrame\n");
	return pRtlPopFrame(frame);
}

extern WINAPI void wine32a_RtlPopFrame(void);
__ASM_GLOBAL_FUNC(wine32a_RtlPopFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlPopFrame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TEB_ACTIVE_FRAME * wine32b_RtlGetFrame(void)
{
	TRACE("Enter RtlGetFrame\n");
	return pRtlGetFrame();
}

extern WINAPI void wine32a_RtlGetFrame(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetFrame") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryInformationThread(HANDLE handle, THREADINFOCLASS class, void * data, ULONG length, ULONG * ret_len)
{
	TRACE("Enter NtQueryInformationThread\n");
	return pNtQueryInformationThread(handle, class, data, length, ret_len);
}

extern WINAPI void wine32a_NtQueryInformationThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryInformationThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryInformationThread") "\n"
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

extern WINAPI NTSTATUS wine32b_NtSetInformationThread(HANDLE handle, THREADINFOCLASS class, LPCVOID data, ULONG length)
{
	TRACE("Enter NtSetInformationThread\n");
	return pNtSetInformationThread(handle, class, data, length);
}

extern WINAPI void wine32a_NtSetInformationThread(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetInformationThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetInformationThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_NtGetCurrentProcessorNumber(void)
{
	TRACE("Enter NtGetCurrentProcessorNumber\n");
	return pNtGetCurrentProcessorNumber();
}

extern WINAPI void wine32a_NtGetCurrentProcessorNumber(void);
__ASM_GLOBAL_FUNC(wine32a_NtGetCurrentProcessorNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtGetCurrentProcessorNumber") "\n"
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

static WINAPI NTSTATUS (*pRtlQueueWorkItem)(PRTL_WORK_ITEM_ROUTINE function, PVOID context, ULONG flags);
static WINAPI NTSTATUS (*pRtlSetIoCompletionCallback)(HANDLE FileHandle, PRTL_OVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags);
static WINAPI NTSTATUS (*pRtlRegisterWait)(PHANDLE NewWaitObject, HANDLE Object, RTL_WAITORTIMERCALLBACKFUNC Callback, PVOID Context, ULONG Milliseconds, ULONG Flags);
static WINAPI NTSTATUS (*pRtlDeregisterWaitEx)(HANDLE WaitHandle, HANDLE CompletionEvent);
static WINAPI NTSTATUS (*pRtlDeregisterWait)(HANDLE WaitHandle);
static WINAPI NTSTATUS (*pRtlCreateTimerQueue)(PHANDLE NewTimerQueue);
static WINAPI NTSTATUS (*pRtlDeleteTimerQueueEx)(HANDLE TimerQueue, HANDLE CompletionEvent);
static WINAPI NTSTATUS (*pRtlCreateTimer)(PHANDLE NewTimer, HANDLE TimerQueue, RTL_WAITORTIMERCALLBACKFUNC Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags);
static WINAPI NTSTATUS (*pRtlUpdateTimer)(HANDLE TimerQueue, HANDLE Timer, DWORD DueTime, DWORD Period);
static WINAPI NTSTATUS (*pRtlDeleteTimer)(HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent);
static WINAPI NTSTATUS (*pTpAllocCleanupGroup)(TP_CLEANUP_GROUP ** out);
static WINAPI NTSTATUS (*pTpAllocPool)(TP_POOL ** out, PVOID reserved);
static WINAPI NTSTATUS (*pTpAllocTimer)(TP_TIMER ** out, PTP_TIMER_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment);
static WINAPI NTSTATUS (*pTpAllocWait)(TP_WAIT ** out, PTP_WAIT_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment);
static WINAPI NTSTATUS (*pTpAllocWork)(TP_WORK ** out, PTP_WORK_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment);
static WINAPI void (*pTpCallbackLeaveCriticalSectionOnCompletion)(TP_CALLBACK_INSTANCE * instance, CRITICAL_SECTION * crit);
static WINAPI NTSTATUS (*pTpCallbackMayRunLong)(TP_CALLBACK_INSTANCE * instance);
static WINAPI void (*pTpCallbackReleaseMutexOnCompletion)(TP_CALLBACK_INSTANCE * instance, HANDLE mutex);
static WINAPI void (*pTpCallbackReleaseSemaphoreOnCompletion)(TP_CALLBACK_INSTANCE * instance, HANDLE semaphore, DWORD count);
static WINAPI void (*pTpCallbackSetEventOnCompletion)(TP_CALLBACK_INSTANCE * instance, HANDLE event);
static WINAPI void (*pTpCallbackUnloadDllOnCompletion)(TP_CALLBACK_INSTANCE * instance, HMODULE module);
static WINAPI void (*pTpDisassociateCallback)(TP_CALLBACK_INSTANCE * instance);
static WINAPI BOOL (*pTpIsTimerSet)(TP_TIMER * timer);
static WINAPI void (*pTpPostWork)(TP_WORK * work);
static WINAPI void (*pTpReleaseCleanupGroup)(TP_CLEANUP_GROUP * group);
static WINAPI void (*pTpReleaseCleanupGroupMembers)(TP_CLEANUP_GROUP * group, BOOL cancel_pending, PVOID userdata);
static WINAPI void (*pTpReleasePool)(TP_POOL * pool);
static WINAPI void (*pTpReleaseTimer)(TP_TIMER * timer);
static WINAPI void (*pTpReleaseWait)(TP_WAIT * wait);
static WINAPI void (*pTpReleaseWork)(TP_WORK * work);
static WINAPI void (*pTpSetPoolMaxThreads)(TP_POOL * pool, DWORD maximum);
static WINAPI BOOL (*pTpSetPoolMinThreads)(TP_POOL * pool, DWORD minimum);
static WINAPI void (*pTpSetTimer)(TP_TIMER * timer, LARGE_INTEGER * timeout, LONG period, LONG window_length);
static WINAPI void (*pTpSetWait)(TP_WAIT * wait, HANDLE handle, LARGE_INTEGER * timeout);
static WINAPI NTSTATUS (*pTpSimpleTryPost)(PTP_SIMPLE_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment);
static WINAPI void (*pTpWaitForTimer)(TP_TIMER * timer, BOOL cancel_pending);
static WINAPI void (*pTpWaitForWait)(TP_WAIT * wait, BOOL cancel_pending);
static WINAPI void (*pTpWaitForWork)(TP_WORK * work, BOOL cancel_pending);

extern WINAPI NTSTATUS wine32b_RtlQueueWorkItem(PRTL_WORK_ITEM_ROUTINE function, PVOID context, ULONG flags)
{
	TRACE("Enter RtlQueueWorkItem\n");
	return pRtlQueueWorkItem(function, context, flags);
}

extern WINAPI void wine32a_RtlQueueWorkItem(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueueWorkItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueueWorkItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetIoCompletionCallback(HANDLE FileHandle, PRTL_OVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags)
{
	TRACE("Enter RtlSetIoCompletionCallback\n");
	return pRtlSetIoCompletionCallback(FileHandle, Function, Flags);
}

extern WINAPI void wine32a_RtlSetIoCompletionCallback(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetIoCompletionCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetIoCompletionCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlRegisterWait(PHANDLE NewWaitObject, HANDLE Object, RTL_WAITORTIMERCALLBACKFUNC Callback, PVOID Context, ULONG Milliseconds, ULONG Flags)
{
	TRACE("Enter RtlRegisterWait\n");
	return pRtlRegisterWait(NewWaitObject, Object, Callback, Context, Milliseconds, Flags);
}

extern WINAPI void wine32a_RtlRegisterWait(void);
__ASM_GLOBAL_FUNC(wine32a_RtlRegisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlRegisterWait") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlDeregisterWaitEx(HANDLE WaitHandle, HANDLE CompletionEvent)
{
	TRACE("Enter RtlDeregisterWaitEx\n");
	return pRtlDeregisterWaitEx(WaitHandle, CompletionEvent);
}

extern WINAPI void wine32a_RtlDeregisterWaitEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeregisterWaitEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeregisterWaitEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDeregisterWait(HANDLE WaitHandle)
{
	TRACE("Enter RtlDeregisterWait\n");
	return pRtlDeregisterWait(WaitHandle);
}

extern WINAPI void wine32a_RtlDeregisterWait(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeregisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeregisterWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateTimerQueue(PHANDLE NewTimerQueue)
{
	TRACE("Enter RtlCreateTimerQueue\n");
	return pRtlCreateTimerQueue(NewTimerQueue);
}

extern WINAPI void wine32a_RtlCreateTimerQueue(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateTimerQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateTimerQueue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDeleteTimerQueueEx(HANDLE TimerQueue, HANDLE CompletionEvent)
{
	TRACE("Enter RtlDeleteTimerQueueEx\n");
	return pRtlDeleteTimerQueueEx(TimerQueue, CompletionEvent);
}

extern WINAPI void wine32a_RtlDeleteTimerQueueEx(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteTimerQueueEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteTimerQueueEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlCreateTimer(PHANDLE NewTimer, HANDLE TimerQueue, RTL_WAITORTIMERCALLBACKFUNC Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags)
{
	TRACE("Enter RtlCreateTimer\n");
	return pRtlCreateTimer(NewTimer, TimerQueue, Callback, Parameter, DueTime, Period, Flags);
}

extern WINAPI void wine32a_RtlCreateTimer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateTimer") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlUpdateTimer(HANDLE TimerQueue, HANDLE Timer, DWORD DueTime, DWORD Period)
{
	TRACE("Enter RtlUpdateTimer\n");
	return pRtlUpdateTimer(TimerQueue, Timer, DueTime, Period);
}

extern WINAPI void wine32a_RtlUpdateTimer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlUpdateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlUpdateTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlDeleteTimer(HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent)
{
	TRACE("Enter RtlDeleteTimer\n");
	return pRtlDeleteTimer(TimerQueue, Timer, CompletionEvent);
}

extern WINAPI void wine32a_RtlDeleteTimer(void);
__ASM_GLOBAL_FUNC(wine32a_RtlDeleteTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlDeleteTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpAllocCleanupGroup(TP_CLEANUP_GROUP ** out)
{
	TRACE("Enter TpAllocCleanupGroup\n");
	return pTpAllocCleanupGroup(out);
}

extern WINAPI void wine32a_TpAllocCleanupGroup(void);
__ASM_GLOBAL_FUNC(wine32a_TpAllocCleanupGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpAllocCleanupGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpAllocPool(TP_POOL ** out, PVOID reserved)
{
	TRACE("Enter TpAllocPool\n");
	return pTpAllocPool(out, reserved);
}

extern WINAPI void wine32a_TpAllocPool(void);
__ASM_GLOBAL_FUNC(wine32a_TpAllocPool,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpAllocPool") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpAllocTimer(TP_TIMER ** out, PTP_TIMER_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment)
{
	TRACE("Enter TpAllocTimer\n");
	return pTpAllocTimer(out, callback, userdata, environment);
}

extern WINAPI void wine32a_TpAllocTimer(void);
__ASM_GLOBAL_FUNC(wine32a_TpAllocTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpAllocTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpAllocWait(TP_WAIT ** out, PTP_WAIT_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment)
{
	TRACE("Enter TpAllocWait\n");
	return pTpAllocWait(out, callback, userdata, environment);
}

extern WINAPI void wine32a_TpAllocWait(void);
__ASM_GLOBAL_FUNC(wine32a_TpAllocWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpAllocWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpAllocWork(TP_WORK ** out, PTP_WORK_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment)
{
	TRACE("Enter TpAllocWork\n");
	return pTpAllocWork(out, callback, userdata, environment);
}

extern WINAPI void wine32a_TpAllocWork(void);
__ASM_GLOBAL_FUNC(wine32a_TpAllocWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpAllocWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpCallbackLeaveCriticalSectionOnCompletion(TP_CALLBACK_INSTANCE * instance, CRITICAL_SECTION * crit)
{
	TRACE("Enter TpCallbackLeaveCriticalSectionOnCompletion\n");
	return pTpCallbackLeaveCriticalSectionOnCompletion(instance, crit);
}

extern WINAPI void wine32a_TpCallbackLeaveCriticalSectionOnCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackLeaveCriticalSectionOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackLeaveCriticalSectionOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpCallbackMayRunLong(TP_CALLBACK_INSTANCE * instance)
{
	TRACE("Enter TpCallbackMayRunLong\n");
	return pTpCallbackMayRunLong(instance);
}

extern WINAPI void wine32a_TpCallbackMayRunLong(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackMayRunLong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackMayRunLong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpCallbackReleaseMutexOnCompletion(TP_CALLBACK_INSTANCE * instance, HANDLE mutex)
{
	TRACE("Enter TpCallbackReleaseMutexOnCompletion\n");
	return pTpCallbackReleaseMutexOnCompletion(instance, mutex);
}

extern WINAPI void wine32a_TpCallbackReleaseMutexOnCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackReleaseMutexOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackReleaseMutexOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpCallbackReleaseSemaphoreOnCompletion(TP_CALLBACK_INSTANCE * instance, HANDLE semaphore, DWORD count)
{
	TRACE("Enter TpCallbackReleaseSemaphoreOnCompletion\n");
	return pTpCallbackReleaseSemaphoreOnCompletion(instance, semaphore, count);
}

extern WINAPI void wine32a_TpCallbackReleaseSemaphoreOnCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackReleaseSemaphoreOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackReleaseSemaphoreOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpCallbackSetEventOnCompletion(TP_CALLBACK_INSTANCE * instance, HANDLE event)
{
	TRACE("Enter TpCallbackSetEventOnCompletion\n");
	return pTpCallbackSetEventOnCompletion(instance, event);
}

extern WINAPI void wine32a_TpCallbackSetEventOnCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackSetEventOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackSetEventOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpCallbackUnloadDllOnCompletion(TP_CALLBACK_INSTANCE * instance, HMODULE module)
{
	TRACE("Enter TpCallbackUnloadDllOnCompletion\n");
	return pTpCallbackUnloadDllOnCompletion(instance, module);
}

extern WINAPI void wine32a_TpCallbackUnloadDllOnCompletion(void);
__ASM_GLOBAL_FUNC(wine32a_TpCallbackUnloadDllOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpCallbackUnloadDllOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpDisassociateCallback(TP_CALLBACK_INSTANCE * instance)
{
	TRACE("Enter TpDisassociateCallback\n");
	return pTpDisassociateCallback(instance);
}

extern WINAPI void wine32a_TpDisassociateCallback(void);
__ASM_GLOBAL_FUNC(wine32a_TpDisassociateCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpDisassociateCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TpIsTimerSet(TP_TIMER * timer)
{
	TRACE("Enter TpIsTimerSet\n");
	return pTpIsTimerSet(timer);
}

extern WINAPI void wine32a_TpIsTimerSet(void);
__ASM_GLOBAL_FUNC(wine32a_TpIsTimerSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpIsTimerSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpPostWork(TP_WORK * work)
{
	TRACE("Enter TpPostWork\n");
	return pTpPostWork(work);
}

extern WINAPI void wine32a_TpPostWork(void);
__ASM_GLOBAL_FUNC(wine32a_TpPostWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpPostWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleaseCleanupGroup(TP_CLEANUP_GROUP * group)
{
	TRACE("Enter TpReleaseCleanupGroup\n");
	return pTpReleaseCleanupGroup(group);
}

extern WINAPI void wine32a_TpReleaseCleanupGroup(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleaseCleanupGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleaseCleanupGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleaseCleanupGroupMembers(TP_CLEANUP_GROUP * group, BOOL cancel_pending, PVOID userdata)
{
	TRACE("Enter TpReleaseCleanupGroupMembers\n");
	return pTpReleaseCleanupGroupMembers(group, cancel_pending, userdata);
}

extern WINAPI void wine32a_TpReleaseCleanupGroupMembers(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleaseCleanupGroupMembers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleaseCleanupGroupMembers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleasePool(TP_POOL * pool)
{
	TRACE("Enter TpReleasePool\n");
	return pTpReleasePool(pool);
}

extern WINAPI void wine32a_TpReleasePool(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleasePool,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleasePool") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleaseTimer(TP_TIMER * timer)
{
	TRACE("Enter TpReleaseTimer\n");
	return pTpReleaseTimer(timer);
}

extern WINAPI void wine32a_TpReleaseTimer(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleaseTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleaseTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleaseWait(TP_WAIT * wait)
{
	TRACE("Enter TpReleaseWait\n");
	return pTpReleaseWait(wait);
}

extern WINAPI void wine32a_TpReleaseWait(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleaseWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleaseWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpReleaseWork(TP_WORK * work)
{
	TRACE("Enter TpReleaseWork\n");
	return pTpReleaseWork(work);
}

extern WINAPI void wine32a_TpReleaseWork(void);
__ASM_GLOBAL_FUNC(wine32a_TpReleaseWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpReleaseWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpSetPoolMaxThreads(TP_POOL * pool, DWORD maximum)
{
	TRACE("Enter TpSetPoolMaxThreads\n");
	return pTpSetPoolMaxThreads(pool, maximum);
}

extern WINAPI void wine32a_TpSetPoolMaxThreads(void);
__ASM_GLOBAL_FUNC(wine32a_TpSetPoolMaxThreads,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpSetPoolMaxThreads") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_TpSetPoolMinThreads(TP_POOL * pool, DWORD minimum)
{
	TRACE("Enter TpSetPoolMinThreads\n");
	return pTpSetPoolMinThreads(pool, minimum);
}

extern WINAPI void wine32a_TpSetPoolMinThreads(void);
__ASM_GLOBAL_FUNC(wine32a_TpSetPoolMinThreads,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpSetPoolMinThreads") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpSetTimer(TP_TIMER * timer, LARGE_INTEGER * timeout, LONG period, LONG window_length)
{
	TRACE("Enter TpSetTimer\n");
	return pTpSetTimer(timer, timeout, period, window_length);
}

extern WINAPI void wine32a_TpSetTimer(void);
__ASM_GLOBAL_FUNC(wine32a_TpSetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpSetTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpSetWait(TP_WAIT * wait, HANDLE handle, LARGE_INTEGER * timeout)
{
	TRACE("Enter TpSetWait\n");
	return pTpSetWait(wait, handle, timeout);
}

extern WINAPI void wine32a_TpSetWait(void);
__ASM_GLOBAL_FUNC(wine32a_TpSetWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpSetWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_TpSimpleTryPost(PTP_SIMPLE_CALLBACK callback, PVOID userdata, TP_CALLBACK_ENVIRON * environment)
{
	TRACE("Enter TpSimpleTryPost\n");
	return pTpSimpleTryPost(callback, userdata, environment);
}

extern WINAPI void wine32a_TpSimpleTryPost(void);
__ASM_GLOBAL_FUNC(wine32a_TpSimpleTryPost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpSimpleTryPost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpWaitForTimer(TP_TIMER * timer, BOOL cancel_pending)
{
	TRACE("Enter TpWaitForTimer\n");
	return pTpWaitForTimer(timer, cancel_pending);
}

extern WINAPI void wine32a_TpWaitForTimer(void);
__ASM_GLOBAL_FUNC(wine32a_TpWaitForTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpWaitForTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpWaitForWait(TP_WAIT * wait, BOOL cancel_pending)
{
	TRACE("Enter TpWaitForWait\n");
	return pTpWaitForWait(wait, cancel_pending);
}

extern WINAPI void wine32a_TpWaitForWait(void);
__ASM_GLOBAL_FUNC(wine32a_TpWaitForWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpWaitForWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_TpWaitForWork(TP_WORK * work, BOOL cancel_pending)
{
	TRACE("Enter TpWaitForWork\n");
	return pTpWaitForWork(work, cancel_pending);
}

extern WINAPI void wine32a_TpWaitForWork(void);
__ASM_GLOBAL_FUNC(wine32a_TpWaitForWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_TpWaitForWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI void (*pRtlTimeToTimeFields)(const LARGE_INTEGER * liTime, PTIME_FIELDS TimeFields);
static WINAPI BOOLEAN (*pRtlTimeFieldsToTime)(PTIME_FIELDS tfTimeFields, PLARGE_INTEGER Time);
static WINAPI NTSTATUS (*pRtlLocalTimeToSystemTime)(const LARGE_INTEGER * LocalTime, PLARGE_INTEGER SystemTime);
static WINAPI NTSTATUS (*pRtlSystemTimeToLocalTime)(const LARGE_INTEGER * SystemTime, PLARGE_INTEGER LocalTime);
static WINAPI BOOLEAN (*pRtlTimeToSecondsSince1970)(const LARGE_INTEGER * Time, LPDWORD Seconds);
static WINAPI BOOLEAN (*pRtlTimeToSecondsSince1980)(const LARGE_INTEGER * Time, LPDWORD Seconds);
static WINAPI void (*pRtlSecondsSince1970ToTime)(DWORD Seconds, LARGE_INTEGER * Time);
static WINAPI void (*pRtlSecondsSince1980ToTime)(DWORD Seconds, LARGE_INTEGER * Time);
static WINAPI void (*pRtlTimeToElapsedTimeFields)(const LARGE_INTEGER * Time, PTIME_FIELDS TimeFields);
static WINAPI NTSTATUS (*pNtQuerySystemTime)(LARGE_INTEGER * time);
static WINAPI LONGLONG (*pRtlGetSystemTimePrecise)(void);
static WINAPI NTSTATUS (*pNtQueryPerformanceCounter)(LARGE_INTEGER * counter, LARGE_INTEGER * frequency);
static WINAPI ULONG (*pNtGetTickCount)(void);
static WINAPI NTSTATUS (*pRtlQueryTimeZoneInformation)(RTL_TIME_ZONE_INFORMATION * ret);
static WINAPI NTSTATUS (*pRtlQueryDynamicTimeZoneInformation)(RTL_DYNAMIC_TIME_ZONE_INFORMATION * tzinfo);
static WINAPI NTSTATUS (*pRtlSetTimeZoneInformation)(const RTL_TIME_ZONE_INFORMATION * tzinfo);
static WINAPI NTSTATUS (*pNtSetSystemTime)(const LARGE_INTEGER * NewTime, LARGE_INTEGER * OldTime);
static WINAPI NTSTATUS (*pRtlQueryUnbiasedInterruptTime)(ULONGLONG * time);

extern WINAPI void wine32b_RtlTimeToTimeFields(const LARGE_INTEGER * liTime, PTIME_FIELDS TimeFields)
{
	TRACE("Enter RtlTimeToTimeFields\n");
	return pRtlTimeToTimeFields(liTime, TimeFields);
}

extern WINAPI void wine32a_RtlTimeToTimeFields(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTimeToTimeFields,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTimeToTimeFields") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlTimeFieldsToTime(PTIME_FIELDS tfTimeFields, PLARGE_INTEGER Time)
{
	TRACE("Enter RtlTimeFieldsToTime\n");
	return pRtlTimeFieldsToTime(tfTimeFields, Time);
}

extern WINAPI void wine32a_RtlTimeFieldsToTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTimeFieldsToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTimeFieldsToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlLocalTimeToSystemTime(const LARGE_INTEGER * LocalTime, PLARGE_INTEGER SystemTime)
{
	TRACE("Enter RtlLocalTimeToSystemTime\n");
	return pRtlLocalTimeToSystemTime(LocalTime, SystemTime);
}

extern WINAPI void wine32a_RtlLocalTimeToSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlLocalTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlLocalTimeToSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSystemTimeToLocalTime(const LARGE_INTEGER * SystemTime, PLARGE_INTEGER LocalTime)
{
	TRACE("Enter RtlSystemTimeToLocalTime\n");
	return pRtlSystemTimeToLocalTime(SystemTime, LocalTime);
}

extern WINAPI void wine32a_RtlSystemTimeToLocalTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSystemTimeToLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSystemTimeToLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlTimeToSecondsSince1970(const LARGE_INTEGER * Time, LPDWORD Seconds)
{
	TRACE("Enter RtlTimeToSecondsSince1970\n");
	return pRtlTimeToSecondsSince1970(Time, Seconds);
}

extern WINAPI void wine32a_RtlTimeToSecondsSince1970(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTimeToSecondsSince1970,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTimeToSecondsSince1970") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlTimeToSecondsSince1980(const LARGE_INTEGER * Time, LPDWORD Seconds)
{
	TRACE("Enter RtlTimeToSecondsSince1980\n");
	return pRtlTimeToSecondsSince1980(Time, Seconds);
}

extern WINAPI void wine32a_RtlTimeToSecondsSince1980(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTimeToSecondsSince1980,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTimeToSecondsSince1980") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSecondsSince1970ToTime(DWORD Seconds, LARGE_INTEGER * Time)
{
	TRACE("Enter RtlSecondsSince1970ToTime\n");
	return pRtlSecondsSince1970ToTime(Seconds, Time);
}

extern WINAPI void wine32a_RtlSecondsSince1970ToTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSecondsSince1970ToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSecondsSince1970ToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlSecondsSince1980ToTime(DWORD Seconds, LARGE_INTEGER * Time)
{
	TRACE("Enter RtlSecondsSince1980ToTime\n");
	return pRtlSecondsSince1980ToTime(Seconds, Time);
}

extern WINAPI void wine32a_RtlSecondsSince1980ToTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSecondsSince1980ToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSecondsSince1980ToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlTimeToElapsedTimeFields(const LARGE_INTEGER * Time, PTIME_FIELDS TimeFields)
{
	TRACE("Enter RtlTimeToElapsedTimeFields\n");
	return pRtlTimeToElapsedTimeFields(Time, TimeFields);
}

extern WINAPI void wine32a_RtlTimeToElapsedTimeFields(void);
__ASM_GLOBAL_FUNC(wine32a_RtlTimeToElapsedTimeFields,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlTimeToElapsedTimeFields") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySystemTime(LARGE_INTEGER * time)
{
	TRACE("Enter NtQuerySystemTime\n");
	return pNtQuerySystemTime(time);
}

extern WINAPI void wine32a_NtQuerySystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONGLONG wine32b_RtlGetSystemTimePrecise(void)
{
	TRACE("Enter RtlGetSystemTimePrecise\n");
	return pRtlGetSystemTimePrecise();
}

extern WINAPI void wine32a_RtlGetSystemTimePrecise(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetSystemTimePrecise,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetSystemTimePrecise") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryPerformanceCounter(LARGE_INTEGER * counter, LARGE_INTEGER * frequency)
{
	TRACE("Enter NtQueryPerformanceCounter\n");
	return pNtQueryPerformanceCounter(counter, frequency);
}

extern WINAPI void wine32a_NtQueryPerformanceCounter(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryPerformanceCounter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryPerformanceCounter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_NtGetTickCount(void)
{
	TRACE("Enter NtGetTickCount\n");
	return pNtGetTickCount();
}

extern WINAPI void wine32a_NtGetTickCount(void);
__ASM_GLOBAL_FUNC(wine32a_NtGetTickCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtGetTickCount") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlQueryTimeZoneInformation(RTL_TIME_ZONE_INFORMATION * ret)
{
	TRACE("Enter RtlQueryTimeZoneInformation\n");
	return pRtlQueryTimeZoneInformation(ret);
}

extern WINAPI void wine32a_RtlQueryTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryDynamicTimeZoneInformation(RTL_DYNAMIC_TIME_ZONE_INFORMATION * tzinfo)
{
	TRACE("Enter RtlQueryDynamicTimeZoneInformation\n");
	return pRtlQueryDynamicTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_RtlQueryDynamicTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryDynamicTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryDynamicTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlSetTimeZoneInformation(const RTL_TIME_ZONE_INFORMATION * tzinfo)
{
	TRACE("Enter RtlSetTimeZoneInformation\n");
	return pRtlSetTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_RtlSetTimeZoneInformation(void);
__ASM_GLOBAL_FUNC(wine32a_RtlSetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlSetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtSetSystemTime(const LARGE_INTEGER * NewTime, LARGE_INTEGER * OldTime)
{
	TRACE("Enter NtSetSystemTime\n");
	return pNtSetSystemTime(NewTime, OldTime);
}

extern WINAPI void wine32a_NtSetSystemTime(void);
__ASM_GLOBAL_FUNC(wine32a_NtSetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtSetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlQueryUnbiasedInterruptTime(ULONGLONG * time)
{
	TRACE("Enter RtlQueryUnbiasedInterruptTime\n");
	return pRtlQueryUnbiasedInterruptTime(time);
}

extern WINAPI void wine32a_RtlQueryUnbiasedInterruptTime(void);
__ASM_GLOBAL_FUNC(wine32a_RtlQueryUnbiasedInterruptTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlQueryUnbiasedInterruptTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI BOOLEAN (*pRtlGetProductInfo)(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
static WINAPI NTSTATUS (*pRtlGetVersion)(RTL_OSVERSIONINFOEXW * info);
static WINAPI void (*pRtlGetNtVersionNumbers)(LPDWORD major, LPDWORD minor, LPDWORD build);
static WINAPI BOOLEAN (*pRtlGetNtProductType)(LPDWORD type);
static WINAPI NTSTATUS (*pRtlVerifyVersionInfo)(const RTL_OSVERSIONINFOEXW * info, DWORD dwTypeMask, DWORDLONG dwlConditionMask);

extern WINAPI BOOLEAN wine32b_RtlGetProductInfo(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType)
{
	TRACE("Enter RtlGetProductInfo\n");
	return pRtlGetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
}

extern WINAPI void wine32a_RtlGetProductInfo(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetProductInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetProductInfo") "\n"
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

extern WINAPI NTSTATUS wine32b_RtlGetVersion(RTL_OSVERSIONINFOEXW * info)
{
	TRACE("Enter RtlGetVersion\n");
	return pRtlGetVersion(info);
}

extern WINAPI void wine32a_RtlGetVersion(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetVersion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetVersion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_RtlGetNtVersionNumbers(LPDWORD major, LPDWORD minor, LPDWORD build)
{
	TRACE("Enter RtlGetNtVersionNumbers\n");
	return pRtlGetNtVersionNumbers(major, minor, build);
}

extern WINAPI void wine32a_RtlGetNtVersionNumbers(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetNtVersionNumbers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetNtVersionNumbers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_RtlGetNtProductType(LPDWORD type)
{
	TRACE("Enter RtlGetNtProductType\n");
	return pRtlGetNtProductType(type);
}

extern WINAPI void wine32a_RtlGetNtProductType(void);
__ASM_GLOBAL_FUNC(wine32a_RtlGetNtProductType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlGetNtProductType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_RtlVerifyVersionInfo(const RTL_OSVERSIONINFOEXW * info, DWORD dwTypeMask, DWORDLONG dwlConditionMask)
{
	TRACE("Enter RtlVerifyVersionInfo\n");
	return pRtlVerifyVersionInfo(info, dwTypeMask, dwlConditionMask);
}

extern WINAPI void wine32a_RtlVerifyVersionInfo(void);
__ASM_GLOBAL_FUNC(wine32a_RtlVerifyVersionInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlVerifyVersionInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI NTSTATUS (*pRtlCreateUserStack)(SIZE_T commit, SIZE_T reserve, ULONG zero_bits, SIZE_T commit_align, SIZE_T reserve_align, INITIAL_TEB * stack);
static WINAPI void (*pRtlFreeUserStack)(void * stack);
static WINAPI ssize_t (*p__wine_locked_recvmsg)(int fd, struct msghdr * hdr, int flags);
static WINAPI NTSTATUS (*pNtAllocateVirtualMemory)(HANDLE process, PVOID * ret, ULONG_PTR zero_bits, SIZE_T * size_ptr, ULONG type, ULONG protect);
static WINAPI NTSTATUS (*pNtFreeVirtualMemory)(HANDLE process, PVOID * addr_ptr, SIZE_T * size_ptr, ULONG type);
static WINAPI NTSTATUS (*pNtProtectVirtualMemory)(HANDLE process, PVOID * addr_ptr, SIZE_T * size_ptr, ULONG new_prot, ULONG * old_prot);
static WINAPI NTSTATUS (*pNtQueryVirtualMemory)(HANDLE process, LPCVOID addr, MEMORY_INFORMATION_CLASS info_class, PVOID buffer, SIZE_T len, SIZE_T * res_len);
static WINAPI NTSTATUS (*pNtLockVirtualMemory)(HANDLE process, PVOID * addr, SIZE_T * size, ULONG unknown);
static WINAPI NTSTATUS (*pNtUnlockVirtualMemory)(HANDLE process, PVOID * addr, SIZE_T * size, ULONG unknown);
static WINAPI NTSTATUS (*pNtCreateSection)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const LARGE_INTEGER * size, ULONG protect, ULONG sec_flags, HANDLE file);
static WINAPI NTSTATUS (*pNtOpenSection)(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr);
static WINAPI NTSTATUS (*pNtMapViewOfSection)(HANDLE handle, HANDLE process, PVOID * addr_ptr, ULONG_PTR zero_bits, SIZE_T commit_size, const LARGE_INTEGER * offset_ptr, SIZE_T * size_ptr, SECTION_INHERIT inherit, ULONG alloc_type, ULONG protect);
static WINAPI NTSTATUS (*pNtUnmapViewOfSection)(HANDLE process, PVOID addr);
static WINAPI NTSTATUS (*pNtQuerySection)(HANDLE handle, SECTION_INFORMATION_CLASS class, void * ptr, SIZE_T size, SIZE_T * ret_size);
static WINAPI NTSTATUS (*pNtFlushVirtualMemory)(HANDLE process, LPCVOID * addr_ptr, SIZE_T * size_ptr, ULONG unknown);
static WINAPI NTSTATUS (*pNtGetWriteWatch)(HANDLE process, ULONG flags, PVOID base, SIZE_T size, PVOID * addresses, ULONG_PTR * count, ULONG * granularity);
static WINAPI NTSTATUS (*pNtResetWriteWatch)(HANDLE process, PVOID base, SIZE_T size);
static WINAPI NTSTATUS (*pNtReadVirtualMemory)(HANDLE process, const void * addr, void * buffer, SIZE_T size, SIZE_T * bytes_read);
static WINAPI NTSTATUS (*pNtWriteVirtualMemory)(HANDLE process, void * addr, const void * buffer, SIZE_T size, SIZE_T * bytes_written);
static WINAPI NTSTATUS (*pNtAreMappedFilesTheSame)(PVOID addr1, PVOID addr2);

extern WINAPI NTSTATUS wine32b_RtlCreateUserStack(SIZE_T commit, SIZE_T reserve, ULONG zero_bits, SIZE_T commit_align, SIZE_T reserve_align, INITIAL_TEB * stack)
{
	TRACE("Enter RtlCreateUserStack\n");
	return pRtlCreateUserStack(commit, reserve, zero_bits, commit_align, reserve_align, stack);
}

extern WINAPI void wine32a_RtlCreateUserStack(void);
__ASM_GLOBAL_FUNC(wine32a_RtlCreateUserStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlCreateUserStack") "\n"
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

extern WINAPI void wine32b_RtlFreeUserStack(void * stack)
{
	TRACE("Enter RtlFreeUserStack\n");
	return pRtlFreeUserStack(stack);
}

extern WINAPI void wine32a_RtlFreeUserStack(void);
__ASM_GLOBAL_FUNC(wine32a_RtlFreeUserStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_RtlFreeUserStack") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ssize_t wine32b___wine_locked_recvmsg(int fd, struct msghdr * hdr, int flags)
{
	TRACE("Enter __wine_locked_recvmsg\n");
	return p__wine_locked_recvmsg(fd, hdr, flags);
}

extern WINAPI void wine32a___wine_locked_recvmsg(void);
__ASM_GLOBAL_FUNC(wine32a___wine_locked_recvmsg,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b___wine_locked_recvmsg") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtAllocateVirtualMemory(HANDLE process, PVOID * ret, ULONG_PTR zero_bits, SIZE_T * size_ptr, ULONG type, ULONG protect)
{
	TRACE("Enter NtAllocateVirtualMemory\n");
	return pNtAllocateVirtualMemory(process, ret, zero_bits, size_ptr, type, protect);
}

extern WINAPI void wine32a_NtAllocateVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtAllocateVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAllocateVirtualMemory") "\n"
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

extern WINAPI NTSTATUS wine32b_NtFreeVirtualMemory(HANDLE process, PVOID * addr_ptr, SIZE_T * size_ptr, ULONG type)
{
	TRACE("Enter NtFreeVirtualMemory\n");
	return pNtFreeVirtualMemory(process, addr_ptr, size_ptr, type);
}

extern WINAPI void wine32a_NtFreeVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtFreeVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFreeVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtProtectVirtualMemory(HANDLE process, PVOID * addr_ptr, SIZE_T * size_ptr, ULONG new_prot, ULONG * old_prot)
{
	TRACE("Enter NtProtectVirtualMemory\n");
	return pNtProtectVirtualMemory(process, addr_ptr, size_ptr, new_prot, old_prot);
}

extern WINAPI void wine32a_NtProtectVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtProtectVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtProtectVirtualMemory") "\n"
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

extern WINAPI NTSTATUS wine32b_NtQueryVirtualMemory(HANDLE process, LPCVOID addr, MEMORY_INFORMATION_CLASS info_class, PVOID buffer, SIZE_T len, SIZE_T * res_len)
{
	TRACE("Enter NtQueryVirtualMemory\n");
	return pNtQueryVirtualMemory(process, addr, info_class, buffer, len, res_len);
}

extern WINAPI void wine32a_NtQueryVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtQueryVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQueryVirtualMemory") "\n"
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

extern WINAPI NTSTATUS wine32b_NtLockVirtualMemory(HANDLE process, PVOID * addr, SIZE_T * size, ULONG unknown)
{
	TRACE("Enter NtLockVirtualMemory\n");
	return pNtLockVirtualMemory(process, addr, size, unknown);
}

extern WINAPI void wine32a_NtLockVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtLockVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtLockVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtUnlockVirtualMemory(HANDLE process, PVOID * addr, SIZE_T * size, ULONG unknown)
{
	TRACE("Enter NtUnlockVirtualMemory\n");
	return pNtUnlockVirtualMemory(process, addr, size, unknown);
}

extern WINAPI void wine32a_NtUnlockVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtUnlockVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtUnlockVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtCreateSection(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr, const LARGE_INTEGER * size, ULONG protect, ULONG sec_flags, HANDLE file)
{
	TRACE("Enter NtCreateSection\n");
	return pNtCreateSection(handle, access, attr, size, protect, sec_flags, file);
}

extern WINAPI void wine32a_NtCreateSection(void);
__ASM_GLOBAL_FUNC(wine32a_NtCreateSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtCreateSection") "\n"
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

extern WINAPI NTSTATUS wine32b_NtOpenSection(HANDLE * handle, ACCESS_MASK access, const OBJECT_ATTRIBUTES * attr)
{
	TRACE("Enter NtOpenSection\n");
	return pNtOpenSection(handle, access, attr);
}

extern WINAPI void wine32a_NtOpenSection(void);
__ASM_GLOBAL_FUNC(wine32a_NtOpenSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtOpenSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtMapViewOfSection(HANDLE handle, HANDLE process, PVOID * addr_ptr, ULONG_PTR zero_bits, SIZE_T commit_size, const LARGE_INTEGER * offset_ptr, SIZE_T * size_ptr, SECTION_INHERIT inherit, ULONG alloc_type, ULONG protect)
{
	TRACE("Enter NtMapViewOfSection\n");
	return pNtMapViewOfSection(handle, process, addr_ptr, zero_bits, commit_size, offset_ptr, size_ptr, inherit, alloc_type, protect);
}

extern WINAPI void wine32a_NtMapViewOfSection(void);
__ASM_GLOBAL_FUNC(wine32a_NtMapViewOfSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtMapViewOfSection") "\n"
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

extern WINAPI NTSTATUS wine32b_NtUnmapViewOfSection(HANDLE process, PVOID addr)
{
	TRACE("Enter NtUnmapViewOfSection\n");
	return pNtUnmapViewOfSection(process, addr);
}

extern WINAPI void wine32a_NtUnmapViewOfSection(void);
__ASM_GLOBAL_FUNC(wine32a_NtUnmapViewOfSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtUnmapViewOfSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtQuerySection(HANDLE handle, SECTION_INFORMATION_CLASS class, void * ptr, SIZE_T size, SIZE_T * ret_size)
{
	TRACE("Enter NtQuerySection\n");
	return pNtQuerySection(handle, class, ptr, size, ret_size);
}

extern WINAPI void wine32a_NtQuerySection(void);
__ASM_GLOBAL_FUNC(wine32a_NtQuerySection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtQuerySection") "\n"
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

extern WINAPI NTSTATUS wine32b_NtFlushVirtualMemory(HANDLE process, LPCVOID * addr_ptr, SIZE_T * size_ptr, ULONG unknown)
{
	TRACE("Enter NtFlushVirtualMemory\n");
	return pNtFlushVirtualMemory(process, addr_ptr, size_ptr, unknown);
}

extern WINAPI void wine32a_NtFlushVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtFlushVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtFlushVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtGetWriteWatch(HANDLE process, ULONG flags, PVOID base, SIZE_T size, PVOID * addresses, ULONG_PTR * count, ULONG * granularity)
{
	TRACE("Enter NtGetWriteWatch\n");
	return pNtGetWriteWatch(process, flags, base, size, addresses, count, granularity);
}

extern WINAPI void wine32a_NtGetWriteWatch(void);
__ASM_GLOBAL_FUNC(wine32a_NtGetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtGetWriteWatch") "\n"
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

extern WINAPI NTSTATUS wine32b_NtResetWriteWatch(HANDLE process, PVOID base, SIZE_T size)
{
	TRACE("Enter NtResetWriteWatch\n");
	return pNtResetWriteWatch(process, base, size);
}

extern WINAPI void wine32a_NtResetWriteWatch(void);
__ASM_GLOBAL_FUNC(wine32a_NtResetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtResetWriteWatch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_NtReadVirtualMemory(HANDLE process, const void * addr, void * buffer, SIZE_T size, SIZE_T * bytes_read)
{
	TRACE("Enter NtReadVirtualMemory\n");
	return pNtReadVirtualMemory(process, addr, buffer, size, bytes_read);
}

extern WINAPI void wine32a_NtReadVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtReadVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtReadVirtualMemory") "\n"
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

extern WINAPI NTSTATUS wine32b_NtWriteVirtualMemory(HANDLE process, void * addr, const void * buffer, SIZE_T size, SIZE_T * bytes_written)
{
	TRACE("Enter NtWriteVirtualMemory\n");
	return pNtWriteVirtualMemory(process, addr, buffer, size, bytes_written);
}

extern WINAPI void wine32a_NtWriteVirtualMemory(void);
__ASM_GLOBAL_FUNC(wine32a_NtWriteVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtWriteVirtualMemory") "\n"
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

extern WINAPI NTSTATUS wine32b_NtAreMappedFilesTheSame(PVOID addr1, PVOID addr2)
{
	TRACE("Enter NtAreMappedFilesTheSame\n");
	return pNtAreMappedFilesTheSame(addr1, addr2);
}

extern WINAPI void wine32a_NtAreMappedFilesTheSame(void);
__ASM_GLOBAL_FUNC(wine32a_NtAreMappedFilesTheSame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_NtAreMappedFilesTheSame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static WINAPI LPWSTR (*p_ultow)(ULONG value, LPWSTR str, INT radix);
static WINAPI LPWSTR (*p_ltow)(LONG value, LPWSTR str, INT radix);
static WINAPI LPWSTR (*p_itow)(int value, LPWSTR str, INT radix);
static WINAPI LPWSTR (*p_ui64tow)(ULONGLONG value, LPWSTR str, INT radix);
static WINAPI LPWSTR (*p_i64tow)(LONGLONG value, LPWSTR str, INT radix);
static WINAPI LONG (*p_wtol)(LPCWSTR str);
static WINAPI int (*p_wtoi)(LPCWSTR str);
static WINAPI LONGLONG (*p_wtoi64)(LPCWSTR str);

extern WINAPI LPWSTR wine32b__ultow(ULONG value, LPWSTR str, INT radix)
{
	TRACE("Enter _ultow\n");
	return p_ultow(value, str, radix);
}

extern WINAPI void wine32a__ultow(void);
__ASM_GLOBAL_FUNC(wine32a__ultow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ultow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b__ltow(LONG value, LPWSTR str, INT radix)
{
	TRACE("Enter _ltow\n");
	return p_ltow(value, str, radix);
}

extern WINAPI void wine32a__ltow(void);
__ASM_GLOBAL_FUNC(wine32a__ltow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ltow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b__itow(int value, LPWSTR str, INT radix)
{
	TRACE("Enter _itow\n");
	return p_itow(value, str, radix);
}

extern WINAPI void wine32a__itow(void);
__ASM_GLOBAL_FUNC(wine32a__itow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__itow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b__ui64tow(ULONGLONG value, LPWSTR str, INT radix)
{
	TRACE("Enter _ui64tow\n");
	return p_ui64tow(value, str, radix);
}

extern WINAPI void wine32a__ui64tow(void);
__ASM_GLOBAL_FUNC(wine32a__ui64tow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__ui64tow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b__i64tow(LONGLONG value, LPWSTR str, INT radix)
{
	TRACE("Enter _i64tow\n");
	return p_i64tow(value, str, radix);
}

extern WINAPI void wine32a__i64tow(void);
__ASM_GLOBAL_FUNC(wine32a__i64tow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__i64tow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b__wtol(LPCWSTR str)
{
	TRACE("Enter _wtol\n");
	return p_wtol(str);
}

extern WINAPI void wine32a__wtol(void);
__ASM_GLOBAL_FUNC(wine32a__wtol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wtol") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b__wtoi(LPCWSTR str)
{
	TRACE("Enter _wtoi\n");
	return p_wtoi(str);
}

extern WINAPI void wine32a__wtoi(void);
__ASM_GLOBAL_FUNC(wine32a__wtoi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wtoi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONGLONG wine32b__wtoi64(LPCWSTR str)
{
	TRACE("Enter _wtoi64\n");
	return p_wtoi64(str);
}

extern WINAPI void wine32a__wtoi64(void);
__ASM_GLOBAL_FUNC(wine32a__wtoi64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b__wtoi64") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
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

void wine_thunk_initialize_ntdll(void)
{
	HMODULE library = LoadLibraryA("ntdll.dll");
	pRtlCreateActivationContext = (void *)GetProcAddress(library, "RtlCreateActivationContext");
	pRtlAddRefActivationContext = (void *)GetProcAddress(library, "RtlAddRefActivationContext");
	pRtlReleaseActivationContext = (void *)GetProcAddress(library, "RtlReleaseActivationContext");
	pRtlZombifyActivationContext = (void *)GetProcAddress(library, "RtlZombifyActivationContext");
	pRtlActivateActivationContext = (void *)GetProcAddress(library, "RtlActivateActivationContext");
	pRtlDeactivateActivationContext = (void *)GetProcAddress(library, "RtlDeactivateActivationContext");
	pRtlFreeThreadActivationContextStack = (void *)GetProcAddress(library, "RtlFreeThreadActivationContextStack");
	pRtlGetActiveActivationContext = (void *)GetProcAddress(library, "RtlGetActiveActivationContext");
	pRtlIsActivationContextActive = (void *)GetProcAddress(library, "RtlIsActivationContextActive");
	pRtlQueryInformationActivationContext = (void *)GetProcAddress(library, "RtlQueryInformationActivationContext");
	pRtlFindActivationContextSectionString = (void *)GetProcAddress(library, "RtlFindActivationContextSectionString");
	pRtlFindActivationContextSectionGuid = (void *)GetProcAddress(library, "RtlFindActivationContextSectionGuid");
	pRtlQueryActivationContextApplicationSettings = (void *)GetProcAddress(library, "RtlQueryActivationContextApplicationSettings");
	pRtlDeleteAtomFromAtomTable = (void *)GetProcAddress(library, "RtlDeleteAtomFromAtomTable");
	pRtlQueryAtomInAtomTable = (void *)GetProcAddress(library, "RtlQueryAtomInAtomTable");
	pRtlCreateAtomTable = (void *)GetProcAddress(library, "RtlCreateAtomTable");
	pRtlDestroyAtomTable = (void *)GetProcAddress(library, "RtlDestroyAtomTable");
	pRtlAddAtomToAtomTable = (void *)GetProcAddress(library, "RtlAddAtomToAtomTable");
	pRtlLookupAtomInAtomTable = (void *)GetProcAddress(library, "RtlLookupAtomInAtomTable");
	pRtlEmptyAtomTable = (void *)GetProcAddress(library, "RtlEmptyAtomTable");
	pRtlPinAtomInAtomTable = (void *)GetProcAddress(library, "RtlPinAtomInAtomTable");
	pNtAddAtom = (void *)GetProcAddress(library, "NtAddAtom");
	pNtDeleteAtom = (void *)GetProcAddress(library, "NtDeleteAtom");
	pNtFindAtom = (void *)GetProcAddress(library, "NtFindAtom");
	pNtQueryInformationAtom = (void *)GetProcAddress(library, "NtQueryInformationAtom");
	pRtlInitializeCriticalSection = (void *)GetProcAddress(library, "RtlInitializeCriticalSection");
	pRtlInitializeCriticalSectionAndSpinCount = (void *)GetProcAddress(library, "RtlInitializeCriticalSectionAndSpinCount");
	pRtlInitializeCriticalSectionEx = (void *)GetProcAddress(library, "RtlInitializeCriticalSectionEx");
	pRtlSetCriticalSectionSpinCount = (void *)GetProcAddress(library, "RtlSetCriticalSectionSpinCount");
	pRtlDeleteCriticalSection = (void *)GetProcAddress(library, "RtlDeleteCriticalSection");
	pRtlpWaitForCriticalSection = (void *)GetProcAddress(library, "RtlpWaitForCriticalSection");
	pRtlpUnWaitCriticalSection = (void *)GetProcAddress(library, "RtlpUnWaitCriticalSection");
	pRtlEnterCriticalSection = (void *)GetProcAddress(library, "RtlEnterCriticalSection");
	pRtlTryEnterCriticalSection = (void *)GetProcAddress(library, "RtlTryEnterCriticalSection");
	pRtlIsCriticalSectionLocked = (void *)GetProcAddress(library, "RtlIsCriticalSectionLocked");
	pRtlIsCriticalSectionLockedByThread = (void *)GetProcAddress(library, "RtlIsCriticalSectionLockedByThread");
	pRtlLeaveCriticalSection = (void *)GetProcAddress(library, "RtlLeaveCriticalSection");
	pA_SHAInit = (void *)GetProcAddress(library, "A_SHAInit");
	pA_SHAUpdate = (void *)GetProcAddress(library, "A_SHAUpdate");
	pA_SHAFinal = (void *)GetProcAddress(library, "A_SHAFinal");
	pMD4Init = (void *)GetProcAddress(library, "MD4Init");
	pMD4Update = (void *)GetProcAddress(library, "MD4Update");
	pMD4Final = (void *)GetProcAddress(library, "MD4Final");
	pMD5Init = (void *)GetProcAddress(library, "MD5Init");
	pMD5Update = (void *)GetProcAddress(library, "MD5Update");
	pMD5Final = (void *)GetProcAddress(library, "MD5Final");
	pRtlCreateQueryDebugBuffer = (void *)GetProcAddress(library, "RtlCreateQueryDebugBuffer");
	pRtlDestroyQueryDebugBuffer = (void *)GetProcAddress(library, "RtlDestroyQueryDebugBuffer");
	pRtlQueryProcessDebugInformation = (void *)GetProcAddress(library, "RtlQueryProcessDebugInformation");
	p__wine_dbg_get_channel_flags = (void *)GetProcAddress(library, "__wine_dbg_get_channel_flags");
	p__wine_dbg_strdup = (void *)GetProcAddress(library, "__wine_dbg_strdup");
	p__wine_dbg_output = (void *)GetProcAddress(library, "__wine_dbg_output");
	p__wine_dbg_header = (void *)GetProcAddress(library, "__wine_dbg_header");
	pNtQueryDirectoryFile = (void *)GetProcAddress(library, "NtQueryDirectoryFile");
	pwine_nt_to_unix_file_name = (void *)GetProcAddress(library, "wine_nt_to_unix_file_name");
	pRtlWow64EnableFsRedirection = (void *)GetProcAddress(library, "RtlWow64EnableFsRedirection");
	pRtlWow64EnableFsRedirectionEx = (void *)GetProcAddress(library, "RtlWow64EnableFsRedirectionEx");
	pRtlDoesFileExists_U = (void *)GetProcAddress(library, "RtlDoesFileExists_U");
	pNtQuerySystemEnvironmentValue = (void *)GetProcAddress(library, "NtQuerySystemEnvironmentValue");
	pNtQuerySystemEnvironmentValueEx = (void *)GetProcAddress(library, "NtQuerySystemEnvironmentValueEx");
	pRtlCreateEnvironment = (void *)GetProcAddress(library, "RtlCreateEnvironment");
	pRtlDestroyEnvironment = (void *)GetProcAddress(library, "RtlDestroyEnvironment");
	pRtlQueryEnvironmentVariable_U = (void *)GetProcAddress(library, "RtlQueryEnvironmentVariable_U");
	pRtlSetCurrentEnvironment = (void *)GetProcAddress(library, "RtlSetCurrentEnvironment");
	pRtlSetEnvironmentVariable = (void *)GetProcAddress(library, "RtlSetEnvironmentVariable");
	pRtlExpandEnvironmentStrings = (void *)GetProcAddress(library, "RtlExpandEnvironmentStrings");
	pRtlExpandEnvironmentStrings_U = (void *)GetProcAddress(library, "RtlExpandEnvironmentStrings_U");
	pRtlNormalizeProcessParams = (void *)GetProcAddress(library, "RtlNormalizeProcessParams");
	pRtlDeNormalizeProcessParams = (void *)GetProcAddress(library, "RtlDeNormalizeProcessParams");
	pRtlCreateProcessParametersEx = (void *)GetProcAddress(library, "RtlCreateProcessParametersEx");
	pRtlCreateProcessParameters = (void *)GetProcAddress(library, "RtlCreateProcessParameters");
	pRtlDestroyProcessParameters = (void *)GetProcAddress(library, "RtlDestroyProcessParameters");
	pRtlNtStatusToDosErrorNoTeb = (void *)GetProcAddress(library, "RtlNtStatusToDosErrorNoTeb");
	pRtlNtStatusToDosError = (void *)GetProcAddress(library, "RtlNtStatusToDosError");
	pRtlGetLastNtStatus = (void *)GetProcAddress(library, "RtlGetLastNtStatus");
	pRtlGetLastWin32Error = (void *)GetProcAddress(library, "RtlGetLastWin32Error");
	pNtRaiseHardError = (void *)GetProcAddress(library, "NtRaiseHardError");
	pRtlSetLastWin32Error = (void *)GetProcAddress(library, "RtlSetLastWin32Error");
	pRtlSetLastWin32ErrorAndNtStatusFromNtStatus = (void *)GetProcAddress(library, "RtlSetLastWin32ErrorAndNtStatusFromNtStatus");
	pRtlRaiseStatus = (void *)GetProcAddress(library, "RtlRaiseStatus");
	pRtlAddVectoredContinueHandler = (void *)GetProcAddress(library, "RtlAddVectoredContinueHandler");
	pRtlRemoveVectoredContinueHandler = (void *)GetProcAddress(library, "RtlRemoveVectoredContinueHandler");
	pRtlAddVectoredExceptionHandler = (void *)GetProcAddress(library, "RtlAddVectoredExceptionHandler");
	pRtlRemoveVectoredExceptionHandler = (void *)GetProcAddress(library, "RtlRemoveVectoredExceptionHandler");
	pRtlSetUnhandledExceptionFilter = (void *)GetProcAddress(library, "RtlSetUnhandledExceptionFilter");
	pRtlAddFunctionTable = (void *)GetProcAddress(library, "RtlAddFunctionTable");
	pRtlInstallFunctionTableCallback = (void *)GetProcAddress(library, "RtlInstallFunctionTableCallback");
	pRtlAddGrowableFunctionTable = (void *)GetProcAddress(library, "RtlAddGrowableFunctionTable");
	pRtlGrowFunctionTable = (void *)GetProcAddress(library, "RtlGrowFunctionTable");
	pRtlDeleteGrowableFunctionTable = (void *)GetProcAddress(library, "RtlDeleteGrowableFunctionTable");
	pRtlDeleteFunctionTable = (void *)GetProcAddress(library, "RtlDeleteFunctionTable");
	pRtlLookupFunctionEntry = (void *)GetProcAddress(library, "RtlLookupFunctionEntry");
	pNtOpenFile = (void *)GetProcAddress(library, "NtOpenFile");
	pNtCreateFile = (void *)GetProcAddress(library, "NtCreateFile");
	pNtReadFile = (void *)GetProcAddress(library, "NtReadFile");
	pNtReadFileScatter = (void *)GetProcAddress(library, "NtReadFileScatter");
	pNtWriteFile = (void *)GetProcAddress(library, "NtWriteFile");
	pNtWriteFileGather = (void *)GetProcAddress(library, "NtWriteFileGather");
	pNtDeviceIoControlFile = (void *)GetProcAddress(library, "NtDeviceIoControlFile");
	pNtFsControlFile = (void *)GetProcAddress(library, "NtFsControlFile");
	pNtNotifyChangeDirectoryFile = (void *)GetProcAddress(library, "NtNotifyChangeDirectoryFile");
	pNtSetVolumeInformationFile = (void *)GetProcAddress(library, "NtSetVolumeInformationFile");
	pNtQueryInformationFile = (void *)GetProcAddress(library, "NtQueryInformationFile");
	pNtSetInformationFile = (void *)GetProcAddress(library, "NtSetInformationFile");
	pNtQueryFullAttributesFile = (void *)GetProcAddress(library, "NtQueryFullAttributesFile");
	pNtQueryAttributesFile = (void *)GetProcAddress(library, "NtQueryAttributesFile");
	pNtQueryVolumeInformationFile = (void *)GetProcAddress(library, "NtQueryVolumeInformationFile");
	pNtQueryEaFile = (void *)GetProcAddress(library, "NtQueryEaFile");
	pNtSetEaFile = (void *)GetProcAddress(library, "NtSetEaFile");
	pNtFlushBuffersFile = (void *)GetProcAddress(library, "NtFlushBuffersFile");
	pNtLockFile = (void *)GetProcAddress(library, "NtLockFile");
	pNtUnlockFile = (void *)GetProcAddress(library, "NtUnlockFile");
	pNtCreateNamedPipeFile = (void *)GetProcAddress(library, "NtCreateNamedPipeFile");
	pNtDeleteFile = (void *)GetProcAddress(library, "NtDeleteFile");
	pNtCancelIoFileEx = (void *)GetProcAddress(library, "NtCancelIoFileEx");
	pNtCancelIoFile = (void *)GetProcAddress(library, "NtCancelIoFile");
	pNtCreateMailslotFile = (void *)GetProcAddress(library, "NtCreateMailslotFile");
	pRtlInitializeHandleTable = (void *)GetProcAddress(library, "RtlInitializeHandleTable");
	pRtlDestroyHandleTable = (void *)GetProcAddress(library, "RtlDestroyHandleTable");
	pRtlAllocateHandle = (void *)GetProcAddress(library, "RtlAllocateHandle");
	pRtlFreeHandle = (void *)GetProcAddress(library, "RtlFreeHandle");
	pRtlIsValidHandle = (void *)GetProcAddress(library, "RtlIsValidHandle");
	pRtlIsValidIndexHandle = (void *)GetProcAddress(library, "RtlIsValidIndexHandle");
	pRtlCreateHeap = (void *)GetProcAddress(library, "RtlCreateHeap");
	pRtlDestroyHeap = (void *)GetProcAddress(library, "RtlDestroyHeap");
	pRtlAllocateHeap = (void *)GetProcAddress(library, "RtlAllocateHeap");
	pRtlFreeHeap = (void *)GetProcAddress(library, "RtlFreeHeap");
	pRtlReAllocateHeap = (void *)GetProcAddress(library, "RtlReAllocateHeap");
	pRtlCompactHeap = (void *)GetProcAddress(library, "RtlCompactHeap");
	pRtlLockHeap = (void *)GetProcAddress(library, "RtlLockHeap");
	pRtlUnlockHeap = (void *)GetProcAddress(library, "RtlUnlockHeap");
	pRtlSizeHeap = (void *)GetProcAddress(library, "RtlSizeHeap");
	pRtlValidateHeap = (void *)GetProcAddress(library, "RtlValidateHeap");
	pRtlWalkHeap = (void *)GetProcAddress(library, "RtlWalkHeap");
	pRtlGetProcessHeaps = (void *)GetProcAddress(library, "RtlGetProcessHeaps");
	pRtlQueryHeapInformation = (void *)GetProcAddress(library, "RtlQueryHeapInformation");
	pRtlSetHeapInformation = (void *)GetProcAddress(library, "RtlSetHeapInformation");
	pRtlLargeIntegerToChar = (void *)GetProcAddress(library, "RtlLargeIntegerToChar");
	pRtlInt64ToUnicodeString = (void *)GetProcAddress(library, "RtlInt64ToUnicodeString");
	pRtlGetUnloadEventTrace = (void *)GetProcAddress(library, "RtlGetUnloadEventTrace");
	pRtlGetUnloadEventTraceEx = (void *)GetProcAddress(library, "RtlGetUnloadEventTraceEx");
	pLdrDisableThreadCalloutsForDll = (void *)GetProcAddress(library, "LdrDisableThreadCalloutsForDll");
	pLdrFindEntryForAddress = (void *)GetProcAddress(library, "LdrFindEntryForAddress");
	pLdrEnumerateLoadedModules = (void *)GetProcAddress(library, "LdrEnumerateLoadedModules");
	pLdrRegisterDllNotification = (void *)GetProcAddress(library, "LdrRegisterDllNotification");
	pLdrUnregisterDllNotification = (void *)GetProcAddress(library, "LdrUnregisterDllNotification");
	pLdrLockLoaderLock = (void *)GetProcAddress(library, "LdrLockLoaderLock");
	pLdrUnlockLoaderLock = (void *)GetProcAddress(library, "LdrUnlockLoaderLock");
	pLdrGetProcedureAddress = (void *)GetProcAddress(library, "LdrGetProcedureAddress");
	pLdrLoadDll = (void *)GetProcAddress(library, "LdrLoadDll");
	pLdrGetDllHandle = (void *)GetProcAddress(library, "LdrGetDllHandle");
	pLdrAddRefDll = (void *)GetProcAddress(library, "LdrAddRefDll");
	pLdrProcessRelocationBlock = (void *)GetProcAddress(library, "LdrProcessRelocationBlock");
	pLdrQueryProcessModuleInformation = (void *)GetProcAddress(library, "LdrQueryProcessModuleInformation");
	pLdrQueryImageFileExecutionOptions = (void *)GetProcAddress(library, "LdrQueryImageFileExecutionOptions");
	pRtlDllShutdownInProgress = (void *)GetProcAddress(library, "RtlDllShutdownInProgress");
	pLdrResolveDelayLoadedAPI = (void *)GetProcAddress(library, "LdrResolveDelayLoadedAPI");
	pLdrShutdownProcess = (void *)GetProcAddress(library, "LdrShutdownProcess");
	pRtlExitUserProcess = (void *)GetProcAddress(library, "RtlExitUserProcess");
	pLdrShutdownThread = (void *)GetProcAddress(library, "LdrShutdownThread");
	pLdrUnloadDll = (void *)GetProcAddress(library, "LdrUnloadDll");
	pRtlImageNtHeader = (void *)GetProcAddress(library, "RtlImageNtHeader");
	pLdrInitializeThunk = (void *)GetProcAddress(library, "LdrInitializeThunk");
	pRtlImageDirectoryEntryToData = (void *)GetProcAddress(library, "RtlImageDirectoryEntryToData");
	pRtlImageRvaToSection = (void *)GetProcAddress(library, "RtlImageRvaToSection");
	pRtlImageRvaToVa = (void *)GetProcAddress(library, "RtlImageRvaToVa");
	pRtlPcToFileHeader = (void *)GetProcAddress(library, "RtlPcToFileHeader");
	pNtLoadDriver = (void *)GetProcAddress(library, "NtLoadDriver");
	pNtUnloadDriver = (void *)GetProcAddress(library, "NtUnloadDriver");
	p_lfind = (void *)GetProcAddress(library, "_lfind");
	pWinSqmEndSession = (void *)GetProcAddress(library, "WinSqmEndSession");
	pWinSqmIncrementDWORD = (void *)GetProcAddress(library, "WinSqmIncrementDWORD");
	pWinSqmIsOptedIn = (void *)GetProcAddress(library, "WinSqmIsOptedIn");
	pWinSqmStartSession = (void *)GetProcAddress(library, "WinSqmStartSession");
	pWinSqmSetDWORD = (void *)GetProcAddress(library, "WinSqmSetDWORD");
	pEtwEventActivityIdControl = (void *)GetProcAddress(library, "EtwEventActivityIdControl");
	pEtwEventProviderEnabled = (void *)GetProcAddress(library, "EtwEventProviderEnabled");
	pEtwEventRegister = (void *)GetProcAddress(library, "EtwEventRegister");
	pEtwEventUnregister = (void *)GetProcAddress(library, "EtwEventUnregister");
	pEtwEventSetInformation = (void *)GetProcAddress(library, "EtwEventSetInformation");
	pEtwEventWriteTransfer = (void *)GetProcAddress(library, "EtwEventWriteTransfer");
	pEtwRegisterTraceGuidsW = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsW");
	pEtwRegisterTraceGuidsA = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsA");
	pEtwUnregisterTraceGuids = (void *)GetProcAddress(library, "EtwUnregisterTraceGuids");
	pEtwEventEnabled = (void *)GetProcAddress(library, "EtwEventEnabled");
	pEtwEventWrite = (void *)GetProcAddress(library, "EtwEventWrite");
	pEtwGetTraceEnableFlags = (void *)GetProcAddress(library, "EtwGetTraceEnableFlags");
	pEtwGetTraceEnableLevel = (void *)GetProcAddress(library, "EtwGetTraceEnableLevel");
	pEtwGetTraceLoggerHandle = (void *)GetProcAddress(library, "EtwGetTraceLoggerHandle");
	pEtwLogTraceEvent = (void *)GetProcAddress(library, "EtwLogTraceEvent");
	pEtwTraceMessageVa = (void *)GetProcAddress(library, "EtwTraceMessageVa");
	pEtwTraceMessage = (void *)GetProcAddress(library, "EtwTraceMessage");
	pNtCreateLowBoxToken = (void *)GetProcAddress(library, "NtCreateLowBoxToken");
	pApiSetQueryApiSetPresence = (void *)GetProcAddress(library, "ApiSetQueryApiSetPresence");
	pNtDuplicateToken = (void *)GetProcAddress(library, "NtDuplicateToken");
	pNtOpenProcessToken = (void *)GetProcAddress(library, "NtOpenProcessToken");
	pNtOpenProcessTokenEx = (void *)GetProcAddress(library, "NtOpenProcessTokenEx");
	pNtOpenThreadToken = (void *)GetProcAddress(library, "NtOpenThreadToken");
	pNtOpenThreadTokenEx = (void *)GetProcAddress(library, "NtOpenThreadTokenEx");
	pNtAdjustPrivilegesToken = (void *)GetProcAddress(library, "NtAdjustPrivilegesToken");
	pNtQueryInformationToken = (void *)GetProcAddress(library, "NtQueryInformationToken");
	pNtSetInformationToken = (void *)GetProcAddress(library, "NtSetInformationToken");
	pNtAdjustGroupsToken = (void *)GetProcAddress(library, "NtAdjustGroupsToken");
	pNtPrivilegeCheck = (void *)GetProcAddress(library, "NtPrivilegeCheck");
	pNtCreatePort = (void *)GetProcAddress(library, "NtCreatePort");
	pNtConnectPort = (void *)GetProcAddress(library, "NtConnectPort");
	pNtSecureConnectPort = (void *)GetProcAddress(library, "NtSecureConnectPort");
	pNtListenPort = (void *)GetProcAddress(library, "NtListenPort");
	pNtAcceptConnectPort = (void *)GetProcAddress(library, "NtAcceptConnectPort");
	pNtCompleteConnectPort = (void *)GetProcAddress(library, "NtCompleteConnectPort");
	pNtRegisterThreadTerminatePort = (void *)GetProcAddress(library, "NtRegisterThreadTerminatePort");
	pNtRequestWaitReplyPort = (void *)GetProcAddress(library, "NtRequestWaitReplyPort");
	pNtReplyWaitReceivePort = (void *)GetProcAddress(library, "NtReplyWaitReceivePort");
	pNtSetIntervalProfile = (void *)GetProcAddress(library, "NtSetIntervalProfile");
	pRtlIsProcessorFeaturePresent = (void *)GetProcAddress(library, "RtlIsProcessorFeaturePresent");
	pNtQuerySystemInformation = (void *)GetProcAddress(library, "NtQuerySystemInformation");
	pNtQuerySystemInformationEx = (void *)GetProcAddress(library, "NtQuerySystemInformationEx");
	pNtSetSystemInformation = (void *)GetProcAddress(library, "NtSetSystemInformation");
	pNtCreatePagingFile = (void *)GetProcAddress(library, "NtCreatePagingFile");
	pNtDisplayString = (void *)GetProcAddress(library, "NtDisplayString");
	pNtInitiatePowerAction = (void *)GetProcAddress(library, "NtInitiatePowerAction");
	pNtSetThreadExecutionState = (void *)GetProcAddress(library, "NtSetThreadExecutionState");
	pNtCreatePowerRequest = (void *)GetProcAddress(library, "NtCreatePowerRequest");
	pNtSetPowerRequest = (void *)GetProcAddress(library, "NtSetPowerRequest");
	pNtClearPowerRequest = (void *)GetProcAddress(library, "NtClearPowerRequest");
	pNtPowerInformation = (void *)GetProcAddress(library, "NtPowerInformation");
	pNtShutdownSystem = (void *)GetProcAddress(library, "NtShutdownSystem");
	pNtAllocateLocallyUniqueId = (void *)GetProcAddress(library, "NtAllocateLocallyUniqueId");
	pVerSetConditionMask = (void *)GetProcAddress(library, "VerSetConditionMask");
	pNtAccessCheckAndAuditAlarm = (void *)GetProcAddress(library, "NtAccessCheckAndAuditAlarm");
	pNtSystemDebugControl = (void *)GetProcAddress(library, "NtSystemDebugControl");
	pNtSetLdtEntries = (void *)GetProcAddress(library, "NtSetLdtEntries");
	pNtQueryObject = (void *)GetProcAddress(library, "NtQueryObject");
	pNtSetInformationObject = (void *)GetProcAddress(library, "NtSetInformationObject");
	pNtQuerySecurityObject = (void *)GetProcAddress(library, "NtQuerySecurityObject");
	pNtDuplicateObject = (void *)GetProcAddress(library, "NtDuplicateObject");
	pNtClose = (void *)GetProcAddress(library, "NtClose");
	pNtOpenDirectoryObject = (void *)GetProcAddress(library, "NtOpenDirectoryObject");
	pNtCreateDirectoryObject = (void *)GetProcAddress(library, "NtCreateDirectoryObject");
	pNtQueryDirectoryObject = (void *)GetProcAddress(library, "NtQueryDirectoryObject");
	pNtOpenSymbolicLinkObject = (void *)GetProcAddress(library, "NtOpenSymbolicLinkObject");
	pNtCreateSymbolicLinkObject = (void *)GetProcAddress(library, "NtCreateSymbolicLinkObject");
	pNtQuerySymbolicLinkObject = (void *)GetProcAddress(library, "NtQuerySymbolicLinkObject");
	pNtAllocateUuids = (void *)GetProcAddress(library, "NtAllocateUuids");
	pNtMakeTemporaryObject = (void *)GetProcAddress(library, "NtMakeTemporaryObject");
	pRtlDetermineDosPathNameType_U = (void *)GetProcAddress(library, "RtlDetermineDosPathNameType_U");
	pRtlIsDosDeviceName_U = (void *)GetProcAddress(library, "RtlIsDosDeviceName_U");
	pRtlDosPathNameToNtPathName_U_WithStatus = (void *)GetProcAddress(library, "RtlDosPathNameToNtPathName_U_WithStatus");
	pRtlDosPathNameToNtPathName_U = (void *)GetProcAddress(library, "RtlDosPathNameToNtPathName_U");
	pRtlDosPathNameToRelativeNtPathName_U_WithStatus = (void *)GetProcAddress(library, "RtlDosPathNameToRelativeNtPathName_U_WithStatus");
	pRtlReleaseRelativeName = (void *)GetProcAddress(library, "RtlReleaseRelativeName");
	pRtlDosSearchPath_U = (void *)GetProcAddress(library, "RtlDosSearchPath_U");
	pRtlGetFullPathName_U = (void *)GetProcAddress(library, "RtlGetFullPathName_U");
	pRtlGetLongestNtPathLength = (void *)GetProcAddress(library, "RtlGetLongestNtPathLength");
	pRtlIsNameLegalDOS8Dot3 = (void *)GetProcAddress(library, "RtlIsNameLegalDOS8Dot3");
	pRtlGetCurrentDirectory_U = (void *)GetProcAddress(library, "RtlGetCurrentDirectory_U");
	pRtlSetCurrentDirectory_U = (void *)GetProcAddress(library, "RtlSetCurrentDirectory_U");
	pwine_unix_to_nt_file_name = (void *)GetProcAddress(library, "wine_unix_to_nt_file_name");
	p_vsnprintf_s = (void *)GetProcAddress(library, "_vsnprintf_s");
	p_snprintf_s = (void *)GetProcAddress(library, "_snprintf_s");
	pNtTerminateProcess = (void *)GetProcAddress(library, "NtTerminateProcess");
	pRtlGetCurrentPeb = (void *)GetProcAddress(library, "RtlGetCurrentPeb");
	p__wine_make_process_system = (void *)GetProcAddress(library, "__wine_make_process_system");
	pNtQueryInformationProcess = (void *)GetProcAddress(library, "NtQueryInformationProcess");
	pNtSetInformationProcess = (void *)GetProcAddress(library, "NtSetInformationProcess");
	pNtFlushInstructionCache = (void *)GetProcAddress(library, "NtFlushInstructionCache");
	pNtOpenProcess = (void *)GetProcAddress(library, "NtOpenProcess");
	pNtResumeProcess = (void *)GetProcAddress(library, "NtResumeProcess");
	pNtSuspendProcess = (void *)GetProcAddress(library, "NtSuspendProcess");
	pRtlCreateUserProcess = (void *)GetProcAddress(library, "RtlCreateUserProcess");
	pDbgUiRemoteBreakin = (void *)GetProcAddress(library, "DbgUiRemoteBreakin");
	pDbgUiIssueRemoteBreakin = (void *)GetProcAddress(library, "DbgUiIssueRemoteBreakin");
	pNtCreateKey = (void *)GetProcAddress(library, "NtCreateKey");
	pNtCreateKeyTransacted = (void *)GetProcAddress(library, "NtCreateKeyTransacted");
	pNtRenameKey = (void *)GetProcAddress(library, "NtRenameKey");
	pRtlpNtCreateKey = (void *)GetProcAddress(library, "RtlpNtCreateKey");
	pNtOpenKeyEx = (void *)GetProcAddress(library, "NtOpenKeyEx");
	pNtOpenKey = (void *)GetProcAddress(library, "NtOpenKey");
	pNtOpenKeyTransactedEx = (void *)GetProcAddress(library, "NtOpenKeyTransactedEx");
	pNtOpenKeyTransacted = (void *)GetProcAddress(library, "NtOpenKeyTransacted");
	pRtlpNtOpenKey = (void *)GetProcAddress(library, "RtlpNtOpenKey");
	pNtDeleteKey = (void *)GetProcAddress(library, "NtDeleteKey");
	pRtlpNtMakeTemporaryKey = (void *)GetProcAddress(library, "RtlpNtMakeTemporaryKey");
	pNtDeleteValueKey = (void *)GetProcAddress(library, "NtDeleteValueKey");
	pNtEnumerateKey = (void *)GetProcAddress(library, "NtEnumerateKey");
	pRtlpNtEnumerateSubKey = (void *)GetProcAddress(library, "RtlpNtEnumerateSubKey");
	pNtQueryKey = (void *)GetProcAddress(library, "NtQueryKey");
	pNtEnumerateValueKey = (void *)GetProcAddress(library, "NtEnumerateValueKey");
	pNtQueryValueKey = (void *)GetProcAddress(library, "NtQueryValueKey");
	pRtlpNtQueryValueKey = (void *)GetProcAddress(library, "RtlpNtQueryValueKey");
	pNtFlushKey = (void *)GetProcAddress(library, "NtFlushKey");
	pNtLoadKey = (void *)GetProcAddress(library, "NtLoadKey");
	pNtLoadKey2 = (void *)GetProcAddress(library, "NtLoadKey2");
	pNtNotifyChangeMultipleKeys = (void *)GetProcAddress(library, "NtNotifyChangeMultipleKeys");
	pNtNotifyChangeKey = (void *)GetProcAddress(library, "NtNotifyChangeKey");
	pNtQueryMultipleValueKey = (void *)GetProcAddress(library, "NtQueryMultipleValueKey");
	pNtReplaceKey = (void *)GetProcAddress(library, "NtReplaceKey");
	pNtRestoreKey = (void *)GetProcAddress(library, "NtRestoreKey");
	pNtSaveKey = (void *)GetProcAddress(library, "NtSaveKey");
	pNtSetInformationKey = (void *)GetProcAddress(library, "NtSetInformationKey");
	pNtSetValueKey = (void *)GetProcAddress(library, "NtSetValueKey");
	pRtlpNtSetValueKey = (void *)GetProcAddress(library, "RtlpNtSetValueKey");
	pNtUnloadKey = (void *)GetProcAddress(library, "NtUnloadKey");
	pRtlFormatCurrentUserKeyPath = (void *)GetProcAddress(library, "RtlFormatCurrentUserKeyPath");
	pRtlOpenCurrentUser = (void *)GetProcAddress(library, "RtlOpenCurrentUser");
	pRtlQueryRegistryValues = (void *)GetProcAddress(library, "RtlQueryRegistryValues");
	pRtlCheckRegistryKey = (void *)GetProcAddress(library, "RtlCheckRegistryKey");
	pRtlCreateRegistryKey = (void *)GetProcAddress(library, "RtlCreateRegistryKey");
	pRtlDeleteRegistryValue = (void *)GetProcAddress(library, "RtlDeleteRegistryValue");
	pRtlWriteRegistryValue = (void *)GetProcAddress(library, "RtlWriteRegistryValue");
	pNtQueryLicenseValue = (void *)GetProcAddress(library, "NtQueryLicenseValue");
	pLdrFindResourceDirectory_U = (void *)GetProcAddress(library, "LdrFindResourceDirectory_U");
	pLdrFindResource_U = (void *)GetProcAddress(library, "LdrFindResource_U");
	pLdrAccessResource = (void *)GetProcAddress(library, "LdrAccessResource");
	pRtlFindMessage = (void *)GetProcAddress(library, "RtlFindMessage");
	pRtlFormatMessage = (void *)GetProcAddress(library, "RtlFormatMessage");
	pNtQueryDefaultLocale = (void *)GetProcAddress(library, "NtQueryDefaultLocale");
	pNtSetDefaultLocale = (void *)GetProcAddress(library, "NtSetDefaultLocale");
	pNtQueryDefaultUILanguage = (void *)GetProcAddress(library, "NtQueryDefaultUILanguage");
	pNtSetDefaultUILanguage = (void *)GetProcAddress(library, "NtSetDefaultUILanguage");
	pNtQueryInstallUILanguage = (void *)GetProcAddress(library, "NtQueryInstallUILanguage");
	pRtlInitializeResource = (void *)GetProcAddress(library, "RtlInitializeResource");
	pRtlDeleteResource = (void *)GetProcAddress(library, "RtlDeleteResource");
	pRtlAcquireResourceExclusive = (void *)GetProcAddress(library, "RtlAcquireResourceExclusive");
	pRtlAcquireResourceShared = (void *)GetProcAddress(library, "RtlAcquireResourceShared");
	pRtlReleaseResource = (void *)GetProcAddress(library, "RtlReleaseResource");
	pRtlDumpResource = (void *)GetProcAddress(library, "RtlDumpResource");
	pDbgPrint = (void *)GetProcAddress(library, "DbgPrint");
	pDbgPrintEx = (void *)GetProcAddress(library, "DbgPrintEx");
	pvDbgPrintEx = (void *)GetProcAddress(library, "vDbgPrintEx");
	pvDbgPrintExWithPrefix = (void *)GetProcAddress(library, "vDbgPrintExWithPrefix");
	pRtlAcquirePebLock = (void *)GetProcAddress(library, "RtlAcquirePebLock");
	pRtlReleasePebLock = (void *)GetProcAddress(library, "RtlReleasePebLock");
	pRtlNewSecurityObject = (void *)GetProcAddress(library, "RtlNewSecurityObject");
	pRtlDeleteSecurityObject = (void *)GetProcAddress(library, "RtlDeleteSecurityObject");
	pRtlInitializeGenericTable = (void *)GetProcAddress(library, "RtlInitializeGenericTable");
	pRtlEnumerateGenericTableWithoutSplaying = (void *)GetProcAddress(library, "RtlEnumerateGenericTableWithoutSplaying");
	pRtlNumberGenericTableElements = (void *)GetProcAddress(library, "RtlNumberGenericTableElements");
	pRtlMoveMemory = (void *)GetProcAddress(library, "RtlMoveMemory");
	pRtlFillMemory = (void *)GetProcAddress(library, "RtlFillMemory");
	pRtlZeroMemory = (void *)GetProcAddress(library, "RtlZeroMemory");
	pRtlCompareMemory = (void *)GetProcAddress(library, "RtlCompareMemory");
	pRtlCompareMemoryUlong = (void *)GetProcAddress(library, "RtlCompareMemoryUlong");
	pRtlCopyMemory = (void *)GetProcAddress(library, "RtlCopyMemory");
	pRtlAssert = (void *)GetProcAddress(library, "RtlAssert");
	pRtlFillMemoryUlong = (void *)GetProcAddress(library, "RtlFillMemoryUlong");
	pRtlComputeCrc32 = (void *)GetProcAddress(library, "RtlComputeCrc32");
	pRtlUlonglongByteSwap = (void *)GetProcAddress(library, "RtlUlonglongByteSwap");
	pRtlUniform = (void *)GetProcAddress(library, "RtlUniform");
	pRtlRandom = (void *)GetProcAddress(library, "RtlRandom");
	pRtlRandomEx = (void *)GetProcAddress(library, "RtlRandomEx");
	pRtlAreAllAccessesGranted = (void *)GetProcAddress(library, "RtlAreAllAccessesGranted");
	pRtlAreAnyAccessesGranted = (void *)GetProcAddress(library, "RtlAreAnyAccessesGranted");
	pRtlMapGenericMask = (void *)GetProcAddress(library, "RtlMapGenericMask");
	pRtlCopyLuid = (void *)GetProcAddress(library, "RtlCopyLuid");
	pRtlEqualLuid = (void *)GetProcAddress(library, "RtlEqualLuid");
	pRtlCopyLuidAndAttributesArray = (void *)GetProcAddress(library, "RtlCopyLuidAndAttributesArray");
	pRtlIpv4StringToAddressExW = (void *)GetProcAddress(library, "RtlIpv4StringToAddressExW");
	pRtlIpv4StringToAddressW = (void *)GetProcAddress(library, "RtlIpv4StringToAddressW");
	pRtlIpv6StringToAddressExW = (void *)GetProcAddress(library, "RtlIpv6StringToAddressExW");
	pRtlIpv4AddressToStringExW = (void *)GetProcAddress(library, "RtlIpv4AddressToStringExW");
	pRtlIpv4AddressToStringExA = (void *)GetProcAddress(library, "RtlIpv4AddressToStringExA");
	pRtlIpv4AddressToStringW = (void *)GetProcAddress(library, "RtlIpv4AddressToStringW");
	pRtlIpv4AddressToStringA = (void *)GetProcAddress(library, "RtlIpv4AddressToStringA");
	pRtlEncodePointer = (void *)GetProcAddress(library, "RtlEncodePointer");
	pRtlDecodePointer = (void *)GetProcAddress(library, "RtlDecodePointer");
	pRtlInitializeSListHead = (void *)GetProcAddress(library, "RtlInitializeSListHead");
	pRtlQueryDepthSList = (void *)GetProcAddress(library, "RtlQueryDepthSList");
	pRtlFirstEntrySList = (void *)GetProcAddress(library, "RtlFirstEntrySList");
	pRtlInterlockedFlushSList = (void *)GetProcAddress(library, "RtlInterlockedFlushSList");
	pRtlInterlockedPushEntrySList = (void *)GetProcAddress(library, "RtlInterlockedPushEntrySList");
	pRtlInterlockedPopEntrySList = (void *)GetProcAddress(library, "RtlInterlockedPopEntrySList");
	pRtlInterlockedPushListSListEx = (void *)GetProcAddress(library, "RtlInterlockedPushListSListEx");
	pRtlInterlockedPushListSList = (void *)GetProcAddress(library, "RtlInterlockedPushListSList");
	pRtlGetCompressionWorkSpaceSize = (void *)GetProcAddress(library, "RtlGetCompressionWorkSpaceSize");
	pRtlCompressBuffer = (void *)GetProcAddress(library, "RtlCompressBuffer");
	pRtlDecompressFragment = (void *)GetProcAddress(library, "RtlDecompressFragment");
	pRtlDecompressBuffer = (void *)GetProcAddress(library, "RtlDecompressBuffer");
	pRtlSetThreadErrorMode = (void *)GetProcAddress(library, "RtlSetThreadErrorMode");
	pRtlGetThreadErrorMode = (void *)GetProcAddress(library, "RtlGetThreadErrorMode");
	pRtlGetCurrentTransaction = (void *)GetProcAddress(library, "RtlGetCurrentTransaction");
	pRtlSetCurrentTransaction = (void *)GetProcAddress(library, "RtlSetCurrentTransaction");
	pRtlGetCurrentProcessorNumberEx = (void *)GetProcAddress(library, "RtlGetCurrentProcessorNumberEx");
	pRtlInitializeGenericTableAvl = (void *)GetProcAddress(library, "RtlInitializeGenericTableAvl");
	pRtlInsertElementGenericTableAvl = (void *)GetProcAddress(library, "RtlInsertElementGenericTableAvl");
	pRtlQueryPackageIdentity = (void *)GetProcAddress(library, "RtlQueryPackageIdentity");
	pRtlInitializeBitMap = (void *)GetProcAddress(library, "RtlInitializeBitMap");
	pRtlSetAllBits = (void *)GetProcAddress(library, "RtlSetAllBits");
	pRtlClearAllBits = (void *)GetProcAddress(library, "RtlClearAllBits");
	pRtlSetBits = (void *)GetProcAddress(library, "RtlSetBits");
	pRtlClearBits = (void *)GetProcAddress(library, "RtlClearBits");
	pRtlAreBitsSet = (void *)GetProcAddress(library, "RtlAreBitsSet");
	pRtlAreBitsClear = (void *)GetProcAddress(library, "RtlAreBitsClear");
	pRtlFindSetBits = (void *)GetProcAddress(library, "RtlFindSetBits");
	pRtlFindClearBits = (void *)GetProcAddress(library, "RtlFindClearBits");
	pRtlFindSetBitsAndClear = (void *)GetProcAddress(library, "RtlFindSetBitsAndClear");
	pRtlFindClearBitsAndSet = (void *)GetProcAddress(library, "RtlFindClearBitsAndSet");
	pRtlNumberOfSetBits = (void *)GetProcAddress(library, "RtlNumberOfSetBits");
	pRtlNumberOfClearBits = (void *)GetProcAddress(library, "RtlNumberOfClearBits");
	pRtlFindMostSignificantBit = (void *)GetProcAddress(library, "RtlFindMostSignificantBit");
	pRtlFindLeastSignificantBit = (void *)GetProcAddress(library, "RtlFindLeastSignificantBit");
	pRtlFindNextForwardRunSet = (void *)GetProcAddress(library, "RtlFindNextForwardRunSet");
	pRtlFindNextForwardRunClear = (void *)GetProcAddress(library, "RtlFindNextForwardRunClear");
	pRtlFindLastBackwardRunSet = (void *)GetProcAddress(library, "RtlFindLastBackwardRunSet");
	pRtlFindLastBackwardRunClear = (void *)GetProcAddress(library, "RtlFindLastBackwardRunClear");
	pRtlFindSetRuns = (void *)GetProcAddress(library, "RtlFindSetRuns");
	pRtlFindClearRuns = (void *)GetProcAddress(library, "RtlFindClearRuns");
	pRtlFindLongestRunSet = (void *)GetProcAddress(library, "RtlFindLongestRunSet");
	pRtlFindLongestRunClear = (void *)GetProcAddress(library, "RtlFindLongestRunClear");
	p__wine_init_codepages = (void *)GetProcAddress(library, "__wine_init_codepages");
	pRtlInitAnsiString = (void *)GetProcAddress(library, "RtlInitAnsiString");
	pRtlInitAnsiStringEx = (void *)GetProcAddress(library, "RtlInitAnsiStringEx");
	pRtlInitString = (void *)GetProcAddress(library, "RtlInitString");
	pRtlFreeAnsiString = (void *)GetProcAddress(library, "RtlFreeAnsiString");
	pRtlFreeOemString = (void *)GetProcAddress(library, "RtlFreeOemString");
	pRtlCopyString = (void *)GetProcAddress(library, "RtlCopyString");
	pRtlInitUnicodeString = (void *)GetProcAddress(library, "RtlInitUnicodeString");
	pRtlInitUnicodeStringEx = (void *)GetProcAddress(library, "RtlInitUnicodeStringEx");
	pRtlCreateUnicodeString = (void *)GetProcAddress(library, "RtlCreateUnicodeString");
	pRtlCreateUnicodeStringFromAsciiz = (void *)GetProcAddress(library, "RtlCreateUnicodeStringFromAsciiz");
	pRtlFreeUnicodeString = (void *)GetProcAddress(library, "RtlFreeUnicodeString");
	pRtlCopyUnicodeString = (void *)GetProcAddress(library, "RtlCopyUnicodeString");
	pRtlDuplicateUnicodeString = (void *)GetProcAddress(library, "RtlDuplicateUnicodeString");
	pRtlEraseUnicodeString = (void *)GetProcAddress(library, "RtlEraseUnicodeString");
	pRtlCompareString = (void *)GetProcAddress(library, "RtlCompareString");
	pRtlCompareUnicodeStrings = (void *)GetProcAddress(library, "RtlCompareUnicodeStrings");
	pRtlCompareUnicodeString = (void *)GetProcAddress(library, "RtlCompareUnicodeString");
	pRtlEqualString = (void *)GetProcAddress(library, "RtlEqualString");
	pRtlEqualUnicodeString = (void *)GetProcAddress(library, "RtlEqualUnicodeString");
	pRtlPrefixString = (void *)GetProcAddress(library, "RtlPrefixString");
	pRtlPrefixUnicodeString = (void *)GetProcAddress(library, "RtlPrefixUnicodeString");
	pRtlEqualComputerName = (void *)GetProcAddress(library, "RtlEqualComputerName");
	pRtlEqualDomainName = (void *)GetProcAddress(library, "RtlEqualDomainName");
	pRtlAnsiCharToUnicodeChar = (void *)GetProcAddress(library, "RtlAnsiCharToUnicodeChar");
	pRtlAnsiStringToUnicodeString = (void *)GetProcAddress(library, "RtlAnsiStringToUnicodeString");
	pRtlOemStringToUnicodeString = (void *)GetProcAddress(library, "RtlOemStringToUnicodeString");
	pRtlUnicodeStringToAnsiString = (void *)GetProcAddress(library, "RtlUnicodeStringToAnsiString");
	pRtlUnicodeStringToOemString = (void *)GetProcAddress(library, "RtlUnicodeStringToOemString");
	pRtlMultiByteToUnicodeN = (void *)GetProcAddress(library, "RtlMultiByteToUnicodeN");
	pRtlOemToUnicodeN = (void *)GetProcAddress(library, "RtlOemToUnicodeN");
	pRtlUnicodeToMultiByteN = (void *)GetProcAddress(library, "RtlUnicodeToMultiByteN");
	pRtlUnicodeToOemN = (void *)GetProcAddress(library, "RtlUnicodeToOemN");
	pRtlUpperChar = (void *)GetProcAddress(library, "RtlUpperChar");
	pRtlUpperString = (void *)GetProcAddress(library, "RtlUpperString");
	pRtlUpcaseUnicodeChar = (void *)GetProcAddress(library, "RtlUpcaseUnicodeChar");
	pRtlDowncaseUnicodeChar = (void *)GetProcAddress(library, "RtlDowncaseUnicodeChar");
	pRtlUpcaseUnicodeString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeString");
	pRtlDowncaseUnicodeString = (void *)GetProcAddress(library, "RtlDowncaseUnicodeString");
	pRtlUpcaseUnicodeStringToAnsiString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToAnsiString");
	pRtlUpcaseUnicodeStringToOemString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToOemString");
	pRtlUpcaseUnicodeStringToCountedOemString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToCountedOemString");
	pRtlUpcaseUnicodeToMultiByteN = (void *)GetProcAddress(library, "RtlUpcaseUnicodeToMultiByteN");
	pRtlUpcaseUnicodeToOemN = (void *)GetProcAddress(library, "RtlUpcaseUnicodeToOemN");
	pRtlOemStringToUnicodeSize = (void *)GetProcAddress(library, "RtlOemStringToUnicodeSize");
	pRtlAnsiStringToUnicodeSize = (void *)GetProcAddress(library, "RtlAnsiStringToUnicodeSize");
	pRtlMultiByteToUnicodeSize = (void *)GetProcAddress(library, "RtlMultiByteToUnicodeSize");
	pRtlUnicodeToMultiByteSize = (void *)GetProcAddress(library, "RtlUnicodeToMultiByteSize");
	pRtlUnicodeStringToAnsiSize = (void *)GetProcAddress(library, "RtlUnicodeStringToAnsiSize");
	pRtlUnicodeStringToOemSize = (void *)GetProcAddress(library, "RtlUnicodeStringToOemSize");
	pRtlAppendAsciizToString = (void *)GetProcAddress(library, "RtlAppendAsciizToString");
	pRtlAppendStringToString = (void *)GetProcAddress(library, "RtlAppendStringToString");
	pRtlAppendUnicodeToString = (void *)GetProcAddress(library, "RtlAppendUnicodeToString");
	pRtlAppendUnicodeStringToString = (void *)GetProcAddress(library, "RtlAppendUnicodeStringToString");
	pRtlFindCharInUnicodeString = (void *)GetProcAddress(library, "RtlFindCharInUnicodeString");
	pRtlIsTextUnicode = (void *)GetProcAddress(library, "RtlIsTextUnicode");
	pRtlCharToInteger = (void *)GetProcAddress(library, "RtlCharToInteger");
	pRtlIntegerToChar = (void *)GetProcAddress(library, "RtlIntegerToChar");
	pRtlUnicodeStringToInteger = (void *)GetProcAddress(library, "RtlUnicodeStringToInteger");
	pRtlIntegerToUnicodeString = (void *)GetProcAddress(library, "RtlIntegerToUnicodeString");
	pRtlGUIDFromString = (void *)GetProcAddress(library, "RtlGUIDFromString");
	pRtlStringFromGUID = (void *)GetProcAddress(library, "RtlStringFromGUID");
	pRtlHashUnicodeString = (void *)GetProcAddress(library, "RtlHashUnicodeString");
	pRtlAllocateAndInitializeSid = (void *)GetProcAddress(library, "RtlAllocateAndInitializeSid");
	pRtlEqualSid = (void *)GetProcAddress(library, "RtlEqualSid");
	pRtlEqualPrefixSid = (void *)GetProcAddress(library, "RtlEqualPrefixSid");
	pRtlFreeSid = (void *)GetProcAddress(library, "RtlFreeSid");
	pRtlLengthRequiredSid = (void *)GetProcAddress(library, "RtlLengthRequiredSid");
	pRtlLengthSid = (void *)GetProcAddress(library, "RtlLengthSid");
	pRtlInitializeSid = (void *)GetProcAddress(library, "RtlInitializeSid");
	pRtlSubAuthoritySid = (void *)GetProcAddress(library, "RtlSubAuthoritySid");
	pRtlIdentifierAuthoritySid = (void *)GetProcAddress(library, "RtlIdentifierAuthoritySid");
	pRtlSubAuthorityCountSid = (void *)GetProcAddress(library, "RtlSubAuthorityCountSid");
	pRtlCopySid = (void *)GetProcAddress(library, "RtlCopySid");
	pRtlValidSid = (void *)GetProcAddress(library, "RtlValidSid");
	pRtlCreateSecurityDescriptor = (void *)GetProcAddress(library, "RtlCreateSecurityDescriptor");
	pRtlCopySecurityDescriptor = (void *)GetProcAddress(library, "RtlCopySecurityDescriptor");
	pRtlValidSecurityDescriptor = (void *)GetProcAddress(library, "RtlValidSecurityDescriptor");
	pRtlValidRelativeSecurityDescriptor = (void *)GetProcAddress(library, "RtlValidRelativeSecurityDescriptor");
	pRtlLengthSecurityDescriptor = (void *)GetProcAddress(library, "RtlLengthSecurityDescriptor");
	pRtlGetDaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetDaclSecurityDescriptor");
	pRtlSetDaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetDaclSecurityDescriptor");
	pRtlGetSaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetSaclSecurityDescriptor");
	pRtlSetSaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetSaclSecurityDescriptor");
	pRtlGetOwnerSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetOwnerSecurityDescriptor");
	pRtlSetOwnerSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetOwnerSecurityDescriptor");
	pRtlSetGroupSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetGroupSecurityDescriptor");
	pRtlGetGroupSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetGroupSecurityDescriptor");
	pRtlMakeSelfRelativeSD = (void *)GetProcAddress(library, "RtlMakeSelfRelativeSD");
	pRtlSelfRelativeToAbsoluteSD = (void *)GetProcAddress(library, "RtlSelfRelativeToAbsoluteSD");
	pRtlGetControlSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetControlSecurityDescriptor");
	pRtlSetControlSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetControlSecurityDescriptor");
	pRtlAbsoluteToSelfRelativeSD = (void *)GetProcAddress(library, "RtlAbsoluteToSelfRelativeSD");
	pRtlCreateAcl = (void *)GetProcAddress(library, "RtlCreateAcl");
	pRtlFirstFreeAce = (void *)GetProcAddress(library, "RtlFirstFreeAce");
	pRtlAddAce = (void *)GetProcAddress(library, "RtlAddAce");
	pRtlDeleteAce = (void *)GetProcAddress(library, "RtlDeleteAce");
	pRtlAddAccessAllowedAce = (void *)GetProcAddress(library, "RtlAddAccessAllowedAce");
	pRtlAddAccessAllowedAceEx = (void *)GetProcAddress(library, "RtlAddAccessAllowedAceEx");
	pRtlAddAccessAllowedObjectAce = (void *)GetProcAddress(library, "RtlAddAccessAllowedObjectAce");
	pRtlAddAccessDeniedAce = (void *)GetProcAddress(library, "RtlAddAccessDeniedAce");
	pRtlAddAccessDeniedAceEx = (void *)GetProcAddress(library, "RtlAddAccessDeniedAceEx");
	pRtlAddAccessDeniedObjectAce = (void *)GetProcAddress(library, "RtlAddAccessDeniedObjectAce");
	pRtlAddAuditAccessAceEx = (void *)GetProcAddress(library, "RtlAddAuditAccessAceEx");
	pRtlAddAuditAccessAce = (void *)GetProcAddress(library, "RtlAddAuditAccessAce");
	pRtlAddAuditAccessObjectAce = (void *)GetProcAddress(library, "RtlAddAuditAccessObjectAce");
	pRtlAddMandatoryAce = (void *)GetProcAddress(library, "RtlAddMandatoryAce");
	pRtlValidAcl = (void *)GetProcAddress(library, "RtlValidAcl");
	pRtlGetAce = (void *)GetProcAddress(library, "RtlGetAce");
	pRtlAdjustPrivilege = (void *)GetProcAddress(library, "RtlAdjustPrivilege");
	pRtlImpersonateSelf = (void *)GetProcAddress(library, "RtlImpersonateSelf");
	pNtImpersonateAnonymousToken = (void *)GetProcAddress(library, "NtImpersonateAnonymousToken");
	pNtAccessCheck = (void *)GetProcAddress(library, "NtAccessCheck");
	pNtSetSecurityObject = (void *)GetProcAddress(library, "NtSetSecurityObject");
	pRtlConvertSidToUnicodeString = (void *)GetProcAddress(library, "RtlConvertSidToUnicodeString");
	pRtlQueryInformationAcl = (void *)GetProcAddress(library, "RtlQueryInformationAcl");
	pRtlConvertToAutoInheritSecurityObject = (void *)GetProcAddress(library, "RtlConvertToAutoInheritSecurityObject");
	pwine_server_call = (void *)GetProcAddress(library, "wine_server_call");
	pwine_server_send_fd = (void *)GetProcAddress(library, "wine_server_send_fd");
	pwine_server_fd_to_handle = (void *)GetProcAddress(library, "wine_server_fd_to_handle");
	pwine_server_handle_to_fd = (void *)GetProcAddress(library, "wine_server_handle_to_fd");
	pwine_server_release_fd = (void *)GetProcAddress(library, "wine_server_release_fd");
	pNtSetContextThread = (void *)GetProcAddress(library, "NtSetContextThread");
	pNtGetContextThread = (void *)GetProcAddress(library, "NtGetContextThread");
	pRtlWow64GetThreadContext = (void *)GetProcAddress(library, "RtlWow64GetThreadContext");
	pRtlWow64SetThreadContext = (void *)GetProcAddress(library, "RtlWow64SetThreadContext");
	pNtRaiseException = (void *)GetProcAddress(library, "NtRaiseException");
	p__wine_set_signal_handler = (void *)GetProcAddress(library, "__wine_set_signal_handler");
	pRtlVirtualUnwind = (void *)GetProcAddress(library, "RtlVirtualUnwind");
	pRtlRestoreContext = (void *)GetProcAddress(library, "RtlRestoreContext");
	pRtlUnwindEx = (void *)GetProcAddress(library, "RtlUnwindEx");
	pRtlUnwind = (void *)GetProcAddress(library, "RtlUnwind");
	p_local_unwind = (void *)GetProcAddress(library, "_local_unwind");
	p__C_specific_handler = (void *)GetProcAddress(library, "__C_specific_handler");
	pRtlCaptureStackBackTrace = (void *)GetProcAddress(library, "RtlCaptureStackBackTrace");
	p_memccpy = (void *)GetProcAddress(library, "_memccpy");
	p_memicmp = (void *)GetProcAddress(library, "_memicmp");
	p_strnicmp = (void *)GetProcAddress(library, "_strnicmp");
	p_stricmp = (void *)GetProcAddress(library, "_stricmp");
	p_strupr = (void *)GetProcAddress(library, "_strupr");
	p_strlwr = (void *)GetProcAddress(library, "_strlwr");
	p_ultoa = (void *)GetProcAddress(library, "_ultoa");
	p_ltoa = (void *)GetProcAddress(library, "_ltoa");
	p_itoa = (void *)GetProcAddress(library, "_itoa");
	p_ui64toa = (void *)GetProcAddress(library, "_ui64toa");
	p_i64toa = (void *)GetProcAddress(library, "_i64toa");
	p_atoi64 = (void *)GetProcAddress(library, "_atoi64");
	p_splitpath = (void *)GetProcAddress(library, "_splitpath");
	pNtCreateSemaphore = (void *)GetProcAddress(library, "NtCreateSemaphore");
	pNtOpenSemaphore = (void *)GetProcAddress(library, "NtOpenSemaphore");
	pNtQuerySemaphore = (void *)GetProcAddress(library, "NtQuerySemaphore");
	pNtReleaseSemaphore = (void *)GetProcAddress(library, "NtReleaseSemaphore");
	pNtCreateEvent = (void *)GetProcAddress(library, "NtCreateEvent");
	pNtOpenEvent = (void *)GetProcAddress(library, "NtOpenEvent");
	pNtSetEvent = (void *)GetProcAddress(library, "NtSetEvent");
	pNtResetEvent = (void *)GetProcAddress(library, "NtResetEvent");
	pNtClearEvent = (void *)GetProcAddress(library, "NtClearEvent");
	pNtPulseEvent = (void *)GetProcAddress(library, "NtPulseEvent");
	pNtQueryEvent = (void *)GetProcAddress(library, "NtQueryEvent");
	pNtCreateMutant = (void *)GetProcAddress(library, "NtCreateMutant");
	pNtOpenMutant = (void *)GetProcAddress(library, "NtOpenMutant");
	pNtReleaseMutant = (void *)GetProcAddress(library, "NtReleaseMutant");
	pNtQueryMutant = (void *)GetProcAddress(library, "NtQueryMutant");
	pNtCreateJobObject = (void *)GetProcAddress(library, "NtCreateJobObject");
	pNtOpenJobObject = (void *)GetProcAddress(library, "NtOpenJobObject");
	pNtTerminateJobObject = (void *)GetProcAddress(library, "NtTerminateJobObject");
	pNtQueryInformationJobObject = (void *)GetProcAddress(library, "NtQueryInformationJobObject");
	pNtSetInformationJobObject = (void *)GetProcAddress(library, "NtSetInformationJobObject");
	pNtIsProcessInJob = (void *)GetProcAddress(library, "NtIsProcessInJob");
	pNtAssignProcessToJobObject = (void *)GetProcAddress(library, "NtAssignProcessToJobObject");
	pNtCreateTimer = (void *)GetProcAddress(library, "NtCreateTimer");
	pNtOpenTimer = (void *)GetProcAddress(library, "NtOpenTimer");
	pNtSetTimer = (void *)GetProcAddress(library, "NtSetTimer");
	pNtCancelTimer = (void *)GetProcAddress(library, "NtCancelTimer");
	pNtQueryTimer = (void *)GetProcAddress(library, "NtQueryTimer");
	pNtQueryTimerResolution = (void *)GetProcAddress(library, "NtQueryTimerResolution");
	pNtSetTimerResolution = (void *)GetProcAddress(library, "NtSetTimerResolution");
	pNtWaitForMultipleObjects = (void *)GetProcAddress(library, "NtWaitForMultipleObjects");
	pNtWaitForSingleObject = (void *)GetProcAddress(library, "NtWaitForSingleObject");
	pNtSignalAndWaitForSingleObject = (void *)GetProcAddress(library, "NtSignalAndWaitForSingleObject");
	pNtYieldExecution = (void *)GetProcAddress(library, "NtYieldExecution");
	pNtDelayExecution = (void *)GetProcAddress(library, "NtDelayExecution");
	pNtCreateKeyedEvent = (void *)GetProcAddress(library, "NtCreateKeyedEvent");
	pNtOpenKeyedEvent = (void *)GetProcAddress(library, "NtOpenKeyedEvent");
	pNtWaitForKeyedEvent = (void *)GetProcAddress(library, "NtWaitForKeyedEvent");
	pNtReleaseKeyedEvent = (void *)GetProcAddress(library, "NtReleaseKeyedEvent");
	pNtCreateIoCompletion = (void *)GetProcAddress(library, "NtCreateIoCompletion");
	pNtSetIoCompletion = (void *)GetProcAddress(library, "NtSetIoCompletion");
	pNtRemoveIoCompletion = (void *)GetProcAddress(library, "NtRemoveIoCompletion");
	pNtRemoveIoCompletionEx = (void *)GetProcAddress(library, "NtRemoveIoCompletionEx");
	pNtOpenIoCompletion = (void *)GetProcAddress(library, "NtOpenIoCompletion");
	pNtQueryIoCompletion = (void *)GetProcAddress(library, "NtQueryIoCompletion");
	pRtlRunOnceInitialize = (void *)GetProcAddress(library, "RtlRunOnceInitialize");
	pRtlRunOnceBeginInitialize = (void *)GetProcAddress(library, "RtlRunOnceBeginInitialize");
	pRtlRunOnceComplete = (void *)GetProcAddress(library, "RtlRunOnceComplete");
	pRtlRunOnceExecuteOnce = (void *)GetProcAddress(library, "RtlRunOnceExecuteOnce");
	pRtlInitializeSRWLock = (void *)GetProcAddress(library, "RtlInitializeSRWLock");
	pRtlAcquireSRWLockExclusive = (void *)GetProcAddress(library, "RtlAcquireSRWLockExclusive");
	pRtlAcquireSRWLockShared = (void *)GetProcAddress(library, "RtlAcquireSRWLockShared");
	pRtlReleaseSRWLockExclusive = (void *)GetProcAddress(library, "RtlReleaseSRWLockExclusive");
	pRtlReleaseSRWLockShared = (void *)GetProcAddress(library, "RtlReleaseSRWLockShared");
	pRtlTryAcquireSRWLockExclusive = (void *)GetProcAddress(library, "RtlTryAcquireSRWLockExclusive");
	pRtlTryAcquireSRWLockShared = (void *)GetProcAddress(library, "RtlTryAcquireSRWLockShared");
	pRtlInitializeConditionVariable = (void *)GetProcAddress(library, "RtlInitializeConditionVariable");
	pRtlWakeConditionVariable = (void *)GetProcAddress(library, "RtlWakeConditionVariable");
	pRtlWakeAllConditionVariable = (void *)GetProcAddress(library, "RtlWakeAllConditionVariable");
	pRtlSleepConditionVariableCS = (void *)GetProcAddress(library, "RtlSleepConditionVariableCS");
	pRtlSleepConditionVariableSRW = (void *)GetProcAddress(library, "RtlSleepConditionVariableSRW");
	pRtlWaitOnAddress = (void *)GetProcAddress(library, "RtlWaitOnAddress");
	pRtlWakeAddressAll = (void *)GetProcAddress(library, "RtlWakeAddressAll");
	pRtlWakeAddressSingle = (void *)GetProcAddress(library, "RtlWakeAddressSingle");
	pRtlExitUserThread = (void *)GetProcAddress(library, "RtlExitUserThread");
	pNtCreateThreadEx = (void *)GetProcAddress(library, "NtCreateThreadEx");
	pRtlCreateUserThread = (void *)GetProcAddress(library, "RtlCreateUserThread");
	pRtlGetNtGlobalFlags = (void *)GetProcAddress(library, "RtlGetNtGlobalFlags");
	pNtOpenThread = (void *)GetProcAddress(library, "NtOpenThread");
	pNtSuspendThread = (void *)GetProcAddress(library, "NtSuspendThread");
	pNtResumeThread = (void *)GetProcAddress(library, "NtResumeThread");
	pNtAlertResumeThread = (void *)GetProcAddress(library, "NtAlertResumeThread");
	pNtAlertThread = (void *)GetProcAddress(library, "NtAlertThread");
	pNtTerminateThread = (void *)GetProcAddress(library, "NtTerminateThread");
	pNtQueueApcThread = (void *)GetProcAddress(library, "NtQueueApcThread");
	pRtlPushFrame = (void *)GetProcAddress(library, "RtlPushFrame");
	pRtlPopFrame = (void *)GetProcAddress(library, "RtlPopFrame");
	pRtlGetFrame = (void *)GetProcAddress(library, "RtlGetFrame");
	pNtQueryInformationThread = (void *)GetProcAddress(library, "NtQueryInformationThread");
	pNtSetInformationThread = (void *)GetProcAddress(library, "NtSetInformationThread");
	pNtGetCurrentProcessorNumber = (void *)GetProcAddress(library, "NtGetCurrentProcessorNumber");
	pRtlQueueWorkItem = (void *)GetProcAddress(library, "RtlQueueWorkItem");
	pRtlSetIoCompletionCallback = (void *)GetProcAddress(library, "RtlSetIoCompletionCallback");
	pRtlRegisterWait = (void *)GetProcAddress(library, "RtlRegisterWait");
	pRtlDeregisterWaitEx = (void *)GetProcAddress(library, "RtlDeregisterWaitEx");
	pRtlDeregisterWait = (void *)GetProcAddress(library, "RtlDeregisterWait");
	pRtlCreateTimerQueue = (void *)GetProcAddress(library, "RtlCreateTimerQueue");
	pRtlDeleteTimerQueueEx = (void *)GetProcAddress(library, "RtlDeleteTimerQueueEx");
	pRtlCreateTimer = (void *)GetProcAddress(library, "RtlCreateTimer");
	pRtlUpdateTimer = (void *)GetProcAddress(library, "RtlUpdateTimer");
	pRtlDeleteTimer = (void *)GetProcAddress(library, "RtlDeleteTimer");
	pTpAllocCleanupGroup = (void *)GetProcAddress(library, "TpAllocCleanupGroup");
	pTpAllocPool = (void *)GetProcAddress(library, "TpAllocPool");
	pTpAllocTimer = (void *)GetProcAddress(library, "TpAllocTimer");
	pTpAllocWait = (void *)GetProcAddress(library, "TpAllocWait");
	pTpAllocWork = (void *)GetProcAddress(library, "TpAllocWork");
	pTpCallbackLeaveCriticalSectionOnCompletion = (void *)GetProcAddress(library, "TpCallbackLeaveCriticalSectionOnCompletion");
	pTpCallbackMayRunLong = (void *)GetProcAddress(library, "TpCallbackMayRunLong");
	pTpCallbackReleaseMutexOnCompletion = (void *)GetProcAddress(library, "TpCallbackReleaseMutexOnCompletion");
	pTpCallbackReleaseSemaphoreOnCompletion = (void *)GetProcAddress(library, "TpCallbackReleaseSemaphoreOnCompletion");
	pTpCallbackSetEventOnCompletion = (void *)GetProcAddress(library, "TpCallbackSetEventOnCompletion");
	pTpCallbackUnloadDllOnCompletion = (void *)GetProcAddress(library, "TpCallbackUnloadDllOnCompletion");
	pTpDisassociateCallback = (void *)GetProcAddress(library, "TpDisassociateCallback");
	pTpIsTimerSet = (void *)GetProcAddress(library, "TpIsTimerSet");
	pTpPostWork = (void *)GetProcAddress(library, "TpPostWork");
	pTpReleaseCleanupGroup = (void *)GetProcAddress(library, "TpReleaseCleanupGroup");
	pTpReleaseCleanupGroupMembers = (void *)GetProcAddress(library, "TpReleaseCleanupGroupMembers");
	pTpReleasePool = (void *)GetProcAddress(library, "TpReleasePool");
	pTpReleaseTimer = (void *)GetProcAddress(library, "TpReleaseTimer");
	pTpReleaseWait = (void *)GetProcAddress(library, "TpReleaseWait");
	pTpReleaseWork = (void *)GetProcAddress(library, "TpReleaseWork");
	pTpSetPoolMaxThreads = (void *)GetProcAddress(library, "TpSetPoolMaxThreads");
	pTpSetPoolMinThreads = (void *)GetProcAddress(library, "TpSetPoolMinThreads");
	pTpSetTimer = (void *)GetProcAddress(library, "TpSetTimer");
	pTpSetWait = (void *)GetProcAddress(library, "TpSetWait");
	pTpSimpleTryPost = (void *)GetProcAddress(library, "TpSimpleTryPost");
	pTpWaitForTimer = (void *)GetProcAddress(library, "TpWaitForTimer");
	pTpWaitForWait = (void *)GetProcAddress(library, "TpWaitForWait");
	pTpWaitForWork = (void *)GetProcAddress(library, "TpWaitForWork");
	pRtlTimeToTimeFields = (void *)GetProcAddress(library, "RtlTimeToTimeFields");
	pRtlTimeFieldsToTime = (void *)GetProcAddress(library, "RtlTimeFieldsToTime");
	pRtlLocalTimeToSystemTime = (void *)GetProcAddress(library, "RtlLocalTimeToSystemTime");
	pRtlSystemTimeToLocalTime = (void *)GetProcAddress(library, "RtlSystemTimeToLocalTime");
	pRtlTimeToSecondsSince1970 = (void *)GetProcAddress(library, "RtlTimeToSecondsSince1970");
	pRtlTimeToSecondsSince1980 = (void *)GetProcAddress(library, "RtlTimeToSecondsSince1980");
	pRtlSecondsSince1970ToTime = (void *)GetProcAddress(library, "RtlSecondsSince1970ToTime");
	pRtlSecondsSince1980ToTime = (void *)GetProcAddress(library, "RtlSecondsSince1980ToTime");
	pRtlTimeToElapsedTimeFields = (void *)GetProcAddress(library, "RtlTimeToElapsedTimeFields");
	pNtQuerySystemTime = (void *)GetProcAddress(library, "NtQuerySystemTime");
	pRtlGetSystemTimePrecise = (void *)GetProcAddress(library, "RtlGetSystemTimePrecise");
	pNtQueryPerformanceCounter = (void *)GetProcAddress(library, "NtQueryPerformanceCounter");
	pNtGetTickCount = (void *)GetProcAddress(library, "NtGetTickCount");
	pRtlQueryTimeZoneInformation = (void *)GetProcAddress(library, "RtlQueryTimeZoneInformation");
	pRtlQueryDynamicTimeZoneInformation = (void *)GetProcAddress(library, "RtlQueryDynamicTimeZoneInformation");
	pRtlSetTimeZoneInformation = (void *)GetProcAddress(library, "RtlSetTimeZoneInformation");
	pNtSetSystemTime = (void *)GetProcAddress(library, "NtSetSystemTime");
	pRtlQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "RtlQueryUnbiasedInterruptTime");
	pRtlGetProductInfo = (void *)GetProcAddress(library, "RtlGetProductInfo");
	pRtlGetVersion = (void *)GetProcAddress(library, "RtlGetVersion");
	pRtlGetNtVersionNumbers = (void *)GetProcAddress(library, "RtlGetNtVersionNumbers");
	pRtlGetNtProductType = (void *)GetProcAddress(library, "RtlGetNtProductType");
	pRtlVerifyVersionInfo = (void *)GetProcAddress(library, "RtlVerifyVersionInfo");
	pRtlCreateUserStack = (void *)GetProcAddress(library, "RtlCreateUserStack");
	pRtlFreeUserStack = (void *)GetProcAddress(library, "RtlFreeUserStack");
	p__wine_locked_recvmsg = (void *)GetProcAddress(library, "__wine_locked_recvmsg");
	pNtAllocateVirtualMemory = (void *)GetProcAddress(library, "NtAllocateVirtualMemory");
	pNtFreeVirtualMemory = (void *)GetProcAddress(library, "NtFreeVirtualMemory");
	pNtProtectVirtualMemory = (void *)GetProcAddress(library, "NtProtectVirtualMemory");
	pNtQueryVirtualMemory = (void *)GetProcAddress(library, "NtQueryVirtualMemory");
	pNtLockVirtualMemory = (void *)GetProcAddress(library, "NtLockVirtualMemory");
	pNtUnlockVirtualMemory = (void *)GetProcAddress(library, "NtUnlockVirtualMemory");
	pNtCreateSection = (void *)GetProcAddress(library, "NtCreateSection");
	pNtOpenSection = (void *)GetProcAddress(library, "NtOpenSection");
	pNtMapViewOfSection = (void *)GetProcAddress(library, "NtMapViewOfSection");
	pNtUnmapViewOfSection = (void *)GetProcAddress(library, "NtUnmapViewOfSection");
	pNtQuerySection = (void *)GetProcAddress(library, "NtQuerySection");
	pNtFlushVirtualMemory = (void *)GetProcAddress(library, "NtFlushVirtualMemory");
	pNtGetWriteWatch = (void *)GetProcAddress(library, "NtGetWriteWatch");
	pNtResetWriteWatch = (void *)GetProcAddress(library, "NtResetWriteWatch");
	pNtReadVirtualMemory = (void *)GetProcAddress(library, "NtReadVirtualMemory");
	pNtWriteVirtualMemory = (void *)GetProcAddress(library, "NtWriteVirtualMemory");
	pNtAreMappedFilesTheSame = (void *)GetProcAddress(library, "NtAreMappedFilesTheSame");
	p_ultow = (void *)GetProcAddress(library, "_ultow");
	p_ltow = (void *)GetProcAddress(library, "_ltow");
	p_itow = (void *)GetProcAddress(library, "_itow");
	p_ui64tow = (void *)GetProcAddress(library, "_ui64tow");
	p_i64tow = (void *)GetProcAddress(library, "_i64tow");
	p_wtol = (void *)GetProcAddress(library, "_wtol");
	p_wtoi = (void *)GetProcAddress(library, "_wtoi");
	p_wtoi64 = (void *)GetProcAddress(library, "_wtoi64");
	initialized = TRUE;
}

void* wine_thunk_get_for_ntdll(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pRtlCreateActivationContext)
		return wine32a_RtlCreateActivationContext;
	if (func == pRtlAddRefActivationContext)
		return wine32a_RtlAddRefActivationContext;
	if (func == pRtlReleaseActivationContext)
		return wine32a_RtlReleaseActivationContext;
	if (func == pRtlZombifyActivationContext)
		return wine32a_RtlZombifyActivationContext;
	if (func == pRtlActivateActivationContext)
		return wine32a_RtlActivateActivationContext;
	if (func == pRtlDeactivateActivationContext)
		return wine32a_RtlDeactivateActivationContext;
	if (func == pRtlFreeThreadActivationContextStack)
		return wine32a_RtlFreeThreadActivationContextStack;
	if (func == pRtlGetActiveActivationContext)
		return wine32a_RtlGetActiveActivationContext;
	if (func == pRtlIsActivationContextActive)
		return wine32a_RtlIsActivationContextActive;
	if (func == pRtlQueryInformationActivationContext)
		return wine32a_RtlQueryInformationActivationContext;
	if (func == pRtlFindActivationContextSectionString)
		return wine32a_RtlFindActivationContextSectionString;
	if (func == pRtlFindActivationContextSectionGuid)
		return wine32a_RtlFindActivationContextSectionGuid;
	if (func == pRtlQueryActivationContextApplicationSettings)
		return wine32a_RtlQueryActivationContextApplicationSettings;
	if (func == pRtlDeleteAtomFromAtomTable)
		return wine32a_RtlDeleteAtomFromAtomTable;
	if (func == pRtlQueryAtomInAtomTable)
		return wine32a_RtlQueryAtomInAtomTable;
	if (func == pRtlCreateAtomTable)
		return wine32a_RtlCreateAtomTable;
	if (func == pRtlDestroyAtomTable)
		return wine32a_RtlDestroyAtomTable;
	if (func == pRtlAddAtomToAtomTable)
		return wine32a_RtlAddAtomToAtomTable;
	if (func == pRtlLookupAtomInAtomTable)
		return wine32a_RtlLookupAtomInAtomTable;
	if (func == pRtlEmptyAtomTable)
		return wine32a_RtlEmptyAtomTable;
	if (func == pRtlPinAtomInAtomTable)
		return wine32a_RtlPinAtomInAtomTable;
	if (func == pNtAddAtom)
		return wine32a_NtAddAtom;
	if (func == pNtDeleteAtom)
		return wine32a_NtDeleteAtom;
	if (func == pNtFindAtom)
		return wine32a_NtFindAtom;
	if (func == pNtQueryInformationAtom)
		return wine32a_NtQueryInformationAtom;
	if (func == pRtlInitializeCriticalSection)
		return wine32a_RtlInitializeCriticalSection;
	if (func == pRtlInitializeCriticalSectionAndSpinCount)
		return wine32a_RtlInitializeCriticalSectionAndSpinCount;
	if (func == pRtlInitializeCriticalSectionEx)
		return wine32a_RtlInitializeCriticalSectionEx;
	if (func == pRtlSetCriticalSectionSpinCount)
		return wine32a_RtlSetCriticalSectionSpinCount;
	if (func == pRtlDeleteCriticalSection)
		return wine32a_RtlDeleteCriticalSection;
	if (func == pRtlpWaitForCriticalSection)
		return wine32a_RtlpWaitForCriticalSection;
	if (func == pRtlpUnWaitCriticalSection)
		return wine32a_RtlpUnWaitCriticalSection;
	if (func == pRtlEnterCriticalSection)
		return wine32a_RtlEnterCriticalSection;
	if (func == pRtlTryEnterCriticalSection)
		return wine32a_RtlTryEnterCriticalSection;
	if (func == pRtlIsCriticalSectionLocked)
		return wine32a_RtlIsCriticalSectionLocked;
	if (func == pRtlIsCriticalSectionLockedByThread)
		return wine32a_RtlIsCriticalSectionLockedByThread;
	if (func == pRtlLeaveCriticalSection)
		return wine32a_RtlLeaveCriticalSection;
	if (func == pA_SHAInit)
		return wine32a_A_SHAInit;
	if (func == pA_SHAUpdate)
		return wine32a_A_SHAUpdate;
	if (func == pA_SHAFinal)
		return wine32a_A_SHAFinal;
	if (func == pMD4Init)
		return wine32a_MD4Init;
	if (func == pMD4Update)
		return wine32a_MD4Update;
	if (func == pMD4Final)
		return wine32a_MD4Final;
	if (func == pMD5Init)
		return wine32a_MD5Init;
	if (func == pMD5Update)
		return wine32a_MD5Update;
	if (func == pMD5Final)
		return wine32a_MD5Final;
	if (func == pRtlCreateQueryDebugBuffer)
		return wine32a_RtlCreateQueryDebugBuffer;
	if (func == pRtlDestroyQueryDebugBuffer)
		return wine32a_RtlDestroyQueryDebugBuffer;
	if (func == pRtlQueryProcessDebugInformation)
		return wine32a_RtlQueryProcessDebugInformation;
	if (func == p__wine_dbg_get_channel_flags)
		return wine32a___wine_dbg_get_channel_flags;
	if (func == p__wine_dbg_strdup)
		return wine32a___wine_dbg_strdup;
	if (func == p__wine_dbg_output)
		return wine32a___wine_dbg_output;
	if (func == p__wine_dbg_header)
		return wine32a___wine_dbg_header;
	if (func == pNtQueryDirectoryFile)
		return wine32a_NtQueryDirectoryFile;
	if (func == pwine_nt_to_unix_file_name)
		return wine32a_wine_nt_to_unix_file_name;
	if (func == pRtlWow64EnableFsRedirection)
		return wine32a_RtlWow64EnableFsRedirection;
	if (func == pRtlWow64EnableFsRedirectionEx)
		return wine32a_RtlWow64EnableFsRedirectionEx;
	if (func == pRtlDoesFileExists_U)
		return wine32a_RtlDoesFileExists_U;
	if (func == pNtQuerySystemEnvironmentValue)
		return wine32a_NtQuerySystemEnvironmentValue;
	if (func == pNtQuerySystemEnvironmentValueEx)
		return wine32a_NtQuerySystemEnvironmentValueEx;
	if (func == pRtlCreateEnvironment)
		return wine32a_RtlCreateEnvironment;
	if (func == pRtlDestroyEnvironment)
		return wine32a_RtlDestroyEnvironment;
	if (func == pRtlQueryEnvironmentVariable_U)
		return wine32a_RtlQueryEnvironmentVariable_U;
	if (func == pRtlSetCurrentEnvironment)
		return wine32a_RtlSetCurrentEnvironment;
	if (func == pRtlSetEnvironmentVariable)
		return wine32a_RtlSetEnvironmentVariable;
	if (func == pRtlExpandEnvironmentStrings)
		return wine32a_RtlExpandEnvironmentStrings;
	if (func == pRtlExpandEnvironmentStrings_U)
		return wine32a_RtlExpandEnvironmentStrings_U;
	if (func == pRtlNormalizeProcessParams)
		return wine32a_RtlNormalizeProcessParams;
	if (func == pRtlDeNormalizeProcessParams)
		return wine32a_RtlDeNormalizeProcessParams;
	if (func == pRtlCreateProcessParametersEx)
		return wine32a_RtlCreateProcessParametersEx;
	if (func == pRtlCreateProcessParameters)
		return wine32a_RtlCreateProcessParameters;
	if (func == pRtlDestroyProcessParameters)
		return wine32a_RtlDestroyProcessParameters;
	if (func == pRtlNtStatusToDosErrorNoTeb)
		return wine32a_RtlNtStatusToDosErrorNoTeb;
	if (func == pRtlNtStatusToDosError)
		return wine32a_RtlNtStatusToDosError;
	if (func == pRtlGetLastNtStatus)
		return wine32a_RtlGetLastNtStatus;
	if (func == pRtlGetLastWin32Error)
		return wine32a_RtlGetLastWin32Error;
	if (func == pNtRaiseHardError)
		return wine32a_NtRaiseHardError;
	if (func == pRtlSetLastWin32Error)
		return wine32a_RtlSetLastWin32Error;
	if (func == pRtlSetLastWin32ErrorAndNtStatusFromNtStatus)
		return wine32a_RtlSetLastWin32ErrorAndNtStatusFromNtStatus;
	if (func == pRtlRaiseStatus)
		return wine32a_RtlRaiseStatus;
	if (func == pRtlAddVectoredContinueHandler)
		return wine32a_RtlAddVectoredContinueHandler;
	if (func == pRtlRemoveVectoredContinueHandler)
		return wine32a_RtlRemoveVectoredContinueHandler;
	if (func == pRtlAddVectoredExceptionHandler)
		return wine32a_RtlAddVectoredExceptionHandler;
	if (func == pRtlRemoveVectoredExceptionHandler)
		return wine32a_RtlRemoveVectoredExceptionHandler;
	if (func == pRtlSetUnhandledExceptionFilter)
		return wine32a_RtlSetUnhandledExceptionFilter;
	if (func == pRtlAddFunctionTable)
		return wine32a_RtlAddFunctionTable;
	if (func == pRtlInstallFunctionTableCallback)
		return wine32a_RtlInstallFunctionTableCallback;
	if (func == pRtlAddGrowableFunctionTable)
		return wine32a_RtlAddGrowableFunctionTable;
	if (func == pRtlGrowFunctionTable)
		return wine32a_RtlGrowFunctionTable;
	if (func == pRtlDeleteGrowableFunctionTable)
		return wine32a_RtlDeleteGrowableFunctionTable;
	if (func == pRtlDeleteFunctionTable)
		return wine32a_RtlDeleteFunctionTable;
	if (func == pRtlLookupFunctionEntry)
		return wine32a_RtlLookupFunctionEntry;
	if (func == pNtOpenFile)
		return wine32a_NtOpenFile;
	if (func == pNtCreateFile)
		return wine32a_NtCreateFile;
	if (func == pNtReadFile)
		return wine32a_NtReadFile;
	if (func == pNtReadFileScatter)
		return wine32a_NtReadFileScatter;
	if (func == pNtWriteFile)
		return wine32a_NtWriteFile;
	if (func == pNtWriteFileGather)
		return wine32a_NtWriteFileGather;
	if (func == pNtDeviceIoControlFile)
		return wine32a_NtDeviceIoControlFile;
	if (func == pNtFsControlFile)
		return wine32a_NtFsControlFile;
	if (func == pNtNotifyChangeDirectoryFile)
		return wine32a_NtNotifyChangeDirectoryFile;
	if (func == pNtSetVolumeInformationFile)
		return wine32a_NtSetVolumeInformationFile;
	if (func == pNtQueryInformationFile)
		return wine32a_NtQueryInformationFile;
	if (func == pNtSetInformationFile)
		return wine32a_NtSetInformationFile;
	if (func == pNtQueryFullAttributesFile)
		return wine32a_NtQueryFullAttributesFile;
	if (func == pNtQueryAttributesFile)
		return wine32a_NtQueryAttributesFile;
	if (func == pNtQueryVolumeInformationFile)
		return wine32a_NtQueryVolumeInformationFile;
	if (func == pNtQueryEaFile)
		return wine32a_NtQueryEaFile;
	if (func == pNtSetEaFile)
		return wine32a_NtSetEaFile;
	if (func == pNtFlushBuffersFile)
		return wine32a_NtFlushBuffersFile;
	if (func == pNtLockFile)
		return wine32a_NtLockFile;
	if (func == pNtUnlockFile)
		return wine32a_NtUnlockFile;
	if (func == pNtCreateNamedPipeFile)
		return wine32a_NtCreateNamedPipeFile;
	if (func == pNtDeleteFile)
		return wine32a_NtDeleteFile;
	if (func == pNtCancelIoFileEx)
		return wine32a_NtCancelIoFileEx;
	if (func == pNtCancelIoFile)
		return wine32a_NtCancelIoFile;
	if (func == pNtCreateMailslotFile)
		return wine32a_NtCreateMailslotFile;
	if (func == pRtlInitializeHandleTable)
		return wine32a_RtlInitializeHandleTable;
	if (func == pRtlDestroyHandleTable)
		return wine32a_RtlDestroyHandleTable;
	if (func == pRtlAllocateHandle)
		return wine32a_RtlAllocateHandle;
	if (func == pRtlFreeHandle)
		return wine32a_RtlFreeHandle;
	if (func == pRtlIsValidHandle)
		return wine32a_RtlIsValidHandle;
	if (func == pRtlIsValidIndexHandle)
		return wine32a_RtlIsValidIndexHandle;
	if (func == pRtlCreateHeap)
		return wine32a_RtlCreateHeap;
	if (func == pRtlDestroyHeap)
		return wine32a_RtlDestroyHeap;
	if (func == pRtlAllocateHeap)
		return wine32a_RtlAllocateHeap;
	if (func == pRtlFreeHeap)
		return wine32a_RtlFreeHeap;
	if (func == pRtlReAllocateHeap)
		return wine32a_RtlReAllocateHeap;
	if (func == pRtlCompactHeap)
		return wine32a_RtlCompactHeap;
	if (func == pRtlLockHeap)
		return wine32a_RtlLockHeap;
	if (func == pRtlUnlockHeap)
		return wine32a_RtlUnlockHeap;
	if (func == pRtlSizeHeap)
		return wine32a_RtlSizeHeap;
	if (func == pRtlValidateHeap)
		return wine32a_RtlValidateHeap;
	if (func == pRtlWalkHeap)
		return wine32a_RtlWalkHeap;
	if (func == pRtlGetProcessHeaps)
		return wine32a_RtlGetProcessHeaps;
	if (func == pRtlQueryHeapInformation)
		return wine32a_RtlQueryHeapInformation;
	if (func == pRtlSetHeapInformation)
		return wine32a_RtlSetHeapInformation;
	if (func == pRtlLargeIntegerToChar)
		return wine32a_RtlLargeIntegerToChar;
	if (func == pRtlInt64ToUnicodeString)
		return wine32a_RtlInt64ToUnicodeString;
	if (func == pRtlGetUnloadEventTrace)
		return wine32a_RtlGetUnloadEventTrace;
	if (func == pRtlGetUnloadEventTraceEx)
		return wine32a_RtlGetUnloadEventTraceEx;
	if (func == pLdrDisableThreadCalloutsForDll)
		return wine32a_LdrDisableThreadCalloutsForDll;
	if (func == pLdrFindEntryForAddress)
		return wine32a_LdrFindEntryForAddress;
	if (func == pLdrEnumerateLoadedModules)
		return wine32a_LdrEnumerateLoadedModules;
	if (func == pLdrRegisterDllNotification)
		return wine32a_LdrRegisterDllNotification;
	if (func == pLdrUnregisterDllNotification)
		return wine32a_LdrUnregisterDllNotification;
	if (func == pLdrLockLoaderLock)
		return wine32a_LdrLockLoaderLock;
	if (func == pLdrUnlockLoaderLock)
		return wine32a_LdrUnlockLoaderLock;
	if (func == pLdrGetProcedureAddress)
		return wine32a_LdrGetProcedureAddress;
	if (func == pLdrLoadDll)
		return wine32a_LdrLoadDll;
	if (func == pLdrGetDllHandle)
		return wine32a_LdrGetDllHandle;
	if (func == pLdrAddRefDll)
		return wine32a_LdrAddRefDll;
	if (func == pLdrProcessRelocationBlock)
		return wine32a_LdrProcessRelocationBlock;
	if (func == pLdrQueryProcessModuleInformation)
		return wine32a_LdrQueryProcessModuleInformation;
	if (func == pLdrQueryImageFileExecutionOptions)
		return wine32a_LdrQueryImageFileExecutionOptions;
	if (func == pRtlDllShutdownInProgress)
		return wine32a_RtlDllShutdownInProgress;
	if (func == pLdrResolveDelayLoadedAPI)
		return wine32a_LdrResolveDelayLoadedAPI;
	if (func == pLdrShutdownProcess)
		return wine32a_LdrShutdownProcess;
	if (func == pRtlExitUserProcess)
		return wine32a_RtlExitUserProcess;
	if (func == pLdrShutdownThread)
		return wine32a_LdrShutdownThread;
	if (func == pLdrUnloadDll)
		return wine32a_LdrUnloadDll;
	if (func == pRtlImageNtHeader)
		return wine32a_RtlImageNtHeader;
	if (func == pLdrInitializeThunk)
		return wine32a_LdrInitializeThunk;
	if (func == pRtlImageDirectoryEntryToData)
		return wine32a_RtlImageDirectoryEntryToData;
	if (func == pRtlImageRvaToSection)
		return wine32a_RtlImageRvaToSection;
	if (func == pRtlImageRvaToVa)
		return wine32a_RtlImageRvaToVa;
	if (func == pRtlPcToFileHeader)
		return wine32a_RtlPcToFileHeader;
	if (func == pNtLoadDriver)
		return wine32a_NtLoadDriver;
	if (func == pNtUnloadDriver)
		return wine32a_NtUnloadDriver;
	if (func == p_lfind)
		return wine32a__lfind;
	if (func == pWinSqmEndSession)
		return wine32a_WinSqmEndSession;
	if (func == pWinSqmIncrementDWORD)
		return wine32a_WinSqmIncrementDWORD;
	if (func == pWinSqmIsOptedIn)
		return wine32a_WinSqmIsOptedIn;
	if (func == pWinSqmStartSession)
		return wine32a_WinSqmStartSession;
	if (func == pWinSqmSetDWORD)
		return wine32a_WinSqmSetDWORD;
	if (func == pEtwEventActivityIdControl)
		return wine32a_EtwEventActivityIdControl;
	if (func == pEtwEventProviderEnabled)
		return wine32a_EtwEventProviderEnabled;
	if (func == pEtwEventRegister)
		return wine32a_EtwEventRegister;
	if (func == pEtwEventUnregister)
		return wine32a_EtwEventUnregister;
	if (func == pEtwEventSetInformation)
		return wine32a_EtwEventSetInformation;
	if (func == pEtwEventWriteTransfer)
		return wine32a_EtwEventWriteTransfer;
	if (func == pEtwRegisterTraceGuidsW)
		return wine32a_EtwRegisterTraceGuidsW;
	if (func == pEtwRegisterTraceGuidsA)
		return wine32a_EtwRegisterTraceGuidsA;
	if (func == pEtwUnregisterTraceGuids)
		return wine32a_EtwUnregisterTraceGuids;
	if (func == pEtwEventEnabled)
		return wine32a_EtwEventEnabled;
	if (func == pEtwEventWrite)
		return wine32a_EtwEventWrite;
	if (func == pEtwGetTraceEnableFlags)
		return wine32a_EtwGetTraceEnableFlags;
	if (func == pEtwGetTraceEnableLevel)
		return wine32a_EtwGetTraceEnableLevel;
	if (func == pEtwGetTraceLoggerHandle)
		return wine32a_EtwGetTraceLoggerHandle;
	if (func == pEtwLogTraceEvent)
		return wine32a_EtwLogTraceEvent;
	if (func == pEtwTraceMessageVa)
		return wine32a_EtwTraceMessageVa;
	if (func == pEtwTraceMessage)
		return wine32a_EtwTraceMessage;
	if (func == pNtCreateLowBoxToken)
		return wine32a_NtCreateLowBoxToken;
	if (func == pApiSetQueryApiSetPresence)
		return wine32a_ApiSetQueryApiSetPresence;
	if (func == pNtDuplicateToken)
		return wine32a_NtDuplicateToken;
	if (func == pNtOpenProcessToken)
		return wine32a_NtOpenProcessToken;
	if (func == pNtOpenProcessTokenEx)
		return wine32a_NtOpenProcessTokenEx;
	if (func == pNtOpenThreadToken)
		return wine32a_NtOpenThreadToken;
	if (func == pNtOpenThreadTokenEx)
		return wine32a_NtOpenThreadTokenEx;
	if (func == pNtAdjustPrivilegesToken)
		return wine32a_NtAdjustPrivilegesToken;
	if (func == pNtQueryInformationToken)
		return wine32a_NtQueryInformationToken;
	if (func == pNtSetInformationToken)
		return wine32a_NtSetInformationToken;
	if (func == pNtAdjustGroupsToken)
		return wine32a_NtAdjustGroupsToken;
	if (func == pNtPrivilegeCheck)
		return wine32a_NtPrivilegeCheck;
	if (func == pNtCreatePort)
		return wine32a_NtCreatePort;
	if (func == pNtConnectPort)
		return wine32a_NtConnectPort;
	if (func == pNtSecureConnectPort)
		return wine32a_NtSecureConnectPort;
	if (func == pNtListenPort)
		return wine32a_NtListenPort;
	if (func == pNtAcceptConnectPort)
		return wine32a_NtAcceptConnectPort;
	if (func == pNtCompleteConnectPort)
		return wine32a_NtCompleteConnectPort;
	if (func == pNtRegisterThreadTerminatePort)
		return wine32a_NtRegisterThreadTerminatePort;
	if (func == pNtRequestWaitReplyPort)
		return wine32a_NtRequestWaitReplyPort;
	if (func == pNtReplyWaitReceivePort)
		return wine32a_NtReplyWaitReceivePort;
	if (func == pNtSetIntervalProfile)
		return wine32a_NtSetIntervalProfile;
	if (func == pRtlIsProcessorFeaturePresent)
		return wine32a_RtlIsProcessorFeaturePresent;
	if (func == pNtQuerySystemInformation)
		return wine32a_NtQuerySystemInformation;
	if (func == pNtQuerySystemInformationEx)
		return wine32a_NtQuerySystemInformationEx;
	if (func == pNtSetSystemInformation)
		return wine32a_NtSetSystemInformation;
	if (func == pNtCreatePagingFile)
		return wine32a_NtCreatePagingFile;
	if (func == pNtDisplayString)
		return wine32a_NtDisplayString;
	if (func == pNtInitiatePowerAction)
		return wine32a_NtInitiatePowerAction;
	if (func == pNtSetThreadExecutionState)
		return wine32a_NtSetThreadExecutionState;
	if (func == pNtCreatePowerRequest)
		return wine32a_NtCreatePowerRequest;
	if (func == pNtSetPowerRequest)
		return wine32a_NtSetPowerRequest;
	if (func == pNtClearPowerRequest)
		return wine32a_NtClearPowerRequest;
	if (func == pNtPowerInformation)
		return wine32a_NtPowerInformation;
	if (func == pNtShutdownSystem)
		return wine32a_NtShutdownSystem;
	if (func == pNtAllocateLocallyUniqueId)
		return wine32a_NtAllocateLocallyUniqueId;
	if (func == pVerSetConditionMask)
		return wine32a_VerSetConditionMask;
	if (func == pNtAccessCheckAndAuditAlarm)
		return wine32a_NtAccessCheckAndAuditAlarm;
	if (func == pNtSystemDebugControl)
		return wine32a_NtSystemDebugControl;
	if (func == pNtSetLdtEntries)
		return wine32a_NtSetLdtEntries;
	if (func == pNtQueryObject)
		return wine32a_NtQueryObject;
	if (func == pNtSetInformationObject)
		return wine32a_NtSetInformationObject;
	if (func == pNtQuerySecurityObject)
		return wine32a_NtQuerySecurityObject;
	if (func == pNtDuplicateObject)
		return wine32a_NtDuplicateObject;
	if (func == pNtClose)
		return wine32a_NtClose;
	if (func == pNtOpenDirectoryObject)
		return wine32a_NtOpenDirectoryObject;
	if (func == pNtCreateDirectoryObject)
		return wine32a_NtCreateDirectoryObject;
	if (func == pNtQueryDirectoryObject)
		return wine32a_NtQueryDirectoryObject;
	if (func == pNtOpenSymbolicLinkObject)
		return wine32a_NtOpenSymbolicLinkObject;
	if (func == pNtCreateSymbolicLinkObject)
		return wine32a_NtCreateSymbolicLinkObject;
	if (func == pNtQuerySymbolicLinkObject)
		return wine32a_NtQuerySymbolicLinkObject;
	if (func == pNtAllocateUuids)
		return wine32a_NtAllocateUuids;
	if (func == pNtMakeTemporaryObject)
		return wine32a_NtMakeTemporaryObject;
	if (func == pRtlDetermineDosPathNameType_U)
		return wine32a_RtlDetermineDosPathNameType_U;
	if (func == pRtlIsDosDeviceName_U)
		return wine32a_RtlIsDosDeviceName_U;
	if (func == pRtlDosPathNameToNtPathName_U_WithStatus)
		return wine32a_RtlDosPathNameToNtPathName_U_WithStatus;
	if (func == pRtlDosPathNameToNtPathName_U)
		return wine32a_RtlDosPathNameToNtPathName_U;
	if (func == pRtlDosPathNameToRelativeNtPathName_U_WithStatus)
		return wine32a_RtlDosPathNameToRelativeNtPathName_U_WithStatus;
	if (func == pRtlReleaseRelativeName)
		return wine32a_RtlReleaseRelativeName;
	if (func == pRtlDosSearchPath_U)
		return wine32a_RtlDosSearchPath_U;
	if (func == pRtlGetFullPathName_U)
		return wine32a_RtlGetFullPathName_U;
	if (func == pRtlGetLongestNtPathLength)
		return wine32a_RtlGetLongestNtPathLength;
	if (func == pRtlIsNameLegalDOS8Dot3)
		return wine32a_RtlIsNameLegalDOS8Dot3;
	if (func == pRtlGetCurrentDirectory_U)
		return wine32a_RtlGetCurrentDirectory_U;
	if (func == pRtlSetCurrentDirectory_U)
		return wine32a_RtlSetCurrentDirectory_U;
	if (func == pwine_unix_to_nt_file_name)
		return wine32a_wine_unix_to_nt_file_name;
	if (func == p_vsnprintf_s)
		return wine32a__vsnprintf_s;
	if (func == p_snprintf_s)
		return wine32a__snprintf_s;
	if (func == pNtTerminateProcess)
		return wine32a_NtTerminateProcess;
	if (func == pRtlGetCurrentPeb)
		return wine32a_RtlGetCurrentPeb;
	if (func == p__wine_make_process_system)
		return wine32a___wine_make_process_system;
	if (func == pNtQueryInformationProcess)
		return wine32a_NtQueryInformationProcess;
	if (func == pNtSetInformationProcess)
		return wine32a_NtSetInformationProcess;
	if (func == pNtFlushInstructionCache)
		return wine32a_NtFlushInstructionCache;
	if (func == pNtOpenProcess)
		return wine32a_NtOpenProcess;
	if (func == pNtResumeProcess)
		return wine32a_NtResumeProcess;
	if (func == pNtSuspendProcess)
		return wine32a_NtSuspendProcess;
	if (func == pRtlCreateUserProcess)
		return wine32a_RtlCreateUserProcess;
	if (func == pDbgUiRemoteBreakin)
		return wine32a_DbgUiRemoteBreakin;
	if (func == pDbgUiIssueRemoteBreakin)
		return wine32a_DbgUiIssueRemoteBreakin;
	if (func == pNtCreateKey)
		return wine32a_NtCreateKey;
	if (func == pNtCreateKeyTransacted)
		return wine32a_NtCreateKeyTransacted;
	if (func == pNtRenameKey)
		return wine32a_NtRenameKey;
	if (func == pRtlpNtCreateKey)
		return wine32a_RtlpNtCreateKey;
	if (func == pNtOpenKeyEx)
		return wine32a_NtOpenKeyEx;
	if (func == pNtOpenKey)
		return wine32a_NtOpenKey;
	if (func == pNtOpenKeyTransactedEx)
		return wine32a_NtOpenKeyTransactedEx;
	if (func == pNtOpenKeyTransacted)
		return wine32a_NtOpenKeyTransacted;
	if (func == pRtlpNtOpenKey)
		return wine32a_RtlpNtOpenKey;
	if (func == pNtDeleteKey)
		return wine32a_NtDeleteKey;
	if (func == pRtlpNtMakeTemporaryKey)
		return wine32a_RtlpNtMakeTemporaryKey;
	if (func == pNtDeleteValueKey)
		return wine32a_NtDeleteValueKey;
	if (func == pNtEnumerateKey)
		return wine32a_NtEnumerateKey;
	if (func == pRtlpNtEnumerateSubKey)
		return wine32a_RtlpNtEnumerateSubKey;
	if (func == pNtQueryKey)
		return wine32a_NtQueryKey;
	if (func == pNtEnumerateValueKey)
		return wine32a_NtEnumerateValueKey;
	if (func == pNtQueryValueKey)
		return wine32a_NtQueryValueKey;
	if (func == pRtlpNtQueryValueKey)
		return wine32a_RtlpNtQueryValueKey;
	if (func == pNtFlushKey)
		return wine32a_NtFlushKey;
	if (func == pNtLoadKey)
		return wine32a_NtLoadKey;
	if (func == pNtLoadKey2)
		return wine32a_NtLoadKey2;
	if (func == pNtNotifyChangeMultipleKeys)
		return wine32a_NtNotifyChangeMultipleKeys;
	if (func == pNtNotifyChangeKey)
		return wine32a_NtNotifyChangeKey;
	if (func == pNtQueryMultipleValueKey)
		return wine32a_NtQueryMultipleValueKey;
	if (func == pNtReplaceKey)
		return wine32a_NtReplaceKey;
	if (func == pNtRestoreKey)
		return wine32a_NtRestoreKey;
	if (func == pNtSaveKey)
		return wine32a_NtSaveKey;
	if (func == pNtSetInformationKey)
		return wine32a_NtSetInformationKey;
	if (func == pNtSetValueKey)
		return wine32a_NtSetValueKey;
	if (func == pRtlpNtSetValueKey)
		return wine32a_RtlpNtSetValueKey;
	if (func == pNtUnloadKey)
		return wine32a_NtUnloadKey;
	if (func == pRtlFormatCurrentUserKeyPath)
		return wine32a_RtlFormatCurrentUserKeyPath;
	if (func == pRtlOpenCurrentUser)
		return wine32a_RtlOpenCurrentUser;
	if (func == pRtlQueryRegistryValues)
		return wine32a_RtlQueryRegistryValues;
	if (func == pRtlCheckRegistryKey)
		return wine32a_RtlCheckRegistryKey;
	if (func == pRtlCreateRegistryKey)
		return wine32a_RtlCreateRegistryKey;
	if (func == pRtlDeleteRegistryValue)
		return wine32a_RtlDeleteRegistryValue;
	if (func == pRtlWriteRegistryValue)
		return wine32a_RtlWriteRegistryValue;
	if (func == pNtQueryLicenseValue)
		return wine32a_NtQueryLicenseValue;
	if (func == pLdrFindResourceDirectory_U)
		return wine32a_LdrFindResourceDirectory_U;
	if (func == pLdrFindResource_U)
		return wine32a_LdrFindResource_U;
	if (func == pLdrAccessResource)
		return wine32a_LdrAccessResource;
	if (func == pRtlFindMessage)
		return wine32a_RtlFindMessage;
	if (func == pRtlFormatMessage)
		return wine32a_RtlFormatMessage;
	if (func == pNtQueryDefaultLocale)
		return wine32a_NtQueryDefaultLocale;
	if (func == pNtSetDefaultLocale)
		return wine32a_NtSetDefaultLocale;
	if (func == pNtQueryDefaultUILanguage)
		return wine32a_NtQueryDefaultUILanguage;
	if (func == pNtSetDefaultUILanguage)
		return wine32a_NtSetDefaultUILanguage;
	if (func == pNtQueryInstallUILanguage)
		return wine32a_NtQueryInstallUILanguage;
	if (func == pRtlInitializeResource)
		return wine32a_RtlInitializeResource;
	if (func == pRtlDeleteResource)
		return wine32a_RtlDeleteResource;
	if (func == pRtlAcquireResourceExclusive)
		return wine32a_RtlAcquireResourceExclusive;
	if (func == pRtlAcquireResourceShared)
		return wine32a_RtlAcquireResourceShared;
	if (func == pRtlReleaseResource)
		return wine32a_RtlReleaseResource;
	if (func == pRtlDumpResource)
		return wine32a_RtlDumpResource;
	if (func == pDbgPrint)
		return wine32a_DbgPrint;
	if (func == pDbgPrintEx)
		return wine32a_DbgPrintEx;
	if (func == pvDbgPrintEx)
		return wine32a_vDbgPrintEx;
	if (func == pvDbgPrintExWithPrefix)
		return wine32a_vDbgPrintExWithPrefix;
	if (func == pRtlAcquirePebLock)
		return wine32a_RtlAcquirePebLock;
	if (func == pRtlReleasePebLock)
		return wine32a_RtlReleasePebLock;
	if (func == pRtlNewSecurityObject)
		return wine32a_RtlNewSecurityObject;
	if (func == pRtlDeleteSecurityObject)
		return wine32a_RtlDeleteSecurityObject;
	if (func == pRtlInitializeGenericTable)
		return wine32a_RtlInitializeGenericTable;
	if (func == pRtlEnumerateGenericTableWithoutSplaying)
		return wine32a_RtlEnumerateGenericTableWithoutSplaying;
	if (func == pRtlNumberGenericTableElements)
		return wine32a_RtlNumberGenericTableElements;
	if (func == pRtlMoveMemory)
		return wine32a_RtlMoveMemory;
	if (func == pRtlFillMemory)
		return wine32a_RtlFillMemory;
	if (func == pRtlZeroMemory)
		return wine32a_RtlZeroMemory;
	if (func == pRtlCompareMemory)
		return wine32a_RtlCompareMemory;
	if (func == pRtlCompareMemoryUlong)
		return wine32a_RtlCompareMemoryUlong;
	if (func == pRtlCopyMemory)
		return wine32a_RtlCopyMemory;
	if (func == pRtlAssert)
		return wine32a_RtlAssert;
	if (func == pRtlFillMemoryUlong)
		return wine32a_RtlFillMemoryUlong;
	if (func == pRtlComputeCrc32)
		return wine32a_RtlComputeCrc32;
	if (func == pRtlUlonglongByteSwap)
		return wine32a_RtlUlonglongByteSwap;
	if (func == pRtlUniform)
		return wine32a_RtlUniform;
	if (func == pRtlRandom)
		return wine32a_RtlRandom;
	if (func == pRtlRandomEx)
		return wine32a_RtlRandomEx;
	if (func == pRtlAreAllAccessesGranted)
		return wine32a_RtlAreAllAccessesGranted;
	if (func == pRtlAreAnyAccessesGranted)
		return wine32a_RtlAreAnyAccessesGranted;
	if (func == pRtlMapGenericMask)
		return wine32a_RtlMapGenericMask;
	if (func == pRtlCopyLuid)
		return wine32a_RtlCopyLuid;
	if (func == pRtlEqualLuid)
		return wine32a_RtlEqualLuid;
	if (func == pRtlCopyLuidAndAttributesArray)
		return wine32a_RtlCopyLuidAndAttributesArray;
	if (func == pRtlIpv4StringToAddressExW)
		return wine32a_RtlIpv4StringToAddressExW;
	if (func == pRtlIpv4StringToAddressW)
		return wine32a_RtlIpv4StringToAddressW;
	if (func == pRtlIpv6StringToAddressExW)
		return wine32a_RtlIpv6StringToAddressExW;
	if (func == pRtlIpv4AddressToStringExW)
		return wine32a_RtlIpv4AddressToStringExW;
	if (func == pRtlIpv4AddressToStringExA)
		return wine32a_RtlIpv4AddressToStringExA;
	if (func == pRtlIpv4AddressToStringW)
		return wine32a_RtlIpv4AddressToStringW;
	if (func == pRtlIpv4AddressToStringA)
		return wine32a_RtlIpv4AddressToStringA;
	if (func == pRtlEncodePointer)
		return wine32a_RtlEncodePointer;
	if (func == pRtlDecodePointer)
		return wine32a_RtlDecodePointer;
	if (func == pRtlInitializeSListHead)
		return wine32a_RtlInitializeSListHead;
	if (func == pRtlQueryDepthSList)
		return wine32a_RtlQueryDepthSList;
	if (func == pRtlFirstEntrySList)
		return wine32a_RtlFirstEntrySList;
	if (func == pRtlInterlockedFlushSList)
		return wine32a_RtlInterlockedFlushSList;
	if (func == pRtlInterlockedPushEntrySList)
		return wine32a_RtlInterlockedPushEntrySList;
	if (func == pRtlInterlockedPopEntrySList)
		return wine32a_RtlInterlockedPopEntrySList;
	if (func == pRtlInterlockedPushListSListEx)
		return wine32a_RtlInterlockedPushListSListEx;
	if (func == pRtlInterlockedPushListSList)
		return wine32a_RtlInterlockedPushListSList;
	if (func == pRtlGetCompressionWorkSpaceSize)
		return wine32a_RtlGetCompressionWorkSpaceSize;
	if (func == pRtlCompressBuffer)
		return wine32a_RtlCompressBuffer;
	if (func == pRtlDecompressFragment)
		return wine32a_RtlDecompressFragment;
	if (func == pRtlDecompressBuffer)
		return wine32a_RtlDecompressBuffer;
	if (func == pRtlSetThreadErrorMode)
		return wine32a_RtlSetThreadErrorMode;
	if (func == pRtlGetThreadErrorMode)
		return wine32a_RtlGetThreadErrorMode;
	if (func == pRtlGetCurrentTransaction)
		return wine32a_RtlGetCurrentTransaction;
	if (func == pRtlSetCurrentTransaction)
		return wine32a_RtlSetCurrentTransaction;
	if (func == pRtlGetCurrentProcessorNumberEx)
		return wine32a_RtlGetCurrentProcessorNumberEx;
	if (func == pRtlInitializeGenericTableAvl)
		return wine32a_RtlInitializeGenericTableAvl;
	if (func == pRtlInsertElementGenericTableAvl)
		return wine32a_RtlInsertElementGenericTableAvl;
	if (func == pRtlQueryPackageIdentity)
		return wine32a_RtlQueryPackageIdentity;
	if (func == pRtlInitializeBitMap)
		return wine32a_RtlInitializeBitMap;
	if (func == pRtlSetAllBits)
		return wine32a_RtlSetAllBits;
	if (func == pRtlClearAllBits)
		return wine32a_RtlClearAllBits;
	if (func == pRtlSetBits)
		return wine32a_RtlSetBits;
	if (func == pRtlClearBits)
		return wine32a_RtlClearBits;
	if (func == pRtlAreBitsSet)
		return wine32a_RtlAreBitsSet;
	if (func == pRtlAreBitsClear)
		return wine32a_RtlAreBitsClear;
	if (func == pRtlFindSetBits)
		return wine32a_RtlFindSetBits;
	if (func == pRtlFindClearBits)
		return wine32a_RtlFindClearBits;
	if (func == pRtlFindSetBitsAndClear)
		return wine32a_RtlFindSetBitsAndClear;
	if (func == pRtlFindClearBitsAndSet)
		return wine32a_RtlFindClearBitsAndSet;
	if (func == pRtlNumberOfSetBits)
		return wine32a_RtlNumberOfSetBits;
	if (func == pRtlNumberOfClearBits)
		return wine32a_RtlNumberOfClearBits;
	if (func == pRtlFindMostSignificantBit)
		return wine32a_RtlFindMostSignificantBit;
	if (func == pRtlFindLeastSignificantBit)
		return wine32a_RtlFindLeastSignificantBit;
	if (func == pRtlFindNextForwardRunSet)
		return wine32a_RtlFindNextForwardRunSet;
	if (func == pRtlFindNextForwardRunClear)
		return wine32a_RtlFindNextForwardRunClear;
	if (func == pRtlFindLastBackwardRunSet)
		return wine32a_RtlFindLastBackwardRunSet;
	if (func == pRtlFindLastBackwardRunClear)
		return wine32a_RtlFindLastBackwardRunClear;
	if (func == pRtlFindSetRuns)
		return wine32a_RtlFindSetRuns;
	if (func == pRtlFindClearRuns)
		return wine32a_RtlFindClearRuns;
	if (func == pRtlFindLongestRunSet)
		return wine32a_RtlFindLongestRunSet;
	if (func == pRtlFindLongestRunClear)
		return wine32a_RtlFindLongestRunClear;
	if (func == p__wine_init_codepages)
		return wine32a___wine_init_codepages;
	if (func == pRtlInitAnsiString)
		return wine32a_RtlInitAnsiString;
	if (func == pRtlInitAnsiStringEx)
		return wine32a_RtlInitAnsiStringEx;
	if (func == pRtlInitString)
		return wine32a_RtlInitString;
	if (func == pRtlFreeAnsiString)
		return wine32a_RtlFreeAnsiString;
	if (func == pRtlFreeOemString)
		return wine32a_RtlFreeOemString;
	if (func == pRtlCopyString)
		return wine32a_RtlCopyString;
	if (func == pRtlInitUnicodeString)
		return wine32a_RtlInitUnicodeString;
	if (func == pRtlInitUnicodeStringEx)
		return wine32a_RtlInitUnicodeStringEx;
	if (func == pRtlCreateUnicodeString)
		return wine32a_RtlCreateUnicodeString;
	if (func == pRtlCreateUnicodeStringFromAsciiz)
		return wine32a_RtlCreateUnicodeStringFromAsciiz;
	if (func == pRtlFreeUnicodeString)
		return wine32a_RtlFreeUnicodeString;
	if (func == pRtlCopyUnicodeString)
		return wine32a_RtlCopyUnicodeString;
	if (func == pRtlDuplicateUnicodeString)
		return wine32a_RtlDuplicateUnicodeString;
	if (func == pRtlEraseUnicodeString)
		return wine32a_RtlEraseUnicodeString;
	if (func == pRtlCompareString)
		return wine32a_RtlCompareString;
	if (func == pRtlCompareUnicodeStrings)
		return wine32a_RtlCompareUnicodeStrings;
	if (func == pRtlCompareUnicodeString)
		return wine32a_RtlCompareUnicodeString;
	if (func == pRtlEqualString)
		return wine32a_RtlEqualString;
	if (func == pRtlEqualUnicodeString)
		return wine32a_RtlEqualUnicodeString;
	if (func == pRtlPrefixString)
		return wine32a_RtlPrefixString;
	if (func == pRtlPrefixUnicodeString)
		return wine32a_RtlPrefixUnicodeString;
	if (func == pRtlEqualComputerName)
		return wine32a_RtlEqualComputerName;
	if (func == pRtlEqualDomainName)
		return wine32a_RtlEqualDomainName;
	if (func == pRtlAnsiCharToUnicodeChar)
		return wine32a_RtlAnsiCharToUnicodeChar;
	if (func == pRtlAnsiStringToUnicodeString)
		return wine32a_RtlAnsiStringToUnicodeString;
	if (func == pRtlOemStringToUnicodeString)
		return wine32a_RtlOemStringToUnicodeString;
	if (func == pRtlUnicodeStringToAnsiString)
		return wine32a_RtlUnicodeStringToAnsiString;
	if (func == pRtlUnicodeStringToOemString)
		return wine32a_RtlUnicodeStringToOemString;
	if (func == pRtlMultiByteToUnicodeN)
		return wine32a_RtlMultiByteToUnicodeN;
	if (func == pRtlOemToUnicodeN)
		return wine32a_RtlOemToUnicodeN;
	if (func == pRtlUnicodeToMultiByteN)
		return wine32a_RtlUnicodeToMultiByteN;
	if (func == pRtlUnicodeToOemN)
		return wine32a_RtlUnicodeToOemN;
	if (func == pRtlUpperChar)
		return wine32a_RtlUpperChar;
	if (func == pRtlUpperString)
		return wine32a_RtlUpperString;
	if (func == pRtlUpcaseUnicodeChar)
		return wine32a_RtlUpcaseUnicodeChar;
	if (func == pRtlDowncaseUnicodeChar)
		return wine32a_RtlDowncaseUnicodeChar;
	if (func == pRtlUpcaseUnicodeString)
		return wine32a_RtlUpcaseUnicodeString;
	if (func == pRtlDowncaseUnicodeString)
		return wine32a_RtlDowncaseUnicodeString;
	if (func == pRtlUpcaseUnicodeStringToAnsiString)
		return wine32a_RtlUpcaseUnicodeStringToAnsiString;
	if (func == pRtlUpcaseUnicodeStringToOemString)
		return wine32a_RtlUpcaseUnicodeStringToOemString;
	if (func == pRtlUpcaseUnicodeStringToCountedOemString)
		return wine32a_RtlUpcaseUnicodeStringToCountedOemString;
	if (func == pRtlUpcaseUnicodeToMultiByteN)
		return wine32a_RtlUpcaseUnicodeToMultiByteN;
	if (func == pRtlUpcaseUnicodeToOemN)
		return wine32a_RtlUpcaseUnicodeToOemN;
	if (func == pRtlOemStringToUnicodeSize)
		return wine32a_RtlOemStringToUnicodeSize;
	if (func == pRtlAnsiStringToUnicodeSize)
		return wine32a_RtlAnsiStringToUnicodeSize;
	if (func == pRtlMultiByteToUnicodeSize)
		return wine32a_RtlMultiByteToUnicodeSize;
	if (func == pRtlUnicodeToMultiByteSize)
		return wine32a_RtlUnicodeToMultiByteSize;
	if (func == pRtlUnicodeStringToAnsiSize)
		return wine32a_RtlUnicodeStringToAnsiSize;
	if (func == pRtlUnicodeStringToOemSize)
		return wine32a_RtlUnicodeStringToOemSize;
	if (func == pRtlAppendAsciizToString)
		return wine32a_RtlAppendAsciizToString;
	if (func == pRtlAppendStringToString)
		return wine32a_RtlAppendStringToString;
	if (func == pRtlAppendUnicodeToString)
		return wine32a_RtlAppendUnicodeToString;
	if (func == pRtlAppendUnicodeStringToString)
		return wine32a_RtlAppendUnicodeStringToString;
	if (func == pRtlFindCharInUnicodeString)
		return wine32a_RtlFindCharInUnicodeString;
	if (func == pRtlIsTextUnicode)
		return wine32a_RtlIsTextUnicode;
	if (func == pRtlCharToInteger)
		return wine32a_RtlCharToInteger;
	if (func == pRtlIntegerToChar)
		return wine32a_RtlIntegerToChar;
	if (func == pRtlUnicodeStringToInteger)
		return wine32a_RtlUnicodeStringToInteger;
	if (func == pRtlIntegerToUnicodeString)
		return wine32a_RtlIntegerToUnicodeString;
	if (func == pRtlGUIDFromString)
		return wine32a_RtlGUIDFromString;
	if (func == pRtlStringFromGUID)
		return wine32a_RtlStringFromGUID;
	if (func == pRtlHashUnicodeString)
		return wine32a_RtlHashUnicodeString;
	if (func == pRtlAllocateAndInitializeSid)
		return wine32a_RtlAllocateAndInitializeSid;
	if (func == pRtlEqualSid)
		return wine32a_RtlEqualSid;
	if (func == pRtlEqualPrefixSid)
		return wine32a_RtlEqualPrefixSid;
	if (func == pRtlFreeSid)
		return wine32a_RtlFreeSid;
	if (func == pRtlLengthRequiredSid)
		return wine32a_RtlLengthRequiredSid;
	if (func == pRtlLengthSid)
		return wine32a_RtlLengthSid;
	if (func == pRtlInitializeSid)
		return wine32a_RtlInitializeSid;
	if (func == pRtlSubAuthoritySid)
		return wine32a_RtlSubAuthoritySid;
	if (func == pRtlIdentifierAuthoritySid)
		return wine32a_RtlIdentifierAuthoritySid;
	if (func == pRtlSubAuthorityCountSid)
		return wine32a_RtlSubAuthorityCountSid;
	if (func == pRtlCopySid)
		return wine32a_RtlCopySid;
	if (func == pRtlValidSid)
		return wine32a_RtlValidSid;
	if (func == pRtlCreateSecurityDescriptor)
		return wine32a_RtlCreateSecurityDescriptor;
	if (func == pRtlCopySecurityDescriptor)
		return wine32a_RtlCopySecurityDescriptor;
	if (func == pRtlValidSecurityDescriptor)
		return wine32a_RtlValidSecurityDescriptor;
	if (func == pRtlValidRelativeSecurityDescriptor)
		return wine32a_RtlValidRelativeSecurityDescriptor;
	if (func == pRtlLengthSecurityDescriptor)
		return wine32a_RtlLengthSecurityDescriptor;
	if (func == pRtlGetDaclSecurityDescriptor)
		return wine32a_RtlGetDaclSecurityDescriptor;
	if (func == pRtlSetDaclSecurityDescriptor)
		return wine32a_RtlSetDaclSecurityDescriptor;
	if (func == pRtlGetSaclSecurityDescriptor)
		return wine32a_RtlGetSaclSecurityDescriptor;
	if (func == pRtlSetSaclSecurityDescriptor)
		return wine32a_RtlSetSaclSecurityDescriptor;
	if (func == pRtlGetOwnerSecurityDescriptor)
		return wine32a_RtlGetOwnerSecurityDescriptor;
	if (func == pRtlSetOwnerSecurityDescriptor)
		return wine32a_RtlSetOwnerSecurityDescriptor;
	if (func == pRtlSetGroupSecurityDescriptor)
		return wine32a_RtlSetGroupSecurityDescriptor;
	if (func == pRtlGetGroupSecurityDescriptor)
		return wine32a_RtlGetGroupSecurityDescriptor;
	if (func == pRtlMakeSelfRelativeSD)
		return wine32a_RtlMakeSelfRelativeSD;
	if (func == pRtlSelfRelativeToAbsoluteSD)
		return wine32a_RtlSelfRelativeToAbsoluteSD;
	if (func == pRtlGetControlSecurityDescriptor)
		return wine32a_RtlGetControlSecurityDescriptor;
	if (func == pRtlSetControlSecurityDescriptor)
		return wine32a_RtlSetControlSecurityDescriptor;
	if (func == pRtlAbsoluteToSelfRelativeSD)
		return wine32a_RtlAbsoluteToSelfRelativeSD;
	if (func == pRtlCreateAcl)
		return wine32a_RtlCreateAcl;
	if (func == pRtlFirstFreeAce)
		return wine32a_RtlFirstFreeAce;
	if (func == pRtlAddAce)
		return wine32a_RtlAddAce;
	if (func == pRtlDeleteAce)
		return wine32a_RtlDeleteAce;
	if (func == pRtlAddAccessAllowedAce)
		return wine32a_RtlAddAccessAllowedAce;
	if (func == pRtlAddAccessAllowedAceEx)
		return wine32a_RtlAddAccessAllowedAceEx;
	if (func == pRtlAddAccessAllowedObjectAce)
		return wine32a_RtlAddAccessAllowedObjectAce;
	if (func == pRtlAddAccessDeniedAce)
		return wine32a_RtlAddAccessDeniedAce;
	if (func == pRtlAddAccessDeniedAceEx)
		return wine32a_RtlAddAccessDeniedAceEx;
	if (func == pRtlAddAccessDeniedObjectAce)
		return wine32a_RtlAddAccessDeniedObjectAce;
	if (func == pRtlAddAuditAccessAceEx)
		return wine32a_RtlAddAuditAccessAceEx;
	if (func == pRtlAddAuditAccessAce)
		return wine32a_RtlAddAuditAccessAce;
	if (func == pRtlAddAuditAccessObjectAce)
		return wine32a_RtlAddAuditAccessObjectAce;
	if (func == pRtlAddMandatoryAce)
		return wine32a_RtlAddMandatoryAce;
	if (func == pRtlValidAcl)
		return wine32a_RtlValidAcl;
	if (func == pRtlGetAce)
		return wine32a_RtlGetAce;
	if (func == pRtlAdjustPrivilege)
		return wine32a_RtlAdjustPrivilege;
	if (func == pRtlImpersonateSelf)
		return wine32a_RtlImpersonateSelf;
	if (func == pNtImpersonateAnonymousToken)
		return wine32a_NtImpersonateAnonymousToken;
	if (func == pNtAccessCheck)
		return wine32a_NtAccessCheck;
	if (func == pNtSetSecurityObject)
		return wine32a_NtSetSecurityObject;
	if (func == pRtlConvertSidToUnicodeString)
		return wine32a_RtlConvertSidToUnicodeString;
	if (func == pRtlQueryInformationAcl)
		return wine32a_RtlQueryInformationAcl;
	if (func == pRtlConvertToAutoInheritSecurityObject)
		return wine32a_RtlConvertToAutoInheritSecurityObject;
	if (func == pwine_server_call)
		return wine32a_wine_server_call;
	if (func == pwine_server_send_fd)
		return wine32a_wine_server_send_fd;
	if (func == pwine_server_fd_to_handle)
		return wine32a_wine_server_fd_to_handle;
	if (func == pwine_server_handle_to_fd)
		return wine32a_wine_server_handle_to_fd;
	if (func == pwine_server_release_fd)
		return wine32a_wine_server_release_fd;
	if (func == pNtSetContextThread)
		return wine32a_NtSetContextThread;
	if (func == pNtGetContextThread)
		return wine32a_NtGetContextThread;
	if (func == pRtlWow64GetThreadContext)
		return wine32a_RtlWow64GetThreadContext;
	if (func == pRtlWow64SetThreadContext)
		return wine32a_RtlWow64SetThreadContext;
	if (func == pNtRaiseException)
		return wine32a_NtRaiseException;
	if (func == p__wine_set_signal_handler)
		return wine32a___wine_set_signal_handler;
	if (func == pRtlVirtualUnwind)
		return wine32a_RtlVirtualUnwind;
	if (func == pRtlRestoreContext)
		return wine32a_RtlRestoreContext;
	if (func == pRtlUnwindEx)
		return wine32a_RtlUnwindEx;
	if (func == pRtlUnwind)
		return wine32a_RtlUnwind;
	if (func == p_local_unwind)
		return wine32a__local_unwind;
	if (func == p__C_specific_handler)
		return wine32a___C_specific_handler;
	if (func == pRtlCaptureStackBackTrace)
		return wine32a_RtlCaptureStackBackTrace;
	if (func == p_memccpy)
		return wine32a__memccpy;
	if (func == p_memicmp)
		return wine32a__memicmp;
	if (func == p_strnicmp)
		return wine32a__strnicmp;
	if (func == p_stricmp)
		return wine32a__stricmp;
	if (func == p_strupr)
		return wine32a__strupr;
	if (func == p_strlwr)
		return wine32a__strlwr;
	if (func == p_ultoa)
		return wine32a__ultoa;
	if (func == p_ltoa)
		return wine32a__ltoa;
	if (func == p_itoa)
		return wine32a__itoa;
	if (func == p_ui64toa)
		return wine32a__ui64toa;
	if (func == p_i64toa)
		return wine32a__i64toa;
	if (func == p_atoi64)
		return wine32a__atoi64;
	if (func == p_splitpath)
		return wine32a__splitpath;
	if (func == pNtCreateSemaphore)
		return wine32a_NtCreateSemaphore;
	if (func == pNtOpenSemaphore)
		return wine32a_NtOpenSemaphore;
	if (func == pNtQuerySemaphore)
		return wine32a_NtQuerySemaphore;
	if (func == pNtReleaseSemaphore)
		return wine32a_NtReleaseSemaphore;
	if (func == pNtCreateEvent)
		return wine32a_NtCreateEvent;
	if (func == pNtOpenEvent)
		return wine32a_NtOpenEvent;
	if (func == pNtSetEvent)
		return wine32a_NtSetEvent;
	if (func == pNtResetEvent)
		return wine32a_NtResetEvent;
	if (func == pNtClearEvent)
		return wine32a_NtClearEvent;
	if (func == pNtPulseEvent)
		return wine32a_NtPulseEvent;
	if (func == pNtQueryEvent)
		return wine32a_NtQueryEvent;
	if (func == pNtCreateMutant)
		return wine32a_NtCreateMutant;
	if (func == pNtOpenMutant)
		return wine32a_NtOpenMutant;
	if (func == pNtReleaseMutant)
		return wine32a_NtReleaseMutant;
	if (func == pNtQueryMutant)
		return wine32a_NtQueryMutant;
	if (func == pNtCreateJobObject)
		return wine32a_NtCreateJobObject;
	if (func == pNtOpenJobObject)
		return wine32a_NtOpenJobObject;
	if (func == pNtTerminateJobObject)
		return wine32a_NtTerminateJobObject;
	if (func == pNtQueryInformationJobObject)
		return wine32a_NtQueryInformationJobObject;
	if (func == pNtSetInformationJobObject)
		return wine32a_NtSetInformationJobObject;
	if (func == pNtIsProcessInJob)
		return wine32a_NtIsProcessInJob;
	if (func == pNtAssignProcessToJobObject)
		return wine32a_NtAssignProcessToJobObject;
	if (func == pNtCreateTimer)
		return wine32a_NtCreateTimer;
	if (func == pNtOpenTimer)
		return wine32a_NtOpenTimer;
	if (func == pNtSetTimer)
		return wine32a_NtSetTimer;
	if (func == pNtCancelTimer)
		return wine32a_NtCancelTimer;
	if (func == pNtQueryTimer)
		return wine32a_NtQueryTimer;
	if (func == pNtQueryTimerResolution)
		return wine32a_NtQueryTimerResolution;
	if (func == pNtSetTimerResolution)
		return wine32a_NtSetTimerResolution;
	if (func == pNtWaitForMultipleObjects)
		return wine32a_NtWaitForMultipleObjects;
	if (func == pNtWaitForSingleObject)
		return wine32a_NtWaitForSingleObject;
	if (func == pNtSignalAndWaitForSingleObject)
		return wine32a_NtSignalAndWaitForSingleObject;
	if (func == pNtYieldExecution)
		return wine32a_NtYieldExecution;
	if (func == pNtDelayExecution)
		return wine32a_NtDelayExecution;
	if (func == pNtCreateKeyedEvent)
		return wine32a_NtCreateKeyedEvent;
	if (func == pNtOpenKeyedEvent)
		return wine32a_NtOpenKeyedEvent;
	if (func == pNtWaitForKeyedEvent)
		return wine32a_NtWaitForKeyedEvent;
	if (func == pNtReleaseKeyedEvent)
		return wine32a_NtReleaseKeyedEvent;
	if (func == pNtCreateIoCompletion)
		return wine32a_NtCreateIoCompletion;
	if (func == pNtSetIoCompletion)
		return wine32a_NtSetIoCompletion;
	if (func == pNtRemoveIoCompletion)
		return wine32a_NtRemoveIoCompletion;
	if (func == pNtRemoveIoCompletionEx)
		return wine32a_NtRemoveIoCompletionEx;
	if (func == pNtOpenIoCompletion)
		return wine32a_NtOpenIoCompletion;
	if (func == pNtQueryIoCompletion)
		return wine32a_NtQueryIoCompletion;
	if (func == pRtlRunOnceInitialize)
		return wine32a_RtlRunOnceInitialize;
	if (func == pRtlRunOnceBeginInitialize)
		return wine32a_RtlRunOnceBeginInitialize;
	if (func == pRtlRunOnceComplete)
		return wine32a_RtlRunOnceComplete;
	if (func == pRtlRunOnceExecuteOnce)
		return wine32a_RtlRunOnceExecuteOnce;
	if (func == pRtlInitializeSRWLock)
		return wine32a_RtlInitializeSRWLock;
	if (func == pRtlAcquireSRWLockExclusive)
		return wine32a_RtlAcquireSRWLockExclusive;
	if (func == pRtlAcquireSRWLockShared)
		return wine32a_RtlAcquireSRWLockShared;
	if (func == pRtlReleaseSRWLockExclusive)
		return wine32a_RtlReleaseSRWLockExclusive;
	if (func == pRtlReleaseSRWLockShared)
		return wine32a_RtlReleaseSRWLockShared;
	if (func == pRtlTryAcquireSRWLockExclusive)
		return wine32a_RtlTryAcquireSRWLockExclusive;
	if (func == pRtlTryAcquireSRWLockShared)
		return wine32a_RtlTryAcquireSRWLockShared;
	if (func == pRtlInitializeConditionVariable)
		return wine32a_RtlInitializeConditionVariable;
	if (func == pRtlWakeConditionVariable)
		return wine32a_RtlWakeConditionVariable;
	if (func == pRtlWakeAllConditionVariable)
		return wine32a_RtlWakeAllConditionVariable;
	if (func == pRtlSleepConditionVariableCS)
		return wine32a_RtlSleepConditionVariableCS;
	if (func == pRtlSleepConditionVariableSRW)
		return wine32a_RtlSleepConditionVariableSRW;
	if (func == pRtlWaitOnAddress)
		return wine32a_RtlWaitOnAddress;
	if (func == pRtlWakeAddressAll)
		return wine32a_RtlWakeAddressAll;
	if (func == pRtlWakeAddressSingle)
		return wine32a_RtlWakeAddressSingle;
	if (func == pRtlExitUserThread)
		return wine32a_RtlExitUserThread;
	if (func == pNtCreateThreadEx)
		return wine32a_NtCreateThreadEx;
	if (func == pRtlCreateUserThread)
		return wine32a_RtlCreateUserThread;
	if (func == pRtlGetNtGlobalFlags)
		return wine32a_RtlGetNtGlobalFlags;
	if (func == pNtOpenThread)
		return wine32a_NtOpenThread;
	if (func == pNtSuspendThread)
		return wine32a_NtSuspendThread;
	if (func == pNtResumeThread)
		return wine32a_NtResumeThread;
	if (func == pNtAlertResumeThread)
		return wine32a_NtAlertResumeThread;
	if (func == pNtAlertThread)
		return wine32a_NtAlertThread;
	if (func == pNtTerminateThread)
		return wine32a_NtTerminateThread;
	if (func == pNtQueueApcThread)
		return wine32a_NtQueueApcThread;
	if (func == pRtlPushFrame)
		return wine32a_RtlPushFrame;
	if (func == pRtlPopFrame)
		return wine32a_RtlPopFrame;
	if (func == pRtlGetFrame)
		return wine32a_RtlGetFrame;
	if (func == pNtQueryInformationThread)
		return wine32a_NtQueryInformationThread;
	if (func == pNtSetInformationThread)
		return wine32a_NtSetInformationThread;
	if (func == pNtGetCurrentProcessorNumber)
		return wine32a_NtGetCurrentProcessorNumber;
	if (func == pRtlQueueWorkItem)
		return wine32a_RtlQueueWorkItem;
	if (func == pRtlSetIoCompletionCallback)
		return wine32a_RtlSetIoCompletionCallback;
	if (func == pRtlRegisterWait)
		return wine32a_RtlRegisterWait;
	if (func == pRtlDeregisterWaitEx)
		return wine32a_RtlDeregisterWaitEx;
	if (func == pRtlDeregisterWait)
		return wine32a_RtlDeregisterWait;
	if (func == pRtlCreateTimerQueue)
		return wine32a_RtlCreateTimerQueue;
	if (func == pRtlDeleteTimerQueueEx)
		return wine32a_RtlDeleteTimerQueueEx;
	if (func == pRtlCreateTimer)
		return wine32a_RtlCreateTimer;
	if (func == pRtlUpdateTimer)
		return wine32a_RtlUpdateTimer;
	if (func == pRtlDeleteTimer)
		return wine32a_RtlDeleteTimer;
	if (func == pTpAllocCleanupGroup)
		return wine32a_TpAllocCleanupGroup;
	if (func == pTpAllocPool)
		return wine32a_TpAllocPool;
	if (func == pTpAllocTimer)
		return wine32a_TpAllocTimer;
	if (func == pTpAllocWait)
		return wine32a_TpAllocWait;
	if (func == pTpAllocWork)
		return wine32a_TpAllocWork;
	if (func == pTpCallbackLeaveCriticalSectionOnCompletion)
		return wine32a_TpCallbackLeaveCriticalSectionOnCompletion;
	if (func == pTpCallbackMayRunLong)
		return wine32a_TpCallbackMayRunLong;
	if (func == pTpCallbackReleaseMutexOnCompletion)
		return wine32a_TpCallbackReleaseMutexOnCompletion;
	if (func == pTpCallbackReleaseSemaphoreOnCompletion)
		return wine32a_TpCallbackReleaseSemaphoreOnCompletion;
	if (func == pTpCallbackSetEventOnCompletion)
		return wine32a_TpCallbackSetEventOnCompletion;
	if (func == pTpCallbackUnloadDllOnCompletion)
		return wine32a_TpCallbackUnloadDllOnCompletion;
	if (func == pTpDisassociateCallback)
		return wine32a_TpDisassociateCallback;
	if (func == pTpIsTimerSet)
		return wine32a_TpIsTimerSet;
	if (func == pTpPostWork)
		return wine32a_TpPostWork;
	if (func == pTpReleaseCleanupGroup)
		return wine32a_TpReleaseCleanupGroup;
	if (func == pTpReleaseCleanupGroupMembers)
		return wine32a_TpReleaseCleanupGroupMembers;
	if (func == pTpReleasePool)
		return wine32a_TpReleasePool;
	if (func == pTpReleaseTimer)
		return wine32a_TpReleaseTimer;
	if (func == pTpReleaseWait)
		return wine32a_TpReleaseWait;
	if (func == pTpReleaseWork)
		return wine32a_TpReleaseWork;
	if (func == pTpSetPoolMaxThreads)
		return wine32a_TpSetPoolMaxThreads;
	if (func == pTpSetPoolMinThreads)
		return wine32a_TpSetPoolMinThreads;
	if (func == pTpSetTimer)
		return wine32a_TpSetTimer;
	if (func == pTpSetWait)
		return wine32a_TpSetWait;
	if (func == pTpSimpleTryPost)
		return wine32a_TpSimpleTryPost;
	if (func == pTpWaitForTimer)
		return wine32a_TpWaitForTimer;
	if (func == pTpWaitForWait)
		return wine32a_TpWaitForWait;
	if (func == pTpWaitForWork)
		return wine32a_TpWaitForWork;
	if (func == pRtlTimeToTimeFields)
		return wine32a_RtlTimeToTimeFields;
	if (func == pRtlTimeFieldsToTime)
		return wine32a_RtlTimeFieldsToTime;
	if (func == pRtlLocalTimeToSystemTime)
		return wine32a_RtlLocalTimeToSystemTime;
	if (func == pRtlSystemTimeToLocalTime)
		return wine32a_RtlSystemTimeToLocalTime;
	if (func == pRtlTimeToSecondsSince1970)
		return wine32a_RtlTimeToSecondsSince1970;
	if (func == pRtlTimeToSecondsSince1980)
		return wine32a_RtlTimeToSecondsSince1980;
	if (func == pRtlSecondsSince1970ToTime)
		return wine32a_RtlSecondsSince1970ToTime;
	if (func == pRtlSecondsSince1980ToTime)
		return wine32a_RtlSecondsSince1980ToTime;
	if (func == pRtlTimeToElapsedTimeFields)
		return wine32a_RtlTimeToElapsedTimeFields;
	if (func == pNtQuerySystemTime)
		return wine32a_NtQuerySystemTime;
	if (func == pRtlGetSystemTimePrecise)
		return wine32a_RtlGetSystemTimePrecise;
	if (func == pNtQueryPerformanceCounter)
		return wine32a_NtQueryPerformanceCounter;
	if (func == pNtGetTickCount)
		return wine32a_NtGetTickCount;
	if (func == pRtlQueryTimeZoneInformation)
		return wine32a_RtlQueryTimeZoneInformation;
	if (func == pRtlQueryDynamicTimeZoneInformation)
		return wine32a_RtlQueryDynamicTimeZoneInformation;
	if (func == pRtlSetTimeZoneInformation)
		return wine32a_RtlSetTimeZoneInformation;
	if (func == pNtSetSystemTime)
		return wine32a_NtSetSystemTime;
	if (func == pRtlQueryUnbiasedInterruptTime)
		return wine32a_RtlQueryUnbiasedInterruptTime;
	if (func == pRtlGetProductInfo)
		return wine32a_RtlGetProductInfo;
	if (func == pRtlGetVersion)
		return wine32a_RtlGetVersion;
	if (func == pRtlGetNtVersionNumbers)
		return wine32a_RtlGetNtVersionNumbers;
	if (func == pRtlGetNtProductType)
		return wine32a_RtlGetNtProductType;
	if (func == pRtlVerifyVersionInfo)
		return wine32a_RtlVerifyVersionInfo;
	if (func == pRtlCreateUserStack)
		return wine32a_RtlCreateUserStack;
	if (func == pRtlFreeUserStack)
		return wine32a_RtlFreeUserStack;
	if (func == p__wine_locked_recvmsg)
		return wine32a___wine_locked_recvmsg;
	if (func == pNtAllocateVirtualMemory)
		return wine32a_NtAllocateVirtualMemory;
	if (func == pNtFreeVirtualMemory)
		return wine32a_NtFreeVirtualMemory;
	if (func == pNtProtectVirtualMemory)
		return wine32a_NtProtectVirtualMemory;
	if (func == pNtQueryVirtualMemory)
		return wine32a_NtQueryVirtualMemory;
	if (func == pNtLockVirtualMemory)
		return wine32a_NtLockVirtualMemory;
	if (func == pNtUnlockVirtualMemory)
		return wine32a_NtUnlockVirtualMemory;
	if (func == pNtCreateSection)
		return wine32a_NtCreateSection;
	if (func == pNtOpenSection)
		return wine32a_NtOpenSection;
	if (func == pNtMapViewOfSection)
		return wine32a_NtMapViewOfSection;
	if (func == pNtUnmapViewOfSection)
		return wine32a_NtUnmapViewOfSection;
	if (func == pNtQuerySection)
		return wine32a_NtQuerySection;
	if (func == pNtFlushVirtualMemory)
		return wine32a_NtFlushVirtualMemory;
	if (func == pNtGetWriteWatch)
		return wine32a_NtGetWriteWatch;
	if (func == pNtResetWriteWatch)
		return wine32a_NtResetWriteWatch;
	if (func == pNtReadVirtualMemory)
		return wine32a_NtReadVirtualMemory;
	if (func == pNtWriteVirtualMemory)
		return wine32a_NtWriteVirtualMemory;
	if (func == pNtAreMappedFilesTheSame)
		return wine32a_NtAreMappedFilesTheSame;
	if (func == p_ultow)
		return wine32a__ultow;
	if (func == p_ltow)
		return wine32a__ltow;
	if (func == p_itow)
		return wine32a__itow;
	if (func == p_ui64tow)
		return wine32a__ui64tow;
	if (func == p_i64tow)
		return wine32a__i64tow;
	if (func == p_wtol)
		return wine32a__wtol;
	if (func == p_wtoi)
		return wine32a__wtoi;
	if (func == p_wtoi64)
		return wine32a__wtoi64;

	return NULL;
}
