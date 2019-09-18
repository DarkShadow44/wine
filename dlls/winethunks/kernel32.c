#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
#include "wine/winethunks.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

struct _MODULEINFO; /* ../include/psapi.h:28 */
struct _PROCESS_MEMORY_COUNTERS; /* ../include/psapi.h:34 */
struct _PSAPI_WS_WATCH_INFORMATION; /* ../include/psapi.h:48 */
struct _PSAPI_WS_WATCH_INFORMATION_EX; /* ../include/psapi.h:53 */
struct _PERFORMANCE_INFORMATION; /* ../include/psapi.h:59 */
struct _ENUM_PAGE_FILE_INFORMATION; /* ../include/psapi.h:76 */
struct tagTHREADENTRY32; /* ../include/tlhelp32.h:43 */
struct tagPROCESSENTRY32; /* ../include/tlhelp32.h:61 */
struct tagPROCESSENTRY32W; /* ../include/tlhelp32.h:75 */
struct tagMODULEENTRY32; /* ../include/tlhelp32.h:108 */
struct tagMODULEENTRY32W; /* ../include/tlhelp32.h:122 */
struct tagHEAPLIST32; /* ../include/tlhelp32.h:149 */
enum _WER_REGISTER_FILE_TYPE; /* ../include/werapi.h:83 */

typedef unsigned int UINT32; /* ../include/basetsd.h:84 */

typedef unsigned long* PULONG64; /* ../include/basetsd.h:99 */

typedef unsigned long DWORD64; /* ../include/basetsd.h:100 */

typedef long LONG_PTR; /* ../include/basetsd.h:118 */

typedef unsigned long UINT_PTR; /* ../include/basetsd.h:119 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef unsigned long* PULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR DWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR* PDWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR SIZE_T; /* ../include/basetsd.h:264 */

typedef ULONG_PTR* PSIZE_T; /* ../include/basetsd.h:264 */

typedef void* DLL_DIRECTORY_COOKIE; /* ../include/libloaderapi.h:26 */

struct _MODULEINFO /* ../include/psapi.h:28 */
{
    LPVOID lpBaseOfDll;
    DWORD SizeOfImage;
    LPVOID EntryPoint;
};


typedef struct _MODULEINFO MODULEINFO; /* ../include/psapi.h:32 */

struct _PROCESS_MEMORY_COUNTERS /* ../include/psapi.h:34 */
{
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
};


typedef struct _PROCESS_MEMORY_COUNTERS PROCESS_MEMORY_COUNTERS; /* ../include/psapi.h:45 */

typedef PROCESS_MEMORY_COUNTERS* PPROCESS_MEMORY_COUNTERS; /* ../include/psapi.h:46 */

struct _PSAPI_WS_WATCH_INFORMATION /* ../include/psapi.h:48 */
{
    LPVOID FaultingPc;
    LPVOID FaultingVa;
};


typedef struct _PSAPI_WS_WATCH_INFORMATION PSAPI_WS_WATCH_INFORMATION; /* ../include/psapi.h:51 */

typedef struct _PSAPI_WS_WATCH_INFORMATION* PPSAPI_WS_WATCH_INFORMATION; /* ../include/psapi.h:51 */

struct _PSAPI_WS_WATCH_INFORMATION_EX /* ../include/psapi.h:53 */
{
    PSAPI_WS_WATCH_INFORMATION BasicInfo;
    ULONG_PTR FaultingThreadId;
    ULONG_PTR Flags;
};


typedef struct _PSAPI_WS_WATCH_INFORMATION_EX PSAPI_WS_WATCH_INFORMATION_EX; /* ../include/psapi.h:57 */

struct _PERFORMANCE_INFORMATION /* ../include/psapi.h:59 */
{
    DWORD cb;
    SIZE_T CommitTotal;
    SIZE_T CommitLimit;
    SIZE_T CommitPeak;
    SIZE_T PhysicalTotal;
    SIZE_T PhysicalAvailable;
    SIZE_T SystemCache;
    SIZE_T KernelTotal;
    SIZE_T KernelPaged;
    SIZE_T KernelNonpaged;
    SIZE_T PageSize;
    DWORD HandleCount;
    DWORD ProcessCount;
    DWORD ThreadCount;
};


typedef struct _PERFORMANCE_INFORMATION* PPERFORMANCE_INFORMATION; /* ../include/psapi.h:74 */

struct _ENUM_PAGE_FILE_INFORMATION /* ../include/psapi.h:76 */
{
    DWORD cb;
    DWORD Reserved;
    SIZE_T TotalSize;
    SIZE_T TotalInUse;
    SIZE_T PeakUsage;
};


typedef struct _ENUM_PAGE_FILE_INFORMATION* PENUM_PAGE_FILE_INFORMATION; /* ../include/psapi.h:82 */

typedef BOOL (*PENUM_PAGE_FILE_CALLBACKA) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCSTR); /* ../include/psapi.h:84 */

typedef BOOL (*PENUM_PAGE_FILE_CALLBACKW) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCWSTR); /* ../include/psapi.h:85 */

typedef int HRESULT; /* ../include/winerror.h:93 */

struct tagTHREADENTRY32 /* ../include/tlhelp32.h:43 */
{
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ThreadID;
    DWORD th32OwnerProcessID;
    LONG tpBasePri;
    LONG tpDeltaPri;
    DWORD dwFlags;
};


typedef struct tagTHREADENTRY32* LPTHREADENTRY32; /* ../include/tlhelp32.h:52 */

struct tagPROCESSENTRY32 /* ../include/tlhelp32.h:61 */
{
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ProcessID;
    ULONG_PTR th32DefaultHeapID;
    DWORD th32ModuleID;
    DWORD cntThreads;
    DWORD th32ParentProcessID;
    LONG pcPriClassBase;
    DWORD dwFlags;
    char szExeFile[260];
};


typedef struct tagPROCESSENTRY32* LPPROCESSENTRY32; /* ../include/tlhelp32.h:73 */

struct tagPROCESSENTRY32W /* ../include/tlhelp32.h:75 */
{
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ProcessID;
    ULONG_PTR th32DefaultHeapID;
    DWORD th32ModuleID;
    DWORD cntThreads;
    DWORD th32ParentProcessID;
    LONG pcPriClassBase;
    DWORD dwFlags;
    WCHAR szExeFile[260];
};


typedef struct tagPROCESSENTRY32W* LPPROCESSENTRY32W; /* ../include/tlhelp32.h:87 */

struct tagMODULEENTRY32 /* ../include/tlhelp32.h:108 */
{
    DWORD dwSize;
    DWORD th32ModuleID;
    DWORD th32ProcessID;
    DWORD GlblcntUsage;
    DWORD ProccntUsage;
    BYTE* modBaseAddr;
    DWORD modBaseSize;
    HMODULE hModule;
    char szModule[256];
    char szExePath[260];
};


typedef struct tagMODULEENTRY32* LPMODULEENTRY32; /* ../include/tlhelp32.h:120 */

struct tagMODULEENTRY32W /* ../include/tlhelp32.h:122 */
{
    DWORD dwSize;
    DWORD th32ModuleID;
    DWORD th32ProcessID;
    DWORD GlblcntUsage;
    DWORD ProccntUsage;
    BYTE* modBaseAddr;
    DWORD modBaseSize;
    HMODULE hModule;
    WCHAR szModule[256];
    WCHAR szExePath[260];
};


typedef struct tagMODULEENTRY32W* LPMODULEENTRY32W; /* ../include/tlhelp32.h:134 */

struct tagHEAPLIST32 /* ../include/tlhelp32.h:149 */
{
    SIZE_T dwSize;
    DWORD th32ProcessID;
    ULONG_PTR th32HeapID;
    DWORD dwFlags;
};


typedef struct tagHEAPLIST32* LPHEAPLIST32; /* ../include/tlhelp32.h:155 */

enum _WER_REGISTER_FILE_TYPE /* ../include/werapi.h:83 */
{
    _WER_REGISTER_FILE_TYPE_DUMMY = 0
};


typedef enum _WER_REGISTER_FILE_TYPE WER_REGISTER_FILE_TYPE; /* ../include/werapi.h:88 */

static void* pAcquireSRWLockExclusive;
static void* pextAcquireSRWLockExclusive;
static void* pAcquireSRWLockShared;
static void* pextAcquireSRWLockShared;
static void* pActivateActCtx;
static void* pextActivateActCtx;
static WINAPI ATOM (*pAddAtomA)(LPCSTR  str);
static WINAPI ATOM (*pAddAtomW)(LPCWSTR  str);
static WINAPI BOOL (*pAddConsoleAliasA)(LPSTR  source, LPSTR  target, LPSTR  exename);
static WINAPI BOOL (*pAddConsoleAliasW)(LPWSTR  source, LPWSTR  target, LPWSTR  exename);
static WINAPI DLL_DIRECTORY_COOKIE (*pAddDllDirectory)(WCHAR*  dir);
static void* pAddRefActCtx;
static void* pextAddRefActCtx;
static void* pAddVectoredContinueHandler;
static void* pextAddVectoredContinueHandler;
static void* pAddVectoredExceptionHandler;
static void* pextAddVectoredExceptionHandler;
static WINAPI BOOL (*pAllocConsole)(void);
static WINAPI BOOL (*pAllocateUserPhysicalPages)(HANDLE  process, ULONG_PTR*  pages, ULONG_PTR*  userarray);
static WINAPI void (*pApplicationRecoveryFinished)(BOOL  success);
static WINAPI HRESULT (*pApplicationRecoveryInProgress)(PBOOL  canceled);
static void* pAreFileApisANSI;
static void* pextAreFileApisANSI;
static WINAPI BOOL (*pAssignProcessToJobObject)(HANDLE  job, HANDLE  process);
static void* pAttachConsole;
static void* pextAttachConsole;
static WINAPI BOOL (*pBackupRead)(HANDLE  file, LPBYTE  buffer, DWORD  to_read, LPDWORD  read, BOOL  abort, BOOL  security, LPVOID*  context);
static WINAPI BOOL (*pBackupSeek)(HANDLE  file, DWORD  seek_low, DWORD  seek_high, LPDWORD  seeked_low, LPDWORD  seeked_high, LPVOID*  context);
static WINAPI BOOL (*pBackupWrite)(HANDLE  file, LPBYTE  buffer, DWORD  to_write, LPDWORD  written, BOOL  abort, BOOL  security, LPVOID*  context);
static WINAPI BOOL (*pBaseFlushAppcompatCache)(void);
static void* pBaseGetNamedObjectDirectory;
static void* pextBaseGetNamedObjectDirectory;
static WINAPI BOOL (*pBeep)(DWORD  dwFreq, DWORD  dwDur);
static WINAPI HANDLE (*pBeginUpdateResourceA)(LPCSTR  pFileName, BOOL  bDeleteExistingResources);
static WINAPI HANDLE (*pBeginUpdateResourceW)(LPCWSTR  pFileName, BOOL  bDeleteExistingResources);
static WINAPI BOOL (*pBindIoCompletionCallback)(HANDLE  FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE  Function, ULONG  Flags);
static WINAPI BOOL (*pBuildCommDCBA)(LPCSTR  device, LPDCB  lpdcb);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsA)(LPCSTR  device, LPDCB  lpdcb, LPCOMMTIMEOUTS  lptimeouts);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsW)(LPCWSTR  devid, LPDCB  lpdcb, LPCOMMTIMEOUTS  lptimeouts);
static WINAPI BOOL (*pBuildCommDCBW)(LPCWSTR  devid, LPDCB  lpdcb);
static void* pCallbackMayRunLong;
static void* pextCallbackMayRunLong;
static WINAPI BOOL (*pCallNamedPipeA)(LPCSTR  lpNamedPipeName, LPVOID  lpInput, DWORD  dwInputSize, LPVOID  lpOutput, DWORD  dwOutputSize, LPDWORD  lpBytesRead, DWORD  nTimeout);
static void* pCallNamedPipeW;
static void* pextCallNamedPipeW;
static void* pCancelIo;
static void* pextCancelIo;
static void* pCancelIoEx;
static void* pextCancelIoEx;
static void* pCancelSynchronousIo;
static void* pextCancelSynchronousIo;
static WINAPI BOOL (*pCancelTimerQueueTimer)(HANDLE  queue, HANDLE  timer);
static void* pCancelWaitableTimer;
static void* pextCancelWaitableTimer;
static void* pChangeTimerQueueTimer;
static void* pextChangeTimerQueueTimer;
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3A)(char*  name, char*  oemname, DWORD  oemname_len, BOOL*  contains_spaces, BOOL*  is_legal);
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3W)(WCHAR*  name, char*  oemname, DWORD  oemname_len, BOOL*  contains_spaces_ret, BOOL*  is_legal);
static void* pCheckRemoteDebuggerPresent;
static void* pextCheckRemoteDebuggerPresent;
static void* pClearCommBreak;
static void* pextClearCommBreak;
static void* pClearCommError;
static void* pextClearCommError;
static WINAPI BOOL (*pCloseConsoleHandle)(HANDLE  handle);
static WINAPI BOOL (*pCloseHandle)(HANDLE  handle);
static WINAPI BOOL (*pCloseProfileUserMapping)(void);
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
static WINAPI BOOL (*pCmdBatNotification)(BOOL  bBatchRunning);
static WINAPI BOOL (*pCommConfigDialogA)(LPCSTR  lpszDevice, HWND  hWnd, LPCOMMCONFIG  lpCommConfig);
static WINAPI BOOL (*pCommConfigDialogW)(LPCWSTR  lpszDevice, HWND  hWnd, LPCOMMCONFIG  lpCommConfig);
static WINAPI INT (*pCompareFileTime)(FILETIME*  x, FILETIME*  y);
static WINAPI INT (*pCompareStringA)(LCID  lcid, DWORD  flags, LPCSTR  str1, INT  len1, LPCSTR  str2, INT  len2);
static WINAPI INT (*pCompareStringW)(LCID  lcid, DWORD  flags, LPCWSTR  str1, INT  len1, LPCWSTR  str2, INT  len2);
static WINAPI INT (*pCompareStringEx)(LPCWSTR  locale, DWORD  flags, LPCWSTR  str1, INT  len1, LPCWSTR  str2, INT  len2, LPNLSVERSIONINFO  version, LPVOID  reserved, LPARAM  lParam);
static WINAPI INT (*pCompareStringOrdinal)(WCHAR*  str1, INT  len1, WCHAR*  str2, INT  len2, BOOL  ignore_case);
static void* pConnectNamedPipe;
static void* pextConnectNamedPipe;
static void* pContinueDebugEvent;
static void* pextContinueDebugEvent;
static WINAPI LCID (*pConvertDefaultLocale)(LCID  lcid);
static void* pConvertFiberToThread;
static void* pextConvertFiberToThread;
static void* pConvertThreadToFiber;
static void* pextConvertThreadToFiber;
static void* pConvertThreadToFiberEx;
static void* pextConvertThreadToFiberEx;
static WINAPI HANDLE (*pConvertToGlobalHandle)(HANDLE  hSrc);
static WINAPI BOOL (*pCopyFileA)(LPCSTR  source, LPCSTR  dest, BOOL  fail_if_exists);
static WINAPI BOOL (*pCopyFileExA)(LPCSTR  sourceFilename, LPCSTR  destFilename, LPPROGRESS_ROUTINE  progressRoutine, LPVOID  appData, LPBOOL  cancelFlagPointer, DWORD  copyFlags);
static WINAPI BOOL (*pCopyFileExW)(LPCWSTR  source, LPCWSTR  dest, LPPROGRESS_ROUTINE  progress, LPVOID  param, LPBOOL  cancel_ptr, DWORD  flags);
static WINAPI BOOL (*pCopyFileW)(LPCWSTR  source, LPCWSTR  dest, BOOL  fail_if_exists);
static WINAPI HANDLE (*pCreateActCtxA)(PCACTCTXA  pActCtx);
static void* pCreateActCtxW;
static void* pextCreateActCtxW;
static void* pCreateConsoleScreenBuffer;
static void* pextCreateConsoleScreenBuffer;
static void* pCreateDirectoryA;
static void* pextCreateDirectoryA;
static WINAPI BOOL (*pCreateDirectoryExA)(LPCSTR  template, LPCSTR  path, LPSECURITY_ATTRIBUTES  sa);
static void* pCreateDirectoryExW;
static void* pextCreateDirectoryExW;
static void* pCreateDirectoryW;
static void* pextCreateDirectoryW;
static void* pCreateEventA;
static void* pextCreateEventA;
static void* pCreateEventExA;
static void* pextCreateEventExA;
static void* pCreateEventExW;
static void* pextCreateEventExW;
static void* pCreateEventW;
static void* pextCreateEventW;
static void* pCreateFiber;
static void* pextCreateFiber;
static void* pCreateFiberEx;
static void* pextCreateFiberEx;
static void* pCreateFile2;
static void* pextCreateFile2;
static void* pCreateFileA;
static void* pextCreateFileA;
static WINAPI HANDLE (*pCreateFileMappingA)(HANDLE  file, SECURITY_ATTRIBUTES*  sa, DWORD  protect, DWORD  size_high, DWORD  size_low, LPCSTR  name);
static void* pCreateFileMappingW;
static void* pextCreateFileMappingW;
static void* pCreateFileW;
static void* pextCreateFileW;
static WINAPI BOOL (*pCreateHardLinkA)(LPCSTR  lpFileName, LPCSTR  lpExistingFileName, LPSECURITY_ATTRIBUTES  lpSecurityAttributes);
static WINAPI BOOL (*pCreateHardLinkTransactedA)(LPCSTR  link, LPCSTR  target, LPSECURITY_ATTRIBUTES  sa, HANDLE  transaction);
static WINAPI BOOL (*pCreateHardLinkTransactedW)(LPCWSTR  link, LPCWSTR  target, LPSECURITY_ATTRIBUTES  sa, HANDLE  transaction);
static WINAPI BOOL (*pCreateHardLinkW)(LPCWSTR  lpFileName, LPCWSTR  lpExistingFileName, LPSECURITY_ATTRIBUTES  lpSecurityAttributes);
static void* pCreateIoCompletionPort;
static void* pextCreateIoCompletionPort;
static WINAPI HANDLE (*pCreateJobObjectA)(LPSECURITY_ATTRIBUTES  attr, LPCSTR  name);
static WINAPI HANDLE (*pCreateJobObjectW)(LPSECURITY_ATTRIBUTES  sa, LPCWSTR  name);
static WINAPI HANDLE (*pCreateMailslotA)(LPCSTR  lpName, DWORD  nMaxMessageSize, DWORD  lReadTimeout, LPSECURITY_ATTRIBUTES  sa);
static WINAPI HANDLE (*pCreateMailslotW)(LPCWSTR  lpName, DWORD  nMaxMessageSize, DWORD  lReadTimeout, LPSECURITY_ATTRIBUTES  sa);
static void* pCreateMemoryResourceNotification;
static void* pextCreateMemoryResourceNotification;
static void* pCreateMutexA;
static void* pextCreateMutexA;
static void* pCreateMutexExA;
static void* pextCreateMutexExA;
static void* pCreateMutexExW;
static void* pextCreateMutexExW;
static void* pCreateMutexW;
static void* pextCreateMutexW;
static WINAPI HANDLE (*pCreateNamedPipeA)(LPCSTR  name, DWORD  dwOpenMode, DWORD  dwPipeMode, DWORD  nMaxInstances, DWORD  nOutBufferSize, DWORD  nInBufferSize, DWORD  nDefaultTimeOut, LPSECURITY_ATTRIBUTES  attr);
static void* pCreateNamedPipeW;
static void* pextCreateNamedPipeW;
static WINAPI BOOL (*pCreatePipe)(PHANDLE  hReadPipe, PHANDLE  hWritePipe, LPSECURITY_ATTRIBUTES  sa, DWORD  size);
static WINAPI BOOL (*pCreateProcessA)(LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info);
static WINAPI BOOL (*pCreateProcessAsUserA)(HANDLE  token, LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info);
static WINAPI BOOL (*pCreateProcessAsUserW)(HANDLE  token, LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info);
static WINAPI BOOL (*pCreateProcessInternalA)(HANDLE  token, LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info, HANDLE*  new_token);
static WINAPI BOOL (*pCreateProcessInternalW)(HANDLE  token, LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info, HANDLE*  new_token);
static WINAPI BOOL (*pCreateProcessW)(LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info);
static void* pCreateRemoteThread;
static void* pextCreateRemoteThread;
static void* pCreateRemoteThreadEx;
static void* pextCreateRemoteThreadEx;
static WINAPI HANDLE (*pCreateSemaphoreA)(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCSTR  name);
static WINAPI HANDLE (*pCreateSemaphoreExA)(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCSTR  name, DWORD  flags, DWORD  access);
static void* pCreateSemaphoreExW;
static void* pextCreateSemaphoreExW;
static void* pCreateSemaphoreW;
static void* pextCreateSemaphoreW;
static WINAPI HANDLE (*pCreateSocketHandle)(void);
static WINAPI BOOLEAN (*pCreateSymbolicLinkA)(LPCSTR  link, LPCSTR  target, DWORD  flags);
static WINAPI BOOLEAN (*pCreateSymbolicLinkW)(LPCWSTR  link, LPCWSTR  target, DWORD  flags);
static WINAPI DWORD (*pCreateTapePartition)(HANDLE  device, DWORD  method, DWORD  count, DWORD  size);
static void* pCreateThread;
static void* pextCreateThread;
static void* pCreateThreadpool;
static void* pextCreateThreadpool;
static void* pCreateThreadpoolCleanupGroup;
static void* pextCreateThreadpoolCleanupGroup;
static void* pCreateThreadpoolIo;
static void* pextCreateThreadpoolIo;
static void* pCreateThreadpoolTimer;
static void* pextCreateThreadpoolTimer;
static void* pCreateThreadpoolWait;
static void* pextCreateThreadpoolWait;
static void* pCreateThreadpoolWork;
static void* pextCreateThreadpoolWork;
static void* pCreateTimerQueue;
static void* pextCreateTimerQueue;
static void* pCreateTimerQueueTimer;
static void* pextCreateTimerQueueTimer;
static WINAPI HANDLE (*pCreateToolhelp32Snapshot)(DWORD  flags, DWORD  process);
static WINAPI BOOL (*pCreateUmsCompletionList)(PUMS_COMPLETION_LIST*  list);
static WINAPI BOOL (*pCreateUmsThreadContext)(PUMS_CONTEXT*  ctx);
static WINAPI HANDLE (*pCreateWaitableTimerA)(SECURITY_ATTRIBUTES*  sa, BOOL  manual, LPCSTR  name);
static WINAPI HANDLE (*pCreateWaitableTimerExA)(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access);
static void* pCreateWaitableTimerExW;
static void* pextCreateWaitableTimerExW;
static void* pCreateWaitableTimerW;
static void* pextCreateWaitableTimerW;
static void* pDeactivateActCtx;
static void* pextDeactivateActCtx;
static void* pDebugActiveProcess;
static void* pextDebugActiveProcess;
static void* pDebugActiveProcessStop;
static void* pextDebugActiveProcessStop;
static WINAPI BOOL (*pDebugBreakProcess)(HANDLE  process);
static WINAPI BOOL (*pDebugSetProcessKillOnExit)(BOOL  kill);
static void* pDecodePointer;
static void* pextDecodePointer;
static void* pDecodeSystemPointer;
static void* pextDecodeSystemPointer;
static WINAPI BOOL (*pDefineDosDeviceA)(DWORD  flags, LPCSTR  devname, LPCSTR  targetpath);
static WINAPI BOOL (*pDefineDosDeviceW)(DWORD  flags, LPCWSTR  devname, LPCWSTR  targetpath);
static WINAPI FARPROC (*pDelayLoadFailureHook)(LPCSTR  name, LPCSTR  function);
static WINAPI ATOM (*pDeleteAtom)(ATOM  atom);
static void* pDeleteCriticalSection;
static void* pextDeleteCriticalSection;
static void* pDeleteFiber;
static void* pextDeleteFiber;
static void* pDeleteFileA;
static void* pextDeleteFileA;
static void* pDeleteFileW;
static void* pextDeleteFileW;
static void* pDeleteProcThreadAttributeList;
static void* pextDeleteProcThreadAttributeList;
static void* pDisassociateCurrentThreadFromCallback;
static void* pextDisassociateCurrentThreadFromCallback;
static WINAPI BOOL (*pDeleteTimerQueue)(HANDLE  TimerQueue);
static void* pDeleteTimerQueueEx;
static void* pextDeleteTimerQueueEx;
static void* pDeleteTimerQueueTimer;
static void* pextDeleteTimerQueueTimer;
static WINAPI BOOL (*pDeleteUmsCompletionList)(PUMS_COMPLETION_LIST  list);
static WINAPI BOOL (*pDeleteUmsThreadContext)(PUMS_CONTEXT  ctx);
static WINAPI BOOL (*pDeleteVolumeMountPointA)(LPCSTR  mountpoint);
static WINAPI BOOL (*pDeleteVolumeMountPointW)(LPCWSTR  mountpoint);
static WINAPI BOOL (*pDequeueUmsCompletionListItems)(void*  list, DWORD  timeout, PUMS_CONTEXT*  ctx);
static WINAPI BOOL (*pDeviceIoControl)(HANDLE  hDevice, DWORD  dwIoControlCode, LPVOID  lpvInBuffer, DWORD  cbInBuffer, LPVOID  lpvOutBuffer, DWORD  cbOutBuffer, LPDWORD  lpcbBytesReturned, LPOVERLAPPED  lpOverlapped);
static void* pDisableThreadLibraryCalls;
static void* pextDisableThreadLibraryCalls;
static void* pDisconnectNamedPipe;
static void* pextDisconnectNamedPipe;
static WINAPI BOOL (*pDnsHostnameToComputerNameA)(LPCSTR  hostname, LPSTR  computername, LPDWORD  size);
static WINAPI BOOL (*pDnsHostnameToComputerNameW)(LPCWSTR  hostname, LPWSTR  computername, LPDWORD  size);
static WINAPI BOOL (*pDosDateTimeToFileTime)(WORD  fatdate, WORD  fattime, LPFILETIME  ft);
static WINAPI HANDLE (*pDuplicateConsoleHandle)(HANDLE  handle, DWORD  access, BOOL  inherit, DWORD  options);
static WINAPI BOOL (*pDuplicateHandle)(HANDLE  source_process, HANDLE  source, HANDLE  dest_process, HANDLE*  dest, DWORD  access, BOOL  inherit, DWORD  options);
static void* pEncodePointer;
static void* pextEncodePointer;
static void* pEncodeSystemPointer;
static void* pextEncodeSystemPointer;
static WINAPI BOOL (*pEndUpdateResourceA)(HANDLE  hUpdate, BOOL  fDiscard);
static WINAPI BOOL (*pEndUpdateResourceW)(HANDLE  hUpdate, BOOL  fDiscard);
static void* pEnterCriticalSection;
static void* pextEnterCriticalSection;
static WINAPI BOOL (*pEnumCalendarInfoA)(CALINFO_ENUMPROCA  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype);
static WINAPI BOOL (*pEnumCalendarInfoExA)(CALINFO_ENUMPROCEXA  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype);
static WINAPI BOOL (*pEnumCalendarInfoExEx)(CALINFO_ENUMPROCEXEX  calinfoproc, LPCWSTR  locale, CALID  calendar, LPCWSTR  reserved, CALTYPE  caltype, LPARAM  lParam);
static WINAPI BOOL (*pEnumCalendarInfoExW)(CALINFO_ENUMPROCEXW  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype);
static WINAPI BOOL (*pEnumCalendarInfoW)(CALINFO_ENUMPROCW  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype);
static WINAPI BOOL (*pEnumDateFormatsA)(DATEFMT_ENUMPROCA  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumDateFormatsExA)(DATEFMT_ENUMPROCEXA  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumDateFormatsExEx)(DATEFMT_ENUMPROCEXEX  proc, WCHAR*  locale, DWORD  flags, LPARAM  lParam);
static WINAPI BOOL (*pEnumDateFormatsExW)(DATEFMT_ENUMPROCEXW  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumDateFormatsW)(DATEFMT_ENUMPROCW  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumLanguageGroupLocalesA)(LANGGROUPLOCALE_ENUMPROCA  pLangGrpLcEnumProc, LGRPID  lgrpid, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnumLanguageGroupLocalesW)(LANGGROUPLOCALE_ENUMPROCW  pLangGrpLcEnumProc, LGRPID  lgrpid, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnumResourceLanguagesA)(HMODULE  hmod, LPCSTR  type, LPCSTR  name, ENUMRESLANGPROCA  lpfun, LONG_PTR  lparam);
static void* pEnumResourceLanguagesExA;
static void* pextEnumResourceLanguagesExA;
static void* pEnumResourceLanguagesExW;
static void* pextEnumResourceLanguagesExW;
static WINAPI BOOL (*pEnumResourceLanguagesW)(HMODULE  hmod, LPCWSTR  type, LPCWSTR  name, ENUMRESLANGPROCW  lpfun, LONG_PTR  lparam);
static WINAPI BOOL (*pEnumResourceNamesA)(HMODULE  hmod, LPCSTR  type, ENUMRESNAMEPROCA  lpfun, LONG_PTR  lparam);
static void* pEnumResourceNamesExA;
static void* pextEnumResourceNamesExA;
static void* pEnumResourceNamesExW;
static void* pextEnumResourceNamesExW;
static void* pEnumResourceNamesW;
static void* pextEnumResourceNamesW;
static WINAPI BOOL (*pEnumResourceTypesA)(HMODULE  hmod, ENUMRESTYPEPROCA  lpfun, LONG_PTR  lparam);
static void* pEnumResourceTypesExA;
static void* pextEnumResourceTypesExA;
static void* pEnumResourceTypesExW;
static void* pextEnumResourceTypesExW;
static WINAPI BOOL (*pEnumResourceTypesW)(HMODULE  hmod, ENUMRESTYPEPROCW  lpfun, LONG_PTR  lparam);
static WINAPI BOOL (*pEnumSystemCodePagesA)(CODEPAGE_ENUMPROCA  lpfnCodePageEnum, DWORD  flags);
static WINAPI BOOL (*pEnumSystemCodePagesW)(CODEPAGE_ENUMPROCW  lpfnCodePageEnum, DWORD  flags);
static WINAPI UINT (*pEnumSystemFirmwareTables)(DWORD  provider, void*  buffer, DWORD  size);
static WINAPI BOOL (*pEnumSystemGeoID)(GEOCLASS  geoclass, GEOID  parent, GEO_ENUMPROC  enumproc);
static WINAPI BOOL (*pEnumSystemLanguageGroupsA)(LANGUAGEGROUP_ENUMPROCA  pLangGrpEnumProc, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnumSystemLanguageGroupsW)(LANGUAGEGROUP_ENUMPROCW  pLangGrpEnumProc, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnumSystemLocalesA)(LOCALE_ENUMPROCA  lpfnLocaleEnum, DWORD  dwFlags);
static WINAPI BOOL (*pEnumSystemLocalesEx)(LOCALE_ENUMPROCEX  proc, DWORD  flags, LPARAM  lparam, LPVOID  reserved);
static WINAPI BOOL (*pEnumSystemLocalesW)(LOCALE_ENUMPROCW  lpfnLocaleEnum, DWORD  dwFlags);
static WINAPI BOOL (*pEnumTimeFormatsA)(TIMEFMT_ENUMPROCA  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumTimeFormatsEx)(TIMEFMT_ENUMPROCEX  proc, WCHAR*  locale, DWORD  flags, LPARAM  lParam);
static WINAPI BOOL (*pEnumTimeFormatsW)(TIMEFMT_ENUMPROCW  proc, LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pEnumUILanguagesA)(UILANGUAGE_ENUMPROCA  pUILangEnumProc, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnumUILanguagesW)(UILANGUAGE_ENUMPROCW  pUILangEnumProc, DWORD  dwFlags, LONG_PTR  lParam);
static WINAPI BOOL (*pEnterUmsSchedulingMode)(UMS_SCHEDULER_STARTUP_INFO*  info);
static WINAPI DWORD (*pEraseTape)(HANDLE  device, DWORD  type, BOOL  immediate);
static void* pEscapeCommFunction;
static void* pextEscapeCommFunction;
static WINAPI BOOL (*pExecuteUmsThread)(PUMS_CONTEXT  ctx);
static WINAPI void (*pExitProcess)(DWORD  status);
static void* pExitThread;
static void* pextExitThread;
static void* pExpandEnvironmentStringsA;
static void* pextExpandEnvironmentStringsA;
static void* pExpandEnvironmentStringsW;
static void* pextExpandEnvironmentStringsW;
static WINAPI void (*pExpungeConsoleCommandHistoryA)(LPCSTR  unknown);
static WINAPI void (*pExpungeConsoleCommandHistoryW)(LPCWSTR  unknown);
static void* pFatalAppExitA;
static void* pextFatalAppExitA;
static void* pFatalAppExitW;
static void* pextFatalAppExitW;
static WINAPI void (*pFatalExit)(int  code);
static WINAPI BOOL (*pFileTimeToDosDateTime)(FILETIME*  ft, LPWORD  fatdate, LPWORD  fattime);
static WINAPI BOOL (*pFileTimeToLocalFileTime)(FILETIME*  utcft, LPFILETIME  localft);
static WINAPI BOOL (*pFileTimeToSystemTime)(FILETIME*  ft, LPSYSTEMTIME  syst);
static void* pFillConsoleOutputAttribute;
static void* pextFillConsoleOutputAttribute;
static void* pFillConsoleOutputCharacterA;
static void* pextFillConsoleOutputCharacterA;
static void* pFillConsoleOutputCharacterW;
static void* pextFillConsoleOutputCharacterW;
static void* pFindActCtxSectionGuid;
static void* pextFindActCtxSectionGuid;
static WINAPI BOOL (*pFindActCtxSectionStringA)(DWORD  dwFlags, GUID*  lpExtGuid, ULONG  ulId, LPCSTR  lpSearchStr, PACTCTX_SECTION_KEYED_DATA  pInfo);
static void* pFindActCtxSectionStringW;
static void* pextFindActCtxSectionStringW;
static WINAPI ATOM (*pFindAtomA)(LPCSTR  str);
static WINAPI ATOM (*pFindAtomW)(LPCWSTR  str);
static WINAPI BOOL (*pFindClose)(HANDLE  handle);
static void* pFindCloseChangeNotification;
static void* pextFindCloseChangeNotification;
static void* pFindFirstChangeNotificationA;
static void* pextFindFirstChangeNotificationA;
static void* pFindFirstChangeNotificationW;
static void* pextFindFirstChangeNotificationW;
static WINAPI HANDLE (*pFindFirstFileA)(LPCSTR  lpFileName, WIN32_FIND_DATAA*  lpFindData);
static WINAPI HANDLE (*pFindFirstFileExA)(LPCSTR  lpFileName, FINDEX_INFO_LEVELS  fInfoLevelId, LPVOID  lpFindFileData, FINDEX_SEARCH_OPS  fSearchOp, LPVOID  lpSearchFilter, DWORD  dwAdditionalFlags);
static WINAPI HANDLE (*pFindFirstFileExW)(LPCWSTR  filename, FINDEX_INFO_LEVELS  level, LPVOID  data, FINDEX_SEARCH_OPS  search_op, LPVOID  filter, DWORD  flags);
static WINAPI HANDLE (*pFindFirstFileW)(LPCWSTR  lpFileName, WIN32_FIND_DATAW*  lpFindData);
static WINAPI HANDLE (*pFindFirstStreamW)(LPCWSTR  filename, STREAM_INFO_LEVELS  infolevel, void*  data, DWORD  flags);
static WINAPI HANDLE (*pFindFirstVolumeA)(LPSTR  volume, DWORD  len);
static WINAPI HANDLE (*pFindFirstVolumeMountPointA)(LPCSTR  root, LPSTR  mount_point, DWORD  len);
static WINAPI HANDLE (*pFindFirstVolumeMountPointW)(LPCWSTR  root, LPWSTR  mount_point, DWORD  len);
static WINAPI HANDLE (*pFindFirstVolumeW)(LPWSTR  volume, DWORD  len);
static void* pFindNextChangeNotification;
static void* pextFindNextChangeNotification;
static WINAPI BOOL (*pFindNextFileA)(HANDLE  handle, WIN32_FIND_DATAA*  data);
static WINAPI BOOL (*pFindNextFileW)(HANDLE  handle, WIN32_FIND_DATAW*  data);
static WINAPI BOOL (*pFindNextStreamW)(HANDLE  handle, void*  data);
static WINAPI BOOL (*pFindNextVolumeA)(HANDLE  handle, LPSTR  volume, DWORD  len);
static WINAPI BOOL (*pFindNextVolumeW)(HANDLE  handle, LPWSTR  volume, DWORD  len);
static WINAPI INT (*pFindNLSStringEx)(WCHAR*  localename, DWORD  flags, WCHAR*  src, INT  src_size, WCHAR*  value, INT  value_size, INT*  found, NLSVERSIONINFO*  version_info, void*  reserved, LPARAM  sort_handle);
static WINAPI HRSRC (*pFindResourceA)(HMODULE  hModule, LPCSTR  name, LPCSTR  type);
static WINAPI HRSRC (*pFindResourceExA)(HMODULE  module, LPCSTR  type, LPCSTR  name, WORD  lang);
static void* pFindResourceExW;
static void* pextFindResourceExW;
static void* pFindResourceW;
static void* pextFindResourceW;
static WINAPI INT (*pFindStringOrdinal)(DWORD  flag, WCHAR*  src, INT  src_size, WCHAR*  val, INT  val_size, BOOL  ignore_case);
static WINAPI BOOL (*pFindVolumeClose)(HANDLE  handle);
static WINAPI BOOL (*pFindVolumeMountPointClose)(HANDLE  h);
static void* pFlsAlloc;
static void* pextFlsAlloc;
static void* pFlsFree;
static void* pextFlsFree;
static void* pFlsGetValue;
static void* pextFlsGetValue;
static void* pFlsSetValue;
static void* pextFlsSetValue;
static WINAPI BOOL (*pFlushConsoleInputBuffer)(HANDLE  handle);
static void* pFlushFileBuffers;
static void* pextFlushFileBuffers;
static void* pFlushInstructionCache;
static void* pextFlushInstructionCache;
static WINAPI void (*pFlushProcessWriteBuffers)(void);
static void* pFlushViewOfFile;
static void* pextFlushViewOfFile;
static WINAPI INT (*pFoldStringA)(DWORD  dwFlags, LPCSTR  src, INT  srclen, LPSTR  dst, INT  dstlen);
static WINAPI INT (*pFoldStringW)(DWORD  dwFlags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen);
static WINAPI DWORD (*pFormatMessageA)(DWORD  dwFlags, LPCVOID  lpSource, DWORD  dwMessageId, DWORD  dwLanguageId, LPSTR  lpBuffer, DWORD  nSize, __builtin_ms_va_list*  args);
static WINAPI DWORD (*pFormatMessageW)(DWORD  dwFlags, LPCVOID  lpSource, DWORD  dwMessageId, DWORD  dwLanguageId, LPWSTR  lpBuffer, DWORD  nSize, __builtin_ms_va_list*  args);
static WINAPI BOOL (*pFreeConsole)(void);
static void* pFreeEnvironmentStringsA;
static void* pextFreeEnvironmentStringsA;
static void* pFreeEnvironmentStringsW;
static void* pextFreeEnvironmentStringsW;
static WINAPI BOOL (*pFreeLibrary)(HINSTANCE  hLibModule);
static WINAPI void (*pFreeLibraryAndExitThread)(HINSTANCE  hLibModule, DWORD  dwExitCode);
static void* pFreeLibraryWhenCallbackReturns;
static void* pextFreeLibraryWhenCallbackReturns;
static void* pFreeResource;
static void* pextFreeResource;
static WINAPI BOOL (*pFreeUserPhysicalPages)(HANDLE  process, ULONG_PTR*  pages, ULONG_PTR*  userarray);
static void* pGenerateConsoleCtrlEvent;
static void* pextGenerateConsoleCtrlEvent;
static WINAPI UINT (*pGetACP)(void);
static WINAPI DWORD (*pGetActiveProcessorCount)(WORD  group);
static WINAPI WORD (*pGetActiveProcessorGroupCount)(void);
static WINAPI HRESULT (*pGetApplicationRestartSettings)(HANDLE  process, WCHAR*  cmdline, DWORD*  size, DWORD*  flags);
static WINAPI UINT (*pGetAtomNameA)(ATOM  atom, LPSTR  buffer, INT  count);
static WINAPI UINT (*pGetAtomNameW)(ATOM  atom, LPWSTR  buffer, INT  count);
static WINAPI BOOL (*pGetBinaryTypeA)(LPCSTR  lpApplicationName, LPDWORD  lpBinaryType);
static WINAPI BOOL (*pGetBinaryTypeW)(LPCWSTR  name, LPDWORD  type);
static WINAPI BOOL (*pGetCPInfo)(UINT  codepage, LPCPINFO  cpinfo);
static WINAPI BOOL (*pGetCPInfoExA)(UINT  codepage, DWORD  dwFlags, LPCPINFOEXA  cpinfo);
static WINAPI BOOL (*pGetCPInfoExW)(UINT  codepage, DWORD  dwFlags, LPCPINFOEXW  cpinfo);
static WINAPI INT (*pGetCalendarInfoA)(LCID  lcid, CALID  Calendar, CALTYPE  CalType, LPSTR  lpCalData, int  cchData, LPDWORD  lpValue);
static WINAPI INT (*pGetCalendarInfoW)(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPWSTR  lpCalData, int  cchData, LPDWORD  lpValue);
static WINAPI int (*pGetCalendarInfoEx)(LPCWSTR  locale, CALID  calendar, LPCWSTR  lpReserved, CALTYPE  caltype, LPWSTR  data, int  len, DWORD*  value);
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
static void* pGetCompressedFileSizeA;
static void* pextGetCompressedFileSizeA;
static void* pGetCompressedFileSizeW;
static void* pextGetCompressedFileSizeW;
static WINAPI BOOL (*pGetComputerNameA)(LPSTR  name, LPDWORD  size);
static WINAPI BOOL (*pGetComputerNameExA)(COMPUTER_NAME_FORMAT  type, LPSTR  name, LPDWORD  size);
static WINAPI BOOL (*pGetComputerNameExW)(COMPUTER_NAME_FORMAT  type, LPWSTR  name, LPDWORD  size);
static WINAPI BOOL (*pGetComputerNameW)(LPWSTR  name, LPDWORD  size);
static WINAPI DWORD (*pGetConsoleAliasExesLengthA)(void);
static WINAPI DWORD (*pGetConsoleAliasExesLengthW)(void);
static WINAPI DWORD (*pGetConsoleAliasW)(LPWSTR  lpSource, LPWSTR  lpTargetBuffer, DWORD  TargetBufferLength, LPWSTR  lpExename);
static WINAPI DWORD (*pGetConsoleAliasesLengthA)(LPSTR  unknown);
static WINAPI DWORD (*pGetConsoleAliasesLengthW)(LPWSTR  unknown);
static void* pGetConsoleCP;
static void* pextGetConsoleCP;
static WINAPI DWORD (*pGetConsoleCommandHistoryA)(DWORD  unknown1, DWORD  unknown2, DWORD  unknown3);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthA)(LPCSTR  unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthW)(LPCWSTR  unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryW)(DWORD  unknown1, DWORD  unknown2, DWORD  unknown3);
static void* pGetConsoleCursorInfo;
static void* pextGetConsoleCursorInfo;
static WINAPI BOOL (*pGetConsoleDisplayMode)(LPDWORD  lpModeFlags);
static WINAPI BOOL (*pGetConsoleFontInfo)(HANDLE  hConsole, BOOL  maximize, DWORD  numfonts, CONSOLE_FONT_INFO*  info);
static WINAPI COORD (*pGetConsoleFontSize)(HANDLE  hConsole, DWORD  index);
static void* pGetConsoleInputExeNameA;
static void* pextGetConsoleInputExeNameA;
static void* pGetConsoleInputExeNameW;
static void* pextGetConsoleInputExeNameW;
static WINAPI HANDLE (*pGetConsoleInputWaitHandle)(void);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameA)(LPSTR  layoutName);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameW)(LPWSTR  layoutName);
static void* pGetConsoleMode;
static void* pextGetConsoleMode;
static void* pGetConsoleOutputCP;
static void* pextGetConsoleOutputCP;
static WINAPI DWORD (*pGetConsoleProcessList)(LPDWORD  processlist, DWORD  processcount);
static void* pGetConsoleScreenBufferInfo;
static void* pextGetConsoleScreenBufferInfo;
static void* pGetConsoleScreenBufferInfoEx;
static void* pextGetConsoleScreenBufferInfoEx;
static WINAPI DWORD (*pGetConsoleTitleA)(LPSTR  title, DWORD  size);
static void* pGetConsoleTitleW;
static void* pextGetConsoleTitleW;
static WINAPI HWND (*pGetConsoleWindow)(void);
static WINAPI INT (*pGetCurrencyFormatA)(LCID  lcid, DWORD  dwFlags, LPCSTR  lpszValue, CURRENCYFMTA*  lpFormat, LPSTR  lpCurrencyStr, int  cchOut);
static WINAPI INT (*pGetCurrencyFormatEx)(LPCWSTR  localename, DWORD  flags, LPCWSTR  value, CURRENCYFMTW*  format, LPWSTR  str, int  len);
static WINAPI INT (*pGetCurrencyFormatW)(LCID  lcid, DWORD  dwFlags, LPCWSTR  lpszValue, CURRENCYFMTW*  lpFormat, LPWSTR  lpCurrencyStr, int  cchOut);
static void* pGetCurrentActCtx;
static void* pextGetCurrentActCtx;
static WINAPI BOOL (*pGetCurrentConsoleFont)(HANDLE  hConsole, BOOL  maxwindow, LPCONSOLE_FONT_INFO  fontinfo);
static WINAPI UINT (*pGetCurrentDirectoryA)(UINT  buflen, LPSTR  buf);
static WINAPI UINT (*pGetCurrentDirectoryW)(UINT  buflen, LPWSTR  buf);
static WINAPI LONG (*pGetCurrentPackageFamilyName)(UINT32*  length, PWSTR  name);
static WINAPI LONG (*pGetCurrentPackageFullName)(UINT32*  length, PWSTR  name);
static WINAPI LONG (*pGetCurrentPackageId)(UINT32*  len, BYTE*  buffer);
static WINAPI HANDLE (*pGetCurrentProcess)(void);
static WINAPI DWORD (*pGetCurrentProcessId)(void);
static void* pGetCurrentProcessorNumber;
static void* pextGetCurrentProcessorNumber;
static void* pGetCurrentProcessorNumberEx;
static void* pextGetCurrentProcessorNumberEx;
static WINAPI HANDLE (*pGetCurrentThread)(void);
static WINAPI DWORD (*pGetCurrentThreadId)(void);
static void* pGetCurrentThreadStackLimits;
static void* pextGetCurrentThreadStackLimits;
static WINAPI PUMS_CONTEXT (*pGetCurrentUmsThread)(void);
static WINAPI INT (*pGetDateFormatA)(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCSTR  lpFormat, LPSTR  lpDateStr, INT  cchOut);
static WINAPI INT (*pGetDateFormatEx)(LPCWSTR  localename, DWORD  flags, SYSTEMTIME*  date, LPCWSTR  format, LPWSTR  outbuf, INT  bufsize, LPCWSTR  calendar);
static WINAPI INT (*pGetDateFormatW)(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCWSTR  lpFormat, LPWSTR  lpDateStr, INT  cchOut);
static WINAPI BOOL (*pGetDaylightFlag)(void);
static WINAPI BOOL (*pGetDefaultCommConfigA)(LPCSTR  lpszName, LPCOMMCONFIG  lpCC, LPDWORD  lpdwSize);
static WINAPI BOOL (*pGetDefaultCommConfigW)(LPCWSTR  lpszName, LPCOMMCONFIG  lpCC, LPDWORD  lpdwSize);
static WINAPI BOOL (*pGetDevicePowerState)(HANDLE  hDevice, BOOL*  pfOn);
static WINAPI BOOL (*pGetDiskFreeSpaceA)(LPCSTR  root, LPDWORD  cluster_sectors, LPDWORD  sector_bytes, LPDWORD  free_clusters, LPDWORD  total_clusters);
static WINAPI BOOL (*pGetDiskFreeSpaceExA)(LPCSTR  root, PULARGE_INTEGER  avail, PULARGE_INTEGER  total, PULARGE_INTEGER  totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceExW)(LPCWSTR  root, PULARGE_INTEGER  avail, PULARGE_INTEGER  total, PULARGE_INTEGER  totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceW)(LPCWSTR  root, LPDWORD  cluster_sectors, LPDWORD  sector_bytes, LPDWORD  free_clusters, LPDWORD  total_clusters);
static WINAPI DWORD (*pGetDllDirectoryA)(DWORD  buf_len, LPSTR  buffer);
static WINAPI DWORD (*pGetDllDirectoryW)(DWORD  buf_len, LPWSTR  buffer);
static WINAPI UINT (*pGetDriveTypeA)(LPCSTR  root);
static WINAPI UINT (*pGetDriveTypeW)(LPCWSTR  root);
static WINAPI DWORD (*pGetDynamicTimeZoneInformation)(DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo);
static WINAPI DWORD (*pGetDynamicTimeZoneInformationEffectiveYears)(DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo, DWORD*  first_year, DWORD*  last_year);
static WINAPI DWORD64 (*pGetEnabledXStateFeatures)(void);
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
static void* pGetErrorMode;
static void* pextGetErrorMode;
static WINAPI BOOL (*pGetExitCodeProcess)(HANDLE  hProcess, LPDWORD  lpExitCode);
static void* pGetExitCodeThread;
static void* pextGetExitCodeThread;
static WINAPI INT (*pGetExpandedNameA)(LPSTR  in, LPSTR  out);
static WINAPI INT (*pGetExpandedNameW)(LPWSTR  in, LPWSTR  out);
static void* pGetFileAttributesA;
static void* pextGetFileAttributesA;
static void* pGetFileAttributesExA;
static void* pextGetFileAttributesExA;
static void* pGetFileAttributesExW;
static void* pextGetFileAttributesExW;
static void* pGetFileAttributesW;
static void* pextGetFileAttributesW;
static void* pGetFileInformationByHandle;
static void* pextGetFileInformationByHandle;
static void* pGetFileInformationByHandleEx;
static void* pextGetFileInformationByHandleEx;
static WINAPI BOOL (*pGetFileMUIInfo)(DWORD  flags, PCWSTR  path, FILEMUIINFO*  info, DWORD*  size);
static WINAPI BOOL (*pGetFileMUIPath)(DWORD  flags, PCWSTR  filepath, PWSTR  language, PULONG  languagelen, PWSTR  muipath, PULONG  muipathlen, PULONGLONG  enumerator);
static void* pGetFileSize;
static void* pextGetFileSize;
static void* pGetFileSizeEx;
static void* pextGetFileSizeEx;
static void* pGetFileTime;
static void* pextGetFileTime;
static void* pGetFileType;
static void* pextGetFileType;
static WINAPI DWORD (*pGetFinalPathNameByHandleA)(HANDLE  file, LPSTR  path, DWORD  charcount, DWORD  flags);
static WINAPI DWORD (*pGetFinalPathNameByHandleW)(HANDLE  file, LPWSTR  path, DWORD  charcount, DWORD  flags);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableA)(LPCSTR  name, LPCSTR  guid, PVOID  buffer, DWORD  size);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableW)(LPCWSTR  name, LPCWSTR  guid, PVOID  buffer, DWORD  size);
static WINAPI DWORD (*pGetFullPathNameA)(LPCSTR  name, DWORD  len, LPSTR  buffer, LPSTR*  lastpart);
static WINAPI DWORD (*pGetFullPathNameW)(LPCWSTR  name, DWORD  len, LPWSTR  buffer, LPWSTR*  lastpart);
static WINAPI INT (*pGetGeoInfoA)(GEOID  geoid, GEOTYPE  geotype, LPSTR  data, int  data_len, LANGID  lang);
static WINAPI INT (*pGetGeoInfoW)(GEOID  geoid, GEOTYPE  geotype, LPWSTR  data, int  data_len, LANGID  lang);
static WINAPI DWORD (*pGetHandleContext)(HANDLE  hnd);
static WINAPI BOOL (*pGetHandleInformation)(HANDLE  handle, LPDWORD  flags);
static WINAPI SIZE_T (*pGetLargePageMinimum)(void);
static void* pGetLargestConsoleWindowSize;
static void* pextGetLargestConsoleWindowSize;
static void* pGetLastError;
static void* pextGetLastError;
static WINAPI void (*pGetLocalTime)(LPSYSTEMTIME  systime);
static WINAPI INT (*pGetLocaleInfoA)(LCID  lcid, LCTYPE  lctype, LPSTR  buffer, INT  len);
static WINAPI INT (*pGetLocaleInfoW)(LCID  lcid, LCTYPE  lctype, LPWSTR  buffer, INT  len);
static WINAPI INT (*pGetLocaleInfoEx)(LPCWSTR  locale, LCTYPE  info, LPWSTR  buffer, INT  len);
static WINAPI UINT (*pGetLogicalDriveStringsA)(UINT  len, LPSTR  buffer);
static WINAPI UINT (*pGetLogicalDriveStringsW)(UINT  len, LPWSTR  buffer);
static WINAPI DWORD (*pGetLogicalDrives)(void);
static WINAPI BOOL (*pGetLogicalProcessorInformation)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION  buffer, PDWORD  pBufLen);
static WINAPI BOOL (*pGetLogicalProcessorInformationEx)(LOGICAL_PROCESSOR_RELATIONSHIP  relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX*  buffer, DWORD*  len);
static WINAPI DWORD (*pGetLongPathNameA)(LPCSTR  shortpath, LPSTR  longpath, DWORD  longlen);
static WINAPI DWORD (*pGetLongPathNameW)(LPCWSTR  shortpath, LPWSTR  longpath, DWORD  longlen);
static WINAPI BOOL (*pGetMailslotInfo)(HANDLE  hMailslot, LPDWORD  lpMaxMessageSize, LPDWORD  lpNextSize, LPDWORD  lpMessageCount, LPDWORD  lpReadTimeout);
static WINAPI DWORD (*pGetMaximumProcessorCount)(WORD  group);
static void* pGetModuleFileNameA;
static void* pextGetModuleFileNameA;
static void* pGetModuleFileNameW;
static void* pextGetModuleFileNameW;
static void* pGetModuleHandleA;
static void* pextGetModuleHandleA;
static void* pGetModuleHandleExA;
static void* pextGetModuleHandleExA;
static void* pGetModuleHandleExW;
static void* pextGetModuleHandleExW;
static void* pGetModuleHandleW;
static void* pextGetModuleHandleW;
static WINAPI BOOL (*pGetNamedPipeClientProcessId)(HANDLE  pipe, ULONG*  id);
static WINAPI BOOL (*pGetNamedPipeClientSessionId)(HANDLE  pipe, ULONG*  id);
static WINAPI BOOL (*pGetNamedPipeHandleStateA)(HANDLE  hNamedPipe, LPDWORD  lpState, LPDWORD  lpCurInstances, LPDWORD  lpMaxCollectionCount, LPDWORD  lpCollectDataTimeout, LPSTR  lpUsername, DWORD  nUsernameMaxSize);
static WINAPI BOOL (*pGetNamedPipeHandleStateW)(HANDLE  hNamedPipe, LPDWORD  lpState, LPDWORD  lpCurInstances, LPDWORD  lpMaxCollectionCount, LPDWORD  lpCollectDataTimeout, LPWSTR  lpUsername, DWORD  nUsernameMaxSize);
static void* pGetNamedPipeInfo;
static void* pextGetNamedPipeInfo;
static WINAPI BOOL (*pGetNamedPipeServerProcessId)(HANDLE  pipe, ULONG*  id);
static WINAPI BOOL (*pGetNamedPipeServerSessionId)(HANDLE  pipe, ULONG*  id);
static WINAPI void (*pGetNativeSystemInfo)(LPSYSTEM_INFO  si);
static WINAPI PUMS_CONTEXT (*pGetNextUmsListItem)(PUMS_CONTEXT  ctx);
static WINAPI BOOL (*pGetNumaAvailableMemoryNode)(UCHAR  node, PULONGLONG  available_bytes);
static WINAPI BOOL (*pGetNumaAvailableMemoryNodeEx)(USHORT  node, PULONGLONG  available_bytes);
static WINAPI BOOL (*pGetNumaHighestNodeNumber)(PULONG  highestnode);
static WINAPI BOOL (*pGetNumaNodeProcessorMask)(UCHAR  node, PULONGLONG  mask);
static WINAPI BOOL (*pGetNumaNodeProcessorMaskEx)(USHORT  node, PGROUP_AFFINITY  mask);
static WINAPI BOOL (*pGetNumaProcessorNode)(UCHAR  processor, PUCHAR  node);
static WINAPI BOOL (*pGetNumaProcessorNodeEx)(PPROCESSOR_NUMBER  processor, PUSHORT  node_number);
static WINAPI BOOL (*pGetNumaProximityNode)(ULONG  proximity_id, PUCHAR  node_number);
static WINAPI BOOL (*pGetNumaProximityNodeEx)(ULONG  proximity_id, PUSHORT  node_number);
static WINAPI INT (*pGetNumberFormatA)(LCID  lcid, DWORD  dwFlags, LPCSTR  lpszValue, NUMBERFMTA*  lpFormat, LPSTR  lpNumberStr, int  cchOut);
static WINAPI INT (*pGetNumberFormatEx)(LPCWSTR  name, DWORD  flags, LPCWSTR  value, NUMBERFMTW*  format, LPWSTR  number, int  numout);
static WINAPI INT (*pGetNumberFormatW)(LCID  lcid, DWORD  dwFlags, LPCWSTR  lpszValue, NUMBERFMTW*  lpFormat, LPWSTR  lpNumberStr, int  cchOut);
static WINAPI DWORD (*pGetNumberOfConsoleFonts)(void);
static void* pGetNumberOfConsoleInputEvents;
static void* pextGetNumberOfConsoleInputEvents;
static WINAPI BOOL (*pGetNumberOfConsoleMouseButtons)(LPDWORD  nrofbuttons);
static WINAPI UINT (*pGetOEMCP)(void);
static void* pGetOverlappedResult;
static void* pextGetOverlappedResult;
static WINAPI BOOL (*pGetUserPreferredUILanguages)(DWORD  flags, ULONG*  count, WCHAR*  buffer, ULONG*  size);
static WINAPI LONG (*pGetPackageFullName)(HANDLE  process, UINT32*  length, PWSTR  name);
static WINAPI BOOL (*pGetPhysicallyInstalledSystemMemory)(ULONGLONG*  total_memory);
static void* pGetPriorityClass;
static void* pextGetPriorityClass;
static WINAPI UINT (*pGetPrivateProfileIntA)(LPCSTR  section, LPCSTR  entry, INT  def_val, LPCSTR  filename);
static WINAPI UINT (*pGetPrivateProfileIntW)(LPCWSTR  section, LPCWSTR  entry, INT  def_val, LPCWSTR  filename);
static WINAPI INT (*pGetPrivateProfileSectionA)(LPCSTR  section, LPSTR  buffer, DWORD  len, LPCSTR  filename);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesA)(LPSTR  buffer, DWORD  size, LPCSTR  filename);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesW)(LPWSTR  buffer, DWORD  size, LPCWSTR  filename);
static WINAPI INT (*pGetPrivateProfileSectionW)(LPCWSTR  section, LPWSTR  buffer, DWORD  len, LPCWSTR  filename);
static WINAPI INT (*pGetPrivateProfileStringA)(LPCSTR  section, LPCSTR  entry, LPCSTR  def_val, LPSTR  buffer, UINT  len, LPCSTR  filename);
static WINAPI INT (*pGetPrivateProfileStringW)(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  def_val, LPWSTR  buffer, UINT  len, LPCWSTR  filename);
static WINAPI BOOL (*pGetPrivateProfileStructA)(LPCSTR  section, LPCSTR  key, LPVOID  buffer, UINT  len, LPCSTR  filename);
static WINAPI BOOL (*pGetPrivateProfileStructW)(LPCWSTR  section, LPCWSTR  key, LPVOID  buf, UINT  len, LPCWSTR  filename);
static WINAPI FARPROC (*pGetProcAddress)(HMODULE  hModule, LPCSTR  function);
static WINAPI BOOL (*pGetProcessAffinityMask)(HANDLE  hProcess, PDWORD_PTR  process_mask, PDWORD_PTR  system_mask);
static WINAPI BOOL (*pGetProcessDEPPolicy)(HANDLE  process, LPDWORD  flags, PBOOL  permanent);
static WINAPI DWORD (*pGetProcessFlags)(DWORD  processid);
static void* pGetProcessHandleCount;
static void* pextGetProcessHandleCount;
static void* pGetProcessHeap;
static void* pextGetProcessHeap;
static void* pGetProcessId;
static void* pextGetProcessId;
static void* pGetProcessIdOfThread;
static void* pextGetProcessIdOfThread;
static WINAPI BOOL (*pGetProcessIoCounters)(HANDLE  hProcess, PIO_COUNTERS  ioc);
static void* pGetProcessMitigationPolicy;
static void* pextGetProcessMitigationPolicy;
static WINAPI BOOL (*pGetProcessPreferredUILanguages)(DWORD  flags, ULONG*  count, WCHAR*  buf, ULONG*  size);
static void* pGetProcessPriorityBoost;
static void* pextGetProcessPriorityBoost;
static void* pGetProcessShutdownParameters;
static void* pextGetProcessShutdownParameters;
static WINAPI BOOL (*pGetProcessTimes)(HANDLE  hprocess, LPFILETIME  lpCreationTime, LPFILETIME  lpExitTime, LPFILETIME  lpKernelTime, LPFILETIME  lpUserTime);
static WINAPI DWORD (*pGetProcessVersion)(DWORD  pid);
static WINAPI BOOL (*pGetProcessWorkingSetSize)(HANDLE  process, SIZE_T*  minset, SIZE_T*  maxset);
static void* pGetProcessWorkingSetSizeEx;
static void* pextGetProcessWorkingSetSizeEx;
static WINAPI BOOL (*pGetProductInfo)(DWORD  dwOSMajorVersion, DWORD  dwOSMinorVersion, DWORD  dwSpMajorVersion, DWORD  dwSpMinorVersion, PDWORD  pdwReturnedProductType);
static WINAPI UINT (*pGetProfileIntA)(LPCSTR  section, LPCSTR  entry, INT  def_val);
static WINAPI UINT (*pGetProfileIntW)(LPCWSTR  section, LPCWSTR  entry, INT  def_val);
static WINAPI INT (*pGetProfileSectionA)(LPCSTR  section, LPSTR  buffer, DWORD  len);
static WINAPI INT (*pGetProfileSectionW)(LPCWSTR  section, LPWSTR  buffer, DWORD  len);
static WINAPI INT (*pGetProfileStringA)(LPCSTR  section, LPCSTR  entry, LPCSTR  def_val, LPSTR  buffer, UINT  len);
static WINAPI INT (*pGetProfileStringW)(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  def_val, LPWSTR  buffer, UINT  len);
static void* pGetQueuedCompletionStatus;
static void* pextGetQueuedCompletionStatus;
static void* pGetQueuedCompletionStatusEx;
static void* pextGetQueuedCompletionStatusEx;
static WINAPI DWORD (*pGetShortPathNameA)(LPCSTR  longpath, LPSTR  shortpath, DWORD  shortlen);
static WINAPI DWORD (*pGetShortPathNameW)(LPCWSTR  longpath, LPWSTR  shortpath, DWORD  shortlen);
static WINAPI void (*pGetStartupInfoA)(LPSTARTUPINFOA  info);
static void* pGetStartupInfoW;
static void* pextGetStartupInfoW;
static void* pGetStdHandle;
static void* pextGetStdHandle;
static WINAPI BOOL (*pGetStringTypeA)(LCID  locale, DWORD  type, LPCSTR  src, INT  count, LPWORD  chartype);
static WINAPI BOOL (*pGetStringTypeExA)(LCID  locale, DWORD  type, LPCSTR  src, INT  count, LPWORD  chartype);
static WINAPI BOOL (*pGetStringTypeExW)(LCID  locale, DWORD  type, LPCWSTR  src, INT  count, LPWORD  chartype);
static WINAPI BOOL (*pGetStringTypeW)(DWORD  type, LPCWSTR  src, INT  count, LPWORD  chartype);
static WINAPI BOOL (*pGetSystemFileCacheSize)(PSIZE_T  mincache, PSIZE_T  maxcache, PDWORD  flags);
static WINAPI LCID (*pGetSystemDefaultLCID)(void);
static WINAPI LANGID (*pGetSystemDefaultLangID)(void);
static WINAPI INT (*pGetSystemDefaultLocaleName)(LPWSTR  localename, INT  len);
static WINAPI LANGID (*pGetSystemDefaultUILanguage)(void);
static WINAPI DEP_SYSTEM_POLICY_TYPE (*pGetSystemDEPPolicy)(void);
static WINAPI UINT (*pGetSystemDirectoryA)(LPSTR  path, UINT  count);
static WINAPI UINT (*pGetSystemDirectoryW)(LPWSTR  path, UINT  count);
static WINAPI UINT (*pGetSystemFirmwareTable)(DWORD  provider, DWORD  id, void*  buffer, DWORD  size);
static WINAPI void (*pGetSystemInfo)(LPSYSTEM_INFO  si);
static WINAPI BOOL (*pGetSystemPowerStatus)(LPSYSTEM_POWER_STATUS  ps);
static WINAPI BOOL (*pGetSystemPreferredUILanguages)(DWORD  flags, ULONG*  count, WCHAR*  buffer, ULONG*  size);
static WINAPI BOOL (*pGetSystemRegistryQuota)(PDWORD  pdwQuotaAllowed, PDWORD  pdwQuotaUsed);
static WINAPI void (*pGetSystemTime)(LPSYSTEMTIME  systime);
static WINAPI BOOL (*pGetSystemTimeAdjustment)(PDWORD  lpTimeAdjustment, PDWORD  lpTimeIncrement, PBOOL  lpTimeAdjustmentDisabled);
static void* pGetSystemTimeAsFileTime;
static void* pextGetSystemTimeAsFileTime;
static WINAPI void (*pGetSystemTimePreciseAsFileTime)(FILETIME*  time);
static WINAPI BOOL (*pGetSystemTimes)(LPFILETIME  lpIdleTime, LPFILETIME  lpKernelTime, LPFILETIME  lpUserTime);
static void* pGetSystemWindowsDirectoryA;
static void* pextGetSystemWindowsDirectoryA;
static void* pGetSystemWindowsDirectoryW;
static void* pextGetSystemWindowsDirectoryW;
static WINAPI UINT (*pGetSystemWow64DirectoryA)(LPSTR  path, UINT  count);
static WINAPI UINT (*pGetSystemWow64DirectoryW)(LPWSTR  path, UINT  count);
static WINAPI DWORD (*pGetTapeParameters)(HANDLE  device, DWORD  operation, LPDWORD  size, LPVOID  info);
static WINAPI DWORD (*pGetTapePosition)(HANDLE  device, DWORD  type, LPDWORD  partition, LPDWORD  offset_low, LPDWORD  offset_high);
static WINAPI DWORD (*pGetTapeStatus)(HANDLE  device);
static WINAPI UINT (*pGetTempFileNameA)(LPCSTR  path, LPCSTR  prefix, UINT  unique, LPSTR  buffer);
static WINAPI UINT (*pGetTempFileNameW)(LPCWSTR  path, LPCWSTR  prefix, UINT  unique, LPWSTR  buffer);
static WINAPI DWORD (*pGetTempPathA)(DWORD  count, LPSTR  path);
static WINAPI DWORD (*pGetTempPathW)(DWORD  count, LPWSTR  path);
static void* pGetThreadContext;
static void* pextGetThreadContext;
static void* pGetThreadErrorMode;
static void* pextGetThreadErrorMode;
static void* pGetThreadGroupAffinity;
static void* pextGetThreadGroupAffinity;
static void* pGetThreadIOPendingFlag;
static void* pextGetThreadIOPendingFlag;
static void* pGetThreadId;
static void* pextGetThreadId;
static WINAPI LCID (*pGetThreadLocale)(void);
static WINAPI BOOL (*pGetThreadPreferredUILanguages)(DWORD  flags, ULONG*  count, WCHAR*  buf, ULONG*  size);
static void* pGetThreadPriority;
static void* pextGetThreadPriority;
static void* pGetThreadPriorityBoost;
static void* pextGetThreadPriorityBoost;
static WINAPI BOOL (*pGetThreadSelectorEntry)(HANDLE  hthread, DWORD  sel, LPLDT_ENTRY  ldtent);
static void* pGetThreadTimes;
static void* pextGetThreadTimes;
static void* pGetThreadUILanguage;
static void* pextGetThreadUILanguage;
static WINAPI DWORD (*pGetTickCount)(void);
static WINAPI ULONGLONG (*pGetTickCount64)(void);
static WINAPI INT (*pGetTimeFormatA)(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCSTR  lpFormat, LPSTR  lpTimeStr, INT  cchOut);
static WINAPI INT (*pGetTimeFormatEx)(LPCWSTR  localename, DWORD  flags, SYSTEMTIME*  time, LPCWSTR  format, LPWSTR  outbuf, INT  bufsize);
static WINAPI INT (*pGetTimeFormatW)(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCWSTR  lpFormat, LPWSTR  lpTimeStr, INT  cchOut);
static WINAPI DWORD (*pGetTimeZoneInformation)(LPTIME_ZONE_INFORMATION  ret);
static WINAPI BOOL (*pGetTimeZoneInformationForYear)(USHORT  wYear, PDYNAMIC_TIME_ZONE_INFORMATION  pdtzi, LPTIME_ZONE_INFORMATION  ptzi);
static WINAPI BOOL (*pGetUmsCompletionListEvent)(PUMS_COMPLETION_LIST  list, HANDLE*  event);
static WINAPI LCID (*pGetUserDefaultLCID)(void);
static WINAPI LANGID (*pGetUserDefaultLangID)(void);
static WINAPI INT (*pGetUserDefaultLocaleName)(LPWSTR  localename, int  buffersize);
static WINAPI LANGID (*pGetUserDefaultUILanguage)(void);
static WINAPI GEOID (*pGetUserGeoID)(GEOCLASS  GeoClass);
static void* pGetVersion;
static void* pextGetVersion;
static void* pGetVersionExA;
static void* pextGetVersionExA;
static void* pGetVersionExW;
static void* pextGetVersionExW;
static WINAPI BOOL (*pGetVolumeInformationA)(LPCSTR  root, LPSTR  label, DWORD  label_len, DWORD*  serial, DWORD*  filename_len, DWORD*  flags, LPSTR  fsname, DWORD  fsname_len);
static WINAPI BOOL (*pGetVolumeInformationByHandleW)(HANDLE  handle, WCHAR*  volnamebuf, DWORD  volnamesize, DWORD*  volserial, DWORD*  maxlength, DWORD*  flags, WCHAR*  fsnamebuf, DWORD  fsnamesize);
static WINAPI BOOL (*pGetVolumeInformationW)(LPCWSTR  root, LPWSTR  label, DWORD  label_len, DWORD*  serial, DWORD*  filename_len, DWORD*  flags, LPWSTR  fsname, DWORD  fsname_len);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointA)(LPCSTR  path, LPSTR  volume, DWORD  size);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointW)(LPCWSTR  path, LPWSTR  volume, DWORD  size);
static WINAPI BOOL (*pGetVolumePathNameA)(LPCSTR  filename, LPSTR  volumepathname, DWORD  buflen);
static WINAPI BOOL (*pGetVolumePathNameW)(LPCWSTR  filename, LPWSTR  volumepathname, DWORD  buflen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameA)(LPCSTR  volumename, LPSTR  volumepathname, DWORD  buflen, PDWORD  returnlen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameW)(LPCWSTR  volumename, LPWSTR  volumepathname, DWORD  buflen, PDWORD  returnlen);
static void* pGetWindowsDirectoryA;
static void* pextGetWindowsDirectoryA;
static void* pGetWindowsDirectoryW;
static void* pextGetWindowsDirectoryW;
static void* pGetWriteWatch;
static void* pextGetWriteWatch;
static WINAPI ATOM (*pGlobalAddAtomA)(LPCSTR  str);
static WINAPI ATOM (*pGlobalAddAtomW)(LPCWSTR  str);
static void* pGlobalAlloc;
static void* pextGlobalAlloc;
static WINAPI SIZE_T (*pGlobalCompact)(DWORD  minfree);
static WINAPI ATOM (*pGlobalDeleteAtom)(ATOM  atom);
static WINAPI ATOM (*pGlobalFindAtomA)(LPCSTR  str);
static WINAPI ATOM (*pGlobalFindAtomW)(LPCWSTR  str);
static WINAPI void (*pGlobalFix)(HGLOBAL  hmem);
static WINAPI UINT (*pGlobalFlags)(HGLOBAL  hmem);
static void* pGlobalFree;
static void* pextGlobalFree;
static WINAPI UINT (*pGlobalGetAtomNameA)(ATOM  atom, LPSTR  buffer, INT  count);
static WINAPI UINT (*pGlobalGetAtomNameW)(ATOM  atom, LPWSTR  buffer, INT  count);
static WINAPI HGLOBAL (*pGlobalHandle)(LPCVOID  pmem);
static WINAPI LPVOID (*pGlobalLock)(HGLOBAL  hmem);
static WINAPI void (*pGlobalMemoryStatus)(LPMEMORYSTATUS  lpBuffer);
static WINAPI BOOL (*pGlobalMemoryStatusEx)(LPMEMORYSTATUSEX  lpmemex);
static WINAPI HGLOBAL (*pGlobalReAlloc)(HGLOBAL  hmem, SIZE_T  size, UINT  flags);
static WINAPI SIZE_T (*pGlobalSize)(HGLOBAL  hmem);
static WINAPI BOOL (*pGlobalUnWire)(HGLOBAL  hmem);
static WINAPI void (*pGlobalUnfix)(HGLOBAL  hmem);
static WINAPI BOOL (*pGlobalUnlock)(HGLOBAL  hmem);
static WINAPI LPVOID (*pGlobalWire)(HGLOBAL  hmem);
static WINAPI BOOL (*pHeap32ListFirst)(HANDLE  hSnapshot, LPHEAPLIST32  lphl);
static void* pHeapAlloc;
static void* pextHeapAlloc;
static void* pHeapCompact;
static void* pextHeapCompact;
static WINAPI HANDLE (*pHeapCreate)(DWORD  flags, SIZE_T  initialSize, SIZE_T  maxSize);
static WINAPI BOOL (*pHeapDestroy)(HANDLE  heap);
static WINAPI BOOL (*pHeapFree)(HANDLE  heap, DWORD  flags, LPVOID  ptr);
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
static WINAPI INT (*pIdnToAscii)(DWORD  dwFlags, LPCWSTR  lpUnicodeCharStr, INT  cchUnicodeChar, LPWSTR  lpASCIICharStr, INT  cchASCIIChar);
static WINAPI INT (*pIdnToNameprepUnicode)(DWORD  dwFlags, LPCWSTR  lpUnicodeCharStr, INT  cchUnicodeChar, LPWSTR  lpNameprepCharStr, INT  cchNameprepChar);
static WINAPI INT (*pIdnToUnicode)(DWORD  dwFlags, LPCWSTR  lpASCIICharStr, INT  cchASCIIChar, LPWSTR  lpUnicodeCharStr, INT  cchUnicodeChar);
static WINAPI BOOL (*pInitAtomTable)(DWORD  entries);
static void* pInitOnceBeginInitialize;
static void* pextInitOnceBeginInitialize;
static void* pInitOnceComplete;
static void* pextInitOnceComplete;
static void* pInitOnceExecuteOnce;
static void* pextInitOnceExecuteOnce;
static void* pInitOnceInitialize;
static void* pextInitOnceInitialize;
static void* pInitializeConditionVariable;
static void* pextInitializeConditionVariable;
static void* pInitializeCriticalSection;
static void* pextInitializeCriticalSection;
static void* pInitializeCriticalSectionAndSpinCount;
static void* pextInitializeCriticalSectionAndSpinCount;
static void* pInitializeCriticalSectionEx;
static void* pextInitializeCriticalSectionEx;
static void* pInitializeProcThreadAttributeList;
static void* pextInitializeProcThreadAttributeList;
static void* pInitializeSListHead;
static void* pextInitializeSListHead;
static void* pInitializeSRWLock;
static void* pextInitializeSRWLock;
static void* pInterlockedCompareExchange64;
static void* pextInterlockedCompareExchange64;
static void* pInterlockedFlushSList;
static void* pextInterlockedFlushSList;
static void* pInterlockedPopEntrySList;
static void* pextInterlockedPopEntrySList;
static void* pInterlockedPushEntrySList;
static void* pextInterlockedPushEntrySList;
static void* pInterlockedPushListSList;
static void* pextInterlockedPushListSList;
static void* pInterlockedPushListSListEx;
static void* pextInterlockedPushListSListEx;
static WINAPI BOOL (*pInvalidateNLSCache)(void);
static WINAPI BOOL (*pIsBadCodePtr)(FARPROC  ptr);
static WINAPI BOOL (*pIsBadHugeReadPtr)(LPCVOID  ptr, UINT_PTR  size);
static WINAPI BOOL (*pIsBadHugeWritePtr)(LPVOID  ptr, UINT_PTR  size);
static WINAPI BOOL (*pIsBadReadPtr)(LPCVOID  ptr, UINT_PTR  size);
static WINAPI BOOL (*pIsBadStringPtrA)(LPCSTR  str, UINT_PTR  max);
static WINAPI BOOL (*pIsBadStringPtrW)(LPCWSTR  str, UINT_PTR  max);
static WINAPI BOOL (*pIsBadWritePtr)(LPVOID  ptr, UINT_PTR  size);
static WINAPI BOOL (*pIsDBCSLeadByte)(BYTE  testchar);
static WINAPI BOOL (*pIsDBCSLeadByteEx)(UINT  codepage, BYTE  testchar);
static void* pIsDebuggerPresent;
static void* pextIsDebuggerPresent;
static WINAPI BOOL (*pIsNormalizedString)(NORM_FORM  NormForm, LPCWSTR  lpString, INT  cwLength);
static WINAPI BOOL (*pIsProcessInJob)(HANDLE  process, HANDLE  job, PBOOL  result);
static WINAPI BOOL (*pIsProcessorFeaturePresent)(DWORD  feature);
static WINAPI BOOL (*pIsSystemResumeAutomatic)(void);
static void* pIsThreadAFiber;
static void* pextIsThreadAFiber;
static void* pIsThreadpoolTimerSet;
static void* pextIsThreadpoolTimerSet;
static WINAPI BOOL (*pIsValidCodePage)(UINT  codepage);
static WINAPI BOOL (*pIsValidLanguageGroup)(LGRPID  lgrpid, DWORD  dwFlags);
static WINAPI BOOL (*pIsValidLocale)(LCID  lcid, DWORD  flags);
static WINAPI BOOL (*pIsValidLocaleName)(LPCWSTR  locale);
static void* pIsWow64Process;
static void* pextIsWow64Process;
static WINAPI BOOL (*pK32EmptyWorkingSet)(HANDLE  hProcess);
static WINAPI BOOL (*pK32EnumDeviceDrivers)(void**  image_base, DWORD  cb, DWORD*  needed);
static WINAPI BOOL (*pK32EnumPageFilesA)(PENUM_PAGE_FILE_CALLBACKA  callback, LPVOID  context);
static WINAPI BOOL (*pK32EnumPageFilesW)(PENUM_PAGE_FILE_CALLBACKW  callback, LPVOID  context);
static WINAPI BOOL (*pK32EnumProcessModules)(HANDLE  process, HMODULE*  lphModule, DWORD  cb, DWORD*  needed);
static WINAPI BOOL (*pK32EnumProcessModulesEx)(HANDLE  process, HMODULE*  lphModule, DWORD  cb, DWORD*  needed, DWORD  filter);
static WINAPI BOOL (*pK32EnumProcesses)(DWORD*  lpdwProcessIDs, DWORD  cb, DWORD*  lpcbUsed);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameA)(void*  image_base, LPSTR  base_name, DWORD  size);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameW)(void*  image_base, LPWSTR  base_name, DWORD  size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameA)(void*  image_base, LPSTR  file_name, DWORD  size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameW)(void*  image_base, LPWSTR  file_name, DWORD  size);
static WINAPI DWORD (*pK32GetMappedFileNameA)(HANDLE  process, LPVOID  lpv, LPSTR  file_name, DWORD  size);
static WINAPI DWORD (*pK32GetMappedFileNameW)(HANDLE  process, LPVOID  lpv, LPWSTR  file_name, DWORD  size);
static WINAPI DWORD (*pK32GetModuleBaseNameA)(HANDLE  process, HMODULE  module, LPSTR  base_name, DWORD  size);
static WINAPI DWORD (*pK32GetModuleBaseNameW)(HANDLE  process, HMODULE  module, LPWSTR  base_name, DWORD  size);
static WINAPI DWORD (*pK32GetModuleFileNameExA)(HANDLE  process, HMODULE  module, LPSTR  file_name, DWORD  size);
static WINAPI DWORD (*pK32GetModuleFileNameExW)(HANDLE  process, HMODULE  module, LPWSTR  file_name, DWORD  size);
static WINAPI BOOL (*pK32GetModuleInformation)(HANDLE  process, HMODULE  module, MODULEINFO*  modinfo, DWORD  cb);
static WINAPI BOOL (*pK32GetPerformanceInfo)(PPERFORMANCE_INFORMATION  info, DWORD  size);
static WINAPI DWORD (*pK32GetProcessImageFileNameA)(HANDLE  process, LPSTR  file, DWORD  size);
static WINAPI DWORD (*pK32GetProcessImageFileNameW)(HANDLE  process, LPWSTR  file, DWORD  size);
static WINAPI BOOL (*pK32GetProcessMemoryInfo)(HANDLE  process, PPROCESS_MEMORY_COUNTERS  pmc, DWORD  cb);
static WINAPI BOOL (*pK32GetWsChanges)(HANDLE  process, PPSAPI_WS_WATCH_INFORMATION  watchinfo, DWORD  size);
static WINAPI BOOL (*pK32GetWsChangesEx)(HANDLE  process, PSAPI_WS_WATCH_INFORMATION_EX*  watchinfoex, DWORD*  size);
static WINAPI BOOL (*pK32InitializeProcessForWsWatch)(HANDLE  process);
static WINAPI BOOL (*pK32QueryWorkingSet)(HANDLE  process, LPVOID  buffer, DWORD  size);
static WINAPI BOOL (*pK32QueryWorkingSetEx)(HANDLE  process, LPVOID  buffer, DWORD  size);
static WINAPI INT (*pLCIDToLocaleName)(LCID  lcid, LPWSTR  name, INT  count, DWORD  flags);
static WINAPI INT (*pLCMapStringA)(LCID  lcid, DWORD  flags, LPCSTR  src, INT  srclen, LPSTR  dst, INT  dstlen);
static WINAPI INT (*pLCMapStringEx)(LPCWSTR  name, DWORD  flags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen, LPNLSVERSIONINFO  version, LPVOID  reserved, LPARAM  lparam);
static WINAPI INT (*pLCMapStringW)(LCID  lcid, DWORD  flags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen);
static WINAPI void (*pLZClose)(HFILE  fd);
static WINAPI LONG (*pLZCopy)(HFILE  src, HFILE  dest);
static WINAPI void (*pLZDone)(void);
static WINAPI HFILE (*pLZInit)(HFILE  hfSrc);
static WINAPI HFILE (*pLZOpenFileA)(LPSTR  fn, LPOFSTRUCT  ofs, WORD  mode);
static WINAPI HFILE (*pLZOpenFileW)(LPWSTR  fn, LPOFSTRUCT  ofs, WORD  mode);
static WINAPI INT (*pLZRead)(HFILE  fd, LPSTR  vbuf, INT  toread);
static WINAPI LONG (*pLZSeek)(HFILE  fd, LONG  off, INT  type);
static WINAPI INT (*pLZStart)(void);
static void* pLeaveCriticalSection;
static void* pextLeaveCriticalSection;
static void* pLeaveCriticalSectionWhenCallbackReturns;
static void* pextLeaveCriticalSectionWhenCallbackReturns;
static WINAPI HMODULE (*pLoadLibraryA)(LPCSTR  libname);
static WINAPI HMODULE (*pLoadLibraryExA)(LPCSTR  libname, HANDLE  hfile, DWORD  flags);
static WINAPI HMODULE (*pLoadLibraryExW)(LPCWSTR  libnameW, HANDLE  hfile, DWORD  flags);
static WINAPI HMODULE (*pLoadLibraryW)(LPCWSTR  libnameW);
static WINAPI DWORD (*pLoadModule)(LPCSTR  name, LPVOID  paramBlock);
static void* pLoadResource;
static void* pextLoadResource;
static void* pLocalAlloc;
static void* pextLocalAlloc;
static WINAPI SIZE_T (*pLocalCompact)(UINT  minfree);
static WINAPI BOOL (*pLocalFileTimeToFileTime)(FILETIME*  localft, LPFILETIME  utcft);
static WINAPI UINT (*pLocalFlags)(HLOCAL  handle);
static void* pLocalFree;
static void* pextLocalFree;
static WINAPI HLOCAL (*pLocalHandle)(LPCVOID  ptr);
static void* pLocalLock;
static void* pextLocalLock;
static void* pLocalReAlloc;
static void* pextLocalReAlloc;
static WINAPI SIZE_T (*pLocalShrink)(HGLOBAL  handle, UINT  newsize);
static WINAPI SIZE_T (*pLocalSize)(HLOCAL  handle);
static void* pLocalUnlock;
static void* pextLocalUnlock;
static WINAPI LCID (*pLocaleNameToLCID)(LPCWSTR  name, DWORD  flags);
static void* pLockFile;
static void* pextLockFile;
static void* pLockFileEx;
static void* pextLockFileEx;
static void* pLockResource;
static void* pextLockResource;
static WINAPI void (*pMakeCriticalSectionGlobal)(CRITICAL_SECTION*  crit);
static WINAPI BOOL (*pMapUserPhysicalPages)(PVOID  addr, ULONG_PTR  page_count, PULONG_PTR  pages);
static void* pMapViewOfFile;
static void* pextMapViewOfFile;
static void* pMapViewOfFileEx;
static void* pextMapViewOfFileEx;
static void* pMapViewOfFileExNuma;
static void* pextMapViewOfFileExNuma;
static WINAPI BOOL (*pModule32First)(HANDLE  hSnapshot, LPMODULEENTRY32  lpme);
static WINAPI BOOL (*pModule32FirstW)(HANDLE  hSnapshot, LPMODULEENTRY32W  lpme);
static WINAPI BOOL (*pModule32Next)(HANDLE  hSnapshot, LPMODULEENTRY32  lpme);
static WINAPI BOOL (*pModule32NextW)(HANDLE  hSnapshot, LPMODULEENTRY32W  lpme);
static WINAPI BOOL (*pMoveFileA)(LPCSTR  source, LPCSTR  dest);
static WINAPI BOOL (*pMoveFileExA)(LPCSTR  source, LPCSTR  dest, DWORD  flag);
static WINAPI BOOL (*pMoveFileExW)(LPCWSTR  source, LPCWSTR  dest, DWORD  flag);
static WINAPI BOOL (*pMoveFileTransactedA)(char*  source, char*  dest, LPPROGRESS_ROUTINE  progress, void*  data, DWORD  flags, HANDLE  handle);
static WINAPI BOOL (*pMoveFileTransactedW)(WCHAR*  source, WCHAR*  dest, LPPROGRESS_ROUTINE  progress, void*  data, DWORD  flags, HANDLE  handle);
static WINAPI BOOL (*pMoveFileW)(LPCWSTR  source, LPCWSTR  dest);
static WINAPI BOOL (*pMoveFileWithProgressA)(LPCSTR  source, LPCSTR  dest, LPPROGRESS_ROUTINE  fnProgress, LPVOID  param, DWORD  flag);
static WINAPI BOOL (*pMoveFileWithProgressW)(LPCWSTR  source, LPCWSTR  dest, LPPROGRESS_ROUTINE  fnProgress, LPVOID  param, DWORD  flag);
static WINAPI INT (*pMulDiv)(INT  nMultiplicand, INT  nMultiplier, INT  nDivisor);
static WINAPI INT (*pMultiByteToWideChar)(UINT  page, DWORD  flags, LPCSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathA)(LPCSTR  name);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathW)(LPCWSTR  name);
static WINAPI INT (*pNormalizeString)(NORM_FORM  form, WCHAR*  src, INT  src_len, WCHAR*  dst, INT  dst_len);
static WINAPI HANDLE (*pOpenConsoleW)(LPCWSTR  name, DWORD  access, BOOL  inherit, DWORD  creation);
static void* pOpenEventA;
static void* pextOpenEventA;
static void* pOpenEventW;
static void* pextOpenEventW;
static WINAPI HFILE (*pOpenFile)(LPCSTR  name, OFSTRUCT*  ofs, UINT  mode);
static void* pOpenFileById;
static void* pextOpenFileById;
static WINAPI HANDLE (*pOpenFileMappingA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static void* pOpenFileMappingW;
static void* pextOpenFileMappingW;
static WINAPI HANDLE (*pOpenJobObjectA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static WINAPI HANDLE (*pOpenJobObjectW)(DWORD  access, BOOL  inherit, LPCWSTR  name);
static WINAPI HANDLE (*pOpenMutexA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static void* pOpenMutexW;
static void* pextOpenMutexW;
static void* pOpenProcess;
static void* pextOpenProcess;
static WINAPI BOOL (*pOpenProfileUserMapping)(void);
static WINAPI HANDLE (*pOpenSemaphoreA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static void* pOpenSemaphoreW;
static void* pextOpenSemaphoreW;
static void* pOpenThread;
static void* pextOpenThread;
static WINAPI HANDLE (*pOpenVxDHandle)(HANDLE  hHandleRing3);
static WINAPI HANDLE (*pOpenWaitableTimerA)(DWORD  access, BOOL  inherit, LPCSTR  name);
static void* pOpenWaitableTimerW;
static void* pextOpenWaitableTimerW;
static void* pOutputDebugStringA;
static void* pextOutputDebugStringA;
static void* pOutputDebugStringW;
static void* pextOutputDebugStringW;
static void* pPeekConsoleInputA;
static void* pextPeekConsoleInputA;
static void* pPeekConsoleInputW;
static void* pextPeekConsoleInputW;
static void* pPeekNamedPipe;
static void* pextPeekNamedPipe;
static void* pPostQueuedCompletionStatus;
static void* pextPostQueuedCompletionStatus;
static WINAPI BOOL (*pPowerClearRequest)(HANDLE  request, POWER_REQUEST_TYPE  type);
static WINAPI HANDLE (*pPowerCreateRequest)(REASON_CONTEXT*  context);
static WINAPI BOOL (*pPowerSetRequest)(HANDLE  request, POWER_REQUEST_TYPE  type);
static WINAPI DWORD (*pPrepareTape)(HANDLE  device, DWORD  operation, BOOL  immediate);
static WINAPI BOOL (*pProcess32First)(HANDLE  hSnapshot, LPPROCESSENTRY32  lppe);
static WINAPI BOOL (*pProcess32FirstW)(HANDLE  hSnapshot, LPPROCESSENTRY32W  lppe);
static WINAPI BOOL (*pProcess32Next)(HANDLE  hSnapshot, LPPROCESSENTRY32  lppe);
static WINAPI BOOL (*pProcess32NextW)(HANDLE  hSnapshot, LPPROCESSENTRY32W  lppe);
static WINAPI BOOL (*pProcessIdToSessionId)(DWORD  procid, DWORD*  sessionid_ptr);
static void* pPulseEvent;
static void* pextPulseEvent;
static void* pPurgeComm;
static void* pextPurgeComm;
static void* pQueryActCtxSettingsW;
static void* pextQueryActCtxSettingsW;
static void* pQueryActCtxW;
static void* pextQueryActCtxW;
static void* pQueryDepthSList;
static void* pextQueryDepthSList;
static WINAPI DWORD (*pQueryDosDeviceA)(LPCSTR  devname, LPSTR  target, DWORD  bufsize);
static WINAPI DWORD (*pQueryDosDeviceW)(LPCWSTR  devname, LPWSTR  target, DWORD  bufsize);
static WINAPI BOOL (*pQueryFullProcessImageNameA)(HANDLE  hProcess, DWORD  dwFlags, LPSTR  lpExeName, PDWORD  pdwSize);
static WINAPI BOOL (*pQueryFullProcessImageNameW)(HANDLE  hProcess, DWORD  dwFlags, LPWSTR  lpExeName, PDWORD  pdwSize);
static WINAPI BOOL (*pQueryInformationJobObject)(HANDLE  job, JOBOBJECTINFOCLASS  class, LPVOID  info, DWORD  len, DWORD*  ret_len);
static void* pQueryMemoryResourceNotification;
static void* pextQueryMemoryResourceNotification;
static void* pQueryPerformanceCounter;
static void* pextQueryPerformanceCounter;
static void* pQueryPerformanceFrequency;
static void* pextQueryPerformanceFrequency;
static WINAPI BOOL (*pQueryProcessCycleTime)(HANDLE  process, PULONG64  cycle);
static WINAPI BOOL (*pQueryThreadCycleTime)(HANDLE  thread, PULONG64  cycle);
static WINAPI BOOL (*pQueryUmsThreadInformation)(PUMS_CONTEXT  ctx, UMS_THREAD_INFO_CLASS  class, void*  buf, ULONG  length, ULONG*  ret_length);
static WINAPI BOOL (*pQueryUnbiasedInterruptTime)(ULONGLONG*  time);
static void* pQueueUserAPC;
static void* pextQueueUserAPC;
static void* pQueueUserWorkItem;
static void* pextQueueUserWorkItem;
static void* pRaiseException;
static void* pextRaiseException;
static void* pReadConsoleA;
static void* pextReadConsoleA;
static void* pReadConsoleInputA;
static void* pextReadConsoleInputA;
static WINAPI BOOL (*pReadConsoleInputW)(HANDLE  hConsoleInput, PINPUT_RECORD  lpBuffer, DWORD  nLength, LPDWORD  lpNumberOfEventsRead);
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
static WINAPI BOOL (*pReadConsoleW)(HANDLE  hConsoleInput, LPVOID  lpBuffer, DWORD  nNumberOfCharsToRead, LPDWORD  lpNumberOfCharsRead, LPVOID  lpReserved);
static void* pReadDirectoryChangesW;
static void* pextReadDirectoryChangesW;
static void* pReadFile;
static void* pextReadFile;
static void* pReadFileEx;
static void* pextReadFileEx;
static void* pReadFileScatter;
static void* pextReadFileScatter;
static void* pReadProcessMemory;
static void* pextReadProcessMemory;
static WINAPI HRESULT (*pRegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK  callback, PVOID  param, DWORD  pingint, DWORD  flags);
static WINAPI HRESULT (*pRegisterApplicationRestart)(PCWSTR  pwzCommandLine, DWORD  dwFlags);
static WINAPI DWORD (*pRegisterServiceProcess)(DWORD  dwProcessId, DWORD  dwType);
static WINAPI BOOL (*pRegisterWaitForSingleObject)(PHANDLE  phNewWaitObject, HANDLE  hObject, WAITORTIMERCALLBACK  Callback, PVOID  Context, ULONG  dwMilliseconds, ULONG  dwFlags);
static void* pRegisterWaitForSingleObjectEx;
static void* pextRegisterWaitForSingleObjectEx;
static WINAPI void (*pReinitializeCriticalSection)(CRITICAL_SECTION*  crit);
static void* pReleaseActCtx;
static void* pextReleaseActCtx;
static void* pReleaseMutex;
static void* pextReleaseMutex;
static void* pReleaseMutexWhenCallbackReturns;
static void* pextReleaseMutexWhenCallbackReturns;
static void* pReleaseSemaphore;
static void* pextReleaseSemaphore;
static void* pReleaseSemaphoreWhenCallbackReturns;
static void* pextReleaseSemaphoreWhenCallbackReturns;
static void* pReleaseSRWLockExclusive;
static void* pextReleaseSRWLockExclusive;
static void* pReleaseSRWLockShared;
static void* pextReleaseSRWLockShared;
static WINAPI BOOL (*pRemoveDirectoryA)(LPCSTR  path);
static WINAPI BOOL (*pRemoveDirectoryW)(LPCWSTR  path);
static void* pRemoveVectoredContinueHandler;
static void* pextRemoveVectoredContinueHandler;
static void* pRemoveVectoredExceptionHandler;
static void* pextRemoveVectoredExceptionHandler;
static WINAPI BOOL (*pReplaceFileA)(LPCSTR  lpReplacedFileName, LPCSTR  lpReplacementFileName, LPCSTR  lpBackupFileName, DWORD  dwReplaceFlags, LPVOID  lpExclude, LPVOID  lpReserved);
static WINAPI BOOL (*pReplaceFileW)(LPCWSTR  lpReplacedFileName, LPCWSTR  lpReplacementFileName, LPCWSTR  lpBackupFileName, DWORD  dwReplaceFlags, LPVOID  lpExclude, LPVOID  lpReserved);
static WINAPI BOOL (*pRemoveDllDirectory)(DLL_DIRECTORY_COOKIE  cookie);
static WINAPI BOOL (*pRequestDeviceWakeup)(HANDLE  device);
static WINAPI BOOL (*pRequestWakeupLatency)(LATENCY_TIME  latency);
static void* pResetEvent;
static void* pextResetEvent;
static void* pResetWriteWatch;
static void* pextResetWriteWatch;
static void* pResolveDelayLoadedAPI;
static void* pextResolveDelayLoadedAPI;
static WINAPI INT (*pResolveLocaleName)(LPCWSTR  name, LPWSTR  localename, INT  len);
static void* pRestoreLastError;
static void* pextRestoreLastError;
static void* pResumeThread;
static void* pextResumeThread;
static void* pRtlAddFunctionTable;
static void* pextRtlAddFunctionTable;
static void* pRtlCaptureContext;
static void* pextRtlCaptureContext;
static void* pRtlCaptureStackBackTrace;
static void* pextRtlCaptureStackBackTrace;
static void* pRtlCompareMemory;
static void* pextRtlCompareMemory;
static void* pRtlCopyMemory;
static void* pextRtlCopyMemory;
static void* pRtlDeleteFunctionTable;
static void* pextRtlDeleteFunctionTable;
static void* pRtlFillMemory;
static void* pextRtlFillMemory;
static void* pRtlInstallFunctionTableCallback;
static void* pextRtlInstallFunctionTableCallback;
static void* pRtlLookupFunctionEntry;
static void* pextRtlLookupFunctionEntry;
static void* pRtlMoveMemory;
static void* pextRtlMoveMemory;
static void* pRtlPcToFileHeader;
static void* pextRtlPcToFileHeader;
static void* pRtlRaiseException;
static void* pextRtlRaiseException;
static void* pRtlRestoreContext;
static void* pextRtlRestoreContext;
static void* pRtlUnwind;
static void* pextRtlUnwind;
static void* pRtlUnwindEx;
static void* pextRtlUnwindEx;
static void* pRtlVirtualUnwind;
static void* pextRtlVirtualUnwind;
static void* pRtlZeroMemory;
static void* pextRtlZeroMemory;
static void* pScrollConsoleScreenBufferA;
static void* pextScrollConsoleScreenBufferA;
static void* pScrollConsoleScreenBufferW;
static void* pextScrollConsoleScreenBufferW;
static WINAPI DWORD (*pSearchPathA)(LPCSTR  path, LPCSTR  name, LPCSTR  ext, DWORD  buflen, LPSTR  buffer, LPSTR*  lastpart);
static WINAPI DWORD (*pSearchPathW)(LPCWSTR  path, LPCWSTR  name, LPCWSTR  ext, DWORD  buflen, LPWSTR  buffer, LPWSTR*  lastpart);
static WINAPI UINT (*pSetCPGlobal)(UINT  acp);
static WINAPI INT (*pSetCalendarInfoA)(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPCSTR  lpCalData);
static WINAPI INT (*pSetCalendarInfoW)(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPCWSTR  lpCalData);
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
static WINAPI BOOL (*pSetComputerNameA)(LPCSTR  lpComputerName);
static WINAPI BOOL (*pSetComputerNameExA)(COMPUTER_NAME_FORMAT  type, LPCSTR  lpComputerName);
static WINAPI BOOL (*pSetComputerNameExW)(COMPUTER_NAME_FORMAT  type, LPCWSTR  lpComputerName);
static WINAPI BOOL (*pSetComputerNameW)(LPCWSTR  lpComputerName);
static void* pSetConsoleActiveScreenBuffer;
static void* pextSetConsoleActiveScreenBuffer;
static void* pSetConsoleCP;
static void* pextSetConsoleCP;
static WINAPI BOOL (*pSetConsoleCtrlHandler)(PHANDLER_ROUTINE  func, BOOL  add);
static void* pSetConsoleCursorInfo;
static void* pextSetConsoleCursorInfo;
static void* pSetConsoleCursorPosition;
static void* pextSetConsoleCursorPosition;
static WINAPI BOOL (*pSetConsoleDisplayMode)(HANDLE  hConsoleOutput, DWORD  dwFlags, COORD*  lpNewScreenBufferDimensions);
static WINAPI BOOL (*pSetConsoleFont)(HANDLE  hConsole, DWORD  index);
static WINAPI BOOL (*pSetConsoleIcon)(HICON  icon);
static void* pSetConsoleInputExeNameA;
static void* pextSetConsoleInputExeNameA;
static void* pSetConsoleInputExeNameW;
static void* pextSetConsoleInputExeNameW;
static WINAPI BOOL (*pSetConsoleKeyShortcuts)(BOOL  set, BYTE  keys, void*  a, DWORD  b);
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
static WINAPI BOOL (*pSetConsoleTitleA)(LPCSTR  title);
static void* pSetConsoleTitleW;
static void* pextSetConsoleTitleW;
static void* pSetConsoleWindowInfo;
static void* pextSetConsoleWindowInfo;
static void* pSetCriticalSectionSpinCount;
static void* pextSetCriticalSectionSpinCount;
static WINAPI BOOL (*pSetCurrentConsoleFontEx)(HANDLE  hConsole, BOOL  maxwindow, CONSOLE_FONT_INFOEX*  cfix);
static WINAPI BOOL (*pSetCurrentDirectoryA)(LPCSTR  dir);
static WINAPI BOOL (*pSetCurrentDirectoryW)(LPCWSTR  dir);
static WINAPI BOOL (*pSetDefaultCommConfigA)(LPCSTR  lpszDevice, LPCOMMCONFIG  lpCommConfig, DWORD  dwSize);
static WINAPI BOOL (*pSetDefaultCommConfigW)(LPCWSTR  lpszDevice, LPCOMMCONFIG  lpCommConfig, DWORD  dwSize);
static WINAPI BOOL (*pSetDefaultDllDirectories)(DWORD  flags);
static WINAPI BOOL (*pSetDllDirectoryA)(LPCSTR  dir);
static WINAPI BOOL (*pSetDllDirectoryW)(LPCWSTR  dir);
static void* pSetEndOfFile;
static void* pextSetEndOfFile;
static void* pSetEnvironmentVariableA;
static void* pextSetEnvironmentVariableA;
static void* pSetEnvironmentVariableW;
static void* pextSetEnvironmentVariableW;
static void* pSetErrorMode;
static void* pextSetErrorMode;
static void* pSetEvent;
static void* pextSetEvent;
static void* pSetEventWhenCallbackReturns;
static void* pextSetEventWhenCallbackReturns;
static void* pSetFileApisToANSI;
static void* pextSetFileApisToANSI;
static void* pSetFileApisToOEM;
static void* pextSetFileApisToOEM;
static void* pSetFileAttributesA;
static void* pextSetFileAttributesA;
static void* pSetFileAttributesW;
static void* pextSetFileAttributesW;
static WINAPI BOOL (*pSetFileCompletionNotificationModes)(HANDLE  file, UCHAR  flags);
static void* pSetFileInformationByHandle;
static void* pextSetFileInformationByHandle;
static void* pSetFilePointer;
static void* pextSetFilePointer;
static void* pSetFilePointerEx;
static void* pextSetFilePointerEx;
static void* pSetFileTime;
static void* pextSetFileTime;
static void* pSetFileValidData;
static void* pextSetFileValidData;
static WINAPI BOOL (*pSetHandleContext)(HANDLE  hnd, DWORD  context);
static WINAPI UINT (*pSetHandleCount)(UINT  count);
static WINAPI BOOL (*pSetHandleInformation)(HANDLE  handle, DWORD  mask, DWORD  flags);
static WINAPI BOOL (*pSetInformationJobObject)(HANDLE  job, JOBOBJECTINFOCLASS  class, LPVOID  info, DWORD  len);
static WINAPI BOOL (*pSetLocalTime)(SYSTEMTIME*  systime);
static WINAPI BOOL (*pSetLocaleInfoA)(LCID  lcid, LCTYPE  lctype, LPCSTR  data);
static WINAPI BOOL (*pSetLocaleInfoW)(LCID  lcid, LCTYPE  lctype, LPCWSTR  data);
static WINAPI BOOL (*pSetMailslotInfo)(HANDLE  hMailslot, DWORD  dwReadTimeout);
static void* pSetNamedPipeHandleState;
static void* pextSetNamedPipeHandleState;
static void* pSetPriorityClass;
static void* pextSetPriorityClass;
static WINAPI BOOL (*pSetProcessAffinityMask)(HANDLE  hProcess, DWORD_PTR  affmask);
static void* pSetProcessAffinityUpdateMode;
static void* pextSetProcessAffinityUpdateMode;
static WINAPI BOOL (*pSetProcessDEPPolicy)(DWORD  newDEP);
static void* pSetProcessMitigationPolicy;
static void* pextSetProcessMitigationPolicy;
static WINAPI BOOL (*pSetProcessPreferredUILanguages)(DWORD  flags, PCZZWSTR  buffer, PULONG  count);
static void* pSetProcessPriorityBoost;
static void* pextSetProcessPriorityBoost;
static void* pSetProcessShutdownParameters;
static void* pextSetProcessShutdownParameters;
static WINAPI BOOL (*pSetProcessWorkingSetSize)(HANDLE  process, SIZE_T  minset, SIZE_T  maxset);
static void* pSetProcessWorkingSetSizeEx;
static void* pextSetProcessWorkingSetSizeEx;
static WINAPI BOOL (*pSetSearchPathMode)(DWORD  flags);
static void* pSetStdHandle;
static void* pextSetStdHandle;
static void* pSetStdHandleEx;
static void* pextSetStdHandleEx;
static WINAPI BOOL (*pSetSystemFileCacheSize)(SIZE_T  mincache, SIZE_T  maxcache, DWORD  flags);
static WINAPI BOOL (*pSetSystemPowerState)(BOOL  suspend_or_hibernate, BOOL  force_flag);
static WINAPI BOOL (*pSetSystemTime)(SYSTEMTIME*  systime);
static WINAPI BOOL (*pSetSystemTimeAdjustment)(DWORD  dwTimeAdjustment, BOOL  bTimeAdjustmentDisabled);
static WINAPI DWORD (*pSetTapeParameters)(HANDLE  device, DWORD  operation, LPVOID  info);
static WINAPI DWORD (*pSetTapePosition)(HANDLE  device, DWORD  method, DWORD  partition, DWORD  offset_low, DWORD  offset_high, BOOL  immediate);
static WINAPI DWORD (*pSetTermsrvAppInstallMode)(BOOL  bInstallMode);
static WINAPI DWORD_PTR (*pSetThreadAffinityMask)(HANDLE  hThread, DWORD_PTR  dwThreadAffinityMask);
static void* pSetThreadContext;
static void* pextSetThreadContext;
static void* pSetThreadErrorMode;
static void* pextSetThreadErrorMode;
static WINAPI DWORD (*pSetThreadExecutionState)(EXECUTION_STATE  flags);
static void* pSetThreadGroupAffinity;
static void* pextSetThreadGroupAffinity;
static void* pSetThreadIdealProcessor;
static void* pextSetThreadIdealProcessor;
static void* pSetThreadIdealProcessorEx;
static void* pextSetThreadIdealProcessorEx;
static WINAPI BOOL (*pSetThreadLocale)(LCID  lcid);
static WINAPI BOOL (*pSetThreadPreferredUILanguages)(DWORD  flags, PCZZWSTR  buffer, PULONG  count);
static void* pSetThreadPriority;
static void* pextSetThreadPriority;
static void* pSetThreadPriorityBoost;
static void* pextSetThreadPriorityBoost;
static void* pSetThreadStackGuarantee;
static void* pextSetThreadStackGuarantee;
static WINAPI LANGID (*pSetThreadUILanguage)(LANGID  langid);
static void* pSetThreadpoolThreadMaximum;
static void* pextSetThreadpoolThreadMaximum;
static void* pSetThreadpoolThreadMinimum;
static void* pextSetThreadpoolThreadMinimum;
static void* pSetThreadpoolTimer;
static void* pextSetThreadpoolTimer;
static void* pSetThreadpoolWait;
static void* pextSetThreadpoolWait;
static WINAPI BOOL (*pSetTimeZoneInformation)(TIME_ZONE_INFORMATION*  tzinfo);
static WINAPI BOOL (*pSetUmsThreadInformation)(PUMS_CONTEXT  ctx, UMS_THREAD_INFO_CLASS  class, void*  buf, ULONG  length);
static void* pSetUnhandledExceptionFilter;
static void* pextSetUnhandledExceptionFilter;
static WINAPI BOOL (*pSetUserGeoID)(GEOID  GeoID);
static WINAPI BOOL (*pSetVolumeLabelA)(LPCSTR  root, LPCSTR  volname);
static WINAPI BOOL (*pSetVolumeLabelW)(LPCWSTR  root, LPCWSTR  label);
static WINAPI BOOL (*pSetVolumeMountPointA)(LPCSTR  path, LPCSTR  volume);
static WINAPI BOOL (*pSetVolumeMountPointW)(LPCWSTR  path, LPCWSTR  volume);
static void* pSetWaitableTimer;
static void* pextSetWaitableTimer;
static void* pSetWaitableTimerEx;
static void* pextSetWaitableTimerEx;
static void* pSetupComm;
static void* pextSetupComm;
static void* pSignalObjectAndWait;
static void* pextSignalObjectAndWait;
static void* pSizeofResource;
static void* pextSizeofResource;
static void* pSleep;
static void* pextSleep;
static void* pSleepConditionVariableCS;
static void* pextSleepConditionVariableCS;
static void* pSleepConditionVariableSRW;
static void* pextSleepConditionVariableSRW;
static void* pSleepEx;
static void* pextSleepEx;
static void* pSubmitThreadpoolWork;
static void* pextSubmitThreadpoolWork;
static void* pSuspendThread;
static void* pextSuspendThread;
static void* pSwitchToFiber;
static void* pextSwitchToFiber;
static void* pSwitchToThread;
static void* pextSwitchToThread;
static WINAPI BOOL (*pSystemTimeToFileTime)(SYSTEMTIME*  syst, LPFILETIME  ft);
static WINAPI BOOL (*pSystemTimeToTzSpecificLocalTime)(TIME_ZONE_INFORMATION*  lpTimeZoneInformation, SYSTEMTIME*  lpUniversalTime, LPSYSTEMTIME  lpLocalTime);
static WINAPI BOOL (*pTerminateJobObject)(HANDLE  job, UINT  exit_code);
static void* pTerminateProcess;
static void* pextTerminateProcess;
static void* pTerminateThread;
static void* pextTerminateThread;
static WINAPI BOOL (*pTermsrvAppInstallMode)(void);
static WINAPI BOOL (*pThread32First)(HANDLE  hSnapShot, LPTHREADENTRY32  lpte);
static WINAPI BOOL (*pThread32Next)(HANDLE  hSnapShot, LPTHREADENTRY32  lpte);
static void* pTlsAlloc;
static void* pextTlsAlloc;
static void* pTlsFree;
static void* pextTlsFree;
static void* pTlsGetValue;
static void* pextTlsGetValue;
static void* pTlsSetValue;
static void* pextTlsSetValue;
static WINAPI BOOL (*pToolhelp32ReadProcessMemory)(DWORD  pid, void*  base, void*  buf, SIZE_T  len, SIZE_T*  r);
static void* pTransactNamedPipe;
static void* pextTransactNamedPipe;
static void* pTransmitCommChar;
static void* pextTransmitCommChar;
static void* pTryAcquireSRWLockExclusive;
static void* pextTryAcquireSRWLockExclusive;
static void* pTryAcquireSRWLockShared;
static void* pextTryAcquireSRWLockShared;
static void* pTryEnterCriticalSection;
static void* pextTryEnterCriticalSection;
static void* pTrySubmitThreadpoolCallback;
static void* pextTrySubmitThreadpoolCallback;
static WINAPI BOOL (*pTzSpecificLocalTimeToSystemTime)(TIME_ZONE_INFORMATION*  lpTimeZoneInformation, SYSTEMTIME*  lpLocalTime, LPSYSTEMTIME  lpUniversalTime);
static WINAPI BOOL (*pUmsThreadYield)(void*  param);
static void* pUnhandledExceptionFilter;
static void* pextUnhandledExceptionFilter;
static WINAPI void (*pUninitializeCriticalSection)(CRITICAL_SECTION*  crit);
static void* pUnlockFile;
static void* pextUnlockFile;
static void* pUnlockFileEx;
static void* pextUnlockFileEx;
static void* pUnmapViewOfFile;
static void* pextUnmapViewOfFile;
static WINAPI HRESULT (*pUnregisterApplicationRestart)(void);
static WINAPI BOOL (*pUnregisterWait)(HANDLE  WaitHandle);
static void* pUnregisterWaitEx;
static void* pextUnregisterWaitEx;
static void* pUpdateProcThreadAttribute;
static void* pextUpdateProcThreadAttribute;
static WINAPI BOOL (*pUpdateResourceA)(HANDLE  hUpdate, LPCSTR  lpType, LPCSTR  lpName, WORD  wLanguage, LPVOID  lpData, DWORD  cbData);
static WINAPI BOOL (*pUpdateResourceW)(HANDLE  hUpdate, LPCWSTR  lpType, LPCWSTR  lpName, WORD  wLanguage, LPVOID  lpData, DWORD  cbData);
static WINAPI DWORD (*pVerLanguageNameA)(DWORD  wLang, LPSTR  szLang, DWORD  nSize);
static WINAPI DWORD (*pVerLanguageNameW)(DWORD  wLang, LPWSTR  szLang, DWORD  nSize);
static void* pVerSetConditionMask;
static void* pextVerSetConditionMask;
static WINAPI BOOL (*pVerifyConsoleIoHandle)(HANDLE  handle);
static WINAPI BOOL (*pVerifyVersionInfoA)(LPOSVERSIONINFOEXA  lpVersionInfo, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask);
static WINAPI BOOL (*pVerifyVersionInfoW)(LPOSVERSIONINFOEXW  lpVersionInfo, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask);
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
static WINAPI DWORD (*pWTSGetActiveConsoleSessionId)(void);
static void* pWaitCommEvent;
static void* pextWaitCommEvent;
static void* pWaitForDebugEvent;
static void* pextWaitForDebugEvent;
static void* pWaitForMultipleObjects;
static void* pextWaitForMultipleObjects;
static void* pWaitForMultipleObjectsEx;
static void* pextWaitForMultipleObjectsEx;
static void* pWaitForSingleObject;
static void* pextWaitForSingleObject;
static void* pWaitForSingleObjectEx;
static void* pextWaitForSingleObjectEx;
static void* pWaitForThreadpoolTimerCallbacks;
static void* pextWaitForThreadpoolTimerCallbacks;
static void* pWaitForThreadpoolWaitCallbacks;
static void* pextWaitForThreadpoolWaitCallbacks;
static void* pWaitForThreadpoolWorkCallbacks;
static void* pextWaitForThreadpoolWorkCallbacks;
static WINAPI BOOL (*pWaitNamedPipeA)(LPCSTR  name, DWORD  nTimeOut);
static void* pWaitNamedPipeW;
static void* pextWaitNamedPipeW;
static void* pWakeAllConditionVariable;
static void* pextWakeAllConditionVariable;
static void* pWakeConditionVariable;
static void* pextWakeConditionVariable;
static WINAPI HRESULT (*pWerRegisterFile)(PCWSTR  file, WER_REGISTER_FILE_TYPE  regfiletype, DWORD  flags);
static WINAPI HRESULT (*pWerRegisterMemoryBlock)(void*  block, DWORD  size);
static WINAPI HRESULT (*pWerRegisterRuntimeExceptionModule)(PCWSTR  callbackdll, PVOID  context);
static WINAPI HRESULT (*pWerSetFlags)(DWORD  flags);
static WINAPI HRESULT (*pWerUnregisterMemoryBlock)(void*  block);
static WINAPI HRESULT (*pWerUnregisterRuntimeExceptionModule)(PCWSTR  callbackdll, PVOID  context);
static WINAPI INT (*pWideCharToMultiByte)(UINT  page, DWORD  flags, LPCWSTR  src, INT  srclen, LPSTR  dst, INT  dstlen, LPCSTR  defchar, BOOL*  used);
static WINAPI UINT (*pWinExec)(LPCSTR  lpCmdLine, UINT  nCmdShow);
static WINAPI BOOLEAN (*pWow64EnableWow64FsRedirection)(BOOLEAN  enable);
static void* pWow64DisableWow64FsRedirection;
static void* pextWow64DisableWow64FsRedirection;
static WINAPI BOOL (*pWow64GetThreadContext)(HANDLE  handle, WOW64_CONTEXT*  context);
static void* pWow64RevertWow64FsRedirection;
static void* pextWow64RevertWow64FsRedirection;
static WINAPI BOOL (*pWow64SetThreadContext)(HANDLE  handle, WOW64_CONTEXT*  context);
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
static WINAPI BOOL (*pWriteConsoleW)(HANDLE  hConsoleOutput, LPCVOID  lpBuffer, DWORD  nNumberOfCharsToWrite, LPDWORD  lpNumberOfCharsWritten, LPVOID  lpReserved);
static void* pWriteFile;
static void* pextWriteFile;
static void* pWriteFileEx;
static void* pextWriteFileEx;
static void* pWriteFileGather;
static void* pextWriteFileGather;
static WINAPI BOOL (*pWritePrivateProfileSectionA)(LPCSTR  section, LPCSTR  string, LPCSTR  filename);
static WINAPI BOOL (*pWritePrivateProfileSectionW)(LPCWSTR  section, LPCWSTR  string, LPCWSTR  filename);
static WINAPI BOOL (*pWritePrivateProfileStringA)(LPCSTR  section, LPCSTR  entry, LPCSTR  string, LPCSTR  filename);
static WINAPI BOOL (*pWritePrivateProfileStringW)(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  string, LPCWSTR  filename);
static WINAPI BOOL (*pWritePrivateProfileStructA)(LPCSTR  section, LPCSTR  key, LPVOID  buf, UINT  bufsize, LPCSTR  filename);
static WINAPI BOOL (*pWritePrivateProfileStructW)(LPCWSTR  section, LPCWSTR  key, LPVOID  buf, UINT  bufsize, LPCWSTR  filename);
static void* pWriteProcessMemory;
static void* pextWriteProcessMemory;
static WINAPI BOOL (*pWriteProfileSectionA)(LPCSTR  section, LPCSTR  keys_n_values);
static WINAPI BOOL (*pWriteProfileSectionW)(LPCWSTR  section, LPCWSTR  keys_n_values);
static WINAPI BOOL (*pWriteProfileStringA)(LPCSTR  section, LPCSTR  entry, LPCSTR  string);
static WINAPI BOOL (*pWriteProfileStringW)(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  string);
static WINAPI DWORD (*pWriteTapemark)(HANDLE  device, DWORD  type, DWORD  count, BOOL  immediate);
static void* pZombifyActCtx;
static void* pextZombifyActCtx;
static WINAPI LONG (*p_hread)(HFILE  hFile, LPVOID  buffer, LONG  count);
static WINAPI LONG (*p_hwrite)(HFILE  handle, LPCSTR  buffer, LONG  count);
static WINAPI HFILE (*p_lclose)(HFILE  hFile);
static WINAPI HFILE (*p_lcreat)(LPCSTR  path, INT  attr);
static WINAPI LONG (*p_llseek)(HFILE  hFile, LONG  lOffset, INT  nOrigin);
static WINAPI HFILE (*p_lopen)(LPCSTR  path, INT  mode);
static WINAPI UINT (*p_lread)(HFILE  handle, LPVOID  buffer, UINT  count);
static WINAPI UINT (*p_lwrite)(HFILE  hFile, LPCSTR  buffer, UINT  count);
static WINAPI LPSTR (*plstrcatA)(LPSTR  dst, LPCSTR  src);
static WINAPI LPWSTR (*plstrcatW)(LPWSTR  dst, LPCWSTR  src);
static void* plstrcmp;
static void* pextlstrcmp;
static void* plstrcmpA;
static void* pextlstrcmpA;
static void* plstrcmpW;
static void* pextlstrcmpW;
static void* plstrcmpi;
static void* pextlstrcmpi;
static void* plstrcmpiA;
static void* pextlstrcmpiA;
static void* plstrcmpiW;
static void* pextlstrcmpiW;
static WINAPI LPSTR (*plstrcpyA)(LPSTR  dst, LPCSTR  src);
static WINAPI LPWSTR (*plstrcpyW)(LPWSTR  dst, LPCWSTR  src);
static void* plstrcpyn;
static void* pextlstrcpyn;
static void* plstrcpynA;
static void* pextlstrcpynA;
static void* plstrcpynW;
static void* pextlstrcpynW;
static void* plstrlen;
static void* pextlstrlen;
static void* plstrlenA;
static void* pextlstrlenA;
static void* plstrlenW;
static void* pextlstrlenW;
static WINAPI char* (*pwine_get_unix_file_name)(LPCWSTR  dosW);
static WINAPI WCHAR* (*pwine_get_dos_file_name)(LPCSTR  str);
static WINAPI void* (*p__wine_kernel_init)(void);

extern WINAPI ATOM wine32b_kernel32_AddAtomA(LPCSTR  str) /* ../dlls/kernel32/atom.c:152 */
{
	TRACE("Enter AddAtomA\n");
	return pAddAtomA(str);
}

extern WINAPI void wine32a_kernel32_AddAtomA(void);  /* ../dlls/kernel32/atom.c:152 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AddAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AddAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_AddAtomW(LPCWSTR  str) /* ../dlls/kernel32/atom.c:202 */
{
	TRACE("Enter AddAtomW\n");
	return pAddAtomW(str);
}

extern WINAPI void wine32a_kernel32_AddAtomW(void);  /* ../dlls/kernel32/atom.c:202 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AddAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AddAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_AddConsoleAliasA(LPSTR  source, LPSTR  target, LPSTR  exename) /* ../dlls/kernel32/console.c:1600 */
{
	TRACE("Enter AddConsoleAliasA\n");
	return pAddConsoleAliasA(source, target, exename);
}

extern WINAPI void wine32a_kernel32_AddConsoleAliasA(void);  /* ../dlls/kernel32/console.c:1600 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AddConsoleAliasA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AddConsoleAliasA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_AddConsoleAliasW(LPWSTR  source, LPWSTR  target, LPWSTR  exename) /* ../dlls/kernel32/console.c:1607 */
{
	TRACE("Enter AddConsoleAliasW\n");
	return pAddConsoleAliasW(source, target, exename);
}

extern WINAPI void wine32a_kernel32_AddConsoleAliasW(void);  /* ../dlls/kernel32/console.c:1607 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AddConsoleAliasW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AddConsoleAliasW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DLL_DIRECTORY_COOKIE wine32b_kernel32_AddDllDirectory(WCHAR*  dir) /* ../dlls/kernel32/module.c:172 */
{
	TRACE("Enter AddDllDirectory\n");
	return pAddDllDirectory(dir);
}

extern WINAPI void wine32a_kernel32_AddDllDirectory(void);  /* ../dlls/kernel32/module.c:172 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AddDllDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AddDllDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_AllocConsole(void) /* ../dlls/kernel32/console.c:633 */
{
	TRACE("Enter AllocConsole\n");
	return pAllocConsole();
}

extern WINAPI void wine32a_kernel32_AllocConsole(void);  /* ../dlls/kernel32/console.c:633 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AllocConsole,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AllocConsole") "\n"
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

extern WINAPI BOOL wine32b_kernel32_AllocateUserPhysicalPages(HANDLE  process, ULONG_PTR*  pages, ULONG_PTR*  userarray) /* ../dlls/kernel32/heap.c:929 */
{
	TRACE("Enter AllocateUserPhysicalPages\n");
	return pAllocateUserPhysicalPages(process, pages, userarray);
}

extern WINAPI void wine32a_kernel32_AllocateUserPhysicalPages(void);  /* ../dlls/kernel32/heap.c:929 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AllocateUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AllocateUserPhysicalPages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_ApplicationRecoveryFinished(BOOL  success) /* ../dlls/kernel32/process.c:3937 */
{
	TRACE("Enter ApplicationRecoveryFinished\n");
	return pApplicationRecoveryFinished(success);
}

extern WINAPI void wine32a_kernel32_ApplicationRecoveryFinished(void);  /* ../dlls/kernel32/process.c:3937 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ApplicationRecoveryFinished,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ApplicationRecoveryFinished") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_ApplicationRecoveryInProgress(PBOOL  canceled) /* ../dlls/kernel32/process.c:3946 */
{
	TRACE("Enter ApplicationRecoveryInProgress\n");
	return pApplicationRecoveryInProgress(canceled);
}

extern WINAPI void wine32a_kernel32_ApplicationRecoveryInProgress(void);  /* ../dlls/kernel32/process.c:3946 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ApplicationRecoveryInProgress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ApplicationRecoveryInProgress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_AssignProcessToJobObject(HANDLE  job, HANDLE  process) /* ../dlls/kernel32/sync.c:378 */
{
	TRACE("Enter AssignProcessToJobObject\n");
	return pAssignProcessToJobObject(job, process);
}

extern WINAPI void wine32a_kernel32_AssignProcessToJobObject(void);  /* ../dlls/kernel32/sync.c:378 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_AssignProcessToJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_AssignProcessToJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BackupRead(HANDLE  file, LPBYTE  buffer, DWORD  to_read, LPDWORD  read, BOOL  abort, BOOL  security, LPVOID*  context) /* ../dlls/kernel32/tape.c:51 */
{
	TRACE("Enter BackupRead\n");
	return pBackupRead(file, buffer, to_read, read, abort, security, context);
}

extern WINAPI void wine32a_kernel32_BackupRead(void);  /* ../dlls/kernel32/tape.c:51 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BackupRead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BackupRead") "\n"
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

extern WINAPI BOOL wine32b_kernel32_BackupSeek(HANDLE  file, DWORD  seek_low, DWORD  seek_high, LPDWORD  seeked_low, LPDWORD  seeked_high, LPVOID*  context) /* ../dlls/kernel32/tape.c:66 */
{
	TRACE("Enter BackupSeek\n");
	return pBackupSeek(file, seek_low, seek_high, seeked_low, seeked_high, context);
}

extern WINAPI void wine32a_kernel32_BackupSeek(void);  /* ../dlls/kernel32/tape.c:66 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BackupSeek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BackupSeek") "\n"
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

extern WINAPI BOOL wine32b_kernel32_BackupWrite(HANDLE  file, LPBYTE  buffer, DWORD  to_write, LPDWORD  written, BOOL  abort, BOOL  security, LPVOID*  context) /* ../dlls/kernel32/tape.c:81 */
{
	TRACE("Enter BackupWrite\n");
	return pBackupWrite(file, buffer, to_write, written, abort, security, context);
}

extern WINAPI void wine32a_kernel32_BackupWrite(void);  /* ../dlls/kernel32/tape.c:81 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BackupWrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BackupWrite") "\n"
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

extern WINAPI BOOL wine32b_kernel32_BaseFlushAppcompatCache(void) /* ../dlls/kernel32/process.c:4258 */
{
	TRACE("Enter BaseFlushAppcompatCache\n");
	return pBaseFlushAppcompatCache();
}

extern WINAPI void wine32a_kernel32_BaseFlushAppcompatCache(void);  /* ../dlls/kernel32/process.c:4258 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BaseFlushAppcompatCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BaseFlushAppcompatCache") "\n"
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

extern WINAPI BOOL wine32b_kernel32_Beep(DWORD  dwFreq, DWORD  dwDur) /* ../dlls/kernel32/console.c:197 */
{
	TRACE("Enter Beep\n");
	return pBeep(dwFreq, dwDur);
}

extern WINAPI void wine32a_kernel32_Beep(void);  /* ../dlls/kernel32/console.c:197 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Beep,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Beep") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_BeginUpdateResourceA(LPCSTR  pFileName, BOOL  bDeleteExistingResources) /* ../dlls/kernel32/resource.c:1240 */
{
	TRACE("Enter BeginUpdateResourceA\n");
	return pBeginUpdateResourceA(pFileName, bDeleteExistingResources);
}

extern WINAPI void wine32a_kernel32_BeginUpdateResourceA(void);  /* ../dlls/kernel32/resource.c:1240 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BeginUpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BeginUpdateResourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_BeginUpdateResourceW(LPCWSTR  pFileName, BOOL  bDeleteExistingResources) /* ../dlls/kernel32/resource.c:1194 */
{
	TRACE("Enter BeginUpdateResourceW\n");
	return pBeginUpdateResourceW(pFileName, bDeleteExistingResources);
}

extern WINAPI void wine32a_kernel32_BeginUpdateResourceW(void);  /* ../dlls/kernel32/resource.c:1194 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BeginUpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BeginUpdateResourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BindIoCompletionCallback(HANDLE  FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE  Function, ULONG  Flags) /* ../dlls/kernel32/sync.c:999 */
{
	TRACE("Enter BindIoCompletionCallback\n");
	return pBindIoCompletionCallback(FileHandle, Function, Flags);
}

extern WINAPI void wine32a_kernel32_BindIoCompletionCallback(void);  /* ../dlls/kernel32/sync.c:999 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BindIoCompletionCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BindIoCompletionCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BuildCommDCBA(LPCSTR  device, LPDCB  lpdcb) /* ../dlls/kernel32/comm.c:422 */
{
	TRACE("Enter BuildCommDCBA\n");
	return pBuildCommDCBA(device, lpdcb);
}

extern WINAPI void wine32a_kernel32_BuildCommDCBA(void);  /* ../dlls/kernel32/comm.c:422 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BuildCommDCBA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BuildCommDCBA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BuildCommDCBAndTimeoutsA(LPCSTR  device, LPDCB  lpdcb, LPCOMMTIMEOUTS  lptimeouts) /* ../dlls/kernel32/comm.c:440 */
{
	TRACE("Enter BuildCommDCBAndTimeoutsA\n");
	return pBuildCommDCBAndTimeoutsA(device, lpdcb, lptimeouts);
}

extern WINAPI void wine32a_kernel32_BuildCommDCBAndTimeoutsA(void);  /* ../dlls/kernel32/comm.c:440 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BuildCommDCBAndTimeoutsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BuildCommDCBAndTimeoutsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BuildCommDCBAndTimeoutsW(LPCWSTR  devid, LPDCB  lpdcb, LPCOMMTIMEOUTS  lptimeouts) /* ../dlls/kernel32/comm.c:469 */
{
	TRACE("Enter BuildCommDCBAndTimeoutsW\n");
	return pBuildCommDCBAndTimeoutsW(devid, lpdcb, lptimeouts);
}

extern WINAPI void wine32a_kernel32_BuildCommDCBAndTimeoutsW(void);  /* ../dlls/kernel32/comm.c:469 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BuildCommDCBAndTimeoutsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BuildCommDCBAndTimeoutsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_BuildCommDCBW(LPCWSTR  devid, LPDCB  lpdcb) /* ../dlls/kernel32/comm.c:526 */
{
	TRACE("Enter BuildCommDCBW\n");
	return pBuildCommDCBW(devid, lpdcb);
}

extern WINAPI void wine32a_kernel32_BuildCommDCBW(void);  /* ../dlls/kernel32/comm.c:526 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_BuildCommDCBW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_BuildCommDCBW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CallNamedPipeA(LPCSTR  lpNamedPipeName, LPVOID  lpInput, DWORD  dwInputSize, LPVOID  lpOutput, DWORD  dwOutputSize, LPDWORD  lpBytesRead, DWORD  nTimeout) /* ../dlls/kernel32/sync.c:715 */
{
	TRACE("Enter CallNamedPipeA\n");
	return pCallNamedPipeA(lpNamedPipeName, lpInput, dwInputSize, lpOutput, dwOutputSize, lpBytesRead, nTimeout);
}

extern WINAPI void wine32a_kernel32_CallNamedPipeA(void);  /* ../dlls/kernel32/sync.c:715 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CallNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CallNamedPipeA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CancelTimerQueueTimer(HANDLE  queue, HANDLE  timer) /* ../dlls/kernel32/sync.c:468 */
{
	TRACE("Enter CancelTimerQueueTimer\n");
	return pCancelTimerQueueTimer(queue, timer);
}

extern WINAPI void wine32a_kernel32_CancelTimerQueueTimer(void);  /* ../dlls/kernel32/sync.c:468 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CancelTimerQueueTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CancelTimerQueueTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CheckNameLegalDOS8Dot3A(char*  name, char*  oemname, DWORD  oemname_len, BOOL*  contains_spaces, BOOL*  is_legal) /* ../dlls/kernel32/path.c:1975 */
{
	TRACE("Enter CheckNameLegalDOS8Dot3A\n");
	return pCheckNameLegalDOS8Dot3A(name, oemname, oemname_len, contains_spaces, is_legal);
}

extern WINAPI void wine32a_kernel32_CheckNameLegalDOS8Dot3A(void);  /* ../dlls/kernel32/path.c:1975 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CheckNameLegalDOS8Dot3A,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CheckNameLegalDOS8Dot3A") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CheckNameLegalDOS8Dot3W(WCHAR*  name, char*  oemname, DWORD  oemname_len, BOOL*  contains_spaces_ret, BOOL*  is_legal) /* ../dlls/kernel32/path.c:1994 */
{
	TRACE("Enter CheckNameLegalDOS8Dot3W\n");
	return pCheckNameLegalDOS8Dot3W(name, oemname, oemname_len, contains_spaces_ret, is_legal);
}

extern WINAPI void wine32a_kernel32_CheckNameLegalDOS8Dot3W(void);  /* ../dlls/kernel32/path.c:1994 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CheckNameLegalDOS8Dot3W,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CheckNameLegalDOS8Dot3W") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CloseConsoleHandle(HANDLE  handle) /* ../dlls/kernel32/console.c:291 */
{
	TRACE("Enter CloseConsoleHandle\n");
	return pCloseConsoleHandle(handle);
}

extern WINAPI void wine32a_kernel32_CloseConsoleHandle(void);  /* ../dlls/kernel32/console.c:291 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CloseConsoleHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CloseConsoleHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CloseHandle(HANDLE  handle) /* ../dlls/kernel32/process.c:3238 */
{
	TRACE("Enter CloseHandle\n");
	return pCloseHandle(handle);
}

extern WINAPI void wine32a_kernel32_CloseHandle(void);  /* ../dlls/kernel32/process.c:3238 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CloseHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CloseHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CloseProfileUserMapping(void) /* ../dlls/kernel32/profile.c:1786 */
{
	TRACE("Enter CloseProfileUserMapping\n");
	return pCloseProfileUserMapping();
}

extern WINAPI void wine32a_kernel32_CloseProfileUserMapping(void);  /* ../dlls/kernel32/profile.c:1786 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CloseProfileUserMapping,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CloseProfileUserMapping") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CmdBatNotification(BOOL  bBatchRunning) /* ../dlls/kernel32/process.c:3888 */
{
	TRACE("Enter CmdBatNotification\n");
	return pCmdBatNotification(bBatchRunning);
}

extern WINAPI void wine32a_kernel32_CmdBatNotification(void);  /* ../dlls/kernel32/process.c:3888 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CmdBatNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CmdBatNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CommConfigDialogA(LPCSTR  lpszDevice, HWND  hWnd, LPCOMMCONFIG  lpCommConfig) /* ../dlls/kernel32/comm.c:568 */
{
	TRACE("Enter CommConfigDialogA\n");
	return pCommConfigDialogA(lpszDevice, hWnd, lpCommConfig);
}

extern WINAPI void wine32a_kernel32_CommConfigDialogA(void);  /* ../dlls/kernel32/comm.c:568 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CommConfigDialogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CommConfigDialogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CommConfigDialogW(LPCWSTR  lpszDevice, HWND  hWnd, LPCOMMCONFIG  lpCommConfig) /* ../dlls/kernel32/comm.c:595 */
{
	TRACE("Enter CommConfigDialogW\n");
	return pCommConfigDialogW(lpszDevice, hWnd, lpCommConfig);
}

extern WINAPI void wine32a_kernel32_CommConfigDialogW(void);  /* ../dlls/kernel32/comm.c:595 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CommConfigDialogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CommConfigDialogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_CompareFileTime(FILETIME*  x, FILETIME*  y) /* ../dlls/kernel32/time.c:1274 */
{
	TRACE("Enter CompareFileTime\n");
	return pCompareFileTime(x, y);
}

extern WINAPI void wine32a_kernel32_CompareFileTime(void);  /* ../dlls/kernel32/time.c:1274 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CompareFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CompareFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_CompareStringA(LCID  lcid, DWORD  flags, LPCSTR  str1, INT  len1, LPCSTR  str2, INT  len2) /* ../dlls/kernel32/locale.c:3976 */
{
	TRACE("Enter CompareStringA\n");
	return pCompareStringA(lcid, flags, str1, len1, str2, len2);
}

extern WINAPI void wine32a_kernel32_CompareStringA(void);  /* ../dlls/kernel32/locale.c:3976 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CompareStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CompareStringA") "\n"
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

extern WINAPI INT wine32b_kernel32_CompareStringW(LCID  lcid, DWORD  flags, LPCWSTR  str1, INT  len1, LPCWSTR  str2, INT  len2) /* ../dlls/kernel32/locale.c:3907 */
{
	TRACE("Enter CompareStringW\n");
	return pCompareStringW(lcid, flags, str1, len1, str2, len2);
}

extern WINAPI void wine32a_kernel32_CompareStringW(void);  /* ../dlls/kernel32/locale.c:3907 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CompareStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CompareStringW") "\n"
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

extern WINAPI INT wine32b_kernel32_CompareStringEx(LPCWSTR  locale, DWORD  flags, LPCWSTR  str1, INT  len1, LPCWSTR  str2, INT  len2, LPNLSVERSIONINFO  version, LPVOID  reserved, LPARAM  lParam) /* ../dlls/kernel32/locale.c:3916 */
{
	TRACE("Enter CompareStringEx\n");
	return pCompareStringEx(locale, flags, str1, len1, str2, len2, version, reserved, lParam);
}

extern WINAPI void wine32a_kernel32_CompareStringEx(void);  /* ../dlls/kernel32/locale.c:3916 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CompareStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CompareStringEx") "\n"
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

extern WINAPI INT wine32b_kernel32_CompareStringOrdinal(WCHAR*  str1, INT  len1, WCHAR*  str2, INT  len2, BOOL  ignore_case) /* ../dlls/kernel32/locale.c:4052 */
{
	TRACE("Enter CompareStringOrdinal\n");
	return pCompareStringOrdinal(str1, len1, str2, len2, ignore_case);
}

extern WINAPI void wine32a_kernel32_CompareStringOrdinal(void);  /* ../dlls/kernel32/locale.c:4052 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CompareStringOrdinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CompareStringOrdinal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_kernel32_ConvertDefaultLocale(LCID  lcid) /* ../dlls/kernel32/locale.c:2871 */
{
	TRACE("Enter ConvertDefaultLocale\n");
	return pConvertDefaultLocale(lcid);
}

extern WINAPI void wine32a_kernel32_ConvertDefaultLocale(void);  /* ../dlls/kernel32/locale.c:2871 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ConvertDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ConvertDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_ConvertToGlobalHandle(HANDLE  hSrc) /* ../dlls/kernel32/process.c:3338 */
{
	TRACE("Enter ConvertToGlobalHandle\n");
	return pConvertToGlobalHandle(hSrc);
}

extern WINAPI void wine32a_kernel32_ConvertToGlobalHandle(void);  /* ../dlls/kernel32/process.c:3338 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ConvertToGlobalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ConvertToGlobalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CopyFileA(LPCSTR  source, LPCSTR  dest, BOOL  fail_if_exists) /* ../dlls/kernel32/path.c:1152 */
{
	TRACE("Enter CopyFileA\n");
	return pCopyFileA(source, dest, fail_if_exists);
}

extern WINAPI void wine32a_kernel32_CopyFileA(void);  /* ../dlls/kernel32/path.c:1152 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CopyFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CopyFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CopyFileExA(LPCSTR  sourceFilename, LPCSTR  destFilename, LPPROGRESS_ROUTINE  progressRoutine, LPVOID  appData, LPBOOL  cancelFlagPointer, DWORD  copyFlags) /* ../dlls/kernel32/path.c:1265 */
{
	TRACE("Enter CopyFileExA\n");
	return pCopyFileExA(sourceFilename, destFilename, progressRoutine, appData, cancelFlagPointer, copyFlags);
}

extern WINAPI void wine32a_kernel32_CopyFileExA(void);  /* ../dlls/kernel32/path.c:1265 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CopyFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CopyFileExA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CopyFileExW(LPCWSTR  source, LPCWSTR  dest, LPPROGRESS_ROUTINE  progress, LPVOID  param, LPBOOL  cancel_ptr, DWORD  flags) /* ../dlls/kernel32/path.c:1170 */
{
	TRACE("Enter CopyFileExW\n");
	return pCopyFileExW(source, dest, progress, param, cancel_ptr, flags);
}

extern WINAPI void wine32a_kernel32_CopyFileExW(void);  /* ../dlls/kernel32/path.c:1170 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CopyFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CopyFileExW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CopyFileW(LPCWSTR  source, LPCWSTR  dest, BOOL  fail_if_exists) /* ../dlls/kernel32/path.c:1142 */
{
	TRACE("Enter CopyFileW\n");
	return pCopyFileW(source, dest, fail_if_exists);
}

extern WINAPI void wine32a_kernel32_CopyFileW(void);  /* ../dlls/kernel32/path.c:1142 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CopyFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CopyFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateActCtxA(PCACTCTXA  pActCtx) /* ../dlls/kernel32/actctx.c:41 */
{
	TRACE("Enter CreateActCtxA\n");
	return pCreateActCtxA(pActCtx);
}

extern WINAPI void wine32a_kernel32_CreateActCtxA(void);  /* ../dlls/kernel32/actctx.c:41 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateActCtxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateActCtxA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateDirectoryExA(LPCSTR  template, LPCSTR  path, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernel32/path.c:1610 */
{
	TRACE("Enter CreateDirectoryExA\n");
	return pCreateDirectoryExA(template, path, sa);
}

extern WINAPI void wine32a_kernel32_CreateDirectoryExA(void);  /* ../dlls/kernel32/path.c:1610 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateDirectoryExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateDirectoryExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateFileMappingA(HANDLE  file, SECURITY_ATTRIBUTES*  sa, DWORD  protect, DWORD  size_high, DWORD  size_low, LPCSTR  name) /* ../dlls/kernel32/sync.c:483 */
{
	TRACE("Enter CreateFileMappingA\n");
	return pCreateFileMappingA(file, sa, protect, size_high, size_low, name);
}

extern WINAPI void wine32a_kernel32_CreateFileMappingA(void);  /* ../dlls/kernel32/sync.c:483 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateFileMappingA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateFileMappingA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateHardLinkA(LPCSTR  lpFileName, LPCSTR  lpExistingFileName, LPSECURITY_ATTRIBUTES  lpSecurityAttributes) /* ../dlls/kernel32/path.c:1582 */
{
	TRACE("Enter CreateHardLinkA\n");
	return pCreateHardLinkA(lpFileName, lpExistingFileName, lpSecurityAttributes);
}

extern WINAPI void wine32a_kernel32_CreateHardLinkA(void);  /* ../dlls/kernel32/path.c:1582 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateHardLinkA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateHardLinkA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateHardLinkTransactedA(LPCSTR  link, LPCSTR  target, LPSECURITY_ATTRIBUTES  sa, HANDLE  transaction) /* ../dlls/kernel32/path.c:1955 */
{
	TRACE("Enter CreateHardLinkTransactedA\n");
	return pCreateHardLinkTransactedA(link, target, sa, transaction);
}

extern WINAPI void wine32a_kernel32_CreateHardLinkTransactedA(void);  /* ../dlls/kernel32/path.c:1955 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateHardLinkTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateHardLinkTransactedA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateHardLinkTransactedW(LPCWSTR  link, LPCWSTR  target, LPSECURITY_ATTRIBUTES  sa, HANDLE  transaction) /* ../dlls/kernel32/path.c:1965 */
{
	TRACE("Enter CreateHardLinkTransactedW\n");
	return pCreateHardLinkTransactedW(link, target, sa, transaction);
}

extern WINAPI void wine32a_kernel32_CreateHardLinkTransactedW(void);  /* ../dlls/kernel32/path.c:1965 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateHardLinkTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateHardLinkTransactedW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateHardLinkW(LPCWSTR  lpFileName, LPCWSTR  lpExistingFileName, LPSECURITY_ATTRIBUTES  lpSecurityAttributes) /* ../dlls/kernel32/path.c:1525 */
{
	TRACE("Enter CreateHardLinkW\n");
	return pCreateHardLinkW(lpFileName, lpExistingFileName, lpSecurityAttributes);
}

extern WINAPI void wine32a_kernel32_CreateHardLinkW(void);  /* ../dlls/kernel32/path.c:1525 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateHardLinkW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateHardLinkW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateJobObjectA(LPSECURITY_ATTRIBUTES  attr, LPCSTR  name) /* ../dlls/kernel32/sync.c:292 */
{
	TRACE("Enter CreateJobObjectA\n");
	return pCreateJobObjectA(attr, name);
}

extern WINAPI void wine32a_kernel32_CreateJobObjectA(void);  /* ../dlls/kernel32/sync.c:292 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateJobObjectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateJobObjectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateJobObjectW(LPSECURITY_ATTRIBUTES  sa, LPCWSTR  name) /* ../dlls/kernel32/sync.c:272 */
{
	TRACE("Enter CreateJobObjectW\n");
	return pCreateJobObjectW(sa, name);
}

extern WINAPI void wine32a_kernel32_CreateJobObjectW(void);  /* ../dlls/kernel32/sync.c:272 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateJobObjectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateJobObjectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateMailslotA(LPCSTR  lpName, DWORD  nMaxMessageSize, DWORD  lReadTimeout, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernel32/sync.c:816 */
{
	TRACE("Enter CreateMailslotA\n");
	return pCreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, sa);
}

extern WINAPI void wine32a_kernel32_CreateMailslotA(void);  /* ../dlls/kernel32/sync.c:816 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateMailslotA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateMailslotA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateMailslotW(LPCWSTR  lpName, DWORD  nMaxMessageSize, DWORD  lReadTimeout, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/kernel32/sync.c:856 */
{
	TRACE("Enter CreateMailslotW\n");
	return pCreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, sa);
}

extern WINAPI void wine32a_kernel32_CreateMailslotW(void);  /* ../dlls/kernel32/sync.c:856 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateMailslotW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateMailslotW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateNamedPipeA(LPCSTR  name, DWORD  dwOpenMode, DWORD  dwPipeMode, DWORD  nMaxInstances, DWORD  nOutBufferSize, DWORD  nInBufferSize, DWORD  nDefaultTimeOut, LPSECURITY_ATTRIBUTES  attr) /* ../dlls/kernel32/sync.c:525 */
{
	TRACE("Enter CreateNamedPipeA\n");
	return pCreateNamedPipeA(name, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, attr);
}

extern WINAPI void wine32a_kernel32_CreateNamedPipeA(void);  /* ../dlls/kernel32/sync.c:525 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateNamedPipeA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreatePipe(PHANDLE  hReadPipe, PHANDLE  hWritePipe, LPSECURITY_ATTRIBUTES  sa, DWORD  size) /* ../dlls/kernel32/sync.c:746 */
{
	TRACE("Enter CreatePipe\n");
	return pCreatePipe(hReadPipe, hWritePipe, sa, size);
}

extern WINAPI void wine32a_kernel32_CreatePipe(void);  /* ../dlls/kernel32/sync.c:746 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreatePipe,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreatePipe") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateProcessA(LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info) /* ../dlls/kernel32/process.c:2911 */
{
	TRACE("Enter CreateProcessA\n");
	return pCreateProcessA(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_kernel32_CreateProcessA(void);  /* ../dlls/kernel32/process.c:2911 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateProcessAsUserA(HANDLE  token, LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info) /* ../dlls/kernel32/process.c:2937 */
{
	TRACE("Enter CreateProcessAsUserA\n");
	return pCreateProcessAsUserA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_kernel32_CreateProcessAsUserA(void);  /* ../dlls/kernel32/process.c:2937 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessAsUserA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessAsUserA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateProcessAsUserW(HANDLE  token, LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info) /* ../dlls/kernel32/process.c:2952 */
{
	TRACE("Enter CreateProcessAsUserW\n");
	return pCreateProcessAsUserW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_kernel32_CreateProcessAsUserW(void);  /* ../dlls/kernel32/process.c:2952 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessAsUserW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessAsUserW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateProcessInternalA(HANDLE  token, LPCSTR  app_name, LPSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCSTR  cur_dir, LPSTARTUPINFOA  startup_info, LPPROCESS_INFORMATION  info, HANDLE*  new_token) /* ../dlls/kernel32/process.c:2868 */
{
	TRACE("Enter CreateProcessInternalA\n");
	return pCreateProcessInternalA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
}

extern WINAPI void wine32a_kernel32_CreateProcessInternalA(void);  /* ../dlls/kernel32/process.c:2868 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessInternalA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessInternalA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateProcessInternalW(HANDLE  token, LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info, HANDLE*  new_token) /* ../dlls/kernel32/process.c:2726 */
{
	TRACE("Enter CreateProcessInternalW\n");
	return pCreateProcessInternalW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
}

extern WINAPI void wine32a_kernel32_CreateProcessInternalW(void);  /* ../dlls/kernel32/process.c:2726 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessInternalW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessInternalW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_CreateProcessW(LPCWSTR  app_name, LPWSTR  cmd_line, LPSECURITY_ATTRIBUTES  process_attr, LPSECURITY_ATTRIBUTES  thread_attr, BOOL  inherit, DWORD  flags, LPVOID  env, LPCWSTR  cur_dir, LPSTARTUPINFOW  startup_info, LPPROCESS_INFORMATION  info) /* ../dlls/kernel32/process.c:2924 */
{
	TRACE("Enter CreateProcessW\n");
	return pCreateProcessW(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
}

extern WINAPI void wine32a_kernel32_CreateProcessW(void);  /* ../dlls/kernel32/process.c:2924 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateProcessW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateProcessW") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_CreateSemaphoreA(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCSTR  name) /* ../dlls/kernel32/sync.c:222 */
{
	TRACE("Enter CreateSemaphoreA\n");
	return pCreateSemaphoreA(sa, initial, max, name);
}

extern WINAPI void wine32a_kernel32_CreateSemaphoreA(void);  /* ../dlls/kernel32/sync.c:222 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateSemaphoreA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateSemaphoreA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateSemaphoreExA(SECURITY_ATTRIBUTES*  sa, LONG  initial, LONG  max, LPCSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernel32/sync.c:231 */
{
	TRACE("Enter CreateSemaphoreExA\n");
	return pCreateSemaphoreExA(sa, initial, max, name, flags, access);
}

extern WINAPI void wine32a_kernel32_CreateSemaphoreExA(void);  /* ../dlls/kernel32/sync.c:231 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateSemaphoreExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateSemaphoreExA") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_CreateSocketHandle(void) /* ../dlls/kernel32/process.c:3374 */
{
	TRACE("Enter CreateSocketHandle\n");
	return pCreateSocketHandle();
}

extern WINAPI void wine32a_kernel32_CreateSocketHandle(void);  /* ../dlls/kernel32/process.c:3374 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateSocketHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateSocketHandle") "\n"
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

extern WINAPI BOOLEAN wine32b_kernel32_CreateSymbolicLinkA(LPCSTR  link, LPCSTR  target, DWORD  flags) /* ../dlls/kernel32/path.c:1946 */
{
	TRACE("Enter CreateSymbolicLinkA\n");
	return pCreateSymbolicLinkA(link, target, flags);
}

extern WINAPI void wine32a_kernel32_CreateSymbolicLinkA(void);  /* ../dlls/kernel32/path.c:1946 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateSymbolicLinkA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateSymbolicLinkA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_kernel32_CreateSymbolicLinkW(LPCWSTR  link, LPCWSTR  target, DWORD  flags) /* ../dlls/kernel32/path.c:1937 */
{
	TRACE("Enter CreateSymbolicLinkW\n");
	return pCreateSymbolicLinkW(link, target, flags);
}

extern WINAPI void wine32a_kernel32_CreateSymbolicLinkW(void);  /* ../dlls/kernel32/path.c:1937 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateSymbolicLinkW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateSymbolicLinkW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_CreateTapePartition(HANDLE  device, DWORD  method, DWORD  count, DWORD  size) /* ../dlls/kernel32/tape.c:96 */
{
	TRACE("Enter CreateTapePartition\n");
	return pCreateTapePartition(device, method, count, size);
}

extern WINAPI void wine32a_kernel32_CreateTapePartition(void);  /* ../dlls/kernel32/tape.c:96 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateTapePartition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateTapePartition") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateToolhelp32Snapshot(DWORD  flags, DWORD  process) /* ../dlls/kernel32/toolhelp.c:293 */
{
	TRACE("Enter CreateToolhelp32Snapshot\n");
	return pCreateToolhelp32Snapshot(flags, process);
}

extern WINAPI void wine32a_kernel32_CreateToolhelp32Snapshot(void);  /* ../dlls/kernel32/toolhelp.c:293 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateToolhelp32Snapshot,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateToolhelp32Snapshot") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateUmsCompletionList(PUMS_COMPLETION_LIST*  list) /* ../dlls/kernel32/process.c:4126 */
{
	TRACE("Enter CreateUmsCompletionList\n");
	return pCreateUmsCompletionList(list);
}

extern WINAPI void wine32a_kernel32_CreateUmsCompletionList(void);  /* ../dlls/kernel32/process.c:4126 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateUmsCompletionList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateUmsCompletionList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_CreateUmsThreadContext(PUMS_CONTEXT*  ctx) /* ../dlls/kernel32/process.c:4136 */
{
	TRACE("Enter CreateUmsThreadContext\n");
	return pCreateUmsThreadContext(ctx);
}

extern WINAPI void wine32a_kernel32_CreateUmsThreadContext(void);  /* ../dlls/kernel32/process.c:4136 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateUmsThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateUmsThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateWaitableTimerA(SECURITY_ATTRIBUTES*  sa, BOOL  manual, LPCSTR  name) /* ../dlls/kernel32/sync.c:414 */
{
	TRACE("Enter CreateWaitableTimerA\n");
	return pCreateWaitableTimerA(sa, manual, name);
}

extern WINAPI void wine32a_kernel32_CreateWaitableTimerA(void);  /* ../dlls/kernel32/sync.c:414 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateWaitableTimerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateWaitableTimerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_CreateWaitableTimerExA(SECURITY_ATTRIBUTES*  sa, LPCSTR  name, DWORD  flags, DWORD  access) /* ../dlls/kernel32/sync.c:424 */
{
	TRACE("Enter CreateWaitableTimerExA\n");
	return pCreateWaitableTimerExA(sa, name, flags, access);
}

extern WINAPI void wine32a_kernel32_CreateWaitableTimerExA(void);  /* ../dlls/kernel32/sync.c:424 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_CreateWaitableTimerExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_CreateWaitableTimerExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DebugBreakProcess(HANDLE  process) /* ../dlls/kernel32/debugger.c:49 */
{
	TRACE("Enter DebugBreakProcess\n");
	return pDebugBreakProcess(process);
}

extern WINAPI void wine32a_kernel32_DebugBreakProcess(void);  /* ../dlls/kernel32/debugger.c:49 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DebugBreakProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DebugBreakProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DebugSetProcessKillOnExit(BOOL  kill) /* ../dlls/kernel32/debugger.c:73 */
{
	TRACE("Enter DebugSetProcessKillOnExit\n");
	return pDebugSetProcessKillOnExit(kill);
}

extern WINAPI void wine32a_kernel32_DebugSetProcessKillOnExit(void);  /* ../dlls/kernel32/debugger.c:73 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DebugSetProcessKillOnExit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DebugSetProcessKillOnExit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DefineDosDeviceA(DWORD  flags, LPCSTR  devname, LPCSTR  targetpath) /* ../dlls/kernel32/volume.c:1210 */
{
	TRACE("Enter DefineDosDeviceA\n");
	return pDefineDosDeviceA(flags, devname, targetpath);
}

extern WINAPI void wine32a_kernel32_DefineDosDeviceA(void);  /* ../dlls/kernel32/volume.c:1210 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DefineDosDeviceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DefineDosDeviceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DefineDosDeviceW(DWORD  flags, LPCWSTR  devname, LPCWSTR  targetpath) /* ../dlls/kernel32/volume.c:1137 */
{
	TRACE("Enter DefineDosDeviceW\n");
	return pDefineDosDeviceW(flags, devname, targetpath);
}

extern WINAPI void wine32a_kernel32_DefineDosDeviceW(void);  /* ../dlls/kernel32/volume.c:1137 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DefineDosDeviceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DefineDosDeviceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI FARPROC wine32b_kernel32_DelayLoadFailureHook(LPCSTR  name, LPCSTR  function) /* ../dlls/kernel32/module.c:1024 */
{
	TRACE("Enter DelayLoadFailureHook\n");
	return pDelayLoadFailureHook(name, function);
}

extern WINAPI void wine32a_kernel32_DelayLoadFailureHook(void);  /* ../dlls/kernel32/module.c:1024 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DelayLoadFailureHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DelayLoadFailureHook") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_DeleteAtom(ATOM  atom) /* ../dlls/kernel32/atom.c:255 */
{
	TRACE("Enter DeleteAtom\n");
	return pDeleteAtom(atom);
}

extern WINAPI void wine32a_kernel32_DeleteAtom(void);  /* ../dlls/kernel32/atom.c:255 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeleteTimerQueue(HANDLE  TimerQueue) /* ../dlls/kernel32/sync.c:460 */
{
	TRACE("Enter DeleteTimerQueue\n");
	return pDeleteTimerQueue(TimerQueue);
}

extern WINAPI void wine32a_kernel32_DeleteTimerQueue(void);  /* ../dlls/kernel32/sync.c:460 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteTimerQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteTimerQueue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeleteUmsCompletionList(PUMS_COMPLETION_LIST  list) /* ../dlls/kernel32/process.c:4146 */
{
	TRACE("Enter DeleteUmsCompletionList\n");
	return pDeleteUmsCompletionList(list);
}

extern WINAPI void wine32a_kernel32_DeleteUmsCompletionList(void);  /* ../dlls/kernel32/process.c:4146 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteUmsCompletionList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteUmsCompletionList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeleteUmsThreadContext(PUMS_CONTEXT  ctx) /* ../dlls/kernel32/process.c:4156 */
{
	TRACE("Enter DeleteUmsThreadContext\n");
	return pDeleteUmsThreadContext(ctx);
}

extern WINAPI void wine32a_kernel32_DeleteUmsThreadContext(void);  /* ../dlls/kernel32/process.c:4156 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteUmsThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteUmsThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeleteVolumeMountPointA(LPCSTR  mountpoint) /* ../dlls/kernel32/volume.c:2126 */
{
	TRACE("Enter DeleteVolumeMountPointA\n");
	return pDeleteVolumeMountPointA(mountpoint);
}

extern WINAPI void wine32a_kernel32_DeleteVolumeMountPointA(void);  /* ../dlls/kernel32/volume.c:2126 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeleteVolumeMountPointW(LPCWSTR  mountpoint) /* ../dlls/kernel32/volume.c:2135 */
{
	TRACE("Enter DeleteVolumeMountPointW\n");
	return pDeleteVolumeMountPointW(mountpoint);
}

extern WINAPI void wine32a_kernel32_DeleteVolumeMountPointW(void);  /* ../dlls/kernel32/volume.c:2135 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeleteVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeleteVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DequeueUmsCompletionListItems(void*  list, DWORD  timeout, PUMS_CONTEXT*  ctx) /* ../dlls/kernel32/process.c:4166 */
{
	TRACE("Enter DequeueUmsCompletionListItems\n");
	return pDequeueUmsCompletionListItems(list, timeout, ctx);
}

extern WINAPI void wine32a_kernel32_DequeueUmsCompletionListItems(void);  /* ../dlls/kernel32/process.c:4166 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DequeueUmsCompletionListItems,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DequeueUmsCompletionListItems") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DeviceIoControl(HANDLE  hDevice, DWORD  dwIoControlCode, LPVOID  lpvInBuffer, DWORD  cbInBuffer, LPVOID  lpvOutBuffer, DWORD  cbOutBuffer, LPDWORD  lpcbBytesReturned, LPOVERLAPPED  lpOverlapped) /* ../dlls/kernel32/file.c:1096 */
{
	TRACE("Enter DeviceIoControl\n");
	return pDeviceIoControl(hDevice, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped);
}

extern WINAPI void wine32a_kernel32_DeviceIoControl(void);  /* ../dlls/kernel32/file.c:1096 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DeviceIoControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DeviceIoControl") "\n"
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

extern WINAPI BOOL wine32b_kernel32_DnsHostnameToComputerNameA(LPCSTR  hostname, LPSTR  computername, LPDWORD  size) /* ../dlls/kernel32/computername.c:679 */
{
	TRACE("Enter DnsHostnameToComputerNameA\n");
	return pDnsHostnameToComputerNameA(hostname, computername, size);
}

extern WINAPI void wine32a_kernel32_DnsHostnameToComputerNameA(void);  /* ../dlls/kernel32/computername.c:679 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DnsHostnameToComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DnsHostnameToComputerNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DnsHostnameToComputerNameW(LPCWSTR  hostname, LPWSTR  computername, LPDWORD  size) /* ../dlls/kernel32/computername.c:707 */
{
	TRACE("Enter DnsHostnameToComputerNameW\n");
	return pDnsHostnameToComputerNameW(hostname, computername, size);
}

extern WINAPI void wine32a_kernel32_DnsHostnameToComputerNameW(void);  /* ../dlls/kernel32/computername.c:707 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DnsHostnameToComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DnsHostnameToComputerNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DosDateTimeToFileTime(WORD  fatdate, WORD  fattime, LPFILETIME  ft) /* ../dlls/kernel32/time.c:1358 */
{
	TRACE("Enter DosDateTimeToFileTime\n");
	return pDosDateTimeToFileTime(fatdate, fattime, ft);
}

extern WINAPI void wine32a_kernel32_DosDateTimeToFileTime(void);  /* ../dlls/kernel32/time.c:1358 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DosDateTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DosDateTimeToFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_DuplicateConsoleHandle(HANDLE  handle, DWORD  access, BOOL  inherit, DWORD  options) /* ../dlls/kernel32/console.c:274 */
{
	TRACE("Enter DuplicateConsoleHandle\n");
	return pDuplicateConsoleHandle(handle, access, inherit, options);
}

extern WINAPI void wine32a_kernel32_DuplicateConsoleHandle(void);  /* ../dlls/kernel32/console.c:274 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DuplicateConsoleHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DuplicateConsoleHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_DuplicateHandle(HANDLE  source_process, HANDLE  source, HANDLE  dest_process, HANDLE*  dest, DWORD  access, BOOL  inherit, DWORD  options) /* ../dlls/kernel32/process.c:3310 */
{
	TRACE("Enter DuplicateHandle\n");
	return pDuplicateHandle(source_process, source, dest_process, dest, access, inherit, options);
}

extern WINAPI void wine32a_kernel32_DuplicateHandle(void);  /* ../dlls/kernel32/process.c:3310 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_DuplicateHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_DuplicateHandle") "\n"
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

extern WINAPI BOOL wine32b_kernel32_EndUpdateResourceA(HANDLE  hUpdate, BOOL  fDiscard) /* ../dlls/kernel32/resource.c:1280 */
{
	TRACE("Enter EndUpdateResourceA\n");
	return pEndUpdateResourceA(hUpdate, fDiscard);
}

extern WINAPI void wine32a_kernel32_EndUpdateResourceA(void);  /* ../dlls/kernel32/resource.c:1280 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EndUpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EndUpdateResourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EndUpdateResourceW(HANDLE  hUpdate, BOOL  fDiscard) /* ../dlls/kernel32/resource.c:1254 */
{
	TRACE("Enter EndUpdateResourceW\n");
	return pEndUpdateResourceW(hUpdate, fDiscard);
}

extern WINAPI void wine32a_kernel32_EndUpdateResourceW(void);  /* ../dlls/kernel32/resource.c:1254 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EndUpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EndUpdateResourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumCalendarInfoA(CALINFO_ENUMPROCA  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype) /* ../dlls/kernel32/lcformat.c:2230 */
{
	TRACE("Enter EnumCalendarInfoA\n");
	return pEnumCalendarInfoA(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_kernel32_EnumCalendarInfoA(void);  /* ../dlls/kernel32/lcformat.c:2230 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumCalendarInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExA(CALINFO_ENUMPROCEXA  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype) /* ../dlls/kernel32/lcformat.c:2270 */
{
	TRACE("Enter EnumCalendarInfoExA\n");
	return pEnumCalendarInfoExA(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_kernel32_EnumCalendarInfoExA(void);  /* ../dlls/kernel32/lcformat.c:2270 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumCalendarInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumCalendarInfoExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExEx(CALINFO_ENUMPROCEXEX  calinfoproc, LPCWSTR  locale, CALID  calendar, LPCWSTR  reserved, CALTYPE  caltype, LPARAM  lParam) /* ../dlls/kernel32/lcformat.c:2310 */
{
	TRACE("Enter EnumCalendarInfoExEx\n");
	return pEnumCalendarInfoExEx(calinfoproc, locale, calendar, reserved, caltype, lParam);
}

extern WINAPI void wine32a_kernel32_EnumCalendarInfoExEx(void);  /* ../dlls/kernel32/lcformat.c:2310 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumCalendarInfoExEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumCalendarInfoExEx") "\n"
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

extern WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExW(CALINFO_ENUMPROCEXW  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype) /* ../dlls/kernel32/lcformat.c:2290 */
{
	TRACE("Enter EnumCalendarInfoExW\n");
	return pEnumCalendarInfoExW(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_kernel32_EnumCalendarInfoExW(void);  /* ../dlls/kernel32/lcformat.c:2290 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumCalendarInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumCalendarInfoExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumCalendarInfoW(CALINFO_ENUMPROCW  calinfoproc, LCID  locale, CALID  calendar, CALTYPE  caltype) /* ../dlls/kernel32/lcformat.c:2250 */
{
	TRACE("Enter EnumCalendarInfoW\n");
	return pEnumCalendarInfoW(calinfoproc, locale, calendar, caltype);
}

extern WINAPI void wine32a_kernel32_EnumCalendarInfoW(void);  /* ../dlls/kernel32/lcformat.c:2250 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumCalendarInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumDateFormatsA(DATEFMT_ENUMPROCA  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:1910 */
{
	TRACE("Enter EnumDateFormatsA\n");
	return pEnumDateFormatsA(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumDateFormatsA(void);  /* ../dlls/kernel32/lcformat.c:1910 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumDateFormatsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumDateFormatsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumDateFormatsExA(DATEFMT_ENUMPROCEXA  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:1875 */
{
	TRACE("Enter EnumDateFormatsExA\n");
	return pEnumDateFormatsExA(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumDateFormatsExA(void);  /* ../dlls/kernel32/lcformat.c:1875 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumDateFormatsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumDateFormatsExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumDateFormatsExEx(DATEFMT_ENUMPROCEXEX  proc, WCHAR*  locale, DWORD  flags, LPARAM  lParam) /* ../dlls/kernel32/lcformat.c:1942 */
{
	TRACE("Enter EnumDateFormatsExEx\n");
	return pEnumDateFormatsExEx(proc, locale, flags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumDateFormatsExEx(void);  /* ../dlls/kernel32/lcformat.c:1942 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumDateFormatsExEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumDateFormatsExEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumDateFormatsExW(DATEFMT_ENUMPROCEXW  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:1891 */
{
	TRACE("Enter EnumDateFormatsExW\n");
	return pEnumDateFormatsExW(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumDateFormatsExW(void);  /* ../dlls/kernel32/lcformat.c:1891 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumDateFormatsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumDateFormatsExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumDateFormatsW(DATEFMT_ENUMPROCW  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:1926 */
{
	TRACE("Enter EnumDateFormatsW\n");
	return pEnumDateFormatsW(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumDateFormatsW(void);  /* ../dlls/kernel32/lcformat.c:1926 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumDateFormatsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumDateFormatsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumLanguageGroupLocalesA(LANGGROUPLOCALE_ENUMPROCA  pLangGrpLcEnumProc, LGRPID  lgrpid, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4553 */
{
	TRACE("Enter EnumLanguageGroupLocalesA\n");
	return pEnumLanguageGroupLocalesA(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumLanguageGroupLocalesA(void);  /* ../dlls/kernel32/locale.c:4553 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumLanguageGroupLocalesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumLanguageGroupLocalesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumLanguageGroupLocalesW(LANGGROUPLOCALE_ENUMPROCW  pLangGrpLcEnumProc, LGRPID  lgrpid, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4574 */
{
	TRACE("Enter EnumLanguageGroupLocalesW\n");
	return pEnumLanguageGroupLocalesW(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumLanguageGroupLocalesW(void);  /* ../dlls/kernel32/locale.c:4574 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumLanguageGroupLocalesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumLanguageGroupLocalesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumResourceLanguagesA(HMODULE  hmod, LPCSTR  type, LPCSTR  name, ENUMRESLANGPROCA  lpfun, LONG_PTR  lparam) /* ../dlls/kernel32/resource.c:139 */
{
	TRACE("Enter EnumResourceLanguagesA\n");
	return pEnumResourceLanguagesA(hmod, type, name, lpfun, lparam);
}

extern WINAPI void wine32a_kernel32_EnumResourceLanguagesA(void);  /* ../dlls/kernel32/resource.c:139 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumResourceLanguagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumResourceLanguagesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumResourceLanguagesW(HMODULE  hmod, LPCWSTR  type, LPCWSTR  name, ENUMRESLANGPROCW  lpfun, LONG_PTR  lparam) /* ../dlls/kernel32/resource.c:149 */
{
	TRACE("Enter EnumResourceLanguagesW\n");
	return pEnumResourceLanguagesW(hmod, type, name, lpfun, lparam);
}

extern WINAPI void wine32a_kernel32_EnumResourceLanguagesW(void);  /* ../dlls/kernel32/resource.c:149 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumResourceLanguagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumResourceLanguagesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumResourceNamesA(HMODULE  hmod, LPCSTR  type, ENUMRESNAMEPROCA  lpfun, LONG_PTR  lparam) /* ../dlls/kernel32/resource.c:130 */
{
	TRACE("Enter EnumResourceNamesA\n");
	return pEnumResourceNamesA(hmod, type, lpfun, lparam);
}

extern WINAPI void wine32a_kernel32_EnumResourceNamesA(void);  /* ../dlls/kernel32/resource.c:130 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumResourceNamesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumResourceNamesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumResourceTypesA(HMODULE  hmod, ENUMRESTYPEPROCA  lpfun, LONG_PTR  lparam) /* ../dlls/kernel32/resource.c:112 */
{
	TRACE("Enter EnumResourceTypesA\n");
	return pEnumResourceTypesA(hmod, lpfun, lparam);
}

extern WINAPI void wine32a_kernel32_EnumResourceTypesA(void);  /* ../dlls/kernel32/resource.c:112 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumResourceTypesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumResourceTypesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumResourceTypesW(HMODULE  hmod, ENUMRESTYPEPROCW  lpfun, LONG_PTR  lparam) /* ../dlls/kernel32/resource.c:121 */
{
	TRACE("Enter EnumResourceTypesW\n");
	return pEnumResourceTypesW(hmod, lpfun, lparam);
}

extern WINAPI void wine32a_kernel32_EnumResourceTypesW(void);  /* ../dlls/kernel32/resource.c:121 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumResourceTypesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumResourceTypesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemCodePagesA(CODEPAGE_ENUMPROCA  lpfnCodePageEnum, DWORD  flags) /* ../dlls/kernel32/locale.c:2262 */
{
	TRACE("Enter EnumSystemCodePagesA\n");
	return pEnumSystemCodePagesA(lpfnCodePageEnum, flags);
}

extern WINAPI void wine32a_kernel32_EnumSystemCodePagesA(void);  /* ../dlls/kernel32/locale.c:2262 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemCodePagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemCodePagesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemCodePagesW(CODEPAGE_ENUMPROCW  lpfnCodePageEnum, DWORD  flags) /* ../dlls/kernel32/locale.c:2283 */
{
	TRACE("Enter EnumSystemCodePagesW\n");
	return pEnumSystemCodePagesW(lpfnCodePageEnum, flags);
}

extern WINAPI void wine32a_kernel32_EnumSystemCodePagesW(void);  /* ../dlls/kernel32/locale.c:2283 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemCodePagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemCodePagesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_EnumSystemFirmwareTables(DWORD  provider, void*  buffer, DWORD  size) /* ../dlls/kernel32/cpu.c:328 */
{
	TRACE("Enter EnumSystemFirmwareTables\n");
	return pEnumSystemFirmwareTables(provider, buffer, size);
}

extern WINAPI void wine32a_kernel32_EnumSystemFirmwareTables(void);  /* ../dlls/kernel32/cpu.c:328 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemFirmwareTables,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemFirmwareTables") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemGeoID(GEOCLASS  geoclass, GEOID  parent, GEO_ENUMPROC  enumproc) /* ../dlls/kernel32/locale.c:5228 */
{
	TRACE("Enter EnumSystemGeoID\n");
	return pEnumSystemGeoID(geoclass, parent, enumproc);
}

extern WINAPI void wine32a_kernel32_EnumSystemGeoID(void);  /* ../dlls/kernel32/locale.c:5228 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemGeoID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA  pLangGrpEnumProc, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4354 */
{
	TRACE("Enter EnumSystemLanguageGroupsA\n");
	return pEnumSystemLanguageGroupsA(pLangGrpEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumSystemLanguageGroupsA(void);  /* ../dlls/kernel32/locale.c:4354 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemLanguageGroupsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemLanguageGroupsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW  pLangGrpEnumProc, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4374 */
{
	TRACE("Enter EnumSystemLanguageGroupsW\n");
	return pEnumSystemLanguageGroupsW(pLangGrpEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumSystemLanguageGroupsW(void);  /* ../dlls/kernel32/locale.c:4374 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemLanguageGroupsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemLanguageGroupsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemLocalesA(LOCALE_ENUMPROCA  lpfnLocaleEnum, DWORD  dwFlags) /* ../dlls/kernel32/locale.c:2976 */
{
	TRACE("Enter EnumSystemLocalesA\n");
	return pEnumSystemLocalesA(lpfnLocaleEnum, dwFlags);
}

extern WINAPI void wine32a_kernel32_EnumSystemLocalesA(void);  /* ../dlls/kernel32/locale.c:2976 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemLocalesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemLocalesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemLocalesEx(LOCALE_ENUMPROCEX  proc, DWORD  flags, LPARAM  lparam, LPVOID  reserved) /* ../dlls/kernel32/locale.c:3031 */
{
	TRACE("Enter EnumSystemLocalesEx\n");
	return pEnumSystemLocalesEx(proc, flags, lparam, reserved);
}

extern WINAPI void wine32a_kernel32_EnumSystemLocalesEx(void);  /* ../dlls/kernel32/locale.c:3031 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemLocalesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemLocalesEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumSystemLocalesW(LOCALE_ENUMPROCW  lpfnLocaleEnum, DWORD  dwFlags) /* ../dlls/kernel32/locale.c:2991 */
{
	TRACE("Enter EnumSystemLocalesW\n");
	return pEnumSystemLocalesW(lpfnLocaleEnum, dwFlags);
}

extern WINAPI void wine32a_kernel32_EnumSystemLocalesW(void);  /* ../dlls/kernel32/locale.c:2991 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumSystemLocalesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumSystemLocalesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumTimeFormatsA(TIMEFMT_ENUMPROCA  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:2025 */
{
	TRACE("Enter EnumTimeFormatsA\n");
	return pEnumTimeFormatsA(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumTimeFormatsA(void);  /* ../dlls/kernel32/lcformat.c:2025 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumTimeFormatsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumTimeFormatsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumTimeFormatsEx(TIMEFMT_ENUMPROCEX  proc, WCHAR*  locale, DWORD  flags, LPARAM  lParam) /* ../dlls/kernel32/lcformat.c:2064 */
{
	TRACE("Enter EnumTimeFormatsEx\n");
	return pEnumTimeFormatsEx(proc, locale, flags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumTimeFormatsEx(void);  /* ../dlls/kernel32/lcformat.c:2064 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumTimeFormatsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumTimeFormatsEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumTimeFormatsW(TIMEFMT_ENUMPROCW  proc, LCID  lcid, DWORD  flags) /* ../dlls/kernel32/lcformat.c:2048 */
{
	TRACE("Enter EnumTimeFormatsW\n");
	return pEnumTimeFormatsW(proc, lcid, flags);
}

extern WINAPI void wine32a_kernel32_EnumTimeFormatsW(void);  /* ../dlls/kernel32/lcformat.c:2048 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumTimeFormatsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumTimeFormatsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumUILanguagesA(UILANGUAGE_ENUMPROCA  pUILangEnumProc, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4718 */
{
	TRACE("Enter EnumUILanguagesA\n");
	return pEnumUILanguagesA(pUILangEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumUILanguagesA(void);  /* ../dlls/kernel32/locale.c:4718 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumUILanguagesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumUILanguagesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnumUILanguagesW(UILANGUAGE_ENUMPROCW  pUILangEnumProc, DWORD  dwFlags, LONG_PTR  lParam) /* ../dlls/kernel32/locale.c:4746 */
{
	TRACE("Enter EnumUILanguagesW\n");
	return pEnumUILanguagesW(pUILangEnumProc, dwFlags, lParam);
}

extern WINAPI void wine32a_kernel32_EnumUILanguagesW(void);  /* ../dlls/kernel32/locale.c:4746 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnumUILanguagesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnumUILanguagesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_EnterUmsSchedulingMode(UMS_SCHEDULER_STARTUP_INFO*  info) /* ../dlls/kernel32/process.c:4176 */
{
	TRACE("Enter EnterUmsSchedulingMode\n");
	return pEnterUmsSchedulingMode(info);
}

extern WINAPI void wine32a_kernel32_EnterUmsSchedulingMode(void);  /* ../dlls/kernel32/process.c:4176 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EnterUmsSchedulingMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EnterUmsSchedulingMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_EraseTape(HANDLE  device, DWORD  type, BOOL  immediate) /* ../dlls/kernel32/tape.c:121 */
{
	TRACE("Enter EraseTape\n");
	return pEraseTape(device, type, immediate);
}

extern WINAPI void wine32a_kernel32_EraseTape(void);  /* ../dlls/kernel32/tape.c:121 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_EraseTape,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_EraseTape") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_ExecuteUmsThread(PUMS_CONTEXT  ctx) /* ../dlls/kernel32/process.c:4186 */
{
	TRACE("Enter ExecuteUmsThread\n");
	return pExecuteUmsThread(ctx);
}

extern WINAPI void wine32a_kernel32_ExecuteUmsThread(void);  /* ../dlls/kernel32/process.c:4186 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ExecuteUmsThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ExecuteUmsThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_ExitProcess(DWORD  status) /* ../dlls/kernel32/process.c:3158 */
{
	TRACE("Enter ExitProcess\n");
	return pExitProcess(status);
}

extern WINAPI void wine32a_kernel32_ExitProcess(void);  /* ../dlls/kernel32/process.c:3158 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ExitProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ExitProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_ExpungeConsoleCommandHistoryA(LPCSTR  unknown) /* ../dlls/kernel32/console.c:1588 */
{
	TRACE("Enter ExpungeConsoleCommandHistoryA\n");
	return pExpungeConsoleCommandHistoryA(unknown);
}

extern WINAPI void wine32a_kernel32_ExpungeConsoleCommandHistoryA(void);  /* ../dlls/kernel32/console.c:1588 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ExpungeConsoleCommandHistoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ExpungeConsoleCommandHistoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_ExpungeConsoleCommandHistoryW(LPCWSTR  unknown) /* ../dlls/kernel32/console.c:1594 */
{
	TRACE("Enter ExpungeConsoleCommandHistoryW\n");
	return pExpungeConsoleCommandHistoryW(unknown);
}

extern WINAPI void wine32a_kernel32_ExpungeConsoleCommandHistoryW(void);  /* ../dlls/kernel32/console.c:1594 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ExpungeConsoleCommandHistoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ExpungeConsoleCommandHistoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_FatalExit(int  code) /* ../dlls/kernel32/process.c:3198 */
{
	TRACE("Enter FatalExit\n");
	return pFatalExit(code);
}

extern WINAPI void wine32a_kernel32_FatalExit(void);  /* ../dlls/kernel32/process.c:3198 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FatalExit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FatalExit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FileTimeToDosDateTime(FILETIME*  ft, LPWORD  fatdate, LPWORD  fattime) /* ../dlls/kernel32/time.c:1388 */
{
	TRACE("Enter FileTimeToDosDateTime\n");
	return pFileTimeToDosDateTime(ft, fatdate, fattime);
}

extern WINAPI void wine32a_kernel32_FileTimeToDosDateTime(void);  /* ../dlls/kernel32/time.c:1388 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FileTimeToDosDateTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FileTimeToDosDateTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FileTimeToLocalFileTime(FILETIME*  utcft, LPFILETIME  localft) /* ../dlls/kernel32/time.c:1196 */
{
	TRACE("Enter FileTimeToLocalFileTime\n");
	return pFileTimeToLocalFileTime(utcft, localft);
}

extern WINAPI void wine32a_kernel32_FileTimeToLocalFileTime(void);  /* ../dlls/kernel32/time.c:1196 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FileTimeToLocalFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FileTimeToLocalFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FileTimeToSystemTime(FILETIME*  ft, LPSYSTEMTIME  syst) /* ../dlls/kernel32/time.c:1216 */
{
	TRACE("Enter FileTimeToSystemTime\n");
	return pFileTimeToSystemTime(ft, syst);
}

extern WINAPI void wine32a_kernel32_FileTimeToSystemTime(void);  /* ../dlls/kernel32/time.c:1216 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FileTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FileTimeToSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindActCtxSectionStringA(DWORD  dwFlags, GUID*  lpExtGuid, ULONG  ulId, LPCSTR  lpSearchStr, PACTCTX_SECTION_KEYED_DATA  pInfo) /* ../dlls/kernel32/actctx.c:117 */
{
	TRACE("Enter FindActCtxSectionStringA\n");
	return pFindActCtxSectionStringA(dwFlags, lpExtGuid, ulId, lpSearchStr, pInfo);
}

extern WINAPI void wine32a_kernel32_FindActCtxSectionStringA(void);  /* ../dlls/kernel32/actctx.c:117 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindActCtxSectionStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindActCtxSectionStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_FindAtomA(LPCSTR  str) /* ../dlls/kernel32/atom.c:315 */
{
	TRACE("Enter FindAtomA\n");
	return pFindAtomA(str);
}

extern WINAPI void wine32a_kernel32_FindAtomA(void);  /* ../dlls/kernel32/atom.c:315 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_FindAtomW(LPCWSTR  str) /* ../dlls/kernel32/atom.c:368 */
{
	TRACE("Enter FindAtomW\n");
	return pFindAtomW(str);
}

extern WINAPI void wine32a_kernel32_FindAtomW(void);  /* ../dlls/kernel32/atom.c:368 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindClose(HANDLE  handle) /* ../dlls/kernel32/file.c:943 */
{
	TRACE("Enter FindClose\n");
	return pFindClose(handle);
}

extern WINAPI void wine32a_kernel32_FindClose(void);  /* ../dlls/kernel32/file.c:943 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstFileA(LPCSTR  lpFileName, WIN32_FIND_DATAA*  lpFindData) /* ../dlls/kernel32/file.c:988 */
{
	TRACE("Enter FindFirstFileA\n");
	return pFindFirstFileA(lpFileName, lpFindData);
}

extern WINAPI void wine32a_kernel32_FindFirstFileA(void);  /* ../dlls/kernel32/file.c:988 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstFileExA(LPCSTR  lpFileName, FINDEX_INFO_LEVELS  fInfoLevelId, LPVOID  lpFindFileData, FINDEX_SEARCH_OPS  fSearchOp, LPVOID  lpSearchFilter, DWORD  dwAdditionalFlags) /* ../dlls/kernel32/file.c:997 */
{
	TRACE("Enter FindFirstFileExA\n");
	return pFindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags);
}

extern WINAPI void wine32a_kernel32_FindFirstFileExA(void);  /* ../dlls/kernel32/file.c:997 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstFileExA") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_FindFirstFileExW(LPCWSTR  filename, FINDEX_INFO_LEVELS  level, LPVOID  data, FINDEX_SEARCH_OPS  search_op, LPVOID  filter, DWORD  flags) /* ../dlls/kernel32/file.c:656 */
{
	TRACE("Enter FindFirstFileExW\n");
	return pFindFirstFileExW(filename, level, data, search_op, filter, flags);
}

extern WINAPI void wine32a_kernel32_FindFirstFileExW(void);  /* ../dlls/kernel32/file.c:656 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstFileExW") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_FindFirstFileW(LPCWSTR  lpFileName, WIN32_FIND_DATAW*  lpFindData) /* ../dlls/kernel32/file.c:1028 */
{
	TRACE("Enter FindFirstFileW\n");
	return pFindFirstFileW(lpFileName, lpFindData);
}

extern WINAPI void wine32a_kernel32_FindFirstFileW(void);  /* ../dlls/kernel32/file.c:1028 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstStreamW(LPCWSTR  filename, STREAM_INFO_LEVELS  infolevel, void*  data, DWORD  flags) /* ../dlls/kernel32/file.c:1058 */
{
	TRACE("Enter FindFirstStreamW\n");
	return pFindFirstStreamW(filename, infolevel, data, flags);
}

extern WINAPI void wine32a_kernel32_FindFirstStreamW(void);  /* ../dlls/kernel32/file.c:1058 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstStreamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstStreamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstVolumeA(LPSTR  volume, DWORD  len) /* ../dlls/kernel32/volume.c:1977 */
{
	TRACE("Enter FindFirstVolumeA\n");
	return pFindFirstVolumeA(volume, len);
}

extern WINAPI void wine32a_kernel32_FindFirstVolumeA(void);  /* ../dlls/kernel32/volume.c:1977 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstVolumeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstVolumeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstVolumeMountPointA(LPCSTR  root, LPSTR  mount_point, DWORD  len) /* ../dlls/kernel32/volume.c:2097 */
{
	TRACE("Enter FindFirstVolumeMountPointA\n");
	return pFindFirstVolumeMountPointA(root, mount_point, len);
}

extern WINAPI void wine32a_kernel32_FindFirstVolumeMountPointA(void);  /* ../dlls/kernel32/volume.c:2097 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstVolumeMountPointW(LPCWSTR  root, LPWSTR  mount_point, DWORD  len) /* ../dlls/kernel32/volume.c:2107 */
{
	TRACE("Enter FindFirstVolumeMountPointW\n");
	return pFindFirstVolumeMountPointW(root, mount_point, len);
}

extern WINAPI void wine32a_kernel32_FindFirstVolumeMountPointW(void);  /* ../dlls/kernel32/volume.c:2107 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_FindFirstVolumeW(LPWSTR  volume, DWORD  len) /* ../dlls/kernel32/volume.c:1997 */
{
	TRACE("Enter FindFirstVolumeW\n");
	return pFindFirstVolumeW(volume, len);
}

extern WINAPI void wine32a_kernel32_FindFirstVolumeW(void);  /* ../dlls/kernel32/volume.c:1997 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindFirstVolumeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindFirstVolumeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindNextFileA(HANDLE  handle, WIN32_FIND_DATAA*  data) /* ../dlls/kernel32/file.c:1038 */
{
	TRACE("Enter FindNextFileA\n");
	return pFindNextFileA(handle, data);
}

extern WINAPI void wine32a_kernel32_FindNextFileA(void);  /* ../dlls/kernel32/file.c:1038 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNextFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNextFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindNextFileW(HANDLE  handle, WIN32_FIND_DATAW*  data) /* ../dlls/kernel32/file.c:837 */
{
	TRACE("Enter FindNextFileW\n");
	return pFindNextFileW(handle, data);
}

extern WINAPI void wine32a_kernel32_FindNextFileW(void);  /* ../dlls/kernel32/file.c:837 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNextFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNextFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindNextStreamW(HANDLE  handle, void*  data) /* ../dlls/kernel32/file.c:1069 */
{
	TRACE("Enter FindNextStreamW\n");
	return pFindNextStreamW(handle, data);
}

extern WINAPI void wine32a_kernel32_FindNextStreamW(void);  /* ../dlls/kernel32/file.c:1069 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNextStreamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNextStreamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindNextVolumeA(HANDLE  handle, LPSTR  volume, DWORD  len) /* ../dlls/kernel32/volume.c:2042 */
{
	TRACE("Enter FindNextVolumeA\n");
	return pFindNextVolumeA(handle, volume, len);
}

extern WINAPI void wine32a_kernel32_FindNextVolumeA(void);  /* ../dlls/kernel32/volume.c:2042 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNextVolumeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNextVolumeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindNextVolumeW(HANDLE  handle, LPWSTR  volume, DWORD  len) /* ../dlls/kernel32/volume.c:2058 */
{
	TRACE("Enter FindNextVolumeW\n");
	return pFindNextVolumeW(handle, volume, len);
}

extern WINAPI void wine32a_kernel32_FindNextVolumeW(void);  /* ../dlls/kernel32/volume.c:2058 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNextVolumeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNextVolumeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_FindNLSStringEx(WCHAR*  localename, DWORD  flags, WCHAR*  src, INT  src_size, WCHAR*  value, INT  value_size, INT*  found, NLSVERSIONINFO*  version_info, void*  reserved, LPARAM  sort_handle) /* ../dlls/kernel32/locale.c:5910 */
{
	TRACE("Enter FindNLSStringEx\n");
	return pFindNLSStringEx(localename, flags, src, src_size, value, value_size, found, version_info, reserved, sort_handle);
}

extern WINAPI void wine32a_kernel32_FindNLSStringEx(void);  /* ../dlls/kernel32/locale.c:5910 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindNLSStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindNLSStringEx") "\n"
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

extern WINAPI HRSRC wine32b_kernel32_FindResourceA(HMODULE  hModule, LPCSTR  name, LPCSTR  type) /* ../dlls/kernel32/resource.c:103 */
{
	TRACE("Enter FindResourceA\n");
	return pFindResourceA(hModule, name, type);
}

extern WINAPI void wine32a_kernel32_FindResourceA(void);  /* ../dlls/kernel32/resource.c:103 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindResourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRSRC wine32b_kernel32_FindResourceExA(HMODULE  module, LPCSTR  type, LPCSTR  name, WORD  lang) /* ../dlls/kernel32/resource.c:69 */
{
	TRACE("Enter FindResourceExA\n");
	return pFindResourceExA(module, type, name, lang);
}

extern WINAPI void wine32a_kernel32_FindResourceExA(void);  /* ../dlls/kernel32/resource.c:69 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindResourceExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindResourceExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_FindStringOrdinal(DWORD  flag, WCHAR*  src, INT  src_size, WCHAR*  val, INT  val_size, BOOL  ignore_case) /* ../dlls/kernel32/locale.c:5961 */
{
	TRACE("Enter FindStringOrdinal\n");
	return pFindStringOrdinal(flag, src, src_size, val, val_size, ignore_case);
}

extern WINAPI void wine32a_kernel32_FindStringOrdinal(void);  /* ../dlls/kernel32/locale.c:5961 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindStringOrdinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindStringOrdinal") "\n"
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

extern WINAPI BOOL wine32b_kernel32_FindVolumeClose(HANDLE  handle) /* ../dlls/kernel32/volume.c:2089 */
{
	TRACE("Enter FindVolumeClose\n");
	return pFindVolumeClose(handle);
}

extern WINAPI void wine32a_kernel32_FindVolumeClose(void);  /* ../dlls/kernel32/volume.c:2089 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindVolumeClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindVolumeClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FindVolumeMountPointClose(HANDLE  h) /* ../dlls/kernel32/volume.c:2117 */
{
	TRACE("Enter FindVolumeMountPointClose\n");
	return pFindVolumeMountPointClose(h);
}

extern WINAPI void wine32a_kernel32_FindVolumeMountPointClose(void);  /* ../dlls/kernel32/volume.c:2117 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FindVolumeMountPointClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FindVolumeMountPointClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FlushConsoleInputBuffer(HANDLE  handle) /* ../dlls/kernel32/console.c:464 */
{
	TRACE("Enter FlushConsoleInputBuffer\n");
	return pFlushConsoleInputBuffer(handle);
}

extern WINAPI void wine32a_kernel32_FlushConsoleInputBuffer(void);  /* ../dlls/kernel32/console.c:464 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FlushConsoleInputBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FlushConsoleInputBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_FlushProcessWriteBuffers(void) /* ../dlls/kernel32/process.c:4105 */
{
	TRACE("Enter FlushProcessWriteBuffers\n");
	return pFlushProcessWriteBuffers();
}

extern WINAPI void wine32a_kernel32_FlushProcessWriteBuffers(void);  /* ../dlls/kernel32/process.c:4105 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FlushProcessWriteBuffers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FlushProcessWriteBuffers") "\n"
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

extern WINAPI INT wine32b_kernel32_FoldStringA(DWORD  dwFlags, LPCSTR  src, INT  srclen, LPSTR  dst, INT  dstlen) /* ../dlls/kernel32/locale.c:3814 */
{
	TRACE("Enter FoldStringA\n");
	return pFoldStringA(dwFlags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_kernel32_FoldStringA(void);  /* ../dlls/kernel32/locale.c:3814 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FoldStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FoldStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_FoldStringW(DWORD  dwFlags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen) /* ../dlls/kernel32/locale.c:3872 */
{
	TRACE("Enter FoldStringW\n");
	return pFoldStringW(dwFlags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_kernel32_FoldStringW(void);  /* ../dlls/kernel32/locale.c:3872 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FoldStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FoldStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_FormatMessageA(DWORD  dwFlags, LPCVOID  lpSource, DWORD  dwMessageId, DWORD  dwLanguageId, LPSTR  lpBuffer, DWORD  nSize, __builtin_ms_va_list*  args) /* ../dlls/kernel32/format_msg.c:460 */
{
	TRACE("Enter FormatMessageA\n");
	return pFormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
}

extern WINAPI void wine32a_kernel32_FormatMessageA(void);  /* ../dlls/kernel32/format_msg.c:460 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FormatMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FormatMessageA") "\n"
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

extern WINAPI DWORD wine32b_kernel32_FormatMessageW(DWORD  dwFlags, LPCVOID  lpSource, DWORD  dwMessageId, DWORD  dwLanguageId, LPWSTR  lpBuffer, DWORD  nSize, __builtin_ms_va_list*  args) /* ../dlls/kernel32/format_msg.c:560 */
{
	TRACE("Enter FormatMessageW\n");
	return pFormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
}

extern WINAPI void wine32a_kernel32_FormatMessageW(void);  /* ../dlls/kernel32/format_msg.c:560 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FormatMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FormatMessageW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_FreeConsole(void) /* ../dlls/kernel32/console.c:540 */
{
	TRACE("Enter FreeConsole\n");
	return pFreeConsole();
}

extern WINAPI void wine32a_kernel32_FreeConsole(void);  /* ../dlls/kernel32/console.c:540 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FreeConsole,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FreeConsole") "\n"
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

extern WINAPI BOOL wine32b_kernel32_FreeLibrary(HINSTANCE  hLibModule) /* ../dlls/kernel32/module.c:887 */
{
	TRACE("Enter FreeLibrary\n");
	return pFreeLibrary(hLibModule);
}

extern WINAPI void wine32a_kernel32_FreeLibrary(void);  /* ../dlls/kernel32/module.c:887 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FreeLibrary,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FreeLibrary") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_FreeLibraryAndExitThread(HINSTANCE  hLibModule, DWORD  dwExitCode) /* ../dlls/kernel32/thread.c:40 */
{
	TRACE("Enter FreeLibraryAndExitThread\n");
	return pFreeLibraryAndExitThread(hLibModule, dwExitCode);
}

extern WINAPI void wine32a_kernel32_FreeLibraryAndExitThread(void);  /* ../dlls/kernel32/thread.c:40 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FreeLibraryAndExitThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FreeLibraryAndExitThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_FreeUserPhysicalPages(HANDLE  process, ULONG_PTR*  pages, ULONG_PTR*  userarray) /* ../dlls/kernel32/heap.c:936 */
{
	TRACE("Enter FreeUserPhysicalPages\n");
	return pFreeUserPhysicalPages(process, pages, userarray);
}

extern WINAPI void wine32a_kernel32_FreeUserPhysicalPages(void);  /* ../dlls/kernel32/heap.c:936 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_FreeUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_FreeUserPhysicalPages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetACP(void) /* ../dlls/kernel32/locale.c:2009 */
{
	TRACE("Enter GetACP\n");
	return pGetACP();
}

extern WINAPI void wine32a_kernel32_GetACP(void);  /* ../dlls/kernel32/locale.c:2009 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetACP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetACP") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetActiveProcessorCount(WORD  group) /* ../dlls/kernel32/cpu.c:257 */
{
	TRACE("Enter GetActiveProcessorCount\n");
	return pGetActiveProcessorCount(group);
}

extern WINAPI void wine32a_kernel32_GetActiveProcessorCount(void);  /* ../dlls/kernel32/cpu.c:257 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetActiveProcessorCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetActiveProcessorCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_kernel32_GetActiveProcessorGroupCount(void) /* ../dlls/kernel32/cpu.c:248 */
{
	TRACE("Enter GetActiveProcessorGroupCount\n");
	return pGetActiveProcessorGroupCount();
}

extern WINAPI void wine32a_kernel32_GetActiveProcessorGroupCount(void);  /* ../dlls/kernel32/cpu.c:248 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetActiveProcessorGroupCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetActiveProcessorGroupCount") "\n"
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

extern WINAPI HRESULT wine32b_kernel32_GetApplicationRestartSettings(HANDLE  process, WCHAR*  cmdline, DWORD*  size, DWORD*  flags) /* ../dlls/kernel32/process.c:3966 */
{
	TRACE("Enter GetApplicationRestartSettings\n");
	return pGetApplicationRestartSettings(process, cmdline, size, flags);
}

extern WINAPI void wine32a_kernel32_GetApplicationRestartSettings(void);  /* ../dlls/kernel32/process.c:3966 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetApplicationRestartSettings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetApplicationRestartSettings") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetAtomNameA(ATOM  atom, LPSTR  buffer, INT  count) /* ../dlls/kernel32/atom.c:432 */
{
	TRACE("Enter GetAtomNameA\n");
	return pGetAtomNameA(atom, buffer, count);
}

extern WINAPI void wine32a_kernel32_GetAtomNameA(void);  /* ../dlls/kernel32/atom.c:432 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetAtomNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetAtomNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetAtomNameW(ATOM  atom, LPWSTR  buffer, INT  count) /* ../dlls/kernel32/atom.c:502 */
{
	TRACE("Enter GetAtomNameW\n");
	return pGetAtomNameW(atom, buffer, count);
}

extern WINAPI void wine32a_kernel32_GetAtomNameW(void);  /* ../dlls/kernel32/atom.c:502 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetAtomNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetAtomNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetBinaryTypeA(LPCSTR  lpApplicationName, LPDWORD  lpBinaryType) /* ../dlls/kernel32/module.c:356 */
{
	TRACE("Enter GetBinaryTypeA\n");
	return pGetBinaryTypeA(lpApplicationName, lpBinaryType);
}

extern WINAPI void wine32a_kernel32_GetBinaryTypeA(void);  /* ../dlls/kernel32/module.c:356 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetBinaryTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetBinaryTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetBinaryTypeW(LPCWSTR  name, LPDWORD  type) /* ../dlls/kernel32/module.c:270 */
{
	TRACE("Enter GetBinaryTypeW\n");
	return pGetBinaryTypeW(name, type);
}

extern WINAPI void wine32a_kernel32_GetBinaryTypeW(void);  /* ../dlls/kernel32/module.c:270 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetBinaryTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetBinaryTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetCPInfo(UINT  codepage, LPCPINFO  cpinfo) /* ../dlls/kernel32/locale.c:2132 */
{
	TRACE("Enter GetCPInfo\n");
	return pGetCPInfo(codepage, cpinfo);
}

extern WINAPI void wine32a_kernel32_GetCPInfo(void);  /* ../dlls/kernel32/locale.c:2132 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCPInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCPInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetCPInfoExA(UINT  codepage, DWORD  dwFlags, LPCPINFOEXA  cpinfo) /* ../dlls/kernel32/locale.c:2190 */
{
	TRACE("Enter GetCPInfoExA\n");
	return pGetCPInfoExA(codepage, dwFlags, cpinfo);
}

extern WINAPI void wine32a_kernel32_GetCPInfoExA(void);  /* ../dlls/kernel32/locale.c:2190 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCPInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCPInfoExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetCPInfoExW(UINT  codepage, DWORD  dwFlags, LPCPINFOEXW  cpinfo) /* ../dlls/kernel32/locale.c:2208 */
{
	TRACE("Enter GetCPInfoExW\n");
	return pGetCPInfoExW(codepage, dwFlags, cpinfo);
}

extern WINAPI void wine32a_kernel32_GetCPInfoExW(void);  /* ../dlls/kernel32/locale.c:2208 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCPInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCPInfoExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetCalendarInfoA(LCID  lcid, CALID  Calendar, CALTYPE  CalType, LPSTR  lpCalData, int  cchData, LPDWORD  lpValue) /* ../dlls/kernel32/time.c:910 */
{
	TRACE("Enter GetCalendarInfoA\n");
	return pGetCalendarInfoA(lcid, Calendar, CalType, lpCalData, cchData, lpValue);
}

extern WINAPI void wine32a_kernel32_GetCalendarInfoA(void);  /* ../dlls/kernel32/time.c:910 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCalendarInfoA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetCalendarInfoW(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPWSTR  lpCalData, int  cchData, LPDWORD  lpValue) /* ../dlls/kernel32/time.c:941 */
{
	TRACE("Enter GetCalendarInfoW\n");
	return pGetCalendarInfoW(Locale, Calendar, CalType, lpCalData, cchData, lpValue);
}

extern WINAPI void wine32a_kernel32_GetCalendarInfoW(void);  /* ../dlls/kernel32/time.c:941 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCalendarInfoW") "\n"
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

extern WINAPI int wine32b_kernel32_GetCalendarInfoEx(LPCWSTR  locale, CALID  calendar, LPCWSTR  lpReserved, CALTYPE  caltype, LPWSTR  data, int  len, DWORD*  value) /* ../dlls/kernel32/time.c:1138 */
{
	TRACE("Enter GetCalendarInfoEx\n");
	return pGetCalendarInfoEx(locale, calendar, lpReserved, caltype, data, len, value);
}

extern WINAPI void wine32a_kernel32_GetCalendarInfoEx(void);  /* ../dlls/kernel32/time.c:1138 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCalendarInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCalendarInfoEx") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetComputerNameA(LPSTR  name, LPDWORD  size) /* ../dlls/kernel32/computername.c:382 */
{
	TRACE("Enter GetComputerNameA\n");
	return pGetComputerNameA(name, size);
}

extern WINAPI void wine32a_kernel32_GetComputerNameA(void);  /* ../dlls/kernel32/computername.c:382 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetComputerNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetComputerNameExA(COMPUTER_NAME_FORMAT  type, LPSTR  name, LPDWORD  size) /* ../dlls/kernel32/computername.c:421 */
{
	TRACE("Enter GetComputerNameExA\n");
	return pGetComputerNameExA(type, name, size);
}

extern WINAPI void wine32a_kernel32_GetComputerNameExA(void);  /* ../dlls/kernel32/computername.c:421 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetComputerNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetComputerNameExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetComputerNameExW(COMPUTER_NAME_FORMAT  type, LPWSTR  name, LPDWORD  size) /* ../dlls/kernel32/computername.c:477 */
{
	TRACE("Enter GetComputerNameExW\n");
	return pGetComputerNameExW(type, name, size);
}

extern WINAPI void wine32a_kernel32_GetComputerNameExW(void);  /* ../dlls/kernel32/computername.c:477 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetComputerNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetComputerNameExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetComputerNameW(LPWSTR  name, LPDWORD  size) /* ../dlls/kernel32/computername.c:313 */
{
	TRACE("Enter GetComputerNameW\n");
	return pGetComputerNameW(name, size);
}

extern WINAPI void wine32a_kernel32_GetComputerNameW(void);  /* ../dlls/kernel32/computername.c:313 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetComputerNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleAliasExesLengthA(void) /* ../dlls/kernel32/console.c:1574 */
{
	TRACE("Enter GetConsoleAliasExesLengthA\n");
	return pGetConsoleAliasExesLengthA();
}

extern WINAPI void wine32a_kernel32_GetConsoleAliasExesLengthA(void);  /* ../dlls/kernel32/console.c:1574 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleAliasExesLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleAliasExesLengthA") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetConsoleAliasExesLengthW(void) /* ../dlls/kernel32/console.c:1581 */
{
	TRACE("Enter GetConsoleAliasExesLengthW\n");
	return pGetConsoleAliasExesLengthW();
}

extern WINAPI void wine32a_kernel32_GetConsoleAliasExesLengthW(void);  /* ../dlls/kernel32/console.c:1581 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleAliasExesLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleAliasExesLengthW") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetConsoleAliasW(LPWSTR  lpSource, LPWSTR  lpTargetBuffer, DWORD  TargetBufferLength, LPWSTR  lpExename) /* ../dlls/kernel32/console.c:1408 */
{
	TRACE("Enter GetConsoleAliasW\n");
	return pGetConsoleAliasW(lpSource, lpTargetBuffer, TargetBufferLength, lpExename);
}

extern WINAPI void wine32a_kernel32_GetConsoleAliasW(void);  /* ../dlls/kernel32/console.c:1408 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleAliasW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleAliasW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleAliasesLengthA(LPSTR  unknown) /* ../dlls/kernel32/console.c:1560 */
{
	TRACE("Enter GetConsoleAliasesLengthA\n");
	return pGetConsoleAliasesLengthA(unknown);
}

extern WINAPI void wine32a_kernel32_GetConsoleAliasesLengthA(void);  /* ../dlls/kernel32/console.c:1560 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleAliasesLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleAliasesLengthA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleAliasesLengthW(LPWSTR  unknown) /* ../dlls/kernel32/console.c:1567 */
{
	TRACE("Enter GetConsoleAliasesLengthW\n");
	return pGetConsoleAliasesLengthW(unknown);
}

extern WINAPI void wine32a_kernel32_GetConsoleAliasesLengthW(void);  /* ../dlls/kernel32/console.c:1567 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleAliasesLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleAliasesLengthW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryA(DWORD  unknown1, DWORD  unknown2, DWORD  unknown3) /* ../dlls/kernel32/console.c:1526 */
{
	TRACE("Enter GetConsoleCommandHistoryA\n");
	return pGetConsoleCommandHistoryA(unknown1, unknown2, unknown3);
}

extern WINAPI void wine32a_kernel32_GetConsoleCommandHistoryA(void);  /* ../dlls/kernel32/console.c:1526 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleCommandHistoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleCommandHistoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryLengthA(LPCSTR  unknown) /* ../dlls/kernel32/console.c:1544 */
{
	TRACE("Enter GetConsoleCommandHistoryLengthA\n");
	return pGetConsoleCommandHistoryLengthA(unknown);
}

extern WINAPI void wine32a_kernel32_GetConsoleCommandHistoryLengthA(void);  /* ../dlls/kernel32/console.c:1544 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleCommandHistoryLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleCommandHistoryLengthA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryLengthW(LPCWSTR  unknown) /* ../dlls/kernel32/console.c:1553 */
{
	TRACE("Enter GetConsoleCommandHistoryLengthW\n");
	return pGetConsoleCommandHistoryLengthW(unknown);
}

extern WINAPI void wine32a_kernel32_GetConsoleCommandHistoryLengthW(void);  /* ../dlls/kernel32/console.c:1553 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleCommandHistoryLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleCommandHistoryLengthW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryW(DWORD  unknown1, DWORD  unknown2, DWORD  unknown3) /* ../dlls/kernel32/console.c:1535 */
{
	TRACE("Enter GetConsoleCommandHistoryW\n");
	return pGetConsoleCommandHistoryW(unknown1, unknown2, unknown3);
}

extern WINAPI void wine32a_kernel32_GetConsoleCommandHistoryW(void);  /* ../dlls/kernel32/console.c:1535 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleCommandHistoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleCommandHistoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetConsoleDisplayMode(LPDWORD  lpModeFlags) /* ../dlls/kernel32/console.c:1283 */
{
	TRACE("Enter GetConsoleDisplayMode\n");
	return pGetConsoleDisplayMode(lpModeFlags);
}

extern WINAPI void wine32a_kernel32_GetConsoleDisplayMode(void);  /* ../dlls/kernel32/console.c:1283 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleDisplayMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleDisplayMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetConsoleFontInfo(HANDLE  hConsole, BOOL  maximize, DWORD  numfonts, CONSOLE_FONT_INFO*  info) /* ../dlls/kernel32/console.c:1711 */
{
	TRACE("Enter GetConsoleFontInfo\n");
	return pGetConsoleFontInfo(hConsole, maximize, numfonts, info);
}

extern WINAPI void wine32a_kernel32_GetConsoleFontInfo(void);  /* ../dlls/kernel32/console.c:1711 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleFontInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleFontInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI COORD wine32b_kernel32_GetConsoleFontSize(HANDLE  hConsole, DWORD  index) /* ../dlls/kernel32/console.c:1705 */
{
	TRACE("Enter GetConsoleFontSize\n");
	return pGetConsoleFontSize(hConsole, index);
}

extern WINAPI void wine32a_kernel32_GetConsoleFontSize(void);  /* ../dlls/kernel32/console.c:1705 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleFontSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleFontSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_GetConsoleInputWaitHandle(void) /* ../dlls/kernel32/console.c:306 */
{
	TRACE("Enter GetConsoleInputWaitHandle\n");
	return pGetConsoleInputWaitHandle();
}

extern WINAPI void wine32a_kernel32_GetConsoleInputWaitHandle(void);  /* ../dlls/kernel32/console.c:306 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleInputWaitHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleInputWaitHandle") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetConsoleKeyboardLayoutNameA(LPSTR  layoutName) /* ../dlls/kernel32/console.c:495 */
{
	TRACE("Enter GetConsoleKeyboardLayoutNameA\n");
	return pGetConsoleKeyboardLayoutNameA(layoutName);
}

extern WINAPI void wine32a_kernel32_GetConsoleKeyboardLayoutNameA(void);  /* ../dlls/kernel32/console.c:495 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleKeyboardLayoutNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleKeyboardLayoutNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetConsoleKeyboardLayoutNameW(LPWSTR  layoutName) /* ../dlls/kernel32/console.c:504 */
{
	TRACE("Enter GetConsoleKeyboardLayoutNameW\n");
	return pGetConsoleKeyboardLayoutNameW(layoutName);
}

extern WINAPI void wine32a_kernel32_GetConsoleKeyboardLayoutNameW(void);  /* ../dlls/kernel32/console.c:504 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleKeyboardLayoutNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleKeyboardLayoutNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleProcessList(LPDWORD  processlist, DWORD  processcount) /* ../dlls/kernel32/console.c:1419 */
{
	TRACE("Enter GetConsoleProcessList\n");
	return pGetConsoleProcessList(processlist, processcount);
}

extern WINAPI void wine32a_kernel32_GetConsoleProcessList(void);  /* ../dlls/kernel32/console.c:1419 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleProcessList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleProcessList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetConsoleTitleA(LPSTR  title, DWORD  size) /* ../dlls/kernel32/console.c:517 */
{
	TRACE("Enter GetConsoleTitleA\n");
	return pGetConsoleTitleA(title, size);
}

extern WINAPI void wine32a_kernel32_GetConsoleTitleA(void);  /* ../dlls/kernel32/console.c:517 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleTitleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleTitleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_kernel32_GetConsoleWindow(void) /* ../dlls/kernel32/console.c:179 */
{
	TRACE("Enter GetConsoleWindow\n");
	return pGetConsoleWindow();
}

extern WINAPI void wine32a_kernel32_GetConsoleWindow(void);  /* ../dlls/kernel32/console.c:179 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetConsoleWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetConsoleWindow") "\n"
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

extern WINAPI INT wine32b_kernel32_GetCurrencyFormatA(LCID  lcid, DWORD  dwFlags, LPCSTR  lpszValue, CURRENCYFMTA*  lpFormat, LPSTR  lpCurrencyStr, int  cchOut) /* ../dlls/kernel32/lcformat.c:1393 */
{
	TRACE("Enter GetCurrencyFormatA\n");
	return pGetCurrencyFormatA(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetCurrencyFormatA(void);  /* ../dlls/kernel32/lcformat.c:1393 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrencyFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrencyFormatA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetCurrencyFormatEx(LPCWSTR  localename, DWORD  flags, LPCWSTR  value, CURRENCYFMTW*  format, LPWSTR  str, int  len) /* ../dlls/kernel32/lcformat.c:1762 */
{
	TRACE("Enter GetCurrencyFormatEx\n");
	return pGetCurrencyFormatEx(localename, flags, value, format, str, len);
}

extern WINAPI void wine32a_kernel32_GetCurrencyFormatEx(void);  /* ../dlls/kernel32/lcformat.c:1762 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrencyFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrencyFormatEx") "\n"
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

extern WINAPI INT wine32b_kernel32_GetCurrencyFormatW(LCID  lcid, DWORD  dwFlags, LPCWSTR  lpszValue, CURRENCYFMTW*  lpFormat, LPWSTR  lpCurrencyStr, int  cchOut) /* ../dlls/kernel32/lcformat.c:1475 */
{
	TRACE("Enter GetCurrencyFormatW\n");
	return pGetCurrencyFormatW(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetCurrencyFormatW(void);  /* ../dlls/kernel32/lcformat.c:1475 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrencyFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrencyFormatW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetCurrentConsoleFont(HANDLE  hConsole, BOOL  maxwindow, LPCONSOLE_FONT_INFO  fontinfo) /* ../dlls/kernel32/console.c:1642 */
{
	TRACE("Enter GetCurrentConsoleFont\n");
	return pGetCurrentConsoleFont(hConsole, maxwindow, fontinfo);
}

extern WINAPI void wine32a_kernel32_GetCurrentConsoleFont(void);  /* ../dlls/kernel32/console.c:1642 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentConsoleFont,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentConsoleFont") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetCurrentDirectoryA(UINT  buflen, LPSTR  buf) /* ../dlls/kernel32/path.c:1701 */
{
	TRACE("Enter GetCurrentDirectoryA\n");
	return pGetCurrentDirectoryA(buflen, buf);
}

extern WINAPI void wine32a_kernel32_GetCurrentDirectoryA(void);  /* ../dlls/kernel32/path.c:1701 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetCurrentDirectoryW(UINT  buflen, LPWSTR  buf) /* ../dlls/kernel32/path.c:1692 */
{
	TRACE("Enter GetCurrentDirectoryW\n");
	return pGetCurrentDirectoryW(buflen, buf);
}

extern WINAPI void wine32a_kernel32_GetCurrentDirectoryW(void);  /* ../dlls/kernel32/path.c:1692 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_GetCurrentPackageFamilyName(UINT32*  length, PWSTR  name) /* ../dlls/kernel32/version.c:140 */
{
	TRACE("Enter GetCurrentPackageFamilyName\n");
	return pGetCurrentPackageFamilyName(length, name);
}

extern WINAPI void wine32a_kernel32_GetCurrentPackageFamilyName(void);  /* ../dlls/kernel32/version.c:140 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentPackageFamilyName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentPackageFamilyName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_GetCurrentPackageFullName(UINT32*  length, PWSTR  name) /* ../dlls/kernel32/version.c:149 */
{
	TRACE("Enter GetCurrentPackageFullName\n");
	return pGetCurrentPackageFullName(length, name);
}

extern WINAPI void wine32a_kernel32_GetCurrentPackageFullName(void);  /* ../dlls/kernel32/version.c:149 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentPackageFullName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentPackageFullName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_GetCurrentPackageId(UINT32*  len, BYTE*  buffer) /* ../dlls/kernel32/version.c:131 */
{
	TRACE("Enter GetCurrentPackageId\n");
	return pGetCurrentPackageId(len, buffer);
}

extern WINAPI void wine32a_kernel32_GetCurrentPackageId(void);  /* ../dlls/kernel32/version.c:131 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentPackageId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentPackageId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_GetCurrentProcess(void) /* ../dlls/kernel32/process.c:3811 */
{
	TRACE("Enter GetCurrentProcess\n");
	return pGetCurrentProcess();
}

extern WINAPI void wine32a_kernel32_GetCurrentProcess(void);  /* ../dlls/kernel32/process.c:3811 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentProcess") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetCurrentProcessId(void) /* ../dlls/kernel32/thread.c:146 */
{
	TRACE("Enter GetCurrentProcessId\n");
	return pGetCurrentProcessId();
}

extern WINAPI void wine32a_kernel32_GetCurrentProcessId(void);  /* ../dlls/kernel32/thread.c:146 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentProcessId") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_GetCurrentThread(void) /* ../dlls/kernel32/thread.c:133 */
{
	TRACE("Enter GetCurrentThread\n");
	return pGetCurrentThread();
}

extern WINAPI void wine32a_kernel32_GetCurrentThread(void);  /* ../dlls/kernel32/thread.c:133 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentThread") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetCurrentThreadId(void) /* ../dlls/kernel32/thread.c:159 */
{
	TRACE("Enter GetCurrentThreadId\n");
	return pGetCurrentThreadId();
}

extern WINAPI void wine32a_kernel32_GetCurrentThreadId(void);  /* ../dlls/kernel32/thread.c:159 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentThreadId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentThreadId") "\n"
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

extern WINAPI PUMS_CONTEXT wine32b_kernel32_GetCurrentUmsThread(void) /* ../dlls/kernel32/process.c:4196 */
{
	TRACE("Enter GetCurrentUmsThread\n");
	return pGetCurrentUmsThread();
}

extern WINAPI void wine32a_kernel32_GetCurrentUmsThread(void);  /* ../dlls/kernel32/process.c:4196 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetCurrentUmsThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetCurrentUmsThread") "\n"
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

extern WINAPI INT wine32b_kernel32_GetDateFormatA(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCSTR  lpFormat, LPSTR  lpDateStr, INT  cchOut) /* ../dlls/kernel32/lcformat.c:839 */
{
	TRACE("Enter GetDateFormatA\n");
	return pGetDateFormatA(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetDateFormatA(void);  /* ../dlls/kernel32/lcformat.c:839 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDateFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDateFormatA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetDateFormatEx(LPCWSTR  localename, DWORD  flags, SYSTEMTIME*  date, LPCWSTR  format, LPWSTR  outbuf, INT  bufsize, LPCWSTR  calendar) /* ../dlls/kernel32/lcformat.c:870 */
{
	TRACE("Enter GetDateFormatEx\n");
	return pGetDateFormatEx(localename, flags, date, format, outbuf, bufsize, calendar);
}

extern WINAPI void wine32a_kernel32_GetDateFormatEx(void);  /* ../dlls/kernel32/lcformat.c:870 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDateFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDateFormatEx") "\n"
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

extern WINAPI INT wine32b_kernel32_GetDateFormatW(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCWSTR  lpFormat, LPWSTR  lpDateStr, INT  cchOut) /* ../dlls/kernel32/lcformat.c:894 */
{
	TRACE("Enter GetDateFormatW\n");
	return pGetDateFormatW(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetDateFormatW(void);  /* ../dlls/kernel32/lcformat.c:894 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDateFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDateFormatW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetDaylightFlag(void) /* ../dlls/kernel32/time.c:1346 */
{
	TRACE("Enter GetDaylightFlag\n");
	return pGetDaylightFlag();
}

extern WINAPI void wine32a_kernel32_GetDaylightFlag(void);  /* ../dlls/kernel32/time.c:1346 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDaylightFlag,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDaylightFlag") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetDefaultCommConfigA(LPCSTR  lpszName, LPCOMMCONFIG  lpCC, LPDWORD  lpdwSize) /* ../dlls/kernel32/comm.c:730 */
{
	TRACE("Enter GetDefaultCommConfigA\n");
	return pGetDefaultCommConfigA(lpszName, lpCC, lpdwSize);
}

extern WINAPI void wine32a_kernel32_GetDefaultCommConfigA(void);  /* ../dlls/kernel32/comm.c:730 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDefaultCommConfigA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDefaultCommConfigA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDefaultCommConfigW(LPCWSTR  lpszName, LPCOMMCONFIG  lpCC, LPDWORD  lpdwSize) /* ../dlls/kernel32/comm.c:694 */
{
	TRACE("Enter GetDefaultCommConfigW\n");
	return pGetDefaultCommConfigW(lpszName, lpCC, lpdwSize);
}

extern WINAPI void wine32a_kernel32_GetDefaultCommConfigW(void);  /* ../dlls/kernel32/comm.c:694 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDefaultCommConfigW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDefaultCommConfigW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDevicePowerState(HANDLE  hDevice, BOOL*  pfOn) /* ../dlls/kernel32/powermgnt.c:37 */
{
	TRACE("Enter GetDevicePowerState\n");
	return pGetDevicePowerState(hDevice, pfOn);
}

extern WINAPI void wine32a_kernel32_GetDevicePowerState(void);  /* ../dlls/kernel32/powermgnt.c:37 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDevicePowerState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDevicePowerState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceA(LPCSTR  root, LPDWORD  cluster_sectors, LPDWORD  sector_bytes, LPDWORD  free_clusters, LPDWORD  total_clusters) /* ../dlls/kernel32/volume.c:1625 */
{
	TRACE("Enter GetDiskFreeSpaceA\n");
	return pGetDiskFreeSpaceA(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
}

extern WINAPI void wine32a_kernel32_GetDiskFreeSpaceA(void);  /* ../dlls/kernel32/volume.c:1625 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDiskFreeSpaceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDiskFreeSpaceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceExA(LPCSTR  root, PULARGE_INTEGER  avail, PULARGE_INTEGER  total, PULARGE_INTEGER  totalfree) /* ../dlls/kernel32/volume.c:1559 */
{
	TRACE("Enter GetDiskFreeSpaceExA\n");
	return pGetDiskFreeSpaceExA(root, avail, total, totalfree);
}

extern WINAPI void wine32a_kernel32_GetDiskFreeSpaceExA(void);  /* ../dlls/kernel32/volume.c:1559 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDiskFreeSpaceExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDiskFreeSpaceExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceExW(LPCWSTR  root, PULARGE_INTEGER  avail, PULARGE_INTEGER  total, PULARGE_INTEGER  totalfree) /* ../dlls/kernel32/volume.c:1524 */
{
	TRACE("Enter GetDiskFreeSpaceExW\n");
	return pGetDiskFreeSpaceExW(root, avail, total, totalfree);
}

extern WINAPI void wine32a_kernel32_GetDiskFreeSpaceExW(void);  /* ../dlls/kernel32/volume.c:1524 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDiskFreeSpaceExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDiskFreeSpaceExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceW(LPCWSTR  root, LPDWORD  cluster_sectors, LPDWORD  sector_bytes, LPDWORD  free_clusters, LPDWORD  total_clusters) /* ../dlls/kernel32/volume.c:1572 */
{
	TRACE("Enter GetDiskFreeSpaceW\n");
	return pGetDiskFreeSpaceW(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
}

extern WINAPI void wine32a_kernel32_GetDiskFreeSpaceW(void);  /* ../dlls/kernel32/volume.c:1572 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDiskFreeSpaceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDiskFreeSpaceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetDllDirectoryA(DWORD  buf_len, LPSTR  buffer) /* ../dlls/kernel32/module.c:83 */
{
	TRACE("Enter GetDllDirectoryA\n");
	return pGetDllDirectoryA(buf_len, buffer);
}

extern WINAPI void wine32a_kernel32_GetDllDirectoryA(void);  /* ../dlls/kernel32/module.c:83 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDllDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDllDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetDllDirectoryW(DWORD  buf_len, LPWSTR  buffer) /* ../dlls/kernel32/module.c:107 */
{
	TRACE("Enter GetDllDirectoryW\n");
	return pGetDllDirectoryW(buf_len, buffer);
}

extern WINAPI void wine32a_kernel32_GetDllDirectoryW(void);  /* ../dlls/kernel32/module.c:107 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDllDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDllDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetDriveTypeA(LPCSTR  root) /* ../dlls/kernel32/volume.c:1503 */
{
	TRACE("Enter GetDriveTypeA\n");
	return pGetDriveTypeA(root);
}

extern WINAPI void wine32a_kernel32_GetDriveTypeA(void);  /* ../dlls/kernel32/volume.c:1503 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDriveTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDriveTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetDriveTypeW(LPCWSTR  root) /* ../dlls/kernel32/volume.c:1451 */
{
	TRACE("Enter GetDriveTypeW\n");
	return pGetDriveTypeW(root);
}

extern WINAPI void wine32a_kernel32_GetDriveTypeW(void);  /* ../dlls/kernel32/volume.c:1451 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDriveTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDriveTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetDynamicTimeZoneInformation(DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo) /* ../dlls/kernel32/time.c:1496 */
{
	TRACE("Enter GetDynamicTimeZoneInformation\n");
	return pGetDynamicTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_kernel32_GetDynamicTimeZoneInformation(void);  /* ../dlls/kernel32/time.c:1496 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDynamicTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDynamicTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetDynamicTimeZoneInformationEffectiveYears(DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo, DWORD*  first_year, DWORD*  last_year) /* ../dlls/kernel32/time.c:1521 */
{
	TRACE("Enter GetDynamicTimeZoneInformationEffectiveYears\n");
	return pGetDynamicTimeZoneInformationEffectiveYears(tzinfo, first_year, last_year);
}

extern WINAPI void wine32a_kernel32_GetDynamicTimeZoneInformationEffectiveYears(void);  /* ../dlls/kernel32/time.c:1521 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetDynamicTimeZoneInformationEffectiveYears,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetDynamicTimeZoneInformationEffectiveYears") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD64 wine32b_kernel32_GetEnabledXStateFeatures(void) /* ../dlls/kernel32/cpu.c:287 */
{
	TRACE("Enter GetEnabledXStateFeatures\n");
	return pGetEnabledXStateFeatures();
}

extern WINAPI void wine32a_kernel32_GetEnabledXStateFeatures(void);  /* ../dlls/kernel32/cpu.c:287 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetEnabledXStateFeatures,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetEnabledXStateFeatures") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetExitCodeProcess(HANDLE  hProcess, LPDWORD  lpExitCode) /* ../dlls/kernel32/process.c:3178 */
{
	TRACE("Enter GetExitCodeProcess\n");
	return pGetExitCodeProcess(hProcess, lpExitCode);
}

extern WINAPI void wine32a_kernel32_GetExitCodeProcess(void);  /* ../dlls/kernel32/process.c:3178 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetExitCodeProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetExitCodeProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetExpandedNameA(LPSTR  in, LPSTR  out) /* ../dlls/kernel32/lzexpand.c:240 */
{
	TRACE("Enter GetExpandedNameA\n");
	return pGetExpandedNameA(in, out);
}

extern WINAPI void wine32a_kernel32_GetExpandedNameA(void);  /* ../dlls/kernel32/lzexpand.c:240 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetExpandedNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetExpandedNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetExpandedNameW(LPWSTR  in, LPWSTR  out) /* ../dlls/kernel32/lzexpand.c:310 */
{
	TRACE("Enter GetExpandedNameW\n");
	return pGetExpandedNameW(in, out);
}

extern WINAPI void wine32a_kernel32_GetExpandedNameW(void);  /* ../dlls/kernel32/lzexpand.c:310 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetExpandedNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetExpandedNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetFileMUIInfo(DWORD  flags, PCWSTR  path, FILEMUIINFO*  info, DWORD*  size) /* ../dlls/kernel32/locale.c:5886 */
{
	TRACE("Enter GetFileMUIInfo\n");
	return pGetFileMUIInfo(flags, path, info, size);
}

extern WINAPI void wine32a_kernel32_GetFileMUIInfo(void);  /* ../dlls/kernel32/locale.c:5886 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFileMUIInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFileMUIInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetFileMUIPath(DWORD  flags, PCWSTR  filepath, PWSTR  language, PULONG  languagelen, PWSTR  muipath, PULONG  muipathlen, PULONGLONG  enumerator) /* ../dlls/kernel32/locale.c:5871 */
{
	TRACE("Enter GetFileMUIPath\n");
	return pGetFileMUIPath(flags, filepath, language, languagelen, muipath, muipathlen, enumerator);
}

extern WINAPI void wine32a_kernel32_GetFileMUIPath(void);  /* ../dlls/kernel32/locale.c:5871 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFileMUIPath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFileMUIPath") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetFinalPathNameByHandleA(HANDLE  file, LPSTR  path, DWORD  charcount, DWORD  flags) /* ../dlls/kernel32/file.c:1494 */
{
	TRACE("Enter GetFinalPathNameByHandleA\n");
	return pGetFinalPathNameByHandleA(file, path, charcount, flags);
}

extern WINAPI void wine32a_kernel32_GetFinalPathNameByHandleA(void);  /* ../dlls/kernel32/file.c:1494 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFinalPathNameByHandleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFinalPathNameByHandleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetFinalPathNameByHandleW(HANDLE  file, LPWSTR  path, DWORD  charcount, DWORD  flags) /* ../dlls/kernel32/file.c:1341 */
{
	TRACE("Enter GetFinalPathNameByHandleW\n");
	return pGetFinalPathNameByHandleW(file, path, charcount, flags);
}

extern WINAPI void wine32a_kernel32_GetFinalPathNameByHandleW(void);  /* ../dlls/kernel32/file.c:1341 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFinalPathNameByHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFinalPathNameByHandleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetFirmwareEnvironmentVariableA(LPCSTR  name, LPCSTR  guid, PVOID  buffer, DWORD  size) /* ../dlls/kernel32/environ.c:100 */
{
	TRACE("Enter GetFirmwareEnvironmentVariableA\n");
	return pGetFirmwareEnvironmentVariableA(name, guid, buffer, size);
}

extern WINAPI void wine32a_kernel32_GetFirmwareEnvironmentVariableA(void);  /* ../dlls/kernel32/environ.c:100 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFirmwareEnvironmentVariableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFirmwareEnvironmentVariableA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetFirmwareEnvironmentVariableW(LPCWSTR  name, LPCWSTR  guid, PVOID  buffer, DWORD  size) /* ../dlls/kernel32/environ.c:110 */
{
	TRACE("Enter GetFirmwareEnvironmentVariableW\n");
	return pGetFirmwareEnvironmentVariableW(name, guid, buffer, size);
}

extern WINAPI void wine32a_kernel32_GetFirmwareEnvironmentVariableW(void);  /* ../dlls/kernel32/environ.c:110 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFirmwareEnvironmentVariableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFirmwareEnvironmentVariableW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetFullPathNameA(LPCSTR  name, DWORD  len, LPSTR  buffer, LPSTR*  lastpart) /* ../dlls/kernel32/path.c:252 */
{
	TRACE("Enter GetFullPathNameA\n");
	return pGetFullPathNameA(name, len, buffer, lastpart);
}

extern WINAPI void wine32a_kernel32_GetFullPathNameA(void);  /* ../dlls/kernel32/path.c:252 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFullPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFullPathNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetFullPathNameW(LPCWSTR  name, DWORD  len, LPWSTR  buffer, LPWSTR*  lastpart) /* ../dlls/kernel32/path.c:241 */
{
	TRACE("Enter GetFullPathNameW\n");
	return pGetFullPathNameW(name, len, buffer, lastpart);
}

extern WINAPI void wine32a_kernel32_GetFullPathNameW(void);  /* ../dlls/kernel32/path.c:241 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetFullPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetFullPathNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetGeoInfoA(GEOID  geoid, GEOTYPE  geotype, LPSTR  data, int  data_len, LANGID  lang) /* ../dlls/kernel32/locale.c:5184 */
{
	TRACE("Enter GetGeoInfoA\n");
	return pGetGeoInfoA(geoid, geotype, data, data_len, lang);
}

extern WINAPI void wine32a_kernel32_GetGeoInfoA(void);  /* ../dlls/kernel32/locale.c:5184 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetGeoInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetGeoInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetGeoInfoW(GEOID  geoid, GEOTYPE  geotype, LPWSTR  data, int  data_len, LANGID  lang) /* ../dlls/kernel32/locale.c:5117 */
{
	TRACE("Enter GetGeoInfoW\n");
	return pGetGeoInfoW(geoid, geotype, data, data_len, lang);
}

extern WINAPI void wine32a_kernel32_GetGeoInfoW(void);  /* ../dlls/kernel32/locale.c:5117 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetGeoInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetGeoInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetHandleContext(HANDLE  hnd) /* ../dlls/kernel32/process.c:3362 */
{
	TRACE("Enter GetHandleContext\n");
	return pGetHandleContext(hnd);
}

extern WINAPI void wine32a_kernel32_GetHandleContext(void);  /* ../dlls/kernel32/process.c:3362 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetHandleContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetHandleContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetHandleInformation(HANDLE  handle, LPDWORD  flags) /* ../dlls/kernel32/process.c:3262 */
{
	TRACE("Enter GetHandleInformation\n");
	return pGetHandleInformation(handle, flags);
}

extern WINAPI void wine32a_kernel32_GetHandleInformation(void);  /* ../dlls/kernel32/process.c:3262 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetHandleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetHandleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_GetLargePageMinimum(void) /* ../dlls/kernel32/cpu.c:236 */
{
	TRACE("Enter GetLargePageMinimum\n");
	return pGetLargePageMinimum();
}

extern WINAPI void wine32a_kernel32_GetLargePageMinimum(void);  /* ../dlls/kernel32/cpu.c:236 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLargePageMinimum,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLargePageMinimum") "\n"
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

extern WINAPI void wine32b_kernel32_GetLocalTime(LPSYSTEMTIME  systime) /* ../dlls/kernel32/time.c:1300 */
{
	TRACE("Enter GetLocalTime\n");
	return pGetLocalTime(systime);
}

extern WINAPI void wine32a_kernel32_GetLocalTime(void);  /* ../dlls/kernel32/time.c:1300 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetLocaleInfoA(LCID  lcid, LCTYPE  lctype, LPSTR  buffer, INT  len) /* ../dlls/kernel32/locale.c:1612 */
{
	TRACE("Enter GetLocaleInfoA\n");
	return pGetLocaleInfoA(lcid, lctype, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetLocaleInfoA(void);  /* ../dlls/kernel32/locale.c:1612 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLocaleInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLocaleInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetLocaleInfoW(LCID  lcid, LCTYPE  lctype, LPWSTR  buffer, INT  len) /* ../dlls/kernel32/locale.c:1678 */
{
	TRACE("Enter GetLocaleInfoW\n");
	return pGetLocaleInfoW(lcid, lctype, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetLocaleInfoW(void);  /* ../dlls/kernel32/locale.c:1678 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLocaleInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLocaleInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetLocaleInfoEx(LPCWSTR  locale, LCTYPE  info, LPWSTR  buffer, INT  len) /* ../dlls/kernel32/locale.c:1824 */
{
	TRACE("Enter GetLocaleInfoEx\n");
	return pGetLocaleInfoEx(locale, info, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetLocaleInfoEx(void);  /* ../dlls/kernel32/locale.c:1824 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLocaleInfoEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLocaleInfoEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetLogicalDriveStringsA(UINT  len, LPSTR  buffer) /* ../dlls/kernel32/volume.c:1384 */
{
	TRACE("Enter GetLogicalDriveStringsA\n");
	return pGetLogicalDriveStringsA(len, buffer);
}

extern WINAPI void wine32a_kernel32_GetLogicalDriveStringsA(void);  /* ../dlls/kernel32/volume.c:1384 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLogicalDriveStringsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLogicalDriveStringsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetLogicalDriveStringsW(UINT  len, LPWSTR  buffer) /* ../dlls/kernel32/volume.c:1410 */
{
	TRACE("Enter GetLogicalDriveStringsW\n");
	return pGetLogicalDriveStringsW(len, buffer);
}

extern WINAPI void wine32a_kernel32_GetLogicalDriveStringsW(void);  /* ../dlls/kernel32/volume.c:1410 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLogicalDriveStringsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLogicalDriveStringsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetLogicalDrives(void) /* ../dlls/kernel32/volume.c:1346 */
{
	TRACE("Enter GetLogicalDrives\n");
	return pGetLogicalDrives();
}

extern WINAPI void wine32a_kernel32_GetLogicalDrives(void);  /* ../dlls/kernel32/volume.c:1346 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLogicalDrives,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLogicalDrives") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION  buffer, PDWORD  pBufLen) /* ../dlls/kernel32/process.c:3819 */
{
	TRACE("Enter GetLogicalProcessorInformation\n");
	return pGetLogicalProcessorInformation(buffer, pBufLen);
}

extern WINAPI void wine32a_kernel32_GetLogicalProcessorInformation(void);  /* ../dlls/kernel32/process.c:3819 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLogicalProcessorInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLogicalProcessorInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP  relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX*  buffer, DWORD*  len) /* ../dlls/kernel32/process.c:3849 */
{
	TRACE("Enter GetLogicalProcessorInformationEx\n");
	return pGetLogicalProcessorInformationEx(relationship, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetLogicalProcessorInformationEx(void);  /* ../dlls/kernel32/process.c:3849 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLogicalProcessorInformationEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLogicalProcessorInformationEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetLongPathNameA(LPCSTR  shortpath, LPSTR  longpath, DWORD  longlen) /* ../dlls/kernel32/path.c:405 */
{
	TRACE("Enter GetLongPathNameA\n");
	return pGetLongPathNameA(shortpath, longpath, longlen);
}

extern WINAPI void wine32a_kernel32_GetLongPathNameA(void);  /* ../dlls/kernel32/path.c:405 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLongPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLongPathNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetLongPathNameW(LPCWSTR  shortpath, LPWSTR  longpath, DWORD  longlen) /* ../dlls/kernel32/path.c:289 */
{
	TRACE("Enter GetLongPathNameW\n");
	return pGetLongPathNameW(shortpath, longpath, longlen);
}

extern WINAPI void wine32a_kernel32_GetLongPathNameW(void);  /* ../dlls/kernel32/path.c:289 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetLongPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetLongPathNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetMailslotInfo(HANDLE  hMailslot, LPDWORD  lpMaxMessageSize, LPDWORD  lpNextSize, LPDWORD  lpMessageCount, LPDWORD  lpReadTimeout) /* ../dlls/kernel32/sync.c:923 */
{
	TRACE("Enter GetMailslotInfo\n");
	return pGetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout);
}

extern WINAPI void wine32a_kernel32_GetMailslotInfo(void);  /* ../dlls/kernel32/sync.c:923 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetMailslotInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetMailslotInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetMaximumProcessorCount(WORD  group) /* ../dlls/kernel32/cpu.c:272 */
{
	TRACE("Enter GetMaximumProcessorCount\n");
	return pGetMaximumProcessorCount(group);
}

extern WINAPI void wine32a_kernel32_GetMaximumProcessorCount(void);  /* ../dlls/kernel32/cpu.c:272 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetMaximumProcessorCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetMaximumProcessorCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeClientProcessId(HANDLE  pipe, ULONG*  id) /* ../dlls/kernel32/sync.c:566 */
{
	TRACE("Enter GetNamedPipeClientProcessId\n");
	return pGetNamedPipeClientProcessId(pipe, id);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeClientProcessId(void);  /* ../dlls/kernel32/sync.c:566 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeClientProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeClientProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeClientSessionId(HANDLE  pipe, ULONG*  id) /* ../dlls/kernel32/sync.c:606 */
{
	TRACE("Enter GetNamedPipeClientSessionId\n");
	return pGetNamedPipeClientSessionId(pipe, id);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeClientSessionId(void);  /* ../dlls/kernel32/sync.c:606 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeClientSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeClientSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeHandleStateA(HANDLE  hNamedPipe, LPDWORD  lpState, LPDWORD  lpCurInstances, LPDWORD  lpMaxCollectionCount, LPDWORD  lpCollectDataTimeout, LPSTR  lpUsername, DWORD  nUsernameMaxSize) /* ../dlls/kernel32/sync.c:630 */
{
	TRACE("Enter GetNamedPipeHandleStateA\n");
	return pGetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeHandleStateA(void);  /* ../dlls/kernel32/sync.c:630 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeHandleStateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeHandleStateA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeHandleStateW(HANDLE  hNamedPipe, LPDWORD  lpState, LPDWORD  lpCurInstances, LPDWORD  lpMaxCollectionCount, LPDWORD  lpCollectDataTimeout, LPWSTR  lpUsername, DWORD  nUsernameMaxSize) /* ../dlls/kernel32/sync.c:656 */
{
	TRACE("Enter GetNamedPipeHandleStateW\n");
	return pGetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeHandleStateW(void);  /* ../dlls/kernel32/sync.c:656 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeHandleStateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeHandleStateW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeServerProcessId(HANDLE  pipe, ULONG*  id) /* ../dlls/kernel32/sync.c:586 */
{
	TRACE("Enter GetNamedPipeServerProcessId\n");
	return pGetNamedPipeServerProcessId(pipe, id);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeServerProcessId(void);  /* ../dlls/kernel32/sync.c:586 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeServerProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeServerProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNamedPipeServerSessionId(HANDLE  pipe, ULONG*  id) /* ../dlls/kernel32/sync.c:618 */
{
	TRACE("Enter GetNamedPipeServerSessionId\n");
	return pGetNamedPipeServerSessionId(pipe, id);
}

extern WINAPI void wine32a_kernel32_GetNamedPipeServerSessionId(void);  /* ../dlls/kernel32/sync.c:618 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNamedPipeServerSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNamedPipeServerSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GetNativeSystemInfo(LPSYSTEM_INFO  si) /* ../dlls/kernel32/cpu.c:129 */
{
	TRACE("Enter GetNativeSystemInfo\n");
	return pGetNativeSystemInfo(si);
}

extern WINAPI void wine32a_kernel32_GetNativeSystemInfo(void);  /* ../dlls/kernel32/cpu.c:129 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNativeSystemInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNativeSystemInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI PUMS_CONTEXT wine32b_kernel32_GetNextUmsListItem(PUMS_CONTEXT  ctx) /* ../dlls/kernel32/process.c:4206 */
{
	TRACE("Enter GetNextUmsListItem\n");
	return pGetNextUmsListItem(ctx);
}

extern WINAPI void wine32a_kernel32_GetNextUmsListItem(void);  /* ../dlls/kernel32/process.c:4206 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNextUmsListItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNextUmsListItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaAvailableMemoryNode(UCHAR  node, PULONGLONG  available_bytes) /* ../dlls/kernel32/process.c:4005 */
{
	TRACE("Enter GetNumaAvailableMemoryNode\n");
	return pGetNumaAvailableMemoryNode(node, available_bytes);
}

extern WINAPI void wine32a_kernel32_GetNumaAvailableMemoryNode(void);  /* ../dlls/kernel32/process.c:4005 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaAvailableMemoryNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaAvailableMemoryNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaAvailableMemoryNodeEx(USHORT  node, PULONGLONG  available_bytes) /* ../dlls/kernel32/process.c:4015 */
{
	TRACE("Enter GetNumaAvailableMemoryNodeEx\n");
	return pGetNumaAvailableMemoryNodeEx(node, available_bytes);
}

extern WINAPI void wine32a_kernel32_GetNumaAvailableMemoryNodeEx(void);  /* ../dlls/kernel32/process.c:4015 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaAvailableMemoryNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaAvailableMemoryNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaHighestNodeNumber(PULONG  highestnode) /* ../dlls/kernel32/process.c:3975 */
{
	TRACE("Enter GetNumaHighestNodeNumber\n");
	return pGetNumaHighestNodeNumber(highestnode);
}

extern WINAPI void wine32a_kernel32_GetNumaHighestNodeNumber(void);  /* ../dlls/kernel32/process.c:3975 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaHighestNodeNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaHighestNodeNumber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaNodeProcessorMask(UCHAR  node, PULONGLONG  mask) /* ../dlls/kernel32/process.c:3985 */
{
	TRACE("Enter GetNumaNodeProcessorMask\n");
	return pGetNumaNodeProcessorMask(node, mask);
}

extern WINAPI void wine32a_kernel32_GetNumaNodeProcessorMask(void);  /* ../dlls/kernel32/process.c:3985 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaNodeProcessorMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaNodeProcessorMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaNodeProcessorMaskEx(USHORT  node, PGROUP_AFFINITY  mask) /* ../dlls/kernel32/process.c:3995 */
{
	TRACE("Enter GetNumaNodeProcessorMaskEx\n");
	return pGetNumaNodeProcessorMaskEx(node, mask);
}

extern WINAPI void wine32a_kernel32_GetNumaNodeProcessorMaskEx(void);  /* ../dlls/kernel32/process.c:3995 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaNodeProcessorMaskEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaNodeProcessorMaskEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaProcessorNode(UCHAR  processor, PUCHAR  node) /* ../dlls/kernel32/process.c:4025 */
{
	TRACE("Enter GetNumaProcessorNode\n");
	return pGetNumaProcessorNode(processor, node);
}

extern WINAPI void wine32a_kernel32_GetNumaProcessorNode(void);  /* ../dlls/kernel32/process.c:4025 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaProcessorNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaProcessorNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaProcessorNodeEx(PPROCESSOR_NUMBER  processor, PUSHORT  node_number) /* ../dlls/kernel32/process.c:4046 */
{
	TRACE("Enter GetNumaProcessorNodeEx\n");
	return pGetNumaProcessorNodeEx(processor, node_number);
}

extern WINAPI void wine32a_kernel32_GetNumaProcessorNodeEx(void);  /* ../dlls/kernel32/process.c:4046 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaProcessorNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaProcessorNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaProximityNode(ULONG  proximity_id, PUCHAR  node_number) /* ../dlls/kernel32/process.c:4055 */
{
	TRACE("Enter GetNumaProximityNode\n");
	return pGetNumaProximityNode(proximity_id, node_number);
}

extern WINAPI void wine32a_kernel32_GetNumaProximityNode(void);  /* ../dlls/kernel32/process.c:4055 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaProximityNode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaProximityNode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetNumaProximityNodeEx(ULONG  proximity_id, PUSHORT  node_number) /* ../dlls/kernel32/process.c:4064 */
{
	TRACE("Enter GetNumaProximityNodeEx\n");
	return pGetNumaProximityNodeEx(proximity_id, node_number);
}

extern WINAPI void wine32a_kernel32_GetNumaProximityNodeEx(void);  /* ../dlls/kernel32/process.c:4064 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumaProximityNodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumaProximityNodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetNumberFormatA(LCID  lcid, DWORD  dwFlags, LPCSTR  lpszValue, NUMBERFMTA*  lpFormat, LPSTR  lpNumberStr, int  cchOut) /* ../dlls/kernel32/lcformat.c:1029 */
{
	TRACE("Enter GetNumberFormatA\n");
	return pGetNumberFormatA(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetNumberFormatA(void);  /* ../dlls/kernel32/lcformat.c:1029 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumberFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumberFormatA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetNumberFormatEx(LPCWSTR  name, DWORD  flags, LPCWSTR  value, NUMBERFMTW*  format, LPWSTR  number, int  numout) /* ../dlls/kernel32/lcformat.c:1350 */
{
	TRACE("Enter GetNumberFormatEx\n");
	return pGetNumberFormatEx(name, flags, value, format, number, numout);
}

extern WINAPI void wine32a_kernel32_GetNumberFormatEx(void);  /* ../dlls/kernel32/lcformat.c:1350 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumberFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumberFormatEx") "\n"
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

extern WINAPI INT wine32b_kernel32_GetNumberFormatW(LCID  lcid, DWORD  dwFlags, LPCWSTR  lpszValue, NUMBERFMTW*  lpFormat, LPWSTR  lpNumberStr, int  cchOut) /* ../dlls/kernel32/lcformat.c:1111 */
{
	TRACE("Enter GetNumberFormatW\n");
	return pGetNumberFormatW(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetNumberFormatW(void);  /* ../dlls/kernel32/lcformat.c:1111 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumberFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumberFormatW") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetNumberOfConsoleFonts(void) /* ../dlls/kernel32/console.c:1622 */
{
	TRACE("Enter GetNumberOfConsoleFonts\n");
	return pGetNumberOfConsoleFonts();
}

extern WINAPI void wine32a_kernel32_GetNumberOfConsoleFonts(void);  /* ../dlls/kernel32/console.c:1622 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumberOfConsoleFonts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumberOfConsoleFonts") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetNumberOfConsoleMouseButtons(LPDWORD  nrofbuttons) /* ../dlls/kernel32/console.c:832 */
{
	TRACE("Enter GetNumberOfConsoleMouseButtons\n");
	return pGetNumberOfConsoleMouseButtons(nrofbuttons);
}

extern WINAPI void wine32a_kernel32_GetNumberOfConsoleMouseButtons(void);  /* ../dlls/kernel32/console.c:832 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetNumberOfConsoleMouseButtons,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetNumberOfConsoleMouseButtons") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetOEMCP(void) /* ../dlls/kernel32/locale.c:2048 */
{
	TRACE("Enter GetOEMCP\n");
	return pGetOEMCP();
}

extern WINAPI void wine32a_kernel32_GetOEMCP(void);  /* ../dlls/kernel32/locale.c:2048 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetOEMCP,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetOEMCP") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetUserPreferredUILanguages(DWORD  flags, ULONG*  count, WCHAR*  buffer, ULONG*  size) /* ../dlls/kernel32/locale.c:1351 */
{
	TRACE("Enter GetUserPreferredUILanguages\n");
	return pGetUserPreferredUILanguages(flags, count, buffer, size);
}

extern WINAPI void wine32a_kernel32_GetUserPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1351 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_GetPackageFullName(HANDLE  process, UINT32*  length, PWSTR  name) /* ../dlls/kernel32/version.c:158 */
{
	TRACE("Enter GetPackageFullName\n");
	return pGetPackageFullName(process, length, name);
}

extern WINAPI void wine32a_kernel32_GetPackageFullName(void);  /* ../dlls/kernel32/version.c:158 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPackageFullName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPackageFullName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetPhysicallyInstalledSystemMemory(ULONGLONG*  total_memory) /* ../dlls/kernel32/heap.c:897 */
{
	TRACE("Enter GetPhysicallyInstalledSystemMemory\n");
	return pGetPhysicallyInstalledSystemMemory(total_memory);
}

extern WINAPI void wine32a_kernel32_GetPhysicallyInstalledSystemMemory(void);  /* ../dlls/kernel32/heap.c:897 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPhysicallyInstalledSystemMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPhysicallyInstalledSystemMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetPrivateProfileIntA(LPCSTR  section, LPCSTR  entry, INT  def_val, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1254 */
{
	TRACE("Enter GetPrivateProfileIntA\n");
	return pGetPrivateProfileIntA(section, entry, def_val, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileIntA(void);  /* ../dlls/kernel32/profile.c:1254 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileIntA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileIntA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetPrivateProfileIntW(LPCWSTR  section, LPCWSTR  entry, INT  def_val, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1226 */
{
	TRACE("Enter GetPrivateProfileIntW\n");
	return pGetPrivateProfileIntW(section, entry, def_val, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileIntW(void);  /* ../dlls/kernel32/profile.c:1226 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileIntW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileIntW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetPrivateProfileSectionA(LPCSTR  section, LPSTR  buffer, DWORD  len, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1302 */
{
	TRACE("Enter GetPrivateProfileSectionA\n");
	return pGetPrivateProfileSectionA(section, buffer, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileSectionA(void);  /* ../dlls/kernel32/profile.c:1302 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileSectionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetPrivateProfileSectionNamesA(LPSTR  buffer, DWORD  size, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1572 */
{
	TRACE("Enter GetPrivateProfileSectionNamesA\n");
	return pGetPrivateProfileSectionNamesA(buffer, size, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileSectionNamesA(void);  /* ../dlls/kernel32/profile.c:1572 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileSectionNamesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileSectionNamesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetPrivateProfileSectionNamesW(LPWSTR  buffer, DWORD  size, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1553 */
{
	TRACE("Enter GetPrivateProfileSectionNamesW\n");
	return pGetPrivateProfileSectionNamesW(buffer, size, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileSectionNamesW(void);  /* ../dlls/kernel32/profile.c:1553 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileSectionNamesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileSectionNamesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetPrivateProfileSectionW(LPCWSTR  section, LPWSTR  buffer, DWORD  len, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1276 */
{
	TRACE("Enter GetPrivateProfileSectionW\n");
	return pGetPrivateProfileSectionW(section, buffer, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileSectionW(void);  /* ../dlls/kernel32/profile.c:1276 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileSectionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetPrivateProfileStringA(LPCSTR  section, LPCSTR  entry, LPCSTR  def_val, LPSTR  buffer, UINT  len, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1144 */
{
	TRACE("Enter GetPrivateProfileStringA\n");
	return pGetPrivateProfileStringA(section, entry, def_val, buffer, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileStringA(void);  /* ../dlls/kernel32/profile.c:1144 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileStringA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetPrivateProfileStringW(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  def_val, LPWSTR  buffer, UINT  len, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1088 */
{
	TRACE("Enter GetPrivateProfileStringW\n");
	return pGetPrivateProfileStringW(section, entry, def_val, buffer, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileStringW(void);  /* ../dlls/kernel32/profile.c:1088 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileStringW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetPrivateProfileStructA(LPCSTR  section, LPCSTR  key, LPVOID  buffer, UINT  len, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1681 */
{
	TRACE("Enter GetPrivateProfileStructA\n");
	return pGetPrivateProfileStructA(section, key, buffer, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileStructA(void);  /* ../dlls/kernel32/profile.c:1681 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileStructA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileStructA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetPrivateProfileStructW(LPCWSTR  section, LPCWSTR  key, LPVOID  buf, UINT  len, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1608 */
{
	TRACE("Enter GetPrivateProfileStructW\n");
	return pGetPrivateProfileStructW(section, key, buf, len, filename);
}

extern WINAPI void wine32a_kernel32_GetPrivateProfileStructW(void);  /* ../dlls/kernel32/profile.c:1608 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetPrivateProfileStructW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetPrivateProfileStructW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI FARPROC wine32b_kernel32_GetProcAddress(HMODULE  hModule, LPCSTR  function) /* ../dlls/kernel32/module.c:1016 */
{
	TRACE("Enter GetProcAddress\n");
	return pGetProcAddress(hModule, function);
}

extern WINAPI void wine32a_kernel32_GetProcAddress(void);  /* ../dlls/kernel32/module.c:1016 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessAffinityMask(HANDLE  hProcess, PDWORD_PTR  process_mask, PDWORD_PTR  system_mask) /* ../dlls/kernel32/process.c:3404 */
{
	TRACE("Enter GetProcessAffinityMask\n");
	return pGetProcessAffinityMask(hProcess, process_mask, system_mask);
}

extern WINAPI void wine32a_kernel32_GetProcessAffinityMask(void);  /* ../dlls/kernel32/process.c:3404 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessAffinityMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessDEPPolicy(HANDLE  process, LPDWORD  flags, PBOOL  permanent) /* ../dlls/kernel32/process.c:4073 */
{
	TRACE("Enter GetProcessDEPPolicy\n");
	return pGetProcessDEPPolicy(process, flags, permanent);
}

extern WINAPI void wine32a_kernel32_GetProcessDEPPolicy(void);  /* ../dlls/kernel32/process.c:4073 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessDEPPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetProcessFlags(DWORD  processid) /* ../dlls/kernel32/process.c:3208 */
{
	TRACE("Enter GetProcessFlags\n");
	return pGetProcessFlags(processid);
}

extern WINAPI void wine32a_kernel32_GetProcessFlags(void);  /* ../dlls/kernel32/process.c:3208 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessIoCounters(HANDLE  hProcess, PIO_COUNTERS  ioc) /* ../dlls/kernel32/process.c:3521 */
{
	TRACE("Enter GetProcessIoCounters\n");
	return pGetProcessIoCounters(hProcess, ioc);
}

extern WINAPI void wine32a_kernel32_GetProcessIoCounters(void);  /* ../dlls/kernel32/process.c:3521 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessIoCounters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessIoCounters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessPreferredUILanguages(DWORD  flags, ULONG*  count, WCHAR*  buf, ULONG*  size) /* ../dlls/kernel32/locale.c:1291 */
{
	TRACE("Enter GetProcessPreferredUILanguages\n");
	return pGetProcessPreferredUILanguages(flags, count, buf, size);
}

extern WINAPI void wine32a_kernel32_GetProcessPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1291 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessTimes(HANDLE  hprocess, LPFILETIME  lpCreationTime, LPFILETIME  lpExitTime, LPFILETIME  lpKernelTime, LPFILETIME  lpUserTime) /* ../dlls/kernel32/time.c:890 */
{
	TRACE("Enter GetProcessTimes\n");
	return pGetProcessTimes(hprocess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime);
}

extern WINAPI void wine32a_kernel32_GetProcessTimes(void);  /* ../dlls/kernel32/time.c:890 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessTimes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessTimes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetProcessVersion(DWORD  pid) /* ../dlls/kernel32/process.c:3430 */
{
	TRACE("Enter GetProcessVersion\n");
	return pGetProcessVersion(pid);
}

extern WINAPI void wine32a_kernel32_GetProcessVersion(void);  /* ../dlls/kernel32/process.c:3430 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessVersion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessVersion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProcessWorkingSetSize(HANDLE  process, SIZE_T*  minset, SIZE_T*  maxset) /* ../dlls/kernel32/process.c:3512 */
{
	TRACE("Enter GetProcessWorkingSetSize\n");
	return pGetProcessWorkingSetSize(process, minset, maxset);
}

extern WINAPI void wine32a_kernel32_GetProcessWorkingSetSize(void);  /* ../dlls/kernel32/process.c:3512 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProcessWorkingSetSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProcessWorkingSetSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetProductInfo(DWORD  dwOSMajorVersion, DWORD  dwOSMinorVersion, DWORD  dwSpMajorVersion, DWORD  dwSpMinorVersion, PDWORD  pdwReturnedProductType) /* ../dlls/kernel32/version.c:121 */
{
	TRACE("Enter GetProductInfo\n");
	return pGetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
}

extern WINAPI void wine32a_kernel32_GetProductInfo(void);  /* ../dlls/kernel32/version.c:121 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProductInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProductInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetProfileIntA(LPCSTR  section, LPCSTR  entry, INT  def_val) /* ../dlls/kernel32/profile.c:1072 */
{
	TRACE("Enter GetProfileIntA\n");
	return pGetProfileIntA(section, entry, def_val);
}

extern WINAPI void wine32a_kernel32_GetProfileIntA(void);  /* ../dlls/kernel32/profile.c:1072 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileIntA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileIntA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetProfileIntW(LPCWSTR  section, LPCWSTR  entry, INT  def_val) /* ../dlls/kernel32/profile.c:1080 */
{
	TRACE("Enter GetProfileIntW\n");
	return pGetProfileIntW(section, entry, def_val);
}

extern WINAPI void wine32a_kernel32_GetProfileIntW(void);  /* ../dlls/kernel32/profile.c:1080 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileIntW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileIntW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetProfileSectionA(LPCSTR  section, LPSTR  buffer, DWORD  len) /* ../dlls/kernel32/profile.c:1348 */
{
	TRACE("Enter GetProfileSectionA\n");
	return pGetProfileSectionA(section, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetProfileSectionA(void);  /* ../dlls/kernel32/profile.c:1348 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileSectionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetProfileSectionW(LPCWSTR  section, LPWSTR  buffer, DWORD  len) /* ../dlls/kernel32/profile.c:1356 */
{
	TRACE("Enter GetProfileSectionW\n");
	return pGetProfileSectionW(section, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetProfileSectionW(void);  /* ../dlls/kernel32/profile.c:1356 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileSectionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetProfileStringA(LPCSTR  section, LPCSTR  entry, LPCSTR  def_val, LPSTR  buffer, UINT  len) /* ../dlls/kernel32/profile.c:1187 */
{
	TRACE("Enter GetProfileStringA\n");
	return pGetProfileStringA(section, entry, def_val, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetProfileStringA(void);  /* ../dlls/kernel32/profile.c:1187 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_GetProfileStringW(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  def_val, LPWSTR  buffer, UINT  len) /* ../dlls/kernel32/profile.c:1197 */
{
	TRACE("Enter GetProfileStringW\n");
	return pGetProfileStringW(section, entry, def_val, buffer, len);
}

extern WINAPI void wine32a_kernel32_GetProfileStringW(void);  /* ../dlls/kernel32/profile.c:1197 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetProfileStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetShortPathNameA(LPCSTR  longpath, LPSTR  shortpath, DWORD  shortlen) /* ../dlls/kernel32/path.c:574 */
{
	TRACE("Enter GetShortPathNameA\n");
	return pGetShortPathNameA(longpath, shortpath, shortlen);
}

extern WINAPI void wine32a_kernel32_GetShortPathNameA(void);  /* ../dlls/kernel32/path.c:574 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetShortPathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetShortPathNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetShortPathNameW(LPCWSTR  longpath, LPWSTR  shortpath, DWORD  shortlen) /* ../dlls/kernel32/path.c:447 */
{
	TRACE("Enter GetShortPathNameW\n");
	return pGetShortPathNameW(longpath, shortpath, shortlen);
}

extern WINAPI void wine32a_kernel32_GetShortPathNameW(void);  /* ../dlls/kernel32/path.c:447 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetShortPathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetShortPathNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GetStartupInfoA(LPSTARTUPINFOA  info) /* ../dlls/kernel32/environ.c:54 */
{
	TRACE("Enter GetStartupInfoA\n");
	return pGetStartupInfoA(info);
}

extern WINAPI void wine32a_kernel32_GetStartupInfoA(void);  /* ../dlls/kernel32/environ.c:54 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetStartupInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetStartupInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetStringTypeA(LCID  locale, DWORD  type, LPCSTR  src, INT  count, LPWORD  chartype) /* ../dlls/kernel32/locale.c:3181 */
{
	TRACE("Enter GetStringTypeA\n");
	return pGetStringTypeA(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_kernel32_GetStringTypeA(void);  /* ../dlls/kernel32/locale.c:3181 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetStringTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetStringTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetStringTypeExA(LCID  locale, DWORD  type, LPCSTR  src, INT  count, LPWORD  chartype) /* ../dlls/kernel32/locale.c:3228 */
{
	TRACE("Enter GetStringTypeExA\n");
	return pGetStringTypeExA(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_kernel32_GetStringTypeExA(void);  /* ../dlls/kernel32/locale.c:3228 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetStringTypeExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetStringTypeExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetStringTypeExW(LCID  locale, DWORD  type, LPCWSTR  src, INT  count, LPWORD  chartype) /* ../dlls/kernel32/locale.c:3157 */
{
	TRACE("Enter GetStringTypeExW\n");
	return pGetStringTypeExW(locale, type, src, count, chartype);
}

extern WINAPI void wine32a_kernel32_GetStringTypeExW(void);  /* ../dlls/kernel32/locale.c:3157 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetStringTypeExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetStringTypeExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetStringTypeW(DWORD  type, LPCWSTR  src, INT  count, LPWORD  chartype) /* ../dlls/kernel32/locale.c:3087 */
{
	TRACE("Enter GetStringTypeW\n");
	return pGetStringTypeW(type, src, count, chartype);
}

extern WINAPI void wine32a_kernel32_GetStringTypeW(void);  /* ../dlls/kernel32/locale.c:3087 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetStringTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetStringTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemFileCacheSize(PSIZE_T  mincache, PSIZE_T  maxcache, PDWORD  flags) /* ../dlls/kernel32/heap.c:915 */
{
	TRACE("Enter GetSystemFileCacheSize\n");
	return pGetSystemFileCacheSize(mincache, maxcache, flags);
}

extern WINAPI void wine32a_kernel32_GetSystemFileCacheSize(void);  /* ../dlls/kernel32/heap.c:915 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemFileCacheSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemFileCacheSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_kernel32_GetSystemDefaultLCID(void) /* ../dlls/kernel32/locale.c:1226 */
{
	TRACE("Enter GetSystemDefaultLCID\n");
	return pGetSystemDefaultLCID();
}

extern WINAPI void wine32a_kernel32_GetSystemDefaultLCID(void);  /* ../dlls/kernel32/locale.c:1226 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDefaultLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDefaultLCID") "\n"
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

extern WINAPI LANGID wine32b_kernel32_GetSystemDefaultLangID(void) /* ../dlls/kernel32/locale.c:1190 */
{
	TRACE("Enter GetSystemDefaultLangID\n");
	return pGetSystemDefaultLangID();
}

extern WINAPI void wine32a_kernel32_GetSystemDefaultLangID(void);  /* ../dlls/kernel32/locale.c:1190 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDefaultLangID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDefaultLangID") "\n"
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

extern WINAPI INT wine32b_kernel32_GetSystemDefaultLocaleName(LPWSTR  localename, INT  len) /* ../dlls/kernel32/locale.c:1236 */
{
	TRACE("Enter GetSystemDefaultLocaleName\n");
	return pGetSystemDefaultLocaleName(localename, len);
}

extern WINAPI void wine32a_kernel32_GetSystemDefaultLocaleName(void);  /* ../dlls/kernel32/locale.c:1236 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDefaultLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDefaultLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LANGID wine32b_kernel32_GetSystemDefaultUILanguage(void) /* ../dlls/kernel32/locale.c:1405 */
{
	TRACE("Enter GetSystemDefaultUILanguage\n");
	return pGetSystemDefaultUILanguage();
}

extern WINAPI void wine32a_kernel32_GetSystemDefaultUILanguage(void);  /* ../dlls/kernel32/locale.c:1405 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDefaultUILanguage") "\n"
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

extern WINAPI DEP_SYSTEM_POLICY_TYPE wine32b_kernel32_GetSystemDEPPolicy(void) /* ../dlls/kernel32/process.c:3918 */
{
	TRACE("Enter GetSystemDEPPolicy\n");
	return pGetSystemDEPPolicy();
}

extern WINAPI void wine32a_kernel32_GetSystemDEPPolicy(void);  /* ../dlls/kernel32/process.c:3918 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDEPPolicy") "\n"
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

extern WINAPI UINT wine32b_kernel32_GetSystemDirectoryA(LPSTR  path, UINT  count) /* ../dlls/kernel32/path.c:1782 */
{
	TRACE("Enter GetSystemDirectoryA\n");
	return pGetSystemDirectoryA(path, count);
}

extern WINAPI void wine32a_kernel32_GetSystemDirectoryA(void);  /* ../dlls/kernel32/path.c:1782 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetSystemDirectoryW(LPWSTR  path, UINT  count) /* ../dlls/kernel32/path.c:1765 */
{
	TRACE("Enter GetSystemDirectoryW\n");
	return pGetSystemDirectoryW(path, count);
}

extern WINAPI void wine32a_kernel32_GetSystemDirectoryW(void);  /* ../dlls/kernel32/path.c:1765 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetSystemFirmwareTable(DWORD  provider, DWORD  id, void*  buffer, DWORD  size) /* ../dlls/kernel32/cpu.c:296 */
{
	TRACE("Enter GetSystemFirmwareTable\n");
	return pGetSystemFirmwareTable(provider, id, buffer, size);
}

extern WINAPI void wine32a_kernel32_GetSystemFirmwareTable(void);  /* ../dlls/kernel32/cpu.c:296 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemFirmwareTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemFirmwareTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GetSystemInfo(LPSYSTEM_INFO  si) /* ../dlls/kernel32/cpu.c:57 */
{
	TRACE("Enter GetSystemInfo\n");
	return pGetSystemInfo(si);
}

extern WINAPI void wine32a_kernel32_GetSystemInfo(void);  /* ../dlls/kernel32/cpu.c:57 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemPowerStatus(LPSYSTEM_POWER_STATUS  ps) /* ../dlls/kernel32/powermgnt.c:46 */
{
	TRACE("Enter GetSystemPowerStatus\n");
	return pGetSystemPowerStatus(ps);
}

extern WINAPI void wine32a_kernel32_GetSystemPowerStatus(void);  /* ../dlls/kernel32/powermgnt.c:46 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemPowerStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemPowerStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemPreferredUILanguages(DWORD  flags, ULONG*  count, WCHAR*  buffer, ULONG*  size) /* ../dlls/kernel32/locale.c:1300 */
{
	TRACE("Enter GetSystemPreferredUILanguages\n");
	return pGetSystemPreferredUILanguages(flags, count, buffer, size);
}

extern WINAPI void wine32a_kernel32_GetSystemPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1300 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemRegistryQuota(PDWORD  pdwQuotaAllowed, PDWORD  pdwQuotaUsed) /* ../dlls/kernel32/kernel_main.c:184 */
{
	TRACE("Enter GetSystemRegistryQuota\n");
	return pGetSystemRegistryQuota(pdwQuotaAllowed, pdwQuotaUsed);
}

extern WINAPI void wine32a_kernel32_GetSystemRegistryQuota(void);  /* ../dlls/kernel32/kernel_main.c:184 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemRegistryQuota,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemRegistryQuota") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GetSystemTime(LPSYSTEMTIME  systime) /* ../dlls/kernel32/time.c:1323 */
{
	TRACE("Enter GetSystemTime\n");
	return pGetSystemTime(systime);
}

extern WINAPI void wine32a_kernel32_GetSystemTime(void);  /* ../dlls/kernel32/time.c:1323 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemTimeAdjustment(PDWORD  lpTimeAdjustment, PDWORD  lpTimeIncrement, PBOOL  lpTimeAdjustmentDisabled) /* ../dlls/kernel32/time.c:566 */
{
	TRACE("Enter GetSystemTimeAdjustment\n");
	return pGetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled);
}

extern WINAPI void wine32a_kernel32_GetSystemTimeAdjustment(void);  /* ../dlls/kernel32/time.c:566 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemTimeAdjustment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemTimeAdjustment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GetSystemTimePreciseAsFileTime(FILETIME*  time) /* ../dlls/kernel32/time.c:798 */
{
	TRACE("Enter GetSystemTimePreciseAsFileTime\n");
	return pGetSystemTimePreciseAsFileTime(time);
}

extern WINAPI void wine32a_kernel32_GetSystemTimePreciseAsFileTime(void);  /* ../dlls/kernel32/time.c:798 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemTimePreciseAsFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemTimePreciseAsFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetSystemTimes(LPFILETIME  lpIdleTime, LPFILETIME  lpKernelTime, LPFILETIME  lpUserTime) /* ../dlls/kernel32/time.c:1428 */
{
	TRACE("Enter GetSystemTimes\n");
	return pGetSystemTimes(lpIdleTime, lpKernelTime, lpUserTime);
}

extern WINAPI void wine32a_kernel32_GetSystemTimes(void);  /* ../dlls/kernel32/time.c:1428 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemTimes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemTimes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetSystemWow64DirectoryA(LPSTR  path, UINT  count) /* ../dlls/kernel32/path.c:1819 */
{
	TRACE("Enter GetSystemWow64DirectoryA\n");
	return pGetSystemWow64DirectoryA(path, count);
}

extern WINAPI void wine32a_kernel32_GetSystemWow64DirectoryA(void);  /* ../dlls/kernel32/path.c:1819 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemWow64DirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemWow64DirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetSystemWow64DirectoryW(LPWSTR  path, UINT  count) /* ../dlls/kernel32/path.c:1795 */
{
	TRACE("Enter GetSystemWow64DirectoryW\n");
	return pGetSystemWow64DirectoryW(path, count);
}

extern WINAPI void wine32a_kernel32_GetSystemWow64DirectoryW(void);  /* ../dlls/kernel32/path.c:1795 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetSystemWow64DirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetSystemWow64DirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTapeParameters(HANDLE  device, DWORD  operation, LPDWORD  size, LPVOID  info) /* ../dlls/kernel32/tape.c:144 */
{
	TRACE("Enter GetTapeParameters\n");
	return pGetTapeParameters(device, operation, size, info);
}

extern WINAPI void wine32a_kernel32_GetTapeParameters(void);  /* ../dlls/kernel32/tape.c:144 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTapeParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTapeParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTapePosition(HANDLE  device, DWORD  type, LPDWORD  partition, LPDWORD  offset_low, LPDWORD  offset_high) /* ../dlls/kernel32/tape.c:175 */
{
	TRACE("Enter GetTapePosition\n");
	return pGetTapePosition(device, type, partition, offset_low, offset_high);
}

extern WINAPI void wine32a_kernel32_GetTapePosition(void);  /* ../dlls/kernel32/tape.c:175 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTapePosition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTapePosition") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTapeStatus(HANDLE  device) /* ../dlls/kernel32/tape.c:208 */
{
	TRACE("Enter GetTapeStatus\n");
	return pGetTapeStatus(device);
}

extern WINAPI void wine32a_kernel32_GetTapeStatus(void);  /* ../dlls/kernel32/tape.c:208 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTapeStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTapeStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetTempFileNameA(LPCSTR  path, LPCSTR  prefix, UINT  unique, LPSTR  buffer) /* ../dlls/kernel32/path.c:682 */
{
	TRACE("Enter GetTempFileNameA\n");
	return pGetTempFileNameA(path, prefix, unique, buffer);
}

extern WINAPI void wine32a_kernel32_GetTempFileNameA(void);  /* ../dlls/kernel32/path.c:682 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTempFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTempFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GetTempFileNameW(LPCWSTR  path, LPCWSTR  prefix, UINT  unique, LPWSTR  buffer) /* ../dlls/kernel32/path.c:701 */
{
	TRACE("Enter GetTempFileNameW\n");
	return pGetTempFileNameW(path, prefix, unique, buffer);
}

extern WINAPI void wine32a_kernel32_GetTempFileNameW(void);  /* ../dlls/kernel32/path.c:701 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTempFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTempFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTempPathA(DWORD  count, LPSTR  path) /* ../dlls/kernel32/path.c:599 */
{
	TRACE("Enter GetTempPathA\n");
	return pGetTempPathA(count, path);
}

extern WINAPI void wine32a_kernel32_GetTempPathA(void);  /* ../dlls/kernel32/path.c:599 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTempPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTempPathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTempPathW(DWORD  count, LPWSTR  path) /* ../dlls/kernel32/path.c:621 */
{
	TRACE("Enter GetTempPathW\n");
	return pGetTempPathW(count, path);
}

extern WINAPI void wine32a_kernel32_GetTempPathW(void);  /* ../dlls/kernel32/path.c:621 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTempPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTempPathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_kernel32_GetThreadLocale(void) /* ../dlls/kernel32/locale.c:2793 */
{
	TRACE("Enter GetThreadLocale\n");
	return pGetThreadLocale();
}

extern WINAPI void wine32a_kernel32_GetThreadLocale(void);  /* ../dlls/kernel32/locale.c:2793 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetThreadLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetThreadLocale") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetThreadPreferredUILanguages(DWORD  flags, ULONG*  count, WCHAR*  buf, ULONG*  size) /* ../dlls/kernel32/locale.c:1342 */
{
	TRACE("Enter GetThreadPreferredUILanguages\n");
	return pGetThreadPreferredUILanguages(flags, count, buf, size);
}

extern WINAPI void wine32a_kernel32_GetThreadPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1342 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetThreadPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetThreadPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetThreadSelectorEntry(HANDLE  hthread, DWORD  sel, LPLDT_ENTRY  ldtent) /* ../dlls/kernel32/thread.c:110 */
{
	TRACE("Enter GetThreadSelectorEntry\n");
	return pGetThreadSelectorEntry(hthread, sel, ldtent);
}

extern WINAPI void wine32a_kernel32_GetThreadSelectorEntry(void);  /* ../dlls/kernel32/thread.c:110 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetThreadSelectorEntry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetThreadSelectorEntry") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_GetTickCount(void) /* ../dlls/kernel32/time.c:1584 */
{
	TRACE("Enter GetTickCount\n");
	return pGetTickCount();
}

extern WINAPI void wine32a_kernel32_GetTickCount(void);  /* ../dlls/kernel32/time.c:1584 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTickCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTickCount") "\n"
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

extern WINAPI ULONGLONG wine32b_kernel32_GetTickCount64(void) /* ../dlls/kernel32/time.c:1565 */
{
	TRACE("Enter GetTickCount64\n");
	return pGetTickCount64();
}

extern WINAPI void wine32a_kernel32_GetTickCount64(void);  /* ../dlls/kernel32/time.c:1565 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTickCount64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTickCount64") "\n"
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

extern WINAPI INT wine32b_kernel32_GetTimeFormatA(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCSTR  lpFormat, LPSTR  lpTimeStr, INT  cchOut) /* ../dlls/kernel32/lcformat.c:945 */
{
	TRACE("Enter GetTimeFormatA\n");
	return pGetTimeFormatA(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetTimeFormatA(void);  /* ../dlls/kernel32/lcformat.c:945 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTimeFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTimeFormatA") "\n"
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

extern WINAPI INT wine32b_kernel32_GetTimeFormatEx(LPCWSTR  localename, DWORD  flags, SYSTEMTIME*  time, LPCWSTR  format, LPWSTR  outbuf, INT  bufsize) /* ../dlls/kernel32/lcformat.c:975 */
{
	TRACE("Enter GetTimeFormatEx\n");
	return pGetTimeFormatEx(localename, flags, time, format, outbuf, bufsize);
}

extern WINAPI void wine32a_kernel32_GetTimeFormatEx(void);  /* ../dlls/kernel32/lcformat.c:975 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTimeFormatEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTimeFormatEx") "\n"
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

extern WINAPI INT wine32b_kernel32_GetTimeFormatW(LCID  lcid, DWORD  dwFlags, SYSTEMTIME*  lpTime, LPCWSTR  lpFormat, LPWSTR  lpTimeStr, INT  cchOut) /* ../dlls/kernel32/lcformat.c:992 */
{
	TRACE("Enter GetTimeFormatW\n");
	return pGetTimeFormatW(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
}

extern WINAPI void wine32a_kernel32_GetTimeFormatW(void);  /* ../dlls/kernel32/lcformat.c:992 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTimeFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTimeFormatW") "\n"
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

extern WINAPI DWORD wine32b_kernel32_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION  ret) /* ../dlls/kernel32/time.c:638 */
{
	TRACE("Enter GetTimeZoneInformation\n");
	return pGetTimeZoneInformation(ret);
}

extern WINAPI void wine32a_kernel32_GetTimeZoneInformation(void);  /* ../dlls/kernel32/time.c:638 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetTimeZoneInformationForYear(USHORT  wYear, PDYNAMIC_TIME_ZONE_INFORMATION  pdtzi, LPTIME_ZONE_INFORMATION  ptzi) /* ../dlls/kernel32/time.c:652 */
{
	TRACE("Enter GetTimeZoneInformationForYear\n");
	return pGetTimeZoneInformationForYear(wYear, pdtzi, ptzi);
}

extern WINAPI void wine32a_kernel32_GetTimeZoneInformationForYear(void);  /* ../dlls/kernel32/time.c:652 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetTimeZoneInformationForYear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetTimeZoneInformationForYear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetUmsCompletionListEvent(PUMS_COMPLETION_LIST  list, HANDLE*  event) /* ../dlls/kernel32/process.c:4216 */
{
	TRACE("Enter GetUmsCompletionListEvent\n");
	return pGetUmsCompletionListEvent(list, event);
}

extern WINAPI void wine32a_kernel32_GetUmsCompletionListEvent(void);  /* ../dlls/kernel32/process.c:4216 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUmsCompletionListEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUmsCompletionListEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_kernel32_GetUserDefaultLCID(void) /* ../dlls/kernel32/locale.c:1207 */
{
	TRACE("Enter GetUserDefaultLCID\n");
	return pGetUserDefaultLCID();
}

extern WINAPI void wine32a_kernel32_GetUserDefaultLCID(void);  /* ../dlls/kernel32/locale.c:1207 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserDefaultLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserDefaultLCID") "\n"
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

extern WINAPI LANGID wine32b_kernel32_GetUserDefaultLangID(void) /* ../dlls/kernel32/locale.c:1173 */
{
	TRACE("Enter GetUserDefaultLangID\n");
	return pGetUserDefaultLangID();
}

extern WINAPI void wine32a_kernel32_GetUserDefaultLangID(void);  /* ../dlls/kernel32/locale.c:1173 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserDefaultLangID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserDefaultLangID") "\n"
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

extern WINAPI INT wine32b_kernel32_GetUserDefaultLocaleName(LPWSTR  localename, int  buffersize) /* ../dlls/kernel32/locale.c:5263 */
{
	TRACE("Enter GetUserDefaultLocaleName\n");
	return pGetUserDefaultLocaleName(localename, buffersize);
}

extern WINAPI void wine32a_kernel32_GetUserDefaultLocaleName(void);  /* ../dlls/kernel32/locale.c:5263 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserDefaultLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserDefaultLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LANGID wine32b_kernel32_GetUserDefaultUILanguage(void) /* ../dlls/kernel32/locale.c:1385 */
{
	TRACE("Enter GetUserDefaultUILanguage\n");
	return pGetUserDefaultUILanguage();
}

extern WINAPI void wine32a_kernel32_GetUserDefaultUILanguage(void);  /* ../dlls/kernel32/locale.c:1385 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserDefaultUILanguage") "\n"
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

extern WINAPI GEOID wine32b_kernel32_GetUserGeoID(GEOCLASS  GeoClass) /* ../dlls/kernel32/locale.c:4611 */
{
	TRACE("Enter GetUserGeoID\n");
	return pGetUserGeoID(GeoClass);
}

extern WINAPI void wine32a_kernel32_GetUserGeoID(void);  /* ../dlls/kernel32/locale.c:4611 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetUserGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetUserGeoID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumeInformationA(LPCSTR  root, LPSTR  label, DWORD  label_len, DWORD*  serial, DWORD*  filename_len, DWORD*  flags, LPSTR  fsname, DWORD  fsname_len) /* ../dlls/kernel32/volume.c:841 */
{
	TRACE("Enter GetVolumeInformationA\n");
	return pGetVolumeInformationA(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
}

extern WINAPI void wine32a_kernel32_GetVolumeInformationA(void);  /* ../dlls/kernel32/volume.c:841 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumeInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumeInformationA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetVolumeInformationByHandleW(HANDLE  handle, WCHAR*  volnamebuf, DWORD  volnamesize, DWORD*  volserial, DWORD*  maxlength, DWORD*  flags, WCHAR*  fsnamebuf, DWORD  fsnamesize) /* ../dlls/kernel32/volume.c:2164 */
{
	TRACE("Enter GetVolumeInformationByHandleW\n");
	return pGetVolumeInformationByHandleW(handle, volnamebuf, volnamesize, volserial, maxlength, flags, fsnamebuf, fsnamesize);
}

extern WINAPI void wine32a_kernel32_GetVolumeInformationByHandleW(void);  /* ../dlls/kernel32/volume.c:2164 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumeInformationByHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumeInformationByHandleW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetVolumeInformationW(LPCWSTR  root, LPWSTR  label, DWORD  label_len, DWORD*  serial, DWORD*  filename_len, DWORD*  flags, LPWSTR  fsname, DWORD  fsname_len) /* ../dlls/kernel32/volume.c:686 */
{
	TRACE("Enter GetVolumeInformationW\n");
	return pGetVolumeInformationW(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
}

extern WINAPI void wine32a_kernel32_GetVolumeInformationW(void);  /* ../dlls/kernel32/volume.c:686 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumeInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumeInformationW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_GetVolumeNameForVolumeMountPointA(LPCSTR  path, LPSTR  volume, DWORD  size) /* ../dlls/kernel32/volume.c:981 */
{
	TRACE("Enter GetVolumeNameForVolumeMountPointA\n");
	return pGetVolumeNameForVolumeMountPointA(path, volume, size);
}

extern WINAPI void wine32a_kernel32_GetVolumeNameForVolumeMountPointA(void);  /* ../dlls/kernel32/volume.c:981 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumeNameForVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumeNameForVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumeNameForVolumeMountPointW(LPCWSTR  path, LPWSTR  volume, DWORD  size) /* ../dlls/kernel32/volume.c:1002 */
{
	TRACE("Enter GetVolumeNameForVolumeMountPointW\n");
	return pGetVolumeNameForVolumeMountPointW(path, volume, size);
}

extern WINAPI void wine32a_kernel32_GetVolumeNameForVolumeMountPointW(void);  /* ../dlls/kernel32/volume.c:1002 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumeNameForVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumeNameForVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumePathNameA(LPCSTR  filename, LPSTR  volumepathname, DWORD  buflen) /* ../dlls/kernel32/volume.c:1638 */
{
	TRACE("Enter GetVolumePathNameA\n");
	return pGetVolumePathNameA(filename, volumepathname, buflen);
}

extern WINAPI void wine32a_kernel32_GetVolumePathNameA(void);  /* ../dlls/kernel32/volume.c:1638 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumePathNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumePathNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumePathNameW(LPCWSTR  filename, LPWSTR  volumepathname, DWORD  buflen) /* ../dlls/kernel32/volume.c:1666 */
{
	TRACE("Enter GetVolumePathNameW\n");
	return pGetVolumePathNameW(filename, volumepathname, buflen);
}

extern WINAPI void wine32a_kernel32_GetVolumePathNameW(void);  /* ../dlls/kernel32/volume.c:1666 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumePathNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumePathNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumePathNamesForVolumeNameA(LPCSTR  volumename, LPSTR  volumepathname, DWORD  buflen, PDWORD  returnlen) /* ../dlls/kernel32/volume.c:1809 */
{
	TRACE("Enter GetVolumePathNamesForVolumeNameA\n");
	return pGetVolumePathNamesForVolumeNameA(volumename, volumepathname, buflen, returnlen);
}

extern WINAPI void wine32a_kernel32_GetVolumePathNamesForVolumeNameA(void);  /* ../dlls/kernel32/volume.c:1809 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumePathNamesForVolumeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumePathNamesForVolumeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GetVolumePathNamesForVolumeNameW(LPCWSTR  volumename, LPWSTR  volumepathname, DWORD  buflen, PDWORD  returnlen) /* ../dlls/kernel32/volume.c:1863 */
{
	TRACE("Enter GetVolumePathNamesForVolumeNameW\n");
	return pGetVolumePathNamesForVolumeNameW(volumename, volumepathname, buflen, returnlen);
}

extern WINAPI void wine32a_kernel32_GetVolumePathNamesForVolumeNameW(void);  /* ../dlls/kernel32/volume.c:1863 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GetVolumePathNamesForVolumeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GetVolumePathNamesForVolumeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_GlobalAddAtomA(LPCSTR  str) /* ../dlls/kernel32/atom.c:111 */
{
	TRACE("Enter GlobalAddAtomA\n");
	return pGlobalAddAtomA(str);
}

extern WINAPI void wine32a_kernel32_GlobalAddAtomA(void);  /* ../dlls/kernel32/atom.c:111 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalAddAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalAddAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_GlobalAddAtomW(LPCWSTR  str) /* ../dlls/kernel32/atom.c:182 */
{
	TRACE("Enter GlobalAddAtomW\n");
	return pGlobalAddAtomW(str);
}

extern WINAPI void wine32a_kernel32_GlobalAddAtomW(void);  /* ../dlls/kernel32/atom.c:182 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalAddAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalAddAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_GlobalCompact(DWORD  minfree) /* ../dlls/kernel32/heap.c:509 */
{
	TRACE("Enter GlobalCompact\n");
	return pGlobalCompact(minfree);
}

extern WINAPI void wine32a_kernel32_GlobalCompact(void);  /* ../dlls/kernel32/heap.c:509 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalCompact,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalCompact") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_GlobalDeleteAtom(ATOM  atom) /* ../dlls/kernel32/atom.c:230 */
{
	TRACE("Enter GlobalDeleteAtom\n");
	return pGlobalDeleteAtom(atom);
}

extern WINAPI void wine32a_kernel32_GlobalDeleteAtom(void);  /* ../dlls/kernel32/atom.c:230 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalDeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalDeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_GlobalFindAtomA(LPCSTR  str) /* ../dlls/kernel32/atom.c:283 */
{
	TRACE("Enter GlobalFindAtomA\n");
	return pGlobalFindAtomA(str);
}

extern WINAPI void wine32a_kernel32_GlobalFindAtomA(void);  /* ../dlls/kernel32/atom.c:283 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalFindAtomA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalFindAtomA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_kernel32_GlobalFindAtomW(LPCWSTR  str) /* ../dlls/kernel32/atom.c:346 */
{
	TRACE("Enter GlobalFindAtomW\n");
	return pGlobalFindAtomW(str);
}

extern WINAPI void wine32a_kernel32_GlobalFindAtomW(void);  /* ../dlls/kernel32/atom.c:346 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalFindAtomW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalFindAtomW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GlobalFix(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:447 */
{
	TRACE("Enter GlobalFix\n");
	return pGlobalFix(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalFix(void);  /* ../dlls/kernel32/heap.c:447 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalFix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalFix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GlobalFlags(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:475 */
{
	TRACE("Enter GlobalFlags\n");
	return pGlobalFlags(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalFlags(void);  /* ../dlls/kernel32/heap.c:475 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GlobalGetAtomNameA(ATOM  atom, LPSTR  buffer, INT  count) /* ../dlls/kernel32/atom.c:396 */
{
	TRACE("Enter GlobalGetAtomNameA\n");
	return pGlobalGetAtomNameA(atom, buffer, count);
}

extern WINAPI void wine32a_kernel32_GlobalGetAtomNameA(void);  /* ../dlls/kernel32/atom.c:396 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalGetAtomNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalGetAtomNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_GlobalGetAtomNameW(ATOM  atom, LPWSTR  buffer, INT  count) /* ../dlls/kernel32/atom.c:464 */
{
	TRACE("Enter GlobalGetAtomNameW\n");
	return pGlobalGetAtomNameW(atom, buffer, count);
}

extern WINAPI void wine32a_kernel32_GlobalGetAtomNameW(void);  /* ../dlls/kernel32/atom.c:464 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalGetAtomNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalGetAtomNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HGLOBAL wine32b_kernel32_GlobalHandle(LPCVOID  pmem) /* ../dlls/kernel32/heap.c:293 */
{
	TRACE("Enter GlobalHandle\n");
	return pGlobalHandle(pmem);
}

extern WINAPI void wine32a_kernel32_GlobalHandle(void);  /* ../dlls/kernel32/heap.c:293 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernel32_GlobalLock(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:255 */
{
	TRACE("Enter GlobalLock\n");
	return pGlobalLock(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalLock(void);  /* ../dlls/kernel32/heap.c:255 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GlobalMemoryStatus(LPMEMORYSTATUS  lpBuffer) /* ../dlls/kernel32/heap.c:822 */
{
	TRACE("Enter GlobalMemoryStatus\n");
	return pGlobalMemoryStatus(lpBuffer);
}

extern WINAPI void wine32a_kernel32_GlobalMemoryStatus(void);  /* ../dlls/kernel32/heap.c:822 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalMemoryStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalMemoryStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GlobalMemoryStatusEx(LPMEMORYSTATUSEX  lpmemex) /* ../dlls/kernel32/heap.c:601 */
{
	TRACE("Enter GlobalMemoryStatusEx\n");
	return pGlobalMemoryStatusEx(lpmemex);
}

extern WINAPI void wine32a_kernel32_GlobalMemoryStatusEx(void);  /* ../dlls/kernel32/heap.c:601 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalMemoryStatusEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalMemoryStatusEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HGLOBAL wine32b_kernel32_GlobalReAlloc(HGLOBAL  hmem, SIZE_T  size, UINT  flags) /* ../dlls/kernel32/heap.c:355 */
{
	TRACE("Enter GlobalReAlloc\n");
	return pGlobalReAlloc(hmem, size, flags);
}

extern WINAPI void wine32a_kernel32_GlobalReAlloc(void);  /* ../dlls/kernel32/heap.c:355 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalReAlloc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalReAlloc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_GlobalSize(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:377 */
{
	TRACE("Enter GlobalSize\n");
	return pGlobalSize(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalSize(void);  /* ../dlls/kernel32/heap.c:377 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GlobalUnWire(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:438 */
{
	TRACE("Enter GlobalUnWire\n");
	return pGlobalUnWire(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalUnWire(void);  /* ../dlls/kernel32/heap.c:438 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalUnWire,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalUnWire") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_GlobalUnfix(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:456 */
{
	TRACE("Enter GlobalUnfix\n");
	return pGlobalUnfix(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalUnfix(void);  /* ../dlls/kernel32/heap.c:456 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalUnfix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalUnfix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_GlobalUnlock(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:277 */
{
	TRACE("Enter GlobalUnlock\n");
	return pGlobalUnlock(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalUnlock(void);  /* ../dlls/kernel32/heap.c:277 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalUnlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalUnlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPVOID wine32b_kernel32_GlobalWire(HGLOBAL  hmem) /* ../dlls/kernel32/heap.c:429 */
{
	TRACE("Enter GlobalWire\n");
	return pGlobalWire(hmem);
}

extern WINAPI void wine32a_kernel32_GlobalWire(void);  /* ../dlls/kernel32/heap.c:429 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_GlobalWire,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_GlobalWire") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Heap32ListFirst(HANDLE  hSnapshot, LPHEAPLIST32  lphl) /* ../dlls/kernel32/toolhelp.c:600 */
{
	TRACE("Enter Heap32ListFirst\n");
	return pHeap32ListFirst(hSnapshot, lphl);
}

extern WINAPI void wine32a_kernel32_Heap32ListFirst(void);  /* ../dlls/kernel32/toolhelp.c:600 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Heap32ListFirst,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Heap32ListFirst") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_HeapCreate(DWORD  flags, SIZE_T  initialSize, SIZE_T  maxSize) /* ../dlls/kernel32/heap.c:130 */
{
	TRACE("Enter HeapCreate\n");
	return pHeapCreate(flags, initialSize, maxSize);
}

extern WINAPI void wine32a_kernel32_HeapCreate(void);  /* ../dlls/kernel32/heap.c:130 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_HeapCreate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_HeapCreate") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_HeapDestroy(HANDLE  heap) /* ../dlls/kernel32/heap.c:161 */
{
	TRACE("Enter HeapDestroy\n");
	return pHeapDestroy(heap);
}

extern WINAPI void wine32a_kernel32_HeapDestroy(void);  /* ../dlls/kernel32/heap.c:161 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_HeapDestroy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_HeapDestroy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_HeapFree(HANDLE  heap, DWORD  flags, LPVOID  ptr) /* ../dlls/kernel32/heap.c:187 */
{
	TRACE("Enter HeapFree\n");
	return pHeapFree(heap, flags, ptr);
}

extern WINAPI void wine32a_kernel32_HeapFree(void);  /* ../dlls/kernel32/heap.c:187 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_HeapFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_HeapFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_IdnToAscii(DWORD  dwFlags, LPCWSTR  lpUnicodeCharStr, INT  cchUnicodeChar, LPWSTR  lpASCIICharStr, INT  cchASCIIChar) /* ../dlls/kernel32/locale.c:5366 */
{
	TRACE("Enter IdnToAscii\n");
	return pIdnToAscii(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpASCIICharStr, cchASCIIChar);
}

extern WINAPI void wine32a_kernel32_IdnToAscii(void);  /* ../dlls/kernel32/locale.c:5366 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IdnToAscii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IdnToAscii") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_IdnToNameprepUnicode(DWORD  dwFlags, LPCWSTR  lpUnicodeCharStr, INT  cchUnicodeChar, LPWSTR  lpNameprepCharStr, INT  cchNameprepChar) /* ../dlls/kernel32/locale.c:5504 */
{
	TRACE("Enter IdnToNameprepUnicode\n");
	return pIdnToNameprepUnicode(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpNameprepCharStr, cchNameprepChar);
}

extern WINAPI void wine32a_kernel32_IdnToNameprepUnicode(void);  /* ../dlls/kernel32/locale.c:5504 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IdnToNameprepUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IdnToNameprepUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_IdnToUnicode(DWORD  dwFlags, LPCWSTR  lpASCIICharStr, INT  cchASCIIChar, LPWSTR  lpUnicodeCharStr, INT  cchUnicodeChar) /* ../dlls/kernel32/locale.c:5716 */
{
	TRACE("Enter IdnToUnicode\n");
	return pIdnToUnicode(dwFlags, lpASCIICharStr, cchASCIIChar, lpUnicodeCharStr, cchUnicodeChar);
}

extern WINAPI void wine32a_kernel32_IdnToUnicode(void);  /* ../dlls/kernel32/locale.c:5716 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IdnToUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IdnToUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_InitAtomTable(DWORD  entries) /* ../dlls/kernel32/atom.c:79 */
{
	TRACE("Enter InitAtomTable\n");
	return pInitAtomTable(entries);
}

extern WINAPI void wine32a_kernel32_InitAtomTable(void);  /* ../dlls/kernel32/atom.c:79 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_InitAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_InitAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_InvalidateNLSCache(void) /* ../dlls/kernel32/locale.c:4602 */
{
	TRACE("Enter InvalidateNLSCache\n");
	return pInvalidateNLSCache();
}

extern WINAPI void wine32a_kernel32_InvalidateNLSCache(void);  /* ../dlls/kernel32/locale.c:4602 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_InvalidateNLSCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_InvalidateNLSCache") "\n"
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

extern WINAPI BOOL wine32b_kernel32_IsBadCodePtr(FARPROC  ptr) /* ../dlls/kernel32/virtual.c:183 */
{
	TRACE("Enter IsBadCodePtr\n");
	return pIsBadCodePtr(ptr);
}

extern WINAPI void wine32a_kernel32_IsBadCodePtr(void);  /* ../dlls/kernel32/virtual.c:183 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadCodePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadCodePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadHugeReadPtr(LPCVOID  ptr, UINT_PTR  size) /* ../dlls/kernel32/virtual.c:146 */
{
	TRACE("Enter IsBadHugeReadPtr\n");
	return pIsBadHugeReadPtr(ptr, size);
}

extern WINAPI void wine32a_kernel32_IsBadHugeReadPtr(void);  /* ../dlls/kernel32/virtual.c:146 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadHugeReadPtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadHugeReadPtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadHugeWritePtr(LPVOID  ptr, UINT_PTR  size) /* ../dlls/kernel32/virtual.c:165 */
{
	TRACE("Enter IsBadHugeWritePtr\n");
	return pIsBadHugeWritePtr(ptr, size);
}

extern WINAPI void wine32a_kernel32_IsBadHugeWritePtr(void);  /* ../dlls/kernel32/virtual.c:165 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadHugeWritePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadHugeWritePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadReadPtr(LPCVOID  ptr, UINT_PTR  size) /* ../dlls/kernel32/virtual.c:63 */
{
	TRACE("Enter IsBadReadPtr\n");
	return pIsBadReadPtr(ptr, size);
}

extern WINAPI void wine32a_kernel32_IsBadReadPtr(void);  /* ../dlls/kernel32/virtual.c:63 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadReadPtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadReadPtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadStringPtrA(LPCSTR  str, UINT_PTR  max) /* ../dlls/kernel32/virtual.c:202 */
{
	TRACE("Enter IsBadStringPtrA\n");
	return pIsBadStringPtrA(str, max);
}

extern WINAPI void wine32a_kernel32_IsBadStringPtrA(void);  /* ../dlls/kernel32/virtual.c:202 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadStringPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadStringPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadStringPtrW(LPCWSTR  str, UINT_PTR  max) /* ../dlls/kernel32/virtual.c:226 */
{
	TRACE("Enter IsBadStringPtrW\n");
	return pIsBadStringPtrW(str, max);
}

extern WINAPI void wine32a_kernel32_IsBadStringPtrW(void);  /* ../dlls/kernel32/virtual.c:226 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadStringPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadStringPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsBadWritePtr(LPVOID  ptr, UINT_PTR  size) /* ../dlls/kernel32/virtual.c:105 */
{
	TRACE("Enter IsBadWritePtr\n");
	return pIsBadWritePtr(ptr, size);
}

extern WINAPI void wine32a_kernel32_IsBadWritePtr(void);  /* ../dlls/kernel32/virtual.c:105 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsBadWritePtr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsBadWritePtr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsDBCSLeadByte(BYTE  testchar) /* ../dlls/kernel32/locale.c:2112 */
{
	TRACE("Enter IsDBCSLeadByte\n");
	return pIsDBCSLeadByte(testchar);
}

extern WINAPI void wine32a_kernel32_IsDBCSLeadByte(void);  /* ../dlls/kernel32/locale.c:2112 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsDBCSLeadByte,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsDBCSLeadByte") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsDBCSLeadByteEx(UINT  codepage, BYTE  testchar) /* ../dlls/kernel32/locale.c:2092 */
{
	TRACE("Enter IsDBCSLeadByteEx\n");
	return pIsDBCSLeadByteEx(codepage, testchar);
}

extern WINAPI void wine32a_kernel32_IsDBCSLeadByteEx(void);  /* ../dlls/kernel32/locale.c:2092 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsDBCSLeadByteEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsDBCSLeadByteEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsNormalizedString(NORM_FORM  NormForm, LPCWSTR  lpString, INT  cwLength) /* ../dlls/kernel32/locale.c:5333 */
{
	TRACE("Enter IsNormalizedString\n");
	return pIsNormalizedString(NormForm, lpString, cwLength);
}

extern WINAPI void wine32a_kernel32_IsNormalizedString(void);  /* ../dlls/kernel32/locale.c:5333 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsNormalizedString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsNormalizedString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsProcessInJob(HANDLE  process, HANDLE  job, PBOOL  result) /* ../dlls/kernel32/sync.c:388 */
{
	TRACE("Enter IsProcessInJob\n");
	return pIsProcessInJob(process, job, result);
}

extern WINAPI void wine32a_kernel32_IsProcessInJob(void);  /* ../dlls/kernel32/sync.c:388 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsProcessInJob,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsProcessInJob") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsProcessorFeaturePresent(DWORD  feature) /* ../dlls/kernel32/cpu.c:157 */
{
	TRACE("Enter IsProcessorFeaturePresent\n");
	return pIsProcessorFeaturePresent(feature);
}

extern WINAPI void wine32a_kernel32_IsProcessorFeaturePresent(void);  /* ../dlls/kernel32/cpu.c:157 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsProcessorFeaturePresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsProcessorFeaturePresent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsSystemResumeAutomatic(void) /* ../dlls/kernel32/powermgnt.c:66 */
{
	TRACE("Enter IsSystemResumeAutomatic\n");
	return pIsSystemResumeAutomatic();
}

extern WINAPI void wine32a_kernel32_IsSystemResumeAutomatic(void);  /* ../dlls/kernel32/powermgnt.c:66 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsSystemResumeAutomatic,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsSystemResumeAutomatic") "\n"
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

extern WINAPI BOOL wine32b_kernel32_IsValidCodePage(UINT  codepage) /* ../dlls/kernel32/locale.c:2067 */
{
	TRACE("Enter IsValidCodePage\n");
	return pIsValidCodePage(codepage);
}

extern WINAPI void wine32a_kernel32_IsValidCodePage(void);  /* ../dlls/kernel32/locale.c:2067 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsValidCodePage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsValidCodePage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsValidLanguageGroup(LGRPID  lgrpid, DWORD  dwFlags) /* ../dlls/kernel32/locale.c:4402 */
{
	TRACE("Enter IsValidLanguageGroup\n");
	return pIsValidLanguageGroup(lgrpid, dwFlags);
}

extern WINAPI void wine32a_kernel32_IsValidLanguageGroup(void);  /* ../dlls/kernel32/locale.c:4402 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsValidLanguageGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsValidLanguageGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsValidLocale(LCID  lcid, DWORD  flags) /* ../dlls/kernel32/locale.c:2917 */
{
	TRACE("Enter IsValidLocale\n");
	return pIsValidLocale(lcid, flags);
}

extern WINAPI void wine32a_kernel32_IsValidLocale(void);  /* ../dlls/kernel32/locale.c:2917 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsValidLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsValidLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_IsValidLocaleName(LPCWSTR  locale) /* ../dlls/kernel32/locale.c:2927 */
{
	TRACE("Enter IsValidLocaleName\n");
	return pIsValidLocaleName(locale);
}

extern WINAPI void wine32a_kernel32_IsValidLocaleName(void);  /* ../dlls/kernel32/locale.c:2927 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_IsValidLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_IsValidLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EmptyWorkingSet(HANDLE  hProcess) /* ../dlls/kernel32/process.c:3503 */
{
	TRACE("Enter K32EmptyWorkingSet\n");
	return pK32EmptyWorkingSet(hProcess);
}

extern WINAPI void wine32a_kernel32_K32EmptyWorkingSet(void);  /* ../dlls/kernel32/process.c:3503 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EmptyWorkingSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EmptyWorkingSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumDeviceDrivers(void**  image_base, DWORD  cb, DWORD*  needed) /* ../dlls/kernel32/file.c:1276 */
{
	TRACE("Enter K32EnumDeviceDrivers\n");
	return pK32EnumDeviceDrivers(image_base, cb, needed);
}

extern WINAPI void wine32a_kernel32_K32EnumDeviceDrivers(void);  /* ../dlls/kernel32/file.c:1276 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumDeviceDrivers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumDeviceDrivers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA  callback, LPVOID  context) /* ../dlls/kernel32/virtual.c:273 */
{
	TRACE("Enter K32EnumPageFilesA\n");
	return pK32EnumPageFilesA(callback, context);
}

extern WINAPI void wine32a_kernel32_K32EnumPageFilesA(void);  /* ../dlls/kernel32/virtual.c:273 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumPageFilesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumPageFilesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW  callback, LPVOID  context) /* ../dlls/kernel32/virtual.c:282 */
{
	TRACE("Enter K32EnumPageFilesW\n");
	return pK32EnumPageFilesW(callback, context);
}

extern WINAPI void wine32a_kernel32_K32EnumPageFilesW(void);  /* ../dlls/kernel32/virtual.c:282 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumPageFilesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumPageFilesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumProcessModules(HANDLE  process, HMODULE*  lphModule, DWORD  cb, DWORD*  needed) /* ../dlls/kernel32/module.c:1228 */
{
	TRACE("Enter K32EnumProcessModules\n");
	return pK32EnumProcessModules(process, lphModule, cb, needed);
}

extern WINAPI void wine32a_kernel32_K32EnumProcessModules(void);  /* ../dlls/kernel32/module.c:1228 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumProcessModules,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumProcessModules") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumProcessModulesEx(HANDLE  process, HMODULE*  lphModule, DWORD  cb, DWORD*  needed, DWORD  filter) /* ../dlls/kernel32/module.c:1273 */
{
	TRACE("Enter K32EnumProcessModulesEx\n");
	return pK32EnumProcessModulesEx(process, lphModule, cb, needed, filter);
}

extern WINAPI void wine32a_kernel32_K32EnumProcessModulesEx(void);  /* ../dlls/kernel32/module.c:1273 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumProcessModulesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumProcessModulesEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32EnumProcesses(DWORD*  lpdwProcessIDs, DWORD  cb, DWORD*  lpcbUsed) /* ../dlls/kernel32/process.c:3653 */
{
	TRACE("Enter K32EnumProcesses\n");
	return pK32EnumProcesses(lpdwProcessIDs, cb, lpcbUsed);
}

extern WINAPI void wine32a_kernel32_K32EnumProcesses(void);  /* ../dlls/kernel32/process.c:3653 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32EnumProcesses,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32EnumProcesses") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverBaseNameA(void*  image_base, LPSTR  base_name, DWORD  size) /* ../dlls/kernel32/file.c:1289 */
{
	TRACE("Enter K32GetDeviceDriverBaseNameA\n");
	return pK32GetDeviceDriverBaseNameA(image_base, base_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetDeviceDriverBaseNameA(void);  /* ../dlls/kernel32/file.c:1289 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetDeviceDriverBaseNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetDeviceDriverBaseNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverBaseNameW(void*  image_base, LPWSTR  base_name, DWORD  size) /* ../dlls/kernel32/file.c:1302 */
{
	TRACE("Enter K32GetDeviceDriverBaseNameW\n");
	return pK32GetDeviceDriverBaseNameW(image_base, base_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetDeviceDriverBaseNameW(void);  /* ../dlls/kernel32/file.c:1302 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetDeviceDriverBaseNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetDeviceDriverBaseNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverFileNameA(void*  image_base, LPSTR  file_name, DWORD  size) /* ../dlls/kernel32/file.c:1315 */
{
	TRACE("Enter K32GetDeviceDriverFileNameA\n");
	return pK32GetDeviceDriverFileNameA(image_base, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetDeviceDriverFileNameA(void);  /* ../dlls/kernel32/file.c:1315 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetDeviceDriverFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetDeviceDriverFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverFileNameW(void*  image_base, LPWSTR  file_name, DWORD  size) /* ../dlls/kernel32/file.c:1328 */
{
	TRACE("Enter K32GetDeviceDriverFileNameW\n");
	return pK32GetDeviceDriverFileNameW(image_base, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetDeviceDriverFileNameW(void);  /* ../dlls/kernel32/file.c:1328 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetDeviceDriverFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetDeviceDriverFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetMappedFileNameA(HANDLE  process, LPVOID  lpv, LPSTR  file_name, DWORD  size) /* ../dlls/kernel32/virtual.c:247 */
{
	TRACE("Enter K32GetMappedFileNameA\n");
	return pK32GetMappedFileNameA(process, lpv, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetMappedFileNameA(void);  /* ../dlls/kernel32/virtual.c:247 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetMappedFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetMappedFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetMappedFileNameW(HANDLE  process, LPVOID  lpv, LPWSTR  file_name, DWORD  size) /* ../dlls/kernel32/virtual.c:260 */
{
	TRACE("Enter K32GetMappedFileNameW\n");
	return pK32GetMappedFileNameW(process, lpv, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetMappedFileNameW(void);  /* ../dlls/kernel32/virtual.c:260 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetMappedFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetMappedFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetModuleBaseNameA(HANDLE  process, HMODULE  module, LPSTR  base_name, DWORD  size) /* ../dlls/kernel32/module.c:1323 */
{
	TRACE("Enter K32GetModuleBaseNameA\n");
	return pK32GetModuleBaseNameA(process, module, base_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetModuleBaseNameA(void);  /* ../dlls/kernel32/module.c:1323 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetModuleBaseNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetModuleBaseNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetModuleBaseNameW(HANDLE  process, HMODULE  module, LPWSTR  base_name, DWORD  size) /* ../dlls/kernel32/module.c:1284 */
{
	TRACE("Enter K32GetModuleBaseNameW\n");
	return pK32GetModuleBaseNameW(process, module, base_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetModuleBaseNameW(void);  /* ../dlls/kernel32/module.c:1284 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetModuleBaseNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetModuleBaseNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetModuleFileNameExA(HANDLE  process, HMODULE  module, LPSTR  file_name, DWORD  size) /* ../dlls/kernel32/module.c:1403 */
{
	TRACE("Enter K32GetModuleFileNameExA\n");
	return pK32GetModuleFileNameExA(process, module, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetModuleFileNameExA(void);  /* ../dlls/kernel32/module.c:1403 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetModuleFileNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetModuleFileNameExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetModuleFileNameExW(HANDLE  process, HMODULE  module, LPWSTR  file_name, DWORD  size) /* ../dlls/kernel32/module.c:1353 */
{
	TRACE("Enter K32GetModuleFileNameExW\n");
	return pK32GetModuleFileNameExW(process, module, file_name, size);
}

extern WINAPI void wine32a_kernel32_K32GetModuleFileNameExW(void);  /* ../dlls/kernel32/module.c:1353 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetModuleFileNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetModuleFileNameExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32GetModuleInformation(HANDLE  process, HMODULE  module, MODULEINFO*  modinfo, DWORD  cb) /* ../dlls/kernel32/module.c:1448 */
{
	TRACE("Enter K32GetModuleInformation\n");
	return pK32GetModuleInformation(process, module, modinfo, cb);
}

extern WINAPI void wine32a_kernel32_K32GetModuleInformation(void);  /* ../dlls/kernel32/module.c:1448 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetModuleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetModuleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32GetPerformanceInfo(PPERFORMANCE_INFORMATION  info, DWORD  size) /* ../dlls/kernel32/cpu.c:165 */
{
	TRACE("Enter K32GetPerformanceInfo\n");
	return pK32GetPerformanceInfo(info, size);
}

extern WINAPI void wine32a_kernel32_K32GetPerformanceInfo(void);  /* ../dlls/kernel32/cpu.c:165 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetPerformanceInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetPerformanceInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetProcessImageFileNameA(HANDLE  process, LPSTR  file, DWORD  size) /* ../dlls/kernel32/process.c:3637 */
{
	TRACE("Enter K32GetProcessImageFileNameA\n");
	return pK32GetProcessImageFileNameA(process, file, size);
}

extern WINAPI void wine32a_kernel32_K32GetProcessImageFileNameA(void);  /* ../dlls/kernel32/process.c:3637 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetProcessImageFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetProcessImageFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_K32GetProcessImageFileNameW(HANDLE  process, LPWSTR  file, DWORD  size) /* ../dlls/kernel32/process.c:3645 */
{
	TRACE("Enter K32GetProcessImageFileNameW\n");
	return pK32GetProcessImageFileNameW(process, file, size);
}

extern WINAPI void wine32a_kernel32_K32GetProcessImageFileNameW(void);  /* ../dlls/kernel32/process.c:3645 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetProcessImageFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetProcessImageFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32GetProcessMemoryInfo(HANDLE  process, PPROCESS_MEMORY_COUNTERS  pmc, DWORD  cb) /* ../dlls/kernel32/process.c:3738 */
{
	TRACE("Enter K32GetProcessMemoryInfo\n");
	return pK32GetProcessMemoryInfo(process, pmc, cb);
}

extern WINAPI void wine32a_kernel32_K32GetProcessMemoryInfo(void);  /* ../dlls/kernel32/process.c:3738 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetProcessMemoryInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetProcessMemoryInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32GetWsChanges(HANDLE  process, PPSAPI_WS_WATCH_INFORMATION  watchinfo, DWORD  size) /* ../dlls/kernel32/virtual.c:291 */
{
	TRACE("Enter K32GetWsChanges\n");
	return pK32GetWsChanges(process, watchinfo, size);
}

extern WINAPI void wine32a_kernel32_K32GetWsChanges(void);  /* ../dlls/kernel32/virtual.c:291 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetWsChanges,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetWsChanges") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32GetWsChangesEx(HANDLE  process, PSAPI_WS_WATCH_INFORMATION_EX*  watchinfoex, DWORD*  size) /* ../dlls/kernel32/virtual.c:310 */
{
	TRACE("Enter K32GetWsChangesEx\n");
	return pK32GetWsChangesEx(process, watchinfoex, size);
}

extern WINAPI void wine32a_kernel32_K32GetWsChangesEx(void);  /* ../dlls/kernel32/virtual.c:310 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32GetWsChangesEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32GetWsChangesEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32InitializeProcessForWsWatch(HANDLE  process) /* ../dlls/kernel32/virtual.c:321 */
{
	TRACE("Enter K32InitializeProcessForWsWatch\n");
	return pK32InitializeProcessForWsWatch(process);
}

extern WINAPI void wine32a_kernel32_K32InitializeProcessForWsWatch(void);  /* ../dlls/kernel32/virtual.c:321 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32InitializeProcessForWsWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32InitializeProcessForWsWatch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32QueryWorkingSet(HANDLE  process, LPVOID  buffer, DWORD  size) /* ../dlls/kernel32/process.c:3697 */
{
	TRACE("Enter K32QueryWorkingSet\n");
	return pK32QueryWorkingSet(process, buffer, size);
}

extern WINAPI void wine32a_kernel32_K32QueryWorkingSet(void);  /* ../dlls/kernel32/process.c:3697 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32QueryWorkingSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32QueryWorkingSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_K32QueryWorkingSetEx(HANDLE  process, LPVOID  buffer, DWORD  size) /* ../dlls/kernel32/process.c:3716 */
{
	TRACE("Enter K32QueryWorkingSetEx\n");
	return pK32QueryWorkingSetEx(process, buffer, size);
}

extern WINAPI void wine32a_kernel32_K32QueryWorkingSetEx(void);  /* ../dlls/kernel32/process.c:3716 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_K32QueryWorkingSetEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_K32QueryWorkingSetEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_LCIDToLocaleName(LCID  lcid, LPWSTR  name, INT  count, DWORD  flags) /* ../dlls/kernel32/locale.c:1450 */
{
	TRACE("Enter LCIDToLocaleName\n");
	return pLCIDToLocaleName(lcid, name, count, flags);
}

extern WINAPI void wine32a_kernel32_LCIDToLocaleName(void);  /* ../dlls/kernel32/locale.c:1450 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LCIDToLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LCIDToLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_LCMapStringA(LCID  lcid, DWORD  flags, LPCSTR  src, INT  srclen, LPSTR  dst, INT  dstlen) /* ../dlls/kernel32/locale.c:3724 */
{
	TRACE("Enter LCMapStringA\n");
	return pLCMapStringA(lcid, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_kernel32_LCMapStringA(void);  /* ../dlls/kernel32/locale.c:3724 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LCMapStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LCMapStringA") "\n"
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

extern WINAPI INT wine32b_kernel32_LCMapStringEx(LPCWSTR  name, DWORD  flags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen, LPNLSVERSIONINFO  version, LPVOID  reserved, LPARAM  lparam) /* ../dlls/kernel32/locale.c:3463 */
{
	TRACE("Enter LCMapStringEx\n");
	return pLCMapStringEx(name, flags, src, srclen, dst, dstlen, version, reserved, lparam);
}

extern WINAPI void wine32a_kernel32_LCMapStringEx(void);  /* ../dlls/kernel32/locale.c:3463 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LCMapStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LCMapStringEx") "\n"
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

extern WINAPI INT wine32b_kernel32_LCMapStringW(LCID  lcid, DWORD  flags, LPCWSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen) /* ../dlls/kernel32/locale.c:3698 */
{
	TRACE("Enter LCMapStringW\n");
	return pLCMapStringW(lcid, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_kernel32_LCMapStringW(void);  /* ../dlls/kernel32/locale.c:3698 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LCMapStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LCMapStringW") "\n"
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

extern WINAPI void wine32b_kernel32_LZClose(HFILE  fd) /* ../dlls/kernel32/lzexpand.c:579 */
{
	TRACE("Enter LZClose\n");
	return pLZClose(fd);
}

extern WINAPI void wine32a_kernel32_LZClose(void);  /* ../dlls/kernel32/lzexpand.c:579 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_LZCopy(HFILE  src, HFILE  dest) /* ../dlls/kernel32/lzexpand.c:455 */
{
	TRACE("Enter LZCopy\n");
	return pLZCopy(src, dest);
}

extern WINAPI void wine32a_kernel32_LZCopy(void);  /* ../dlls/kernel32/lzexpand.c:455 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZCopy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZCopy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_LZDone(void) /* ../dlls/kernel32/lzexpand.c:223 */
{
	TRACE("Enter LZDone\n");
	return pLZDone();
}

extern WINAPI void wine32a_kernel32_LZDone(void);  /* ../dlls/kernel32/lzexpand.c:223 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZDone,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZDone") "\n"
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

extern WINAPI HFILE wine32b_kernel32_LZInit(HFILE  hfSrc) /* ../dlls/kernel32/lzexpand.c:180 */
{
	TRACE("Enter LZInit\n");
	return pLZInit(hfSrc);
}

extern WINAPI void wine32a_kernel32_LZInit(void);  /* ../dlls/kernel32/lzexpand.c:180 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZInit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZInit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32_LZOpenFileA(LPSTR  fn, LPOFSTRUCT  ofs, WORD  mode) /* ../dlls/kernel32/lzexpand.c:535 */
{
	TRACE("Enter LZOpenFileA\n");
	return pLZOpenFileA(fn, ofs, mode);
}

extern WINAPI void wine32a_kernel32_LZOpenFileA(void);  /* ../dlls/kernel32/lzexpand.c:535 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZOpenFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZOpenFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32_LZOpenFileW(LPWSTR  fn, LPOFSTRUCT  ofs, WORD  mode) /* ../dlls/kernel32/lzexpand.c:564 */
{
	TRACE("Enter LZOpenFileW\n");
	return pLZOpenFileW(fn, ofs, mode);
}

extern WINAPI void wine32a_kernel32_LZOpenFileW(void);  /* ../dlls/kernel32/lzexpand.c:564 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZOpenFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZOpenFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_LZRead(HFILE  fd, LPSTR  vbuf, INT  toread) /* ../dlls/kernel32/lzexpand.c:328 */
{
	TRACE("Enter LZRead\n");
	return pLZRead(fd, vbuf, toread);
}

extern WINAPI void wine32a_kernel32_LZRead(void);  /* ../dlls/kernel32/lzexpand.c:328 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZRead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZRead") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32_LZSeek(HFILE  fd, LONG  off, INT  type) /* ../dlls/kernel32/lzexpand.c:419 */
{
	TRACE("Enter LZSeek\n");
	return pLZSeek(fd, off, type);
}

extern WINAPI void wine32a_kernel32_LZSeek(void);  /* ../dlls/kernel32/lzexpand.c:419 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZSeek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZSeek") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_LZStart(void) /* ../dlls/kernel32/lzexpand.c:162 */
{
	TRACE("Enter LZStart\n");
	return pLZStart();
}

extern WINAPI void wine32a_kernel32_LZStart(void);  /* ../dlls/kernel32/lzexpand.c:162 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LZStart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LZStart") "\n"
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

extern WINAPI HMODULE wine32b_kernel32_LoadLibraryA(LPCSTR  libname) /* ../dlls/kernel32/module.c:860 */
{
	TRACE("Enter LoadLibraryA\n");
	return pLoadLibraryA(libname);
}

extern WINAPI void wine32a_kernel32_LoadLibraryA(void);  /* ../dlls/kernel32/module.c:860 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LoadLibraryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LoadLibraryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_kernel32_LoadLibraryExA(LPCSTR  libname, HANDLE  hfile, DWORD  flags) /* ../dlls/kernel32/module.c:805 */
{
	TRACE("Enter LoadLibraryExA\n");
	return pLoadLibraryExA(libname, hfile, flags);
}

extern WINAPI void wine32a_kernel32_LoadLibraryExA(void);  /* ../dlls/kernel32/module.c:805 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LoadLibraryExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LoadLibraryExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_kernel32_LoadLibraryExW(LPCWSTR  libnameW, HANDLE  hfile, DWORD  flags) /* ../dlls/kernel32/module.c:818 */
{
	TRACE("Enter LoadLibraryExW\n");
	return pLoadLibraryExW(libnameW, hfile, flags);
}

extern WINAPI void wine32a_kernel32_LoadLibraryExW(void);  /* ../dlls/kernel32/module.c:818 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LoadLibraryExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LoadLibraryExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMODULE wine32b_kernel32_LoadLibraryW(LPCWSTR  libnameW) /* ../dlls/kernel32/module.c:870 */
{
	TRACE("Enter LoadLibraryW\n");
	return pLoadLibraryW(libnameW);
}

extern WINAPI void wine32a_kernel32_LoadLibraryW(void);  /* ../dlls/kernel32/module.c:870 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LoadLibraryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LoadLibraryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_LoadModule(LPCSTR  name, LPVOID  paramBlock) /* ../dlls/kernel32/process.c:3079 */
{
	TRACE("Enter LoadModule\n");
	return pLoadModule(name, paramBlock);
}

extern WINAPI void wine32a_kernel32_LoadModule(void);  /* ../dlls/kernel32/process.c:3079 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LoadModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LoadModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_LocalCompact(UINT  minfree) /* ../dlls/kernel32/heap.c:518 */
{
	TRACE("Enter LocalCompact\n");
	return pLocalCompact(minfree);
}

extern WINAPI void wine32a_kernel32_LocalCompact(void);  /* ../dlls/kernel32/heap.c:518 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalCompact,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalCompact") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_LocalFileTimeToFileTime(FILETIME*  localft, LPFILETIME  utcft) /* ../dlls/kernel32/time.c:1176 */
{
	TRACE("Enter LocalFileTimeToFileTime\n");
	return pLocalFileTimeToFileTime(localft, utcft);
}

extern WINAPI void wine32a_kernel32_LocalFileTimeToFileTime(void);  /* ../dlls/kernel32/time.c:1176 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalFileTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalFileTimeToFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_LocalFlags(HLOCAL  handle) /* ../dlls/kernel32/heap.c:537 */
{
	TRACE("Enter LocalFlags\n");
	return pLocalFlags(handle);
}

extern WINAPI void wine32a_kernel32_LocalFlags(void);  /* ../dlls/kernel32/heap.c:537 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HLOCAL wine32b_kernel32_LocalHandle(LPCVOID  ptr) /* ../dlls/kernel32/heap.c:557 */
{
	TRACE("Enter LocalHandle\n");
	return pLocalHandle(ptr);
}

extern WINAPI void wine32a_kernel32_LocalHandle(void);  /* ../dlls/kernel32/heap.c:557 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_LocalShrink(HGLOBAL  handle, UINT  newsize) /* ../dlls/kernel32/heap.c:567 */
{
	TRACE("Enter LocalShrink\n");
	return pLocalShrink(handle, newsize);
}

extern WINAPI void wine32a_kernel32_LocalShrink(void);  /* ../dlls/kernel32/heap.c:567 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalShrink,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalShrink") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SIZE_T wine32b_kernel32_LocalSize(HLOCAL  handle) /* ../dlls/kernel32/heap.c:586 */
{
	TRACE("Enter LocalSize\n");
	return pLocalSize(handle);
}

extern WINAPI void wine32a_kernel32_LocalSize(void);  /* ../dlls/kernel32/heap.c:586 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocalSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocalSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LCID wine32b_kernel32_LocaleNameToLCID(LPCWSTR  name, DWORD  flags) /* ../dlls/kernel32/locale.c:1416 */
{
	TRACE("Enter LocaleNameToLCID\n");
	return pLocaleNameToLCID(name, flags);
}

extern WINAPI void wine32a_kernel32_LocaleNameToLCID(void);  /* ../dlls/kernel32/locale.c:1416 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_LocaleNameToLCID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_LocaleNameToLCID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_MakeCriticalSectionGlobal(CRITICAL_SECTION*  crit) /* ../dlls/kernel32/sync.c:147 */
{
	TRACE("Enter MakeCriticalSectionGlobal\n");
	return pMakeCriticalSectionGlobal(crit);
}

extern WINAPI void wine32a_kernel32_MakeCriticalSectionGlobal(void);  /* ../dlls/kernel32/sync.c:147 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MakeCriticalSectionGlobal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MakeCriticalSectionGlobal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MapUserPhysicalPages(PVOID  addr, ULONG_PTR  page_count, PULONG_PTR  pages) /* ../dlls/kernel32/heap.c:944 */
{
	TRACE("Enter MapUserPhysicalPages\n");
	return pMapUserPhysicalPages(addr, page_count, pages);
}

extern WINAPI void wine32a_kernel32_MapUserPhysicalPages(void);  /* ../dlls/kernel32/heap.c:944 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MapUserPhysicalPages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MapUserPhysicalPages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Module32First(HANDLE  hSnapshot, LPMODULEENTRY32  lpme) /* ../dlls/kernel32/toolhelp.c:581 */
{
	TRACE("Enter Module32First\n");
	return pModule32First(hSnapshot, lpme);
}

extern WINAPI void wine32a_kernel32_Module32First(void);  /* ../dlls/kernel32/toolhelp.c:581 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Module32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Module32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Module32FirstW(HANDLE  hSnapshot, LPMODULEENTRY32W  lpme) /* ../dlls/kernel32/toolhelp.c:528 */
{
	TRACE("Enter Module32FirstW\n");
	return pModule32FirstW(hSnapshot, lpme);
}

extern WINAPI void wine32a_kernel32_Module32FirstW(void);  /* ../dlls/kernel32/toolhelp.c:528 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Module32FirstW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Module32FirstW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Module32Next(HANDLE  hSnapshot, LPMODULEENTRY32  lpme) /* ../dlls/kernel32/toolhelp.c:591 */
{
	TRACE("Enter Module32Next\n");
	return pModule32Next(hSnapshot, lpme);
}

extern WINAPI void wine32a_kernel32_Module32Next(void);  /* ../dlls/kernel32/toolhelp.c:591 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Module32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Module32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Module32NextW(HANDLE  hSnapshot, LPMODULEENTRY32W  lpme) /* ../dlls/kernel32/toolhelp.c:538 */
{
	TRACE("Enter Module32NextW\n");
	return pModule32NextW(hSnapshot, lpme);
}

extern WINAPI void wine32a_kernel32_Module32NextW(void);  /* ../dlls/kernel32/toolhelp.c:538 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Module32NextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Module32NextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileA(LPCSTR  source, LPCSTR  dest) /* ../dlls/kernel32/path.c:1516 */
{
	TRACE("Enter MoveFileA\n");
	return pMoveFileA(source, dest);
}

extern WINAPI void wine32a_kernel32_MoveFileA(void);  /* ../dlls/kernel32/path.c:1516 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileExA(LPCSTR  source, LPCSTR  dest, DWORD  flag) /* ../dlls/kernel32/path.c:1496 */
{
	TRACE("Enter MoveFileExA\n");
	return pMoveFileExA(source, dest, flag);
}

extern WINAPI void wine32a_kernel32_MoveFileExA(void);  /* ../dlls/kernel32/path.c:1496 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileExW(LPCWSTR  source, LPCWSTR  dest, DWORD  flag) /* ../dlls/kernel32/path.c:1488 */
{
	TRACE("Enter MoveFileExW\n");
	return pMoveFileExW(source, dest, flag);
}

extern WINAPI void wine32a_kernel32_MoveFileExW(void);  /* ../dlls/kernel32/path.c:1488 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileTransactedA(char*  source, char*  dest, LPPROGRESS_ROUTINE  progress, void*  data, DWORD  flags, HANDLE  handle) /* ../dlls/kernel32/path.c:1289 */
{
	TRACE("Enter MoveFileTransactedA\n");
	return pMoveFileTransactedA(source, dest, progress, data, flags, handle);
}

extern WINAPI void wine32a_kernel32_MoveFileTransactedA(void);  /* ../dlls/kernel32/path.c:1289 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileTransactedA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_MoveFileTransactedW(WCHAR*  source, WCHAR*  dest, LPPROGRESS_ROUTINE  progress, void*  data, DWORD  flags, HANDLE  handle) /* ../dlls/kernel32/path.c:1299 */
{
	TRACE("Enter MoveFileTransactedW\n");
	return pMoveFileTransactedW(source, dest, progress, data, flags, handle);
}

extern WINAPI void wine32a_kernel32_MoveFileTransactedW(void);  /* ../dlls/kernel32/path.c:1299 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileTransactedW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_MoveFileW(LPCWSTR  source, LPCWSTR  dest) /* ../dlls/kernel32/path.c:1507 */
{
	TRACE("Enter MoveFileW\n");
	return pMoveFileW(source, dest);
}

extern WINAPI void wine32a_kernel32_MoveFileW(void);  /* ../dlls/kernel32/path.c:1507 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileWithProgressA(LPCSTR  source, LPCSTR  dest, LPPROGRESS_ROUTINE  fnProgress, LPVOID  param, DWORD  flag) /* ../dlls/kernel32/path.c:1465 */
{
	TRACE("Enter MoveFileWithProgressA\n");
	return pMoveFileWithProgressA(source, dest, fnProgress, param, flag);
}

extern WINAPI void wine32a_kernel32_MoveFileWithProgressA(void);  /* ../dlls/kernel32/path.c:1465 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileWithProgressA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileWithProgressA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_MoveFileWithProgressW(LPCWSTR  source, LPCWSTR  dest, LPPROGRESS_ROUTINE  fnProgress, LPVOID  param, DWORD  flag) /* ../dlls/kernel32/path.c:1309 */
{
	TRACE("Enter MoveFileWithProgressW\n");
	return pMoveFileWithProgressW(source, dest, fnProgress, param, flag);
}

extern WINAPI void wine32a_kernel32_MoveFileWithProgressW(void);  /* ../dlls/kernel32/path.c:1309 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MoveFileWithProgressW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MoveFileWithProgressW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_MulDiv(INT  nMultiplicand, INT  nMultiplier, INT  nDivisor) /* ../dlls/kernel32/kernel_main.c:157 */
{
	TRACE("Enter MulDiv\n");
	return pMulDiv(nMultiplicand, nMultiplier, nDivisor);
}

extern WINAPI void wine32a_kernel32_MulDiv(void);  /* ../dlls/kernel32/kernel_main.c:157 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MulDiv,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MulDiv") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_MultiByteToWideChar(UINT  page, DWORD  flags, LPCSTR  src, INT  srclen, LPWSTR  dst, INT  dstlen) /* ../dlls/kernel32/locale.c:2454 */
{
	TRACE("Enter MultiByteToWideChar\n");
	return pMultiByteToWideChar(page, flags, src, srclen, dst, dstlen);
}

extern WINAPI void wine32a_kernel32_MultiByteToWideChar(void);  /* ../dlls/kernel32/locale.c:2454 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_MultiByteToWideChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_MultiByteToWideChar") "\n"
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

extern WINAPI BOOL wine32b_kernel32_NeedCurrentDirectoryForExePathA(LPCSTR  name) /* ../dlls/kernel32/path.c:1868 */
{
	TRACE("Enter NeedCurrentDirectoryForExePathA\n");
	return pNeedCurrentDirectoryForExePathA(name);
}

extern WINAPI void wine32a_kernel32_NeedCurrentDirectoryForExePathA(void);  /* ../dlls/kernel32/path.c:1868 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_NeedCurrentDirectoryForExePathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_NeedCurrentDirectoryForExePathA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_NeedCurrentDirectoryForExePathW(LPCWSTR  name) /* ../dlls/kernel32/path.c:1844 */
{
	TRACE("Enter NeedCurrentDirectoryForExePathW\n");
	return pNeedCurrentDirectoryForExePathW(name);
}

extern WINAPI void wine32a_kernel32_NeedCurrentDirectoryForExePathW(void);  /* ../dlls/kernel32/path.c:1844 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_NeedCurrentDirectoryForExePathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_NeedCurrentDirectoryForExePathW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_NormalizeString(NORM_FORM  form, WCHAR*  src, INT  src_len, WCHAR*  dst, INT  dst_len) /* ../dlls/kernel32/locale.c:5276 */
{
	TRACE("Enter NormalizeString\n");
	return pNormalizeString(form, src, src_len, dst, dst_len);
}

extern WINAPI void wine32a_kernel32_NormalizeString(void);  /* ../dlls/kernel32/locale.c:5276 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_NormalizeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_NormalizeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenConsoleW(LPCWSTR  name, DWORD  access, BOOL  inherit, DWORD  creation) /* ../dlls/kernel32/console.c:213 */
{
	TRACE("Enter OpenConsoleW\n");
	return pOpenConsoleW(name, access, inherit, creation);
}

extern WINAPI void wine32a_kernel32_OpenConsoleW(void);  /* ../dlls/kernel32/console.c:213 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenConsoleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32_OpenFile(LPCSTR  name, OFSTRUCT*  ofs, UINT  mode) /* ../dlls/kernel32/file.c:1164 */
{
	TRACE("Enter OpenFile\n");
	return pOpenFile(name, ofs, mode);
}

extern WINAPI void wine32a_kernel32_OpenFile(void);  /* ../dlls/kernel32/file.c:1164 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenFileMappingA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernel32/sync.c:502 */
{
	TRACE("Enter OpenFileMappingA\n");
	return pOpenFileMappingA(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenFileMappingA(void);  /* ../dlls/kernel32/sync.c:502 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenFileMappingA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenFileMappingA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenJobObjectA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernel32/sync.c:330 */
{
	TRACE("Enter OpenJobObjectA\n");
	return pOpenJobObjectA(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenJobObjectA(void);  /* ../dlls/kernel32/sync.c:330 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenJobObjectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenJobObjectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenJobObjectW(DWORD  access, BOOL  inherit, LPCWSTR  name) /* ../dlls/kernel32/sync.c:309 */
{
	TRACE("Enter OpenJobObjectW\n");
	return pOpenJobObjectW(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenJobObjectW(void);  /* ../dlls/kernel32/sync.c:309 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenJobObjectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenJobObjectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenMutexA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernel32/sync.c:197 */
{
	TRACE("Enter OpenMutexA\n");
	return pOpenMutexA(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenMutexA(void);  /* ../dlls/kernel32/sync.c:197 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenMutexA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenMutexA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_OpenProfileUserMapping(void) /* ../dlls/kernel32/profile.c:1777 */
{
	TRACE("Enter OpenProfileUserMapping\n");
	return pOpenProfileUserMapping();
}

extern WINAPI void wine32a_kernel32_OpenProfileUserMapping(void);  /* ../dlls/kernel32/profile.c:1777 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenProfileUserMapping,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenProfileUserMapping") "\n"
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

extern WINAPI HANDLE wine32b_kernel32_OpenSemaphoreA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernel32/sync.c:250 */
{
	TRACE("Enter OpenSemaphoreA\n");
	return pOpenSemaphoreA(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenSemaphoreA(void);  /* ../dlls/kernel32/sync.c:250 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenSemaphoreA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenSemaphoreA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenVxDHandle(HANDLE  hHandleRing3) /* ../dlls/kernel32/file.c:1086 */
{
	TRACE("Enter OpenVxDHandle\n");
	return pOpenVxDHandle(hHandleRing3);
}

extern WINAPI void wine32a_kernel32_OpenVxDHandle(void);  /* ../dlls/kernel32/file.c:1086 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenVxDHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenVxDHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_OpenWaitableTimerA(DWORD  access, BOOL  inherit, LPCSTR  name) /* ../dlls/kernel32/sync.c:442 */
{
	TRACE("Enter OpenWaitableTimerA\n");
	return pOpenWaitableTimerA(access, inherit, name);
}

extern WINAPI void wine32a_kernel32_OpenWaitableTimerA(void);  /* ../dlls/kernel32/sync.c:442 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_OpenWaitableTimerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_OpenWaitableTimerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_PowerClearRequest(HANDLE  request, POWER_REQUEST_TYPE  type) /* ../dlls/kernel32/powermgnt.c:167 */
{
	TRACE("Enter PowerClearRequest\n");
	return pPowerClearRequest(request, type);
}

extern WINAPI void wine32a_kernel32_PowerClearRequest(void);  /* ../dlls/kernel32/powermgnt.c:167 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_PowerClearRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_PowerClearRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_kernel32_PowerCreateRequest(REASON_CONTEXT*  context) /* ../dlls/kernel32/powermgnt.c:119 */
{
	TRACE("Enter PowerCreateRequest\n");
	return pPowerCreateRequest(context);
}

extern WINAPI void wine32a_kernel32_PowerCreateRequest(void);  /* ../dlls/kernel32/powermgnt.c:119 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_PowerCreateRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_PowerCreateRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_PowerSetRequest(HANDLE  request, POWER_REQUEST_TYPE  type) /* ../dlls/kernel32/powermgnt.c:156 */
{
	TRACE("Enter PowerSetRequest\n");
	return pPowerSetRequest(request, type);
}

extern WINAPI void wine32a_kernel32_PowerSetRequest(void);  /* ../dlls/kernel32/powermgnt.c:156 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_PowerSetRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_PowerSetRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_PrepareTape(HANDLE  device, DWORD  operation, BOOL  immediate) /* ../dlls/kernel32/tape.c:227 */
{
	TRACE("Enter PrepareTape\n");
	return pPrepareTape(device, operation, immediate);
}

extern WINAPI void wine32a_kernel32_PrepareTape(void);  /* ../dlls/kernel32/tape.c:227 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_PrepareTape,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_PrepareTape") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Process32First(HANDLE  hSnapshot, LPPROCESSENTRY32  lppe) /* ../dlls/kernel32/toolhelp.c:456 */
{
	TRACE("Enter Process32First\n");
	return pProcess32First(hSnapshot, lppe);
}

extern WINAPI void wine32a_kernel32_Process32First(void);  /* ../dlls/kernel32/toolhelp.c:456 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Process32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Process32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Process32FirstW(HANDLE  hSnapshot, LPPROCESSENTRY32W  lppe) /* ../dlls/kernel32/toolhelp.c:476 */
{
	TRACE("Enter Process32FirstW\n");
	return pProcess32FirstW(hSnapshot, lppe);
}

extern WINAPI void wine32a_kernel32_Process32FirstW(void);  /* ../dlls/kernel32/toolhelp.c:476 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Process32FirstW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Process32FirstW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Process32Next(HANDLE  hSnapshot, LPPROCESSENTRY32  lppe) /* ../dlls/kernel32/toolhelp.c:466 */
{
	TRACE("Enter Process32Next\n");
	return pProcess32Next(hSnapshot, lppe);
}

extern WINAPI void wine32a_kernel32_Process32Next(void);  /* ../dlls/kernel32/toolhelp.c:466 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Process32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Process32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Process32NextW(HANDLE  hSnapshot, LPPROCESSENTRY32W  lppe) /* ../dlls/kernel32/toolhelp.c:486 */
{
	TRACE("Enter Process32NextW\n");
	return pProcess32NextW(hSnapshot, lppe);
}

extern WINAPI void wine32a_kernel32_Process32NextW(void);  /* ../dlls/kernel32/toolhelp.c:486 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Process32NextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Process32NextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_ProcessIdToSessionId(DWORD  procid, DWORD*  sessionid_ptr) /* ../dlls/kernel32/process.c:3777 */
{
	TRACE("Enter ProcessIdToSessionId\n");
	return pProcessIdToSessionId(procid, sessionid_ptr);
}

extern WINAPI void wine32a_kernel32_ProcessIdToSessionId(void);  /* ../dlls/kernel32/process.c:3777 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ProcessIdToSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ProcessIdToSessionId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_QueryDosDeviceA(LPCSTR  devname, LPSTR  target, DWORD  bufsize) /* ../dlls/kernel32/volume.c:1319 */
{
	TRACE("Enter QueryDosDeviceA\n");
	return pQueryDosDeviceA(devname, target, bufsize);
}

extern WINAPI void wine32a_kernel32_QueryDosDeviceA(void);  /* ../dlls/kernel32/volume.c:1319 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryDosDeviceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryDosDeviceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_QueryDosDeviceW(LPCWSTR  devname, LPWSTR  target, DWORD  bufsize) /* ../dlls/kernel32/volume.c:1228 */
{
	TRACE("Enter QueryDosDeviceW\n");
	return pQueryDosDeviceW(devname, target, bufsize);
}

extern WINAPI void wine32a_kernel32_QueryDosDeviceW(void);  /* ../dlls/kernel32/volume.c:1228 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryDosDeviceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryDosDeviceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryFullProcessImageNameA(HANDLE  hProcess, DWORD  dwFlags, LPSTR  lpExeName, PDWORD  pdwSize) /* ../dlls/kernel32/process.c:3534 */
{
	TRACE("Enter QueryFullProcessImageNameA\n");
	return pQueryFullProcessImageNameA(hProcess, dwFlags, lpExeName, pdwSize);
}

extern WINAPI void wine32a_kernel32_QueryFullProcessImageNameA(void);  /* ../dlls/kernel32/process.c:3534 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryFullProcessImageNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryFullProcessImageNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryFullProcessImageNameW(HANDLE  hProcess, DWORD  dwFlags, LPWSTR  lpExeName, PDWORD  pdwSize) /* ../dlls/kernel32/process.c:3555 */
{
	TRACE("Enter QueryFullProcessImageNameW\n");
	return pQueryFullProcessImageNameW(hProcess, dwFlags, lpExeName, pdwSize);
}

extern WINAPI void wine32a_kernel32_QueryFullProcessImageNameW(void);  /* ../dlls/kernel32/process.c:3555 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryFullProcessImageNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryFullProcessImageNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryInformationJobObject(HANDLE  job, JOBOBJECTINFOCLASS  class, LPVOID  info, DWORD  len, DWORD*  ret_len) /* ../dlls/kernel32/sync.c:357 */
{
	TRACE("Enter QueryInformationJobObject\n");
	return pQueryInformationJobObject(job, class, info, len, ret_len);
}

extern WINAPI void wine32a_kernel32_QueryInformationJobObject(void);  /* ../dlls/kernel32/sync.c:357 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryInformationJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryProcessCycleTime(HANDLE  process, PULONG64  cycle) /* ../dlls/kernel32/time.c:1530 */
{
	TRACE("Enter QueryProcessCycleTime\n");
	return pQueryProcessCycleTime(process, cycle);
}

extern WINAPI void wine32a_kernel32_QueryProcessCycleTime(void);  /* ../dlls/kernel32/time.c:1530 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryProcessCycleTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryProcessCycleTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryThreadCycleTime(HANDLE  thread, PULONG64  cycle) /* ../dlls/kernel32/time.c:1542 */
{
	TRACE("Enter QueryThreadCycleTime\n");
	return pQueryThreadCycleTime(thread, cycle);
}

extern WINAPI void wine32a_kernel32_QueryThreadCycleTime(void);  /* ../dlls/kernel32/time.c:1542 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryThreadCycleTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryThreadCycleTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryUmsThreadInformation(PUMS_CONTEXT  ctx, UMS_THREAD_INFO_CLASS  class, void*  buf, ULONG  length, ULONG*  ret_length) /* ../dlls/kernel32/process.c:4226 */
{
	TRACE("Enter QueryUmsThreadInformation\n");
	return pQueryUmsThreadInformation(ctx, class, buf, length, ret_length);
}

extern WINAPI void wine32a_kernel32_QueryUmsThreadInformation(void);  /* ../dlls/kernel32/process.c:4226 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryUmsThreadInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryUmsThreadInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_QueryUnbiasedInterruptTime(ULONGLONG*  time) /* ../dlls/kernel32/time.c:1554 */
{
	TRACE("Enter QueryUnbiasedInterruptTime\n");
	return pQueryUnbiasedInterruptTime(time);
}

extern WINAPI void wine32a_kernel32_QueryUnbiasedInterruptTime(void);  /* ../dlls/kernel32/time.c:1554 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_QueryUnbiasedInterruptTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_QueryUnbiasedInterruptTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_ReadConsoleInputW(HANDLE  hConsoleInput, PINPUT_RECORD  lpBuffer, DWORD  nLength, LPDWORD  lpNumberOfEventsRead) /* ../dlls/kernel32/console.c:807 */
{
	TRACE("Enter ReadConsoleInputW\n");
	return pReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead);
}

extern WINAPI void wine32a_kernel32_ReadConsoleInputW(void);  /* ../dlls/kernel32/console.c:807 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ReadConsoleInputW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ReadConsoleInputW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_ReadConsoleW(HANDLE  hConsoleInput, LPVOID  lpBuffer, DWORD  nNumberOfCharsToRead, LPDWORD  lpNumberOfCharsRead, LPVOID  lpReserved) /* ../dlls/kernel32/console.c:732 */
{
	TRACE("Enter ReadConsoleW\n");
	return pReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved);
}

extern WINAPI void wine32a_kernel32_ReadConsoleW(void);  /* ../dlls/kernel32/console.c:732 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ReadConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ReadConsoleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK  callback, PVOID  param, DWORD  pingint, DWORD  flags) /* ../dlls/kernel32/process.c:3956 */
{
	TRACE("Enter RegisterApplicationRecoveryCallback\n");
	return pRegisterApplicationRecoveryCallback(callback, param, pingint, flags);
}

extern WINAPI void wine32a_kernel32_RegisterApplicationRecoveryCallback(void);  /* ../dlls/kernel32/process.c:3956 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RegisterApplicationRecoveryCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RegisterApplicationRecoveryCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_RegisterApplicationRestart(PCWSTR  pwzCommandLine, DWORD  dwFlags) /* ../dlls/kernel32/process.c:3897 */
{
	TRACE("Enter RegisterApplicationRestart\n");
	return pRegisterApplicationRestart(pwzCommandLine, dwFlags);
}

extern WINAPI void wine32a_kernel32_RegisterApplicationRestart(void);  /* ../dlls/kernel32/process.c:3897 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RegisterApplicationRestart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RegisterApplicationRestart") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_RegisterServiceProcess(DWORD  dwProcessId, DWORD  dwType) /* ../dlls/kernel32/process.c:3793 */
{
	TRACE("Enter RegisterServiceProcess\n");
	return pRegisterServiceProcess(dwProcessId, dwType);
}

extern WINAPI void wine32a_kernel32_RegisterServiceProcess(void);  /* ../dlls/kernel32/process.c:3793 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RegisterServiceProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RegisterServiceProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_RegisterWaitForSingleObject(PHANDLE  phNewWaitObject, HANDLE  hObject, WAITORTIMERCALLBACK  Callback, PVOID  Context, ULONG  dwMilliseconds, ULONG  dwFlags) /* ../dlls/kernel32/sync.c:107 */
{
	TRACE("Enter RegisterWaitForSingleObject\n");
	return pRegisterWaitForSingleObject(phNewWaitObject, hObject, Callback, Context, dwMilliseconds, dwFlags);
}

extern WINAPI void wine32a_kernel32_RegisterWaitForSingleObject(void);  /* ../dlls/kernel32/sync.c:107 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RegisterWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RegisterWaitForSingleObject") "\n"
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

extern WINAPI void wine32b_kernel32_ReinitializeCriticalSection(CRITICAL_SECTION*  crit) /* ../dlls/kernel32/sync.c:170 */
{
	TRACE("Enter ReinitializeCriticalSection\n");
	return pReinitializeCriticalSection(crit);
}

extern WINAPI void wine32a_kernel32_ReinitializeCriticalSection(void);  /* ../dlls/kernel32/sync.c:170 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ReinitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ReinitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_RemoveDirectoryA(LPCSTR  path) /* ../dlls/kernel32/path.c:1680 */
{
	TRACE("Enter RemoveDirectoryA\n");
	return pRemoveDirectoryA(path);
}

extern WINAPI void wine32a_kernel32_RemoveDirectoryA(void);  /* ../dlls/kernel32/path.c:1680 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RemoveDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RemoveDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_RemoveDirectoryW(LPCWSTR  path) /* ../dlls/kernel32/path.c:1627 */
{
	TRACE("Enter RemoveDirectoryW\n");
	return pRemoveDirectoryW(path);
}

extern WINAPI void wine32a_kernel32_RemoveDirectoryW(void);  /* ../dlls/kernel32/path.c:1627 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RemoveDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RemoveDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_ReplaceFileA(LPCSTR  lpReplacedFileName, LPCSTR  lpReplacementFileName, LPCSTR  lpBackupFileName, DWORD  dwReplaceFlags, LPVOID  lpExclude, LPVOID  lpReserved) /* ../dlls/kernel32/file.c:612 */
{
	TRACE("Enter ReplaceFileA\n");
	return pReplaceFileA(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
}

extern WINAPI void wine32a_kernel32_ReplaceFileA(void);  /* ../dlls/kernel32/file.c:612 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ReplaceFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ReplaceFileA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_ReplaceFileW(LPCWSTR  lpReplacedFileName, LPCWSTR  lpReplacementFileName, LPCWSTR  lpBackupFileName, DWORD  dwReplaceFlags, LPVOID  lpExclude, LPVOID  lpReserved) /* ../dlls/kernel32/file.c:425 */
{
	TRACE("Enter ReplaceFileW\n");
	return pReplaceFileW(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
}

extern WINAPI void wine32a_kernel32_ReplaceFileW(void);  /* ../dlls/kernel32/file.c:425 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ReplaceFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ReplaceFileW") "\n"
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

extern WINAPI BOOL wine32b_kernel32_RemoveDllDirectory(DLL_DIRECTORY_COOKIE  cookie) /* ../dlls/kernel32/module.c:201 */
{
	TRACE("Enter RemoveDllDirectory\n");
	return pRemoveDllDirectory(cookie);
}

extern WINAPI void wine32a_kernel32_RemoveDllDirectory(void);  /* ../dlls/kernel32/module.c:201 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RemoveDllDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RemoveDllDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_RequestDeviceWakeup(HANDLE  device) /* ../dlls/kernel32/powermgnt.c:84 */
{
	TRACE("Enter RequestDeviceWakeup\n");
	return pRequestDeviceWakeup(device);
}

extern WINAPI void wine32a_kernel32_RequestDeviceWakeup(void);  /* ../dlls/kernel32/powermgnt.c:84 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RequestDeviceWakeup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RequestDeviceWakeup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_RequestWakeupLatency(LATENCY_TIME  latency) /* ../dlls/kernel32/powermgnt.c:75 */
{
	TRACE("Enter RequestWakeupLatency\n");
	return pRequestWakeupLatency(latency);
}

extern WINAPI void wine32a_kernel32_RequestWakeupLatency(void);  /* ../dlls/kernel32/powermgnt.c:75 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_RequestWakeupLatency,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_RequestWakeupLatency") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_ResolveLocaleName(LPCWSTR  name, LPWSTR  localename, INT  len) /* ../dlls/kernel32/locale.c:5898 */
{
	TRACE("Enter ResolveLocaleName\n");
	return pResolveLocaleName(name, localename, len);
}

extern WINAPI void wine32a_kernel32_ResolveLocaleName(void);  /* ../dlls/kernel32/locale.c:5898 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_ResolveLocaleName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_ResolveLocaleName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_SearchPathA(LPCSTR  path, LPCSTR  name, LPCSTR  ext, DWORD  buflen, LPSTR  buffer, LPSTR*  lastpart) /* ../dlls/kernel32/path.c:1081 */
{
	TRACE("Enter SearchPathA\n");
	return pSearchPathA(path, name, ext, buflen, buffer, lastpart);
}

extern WINAPI void wine32a_kernel32_SearchPathA(void);  /* ../dlls/kernel32/path.c:1081 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SearchPathA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SearchPathA") "\n"
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

extern WINAPI DWORD wine32b_kernel32_SearchPathW(LPCWSTR  path, LPCWSTR  name, LPCWSTR  ext, DWORD  buflen, LPWSTR  buffer, LPWSTR*  lastpart) /* ../dlls/kernel32/path.c:950 */
{
	TRACE("Enter SearchPathW\n");
	return pSearchPathW(path, name, ext, buflen, buffer, lastpart);
}

extern WINAPI void wine32a_kernel32_SearchPathW(void);  /* ../dlls/kernel32/path.c:950 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SearchPathW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SearchPathW") "\n"
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

extern WINAPI UINT wine32b_kernel32_SetCPGlobal(UINT  acp) /* ../dlls/kernel32/locale.c:2027 */
{
	TRACE("Enter SetCPGlobal\n");
	return pSetCPGlobal(acp);
}

extern WINAPI void wine32a_kernel32_SetCPGlobal(void);  /* ../dlls/kernel32/locale.c:2027 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCPGlobal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCPGlobal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_SetCalendarInfoA(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPCSTR  lpCalData) /* ../dlls/kernel32/time.c:1154 */
{
	TRACE("Enter SetCalendarInfoA\n");
	return pSetCalendarInfoA(Locale, Calendar, CalType, lpCalData);
}

extern WINAPI void wine32a_kernel32_SetCalendarInfoA(void);  /* ../dlls/kernel32/time.c:1154 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCalendarInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCalendarInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_SetCalendarInfoW(LCID  Locale, CALID  Calendar, CALTYPE  CalType, LPCWSTR  lpCalData) /* ../dlls/kernel32/time.c:1166 */
{
	TRACE("Enter SetCalendarInfoW\n");
	return pSetCalendarInfoW(Locale, Calendar, CalType, lpCalData);
}

extern WINAPI void wine32a_kernel32_SetCalendarInfoW(void);  /* ../dlls/kernel32/time.c:1166 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCalendarInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCalendarInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetComputerNameA(LPCSTR  lpComputerName) /* ../dlls/kernel32/computername.c:628 */
{
	TRACE("Enter SetComputerNameA\n");
	return pSetComputerNameA(lpComputerName);
}

extern WINAPI void wine32a_kernel32_SetComputerNameA(void);  /* ../dlls/kernel32/computername.c:628 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetComputerNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetComputerNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetComputerNameExA(COMPUTER_NAME_FORMAT  type, LPCSTR  lpComputerName) /* ../dlls/kernel32/computername.c:662 */
{
	TRACE("Enter SetComputerNameExA\n");
	return pSetComputerNameExA(type, lpComputerName);
}

extern WINAPI void wine32a_kernel32_SetComputerNameExA(void);  /* ../dlls/kernel32/computername.c:662 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetComputerNameExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetComputerNameExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetComputerNameExW(COMPUTER_NAME_FORMAT  type, LPCWSTR  lpComputerName) /* ../dlls/kernel32/computername.c:644 */
{
	TRACE("Enter SetComputerNameExW\n");
	return pSetComputerNameExW(type, lpComputerName);
}

extern WINAPI void wine32a_kernel32_SetComputerNameExW(void);  /* ../dlls/kernel32/computername.c:644 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetComputerNameExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetComputerNameExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetComputerNameW(LPCWSTR  lpComputerName) /* ../dlls/kernel32/computername.c:560 */
{
	TRACE("Enter SetComputerNameW\n");
	return pSetComputerNameW(lpComputerName);
}

extern WINAPI void wine32a_kernel32_SetComputerNameW(void);  /* ../dlls/kernel32/computername.c:560 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetComputerNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetComputerNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleCtrlHandler(PHANDLER_ROUTINE  func, BOOL  add) /* ../dlls/kernel32/console.c:878 */
{
	TRACE("Enter SetConsoleCtrlHandler\n");
	return pSetConsoleCtrlHandler(func, add);
}

extern WINAPI void wine32a_kernel32_SetConsoleCtrlHandler(void);  /* ../dlls/kernel32/console.c:878 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleCtrlHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleCtrlHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleDisplayMode(HANDLE  hConsoleOutput, DWORD  dwFlags, COORD*  lpNewScreenBufferDimensions) /* ../dlls/kernel32/console.c:1294 */
{
	TRACE("Enter SetConsoleDisplayMode\n");
	return pSetConsoleDisplayMode(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
}

extern WINAPI void wine32a_kernel32_SetConsoleDisplayMode(void);  /* ../dlls/kernel32/console.c:1294 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleDisplayMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleDisplayMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleFont(HANDLE  hConsole, DWORD  index) /* ../dlls/kernel32/console.c:1627 */
{
	TRACE("Enter SetConsoleFont\n");
	return pSetConsoleFont(hConsole, index);
}

extern WINAPI void wine32a_kernel32_SetConsoleFont(void);  /* ../dlls/kernel32/console.c:1627 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleFont,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleFont") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleIcon(HICON  icon) /* ../dlls/kernel32/console.c:1615 */
{
	TRACE("Enter SetConsoleIcon\n");
	return pSetConsoleIcon(icon);
}

extern WINAPI void wine32a_kernel32_SetConsoleIcon(void);  /* ../dlls/kernel32/console.c:1615 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleKeyShortcuts(BOOL  set, BYTE  keys, void*  a, DWORD  b) /* ../dlls/kernel32/console.c:1634 */
{
	TRACE("Enter SetConsoleKeyShortcuts\n");
	return pSetConsoleKeyShortcuts(set, keys, a, b);
}

extern WINAPI void wine32a_kernel32_SetConsoleKeyShortcuts(void);  /* ../dlls/kernel32/console.c:1634 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleKeyShortcuts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleKeyShortcuts") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetConsoleTitleA(LPCSTR  title) /* ../dlls/kernel32/console.c:478 */
{
	TRACE("Enter SetConsoleTitleA\n");
	return pSetConsoleTitleA(title);
}

extern WINAPI void wine32a_kernel32_SetConsoleTitleA(void);  /* ../dlls/kernel32/console.c:478 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetConsoleTitleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetConsoleTitleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetCurrentConsoleFontEx(HANDLE  hConsole, BOOL  maxwindow, CONSOLE_FONT_INFOEX*  cfix) /* ../dlls/kernel32/console.c:1718 */
{
	TRACE("Enter SetCurrentConsoleFontEx\n");
	return pSetCurrentConsoleFontEx(hConsole, maxwindow, cfix);
}

extern WINAPI void wine32a_kernel32_SetCurrentConsoleFontEx(void);  /* ../dlls/kernel32/console.c:1718 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCurrentConsoleFontEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCurrentConsoleFontEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetCurrentDirectoryA(LPCSTR  dir) /* ../dlls/kernel32/path.c:1746 */
{
	TRACE("Enter SetCurrentDirectoryA\n");
	return pSetCurrentDirectoryA(dir);
}

extern WINAPI void wine32a_kernel32_SetCurrentDirectoryA(void);  /* ../dlls/kernel32/path.c:1746 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCurrentDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCurrentDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetCurrentDirectoryW(LPCWSTR  dir) /* ../dlls/kernel32/path.c:1731 */
{
	TRACE("Enter SetCurrentDirectoryW\n");
	return pSetCurrentDirectoryW(dir);
}

extern WINAPI void wine32a_kernel32_SetCurrentDirectoryW(void);  /* ../dlls/kernel32/path.c:1731 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetCurrentDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetCurrentDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetDefaultCommConfigA(LPCSTR  lpszDevice, LPCOMMCONFIG  lpCommConfig, DWORD  dwSize) /* ../dlls/kernel32/comm.c:664 */
{
	TRACE("Enter SetDefaultCommConfigA\n");
	return pSetDefaultCommConfigA(lpszDevice, lpCommConfig, dwSize);
}

extern WINAPI void wine32a_kernel32_SetDefaultCommConfigA(void);  /* ../dlls/kernel32/comm.c:664 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetDefaultCommConfigA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetDefaultCommConfigA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetDefaultCommConfigW(LPCWSTR  lpszDevice, LPCOMMCONFIG  lpCommConfig, DWORD  dwSize) /* ../dlls/kernel32/comm.c:634 */
{
	TRACE("Enter SetDefaultCommConfigW\n");
	return pSetDefaultCommConfigW(lpszDevice, lpCommConfig, dwSize);
}

extern WINAPI void wine32a_kernel32_SetDefaultCommConfigW(void);  /* ../dlls/kernel32/comm.c:634 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetDefaultCommConfigW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetDefaultCommConfigW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetDefaultDllDirectories(DWORD  flags) /* ../dlls/kernel32/module.c:218 */
{
	TRACE("Enter SetDefaultDllDirectories\n");
	return pSetDefaultDllDirectories(flags);
}

extern WINAPI void wine32a_kernel32_SetDefaultDllDirectories(void);  /* ../dlls/kernel32/module.c:218 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetDefaultDllDirectories,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetDefaultDllDirectories") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetDllDirectoryA(LPCSTR  dir) /* ../dlls/kernel32/module.c:131 */
{
	TRACE("Enter SetDllDirectoryA\n");
	return pSetDllDirectoryA(dir);
}

extern WINAPI void wine32a_kernel32_SetDllDirectoryA(void);  /* ../dlls/kernel32/module.c:131 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetDllDirectoryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetDllDirectoryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetDllDirectoryW(LPCWSTR  dir) /* ../dlls/kernel32/module.c:146 */
{
	TRACE("Enter SetDllDirectoryW\n");
	return pSetDllDirectoryW(dir);
}

extern WINAPI void wine32a_kernel32_SetDllDirectoryW(void);  /* ../dlls/kernel32/module.c:146 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetDllDirectoryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetDllDirectoryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetFileCompletionNotificationModes(HANDLE  file, UCHAR  flags) /* ../dlls/kernel32/file.c:393 */
{
	TRACE("Enter SetFileCompletionNotificationModes\n");
	return pSetFileCompletionNotificationModes(file, flags);
}

extern WINAPI void wine32a_kernel32_SetFileCompletionNotificationModes(void);  /* ../dlls/kernel32/file.c:393 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetFileCompletionNotificationModes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetFileCompletionNotificationModes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetHandleContext(HANDLE  hnd, DWORD  context) /* ../dlls/kernel32/process.c:3350 */
{
	TRACE("Enter SetHandleContext\n");
	return pSetHandleContext(hnd, context);
}

extern WINAPI void wine32a_kernel32_SetHandleContext(void);  /* ../dlls/kernel32/process.c:3350 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetHandleContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetHandleContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32_SetHandleCount(UINT  count) /* ../dlls/kernel32/file.c:410 */
{
	TRACE("Enter SetHandleCount\n");
	return pSetHandleCount(count);
}

extern WINAPI void wine32a_kernel32_SetHandleCount(void);  /* ../dlls/kernel32/file.c:410 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetHandleCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetHandleCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetHandleInformation(HANDLE  handle, DWORD  mask, DWORD  flags) /* ../dlls/kernel32/process.c:3281 */
{
	TRACE("Enter SetHandleInformation\n");
	return pSetHandleInformation(handle, mask, flags);
}

extern WINAPI void wine32a_kernel32_SetHandleInformation(void);  /* ../dlls/kernel32/process.c:3281 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetHandleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetHandleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetInformationJobObject(HANDLE  job, JOBOBJECTINFOCLASS  class, LPVOID  info, DWORD  len) /* ../dlls/kernel32/sync.c:368 */
{
	TRACE("Enter SetInformationJobObject\n");
	return pSetInformationJobObject(job, class, info, len);
}

extern WINAPI void wine32a_kernel32_SetInformationJobObject(void);  /* ../dlls/kernel32/sync.c:368 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetInformationJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetLocalTime(SYSTEMTIME*  systime) /* ../dlls/kernel32/time.c:531 */
{
	TRACE("Enter SetLocalTime\n");
	return pSetLocalTime(systime);
}

extern WINAPI void wine32a_kernel32_SetLocalTime(void);  /* ../dlls/kernel32/time.c:531 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetLocaleInfoA(LCID  lcid, LCTYPE  lctype, LPCSTR  data) /* ../dlls/kernel32/locale.c:1878 */
{
	TRACE("Enter SetLocaleInfoA\n");
	return pSetLocaleInfoA(lcid, lctype, data);
}

extern WINAPI void wine32a_kernel32_SetLocaleInfoA(void);  /* ../dlls/kernel32/locale.c:1878 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetLocaleInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetLocaleInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetLocaleInfoW(LCID  lcid, LCTYPE  lctype, LPCWSTR  data) /* ../dlls/kernel32/locale.c:1910 */
{
	TRACE("Enter SetLocaleInfoW\n");
	return pSetLocaleInfoW(lcid, lctype, data);
}

extern WINAPI void wine32a_kernel32_SetLocaleInfoW(void);  /* ../dlls/kernel32/locale.c:1910 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetLocaleInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetLocaleInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetMailslotInfo(HANDLE  hMailslot, DWORD  dwReadTimeout) /* ../dlls/kernel32/sync.c:973 */
{
	TRACE("Enter SetMailslotInfo\n");
	return pSetMailslotInfo(hMailslot, dwReadTimeout);
}

extern WINAPI void wine32a_kernel32_SetMailslotInfo(void);  /* ../dlls/kernel32/sync.c:973 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetMailslotInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetMailslotInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetProcessAffinityMask(HANDLE  hProcess, DWORD_PTR  affmask) /* ../dlls/kernel32/process.c:3386 */
{
	TRACE("Enter SetProcessAffinityMask\n");
	return pSetProcessAffinityMask(hProcess, affmask);
}

extern WINAPI void wine32a_kernel32_SetProcessAffinityMask(void);  /* ../dlls/kernel32/process.c:3386 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetProcessAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetProcessAffinityMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetProcessDEPPolicy(DWORD  newDEP) /* ../dlls/kernel32/process.c:3927 */
{
	TRACE("Enter SetProcessDEPPolicy\n");
	return pSetProcessDEPPolicy(newDEP);
}

extern WINAPI void wine32a_kernel32_SetProcessDEPPolicy(void);  /* ../dlls/kernel32/process.c:3927 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetProcessDEPPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetProcessDEPPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetProcessPreferredUILanguages(DWORD  flags, PCZZWSTR  buffer, PULONG  count) /* ../dlls/kernel32/locale.c:1324 */
{
	TRACE("Enter SetProcessPreferredUILanguages\n");
	return pSetProcessPreferredUILanguages(flags, buffer, count);
}

extern WINAPI void wine32a_kernel32_SetProcessPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1324 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetProcessPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetProcessPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetProcessWorkingSetSize(HANDLE  process, SIZE_T  minset, SIZE_T  maxset) /* ../dlls/kernel32/process.c:3495 */
{
	TRACE("Enter SetProcessWorkingSetSize\n");
	return pSetProcessWorkingSetSize(process, minset, maxset);
}

extern WINAPI void wine32a_kernel32_SetProcessWorkingSetSize(void);  /* ../dlls/kernel32/process.c:3495 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetProcessWorkingSetSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetProcessWorkingSetSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetSearchPathMode(DWORD  flags) /* ../dlls/kernel32/path.c:2024 */
{
	TRACE("Enter SetSearchPathMode\n");
	return pSetSearchPathMode(flags);
}

extern WINAPI void wine32a_kernel32_SetSearchPathMode(void);  /* ../dlls/kernel32/path.c:2024 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetSearchPathMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetSearchPathMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetSystemFileCacheSize(SIZE_T  mincache, SIZE_T  maxcache, DWORD  flags) /* ../dlls/kernel32/heap.c:922 */
{
	TRACE("Enter SetSystemFileCacheSize\n");
	return pSetSystemFileCacheSize(mincache, maxcache, flags);
}

extern WINAPI void wine32a_kernel32_SetSystemFileCacheSize(void);  /* ../dlls/kernel32/heap.c:922 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetSystemFileCacheSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetSystemFileCacheSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetSystemPowerState(BOOL  suspend_or_hibernate, BOOL  force_flag) /* ../dlls/kernel32/powermgnt.c:94 */
{
	TRACE("Enter SetSystemPowerState\n");
	return pSetSystemPowerState(suspend_or_hibernate, force_flag);
}

extern WINAPI void wine32a_kernel32_SetSystemPowerState(void);  /* ../dlls/kernel32/powermgnt.c:94 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetSystemPowerState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetSystemPowerState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetSystemTime(SYSTEMTIME*  systime) /* ../dlls/kernel32/time.c:589 */
{
	TRACE("Enter SetSystemTime\n");
	return pSetSystemTime(systime);
}

extern WINAPI void wine32a_kernel32_SetSystemTime(void);  /* ../dlls/kernel32/time.c:589 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetSystemTimeAdjustment(DWORD  dwTimeAdjustment, BOOL  bTimeAdjustmentDisabled) /* ../dlls/kernel32/time.c:617 */
{
	TRACE("Enter SetSystemTimeAdjustment\n");
	return pSetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled);
}

extern WINAPI void wine32a_kernel32_SetSystemTimeAdjustment(void);  /* ../dlls/kernel32/time.c:617 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetSystemTimeAdjustment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetSystemTimeAdjustment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_SetTapeParameters(HANDLE  device, DWORD  operation, LPVOID  info) /* ../dlls/kernel32/tape.c:250 */
{
	TRACE("Enter SetTapeParameters\n");
	return pSetTapeParameters(device, operation, info);
}

extern WINAPI void wine32a_kernel32_SetTapeParameters(void);  /* ../dlls/kernel32/tape.c:250 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetTapeParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetTapeParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_SetTapePosition(HANDLE  device, DWORD  method, DWORD  partition, DWORD  offset_low, DWORD  offset_high, BOOL  immediate) /* ../dlls/kernel32/tape.c:282 */
{
	TRACE("Enter SetTapePosition\n");
	return pSetTapePosition(device, method, partition, offset_low, offset_high, immediate);
}

extern WINAPI void wine32a_kernel32_SetTapePosition(void);  /* ../dlls/kernel32/tape.c:282 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetTapePosition,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetTapePosition") "\n"
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

extern WINAPI DWORD wine32b_kernel32_SetTermsrvAppInstallMode(BOOL  bInstallMode) /* ../dlls/kernel32/version.c:107 */
{
	TRACE("Enter SetTermsrvAppInstallMode\n");
	return pSetTermsrvAppInstallMode(bInstallMode);
}

extern WINAPI void wine32a_kernel32_SetTermsrvAppInstallMode(void);  /* ../dlls/kernel32/version.c:107 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetTermsrvAppInstallMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetTermsrvAppInstallMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD_PTR wine32b_kernel32_SetThreadAffinityMask(HANDLE  hThread, DWORD_PTR  dwThreadAffinityMask) /* ../dlls/kernel32/thread.c:83 */
{
	TRACE("Enter SetThreadAffinityMask\n");
	return pSetThreadAffinityMask(hThread, dwThreadAffinityMask);
}

extern WINAPI void wine32a_kernel32_SetThreadAffinityMask(void);  /* ../dlls/kernel32/thread.c:83 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetThreadAffinityMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetThreadAffinityMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_SetThreadExecutionState(EXECUTION_STATE  flags) /* ../dlls/kernel32/powermgnt.c:107 */
{
	TRACE("Enter SetThreadExecutionState\n");
	return pSetThreadExecutionState(flags);
}

extern WINAPI void wine32a_kernel32_SetThreadExecutionState(void);  /* ../dlls/kernel32/powermgnt.c:107 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetThreadExecutionState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetThreadExecutionState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetThreadLocale(LCID  lcid) /* ../dlls/kernel32/locale.c:2812 */
{
	TRACE("Enter SetThreadLocale\n");
	return pSetThreadLocale(lcid);
}

extern WINAPI void wine32a_kernel32_SetThreadLocale(void);  /* ../dlls/kernel32/locale.c:2812 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetThreadLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetThreadLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetThreadPreferredUILanguages(DWORD  flags, PCZZWSTR  buffer, PULONG  count) /* ../dlls/kernel32/locale.c:1333 */
{
	TRACE("Enter SetThreadPreferredUILanguages\n");
	return pSetThreadPreferredUILanguages(flags, buffer, count);
}

extern WINAPI void wine32a_kernel32_SetThreadPreferredUILanguages(void);  /* ../dlls/kernel32/locale.c:1333 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetThreadPreferredUILanguages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetThreadPreferredUILanguages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LANGID wine32b_kernel32_SetThreadUILanguage(LANGID  langid) /* ../dlls/kernel32/locale.c:2846 */
{
	TRACE("Enter SetThreadUILanguage\n");
	return pSetThreadUILanguage(langid);
}

extern WINAPI void wine32a_kernel32_SetThreadUILanguage(void);  /* ../dlls/kernel32/locale.c:2846 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetThreadUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetThreadUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetTimeZoneInformation(TIME_ZONE_INFORMATION*  tzinfo) /* ../dlls/kernel32/time.c:686 */
{
	TRACE("Enter SetTimeZoneInformation\n");
	return pSetTimeZoneInformation(tzinfo);
}

extern WINAPI void wine32a_kernel32_SetTimeZoneInformation(void);  /* ../dlls/kernel32/time.c:686 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetUmsThreadInformation(PUMS_CONTEXT  ctx, UMS_THREAD_INFO_CLASS  class, void*  buf, ULONG  length) /* ../dlls/kernel32/process.c:4237 */
{
	TRACE("Enter SetUmsThreadInformation\n");
	return pSetUmsThreadInformation(ctx, class, buf, length);
}

extern WINAPI void wine32a_kernel32_SetUmsThreadInformation(void);  /* ../dlls/kernel32/process.c:4237 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetUmsThreadInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetUmsThreadInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetUserGeoID(GEOID  GeoID) /* ../dlls/kernel32/locale.c:4648 */
{
	TRACE("Enter SetUserGeoID\n");
	return pSetUserGeoID(GeoID);
}

extern WINAPI void wine32a_kernel32_SetUserGeoID(void);  /* ../dlls/kernel32/locale.c:4648 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetUserGeoID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetUserGeoID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetVolumeLabelA(LPCSTR  root, LPCSTR  volname) /* ../dlls/kernel32/volume.c:965 */
{
	TRACE("Enter SetVolumeLabelA\n");
	return pSetVolumeLabelA(root, volname);
}

extern WINAPI void wine32a_kernel32_SetVolumeLabelA(void);  /* ../dlls/kernel32/volume.c:965 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetVolumeLabelA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetVolumeLabelA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetVolumeLabelW(LPCWSTR  root, LPCWSTR  label) /* ../dlls/kernel32/volume.c:872 */
{
	TRACE("Enter SetVolumeLabelW\n");
	return pSetVolumeLabelW(root, label);
}

extern WINAPI void wine32a_kernel32_SetVolumeLabelW(void);  /* ../dlls/kernel32/volume.c:872 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetVolumeLabelW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetVolumeLabelW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetVolumeMountPointA(LPCSTR  path, LPCSTR  volume) /* ../dlls/kernel32/volume.c:2144 */
{
	TRACE("Enter SetVolumeMountPointA\n");
	return pSetVolumeMountPointA(path, volume);
}

extern WINAPI void wine32a_kernel32_SetVolumeMountPointA(void);  /* ../dlls/kernel32/volume.c:2144 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetVolumeMountPointA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetVolumeMountPointA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SetVolumeMountPointW(LPCWSTR  path, LPCWSTR  volume) /* ../dlls/kernel32/volume.c:2154 */
{
	TRACE("Enter SetVolumeMountPointW\n");
	return pSetVolumeMountPointW(path, volume);
}

extern WINAPI void wine32a_kernel32_SetVolumeMountPointW(void);  /* ../dlls/kernel32/volume.c:2154 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SetVolumeMountPointW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SetVolumeMountPointW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SystemTimeToFileTime(SYSTEMTIME*  syst, LPFILETIME  ft) /* ../dlls/kernel32/time.c:1239 */
{
	TRACE("Enter SystemTimeToFileTime\n");
	return pSystemTimeToFileTime(syst, ft);
}

extern WINAPI void wine32a_kernel32_SystemTimeToFileTime(void);  /* ../dlls/kernel32/time.c:1239 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SystemTimeToFileTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SystemTimeToFileTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_SystemTimeToTzSpecificLocalTime(TIME_ZONE_INFORMATION*  lpTimeZoneInformation, SYSTEMTIME*  lpUniversalTime, LPSYSTEMTIME  lpLocalTime) /* ../dlls/kernel32/time.c:712 */
{
	TRACE("Enter SystemTimeToTzSpecificLocalTime\n");
	return pSystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime);
}

extern WINAPI void wine32a_kernel32_SystemTimeToTzSpecificLocalTime(void);  /* ../dlls/kernel32/time.c:712 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_SystemTimeToTzSpecificLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_SystemTimeToTzSpecificLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_TerminateJobObject(HANDLE  job, UINT  exit_code) /* ../dlls/kernel32/sync.c:347 */
{
	TRACE("Enter TerminateJobObject\n");
	return pTerminateJobObject(job, exit_code);
}

extern WINAPI void wine32a_kernel32_TerminateJobObject(void);  /* ../dlls/kernel32/sync.c:347 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_TerminateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_TerminateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_TermsrvAppInstallMode(void) /* ../dlls/kernel32/version.c:91 */
{
	TRACE("Enter TermsrvAppInstallMode\n");
	return pTermsrvAppInstallMode();
}

extern WINAPI void wine32a_kernel32_TermsrvAppInstallMode(void);  /* ../dlls/kernel32/version.c:91 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_TermsrvAppInstallMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_TermsrvAppInstallMode") "\n"
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

extern WINAPI BOOL wine32b_kernel32_Thread32First(HANDLE  hSnapShot, LPTHREADENTRY32  lpte) /* ../dlls/kernel32/toolhelp.c:382 */
{
	TRACE("Enter Thread32First\n");
	return pThread32First(hSnapShot, lpte);
}

extern WINAPI void wine32a_kernel32_Thread32First(void);  /* ../dlls/kernel32/toolhelp.c:382 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Thread32First,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Thread32First") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Thread32Next(HANDLE  hSnapShot, LPTHREADENTRY32  lpte) /* ../dlls/kernel32/toolhelp.c:392 */
{
	TRACE("Enter Thread32Next\n");
	return pThread32Next(hSnapShot, lpte);
}

extern WINAPI void wine32a_kernel32_Thread32Next(void);  /* ../dlls/kernel32/toolhelp.c:392 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Thread32Next,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Thread32Next") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Toolhelp32ReadProcessMemory(DWORD  pid, void*  base, void*  buf, SIZE_T  len, SIZE_T*  r) /* ../dlls/kernel32/toolhelp.c:611 */
{
	TRACE("Enter Toolhelp32ReadProcessMemory\n");
	return pToolhelp32ReadProcessMemory(pid, base, buf, len, r);
}

extern WINAPI void wine32a_kernel32_Toolhelp32ReadProcessMemory(void);  /* ../dlls/kernel32/toolhelp.c:611 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Toolhelp32ReadProcessMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Toolhelp32ReadProcessMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_TzSpecificLocalTimeToSystemTime(TIME_ZONE_INFORMATION*  lpTimeZoneInformation, SYSTEMTIME*  lpLocalTime, LPSYSTEMTIME  lpUniversalTime) /* ../dlls/kernel32/time.c:757 */
{
	TRACE("Enter TzSpecificLocalTimeToSystemTime\n");
	return pTzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime);
}

extern WINAPI void wine32a_kernel32_TzSpecificLocalTimeToSystemTime(void);  /* ../dlls/kernel32/time.c:757 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_TzSpecificLocalTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_TzSpecificLocalTimeToSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_UmsThreadYield(void*  param) /* ../dlls/kernel32/process.c:4248 */
{
	TRACE("Enter UmsThreadYield\n");
	return pUmsThreadYield(param);
}

extern WINAPI void wine32a_kernel32_UmsThreadYield(void);  /* ../dlls/kernel32/process.c:4248 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UmsThreadYield,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UmsThreadYield") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_kernel32_UninitializeCriticalSection(CRITICAL_SECTION*  crit) /* ../dlls/kernel32/sync.c:188 */
{
	TRACE("Enter UninitializeCriticalSection\n");
	return pUninitializeCriticalSection(crit);
}

extern WINAPI void wine32a_kernel32_UninitializeCriticalSection(void);  /* ../dlls/kernel32/sync.c:188 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UninitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UninitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_UnregisterApplicationRestart(void) /* ../dlls/kernel32/process.c:4116 */
{
	TRACE("Enter UnregisterApplicationRestart\n");
	return pUnregisterApplicationRestart();
}

extern WINAPI void wine32a_kernel32_UnregisterApplicationRestart(void);  /* ../dlls/kernel32/process.c:4116 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UnregisterApplicationRestart,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UnregisterApplicationRestart") "\n"
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

extern WINAPI BOOL wine32b_kernel32_UnregisterWait(HANDLE  WaitHandle) /* ../dlls/kernel32/sync.c:129 */
{
	TRACE("Enter UnregisterWait\n");
	return pUnregisterWait(WaitHandle);
}

extern WINAPI void wine32a_kernel32_UnregisterWait(void);  /* ../dlls/kernel32/sync.c:129 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UnregisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UnregisterWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_UpdateResourceA(HANDLE  hUpdate, LPCSTR  lpType, LPCSTR  lpName, WORD  wLanguage, LPVOID  lpData, DWORD  cbData) /* ../dlls/kernel32/resource.c:1321 */
{
	TRACE("Enter UpdateResourceA\n");
	return pUpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
}

extern WINAPI void wine32a_kernel32_UpdateResourceA(void);  /* ../dlls/kernel32/resource.c:1321 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UpdateResourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UpdateResourceA") "\n"
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

extern WINAPI BOOL wine32b_kernel32_UpdateResourceW(HANDLE  hUpdate, LPCWSTR  lpType, LPCWSTR  lpName, WORD  wLanguage, LPVOID  lpData, DWORD  cbData) /* ../dlls/kernel32/resource.c:1289 */
{
	TRACE("Enter UpdateResourceW\n");
	return pUpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
}

extern WINAPI void wine32a_kernel32_UpdateResourceW(void);  /* ../dlls/kernel32/resource.c:1289 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_UpdateResourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_UpdateResourceW") "\n"
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

extern WINAPI DWORD wine32b_kernel32_VerLanguageNameA(DWORD  wLang, LPSTR  szLang, DWORD  nSize) /* ../dlls/kernel32/locale.c:3065 */
{
	TRACE("Enter VerLanguageNameA\n");
	return pVerLanguageNameA(wLang, szLang, nSize);
}

extern WINAPI void wine32a_kernel32_VerLanguageNameA(void);  /* ../dlls/kernel32/locale.c:3065 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_VerLanguageNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_VerLanguageNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_VerLanguageNameW(DWORD  wLang, LPWSTR  szLang, DWORD  nSize) /* ../dlls/kernel32/locale.c:3076 */
{
	TRACE("Enter VerLanguageNameW\n");
	return pVerLanguageNameW(wLang, szLang, nSize);
}

extern WINAPI void wine32a_kernel32_VerLanguageNameW(void);  /* ../dlls/kernel32/locale.c:3076 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_VerLanguageNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_VerLanguageNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_VerifyConsoleIoHandle(HANDLE  handle) /* ../dlls/kernel32/console.c:255 */
{
	TRACE("Enter VerifyConsoleIoHandle\n");
	return pVerifyConsoleIoHandle(handle);
}

extern WINAPI void wine32a_kernel32_VerifyConsoleIoHandle(void);  /* ../dlls/kernel32/console.c:255 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_VerifyConsoleIoHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_VerifyConsoleIoHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_VerifyVersionInfoA(LPOSVERSIONINFOEXA  lpVersionInfo, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask) /* ../dlls/kernel32/version.c:48 */
{
	TRACE("Enter VerifyVersionInfoA\n");
	return pVerifyVersionInfoA(lpVersionInfo, dwTypeMask, dwlConditionMask);
}

extern WINAPI void wine32a_kernel32_VerifyVersionInfoA(void);  /* ../dlls/kernel32/version.c:48 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_VerifyVersionInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_VerifyVersionInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_VerifyVersionInfoW(LPOSVERSIONINFOEXW  lpVersionInfo, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask) /* ../dlls/kernel32/version.c:71 */
{
	TRACE("Enter VerifyVersionInfoW\n");
	return pVerifyVersionInfoW(lpVersionInfo, dwTypeMask, dwlConditionMask);
}

extern WINAPI void wine32a_kernel32_VerifyVersionInfoW(void);  /* ../dlls/kernel32/version.c:71 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_VerifyVersionInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_VerifyVersionInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_WTSGetActiveConsoleSessionId(void) /* ../dlls/kernel32/process.c:3907 */
{
	TRACE("Enter WTSGetActiveConsoleSessionId\n");
	return pWTSGetActiveConsoleSessionId();
}

extern WINAPI void wine32a_kernel32_WTSGetActiveConsoleSessionId(void);  /* ../dlls/kernel32/process.c:3907 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WTSGetActiveConsoleSessionId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WTSGetActiveConsoleSessionId") "\n"
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

extern WINAPI BOOL wine32b_kernel32_WaitNamedPipeA(LPCSTR  name, DWORD  nTimeOut) /* ../dlls/kernel32/sync.c:548 */
{
	TRACE("Enter WaitNamedPipeA\n");
	return pWaitNamedPipeA(name, nTimeOut);
}

extern WINAPI void wine32a_kernel32_WaitNamedPipeA(void);  /* ../dlls/kernel32/sync.c:548 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WaitNamedPipeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WaitNamedPipeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerRegisterFile(PCWSTR  file, WER_REGISTER_FILE_TYPE  regfiletype, DWORD  flags) /* ../dlls/kernel32/wer.c:37 */
{
	TRACE("Enter WerRegisterFile\n");
	return pWerRegisterFile(file, regfiletype, flags);
}

extern WINAPI void wine32a_kernel32_WerRegisterFile(void);  /* ../dlls/kernel32/wer.c:37 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerRegisterFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerRegisterFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerRegisterMemoryBlock(void*  block, DWORD  size) /* ../dlls/kernel32/wer.c:70 */
{
	TRACE("Enter WerRegisterMemoryBlock\n");
	return pWerRegisterMemoryBlock(block, size);
}

extern WINAPI void wine32a_kernel32_WerRegisterMemoryBlock(void);  /* ../dlls/kernel32/wer.c:70 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerRegisterMemoryBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerRegisterMemoryBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerRegisterRuntimeExceptionModule(PCWSTR  callbackdll, PVOID  context) /* ../dlls/kernel32/wer.c:49 */
{
	TRACE("Enter WerRegisterRuntimeExceptionModule\n");
	return pWerRegisterRuntimeExceptionModule(callbackdll, context);
}

extern WINAPI void wine32a_kernel32_WerRegisterRuntimeExceptionModule(void);  /* ../dlls/kernel32/wer.c:49 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerRegisterRuntimeExceptionModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerRegisterRuntimeExceptionModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerSetFlags(DWORD  flags) /* ../dlls/kernel32/wer.c:61 */
{
	TRACE("Enter WerSetFlags\n");
	return pWerSetFlags(flags);
}

extern WINAPI void wine32a_kernel32_WerSetFlags(void);  /* ../dlls/kernel32/wer.c:61 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerSetFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerSetFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerUnregisterMemoryBlock(void*  block) /* ../dlls/kernel32/wer.c:79 */
{
	TRACE("Enter WerUnregisterMemoryBlock\n");
	return pWerUnregisterMemoryBlock(block);
}

extern WINAPI void wine32a_kernel32_WerUnregisterMemoryBlock(void);  /* ../dlls/kernel32/wer.c:79 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerUnregisterMemoryBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerUnregisterMemoryBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HRESULT wine32b_kernel32_WerUnregisterRuntimeExceptionModule(PCWSTR  callbackdll, PVOID  context) /* ../dlls/kernel32/wer.c:88 */
{
	TRACE("Enter WerUnregisterRuntimeExceptionModule\n");
	return pWerUnregisterRuntimeExceptionModule(callbackdll, context);
}

extern WINAPI void wine32a_kernel32_WerUnregisterRuntimeExceptionModule(void);  /* ../dlls/kernel32/wer.c:88 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WerUnregisterRuntimeExceptionModule,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WerUnregisterRuntimeExceptionModule") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_kernel32_WideCharToMultiByte(UINT  page, DWORD  flags, LPCWSTR  src, INT  srclen, LPSTR  dst, INT  dstlen, LPCSTR  defchar, BOOL*  used) /* ../dlls/kernel32/locale.c:2680 */
{
	TRACE("Enter WideCharToMultiByte\n");
	return pWideCharToMultiByte(page, flags, src, srclen, dst, dstlen, defchar, used);
}

extern WINAPI void wine32a_kernel32_WideCharToMultiByte(void);  /* ../dlls/kernel32/locale.c:2680 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WideCharToMultiByte,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WideCharToMultiByte") "\n"
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

extern WINAPI UINT wine32b_kernel32_WinExec(LPCSTR  lpCmdLine, UINT  nCmdShow) /* ../dlls/kernel32/process.c:3039 */
{
	TRACE("Enter WinExec\n");
	return pWinExec(lpCmdLine, nCmdShow);
}

extern WINAPI void wine32a_kernel32_WinExec(void);  /* ../dlls/kernel32/process.c:3039 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WinExec,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WinExec") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOLEAN wine32b_kernel32_Wow64EnableWow64FsRedirection(BOOLEAN  enable) /* ../dlls/kernel32/path.c:1833 */
{
	TRACE("Enter Wow64EnableWow64FsRedirection\n");
	return pWow64EnableWow64FsRedirection(enable);
}

extern WINAPI void wine32a_kernel32_Wow64EnableWow64FsRedirection(void);  /* ../dlls/kernel32/path.c:1833 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Wow64EnableWow64FsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Wow64EnableWow64FsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Wow64GetThreadContext(HANDLE  handle, WOW64_CONTEXT*  context) /* ../dlls/kernel32/thread.c:66 */
{
	TRACE("Enter Wow64GetThreadContext\n");
	return pWow64GetThreadContext(handle, context);
}

extern WINAPI void wine32a_kernel32_Wow64GetThreadContext(void);  /* ../dlls/kernel32/thread.c:66 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Wow64GetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Wow64GetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_Wow64SetThreadContext(HANDLE  handle, WOW64_CONTEXT*  context) /* ../dlls/kernel32/thread.c:50 */
{
	TRACE("Enter Wow64SetThreadContext\n");
	return pWow64SetThreadContext(handle, context);
}

extern WINAPI void wine32a_kernel32_Wow64SetThreadContext(void);  /* ../dlls/kernel32/thread.c:50 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_Wow64SetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_Wow64SetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WriteConsoleW(HANDLE  hConsoleOutput, LPCVOID  lpBuffer, DWORD  nNumberOfCharsToWrite, LPDWORD  lpNumberOfCharsWritten, LPVOID  lpReserved) /* ../dlls/kernel32/console.c:1132 */
{
	TRACE("Enter WriteConsoleW\n");
	return pWriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
}

extern WINAPI void wine32a_kernel32_WriteConsoleW(void);  /* ../dlls/kernel32/console.c:1132 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteConsoleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteConsoleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileSectionA(LPCSTR  section, LPCSTR  string, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1465 */
{
	TRACE("Enter WritePrivateProfileSectionA\n");
	return pWritePrivateProfileSectionA(section, string, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileSectionA(void);  /* ../dlls/kernel32/profile.c:1465 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileSectionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileSectionW(LPCWSTR  section, LPCWSTR  string, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1423 */
{
	TRACE("Enter WritePrivateProfileSectionW\n");
	return pWritePrivateProfileSectionW(section, string, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileSectionW(void);  /* ../dlls/kernel32/profile.c:1423 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileSectionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileStringA(LPCSTR  section, LPCSTR  entry, LPCSTR  string, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1396 */
{
	TRACE("Enter WritePrivateProfileStringA\n");
	return pWritePrivateProfileStringA(section, entry, string, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileStringA(void);  /* ../dlls/kernel32/profile.c:1396 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileStringW(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  string, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1365 */
{
	TRACE("Enter WritePrivateProfileStringW\n");
	return pWritePrivateProfileStringW(section, entry, string, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileStringW(void);  /* ../dlls/kernel32/profile.c:1365 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileStructA(LPCSTR  section, LPCSTR  key, LPVOID  buf, UINT  bufsize, LPCSTR  filename) /* ../dlls/kernel32/profile.c:1750 */
{
	TRACE("Enter WritePrivateProfileStructA\n");
	return pWritePrivateProfileStructA(section, key, buf, bufsize, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileStructA(void);  /* ../dlls/kernel32/profile.c:1750 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileStructA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileStructA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WritePrivateProfileStructW(LPCWSTR  section, LPCWSTR  key, LPVOID  buf, UINT  bufsize, LPCWSTR  filename) /* ../dlls/kernel32/profile.c:1709 */
{
	TRACE("Enter WritePrivateProfileStructW\n");
	return pWritePrivateProfileStructW(section, key, buf, bufsize, filename);
}

extern WINAPI void wine32a_kernel32_WritePrivateProfileStructW(void);  /* ../dlls/kernel32/profile.c:1709 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WritePrivateProfileStructW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WritePrivateProfileStructW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WriteProfileSectionA(LPCSTR  section, LPCSTR  keys_n_values) /* ../dlls/kernel32/profile.c:1501 */
{
	TRACE("Enter WriteProfileSectionA\n");
	return pWriteProfileSectionA(section, keys_n_values);
}

extern WINAPI void wine32a_kernel32_WriteProfileSectionA(void);  /* ../dlls/kernel32/profile.c:1501 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteProfileSectionA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteProfileSectionA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WriteProfileSectionW(LPCWSTR  section, LPCWSTR  keys_n_values) /* ../dlls/kernel32/profile.c:1510 */
{
	TRACE("Enter WriteProfileSectionW\n");
	return pWriteProfileSectionW(section, keys_n_values);
}

extern WINAPI void wine32a_kernel32_WriteProfileSectionW(void);  /* ../dlls/kernel32/profile.c:1510 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteProfileSectionW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteProfileSectionW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WriteProfileStringA(LPCSTR  section, LPCSTR  entry, LPCSTR  string) /* ../dlls/kernel32/profile.c:1207 */
{
	TRACE("Enter WriteProfileStringA\n");
	return pWriteProfileStringA(section, entry, string);
}

extern WINAPI void wine32a_kernel32_WriteProfileStringA(void);  /* ../dlls/kernel32/profile.c:1207 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteProfileStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteProfileStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_kernel32_WriteProfileStringW(LPCWSTR  section, LPCWSTR  entry, LPCWSTR  string) /* ../dlls/kernel32/profile.c:1216 */
{
	TRACE("Enter WriteProfileStringW\n");
	return pWriteProfileStringW(section, entry, string);
}

extern WINAPI void wine32a_kernel32_WriteProfileStringW(void);  /* ../dlls/kernel32/profile.c:1216 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteProfileStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteProfileStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_kernel32_WriteTapemark(HANDLE  device, DWORD  type, DWORD  count, BOOL  immediate) /* ../dlls/kernel32/tape.c:310 */
{
	TRACE("Enter WriteTapemark\n");
	return pWriteTapemark(device, type, count, immediate);
}

extern WINAPI void wine32a_kernel32_WriteTapemark(void);  /* ../dlls/kernel32/tape.c:310 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_WriteTapemark,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_WriteTapemark") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32__hread(HFILE  hFile, LPVOID  buffer, LONG  count) /* ../dlls/kernel32/file.c:287 */
{
	TRACE("Enter _hread\n");
	return p_hread(hFile, buffer, count);
}

extern WINAPI void wine32a_kernel32__hread(void);  /* ../dlls/kernel32/file.c:287 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__hread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__hread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32__hwrite(HFILE  handle, LPCSTR  buffer, LONG  count) /* ../dlls/kernel32/file.c:303 */
{
	TRACE("Enter _hwrite\n");
	return p_hwrite(handle, buffer, count);
}

extern WINAPI void wine32a_kernel32__hwrite(void);  /* ../dlls/kernel32/file.c:303 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__hwrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__hwrite") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32__lclose(HFILE  hFile) /* ../dlls/kernel32/file.c:324 */
{
	TRACE("Enter _lclose\n");
	return p_lclose(hFile);
}

extern WINAPI void wine32a_kernel32__lclose(void);  /* ../dlls/kernel32/file.c:324 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__lclose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__lclose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32__lcreat(LPCSTR  path, INT  attr) /* ../dlls/kernel32/file.c:334 */
{
	TRACE("Enter _lcreat\n");
	return p_lcreat(path, attr);
}

extern WINAPI void wine32a_kernel32__lcreat(void);  /* ../dlls/kernel32/file.c:334 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__lcreat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__lcreat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_kernel32__llseek(HFILE  hFile, LONG  lOffset, INT  nOrigin) /* ../dlls/kernel32/file.c:375 */
{
	TRACE("Enter _llseek\n");
	return p_llseek(hFile, lOffset, nOrigin);
}

extern WINAPI void wine32a_kernel32__llseek(void);  /* ../dlls/kernel32/file.c:375 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__llseek,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__llseek") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HFILE wine32b_kernel32__lopen(LPCSTR  path, INT  mode) /* ../dlls/kernel32/file.c:351 */
{
	TRACE("Enter _lopen\n");
	return p_lopen(path, mode);
}

extern WINAPI void wine32a_kernel32__lopen(void);  /* ../dlls/kernel32/file.c:351 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__lopen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__lopen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32__lread(HFILE  handle, LPVOID  buffer, UINT  count) /* ../dlls/kernel32/file.c:363 */
{
	TRACE("Enter _lread\n");
	return p_lread(handle, buffer, count);
}

extern WINAPI void wine32a_kernel32__lread(void);  /* ../dlls/kernel32/file.c:363 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__lread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__lread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_kernel32__lwrite(HFILE  hFile, LPCSTR  buffer, UINT  count) /* ../dlls/kernel32/file.c:384 */
{
	TRACE("Enter _lwrite\n");
	return p_lwrite(hFile, buffer, count);
}

extern WINAPI void wine32a_kernel32__lwrite(void);  /* ../dlls/kernel32/file.c:384 */
__ASM_GLOBAL_FUNC(wine32a_kernel32__lwrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32__lwrite") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernel32_lstrcatA(LPSTR  dst, LPCSTR  src) /* ../dlls/kernel32/string.c:41 */
{
	TRACE("Enter lstrcatA\n");
	return plstrcatA(dst, src);
}

extern WINAPI void wine32a_kernel32_lstrcatA(void);  /* ../dlls/kernel32/string.c:41 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_lstrcatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_lstrcatA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernel32_lstrcatW(LPWSTR  dst, LPCWSTR  src) /* ../dlls/kernel32/string.c:60 */
{
	TRACE("Enter lstrcatW\n");
	return plstrcatW(dst, src);
}

extern WINAPI void wine32a_kernel32_lstrcatW(void);  /* ../dlls/kernel32/string.c:60 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_lstrcatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_lstrcatW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_kernel32_lstrcpyA(LPSTR  dst, LPCSTR  src) /* ../dlls/kernel32/string.c:80 */
{
	TRACE("Enter lstrcpyA\n");
	return plstrcpyA(dst, src);
}

extern WINAPI void wine32a_kernel32_lstrcpyA(void);  /* ../dlls/kernel32/string.c:80 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_lstrcpyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_lstrcpyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_kernel32_lstrcpyW(LPWSTR  dst, LPCWSTR  src) /* ../dlls/kernel32/string.c:100 */
{
	TRACE("Enter lstrcpyW\n");
	return plstrcpyW(dst, src);
}

extern WINAPI void wine32a_kernel32_lstrcpyW(void);  /* ../dlls/kernel32/string.c:100 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_lstrcpyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_lstrcpyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI char* wine32b_kernel32_wine_get_unix_file_name(LPCWSTR  dosW) /* ../dlls/kernel32/path.c:1883 */
{
	TRACE("Enter wine_get_unix_file_name\n");
	return pwine_get_unix_file_name(dosW);
}

extern WINAPI void wine32a_kernel32_wine_get_unix_file_name(void);  /* ../dlls/kernel32/path.c:1883 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_wine_get_unix_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_wine_get_unix_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WCHAR* wine32b_kernel32_wine_get_dos_file_name(LPCSTR  str) /* ../dlls/kernel32/path.c:1907 */
{
	TRACE("Enter wine_get_dos_file_name\n");
	return pwine_get_dos_file_name(str);
}

extern WINAPI void wine32a_kernel32_wine_get_dos_file_name(void);  /* ../dlls/kernel32/path.c:1907 */
__ASM_GLOBAL_FUNC(wine32a_kernel32_wine_get_dos_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32_wine_get_dos_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void* wine32b_kernel32___wine_kernel_init(void) /* ../dlls/kernel32/process.c:1390 */
{
	TRACE("Enter __wine_kernel_init\n");
	return p__wine_kernel_init();
}

extern WINAPI void wine32a_kernel32___wine_kernel_init(void);  /* ../dlls/kernel32/process.c:1390 */
__ASM_GLOBAL_FUNC(wine32a_kernel32___wine_kernel_init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_kernel32___wine_kernel_init") "\n"
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

static BOOL initialized = FALSE;

void wine_thunk_initialize_kernel32(void)
{
	HMODULE library = GetModuleHandleA("kernel32.dll");
	HMODULE library_ntdll = GetModuleHandleA("ntdll.dll");
	HMODULE library_kernelbase = GetModuleHandleA("kernelbase.dll");
	pAcquireSRWLockExclusive = (void *)GetProcAddress(library, "AcquireSRWLockExclusive");
	pextAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockExclusive");
	pAcquireSRWLockShared = (void *)GetProcAddress(library, "AcquireSRWLockShared");
	pextAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockShared");
	pActivateActCtx = (void *)GetProcAddress(library, "ActivateActCtx");
	pextActivateActCtx = (void *)GetProcAddress(library_kernelbase, "ActivateActCtx");
	pAddAtomA = (void *)GetProcAddress(library, "AddAtomA");
	pAddAtomW = (void *)GetProcAddress(library, "AddAtomW");
	pAddConsoleAliasA = (void *)GetProcAddress(library, "AddConsoleAliasA");
	pAddConsoleAliasW = (void *)GetProcAddress(library, "AddConsoleAliasW");
	pAddDllDirectory = (void *)GetProcAddress(library, "AddDllDirectory");
	pAddRefActCtx = (void *)GetProcAddress(library, "AddRefActCtx");
	pextAddRefActCtx = (void *)GetProcAddress(library_kernelbase, "AddRefActCtx");
	pAddVectoredContinueHandler = (void *)GetProcAddress(library, "AddVectoredContinueHandler");
	pextAddVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredContinueHandler");
	pAddVectoredExceptionHandler = (void *)GetProcAddress(library, "AddVectoredExceptionHandler");
	pextAddVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredExceptionHandler");
	pAllocConsole = (void *)GetProcAddress(library, "AllocConsole");
	pAllocateUserPhysicalPages = (void *)GetProcAddress(library, "AllocateUserPhysicalPages");
	pApplicationRecoveryFinished = (void *)GetProcAddress(library, "ApplicationRecoveryFinished");
	pApplicationRecoveryInProgress = (void *)GetProcAddress(library, "ApplicationRecoveryInProgress");
	pAreFileApisANSI = (void *)GetProcAddress(library, "AreFileApisANSI");
	pextAreFileApisANSI = (void *)GetProcAddress(library_kernelbase, "AreFileApisANSI");
	pAssignProcessToJobObject = (void *)GetProcAddress(library, "AssignProcessToJobObject");
	pAttachConsole = (void *)GetProcAddress(library, "AttachConsole");
	pextAttachConsole = (void *)GetProcAddress(library_kernelbase, "AttachConsole");
	pBackupRead = (void *)GetProcAddress(library, "BackupRead");
	pBackupSeek = (void *)GetProcAddress(library, "BackupSeek");
	pBackupWrite = (void *)GetProcAddress(library, "BackupWrite");
	pBaseFlushAppcompatCache = (void *)GetProcAddress(library, "BaseFlushAppcompatCache");
	pBaseGetNamedObjectDirectory = (void *)GetProcAddress(library, "BaseGetNamedObjectDirectory");
	pextBaseGetNamedObjectDirectory = (void *)GetProcAddress(library_kernelbase, "BaseGetNamedObjectDirectory");
	pBeep = (void *)GetProcAddress(library, "Beep");
	pBeginUpdateResourceA = (void *)GetProcAddress(library, "BeginUpdateResourceA");
	pBeginUpdateResourceW = (void *)GetProcAddress(library, "BeginUpdateResourceW");
	pBindIoCompletionCallback = (void *)GetProcAddress(library, "BindIoCompletionCallback");
	pBuildCommDCBA = (void *)GetProcAddress(library, "BuildCommDCBA");
	pBuildCommDCBAndTimeoutsA = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsA");
	pBuildCommDCBAndTimeoutsW = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsW");
	pBuildCommDCBW = (void *)GetProcAddress(library, "BuildCommDCBW");
	pCallbackMayRunLong = (void *)GetProcAddress(library, "CallbackMayRunLong");
	pextCallbackMayRunLong = (void *)GetProcAddress(library_kernelbase, "CallbackMayRunLong");
	pCallNamedPipeA = (void *)GetProcAddress(library, "CallNamedPipeA");
	pCallNamedPipeW = (void *)GetProcAddress(library, "CallNamedPipeW");
	pextCallNamedPipeW = (void *)GetProcAddress(library_kernelbase, "CallNamedPipeW");
	pCancelIo = (void *)GetProcAddress(library, "CancelIo");
	pextCancelIo = (void *)GetProcAddress(library_kernelbase, "CancelIo");
	pCancelIoEx = (void *)GetProcAddress(library, "CancelIoEx");
	pextCancelIoEx = (void *)GetProcAddress(library_kernelbase, "CancelIoEx");
	pCancelSynchronousIo = (void *)GetProcAddress(library, "CancelSynchronousIo");
	pextCancelSynchronousIo = (void *)GetProcAddress(library_kernelbase, "CancelSynchronousIo");
	pCancelTimerQueueTimer = (void *)GetProcAddress(library, "CancelTimerQueueTimer");
	pCancelWaitableTimer = (void *)GetProcAddress(library, "CancelWaitableTimer");
	pextCancelWaitableTimer = (void *)GetProcAddress(library_kernelbase, "CancelWaitableTimer");
	pChangeTimerQueueTimer = (void *)GetProcAddress(library, "ChangeTimerQueueTimer");
	pextChangeTimerQueueTimer = (void *)GetProcAddress(library_kernelbase, "ChangeTimerQueueTimer");
	pCheckNameLegalDOS8Dot3A = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3A");
	pCheckNameLegalDOS8Dot3W = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3W");
	pCheckRemoteDebuggerPresent = (void *)GetProcAddress(library, "CheckRemoteDebuggerPresent");
	pextCheckRemoteDebuggerPresent = (void *)GetProcAddress(library_kernelbase, "CheckRemoteDebuggerPresent");
	pClearCommBreak = (void *)GetProcAddress(library, "ClearCommBreak");
	pextClearCommBreak = (void *)GetProcAddress(library_kernelbase, "ClearCommBreak");
	pClearCommError = (void *)GetProcAddress(library, "ClearCommError");
	pextClearCommError = (void *)GetProcAddress(library_kernelbase, "ClearCommError");
	pCloseConsoleHandle = (void *)GetProcAddress(library, "CloseConsoleHandle");
	pCloseHandle = (void *)GetProcAddress(library, "CloseHandle");
	pCloseProfileUserMapping = (void *)GetProcAddress(library, "CloseProfileUserMapping");
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
	pCmdBatNotification = (void *)GetProcAddress(library, "CmdBatNotification");
	pCommConfigDialogA = (void *)GetProcAddress(library, "CommConfigDialogA");
	pCommConfigDialogW = (void *)GetProcAddress(library, "CommConfigDialogW");
	pCompareFileTime = (void *)GetProcAddress(library, "CompareFileTime");
	pCompareStringA = (void *)GetProcAddress(library, "CompareStringA");
	pCompareStringW = (void *)GetProcAddress(library, "CompareStringW");
	pCompareStringEx = (void *)GetProcAddress(library, "CompareStringEx");
	pCompareStringOrdinal = (void *)GetProcAddress(library, "CompareStringOrdinal");
	pConnectNamedPipe = (void *)GetProcAddress(library, "ConnectNamedPipe");
	pextConnectNamedPipe = (void *)GetProcAddress(library_kernelbase, "ConnectNamedPipe");
	pContinueDebugEvent = (void *)GetProcAddress(library, "ContinueDebugEvent");
	pextContinueDebugEvent = (void *)GetProcAddress(library_kernelbase, "ContinueDebugEvent");
	pConvertDefaultLocale = (void *)GetProcAddress(library, "ConvertDefaultLocale");
	pConvertFiberToThread = (void *)GetProcAddress(library, "ConvertFiberToThread");
	pextConvertFiberToThread = (void *)GetProcAddress(library_kernelbase, "ConvertFiberToThread");
	pConvertThreadToFiber = (void *)GetProcAddress(library, "ConvertThreadToFiber");
	pextConvertThreadToFiber = (void *)GetProcAddress(library_kernelbase, "ConvertThreadToFiber");
	pConvertThreadToFiberEx = (void *)GetProcAddress(library, "ConvertThreadToFiberEx");
	pextConvertThreadToFiberEx = (void *)GetProcAddress(library_kernelbase, "ConvertThreadToFiberEx");
	pConvertToGlobalHandle = (void *)GetProcAddress(library, "ConvertToGlobalHandle");
	pCopyFileA = (void *)GetProcAddress(library, "CopyFileA");
	pCopyFileExA = (void *)GetProcAddress(library, "CopyFileExA");
	pCopyFileExW = (void *)GetProcAddress(library, "CopyFileExW");
	pCopyFileW = (void *)GetProcAddress(library, "CopyFileW");
	pCreateActCtxA = (void *)GetProcAddress(library, "CreateActCtxA");
	pCreateActCtxW = (void *)GetProcAddress(library, "CreateActCtxW");
	pextCreateActCtxW = (void *)GetProcAddress(library_kernelbase, "CreateActCtxW");
	pCreateConsoleScreenBuffer = (void *)GetProcAddress(library, "CreateConsoleScreenBuffer");
	pextCreateConsoleScreenBuffer = (void *)GetProcAddress(library_kernelbase, "CreateConsoleScreenBuffer");
	pCreateDirectoryA = (void *)GetProcAddress(library, "CreateDirectoryA");
	pextCreateDirectoryA = (void *)GetProcAddress(library_kernelbase, "CreateDirectoryA");
	pCreateDirectoryExA = (void *)GetProcAddress(library, "CreateDirectoryExA");
	pCreateDirectoryExW = (void *)GetProcAddress(library, "CreateDirectoryExW");
	pextCreateDirectoryExW = (void *)GetProcAddress(library_kernelbase, "CreateDirectoryExW");
	pCreateDirectoryW = (void *)GetProcAddress(library, "CreateDirectoryW");
	pextCreateDirectoryW = (void *)GetProcAddress(library_kernelbase, "CreateDirectoryW");
	pCreateEventA = (void *)GetProcAddress(library, "CreateEventA");
	pextCreateEventA = (void *)GetProcAddress(library_kernelbase, "CreateEventA");
	pCreateEventExA = (void *)GetProcAddress(library, "CreateEventExA");
	pextCreateEventExA = (void *)GetProcAddress(library_kernelbase, "CreateEventExA");
	pCreateEventExW = (void *)GetProcAddress(library, "CreateEventExW");
	pextCreateEventExW = (void *)GetProcAddress(library_kernelbase, "CreateEventExW");
	pCreateEventW = (void *)GetProcAddress(library, "CreateEventW");
	pextCreateEventW = (void *)GetProcAddress(library_kernelbase, "CreateEventW");
	pCreateFiber = (void *)GetProcAddress(library, "CreateFiber");
	pextCreateFiber = (void *)GetProcAddress(library_kernelbase, "CreateFiber");
	pCreateFiberEx = (void *)GetProcAddress(library, "CreateFiberEx");
	pextCreateFiberEx = (void *)GetProcAddress(library_kernelbase, "CreateFiberEx");
	pCreateFile2 = (void *)GetProcAddress(library, "CreateFile2");
	pextCreateFile2 = (void *)GetProcAddress(library_kernelbase, "CreateFile2");
	pCreateFileA = (void *)GetProcAddress(library, "CreateFileA");
	pextCreateFileA = (void *)GetProcAddress(library_kernelbase, "CreateFileA");
	pCreateFileMappingA = (void *)GetProcAddress(library, "CreateFileMappingA");
	pCreateFileMappingW = (void *)GetProcAddress(library, "CreateFileMappingW");
	pextCreateFileMappingW = (void *)GetProcAddress(library_kernelbase, "CreateFileMappingW");
	pCreateFileW = (void *)GetProcAddress(library, "CreateFileW");
	pextCreateFileW = (void *)GetProcAddress(library_kernelbase, "CreateFileW");
	pCreateHardLinkA = (void *)GetProcAddress(library, "CreateHardLinkA");
	pCreateHardLinkTransactedA = (void *)GetProcAddress(library, "CreateHardLinkTransactedA");
	pCreateHardLinkTransactedW = (void *)GetProcAddress(library, "CreateHardLinkTransactedW");
	pCreateHardLinkW = (void *)GetProcAddress(library, "CreateHardLinkW");
	pCreateIoCompletionPort = (void *)GetProcAddress(library, "CreateIoCompletionPort");
	pextCreateIoCompletionPort = (void *)GetProcAddress(library_kernelbase, "CreateIoCompletionPort");
	pCreateJobObjectA = (void *)GetProcAddress(library, "CreateJobObjectA");
	pCreateJobObjectW = (void *)GetProcAddress(library, "CreateJobObjectW");
	pCreateMailslotA = (void *)GetProcAddress(library, "CreateMailslotA");
	pCreateMailslotW = (void *)GetProcAddress(library, "CreateMailslotW");
	pCreateMemoryResourceNotification = (void *)GetProcAddress(library, "CreateMemoryResourceNotification");
	pextCreateMemoryResourceNotification = (void *)GetProcAddress(library_kernelbase, "CreateMemoryResourceNotification");
	pCreateMutexA = (void *)GetProcAddress(library, "CreateMutexA");
	pextCreateMutexA = (void *)GetProcAddress(library_kernelbase, "CreateMutexA");
	pCreateMutexExA = (void *)GetProcAddress(library, "CreateMutexExA");
	pextCreateMutexExA = (void *)GetProcAddress(library_kernelbase, "CreateMutexExA");
	pCreateMutexExW = (void *)GetProcAddress(library, "CreateMutexExW");
	pextCreateMutexExW = (void *)GetProcAddress(library_kernelbase, "CreateMutexExW");
	pCreateMutexW = (void *)GetProcAddress(library, "CreateMutexW");
	pextCreateMutexW = (void *)GetProcAddress(library_kernelbase, "CreateMutexW");
	pCreateNamedPipeA = (void *)GetProcAddress(library, "CreateNamedPipeA");
	pCreateNamedPipeW = (void *)GetProcAddress(library, "CreateNamedPipeW");
	pextCreateNamedPipeW = (void *)GetProcAddress(library_kernelbase, "CreateNamedPipeW");
	pCreatePipe = (void *)GetProcAddress(library, "CreatePipe");
	pCreateProcessA = (void *)GetProcAddress(library, "CreateProcessA");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pCreateProcessInternalA = (void *)GetProcAddress(library, "CreateProcessInternalA");
	pCreateProcessInternalW = (void *)GetProcAddress(library, "CreateProcessInternalW");
	pCreateProcessW = (void *)GetProcAddress(library, "CreateProcessW");
	pCreateRemoteThread = (void *)GetProcAddress(library, "CreateRemoteThread");
	pextCreateRemoteThread = (void *)GetProcAddress(library_kernelbase, "CreateRemoteThread");
	pCreateRemoteThreadEx = (void *)GetProcAddress(library, "CreateRemoteThreadEx");
	pextCreateRemoteThreadEx = (void *)GetProcAddress(library_kernelbase, "CreateRemoteThreadEx");
	pCreateSemaphoreA = (void *)GetProcAddress(library, "CreateSemaphoreA");
	pCreateSemaphoreExA = (void *)GetProcAddress(library, "CreateSemaphoreExA");
	pCreateSemaphoreExW = (void *)GetProcAddress(library, "CreateSemaphoreExW");
	pextCreateSemaphoreExW = (void *)GetProcAddress(library_kernelbase, "CreateSemaphoreExW");
	pCreateSemaphoreW = (void *)GetProcAddress(library, "CreateSemaphoreW");
	pextCreateSemaphoreW = (void *)GetProcAddress(library_kernelbase, "CreateSemaphoreW");
	pCreateSocketHandle = (void *)GetProcAddress(library, "CreateSocketHandle");
	pCreateSymbolicLinkA = (void *)GetProcAddress(library, "CreateSymbolicLinkA");
	pCreateSymbolicLinkW = (void *)GetProcAddress(library, "CreateSymbolicLinkW");
	pCreateTapePartition = (void *)GetProcAddress(library, "CreateTapePartition");
	pCreateThread = (void *)GetProcAddress(library, "CreateThread");
	pextCreateThread = (void *)GetProcAddress(library_kernelbase, "CreateThread");
	pCreateThreadpool = (void *)GetProcAddress(library, "CreateThreadpool");
	pextCreateThreadpool = (void *)GetProcAddress(library_kernelbase, "CreateThreadpool");
	pCreateThreadpoolCleanupGroup = (void *)GetProcAddress(library, "CreateThreadpoolCleanupGroup");
	pextCreateThreadpoolCleanupGroup = (void *)GetProcAddress(library_kernelbase, "CreateThreadpoolCleanupGroup");
	pCreateThreadpoolIo = (void *)GetProcAddress(library, "CreateThreadpoolIo");
	pextCreateThreadpoolIo = (void *)GetProcAddress(library_kernelbase, "CreateThreadpoolIo");
	pCreateThreadpoolTimer = (void *)GetProcAddress(library, "CreateThreadpoolTimer");
	pextCreateThreadpoolTimer = (void *)GetProcAddress(library_kernelbase, "CreateThreadpoolTimer");
	pCreateThreadpoolWait = (void *)GetProcAddress(library, "CreateThreadpoolWait");
	pextCreateThreadpoolWait = (void *)GetProcAddress(library_kernelbase, "CreateThreadpoolWait");
	pCreateThreadpoolWork = (void *)GetProcAddress(library, "CreateThreadpoolWork");
	pextCreateThreadpoolWork = (void *)GetProcAddress(library_kernelbase, "CreateThreadpoolWork");
	pCreateTimerQueue = (void *)GetProcAddress(library, "CreateTimerQueue");
	pextCreateTimerQueue = (void *)GetProcAddress(library_kernelbase, "CreateTimerQueue");
	pCreateTimerQueueTimer = (void *)GetProcAddress(library, "CreateTimerQueueTimer");
	pextCreateTimerQueueTimer = (void *)GetProcAddress(library_kernelbase, "CreateTimerQueueTimer");
	pCreateToolhelp32Snapshot = (void *)GetProcAddress(library, "CreateToolhelp32Snapshot");
	pCreateUmsCompletionList = (void *)GetProcAddress(library, "CreateUmsCompletionList");
	pCreateUmsThreadContext = (void *)GetProcAddress(library, "CreateUmsThreadContext");
	pCreateWaitableTimerA = (void *)GetProcAddress(library, "CreateWaitableTimerA");
	pCreateWaitableTimerExA = (void *)GetProcAddress(library, "CreateWaitableTimerExA");
	pCreateWaitableTimerExW = (void *)GetProcAddress(library, "CreateWaitableTimerExW");
	pextCreateWaitableTimerExW = (void *)GetProcAddress(library_kernelbase, "CreateWaitableTimerExW");
	pCreateWaitableTimerW = (void *)GetProcAddress(library, "CreateWaitableTimerW");
	pextCreateWaitableTimerW = (void *)GetProcAddress(library_kernelbase, "CreateWaitableTimerW");
	pDeactivateActCtx = (void *)GetProcAddress(library, "DeactivateActCtx");
	pextDeactivateActCtx = (void *)GetProcAddress(library_kernelbase, "DeactivateActCtx");
	pDebugActiveProcess = (void *)GetProcAddress(library, "DebugActiveProcess");
	pextDebugActiveProcess = (void *)GetProcAddress(library_kernelbase, "DebugActiveProcess");
	pDebugActiveProcessStop = (void *)GetProcAddress(library, "DebugActiveProcessStop");
	pextDebugActiveProcessStop = (void *)GetProcAddress(library_kernelbase, "DebugActiveProcessStop");
	pDebugBreakProcess = (void *)GetProcAddress(library, "DebugBreakProcess");
	pDebugSetProcessKillOnExit = (void *)GetProcAddress(library, "DebugSetProcessKillOnExit");
	pDecodePointer = (void *)GetProcAddress(library, "DecodePointer");
	pextDecodePointer = (void *)GetProcAddress(library_ntdll, "RtlDecodePointer");
	pDecodeSystemPointer = (void *)GetProcAddress(library, "DecodeSystemPointer");
	pextDecodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlDecodeSystemPointer");
	pDefineDosDeviceA = (void *)GetProcAddress(library, "DefineDosDeviceA");
	pDefineDosDeviceW = (void *)GetProcAddress(library, "DefineDosDeviceW");
	pDelayLoadFailureHook = (void *)GetProcAddress(library, "DelayLoadFailureHook");
	pDeleteAtom = (void *)GetProcAddress(library, "DeleteAtom");
	pDeleteCriticalSection = (void *)GetProcAddress(library, "DeleteCriticalSection");
	pextDeleteCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlDeleteCriticalSection");
	pDeleteFiber = (void *)GetProcAddress(library, "DeleteFiber");
	pextDeleteFiber = (void *)GetProcAddress(library_kernelbase, "DeleteFiber");
	pDeleteFileA = (void *)GetProcAddress(library, "DeleteFileA");
	pextDeleteFileA = (void *)GetProcAddress(library_kernelbase, "DeleteFileA");
	pDeleteFileW = (void *)GetProcAddress(library, "DeleteFileW");
	pextDeleteFileW = (void *)GetProcAddress(library_kernelbase, "DeleteFileW");
	pDeleteProcThreadAttributeList = (void *)GetProcAddress(library, "DeleteProcThreadAttributeList");
	pextDeleteProcThreadAttributeList = (void *)GetProcAddress(library_kernelbase, "DeleteProcThreadAttributeList");
	pDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library, "DisassociateCurrentThreadFromCallback");
	pextDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library_ntdll, "TpDisassociateCallback");
	pDeleteTimerQueue = (void *)GetProcAddress(library, "DeleteTimerQueue");
	pDeleteTimerQueueEx = (void *)GetProcAddress(library, "DeleteTimerQueueEx");
	pextDeleteTimerQueueEx = (void *)GetProcAddress(library_kernelbase, "DeleteTimerQueueEx");
	pDeleteTimerQueueTimer = (void *)GetProcAddress(library, "DeleteTimerQueueTimer");
	pextDeleteTimerQueueTimer = (void *)GetProcAddress(library_kernelbase, "DeleteTimerQueueTimer");
	pDeleteUmsCompletionList = (void *)GetProcAddress(library, "DeleteUmsCompletionList");
	pDeleteUmsThreadContext = (void *)GetProcAddress(library, "DeleteUmsThreadContext");
	pDeleteVolumeMountPointA = (void *)GetProcAddress(library, "DeleteVolumeMountPointA");
	pDeleteVolumeMountPointW = (void *)GetProcAddress(library, "DeleteVolumeMountPointW");
	pDequeueUmsCompletionListItems = (void *)GetProcAddress(library, "DequeueUmsCompletionListItems");
	pDeviceIoControl = (void *)GetProcAddress(library, "DeviceIoControl");
	pDisableThreadLibraryCalls = (void *)GetProcAddress(library, "DisableThreadLibraryCalls");
	pextDisableThreadLibraryCalls = (void *)GetProcAddress(library_kernelbase, "DisableThreadLibraryCalls");
	pDisconnectNamedPipe = (void *)GetProcAddress(library, "DisconnectNamedPipe");
	pextDisconnectNamedPipe = (void *)GetProcAddress(library_kernelbase, "DisconnectNamedPipe");
	pDnsHostnameToComputerNameA = (void *)GetProcAddress(library, "DnsHostnameToComputerNameA");
	pDnsHostnameToComputerNameW = (void *)GetProcAddress(library, "DnsHostnameToComputerNameW");
	pDosDateTimeToFileTime = (void *)GetProcAddress(library, "DosDateTimeToFileTime");
	pDuplicateConsoleHandle = (void *)GetProcAddress(library, "DuplicateConsoleHandle");
	pDuplicateHandle = (void *)GetProcAddress(library, "DuplicateHandle");
	pEncodePointer = (void *)GetProcAddress(library, "EncodePointer");
	pextEncodePointer = (void *)GetProcAddress(library_ntdll, "RtlEncodePointer");
	pEncodeSystemPointer = (void *)GetProcAddress(library, "EncodeSystemPointer");
	pextEncodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlEncodeSystemPointer");
	pEndUpdateResourceA = (void *)GetProcAddress(library, "EndUpdateResourceA");
	pEndUpdateResourceW = (void *)GetProcAddress(library, "EndUpdateResourceW");
	pEnterCriticalSection = (void *)GetProcAddress(library, "EnterCriticalSection");
	pextEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlEnterCriticalSection");
	pEnumCalendarInfoA = (void *)GetProcAddress(library, "EnumCalendarInfoA");
	pEnumCalendarInfoExA = (void *)GetProcAddress(library, "EnumCalendarInfoExA");
	pEnumCalendarInfoExEx = (void *)GetProcAddress(library, "EnumCalendarInfoExEx");
	pEnumCalendarInfoExW = (void *)GetProcAddress(library, "EnumCalendarInfoExW");
	pEnumCalendarInfoW = (void *)GetProcAddress(library, "EnumCalendarInfoW");
	pEnumDateFormatsA = (void *)GetProcAddress(library, "EnumDateFormatsA");
	pEnumDateFormatsExA = (void *)GetProcAddress(library, "EnumDateFormatsExA");
	pEnumDateFormatsExEx = (void *)GetProcAddress(library, "EnumDateFormatsExEx");
	pEnumDateFormatsExW = (void *)GetProcAddress(library, "EnumDateFormatsExW");
	pEnumDateFormatsW = (void *)GetProcAddress(library, "EnumDateFormatsW");
	pEnumLanguageGroupLocalesA = (void *)GetProcAddress(library, "EnumLanguageGroupLocalesA");
	pEnumLanguageGroupLocalesW = (void *)GetProcAddress(library, "EnumLanguageGroupLocalesW");
	pEnumResourceLanguagesA = (void *)GetProcAddress(library, "EnumResourceLanguagesA");
	pEnumResourceLanguagesExA = (void *)GetProcAddress(library, "EnumResourceLanguagesExA");
	pextEnumResourceLanguagesExA = (void *)GetProcAddress(library_kernelbase, "EnumResourceLanguagesExA");
	pEnumResourceLanguagesExW = (void *)GetProcAddress(library, "EnumResourceLanguagesExW");
	pextEnumResourceLanguagesExW = (void *)GetProcAddress(library_kernelbase, "EnumResourceLanguagesExW");
	pEnumResourceLanguagesW = (void *)GetProcAddress(library, "EnumResourceLanguagesW");
	pEnumResourceNamesA = (void *)GetProcAddress(library, "EnumResourceNamesA");
	pEnumResourceNamesExA = (void *)GetProcAddress(library, "EnumResourceNamesExA");
	pextEnumResourceNamesExA = (void *)GetProcAddress(library_kernelbase, "EnumResourceNamesExA");
	pEnumResourceNamesExW = (void *)GetProcAddress(library, "EnumResourceNamesExW");
	pextEnumResourceNamesExW = (void *)GetProcAddress(library_kernelbase, "EnumResourceNamesExW");
	pEnumResourceNamesW = (void *)GetProcAddress(library, "EnumResourceNamesW");
	pextEnumResourceNamesW = (void *)GetProcAddress(library_kernelbase, "EnumResourceNamesW");
	pEnumResourceTypesA = (void *)GetProcAddress(library, "EnumResourceTypesA");
	pEnumResourceTypesExA = (void *)GetProcAddress(library, "EnumResourceTypesExA");
	pextEnumResourceTypesExA = (void *)GetProcAddress(library_kernelbase, "EnumResourceTypesExA");
	pEnumResourceTypesExW = (void *)GetProcAddress(library, "EnumResourceTypesExW");
	pextEnumResourceTypesExW = (void *)GetProcAddress(library_kernelbase, "EnumResourceTypesExW");
	pEnumResourceTypesW = (void *)GetProcAddress(library, "EnumResourceTypesW");
	pEnumSystemCodePagesA = (void *)GetProcAddress(library, "EnumSystemCodePagesA");
	pEnumSystemCodePagesW = (void *)GetProcAddress(library, "EnumSystemCodePagesW");
	pEnumSystemFirmwareTables = (void *)GetProcAddress(library, "EnumSystemFirmwareTables");
	pEnumSystemGeoID = (void *)GetProcAddress(library, "EnumSystemGeoID");
	pEnumSystemLanguageGroupsA = (void *)GetProcAddress(library, "EnumSystemLanguageGroupsA");
	pEnumSystemLanguageGroupsW = (void *)GetProcAddress(library, "EnumSystemLanguageGroupsW");
	pEnumSystemLocalesA = (void *)GetProcAddress(library, "EnumSystemLocalesA");
	pEnumSystemLocalesEx = (void *)GetProcAddress(library, "EnumSystemLocalesEx");
	pEnumSystemLocalesW = (void *)GetProcAddress(library, "EnumSystemLocalesW");
	pEnumTimeFormatsA = (void *)GetProcAddress(library, "EnumTimeFormatsA");
	pEnumTimeFormatsEx = (void *)GetProcAddress(library, "EnumTimeFormatsEx");
	pEnumTimeFormatsW = (void *)GetProcAddress(library, "EnumTimeFormatsW");
	pEnumUILanguagesA = (void *)GetProcAddress(library, "EnumUILanguagesA");
	pEnumUILanguagesW = (void *)GetProcAddress(library, "EnumUILanguagesW");
	pEnterUmsSchedulingMode = (void *)GetProcAddress(library, "EnterUmsSchedulingMode");
	pEraseTape = (void *)GetProcAddress(library, "EraseTape");
	pEscapeCommFunction = (void *)GetProcAddress(library, "EscapeCommFunction");
	pextEscapeCommFunction = (void *)GetProcAddress(library_kernelbase, "EscapeCommFunction");
	pExecuteUmsThread = (void *)GetProcAddress(library, "ExecuteUmsThread");
	pExitProcess = (void *)GetProcAddress(library, "ExitProcess");
	pExitThread = (void *)GetProcAddress(library, "ExitThread");
	pextExitThread = (void *)GetProcAddress(library_ntdll, "RtlExitUserThread");
	pExpandEnvironmentStringsA = (void *)GetProcAddress(library, "ExpandEnvironmentStringsA");
	pextExpandEnvironmentStringsA = (void *)GetProcAddress(library_kernelbase, "ExpandEnvironmentStringsA");
	pExpandEnvironmentStringsW = (void *)GetProcAddress(library, "ExpandEnvironmentStringsW");
	pextExpandEnvironmentStringsW = (void *)GetProcAddress(library_kernelbase, "ExpandEnvironmentStringsW");
	pExpungeConsoleCommandHistoryA = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryA");
	pExpungeConsoleCommandHistoryW = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryW");
	pFatalAppExitA = (void *)GetProcAddress(library, "FatalAppExitA");
	pextFatalAppExitA = (void *)GetProcAddress(library_kernelbase, "FatalAppExitA");
	pFatalAppExitW = (void *)GetProcAddress(library, "FatalAppExitW");
	pextFatalAppExitW = (void *)GetProcAddress(library_kernelbase, "FatalAppExitW");
	pFatalExit = (void *)GetProcAddress(library, "FatalExit");
	pFileTimeToDosDateTime = (void *)GetProcAddress(library, "FileTimeToDosDateTime");
	pFileTimeToLocalFileTime = (void *)GetProcAddress(library, "FileTimeToLocalFileTime");
	pFileTimeToSystemTime = (void *)GetProcAddress(library, "FileTimeToSystemTime");
	pFillConsoleOutputAttribute = (void *)GetProcAddress(library, "FillConsoleOutputAttribute");
	pextFillConsoleOutputAttribute = (void *)GetProcAddress(library_kernelbase, "FillConsoleOutputAttribute");
	pFillConsoleOutputCharacterA = (void *)GetProcAddress(library, "FillConsoleOutputCharacterA");
	pextFillConsoleOutputCharacterA = (void *)GetProcAddress(library_kernelbase, "FillConsoleOutputCharacterA");
	pFillConsoleOutputCharacterW = (void *)GetProcAddress(library, "FillConsoleOutputCharacterW");
	pextFillConsoleOutputCharacterW = (void *)GetProcAddress(library_kernelbase, "FillConsoleOutputCharacterW");
	pFindActCtxSectionGuid = (void *)GetProcAddress(library, "FindActCtxSectionGuid");
	pextFindActCtxSectionGuid = (void *)GetProcAddress(library_kernelbase, "FindActCtxSectionGuid");
	pFindActCtxSectionStringA = (void *)GetProcAddress(library, "FindActCtxSectionStringA");
	pFindActCtxSectionStringW = (void *)GetProcAddress(library, "FindActCtxSectionStringW");
	pextFindActCtxSectionStringW = (void *)GetProcAddress(library_kernelbase, "FindActCtxSectionStringW");
	pFindAtomA = (void *)GetProcAddress(library, "FindAtomA");
	pFindAtomW = (void *)GetProcAddress(library, "FindAtomW");
	pFindClose = (void *)GetProcAddress(library, "FindClose");
	pFindCloseChangeNotification = (void *)GetProcAddress(library, "FindCloseChangeNotification");
	pextFindCloseChangeNotification = (void *)GetProcAddress(library_kernelbase, "FindCloseChangeNotification");
	pFindFirstChangeNotificationA = (void *)GetProcAddress(library, "FindFirstChangeNotificationA");
	pextFindFirstChangeNotificationA = (void *)GetProcAddress(library_kernelbase, "FindFirstChangeNotificationA");
	pFindFirstChangeNotificationW = (void *)GetProcAddress(library, "FindFirstChangeNotificationW");
	pextFindFirstChangeNotificationW = (void *)GetProcAddress(library_kernelbase, "FindFirstChangeNotificationW");
	pFindFirstFileA = (void *)GetProcAddress(library, "FindFirstFileA");
	pFindFirstFileExA = (void *)GetProcAddress(library, "FindFirstFileExA");
	pFindFirstFileExW = (void *)GetProcAddress(library, "FindFirstFileExW");
	pFindFirstFileW = (void *)GetProcAddress(library, "FindFirstFileW");
	pFindFirstStreamW = (void *)GetProcAddress(library, "FindFirstStreamW");
	pFindFirstVolumeA = (void *)GetProcAddress(library, "FindFirstVolumeA");
	pFindFirstVolumeMountPointA = (void *)GetProcAddress(library, "FindFirstVolumeMountPointA");
	pFindFirstVolumeMountPointW = (void *)GetProcAddress(library, "FindFirstVolumeMountPointW");
	pFindFirstVolumeW = (void *)GetProcAddress(library, "FindFirstVolumeW");
	pFindNextChangeNotification = (void *)GetProcAddress(library, "FindNextChangeNotification");
	pextFindNextChangeNotification = (void *)GetProcAddress(library_kernelbase, "FindNextChangeNotification");
	pFindNextFileA = (void *)GetProcAddress(library, "FindNextFileA");
	pFindNextFileW = (void *)GetProcAddress(library, "FindNextFileW");
	pFindNextStreamW = (void *)GetProcAddress(library, "FindNextStreamW");
	pFindNextVolumeA = (void *)GetProcAddress(library, "FindNextVolumeA");
	pFindNextVolumeW = (void *)GetProcAddress(library, "FindNextVolumeW");
	pFindNLSStringEx = (void *)GetProcAddress(library, "FindNLSStringEx");
	pFindResourceA = (void *)GetProcAddress(library, "FindResourceA");
	pFindResourceExA = (void *)GetProcAddress(library, "FindResourceExA");
	pFindResourceExW = (void *)GetProcAddress(library, "FindResourceExW");
	pextFindResourceExW = (void *)GetProcAddress(library_kernelbase, "FindResourceExW");
	pFindResourceW = (void *)GetProcAddress(library, "FindResourceW");
	pextFindResourceW = (void *)GetProcAddress(library_kernelbase, "FindResourceW");
	pFindStringOrdinal = (void *)GetProcAddress(library, "FindStringOrdinal");
	pFindVolumeClose = (void *)GetProcAddress(library, "FindVolumeClose");
	pFindVolumeMountPointClose = (void *)GetProcAddress(library, "FindVolumeMountPointClose");
	pFlsAlloc = (void *)GetProcAddress(library, "FlsAlloc");
	pextFlsAlloc = (void *)GetProcAddress(library_kernelbase, "FlsAlloc");
	pFlsFree = (void *)GetProcAddress(library, "FlsFree");
	pextFlsFree = (void *)GetProcAddress(library_kernelbase, "FlsFree");
	pFlsGetValue = (void *)GetProcAddress(library, "FlsGetValue");
	pextFlsGetValue = (void *)GetProcAddress(library_kernelbase, "FlsGetValue");
	pFlsSetValue = (void *)GetProcAddress(library, "FlsSetValue");
	pextFlsSetValue = (void *)GetProcAddress(library_kernelbase, "FlsSetValue");
	pFlushConsoleInputBuffer = (void *)GetProcAddress(library, "FlushConsoleInputBuffer");
	pFlushFileBuffers = (void *)GetProcAddress(library, "FlushFileBuffers");
	pextFlushFileBuffers = (void *)GetProcAddress(library_kernelbase, "FlushFileBuffers");
	pFlushInstructionCache = (void *)GetProcAddress(library, "FlushInstructionCache");
	pextFlushInstructionCache = (void *)GetProcAddress(library_kernelbase, "FlushInstructionCache");
	pFlushProcessWriteBuffers = (void *)GetProcAddress(library, "FlushProcessWriteBuffers");
	pFlushViewOfFile = (void *)GetProcAddress(library, "FlushViewOfFile");
	pextFlushViewOfFile = (void *)GetProcAddress(library_kernelbase, "FlushViewOfFile");
	pFoldStringA = (void *)GetProcAddress(library, "FoldStringA");
	pFoldStringW = (void *)GetProcAddress(library, "FoldStringW");
	pFormatMessageA = (void *)GetProcAddress(library, "FormatMessageA");
	pFormatMessageW = (void *)GetProcAddress(library, "FormatMessageW");
	pFreeConsole = (void *)GetProcAddress(library, "FreeConsole");
	pFreeEnvironmentStringsA = (void *)GetProcAddress(library, "FreeEnvironmentStringsA");
	pextFreeEnvironmentStringsA = (void *)GetProcAddress(library_kernelbase, "FreeEnvironmentStringsA");
	pFreeEnvironmentStringsW = (void *)GetProcAddress(library, "FreeEnvironmentStringsW");
	pextFreeEnvironmentStringsW = (void *)GetProcAddress(library_kernelbase, "FreeEnvironmentStringsW");
	pFreeLibrary = (void *)GetProcAddress(library, "FreeLibrary");
	pFreeLibraryAndExitThread = (void *)GetProcAddress(library, "FreeLibraryAndExitThread");
	pFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library, "FreeLibraryWhenCallbackReturns");
	pextFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackUnloadDllOnCompletion");
	pFreeResource = (void *)GetProcAddress(library, "FreeResource");
	pextFreeResource = (void *)GetProcAddress(library_kernelbase, "FreeResource");
	pFreeUserPhysicalPages = (void *)GetProcAddress(library, "FreeUserPhysicalPages");
	pGenerateConsoleCtrlEvent = (void *)GetProcAddress(library, "GenerateConsoleCtrlEvent");
	pextGenerateConsoleCtrlEvent = (void *)GetProcAddress(library_kernelbase, "GenerateConsoleCtrlEvent");
	pGetACP = (void *)GetProcAddress(library, "GetACP");
	pGetActiveProcessorCount = (void *)GetProcAddress(library, "GetActiveProcessorCount");
	pGetActiveProcessorGroupCount = (void *)GetProcAddress(library, "GetActiveProcessorGroupCount");
	pGetApplicationRestartSettings = (void *)GetProcAddress(library, "GetApplicationRestartSettings");
	pGetAtomNameA = (void *)GetProcAddress(library, "GetAtomNameA");
	pGetAtomNameW = (void *)GetProcAddress(library, "GetAtomNameW");
	pGetBinaryTypeA = (void *)GetProcAddress(library, "GetBinaryTypeA");
	pGetBinaryTypeW = (void *)GetProcAddress(library, "GetBinaryTypeW");
	pGetCPInfo = (void *)GetProcAddress(library, "GetCPInfo");
	pGetCPInfoExA = (void *)GetProcAddress(library, "GetCPInfoExA");
	pGetCPInfoExW = (void *)GetProcAddress(library, "GetCPInfoExW");
	pGetCalendarInfoA = (void *)GetProcAddress(library, "GetCalendarInfoA");
	pGetCalendarInfoW = (void *)GetProcAddress(library, "GetCalendarInfoW");
	pGetCalendarInfoEx = (void *)GetProcAddress(library, "GetCalendarInfoEx");
	pGetCommConfig = (void *)GetProcAddress(library, "GetCommConfig");
	pextGetCommConfig = (void *)GetProcAddress(library_kernelbase, "GetCommConfig");
	pGetCommMask = (void *)GetProcAddress(library, "GetCommMask");
	pextGetCommMask = (void *)GetProcAddress(library_kernelbase, "GetCommMask");
	pGetCommModemStatus = (void *)GetProcAddress(library, "GetCommModemStatus");
	pextGetCommModemStatus = (void *)GetProcAddress(library_kernelbase, "GetCommModemStatus");
	pGetCommProperties = (void *)GetProcAddress(library, "GetCommProperties");
	pextGetCommProperties = (void *)GetProcAddress(library_kernelbase, "GetCommProperties");
	pGetCommState = (void *)GetProcAddress(library, "GetCommState");
	pextGetCommState = (void *)GetProcAddress(library_kernelbase, "GetCommState");
	pGetCommTimeouts = (void *)GetProcAddress(library, "GetCommTimeouts");
	pextGetCommTimeouts = (void *)GetProcAddress(library_kernelbase, "GetCommTimeouts");
	pGetCommandLineA = (void *)GetProcAddress(library, "GetCommandLineA");
	pextGetCommandLineA = (void *)GetProcAddress(library_kernelbase, "GetCommandLineA");
	pGetCommandLineW = (void *)GetProcAddress(library, "GetCommandLineW");
	pextGetCommandLineW = (void *)GetProcAddress(library_kernelbase, "GetCommandLineW");
	pGetCompressedFileSizeA = (void *)GetProcAddress(library, "GetCompressedFileSizeA");
	pextGetCompressedFileSizeA = (void *)GetProcAddress(library_kernelbase, "GetCompressedFileSizeA");
	pGetCompressedFileSizeW = (void *)GetProcAddress(library, "GetCompressedFileSizeW");
	pextGetCompressedFileSizeW = (void *)GetProcAddress(library_kernelbase, "GetCompressedFileSizeW");
	pGetComputerNameA = (void *)GetProcAddress(library, "GetComputerNameA");
	pGetComputerNameExA = (void *)GetProcAddress(library, "GetComputerNameExA");
	pGetComputerNameExW = (void *)GetProcAddress(library, "GetComputerNameExW");
	pGetComputerNameW = (void *)GetProcAddress(library, "GetComputerNameW");
	pGetConsoleAliasExesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthA");
	pGetConsoleAliasExesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthW");
	pGetConsoleAliasW = (void *)GetProcAddress(library, "GetConsoleAliasW");
	pGetConsoleAliasesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasesLengthA");
	pGetConsoleAliasesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasesLengthW");
	pGetConsoleCP = (void *)GetProcAddress(library, "GetConsoleCP");
	pextGetConsoleCP = (void *)GetProcAddress(library_kernelbase, "GetConsoleCP");
	pGetConsoleCommandHistoryA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryA");
	pGetConsoleCommandHistoryLengthA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthA");
	pGetConsoleCommandHistoryLengthW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthW");
	pGetConsoleCommandHistoryW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryW");
	pGetConsoleCursorInfo = (void *)GetProcAddress(library, "GetConsoleCursorInfo");
	pextGetConsoleCursorInfo = (void *)GetProcAddress(library_kernelbase, "GetConsoleCursorInfo");
	pGetConsoleDisplayMode = (void *)GetProcAddress(library, "GetConsoleDisplayMode");
	pGetConsoleFontInfo = (void *)GetProcAddress(library, "GetConsoleFontInfo");
	pGetConsoleFontSize = (void *)GetProcAddress(library, "GetConsoleFontSize");
	pGetConsoleInputExeNameA = (void *)GetProcAddress(library, "GetConsoleInputExeNameA");
	pextGetConsoleInputExeNameA = (void *)GetProcAddress(library_kernelbase, "GetConsoleInputExeNameA");
	pGetConsoleInputExeNameW = (void *)GetProcAddress(library, "GetConsoleInputExeNameW");
	pextGetConsoleInputExeNameW = (void *)GetProcAddress(library_kernelbase, "GetConsoleInputExeNameW");
	pGetConsoleInputWaitHandle = (void *)GetProcAddress(library, "GetConsoleInputWaitHandle");
	pGetConsoleKeyboardLayoutNameA = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameA");
	pGetConsoleKeyboardLayoutNameW = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameW");
	pGetConsoleMode = (void *)GetProcAddress(library, "GetConsoleMode");
	pextGetConsoleMode = (void *)GetProcAddress(library_kernelbase, "GetConsoleMode");
	pGetConsoleOutputCP = (void *)GetProcAddress(library, "GetConsoleOutputCP");
	pextGetConsoleOutputCP = (void *)GetProcAddress(library_kernelbase, "GetConsoleOutputCP");
	pGetConsoleProcessList = (void *)GetProcAddress(library, "GetConsoleProcessList");
	pGetConsoleScreenBufferInfo = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfo");
	pextGetConsoleScreenBufferInfo = (void *)GetProcAddress(library_kernelbase, "GetConsoleScreenBufferInfo");
	pGetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "GetConsoleScreenBufferInfoEx");
	pextGetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library_kernelbase, "GetConsoleScreenBufferInfoEx");
	pGetConsoleTitleA = (void *)GetProcAddress(library, "GetConsoleTitleA");
	pGetConsoleTitleW = (void *)GetProcAddress(library, "GetConsoleTitleW");
	pextGetConsoleTitleW = (void *)GetProcAddress(library_kernelbase, "GetConsoleTitleW");
	pGetConsoleWindow = (void *)GetProcAddress(library, "GetConsoleWindow");
	pGetCurrencyFormatA = (void *)GetProcAddress(library, "GetCurrencyFormatA");
	pGetCurrencyFormatEx = (void *)GetProcAddress(library, "GetCurrencyFormatEx");
	pGetCurrencyFormatW = (void *)GetProcAddress(library, "GetCurrencyFormatW");
	pGetCurrentActCtx = (void *)GetProcAddress(library, "GetCurrentActCtx");
	pextGetCurrentActCtx = (void *)GetProcAddress(library_kernelbase, "GetCurrentActCtx");
	pGetCurrentConsoleFont = (void *)GetProcAddress(library, "GetCurrentConsoleFont");
	pGetCurrentDirectoryA = (void *)GetProcAddress(library, "GetCurrentDirectoryA");
	pGetCurrentDirectoryW = (void *)GetProcAddress(library, "GetCurrentDirectoryW");
	pGetCurrentPackageFamilyName = (void *)GetProcAddress(library, "GetCurrentPackageFamilyName");
	pGetCurrentPackageFullName = (void *)GetProcAddress(library, "GetCurrentPackageFullName");
	pGetCurrentPackageId = (void *)GetProcAddress(library, "GetCurrentPackageId");
	pGetCurrentProcess = (void *)GetProcAddress(library, "GetCurrentProcess");
	pGetCurrentProcessId = (void *)GetProcAddress(library, "GetCurrentProcessId");
	pGetCurrentProcessorNumber = (void *)GetProcAddress(library, "GetCurrentProcessorNumber");
	pextGetCurrentProcessorNumber = (void *)GetProcAddress(library_ntdll, "NtGetCurrentProcessorNumber");
	pGetCurrentProcessorNumberEx = (void *)GetProcAddress(library, "GetCurrentProcessorNumberEx");
	pextGetCurrentProcessorNumberEx = (void *)GetProcAddress(library_ntdll, "RtlGetCurrentProcessorNumberEx");
	pGetCurrentThread = (void *)GetProcAddress(library, "GetCurrentThread");
	pGetCurrentThreadId = (void *)GetProcAddress(library, "GetCurrentThreadId");
	pGetCurrentThreadStackLimits = (void *)GetProcAddress(library, "GetCurrentThreadStackLimits");
	pextGetCurrentThreadStackLimits = (void *)GetProcAddress(library_kernelbase, "GetCurrentThreadStackLimits");
	pGetCurrentUmsThread = (void *)GetProcAddress(library, "GetCurrentUmsThread");
	pGetDateFormatA = (void *)GetProcAddress(library, "GetDateFormatA");
	pGetDateFormatEx = (void *)GetProcAddress(library, "GetDateFormatEx");
	pGetDateFormatW = (void *)GetProcAddress(library, "GetDateFormatW");
	pGetDaylightFlag = (void *)GetProcAddress(library, "GetDaylightFlag");
	pGetDefaultCommConfigA = (void *)GetProcAddress(library, "GetDefaultCommConfigA");
	pGetDefaultCommConfigW = (void *)GetProcAddress(library, "GetDefaultCommConfigW");
	pGetDevicePowerState = (void *)GetProcAddress(library, "GetDevicePowerState");
	pGetDiskFreeSpaceA = (void *)GetProcAddress(library, "GetDiskFreeSpaceA");
	pGetDiskFreeSpaceExA = (void *)GetProcAddress(library, "GetDiskFreeSpaceExA");
	pGetDiskFreeSpaceExW = (void *)GetProcAddress(library, "GetDiskFreeSpaceExW");
	pGetDiskFreeSpaceW = (void *)GetProcAddress(library, "GetDiskFreeSpaceW");
	pGetDllDirectoryA = (void *)GetProcAddress(library, "GetDllDirectoryA");
	pGetDllDirectoryW = (void *)GetProcAddress(library, "GetDllDirectoryW");
	pGetDriveTypeA = (void *)GetProcAddress(library, "GetDriveTypeA");
	pGetDriveTypeW = (void *)GetProcAddress(library, "GetDriveTypeW");
	pGetDynamicTimeZoneInformation = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformation");
	pGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformationEffectiveYears");
	pGetEnabledXStateFeatures = (void *)GetProcAddress(library, "GetEnabledXStateFeatures");
	pGetEnvironmentStrings = (void *)GetProcAddress(library, "GetEnvironmentStrings");
	pextGetEnvironmentStrings = (void *)GetProcAddress(library_kernelbase, "GetEnvironmentStrings");
	pGetEnvironmentStringsA = (void *)GetProcAddress(library, "GetEnvironmentStringsA");
	pextGetEnvironmentStringsA = (void *)GetProcAddress(library_kernelbase, "GetEnvironmentStringsA");
	pGetEnvironmentStringsW = (void *)GetProcAddress(library, "GetEnvironmentStringsW");
	pextGetEnvironmentStringsW = (void *)GetProcAddress(library_kernelbase, "GetEnvironmentStringsW");
	pGetEnvironmentVariableA = (void *)GetProcAddress(library, "GetEnvironmentVariableA");
	pextGetEnvironmentVariableA = (void *)GetProcAddress(library_kernelbase, "GetEnvironmentVariableA");
	pGetEnvironmentVariableW = (void *)GetProcAddress(library, "GetEnvironmentVariableW");
	pextGetEnvironmentVariableW = (void *)GetProcAddress(library_kernelbase, "GetEnvironmentVariableW");
	pGetErrorMode = (void *)GetProcAddress(library, "GetErrorMode");
	pextGetErrorMode = (void *)GetProcAddress(library_kernelbase, "GetErrorMode");
	pGetExitCodeProcess = (void *)GetProcAddress(library, "GetExitCodeProcess");
	pGetExitCodeThread = (void *)GetProcAddress(library, "GetExitCodeThread");
	pextGetExitCodeThread = (void *)GetProcAddress(library_kernelbase, "GetExitCodeThread");
	pGetExpandedNameA = (void *)GetProcAddress(library, "GetExpandedNameA");
	pGetExpandedNameW = (void *)GetProcAddress(library, "GetExpandedNameW");
	pGetFileAttributesA = (void *)GetProcAddress(library, "GetFileAttributesA");
	pextGetFileAttributesA = (void *)GetProcAddress(library_kernelbase, "GetFileAttributesA");
	pGetFileAttributesExA = (void *)GetProcAddress(library, "GetFileAttributesExA");
	pextGetFileAttributesExA = (void *)GetProcAddress(library_kernelbase, "GetFileAttributesExA");
	pGetFileAttributesExW = (void *)GetProcAddress(library, "GetFileAttributesExW");
	pextGetFileAttributesExW = (void *)GetProcAddress(library_kernelbase, "GetFileAttributesExW");
	pGetFileAttributesW = (void *)GetProcAddress(library, "GetFileAttributesW");
	pextGetFileAttributesW = (void *)GetProcAddress(library_kernelbase, "GetFileAttributesW");
	pGetFileInformationByHandle = (void *)GetProcAddress(library, "GetFileInformationByHandle");
	pextGetFileInformationByHandle = (void *)GetProcAddress(library_kernelbase, "GetFileInformationByHandle");
	pGetFileInformationByHandleEx = (void *)GetProcAddress(library, "GetFileInformationByHandleEx");
	pextGetFileInformationByHandleEx = (void *)GetProcAddress(library_kernelbase, "GetFileInformationByHandleEx");
	pGetFileMUIInfo = (void *)GetProcAddress(library, "GetFileMUIInfo");
	pGetFileMUIPath = (void *)GetProcAddress(library, "GetFileMUIPath");
	pGetFileSize = (void *)GetProcAddress(library, "GetFileSize");
	pextGetFileSize = (void *)GetProcAddress(library_kernelbase, "GetFileSize");
	pGetFileSizeEx = (void *)GetProcAddress(library, "GetFileSizeEx");
	pextGetFileSizeEx = (void *)GetProcAddress(library_kernelbase, "GetFileSizeEx");
	pGetFileTime = (void *)GetProcAddress(library, "GetFileTime");
	pextGetFileTime = (void *)GetProcAddress(library_kernelbase, "GetFileTime");
	pGetFileType = (void *)GetProcAddress(library, "GetFileType");
	pextGetFileType = (void *)GetProcAddress(library_kernelbase, "GetFileType");
	pGetFinalPathNameByHandleA = (void *)GetProcAddress(library, "GetFinalPathNameByHandleA");
	pGetFinalPathNameByHandleW = (void *)GetProcAddress(library, "GetFinalPathNameByHandleW");
	pGetFirmwareEnvironmentVariableA = (void *)GetProcAddress(library, "GetFirmwareEnvironmentVariableA");
	pGetFirmwareEnvironmentVariableW = (void *)GetProcAddress(library, "GetFirmwareEnvironmentVariableW");
	pGetFullPathNameA = (void *)GetProcAddress(library, "GetFullPathNameA");
	pGetFullPathNameW = (void *)GetProcAddress(library, "GetFullPathNameW");
	pGetGeoInfoA = (void *)GetProcAddress(library, "GetGeoInfoA");
	pGetGeoInfoW = (void *)GetProcAddress(library, "GetGeoInfoW");
	pGetHandleContext = (void *)GetProcAddress(library, "GetHandleContext");
	pGetHandleInformation = (void *)GetProcAddress(library, "GetHandleInformation");
	pGetLargePageMinimum = (void *)GetProcAddress(library, "GetLargePageMinimum");
	pGetLargestConsoleWindowSize = (void *)GetProcAddress(library, "GetLargestConsoleWindowSize");
	pextGetLargestConsoleWindowSize = (void *)GetProcAddress(library_kernelbase, "GetLargestConsoleWindowSize");
	pGetLastError = (void *)GetProcAddress(library, "GetLastError");
	pextGetLastError = (void *)GetProcAddress(library_kernelbase, "GetLastError");
	pGetLocalTime = (void *)GetProcAddress(library, "GetLocalTime");
	pGetLocaleInfoA = (void *)GetProcAddress(library, "GetLocaleInfoA");
	pGetLocaleInfoW = (void *)GetProcAddress(library, "GetLocaleInfoW");
	pGetLocaleInfoEx = (void *)GetProcAddress(library, "GetLocaleInfoEx");
	pGetLogicalDriveStringsA = (void *)GetProcAddress(library, "GetLogicalDriveStringsA");
	pGetLogicalDriveStringsW = (void *)GetProcAddress(library, "GetLogicalDriveStringsW");
	pGetLogicalDrives = (void *)GetProcAddress(library, "GetLogicalDrives");
	pGetLogicalProcessorInformation = (void *)GetProcAddress(library, "GetLogicalProcessorInformation");
	pGetLogicalProcessorInformationEx = (void *)GetProcAddress(library, "GetLogicalProcessorInformationEx");
	pGetLongPathNameA = (void *)GetProcAddress(library, "GetLongPathNameA");
	pGetLongPathNameW = (void *)GetProcAddress(library, "GetLongPathNameW");
	pGetMailslotInfo = (void *)GetProcAddress(library, "GetMailslotInfo");
	pGetMaximumProcessorCount = (void *)GetProcAddress(library, "GetMaximumProcessorCount");
	pGetModuleFileNameA = (void *)GetProcAddress(library, "GetModuleFileNameA");
	pextGetModuleFileNameA = (void *)GetProcAddress(library_kernelbase, "GetModuleFileNameA");
	pGetModuleFileNameW = (void *)GetProcAddress(library, "GetModuleFileNameW");
	pextGetModuleFileNameW = (void *)GetProcAddress(library_kernelbase, "GetModuleFileNameW");
	pGetModuleHandleA = (void *)GetProcAddress(library, "GetModuleHandleA");
	pextGetModuleHandleA = (void *)GetProcAddress(library_kernelbase, "GetModuleHandleA");
	pGetModuleHandleExA = (void *)GetProcAddress(library, "GetModuleHandleExA");
	pextGetModuleHandleExA = (void *)GetProcAddress(library_kernelbase, "GetModuleHandleExA");
	pGetModuleHandleExW = (void *)GetProcAddress(library, "GetModuleHandleExW");
	pextGetModuleHandleExW = (void *)GetProcAddress(library_kernelbase, "GetModuleHandleExW");
	pGetModuleHandleW = (void *)GetProcAddress(library, "GetModuleHandleW");
	pextGetModuleHandleW = (void *)GetProcAddress(library_kernelbase, "GetModuleHandleW");
	pGetNamedPipeClientProcessId = (void *)GetProcAddress(library, "GetNamedPipeClientProcessId");
	pGetNamedPipeClientSessionId = (void *)GetProcAddress(library, "GetNamedPipeClientSessionId");
	pGetNamedPipeHandleStateA = (void *)GetProcAddress(library, "GetNamedPipeHandleStateA");
	pGetNamedPipeHandleStateW = (void *)GetProcAddress(library, "GetNamedPipeHandleStateW");
	pGetNamedPipeInfo = (void *)GetProcAddress(library, "GetNamedPipeInfo");
	pextGetNamedPipeInfo = (void *)GetProcAddress(library_kernelbase, "GetNamedPipeInfo");
	pGetNamedPipeServerProcessId = (void *)GetProcAddress(library, "GetNamedPipeServerProcessId");
	pGetNamedPipeServerSessionId = (void *)GetProcAddress(library, "GetNamedPipeServerSessionId");
	pGetNativeSystemInfo = (void *)GetProcAddress(library, "GetNativeSystemInfo");
	pGetNextUmsListItem = (void *)GetProcAddress(library, "GetNextUmsListItem");
	pGetNumaAvailableMemoryNode = (void *)GetProcAddress(library, "GetNumaAvailableMemoryNode");
	pGetNumaAvailableMemoryNodeEx = (void *)GetProcAddress(library, "GetNumaAvailableMemoryNodeEx");
	pGetNumaHighestNodeNumber = (void *)GetProcAddress(library, "GetNumaHighestNodeNumber");
	pGetNumaNodeProcessorMask = (void *)GetProcAddress(library, "GetNumaNodeProcessorMask");
	pGetNumaNodeProcessorMaskEx = (void *)GetProcAddress(library, "GetNumaNodeProcessorMaskEx");
	pGetNumaProcessorNode = (void *)GetProcAddress(library, "GetNumaProcessorNode");
	pGetNumaProcessorNodeEx = (void *)GetProcAddress(library, "GetNumaProcessorNodeEx");
	pGetNumaProximityNode = (void *)GetProcAddress(library, "GetNumaProximityNode");
	pGetNumaProximityNodeEx = (void *)GetProcAddress(library, "GetNumaProximityNodeEx");
	pGetNumberFormatA = (void *)GetProcAddress(library, "GetNumberFormatA");
	pGetNumberFormatEx = (void *)GetProcAddress(library, "GetNumberFormatEx");
	pGetNumberFormatW = (void *)GetProcAddress(library, "GetNumberFormatW");
	pGetNumberOfConsoleFonts = (void *)GetProcAddress(library, "GetNumberOfConsoleFonts");
	pGetNumberOfConsoleInputEvents = (void *)GetProcAddress(library, "GetNumberOfConsoleInputEvents");
	pextGetNumberOfConsoleInputEvents = (void *)GetProcAddress(library_kernelbase, "GetNumberOfConsoleInputEvents");
	pGetNumberOfConsoleMouseButtons = (void *)GetProcAddress(library, "GetNumberOfConsoleMouseButtons");
	pGetOEMCP = (void *)GetProcAddress(library, "GetOEMCP");
	pGetOverlappedResult = (void *)GetProcAddress(library, "GetOverlappedResult");
	pextGetOverlappedResult = (void *)GetProcAddress(library_kernelbase, "GetOverlappedResult");
	pGetUserPreferredUILanguages = (void *)GetProcAddress(library, "GetUserPreferredUILanguages");
	pGetPackageFullName = (void *)GetProcAddress(library, "GetPackageFullName");
	pGetPhysicallyInstalledSystemMemory = (void *)GetProcAddress(library, "GetPhysicallyInstalledSystemMemory");
	pGetPriorityClass = (void *)GetProcAddress(library, "GetPriorityClass");
	pextGetPriorityClass = (void *)GetProcAddress(library_kernelbase, "GetPriorityClass");
	pGetPrivateProfileIntA = (void *)GetProcAddress(library, "GetPrivateProfileIntA");
	pGetPrivateProfileIntW = (void *)GetProcAddress(library, "GetPrivateProfileIntW");
	pGetPrivateProfileSectionA = (void *)GetProcAddress(library, "GetPrivateProfileSectionA");
	pGetPrivateProfileSectionNamesA = (void *)GetProcAddress(library, "GetPrivateProfileSectionNamesA");
	pGetPrivateProfileSectionNamesW = (void *)GetProcAddress(library, "GetPrivateProfileSectionNamesW");
	pGetPrivateProfileSectionW = (void *)GetProcAddress(library, "GetPrivateProfileSectionW");
	pGetPrivateProfileStringA = (void *)GetProcAddress(library, "GetPrivateProfileStringA");
	pGetPrivateProfileStringW = (void *)GetProcAddress(library, "GetPrivateProfileStringW");
	pGetPrivateProfileStructA = (void *)GetProcAddress(library, "GetPrivateProfileStructA");
	pGetPrivateProfileStructW = (void *)GetProcAddress(library, "GetPrivateProfileStructW");
	pGetProcAddress = (void *)GetProcAddress(library, "GetProcAddress");
	pGetProcessAffinityMask = (void *)GetProcAddress(library, "GetProcessAffinityMask");
	pGetProcessDEPPolicy = (void *)GetProcAddress(library, "GetProcessDEPPolicy");
	pGetProcessFlags = (void *)GetProcAddress(library, "GetProcessFlags");
	pGetProcessHandleCount = (void *)GetProcAddress(library, "GetProcessHandleCount");
	pextGetProcessHandleCount = (void *)GetProcAddress(library_kernelbase, "GetProcessHandleCount");
	pGetProcessHeap = (void *)GetProcAddress(library, "GetProcessHeap");
	pextGetProcessHeap = (void *)GetProcAddress(library_kernelbase, "GetProcessHeap");
	pGetProcessId = (void *)GetProcAddress(library, "GetProcessId");
	pextGetProcessId = (void *)GetProcAddress(library_kernelbase, "GetProcessId");
	pGetProcessIdOfThread = (void *)GetProcAddress(library, "GetProcessIdOfThread");
	pextGetProcessIdOfThread = (void *)GetProcAddress(library_kernelbase, "GetProcessIdOfThread");
	pGetProcessIoCounters = (void *)GetProcAddress(library, "GetProcessIoCounters");
	pGetProcessMitigationPolicy = (void *)GetProcAddress(library, "GetProcessMitigationPolicy");
	pextGetProcessMitigationPolicy = (void *)GetProcAddress(library_kernelbase, "GetProcessMitigationPolicy");
	pGetProcessPreferredUILanguages = (void *)GetProcAddress(library, "GetProcessPreferredUILanguages");
	pGetProcessPriorityBoost = (void *)GetProcAddress(library, "GetProcessPriorityBoost");
	pextGetProcessPriorityBoost = (void *)GetProcAddress(library_kernelbase, "GetProcessPriorityBoost");
	pGetProcessShutdownParameters = (void *)GetProcAddress(library, "GetProcessShutdownParameters");
	pextGetProcessShutdownParameters = (void *)GetProcAddress(library_kernelbase, "GetProcessShutdownParameters");
	pGetProcessTimes = (void *)GetProcAddress(library, "GetProcessTimes");
	pGetProcessVersion = (void *)GetProcAddress(library, "GetProcessVersion");
	pGetProcessWorkingSetSize = (void *)GetProcAddress(library, "GetProcessWorkingSetSize");
	pGetProcessWorkingSetSizeEx = (void *)GetProcAddress(library, "GetProcessWorkingSetSizeEx");
	pextGetProcessWorkingSetSizeEx = (void *)GetProcAddress(library_kernelbase, "GetProcessWorkingSetSizeEx");
	pGetProductInfo = (void *)GetProcAddress(library, "GetProductInfo");
	pGetProfileIntA = (void *)GetProcAddress(library, "GetProfileIntA");
	pGetProfileIntW = (void *)GetProcAddress(library, "GetProfileIntW");
	pGetProfileSectionA = (void *)GetProcAddress(library, "GetProfileSectionA");
	pGetProfileSectionW = (void *)GetProcAddress(library, "GetProfileSectionW");
	pGetProfileStringA = (void *)GetProcAddress(library, "GetProfileStringA");
	pGetProfileStringW = (void *)GetProcAddress(library, "GetProfileStringW");
	pGetQueuedCompletionStatus = (void *)GetProcAddress(library, "GetQueuedCompletionStatus");
	pextGetQueuedCompletionStatus = (void *)GetProcAddress(library_kernelbase, "GetQueuedCompletionStatus");
	pGetQueuedCompletionStatusEx = (void *)GetProcAddress(library, "GetQueuedCompletionStatusEx");
	pextGetQueuedCompletionStatusEx = (void *)GetProcAddress(library_kernelbase, "GetQueuedCompletionStatusEx");
	pGetShortPathNameA = (void *)GetProcAddress(library, "GetShortPathNameA");
	pGetShortPathNameW = (void *)GetProcAddress(library, "GetShortPathNameW");
	pGetStartupInfoA = (void *)GetProcAddress(library, "GetStartupInfoA");
	pGetStartupInfoW = (void *)GetProcAddress(library, "GetStartupInfoW");
	pextGetStartupInfoW = (void *)GetProcAddress(library_kernelbase, "GetStartupInfoW");
	pGetStdHandle = (void *)GetProcAddress(library, "GetStdHandle");
	pextGetStdHandle = (void *)GetProcAddress(library_kernelbase, "GetStdHandle");
	pGetStringTypeA = (void *)GetProcAddress(library, "GetStringTypeA");
	pGetStringTypeExA = (void *)GetProcAddress(library, "GetStringTypeExA");
	pGetStringTypeExW = (void *)GetProcAddress(library, "GetStringTypeExW");
	pGetStringTypeW = (void *)GetProcAddress(library, "GetStringTypeW");
	pGetSystemFileCacheSize = (void *)GetProcAddress(library, "GetSystemFileCacheSize");
	pGetSystemDefaultLCID = (void *)GetProcAddress(library, "GetSystemDefaultLCID");
	pGetSystemDefaultLangID = (void *)GetProcAddress(library, "GetSystemDefaultLangID");
	pGetSystemDefaultLocaleName = (void *)GetProcAddress(library, "GetSystemDefaultLocaleName");
	pGetSystemDefaultUILanguage = (void *)GetProcAddress(library, "GetSystemDefaultUILanguage");
	pGetSystemDEPPolicy = (void *)GetProcAddress(library, "GetSystemDEPPolicy");
	pGetSystemDirectoryA = (void *)GetProcAddress(library, "GetSystemDirectoryA");
	pGetSystemDirectoryW = (void *)GetProcAddress(library, "GetSystemDirectoryW");
	pGetSystemFirmwareTable = (void *)GetProcAddress(library, "GetSystemFirmwareTable");
	pGetSystemInfo = (void *)GetProcAddress(library, "GetSystemInfo");
	pGetSystemPowerStatus = (void *)GetProcAddress(library, "GetSystemPowerStatus");
	pGetSystemPreferredUILanguages = (void *)GetProcAddress(library, "GetSystemPreferredUILanguages");
	pGetSystemRegistryQuota = (void *)GetProcAddress(library, "GetSystemRegistryQuota");
	pGetSystemTime = (void *)GetProcAddress(library, "GetSystemTime");
	pGetSystemTimeAdjustment = (void *)GetProcAddress(library, "GetSystemTimeAdjustment");
	pGetSystemTimeAsFileTime = (void *)GetProcAddress(library, "GetSystemTimeAsFileTime");
	pextGetSystemTimeAsFileTime = (void *)GetProcAddress(library_ntdll, "NtQuerySystemTime");
	pGetSystemTimePreciseAsFileTime = (void *)GetProcAddress(library, "GetSystemTimePreciseAsFileTime");
	pGetSystemTimes = (void *)GetProcAddress(library, "GetSystemTimes");
	pGetSystemWindowsDirectoryA = (void *)GetProcAddress(library, "GetSystemWindowsDirectoryA");
	pextGetSystemWindowsDirectoryA = (void *)GetProcAddress(library_kernelbase, "GetSystemWindowsDirectoryA");
	pGetSystemWindowsDirectoryW = (void *)GetProcAddress(library, "GetSystemWindowsDirectoryW");
	pextGetSystemWindowsDirectoryW = (void *)GetProcAddress(library_kernelbase, "GetSystemWindowsDirectoryW");
	pGetSystemWow64DirectoryA = (void *)GetProcAddress(library, "GetSystemWow64DirectoryA");
	pGetSystemWow64DirectoryW = (void *)GetProcAddress(library, "GetSystemWow64DirectoryW");
	pGetTapeParameters = (void *)GetProcAddress(library, "GetTapeParameters");
	pGetTapePosition = (void *)GetProcAddress(library, "GetTapePosition");
	pGetTapeStatus = (void *)GetProcAddress(library, "GetTapeStatus");
	pGetTempFileNameA = (void *)GetProcAddress(library, "GetTempFileNameA");
	pGetTempFileNameW = (void *)GetProcAddress(library, "GetTempFileNameW");
	pGetTempPathA = (void *)GetProcAddress(library, "GetTempPathA");
	pGetTempPathW = (void *)GetProcAddress(library, "GetTempPathW");
	pGetThreadContext = (void *)GetProcAddress(library, "GetThreadContext");
	pextGetThreadContext = (void *)GetProcAddress(library_kernelbase, "GetThreadContext");
	pGetThreadErrorMode = (void *)GetProcAddress(library, "GetThreadErrorMode");
	pextGetThreadErrorMode = (void *)GetProcAddress(library_kernelbase, "GetThreadErrorMode");
	pGetThreadGroupAffinity = (void *)GetProcAddress(library, "GetThreadGroupAffinity");
	pextGetThreadGroupAffinity = (void *)GetProcAddress(library_kernelbase, "GetThreadGroupAffinity");
	pGetThreadIOPendingFlag = (void *)GetProcAddress(library, "GetThreadIOPendingFlag");
	pextGetThreadIOPendingFlag = (void *)GetProcAddress(library_kernelbase, "GetThreadIOPendingFlag");
	pGetThreadId = (void *)GetProcAddress(library, "GetThreadId");
	pextGetThreadId = (void *)GetProcAddress(library_kernelbase, "GetThreadId");
	pGetThreadLocale = (void *)GetProcAddress(library, "GetThreadLocale");
	pGetThreadPreferredUILanguages = (void *)GetProcAddress(library, "GetThreadPreferredUILanguages");
	pGetThreadPriority = (void *)GetProcAddress(library, "GetThreadPriority");
	pextGetThreadPriority = (void *)GetProcAddress(library_kernelbase, "GetThreadPriority");
	pGetThreadPriorityBoost = (void *)GetProcAddress(library, "GetThreadPriorityBoost");
	pextGetThreadPriorityBoost = (void *)GetProcAddress(library_kernelbase, "GetThreadPriorityBoost");
	pGetThreadSelectorEntry = (void *)GetProcAddress(library, "GetThreadSelectorEntry");
	pGetThreadTimes = (void *)GetProcAddress(library, "GetThreadTimes");
	pextGetThreadTimes = (void *)GetProcAddress(library_kernelbase, "GetThreadTimes");
	pGetThreadUILanguage = (void *)GetProcAddress(library, "GetThreadUILanguage");
	pextGetThreadUILanguage = (void *)GetProcAddress(library_kernelbase, "GetThreadUILanguage");
	pGetTickCount = (void *)GetProcAddress(library, "GetTickCount");
	pGetTickCount64 = (void *)GetProcAddress(library, "GetTickCount64");
	pGetTimeFormatA = (void *)GetProcAddress(library, "GetTimeFormatA");
	pGetTimeFormatEx = (void *)GetProcAddress(library, "GetTimeFormatEx");
	pGetTimeFormatW = (void *)GetProcAddress(library, "GetTimeFormatW");
	pGetTimeZoneInformation = (void *)GetProcAddress(library, "GetTimeZoneInformation");
	pGetTimeZoneInformationForYear = (void *)GetProcAddress(library, "GetTimeZoneInformationForYear");
	pGetUmsCompletionListEvent = (void *)GetProcAddress(library, "GetUmsCompletionListEvent");
	pGetUserDefaultLCID = (void *)GetProcAddress(library, "GetUserDefaultLCID");
	pGetUserDefaultLangID = (void *)GetProcAddress(library, "GetUserDefaultLangID");
	pGetUserDefaultLocaleName = (void *)GetProcAddress(library, "GetUserDefaultLocaleName");
	pGetUserDefaultUILanguage = (void *)GetProcAddress(library, "GetUserDefaultUILanguage");
	pGetUserGeoID = (void *)GetProcAddress(library, "GetUserGeoID");
	pGetVersion = (void *)GetProcAddress(library, "GetVersion");
	pextGetVersion = (void *)GetProcAddress(library_kernelbase, "GetVersion");
	pGetVersionExA = (void *)GetProcAddress(library, "GetVersionExA");
	pextGetVersionExA = (void *)GetProcAddress(library_kernelbase, "GetVersionExA");
	pGetVersionExW = (void *)GetProcAddress(library, "GetVersionExW");
	pextGetVersionExW = (void *)GetProcAddress(library_kernelbase, "GetVersionExW");
	pGetVolumeInformationA = (void *)GetProcAddress(library, "GetVolumeInformationA");
	pGetVolumeInformationByHandleW = (void *)GetProcAddress(library, "GetVolumeInformationByHandleW");
	pGetVolumeInformationW = (void *)GetProcAddress(library, "GetVolumeInformationW");
	pGetVolumeNameForVolumeMountPointA = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointA");
	pGetVolumeNameForVolumeMountPointW = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointW");
	pGetVolumePathNameA = (void *)GetProcAddress(library, "GetVolumePathNameA");
	pGetVolumePathNameW = (void *)GetProcAddress(library, "GetVolumePathNameW");
	pGetVolumePathNamesForVolumeNameA = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameA");
	pGetVolumePathNamesForVolumeNameW = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameW");
	pGetWindowsDirectoryA = (void *)GetProcAddress(library, "GetWindowsDirectoryA");
	pextGetWindowsDirectoryA = (void *)GetProcAddress(library_kernelbase, "GetWindowsDirectoryA");
	pGetWindowsDirectoryW = (void *)GetProcAddress(library, "GetWindowsDirectoryW");
	pextGetWindowsDirectoryW = (void *)GetProcAddress(library_kernelbase, "GetWindowsDirectoryW");
	pGetWriteWatch = (void *)GetProcAddress(library, "GetWriteWatch");
	pextGetWriteWatch = (void *)GetProcAddress(library_kernelbase, "GetWriteWatch");
	pGlobalAddAtomA = (void *)GetProcAddress(library, "GlobalAddAtomA");
	pGlobalAddAtomW = (void *)GetProcAddress(library, "GlobalAddAtomW");
	pGlobalAlloc = (void *)GetProcAddress(library, "GlobalAlloc");
	pextGlobalAlloc = (void *)GetProcAddress(library_kernelbase, "GlobalAlloc");
	pGlobalCompact = (void *)GetProcAddress(library, "GlobalCompact");
	pGlobalDeleteAtom = (void *)GetProcAddress(library, "GlobalDeleteAtom");
	pGlobalFindAtomA = (void *)GetProcAddress(library, "GlobalFindAtomA");
	pGlobalFindAtomW = (void *)GetProcAddress(library, "GlobalFindAtomW");
	pGlobalFix = (void *)GetProcAddress(library, "GlobalFix");
	pGlobalFlags = (void *)GetProcAddress(library, "GlobalFlags");
	pGlobalFree = (void *)GetProcAddress(library, "GlobalFree");
	pextGlobalFree = (void *)GetProcAddress(library_kernelbase, "GlobalFree");
	pGlobalGetAtomNameA = (void *)GetProcAddress(library, "GlobalGetAtomNameA");
	pGlobalGetAtomNameW = (void *)GetProcAddress(library, "GlobalGetAtomNameW");
	pGlobalHandle = (void *)GetProcAddress(library, "GlobalHandle");
	pGlobalLock = (void *)GetProcAddress(library, "GlobalLock");
	pGlobalMemoryStatus = (void *)GetProcAddress(library, "GlobalMemoryStatus");
	pGlobalMemoryStatusEx = (void *)GetProcAddress(library, "GlobalMemoryStatusEx");
	pGlobalReAlloc = (void *)GetProcAddress(library, "GlobalReAlloc");
	pGlobalSize = (void *)GetProcAddress(library, "GlobalSize");
	pGlobalUnWire = (void *)GetProcAddress(library, "GlobalUnWire");
	pGlobalUnfix = (void *)GetProcAddress(library, "GlobalUnfix");
	pGlobalUnlock = (void *)GetProcAddress(library, "GlobalUnlock");
	pGlobalWire = (void *)GetProcAddress(library, "GlobalWire");
	pHeap32ListFirst = (void *)GetProcAddress(library, "Heap32ListFirst");
	pHeapAlloc = (void *)GetProcAddress(library, "HeapAlloc");
	pextHeapAlloc = (void *)GetProcAddress(library_ntdll, "RtlAllocateHeap");
	pHeapCompact = (void *)GetProcAddress(library, "HeapCompact");
	pextHeapCompact = (void *)GetProcAddress(library_kernelbase, "HeapCompact");
	pHeapCreate = (void *)GetProcAddress(library, "HeapCreate");
	pHeapDestroy = (void *)GetProcAddress(library, "HeapDestroy");
	pHeapFree = (void *)GetProcAddress(library, "HeapFree");
	pHeapLock = (void *)GetProcAddress(library, "HeapLock");
	pextHeapLock = (void *)GetProcAddress(library_kernelbase, "HeapLock");
	pHeapQueryInformation = (void *)GetProcAddress(library, "HeapQueryInformation");
	pextHeapQueryInformation = (void *)GetProcAddress(library_kernelbase, "HeapQueryInformation");
	pHeapReAlloc = (void *)GetProcAddress(library, "HeapReAlloc");
	pextHeapReAlloc = (void *)GetProcAddress(library_ntdll, "RtlReAllocateHeap");
	pHeapSetInformation = (void *)GetProcAddress(library, "HeapSetInformation");
	pextHeapSetInformation = (void *)GetProcAddress(library_kernelbase, "HeapSetInformation");
	pHeapSize = (void *)GetProcAddress(library, "HeapSize");
	pextHeapSize = (void *)GetProcAddress(library_ntdll, "RtlSizeHeap");
	pHeapUnlock = (void *)GetProcAddress(library, "HeapUnlock");
	pextHeapUnlock = (void *)GetProcAddress(library_kernelbase, "HeapUnlock");
	pHeapValidate = (void *)GetProcAddress(library, "HeapValidate");
	pextHeapValidate = (void *)GetProcAddress(library_kernelbase, "HeapValidate");
	pHeapWalk = (void *)GetProcAddress(library, "HeapWalk");
	pextHeapWalk = (void *)GetProcAddress(library_kernelbase, "HeapWalk");
	pIdnToAscii = (void *)GetProcAddress(library, "IdnToAscii");
	pIdnToNameprepUnicode = (void *)GetProcAddress(library, "IdnToNameprepUnicode");
	pIdnToUnicode = (void *)GetProcAddress(library, "IdnToUnicode");
	pInitAtomTable = (void *)GetProcAddress(library, "InitAtomTable");
	pInitOnceBeginInitialize = (void *)GetProcAddress(library, "InitOnceBeginInitialize");
	pextInitOnceBeginInitialize = (void *)GetProcAddress(library_kernelbase, "InitOnceBeginInitialize");
	pInitOnceComplete = (void *)GetProcAddress(library, "InitOnceComplete");
	pextInitOnceComplete = (void *)GetProcAddress(library_kernelbase, "InitOnceComplete");
	pInitOnceExecuteOnce = (void *)GetProcAddress(library, "InitOnceExecuteOnce");
	pextInitOnceExecuteOnce = (void *)GetProcAddress(library_kernelbase, "InitOnceExecuteOnce");
	pInitOnceInitialize = (void *)GetProcAddress(library, "InitOnceInitialize");
	pextInitOnceInitialize = (void *)GetProcAddress(library_ntdll, "RtlRunOnceInitialize");
	pInitializeConditionVariable = (void *)GetProcAddress(library, "InitializeConditionVariable");
	pextInitializeConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlInitializeConditionVariable");
	pInitializeCriticalSection = (void *)GetProcAddress(library, "InitializeCriticalSection");
	pextInitializeCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlInitializeCriticalSection");
	pInitializeCriticalSectionAndSpinCount = (void *)GetProcAddress(library, "InitializeCriticalSectionAndSpinCount");
	pextInitializeCriticalSectionAndSpinCount = (void *)GetProcAddress(library_kernelbase, "InitializeCriticalSectionAndSpinCount");
	pInitializeCriticalSectionEx = (void *)GetProcAddress(library, "InitializeCriticalSectionEx");
	pextInitializeCriticalSectionEx = (void *)GetProcAddress(library_kernelbase, "InitializeCriticalSectionEx");
	pInitializeProcThreadAttributeList = (void *)GetProcAddress(library, "InitializeProcThreadAttributeList");
	pextInitializeProcThreadAttributeList = (void *)GetProcAddress(library_kernelbase, "InitializeProcThreadAttributeList");
	pInitializeSListHead = (void *)GetProcAddress(library, "InitializeSListHead");
	pextInitializeSListHead = (void *)GetProcAddress(library_ntdll, "RtlInitializeSListHead");
	pInitializeSRWLock = (void *)GetProcAddress(library, "InitializeSRWLock");
	pextInitializeSRWLock = (void *)GetProcAddress(library_ntdll, "RtlInitializeSRWLock");
	pInterlockedCompareExchange64 = (void *)GetProcAddress(library, "InterlockedCompareExchange64");
	pextInterlockedCompareExchange64 = (void *)GetProcAddress(library_ntdll, "RtlInterlockedCompareExchange64");
	pInterlockedFlushSList = (void *)GetProcAddress(library, "InterlockedFlushSList");
	pextInterlockedFlushSList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedFlushSList");
	pInterlockedPopEntrySList = (void *)GetProcAddress(library, "InterlockedPopEntrySList");
	pextInterlockedPopEntrySList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPopEntrySList");
	pInterlockedPushEntrySList = (void *)GetProcAddress(library, "InterlockedPushEntrySList");
	pextInterlockedPushEntrySList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushEntrySList");
	pInterlockedPushListSList = (void *)GetProcAddress(library, "InterlockedPushListSList");
	pextInterlockedPushListSList = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushListSList");
	pInterlockedPushListSListEx = (void *)GetProcAddress(library, "InterlockedPushListSListEx");
	pextInterlockedPushListSListEx = (void *)GetProcAddress(library_ntdll, "RtlInterlockedPushListSListEx");
	pInvalidateNLSCache = (void *)GetProcAddress(library, "InvalidateNLSCache");
	pIsBadCodePtr = (void *)GetProcAddress(library, "IsBadCodePtr");
	pIsBadHugeReadPtr = (void *)GetProcAddress(library, "IsBadHugeReadPtr");
	pIsBadHugeWritePtr = (void *)GetProcAddress(library, "IsBadHugeWritePtr");
	pIsBadReadPtr = (void *)GetProcAddress(library, "IsBadReadPtr");
	pIsBadStringPtrA = (void *)GetProcAddress(library, "IsBadStringPtrA");
	pIsBadStringPtrW = (void *)GetProcAddress(library, "IsBadStringPtrW");
	pIsBadWritePtr = (void *)GetProcAddress(library, "IsBadWritePtr");
	pIsDBCSLeadByte = (void *)GetProcAddress(library, "IsDBCSLeadByte");
	pIsDBCSLeadByteEx = (void *)GetProcAddress(library, "IsDBCSLeadByteEx");
	pIsDebuggerPresent = (void *)GetProcAddress(library, "IsDebuggerPresent");
	pextIsDebuggerPresent = (void *)GetProcAddress(library_kernelbase, "IsDebuggerPresent");
	pIsNormalizedString = (void *)GetProcAddress(library, "IsNormalizedString");
	pIsProcessInJob = (void *)GetProcAddress(library, "IsProcessInJob");
	pIsProcessorFeaturePresent = (void *)GetProcAddress(library, "IsProcessorFeaturePresent");
	pIsSystemResumeAutomatic = (void *)GetProcAddress(library, "IsSystemResumeAutomatic");
	pIsThreadAFiber = (void *)GetProcAddress(library, "IsThreadAFiber");
	pextIsThreadAFiber = (void *)GetProcAddress(library_kernelbase, "IsThreadAFiber");
	pIsThreadpoolTimerSet = (void *)GetProcAddress(library, "IsThreadpoolTimerSet");
	pextIsThreadpoolTimerSet = (void *)GetProcAddress(library_ntdll, "TpIsTimerSet");
	pIsValidCodePage = (void *)GetProcAddress(library, "IsValidCodePage");
	pIsValidLanguageGroup = (void *)GetProcAddress(library, "IsValidLanguageGroup");
	pIsValidLocale = (void *)GetProcAddress(library, "IsValidLocale");
	pIsValidLocaleName = (void *)GetProcAddress(library, "IsValidLocaleName");
	pIsWow64Process = (void *)GetProcAddress(library, "IsWow64Process");
	pextIsWow64Process = (void *)GetProcAddress(library_kernelbase, "IsWow64Process");
	pK32EmptyWorkingSet = (void *)GetProcAddress(library, "K32EmptyWorkingSet");
	pK32EnumDeviceDrivers = (void *)GetProcAddress(library, "K32EnumDeviceDrivers");
	pK32EnumPageFilesA = (void *)GetProcAddress(library, "K32EnumPageFilesA");
	pK32EnumPageFilesW = (void *)GetProcAddress(library, "K32EnumPageFilesW");
	pK32EnumProcessModules = (void *)GetProcAddress(library, "K32EnumProcessModules");
	pK32EnumProcessModulesEx = (void *)GetProcAddress(library, "K32EnumProcessModulesEx");
	pK32EnumProcesses = (void *)GetProcAddress(library, "K32EnumProcesses");
	pK32GetDeviceDriverBaseNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameA");
	pK32GetDeviceDriverBaseNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverBaseNameW");
	pK32GetDeviceDriverFileNameA = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameA");
	pK32GetDeviceDriverFileNameW = (void *)GetProcAddress(library, "K32GetDeviceDriverFileNameW");
	pK32GetMappedFileNameA = (void *)GetProcAddress(library, "K32GetMappedFileNameA");
	pK32GetMappedFileNameW = (void *)GetProcAddress(library, "K32GetMappedFileNameW");
	pK32GetModuleBaseNameA = (void *)GetProcAddress(library, "K32GetModuleBaseNameA");
	pK32GetModuleBaseNameW = (void *)GetProcAddress(library, "K32GetModuleBaseNameW");
	pK32GetModuleFileNameExA = (void *)GetProcAddress(library, "K32GetModuleFileNameExA");
	pK32GetModuleFileNameExW = (void *)GetProcAddress(library, "K32GetModuleFileNameExW");
	pK32GetModuleInformation = (void *)GetProcAddress(library, "K32GetModuleInformation");
	pK32GetPerformanceInfo = (void *)GetProcAddress(library, "K32GetPerformanceInfo");
	pK32GetProcessImageFileNameA = (void *)GetProcAddress(library, "K32GetProcessImageFileNameA");
	pK32GetProcessImageFileNameW = (void *)GetProcAddress(library, "K32GetProcessImageFileNameW");
	pK32GetProcessMemoryInfo = (void *)GetProcAddress(library, "K32GetProcessMemoryInfo");
	pK32GetWsChanges = (void *)GetProcAddress(library, "K32GetWsChanges");
	pK32GetWsChangesEx = (void *)GetProcAddress(library, "K32GetWsChangesEx");
	pK32InitializeProcessForWsWatch = (void *)GetProcAddress(library, "K32InitializeProcessForWsWatch");
	pK32QueryWorkingSet = (void *)GetProcAddress(library, "K32QueryWorkingSet");
	pK32QueryWorkingSetEx = (void *)GetProcAddress(library, "K32QueryWorkingSetEx");
	pLCIDToLocaleName = (void *)GetProcAddress(library, "LCIDToLocaleName");
	pLCMapStringA = (void *)GetProcAddress(library, "LCMapStringA");
	pLCMapStringEx = (void *)GetProcAddress(library, "LCMapStringEx");
	pLCMapStringW = (void *)GetProcAddress(library, "LCMapStringW");
	pLZClose = (void *)GetProcAddress(library, "LZClose");
	pLZCopy = (void *)GetProcAddress(library, "LZCopy");
	pLZDone = (void *)GetProcAddress(library, "LZDone");
	pLZInit = (void *)GetProcAddress(library, "LZInit");
	pLZOpenFileA = (void *)GetProcAddress(library, "LZOpenFileA");
	pLZOpenFileW = (void *)GetProcAddress(library, "LZOpenFileW");
	pLZRead = (void *)GetProcAddress(library, "LZRead");
	pLZSeek = (void *)GetProcAddress(library, "LZSeek");
	pLZStart = (void *)GetProcAddress(library, "LZStart");
	pLeaveCriticalSection = (void *)GetProcAddress(library, "LeaveCriticalSection");
	pextLeaveCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlLeaveCriticalSection");
	pLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library, "LeaveCriticalSectionWhenCallbackReturns");
	pextLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackLeaveCriticalSectionOnCompletion");
	pLoadLibraryA = (void *)GetProcAddress(library, "LoadLibraryA");
	pLoadLibraryExA = (void *)GetProcAddress(library, "LoadLibraryExA");
	pLoadLibraryExW = (void *)GetProcAddress(library, "LoadLibraryExW");
	pLoadLibraryW = (void *)GetProcAddress(library, "LoadLibraryW");
	pLoadModule = (void *)GetProcAddress(library, "LoadModule");
	pLoadResource = (void *)GetProcAddress(library, "LoadResource");
	pextLoadResource = (void *)GetProcAddress(library_kernelbase, "LoadResource");
	pLocalAlloc = (void *)GetProcAddress(library, "LocalAlloc");
	pextLocalAlloc = (void *)GetProcAddress(library_kernelbase, "LocalAlloc");
	pLocalCompact = (void *)GetProcAddress(library, "LocalCompact");
	pLocalFileTimeToFileTime = (void *)GetProcAddress(library, "LocalFileTimeToFileTime");
	pLocalFlags = (void *)GetProcAddress(library, "LocalFlags");
	pLocalFree = (void *)GetProcAddress(library, "LocalFree");
	pextLocalFree = (void *)GetProcAddress(library_kernelbase, "LocalFree");
	pLocalHandle = (void *)GetProcAddress(library, "LocalHandle");
	pLocalLock = (void *)GetProcAddress(library, "LocalLock");
	pextLocalLock = (void *)GetProcAddress(library_kernelbase, "LocalLock");
	pLocalReAlloc = (void *)GetProcAddress(library, "LocalReAlloc");
	pextLocalReAlloc = (void *)GetProcAddress(library_kernelbase, "LocalReAlloc");
	pLocalShrink = (void *)GetProcAddress(library, "LocalShrink");
	pLocalSize = (void *)GetProcAddress(library, "LocalSize");
	pLocalUnlock = (void *)GetProcAddress(library, "LocalUnlock");
	pextLocalUnlock = (void *)GetProcAddress(library_kernelbase, "LocalUnlock");
	pLocaleNameToLCID = (void *)GetProcAddress(library, "LocaleNameToLCID");
	pLockFile = (void *)GetProcAddress(library, "LockFile");
	pextLockFile = (void *)GetProcAddress(library_kernelbase, "LockFile");
	pLockFileEx = (void *)GetProcAddress(library, "LockFileEx");
	pextLockFileEx = (void *)GetProcAddress(library_kernelbase, "LockFileEx");
	pLockResource = (void *)GetProcAddress(library, "LockResource");
	pextLockResource = (void *)GetProcAddress(library_kernelbase, "LockResource");
	pMakeCriticalSectionGlobal = (void *)GetProcAddress(library, "MakeCriticalSectionGlobal");
	pMapUserPhysicalPages = (void *)GetProcAddress(library, "MapUserPhysicalPages");
	pMapViewOfFile = (void *)GetProcAddress(library, "MapViewOfFile");
	pextMapViewOfFile = (void *)GetProcAddress(library_kernelbase, "MapViewOfFile");
	pMapViewOfFileEx = (void *)GetProcAddress(library, "MapViewOfFileEx");
	pextMapViewOfFileEx = (void *)GetProcAddress(library_kernelbase, "MapViewOfFileEx");
	pMapViewOfFileExNuma = (void *)GetProcAddress(library, "MapViewOfFileExNuma");
	pextMapViewOfFileExNuma = (void *)GetProcAddress(library_kernelbase, "MapViewOfFileExNuma");
	pModule32First = (void *)GetProcAddress(library, "Module32First");
	pModule32FirstW = (void *)GetProcAddress(library, "Module32FirstW");
	pModule32Next = (void *)GetProcAddress(library, "Module32Next");
	pModule32NextW = (void *)GetProcAddress(library, "Module32NextW");
	pMoveFileA = (void *)GetProcAddress(library, "MoveFileA");
	pMoveFileExA = (void *)GetProcAddress(library, "MoveFileExA");
	pMoveFileExW = (void *)GetProcAddress(library, "MoveFileExW");
	pMoveFileTransactedA = (void *)GetProcAddress(library, "MoveFileTransactedA");
	pMoveFileTransactedW = (void *)GetProcAddress(library, "MoveFileTransactedW");
	pMoveFileW = (void *)GetProcAddress(library, "MoveFileW");
	pMoveFileWithProgressA = (void *)GetProcAddress(library, "MoveFileWithProgressA");
	pMoveFileWithProgressW = (void *)GetProcAddress(library, "MoveFileWithProgressW");
	pMulDiv = (void *)GetProcAddress(library, "MulDiv");
	pMultiByteToWideChar = (void *)GetProcAddress(library, "MultiByteToWideChar");
	pNeedCurrentDirectoryForExePathA = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathA");
	pNeedCurrentDirectoryForExePathW = (void *)GetProcAddress(library, "NeedCurrentDirectoryForExePathW");
	pNormalizeString = (void *)GetProcAddress(library, "NormalizeString");
	pOpenConsoleW = (void *)GetProcAddress(library, "OpenConsoleW");
	pOpenEventA = (void *)GetProcAddress(library, "OpenEventA");
	pextOpenEventA = (void *)GetProcAddress(library_kernelbase, "OpenEventA");
	pOpenEventW = (void *)GetProcAddress(library, "OpenEventW");
	pextOpenEventW = (void *)GetProcAddress(library_kernelbase, "OpenEventW");
	pOpenFile = (void *)GetProcAddress(library, "OpenFile");
	pOpenFileById = (void *)GetProcAddress(library, "OpenFileById");
	pextOpenFileById = (void *)GetProcAddress(library_kernelbase, "OpenFileById");
	pOpenFileMappingA = (void *)GetProcAddress(library, "OpenFileMappingA");
	pOpenFileMappingW = (void *)GetProcAddress(library, "OpenFileMappingW");
	pextOpenFileMappingW = (void *)GetProcAddress(library_kernelbase, "OpenFileMappingW");
	pOpenJobObjectA = (void *)GetProcAddress(library, "OpenJobObjectA");
	pOpenJobObjectW = (void *)GetProcAddress(library, "OpenJobObjectW");
	pOpenMutexA = (void *)GetProcAddress(library, "OpenMutexA");
	pOpenMutexW = (void *)GetProcAddress(library, "OpenMutexW");
	pextOpenMutexW = (void *)GetProcAddress(library_kernelbase, "OpenMutexW");
	pOpenProcess = (void *)GetProcAddress(library, "OpenProcess");
	pextOpenProcess = (void *)GetProcAddress(library_kernelbase, "OpenProcess");
	pOpenProfileUserMapping = (void *)GetProcAddress(library, "OpenProfileUserMapping");
	pOpenSemaphoreA = (void *)GetProcAddress(library, "OpenSemaphoreA");
	pOpenSemaphoreW = (void *)GetProcAddress(library, "OpenSemaphoreW");
	pextOpenSemaphoreW = (void *)GetProcAddress(library_kernelbase, "OpenSemaphoreW");
	pOpenThread = (void *)GetProcAddress(library, "OpenThread");
	pextOpenThread = (void *)GetProcAddress(library_kernelbase, "OpenThread");
	pOpenVxDHandle = (void *)GetProcAddress(library, "OpenVxDHandle");
	pOpenWaitableTimerA = (void *)GetProcAddress(library, "OpenWaitableTimerA");
	pOpenWaitableTimerW = (void *)GetProcAddress(library, "OpenWaitableTimerW");
	pextOpenWaitableTimerW = (void *)GetProcAddress(library_kernelbase, "OpenWaitableTimerW");
	pOutputDebugStringA = (void *)GetProcAddress(library, "OutputDebugStringA");
	pextOutputDebugStringA = (void *)GetProcAddress(library_kernelbase, "OutputDebugStringA");
	pOutputDebugStringW = (void *)GetProcAddress(library, "OutputDebugStringW");
	pextOutputDebugStringW = (void *)GetProcAddress(library_kernelbase, "OutputDebugStringW");
	pPeekConsoleInputA = (void *)GetProcAddress(library, "PeekConsoleInputA");
	pextPeekConsoleInputA = (void *)GetProcAddress(library_kernelbase, "PeekConsoleInputA");
	pPeekConsoleInputW = (void *)GetProcAddress(library, "PeekConsoleInputW");
	pextPeekConsoleInputW = (void *)GetProcAddress(library_kernelbase, "PeekConsoleInputW");
	pPeekNamedPipe = (void *)GetProcAddress(library, "PeekNamedPipe");
	pextPeekNamedPipe = (void *)GetProcAddress(library_kernelbase, "PeekNamedPipe");
	pPostQueuedCompletionStatus = (void *)GetProcAddress(library, "PostQueuedCompletionStatus");
	pextPostQueuedCompletionStatus = (void *)GetProcAddress(library_kernelbase, "PostQueuedCompletionStatus");
	pPowerClearRequest = (void *)GetProcAddress(library, "PowerClearRequest");
	pPowerCreateRequest = (void *)GetProcAddress(library, "PowerCreateRequest");
	pPowerSetRequest = (void *)GetProcAddress(library, "PowerSetRequest");
	pPrepareTape = (void *)GetProcAddress(library, "PrepareTape");
	pProcess32First = (void *)GetProcAddress(library, "Process32First");
	pProcess32FirstW = (void *)GetProcAddress(library, "Process32FirstW");
	pProcess32Next = (void *)GetProcAddress(library, "Process32Next");
	pProcess32NextW = (void *)GetProcAddress(library, "Process32NextW");
	pProcessIdToSessionId = (void *)GetProcAddress(library, "ProcessIdToSessionId");
	pPulseEvent = (void *)GetProcAddress(library, "PulseEvent");
	pextPulseEvent = (void *)GetProcAddress(library_kernelbase, "PulseEvent");
	pPurgeComm = (void *)GetProcAddress(library, "PurgeComm");
	pextPurgeComm = (void *)GetProcAddress(library_kernelbase, "PurgeComm");
	pQueryActCtxSettingsW = (void *)GetProcAddress(library, "QueryActCtxSettingsW");
	pextQueryActCtxSettingsW = (void *)GetProcAddress(library_kernelbase, "QueryActCtxSettingsW");
	pQueryActCtxW = (void *)GetProcAddress(library, "QueryActCtxW");
	pextQueryActCtxW = (void *)GetProcAddress(library_kernelbase, "QueryActCtxW");
	pQueryDepthSList = (void *)GetProcAddress(library, "QueryDepthSList");
	pextQueryDepthSList = (void *)GetProcAddress(library_ntdll, "RtlQueryDepthSList");
	pQueryDosDeviceA = (void *)GetProcAddress(library, "QueryDosDeviceA");
	pQueryDosDeviceW = (void *)GetProcAddress(library, "QueryDosDeviceW");
	pQueryFullProcessImageNameA = (void *)GetProcAddress(library, "QueryFullProcessImageNameA");
	pQueryFullProcessImageNameW = (void *)GetProcAddress(library, "QueryFullProcessImageNameW");
	pQueryInformationJobObject = (void *)GetProcAddress(library, "QueryInformationJobObject");
	pQueryMemoryResourceNotification = (void *)GetProcAddress(library, "QueryMemoryResourceNotification");
	pextQueryMemoryResourceNotification = (void *)GetProcAddress(library_kernelbase, "QueryMemoryResourceNotification");
	pQueryPerformanceCounter = (void *)GetProcAddress(library, "QueryPerformanceCounter");
	pextQueryPerformanceCounter = (void *)GetProcAddress(library_kernelbase, "QueryPerformanceCounter");
	pQueryPerformanceFrequency = (void *)GetProcAddress(library, "QueryPerformanceFrequency");
	pextQueryPerformanceFrequency = (void *)GetProcAddress(library_kernelbase, "QueryPerformanceFrequency");
	pQueryProcessCycleTime = (void *)GetProcAddress(library, "QueryProcessCycleTime");
	pQueryThreadCycleTime = (void *)GetProcAddress(library, "QueryThreadCycleTime");
	pQueryUmsThreadInformation = (void *)GetProcAddress(library, "QueryUmsThreadInformation");
	pQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "QueryUnbiasedInterruptTime");
	pQueueUserAPC = (void *)GetProcAddress(library, "QueueUserAPC");
	pextQueueUserAPC = (void *)GetProcAddress(library_kernelbase, "QueueUserAPC");
	pQueueUserWorkItem = (void *)GetProcAddress(library, "QueueUserWorkItem");
	pextQueueUserWorkItem = (void *)GetProcAddress(library_kernelbase, "QueueUserWorkItem");
	pRaiseException = (void *)GetProcAddress(library, "RaiseException");
	pextRaiseException = (void *)GetProcAddress(library_kernelbase, "RaiseException");
	pReadConsoleA = (void *)GetProcAddress(library, "ReadConsoleA");
	pextReadConsoleA = (void *)GetProcAddress(library_kernelbase, "ReadConsoleA");
	pReadConsoleInputA = (void *)GetProcAddress(library, "ReadConsoleInputA");
	pextReadConsoleInputA = (void *)GetProcAddress(library_kernelbase, "ReadConsoleInputA");
	pReadConsoleInputW = (void *)GetProcAddress(library, "ReadConsoleInputW");
	pReadConsoleOutputA = (void *)GetProcAddress(library, "ReadConsoleOutputA");
	pextReadConsoleOutputA = (void *)GetProcAddress(library_kernelbase, "ReadConsoleOutputA");
	pReadConsoleOutputAttribute = (void *)GetProcAddress(library, "ReadConsoleOutputAttribute");
	pextReadConsoleOutputAttribute = (void *)GetProcAddress(library_kernelbase, "ReadConsoleOutputAttribute");
	pReadConsoleOutputCharacterA = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterA");
	pextReadConsoleOutputCharacterA = (void *)GetProcAddress(library_kernelbase, "ReadConsoleOutputCharacterA");
	pReadConsoleOutputCharacterW = (void *)GetProcAddress(library, "ReadConsoleOutputCharacterW");
	pextReadConsoleOutputCharacterW = (void *)GetProcAddress(library_kernelbase, "ReadConsoleOutputCharacterW");
	pReadConsoleOutputW = (void *)GetProcAddress(library, "ReadConsoleOutputW");
	pextReadConsoleOutputW = (void *)GetProcAddress(library_kernelbase, "ReadConsoleOutputW");
	pReadConsoleW = (void *)GetProcAddress(library, "ReadConsoleW");
	pReadDirectoryChangesW = (void *)GetProcAddress(library, "ReadDirectoryChangesW");
	pextReadDirectoryChangesW = (void *)GetProcAddress(library_kernelbase, "ReadDirectoryChangesW");
	pReadFile = (void *)GetProcAddress(library, "ReadFile");
	pextReadFile = (void *)GetProcAddress(library_kernelbase, "ReadFile");
	pReadFileEx = (void *)GetProcAddress(library, "ReadFileEx");
	pextReadFileEx = (void *)GetProcAddress(library_kernelbase, "ReadFileEx");
	pReadFileScatter = (void *)GetProcAddress(library, "ReadFileScatter");
	pextReadFileScatter = (void *)GetProcAddress(library_kernelbase, "ReadFileScatter");
	pReadProcessMemory = (void *)GetProcAddress(library, "ReadProcessMemory");
	pextReadProcessMemory = (void *)GetProcAddress(library_kernelbase, "ReadProcessMemory");
	pRegisterApplicationRecoveryCallback = (void *)GetProcAddress(library, "RegisterApplicationRecoveryCallback");
	pRegisterApplicationRestart = (void *)GetProcAddress(library, "RegisterApplicationRestart");
	pRegisterServiceProcess = (void *)GetProcAddress(library, "RegisterServiceProcess");
	pRegisterWaitForSingleObject = (void *)GetProcAddress(library, "RegisterWaitForSingleObject");
	pRegisterWaitForSingleObjectEx = (void *)GetProcAddress(library, "RegisterWaitForSingleObjectEx");
	pextRegisterWaitForSingleObjectEx = (void *)GetProcAddress(library_kernelbase, "RegisterWaitForSingleObjectEx");
	pReinitializeCriticalSection = (void *)GetProcAddress(library, "ReinitializeCriticalSection");
	pReleaseActCtx = (void *)GetProcAddress(library, "ReleaseActCtx");
	pextReleaseActCtx = (void *)GetProcAddress(library_kernelbase, "ReleaseActCtx");
	pReleaseMutex = (void *)GetProcAddress(library, "ReleaseMutex");
	pextReleaseMutex = (void *)GetProcAddress(library_kernelbase, "ReleaseMutex");
	pReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseMutexWhenCallbackReturns");
	pextReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseMutexOnCompletion");
	pReleaseSemaphore = (void *)GetProcAddress(library, "ReleaseSemaphore");
	pextReleaseSemaphore = (void *)GetProcAddress(library_kernelbase, "ReleaseSemaphore");
	pReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseSemaphoreWhenCallbackReturns");
	pextReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseSemaphoreOnCompletion");
	pReleaseSRWLockExclusive = (void *)GetProcAddress(library, "ReleaseSRWLockExclusive");
	pextReleaseSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockExclusive");
	pReleaseSRWLockShared = (void *)GetProcAddress(library, "ReleaseSRWLockShared");
	pextReleaseSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockShared");
	pRemoveDirectoryA = (void *)GetProcAddress(library, "RemoveDirectoryA");
	pRemoveDirectoryW = (void *)GetProcAddress(library, "RemoveDirectoryW");
	pRemoveVectoredContinueHandler = (void *)GetProcAddress(library, "RemoveVectoredContinueHandler");
	pextRemoveVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredContinueHandler");
	pRemoveVectoredExceptionHandler = (void *)GetProcAddress(library, "RemoveVectoredExceptionHandler");
	pextRemoveVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredExceptionHandler");
	pReplaceFileA = (void *)GetProcAddress(library, "ReplaceFileA");
	pReplaceFileW = (void *)GetProcAddress(library, "ReplaceFileW");
	pRemoveDllDirectory = (void *)GetProcAddress(library, "RemoveDllDirectory");
	pRequestDeviceWakeup = (void *)GetProcAddress(library, "RequestDeviceWakeup");
	pRequestWakeupLatency = (void *)GetProcAddress(library, "RequestWakeupLatency");
	pResetEvent = (void *)GetProcAddress(library, "ResetEvent");
	pextResetEvent = (void *)GetProcAddress(library_kernelbase, "ResetEvent");
	pResetWriteWatch = (void *)GetProcAddress(library, "ResetWriteWatch");
	pextResetWriteWatch = (void *)GetProcAddress(library_kernelbase, "ResetWriteWatch");
	pResolveDelayLoadedAPI = (void *)GetProcAddress(library, "ResolveDelayLoadedAPI");
	pextResolveDelayLoadedAPI = (void *)GetProcAddress(library_ntdll, "LdrResolveDelayLoadedAPI");
	pResolveLocaleName = (void *)GetProcAddress(library, "ResolveLocaleName");
	pRestoreLastError = (void *)GetProcAddress(library, "RestoreLastError");
	pextRestoreLastError = (void *)GetProcAddress(library_ntdll, "RtlRestoreLastWin32Error");
	pResumeThread = (void *)GetProcAddress(library, "ResumeThread");
	pextResumeThread = (void *)GetProcAddress(library_kernelbase, "ResumeThread");
	pRtlAddFunctionTable = (void *)GetProcAddress(library, "RtlAddFunctionTable");
	pextRtlAddFunctionTable = (void *)GetProcAddress(library_ntdll, "RtlAddFunctionTable");
	pRtlCaptureContext = (void *)GetProcAddress(library, "RtlCaptureContext");
	pextRtlCaptureContext = (void *)GetProcAddress(library_ntdll, "RtlCaptureContext");
	pRtlCaptureStackBackTrace = (void *)GetProcAddress(library, "RtlCaptureStackBackTrace");
	pextRtlCaptureStackBackTrace = (void *)GetProcAddress(library_ntdll, "RtlCaptureStackBackTrace");
	pRtlCompareMemory = (void *)GetProcAddress(library, "RtlCompareMemory");
	pextRtlCompareMemory = (void *)GetProcAddress(library_ntdll, "RtlCompareMemory");
	pRtlCopyMemory = (void *)GetProcAddress(library, "RtlCopyMemory");
	pextRtlCopyMemory = (void *)GetProcAddress(library_ntdll, "RtlCopyMemory");
	pRtlDeleteFunctionTable = (void *)GetProcAddress(library, "RtlDeleteFunctionTable");
	pextRtlDeleteFunctionTable = (void *)GetProcAddress(library_ntdll, "RtlDeleteFunctionTable");
	pRtlFillMemory = (void *)GetProcAddress(library, "RtlFillMemory");
	pextRtlFillMemory = (void *)GetProcAddress(library_ntdll, "RtlFillMemory");
	pRtlInstallFunctionTableCallback = (void *)GetProcAddress(library, "RtlInstallFunctionTableCallback");
	pextRtlInstallFunctionTableCallback = (void *)GetProcAddress(library_ntdll, "RtlInstallFunctionTableCallback");
	pRtlLookupFunctionEntry = (void *)GetProcAddress(library, "RtlLookupFunctionEntry");
	pextRtlLookupFunctionEntry = (void *)GetProcAddress(library_ntdll, "RtlLookupFunctionEntry");
	pRtlMoveMemory = (void *)GetProcAddress(library, "RtlMoveMemory");
	pextRtlMoveMemory = (void *)GetProcAddress(library_ntdll, "RtlMoveMemory");
	pRtlPcToFileHeader = (void *)GetProcAddress(library, "RtlPcToFileHeader");
	pextRtlPcToFileHeader = (void *)GetProcAddress(library_ntdll, "RtlPcToFileHeader");
	pRtlRaiseException = (void *)GetProcAddress(library, "RtlRaiseException");
	pextRtlRaiseException = (void *)GetProcAddress(library_ntdll, "RtlRaiseException");
	pRtlRestoreContext = (void *)GetProcAddress(library, "RtlRestoreContext");
	pextRtlRestoreContext = (void *)GetProcAddress(library_ntdll, "RtlRestoreContext");
	pRtlUnwind = (void *)GetProcAddress(library, "RtlUnwind");
	pextRtlUnwind = (void *)GetProcAddress(library_ntdll, "RtlUnwind");
	pRtlUnwindEx = (void *)GetProcAddress(library, "RtlUnwindEx");
	pextRtlUnwindEx = (void *)GetProcAddress(library_ntdll, "RtlUnwindEx");
	pRtlVirtualUnwind = (void *)GetProcAddress(library, "RtlVirtualUnwind");
	pextRtlVirtualUnwind = (void *)GetProcAddress(library_ntdll, "RtlVirtualUnwind");
	pRtlZeroMemory = (void *)GetProcAddress(library, "RtlZeroMemory");
	pextRtlZeroMemory = (void *)GetProcAddress(library_ntdll, "RtlZeroMemory");
	pScrollConsoleScreenBufferA = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferA");
	pextScrollConsoleScreenBufferA = (void *)GetProcAddress(library_kernelbase, "ScrollConsoleScreenBufferA");
	pScrollConsoleScreenBufferW = (void *)GetProcAddress(library, "ScrollConsoleScreenBufferW");
	pextScrollConsoleScreenBufferW = (void *)GetProcAddress(library_kernelbase, "ScrollConsoleScreenBufferW");
	pSearchPathA = (void *)GetProcAddress(library, "SearchPathA");
	pSearchPathW = (void *)GetProcAddress(library, "SearchPathW");
	pSetCPGlobal = (void *)GetProcAddress(library, "SetCPGlobal");
	pSetCalendarInfoA = (void *)GetProcAddress(library, "SetCalendarInfoA");
	pSetCalendarInfoW = (void *)GetProcAddress(library, "SetCalendarInfoW");
	pSetCommBreak = (void *)GetProcAddress(library, "SetCommBreak");
	pextSetCommBreak = (void *)GetProcAddress(library_kernelbase, "SetCommBreak");
	pSetCommConfig = (void *)GetProcAddress(library, "SetCommConfig");
	pextSetCommConfig = (void *)GetProcAddress(library_kernelbase, "SetCommConfig");
	pSetCommMask = (void *)GetProcAddress(library, "SetCommMask");
	pextSetCommMask = (void *)GetProcAddress(library_kernelbase, "SetCommMask");
	pSetCommState = (void *)GetProcAddress(library, "SetCommState");
	pextSetCommState = (void *)GetProcAddress(library_kernelbase, "SetCommState");
	pSetCommTimeouts = (void *)GetProcAddress(library, "SetCommTimeouts");
	pextSetCommTimeouts = (void *)GetProcAddress(library_kernelbase, "SetCommTimeouts");
	pSetComputerNameA = (void *)GetProcAddress(library, "SetComputerNameA");
	pSetComputerNameExA = (void *)GetProcAddress(library, "SetComputerNameExA");
	pSetComputerNameExW = (void *)GetProcAddress(library, "SetComputerNameExW");
	pSetComputerNameW = (void *)GetProcAddress(library, "SetComputerNameW");
	pSetConsoleActiveScreenBuffer = (void *)GetProcAddress(library, "SetConsoleActiveScreenBuffer");
	pextSetConsoleActiveScreenBuffer = (void *)GetProcAddress(library_kernelbase, "SetConsoleActiveScreenBuffer");
	pSetConsoleCP = (void *)GetProcAddress(library, "SetConsoleCP");
	pextSetConsoleCP = (void *)GetProcAddress(library_kernelbase, "SetConsoleCP");
	pSetConsoleCtrlHandler = (void *)GetProcAddress(library, "SetConsoleCtrlHandler");
	pSetConsoleCursorInfo = (void *)GetProcAddress(library, "SetConsoleCursorInfo");
	pextSetConsoleCursorInfo = (void *)GetProcAddress(library_kernelbase, "SetConsoleCursorInfo");
	pSetConsoleCursorPosition = (void *)GetProcAddress(library, "SetConsoleCursorPosition");
	pextSetConsoleCursorPosition = (void *)GetProcAddress(library_kernelbase, "SetConsoleCursorPosition");
	pSetConsoleDisplayMode = (void *)GetProcAddress(library, "SetConsoleDisplayMode");
	pSetConsoleFont = (void *)GetProcAddress(library, "SetConsoleFont");
	pSetConsoleIcon = (void *)GetProcAddress(library, "SetConsoleIcon");
	pSetConsoleInputExeNameA = (void *)GetProcAddress(library, "SetConsoleInputExeNameA");
	pextSetConsoleInputExeNameA = (void *)GetProcAddress(library_kernelbase, "SetConsoleInputExeNameA");
	pSetConsoleInputExeNameW = (void *)GetProcAddress(library, "SetConsoleInputExeNameW");
	pextSetConsoleInputExeNameW = (void *)GetProcAddress(library_kernelbase, "SetConsoleInputExeNameW");
	pSetConsoleKeyShortcuts = (void *)GetProcAddress(library, "SetConsoleKeyShortcuts");
	pSetConsoleMode = (void *)GetProcAddress(library, "SetConsoleMode");
	pextSetConsoleMode = (void *)GetProcAddress(library_kernelbase, "SetConsoleMode");
	pSetConsoleOutputCP = (void *)GetProcAddress(library, "SetConsoleOutputCP");
	pextSetConsoleOutputCP = (void *)GetProcAddress(library_kernelbase, "SetConsoleOutputCP");
	pSetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library, "SetConsoleScreenBufferInfoEx");
	pextSetConsoleScreenBufferInfoEx = (void *)GetProcAddress(library_kernelbase, "SetConsoleScreenBufferInfoEx");
	pSetConsoleScreenBufferSize = (void *)GetProcAddress(library, "SetConsoleScreenBufferSize");
	pextSetConsoleScreenBufferSize = (void *)GetProcAddress(library_kernelbase, "SetConsoleScreenBufferSize");
	pSetConsoleTextAttribute = (void *)GetProcAddress(library, "SetConsoleTextAttribute");
	pextSetConsoleTextAttribute = (void *)GetProcAddress(library_kernelbase, "SetConsoleTextAttribute");
	pSetConsoleTitleA = (void *)GetProcAddress(library, "SetConsoleTitleA");
	pSetConsoleTitleW = (void *)GetProcAddress(library, "SetConsoleTitleW");
	pextSetConsoleTitleW = (void *)GetProcAddress(library_kernelbase, "SetConsoleTitleW");
	pSetConsoleWindowInfo = (void *)GetProcAddress(library, "SetConsoleWindowInfo");
	pextSetConsoleWindowInfo = (void *)GetProcAddress(library_kernelbase, "SetConsoleWindowInfo");
	pSetCriticalSectionSpinCount = (void *)GetProcAddress(library, "SetCriticalSectionSpinCount");
	pextSetCriticalSectionSpinCount = (void *)GetProcAddress(library_ntdll, "RtlSetCriticalSectionSpinCount");
	pSetCurrentConsoleFontEx = (void *)GetProcAddress(library, "SetCurrentConsoleFontEx");
	pSetCurrentDirectoryA = (void *)GetProcAddress(library, "SetCurrentDirectoryA");
	pSetCurrentDirectoryW = (void *)GetProcAddress(library, "SetCurrentDirectoryW");
	pSetDefaultCommConfigA = (void *)GetProcAddress(library, "SetDefaultCommConfigA");
	pSetDefaultCommConfigW = (void *)GetProcAddress(library, "SetDefaultCommConfigW");
	pSetDefaultDllDirectories = (void *)GetProcAddress(library, "SetDefaultDllDirectories");
	pSetDllDirectoryA = (void *)GetProcAddress(library, "SetDllDirectoryA");
	pSetDllDirectoryW = (void *)GetProcAddress(library, "SetDllDirectoryW");
	pSetEndOfFile = (void *)GetProcAddress(library, "SetEndOfFile");
	pextSetEndOfFile = (void *)GetProcAddress(library_kernelbase, "SetEndOfFile");
	pSetEnvironmentVariableA = (void *)GetProcAddress(library, "SetEnvironmentVariableA");
	pextSetEnvironmentVariableA = (void *)GetProcAddress(library_kernelbase, "SetEnvironmentVariableA");
	pSetEnvironmentVariableW = (void *)GetProcAddress(library, "SetEnvironmentVariableW");
	pextSetEnvironmentVariableW = (void *)GetProcAddress(library_kernelbase, "SetEnvironmentVariableW");
	pSetErrorMode = (void *)GetProcAddress(library, "SetErrorMode");
	pextSetErrorMode = (void *)GetProcAddress(library_kernelbase, "SetErrorMode");
	pSetEvent = (void *)GetProcAddress(library, "SetEvent");
	pextSetEvent = (void *)GetProcAddress(library_kernelbase, "SetEvent");
	pSetEventWhenCallbackReturns = (void *)GetProcAddress(library, "SetEventWhenCallbackReturns");
	pextSetEventWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackSetEventOnCompletion");
	pSetFileApisToANSI = (void *)GetProcAddress(library, "SetFileApisToANSI");
	pextSetFileApisToANSI = (void *)GetProcAddress(library_kernelbase, "SetFileApisToANSI");
	pSetFileApisToOEM = (void *)GetProcAddress(library, "SetFileApisToOEM");
	pextSetFileApisToOEM = (void *)GetProcAddress(library_kernelbase, "SetFileApisToOEM");
	pSetFileAttributesA = (void *)GetProcAddress(library, "SetFileAttributesA");
	pextSetFileAttributesA = (void *)GetProcAddress(library_kernelbase, "SetFileAttributesA");
	pSetFileAttributesW = (void *)GetProcAddress(library, "SetFileAttributesW");
	pextSetFileAttributesW = (void *)GetProcAddress(library_kernelbase, "SetFileAttributesW");
	pSetFileCompletionNotificationModes = (void *)GetProcAddress(library, "SetFileCompletionNotificationModes");
	pSetFileInformationByHandle = (void *)GetProcAddress(library, "SetFileInformationByHandle");
	pextSetFileInformationByHandle = (void *)GetProcAddress(library_kernelbase, "SetFileInformationByHandle");
	pSetFilePointer = (void *)GetProcAddress(library, "SetFilePointer");
	pextSetFilePointer = (void *)GetProcAddress(library_kernelbase, "SetFilePointer");
	pSetFilePointerEx = (void *)GetProcAddress(library, "SetFilePointerEx");
	pextSetFilePointerEx = (void *)GetProcAddress(library_kernelbase, "SetFilePointerEx");
	pSetFileTime = (void *)GetProcAddress(library, "SetFileTime");
	pextSetFileTime = (void *)GetProcAddress(library_kernelbase, "SetFileTime");
	pSetFileValidData = (void *)GetProcAddress(library, "SetFileValidData");
	pextSetFileValidData = (void *)GetProcAddress(library_kernelbase, "SetFileValidData");
	pSetHandleContext = (void *)GetProcAddress(library, "SetHandleContext");
	pSetHandleCount = (void *)GetProcAddress(library, "SetHandleCount");
	pSetHandleInformation = (void *)GetProcAddress(library, "SetHandleInformation");
	pSetInformationJobObject = (void *)GetProcAddress(library, "SetInformationJobObject");
	pSetLocalTime = (void *)GetProcAddress(library, "SetLocalTime");
	pSetLocaleInfoA = (void *)GetProcAddress(library, "SetLocaleInfoA");
	pSetLocaleInfoW = (void *)GetProcAddress(library, "SetLocaleInfoW");
	pSetMailslotInfo = (void *)GetProcAddress(library, "SetMailslotInfo");
	pSetNamedPipeHandleState = (void *)GetProcAddress(library, "SetNamedPipeHandleState");
	pextSetNamedPipeHandleState = (void *)GetProcAddress(library_kernelbase, "SetNamedPipeHandleState");
	pSetPriorityClass = (void *)GetProcAddress(library, "SetPriorityClass");
	pextSetPriorityClass = (void *)GetProcAddress(library_kernelbase, "SetPriorityClass");
	pSetProcessAffinityMask = (void *)GetProcAddress(library, "SetProcessAffinityMask");
	pSetProcessAffinityUpdateMode = (void *)GetProcAddress(library, "SetProcessAffinityUpdateMode");
	pextSetProcessAffinityUpdateMode = (void *)GetProcAddress(library_kernelbase, "SetProcessAffinityUpdateMode");
	pSetProcessDEPPolicy = (void *)GetProcAddress(library, "SetProcessDEPPolicy");
	pSetProcessMitigationPolicy = (void *)GetProcAddress(library, "SetProcessMitigationPolicy");
	pextSetProcessMitigationPolicy = (void *)GetProcAddress(library_kernelbase, "SetProcessMitigationPolicy");
	pSetProcessPreferredUILanguages = (void *)GetProcAddress(library, "SetProcessPreferredUILanguages");
	pSetProcessPriorityBoost = (void *)GetProcAddress(library, "SetProcessPriorityBoost");
	pextSetProcessPriorityBoost = (void *)GetProcAddress(library_kernelbase, "SetProcessPriorityBoost");
	pSetProcessShutdownParameters = (void *)GetProcAddress(library, "SetProcessShutdownParameters");
	pextSetProcessShutdownParameters = (void *)GetProcAddress(library_kernelbase, "SetProcessShutdownParameters");
	pSetProcessWorkingSetSize = (void *)GetProcAddress(library, "SetProcessWorkingSetSize");
	pSetProcessWorkingSetSizeEx = (void *)GetProcAddress(library, "SetProcessWorkingSetSizeEx");
	pextSetProcessWorkingSetSizeEx = (void *)GetProcAddress(library_kernelbase, "SetProcessWorkingSetSizeEx");
	pSetSearchPathMode = (void *)GetProcAddress(library, "SetSearchPathMode");
	pSetStdHandle = (void *)GetProcAddress(library, "SetStdHandle");
	pextSetStdHandle = (void *)GetProcAddress(library_kernelbase, "SetStdHandle");
	pSetStdHandleEx = (void *)GetProcAddress(library, "SetStdHandleEx");
	pextSetStdHandleEx = (void *)GetProcAddress(library_kernelbase, "SetStdHandleEx");
	pSetSystemFileCacheSize = (void *)GetProcAddress(library, "SetSystemFileCacheSize");
	pSetSystemPowerState = (void *)GetProcAddress(library, "SetSystemPowerState");
	pSetSystemTime = (void *)GetProcAddress(library, "SetSystemTime");
	pSetSystemTimeAdjustment = (void *)GetProcAddress(library, "SetSystemTimeAdjustment");
	pSetTapeParameters = (void *)GetProcAddress(library, "SetTapeParameters");
	pSetTapePosition = (void *)GetProcAddress(library, "SetTapePosition");
	pSetTermsrvAppInstallMode = (void *)GetProcAddress(library, "SetTermsrvAppInstallMode");
	pSetThreadAffinityMask = (void *)GetProcAddress(library, "SetThreadAffinityMask");
	pSetThreadContext = (void *)GetProcAddress(library, "SetThreadContext");
	pextSetThreadContext = (void *)GetProcAddress(library_kernelbase, "SetThreadContext");
	pSetThreadErrorMode = (void *)GetProcAddress(library, "SetThreadErrorMode");
	pextSetThreadErrorMode = (void *)GetProcAddress(library_kernelbase, "SetThreadErrorMode");
	pSetThreadExecutionState = (void *)GetProcAddress(library, "SetThreadExecutionState");
	pSetThreadGroupAffinity = (void *)GetProcAddress(library, "SetThreadGroupAffinity");
	pextSetThreadGroupAffinity = (void *)GetProcAddress(library_kernelbase, "SetThreadGroupAffinity");
	pSetThreadIdealProcessor = (void *)GetProcAddress(library, "SetThreadIdealProcessor");
	pextSetThreadIdealProcessor = (void *)GetProcAddress(library_kernelbase, "SetThreadIdealProcessor");
	pSetThreadIdealProcessorEx = (void *)GetProcAddress(library, "SetThreadIdealProcessorEx");
	pextSetThreadIdealProcessorEx = (void *)GetProcAddress(library_kernelbase, "SetThreadIdealProcessorEx");
	pSetThreadLocale = (void *)GetProcAddress(library, "SetThreadLocale");
	pSetThreadPreferredUILanguages = (void *)GetProcAddress(library, "SetThreadPreferredUILanguages");
	pSetThreadPriority = (void *)GetProcAddress(library, "SetThreadPriority");
	pextSetThreadPriority = (void *)GetProcAddress(library_kernelbase, "SetThreadPriority");
	pSetThreadPriorityBoost = (void *)GetProcAddress(library, "SetThreadPriorityBoost");
	pextSetThreadPriorityBoost = (void *)GetProcAddress(library_kernelbase, "SetThreadPriorityBoost");
	pSetThreadStackGuarantee = (void *)GetProcAddress(library, "SetThreadStackGuarantee");
	pextSetThreadStackGuarantee = (void *)GetProcAddress(library_kernelbase, "SetThreadStackGuarantee");
	pSetThreadUILanguage = (void *)GetProcAddress(library, "SetThreadUILanguage");
	pSetThreadpoolThreadMaximum = (void *)GetProcAddress(library, "SetThreadpoolThreadMaximum");
	pextSetThreadpoolThreadMaximum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMaxThreads");
	pSetThreadpoolThreadMinimum = (void *)GetProcAddress(library, "SetThreadpoolThreadMinimum");
	pextSetThreadpoolThreadMinimum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMinThreads");
	pSetThreadpoolTimer = (void *)GetProcAddress(library, "SetThreadpoolTimer");
	pextSetThreadpoolTimer = (void *)GetProcAddress(library_ntdll, "TpSetTimer");
	pSetThreadpoolWait = (void *)GetProcAddress(library, "SetThreadpoolWait");
	pextSetThreadpoolWait = (void *)GetProcAddress(library_ntdll, "TpSetWait");
	pSetTimeZoneInformation = (void *)GetProcAddress(library, "SetTimeZoneInformation");
	pSetUmsThreadInformation = (void *)GetProcAddress(library, "SetUmsThreadInformation");
	pSetUnhandledExceptionFilter = (void *)GetProcAddress(library, "SetUnhandledExceptionFilter");
	pextSetUnhandledExceptionFilter = (void *)GetProcAddress(library_kernelbase, "SetUnhandledExceptionFilter");
	pSetUserGeoID = (void *)GetProcAddress(library, "SetUserGeoID");
	pSetVolumeLabelA = (void *)GetProcAddress(library, "SetVolumeLabelA");
	pSetVolumeLabelW = (void *)GetProcAddress(library, "SetVolumeLabelW");
	pSetVolumeMountPointA = (void *)GetProcAddress(library, "SetVolumeMountPointA");
	pSetVolumeMountPointW = (void *)GetProcAddress(library, "SetVolumeMountPointW");
	pSetWaitableTimer = (void *)GetProcAddress(library, "SetWaitableTimer");
	pextSetWaitableTimer = (void *)GetProcAddress(library_kernelbase, "SetWaitableTimer");
	pSetWaitableTimerEx = (void *)GetProcAddress(library, "SetWaitableTimerEx");
	pextSetWaitableTimerEx = (void *)GetProcAddress(library_kernelbase, "SetWaitableTimerEx");
	pSetupComm = (void *)GetProcAddress(library, "SetupComm");
	pextSetupComm = (void *)GetProcAddress(library_kernelbase, "SetupComm");
	pSignalObjectAndWait = (void *)GetProcAddress(library, "SignalObjectAndWait");
	pextSignalObjectAndWait = (void *)GetProcAddress(library_kernelbase, "SignalObjectAndWait");
	pSizeofResource = (void *)GetProcAddress(library, "SizeofResource");
	pextSizeofResource = (void *)GetProcAddress(library_kernelbase, "SizeofResource");
	pSleep = (void *)GetProcAddress(library, "Sleep");
	pextSleep = (void *)GetProcAddress(library_kernelbase, "Sleep");
	pSleepConditionVariableCS = (void *)GetProcAddress(library, "SleepConditionVariableCS");
	pextSleepConditionVariableCS = (void *)GetProcAddress(library_kernelbase, "SleepConditionVariableCS");
	pSleepConditionVariableSRW = (void *)GetProcAddress(library, "SleepConditionVariableSRW");
	pextSleepConditionVariableSRW = (void *)GetProcAddress(library_kernelbase, "SleepConditionVariableSRW");
	pSleepEx = (void *)GetProcAddress(library, "SleepEx");
	pextSleepEx = (void *)GetProcAddress(library_kernelbase, "SleepEx");
	pSubmitThreadpoolWork = (void *)GetProcAddress(library, "SubmitThreadpoolWork");
	pextSubmitThreadpoolWork = (void *)GetProcAddress(library_ntdll, "TpPostWork");
	pSuspendThread = (void *)GetProcAddress(library, "SuspendThread");
	pextSuspendThread = (void *)GetProcAddress(library_kernelbase, "SuspendThread");
	pSwitchToFiber = (void *)GetProcAddress(library, "SwitchToFiber");
	pextSwitchToFiber = (void *)GetProcAddress(library_kernelbase, "SwitchToFiber");
	pSwitchToThread = (void *)GetProcAddress(library, "SwitchToThread");
	pextSwitchToThread = (void *)GetProcAddress(library_kernelbase, "SwitchToThread");
	pSystemTimeToFileTime = (void *)GetProcAddress(library, "SystemTimeToFileTime");
	pSystemTimeToTzSpecificLocalTime = (void *)GetProcAddress(library, "SystemTimeToTzSpecificLocalTime");
	pTerminateJobObject = (void *)GetProcAddress(library, "TerminateJobObject");
	pTerminateProcess = (void *)GetProcAddress(library, "TerminateProcess");
	pextTerminateProcess = (void *)GetProcAddress(library_kernelbase, "TerminateProcess");
	pTerminateThread = (void *)GetProcAddress(library, "TerminateThread");
	pextTerminateThread = (void *)GetProcAddress(library_kernelbase, "TerminateThread");
	pTermsrvAppInstallMode = (void *)GetProcAddress(library, "TermsrvAppInstallMode");
	pThread32First = (void *)GetProcAddress(library, "Thread32First");
	pThread32Next = (void *)GetProcAddress(library, "Thread32Next");
	pTlsAlloc = (void *)GetProcAddress(library, "TlsAlloc");
	pextTlsAlloc = (void *)GetProcAddress(library_kernelbase, "TlsAlloc");
	pTlsFree = (void *)GetProcAddress(library, "TlsFree");
	pextTlsFree = (void *)GetProcAddress(library_kernelbase, "TlsFree");
	pTlsGetValue = (void *)GetProcAddress(library, "TlsGetValue");
	pextTlsGetValue = (void *)GetProcAddress(library_kernelbase, "TlsGetValue");
	pTlsSetValue = (void *)GetProcAddress(library, "TlsSetValue");
	pextTlsSetValue = (void *)GetProcAddress(library_kernelbase, "TlsSetValue");
	pToolhelp32ReadProcessMemory = (void *)GetProcAddress(library, "Toolhelp32ReadProcessMemory");
	pTransactNamedPipe = (void *)GetProcAddress(library, "TransactNamedPipe");
	pextTransactNamedPipe = (void *)GetProcAddress(library_kernelbase, "TransactNamedPipe");
	pTransmitCommChar = (void *)GetProcAddress(library, "TransmitCommChar");
	pextTransmitCommChar = (void *)GetProcAddress(library_kernelbase, "TransmitCommChar");
	pTryAcquireSRWLockExclusive = (void *)GetProcAddress(library, "TryAcquireSRWLockExclusive");
	pextTryAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockExclusive");
	pTryAcquireSRWLockShared = (void *)GetProcAddress(library, "TryAcquireSRWLockShared");
	pextTryAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockShared");
	pTryEnterCriticalSection = (void *)GetProcAddress(library, "TryEnterCriticalSection");
	pextTryEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlTryEnterCriticalSection");
	pTrySubmitThreadpoolCallback = (void *)GetProcAddress(library, "TrySubmitThreadpoolCallback");
	pextTrySubmitThreadpoolCallback = (void *)GetProcAddress(library_kernelbase, "TrySubmitThreadpoolCallback");
	pTzSpecificLocalTimeToSystemTime = (void *)GetProcAddress(library, "TzSpecificLocalTimeToSystemTime");
	pUmsThreadYield = (void *)GetProcAddress(library, "UmsThreadYield");
	pUnhandledExceptionFilter = (void *)GetProcAddress(library, "UnhandledExceptionFilter");
	pextUnhandledExceptionFilter = (void *)GetProcAddress(library_kernelbase, "UnhandledExceptionFilter");
	pUninitializeCriticalSection = (void *)GetProcAddress(library, "UninitializeCriticalSection");
	pUnlockFile = (void *)GetProcAddress(library, "UnlockFile");
	pextUnlockFile = (void *)GetProcAddress(library_kernelbase, "UnlockFile");
	pUnlockFileEx = (void *)GetProcAddress(library, "UnlockFileEx");
	pextUnlockFileEx = (void *)GetProcAddress(library_kernelbase, "UnlockFileEx");
	pUnmapViewOfFile = (void *)GetProcAddress(library, "UnmapViewOfFile");
	pextUnmapViewOfFile = (void *)GetProcAddress(library_kernelbase, "UnmapViewOfFile");
	pUnregisterApplicationRestart = (void *)GetProcAddress(library, "UnregisterApplicationRestart");
	pUnregisterWait = (void *)GetProcAddress(library, "UnregisterWait");
	pUnregisterWaitEx = (void *)GetProcAddress(library, "UnregisterWaitEx");
	pextUnregisterWaitEx = (void *)GetProcAddress(library_kernelbase, "UnregisterWaitEx");
	pUpdateProcThreadAttribute = (void *)GetProcAddress(library, "UpdateProcThreadAttribute");
	pextUpdateProcThreadAttribute = (void *)GetProcAddress(library_kernelbase, "UpdateProcThreadAttribute");
	pUpdateResourceA = (void *)GetProcAddress(library, "UpdateResourceA");
	pUpdateResourceW = (void *)GetProcAddress(library, "UpdateResourceW");
	pVerLanguageNameA = (void *)GetProcAddress(library, "VerLanguageNameA");
	pVerLanguageNameW = (void *)GetProcAddress(library, "VerLanguageNameW");
	pVerSetConditionMask = (void *)GetProcAddress(library, "VerSetConditionMask");
	pextVerSetConditionMask = (void *)GetProcAddress(library_ntdll, "VerSetConditionMask");
	pVerifyConsoleIoHandle = (void *)GetProcAddress(library, "VerifyConsoleIoHandle");
	pVerifyVersionInfoA = (void *)GetProcAddress(library, "VerifyVersionInfoA");
	pVerifyVersionInfoW = (void *)GetProcAddress(library, "VerifyVersionInfoW");
	pVirtualAlloc = (void *)GetProcAddress(library, "VirtualAlloc");
	pextVirtualAlloc = (void *)GetProcAddress(library_kernelbase, "VirtualAlloc");
	pVirtualAllocEx = (void *)GetProcAddress(library, "VirtualAllocEx");
	pextVirtualAllocEx = (void *)GetProcAddress(library_kernelbase, "VirtualAllocEx");
	pVirtualAllocExNuma = (void *)GetProcAddress(library, "VirtualAllocExNuma");
	pextVirtualAllocExNuma = (void *)GetProcAddress(library_kernelbase, "VirtualAllocExNuma");
	pVirtualFree = (void *)GetProcAddress(library, "VirtualFree");
	pextVirtualFree = (void *)GetProcAddress(library_kernelbase, "VirtualFree");
	pVirtualFreeEx = (void *)GetProcAddress(library, "VirtualFreeEx");
	pextVirtualFreeEx = (void *)GetProcAddress(library_kernelbase, "VirtualFreeEx");
	pVirtualLock = (void *)GetProcAddress(library, "VirtualLock");
	pextVirtualLock = (void *)GetProcAddress(library_kernelbase, "VirtualLock");
	pVirtualProtect = (void *)GetProcAddress(library, "VirtualProtect");
	pextVirtualProtect = (void *)GetProcAddress(library_kernelbase, "VirtualProtect");
	pVirtualProtectEx = (void *)GetProcAddress(library, "VirtualProtectEx");
	pextVirtualProtectEx = (void *)GetProcAddress(library_kernelbase, "VirtualProtectEx");
	pVirtualQuery = (void *)GetProcAddress(library, "VirtualQuery");
	pextVirtualQuery = (void *)GetProcAddress(library_kernelbase, "VirtualQuery");
	pVirtualQueryEx = (void *)GetProcAddress(library, "VirtualQueryEx");
	pextVirtualQueryEx = (void *)GetProcAddress(library_kernelbase, "VirtualQueryEx");
	pVirtualUnlock = (void *)GetProcAddress(library, "VirtualUnlock");
	pextVirtualUnlock = (void *)GetProcAddress(library_kernelbase, "VirtualUnlock");
	pWTSGetActiveConsoleSessionId = (void *)GetProcAddress(library, "WTSGetActiveConsoleSessionId");
	pWaitCommEvent = (void *)GetProcAddress(library, "WaitCommEvent");
	pextWaitCommEvent = (void *)GetProcAddress(library_kernelbase, "WaitCommEvent");
	pWaitForDebugEvent = (void *)GetProcAddress(library, "WaitForDebugEvent");
	pextWaitForDebugEvent = (void *)GetProcAddress(library_kernelbase, "WaitForDebugEvent");
	pWaitForMultipleObjects = (void *)GetProcAddress(library, "WaitForMultipleObjects");
	pextWaitForMultipleObjects = (void *)GetProcAddress(library_kernelbase, "WaitForMultipleObjects");
	pWaitForMultipleObjectsEx = (void *)GetProcAddress(library, "WaitForMultipleObjectsEx");
	pextWaitForMultipleObjectsEx = (void *)GetProcAddress(library_kernelbase, "WaitForMultipleObjectsEx");
	pWaitForSingleObject = (void *)GetProcAddress(library, "WaitForSingleObject");
	pextWaitForSingleObject = (void *)GetProcAddress(library_kernelbase, "WaitForSingleObject");
	pWaitForSingleObjectEx = (void *)GetProcAddress(library, "WaitForSingleObjectEx");
	pextWaitForSingleObjectEx = (void *)GetProcAddress(library_kernelbase, "WaitForSingleObjectEx");
	pWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolTimerCallbacks");
	pextWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForTimer");
	pWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWaitCallbacks");
	pextWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWait");
	pWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWorkCallbacks");
	pextWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWork");
	pWaitNamedPipeA = (void *)GetProcAddress(library, "WaitNamedPipeA");
	pWaitNamedPipeW = (void *)GetProcAddress(library, "WaitNamedPipeW");
	pextWaitNamedPipeW = (void *)GetProcAddress(library_kernelbase, "WaitNamedPipeW");
	pWakeAllConditionVariable = (void *)GetProcAddress(library, "WakeAllConditionVariable");
	pextWakeAllConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeAllConditionVariable");
	pWakeConditionVariable = (void *)GetProcAddress(library, "WakeConditionVariable");
	pextWakeConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeConditionVariable");
	pWerRegisterFile = (void *)GetProcAddress(library, "WerRegisterFile");
	pWerRegisterMemoryBlock = (void *)GetProcAddress(library, "WerRegisterMemoryBlock");
	pWerRegisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerRegisterRuntimeExceptionModule");
	pWerSetFlags = (void *)GetProcAddress(library, "WerSetFlags");
	pWerUnregisterMemoryBlock = (void *)GetProcAddress(library, "WerUnregisterMemoryBlock");
	pWerUnregisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerUnregisterRuntimeExceptionModule");
	pWideCharToMultiByte = (void *)GetProcAddress(library, "WideCharToMultiByte");
	pWinExec = (void *)GetProcAddress(library, "WinExec");
	pWow64EnableWow64FsRedirection = (void *)GetProcAddress(library, "Wow64EnableWow64FsRedirection");
	pWow64DisableWow64FsRedirection = (void *)GetProcAddress(library, "Wow64DisableWow64FsRedirection");
	pextWow64DisableWow64FsRedirection = (void *)GetProcAddress(library_kernelbase, "Wow64DisableWow64FsRedirection");
	pWow64GetThreadContext = (void *)GetProcAddress(library, "Wow64GetThreadContext");
	pWow64RevertWow64FsRedirection = (void *)GetProcAddress(library, "Wow64RevertWow64FsRedirection");
	pextWow64RevertWow64FsRedirection = (void *)GetProcAddress(library_kernelbase, "Wow64RevertWow64FsRedirection");
	pWow64SetThreadContext = (void *)GetProcAddress(library, "Wow64SetThreadContext");
	pWriteConsoleA = (void *)GetProcAddress(library, "WriteConsoleA");
	pextWriteConsoleA = (void *)GetProcAddress(library_kernelbase, "WriteConsoleA");
	pWriteConsoleInputA = (void *)GetProcAddress(library, "WriteConsoleInputA");
	pextWriteConsoleInputA = (void *)GetProcAddress(library_kernelbase, "WriteConsoleInputA");
	pWriteConsoleInputW = (void *)GetProcAddress(library, "WriteConsoleInputW");
	pextWriteConsoleInputW = (void *)GetProcAddress(library_kernelbase, "WriteConsoleInputW");
	pWriteConsoleOutputA = (void *)GetProcAddress(library, "WriteConsoleOutputA");
	pextWriteConsoleOutputA = (void *)GetProcAddress(library_kernelbase, "WriteConsoleOutputA");
	pWriteConsoleOutputAttribute = (void *)GetProcAddress(library, "WriteConsoleOutputAttribute");
	pextWriteConsoleOutputAttribute = (void *)GetProcAddress(library_kernelbase, "WriteConsoleOutputAttribute");
	pWriteConsoleOutputCharacterA = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterA");
	pextWriteConsoleOutputCharacterA = (void *)GetProcAddress(library_kernelbase, "WriteConsoleOutputCharacterA");
	pWriteConsoleOutputCharacterW = (void *)GetProcAddress(library, "WriteConsoleOutputCharacterW");
	pextWriteConsoleOutputCharacterW = (void *)GetProcAddress(library_kernelbase, "WriteConsoleOutputCharacterW");
	pWriteConsoleOutputW = (void *)GetProcAddress(library, "WriteConsoleOutputW");
	pextWriteConsoleOutputW = (void *)GetProcAddress(library_kernelbase, "WriteConsoleOutputW");
	pWriteConsoleW = (void *)GetProcAddress(library, "WriteConsoleW");
	pWriteFile = (void *)GetProcAddress(library, "WriteFile");
	pextWriteFile = (void *)GetProcAddress(library_kernelbase, "WriteFile");
	pWriteFileEx = (void *)GetProcAddress(library, "WriteFileEx");
	pextWriteFileEx = (void *)GetProcAddress(library_kernelbase, "WriteFileEx");
	pWriteFileGather = (void *)GetProcAddress(library, "WriteFileGather");
	pextWriteFileGather = (void *)GetProcAddress(library_kernelbase, "WriteFileGather");
	pWritePrivateProfileSectionA = (void *)GetProcAddress(library, "WritePrivateProfileSectionA");
	pWritePrivateProfileSectionW = (void *)GetProcAddress(library, "WritePrivateProfileSectionW");
	pWritePrivateProfileStringA = (void *)GetProcAddress(library, "WritePrivateProfileStringA");
	pWritePrivateProfileStringW = (void *)GetProcAddress(library, "WritePrivateProfileStringW");
	pWritePrivateProfileStructA = (void *)GetProcAddress(library, "WritePrivateProfileStructA");
	pWritePrivateProfileStructW = (void *)GetProcAddress(library, "WritePrivateProfileStructW");
	pWriteProcessMemory = (void *)GetProcAddress(library, "WriteProcessMemory");
	pextWriteProcessMemory = (void *)GetProcAddress(library_kernelbase, "WriteProcessMemory");
	pWriteProfileSectionA = (void *)GetProcAddress(library, "WriteProfileSectionA");
	pWriteProfileSectionW = (void *)GetProcAddress(library, "WriteProfileSectionW");
	pWriteProfileStringA = (void *)GetProcAddress(library, "WriteProfileStringA");
	pWriteProfileStringW = (void *)GetProcAddress(library, "WriteProfileStringW");
	pWriteTapemark = (void *)GetProcAddress(library, "WriteTapemark");
	pZombifyActCtx = (void *)GetProcAddress(library, "ZombifyActCtx");
	pextZombifyActCtx = (void *)GetProcAddress(library_kernelbase, "ZombifyActCtx");
	p_hread = (void *)GetProcAddress(library, "_hread");
	p_hwrite = (void *)GetProcAddress(library, "_hwrite");
	p_lclose = (void *)GetProcAddress(library, "_lclose");
	p_lcreat = (void *)GetProcAddress(library, "_lcreat");
	p_llseek = (void *)GetProcAddress(library, "_llseek");
	p_lopen = (void *)GetProcAddress(library, "_lopen");
	p_lread = (void *)GetProcAddress(library, "_lread");
	p_lwrite = (void *)GetProcAddress(library, "_lwrite");
	plstrcatA = (void *)GetProcAddress(library, "lstrcatA");
	plstrcatW = (void *)GetProcAddress(library, "lstrcatW");
	plstrcmp = (void *)GetProcAddress(library, "lstrcmp");
	pextlstrcmp = (void *)GetProcAddress(library_kernelbase, "lstrcmp");
	plstrcmpA = (void *)GetProcAddress(library, "lstrcmpA");
	pextlstrcmpA = (void *)GetProcAddress(library_kernelbase, "lstrcmpA");
	plstrcmpW = (void *)GetProcAddress(library, "lstrcmpW");
	pextlstrcmpW = (void *)GetProcAddress(library_kernelbase, "lstrcmpW");
	plstrcmpi = (void *)GetProcAddress(library, "lstrcmpi");
	pextlstrcmpi = (void *)GetProcAddress(library_kernelbase, "lstrcmpi");
	plstrcmpiA = (void *)GetProcAddress(library, "lstrcmpiA");
	pextlstrcmpiA = (void *)GetProcAddress(library_kernelbase, "lstrcmpiA");
	plstrcmpiW = (void *)GetProcAddress(library, "lstrcmpiW");
	pextlstrcmpiW = (void *)GetProcAddress(library_kernelbase, "lstrcmpiW");
	plstrcpyA = (void *)GetProcAddress(library, "lstrcpyA");
	plstrcpyW = (void *)GetProcAddress(library, "lstrcpyW");
	plstrcpyn = (void *)GetProcAddress(library, "lstrcpyn");
	pextlstrcpyn = (void *)GetProcAddress(library_kernelbase, "lstrcpyn");
	plstrcpynA = (void *)GetProcAddress(library, "lstrcpynA");
	pextlstrcpynA = (void *)GetProcAddress(library_kernelbase, "lstrcpynA");
	plstrcpynW = (void *)GetProcAddress(library, "lstrcpynW");
	pextlstrcpynW = (void *)GetProcAddress(library_kernelbase, "lstrcpynW");
	plstrlen = (void *)GetProcAddress(library, "lstrlen");
	pextlstrlen = (void *)GetProcAddress(library_kernelbase, "lstrlen");
	plstrlenA = (void *)GetProcAddress(library, "lstrlenA");
	pextlstrlenA = (void *)GetProcAddress(library_kernelbase, "lstrlenA");
	plstrlenW = (void *)GetProcAddress(library, "lstrlenW");
	pextlstrlenW = (void *)GetProcAddress(library_kernelbase, "lstrlenW");
	pwine_get_unix_file_name = (void *)GetProcAddress(library, "wine_get_unix_file_name");
	pwine_get_dos_file_name = (void *)GetProcAddress(library, "wine_get_dos_file_name");
	p__wine_kernel_init = (void *)GetProcAddress(library, "__wine_kernel_init");
	initialized = TRUE;
}

void* wine_thunk_get_for_kernel32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pAcquireSRWLockExclusive && func != pextAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextAcquireSRWLockExclusive);
	if (func == pAcquireSRWLockShared && func != pextAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextAcquireSRWLockShared);
	if (func == pActivateActCtx && func != pextActivateActCtx)
		return wine_thunk_get_for_any(pextActivateActCtx);
	if (func == pAddAtomA)
		return wine32a_kernel32_AddAtomA;
	if (func == pAddAtomW)
		return wine32a_kernel32_AddAtomW;
	if (func == pAddConsoleAliasA)
		return wine32a_kernel32_AddConsoleAliasA;
	if (func == pAddConsoleAliasW)
		return wine32a_kernel32_AddConsoleAliasW;
	if (func == pAddDllDirectory)
		return wine32a_kernel32_AddDllDirectory;
	if (func == pAddRefActCtx && func != pextAddRefActCtx)
		return wine_thunk_get_for_any(pextAddRefActCtx);
	if (func == pAddVectoredContinueHandler && func != pextAddVectoredContinueHandler)
		return wine_thunk_get_for_any(pextAddVectoredContinueHandler);
	if (func == pAddVectoredExceptionHandler && func != pextAddVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextAddVectoredExceptionHandler);
	if (func == pAllocConsole)
		return wine32a_kernel32_AllocConsole;
	if (func == pAllocateUserPhysicalPages)
		return wine32a_kernel32_AllocateUserPhysicalPages;
	if (func == pApplicationRecoveryFinished)
		return wine32a_kernel32_ApplicationRecoveryFinished;
	if (func == pApplicationRecoveryInProgress)
		return wine32a_kernel32_ApplicationRecoveryInProgress;
	if (func == pAreFileApisANSI && func != pextAreFileApisANSI)
		return wine_thunk_get_for_any(pextAreFileApisANSI);
	if (func == pAssignProcessToJobObject)
		return wine32a_kernel32_AssignProcessToJobObject;
	if (func == pAttachConsole && func != pextAttachConsole)
		return wine_thunk_get_for_any(pextAttachConsole);
	if (func == pBackupRead)
		return wine32a_kernel32_BackupRead;
	if (func == pBackupSeek)
		return wine32a_kernel32_BackupSeek;
	if (func == pBackupWrite)
		return wine32a_kernel32_BackupWrite;
	if (func == pBaseFlushAppcompatCache)
		return wine32a_kernel32_BaseFlushAppcompatCache;
	if (func == pBaseGetNamedObjectDirectory && func != pextBaseGetNamedObjectDirectory)
		return wine_thunk_get_for_any(pextBaseGetNamedObjectDirectory);
	if (func == pBeep)
		return wine32a_kernel32_Beep;
	if (func == pBeginUpdateResourceA)
		return wine32a_kernel32_BeginUpdateResourceA;
	if (func == pBeginUpdateResourceW)
		return wine32a_kernel32_BeginUpdateResourceW;
	if (func == pBindIoCompletionCallback)
		return wine32a_kernel32_BindIoCompletionCallback;
	if (func == pBuildCommDCBA)
		return wine32a_kernel32_BuildCommDCBA;
	if (func == pBuildCommDCBAndTimeoutsA)
		return wine32a_kernel32_BuildCommDCBAndTimeoutsA;
	if (func == pBuildCommDCBAndTimeoutsW)
		return wine32a_kernel32_BuildCommDCBAndTimeoutsW;
	if (func == pBuildCommDCBW)
		return wine32a_kernel32_BuildCommDCBW;
	if (func == pCallbackMayRunLong && func != pextCallbackMayRunLong)
		return wine_thunk_get_for_any(pextCallbackMayRunLong);
	if (func == pCallNamedPipeA)
		return wine32a_kernel32_CallNamedPipeA;
	if (func == pCallNamedPipeW && func != pextCallNamedPipeW)
		return wine_thunk_get_for_any(pextCallNamedPipeW);
	if (func == pCancelIo && func != pextCancelIo)
		return wine_thunk_get_for_any(pextCancelIo);
	if (func == pCancelIoEx && func != pextCancelIoEx)
		return wine_thunk_get_for_any(pextCancelIoEx);
	if (func == pCancelSynchronousIo && func != pextCancelSynchronousIo)
		return wine_thunk_get_for_any(pextCancelSynchronousIo);
	if (func == pCancelTimerQueueTimer)
		return wine32a_kernel32_CancelTimerQueueTimer;
	if (func == pCancelWaitableTimer && func != pextCancelWaitableTimer)
		return wine_thunk_get_for_any(pextCancelWaitableTimer);
	if (func == pChangeTimerQueueTimer && func != pextChangeTimerQueueTimer)
		return wine_thunk_get_for_any(pextChangeTimerQueueTimer);
	if (func == pCheckNameLegalDOS8Dot3A)
		return wine32a_kernel32_CheckNameLegalDOS8Dot3A;
	if (func == pCheckNameLegalDOS8Dot3W)
		return wine32a_kernel32_CheckNameLegalDOS8Dot3W;
	if (func == pCheckRemoteDebuggerPresent && func != pextCheckRemoteDebuggerPresent)
		return wine_thunk_get_for_any(pextCheckRemoteDebuggerPresent);
	if (func == pClearCommBreak && func != pextClearCommBreak)
		return wine_thunk_get_for_any(pextClearCommBreak);
	if (func == pClearCommError && func != pextClearCommError)
		return wine_thunk_get_for_any(pextClearCommError);
	if (func == pCloseConsoleHandle)
		return wine32a_kernel32_CloseConsoleHandle;
	if (func == pCloseHandle)
		return wine32a_kernel32_CloseHandle;
	if (func == pCloseProfileUserMapping)
		return wine32a_kernel32_CloseProfileUserMapping;
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
	if (func == pCmdBatNotification)
		return wine32a_kernel32_CmdBatNotification;
	if (func == pCommConfigDialogA)
		return wine32a_kernel32_CommConfigDialogA;
	if (func == pCommConfigDialogW)
		return wine32a_kernel32_CommConfigDialogW;
	if (func == pCompareFileTime)
		return wine32a_kernel32_CompareFileTime;
	if (func == pCompareStringA)
		return wine32a_kernel32_CompareStringA;
	if (func == pCompareStringW)
		return wine32a_kernel32_CompareStringW;
	if (func == pCompareStringEx)
		return wine32a_kernel32_CompareStringEx;
	if (func == pCompareStringOrdinal)
		return wine32a_kernel32_CompareStringOrdinal;
	if (func == pConnectNamedPipe && func != pextConnectNamedPipe)
		return wine_thunk_get_for_any(pextConnectNamedPipe);
	if (func == pContinueDebugEvent && func != pextContinueDebugEvent)
		return wine_thunk_get_for_any(pextContinueDebugEvent);
	if (func == pConvertDefaultLocale)
		return wine32a_kernel32_ConvertDefaultLocale;
	if (func == pConvertFiberToThread && func != pextConvertFiberToThread)
		return wine_thunk_get_for_any(pextConvertFiberToThread);
	if (func == pConvertThreadToFiber && func != pextConvertThreadToFiber)
		return wine_thunk_get_for_any(pextConvertThreadToFiber);
	if (func == pConvertThreadToFiberEx && func != pextConvertThreadToFiberEx)
		return wine_thunk_get_for_any(pextConvertThreadToFiberEx);
	if (func == pConvertToGlobalHandle)
		return wine32a_kernel32_ConvertToGlobalHandle;
	if (func == pCopyFileA)
		return wine32a_kernel32_CopyFileA;
	if (func == pCopyFileExA)
		return wine32a_kernel32_CopyFileExA;
	if (func == pCopyFileExW)
		return wine32a_kernel32_CopyFileExW;
	if (func == pCopyFileW)
		return wine32a_kernel32_CopyFileW;
	if (func == pCreateActCtxA)
		return wine32a_kernel32_CreateActCtxA;
	if (func == pCreateActCtxW && func != pextCreateActCtxW)
		return wine_thunk_get_for_any(pextCreateActCtxW);
	if (func == pCreateConsoleScreenBuffer && func != pextCreateConsoleScreenBuffer)
		return wine_thunk_get_for_any(pextCreateConsoleScreenBuffer);
	if (func == pCreateDirectoryA && func != pextCreateDirectoryA)
		return wine_thunk_get_for_any(pextCreateDirectoryA);
	if (func == pCreateDirectoryExA)
		return wine32a_kernel32_CreateDirectoryExA;
	if (func == pCreateDirectoryExW && func != pextCreateDirectoryExW)
		return wine_thunk_get_for_any(pextCreateDirectoryExW);
	if (func == pCreateDirectoryW && func != pextCreateDirectoryW)
		return wine_thunk_get_for_any(pextCreateDirectoryW);
	if (func == pCreateEventA && func != pextCreateEventA)
		return wine_thunk_get_for_any(pextCreateEventA);
	if (func == pCreateEventExA && func != pextCreateEventExA)
		return wine_thunk_get_for_any(pextCreateEventExA);
	if (func == pCreateEventExW && func != pextCreateEventExW)
		return wine_thunk_get_for_any(pextCreateEventExW);
	if (func == pCreateEventW && func != pextCreateEventW)
		return wine_thunk_get_for_any(pextCreateEventW);
	if (func == pCreateFiber && func != pextCreateFiber)
		return wine_thunk_get_for_any(pextCreateFiber);
	if (func == pCreateFiberEx && func != pextCreateFiberEx)
		return wine_thunk_get_for_any(pextCreateFiberEx);
	if (func == pCreateFile2 && func != pextCreateFile2)
		return wine_thunk_get_for_any(pextCreateFile2);
	if (func == pCreateFileA && func != pextCreateFileA)
		return wine_thunk_get_for_any(pextCreateFileA);
	if (func == pCreateFileMappingA)
		return wine32a_kernel32_CreateFileMappingA;
	if (func == pCreateFileMappingW && func != pextCreateFileMappingW)
		return wine_thunk_get_for_any(pextCreateFileMappingW);
	if (func == pCreateFileW && func != pextCreateFileW)
		return wine_thunk_get_for_any(pextCreateFileW);
	if (func == pCreateHardLinkA)
		return wine32a_kernel32_CreateHardLinkA;
	if (func == pCreateHardLinkTransactedA)
		return wine32a_kernel32_CreateHardLinkTransactedA;
	if (func == pCreateHardLinkTransactedW)
		return wine32a_kernel32_CreateHardLinkTransactedW;
	if (func == pCreateHardLinkW)
		return wine32a_kernel32_CreateHardLinkW;
	if (func == pCreateIoCompletionPort && func != pextCreateIoCompletionPort)
		return wine_thunk_get_for_any(pextCreateIoCompletionPort);
	if (func == pCreateJobObjectA)
		return wine32a_kernel32_CreateJobObjectA;
	if (func == pCreateJobObjectW)
		return wine32a_kernel32_CreateJobObjectW;
	if (func == pCreateMailslotA)
		return wine32a_kernel32_CreateMailslotA;
	if (func == pCreateMailslotW)
		return wine32a_kernel32_CreateMailslotW;
	if (func == pCreateMemoryResourceNotification && func != pextCreateMemoryResourceNotification)
		return wine_thunk_get_for_any(pextCreateMemoryResourceNotification);
	if (func == pCreateMutexA && func != pextCreateMutexA)
		return wine_thunk_get_for_any(pextCreateMutexA);
	if (func == pCreateMutexExA && func != pextCreateMutexExA)
		return wine_thunk_get_for_any(pextCreateMutexExA);
	if (func == pCreateMutexExW && func != pextCreateMutexExW)
		return wine_thunk_get_for_any(pextCreateMutexExW);
	if (func == pCreateMutexW && func != pextCreateMutexW)
		return wine_thunk_get_for_any(pextCreateMutexW);
	if (func == pCreateNamedPipeA)
		return wine32a_kernel32_CreateNamedPipeA;
	if (func == pCreateNamedPipeW && func != pextCreateNamedPipeW)
		return wine_thunk_get_for_any(pextCreateNamedPipeW);
	if (func == pCreatePipe)
		return wine32a_kernel32_CreatePipe;
	if (func == pCreateProcessA)
		return wine32a_kernel32_CreateProcessA;
	if (func == pCreateProcessAsUserA)
		return wine32a_kernel32_CreateProcessAsUserA;
	if (func == pCreateProcessAsUserW)
		return wine32a_kernel32_CreateProcessAsUserW;
	if (func == pCreateProcessInternalA)
		return wine32a_kernel32_CreateProcessInternalA;
	if (func == pCreateProcessInternalW)
		return wine32a_kernel32_CreateProcessInternalW;
	if (func == pCreateProcessW)
		return wine32a_kernel32_CreateProcessW;
	if (func == pCreateRemoteThread && func != pextCreateRemoteThread)
		return wine_thunk_get_for_any(pextCreateRemoteThread);
	if (func == pCreateRemoteThreadEx && func != pextCreateRemoteThreadEx)
		return wine_thunk_get_for_any(pextCreateRemoteThreadEx);
	if (func == pCreateSemaphoreA)
		return wine32a_kernel32_CreateSemaphoreA;
	if (func == pCreateSemaphoreExA)
		return wine32a_kernel32_CreateSemaphoreExA;
	if (func == pCreateSemaphoreExW && func != pextCreateSemaphoreExW)
		return wine_thunk_get_for_any(pextCreateSemaphoreExW);
	if (func == pCreateSemaphoreW && func != pextCreateSemaphoreW)
		return wine_thunk_get_for_any(pextCreateSemaphoreW);
	if (func == pCreateSocketHandle)
		return wine32a_kernel32_CreateSocketHandle;
	if (func == pCreateSymbolicLinkA)
		return wine32a_kernel32_CreateSymbolicLinkA;
	if (func == pCreateSymbolicLinkW)
		return wine32a_kernel32_CreateSymbolicLinkW;
	if (func == pCreateTapePartition)
		return wine32a_kernel32_CreateTapePartition;
	if (func == pCreateThread && func != pextCreateThread)
		return wine_thunk_get_for_any(pextCreateThread);
	if (func == pCreateThreadpool && func != pextCreateThreadpool)
		return wine_thunk_get_for_any(pextCreateThreadpool);
	if (func == pCreateThreadpoolCleanupGroup && func != pextCreateThreadpoolCleanupGroup)
		return wine_thunk_get_for_any(pextCreateThreadpoolCleanupGroup);
	if (func == pCreateThreadpoolIo && func != pextCreateThreadpoolIo)
		return wine_thunk_get_for_any(pextCreateThreadpoolIo);
	if (func == pCreateThreadpoolTimer && func != pextCreateThreadpoolTimer)
		return wine_thunk_get_for_any(pextCreateThreadpoolTimer);
	if (func == pCreateThreadpoolWait && func != pextCreateThreadpoolWait)
		return wine_thunk_get_for_any(pextCreateThreadpoolWait);
	if (func == pCreateThreadpoolWork && func != pextCreateThreadpoolWork)
		return wine_thunk_get_for_any(pextCreateThreadpoolWork);
	if (func == pCreateTimerQueue && func != pextCreateTimerQueue)
		return wine_thunk_get_for_any(pextCreateTimerQueue);
	if (func == pCreateTimerQueueTimer && func != pextCreateTimerQueueTimer)
		return wine_thunk_get_for_any(pextCreateTimerQueueTimer);
	if (func == pCreateToolhelp32Snapshot)
		return wine32a_kernel32_CreateToolhelp32Snapshot;
	if (func == pCreateUmsCompletionList)
		return wine32a_kernel32_CreateUmsCompletionList;
	if (func == pCreateUmsThreadContext)
		return wine32a_kernel32_CreateUmsThreadContext;
	if (func == pCreateWaitableTimerA)
		return wine32a_kernel32_CreateWaitableTimerA;
	if (func == pCreateWaitableTimerExA)
		return wine32a_kernel32_CreateWaitableTimerExA;
	if (func == pCreateWaitableTimerExW && func != pextCreateWaitableTimerExW)
		return wine_thunk_get_for_any(pextCreateWaitableTimerExW);
	if (func == pCreateWaitableTimerW && func != pextCreateWaitableTimerW)
		return wine_thunk_get_for_any(pextCreateWaitableTimerW);
	if (func == pDeactivateActCtx && func != pextDeactivateActCtx)
		return wine_thunk_get_for_any(pextDeactivateActCtx);
	if (func == pDebugActiveProcess && func != pextDebugActiveProcess)
		return wine_thunk_get_for_any(pextDebugActiveProcess);
	if (func == pDebugActiveProcessStop && func != pextDebugActiveProcessStop)
		return wine_thunk_get_for_any(pextDebugActiveProcessStop);
	if (func == pDebugBreakProcess)
		return wine32a_kernel32_DebugBreakProcess;
	if (func == pDebugSetProcessKillOnExit)
		return wine32a_kernel32_DebugSetProcessKillOnExit;
	if (func == pDecodePointer && func != pextDecodePointer)
		return wine_thunk_get_for_any(pextDecodePointer);
	if (func == pDecodeSystemPointer && func != pextDecodeSystemPointer)
		return wine_thunk_get_for_any(pextDecodeSystemPointer);
	if (func == pDefineDosDeviceA)
		return wine32a_kernel32_DefineDosDeviceA;
	if (func == pDefineDosDeviceW)
		return wine32a_kernel32_DefineDosDeviceW;
	if (func == pDelayLoadFailureHook)
		return wine32a_kernel32_DelayLoadFailureHook;
	if (func == pDeleteAtom)
		return wine32a_kernel32_DeleteAtom;
	if (func == pDeleteCriticalSection && func != pextDeleteCriticalSection)
		return wine_thunk_get_for_any(pextDeleteCriticalSection);
	if (func == pDeleteFiber && func != pextDeleteFiber)
		return wine_thunk_get_for_any(pextDeleteFiber);
	if (func == pDeleteFileA && func != pextDeleteFileA)
		return wine_thunk_get_for_any(pextDeleteFileA);
	if (func == pDeleteFileW && func != pextDeleteFileW)
		return wine_thunk_get_for_any(pextDeleteFileW);
	if (func == pDeleteProcThreadAttributeList && func != pextDeleteProcThreadAttributeList)
		return wine_thunk_get_for_any(pextDeleteProcThreadAttributeList);
	if (func == pDisassociateCurrentThreadFromCallback && func != pextDisassociateCurrentThreadFromCallback)
		return wine_thunk_get_for_any(pextDisassociateCurrentThreadFromCallback);
	if (func == pDeleteTimerQueue)
		return wine32a_kernel32_DeleteTimerQueue;
	if (func == pDeleteTimerQueueEx && func != pextDeleteTimerQueueEx)
		return wine_thunk_get_for_any(pextDeleteTimerQueueEx);
	if (func == pDeleteTimerQueueTimer && func != pextDeleteTimerQueueTimer)
		return wine_thunk_get_for_any(pextDeleteTimerQueueTimer);
	if (func == pDeleteUmsCompletionList)
		return wine32a_kernel32_DeleteUmsCompletionList;
	if (func == pDeleteUmsThreadContext)
		return wine32a_kernel32_DeleteUmsThreadContext;
	if (func == pDeleteVolumeMountPointA)
		return wine32a_kernel32_DeleteVolumeMountPointA;
	if (func == pDeleteVolumeMountPointW)
		return wine32a_kernel32_DeleteVolumeMountPointW;
	if (func == pDequeueUmsCompletionListItems)
		return wine32a_kernel32_DequeueUmsCompletionListItems;
	if (func == pDeviceIoControl)
		return wine32a_kernel32_DeviceIoControl;
	if (func == pDisableThreadLibraryCalls && func != pextDisableThreadLibraryCalls)
		return wine_thunk_get_for_any(pextDisableThreadLibraryCalls);
	if (func == pDisconnectNamedPipe && func != pextDisconnectNamedPipe)
		return wine_thunk_get_for_any(pextDisconnectNamedPipe);
	if (func == pDnsHostnameToComputerNameA)
		return wine32a_kernel32_DnsHostnameToComputerNameA;
	if (func == pDnsHostnameToComputerNameW)
		return wine32a_kernel32_DnsHostnameToComputerNameW;
	if (func == pDosDateTimeToFileTime)
		return wine32a_kernel32_DosDateTimeToFileTime;
	if (func == pDuplicateConsoleHandle)
		return wine32a_kernel32_DuplicateConsoleHandle;
	if (func == pDuplicateHandle)
		return wine32a_kernel32_DuplicateHandle;
	if (func == pEncodePointer && func != pextEncodePointer)
		return wine_thunk_get_for_any(pextEncodePointer);
	if (func == pEncodeSystemPointer && func != pextEncodeSystemPointer)
		return wine_thunk_get_for_any(pextEncodeSystemPointer);
	if (func == pEndUpdateResourceA)
		return wine32a_kernel32_EndUpdateResourceA;
	if (func == pEndUpdateResourceW)
		return wine32a_kernel32_EndUpdateResourceW;
	if (func == pEnterCriticalSection && func != pextEnterCriticalSection)
		return wine_thunk_get_for_any(pextEnterCriticalSection);
	if (func == pEnumCalendarInfoA)
		return wine32a_kernel32_EnumCalendarInfoA;
	if (func == pEnumCalendarInfoExA)
		return wine32a_kernel32_EnumCalendarInfoExA;
	if (func == pEnumCalendarInfoExEx)
		return wine32a_kernel32_EnumCalendarInfoExEx;
	if (func == pEnumCalendarInfoExW)
		return wine32a_kernel32_EnumCalendarInfoExW;
	if (func == pEnumCalendarInfoW)
		return wine32a_kernel32_EnumCalendarInfoW;
	if (func == pEnumDateFormatsA)
		return wine32a_kernel32_EnumDateFormatsA;
	if (func == pEnumDateFormatsExA)
		return wine32a_kernel32_EnumDateFormatsExA;
	if (func == pEnumDateFormatsExEx)
		return wine32a_kernel32_EnumDateFormatsExEx;
	if (func == pEnumDateFormatsExW)
		return wine32a_kernel32_EnumDateFormatsExW;
	if (func == pEnumDateFormatsW)
		return wine32a_kernel32_EnumDateFormatsW;
	if (func == pEnumLanguageGroupLocalesA)
		return wine32a_kernel32_EnumLanguageGroupLocalesA;
	if (func == pEnumLanguageGroupLocalesW)
		return wine32a_kernel32_EnumLanguageGroupLocalesW;
	if (func == pEnumResourceLanguagesA)
		return wine32a_kernel32_EnumResourceLanguagesA;
	if (func == pEnumResourceLanguagesExA && func != pextEnumResourceLanguagesExA)
		return wine_thunk_get_for_any(pextEnumResourceLanguagesExA);
	if (func == pEnumResourceLanguagesExW && func != pextEnumResourceLanguagesExW)
		return wine_thunk_get_for_any(pextEnumResourceLanguagesExW);
	if (func == pEnumResourceLanguagesW)
		return wine32a_kernel32_EnumResourceLanguagesW;
	if (func == pEnumResourceNamesA)
		return wine32a_kernel32_EnumResourceNamesA;
	if (func == pEnumResourceNamesExA && func != pextEnumResourceNamesExA)
		return wine_thunk_get_for_any(pextEnumResourceNamesExA);
	if (func == pEnumResourceNamesExW && func != pextEnumResourceNamesExW)
		return wine_thunk_get_for_any(pextEnumResourceNamesExW);
	if (func == pEnumResourceNamesW && func != pextEnumResourceNamesW)
		return wine_thunk_get_for_any(pextEnumResourceNamesW);
	if (func == pEnumResourceTypesA)
		return wine32a_kernel32_EnumResourceTypesA;
	if (func == pEnumResourceTypesExA && func != pextEnumResourceTypesExA)
		return wine_thunk_get_for_any(pextEnumResourceTypesExA);
	if (func == pEnumResourceTypesExW && func != pextEnumResourceTypesExW)
		return wine_thunk_get_for_any(pextEnumResourceTypesExW);
	if (func == pEnumResourceTypesW)
		return wine32a_kernel32_EnumResourceTypesW;
	if (func == pEnumSystemCodePagesA)
		return wine32a_kernel32_EnumSystemCodePagesA;
	if (func == pEnumSystemCodePagesW)
		return wine32a_kernel32_EnumSystemCodePagesW;
	if (func == pEnumSystemFirmwareTables)
		return wine32a_kernel32_EnumSystemFirmwareTables;
	if (func == pEnumSystemGeoID)
		return wine32a_kernel32_EnumSystemGeoID;
	if (func == pEnumSystemLanguageGroupsA)
		return wine32a_kernel32_EnumSystemLanguageGroupsA;
	if (func == pEnumSystemLanguageGroupsW)
		return wine32a_kernel32_EnumSystemLanguageGroupsW;
	if (func == pEnumSystemLocalesA)
		return wine32a_kernel32_EnumSystemLocalesA;
	if (func == pEnumSystemLocalesEx)
		return wine32a_kernel32_EnumSystemLocalesEx;
	if (func == pEnumSystemLocalesW)
		return wine32a_kernel32_EnumSystemLocalesW;
	if (func == pEnumTimeFormatsA)
		return wine32a_kernel32_EnumTimeFormatsA;
	if (func == pEnumTimeFormatsEx)
		return wine32a_kernel32_EnumTimeFormatsEx;
	if (func == pEnumTimeFormatsW)
		return wine32a_kernel32_EnumTimeFormatsW;
	if (func == pEnumUILanguagesA)
		return wine32a_kernel32_EnumUILanguagesA;
	if (func == pEnumUILanguagesW)
		return wine32a_kernel32_EnumUILanguagesW;
	if (func == pEnterUmsSchedulingMode)
		return wine32a_kernel32_EnterUmsSchedulingMode;
	if (func == pEraseTape)
		return wine32a_kernel32_EraseTape;
	if (func == pEscapeCommFunction && func != pextEscapeCommFunction)
		return wine_thunk_get_for_any(pextEscapeCommFunction);
	if (func == pExecuteUmsThread)
		return wine32a_kernel32_ExecuteUmsThread;
	if (func == pExitProcess)
		return wine32a_kernel32_ExitProcess;
	if (func == pExitThread && func != pextExitThread)
		return wine_thunk_get_for_any(pextExitThread);
	if (func == pExpandEnvironmentStringsA && func != pextExpandEnvironmentStringsA)
		return wine_thunk_get_for_any(pextExpandEnvironmentStringsA);
	if (func == pExpandEnvironmentStringsW && func != pextExpandEnvironmentStringsW)
		return wine_thunk_get_for_any(pextExpandEnvironmentStringsW);
	if (func == pExpungeConsoleCommandHistoryA)
		return wine32a_kernel32_ExpungeConsoleCommandHistoryA;
	if (func == pExpungeConsoleCommandHistoryW)
		return wine32a_kernel32_ExpungeConsoleCommandHistoryW;
	if (func == pFatalAppExitA && func != pextFatalAppExitA)
		return wine_thunk_get_for_any(pextFatalAppExitA);
	if (func == pFatalAppExitW && func != pextFatalAppExitW)
		return wine_thunk_get_for_any(pextFatalAppExitW);
	if (func == pFatalExit)
		return wine32a_kernel32_FatalExit;
	if (func == pFileTimeToDosDateTime)
		return wine32a_kernel32_FileTimeToDosDateTime;
	if (func == pFileTimeToLocalFileTime)
		return wine32a_kernel32_FileTimeToLocalFileTime;
	if (func == pFileTimeToSystemTime)
		return wine32a_kernel32_FileTimeToSystemTime;
	if (func == pFillConsoleOutputAttribute && func != pextFillConsoleOutputAttribute)
		return wine_thunk_get_for_any(pextFillConsoleOutputAttribute);
	if (func == pFillConsoleOutputCharacterA && func != pextFillConsoleOutputCharacterA)
		return wine_thunk_get_for_any(pextFillConsoleOutputCharacterA);
	if (func == pFillConsoleOutputCharacterW && func != pextFillConsoleOutputCharacterW)
		return wine_thunk_get_for_any(pextFillConsoleOutputCharacterW);
	if (func == pFindActCtxSectionGuid && func != pextFindActCtxSectionGuid)
		return wine_thunk_get_for_any(pextFindActCtxSectionGuid);
	if (func == pFindActCtxSectionStringA)
		return wine32a_kernel32_FindActCtxSectionStringA;
	if (func == pFindActCtxSectionStringW && func != pextFindActCtxSectionStringW)
		return wine_thunk_get_for_any(pextFindActCtxSectionStringW);
	if (func == pFindAtomA)
		return wine32a_kernel32_FindAtomA;
	if (func == pFindAtomW)
		return wine32a_kernel32_FindAtomW;
	if (func == pFindClose)
		return wine32a_kernel32_FindClose;
	if (func == pFindCloseChangeNotification && func != pextFindCloseChangeNotification)
		return wine_thunk_get_for_any(pextFindCloseChangeNotification);
	if (func == pFindFirstChangeNotificationA && func != pextFindFirstChangeNotificationA)
		return wine_thunk_get_for_any(pextFindFirstChangeNotificationA);
	if (func == pFindFirstChangeNotificationW && func != pextFindFirstChangeNotificationW)
		return wine_thunk_get_for_any(pextFindFirstChangeNotificationW);
	if (func == pFindFirstFileA)
		return wine32a_kernel32_FindFirstFileA;
	if (func == pFindFirstFileExA)
		return wine32a_kernel32_FindFirstFileExA;
	if (func == pFindFirstFileExW)
		return wine32a_kernel32_FindFirstFileExW;
	if (func == pFindFirstFileW)
		return wine32a_kernel32_FindFirstFileW;
	if (func == pFindFirstStreamW)
		return wine32a_kernel32_FindFirstStreamW;
	if (func == pFindFirstVolumeA)
		return wine32a_kernel32_FindFirstVolumeA;
	if (func == pFindFirstVolumeMountPointA)
		return wine32a_kernel32_FindFirstVolumeMountPointA;
	if (func == pFindFirstVolumeMountPointW)
		return wine32a_kernel32_FindFirstVolumeMountPointW;
	if (func == pFindFirstVolumeW)
		return wine32a_kernel32_FindFirstVolumeW;
	if (func == pFindNextChangeNotification && func != pextFindNextChangeNotification)
		return wine_thunk_get_for_any(pextFindNextChangeNotification);
	if (func == pFindNextFileA)
		return wine32a_kernel32_FindNextFileA;
	if (func == pFindNextFileW)
		return wine32a_kernel32_FindNextFileW;
	if (func == pFindNextStreamW)
		return wine32a_kernel32_FindNextStreamW;
	if (func == pFindNextVolumeA)
		return wine32a_kernel32_FindNextVolumeA;
	if (func == pFindNextVolumeW)
		return wine32a_kernel32_FindNextVolumeW;
	if (func == pFindNLSStringEx)
		return wine32a_kernel32_FindNLSStringEx;
	if (func == pFindResourceA)
		return wine32a_kernel32_FindResourceA;
	if (func == pFindResourceExA)
		return wine32a_kernel32_FindResourceExA;
	if (func == pFindResourceExW && func != pextFindResourceExW)
		return wine_thunk_get_for_any(pextFindResourceExW);
	if (func == pFindResourceW && func != pextFindResourceW)
		return wine_thunk_get_for_any(pextFindResourceW);
	if (func == pFindStringOrdinal)
		return wine32a_kernel32_FindStringOrdinal;
	if (func == pFindVolumeClose)
		return wine32a_kernel32_FindVolumeClose;
	if (func == pFindVolumeMountPointClose)
		return wine32a_kernel32_FindVolumeMountPointClose;
	if (func == pFlsAlloc && func != pextFlsAlloc)
		return wine_thunk_get_for_any(pextFlsAlloc);
	if (func == pFlsFree && func != pextFlsFree)
		return wine_thunk_get_for_any(pextFlsFree);
	if (func == pFlsGetValue && func != pextFlsGetValue)
		return wine_thunk_get_for_any(pextFlsGetValue);
	if (func == pFlsSetValue && func != pextFlsSetValue)
		return wine_thunk_get_for_any(pextFlsSetValue);
	if (func == pFlushConsoleInputBuffer)
		return wine32a_kernel32_FlushConsoleInputBuffer;
	if (func == pFlushFileBuffers && func != pextFlushFileBuffers)
		return wine_thunk_get_for_any(pextFlushFileBuffers);
	if (func == pFlushInstructionCache && func != pextFlushInstructionCache)
		return wine_thunk_get_for_any(pextFlushInstructionCache);
	if (func == pFlushProcessWriteBuffers)
		return wine32a_kernel32_FlushProcessWriteBuffers;
	if (func == pFlushViewOfFile && func != pextFlushViewOfFile)
		return wine_thunk_get_for_any(pextFlushViewOfFile);
	if (func == pFoldStringA)
		return wine32a_kernel32_FoldStringA;
	if (func == pFoldStringW)
		return wine32a_kernel32_FoldStringW;
	if (func == pFormatMessageA)
		return wine32a_kernel32_FormatMessageA;
	if (func == pFormatMessageW)
		return wine32a_kernel32_FormatMessageW;
	if (func == pFreeConsole)
		return wine32a_kernel32_FreeConsole;
	if (func == pFreeEnvironmentStringsA && func != pextFreeEnvironmentStringsA)
		return wine_thunk_get_for_any(pextFreeEnvironmentStringsA);
	if (func == pFreeEnvironmentStringsW && func != pextFreeEnvironmentStringsW)
		return wine_thunk_get_for_any(pextFreeEnvironmentStringsW);
	if (func == pFreeLibrary)
		return wine32a_kernel32_FreeLibrary;
	if (func == pFreeLibraryAndExitThread)
		return wine32a_kernel32_FreeLibraryAndExitThread;
	if (func == pFreeLibraryWhenCallbackReturns && func != pextFreeLibraryWhenCallbackReturns)
		return wine_thunk_get_for_any(pextFreeLibraryWhenCallbackReturns);
	if (func == pFreeResource && func != pextFreeResource)
		return wine_thunk_get_for_any(pextFreeResource);
	if (func == pFreeUserPhysicalPages)
		return wine32a_kernel32_FreeUserPhysicalPages;
	if (func == pGenerateConsoleCtrlEvent && func != pextGenerateConsoleCtrlEvent)
		return wine_thunk_get_for_any(pextGenerateConsoleCtrlEvent);
	if (func == pGetACP)
		return wine32a_kernel32_GetACP;
	if (func == pGetActiveProcessorCount)
		return wine32a_kernel32_GetActiveProcessorCount;
	if (func == pGetActiveProcessorGroupCount)
		return wine32a_kernel32_GetActiveProcessorGroupCount;
	if (func == pGetApplicationRestartSettings)
		return wine32a_kernel32_GetApplicationRestartSettings;
	if (func == pGetAtomNameA)
		return wine32a_kernel32_GetAtomNameA;
	if (func == pGetAtomNameW)
		return wine32a_kernel32_GetAtomNameW;
	if (func == pGetBinaryTypeA)
		return wine32a_kernel32_GetBinaryTypeA;
	if (func == pGetBinaryTypeW)
		return wine32a_kernel32_GetBinaryTypeW;
	if (func == pGetCPInfo)
		return wine32a_kernel32_GetCPInfo;
	if (func == pGetCPInfoExA)
		return wine32a_kernel32_GetCPInfoExA;
	if (func == pGetCPInfoExW)
		return wine32a_kernel32_GetCPInfoExW;
	if (func == pGetCalendarInfoA)
		return wine32a_kernel32_GetCalendarInfoA;
	if (func == pGetCalendarInfoW)
		return wine32a_kernel32_GetCalendarInfoW;
	if (func == pGetCalendarInfoEx)
		return wine32a_kernel32_GetCalendarInfoEx;
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
	if (func == pGetCompressedFileSizeA && func != pextGetCompressedFileSizeA)
		return wine_thunk_get_for_any(pextGetCompressedFileSizeA);
	if (func == pGetCompressedFileSizeW && func != pextGetCompressedFileSizeW)
		return wine_thunk_get_for_any(pextGetCompressedFileSizeW);
	if (func == pGetComputerNameA)
		return wine32a_kernel32_GetComputerNameA;
	if (func == pGetComputerNameExA)
		return wine32a_kernel32_GetComputerNameExA;
	if (func == pGetComputerNameExW)
		return wine32a_kernel32_GetComputerNameExW;
	if (func == pGetComputerNameW)
		return wine32a_kernel32_GetComputerNameW;
	if (func == pGetConsoleAliasExesLengthA)
		return wine32a_kernel32_GetConsoleAliasExesLengthA;
	if (func == pGetConsoleAliasExesLengthW)
		return wine32a_kernel32_GetConsoleAliasExesLengthW;
	if (func == pGetConsoleAliasW)
		return wine32a_kernel32_GetConsoleAliasW;
	if (func == pGetConsoleAliasesLengthA)
		return wine32a_kernel32_GetConsoleAliasesLengthA;
	if (func == pGetConsoleAliasesLengthW)
		return wine32a_kernel32_GetConsoleAliasesLengthW;
	if (func == pGetConsoleCP && func != pextGetConsoleCP)
		return wine_thunk_get_for_any(pextGetConsoleCP);
	if (func == pGetConsoleCommandHistoryA)
		return wine32a_kernel32_GetConsoleCommandHistoryA;
	if (func == pGetConsoleCommandHistoryLengthA)
		return wine32a_kernel32_GetConsoleCommandHistoryLengthA;
	if (func == pGetConsoleCommandHistoryLengthW)
		return wine32a_kernel32_GetConsoleCommandHistoryLengthW;
	if (func == pGetConsoleCommandHistoryW)
		return wine32a_kernel32_GetConsoleCommandHistoryW;
	if (func == pGetConsoleCursorInfo && func != pextGetConsoleCursorInfo)
		return wine_thunk_get_for_any(pextGetConsoleCursorInfo);
	if (func == pGetConsoleDisplayMode)
		return wine32a_kernel32_GetConsoleDisplayMode;
	if (func == pGetConsoleFontInfo)
		return wine32a_kernel32_GetConsoleFontInfo;
	if (func == pGetConsoleFontSize)
		return wine32a_kernel32_GetConsoleFontSize;
	if (func == pGetConsoleInputExeNameA && func != pextGetConsoleInputExeNameA)
		return wine_thunk_get_for_any(pextGetConsoleInputExeNameA);
	if (func == pGetConsoleInputExeNameW && func != pextGetConsoleInputExeNameW)
		return wine_thunk_get_for_any(pextGetConsoleInputExeNameW);
	if (func == pGetConsoleInputWaitHandle)
		return wine32a_kernel32_GetConsoleInputWaitHandle;
	if (func == pGetConsoleKeyboardLayoutNameA)
		return wine32a_kernel32_GetConsoleKeyboardLayoutNameA;
	if (func == pGetConsoleKeyboardLayoutNameW)
		return wine32a_kernel32_GetConsoleKeyboardLayoutNameW;
	if (func == pGetConsoleMode && func != pextGetConsoleMode)
		return wine_thunk_get_for_any(pextGetConsoleMode);
	if (func == pGetConsoleOutputCP && func != pextGetConsoleOutputCP)
		return wine_thunk_get_for_any(pextGetConsoleOutputCP);
	if (func == pGetConsoleProcessList)
		return wine32a_kernel32_GetConsoleProcessList;
	if (func == pGetConsoleScreenBufferInfo && func != pextGetConsoleScreenBufferInfo)
		return wine_thunk_get_for_any(pextGetConsoleScreenBufferInfo);
	if (func == pGetConsoleScreenBufferInfoEx && func != pextGetConsoleScreenBufferInfoEx)
		return wine_thunk_get_for_any(pextGetConsoleScreenBufferInfoEx);
	if (func == pGetConsoleTitleA)
		return wine32a_kernel32_GetConsoleTitleA;
	if (func == pGetConsoleTitleW && func != pextGetConsoleTitleW)
		return wine_thunk_get_for_any(pextGetConsoleTitleW);
	if (func == pGetConsoleWindow)
		return wine32a_kernel32_GetConsoleWindow;
	if (func == pGetCurrencyFormatA)
		return wine32a_kernel32_GetCurrencyFormatA;
	if (func == pGetCurrencyFormatEx)
		return wine32a_kernel32_GetCurrencyFormatEx;
	if (func == pGetCurrencyFormatW)
		return wine32a_kernel32_GetCurrencyFormatW;
	if (func == pGetCurrentActCtx && func != pextGetCurrentActCtx)
		return wine_thunk_get_for_any(pextGetCurrentActCtx);
	if (func == pGetCurrentConsoleFont)
		return wine32a_kernel32_GetCurrentConsoleFont;
	if (func == pGetCurrentDirectoryA)
		return wine32a_kernel32_GetCurrentDirectoryA;
	if (func == pGetCurrentDirectoryW)
		return wine32a_kernel32_GetCurrentDirectoryW;
	if (func == pGetCurrentPackageFamilyName)
		return wine32a_kernel32_GetCurrentPackageFamilyName;
	if (func == pGetCurrentPackageFullName)
		return wine32a_kernel32_GetCurrentPackageFullName;
	if (func == pGetCurrentPackageId)
		return wine32a_kernel32_GetCurrentPackageId;
	if (func == pGetCurrentProcess)
		return wine32a_kernel32_GetCurrentProcess;
	if (func == pGetCurrentProcessId)
		return wine32a_kernel32_GetCurrentProcessId;
	if (func == pGetCurrentProcessorNumber && func != pextGetCurrentProcessorNumber)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumber);
	if (func == pGetCurrentProcessorNumberEx && func != pextGetCurrentProcessorNumberEx)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumberEx);
	if (func == pGetCurrentThread)
		return wine32a_kernel32_GetCurrentThread;
	if (func == pGetCurrentThreadId)
		return wine32a_kernel32_GetCurrentThreadId;
	if (func == pGetCurrentThreadStackLimits && func != pextGetCurrentThreadStackLimits)
		return wine_thunk_get_for_any(pextGetCurrentThreadStackLimits);
	if (func == pGetCurrentUmsThread)
		return wine32a_kernel32_GetCurrentUmsThread;
	if (func == pGetDateFormatA)
		return wine32a_kernel32_GetDateFormatA;
	if (func == pGetDateFormatEx)
		return wine32a_kernel32_GetDateFormatEx;
	if (func == pGetDateFormatW)
		return wine32a_kernel32_GetDateFormatW;
	if (func == pGetDaylightFlag)
		return wine32a_kernel32_GetDaylightFlag;
	if (func == pGetDefaultCommConfigA)
		return wine32a_kernel32_GetDefaultCommConfigA;
	if (func == pGetDefaultCommConfigW)
		return wine32a_kernel32_GetDefaultCommConfigW;
	if (func == pGetDevicePowerState)
		return wine32a_kernel32_GetDevicePowerState;
	if (func == pGetDiskFreeSpaceA)
		return wine32a_kernel32_GetDiskFreeSpaceA;
	if (func == pGetDiskFreeSpaceExA)
		return wine32a_kernel32_GetDiskFreeSpaceExA;
	if (func == pGetDiskFreeSpaceExW)
		return wine32a_kernel32_GetDiskFreeSpaceExW;
	if (func == pGetDiskFreeSpaceW)
		return wine32a_kernel32_GetDiskFreeSpaceW;
	if (func == pGetDllDirectoryA)
		return wine32a_kernel32_GetDllDirectoryA;
	if (func == pGetDllDirectoryW)
		return wine32a_kernel32_GetDllDirectoryW;
	if (func == pGetDriveTypeA)
		return wine32a_kernel32_GetDriveTypeA;
	if (func == pGetDriveTypeW)
		return wine32a_kernel32_GetDriveTypeW;
	if (func == pGetDynamicTimeZoneInformation)
		return wine32a_kernel32_GetDynamicTimeZoneInformation;
	if (func == pGetDynamicTimeZoneInformationEffectiveYears)
		return wine32a_kernel32_GetDynamicTimeZoneInformationEffectiveYears;
	if (func == pGetEnabledXStateFeatures)
		return wine32a_kernel32_GetEnabledXStateFeatures;
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
	if (func == pGetErrorMode && func != pextGetErrorMode)
		return wine_thunk_get_for_any(pextGetErrorMode);
	if (func == pGetExitCodeProcess)
		return wine32a_kernel32_GetExitCodeProcess;
	if (func == pGetExitCodeThread && func != pextGetExitCodeThread)
		return wine_thunk_get_for_any(pextGetExitCodeThread);
	if (func == pGetExpandedNameA)
		return wine32a_kernel32_GetExpandedNameA;
	if (func == pGetExpandedNameW)
		return wine32a_kernel32_GetExpandedNameW;
	if (func == pGetFileAttributesA && func != pextGetFileAttributesA)
		return wine_thunk_get_for_any(pextGetFileAttributesA);
	if (func == pGetFileAttributesExA && func != pextGetFileAttributesExA)
		return wine_thunk_get_for_any(pextGetFileAttributesExA);
	if (func == pGetFileAttributesExW && func != pextGetFileAttributesExW)
		return wine_thunk_get_for_any(pextGetFileAttributesExW);
	if (func == pGetFileAttributesW && func != pextGetFileAttributesW)
		return wine_thunk_get_for_any(pextGetFileAttributesW);
	if (func == pGetFileInformationByHandle && func != pextGetFileInformationByHandle)
		return wine_thunk_get_for_any(pextGetFileInformationByHandle);
	if (func == pGetFileInformationByHandleEx && func != pextGetFileInformationByHandleEx)
		return wine_thunk_get_for_any(pextGetFileInformationByHandleEx);
	if (func == pGetFileMUIInfo)
		return wine32a_kernel32_GetFileMUIInfo;
	if (func == pGetFileMUIPath)
		return wine32a_kernel32_GetFileMUIPath;
	if (func == pGetFileSize && func != pextGetFileSize)
		return wine_thunk_get_for_any(pextGetFileSize);
	if (func == pGetFileSizeEx && func != pextGetFileSizeEx)
		return wine_thunk_get_for_any(pextGetFileSizeEx);
	if (func == pGetFileTime && func != pextGetFileTime)
		return wine_thunk_get_for_any(pextGetFileTime);
	if (func == pGetFileType && func != pextGetFileType)
		return wine_thunk_get_for_any(pextGetFileType);
	if (func == pGetFinalPathNameByHandleA)
		return wine32a_kernel32_GetFinalPathNameByHandleA;
	if (func == pGetFinalPathNameByHandleW)
		return wine32a_kernel32_GetFinalPathNameByHandleW;
	if (func == pGetFirmwareEnvironmentVariableA)
		return wine32a_kernel32_GetFirmwareEnvironmentVariableA;
	if (func == pGetFirmwareEnvironmentVariableW)
		return wine32a_kernel32_GetFirmwareEnvironmentVariableW;
	if (func == pGetFullPathNameA)
		return wine32a_kernel32_GetFullPathNameA;
	if (func == pGetFullPathNameW)
		return wine32a_kernel32_GetFullPathNameW;
	if (func == pGetGeoInfoA)
		return wine32a_kernel32_GetGeoInfoA;
	if (func == pGetGeoInfoW)
		return wine32a_kernel32_GetGeoInfoW;
	if (func == pGetHandleContext)
		return wine32a_kernel32_GetHandleContext;
	if (func == pGetHandleInformation)
		return wine32a_kernel32_GetHandleInformation;
	if (func == pGetLargePageMinimum)
		return wine32a_kernel32_GetLargePageMinimum;
	if (func == pGetLargestConsoleWindowSize && func != pextGetLargestConsoleWindowSize)
		return wine_thunk_get_for_any(pextGetLargestConsoleWindowSize);
	if (func == pGetLastError && func != pextGetLastError)
		return wine_thunk_get_for_any(pextGetLastError);
	if (func == pGetLocalTime)
		return wine32a_kernel32_GetLocalTime;
	if (func == pGetLocaleInfoA)
		return wine32a_kernel32_GetLocaleInfoA;
	if (func == pGetLocaleInfoW)
		return wine32a_kernel32_GetLocaleInfoW;
	if (func == pGetLocaleInfoEx)
		return wine32a_kernel32_GetLocaleInfoEx;
	if (func == pGetLogicalDriveStringsA)
		return wine32a_kernel32_GetLogicalDriveStringsA;
	if (func == pGetLogicalDriveStringsW)
		return wine32a_kernel32_GetLogicalDriveStringsW;
	if (func == pGetLogicalDrives)
		return wine32a_kernel32_GetLogicalDrives;
	if (func == pGetLogicalProcessorInformation)
		return wine32a_kernel32_GetLogicalProcessorInformation;
	if (func == pGetLogicalProcessorInformationEx)
		return wine32a_kernel32_GetLogicalProcessorInformationEx;
	if (func == pGetLongPathNameA)
		return wine32a_kernel32_GetLongPathNameA;
	if (func == pGetLongPathNameW)
		return wine32a_kernel32_GetLongPathNameW;
	if (func == pGetMailslotInfo)
		return wine32a_kernel32_GetMailslotInfo;
	if (func == pGetMaximumProcessorCount)
		return wine32a_kernel32_GetMaximumProcessorCount;
	if (func == pGetModuleFileNameA && func != pextGetModuleFileNameA)
		return wine_thunk_get_for_any(pextGetModuleFileNameA);
	if (func == pGetModuleFileNameW && func != pextGetModuleFileNameW)
		return wine_thunk_get_for_any(pextGetModuleFileNameW);
	if (func == pGetModuleHandleA && func != pextGetModuleHandleA)
		return wine_thunk_get_for_any(pextGetModuleHandleA);
	if (func == pGetModuleHandleExA && func != pextGetModuleHandleExA)
		return wine_thunk_get_for_any(pextGetModuleHandleExA);
	if (func == pGetModuleHandleExW && func != pextGetModuleHandleExW)
		return wine_thunk_get_for_any(pextGetModuleHandleExW);
	if (func == pGetModuleHandleW && func != pextGetModuleHandleW)
		return wine_thunk_get_for_any(pextGetModuleHandleW);
	if (func == pGetNamedPipeClientProcessId)
		return wine32a_kernel32_GetNamedPipeClientProcessId;
	if (func == pGetNamedPipeClientSessionId)
		return wine32a_kernel32_GetNamedPipeClientSessionId;
	if (func == pGetNamedPipeHandleStateA)
		return wine32a_kernel32_GetNamedPipeHandleStateA;
	if (func == pGetNamedPipeHandleStateW)
		return wine32a_kernel32_GetNamedPipeHandleStateW;
	if (func == pGetNamedPipeInfo && func != pextGetNamedPipeInfo)
		return wine_thunk_get_for_any(pextGetNamedPipeInfo);
	if (func == pGetNamedPipeServerProcessId)
		return wine32a_kernel32_GetNamedPipeServerProcessId;
	if (func == pGetNamedPipeServerSessionId)
		return wine32a_kernel32_GetNamedPipeServerSessionId;
	if (func == pGetNativeSystemInfo)
		return wine32a_kernel32_GetNativeSystemInfo;
	if (func == pGetNextUmsListItem)
		return wine32a_kernel32_GetNextUmsListItem;
	if (func == pGetNumaAvailableMemoryNode)
		return wine32a_kernel32_GetNumaAvailableMemoryNode;
	if (func == pGetNumaAvailableMemoryNodeEx)
		return wine32a_kernel32_GetNumaAvailableMemoryNodeEx;
	if (func == pGetNumaHighestNodeNumber)
		return wine32a_kernel32_GetNumaHighestNodeNumber;
	if (func == pGetNumaNodeProcessorMask)
		return wine32a_kernel32_GetNumaNodeProcessorMask;
	if (func == pGetNumaNodeProcessorMaskEx)
		return wine32a_kernel32_GetNumaNodeProcessorMaskEx;
	if (func == pGetNumaProcessorNode)
		return wine32a_kernel32_GetNumaProcessorNode;
	if (func == pGetNumaProcessorNodeEx)
		return wine32a_kernel32_GetNumaProcessorNodeEx;
	if (func == pGetNumaProximityNode)
		return wine32a_kernel32_GetNumaProximityNode;
	if (func == pGetNumaProximityNodeEx)
		return wine32a_kernel32_GetNumaProximityNodeEx;
	if (func == pGetNumberFormatA)
		return wine32a_kernel32_GetNumberFormatA;
	if (func == pGetNumberFormatEx)
		return wine32a_kernel32_GetNumberFormatEx;
	if (func == pGetNumberFormatW)
		return wine32a_kernel32_GetNumberFormatW;
	if (func == pGetNumberOfConsoleFonts)
		return wine32a_kernel32_GetNumberOfConsoleFonts;
	if (func == pGetNumberOfConsoleInputEvents && func != pextGetNumberOfConsoleInputEvents)
		return wine_thunk_get_for_any(pextGetNumberOfConsoleInputEvents);
	if (func == pGetNumberOfConsoleMouseButtons)
		return wine32a_kernel32_GetNumberOfConsoleMouseButtons;
	if (func == pGetOEMCP)
		return wine32a_kernel32_GetOEMCP;
	if (func == pGetOverlappedResult && func != pextGetOverlappedResult)
		return wine_thunk_get_for_any(pextGetOverlappedResult);
	if (func == pGetUserPreferredUILanguages)
		return wine32a_kernel32_GetUserPreferredUILanguages;
	if (func == pGetPackageFullName)
		return wine32a_kernel32_GetPackageFullName;
	if (func == pGetPhysicallyInstalledSystemMemory)
		return wine32a_kernel32_GetPhysicallyInstalledSystemMemory;
	if (func == pGetPriorityClass && func != pextGetPriorityClass)
		return wine_thunk_get_for_any(pextGetPriorityClass);
	if (func == pGetPrivateProfileIntA)
		return wine32a_kernel32_GetPrivateProfileIntA;
	if (func == pGetPrivateProfileIntW)
		return wine32a_kernel32_GetPrivateProfileIntW;
	if (func == pGetPrivateProfileSectionA)
		return wine32a_kernel32_GetPrivateProfileSectionA;
	if (func == pGetPrivateProfileSectionNamesA)
		return wine32a_kernel32_GetPrivateProfileSectionNamesA;
	if (func == pGetPrivateProfileSectionNamesW)
		return wine32a_kernel32_GetPrivateProfileSectionNamesW;
	if (func == pGetPrivateProfileSectionW)
		return wine32a_kernel32_GetPrivateProfileSectionW;
	if (func == pGetPrivateProfileStringA)
		return wine32a_kernel32_GetPrivateProfileStringA;
	if (func == pGetPrivateProfileStringW)
		return wine32a_kernel32_GetPrivateProfileStringW;
	if (func == pGetPrivateProfileStructA)
		return wine32a_kernel32_GetPrivateProfileStructA;
	if (func == pGetPrivateProfileStructW)
		return wine32a_kernel32_GetPrivateProfileStructW;
	if (func == pGetProcAddress)
		return wine32a_kernel32_GetProcAddress;
	if (func == pGetProcessAffinityMask)
		return wine32a_kernel32_GetProcessAffinityMask;
	if (func == pGetProcessDEPPolicy)
		return wine32a_kernel32_GetProcessDEPPolicy;
	if (func == pGetProcessFlags)
		return wine32a_kernel32_GetProcessFlags;
	if (func == pGetProcessHandleCount && func != pextGetProcessHandleCount)
		return wine_thunk_get_for_any(pextGetProcessHandleCount);
	if (func == pGetProcessHeap && func != pextGetProcessHeap)
		return wine_thunk_get_for_any(pextGetProcessHeap);
	if (func == pGetProcessId && func != pextGetProcessId)
		return wine_thunk_get_for_any(pextGetProcessId);
	if (func == pGetProcessIdOfThread && func != pextGetProcessIdOfThread)
		return wine_thunk_get_for_any(pextGetProcessIdOfThread);
	if (func == pGetProcessIoCounters)
		return wine32a_kernel32_GetProcessIoCounters;
	if (func == pGetProcessMitigationPolicy && func != pextGetProcessMitigationPolicy)
		return wine_thunk_get_for_any(pextGetProcessMitigationPolicy);
	if (func == pGetProcessPreferredUILanguages)
		return wine32a_kernel32_GetProcessPreferredUILanguages;
	if (func == pGetProcessPriorityBoost && func != pextGetProcessPriorityBoost)
		return wine_thunk_get_for_any(pextGetProcessPriorityBoost);
	if (func == pGetProcessShutdownParameters && func != pextGetProcessShutdownParameters)
		return wine_thunk_get_for_any(pextGetProcessShutdownParameters);
	if (func == pGetProcessTimes)
		return wine32a_kernel32_GetProcessTimes;
	if (func == pGetProcessVersion)
		return wine32a_kernel32_GetProcessVersion;
	if (func == pGetProcessWorkingSetSize)
		return wine32a_kernel32_GetProcessWorkingSetSize;
	if (func == pGetProcessWorkingSetSizeEx && func != pextGetProcessWorkingSetSizeEx)
		return wine_thunk_get_for_any(pextGetProcessWorkingSetSizeEx);
	if (func == pGetProductInfo)
		return wine32a_kernel32_GetProductInfo;
	if (func == pGetProfileIntA)
		return wine32a_kernel32_GetProfileIntA;
	if (func == pGetProfileIntW)
		return wine32a_kernel32_GetProfileIntW;
	if (func == pGetProfileSectionA)
		return wine32a_kernel32_GetProfileSectionA;
	if (func == pGetProfileSectionW)
		return wine32a_kernel32_GetProfileSectionW;
	if (func == pGetProfileStringA)
		return wine32a_kernel32_GetProfileStringA;
	if (func == pGetProfileStringW)
		return wine32a_kernel32_GetProfileStringW;
	if (func == pGetQueuedCompletionStatus && func != pextGetQueuedCompletionStatus)
		return wine_thunk_get_for_any(pextGetQueuedCompletionStatus);
	if (func == pGetQueuedCompletionStatusEx && func != pextGetQueuedCompletionStatusEx)
		return wine_thunk_get_for_any(pextGetQueuedCompletionStatusEx);
	if (func == pGetShortPathNameA)
		return wine32a_kernel32_GetShortPathNameA;
	if (func == pGetShortPathNameW)
		return wine32a_kernel32_GetShortPathNameW;
	if (func == pGetStartupInfoA)
		return wine32a_kernel32_GetStartupInfoA;
	if (func == pGetStartupInfoW && func != pextGetStartupInfoW)
		return wine_thunk_get_for_any(pextGetStartupInfoW);
	if (func == pGetStdHandle && func != pextGetStdHandle)
		return wine_thunk_get_for_any(pextGetStdHandle);
	if (func == pGetStringTypeA)
		return wine32a_kernel32_GetStringTypeA;
	if (func == pGetStringTypeExA)
		return wine32a_kernel32_GetStringTypeExA;
	if (func == pGetStringTypeExW)
		return wine32a_kernel32_GetStringTypeExW;
	if (func == pGetStringTypeW)
		return wine32a_kernel32_GetStringTypeW;
	if (func == pGetSystemFileCacheSize)
		return wine32a_kernel32_GetSystemFileCacheSize;
	if (func == pGetSystemDefaultLCID)
		return wine32a_kernel32_GetSystemDefaultLCID;
	if (func == pGetSystemDefaultLangID)
		return wine32a_kernel32_GetSystemDefaultLangID;
	if (func == pGetSystemDefaultLocaleName)
		return wine32a_kernel32_GetSystemDefaultLocaleName;
	if (func == pGetSystemDefaultUILanguage)
		return wine32a_kernel32_GetSystemDefaultUILanguage;
	if (func == pGetSystemDEPPolicy)
		return wine32a_kernel32_GetSystemDEPPolicy;
	if (func == pGetSystemDirectoryA)
		return wine32a_kernel32_GetSystemDirectoryA;
	if (func == pGetSystemDirectoryW)
		return wine32a_kernel32_GetSystemDirectoryW;
	if (func == pGetSystemFirmwareTable)
		return wine32a_kernel32_GetSystemFirmwareTable;
	if (func == pGetSystemInfo)
		return wine32a_kernel32_GetSystemInfo;
	if (func == pGetSystemPowerStatus)
		return wine32a_kernel32_GetSystemPowerStatus;
	if (func == pGetSystemPreferredUILanguages)
		return wine32a_kernel32_GetSystemPreferredUILanguages;
	if (func == pGetSystemRegistryQuota)
		return wine32a_kernel32_GetSystemRegistryQuota;
	if (func == pGetSystemTime)
		return wine32a_kernel32_GetSystemTime;
	if (func == pGetSystemTimeAdjustment)
		return wine32a_kernel32_GetSystemTimeAdjustment;
	if (func == pGetSystemTimeAsFileTime && func != pextGetSystemTimeAsFileTime)
		return wine_thunk_get_for_any(pextGetSystemTimeAsFileTime);
	if (func == pGetSystemTimePreciseAsFileTime)
		return wine32a_kernel32_GetSystemTimePreciseAsFileTime;
	if (func == pGetSystemTimes)
		return wine32a_kernel32_GetSystemTimes;
	if (func == pGetSystemWindowsDirectoryA && func != pextGetSystemWindowsDirectoryA)
		return wine_thunk_get_for_any(pextGetSystemWindowsDirectoryA);
	if (func == pGetSystemWindowsDirectoryW && func != pextGetSystemWindowsDirectoryW)
		return wine_thunk_get_for_any(pextGetSystemWindowsDirectoryW);
	if (func == pGetSystemWow64DirectoryA)
		return wine32a_kernel32_GetSystemWow64DirectoryA;
	if (func == pGetSystemWow64DirectoryW)
		return wine32a_kernel32_GetSystemWow64DirectoryW;
	if (func == pGetTapeParameters)
		return wine32a_kernel32_GetTapeParameters;
	if (func == pGetTapePosition)
		return wine32a_kernel32_GetTapePosition;
	if (func == pGetTapeStatus)
		return wine32a_kernel32_GetTapeStatus;
	if (func == pGetTempFileNameA)
		return wine32a_kernel32_GetTempFileNameA;
	if (func == pGetTempFileNameW)
		return wine32a_kernel32_GetTempFileNameW;
	if (func == pGetTempPathA)
		return wine32a_kernel32_GetTempPathA;
	if (func == pGetTempPathW)
		return wine32a_kernel32_GetTempPathW;
	if (func == pGetThreadContext && func != pextGetThreadContext)
		return wine_thunk_get_for_any(pextGetThreadContext);
	if (func == pGetThreadErrorMode && func != pextGetThreadErrorMode)
		return wine_thunk_get_for_any(pextGetThreadErrorMode);
	if (func == pGetThreadGroupAffinity && func != pextGetThreadGroupAffinity)
		return wine_thunk_get_for_any(pextGetThreadGroupAffinity);
	if (func == pGetThreadIOPendingFlag && func != pextGetThreadIOPendingFlag)
		return wine_thunk_get_for_any(pextGetThreadIOPendingFlag);
	if (func == pGetThreadId && func != pextGetThreadId)
		return wine_thunk_get_for_any(pextGetThreadId);
	if (func == pGetThreadLocale)
		return wine32a_kernel32_GetThreadLocale;
	if (func == pGetThreadPreferredUILanguages)
		return wine32a_kernel32_GetThreadPreferredUILanguages;
	if (func == pGetThreadPriority && func != pextGetThreadPriority)
		return wine_thunk_get_for_any(pextGetThreadPriority);
	if (func == pGetThreadPriorityBoost && func != pextGetThreadPriorityBoost)
		return wine_thunk_get_for_any(pextGetThreadPriorityBoost);
	if (func == pGetThreadSelectorEntry)
		return wine32a_kernel32_GetThreadSelectorEntry;
	if (func == pGetThreadTimes && func != pextGetThreadTimes)
		return wine_thunk_get_for_any(pextGetThreadTimes);
	if (func == pGetThreadUILanguage && func != pextGetThreadUILanguage)
		return wine_thunk_get_for_any(pextGetThreadUILanguage);
	if (func == pGetTickCount)
		return wine32a_kernel32_GetTickCount;
	if (func == pGetTickCount64)
		return wine32a_kernel32_GetTickCount64;
	if (func == pGetTimeFormatA)
		return wine32a_kernel32_GetTimeFormatA;
	if (func == pGetTimeFormatEx)
		return wine32a_kernel32_GetTimeFormatEx;
	if (func == pGetTimeFormatW)
		return wine32a_kernel32_GetTimeFormatW;
	if (func == pGetTimeZoneInformation)
		return wine32a_kernel32_GetTimeZoneInformation;
	if (func == pGetTimeZoneInformationForYear)
		return wine32a_kernel32_GetTimeZoneInformationForYear;
	if (func == pGetUmsCompletionListEvent)
		return wine32a_kernel32_GetUmsCompletionListEvent;
	if (func == pGetUserDefaultLCID)
		return wine32a_kernel32_GetUserDefaultLCID;
	if (func == pGetUserDefaultLangID)
		return wine32a_kernel32_GetUserDefaultLangID;
	if (func == pGetUserDefaultLocaleName)
		return wine32a_kernel32_GetUserDefaultLocaleName;
	if (func == pGetUserDefaultUILanguage)
		return wine32a_kernel32_GetUserDefaultUILanguage;
	if (func == pGetUserGeoID)
		return wine32a_kernel32_GetUserGeoID;
	if (func == pGetVersion && func != pextGetVersion)
		return wine_thunk_get_for_any(pextGetVersion);
	if (func == pGetVersionExA && func != pextGetVersionExA)
		return wine_thunk_get_for_any(pextGetVersionExA);
	if (func == pGetVersionExW && func != pextGetVersionExW)
		return wine_thunk_get_for_any(pextGetVersionExW);
	if (func == pGetVolumeInformationA)
		return wine32a_kernel32_GetVolumeInformationA;
	if (func == pGetVolumeInformationByHandleW)
		return wine32a_kernel32_GetVolumeInformationByHandleW;
	if (func == pGetVolumeInformationW)
		return wine32a_kernel32_GetVolumeInformationW;
	if (func == pGetVolumeNameForVolumeMountPointA)
		return wine32a_kernel32_GetVolumeNameForVolumeMountPointA;
	if (func == pGetVolumeNameForVolumeMountPointW)
		return wine32a_kernel32_GetVolumeNameForVolumeMountPointW;
	if (func == pGetVolumePathNameA)
		return wine32a_kernel32_GetVolumePathNameA;
	if (func == pGetVolumePathNameW)
		return wine32a_kernel32_GetVolumePathNameW;
	if (func == pGetVolumePathNamesForVolumeNameA)
		return wine32a_kernel32_GetVolumePathNamesForVolumeNameA;
	if (func == pGetVolumePathNamesForVolumeNameW)
		return wine32a_kernel32_GetVolumePathNamesForVolumeNameW;
	if (func == pGetWindowsDirectoryA && func != pextGetWindowsDirectoryA)
		return wine_thunk_get_for_any(pextGetWindowsDirectoryA);
	if (func == pGetWindowsDirectoryW && func != pextGetWindowsDirectoryW)
		return wine_thunk_get_for_any(pextGetWindowsDirectoryW);
	if (func == pGetWriteWatch && func != pextGetWriteWatch)
		return wine_thunk_get_for_any(pextGetWriteWatch);
	if (func == pGlobalAddAtomA)
		return wine32a_kernel32_GlobalAddAtomA;
	if (func == pGlobalAddAtomW)
		return wine32a_kernel32_GlobalAddAtomW;
	if (func == pGlobalAlloc && func != pextGlobalAlloc)
		return wine_thunk_get_for_any(pextGlobalAlloc);
	if (func == pGlobalCompact)
		return wine32a_kernel32_GlobalCompact;
	if (func == pGlobalDeleteAtom)
		return wine32a_kernel32_GlobalDeleteAtom;
	if (func == pGlobalFindAtomA)
		return wine32a_kernel32_GlobalFindAtomA;
	if (func == pGlobalFindAtomW)
		return wine32a_kernel32_GlobalFindAtomW;
	if (func == pGlobalFix)
		return wine32a_kernel32_GlobalFix;
	if (func == pGlobalFlags)
		return wine32a_kernel32_GlobalFlags;
	if (func == pGlobalFree && func != pextGlobalFree)
		return wine_thunk_get_for_any(pextGlobalFree);
	if (func == pGlobalGetAtomNameA)
		return wine32a_kernel32_GlobalGetAtomNameA;
	if (func == pGlobalGetAtomNameW)
		return wine32a_kernel32_GlobalGetAtomNameW;
	if (func == pGlobalHandle)
		return wine32a_kernel32_GlobalHandle;
	if (func == pGlobalLock)
		return wine32a_kernel32_GlobalLock;
	if (func == pGlobalMemoryStatus)
		return wine32a_kernel32_GlobalMemoryStatus;
	if (func == pGlobalMemoryStatusEx)
		return wine32a_kernel32_GlobalMemoryStatusEx;
	if (func == pGlobalReAlloc)
		return wine32a_kernel32_GlobalReAlloc;
	if (func == pGlobalSize)
		return wine32a_kernel32_GlobalSize;
	if (func == pGlobalUnWire)
		return wine32a_kernel32_GlobalUnWire;
	if (func == pGlobalUnfix)
		return wine32a_kernel32_GlobalUnfix;
	if (func == pGlobalUnlock)
		return wine32a_kernel32_GlobalUnlock;
	if (func == pGlobalWire)
		return wine32a_kernel32_GlobalWire;
	if (func == pHeap32ListFirst)
		return wine32a_kernel32_Heap32ListFirst;
	if (func == pHeapAlloc && func != pextHeapAlloc)
		return wine_thunk_get_for_any(pextHeapAlloc);
	if (func == pHeapCompact && func != pextHeapCompact)
		return wine_thunk_get_for_any(pextHeapCompact);
	if (func == pHeapCreate)
		return wine32a_kernel32_HeapCreate;
	if (func == pHeapDestroy)
		return wine32a_kernel32_HeapDestroy;
	if (func == pHeapFree)
		return wine32a_kernel32_HeapFree;
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
	if (func == pIdnToAscii)
		return wine32a_kernel32_IdnToAscii;
	if (func == pIdnToNameprepUnicode)
		return wine32a_kernel32_IdnToNameprepUnicode;
	if (func == pIdnToUnicode)
		return wine32a_kernel32_IdnToUnicode;
	if (func == pInitAtomTable)
		return wine32a_kernel32_InitAtomTable;
	if (func == pInitOnceBeginInitialize && func != pextInitOnceBeginInitialize)
		return wine_thunk_get_for_any(pextInitOnceBeginInitialize);
	if (func == pInitOnceComplete && func != pextInitOnceComplete)
		return wine_thunk_get_for_any(pextInitOnceComplete);
	if (func == pInitOnceExecuteOnce && func != pextInitOnceExecuteOnce)
		return wine_thunk_get_for_any(pextInitOnceExecuteOnce);
	if (func == pInitOnceInitialize && func != pextInitOnceInitialize)
		return wine_thunk_get_for_any(pextInitOnceInitialize);
	if (func == pInitializeConditionVariable && func != pextInitializeConditionVariable)
		return wine_thunk_get_for_any(pextInitializeConditionVariable);
	if (func == pInitializeCriticalSection && func != pextInitializeCriticalSection)
		return wine_thunk_get_for_any(pextInitializeCriticalSection);
	if (func == pInitializeCriticalSectionAndSpinCount && func != pextInitializeCriticalSectionAndSpinCount)
		return wine_thunk_get_for_any(pextInitializeCriticalSectionAndSpinCount);
	if (func == pInitializeCriticalSectionEx && func != pextInitializeCriticalSectionEx)
		return wine_thunk_get_for_any(pextInitializeCriticalSectionEx);
	if (func == pInitializeProcThreadAttributeList && func != pextInitializeProcThreadAttributeList)
		return wine_thunk_get_for_any(pextInitializeProcThreadAttributeList);
	if (func == pInitializeSListHead && func != pextInitializeSListHead)
		return wine_thunk_get_for_any(pextInitializeSListHead);
	if (func == pInitializeSRWLock && func != pextInitializeSRWLock)
		return wine_thunk_get_for_any(pextInitializeSRWLock);
	if (func == pInterlockedCompareExchange64 && func != pextInterlockedCompareExchange64)
		return wine_thunk_get_for_any(pextInterlockedCompareExchange64);
	if (func == pInterlockedFlushSList && func != pextInterlockedFlushSList)
		return wine_thunk_get_for_any(pextInterlockedFlushSList);
	if (func == pInterlockedPopEntrySList && func != pextInterlockedPopEntrySList)
		return wine_thunk_get_for_any(pextInterlockedPopEntrySList);
	if (func == pInterlockedPushEntrySList && func != pextInterlockedPushEntrySList)
		return wine_thunk_get_for_any(pextInterlockedPushEntrySList);
	if (func == pInterlockedPushListSList && func != pextInterlockedPushListSList)
		return wine_thunk_get_for_any(pextInterlockedPushListSList);
	if (func == pInterlockedPushListSListEx && func != pextInterlockedPushListSListEx)
		return wine_thunk_get_for_any(pextInterlockedPushListSListEx);
	if (func == pInvalidateNLSCache)
		return wine32a_kernel32_InvalidateNLSCache;
	if (func == pIsBadCodePtr)
		return wine32a_kernel32_IsBadCodePtr;
	if (func == pIsBadHugeReadPtr)
		return wine32a_kernel32_IsBadHugeReadPtr;
	if (func == pIsBadHugeWritePtr)
		return wine32a_kernel32_IsBadHugeWritePtr;
	if (func == pIsBadReadPtr)
		return wine32a_kernel32_IsBadReadPtr;
	if (func == pIsBadStringPtrA)
		return wine32a_kernel32_IsBadStringPtrA;
	if (func == pIsBadStringPtrW)
		return wine32a_kernel32_IsBadStringPtrW;
	if (func == pIsBadWritePtr)
		return wine32a_kernel32_IsBadWritePtr;
	if (func == pIsDBCSLeadByte)
		return wine32a_kernel32_IsDBCSLeadByte;
	if (func == pIsDBCSLeadByteEx)
		return wine32a_kernel32_IsDBCSLeadByteEx;
	if (func == pIsDebuggerPresent && func != pextIsDebuggerPresent)
		return wine_thunk_get_for_any(pextIsDebuggerPresent);
	if (func == pIsNormalizedString)
		return wine32a_kernel32_IsNormalizedString;
	if (func == pIsProcessInJob)
		return wine32a_kernel32_IsProcessInJob;
	if (func == pIsProcessorFeaturePresent)
		return wine32a_kernel32_IsProcessorFeaturePresent;
	if (func == pIsSystemResumeAutomatic)
		return wine32a_kernel32_IsSystemResumeAutomatic;
	if (func == pIsThreadAFiber && func != pextIsThreadAFiber)
		return wine_thunk_get_for_any(pextIsThreadAFiber);
	if (func == pIsThreadpoolTimerSet && func != pextIsThreadpoolTimerSet)
		return wine_thunk_get_for_any(pextIsThreadpoolTimerSet);
	if (func == pIsValidCodePage)
		return wine32a_kernel32_IsValidCodePage;
	if (func == pIsValidLanguageGroup)
		return wine32a_kernel32_IsValidLanguageGroup;
	if (func == pIsValidLocale)
		return wine32a_kernel32_IsValidLocale;
	if (func == pIsValidLocaleName)
		return wine32a_kernel32_IsValidLocaleName;
	if (func == pIsWow64Process && func != pextIsWow64Process)
		return wine_thunk_get_for_any(pextIsWow64Process);
	if (func == pK32EmptyWorkingSet)
		return wine32a_kernel32_K32EmptyWorkingSet;
	if (func == pK32EnumDeviceDrivers)
		return wine32a_kernel32_K32EnumDeviceDrivers;
	if (func == pK32EnumPageFilesA)
		return wine32a_kernel32_K32EnumPageFilesA;
	if (func == pK32EnumPageFilesW)
		return wine32a_kernel32_K32EnumPageFilesW;
	if (func == pK32EnumProcessModules)
		return wine32a_kernel32_K32EnumProcessModules;
	if (func == pK32EnumProcessModulesEx)
		return wine32a_kernel32_K32EnumProcessModulesEx;
	if (func == pK32EnumProcesses)
		return wine32a_kernel32_K32EnumProcesses;
	if (func == pK32GetDeviceDriverBaseNameA)
		return wine32a_kernel32_K32GetDeviceDriverBaseNameA;
	if (func == pK32GetDeviceDriverBaseNameW)
		return wine32a_kernel32_K32GetDeviceDriverBaseNameW;
	if (func == pK32GetDeviceDriverFileNameA)
		return wine32a_kernel32_K32GetDeviceDriverFileNameA;
	if (func == pK32GetDeviceDriverFileNameW)
		return wine32a_kernel32_K32GetDeviceDriverFileNameW;
	if (func == pK32GetMappedFileNameA)
		return wine32a_kernel32_K32GetMappedFileNameA;
	if (func == pK32GetMappedFileNameW)
		return wine32a_kernel32_K32GetMappedFileNameW;
	if (func == pK32GetModuleBaseNameA)
		return wine32a_kernel32_K32GetModuleBaseNameA;
	if (func == pK32GetModuleBaseNameW)
		return wine32a_kernel32_K32GetModuleBaseNameW;
	if (func == pK32GetModuleFileNameExA)
		return wine32a_kernel32_K32GetModuleFileNameExA;
	if (func == pK32GetModuleFileNameExW)
		return wine32a_kernel32_K32GetModuleFileNameExW;
	if (func == pK32GetModuleInformation)
		return wine32a_kernel32_K32GetModuleInformation;
	if (func == pK32GetPerformanceInfo)
		return wine32a_kernel32_K32GetPerformanceInfo;
	if (func == pK32GetProcessImageFileNameA)
		return wine32a_kernel32_K32GetProcessImageFileNameA;
	if (func == pK32GetProcessImageFileNameW)
		return wine32a_kernel32_K32GetProcessImageFileNameW;
	if (func == pK32GetProcessMemoryInfo)
		return wine32a_kernel32_K32GetProcessMemoryInfo;
	if (func == pK32GetWsChanges)
		return wine32a_kernel32_K32GetWsChanges;
	if (func == pK32GetWsChangesEx)
		return wine32a_kernel32_K32GetWsChangesEx;
	if (func == pK32InitializeProcessForWsWatch)
		return wine32a_kernel32_K32InitializeProcessForWsWatch;
	if (func == pK32QueryWorkingSet)
		return wine32a_kernel32_K32QueryWorkingSet;
	if (func == pK32QueryWorkingSetEx)
		return wine32a_kernel32_K32QueryWorkingSetEx;
	if (func == pLCIDToLocaleName)
		return wine32a_kernel32_LCIDToLocaleName;
	if (func == pLCMapStringA)
		return wine32a_kernel32_LCMapStringA;
	if (func == pLCMapStringEx)
		return wine32a_kernel32_LCMapStringEx;
	if (func == pLCMapStringW)
		return wine32a_kernel32_LCMapStringW;
	if (func == pLZClose)
		return wine32a_kernel32_LZClose;
	if (func == pLZCopy)
		return wine32a_kernel32_LZCopy;
	if (func == pLZDone)
		return wine32a_kernel32_LZDone;
	if (func == pLZInit)
		return wine32a_kernel32_LZInit;
	if (func == pLZOpenFileA)
		return wine32a_kernel32_LZOpenFileA;
	if (func == pLZOpenFileW)
		return wine32a_kernel32_LZOpenFileW;
	if (func == pLZRead)
		return wine32a_kernel32_LZRead;
	if (func == pLZSeek)
		return wine32a_kernel32_LZSeek;
	if (func == pLZStart)
		return wine32a_kernel32_LZStart;
	if (func == pLeaveCriticalSection && func != pextLeaveCriticalSection)
		return wine_thunk_get_for_any(pextLeaveCriticalSection);
	if (func == pLeaveCriticalSectionWhenCallbackReturns && func != pextLeaveCriticalSectionWhenCallbackReturns)
		return wine_thunk_get_for_any(pextLeaveCriticalSectionWhenCallbackReturns);
	if (func == pLoadLibraryA)
		return wine32a_kernel32_LoadLibraryA;
	if (func == pLoadLibraryExA)
		return wine32a_kernel32_LoadLibraryExA;
	if (func == pLoadLibraryExW)
		return wine32a_kernel32_LoadLibraryExW;
	if (func == pLoadLibraryW)
		return wine32a_kernel32_LoadLibraryW;
	if (func == pLoadModule)
		return wine32a_kernel32_LoadModule;
	if (func == pLoadResource && func != pextLoadResource)
		return wine_thunk_get_for_any(pextLoadResource);
	if (func == pLocalAlloc && func != pextLocalAlloc)
		return wine_thunk_get_for_any(pextLocalAlloc);
	if (func == pLocalCompact)
		return wine32a_kernel32_LocalCompact;
	if (func == pLocalFileTimeToFileTime)
		return wine32a_kernel32_LocalFileTimeToFileTime;
	if (func == pLocalFlags)
		return wine32a_kernel32_LocalFlags;
	if (func == pLocalFree && func != pextLocalFree)
		return wine_thunk_get_for_any(pextLocalFree);
	if (func == pLocalHandle)
		return wine32a_kernel32_LocalHandle;
	if (func == pLocalLock && func != pextLocalLock)
		return wine_thunk_get_for_any(pextLocalLock);
	if (func == pLocalReAlloc && func != pextLocalReAlloc)
		return wine_thunk_get_for_any(pextLocalReAlloc);
	if (func == pLocalShrink)
		return wine32a_kernel32_LocalShrink;
	if (func == pLocalSize)
		return wine32a_kernel32_LocalSize;
	if (func == pLocalUnlock && func != pextLocalUnlock)
		return wine_thunk_get_for_any(pextLocalUnlock);
	if (func == pLocaleNameToLCID)
		return wine32a_kernel32_LocaleNameToLCID;
	if (func == pLockFile && func != pextLockFile)
		return wine_thunk_get_for_any(pextLockFile);
	if (func == pLockFileEx && func != pextLockFileEx)
		return wine_thunk_get_for_any(pextLockFileEx);
	if (func == pLockResource && func != pextLockResource)
		return wine_thunk_get_for_any(pextLockResource);
	if (func == pMakeCriticalSectionGlobal)
		return wine32a_kernel32_MakeCriticalSectionGlobal;
	if (func == pMapUserPhysicalPages)
		return wine32a_kernel32_MapUserPhysicalPages;
	if (func == pMapViewOfFile && func != pextMapViewOfFile)
		return wine_thunk_get_for_any(pextMapViewOfFile);
	if (func == pMapViewOfFileEx && func != pextMapViewOfFileEx)
		return wine_thunk_get_for_any(pextMapViewOfFileEx);
	if (func == pMapViewOfFileExNuma && func != pextMapViewOfFileExNuma)
		return wine_thunk_get_for_any(pextMapViewOfFileExNuma);
	if (func == pModule32First)
		return wine32a_kernel32_Module32First;
	if (func == pModule32FirstW)
		return wine32a_kernel32_Module32FirstW;
	if (func == pModule32Next)
		return wine32a_kernel32_Module32Next;
	if (func == pModule32NextW)
		return wine32a_kernel32_Module32NextW;
	if (func == pMoveFileA)
		return wine32a_kernel32_MoveFileA;
	if (func == pMoveFileExA)
		return wine32a_kernel32_MoveFileExA;
	if (func == pMoveFileExW)
		return wine32a_kernel32_MoveFileExW;
	if (func == pMoveFileTransactedA)
		return wine32a_kernel32_MoveFileTransactedA;
	if (func == pMoveFileTransactedW)
		return wine32a_kernel32_MoveFileTransactedW;
	if (func == pMoveFileW)
		return wine32a_kernel32_MoveFileW;
	if (func == pMoveFileWithProgressA)
		return wine32a_kernel32_MoveFileWithProgressA;
	if (func == pMoveFileWithProgressW)
		return wine32a_kernel32_MoveFileWithProgressW;
	if (func == pMulDiv)
		return wine32a_kernel32_MulDiv;
	if (func == pMultiByteToWideChar)
		return wine32a_kernel32_MultiByteToWideChar;
	if (func == pNeedCurrentDirectoryForExePathA)
		return wine32a_kernel32_NeedCurrentDirectoryForExePathA;
	if (func == pNeedCurrentDirectoryForExePathW)
		return wine32a_kernel32_NeedCurrentDirectoryForExePathW;
	if (func == pNormalizeString)
		return wine32a_kernel32_NormalizeString;
	if (func == pOpenConsoleW)
		return wine32a_kernel32_OpenConsoleW;
	if (func == pOpenEventA && func != pextOpenEventA)
		return wine_thunk_get_for_any(pextOpenEventA);
	if (func == pOpenEventW && func != pextOpenEventW)
		return wine_thunk_get_for_any(pextOpenEventW);
	if (func == pOpenFile)
		return wine32a_kernel32_OpenFile;
	if (func == pOpenFileById && func != pextOpenFileById)
		return wine_thunk_get_for_any(pextOpenFileById);
	if (func == pOpenFileMappingA)
		return wine32a_kernel32_OpenFileMappingA;
	if (func == pOpenFileMappingW && func != pextOpenFileMappingW)
		return wine_thunk_get_for_any(pextOpenFileMappingW);
	if (func == pOpenJobObjectA)
		return wine32a_kernel32_OpenJobObjectA;
	if (func == pOpenJobObjectW)
		return wine32a_kernel32_OpenJobObjectW;
	if (func == pOpenMutexA)
		return wine32a_kernel32_OpenMutexA;
	if (func == pOpenMutexW && func != pextOpenMutexW)
		return wine_thunk_get_for_any(pextOpenMutexW);
	if (func == pOpenProcess && func != pextOpenProcess)
		return wine_thunk_get_for_any(pextOpenProcess);
	if (func == pOpenProfileUserMapping)
		return wine32a_kernel32_OpenProfileUserMapping;
	if (func == pOpenSemaphoreA)
		return wine32a_kernel32_OpenSemaphoreA;
	if (func == pOpenSemaphoreW && func != pextOpenSemaphoreW)
		return wine_thunk_get_for_any(pextOpenSemaphoreW);
	if (func == pOpenThread && func != pextOpenThread)
		return wine_thunk_get_for_any(pextOpenThread);
	if (func == pOpenVxDHandle)
		return wine32a_kernel32_OpenVxDHandle;
	if (func == pOpenWaitableTimerA)
		return wine32a_kernel32_OpenWaitableTimerA;
	if (func == pOpenWaitableTimerW && func != pextOpenWaitableTimerW)
		return wine_thunk_get_for_any(pextOpenWaitableTimerW);
	if (func == pOutputDebugStringA && func != pextOutputDebugStringA)
		return wine_thunk_get_for_any(pextOutputDebugStringA);
	if (func == pOutputDebugStringW && func != pextOutputDebugStringW)
		return wine_thunk_get_for_any(pextOutputDebugStringW);
	if (func == pPeekConsoleInputA && func != pextPeekConsoleInputA)
		return wine_thunk_get_for_any(pextPeekConsoleInputA);
	if (func == pPeekConsoleInputW && func != pextPeekConsoleInputW)
		return wine_thunk_get_for_any(pextPeekConsoleInputW);
	if (func == pPeekNamedPipe && func != pextPeekNamedPipe)
		return wine_thunk_get_for_any(pextPeekNamedPipe);
	if (func == pPostQueuedCompletionStatus && func != pextPostQueuedCompletionStatus)
		return wine_thunk_get_for_any(pextPostQueuedCompletionStatus);
	if (func == pPowerClearRequest)
		return wine32a_kernel32_PowerClearRequest;
	if (func == pPowerCreateRequest)
		return wine32a_kernel32_PowerCreateRequest;
	if (func == pPowerSetRequest)
		return wine32a_kernel32_PowerSetRequest;
	if (func == pPrepareTape)
		return wine32a_kernel32_PrepareTape;
	if (func == pProcess32First)
		return wine32a_kernel32_Process32First;
	if (func == pProcess32FirstW)
		return wine32a_kernel32_Process32FirstW;
	if (func == pProcess32Next)
		return wine32a_kernel32_Process32Next;
	if (func == pProcess32NextW)
		return wine32a_kernel32_Process32NextW;
	if (func == pProcessIdToSessionId)
		return wine32a_kernel32_ProcessIdToSessionId;
	if (func == pPulseEvent && func != pextPulseEvent)
		return wine_thunk_get_for_any(pextPulseEvent);
	if (func == pPurgeComm && func != pextPurgeComm)
		return wine_thunk_get_for_any(pextPurgeComm);
	if (func == pQueryActCtxSettingsW && func != pextQueryActCtxSettingsW)
		return wine_thunk_get_for_any(pextQueryActCtxSettingsW);
	if (func == pQueryActCtxW && func != pextQueryActCtxW)
		return wine_thunk_get_for_any(pextQueryActCtxW);
	if (func == pQueryDepthSList && func != pextQueryDepthSList)
		return wine_thunk_get_for_any(pextQueryDepthSList);
	if (func == pQueryDosDeviceA)
		return wine32a_kernel32_QueryDosDeviceA;
	if (func == pQueryDosDeviceW)
		return wine32a_kernel32_QueryDosDeviceW;
	if (func == pQueryFullProcessImageNameA)
		return wine32a_kernel32_QueryFullProcessImageNameA;
	if (func == pQueryFullProcessImageNameW)
		return wine32a_kernel32_QueryFullProcessImageNameW;
	if (func == pQueryInformationJobObject)
		return wine32a_kernel32_QueryInformationJobObject;
	if (func == pQueryMemoryResourceNotification && func != pextQueryMemoryResourceNotification)
		return wine_thunk_get_for_any(pextQueryMemoryResourceNotification);
	if (func == pQueryPerformanceCounter && func != pextQueryPerformanceCounter)
		return wine_thunk_get_for_any(pextQueryPerformanceCounter);
	if (func == pQueryPerformanceFrequency && func != pextQueryPerformanceFrequency)
		return wine_thunk_get_for_any(pextQueryPerformanceFrequency);
	if (func == pQueryProcessCycleTime)
		return wine32a_kernel32_QueryProcessCycleTime;
	if (func == pQueryThreadCycleTime)
		return wine32a_kernel32_QueryThreadCycleTime;
	if (func == pQueryUmsThreadInformation)
		return wine32a_kernel32_QueryUmsThreadInformation;
	if (func == pQueryUnbiasedInterruptTime)
		return wine32a_kernel32_QueryUnbiasedInterruptTime;
	if (func == pQueueUserAPC && func != pextQueueUserAPC)
		return wine_thunk_get_for_any(pextQueueUserAPC);
	if (func == pQueueUserWorkItem && func != pextQueueUserWorkItem)
		return wine_thunk_get_for_any(pextQueueUserWorkItem);
	if (func == pRaiseException && func != pextRaiseException)
		return wine_thunk_get_for_any(pextRaiseException);
	if (func == pReadConsoleA && func != pextReadConsoleA)
		return wine_thunk_get_for_any(pextReadConsoleA);
	if (func == pReadConsoleInputA && func != pextReadConsoleInputA)
		return wine_thunk_get_for_any(pextReadConsoleInputA);
	if (func == pReadConsoleInputW)
		return wine32a_kernel32_ReadConsoleInputW;
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
	if (func == pReadConsoleW)
		return wine32a_kernel32_ReadConsoleW;
	if (func == pReadDirectoryChangesW && func != pextReadDirectoryChangesW)
		return wine_thunk_get_for_any(pextReadDirectoryChangesW);
	if (func == pReadFile && func != pextReadFile)
		return wine_thunk_get_for_any(pextReadFile);
	if (func == pReadFileEx && func != pextReadFileEx)
		return wine_thunk_get_for_any(pextReadFileEx);
	if (func == pReadFileScatter && func != pextReadFileScatter)
		return wine_thunk_get_for_any(pextReadFileScatter);
	if (func == pReadProcessMemory && func != pextReadProcessMemory)
		return wine_thunk_get_for_any(pextReadProcessMemory);
	if (func == pRegisterApplicationRecoveryCallback)
		return wine32a_kernel32_RegisterApplicationRecoveryCallback;
	if (func == pRegisterApplicationRestart)
		return wine32a_kernel32_RegisterApplicationRestart;
	if (func == pRegisterServiceProcess)
		return wine32a_kernel32_RegisterServiceProcess;
	if (func == pRegisterWaitForSingleObject)
		return wine32a_kernel32_RegisterWaitForSingleObject;
	if (func == pRegisterWaitForSingleObjectEx && func != pextRegisterWaitForSingleObjectEx)
		return wine_thunk_get_for_any(pextRegisterWaitForSingleObjectEx);
	if (func == pReinitializeCriticalSection)
		return wine32a_kernel32_ReinitializeCriticalSection;
	if (func == pReleaseActCtx && func != pextReleaseActCtx)
		return wine_thunk_get_for_any(pextReleaseActCtx);
	if (func == pReleaseMutex && func != pextReleaseMutex)
		return wine_thunk_get_for_any(pextReleaseMutex);
	if (func == pReleaseMutexWhenCallbackReturns && func != pextReleaseMutexWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseMutexWhenCallbackReturns);
	if (func == pReleaseSemaphore && func != pextReleaseSemaphore)
		return wine_thunk_get_for_any(pextReleaseSemaphore);
	if (func == pReleaseSemaphoreWhenCallbackReturns && func != pextReleaseSemaphoreWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseSemaphoreWhenCallbackReturns);
	if (func == pReleaseSRWLockExclusive && func != pextReleaseSRWLockExclusive)
		return wine_thunk_get_for_any(pextReleaseSRWLockExclusive);
	if (func == pReleaseSRWLockShared && func != pextReleaseSRWLockShared)
		return wine_thunk_get_for_any(pextReleaseSRWLockShared);
	if (func == pRemoveDirectoryA)
		return wine32a_kernel32_RemoveDirectoryA;
	if (func == pRemoveDirectoryW)
		return wine32a_kernel32_RemoveDirectoryW;
	if (func == pRemoveVectoredContinueHandler && func != pextRemoveVectoredContinueHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredContinueHandler);
	if (func == pRemoveVectoredExceptionHandler && func != pextRemoveVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredExceptionHandler);
	if (func == pReplaceFileA)
		return wine32a_kernel32_ReplaceFileA;
	if (func == pReplaceFileW)
		return wine32a_kernel32_ReplaceFileW;
	if (func == pRemoveDllDirectory)
		return wine32a_kernel32_RemoveDllDirectory;
	if (func == pRequestDeviceWakeup)
		return wine32a_kernel32_RequestDeviceWakeup;
	if (func == pRequestWakeupLatency)
		return wine32a_kernel32_RequestWakeupLatency;
	if (func == pResetEvent && func != pextResetEvent)
		return wine_thunk_get_for_any(pextResetEvent);
	if (func == pResetWriteWatch && func != pextResetWriteWatch)
		return wine_thunk_get_for_any(pextResetWriteWatch);
	if (func == pResolveDelayLoadedAPI && func != pextResolveDelayLoadedAPI)
		return wine_thunk_get_for_any(pextResolveDelayLoadedAPI);
	if (func == pResolveLocaleName)
		return wine32a_kernel32_ResolveLocaleName;
	if (func == pRestoreLastError && func != pextRestoreLastError)
		return wine_thunk_get_for_any(pextRestoreLastError);
	if (func == pResumeThread && func != pextResumeThread)
		return wine_thunk_get_for_any(pextResumeThread);
	if (func == pRtlAddFunctionTable && func != pextRtlAddFunctionTable)
		return wine_thunk_get_for_any(pextRtlAddFunctionTable);
	if (func == pRtlCaptureContext && func != pextRtlCaptureContext)
		return wine_thunk_get_for_any(pextRtlCaptureContext);
	if (func == pRtlCaptureStackBackTrace && func != pextRtlCaptureStackBackTrace)
		return wine_thunk_get_for_any(pextRtlCaptureStackBackTrace);
	if (func == pRtlCompareMemory && func != pextRtlCompareMemory)
		return wine_thunk_get_for_any(pextRtlCompareMemory);
	if (func == pRtlCopyMemory && func != pextRtlCopyMemory)
		return wine_thunk_get_for_any(pextRtlCopyMemory);
	if (func == pRtlDeleteFunctionTable && func != pextRtlDeleteFunctionTable)
		return wine_thunk_get_for_any(pextRtlDeleteFunctionTable);
	if (func == pRtlFillMemory && func != pextRtlFillMemory)
		return wine_thunk_get_for_any(pextRtlFillMemory);
	if (func == pRtlInstallFunctionTableCallback && func != pextRtlInstallFunctionTableCallback)
		return wine_thunk_get_for_any(pextRtlInstallFunctionTableCallback);
	if (func == pRtlLookupFunctionEntry && func != pextRtlLookupFunctionEntry)
		return wine_thunk_get_for_any(pextRtlLookupFunctionEntry);
	if (func == pRtlMoveMemory && func != pextRtlMoveMemory)
		return wine_thunk_get_for_any(pextRtlMoveMemory);
	if (func == pRtlPcToFileHeader && func != pextRtlPcToFileHeader)
		return wine_thunk_get_for_any(pextRtlPcToFileHeader);
	if (func == pRtlRaiseException && func != pextRtlRaiseException)
		return wine_thunk_get_for_any(pextRtlRaiseException);
	if (func == pRtlRestoreContext && func != pextRtlRestoreContext)
		return wine_thunk_get_for_any(pextRtlRestoreContext);
	if (func == pRtlUnwind && func != pextRtlUnwind)
		return wine_thunk_get_for_any(pextRtlUnwind);
	if (func == pRtlUnwindEx && func != pextRtlUnwindEx)
		return wine_thunk_get_for_any(pextRtlUnwindEx);
	if (func == pRtlVirtualUnwind && func != pextRtlVirtualUnwind)
		return wine_thunk_get_for_any(pextRtlVirtualUnwind);
	if (func == pRtlZeroMemory && func != pextRtlZeroMemory)
		return wine_thunk_get_for_any(pextRtlZeroMemory);
	if (func == pScrollConsoleScreenBufferA && func != pextScrollConsoleScreenBufferA)
		return wine_thunk_get_for_any(pextScrollConsoleScreenBufferA);
	if (func == pScrollConsoleScreenBufferW && func != pextScrollConsoleScreenBufferW)
		return wine_thunk_get_for_any(pextScrollConsoleScreenBufferW);
	if (func == pSearchPathA)
		return wine32a_kernel32_SearchPathA;
	if (func == pSearchPathW)
		return wine32a_kernel32_SearchPathW;
	if (func == pSetCPGlobal)
		return wine32a_kernel32_SetCPGlobal;
	if (func == pSetCalendarInfoA)
		return wine32a_kernel32_SetCalendarInfoA;
	if (func == pSetCalendarInfoW)
		return wine32a_kernel32_SetCalendarInfoW;
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
	if (func == pSetComputerNameA)
		return wine32a_kernel32_SetComputerNameA;
	if (func == pSetComputerNameExA)
		return wine32a_kernel32_SetComputerNameExA;
	if (func == pSetComputerNameExW)
		return wine32a_kernel32_SetComputerNameExW;
	if (func == pSetComputerNameW)
		return wine32a_kernel32_SetComputerNameW;
	if (func == pSetConsoleActiveScreenBuffer && func != pextSetConsoleActiveScreenBuffer)
		return wine_thunk_get_for_any(pextSetConsoleActiveScreenBuffer);
	if (func == pSetConsoleCP && func != pextSetConsoleCP)
		return wine_thunk_get_for_any(pextSetConsoleCP);
	if (func == pSetConsoleCtrlHandler)
		return wine32a_kernel32_SetConsoleCtrlHandler;
	if (func == pSetConsoleCursorInfo && func != pextSetConsoleCursorInfo)
		return wine_thunk_get_for_any(pextSetConsoleCursorInfo);
	if (func == pSetConsoleCursorPosition && func != pextSetConsoleCursorPosition)
		return wine_thunk_get_for_any(pextSetConsoleCursorPosition);
	if (func == pSetConsoleDisplayMode)
		return wine32a_kernel32_SetConsoleDisplayMode;
	if (func == pSetConsoleFont)
		return wine32a_kernel32_SetConsoleFont;
	if (func == pSetConsoleIcon)
		return wine32a_kernel32_SetConsoleIcon;
	if (func == pSetConsoleInputExeNameA && func != pextSetConsoleInputExeNameA)
		return wine_thunk_get_for_any(pextSetConsoleInputExeNameA);
	if (func == pSetConsoleInputExeNameW && func != pextSetConsoleInputExeNameW)
		return wine_thunk_get_for_any(pextSetConsoleInputExeNameW);
	if (func == pSetConsoleKeyShortcuts)
		return wine32a_kernel32_SetConsoleKeyShortcuts;
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
	if (func == pSetConsoleTitleA)
		return wine32a_kernel32_SetConsoleTitleA;
	if (func == pSetConsoleTitleW && func != pextSetConsoleTitleW)
		return wine_thunk_get_for_any(pextSetConsoleTitleW);
	if (func == pSetConsoleWindowInfo && func != pextSetConsoleWindowInfo)
		return wine_thunk_get_for_any(pextSetConsoleWindowInfo);
	if (func == pSetCriticalSectionSpinCount && func != pextSetCriticalSectionSpinCount)
		return wine_thunk_get_for_any(pextSetCriticalSectionSpinCount);
	if (func == pSetCurrentConsoleFontEx)
		return wine32a_kernel32_SetCurrentConsoleFontEx;
	if (func == pSetCurrentDirectoryA)
		return wine32a_kernel32_SetCurrentDirectoryA;
	if (func == pSetCurrentDirectoryW)
		return wine32a_kernel32_SetCurrentDirectoryW;
	if (func == pSetDefaultCommConfigA)
		return wine32a_kernel32_SetDefaultCommConfigA;
	if (func == pSetDefaultCommConfigW)
		return wine32a_kernel32_SetDefaultCommConfigW;
	if (func == pSetDefaultDllDirectories)
		return wine32a_kernel32_SetDefaultDllDirectories;
	if (func == pSetDllDirectoryA)
		return wine32a_kernel32_SetDllDirectoryA;
	if (func == pSetDllDirectoryW)
		return wine32a_kernel32_SetDllDirectoryW;
	if (func == pSetEndOfFile && func != pextSetEndOfFile)
		return wine_thunk_get_for_any(pextSetEndOfFile);
	if (func == pSetEnvironmentVariableA && func != pextSetEnvironmentVariableA)
		return wine_thunk_get_for_any(pextSetEnvironmentVariableA);
	if (func == pSetEnvironmentVariableW && func != pextSetEnvironmentVariableW)
		return wine_thunk_get_for_any(pextSetEnvironmentVariableW);
	if (func == pSetErrorMode && func != pextSetErrorMode)
		return wine_thunk_get_for_any(pextSetErrorMode);
	if (func == pSetEvent && func != pextSetEvent)
		return wine_thunk_get_for_any(pextSetEvent);
	if (func == pSetEventWhenCallbackReturns && func != pextSetEventWhenCallbackReturns)
		return wine_thunk_get_for_any(pextSetEventWhenCallbackReturns);
	if (func == pSetFileApisToANSI && func != pextSetFileApisToANSI)
		return wine_thunk_get_for_any(pextSetFileApisToANSI);
	if (func == pSetFileApisToOEM && func != pextSetFileApisToOEM)
		return wine_thunk_get_for_any(pextSetFileApisToOEM);
	if (func == pSetFileAttributesA && func != pextSetFileAttributesA)
		return wine_thunk_get_for_any(pextSetFileAttributesA);
	if (func == pSetFileAttributesW && func != pextSetFileAttributesW)
		return wine_thunk_get_for_any(pextSetFileAttributesW);
	if (func == pSetFileCompletionNotificationModes)
		return wine32a_kernel32_SetFileCompletionNotificationModes;
	if (func == pSetFileInformationByHandle && func != pextSetFileInformationByHandle)
		return wine_thunk_get_for_any(pextSetFileInformationByHandle);
	if (func == pSetFilePointer && func != pextSetFilePointer)
		return wine_thunk_get_for_any(pextSetFilePointer);
	if (func == pSetFilePointerEx && func != pextSetFilePointerEx)
		return wine_thunk_get_for_any(pextSetFilePointerEx);
	if (func == pSetFileTime && func != pextSetFileTime)
		return wine_thunk_get_for_any(pextSetFileTime);
	if (func == pSetFileValidData && func != pextSetFileValidData)
		return wine_thunk_get_for_any(pextSetFileValidData);
	if (func == pSetHandleContext)
		return wine32a_kernel32_SetHandleContext;
	if (func == pSetHandleCount)
		return wine32a_kernel32_SetHandleCount;
	if (func == pSetHandleInformation)
		return wine32a_kernel32_SetHandleInformation;
	if (func == pSetInformationJobObject)
		return wine32a_kernel32_SetInformationJobObject;
	if (func == pSetLocalTime)
		return wine32a_kernel32_SetLocalTime;
	if (func == pSetLocaleInfoA)
		return wine32a_kernel32_SetLocaleInfoA;
	if (func == pSetLocaleInfoW)
		return wine32a_kernel32_SetLocaleInfoW;
	if (func == pSetMailslotInfo)
		return wine32a_kernel32_SetMailslotInfo;
	if (func == pSetNamedPipeHandleState && func != pextSetNamedPipeHandleState)
		return wine_thunk_get_for_any(pextSetNamedPipeHandleState);
	if (func == pSetPriorityClass && func != pextSetPriorityClass)
		return wine_thunk_get_for_any(pextSetPriorityClass);
	if (func == pSetProcessAffinityMask)
		return wine32a_kernel32_SetProcessAffinityMask;
	if (func == pSetProcessAffinityUpdateMode && func != pextSetProcessAffinityUpdateMode)
		return wine_thunk_get_for_any(pextSetProcessAffinityUpdateMode);
	if (func == pSetProcessDEPPolicy)
		return wine32a_kernel32_SetProcessDEPPolicy;
	if (func == pSetProcessMitigationPolicy && func != pextSetProcessMitigationPolicy)
		return wine_thunk_get_for_any(pextSetProcessMitigationPolicy);
	if (func == pSetProcessPreferredUILanguages)
		return wine32a_kernel32_SetProcessPreferredUILanguages;
	if (func == pSetProcessPriorityBoost && func != pextSetProcessPriorityBoost)
		return wine_thunk_get_for_any(pextSetProcessPriorityBoost);
	if (func == pSetProcessShutdownParameters && func != pextSetProcessShutdownParameters)
		return wine_thunk_get_for_any(pextSetProcessShutdownParameters);
	if (func == pSetProcessWorkingSetSize)
		return wine32a_kernel32_SetProcessWorkingSetSize;
	if (func == pSetProcessWorkingSetSizeEx && func != pextSetProcessWorkingSetSizeEx)
		return wine_thunk_get_for_any(pextSetProcessWorkingSetSizeEx);
	if (func == pSetSearchPathMode)
		return wine32a_kernel32_SetSearchPathMode;
	if (func == pSetStdHandle && func != pextSetStdHandle)
		return wine_thunk_get_for_any(pextSetStdHandle);
	if (func == pSetStdHandleEx && func != pextSetStdHandleEx)
		return wine_thunk_get_for_any(pextSetStdHandleEx);
	if (func == pSetSystemFileCacheSize)
		return wine32a_kernel32_SetSystemFileCacheSize;
	if (func == pSetSystemPowerState)
		return wine32a_kernel32_SetSystemPowerState;
	if (func == pSetSystemTime)
		return wine32a_kernel32_SetSystemTime;
	if (func == pSetSystemTimeAdjustment)
		return wine32a_kernel32_SetSystemTimeAdjustment;
	if (func == pSetTapeParameters)
		return wine32a_kernel32_SetTapeParameters;
	if (func == pSetTapePosition)
		return wine32a_kernel32_SetTapePosition;
	if (func == pSetTermsrvAppInstallMode)
		return wine32a_kernel32_SetTermsrvAppInstallMode;
	if (func == pSetThreadAffinityMask)
		return wine32a_kernel32_SetThreadAffinityMask;
	if (func == pSetThreadContext && func != pextSetThreadContext)
		return wine_thunk_get_for_any(pextSetThreadContext);
	if (func == pSetThreadErrorMode && func != pextSetThreadErrorMode)
		return wine_thunk_get_for_any(pextSetThreadErrorMode);
	if (func == pSetThreadExecutionState)
		return wine32a_kernel32_SetThreadExecutionState;
	if (func == pSetThreadGroupAffinity && func != pextSetThreadGroupAffinity)
		return wine_thunk_get_for_any(pextSetThreadGroupAffinity);
	if (func == pSetThreadIdealProcessor && func != pextSetThreadIdealProcessor)
		return wine_thunk_get_for_any(pextSetThreadIdealProcessor);
	if (func == pSetThreadIdealProcessorEx && func != pextSetThreadIdealProcessorEx)
		return wine_thunk_get_for_any(pextSetThreadIdealProcessorEx);
	if (func == pSetThreadLocale)
		return wine32a_kernel32_SetThreadLocale;
	if (func == pSetThreadPreferredUILanguages)
		return wine32a_kernel32_SetThreadPreferredUILanguages;
	if (func == pSetThreadPriority && func != pextSetThreadPriority)
		return wine_thunk_get_for_any(pextSetThreadPriority);
	if (func == pSetThreadPriorityBoost && func != pextSetThreadPriorityBoost)
		return wine_thunk_get_for_any(pextSetThreadPriorityBoost);
	if (func == pSetThreadStackGuarantee && func != pextSetThreadStackGuarantee)
		return wine_thunk_get_for_any(pextSetThreadStackGuarantee);
	if (func == pSetThreadUILanguage)
		return wine32a_kernel32_SetThreadUILanguage;
	if (func == pSetThreadpoolThreadMaximum && func != pextSetThreadpoolThreadMaximum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMaximum);
	if (func == pSetThreadpoolThreadMinimum && func != pextSetThreadpoolThreadMinimum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMinimum);
	if (func == pSetThreadpoolTimer && func != pextSetThreadpoolTimer)
		return wine_thunk_get_for_any(pextSetThreadpoolTimer);
	if (func == pSetThreadpoolWait && func != pextSetThreadpoolWait)
		return wine_thunk_get_for_any(pextSetThreadpoolWait);
	if (func == pSetTimeZoneInformation)
		return wine32a_kernel32_SetTimeZoneInformation;
	if (func == pSetUmsThreadInformation)
		return wine32a_kernel32_SetUmsThreadInformation;
	if (func == pSetUnhandledExceptionFilter && func != pextSetUnhandledExceptionFilter)
		return wine_thunk_get_for_any(pextSetUnhandledExceptionFilter);
	if (func == pSetUserGeoID)
		return wine32a_kernel32_SetUserGeoID;
	if (func == pSetVolumeLabelA)
		return wine32a_kernel32_SetVolumeLabelA;
	if (func == pSetVolumeLabelW)
		return wine32a_kernel32_SetVolumeLabelW;
	if (func == pSetVolumeMountPointA)
		return wine32a_kernel32_SetVolumeMountPointA;
	if (func == pSetVolumeMountPointW)
		return wine32a_kernel32_SetVolumeMountPointW;
	if (func == pSetWaitableTimer && func != pextSetWaitableTimer)
		return wine_thunk_get_for_any(pextSetWaitableTimer);
	if (func == pSetWaitableTimerEx && func != pextSetWaitableTimerEx)
		return wine_thunk_get_for_any(pextSetWaitableTimerEx);
	if (func == pSetupComm && func != pextSetupComm)
		return wine_thunk_get_for_any(pextSetupComm);
	if (func == pSignalObjectAndWait && func != pextSignalObjectAndWait)
		return wine_thunk_get_for_any(pextSignalObjectAndWait);
	if (func == pSizeofResource && func != pextSizeofResource)
		return wine_thunk_get_for_any(pextSizeofResource);
	if (func == pSleep && func != pextSleep)
		return wine_thunk_get_for_any(pextSleep);
	if (func == pSleepConditionVariableCS && func != pextSleepConditionVariableCS)
		return wine_thunk_get_for_any(pextSleepConditionVariableCS);
	if (func == pSleepConditionVariableSRW && func != pextSleepConditionVariableSRW)
		return wine_thunk_get_for_any(pextSleepConditionVariableSRW);
	if (func == pSleepEx && func != pextSleepEx)
		return wine_thunk_get_for_any(pextSleepEx);
	if (func == pSubmitThreadpoolWork && func != pextSubmitThreadpoolWork)
		return wine_thunk_get_for_any(pextSubmitThreadpoolWork);
	if (func == pSuspendThread && func != pextSuspendThread)
		return wine_thunk_get_for_any(pextSuspendThread);
	if (func == pSwitchToFiber && func != pextSwitchToFiber)
		return wine_thunk_get_for_any(pextSwitchToFiber);
	if (func == pSwitchToThread && func != pextSwitchToThread)
		return wine_thunk_get_for_any(pextSwitchToThread);
	if (func == pSystemTimeToFileTime)
		return wine32a_kernel32_SystemTimeToFileTime;
	if (func == pSystemTimeToTzSpecificLocalTime)
		return wine32a_kernel32_SystemTimeToTzSpecificLocalTime;
	if (func == pTerminateJobObject)
		return wine32a_kernel32_TerminateJobObject;
	if (func == pTerminateProcess && func != pextTerminateProcess)
		return wine_thunk_get_for_any(pextTerminateProcess);
	if (func == pTerminateThread && func != pextTerminateThread)
		return wine_thunk_get_for_any(pextTerminateThread);
	if (func == pTermsrvAppInstallMode)
		return wine32a_kernel32_TermsrvAppInstallMode;
	if (func == pThread32First)
		return wine32a_kernel32_Thread32First;
	if (func == pThread32Next)
		return wine32a_kernel32_Thread32Next;
	if (func == pTlsAlloc && func != pextTlsAlloc)
		return wine_thunk_get_for_any(pextTlsAlloc);
	if (func == pTlsFree && func != pextTlsFree)
		return wine_thunk_get_for_any(pextTlsFree);
	if (func == pTlsGetValue && func != pextTlsGetValue)
		return wine_thunk_get_for_any(pextTlsGetValue);
	if (func == pTlsSetValue && func != pextTlsSetValue)
		return wine_thunk_get_for_any(pextTlsSetValue);
	if (func == pToolhelp32ReadProcessMemory)
		return wine32a_kernel32_Toolhelp32ReadProcessMemory;
	if (func == pTransactNamedPipe && func != pextTransactNamedPipe)
		return wine_thunk_get_for_any(pextTransactNamedPipe);
	if (func == pTransmitCommChar && func != pextTransmitCommChar)
		return wine_thunk_get_for_any(pextTransmitCommChar);
	if (func == pTryAcquireSRWLockExclusive && func != pextTryAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockExclusive);
	if (func == pTryAcquireSRWLockShared && func != pextTryAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockShared);
	if (func == pTryEnterCriticalSection && func != pextTryEnterCriticalSection)
		return wine_thunk_get_for_any(pextTryEnterCriticalSection);
	if (func == pTrySubmitThreadpoolCallback && func != pextTrySubmitThreadpoolCallback)
		return wine_thunk_get_for_any(pextTrySubmitThreadpoolCallback);
	if (func == pTzSpecificLocalTimeToSystemTime)
		return wine32a_kernel32_TzSpecificLocalTimeToSystemTime;
	if (func == pUmsThreadYield)
		return wine32a_kernel32_UmsThreadYield;
	if (func == pUnhandledExceptionFilter && func != pextUnhandledExceptionFilter)
		return wine_thunk_get_for_any(pextUnhandledExceptionFilter);
	if (func == pUninitializeCriticalSection)
		return wine32a_kernel32_UninitializeCriticalSection;
	if (func == pUnlockFile && func != pextUnlockFile)
		return wine_thunk_get_for_any(pextUnlockFile);
	if (func == pUnlockFileEx && func != pextUnlockFileEx)
		return wine_thunk_get_for_any(pextUnlockFileEx);
	if (func == pUnmapViewOfFile && func != pextUnmapViewOfFile)
		return wine_thunk_get_for_any(pextUnmapViewOfFile);
	if (func == pUnregisterApplicationRestart)
		return wine32a_kernel32_UnregisterApplicationRestart;
	if (func == pUnregisterWait)
		return wine32a_kernel32_UnregisterWait;
	if (func == pUnregisterWaitEx && func != pextUnregisterWaitEx)
		return wine_thunk_get_for_any(pextUnregisterWaitEx);
	if (func == pUpdateProcThreadAttribute && func != pextUpdateProcThreadAttribute)
		return wine_thunk_get_for_any(pextUpdateProcThreadAttribute);
	if (func == pUpdateResourceA)
		return wine32a_kernel32_UpdateResourceA;
	if (func == pUpdateResourceW)
		return wine32a_kernel32_UpdateResourceW;
	if (func == pVerLanguageNameA)
		return wine32a_kernel32_VerLanguageNameA;
	if (func == pVerLanguageNameW)
		return wine32a_kernel32_VerLanguageNameW;
	if (func == pVerSetConditionMask && func != pextVerSetConditionMask)
		return wine_thunk_get_for_any(pextVerSetConditionMask);
	if (func == pVerifyConsoleIoHandle)
		return wine32a_kernel32_VerifyConsoleIoHandle;
	if (func == pVerifyVersionInfoA)
		return wine32a_kernel32_VerifyVersionInfoA;
	if (func == pVerifyVersionInfoW)
		return wine32a_kernel32_VerifyVersionInfoW;
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
	if (func == pWTSGetActiveConsoleSessionId)
		return wine32a_kernel32_WTSGetActiveConsoleSessionId;
	if (func == pWaitCommEvent && func != pextWaitCommEvent)
		return wine_thunk_get_for_any(pextWaitCommEvent);
	if (func == pWaitForDebugEvent && func != pextWaitForDebugEvent)
		return wine_thunk_get_for_any(pextWaitForDebugEvent);
	if (func == pWaitForMultipleObjects && func != pextWaitForMultipleObjects)
		return wine_thunk_get_for_any(pextWaitForMultipleObjects);
	if (func == pWaitForMultipleObjectsEx && func != pextWaitForMultipleObjectsEx)
		return wine_thunk_get_for_any(pextWaitForMultipleObjectsEx);
	if (func == pWaitForSingleObject && func != pextWaitForSingleObject)
		return wine_thunk_get_for_any(pextWaitForSingleObject);
	if (func == pWaitForSingleObjectEx && func != pextWaitForSingleObjectEx)
		return wine_thunk_get_for_any(pextWaitForSingleObjectEx);
	if (func == pWaitForThreadpoolTimerCallbacks && func != pextWaitForThreadpoolTimerCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolTimerCallbacks);
	if (func == pWaitForThreadpoolWaitCallbacks && func != pextWaitForThreadpoolWaitCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWaitCallbacks);
	if (func == pWaitForThreadpoolWorkCallbacks && func != pextWaitForThreadpoolWorkCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWorkCallbacks);
	if (func == pWaitNamedPipeA)
		return wine32a_kernel32_WaitNamedPipeA;
	if (func == pWaitNamedPipeW && func != pextWaitNamedPipeW)
		return wine_thunk_get_for_any(pextWaitNamedPipeW);
	if (func == pWakeAllConditionVariable && func != pextWakeAllConditionVariable)
		return wine_thunk_get_for_any(pextWakeAllConditionVariable);
	if (func == pWakeConditionVariable && func != pextWakeConditionVariable)
		return wine_thunk_get_for_any(pextWakeConditionVariable);
	if (func == pWerRegisterFile)
		return wine32a_kernel32_WerRegisterFile;
	if (func == pWerRegisterMemoryBlock)
		return wine32a_kernel32_WerRegisterMemoryBlock;
	if (func == pWerRegisterRuntimeExceptionModule)
		return wine32a_kernel32_WerRegisterRuntimeExceptionModule;
	if (func == pWerSetFlags)
		return wine32a_kernel32_WerSetFlags;
	if (func == pWerUnregisterMemoryBlock)
		return wine32a_kernel32_WerUnregisterMemoryBlock;
	if (func == pWerUnregisterRuntimeExceptionModule)
		return wine32a_kernel32_WerUnregisterRuntimeExceptionModule;
	if (func == pWideCharToMultiByte)
		return wine32a_kernel32_WideCharToMultiByte;
	if (func == pWinExec)
		return wine32a_kernel32_WinExec;
	if (func == pWow64EnableWow64FsRedirection)
		return wine32a_kernel32_Wow64EnableWow64FsRedirection;
	if (func == pWow64DisableWow64FsRedirection && func != pextWow64DisableWow64FsRedirection)
		return wine_thunk_get_for_any(pextWow64DisableWow64FsRedirection);
	if (func == pWow64GetThreadContext)
		return wine32a_kernel32_Wow64GetThreadContext;
	if (func == pWow64RevertWow64FsRedirection && func != pextWow64RevertWow64FsRedirection)
		return wine_thunk_get_for_any(pextWow64RevertWow64FsRedirection);
	if (func == pWow64SetThreadContext)
		return wine32a_kernel32_Wow64SetThreadContext;
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
	if (func == pWriteConsoleW)
		return wine32a_kernel32_WriteConsoleW;
	if (func == pWriteFile && func != pextWriteFile)
		return wine_thunk_get_for_any(pextWriteFile);
	if (func == pWriteFileEx && func != pextWriteFileEx)
		return wine_thunk_get_for_any(pextWriteFileEx);
	if (func == pWriteFileGather && func != pextWriteFileGather)
		return wine_thunk_get_for_any(pextWriteFileGather);
	if (func == pWritePrivateProfileSectionA)
		return wine32a_kernel32_WritePrivateProfileSectionA;
	if (func == pWritePrivateProfileSectionW)
		return wine32a_kernel32_WritePrivateProfileSectionW;
	if (func == pWritePrivateProfileStringA)
		return wine32a_kernel32_WritePrivateProfileStringA;
	if (func == pWritePrivateProfileStringW)
		return wine32a_kernel32_WritePrivateProfileStringW;
	if (func == pWritePrivateProfileStructA)
		return wine32a_kernel32_WritePrivateProfileStructA;
	if (func == pWritePrivateProfileStructW)
		return wine32a_kernel32_WritePrivateProfileStructW;
	if (func == pWriteProcessMemory && func != pextWriteProcessMemory)
		return wine_thunk_get_for_any(pextWriteProcessMemory);
	if (func == pWriteProfileSectionA)
		return wine32a_kernel32_WriteProfileSectionA;
	if (func == pWriteProfileSectionW)
		return wine32a_kernel32_WriteProfileSectionW;
	if (func == pWriteProfileStringA)
		return wine32a_kernel32_WriteProfileStringA;
	if (func == pWriteProfileStringW)
		return wine32a_kernel32_WriteProfileStringW;
	if (func == pWriteTapemark)
		return wine32a_kernel32_WriteTapemark;
	if (func == pZombifyActCtx && func != pextZombifyActCtx)
		return wine_thunk_get_for_any(pextZombifyActCtx);
	if (func == p_hread)
		return wine32a_kernel32__hread;
	if (func == p_hwrite)
		return wine32a_kernel32__hwrite;
	if (func == p_lclose)
		return wine32a_kernel32__lclose;
	if (func == p_lcreat)
		return wine32a_kernel32__lcreat;
	if (func == p_llseek)
		return wine32a_kernel32__llseek;
	if (func == p_lopen)
		return wine32a_kernel32__lopen;
	if (func == p_lread)
		return wine32a_kernel32__lread;
	if (func == p_lwrite)
		return wine32a_kernel32__lwrite;
	if (func == plstrcatA)
		return wine32a_kernel32_lstrcatA;
	if (func == plstrcatW)
		return wine32a_kernel32_lstrcatW;
	if (func == plstrcmp && func != pextlstrcmp)
		return wine_thunk_get_for_any(pextlstrcmp);
	if (func == plstrcmpA && func != pextlstrcmpA)
		return wine_thunk_get_for_any(pextlstrcmpA);
	if (func == plstrcmpW && func != pextlstrcmpW)
		return wine_thunk_get_for_any(pextlstrcmpW);
	if (func == plstrcmpi && func != pextlstrcmpi)
		return wine_thunk_get_for_any(pextlstrcmpi);
	if (func == plstrcmpiA && func != pextlstrcmpiA)
		return wine_thunk_get_for_any(pextlstrcmpiA);
	if (func == plstrcmpiW && func != pextlstrcmpiW)
		return wine_thunk_get_for_any(pextlstrcmpiW);
	if (func == plstrcpyA)
		return wine32a_kernel32_lstrcpyA;
	if (func == plstrcpyW)
		return wine32a_kernel32_lstrcpyW;
	if (func == plstrcpyn && func != pextlstrcpyn)
		return wine_thunk_get_for_any(pextlstrcpyn);
	if (func == plstrcpynA && func != pextlstrcpynA)
		return wine_thunk_get_for_any(pextlstrcpynA);
	if (func == plstrcpynW && func != pextlstrcpynW)
		return wine_thunk_get_for_any(pextlstrcpynW);
	if (func == plstrlen && func != pextlstrlen)
		return wine_thunk_get_for_any(pextlstrlen);
	if (func == plstrlenA && func != pextlstrlenA)
		return wine_thunk_get_for_any(pextlstrlenA);
	if (func == plstrlenW && func != pextlstrlenW)
		return wine_thunk_get_for_any(pextlstrlenW);
	if (func == pwine_get_unix_file_name)
		return wine32a_kernel32_wine_get_unix_file_name;
	if (func == pwine_get_dos_file_name)
		return wine32a_kernel32_wine_get_dos_file_name;
	if (func == p__wine_kernel_init)
		return wine32a_kernel32___wine_kernel_init;

	return NULL;
}
