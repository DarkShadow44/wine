#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
#include "wine/winethunks.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

struct _CREATEFILE2_EXTENDED_PARAMETERS; /* ../include/fileapi.h:26 */
enum AppPolicyProcessTerminationMethod; /* ../include/appmodel.h:25 */
enum AppPolicyThreadInitializationType; /* ../include/appmodel.h:31 */
enum AppPolicyShowDeveloperDiagnostic; /* ../include/appmodel.h:37 */
enum AppPolicyWindowingModel; /* ../include/appmodel.h:43 */
enum SHREGDEL_FLAGS; /* ../include/shlwapi.h:133 */
enum SHREGENUM_FLAGS; /* ../include/shlwapi.h:141 */
enum URLIS; /* ../include/shlwapi.h:624 */
struct tagPARSEDURLA; /* ../include/shlwapi.h:736 */
struct tagPARSEDURLW; /* ../include/shlwapi.h:745 */
struct QITAB; /* ../include/shlwapi.h:1128 */
struct _PERF_COUNTERSET_INFO; /* ../include/perflib.h:30 */
struct _PERF_COUNTERSET_INSTANCE; /* ../include/perflib.h:37 */
struct _PROVIDER_CONTEXT; /* ../include/perflib.h:45 */
struct proc_thread_attr; /* ../dlls/kernelbase/process.c:353 */
struct _PROC_THREAD_ATTRIBUTE_LIST; /* ../dlls/kernelbase/process.c:360 */

typedef int HRESULT; /* ../include/winerror.h:93 */

typedef long LONG_PTR; /* ../include/basetsd.h:118 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef unsigned long* PULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR DWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR SIZE_T; /* ../include/basetsd.h:264 */

typedef LONG NTSTATUS; /* ../include/winternl.h:38 */

struct _CREATEFILE2_EXTENDED_PARAMETERS /* ../include/fileapi.h:26 */
{
    DWORD dwSize;
    DWORD dwFileAttributes;
    DWORD dwFileFlags;
    DWORD dwSecurityQosFlags;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes;
    HANDLE hTemplateFile;
};


typedef struct _CREATEFILE2_EXTENDED_PARAMETERS CREATEFILE2_EXTENDED_PARAMETERS; /* ../include/fileapi.h:33 */

enum AppPolicyProcessTerminationMethod /* ../include/appmodel.h:25 */
{
    AppPolicyProcessTerminationMethod_DUMMY = 0
};


typedef enum AppPolicyProcessTerminationMethod AppPolicyProcessTerminationMethod; /* ../include/appmodel.h:29 */

enum AppPolicyThreadInitializationType /* ../include/appmodel.h:31 */
{
    AppPolicyThreadInitializationType_DUMMY = 0
};


typedef enum AppPolicyThreadInitializationType AppPolicyThreadInitializationType; /* ../include/appmodel.h:35 */

enum AppPolicyShowDeveloperDiagnostic /* ../include/appmodel.h:37 */
{
    AppPolicyShowDeveloperDiagnostic_DUMMY = 0
};


typedef enum AppPolicyShowDeveloperDiagnostic AppPolicyShowDeveloperDiagnostic; /* ../include/appmodel.h:41 */

enum AppPolicyWindowingModel /* ../include/appmodel.h:43 */
{
    AppPolicyWindowingModel_DUMMY = 0
};


typedef enum AppPolicyWindowingModel AppPolicyWindowingModel; /* ../include/appmodel.h:49 */

enum SHREGDEL_FLAGS /* ../include/shlwapi.h:133 */
{
    SHREGDEL_FLAGS_DUMMY = 0
};


typedef enum SHREGDEL_FLAGS SHREGDEL_FLAGS; /* ../include/shlwapi.h:139 */

enum SHREGENUM_FLAGS /* ../include/shlwapi.h:141 */
{
    SHREGENUM_FLAGS_DUMMY = 0
};


typedef enum SHREGENUM_FLAGS SHREGENUM_FLAGS; /* ../include/shlwapi.h:147 */

typedef HANDLE HUSKEY; /* ../include/shlwapi.h:155 */

typedef HUSKEY* PHUSKEY; /* ../include/shlwapi.h:156 */

enum URLIS /* ../include/shlwapi.h:624 */
{
    URLIS_DUMMY = 0
};


typedef enum URLIS URLIS; /* ../include/shlwapi.h:632 */

struct tagPARSEDURLA /* ../include/shlwapi.h:736 */
{
    DWORD cbSize;
    LPCSTR pszProtocol;
    UINT cchProtocol;
    LPCSTR pszSuffix;
    UINT cchSuffix;
    UINT nScheme;
};


typedef struct tagPARSEDURLA PARSEDURLA; /* ../include/shlwapi.h:743 */

struct tagPARSEDURLW /* ../include/shlwapi.h:745 */
{
    DWORD cbSize;
    LPCWSTR pszProtocol;
    UINT cchProtocol;
    LPCWSTR pszSuffix;
    UINT cchSuffix;
    UINT nScheme;
};


typedef struct tagPARSEDURLW PARSEDURLW; /* ../include/shlwapi.h:752 */

struct QITAB /* ../include/shlwapi.h:1128 */
{
    IID* piid;
    int dwOffset;
};


typedef struct QITAB QITAB; /* ../include/shlwapi.h:1132 */

typedef LPVOID (*PERF_MEM_ALLOC) (SIZE_T, LPVOID); /* ../include/perflib.h:26 */

typedef void (*PERF_MEM_FREE) (LPVOID, LPVOID); /* ../include/perflib.h:27 */

typedef ULONG (*PERFLIBREQUEST) (ULONG, PVOID, ULONG); /* ../include/perflib.h:28 */

struct _PERF_COUNTERSET_INFO /* ../include/perflib.h:30 */
{
    GUID CounterSetGuid;
    GUID ProviderGuid;
    ULONG NumCounters;
    ULONG InstanceType;
};


typedef struct _PERF_COUNTERSET_INFO* PPERF_COUNTERSET_INFO; /* ../include/perflib.h:35 */

struct _PERF_COUNTERSET_INSTANCE /* ../include/perflib.h:37 */
{
    GUID CounterSetGuid;
    ULONG dwSize;
    ULONG InstanceId;
    ULONG InstanceNameOffset;
    ULONG InstanceNameSize;
};


typedef struct _PERF_COUNTERSET_INSTANCE* PPERF_COUNTERSET_INSTANCE; /* ../include/perflib.h:43 */

struct _PROVIDER_CONTEXT /* ../include/perflib.h:45 */
{
    DWORD ContextSize;
    DWORD Reserved;
    PERFLIBREQUEST ControlCallback;
    PERF_MEM_ALLOC MemAllocRoutine;
    PERF_MEM_FREE MemFreeRoutine;
    LPVOID pMemContext;
};


typedef struct _PROVIDER_CONTEXT* PPERF_PROVIDER_CONTEXT; /* ../include/perflib.h:52 */

struct proc_thread_attr /* ../dlls/kernelbase/process.c:353 */
{
    DWORD_PTR attr;
    SIZE_T size;
    void* value;
};


struct _PROC_THREAD_ATTRIBUTE_LIST /* ../dlls/kernelbase/process.c:360 */
{
    DWORD mask;
    DWORD size;
    DWORD count;
    DWORD pad;
    DWORD_PTR unk;
    struct proc_thread_attr attrs[1];
};


static WINAPI BOOL (*pAccessCheck)(PSECURITY_DESCRIPTOR  descr, HANDLE  token, DWORD  access, PGENERIC_MAPPING  mapping, PPRIVILEGE_SET  priv, LPDWORD  priv_len, LPDWORD  granted, LPBOOL  status);
static WINAPI BOOL (*pAccessCheckAndAuditAlarmW)(LPCWSTR  subsystem, LPVOID  id, LPWSTR  type_name, LPWSTR  name, PSECURITY_DESCRIPTOR  descr, DWORD  access, PGENERIC_MAPPING  mapping, BOOL  creation, LPDWORD  granted, LPBOOL  status, LPBOOL  on_close);
static WINAPI BOOL (*pAccessCheckByType)(PSECURITY_DESCRIPTOR  descr, PSID  sid, HANDLE  token, DWORD  access, POBJECT_TYPE_LIST  types, DWORD  types_len, PGENERIC_MAPPING  mapping, PPRIVILEGE_SET  priv, LPDWORD  priv_len, LPDWORD  granted, LPBOOL  status);
static void* pAcquireSRWLockExclusive;
static void* pextAcquireSRWLockExclusive;
static void* pAcquireSRWLockShared;
static void* pextAcquireSRWLockShared;
static WINAPI BOOL (*pActivateActCtx)(HANDLE  context, ULONG_PTR*  cookie);
static WINAPI BOOL (*pAddAccessAllowedAce)(PACL  acl, DWORD  rev, DWORD  access, PSID  sid);
static WINAPI BOOL (*pAddAccessAllowedAceEx)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid);
static WINAPI BOOL (*pAddAccessAllowedObjectAce)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid);
static WINAPI BOOL (*pAddAccessDeniedAce)(PACL  acl, DWORD  rev, DWORD  access, PSID  sid);
static WINAPI BOOL (*pAddAccessDeniedAceEx)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid);
static WINAPI BOOL (*pAddAccessDeniedObjectAce)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid);
static WINAPI BOOL (*pAddAce)(PACL  acl, DWORD  rev, DWORD  index, LPVOID  list, DWORD  len);
static WINAPI BOOL (*pAddAuditAccessAce)(PACL  acl, DWORD  rev, DWORD  access, PSID  sid, BOOL  success, BOOL  failure);
static WINAPI BOOL (*pAddAuditAccessAceEx)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid, BOOL  success, BOOL  failure);
static WINAPI BOOL (*pAddAuditAccessObjectAce)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid, BOOL  success, BOOL  failure);
static void* pAddDllDirectory;
static void* pextAddDllDirectory;
static WINAPI BOOL (*pAddMandatoryAce)(PACL  acl, DWORD  rev, DWORD  flags, DWORD  policy, PSID  sid);
static WINAPI void (*pAddRefActCtx)(HANDLE  context);
static void* pAddVectoredContinueHandler;
static void* pextAddVectoredContinueHandler;
static void* pAddVectoredExceptionHandler;
static void* pextAddVectoredExceptionHandler;
static WINAPI BOOL (*pAdjustTokenGroups)(HANDLE  token, BOOL  reset, PTOKEN_GROUPS  new, DWORD  len, PTOKEN_GROUPS  prev, PDWORD  ret_len);
static WINAPI BOOL (*pAdjustTokenPrivileges)(HANDLE  token, BOOL  disable, PTOKEN_PRIVILEGES  new, DWORD  len, PTOKEN_PRIVILEGES  prev, PDWORD  ret_len);
static void* pAllocConsole;
static void* pextAllocConsole;
static WINAPI BOOL (*pAllocateAndInitializeSid)(PSID_IDENTIFIER_AUTHORITY  auth, BYTE  count, DWORD  auth0, DWORD  auth1, DWORD  auth2, DWORD  auth3, DWORD  auth4, DWORD  auth5, DWORD  auth6, DWORD  auth7, PSID*  sid);
static WINAPI BOOL (*pAllocateLocallyUniqueId)(PLUID  luid);
static void* pAllocateUserPhysicalPages;
static void* pextAllocateUserPhysicalPages;
static WINAPI LONG (*pAppPolicyGetProcessTerminationMethod)(HANDLE  token, AppPolicyProcessTerminationMethod*  policy);
static WINAPI LONG (*pAppPolicyGetShowDeveloperDiagnostic)(HANDLE  token, AppPolicyShowDeveloperDiagnostic*  policy);
static WINAPI LONG (*pAppPolicyGetThreadInitializationType)(HANDLE  token, AppPolicyThreadInitializationType*  policy);
static WINAPI LONG (*pAppPolicyGetWindowingModel)(HANDLE  token, AppPolicyWindowingModel*  policy);
static WINAPI BOOL (*pAreAllAccessesGranted)(DWORD  granted, DWORD  desired);
static WINAPI BOOL (*pAreAnyAccessesGranted)(DWORD  granted, DWORD  desired);
static WINAPI BOOL (*pAreFileApisANSI)(void);
static void* pAttachConsole;
static void* pextAttachConsole;
static void* pBaseFlushAppcompatCache;
static void* pextBaseFlushAppcompatCache;
static WINAPI NTSTATUS (*pBaseGetNamedObjectDirectory)(HANDLE*  dir);
static void* pBeep;
static void* pextBeep;
static WINAPI BOOL (*pCallNamedPipeW)(LPCWSTR  name, LPVOID  input, DWORD  in_size, LPVOID  output, DWORD  out_size, LPDWORD  read_size, DWORD  timeout);
static WINAPI BOOL (*pCallbackMayRunLong)(TP_CALLBACK_INSTANCE*  instance);
static WINAPI BOOL (*pCancelIo)(HANDLE  handle);
static WINAPI BOOL (*pCancelIoEx)(HANDLE  handle, LPOVERLAPPED  overlapped);
static WINAPI BOOL (*pCancelSynchronousIo)(HANDLE  thread);
static WINAPI BOOL (*pCancelWaitableTimer)(HANDLE  handle);
static WINAPI BOOL (*pChangeTimerQueueTimer)(HANDLE  queue, HANDLE  timer, ULONG  when, ULONG  period);
static WINAPI LPSTR (*pCharLowerA)(char*  str);
static WINAPI DWORD (*pCharLowerBuffA)(char*  str, DWORD  len);
static WINAPI DWORD (*pCharLowerBuffW)(WCHAR*  str, DWORD  len);
static WINAPI LPWSTR (*pCharLowerW)(WCHAR*  str);
static WINAPI LPSTR (*pCharNextA)(char*  ptr);
static WINAPI LPSTR (*pCharNextExA)(WORD  codepage, char*  ptr, DWORD  flags);
static WINAPI LPWSTR (*pCharNextW)(WCHAR*  x);
static WINAPI LPSTR (*pCharPrevA)(char*  start, char*  ptr);
static WINAPI LPSTR (*pCharPrevExA)(WORD  codepage, char*  start, char*  ptr, DWORD  flags);
static WINAPI LPWSTR (*pCharPrevW)(WCHAR*  start, WCHAR*  x);
static WINAPI LPSTR (*pCharUpperA)(LPSTR  str);
static WINAPI DWORD (*pCharUpperBuffA)(LPSTR  str, DWORD  len);
static WINAPI DWORD (*pCharUpperBuffW)(WCHAR*  str, DWORD  len);
static WINAPI LPWSTR (*pCharUpperW)(WCHAR*  str);
static void* pCheckRemoteDebuggerPresent;
static void* pextCheckRemoteDebuggerPresent;
static WINAPI BOOL (*pCheckTokenMembership)(HANDLE  token, PSID  sid_to_check, PBOOL  is_member);
static WINAPI BOOL (*pChrCmpIA)(WORD  ch1, WORD  ch2);
static WINAPI BOOL (*pChrCmpIW)(WCHAR  ch1, WCHAR  ch2);
static void* pClearCommBreak;
static void* pextClearCommBreak;
static void* pClearCommError;
static void* pextClearCommError;
static void* pCloseHandle;
static void* pextCloseHandle;
static void* pCloseThreadpool;
static void* pextCloseThreadpool;
static void* pCloseThreadpoolCleanupGroup;
static void* pextCloseThreadpoolCleanupGroup;
static void* pCloseThreadpoolCleanupGroupMembers;
static void* pextCloseThreadpoolCleanupGroupMembers;
static void* pCloseThreadpoolTimer;
static void* pextCloseThreadpoolTimer;
static void* pCloseThreadpoolWait;
static void* pextCloseThreadpoolWait;
static void* pCloseThreadpoolWork;
static void* pextCloseThreadpoolWork;
static void* pCompareFileTime;
static void* pextCompareFileTime;
static void* pCompareStringA;
static void* pextCompareStringA;
static void* pCompareStringEx;
static void* pextCompareStringEx;
static void* pCompareStringOrdinal;
static void* pextCompareStringOrdinal;
static void* pCompareStringW;
static void* pextCompareStringW;
static WINAPI BOOL (*pConnectNamedPipe)(HANDLE  pipe, LPOVERLAPPED  overlapped);
static void* pContinueDebugEvent;
static void* pextContinueDebugEvent;
static void* pConvertDefaultLocale;
static void* pextConvertDefaultLocale;
static WINAPI BOOL (*pConvertFiberToThread)(void);
static WINAPI LPVOID (*pConvertThreadToFiber)(LPVOID  param);
static WINAPI LPVOID (*pConvertThreadToFiberEx)(LPVOID  param, DWORD  flags);
static WINAPI BOOL (*pConvertToAutoInheritPrivateObjectSecurity)(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  current, PSECURITY_DESCRIPTOR*  descr, GUID*  type, BOOL  is_dir, PGENERIC_MAPPING  mapping);
static void* pCopyFileExW;
static void* pextCopyFileExW;
static void* pCopyFileW;
static void* pextCopyFileW;
static WINAPI BOOL (*pCopySid)(DWORD  len, PSID  dest, PSID  source);
static WINAPI HANDLE (*pCreateActCtxW)(PCACTCTXW  ctx);
static void* pCreateConsoleScreenBuffer;
static void* pextCreateConsoleScreenBuffer;
static WINAPI BOOL (*pCreateDirectoryA)(LPCSTR  path, LPSECURITY_ATTRIBUTES  sa);
static WINAPI BOOL (*pCreateDirectoryExW)(LPCWSTR  template, LPCWSTR  path, LPSECURITY_ATTRIBUTES  sa);
static WINAPI BOOL (*pCreateDirectoryW)(LPCWSTR  path, LPSECURITY_ATTRIBUTES  sa);
static WINAPI HANDLE (*pCreateEventA)(SECURITY_ATTRIBUTES*  sa, BOOL  manual_reset, BOOL  initial_state, LPCSTR  name);
static WINAPI HANDLE (*pCreateEventExA)(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateEventExW)(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateEventW)(SECURITY_ATTRIBUTES*  sa, BOOL  manual_reset, BOOL  initial_state, LPCWSTR  name);
static WINAPI LPVOID (*pCreateFiber)(SIZE_T  stack, LPFIBER_START_ROUTINE  start, LPVOID  param);
static WINAPI LPVOID (*pCreateFiberEx)(SIZE_T  stack_commit, SIZE_T  stack_reserve, DWORD  flags, LPFIBER_START_ROUTINE  start, LPVOID  param);
static WINAPI HANDLE (*pCreateFile2)(LPCWSTR  name, DWORD  access, DWORD  sharing, DWORD  creation, CREATEFILE2_EXTENDED_PARAMETERS*  params);
static WINAPI HANDLE (*pCreateFileA)(LPCSTR  name, DWORD  access, DWORD  sharing, LPSECURITY_ATTRIBUTES  sa, DWORD  creation, DWORD  attributes, HANDLE  template);
static WINAPI HANDLE (*pCreateFileMappingW)(HANDLE  file, LPSECURITY_ATTRIBUTES  sa, DWORD  protect, DWORD  size_high, DWORD  size_low, LPCWSTR  name);
static WINAPI HANDLE (*pCreateFileW)(LPCWSTR  filename, DWORD  access, DWORD  sharing, LPSECURITY_ATTRIBUTES  sa, DWORD  creation, DWORD  attributes, HANDLE  template);
static void* pCreateHardLinkA;
static void* pextCreateHardLinkA;
static void* pCreateHardLinkW;
static void* pextCreateHardLinkW;
static WINAPI HANDLE (*pCreateIoCompletionPort)(HANDLE  handle, HANDLE  port, ULONG_PTR  key, DWORD  threads);
static void* pCreateMemoryResourceNotification;
static void* pextCreateMemoryResourceNotification;
static WINAPI HANDLE (*pCreateMutexA)(SECURITY_ATTRIBUTES*  sa, BOOL  owner, LPCSTR  name);
static WINAPI HANDLE (*pCreateMutexExA)(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateMutexExW)(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateMutexW)(SECURITY_ATTRIBUTES*  sa, BOOL  owner, LPCWSTR  name);
static WINAPI HANDLE (*pCreateNamedPipeW)(LPCWSTR  name, DWORD  open_mode, DWORD  pipe_mode, DWORD  instances, DWORD  out_buff, DWORD  in_buff, DWORD  timeout, LPSECURITY_ATTRIBUTES  sa);
static void* pCreatePipe;
static void* pextCreatePipe;
static WINAPI BOOL (*pCreatePrivateObjectSecurity)(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, BOOL  is_container, HANDLE  token, PGENERIC_MAPPING  mapping);
static WINAPI BOOL (*pCreatePrivateObjectSecurityEx)(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, GUID*  type, BOOL  is_container, ULONG  flags, HANDLE  token, PGENERIC_MAPPING  mapping);
static WINAPI BOOL (*pCreatePrivateObjectSecurityWithMultipleInheritance)(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, GUID**  types, ULONG  count, BOOL  is_container, ULONG  flags, HANDLE  token, PGENERIC_MAPPING  mapping);
static void* pCreateProcessA;
static void* pextCreateProcessA;
static void* pCreateProcessAsUserA;
static void* pextCreateProcessAsUserA;
static void* pCreateProcessAsUserW;
static void* pextCreateProcessAsUserW;
static void* pCreateProcessInternalA;
static void* pextCreateProcessInternalA;
static void* pCreateProcessInternalW;
static void* pextCreateProcessInternalW;
static void* pCreateProcessW;
static void* pextCreateProcessW;
static WINAPI HANDLE (*pCreateRemoteThread)(HANDLE  process, SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, DWORD*  id);
static WINAPI HANDLE (*pCreateRemoteThreadEx)(HANDLE  process, SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, LPPROC_THREAD_ATTRIBUTE_LIST  attributes, DWORD*  id);
static WINAPI BOOL (*pCreateRestrictedToken)(HANDLE  token, DWORD  flags, DWORD  disable_count, PSID_AND_ATTRIBUTES  disable_sids, DWORD  delete_count, PLUID_AND_ATTRIBUTES  delete_privs, DWORD  restrict_count, PSID_AND_ATTRIBUTES  restrict_sids, PHANDLE  ret);
static WINAPI HANDLE (*pCreateSemaphoreExW)(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCWSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateSemaphoreW)(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCWSTR  name);
static void* pCreateSymbolicLinkW;
static void* pextCreateSymbolicLinkW;
static WINAPI HANDLE (*pCreateThread)(SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, LPDWORD  id);
static WINAPI PTP_POOL (*pCreateThreadpool)(void*  reserved);
static WINAPI PTP_CLEANUP_GROUP (*pCreateThreadpoolCleanupGroup)(void);
static WINAPI PTP_IO (*pCreateThreadpoolIo)(HANDLE  handle, PTP_WIN32_IO_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI PTP_TIMER (*pCreateThreadpoolTimer)(PTP_TIMER_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI PTP_WAIT (*pCreateThreadpoolWait)(PTP_WAIT_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI PTP_WORK (*pCreateThreadpoolWork)(PTP_WORK_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI HANDLE (*pCreateTimerQueue)(void);
static WINAPI BOOL (*pCreateTimerQueueTimer)(PHANDLE  timer, HANDLE  queue, WAITORTIMERCALLBACK  callback, PVOID  arg, DWORD  when, DWORD  period, ULONG  flags);
static WINAPI HANDLE (*pCreateWaitableTimerExW)(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access);
static WINAPI HANDLE (*pCreateWaitableTimerW)(SECURITY_ATTRIBUTES*  sa, BOOL  manual, LPCWSTR  name);
static WINAPI BOOL (*pCreateWellKnownSid)(WELL_KNOWN_SID_TYPE  type, PSID  domain, PSID  sid, DWORD*  size);
static WINAPI BOOL (*pDeactivateActCtx)(DWORD  flags, ULONG_PTR  cookie);
static void* pDebugActiveProcess;
static void* pextDebugActiveProcess;
static void* pDebugActiveProcessStop;
static void* pextDebugActiveProcessStop;
static void* pDebugBreak;
static void* pextDebugBreak;
static void* pDecodePointer;
static void* pextDecodePointer;
static void* pDecodeSystemPointer;
static void* pextDecodeSystemPointer;
static void* pDefineDosDeviceW;
static void* pextDefineDosDeviceW;
static void* pDelayLoadFailureHook;
static void* pextDelayLoadFailureHook;
static WINAPI BOOL (*pDeleteAce)(PACL  acl, DWORD  index);
static void* pDeleteCriticalSection;
static void* pextDeleteCriticalSection;
static WINAPI void (*pDeleteFiber)(LPVOID  fiber_ptr);
static WINAPI BOOL (*pDeleteFileA)(LPCSTR  path);
static WINAPI BOOL (*pDeleteFileW)(LPCWSTR  path);
static WINAPI void (*pDeleteProcThreadAttributeList)(struct _PROC_THREAD_ATTRIBUTE_LIST*  list);
static WINAPI BOOL (*pDeleteTimerQueueEx)(HANDLE  queue, HANDLE  event);
static WINAPI BOOL (*pDeleteTimerQueueTimer)(HANDLE  queue, HANDLE  timer, HANDLE  event);
static void* pDeleteVolumeMountPointW;
static void* pextDeleteVolumeMountPointW;
static WINAPI BOOL (*pDestroyPrivateObjectSecurity)(PSECURITY_DESCRIPTOR*  descr);
static void* pDeviceIoControl;
static void* pextDeviceIoControl;
static WINAPI NTSTATUS (*pDisablePredefinedHandleTableInternal)(HKEY  hkey);
static WINAPI BOOL (*pDisableThreadLibraryCalls)(HMODULE  module);
static void* pDisassociateCurrentThreadFromCallback;
static void* pextDisassociateCurrentThreadFromCallback;
static WINAPI BOOL (*pDisconnectNamedPipe)(HANDLE  pipe);
static void* pDuplicateHandle;
static void* pextDuplicateHandle;
static WINAPI BOOL (*pDuplicateToken)(HANDLE  token, SECURITY_IMPERSONATION_LEVEL  level, PHANDLE  ret);
static WINAPI BOOL (*pDuplicateTokenEx)(HANDLE  token, DWORD  access, LPSECURITY_ATTRIBUTES  sa, SECURITY_IMPERSONATION_LEVEL  level, TOKEN_TYPE  type, PHANDLE  ret);
static void* pEncodePointer;
static void* pextEncodePointer;
static void* pEncodeSystemPointer;
static void* pextEncodeSystemPointer;
static void* pEnterCriticalSection;
static void* pextEnterCriticalSection;
static void* pEnumCalendarInfoExEx;
static void* pextEnumCalendarInfoExEx;
static void* pEnumCalendarInfoExW;
static void* pextEnumCalendarInfoExW;
static void* pEnumCalendarInfoW;
static void* pextEnumCalendarInfoW;
static void* pEnumDateFormatsExEx;
static void* pextEnumDateFormatsExEx;
static void* pEnumDateFormatsExW;
static void* pextEnumDateFormatsExW;
static void* pEnumDateFormatsW;
static void* pextEnumDateFormatsW;
static WINAPI DWORD (*pEnumDynamicTimeZoneInformation)(DWORD  index, DYNAMIC_TIME_ZONE_INFORMATION*  dtzi);
static void* pEnumLanguageGroupLocalesW;
static void* pextEnumLanguageGroupLocalesW;
static WINAPI BOOL (*pEnumResourceLanguagesExA)(HMODULE  module, LPCSTR  type, LPCSTR  name, ENUMRESLANGPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static WINAPI BOOL (*pEnumResourceLanguagesExW)(HMODULE  module, LPCWSTR  type, LPCWSTR  name, ENUMRESLANGPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static WINAPI BOOL (*pEnumResourceNamesExA)(HMODULE  module, LPCSTR  type, ENUMRESNAMEPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static WINAPI BOOL (*pEnumResourceNamesExW)(HMODULE  module, LPCWSTR  type, ENUMRESNAMEPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static WINAPI BOOL (*pEnumResourceNamesW)(HMODULE  module, LPCWSTR  type, ENUMRESNAMEPROCW  func, LONG_PTR  param);
static WINAPI BOOL (*pEnumResourceTypesExA)(HMODULE  module, ENUMRESTYPEPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static WINAPI BOOL (*pEnumResourceTypesExW)(HMODULE  module, ENUMRESTYPEPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang);
static void* pEnumSystemCodePagesW;
static void* pextEnumSystemCodePagesW;
static void* pEnumSystemFirmwareTables;
static void* pextEnumSystemFirmwareTables;
static void* pEnumSystemGeoID;
static void* pextEnumSystemGeoID;
static void* pEnumSystemLanguageGroupsW;
static void* pextEnumSystemLanguageGroupsW;
static void* pEnumSystemLocalesA;
static void* pextEnumSystemLocalesA;
static void* pEnumSystemLocalesEx;
static void* pextEnumSystemLocalesEx;
static void* pEnumSystemLocalesW;
static void* pextEnumSystemLocalesW;
static void* pEnumTimeFormatsEx;
static void* pextEnumTimeFormatsEx;
static void* pEnumTimeFormatsW;
static void* pextEnumTimeFormatsW;
static void* pEnumUILanguagesW;
static void* pextEnumUILanguagesW;
static WINAPI BOOL (*pEqualPrefixSid)(PSID  sid1, PSID  sid2);
static WINAPI BOOL (*pEqualSid)(PSID  sid1, PSID  sid2);
static void* pEscapeCommFunction;
static void* pextEscapeCommFunction;
static void* pEventActivityIdControl;
static void* pextEventActivityIdControl;
static void* pEventEnabled;
static void* pextEventEnabled;
static void* pEventProviderEnabled;
static void* pextEventProviderEnabled;
static void* pEventRegister;
static void* pextEventRegister;
static void* pEventSetInformation;
static void* pextEventSetInformation;
static void* pEventUnregister;
static void* pextEventUnregister;
static void* pEventWrite;
static void* pextEventWrite;
static void* pEventWriteString;
static void* pextEventWriteString;
static void* pEventWriteTransfer;
static void* pextEventWriteTransfer;
static void* pExitProcess;
static void* pextExitProcess;
static void* pExitThread;
static void* pextExitThread;
static void* pExpandEnvironmentStringsA;
static void* pextExpandEnvironmentStringsA;
static void* pExpandEnvironmentStringsW;
static void* pextExpandEnvironmentStringsW;
static void* pFatalAppExitA;
static void* pextFatalAppExitA;
static void* pFatalAppExitW;
static void* pextFatalAppExitW;
static void* pFileTimeToLocalFileTime;
static void* pextFileTimeToLocalFileTime;
static void* pFileTimeToSystemTime;
static void* pextFileTimeToSystemTime;
static void* pFillConsoleOutputAttribute;
static void* pextFillConsoleOutputAttribute;
static void* pFillConsoleOutputCharacterA;
static void* pextFillConsoleOutputCharacterA;
static void* pFillConsoleOutputCharacterW;
static void* pextFillConsoleOutputCharacterW;
static WINAPI BOOL (*pFindActCtxSectionGuid)(DWORD  flags, GUID*  ext_guid, ULONG  id, GUID*  guid, PACTCTX_SECTION_KEYED_DATA  info);
static WINAPI BOOL (*pFindActCtxSectionStringW)(DWORD  flags, GUID*  ext_guid, ULONG  id, LPCWSTR  str, PACTCTX_SECTION_KEYED_DATA  info);
static void* pFindClose;
static void* pextFindClose;
static void* pFindCloseChangeNotification;
static void* pextFindCloseChangeNotification;
static void* pFindFirstChangeNotificationA;
static void* pextFindFirstChangeNotificationA;
static void* pFindFirstChangeNotificationW;
static void* pextFindFirstChangeNotificationW;
static void* pFindFirstFileA;
static void* pextFindFirstFileA;
static void* pFindFirstFileExA;
static void* pextFindFirstFileExA;
static void* pFindFirstFileExW;
static void* pextFindFirstFileExW;
static void* pFindFirstFileW;
static void* pextFindFirstFileW;
static WINAPI BOOL (*pFindFirstFreeAce)(PACL  acl, LPVOID*  ace);
static void* pFindFirstStreamW;
static void* pextFindFirstStreamW;
static void* pFindFirstVolumeW;
static void* pextFindFirstVolumeW;
static void* pFindNLSStringEx;
static void* pextFindNLSStringEx;
static void* pFindNextChangeNotification;
static void* pextFindNextChangeNotification;
static void* pFindNextFileA;
static void* pextFindNextFileA;
static void* pFindNextFileW;
static void* pextFindNextFileW;
static void* pFindNextStreamW;
static void* pextFindNextStreamW;
static void* pFindNextVolumeW;
static void* pextFindNextVolumeW;
static WINAPI HRSRC (*pFindResourceExW)(HMODULE  module, LPCWSTR  type, LPCWSTR  name, WORD  lang);
static WINAPI HRSRC (*pFindResourceW)(HINSTANCE  module, LPCWSTR  name, LPCWSTR  type);
static void* pFindStringOrdinal;
static void* pextFindStringOrdinal;
static void* pFindVolumeClose;
static void* pextFindVolumeClose;
static WINAPI DWORD (*pFlsAlloc)(PFLS_CALLBACK_FUNCTION  callback);
static WINAPI BOOL (*pFlsFree)(DWORD  index);
static WINAPI PVOID (*pFlsGetValue)(DWORD  index);
static WINAPI BOOL (*pFlsSetValue)(DWORD  index, PVOID  data);
static void* pFlushConsoleInputBuffer;
static void* pextFlushConsoleInputBuffer;
static WINAPI BOOL (*pFlushFileBuffers)(HANDLE  file);
static WINAPI BOOL (*pFlushInstructionCache)(HANDLE  process, LPCVOID  addr, SIZE_T  size);
static void* pFlushProcessWriteBuffers;
static void* pextFlushProcessWriteBuffers;
static void* pFlushViewOfFile;
static void* pextFlushViewOfFile;
static void* pFoldStringW;
static void* pextFoldStringW;
static void* pFormatMessageA;
static void* pextFormatMessageA;
static void* pFormatMessageW;
static void* pextFormatMessageW;
static void* pFreeConsole;
static void* pextFreeConsole;
static void* pFreeEnvironmentStringsA;
static void* pextFreeEnvironmentStringsA;
static void* pFreeEnvironmentStringsW;
static void* pextFreeEnvironmentStringsW;
static void* pFreeLibrary;
static void* pextFreeLibrary;
static WINAPI void (*pFreeLibraryAndExitThread)(HINSTANCE  module, DWORD  exit_code);
static void* pFreeLibraryWhenCallbackReturns;
static void* pextFreeLibraryWhenCallbackReturns;
static WINAPI BOOL (*pFreeResource)(HGLOBAL  handle);
static WINAPI PVOID (*pFreeSid)(PSID  pSid);
static void* pFreeUserPhysicalPages;
static void* pextFreeUserPhysicalPages;
static void* pGenerateConsoleCtrlEvent;
static void* pextGenerateConsoleCtrlEvent;
static void* pGetACP;
static void* pextGetACP;
static WINAPI HRESULT (*pGetAcceptLanguagesA)(LPSTR  langbuf, DWORD*  buflen);
static WINAPI HRESULT (*pGetAcceptLanguagesW)(WCHAR*  langbuf, DWORD*  buflen);
static WINAPI BOOL (*pGetAce)(PACL  acl, DWORD  index, LPVOID*  ace);
static WINAPI BOOL (*pGetAclInformation)(PACL  acl, LPVOID  info, DWORD  len, ACL_INFORMATION_CLASS  class);
static void* pGetApplicationRestartSettings;
static void* pextGetApplicationRestartSettings;
static void* pGetCPInfo;
static void* pextGetCPInfo;
static void* pGetCPInfoExW;
static void* pextGetCPInfoExW;
static void* pGetCalendarInfoEx;
static void* pextGetCalendarInfoEx;
static void* pGetCalendarInfoW;
static void* pextGetCalendarInfoW;
static void* pGetCommConfig;
static void* pextGetCommConfig;
static void* pGetCommMask;
static void* pextGetCommMask;
static void* pGetCommModemStatus;
static void* pextGetCommModemStatus;
static void* pGetCommProperties;
static void* pextGetCommProperties;
static void* pGetCommState;
static void* pextGetCommState;
static void* pGetCommTimeouts;
static void* pextGetCommTimeouts;
static void* pGetCommandLineA;
static void* pextGetCommandLineA;
static void* pGetCommandLineW;
static void* pextGetCommandLineW;
static WINAPI DWORD (*pGetCompressedFileSizeA)(LPCSTR  name, LPDWORD  size_high);
static WINAPI DWORD (*pGetCompressedFileSizeW)(LPCWSTR  name, LPDWORD  size_high);
static void* pGetComputerNameExA;
static void* pextGetComputerNameExA;
static void* pGetComputerNameExW;
static void* pextGetComputerNameExW;
static void* pGetConsoleCP;
static void* pextGetConsoleCP;
static void* pGetConsoleCursorInfo;
static void* pextGetConsoleCursorInfo;
static void* pGetConsoleInputExeNameA;
static void* pextGetConsoleInputExeNameA;
static void* pGetConsoleInputExeNameW;
static void* pextGetConsoleInputExeNameW;
static void* pGetConsoleMode;
static void* pextGetConsoleMode;
static void* pGetConsoleOutputCP;
static void* pextGetConsoleOutputCP;
static void* pGetConsoleScreenBufferInfo;
static void* pextGetConsoleScreenBufferInfo;
static void* pGetConsoleScreenBufferInfoEx;
static void* pextGetConsoleScreenBufferInfoEx;
static void* pGetConsoleTitleW;
static void* pextGetConsoleTitleW;
static void* pGetCurrencyFormatEx;
static void* pextGetCurrencyFormatEx;
static void* pGetCurrencyFormatW;
static void* pextGetCurrencyFormatW;
static WINAPI BOOL (*pGetCurrentActCtx)(HANDLE*  pcontext);
static void* pGetCurrentDirectoryA;
static void* pextGetCurrentDirectoryA;
static void* pGetCurrentDirectoryW;
static void* pextGetCurrentDirectoryW;
static void* pGetCurrentPackageFamilyName;
static void* pextGetCurrentPackageFamilyName;
static void* pGetCurrentPackageFullName;
static void* pextGetCurrentPackageFullName;
static void* pGetCurrentPackageId;
static void* pextGetCurrentPackageId;
static WINAPI HANDLE (*pGetCurrentProcess)(void);
static WINAPI DWORD (*pGetCurrentProcessId)(void);
static void* pGetCurrentProcessorNumber;
static void* pextGetCurrentProcessorNumber;
static void* pGetCurrentProcessorNumberEx;
static void* pextGetCurrentProcessorNumberEx;
static WINAPI HANDLE (*pGetCurrentThread)(void);
static WINAPI DWORD (*pGetCurrentThreadId)(void);
static WINAPI void (*pGetCurrentThreadStackLimits)(ULONG_PTR*  low, ULONG_PTR*  high);
static void* pGetDateFormatA;
static void* pextGetDateFormatA;
static void* pGetDateFormatEx;
static void* pextGetDateFormatEx;
static void* pGetDateFormatW;
static void* pextGetDateFormatW;
static void* pGetDiskFreeSpaceA;
static void* pextGetDiskFreeSpaceA;
static void* pGetDiskFreeSpaceExA;
static void* pextGetDiskFreeSpaceExA;
static void* pGetDiskFreeSpaceExW;
static void* pextGetDiskFreeSpaceExW;
static void* pGetDiskFreeSpaceW;
static void* pextGetDiskFreeSpaceW;
static void* pGetDriveTypeA;
static void* pextGetDriveTypeA;
static void* pGetDriveTypeW;
static void* pextGetDriveTypeW;
static void* pGetDynamicTimeZoneInformation;
static void* pextGetDynamicTimeZoneInformation;
static void* pGetDynamicTimeZoneInformationEffectiveYears;
static void* pextGetDynamicTimeZoneInformationEffectiveYears;
static void* pGetEnabledXStateFeatures;
static void* pextGetEnabledXStateFeatures;
static void* pGetEnvironmentStrings;
static void* pextGetEnvironmentStrings;
static void* pGetEnvironmentStringsA;
static void* pextGetEnvironmentStringsA;
static void* pGetEnvironmentStringsW;
static void* pextGetEnvironmentStringsW;
static void* pGetEnvironmentVariableA;
static void* pextGetEnvironmentVariableA;
static void* pGetEnvironmentVariableW;
static void* pextGetEnvironmentVariableW;
static WINAPI UINT (*pGetErrorMode)(void);
static WINAPI BOOL (*pGetExitCodeProcess)(HANDLE  process, LPDWORD  exit_code);
static WINAPI BOOL (*pGetExitCodeThread)(HANDLE  thread, LPDWORD  exit_code);
static WINAPI DWORD (*pGetFileAttributesA)(LPCSTR  name);
static WINAPI BOOL (*pGetFileAttributesExA)(LPCSTR  name, GET_FILEEX_INFO_LEVELS  level, void*  ptr);
static WINAPI BOOL (*pGetFileAttributesExW)(LPCWSTR  name, GET_FILEEX_INFO_LEVELS  level, void*  ptr);
static WINAPI DWORD (*pGetFileAttributesW)(LPCWSTR  name);
static WINAPI BOOL (*pGetFileInformationByHandle)(HANDLE  file, BY_HANDLE_FILE_INFORMATION*  info);
static WINAPI BOOL (*pGetFileInformationByHandleEx)(HANDLE  handle, FILE_INFO_BY_HANDLE_CLASS  class, LPVOID  info, DWORD  size);
static void* pGetFileMUIInfo;
static void* pextGetFileMUIInfo;
static void* pGetFileMUIPath;
static void* pextGetFileMUIPath;
static WINAPI BOOL (*pGetFileSecurityW)(LPCWSTR  name, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, DWORD  len, LPDWORD  ret_len);
static WINAPI DWORD (*pGetFileSize)(HANDLE  file, LPDWORD  size_high);
static WINAPI BOOL (*pGetFileSizeEx)(HANDLE  file, PLARGE_INTEGER  size);
static WINAPI BOOL (*pGetFileTime)(HANDLE  file, FILETIME*  creation, FILETIME*  access, FILETIME*  write);
static WINAPI DWORD (*pGetFileType)(HANDLE  file);
static WINAPI BOOL (*pGetFileVersionInfoA)(LPCSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data);
static WINAPI BOOL (*pGetFileVersionInfoExA)(DWORD  flags, LPCSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data);
static WINAPI BOOL (*pGetFileVersionInfoExW)(DWORD  flags, LPCWSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data);
static WINAPI DWORD (*pGetFileVersionInfoSizeA)(LPCSTR  filename, LPDWORD  handle);
static WINAPI DWORD (*pGetFileVersionInfoSizeExA)(DWORD  flags, LPCSTR  filename, LPDWORD  handle);
static WINAPI DWORD (*pGetFileVersionInfoSizeExW)(DWORD  flags, LPCWSTR  filename, LPDWORD  handle);
static WINAPI DWORD (*pGetFileVersionInfoSizeW)(LPCWSTR  filename, LPDWORD  handle);
static WINAPI BOOL (*pGetFileVersionInfoW)(LPCWSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data);
static void* pGetFinalPathNameByHandleA;
static void* pextGetFinalPathNameByHandleA;
static void* pGetFinalPathNameByHandleW;
static void* pextGetFinalPathNameByHandleW;
static void* pGetFullPathNameA;
static void* pextGetFullPathNameA;
static void* pGetFullPathNameW;
static void* pextGetFullPathNameW;
static void* pGetGeoInfoW;
static void* pextGetGeoInfoW;
static void* pGetHandleInformation;
static void* pextGetHandleInformation;
static WINAPI BOOL (*pGetKernelObjectSecurity)(HANDLE  handle, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, DWORD  len, LPDWORD  ret_len);
static void* pGetLargePageMinimum;
static void* pextGetLargePageMinimum;
static void* pGetLargestConsoleWindowSize;
static void* pextGetLargestConsoleWindowSize;
static WINAPI DWORD (*pGetLastError)(void);
static WINAPI DWORD (*pGetLengthSid)(PSID  sid);
static void* pGetLocalTime;
static void* pextGetLocalTime;
static void* pGetLocaleInfoA;
static void* pextGetLocaleInfoA;
static void* pGetLocaleInfoEx;
static void* pextGetLocaleInfoEx;
static void* pGetLocaleInfoW;
static void* pextGetLocaleInfoW;
static void* pGetLogicalDriveStringsW;
static void* pextGetLogicalDriveStringsW;
static void* pGetLogicalDrives;
static void* pextGetLogicalDrives;
static void* pGetLogicalProcessorInformation;
static void* pextGetLogicalProcessorInformation;
static void* pGetLogicalProcessorInformationEx;
static void* pextGetLogicalProcessorInformationEx;
static void* pGetLongPathNameA;
static void* pextGetLongPathNameA;
static void* pGetLongPathNameW;
static void* pextGetLongPathNameW;
static WINAPI DWORD (*pGetModuleFileNameA)(HMODULE  module, LPSTR  filename, DWORD  size);
static WINAPI DWORD (*pGetModuleFileNameW)(HMODULE  module, LPWSTR  filename, DWORD  size);
static WINAPI HMODULE (*pGetModuleHandleA)(LPCSTR  module);
static WINAPI BOOL (*pGetModuleHandleExA)(DWORD  flags, LPCSTR  name, HMODULE*  module);
static WINAPI BOOL (*pGetModuleHandleExW)(DWORD  flags, LPCWSTR  name, HMODULE*  module);
static WINAPI HMODULE (*pGetModuleHandleW)(LPCWSTR  module);
static void* pGetNamedPipeHandleStateW;
static void* pextGetNamedPipeHandleStateW;
static WINAPI BOOL (*pGetNamedPipeInfo)(HANDLE  pipe, LPDWORD  flags, LPDWORD  out_size, LPDWORD  in_size, LPDWORD  instances);
static void* pGetNativeSystemInfo;
static void* pextGetNativeSystemInfo;
static void* pGetNumaHighestNodeNumber;
static void* pextGetNumaHighestNodeNumber;
static void* pGetNumaNodeProcessorMaskEx;
static void* pextGetNumaNodeProcessorMaskEx;
static void* pGetNumaProximityNode;
static void* pextGetNumaProximityNode;
static void* pGetNumaProximityNodeEx;
static void* pextGetNumaProximityNodeEx;
static void* pGetNumberFormatEx;
static void* pextGetNumberFormatEx;
static void* pGetNumberFormatW;
static void* pextGetNumberFormatW;
static void* pGetNumberOfConsoleInputEvents;
static void* pextGetNumberOfConsoleInputEvents;
static void* pGetOEMCP;
static void* pextGetOEMCP;
static WINAPI BOOL (*pGetOverlappedResult)(HANDLE  file, LPOVERLAPPED  overlapped, LPDWORD  result, BOOL  wait);
static void* pGetPackageFullName;
static void* pextGetPackageFullName;
static void* pGetPhysicallyInstalledSystemMemory;
static void* pextGetPhysicallyInstalledSystemMemory;
static WINAPI DWORD (*pGetPriorityClass)(HANDLE  process);
static WINAPI BOOL (*pGetPrivateObjectSecurity)(PSECURITY_DESCRIPTOR  obj_descr, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  ret_descr, DWORD  len, PDWORD  ret_len);
static void* pGetProcAddress;
static void* pextGetProcAddress;
static WINAPI BOOL (*pGetProcessHandleCount)(HANDLE  process, DWORD*  count);
static WINAPI HANDLE (*pGetProcessHeap)(void);
static WINAPI DWORD (*pGetProcessId)(HANDLE  process);
static WINAPI DWORD (*pGetProcessIdOfThread)(HANDLE  thread);
static WINAPI BOOL (*pGetProcessMitigationPolicy)(HANDLE  process, PROCESS_MITIGATION_POLICY  policy, void*  buffer, SIZE_T  length);
static void* pGetProcessPreferredUILanguages;
static void* pextGetProcessPreferredUILanguages;
static WINAPI BOOL (*pGetProcessPriorityBoost)(HANDLE  process, PBOOL  disable);
static WINAPI BOOL (*pGetProcessShutdownParameters)(LPDWORD  level, LPDWORD  flags);
static void* pGetProcessTimes;
static void* pextGetProcessTimes;
static void* pGetProcessVersion;
static void* pextGetProcessVersion;
static WINAPI BOOL (*pGetProcessWorkingSetSizeEx)(HANDLE  process, SIZE_T*  minset, SIZE_T*  maxset, DWORD*  flags);
static void* pGetProductInfo;
static void* pextGetProductInfo;
static WINAPI BOOL (*pGetQueuedCompletionStatus)(HANDLE  port, LPDWORD  count, PULONG_PTR  key, LPOVERLAPPED*  overlapped, DWORD  timeout);
static WINAPI BOOL (*pGetQueuedCompletionStatusEx)(HANDLE  port, OVERLAPPED_ENTRY*  entries, ULONG  count, ULONG*  written, DWORD  timeout, BOOL  alertable);
static WINAPI BOOL (*pGetSecurityDescriptorControl)(PSECURITY_DESCRIPTOR  descr, PSECURITY_DESCRIPTOR_CONTROL  control, LPDWORD  revision);
static WINAPI BOOL (*pGetSecurityDescriptorDacl)(PSECURITY_DESCRIPTOR  descr, LPBOOL  dacl_present, PACL*  dacl, LPBOOL  dacl_defaulted);
static WINAPI BOOL (*pGetSecurityDescriptorGroup)(PSECURITY_DESCRIPTOR  descr, PSID*  group, LPBOOL  group_defaulted);
static WINAPI DWORD (*pGetSecurityDescriptorLength)(PSECURITY_DESCRIPTOR  descr);
static WINAPI BOOL (*pGetSecurityDescriptorOwner)(PSECURITY_DESCRIPTOR  descr, PSID*  owner, LPBOOL  owner_defaulted);
static WINAPI BOOL (*pGetSecurityDescriptorSacl)(PSECURITY_DESCRIPTOR  descr, LPBOOL  sacl_present, PACL*  sacl, LPBOOL  sacl_defaulted);
static void* pGetShortPathNameW;
static void* pextGetShortPathNameW;
static WINAPI PSID_IDENTIFIER_AUTHORITY (*pGetSidIdentifierAuthority)(PSID  sid);
static WINAPI DWORD (*pGetSidLengthRequired)(BYTE  count);
static WINAPI PDWORD (*pGetSidSubAuthority)(PSID  sid, DWORD  auth);
static WINAPI PUCHAR (*pGetSidSubAuthorityCount)(PSID  sid);
static void* pGetStartupInfoW;
static void* pextGetStartupInfoW;
static void* pGetStdHandle;
static void* pextGetStdHandle;
static void* pGetStringTypeA;
static void* pextGetStringTypeA;
static void* pGetStringTypeExW;
static void* pextGetStringTypeExW;
static void* pGetStringTypeW;
static void* pextGetStringTypeW;
static void* pGetSystemDefaultLCID;
static void* pextGetSystemDefaultLCID;
static void* pGetSystemDefaultLangID;
static void* pextGetSystemDefaultLangID;
static void* pGetSystemDefaultLocaleName;
static void* pextGetSystemDefaultLocaleName;
static void* pGetSystemDefaultUILanguage;
static void* pextGetSystemDefaultUILanguage;
static WINAPI UINT (*pGetSystemDirectoryA)(LPSTR  path, UINT  count);
static WINAPI UINT (*pGetSystemDirectoryW)(LPWSTR  path, UINT  count);
static void* pGetSystemFileCacheSize;
static void* pextGetSystemFileCacheSize;
static void* pGetSystemFirmwareTable;
static void* pextGetSystemFirmwareTable;
static void* pGetSystemInfo;
static void* pextGetSystemInfo;
static void* pGetSystemPreferredUILanguages;
static void* pextGetSystemPreferredUILanguages;
static void* pGetSystemTime;
static void* pextGetSystemTime;
static void* pGetSystemTimeAdjustment;
static void* pextGetSystemTimeAdjustment;
static void* pGetSystemTimeAsFileTime;
static void* pextGetSystemTimeAsFileTime;
static void* pGetSystemTimePreciseAsFileTime;
static void* pextGetSystemTimePreciseAsFileTime;
static void* pGetSystemTimes;
static void* pextGetSystemTimes;
static WINAPI UINT (*pGetSystemWindowsDirectoryA)(LPSTR  path, UINT  count);
static WINAPI UINT (*pGetSystemWindowsDirectoryW)(LPWSTR  path, UINT  count);
static void* pGetSystemWow64DirectoryA;
static void* pextGetSystemWow64DirectoryA;
static void* pGetSystemWow64DirectoryW;
static void* pextGetSystemWow64DirectoryW;
static void* pGetTempFileNameA;
static void* pextGetTempFileNameA;
static void* pGetTempFileNameW;
static void* pextGetTempFileNameW;
static void* pGetTempPathA;
static void* pextGetTempPathA;
static void* pGetTempPathW;
static void* pextGetTempPathW;
static WINAPI BOOL (*pGetThreadContext)(HANDLE  thread, CONTEXT*  context);
static WINAPI DWORD (*pGetThreadErrorMode)(void);
static WINAPI BOOL (*pGetThreadGroupAffinity)(HANDLE  thread, GROUP_AFFINITY*  affinity);
static WINAPI BOOL (*pGetThreadIOPendingFlag)(HANDLE  thread, PBOOL  pending);
static WINAPI DWORD (*pGetThreadId)(HANDLE  thread);
static void* pGetThreadLocale;
static void* pextGetThreadLocale;
static void* pGetThreadPreferredUILanguages;
static void* pextGetThreadPreferredUILanguages;
static WINAPI INT (*pGetThreadPriority)(HANDLE  thread);
static WINAPI BOOL (*pGetThreadPriorityBoost)(HANDLE  thread, BOOL*  state);
static WINAPI BOOL (*pGetThreadTimes)(HANDLE  thread, LPFILETIME  creationtime, LPFILETIME  exittime, LPFILETIME  kerneltime, LPFILETIME  usertime);
static WINAPI LANGID (*pGetThreadUILanguage)(void);
static void* pGetTickCount;
static void* pextGetTickCount;
static void* pGetTickCount64;
static void* pextGetTickCount64;
static void* pGetTimeFormatA;
static void* pextGetTimeFormatA;
static void* pGetTimeFormatEx;
static void* pextGetTimeFormatEx;
static void* pGetTimeFormatW;
static void* pextGetTimeFormatW;
static void* pGetTimeZoneInformation;
static void* pextGetTimeZoneInformation;
static void* pGetTimeZoneInformationForYear;
static void* pextGetTimeZoneInformationForYear;
static WINAPI BOOL (*pGetTokenInformation)(HANDLE  token, TOKEN_INFORMATION_CLASS  class, LPVOID  info, DWORD  len, LPDWORD  retlen);
static void* pGetTraceEnableFlags;
static void* pextGetTraceEnableFlags;
static void* pGetTraceEnableLevel;
static void* pextGetTraceEnableLevel;
static void* pGetTraceLoggerHandle;
static void* pextGetTraceLoggerHandle;
static void* pGetUserDefaultLCID;
static void* pextGetUserDefaultLCID;
static void* pGetUserDefaultLangID;
static void* pextGetUserDefaultLangID;
static void* pGetUserDefaultLocaleName;
static void* pextGetUserDefaultLocaleName;
static void* pGetUserDefaultUILanguage;
static void* pextGetUserDefaultUILanguage;
static void* pGetUserGeoID;
static void* pextGetUserGeoID;
static void* pGetUserPreferredUILanguages;
static void* pextGetUserPreferredUILanguages;
static void* pGetVersion;
static void* pextGetVersion;
static void* pGetVersionExA;
static void* pextGetVersionExA;
static void* pGetVersionExW;
static void* pextGetVersionExW;
static void* pGetVolumeInformationA;
static void* pextGetVolumeInformationA;
static void* pGetVolumeInformationByHandleW;
static void* pextGetVolumeInformationByHandleW;
static void* pGetVolumeInformationW;
static void* pextGetVolumeInformationW;
static void* pGetVolumeNameForVolumeMountPointW;
static void* pextGetVolumeNameForVolumeMountPointW;
static void* pGetVolumePathNameW;
static void* pextGetVolumePathNameW;
static void* pGetVolumePathNamesForVolumeNameW;
static void* pextGetVolumePathNamesForVolumeNameW;
static WINAPI BOOL (*pGetWindowsAccountDomainSid)(PSID  sid, PSID  domain_sid, DWORD*  size);
static WINAPI UINT (*pGetWindowsDirectoryA)(LPSTR  path, UINT  count);
static WINAPI UINT (*pGetWindowsDirectoryW)(LPWSTR  path, UINT  count);
static void* pGetWriteWatch;
static void* pextGetWriteWatch;
static void* pGlobalAlloc;
static void* pextGlobalAlloc;
static void* pGlobalFree;
static void* pextGlobalFree;
static void* pGlobalMemoryStatusEx;
static void* pextGlobalMemoryStatusEx;
static WINAPI HRESULT (*pHashData)(unsigned char*  src, DWORD  src_len, unsigned char*  dest, DWORD  dest_len);
static void* pHeapAlloc;
static void* pextHeapAlloc;
static void* pHeapCompact;
static void* pextHeapCompact;
static void* pHeapCreate;
static void* pextHeapCreate;
static void* pHeapDestroy;
static void* pextHeapDestroy;
static void* pHeapFree;
static void* pextHeapFree;
static void* pHeapLock;
static void* pextHeapLock;
static void* pHeapQueryInformation;
static void* pextHeapQueryInformation;
static void* pHeapReAlloc;
static void* pextHeapReAlloc;
static void* pHeapSetInformation;
static void* pextHeapSetInformation;
static void* pHeapSize;
static void* pextHeapSize;
static void* pHeapUnlock;
static void* pextHeapUnlock;
static void* pHeapValidate;
static void* pextHeapValidate;
static void* pHeapWalk;
static void* pextHeapWalk;
static void* pIdnToAscii;
static void* pextIdnToAscii;
static void* pIdnToNameprepUnicode;
static void* pextIdnToNameprepUnicode;
static void* pIdnToUnicode;
static void* pextIdnToUnicode;
static WINAPI BOOL (*pImpersonateAnonymousToken)(HANDLE  thread);
static WINAPI BOOL (*pImpersonateLoggedOnUser)(HANDLE  token);
static WINAPI BOOL (*pImpersonateNamedPipeClient)(HANDLE  pipe);
static WINAPI BOOL (*pImpersonateSelf)(SECURITY_IMPERSONATION_LEVEL  level);
static void* pInitOnceBeginInitialize;
static void* pextInitOnceBeginInitialize;
static void* pInitOnceComplete;
static void* pextInitOnceComplete;
static void* pInitOnceExecuteOnce;
static void* pextInitOnceExecuteOnce;
static void* pInitOnceInitialize;
static void* pextInitOnceInitialize;
static WINAPI BOOL (*pInitializeAcl)(PACL  acl, DWORD  size, DWORD  rev);
static void* pInitializeConditionVariable;
static void* pextInitializeConditionVariable;
static void* pInitializeCriticalSection;
static void* pextInitializeCriticalSection;
static WINAPI BOOL (*pInitializeCriticalSectionAndSpinCount)(CRITICAL_SECTION*  crit, DWORD  count);
static WINAPI BOOL (*pInitializeCriticalSectionEx)(CRITICAL_SECTION*  crit, DWORD  spincount, DWORD  flags);
static WINAPI BOOL (*pInitializeProcThreadAttributeList)(struct _PROC_THREAD_ATTRIBUTE_LIST*  list, DWORD  count, DWORD  flags, SIZE_T*  size);
static void* pInitializeSListHead;
static void* pextInitializeSListHead;
static void* pInitializeSRWLock;
static void* pextInitializeSRWLock;
static WINAPI BOOL (*pInitializeSecurityDescriptor)(PSECURITY_DESCRIPTOR  descr, DWORD  revision);
static WINAPI BOOL (*pInitializeSid)(PSID  sid, PSID_IDENTIFIER_AUTHORITY  auth, BYTE  count);
static void* pInterlockedCompareExchange;
static void* pextInterlockedCompareExchange;
static void* pInterlockedCompareExchange64;
static void* pextInterlockedCompareExchange64;
static void* pInterlockedDecrement;
static void* pextInterlockedDecrement;
static void* pInterlockedExchange;
static void* pextInterlockedExchange;
static void* pInterlockedExchangeAdd;
static void* pextInterlockedExchangeAdd;
static void* pInterlockedFlushSList;
static void* pextInterlockedFlushSList;
static void* pInterlockedIncrement;
static void* pextInterlockedIncrement;
static void* pInterlockedPopEntrySList;
static void* pextInterlockedPopEntrySList;
static void* pInterlockedPushEntrySList;
static void* pextInterlockedPushEntrySList;
static void* pInterlockedPushListSList;
static void* pextInterlockedPushListSList;
static void* pInterlockedPushListSListEx;
static void* pextInterlockedPushListSListEx;
static WINAPI BOOL (*pIsCharAlphaA)(CHAR  x);
static WINAPI BOOL (*pIsCharAlphaNumericA)(CHAR  x);
static WINAPI BOOL (*pIsCharAlphaNumericW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharAlphaW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharBlankW)(WCHAR  wc);
static WINAPI BOOL (*pIsCharCntrlW)(WCHAR  wc);
static WINAPI BOOL (*pIsCharDigitW)(WCHAR  wc);
static WINAPI BOOL (*pIsCharLowerA)(CHAR  x);
static WINAPI BOOL (*pIsCharLowerW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharPunctW)(WCHAR  wc);
static WINAPI BOOL (*pIsCharSpaceA)(CHAR  c);
static WINAPI BOOL (*pIsCharSpaceW)(WCHAR  wc);
static WINAPI BOOL (*pIsCharUpperA)(CHAR  x);
static WINAPI BOOL (*pIsCharUpperW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharXDigitW)(WCHAR  wc);
static void* pIsDBCSLeadByte;
static void* pextIsDBCSLeadByte;
static void* pIsDBCSLeadByteEx;
static void* pextIsDBCSLeadByteEx;
static void* pIsDebuggerPresent;
static void* pextIsDebuggerPresent;
static WINAPI BOOL (*pIsInternetESCEnabled)(void);
static void* pIsNormalizedString;
static void* pextIsNormalizedString;
static void* pIsProcessInJob;
static void* pextIsProcessInJob;
static void* pIsProcessorFeaturePresent;
static void* pextIsProcessorFeaturePresent;
static WINAPI BOOL (*pIsThreadAFiber)(void);
static void* pIsThreadpoolTimerSet;
static void* pextIsThreadpoolTimerSet;
static WINAPI BOOL (*pIsTokenRestricted)(HANDLE  token);
static WINAPI BOOL (*pIsValidAcl)(PACL  acl);
static void* pIsValidCodePage;
static void* pextIsValidCodePage;
static void* pIsValidLanguageGroup;
static void* pextIsValidLanguageGroup;
static void* pIsValidLocale;
static void* pextIsValidLocale;
static void* pIsValidLocaleName;
static void* pextIsValidLocaleName;
static WINAPI BOOL (*pIsValidSecurityDescriptor)(PSECURITY_DESCRIPTOR  descr);
static WINAPI BOOL (*pIsValidSid)(PSID  sid);
static WINAPI BOOL (*pIsWellKnownSid)(PSID  sid, WELL_KNOWN_SID_TYPE  type);
static WINAPI BOOL (*pIsWow64Process)(HANDLE  process, PBOOL  wow64);
static void* pK32EmptyWorkingSet;
static void* pextK32EmptyWorkingSet;
static void* pK32EnumDeviceDrivers;
static void* pextK32EnumDeviceDrivers;
static void* pK32EnumPageFilesA;
static void* pextK32EnumPageFilesA;
static void* pK32EnumPageFilesW;
static void* pextK32EnumPageFilesW;
static void* pK32EnumProcessModules;
static void* pextK32EnumProcessModules;
static void* pK32EnumProcessModulesEx;
static void* pextK32EnumProcessModulesEx;
static void* pK32EnumProcesses;
static void* pextK32EnumProcesses;
static void* pK32GetDeviceDriverBaseNameA;
static void* pextK32GetDeviceDriverBaseNameA;
static void* pK32GetDeviceDriverBaseNameW;
static void* pextK32GetDeviceDriverBaseNameW;
static void* pK32GetDeviceDriverFileNameA;
static void* pextK32GetDeviceDriverFileNameA;
static void* pK32GetDeviceDriverFileNameW;
static void* pextK32GetDeviceDriverFileNameW;
static void* pK32GetMappedFileNameA;
static void* pextK32GetMappedFileNameA;
static void* pK32GetMappedFileNameW;
static void* pextK32GetMappedFileNameW;
static void* pK32GetModuleBaseNameA;
static void* pextK32GetModuleBaseNameA;
static void* pK32GetModuleBaseNameW;
static void* pextK32GetModuleBaseNameW;
static void* pK32GetModuleFileNameExA;
static void* pextK32GetModuleFileNameExA;
static void* pK32GetModuleFileNameExW;
static void* pextK32GetModuleFileNameExW;
static void* pK32GetModuleInformation;
static void* pextK32GetModuleInformation;
static void* pK32GetPerformanceInfo;
static void* pextK32GetPerformanceInfo;
static void* pK32GetProcessImageFileNameA;
static void* pextK32GetProcessImageFileNameA;
static void* pK32GetProcessImageFileNameW;
static void* pextK32GetProcessImageFileNameW;
static void* pK32GetProcessMemoryInfo;
static void* pextK32GetProcessMemoryInfo;
static void* pK32GetWsChanges;
static void* pextK32GetWsChanges;
static void* pK32GetWsChangesEx;
static void* pextK32GetWsChangesEx;
static void* pK32InitializeProcessForWsWatch;
static void* pextK32InitializeProcessForWsWatch;
static void* pK32QueryWorkingSet;
static void* pextK32QueryWorkingSet;
static void* pK32QueryWorkingSetEx;
static void* pextK32QueryWorkingSetEx;
static void* pLCIDToLocaleName;
static void* pextLCIDToLocaleName;
static void* pLCMapStringA;
static void* pextLCMapStringA;
static void* pLCMapStringEx;
static void* pextLCMapStringEx;
static void* pLCMapStringW;
static void* pextLCMapStringW;
static void* pLeaveCriticalSection;
static void* pextLeaveCriticalSection;
static void* pLeaveCriticalSectionWhenCallbackReturns;
static void* pextLeaveCriticalSectionWhenCallbackReturns;
static void* pLoadLibraryA;
static void* pextLoadLibraryA;
static void* pLoadLibraryExA;
static void* pextLoadLibraryExA;
static void* pLoadLibraryExW;
static void* pextLoadLibraryExW;
static void* pLoadLibraryW;
static void* pextLoadLibraryW;
static WINAPI HGLOBAL (*pLoadResource)(HINSTANCE  module, HRSRC  rsrc);
static WINAPI INT (*pLoadStringA)(HINSTANCE  instance, UINT  resource_id, LPSTR  buffer, INT  buflen);
static WINAPI INT (*pLoadStringW)(HINSTANCE  instance, UINT  resource_id, LPWSTR  buffer, INT  buflen);
static void* pLocalAlloc;
static void* pextLocalAlloc;
static void* pLocalFileTimeToFileTime;
static void* pextLocalFileTimeToFileTime;
static void* pLocalFree;
static void* pextLocalFree;
static void* pLocalLock;
static void* pextLocalLock;
static void* pLocalReAlloc;
static void* pextLocalReAlloc;
static void* pLocalUnlock;
static void* pextLocalUnlock;
static void* pLocaleNameToLCID;
static void* pextLocaleNameToLCID;
static WINAPI BOOL (*pLockFile)(HANDLE  file, DWORD  offset_low, DWORD  offset_high, DWORD  count_low, DWORD  count_high);
static WINAPI BOOL (*pLockFileEx)(HANDLE  file, DWORD  flags, DWORD  reserved, DWORD  count_low, DWORD  count_high, LPOVERLAPPED  overlapped);
static WINAPI LPVOID (*pLockResource)(HGLOBAL  handle);
static WINAPI BOOL (*pMakeAbsoluteSD)(PSECURITY_DESCRIPTOR  rel_descr, PSECURITY_DESCRIPTOR  abs_descr, LPDWORD  abs_size, PACL  dacl, LPDWORD  dacl_size, PACL  sacl, LPDWORD  sacl_size, PSID  owner, LPDWORD  owner_size, PSID  group, LPDWORD  group_size);
static WINAPI BOOL (*pMakeSelfRelativeSD)(PSECURITY_DESCRIPTOR  abs_descr, PSECURITY_DESCRIPTOR  rel_descr, LPDWORD  len);
static WINAPI void (*pMapGenericMask)(PDWORD  access, PGENERIC_MAPPING  mapping);
static void* pMapUserPhysicalPages;
static void* pextMapUserPhysicalPages;
static void* pMapViewOfFile;
static void* pextMapViewOfFile;
static void* pMapViewOfFileEx;
static void* pextMapViewOfFileEx;
static void* pMoveFileExW;
static void* pextMoveFileExW;
static void* pMoveFileWithProgressW;
static void* pextMoveFileWithProgressW;
static void* pMulDiv;
static void* pextMulDiv;
static void* pMultiByteToWideChar;
static void* pextMultiByteToWideChar;
static void* pNeedCurrentDirectoryForExePathA;
static void* pextNeedCurrentDirectoryForExePathA;
static void* pNeedCurrentDirectoryForExePathW;
static void* pextNeedCurrentDirectoryForExePathW;
static void* pNormalizeString;
static void* pextNormalizeString;
static WINAPI BOOL (*pObjectCloseAuditAlarmW)(LPCWSTR  subsystem, LPVOID  id, BOOL  on_close);
static WINAPI BOOL (*pObjectDeleteAuditAlarmW)(LPCWSTR  subsystem, LPVOID  id, BOOL  on_close);
static WINAPI BOOL (*pObjectOpenAuditAlarmW)(LPCWSTR  subsystem, LPVOID  id, LPWSTR  type, LPWSTR  name, PSECURITY_DESCRIPTOR  descr, HANDLE  token, DWORD  desired, DWORD  granted, PPRIVILEGE_SET  privs, BOOL  creation, BOOL  access, LPBOOL  on_close);
static WINAPI BOOL (*pObjectPrivilegeAuditAlarmW)(LPCWSTR  subsystem, LPVOID  id, HANDLE  token, DWORD  desired, PPRIVILEGE_SET  privs, BOOL  granted);
static WINAPI HANDLE (*pOpenEventA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static WINAPI HANDLE (*pOpenEventW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static WINAPI HANDLE (*pOpenFileById)(HANDLE  handle, LPFILE_ID_DESCRIPTOR  id, DWORD  access, DWORD  share, LPSECURITY_ATTRIBUTES  sec_attr, DWORD  flags);
static WINAPI HANDLE (*pOpenFileMappingW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static WINAPI HANDLE (*pOpenMutexW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static WINAPI HANDLE (*pOpenProcess)(DWORD  access, BOOL  inherit, DWORD  id);
static WINAPI BOOL (*pOpenProcessToken)(HANDLE  process, DWORD  access, HANDLE*  handle);
static WINAPI HANDLE (*pOpenSemaphoreW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static WINAPI HANDLE (*pOpenThread)(DWORD  access, BOOL  inherit, DWORD  id);
static WINAPI BOOL (*pOpenThreadToken)(HANDLE  thread, DWORD  access, BOOL  self, HANDLE*  handle);
static WINAPI HANDLE (*pOpenWaitableTimerW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static void* pOutputDebugStringA;
static void* pextOutputDebugStringA;
static void* pOutputDebugStringW;
static void* pextOutputDebugStringW;
static WINAPI HRESULT (*pParseURLA)(char*  url, PARSEDURLA*  result);
static WINAPI HRESULT (*pParseURLW)(WCHAR*  url, PARSEDURLW*  result);
static WINAPI LPSTR (*pPathAddBackslashA)(char*  path);
static WINAPI LPWSTR (*pPathAddBackslashW)(WCHAR*  path);
static WINAPI BOOL (*pPathAddExtensionA)(char*  path, char*  ext);
static WINAPI BOOL (*pPathAddExtensionW)(WCHAR*  path, WCHAR*  ext);
static WINAPI HRESULT (*pPathAllocCanonicalize)(WCHAR*  path_in, DWORD  flags, WCHAR**  path_out);
static WINAPI HRESULT (*pPathAllocCombine)(WCHAR*  path1, WCHAR*  path2, DWORD  flags, WCHAR**  out);
static WINAPI BOOL (*pPathAppendA)(char*  path, char*  append);
static WINAPI BOOL (*pPathAppendW)(WCHAR*  path, WCHAR*  append);
static WINAPI BOOL (*pPathCanonicalizeA)(char*  buffer, char*  path);
static WINAPI BOOL (*pPathCanonicalizeW)(WCHAR*  buffer, WCHAR*  path);
static WINAPI HRESULT (*pPathCchAddBackslash)(WCHAR*  path, SIZE_T  size);
static WINAPI HRESULT (*pPathCchAddBackslashEx)(WCHAR*  path, SIZE_T  size, WCHAR**  endptr, SIZE_T*  remaining);
static WINAPI HRESULT (*pPathCchAddExtension)(WCHAR*  path, SIZE_T  size, WCHAR*  extension);
static WINAPI HRESULT (*pPathCchAppend)(WCHAR*  path1, SIZE_T  size, WCHAR*  path2);
static WINAPI HRESULT (*pPathCchAppendEx)(WCHAR*  path1, SIZE_T  size, WCHAR*  path2, DWORD  flags);
static WINAPI HRESULT (*pPathCchCanonicalize)(WCHAR*  out, SIZE_T  size, WCHAR*  in);
static WINAPI HRESULT (*pPathCchCanonicalizeEx)(WCHAR*  out, SIZE_T  size, WCHAR*  in, DWORD  flags);
static WINAPI HRESULT (*pPathCchCombine)(WCHAR*  out, SIZE_T  size, WCHAR*  path1, WCHAR*  path2);
static WINAPI HRESULT (*pPathCchCombineEx)(WCHAR*  out, SIZE_T  size, WCHAR*  path1, WCHAR*  path2, DWORD  flags);
static WINAPI HRESULT (*pPathCchFindExtension)(WCHAR*  path, SIZE_T  size, WCHAR**  extension);
static WINAPI BOOL (*pPathCchIsRoot)(WCHAR*  path);
static WINAPI HRESULT (*pPathCchRemoveBackslash)(WCHAR*  path, SIZE_T  path_size);
static WINAPI HRESULT (*pPathCchRemoveBackslashEx)(WCHAR*  path, SIZE_T  path_size, WCHAR**  path_end, SIZE_T*  free_size);
static WINAPI HRESULT (*pPathCchRemoveExtension)(WCHAR*  path, SIZE_T  size);
static WINAPI HRESULT (*pPathCchRemoveFileSpec)(WCHAR*  path, SIZE_T  size);
static WINAPI HRESULT (*pPathCchRenameExtension)(WCHAR*  path, SIZE_T  size, WCHAR*  extension);
static WINAPI HRESULT (*pPathCchSkipRoot)(WCHAR*  path, WCHAR**  root_end);
static WINAPI HRESULT (*pPathCchStripPrefix)(WCHAR*  path, SIZE_T  size);
static WINAPI HRESULT (*pPathCchStripToRoot)(WCHAR*  path, SIZE_T  size);
static WINAPI LPSTR (*pPathCombineA)(char*  dst, char*  dir, char*  file);
static WINAPI LPWSTR (*pPathCombineW)(WCHAR*  dst, WCHAR*  dir, WCHAR*  file);
static WINAPI int (*pPathCommonPrefixA)(char*  file1, char*  file2, char*  path);
static WINAPI int (*pPathCommonPrefixW)(WCHAR*  file1, WCHAR*  file2, WCHAR*  path);
static WINAPI HRESULT (*pPathCreateFromUrlA)(char*  pszUrl, char*  pszPath, DWORD*  pcchPath, DWORD  dwReserved);
static WINAPI HRESULT (*pPathCreateFromUrlAlloc)(WCHAR*  url, WCHAR**  path, DWORD  reserved);
static WINAPI HRESULT (*pPathCreateFromUrlW)(WCHAR*  url, WCHAR*  path, DWORD*  pcchPath, DWORD  dwReserved);
static WINAPI BOOL (*pPathFileExistsA)(char*  path);
static WINAPI BOOL (*pPathFileExistsW)(WCHAR*  path);
static WINAPI LPSTR (*pPathFindExtensionA)(char*  path);
static WINAPI LPWSTR (*pPathFindExtensionW)(WCHAR*  path);
static WINAPI LPSTR (*pPathFindFileNameA)(char*  path);
static WINAPI LPWSTR (*pPathFindFileNameW)(WCHAR*  path);
static WINAPI LPSTR (*pPathFindNextComponentA)(char*  path);
static WINAPI LPWSTR (*pPathFindNextComponentW)(WCHAR*  path);
static WINAPI LPSTR (*pPathGetArgsA)(char*  path);
static WINAPI LPWSTR (*pPathGetArgsW)(WCHAR*  path);
static WINAPI UINT (*pPathGetCharTypeA)(UCHAR  ch);
static WINAPI UINT (*pPathGetCharTypeW)(WCHAR  ch);
static WINAPI int (*pPathGetDriveNumberA)(char*  path);
static WINAPI int (*pPathGetDriveNumberW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsFileSpecA)(char*  path);
static WINAPI BOOL (*pPathIsFileSpecW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsLFNFileSpecA)(char*  path);
static WINAPI BOOL (*pPathIsLFNFileSpecW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsPrefixA)(char*  prefix, char*  path);
static WINAPI BOOL (*pPathIsPrefixW)(WCHAR*  prefix, WCHAR*  path);
static WINAPI BOOL (*pPathIsRelativeA)(char*  path);
static WINAPI BOOL (*pPathIsRelativeW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsRootA)(char*  path);
static WINAPI BOOL (*pPathIsRootW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsSameRootA)(char*  path1, char*  path2);
static WINAPI BOOL (*pPathIsSameRootW)(WCHAR*  path1, WCHAR*  path2);
static WINAPI BOOL (*pPathIsUNCA)(char*  path);
static WINAPI BOOL (*pPathIsUNCEx)(WCHAR*  path, WCHAR**  server);
static WINAPI BOOL (*pPathIsUNCServerA)(char*  path);
static WINAPI BOOL (*pPathIsUNCServerShareA)(char*  path);
static WINAPI BOOL (*pPathIsUNCServerShareW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsUNCServerW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsUNCW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsURLA)(char*  path);
static WINAPI BOOL (*pPathIsURLW)(WCHAR*  path);
static WINAPI BOOL (*pPathIsValidCharA)(char  c, DWORD  class);
static WINAPI BOOL (*pPathIsValidCharW)(WCHAR  c, DWORD  class);
static WINAPI BOOL (*pPathMatchSpecA)(char*  path, char*  mask);
static WINAPI BOOL (*pPathMatchSpecW)(WCHAR*  path, WCHAR*  mask);
static WINAPI int (*pPathParseIconLocationA)(char*  path);
static WINAPI int (*pPathParseIconLocationW)(WCHAR*  path);
static WINAPI void (*pPathQuoteSpacesA)(char*  path);
static WINAPI void (*pPathQuoteSpacesW)(WCHAR*  path);
static WINAPI BOOL (*pPathRelativePathToA)(char*  path, char*  from, DWORD  attributes_from, char*  to, DWORD  attributes_to);
static WINAPI BOOL (*pPathRelativePathToW)(WCHAR*  path, WCHAR*  from, DWORD  attributes_from, WCHAR*  to, DWORD  attributes_to);
static WINAPI LPSTR (*pPathRemoveBackslashA)(char*  path);
static WINAPI LPWSTR (*pPathRemoveBackslashW)(WCHAR*  path);
static WINAPI void (*pPathRemoveBlanksA)(char*  path);
static WINAPI void (*pPathRemoveBlanksW)(WCHAR*  path);
static WINAPI void (*pPathRemoveExtensionA)(char*  path);
static WINAPI void (*pPathRemoveExtensionW)(WCHAR*  path);
static WINAPI BOOL (*pPathRemoveFileSpecA)(char*  path);
static WINAPI BOOL (*pPathRemoveFileSpecW)(WCHAR*  path);
static WINAPI BOOL (*pPathRenameExtensionA)(char*  path, char*  ext);
static WINAPI BOOL (*pPathRenameExtensionW)(WCHAR*  path, WCHAR*  ext);
static WINAPI BOOL (*pPathSearchAndQualifyA)(char*  path, char*  buffer, UINT  length);
static WINAPI BOOL (*pPathSearchAndQualifyW)(WCHAR*  path, WCHAR*  buffer, UINT  length);
static WINAPI LPSTR (*pPathSkipRootA)(char*  path);
static WINAPI LPWSTR (*pPathSkipRootW)(WCHAR*  path);
static WINAPI void (*pPathStripPathA)(char*  path);
static WINAPI void (*pPathStripPathW)(WCHAR*  path);
static WINAPI BOOL (*pPathStripToRootA)(char*  path);
static WINAPI BOOL (*pPathStripToRootW)(WCHAR*  path);
static WINAPI BOOL (*pPathUnExpandEnvStringsA)(char*  path, char*  buffer, UINT  buf_len);
static WINAPI BOOL (*pPathUnExpandEnvStringsW)(WCHAR*  path, WCHAR*  buffer, UINT  buf_len);
static WINAPI void (*pPathUnquoteSpacesA)(char*  path);
static WINAPI void (*pPathUnquoteSpacesW)(WCHAR*  path);
static void* pPeekConsoleInputA;
static void* pextPeekConsoleInputA;
static void* pPeekConsoleInputW;
static void* pextPeekConsoleInputW;
static WINAPI BOOL (*pPeekNamedPipe)(HANDLE  pipe, LPVOID  out_buffer, DWORD  size, LPDWORD  read_size, LPDWORD  avail, LPDWORD  message);
static WINAPI PPERF_COUNTERSET_INSTANCE (*pPerfCreateInstance)(HANDLE  handle, LPCGUID  guid, WCHAR*  name, ULONG  id);
static WINAPI ULONG (*pPerfDeleteInstance)(HANDLE  provider, PPERF_COUNTERSET_INSTANCE  block);
static WINAPI ULONG (*pPerfSetCounterRefValue)(HANDLE  provider, PPERF_COUNTERSET_INSTANCE  instance, ULONG  counterid, void*  address);
static WINAPI ULONG (*pPerfSetCounterSetInfo)(HANDLE  handle, PPERF_COUNTERSET_INFO  template, ULONG  size);
static WINAPI ULONG (*pPerfStartProvider)(GUID*  guid, PERFLIBREQUEST  callback, HANDLE*  provider);
static WINAPI ULONG (*pPerfStartProviderEx)(GUID*  guid, PPERF_PROVIDER_CONTEXT  context, HANDLE*  provider);
static WINAPI ULONG (*pPerfStopProvider)(HANDLE  handle);
static WINAPI BOOL (*pPostQueuedCompletionStatus)(HANDLE  port, DWORD  count, ULONG_PTR  key, LPOVERLAPPED  overlapped);
static WINAPI BOOL (*pPrivilegeCheck)(HANDLE  token, PPRIVILEGE_SET  privs, LPBOOL  result);
static WINAPI BOOL (*pPrivilegedServiceAuditAlarmW)(LPCWSTR  subsystem, LPCWSTR  service, HANDLE  token, PPRIVILEGE_SET  privs, BOOL  granted);
static void* pProcessIdToSessionId;
static void* pextProcessIdToSessionId;
static WINAPI BOOL (*pPulseEvent)(HANDLE  handle);
static void* pPurgeComm;
static void* pextPurgeComm;
static WINAPI HRESULT (*pQISearch)(void*  base, QITAB*  table, IID*  riid, void**  obj);
static WINAPI BOOL (*pQueryActCtxSettingsW)(DWORD  flags, HANDLE  ctx, WCHAR*  ns, WCHAR*  settings, WCHAR*  buffer, SIZE_T  size, SIZE_T*  written);
static WINAPI BOOL (*pQueryActCtxW)(DWORD  flags, HANDLE  context, PVOID  inst, ULONG  class, PVOID  buffer, SIZE_T  size, SIZE_T*  written);
static void* pQueryDepthSList;
static void* pextQueryDepthSList;
static void* pQueryDosDeviceW;
static void* pextQueryDosDeviceW;
static void* pQueryFullProcessImageNameA;
static void* pextQueryFullProcessImageNameA;
static void* pQueryFullProcessImageNameW;
static void* pextQueryFullProcessImageNameW;
static void* pQueryMemoryResourceNotification;
static void* pextQueryMemoryResourceNotification;
static void* pQueryPerformanceCounter;
static void* pextQueryPerformanceCounter;
static void* pQueryPerformanceFrequency;
static void* pextQueryPerformanceFrequency;
static void* pQueryProcessCycleTime;
static void* pextQueryProcessCycleTime;
static void* pQueryThreadCycleTime;
static void* pextQueryThreadCycleTime;
static void* pQueryUnbiasedInterruptTime;
static void* pextQueryUnbiasedInterruptTime;
static WINAPI DWORD (*pQueueUserAPC)(PAPCFUNC  func, HANDLE  thread, ULONG_PTR  data);
static WINAPI BOOL (*pQueueUserWorkItem)(LPTHREAD_START_ROUTINE  func, PVOID  context, ULONG  flags);
static WINAPI BOOL (*pQuirkIsEnabled)(void*  arg);
static WINAPI BOOL (*pQuirkIsEnabled3)(void*  unk1, void*  unk2);
static void* pRaiseException;
static void* pextRaiseException;
static WINAPI HANDLE (*pReOpenFile)(HANDLE  handle, DWORD  access, DWORD  sharing, DWORD  flags);
static void* pReadConsoleA;
static void* pextReadConsoleA;
static void* pReadConsoleInputA;
static void* pextReadConsoleInputA;
static void* pReadConsoleInputW;
static void* pextReadConsoleInputW;
static void* pReadConsoleOutputA;
static void* pextReadConsoleOutputA;
static void* pReadConsoleOutputAttribute;
static void* pextReadConsoleOutputAttribute;
static void* pReadConsoleOutputCharacterA;
static void* pextReadConsoleOutputCharacterA;
static void* pReadConsoleOutputCharacterW;
static void* pextReadConsoleOutputCharacterW;
static void* pReadConsoleOutputW;
static void* pextReadConsoleOutputW;
static void* pReadConsoleW;
static void* pextReadConsoleW;
static void* pReadDirectoryChangesW;
static void* pextReadDirectoryChangesW;
static WINAPI BOOL (*pReadFile)(HANDLE  file, LPVOID  buffer, DWORD  count, LPDWORD  result, LPOVERLAPPED  overlapped);
static WINAPI BOOL (*pReadFileEx)(HANDLE  file, LPVOID  buffer, DWORD  count, LPOVERLAPPED  overlapped, LPOVERLAPPED_COMPLETION_ROUTINE  completion);
static WINAPI BOOL (*pReadFileScatter)(HANDLE  file, FILE_SEGMENT_ELEMENT*  segments, DWORD  count, LPDWORD  reserved, LPOVERLAPPED  overlapped);
static void* pReadProcessMemory;
static void* pextReadProcessMemory;
static WINAPI LSTATUS (*pRegCloseKey)(HKEY  hkey);
static WINAPI LSTATUS (*pRegCopyTreeW)(HKEY  hsrc, WCHAR*  subkey, HKEY  hdst);
static WINAPI LSTATUS (*pRegCreateKeyExA)(HKEY  hkey, LPCSTR  name, DWORD  reserved, LPSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos);
static WINAPI LSTATUS (*pRegCreateKeyExW)(HKEY  hkey, LPCWSTR  name, DWORD  reserved, LPWSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos);
static WINAPI LSTATUS (*pRegDeleteKeyExA)(HKEY  hkey, LPCSTR  name, REGSAM  access, DWORD  reserved);
static WINAPI LSTATUS (*pRegDeleteKeyExW)(HKEY  hkey, LPCWSTR  name, REGSAM  access, DWORD  reserved);
static WINAPI LSTATUS (*pRegDeleteKeyValueA)(HKEY  hkey, LPCSTR  subkey, LPCSTR  name);
static WINAPI LSTATUS (*pRegDeleteKeyValueW)(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  name);
static WINAPI LSTATUS (*pRegDeleteTreeA)(HKEY  hkey, char*  subkey);
static WINAPI LSTATUS (*pRegDeleteTreeW)(HKEY  hkey, WCHAR*  subkey);
static WINAPI LSTATUS (*pRegDeleteValueA)(HKEY  hkey, LPCSTR  name);
static WINAPI LSTATUS (*pRegDeleteValueW)(HKEY  hkey, LPCWSTR  name);
static WINAPI LSTATUS (*pRegEnumKeyExA)(HKEY  hkey, DWORD  index, LPSTR  name, LPDWORD  name_len, LPDWORD  reserved, LPSTR  class, LPDWORD  class_len, FILETIME*  ft);
static WINAPI LSTATUS (*pRegEnumKeyExW)(HKEY  hkey, DWORD  index, LPWSTR  name, LPDWORD  name_len, LPDWORD  reserved, LPWSTR  class, LPDWORD  class_len, FILETIME*  ft);
static WINAPI LSTATUS (*pRegEnumValueA)(HKEY  hkey, DWORD  index, LPSTR  value, LPDWORD  val_count, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count);
static WINAPI LSTATUS (*pRegEnumValueW)(HKEY  hkey, DWORD  index, LPWSTR  value, LPDWORD  val_count, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count);
static WINAPI LSTATUS (*pRegFlushKey)(HKEY  hkey);
static WINAPI LSTATUS (*pRegGetKeySecurity)(HKEY  hkey, SECURITY_INFORMATION  SecurityInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, LPDWORD  lpcbSecurityDescriptor);
static WINAPI LSTATUS (*pRegGetValueA)(HKEY  hKey, LPCSTR  pszSubKey, LPCSTR  pszValue, DWORD  dwFlags, LPDWORD  pdwType, PVOID  pvData, LPDWORD  pcbData);
static WINAPI LSTATUS (*pRegGetValueW)(HKEY  hKey, LPCWSTR  pszSubKey, LPCWSTR  pszValue, DWORD  dwFlags, LPDWORD  pdwType, PVOID  pvData, LPDWORD  pcbData);
static WINAPI LSTATUS (*pRegLoadAppKeyA)(char*  file, HKEY*  result, REGSAM  sam, DWORD  options, DWORD  reserved);
static WINAPI LSTATUS (*pRegLoadAppKeyW)(WCHAR*  file, HKEY*  result, REGSAM  sam, DWORD  options, DWORD  reserved);
static WINAPI LSTATUS (*pRegLoadKeyA)(HKEY  hkey, LPCSTR  subkey, LPCSTR  filename);
static WINAPI LSTATUS (*pRegLoadKeyW)(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  filename);
static WINAPI LSTATUS (*pRegLoadMUIStringA)(HKEY  hKey, LPCSTR  pszValue, LPSTR  pszBuffer, DWORD  cbBuffer, LPDWORD  pcbData, DWORD  dwFlags, LPCSTR  pszBaseDir);
static WINAPI LSTATUS (*pRegLoadMUIStringW)(HKEY  hKey, LPCWSTR  pwszValue, LPWSTR  pwszBuffer, DWORD  cbBuffer, LPDWORD  pcbData, DWORD  dwFlags, LPCWSTR  pwszBaseDir);
static WINAPI LSTATUS (*pRegNotifyChangeKeyValue)(HKEY  hkey, BOOL  fWatchSubTree, DWORD  fdwNotifyFilter, HANDLE  hEvent, BOOL  fAsync);
static WINAPI LSTATUS (*pRegOpenCurrentUser)(REGSAM  access, PHKEY  retkey);
static WINAPI LSTATUS (*pRegOpenKeyExA)(HKEY  hkey, LPCSTR  name, DWORD  options, REGSAM  access, PHKEY  retkey);
static WINAPI LSTATUS (*pRegOpenKeyExW)(HKEY  hkey, LPCWSTR  name, DWORD  options, REGSAM  access, PHKEY  retkey);
static WINAPI LSTATUS (*pRegOpenUserClassesRoot)(HANDLE  hToken, DWORD  dwOptions, REGSAM  samDesired, PHKEY  phkResult);
static WINAPI LSTATUS (*pRegQueryInfoKeyA)(HKEY  hkey, LPSTR  class, LPDWORD  class_len, LPDWORD  reserved, LPDWORD  subkeys, LPDWORD  max_subkey, LPDWORD  max_class, LPDWORD  values, LPDWORD  max_value, LPDWORD  max_data, LPDWORD  security, FILETIME*  modif);
static WINAPI LSTATUS (*pRegQueryInfoKeyW)(HKEY  hkey, LPWSTR  class, LPDWORD  class_len, LPDWORD  reserved, LPDWORD  subkeys, LPDWORD  max_subkey, LPDWORD  max_class, LPDWORD  values, LPDWORD  max_value, LPDWORD  max_data, LPDWORD  security, FILETIME*  modif);
static WINAPI LSTATUS (*pRegQueryValueExA)(HKEY  hkey, LPCSTR  name, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count);
static WINAPI LSTATUS (*pRegQueryValueExW)(HKEY  hkey, LPCWSTR  name, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count);
static WINAPI LSTATUS (*pRegRestoreKeyA)(HKEY  hkey, LPCSTR  lpFile, DWORD  dwFlags);
static WINAPI LSTATUS (*pRegRestoreKeyW)(HKEY  hkey, LPCWSTR  lpFile, DWORD  dwFlags);
static WINAPI LSTATUS (*pRegSaveKeyExA)(HKEY  hkey, LPCSTR  file, SECURITY_ATTRIBUTES*  sa, DWORD  flags);
static WINAPI LSTATUS (*pRegSaveKeyExW)(HKEY  hkey, LPCWSTR  file, SECURITY_ATTRIBUTES*  sa, DWORD  flags);
static WINAPI LSTATUS (*pRegSetKeySecurity)(HKEY  hkey, SECURITY_INFORMATION  SecurityInfo, PSECURITY_DESCRIPTOR  pSecurityDesc);
static WINAPI LSTATUS (*pRegSetKeyValueA)(HKEY  hkey, LPCSTR  subkey, LPCSTR  name, DWORD  type, void*  data, DWORD  len);
static WINAPI LSTATUS (*pRegSetKeyValueW)(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  name, DWORD  type, void*  data, DWORD  len);
static WINAPI LSTATUS (*pRegSetValueExA)(HKEY  hkey, LPCSTR  name, DWORD  reserved, DWORD  type, BYTE*  data, DWORD  count);
static WINAPI LSTATUS (*pRegSetValueExW)(HKEY  hkey, LPCWSTR  name, DWORD  reserved, DWORD  type, BYTE*  data, DWORD  count);
static WINAPI LSTATUS (*pRegUnLoadKeyA)(HKEY  hkey, LPCSTR  lpSubKey);
static WINAPI LSTATUS (*pRegUnLoadKeyW)(HKEY  hkey, LPCWSTR  lpSubKey);
static void* pRegisterTraceGuidsW;
static void* pextRegisterTraceGuidsW;
static WINAPI HANDLE (*pRegisterWaitForSingleObjectEx)(HANDLE  handle, WAITORTIMERCALLBACK  callback, PVOID  context, ULONG  timeout, ULONG  flags);
static WINAPI void (*pReleaseActCtx)(HANDLE  context);
static WINAPI BOOL (*pReleaseMutex)(HANDLE  handle);
static void* pReleaseMutexWhenCallbackReturns;
static void* pextReleaseMutexWhenCallbackReturns;
static void* pReleaseSRWLockExclusive;
static void* pextReleaseSRWLockExclusive;
static void* pReleaseSRWLockShared;
static void* pextReleaseSRWLockShared;
static WINAPI BOOL (*pReleaseSemaphore)(HANDLE  handle, LONG  count, LONG*  previous);
static void* pReleaseSemaphoreWhenCallbackReturns;
static void* pextReleaseSemaphoreWhenCallbackReturns;
static WINAPI NTSTATUS (*pRemapPredefinedHandleInternal)(HKEY  hkey, HKEY  override);
static void* pRemoveDirectoryA;
static void* pextRemoveDirectoryA;
static void* pRemoveDirectoryW;
static void* pextRemoveDirectoryW;
static void* pRemoveDllDirectory;
static void* pextRemoveDllDirectory;
static void* pRemoveVectoredContinueHandler;
static void* pextRemoveVectoredContinueHandler;
static void* pRemoveVectoredExceptionHandler;
static void* pextRemoveVectoredExceptionHandler;
static void* pReplaceFileW;
static void* pextReplaceFileW;
static WINAPI BOOL (*pResetEvent)(HANDLE  handle);
static void* pResetWriteWatch;
static void* pextResetWriteWatch;
static void* pResolveDelayLoadedAPI;
static void* pextResolveDelayLoadedAPI;
static void* pResolveLocaleName;
static void* pextResolveLocaleName;
static void* pRestoreLastError;
static void* pextRestoreLastError;
static WINAPI DWORD (*pResumeThread)(HANDLE  thread);
static WINAPI BOOL (*pRevertToSelf)(void);
static void* pSHExpandEnvironmentStringsA;
static void* pextSHExpandEnvironmentStringsA;
static void* pSHExpandEnvironmentStringsW;
static void* pextSHExpandEnvironmentStringsW;
static WINAPI HRESULT (*pSHLoadIndirectString)(WCHAR*  src, WCHAR*  dst, UINT  dst_len, void**  reserved);
static WINAPI LONG (*pSHRegCloseUSKey)(HUSKEY  hUSKey);
static WINAPI LONG (*pSHRegCreateUSKeyA)(LPCSTR  path, REGSAM  samDesired, HUSKEY  relative_key, PHUSKEY  new_uskey, DWORD  flags);
static WINAPI LONG (*pSHRegCreateUSKeyW)(WCHAR*  path, REGSAM  samDesired, HUSKEY  relative_key, PHUSKEY  new_uskey, DWORD  flags);
static WINAPI LONG (*pSHRegDeleteEmptyUSKeyA)(HUSKEY  hUSKey, char*  value, SHREGDEL_FLAGS  flags);
static WINAPI LONG (*pSHRegDeleteEmptyUSKeyW)(HUSKEY  hUSKey, WCHAR*  value, SHREGDEL_FLAGS  flags);
static WINAPI LONG (*pSHRegDeleteUSValueA)(HUSKEY  hUSKey, char*  value, SHREGDEL_FLAGS  flags);
static WINAPI LONG (*pSHRegDeleteUSValueW)(HUSKEY  hUSKey, WCHAR*  value, SHREGDEL_FLAGS  flags);
static WINAPI LONG (*pSHRegEnumUSKeyA)(HUSKEY  hUSKey, DWORD  index, char*  name, DWORD*  name_len, SHREGENUM_FLAGS  flags);
static WINAPI LONG (*pSHRegEnumUSKeyW)(HUSKEY  hUSKey, DWORD  index, WCHAR*  name, DWORD*  name_len, SHREGENUM_FLAGS  flags);
static WINAPI LONG (*pSHRegEnumUSValueA)(HUSKEY  hUSKey, DWORD  index, char*  value_name, DWORD*  value_name_len, DWORD*  type, void*  data, DWORD*  data_len, SHREGENUM_FLAGS  flags);
static WINAPI LONG (*pSHRegEnumUSValueW)(HUSKEY  hUSKey, DWORD  index, WCHAR*  value_name, DWORD*  value_name_len, DWORD*  type, void*  data, DWORD*  data_len, SHREGENUM_FLAGS  flags);
static WINAPI BOOL (*pSHRegGetBoolUSValueA)(char*  subkey, char*  value, BOOL  ignore_hkcu, BOOL  default_value);
static WINAPI BOOL (*pSHRegGetBoolUSValueW)(WCHAR*  subkey, WCHAR*  value, BOOL  ignore_hkcu, BOOL  default_value);
static WINAPI LONG (*pSHRegGetUSValueA)(char*  subkey, char*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len);
static WINAPI LONG (*pSHRegGetUSValueW)(WCHAR*  subkey, WCHAR*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len);
static WINAPI LONG (*pSHRegOpenUSKeyA)(char*  path, REGSAM  access_mask, HUSKEY  relative_key, HUSKEY*  uskey, BOOL  ignore_hkcu);
static WINAPI LONG (*pSHRegOpenUSKeyW)(WCHAR*  path, REGSAM  access_mask, HUSKEY  relative_key, HUSKEY*  uskey, BOOL  ignore_hkcu);
static WINAPI LONG (*pSHRegQueryInfoUSKeyA)(HUSKEY  hUSKey, DWORD*  subkeys, DWORD*  max_subkey_len, DWORD*  values, DWORD*  max_value_name_len, SHREGENUM_FLAGS  flags);
static WINAPI LONG (*pSHRegQueryInfoUSKeyW)(HUSKEY  hUSKey, DWORD*  subkeys, DWORD*  max_subkey_len, DWORD*  values, DWORD*  max_value_name_len, SHREGENUM_FLAGS  flags);
static WINAPI LONG (*pSHRegQueryUSValueA)(HUSKEY  hUSKey, char*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len);
static WINAPI LONG (*pSHRegQueryUSValueW)(HUSKEY  hUSKey, WCHAR*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len);
static WINAPI LONG (*pSHRegSetUSValueA)(char*  subkey, char*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags);
static WINAPI LONG (*pSHRegSetUSValueW)(WCHAR*  subkey, WCHAR*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags);
static WINAPI LONG (*pSHRegWriteUSValueA)(HUSKEY  hUSKey, char*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags);
static WINAPI LONG (*pSHRegWriteUSValueW)(HUSKEY  hUSKey, WCHAR*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags);
static WINAPI DWORD (*pSHTruncateString)(char*  str, DWORD  size);
static void* pScrollConsoleScreenBufferA;
static void* pextScrollConsoleScreenBufferA;
static void* pScrollConsoleScreenBufferW;
static void* pextScrollConsoleScreenBufferW;
static void* pSearchPathA;
static void* pextSearchPathA;
static void* pSearchPathW;
static void* pextSearchPathW;
static WINAPI BOOL (*pSetAclInformation)(PACL  acl, LPVOID  info, DWORD  len, ACL_INFORMATION_CLASS  class);
static void* pSetCalendarInfoW;
static void* pextSetCalendarInfoW;
static void* pSetCommBreak;
static void* pextSetCommBreak;
static void* pSetCommConfig;
static void* pextSetCommConfig;
static void* pSetCommMask;
static void* pextSetCommMask;
static void* pSetCommState;
static void* pextSetCommState;
static void* pSetCommTimeouts;
static void* pextSetCommTimeouts;
static void* pSetComputerNameA;
static void* pextSetComputerNameA;
static void* pSetComputerNameExA;
static void* pextSetComputerNameExA;
static void* pSetComputerNameExW;
static void* pextSetComputerNameExW;
static void* pSetComputerNameW;
static void* pextSetComputerNameW;
static void* pSetConsoleActiveScreenBuffer;
static void* pextSetConsoleActiveScreenBuffer;
static void* pSetConsoleCP;
static void* pextSetConsoleCP;
static void* pSetConsoleCtrlHandler;
static void* pextSetConsoleCtrlHandler;
static void* pSetConsoleCursorInfo;
static void* pextSetConsoleCursorInfo;
static void* pSetConsoleCursorPosition;
static void* pextSetConsoleCursorPosition;
static void* pSetConsoleInputExeNameA;
static void* pextSetConsoleInputExeNameA;
static void* pSetConsoleInputExeNameW;
static void* pextSetConsoleInputExeNameW;
static void* pSetConsoleMode;
static void* pextSetConsoleMode;
static void* pSetConsoleOutputCP;
static void* pextSetConsoleOutputCP;
static void* pSetConsoleScreenBufferInfoEx;
static void* pextSetConsoleScreenBufferInfoEx;
static void* pSetConsoleScreenBufferSize;
static void* pextSetConsoleScreenBufferSize;
static void* pSetConsoleTextAttribute;
static void* pextSetConsoleTextAttribute;
static void* pSetConsoleTitleW;
static void* pextSetConsoleTitleW;
static void* pSetConsoleWindowInfo;
static void* pextSetConsoleWindowInfo;
static void* pSetCriticalSectionSpinCount;
static void* pextSetCriticalSectionSpinCount;
static void* pSetCurrentDirectoryA;
static void* pextSetCurrentDirectoryA;
static void* pSetCurrentDirectoryW;
static void* pextSetCurrentDirectoryW;
static void* pSetDefaultDllDirectories;
static void* pextSetDefaultDllDirectories;
static WINAPI BOOL (*pSetEndOfFile)(HANDLE  file);
static void* pSetEnvironmentVariableA;
static void* pextSetEnvironmentVariableA;
static void* pSetEnvironmentVariableW;
static void* pextSetEnvironmentVariableW;
static WINAPI UINT (*pSetErrorMode)(UINT  mode);
static WINAPI BOOL (*pSetEvent)(HANDLE  handle);
static void* pSetEventWhenCallbackReturns;
static void* pextSetEventWhenCallbackReturns;
static WINAPI void (*pSetFileApisToANSI)(void);
static WINAPI void (*pSetFileApisToOEM)(void);
static WINAPI BOOL (*pSetFileAttributesA)(LPCSTR  name, DWORD  attributes);
static WINAPI BOOL (*pSetFileAttributesW)(LPCWSTR  name, DWORD  attributes);
static WINAPI BOOL (*pSetFileInformationByHandle)(HANDLE  file, FILE_INFO_BY_HANDLE_CLASS  class, void*  info, DWORD  size);
static WINAPI DWORD (*pSetFilePointer)(HANDLE  file, LONG  distance, LONG*  highword, DWORD  method);
static WINAPI BOOL (*pSetFilePointerEx)(HANDLE  file, LARGE_INTEGER  distance, LARGE_INTEGER*  newpos, DWORD  method);
static WINAPI BOOL (*pSetFileSecurityW)(LPCWSTR  name, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr);
static WINAPI BOOL (*pSetFileTime)(HANDLE  file, FILETIME*  ctime, FILETIME*  atime, FILETIME*  mtime);
static WINAPI BOOL (*pSetFileValidData)(HANDLE  file, LONGLONG  length);
static void* pSetHandleCount;
static void* pextSetHandleCount;
static void* pSetHandleInformation;
static void* pextSetHandleInformation;
static WINAPI BOOL (*pSetKernelObjectSecurity)(HANDLE  handle, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr);
static void* pSetLastError;
static void* pextSetLastError;
static void* pSetLocalTime;
static void* pextSetLocalTime;
static void* pSetLocaleInfoW;
static void* pextSetLocaleInfoW;
static WINAPI BOOL (*pSetNamedPipeHandleState)(HANDLE  pipe, LPDWORD  mode, LPDWORD  count, LPDWORD  timeout);
static WINAPI BOOL (*pSetPriorityClass)(HANDLE  process, DWORD  class);
static WINAPI BOOL (*pSetPrivateObjectSecurity)(SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, PSECURITY_DESCRIPTOR*  obj_descr, PGENERIC_MAPPING  mapping, HANDLE  token);
static WINAPI BOOL (*pSetProcessAffinityUpdateMode)(HANDLE  process, DWORD  flags);
static WINAPI BOOL (*pSetProcessMitigationPolicy)(PROCESS_MITIGATION_POLICY  policy, void*  buffer, SIZE_T  length);
static void* pSetProcessPreferredUILanguages;
static void* pextSetProcessPreferredUILanguages;
static WINAPI BOOL (*pSetProcessPriorityBoost)(HANDLE  process, BOOL  disable);
static WINAPI BOOL (*pSetProcessShutdownParameters)(DWORD  level, DWORD  flags);
static WINAPI BOOL (*pSetProcessWorkingSetSizeEx)(HANDLE  process, SIZE_T  minset, SIZE_T  maxset, DWORD  flags);
static WINAPI BOOL (*pSetSecurityDescriptorControl)(PSECURITY_DESCRIPTOR  descr, SECURITY_DESCRIPTOR_CONTROL  mask, SECURITY_DESCRIPTOR_CONTROL  set);
static WINAPI BOOL (*pSetSecurityDescriptorDacl)(PSECURITY_DESCRIPTOR  descr, BOOL  present, PACL  dacl, BOOL  defaulted);
static WINAPI BOOL (*pSetSecurityDescriptorGroup)(PSECURITY_DESCRIPTOR  descr, PSID  group, BOOL  defaulted);
static WINAPI BOOL (*pSetSecurityDescriptorOwner)(PSECURITY_DESCRIPTOR  descr, PSID  owner, BOOL  defaulted);
static WINAPI BOOL (*pSetSecurityDescriptorSacl)(PSECURITY_DESCRIPTOR  descr, BOOL  present, PACL  sacl, BOOL  defaulted);
static void* pSetStdHandle;
static void* pextSetStdHandle;
static void* pSetSystemFileCacheSize;
static void* pextSetSystemFileCacheSize;
static void* pSetSystemTime;
static void* pextSetSystemTime;
static void* pSetSystemTimeAdjustment;
static void* pextSetSystemTimeAdjustment;
static WINAPI BOOL (*pSetThreadContext)(HANDLE  thread, CONTEXT*  context);
static WINAPI BOOL (*pSetThreadErrorMode)(DWORD  mode, DWORD*  old);
static WINAPI BOOL (*pSetThreadGroupAffinity)(HANDLE  thread, GROUP_AFFINITY*  new, GROUP_AFFINITY*  old);
static WINAPI DWORD (*pSetThreadIdealProcessor)(HANDLE  thread, DWORD  proc);
static WINAPI BOOL (*pSetThreadIdealProcessorEx)(HANDLE  thread, PROCESSOR_NUMBER*  ideal, PROCESSOR_NUMBER*  previous);
static void* pSetThreadLocale;
static void* pextSetThreadLocale;
static void* pSetThreadPreferredUILanguages;
static void* pextSetThreadPreferredUILanguages;
static WINAPI BOOL (*pSetThreadPriority)(HANDLE  thread, INT  priority);
static WINAPI BOOL (*pSetThreadPriorityBoost)(HANDLE  thread, BOOL  disable);
static WINAPI BOOL (*pSetThreadStackGuarantee)(ULONG*  size);
static WINAPI BOOL (*pSetThreadToken)(PHANDLE  thread, HANDLE  token);
static void* pSetThreadUILanguage;
static void* pextSetThreadUILanguage;
static void* pSetThreadpoolThreadMaximum;
static void* pextSetThreadpoolThreadMaximum;
static void* pSetThreadpoolThreadMinimum;
static void* pextSetThreadpoolThreadMinimum;
static void* pSetThreadpoolTimer;
static void* pextSetThreadpoolTimer;
static void* pSetThreadpoolWait;
static void* pextSetThreadpoolWait;
static void* pSetTimeZoneInformation;
static void* pextSetTimeZoneInformation;
static WINAPI BOOL (*pSetTokenInformation)(HANDLE  token, TOKEN_INFORMATION_CLASS  class, LPVOID  info, DWORD  len);
static void* pSetUnhandledExceptionFilter;
static void* pextSetUnhandledExceptionFilter;
static void* pSetUserGeoID;
static void* pextSetUserGeoID;
static WINAPI BOOL (*pSetWaitableTimer)(HANDLE  handle, LARGE_INTEGER*  when, LONG  period, PTIMERAPCROUTINE  callback, LPVOID  arg, BOOL  resume);
static WINAPI BOOL (*pSetWaitableTimerEx)(HANDLE  handle, LARGE_INTEGER*  when, LONG  period, PTIMERAPCROUTINE  callback, LPVOID  arg, REASON_CONTEXT*  context, ULONG  tolerabledelay);
static void* pSetupComm;
static void* pextSetupComm;
static WINAPI DWORD (*pSignalObjectAndWait)(HANDLE  signal, HANDLE  wait, DWORD  timeout, BOOL  alertable);
static WINAPI DWORD (*pSizeofResource)(HINSTANCE  module, HRSRC  rsrc);
static WINAPI void (*pSleep)(DWORD  timeout);
static WINAPI BOOL (*pSleepConditionVariableCS)(CONDITION_VARIABLE*  variable, CRITICAL_SECTION*  crit, DWORD  timeout);
static WINAPI BOOL (*pSleepConditionVariableSRW)(RTL_CONDITION_VARIABLE*  variable, RTL_SRWLOCK*  lock, DWORD  timeout, ULONG  flags);
static WINAPI DWORD (*pSleepEx)(DWORD  timeout, BOOL  alertable);
static WINAPI INT (*pStrCSpnA)(char*  str, char*  match);
static WINAPI INT (*pStrCSpnIA)(char*  str, char*  match);
static WINAPI INT (*pStrCSpnIW)(WCHAR*  str, WCHAR*  match);
static WINAPI INT (*pStrCSpnW)(WCHAR*  str, WCHAR*  match);
static WINAPI LPSTR (*pStrCatBuffA)(char*  str, char*  cat, INT  max_len);
static WINAPI LPWSTR (*pStrCatBuffW)(WCHAR*  str, WCHAR*  cat, INT  max_len);
static WINAPI DWORD (*pStrCatChainW)(WCHAR*  str, DWORD  max_len, DWORD  at, WCHAR*  cat);
static WINAPI LPSTR (*pStrChrA)(char*  str, WORD  ch);
static WINAPI LPSTR (*pStrChrIA)(char*  str, WORD  ch);
static WINAPI LPWSTR (*pStrChrIW)(WCHAR*  str, WCHAR  ch);
static WINAPI WCHAR* (*pStrChrNW)(WCHAR*  str, WCHAR  ch, UINT  max_len);
static WINAPI LPWSTR (*pStrChrW)(WCHAR*  str, WCHAR  ch);
static WINAPI DWORD (*pStrCmpCA)(char*  str, char*  cmp);
static WINAPI DWORD (*pStrCmpCW)(WCHAR*  str, WCHAR*  cmp);
static WINAPI DWORD (*pStrCmpICA)(char*  str, char*  cmp);
static WINAPI DWORD (*pStrCmpICW)(WCHAR*  str, WCHAR*  cmp);
static WINAPI int (*pStrCmpIW)(WCHAR*  str, WCHAR*  comp);
static WINAPI INT (*pStrCmpLogicalW)(WCHAR*  str, WCHAR*  comp);
static WINAPI INT (*pStrCmpNA)(char*  str, char*  comp, int  len);
static WINAPI DWORD (*pStrCmpNCA)(char*  str, char*  comp, int  len);
static WINAPI DWORD (*pStrCmpNCW)(WCHAR*  str, WCHAR*  comp, int  len);
static WINAPI INT (*pStrCmpNIA)(char*  str, char*  cmp, int  len);
static WINAPI DWORD (*pStrCmpNICA)(char*  str, char*  cmp, DWORD  len);
static WINAPI DWORD (*pStrCmpNICW)(WCHAR*  str, WCHAR*  cmp, DWORD  len);
static WINAPI INT (*pStrCmpNIW)(WCHAR*  str, WCHAR*  comp, int  len);
static WINAPI INT (*pStrCmpNW)(WCHAR*  str, WCHAR*  comp, int  len);
static WINAPI int (*pStrCmpW)(WCHAR*  str, WCHAR*  comp);
static WINAPI LPWSTR (*pStrCpyNW)(WCHAR*  dst, WCHAR*  src, int  count);
static WINAPI char* (*pStrCpyNXA)(char*  dst, char*  src, int  len);
static WINAPI WCHAR* (*pStrCpyNXW)(WCHAR*  dst, WCHAR*  src, int  len);
static WINAPI LPSTR (*pStrDupA)(char*  str);
static WINAPI LPWSTR (*pStrDupW)(WCHAR*  str);
static WINAPI BOOL (*pStrIsIntlEqualA)(BOOL  case_sensitive, char*  str, char*  cmp, int  len);
static WINAPI BOOL (*pStrIsIntlEqualW)(BOOL  case_sensitive, WCHAR*  str, WCHAR*  cmp, int  len);
static WINAPI LPSTR (*pStrPBrkA)(char*  str, char*  match);
static WINAPI LPWSTR (*pStrPBrkW)(WCHAR*  str, WCHAR*  match);
static WINAPI LPSTR (*pStrRChrA)(char*  str, char*  end, WORD  ch);
static WINAPI LPSTR (*pStrRChrIA)(char*  str, char*  end, WORD  ch);
static WINAPI LPWSTR (*pStrRChrIW)(WCHAR*  str, WCHAR*  end, WORD  ch);
static WINAPI LPWSTR (*pStrRChrW)(WCHAR*  str, WCHAR*  end, WORD  ch);
static WINAPI LPSTR (*pStrRStrIA)(char*  str, char*  end, char*  search);
static WINAPI LPWSTR (*pStrRStrIW)(WCHAR*  str, WCHAR*  end, WCHAR*  search);
static WINAPI int (*pStrSpnA)(char*  str, char*  match);
static WINAPI int (*pStrSpnW)(WCHAR*  str, WCHAR*  match);
static WINAPI LPSTR (*pStrStrA)(char*  str, char*  search);
static WINAPI LPSTR (*pStrStrIA)(char*  str, char*  search);
static WINAPI LPWSTR (*pStrStrIW)(WCHAR*  str, WCHAR*  search);
static WINAPI LPWSTR (*pStrStrNIW)(WCHAR*  str, WCHAR*  search, UINT  max_len);
static WINAPI LPWSTR (*pStrStrNW)(WCHAR*  str, WCHAR*  search, UINT  max_len);
static WINAPI LPWSTR (*pStrStrW)(WCHAR*  str, WCHAR*  search);
static WINAPI BOOL (*pStrToInt64ExA)(char*  str, DWORD  flags, LONGLONG*  ret);
static WINAPI BOOL (*pStrToInt64ExW)(WCHAR*  str, DWORD  flags, LONGLONG*  ret);
static WINAPI int (*pStrToIntA)(char*  str);
static WINAPI BOOL (*pStrToIntExA)(char*  str, DWORD  flags, INT*  ret);
static WINAPI BOOL (*pStrToIntExW)(WCHAR*  str, DWORD  flags, INT*  ret);
static WINAPI int (*pStrToIntW)(WCHAR*  str);
static WINAPI BOOL (*pStrTrimA)(char*  str, char*  trim);
static WINAPI BOOL (*pStrTrimW)(WCHAR*  str, WCHAR*  trim);
static void* pSubmitThreadpoolWork;
static void* pextSubmitThreadpoolWork;
static WINAPI DWORD (*pSuspendThread)(HANDLE  thread);
static WINAPI void (*pSwitchToFiber)(LPVOID  fiber);
static WINAPI BOOL (*pSwitchToThread)(void);
static void* pSystemTimeToFileTime;
static void* pextSystemTimeToFileTime;
static void* pSystemTimeToTzSpecificLocalTime;
static void* pextSystemTimeToTzSpecificLocalTime;
static WINAPI BOOL (*pTerminateProcess)(HANDLE  handle, DWORD  exit_code);
static WINAPI BOOL (*pTerminateThread)(HANDLE  handle, DWORD  exit_code);
static WINAPI DWORD (*pTlsAlloc)(void);
static WINAPI BOOL (*pTlsFree)(DWORD  index);
static WINAPI LPVOID (*pTlsGetValue)(DWORD  index);
static WINAPI BOOL (*pTlsSetValue)(DWORD  index, LPVOID  value);
static void* pTraceEvent;
static void* pextTraceEvent;
static void* pTraceMessage;
static void* pextTraceMessage;
static void* pTraceMessageVa;
static void* pextTraceMessageVa;
static WINAPI BOOL (*pTransactNamedPipe)(HANDLE  handle, LPVOID  write_buf, DWORD  write_size, LPVOID  read_buf, DWORD  read_size, LPDWORD  bytes_read, LPOVERLAPPED  overlapped);
static void* pTransmitCommChar;
static void* pextTransmitCommChar;
static void* pTryAcquireSRWLockExclusive;
static void* pextTryAcquireSRWLockExclusive;
static void* pTryAcquireSRWLockShared;
static void* pextTryAcquireSRWLockShared;
static void* pTryEnterCriticalSection;
static void* pextTryEnterCriticalSection;
static WINAPI BOOL (*pTrySubmitThreadpoolCallback)(PTP_SIMPLE_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static void* pTzSpecificLocalTimeToSystemTime;
static void* pextTzSpecificLocalTimeToSystemTime;
static void* pUnhandledExceptionFilter;
static void* pextUnhandledExceptionFilter;
static WINAPI BOOL (*pUnlockFile)(HANDLE  file, DWORD  offset_low, DWORD  offset_high, DWORD  count_low, DWORD  count_high);
static WINAPI BOOL (*pUnlockFileEx)(HANDLE  file, DWORD  reserved, DWORD  count_low, DWORD  count_high, LPOVERLAPPED  overlapped);
static void* pUnmapViewOfFile;
static void* pextUnmapViewOfFile;
static void* pUnregisterTraceGuids;
static void* pextUnregisterTraceGuids;
static WINAPI BOOL (*pUnregisterWaitEx)(HANDLE  handle, HANDLE  event);
static WINAPI BOOL (*pUpdateProcThreadAttribute)(struct _PROC_THREAD_ATTRIBUTE_LIST*  list, DWORD  flags, DWORD_PTR  attr, void*  value, SIZE_T  size, void*  prev_ret, SIZE_T*  size_ret);
static WINAPI HRESULT (*pUrlApplySchemeA)(char*  url, char*  out, DWORD*  out_len, DWORD  flags);
static WINAPI HRESULT (*pUrlApplySchemeW)(WCHAR*  url, WCHAR*  out, DWORD*  length, DWORD  flags);
static WINAPI HRESULT (*pUrlCanonicalizeA)(char*  src_url, char*  canonicalized, DWORD*  canonicalized_len, DWORD  flags);
static WINAPI HRESULT (*pUrlCanonicalizeW)(WCHAR*  src_url, WCHAR*  canonicalized, DWORD*  canonicalized_len, DWORD  flags);
static WINAPI HRESULT (*pUrlCombineA)(char*  base, char*  relative, char*  combined, DWORD*  combined_len, DWORD  flags);
static WINAPI HRESULT (*pUrlCombineW)(WCHAR*  baseW, WCHAR*  relativeW, WCHAR*  combined, DWORD*  combined_len, DWORD  flags);
static WINAPI INT (*pUrlCompareA)(char*  url1, char*  url2, BOOL  ignore_slash);
static WINAPI INT (*pUrlCompareW)(WCHAR*  url1, WCHAR*  url2, BOOL  ignore_slash);
static WINAPI HRESULT (*pUrlCreateFromPathA)(char*  path, char*  url, DWORD*  url_len, DWORD  reserved);
static WINAPI HRESULT (*pUrlCreateFromPathW)(WCHAR*  path, WCHAR*  url, DWORD*  url_len, DWORD  reserved);
static WINAPI HRESULT (*pUrlEscapeA)(char*  url, char*  escaped, DWORD*  escaped_len, DWORD  flags);
static WINAPI HRESULT (*pUrlEscapeW)(WCHAR*  url, WCHAR*  escaped, DWORD*  escaped_len, DWORD  flags);
static WINAPI HRESULT (*pUrlFixupW)(WCHAR*  url, WCHAR*  translatedUrl, DWORD  maxChars);
static WINAPI LPCSTR (*pUrlGetLocationA)(char*  url);
static WINAPI LPCWSTR (*pUrlGetLocationW)(WCHAR*  url);
static WINAPI HRESULT (*pUrlGetPartA)(char*  url, char*  out, DWORD*  out_len, DWORD  part, DWORD  flags);
static WINAPI HRESULT (*pUrlGetPartW)(WCHAR*  url, WCHAR*  out, DWORD*  out_len, DWORD  part, DWORD  flags);
static WINAPI HRESULT (*pUrlHashA)(char*  url, unsigned char*  dest, DWORD  dest_len);
static WINAPI HRESULT (*pUrlHashW)(WCHAR*  url, unsigned char*  dest, DWORD  dest_len);
static WINAPI BOOL (*pUrlIsA)(char*  url, URLIS  Urlis);
static WINAPI BOOL (*pUrlIsNoHistoryA)(char*  url);
static WINAPI BOOL (*pUrlIsNoHistoryW)(WCHAR*  url);
static WINAPI BOOL (*pUrlIsOpaqueA)(char*  url);
static WINAPI BOOL (*pUrlIsOpaqueW)(WCHAR*  url);
static WINAPI BOOL (*pUrlIsW)(WCHAR*  url, URLIS  Urlis);
static WINAPI HRESULT (*pUrlUnescapeA)(char*  url, char*  unescaped, DWORD*  unescaped_len, DWORD  flags);
static WINAPI HRESULT (*pUrlUnescapeW)(WCHAR*  url, WCHAR*  unescaped, DWORD*  unescaped_len, DWORD  flags);
static WINAPI DWORD (*pVerFindFileA)(DWORD  flags, LPCSTR  filename, LPCSTR  win_dir, LPCSTR  app_dir, LPSTR  cur_dir, PUINT  curdir_len, LPSTR  dest, PUINT  dest_len);
static WINAPI DWORD (*pVerFindFileW)(DWORD  flags, LPCWSTR  filename, LPCWSTR  win_dir, LPCWSTR  app_dir, LPWSTR  cur_dir, PUINT  curdir_len, LPWSTR  dest, PUINT  dest_len);
static void* pVerLanguageNameA;
static void* pextVerLanguageNameA;
static void* pVerLanguageNameW;
static void* pextVerLanguageNameW;
static WINAPI BOOL (*pVerQueryValueA)(LPCVOID  pBlock, LPCSTR  lpSubBlock, LPVOID*  lplpBuffer, PUINT  puLen);
static WINAPI BOOL (*pVerQueryValueW)(LPCVOID  pBlock, LPCWSTR  lpSubBlock, LPVOID*  lplpBuffer, PUINT  puLen);
static void* pVerSetConditionMask;
static void* pextVerSetConditionMask;
static void* pVirtualAlloc;
static void* pextVirtualAlloc;
static void* pVirtualAllocEx;
static void* pextVirtualAllocEx;
static void* pVirtualAllocExNuma;
static void* pextVirtualAllocExNuma;
static void* pVirtualFree;
static void* pextVirtualFree;
static void* pVirtualFreeEx;
static void* pextVirtualFreeEx;
static void* pVirtualLock;
static void* pextVirtualLock;
static void* pVirtualProtect;
static void* pextVirtualProtect;
static void* pVirtualProtectEx;
static void* pextVirtualProtectEx;
static void* pVirtualQuery;
static void* pextVirtualQuery;
static void* pVirtualQueryEx;
static void* pextVirtualQueryEx;
static void* pVirtualUnlock;
static void* pextVirtualUnlock;
static void* pWaitCommEvent;
static void* pextWaitCommEvent;
static void* pWaitForDebugEvent;
static void* pextWaitForDebugEvent;
static WINAPI DWORD (*pWaitForMultipleObjects)(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout);
static WINAPI DWORD (*pWaitForMultipleObjectsEx)(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout, BOOL  alertable);
static WINAPI DWORD (*pWaitForSingleObject)(HANDLE  handle, DWORD  timeout);
static WINAPI DWORD (*pWaitForSingleObjectEx)(HANDLE  handle, DWORD  timeout, BOOL  alertable);
static void* pWaitForThreadpoolTimerCallbacks;
static void* pextWaitForThreadpoolTimerCallbacks;
static void* pWaitForThreadpoolWaitCallbacks;
static void* pextWaitForThreadpoolWaitCallbacks;
static void* pWaitForThreadpoolWorkCallbacks;
static void* pextWaitForThreadpoolWorkCallbacks;
static WINAPI BOOL (*pWaitNamedPipeW)(LPCWSTR  name, DWORD  timeout);
static WINAPI BOOL (*pWaitOnAddress)(volatile void*  addr, void*  cmp, SIZE_T  size, DWORD  timeout);
static void* pWakeAllConditionVariable;
static void* pextWakeAllConditionVariable;
static void* pWakeByAddressAll;
static void* pextWakeByAddressAll;
static void* pWakeByAddressSingle;
static void* pextWakeByAddressSingle;
static void* pWakeConditionVariable;
static void* pextWakeConditionVariable;
static void* pWerRegisterFile;
static void* pextWerRegisterFile;
static void* pWerRegisterMemoryBlock;
static void* pextWerRegisterMemoryBlock;
static void* pWerRegisterRuntimeExceptionModule;
static void* pextWerRegisterRuntimeExceptionModule;
static void* pWerSetFlags;
static void* pextWerSetFlags;
static void* pWerUnregisterMemoryBlock;
static void* pextWerUnregisterMemoryBlock;
static void* pWerUnregisterRuntimeExceptionModule;
static void* pextWerUnregisterRuntimeExceptionModule;
static void* pWideCharToMultiByte;
static void* pextWideCharToMultiByte;
static WINAPI BOOL (*pWow64DisableWow64FsRedirection)(PVOID*  old_value);
static WINAPI BOOL (*pWow64RevertWow64FsRedirection)(PVOID  old_value);
static void* pWriteConsoleA;
static void* pextWriteConsoleA;
static void* pWriteConsoleInputA;
static void* pextWriteConsoleInputA;
static void* pWriteConsoleInputW;
static void* pextWriteConsoleInputW;
static void* pWriteConsoleOutputA;
static void* pextWriteConsoleOutputA;
static void* pWriteConsoleOutputAttribute;
static void* pextWriteConsoleOutputAttribute;
static void* pWriteConsoleOutputCharacterA;
static void* pextWriteConsoleOutputCharacterA;
static void* pWriteConsoleOutputCharacterW;
static void* pextWriteConsoleOutputCharacterW;
static void* pWriteConsoleOutputW;
static void* pextWriteConsoleOutputW;
static void* pWriteConsoleW;
static void* pextWriteConsoleW;
static WINAPI BOOL (*pWriteFile)(HANDLE  file, LPCVOID  buffer, DWORD  count, LPDWORD  result, LPOVERLAPPED  overlapped);
static WINAPI BOOL (*pWriteFileEx)(HANDLE  file, LPCVOID  buffer, DWORD  count, LPOVERLAPPED  overlapped, LPOVERLAPPED_COMPLETION_ROUTINE  completion);
static WINAPI BOOL (*pWriteFileGather)(HANDLE  file, FILE_SEGMENT_ELEMENT*  segments, DWORD  count, LPDWORD  reserved, LPOVERLAPPED  overlapped);
static void* pWriteProcessMemory;
static void* pextWriteProcessMemory;
static WINAPI BOOL (*pZombifyActCtx)(HANDLE  context);
static void* p__C_specific_handler;
static void* pext__C_specific_handler;
static void* p__chkstk;
static void* pext__chkstk;
static void* p_local_unwind;
static void* pext_local_unwind;
static WINAPI INT (*plstrcmpA)(LPCSTR  str1, LPCSTR  str2);
static WINAPI INT (*plstrcmpW)(LPCWSTR  str1, LPCWSTR  str2);
static WINAPI INT (*plstrcmpiA)(LPCSTR  str1, LPCSTR  str2);
static WINAPI INT (*plstrcmpiW)(LPCWSTR  str1, LPCWSTR  str2);
static WINAPI LPSTR (*plstrcpynA)(LPSTR  dst, LPCSTR  src, INT  n);
static WINAPI LPWSTR (*plstrcpynW)(LPWSTR  dst, LPCWSTR  src, INT  n);
static WINAPI INT (*plstrlenA)(LPCSTR  str);
static WINAPI INT (*plstrlenW)(LPCWSTR  str);

extern WINAPI BOOL wine32b_kernelbase_AccessCheck(PSECURITY_DESCRIPTOR  descr, HANDLE  token, DWORD  access, PGENERIC_MAPPING  mapping, PPRIVILEGE_SET  priv, LPDWORD  priv_len, LPDWORD  granted, LPBOOL  status) /* ../dlls/kernelbase/security.c:1204 */
{
	TRACE("Enter AccessCheck\n");
	return pAccessCheck(descr, token, access, mapping, priv, priv_len, granted, status);
}

extern WINAPI void wine32a_kernelbase_AccessCheck(void);  /* ../dlls/kernelbase/security.c:1204 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AccessCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AccessCheck") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AccessCheckAndAuditAlarmW(LPCWSTR  subsystem, LPVOID  id, LPWSTR  type_name, LPWSTR  name, PSECURITY_DESCRIPTOR  descr, DWORD  access, PGENERIC_MAPPING  mapping, BOOL  creation, LPDWORD  granted, LPBOOL  status, LPBOOL  on_close) /* ../dlls/kernelbase/security.c:1217 */
{
	TRACE("Enter AccessCheckAndAuditAlarmW\n");
	return pAccessCheckAndAuditAlarmW(subsystem, id, type_name, name, descr, access, mapping, creation, granted, status, on_close);
}

extern WINAPI void wine32a_kernelbase_AccessCheckAndAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1217 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AccessCheckAndAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AccessCheckAndAuditAlarmW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AccessCheckByType(PSECURITY_DESCRIPTOR  descr, PSID  sid, HANDLE  token, DWORD  access, POBJECT_TYPE_LIST  types, DWORD  types_len, PGENERIC_MAPPING  mapping, PPRIVILEGE_SET  priv, LPDWORD  priv_len, LPDWORD  granted, LPBOOL  status) /* ../dlls/kernelbase/security.c:1231 */
{
	TRACE("Enter AccessCheckByType\n");
	return pAccessCheckByType(descr, sid, token, access, types, types_len, mapping, priv, priv_len, granted, status);
}

extern WINAPI void wine32a_kernelbase_AccessCheckByType(void);  /* ../dlls/kernelbase/security.c:1231 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AccessCheckByType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AccessCheckByType") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_ActivateActCtx(HANDLE  context, ULONG_PTR*  cookie) /* ../dlls/kernelbase/loader.c:760 */
{
	TRACE("Enter ActivateActCtx\n");
	return pActivateActCtx(context, cookie);
}

extern WINAPI void wine32a_kernelbase_ActivateActCtx(void);  /* ../dlls/kernelbase/loader.c:760 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ActivateActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ActivateActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AddAccessAllowedAce(PACL  acl, DWORD  rev, DWORD  access, PSID  sid) /* ../dlls/kernelbase/security.c:1243 */
{
	TRACE("Enter AddAccessAllowedAce\n");
	return pAddAccessAllowedAce(acl, rev, access, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessAllowedAce(void);  /* ../dlls/kernelbase/security.c:1243 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessAllowedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessAllowedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AddAccessAllowedAceEx(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid) /* ../dlls/kernelbase/security.c:1251 */
{
	TRACE("Enter AddAccessAllowedAceEx\n");
	return pAddAccessAllowedAceEx(acl, rev, flags, access, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessAllowedAceEx(void);  /* ../dlls/kernelbase/security.c:1251 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessAllowedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessAllowedAceEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAccessAllowedObjectAce(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid) /* ../dlls/kernelbase/security.c:1259 */
{
	TRACE("Enter AddAccessAllowedObjectAce\n");
	return pAddAccessAllowedObjectAce(acl, rev, flags, access, type, inherit, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessAllowedObjectAce(void);  /* ../dlls/kernelbase/security.c:1259 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessAllowedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessAllowedObjectAce") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAccessDeniedAce(PACL  acl, DWORD  rev, DWORD  access, PSID  sid) /* ../dlls/kernelbase/security.c:1268 */
{
	TRACE("Enter AddAccessDeniedAce\n");
	return pAddAccessDeniedAce(acl, rev, access, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessDeniedAce(void);  /* ../dlls/kernelbase/security.c:1268 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessDeniedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessDeniedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AddAccessDeniedAceEx(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid) /* ../dlls/kernelbase/security.c:1276 */
{
	TRACE("Enter AddAccessDeniedAceEx\n");
	return pAddAccessDeniedAceEx(acl, rev, flags, access, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessDeniedAceEx(void);  /* ../dlls/kernelbase/security.c:1276 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessDeniedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessDeniedAceEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAccessDeniedObjectAce(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid) /* ../dlls/kernelbase/security.c:1284 */
{
	TRACE("Enter AddAccessDeniedObjectAce\n");
	return pAddAccessDeniedObjectAce(acl, rev, flags, access, type, inherit, sid);
}

extern WINAPI void wine32a_kernelbase_AddAccessDeniedObjectAce(void);  /* ../dlls/kernelbase/security.c:1284 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAccessDeniedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAccessDeniedObjectAce") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAce(PACL  acl, DWORD  rev, DWORD  index, LPVOID  list, DWORD  len) /* ../dlls/kernelbase/security.c:1293 */
{
	TRACE("Enter AddAce\n");
	return pAddAce(acl, rev, index, list, len);
}

extern WINAPI void wine32a_kernelbase_AddAce(void);  /* ../dlls/kernelbase/security.c:1293 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAce") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAuditAccessAce(PACL  acl, DWORD  rev, DWORD  access, PSID  sid, BOOL  success, BOOL  failure) /* ../dlls/kernelbase/security.c:1301 */
{
	TRACE("Enter AddAuditAccessAce\n");
	return pAddAuditAccessAce(acl, rev, access, sid, success, failure);
}

extern WINAPI void wine32a_kernelbase_AddAuditAccessAce(void);  /* ../dlls/kernelbase/security.c:1301 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAuditAccessAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAuditAccessAce") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAuditAccessAceEx(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, PSID  sid, BOOL  success, BOOL  failure) /* ../dlls/kernelbase/security.c:1309 */
{
	TRACE("Enter AddAuditAccessAceEx\n");
	return pAddAuditAccessAceEx(acl, rev, flags, access, sid, success, failure);
}

extern WINAPI void wine32a_kernelbase_AddAuditAccessAceEx(void);  /* ../dlls/kernelbase/security.c:1309 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAuditAccessAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAuditAccessAceEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddAuditAccessObjectAce(PACL  acl, DWORD  rev, DWORD  flags, DWORD  access, GUID*  type, GUID*  inherit, PSID  sid, BOOL  success, BOOL  failure) /* ../dlls/kernelbase/security.c:1318 */
{
	TRACE("Enter AddAuditAccessObjectAce\n");
	return pAddAuditAccessObjectAce(acl, rev, flags, access, type, inherit, sid, success, failure);
}

extern WINAPI void wine32a_kernelbase_AddAuditAccessObjectAce(void);  /* ../dlls/kernelbase/security.c:1318 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddAuditAccessObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddAuditAccessObjectAce") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AddMandatoryAce(PACL  acl, DWORD  rev, DWORD  flags, DWORD  policy, PSID  sid) /* ../dlls/kernelbase/security.c:1328 */
{
	TRACE("Enter AddMandatoryAce\n");
	return pAddMandatoryAce(acl, rev, flags, policy, sid);
}

extern WINAPI void wine32a_kernelbase_AddMandatoryAce(void);  /* ../dlls/kernelbase/security.c:1328 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddMandatoryAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddMandatoryAce") "\n"
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

extern WINAPI void wine32b_kernelbase_AddRefActCtx(HANDLE  context) /* ../dlls/kernelbase/loader.c:769 */
{
	TRACE("Enter AddRefActCtx\n");
	return pAddRefActCtx(context);
}

extern WINAPI void wine32a_kernelbase_AddRefActCtx(void);  /* ../dlls/kernelbase/loader.c:769 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AddRefActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AddRefActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AdjustTokenGroups(HANDLE  token, BOOL  reset, PTOKEN_GROUPS  new, DWORD  len, PTOKEN_GROUPS  prev, PDWORD  ret_len) /* ../dlls/kernelbase/security.c:490 */
{
	TRACE("Enter AdjustTokenGroups\n");
	return pAdjustTokenGroups(token, reset, new, len, prev, ret_len);
}

extern WINAPI void wine32a_kernelbase_AdjustTokenGroups(void);  /* ../dlls/kernelbase/security.c:490 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AdjustTokenGroups,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AdjustTokenGroups") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AdjustTokenPrivileges(HANDLE  token, BOOL  disable, PTOKEN_PRIVILEGES  new, DWORD  len, PTOKEN_PRIVILEGES  prev, PDWORD  ret_len) /* ../dlls/kernelbase/security.c:499 */
{
	TRACE("Enter AdjustTokenPrivileges\n");
	return pAdjustTokenPrivileges(token, disable, new, len, prev, ret_len);
}

extern WINAPI void wine32a_kernelbase_AdjustTokenPrivileges(void);  /* ../dlls/kernelbase/security.c:499 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AdjustTokenPrivileges,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AdjustTokenPrivileges") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY  auth, BYTE  count, DWORD  auth0, DWORD  auth1, DWORD  auth2, DWORD  auth3, DWORD  auth4, DWORD  auth5, DWORD  auth6, DWORD  auth7, PSID*  sid) /* ../dlls/kernelbase/security.c:235 */
{
	TRACE("Enter AllocateAndInitializeSid\n");
	return pAllocateAndInitializeSid(auth, count, auth0, auth1, auth2, auth3, auth4, auth5, auth6, auth7, sid);
}

extern WINAPI void wine32a_kernelbase_AllocateAndInitializeSid(void);  /* ../dlls/kernelbase/security.c:235 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AllocateAndInitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AllocateAndInitializeSid") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_AllocateLocallyUniqueId(PLUID  luid) /* ../dlls/kernelbase/security.c:246 */
{
	TRACE("Enter AllocateLocallyUniqueId\n");
	return pAllocateLocallyUniqueId(luid);
}

extern WINAPI void wine32a_kernelbase_AllocateLocallyUniqueId(void);  /* ../dlls/kernelbase/security.c:246 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AllocateLocallyUniqueId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AllocateLocallyUniqueId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_AppPolicyGetProcessTerminationMethod(HANDLE  token, AppPolicyProcessTerminationMethod*  policy) /* ../dlls/kernelbase/main.c:48 */
{
	TRACE("Enter AppPolicyGetProcessTerminationMethod\n");
	return pAppPolicyGetProcessTerminationMethod(token, policy);
}

extern WINAPI void wine32a_kernelbase_AppPolicyGetProcessTerminationMethod(void);  /* ../dlls/kernelbase/main.c:48 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AppPolicyGetProcessTerminationMethod,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AppPolicyGetProcessTerminationMethod") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_AppPolicyGetShowDeveloperDiagnostic(HANDLE  token, AppPolicyShowDeveloperDiagnostic*  policy) /* ../dlls/kernelbase/main.c:74 */
{
	TRACE("Enter AppPolicyGetShowDeveloperDiagnostic\n");
	return pAppPolicyGetShowDeveloperDiagnostic(token, policy);
}

extern WINAPI void wine32a_kernelbase_AppPolicyGetShowDeveloperDiagnostic(void);  /* ../dlls/kernelbase/main.c:74 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AppPolicyGetShowDeveloperDiagnostic,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AppPolicyGetShowDeveloperDiagnostic") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_AppPolicyGetThreadInitializationType(HANDLE  token, AppPolicyThreadInitializationType*  policy) /* ../dlls/kernelbase/main.c:61 */
{
	TRACE("Enter AppPolicyGetThreadInitializationType\n");
	return pAppPolicyGetThreadInitializationType(token, policy);
}

extern WINAPI void wine32a_kernelbase_AppPolicyGetThreadInitializationType(void);  /* ../dlls/kernelbase/main.c:61 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AppPolicyGetThreadInitializationType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AppPolicyGetThreadInitializationType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_AppPolicyGetWindowingModel(HANDLE  token, AppPolicyWindowingModel*  policy) /* ../dlls/kernelbase/main.c:87 */
{
	TRACE("Enter AppPolicyGetWindowingModel\n");
	return pAppPolicyGetWindowingModel(token, policy);
}

extern WINAPI void wine32a_kernelbase_AppPolicyGetWindowingModel(void);  /* ../dlls/kernelbase/main.c:87 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AppPolicyGetWindowingModel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AppPolicyGetWindowingModel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AreAllAccessesGranted(DWORD  granted, DWORD  desired) /* ../dlls/kernelbase/security.c:1337 */
{
	TRACE("Enter AreAllAccessesGranted\n");
	return pAreAllAccessesGranted(granted, desired);
}

extern WINAPI void wine32a_kernelbase_AreAllAccessesGranted(void);  /* ../dlls/kernelbase/security.c:1337 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AreAllAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AreAllAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AreAnyAccessesGranted(DWORD  granted, DWORD  desired) /* ../dlls/kernelbase/security.c:1345 */
{
	TRACE("Enter AreAnyAccessesGranted\n");
	return pAreAnyAccessesGranted(granted, desired);
}

extern WINAPI void wine32a_kernelbase_AreAnyAccessesGranted(void);  /* ../dlls/kernelbase/security.c:1345 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AreAnyAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AreAnyAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_AreFileApisANSI(void) /* ../dlls/kernelbase/file.c:146 */
{
	TRACE("Enter AreFileApisANSI\n");
	return pAreFileApisANSI();
}

extern WINAPI void wine32a_kernelbase_AreFileApisANSI(void);  /* ../dlls/kernelbase/file.c:146 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_AreFileApisANSI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_AreFileApisANSI") "\n"
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

extern WINAPI NTSTATUS wine32b_kernelbase_BaseGetNamedObjectDirectory(HANDLE*  dir) /* ../dlls/kernelbase/sync.c:61 */
{
	TRACE("Enter BaseGetNamedObjectDirectory\n");
	return pBaseGetNamedObjectDirectory(dir);
}

extern WINAPI void wine32a_kernelbase_BaseGetNamedObjectDirectory(void);  /* ../dlls/kernelbase/sync.c:61 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_BaseGetNamedObjectDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_BaseGetNamedObjectDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CallNamedPipeW(LPCWSTR  name, LPVOID  input, DWORD  in_size, LPVOID  output, DWORD  out_size, LPDWORD  read_size, DWORD  timeout) /* ../dlls/kernelbase/sync.c:1036 */
{
	TRACE("Enter CallNamedPipeW\n");
	return pCallNamedPipeW(name, input, in_size, output, out_size, read_size, timeout);
}

extern WINAPI void wine32a_kernelbase_CallNamedPipeW(void);  /* ../dlls/kernelbase/sync.c:1036 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CallNamedPipeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CallNamedPipeW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CallbackMayRunLong(TP_CALLBACK_INSTANCE*  instance) /* ../dlls/kernelbase/thread.c:1054 */
{
	TRACE("Enter CallbackMayRunLong\n");
	return pCallbackMayRunLong(instance);
}

extern WINAPI void wine32a_kernelbase_CallbackMayRunLong(void);  /* ../dlls/kernelbase/thread.c:1054 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CallbackMayRunLong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CallbackMayRunLong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CancelIo(HANDLE  handle) /* ../dlls/kernelbase/file.c:808 */
{
	TRACE("Enter CancelIo\n");
	return pCancelIo(handle);
}

extern WINAPI void wine32a_kernelbase_CancelIo(void);  /* ../dlls/kernelbase/file.c:808 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CancelIo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CancelIo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CancelIoEx(HANDLE  handle, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:820 */
{
	TRACE("Enter CancelIoEx\n");
	return pCancelIoEx(handle, overlapped);
}

extern WINAPI void wine32a_kernelbase_CancelIoEx(void);  /* ../dlls/kernelbase/file.c:820 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CancelIoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CancelIoEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CancelSynchronousIo(HANDLE  thread) /* ../dlls/kernelbase/file.c:832 */
{
	TRACE("Enter CancelSynchronousIo\n");
	return pCancelSynchronousIo(thread);
}

extern WINAPI void wine32a_kernelbase_CancelSynchronousIo(void);  /* ../dlls/kernelbase/file.c:832 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CancelSynchronousIo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CancelSynchronousIo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CancelWaitableTimer(HANDLE  handle) /* ../dlls/kernelbase/sync.c:695 */
{
	TRACE("Enter CancelWaitableTimer\n");
	return pCancelWaitableTimer(handle);
}

extern WINAPI void wine32a_kernelbase_CancelWaitableTimer(void);  /* ../dlls/kernelbase/sync.c:695 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CancelWaitableTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CancelWaitableTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ChangeTimerQueueTimer(HANDLE  queue, HANDLE  timer, ULONG  when, ULONG  period) /* ../dlls/kernelbase/sync.c:737 */
{
	TRACE("Enter ChangeTimerQueueTimer\n");
	return pChangeTimerQueueTimer(queue, timer, when, period);
}

extern WINAPI void wine32a_kernelbase_ChangeTimerQueueTimer(void);  /* ../dlls/kernelbase/sync.c:737 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ChangeTimerQueueTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ChangeTimerQueueTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharLowerA(char*  str) /* ../dlls/kernelbase/string.c:1137 */
{
	TRACE("Enter CharLowerA\n");
	return pCharLowerA(str);
}

extern WINAPI void wine32a_kernelbase_CharLowerA(void);  /* ../dlls/kernelbase/string.c:1137 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharLowerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_CharLowerBuffA(char*  str, DWORD  len) /* ../dlls/kernelbase/string.c:1159 */
{
	TRACE("Enter CharLowerBuffA\n");
	return pCharLowerBuffA(str, len);
}

extern WINAPI void wine32a_kernelbase_CharLowerBuffA(void);  /* ../dlls/kernelbase/string.c:1159 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharLowerBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharLowerBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_CharLowerBuffW(WCHAR*  str, DWORD  len) /* ../dlls/kernelbase/string.c:1180 */
{
	TRACE("Enter CharLowerBuffW\n");
	return pCharLowerBuffW(str, len);
}

extern WINAPI void wine32a_kernelbase_CharLowerBuffW(void);  /* ../dlls/kernelbase/string.c:1180 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharLowerBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharLowerBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_CharLowerW(WCHAR*  str) /* ../dlls/kernelbase/string.c:1186 */
{
	TRACE("Enter CharLowerW\n");
	return pCharLowerW(str);
}

extern WINAPI void wine32a_kernelbase_CharLowerW(void);  /* ../dlls/kernelbase/string.c:1186 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharLowerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharNextA(char*  ptr) /* ../dlls/kernelbase/string.c:1201 */
{
	TRACE("Enter CharNextA\n");
	return pCharNextA(ptr);
}

extern WINAPI void wine32a_kernelbase_CharNextA(void);  /* ../dlls/kernelbase/string.c:1201 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharNextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharNextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharNextExA(WORD  codepage, char*  ptr, DWORD  flags) /* ../dlls/kernelbase/string.c:1208 */
{
	TRACE("Enter CharNextExA\n");
	return pCharNextExA(codepage, ptr, flags);
}

extern WINAPI void wine32a_kernelbase_CharNextExA(void);  /* ../dlls/kernelbase/string.c:1208 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharNextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharNextExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_CharNextW(WCHAR*  x) /* ../dlls/kernelbase/string.c:1215 */
{
	TRACE("Enter CharNextW\n");
	return pCharNextW(x);
}

extern WINAPI void wine32a_kernelbase_CharNextW(void);  /* ../dlls/kernelbase/string.c:1215 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharNextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharNextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharPrevA(char*  start, char*  ptr) /* ../dlls/kernelbase/string.c:1222 */
{
	TRACE("Enter CharPrevA\n");
	return pCharPrevA(start, ptr);
}

extern WINAPI void wine32a_kernelbase_CharPrevA(void);  /* ../dlls/kernelbase/string.c:1222 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharPrevA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharPrevA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharPrevExA(WORD  codepage, char*  start, char*  ptr, DWORD  flags) /* ../dlls/kernelbase/string.c:1233 */
{
	TRACE("Enter CharPrevExA\n");
	return pCharPrevExA(codepage, start, ptr, flags);
}

extern WINAPI void wine32a_kernelbase_CharPrevExA(void);  /* ../dlls/kernelbase/string.c:1233 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharPrevExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharPrevExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_CharPrevW(WCHAR*  start, WCHAR*  x) /* ../dlls/kernelbase/string.c:1244 */
{
	TRACE("Enter CharPrevW\n");
	return pCharPrevW(start, x);
}

extern WINAPI void wine32a_kernelbase_CharPrevW(void);  /* ../dlls/kernelbase/string.c:1244 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharPrevW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharPrevW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_CharUpperA(LPSTR  str) /* ../dlls/kernelbase/string.c:1250 */
{
	TRACE("Enter CharUpperA\n");
	return pCharUpperA(str);
}

extern WINAPI void wine32a_kernelbase_CharUpperA(void);  /* ../dlls/kernelbase/string.c:1250 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharUpperA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_CharUpperBuffA(LPSTR  str, DWORD  len) /* ../dlls/kernelbase/string.c:1272 */
{
	TRACE("Enter CharUpperBuffA\n");
	return pCharUpperBuffA(str, len);
}

extern WINAPI void wine32a_kernelbase_CharUpperBuffA(void);  /* ../dlls/kernelbase/string.c:1272 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharUpperBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharUpperBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_CharUpperBuffW(WCHAR*  str, DWORD  len) /* ../dlls/kernelbase/string.c:1293 */
{
	TRACE("Enter CharUpperBuffW\n");
	return pCharUpperBuffW(str, len);
}

extern WINAPI void wine32a_kernelbase_CharUpperBuffW(void);  /* ../dlls/kernelbase/string.c:1293 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharUpperBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharUpperBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_CharUpperW(WCHAR*  str) /* ../dlls/kernelbase/string.c:1299 */
{
	TRACE("Enter CharUpperW\n");
	return pCharUpperW(str);
}

extern WINAPI void wine32a_kernelbase_CharUpperW(void);  /* ../dlls/kernelbase/string.c:1299 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CharUpperW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CheckTokenMembership(HANDLE  token, PSID  sid_to_check, PBOOL  is_member) /* ../dlls/kernelbase/security.c:514 */
{
	TRACE("Enter CheckTokenMembership\n");
	return pCheckTokenMembership(token, sid_to_check, is_member);
}

extern WINAPI void wine32a_kernelbase_CheckTokenMembership(void);  /* ../dlls/kernelbase/security.c:514 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CheckTokenMembership,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CheckTokenMembership") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ChrCmpIA(WORD  ch1, WORD  ch2) /* ../dlls/kernelbase/string.c:428 */
{
	TRACE("Enter ChrCmpIA\n");
	return pChrCmpIA(ch1, ch2);
}

extern WINAPI void wine32a_kernelbase_ChrCmpIA(void);  /* ../dlls/kernelbase/string.c:428 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ChrCmpIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ChrCmpIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ChrCmpIW(WCHAR  ch1, WCHAR  ch2) /* ../dlls/kernelbase/string.c:435 */
{
	TRACE("Enter ChrCmpIW\n");
	return pChrCmpIW(ch1, ch2);
}

extern WINAPI void wine32a_kernelbase_ChrCmpIW(void);  /* ../dlls/kernelbase/string.c:435 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ChrCmpIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ChrCmpIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ConnectNamedPipe(HANDLE  pipe, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/sync.c:1066 */
{
	TRACE("Enter ConnectNamedPipe\n");
	return pConnectNamedPipe(pipe, overlapped);
}

extern WINAPI void wine32a_kernelbase_ConnectNamedPipe(void);  /* ../dlls/kernelbase/sync.c:1066 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ConnectNamedPipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ConnectNamedPipe") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ConvertFiberToThread(void) /* ../dlls/kernelbase/thread.c:846 */
{
	TRACE("Enter ConvertFiberToThread\n");
	return pConvertFiberToThread();
}

extern WINAPI void wine32a_kernelbase_ConvertFiberToThread(void);  /* ../dlls/kernelbase/thread.c:846 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ConvertFiberToThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ConvertFiberToThread") "\n"
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

extern WINAPI LPVOID wine32b_kernelbase_ConvertThreadToFiber(LPVOID  param) /* ../dlls/kernelbase/thread.c:862 */
{
	TRACE("Enter ConvertThreadToFiber\n");
	return pConvertThreadToFiber(param);
}

extern WINAPI void wine32a_kernelbase_ConvertThreadToFiber(void);  /* ../dlls/kernelbase/thread.c:862 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ConvertThreadToFiber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ConvertThreadToFiber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernelbase_ConvertThreadToFiberEx(LPVOID  param, DWORD  flags) /* ../dlls/kernelbase/thread.c:871 */
{
	TRACE("Enter ConvertThreadToFiberEx\n");
	return pConvertThreadToFiberEx(param, flags);
}

extern WINAPI void wine32a_kernelbase_ConvertThreadToFiberEx(void);  /* ../dlls/kernelbase/thread.c:871 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ConvertThreadToFiberEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ConvertThreadToFiberEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  current, PSECURITY_DESCRIPTOR*  descr, GUID*  type, BOOL  is_dir, PGENERIC_MAPPING  mapping) /* ../dlls/kernelbase/security.c:842 */
{
	TRACE("Enter ConvertToAutoInheritPrivateObjectSecurity\n");
	return pConvertToAutoInheritPrivateObjectSecurity(parent, current, descr, type, is_dir, mapping);
}

extern WINAPI void wine32a_kernelbase_ConvertToAutoInheritPrivateObjectSecurity(void);  /* ../dlls/kernelbase/security.c:842 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ConvertToAutoInheritPrivateObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ConvertToAutoInheritPrivateObjectSecurity") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CopySid(DWORD  len, PSID  dest, PSID  source) /* ../dlls/kernelbase/security.c:254 */
{
	TRACE("Enter CopySid\n");
	return pCopySid(len, dest, source);
}

extern WINAPI void wine32a_kernelbase_CopySid(void);  /* ../dlls/kernelbase/security.c:254 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CopySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CopySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateActCtxW(PCACTCTXW  ctx) /* ../dlls/kernelbase/loader.c:778 */
{
	TRACE("Enter CreateActCtxW\n");
	return pCreateActCtxW(ctx);
}

extern WINAPI void wine32a_kernelbase_CreateActCtxW(void);  /* ../dlls/kernelbase/loader.c:778 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateActCtxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateActCtxW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CreateDirectoryA(LPCSTR  path, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernelbase/file.c:155 */
{
	TRACE("Enter CreateDirectoryA\n");
	return pCreateDirectoryA(path, sa);
}

extern WINAPI void wine32a_kernelbase_CreateDirectoryA(void);  /* ../dlls/kernelbase/file.c:155 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CreateDirectoryExW(LPCWSTR  template, LPCWSTR  path, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernelbase/file.c:202 */
{
	TRACE("Enter CreateDirectoryExW\n");
	return pCreateDirectoryExW(template, path, sa);
}

extern WINAPI void wine32a_kernelbase_CreateDirectoryExW(void);  /* ../dlls/kernelbase/file.c:202 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateDirectoryExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateDirectoryExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CreateDirectoryW(LPCWSTR  path, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernelbase/file.c:167 */
{
	TRACE("Enter CreateDirectoryW\n");
	return pCreateDirectoryW(path, sa);
}

extern WINAPI void wine32a_kernelbase_CreateDirectoryW(void);  /* ../dlls/kernelbase/file.c:167 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateEventA(SECURITY_ATTRIBUTES*  sa, BOOL  manual_reset, BOOL  initial_state, LPCSTR  name) /* ../dlls/kernelbase/sync.c:287 */
{
	TRACE("Enter CreateEventA\n");
	return pCreateEventA(sa, manual_reset, initial_state, name);
}

extern WINAPI void wine32a_kernelbase_CreateEventA(void);  /* ../dlls/kernelbase/sync.c:287 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateEventA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateEventA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateEventExA(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:315 */
{
	TRACE("Enter CreateEventExA\n");
	return pCreateEventExA(sa, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateEventExA(void);  /* ../dlls/kernelbase/sync.c:315 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateEventExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateEventExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateEventExW(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:334 */
{
	TRACE("Enter CreateEventExW\n");
	return pCreateEventExW(sa, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateEventExW(void);  /* ../dlls/kernelbase/sync.c:334 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateEventExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateEventExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateEventW(SECURITY_ATTRIBUTES*  sa, BOOL  manual_reset, BOOL  initial_state, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:301 */
{
	TRACE("Enter CreateEventW\n");
	return pCreateEventW(sa, manual_reset, initial_state, name);
}

extern WINAPI void wine32a_kernelbase_CreateEventW(void);  /* ../dlls/kernelbase/sync.c:301 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateEventW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateEventW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernelbase_CreateFiber(SIZE_T  stack, LPFIBER_START_ROUTINE  start, LPVOID  param) /* ../dlls/kernelbase/thread.c:803 */
{
	TRACE("Enter CreateFiber\n");
	return pCreateFiber(stack, start, param);
}

extern WINAPI void wine32a_kernelbase_CreateFiber(void);  /* ../dlls/kernelbase/thread.c:803 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFiber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFiber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernelbase_CreateFiberEx(SIZE_T  stack_commit, SIZE_T  stack_reserve, DWORD  flags, LPFIBER_START_ROUTINE  start, LPVOID  param) /* ../dlls/kernelbase/thread.c:812 */
{
	TRACE("Enter CreateFiberEx\n");
	return pCreateFiberEx(stack_commit, stack_reserve, flags, start, param);
}

extern WINAPI void wine32a_kernelbase_CreateFiberEx(void);  /* ../dlls/kernelbase/thread.c:812 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFiberEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFiberEx") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateFile2(LPCWSTR  name, DWORD  access, DWORD  sharing, DWORD  creation, CREATEFILE2_EXTENDED_PARAMETERS*  params) /* ../dlls/kernelbase/file.c:212 */
{
	TRACE("Enter CreateFile2\n");
	return pCreateFile2(name, access, sharing, creation, params);
}

extern WINAPI void wine32a_kernelbase_CreateFile2(void);  /* ../dlls/kernelbase/file.c:212 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFile2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFile2") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateFileA(LPCSTR  name, DWORD  access, DWORD  sharing, LPSECURITY_ATTRIBUTES  sa, DWORD  creation, DWORD  attributes, HANDLE  template) /* ../dlls/kernelbase/file.c:228 */
{
	TRACE("Enter CreateFileA\n");
	return pCreateFileA(name, access, sharing, sa, creation, attributes, template);
}

extern WINAPI void wine32a_kernelbase_CreateFileA(void);  /* ../dlls/kernelbase/file.c:228 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFileA") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateFileMappingW(HANDLE  file, LPSECURITY_ATTRIBUTES  sa, DWORD  protect, DWORD  size_high, DWORD  size_low, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:795 */
{
	TRACE("Enter CreateFileMappingW\n");
	return pCreateFileMappingW(file, sa, protect, size_high, size_low, name);
}

extern WINAPI void wine32a_kernelbase_CreateFileMappingW(void);  /* ../dlls/kernelbase/sync.c:795 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFileMappingW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFileMappingW") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateFileW(LPCWSTR  filename, DWORD  access, DWORD  sharing, LPSECURITY_ATTRIBUTES  sa, DWORD  creation, DWORD  attributes, HANDLE  template) /* ../dlls/kernelbase/file.c:243 */
{
	TRACE("Enter CreateFileW\n");
	return pCreateFileW(filename, access, sharing, sa, creation, attributes, template);
}

extern WINAPI void wine32a_kernelbase_CreateFileW(void);  /* ../dlls/kernelbase/file.c:243 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateFileW") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateIoCompletionPort(HANDLE  handle, HANDLE  port, ULONG_PTR  key, DWORD  threads) /* ../dlls/kernelbase/sync.c:927 */
{
	TRACE("Enter CreateIoCompletionPort\n");
	return pCreateIoCompletionPort(handle, port, key, threads);
}

extern WINAPI void wine32a_kernelbase_CreateIoCompletionPort(void);  /* ../dlls/kernelbase/sync.c:927 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateIoCompletionPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateIoCompletionPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateMutexA(SECURITY_ATTRIBUTES*  sa, BOOL  owner, LPCSTR  name) /* ../dlls/kernelbase/sync.c:441 */
{
	TRACE("Enter CreateMutexA\n");
	return pCreateMutexA(sa, owner, name);
}

extern WINAPI void wine32a_kernelbase_CreateMutexA(void);  /* ../dlls/kernelbase/sync.c:441 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateMutexA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateMutexA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateMutexExA(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:459 */
{
	TRACE("Enter CreateMutexExA\n");
	return pCreateMutexExA(sa, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateMutexExA(void);  /* ../dlls/kernelbase/sync.c:459 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateMutexExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateMutexExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateMutexExW(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:481 */
{
	TRACE("Enter CreateMutexExW\n");
	return pCreateMutexExW(sa, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateMutexExW(void);  /* ../dlls/kernelbase/sync.c:481 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateMutexExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateMutexExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateMutexW(SECURITY_ATTRIBUTES*  sa, BOOL  owner, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:450 */
{
	TRACE("Enter CreateMutexW\n");
	return pCreateMutexW(sa, owner, name);
}

extern WINAPI void wine32a_kernelbase_CreateMutexW(void);  /* ../dlls/kernelbase/sync.c:450 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateMutexW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateMutexW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateNamedPipeW(LPCWSTR  name, DWORD  open_mode, DWORD  pipe_mode, DWORD  instances, DWORD  out_buff, DWORD  in_buff, DWORD  timeout, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernelbase/sync.c:1095 */
{
	TRACE("Enter CreateNamedPipeW\n");
	return pCreateNamedPipeW(name, open_mode, pipe_mode, instances, out_buff, in_buff, timeout, sa);
}

extern WINAPI void wine32a_kernelbase_CreateNamedPipeW(void);  /* ../dlls/kernelbase/sync.c:1095 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateNamedPipeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateNamedPipeW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, BOOL  is_container, HANDLE  token, PGENERIC_MAPPING  mapping) /* ../dlls/kernelbase/security.c:855 */
{
	TRACE("Enter CreatePrivateObjectSecurity\n");
	return pCreatePrivateObjectSecurity(parent, creator, descr, is_container, token, mapping);
}

extern WINAPI void wine32a_kernelbase_CreatePrivateObjectSecurity(void);  /* ../dlls/kernelbase/security.c:855 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreatePrivateObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreatePrivateObjectSecurity") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, GUID*  type, BOOL  is_container, ULONG  flags, HANDLE  token, PGENERIC_MAPPING  mapping) /* ../dlls/kernelbase/security.c:865 */
{
	TRACE("Enter CreatePrivateObjectSecurityEx\n");
	return pCreatePrivateObjectSecurityEx(parent, creator, descr, type, is_container, flags, token, mapping);
}

extern WINAPI void wine32a_kernelbase_CreatePrivateObjectSecurityEx(void);  /* ../dlls/kernelbase/security.c:865 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreatePrivateObjectSecurityEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreatePrivateObjectSecurityEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR  parent, PSECURITY_DESCRIPTOR  creator, PSECURITY_DESCRIPTOR*  descr, GUID**  types, ULONG  count, BOOL  is_container, ULONG  flags, HANDLE  token, PGENERIC_MAPPING  mapping) /* ../dlls/kernelbase/security.c:914 */
{
	TRACE("Enter CreatePrivateObjectSecurityWithMultipleInheritance\n");
	return pCreatePrivateObjectSecurityWithMultipleInheritance(parent, creator, descr, types, count, is_container, flags, token, mapping);
}

extern WINAPI void wine32a_kernelbase_CreatePrivateObjectSecurityWithMultipleInheritance(void);  /* ../dlls/kernelbase/security.c:914 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreatePrivateObjectSecurityWithMultipleInheritance,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreatePrivateObjectSecurityWithMultipleInheritance") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateRemoteThread(HANDLE  process, SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, DWORD*  id) /* ../dlls/kernelbase/thread.c:58 */
{
	TRACE("Enter CreateRemoteThread\n");
	return pCreateRemoteThread(process, sa, stack, start, param, flags, id);
}

extern WINAPI void wine32a_kernelbase_CreateRemoteThread(void);  /* ../dlls/kernelbase/thread.c:58 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateRemoteThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateRemoteThread") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateRemoteThreadEx(HANDLE  process, SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, LPPROC_THREAD_ATTRIBUTE_LIST  attributes, DWORD*  id) /* ../dlls/kernelbase/thread.c:69 */
{
	TRACE("Enter CreateRemoteThreadEx\n");
	return pCreateRemoteThreadEx(process, sa, stack, start, param, flags, attributes, id);
}

extern WINAPI void wine32a_kernelbase_CreateRemoteThreadEx(void);  /* ../dlls/kernelbase/thread.c:69 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateRemoteThreadEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateRemoteThreadEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CreateRestrictedToken(HANDLE  token, DWORD  flags, DWORD  disable_count, PSID_AND_ATTRIBUTES  disable_sids, DWORD  delete_count, PLUID_AND_ATTRIBUTES  delete_privs, DWORD  restrict_count, PSID_AND_ATTRIBUTES  restrict_sids, PHANDLE  ret) /* ../dlls/kernelbase/security.c:593 */
{
	TRACE("Enter CreateRestrictedToken\n");
	return pCreateRestrictedToken(token, flags, disable_count, disable_sids, delete_count, delete_privs, restrict_count, restrict_sids, ret);
}

extern WINAPI void wine32a_kernelbase_CreateRestrictedToken(void);  /* ../dlls/kernelbase/security.c:593 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateRestrictedToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateRestrictedToken") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateSemaphoreExW(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCWSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:551 */
{
	TRACE("Enter CreateSemaphoreExW\n");
	return pCreateSemaphoreExW(sa, initial, max, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateSemaphoreExW(void);  /* ../dlls/kernelbase/sync.c:551 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateSemaphoreExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateSemaphoreExW") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateSemaphoreW(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:541 */
{
	TRACE("Enter CreateSemaphoreW\n");
	return pCreateSemaphoreW(sa, initial, max, name);
}

extern WINAPI void wine32a_kernelbase_CreateSemaphoreW(void);  /* ../dlls/kernelbase/sync.c:541 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateSemaphoreW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateSemaphoreW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateThread(SECURITY_ATTRIBUTES*  sa, SIZE_T  stack, LPTHREAD_START_ROUTINE  start, LPVOID  param, DWORD  flags, LPDWORD  id) /* ../dlls/kernelbase/thread.c:115 */
{
	TRACE("Enter CreateThread\n");
	return pCreateThread(sa, stack, start, param, flags, id);
}

extern WINAPI void wine32a_kernelbase_CreateThread(void);  /* ../dlls/kernelbase/thread.c:115 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThread") "\n"
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

extern WINAPI PTP_POOL wine32b_kernelbase_CreateThreadpool(void*  reserved) /* ../dlls/kernelbase/thread.c:1063 */
{
	TRACE("Enter CreateThreadpool\n");
	return pCreateThreadpool(reserved);
}

extern WINAPI void wine32a_kernelbase_CreateThreadpool(void);  /* ../dlls/kernelbase/thread.c:1063 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpool,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpool") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PTP_CLEANUP_GROUP wine32b_kernelbase_CreateThreadpoolCleanupGroup(void) /* ../dlls/kernelbase/thread.c:1075 */
{
	TRACE("Enter CreateThreadpoolCleanupGroup\n");
	return pCreateThreadpoolCleanupGroup();
}

extern WINAPI void wine32a_kernelbase_CreateThreadpoolCleanupGroup(void);  /* ../dlls/kernelbase/thread.c:1075 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpoolCleanupGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpoolCleanupGroup") "\n"
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

extern WINAPI PTP_IO wine32b_kernelbase_CreateThreadpoolIo(HANDLE  handle, PTP_WIN32_IO_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/kernelbase/thread.c:1087 */
{
	TRACE("Enter CreateThreadpoolIo\n");
	return pCreateThreadpoolIo(handle, callback, userdata, environment);
}

extern WINAPI void wine32a_kernelbase_CreateThreadpoolIo(void);  /* ../dlls/kernelbase/thread.c:1087 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpoolIo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpoolIo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PTP_TIMER wine32b_kernelbase_CreateThreadpoolTimer(PTP_TIMER_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/kernelbase/thread.c:1098 */
{
	TRACE("Enter CreateThreadpoolTimer\n");
	return pCreateThreadpoolTimer(callback, userdata, environment);
}

extern WINAPI void wine32a_kernelbase_CreateThreadpoolTimer(void);  /* ../dlls/kernelbase/thread.c:1098 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpoolTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpoolTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PTP_WAIT wine32b_kernelbase_CreateThreadpoolWait(PTP_WAIT_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/kernelbase/thread.c:1111 */
{
	TRACE("Enter CreateThreadpoolWait\n");
	return pCreateThreadpoolWait(callback, userdata, environment);
}

extern WINAPI void wine32a_kernelbase_CreateThreadpoolWait(void);  /* ../dlls/kernelbase/thread.c:1111 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpoolWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpoolWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PTP_WORK wine32b_kernelbase_CreateThreadpoolWork(PTP_WORK_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/kernelbase/thread.c:1124 */
{
	TRACE("Enter CreateThreadpoolWork\n");
	return pCreateThreadpoolWork(callback, userdata, environment);
}

extern WINAPI void wine32a_kernelbase_CreateThreadpoolWork(void);  /* ../dlls/kernelbase/thread.c:1124 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateThreadpoolWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateThreadpoolWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateTimerQueue(void) /* ../dlls/kernelbase/sync.c:709 */
{
	TRACE("Enter CreateTimerQueue\n");
	return pCreateTimerQueue();
}

extern WINAPI void wine32a_kernelbase_CreateTimerQueue(void);  /* ../dlls/kernelbase/sync.c:709 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateTimerQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateTimerQueue") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_CreateTimerQueueTimer(PHANDLE  timer, HANDLE  queue, WAITORTIMERCALLBACK  callback, PVOID  arg, DWORD  when, DWORD  period, ULONG  flags) /* ../dlls/kernelbase/sync.c:726 */
{
	TRACE("Enter CreateTimerQueueTimer\n");
	return pCreateTimerQueueTimer(timer, queue, callback, arg, when, period, flags);
}

extern WINAPI void wine32a_kernelbase_CreateTimerQueueTimer(void);  /* ../dlls/kernelbase/sync.c:726 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateTimerQueueTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateTimerQueueTimer") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_CreateWaitableTimerExW(SECURITY_ATTRIBUTES*  sa, LPCWSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernelbase/sync.c:621 */
{
	TRACE("Enter CreateWaitableTimerExW\n");
	return pCreateWaitableTimerExW(sa, name, flags, access);
}

extern WINAPI void wine32a_kernelbase_CreateWaitableTimerExW(void);  /* ../dlls/kernelbase/sync.c:621 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateWaitableTimerExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateWaitableTimerExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_CreateWaitableTimerW(SECURITY_ATTRIBUTES*  sa, BOOL  manual, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:611 */
{
	TRACE("Enter CreateWaitableTimerW\n");
	return pCreateWaitableTimerW(sa, manual, name);
}

extern WINAPI void wine32a_kernelbase_CreateWaitableTimerW(void);  /* ../dlls/kernelbase/sync.c:611 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateWaitableTimerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateWaitableTimerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_CreateWellKnownSid(WELL_KNOWN_SID_TYPE  type, PSID  domain, PSID  sid, DWORD*  size) /* ../dlls/kernelbase/security.c:393 */
{
	TRACE("Enter CreateWellKnownSid\n");
	return pCreateWellKnownSid(type, domain, sid, size);
}

extern WINAPI void wine32a_kernelbase_CreateWellKnownSid(void);  /* ../dlls/kernelbase/security.c:393 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_CreateWellKnownSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_CreateWellKnownSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeactivateActCtx(DWORD  flags, ULONG_PTR  cookie) /* ../dlls/kernelbase/loader.c:797 */
{
	TRACE("Enter DeactivateActCtx\n");
	return pDeactivateActCtx(flags, cookie);
}

extern WINAPI void wine32a_kernelbase_DeactivateActCtx(void);  /* ../dlls/kernelbase/loader.c:797 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeactivateActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeactivateActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeleteAce(PACL  acl, DWORD  index) /* ../dlls/kernelbase/security.c:1353 */
{
	TRACE("Enter DeleteAce\n");
	return pDeleteAce(acl, index);
}

extern WINAPI void wine32a_kernelbase_DeleteAce(void);  /* ../dlls/kernelbase/security.c:1353 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_DeleteFiber(LPVOID  fiber_ptr) /* ../dlls/kernelbase/thread.c:896 */
{
	TRACE("Enter DeleteFiber\n");
	return pDeleteFiber(fiber_ptr);
}

extern WINAPI void wine32a_kernelbase_DeleteFiber(void);  /* ../dlls/kernelbase/thread.c:896 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteFiber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteFiber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeleteFileA(LPCSTR  path) /* ../dlls/kernelbase/file.c:438 */
{
	TRACE("Enter DeleteFileA\n");
	return pDeleteFileA(path);
}

extern WINAPI void wine32a_kernelbase_DeleteFileA(void);  /* ../dlls/kernelbase/file.c:438 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeleteFileW(LPCWSTR  path) /* ../dlls/kernelbase/file.c:450 */
{
	TRACE("Enter DeleteFileW\n");
	return pDeleteFileW(path);
}

extern WINAPI void wine32a_kernelbase_DeleteFileW(void);  /* ../dlls/kernelbase/file.c:450 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_DeleteProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST*  list) /* ../dlls/kernelbase/process.c:483 */
{
	TRACE("Enter DeleteProcThreadAttributeList\n");
	return pDeleteProcThreadAttributeList(list);
}

extern WINAPI void wine32a_kernelbase_DeleteProcThreadAttributeList(void);  /* ../dlls/kernelbase/process.c:483 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteProcThreadAttributeList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteProcThreadAttributeList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeleteTimerQueueEx(HANDLE  queue, HANDLE  event) /* ../dlls/kernelbase/sync.c:747 */
{
	TRACE("Enter DeleteTimerQueueEx\n");
	return pDeleteTimerQueueEx(queue, event);
}

extern WINAPI void wine32a_kernelbase_DeleteTimerQueueEx(void);  /* ../dlls/kernelbase/sync.c:747 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteTimerQueueEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteTimerQueueEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DeleteTimerQueueTimer(HANDLE  queue, HANDLE  timer, HANDLE  event) /* ../dlls/kernelbase/sync.c:756 */
{
	TRACE("Enter DeleteTimerQueueTimer\n");
	return pDeleteTimerQueueTimer(queue, timer, event);
}

extern WINAPI void wine32a_kernelbase_DeleteTimerQueueTimer(void);  /* ../dlls/kernelbase/sync.c:756 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DeleteTimerQueueTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DeleteTimerQueueTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR*  descr) /* ../dlls/kernelbase/security.c:929 */
{
	TRACE("Enter DestroyPrivateObjectSecurity\n");
	return pDestroyPrivateObjectSecurity(descr);
}

extern WINAPI void wine32a_kernelbase_DestroyPrivateObjectSecurity(void);  /* ../dlls/kernelbase/security.c:929 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DestroyPrivateObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DestroyPrivateObjectSecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_kernelbase_DisablePredefinedHandleTableInternal(HKEY  hkey) /* ../dlls/kernelbase/registry.c:379 */
{
	TRACE("Enter DisablePredefinedHandleTableInternal\n");
	return pDisablePredefinedHandleTableInternal(hkey);
}

extern WINAPI void wine32a_kernelbase_DisablePredefinedHandleTableInternal(void);  /* ../dlls/kernelbase/registry.c:379 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DisablePredefinedHandleTableInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DisablePredefinedHandleTableInternal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DisableThreadLibraryCalls(HMODULE  module) /* ../dlls/kernelbase/loader.c:48 */
{
	TRACE("Enter DisableThreadLibraryCalls\n");
	return pDisableThreadLibraryCalls(module);
}

extern WINAPI void wine32a_kernelbase_DisableThreadLibraryCalls(void);  /* ../dlls/kernelbase/loader.c:48 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DisableThreadLibraryCalls,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DisableThreadLibraryCalls") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DisconnectNamedPipe(HANDLE  pipe) /* ../dlls/kernelbase/sync.c:1178 */
{
	TRACE("Enter DisconnectNamedPipe\n");
	return pDisconnectNamedPipe(pipe);
}

extern WINAPI void wine32a_kernelbase_DisconnectNamedPipe(void);  /* ../dlls/kernelbase/sync.c:1178 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DisconnectNamedPipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DisconnectNamedPipe") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DuplicateToken(HANDLE  token, SECURITY_IMPERSONATION_LEVEL  level, PHANDLE  ret) /* ../dlls/kernelbase/security.c:620 */
{
	TRACE("Enter DuplicateToken\n");
	return pDuplicateToken(token, level, ret);
}

extern WINAPI void wine32a_kernelbase_DuplicateToken(void);  /* ../dlls/kernelbase/security.c:620 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DuplicateToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DuplicateToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_DuplicateTokenEx(HANDLE  token, DWORD  access, LPSECURITY_ATTRIBUTES  sa, SECURITY_IMPERSONATION_LEVEL  level, TOKEN_TYPE  type, PHANDLE  ret) /* ../dlls/kernelbase/security.c:628 */
{
	TRACE("Enter DuplicateTokenEx\n");
	return pDuplicateTokenEx(token, access, sa, level, type, ret);
}

extern WINAPI void wine32a_kernelbase_DuplicateTokenEx(void);  /* ../dlls/kernelbase/security.c:628 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_DuplicateTokenEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_DuplicateTokenEx") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_EnumDynamicTimeZoneInformation(DWORD  index, DYNAMIC_TIME_ZONE_INFORMATION*  dtzi) /* ../dlls/kernelbase/registry.c:3072 */
{
	TRACE("Enter EnumDynamicTimeZoneInformation\n");
	return pEnumDynamicTimeZoneInformation(index, dtzi);
}

extern WINAPI void wine32a_kernelbase_EnumDynamicTimeZoneInformation(void);  /* ../dlls/kernelbase/registry.c:3072 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumDynamicTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumDynamicTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_EnumResourceLanguagesExA(HMODULE  module, LPCSTR  type, LPCSTR  name, ENUMRESLANGPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:264 */
{
	TRACE("Enter EnumResourceLanguagesExA\n");
	return pEnumResourceLanguagesExA(module, type, name, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceLanguagesExA(void);  /* ../dlls/kernelbase/loader.c:264 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceLanguagesExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceLanguagesExA") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EnumResourceLanguagesExW(HMODULE  module, LPCWSTR  type, LPCWSTR  name, ENUMRESLANGPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:324 */
{
	TRACE("Enter EnumResourceLanguagesExW\n");
	return pEnumResourceLanguagesExW(module, type, name, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceLanguagesExW(void);  /* ../dlls/kernelbase/loader.c:324 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceLanguagesExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceLanguagesExW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EnumResourceNamesExA(HMODULE  module, LPCSTR  type, ENUMRESNAMEPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:384 */
{
	TRACE("Enter EnumResourceNamesExA\n");
	return pEnumResourceNamesExA(module, type, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceNamesExA(void);  /* ../dlls/kernelbase/loader.c:384 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceNamesExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceNamesExA") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EnumResourceNamesExW(HMODULE  module, LPCWSTR  type, ENUMRESNAMEPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:464 */
{
	TRACE("Enter EnumResourceNamesExW\n");
	return pEnumResourceNamesExW(module, type, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceNamesExW(void);  /* ../dlls/kernelbase/loader.c:464 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceNamesExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceNamesExW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EnumResourceNamesW(HMODULE  module, LPCWSTR  type, ENUMRESNAMEPROCW  func, LONG_PTR  param) /* ../dlls/kernelbase/loader.c:541 */
{
	TRACE("Enter EnumResourceNamesW\n");
	return pEnumResourceNamesW(module, type, func, param);
}

extern WINAPI void wine32a_kernelbase_EnumResourceNamesW(void);  /* ../dlls/kernelbase/loader.c:541 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceNamesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceNamesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_EnumResourceTypesExA(HMODULE  module, ENUMRESTYPEPROCA  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:551 */
{
	TRACE("Enter EnumResourceTypesExA\n");
	return pEnumResourceTypesExA(module, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceTypesExA(void);  /* ../dlls/kernelbase/loader.c:551 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceTypesExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceTypesExA") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EnumResourceTypesExW(HMODULE  module, ENUMRESTYPEPROCW  func, LONG_PTR  param, DWORD  flags, LANGID  lang) /* ../dlls/kernelbase/loader.c:609 */
{
	TRACE("Enter EnumResourceTypesExW\n");
	return pEnumResourceTypesExW(module, func, param, flags, lang);
}

extern WINAPI void wine32a_kernelbase_EnumResourceTypesExW(void);  /* ../dlls/kernelbase/loader.c:609 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EnumResourceTypesExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EnumResourceTypesExW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_EqualPrefixSid(PSID  sid1, PSID  sid2) /* ../dlls/kernelbase/security.c:262 */
{
	TRACE("Enter EqualPrefixSid\n");
	return pEqualPrefixSid(sid1, sid2);
}

extern WINAPI void wine32a_kernelbase_EqualPrefixSid(void);  /* ../dlls/kernelbase/security.c:262 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EqualPrefixSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EqualPrefixSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_EqualSid(PSID  sid1, PSID  sid2) /* ../dlls/kernelbase/security.c:270 */
{
	TRACE("Enter EqualSid\n");
	return pEqualSid(sid1, sid2);
}

extern WINAPI void wine32a_kernelbase_EqualSid(void);  /* ../dlls/kernelbase/security.c:270 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_EqualSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_EqualSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FindActCtxSectionGuid(DWORD  flags, GUID*  ext_guid, ULONG  id, GUID*  guid, PACTCTX_SECTION_KEYED_DATA  info) /* ../dlls/kernelbase/loader.c:807 */
{
	TRACE("Enter FindActCtxSectionGuid\n");
	return pFindActCtxSectionGuid(flags, ext_guid, id, guid, info);
}

extern WINAPI void wine32a_kernelbase_FindActCtxSectionGuid(void);  /* ../dlls/kernelbase/loader.c:807 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FindActCtxSectionGuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FindActCtxSectionGuid") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_FindActCtxSectionStringW(DWORD  flags, GUID*  ext_guid, ULONG  id, LPCWSTR  str, PACTCTX_SECTION_KEYED_DATA  info) /* ../dlls/kernelbase/loader.c:817 */
{
	TRACE("Enter FindActCtxSectionStringW\n");
	return pFindActCtxSectionStringW(flags, ext_guid, id, str, info);
}

extern WINAPI void wine32a_kernelbase_FindActCtxSectionStringW(void);  /* ../dlls/kernelbase/loader.c:817 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FindActCtxSectionStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FindActCtxSectionStringW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_FindFirstFreeAce(PACL  acl, LPVOID*  ace) /* ../dlls/kernelbase/security.c:1361 */
{
	TRACE("Enter FindFirstFreeAce\n");
	return pFindFirstFreeAce(acl, ace);
}

extern WINAPI void wine32a_kernelbase_FindFirstFreeAce(void);  /* ../dlls/kernelbase/security.c:1361 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FindFirstFreeAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FindFirstFreeAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRSRC wine32b_kernelbase_FindResourceExW(HMODULE  module, LPCWSTR  type, LPCWSTR  name, WORD  lang) /* ../dlls/kernelbase/loader.c:662 */
{
	TRACE("Enter FindResourceExW\n");
	return pFindResourceExW(module, type, name, lang);
}

extern WINAPI void wine32a_kernelbase_FindResourceExW(void);  /* ../dlls/kernelbase/loader.c:662 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FindResourceExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FindResourceExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRSRC wine32b_kernelbase_FindResourceW(HINSTANCE  module, LPCWSTR  name, LPCWSTR  type) /* ../dlls/kernelbase/loader.c:700 */
{
	TRACE("Enter FindResourceW\n");
	return pFindResourceW(module, name, type);
}

extern WINAPI void wine32a_kernelbase_FindResourceW(void);  /* ../dlls/kernelbase/loader.c:700 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FindResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FindResourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_FlsAlloc(PFLS_CALLBACK_FUNCTION  callback) /* ../dlls/kernelbase/thread.c:948 */
{
	TRACE("Enter FlsAlloc\n");
	return pFlsAlloc(callback);
}

extern WINAPI void wine32a_kernelbase_FlsAlloc(void);  /* ../dlls/kernelbase/thread.c:948 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlsAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlsAlloc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FlsFree(DWORD  index) /* ../dlls/kernelbase/thread.c:990 */
{
	TRACE("Enter FlsFree\n");
	return pFlsFree(index);
}

extern WINAPI void wine32a_kernelbase_FlsFree(void);  /* ../dlls/kernelbase/thread.c:990 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlsFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlsFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_kernelbase_FlsGetValue(DWORD  index) /* ../dlls/kernelbase/thread.c:1012 */
{
	TRACE("Enter FlsGetValue\n");
	return pFlsGetValue(index);
}

extern WINAPI void wine32a_kernelbase_FlsGetValue(void);  /* ../dlls/kernelbase/thread.c:1012 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlsGetValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlsGetValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FlsSetValue(DWORD  index, PVOID  data) /* ../dlls/kernelbase/thread.c:1027 */
{
	TRACE("Enter FlsSetValue\n");
	return pFlsSetValue(index, data);
}

extern WINAPI void wine32a_kernelbase_FlsSetValue(void);  /* ../dlls/kernelbase/thread.c:1027 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlsSetValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlsSetValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FlushFileBuffers(HANDLE  file) /* ../dlls/kernelbase/file.c:843 */
{
	TRACE("Enter FlushFileBuffers\n");
	return pFlushFileBuffers(file);
}

extern WINAPI void wine32a_kernelbase_FlushFileBuffers(void);  /* ../dlls/kernelbase/file.c:843 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlushFileBuffers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlushFileBuffers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FlushInstructionCache(HANDLE  process, LPCVOID  addr, SIZE_T  size) /* ../dlls/kernelbase/process.c:47 */
{
	TRACE("Enter FlushInstructionCache\n");
	return pFlushInstructionCache(process, addr, size);
}

extern WINAPI void wine32a_kernelbase_FlushInstructionCache(void);  /* ../dlls/kernelbase/process.c:47 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FlushInstructionCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FlushInstructionCache") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_FreeLibraryAndExitThread(HINSTANCE  module, DWORD  exit_code) /* ../dlls/kernelbase/thread.c:126 */
{
	TRACE("Enter FreeLibraryAndExitThread\n");
	return pFreeLibraryAndExitThread(module, exit_code);
}

extern WINAPI void wine32a_kernelbase_FreeLibraryAndExitThread(void);  /* ../dlls/kernelbase/thread.c:126 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FreeLibraryAndExitThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FreeLibraryAndExitThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_FreeResource(HGLOBAL  handle) /* ../dlls/kernelbase/loader.c:709 */
{
	TRACE("Enter FreeResource\n");
	return pFreeResource(handle);
}

extern WINAPI void wine32a_kernelbase_FreeResource(void);  /* ../dlls/kernelbase/loader.c:709 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FreeResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FreeResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PVOID wine32b_kernelbase_FreeSid(PSID  pSid) /* ../dlls/kernelbase/security.c:280 */
{
	TRACE("Enter FreeSid\n");
	return pFreeSid(pSid);
}

extern WINAPI void wine32a_kernelbase_FreeSid(void);  /* ../dlls/kernelbase/security.c:280 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_FreeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_FreeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_GetAcceptLanguagesA(LPSTR  langbuf, DWORD*  buflen) /* ../dlls/kernelbase/main.c:246 */
{
	TRACE("Enter GetAcceptLanguagesA\n");
	return pGetAcceptLanguagesA(langbuf, buflen);
}

extern WINAPI void wine32a_kernelbase_GetAcceptLanguagesA(void);  /* ../dlls/kernelbase/main.c:246 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetAcceptLanguagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetAcceptLanguagesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_GetAcceptLanguagesW(WCHAR*  langbuf, DWORD*  buflen) /* ../dlls/kernelbase/main.c:312 */
{
	TRACE("Enter GetAcceptLanguagesW\n");
	return pGetAcceptLanguagesW(langbuf, buflen);
}

extern WINAPI void wine32a_kernelbase_GetAcceptLanguagesW(void);  /* ../dlls/kernelbase/main.c:312 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetAcceptLanguagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetAcceptLanguagesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetAce(PACL  acl, DWORD  index, LPVOID*  ace) /* ../dlls/kernelbase/security.c:1369 */
{
	TRACE("Enter GetAce\n");
	return pGetAce(acl, index, ace);
}

extern WINAPI void wine32a_kernelbase_GetAce(void);  /* ../dlls/kernelbase/security.c:1369 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetAclInformation(PACL  acl, LPVOID  info, DWORD  len, ACL_INFORMATION_CLASS  class) /* ../dlls/kernelbase/security.c:1377 */
{
	TRACE("Enter GetAclInformation\n");
	return pGetAclInformation(acl, info, len, class);
}

extern WINAPI void wine32a_kernelbase_GetAclInformation(void);  /* ../dlls/kernelbase/security.c:1377 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetAclInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetAclInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetCompressedFileSizeA(LPCSTR  name, LPDWORD  size_high) /* ../dlls/kernelbase/file.c:486 */
{
	TRACE("Enter GetCompressedFileSizeA\n");
	return pGetCompressedFileSizeA(name, size_high);
}

extern WINAPI void wine32a_kernelbase_GetCompressedFileSizeA(void);  /* ../dlls/kernelbase/file.c:486 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCompressedFileSizeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCompressedFileSizeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetCompressedFileSizeW(LPCWSTR  name, LPDWORD  size_high) /* ../dlls/kernelbase/file.c:498 */
{
	TRACE("Enter GetCompressedFileSizeW\n");
	return pGetCompressedFileSizeW(name, size_high);
}

extern WINAPI void wine32a_kernelbase_GetCompressedFileSizeW(void);  /* ../dlls/kernelbase/file.c:498 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCompressedFileSizeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCompressedFileSizeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetCurrentActCtx(HANDLE*  pcontext) /* ../dlls/kernelbase/loader.c:835 */
{
	TRACE("Enter GetCurrentActCtx\n");
	return pGetCurrentActCtx(pcontext);
}

extern WINAPI void wine32a_kernelbase_GetCurrentActCtx(void);  /* ../dlls/kernelbase/loader.c:835 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_GetCurrentProcess(void) /* ../dlls/kernelbase/process.c:56 */
{
	TRACE("Enter GetCurrentProcess\n");
	return pGetCurrentProcess();
}

extern WINAPI void wine32a_kernelbase_GetCurrentProcess(void);  /* ../dlls/kernelbase/process.c:56 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentProcess") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetCurrentProcessId(void) /* ../dlls/kernelbase/process.c:65 */
{
	TRACE("Enter GetCurrentProcessId\n");
	return pGetCurrentProcessId();
}

extern WINAPI void wine32a_kernelbase_GetCurrentProcessId(void);  /* ../dlls/kernelbase/process.c:65 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentProcessId") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_GetCurrentThread(void) /* ../dlls/kernelbase/thread.c:146 */
{
	TRACE("Enter GetCurrentThread\n");
	return pGetCurrentThread();
}

extern WINAPI void wine32a_kernelbase_GetCurrentThread(void);  /* ../dlls/kernelbase/thread.c:146 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentThread") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetCurrentThreadId(void) /* ../dlls/kernelbase/thread.c:155 */
{
	TRACE("Enter GetCurrentThreadId\n");
	return pGetCurrentThreadId();
}

extern WINAPI void wine32a_kernelbase_GetCurrentThreadId(void);  /* ../dlls/kernelbase/thread.c:155 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentThreadId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentThreadId") "\n"
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

extern WINAPI void wine32b_kernelbase_GetCurrentThreadStackLimits(ULONG_PTR*  low, ULONG_PTR*  high) /* ../dlls/kernelbase/thread.c:136 */
{
	TRACE("Enter GetCurrentThreadStackLimits\n");
	return pGetCurrentThreadStackLimits(low, high);
}

extern WINAPI void wine32a_kernelbase_GetCurrentThreadStackLimits(void);  /* ../dlls/kernelbase/thread.c:136 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetCurrentThreadStackLimits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetCurrentThreadStackLimits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetErrorMode(void) /* ../dlls/kernelbase/process.c:74 */
{
	TRACE("Enter GetErrorMode\n");
	return pGetErrorMode();
}

extern WINAPI void wine32a_kernelbase_GetErrorMode(void);  /* ../dlls/kernelbase/process.c:74 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetErrorMode") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetExitCodeProcess(HANDLE  process, LPDWORD  exit_code) /* ../dlls/kernelbase/process.c:87 */
{
	TRACE("Enter GetExitCodeProcess\n");
	return pGetExitCodeProcess(process, exit_code);
}

extern WINAPI void wine32a_kernelbase_GetExitCodeProcess(void);  /* ../dlls/kernelbase/process.c:87 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetExitCodeProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetExitCodeProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetExitCodeThread(HANDLE  thread, LPDWORD  exit_code) /* ../dlls/kernelbase/thread.c:164 */
{
	TRACE("Enter GetExitCodeThread\n");
	return pGetExitCodeThread(thread, exit_code);
}

extern WINAPI void wine32a_kernelbase_GetExitCodeThread(void);  /* ../dlls/kernelbase/thread.c:164 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetExitCodeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetExitCodeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileAttributesA(LPCSTR  name) /* ../dlls/kernelbase/file.c:536 */
{
	TRACE("Enter GetFileAttributesA\n");
	return pGetFileAttributesA(name);
}

extern WINAPI void wine32a_kernelbase_GetFileAttributesA(void);  /* ../dlls/kernelbase/file.c:536 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileAttributesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileAttributesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileAttributesExA(LPCSTR  name, GET_FILEEX_INFO_LEVELS  level, void*  ptr) /* ../dlls/kernelbase/file.c:586 */
{
	TRACE("Enter GetFileAttributesExA\n");
	return pGetFileAttributesExA(name, level, ptr);
}

extern WINAPI void wine32a_kernelbase_GetFileAttributesExA(void);  /* ../dlls/kernelbase/file.c:586 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileAttributesExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileAttributesExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileAttributesExW(LPCWSTR  name, GET_FILEEX_INFO_LEVELS  level, void*  ptr) /* ../dlls/kernelbase/file.c:598 */
{
	TRACE("Enter GetFileAttributesExW\n");
	return pGetFileAttributesExW(name, level, ptr);
}

extern WINAPI void wine32a_kernelbase_GetFileAttributesExW(void);  /* ../dlls/kernelbase/file.c:598 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileAttributesExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileAttributesExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileAttributesW(LPCWSTR  name) /* ../dlls/kernelbase/file.c:548 */
{
	TRACE("Enter GetFileAttributesW\n");
	return pGetFileAttributesW(name);
}

extern WINAPI void wine32a_kernelbase_GetFileAttributesW(void);  /* ../dlls/kernelbase/file.c:548 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileAttributesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileAttributesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileInformationByHandle(HANDLE  file, BY_HANDLE_FILE_INFORMATION*  info) /* ../dlls/kernelbase/file.c:857 */
{
	TRACE("Enter GetFileInformationByHandle\n");
	return pGetFileInformationByHandle(file, info);
}

extern WINAPI void wine32a_kernelbase_GetFileInformationByHandle(void);  /* ../dlls/kernelbase/file.c:857 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileInformationByHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileInformationByHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileInformationByHandleEx(HANDLE  handle, FILE_INFO_BY_HANDLE_CLASS  class, LPVOID  info, DWORD  size) /* ../dlls/kernelbase/file.c:887 */
{
	TRACE("Enter GetFileInformationByHandleEx\n");
	return pGetFileInformationByHandleEx(handle, class, info, size);
}

extern WINAPI void wine32a_kernelbase_GetFileInformationByHandleEx(void);  /* ../dlls/kernelbase/file.c:887 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileInformationByHandleEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileInformationByHandleEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileSecurityW(LPCWSTR  name, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, DWORD  len, LPDWORD  ret_len) /* ../dlls/kernelbase/security.c:939 */
{
	TRACE("Enter GetFileSecurityW\n");
	return pGetFileSecurityW(name, info, descr, len, ret_len);
}

extern WINAPI void wine32a_kernelbase_GetFileSecurityW(void);  /* ../dlls/kernelbase/security.c:939 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileSecurityW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileSecurityW") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetFileSize(HANDLE  file, LPDWORD  size_high) /* ../dlls/kernelbase/file.c:948 */
{
	TRACE("Enter GetFileSize\n");
	return pGetFileSize(file, size_high);
}

extern WINAPI void wine32a_kernelbase_GetFileSize(void);  /* ../dlls/kernelbase/file.c:948 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileSizeEx(HANDLE  file, PLARGE_INTEGER  size) /* ../dlls/kernelbase/file.c:962 */
{
	TRACE("Enter GetFileSizeEx\n");
	return pGetFileSizeEx(file, size);
}

extern WINAPI void wine32a_kernelbase_GetFileSizeEx(void);  /* ../dlls/kernelbase/file.c:962 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileSizeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileSizeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileTime(HANDLE  file, FILETIME*  creation, FILETIME*  access, FILETIME*  write) /* ../dlls/kernelbase/file.c:984 */
{
	TRACE("Enter GetFileTime\n");
	return pGetFileTime(file, creation, access, write);
}

extern WINAPI void wine32a_kernelbase_GetFileTime(void);  /* ../dlls/kernelbase/file.c:984 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileType(HANDLE  file) /* ../dlls/kernelbase/file.c:1015 */
{
	TRACE("Enter GetFileType\n");
	return pGetFileType(file);
}

extern WINAPI void wine32a_kernelbase_GetFileType(void);  /* ../dlls/kernelbase/file.c:1015 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileVersionInfoA(LPCSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data) /* ../dlls/kernelbase/version.c:849 */
{
	TRACE("Enter GetFileVersionInfoA\n");
	return pGetFileVersionInfoA(filename, handle, datasize, data);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoA(void);  /* ../dlls/kernelbase/version.c:849 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileVersionInfoExA(DWORD  flags, LPCSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data) /* ../dlls/kernelbase/version.c:818 */
{
	TRACE("Enter GetFileVersionInfoExA\n");
	return pGetFileVersionInfoExA(flags, filename, handle, datasize, data);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoExA(void);  /* ../dlls/kernelbase/version.c:818 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoExA") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetFileVersionInfoExW(DWORD  flags, LPCWSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data) /* ../dlls/kernelbase/version.c:734 */
{
	TRACE("Enter GetFileVersionInfoExW\n");
	return pGetFileVersionInfoExW(flags, filename, handle, datasize, data);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoExW(void);  /* ../dlls/kernelbase/version.c:734 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoExW") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetFileVersionInfoSizeA(LPCSTR  filename, LPDWORD  handle) /* ../dlls/kernelbase/version.c:615 */
{
	TRACE("Enter GetFileVersionInfoSizeA\n");
	return pGetFileVersionInfoSizeA(filename, handle);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoSizeA(void);  /* ../dlls/kernelbase/version.c:615 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoSizeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoSizeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileVersionInfoSizeExA(DWORD  flags, LPCSTR  filename, LPDWORD  handle) /* ../dlls/kernelbase/version.c:712 */
{
	TRACE("Enter GetFileVersionInfoSizeExA\n");
	return pGetFileVersionInfoSizeExA(flags, filename, handle);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoSizeExA(void);  /* ../dlls/kernelbase/version.c:712 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoSizeExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoSizeExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileVersionInfoSizeExW(DWORD  flags, LPCWSTR  filename, LPDWORD  handle) /* ../dlls/kernelbase/version.c:623 */
{
	TRACE("Enter GetFileVersionInfoSizeExW\n");
	return pGetFileVersionInfoSizeExW(flags, filename, handle);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoSizeExW(void);  /* ../dlls/kernelbase/version.c:623 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoSizeExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoSizeExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetFileVersionInfoSizeW(LPCWSTR  filename, LPDWORD  handle) /* ../dlls/kernelbase/version.c:607 */
{
	TRACE("Enter GetFileVersionInfoSizeW\n");
	return pGetFileVersionInfoSizeW(filename, handle);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoSizeW(void);  /* ../dlls/kernelbase/version.c:607 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoSizeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoSizeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetFileVersionInfoW(LPCWSTR  filename, DWORD  handle, DWORD  datasize, LPVOID  data) /* ../dlls/kernelbase/version.c:841 */
{
	TRACE("Enter GetFileVersionInfoW\n");
	return pGetFileVersionInfoW(filename, handle, datasize, data);
}

extern WINAPI void wine32a_kernelbase_GetFileVersionInfoW(void);  /* ../dlls/kernelbase/version.c:841 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetFileVersionInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetFileVersionInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetKernelObjectSecurity(HANDLE  handle, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, DWORD  len, LPDWORD  ret_len) /* ../dlls/kernelbase/security.c:964 */
{
	TRACE("Enter GetKernelObjectSecurity\n");
	return pGetKernelObjectSecurity(handle, info, descr, len, ret_len);
}

extern WINAPI void wine32a_kernelbase_GetKernelObjectSecurity(void);  /* ../dlls/kernelbase/security.c:964 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetKernelObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetKernelObjectSecurity") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetLastError(void) /* ../dlls/kernelbase/thread.c:177 */
{
	TRACE("Enter GetLastError\n");
	return pGetLastError();
}

extern WINAPI void wine32a_kernelbase_GetLastError(void);  /* ../dlls/kernelbase/thread.c:177 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetLastError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetLastError") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetLengthSid(PSID  sid) /* ../dlls/kernelbase/security.c:289 */
{
	TRACE("Enter GetLengthSid\n");
	return pGetLengthSid(sid);
}

extern WINAPI void wine32a_kernelbase_GetLengthSid(void);  /* ../dlls/kernelbase/security.c:289 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetLengthSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetLengthSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetModuleFileNameA(HMODULE  module, LPSTR  filename, DWORD  size) /* ../dlls/kernelbase/loader.c:57 */
{
	TRACE("Enter GetModuleFileNameA\n");
	return pGetModuleFileNameA(module, filename, size);
}

extern WINAPI void wine32a_kernelbase_GetModuleFileNameA(void);  /* ../dlls/kernelbase/loader.c:57 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetModuleFileNameW(HMODULE  module, LPWSTR  filename, DWORD  size) /* ../dlls/kernelbase/loader.c:83 */
{
	TRACE("Enter GetModuleFileNameW\n");
	return pGetModuleFileNameW(module, filename, size);
}

extern WINAPI void wine32a_kernelbase_GetModuleFileNameW(void);  /* ../dlls/kernelbase/loader.c:83 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_kernelbase_GetModuleHandleA(LPCSTR  module) /* ../dlls/kernelbase/loader.c:123 */
{
	TRACE("Enter GetModuleHandleA\n");
	return pGetModuleHandleA(module);
}

extern WINAPI void wine32a_kernelbase_GetModuleHandleA(void);  /* ../dlls/kernelbase/loader.c:123 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleHandleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleHandleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetModuleHandleExA(DWORD  flags, LPCSTR  name, HMODULE*  module) /* ../dlls/kernelbase/loader.c:147 */
{
	TRACE("Enter GetModuleHandleExA\n");
	return pGetModuleHandleExA(flags, name, module);
}

extern WINAPI void wine32a_kernelbase_GetModuleHandleExA(void);  /* ../dlls/kernelbase/loader.c:147 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleHandleExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleHandleExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetModuleHandleExW(DWORD  flags, LPCWSTR  name, HMODULE*  module) /* ../dlls/kernelbase/loader.c:162 */
{
	TRACE("Enter GetModuleHandleExW\n");
	return pGetModuleHandleExW(flags, name, module);
}

extern WINAPI void wine32a_kernelbase_GetModuleHandleExW(void);  /* ../dlls/kernelbase/loader.c:162 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleHandleExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleHandleExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_kernelbase_GetModuleHandleW(LPCWSTR  module) /* ../dlls/kernelbase/loader.c:135 */
{
	TRACE("Enter GetModuleHandleW\n");
	return pGetModuleHandleW(module);
}

extern WINAPI void wine32a_kernelbase_GetModuleHandleW(void);  /* ../dlls/kernelbase/loader.c:135 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetModuleHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetModuleHandleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetNamedPipeInfo(HANDLE  pipe, LPDWORD  flags, LPDWORD  out_size, LPDWORD  in_size, LPDWORD  instances) /* ../dlls/kernelbase/sync.c:1191 */
{
	TRACE("Enter GetNamedPipeInfo\n");
	return pGetNamedPipeInfo(pipe, flags, out_size, in_size, instances);
}

extern WINAPI void wine32a_kernelbase_GetNamedPipeInfo(void);  /* ../dlls/kernelbase/sync.c:1191 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetNamedPipeInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetNamedPipeInfo") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetOverlappedResult(HANDLE  file, LPOVERLAPPED  overlapped, LPDWORD  result, BOOL  wait) /* ../dlls/kernelbase/file.c:1050 */
{
	TRACE("Enter GetOverlappedResult\n");
	return pGetOverlappedResult(file, overlapped, result, wait);
}

extern WINAPI void wine32a_kernelbase_GetOverlappedResult(void);  /* ../dlls/kernelbase/file.c:1050 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetOverlappedResult,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetOverlappedResult") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetPriorityClass(HANDLE  process) /* ../dlls/kernelbase/process.c:101 */
{
	TRACE("Enter GetPriorityClass\n");
	return pGetPriorityClass(process);
}

extern WINAPI void wine32a_kernelbase_GetPriorityClass(void);  /* ../dlls/kernelbase/process.c:101 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetPriorityClass,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetPriorityClass") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR  obj_descr, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  ret_descr, DWORD  len, PDWORD  ret_len) /* ../dlls/kernelbase/security.c:973 */
{
	TRACE("Enter GetPrivateObjectSecurity\n");
	return pGetPrivateObjectSecurity(obj_descr, info, ret_descr, len, ret_len);
}

extern WINAPI void wine32a_kernelbase_GetPrivateObjectSecurity(void);  /* ../dlls/kernelbase/security.c:973 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetPrivateObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetPrivateObjectSecurity") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetProcessHandleCount(HANDLE  process, DWORD*  count) /* ../dlls/kernelbase/process.c:125 */
{
	TRACE("Enter GetProcessHandleCount\n");
	return pGetProcessHandleCount(process, count);
}

extern WINAPI void wine32a_kernelbase_GetProcessHandleCount(void);  /* ../dlls/kernelbase/process.c:125 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessHandleCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessHandleCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_GetProcessHeap(void) /* ../dlls/kernelbase/process.c:135 */
{
	TRACE("Enter GetProcessHeap\n");
	return pGetProcessHeap();
}

extern WINAPI void wine32a_kernelbase_GetProcessHeap(void);  /* ../dlls/kernelbase/process.c:135 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessHeap") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_GetProcessId(HANDLE  process) /* ../dlls/kernelbase/process.c:144 */
{
	TRACE("Enter GetProcessId\n");
	return pGetProcessId(process);
}

extern WINAPI void wine32a_kernelbase_GetProcessId(void);  /* ../dlls/kernelbase/process.c:144 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetProcessIdOfThread(HANDLE  thread) /* ../dlls/kernelbase/thread.c:186 */
{
	TRACE("Enter GetProcessIdOfThread\n");
	return pGetProcessIdOfThread(thread);
}

extern WINAPI void wine32a_kernelbase_GetProcessIdOfThread(void);  /* ../dlls/kernelbase/thread.c:186 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessIdOfThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessIdOfThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetProcessMitigationPolicy(HANDLE  process, PROCESS_MITIGATION_POLICY  policy, void*  buffer, SIZE_T  length) /* ../dlls/kernelbase/process.c:158 */
{
	TRACE("Enter GetProcessMitigationPolicy\n");
	return pGetProcessMitigationPolicy(process, policy, buffer, length);
}

extern WINAPI void wine32a_kernelbase_GetProcessMitigationPolicy(void);  /* ../dlls/kernelbase/process.c:158 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessMitigationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessMitigationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetProcessPriorityBoost(HANDLE  process, PBOOL  disable) /* ../dlls/kernelbase/process.c:169 */
{
	TRACE("Enter GetProcessPriorityBoost\n");
	return pGetProcessPriorityBoost(process, disable);
}

extern WINAPI void wine32a_kernelbase_GetProcessPriorityBoost(void);  /* ../dlls/kernelbase/process.c:169 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessPriorityBoost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessPriorityBoost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetProcessShutdownParameters(LPDWORD  level, LPDWORD  flags) /* ../dlls/kernelbase/process.c:180 */
{
	TRACE("Enter GetProcessShutdownParameters\n");
	return pGetProcessShutdownParameters(level, flags);
}

extern WINAPI void wine32a_kernelbase_GetProcessShutdownParameters(void);  /* ../dlls/kernelbase/process.c:180 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessShutdownParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessShutdownParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetProcessWorkingSetSizeEx(HANDLE  process, SIZE_T*  minset, SIZE_T*  maxset, DWORD*  flags) /* ../dlls/kernelbase/process.c:191 */
{
	TRACE("Enter GetProcessWorkingSetSizeEx\n");
	return pGetProcessWorkingSetSizeEx(process, minset, maxset, flags);
}

extern WINAPI void wine32a_kernelbase_GetProcessWorkingSetSizeEx(void);  /* ../dlls/kernelbase/process.c:191 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetProcessWorkingSetSizeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetProcessWorkingSetSizeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetQueuedCompletionStatus(HANDLE  port, LPDWORD  count, PULONG_PTR  key, LPOVERLAPPED*  overlapped, DWORD  timeout) /* ../dlls/kernelbase/sync.c:969 */
{
	TRACE("Enter GetQueuedCompletionStatus\n");
	return pGetQueuedCompletionStatus(port, count, key, overlapped, timeout);
}

extern WINAPI void wine32a_kernelbase_GetQueuedCompletionStatus(void);  /* ../dlls/kernelbase/sync.c:969 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetQueuedCompletionStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetQueuedCompletionStatus") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetQueuedCompletionStatusEx(HANDLE  port, OVERLAPPED_ENTRY*  entries, ULONG  count, ULONG*  written, DWORD  timeout, BOOL  alertable) /* ../dlls/kernelbase/sync.c:997 */
{
	TRACE("Enter GetQueuedCompletionStatusEx\n");
	return pGetQueuedCompletionStatusEx(port, entries, count, written, timeout, alertable);
}

extern WINAPI void wine32a_kernelbase_GetQueuedCompletionStatusEx(void);  /* ../dlls/kernelbase/sync.c:997 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetQueuedCompletionStatusEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetQueuedCompletionStatusEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR  descr, PSECURITY_DESCRIPTOR_CONTROL  control, LPDWORD  revision) /* ../dlls/kernelbase/security.c:1013 */
{
	TRACE("Enter GetSecurityDescriptorControl\n");
	return pGetSecurityDescriptorControl(descr, control, revision);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorControl(void);  /* ../dlls/kernelbase/security.c:1013 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorControl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR  descr, LPBOOL  dacl_present, PACL*  dacl, LPBOOL  dacl_defaulted) /* ../dlls/kernelbase/security.c:1022 */
{
	TRACE("Enter GetSecurityDescriptorDacl\n");
	return pGetSecurityDescriptorDacl(descr, dacl_present, dacl, dacl_defaulted);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorDacl(void);  /* ../dlls/kernelbase/security.c:1022 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorDacl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorDacl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR  descr, PSID*  group, LPBOOL  group_defaulted) /* ../dlls/kernelbase/security.c:1035 */
{
	TRACE("Enter GetSecurityDescriptorGroup\n");
	return pGetSecurityDescriptorGroup(descr, group, group_defaulted);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorGroup(void);  /* ../dlls/kernelbase/security.c:1035 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetSecurityDescriptorLength(PSECURITY_DESCRIPTOR  descr) /* ../dlls/kernelbase/security.c:1046 */
{
	TRACE("Enter GetSecurityDescriptorLength\n");
	return pGetSecurityDescriptorLength(descr);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorLength(void);  /* ../dlls/kernelbase/security.c:1046 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorLength,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorLength") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR  descr, PSID*  owner, LPBOOL  owner_defaulted) /* ../dlls/kernelbase/security.c:1054 */
{
	TRACE("Enter GetSecurityDescriptorOwner\n");
	return pGetSecurityDescriptorOwner(descr, owner, owner_defaulted);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorOwner(void);  /* ../dlls/kernelbase/security.c:1054 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorOwner,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorOwner") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR  descr, LPBOOL  sacl_present, PACL*  sacl, LPBOOL  sacl_defaulted) /* ../dlls/kernelbase/security.c:1065 */
{
	TRACE("Enter GetSecurityDescriptorSacl\n");
	return pGetSecurityDescriptorSacl(descr, sacl_present, sacl, sacl_defaulted);
}

extern WINAPI void wine32a_kernelbase_GetSecurityDescriptorSacl(void);  /* ../dlls/kernelbase/security.c:1065 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSecurityDescriptorSacl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSecurityDescriptorSacl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PSID_IDENTIFIER_AUTHORITY wine32b_kernelbase_GetSidIdentifierAuthority(PSID  sid) /* ../dlls/kernelbase/security.c:297 */
{
	TRACE("Enter GetSidIdentifierAuthority\n");
	return pGetSidIdentifierAuthority(sid);
}

extern WINAPI void wine32a_kernelbase_GetSidIdentifierAuthority(void);  /* ../dlls/kernelbase/security.c:297 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSidIdentifierAuthority,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSidIdentifierAuthority") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetSidLengthRequired(BYTE  count) /* ../dlls/kernelbase/security.c:306 */
{
	TRACE("Enter GetSidLengthRequired\n");
	return pGetSidLengthRequired(count);
}

extern WINAPI void wine32a_kernelbase_GetSidLengthRequired(void);  /* ../dlls/kernelbase/security.c:306 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSidLengthRequired,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSidLengthRequired") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PDWORD wine32b_kernelbase_GetSidSubAuthority(PSID  sid, DWORD  auth) /* ../dlls/kernelbase/security.c:314 */
{
	TRACE("Enter GetSidSubAuthority\n");
	return pGetSidSubAuthority(sid, auth);
}

extern WINAPI void wine32a_kernelbase_GetSidSubAuthority(void);  /* ../dlls/kernelbase/security.c:314 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSidSubAuthority,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSidSubAuthority") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PUCHAR wine32b_kernelbase_GetSidSubAuthorityCount(PSID  sid) /* ../dlls/kernelbase/security.c:323 */
{
	TRACE("Enter GetSidSubAuthorityCount\n");
	return pGetSidSubAuthorityCount(sid);
}

extern WINAPI void wine32a_kernelbase_GetSidSubAuthorityCount(void);  /* ../dlls/kernelbase/security.c:323 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSidSubAuthorityCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSidSubAuthorityCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetSystemDirectoryA(LPSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:647 */
{
	TRACE("Enter GetSystemDirectoryA\n");
	return pGetSystemDirectoryA(path, count);
}

extern WINAPI void wine32a_kernelbase_GetSystemDirectoryA(void);  /* ../dlls/kernelbase/file.c:647 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSystemDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSystemDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetSystemDirectoryW(LPWSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:656 */
{
	TRACE("Enter GetSystemDirectoryW\n");
	return pGetSystemDirectoryW(path, count);
}

extern WINAPI void wine32a_kernelbase_GetSystemDirectoryW(void);  /* ../dlls/kernelbase/file.c:656 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSystemDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSystemDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetSystemWindowsDirectoryA(LPSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:671 */
{
	TRACE("Enter GetSystemWindowsDirectoryA\n");
	return pGetSystemWindowsDirectoryA(path, count);
}

extern WINAPI void wine32a_kernelbase_GetSystemWindowsDirectoryA(void);  /* ../dlls/kernelbase/file.c:671 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSystemWindowsDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSystemWindowsDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetSystemWindowsDirectoryW(LPWSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:680 */
{
	TRACE("Enter GetSystemWindowsDirectoryW\n");
	return pGetSystemWindowsDirectoryW(path, count);
}

extern WINAPI void wine32a_kernelbase_GetSystemWindowsDirectoryW(void);  /* ../dlls/kernelbase/file.c:680 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetSystemWindowsDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetSystemWindowsDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetThreadContext(HANDLE  thread, CONTEXT*  context) /* ../dlls/kernelbase/thread.c:199 */
{
	TRACE("Enter GetThreadContext\n");
	return pGetThreadContext(thread, context);
}

extern WINAPI void wine32a_kernelbase_GetThreadContext(void);  /* ../dlls/kernelbase/thread.c:199 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetThreadErrorMode(void) /* ../dlls/kernelbase/thread.c:208 */
{
	TRACE("Enter GetThreadErrorMode\n");
	return pGetThreadErrorMode();
}

extern WINAPI void wine32a_kernelbase_GetThreadErrorMode(void);  /* ../dlls/kernelbase/thread.c:208 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadErrorMode") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetThreadGroupAffinity(HANDLE  thread, GROUP_AFFINITY*  affinity) /* ../dlls/kernelbase/thread.c:217 */
{
	TRACE("Enter GetThreadGroupAffinity\n");
	return pGetThreadGroupAffinity(thread, affinity);
}

extern WINAPI void wine32a_kernelbase_GetThreadGroupAffinity(void);  /* ../dlls/kernelbase/thread.c:217 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadGroupAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadGroupAffinity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetThreadIOPendingFlag(HANDLE  thread, PBOOL  pending) /* ../dlls/kernelbase/thread.c:232 */
{
	TRACE("Enter GetThreadIOPendingFlag\n");
	return pGetThreadIOPendingFlag(thread, pending);
}

extern WINAPI void wine32a_kernelbase_GetThreadIOPendingFlag(void);  /* ../dlls/kernelbase/thread.c:232 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadIOPendingFlag,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadIOPendingFlag") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_GetThreadId(HANDLE  thread) /* ../dlls/kernelbase/thread.c:242 */
{
	TRACE("Enter GetThreadId\n");
	return pGetThreadId(thread);
}

extern WINAPI void wine32a_kernelbase_GetThreadId(void);  /* ../dlls/kernelbase/thread.c:242 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_GetThreadPriority(HANDLE  thread) /* ../dlls/kernelbase/thread.c:255 */
{
	TRACE("Enter GetThreadPriority\n");
	return pGetThreadPriority(thread);
}

extern WINAPI void wine32a_kernelbase_GetThreadPriority(void);  /* ../dlls/kernelbase/thread.c:255 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadPriority,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadPriority") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetThreadPriorityBoost(HANDLE  thread, BOOL*  state) /* ../dlls/kernelbase/thread.c:269 */
{
	TRACE("Enter GetThreadPriorityBoost\n");
	return pGetThreadPriorityBoost(thread, state);
}

extern WINAPI void wine32a_kernelbase_GetThreadPriorityBoost(void);  /* ../dlls/kernelbase/thread.c:269 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadPriorityBoost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadPriorityBoost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_GetThreadTimes(HANDLE  thread, LPFILETIME  creationtime, LPFILETIME  exittime, LPFILETIME  kerneltime, LPFILETIME  usertime) /* ../dlls/kernelbase/thread.c:279 */
{
	TRACE("Enter GetThreadTimes\n");
	return pGetThreadTimes(thread, creationtime, exittime, kerneltime, usertime);
}

extern WINAPI void wine32a_kernelbase_GetThreadTimes(void);  /* ../dlls/kernelbase/thread.c:279 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadTimes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadTimes") "\n"
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

extern WINAPI LANGID wine32b_kernelbase_GetThreadUILanguage(void) /* ../dlls/kernelbase/thread.c:316 */
{
	TRACE("Enter GetThreadUILanguage\n");
	return pGetThreadUILanguage();
}

extern WINAPI void wine32a_kernelbase_GetThreadUILanguage(void);  /* ../dlls/kernelbase/thread.c:316 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetThreadUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetThreadUILanguage") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetTokenInformation(HANDLE  token, TOKEN_INFORMATION_CLASS  class, LPVOID  info, DWORD  len, LPDWORD  retlen) /* ../dlls/kernelbase/security.c:643 */
{
	TRACE("Enter GetTokenInformation\n");
	return pGetTokenInformation(token, class, info, len, retlen);
}

extern WINAPI void wine32a_kernelbase_GetTokenInformation(void);  /* ../dlls/kernelbase/security.c:643 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetTokenInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetTokenInformation") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_GetWindowsAccountDomainSid(PSID  sid, PSID  domain_sid, DWORD*  size) /* ../dlls/kernelbase/security.c:332 */
{
	TRACE("Enter GetWindowsAccountDomainSid\n");
	return pGetWindowsAccountDomainSid(sid, domain_sid, size);
}

extern WINAPI void wine32a_kernelbase_GetWindowsAccountDomainSid(void);  /* ../dlls/kernelbase/security.c:332 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetWindowsAccountDomainSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetWindowsAccountDomainSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetWindowsDirectoryA(LPSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:689 */
{
	TRACE("Enter GetWindowsDirectoryA\n");
	return pGetWindowsDirectoryA(path, count);
}

extern WINAPI void wine32a_kernelbase_GetWindowsDirectoryA(void);  /* ../dlls/kernelbase/file.c:689 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetWindowsDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetWindowsDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_GetWindowsDirectoryW(LPWSTR  path, UINT  count) /* ../dlls/kernelbase/file.c:698 */
{
	TRACE("Enter GetWindowsDirectoryW\n");
	return pGetWindowsDirectoryW(path, count);
}

extern WINAPI void wine32a_kernelbase_GetWindowsDirectoryW(void);  /* ../dlls/kernelbase/file.c:698 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_GetWindowsDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_GetWindowsDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_HashData(unsigned char*  src, DWORD  src_len, unsigned char*  dest, DWORD  dest_len) /* ../dlls/kernelbase/path.c:5017 */
{
	TRACE("Enter HashData\n");
	return pHashData(src, src_len, dest, dest_len);
}

extern WINAPI void wine32a_kernelbase_HashData(void);  /* ../dlls/kernelbase/path.c:5017 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_HashData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_HashData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ImpersonateAnonymousToken(HANDLE  thread) /* ../dlls/kernelbase/security.c:672 */
{
	TRACE("Enter ImpersonateAnonymousToken\n");
	return pImpersonateAnonymousToken(thread);
}

extern WINAPI void wine32a_kernelbase_ImpersonateAnonymousToken(void);  /* ../dlls/kernelbase/security.c:672 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ImpersonateAnonymousToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ImpersonateAnonymousToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ImpersonateLoggedOnUser(HANDLE  token) /* ../dlls/kernelbase/security.c:681 */
{
	TRACE("Enter ImpersonateLoggedOnUser\n");
	return pImpersonateLoggedOnUser(token);
}

extern WINAPI void wine32a_kernelbase_ImpersonateLoggedOnUser(void);  /* ../dlls/kernelbase/security.c:681 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ImpersonateLoggedOnUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ImpersonateLoggedOnUser") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ImpersonateNamedPipeClient(HANDLE  pipe) /* ../dlls/kernelbase/security.c:710 */
{
	TRACE("Enter ImpersonateNamedPipeClient\n");
	return pImpersonateNamedPipeClient(pipe);
}

extern WINAPI void wine32a_kernelbase_ImpersonateNamedPipeClient(void);  /* ../dlls/kernelbase/security.c:710 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ImpersonateNamedPipeClient,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ImpersonateNamedPipeClient") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL  level) /* ../dlls/kernelbase/security.c:721 */
{
	TRACE("Enter ImpersonateSelf\n");
	return pImpersonateSelf(level);
}

extern WINAPI void wine32a_kernelbase_ImpersonateSelf(void);  /* ../dlls/kernelbase/security.c:721 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ImpersonateSelf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ImpersonateSelf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeAcl(PACL  acl, DWORD  size, DWORD  rev) /* ../dlls/kernelbase/security.c:1385 */
{
	TRACE("Enter InitializeAcl\n");
	return pInitializeAcl(acl, size, rev);
}

extern WINAPI void wine32a_kernelbase_InitializeAcl(void);  /* ../dlls/kernelbase/security.c:1385 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeCriticalSectionAndSpinCount(CRITICAL_SECTION*  crit, DWORD  count) /* ../dlls/kernelbase/sync.c:770 */
{
	TRACE("Enter InitializeCriticalSectionAndSpinCount\n");
	return pInitializeCriticalSectionAndSpinCount(crit, count);
}

extern WINAPI void wine32a_kernelbase_InitializeCriticalSectionAndSpinCount(void);  /* ../dlls/kernelbase/sync.c:770 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeCriticalSectionAndSpinCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeCriticalSectionAndSpinCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeCriticalSectionEx(CRITICAL_SECTION*  crit, DWORD  spincount, DWORD  flags) /* ../dlls/kernelbase/sync.c:778 */
{
	TRACE("Enter InitializeCriticalSectionEx\n");
	return pInitializeCriticalSectionEx(crit, spincount, flags);
}

extern WINAPI void wine32a_kernelbase_InitializeCriticalSectionEx(void);  /* ../dlls/kernelbase/sync.c:778 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeCriticalSectionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeCriticalSectionEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeProcThreadAttributeList(struct _PROC_THREAD_ATTRIBUTE_LIST*  list, DWORD  count, DWORD  flags, SIZE_T*  size) /* ../dlls/kernelbase/process.c:373 */
{
	TRACE("Enter InitializeProcThreadAttributeList\n");
	return pInitializeProcThreadAttributeList(list, count, flags, size);
}

extern WINAPI void wine32a_kernelbase_InitializeProcThreadAttributeList(void);  /* ../dlls/kernelbase/process.c:373 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeProcThreadAttributeList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeProcThreadAttributeList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR  descr, DWORD  revision) /* ../dlls/kernelbase/security.c:1078 */
{
	TRACE("Enter InitializeSecurityDescriptor\n");
	return pInitializeSecurityDescriptor(descr, revision);
}

extern WINAPI void wine32a_kernelbase_InitializeSecurityDescriptor(void);  /* ../dlls/kernelbase/security.c:1078 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_InitializeSid(PSID  sid, PSID_IDENTIFIER_AUTHORITY  auth, BYTE  count) /* ../dlls/kernelbase/security.c:377 */
{
	TRACE("Enter InitializeSid\n");
	return pInitializeSid(sid, auth, count);
}

extern WINAPI void wine32a_kernelbase_InitializeSid(void);  /* ../dlls/kernelbase/security.c:377 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_InitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_InitializeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharAlphaA(CHAR  x) /* ../dlls/kernelbase/string.c:258 */
{
	TRACE("Enter IsCharAlphaA\n");
	return pIsCharAlphaA(x);
}

extern WINAPI void wine32a_kernelbase_IsCharAlphaA(void);  /* ../dlls/kernelbase/string.c:258 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharAlphaA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharAlphaA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharAlphaNumericA(CHAR  x) /* ../dlls/kernelbase/string.c:282 */
{
	TRACE("Enter IsCharAlphaNumericA\n");
	return pIsCharAlphaNumericA(x);
}

extern WINAPI void wine32a_kernelbase_IsCharAlphaNumericA(void);  /* ../dlls/kernelbase/string.c:282 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharAlphaNumericA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharAlphaNumericA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharAlphaNumericW(WCHAR  ch) /* ../dlls/kernelbase/string.c:289 */
{
	TRACE("Enter IsCharAlphaNumericW\n");
	return pIsCharAlphaNumericW(ch);
}

extern WINAPI void wine32a_kernelbase_IsCharAlphaNumericW(void);  /* ../dlls/kernelbase/string.c:289 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharAlphaNumericW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharAlphaNumericW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharAlphaW(WCHAR  ch) /* ../dlls/kernelbase/string.c:265 */
{
	TRACE("Enter IsCharAlphaW\n");
	return pIsCharAlphaW(ch);
}

extern WINAPI void wine32a_kernelbase_IsCharAlphaW(void);  /* ../dlls/kernelbase/string.c:265 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharAlphaW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharAlphaW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharBlankW(WCHAR  wc) /* ../dlls/kernelbase/string.c:222 */
{
	TRACE("Enter IsCharBlankW\n");
	return pIsCharBlankW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharBlankW(void);  /* ../dlls/kernelbase/string.c:222 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharBlankW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharBlankW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharCntrlW(WCHAR  wc) /* ../dlls/kernelbase/string.c:227 */
{
	TRACE("Enter IsCharCntrlW\n");
	return pIsCharCntrlW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharCntrlW(void);  /* ../dlls/kernelbase/string.c:227 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharCntrlW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharCntrlW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharDigitW(WCHAR  wc) /* ../dlls/kernelbase/string.c:232 */
{
	TRACE("Enter IsCharDigitW\n");
	return pIsCharDigitW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharDigitW(void);  /* ../dlls/kernelbase/string.c:232 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharDigitW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharDigitW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharLowerA(CHAR  x) /* ../dlls/kernelbase/string.c:270 */
{
	TRACE("Enter IsCharLowerA\n");
	return pIsCharLowerA(x);
}

extern WINAPI void wine32a_kernelbase_IsCharLowerA(void);  /* ../dlls/kernelbase/string.c:270 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharLowerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharLowerW(WCHAR  ch) /* ../dlls/kernelbase/string.c:277 */
{
	TRACE("Enter IsCharLowerW\n");
	return pIsCharLowerW(ch);
}

extern WINAPI void wine32a_kernelbase_IsCharLowerW(void);  /* ../dlls/kernelbase/string.c:277 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharLowerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharPunctW(WCHAR  wc) /* ../dlls/kernelbase/string.c:237 */
{
	TRACE("Enter IsCharPunctW\n");
	return pIsCharPunctW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharPunctW(void);  /* ../dlls/kernelbase/string.c:237 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharPunctW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharPunctW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharSpaceA(CHAR  c) /* ../dlls/kernelbase/string.c:242 */
{
	TRACE("Enter IsCharSpaceA\n");
	return pIsCharSpaceA(c);
}

extern WINAPI void wine32a_kernelbase_IsCharSpaceA(void);  /* ../dlls/kernelbase/string.c:242 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharSpaceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharSpaceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharSpaceW(WCHAR  wc) /* ../dlls/kernelbase/string.c:248 */
{
	TRACE("Enter IsCharSpaceW\n");
	return pIsCharSpaceW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharSpaceW(void);  /* ../dlls/kernelbase/string.c:248 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharSpaceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharSpaceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharUpperA(CHAR  x) /* ../dlls/kernelbase/string.c:294 */
{
	TRACE("Enter IsCharUpperA\n");
	return pIsCharUpperA(x);
}

extern WINAPI void wine32a_kernelbase_IsCharUpperA(void);  /* ../dlls/kernelbase/string.c:294 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharUpperA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharUpperW(WCHAR  ch) /* ../dlls/kernelbase/string.c:301 */
{
	TRACE("Enter IsCharUpperW\n");
	return pIsCharUpperW(ch);
}

extern WINAPI void wine32a_kernelbase_IsCharUpperW(void);  /* ../dlls/kernelbase/string.c:301 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharUpperW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsCharXDigitW(WCHAR  wc) /* ../dlls/kernelbase/string.c:253 */
{
	TRACE("Enter IsCharXDigitW\n");
	return pIsCharXDigitW(wc);
}

extern WINAPI void wine32a_kernelbase_IsCharXDigitW(void);  /* ../dlls/kernelbase/string.c:253 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsCharXDigitW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsCharXDigitW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsInternetESCEnabled(void) /* ../dlls/kernelbase/path.c:5067 */
{
	TRACE("Enter IsInternetESCEnabled\n");
	return pIsInternetESCEnabled();
}

extern WINAPI void wine32a_kernelbase_IsInternetESCEnabled(void);  /* ../dlls/kernelbase/path.c:5067 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsInternetESCEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsInternetESCEnabled") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_IsThreadAFiber(void) /* ../dlls/kernelbase/thread.c:915 */
{
	TRACE("Enter IsThreadAFiber\n");
	return pIsThreadAFiber();
}

extern WINAPI void wine32a_kernelbase_IsThreadAFiber(void);  /* ../dlls/kernelbase/thread.c:915 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsThreadAFiber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsThreadAFiber") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_IsTokenRestricted(HANDLE  token) /* ../dlls/kernelbase/security.c:729 */
{
	TRACE("Enter IsTokenRestricted\n");
	return pIsTokenRestricted(token);
}

extern WINAPI void wine32a_kernelbase_IsTokenRestricted(void);  /* ../dlls/kernelbase/security.c:729 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsTokenRestricted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsTokenRestricted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsValidAcl(PACL  acl) /* ../dlls/kernelbase/security.c:1393 */
{
	TRACE("Enter IsValidAcl\n");
	return pIsValidAcl(acl);
}

extern WINAPI void wine32a_kernelbase_IsValidAcl(void);  /* ../dlls/kernelbase/security.c:1393 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsValidAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsValidAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR  descr) /* ../dlls/kernelbase/security.c:1086 */
{
	TRACE("Enter IsValidSecurityDescriptor\n");
	return pIsValidSecurityDescriptor(descr);
}

extern WINAPI void wine32a_kernelbase_IsValidSecurityDescriptor(void);  /* ../dlls/kernelbase/security.c:1086 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsValidSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsValidSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsValidSid(PSID  sid) /* ../dlls/kernelbase/security.c:385 */
{
	TRACE("Enter IsValidSid\n");
	return pIsValidSid(sid);
}

extern WINAPI void wine32a_kernelbase_IsValidSid(void);  /* ../dlls/kernelbase/security.c:385 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsValidSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsValidSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsWellKnownSid(PSID  sid, WELL_KNOWN_SID_TYPE  type) /* ../dlls/kernelbase/security.c:467 */
{
	TRACE("Enter IsWellKnownSid\n");
	return pIsWellKnownSid(sid, type);
}

extern WINAPI void wine32a_kernelbase_IsWellKnownSid(void);  /* ../dlls/kernelbase/security.c:467 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsWellKnownSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsWellKnownSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_IsWow64Process(HANDLE  process, PBOOL  wow64) /* ../dlls/kernelbase/process.c:206 */
{
	TRACE("Enter IsWow64Process\n");
	return pIsWow64Process(process, wow64);
}

extern WINAPI void wine32a_kernelbase_IsWow64Process(void);  /* ../dlls/kernelbase/process.c:206 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_IsWow64Process,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_IsWow64Process") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HGLOBAL wine32b_kernelbase_LoadResource(HINSTANCE  module, HRSRC  rsrc) /* ../dlls/kernelbase/loader.c:718 */
{
	TRACE("Enter LoadResource\n");
	return pLoadResource(module, rsrc);
}

extern WINAPI void wine32a_kernelbase_LoadResource(void);  /* ../dlls/kernelbase/loader.c:718 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LoadResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LoadResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_LoadStringA(HINSTANCE  instance, UINT  resource_id, LPSTR  buffer, INT  buflen) /* ../dlls/kernelbase/string.c:1366 */
{
	TRACE("Enter LoadStringA\n");
	return pLoadStringA(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_kernelbase_LoadStringA(void);  /* ../dlls/kernelbase/string.c:1366 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LoadStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LoadStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_LoadStringW(HINSTANCE  instance, UINT  resource_id, LPWSTR  buffer, INT  buflen) /* ../dlls/kernelbase/string.c:1314 */
{
	TRACE("Enter LoadStringW\n");
	return pLoadStringW(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_kernelbase_LoadStringW(void);  /* ../dlls/kernelbase/string.c:1314 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LoadStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LoadStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_LockFile(HANDLE  file, DWORD  offset_low, DWORD  offset_high, DWORD  count_low, DWORD  count_high) /* ../dlls/kernelbase/file.c:1080 */
{
	TRACE("Enter LockFile\n");
	return pLockFile(file, offset_low, offset_high, count_low, count_high);
}

extern WINAPI void wine32a_kernelbase_LockFile(void);  /* ../dlls/kernelbase/file.c:1080 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LockFile") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_LockFileEx(HANDLE  file, DWORD  flags, DWORD  reserved, DWORD  count_low, DWORD  count_high, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1098 */
{
	TRACE("Enter LockFileEx\n");
	return pLockFileEx(file, flags, reserved, count_low, count_high, overlapped);
}

extern WINAPI void wine32a_kernelbase_LockFileEx(void);  /* ../dlls/kernelbase/file.c:1098 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LockFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LockFileEx") "\n"
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

extern WINAPI LPVOID wine32b_kernelbase_LockResource(HGLOBAL  handle) /* ../dlls/kernelbase/loader.c:736 */
{
	TRACE("Enter LockResource\n");
	return pLockResource(handle);
}

extern WINAPI void wine32a_kernelbase_LockResource(void);  /* ../dlls/kernelbase/loader.c:736 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_LockResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_LockResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_MakeAbsoluteSD(PSECURITY_DESCRIPTOR  rel_descr, PSECURITY_DESCRIPTOR  abs_descr, LPDWORD  abs_size, PACL  dacl, LPDWORD  dacl_size, PACL  sacl, LPDWORD  sacl_size, PSID  owner, LPDWORD  owner_size, PSID  group, LPDWORD  group_size) /* ../dlls/kernelbase/security.c:1094 */
{
	TRACE("Enter MakeAbsoluteSD\n");
	return pMakeAbsoluteSD(rel_descr, abs_descr, abs_size, dacl, dacl_size, sacl, sacl_size, owner, owner_size, group, group_size);
}

extern WINAPI void wine32a_kernelbase_MakeAbsoluteSD(void);  /* ../dlls/kernelbase/security.c:1094 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_MakeAbsoluteSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_MakeAbsoluteSD") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_MakeSelfRelativeSD(PSECURITY_DESCRIPTOR  abs_descr, PSECURITY_DESCRIPTOR  rel_descr, LPDWORD  len) /* ../dlls/kernelbase/security.c:1106 */
{
	TRACE("Enter MakeSelfRelativeSD\n");
	return pMakeSelfRelativeSD(abs_descr, rel_descr, len);
}

extern WINAPI void wine32a_kernelbase_MakeSelfRelativeSD(void);  /* ../dlls/kernelbase/security.c:1106 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_MakeSelfRelativeSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_MakeSelfRelativeSD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_MapGenericMask(PDWORD  access, PGENERIC_MAPPING  mapping) /* ../dlls/kernelbase/security.c:1401 */
{
	TRACE("Enter MapGenericMask\n");
	return pMapGenericMask(access, mapping);
}

extern WINAPI void wine32a_kernelbase_MapGenericMask(void);  /* ../dlls/kernelbase/security.c:1401 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_MapGenericMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_MapGenericMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ObjectCloseAuditAlarmW(LPCWSTR  subsystem, LPVOID  id, BOOL  on_close) /* ../dlls/kernelbase/security.c:1409 */
{
	TRACE("Enter ObjectCloseAuditAlarmW\n");
	return pObjectCloseAuditAlarmW(subsystem, id, on_close);
}

extern WINAPI void wine32a_kernelbase_ObjectCloseAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1409 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ObjectCloseAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ObjectCloseAuditAlarmW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ObjectDeleteAuditAlarmW(LPCWSTR  subsystem, LPVOID  id, BOOL  on_close) /* ../dlls/kernelbase/security.c:1418 */
{
	TRACE("Enter ObjectDeleteAuditAlarmW\n");
	return pObjectDeleteAuditAlarmW(subsystem, id, on_close);
}

extern WINAPI void wine32a_kernelbase_ObjectDeleteAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1418 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ObjectDeleteAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ObjectDeleteAuditAlarmW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ObjectOpenAuditAlarmW(LPCWSTR  subsystem, LPVOID  id, LPWSTR  type, LPWSTR  name, PSECURITY_DESCRIPTOR  descr, HANDLE  token, DWORD  desired, DWORD  granted, PPRIVILEGE_SET  privs, BOOL  creation, BOOL  access, LPBOOL  on_close) /* ../dlls/kernelbase/security.c:1427 */
{
	TRACE("Enter ObjectOpenAuditAlarmW\n");
	return pObjectOpenAuditAlarmW(subsystem, id, type, name, descr, token, desired, granted, privs, creation, access, on_close);
}

extern WINAPI void wine32a_kernelbase_ObjectOpenAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1427 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ObjectOpenAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ObjectOpenAuditAlarmW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_ObjectPrivilegeAuditAlarmW(LPCWSTR  subsystem, LPVOID  id, HANDLE  token, DWORD  desired, PPRIVILEGE_SET  privs, BOOL  granted) /* ../dlls/kernelbase/security.c:1441 */
{
	TRACE("Enter ObjectPrivilegeAuditAlarmW\n");
	return pObjectPrivilegeAuditAlarmW(subsystem, id, token, desired, privs, granted);
}

extern WINAPI void wine32a_kernelbase_ObjectPrivilegeAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1441 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ObjectPrivilegeAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ObjectPrivilegeAuditAlarmW") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_OpenEventA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernelbase/sync.c:368 */
{
	TRACE("Enter OpenEventA\n");
	return pOpenEventA(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenEventA(void);  /* ../dlls/kernelbase/sync.c:368 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenEventA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenEventA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenEventW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:386 */
{
	TRACE("Enter OpenEventW\n");
	return pOpenEventW(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenEventW(void);  /* ../dlls/kernelbase/sync.c:386 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenEventW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenEventW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenFileById(HANDLE  handle, LPFILE_ID_DESCRIPTOR  id, DWORD  access, DWORD  share, LPSECURITY_ATTRIBUTES  sec_attr, DWORD  flags) /* ../dlls/kernelbase/file.c:1130 */
{
	TRACE("Enter OpenFileById\n");
	return pOpenFileById(handle, id, access, share, sec_attr, flags);
}

extern WINAPI void wine32a_kernelbase_OpenFileById(void);  /* ../dlls/kernelbase/file.c:1130 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenFileById,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenFileById") "\n"
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

extern WINAPI HANDLE wine32b_kernelbase_OpenFileMappingW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:862 */
{
	TRACE("Enter OpenFileMappingW\n");
	return pOpenFileMappingW(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenFileMappingW(void);  /* ../dlls/kernelbase/sync.c:862 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenFileMappingW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenFileMappingW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenMutexW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:503 */
{
	TRACE("Enter OpenMutexW\n");
	return pOpenMutexW(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenMutexW(void);  /* ../dlls/kernelbase/sync.c:503 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenMutexW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenMutexW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenProcess(DWORD  access, BOOL  inherit, DWORD  id) /* ../dlls/kernelbase/process.c:220 */
{
	TRACE("Enter OpenProcess\n");
	return pOpenProcess(access, inherit, id);
}

extern WINAPI void wine32a_kernelbase_OpenProcess(void);  /* ../dlls/kernelbase/process.c:220 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_OpenProcessToken(HANDLE  process, DWORD  access, HANDLE*  handle) /* ../dlls/kernelbase/security.c:764 */
{
	TRACE("Enter OpenProcessToken\n");
	return pOpenProcessToken(process, access, handle);
}

extern WINAPI void wine32a_kernelbase_OpenProcessToken(void);  /* ../dlls/kernelbase/security.c:764 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenProcessToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenProcessToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenSemaphoreW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:573 */
{
	TRACE("Enter OpenSemaphoreW\n");
	return pOpenSemaphoreW(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenSemaphoreW(void);  /* ../dlls/kernelbase/sync.c:573 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenSemaphoreW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenSemaphoreW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenThread(DWORD  access, BOOL  inherit, DWORD  id) /* ../dlls/kernelbase/thread.c:329 */
{
	TRACE("Enter OpenThread\n");
	return pOpenThread(access, inherit, id);
}

extern WINAPI void wine32a_kernelbase_OpenThread(void);  /* ../dlls/kernelbase/thread.c:329 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_OpenThreadToken(HANDLE  thread, DWORD  access, BOOL  self, HANDLE*  handle) /* ../dlls/kernelbase/security.c:772 */
{
	TRACE("Enter OpenThreadToken\n");
	return pOpenThreadToken(thread, access, self, handle);
}

extern WINAPI void wine32a_kernelbase_OpenThreadToken(void);  /* ../dlls/kernelbase/security.c:772 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenThreadToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenThreadToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_OpenWaitableTimerW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernelbase/sync.c:644 */
{
	TRACE("Enter OpenWaitableTimerW\n");
	return pOpenWaitableTimerW(access, inherit, name);
}

extern WINAPI void wine32a_kernelbase_OpenWaitableTimerW(void);  /* ../dlls/kernelbase/sync.c:644 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_OpenWaitableTimerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_OpenWaitableTimerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_ParseURLA(char*  url, PARSEDURLA*  result) /* ../dlls/kernelbase/path.c:2794 */
{
	TRACE("Enter ParseURLA\n");
	return pParseURLA(url, result);
}

extern WINAPI void wine32a_kernelbase_ParseURLA(void);  /* ../dlls/kernelbase/path.c:2794 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ParseURLA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ParseURLA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_ParseURLW(WCHAR*  url, PARSEDURLW*  result) /* ../dlls/kernelbase/path.c:2826 */
{
	TRACE("Enter ParseURLW\n");
	return pParseURLW(url, result);
}

extern WINAPI void wine32a_kernelbase_ParseURLW(void);  /* ../dlls/kernelbase/path.c:2826 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ParseURLW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ParseURLW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathAddBackslashA(char*  path) /* ../dlls/kernelbase/path.c:1204 */
{
	TRACE("Enter PathAddBackslashA\n");
	return pPathAddBackslashA(path);
}

extern WINAPI void wine32a_kernelbase_PathAddBackslashA(void);  /* ../dlls/kernelbase/path.c:1204 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAddBackslashA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAddBackslashA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathAddBackslashW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1233 */
{
	TRACE("Enter PathAddBackslashW\n");
	return pPathAddBackslashW(path);
}

extern WINAPI void wine32a_kernelbase_PathAddBackslashW(void);  /* ../dlls/kernelbase/path.c:1233 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAddBackslashW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAddBackslashW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathAddExtensionA(char*  path, char*  ext) /* ../dlls/kernelbase/path.c:1297 */
{
	TRACE("Enter PathAddExtensionA\n");
	return pPathAddExtensionA(path, ext);
}

extern WINAPI void wine32a_kernelbase_PathAddExtensionA(void);  /* ../dlls/kernelbase/path.c:1297 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAddExtensionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAddExtensionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathAddExtensionW(WCHAR*  path, WCHAR*  ext) /* ../dlls/kernelbase/path.c:1314 */
{
	TRACE("Enter PathAddExtensionW\n");
	return pPathAddExtensionW(path, ext);
}

extern WINAPI void wine32a_kernelbase_PathAddExtensionW(void);  /* ../dlls/kernelbase/path.c:1314 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAddExtensionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAddExtensionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathAllocCanonicalize(WCHAR*  path_in, DWORD  flags, WCHAR**  path_out) /* ../dlls/kernelbase/path.c:201 */
{
	TRACE("Enter PathAllocCanonicalize\n");
	return pPathAllocCanonicalize(path_in, flags, path_out);
}

extern WINAPI void wine32a_kernelbase_PathAllocCanonicalize(void);  /* ../dlls/kernelbase/path.c:201 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAllocCanonicalize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAllocCanonicalize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathAllocCombine(WCHAR*  path1, WCHAR*  path2, DWORD  flags, WCHAR**  out) /* ../dlls/kernelbase/path.c:383 */
{
	TRACE("Enter PathAllocCombine\n");
	return pPathAllocCombine(path1, path2, flags, out);
}

extern WINAPI void wine32a_kernelbase_PathAllocCombine(void);  /* ../dlls/kernelbase/path.c:383 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAllocCombine,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAllocCombine") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathAppendA(char*  path, char*  append) /* ../dlls/kernelbase/path.c:1538 */
{
	TRACE("Enter PathAppendA\n");
	return pPathAppendA(path, append);
}

extern WINAPI void wine32a_kernelbase_PathAppendA(void);  /* ../dlls/kernelbase/path.c:1538 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAppendA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAppendA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathAppendW(WCHAR*  path, WCHAR*  append) /* ../dlls/kernelbase/path.c:1555 */
{
	TRACE("Enter PathAppendW\n");
	return pPathAppendW(path, append);
}

extern WINAPI void wine32a_kernelbase_PathAppendW(void);  /* ../dlls/kernelbase/path.c:1555 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathAppendW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathAppendW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathCanonicalizeA(char*  buffer, char*  path) /* ../dlls/kernelbase/path.c:1424 */
{
	TRACE("Enter PathCanonicalizeA\n");
	return pPathCanonicalizeA(buffer, path);
}

extern WINAPI void wine32a_kernelbase_PathCanonicalizeA(void);  /* ../dlls/kernelbase/path.c:1424 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCanonicalizeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCanonicalizeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathCanonicalizeW(WCHAR*  buffer, WCHAR*  path) /* ../dlls/kernelbase/path.c:1331 */
{
	TRACE("Enter PathCanonicalizeW\n");
	return pPathCanonicalizeW(buffer, path);
}

extern WINAPI void wine32a_kernelbase_PathCanonicalizeW(void);  /* ../dlls/kernelbase/path.c:1331 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCanonicalizeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCanonicalizeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchAddBackslash(WCHAR*  path, SIZE_T  size) /* ../dlls/kernelbase/path.c:440 */
{
	TRACE("Enter PathCchAddBackslash\n");
	return pPathCchAddBackslash(path, size);
}

extern WINAPI void wine32a_kernelbase_PathCchAddBackslash(void);  /* ../dlls/kernelbase/path.c:440 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchAddBackslash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchAddBackslash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchAddBackslashEx(WCHAR*  path, SIZE_T  size, WCHAR**  endptr, SIZE_T*  remaining) /* ../dlls/kernelbase/path.c:445 */
{
	TRACE("Enter PathCchAddBackslashEx\n");
	return pPathCchAddBackslashEx(path, size, endptr, remaining);
}

extern WINAPI void wine32a_kernelbase_PathCchAddBackslashEx(void);  /* ../dlls/kernelbase/path.c:445 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchAddBackslashEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchAddBackslashEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchAddExtension(WCHAR*  path, SIZE_T  size, WCHAR*  extension) /* ../dlls/kernelbase/path.c:478 */
{
	TRACE("Enter PathCchAddExtension\n");
	return pPathCchAddExtension(path, size, extension);
}

extern WINAPI void wine32a_kernelbase_PathCchAddExtension(void);  /* ../dlls/kernelbase/path.c:478 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchAddExtension,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchAddExtension") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchAppend(WCHAR*  path1, SIZE_T  size, WCHAR*  path2) /* ../dlls/kernelbase/path.c:521 */
{
	TRACE("Enter PathCchAppend\n");
	return pPathCchAppend(path1, size, path2);
}

extern WINAPI void wine32a_kernelbase_PathCchAppend(void);  /* ../dlls/kernelbase/path.c:521 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchAppend,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchAppend") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchAppendEx(WCHAR*  path1, SIZE_T  size, WCHAR*  path2, DWORD  flags) /* ../dlls/kernelbase/path.c:528 */
{
	TRACE("Enter PathCchAppendEx\n");
	return pPathCchAppendEx(path1, size, path2, flags);
}

extern WINAPI void wine32a_kernelbase_PathCchAppendEx(void);  /* ../dlls/kernelbase/path.c:528 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchAppendEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchAppendEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchCanonicalize(WCHAR*  out, SIZE_T  size, WCHAR*  in) /* ../dlls/kernelbase/path.c:553 */
{
	TRACE("Enter PathCchCanonicalize\n");
	return pPathCchCanonicalize(out, size, in);
}

extern WINAPI void wine32a_kernelbase_PathCchCanonicalize(void);  /* ../dlls/kernelbase/path.c:553 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchCanonicalize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchCanonicalize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchCanonicalizeEx(WCHAR*  out, SIZE_T  size, WCHAR*  in, DWORD  flags) /* ../dlls/kernelbase/path.c:564 */
{
	TRACE("Enter PathCchCanonicalizeEx\n");
	return pPathCchCanonicalizeEx(out, size, in, flags);
}

extern WINAPI void wine32a_kernelbase_PathCchCanonicalizeEx(void);  /* ../dlls/kernelbase/path.c:564 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchCanonicalizeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchCanonicalizeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchCombine(WCHAR*  out, SIZE_T  size, WCHAR*  path1, WCHAR*  path2) /* ../dlls/kernelbase/path.c:603 */
{
	TRACE("Enter PathCchCombine\n");
	return pPathCchCombine(out, size, path1, path2);
}

extern WINAPI void wine32a_kernelbase_PathCchCombine(void);  /* ../dlls/kernelbase/path.c:603 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchCombine,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchCombine") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchCombineEx(WCHAR*  out, SIZE_T  size, WCHAR*  path1, WCHAR*  path2, DWORD  flags) /* ../dlls/kernelbase/path.c:610 */
{
	TRACE("Enter PathCchCombineEx\n");
	return pPathCchCombineEx(out, size, path1, path2, flags);
}

extern WINAPI void wine32a_kernelbase_PathCchCombineEx(void);  /* ../dlls/kernelbase/path.c:610 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchCombineEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchCombineEx") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_PathCchFindExtension(WCHAR*  path, SIZE_T  size, WCHAR**  extension) /* ../dlls/kernelbase/path.c:642 */
{
	TRACE("Enter PathCchFindExtension\n");
	return pPathCchFindExtension(path, size, extension);
}

extern WINAPI void wine32a_kernelbase_PathCchFindExtension(void);  /* ../dlls/kernelbase/path.c:642 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchFindExtension,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchFindExtension") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathCchIsRoot(WCHAR*  path) /* ../dlls/kernelbase/path.c:675 */
{
	TRACE("Enter PathCchIsRoot\n");
	return pPathCchIsRoot(path);
}

extern WINAPI void wine32a_kernelbase_PathCchIsRoot(void);  /* ../dlls/kernelbase/path.c:675 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchIsRoot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchIsRoot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchRemoveBackslash(WCHAR*  path, SIZE_T  path_size) /* ../dlls/kernelbase/path.c:713 */
{
	TRACE("Enter PathCchRemoveBackslash\n");
	return pPathCchRemoveBackslash(path, path_size);
}

extern WINAPI void wine32a_kernelbase_PathCchRemoveBackslash(void);  /* ../dlls/kernelbase/path.c:713 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchRemoveBackslash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchRemoveBackslash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchRemoveBackslashEx(WCHAR*  path, SIZE_T  path_size, WCHAR**  path_end, SIZE_T*  free_size) /* ../dlls/kernelbase/path.c:723 */
{
	TRACE("Enter PathCchRemoveBackslashEx\n");
	return pPathCchRemoveBackslashEx(path, path_size, path_end, free_size);
}

extern WINAPI void wine32a_kernelbase_PathCchRemoveBackslashEx(void);  /* ../dlls/kernelbase/path.c:723 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchRemoveBackslashEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchRemoveBackslashEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchRemoveExtension(WCHAR*  path, SIZE_T  size) /* ../dlls/kernelbase/path.c:762 */
{
	TRACE("Enter PathCchRemoveExtension\n");
	return pPathCchRemoveExtension(path, size);
}

extern WINAPI void wine32a_kernelbase_PathCchRemoveExtension(void);  /* ../dlls/kernelbase/path.c:762 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchRemoveExtension,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchRemoveExtension") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchRemoveFileSpec(WCHAR*  path, SIZE_T  size) /* ../dlls/kernelbase/path.c:781 */
{
	TRACE("Enter PathCchRemoveFileSpec\n");
	return pPathCchRemoveFileSpec(path, size);
}

extern WINAPI void wine32a_kernelbase_PathCchRemoveFileSpec(void);  /* ../dlls/kernelbase/path.c:781 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchRemoveFileSpec,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchRemoveFileSpec") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchRenameExtension(WCHAR*  path, SIZE_T  size, WCHAR*  extension) /* ../dlls/kernelbase/path.c:818 */
{
	TRACE("Enter PathCchRenameExtension\n");
	return pPathCchRenameExtension(path, size, extension);
}

extern WINAPI void wine32a_kernelbase_PathCchRenameExtension(void);  /* ../dlls/kernelbase/path.c:818 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchRenameExtension,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchRenameExtension") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchSkipRoot(WCHAR*  path, WCHAR**  root_end) /* ../dlls/kernelbase/path.c:831 */
{
	TRACE("Enter PathCchSkipRoot\n");
	return pPathCchSkipRoot(path, root_end);
}

extern WINAPI void wine32a_kernelbase_PathCchSkipRoot(void);  /* ../dlls/kernelbase/path.c:831 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchSkipRoot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchSkipRoot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchStripPrefix(WCHAR*  path, SIZE_T  size) /* ../dlls/kernelbase/path.c:863 */
{
	TRACE("Enter PathCchStripPrefix\n");
	return pPathCchStripPrefix(path, size);
}

extern WINAPI void wine32a_kernelbase_PathCchStripPrefix(void);  /* ../dlls/kernelbase/path.c:863 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchStripPrefix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchStripPrefix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCchStripToRoot(WCHAR*  path, SIZE_T  size) /* ../dlls/kernelbase/path.c:887 */
{
	TRACE("Enter PathCchStripToRoot\n");
	return pPathCchStripToRoot(path, size);
}

extern WINAPI void wine32a_kernelbase_PathCchStripToRoot(void);  /* ../dlls/kernelbase/path.c:887 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCchStripToRoot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCchStripToRoot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathCombineA(char*  dst, char*  dir, char*  file) /* ../dlls/kernelbase/path.c:1511 */
{
	TRACE("Enter PathCombineA\n");
	return pPathCombineA(dst, dir, file);
}

extern WINAPI void wine32a_kernelbase_PathCombineA(void);  /* ../dlls/kernelbase/path.c:1511 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCombineA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCombineA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathCombineW(WCHAR*  dst, WCHAR*  dir, WCHAR*  file) /* ../dlls/kernelbase/path.c:1451 */
{
	TRACE("Enter PathCombineW\n");
	return pPathCombineW(dst, dir, file);
}

extern WINAPI void wine32a_kernelbase_PathCombineW(void);  /* ../dlls/kernelbase/path.c:1451 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCombineW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCombineW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathCommonPrefixA(char*  file1, char*  file2, char*  path) /* ../dlls/kernelbase/path.c:1572 */
{
	TRACE("Enter PathCommonPrefixA\n");
	return pPathCommonPrefixA(file1, file2, path);
}

extern WINAPI void wine32a_kernelbase_PathCommonPrefixA(void);  /* ../dlls/kernelbase/path.c:1572 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCommonPrefixA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCommonPrefixA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathCommonPrefixW(WCHAR*  file1, WCHAR*  file2, WCHAR*  path) /* ../dlls/kernelbase/path.c:1622 */
{
	TRACE("Enter PathCommonPrefixW\n");
	return pPathCommonPrefixW(file1, file2, path);
}

extern WINAPI void wine32a_kernelbase_PathCommonPrefixW(void);  /* ../dlls/kernelbase/path.c:1622 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCommonPrefixW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCommonPrefixW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCreateFromUrlA(char*  pszUrl, char*  pszPath, DWORD*  pcchPath, DWORD  dwReserved) /* ../dlls/kernelbase/path.c:2983 */
{
	TRACE("Enter PathCreateFromUrlA\n");
	return pPathCreateFromUrlA(pszUrl, pszPath, pcchPath, dwReserved);
}

extern WINAPI void wine32a_kernelbase_PathCreateFromUrlA(void);  /* ../dlls/kernelbase/path.c:2983 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCreateFromUrlA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCreateFromUrlA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCreateFromUrlAlloc(WCHAR*  url, WCHAR**  path, DWORD  reserved) /* ../dlls/kernelbase/path.c:3154 */
{
	TRACE("Enter PathCreateFromUrlAlloc\n");
	return pPathCreateFromUrlAlloc(url, path, reserved);
}

extern WINAPI void wine32a_kernelbase_PathCreateFromUrlAlloc(void);  /* ../dlls/kernelbase/path.c:3154 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCreateFromUrlAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCreateFromUrlAlloc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_PathCreateFromUrlW(WCHAR*  url, WCHAR*  path, DWORD*  pcchPath, DWORD  dwReserved) /* ../dlls/kernelbase/path.c:3016 */
{
	TRACE("Enter PathCreateFromUrlW\n");
	return pPathCreateFromUrlW(url, path, pcchPath, dwReserved);
}

extern WINAPI void wine32a_kernelbase_PathCreateFromUrlW(void);  /* ../dlls/kernelbase/path.c:3016 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathCreateFromUrlW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathCreateFromUrlW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathFileExistsA(char*  path) /* ../dlls/kernelbase/path.c:2583 */
{
	TRACE("Enter PathFileExistsA\n");
	return pPathFileExistsA(path);
}

extern WINAPI void wine32a_kernelbase_PathFileExistsA(void);  /* ../dlls/kernelbase/path.c:2583 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFileExistsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFileExistsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathFileExistsW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2600 */
{
	TRACE("Enter PathFileExistsW\n");
	return pPathFileExistsW(path);
}

extern WINAPI void wine32a_kernelbase_PathFileExistsW(void);  /* ../dlls/kernelbase/path.c:2600 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFileExistsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFileExistsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathFindExtensionA(char*  path) /* ../dlls/kernelbase/path.c:1255 */
{
	TRACE("Enter PathFindExtensionA\n");
	return pPathFindExtensionA(path);
}

extern WINAPI void wine32a_kernelbase_PathFindExtensionA(void);  /* ../dlls/kernelbase/path.c:1255 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindExtensionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindExtensionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathFindExtensionW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1276 */
{
	TRACE("Enter PathFindExtensionW\n");
	return pPathFindExtensionW(path);
}

extern WINAPI void wine32a_kernelbase_PathFindExtensionW(void);  /* ../dlls/kernelbase/path.c:1276 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindExtensionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindExtensionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathFindFileNameA(char*  path) /* ../dlls/kernelbase/path.c:1686 */
{
	TRACE("Enter PathFindFileNameA\n");
	return pPathFindFileNameA(path);
}

extern WINAPI void wine32a_kernelbase_PathFindFileNameA(void);  /* ../dlls/kernelbase/path.c:1686 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathFindFileNameW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1703 */
{
	TRACE("Enter PathFindFileNameW\n");
	return pPathFindFileNameW(path);
}

extern WINAPI void wine32a_kernelbase_PathFindFileNameW(void);  /* ../dlls/kernelbase/path.c:1703 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathFindNextComponentA(char*  path) /* ../dlls/kernelbase/path.c:2234 */
{
	TRACE("Enter PathFindNextComponentA\n");
	return pPathFindNextComponentA(path);
}

extern WINAPI void wine32a_kernelbase_PathFindNextComponentA(void);  /* ../dlls/kernelbase/path.c:2234 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindNextComponentA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindNextComponentA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathFindNextComponentW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2253 */
{
	TRACE("Enter PathFindNextComponentW\n");
	return pPathFindNextComponentW(path);
}

extern WINAPI void wine32a_kernelbase_PathFindNextComponentW(void);  /* ../dlls/kernelbase/path.c:2253 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathFindNextComponentW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathFindNextComponentW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathGetArgsA(char*  path) /* ../dlls/kernelbase/path.c:1720 */
{
	TRACE("Enter PathGetArgsA\n");
	return pPathGetArgsA(path);
}

extern WINAPI void wine32a_kernelbase_PathGetArgsA(void);  /* ../dlls/kernelbase/path.c:1720 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetArgsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetArgsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathGetArgsW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1742 */
{
	TRACE("Enter PathGetArgsW\n");
	return pPathGetArgsW(path);
}

extern WINAPI void wine32a_kernelbase_PathGetArgsW(void);  /* ../dlls/kernelbase/path.c:1742 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetArgsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetArgsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_PathGetCharTypeA(UCHAR  ch) /* ../dlls/kernelbase/path.c:1795 */
{
	TRACE("Enter PathGetCharTypeA\n");
	return pPathGetCharTypeA(ch);
}

extern WINAPI void wine32a_kernelbase_PathGetCharTypeA(void);  /* ../dlls/kernelbase/path.c:1795 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetCharTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetCharTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_PathGetCharTypeW(WCHAR  ch) /* ../dlls/kernelbase/path.c:1764 */
{
	TRACE("Enter PathGetCharTypeW\n");
	return pPathGetCharTypeW(ch);
}

extern WINAPI void wine32a_kernelbase_PathGetCharTypeW(void);  /* ../dlls/kernelbase/path.c:1764 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetCharTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetCharTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathGetDriveNumberA(char*  path) /* ../dlls/kernelbase/path.c:1800 */
{
	TRACE("Enter PathGetDriveNumberA\n");
	return pPathGetDriveNumberA(path);
}

extern WINAPI void wine32a_kernelbase_PathGetDriveNumberA(void);  /* ../dlls/kernelbase/path.c:1800 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetDriveNumberA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetDriveNumberA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathGetDriveNumberW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1812 */
{
	TRACE("Enter PathGetDriveNumberW\n");
	return pPathGetDriveNumberW(path);
}

extern WINAPI void wine32a_kernelbase_PathGetDriveNumberW(void);  /* ../dlls/kernelbase/path.c:1812 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathGetDriveNumberW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathGetDriveNumberW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsFileSpecA(char*  path) /* ../dlls/kernelbase/path.c:1832 */
{
	TRACE("Enter PathIsFileSpecA\n");
	return pPathIsFileSpecA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsFileSpecA(void);  /* ../dlls/kernelbase/path.c:1832 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsFileSpecA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsFileSpecA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsFileSpecW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1849 */
{
	TRACE("Enter PathIsFileSpecW\n");
	return pPathIsFileSpecW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsFileSpecW(void);  /* ../dlls/kernelbase/path.c:1849 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsFileSpecW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsFileSpecW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsLFNFileSpecA(char*  path) /* ../dlls/kernelbase/path.c:2062 */
{
	TRACE("Enter PathIsLFNFileSpecA\n");
	return pPathIsLFNFileSpecA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsLFNFileSpecA(void);  /* ../dlls/kernelbase/path.c:2062 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsLFNFileSpecA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsLFNFileSpecA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsLFNFileSpecW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2099 */
{
	TRACE("Enter PathIsLFNFileSpecW\n");
	return pPathIsLFNFileSpecW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsLFNFileSpecW(void);  /* ../dlls/kernelbase/path.c:2099 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsLFNFileSpecW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsLFNFileSpecW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsPrefixA(char*  prefix, char*  path) /* ../dlls/kernelbase/path.c:1672 */
{
	TRACE("Enter PathIsPrefixA\n");
	return pPathIsPrefixA(prefix, path);
}

extern WINAPI void wine32a_kernelbase_PathIsPrefixA(void);  /* ../dlls/kernelbase/path.c:1672 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsPrefixA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsPrefixA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsPrefixW(WCHAR*  prefix, WCHAR*  path) /* ../dlls/kernelbase/path.c:1679 */
{
	TRACE("Enter PathIsPrefixW\n");
	return pPathIsPrefixW(prefix, path);
}

extern WINAPI void wine32a_kernelbase_PathIsPrefixW(void);  /* ../dlls/kernelbase/path.c:1679 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsPrefixW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsPrefixW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsRelativeA(char*  path) /* ../dlls/kernelbase/path.c:955 */
{
	TRACE("Enter PathIsRelativeA\n");
	return pPathIsRelativeA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsRelativeA(void);  /* ../dlls/kernelbase/path.c:955 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsRelativeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsRelativeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsRelativeW(WCHAR*  path) /* ../dlls/kernelbase/path.c:965 */
{
	TRACE("Enter PathIsRelativeW\n");
	return pPathIsRelativeW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsRelativeW(void);  /* ../dlls/kernelbase/path.c:965 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsRelativeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsRelativeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsRootA(char*  path) /* ../dlls/kernelbase/path.c:1023 */
{
	TRACE("Enter PathIsRootA\n");
	return pPathIsRootA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsRootA(void);  /* ../dlls/kernelbase/path.c:1023 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsRootA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsRootA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsRootW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1061 */
{
	TRACE("Enter PathIsRootW\n");
	return pPathIsRootW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsRootW(void);  /* ../dlls/kernelbase/path.c:1061 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsRootW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsRootW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsSameRootA(char*  path1, char*  path2) /* ../dlls/kernelbase/path.c:2555 */
{
	TRACE("Enter PathIsSameRootA\n");
	return pPathIsSameRootA(path1, path2);
}

extern WINAPI void wine32a_kernelbase_PathIsSameRootA(void);  /* ../dlls/kernelbase/path.c:2555 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsSameRootA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsSameRootA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsSameRootW(WCHAR*  path1, WCHAR*  path2) /* ../dlls/kernelbase/path.c:2569 */
{
	TRACE("Enter PathIsSameRootW\n");
	return pPathIsSameRootW(path1, path2);
}

extern WINAPI void wine32a_kernelbase_PathIsSameRootW(void);  /* ../dlls/kernelbase/path.c:2569 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsSameRootW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsSameRootW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCA(char*  path) /* ../dlls/kernelbase/path.c:941 */
{
	TRACE("Enter PathIsUNCA\n");
	return pPathIsUNCA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCA(void);  /* ../dlls/kernelbase/path.c:941 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCEx(WCHAR*  path, WCHAR**  server) /* ../dlls/kernelbase/path.c:926 */
{
	TRACE("Enter PathIsUNCEx\n");
	return pPathIsUNCEx(path, server);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCEx(void);  /* ../dlls/kernelbase/path.c:926 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCServerA(char*  path) /* ../dlls/kernelbase/path.c:1866 */
{
	TRACE("Enter PathIsUNCServerA\n");
	return pPathIsUNCServerA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCServerA(void);  /* ../dlls/kernelbase/path.c:1866 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCServerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCServerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCServerShareA(char*  path) /* ../dlls/kernelbase/path.c:975 */
{
	TRACE("Enter PathIsUNCServerShareA\n");
	return pPathIsUNCServerShareA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCServerShareA(void);  /* ../dlls/kernelbase/path.c:975 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCServerShareA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCServerShareA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCServerShareW(WCHAR*  path) /* ../dlls/kernelbase/path.c:999 */
{
	TRACE("Enter PathIsUNCServerShareW\n");
	return pPathIsUNCServerShareW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCServerShareW(void);  /* ../dlls/kernelbase/path.c:999 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCServerShareW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCServerShareW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCServerW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1883 */
{
	TRACE("Enter PathIsUNCServerW\n");
	return pPathIsUNCServerW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCServerW(void);  /* ../dlls/kernelbase/path.c:1883 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCServerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCServerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsUNCW(WCHAR*  path) /* ../dlls/kernelbase/path.c:948 */
{
	TRACE("Enter PathIsUNCW\n");
	return pPathIsUNCW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsUNCW(void);  /* ../dlls/kernelbase/path.c:948 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsUNCW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsUNCW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsURLA(char*  path) /* ../dlls/kernelbase/path.c:3171 */
{
	TRACE("Enter PathIsURLA\n");
	return pPathIsURLA(path);
}

extern WINAPI void wine32a_kernelbase_PathIsURLA(void);  /* ../dlls/kernelbase/path.c:3171 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsURLA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsURLA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsURLW(WCHAR*  path) /* ../dlls/kernelbase/path.c:3187 */
{
	TRACE("Enter PathIsURLW\n");
	return pPathIsURLW(path);
}

extern WINAPI void wine32a_kernelbase_PathIsURLW(void);  /* ../dlls/kernelbase/path.c:3187 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsURLW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsURLW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsValidCharA(char  c, DWORD  class) /* ../dlls/kernelbase/path.c:2218 */
{
	TRACE("Enter PathIsValidCharA\n");
	return pPathIsValidCharA(c, class);
}

extern WINAPI void wine32a_kernelbase_PathIsValidCharA(void);  /* ../dlls/kernelbase/path.c:2218 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsValidCharA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsValidCharA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathIsValidCharW(WCHAR  c, DWORD  class) /* ../dlls/kernelbase/path.c:2226 */
{
	TRACE("Enter PathIsValidCharW\n");
	return pPathIsValidCharW(c, class);
}

extern WINAPI void wine32a_kernelbase_PathIsValidCharW(void);  /* ../dlls/kernelbase/path.c:2226 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathIsValidCharW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathIsValidCharW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathMatchSpecA(char*  path, char*  mask) /* ../dlls/kernelbase/path.c:2442 */
{
	TRACE("Enter PathMatchSpecA\n");
	return pPathMatchSpecA(path, mask);
}

extern WINAPI void wine32a_kernelbase_PathMatchSpecA(void);  /* ../dlls/kernelbase/path.c:2442 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathMatchSpecA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathMatchSpecA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathMatchSpecW(WCHAR*  path, WCHAR*  mask) /* ../dlls/kernelbase/path.c:2492 */
{
	TRACE("Enter PathMatchSpecW\n");
	return pPathMatchSpecW(path, mask);
}

extern WINAPI void wine32a_kernelbase_PathMatchSpecW(void);  /* ../dlls/kernelbase/path.c:2492 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathMatchSpecW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathMatchSpecW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathParseIconLocationA(char*  path) /* ../dlls/kernelbase/path.c:2616 */
{
	TRACE("Enter PathParseIconLocationA\n");
	return pPathParseIconLocationA(path);
}

extern WINAPI void wine32a_kernelbase_PathParseIconLocationA(void);  /* ../dlls/kernelbase/path.c:2616 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathParseIconLocationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathParseIconLocationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_PathParseIconLocationW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2637 */
{
	TRACE("Enter PathParseIconLocationW\n");
	return pPathParseIconLocationW(path);
}

extern WINAPI void wine32a_kernelbase_PathParseIconLocationW(void);  /* ../dlls/kernelbase/path.c:2637 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathParseIconLocationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathParseIconLocationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathQuoteSpacesA(char*  path) /* ../dlls/kernelbase/path.c:2519 */
{
	TRACE("Enter PathQuoteSpacesA\n");
	return pPathQuoteSpacesA(path);
}

extern WINAPI void wine32a_kernelbase_PathQuoteSpacesA(void);  /* ../dlls/kernelbase/path.c:2519 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathQuoteSpacesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathQuoteSpacesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathQuoteSpacesW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2537 */
{
	TRACE("Enter PathQuoteSpacesW\n");
	return pPathQuoteSpacesW(path);
}

extern WINAPI void wine32a_kernelbase_PathQuoteSpacesW(void);  /* ../dlls/kernelbase/path.c:2537 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathQuoteSpacesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathQuoteSpacesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathRelativePathToA(char*  path, char*  from, DWORD  attributes_from, char*  to, DWORD  attributes_to) /* ../dlls/kernelbase/path.c:2362 */
{
	TRACE("Enter PathRelativePathToA\n");
	return pPathRelativePathToA(path, from, attributes_from, to, attributes_to);
}

extern WINAPI void wine32a_kernelbase_PathRelativePathToA(void);  /* ../dlls/kernelbase/path.c:2362 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRelativePathToA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRelativePathToA") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_PathRelativePathToW(WCHAR*  path, WCHAR*  from, DWORD  attributes_from, WCHAR*  to, DWORD  attributes_to) /* ../dlls/kernelbase/path.c:2381 */
{
	TRACE("Enter PathRelativePathToW\n");
	return pPathRelativePathToW(path, from, attributes_from, to, attributes_to);
}

extern WINAPI void wine32a_kernelbase_PathRelativePathToW(void);  /* ../dlls/kernelbase/path.c:2381 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRelativePathToW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRelativePathToW") "\n"
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

extern WINAPI LPSTR wine32b_kernelbase_PathRemoveBackslashA(char*  path) /* ../dlls/kernelbase/path.c:2029 */
{
	TRACE("Enter PathRemoveBackslashA\n");
	return pPathRemoveBackslashA(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveBackslashA(void);  /* ../dlls/kernelbase/path.c:2029 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveBackslashA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveBackslashA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathRemoveBackslashW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2045 */
{
	TRACE("Enter PathRemoveBackslashW\n");
	return pPathRemoveBackslashW(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveBackslashW(void);  /* ../dlls/kernelbase/path.c:2045 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveBackslashW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveBackslashW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathRemoveBlanksA(char*  path) /* ../dlls/kernelbase/path.c:1893 */
{
	TRACE("Enter PathRemoveBlanksA\n");
	return pPathRemoveBlanksA(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveBlanksA(void);  /* ../dlls/kernelbase/path.c:1893 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveBlanksA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveBlanksA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathRemoveBlanksW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1917 */
{
	TRACE("Enter PathRemoveBlanksW\n");
	return pPathRemoveBlanksW(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveBlanksW(void);  /* ../dlls/kernelbase/path.c:1917 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveBlanksW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveBlanksW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathRemoveExtensionA(char*  path) /* ../dlls/kernelbase/path.c:1939 */
{
	TRACE("Enter PathRemoveExtensionA\n");
	return pPathRemoveExtensionA(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveExtensionA(void);  /* ../dlls/kernelbase/path.c:1939 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveExtensionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveExtensionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathRemoveExtensionW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1951 */
{
	TRACE("Enter PathRemoveExtensionW\n");
	return pPathRemoveExtensionW(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveExtensionW(void);  /* ../dlls/kernelbase/path.c:1951 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveExtensionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveExtensionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathRemoveFileSpecA(char*  path) /* ../dlls/kernelbase/path.c:1098 */
{
	TRACE("Enter PathRemoveFileSpecA\n");
	return pPathRemoveFileSpecA(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveFileSpecA(void);  /* ../dlls/kernelbase/path.c:1098 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveFileSpecA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveFileSpecA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathRemoveFileSpecW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1137 */
{
	TRACE("Enter PathRemoveFileSpecW\n");
	return pPathRemoveFileSpecW(path);
}

extern WINAPI void wine32a_kernelbase_PathRemoveFileSpecW(void);  /* ../dlls/kernelbase/path.c:1137 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRemoveFileSpecW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRemoveFileSpecW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathRenameExtensionA(char*  path, char*  ext) /* ../dlls/kernelbase/path.c:1963 */
{
	TRACE("Enter PathRenameExtensionA\n");
	return pPathRenameExtensionA(path, ext);
}

extern WINAPI void wine32a_kernelbase_PathRenameExtensionA(void);  /* ../dlls/kernelbase/path.c:1963 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRenameExtensionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRenameExtensionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathRenameExtensionW(WCHAR*  path, WCHAR*  ext) /* ../dlls/kernelbase/path.c:1978 */
{
	TRACE("Enter PathRenameExtensionW\n");
	return pPathRenameExtensionW(path, ext);
}

extern WINAPI void wine32a_kernelbase_PathRenameExtensionW(void);  /* ../dlls/kernelbase/path.c:1978 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathRenameExtensionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathRenameExtensionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathSearchAndQualifyA(char*  path, char*  buffer, UINT  length) /* ../dlls/kernelbase/path.c:2343 */
{
	TRACE("Enter PathSearchAndQualifyA\n");
	return pPathSearchAndQualifyA(path, buffer, length);
}

extern WINAPI void wine32a_kernelbase_PathSearchAndQualifyA(void);  /* ../dlls/kernelbase/path.c:2343 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathSearchAndQualifyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathSearchAndQualifyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathSearchAndQualifyW(WCHAR*  path, WCHAR*  buffer, UINT  length) /* ../dlls/kernelbase/path.c:2353 */
{
	TRACE("Enter PathSearchAndQualifyW\n");
	return pPathSearchAndQualifyW(path, buffer, length);
}

extern WINAPI void wine32a_kernelbase_PathSearchAndQualifyW(void);  /* ../dlls/kernelbase/path.c:2353 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathSearchAndQualifyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathSearchAndQualifyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_PathSkipRootA(char*  path) /* ../dlls/kernelbase/path.c:2272 */
{
	TRACE("Enter PathSkipRootA\n");
	return pPathSkipRootA(path);
}

extern WINAPI void wine32a_kernelbase_PathSkipRootA(void);  /* ../dlls/kernelbase/path.c:2272 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathSkipRootA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathSkipRootA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_PathSkipRootW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2298 */
{
	TRACE("Enter PathSkipRootW\n");
	return pPathSkipRootW(path);
}

extern WINAPI void wine32a_kernelbase_PathSkipRootW(void);  /* ../dlls/kernelbase/path.c:2298 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathSkipRootW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathSkipRootW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathStripPathA(char*  path) /* ../dlls/kernelbase/path.c:2321 */
{
	TRACE("Enter PathStripPathA\n");
	return pPathStripPathA(path);
}

extern WINAPI void wine32a_kernelbase_PathStripPathA(void);  /* ../dlls/kernelbase/path.c:2321 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathStripPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathStripPathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathStripPathW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2333 */
{
	TRACE("Enter PathStripPathW\n");
	return pPathStripPathW(path);
}

extern WINAPI void wine32a_kernelbase_PathStripPathW(void);  /* ../dlls/kernelbase/path.c:2333 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathStripPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathStripPathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathStripToRootA(char*  path) /* ../dlls/kernelbase/path.c:1176 */
{
	TRACE("Enter PathStripToRootA\n");
	return pPathStripToRootA(path);
}

extern WINAPI void wine32a_kernelbase_PathStripToRootA(void);  /* ../dlls/kernelbase/path.c:1176 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathStripToRootA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathStripToRootA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathStripToRootW(WCHAR*  path) /* ../dlls/kernelbase/path.c:1190 */
{
	TRACE("Enter PathStripToRootW\n");
	return pPathStripToRootW(path);
}

extern WINAPI void wine32a_kernelbase_PathStripToRootW(void);  /* ../dlls/kernelbase/path.c:1190 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathStripToRootW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathStripToRootW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathUnExpandEnvStringsA(char*  path, char*  buffer, UINT  buf_len) /* ../dlls/kernelbase/path.c:2658 */
{
	TRACE("Enter PathUnExpandEnvStringsA\n");
	return pPathUnExpandEnvStringsA(path, buffer, buf_len);
}

extern WINAPI void wine32a_kernelbase_PathUnExpandEnvStringsA(void);  /* ../dlls/kernelbase/path.c:2658 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathUnExpandEnvStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathUnExpandEnvStringsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PathUnExpandEnvStringsW(WCHAR*  path, WCHAR*  buffer, UINT  buf_len) /* ../dlls/kernelbase/path.c:2706 */
{
	TRACE("Enter PathUnExpandEnvStringsW\n");
	return pPathUnExpandEnvStringsW(path, buffer, buf_len);
}

extern WINAPI void wine32a_kernelbase_PathUnExpandEnvStringsW(void);  /* ../dlls/kernelbase/path.c:2706 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathUnExpandEnvStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathUnExpandEnvStringsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathUnquoteSpacesA(char*  path) /* ../dlls/kernelbase/path.c:1993 */
{
	TRACE("Enter PathUnquoteSpacesA\n");
	return pPathUnquoteSpacesA(path);
}

extern WINAPI void wine32a_kernelbase_PathUnquoteSpacesA(void);  /* ../dlls/kernelbase/path.c:1993 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathUnquoteSpacesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathUnquoteSpacesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_PathUnquoteSpacesW(WCHAR*  path) /* ../dlls/kernelbase/path.c:2011 */
{
	TRACE("Enter PathUnquoteSpacesW\n");
	return pPathUnquoteSpacesW(path);
}

extern WINAPI void wine32a_kernelbase_PathUnquoteSpacesW(void);  /* ../dlls/kernelbase/path.c:2011 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PathUnquoteSpacesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PathUnquoteSpacesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PeekNamedPipe(HANDLE  pipe, LPVOID  out_buffer, DWORD  size, LPDWORD  read_size, LPDWORD  avail, LPDWORD  message) /* ../dlls/kernelbase/sync.c:1219 */
{
	TRACE("Enter PeekNamedPipe\n");
	return pPeekNamedPipe(pipe, out_buffer, size, read_size, avail, message);
}

extern WINAPI void wine32a_kernelbase_PeekNamedPipe(void);  /* ../dlls/kernelbase/sync.c:1219 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PeekNamedPipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PeekNamedPipe") "\n"
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

extern WINAPI PPERF_COUNTERSET_INSTANCE wine32b_kernelbase_PerfCreateInstance(HANDLE  handle, LPCGUID  guid, WCHAR*  name, ULONG  id) /* ../dlls/kernelbase/main.c:100 */
{
	TRACE("Enter PerfCreateInstance\n");
	return pPerfCreateInstance(handle, guid, name, id);
}

extern WINAPI void wine32a_kernelbase_PerfCreateInstance(void);  /* ../dlls/kernelbase/main.c:100 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfCreateInstance,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfCreateInstance") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfDeleteInstance(HANDLE  provider, PPERF_COUNTERSET_INSTANCE  block) /* ../dlls/kernelbase/main.c:110 */
{
	TRACE("Enter PerfDeleteInstance\n");
	return pPerfDeleteInstance(provider, block);
}

extern WINAPI void wine32a_kernelbase_PerfDeleteInstance(void);  /* ../dlls/kernelbase/main.c:110 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfDeleteInstance,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfDeleteInstance") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfSetCounterRefValue(HANDLE  provider, PPERF_COUNTERSET_INSTANCE  instance, ULONG  counterid, void*  address) /* ../dlls/kernelbase/main.c:128 */
{
	TRACE("Enter PerfSetCounterRefValue\n");
	return pPerfSetCounterRefValue(provider, instance, counterid, address);
}

extern WINAPI void wine32a_kernelbase_PerfSetCounterRefValue(void);  /* ../dlls/kernelbase/main.c:128 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfSetCounterRefValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfSetCounterRefValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfSetCounterSetInfo(HANDLE  handle, PPERF_COUNTERSET_INFO  template, ULONG  size) /* ../dlls/kernelbase/main.c:119 */
{
	TRACE("Enter PerfSetCounterSetInfo\n");
	return pPerfSetCounterSetInfo(handle, template, size);
}

extern WINAPI void wine32a_kernelbase_PerfSetCounterSetInfo(void);  /* ../dlls/kernelbase/main.c:119 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfSetCounterSetInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfSetCounterSetInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfStartProvider(GUID*  guid, PERFLIBREQUEST  callback, HANDLE*  provider) /* ../dlls/kernelbase/main.c:138 */
{
	TRACE("Enter PerfStartProvider\n");
	return pPerfStartProvider(guid, callback, provider);
}

extern WINAPI void wine32a_kernelbase_PerfStartProvider(void);  /* ../dlls/kernelbase/main.c:138 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfStartProvider,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfStartProvider") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfStartProviderEx(GUID*  guid, PPERF_PROVIDER_CONTEXT  context, HANDLE*  provider) /* ../dlls/kernelbase/main.c:147 */
{
	TRACE("Enter PerfStartProviderEx\n");
	return pPerfStartProviderEx(guid, context, provider);
}

extern WINAPI void wine32a_kernelbase_PerfStartProviderEx(void);  /* ../dlls/kernelbase/main.c:147 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfStartProviderEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfStartProviderEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_kernelbase_PerfStopProvider(HANDLE  handle) /* ../dlls/kernelbase/main.c:156 */
{
	TRACE("Enter PerfStopProvider\n");
	return pPerfStopProvider(handle);
}

extern WINAPI void wine32a_kernelbase_PerfStopProvider(void);  /* ../dlls/kernelbase/main.c:156 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PerfStopProvider,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PerfStopProvider") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PostQueuedCompletionStatus(HANDLE  port, DWORD  count, ULONG_PTR  key, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/sync.c:1019 */
{
	TRACE("Enter PostQueuedCompletionStatus\n");
	return pPostQueuedCompletionStatus(port, count, key, overlapped);
}

extern WINAPI void wine32a_kernelbase_PostQueuedCompletionStatus(void);  /* ../dlls/kernelbase/sync.c:1019 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PostQueuedCompletionStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PostQueuedCompletionStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PrivilegeCheck(HANDLE  token, PPRIVILEGE_SET  privs, LPBOOL  result) /* ../dlls/kernelbase/security.c:780 */
{
	TRACE("Enter PrivilegeCheck\n");
	return pPrivilegeCheck(token, privs, result);
}

extern WINAPI void wine32a_kernelbase_PrivilegeCheck(void);  /* ../dlls/kernelbase/security.c:780 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PrivilegeCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PrivilegeCheck") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_PrivilegedServiceAuditAlarmW(LPCWSTR  subsystem, LPCWSTR  service, HANDLE  token, PPRIVILEGE_SET  privs, BOOL  granted) /* ../dlls/kernelbase/security.c:1451 */
{
	TRACE("Enter PrivilegedServiceAuditAlarmW\n");
	return pPrivilegedServiceAuditAlarmW(subsystem, service, token, privs, granted);
}

extern WINAPI void wine32a_kernelbase_PrivilegedServiceAuditAlarmW(void);  /* ../dlls/kernelbase/security.c:1451 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PrivilegedServiceAuditAlarmW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PrivilegedServiceAuditAlarmW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_PulseEvent(HANDLE  handle) /* ../dlls/kernelbase/sync.c:409 */
{
	TRACE("Enter PulseEvent\n");
	return pPulseEvent(handle);
}

extern WINAPI void wine32a_kernelbase_PulseEvent(void);  /* ../dlls/kernelbase/sync.c:409 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_PulseEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_PulseEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_QISearch(void*  base, QITAB*  table, IID*  riid, void**  obj) /* ../dlls/kernelbase/main.c:209 */
{
	TRACE("Enter QISearch\n");
	return pQISearch(base, table, riid, obj);
}

extern WINAPI void wine32a_kernelbase_QISearch(void);  /* ../dlls/kernelbase/main.c:209 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QISearch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QISearch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_QueryActCtxSettingsW(DWORD  flags, HANDLE  ctx, WCHAR*  ns, WCHAR*  settings, WCHAR*  buffer, SIZE_T  size, SIZE_T*  written) /* ../dlls/kernelbase/loader.c:844 */
{
	TRACE("Enter QueryActCtxSettingsW\n");
	return pQueryActCtxSettingsW(flags, ctx, ns, settings, buffer, size, written);
}

extern WINAPI void wine32a_kernelbase_QueryActCtxSettingsW(void);  /* ../dlls/kernelbase/loader.c:844 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QueryActCtxSettingsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QueryActCtxSettingsW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_QueryActCtxW(DWORD  flags, HANDLE  context, PVOID  inst, ULONG  class, PVOID  buffer, SIZE_T  size, SIZE_T*  written) /* ../dlls/kernelbase/loader.c:856 */
{
	TRACE("Enter QueryActCtxW\n");
	return pQueryActCtxW(flags, context, inst, class, buffer, size, written);
}

extern WINAPI void wine32a_kernelbase_QueryActCtxW(void);  /* ../dlls/kernelbase/loader.c:856 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QueryActCtxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QueryActCtxW") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_QueueUserAPC(PAPCFUNC  func, HANDLE  thread, ULONG_PTR  data) /* ../dlls/kernelbase/thread.c:360 */
{
	TRACE("Enter QueueUserAPC\n");
	return pQueueUserAPC(func, thread, data);
}

extern WINAPI void wine32a_kernelbase_QueueUserAPC(void);  /* ../dlls/kernelbase/thread.c:360 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QueueUserAPC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QueueUserAPC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_QueueUserWorkItem(LPTHREAD_START_ROUTINE  func, PVOID  context, ULONG  flags) /* ../dlls/kernelbase/thread.c:1147 */
{
	TRACE("Enter QueueUserWorkItem\n");
	return pQueueUserWorkItem(func, context, flags);
}

extern WINAPI void wine32a_kernelbase_QueueUserWorkItem(void);  /* ../dlls/kernelbase/thread.c:1147 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QueueUserWorkItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QueueUserWorkItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_QuirkIsEnabled(void*  arg) /* ../dlls/kernelbase/main.c:165 */
{
	TRACE("Enter QuirkIsEnabled\n");
	return pQuirkIsEnabled(arg);
}

extern WINAPI void wine32a_kernelbase_QuirkIsEnabled(void);  /* ../dlls/kernelbase/main.c:165 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QuirkIsEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QuirkIsEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_QuirkIsEnabled3(void*  unk1, void*  unk2) /* ../dlls/kernelbase/main.c:174 */
{
	TRACE("Enter QuirkIsEnabled3\n");
	return pQuirkIsEnabled3(unk1, unk2);
}

extern WINAPI void wine32a_kernelbase_QuirkIsEnabled3(void);  /* ../dlls/kernelbase/main.c:174 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_QuirkIsEnabled3,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_QuirkIsEnabled3") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_ReOpenFile(HANDLE  handle, DWORD  access, DWORD  sharing, DWORD  flags) /* ../dlls/kernelbase/file.c:1175 */
{
	TRACE("Enter ReOpenFile\n");
	return pReOpenFile(handle, access, sharing, flags);
}

extern WINAPI void wine32a_kernelbase_ReOpenFile(void);  /* ../dlls/kernelbase/file.c:1175 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReOpenFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReOpenFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ReadFile(HANDLE  file, LPVOID  buffer, DWORD  count, LPDWORD  result, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1185 */
{
	TRACE("Enter ReadFile\n");
	return pReadFile(file, buffer, count, result, overlapped);
}

extern WINAPI void wine32a_kernelbase_ReadFile(void);  /* ../dlls/kernelbase/file.c:1185 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReadFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReadFile") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_ReadFileEx(HANDLE  file, LPVOID  buffer, DWORD  count, LPOVERLAPPED  overlapped, LPOVERLAPPED_COMPLETION_ROUTINE  completion) /* ../dlls/kernelbase/file.c:1261 */
{
	TRACE("Enter ReadFileEx\n");
	return pReadFileEx(file, buffer, count, overlapped, completion);
}

extern WINAPI void wine32a_kernelbase_ReadFileEx(void);  /* ../dlls/kernelbase/file.c:1261 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReadFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReadFileEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_ReadFileScatter(HANDLE  file, FILE_SEGMENT_ELEMENT*  segments, DWORD  count, LPDWORD  reserved, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1291 */
{
	TRACE("Enter ReadFileScatter\n");
	return pReadFileScatter(file, segments, count, reserved, overlapped);
}

extern WINAPI void wine32a_kernelbase_ReadFileScatter(void);  /* ../dlls/kernelbase/file.c:1291 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReadFileScatter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReadFileScatter") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegCloseKey(HKEY  hkey) /* ../dlls/kernelbase/registry.c:992 */
{
	TRACE("Enter RegCloseKey\n");
	return pRegCloseKey(hkey);
}

extern WINAPI void wine32a_kernelbase_RegCloseKey(void);  /* ../dlls/kernelbase/registry.c:992 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegCloseKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegCloseKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegCopyTreeW(HKEY  hsrc, WCHAR*  subkey, HKEY  hdst) /* ../dlls/kernelbase/registry.c:2966 */
{
	TRACE("Enter RegCopyTreeW\n");
	return pRegCopyTreeW(hsrc, subkey, hdst);
}

extern WINAPI void wine32a_kernelbase_RegCopyTreeW(void);  /* ../dlls/kernelbase/registry.c:2966 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegCopyTreeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegCopyTreeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegCreateKeyExA(HKEY  hkey, LPCSTR  name, DWORD  reserved, LPSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos) /* ../dlls/kernelbase/registry.c:451 */
{
	TRACE("Enter RegCreateKeyExA\n");
	return pRegCreateKeyExA(hkey, name, reserved, class, options, access, sa, retkey, dispos);
}

extern WINAPI void wine32a_kernelbase_RegCreateKeyExA(void);  /* ../dlls/kernelbase/registry.c:451 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegCreateKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegCreateKeyExA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegCreateKeyExW(HKEY  hkey, LPCWSTR  name, DWORD  reserved, LPWSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos) /* ../dlls/kernelbase/registry.c:404 */
{
	TRACE("Enter RegCreateKeyExW\n");
	return pRegCreateKeyExW(hkey, name, reserved, class, options, access, sa, retkey, dispos);
}

extern WINAPI void wine32a_kernelbase_RegCreateKeyExW(void);  /* ../dlls/kernelbase/registry.c:404 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegCreateKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegCreateKeyExW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteKeyExA(HKEY  hkey, LPCSTR  name, REGSAM  access, DWORD  reserved) /* ../dlls/kernelbase/registry.c:1026 */
{
	TRACE("Enter RegDeleteKeyExA\n");
	return pRegDeleteKeyExA(hkey, name, access, reserved);
}

extern WINAPI void wine32a_kernelbase_RegDeleteKeyExA(void);  /* ../dlls/kernelbase/registry.c:1026 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteKeyExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteKeyExW(HKEY  hkey, LPCWSTR  name, REGSAM  access, DWORD  reserved) /* ../dlls/kernelbase/registry.c:1003 */
{
	TRACE("Enter RegDeleteKeyExW\n");
	return pRegDeleteKeyExW(hkey, name, access, reserved);
}

extern WINAPI void wine32a_kernelbase_RegDeleteKeyExW(void);  /* ../dlls/kernelbase/registry.c:1003 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteKeyExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteKeyValueA(HKEY  hkey, LPCSTR  subkey, LPCSTR  name) /* ../dlls/kernelbase/registry.c:2159 */
{
	TRACE("Enter RegDeleteKeyValueA\n");
	return pRegDeleteKeyValueA(hkey, subkey, name);
}

extern WINAPI void wine32a_kernelbase_RegDeleteKeyValueA(void);  /* ../dlls/kernelbase/registry.c:2159 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteKeyValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteKeyValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteKeyValueW(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  name) /* ../dlls/kernelbase/registry.c:2135 */
{
	TRACE("Enter RegDeleteKeyValueW\n");
	return pRegDeleteKeyValueW(hkey, subkey, name);
}

extern WINAPI void wine32a_kernelbase_RegDeleteKeyValueW(void);  /* ../dlls/kernelbase/registry.c:2135 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteKeyValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteKeyValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteTreeA(HKEY  hkey, char*  subkey) /* ../dlls/kernelbase/registry.c:2949 */
{
	TRACE("Enter RegDeleteTreeA\n");
	return pRegDeleteTreeA(hkey, subkey);
}

extern WINAPI void wine32a_kernelbase_RegDeleteTreeA(void);  /* ../dlls/kernelbase/registry.c:2949 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteTreeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteTreeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteTreeW(HKEY  hkey, WCHAR*  subkey) /* ../dlls/kernelbase/registry.c:2879 */
{
	TRACE("Enter RegDeleteTreeW\n");
	return pRegDeleteTreeW(hkey, subkey);
}

extern WINAPI void wine32a_kernelbase_RegDeleteTreeW(void);  /* ../dlls/kernelbase/registry.c:2879 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteTreeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteTreeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteValueA(HKEY  hkey, LPCSTR  name) /* ../dlls/kernelbase/registry.c:2127 */
{
	TRACE("Enter RegDeleteValueA\n");
	return pRegDeleteValueA(hkey, name);
}

extern WINAPI void wine32a_kernelbase_RegDeleteValueA(void);  /* ../dlls/kernelbase/registry.c:2127 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegDeleteValueW(HKEY  hkey, LPCWSTR  name) /* ../dlls/kernelbase/registry.c:2109 */
{
	TRACE("Enter RegDeleteValueW\n");
	return pRegDeleteValueW(hkey, name);
}

extern WINAPI void wine32a_kernelbase_RegDeleteValueW(void);  /* ../dlls/kernelbase/registry.c:2109 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegDeleteValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegDeleteValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegEnumKeyExA(HKEY  hkey, DWORD  index, LPSTR  name, LPDWORD  name_len, LPDWORD  reserved, LPSTR  class, LPDWORD  class_len, FILETIME*  ft) /* ../dlls/kernelbase/registry.c:730 */
{
	TRACE("Enter RegEnumKeyExA\n");
	return pRegEnumKeyExA(hkey, index, name, name_len, reserved, class, class_len, ft);
}

extern WINAPI void wine32a_kernelbase_RegEnumKeyExA(void);  /* ../dlls/kernelbase/registry.c:730 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegEnumKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegEnumKeyExA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegEnumKeyExW(HKEY  hkey, DWORD  index, LPWSTR  name, LPDWORD  name_len, LPDWORD  reserved, LPWSTR  class, LPDWORD  class_len, FILETIME*  ft) /* ../dlls/kernelbase/registry.c:666 */
{
	TRACE("Enter RegEnumKeyExW\n");
	return pRegEnumKeyExW(hkey, index, name, name_len, reserved, class, class_len, ft);
}

extern WINAPI void wine32a_kernelbase_RegEnumKeyExW(void);  /* ../dlls/kernelbase/registry.c:666 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegEnumKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegEnumKeyExW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegEnumValueA(HKEY  hkey, DWORD  index, LPSTR  value, LPDWORD  val_count, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count) /* ../dlls/kernelbase/registry.c:2009 */
{
	TRACE("Enter RegEnumValueA\n");
	return pRegEnumValueA(hkey, index, value, val_count, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegEnumValueA(void);  /* ../dlls/kernelbase/registry.c:2009 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegEnumValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegEnumValueA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegEnumValueW(HKEY  hkey, DWORD  index, LPWSTR  value, LPDWORD  val_count, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count) /* ../dlls/kernelbase/registry.c:1932 */
{
	TRACE("Enter RegEnumValueW\n");
	return pRegEnumValueW(hkey, index, value, val_count, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegEnumValueW(void);  /* ../dlls/kernelbase/registry.c:1932 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegEnumValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegEnumValueW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegFlushKey(HKEY  hkey) /* ../dlls/kernelbase/registry.c:2510 */
{
	TRACE("Enter RegFlushKey\n");
	return pRegFlushKey(hkey);
}

extern WINAPI void wine32a_kernelbase_RegFlushKey(void);  /* ../dlls/kernelbase/registry.c:2510 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegFlushKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegFlushKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegGetKeySecurity(HKEY  hkey, SECURITY_INFORMATION  SecurityInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, LPDWORD  lpcbSecurityDescriptor) /* ../dlls/kernelbase/registry.c:2483 */
{
	TRACE("Enter RegGetKeySecurity\n");
	return pRegGetKeySecurity(hkey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor);
}

extern WINAPI void wine32a_kernelbase_RegGetKeySecurity(void);  /* ../dlls/kernelbase/registry.c:2483 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegGetKeySecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegGetKeySecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegGetValueA(HKEY  hKey, LPCSTR  pszSubKey, LPCSTR  pszValue, DWORD  dwFlags, LPDWORD  pdwType, PVOID  pvData, LPDWORD  pcbData) /* ../dlls/kernelbase/registry.c:1822 */
{
	TRACE("Enter RegGetValueA\n");
	return pRegGetValueA(hKey, pszSubKey, pszValue, dwFlags, pdwType, pvData, pcbData);
}

extern WINAPI void wine32a_kernelbase_RegGetValueA(void);  /* ../dlls/kernelbase/registry.c:1822 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegGetValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegGetValueA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegGetValueW(HKEY  hKey, LPCWSTR  pszSubKey, LPCWSTR  pszValue, DWORD  dwFlags, LPDWORD  pdwType, PVOID  pvData, LPDWORD  pcbData) /* ../dlls/kernelbase/registry.c:1726 */
{
	TRACE("Enter RegGetValueW\n");
	return pRegGetValueW(hKey, pszSubKey, pszValue, dwFlags, pdwType, pvData, pcbData);
}

extern WINAPI void wine32a_kernelbase_RegGetValueW(void);  /* ../dlls/kernelbase/registry.c:1726 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegGetValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegGetValueW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadAppKeyA(char*  file, HKEY*  result, REGSAM  sam, DWORD  options, DWORD  reserved) /* ../dlls/kernelbase/registry.c:3043 */
{
	TRACE("Enter RegLoadAppKeyA\n");
	return pRegLoadAppKeyA(file, result, sam, options, reserved);
}

extern WINAPI void wine32a_kernelbase_RegLoadAppKeyA(void);  /* ../dlls/kernelbase/registry.c:3043 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadAppKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadAppKeyA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadAppKeyW(WCHAR*  file, HKEY*  result, REGSAM  sam, DWORD  options, DWORD  reserved) /* ../dlls/kernelbase/registry.c:3058 */
{
	TRACE("Enter RegLoadAppKeyW\n");
	return pRegLoadAppKeyW(file, result, sam, options, reserved);
}

extern WINAPI void wine32a_kernelbase_RegLoadAppKeyW(void);  /* ../dlls/kernelbase/registry.c:3058 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadAppKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadAppKeyW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadKeyA(HKEY  hkey, LPCSTR  subkey, LPCSTR  filename) /* ../dlls/kernelbase/registry.c:2237 */
{
	TRACE("Enter RegLoadKeyA\n");
	return pRegLoadKeyA(hkey, subkey, filename);
}

extern WINAPI void wine32a_kernelbase_RegLoadKeyA(void);  /* ../dlls/kernelbase/registry.c:2237 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadKeyW(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  filename) /* ../dlls/kernelbase/registry.c:2202 */
{
	TRACE("Enter RegLoadKeyW\n");
	return pRegLoadKeyW(hkey, subkey, filename);
}

extern WINAPI void wine32a_kernelbase_RegLoadKeyW(void);  /* ../dlls/kernelbase/registry.c:2202 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadMUIStringA(HKEY  hKey, LPCSTR  pszValue, LPSTR  pszBuffer, DWORD  cbBuffer, LPDWORD  pcbData, DWORD  dwFlags, LPCSTR  pszBaseDir) /* ../dlls/kernelbase/registry.c:2868 */
{
	TRACE("Enter RegLoadMUIStringA\n");
	return pRegLoadMUIStringA(hKey, pszValue, pszBuffer, cbBuffer, pcbData, dwFlags, pszBaseDir);
}

extern WINAPI void wine32a_kernelbase_RegLoadMUIStringA(void);  /* ../dlls/kernelbase/registry.c:2868 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadMUIStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadMUIStringA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegLoadMUIStringW(HKEY  hKey, LPCWSTR  pwszValue, LPWSTR  pwszBuffer, DWORD  cbBuffer, LPDWORD  pcbData, DWORD  dwFlags, LPCWSTR  pwszBaseDir) /* ../dlls/kernelbase/registry.c:2768 */
{
	TRACE("Enter RegLoadMUIStringW\n");
	return pRegLoadMUIStringW(hKey, pwszValue, pwszBuffer, cbBuffer, pcbData, dwFlags, pwszBaseDir);
}

extern WINAPI void wine32a_kernelbase_RegLoadMUIStringW(void);  /* ../dlls/kernelbase/registry.c:2768 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegLoadMUIStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegLoadMUIStringW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegNotifyChangeKeyValue(HKEY  hkey, BOOL  fWatchSubTree, DWORD  fdwNotifyFilter, HANDLE  hEvent, BOOL  fAsync) /* ../dlls/kernelbase/registry.c:2535 */
{
	TRACE("Enter RegNotifyChangeKeyValue\n");
	return pRegNotifyChangeKeyValue(hkey, fWatchSubTree, fdwNotifyFilter, hEvent, fAsync);
}

extern WINAPI void wine32a_kernelbase_RegNotifyChangeKeyValue(void);  /* ../dlls/kernelbase/registry.c:2535 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegNotifyChangeKeyValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegNotifyChangeKeyValue") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegOpenCurrentUser(REGSAM  access, PHKEY  retkey) /* ../dlls/kernelbase/registry.c:606 */
{
	TRACE("Enter RegOpenCurrentUser\n");
	return pRegOpenCurrentUser(access, retkey);
}

extern WINAPI void wine32a_kernelbase_RegOpenCurrentUser(void);  /* ../dlls/kernelbase/registry.c:606 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegOpenCurrentUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegOpenCurrentUser") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegOpenKeyExA(HKEY  hkey, LPCSTR  name, DWORD  options, REGSAM  access, PHKEY  retkey) /* ../dlls/kernelbase/registry.c:546 */
{
	TRACE("Enter RegOpenKeyExA\n");
	return pRegOpenKeyExA(hkey, name, options, access, retkey);
}

extern WINAPI void wine32a_kernelbase_RegOpenKeyExA(void);  /* ../dlls/kernelbase/registry.c:546 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegOpenKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegOpenKeyExA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegOpenKeyExW(HKEY  hkey, LPCWSTR  name, DWORD  options, REGSAM  access, PHKEY  retkey) /* ../dlls/kernelbase/registry.c:496 */
{
	TRACE("Enter RegOpenKeyExW\n");
	return pRegOpenKeyExW(hkey, name, options, access, retkey);
}

extern WINAPI void wine32a_kernelbase_RegOpenKeyExW(void);  /* ../dlls/kernelbase/registry.c:496 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegOpenKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegOpenKeyExW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegOpenUserClassesRoot(HANDLE  hToken, DWORD  dwOptions, REGSAM  samDesired, PHKEY  phkResult) /* ../dlls/kernelbase/registry.c:2578 */
{
	TRACE("Enter RegOpenUserClassesRoot\n");
	return pRegOpenUserClassesRoot(hToken, dwOptions, samDesired, phkResult);
}

extern WINAPI void wine32a_kernelbase_RegOpenUserClassesRoot(void);  /* ../dlls/kernelbase/registry.c:2578 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegOpenUserClassesRoot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegOpenUserClassesRoot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegQueryInfoKeyA(HKEY  hkey, LPSTR  class, LPDWORD  class_len, LPDWORD  reserved, LPDWORD  subkeys, LPDWORD  max_subkey, LPDWORD  max_class, LPDWORD  values, LPDWORD  max_value, LPDWORD  max_data, LPDWORD  security, FILETIME*  modif) /* ../dlls/kernelbase/registry.c:912 */
{
	TRACE("Enter RegQueryInfoKeyA\n");
	return pRegQueryInfoKeyA(hkey, class, class_len, reserved, subkeys, max_subkey, max_class, values, max_value, max_data, security, modif);
}

extern WINAPI void wine32a_kernelbase_RegQueryInfoKeyA(void);  /* ../dlls/kernelbase/registry.c:912 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegQueryInfoKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegQueryInfoKeyA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegQueryInfoKeyW(HKEY  hkey, LPWSTR  class, LPDWORD  class_len, LPDWORD  reserved, LPDWORD  subkeys, LPDWORD  max_subkey, LPDWORD  max_class, LPDWORD  values, LPDWORD  max_value, LPDWORD  max_data, LPDWORD  security, FILETIME*  modif) /* ../dlls/kernelbase/registry.c:822 */
{
	TRACE("Enter RegQueryInfoKeyW\n");
	return pRegQueryInfoKeyW(hkey, class, class_len, reserved, subkeys, max_subkey, max_class, values, max_value, max_data, security, modif);
}

extern WINAPI void wine32a_kernelbase_RegQueryInfoKeyW(void);  /* ../dlls/kernelbase/registry.c:822 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegQueryInfoKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegQueryInfoKeyW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegQueryValueExA(HKEY  hkey, LPCSTR  name, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count) /* ../dlls/kernelbase/registry.c:1556 */
{
	TRACE("Enter RegQueryValueExA\n");
	return pRegQueryValueExA(hkey, name, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegQueryValueExA(void);  /* ../dlls/kernelbase/registry.c:1556 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegQueryValueExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegQueryValueExA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegQueryValueExW(HKEY  hkey, LPCWSTR  name, LPDWORD  reserved, LPDWORD  type, LPBYTE  data, LPDWORD  count) /* ../dlls/kernelbase/registry.c:1462 */
{
	TRACE("Enter RegQueryValueExW\n");
	return pRegQueryValueExW(hkey, name, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegQueryValueExW(void);  /* ../dlls/kernelbase/registry.c:1462 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegQueryValueExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegQueryValueExW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegRestoreKeyA(HKEY  hkey, LPCSTR  lpFile, DWORD  dwFlags) /* ../dlls/kernelbase/registry.c:2366 */
{
	TRACE("Enter RegRestoreKeyA\n");
	return pRegRestoreKeyA(hkey, lpFile, dwFlags);
}

extern WINAPI void wine32a_kernelbase_RegRestoreKeyA(void);  /* ../dlls/kernelbase/registry.c:2366 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegRestoreKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegRestoreKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegRestoreKeyW(HKEY  hkey, LPCWSTR  lpFile, DWORD  dwFlags) /* ../dlls/kernelbase/registry.c:2345 */
{
	TRACE("Enter RegRestoreKeyW\n");
	return pRegRestoreKeyW(hkey, lpFile, dwFlags);
}

extern WINAPI void wine32a_kernelbase_RegRestoreKeyW(void);  /* ../dlls/kernelbase/registry.c:2345 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegRestoreKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegRestoreKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegSaveKeyExA(HKEY  hkey, LPCSTR  file, SECURITY_ATTRIBUTES*  sa, DWORD  flags) /* ../dlls/kernelbase/registry.c:2318 */
{
	TRACE("Enter RegSaveKeyExA\n");
	return pRegSaveKeyExA(hkey, file, sa, flags);
}

extern WINAPI void wine32a_kernelbase_RegSaveKeyExA(void);  /* ../dlls/kernelbase/registry.c:2318 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSaveKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSaveKeyExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegSaveKeyExW(HKEY  hkey, LPCWSTR  file, SECURITY_ATTRIBUTES*  sa, DWORD  flags) /* ../dlls/kernelbase/registry.c:2264 */
{
	TRACE("Enter RegSaveKeyExW\n");
	return pRegSaveKeyExW(hkey, file, sa, flags);
}

extern WINAPI void wine32a_kernelbase_RegSaveKeyExW(void);  /* ../dlls/kernelbase/registry.c:2264 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSaveKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSaveKeyExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegSetKeySecurity(HKEY  hkey, SECURITY_INFORMATION  SecurityInfo, PSECURITY_DESCRIPTOR  pSecurityDesc) /* ../dlls/kernelbase/registry.c:2445 */
{
	TRACE("Enter RegSetKeySecurity\n");
	return pRegSetKeySecurity(hkey, SecurityInfo, pSecurityDesc);
}

extern WINAPI void wine32a_kernelbase_RegSetKeySecurity(void);  /* ../dlls/kernelbase/registry.c:2445 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSetKeySecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSetKeySecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegSetKeyValueA(HKEY  hkey, LPCSTR  subkey, LPCSTR  name, DWORD  type, void*  data, DWORD  len) /* ../dlls/kernelbase/registry.c:1174 */
{
	TRACE("Enter RegSetKeyValueA\n");
	return pRegSetKeyValueA(hkey, subkey, name, type, data, len);
}

extern WINAPI void wine32a_kernelbase_RegSetKeyValueA(void);  /* ../dlls/kernelbase/registry.c:1174 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSetKeyValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSetKeyValueA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegSetKeyValueW(HKEY  hkey, LPCWSTR  subkey, LPCWSTR  name, DWORD  type, void*  data, DWORD  len) /* ../dlls/kernelbase/registry.c:1152 */
{
	TRACE("Enter RegSetKeyValueW\n");
	return pRegSetKeyValueW(hkey, subkey, name, type, data, len);
}

extern WINAPI void wine32a_kernelbase_RegSetKeyValueW(void);  /* ../dlls/kernelbase/registry.c:1152 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSetKeyValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSetKeyValueW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegSetValueExA(HKEY  hkey, LPCSTR  name, DWORD  reserved, DWORD  type, BYTE*  data, DWORD  count) /* ../dlls/kernelbase/registry.c:1104 */
{
	TRACE("Enter RegSetValueExA\n");
	return pRegSetValueExA(hkey, name, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegSetValueExA(void);  /* ../dlls/kernelbase/registry.c:1104 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSetValueExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSetValueExA") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegSetValueExW(HKEY  hkey, LPCWSTR  name, DWORD  reserved, DWORD  type, BYTE*  data, DWORD  count) /* ../dlls/kernelbase/registry.c:1072 */
{
	TRACE("Enter RegSetValueExW\n");
	return pRegSetValueExW(hkey, name, reserved, type, data, count);
}

extern WINAPI void wine32a_kernelbase_RegSetValueExW(void);  /* ../dlls/kernelbase/registry.c:1072 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegSetValueExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegSetValueExW") "\n"
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

extern WINAPI LSTATUS wine32b_kernelbase_RegUnLoadKeyA(HKEY  hkey, LPCSTR  lpSubKey) /* ../dlls/kernelbase/registry.c:2419 */
{
	TRACE("Enter RegUnLoadKeyA\n");
	return pRegUnLoadKeyA(hkey, lpSubKey);
}

extern WINAPI void wine32a_kernelbase_RegUnLoadKeyA(void);  /* ../dlls/kernelbase/registry.c:2419 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegUnLoadKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegUnLoadKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_kernelbase_RegUnLoadKeyW(HKEY  hkey, LPCWSTR  lpSubKey) /* ../dlls/kernelbase/registry.c:2391 */
{
	TRACE("Enter RegUnLoadKeyW\n");
	return pRegUnLoadKeyW(hkey, lpSubKey);
}

extern WINAPI void wine32a_kernelbase_RegUnLoadKeyW(void);  /* ../dlls/kernelbase/registry.c:2391 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegUnLoadKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegUnLoadKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernelbase_RegisterWaitForSingleObjectEx(HANDLE  handle, WAITORTIMERCALLBACK  callback, PVOID  context, ULONG  timeout, ULONG  flags) /* ../dlls/kernelbase/sync.c:148 */
{
	TRACE("Enter RegisterWaitForSingleObjectEx\n");
	return pRegisterWaitForSingleObjectEx(handle, callback, context, timeout, flags);
}

extern WINAPI void wine32a_kernelbase_RegisterWaitForSingleObjectEx(void);  /* ../dlls/kernelbase/sync.c:148 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RegisterWaitForSingleObjectEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RegisterWaitForSingleObjectEx") "\n"
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

extern WINAPI void wine32b_kernelbase_ReleaseActCtx(HANDLE  context) /* ../dlls/kernelbase/loader.c:867 */
{
	TRACE("Enter ReleaseActCtx\n");
	return pReleaseActCtx(context);
}

extern WINAPI void wine32a_kernelbase_ReleaseActCtx(void);  /* ../dlls/kernelbase/loader.c:867 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReleaseActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReleaseActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ReleaseMutex(HANDLE  handle) /* ../dlls/kernelbase/sync.c:527 */
{
	TRACE("Enter ReleaseMutex\n");
	return pReleaseMutex(handle);
}

extern WINAPI void wine32a_kernelbase_ReleaseMutex(void);  /* ../dlls/kernelbase/sync.c:527 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReleaseMutex,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReleaseMutex") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ReleaseSemaphore(HANDLE  handle, LONG  count, LONG*  previous) /* ../dlls/kernelbase/sync.c:597 */
{
	TRACE("Enter ReleaseSemaphore\n");
	return pReleaseSemaphore(handle, count, previous);
}

extern WINAPI void wine32a_kernelbase_ReleaseSemaphore(void);  /* ../dlls/kernelbase/sync.c:597 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ReleaseSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ReleaseSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_kernelbase_RemapPredefinedHandleInternal(HKEY  hkey, HKEY  override) /* ../dlls/kernelbase/registry.c:350 */
{
	TRACE("Enter RemapPredefinedHandleInternal\n");
	return pRemapPredefinedHandleInternal(hkey, override);
}

extern WINAPI void wine32a_kernelbase_RemapPredefinedHandleInternal(void);  /* ../dlls/kernelbase/registry.c:350 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RemapPredefinedHandleInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RemapPredefinedHandleInternal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_ResetEvent(HANDLE  handle) /* ../dlls/kernelbase/sync.c:427 */
{
	TRACE("Enter ResetEvent\n");
	return pResetEvent(handle);
}

extern WINAPI void wine32a_kernelbase_ResetEvent(void);  /* ../dlls/kernelbase/sync.c:427 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ResetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ResetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_ResumeThread(HANDLE  thread) /* ../dlls/kernelbase/thread.c:369 */
{
	TRACE("Enter ResumeThread\n");
	return pResumeThread(thread);
}

extern WINAPI void wine32a_kernelbase_ResumeThread(void);  /* ../dlls/kernelbase/thread.c:369 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ResumeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ResumeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_RevertToSelf(void) /* ../dlls/kernelbase/security.c:791 */
{
	TRACE("Enter RevertToSelf\n");
	return pRevertToSelf();
}

extern WINAPI void wine32a_kernelbase_RevertToSelf(void);  /* ../dlls/kernelbase/security.c:791 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_RevertToSelf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_RevertToSelf") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_SHLoadIndirectString(WCHAR*  src, WCHAR*  dst, UINT  dst_len, void**  reserved) /* ../dlls/kernelbase/string.c:1561 */
{
	TRACE("Enter SHLoadIndirectString\n");
	return pSHLoadIndirectString(src, dst, dst_len, reserved);
}

extern WINAPI void wine32a_kernelbase_SHLoadIndirectString(void);  /* ../dlls/kernelbase/string.c:1561 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHLoadIndirectString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHLoadIndirectString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegCloseUSKey(HUSKEY  hUSKey) /* ../dlls/kernelbase/registry.c:3240 */
{
	TRACE("Enter SHRegCloseUSKey\n");
	return pSHRegCloseUSKey(hUSKey);
}

extern WINAPI void wine32a_kernelbase_SHRegCloseUSKey(void);  /* ../dlls/kernelbase/registry.c:3240 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegCloseUSKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegCloseUSKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegCreateUSKeyA(LPCSTR  path, REGSAM  samDesired, HUSKEY  relative_key, PHUSKEY  new_uskey, DWORD  flags) /* ../dlls/kernelbase/registry.c:3142 */
{
	TRACE("Enter SHRegCreateUSKeyA\n");
	return pSHRegCreateUSKeyA(path, samDesired, relative_key, new_uskey, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegCreateUSKeyA(void);  /* ../dlls/kernelbase/registry.c:3142 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegCreateUSKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegCreateUSKeyA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegCreateUSKeyW(WCHAR*  path, REGSAM  samDesired, HUSKEY  relative_key, PHUSKEY  new_uskey, DWORD  flags) /* ../dlls/kernelbase/registry.c:3196 */
{
	TRACE("Enter SHRegCreateUSKeyW\n");
	return pSHRegCreateUSKeyW(path, samDesired, relative_key, new_uskey, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegCreateUSKeyW(void);  /* ../dlls/kernelbase/registry.c:3196 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegCreateUSKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegCreateUSKeyW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegDeleteEmptyUSKeyA(HUSKEY  hUSKey, char*  value, SHREGDEL_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3261 */
{
	TRACE("Enter SHRegDeleteEmptyUSKeyA\n");
	return pSHRegDeleteEmptyUSKeyA(hUSKey, value, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegDeleteEmptyUSKeyA(void);  /* ../dlls/kernelbase/registry.c:3261 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegDeleteEmptyUSKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegDeleteEmptyUSKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegDeleteEmptyUSKeyW(HUSKEY  hUSKey, WCHAR*  value, SHREGDEL_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3267 */
{
	TRACE("Enter SHRegDeleteEmptyUSKeyW\n");
	return pSHRegDeleteEmptyUSKeyW(hUSKey, value, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegDeleteEmptyUSKeyW(void);  /* ../dlls/kernelbase/registry.c:3267 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegDeleteEmptyUSKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegDeleteEmptyUSKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegDeleteUSValueA(HUSKEY  hUSKey, char*  value, SHREGDEL_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3273 */
{
	TRACE("Enter SHRegDeleteUSValueA\n");
	return pSHRegDeleteUSValueA(hUSKey, value, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegDeleteUSValueA(void);  /* ../dlls/kernelbase/registry.c:3273 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegDeleteUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegDeleteUSValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegDeleteUSValueW(HUSKEY  hUSKey, WCHAR*  value, SHREGDEL_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3279 */
{
	TRACE("Enter SHRegDeleteUSValueW\n");
	return pSHRegDeleteUSValueW(hUSKey, value, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegDeleteUSValueW(void);  /* ../dlls/kernelbase/registry.c:3279 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegDeleteUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegDeleteUSValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegEnumUSKeyA(HUSKEY  hUSKey, DWORD  index, char*  name, DWORD*  name_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3319 */
{
	TRACE("Enter SHRegEnumUSKeyA\n");
	return pSHRegEnumUSKeyA(hUSKey, index, name, name_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegEnumUSKeyA(void);  /* ../dlls/kernelbase/registry.c:3319 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegEnumUSKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegEnumUSKeyA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegEnumUSKeyW(HUSKEY  hUSKey, DWORD  index, WCHAR*  name, DWORD*  name_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3335 */
{
	TRACE("Enter SHRegEnumUSKeyW\n");
	return pSHRegEnumUSKeyW(hUSKey, index, name, name_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegEnumUSKeyW(void);  /* ../dlls/kernelbase/registry.c:3335 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegEnumUSKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegEnumUSKeyW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegEnumUSValueA(HUSKEY  hUSKey, DWORD  index, char*  value_name, DWORD*  value_name_len, DWORD*  type, void*  data, DWORD*  data_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3285 */
{
	TRACE("Enter SHRegEnumUSValueA\n");
	return pSHRegEnumUSValueA(hUSKey, index, value_name, value_name_len, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegEnumUSValueA(void);  /* ../dlls/kernelbase/registry.c:3285 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegEnumUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegEnumUSValueA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegEnumUSValueW(HUSKEY  hUSKey, DWORD  index, WCHAR*  value_name, DWORD*  value_name_len, DWORD*  type, void*  data, DWORD*  data_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3302 */
{
	TRACE("Enter SHRegEnumUSValueW\n");
	return pSHRegEnumUSValueW(hUSKey, index, value_name, value_name_len, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegEnumUSValueW(void);  /* ../dlls/kernelbase/registry.c:3302 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegEnumUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegEnumUSValueW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_SHRegGetBoolUSValueA(char*  subkey, char*  value, BOOL  ignore_hkcu, BOOL  default_value) /* ../dlls/kernelbase/registry.c:3704 */
{
	TRACE("Enter SHRegGetBoolUSValueA\n");
	return pSHRegGetBoolUSValueA(subkey, value, ignore_hkcu, default_value);
}

extern WINAPI void wine32a_kernelbase_SHRegGetBoolUSValueA(void);  /* ../dlls/kernelbase/registry.c:3704 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegGetBoolUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegGetBoolUSValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SHRegGetBoolUSValueW(WCHAR*  subkey, WCHAR*  value, BOOL  ignore_hkcu, BOOL  default_value) /* ../dlls/kernelbase/registry.c:3745 */
{
	TRACE("Enter SHRegGetBoolUSValueW\n");
	return pSHRegGetBoolUSValueW(subkey, value, ignore_hkcu, default_value);
}

extern WINAPI void wine32a_kernelbase_SHRegGetBoolUSValueW(void);  /* ../dlls/kernelbase/registry.c:3745 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegGetBoolUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegGetBoolUSValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernelbase_SHRegGetUSValueA(char*  subkey, char*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len) /* ../dlls/kernelbase/registry.c:3662 */
{
	TRACE("Enter SHRegGetUSValueA\n");
	return pSHRegGetUSValueA(subkey, value, type, data, data_len, ignore_hkcu, default_data, default_data_len);
}

extern WINAPI void wine32a_kernelbase_SHRegGetUSValueA(void);  /* ../dlls/kernelbase/registry.c:3662 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegGetUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegGetUSValueA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegGetUSValueW(WCHAR*  subkey, WCHAR*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len) /* ../dlls/kernelbase/registry.c:3683 */
{
	TRACE("Enter SHRegGetUSValueW\n");
	return pSHRegGetUSValueW(subkey, value, type, data, data_len, ignore_hkcu, default_data, default_data_len);
}

extern WINAPI void wine32a_kernelbase_SHRegGetUSValueW(void);  /* ../dlls/kernelbase/registry.c:3683 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegGetUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegGetUSValueW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegOpenUSKeyA(char*  path, REGSAM  access_mask, HUSKEY  relative_key, HUSKEY*  uskey, BOOL  ignore_hkcu) /* ../dlls/kernelbase/registry.c:3351 */
{
	TRACE("Enter SHRegOpenUSKeyA\n");
	return pSHRegOpenUSKeyA(path, access_mask, relative_key, uskey, ignore_hkcu);
}

extern WINAPI void wine32a_kernelbase_SHRegOpenUSKeyA(void);  /* ../dlls/kernelbase/registry.c:3351 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegOpenUSKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegOpenUSKeyA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegOpenUSKeyW(WCHAR*  path, REGSAM  access_mask, HUSKEY  relative_key, HUSKEY*  uskey, BOOL  ignore_hkcu) /* ../dlls/kernelbase/registry.c:3361 */
{
	TRACE("Enter SHRegOpenUSKeyW\n");
	return pSHRegOpenUSKeyW(path, access_mask, relative_key, uskey, ignore_hkcu);
}

extern WINAPI void wine32a_kernelbase_SHRegOpenUSKeyW(void);  /* ../dlls/kernelbase/registry.c:3361 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegOpenUSKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegOpenUSKeyW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegQueryInfoUSKeyA(HUSKEY  hUSKey, DWORD*  subkeys, DWORD*  max_subkey_len, DWORD*  values, DWORD*  max_value_name_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3542 */
{
	TRACE("Enter SHRegQueryInfoUSKeyA\n");
	return pSHRegQueryInfoUSKeyA(hUSKey, subkeys, max_subkey_len, values, max_value_name_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegQueryInfoUSKeyA(void);  /* ../dlls/kernelbase/registry.c:3542 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegQueryInfoUSKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegQueryInfoUSKeyA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegQueryInfoUSKeyW(HUSKEY  hUSKey, DWORD*  subkeys, DWORD*  max_subkey_len, DWORD*  values, DWORD*  max_value_name_len, SHREGENUM_FLAGS  flags) /* ../dlls/kernelbase/registry.c:3565 */
{
	TRACE("Enter SHRegQueryInfoUSKeyW\n");
	return pSHRegQueryInfoUSKeyW(hUSKey, subkeys, max_subkey_len, values, max_value_name_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegQueryInfoUSKeyW(void);  /* ../dlls/kernelbase/registry.c:3565 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegQueryInfoUSKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegQueryInfoUSKeyW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegQueryUSValueA(HUSKEY  hUSKey, char*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len) /* ../dlls/kernelbase/registry.c:3588 */
{
	TRACE("Enter SHRegQueryUSValueA\n");
	return pSHRegQueryUSValueA(hUSKey, value, type, data, data_len, ignore_hkcu, default_data, default_data_len);
}

extern WINAPI void wine32a_kernelbase_SHRegQueryUSValueA(void);  /* ../dlls/kernelbase/registry.c:3588 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegQueryUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegQueryUSValueA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegQueryUSValueW(HUSKEY  hUSKey, WCHAR*  value, DWORD*  type, void*  data, DWORD*  data_len, BOOL  ignore_hkcu, void*  default_data, DWORD  default_data_len) /* ../dlls/kernelbase/registry.c:3625 */
{
	TRACE("Enter SHRegQueryUSValueW\n");
	return pSHRegQueryUSValueW(hUSKey, value, type, data, data_len, ignore_hkcu, default_data, default_data_len);
}

extern WINAPI void wine32a_kernelbase_SHRegQueryUSValueW(void);  /* ../dlls/kernelbase/registry.c:3625 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegQueryUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegQueryUSValueW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegSetUSValueA(char*  subkey, char*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags) /* ../dlls/kernelbase/registry.c:3494 */
{
	TRACE("Enter SHRegSetUSValueA\n");
	return pSHRegSetUSValueA(subkey, value, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegSetUSValueA(void);  /* ../dlls/kernelbase/registry.c:3494 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegSetUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegSetUSValueA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegSetUSValueW(WCHAR*  subkey, WCHAR*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags) /* ../dlls/kernelbase/registry.c:3518 */
{
	TRACE("Enter SHRegSetUSValueW\n");
	return pSHRegSetUSValueW(subkey, value, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegSetUSValueW(void);  /* ../dlls/kernelbase/registry.c:3518 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegSetUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegSetUSValueW") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegWriteUSValueA(HUSKEY  hUSKey, char*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags) /* ../dlls/kernelbase/registry.c:3418 */
{
	TRACE("Enter SHRegWriteUSValueA\n");
	return pSHRegWriteUSValueA(hUSKey, value, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegWriteUSValueA(void);  /* ../dlls/kernelbase/registry.c:3418 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegWriteUSValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegWriteUSValueA") "\n"
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

extern WINAPI LONG wine32b_kernelbase_SHRegWriteUSValueW(HUSKEY  hUSKey, WCHAR*  value, DWORD  type, void*  data, DWORD  data_len, DWORD  flags) /* ../dlls/kernelbase/registry.c:3428 */
{
	TRACE("Enter SHRegWriteUSValueW\n");
	return pSHRegWriteUSValueW(hUSKey, value, type, data, data_len, flags);
}

extern WINAPI void wine32a_kernelbase_SHRegWriteUSValueW(void);  /* ../dlls/kernelbase/registry.c:3428 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHRegWriteUSValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHRegWriteUSValueW") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_SHTruncateString(char*  str, DWORD  size) /* ../dlls/kernelbase/string.c:1540 */
{
	TRACE("Enter SHTruncateString\n");
	return pSHTruncateString(str, size);
}

extern WINAPI void wine32a_kernelbase_SHTruncateString(void);  /* ../dlls/kernelbase/string.c:1540 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SHTruncateString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SHTruncateString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetAclInformation(PACL  acl, LPVOID  info, DWORD  len, ACL_INFORMATION_CLASS  class) /* ../dlls/kernelbase/security.c:1461 */
{
	TRACE("Enter SetAclInformation\n");
	return pSetAclInformation(acl, info, len, class);
}

extern WINAPI void wine32a_kernelbase_SetAclInformation(void);  /* ../dlls/kernelbase/security.c:1461 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetAclInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetAclInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetEndOfFile(HANDLE  file) /* ../dlls/kernelbase/file.c:1315 */
{
	TRACE("Enter SetEndOfFile\n");
	return pSetEndOfFile(file);
}

extern WINAPI void wine32a_kernelbase_SetEndOfFile(void);  /* ../dlls/kernelbase/file.c:1315 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetEndOfFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetEndOfFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernelbase_SetErrorMode(UINT  mode) /* ../dlls/kernelbase/process.c:246 */
{
	TRACE("Enter SetErrorMode\n");
	return pSetErrorMode(mode);
}

extern WINAPI void wine32a_kernelbase_SetErrorMode(void);  /* ../dlls/kernelbase/process.c:246 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetErrorMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetEvent(HANDLE  handle) /* ../dlls/kernelbase/sync.c:418 */
{
	TRACE("Enter SetEvent\n");
	return pSetEvent(handle);
}

extern WINAPI void wine32a_kernelbase_SetEvent(void);  /* ../dlls/kernelbase/sync.c:418 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_SetFileApisToANSI(void) /* ../dlls/kernelbase/file.c:713 */
{
	TRACE("Enter SetFileApisToANSI\n");
	return pSetFileApisToANSI();
}

extern WINAPI void wine32a_kernelbase_SetFileApisToANSI(void);  /* ../dlls/kernelbase/file.c:713 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileApisToANSI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileApisToANSI") "\n"
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

extern WINAPI void wine32b_kernelbase_SetFileApisToOEM(void) /* ../dlls/kernelbase/file.c:722 */
{
	TRACE("Enter SetFileApisToOEM\n");
	return pSetFileApisToOEM();
}

extern WINAPI void wine32a_kernelbase_SetFileApisToOEM(void);  /* ../dlls/kernelbase/file.c:722 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileApisToOEM,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileApisToOEM") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_SetFileAttributesA(LPCSTR  name, DWORD  attributes) /* ../dlls/kernelbase/file.c:731 */
{
	TRACE("Enter SetFileAttributesA\n");
	return pSetFileAttributesA(name, attributes);
}

extern WINAPI void wine32a_kernelbase_SetFileAttributesA(void);  /* ../dlls/kernelbase/file.c:731 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileAttributesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileAttributesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFileAttributesW(LPCWSTR  name, DWORD  attributes) /* ../dlls/kernelbase/file.c:743 */
{
	TRACE("Enter SetFileAttributesW\n");
	return pSetFileAttributesW(name, attributes);
}

extern WINAPI void wine32a_kernelbase_SetFileAttributesW(void);  /* ../dlls/kernelbase/file.c:743 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileAttributesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileAttributesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFileInformationByHandle(HANDLE  file, FILE_INFO_BY_HANDLE_CLASS  class, void*  info, DWORD  size) /* ../dlls/kernelbase/file.c:1334 */
{
	TRACE("Enter SetFileInformationByHandle\n");
	return pSetFileInformationByHandle(file, class, info, size);
}

extern WINAPI void wine32a_kernelbase_SetFileInformationByHandle(void);  /* ../dlls/kernelbase/file.c:1334 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileInformationByHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileInformationByHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_SetFilePointer(HANDLE  file, LONG  distance, LONG*  highword, DWORD  method) /* ../dlls/kernelbase/file.c:1386 */
{
	TRACE("Enter SetFilePointer\n");
	return pSetFilePointer(file, distance, highword, method);
}

extern WINAPI void wine32a_kernelbase_SetFilePointer(void);  /* ../dlls/kernelbase/file.c:1386 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFilePointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFilePointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFilePointerEx(HANDLE  file, LARGE_INTEGER  distance, LARGE_INTEGER*  newpos, DWORD  method) /* ../dlls/kernelbase/file.c:1408 */
{
	TRACE("Enter SetFilePointerEx\n");
	return pSetFilePointerEx(file, distance, newpos, method);
}

extern WINAPI void wine32a_kernelbase_SetFilePointerEx(void);  /* ../dlls/kernelbase/file.c:1408 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFilePointerEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFilePointerEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFileSecurityW(LPCWSTR  name, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr) /* ../dlls/kernelbase/security.c:1115 */
{
	TRACE("Enter SetFileSecurityW\n");
	return pSetFileSecurityW(name, info, descr);
}

extern WINAPI void wine32a_kernelbase_SetFileSecurityW(void);  /* ../dlls/kernelbase/security.c:1115 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileSecurityW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileSecurityW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFileTime(HANDLE  file, FILETIME*  ctime, FILETIME*  atime, FILETIME*  mtime) /* ../dlls/kernelbase/file.c:1457 */
{
	TRACE("Enter SetFileTime\n");
	return pSetFileTime(file, ctime, atime, mtime);
}

extern WINAPI void wine32a_kernelbase_SetFileTime(void);  /* ../dlls/kernelbase/file.c:1457 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetFileValidData(HANDLE  file, LONGLONG  length) /* ../dlls/kernelbase/file.c:1487 */
{
	TRACE("Enter SetFileValidData\n");
	return pSetFileValidData(file, length);
}

extern WINAPI void wine32a_kernelbase_SetFileValidData(void);  /* ../dlls/kernelbase/file.c:1487 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetFileValidData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetFileValidData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetKernelObjectSecurity(HANDLE  handle, SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr) /* ../dlls/kernelbase/security.c:1138 */
{
	TRACE("Enter SetKernelObjectSecurity\n");
	return pSetKernelObjectSecurity(handle, info, descr);
}

extern WINAPI void wine32a_kernelbase_SetKernelObjectSecurity(void);  /* ../dlls/kernelbase/security.c:1138 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetKernelObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetKernelObjectSecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetNamedPipeHandleState(HANDLE  pipe, LPDWORD  mode, LPDWORD  count, LPDWORD  timeout) /* ../dlls/kernelbase/sync.c:1255 */
{
	TRACE("Enter SetNamedPipeHandleState\n");
	return pSetNamedPipeHandleState(pipe, mode, count, timeout);
}

extern WINAPI void wine32a_kernelbase_SetNamedPipeHandleState(void);  /* ../dlls/kernelbase/sync.c:1255 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetNamedPipeHandleState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetNamedPipeHandleState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetPriorityClass(HANDLE  process, DWORD  class) /* ../dlls/kernelbase/process.c:259 */
{
	TRACE("Enter SetPriorityClass\n");
	return pSetPriorityClass(process, class);
}

extern WINAPI void wine32a_kernelbase_SetPriorityClass(void);  /* ../dlls/kernelbase/process.c:259 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetPriorityClass,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetPriorityClass") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetPrivateObjectSecurity(SECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  descr, PSECURITY_DESCRIPTOR*  obj_descr, PGENERIC_MAPPING  mapping, HANDLE  token) /* ../dlls/kernelbase/security.c:1146 */
{
	TRACE("Enter SetPrivateObjectSecurity\n");
	return pSetPrivateObjectSecurity(info, descr, obj_descr, mapping, token);
}

extern WINAPI void wine32a_kernelbase_SetPrivateObjectSecurity(void);  /* ../dlls/kernelbase/security.c:1146 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetPrivateObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetPrivateObjectSecurity") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_SetProcessAffinityUpdateMode(HANDLE  process, DWORD  flags) /* ../dlls/kernelbase/process.c:283 */
{
	TRACE("Enter SetProcessAffinityUpdateMode\n");
	return pSetProcessAffinityUpdateMode(process, flags);
}

extern WINAPI void wine32a_kernelbase_SetProcessAffinityUpdateMode(void);  /* ../dlls/kernelbase/process.c:283 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetProcessAffinityUpdateMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetProcessAffinityUpdateMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetProcessMitigationPolicy(PROCESS_MITIGATION_POLICY  policy, void*  buffer, SIZE_T  length) /* ../dlls/kernelbase/process.c:294 */
{
	TRACE("Enter SetProcessMitigationPolicy\n");
	return pSetProcessMitigationPolicy(policy, buffer, length);
}

extern WINAPI void wine32a_kernelbase_SetProcessMitigationPolicy(void);  /* ../dlls/kernelbase/process.c:294 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetProcessMitigationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetProcessMitigationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetProcessPriorityBoost(HANDLE  process, BOOL  disable) /* ../dlls/kernelbase/process.c:305 */
{
	TRACE("Enter SetProcessPriorityBoost\n");
	return pSetProcessPriorityBoost(process, disable);
}

extern WINAPI void wine32a_kernelbase_SetProcessPriorityBoost(void);  /* ../dlls/kernelbase/process.c:305 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetProcessPriorityBoost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetProcessPriorityBoost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetProcessShutdownParameters(DWORD  level, DWORD  flags) /* ../dlls/kernelbase/process.c:315 */
{
	TRACE("Enter SetProcessShutdownParameters\n");
	return pSetProcessShutdownParameters(level, flags);
}

extern WINAPI void wine32a_kernelbase_SetProcessShutdownParameters(void);  /* ../dlls/kernelbase/process.c:315 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetProcessShutdownParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetProcessShutdownParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetProcessWorkingSetSizeEx(HANDLE  process, SIZE_T  minset, SIZE_T  maxset, DWORD  flags) /* ../dlls/kernelbase/process.c:327 */
{
	TRACE("Enter SetProcessWorkingSetSizeEx\n");
	return pSetProcessWorkingSetSizeEx(process, minset, maxset, flags);
}

extern WINAPI void wine32a_kernelbase_SetProcessWorkingSetSizeEx(void);  /* ../dlls/kernelbase/process.c:327 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetProcessWorkingSetSizeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetProcessWorkingSetSizeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR  descr, SECURITY_DESCRIPTOR_CONTROL  mask, SECURITY_DESCRIPTOR_CONTROL  set) /* ../dlls/kernelbase/security.c:1157 */
{
	TRACE("Enter SetSecurityDescriptorControl\n");
	return pSetSecurityDescriptorControl(descr, mask, set);
}

extern WINAPI void wine32a_kernelbase_SetSecurityDescriptorControl(void);  /* ../dlls/kernelbase/security.c:1157 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetSecurityDescriptorControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetSecurityDescriptorControl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR  descr, BOOL  present, PACL  dacl, BOOL  defaulted) /* ../dlls/kernelbase/security.c:1166 */
{
	TRACE("Enter SetSecurityDescriptorDacl\n");
	return pSetSecurityDescriptorDacl(descr, present, dacl, defaulted);
}

extern WINAPI void wine32a_kernelbase_SetSecurityDescriptorDacl(void);  /* ../dlls/kernelbase/security.c:1166 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetSecurityDescriptorDacl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetSecurityDescriptorDacl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR  descr, PSID  group, BOOL  defaulted) /* ../dlls/kernelbase/security.c:1174 */
{
	TRACE("Enter SetSecurityDescriptorGroup\n");
	return pSetSecurityDescriptorGroup(descr, group, defaulted);
}

extern WINAPI void wine32a_kernelbase_SetSecurityDescriptorGroup(void);  /* ../dlls/kernelbase/security.c:1174 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetSecurityDescriptorGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetSecurityDescriptorGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR  descr, PSID  owner, BOOL  defaulted) /* ../dlls/kernelbase/security.c:1182 */
{
	TRACE("Enter SetSecurityDescriptorOwner\n");
	return pSetSecurityDescriptorOwner(descr, owner, defaulted);
}

extern WINAPI void wine32a_kernelbase_SetSecurityDescriptorOwner(void);  /* ../dlls/kernelbase/security.c:1182 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetSecurityDescriptorOwner,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetSecurityDescriptorOwner") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR  descr, BOOL  present, PACL  sacl, BOOL  defaulted) /* ../dlls/kernelbase/security.c:1190 */
{
	TRACE("Enter SetSecurityDescriptorSacl\n");
	return pSetSecurityDescriptorSacl(descr, present, sacl, defaulted);
}

extern WINAPI void wine32a_kernelbase_SetSecurityDescriptorSacl(void);  /* ../dlls/kernelbase/security.c:1190 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetSecurityDescriptorSacl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetSecurityDescriptorSacl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadContext(HANDLE  thread, CONTEXT*  context) /* ../dlls/kernelbase/thread.c:381 */
{
	TRACE("Enter SetThreadContext\n");
	return pSetThreadContext(thread, context);
}

extern WINAPI void wine32a_kernelbase_SetThreadContext(void);  /* ../dlls/kernelbase/thread.c:381 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadErrorMode(DWORD  mode, DWORD*  old) /* ../dlls/kernelbase/thread.c:390 */
{
	TRACE("Enter SetThreadErrorMode\n");
	return pSetThreadErrorMode(mode, old);
}

extern WINAPI void wine32a_kernelbase_SetThreadErrorMode(void);  /* ../dlls/kernelbase/thread.c:390 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadErrorMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadGroupAffinity(HANDLE  thread, GROUP_AFFINITY*  new, GROUP_AFFINITY*  old) /* ../dlls/kernelbase/thread.c:414 */
{
	TRACE("Enter SetThreadGroupAffinity\n");
	return pSetThreadGroupAffinity(thread, new, old);
}

extern WINAPI void wine32a_kernelbase_SetThreadGroupAffinity(void);  /* ../dlls/kernelbase/thread.c:414 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadGroupAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadGroupAffinity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_SetThreadIdealProcessor(HANDLE  thread, DWORD  proc) /* ../dlls/kernelbase/thread.c:425 */
{
	TRACE("Enter SetThreadIdealProcessor\n");
	return pSetThreadIdealProcessor(thread, proc);
}

extern WINAPI void wine32a_kernelbase_SetThreadIdealProcessor(void);  /* ../dlls/kernelbase/thread.c:425 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadIdealProcessor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadIdealProcessor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadIdealProcessorEx(HANDLE  thread, PROCESSOR_NUMBER*  ideal, PROCESSOR_NUMBER*  previous) /* ../dlls/kernelbase/thread.c:440 */
{
	TRACE("Enter SetThreadIdealProcessorEx\n");
	return pSetThreadIdealProcessorEx(thread, ideal, previous);
}

extern WINAPI void wine32a_kernelbase_SetThreadIdealProcessorEx(void);  /* ../dlls/kernelbase/thread.c:440 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadIdealProcessorEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadIdealProcessorEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadPriority(HANDLE  thread, INT  priority) /* ../dlls/kernelbase/thread.c:452 */
{
	TRACE("Enter SetThreadPriority\n");
	return pSetThreadPriority(thread, priority);
}

extern WINAPI void wine32a_kernelbase_SetThreadPriority(void);  /* ../dlls/kernelbase/thread.c:452 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadPriority,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadPriority") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadPriorityBoost(HANDLE  thread, BOOL  disable) /* ../dlls/kernelbase/thread.c:462 */
{
	TRACE("Enter SetThreadPriorityBoost\n");
	return pSetThreadPriorityBoost(thread, disable);
}

extern WINAPI void wine32a_kernelbase_SetThreadPriorityBoost(void);  /* ../dlls/kernelbase/thread.c:462 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadPriorityBoost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadPriorityBoost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadStackGuarantee(ULONG*  size) /* ../dlls/kernelbase/thread.c:471 */
{
	TRACE("Enter SetThreadStackGuarantee\n");
	return pSetThreadStackGuarantee(size);
}

extern WINAPI void wine32a_kernelbase_SetThreadStackGuarantee(void);  /* ../dlls/kernelbase/thread.c:471 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadStackGuarantee,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadStackGuarantee") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetThreadToken(PHANDLE  thread, HANDLE  token) /* ../dlls/kernelbase/security.c:799 */
{
	TRACE("Enter SetThreadToken\n");
	return pSetThreadToken(thread, token);
}

extern WINAPI void wine32a_kernelbase_SetThreadToken(void);  /* ../dlls/kernelbase/security.c:799 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetThreadToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetThreadToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetTokenInformation(HANDLE  token, TOKEN_INFORMATION_CLASS  class, LPVOID  info, DWORD  len) /* ../dlls/kernelbase/security.c:808 */
{
	TRACE("Enter SetTokenInformation\n");
	return pSetTokenInformation(token, class, info, len);
}

extern WINAPI void wine32a_kernelbase_SetTokenInformation(void);  /* ../dlls/kernelbase/security.c:808 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetTokenInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetTokenInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SetWaitableTimer(HANDLE  handle, LARGE_INTEGER*  when, LONG  period, PTIMERAPCROUTINE  callback, LPVOID  arg, BOOL  resume) /* ../dlls/kernelbase/sync.c:668 */
{
	TRACE("Enter SetWaitableTimer\n");
	return pSetWaitableTimer(handle, when, period, callback, arg, resume);
}

extern WINAPI void wine32a_kernelbase_SetWaitableTimer(void);  /* ../dlls/kernelbase/sync.c:668 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetWaitableTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetWaitableTimer") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_SetWaitableTimerEx(HANDLE  handle, LARGE_INTEGER*  when, LONG  period, PTIMERAPCROUTINE  callback, LPVOID  arg, REASON_CONTEXT*  context, ULONG  tolerabledelay) /* ../dlls/kernelbase/sync.c:680 */
{
	TRACE("Enter SetWaitableTimerEx\n");
	return pSetWaitableTimerEx(handle, when, period, callback, arg, context, tolerabledelay);
}

extern WINAPI void wine32a_kernelbase_SetWaitableTimerEx(void);  /* ../dlls/kernelbase/sync.c:680 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SetWaitableTimerEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SetWaitableTimerEx") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_SignalObjectAndWait(HANDLE  signal, HANDLE  wait, DWORD  timeout, BOOL  alertable) /* ../dlls/kernelbase/sync.c:170 */
{
	TRACE("Enter SignalObjectAndWait\n");
	return pSignalObjectAndWait(signal, wait, timeout, alertable);
}

extern WINAPI void wine32a_kernelbase_SignalObjectAndWait(void);  /* ../dlls/kernelbase/sync.c:170 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SignalObjectAndWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SignalObjectAndWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_SizeofResource(HINSTANCE  module, HRSRC  rsrc) /* ../dlls/kernelbase/loader.c:745 */
{
	TRACE("Enter SizeofResource\n");
	return pSizeofResource(module, rsrc);
}

extern WINAPI void wine32a_kernelbase_SizeofResource(void);  /* ../dlls/kernelbase/loader.c:745 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SizeofResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SizeofResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_Sleep(DWORD  timeout) /* ../dlls/kernelbase/sync.c:191 */
{
	TRACE("Enter Sleep\n");
	return pSleep(timeout);
}

extern WINAPI void wine32a_kernelbase_Sleep(void);  /* ../dlls/kernelbase/sync.c:191 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_Sleep,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_Sleep") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SleepConditionVariableCS(CONDITION_VARIABLE*  variable, CRITICAL_SECTION*  crit, DWORD  timeout) /* ../dlls/kernelbase/sync.c:897 */
{
	TRACE("Enter SleepConditionVariableCS\n");
	return pSleepConditionVariableCS(variable, crit, timeout);
}

extern WINAPI void wine32a_kernelbase_SleepConditionVariableCS(void);  /* ../dlls/kernelbase/sync.c:897 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SleepConditionVariableCS,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SleepConditionVariableCS") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SleepConditionVariableSRW(RTL_CONDITION_VARIABLE*  variable, RTL_SRWLOCK*  lock, DWORD  timeout, ULONG  flags) /* ../dlls/kernelbase/sync.c:909 */
{
	TRACE("Enter SleepConditionVariableSRW\n");
	return pSleepConditionVariableSRW(variable, lock, timeout, flags);
}

extern WINAPI void wine32a_kernelbase_SleepConditionVariableSRW(void);  /* ../dlls/kernelbase/sync.c:909 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SleepConditionVariableSRW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SleepConditionVariableSRW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_SleepEx(DWORD  timeout, BOOL  alertable) /* ../dlls/kernelbase/sync.c:202 */
{
	TRACE("Enter SleepEx\n");
	return pSleepEx(timeout, alertable);
}

extern WINAPI void wine32a_kernelbase_SleepEx(void);  /* ../dlls/kernelbase/sync.c:202 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SleepEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SleepEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCSpnA(char*  str, char*  match) /* ../dlls/kernelbase/string.c:641 */
{
	TRACE("Enter StrCSpnA\n");
	return pStrCSpnA(str, match);
}

extern WINAPI void wine32a_kernelbase_StrCSpnA(void);  /* ../dlls/kernelbase/string.c:641 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCSpnA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCSpnA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCSpnIA(char*  str, char*  match) /* ../dlls/kernelbase/string.c:665 */
{
	TRACE("Enter StrCSpnIA\n");
	return pStrCSpnIA(str, match);
}

extern WINAPI void wine32a_kernelbase_StrCSpnIA(void);  /* ../dlls/kernelbase/string.c:665 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCSpnIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCSpnIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCSpnIW(WCHAR*  str, WCHAR*  match) /* ../dlls/kernelbase/string.c:681 */
{
	TRACE("Enter StrCSpnIW\n");
	return pStrCSpnIW(str, match);
}

extern WINAPI void wine32a_kernelbase_StrCSpnIW(void);  /* ../dlls/kernelbase/string.c:681 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCSpnIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCSpnIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCSpnW(WCHAR*  str, WCHAR*  match) /* ../dlls/kernelbase/string.c:657 */
{
	TRACE("Enter StrCSpnW\n");
	return pStrCSpnW(str, match);
}

extern WINAPI void wine32a_kernelbase_StrCSpnW(void);  /* ../dlls/kernelbase/string.c:657 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCSpnW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCSpnW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrCatBuffA(char*  str, char*  cat, INT  max_len) /* ../dlls/kernelbase/string.c:1479 */
{
	TRACE("Enter StrCatBuffA\n");
	return pStrCatBuffA(str, cat, max_len);
}

extern WINAPI void wine32a_kernelbase_StrCatBuffA(void);  /* ../dlls/kernelbase/string.c:1479 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCatBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCatBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrCatBuffW(WCHAR*  str, WCHAR*  cat, INT  max_len) /* ../dlls/kernelbase/string.c:1496 */
{
	TRACE("Enter StrCatBuffW\n");
	return pStrCatBuffW(str, cat, max_len);
}

extern WINAPI void wine32a_kernelbase_StrCatBuffW(void);  /* ../dlls/kernelbase/string.c:1496 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCatBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCatBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCatChainW(WCHAR*  str, DWORD  max_len, DWORD  at, WCHAR*  cat) /* ../dlls/kernelbase/string.c:1513 */
{
	TRACE("Enter StrCatChainW\n");
	return pStrCatChainW(str, max_len, at, cat);
}

extern WINAPI void wine32a_kernelbase_StrCatChainW(void);  /* ../dlls/kernelbase/string.c:1513 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCatChainW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCatChainW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrChrA(char*  str, WORD  ch) /* ../dlls/kernelbase/string.c:306 */
{
	TRACE("Enter StrChrA\n");
	return pStrChrA(str, ch);
}

extern WINAPI void wine32a_kernelbase_StrChrA(void);  /* ../dlls/kernelbase/string.c:306 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrChrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrChrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrChrIA(char*  str, WORD  ch) /* ../dlls/kernelbase/string.c:333 */
{
	TRACE("Enter StrChrIA\n");
	return pStrChrIA(str, ch);
}

extern WINAPI void wine32a_kernelbase_StrChrIA(void);  /* ../dlls/kernelbase/string.c:333 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrChrIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrChrIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrChrIW(WCHAR*  str, WCHAR  ch) /* ../dlls/kernelbase/string.c:350 */
{
	TRACE("Enter StrChrIW\n");
	return pStrChrIW(str, ch);
}

extern WINAPI void wine32a_kernelbase_StrChrIW(void);  /* ../dlls/kernelbase/string.c:350 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrChrIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrChrIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR* wine32b_kernelbase_StrChrNW(WCHAR*  str, WCHAR  ch, UINT  max_len) /* ../dlls/kernelbase/string.c:369 */
{
	TRACE("Enter StrChrNW\n");
	return pStrChrNW(str, ch, max_len);
}

extern WINAPI void wine32a_kernelbase_StrChrNW(void);  /* ../dlls/kernelbase/string.c:369 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrChrNW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrChrNW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrChrW(WCHAR*  str, WCHAR  ch) /* ../dlls/kernelbase/string.c:323 */
{
	TRACE("Enter StrChrW\n");
	return pStrChrW(str, ch);
}

extern WINAPI void wine32a_kernelbase_StrChrW(void);  /* ../dlls/kernelbase/string.c:323 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrChrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrChrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpCA(char*  str, char*  cmp) /* ../dlls/kernelbase/string.c:192 */
{
	TRACE("Enter StrCmpCA\n");
	return pStrCmpCA(str, cmp);
}

extern WINAPI void wine32a_kernelbase_StrCmpCA(void);  /* ../dlls/kernelbase/string.c:192 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpCA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpCA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpCW(WCHAR*  str, WCHAR*  cmp) /* ../dlls/kernelbase/string.c:197 */
{
	TRACE("Enter StrCmpCW\n");
	return pStrCmpCW(str, cmp);
}

extern WINAPI void wine32a_kernelbase_StrCmpCW(void);  /* ../dlls/kernelbase/string.c:197 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpCW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpCW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpICA(char*  str, char*  cmp) /* ../dlls/kernelbase/string.c:202 */
{
	TRACE("Enter StrCmpICA\n");
	return pStrCmpICA(str, cmp);
}

extern WINAPI void wine32a_kernelbase_StrCmpICA(void);  /* ../dlls/kernelbase/string.c:202 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpICA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpICA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpICW(WCHAR*  str, WCHAR*  cmp) /* ../dlls/kernelbase/string.c:207 */
{
	TRACE("Enter StrCmpICW\n");
	return pStrCmpICW(str, cmp);
}

extern WINAPI void wine32a_kernelbase_StrCmpICW(void);  /* ../dlls/kernelbase/string.c:207 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpICW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpICW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrCmpIW(WCHAR*  str, WCHAR*  comp) /* ../dlls/kernelbase/string.c:550 */
{
	TRACE("Enter StrCmpIW\n");
	return pStrCmpIW(str, comp);
}

extern WINAPI void wine32a_kernelbase_StrCmpIW(void);  /* ../dlls/kernelbase/string.c:550 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCmpLogicalW(WCHAR*  str, WCHAR*  comp) /* ../dlls/kernelbase/string.c:1393 */
{
	TRACE("Enter StrCmpLogicalW\n");
	return pStrCmpLogicalW(str, comp);
}

extern WINAPI void wine32a_kernelbase_StrCmpLogicalW(void);  /* ../dlls/kernelbase/string.c:1393 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpLogicalW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpLogicalW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCmpNA(char*  str, char*  comp, int  len) /* ../dlls/kernelbase/string.c:516 */
{
	TRACE("Enter StrCmpNA\n");
	return pStrCmpNA(str, comp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNA(void);  /* ../dlls/kernelbase/string.c:516 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpNCA(char*  str, char*  comp, int  len) /* ../dlls/kernelbase/string.c:528 */
{
	TRACE("Enter StrCmpNCA\n");
	return pStrCmpNCA(str, comp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNCA(void);  /* ../dlls/kernelbase/string.c:528 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNCA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNCA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpNCW(WCHAR*  str, WCHAR*  comp, int  len) /* ../dlls/kernelbase/string.c:533 */
{
	TRACE("Enter StrCmpNCW\n");
	return pStrCmpNCW(str, comp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNCW(void);  /* ../dlls/kernelbase/string.c:533 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNCW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNCW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCmpNIA(char*  str, char*  cmp, int  len) /* ../dlls/kernelbase/string.c:490 */
{
	TRACE("Enter StrCmpNIA\n");
	return pStrCmpNIA(str, cmp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNIA(void);  /* ../dlls/kernelbase/string.c:490 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpNICA(char*  str, char*  cmp, DWORD  len) /* ../dlls/kernelbase/string.c:212 */
{
	TRACE("Enter StrCmpNICA\n");
	return pStrCmpNICA(str, cmp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNICA(void);  /* ../dlls/kernelbase/string.c:212 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNICA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNICA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_StrCmpNICW(WCHAR*  str, WCHAR*  cmp, DWORD  len) /* ../dlls/kernelbase/string.c:217 */
{
	TRACE("Enter StrCmpNICW\n");
	return pStrCmpNICW(str, cmp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNICW(void);  /* ../dlls/kernelbase/string.c:217 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNICW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNICW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCmpNIW(WCHAR*  str, WCHAR*  comp, int  len) /* ../dlls/kernelbase/string.c:538 */
{
	TRACE("Enter StrCmpNIW\n");
	return pStrCmpNIW(str, comp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNIW(void);  /* ../dlls/kernelbase/string.c:538 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_StrCmpNW(WCHAR*  str, WCHAR*  comp, int  len) /* ../dlls/kernelbase/string.c:522 */
{
	TRACE("Enter StrCmpNW\n");
	return pStrCmpNW(str, comp, len);
}

extern WINAPI void wine32a_kernelbase_StrCmpNW(void);  /* ../dlls/kernelbase/string.c:522 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpNW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpNW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrCmpW(WCHAR*  str, WCHAR*  comp) /* ../dlls/kernelbase/string.c:544 */
{
	TRACE("Enter StrCmpW\n");
	return pStrCmpW(str, comp);
}

extern WINAPI void wine32a_kernelbase_StrCmpW(void);  /* ../dlls/kernelbase/string.c:544 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCmpW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCmpW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrCpyNW(WCHAR*  dst, WCHAR*  src, int  count) /* ../dlls/kernelbase/string.c:556 */
{
	TRACE("Enter StrCpyNW\n");
	return pStrCpyNW(dst, src, count);
}

extern WINAPI void wine32a_kernelbase_StrCpyNW(void);  /* ../dlls/kernelbase/string.c:556 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCpyNW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCpyNW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char* wine32b_kernelbase_StrCpyNXA(char*  dst, char*  src, int  len) /* ../dlls/kernelbase/string.c:1107 */
{
	TRACE("Enter StrCpyNXA\n");
	return pStrCpyNXA(dst, src, len);
}

extern WINAPI void wine32a_kernelbase_StrCpyNXA(void);  /* ../dlls/kernelbase/string.c:1107 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCpyNXA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCpyNXA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR* wine32b_kernelbase_StrCpyNXW(WCHAR*  dst, WCHAR*  src, int  len) /* ../dlls/kernelbase/string.c:1122 */
{
	TRACE("Enter StrCpyNXW\n");
	return pStrCpyNXW(dst, src, len);
}

extern WINAPI void wine32a_kernelbase_StrCpyNXW(void);  /* ../dlls/kernelbase/string.c:1122 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrCpyNXW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrCpyNXW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrDupA(char*  str) /* ../dlls/kernelbase/string.c:386 */
{
	TRACE("Enter StrDupA\n");
	return pStrDupA(str);
}

extern WINAPI void wine32a_kernelbase_StrDupA(void);  /* ../dlls/kernelbase/string.c:386 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrDupA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrDupA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrDupW(WCHAR*  str) /* ../dlls/kernelbase/string.c:407 */
{
	TRACE("Enter StrDupW\n");
	return pStrDupW(str);
}

extern WINAPI void wine32a_kernelbase_StrDupW(void);  /* ../dlls/kernelbase/string.c:407 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrDupW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrDupW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrIsIntlEqualA(BOOL  case_sensitive, char*  str, char*  cmp, int  len) /* ../dlls/kernelbase/string.c:1447 */
{
	TRACE("Enter StrIsIntlEqualA\n");
	return pStrIsIntlEqualA(case_sensitive, str, cmp, len);
}

extern WINAPI void wine32a_kernelbase_StrIsIntlEqualA(void);  /* ../dlls/kernelbase/string.c:1447 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrIsIntlEqualA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrIsIntlEqualA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrIsIntlEqualW(BOOL  case_sensitive, WCHAR*  str, WCHAR*  cmp, int  len) /* ../dlls/kernelbase/string.c:1463 */
{
	TRACE("Enter StrIsIntlEqualW\n");
	return pStrIsIntlEqualW(case_sensitive, str, cmp, len);
}

extern WINAPI void wine32a_kernelbase_StrIsIntlEqualW(void);  /* ../dlls/kernelbase/string.c:1463 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrIsIntlEqualW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrIsIntlEqualW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrPBrkA(char*  str, char*  match) /* ../dlls/kernelbase/string.c:829 */
{
	TRACE("Enter StrPBrkA\n");
	return pStrPBrkA(str, match);
}

extern WINAPI void wine32a_kernelbase_StrPBrkA(void);  /* ../dlls/kernelbase/string.c:829 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrPBrkA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrPBrkA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrPBrkW(WCHAR*  str, WCHAR*  match) /* ../dlls/kernelbase/string.c:846 */
{
	TRACE("Enter StrPBrkW\n");
	return pStrPBrkW(str, match);
}

extern WINAPI void wine32a_kernelbase_StrPBrkW(void);  /* ../dlls/kernelbase/string.c:846 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrPBrkW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrPBrkW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrRChrA(char*  str, char*  end, WORD  ch) /* ../dlls/kernelbase/string.c:699 */
{
	TRACE("Enter StrRChrA\n");
	return pStrRChrA(str, end, ch);
}

extern WINAPI void wine32a_kernelbase_StrRChrA(void);  /* ../dlls/kernelbase/string.c:699 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRChrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRChrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrRChrIA(char*  str, char*  end, WORD  ch) /* ../dlls/kernelbase/string.c:730 */
{
	TRACE("Enter StrRChrIA\n");
	return pStrRChrIA(str, end, ch);
}

extern WINAPI void wine32a_kernelbase_StrRChrIA(void);  /* ../dlls/kernelbase/string.c:730 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRChrIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRChrIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrRChrIW(WCHAR*  str, WCHAR*  end, WORD  ch) /* ../dlls/kernelbase/string.c:748 */
{
	TRACE("Enter StrRChrIW\n");
	return pStrRChrIW(str, end, ch);
}

extern WINAPI void wine32a_kernelbase_StrRChrIW(void);  /* ../dlls/kernelbase/string.c:748 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRChrIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRChrIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrRChrW(WCHAR*  str, WCHAR*  end, WORD  ch) /* ../dlls/kernelbase/string.c:716 */
{
	TRACE("Enter StrRChrW\n");
	return pStrRChrW(str, end, ch);
}

extern WINAPI void wine32a_kernelbase_StrRChrW(void);  /* ../dlls/kernelbase/string.c:716 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRChrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRChrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrRStrIA(char*  str, char*  end, char*  search) /* ../dlls/kernelbase/string.c:762 */
{
	TRACE("Enter StrRStrIA\n");
	return pStrRStrIA(str, end, search);
}

extern WINAPI void wine32a_kernelbase_StrRStrIA(void);  /* ../dlls/kernelbase/string.c:762 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRStrIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRStrIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrRStrIW(WCHAR*  str, WCHAR*  end, WCHAR*  search) /* ../dlls/kernelbase/string.c:799 */
{
	TRACE("Enter StrRStrIW\n");
	return pStrRStrIW(str, end, search);
}

extern WINAPI void wine32a_kernelbase_StrRStrIW(void);  /* ../dlls/kernelbase/string.c:799 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrRStrIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrRStrIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrSpnA(char*  str, char*  match) /* ../dlls/kernelbase/string.c:619 */
{
	TRACE("Enter StrSpnA\n");
	return pStrSpnA(str, match);
}

extern WINAPI void wine32a_kernelbase_StrSpnA(void);  /* ../dlls/kernelbase/string.c:619 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrSpnA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrSpnA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrSpnW(WCHAR*  str, WCHAR*  match) /* ../dlls/kernelbase/string.c:635 */
{
	TRACE("Enter StrSpnW\n");
	return pStrSpnW(str, match);
}

extern WINAPI void wine32a_kernelbase_StrSpnW(void);  /* ../dlls/kernelbase/string.c:635 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrSpnW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrSpnW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrStrA(char*  str, char*  search) /* ../dlls/kernelbase/string.c:440 */
{
	TRACE("Enter StrStrA\n");
	return pStrStrA(str, search);
}

extern WINAPI void wine32a_kernelbase_StrStrA(void);  /* ../dlls/kernelbase/string.c:440 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_StrStrIA(char*  str, char*  search) /* ../dlls/kernelbase/string.c:576 */
{
	TRACE("Enter StrStrIA\n");
	return pStrStrIA(str, search);
}

extern WINAPI void wine32a_kernelbase_StrStrIA(void);  /* ../dlls/kernelbase/string.c:576 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrIA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrIA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrStrIW(WCHAR*  str, WCHAR*  search) /* ../dlls/kernelbase/string.c:596 */
{
	TRACE("Enter StrStrIW\n");
	return pStrStrIW(str, search);
}

extern WINAPI void wine32a_kernelbase_StrStrIW(void);  /* ../dlls/kernelbase/string.c:596 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrStrNIW(WCHAR*  str, WCHAR*  search, UINT  max_len) /* ../dlls/kernelbase/string.c:496 */
{
	TRACE("Enter StrStrNIW\n");
	return pStrStrNIW(str, search, max_len);
}

extern WINAPI void wine32a_kernelbase_StrStrNIW(void);  /* ../dlls/kernelbase/string.c:496 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrNIW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrNIW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrStrNW(WCHAR*  str, WCHAR*  search, UINT  max_len) /* ../dlls/kernelbase/string.c:470 */
{
	TRACE("Enter StrStrNW\n");
	return pStrStrNW(str, search, max_len);
}

extern WINAPI void wine32a_kernelbase_StrStrNW(void);  /* ../dlls/kernelbase/string.c:470 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrNW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrNW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_StrStrW(WCHAR*  str, WCHAR*  search) /* ../dlls/kernelbase/string.c:460 */
{
	TRACE("Enter StrStrW\n");
	return pStrStrW(str, search);
}

extern WINAPI void wine32a_kernelbase_StrStrW(void);  /* ../dlls/kernelbase/string.c:460 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrStrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrStrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrToInt64ExA(char*  str, DWORD  flags, LONGLONG*  ret) /* ../dlls/kernelbase/string.c:928 */
{
	TRACE("Enter StrToInt64ExA\n");
	return pStrToInt64ExA(str, flags, ret);
}

extern WINAPI void wine32a_kernelbase_StrToInt64ExA(void);  /* ../dlls/kernelbase/string.c:928 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToInt64ExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToInt64ExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrToInt64ExW(WCHAR*  str, DWORD  flags, LONGLONG*  ret) /* ../dlls/kernelbase/string.c:992 */
{
	TRACE("Enter StrToInt64ExW\n");
	return pStrToInt64ExW(str, flags, ret);
}

extern WINAPI void wine32a_kernelbase_StrToInt64ExW(void);  /* ../dlls/kernelbase/string.c:992 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToInt64ExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToInt64ExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrToIntA(char*  str) /* ../dlls/kernelbase/string.c:1078 */
{
	TRACE("Enter StrToIntA\n");
	return pStrToIntA(str);
}

extern WINAPI void wine32a_kernelbase_StrToIntA(void);  /* ../dlls/kernelbase/string.c:1078 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToIntA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToIntA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrToIntExA(char*  str, DWORD  flags, INT*  ret) /* ../dlls/kernelbase/string.c:1054 */
{
	TRACE("Enter StrToIntExA\n");
	return pStrToIntExA(str, flags, ret);
}

extern WINAPI void wine32a_kernelbase_StrToIntExA(void);  /* ../dlls/kernelbase/string.c:1054 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToIntExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToIntExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrToIntExW(WCHAR*  str, DWORD  flags, INT*  ret) /* ../dlls/kernelbase/string.c:1066 */
{
	TRACE("Enter StrToIntExW\n");
	return pStrToIntExW(str, flags, ret);
}

extern WINAPI void wine32a_kernelbase_StrToIntExW(void);  /* ../dlls/kernelbase/string.c:1066 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToIntExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToIntExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_kernelbase_StrToIntW(WCHAR*  str) /* ../dlls/kernelbase/string.c:1093 */
{
	TRACE("Enter StrToIntW\n");
	return pStrToIntW(str);
}

extern WINAPI void wine32a_kernelbase_StrToIntW(void);  /* ../dlls/kernelbase/string.c:1093 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrToIntW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrToIntW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrTrimA(char*  str, char*  trim) /* ../dlls/kernelbase/string.c:852 */
{
	TRACE("Enter StrTrimA\n");
	return pStrTrimA(str, trim);
}

extern WINAPI void wine32a_kernelbase_StrTrimA(void);  /* ../dlls/kernelbase/string.c:852 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrTrimA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrTrimA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_StrTrimW(WCHAR*  str, WCHAR*  trim) /* ../dlls/kernelbase/string.c:890 */
{
	TRACE("Enter StrTrimW\n");
	return pStrTrimW(str, trim);
}

extern WINAPI void wine32a_kernelbase_StrTrimW(void);  /* ../dlls/kernelbase/string.c:890 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_StrTrimW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_StrTrimW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_SuspendThread(HANDLE  thread) /* ../dlls/kernelbase/thread.c:493 */
{
	TRACE("Enter SuspendThread\n");
	return pSuspendThread(thread);
}

extern WINAPI void wine32a_kernelbase_SuspendThread(void);  /* ../dlls/kernelbase/thread.c:493 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SuspendThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SuspendThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernelbase_SwitchToFiber(LPVOID  fiber) /* ../dlls/kernelbase/thread.c:924 */
{
	TRACE("Enter SwitchToFiber\n");
	return pSwitchToFiber(fiber);
}

extern WINAPI void wine32a_kernelbase_SwitchToFiber(void);  /* ../dlls/kernelbase/thread.c:924 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SwitchToFiber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SwitchToFiber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_SwitchToThread(void) /* ../dlls/kernelbase/thread.c:505 */
{
	TRACE("Enter SwitchToThread\n");
	return pSwitchToThread();
}

extern WINAPI void wine32a_kernelbase_SwitchToThread(void);  /* ../dlls/kernelbase/thread.c:505 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_SwitchToThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_SwitchToThread") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_TerminateProcess(HANDLE  handle, DWORD  exit_code) /* ../dlls/kernelbase/process.c:337 */
{
	TRACE("Enter TerminateProcess\n");
	return pTerminateProcess(handle, exit_code);
}

extern WINAPI void wine32a_kernelbase_TerminateProcess(void);  /* ../dlls/kernelbase/process.c:337 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TerminateProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TerminateProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_TerminateThread(HANDLE  handle, DWORD  exit_code) /* ../dlls/kernelbase/thread.c:514 */
{
	TRACE("Enter TerminateThread\n");
	return pTerminateThread(handle, exit_code);
}

extern WINAPI void wine32a_kernelbase_TerminateThread(void);  /* ../dlls/kernelbase/thread.c:514 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TerminateThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TerminateThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_TlsAlloc(void) /* ../dlls/kernelbase/thread.c:523 */
{
	TRACE("Enter TlsAlloc\n");
	return pTlsAlloc();
}

extern WINAPI void wine32a_kernelbase_TlsAlloc(void);  /* ../dlls/kernelbase/thread.c:523 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TlsAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TlsAlloc") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_TlsFree(DWORD  index) /* ../dlls/kernelbase/thread.c:560 */
{
	TRACE("Enter TlsFree\n");
	return pTlsFree(index);
}

extern WINAPI void wine32a_kernelbase_TlsFree(void);  /* ../dlls/kernelbase/thread.c:560 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TlsFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TlsFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernelbase_TlsGetValue(DWORD  index) /* ../dlls/kernelbase/thread.c:585 */
{
	TRACE("Enter TlsGetValue\n");
	return pTlsGetValue(index);
}

extern WINAPI void wine32a_kernelbase_TlsGetValue(void);  /* ../dlls/kernelbase/thread.c:585 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TlsGetValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TlsGetValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_TlsSetValue(DWORD  index, LPVOID  value) /* ../dlls/kernelbase/thread.c:604 */
{
	TRACE("Enter TlsSetValue\n");
	return pTlsSetValue(index, value);
}

extern WINAPI void wine32a_kernelbase_TlsSetValue(void);  /* ../dlls/kernelbase/thread.c:604 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TlsSetValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TlsSetValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_TransactNamedPipe(HANDLE  handle, LPVOID  write_buf, DWORD  write_size, LPVOID  read_buf, DWORD  read_size, LPDWORD  bytes_read, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/sync.c:1284 */
{
	TRACE("Enter TransactNamedPipe\n");
	return pTransactNamedPipe(handle, write_buf, write_size, read_buf, read_size, bytes_read, overlapped);
}

extern WINAPI void wine32a_kernelbase_TransactNamedPipe(void);  /* ../dlls/kernelbase/sync.c:1284 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TransactNamedPipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TransactNamedPipe") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_TrySubmitThreadpoolCallback(PTP_SIMPLE_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/kernelbase/thread.c:1137 */
{
	TRACE("Enter TrySubmitThreadpoolCallback\n");
	return pTrySubmitThreadpoolCallback(callback, userdata, environment);
}

extern WINAPI void wine32a_kernelbase_TrySubmitThreadpoolCallback(void);  /* ../dlls/kernelbase/thread.c:1137 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_TrySubmitThreadpoolCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_TrySubmitThreadpoolCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UnlockFile(HANDLE  file, DWORD  offset_low, DWORD  offset_high, DWORD  count_low, DWORD  count_high) /* ../dlls/kernelbase/file.c:1501 */
{
	TRACE("Enter UnlockFile\n");
	return pUnlockFile(file, offset_low, offset_high, count_low, count_high);
}

extern WINAPI void wine32a_kernelbase_UnlockFile(void);  /* ../dlls/kernelbase/file.c:1501 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UnlockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UnlockFile") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_UnlockFileEx(HANDLE  file, DWORD  reserved, DWORD  count_low, DWORD  count_high, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1517 */
{
	TRACE("Enter UnlockFileEx\n");
	return pUnlockFileEx(file, reserved, count_low, count_high, overlapped);
}

extern WINAPI void wine32a_kernelbase_UnlockFileEx(void);  /* ../dlls/kernelbase/file.c:1517 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UnlockFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UnlockFileEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_UnregisterWaitEx(HANDLE  handle, HANDLE  event) /* ../dlls/kernelbase/sync.c:216 */
{
	TRACE("Enter UnregisterWaitEx\n");
	return pUnregisterWaitEx(handle, event);
}

extern WINAPI void wine32a_kernelbase_UnregisterWaitEx(void);  /* ../dlls/kernelbase/sync.c:216 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UnregisterWaitEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UnregisterWaitEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UpdateProcThreadAttribute(struct _PROC_THREAD_ATTRIBUTE_LIST*  list, DWORD  flags, DWORD_PTR  attr, void*  value, SIZE_T  size, void*  prev_ret, SIZE_T*  size_ret) /* ../dlls/kernelbase/process.c:400 */
{
	TRACE("Enter UpdateProcThreadAttribute\n");
	return pUpdateProcThreadAttribute(list, flags, attr, value, size, prev_ret, size_ret);
}

extern WINAPI void wine32a_kernelbase_UpdateProcThreadAttribute(void);  /* ../dlls/kernelbase/process.c:400 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UpdateProcThreadAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UpdateProcThreadAttribute") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_UrlApplySchemeA(char*  url, char*  out, DWORD*  out_len, DWORD  flags) /* ../dlls/kernelbase/path.c:3876 */
{
	TRACE("Enter UrlApplySchemeA\n");
	return pUrlApplySchemeA(url, out, out_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlApplySchemeA(void);  /* ../dlls/kernelbase/path.c:3876 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlApplySchemeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlApplySchemeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlApplySchemeW(WCHAR*  url, WCHAR*  out, DWORD*  length, DWORD  flags) /* ../dlls/kernelbase/path.c:4032 */
{
	TRACE("Enter UrlApplySchemeW\n");
	return pUrlApplySchemeW(url, out, length, flags);
}

extern WINAPI void wine32a_kernelbase_UrlApplySchemeW(void);  /* ../dlls/kernelbase/path.c:4032 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlApplySchemeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlApplySchemeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlCanonicalizeA(char*  src_url, char*  canonicalized, DWORD*  canonicalized_len, DWORD  flags) /* ../dlls/kernelbase/path.c:3494 */
{
	TRACE("Enter UrlCanonicalizeA\n");
	return pUrlCanonicalizeA(src_url, canonicalized, canonicalized_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlCanonicalizeA(void);  /* ../dlls/kernelbase/path.c:3494 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCanonicalizeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCanonicalizeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlCanonicalizeW(WCHAR*  src_url, WCHAR*  canonicalized, DWORD*  canonicalized_len, DWORD  flags) /* ../dlls/kernelbase/path.c:3522 */
{
	TRACE("Enter UrlCanonicalizeW\n");
	return pUrlCanonicalizeW(src_url, canonicalized, canonicalized_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlCanonicalizeW(void);  /* ../dlls/kernelbase/path.c:3522 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCanonicalizeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCanonicalizeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlCombineA(char*  base, char*  relative, char*  combined, DWORD*  combined_len, DWORD  flags) /* ../dlls/kernelbase/path.c:4690 */
{
	TRACE("Enter UrlCombineA\n");
	return pUrlCombineA(base, relative, combined, combined_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlCombineA(void);  /* ../dlls/kernelbase/path.c:4690 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCombineA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCombineA") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_UrlCombineW(WCHAR*  baseW, WCHAR*  relativeW, WCHAR*  combined, DWORD*  combined_len, DWORD  flags) /* ../dlls/kernelbase/path.c:4730 */
{
	TRACE("Enter UrlCombineW\n");
	return pUrlCombineW(baseW, relativeW, combined, combined_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlCombineW(void);  /* ../dlls/kernelbase/path.c:4730 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCombineW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCombineW") "\n"
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

extern WINAPI INT wine32b_kernelbase_UrlCompareA(char*  url1, char*  url2, BOOL  ignore_slash) /* ../dlls/kernelbase/path.c:4083 */
{
	TRACE("Enter UrlCompareA\n");
	return pUrlCompareA(url1, url2, ignore_slash);
}

extern WINAPI void wine32a_kernelbase_UrlCompareA(void);  /* ../dlls/kernelbase/path.c:4083 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCompareA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCompareA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_UrlCompareW(WCHAR*  url1, WCHAR*  url2, BOOL  ignore_slash) /* ../dlls/kernelbase/path.c:4102 */
{
	TRACE("Enter UrlCompareW\n");
	return pUrlCompareW(url1, url2, ignore_slash);
}

extern WINAPI void wine32a_kernelbase_UrlCompareW(void);  /* ../dlls/kernelbase/path.c:4102 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCompareW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCompareW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlCreateFromPathA(char*  path, char*  url, DWORD*  url_len, DWORD  reserved) /* ../dlls/kernelbase/path.c:4636 */
{
	TRACE("Enter UrlCreateFromPathA\n");
	return pUrlCreateFromPathA(path, url, url_len, reserved);
}

extern WINAPI void wine32a_kernelbase_UrlCreateFromPathA(void);  /* ../dlls/kernelbase/path.c:4636 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCreateFromPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCreateFromPathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlCreateFromPathW(WCHAR*  path, WCHAR*  url, DWORD*  url_len, DWORD  reserved) /* ../dlls/kernelbase/path.c:4674 */
{
	TRACE("Enter UrlCreateFromPathW\n");
	return pUrlCreateFromPathW(path, url, url_len, reserved);
}

extern WINAPI void wine32a_kernelbase_UrlCreateFromPathW(void);  /* ../dlls/kernelbase/path.c:4674 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlCreateFromPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlCreateFromPathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlEscapeA(char*  url, char*  escaped, DWORD*  escaped_len, DWORD  flags) /* ../dlls/kernelbase/path.c:3254 */
{
	TRACE("Enter UrlEscapeA\n");
	return pUrlEscapeA(url, escaped, escaped_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlEscapeA(void);  /* ../dlls/kernelbase/path.c:3254 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlEscapeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlEscapeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlEscapeW(WCHAR*  url, WCHAR*  escaped, DWORD*  escaped_len, DWORD  flags) /* ../dlls/kernelbase/path.c:3301 */
{
	TRACE("Enter UrlEscapeW\n");
	return pUrlEscapeW(url, escaped, escaped_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlEscapeW(void);  /* ../dlls/kernelbase/path.c:3301 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlEscapeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlEscapeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlFixupW(WCHAR*  url, WCHAR*  translatedUrl, DWORD  maxChars) /* ../dlls/kernelbase/path.c:4122 */
{
	TRACE("Enter UrlFixupW\n");
	return pUrlFixupW(url, translatedUrl, maxChars);
}

extern WINAPI void wine32a_kernelbase_UrlFixupW(void);  /* ../dlls/kernelbase/path.c:4122 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlFixupW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlFixupW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPCSTR wine32b_kernelbase_UrlGetLocationA(char*  url) /* ../dlls/kernelbase/path.c:4139 */
{
	TRACE("Enter UrlGetLocationA\n");
	return pUrlGetLocationA(url);
}

extern WINAPI void wine32a_kernelbase_UrlGetLocationA(void);  /* ../dlls/kernelbase/path.c:4139 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlGetLocationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlGetLocationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPCWSTR wine32b_kernelbase_UrlGetLocationW(WCHAR*  url) /* ../dlls/kernelbase/path.c:4154 */
{
	TRACE("Enter UrlGetLocationW\n");
	return pUrlGetLocationW(url);
}

extern WINAPI void wine32a_kernelbase_UrlGetLocationW(void);  /* ../dlls/kernelbase/path.c:4154 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlGetLocationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlGetLocationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlGetPartA(char*  url, char*  out, DWORD*  out_len, DWORD  part, DWORD  flags) /* ../dlls/kernelbase/path.c:4170 */
{
	TRACE("Enter UrlGetPartA\n");
	return pUrlGetPartA(url, out, out_len, part, flags);
}

extern WINAPI void wine32a_kernelbase_UrlGetPartA(void);  /* ../dlls/kernelbase/path.c:4170 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlGetPartA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlGetPartA") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_UrlGetPartW(WCHAR*  url, WCHAR*  out, DWORD*  out_len, DWORD  part, DWORD  flags) /* ../dlls/kernelbase/path.c:4378 */
{
	TRACE("Enter UrlGetPartW\n");
	return pUrlGetPartW(url, out, out_len, part, flags);
}

extern WINAPI void wine32a_kernelbase_UrlGetPartW(void);  /* ../dlls/kernelbase/path.c:4378 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlGetPartW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlGetPartW") "\n"
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

extern WINAPI HRESULT wine32b_kernelbase_UrlHashA(char*  url, unsigned char*  dest, DWORD  dest_len) /* ../dlls/kernelbase/path.c:5044 */
{
	TRACE("Enter UrlHashA\n");
	return pUrlHashA(url, dest, dest_len);
}

extern WINAPI void wine32a_kernelbase_UrlHashA(void);  /* ../dlls/kernelbase/path.c:5044 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlHashA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlHashA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlHashW(WCHAR*  url, unsigned char*  dest, DWORD  dest_len) /* ../dlls/kernelbase/path.c:5053 */
{
	TRACE("Enter UrlHashW\n");
	return pUrlHashW(url, dest, dest_len);
}

extern WINAPI void wine32a_kernelbase_UrlHashW(void);  /* ../dlls/kernelbase/path.c:5053 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlHashW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlHashW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsA(char*  url, URLIS  Urlis) /* ../dlls/kernelbase/path.c:4523 */
{
	TRACE("Enter UrlIsA\n");
	return pUrlIsA(url, Urlis);
}

extern WINAPI void wine32a_kernelbase_UrlIsA(void);  /* ../dlls/kernelbase/path.c:4523 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsNoHistoryA(char*  url) /* ../dlls/kernelbase/path.c:4626 */
{
	TRACE("Enter UrlIsNoHistoryA\n");
	return pUrlIsNoHistoryA(url);
}

extern WINAPI void wine32a_kernelbase_UrlIsNoHistoryA(void);  /* ../dlls/kernelbase/path.c:4626 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsNoHistoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsNoHistoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsNoHistoryW(WCHAR*  url) /* ../dlls/kernelbase/path.c:4631 */
{
	TRACE("Enter UrlIsNoHistoryW\n");
	return pUrlIsNoHistoryW(url);
}

extern WINAPI void wine32a_kernelbase_UrlIsNoHistoryW(void);  /* ../dlls/kernelbase/path.c:4631 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsNoHistoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsNoHistoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsOpaqueA(char*  url) /* ../dlls/kernelbase/path.c:4616 */
{
	TRACE("Enter UrlIsOpaqueA\n");
	return pUrlIsOpaqueA(url);
}

extern WINAPI void wine32a_kernelbase_UrlIsOpaqueA(void);  /* ../dlls/kernelbase/path.c:4616 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsOpaqueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsOpaqueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsOpaqueW(WCHAR*  url) /* ../dlls/kernelbase/path.c:4621 */
{
	TRACE("Enter UrlIsOpaqueW\n");
	return pUrlIsOpaqueW(url);
}

extern WINAPI void wine32a_kernelbase_UrlIsOpaqueW(void);  /* ../dlls/kernelbase/path.c:4621 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsOpaqueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsOpaqueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_UrlIsW(WCHAR*  url, URLIS  Urlis) /* ../dlls/kernelbase/path.c:4569 */
{
	TRACE("Enter UrlIsW\n");
	return pUrlIsW(url, Urlis);
}

extern WINAPI void wine32a_kernelbase_UrlIsW(void);  /* ../dlls/kernelbase/path.c:4569 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlIsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlIsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlUnescapeA(char*  url, char*  unescaped, DWORD*  unescaped_len, DWORD  flags) /* ../dlls/kernelbase/path.c:2853 */
{
	TRACE("Enter UrlUnescapeA\n");
	return pUrlUnescapeA(url, unescaped, unescaped_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlUnescapeA(void);  /* ../dlls/kernelbase/path.c:2853 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlUnescapeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlUnescapeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernelbase_UrlUnescapeW(WCHAR*  url, WCHAR*  unescaped, DWORD*  unescaped_len, DWORD  flags) /* ../dlls/kernelbase/path.c:2918 */
{
	TRACE("Enter UrlUnescapeW\n");
	return pUrlUnescapeW(url, unescaped, unescaped_len, flags);
}

extern WINAPI void wine32a_kernelbase_UrlUnescapeW(void);  /* ../dlls/kernelbase/path.c:2918 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_UrlUnescapeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_UrlUnescapeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_VerFindFileA(DWORD  flags, LPCSTR  filename, LPCSTR  win_dir, LPCSTR  app_dir, LPSTR  cur_dir, PUINT  curdir_len, LPSTR  dest, PUINT  dest_len) /* ../dlls/kernelbase/version.c:1177 */
{
	TRACE("Enter VerFindFileA\n");
	return pVerFindFileA(flags, filename, win_dir, app_dir, cur_dir, curdir_len, dest, dest_len);
}

extern WINAPI void wine32a_kernelbase_VerFindFileA(void);  /* ../dlls/kernelbase/version.c:1177 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_VerFindFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_VerFindFileA") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_VerFindFileW(DWORD  flags, LPCWSTR  filename, LPCWSTR  win_dir, LPCWSTR  app_dir, LPWSTR  cur_dir, PUINT  curdir_len, LPWSTR  dest, PUINT  dest_len) /* ../dlls/kernelbase/version.c:1265 */
{
	TRACE("Enter VerFindFileW\n");
	return pVerFindFileW(flags, filename, win_dir, app_dir, cur_dir, curdir_len, dest, dest_len);
}

extern WINAPI void wine32a_kernelbase_VerFindFileW(void);  /* ../dlls/kernelbase/version.c:1265 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_VerFindFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_VerFindFileW") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_VerQueryValueA(LPCVOID  pBlock, LPCSTR  lpSubBlock, LPVOID*  lplpBuffer, PUINT  puLen) /* ../dlls/kernelbase/version.c:989 */
{
	TRACE("Enter VerQueryValueA\n");
	return pVerQueryValueA(pBlock, lpSubBlock, lplpBuffer, puLen);
}

extern WINAPI void wine32a_kernelbase_VerQueryValueA(void);  /* ../dlls/kernelbase/version.c:989 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_VerQueryValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_VerQueryValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_VerQueryValueW(LPCVOID  pBlock, LPCWSTR  lpSubBlock, LPVOID*  lplpBuffer, PUINT  puLen) /* ../dlls/kernelbase/version.c:1045 */
{
	TRACE("Enter VerQueryValueW\n");
	return pVerQueryValueW(pBlock, lpSubBlock, lplpBuffer, puLen);
}

extern WINAPI void wine32a_kernelbase_VerQueryValueW(void);  /* ../dlls/kernelbase/version.c:1045 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_VerQueryValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_VerQueryValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_WaitForMultipleObjects(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout) /* ../dlls/kernelbase/sync.c:243 */
{
	TRACE("Enter WaitForMultipleObjects\n");
	return pWaitForMultipleObjects(count, handles, wait_all, timeout);
}

extern WINAPI void wine32a_kernelbase_WaitForMultipleObjects(void);  /* ../dlls/kernelbase/sync.c:243 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitForMultipleObjects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitForMultipleObjects") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_WaitForMultipleObjectsEx(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout, BOOL  alertable) /* ../dlls/kernelbase/sync.c:253 */
{
	TRACE("Enter WaitForMultipleObjectsEx\n");
	return pWaitForMultipleObjectsEx(count, handles, wait_all, timeout, alertable);
}

extern WINAPI void wine32a_kernelbase_WaitForMultipleObjectsEx(void);  /* ../dlls/kernelbase/sync.c:253 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitForMultipleObjectsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitForMultipleObjectsEx") "\n"
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

extern WINAPI DWORD wine32b_kernelbase_WaitForSingleObject(HANDLE  handle, DWORD  timeout) /* ../dlls/kernelbase/sync.c:225 */
{
	TRACE("Enter WaitForSingleObject\n");
	return pWaitForSingleObject(handle, timeout);
}

extern WINAPI void wine32a_kernelbase_WaitForSingleObject(void);  /* ../dlls/kernelbase/sync.c:225 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitForSingleObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernelbase_WaitForSingleObjectEx(HANDLE  handle, DWORD  timeout, BOOL  alertable) /* ../dlls/kernelbase/sync.c:234 */
{
	TRACE("Enter WaitForSingleObjectEx\n");
	return pWaitForSingleObjectEx(handle, timeout, alertable);
}

extern WINAPI void wine32a_kernelbase_WaitForSingleObjectEx(void);  /* ../dlls/kernelbase/sync.c:234 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitForSingleObjectEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitForSingleObjectEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_WaitNamedPipeW(LPCWSTR  name, DWORD  timeout) /* ../dlls/kernelbase/sync.c:1323 */
{
	TRACE("Enter WaitNamedPipeW\n");
	return pWaitNamedPipeW(name, timeout);
}

extern WINAPI void wine32a_kernelbase_WaitNamedPipeW(void);  /* ../dlls/kernelbase/sync.c:1323 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitNamedPipeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitNamedPipeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_WaitOnAddress(volatile void*  addr, void*  cmp, SIZE_T  size, DWORD  timeout) /* ../dlls/kernelbase/main.c:187 */
{
	TRACE("Enter WaitOnAddress\n");
	return pWaitOnAddress(addr, cmp, size, timeout);
}

extern WINAPI void wine32a_kernelbase_WaitOnAddress(void);  /* ../dlls/kernelbase/main.c:187 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WaitOnAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WaitOnAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_Wow64DisableWow64FsRedirection(PVOID*  old_value) /* ../dlls/kernelbase/file.c:785 */
{
	TRACE("Enter Wow64DisableWow64FsRedirection\n");
	return pWow64DisableWow64FsRedirection(old_value);
}

extern WINAPI void wine32a_kernelbase_Wow64DisableWow64FsRedirection(void);  /* ../dlls/kernelbase/file.c:785 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_Wow64DisableWow64FsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_Wow64DisableWow64FsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_Wow64RevertWow64FsRedirection(PVOID  old_value) /* ../dlls/kernelbase/file.c:794 */
{
	TRACE("Enter Wow64RevertWow64FsRedirection\n");
	return pWow64RevertWow64FsRedirection(old_value);
}

extern WINAPI void wine32a_kernelbase_Wow64RevertWow64FsRedirection(void);  /* ../dlls/kernelbase/file.c:794 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_Wow64RevertWow64FsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_Wow64RevertWow64FsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernelbase_WriteFile(HANDLE  file, LPCVOID  buffer, DWORD  count, LPDWORD  result, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1534 */
{
	TRACE("Enter WriteFile\n");
	return pWriteFile(file, buffer, count, result, overlapped);
}

extern WINAPI void wine32a_kernelbase_WriteFile(void);  /* ../dlls/kernelbase/file.c:1534 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WriteFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WriteFile") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_WriteFileEx(HANDLE  file, LPCVOID  buffer, DWORD  count, LPOVERLAPPED  overlapped, LPOVERLAPPED_COMPLETION_ROUTINE  completion) /* ../dlls/kernelbase/file.c:1583 */
{
	TRACE("Enter WriteFileEx\n");
	return pWriteFileEx(file, buffer, count, overlapped, completion);
}

extern WINAPI void wine32a_kernelbase_WriteFileEx(void);  /* ../dlls/kernelbase/file.c:1583 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WriteFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WriteFileEx") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_WriteFileGather(HANDLE  file, FILE_SEGMENT_ELEMENT*  segments, DWORD  count, LPDWORD  reserved, LPOVERLAPPED  overlapped) /* ../dlls/kernelbase/file.c:1614 */
{
	TRACE("Enter WriteFileGather\n");
	return pWriteFileGather(file, segments, count, reserved, overlapped);
}

extern WINAPI void wine32a_kernelbase_WriteFileGather(void);  /* ../dlls/kernelbase/file.c:1614 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_WriteFileGather,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_WriteFileGather") "\n"
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

extern WINAPI BOOL wine32b_kernelbase_ZombifyActCtx(HANDLE  context) /* ../dlls/kernelbase/loader.c:876 */
{
	TRACE("Enter ZombifyActCtx\n");
	return pZombifyActCtx(context);
}

extern WINAPI void wine32a_kernelbase_ZombifyActCtx(void);  /* ../dlls/kernelbase/loader.c:876 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_ZombifyActCtx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_ZombifyActCtx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrcmpA(LPCSTR  str1, LPCSTR  str2) /* ../dlls/kernelbase/string.c:68 */
{
	TRACE("Enter lstrcmpA\n");
	return plstrcmpA(str1, str2);
}

extern WINAPI void wine32a_kernelbase_lstrcmpA(void);  /* ../dlls/kernelbase/string.c:68 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcmpA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcmpA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrcmpW(LPCWSTR  str1, LPCWSTR  str2) /* ../dlls/kernelbase/string.c:76 */
{
	TRACE("Enter lstrcmpW\n");
	return plstrcmpW(str1, str2);
}

extern WINAPI void wine32a_kernelbase_lstrcmpW(void);  /* ../dlls/kernelbase/string.c:76 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcmpW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcmpW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrcmpiA(LPCSTR  str1, LPCSTR  str2) /* ../dlls/kernelbase/string.c:84 */
{
	TRACE("Enter lstrcmpiA\n");
	return plstrcmpiA(str1, str2);
}

extern WINAPI void wine32a_kernelbase_lstrcmpiA(void);  /* ../dlls/kernelbase/string.c:84 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcmpiA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcmpiA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrcmpiW(LPCWSTR  str1, LPCWSTR  str2) /* ../dlls/kernelbase/string.c:92 */
{
	TRACE("Enter lstrcmpiW\n");
	return plstrcmpiW(str1, str2);
}

extern WINAPI void wine32a_kernelbase_lstrcmpiW(void);  /* ../dlls/kernelbase/string.c:92 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcmpiW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcmpiW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernelbase_lstrcpynA(LPSTR  dst, LPCSTR  src, INT  n) /* ../dlls/kernelbase/string.c:100 */
{
	TRACE("Enter lstrcpynA\n");
	return plstrcpynA(dst, src, n);
}

extern WINAPI void wine32a_kernelbase_lstrcpynA(void);  /* ../dlls/kernelbase/string.c:100 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcpynA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcpynA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernelbase_lstrcpynW(LPWSTR  dst, LPCWSTR  src, INT  n) /* ../dlls/kernelbase/string.c:130 */
{
	TRACE("Enter lstrcpynW\n");
	return plstrcpynW(dst, src, n);
}

extern WINAPI void wine32a_kernelbase_lstrcpynW(void);  /* ../dlls/kernelbase/string.c:130 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrcpynW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrcpynW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrlenA(LPCSTR  str) /* ../dlls/kernelbase/string.c:160 */
{
	TRACE("Enter lstrlenA\n");
	return plstrlenA(str);
}

extern WINAPI void wine32a_kernelbase_lstrlenA(void);  /* ../dlls/kernelbase/string.c:160 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrlenA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrlenA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernelbase_lstrlenW(LPCWSTR  str) /* ../dlls/kernelbase/string.c:176 */
{
	TRACE("Enter lstrlenW\n");
	return plstrlenW(str);
}

extern WINAPI void wine32a_kernelbase_lstrlenW(void);  /* ../dlls/kernelbase/string.c:176 */
__ASM_GLOBAL_FUNC(wine32a_kernelbase_lstrlenW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernelbase_lstrlenW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
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

void wine_thunk_initialize_kernelbase(void)
{
	HMODULE library = LoadLibraryA("kernelbase.dll");
	HMODULE library_ntdll = LoadLibraryA("ntdll.dll");
	HMODULE library_kernel32 = LoadLibraryA("kernel32.dll");
	pAccessCheck = (void *)GetProcAddress(library, "AccessCheck");
	pAccessCheckAndAuditAlarmW = (void *)GetProcAddress(library, "AccessCheckAndAuditAlarmW");
	pAccessCheckByType = (void *)GetProcAddress(library, "AccessCheckByType");
	pAcquireSRWLockExclusive = (void *)GetProcAddress(library, "AcquireSRWLockExclusive");
	pextAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockExclusive");
	pAcquireSRWLockShared = (void *)GetProcAddress(library, "AcquireSRWLockShared");
	pextAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockShared");
	pActivateActCtx = (void *)GetProcAddress(library, "ActivateActCtx");
	pAddAccessAllowedAce = (void *)GetProcAddress(library, "AddAccessAllowedAce");
	pAddAccessAllowedAceEx = (void *)GetProcAddress(library, "AddAccessAllowedAceEx");
	pAddAccessAllowedObjectAce = (void *)GetProcAddress(library, "AddAccessAllowedObjectAce");
	pAddAccessDeniedAce = (void *)GetProcAddress(library, "AddAccessDeniedAce");
	pAddAccessDeniedAceEx = (void *)GetProcAddress(library, "AddAccessDeniedAceEx");
	pAddAccessDeniedObjectAce = (void *)GetProcAddress(library, "AddAccessDeniedObjectAce");
	pAddAce = (void *)GetProcAddress(library, "AddAce");
	pAddAuditAccessAce = (void *)GetProcAddress(library, "AddAuditAccessAce");
	pAddAuditAccessAceEx = (void *)GetProcAddress(library, "AddAuditAccessAceEx");
	pAddAuditAccessObjectAce = (void *)GetProcAddress(library, "AddAuditAccessObjectAce");
	pAddDllDirectory = (void *)GetProcAddress(library, "AddDllDirectory");
	pextAddDllDirectory = (void *)GetProcAddress(library_kernel32, "AddDllDirectory");
	pAddMandatoryAce = (void *)GetProcAddress(library, "AddMandatoryAce");
	pAddRefActCtx = (void *)GetProcAddress(library, "AddRefActCtx");
	pAddVectoredContinueHandler = (void *)GetProcAddress(library, "AddVectoredContinueHandler");
	pextAddVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredContinueHandler");
	pAddVectoredExceptionHandler = (void *)GetProcAddress(library, "AddVectoredExceptionHandler");
	pextAddVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredExceptionHandler");
	pAdjustTokenGroups = (void *)GetProcAddress(library, "AdjustTokenGroups");
	pAdjustTokenPrivileges = (void *)GetProcAddress(library, "AdjustTokenPrivileges");
	pAllocConsole = (void *)GetProcAddress(library, "AllocConsole");
	pextAllocConsole = (void *)GetProcAddress(library_kernel32, "AllocConsole");
	pAllocateAndInitializeSid = (void *)GetProcAddress(library, "AllocateAndInitializeSid");
	pAllocateLocallyUniqueId = (void *)GetProcAddress(library, "AllocateLocallyUniqueId");
	pAllocateUserPhysicalPages = (void *)GetProcAddress(library, "AllocateUserPhysicalPages");
	pextAllocateUserPhysicalPages = (void *)GetProcAddress(library_kernel32, "AllocateUserPhysicalPages");
	pAppPolicyGetProcessTerminationMethod = (void *)GetProcAddress(library, "AppPolicyGetProcessTerminationMethod");
	pAppPolicyGetShowDeveloperDiagnostic = (void *)GetProcAddress(library, "AppPolicyGetShowDeveloperDiagnostic");
	pAppPolicyGetThreadInitializationType = (void *)GetProcAddress(library, "AppPolicyGetThreadInitializationType");
	pAppPolicyGetWindowingModel = (void *)GetProcAddress(library, "AppPolicyGetWindowingModel");
	pAreAllAccessesGranted = (void *)GetProcAddress(library, "AreAllAccessesGranted");
	pAreAnyAccessesGranted = (void *)GetProcAddress(library, "AreAnyAccessesGranted");
	pAreFileApisANSI = (void *)GetProcAddress(library, "AreFileApisANSI");
	pAttachConsole = (void *)GetProcAddress(library, "AttachConsole");
	pextAttachConsole = (void *)GetProcAddress(library_kernel32, "AttachConsole");
	pBaseFlushAppcompatCache = (void *)GetProcAddress(library, "BaseFlushAppcompatCache");
	pextBaseFlushAppcompatCache = (void *)GetProcAddress(library_kernel32, "BaseFlushAppcompatCache");
	pBaseGetNamedObjectDirectory = (void *)GetProcAddress(library, "BaseGetNamedObjectDirectory");
	pBeep = (void *)GetProcAddress(library, "Beep");
	pextBeep = (void *)GetProcAddress(library_kernel32, "Beep");
	pCallNamedPipeW = (void *)GetProcAddress(library, "CallNamedPipeW");
	pCallbackMayRunLong = (void *)GetProcAddress(library, "CallbackMayRunLong");
	pCancelIo = (void *)GetProcAddress(library, "CancelIo");
	pCancelIoEx = (void *)GetProcAddress(library, "CancelIoEx");
	pCancelSynchronousIo = (void *)GetProcAddress(library, "CancelSynchronousIo");
	pCancelWaitableTimer = (void *)GetProcAddress(library, "CancelWaitableTimer");
	pChangeTimerQueueTimer = (void *)GetProcAddress(library, "ChangeTimerQueueTimer");
	pCharLowerA = (void *)GetProcAddress(library, "CharLowerA");
	pCharLowerBuffA = (void *)GetProcAddress(library, "CharLowerBuffA");
	pCharLowerBuffW = (void *)GetProcAddress(library, "CharLowerBuffW");
	pCharLowerW = (void *)GetProcAddress(library, "CharLowerW");
	pCharNextA = (void *)GetProcAddress(library, "CharNextA");
	pCharNextExA = (void *)GetProcAddress(library, "CharNextExA");
	pCharNextW = (void *)GetProcAddress(library, "CharNextW");
	pCharPrevA = (void *)GetProcAddress(library, "CharPrevA");
	pCharPrevExA = (void *)GetProcAddress(library, "CharPrevExA");
	pCharPrevW = (void *)GetProcAddress(library, "CharPrevW");
	pCharUpperA = (void *)GetProcAddress(library, "CharUpperA");
	pCharUpperBuffA = (void *)GetProcAddress(library, "CharUpperBuffA");
	pCharUpperBuffW = (void *)GetProcAddress(library, "CharUpperBuffW");
	pCharUpperW = (void *)GetProcAddress(library, "CharUpperW");
	pCheckRemoteDebuggerPresent = (void *)GetProcAddress(library, "CheckRemoteDebuggerPresent");
	pextCheckRemoteDebuggerPresent = (void *)GetProcAddress(library_kernel32, "CheckRemoteDebuggerPresent");
	pCheckTokenMembership = (void *)GetProcAddress(library, "CheckTokenMembership");
	pChrCmpIA = (void *)GetProcAddress(library, "ChrCmpIA");
	pChrCmpIW = (void *)GetProcAddress(library, "ChrCmpIW");
	pClearCommBreak = (void *)GetProcAddress(library, "ClearCommBreak");
	pextClearCommBreak = (void *)GetProcAddress(library_kernel32, "ClearCommBreak");
	pClearCommError = (void *)GetProcAddress(library, "ClearCommError");
	pextClearCommError = (void *)GetProcAddress(library_kernel32, "ClearCommError");
	pCloseHandle = (void *)GetProcAddress(library, "CloseHandle");
	pextCloseHandle = (void *)GetProcAddress(library_kernel32, "CloseHandle");
	pCloseThreadpool = (void *)GetProcAddress(library, "CloseThreadpool");
	pextCloseThreadpool = (void *)GetProcAddress(library_ntdll, "TpReleasePool");
	pCloseThreadpoolCleanupGroup = (void *)GetProcAddress(library, "CloseThreadpoolCleanupGroup");
	pextCloseThreadpoolCleanupGroup = (void *)GetProcAddress(library_ntdll, "TpReleaseCleanupGroup");
	pCloseThreadpoolCleanupGroupMembers = (void *)GetProcAddress(library, "CloseThreadpoolCleanupGroupMembers");
	pextCloseThreadpoolCleanupGroupMembers = (void *)GetProcAddress(library_ntdll, "TpReleaseCleanupGroupMembers");
	pCloseThreadpoolTimer = (void *)GetProcAddress(library, "CloseThreadpoolTimer");
	pextCloseThreadpoolTimer = (void *)GetProcAddress(library_ntdll, "TpReleaseTimer");
	pCloseThreadpoolWait = (void *)GetProcAddress(library, "CloseThreadpoolWait");
	pextCloseThreadpoolWait = (void *)GetProcAddress(library_ntdll, "TpReleaseWait");
	pCloseThreadpoolWork = (void *)GetProcAddress(library, "CloseThreadpoolWork");
	pextCloseThreadpoolWork = (void *)GetProcAddress(library_ntdll, "TpReleaseWork");
	pCompareFileTime = (void *)GetProcAddress(library, "CompareFileTime");
	pextCompareFileTime = (void *)GetProcAddress(library_kernel32, "CompareFileTime");
	pCompareStringA = (void *)GetProcAddress(library, "CompareStringA");
	pextCompareStringA = (void *)GetProcAddress(library_kernel32, "CompareStringA");
	pCompareStringEx = (void *)GetProcAddress(library, "CompareStringEx");
	pextCompareStringEx = (void *)GetProcAddress(library_kernel32, "CompareStringEx");
	pCompareStringOrdinal = (void *)GetProcAddress(library, "CompareStringOrdinal");
	pextCompareStringOrdinal = (void *)GetProcAddress(library_kernel32, "CompareStringOrdinal");
	pCompareStringW = (void *)GetProcAddress(library, "CompareStringW");
	pextCompareStringW = (void *)GetProcAddress(library_kernel32, "CompareStringW");
	pConnectNamedPipe = (void *)GetProcAddress(library, "ConnectNamedPipe");
	pContinueDebugEvent = (void *)GetProcAddress(library, "ContinueDebugEvent");
	pextContinueDebugEvent = (void *)GetProcAddress(library_kernel32, "ContinueDebugEvent");
	pConvertDefaultLocale = (void *)GetProcAddress(library, "ConvertDefaultLocale");
	pextConvertDefaultLocale = (void *)GetProcAddress(library_kernel32, "ConvertDefaultLocale");
	pConvertFiberToThread = (void *)GetProcAddress(library, "ConvertFiberToThread");
	pConvertThreadToFiber = (void *)GetProcAddress(library, "ConvertThreadToFiber");
	pConvertThreadToFiberEx = (void *)GetProcAddress(library, "ConvertThreadToFiberEx");
	pConvertToAutoInheritPrivateObjectSecurity = (void *)GetProcAddress(library, "ConvertToAutoInheritPrivateObjectSecurity");
	pCopyFileExW = (void *)GetProcAddress(library, "CopyFileExW");
	pextCopyFileExW = (void *)GetProcAddress(library_kernel32, "CopyFileExW");
	pCopyFileW = (void *)GetProcAddress(library, "CopyFileW");
	pextCopyFileW = (void *)GetProcAddress(library_kernel32, "CopyFileW");
	pCopySid = (void *)GetProcAddress(library, "CopySid");
	pCreateActCtxW = (void *)GetProcAddress(library, "CreateActCtxW");
	pCreateConsoleScreenBuffer = (void *)GetProcAddress(library, "CreateConsoleScreenBuffer");
	pextCreateConsoleScreenBuffer = (void *)GetProcAddress(library_kernel32, "CreateConsoleScreenBuffer");
	pCreateDirectoryA = (void *)GetProcAddress(library, "CreateDirectoryA");
	pCreateDirectoryExW = (void *)GetProcAddress(library, "CreateDirectoryExW");
	pCreateDirectoryW = (void *)GetProcAddress(library, "CreateDirectoryW");
	pCreateEventA = (void *)GetProcAddress(library, "CreateEventA");
	pCreateEventExA = (void *)GetProcAddress(library, "CreateEventExA");
	pCreateEventExW = (void *)GetProcAddress(library, "CreateEventExW");
	pCreateEventW = (void *)GetProcAddress(library, "CreateEventW");
	pCreateFiber = (void *)GetProcAddress(library, "CreateFiber");
	pCreateFiberEx = (void *)GetProcAddress(library, "CreateFiberEx");
	pCreateFile2 = (void *)GetProcAddress(library, "CreateFile2");
	pCreateFileA = (void *)GetProcAddress(library, "CreateFileA");
	pCreateFileMappingW = (void *)GetProcAddress(library, "CreateFileMappingW");
	pCreateFileW = (void *)GetProcAddress(library, "CreateFileW");
	pCreateHardLinkA = (void *)GetProcAddress(library, "CreateHardLinkA");
	pextCreateHardLinkA = (void *)GetProcAddress(library_kernel32, "CreateHardLinkA");
	pCreateHardLinkW = (void *)GetProcAddress(library, "CreateHardLinkW");
	pextCreateHardLinkW = (void *)GetProcAddress(library_kernel32, "CreateHardLinkW");
	pCreateIoCompletionPort = (void *)GetProcAddress(library, "CreateIoCompletionPort");
	pCreateMemoryResourceNotification = (void *)GetProcAddress(library, "CreateMemoryResourceNotification");
	pextCreateMemoryResourceNotification = (void *)GetProcAddress(library_kernel32, "CreateMemoryResourceNotification");
	pCreateMutexA = (void *)GetProcAddress(library, "CreateMutexA");
	pCreateMutexExA = (void *)GetProcAddress(library, "CreateMutexExA");
	pCreateMutexExW = (void *)GetProcAddress(library, "CreateMutexExW");
	pCreateMutexW = (void *)GetProcAddress(library, "CreateMutexW");
	pCreateNamedPipeW = (void *)GetProcAddress(library, "CreateNamedPipeW");
	pCreatePipe = (void *)GetProcAddress(library, "CreatePipe");
	pextCreatePipe = (void *)GetProcAddress(library_kernel32, "CreatePipe");
	pCreatePrivateObjectSecurity = (void *)GetProcAddress(library, "CreatePrivateObjectSecurity");
	pCreatePrivateObjectSecurityEx = (void *)GetProcAddress(library, "CreatePrivateObjectSecurityEx");
	pCreatePrivateObjectSecurityWithMultipleInheritance = (void *)GetProcAddress(library, "CreatePrivateObjectSecurityWithMultipleInheritance");
	pCreateProcessA = (void *)GetProcAddress(library, "CreateProcessA");
	pextCreateProcessA = (void *)GetProcAddress(library_kernel32, "CreateProcessA");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pextCreateProcessAsUserA = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pextCreateProcessAsUserW = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserW");
	pCreateProcessInternalA = (void *)GetProcAddress(library, "CreateProcessInternalA");
	pextCreateProcessInternalA = (void *)GetProcAddress(library_kernel32, "CreateProcessInternalA");
	pCreateProcessInternalW = (void *)GetProcAddress(library, "CreateProcessInternalW");
	pextCreateProcessInternalW = (void *)GetProcAddress(library_kernel32, "CreateProcessInternalW");
	pCreateProcessW = (void *)GetProcAddress(library, "CreateProcessW");
	pextCreateProcessW = (void *)GetProcAddress(library_kernel32, "CreateProcessW");
	pCreateRemoteThread = (void *)GetProcAddress(library, "CreateRemoteThread");
	pCreateRemoteThreadEx = (void *)GetProcAddress(library, "CreateRemoteThreadEx");
	pCreateRestrictedToken = (void *)GetProcAddress(library, "CreateRestrictedToken");
	pCreateSemaphoreExW = (void *)GetProcAddress(library, "CreateSemaphoreExW");
	pCreateSemaphoreW = (void *)GetProcAddress(library, "CreateSemaphoreW");
	pCreateSymbolicLinkW = (void *)GetProcAddress(library, "CreateSymbolicLinkW");
	pextCreateSymbolicLinkW = (void *)GetProcAddress(library_kernel32, "CreateSymbolicLinkW");
	pCreateThread = (void *)GetProcAddress(library, "CreateThread");
	pCreateThreadpool = (void *)GetProcAddress(library, "CreateThreadpool");
	pCreateThreadpoolCleanupGroup = (void *)GetProcAddress(library, "CreateThreadpoolCleanupGroup");
	pCreateThreadpoolIo = (void *)GetProcAddress(library, "CreateThreadpoolIo");
	pCreateThreadpoolTimer = (void *)GetProcAddress(library, "CreateThreadpoolTimer");
	pCreateThreadpoolWait = (void *)GetProcAddress(library, "CreateThreadpoolWait");
	pCreateThreadpoolWork = (void *)GetProcAddress(library, "CreateThreadpoolWork");
	pCreateTimerQueue = (void *)GetProcAddress(library, "CreateTimerQueue");
	pCreateTimerQueueTimer = (void *)GetProcAddress(library, "CreateTimerQueueTimer");
	pCreateWaitableTimerExW = (void *)GetProcAddress(library, "CreateWaitableTimerExW");
	pCreateWaitableTimerW = (void *)GetProcAddress(library, "CreateWaitableTimerW");
	pCreateWellKnownSid = (void *)GetProcAddress(library, "CreateWellKnownSid");
	pDeactivateActCtx = (void *)GetProcAddress(library, "DeactivateActCtx");
	pDebugActiveProcess = (void *)GetProcAddress(library, "DebugActiveProcess");
	pextDebugActiveProcess = (void *)GetProcAddress(library_kernel32, "DebugActiveProcess");
	pDebugActiveProcessStop = (void *)GetProcAddress(library, "DebugActiveProcessStop");
	pextDebugActiveProcessStop = (void *)GetProcAddress(library_kernel32, "DebugActiveProcessStop");
	pDebugBreak = (void *)GetProcAddress(library, "DebugBreak");
	pextDebugBreak = (void *)GetProcAddress(library_kernel32, "DebugBreak");
	pDecodePointer = (void *)GetProcAddress(library, "DecodePointer");
	pextDecodePointer = (void *)GetProcAddress(library_ntdll, "RtlDecodePointer");
	pDecodeSystemPointer = (void *)GetProcAddress(library, "DecodeSystemPointer");
	pextDecodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlDecodeSystemPointer");
	pDefineDosDeviceW = (void *)GetProcAddress(library, "DefineDosDeviceW");
	pextDefineDosDeviceW = (void *)GetProcAddress(library_kernel32, "DefineDosDeviceW");
	pDelayLoadFailureHook = (void *)GetProcAddress(library, "DelayLoadFailureHook");
	pextDelayLoadFailureHook = (void *)GetProcAddress(library_kernel32, "DelayLoadFailureHook");
	pDeleteAce = (void *)GetProcAddress(library, "DeleteAce");
	pDeleteCriticalSection = (void *)GetProcAddress(library, "DeleteCriticalSection");
	pextDeleteCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlDeleteCriticalSection");
	pDeleteFiber = (void *)GetProcAddress(library, "DeleteFiber");
	pDeleteFileA = (void *)GetProcAddress(library, "DeleteFileA");
	pDeleteFileW = (void *)GetProcAddress(library, "DeleteFileW");
	pDeleteProcThreadAttributeList = (void *)GetProcAddress(library, "DeleteProcThreadAttributeList");
	pDeleteTimerQueueEx = (void *)GetProcAddress(library, "DeleteTimerQueueEx");
	pDeleteTimerQueueTimer = (void *)GetProcAddress(library, "DeleteTimerQueueTimer");
	pDeleteVolumeMountPointW = (void *)GetProcAddress(library, "DeleteVolumeMountPointW");
	pextDeleteVolumeMountPointW = (void *)GetProcAddress(library_kernel32, "DeleteVolumeMountPointW");
	pDestroyPrivateObjectSecurity = (void *)GetProcAddress(library, "DestroyPrivateObjectSecurity");
	pDeviceIoControl = (void *)GetProcAddress(library, "DeviceIoControl");
	pextDeviceIoControl = (void *)GetProcAddress(library_kernel32, "DeviceIoControl");
	pDisablePredefinedHandleTableInternal = (void *)GetProcAddress(library, "DisablePredefinedHandleTableInternal");
	pDisableThreadLibraryCalls = (void *)GetProcAddress(library, "DisableThreadLibraryCalls");
	pDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library, "DisassociateCurrentThreadFromCallback");
	pextDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library_ntdll, "TpDisassociateCallback");
	pDisconnectNamedPipe = (void *)GetProcAddress(library, "DisconnectNamedPipe");
	pDuplicateHandle = (void *)GetProcAddress(library, "DuplicateHandle");
	pextDuplicateHandle = (void *)GetProcAddress(library_kernel32, "DuplicateHandle");
	pDuplicateToken = (void *)GetProcAddress(library, "DuplicateToken");
	pDuplicateTokenEx = (void *)GetProcAddress(library, "DuplicateTokenEx");
	pEncodePointer = (void *)GetProcAddress(library, "EncodePointer");
	pextEncodePointer = (void *)GetProcAddress(library_ntdll, "RtlEncodePointer");
	pEncodeSystemPointer = (void *)GetProcAddress(library, "EncodeSystemPointer");
	pextEncodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlEncodeSystemPointer");
	pEnterCriticalSection = (void *)GetProcAddress(library, "EnterCriticalSection");
	pextEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlEnterCriticalSection");
	pEnumCalendarInfoExEx = (void *)GetProcAddress(library, "EnumCalendarInfoExEx");
	pextEnumCalendarInfoExEx = (void *)GetProcAddress(library_kernel32, "EnumCalendarInfoExEx");
	pEnumCalendarInfoExW = (void *)GetProcAddress(library, "EnumCalendarInfoExW");
	pextEnumCalendarInfoExW = (void *)GetProcAddress(library_kernel32, "EnumCalendarInfoExW");
	pEnumCalendarInfoW = (void *)GetProcAddress(library, "EnumCalendarInfoW");
	pextEnumCalendarInfoW = (void *)GetProcAddress(library_kernel32, "EnumCalendarInfoW");
	pEnumDateFormatsExEx = (void *)GetProcAddress(library, "EnumDateFormatsExEx");
	pextEnumDateFormatsExEx = (void *)GetProcAddress(library_kernel32, "EnumDateFormatsExEx");
	pEnumDateFormatsExW = (void *)GetProcAddress(library, "EnumDateFormatsExW");
	pextEnumDateFormatsExW = (void *)GetProcAddress(library_kernel32, "EnumDateFormatsExW");
	pEnumDateFormatsW = (void *)GetProcAddress(library, "EnumDateFormatsW");
	pextEnumDateFormatsW = (void *)GetProcAddress(library_kernel32, "EnumDateFormatsW");
	pEnumDynamicTimeZoneInformation = (void *)GetProcAddress(library, "EnumDynamicTimeZoneInformation");
	pEnumLanguageGroupLocalesW = (void *)GetProcAddress(library, "EnumLanguageGroupLocalesW");
	pextEnumLanguageGroupLocalesW = (void *)GetProcAddress(library_kernel32, "EnumLanguageGroupLocalesW");
	pEnumResourceLanguagesExA = (void *)GetProcAddress(library, "EnumResourceLanguagesExA");
	pEnumResourceLanguagesExW = (void *)GetProcAddress(library, "EnumResourceLanguagesExW");
	pEnumResourceNamesExA = (void *)GetProcAddress(library, "EnumResourceNamesExA");
	pEnumResourceNamesExW = (void *)GetProcAddress(library, "EnumResourceNamesExW");
	pEnumResourceNamesW = (void *)GetProcAddress(library, "EnumResourceNamesW");
	pEnumResourceTypesExA = (void *)GetProcAddress(library, "EnumResourceTypesExA");
	pEnumResourceTypesExW = (void *)GetProcAddress(library, "EnumResourceTypesExW");
	pEnumSystemCodePagesW = (void *)GetProcAddress(library, "EnumSystemCodePagesW");
	pextEnumSystemCodePagesW = (void *)GetProcAddress(library_kernel32, "EnumSystemCodePagesW");
	pEnumSystemFirmwareTables = (void *)GetProcAddress(library, "EnumSystemFirmwareTables");
	pextEnumSystemFirmwareTables = (void *)GetProcAddress(library_kernel32, "EnumSystemFirmwareTables");
	pEnumSystemGeoID = (void *)GetProcAddress(library, "EnumSystemGeoID");
	pextEnumSystemGeoID = (void *)GetProcAddress(library_kernel32, "EnumSystemGeoID");
	pEnumSystemLanguageGroupsW = (void *)GetProcAddress(library, "EnumSystemLanguageGroupsW");
	pextEnumSystemLanguageGroupsW = (void *)GetProcAddress(library_kernel32, "EnumSystemLanguageGroupsW");
	pEnumSystemLocalesA = (void *)GetProcAddress(library, "EnumSystemLocalesA");
	pextEnumSystemLocalesA = (void *)GetProcAddress(library_kernel32, "EnumSystemLocalesA");
	pEnumSystemLocalesEx = (void *)GetProcAddress(library, "EnumSystemLocalesEx");
	pextEnumSystemLocalesEx = (void *)GetProcAddress(library_kernel32, "EnumSystemLocalesEx");
	pEnumSystemLocalesW = (void *)GetProcAddress(library, "EnumSystemLocalesW");
	pextEnumSystemLocalesW = (void *)GetProcAddress(library_kernel32, "EnumSystemLocalesW");
	pEnumTimeFormatsEx = (void *)GetProcAddress(library, "EnumTimeFormatsEx");
	pextEnumTimeFormatsEx = (void *)GetProcAddress(library_kernel32, "EnumTimeFormatsEx");
	pEnumTimeFormatsW = (void *)GetProcAddress(library, "EnumTimeFormatsW");
	pextEnumTimeFormatsW = (void *)GetProcAddress(library_kernel32, "EnumTimeFormatsW");
	pEnumUILanguagesW = (void *)GetProcAddress(library, "EnumUILanguagesW");
	pextEnumUILanguagesW = (void *)GetProcAddress(library_kernel32, "EnumUILanguagesW");
	pEqualPrefixSid = (void *)GetProcAddress(library, "EqualPrefixSid");
	pEqualSid = (void *)GetProcAddress(library, "EqualSid");
	pEscapeCommFunction = (void *)GetProcAddress(library, "EscapeCommFunction");
	pextEscapeCommFunction = (void *)GetProcAddress(library_kernel32, "EscapeCommFunction");
	pEventActivityIdControl = (void *)GetProcAddress(library, "EventActivityIdControl");
	pextEventActivityIdControl = (void *)GetProcAddress(library_ntdll, "EtwEventActivityIdControl");
	pEventEnabled = (void *)GetProcAddress(library, "EventEnabled");
	pextEventEnabled = (void *)GetProcAddress(library_ntdll, "EtwEventEnabled");
	pEventProviderEnabled = (void *)GetProcAddress(library, "EventProviderEnabled");
	pextEventProviderEnabled = (void *)GetProcAddress(library_ntdll, "EtwEventProviderEnabled");
	pEventRegister = (void *)GetProcAddress(library, "EventRegister");
	pextEventRegister = (void *)GetProcAddress(library_ntdll, "EtwEventRegister");
	pEventSetInformation = (void *)GetProcAddress(library, "EventSetInformation");
	pextEventSetInformation = (void *)GetProcAddress(library_ntdll, "EtwEventSetInformation");
	pEventUnregister = (void *)GetProcAddress(library, "EventUnregister");
	pextEventUnregister = (void *)GetProcAddress(library_ntdll, "EtwEventUnregister");
	pEventWrite = (void *)GetProcAddress(library, "EventWrite");
	pextEventWrite = (void *)GetProcAddress(library_ntdll, "EtwEventWrite");
	pEventWriteString = (void *)GetProcAddress(library, "EventWriteString");
	pextEventWriteString = (void *)GetProcAddress(library_ntdll, "EtwEventWriteString");
	pEventWriteTransfer = (void *)GetProcAddress(library, "EventWriteTransfer");
	pextEventWriteTransfer = (void *)GetProcAddress(library_ntdll, "EtwEventWriteTransfer");
	pExitProcess = (void *)GetProcAddress(library, "ExitProcess");
	pextExitProcess = (void *)GetProcAddress(library_ntdll, "RtlExitUserProcess");
	pExitThread = (void *)GetProcAddress(library, "ExitThread");
	pextExitThread = (void *)GetProcAddress(library_ntdll, "RtlExitUserThread");
	pExpandEnvironmentStringsA = (void *)GetProcAddress(library, "ExpandEnvironmentStringsA");
	pextExpandEnvironmentStringsA = (void *)GetProcAddress(library_kernel32, "ExpandEnvironmentStringsA");
	pExpandEnvironmentStringsW = (void *)GetProcAddress(library, "ExpandEnvironmentStringsW");
	pextExpandEnvironmentStringsW = (void *)GetProcAddress(library_kernel32, "ExpandEnvironmentStringsW");
	pFatalAppExitA = (void *)GetProcAddress(library, "FatalAppExitA");
	pextFatalAppExitA = (void *)GetProcAddress(library_kernel32, "FatalAppExitA");
	pFatalAppExitW = (void *)GetProcAddress(library, "FatalAppExitW");
	pextFatalAppExitW = (void *)GetProcAddress(library_kernel32, "FatalAppExitW");
	pFileTimeToLocalFileTime = (void *)GetProcAddress(library, "FileTimeToLocalFileTime");
	pextFileTimeToLocalFileTime = (void *)GetProcAddress(library_kernel32, "FileTimeToLocalFileTime");
	pFileTimeToSystemTime = (void *)GetProcAddress(library, "FileTimeToSystemTime");
	pextFileTimeToSystemTime = (void *)GetProcAddress(library_kernel32, "FileTimeToSystemTime");
	pFillConsoleOutputAttribute = (void *)GetProcAddress(library, "FillConsoleOutputAttribute");
	pextFillConsoleOutputAttribute = (void *)GetProcAddress(library_kernel32, "FillConsoleOutputAttribute");
	pFillConsoleOutputCharacterA = (void *)GetProcAddress(library, "FillConsoleOutputCharacterA");
	pextFillConsoleOutputCharacterA = (void *)GetProcAddress(library_kernel32, "FillConsoleOutputCharacterA");
	pFillConsoleOutputCharacterW = (void *)GetProcAddress(library, "FillConsoleOutputCharacterW");
	pextFillConsoleOutputCharacterW = (void *)GetProcAddress(library_kernel32, "FillConsoleOutputCharacterW");
	pFindActCtxSectionGuid = (void *)GetProcAddress(library, "FindActCtxSectionGuid");
	pFindActCtxSectionStringW = (void *)GetProcAddress(library, "FindActCtxSectionStringW");
	pFindClose = (void *)GetProcAddress(library, "FindClose");
	pextFindClose = (void *)GetProcAddress(library_kernel32, "FindClose");
	pFindCloseChangeNotification = (void *)GetProcAddress(library, "FindCloseChangeNotification");
	pextFindCloseChangeNotification = (void *)GetProcAddress(library_kernel32, "FindCloseChangeNotification");
	pFindFirstChangeNotificationA = (void *)GetProcAddress(library, "FindFirstChangeNotificationA");
	pextFindFirstChangeNotificationA = (void *)GetProcAddress(library_kernel32, "FindFirstChangeNotificationA");
	pFindFirstChangeNotificationW = (void *)GetProcAddress(library, "FindFirstChangeNotificationW");
	pextFindFirstChangeNotificationW = (void *)GetProcAddress(library_kernel32, "FindFirstChangeNotificationW");
	pFindFirstFileA = (void *)GetProcAddress(library, "FindFirstFileA");
	pextFindFirstFileA = (void *)GetProcAddress(library_kernel32, "FindFirstFileA");
	pFindFirstFileExA = (void *)GetProcAddress(library, "FindFirstFileExA");
	pextFindFirstFileExA = (void *)GetProcAddress(library_kernel32, "FindFirstFileExA");
	pFindFirstFileExW = (void *)GetProcAddress(library, "FindFirstFileExW");
	pextFindFirstFileExW = (void *)GetProcAddress(library_kernel32, "FindFirstFileExW");
	pFindFirstFileW = (void *)GetProcAddress(library, "FindFirstFileW");
	pextFindFirstFileW = (void *)GetProcAddress(library_kernel32, "FindFirstFileW");
	pFindFirstFreeAce = (void *)GetProcAddress(library, "FindFirstFreeAce");
	pFindFirstStreamW = (void *)GetProcAddress(library, "FindFirstStreamW");
	pextFindFirstStreamW = (void *)GetProcAddress(library_kernel32, "FindFirstStreamW");
	pFindFirstVolumeW = (void *)GetProcAddress(library, "FindFirstVolumeW");
	pextFindFirstVolumeW = (void *)GetProcAddress(library_kernel32, "FindFirstVolumeW");
	pFindNLSStringEx = (void *)GetProcAddress(library, "FindNLSStringEx");
	pextFindNLSStringEx = (void *)GetProcAddress(library_kernel32, "FindNLSStringEx");
	pFindNextChangeNotification = (void *)GetProcAddress(library, "FindNextChangeNotification");
	pextFindNextChangeNotification = (void *)GetProcAddress(library_kernel32, "FindNextChangeNotification");
	pFindNextFileA = (void *)GetProcAddress(library, "FindNextFileA");
	pextFindNextFileA = (void *)GetProcAddress(library_kernel32, "FindNextFileA");
	pFindNextFileW = (void *)GetProcAddress(library, "FindNextFileW");
	pextFindNextFileW = (void *)GetProcAddress(library_kernel32, "FindNextFileW");
	pFindNextStreamW = (void *)GetProcAddress(library, "FindNextStreamW");
	pextFindNextStreamW = (void *)GetProcAddress(library_kernel32, "FindNextStreamW");
	pFindNextVolumeW = (void *)GetProcAddress(library, "FindNextVolumeW");
	pextFindNextVolumeW = (void *)GetProcAddress(library_kernel32, "FindNextVolumeW");
	pFindResourceExW = (void *)GetProcAddress(library, "FindResourceExW");
	pFindResourceW = (void *)GetProcAddress(library, "FindResourceW");
	pFindStringOrdinal = (void *)GetProcAddress(library, "FindStringOrdinal");
	pextFindStringOrdinal = (void *)GetProcAddress(library_kernel32, "FindStringOrdinal");
	pFindVolumeClose = (void *)GetProcAddress(library, "FindVolumeClose");
	pextFindVolumeClose = (void *)GetProcAddress(library_kernel32, "FindVolumeClose");
	pFlsAlloc = (void *)GetProcAddress(library, "FlsAlloc");
	pFlsFree = (void *)GetProcAddress(library, "FlsFree");
	pFlsGetValue = (void *)GetProcAddress(library, "FlsGetValue");
	pFlsSetValue = (void *)GetProcAddress(library, "FlsSetValue");
	pFlushConsoleInputBuffer = (void *)GetProcAddress(library, "FlushConsoleInputBuffer");
	pextFlushConsoleInputBuffer = (void *)GetProcAddress(library_kernel32, "FlushConsoleInputBuffer");
	pFlushFileBuffers = (void *)GetProcAddress(library, "FlushFileBuffers");
	pFlushInstructionCache = (void *)GetProcAddress(library, "FlushInstructionCache");
	pFlushProcessWriteBuffers = (void *)GetProcAddress(library, "FlushProcessWriteBuffers");
	pextFlushProcessWriteBuffers = (void *)GetProcAddress(library_kernel32, "FlushProcessWriteBuffers");
	pFlushViewOfFile = (void *)GetProcAddress(library, "FlushViewOfFile");
	pextFlushViewOfFile = (void *)GetProcAddress(library_kernel32, "FlushViewOfFile");
	pFoldStringW = (void *)GetProcAddress(library, "FoldStringW");
	pextFoldStringW = (void *)GetProcAddress(library_kernel32, "FoldStringW");
	pFormatMessageA = (void *)GetProcAddress(library, "FormatMessageA");
	pextFormatMessageA = (void *)GetProcAddress(library_kernel32, "FormatMessageA");
	pFormatMessageW = (void *)GetProcAddress(library, "FormatMessageW");
	pextFormatMessageW = (void *)GetProcAddress(library_kernel32, "FormatMessageW");
	pFreeConsole = (void *)GetProcAddress(library, "FreeConsole");
	pextFreeConsole = (void *)GetProcAddress(library_kernel32, "FreeConsole");
	pFreeEnvironmentStringsA = (void *)GetProcAddress(library, "FreeEnvironmentStringsA");
	pextFreeEnvironmentStringsA = (void *)GetProcAddress(library_kernel32, "FreeEnvironmentStringsA");
	pFreeEnvironmentStringsW = (void *)GetProcAddress(library, "FreeEnvironmentStringsW");
	pextFreeEnvironmentStringsW = (void *)GetProcAddress(library_kernel32, "FreeEnvironmentStringsW");
	pFreeLibrary = (void *)GetProcAddress(library, "FreeLibrary");
	pextFreeLibrary = (void *)GetProcAddress(library_kernel32, "FreeLibrary");
	pFreeLibraryAndExitThread = (void *)GetProcAddress(library, "FreeLibraryAndExitThread");
	pFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library, "FreeLibraryWhenCallbackReturns");
	pextFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackUnloadDllOnCompletion");
	pFreeResource = (void *)GetProcAddress(library, "FreeResource");
	pFreeSid = (void *)GetProcAddress(library, "FreeSid");
	pFreeUserPhysicalPages = (void *)GetProcAddress(library, "FreeUserPhysicalPages");
	pextFreeUserPhysicalPages = (void *)GetProcAddress(library_kernel32, "FreeUserPhysicalPages");
	pGenerateConsoleCtrlEvent = (void *)GetProcAddress(library, "GenerateConsoleCtrlEvent");
	pextGenerateConsoleCtrlEvent = (void *)GetProcAddress(library_kernel32, "GenerateConsoleCtrlEvent");
	pGetACP = (void *)GetProcAddress(library, "GetACP");
	pextGetACP = (void *)GetProcAddress(library_kernel32, "GetACP");
	pGetAcceptLanguagesA = (void *)GetProcAddress(library, "GetAcceptLanguagesA");
	pGetAcceptLanguagesW = (void *)GetProcAddress(library, "GetAcceptLanguagesW");
	pGetAce = (void *)GetProcAddress(library, "GetAce");
	pGetAclInformation = (void *)GetProcAddress(library, "GetAclInformation");
	pGetApplicationRestartSettings = (void *)GetProcAddress(library, "GetApplicationRestartSettings");
	pextGetApplicationRestartSettings = (void *)GetProcAddress(library_kernel32, "GetApplicationRestartSettings");
	pGetCPInfo = (void *)GetProcAddress(library, "GetCPInfo");
	pextGetCPInfo = (void *)GetProcAddress(library_kernel32, "GetCPInfo");
	pGetCPInfoExW = (void *)GetProcAddress(library, "GetCPInfoExW");
	pextGetCPInfoExW = (void *)GetProcAddress(library_kernel32, "GetCPInfoExW");
	pGetCalendarInfoEx = (void *)GetProcAddress(library, "GetCalendarInfoEx");
	pextGetCalendarInfoEx = (void *)GetProcAddress(library_kernel32, "GetCalendarInfoEx");
	pGetCalendarInfoW = (void *)GetProcAddress(library, "GetCalendarInfoW");
	pextGetCalendarInfoW = (void *)GetProcAddress(library_kernel32, "GetCalendarInfoW");
	pGetCommConfig = (void *)GetProcAddress(library, "GetCommConfig");
	pextGetCommConfig = (void *)GetProcAddress(library_kernel32, "GetCommConfig");
	pGetCommMask = (void *)GetProcAddress(library, "GetCommMask");
	pextGetCommMask = (void *)GetProcAddress(library_kernel32, "GetCommMask");
	pGetCommModemStatus = (void *)GetProcAddress(library, "GetCommModemStatus");
	pextGetCommModemStatus = (void *)GetProcAddress(library_kernel32, "GetCommModemStatus");
	pGetCommProperties = (void *)GetProcAddress(library, "GetCommProperties");
	pextGetCommProperties = (void *)GetProcAddress(library_kernel32, "GetCommProperties");
	pGetCommState = (void *)GetProcAddress(library, "GetCommState");
	pextGetCommState = (void *)GetProcAddress(library_kernel32, "GetCommState");
	pGetCommTimeouts = (void *)GetProcAddress(library, "GetCommTimeouts");
	pextGetCommTimeouts = (void *)GetProcAddress(library_kernel32, "GetCommTimeouts");
	pGetCommandLineA = (void *)GetProcAddress(library, "GetCommandLineA");
	pextGetCommandLineA = (void *)GetProcAddress(library_kernel32, "GetCommandLineA");
	pGetCommandLineW = (void *)GetProcAddress(library, "GetCommandLineW");
	pextGetCommandLineW = (void *)GetProcAddress(library_kernel32, "GetCommandLineW");
	pGetCompressedFileSizeA = (void *)GetProcAddress(library, "GetCompressedFileSizeA");
	pGetCompressedFileSizeW = (void *)GetProcAddress(library, "GetCompressedFileSizeW");
	pGetComputerNameExA = (void *)GetProcAddress(library, "GetComputerNameExA");
	pextGetComputerNameExA = (void *)GetProcAddress(library_kernel32, "GetComputerNameExA");
	pGetComputerNameExW = (void *)GetProcAddress(library, "GetComputerNameExW");
	pextGetComputerNameExW = (void *)GetProcAddress(library_kernel32, "GetComputerNameExW");
	pGetConsoleCP = (void *)GetProcAddress(library, "GetConsoleCP");
	pextGetConsoleCP = (void *)GetProcAddress(library_kernel32, "GetConsoleCP");
	pGetConsoleCursorInfo = (void *)GetProcAddress(library, "GetConsoleCursorInfo");
	pextGetConsoleCursorInfo = (void *)GetProcAddress(library_kernel32, "GetConsoleCursorInfo");
	pGetConsoleInputExeNameA = (void *)GetProcAddress(library, "GetConsoleInputExeNameA");
	pextGetConsoleInputExeNameA = (void *)GetProcAddress(library_kernel32, "GetConsoleInputExeNameA");
	pGetConsoleInputExeNameW = (void *)GetProcAddress(library, "GetConsoleInputExeNameW");
	pextGetConsoleInputExeNameW = (void *)GetProcAddress(library_kernel32, "GetConsoleInputExeNameW");
	pGetConsoleMode = (void *)GetProcAddress(library, "GetConsoleMode");
	pextGetConsoleMode = (void *)GetProcAddress(library_kernel32, "GetConsoleMode");
	pGetConsoleOutputCP = (void *)GetProcAddress(library, "GetConsoleOutputCP");
	pextGetConsoleOutputCP = (void *)GetProcAddress(library_kernel32, "GetConsoleOutputCP");
	pGetConsoleScreenBufferInfo = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfo");
	pextGetConsoleScreenBufferInfo = (void *)GetProcAddress(library_kernel32, "GetConsoleScreenBufferInfo");
	pGetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfoEx");
	pextGetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library_kernel32, "GetConsoleScreenBufferInfoEx");
	pGetConsoleTitleW = (void *)GetProcAddress(library, "GetConsoleTitleW");
	pextGetConsoleTitleW = (void *)GetProcAddress(library_kernel32, "GetConsoleTitleW");
	pGetCurrencyFormatEx = (void *)GetProcAddress(library, "GetCurrencyFormatEx");
	pextGetCurrencyFormatEx = (void *)GetProcAddress(library_kernel32, "GetCurrencyFormatEx");
	pGetCurrencyFormatW = (void *)GetProcAddress(library, "GetCurrencyFormatW");
	pextGetCurrencyFormatW = (void *)GetProcAddress(library_kernel32, "GetCurrencyFormatW");
	pGetCurrentActCtx = (void *)GetProcAddress(library, "GetCurrentActCtx");
	pGetCurrentDirectoryA = (void *)GetProcAddress(library, "GetCurrentDirectoryA");
	pextGetCurrentDirectoryA = (void *)GetProcAddress(library_kernel32, "GetCurrentDirectoryA");
	pGetCurrentDirectoryW = (void *)GetProcAddress(library, "GetCurrentDirectoryW");
	pextGetCurrentDirectoryW = (void *)GetProcAddress(library_kernel32, "GetCurrentDirectoryW");
	pGetCurrentPackageFamilyName = (void *)GetProcAddress(library, "GetCurrentPackageFamilyName");
	pextGetCurrentPackageFamilyName = (void *)GetProcAddress(library_kernel32, "GetCurrentPackageFamilyName");
	pGetCurrentPackageFullName = (void *)GetProcAddress(library, "GetCurrentPackageFullName");
	pextGetCurrentPackageFullName = (void *)GetProcAddress(library_kernel32, "GetCurrentPackageFullName");
	pGetCurrentPackageId = (void *)GetProcAddress(library, "GetCurrentPackageId");
	pextGetCurrentPackageId = (void *)GetProcAddress(library_kernel32, "GetCurrentPackageId");
	pGetCurrentProcess = (void *)GetProcAddress(library, "GetCurrentProcess");
	pGetCurrentProcessId = (void *)GetProcAddress(library, "GetCurrentProcessId");
	pGetCurrentProcessorNumber = (void *)GetProcAddress(library, "GetCurrentProcessorNumber");
	pextGetCurrentProcessorNumber = (void *)GetProcAddress(library_ntdll, "NtGetCurrentProcessorNumber");
	pGetCurrentProcessorNumberEx = (void *)GetProcAddress(library, "GetCurrentProcessorNumberEx");
	pextGetCurrentProcessorNumberEx = (void *)GetProcAddress(library_ntdll, "RtlGetCurrentProcessorNumberEx");
	pGetCurrentThread = (void *)GetProcAddress(library, "GetCurrentThread");
	pGetCurrentThreadId = (void *)GetProcAddress(library, "GetCurrentThreadId");
	pGetCurrentThreadStackLimits = (void *)GetProcAddress(library, "GetCurrentThreadStackLimits");
	pGetDateFormatA = (void *)GetProcAddress(library, "GetDateFormatA");
	pextGetDateFormatA = (void *)GetProcAddress(library_kernel32, "GetDateFormatA");
	pGetDateFormatEx = (void *)GetProcAddress(library, "GetDateFormatEx");
	pextGetDateFormatEx = (void *)GetProcAddress(library_kernel32, "GetDateFormatEx");
	pGetDateFormatW = (void *)GetProcAddress(library, "GetDateFormatW");
	pextGetDateFormatW = (void *)GetProcAddress(library_kernel32, "GetDateFormatW");
	pGetDiskFreeSpaceA = (void *)GetProcAddress(library, "GetDiskFreeSpaceA");
	pextGetDiskFreeSpaceA = (void *)GetProcAddress(library_kernel32, "GetDiskFreeSpaceA");
	pGetDiskFreeSpaceExA = (void *)GetProcAddress(library, "GetDiskFreeSpaceExA");
	pextGetDiskFreeSpaceExA = (void *)GetProcAddress(library_kernel32, "GetDiskFreeSpaceExA");
	pGetDiskFreeSpaceExW = (void *)GetProcAddress(library, "GetDiskFreeSpaceExW");
	pextGetDiskFreeSpaceExW = (void *)GetProcAddress(library_kernel32, "GetDiskFreeSpaceExW");
	pGetDiskFreeSpaceW = (void *)GetProcAddress(library, "GetDiskFreeSpaceW");
	pextGetDiskFreeSpaceW = (void *)GetProcAddress(library_kernel32, "GetDiskFreeSpaceW");
	pGetDriveTypeA = (void *)GetProcAddress(library, "GetDriveTypeA");
	pextGetDriveTypeA = (void *)GetProcAddress(library_kernel32, "GetDriveTypeA");
	pGetDriveTypeW = (void *)GetProcAddress(library, "GetDriveTypeW");
	pextGetDriveTypeW = (void *)GetProcAddress(library_kernel32, "GetDriveTypeW");
	pGetDynamicTimeZoneInformation = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformation");
	pextGetDynamicTimeZoneInformation = (void *)GetProcAddress(library_kernel32, "GetDynamicTimeZoneInformation");
	pGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformationEffectiveYears");
	pextGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library_kernel32, "GetDynamicTimeZoneInformationEffectiveYears");
	pGetEnabledXStateFeatures = (void *)GetProcAddress(library, "GetEnabledXStateFeatures");
	pextGetEnabledXStateFeatures = (void *)GetProcAddress(library_kernel32, "GetEnabledXStateFeatures");
	pGetEnvironmentStrings = (void *)GetProcAddress(library, "GetEnvironmentStrings");
	pextGetEnvironmentStrings = (void *)GetProcAddress(library_kernel32, "GetEnvironmentStrings");
	pGetEnvironmentStringsA = (void *)GetProcAddress(library, "GetEnvironmentStringsA");
	pextGetEnvironmentStringsA = (void *)GetProcAddress(library_kernel32, "GetEnvironmentStringsA");
	pGetEnvironmentStringsW = (void *)GetProcAddress(library, "GetEnvironmentStringsW");
	pextGetEnvironmentStringsW = (void *)GetProcAddress(library_kernel32, "GetEnvironmentStringsW");
	pGetEnvironmentVariableA = (void *)GetProcAddress(library, "GetEnvironmentVariableA");
	pextGetEnvironmentVariableA = (void *)GetProcAddress(library_kernel32, "GetEnvironmentVariableA");
	pGetEnvironmentVariableW = (void *)GetProcAddress(library, "GetEnvironmentVariableW");
	pextGetEnvironmentVariableW = (void *)GetProcAddress(library_kernel32, "GetEnvironmentVariableW");
	pGetErrorMode = (void *)GetProcAddress(library, "GetErrorMode");
	pGetExitCodeProcess = (void *)GetProcAddress(library, "GetExitCodeProcess");
	pGetExitCodeThread = (void *)GetProcAddress(library, "GetExitCodeThread");
	pGetFileAttributesA = (void *)GetProcAddress(library, "GetFileAttributesA");
	pGetFileAttributesExA = (void *)GetProcAddress(library, "GetFileAttributesExA");
	pGetFileAttributesExW = (void *)GetProcAddress(library, "GetFileAttributesExW");
	pGetFileAttributesW = (void *)GetProcAddress(library, "GetFileAttributesW");
	pGetFileInformationByHandle = (void *)GetProcAddress(library, "GetFileInformationByHandle");
	pGetFileInformationByHandleEx = (void *)GetProcAddress(library, "GetFileInformationByHandleEx");
	pGetFileMUIInfo = (void *)GetProcAddress(library, "GetFileMUIInfo");
	pextGetFileMUIInfo = (void *)GetProcAddress(library_kernel32, "GetFileMUIInfo");
	pGetFileMUIPath = (void *)GetProcAddress(library, "GetFileMUIPath");
	pextGetFileMUIPath = (void *)GetProcAddress(library_kernel32, "GetFileMUIPath");
	pGetFileSecurityW = (void *)GetProcAddress(library, "GetFileSecurityW");
	pGetFileSize = (void *)GetProcAddress(library, "GetFileSize");
	pGetFileSizeEx = (void *)GetProcAddress(library, "GetFileSizeEx");
	pGetFileTime = (void *)GetProcAddress(library, "GetFileTime");
	pGetFileType = (void *)GetProcAddress(library, "GetFileType");
	pGetFileVersionInfoA = (void *)GetProcAddress(library, "GetFileVersionInfoA");
	pGetFileVersionInfoExA = (void *)GetProcAddress(library, "GetFileVersionInfoExA");
	pGetFileVersionInfoExW = (void *)GetProcAddress(library, "GetFileVersionInfoExW");
	pGetFileVersionInfoSizeA = (void *)GetProcAddress(library, "GetFileVersionInfoSizeA");
	pGetFileVersionInfoSizeExA = (void *)GetProcAddress(library, "GetFileVersionInfoSizeExA");
	pGetFileVersionInfoSizeExW = (void *)GetProcAddress(library, "GetFileVersionInfoSizeExW");
	pGetFileVersionInfoSizeW = (void *)GetProcAddress(library, "GetFileVersionInfoSizeW");
	pGetFileVersionInfoW = (void *)GetProcAddress(library, "GetFileVersionInfoW");
	pGetFinalPathNameByHandleA = (void *)GetProcAddress(library, "GetFinalPathNameByHandleA");
	pextGetFinalPathNameByHandleA = (void *)GetProcAddress(library_kernel32, "GetFinalPathNameByHandleA");
	pGetFinalPathNameByHandleW = (void *)GetProcAddress(library, "GetFinalPathNameByHandleW");
	pextGetFinalPathNameByHandleW = (void *)GetProcAddress(library_kernel32, "GetFinalPathNameByHandleW");
	pGetFullPathNameA = (void *)GetProcAddress(library, "GetFullPathNameA");
	pextGetFullPathNameA = (void *)GetProcAddress(library_kernel32, "GetFullPathNameA");
	pGetFullPathNameW = (void *)GetProcAddress(library, "GetFullPathNameW");
	pextGetFullPathNameW = (void *)GetProcAddress(library_kernel32, "GetFullPathNameW");
	pGetGeoInfoW = (void *)GetProcAddress(library, "GetGeoInfoW");
	pextGetGeoInfoW = (void *)GetProcAddress(library_kernel32, "GetGeoInfoW");
	pGetHandleInformation = (void *)GetProcAddress(library, "GetHandleInformation");
	pextGetHandleInformation = (void *)GetProcAddress(library_kernel32, "GetHandleInformation");
	pGetKernelObjectSecurity = (void *)GetProcAddress(library, "GetKernelObjectSecurity");
	pGetLargePageMinimum = (void *)GetProcAddress(library, "GetLargePageMinimum");
	pextGetLargePageMinimum = (void *)GetProcAddress(library_kernel32, "GetLargePageMinimum");
	pGetLargestConsoleWindowSize = (void *)GetProcAddress(library, "GetLargestConsoleWindowSize");
	pextGetLargestConsoleWindowSize = (void *)GetProcAddress(library_kernel32, "GetLargestConsoleWindowSize");
	pGetLastError = (void *)GetProcAddress(library, "GetLastError");
	pGetLengthSid = (void *)GetProcAddress(library, "GetLengthSid");
	pGetLocalTime = (void *)GetProcAddress(library, "GetLocalTime");
	pextGetLocalTime = (void *)GetProcAddress(library_kernel32, "GetLocalTime");
	pGetLocaleInfoA = (void *)GetProcAddress(library, "GetLocaleInfoA");
	pextGetLocaleInfoA = (void *)GetProcAddress(library_kernel32, "GetLocaleInfoA");
	pGetLocaleInfoEx = (void *)GetProcAddress(library, "GetLocaleInfoEx");
	pextGetLocaleInfoEx = (void *)GetProcAddress(library_kernel32, "GetLocaleInfoEx");
	pGetLocaleInfoW = (void *)GetProcAddress(library, "GetLocaleInfoW");
	pextGetLocaleInfoW = (void *)GetProcAddress(library_kernel32, "GetLocaleInfoW");
	pGetLogicalDriveStringsW = (void *)GetProcAddress(library, "GetLogicalDriveStringsW");
	pextGetLogicalDriveStringsW = (void *)GetProcAddress(library_kernel32, "GetLogicalDriveStringsW");
	pGetLogicalDrives = (void *)GetProcAddress(library, "GetLogicalDrives");
	pextGetLogicalDrives = (void *)GetProcAddress(library_kernel32, "GetLogicalDrives");
	pGetLogicalProcessorInformation = (void *)GetProcAddress(library, "GetLogicalProcessorInformation");
	pextGetLogicalProcessorInformation = (void *)GetProcAddress(library_kernel32, "GetLogicalProcessorInformation");
	pGetLogicalProcessorInformationEx = (void *)GetProcAddress(library, "GetLogicalProcessorInformationEx");
	pextGetLogicalProcessorInformationEx = (void *)GetProcAddress(library_kernel32, "GetLogicalProcessorInformationEx");
	pGetLongPathNameA = (void *)GetProcAddress(library, "GetLongPathNameA");
	pextGetLongPathNameA = (void *)GetProcAddress(library_kernel32, "GetLongPathNameA");
	pGetLongPathNameW = (void *)GetProcAddress(library, "GetLongPathNameW");
	pextGetLongPathNameW = (void *)GetProcAddress(library_kernel32, "GetLongPathNameW");
	pGetModuleFileNameA = (void *)GetProcAddress(library, "GetModuleFileNameA");
	pGetModuleFileNameW = (void *)GetProcAddress(library, "GetModuleFileNameW");
	pGetModuleHandleA = (void *)GetProcAddress(library, "GetModuleHandleA");
	pGetModuleHandleExA = (void *)GetProcAddress(library, "GetModuleHandleExA");
	pGetModuleHandleExW = (void *)GetProcAddress(library, "GetModuleHandleExW");
	pGetModuleHandleW = (void *)GetProcAddress(library, "GetModuleHandleW");
	pGetNamedPipeHandleStateW = (void *)GetProcAddress(library, "GetNamedPipeHandleStateW");
	pextGetNamedPipeHandleStateW = (void *)GetProcAddress(library_kernel32, "GetNamedPipeHandleStateW");
	pGetNamedPipeInfo = (void *)GetProcAddress(library, "GetNamedPipeInfo");
	pGetNativeSystemInfo = (void *)GetProcAddress(library, "GetNativeSystemInfo");
	pextGetNativeSystemInfo = (void *)GetProcAddress(library_kernel32, "GetNativeSystemInfo");
	pGetNumaHighestNodeNumber = (void *)GetProcAddress(library, "GetNumaHighestNodeNumber");
	pextGetNumaHighestNodeNumber = (void *)GetProcAddress(library_kernel32, "GetNumaHighestNodeNumber");
	pGetNumaNodeProcessorMaskEx = (void *)GetProcAddress(library, "GetNumaNodeProcessorMaskEx");
	pextGetNumaNodeProcessorMaskEx = (void *)GetProcAddress(library_kernel32, "GetNumaNodeProcessorMaskEx");
	pGetNumaProximityNode = (void *)GetProcAddress(library, "GetNumaProximityNode");
	pextGetNumaProximityNode = (void *)GetProcAddress(library_kernel32, "GetNumaProximityNode");
	pGetNumaProximityNodeEx = (void *)GetProcAddress(library, "GetNumaProximityNodeEx");
	pextGetNumaProximityNodeEx = (void *)GetProcAddress(library_kernel32, "GetNumaProximityNodeEx");
	pGetNumberFormatEx = (void *)GetProcAddress(library, "GetNumberFormatEx");
	pextGetNumberFormatEx = (void *)GetProcAddress(library_kernel32, "GetNumberFormatEx");
	pGetNumberFormatW = (void *)GetProcAddress(library, "GetNumberFormatW");
	pextGetNumberFormatW = (void *)GetProcAddress(library_kernel32, "GetNumberFormatW");
	pGetNumberOfConsoleInputEvents = (void *)GetProcAddress(library, "GetNumberOfConsoleInputEvents");
	pextGetNumberOfConsoleInputEvents = (void *)GetProcAddress(library_kernel32, "GetNumberOfConsoleInputEvents");
	pGetOEMCP = (void *)GetProcAddress(library, "GetOEMCP");
	pextGetOEMCP = (void *)GetProcAddress(library_kernel32, "GetOEMCP");
	pGetOverlappedResult = (void *)GetProcAddress(library, "GetOverlappedResult");
	pGetPackageFullName = (void *)GetProcAddress(library, "GetPackageFullName");
	pextGetPackageFullName = (void *)GetProcAddress(library_kernel32, "GetPackageFullName");
	pGetPhysicallyInstalledSystemMemory = (void *)GetProcAddress(library, "GetPhysicallyInstalledSystemMemory");
	pextGetPhysicallyInstalledSystemMemory = (void *)GetProcAddress(library_kernel32, "GetPhysicallyInstalledSystemMemory");
	pGetPriorityClass = (void *)GetProcAddress(library, "GetPriorityClass");
	pGetPrivateObjectSecurity = (void *)GetProcAddress(library, "GetPrivateObjectSecurity");
	pGetProcAddress = (void *)GetProcAddress(library, "GetProcAddress");
	pextGetProcAddress = (void *)GetProcAddress(library_kernel32, "GetProcAddress");
	pGetProcessHandleCount = (void *)GetProcAddress(library, "GetProcessHandleCount");
	pGetProcessHeap = (void *)GetProcAddress(library, "GetProcessHeap");
	pGetProcessId = (void *)GetProcAddress(library, "GetProcessId");
	pGetProcessIdOfThread = (void *)GetProcAddress(library, "GetProcessIdOfThread");
	pGetProcessMitigationPolicy = (void *)GetProcAddress(library, "GetProcessMitigationPolicy");
	pGetProcessPreferredUILanguages = (void *)GetProcAddress(library, "GetProcessPreferredUILanguages");
	pextGetProcessPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "GetProcessPreferredUILanguages");
	pGetProcessPriorityBoost = (void *)GetProcAddress(library, "GetProcessPriorityBoost");
	pGetProcessShutdownParameters = (void *)GetProcAddress(library, "GetProcessShutdownParameters");
	pGetProcessTimes = (void *)GetProcAddress(library, "GetProcessTimes");
	pextGetProcessTimes = (void *)GetProcAddress(library_kernel32, "GetProcessTimes");
	pGetProcessVersion = (void *)GetProcAddress(library, "GetProcessVersion");
	pextGetProcessVersion = (void *)GetProcAddress(library_kernel32, "GetProcessVersion");
	pGetProcessWorkingSetSizeEx = (void *)GetProcAddress(library, "GetProcessWorkingSetSizeEx");
	pGetProductInfo = (void *)GetProcAddress(library, "GetProductInfo");
	pextGetProductInfo = (void *)GetProcAddress(library_kernel32, "GetProductInfo");
	pGetQueuedCompletionStatus = (void *)GetProcAddress(library, "GetQueuedCompletionStatus");
	pGetQueuedCompletionStatusEx = (void *)GetProcAddress(library, "GetQueuedCompletionStatusEx");
	pGetSecurityDescriptorControl = (void *)GetProcAddress(library, "GetSecurityDescriptorControl");
	pGetSecurityDescriptorDacl = (void *)GetProcAddress(library, "GetSecurityDescriptorDacl");
	pGetSecurityDescriptorGroup = (void *)GetProcAddress(library, "GetSecurityDescriptorGroup");
	pGetSecurityDescriptorLength = (void *)GetProcAddress(library, "GetSecurityDescriptorLength");
	pGetSecurityDescriptorOwner = (void *)GetProcAddress(library, "GetSecurityDescriptorOwner");
	pGetSecurityDescriptorSacl = (void *)GetProcAddress(library, "GetSecurityDescriptorSacl");
	pGetShortPathNameW = (void *)GetProcAddress(library, "GetShortPathNameW");
	pextGetShortPathNameW = (void *)GetProcAddress(library_kernel32, "GetShortPathNameW");
	pGetSidIdentifierAuthority = (void *)GetProcAddress(library, "GetSidIdentifierAuthority");
	pGetSidLengthRequired = (void *)GetProcAddress(library, "GetSidLengthRequired");
	pGetSidSubAuthority = (void *)GetProcAddress(library, "GetSidSubAuthority");
	pGetSidSubAuthorityCount = (void *)GetProcAddress(library, "GetSidSubAuthorityCount");
	pGetStartupInfoW = (void *)GetProcAddress(library, "GetStartupInfoW");
	pextGetStartupInfoW = (void *)GetProcAddress(library_kernel32, "GetStartupInfoW");
	pGetStdHandle = (void *)GetProcAddress(library, "GetStdHandle");
	pextGetStdHandle = (void *)GetProcAddress(library_kernel32, "GetStdHandle");
	pGetStringTypeA = (void *)GetProcAddress(library, "GetStringTypeA");
	pextGetStringTypeA = (void *)GetProcAddress(library_kernel32, "GetStringTypeA");
	pGetStringTypeExW = (void *)GetProcAddress(library, "GetStringTypeExW");
	pextGetStringTypeExW = (void *)GetProcAddress(library_kernel32, "GetStringTypeExW");
	pGetStringTypeW = (void *)GetProcAddress(library, "GetStringTypeW");
	pextGetStringTypeW = (void *)GetProcAddress(library_kernel32, "GetStringTypeW");
	pGetSystemDefaultLCID = (void *)GetProcAddress(library, "GetSystemDefaultLCID");
	pextGetSystemDefaultLCID = (void *)GetProcAddress(library_kernel32, "GetSystemDefaultLCID");
	pGetSystemDefaultLangID = (void *)GetProcAddress(library, "GetSystemDefaultLangID");
	pextGetSystemDefaultLangID = (void *)GetProcAddress(library_kernel32, "GetSystemDefaultLangID");
	pGetSystemDefaultLocaleName = (void *)GetProcAddress(library, "GetSystemDefaultLocaleName");
	pextGetSystemDefaultLocaleName = (void *)GetProcAddress(library_kernel32, "GetSystemDefaultLocaleName");
	pGetSystemDefaultUILanguage = (void *)GetProcAddress(library, "GetSystemDefaultUILanguage");
	pextGetSystemDefaultUILanguage = (void *)GetProcAddress(library_kernel32, "GetSystemDefaultUILanguage");
	pGetSystemDirectoryA = (void *)GetProcAddress(library, "GetSystemDirectoryA");
	pGetSystemDirectoryW = (void *)GetProcAddress(library, "GetSystemDirectoryW");
	pGetSystemFileCacheSize = (void *)GetProcAddress(library, "GetSystemFileCacheSize");
	pextGetSystemFileCacheSize = (void *)GetProcAddress(library_kernel32, "GetSystemFileCacheSize");
	pGetSystemFirmwareTable = (void *)GetProcAddress(library, "GetSystemFirmwareTable");
	pextGetSystemFirmwareTable = (void *)GetProcAddress(library_kernel32, "GetSystemFirmwareTable");
	pGetSystemInfo = (void *)GetProcAddress(library, "GetSystemInfo");
	pextGetSystemInfo = (void *)GetProcAddress(library_kernel32, "GetSystemInfo");
	pGetSystemPreferredUILanguages = (void *)GetProcAddress(library, "GetSystemPreferredUILanguages");
	pextGetSystemPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "GetSystemPreferredUILanguages");
	pGetSystemTime = (void *)GetProcAddress(library, "GetSystemTime");
	pextGetSystemTime = (void *)GetProcAddress(library_kernel32, "GetSystemTime");
	pGetSystemTimeAdjustment = (void *)GetProcAddress(library, "GetSystemTimeAdjustment");
	pextGetSystemTimeAdjustment = (void *)GetProcAddress(library_kernel32, "GetSystemTimeAdjustment");
	pGetSystemTimeAsFileTime = (void *)GetProcAddress(library, "GetSystemTimeAsFileTime");
	pextGetSystemTimeAsFileTime = (void *)GetProcAddress(library_kernel32, "GetSystemTimeAsFileTime");
	pGetSystemTimePreciseAsFileTime = (void *)GetProcAddress(library, "GetSystemTimePreciseAsFileTime");
	pextGetSystemTimePreciseAsFileTime = (void *)GetProcAddress(library_kernel32, "GetSystemTimePreciseAsFileTime");
	pGetSystemTimes = (void *)GetProcAddress(library, "GetSystemTimes");
	pextGetSystemTimes = (void *)GetProcAddress(library_kernel32, "GetSystemTimes");
	pGetSystemWindowsDirectoryA = (void *)GetProcAddress(library, "GetSystemWindowsDirectoryA");
	pGetSystemWindowsDirectoryW = (void *)GetProcAddress(library, "GetSystemWindowsDirectoryW");
	pGetSystemWow64DirectoryA = (void *)GetProcAddress(library, "GetSystemWow64DirectoryA");
	pextGetSystemWow64DirectoryA = (void *)GetProcAddress(library_kernel32, "GetSystemWow64DirectoryA");
	pGetSystemWow64DirectoryW = (void *)GetProcAddress(library, "GetSystemWow64DirectoryW");
	pextGetSystemWow64DirectoryW = (void *)GetProcAddress(library_kernel32, "GetSystemWow64DirectoryW");
	pGetTempFileNameA = (void *)GetProcAddress(library, "GetTempFileNameA");
	pextGetTempFileNameA = (void *)GetProcAddress(library_kernel32, "GetTempFileNameA");
	pGetTempFileNameW = (void *)GetProcAddress(library, "GetTempFileNameW");
	pextGetTempFileNameW = (void *)GetProcAddress(library_kernel32, "GetTempFileNameW");
	pGetTempPathA = (void *)GetProcAddress(library, "GetTempPathA");
	pextGetTempPathA = (void *)GetProcAddress(library_kernel32, "GetTempPathA");
	pGetTempPathW = (void *)GetProcAddress(library, "GetTempPathW");
	pextGetTempPathW = (void *)GetProcAddress(library_kernel32, "GetTempPathW");
	pGetThreadContext = (void *)GetProcAddress(library, "GetThreadContext");
	pGetThreadErrorMode = (void *)GetProcAddress(library, "GetThreadErrorMode");
	pGetThreadGroupAffinity = (void *)GetProcAddress(library, "GetThreadGroupAffinity");
	pGetThreadIOPendingFlag = (void *)GetProcAddress(library, "GetThreadIOPendingFlag");
	pGetThreadId = (void *)GetProcAddress(library, "GetThreadId");
	pGetThreadLocale = (void *)GetProcAddress(library, "GetThreadLocale");
	pextGetThreadLocale = (void *)GetProcAddress(library_kernel32, "GetThreadLocale");
	pGetThreadPreferredUILanguages = (void *)GetProcAddress(library, "GetThreadPreferredUILanguages");
	pextGetThreadPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "GetThreadPreferredUILanguages");
	pGetThreadPriority = (void *)GetProcAddress(library, "GetThreadPriority");
	pGetThreadPriorityBoost = (void *)GetProcAddress(library, "GetThreadPriorityBoost");
	pGetThreadTimes = (void *)GetProcAddress(library, "GetThreadTimes");
	pGetThreadUILanguage = (void *)GetProcAddress(library, "GetThreadUILanguage");
	pGetTickCount = (void *)GetProcAddress(library, "GetTickCount");
	pextGetTickCount = (void *)GetProcAddress(library_kernel32, "GetTickCount");
	pGetTickCount64 = (void *)GetProcAddress(library, "GetTickCount64");
	pextGetTickCount64 = (void *)GetProcAddress(library_kernel32, "GetTickCount64");
	pGetTimeFormatA = (void *)GetProcAddress(library, "GetTimeFormatA");
	pextGetTimeFormatA = (void *)GetProcAddress(library_kernel32, "GetTimeFormatA");
	pGetTimeFormatEx = (void *)GetProcAddress(library, "GetTimeFormatEx");
	pextGetTimeFormatEx = (void *)GetProcAddress(library_kernel32, "GetTimeFormatEx");
	pGetTimeFormatW = (void *)GetProcAddress(library, "GetTimeFormatW");
	pextGetTimeFormatW = (void *)GetProcAddress(library_kernel32, "GetTimeFormatW");
	pGetTimeZoneInformation = (void *)GetProcAddress(library, "GetTimeZoneInformation");
	pextGetTimeZoneInformation = (void *)GetProcAddress(library_kernel32, "GetTimeZoneInformation");
	pGetTimeZoneInformationForYear = (void *)GetProcAddress(library, "GetTimeZoneInformationForYear");
	pextGetTimeZoneInformationForYear = (void *)GetProcAddress(library_kernel32, "GetTimeZoneInformationForYear");
	pGetTokenInformation = (void *)GetProcAddress(library, "GetTokenInformation");
	pGetTraceEnableFlags = (void *)GetProcAddress(library, "GetTraceEnableFlags");
	pextGetTraceEnableFlags = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableFlags");
	pGetTraceEnableLevel = (void *)GetProcAddress(library, "GetTraceEnableLevel");
	pextGetTraceEnableLevel = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableLevel");
	pGetTraceLoggerHandle = (void *)GetProcAddress(library, "GetTraceLoggerHandle");
	pextGetTraceLoggerHandle = (void *)GetProcAddress(library_ntdll, "EtwGetTraceLoggerHandle");
	pGetUserDefaultLCID = (void *)GetProcAddress(library, "GetUserDefaultLCID");
	pextGetUserDefaultLCID = (void *)GetProcAddress(library_kernel32, "GetUserDefaultLCID");
	pGetUserDefaultLangID = (void *)GetProcAddress(library, "GetUserDefaultLangID");
	pextGetUserDefaultLangID = (void *)GetProcAddress(library_kernel32, "GetUserDefaultLangID");
	pGetUserDefaultLocaleName = (void *)GetProcAddress(library, "GetUserDefaultLocaleName");
	pextGetUserDefaultLocaleName = (void *)GetProcAddress(library_kernel32, "GetUserDefaultLocaleName");
	pGetUserDefaultUILanguage = (void *)GetProcAddress(library, "GetUserDefaultUILanguage");
	pextGetUserDefaultUILanguage = (void *)GetProcAddress(library_kernel32, "GetUserDefaultUILanguage");
	pGetUserGeoID = (void *)GetProcAddress(library, "GetUserGeoID");
	pextGetUserGeoID = (void *)GetProcAddress(library_kernel32, "GetUserGeoID");
	pGetUserPreferredUILanguages = (void *)GetProcAddress(library, "GetUserPreferredUILanguages");
	pextGetUserPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "GetUserPreferredUILanguages");
	pGetVersion = (void *)GetProcAddress(library, "GetVersion");
	pextGetVersion = (void *)GetProcAddress(library_kernel32, "GetVersion");
	pGetVersionExA = (void *)GetProcAddress(library, "GetVersionExA");
	pextGetVersionExA = (void *)GetProcAddress(library_kernel32, "GetVersionExA");
	pGetVersionExW = (void *)GetProcAddress(library, "GetVersionExW");
	pextGetVersionExW = (void *)GetProcAddress(library_kernel32, "GetVersionExW");
	pGetVolumeInformationA = (void *)GetProcAddress(library, "GetVolumeInformationA");
	pextGetVolumeInformationA = (void *)GetProcAddress(library_kernel32, "GetVolumeInformationA");
	pGetVolumeInformationByHandleW = (void *)GetProcAddress(library, "GetVolumeInformationByHandleW");
	pextGetVolumeInformationByHandleW = (void *)GetProcAddress(library_kernel32, "GetVolumeInformationByHandleW");
	pGetVolumeInformationW = (void *)GetProcAddress(library, "GetVolumeInformationW");
	pextGetVolumeInformationW = (void *)GetProcAddress(library_kernel32, "GetVolumeInformationW");
	pGetVolumeNameForVolumeMountPointW = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointW");
	pextGetVolumeNameForVolumeMountPointW = (void *)GetProcAddress(library_kernel32, "GetVolumeNameForVolumeMountPointW");
	pGetVolumePathNameW = (void *)GetProcAddress(library, "GetVolumePathNameW");
	pextGetVolumePathNameW = (void *)GetProcAddress(library_kernel32, "GetVolumePathNameW");
	pGetVolumePathNamesForVolumeNameW = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameW");
	pextGetVolumePathNamesForVolumeNameW = (void *)GetProcAddress(library_kernel32, "GetVolumePathNamesForVolumeNameW");
	pGetWindowsAccountDomainSid = (void *)GetProcAddress(library, "GetWindowsAccountDomainSid");
	pGetWindowsDirectoryA = (void *)GetProcAddress(library, "GetWindowsDirectoryA");
	pGetWindowsDirectoryW = (void *)GetProcAddress(library, "GetWindowsDirectoryW");
	pGetWriteWatch = (void *)GetProcAddress(library, "GetWriteWatch");
	pextGetWriteWatch = (void *)GetProcAddress(library_kernel32, "GetWriteWatch");
	pGlobalAlloc = (void *)GetProcAddress(library, "GlobalAlloc");
	pextGlobalAlloc = (void *)GetProcAddress(library_kernel32, "GlobalAlloc");
	pGlobalFree = (void *)GetProcAddress(library, "GlobalFree");
	pextGlobalFree = (void *)GetProcAddress(library_kernel32, "GlobalFree");
	pGlobalMemoryStatusEx = (void *)GetProcAddress(library, "GlobalMemoryStatusEx");
	pextGlobalMemoryStatusEx = (void *)GetProcAddress(library_kernel32, "GlobalMemoryStatusEx");
	pHashData = (void *)GetProcAddress(library, "HashData");
	pHeapAlloc = (void *)GetProcAddress(library, "HeapAlloc");
	pextHeapAlloc = (void *)GetProcAddress(library_ntdll, "RtlAllocateHeap");
	pHeapCompact = (void *)GetProcAddress(library, "HeapCompact");
	pextHeapCompact = (void *)GetProcAddress(library_kernel32, "HeapCompact");
	pHeapCreate = (void *)GetProcAddress(library, "HeapCreate");
	pextHeapCreate = (void *)GetProcAddress(library_kernel32, "HeapCreate");
	pHeapDestroy = (void *)GetProcAddress(library, "HeapDestroy");
	pextHeapDestroy = (void *)GetProcAddress(library_kernel32, "HeapDestroy");
	pHeapFree = (void *)GetProcAddress(library, "HeapFree");
	pextHeapFree = (void *)GetProcAddress(library_ntdll, "RtlFreeHeap");
	pHeapLock = (void *)GetProcAddress(library, "HeapLock");
	pextHeapLock = (void *)GetProcAddress(library_kernel32, "HeapLock");
	pHeapQueryInformation = (void *)GetProcAddress(library, "HeapQueryInformation");
	pextHeapQueryInformation = (void *)GetProcAddress(library_kernel32, "HeapQueryInformation");
	pHeapReAlloc = (void *)GetProcAddress(library, "HeapReAlloc");
	pextHeapReAlloc = (void *)GetProcAddress(library_ntdll, "RtlReAllocateHeap");
	pHeapSetInformation = (void *)GetProcAddress(library, "HeapSetInformation");
	pextHeapSetInformation = (void *)GetProcAddress(library_kernel32, "HeapSetInformation");
	pHeapSize = (void *)GetProcAddress(library, "HeapSize");
	pextHeapSize = (void *)GetProcAddress(library_ntdll, "RtlSizeHeap");
	pHeapUnlock = (void *)GetProcAddress(library, "HeapUnlock");
	pextHeapUnlock = (void *)GetProcAddress(library_kernel32, "HeapUnlock");
	pHeapValidate = (void *)GetProcAddress(library, "HeapValidate");
	pextHeapValidate = (void *)GetProcAddress(library_kernel32, "HeapValidate");
	pHeapWalk = (void *)GetProcAddress(library, "HeapWalk");
	pextHeapWalk = (void *)GetProcAddress(library_kernel32, "HeapWalk");
	pIdnToAscii = (void *)GetProcAddress(library, "IdnToAscii");
	pextIdnToAscii = (void *)GetProcAddress(library_kernel32, "IdnToAscii");
	pIdnToNameprepUnicode = (void *)GetProcAddress(library, "IdnToNameprepUnicode");
	pextIdnToNameprepUnicode = (void *)GetProcAddress(library_kernel32, "IdnToNameprepUnicode");
	pIdnToUnicode = (void *)GetProcAddress(library, "IdnToUnicode");
	pextIdnToUnicode = (void *)GetProcAddress(library_kernel32, "IdnToUnicode");
	pImpersonateAnonymousToken = (void *)GetProcAddress(library, "ImpersonateAnonymousToken");
	pImpersonateLoggedOnUser = (void *)GetProcAddress(library, "ImpersonateLoggedOnUser");
	pImpersonateNamedPipeClient = (void *)GetProcAddress(library, "ImpersonateNamedPipeClient");
	pImpersonateSelf = (void *)GetProcAddress(library, "ImpersonateSelf");
	pInitOnceBeginInitialize = (void *)GetProcAddress(library, "InitOnceBeginInitialize");
	pextInitOnceBeginInitialize = (void *)GetProcAddress(library_kernel32, "InitOnceBeginInitialize");
	pInitOnceComplete = (void *)GetProcAddress(library, "InitOnceComplete");
	pextInitOnceComplete = (void *)GetProcAddress(library_kernel32, "InitOnceComplete");
	pInitOnceExecuteOnce = (void *)GetProcAddress(library, "InitOnceExecuteOnce");
	pextInitOnceExecuteOnce = (void *)GetProcAddress(library_kernel32, "InitOnceExecuteOnce");
	pInitOnceInitialize = (void *)GetProcAddress(library, "InitOnceInitialize");
	pextInitOnceInitialize = (void *)GetProcAddress(library_ntdll, "RtlRunOnceInitialize");
	pInitializeAcl = (void *)GetProcAddress(library, "InitializeAcl");
	pInitializeConditionVariable = (void *)GetProcAddress(library, "InitializeConditionVariable");
	pextInitializeConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlInitializeConditionVariable");
	pInitializeCriticalSection = (void *)GetProcAddress(library, "InitializeCriticalSection");
	pextInitializeCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlInitializeCriticalSection");
	pInitializeCriticalSectionAndSpinCount = (void *)GetProcAddress(library, "InitializeCriticalSectionAndSpinCount");
	pInitializeCriticalSectionEx = (void *)GetProcAddress(library, "InitializeCriticalSectionEx");
	pInitializeProcThreadAttributeList = (void *)GetProcAddress(library, "InitializeProcThreadAttributeList");
	pInitializeSListHead = (void *)GetProcAddress(library, "InitializeSListHead");
	pextInitializeSListHead = (void *)GetProcAddress(library_ntdll, "RtlInitializeSListHead");
	pInitializeSRWLock = (void *)GetProcAddress(library, "InitializeSRWLock");
	pextInitializeSRWLock = (void *)GetProcAddress(library_ntdll, "RtlInitializeSRWLock");
	pInitializeSecurityDescriptor = (void *)GetProcAddress(library, "InitializeSecurityDescriptor");
	pInitializeSid = (void *)GetProcAddress(library, "InitializeSid");
	pInterlockedCompareExchange = (void *)GetProcAddress(library, "InterlockedCompareExchange");
	pextInterlockedCompareExchange = (void *)GetProcAddress(library_kernel32, "InterlockedCompareExchange");
	pInterlockedCompareExchange64 = (void *)GetProcAddress(library, "InterlockedCompareExchange64");
	pextInterlockedCompareExchange64 = (void *)GetProcAddress(library_ntdll, "RtlInterlockedCompareExchange64");
	pInterlockedDecrement = (void *)GetProcAddress(library, "InterlockedDecrement");
	pextInterlockedDecrement = (void *)GetProcAddress(library_kernel32, "InterlockedDecrement");
	pInterlockedExchange = (void *)GetProcAddress(library, "InterlockedExchange");
	pextInterlockedExchange = (void *)GetProcAddress(library_kernel32, "InterlockedExchange");
	pInterlockedExchangeAdd = (void *)GetProcAddress(library, "InterlockedExchangeAdd");
	pextInterlockedExchangeAdd = (void *)GetProcAddress(library_kernel32, "InterlockedExchangeAdd");
	pInterlockedFlushSList = (void *)GetProcAddress(library, "InterlockedFlushSList");
	pextInterlockedFlushSList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedFlushSList");
	pInterlockedIncrement = (void *)GetProcAddress(library, "InterlockedIncrement");
	pextInterlockedIncrement = (void *)GetProcAddress(library_kernel32, "InterlockedIncrement");
	pInterlockedPopEntrySList = (void *)GetProcAddress(library, "InterlockedPopEntrySList");
	pextInterlockedPopEntrySList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPopEntrySList");
	pInterlockedPushEntrySList = (void *)GetProcAddress(library, "InterlockedPushEntrySList");
	pextInterlockedPushEntrySList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushEntrySList");
	pInterlockedPushListSList = (void *)GetProcAddress(library, "InterlockedPushListSList");
	pextInterlockedPushListSList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushListSList");
	pInterlockedPushListSListEx = (void *)GetProcAddress(library, "InterlockedPushListSListEx");
	pextInterlockedPushListSListEx = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushListSListEx");
	pIsCharAlphaA = (void *)GetProcAddress(library, "IsCharAlphaA");
	pIsCharAlphaNumericA = (void *)GetProcAddress(library, "IsCharAlphaNumericA");
	pIsCharAlphaNumericW = (void *)GetProcAddress(library, "IsCharAlphaNumericW");
	pIsCharAlphaW = (void *)GetProcAddress(library, "IsCharAlphaW");
	pIsCharBlankW = (void *)GetProcAddress(library, "IsCharBlankW");
	pIsCharCntrlW = (void *)GetProcAddress(library, "IsCharCntrlW");
	pIsCharDigitW = (void *)GetProcAddress(library, "IsCharDigitW");
	pIsCharLowerA = (void *)GetProcAddress(library, "IsCharLowerA");
	pIsCharLowerW = (void *)GetProcAddress(library, "IsCharLowerW");
	pIsCharPunctW = (void *)GetProcAddress(library, "IsCharPunctW");
	pIsCharSpaceA = (void *)GetProcAddress(library, "IsCharSpaceA");
	pIsCharSpaceW = (void *)GetProcAddress(library, "IsCharSpaceW");
	pIsCharUpperA = (void *)GetProcAddress(library, "IsCharUpperA");
	pIsCharUpperW = (void *)GetProcAddress(library, "IsCharUpperW");
	pIsCharXDigitW = (void *)GetProcAddress(library, "IsCharXDigitW");
	pIsDBCSLeadByte = (void *)GetProcAddress(library, "IsDBCSLeadByte");
	pextIsDBCSLeadByte = (void *)GetProcAddress(library_kernel32, "IsDBCSLeadByte");
	pIsDBCSLeadByteEx = (void *)GetProcAddress(library, "IsDBCSLeadByteEx");
	pextIsDBCSLeadByteEx = (void *)GetProcAddress(library_kernel32, "IsDBCSLeadByteEx");
	pIsDebuggerPresent = (void *)GetProcAddress(library, "IsDebuggerPresent");
	pextIsDebuggerPresent = (void *)GetProcAddress(library_kernel32, "IsDebuggerPresent");
	pIsInternetESCEnabled = (void *)GetProcAddress(library, "IsInternetESCEnabled");
	pIsNormalizedString = (void *)GetProcAddress(library, "IsNormalizedString");
	pextIsNormalizedString = (void *)GetProcAddress(library_kernel32, "IsNormalizedString");
	pIsProcessInJob = (void *)GetProcAddress(library, "IsProcessInJob");
	pextIsProcessInJob = (void *)GetProcAddress(library_kernel32, "IsProcessInJob");
	pIsProcessorFeaturePresent = (void *)GetProcAddress(library, "IsProcessorFeaturePresent");
	pextIsProcessorFeaturePresent = (void *)GetProcAddress(library_kernel32, "IsProcessorFeaturePresent");
	pIsThreadAFiber = (void *)GetProcAddress(library, "IsThreadAFiber");
	pIsThreadpoolTimerSet = (void *)GetProcAddress(library, "IsThreadpoolTimerSet");
	pextIsThreadpoolTimerSet = (void *)GetProcAddress(library_ntdll, "TpIsTimerSet");
	pIsTokenRestricted = (void *)GetProcAddress(library, "IsTokenRestricted");
	pIsValidAcl = (void *)GetProcAddress(library, "IsValidAcl");
	pIsValidCodePage = (void *)GetProcAddress(library, "IsValidCodePage");
	pextIsValidCodePage = (void *)GetProcAddress(library_kernel32, "IsValidCodePage");
	pIsValidLanguageGroup = (void *)GetProcAddress(library, "IsValidLanguageGroup");
	pextIsValidLanguageGroup = (void *)GetProcAddress(library_kernel32, "IsValidLanguageGroup");
	pIsValidLocale = (void *)GetProcAddress(library, "IsValidLocale");
	pextIsValidLocale = (void *)GetProcAddress(library_kernel32, "IsValidLocale");
	pIsValidLocaleName = (void *)GetProcAddress(library, "IsValidLocaleName");
	pextIsValidLocaleName = (void *)GetProcAddress(library_kernel32, "IsValidLocaleName");
	pIsValidSecurityDescriptor = (void *)GetProcAddress(library, "IsValidSecurityDescriptor");
	pIsValidSid = (void *)GetProcAddress(library, "IsValidSid");
	pIsWellKnownSid = (void *)GetProcAddress(library, "IsWellKnownSid");
	pIsWow64Process = (void *)GetProcAddress(library, "IsWow64Process");
	pK32EmptyWorkingSet = (void *)GetProcAddress(library, "K32EmptyWorkingSet");
	pextK32EmptyWorkingSet = (void *)GetProcAddress(library_kernel32, "K32EmptyWorkingSet");
	pK32EnumDeviceDrivers = (void *)GetProcAddress(library, "K32EnumDeviceDrivers");
	pextK32EnumDeviceDrivers = (void *)GetProcAddress(library_kernel32, "K32EnumDeviceDrivers");
	pK32EnumPageFilesA = (void *)GetProcAddress(library, "K32EnumPageFilesA");
	pextK32EnumPageFilesA = (void *)GetProcAddress(library_kernel32, "K32EnumPageFilesA");
	pK32EnumPageFilesW = (void *)GetProcAddress(library, "K32EnumPageFilesW");
	pextK32EnumPageFilesW = (void *)GetProcAddress(library_kernel32, "K32EnumPageFilesW");
	pK32EnumProcessModules = (void *)GetProcAddress(library, "K32EnumProcessModules");
	pextK32EnumProcessModules = (void *)GetProcAddress(library_kernel32, "K32EnumProcessModules");
	pK32EnumProcessModulesEx = (void *)GetProcAddress(library, "K32EnumProcessModulesEx");
	pextK32EnumProcessModulesEx = (void *)GetProcAddress(library_kernel32, "K32EnumProcessModulesEx");
	pK32EnumProcesses = (void *)GetProcAddress(library, "K32EnumProcesses");
	pextK32EnumProcesses = (void *)GetProcAddress(library_kernel32, "K32EnumProcesses");
	pK32GetDeviceDriverBaseNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameA");
	pextK32GetDeviceDriverBaseNameA = (void *)GetProcAddress(library_kernel32, "K32GetDeviceDriverBaseNameA");
	pK32GetDeviceDriverBaseNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameW");
	pextK32GetDeviceDriverBaseNameW = (void *)GetProcAddress(library_kernel32, "K32GetDeviceDriverBaseNameW");
	pK32GetDeviceDriverFileNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameA");
	pextK32GetDeviceDriverFileNameA = (void *)GetProcAddress(library_kernel32, "K32GetDeviceDriverFileNameA");
	pK32GetDeviceDriverFileNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameW");
	pextK32GetDeviceDriverFileNameW = (void *)GetProcAddress(library_kernel32, "K32GetDeviceDriverFileNameW");
	pK32GetMappedFileNameA = (void *)GetProcAddress(library, "K32GetMappedFileNameA");
	pextK32GetMappedFileNameA = (void *)GetProcAddress(library_kernel32, "K32GetMappedFileNameA");
	pK32GetMappedFileNameW = (void *)GetProcAddress(library, "K32GetMappedFileNameW");
	pextK32GetMappedFileNameW = (void *)GetProcAddress(library_kernel32, "K32GetMappedFileNameW");
	pK32GetModuleBaseNameA = (void *)GetProcAddress(library, "K32GetModuleBaseNameA");
	pextK32GetModuleBaseNameA = (void *)GetProcAddress(library_kernel32, "K32GetModuleBaseNameA");
	pK32GetModuleBaseNameW = (void *)GetProcAddress(library, "K32GetModuleBaseNameW");
	pextK32GetModuleBaseNameW = (void *)GetProcAddress(library_kernel32, "K32GetModuleBaseNameW");
	pK32GetModuleFileNameExA = (void *)GetProcAddress(library, "K32GetModuleFileNameExA");
	pextK32GetModuleFileNameExA = (void *)GetProcAddress(library_kernel32, "K32GetModuleFileNameExA");
	pK32GetModuleFileNameExW = (void *)GetProcAddress(library, "K32GetModuleFileNameExW");
	pextK32GetModuleFileNameExW = (void *)GetProcAddress(library_kernel32, "K32GetModuleFileNameExW");
	pK32GetModuleInformation = (void *)GetProcAddress(library, "K32GetModuleInformation");
	pextK32GetModuleInformation = (void *)GetProcAddress(library_kernel32, "K32GetModuleInformation");
	pK32GetPerformanceInfo = (void *)GetProcAddress(library, "K32GetPerformanceInfo");
	pextK32GetPerformanceInfo = (void *)GetProcAddress(library_kernel32, "K32GetPerformanceInfo");
	pK32GetProcessImageFileNameA = (void *)GetProcAddress(library, "K32GetProcessImageFileNameA");
	pextK32GetProcessImageFileNameA = (void *)GetProcAddress(library_kernel32, "K32GetProcessImageFileNameA");
	pK32GetProcessImageFileNameW = (void *)GetProcAddress(library, "K32GetProcessImageFileNameW");
	pextK32GetProcessImageFileNameW = (void *)GetProcAddress(library_kernel32, "K32GetProcessImageFileNameW");
	pK32GetProcessMemoryInfo = (void *)GetProcAddress(library, "K32GetProcessMemoryInfo");
	pextK32GetProcessMemoryInfo = (void *)GetProcAddress(library_kernel32, "K32GetProcessMemoryInfo");
	pK32GetWsChanges = (void *)GetProcAddress(library, "K32GetWsChanges");
	pextK32GetWsChanges = (void *)GetProcAddress(library_kernel32, "K32GetWsChanges");
	pK32GetWsChangesEx = (void *)GetProcAddress(library, "K32GetWsChangesEx");
	pextK32GetWsChangesEx = (void *)GetProcAddress(library_kernel32, "K32GetWsChangesEx");
	pK32InitializeProcessForWsWatch = (void *)GetProcAddress(library, "K32InitializeProcessForWsWatch");
	pextK32InitializeProcessForWsWatch = (void *)GetProcAddress(library_kernel32, "K32InitializeProcessForWsWatch");
	pK32QueryWorkingSet = (void *)GetProcAddress(library, "K32QueryWorkingSet");
	pextK32QueryWorkingSet = (void *)GetProcAddress(library_kernel32, "K32QueryWorkingSet");
	pK32QueryWorkingSetEx = (void *)GetProcAddress(library, "K32QueryWorkingSetEx");
	pextK32QueryWorkingSetEx = (void *)GetProcAddress(library_kernel32, "K32QueryWorkingSetEx");
	pLCIDToLocaleName = (void *)GetProcAddress(library, "LCIDToLocaleName");
	pextLCIDToLocaleName = (void *)GetProcAddress(library_kernel32, "LCIDToLocaleName");
	pLCMapStringA = (void *)GetProcAddress(library, "LCMapStringA");
	pextLCMapStringA = (void *)GetProcAddress(library_kernel32, "LCMapStringA");
	pLCMapStringEx = (void *)GetProcAddress(library, "LCMapStringEx");
	pextLCMapStringEx = (void *)GetProcAddress(library_kernel32, "LCMapStringEx");
	pLCMapStringW = (void *)GetProcAddress(library, "LCMapStringW");
	pextLCMapStringW = (void *)GetProcAddress(library_kernel32, "LCMapStringW");
	pLeaveCriticalSection = (void *)GetProcAddress(library, "LeaveCriticalSection");
	pextLeaveCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlLeaveCriticalSection");
	pLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library, "LeaveCriticalSectionWhenCallbackReturns");
	pextLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackLeaveCriticalSectionOnCompletion");
	pLoadLibraryA = (void *)GetProcAddress(library, "LoadLibraryA");
	pextLoadLibraryA = (void *)GetProcAddress(library_kernel32, "LoadLibraryA");
	pLoadLibraryExA = (void *)GetProcAddress(library, "LoadLibraryExA");
	pextLoadLibraryExA = (void *)GetProcAddress(library_kernel32, "LoadLibraryExA");
	pLoadLibraryExW = (void *)GetProcAddress(library, "LoadLibraryExW");
	pextLoadLibraryExW = (void *)GetProcAddress(library_kernel32, "LoadLibraryExW");
	pLoadLibraryW = (void *)GetProcAddress(library, "LoadLibraryW");
	pextLoadLibraryW = (void *)GetProcAddress(library_kernel32, "LoadLibraryW");
	pLoadResource = (void *)GetProcAddress(library, "LoadResource");
	pLoadStringA = (void *)GetProcAddress(library, "LoadStringA");
	pLoadStringW = (void *)GetProcAddress(library, "LoadStringW");
	pLocalAlloc = (void *)GetProcAddress(library, "LocalAlloc");
	pextLocalAlloc = (void *)GetProcAddress(library_kernel32, "LocalAlloc");
	pLocalFileTimeToFileTime = (void *)GetProcAddress(library, "LocalFileTimeToFileTime");
	pextLocalFileTimeToFileTime = (void *)GetProcAddress(library_kernel32, "LocalFileTimeToFileTime");
	pLocalFree = (void *)GetProcAddress(library, "LocalFree");
	pextLocalFree = (void *)GetProcAddress(library_kernel32, "LocalFree");
	pLocalLock = (void *)GetProcAddress(library, "LocalLock");
	pextLocalLock = (void *)GetProcAddress(library_kernel32, "LocalLock");
	pLocalReAlloc = (void *)GetProcAddress(library, "LocalReAlloc");
	pextLocalReAlloc = (void *)GetProcAddress(library_kernel32, "LocalReAlloc");
	pLocalUnlock = (void *)GetProcAddress(library, "LocalUnlock");
	pextLocalUnlock = (void *)GetProcAddress(library_kernel32, "LocalUnlock");
	pLocaleNameToLCID = (void *)GetProcAddress(library, "LocaleNameToLCID");
	pextLocaleNameToLCID = (void *)GetProcAddress(library_kernel32, "LocaleNameToLCID");
	pLockFile = (void *)GetProcAddress(library, "LockFile");
	pLockFileEx = (void *)GetProcAddress(library, "LockFileEx");
	pLockResource = (void *)GetProcAddress(library, "LockResource");
	pMakeAbsoluteSD = (void *)GetProcAddress(library, "MakeAbsoluteSD");
	pMakeSelfRelativeSD = (void *)GetProcAddress(library, "MakeSelfRelativeSD");
	pMapGenericMask = (void *)GetProcAddress(library, "MapGenericMask");
	pMapUserPhysicalPages = (void *)GetProcAddress(library, "MapUserPhysicalPages");
	pextMapUserPhysicalPages = (void *)GetProcAddress(library_kernel32, "MapUserPhysicalPages");
	pMapViewOfFile = (void *)GetProcAddress(library, "MapViewOfFile");
	pextMapViewOfFile = (void *)GetProcAddress(library_kernel32, "MapViewOfFile");
	pMapViewOfFileEx = (void *)GetProcAddress(library, "MapViewOfFileEx");
	pextMapViewOfFileEx = (void *)GetProcAddress(library_kernel32, "MapViewOfFileEx");
	pMoveFileExW = (void *)GetProcAddress(library, "MoveFileExW");
	pextMoveFileExW = (void *)GetProcAddress(library_kernel32, "MoveFileExW");
	pMoveFileWithProgressW = (void *)GetProcAddress(library, "MoveFileWithProgressW");
	pextMoveFileWithProgressW = (void *)GetProcAddress(library_kernel32, "MoveFileWithProgressW");
	pMulDiv = (void *)GetProcAddress(library, "MulDiv");
	pextMulDiv = (void *)GetProcAddress(library_kernel32, "MulDiv");
	pMultiByteToWideChar = (void *)GetProcAddress(library, "MultiByteToWideChar");
	pextMultiByteToWideChar = (void *)GetProcAddress(library_kernel32, "MultiByteToWideChar");
	pNeedCurrentDirectoryForExePathA = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathA");
	pextNeedCurrentDirectoryForExePathA = (void *)GetProcAddress(library_kernel32, "NeedCurrentDirectoryForExePathA");
	pNeedCurrentDirectoryForExePathW = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathW");
	pextNeedCurrentDirectoryForExePathW = (void *)GetProcAddress(library_kernel32, "NeedCurrentDirectoryForExePathW");
	pNormalizeString = (void *)GetProcAddress(library, "NormalizeString");
	pextNormalizeString = (void *)GetProcAddress(library_kernel32, "NormalizeString");
	pObjectCloseAuditAlarmW = (void *)GetProcAddress(library, "ObjectCloseAuditAlarmW");
	pObjectDeleteAuditAlarmW = (void *)GetProcAddress(library, "ObjectDeleteAuditAlarmW");
	pObjectOpenAuditAlarmW = (void *)GetProcAddress(library, "ObjectOpenAuditAlarmW");
	pObjectPrivilegeAuditAlarmW = (void *)GetProcAddress(library, "ObjectPrivilegeAuditAlarmW");
	pOpenEventA = (void *)GetProcAddress(library, "OpenEventA");
	pOpenEventW = (void *)GetProcAddress(library, "OpenEventW");
	pOpenFileById = (void *)GetProcAddress(library, "OpenFileById");
	pOpenFileMappingW = (void *)GetProcAddress(library, "OpenFileMappingW");
	pOpenMutexW = (void *)GetProcAddress(library, "OpenMutexW");
	pOpenProcess = (void *)GetProcAddress(library, "OpenProcess");
	pOpenProcessToken = (void *)GetProcAddress(library, "OpenProcessToken");
	pOpenSemaphoreW = (void *)GetProcAddress(library, "OpenSemaphoreW");
	pOpenThread = (void *)GetProcAddress(library, "OpenThread");
	pOpenThreadToken = (void *)GetProcAddress(library, "OpenThreadToken");
	pOpenWaitableTimerW = (void *)GetProcAddress(library, "OpenWaitableTimerW");
	pOutputDebugStringA = (void *)GetProcAddress(library, "OutputDebugStringA");
	pextOutputDebugStringA = (void *)GetProcAddress(library_kernel32, "OutputDebugStringA");
	pOutputDebugStringW = (void *)GetProcAddress(library, "OutputDebugStringW");
	pextOutputDebugStringW = (void *)GetProcAddress(library_kernel32, "OutputDebugStringW");
	pParseURLA = (void *)GetProcAddress(library, "ParseURLA");
	pParseURLW = (void *)GetProcAddress(library, "ParseURLW");
	pPathAddBackslashA = (void *)GetProcAddress(library, "PathAddBackslashA");
	pPathAddBackslashW = (void *)GetProcAddress(library, "PathAddBackslashW");
	pPathAddExtensionA = (void *)GetProcAddress(library, "PathAddExtensionA");
	pPathAddExtensionW = (void *)GetProcAddress(library, "PathAddExtensionW");
	pPathAllocCanonicalize = (void *)GetProcAddress(library, "PathAllocCanonicalize");
	pPathAllocCombine = (void *)GetProcAddress(library, "PathAllocCombine");
	pPathAppendA = (void *)GetProcAddress(library, "PathAppendA");
	pPathAppendW = (void *)GetProcAddress(library, "PathAppendW");
	pPathCanonicalizeA = (void *)GetProcAddress(library, "PathCanonicalizeA");
	pPathCanonicalizeW = (void *)GetProcAddress(library, "PathCanonicalizeW");
	pPathCchAddBackslash = (void *)GetProcAddress(library, "PathCchAddBackslash");
	pPathCchAddBackslashEx = (void *)GetProcAddress(library, "PathCchAddBackslashEx");
	pPathCchAddExtension = (void *)GetProcAddress(library, "PathCchAddExtension");
	pPathCchAppend = (void *)GetProcAddress(library, "PathCchAppend");
	pPathCchAppendEx = (void *)GetProcAddress(library, "PathCchAppendEx");
	pPathCchCanonicalize = (void *)GetProcAddress(library, "PathCchCanonicalize");
	pPathCchCanonicalizeEx = (void *)GetProcAddress(library, "PathCchCanonicalizeEx");
	pPathCchCombine = (void *)GetProcAddress(library, "PathCchCombine");
	pPathCchCombineEx = (void *)GetProcAddress(library, "PathCchCombineEx");
	pPathCchFindExtension = (void *)GetProcAddress(library, "PathCchFindExtension");
	pPathCchIsRoot = (void *)GetProcAddress(library, "PathCchIsRoot");
	pPathCchRemoveBackslash = (void *)GetProcAddress(library, "PathCchRemoveBackslash");
	pPathCchRemoveBackslashEx = (void *)GetProcAddress(library, "PathCchRemoveBackslashEx");
	pPathCchRemoveExtension = (void *)GetProcAddress(library, "PathCchRemoveExtension");
	pPathCchRemoveFileSpec = (void *)GetProcAddress(library, "PathCchRemoveFileSpec");
	pPathCchRenameExtension = (void *)GetProcAddress(library, "PathCchRenameExtension");
	pPathCchSkipRoot = (void *)GetProcAddress(library, "PathCchSkipRoot");
	pPathCchStripPrefix = (void *)GetProcAddress(library, "PathCchStripPrefix");
	pPathCchStripToRoot = (void *)GetProcAddress(library, "PathCchStripToRoot");
	pPathCombineA = (void *)GetProcAddress(library, "PathCombineA");
	pPathCombineW = (void *)GetProcAddress(library, "PathCombineW");
	pPathCommonPrefixA = (void *)GetProcAddress(library, "PathCommonPrefixA");
	pPathCommonPrefixW = (void *)GetProcAddress(library, "PathCommonPrefixW");
	pPathCreateFromUrlA = (void *)GetProcAddress(library, "PathCreateFromUrlA");
	pPathCreateFromUrlAlloc = (void *)GetProcAddress(library, "PathCreateFromUrlAlloc");
	pPathCreateFromUrlW = (void *)GetProcAddress(library, "PathCreateFromUrlW");
	pPathFileExistsA = (void *)GetProcAddress(library, "PathFileExistsA");
	pPathFileExistsW = (void *)GetProcAddress(library, "PathFileExistsW");
	pPathFindExtensionA = (void *)GetProcAddress(library, "PathFindExtensionA");
	pPathFindExtensionW = (void *)GetProcAddress(library, "PathFindExtensionW");
	pPathFindFileNameA = (void *)GetProcAddress(library, "PathFindFileNameA");
	pPathFindFileNameW = (void *)GetProcAddress(library, "PathFindFileNameW");
	pPathFindNextComponentA = (void *)GetProcAddress(library, "PathFindNextComponentA");
	pPathFindNextComponentW = (void *)GetProcAddress(library, "PathFindNextComponentW");
	pPathGetArgsA = (void *)GetProcAddress(library, "PathGetArgsA");
	pPathGetArgsW = (void *)GetProcAddress(library, "PathGetArgsW");
	pPathGetCharTypeA = (void *)GetProcAddress(library, "PathGetCharTypeA");
	pPathGetCharTypeW = (void *)GetProcAddress(library, "PathGetCharTypeW");
	pPathGetDriveNumberA = (void *)GetProcAddress(library, "PathGetDriveNumberA");
	pPathGetDriveNumberW = (void *)GetProcAddress(library, "PathGetDriveNumberW");
	pPathIsFileSpecA = (void *)GetProcAddress(library, "PathIsFileSpecA");
	pPathIsFileSpecW = (void *)GetProcAddress(library, "PathIsFileSpecW");
	pPathIsLFNFileSpecA = (void *)GetProcAddress(library, "PathIsLFNFileSpecA");
	pPathIsLFNFileSpecW = (void *)GetProcAddress(library, "PathIsLFNFileSpecW");
	pPathIsPrefixA = (void *)GetProcAddress(library, "PathIsPrefixA");
	pPathIsPrefixW = (void *)GetProcAddress(library, "PathIsPrefixW");
	pPathIsRelativeA = (void *)GetProcAddress(library, "PathIsRelativeA");
	pPathIsRelativeW = (void *)GetProcAddress(library, "PathIsRelativeW");
	pPathIsRootA = (void *)GetProcAddress(library, "PathIsRootA");
	pPathIsRootW = (void *)GetProcAddress(library, "PathIsRootW");
	pPathIsSameRootA = (void *)GetProcAddress(library, "PathIsSameRootA");
	pPathIsSameRootW = (void *)GetProcAddress(library, "PathIsSameRootW");
	pPathIsUNCA = (void *)GetProcAddress(library, "PathIsUNCA");
	pPathIsUNCEx = (void *)GetProcAddress(library, "PathIsUNCEx");
	pPathIsUNCServerA = (void *)GetProcAddress(library, "PathIsUNCServerA");
	pPathIsUNCServerShareA = (void *)GetProcAddress(library, "PathIsUNCServerShareA");
	pPathIsUNCServerShareW = (void *)GetProcAddress(library, "PathIsUNCServerShareW");
	pPathIsUNCServerW = (void *)GetProcAddress(library, "PathIsUNCServerW");
	pPathIsUNCW = (void *)GetProcAddress(library, "PathIsUNCW");
	pPathIsURLA = (void *)GetProcAddress(library, "PathIsURLA");
	pPathIsURLW = (void *)GetProcAddress(library, "PathIsURLW");
	pPathIsValidCharA = (void *)GetProcAddress(library, "PathIsValidCharA");
	pPathIsValidCharW = (void *)GetProcAddress(library, "PathIsValidCharW");
	pPathMatchSpecA = (void *)GetProcAddress(library, "PathMatchSpecA");
	pPathMatchSpecW = (void *)GetProcAddress(library, "PathMatchSpecW");
	pPathParseIconLocationA = (void *)GetProcAddress(library, "PathParseIconLocationA");
	pPathParseIconLocationW = (void *)GetProcAddress(library, "PathParseIconLocationW");
	pPathQuoteSpacesA = (void *)GetProcAddress(library, "PathQuoteSpacesA");
	pPathQuoteSpacesW = (void *)GetProcAddress(library, "PathQuoteSpacesW");
	pPathRelativePathToA = (void *)GetProcAddress(library, "PathRelativePathToA");
	pPathRelativePathToW = (void *)GetProcAddress(library, "PathRelativePathToW");
	pPathRemoveBackslashA = (void *)GetProcAddress(library, "PathRemoveBackslashA");
	pPathRemoveBackslashW = (void *)GetProcAddress(library, "PathRemoveBackslashW");
	pPathRemoveBlanksA = (void *)GetProcAddress(library, "PathRemoveBlanksA");
	pPathRemoveBlanksW = (void *)GetProcAddress(library, "PathRemoveBlanksW");
	pPathRemoveExtensionA = (void *)GetProcAddress(library, "PathRemoveExtensionA");
	pPathRemoveExtensionW = (void *)GetProcAddress(library, "PathRemoveExtensionW");
	pPathRemoveFileSpecA = (void *)GetProcAddress(library, "PathRemoveFileSpecA");
	pPathRemoveFileSpecW = (void *)GetProcAddress(library, "PathRemoveFileSpecW");
	pPathRenameExtensionA = (void *)GetProcAddress(library, "PathRenameExtensionA");
	pPathRenameExtensionW = (void *)GetProcAddress(library, "PathRenameExtensionW");
	pPathSearchAndQualifyA = (void *)GetProcAddress(library, "PathSearchAndQualifyA");
	pPathSearchAndQualifyW = (void *)GetProcAddress(library, "PathSearchAndQualifyW");
	pPathSkipRootA = (void *)GetProcAddress(library, "PathSkipRootA");
	pPathSkipRootW = (void *)GetProcAddress(library, "PathSkipRootW");
	pPathStripPathA = (void *)GetProcAddress(library, "PathStripPathA");
	pPathStripPathW = (void *)GetProcAddress(library, "PathStripPathW");
	pPathStripToRootA = (void *)GetProcAddress(library, "PathStripToRootA");
	pPathStripToRootW = (void *)GetProcAddress(library, "PathStripToRootW");
	pPathUnExpandEnvStringsA = (void *)GetProcAddress(library, "PathUnExpandEnvStringsA");
	pPathUnExpandEnvStringsW = (void *)GetProcAddress(library, "PathUnExpandEnvStringsW");
	pPathUnquoteSpacesA = (void *)GetProcAddress(library, "PathUnquoteSpacesA");
	pPathUnquoteSpacesW = (void *)GetProcAddress(library, "PathUnquoteSpacesW");
	pPeekConsoleInputA = (void *)GetProcAddress(library, "PeekConsoleInputA");
	pextPeekConsoleInputA = (void *)GetProcAddress(library_kernel32, "PeekConsoleInputA");
	pPeekConsoleInputW = (void *)GetProcAddress(library, "PeekConsoleInputW");
	pextPeekConsoleInputW = (void *)GetProcAddress(library_kernel32, "PeekConsoleInputW");
	pPeekNamedPipe = (void *)GetProcAddress(library, "PeekNamedPipe");
	pPerfCreateInstance = (void *)GetProcAddress(library, "PerfCreateInstance");
	pPerfDeleteInstance = (void *)GetProcAddress(library, "PerfDeleteInstance");
	pPerfSetCounterRefValue = (void *)GetProcAddress(library, "PerfSetCounterRefValue");
	pPerfSetCounterSetInfo = (void *)GetProcAddress(library, "PerfSetCounterSetInfo");
	pPerfStartProvider = (void *)GetProcAddress(library, "PerfStartProvider");
	pPerfStartProviderEx = (void *)GetProcAddress(library, "PerfStartProviderEx");
	pPerfStopProvider = (void *)GetProcAddress(library, "PerfStopProvider");
	pPostQueuedCompletionStatus = (void *)GetProcAddress(library, "PostQueuedCompletionStatus");
	pPrivilegeCheck = (void *)GetProcAddress(library, "PrivilegeCheck");
	pPrivilegedServiceAuditAlarmW = (void *)GetProcAddress(library, "PrivilegedServiceAuditAlarmW");
	pProcessIdToSessionId = (void *)GetProcAddress(library, "ProcessIdToSessionId");
	pextProcessIdToSessionId = (void *)GetProcAddress(library_kernel32, "ProcessIdToSessionId");
	pPulseEvent = (void *)GetProcAddress(library, "PulseEvent");
	pPurgeComm = (void *)GetProcAddress(library, "PurgeComm");
	pextPurgeComm = (void *)GetProcAddress(library_kernel32, "PurgeComm");
	pQISearch = (void *)GetProcAddress(library, "QISearch");
	pQueryActCtxSettingsW = (void *)GetProcAddress(library, "QueryActCtxSettingsW");
	pQueryActCtxW = (void *)GetProcAddress(library, "QueryActCtxW");
	pQueryDepthSList = (void *)GetProcAddress(library, "QueryDepthSList");
	pextQueryDepthSList = (void *)GetProcAddress(library_ntdll, "RtlQueryDepthSList");
	pQueryDosDeviceW = (void *)GetProcAddress(library, "QueryDosDeviceW");
	pextQueryDosDeviceW = (void *)GetProcAddress(library_kernel32, "QueryDosDeviceW");
	pQueryFullProcessImageNameA = (void *)GetProcAddress(library, "QueryFullProcessImageNameA");
	pextQueryFullProcessImageNameA = (void *)GetProcAddress(library_kernel32, "QueryFullProcessImageNameA");
	pQueryFullProcessImageNameW = (void *)GetProcAddress(library, "QueryFullProcessImageNameW");
	pextQueryFullProcessImageNameW = (void *)GetProcAddress(library_kernel32, "QueryFullProcessImageNameW");
	pQueryMemoryResourceNotification = (void *)GetProcAddress(library, "QueryMemoryResourceNotification");
	pextQueryMemoryResourceNotification = (void *)GetProcAddress(library_kernel32, "QueryMemoryResourceNotification");
	pQueryPerformanceCounter = (void *)GetProcAddress(library, "QueryPerformanceCounter");
	pextQueryPerformanceCounter = (void *)GetProcAddress(library_kernel32, "QueryPerformanceCounter");
	pQueryPerformanceFrequency = (void *)GetProcAddress(library, "QueryPerformanceFrequency");
	pextQueryPerformanceFrequency = (void *)GetProcAddress(library_kernel32, "QueryPerformanceFrequency");
	pQueryProcessCycleTime = (void *)GetProcAddress(library, "QueryProcessCycleTime");
	pextQueryProcessCycleTime = (void *)GetProcAddress(library_kernel32, "QueryProcessCycleTime");
	pQueryThreadCycleTime = (void *)GetProcAddress(library, "QueryThreadCycleTime");
	pextQueryThreadCycleTime = (void *)GetProcAddress(library_kernel32, "QueryThreadCycleTime");
	pQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "QueryUnbiasedInterruptTime");
	pextQueryUnbiasedInterruptTime = (void *)GetProcAddress(library_kernel32, "QueryUnbiasedInterruptTime");
	pQueueUserAPC = (void *)GetProcAddress(library, "QueueUserAPC");
	pQueueUserWorkItem = (void *)GetProcAddress(library, "QueueUserWorkItem");
	pQuirkIsEnabled = (void *)GetProcAddress(library, "QuirkIsEnabled");
	pQuirkIsEnabled3 = (void *)GetProcAddress(library, "QuirkIsEnabled3");
	pRaiseException = (void *)GetProcAddress(library, "RaiseException");
	pextRaiseException = (void *)GetProcAddress(library_kernel32, "RaiseException");
	pReOpenFile = (void *)GetProcAddress(library, "ReOpenFile");
	pReadConsoleA = (void *)GetProcAddress(library, "ReadConsoleA");
	pextReadConsoleA = (void *)GetProcAddress(library_kernel32, "ReadConsoleA");
	pReadConsoleInputA = (void *)GetProcAddress(library, "ReadConsoleInputA");
	pextReadConsoleInputA = (void *)GetProcAddress(library_kernel32, "ReadConsoleInputA");
	pReadConsoleInputW = (void *)GetProcAddress(library, "ReadConsoleInputW");
	pextReadConsoleInputW = (void *)GetProcAddress(library_kernel32, "ReadConsoleInputW");
	pReadConsoleOutputA = (void *)GetProcAddress(library, "ReadConsoleOutputA");
	pextReadConsoleOutputA = (void *)GetProcAddress(library_kernel32, "ReadConsoleOutputA");
	pReadConsoleOutputAttribute = (void *)GetProcAddress(library, "ReadConsoleOutputAttribute");
	pextReadConsoleOutputAttribute = (void *)GetProcAddress(library_kernel32, "ReadConsoleOutputAttribute");
	pReadConsoleOutputCharacterA = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterA");
	pextReadConsoleOutputCharacterA = (void *)GetProcAddress(library_kernel32, "ReadConsoleOutputCharacterA");
	pReadConsoleOutputCharacterW = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterW");
	pextReadConsoleOutputCharacterW = (void *)GetProcAddress(library_kernel32, "ReadConsoleOutputCharacterW");
	pReadConsoleOutputW = (void *)GetProcAddress(library, "ReadConsoleOutputW");
	pextReadConsoleOutputW = (void *)GetProcAddress(library_kernel32, "ReadConsoleOutputW");
	pReadConsoleW = (void *)GetProcAddress(library, "ReadConsoleW");
	pextReadConsoleW = (void *)GetProcAddress(library_kernel32, "ReadConsoleW");
	pReadDirectoryChangesW = (void *)GetProcAddress(library, "ReadDirectoryChangesW");
	pextReadDirectoryChangesW = (void *)GetProcAddress(library_kernel32, "ReadDirectoryChangesW");
	pReadFile = (void *)GetProcAddress(library, "ReadFile");
	pReadFileEx = (void *)GetProcAddress(library, "ReadFileEx");
	pReadFileScatter = (void *)GetProcAddress(library, "ReadFileScatter");
	pReadProcessMemory = (void *)GetProcAddress(library, "ReadProcessMemory");
	pextReadProcessMemory = (void *)GetProcAddress(library_kernel32, "ReadProcessMemory");
	pRegCloseKey = (void *)GetProcAddress(library, "RegCloseKey");
	pRegCopyTreeW = (void *)GetProcAddress(library, "RegCopyTreeW");
	pRegCreateKeyExA = (void *)GetProcAddress(library, "RegCreateKeyExA");
	pRegCreateKeyExW = (void *)GetProcAddress(library, "RegCreateKeyExW");
	pRegDeleteKeyExA = (void *)GetProcAddress(library, "RegDeleteKeyExA");
	pRegDeleteKeyExW = (void *)GetProcAddress(library, "RegDeleteKeyExW");
	pRegDeleteKeyValueA = (void *)GetProcAddress(library, "RegDeleteKeyValueA");
	pRegDeleteKeyValueW = (void *)GetProcAddress(library, "RegDeleteKeyValueW");
	pRegDeleteTreeA = (void *)GetProcAddress(library, "RegDeleteTreeA");
	pRegDeleteTreeW = (void *)GetProcAddress(library, "RegDeleteTreeW");
	pRegDeleteValueA = (void *)GetProcAddress(library, "RegDeleteValueA");
	pRegDeleteValueW = (void *)GetProcAddress(library, "RegDeleteValueW");
	pRegEnumKeyExA = (void *)GetProcAddress(library, "RegEnumKeyExA");
	pRegEnumKeyExW = (void *)GetProcAddress(library, "RegEnumKeyExW");
	pRegEnumValueA = (void *)GetProcAddress(library, "RegEnumValueA");
	pRegEnumValueW = (void *)GetProcAddress(library, "RegEnumValueW");
	pRegFlushKey = (void *)GetProcAddress(library, "RegFlushKey");
	pRegGetKeySecurity = (void *)GetProcAddress(library, "RegGetKeySecurity");
	pRegGetValueA = (void *)GetProcAddress(library, "RegGetValueA");
	pRegGetValueW = (void *)GetProcAddress(library, "RegGetValueW");
	pRegLoadAppKeyA = (void *)GetProcAddress(library, "RegLoadAppKeyA");
	pRegLoadAppKeyW = (void *)GetProcAddress(library, "RegLoadAppKeyW");
	pRegLoadKeyA = (void *)GetProcAddress(library, "RegLoadKeyA");
	pRegLoadKeyW = (void *)GetProcAddress(library, "RegLoadKeyW");
	pRegLoadMUIStringA = (void *)GetProcAddress(library, "RegLoadMUIStringA");
	pRegLoadMUIStringW = (void *)GetProcAddress(library, "RegLoadMUIStringW");
	pRegNotifyChangeKeyValue = (void *)GetProcAddress(library, "RegNotifyChangeKeyValue");
	pRegOpenCurrentUser = (void *)GetProcAddress(library, "RegOpenCurrentUser");
	pRegOpenKeyExA = (void *)GetProcAddress(library, "RegOpenKeyExA");
	pRegOpenKeyExW = (void *)GetProcAddress(library, "RegOpenKeyExW");
	pRegOpenUserClassesRoot = (void *)GetProcAddress(library, "RegOpenUserClassesRoot");
	pRegQueryInfoKeyA = (void *)GetProcAddress(library, "RegQueryInfoKeyA");
	pRegQueryInfoKeyW = (void *)GetProcAddress(library, "RegQueryInfoKeyW");
	pRegQueryValueExA = (void *)GetProcAddress(library, "RegQueryValueExA");
	pRegQueryValueExW = (void *)GetProcAddress(library, "RegQueryValueExW");
	pRegRestoreKeyA = (void *)GetProcAddress(library, "RegRestoreKeyA");
	pRegRestoreKeyW = (void *)GetProcAddress(library, "RegRestoreKeyW");
	pRegSaveKeyExA = (void *)GetProcAddress(library, "RegSaveKeyExA");
	pRegSaveKeyExW = (void *)GetProcAddress(library, "RegSaveKeyExW");
	pRegSetKeySecurity = (void *)GetProcAddress(library, "RegSetKeySecurity");
	pRegSetKeyValueA = (void *)GetProcAddress(library, "RegSetKeyValueA");
	pRegSetKeyValueW = (void *)GetProcAddress(library, "RegSetKeyValueW");
	pRegSetValueExA = (void *)GetProcAddress(library, "RegSetValueExA");
	pRegSetValueExW = (void *)GetProcAddress(library, "RegSetValueExW");
	pRegUnLoadKeyA = (void *)GetProcAddress(library, "RegUnLoadKeyA");
	pRegUnLoadKeyW = (void *)GetProcAddress(library, "RegUnLoadKeyW");
	pRegisterTraceGuidsW = (void *)GetProcAddress(library, "RegisterTraceGuidsW");
	pextRegisterTraceGuidsW = (void *)GetProcAddress(library_ntdll, "EtwRegisterTraceGuidsW");
	pRegisterWaitForSingleObjectEx = (void *)GetProcAddress(library, "RegisterWaitForSingleObjectEx");
	pReleaseActCtx = (void *)GetProcAddress(library, "ReleaseActCtx");
	pReleaseMutex = (void *)GetProcAddress(library, "ReleaseMutex");
	pReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseMutexWhenCallbackReturns");
	pextReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseMutexOnCompletion");
	pReleaseSRWLockExclusive = (void *)GetProcAddress(library, "ReleaseSRWLockExclusive");
	pextReleaseSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockExclusive");
	pReleaseSRWLockShared = (void *)GetProcAddress(library, "ReleaseSRWLockShared");
	pextReleaseSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockShared");
	pReleaseSemaphore = (void *)GetProcAddress(library, "ReleaseSemaphore");
	pReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseSemaphoreWhenCallbackReturns");
	pextReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseSemaphoreOnCompletion");
	pRemapPredefinedHandleInternal = (void *)GetProcAddress(library, "RemapPredefinedHandleInternal");
	pRemoveDirectoryA = (void *)GetProcAddress(library, "RemoveDirectoryA");
	pextRemoveDirectoryA = (void *)GetProcAddress(library_kernel32, "RemoveDirectoryA");
	pRemoveDirectoryW = (void *)GetProcAddress(library, "RemoveDirectoryW");
	pextRemoveDirectoryW = (void *)GetProcAddress(library_kernel32, "RemoveDirectoryW");
	pRemoveDllDirectory = (void *)GetProcAddress(library, "RemoveDllDirectory");
	pextRemoveDllDirectory = (void *)GetProcAddress(library_kernel32, "RemoveDllDirectory");
	pRemoveVectoredContinueHandler = (void *)GetProcAddress(library, "RemoveVectoredContinueHandler");
	pextRemoveVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredContinueHandler");
	pRemoveVectoredExceptionHandler = (void *)GetProcAddress(library, "RemoveVectoredExceptionHandler");
	pextRemoveVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredExceptionHandler");
	pReplaceFileW = (void *)GetProcAddress(library, "ReplaceFileW");
	pextReplaceFileW = (void *)GetProcAddress(library_kernel32, "ReplaceFileW");
	pResetEvent = (void *)GetProcAddress(library, "ResetEvent");
	pResetWriteWatch = (void *)GetProcAddress(library, "ResetWriteWatch");
	pextResetWriteWatch = (void *)GetProcAddress(library_kernel32, "ResetWriteWatch");
	pResolveDelayLoadedAPI = (void *)GetProcAddress(library, "ResolveDelayLoadedAPI");
	pextResolveDelayLoadedAPI = (void *)GetProcAddress(library_kernel32, "ResolveDelayLoadedAPI");
	pResolveLocaleName = (void *)GetProcAddress(library, "ResolveLocaleName");
	pextResolveLocaleName = (void *)GetProcAddress(library_kernel32, "ResolveLocaleName");
	pRestoreLastError = (void *)GetProcAddress(library, "RestoreLastError");
	pextRestoreLastError = (void *)GetProcAddress(library_ntdll, "RtlRestoreLastWin32Error");
	pResumeThread = (void *)GetProcAddress(library, "ResumeThread");
	pRevertToSelf = (void *)GetProcAddress(library, "RevertToSelf");
	pSHExpandEnvironmentStringsA = (void *)GetProcAddress(library, "SHExpandEnvironmentStringsA");
	pextSHExpandEnvironmentStringsA = (void *)GetProcAddress(library_kernel32, "ExpandEnvironmentStringsA");
	pSHExpandEnvironmentStringsW = (void *)GetProcAddress(library, "SHExpandEnvironmentStringsW");
	pextSHExpandEnvironmentStringsW = (void *)GetProcAddress(library_kernel32, "ExpandEnvironmentStringsW");
	pSHLoadIndirectString = (void *)GetProcAddress(library, "SHLoadIndirectString");
	pSHRegCloseUSKey = (void *)GetProcAddress(library, "SHRegCloseUSKey");
	pSHRegCreateUSKeyA = (void *)GetProcAddress(library, "SHRegCreateUSKeyA");
	pSHRegCreateUSKeyW = (void *)GetProcAddress(library, "SHRegCreateUSKeyW");
	pSHRegDeleteEmptyUSKeyA = (void *)GetProcAddress(library, "SHRegDeleteEmptyUSKeyA");
	pSHRegDeleteEmptyUSKeyW = (void *)GetProcAddress(library, "SHRegDeleteEmptyUSKeyW");
	pSHRegDeleteUSValueA = (void *)GetProcAddress(library, "SHRegDeleteUSValueA");
	pSHRegDeleteUSValueW = (void *)GetProcAddress(library, "SHRegDeleteUSValueW");
	pSHRegEnumUSKeyA = (void *)GetProcAddress(library, "SHRegEnumUSKeyA");
	pSHRegEnumUSKeyW = (void *)GetProcAddress(library, "SHRegEnumUSKeyW");
	pSHRegEnumUSValueA = (void *)GetProcAddress(library, "SHRegEnumUSValueA");
	pSHRegEnumUSValueW = (void *)GetProcAddress(library, "SHRegEnumUSValueW");
	pSHRegGetBoolUSValueA = (void *)GetProcAddress(library, "SHRegGetBoolUSValueA");
	pSHRegGetBoolUSValueW = (void *)GetProcAddress(library, "SHRegGetBoolUSValueW");
	pSHRegGetUSValueA = (void *)GetProcAddress(library, "SHRegGetUSValueA");
	pSHRegGetUSValueW = (void *)GetProcAddress(library, "SHRegGetUSValueW");
	pSHRegOpenUSKeyA = (void *)GetProcAddress(library, "SHRegOpenUSKeyA");
	pSHRegOpenUSKeyW = (void *)GetProcAddress(library, "SHRegOpenUSKeyW");
	pSHRegQueryInfoUSKeyA = (void *)GetProcAddress(library, "SHRegQueryInfoUSKeyA");
	pSHRegQueryInfoUSKeyW = (void *)GetProcAddress(library, "SHRegQueryInfoUSKeyW");
	pSHRegQueryUSValueA = (void *)GetProcAddress(library, "SHRegQueryUSValueA");
	pSHRegQueryUSValueW = (void *)GetProcAddress(library, "SHRegQueryUSValueW");
	pSHRegSetUSValueA = (void *)GetProcAddress(library, "SHRegSetUSValueA");
	pSHRegSetUSValueW = (void *)GetProcAddress(library, "SHRegSetUSValueW");
	pSHRegWriteUSValueA = (void *)GetProcAddress(library, "SHRegWriteUSValueA");
	pSHRegWriteUSValueW = (void *)GetProcAddress(library, "SHRegWriteUSValueW");
	pSHTruncateString = (void *)GetProcAddress(library, "SHTruncateString");
	pScrollConsoleScreenBufferA = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferA");
	pextScrollConsoleScreenBufferA = (void *)GetProcAddress(library_kernel32, "ScrollConsoleScreenBufferA");
	pScrollConsoleScreenBufferW = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferW");
	pextScrollConsoleScreenBufferW = (void *)GetProcAddress(library_kernel32, "ScrollConsoleScreenBufferW");
	pSearchPathA = (void *)GetProcAddress(library, "SearchPathA");
	pextSearchPathA = (void *)GetProcAddress(library_kernel32, "SearchPathA");
	pSearchPathW = (void *)GetProcAddress(library, "SearchPathW");
	pextSearchPathW = (void *)GetProcAddress(library_kernel32, "SearchPathW");
	pSetAclInformation = (void *)GetProcAddress(library, "SetAclInformation");
	pSetCalendarInfoW = (void *)GetProcAddress(library, "SetCalendarInfoW");
	pextSetCalendarInfoW = (void *)GetProcAddress(library_kernel32, "SetCalendarInfoW");
	pSetCommBreak = (void *)GetProcAddress(library, "SetCommBreak");
	pextSetCommBreak = (void *)GetProcAddress(library_kernel32, "SetCommBreak");
	pSetCommConfig = (void *)GetProcAddress(library, "SetCommConfig");
	pextSetCommConfig = (void *)GetProcAddress(library_kernel32, "SetCommConfig");
	pSetCommMask = (void *)GetProcAddress(library, "SetCommMask");
	pextSetCommMask = (void *)GetProcAddress(library_kernel32, "SetCommMask");
	pSetCommState = (void *)GetProcAddress(library, "SetCommState");
	pextSetCommState = (void *)GetProcAddress(library_kernel32, "SetCommState");
	pSetCommTimeouts = (void *)GetProcAddress(library, "SetCommTimeouts");
	pextSetCommTimeouts = (void *)GetProcAddress(library_kernel32, "SetCommTimeouts");
	pSetComputerNameA = (void *)GetProcAddress(library, "SetComputerNameA");
	pextSetComputerNameA = (void *)GetProcAddress(library_kernel32, "SetComputerNameA");
	pSetComputerNameExA = (void *)GetProcAddress(library, "SetComputerNameExA");
	pextSetComputerNameExA = (void *)GetProcAddress(library_kernel32, "SetComputerNameExA");
	pSetComputerNameExW = (void *)GetProcAddress(library, "SetComputerNameExW");
	pextSetComputerNameExW = (void *)GetProcAddress(library_kernel32, "SetComputerNameExW");
	pSetComputerNameW = (void *)GetProcAddress(library, "SetComputerNameW");
	pextSetComputerNameW = (void *)GetProcAddress(library_kernel32, "SetComputerNameW");
	pSetConsoleActiveScreenBuffer = (void *)GetProcAddress(library, "SetConsoleActiveScreenBuffer");
	pextSetConsoleActiveScreenBuffer = (void *)GetProcAddress(library_kernel32, "SetConsoleActiveScreenBuffer");
	pSetConsoleCP = (void *)GetProcAddress(library, "SetConsoleCP");
	pextSetConsoleCP = (void *)GetProcAddress(library_kernel32, "SetConsoleCP");
	pSetConsoleCtrlHandler = (void *)GetProcAddress(library, "SetConsoleCtrlHandler");
	pextSetConsoleCtrlHandler = (void *)GetProcAddress(library_kernel32, "SetConsoleCtrlHandler");
	pSetConsoleCursorInfo = (void *)GetProcAddress(library, "SetConsoleCursorInfo");
	pextSetConsoleCursorInfo = (void *)GetProcAddress(library_kernel32, "SetConsoleCursorInfo");
	pSetConsoleCursorPosition = (void *)GetProcAddress(library, "SetConsoleCursorPosition");
	pextSetConsoleCursorPosition = (void *)GetProcAddress(library_kernel32, "SetConsoleCursorPosition");
	pSetConsoleInputExeNameA = (void *)GetProcAddress(library, "SetConsoleInputExeNameA");
	pextSetConsoleInputExeNameA = (void *)GetProcAddress(library_kernel32, "SetConsoleInputExeNameA");
	pSetConsoleInputExeNameW = (void *)GetProcAddress(library, "SetConsoleInputExeNameW");
	pextSetConsoleInputExeNameW = (void *)GetProcAddress(library_kernel32, "SetConsoleInputExeNameW");
	pSetConsoleMode = (void *)GetProcAddress(library, "SetConsoleMode");
	pextSetConsoleMode = (void *)GetProcAddress(library_kernel32, "SetConsoleMode");
	pSetConsoleOutputCP = (void *)GetProcAddress(library, "SetConsoleOutputCP");
	pextSetConsoleOutputCP = (void *)GetProcAddress(library_kernel32, "SetConsoleOutputCP");
	pSetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "SetConsoleScreenBufferInfoEx");
	pextSetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library_kernel32, "SetConsoleScreenBufferInfoEx");
	pSetConsoleScreenBufferSize = (void *)GetProcAddress(library, "SetConsoleScreenBufferSize");
	pextSetConsoleScreenBufferSize = (void *)GetProcAddress(library_kernel32, "SetConsoleScreenBufferSize");
	pSetConsoleTextAttribute = (void *)GetProcAddress(library, "SetConsoleTextAttribute");
	pextSetConsoleTextAttribute = (void *)GetProcAddress(library_kernel32, "SetConsoleTextAttribute");
	pSetConsoleTitleW = (void *)GetProcAddress(library, "SetConsoleTitleW");
	pextSetConsoleTitleW = (void *)GetProcAddress(library_kernel32, "SetConsoleTitleW");
	pSetConsoleWindowInfo = (void *)GetProcAddress(library, "SetConsoleWindowInfo");
	pextSetConsoleWindowInfo = (void *)GetProcAddress(library_kernel32, "SetConsoleWindowInfo");
	pSetCriticalSectionSpinCount = (void *)GetProcAddress(library, "SetCriticalSectionSpinCount");
	pextSetCriticalSectionSpinCount = (void *)GetProcAddress(library_ntdll, "RtlSetCriticalSectionSpinCount");
	pSetCurrentDirectoryA = (void *)GetProcAddress(library, "SetCurrentDirectoryA");
	pextSetCurrentDirectoryA = (void *)GetProcAddress(library_kernel32, "SetCurrentDirectoryA");
	pSetCurrentDirectoryW = (void *)GetProcAddress(library, "SetCurrentDirectoryW");
	pextSetCurrentDirectoryW = (void *)GetProcAddress(library_kernel32, "SetCurrentDirectoryW");
	pSetDefaultDllDirectories = (void *)GetProcAddress(library, "SetDefaultDllDirectories");
	pextSetDefaultDllDirectories = (void *)GetProcAddress(library_kernel32, "SetDefaultDllDirectories");
	pSetEndOfFile = (void *)GetProcAddress(library, "SetEndOfFile");
	pSetEnvironmentVariableA = (void *)GetProcAddress(library, "SetEnvironmentVariableA");
	pextSetEnvironmentVariableA = (void *)GetProcAddress(library_kernel32, "SetEnvironmentVariableA");
	pSetEnvironmentVariableW = (void *)GetProcAddress(library, "SetEnvironmentVariableW");
	pextSetEnvironmentVariableW = (void *)GetProcAddress(library_kernel32, "SetEnvironmentVariableW");
	pSetErrorMode = (void *)GetProcAddress(library, "SetErrorMode");
	pSetEvent = (void *)GetProcAddress(library, "SetEvent");
	pSetEventWhenCallbackReturns = (void *)GetProcAddress(library, "SetEventWhenCallbackReturns");
	pextSetEventWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackSetEventOnCompletion");
	pSetFileApisToANSI = (void *)GetProcAddress(library, "SetFileApisToANSI");
	pSetFileApisToOEM = (void *)GetProcAddress(library, "SetFileApisToOEM");
	pSetFileAttributesA = (void *)GetProcAddress(library, "SetFileAttributesA");
	pSetFileAttributesW = (void *)GetProcAddress(library, "SetFileAttributesW");
	pSetFileInformationByHandle = (void *)GetProcAddress(library, "SetFileInformationByHandle");
	pSetFilePointer = (void *)GetProcAddress(library, "SetFilePointer");
	pSetFilePointerEx = (void *)GetProcAddress(library, "SetFilePointerEx");
	pSetFileSecurityW = (void *)GetProcAddress(library, "SetFileSecurityW");
	pSetFileTime = (void *)GetProcAddress(library, "SetFileTime");
	pSetFileValidData = (void *)GetProcAddress(library, "SetFileValidData");
	pSetHandleCount = (void *)GetProcAddress(library, "SetHandleCount");
	pextSetHandleCount = (void *)GetProcAddress(library_kernel32, "SetHandleCount");
	pSetHandleInformation = (void *)GetProcAddress(library, "SetHandleInformation");
	pextSetHandleInformation = (void *)GetProcAddress(library_kernel32, "SetHandleInformation");
	pSetKernelObjectSecurity = (void *)GetProcAddress(library, "SetKernelObjectSecurity");
	pSetLastError = (void *)GetProcAddress(library, "SetLastError");
	pextSetLastError = (void *)GetProcAddress(library_ntdll, "RtlSetLastWin32Error");
	pSetLocalTime = (void *)GetProcAddress(library, "SetLocalTime");
	pextSetLocalTime = (void *)GetProcAddress(library_kernel32, "SetLocalTime");
	pSetLocaleInfoW = (void *)GetProcAddress(library, "SetLocaleInfoW");
	pextSetLocaleInfoW = (void *)GetProcAddress(library_kernel32, "SetLocaleInfoW");
	pSetNamedPipeHandleState = (void *)GetProcAddress(library, "SetNamedPipeHandleState");
	pSetPriorityClass = (void *)GetProcAddress(library, "SetPriorityClass");
	pSetPrivateObjectSecurity = (void *)GetProcAddress(library, "SetPrivateObjectSecurity");
	pSetProcessAffinityUpdateMode = (void *)GetProcAddress(library, "SetProcessAffinityUpdateMode");
	pSetProcessMitigationPolicy = (void *)GetProcAddress(library, "SetProcessMitigationPolicy");
	pSetProcessPreferredUILanguages = (void *)GetProcAddress(library, "SetProcessPreferredUILanguages");
	pextSetProcessPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "SetProcessPreferredUILanguages");
	pSetProcessPriorityBoost = (void *)GetProcAddress(library, "SetProcessPriorityBoost");
	pSetProcessShutdownParameters = (void *)GetProcAddress(library, "SetProcessShutdownParameters");
	pSetProcessWorkingSetSizeEx = (void *)GetProcAddress(library, "SetProcessWorkingSetSizeEx");
	pSetSecurityDescriptorControl = (void *)GetProcAddress(library, "SetSecurityDescriptorControl");
	pSetSecurityDescriptorDacl = (void *)GetProcAddress(library, "SetSecurityDescriptorDacl");
	pSetSecurityDescriptorGroup = (void *)GetProcAddress(library, "SetSecurityDescriptorGroup");
	pSetSecurityDescriptorOwner = (void *)GetProcAddress(library, "SetSecurityDescriptorOwner");
	pSetSecurityDescriptorSacl = (void *)GetProcAddress(library, "SetSecurityDescriptorSacl");
	pSetStdHandle = (void *)GetProcAddress(library, "SetStdHandle");
	pextSetStdHandle = (void *)GetProcAddress(library_kernel32, "SetStdHandle");
	pSetSystemFileCacheSize = (void *)GetProcAddress(library, "SetSystemFileCacheSize");
	pextSetSystemFileCacheSize = (void *)GetProcAddress(library_kernel32, "SetSystemFileCacheSize");
	pSetSystemTime = (void *)GetProcAddress(library, "SetSystemTime");
	pextSetSystemTime = (void *)GetProcAddress(library_kernel32, "SetSystemTime");
	pSetSystemTimeAdjustment = (void *)GetProcAddress(library, "SetSystemTimeAdjustment");
	pextSetSystemTimeAdjustment = (void *)GetProcAddress(library_kernel32, "SetSystemTimeAdjustment");
	pSetThreadContext = (void *)GetProcAddress(library, "SetThreadContext");
	pSetThreadErrorMode = (void *)GetProcAddress(library, "SetThreadErrorMode");
	pSetThreadGroupAffinity = (void *)GetProcAddress(library, "SetThreadGroupAffinity");
	pSetThreadIdealProcessor = (void *)GetProcAddress(library, "SetThreadIdealProcessor");
	pSetThreadIdealProcessorEx = (void *)GetProcAddress(library, "SetThreadIdealProcessorEx");
	pSetThreadLocale = (void *)GetProcAddress(library, "SetThreadLocale");
	pextSetThreadLocale = (void *)GetProcAddress(library_kernel32, "SetThreadLocale");
	pSetThreadPreferredUILanguages = (void *)GetProcAddress(library, "SetThreadPreferredUILanguages");
	pextSetThreadPreferredUILanguages = (void *)GetProcAddress(library_kernel32, "SetThreadPreferredUILanguages");
	pSetThreadPriority = (void *)GetProcAddress(library, "SetThreadPriority");
	pSetThreadPriorityBoost = (void *)GetProcAddress(library, "SetThreadPriorityBoost");
	pSetThreadStackGuarantee = (void *)GetProcAddress(library, "SetThreadStackGuarantee");
	pSetThreadToken = (void *)GetProcAddress(library, "SetThreadToken");
	pSetThreadUILanguage = (void *)GetProcAddress(library, "SetThreadUILanguage");
	pextSetThreadUILanguage = (void *)GetProcAddress(library_kernel32, "SetThreadUILanguage");
	pSetThreadpoolThreadMaximum = (void *)GetProcAddress(library, "SetThreadpoolThreadMaximum");
	pextSetThreadpoolThreadMaximum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMaxThreads");
	pSetThreadpoolThreadMinimum = (void *)GetProcAddress(library, "SetThreadpoolThreadMinimum");
	pextSetThreadpoolThreadMinimum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMinThreads");
	pSetThreadpoolTimer = (void *)GetProcAddress(library, "SetThreadpoolTimer");
	pextSetThreadpoolTimer = (void *)GetProcAddress(library_ntdll, "TpSetTimer");
	pSetThreadpoolWait = (void *)GetProcAddress(library, "SetThreadpoolWait");
	pextSetThreadpoolWait = (void *)GetProcAddress(library_ntdll, "TpSetWait");
	pSetTimeZoneInformation = (void *)GetProcAddress(library, "SetTimeZoneInformation");
	pextSetTimeZoneInformation = (void *)GetProcAddress(library_kernel32, "SetTimeZoneInformation");
	pSetTokenInformation = (void *)GetProcAddress(library, "SetTokenInformation");
	pSetUnhandledExceptionFilter = (void *)GetProcAddress(library, "SetUnhandledExceptionFilter");
	pextSetUnhandledExceptionFilter = (void *)GetProcAddress(library_kernel32, "SetUnhandledExceptionFilter");
	pSetUserGeoID = (void *)GetProcAddress(library, "SetUserGeoID");
	pextSetUserGeoID = (void *)GetProcAddress(library_kernel32, "SetUserGeoID");
	pSetWaitableTimer = (void *)GetProcAddress(library, "SetWaitableTimer");
	pSetWaitableTimerEx = (void *)GetProcAddress(library, "SetWaitableTimerEx");
	pSetupComm = (void *)GetProcAddress(library, "SetupComm");
	pextSetupComm = (void *)GetProcAddress(library_kernel32, "SetupComm");
	pSignalObjectAndWait = (void *)GetProcAddress(library, "SignalObjectAndWait");
	pSizeofResource = (void *)GetProcAddress(library, "SizeofResource");
	pSleep = (void *)GetProcAddress(library, "Sleep");
	pSleepConditionVariableCS = (void *)GetProcAddress(library, "SleepConditionVariableCS");
	pSleepConditionVariableSRW = (void *)GetProcAddress(library, "SleepConditionVariableSRW");
	pSleepEx = (void *)GetProcAddress(library, "SleepEx");
	pStrCSpnA = (void *)GetProcAddress(library, "StrCSpnA");
	pStrCSpnIA = (void *)GetProcAddress(library, "StrCSpnIA");
	pStrCSpnIW = (void *)GetProcAddress(library, "StrCSpnIW");
	pStrCSpnW = (void *)GetProcAddress(library, "StrCSpnW");
	pStrCatBuffA = (void *)GetProcAddress(library, "StrCatBuffA");
	pStrCatBuffW = (void *)GetProcAddress(library, "StrCatBuffW");
	pStrCatChainW = (void *)GetProcAddress(library, "StrCatChainW");
	pStrChrA = (void *)GetProcAddress(library, "StrChrA");
	pStrChrIA = (void *)GetProcAddress(library, "StrChrIA");
	pStrChrIW = (void *)GetProcAddress(library, "StrChrIW");
	pStrChrNW = (void *)GetProcAddress(library, "StrChrNW");
	pStrChrW = (void *)GetProcAddress(library, "StrChrW");
	pStrCmpCA = (void *)GetProcAddress(library, "StrCmpCA");
	pStrCmpCW = (void *)GetProcAddress(library, "StrCmpCW");
	pStrCmpICA = (void *)GetProcAddress(library, "StrCmpICA");
	pStrCmpICW = (void *)GetProcAddress(library, "StrCmpICW");
	pStrCmpIW = (void *)GetProcAddress(library, "StrCmpIW");
	pStrCmpLogicalW = (void *)GetProcAddress(library, "StrCmpLogicalW");
	pStrCmpNA = (void *)GetProcAddress(library, "StrCmpNA");
	pStrCmpNCA = (void *)GetProcAddress(library, "StrCmpNCA");
	pStrCmpNCW = (void *)GetProcAddress(library, "StrCmpNCW");
	pStrCmpNIA = (void *)GetProcAddress(library, "StrCmpNIA");
	pStrCmpNICA = (void *)GetProcAddress(library, "StrCmpNICA");
	pStrCmpNICW = (void *)GetProcAddress(library, "StrCmpNICW");
	pStrCmpNIW = (void *)GetProcAddress(library, "StrCmpNIW");
	pStrCmpNW = (void *)GetProcAddress(library, "StrCmpNW");
	pStrCmpW = (void *)GetProcAddress(library, "StrCmpW");
	pStrCpyNW = (void *)GetProcAddress(library, "StrCpyNW");
	pStrCpyNXA = (void *)GetProcAddress(library, "StrCpyNXA");
	pStrCpyNXW = (void *)GetProcAddress(library, "StrCpyNXW");
	pStrDupA = (void *)GetProcAddress(library, "StrDupA");
	pStrDupW = (void *)GetProcAddress(library, "StrDupW");
	pStrIsIntlEqualA = (void *)GetProcAddress(library, "StrIsIntlEqualA");
	pStrIsIntlEqualW = (void *)GetProcAddress(library, "StrIsIntlEqualW");
	pStrPBrkA = (void *)GetProcAddress(library, "StrPBrkA");
	pStrPBrkW = (void *)GetProcAddress(library, "StrPBrkW");
	pStrRChrA = (void *)GetProcAddress(library, "StrRChrA");
	pStrRChrIA = (void *)GetProcAddress(library, "StrRChrIA");
	pStrRChrIW = (void *)GetProcAddress(library, "StrRChrIW");
	pStrRChrW = (void *)GetProcAddress(library, "StrRChrW");
	pStrRStrIA = (void *)GetProcAddress(library, "StrRStrIA");
	pStrRStrIW = (void *)GetProcAddress(library, "StrRStrIW");
	pStrSpnA = (void *)GetProcAddress(library, "StrSpnA");
	pStrSpnW = (void *)GetProcAddress(library, "StrSpnW");
	pStrStrA = (void *)GetProcAddress(library, "StrStrA");
	pStrStrIA = (void *)GetProcAddress(library, "StrStrIA");
	pStrStrIW = (void *)GetProcAddress(library, "StrStrIW");
	pStrStrNIW = (void *)GetProcAddress(library, "StrStrNIW");
	pStrStrNW = (void *)GetProcAddress(library, "StrStrNW");
	pStrStrW = (void *)GetProcAddress(library, "StrStrW");
	pStrToInt64ExA = (void *)GetProcAddress(library, "StrToInt64ExA");
	pStrToInt64ExW = (void *)GetProcAddress(library, "StrToInt64ExW");
	pStrToIntA = (void *)GetProcAddress(library, "StrToIntA");
	pStrToIntExA = (void *)GetProcAddress(library, "StrToIntExA");
	pStrToIntExW = (void *)GetProcAddress(library, "StrToIntExW");
	pStrToIntW = (void *)GetProcAddress(library, "StrToIntW");
	pStrTrimA = (void *)GetProcAddress(library, "StrTrimA");
	pStrTrimW = (void *)GetProcAddress(library, "StrTrimW");
	pSubmitThreadpoolWork = (void *)GetProcAddress(library, "SubmitThreadpoolWork");
	pextSubmitThreadpoolWork = (void *)GetProcAddress(library_ntdll, "TpPostWork");
	pSuspendThread = (void *)GetProcAddress(library, "SuspendThread");
	pSwitchToFiber = (void *)GetProcAddress(library, "SwitchToFiber");
	pSwitchToThread = (void *)GetProcAddress(library, "SwitchToThread");
	pSystemTimeToFileTime = (void *)GetProcAddress(library, "SystemTimeToFileTime");
	pextSystemTimeToFileTime = (void *)GetProcAddress(library_kernel32, "SystemTimeToFileTime");
	pSystemTimeToTzSpecificLocalTime = (void *)GetProcAddress(library, "SystemTimeToTzSpecificLocalTime");
	pextSystemTimeToTzSpecificLocalTime = (void *)GetProcAddress(library_kernel32, "SystemTimeToTzSpecificLocalTime");
	pTerminateProcess = (void *)GetProcAddress(library, "TerminateProcess");
	pTerminateThread = (void *)GetProcAddress(library, "TerminateThread");
	pTlsAlloc = (void *)GetProcAddress(library, "TlsAlloc");
	pTlsFree = (void *)GetProcAddress(library, "TlsFree");
	pTlsGetValue = (void *)GetProcAddress(library, "TlsGetValue");
	pTlsSetValue = (void *)GetProcAddress(library, "TlsSetValue");
	pTraceEvent = (void *)GetProcAddress(library, "TraceEvent");
	pextTraceEvent = (void *)GetProcAddress(library_ntdll, "EtwLogTraceEvent");
	pTraceMessage = (void *)GetProcAddress(library, "TraceMessage");
	pextTraceMessage = (void *)GetProcAddress(library_ntdll, "EtwTraceMessage");
	pTraceMessageVa = (void *)GetProcAddress(library, "TraceMessageVa");
	pextTraceMessageVa = (void *)GetProcAddress(library_ntdll, "EtwTraceMessageVa");
	pTransactNamedPipe = (void *)GetProcAddress(library, "TransactNamedPipe");
	pTransmitCommChar = (void *)GetProcAddress(library, "TransmitCommChar");
	pextTransmitCommChar = (void *)GetProcAddress(library_kernel32, "TransmitCommChar");
	pTryAcquireSRWLockExclusive = (void *)GetProcAddress(library, "TryAcquireSRWLockExclusive");
	pextTryAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockExclusive");
	pTryAcquireSRWLockShared = (void *)GetProcAddress(library, "TryAcquireSRWLockShared");
	pextTryAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockShared");
	pTryEnterCriticalSection = (void *)GetProcAddress(library, "TryEnterCriticalSection");
	pextTryEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlTryEnterCriticalSection");
	pTrySubmitThreadpoolCallback = (void *)GetProcAddress(library, "TrySubmitThreadpoolCallback");
	pTzSpecificLocalTimeToSystemTime = (void *)GetProcAddress(library, "TzSpecificLocalTimeToSystemTime");
	pextTzSpecificLocalTimeToSystemTime = (void *)GetProcAddress(library_kernel32, "TzSpecificLocalTimeToSystemTime");
	pUnhandledExceptionFilter = (void *)GetProcAddress(library, "UnhandledExceptionFilter");
	pextUnhandledExceptionFilter = (void *)GetProcAddress(library_kernel32, "UnhandledExceptionFilter");
	pUnlockFile = (void *)GetProcAddress(library, "UnlockFile");
	pUnlockFileEx = (void *)GetProcAddress(library, "UnlockFileEx");
	pUnmapViewOfFile = (void *)GetProcAddress(library, "UnmapViewOfFile");
	pextUnmapViewOfFile = (void *)GetProcAddress(library_kernel32, "UnmapViewOfFile");
	pUnregisterTraceGuids = (void *)GetProcAddress(library, "UnregisterTraceGuids");
	pextUnregisterTraceGuids = (void *)GetProcAddress(library_ntdll, "EtwUnregisterTraceGuids");
	pUnregisterWaitEx = (void *)GetProcAddress(library, "UnregisterWaitEx");
	pUpdateProcThreadAttribute = (void *)GetProcAddress(library, "UpdateProcThreadAttribute");
	pUrlApplySchemeA = (void *)GetProcAddress(library, "UrlApplySchemeA");
	pUrlApplySchemeW = (void *)GetProcAddress(library, "UrlApplySchemeW");
	pUrlCanonicalizeA = (void *)GetProcAddress(library, "UrlCanonicalizeA");
	pUrlCanonicalizeW = (void *)GetProcAddress(library, "UrlCanonicalizeW");
	pUrlCombineA = (void *)GetProcAddress(library, "UrlCombineA");
	pUrlCombineW = (void *)GetProcAddress(library, "UrlCombineW");
	pUrlCompareA = (void *)GetProcAddress(library, "UrlCompareA");
	pUrlCompareW = (void *)GetProcAddress(library, "UrlCompareW");
	pUrlCreateFromPathA = (void *)GetProcAddress(library, "UrlCreateFromPathA");
	pUrlCreateFromPathW = (void *)GetProcAddress(library, "UrlCreateFromPathW");
	pUrlEscapeA = (void *)GetProcAddress(library, "UrlEscapeA");
	pUrlEscapeW = (void *)GetProcAddress(library, "UrlEscapeW");
	pUrlFixupW = (void *)GetProcAddress(library, "UrlFixupW");
	pUrlGetLocationA = (void *)GetProcAddress(library, "UrlGetLocationA");
	pUrlGetLocationW = (void *)GetProcAddress(library, "UrlGetLocationW");
	pUrlGetPartA = (void *)GetProcAddress(library, "UrlGetPartA");
	pUrlGetPartW = (void *)GetProcAddress(library, "UrlGetPartW");
	pUrlHashA = (void *)GetProcAddress(library, "UrlHashA");
	pUrlHashW = (void *)GetProcAddress(library, "UrlHashW");
	pUrlIsA = (void *)GetProcAddress(library, "UrlIsA");
	pUrlIsNoHistoryA = (void *)GetProcAddress(library, "UrlIsNoHistoryA");
	pUrlIsNoHistoryW = (void *)GetProcAddress(library, "UrlIsNoHistoryW");
	pUrlIsOpaqueA = (void *)GetProcAddress(library, "UrlIsOpaqueA");
	pUrlIsOpaqueW = (void *)GetProcAddress(library, "UrlIsOpaqueW");
	pUrlIsW = (void *)GetProcAddress(library, "UrlIsW");
	pUrlUnescapeA = (void *)GetProcAddress(library, "UrlUnescapeA");
	pUrlUnescapeW = (void *)GetProcAddress(library, "UrlUnescapeW");
	pVerFindFileA = (void *)GetProcAddress(library, "VerFindFileA");
	pVerFindFileW = (void *)GetProcAddress(library, "VerFindFileW");
	pVerLanguageNameA = (void *)GetProcAddress(library, "VerLanguageNameA");
	pextVerLanguageNameA = (void *)GetProcAddress(library_kernel32, "VerLanguageNameA");
	pVerLanguageNameW = (void *)GetProcAddress(library, "VerLanguageNameW");
	pextVerLanguageNameW = (void *)GetProcAddress(library_kernel32, "VerLanguageNameW");
	pVerQueryValueA = (void *)GetProcAddress(library, "VerQueryValueA");
	pVerQueryValueW = (void *)GetProcAddress(library, "VerQueryValueW");
	pVerSetConditionMask = (void *)GetProcAddress(library, "VerSetConditionMask");
	pextVerSetConditionMask = (void *)GetProcAddress(library_ntdll, "VerSetConditionMask");
	pVirtualAlloc = (void *)GetProcAddress(library, "VirtualAlloc");
	pextVirtualAlloc = (void *)GetProcAddress(library_kernel32, "VirtualAlloc");
	pVirtualAllocEx = (void *)GetProcAddress(library, "VirtualAllocEx");
	pextVirtualAllocEx = (void *)GetProcAddress(library_kernel32, "VirtualAllocEx");
	pVirtualAllocExNuma = (void *)GetProcAddress(library, "VirtualAllocExNuma");
	pextVirtualAllocExNuma = (void *)GetProcAddress(library_kernel32, "VirtualAllocExNuma");
	pVirtualFree = (void *)GetProcAddress(library, "VirtualFree");
	pextVirtualFree = (void *)GetProcAddress(library_kernel32, "VirtualFree");
	pVirtualFreeEx = (void *)GetProcAddress(library, "VirtualFreeEx");
	pextVirtualFreeEx = (void *)GetProcAddress(library_kernel32, "VirtualFreeEx");
	pVirtualLock = (void *)GetProcAddress(library, "VirtualLock");
	pextVirtualLock = (void *)GetProcAddress(library_kernel32, "VirtualLock");
	pVirtualProtect = (void *)GetProcAddress(library, "VirtualProtect");
	pextVirtualProtect = (void *)GetProcAddress(library_kernel32, "VirtualProtect");
	pVirtualProtectEx = (void *)GetProcAddress(library, "VirtualProtectEx");
	pextVirtualProtectEx = (void *)GetProcAddress(library_kernel32, "VirtualProtectEx");
	pVirtualQuery = (void *)GetProcAddress(library, "VirtualQuery");
	pextVirtualQuery = (void *)GetProcAddress(library_kernel32, "VirtualQuery");
	pVirtualQueryEx = (void *)GetProcAddress(library, "VirtualQueryEx");
	pextVirtualQueryEx = (void *)GetProcAddress(library_kernel32, "VirtualQueryEx");
	pVirtualUnlock = (void *)GetProcAddress(library, "VirtualUnlock");
	pextVirtualUnlock = (void *)GetProcAddress(library_kernel32, "VirtualUnlock");
	pWaitCommEvent = (void *)GetProcAddress(library, "WaitCommEvent");
	pextWaitCommEvent = (void *)GetProcAddress(library_kernel32, "WaitCommEvent");
	pWaitForDebugEvent = (void *)GetProcAddress(library, "WaitForDebugEvent");
	pextWaitForDebugEvent = (void *)GetProcAddress(library_kernel32, "WaitForDebugEvent");
	pWaitForMultipleObjects = (void *)GetProcAddress(library, "WaitForMultipleObjects");
	pWaitForMultipleObjectsEx = (void *)GetProcAddress(library, "WaitForMultipleObjectsEx");
	pWaitForSingleObject = (void *)GetProcAddress(library, "WaitForSingleObject");
	pWaitForSingleObjectEx = (void *)GetProcAddress(library, "WaitForSingleObjectEx");
	pWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolTimerCallbacks");
	pextWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForTimer");
	pWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWaitCallbacks");
	pextWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWait");
	pWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWorkCallbacks");
	pextWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWork");
	pWaitNamedPipeW = (void *)GetProcAddress(library, "WaitNamedPipeW");
	pWaitOnAddress = (void *)GetProcAddress(library, "WaitOnAddress");
	pWakeAllConditionVariable = (void *)GetProcAddress(library, "WakeAllConditionVariable");
	pextWakeAllConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeAllConditionVariable");
	pWakeByAddressAll = (void *)GetProcAddress(library, "WakeByAddressAll");
	pextWakeByAddressAll = (void *)GetProcAddress(library_ntdll, "RtlWakeAddressAll");
	pWakeByAddressSingle = (void *)GetProcAddress(library, "WakeByAddressSingle");
	pextWakeByAddressSingle = (void *)GetProcAddress(library_ntdll, "RtlWakeAddressSingle");
	pWakeConditionVariable = (void *)GetProcAddress(library, "WakeConditionVariable");
	pextWakeConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeConditionVariable");
	pWerRegisterFile = (void *)GetProcAddress(library, "WerRegisterFile");
	pextWerRegisterFile = (void *)GetProcAddress(library_kernel32, "WerRegisterFile");
	pWerRegisterMemoryBlock = (void *)GetProcAddress(library, "WerRegisterMemoryBlock");
	pextWerRegisterMemoryBlock = (void *)GetProcAddress(library_kernel32, "WerRegisterMemoryBlock");
	pWerRegisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerRegisterRuntimeExceptionModule");
	pextWerRegisterRuntimeExceptionModule = (void *)GetProcAddress(library_kernel32, "WerRegisterRuntimeExceptionModule");
	pWerSetFlags = (void *)GetProcAddress(library, "WerSetFlags");
	pextWerSetFlags = (void *)GetProcAddress(library_kernel32, "WerSetFlags");
	pWerUnregisterMemoryBlock = (void *)GetProcAddress(library, "WerUnregisterMemoryBlock");
	pextWerUnregisterMemoryBlock = (void *)GetProcAddress(library_kernel32, "WerUnregisterMemoryBlock");
	pWerUnregisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerUnregisterRuntimeExceptionModule");
	pextWerUnregisterRuntimeExceptionModule = (void *)GetProcAddress(library_kernel32, "WerUnregisterRuntimeExceptionModule");
	pWideCharToMultiByte = (void *)GetProcAddress(library, "WideCharToMultiByte");
	pextWideCharToMultiByte = (void *)GetProcAddress(library_kernel32, "WideCharToMultiByte");
	pWow64DisableWow64FsRedirection = (void *)GetProcAddress(library, "Wow64DisableWow64FsRedirection");
	pWow64RevertWow64FsRedirection = (void *)GetProcAddress(library, "Wow64RevertWow64FsRedirection");
	pWriteConsoleA = (void *)GetProcAddress(library, "WriteConsoleA");
	pextWriteConsoleA = (void *)GetProcAddress(library_kernel32, "WriteConsoleA");
	pWriteConsoleInputA = (void *)GetProcAddress(library, "WriteConsoleInputA");
	pextWriteConsoleInputA = (void *)GetProcAddress(library_kernel32, "WriteConsoleInputA");
	pWriteConsoleInputW = (void *)GetProcAddress(library, "WriteConsoleInputW");
	pextWriteConsoleInputW = (void *)GetProcAddress(library_kernel32, "WriteConsoleInputW");
	pWriteConsoleOutputA = (void *)GetProcAddress(library, "WriteConsoleOutputA");
	pextWriteConsoleOutputA = (void *)GetProcAddress(library_kernel32, "WriteConsoleOutputA");
	pWriteConsoleOutputAttribute = (void *)GetProcAddress(library, "WriteConsoleOutputAttribute");
	pextWriteConsoleOutputAttribute = (void *)GetProcAddress(library_kernel32, "WriteConsoleOutputAttribute");
	pWriteConsoleOutputCharacterA = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterA");
	pextWriteConsoleOutputCharacterA = (void *)GetProcAddress(library_kernel32, "WriteConsoleOutputCharacterA");
	pWriteConsoleOutputCharacterW = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterW");
	pextWriteConsoleOutputCharacterW = (void *)GetProcAddress(library_kernel32, "WriteConsoleOutputCharacterW");
	pWriteConsoleOutputW = (void *)GetProcAddress(library, "WriteConsoleOutputW");
	pextWriteConsoleOutputW = (void *)GetProcAddress(library_kernel32, "WriteConsoleOutputW");
	pWriteConsoleW = (void *)GetProcAddress(library, "WriteConsoleW");
	pextWriteConsoleW = (void *)GetProcAddress(library_kernel32, "WriteConsoleW");
	pWriteFile = (void *)GetProcAddress(library, "WriteFile");
	pWriteFileEx = (void *)GetProcAddress(library, "WriteFileEx");
	pWriteFileGather = (void *)GetProcAddress(library, "WriteFileGather");
	pWriteProcessMemory = (void *)GetProcAddress(library, "WriteProcessMemory");
	pextWriteProcessMemory = (void *)GetProcAddress(library_kernel32, "WriteProcessMemory");
	pZombifyActCtx = (void *)GetProcAddress(library, "ZombifyActCtx");
	p__C_specific_handler = (void *)GetProcAddress(library, "__C_specific_handler");
	pext__C_specific_handler = (void *)GetProcAddress(library_kernel32, "__C_specific_handler");
	p__chkstk = (void *)GetProcAddress(library, "__chkstk");
	pext__chkstk = (void *)GetProcAddress(library_kernel32, "__chkstk");
	p_local_unwind = (void *)GetProcAddress(library, "_local_unwind");
	pext_local_unwind = (void *)GetProcAddress(library_kernel32, "_local_unwind");
	plstrcmpA = (void *)GetProcAddress(library, "lstrcmpA");
	plstrcmpW = (void *)GetProcAddress(library, "lstrcmpW");
	plstrcmpiA = (void *)GetProcAddress(library, "lstrcmpiA");
	plstrcmpiW = (void *)GetProcAddress(library, "lstrcmpiW");
	plstrcpynA = (void *)GetProcAddress(library, "lstrcpynA");
	plstrcpynW = (void *)GetProcAddress(library, "lstrcpynW");
	plstrlenA = (void *)GetProcAddress(library, "lstrlenA");
	plstrlenW = (void *)GetProcAddress(library, "lstrlenW");
	initialized = TRUE;
}

void* wine_thunk_get_for_kernelbase(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pAccessCheck)
		return wine32a_kernelbase_AccessCheck;
	if (func == pAccessCheckAndAuditAlarmW)
		return wine32a_kernelbase_AccessCheckAndAuditAlarmW;
	if (func == pAccessCheckByType)
		return wine32a_kernelbase_AccessCheckByType;
	if (func == pAcquireSRWLockExclusive && func != pextAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextAcquireSRWLockExclusive);
	if (func == pAcquireSRWLockShared && func != pextAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextAcquireSRWLockShared);
	if (func == pActivateActCtx)
		return wine32a_kernelbase_ActivateActCtx;
	if (func == pAddAccessAllowedAce)
		return wine32a_kernelbase_AddAccessAllowedAce;
	if (func == pAddAccessAllowedAceEx)
		return wine32a_kernelbase_AddAccessAllowedAceEx;
	if (func == pAddAccessAllowedObjectAce)
		return wine32a_kernelbase_AddAccessAllowedObjectAce;
	if (func == pAddAccessDeniedAce)
		return wine32a_kernelbase_AddAccessDeniedAce;
	if (func == pAddAccessDeniedAceEx)
		return wine32a_kernelbase_AddAccessDeniedAceEx;
	if (func == pAddAccessDeniedObjectAce)
		return wine32a_kernelbase_AddAccessDeniedObjectAce;
	if (func == pAddAce)
		return wine32a_kernelbase_AddAce;
	if (func == pAddAuditAccessAce)
		return wine32a_kernelbase_AddAuditAccessAce;
	if (func == pAddAuditAccessAceEx)
		return wine32a_kernelbase_AddAuditAccessAceEx;
	if (func == pAddAuditAccessObjectAce)
		return wine32a_kernelbase_AddAuditAccessObjectAce;
	if (func == pAddDllDirectory && func != pextAddDllDirectory)
		return wine_thunk_get_for_any(pextAddDllDirectory);
	if (func == pAddMandatoryAce)
		return wine32a_kernelbase_AddMandatoryAce;
	if (func == pAddRefActCtx)
		return wine32a_kernelbase_AddRefActCtx;
	if (func == pAddVectoredContinueHandler && func != pextAddVectoredContinueHandler)
		return wine_thunk_get_for_any(pextAddVectoredContinueHandler);
	if (func == pAddVectoredExceptionHandler && func != pextAddVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextAddVectoredExceptionHandler);
	if (func == pAdjustTokenGroups)
		return wine32a_kernelbase_AdjustTokenGroups;
	if (func == pAdjustTokenPrivileges)
		return wine32a_kernelbase_AdjustTokenPrivileges;
	if (func == pAllocConsole && func != pextAllocConsole)
		return wine_thunk_get_for_any(pextAllocConsole);
	if (func == pAllocateAndInitializeSid)
		return wine32a_kernelbase_AllocateAndInitializeSid;
	if (func == pAllocateLocallyUniqueId)
		return wine32a_kernelbase_AllocateLocallyUniqueId;
	if (func == pAllocateUserPhysicalPages && func != pextAllocateUserPhysicalPages)
		return wine_thunk_get_for_any(pextAllocateUserPhysicalPages);
	if (func == pAppPolicyGetProcessTerminationMethod)
		return wine32a_kernelbase_AppPolicyGetProcessTerminationMethod;
	if (func == pAppPolicyGetShowDeveloperDiagnostic)
		return wine32a_kernelbase_AppPolicyGetShowDeveloperDiagnostic;
	if (func == pAppPolicyGetThreadInitializationType)
		return wine32a_kernelbase_AppPolicyGetThreadInitializationType;
	if (func == pAppPolicyGetWindowingModel)
		return wine32a_kernelbase_AppPolicyGetWindowingModel;
	if (func == pAreAllAccessesGranted)
		return wine32a_kernelbase_AreAllAccessesGranted;
	if (func == pAreAnyAccessesGranted)
		return wine32a_kernelbase_AreAnyAccessesGranted;
	if (func == pAreFileApisANSI)
		return wine32a_kernelbase_AreFileApisANSI;
	if (func == pAttachConsole && func != pextAttachConsole)
		return wine_thunk_get_for_any(pextAttachConsole);
	if (func == pBaseFlushAppcompatCache && func != pextBaseFlushAppcompatCache)
		return wine_thunk_get_for_any(pextBaseFlushAppcompatCache);
	if (func == pBaseGetNamedObjectDirectory)
		return wine32a_kernelbase_BaseGetNamedObjectDirectory;
	if (func == pBeep && func != pextBeep)
		return wine_thunk_get_for_any(pextBeep);
	if (func == pCallNamedPipeW)
		return wine32a_kernelbase_CallNamedPipeW;
	if (func == pCallbackMayRunLong)
		return wine32a_kernelbase_CallbackMayRunLong;
	if (func == pCancelIo)
		return wine32a_kernelbase_CancelIo;
	if (func == pCancelIoEx)
		return wine32a_kernelbase_CancelIoEx;
	if (func == pCancelSynchronousIo)
		return wine32a_kernelbase_CancelSynchronousIo;
	if (func == pCancelWaitableTimer)
		return wine32a_kernelbase_CancelWaitableTimer;
	if (func == pChangeTimerQueueTimer)
		return wine32a_kernelbase_ChangeTimerQueueTimer;
	if (func == pCharLowerA)
		return wine32a_kernelbase_CharLowerA;
	if (func == pCharLowerBuffA)
		return wine32a_kernelbase_CharLowerBuffA;
	if (func == pCharLowerBuffW)
		return wine32a_kernelbase_CharLowerBuffW;
	if (func == pCharLowerW)
		return wine32a_kernelbase_CharLowerW;
	if (func == pCharNextA)
		return wine32a_kernelbase_CharNextA;
	if (func == pCharNextExA)
		return wine32a_kernelbase_CharNextExA;
	if (func == pCharNextW)
		return wine32a_kernelbase_CharNextW;
	if (func == pCharPrevA)
		return wine32a_kernelbase_CharPrevA;
	if (func == pCharPrevExA)
		return wine32a_kernelbase_CharPrevExA;
	if (func == pCharPrevW)
		return wine32a_kernelbase_CharPrevW;
	if (func == pCharUpperA)
		return wine32a_kernelbase_CharUpperA;
	if (func == pCharUpperBuffA)
		return wine32a_kernelbase_CharUpperBuffA;
	if (func == pCharUpperBuffW)
		return wine32a_kernelbase_CharUpperBuffW;
	if (func == pCharUpperW)
		return wine32a_kernelbase_CharUpperW;
	if (func == pCheckRemoteDebuggerPresent && func != pextCheckRemoteDebuggerPresent)
		return wine_thunk_get_for_any(pextCheckRemoteDebuggerPresent);
	if (func == pCheckTokenMembership)
		return wine32a_kernelbase_CheckTokenMembership;
	if (func == pChrCmpIA)
		return wine32a_kernelbase_ChrCmpIA;
	if (func == pChrCmpIW)
		return wine32a_kernelbase_ChrCmpIW;
	if (func == pClearCommBreak && func != pextClearCommBreak)
		return wine_thunk_get_for_any(pextClearCommBreak);
	if (func == pClearCommError && func != pextClearCommError)
		return wine_thunk_get_for_any(pextClearCommError);
	if (func == pCloseHandle && func != pextCloseHandle)
		return wine_thunk_get_for_any(pextCloseHandle);
	if (func == pCloseThreadpool && func != pextCloseThreadpool)
		return wine_thunk_get_for_any(pextCloseThreadpool);
	if (func == pCloseThreadpoolCleanupGroup && func != pextCloseThreadpoolCleanupGroup)
		return wine_thunk_get_for_any(pextCloseThreadpoolCleanupGroup);
	if (func == pCloseThreadpoolCleanupGroupMembers && func != pextCloseThreadpoolCleanupGroupMembers)
		return wine_thunk_get_for_any(pextCloseThreadpoolCleanupGroupMembers);
	if (func == pCloseThreadpoolTimer && func != pextCloseThreadpoolTimer)
		return wine_thunk_get_for_any(pextCloseThreadpoolTimer);
	if (func == pCloseThreadpoolWait && func != pextCloseThreadpoolWait)
		return wine_thunk_get_for_any(pextCloseThreadpoolWait);
	if (func == pCloseThreadpoolWork && func != pextCloseThreadpoolWork)
		return wine_thunk_get_for_any(pextCloseThreadpoolWork);
	if (func == pCompareFileTime && func != pextCompareFileTime)
		return wine_thunk_get_for_any(pextCompareFileTime);
	if (func == pCompareStringA && func != pextCompareStringA)
		return wine_thunk_get_for_any(pextCompareStringA);
	if (func == pCompareStringEx && func != pextCompareStringEx)
		return wine_thunk_get_for_any(pextCompareStringEx);
	if (func == pCompareStringOrdinal && func != pextCompareStringOrdinal)
		return wine_thunk_get_for_any(pextCompareStringOrdinal);
	if (func == pCompareStringW && func != pextCompareStringW)
		return wine_thunk_get_for_any(pextCompareStringW);
	if (func == pConnectNamedPipe)
		return wine32a_kernelbase_ConnectNamedPipe;
	if (func == pContinueDebugEvent && func != pextContinueDebugEvent)
		return wine_thunk_get_for_any(pextContinueDebugEvent);
	if (func == pConvertDefaultLocale && func != pextConvertDefaultLocale)
		return wine_thunk_get_for_any(pextConvertDefaultLocale);
	if (func == pConvertFiberToThread)
		return wine32a_kernelbase_ConvertFiberToThread;
	if (func == pConvertThreadToFiber)
		return wine32a_kernelbase_ConvertThreadToFiber;
	if (func == pConvertThreadToFiberEx)
		return wine32a_kernelbase_ConvertThreadToFiberEx;
	if (func == pConvertToAutoInheritPrivateObjectSecurity)
		return wine32a_kernelbase_ConvertToAutoInheritPrivateObjectSecurity;
	if (func == pCopyFileExW && func != pextCopyFileExW)
		return wine_thunk_get_for_any(pextCopyFileExW);
	if (func == pCopyFileW && func != pextCopyFileW)
		return wine_thunk_get_for_any(pextCopyFileW);
	if (func == pCopySid)
		return wine32a_kernelbase_CopySid;
	if (func == pCreateActCtxW)
		return wine32a_kernelbase_CreateActCtxW;
	if (func == pCreateConsoleScreenBuffer && func != pextCreateConsoleScreenBuffer)
		return wine_thunk_get_for_any(pextCreateConsoleScreenBuffer);
	if (func == pCreateDirectoryA)
		return wine32a_kernelbase_CreateDirectoryA;
	if (func == pCreateDirectoryExW)
		return wine32a_kernelbase_CreateDirectoryExW;
	if (func == pCreateDirectoryW)
		return wine32a_kernelbase_CreateDirectoryW;
	if (func == pCreateEventA)
		return wine32a_kernelbase_CreateEventA;
	if (func == pCreateEventExA)
		return wine32a_kernelbase_CreateEventExA;
	if (func == pCreateEventExW)
		return wine32a_kernelbase_CreateEventExW;
	if (func == pCreateEventW)
		return wine32a_kernelbase_CreateEventW;
	if (func == pCreateFiber)
		return wine32a_kernelbase_CreateFiber;
	if (func == pCreateFiberEx)
		return wine32a_kernelbase_CreateFiberEx;
	if (func == pCreateFile2)
		return wine32a_kernelbase_CreateFile2;
	if (func == pCreateFileA)
		return wine32a_kernelbase_CreateFileA;
	if (func == pCreateFileMappingW)
		return wine32a_kernelbase_CreateFileMappingW;
	if (func == pCreateFileW)
		return wine32a_kernelbase_CreateFileW;
	if (func == pCreateHardLinkA && func != pextCreateHardLinkA)
		return wine_thunk_get_for_any(pextCreateHardLinkA);
	if (func == pCreateHardLinkW && func != pextCreateHardLinkW)
		return wine_thunk_get_for_any(pextCreateHardLinkW);
	if (func == pCreateIoCompletionPort)
		return wine32a_kernelbase_CreateIoCompletionPort;
	if (func == pCreateMemoryResourceNotification && func != pextCreateMemoryResourceNotification)
		return wine_thunk_get_for_any(pextCreateMemoryResourceNotification);
	if (func == pCreateMutexA)
		return wine32a_kernelbase_CreateMutexA;
	if (func == pCreateMutexExA)
		return wine32a_kernelbase_CreateMutexExA;
	if (func == pCreateMutexExW)
		return wine32a_kernelbase_CreateMutexExW;
	if (func == pCreateMutexW)
		return wine32a_kernelbase_CreateMutexW;
	if (func == pCreateNamedPipeW)
		return wine32a_kernelbase_CreateNamedPipeW;
	if (func == pCreatePipe && func != pextCreatePipe)
		return wine_thunk_get_for_any(pextCreatePipe);
	if (func == pCreatePrivateObjectSecurity)
		return wine32a_kernelbase_CreatePrivateObjectSecurity;
	if (func == pCreatePrivateObjectSecurityEx)
		return wine32a_kernelbase_CreatePrivateObjectSecurityEx;
	if (func == pCreatePrivateObjectSecurityWithMultipleInheritance)
		return wine32a_kernelbase_CreatePrivateObjectSecurityWithMultipleInheritance;
	if (func == pCreateProcessA && func != pextCreateProcessA)
		return wine_thunk_get_for_any(pextCreateProcessA);
	if (func == pCreateProcessAsUserA && func != pextCreateProcessAsUserA)
		return wine_thunk_get_for_any(pextCreateProcessAsUserA);
	if (func == pCreateProcessAsUserW && func != pextCreateProcessAsUserW)
		return wine_thunk_get_for_any(pextCreateProcessAsUserW);
	if (func == pCreateProcessInternalA && func != pextCreateProcessInternalA)
		return wine_thunk_get_for_any(pextCreateProcessInternalA);
	if (func == pCreateProcessInternalW && func != pextCreateProcessInternalW)
		return wine_thunk_get_for_any(pextCreateProcessInternalW);
	if (func == pCreateProcessW && func != pextCreateProcessW)
		return wine_thunk_get_for_any(pextCreateProcessW);
	if (func == pCreateRemoteThread)
		return wine32a_kernelbase_CreateRemoteThread;
	if (func == pCreateRemoteThreadEx)
		return wine32a_kernelbase_CreateRemoteThreadEx;
	if (func == pCreateRestrictedToken)
		return wine32a_kernelbase_CreateRestrictedToken;
	if (func == pCreateSemaphoreExW)
		return wine32a_kernelbase_CreateSemaphoreExW;
	if (func == pCreateSemaphoreW)
		return wine32a_kernelbase_CreateSemaphoreW;
	if (func == pCreateSymbolicLinkW && func != pextCreateSymbolicLinkW)
		return wine_thunk_get_for_any(pextCreateSymbolicLinkW);
	if (func == pCreateThread)
		return wine32a_kernelbase_CreateThread;
	if (func == pCreateThreadpool)
		return wine32a_kernelbase_CreateThreadpool;
	if (func == pCreateThreadpoolCleanupGroup)
		return wine32a_kernelbase_CreateThreadpoolCleanupGroup;
	if (func == pCreateThreadpoolIo)
		return wine32a_kernelbase_CreateThreadpoolIo;
	if (func == pCreateThreadpoolTimer)
		return wine32a_kernelbase_CreateThreadpoolTimer;
	if (func == pCreateThreadpoolWait)
		return wine32a_kernelbase_CreateThreadpoolWait;
	if (func == pCreateThreadpoolWork)
		return wine32a_kernelbase_CreateThreadpoolWork;
	if (func == pCreateTimerQueue)
		return wine32a_kernelbase_CreateTimerQueue;
	if (func == pCreateTimerQueueTimer)
		return wine32a_kernelbase_CreateTimerQueueTimer;
	if (func == pCreateWaitableTimerExW)
		return wine32a_kernelbase_CreateWaitableTimerExW;
	if (func == pCreateWaitableTimerW)
		return wine32a_kernelbase_CreateWaitableTimerW;
	if (func == pCreateWellKnownSid)
		return wine32a_kernelbase_CreateWellKnownSid;
	if (func == pDeactivateActCtx)
		return wine32a_kernelbase_DeactivateActCtx;
	if (func == pDebugActiveProcess && func != pextDebugActiveProcess)
		return wine_thunk_get_for_any(pextDebugActiveProcess);
	if (func == pDebugActiveProcessStop && func != pextDebugActiveProcessStop)
		return wine_thunk_get_for_any(pextDebugActiveProcessStop);
	if (func == pDebugBreak && func != pextDebugBreak)
		return wine_thunk_get_for_any(pextDebugBreak);
	if (func == pDecodePointer && func != pextDecodePointer)
		return wine_thunk_get_for_any(pextDecodePointer);
	if (func == pDecodeSystemPointer && func != pextDecodeSystemPointer)
		return wine_thunk_get_for_any(pextDecodeSystemPointer);
	if (func == pDefineDosDeviceW && func != pextDefineDosDeviceW)
		return wine_thunk_get_for_any(pextDefineDosDeviceW);
	if (func == pDelayLoadFailureHook && func != pextDelayLoadFailureHook)
		return wine_thunk_get_for_any(pextDelayLoadFailureHook);
	if (func == pDeleteAce)
		return wine32a_kernelbase_DeleteAce;
	if (func == pDeleteCriticalSection && func != pextDeleteCriticalSection)
		return wine_thunk_get_for_any(pextDeleteCriticalSection);
	if (func == pDeleteFiber)
		return wine32a_kernelbase_DeleteFiber;
	if (func == pDeleteFileA)
		return wine32a_kernelbase_DeleteFileA;
	if (func == pDeleteFileW)
		return wine32a_kernelbase_DeleteFileW;
	if (func == pDeleteProcThreadAttributeList)
		return wine32a_kernelbase_DeleteProcThreadAttributeList;
	if (func == pDeleteTimerQueueEx)
		return wine32a_kernelbase_DeleteTimerQueueEx;
	if (func == pDeleteTimerQueueTimer)
		return wine32a_kernelbase_DeleteTimerQueueTimer;
	if (func == pDeleteVolumeMountPointW && func != pextDeleteVolumeMountPointW)
		return wine_thunk_get_for_any(pextDeleteVolumeMountPointW);
	if (func == pDestroyPrivateObjectSecurity)
		return wine32a_kernelbase_DestroyPrivateObjectSecurity;
	if (func == pDeviceIoControl && func != pextDeviceIoControl)
		return wine_thunk_get_for_any(pextDeviceIoControl);
	if (func == pDisablePredefinedHandleTableInternal)
		return wine32a_kernelbase_DisablePredefinedHandleTableInternal;
	if (func == pDisableThreadLibraryCalls)
		return wine32a_kernelbase_DisableThreadLibraryCalls;
	if (func == pDisassociateCurrentThreadFromCallback && func != pextDisassociateCurrentThreadFromCallback)
		return wine_thunk_get_for_any(pextDisassociateCurrentThreadFromCallback);
	if (func == pDisconnectNamedPipe)
		return wine32a_kernelbase_DisconnectNamedPipe;
	if (func == pDuplicateHandle && func != pextDuplicateHandle)
		return wine_thunk_get_for_any(pextDuplicateHandle);
	if (func == pDuplicateToken)
		return wine32a_kernelbase_DuplicateToken;
	if (func == pDuplicateTokenEx)
		return wine32a_kernelbase_DuplicateTokenEx;
	if (func == pEncodePointer && func != pextEncodePointer)
		return wine_thunk_get_for_any(pextEncodePointer);
	if (func == pEncodeSystemPointer && func != pextEncodeSystemPointer)
		return wine_thunk_get_for_any(pextEncodeSystemPointer);
	if (func == pEnterCriticalSection && func != pextEnterCriticalSection)
		return wine_thunk_get_for_any(pextEnterCriticalSection);
	if (func == pEnumCalendarInfoExEx && func != pextEnumCalendarInfoExEx)
		return wine_thunk_get_for_any(pextEnumCalendarInfoExEx);
	if (func == pEnumCalendarInfoExW && func != pextEnumCalendarInfoExW)
		return wine_thunk_get_for_any(pextEnumCalendarInfoExW);
	if (func == pEnumCalendarInfoW && func != pextEnumCalendarInfoW)
		return wine_thunk_get_for_any(pextEnumCalendarInfoW);
	if (func == pEnumDateFormatsExEx && func != pextEnumDateFormatsExEx)
		return wine_thunk_get_for_any(pextEnumDateFormatsExEx);
	if (func == pEnumDateFormatsExW && func != pextEnumDateFormatsExW)
		return wine_thunk_get_for_any(pextEnumDateFormatsExW);
	if (func == pEnumDateFormatsW && func != pextEnumDateFormatsW)
		return wine_thunk_get_for_any(pextEnumDateFormatsW);
	if (func == pEnumDynamicTimeZoneInformation)
		return wine32a_kernelbase_EnumDynamicTimeZoneInformation;
	if (func == pEnumLanguageGroupLocalesW && func != pextEnumLanguageGroupLocalesW)
		return wine_thunk_get_for_any(pextEnumLanguageGroupLocalesW);
	if (func == pEnumResourceLanguagesExA)
		return wine32a_kernelbase_EnumResourceLanguagesExA;
	if (func == pEnumResourceLanguagesExW)
		return wine32a_kernelbase_EnumResourceLanguagesExW;
	if (func == pEnumResourceNamesExA)
		return wine32a_kernelbase_EnumResourceNamesExA;
	if (func == pEnumResourceNamesExW)
		return wine32a_kernelbase_EnumResourceNamesExW;
	if (func == pEnumResourceNamesW)
		return wine32a_kernelbase_EnumResourceNamesW;
	if (func == pEnumResourceTypesExA)
		return wine32a_kernelbase_EnumResourceTypesExA;
	if (func == pEnumResourceTypesExW)
		return wine32a_kernelbase_EnumResourceTypesExW;
	if (func == pEnumSystemCodePagesW && func != pextEnumSystemCodePagesW)
		return wine_thunk_get_for_any(pextEnumSystemCodePagesW);
	if (func == pEnumSystemFirmwareTables && func != pextEnumSystemFirmwareTables)
		return wine_thunk_get_for_any(pextEnumSystemFirmwareTables);
	if (func == pEnumSystemGeoID && func != pextEnumSystemGeoID)
		return wine_thunk_get_for_any(pextEnumSystemGeoID);
	if (func == pEnumSystemLanguageGroupsW && func != pextEnumSystemLanguageGroupsW)
		return wine_thunk_get_for_any(pextEnumSystemLanguageGroupsW);
	if (func == pEnumSystemLocalesA && func != pextEnumSystemLocalesA)
		return wine_thunk_get_for_any(pextEnumSystemLocalesA);
	if (func == pEnumSystemLocalesEx && func != pextEnumSystemLocalesEx)
		return wine_thunk_get_for_any(pextEnumSystemLocalesEx);
	if (func == pEnumSystemLocalesW && func != pextEnumSystemLocalesW)
		return wine_thunk_get_for_any(pextEnumSystemLocalesW);
	if (func == pEnumTimeFormatsEx && func != pextEnumTimeFormatsEx)
		return wine_thunk_get_for_any(pextEnumTimeFormatsEx);
	if (func == pEnumTimeFormatsW && func != pextEnumTimeFormatsW)
		return wine_thunk_get_for_any(pextEnumTimeFormatsW);
	if (func == pEnumUILanguagesW && func != pextEnumUILanguagesW)
		return wine_thunk_get_for_any(pextEnumUILanguagesW);
	if (func == pEqualPrefixSid)
		return wine32a_kernelbase_EqualPrefixSid;
	if (func == pEqualSid)
		return wine32a_kernelbase_EqualSid;
	if (func == pEscapeCommFunction && func != pextEscapeCommFunction)
		return wine_thunk_get_for_any(pextEscapeCommFunction);
	if (func == pEventActivityIdControl && func != pextEventActivityIdControl)
		return wine_thunk_get_for_any(pextEventActivityIdControl);
	if (func == pEventEnabled && func != pextEventEnabled)
		return wine_thunk_get_for_any(pextEventEnabled);
	if (func == pEventProviderEnabled && func != pextEventProviderEnabled)
		return wine_thunk_get_for_any(pextEventProviderEnabled);
	if (func == pEventRegister && func != pextEventRegister)
		return wine_thunk_get_for_any(pextEventRegister);
	if (func == pEventSetInformation && func != pextEventSetInformation)
		return wine_thunk_get_for_any(pextEventSetInformation);
	if (func == pEventUnregister && func != pextEventUnregister)
		return wine_thunk_get_for_any(pextEventUnregister);
	if (func == pEventWrite && func != pextEventWrite)
		return wine_thunk_get_for_any(pextEventWrite);
	if (func == pEventWriteString && func != pextEventWriteString)
		return wine_thunk_get_for_any(pextEventWriteString);
	if (func == pEventWriteTransfer && func != pextEventWriteTransfer)
		return wine_thunk_get_for_any(pextEventWriteTransfer);
	if (func == pExitProcess && func != pextExitProcess)
		return wine_thunk_get_for_any(pextExitProcess);
	if (func == pExitThread && func != pextExitThread)
		return wine_thunk_get_for_any(pextExitThread);
	if (func == pExpandEnvironmentStringsA && func != pextExpandEnvironmentStringsA)
		return wine_thunk_get_for_any(pextExpandEnvironmentStringsA);
	if (func == pExpandEnvironmentStringsW && func != pextExpandEnvironmentStringsW)
		return wine_thunk_get_for_any(pextExpandEnvironmentStringsW);
	if (func == pFatalAppExitA && func != pextFatalAppExitA)
		return wine_thunk_get_for_any(pextFatalAppExitA);
	if (func == pFatalAppExitW && func != pextFatalAppExitW)
		return wine_thunk_get_for_any(pextFatalAppExitW);
	if (func == pFileTimeToLocalFileTime && func != pextFileTimeToLocalFileTime)
		return wine_thunk_get_for_any(pextFileTimeToLocalFileTime);
	if (func == pFileTimeToSystemTime && func != pextFileTimeToSystemTime)
		return wine_thunk_get_for_any(pextFileTimeToSystemTime);
	if (func == pFillConsoleOutputAttribute && func != pextFillConsoleOutputAttribute)
		return wine_thunk_get_for_any(pextFillConsoleOutputAttribute);
	if (func == pFillConsoleOutputCharacterA && func != pextFillConsoleOutputCharacterA)
		return wine_thunk_get_for_any(pextFillConsoleOutputCharacterA);
	if (func == pFillConsoleOutputCharacterW && func != pextFillConsoleOutputCharacterW)
		return wine_thunk_get_for_any(pextFillConsoleOutputCharacterW);
	if (func == pFindActCtxSectionGuid)
		return wine32a_kernelbase_FindActCtxSectionGuid;
	if (func == pFindActCtxSectionStringW)
		return wine32a_kernelbase_FindActCtxSectionStringW;
	if (func == pFindClose && func != pextFindClose)
		return wine_thunk_get_for_any(pextFindClose);
	if (func == pFindCloseChangeNotification && func != pextFindCloseChangeNotification)
		return wine_thunk_get_for_any(pextFindCloseChangeNotification);
	if (func == pFindFirstChangeNotificationA && func != pextFindFirstChangeNotificationA)
		return wine_thunk_get_for_any(pextFindFirstChangeNotificationA);
	if (func == pFindFirstChangeNotificationW && func != pextFindFirstChangeNotificationW)
		return wine_thunk_get_for_any(pextFindFirstChangeNotificationW);
	if (func == pFindFirstFileA && func != pextFindFirstFileA)
		return wine_thunk_get_for_any(pextFindFirstFileA);
	if (func == pFindFirstFileExA && func != pextFindFirstFileExA)
		return wine_thunk_get_for_any(pextFindFirstFileExA);
	if (func == pFindFirstFileExW && func != pextFindFirstFileExW)
		return wine_thunk_get_for_any(pextFindFirstFileExW);
	if (func == pFindFirstFileW && func != pextFindFirstFileW)
		return wine_thunk_get_for_any(pextFindFirstFileW);
	if (func == pFindFirstFreeAce)
		return wine32a_kernelbase_FindFirstFreeAce;
	if (func == pFindFirstStreamW && func != pextFindFirstStreamW)
		return wine_thunk_get_for_any(pextFindFirstStreamW);
	if (func == pFindFirstVolumeW && func != pextFindFirstVolumeW)
		return wine_thunk_get_for_any(pextFindFirstVolumeW);
	if (func == pFindNLSStringEx && func != pextFindNLSStringEx)
		return wine_thunk_get_for_any(pextFindNLSStringEx);
	if (func == pFindNextChangeNotification && func != pextFindNextChangeNotification)
		return wine_thunk_get_for_any(pextFindNextChangeNotification);
	if (func == pFindNextFileA && func != pextFindNextFileA)
		return wine_thunk_get_for_any(pextFindNextFileA);
	if (func == pFindNextFileW && func != pextFindNextFileW)
		return wine_thunk_get_for_any(pextFindNextFileW);
	if (func == pFindNextStreamW && func != pextFindNextStreamW)
		return wine_thunk_get_for_any(pextFindNextStreamW);
	if (func == pFindNextVolumeW && func != pextFindNextVolumeW)
		return wine_thunk_get_for_any(pextFindNextVolumeW);
	if (func == pFindResourceExW)
		return wine32a_kernelbase_FindResourceExW;
	if (func == pFindResourceW)
		return wine32a_kernelbase_FindResourceW;
	if (func == pFindStringOrdinal && func != pextFindStringOrdinal)
		return wine_thunk_get_for_any(pextFindStringOrdinal);
	if (func == pFindVolumeClose && func != pextFindVolumeClose)
		return wine_thunk_get_for_any(pextFindVolumeClose);
	if (func == pFlsAlloc)
		return wine32a_kernelbase_FlsAlloc;
	if (func == pFlsFree)
		return wine32a_kernelbase_FlsFree;
	if (func == pFlsGetValue)
		return wine32a_kernelbase_FlsGetValue;
	if (func == pFlsSetValue)
		return wine32a_kernelbase_FlsSetValue;
	if (func == pFlushConsoleInputBuffer && func != pextFlushConsoleInputBuffer)
		return wine_thunk_get_for_any(pextFlushConsoleInputBuffer);
	if (func == pFlushFileBuffers)
		return wine32a_kernelbase_FlushFileBuffers;
	if (func == pFlushInstructionCache)
		return wine32a_kernelbase_FlushInstructionCache;
	if (func == pFlushProcessWriteBuffers && func != pextFlushProcessWriteBuffers)
		return wine_thunk_get_for_any(pextFlushProcessWriteBuffers);
	if (func == pFlushViewOfFile && func != pextFlushViewOfFile)
		return wine_thunk_get_for_any(pextFlushViewOfFile);
	if (func == pFoldStringW && func != pextFoldStringW)
		return wine_thunk_get_for_any(pextFoldStringW);
	if (func == pFormatMessageA && func != pextFormatMessageA)
		return wine_thunk_get_for_any(pextFormatMessageA);
	if (func == pFormatMessageW && func != pextFormatMessageW)
		return wine_thunk_get_for_any(pextFormatMessageW);
	if (func == pFreeConsole && func != pextFreeConsole)
		return wine_thunk_get_for_any(pextFreeConsole);
	if (func == pFreeEnvironmentStringsA && func != pextFreeEnvironmentStringsA)
		return wine_thunk_get_for_any(pextFreeEnvironmentStringsA);
	if (func == pFreeEnvironmentStringsW && func != pextFreeEnvironmentStringsW)
		return wine_thunk_get_for_any(pextFreeEnvironmentStringsW);
	if (func == pFreeLibrary && func != pextFreeLibrary)
		return wine_thunk_get_for_any(pextFreeLibrary);
	if (func == pFreeLibraryAndExitThread)
		return wine32a_kernelbase_FreeLibraryAndExitThread;
	if (func == pFreeLibraryWhenCallbackReturns && func != pextFreeLibraryWhenCallbackReturns)
		return wine_thunk_get_for_any(pextFreeLibraryWhenCallbackReturns);
	if (func == pFreeResource)
		return wine32a_kernelbase_FreeResource;
	if (func == pFreeSid)
		return wine32a_kernelbase_FreeSid;
	if (func == pFreeUserPhysicalPages && func != pextFreeUserPhysicalPages)
		return wine_thunk_get_for_any(pextFreeUserPhysicalPages);
	if (func == pGenerateConsoleCtrlEvent && func != pextGenerateConsoleCtrlEvent)
		return wine_thunk_get_for_any(pextGenerateConsoleCtrlEvent);
	if (func == pGetACP && func != pextGetACP)
		return wine_thunk_get_for_any(pextGetACP);
	if (func == pGetAcceptLanguagesA)
		return wine32a_kernelbase_GetAcceptLanguagesA;
	if (func == pGetAcceptLanguagesW)
		return wine32a_kernelbase_GetAcceptLanguagesW;
	if (func == pGetAce)
		return wine32a_kernelbase_GetAce;
	if (func == pGetAclInformation)
		return wine32a_kernelbase_GetAclInformation;
	if (func == pGetApplicationRestartSettings && func != pextGetApplicationRestartSettings)
		return wine_thunk_get_for_any(pextGetApplicationRestartSettings);
	if (func == pGetCPInfo && func != pextGetCPInfo)
		return wine_thunk_get_for_any(pextGetCPInfo);
	if (func == pGetCPInfoExW && func != pextGetCPInfoExW)
		return wine_thunk_get_for_any(pextGetCPInfoExW);
	if (func == pGetCalendarInfoEx && func != pextGetCalendarInfoEx)
		return wine_thunk_get_for_any(pextGetCalendarInfoEx);
	if (func == pGetCalendarInfoW && func != pextGetCalendarInfoW)
		return wine_thunk_get_for_any(pextGetCalendarInfoW);
	if (func == pGetCommConfig && func != pextGetCommConfig)
		return wine_thunk_get_for_any(pextGetCommConfig);
	if (func == pGetCommMask && func != pextGetCommMask)
		return wine_thunk_get_for_any(pextGetCommMask);
	if (func == pGetCommModemStatus && func != pextGetCommModemStatus)
		return wine_thunk_get_for_any(pextGetCommModemStatus);
	if (func == pGetCommProperties && func != pextGetCommProperties)
		return wine_thunk_get_for_any(pextGetCommProperties);
	if (func == pGetCommState && func != pextGetCommState)
		return wine_thunk_get_for_any(pextGetCommState);
	if (func == pGetCommTimeouts && func != pextGetCommTimeouts)
		return wine_thunk_get_for_any(pextGetCommTimeouts);
	if (func == pGetCommandLineA && func != pextGetCommandLineA)
		return wine_thunk_get_for_any(pextGetCommandLineA);
	if (func == pGetCommandLineW && func != pextGetCommandLineW)
		return wine_thunk_get_for_any(pextGetCommandLineW);
	if (func == pGetCompressedFileSizeA)
		return wine32a_kernelbase_GetCompressedFileSizeA;
	if (func == pGetCompressedFileSizeW)
		return wine32a_kernelbase_GetCompressedFileSizeW;
	if (func == pGetComputerNameExA && func != pextGetComputerNameExA)
		return wine_thunk_get_for_any(pextGetComputerNameExA);
	if (func == pGetComputerNameExW && func != pextGetComputerNameExW)
		return wine_thunk_get_for_any(pextGetComputerNameExW);
	if (func == pGetConsoleCP && func != pextGetConsoleCP)
		return wine_thunk_get_for_any(pextGetConsoleCP);
	if (func == pGetConsoleCursorInfo && func != pextGetConsoleCursorInfo)
		return wine_thunk_get_for_any(pextGetConsoleCursorInfo);
	if (func == pGetConsoleInputExeNameA && func != pextGetConsoleInputExeNameA)
		return wine_thunk_get_for_any(pextGetConsoleInputExeNameA);
	if (func == pGetConsoleInputExeNameW && func != pextGetConsoleInputExeNameW)
		return wine_thunk_get_for_any(pextGetConsoleInputExeNameW);
	if (func == pGetConsoleMode && func != pextGetConsoleMode)
		return wine_thunk_get_for_any(pextGetConsoleMode);
	if (func == pGetConsoleOutputCP && func != pextGetConsoleOutputCP)
		return wine_thunk_get_for_any(pextGetConsoleOutputCP);
	if (func == pGetConsoleScreenBufferInfo && func != pextGetConsoleScreenBufferInfo)
		return wine_thunk_get_for_any(pextGetConsoleScreenBufferInfo);
	if (func == pGetConsoleScreenBufferInfoEx && func != pextGetConsoleScreenBufferInfoEx)
		return wine_thunk_get_for_any(pextGetConsoleScreenBufferInfoEx);
	if (func == pGetConsoleTitleW && func != pextGetConsoleTitleW)
		return wine_thunk_get_for_any(pextGetConsoleTitleW);
	if (func == pGetCurrencyFormatEx && func != pextGetCurrencyFormatEx)
		return wine_thunk_get_for_any(pextGetCurrencyFormatEx);
	if (func == pGetCurrencyFormatW && func != pextGetCurrencyFormatW)
		return wine_thunk_get_for_any(pextGetCurrencyFormatW);
	if (func == pGetCurrentActCtx)
		return wine32a_kernelbase_GetCurrentActCtx;
	if (func == pGetCurrentDirectoryA && func != pextGetCurrentDirectoryA)
		return wine_thunk_get_for_any(pextGetCurrentDirectoryA);
	if (func == pGetCurrentDirectoryW && func != pextGetCurrentDirectoryW)
		return wine_thunk_get_for_any(pextGetCurrentDirectoryW);
	if (func == pGetCurrentPackageFamilyName && func != pextGetCurrentPackageFamilyName)
		return wine_thunk_get_for_any(pextGetCurrentPackageFamilyName);
	if (func == pGetCurrentPackageFullName && func != pextGetCurrentPackageFullName)
		return wine_thunk_get_for_any(pextGetCurrentPackageFullName);
	if (func == pGetCurrentPackageId && func != pextGetCurrentPackageId)
		return wine_thunk_get_for_any(pextGetCurrentPackageId);
	if (func == pGetCurrentProcess)
		return wine32a_kernelbase_GetCurrentProcess;
	if (func == pGetCurrentProcessId)
		return wine32a_kernelbase_GetCurrentProcessId;
	if (func == pGetCurrentProcessorNumber && func != pextGetCurrentProcessorNumber)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumber);
	if (func == pGetCurrentProcessorNumberEx && func != pextGetCurrentProcessorNumberEx)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumberEx);
	if (func == pGetCurrentThread)
		return wine32a_kernelbase_GetCurrentThread;
	if (func == pGetCurrentThreadId)
		return wine32a_kernelbase_GetCurrentThreadId;
	if (func == pGetCurrentThreadStackLimits)
		return wine32a_kernelbase_GetCurrentThreadStackLimits;
	if (func == pGetDateFormatA && func != pextGetDateFormatA)
		return wine_thunk_get_for_any(pextGetDateFormatA);
	if (func == pGetDateFormatEx && func != pextGetDateFormatEx)
		return wine_thunk_get_for_any(pextGetDateFormatEx);
	if (func == pGetDateFormatW && func != pextGetDateFormatW)
		return wine_thunk_get_for_any(pextGetDateFormatW);
	if (func == pGetDiskFreeSpaceA && func != pextGetDiskFreeSpaceA)
		return wine_thunk_get_for_any(pextGetDiskFreeSpaceA);
	if (func == pGetDiskFreeSpaceExA && func != pextGetDiskFreeSpaceExA)
		return wine_thunk_get_for_any(pextGetDiskFreeSpaceExA);
	if (func == pGetDiskFreeSpaceExW && func != pextGetDiskFreeSpaceExW)
		return wine_thunk_get_for_any(pextGetDiskFreeSpaceExW);
	if (func == pGetDiskFreeSpaceW && func != pextGetDiskFreeSpaceW)
		return wine_thunk_get_for_any(pextGetDiskFreeSpaceW);
	if (func == pGetDriveTypeA && func != pextGetDriveTypeA)
		return wine_thunk_get_for_any(pextGetDriveTypeA);
	if (func == pGetDriveTypeW && func != pextGetDriveTypeW)
		return wine_thunk_get_for_any(pextGetDriveTypeW);
	if (func == pGetDynamicTimeZoneInformation && func != pextGetDynamicTimeZoneInformation)
		return wine_thunk_get_for_any(pextGetDynamicTimeZoneInformation);
	if (func == pGetDynamicTimeZoneInformationEffectiveYears && func != pextGetDynamicTimeZoneInformationEffectiveYears)
		return wine_thunk_get_for_any(pextGetDynamicTimeZoneInformationEffectiveYears);
	if (func == pGetEnabledXStateFeatures && func != pextGetEnabledXStateFeatures)
		return wine_thunk_get_for_any(pextGetEnabledXStateFeatures);
	if (func == pGetEnvironmentStrings && func != pextGetEnvironmentStrings)
		return wine_thunk_get_for_any(pextGetEnvironmentStrings);
	if (func == pGetEnvironmentStringsA && func != pextGetEnvironmentStringsA)
		return wine_thunk_get_for_any(pextGetEnvironmentStringsA);
	if (func == pGetEnvironmentStringsW && func != pextGetEnvironmentStringsW)
		return wine_thunk_get_for_any(pextGetEnvironmentStringsW);
	if (func == pGetEnvironmentVariableA && func != pextGetEnvironmentVariableA)
		return wine_thunk_get_for_any(pextGetEnvironmentVariableA);
	if (func == pGetEnvironmentVariableW && func != pextGetEnvironmentVariableW)
		return wine_thunk_get_for_any(pextGetEnvironmentVariableW);
	if (func == pGetErrorMode)
		return wine32a_kernelbase_GetErrorMode;
	if (func == pGetExitCodeProcess)
		return wine32a_kernelbase_GetExitCodeProcess;
	if (func == pGetExitCodeThread)
		return wine32a_kernelbase_GetExitCodeThread;
	if (func == pGetFileAttributesA)
		return wine32a_kernelbase_GetFileAttributesA;
	if (func == pGetFileAttributesExA)
		return wine32a_kernelbase_GetFileAttributesExA;
	if (func == pGetFileAttributesExW)
		return wine32a_kernelbase_GetFileAttributesExW;
	if (func == pGetFileAttributesW)
		return wine32a_kernelbase_GetFileAttributesW;
	if (func == pGetFileInformationByHandle)
		return wine32a_kernelbase_GetFileInformationByHandle;
	if (func == pGetFileInformationByHandleEx)
		return wine32a_kernelbase_GetFileInformationByHandleEx;
	if (func == pGetFileMUIInfo && func != pextGetFileMUIInfo)
		return wine_thunk_get_for_any(pextGetFileMUIInfo);
	if (func == pGetFileMUIPath && func != pextGetFileMUIPath)
		return wine_thunk_get_for_any(pextGetFileMUIPath);
	if (func == pGetFileSecurityW)
		return wine32a_kernelbase_GetFileSecurityW;
	if (func == pGetFileSize)
		return wine32a_kernelbase_GetFileSize;
	if (func == pGetFileSizeEx)
		return wine32a_kernelbase_GetFileSizeEx;
	if (func == pGetFileTime)
		return wine32a_kernelbase_GetFileTime;
	if (func == pGetFileType)
		return wine32a_kernelbase_GetFileType;
	if (func == pGetFileVersionInfoA)
		return wine32a_kernelbase_GetFileVersionInfoA;
	if (func == pGetFileVersionInfoExA)
		return wine32a_kernelbase_GetFileVersionInfoExA;
	if (func == pGetFileVersionInfoExW)
		return wine32a_kernelbase_GetFileVersionInfoExW;
	if (func == pGetFileVersionInfoSizeA)
		return wine32a_kernelbase_GetFileVersionInfoSizeA;
	if (func == pGetFileVersionInfoSizeExA)
		return wine32a_kernelbase_GetFileVersionInfoSizeExA;
	if (func == pGetFileVersionInfoSizeExW)
		return wine32a_kernelbase_GetFileVersionInfoSizeExW;
	if (func == pGetFileVersionInfoSizeW)
		return wine32a_kernelbase_GetFileVersionInfoSizeW;
	if (func == pGetFileVersionInfoW)
		return wine32a_kernelbase_GetFileVersionInfoW;
	if (func == pGetFinalPathNameByHandleA && func != pextGetFinalPathNameByHandleA)
		return wine_thunk_get_for_any(pextGetFinalPathNameByHandleA);
	if (func == pGetFinalPathNameByHandleW && func != pextGetFinalPathNameByHandleW)
		return wine_thunk_get_for_any(pextGetFinalPathNameByHandleW);
	if (func == pGetFullPathNameA && func != pextGetFullPathNameA)
		return wine_thunk_get_for_any(pextGetFullPathNameA);
	if (func == pGetFullPathNameW && func != pextGetFullPathNameW)
		return wine_thunk_get_for_any(pextGetFullPathNameW);
	if (func == pGetGeoInfoW && func != pextGetGeoInfoW)
		return wine_thunk_get_for_any(pextGetGeoInfoW);
	if (func == pGetHandleInformation && func != pextGetHandleInformation)
		return wine_thunk_get_for_any(pextGetHandleInformation);
	if (func == pGetKernelObjectSecurity)
		return wine32a_kernelbase_GetKernelObjectSecurity;
	if (func == pGetLargePageMinimum && func != pextGetLargePageMinimum)
		return wine_thunk_get_for_any(pextGetLargePageMinimum);
	if (func == pGetLargestConsoleWindowSize && func != pextGetLargestConsoleWindowSize)
		return wine_thunk_get_for_any(pextGetLargestConsoleWindowSize);
	if (func == pGetLastError)
		return wine32a_kernelbase_GetLastError;
	if (func == pGetLengthSid)
		return wine32a_kernelbase_GetLengthSid;
	if (func == pGetLocalTime && func != pextGetLocalTime)
		return wine_thunk_get_for_any(pextGetLocalTime);
	if (func == pGetLocaleInfoA && func != pextGetLocaleInfoA)
		return wine_thunk_get_for_any(pextGetLocaleInfoA);
	if (func == pGetLocaleInfoEx && func != pextGetLocaleInfoEx)
		return wine_thunk_get_for_any(pextGetLocaleInfoEx);
	if (func == pGetLocaleInfoW && func != pextGetLocaleInfoW)
		return wine_thunk_get_for_any(pextGetLocaleInfoW);
	if (func == pGetLogicalDriveStringsW && func != pextGetLogicalDriveStringsW)
		return wine_thunk_get_for_any(pextGetLogicalDriveStringsW);
	if (func == pGetLogicalDrives && func != pextGetLogicalDrives)
		return wine_thunk_get_for_any(pextGetLogicalDrives);
	if (func == pGetLogicalProcessorInformation && func != pextGetLogicalProcessorInformation)
		return wine_thunk_get_for_any(pextGetLogicalProcessorInformation);
	if (func == pGetLogicalProcessorInformationEx && func != pextGetLogicalProcessorInformationEx)
		return wine_thunk_get_for_any(pextGetLogicalProcessorInformationEx);
	if (func == pGetLongPathNameA && func != pextGetLongPathNameA)
		return wine_thunk_get_for_any(pextGetLongPathNameA);
	if (func == pGetLongPathNameW && func != pextGetLongPathNameW)
		return wine_thunk_get_for_any(pextGetLongPathNameW);
	if (func == pGetModuleFileNameA)
		return wine32a_kernelbase_GetModuleFileNameA;
	if (func == pGetModuleFileNameW)
		return wine32a_kernelbase_GetModuleFileNameW;
	if (func == pGetModuleHandleA)
		return wine32a_kernelbase_GetModuleHandleA;
	if (func == pGetModuleHandleExA)
		return wine32a_kernelbase_GetModuleHandleExA;
	if (func == pGetModuleHandleExW)
		return wine32a_kernelbase_GetModuleHandleExW;
	if (func == pGetModuleHandleW)
		return wine32a_kernelbase_GetModuleHandleW;
	if (func == pGetNamedPipeHandleStateW && func != pextGetNamedPipeHandleStateW)
		return wine_thunk_get_for_any(pextGetNamedPipeHandleStateW);
	if (func == pGetNamedPipeInfo)
		return wine32a_kernelbase_GetNamedPipeInfo;
	if (func == pGetNativeSystemInfo && func != pextGetNativeSystemInfo)
		return wine_thunk_get_for_any(pextGetNativeSystemInfo);
	if (func == pGetNumaHighestNodeNumber && func != pextGetNumaHighestNodeNumber)
		return wine_thunk_get_for_any(pextGetNumaHighestNodeNumber);
	if (func == pGetNumaNodeProcessorMaskEx && func != pextGetNumaNodeProcessorMaskEx)
		return wine_thunk_get_for_any(pextGetNumaNodeProcessorMaskEx);
	if (func == pGetNumaProximityNode && func != pextGetNumaProximityNode)
		return wine_thunk_get_for_any(pextGetNumaProximityNode);
	if (func == pGetNumaProximityNodeEx && func != pextGetNumaProximityNodeEx)
		return wine_thunk_get_for_any(pextGetNumaProximityNodeEx);
	if (func == pGetNumberFormatEx && func != pextGetNumberFormatEx)
		return wine_thunk_get_for_any(pextGetNumberFormatEx);
	if (func == pGetNumberFormatW && func != pextGetNumberFormatW)
		return wine_thunk_get_for_any(pextGetNumberFormatW);
	if (func == pGetNumberOfConsoleInputEvents && func != pextGetNumberOfConsoleInputEvents)
		return wine_thunk_get_for_any(pextGetNumberOfConsoleInputEvents);
	if (func == pGetOEMCP && func != pextGetOEMCP)
		return wine_thunk_get_for_any(pextGetOEMCP);
	if (func == pGetOverlappedResult)
		return wine32a_kernelbase_GetOverlappedResult;
	if (func == pGetPackageFullName && func != pextGetPackageFullName)
		return wine_thunk_get_for_any(pextGetPackageFullName);
	if (func == pGetPhysicallyInstalledSystemMemory && func != pextGetPhysicallyInstalledSystemMemory)
		return wine_thunk_get_for_any(pextGetPhysicallyInstalledSystemMemory);
	if (func == pGetPriorityClass)
		return wine32a_kernelbase_GetPriorityClass;
	if (func == pGetPrivateObjectSecurity)
		return wine32a_kernelbase_GetPrivateObjectSecurity;
	if (func == pGetProcAddress && func != pextGetProcAddress)
		return wine_thunk_get_for_any(pextGetProcAddress);
	if (func == pGetProcessHandleCount)
		return wine32a_kernelbase_GetProcessHandleCount;
	if (func == pGetProcessHeap)
		return wine32a_kernelbase_GetProcessHeap;
	if (func == pGetProcessId)
		return wine32a_kernelbase_GetProcessId;
	if (func == pGetProcessIdOfThread)
		return wine32a_kernelbase_GetProcessIdOfThread;
	if (func == pGetProcessMitigationPolicy)
		return wine32a_kernelbase_GetProcessMitigationPolicy;
	if (func == pGetProcessPreferredUILanguages && func != pextGetProcessPreferredUILanguages)
		return wine_thunk_get_for_any(pextGetProcessPreferredUILanguages);
	if (func == pGetProcessPriorityBoost)
		return wine32a_kernelbase_GetProcessPriorityBoost;
	if (func == pGetProcessShutdownParameters)
		return wine32a_kernelbase_GetProcessShutdownParameters;
	if (func == pGetProcessTimes && func != pextGetProcessTimes)
		return wine_thunk_get_for_any(pextGetProcessTimes);
	if (func == pGetProcessVersion && func != pextGetProcessVersion)
		return wine_thunk_get_for_any(pextGetProcessVersion);
	if (func == pGetProcessWorkingSetSizeEx)
		return wine32a_kernelbase_GetProcessWorkingSetSizeEx;
	if (func == pGetProductInfo && func != pextGetProductInfo)
		return wine_thunk_get_for_any(pextGetProductInfo);
	if (func == pGetQueuedCompletionStatus)
		return wine32a_kernelbase_GetQueuedCompletionStatus;
	if (func == pGetQueuedCompletionStatusEx)
		return wine32a_kernelbase_GetQueuedCompletionStatusEx;
	if (func == pGetSecurityDescriptorControl)
		return wine32a_kernelbase_GetSecurityDescriptorControl;
	if (func == pGetSecurityDescriptorDacl)
		return wine32a_kernelbase_GetSecurityDescriptorDacl;
	if (func == pGetSecurityDescriptorGroup)
		return wine32a_kernelbase_GetSecurityDescriptorGroup;
	if (func == pGetSecurityDescriptorLength)
		return wine32a_kernelbase_GetSecurityDescriptorLength;
	if (func == pGetSecurityDescriptorOwner)
		return wine32a_kernelbase_GetSecurityDescriptorOwner;
	if (func == pGetSecurityDescriptorSacl)
		return wine32a_kernelbase_GetSecurityDescriptorSacl;
	if (func == pGetShortPathNameW && func != pextGetShortPathNameW)
		return wine_thunk_get_for_any(pextGetShortPathNameW);
	if (func == pGetSidIdentifierAuthority)
		return wine32a_kernelbase_GetSidIdentifierAuthority;
	if (func == pGetSidLengthRequired)
		return wine32a_kernelbase_GetSidLengthRequired;
	if (func == pGetSidSubAuthority)
		return wine32a_kernelbase_GetSidSubAuthority;
	if (func == pGetSidSubAuthorityCount)
		return wine32a_kernelbase_GetSidSubAuthorityCount;
	if (func == pGetStartupInfoW && func != pextGetStartupInfoW)
		return wine_thunk_get_for_any(pextGetStartupInfoW);
	if (func == pGetStdHandle && func != pextGetStdHandle)
		return wine_thunk_get_for_any(pextGetStdHandle);
	if (func == pGetStringTypeA && func != pextGetStringTypeA)
		return wine_thunk_get_for_any(pextGetStringTypeA);
	if (func == pGetStringTypeExW && func != pextGetStringTypeExW)
		return wine_thunk_get_for_any(pextGetStringTypeExW);
	if (func == pGetStringTypeW && func != pextGetStringTypeW)
		return wine_thunk_get_for_any(pextGetStringTypeW);
	if (func == pGetSystemDefaultLCID && func != pextGetSystemDefaultLCID)
		return wine_thunk_get_for_any(pextGetSystemDefaultLCID);
	if (func == pGetSystemDefaultLangID && func != pextGetSystemDefaultLangID)
		return wine_thunk_get_for_any(pextGetSystemDefaultLangID);
	if (func == pGetSystemDefaultLocaleName && func != pextGetSystemDefaultLocaleName)
		return wine_thunk_get_for_any(pextGetSystemDefaultLocaleName);
	if (func == pGetSystemDefaultUILanguage && func != pextGetSystemDefaultUILanguage)
		return wine_thunk_get_for_any(pextGetSystemDefaultUILanguage);
	if (func == pGetSystemDirectoryA)
		return wine32a_kernelbase_GetSystemDirectoryA;
	if (func == pGetSystemDirectoryW)
		return wine32a_kernelbase_GetSystemDirectoryW;
	if (func == pGetSystemFileCacheSize && func != pextGetSystemFileCacheSize)
		return wine_thunk_get_for_any(pextGetSystemFileCacheSize);
	if (func == pGetSystemFirmwareTable && func != pextGetSystemFirmwareTable)
		return wine_thunk_get_for_any(pextGetSystemFirmwareTable);
	if (func == pGetSystemInfo && func != pextGetSystemInfo)
		return wine_thunk_get_for_any(pextGetSystemInfo);
	if (func == pGetSystemPreferredUILanguages && func != pextGetSystemPreferredUILanguages)
		return wine_thunk_get_for_any(pextGetSystemPreferredUILanguages);
	if (func == pGetSystemTime && func != pextGetSystemTime)
		return wine_thunk_get_for_any(pextGetSystemTime);
	if (func == pGetSystemTimeAdjustment && func != pextGetSystemTimeAdjustment)
		return wine_thunk_get_for_any(pextGetSystemTimeAdjustment);
	if (func == pGetSystemTimeAsFileTime && func != pextGetSystemTimeAsFileTime)
		return wine_thunk_get_for_any(pextGetSystemTimeAsFileTime);
	if (func == pGetSystemTimePreciseAsFileTime && func != pextGetSystemTimePreciseAsFileTime)
		return wine_thunk_get_for_any(pextGetSystemTimePreciseAsFileTime);
	if (func == pGetSystemTimes && func != pextGetSystemTimes)
		return wine_thunk_get_for_any(pextGetSystemTimes);
	if (func == pGetSystemWindowsDirectoryA)
		return wine32a_kernelbase_GetSystemWindowsDirectoryA;
	if (func == pGetSystemWindowsDirectoryW)
		return wine32a_kernelbase_GetSystemWindowsDirectoryW;
	if (func == pGetSystemWow64DirectoryA && func != pextGetSystemWow64DirectoryA)
		return wine_thunk_get_for_any(pextGetSystemWow64DirectoryA);
	if (func == pGetSystemWow64DirectoryW && func != pextGetSystemWow64DirectoryW)
		return wine_thunk_get_for_any(pextGetSystemWow64DirectoryW);
	if (func == pGetTempFileNameA && func != pextGetTempFileNameA)
		return wine_thunk_get_for_any(pextGetTempFileNameA);
	if (func == pGetTempFileNameW && func != pextGetTempFileNameW)
		return wine_thunk_get_for_any(pextGetTempFileNameW);
	if (func == pGetTempPathA && func != pextGetTempPathA)
		return wine_thunk_get_for_any(pextGetTempPathA);
	if (func == pGetTempPathW && func != pextGetTempPathW)
		return wine_thunk_get_for_any(pextGetTempPathW);
	if (func == pGetThreadContext)
		return wine32a_kernelbase_GetThreadContext;
	if (func == pGetThreadErrorMode)
		return wine32a_kernelbase_GetThreadErrorMode;
	if (func == pGetThreadGroupAffinity)
		return wine32a_kernelbase_GetThreadGroupAffinity;
	if (func == pGetThreadIOPendingFlag)
		return wine32a_kernelbase_GetThreadIOPendingFlag;
	if (func == pGetThreadId)
		return wine32a_kernelbase_GetThreadId;
	if (func == pGetThreadLocale && func != pextGetThreadLocale)
		return wine_thunk_get_for_any(pextGetThreadLocale);
	if (func == pGetThreadPreferredUILanguages && func != pextGetThreadPreferredUILanguages)
		return wine_thunk_get_for_any(pextGetThreadPreferredUILanguages);
	if (func == pGetThreadPriority)
		return wine32a_kernelbase_GetThreadPriority;
	if (func == pGetThreadPriorityBoost)
		return wine32a_kernelbase_GetThreadPriorityBoost;
	if (func == pGetThreadTimes)
		return wine32a_kernelbase_GetThreadTimes;
	if (func == pGetThreadUILanguage)
		return wine32a_kernelbase_GetThreadUILanguage;
	if (func == pGetTickCount && func != pextGetTickCount)
		return wine_thunk_get_for_any(pextGetTickCount);
	if (func == pGetTickCount64 && func != pextGetTickCount64)
		return wine_thunk_get_for_any(pextGetTickCount64);
	if (func == pGetTimeFormatA && func != pextGetTimeFormatA)
		return wine_thunk_get_for_any(pextGetTimeFormatA);
	if (func == pGetTimeFormatEx && func != pextGetTimeFormatEx)
		return wine_thunk_get_for_any(pextGetTimeFormatEx);
	if (func == pGetTimeFormatW && func != pextGetTimeFormatW)
		return wine_thunk_get_for_any(pextGetTimeFormatW);
	if (func == pGetTimeZoneInformation && func != pextGetTimeZoneInformation)
		return wine_thunk_get_for_any(pextGetTimeZoneInformation);
	if (func == pGetTimeZoneInformationForYear && func != pextGetTimeZoneInformationForYear)
		return wine_thunk_get_for_any(pextGetTimeZoneInformationForYear);
	if (func == pGetTokenInformation)
		return wine32a_kernelbase_GetTokenInformation;
	if (func == pGetTraceEnableFlags && func != pextGetTraceEnableFlags)
		return wine_thunk_get_for_any(pextGetTraceEnableFlags);
	if (func == pGetTraceEnableLevel && func != pextGetTraceEnableLevel)
		return wine_thunk_get_for_any(pextGetTraceEnableLevel);
	if (func == pGetTraceLoggerHandle && func != pextGetTraceLoggerHandle)
		return wine_thunk_get_for_any(pextGetTraceLoggerHandle);
	if (func == pGetUserDefaultLCID && func != pextGetUserDefaultLCID)
		return wine_thunk_get_for_any(pextGetUserDefaultLCID);
	if (func == pGetUserDefaultLangID && func != pextGetUserDefaultLangID)
		return wine_thunk_get_for_any(pextGetUserDefaultLangID);
	if (func == pGetUserDefaultLocaleName && func != pextGetUserDefaultLocaleName)
		return wine_thunk_get_for_any(pextGetUserDefaultLocaleName);
	if (func == pGetUserDefaultUILanguage && func != pextGetUserDefaultUILanguage)
		return wine_thunk_get_for_any(pextGetUserDefaultUILanguage);
	if (func == pGetUserGeoID && func != pextGetUserGeoID)
		return wine_thunk_get_for_any(pextGetUserGeoID);
	if (func == pGetUserPreferredUILanguages && func != pextGetUserPreferredUILanguages)
		return wine_thunk_get_for_any(pextGetUserPreferredUILanguages);
	if (func == pGetVersion && func != pextGetVersion)
		return wine_thunk_get_for_any(pextGetVersion);
	if (func == pGetVersionExA && func != pextGetVersionExA)
		return wine_thunk_get_for_any(pextGetVersionExA);
	if (func == pGetVersionExW && func != pextGetVersionExW)
		return wine_thunk_get_for_any(pextGetVersionExW);
	if (func == pGetVolumeInformationA && func != pextGetVolumeInformationA)
		return wine_thunk_get_for_any(pextGetVolumeInformationA);
	if (func == pGetVolumeInformationByHandleW && func != pextGetVolumeInformationByHandleW)
		return wine_thunk_get_for_any(pextGetVolumeInformationByHandleW);
	if (func == pGetVolumeInformationW && func != pextGetVolumeInformationW)
		return wine_thunk_get_for_any(pextGetVolumeInformationW);
	if (func == pGetVolumeNameForVolumeMountPointW && func != pextGetVolumeNameForVolumeMountPointW)
		return wine_thunk_get_for_any(pextGetVolumeNameForVolumeMountPointW);
	if (func == pGetVolumePathNameW && func != pextGetVolumePathNameW)
		return wine_thunk_get_for_any(pextGetVolumePathNameW);
	if (func == pGetVolumePathNamesForVolumeNameW && func != pextGetVolumePathNamesForVolumeNameW)
		return wine_thunk_get_for_any(pextGetVolumePathNamesForVolumeNameW);
	if (func == pGetWindowsAccountDomainSid)
		return wine32a_kernelbase_GetWindowsAccountDomainSid;
	if (func == pGetWindowsDirectoryA)
		return wine32a_kernelbase_GetWindowsDirectoryA;
	if (func == pGetWindowsDirectoryW)
		return wine32a_kernelbase_GetWindowsDirectoryW;
	if (func == pGetWriteWatch && func != pextGetWriteWatch)
		return wine_thunk_get_for_any(pextGetWriteWatch);
	if (func == pGlobalAlloc && func != pextGlobalAlloc)
		return wine_thunk_get_for_any(pextGlobalAlloc);
	if (func == pGlobalFree && func != pextGlobalFree)
		return wine_thunk_get_for_any(pextGlobalFree);
	if (func == pGlobalMemoryStatusEx && func != pextGlobalMemoryStatusEx)
		return wine_thunk_get_for_any(pextGlobalMemoryStatusEx);
	if (func == pHashData)
		return wine32a_kernelbase_HashData;
	if (func == pHeapAlloc && func != pextHeapAlloc)
		return wine_thunk_get_for_any(pextHeapAlloc);
	if (func == pHeapCompact && func != pextHeapCompact)
		return wine_thunk_get_for_any(pextHeapCompact);
	if (func == pHeapCreate && func != pextHeapCreate)
		return wine_thunk_get_for_any(pextHeapCreate);
	if (func == pHeapDestroy && func != pextHeapDestroy)
		return wine_thunk_get_for_any(pextHeapDestroy);
	if (func == pHeapFree && func != pextHeapFree)
		return wine_thunk_get_for_any(pextHeapFree);
	if (func == pHeapLock && func != pextHeapLock)
		return wine_thunk_get_for_any(pextHeapLock);
	if (func == pHeapQueryInformation && func != pextHeapQueryInformation)
		return wine_thunk_get_for_any(pextHeapQueryInformation);
	if (func == pHeapReAlloc && func != pextHeapReAlloc)
		return wine_thunk_get_for_any(pextHeapReAlloc);
	if (func == pHeapSetInformation && func != pextHeapSetInformation)
		return wine_thunk_get_for_any(pextHeapSetInformation);
	if (func == pHeapSize && func != pextHeapSize)
		return wine_thunk_get_for_any(pextHeapSize);
	if (func == pHeapUnlock && func != pextHeapUnlock)
		return wine_thunk_get_for_any(pextHeapUnlock);
	if (func == pHeapValidate && func != pextHeapValidate)
		return wine_thunk_get_for_any(pextHeapValidate);
	if (func == pHeapWalk && func != pextHeapWalk)
		return wine_thunk_get_for_any(pextHeapWalk);
	if (func == pIdnToAscii && func != pextIdnToAscii)
		return wine_thunk_get_for_any(pextIdnToAscii);
	if (func == pIdnToNameprepUnicode && func != pextIdnToNameprepUnicode)
		return wine_thunk_get_for_any(pextIdnToNameprepUnicode);
	if (func == pIdnToUnicode && func != pextIdnToUnicode)
		return wine_thunk_get_for_any(pextIdnToUnicode);
	if (func == pImpersonateAnonymousToken)
		return wine32a_kernelbase_ImpersonateAnonymousToken;
	if (func == pImpersonateLoggedOnUser)
		return wine32a_kernelbase_ImpersonateLoggedOnUser;
	if (func == pImpersonateNamedPipeClient)
		return wine32a_kernelbase_ImpersonateNamedPipeClient;
	if (func == pImpersonateSelf)
		return wine32a_kernelbase_ImpersonateSelf;
	if (func == pInitOnceBeginInitialize && func != pextInitOnceBeginInitialize)
		return wine_thunk_get_for_any(pextInitOnceBeginInitialize);
	if (func == pInitOnceComplete && func != pextInitOnceComplete)
		return wine_thunk_get_for_any(pextInitOnceComplete);
	if (func == pInitOnceExecuteOnce && func != pextInitOnceExecuteOnce)
		return wine_thunk_get_for_any(pextInitOnceExecuteOnce);
	if (func == pInitOnceInitialize && func != pextInitOnceInitialize)
		return wine_thunk_get_for_any(pextInitOnceInitialize);
	if (func == pInitializeAcl)
		return wine32a_kernelbase_InitializeAcl;
	if (func == pInitializeConditionVariable && func != pextInitializeConditionVariable)
		return wine_thunk_get_for_any(pextInitializeConditionVariable);
	if (func == pInitializeCriticalSection && func != pextInitializeCriticalSection)
		return wine_thunk_get_for_any(pextInitializeCriticalSection);
	if (func == pInitializeCriticalSectionAndSpinCount)
		return wine32a_kernelbase_InitializeCriticalSectionAndSpinCount;
	if (func == pInitializeCriticalSectionEx)
		return wine32a_kernelbase_InitializeCriticalSectionEx;
	if (func == pInitializeProcThreadAttributeList)
		return wine32a_kernelbase_InitializeProcThreadAttributeList;
	if (func == pInitializeSListHead && func != pextInitializeSListHead)
		return wine_thunk_get_for_any(pextInitializeSListHead);
	if (func == pInitializeSRWLock && func != pextInitializeSRWLock)
		return wine_thunk_get_for_any(pextInitializeSRWLock);
	if (func == pInitializeSecurityDescriptor)
		return wine32a_kernelbase_InitializeSecurityDescriptor;
	if (func == pInitializeSid)
		return wine32a_kernelbase_InitializeSid;
	if (func == pInterlockedCompareExchange && func != pextInterlockedCompareExchange)
		return wine_thunk_get_for_any(pextInterlockedCompareExchange);
	if (func == pInterlockedCompareExchange64 && func != pextInterlockedCompareExchange64)
		return wine_thunk_get_for_any(pextInterlockedCompareExchange64);
	if (func == pInterlockedDecrement && func != pextInterlockedDecrement)
		return wine_thunk_get_for_any(pextInterlockedDecrement);
	if (func == pInterlockedExchange && func != pextInterlockedExchange)
		return wine_thunk_get_for_any(pextInterlockedExchange);
	if (func == pInterlockedExchangeAdd && func != pextInterlockedExchangeAdd)
		return wine_thunk_get_for_any(pextInterlockedExchangeAdd);
	if (func == pInterlockedFlushSList && func != pextInterlockedFlushSList)
		return wine_thunk_get_for_any(pextInterlockedFlushSList);
	if (func == pInterlockedIncrement && func != pextInterlockedIncrement)
		return wine_thunk_get_for_any(pextInterlockedIncrement);
	if (func == pInterlockedPopEntrySList && func != pextInterlockedPopEntrySList)
		return wine_thunk_get_for_any(pextInterlockedPopEntrySList);
	if (func == pInterlockedPushEntrySList && func != pextInterlockedPushEntrySList)
		return wine_thunk_get_for_any(pextInterlockedPushEntrySList);
	if (func == pInterlockedPushListSList && func != pextInterlockedPushListSList)
		return wine_thunk_get_for_any(pextInterlockedPushListSList);
	if (func == pInterlockedPushListSListEx && func != pextInterlockedPushListSListEx)
		return wine_thunk_get_for_any(pextInterlockedPushListSListEx);
	if (func == pIsCharAlphaA)
		return wine32a_kernelbase_IsCharAlphaA;
	if (func == pIsCharAlphaNumericA)
		return wine32a_kernelbase_IsCharAlphaNumericA;
	if (func == pIsCharAlphaNumericW)
		return wine32a_kernelbase_IsCharAlphaNumericW;
	if (func == pIsCharAlphaW)
		return wine32a_kernelbase_IsCharAlphaW;
	if (func == pIsCharBlankW)
		return wine32a_kernelbase_IsCharBlankW;
	if (func == pIsCharCntrlW)
		return wine32a_kernelbase_IsCharCntrlW;
	if (func == pIsCharDigitW)
		return wine32a_kernelbase_IsCharDigitW;
	if (func == pIsCharLowerA)
		return wine32a_kernelbase_IsCharLowerA;
	if (func == pIsCharLowerW)
		return wine32a_kernelbase_IsCharLowerW;
	if (func == pIsCharPunctW)
		return wine32a_kernelbase_IsCharPunctW;
	if (func == pIsCharSpaceA)
		return wine32a_kernelbase_IsCharSpaceA;
	if (func == pIsCharSpaceW)
		return wine32a_kernelbase_IsCharSpaceW;
	if (func == pIsCharUpperA)
		return wine32a_kernelbase_IsCharUpperA;
	if (func == pIsCharUpperW)
		return wine32a_kernelbase_IsCharUpperW;
	if (func == pIsCharXDigitW)
		return wine32a_kernelbase_IsCharXDigitW;
	if (func == pIsDBCSLeadByte && func != pextIsDBCSLeadByte)
		return wine_thunk_get_for_any(pextIsDBCSLeadByte);
	if (func == pIsDBCSLeadByteEx && func != pextIsDBCSLeadByteEx)
		return wine_thunk_get_for_any(pextIsDBCSLeadByteEx);
	if (func == pIsDebuggerPresent && func != pextIsDebuggerPresent)
		return wine_thunk_get_for_any(pextIsDebuggerPresent);
	if (func == pIsInternetESCEnabled)
		return wine32a_kernelbase_IsInternetESCEnabled;
	if (func == pIsNormalizedString && func != pextIsNormalizedString)
		return wine_thunk_get_for_any(pextIsNormalizedString);
	if (func == pIsProcessInJob && func != pextIsProcessInJob)
		return wine_thunk_get_for_any(pextIsProcessInJob);
	if (func == pIsProcessorFeaturePresent && func != pextIsProcessorFeaturePresent)
		return wine_thunk_get_for_any(pextIsProcessorFeaturePresent);
	if (func == pIsThreadAFiber)
		return wine32a_kernelbase_IsThreadAFiber;
	if (func == pIsThreadpoolTimerSet && func != pextIsThreadpoolTimerSet)
		return wine_thunk_get_for_any(pextIsThreadpoolTimerSet);
	if (func == pIsTokenRestricted)
		return wine32a_kernelbase_IsTokenRestricted;
	if (func == pIsValidAcl)
		return wine32a_kernelbase_IsValidAcl;
	if (func == pIsValidCodePage && func != pextIsValidCodePage)
		return wine_thunk_get_for_any(pextIsValidCodePage);
	if (func == pIsValidLanguageGroup && func != pextIsValidLanguageGroup)
		return wine_thunk_get_for_any(pextIsValidLanguageGroup);
	if (func == pIsValidLocale && func != pextIsValidLocale)
		return wine_thunk_get_for_any(pextIsValidLocale);
	if (func == pIsValidLocaleName && func != pextIsValidLocaleName)
		return wine_thunk_get_for_any(pextIsValidLocaleName);
	if (func == pIsValidSecurityDescriptor)
		return wine32a_kernelbase_IsValidSecurityDescriptor;
	if (func == pIsValidSid)
		return wine32a_kernelbase_IsValidSid;
	if (func == pIsWellKnownSid)
		return wine32a_kernelbase_IsWellKnownSid;
	if (func == pIsWow64Process)
		return wine32a_kernelbase_IsWow64Process;
	if (func == pK32EmptyWorkingSet && func != pextK32EmptyWorkingSet)
		return wine_thunk_get_for_any(pextK32EmptyWorkingSet);
	if (func == pK32EnumDeviceDrivers && func != pextK32EnumDeviceDrivers)
		return wine_thunk_get_for_any(pextK32EnumDeviceDrivers);
	if (func == pK32EnumPageFilesA && func != pextK32EnumPageFilesA)
		return wine_thunk_get_for_any(pextK32EnumPageFilesA);
	if (func == pK32EnumPageFilesW && func != pextK32EnumPageFilesW)
		return wine_thunk_get_for_any(pextK32EnumPageFilesW);
	if (func == pK32EnumProcessModules && func != pextK32EnumProcessModules)
		return wine_thunk_get_for_any(pextK32EnumProcessModules);
	if (func == pK32EnumProcessModulesEx && func != pextK32EnumProcessModulesEx)
		return wine_thunk_get_for_any(pextK32EnumProcessModulesEx);
	if (func == pK32EnumProcesses && func != pextK32EnumProcesses)
		return wine_thunk_get_for_any(pextK32EnumProcesses);
	if (func == pK32GetDeviceDriverBaseNameA && func != pextK32GetDeviceDriverBaseNameA)
		return wine_thunk_get_for_any(pextK32GetDeviceDriverBaseNameA);
	if (func == pK32GetDeviceDriverBaseNameW && func != pextK32GetDeviceDriverBaseNameW)
		return wine_thunk_get_for_any(pextK32GetDeviceDriverBaseNameW);
	if (func == pK32GetDeviceDriverFileNameA && func != pextK32GetDeviceDriverFileNameA)
		return wine_thunk_get_for_any(pextK32GetDeviceDriverFileNameA);
	if (func == pK32GetDeviceDriverFileNameW && func != pextK32GetDeviceDriverFileNameW)
		return wine_thunk_get_for_any(pextK32GetDeviceDriverFileNameW);
	if (func == pK32GetMappedFileNameA && func != pextK32GetMappedFileNameA)
		return wine_thunk_get_for_any(pextK32GetMappedFileNameA);
	if (func == pK32GetMappedFileNameW && func != pextK32GetMappedFileNameW)
		return wine_thunk_get_for_any(pextK32GetMappedFileNameW);
	if (func == pK32GetModuleBaseNameA && func != pextK32GetModuleBaseNameA)
		return wine_thunk_get_for_any(pextK32GetModuleBaseNameA);
	if (func == pK32GetModuleBaseNameW && func != pextK32GetModuleBaseNameW)
		return wine_thunk_get_for_any(pextK32GetModuleBaseNameW);
	if (func == pK32GetModuleFileNameExA && func != pextK32GetModuleFileNameExA)
		return wine_thunk_get_for_any(pextK32GetModuleFileNameExA);
	if (func == pK32GetModuleFileNameExW && func != pextK32GetModuleFileNameExW)
		return wine_thunk_get_for_any(pextK32GetModuleFileNameExW);
	if (func == pK32GetModuleInformation && func != pextK32GetModuleInformation)
		return wine_thunk_get_for_any(pextK32GetModuleInformation);
	if (func == pK32GetPerformanceInfo && func != pextK32GetPerformanceInfo)
		return wine_thunk_get_for_any(pextK32GetPerformanceInfo);
	if (func == pK32GetProcessImageFileNameA && func != pextK32GetProcessImageFileNameA)
		return wine_thunk_get_for_any(pextK32GetProcessImageFileNameA);
	if (func == pK32GetProcessImageFileNameW && func != pextK32GetProcessImageFileNameW)
		return wine_thunk_get_for_any(pextK32GetProcessImageFileNameW);
	if (func == pK32GetProcessMemoryInfo && func != pextK32GetProcessMemoryInfo)
		return wine_thunk_get_for_any(pextK32GetProcessMemoryInfo);
	if (func == pK32GetWsChanges && func != pextK32GetWsChanges)
		return wine_thunk_get_for_any(pextK32GetWsChanges);
	if (func == pK32GetWsChangesEx && func != pextK32GetWsChangesEx)
		return wine_thunk_get_for_any(pextK32GetWsChangesEx);
	if (func == pK32InitializeProcessForWsWatch && func != pextK32InitializeProcessForWsWatch)
		return wine_thunk_get_for_any(pextK32InitializeProcessForWsWatch);
	if (func == pK32QueryWorkingSet && func != pextK32QueryWorkingSet)
		return wine_thunk_get_for_any(pextK32QueryWorkingSet);
	if (func == pK32QueryWorkingSetEx && func != pextK32QueryWorkingSetEx)
		return wine_thunk_get_for_any(pextK32QueryWorkingSetEx);
	if (func == pLCIDToLocaleName && func != pextLCIDToLocaleName)
		return wine_thunk_get_for_any(pextLCIDToLocaleName);
	if (func == pLCMapStringA && func != pextLCMapStringA)
		return wine_thunk_get_for_any(pextLCMapStringA);
	if (func == pLCMapStringEx && func != pextLCMapStringEx)
		return wine_thunk_get_for_any(pextLCMapStringEx);
	if (func == pLCMapStringW && func != pextLCMapStringW)
		return wine_thunk_get_for_any(pextLCMapStringW);
	if (func == pLeaveCriticalSection && func != pextLeaveCriticalSection)
		return wine_thunk_get_for_any(pextLeaveCriticalSection);
	if (func == pLeaveCriticalSectionWhenCallbackReturns && func != pextLeaveCriticalSectionWhenCallbackReturns)
		return wine_thunk_get_for_any(pextLeaveCriticalSectionWhenCallbackReturns);
	if (func == pLoadLibraryA && func != pextLoadLibraryA)
		return wine_thunk_get_for_any(pextLoadLibraryA);
	if (func == pLoadLibraryExA && func != pextLoadLibraryExA)
		return wine_thunk_get_for_any(pextLoadLibraryExA);
	if (func == pLoadLibraryExW && func != pextLoadLibraryExW)
		return wine_thunk_get_for_any(pextLoadLibraryExW);
	if (func == pLoadLibraryW && func != pextLoadLibraryW)
		return wine_thunk_get_for_any(pextLoadLibraryW);
	if (func == pLoadResource)
		return wine32a_kernelbase_LoadResource;
	if (func == pLoadStringA)
		return wine32a_kernelbase_LoadStringA;
	if (func == pLoadStringW)
		return wine32a_kernelbase_LoadStringW;
	if (func == pLocalAlloc && func != pextLocalAlloc)
		return wine_thunk_get_for_any(pextLocalAlloc);
	if (func == pLocalFileTimeToFileTime && func != pextLocalFileTimeToFileTime)
		return wine_thunk_get_for_any(pextLocalFileTimeToFileTime);
	if (func == pLocalFree && func != pextLocalFree)
		return wine_thunk_get_for_any(pextLocalFree);
	if (func == pLocalLock && func != pextLocalLock)
		return wine_thunk_get_for_any(pextLocalLock);
	if (func == pLocalReAlloc && func != pextLocalReAlloc)
		return wine_thunk_get_for_any(pextLocalReAlloc);
	if (func == pLocalUnlock && func != pextLocalUnlock)
		return wine_thunk_get_for_any(pextLocalUnlock);
	if (func == pLocaleNameToLCID && func != pextLocaleNameToLCID)
		return wine_thunk_get_for_any(pextLocaleNameToLCID);
	if (func == pLockFile)
		return wine32a_kernelbase_LockFile;
	if (func == pLockFileEx)
		return wine32a_kernelbase_LockFileEx;
	if (func == pLockResource)
		return wine32a_kernelbase_LockResource;
	if (func == pMakeAbsoluteSD)
		return wine32a_kernelbase_MakeAbsoluteSD;
	if (func == pMakeSelfRelativeSD)
		return wine32a_kernelbase_MakeSelfRelativeSD;
	if (func == pMapGenericMask)
		return wine32a_kernelbase_MapGenericMask;
	if (func == pMapUserPhysicalPages && func != pextMapUserPhysicalPages)
		return wine_thunk_get_for_any(pextMapUserPhysicalPages);
	if (func == pMapViewOfFile && func != pextMapViewOfFile)
		return wine_thunk_get_for_any(pextMapViewOfFile);
	if (func == pMapViewOfFileEx && func != pextMapViewOfFileEx)
		return wine_thunk_get_for_any(pextMapViewOfFileEx);
	if (func == pMoveFileExW && func != pextMoveFileExW)
		return wine_thunk_get_for_any(pextMoveFileExW);
	if (func == pMoveFileWithProgressW && func != pextMoveFileWithProgressW)
		return wine_thunk_get_for_any(pextMoveFileWithProgressW);
	if (func == pMulDiv && func != pextMulDiv)
		return wine_thunk_get_for_any(pextMulDiv);
	if (func == pMultiByteToWideChar && func != pextMultiByteToWideChar)
		return wine_thunk_get_for_any(pextMultiByteToWideChar);
	if (func == pNeedCurrentDirectoryForExePathA && func != pextNeedCurrentDirectoryForExePathA)
		return wine_thunk_get_for_any(pextNeedCurrentDirectoryForExePathA);
	if (func == pNeedCurrentDirectoryForExePathW && func != pextNeedCurrentDirectoryForExePathW)
		return wine_thunk_get_for_any(pextNeedCurrentDirectoryForExePathW);
	if (func == pNormalizeString && func != pextNormalizeString)
		return wine_thunk_get_for_any(pextNormalizeString);
	if (func == pObjectCloseAuditAlarmW)
		return wine32a_kernelbase_ObjectCloseAuditAlarmW;
	if (func == pObjectDeleteAuditAlarmW)
		return wine32a_kernelbase_ObjectDeleteAuditAlarmW;
	if (func == pObjectOpenAuditAlarmW)
		return wine32a_kernelbase_ObjectOpenAuditAlarmW;
	if (func == pObjectPrivilegeAuditAlarmW)
		return wine32a_kernelbase_ObjectPrivilegeAuditAlarmW;
	if (func == pOpenEventA)
		return wine32a_kernelbase_OpenEventA;
	if (func == pOpenEventW)
		return wine32a_kernelbase_OpenEventW;
	if (func == pOpenFileById)
		return wine32a_kernelbase_OpenFileById;
	if (func == pOpenFileMappingW)
		return wine32a_kernelbase_OpenFileMappingW;
	if (func == pOpenMutexW)
		return wine32a_kernelbase_OpenMutexW;
	if (func == pOpenProcess)
		return wine32a_kernelbase_OpenProcess;
	if (func == pOpenProcessToken)
		return wine32a_kernelbase_OpenProcessToken;
	if (func == pOpenSemaphoreW)
		return wine32a_kernelbase_OpenSemaphoreW;
	if (func == pOpenThread)
		return wine32a_kernelbase_OpenThread;
	if (func == pOpenThreadToken)
		return wine32a_kernelbase_OpenThreadToken;
	if (func == pOpenWaitableTimerW)
		return wine32a_kernelbase_OpenWaitableTimerW;
	if (func == pOutputDebugStringA && func != pextOutputDebugStringA)
		return wine_thunk_get_for_any(pextOutputDebugStringA);
	if (func == pOutputDebugStringW && func != pextOutputDebugStringW)
		return wine_thunk_get_for_any(pextOutputDebugStringW);
	if (func == pParseURLA)
		return wine32a_kernelbase_ParseURLA;
	if (func == pParseURLW)
		return wine32a_kernelbase_ParseURLW;
	if (func == pPathAddBackslashA)
		return wine32a_kernelbase_PathAddBackslashA;
	if (func == pPathAddBackslashW)
		return wine32a_kernelbase_PathAddBackslashW;
	if (func == pPathAddExtensionA)
		return wine32a_kernelbase_PathAddExtensionA;
	if (func == pPathAddExtensionW)
		return wine32a_kernelbase_PathAddExtensionW;
	if (func == pPathAllocCanonicalize)
		return wine32a_kernelbase_PathAllocCanonicalize;
	if (func == pPathAllocCombine)
		return wine32a_kernelbase_PathAllocCombine;
	if (func == pPathAppendA)
		return wine32a_kernelbase_PathAppendA;
	if (func == pPathAppendW)
		return wine32a_kernelbase_PathAppendW;
	if (func == pPathCanonicalizeA)
		return wine32a_kernelbase_PathCanonicalizeA;
	if (func == pPathCanonicalizeW)
		return wine32a_kernelbase_PathCanonicalizeW;
	if (func == pPathCchAddBackslash)
		return wine32a_kernelbase_PathCchAddBackslash;
	if (func == pPathCchAddBackslashEx)
		return wine32a_kernelbase_PathCchAddBackslashEx;
	if (func == pPathCchAddExtension)
		return wine32a_kernelbase_PathCchAddExtension;
	if (func == pPathCchAppend)
		return wine32a_kernelbase_PathCchAppend;
	if (func == pPathCchAppendEx)
		return wine32a_kernelbase_PathCchAppendEx;
	if (func == pPathCchCanonicalize)
		return wine32a_kernelbase_PathCchCanonicalize;
	if (func == pPathCchCanonicalizeEx)
		return wine32a_kernelbase_PathCchCanonicalizeEx;
	if (func == pPathCchCombine)
		return wine32a_kernelbase_PathCchCombine;
	if (func == pPathCchCombineEx)
		return wine32a_kernelbase_PathCchCombineEx;
	if (func == pPathCchFindExtension)
		return wine32a_kernelbase_PathCchFindExtension;
	if (func == pPathCchIsRoot)
		return wine32a_kernelbase_PathCchIsRoot;
	if (func == pPathCchRemoveBackslash)
		return wine32a_kernelbase_PathCchRemoveBackslash;
	if (func == pPathCchRemoveBackslashEx)
		return wine32a_kernelbase_PathCchRemoveBackslashEx;
	if (func == pPathCchRemoveExtension)
		return wine32a_kernelbase_PathCchRemoveExtension;
	if (func == pPathCchRemoveFileSpec)
		return wine32a_kernelbase_PathCchRemoveFileSpec;
	if (func == pPathCchRenameExtension)
		return wine32a_kernelbase_PathCchRenameExtension;
	if (func == pPathCchSkipRoot)
		return wine32a_kernelbase_PathCchSkipRoot;
	if (func == pPathCchStripPrefix)
		return wine32a_kernelbase_PathCchStripPrefix;
	if (func == pPathCchStripToRoot)
		return wine32a_kernelbase_PathCchStripToRoot;
	if (func == pPathCombineA)
		return wine32a_kernelbase_PathCombineA;
	if (func == pPathCombineW)
		return wine32a_kernelbase_PathCombineW;
	if (func == pPathCommonPrefixA)
		return wine32a_kernelbase_PathCommonPrefixA;
	if (func == pPathCommonPrefixW)
		return wine32a_kernelbase_PathCommonPrefixW;
	if (func == pPathCreateFromUrlA)
		return wine32a_kernelbase_PathCreateFromUrlA;
	if (func == pPathCreateFromUrlAlloc)
		return wine32a_kernelbase_PathCreateFromUrlAlloc;
	if (func == pPathCreateFromUrlW)
		return wine32a_kernelbase_PathCreateFromUrlW;
	if (func == pPathFileExistsA)
		return wine32a_kernelbase_PathFileExistsA;
	if (func == pPathFileExistsW)
		return wine32a_kernelbase_PathFileExistsW;
	if (func == pPathFindExtensionA)
		return wine32a_kernelbase_PathFindExtensionA;
	if (func == pPathFindExtensionW)
		return wine32a_kernelbase_PathFindExtensionW;
	if (func == pPathFindFileNameA)
		return wine32a_kernelbase_PathFindFileNameA;
	if (func == pPathFindFileNameW)
		return wine32a_kernelbase_PathFindFileNameW;
	if (func == pPathFindNextComponentA)
		return wine32a_kernelbase_PathFindNextComponentA;
	if (func == pPathFindNextComponentW)
		return wine32a_kernelbase_PathFindNextComponentW;
	if (func == pPathGetArgsA)
		return wine32a_kernelbase_PathGetArgsA;
	if (func == pPathGetArgsW)
		return wine32a_kernelbase_PathGetArgsW;
	if (func == pPathGetCharTypeA)
		return wine32a_kernelbase_PathGetCharTypeA;
	if (func == pPathGetCharTypeW)
		return wine32a_kernelbase_PathGetCharTypeW;
	if (func == pPathGetDriveNumberA)
		return wine32a_kernelbase_PathGetDriveNumberA;
	if (func == pPathGetDriveNumberW)
		return wine32a_kernelbase_PathGetDriveNumberW;
	if (func == pPathIsFileSpecA)
		return wine32a_kernelbase_PathIsFileSpecA;
	if (func == pPathIsFileSpecW)
		return wine32a_kernelbase_PathIsFileSpecW;
	if (func == pPathIsLFNFileSpecA)
		return wine32a_kernelbase_PathIsLFNFileSpecA;
	if (func == pPathIsLFNFileSpecW)
		return wine32a_kernelbase_PathIsLFNFileSpecW;
	if (func == pPathIsPrefixA)
		return wine32a_kernelbase_PathIsPrefixA;
	if (func == pPathIsPrefixW)
		return wine32a_kernelbase_PathIsPrefixW;
	if (func == pPathIsRelativeA)
		return wine32a_kernelbase_PathIsRelativeA;
	if (func == pPathIsRelativeW)
		return wine32a_kernelbase_PathIsRelativeW;
	if (func == pPathIsRootA)
		return wine32a_kernelbase_PathIsRootA;
	if (func == pPathIsRootW)
		return wine32a_kernelbase_PathIsRootW;
	if (func == pPathIsSameRootA)
		return wine32a_kernelbase_PathIsSameRootA;
	if (func == pPathIsSameRootW)
		return wine32a_kernelbase_PathIsSameRootW;
	if (func == pPathIsUNCA)
		return wine32a_kernelbase_PathIsUNCA;
	if (func == pPathIsUNCEx)
		return wine32a_kernelbase_PathIsUNCEx;
	if (func == pPathIsUNCServerA)
		return wine32a_kernelbase_PathIsUNCServerA;
	if (func == pPathIsUNCServerShareA)
		return wine32a_kernelbase_PathIsUNCServerShareA;
	if (func == pPathIsUNCServerShareW)
		return wine32a_kernelbase_PathIsUNCServerShareW;
	if (func == pPathIsUNCServerW)
		return wine32a_kernelbase_PathIsUNCServerW;
	if (func == pPathIsUNCW)
		return wine32a_kernelbase_PathIsUNCW;
	if (func == pPathIsURLA)
		return wine32a_kernelbase_PathIsURLA;
	if (func == pPathIsURLW)
		return wine32a_kernelbase_PathIsURLW;
	if (func == pPathIsValidCharA)
		return wine32a_kernelbase_PathIsValidCharA;
	if (func == pPathIsValidCharW)
		return wine32a_kernelbase_PathIsValidCharW;
	if (func == pPathMatchSpecA)
		return wine32a_kernelbase_PathMatchSpecA;
	if (func == pPathMatchSpecW)
		return wine32a_kernelbase_PathMatchSpecW;
	if (func == pPathParseIconLocationA)
		return wine32a_kernelbase_PathParseIconLocationA;
	if (func == pPathParseIconLocationW)
		return wine32a_kernelbase_PathParseIconLocationW;
	if (func == pPathQuoteSpacesA)
		return wine32a_kernelbase_PathQuoteSpacesA;
	if (func == pPathQuoteSpacesW)
		return wine32a_kernelbase_PathQuoteSpacesW;
	if (func == pPathRelativePathToA)
		return wine32a_kernelbase_PathRelativePathToA;
	if (func == pPathRelativePathToW)
		return wine32a_kernelbase_PathRelativePathToW;
	if (func == pPathRemoveBackslashA)
		return wine32a_kernelbase_PathRemoveBackslashA;
	if (func == pPathRemoveBackslashW)
		return wine32a_kernelbase_PathRemoveBackslashW;
	if (func == pPathRemoveBlanksA)
		return wine32a_kernelbase_PathRemoveBlanksA;
	if (func == pPathRemoveBlanksW)
		return wine32a_kernelbase_PathRemoveBlanksW;
	if (func == pPathRemoveExtensionA)
		return wine32a_kernelbase_PathRemoveExtensionA;
	if (func == pPathRemoveExtensionW)
		return wine32a_kernelbase_PathRemoveExtensionW;
	if (func == pPathRemoveFileSpecA)
		return wine32a_kernelbase_PathRemoveFileSpecA;
	if (func == pPathRemoveFileSpecW)
		return wine32a_kernelbase_PathRemoveFileSpecW;
	if (func == pPathRenameExtensionA)
		return wine32a_kernelbase_PathRenameExtensionA;
	if (func == pPathRenameExtensionW)
		return wine32a_kernelbase_PathRenameExtensionW;
	if (func == pPathSearchAndQualifyA)
		return wine32a_kernelbase_PathSearchAndQualifyA;
	if (func == pPathSearchAndQualifyW)
		return wine32a_kernelbase_PathSearchAndQualifyW;
	if (func == pPathSkipRootA)
		return wine32a_kernelbase_PathSkipRootA;
	if (func == pPathSkipRootW)
		return wine32a_kernelbase_PathSkipRootW;
	if (func == pPathStripPathA)
		return wine32a_kernelbase_PathStripPathA;
	if (func == pPathStripPathW)
		return wine32a_kernelbase_PathStripPathW;
	if (func == pPathStripToRootA)
		return wine32a_kernelbase_PathStripToRootA;
	if (func == pPathStripToRootW)
		return wine32a_kernelbase_PathStripToRootW;
	if (func == pPathUnExpandEnvStringsA)
		return wine32a_kernelbase_PathUnExpandEnvStringsA;
	if (func == pPathUnExpandEnvStringsW)
		return wine32a_kernelbase_PathUnExpandEnvStringsW;
	if (func == pPathUnquoteSpacesA)
		return wine32a_kernelbase_PathUnquoteSpacesA;
	if (func == pPathUnquoteSpacesW)
		return wine32a_kernelbase_PathUnquoteSpacesW;
	if (func == pPeekConsoleInputA && func != pextPeekConsoleInputA)
		return wine_thunk_get_for_any(pextPeekConsoleInputA);
	if (func == pPeekConsoleInputW && func != pextPeekConsoleInputW)
		return wine_thunk_get_for_any(pextPeekConsoleInputW);
	if (func == pPeekNamedPipe)
		return wine32a_kernelbase_PeekNamedPipe;
	if (func == pPerfCreateInstance)
		return wine32a_kernelbase_PerfCreateInstance;
	if (func == pPerfDeleteInstance)
		return wine32a_kernelbase_PerfDeleteInstance;
	if (func == pPerfSetCounterRefValue)
		return wine32a_kernelbase_PerfSetCounterRefValue;
	if (func == pPerfSetCounterSetInfo)
		return wine32a_kernelbase_PerfSetCounterSetInfo;
	if (func == pPerfStartProvider)
		return wine32a_kernelbase_PerfStartProvider;
	if (func == pPerfStartProviderEx)
		return wine32a_kernelbase_PerfStartProviderEx;
	if (func == pPerfStopProvider)
		return wine32a_kernelbase_PerfStopProvider;
	if (func == pPostQueuedCompletionStatus)
		return wine32a_kernelbase_PostQueuedCompletionStatus;
	if (func == pPrivilegeCheck)
		return wine32a_kernelbase_PrivilegeCheck;
	if (func == pPrivilegedServiceAuditAlarmW)
		return wine32a_kernelbase_PrivilegedServiceAuditAlarmW;
	if (func == pProcessIdToSessionId && func != pextProcessIdToSessionId)
		return wine_thunk_get_for_any(pextProcessIdToSessionId);
	if (func == pPulseEvent)
		return wine32a_kernelbase_PulseEvent;
	if (func == pPurgeComm && func != pextPurgeComm)
		return wine_thunk_get_for_any(pextPurgeComm);
	if (func == pQISearch)
		return wine32a_kernelbase_QISearch;
	if (func == pQueryActCtxSettingsW)
		return wine32a_kernelbase_QueryActCtxSettingsW;
	if (func == pQueryActCtxW)
		return wine32a_kernelbase_QueryActCtxW;
	if (func == pQueryDepthSList && func != pextQueryDepthSList)
		return wine_thunk_get_for_any(pextQueryDepthSList);
	if (func == pQueryDosDeviceW && func != pextQueryDosDeviceW)
		return wine_thunk_get_for_any(pextQueryDosDeviceW);
	if (func == pQueryFullProcessImageNameA && func != pextQueryFullProcessImageNameA)
		return wine_thunk_get_for_any(pextQueryFullProcessImageNameA);
	if (func == pQueryFullProcessImageNameW && func != pextQueryFullProcessImageNameW)
		return wine_thunk_get_for_any(pextQueryFullProcessImageNameW);
	if (func == pQueryMemoryResourceNotification && func != pextQueryMemoryResourceNotification)
		return wine_thunk_get_for_any(pextQueryMemoryResourceNotification);
	if (func == pQueryPerformanceCounter && func != pextQueryPerformanceCounter)
		return wine_thunk_get_for_any(pextQueryPerformanceCounter);
	if (func == pQueryPerformanceFrequency && func != pextQueryPerformanceFrequency)
		return wine_thunk_get_for_any(pextQueryPerformanceFrequency);
	if (func == pQueryProcessCycleTime && func != pextQueryProcessCycleTime)
		return wine_thunk_get_for_any(pextQueryProcessCycleTime);
	if (func == pQueryThreadCycleTime && func != pextQueryThreadCycleTime)
		return wine_thunk_get_for_any(pextQueryThreadCycleTime);
	if (func == pQueryUnbiasedInterruptTime && func != pextQueryUnbiasedInterruptTime)
		return wine_thunk_get_for_any(pextQueryUnbiasedInterruptTime);
	if (func == pQueueUserAPC)
		return wine32a_kernelbase_QueueUserAPC;
	if (func == pQueueUserWorkItem)
		return wine32a_kernelbase_QueueUserWorkItem;
	if (func == pQuirkIsEnabled)
		return wine32a_kernelbase_QuirkIsEnabled;
	if (func == pQuirkIsEnabled3)
		return wine32a_kernelbase_QuirkIsEnabled3;
	if (func == pRaiseException && func != pextRaiseException)
		return wine_thunk_get_for_any(pextRaiseException);
	if (func == pReOpenFile)
		return wine32a_kernelbase_ReOpenFile;
	if (func == pReadConsoleA && func != pextReadConsoleA)
		return wine_thunk_get_for_any(pextReadConsoleA);
	if (func == pReadConsoleInputA && func != pextReadConsoleInputA)
		return wine_thunk_get_for_any(pextReadConsoleInputA);
	if (func == pReadConsoleInputW && func != pextReadConsoleInputW)
		return wine_thunk_get_for_any(pextReadConsoleInputW);
	if (func == pReadConsoleOutputA && func != pextReadConsoleOutputA)
		return wine_thunk_get_for_any(pextReadConsoleOutputA);
	if (func == pReadConsoleOutputAttribute && func != pextReadConsoleOutputAttribute)
		return wine_thunk_get_for_any(pextReadConsoleOutputAttribute);
	if (func == pReadConsoleOutputCharacterA && func != pextReadConsoleOutputCharacterA)
		return wine_thunk_get_for_any(pextReadConsoleOutputCharacterA);
	if (func == pReadConsoleOutputCharacterW && func != pextReadConsoleOutputCharacterW)
		return wine_thunk_get_for_any(pextReadConsoleOutputCharacterW);
	if (func == pReadConsoleOutputW && func != pextReadConsoleOutputW)
		return wine_thunk_get_for_any(pextReadConsoleOutputW);
	if (func == pReadConsoleW && func != pextReadConsoleW)
		return wine_thunk_get_for_any(pextReadConsoleW);
	if (func == pReadDirectoryChangesW && func != pextReadDirectoryChangesW)
		return wine_thunk_get_for_any(pextReadDirectoryChangesW);
	if (func == pReadFile)
		return wine32a_kernelbase_ReadFile;
	if (func == pReadFileEx)
		return wine32a_kernelbase_ReadFileEx;
	if (func == pReadFileScatter)
		return wine32a_kernelbase_ReadFileScatter;
	if (func == pReadProcessMemory && func != pextReadProcessMemory)
		return wine_thunk_get_for_any(pextReadProcessMemory);
	if (func == pRegCloseKey)
		return wine32a_kernelbase_RegCloseKey;
	if (func == pRegCopyTreeW)
		return wine32a_kernelbase_RegCopyTreeW;
	if (func == pRegCreateKeyExA)
		return wine32a_kernelbase_RegCreateKeyExA;
	if (func == pRegCreateKeyExW)
		return wine32a_kernelbase_RegCreateKeyExW;
	if (func == pRegDeleteKeyExA)
		return wine32a_kernelbase_RegDeleteKeyExA;
	if (func == pRegDeleteKeyExW)
		return wine32a_kernelbase_RegDeleteKeyExW;
	if (func == pRegDeleteKeyValueA)
		return wine32a_kernelbase_RegDeleteKeyValueA;
	if (func == pRegDeleteKeyValueW)
		return wine32a_kernelbase_RegDeleteKeyValueW;
	if (func == pRegDeleteTreeA)
		return wine32a_kernelbase_RegDeleteTreeA;
	if (func == pRegDeleteTreeW)
		return wine32a_kernelbase_RegDeleteTreeW;
	if (func == pRegDeleteValueA)
		return wine32a_kernelbase_RegDeleteValueA;
	if (func == pRegDeleteValueW)
		return wine32a_kernelbase_RegDeleteValueW;
	if (func == pRegEnumKeyExA)
		return wine32a_kernelbase_RegEnumKeyExA;
	if (func == pRegEnumKeyExW)
		return wine32a_kernelbase_RegEnumKeyExW;
	if (func == pRegEnumValueA)
		return wine32a_kernelbase_RegEnumValueA;
	if (func == pRegEnumValueW)
		return wine32a_kernelbase_RegEnumValueW;
	if (func == pRegFlushKey)
		return wine32a_kernelbase_RegFlushKey;
	if (func == pRegGetKeySecurity)
		return wine32a_kernelbase_RegGetKeySecurity;
	if (func == pRegGetValueA)
		return wine32a_kernelbase_RegGetValueA;
	if (func == pRegGetValueW)
		return wine32a_kernelbase_RegGetValueW;
	if (func == pRegLoadAppKeyA)
		return wine32a_kernelbase_RegLoadAppKeyA;
	if (func == pRegLoadAppKeyW)
		return wine32a_kernelbase_RegLoadAppKeyW;
	if (func == pRegLoadKeyA)
		return wine32a_kernelbase_RegLoadKeyA;
	if (func == pRegLoadKeyW)
		return wine32a_kernelbase_RegLoadKeyW;
	if (func == pRegLoadMUIStringA)
		return wine32a_kernelbase_RegLoadMUIStringA;
	if (func == pRegLoadMUIStringW)
		return wine32a_kernelbase_RegLoadMUIStringW;
	if (func == pRegNotifyChangeKeyValue)
		return wine32a_kernelbase_RegNotifyChangeKeyValue;
	if (func == pRegOpenCurrentUser)
		return wine32a_kernelbase_RegOpenCurrentUser;
	if (func == pRegOpenKeyExA)
		return wine32a_kernelbase_RegOpenKeyExA;
	if (func == pRegOpenKeyExW)
		return wine32a_kernelbase_RegOpenKeyExW;
	if (func == pRegOpenUserClassesRoot)
		return wine32a_kernelbase_RegOpenUserClassesRoot;
	if (func == pRegQueryInfoKeyA)
		return wine32a_kernelbase_RegQueryInfoKeyA;
	if (func == pRegQueryInfoKeyW)
		return wine32a_kernelbase_RegQueryInfoKeyW;
	if (func == pRegQueryValueExA)
		return wine32a_kernelbase_RegQueryValueExA;
	if (func == pRegQueryValueExW)
		return wine32a_kernelbase_RegQueryValueExW;
	if (func == pRegRestoreKeyA)
		return wine32a_kernelbase_RegRestoreKeyA;
	if (func == pRegRestoreKeyW)
		return wine32a_kernelbase_RegRestoreKeyW;
	if (func == pRegSaveKeyExA)
		return wine32a_kernelbase_RegSaveKeyExA;
	if (func == pRegSaveKeyExW)
		return wine32a_kernelbase_RegSaveKeyExW;
	if (func == pRegSetKeySecurity)
		return wine32a_kernelbase_RegSetKeySecurity;
	if (func == pRegSetKeyValueA)
		return wine32a_kernelbase_RegSetKeyValueA;
	if (func == pRegSetKeyValueW)
		return wine32a_kernelbase_RegSetKeyValueW;
	if (func == pRegSetValueExA)
		return wine32a_kernelbase_RegSetValueExA;
	if (func == pRegSetValueExW)
		return wine32a_kernelbase_RegSetValueExW;
	if (func == pRegUnLoadKeyA)
		return wine32a_kernelbase_RegUnLoadKeyA;
	if (func == pRegUnLoadKeyW)
		return wine32a_kernelbase_RegUnLoadKeyW;
	if (func == pRegisterTraceGuidsW && func != pextRegisterTraceGuidsW)
		return wine_thunk_get_for_any(pextRegisterTraceGuidsW);
	if (func == pRegisterWaitForSingleObjectEx)
		return wine32a_kernelbase_RegisterWaitForSingleObjectEx;
	if (func == pReleaseActCtx)
		return wine32a_kernelbase_ReleaseActCtx;
	if (func == pReleaseMutex)
		return wine32a_kernelbase_ReleaseMutex;
	if (func == pReleaseMutexWhenCallbackReturns && func != pextReleaseMutexWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseMutexWhenCallbackReturns);
	if (func == pReleaseSRWLockExclusive && func != pextReleaseSRWLockExclusive)
		return wine_thunk_get_for_any(pextReleaseSRWLockExclusive);
	if (func == pReleaseSRWLockShared && func != pextReleaseSRWLockShared)
		return wine_thunk_get_for_any(pextReleaseSRWLockShared);
	if (func == pReleaseSemaphore)
		return wine32a_kernelbase_ReleaseSemaphore;
	if (func == pReleaseSemaphoreWhenCallbackReturns && func != pextReleaseSemaphoreWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseSemaphoreWhenCallbackReturns);
	if (func == pRemapPredefinedHandleInternal)
		return wine32a_kernelbase_RemapPredefinedHandleInternal;
	if (func == pRemoveDirectoryA && func != pextRemoveDirectoryA)
		return wine_thunk_get_for_any(pextRemoveDirectoryA);
	if (func == pRemoveDirectoryW && func != pextRemoveDirectoryW)
		return wine_thunk_get_for_any(pextRemoveDirectoryW);
	if (func == pRemoveDllDirectory && func != pextRemoveDllDirectory)
		return wine_thunk_get_for_any(pextRemoveDllDirectory);
	if (func == pRemoveVectoredContinueHandler && func != pextRemoveVectoredContinueHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredContinueHandler);
	if (func == pRemoveVectoredExceptionHandler && func != pextRemoveVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredExceptionHandler);
	if (func == pReplaceFileW && func != pextReplaceFileW)
		return wine_thunk_get_for_any(pextReplaceFileW);
	if (func == pResetEvent)
		return wine32a_kernelbase_ResetEvent;
	if (func == pResetWriteWatch && func != pextResetWriteWatch)
		return wine_thunk_get_for_any(pextResetWriteWatch);
	if (func == pResolveDelayLoadedAPI && func != pextResolveDelayLoadedAPI)
		return wine_thunk_get_for_any(pextResolveDelayLoadedAPI);
	if (func == pResolveLocaleName && func != pextResolveLocaleName)
		return wine_thunk_get_for_any(pextResolveLocaleName);
	if (func == pRestoreLastError && func != pextRestoreLastError)
		return wine_thunk_get_for_any(pextRestoreLastError);
	if (func == pResumeThread)
		return wine32a_kernelbase_ResumeThread;
	if (func == pRevertToSelf)
		return wine32a_kernelbase_RevertToSelf;
	if (func == pSHExpandEnvironmentStringsA && func != pextSHExpandEnvironmentStringsA)
		return wine_thunk_get_for_any(pextSHExpandEnvironmentStringsA);
	if (func == pSHExpandEnvironmentStringsW && func != pextSHExpandEnvironmentStringsW)
		return wine_thunk_get_for_any(pextSHExpandEnvironmentStringsW);
	if (func == pSHLoadIndirectString)
		return wine32a_kernelbase_SHLoadIndirectString;
	if (func == pSHRegCloseUSKey)
		return wine32a_kernelbase_SHRegCloseUSKey;
	if (func == pSHRegCreateUSKeyA)
		return wine32a_kernelbase_SHRegCreateUSKeyA;
	if (func == pSHRegCreateUSKeyW)
		return wine32a_kernelbase_SHRegCreateUSKeyW;
	if (func == pSHRegDeleteEmptyUSKeyA)
		return wine32a_kernelbase_SHRegDeleteEmptyUSKeyA;
	if (func == pSHRegDeleteEmptyUSKeyW)
		return wine32a_kernelbase_SHRegDeleteEmptyUSKeyW;
	if (func == pSHRegDeleteUSValueA)
		return wine32a_kernelbase_SHRegDeleteUSValueA;
	if (func == pSHRegDeleteUSValueW)
		return wine32a_kernelbase_SHRegDeleteUSValueW;
	if (func == pSHRegEnumUSKeyA)
		return wine32a_kernelbase_SHRegEnumUSKeyA;
	if (func == pSHRegEnumUSKeyW)
		return wine32a_kernelbase_SHRegEnumUSKeyW;
	if (func == pSHRegEnumUSValueA)
		return wine32a_kernelbase_SHRegEnumUSValueA;
	if (func == pSHRegEnumUSValueW)
		return wine32a_kernelbase_SHRegEnumUSValueW;
	if (func == pSHRegGetBoolUSValueA)
		return wine32a_kernelbase_SHRegGetBoolUSValueA;
	if (func == pSHRegGetBoolUSValueW)
		return wine32a_kernelbase_SHRegGetBoolUSValueW;
	if (func == pSHRegGetUSValueA)
		return wine32a_kernelbase_SHRegGetUSValueA;
	if (func == pSHRegGetUSValueW)
		return wine32a_kernelbase_SHRegGetUSValueW;
	if (func == pSHRegOpenUSKeyA)
		return wine32a_kernelbase_SHRegOpenUSKeyA;
	if (func == pSHRegOpenUSKeyW)
		return wine32a_kernelbase_SHRegOpenUSKeyW;
	if (func == pSHRegQueryInfoUSKeyA)
		return wine32a_kernelbase_SHRegQueryInfoUSKeyA;
	if (func == pSHRegQueryInfoUSKeyW)
		return wine32a_kernelbase_SHRegQueryInfoUSKeyW;
	if (func == pSHRegQueryUSValueA)
		return wine32a_kernelbase_SHRegQueryUSValueA;
	if (func == pSHRegQueryUSValueW)
		return wine32a_kernelbase_SHRegQueryUSValueW;
	if (func == pSHRegSetUSValueA)
		return wine32a_kernelbase_SHRegSetUSValueA;
	if (func == pSHRegSetUSValueW)
		return wine32a_kernelbase_SHRegSetUSValueW;
	if (func == pSHRegWriteUSValueA)
		return wine32a_kernelbase_SHRegWriteUSValueA;
	if (func == pSHRegWriteUSValueW)
		return wine32a_kernelbase_SHRegWriteUSValueW;
	if (func == pSHTruncateString)
		return wine32a_kernelbase_SHTruncateString;
	if (func == pScrollConsoleScreenBufferA && func != pextScrollConsoleScreenBufferA)
		return wine_thunk_get_for_any(pextScrollConsoleScreenBufferA);
	if (func == pScrollConsoleScreenBufferW && func != pextScrollConsoleScreenBufferW)
		return wine_thunk_get_for_any(pextScrollConsoleScreenBufferW);
	if (func == pSearchPathA && func != pextSearchPathA)
		return wine_thunk_get_for_any(pextSearchPathA);
	if (func == pSearchPathW && func != pextSearchPathW)
		return wine_thunk_get_for_any(pextSearchPathW);
	if (func == pSetAclInformation)
		return wine32a_kernelbase_SetAclInformation;
	if (func == pSetCalendarInfoW && func != pextSetCalendarInfoW)
		return wine_thunk_get_for_any(pextSetCalendarInfoW);
	if (func == pSetCommBreak && func != pextSetCommBreak)
		return wine_thunk_get_for_any(pextSetCommBreak);
	if (func == pSetCommConfig && func != pextSetCommConfig)
		return wine_thunk_get_for_any(pextSetCommConfig);
	if (func == pSetCommMask && func != pextSetCommMask)
		return wine_thunk_get_for_any(pextSetCommMask);
	if (func == pSetCommState && func != pextSetCommState)
		return wine_thunk_get_for_any(pextSetCommState);
	if (func == pSetCommTimeouts && func != pextSetCommTimeouts)
		return wine_thunk_get_for_any(pextSetCommTimeouts);
	if (func == pSetComputerNameA && func != pextSetComputerNameA)
		return wine_thunk_get_for_any(pextSetComputerNameA);
	if (func == pSetComputerNameExA && func != pextSetComputerNameExA)
		return wine_thunk_get_for_any(pextSetComputerNameExA);
	if (func == pSetComputerNameExW && func != pextSetComputerNameExW)
		return wine_thunk_get_for_any(pextSetComputerNameExW);
	if (func == pSetComputerNameW && func != pextSetComputerNameW)
		return wine_thunk_get_for_any(pextSetComputerNameW);
	if (func == pSetConsoleActiveScreenBuffer && func != pextSetConsoleActiveScreenBuffer)
		return wine_thunk_get_for_any(pextSetConsoleActiveScreenBuffer);
	if (func == pSetConsoleCP && func != pextSetConsoleCP)
		return wine_thunk_get_for_any(pextSetConsoleCP);
	if (func == pSetConsoleCtrlHandler && func != pextSetConsoleCtrlHandler)
		return wine_thunk_get_for_any(pextSetConsoleCtrlHandler);
	if (func == pSetConsoleCursorInfo && func != pextSetConsoleCursorInfo)
		return wine_thunk_get_for_any(pextSetConsoleCursorInfo);
	if (func == pSetConsoleCursorPosition && func != pextSetConsoleCursorPosition)
		return wine_thunk_get_for_any(pextSetConsoleCursorPosition);
	if (func == pSetConsoleInputExeNameA && func != pextSetConsoleInputExeNameA)
		return wine_thunk_get_for_any(pextSetConsoleInputExeNameA);
	if (func == pSetConsoleInputExeNameW && func != pextSetConsoleInputExeNameW)
		return wine_thunk_get_for_any(pextSetConsoleInputExeNameW);
	if (func == pSetConsoleMode && func != pextSetConsoleMode)
		return wine_thunk_get_for_any(pextSetConsoleMode);
	if (func == pSetConsoleOutputCP && func != pextSetConsoleOutputCP)
		return wine_thunk_get_for_any(pextSetConsoleOutputCP);
	if (func == pSetConsoleScreenBufferInfoEx && func != pextSetConsoleScreenBufferInfoEx)
		return wine_thunk_get_for_any(pextSetConsoleScreenBufferInfoEx);
	if (func == pSetConsoleScreenBufferSize && func != pextSetConsoleScreenBufferSize)
		return wine_thunk_get_for_any(pextSetConsoleScreenBufferSize);
	if (func == pSetConsoleTextAttribute && func != pextSetConsoleTextAttribute)
		return wine_thunk_get_for_any(pextSetConsoleTextAttribute);
	if (func == pSetConsoleTitleW && func != pextSetConsoleTitleW)
		return wine_thunk_get_for_any(pextSetConsoleTitleW);
	if (func == pSetConsoleWindowInfo && func != pextSetConsoleWindowInfo)
		return wine_thunk_get_for_any(pextSetConsoleWindowInfo);
	if (func == pSetCriticalSectionSpinCount && func != pextSetCriticalSectionSpinCount)
		return wine_thunk_get_for_any(pextSetCriticalSectionSpinCount);
	if (func == pSetCurrentDirectoryA && func != pextSetCurrentDirectoryA)
		return wine_thunk_get_for_any(pextSetCurrentDirectoryA);
	if (func == pSetCurrentDirectoryW && func != pextSetCurrentDirectoryW)
		return wine_thunk_get_for_any(pextSetCurrentDirectoryW);
	if (func == pSetDefaultDllDirectories && func != pextSetDefaultDllDirectories)
		return wine_thunk_get_for_any(pextSetDefaultDllDirectories);
	if (func == pSetEndOfFile)
		return wine32a_kernelbase_SetEndOfFile;
	if (func == pSetEnvironmentVariableA && func != pextSetEnvironmentVariableA)
		return wine_thunk_get_for_any(pextSetEnvironmentVariableA);
	if (func == pSetEnvironmentVariableW && func != pextSetEnvironmentVariableW)
		return wine_thunk_get_for_any(pextSetEnvironmentVariableW);
	if (func == pSetErrorMode)
		return wine32a_kernelbase_SetErrorMode;
	if (func == pSetEvent)
		return wine32a_kernelbase_SetEvent;
	if (func == pSetEventWhenCallbackReturns && func != pextSetEventWhenCallbackReturns)
		return wine_thunk_get_for_any(pextSetEventWhenCallbackReturns);
	if (func == pSetFileApisToANSI)
		return wine32a_kernelbase_SetFileApisToANSI;
	if (func == pSetFileApisToOEM)
		return wine32a_kernelbase_SetFileApisToOEM;
	if (func == pSetFileAttributesA)
		return wine32a_kernelbase_SetFileAttributesA;
	if (func == pSetFileAttributesW)
		return wine32a_kernelbase_SetFileAttributesW;
	if (func == pSetFileInformationByHandle)
		return wine32a_kernelbase_SetFileInformationByHandle;
	if (func == pSetFilePointer)
		return wine32a_kernelbase_SetFilePointer;
	if (func == pSetFilePointerEx)
		return wine32a_kernelbase_SetFilePointerEx;
	if (func == pSetFileSecurityW)
		return wine32a_kernelbase_SetFileSecurityW;
	if (func == pSetFileTime)
		return wine32a_kernelbase_SetFileTime;
	if (func == pSetFileValidData)
		return wine32a_kernelbase_SetFileValidData;
	if (func == pSetHandleCount && func != pextSetHandleCount)
		return wine_thunk_get_for_any(pextSetHandleCount);
	if (func == pSetHandleInformation && func != pextSetHandleInformation)
		return wine_thunk_get_for_any(pextSetHandleInformation);
	if (func == pSetKernelObjectSecurity)
		return wine32a_kernelbase_SetKernelObjectSecurity;
	if (func == pSetLastError && func != pextSetLastError)
		return wine_thunk_get_for_any(pextSetLastError);
	if (func == pSetLocalTime && func != pextSetLocalTime)
		return wine_thunk_get_for_any(pextSetLocalTime);
	if (func == pSetLocaleInfoW && func != pextSetLocaleInfoW)
		return wine_thunk_get_for_any(pextSetLocaleInfoW);
	if (func == pSetNamedPipeHandleState)
		return wine32a_kernelbase_SetNamedPipeHandleState;
	if (func == pSetPriorityClass)
		return wine32a_kernelbase_SetPriorityClass;
	if (func == pSetPrivateObjectSecurity)
		return wine32a_kernelbase_SetPrivateObjectSecurity;
	if (func == pSetProcessAffinityUpdateMode)
		return wine32a_kernelbase_SetProcessAffinityUpdateMode;
	if (func == pSetProcessMitigationPolicy)
		return wine32a_kernelbase_SetProcessMitigationPolicy;
	if (func == pSetProcessPreferredUILanguages && func != pextSetProcessPreferredUILanguages)
		return wine_thunk_get_for_any(pextSetProcessPreferredUILanguages);
	if (func == pSetProcessPriorityBoost)
		return wine32a_kernelbase_SetProcessPriorityBoost;
	if (func == pSetProcessShutdownParameters)
		return wine32a_kernelbase_SetProcessShutdownParameters;
	if (func == pSetProcessWorkingSetSizeEx)
		return wine32a_kernelbase_SetProcessWorkingSetSizeEx;
	if (func == pSetSecurityDescriptorControl)
		return wine32a_kernelbase_SetSecurityDescriptorControl;
	if (func == pSetSecurityDescriptorDacl)
		return wine32a_kernelbase_SetSecurityDescriptorDacl;
	if (func == pSetSecurityDescriptorGroup)
		return wine32a_kernelbase_SetSecurityDescriptorGroup;
	if (func == pSetSecurityDescriptorOwner)
		return wine32a_kernelbase_SetSecurityDescriptorOwner;
	if (func == pSetSecurityDescriptorSacl)
		return wine32a_kernelbase_SetSecurityDescriptorSacl;
	if (func == pSetStdHandle && func != pextSetStdHandle)
		return wine_thunk_get_for_any(pextSetStdHandle);
	if (func == pSetSystemFileCacheSize && func != pextSetSystemFileCacheSize)
		return wine_thunk_get_for_any(pextSetSystemFileCacheSize);
	if (func == pSetSystemTime && func != pextSetSystemTime)
		return wine_thunk_get_for_any(pextSetSystemTime);
	if (func == pSetSystemTimeAdjustment && func != pextSetSystemTimeAdjustment)
		return wine_thunk_get_for_any(pextSetSystemTimeAdjustment);
	if (func == pSetThreadContext)
		return wine32a_kernelbase_SetThreadContext;
	if (func == pSetThreadErrorMode)
		return wine32a_kernelbase_SetThreadErrorMode;
	if (func == pSetThreadGroupAffinity)
		return wine32a_kernelbase_SetThreadGroupAffinity;
	if (func == pSetThreadIdealProcessor)
		return wine32a_kernelbase_SetThreadIdealProcessor;
	if (func == pSetThreadIdealProcessorEx)
		return wine32a_kernelbase_SetThreadIdealProcessorEx;
	if (func == pSetThreadLocale && func != pextSetThreadLocale)
		return wine_thunk_get_for_any(pextSetThreadLocale);
	if (func == pSetThreadPreferredUILanguages && func != pextSetThreadPreferredUILanguages)
		return wine_thunk_get_for_any(pextSetThreadPreferredUILanguages);
	if (func == pSetThreadPriority)
		return wine32a_kernelbase_SetThreadPriority;
	if (func == pSetThreadPriorityBoost)
		return wine32a_kernelbase_SetThreadPriorityBoost;
	if (func == pSetThreadStackGuarantee)
		return wine32a_kernelbase_SetThreadStackGuarantee;
	if (func == pSetThreadToken)
		return wine32a_kernelbase_SetThreadToken;
	if (func == pSetThreadUILanguage && func != pextSetThreadUILanguage)
		return wine_thunk_get_for_any(pextSetThreadUILanguage);
	if (func == pSetThreadpoolThreadMaximum && func != pextSetThreadpoolThreadMaximum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMaximum);
	if (func == pSetThreadpoolThreadMinimum && func != pextSetThreadpoolThreadMinimum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMinimum);
	if (func == pSetThreadpoolTimer && func != pextSetThreadpoolTimer)
		return wine_thunk_get_for_any(pextSetThreadpoolTimer);
	if (func == pSetThreadpoolWait && func != pextSetThreadpoolWait)
		return wine_thunk_get_for_any(pextSetThreadpoolWait);
	if (func == pSetTimeZoneInformation && func != pextSetTimeZoneInformation)
		return wine_thunk_get_for_any(pextSetTimeZoneInformation);
	if (func == pSetTokenInformation)
		return wine32a_kernelbase_SetTokenInformation;
	if (func == pSetUnhandledExceptionFilter && func != pextSetUnhandledExceptionFilter)
		return wine_thunk_get_for_any(pextSetUnhandledExceptionFilter);
	if (func == pSetUserGeoID && func != pextSetUserGeoID)
		return wine_thunk_get_for_any(pextSetUserGeoID);
	if (func == pSetWaitableTimer)
		return wine32a_kernelbase_SetWaitableTimer;
	if (func == pSetWaitableTimerEx)
		return wine32a_kernelbase_SetWaitableTimerEx;
	if (func == pSetupComm && func != pextSetupComm)
		return wine_thunk_get_for_any(pextSetupComm);
	if (func == pSignalObjectAndWait)
		return wine32a_kernelbase_SignalObjectAndWait;
	if (func == pSizeofResource)
		return wine32a_kernelbase_SizeofResource;
	if (func == pSleep)
		return wine32a_kernelbase_Sleep;
	if (func == pSleepConditionVariableCS)
		return wine32a_kernelbase_SleepConditionVariableCS;
	if (func == pSleepConditionVariableSRW)
		return wine32a_kernelbase_SleepConditionVariableSRW;
	if (func == pSleepEx)
		return wine32a_kernelbase_SleepEx;
	if (func == pStrCSpnA)
		return wine32a_kernelbase_StrCSpnA;
	if (func == pStrCSpnIA)
		return wine32a_kernelbase_StrCSpnIA;
	if (func == pStrCSpnIW)
		return wine32a_kernelbase_StrCSpnIW;
	if (func == pStrCSpnW)
		return wine32a_kernelbase_StrCSpnW;
	if (func == pStrCatBuffA)
		return wine32a_kernelbase_StrCatBuffA;
	if (func == pStrCatBuffW)
		return wine32a_kernelbase_StrCatBuffW;
	if (func == pStrCatChainW)
		return wine32a_kernelbase_StrCatChainW;
	if (func == pStrChrA)
		return wine32a_kernelbase_StrChrA;
	if (func == pStrChrIA)
		return wine32a_kernelbase_StrChrIA;
	if (func == pStrChrIW)
		return wine32a_kernelbase_StrChrIW;
	if (func == pStrChrNW)
		return wine32a_kernelbase_StrChrNW;
	if (func == pStrChrW)
		return wine32a_kernelbase_StrChrW;
	if (func == pStrCmpCA)
		return wine32a_kernelbase_StrCmpCA;
	if (func == pStrCmpCW)
		return wine32a_kernelbase_StrCmpCW;
	if (func == pStrCmpICA)
		return wine32a_kernelbase_StrCmpICA;
	if (func == pStrCmpICW)
		return wine32a_kernelbase_StrCmpICW;
	if (func == pStrCmpIW)
		return wine32a_kernelbase_StrCmpIW;
	if (func == pStrCmpLogicalW)
		return wine32a_kernelbase_StrCmpLogicalW;
	if (func == pStrCmpNA)
		return wine32a_kernelbase_StrCmpNA;
	if (func == pStrCmpNCA)
		return wine32a_kernelbase_StrCmpNCA;
	if (func == pStrCmpNCW)
		return wine32a_kernelbase_StrCmpNCW;
	if (func == pStrCmpNIA)
		return wine32a_kernelbase_StrCmpNIA;
	if (func == pStrCmpNICA)
		return wine32a_kernelbase_StrCmpNICA;
	if (func == pStrCmpNICW)
		return wine32a_kernelbase_StrCmpNICW;
	if (func == pStrCmpNIW)
		return wine32a_kernelbase_StrCmpNIW;
	if (func == pStrCmpNW)
		return wine32a_kernelbase_StrCmpNW;
	if (func == pStrCmpW)
		return wine32a_kernelbase_StrCmpW;
	if (func == pStrCpyNW)
		return wine32a_kernelbase_StrCpyNW;
	if (func == pStrCpyNXA)
		return wine32a_kernelbase_StrCpyNXA;
	if (func == pStrCpyNXW)
		return wine32a_kernelbase_StrCpyNXW;
	if (func == pStrDupA)
		return wine32a_kernelbase_StrDupA;
	if (func == pStrDupW)
		return wine32a_kernelbase_StrDupW;
	if (func == pStrIsIntlEqualA)
		return wine32a_kernelbase_StrIsIntlEqualA;
	if (func == pStrIsIntlEqualW)
		return wine32a_kernelbase_StrIsIntlEqualW;
	if (func == pStrPBrkA)
		return wine32a_kernelbase_StrPBrkA;
	if (func == pStrPBrkW)
		return wine32a_kernelbase_StrPBrkW;
	if (func == pStrRChrA)
		return wine32a_kernelbase_StrRChrA;
	if (func == pStrRChrIA)
		return wine32a_kernelbase_StrRChrIA;
	if (func == pStrRChrIW)
		return wine32a_kernelbase_StrRChrIW;
	if (func == pStrRChrW)
		return wine32a_kernelbase_StrRChrW;
	if (func == pStrRStrIA)
		return wine32a_kernelbase_StrRStrIA;
	if (func == pStrRStrIW)
		return wine32a_kernelbase_StrRStrIW;
	if (func == pStrSpnA)
		return wine32a_kernelbase_StrSpnA;
	if (func == pStrSpnW)
		return wine32a_kernelbase_StrSpnW;
	if (func == pStrStrA)
		return wine32a_kernelbase_StrStrA;
	if (func == pStrStrIA)
		return wine32a_kernelbase_StrStrIA;
	if (func == pStrStrIW)
		return wine32a_kernelbase_StrStrIW;
	if (func == pStrStrNIW)
		return wine32a_kernelbase_StrStrNIW;
	if (func == pStrStrNW)
		return wine32a_kernelbase_StrStrNW;
	if (func == pStrStrW)
		return wine32a_kernelbase_StrStrW;
	if (func == pStrToInt64ExA)
		return wine32a_kernelbase_StrToInt64ExA;
	if (func == pStrToInt64ExW)
		return wine32a_kernelbase_StrToInt64ExW;
	if (func == pStrToIntA)
		return wine32a_kernelbase_StrToIntA;
	if (func == pStrToIntExA)
		return wine32a_kernelbase_StrToIntExA;
	if (func == pStrToIntExW)
		return wine32a_kernelbase_StrToIntExW;
	if (func == pStrToIntW)
		return wine32a_kernelbase_StrToIntW;
	if (func == pStrTrimA)
		return wine32a_kernelbase_StrTrimA;
	if (func == pStrTrimW)
		return wine32a_kernelbase_StrTrimW;
	if (func == pSubmitThreadpoolWork && func != pextSubmitThreadpoolWork)
		return wine_thunk_get_for_any(pextSubmitThreadpoolWork);
	if (func == pSuspendThread)
		return wine32a_kernelbase_SuspendThread;
	if (func == pSwitchToFiber)
		return wine32a_kernelbase_SwitchToFiber;
	if (func == pSwitchToThread)
		return wine32a_kernelbase_SwitchToThread;
	if (func == pSystemTimeToFileTime && func != pextSystemTimeToFileTime)
		return wine_thunk_get_for_any(pextSystemTimeToFileTime);
	if (func == pSystemTimeToTzSpecificLocalTime && func != pextSystemTimeToTzSpecificLocalTime)
		return wine_thunk_get_for_any(pextSystemTimeToTzSpecificLocalTime);
	if (func == pTerminateProcess)
		return wine32a_kernelbase_TerminateProcess;
	if (func == pTerminateThread)
		return wine32a_kernelbase_TerminateThread;
	if (func == pTlsAlloc)
		return wine32a_kernelbase_TlsAlloc;
	if (func == pTlsFree)
		return wine32a_kernelbase_TlsFree;
	if (func == pTlsGetValue)
		return wine32a_kernelbase_TlsGetValue;
	if (func == pTlsSetValue)
		return wine32a_kernelbase_TlsSetValue;
	if (func == pTraceEvent && func != pextTraceEvent)
		return wine_thunk_get_for_any(pextTraceEvent);
	if (func == pTraceMessage && func != pextTraceMessage)
		return wine_thunk_get_for_any(pextTraceMessage);
	if (func == pTraceMessageVa && func != pextTraceMessageVa)
		return wine_thunk_get_for_any(pextTraceMessageVa);
	if (func == pTransactNamedPipe)
		return wine32a_kernelbase_TransactNamedPipe;
	if (func == pTransmitCommChar && func != pextTransmitCommChar)
		return wine_thunk_get_for_any(pextTransmitCommChar);
	if (func == pTryAcquireSRWLockExclusive && func != pextTryAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockExclusive);
	if (func == pTryAcquireSRWLockShared && func != pextTryAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockShared);
	if (func == pTryEnterCriticalSection && func != pextTryEnterCriticalSection)
		return wine_thunk_get_for_any(pextTryEnterCriticalSection);
	if (func == pTrySubmitThreadpoolCallback)
		return wine32a_kernelbase_TrySubmitThreadpoolCallback;
	if (func == pTzSpecificLocalTimeToSystemTime && func != pextTzSpecificLocalTimeToSystemTime)
		return wine_thunk_get_for_any(pextTzSpecificLocalTimeToSystemTime);
	if (func == pUnhandledExceptionFilter && func != pextUnhandledExceptionFilter)
		return wine_thunk_get_for_any(pextUnhandledExceptionFilter);
	if (func == pUnlockFile)
		return wine32a_kernelbase_UnlockFile;
	if (func == pUnlockFileEx)
		return wine32a_kernelbase_UnlockFileEx;
	if (func == pUnmapViewOfFile && func != pextUnmapViewOfFile)
		return wine_thunk_get_for_any(pextUnmapViewOfFile);
	if (func == pUnregisterTraceGuids && func != pextUnregisterTraceGuids)
		return wine_thunk_get_for_any(pextUnregisterTraceGuids);
	if (func == pUnregisterWaitEx)
		return wine32a_kernelbase_UnregisterWaitEx;
	if (func == pUpdateProcThreadAttribute)
		return wine32a_kernelbase_UpdateProcThreadAttribute;
	if (func == pUrlApplySchemeA)
		return wine32a_kernelbase_UrlApplySchemeA;
	if (func == pUrlApplySchemeW)
		return wine32a_kernelbase_UrlApplySchemeW;
	if (func == pUrlCanonicalizeA)
		return wine32a_kernelbase_UrlCanonicalizeA;
	if (func == pUrlCanonicalizeW)
		return wine32a_kernelbase_UrlCanonicalizeW;
	if (func == pUrlCombineA)
		return wine32a_kernelbase_UrlCombineA;
	if (func == pUrlCombineW)
		return wine32a_kernelbase_UrlCombineW;
	if (func == pUrlCompareA)
		return wine32a_kernelbase_UrlCompareA;
	if (func == pUrlCompareW)
		return wine32a_kernelbase_UrlCompareW;
	if (func == pUrlCreateFromPathA)
		return wine32a_kernelbase_UrlCreateFromPathA;
	if (func == pUrlCreateFromPathW)
		return wine32a_kernelbase_UrlCreateFromPathW;
	if (func == pUrlEscapeA)
		return wine32a_kernelbase_UrlEscapeA;
	if (func == pUrlEscapeW)
		return wine32a_kernelbase_UrlEscapeW;
	if (func == pUrlFixupW)
		return wine32a_kernelbase_UrlFixupW;
	if (func == pUrlGetLocationA)
		return wine32a_kernelbase_UrlGetLocationA;
	if (func == pUrlGetLocationW)
		return wine32a_kernelbase_UrlGetLocationW;
	if (func == pUrlGetPartA)
		return wine32a_kernelbase_UrlGetPartA;
	if (func == pUrlGetPartW)
		return wine32a_kernelbase_UrlGetPartW;
	if (func == pUrlHashA)
		return wine32a_kernelbase_UrlHashA;
	if (func == pUrlHashW)
		return wine32a_kernelbase_UrlHashW;
	if (func == pUrlIsA)
		return wine32a_kernelbase_UrlIsA;
	if (func == pUrlIsNoHistoryA)
		return wine32a_kernelbase_UrlIsNoHistoryA;
	if (func == pUrlIsNoHistoryW)
		return wine32a_kernelbase_UrlIsNoHistoryW;
	if (func == pUrlIsOpaqueA)
		return wine32a_kernelbase_UrlIsOpaqueA;
	if (func == pUrlIsOpaqueW)
		return wine32a_kernelbase_UrlIsOpaqueW;
	if (func == pUrlIsW)
		return wine32a_kernelbase_UrlIsW;
	if (func == pUrlUnescapeA)
		return wine32a_kernelbase_UrlUnescapeA;
	if (func == pUrlUnescapeW)
		return wine32a_kernelbase_UrlUnescapeW;
	if (func == pVerFindFileA)
		return wine32a_kernelbase_VerFindFileA;
	if (func == pVerFindFileW)
		return wine32a_kernelbase_VerFindFileW;
	if (func == pVerLanguageNameA && func != pextVerLanguageNameA)
		return wine_thunk_get_for_any(pextVerLanguageNameA);
	if (func == pVerLanguageNameW && func != pextVerLanguageNameW)
		return wine_thunk_get_for_any(pextVerLanguageNameW);
	if (func == pVerQueryValueA)
		return wine32a_kernelbase_VerQueryValueA;
	if (func == pVerQueryValueW)
		return wine32a_kernelbase_VerQueryValueW;
	if (func == pVerSetConditionMask && func != pextVerSetConditionMask)
		return wine_thunk_get_for_any(pextVerSetConditionMask);
	if (func == pVirtualAlloc && func != pextVirtualAlloc)
		return wine_thunk_get_for_any(pextVirtualAlloc);
	if (func == pVirtualAllocEx && func != pextVirtualAllocEx)
		return wine_thunk_get_for_any(pextVirtualAllocEx);
	if (func == pVirtualAllocExNuma && func != pextVirtualAllocExNuma)
		return wine_thunk_get_for_any(pextVirtualAllocExNuma);
	if (func == pVirtualFree && func != pextVirtualFree)
		return wine_thunk_get_for_any(pextVirtualFree);
	if (func == pVirtualFreeEx && func != pextVirtualFreeEx)
		return wine_thunk_get_for_any(pextVirtualFreeEx);
	if (func == pVirtualLock && func != pextVirtualLock)
		return wine_thunk_get_for_any(pextVirtualLock);
	if (func == pVirtualProtect && func != pextVirtualProtect)
		return wine_thunk_get_for_any(pextVirtualProtect);
	if (func == pVirtualProtectEx && func != pextVirtualProtectEx)
		return wine_thunk_get_for_any(pextVirtualProtectEx);
	if (func == pVirtualQuery && func != pextVirtualQuery)
		return wine_thunk_get_for_any(pextVirtualQuery);
	if (func == pVirtualQueryEx && func != pextVirtualQueryEx)
		return wine_thunk_get_for_any(pextVirtualQueryEx);
	if (func == pVirtualUnlock && func != pextVirtualUnlock)
		return wine_thunk_get_for_any(pextVirtualUnlock);
	if (func == pWaitCommEvent && func != pextWaitCommEvent)
		return wine_thunk_get_for_any(pextWaitCommEvent);
	if (func == pWaitForDebugEvent && func != pextWaitForDebugEvent)
		return wine_thunk_get_for_any(pextWaitForDebugEvent);
	if (func == pWaitForMultipleObjects)
		return wine32a_kernelbase_WaitForMultipleObjects;
	if (func == pWaitForMultipleObjectsEx)
		return wine32a_kernelbase_WaitForMultipleObjectsEx;
	if (func == pWaitForSingleObject)
		return wine32a_kernelbase_WaitForSingleObject;
	if (func == pWaitForSingleObjectEx)
		return wine32a_kernelbase_WaitForSingleObjectEx;
	if (func == pWaitForThreadpoolTimerCallbacks && func != pextWaitForThreadpoolTimerCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolTimerCallbacks);
	if (func == pWaitForThreadpoolWaitCallbacks && func != pextWaitForThreadpoolWaitCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWaitCallbacks);
	if (func == pWaitForThreadpoolWorkCallbacks && func != pextWaitForThreadpoolWorkCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWorkCallbacks);
	if (func == pWaitNamedPipeW)
		return wine32a_kernelbase_WaitNamedPipeW;
	if (func == pWaitOnAddress)
		return wine32a_kernelbase_WaitOnAddress;
	if (func == pWakeAllConditionVariable && func != pextWakeAllConditionVariable)
		return wine_thunk_get_for_any(pextWakeAllConditionVariable);
	if (func == pWakeByAddressAll && func != pextWakeByAddressAll)
		return wine_thunk_get_for_any(pextWakeByAddressAll);
	if (func == pWakeByAddressSingle && func != pextWakeByAddressSingle)
		return wine_thunk_get_for_any(pextWakeByAddressSingle);
	if (func == pWakeConditionVariable && func != pextWakeConditionVariable)
		return wine_thunk_get_for_any(pextWakeConditionVariable);
	if (func == pWerRegisterFile && func != pextWerRegisterFile)
		return wine_thunk_get_for_any(pextWerRegisterFile);
	if (func == pWerRegisterMemoryBlock && func != pextWerRegisterMemoryBlock)
		return wine_thunk_get_for_any(pextWerRegisterMemoryBlock);
	if (func == pWerRegisterRuntimeExceptionModule && func != pextWerRegisterRuntimeExceptionModule)
		return wine_thunk_get_for_any(pextWerRegisterRuntimeExceptionModule);
	if (func == pWerSetFlags && func != pextWerSetFlags)
		return wine_thunk_get_for_any(pextWerSetFlags);
	if (func == pWerUnregisterMemoryBlock && func != pextWerUnregisterMemoryBlock)
		return wine_thunk_get_for_any(pextWerUnregisterMemoryBlock);
	if (func == pWerUnregisterRuntimeExceptionModule && func != pextWerUnregisterRuntimeExceptionModule)
		return wine_thunk_get_for_any(pextWerUnregisterRuntimeExceptionModule);
	if (func == pWideCharToMultiByte && func != pextWideCharToMultiByte)
		return wine_thunk_get_for_any(pextWideCharToMultiByte);
	if (func == pWow64DisableWow64FsRedirection)
		return wine32a_kernelbase_Wow64DisableWow64FsRedirection;
	if (func == pWow64RevertWow64FsRedirection)
		return wine32a_kernelbase_Wow64RevertWow64FsRedirection;
	if (func == pWriteConsoleA && func != pextWriteConsoleA)
		return wine_thunk_get_for_any(pextWriteConsoleA);
	if (func == pWriteConsoleInputA && func != pextWriteConsoleInputA)
		return wine_thunk_get_for_any(pextWriteConsoleInputA);
	if (func == pWriteConsoleInputW && func != pextWriteConsoleInputW)
		return wine_thunk_get_for_any(pextWriteConsoleInputW);
	if (func == pWriteConsoleOutputA && func != pextWriteConsoleOutputA)
		return wine_thunk_get_for_any(pextWriteConsoleOutputA);
	if (func == pWriteConsoleOutputAttribute && func != pextWriteConsoleOutputAttribute)
		return wine_thunk_get_for_any(pextWriteConsoleOutputAttribute);
	if (func == pWriteConsoleOutputCharacterA && func != pextWriteConsoleOutputCharacterA)
		return wine_thunk_get_for_any(pextWriteConsoleOutputCharacterA);
	if (func == pWriteConsoleOutputCharacterW && func != pextWriteConsoleOutputCharacterW)
		return wine_thunk_get_for_any(pextWriteConsoleOutputCharacterW);
	if (func == pWriteConsoleOutputW && func != pextWriteConsoleOutputW)
		return wine_thunk_get_for_any(pextWriteConsoleOutputW);
	if (func == pWriteConsoleW && func != pextWriteConsoleW)
		return wine_thunk_get_for_any(pextWriteConsoleW);
	if (func == pWriteFile)
		return wine32a_kernelbase_WriteFile;
	if (func == pWriteFileEx)
		return wine32a_kernelbase_WriteFileEx;
	if (func == pWriteFileGather)
		return wine32a_kernelbase_WriteFileGather;
	if (func == pWriteProcessMemory && func != pextWriteProcessMemory)
		return wine_thunk_get_for_any(pextWriteProcessMemory);
	if (func == pZombifyActCtx)
		return wine32a_kernelbase_ZombifyActCtx;
	if (func == p__C_specific_handler && func != pext__C_specific_handler)
		return wine_thunk_get_for_any(pext__C_specific_handler);
	if (func == p__chkstk && func != pext__chkstk)
		return wine_thunk_get_for_any(pext__chkstk);
	if (func == p_local_unwind && func != pext_local_unwind)
		return wine_thunk_get_for_any(pext_local_unwind);
	if (func == plstrcmpA)
		return wine32a_kernelbase_lstrcmpA;
	if (func == plstrcmpW)
		return wine32a_kernelbase_lstrcmpW;
	if (func == plstrcmpiA)
		return wine32a_kernelbase_lstrcmpiA;
	if (func == plstrcmpiW)
		return wine32a_kernelbase_lstrcmpiW;
	if (func == plstrcpynA)
		return wine32a_kernelbase_lstrcpynA;
	if (func == plstrcpynW)
		return wine32a_kernelbase_lstrcpynW;
	if (func == plstrlenA)
		return wine32a_kernelbase_lstrlenA;
	if (func == plstrlenW)
		return wine32a_kernelbase_lstrlenW;

	return NULL;
}
