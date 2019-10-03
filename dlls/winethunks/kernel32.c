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

typedef long INT_PTR; /* ../include/basetsd.h:117 */

typedef long LONG_PTR; /* ../include/basetsd.h:118 */

typedef unsigned long UINT_PTR; /* ../include/basetsd.h:119 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef unsigned long* PULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR DWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR* PDWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR SIZE_T; /* ../include/basetsd.h:264 */

typedef ULONG_PTR* PSIZE_T; /* ../include/basetsd.h:264 */

typedef ULONG_PTR KAFFINITY; /* ../include/basetsd.h:266 */

typedef void* DLL_DIRECTORY_COOKIE; /* ../include/libloaderapi.h:26 */

typedef struct _MODULEINFO /* ../include/psapi.h:28 */
{
    LPVOID lpBaseOfDll;
    DWORD SizeOfImage;
    LPVOID EntryPoint;
}  MODULEINFO, * LPMODULEINFO;

typedef struct _PROCESS_MEMORY_COUNTERS /* ../include/psapi.h:34 */
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
}  PROCESS_MEMORY_COUNTERS;

typedef PROCESS_MEMORY_COUNTERS* PPROCESS_MEMORY_COUNTERS; /* ../include/psapi.h:46 */

typedef struct _PSAPI_WS_WATCH_INFORMATION /* ../include/psapi.h:48 */
{
    LPVOID FaultingPc;
    LPVOID FaultingVa;
}  PSAPI_WS_WATCH_INFORMATION, * PPSAPI_WS_WATCH_INFORMATION;

typedef struct _PSAPI_WS_WATCH_INFORMATION_EX /* ../include/psapi.h:53 */
{
    PSAPI_WS_WATCH_INFORMATION BasicInfo;
    ULONG_PTR FaultingThreadId;
    ULONG_PTR Flags;
}  PSAPI_WS_WATCH_INFORMATION_EX, * PPSAPI_WS_WATCH_INFORMATION_EX;

typedef struct _PERFORMANCE_INFORMATION /* ../include/psapi.h:59 */
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
}  PERFORMANCE_INFORMATION, * PPERFORMANCE_INFORMATION;

typedef struct _ENUM_PAGE_FILE_INFORMATION /* ../include/psapi.h:76 */
{
    DWORD cb;
    DWORD Reserved;
    SIZE_T TotalSize;
    SIZE_T TotalInUse;
    SIZE_T PeakUsage;
}  ENUM_PAGE_FILE_INFORMATION, * PENUM_PAGE_FILE_INFORMATION;

typedef BOOL (*PENUM_PAGE_FILE_CALLBACKA) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCSTR); /* ../include/psapi.h:84 */

typedef BOOL (*PENUM_PAGE_FILE_CALLBACKW) (LPVOID, PENUM_PAGE_FILE_INFORMATION, LPCWSTR); /* ../include/psapi.h:85 */

typedef struct tagTHREADENTRY32 /* ../include/tlhelp32.h:43 */
{
    DWORD dwSize;
    DWORD cntUsage;
    DWORD th32ThreadID;
    DWORD th32OwnerProcessID;
    LONG tpBasePri;
    LONG tpDeltaPri;
    DWORD dwFlags;
}  THREADENTRY32, * PTHREADENTRY32, * LPTHREADENTRY32;

typedef struct tagPROCESSENTRY32 /* ../include/tlhelp32.h:61 */
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
}  PROCESSENTRY32, * PPROCESSENTRY32, * LPPROCESSENTRY32;

typedef struct tagPROCESSENTRY32W /* ../include/tlhelp32.h:75 */
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
}  PROCESSENTRY32W, * PPROCESSENTRY32W, * LPPROCESSENTRY32W;

typedef struct tagMODULEENTRY32 /* ../include/tlhelp32.h:108 */
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
}  MODULEENTRY32, * PMODULEENTRY32, * LPMODULEENTRY32;

typedef struct tagMODULEENTRY32W /* ../include/tlhelp32.h:122 */
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
}  MODULEENTRY32W, * PMODULEENTRY32W, * LPMODULEENTRY32W;

typedef struct tagHEAPLIST32 /* ../include/tlhelp32.h:149 */
{
    SIZE_T dwSize;
    DWORD th32ProcessID;
    ULONG_PTR th32HeapID;
    DWORD dwFlags;
}  HEAPLIST32, * PHEAPLIST32, * LPHEAPLIST32;

typedef enum _WER_REGISTER_FILE_TYPE /* ../include/werapi.h:83 */
{
    DUMMY42 = 0
}  WER_REGISTER_FILE_TYPE;

static WINAPI ATOM (*pAddAtomA)(LPCSTR str);
static WINAPI ATOM (*pAddAtomW)(LPCWSTR str);
static WINAPI BOOL (*pAddConsoleAliasA)(LPSTR source, LPSTR target, LPSTR exename);
static WINAPI BOOL (*pAddConsoleAliasW)(LPWSTR source, LPWSTR target, LPWSTR exename);
static WINAPI DLL_DIRECTORY_COOKIE (*pAddDllDirectory)(WCHAR* dir);
static WINAPI BOOL (*pAllocConsole)(void);
static WINAPI BOOL (*pAllocateUserPhysicalPages)(HANDLE process, ULONG_PTR* pages, ULONG_PTR* userarray);
static WINAPI void (*pApplicationRecoveryFinished)(BOOL success);
static WINAPI HRESULT (*pApplicationRecoveryInProgress)(PBOOL canceled);
static WINAPI BOOL (*pAssignProcessToJobObject)(HANDLE job, HANDLE process);
static WINAPI BOOL (*pBackupRead)(HANDLE file, LPBYTE buffer, DWORD to_read, LPDWORD read, BOOL abort, BOOL security, LPVOID* context);
static WINAPI BOOL (*pBackupSeek)(HANDLE file, DWORD seek_low, DWORD seek_high, LPDWORD seeked_low, LPDWORD seeked_high, LPVOID* context);
static WINAPI BOOL (*pBackupWrite)(HANDLE file, LPBYTE buffer, DWORD to_write, LPDWORD written, BOOL abort, BOOL security, LPVOID* context);
static WINAPI BOOL (*pBaseFlushAppcompatCache)(void);
static WINAPI BOOL (*pBeep)(DWORD dwFreq, DWORD dwDur);
static WINAPI HANDLE (*pBeginUpdateResourceA)(LPCSTR pFileName, BOOL bDeleteExistingResources);
static WINAPI HANDLE (*pBeginUpdateResourceW)(LPCWSTR pFileName, BOOL bDeleteExistingResources);
static WINAPI BOOL (*pBindIoCompletionCallback)(HANDLE FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags);
static WINAPI BOOL (*pBuildCommDCBA)(LPCSTR device, LPDCB lpdcb);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsA)(LPCSTR device, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pBuildCommDCBAndTimeoutsW)(LPCWSTR devid, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts);
static WINAPI BOOL (*pBuildCommDCBW)(LPCWSTR devid, LPDCB lpdcb);
static WINAPI BOOL (*pCallNamedPipeA)(LPCSTR lpNamedPipeName, LPVOID lpInput, DWORD dwInputSize, LPVOID lpOutput, DWORD dwOutputSize, LPDWORD lpBytesRead, DWORD nTimeout);
static WINAPI BOOL (*pCancelTimerQueueTimer)(HANDLE queue, HANDLE timer);
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3A)(char* name, char* oemname, DWORD oemname_len, BOOL* contains_spaces, BOOL* is_legal);
static WINAPI BOOL (*pCheckNameLegalDOS8Dot3W)(WCHAR* name, char* oemname, DWORD oemname_len, BOOL* contains_spaces_ret, BOOL* is_legal);
static WINAPI BOOL (*pCloseConsoleHandle)(HANDLE handle);
static WINAPI BOOL (*pCloseHandle)(HANDLE handle);
static WINAPI BOOL (*pCloseProfileUserMapping)(void);
static WINAPI BOOL (*pCmdBatNotification)(BOOL bBatchRunning);
static WINAPI BOOL (*pCommConfigDialogA)(LPCSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig);
static WINAPI BOOL (*pCommConfigDialogW)(LPCWSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig);
static WINAPI INT (*pCompareFileTime)(FILETIME* x, FILETIME* y);
static WINAPI INT (*pCompareStringA)(LCID lcid, DWORD flags, LPCSTR str1, INT len1, LPCSTR str2, INT len2);
static WINAPI INT (*pCompareStringEx)(LPCWSTR locale, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lParam);
static WINAPI INT (*pCompareStringOrdinal)(WCHAR* str1, INT len1, WCHAR* str2, INT len2, BOOL ignore_case);
static WINAPI INT (*pCompareStringW)(LCID lcid, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2);
static WINAPI LCID (*pConvertDefaultLocale)(LCID lcid);
static WINAPI HANDLE (*pConvertToGlobalHandle)(HANDLE hSrc);
static WINAPI BOOL (*pCopyFileA)(LPCSTR source, LPCSTR dest, BOOL fail_if_exists);
static WINAPI BOOL (*pCopyFileExA)(LPCSTR sourceFilename, LPCSTR destFilename, LPPROGRESS_ROUTINE progressRoutine, LPVOID appData, LPBOOL cancelFlagPointer, DWORD copyFlags);
static WINAPI BOOL (*pCopyFileExW)(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE progress, LPVOID param, LPBOOL cancel_ptr, DWORD flags);
static WINAPI BOOL (*pCopyFileW)(LPCWSTR source, LPCWSTR dest, BOOL fail_if_exists);
static WINAPI HANDLE (*pCreateActCtxA)(PCACTCTXA pActCtx);
static WINAPI BOOL (*pCreateDirectoryExA)(LPCSTR template, LPCSTR path, LPSECURITY_ATTRIBUTES sa);
static WINAPI HANDLE (*pCreateFileMappingA)(HANDLE file, SECURITY_ATTRIBUTES* sa, DWORD protect, DWORD size_high, DWORD size_low, LPCSTR name);
static WINAPI BOOL (*pCreateHardLinkA)(LPCSTR lpFileName, LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
static WINAPI BOOL (*pCreateHardLinkTransactedA)(LPCSTR link, LPCSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction);
static WINAPI BOOL (*pCreateHardLinkTransactedW)(LPCWSTR link, LPCWSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction);
static WINAPI BOOL (*pCreateHardLinkW)(LPCWSTR lpFileName, LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
static WINAPI HANDLE (*pCreateJobObjectA)(LPSECURITY_ATTRIBUTES attr, LPCSTR name);
static WINAPI HANDLE (*pCreateJobObjectW)(LPSECURITY_ATTRIBUTES sa, LPCWSTR name);
static WINAPI HANDLE (*pCreateMailslotA)(LPCSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa);
static WINAPI HANDLE (*pCreateMailslotW)(LPCWSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa);
static WINAPI HANDLE (*pCreateNamedPipeA)(LPCSTR name, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES attr);
static WINAPI BOOL (*pCreatePipe)(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES sa, DWORD size);
static WINAPI BOOL (*pCreateProcessA)(LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessAsUserA)(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessAsUserW)(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info);
static WINAPI BOOL (*pCreateProcessInternalA)(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info, HANDLE* new_token);
static WINAPI BOOL (*pCreateProcessInternalW)(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info, HANDLE* new_token);
static WINAPI BOOL (*pCreateProcessW)(LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info);
static WINAPI HANDLE (*pCreateSemaphoreA)(SECURITY_ATTRIBUTES* sa, LONG initial, LONG max, LPCSTR name);
static WINAPI HANDLE (*pCreateSemaphoreExA)(SECURITY_ATTRIBUTES* sa, LONG initial, LONG max, LPCSTR name, DWORD flags, DWORD access);
static WINAPI HANDLE (*pCreateSocketHandle)(void);
static WINAPI BOOLEAN (*pCreateSymbolicLinkA)(LPCSTR link, LPCSTR target, DWORD flags);
static WINAPI BOOLEAN (*pCreateSymbolicLinkW)(LPCWSTR link, LPCWSTR target, DWORD flags);
static WINAPI DWORD (*pCreateTapePartition)(HANDLE device, DWORD method, DWORD count, DWORD size);
static WINAPI HANDLE (*pCreateToolhelp32Snapshot)(DWORD flags, DWORD process);
static WINAPI BOOL (*pCreateUmsCompletionList)(PUMS_COMPLETION_LIST* list);
static WINAPI BOOL (*pCreateUmsThreadContext)(PUMS_CONTEXT* ctx);
static WINAPI HANDLE (*pCreateWaitableTimerA)(SECURITY_ATTRIBUTES* sa, BOOL manual, LPCSTR name);
static WINAPI HANDLE (*pCreateWaitableTimerExA)(SECURITY_ATTRIBUTES* sa, LPCSTR name, DWORD flags, DWORD access);
static WINAPI BOOL (*pDebugBreakProcess)(HANDLE process);
static WINAPI BOOL (*pDebugSetProcessKillOnExit)(BOOL kill);
static WINAPI BOOL (*pDefineDosDeviceA)(DWORD flags, LPCSTR devname, LPCSTR targetpath);
static WINAPI BOOL (*pDefineDosDeviceW)(DWORD flags, LPCWSTR devname, LPCWSTR targetpath);
static WINAPI FARPROC (*pDelayLoadFailureHook)(LPCSTR name, LPCSTR function);
static WINAPI ATOM (*pDeleteAtom)(ATOM atom);
static WINAPI BOOL (*pDeleteTimerQueue)(HANDLE TimerQueue);
static WINAPI BOOL (*pDeleteUmsCompletionList)(PUMS_COMPLETION_LIST list);
static WINAPI BOOL (*pDeleteUmsThreadContext)(PUMS_CONTEXT ctx);
static WINAPI BOOL (*pDeleteVolumeMountPointA)(LPCSTR mountpoint);
static WINAPI BOOL (*pDeleteVolumeMountPointW)(LPCWSTR mountpoint);
static WINAPI BOOL (*pDequeueUmsCompletionListItems)(void* list, DWORD timeout, PUMS_CONTEXT* ctx);
static WINAPI BOOL (*pDeviceIoControl)(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPOVERLAPPED lpOverlapped);
static WINAPI BOOL (*pDnsHostnameToComputerNameA)(LPCSTR hostname, LPSTR computername, LPDWORD size);
static WINAPI BOOL (*pDnsHostnameToComputerNameW)(LPCWSTR hostname, LPWSTR computername, LPDWORD size);
static WINAPI BOOL (*pDosDateTimeToFileTime)(WORD fatdate, WORD fattime, LPFILETIME ft);
static WINAPI HANDLE (*pDuplicateConsoleHandle)(HANDLE handle, DWORD access, BOOL inherit, DWORD options);
static WINAPI BOOL (*pDuplicateHandle)(HANDLE source_process, HANDLE source, HANDLE dest_process, HANDLE* dest, DWORD access, BOOL inherit, DWORD options);
static WINAPI BOOL (*pEndUpdateResourceA)(HANDLE hUpdate, BOOL fDiscard);
static WINAPI BOOL (*pEndUpdateResourceW)(HANDLE hUpdate, BOOL fDiscard);
static WINAPI BOOL (*pEnterUmsSchedulingMode)(UMS_SCHEDULER_STARTUP_INFO* info);
static WINAPI BOOL (*pEnumCalendarInfoA)(CALINFO_ENUMPROCA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoExA)(CALINFO_ENUMPROCEXA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoExEx)(CALINFO_ENUMPROCEXEX calinfoproc, LPCWSTR locale, CALID calendar, LPCWSTR reserved, CALTYPE caltype, LPARAM lParam);
static WINAPI BOOL (*pEnumCalendarInfoExW)(CALINFO_ENUMPROCEXW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumCalendarInfoW)(CALINFO_ENUMPROCW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype);
static WINAPI BOOL (*pEnumDateFormatsA)(DATEFMT_ENUMPROCA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsExA)(DATEFMT_ENUMPROCEXA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsExEx)(DATEFMT_ENUMPROCEXEX proc, WCHAR* locale, DWORD flags, LPARAM lParam);
static WINAPI BOOL (*pEnumDateFormatsExW)(DATEFMT_ENUMPROCEXW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumDateFormatsW)(DATEFMT_ENUMPROCW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumLanguageGroupLocalesA)(LANGGROUPLOCALE_ENUMPROCA pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumLanguageGroupLocalesW)(LANGGROUPLOCALE_ENUMPROCW pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumResourceLanguagesA)(HMODULE hmod, LPCSTR type, LPCSTR name, ENUMRESLANGPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceLanguagesW)(HMODULE hmod, LPCWSTR type, LPCWSTR name, ENUMRESLANGPROCW lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceNamesA)(HMODULE hmod, LPCSTR type, ENUMRESNAMEPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceTypesA)(HMODULE hmod, ENUMRESTYPEPROCA lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumResourceTypesW)(HMODULE hmod, ENUMRESTYPEPROCW lpfun, LONG_PTR lparam);
static WINAPI BOOL (*pEnumSystemCodePagesA)(CODEPAGE_ENUMPROCA lpfnCodePageEnum, DWORD flags);
static WINAPI BOOL (*pEnumSystemCodePagesW)(CODEPAGE_ENUMPROCW lpfnCodePageEnum, DWORD flags);
static WINAPI UINT (*pEnumSystemFirmwareTables)(DWORD provider, void* buffer, DWORD size);
static WINAPI BOOL (*pEnumSystemGeoID)(GEOCLASS geoclass, GEOID parent, GEO_ENUMPROC enumproc);
static WINAPI BOOL (*pEnumSystemLanguageGroupsA)(LANGUAGEGROUP_ENUMPROCA pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumSystemLanguageGroupsW)(LANGUAGEGROUP_ENUMPROCW pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumSystemLocalesA)(LOCALE_ENUMPROCA lpfnLocaleEnum, DWORD dwFlags);
static WINAPI BOOL (*pEnumSystemLocalesEx)(LOCALE_ENUMPROCEX proc, DWORD flags, LPARAM lparam, LPVOID reserved);
static WINAPI BOOL (*pEnumSystemLocalesW)(LOCALE_ENUMPROCW lpfnLocaleEnum, DWORD dwFlags);
static WINAPI BOOL (*pEnumTimeFormatsA)(TIMEFMT_ENUMPROCA proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumTimeFormatsEx)(TIMEFMT_ENUMPROCEX proc, WCHAR* locale, DWORD flags, LPARAM lParam);
static WINAPI BOOL (*pEnumTimeFormatsW)(TIMEFMT_ENUMPROCW proc, LCID lcid, DWORD flags);
static WINAPI BOOL (*pEnumUILanguagesA)(UILANGUAGE_ENUMPROCA pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI BOOL (*pEnumUILanguagesW)(UILANGUAGE_ENUMPROCW pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam);
static WINAPI DWORD (*pEraseTape)(HANDLE device, DWORD type, BOOL immediate);
static WINAPI BOOL (*pExecuteUmsThread)(PUMS_CONTEXT ctx);
static WINAPI void (*pExitProcess)(DWORD status);
static WINAPI void (*pExpungeConsoleCommandHistoryA)(LPCSTR unknown);
static WINAPI void (*pExpungeConsoleCommandHistoryW)(LPCWSTR unknown);
static WINAPI void (*pFatalExit)(int code);
static WINAPI BOOL (*pFileTimeToDosDateTime)(FILETIME* ft, LPWORD fatdate, LPWORD fattime);
static WINAPI BOOL (*pFileTimeToLocalFileTime)(FILETIME* utcft, LPFILETIME localft);
static WINAPI BOOL (*pFileTimeToSystemTime)(FILETIME* ft, LPSYSTEMTIME syst);
static WINAPI BOOL (*pFindActCtxSectionStringA)(DWORD dwFlags, GUID* lpExtGuid, ULONG ulId, LPCSTR lpSearchStr, PACTCTX_SECTION_KEYED_DATA pInfo);
static WINAPI ATOM (*pFindAtomA)(LPCSTR str);
static WINAPI ATOM (*pFindAtomW)(LPCWSTR str);
static WINAPI BOOL (*pFindClose)(HANDLE handle);
static WINAPI HANDLE (*pFindFirstFileA)(LPCSTR lpFileName, WIN32_FIND_DATAA* lpFindData);
static WINAPI HANDLE (*pFindFirstFileExA)(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags);
static WINAPI HANDLE (*pFindFirstFileExW)(LPCWSTR filename, FINDEX_INFO_LEVELS level, LPVOID data, FINDEX_SEARCH_OPS search_op, LPVOID filter, DWORD flags);
static WINAPI HANDLE (*pFindFirstFileW)(LPCWSTR lpFileName, WIN32_FIND_DATAW* lpFindData);
static WINAPI HANDLE (*pFindFirstStreamW)(LPCWSTR filename, STREAM_INFO_LEVELS infolevel, void* data, DWORD flags);
static WINAPI HANDLE (*pFindFirstVolumeA)(LPSTR volume, DWORD len);
static WINAPI HANDLE (*pFindFirstVolumeMountPointA)(LPCSTR root, LPSTR mount_point, DWORD len);
static WINAPI HANDLE (*pFindFirstVolumeMountPointW)(LPCWSTR root, LPWSTR mount_point, DWORD len);
static WINAPI HANDLE (*pFindFirstVolumeW)(LPWSTR volume, DWORD len);
static WINAPI INT (*pFindNLSStringEx)(WCHAR* localename, DWORD flags, WCHAR* src, INT src_size, WCHAR* value, INT value_size, INT* found, NLSVERSIONINFO* version_info, void* reserved, LPARAM sort_handle);
static WINAPI BOOL (*pFindNextFileA)(HANDLE handle, WIN32_FIND_DATAA* data);
static WINAPI BOOL (*pFindNextFileW)(HANDLE handle, WIN32_FIND_DATAW* data);
static WINAPI BOOL (*pFindNextStreamW)(HANDLE handle, void* data);
static WINAPI BOOL (*pFindNextVolumeA)(HANDLE handle, LPSTR volume, DWORD len);
static WINAPI BOOL (*pFindNextVolumeW)(HANDLE handle, LPWSTR volume, DWORD len);
static WINAPI HRSRC (*pFindResourceA)(HMODULE hModule, LPCSTR name, LPCSTR type);
static WINAPI HRSRC (*pFindResourceExA)(HMODULE module, LPCSTR type, LPCSTR name, WORD lang);
static WINAPI INT (*pFindStringOrdinal)(DWORD flag, WCHAR* src, INT src_size, WCHAR* val, INT val_size, BOOL ignore_case);
static WINAPI BOOL (*pFindVolumeClose)(HANDLE handle);
static WINAPI BOOL (*pFindVolumeMountPointClose)(HANDLE h);
static WINAPI BOOL (*pFlushConsoleInputBuffer)(HANDLE handle);
static WINAPI void (*pFlushProcessWriteBuffers)(void);
static WINAPI INT (*pFoldStringA)(DWORD dwFlags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen);
static WINAPI INT (*pFoldStringW)(DWORD dwFlags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI DWORD (*pFormatMessageA)(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, __builtin_ms_va_list* args);
static WINAPI DWORD (*pFormatMessageW)(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, __builtin_ms_va_list* args);
static WINAPI BOOL (*pFreeConsole)(void);
static WINAPI BOOL (*pFreeLibrary)(HINSTANCE hLibModule);
static WINAPI void (*pFreeLibraryAndExitThread)(HINSTANCE hLibModule, DWORD dwExitCode);
static WINAPI BOOL (*pFreeUserPhysicalPages)(HANDLE process, ULONG_PTR* pages, ULONG_PTR* userarray);
static WINAPI UINT (*pGetACP)(void);
static WINAPI DWORD (*pGetActiveProcessorCount)(WORD group);
static WINAPI WORD (*pGetActiveProcessorGroupCount)(void);
static WINAPI HRESULT (*pGetApplicationRestartSettings)(HANDLE process, WCHAR* cmdline, DWORD* size, DWORD* flags);
static WINAPI UINT (*pGetAtomNameA)(ATOM atom, LPSTR buffer, INT count);
static WINAPI UINT (*pGetAtomNameW)(ATOM atom, LPWSTR buffer, INT count);
static WINAPI BOOL (*pGetBinaryTypeA)(LPCSTR lpApplicationName, LPDWORD lpBinaryType);
static WINAPI BOOL (*pGetBinaryTypeW)(LPCWSTR name, LPDWORD type);
static WINAPI BOOL (*pGetCPInfo)(UINT codepage, LPCPINFO cpinfo);
static WINAPI BOOL (*pGetCPInfoExA)(UINT codepage, DWORD dwFlags, LPCPINFOEXA cpinfo);
static WINAPI BOOL (*pGetCPInfoExW)(UINT codepage, DWORD dwFlags, LPCPINFOEXW cpinfo);
static WINAPI INT (*pGetCalendarInfoA)(LCID lcid, CALID Calendar, CALTYPE CalType, LPSTR lpCalData, int cchData, LPDWORD lpValue);
static WINAPI int (*pGetCalendarInfoEx)(LPCWSTR locale, CALID calendar, LPCWSTR lpReserved, CALTYPE caltype, LPWSTR data, int len, DWORD* value);
static WINAPI INT (*pGetCalendarInfoW)(LCID Locale, CALID Calendar, CALTYPE CalType, LPWSTR lpCalData, int cchData, LPDWORD lpValue);
static WINAPI BOOL (*pGetComputerNameA)(LPSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameExA)(COMPUTER_NAME_FORMAT type, LPSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameExW)(COMPUTER_NAME_FORMAT type, LPWSTR name, LPDWORD size);
static WINAPI BOOL (*pGetComputerNameW)(LPWSTR name, LPDWORD size);
static WINAPI DWORD (*pGetConsoleAliasExesLengthA)(void);
static WINAPI DWORD (*pGetConsoleAliasExesLengthW)(void);
static WINAPI DWORD (*pGetConsoleAliasW)(LPWSTR lpSource, LPWSTR lpTargetBuffer, DWORD TargetBufferLength, LPWSTR lpExename);
static WINAPI DWORD (*pGetConsoleAliasesLengthA)(LPSTR unknown);
static WINAPI DWORD (*pGetConsoleAliasesLengthW)(LPWSTR unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryA)(DWORD unknown1, DWORD unknown2, DWORD unknown3);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthA)(LPCSTR unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryLengthW)(LPCWSTR unknown);
static WINAPI DWORD (*pGetConsoleCommandHistoryW)(DWORD unknown1, DWORD unknown2, DWORD unknown3);
static WINAPI BOOL (*pGetConsoleDisplayMode)(LPDWORD lpModeFlags);
static WINAPI BOOL (*pGetConsoleFontInfo)(HANDLE hConsole, BOOL maximize, DWORD numfonts, CONSOLE_FONT_INFO* info);
static WINAPI COORD (*pGetConsoleFontSize)(HANDLE hConsole, DWORD index);
static WINAPI HANDLE (*pGetConsoleInputWaitHandle)(void);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameA)(LPSTR layoutName);
static WINAPI BOOL (*pGetConsoleKeyboardLayoutNameW)(LPWSTR layoutName);
static WINAPI DWORD (*pGetConsoleProcessList)(LPDWORD processlist, DWORD processcount);
static WINAPI DWORD (*pGetConsoleTitleA)(LPSTR title, DWORD size);
static WINAPI HWND (*pGetConsoleWindow)(void);
static WINAPI INT (*pGetCurrencyFormatA)(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, CURRENCYFMTA* lpFormat, LPSTR lpCurrencyStr, int cchOut);
static WINAPI INT (*pGetCurrencyFormatEx)(LPCWSTR localename, DWORD flags, LPCWSTR value, CURRENCYFMTW* format, LPWSTR str, int len);
static WINAPI INT (*pGetCurrencyFormatW)(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, CURRENCYFMTW* lpFormat, LPWSTR lpCurrencyStr, int cchOut);
static WINAPI BOOL (*pGetCurrentConsoleFont)(HANDLE hConsole, BOOL maxwindow, LPCONSOLE_FONT_INFO fontinfo);
static WINAPI UINT (*pGetCurrentDirectoryA)(UINT buflen, LPSTR buf);
static WINAPI UINT (*pGetCurrentDirectoryW)(UINT buflen, LPWSTR buf);
static WINAPI LONG (*pGetCurrentPackageFamilyName)(UINT32* length, PWSTR name);
static WINAPI LONG (*pGetCurrentPackageFullName)(UINT32* length, PWSTR name);
static WINAPI LONG (*pGetCurrentPackageId)(UINT32* len, BYTE* buffer);
static WINAPI PUMS_CONTEXT (*pGetCurrentUmsThread)(void);
static WINAPI INT (*pGetDateFormatA)(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpDateStr, INT cchOut);
static WINAPI INT (*pGetDateFormatEx)(LPCWSTR localename, DWORD flags, SYSTEMTIME* date, LPCWSTR format, LPWSTR outbuf, INT bufsize, LPCWSTR calendar);
static WINAPI INT (*pGetDateFormatW)(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCWSTR lpFormat, LPWSTR lpDateStr, INT cchOut);
static WINAPI BOOL (*pGetDaylightFlag)(void);
static WINAPI BOOL (*pGetDefaultCommConfigA)(LPCSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize);
static WINAPI BOOL (*pGetDefaultCommConfigW)(LPCWSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize);
static WINAPI BOOL (*pGetDevicePowerState)(HANDLE hDevice, BOOL* pfOn);
static WINAPI BOOL (*pGetDiskFreeSpaceA)(LPCSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters);
static WINAPI BOOL (*pGetDiskFreeSpaceExA)(LPCSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceExW)(LPCWSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree);
static WINAPI BOOL (*pGetDiskFreeSpaceW)(LPCWSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters);
static WINAPI DWORD (*pGetDllDirectoryA)(DWORD buf_len, LPSTR buffer);
static WINAPI DWORD (*pGetDllDirectoryW)(DWORD buf_len, LPWSTR buffer);
static WINAPI UINT (*pGetDriveTypeA)(LPCSTR root);
static WINAPI UINT (*pGetDriveTypeW)(LPCWSTR root);
static WINAPI DWORD (*pGetDynamicTimeZoneInformation)(DYNAMIC_TIME_ZONE_INFORMATION* tzinfo);
static WINAPI DWORD (*pGetDynamicTimeZoneInformationEffectiveYears)(DYNAMIC_TIME_ZONE_INFORMATION* tzinfo, DWORD* first_year, DWORD* last_year);
static WINAPI DWORD64 (*pGetEnabledXStateFeatures)(void);
static WINAPI BOOL (*pGetExitCodeProcess)(HANDLE hProcess, LPDWORD lpExitCode);
static WINAPI INT (*pGetExpandedNameA)(LPSTR in, LPSTR out);
static WINAPI INT (*pGetExpandedNameW)(LPWSTR in, LPWSTR out);
static WINAPI BOOL (*pGetFileMUIInfo)(DWORD flags, PCWSTR path, FILEMUIINFO* info, DWORD* size);
static WINAPI BOOL (*pGetFileMUIPath)(DWORD flags, PCWSTR filepath, PWSTR language, PULONG languagelen, PWSTR muipath, PULONG muipathlen, PULONGLONG enumerator);
static WINAPI DWORD (*pGetFinalPathNameByHandleA)(HANDLE file, LPSTR path, DWORD charcount, DWORD flags);
static WINAPI DWORD (*pGetFinalPathNameByHandleW)(HANDLE file, LPWSTR path, DWORD charcount, DWORD flags);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableA)(LPCSTR name, LPCSTR guid, PVOID buffer, DWORD size);
static WINAPI DWORD (*pGetFirmwareEnvironmentVariableW)(LPCWSTR name, LPCWSTR guid, PVOID buffer, DWORD size);
static WINAPI DWORD (*pGetFullPathNameA)(LPCSTR name, DWORD len, LPSTR buffer, LPSTR* lastpart);
static WINAPI DWORD (*pGetFullPathNameW)(LPCWSTR name, DWORD len, LPWSTR buffer, LPWSTR* lastpart);
static WINAPI INT (*pGetGeoInfoA)(GEOID geoid, GEOTYPE geotype, LPSTR data, int data_len, LANGID lang);
static WINAPI INT (*pGetGeoInfoW)(GEOID geoid, GEOTYPE geotype, LPWSTR data, int data_len, LANGID lang);
static WINAPI DWORD (*pGetHandleContext)(HANDLE hnd);
static WINAPI BOOL (*pGetHandleInformation)(HANDLE handle, LPDWORD flags);
static WINAPI SIZE_T (*pGetLargePageMinimum)(void);
static WINAPI void (*pGetLocalTime)(LPSYSTEMTIME systime);
static WINAPI INT (*pGetLocaleInfoA)(LCID lcid, LCTYPE lctype, LPSTR buffer, INT len);
static WINAPI INT (*pGetLocaleInfoEx)(LPCWSTR locale, LCTYPE info, LPWSTR buffer, INT len);
static WINAPI INT (*pGetLocaleInfoW)(LCID lcid, LCTYPE lctype, LPWSTR buffer, INT len);
static WINAPI UINT (*pGetLogicalDriveStringsA)(UINT len, LPSTR buffer);
static WINAPI UINT (*pGetLogicalDriveStringsW)(UINT len, LPWSTR buffer);
static WINAPI DWORD (*pGetLogicalDrives)(void);
static WINAPI BOOL (*pGetLogicalProcessorInformation)(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer, PDWORD pBufLen);
static WINAPI BOOL (*pGetLogicalProcessorInformationEx)(LOGICAL_PROCESSOR_RELATIONSHIP relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX* buffer, DWORD* len);
static WINAPI DWORD (*pGetLongPathNameA)(LPCSTR shortpath, LPSTR longpath, DWORD longlen);
static WINAPI DWORD (*pGetLongPathNameW)(LPCWSTR shortpath, LPWSTR longpath, DWORD longlen);
static WINAPI BOOL (*pGetMailslotInfo)(HANDLE hMailslot, LPDWORD lpMaxMessageSize, LPDWORD lpNextSize, LPDWORD lpMessageCount, LPDWORD lpReadTimeout);
static WINAPI DWORD (*pGetMaximumProcessorCount)(WORD group);
static WINAPI BOOL (*pGetNamedPipeClientProcessId)(HANDLE pipe, ULONG* id);
static WINAPI BOOL (*pGetNamedPipeClientSessionId)(HANDLE pipe, ULONG* id);
static WINAPI BOOL (*pGetNamedPipeHandleStateA)(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPSTR lpUsername, DWORD nUsernameMaxSize);
static WINAPI BOOL (*pGetNamedPipeHandleStateW)(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPWSTR lpUsername, DWORD nUsernameMaxSize);
static WINAPI BOOL (*pGetNamedPipeServerProcessId)(HANDLE pipe, ULONG* id);
static WINAPI BOOL (*pGetNamedPipeServerSessionId)(HANDLE pipe, ULONG* id);
static WINAPI void (*pGetNativeSystemInfo)(LPSYSTEM_INFO si);
static WINAPI PUMS_CONTEXT (*pGetNextUmsListItem)(PUMS_CONTEXT ctx);
static WINAPI BOOL (*pGetNumaAvailableMemoryNode)(UCHAR node, PULONGLONG available_bytes);
static WINAPI BOOL (*pGetNumaAvailableMemoryNodeEx)(USHORT node, PULONGLONG available_bytes);
static WINAPI BOOL (*pGetNumaHighestNodeNumber)(PULONG highestnode);
static WINAPI BOOL (*pGetNumaNodeProcessorMask)(UCHAR node, PULONGLONG mask);
static WINAPI BOOL (*pGetNumaNodeProcessorMaskEx)(USHORT node, PGROUP_AFFINITY mask);
static WINAPI BOOL (*pGetNumaProcessorNode)(UCHAR processor, PUCHAR node);
static WINAPI BOOL (*pGetNumaProcessorNodeEx)(PPROCESSOR_NUMBER processor, PUSHORT node_number);
static WINAPI BOOL (*pGetNumaProximityNode)(ULONG proximity_id, PUCHAR node_number);
static WINAPI BOOL (*pGetNumaProximityNodeEx)(ULONG proximity_id, PUSHORT node_number);
static WINAPI INT (*pGetNumberFormatA)(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, NUMBERFMTA* lpFormat, LPSTR lpNumberStr, int cchOut);
static WINAPI INT (*pGetNumberFormatEx)(LPCWSTR name, DWORD flags, LPCWSTR value, NUMBERFMTW* format, LPWSTR number, int numout);
static WINAPI INT (*pGetNumberFormatW)(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, NUMBERFMTW* lpFormat, LPWSTR lpNumberStr, int cchOut);
static WINAPI DWORD (*pGetNumberOfConsoleFonts)(void);
static WINAPI BOOL (*pGetNumberOfConsoleMouseButtons)(LPDWORD nrofbuttons);
static WINAPI UINT (*pGetOEMCP)(void);
static WINAPI LONG (*pGetPackageFullName)(HANDLE process, UINT32* length, PWSTR name);
static WINAPI BOOL (*pGetPhysicallyInstalledSystemMemory)(ULONGLONG* total_memory);
static WINAPI UINT (*pGetPrivateProfileIntA)(LPCSTR section, LPCSTR entry, INT def_val, LPCSTR filename);
static WINAPI UINT (*pGetPrivateProfileIntW)(LPCWSTR section, LPCWSTR entry, INT def_val, LPCWSTR filename);
static WINAPI INT (*pGetPrivateProfileSectionA)(LPCSTR section, LPSTR buffer, DWORD len, LPCSTR filename);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesA)(LPSTR buffer, DWORD size, LPCSTR filename);
static WINAPI DWORD (*pGetPrivateProfileSectionNamesW)(LPWSTR buffer, DWORD size, LPCWSTR filename);
static WINAPI INT (*pGetPrivateProfileSectionW)(LPCWSTR section, LPWSTR buffer, DWORD len, LPCWSTR filename);
static WINAPI INT (*pGetPrivateProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len, LPCSTR filename);
static WINAPI INT (*pGetPrivateProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len, LPCWSTR filename);
static WINAPI BOOL (*pGetPrivateProfileStructA)(LPCSTR section, LPCSTR key, LPVOID buffer, UINT len, LPCSTR filename);
static WINAPI BOOL (*pGetPrivateProfileStructW)(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT len, LPCWSTR filename);
static WINAPI FARPROC (*pGetProcAddress)(HMODULE hModule, LPCSTR function);
static WINAPI BOOL (*pGetProcessAffinityMask)(HANDLE hProcess, PDWORD_PTR process_mask, PDWORD_PTR system_mask);
static WINAPI BOOL (*pGetProcessDEPPolicy)(HANDLE process, LPDWORD flags, PBOOL permanent);
static WINAPI DWORD (*pGetProcessFlags)(DWORD processid);
static WINAPI BOOL (*pGetProcessIoCounters)(HANDLE hProcess, PIO_COUNTERS ioc);
static WINAPI BOOL (*pGetProcessPreferredUILanguages)(DWORD flags, ULONG* count, WCHAR* buf, ULONG* size);
static WINAPI BOOL (*pGetProcessTimes)(HANDLE hprocess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
static WINAPI DWORD (*pGetProcessVersion)(DWORD pid);
static WINAPI BOOL (*pGetProcessWorkingSetSize)(HANDLE process, SIZE_T* minset, SIZE_T* maxset);
static WINAPI BOOL (*pGetProductInfo)(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType);
static WINAPI UINT (*pGetProfileIntA)(LPCSTR section, LPCSTR entry, INT def_val);
static WINAPI UINT (*pGetProfileIntW)(LPCWSTR section, LPCWSTR entry, INT def_val);
static WINAPI INT (*pGetProfileSectionA)(LPCSTR section, LPSTR buffer, DWORD len);
static WINAPI INT (*pGetProfileSectionW)(LPCWSTR section, LPWSTR buffer, DWORD len);
static WINAPI INT (*pGetProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len);
static WINAPI INT (*pGetProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len);
static WINAPI DWORD (*pGetShortPathNameA)(LPCSTR longpath, LPSTR shortpath, DWORD shortlen);
static WINAPI DWORD (*pGetShortPathNameW)(LPCWSTR longpath, LPWSTR shortpath, DWORD shortlen);
static WINAPI void (*pGetStartupInfoA)(LPSTARTUPINFOA info);
static WINAPI BOOL (*pGetStringTypeA)(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeExA)(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeExW)(LCID locale, DWORD type, LPCWSTR src, INT count, LPWORD chartype);
static WINAPI BOOL (*pGetStringTypeW)(DWORD type, LPCWSTR src, INT count, LPWORD chartype);
static WINAPI DEP_SYSTEM_POLICY_TYPE (*pGetSystemDEPPolicy)(void);
static WINAPI LCID (*pGetSystemDefaultLCID)(void);
static WINAPI LANGID (*pGetSystemDefaultLangID)(void);
static WINAPI INT (*pGetSystemDefaultLocaleName)(LPWSTR localename, INT len);
static WINAPI LANGID (*pGetSystemDefaultUILanguage)(void);
static WINAPI UINT (*pGetSystemDirectoryA)(LPSTR path, UINT count);
static WINAPI UINT (*pGetSystemDirectoryW)(LPWSTR path, UINT count);
static WINAPI BOOL (*pGetSystemFileCacheSize)(PSIZE_T mincache, PSIZE_T maxcache, PDWORD flags);
static WINAPI UINT (*pGetSystemFirmwareTable)(DWORD provider, DWORD id, void* buffer, DWORD size);
static WINAPI void (*pGetSystemInfo)(LPSYSTEM_INFO si);
static WINAPI BOOL (*pGetSystemPowerStatus)(LPSYSTEM_POWER_STATUS ps);
static WINAPI BOOL (*pGetSystemPreferredUILanguages)(DWORD flags, ULONG* count, WCHAR* buffer, ULONG* size);
static WINAPI BOOL (*pGetSystemRegistryQuota)(PDWORD pdwQuotaAllowed, PDWORD pdwQuotaUsed);
static WINAPI void (*pGetSystemTime)(LPSYSTEMTIME systime);
static WINAPI BOOL (*pGetSystemTimeAdjustment)(PDWORD lpTimeAdjustment, PDWORD lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled);
static WINAPI void (*pGetSystemTimePreciseAsFileTime)(FILETIME* time);
static WINAPI BOOL (*pGetSystemTimes)(LPFILETIME lpIdleTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime);
static WINAPI UINT (*pGetSystemWow64DirectoryA)(LPSTR path, UINT count);
static WINAPI UINT (*pGetSystemWow64DirectoryW)(LPWSTR path, UINT count);
static WINAPI DWORD (*pGetTapeParameters)(HANDLE device, DWORD operation, LPDWORD size, LPVOID info);
static WINAPI DWORD (*pGetTapePosition)(HANDLE device, DWORD type, LPDWORD partition, LPDWORD offset_low, LPDWORD offset_high);
static WINAPI DWORD (*pGetTapeStatus)(HANDLE device);
static WINAPI UINT (*pGetTempFileNameA)(LPCSTR path, LPCSTR prefix, UINT unique, LPSTR buffer);
static WINAPI UINT (*pGetTempFileNameW)(LPCWSTR path, LPCWSTR prefix, UINT unique, LPWSTR buffer);
static WINAPI DWORD (*pGetTempPathA)(DWORD count, LPSTR path);
static WINAPI DWORD (*pGetTempPathW)(DWORD count, LPWSTR path);
static WINAPI LCID (*pGetThreadLocale)(void);
static WINAPI BOOL (*pGetThreadPreferredUILanguages)(DWORD flags, ULONG* count, WCHAR* buf, ULONG* size);
static WINAPI BOOL (*pGetThreadSelectorEntry)(HANDLE hthread, DWORD sel, LPLDT_ENTRY ldtent);
static WINAPI DWORD (*pGetTickCount)(void);
static WINAPI ULONGLONG (*pGetTickCount64)(void);
static WINAPI INT (*pGetTimeFormatA)(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, INT cchOut);
static WINAPI INT (*pGetTimeFormatEx)(LPCWSTR localename, DWORD flags, SYSTEMTIME* time, LPCWSTR format, LPWSTR outbuf, INT bufsize);
static WINAPI INT (*pGetTimeFormatW)(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, INT cchOut);
static WINAPI DWORD (*pGetTimeZoneInformation)(LPTIME_ZONE_INFORMATION ret);
static WINAPI BOOL (*pGetTimeZoneInformationForYear)(USHORT wYear, PDYNAMIC_TIME_ZONE_INFORMATION pdtzi, LPTIME_ZONE_INFORMATION ptzi);
static WINAPI BOOL (*pGetUmsCompletionListEvent)(PUMS_COMPLETION_LIST list, HANDLE* event);
static WINAPI LCID (*pGetUserDefaultLCID)(void);
static WINAPI LANGID (*pGetUserDefaultLangID)(void);
static WINAPI INT (*pGetUserDefaultLocaleName)(LPWSTR localename, int buffersize);
static WINAPI LANGID (*pGetUserDefaultUILanguage)(void);
static WINAPI GEOID (*pGetUserGeoID)(GEOCLASS GeoClass);
static WINAPI BOOL (*pGetUserPreferredUILanguages)(DWORD flags, ULONG* count, WCHAR* buffer, ULONG* size);
static WINAPI BOOL (*pGetVolumeInformationA)(LPCSTR root, LPSTR label, DWORD label_len, DWORD* serial, DWORD* filename_len, DWORD* flags, LPSTR fsname, DWORD fsname_len);
static WINAPI BOOL (*pGetVolumeInformationByHandleW)(HANDLE handle, WCHAR* volnamebuf, DWORD volnamesize, DWORD* volserial, DWORD* maxlength, DWORD* flags, WCHAR* fsnamebuf, DWORD fsnamesize);
static WINAPI BOOL (*pGetVolumeInformationW)(LPCWSTR root, LPWSTR label, DWORD label_len, DWORD* serial, DWORD* filename_len, DWORD* flags, LPWSTR fsname, DWORD fsname_len);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointA)(LPCSTR path, LPSTR volume, DWORD size);
static WINAPI BOOL (*pGetVolumeNameForVolumeMountPointW)(LPCWSTR path, LPWSTR volume, DWORD size);
static WINAPI BOOL (*pGetVolumePathNameA)(LPCSTR filename, LPSTR volumepathname, DWORD buflen);
static WINAPI BOOL (*pGetVolumePathNameW)(LPCWSTR filename, LPWSTR volumepathname, DWORD buflen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameA)(LPCSTR volumename, LPSTR volumepathname, DWORD buflen, PDWORD returnlen);
static WINAPI BOOL (*pGetVolumePathNamesForVolumeNameW)(LPCWSTR volumename, LPWSTR volumepathname, DWORD buflen, PDWORD returnlen);
static WINAPI ATOM (*pGlobalAddAtomA)(LPCSTR str);
static WINAPI ATOM (*pGlobalAddAtomW)(LPCWSTR str);
static WINAPI SIZE_T (*pGlobalCompact)(DWORD minfree);
static WINAPI ATOM (*pGlobalDeleteAtom)(ATOM atom);
static WINAPI ATOM (*pGlobalFindAtomA)(LPCSTR str);
static WINAPI ATOM (*pGlobalFindAtomW)(LPCWSTR str);
static WINAPI void (*pGlobalFix)(HGLOBAL hmem);
static WINAPI UINT (*pGlobalFlags)(HGLOBAL hmem);
static WINAPI UINT (*pGlobalGetAtomNameA)(ATOM atom, LPSTR buffer, INT count);
static WINAPI UINT (*pGlobalGetAtomNameW)(ATOM atom, LPWSTR buffer, INT count);
static WINAPI HGLOBAL (*pGlobalHandle)(LPCVOID pmem);
static WINAPI LPVOID (*pGlobalLock)(HGLOBAL hmem);
static WINAPI void (*pGlobalMemoryStatus)(LPMEMORYSTATUS lpBuffer);
static WINAPI BOOL (*pGlobalMemoryStatusEx)(LPMEMORYSTATUSEX lpmemex);
static WINAPI HGLOBAL (*pGlobalReAlloc)(HGLOBAL hmem, SIZE_T size, UINT flags);
static WINAPI SIZE_T (*pGlobalSize)(HGLOBAL hmem);
static WINAPI BOOL (*pGlobalUnWire)(HGLOBAL hmem);
static WINAPI void (*pGlobalUnfix)(HGLOBAL hmem);
static WINAPI BOOL (*pGlobalUnlock)(HGLOBAL hmem);
static WINAPI LPVOID (*pGlobalWire)(HGLOBAL hmem);
static WINAPI BOOL (*pHeap32ListFirst)(HANDLE hSnapshot, LPHEAPLIST32 lphl);
static WINAPI HANDLE (*pHeapCreate)(DWORD flags, SIZE_T initialSize, SIZE_T maxSize);
static WINAPI BOOL (*pHeapDestroy)(HANDLE heap);
static WINAPI BOOL (*pHeapFree)(HANDLE heap, DWORD flags, LPVOID ptr);
static WINAPI INT (*pIdnToAscii)(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpASCIICharStr, INT cchASCIIChar);
static WINAPI INT (*pIdnToNameprepUnicode)(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpNameprepCharStr, INT cchNameprepChar);
static WINAPI INT (*pIdnToUnicode)(DWORD dwFlags, LPCWSTR lpASCIICharStr, INT cchASCIIChar, LPWSTR lpUnicodeCharStr, INT cchUnicodeChar);
static WINAPI BOOL (*pInitAtomTable)(DWORD entries);
static WINAPI BOOL (*pInvalidateNLSCache)(void);
static WINAPI BOOL (*pIsBadCodePtr)(FARPROC ptr);
static WINAPI BOOL (*pIsBadHugeReadPtr)(LPCVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadHugeWritePtr)(LPVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadReadPtr)(LPCVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsBadStringPtrA)(LPCSTR str, UINT_PTR max);
static WINAPI BOOL (*pIsBadStringPtrW)(LPCWSTR str, UINT_PTR max);
static WINAPI BOOL (*pIsBadWritePtr)(LPVOID ptr, UINT_PTR size);
static WINAPI BOOL (*pIsDBCSLeadByte)(BYTE testchar);
static WINAPI BOOL (*pIsDBCSLeadByteEx)(UINT codepage, BYTE testchar);
static WINAPI BOOL (*pIsNormalizedString)(NORM_FORM NormForm, LPCWSTR lpString, INT cwLength);
static WINAPI BOOL (*pIsProcessInJob)(HANDLE process, HANDLE job, PBOOL result);
static WINAPI BOOL (*pIsProcessorFeaturePresent)(DWORD feature);
static WINAPI BOOL (*pIsSystemResumeAutomatic)(void);
static WINAPI BOOL (*pIsValidCodePage)(UINT codepage);
static WINAPI BOOL (*pIsValidLanguageGroup)(LGRPID lgrpid, DWORD dwFlags);
static WINAPI BOOL (*pIsValidLocale)(LCID lcid, DWORD flags);
static WINAPI BOOL (*pIsValidLocaleName)(LPCWSTR locale);
static WINAPI BOOL (*pK32EmptyWorkingSet)(HANDLE hProcess);
static WINAPI BOOL (*pK32EnumDeviceDrivers)(void** image_base, DWORD cb, DWORD* needed);
static WINAPI BOOL (*pK32EnumPageFilesA)(PENUM_PAGE_FILE_CALLBACKA callback, LPVOID context);
static WINAPI BOOL (*pK32EnumPageFilesW)(PENUM_PAGE_FILE_CALLBACKW callback, LPVOID context);
static WINAPI BOOL (*pK32EnumProcessModules)(HANDLE process, HMODULE* lphModule, DWORD cb, DWORD* needed);
static WINAPI BOOL (*pK32EnumProcessModulesEx)(HANDLE process, HMODULE* lphModule, DWORD cb, DWORD* needed, DWORD filter);
static WINAPI BOOL (*pK32EnumProcesses)(DWORD* lpdwProcessIDs, DWORD cb, DWORD* lpcbUsed);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameA)(void* image_base, LPSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverBaseNameW)(void* image_base, LPWSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameA)(void* image_base, LPSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetDeviceDriverFileNameW)(void* image_base, LPWSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetMappedFileNameA)(HANDLE process, LPVOID lpv, LPSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetMappedFileNameW)(HANDLE process, LPVOID lpv, LPWSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleBaseNameA)(HANDLE process, HMODULE module, LPSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleBaseNameW)(HANDLE process, HMODULE module, LPWSTR base_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleFileNameExA)(HANDLE process, HMODULE module, LPSTR file_name, DWORD size);
static WINAPI DWORD (*pK32GetModuleFileNameExW)(HANDLE process, HMODULE module, LPWSTR file_name, DWORD size);
static WINAPI BOOL (*pK32GetModuleInformation)(HANDLE process, HMODULE module, MODULEINFO* modinfo, DWORD cb);
static WINAPI BOOL (*pK32GetPerformanceInfo)(PPERFORMANCE_INFORMATION info, DWORD size);
static WINAPI DWORD (*pK32GetProcessImageFileNameA)(HANDLE process, LPSTR file, DWORD size);
static WINAPI DWORD (*pK32GetProcessImageFileNameW)(HANDLE process, LPWSTR file, DWORD size);
static WINAPI BOOL (*pK32GetProcessMemoryInfo)(HANDLE process, PPROCESS_MEMORY_COUNTERS pmc, DWORD cb);
static WINAPI BOOL (*pK32GetWsChanges)(HANDLE process, PPSAPI_WS_WATCH_INFORMATION watchinfo, DWORD size);
static WINAPI BOOL (*pK32GetWsChangesEx)(HANDLE process, PSAPI_WS_WATCH_INFORMATION_EX* watchinfoex, DWORD* size);
static WINAPI BOOL (*pK32InitializeProcessForWsWatch)(HANDLE process);
static WINAPI BOOL (*pK32QueryWorkingSet)(HANDLE process, LPVOID buffer, DWORD size);
static WINAPI BOOL (*pK32QueryWorkingSetEx)(HANDLE process, LPVOID buffer, DWORD size);
static WINAPI HANDLE (*pGetCurrentProcess)(void);
static WINAPI DWORD (*pGetCurrentProcessId)(void);
static WINAPI HANDLE (*pGetCurrentThread)(void);
static WINAPI DWORD (*pGetCurrentThreadId)(void);
static WINAPI INT (*pLCIDToLocaleName)(LCID lcid, LPWSTR name, INT count, DWORD flags);
static WINAPI INT (*pLCMapStringA)(LCID lcid, DWORD flags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen);
static WINAPI INT (*pLCMapStringEx)(LPCWSTR name, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lparam);
static WINAPI INT (*pLCMapStringW)(LCID lcid, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI void (*pLZClose)(HFILE fd);
static WINAPI LONG (*pLZCopy)(HFILE src, HFILE dest);
static WINAPI void (*pLZDone)(void);
static WINAPI HFILE (*pLZInit)(HFILE hfSrc);
static WINAPI HFILE (*pLZOpenFileA)(LPSTR fn, LPOFSTRUCT ofs, WORD mode);
static WINAPI HFILE (*pLZOpenFileW)(LPWSTR fn, LPOFSTRUCT ofs, WORD mode);
static WINAPI INT (*pLZRead)(HFILE fd, LPSTR vbuf, INT toread);
static WINAPI LONG (*pLZSeek)(HFILE fd, LONG off, INT type);
static WINAPI INT (*pLZStart)(void);
static WINAPI HMODULE (*pLoadLibraryA)(LPCSTR libname);
static WINAPI HMODULE (*pLoadLibraryExA)(LPCSTR libname, HANDLE hfile, DWORD flags);
static WINAPI HMODULE (*pLoadLibraryExW)(LPCWSTR libnameW, HANDLE hfile, DWORD flags);
static WINAPI HMODULE (*pLoadLibraryW)(LPCWSTR libnameW);
static WINAPI DWORD (*pLoadModule)(LPCSTR name, LPVOID paramBlock);
static WINAPI SIZE_T (*pLocalCompact)(UINT minfree);
static WINAPI BOOL (*pLocalFileTimeToFileTime)(FILETIME* localft, LPFILETIME utcft);
static WINAPI UINT (*pLocalFlags)(HLOCAL handle);
static WINAPI HLOCAL (*pLocalHandle)(LPCVOID ptr);
static WINAPI SIZE_T (*pLocalShrink)(HGLOBAL handle, UINT newsize);
static WINAPI SIZE_T (*pLocalSize)(HLOCAL handle);
static WINAPI LCID (*pLocaleNameToLCID)(LPCWSTR name, DWORD flags);
static WINAPI void (*pMakeCriticalSectionGlobal)(CRITICAL_SECTION* crit);
static WINAPI BOOL (*pMapUserPhysicalPages)(PVOID addr, ULONG_PTR page_count, PULONG_PTR pages);
static WINAPI BOOL (*pModule32First)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
static WINAPI BOOL (*pModule32FirstW)(HANDLE hSnapshot, LPMODULEENTRY32W lpme);
static WINAPI BOOL (*pModule32Next)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
static WINAPI BOOL (*pModule32NextW)(HANDLE hSnapshot, LPMODULEENTRY32W lpme);
static WINAPI BOOL (*pMoveFileA)(LPCSTR source, LPCSTR dest);
static WINAPI BOOL (*pMoveFileExA)(LPCSTR source, LPCSTR dest, DWORD flag);
static WINAPI BOOL (*pMoveFileExW)(LPCWSTR source, LPCWSTR dest, DWORD flag);
static WINAPI BOOL (*pMoveFileTransactedA)(char* source, char* dest, LPPROGRESS_ROUTINE progress, void* data, DWORD flags, HANDLE handle);
static WINAPI BOOL (*pMoveFileTransactedW)(WCHAR* source, WCHAR* dest, LPPROGRESS_ROUTINE progress, void* data, DWORD flags, HANDLE handle);
static WINAPI BOOL (*pMoveFileW)(LPCWSTR source, LPCWSTR dest);
static WINAPI BOOL (*pMoveFileWithProgressA)(LPCSTR source, LPCSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag);
static WINAPI BOOL (*pMoveFileWithProgressW)(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag);
static WINAPI INT (*pMulDiv)(INT nMultiplicand, INT nMultiplier, INT nDivisor);
static WINAPI INT (*pMultiByteToWideChar)(UINT page, DWORD flags, LPCSTR src, INT srclen, LPWSTR dst, INT dstlen);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathA)(LPCSTR name);
static WINAPI BOOL (*pNeedCurrentDirectoryForExePathW)(LPCWSTR name);
static WINAPI INT (*pNormalizeString)(NORM_FORM form, WCHAR* src, INT src_len, WCHAR* dst, INT dst_len);
static WINAPI HANDLE (*pOpenConsoleW)(LPCWSTR name, DWORD access, BOOL inherit, DWORD creation);
static WINAPI HFILE (*pOpenFile)(LPCSTR name, OFSTRUCT* ofs, UINT mode);
static WINAPI HANDLE (*pOpenFileMappingA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pOpenJobObjectA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pOpenJobObjectW)(DWORD access, BOOL inherit, LPCWSTR name);
static WINAPI HANDLE (*pOpenMutexA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI BOOL (*pOpenProfileUserMapping)(void);
static WINAPI HANDLE (*pOpenSemaphoreA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI HANDLE (*pOpenVxDHandle)(HANDLE hHandleRing3);
static WINAPI HANDLE (*pOpenWaitableTimerA)(DWORD access, BOOL inherit, LPCSTR name);
static WINAPI BOOL (*pPowerClearRequest)(HANDLE request, POWER_REQUEST_TYPE type);
static WINAPI HANDLE (*pPowerCreateRequest)(REASON_CONTEXT* context);
static WINAPI BOOL (*pPowerSetRequest)(HANDLE request, POWER_REQUEST_TYPE type);
static WINAPI DWORD (*pPrepareTape)(HANDLE device, DWORD operation, BOOL immediate);
static WINAPI BOOL (*pProcess32First)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
static WINAPI BOOL (*pProcess32FirstW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
static WINAPI BOOL (*pProcess32Next)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
static WINAPI BOOL (*pProcess32NextW)(HANDLE hSnapshot, LPPROCESSENTRY32W lppe);
static WINAPI BOOL (*pProcessIdToSessionId)(DWORD procid, DWORD* sessionid_ptr);
static WINAPI DWORD (*pQueryDosDeviceA)(LPCSTR devname, LPSTR target, DWORD bufsize);
static WINAPI DWORD (*pQueryDosDeviceW)(LPCWSTR devname, LPWSTR target, DWORD bufsize);
static WINAPI BOOL (*pQueryFullProcessImageNameA)(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD pdwSize);
static WINAPI BOOL (*pQueryFullProcessImageNameW)(HANDLE hProcess, DWORD dwFlags, LPWSTR lpExeName, PDWORD pdwSize);
static WINAPI BOOL (*pQueryInformationJobObject)(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len, DWORD* ret_len);
static WINAPI BOOL (*pQueryProcessCycleTime)(HANDLE process, PULONG64 cycle);
static WINAPI BOOL (*pQueryThreadCycleTime)(HANDLE thread, PULONG64 cycle);
static WINAPI BOOL (*pQueryUmsThreadInformation)(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void* buf, ULONG length, ULONG* ret_length);
static WINAPI BOOL (*pQueryUnbiasedInterruptTime)(ULONGLONG* time);
static WINAPI BOOL (*pReadConsoleInputW)(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead);
static WINAPI BOOL (*pReadConsoleW)(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved);
static WINAPI HRESULT (*pRegisterApplicationRecoveryCallback)(APPLICATION_RECOVERY_CALLBACK callback, PVOID param, DWORD pingint, DWORD flags);
static WINAPI HRESULT (*pRegisterApplicationRestart)(PCWSTR pwzCommandLine, DWORD dwFlags);
static WINAPI DWORD (*pRegisterServiceProcess)(DWORD dwProcessId, DWORD dwType);
static WINAPI BOOL (*pRegisterWaitForSingleObject)(PHANDLE phNewWaitObject, HANDLE hObject, WAITORTIMERCALLBACK Callback, PVOID Context, ULONG dwMilliseconds, ULONG dwFlags);
static WINAPI void (*pReinitializeCriticalSection)(CRITICAL_SECTION* crit);
static WINAPI BOOL (*pRemoveDirectoryA)(LPCSTR path);
static WINAPI BOOL (*pRemoveDirectoryW)(LPCWSTR path);
static WINAPI BOOL (*pRemoveDllDirectory)(DLL_DIRECTORY_COOKIE cookie);
static WINAPI BOOL (*pReplaceFileA)(LPCSTR lpReplacedFileName, LPCSTR lpReplacementFileName, LPCSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved);
static WINAPI BOOL (*pReplaceFileW)(LPCWSTR lpReplacedFileName, LPCWSTR lpReplacementFileName, LPCWSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved);
static WINAPI BOOL (*pRequestDeviceWakeup)(HANDLE device);
static WINAPI BOOL (*pRequestWakeupLatency)(LATENCY_TIME latency);
static WINAPI INT (*pResolveLocaleName)(LPCWSTR name, LPWSTR localename, INT len);
static WINAPI DWORD (*pSearchPathA)(LPCSTR path, LPCSTR name, LPCSTR ext, DWORD buflen, LPSTR buffer, LPSTR* lastpart);
static WINAPI DWORD (*pSearchPathW)(LPCWSTR path, LPCWSTR name, LPCWSTR ext, DWORD buflen, LPWSTR buffer, LPWSTR* lastpart);
static WINAPI UINT (*pSetCPGlobal)(UINT acp);
static WINAPI INT (*pSetCalendarInfoA)(LCID Locale, CALID Calendar, CALTYPE CalType, LPCSTR lpCalData);
static WINAPI INT (*pSetCalendarInfoW)(LCID Locale, CALID Calendar, CALTYPE CalType, LPCWSTR lpCalData);
static WINAPI BOOL (*pSetComputerNameA)(LPCSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameExA)(COMPUTER_NAME_FORMAT type, LPCSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameExW)(COMPUTER_NAME_FORMAT type, LPCWSTR lpComputerName);
static WINAPI BOOL (*pSetComputerNameW)(LPCWSTR lpComputerName);
static WINAPI BOOL (*pSetConsoleCtrlHandler)(PHANDLER_ROUTINE func, BOOL add);
static WINAPI BOOL (*pSetConsoleDisplayMode)(HANDLE hConsoleOutput, DWORD dwFlags, COORD* lpNewScreenBufferDimensions);
static WINAPI BOOL (*pSetConsoleFont)(HANDLE hConsole, DWORD index);
static WINAPI BOOL (*pSetConsoleIcon)(HICON icon);
static WINAPI BOOL (*pSetConsoleKeyShortcuts)(BOOL set, BYTE keys, void* a, DWORD b);
static WINAPI BOOL (*pSetConsoleTitleA)(LPCSTR title);
static WINAPI BOOL (*pSetCurrentConsoleFontEx)(HANDLE hConsole, BOOL maxwindow, CONSOLE_FONT_INFOEX* cfix);
static WINAPI BOOL (*pSetCurrentDirectoryA)(LPCSTR dir);
static WINAPI BOOL (*pSetCurrentDirectoryW)(LPCWSTR dir);
static WINAPI BOOL (*pSetDefaultCommConfigA)(LPCSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize);
static WINAPI BOOL (*pSetDefaultCommConfigW)(LPCWSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize);
static WINAPI BOOL (*pSetDefaultDllDirectories)(DWORD flags);
static WINAPI BOOL (*pSetDllDirectoryA)(LPCSTR dir);
static WINAPI BOOL (*pSetDllDirectoryW)(LPCWSTR dir);
static WINAPI BOOL (*pSetFileCompletionNotificationModes)(HANDLE file, UCHAR flags);
static WINAPI BOOL (*pSetHandleContext)(HANDLE hnd, DWORD context);
static WINAPI UINT (*pSetHandleCount)(UINT count);
static WINAPI BOOL (*pSetHandleInformation)(HANDLE handle, DWORD mask, DWORD flags);
static WINAPI BOOL (*pSetInformationJobObject)(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len);
static WINAPI BOOL (*pSetLocalTime)(SYSTEMTIME* systime);
static WINAPI BOOL (*pSetLocaleInfoA)(LCID lcid, LCTYPE lctype, LPCSTR data);
static WINAPI BOOL (*pSetLocaleInfoW)(LCID lcid, LCTYPE lctype, LPCWSTR data);
static WINAPI BOOL (*pSetMailslotInfo)(HANDLE hMailslot, DWORD dwReadTimeout);
static WINAPI BOOL (*pSetProcessAffinityMask)(HANDLE hProcess, DWORD_PTR affmask);
static WINAPI BOOL (*pSetProcessDEPPolicy)(DWORD newDEP);
static WINAPI BOOL (*pSetProcessPreferredUILanguages)(DWORD flags, PCZZWSTR buffer, PULONG count);
static WINAPI BOOL (*pSetProcessWorkingSetSize)(HANDLE process, SIZE_T minset, SIZE_T maxset);
static WINAPI BOOL (*pSetSearchPathMode)(DWORD flags);
static WINAPI BOOL (*pSetSystemFileCacheSize)(SIZE_T mincache, SIZE_T maxcache, DWORD flags);
static WINAPI BOOL (*pSetSystemPowerState)(BOOL suspend_or_hibernate, BOOL force_flag);
static WINAPI BOOL (*pSetSystemTime)(SYSTEMTIME* systime);
static WINAPI BOOL (*pSetSystemTimeAdjustment)(DWORD dwTimeAdjustment, BOOL bTimeAdjustmentDisabled);
static WINAPI DWORD (*pSetTapeParameters)(HANDLE device, DWORD operation, LPVOID info);
static WINAPI DWORD (*pSetTapePosition)(HANDLE device, DWORD method, DWORD partition, DWORD offset_low, DWORD offset_high, BOOL immediate);
static WINAPI DWORD (*pSetTermsrvAppInstallMode)(BOOL bInstallMode);
static WINAPI DWORD_PTR (*pSetThreadAffinityMask)(HANDLE hThread, DWORD_PTR dwThreadAffinityMask);
static WINAPI DWORD (*pSetThreadExecutionState)(EXECUTION_STATE flags);
static WINAPI BOOL (*pSetThreadLocale)(LCID lcid);
static WINAPI BOOL (*pSetThreadPreferredUILanguages)(DWORD flags, PCZZWSTR buffer, PULONG count);
static WINAPI LANGID (*pSetThreadUILanguage)(LANGID langid);
static WINAPI BOOL (*pSetTimeZoneInformation)(TIME_ZONE_INFORMATION* tzinfo);
static WINAPI BOOL (*pSetUmsThreadInformation)(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void* buf, ULONG length);
static WINAPI BOOL (*pSetUserGeoID)(GEOID GeoID);
static WINAPI BOOL (*pSetVolumeLabelA)(LPCSTR root, LPCSTR volname);
static WINAPI BOOL (*pSetVolumeLabelW)(LPCWSTR root, LPCWSTR label);
static WINAPI BOOL (*pSetVolumeMountPointA)(LPCSTR path, LPCSTR volume);
static WINAPI BOOL (*pSetVolumeMountPointW)(LPCWSTR path, LPCWSTR volume);
static WINAPI BOOL (*pSystemTimeToFileTime)(SYSTEMTIME* syst, LPFILETIME ft);
static WINAPI BOOL (*pSystemTimeToTzSpecificLocalTime)(TIME_ZONE_INFORMATION* lpTimeZoneInformation, SYSTEMTIME* lpUniversalTime, LPSYSTEMTIME lpLocalTime);
static WINAPI BOOL (*pTerminateJobObject)(HANDLE job, UINT exit_code);
static WINAPI BOOL (*pTermsrvAppInstallMode)(void);
static WINAPI BOOL (*pThread32First)(HANDLE hSnapShot, LPTHREADENTRY32 lpte);
static WINAPI BOOL (*pThread32Next)(HANDLE hSnapShot, LPTHREADENTRY32 lpte);
static WINAPI BOOL (*pToolhelp32ReadProcessMemory)(DWORD pid, void* base, void* buf, SIZE_T len, SIZE_T* r);
static WINAPI BOOL (*pTzSpecificLocalTimeToSystemTime)(TIME_ZONE_INFORMATION* lpTimeZoneInformation, SYSTEMTIME* lpLocalTime, LPSYSTEMTIME lpUniversalTime);
static WINAPI BOOL (*pUmsThreadYield)(void* param);
static WINAPI void (*pUninitializeCriticalSection)(CRITICAL_SECTION* crit);
static WINAPI HRESULT (*pUnregisterApplicationRestart)(void);
static WINAPI BOOL (*pUnregisterWait)(HANDLE WaitHandle);
static WINAPI BOOL (*pUpdateResourceA)(HANDLE hUpdate, LPCSTR lpType, LPCSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData);
static WINAPI BOOL (*pUpdateResourceW)(HANDLE hUpdate, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData);
static WINAPI DWORD (*pVerLanguageNameA)(DWORD wLang, LPSTR szLang, DWORD nSize);
static WINAPI DWORD (*pVerLanguageNameW)(DWORD wLang, LPWSTR szLang, DWORD nSize);
static WINAPI BOOL (*pVerifyConsoleIoHandle)(HANDLE handle);
static WINAPI BOOL (*pVerifyVersionInfoA)(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
static WINAPI BOOL (*pVerifyVersionInfoW)(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask);
static WINAPI DWORD (*pWTSGetActiveConsoleSessionId)(void);
static WINAPI BOOL (*pWaitNamedPipeA)(LPCSTR name, DWORD nTimeOut);
static WINAPI HRESULT (*pWerRegisterFile)(PCWSTR file, WER_REGISTER_FILE_TYPE regfiletype, DWORD flags);
static WINAPI HRESULT (*pWerRegisterMemoryBlock)(void* block, DWORD size);
static WINAPI HRESULT (*pWerRegisterRuntimeExceptionModule)(PCWSTR callbackdll, PVOID context);
static WINAPI HRESULT (*pWerSetFlags)(DWORD flags);
static WINAPI HRESULT (*pWerUnregisterMemoryBlock)(void* block);
static WINAPI HRESULT (*pWerUnregisterRuntimeExceptionModule)(PCWSTR callbackdll, PVOID context);
static WINAPI INT (*pWideCharToMultiByte)(UINT page, DWORD flags, LPCWSTR src, INT srclen, LPSTR dst, INT dstlen, LPCSTR defchar, BOOL* used);
static WINAPI UINT (*pWinExec)(LPCSTR lpCmdLine, UINT nCmdShow);
static WINAPI BOOLEAN (*pWow64EnableWow64FsRedirection)(BOOLEAN enable);
static WINAPI BOOL (*pWow64GetThreadContext)(HANDLE handle, WOW64_CONTEXT* context);
static WINAPI BOOL (*pWow64SetThreadContext)(HANDLE handle, WOW64_CONTEXT* context);
static WINAPI BOOL (*pWriteConsoleW)(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved);
static WINAPI BOOL (*pWritePrivateProfileSectionA)(LPCSTR section, LPCSTR string, LPCSTR filename);
static WINAPI BOOL (*pWritePrivateProfileSectionW)(LPCWSTR section, LPCWSTR string, LPCWSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR string, LPCSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR string, LPCWSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStructA)(LPCSTR section, LPCSTR key, LPVOID buf, UINT bufsize, LPCSTR filename);
static WINAPI BOOL (*pWritePrivateProfileStructW)(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT bufsize, LPCWSTR filename);
static WINAPI BOOL (*pWriteProfileSectionA)(LPCSTR section, LPCSTR keys_n_values);
static WINAPI BOOL (*pWriteProfileSectionW)(LPCWSTR section, LPCWSTR keys_n_values);
static WINAPI BOOL (*pWriteProfileStringA)(LPCSTR section, LPCSTR entry, LPCSTR string);
static WINAPI BOOL (*pWriteProfileStringW)(LPCWSTR section, LPCWSTR entry, LPCWSTR string);
static WINAPI DWORD (*pWriteTapemark)(HANDLE device, DWORD type, DWORD count, BOOL immediate);
static WINAPI void* (*p__wine_kernel_init)(void);
static WINAPI LONG (*p_hread)(HFILE hFile, LPVOID buffer, LONG count);
static WINAPI LONG (*p_hwrite)(HFILE handle, LPCSTR buffer, LONG count);
static WINAPI HFILE (*p_lclose)(HFILE hFile);
static WINAPI HFILE (*p_lcreat)(LPCSTR path, INT attr);
static WINAPI LONG (*p_llseek)(HFILE hFile, LONG lOffset, INT nOrigin);
static WINAPI HFILE (*p_lopen)(LPCSTR path, INT mode);
static WINAPI UINT (*p_lread)(HFILE handle, LPVOID buffer, UINT count);
static WINAPI UINT (*p_lwrite)(HFILE hFile, LPCSTR buffer, UINT count);
static WINAPI LPSTR (*plstrcatA)(LPSTR dst, LPCSTR src);
static WINAPI LPWSTR (*plstrcatW)(LPWSTR dst, LPCWSTR src);
static WINAPI LPSTR (*plstrcpyA)(LPSTR dst, LPCSTR src);
static WINAPI LPWSTR (*plstrcpyW)(LPWSTR dst, LPCWSTR src);
static void* pAcquireSRWLockExclusive;
static void* pextAcquireSRWLockExclusive;
static void* pAcquireSRWLockShared;
static void* pextAcquireSRWLockShared;
static void* pAddVectoredContinueHandler;
static void* pextAddVectoredContinueHandler;
static void* pAddVectoredExceptionHandler;
static void* pextAddVectoredExceptionHandler;
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
static void* pDecodePointer;
static void* pextDecodePointer;
static void* pDecodeSystemPointer;
static void* pextDecodeSystemPointer;
static void* pDeleteCriticalSection;
static void* pextDeleteCriticalSection;
static void* pDisassociateCurrentThreadFromCallback;
static void* pextDisassociateCurrentThreadFromCallback;
static void* pEncodePointer;
static void* pextEncodePointer;
static void* pEncodeSystemPointer;
static void* pextEncodeSystemPointer;
static void* pEnterCriticalSection;
static void* pextEnterCriticalSection;
static void* pExitThread;
static void* pextExitThread;
static void* pFreeLibraryWhenCallbackReturns;
static void* pextFreeLibraryWhenCallbackReturns;
static void* pGetCurrentProcessorNumber;
static void* pextGetCurrentProcessorNumber;
static void* pGetCurrentProcessorNumberEx;
static void* pextGetCurrentProcessorNumberEx;
static void* pGetSystemTimeAsFileTime;
static void* pextGetSystemTimeAsFileTime;
static void* pHeapAlloc;
static void* pextHeapAlloc;
static void* pHeapReAlloc;
static void* pextHeapReAlloc;
static void* pHeapSize;
static void* pextHeapSize;
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
static void* pIsThreadpoolTimerSet;
static void* pextIsThreadpoolTimerSet;
static void* pLeaveCriticalSection;
static void* pextLeaveCriticalSection;
static void* pLeaveCriticalSectionWhenCallbackReturns;
static void* pextLeaveCriticalSectionWhenCallbackReturns;
static void* pQueryDepthSList;
static void* pextQueryDepthSList;
static void* pReleaseMutexWhenCallbackReturns;
static void* pextReleaseMutexWhenCallbackReturns;
static void* pReleaseSRWLockExclusive;
static void* pextReleaseSRWLockExclusive;
static void* pReleaseSRWLockShared;
static void* pextReleaseSRWLockShared;
static void* pReleaseSemaphoreWhenCallbackReturns;
static void* pextReleaseSemaphoreWhenCallbackReturns;
static void* pRemoveVectoredContinueHandler;
static void* pextRemoveVectoredContinueHandler;
static void* pRemoveVectoredExceptionHandler;
static void* pextRemoveVectoredExceptionHandler;
static void* pResolveDelayLoadedAPI;
static void* pextResolveDelayLoadedAPI;
static void* pRestoreLastError;
static void* pextRestoreLastError;
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
static void* pSetCriticalSectionSpinCount;
static void* pextSetCriticalSectionSpinCount;
static void* pSetEventWhenCallbackReturns;
static void* pextSetEventWhenCallbackReturns;
static void* pSetThreadpoolThreadMaximum;
static void* pextSetThreadpoolThreadMaximum;
static void* pSetThreadpoolThreadMinimum;
static void* pextSetThreadpoolThreadMinimum;
static void* pSetThreadpoolTimer;
static void* pextSetThreadpoolTimer;
static void* pSetThreadpoolWait;
static void* pextSetThreadpoolWait;
static void* pSubmitThreadpoolWork;
static void* pextSubmitThreadpoolWork;
static void* pTryAcquireSRWLockExclusive;
static void* pextTryAcquireSRWLockExclusive;
static void* pTryAcquireSRWLockShared;
static void* pextTryAcquireSRWLockShared;
static void* pTryEnterCriticalSection;
static void* pextTryEnterCriticalSection;
static void* pVerSetConditionMask;
static void* pextVerSetConditionMask;
static void* pWaitForThreadpoolTimerCallbacks;
static void* pextWaitForThreadpoolTimerCallbacks;
static void* pWaitForThreadpoolWaitCallbacks;
static void* pextWaitForThreadpoolWaitCallbacks;
static void* pWaitForThreadpoolWorkCallbacks;
static void* pextWaitForThreadpoolWorkCallbacks;
static void* pWakeAllConditionVariable;
static void* pextWakeAllConditionVariable;
static void* pWakeConditionVariable;
static void* pextWakeConditionVariable;
static WINAPI WCHAR* (*pwine_get_dos_file_name)(LPCSTR str);
static WINAPI char* (*pwine_get_unix_file_name)(LPCWSTR dosW);

WINAPI ATOM wine32b_kernel32_AddAtomA(LPCSTR str) /* ../dlls/kernel32/atom.c:152 */
{
	ATOM return_value;
	TRACE("Enter AddAtomA\n");
	return_value = pAddAtomA(str);
	TRACE("Leave AddAtomA\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_AddAtomW(LPCWSTR str) /* ../dlls/kernel32/atom.c:202 */
{
	ATOM return_value;
	TRACE("Enter AddAtomW\n");
	return_value = pAddAtomW(str);
	TRACE("Leave AddAtomW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_AddConsoleAliasA(LPSTR source, LPSTR target, LPSTR exename) /* ../dlls/kernel32/console.c:1600 */
{
	BOOL return_value;
	TRACE("Enter AddConsoleAliasA\n");
	return_value = pAddConsoleAliasA(source, target, exename);
	TRACE("Leave AddConsoleAliasA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_AddConsoleAliasW(LPWSTR source, LPWSTR target, LPWSTR exename) /* ../dlls/kernel32/console.c:1607 */
{
	BOOL return_value;
	TRACE("Enter AddConsoleAliasW\n");
	return_value = pAddConsoleAliasW(source, target, exename);
	TRACE("Leave AddConsoleAliasW\n");
	return return_value;
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

WINAPI DLL_DIRECTORY_COOKIE wine32b_kernel32_AddDllDirectory(WCHAR* dir) /* ../dlls/kernel32/module.c:172 */
{
	DLL_DIRECTORY_COOKIE return_value;
	TRACE("Enter AddDllDirectory\n");
	return_value = pAddDllDirectory(dir);
	TRACE("Leave AddDllDirectory\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_AllocConsole(void) /* ../dlls/kernel32/console.c:633 */
{
	BOOL return_value;
	TRACE("Enter AllocConsole\n");
	return_value = pAllocConsole();
	TRACE("Leave AllocConsole\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_AllocateUserPhysicalPages(HANDLE process, ULONG_PTR* pages, ULONG_PTR* userarray) /* ../dlls/kernel32/heap.c:929 */
{
	BOOL return_value;
	TRACE("Enter AllocateUserPhysicalPages\n");
	return_value = pAllocateUserPhysicalPages(process, pages, userarray);
	TRACE("Leave AllocateUserPhysicalPages\n");
	return return_value;
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

WINAPI void wine32b_kernel32_ApplicationRecoveryFinished(BOOL success) /* ../dlls/kernel32/process.c:3937 */
{
	TRACE("Enter ApplicationRecoveryFinished\n");
	pApplicationRecoveryFinished(success);
	TRACE("Leave ApplicationRecoveryFinished\n");
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

WINAPI HRESULT wine32b_kernel32_ApplicationRecoveryInProgress(PBOOL canceled) /* ../dlls/kernel32/process.c:3946 */
{
	HRESULT return_value;
	TRACE("Enter ApplicationRecoveryInProgress\n");
	return_value = pApplicationRecoveryInProgress(canceled);
	TRACE("Leave ApplicationRecoveryInProgress\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_AssignProcessToJobObject(HANDLE job, HANDLE process) /* ../dlls/kernel32/sync.c:378 */
{
	BOOL return_value;
	TRACE("Enter AssignProcessToJobObject\n");
	return_value = pAssignProcessToJobObject(job, process);
	TRACE("Leave AssignProcessToJobObject\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BackupRead(HANDLE file, LPBYTE buffer, DWORD to_read, LPDWORD read, BOOL abort, BOOL security, LPVOID* context) /* ../dlls/kernel32/tape.c:51 */
{
	BOOL return_value;
	TRACE("Enter BackupRead\n");
	return_value = pBackupRead(file, buffer, to_read, read, abort, security, context);
	TRACE("Leave BackupRead\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BackupSeek(HANDLE file, DWORD seek_low, DWORD seek_high, LPDWORD seeked_low, LPDWORD seeked_high, LPVOID* context) /* ../dlls/kernel32/tape.c:66 */
{
	BOOL return_value;
	TRACE("Enter BackupSeek\n");
	return_value = pBackupSeek(file, seek_low, seek_high, seeked_low, seeked_high, context);
	TRACE("Leave BackupSeek\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BackupWrite(HANDLE file, LPBYTE buffer, DWORD to_write, LPDWORD written, BOOL abort, BOOL security, LPVOID* context) /* ../dlls/kernel32/tape.c:81 */
{
	BOOL return_value;
	TRACE("Enter BackupWrite\n");
	return_value = pBackupWrite(file, buffer, to_write, written, abort, security, context);
	TRACE("Leave BackupWrite\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BaseFlushAppcompatCache(void) /* ../dlls/kernel32/process.c:4258 */
{
	BOOL return_value;
	TRACE("Enter BaseFlushAppcompatCache\n");
	return_value = pBaseFlushAppcompatCache();
	TRACE("Leave BaseFlushAppcompatCache\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Beep(DWORD dwFreq, DWORD dwDur) /* ../dlls/kernel32/console.c:197 */
{
	BOOL return_value;
	TRACE("Enter Beep\n");
	return_value = pBeep(dwFreq, dwDur);
	TRACE("Leave Beep\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_BeginUpdateResourceA(LPCSTR pFileName, BOOL bDeleteExistingResources) /* ../dlls/kernel32/resource.c:1240 */
{
	HANDLE return_value;
	TRACE("Enter BeginUpdateResourceA\n");
	return_value = pBeginUpdateResourceA(pFileName, bDeleteExistingResources);
	TRACE("Leave BeginUpdateResourceA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_BeginUpdateResourceW(LPCWSTR pFileName, BOOL bDeleteExistingResources) /* ../dlls/kernel32/resource.c:1194 */
{
	HANDLE return_value;
	TRACE("Enter BeginUpdateResourceW\n");
	return_value = pBeginUpdateResourceW(pFileName, bDeleteExistingResources);
	TRACE("Leave BeginUpdateResourceW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BindIoCompletionCallback(HANDLE FileHandle, LPOVERLAPPED_COMPLETION_ROUTINE Function, ULONG Flags) /* ../dlls/kernel32/sync.c:999 */
{
	BOOL return_value;
	TRACE("Enter BindIoCompletionCallback\n");
	return_value = pBindIoCompletionCallback(FileHandle, Function, Flags);
	TRACE("Leave BindIoCompletionCallback\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BuildCommDCBA(LPCSTR device, LPDCB lpdcb) /* ../dlls/kernel32/comm.c:422 */
{
	BOOL return_value;
	TRACE("Enter BuildCommDCBA\n");
	return_value = pBuildCommDCBA(device, lpdcb);
	TRACE("Leave BuildCommDCBA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BuildCommDCBAndTimeoutsA(LPCSTR device, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts) /* ../dlls/kernel32/comm.c:440 */
{
	BOOL return_value;
	TRACE("Enter BuildCommDCBAndTimeoutsA\n");
	return_value = pBuildCommDCBAndTimeoutsA(device, lpdcb, lptimeouts);
	TRACE("Leave BuildCommDCBAndTimeoutsA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BuildCommDCBAndTimeoutsW(LPCWSTR devid, LPDCB lpdcb, LPCOMMTIMEOUTS lptimeouts) /* ../dlls/kernel32/comm.c:469 */
{
	BOOL return_value;
	TRACE("Enter BuildCommDCBAndTimeoutsW\n");
	return_value = pBuildCommDCBAndTimeoutsW(devid, lpdcb, lptimeouts);
	TRACE("Leave BuildCommDCBAndTimeoutsW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_BuildCommDCBW(LPCWSTR devid, LPDCB lpdcb) /* ../dlls/kernel32/comm.c:526 */
{
	BOOL return_value;
	TRACE("Enter BuildCommDCBW\n");
	return_value = pBuildCommDCBW(devid, lpdcb);
	TRACE("Leave BuildCommDCBW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CallNamedPipeA(LPCSTR lpNamedPipeName, LPVOID lpInput, DWORD dwInputSize, LPVOID lpOutput, DWORD dwOutputSize, LPDWORD lpBytesRead, DWORD nTimeout) /* ../dlls/kernel32/sync.c:715 */
{
	BOOL return_value;
	TRACE("Enter CallNamedPipeA\n");
	return_value = pCallNamedPipeA(lpNamedPipeName, lpInput, dwInputSize, lpOutput, dwOutputSize, lpBytesRead, nTimeout);
	TRACE("Leave CallNamedPipeA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CancelTimerQueueTimer(HANDLE queue, HANDLE timer) /* ../dlls/kernel32/sync.c:468 */
{
	BOOL return_value;
	TRACE("Enter CancelTimerQueueTimer\n");
	return_value = pCancelTimerQueueTimer(queue, timer);
	TRACE("Leave CancelTimerQueueTimer\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CheckNameLegalDOS8Dot3A(char* name, char* oemname, DWORD oemname_len, BOOL* contains_spaces, BOOL* is_legal) /* ../dlls/kernel32/path.c:1975 */
{
	BOOL return_value;
	TRACE("Enter CheckNameLegalDOS8Dot3A\n");
	return_value = pCheckNameLegalDOS8Dot3A(name, oemname, oemname_len, contains_spaces, is_legal);
	TRACE("Leave CheckNameLegalDOS8Dot3A\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CheckNameLegalDOS8Dot3W(WCHAR* name, char* oemname, DWORD oemname_len, BOOL* contains_spaces_ret, BOOL* is_legal) /* ../dlls/kernel32/path.c:1994 */
{
	BOOL return_value;
	TRACE("Enter CheckNameLegalDOS8Dot3W\n");
	return_value = pCheckNameLegalDOS8Dot3W(name, oemname, oemname_len, contains_spaces_ret, is_legal);
	TRACE("Leave CheckNameLegalDOS8Dot3W\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CloseConsoleHandle(HANDLE handle) /* ../dlls/kernel32/console.c:291 */
{
	BOOL return_value;
	TRACE("Enter CloseConsoleHandle\n");
	return_value = pCloseConsoleHandle(handle);
	TRACE("Leave CloseConsoleHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CloseHandle(HANDLE handle) /* ../dlls/kernel32/process.c:3238 */
{
	BOOL return_value;
	TRACE("Enter CloseHandle\n");
	return_value = pCloseHandle(handle);
	TRACE("Leave CloseHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CloseProfileUserMapping(void) /* ../dlls/kernel32/profile.c:1786 */
{
	BOOL return_value;
	TRACE("Enter CloseProfileUserMapping\n");
	return_value = pCloseProfileUserMapping();
	TRACE("Leave CloseProfileUserMapping\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CmdBatNotification(BOOL bBatchRunning) /* ../dlls/kernel32/process.c:3888 */
{
	BOOL return_value;
	TRACE("Enter CmdBatNotification\n");
	return_value = pCmdBatNotification(bBatchRunning);
	TRACE("Leave CmdBatNotification\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CommConfigDialogA(LPCSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig) /* ../dlls/kernel32/comm.c:568 */
{
	BOOL return_value;
	TRACE("Enter CommConfigDialogA\n");
	return_value = pCommConfigDialogA(lpszDevice, hWnd, lpCommConfig);
	TRACE("Leave CommConfigDialogA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CommConfigDialogW(LPCWSTR lpszDevice, HWND hWnd, LPCOMMCONFIG lpCommConfig) /* ../dlls/kernel32/comm.c:595 */
{
	BOOL return_value;
	TRACE("Enter CommConfigDialogW\n");
	return_value = pCommConfigDialogW(lpszDevice, hWnd, lpCommConfig);
	TRACE("Leave CommConfigDialogW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_CompareFileTime(FILETIME* x, FILETIME* y) /* ../dlls/kernel32/time.c:1274 */
{
	INT return_value;
	TRACE("Enter CompareFileTime\n");
	return_value = pCompareFileTime(x, y);
	TRACE("Leave CompareFileTime\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_CompareStringA(LCID lcid, DWORD flags, LPCSTR str1, INT len1, LPCSTR str2, INT len2) /* ../dlls/kernel32/locale.c:3976 */
{
	INT return_value;
	TRACE("Enter CompareStringA\n");
	return_value = pCompareStringA(lcid, flags, str1, len1, str2, len2);
	TRACE("Leave CompareStringA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_CompareStringEx(LPCWSTR locale, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lParam) /* ../dlls/kernel32/locale.c:3916 */
{
	INT return_value;
	TRACE("Enter CompareStringEx\n");
	return_value = pCompareStringEx(locale, flags, str1, len1, str2, len2, version, reserved, lParam);
	TRACE("Leave CompareStringEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_CompareStringOrdinal(WCHAR* str1, INT len1, WCHAR* str2, INT len2, BOOL ignore_case) /* ../dlls/kernel32/locale.c:4052 */
{
	INT return_value;
	TRACE("Enter CompareStringOrdinal\n");
	return_value = pCompareStringOrdinal(str1, len1, str2, len2, ignore_case);
	TRACE("Leave CompareStringOrdinal\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_CompareStringW(LCID lcid, DWORD flags, LPCWSTR str1, INT len1, LPCWSTR str2, INT len2) /* ../dlls/kernel32/locale.c:3907 */
{
	INT return_value;
	TRACE("Enter CompareStringW\n");
	return_value = pCompareStringW(lcid, flags, str1, len1, str2, len2);
	TRACE("Leave CompareStringW\n");
	return return_value;
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

WINAPI LCID wine32b_kernel32_ConvertDefaultLocale(LCID lcid) /* ../dlls/kernel32/locale.c:2871 */
{
	LCID return_value;
	TRACE("Enter ConvertDefaultLocale\n");
	return_value = pConvertDefaultLocale(lcid);
	TRACE("Leave ConvertDefaultLocale\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_ConvertToGlobalHandle(HANDLE hSrc) /* ../dlls/kernel32/process.c:3338 */
{
	HANDLE return_value;
	TRACE("Enter ConvertToGlobalHandle\n");
	return_value = pConvertToGlobalHandle(hSrc);
	TRACE("Leave ConvertToGlobalHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CopyFileA(LPCSTR source, LPCSTR dest, BOOL fail_if_exists) /* ../dlls/kernel32/path.c:1152 */
{
	BOOL return_value;
	TRACE("Enter CopyFileA\n");
	return_value = pCopyFileA(source, dest, fail_if_exists);
	TRACE("Leave CopyFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CopyFileExA(LPCSTR sourceFilename, LPCSTR destFilename, LPPROGRESS_ROUTINE progressRoutine, LPVOID appData, LPBOOL cancelFlagPointer, DWORD copyFlags) /* ../dlls/kernel32/path.c:1265 */
{
	BOOL return_value;
	TRACE("Enter CopyFileExA\n");
	return_value = pCopyFileExA(sourceFilename, destFilename, progressRoutine, appData, cancelFlagPointer, copyFlags);
	TRACE("Leave CopyFileExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CopyFileExW(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE progress, LPVOID param, LPBOOL cancel_ptr, DWORD flags) /* ../dlls/kernel32/path.c:1170 */
{
	BOOL return_value;
	TRACE("Enter CopyFileExW\n");
	return_value = pCopyFileExW(source, dest, progress, param, cancel_ptr, flags);
	TRACE("Leave CopyFileExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CopyFileW(LPCWSTR source, LPCWSTR dest, BOOL fail_if_exists) /* ../dlls/kernel32/path.c:1142 */
{
	BOOL return_value;
	TRACE("Enter CopyFileW\n");
	return_value = pCopyFileW(source, dest, fail_if_exists);
	TRACE("Leave CopyFileW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateActCtxA(PCACTCTXA pActCtx) /* ../dlls/kernel32/actctx.c:41 */
{
	HANDLE return_value;
	TRACE("Enter CreateActCtxA\n");
	return_value = pCreateActCtxA(pActCtx);
	TRACE("Leave CreateActCtxA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateDirectoryExA(LPCSTR template, LPCSTR path, LPSECURITY_ATTRIBUTES sa) /* ../dlls/kernel32/path.c:1610 */
{
	BOOL return_value;
	TRACE("Enter CreateDirectoryExA\n");
	return_value = pCreateDirectoryExA(template, path, sa);
	TRACE("Leave CreateDirectoryExA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateFileMappingA(HANDLE file, SECURITY_ATTRIBUTES* sa, DWORD protect, DWORD size_high, DWORD size_low, LPCSTR name) /* ../dlls/kernel32/sync.c:483 */
{
	HANDLE return_value;
	TRACE("Enter CreateFileMappingA\n");
	return_value = pCreateFileMappingA(file, sa, protect, size_high, size_low, name);
	TRACE("Leave CreateFileMappingA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateHardLinkA(LPCSTR lpFileName, LPCSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) /* ../dlls/kernel32/path.c:1582 */
{
	BOOL return_value;
	TRACE("Enter CreateHardLinkA\n");
	return_value = pCreateHardLinkA(lpFileName, lpExistingFileName, lpSecurityAttributes);
	TRACE("Leave CreateHardLinkA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateHardLinkTransactedA(LPCSTR link, LPCSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction) /* ../dlls/kernel32/path.c:1955 */
{
	BOOL return_value;
	TRACE("Enter CreateHardLinkTransactedA\n");
	return_value = pCreateHardLinkTransactedA(link, target, sa, transaction);
	TRACE("Leave CreateHardLinkTransactedA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateHardLinkTransactedW(LPCWSTR link, LPCWSTR target, LPSECURITY_ATTRIBUTES sa, HANDLE transaction) /* ../dlls/kernel32/path.c:1965 */
{
	BOOL return_value;
	TRACE("Enter CreateHardLinkTransactedW\n");
	return_value = pCreateHardLinkTransactedW(link, target, sa, transaction);
	TRACE("Leave CreateHardLinkTransactedW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateHardLinkW(LPCWSTR lpFileName, LPCWSTR lpExistingFileName, LPSECURITY_ATTRIBUTES lpSecurityAttributes) /* ../dlls/kernel32/path.c:1525 */
{
	BOOL return_value;
	TRACE("Enter CreateHardLinkW\n");
	return_value = pCreateHardLinkW(lpFileName, lpExistingFileName, lpSecurityAttributes);
	TRACE("Leave CreateHardLinkW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateJobObjectA(LPSECURITY_ATTRIBUTES attr, LPCSTR name) /* ../dlls/kernel32/sync.c:292 */
{
	HANDLE return_value;
	TRACE("Enter CreateJobObjectA\n");
	return_value = pCreateJobObjectA(attr, name);
	TRACE("Leave CreateJobObjectA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateJobObjectW(LPSECURITY_ATTRIBUTES sa, LPCWSTR name) /* ../dlls/kernel32/sync.c:272 */
{
	HANDLE return_value;
	TRACE("Enter CreateJobObjectW\n");
	return_value = pCreateJobObjectW(sa, name);
	TRACE("Leave CreateJobObjectW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateMailslotA(LPCSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa) /* ../dlls/kernel32/sync.c:816 */
{
	HANDLE return_value;
	TRACE("Enter CreateMailslotA\n");
	return_value = pCreateMailslotA(lpName, nMaxMessageSize, lReadTimeout, sa);
	TRACE("Leave CreateMailslotA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateMailslotW(LPCWSTR lpName, DWORD nMaxMessageSize, DWORD lReadTimeout, LPSECURITY_ATTRIBUTES sa) /* ../dlls/kernel32/sync.c:856 */
{
	HANDLE return_value;
	TRACE("Enter CreateMailslotW\n");
	return_value = pCreateMailslotW(lpName, nMaxMessageSize, lReadTimeout, sa);
	TRACE("Leave CreateMailslotW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateNamedPipeA(LPCSTR name, DWORD dwOpenMode, DWORD dwPipeMode, DWORD nMaxInstances, DWORD nOutBufferSize, DWORD nInBufferSize, DWORD nDefaultTimeOut, LPSECURITY_ATTRIBUTES attr) /* ../dlls/kernel32/sync.c:525 */
{
	HANDLE return_value;
	TRACE("Enter CreateNamedPipeA\n");
	return_value = pCreateNamedPipeA(name, dwOpenMode, dwPipeMode, nMaxInstances, nOutBufferSize, nInBufferSize, nDefaultTimeOut, attr);
	TRACE("Leave CreateNamedPipeA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreatePipe(PHANDLE hReadPipe, PHANDLE hWritePipe, LPSECURITY_ATTRIBUTES sa, DWORD size) /* ../dlls/kernel32/sync.c:746 */
{
	BOOL return_value;
	TRACE("Enter CreatePipe\n");
	return_value = pCreatePipe(hReadPipe, hWritePipe, sa, size);
	TRACE("Leave CreatePipe\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessA(LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info) /* ../dlls/kernel32/process.c:2911 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessA\n");
	return_value = pCreateProcessA(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
	TRACE("Leave CreateProcessA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessAsUserA(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info) /* ../dlls/kernel32/process.c:2937 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessAsUserA\n");
	return_value = pCreateProcessAsUserA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
	TRACE("Leave CreateProcessAsUserA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessAsUserW(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info) /* ../dlls/kernel32/process.c:2952 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessAsUserW\n");
	return_value = pCreateProcessAsUserW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
	TRACE("Leave CreateProcessAsUserW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessInternalA(HANDLE token, LPCSTR app_name, LPSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCSTR cur_dir, LPSTARTUPINFOA startup_info, LPPROCESS_INFORMATION info, HANDLE* new_token) /* ../dlls/kernel32/process.c:2868 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessInternalA\n");
	return_value = pCreateProcessInternalA(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
	TRACE("Leave CreateProcessInternalA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessInternalW(HANDLE token, LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info, HANDLE* new_token) /* ../dlls/kernel32/process.c:2726 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessInternalW\n");
	return_value = pCreateProcessInternalW(token, app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info, new_token);
	TRACE("Leave CreateProcessInternalW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateProcessW(LPCWSTR app_name, LPWSTR cmd_line, LPSECURITY_ATTRIBUTES process_attr, LPSECURITY_ATTRIBUTES thread_attr, BOOL inherit, DWORD flags, LPVOID env, LPCWSTR cur_dir, LPSTARTUPINFOW startup_info, LPPROCESS_INFORMATION info) /* ../dlls/kernel32/process.c:2924 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessW\n");
	return_value = pCreateProcessW(app_name, cmd_line, process_attr, thread_attr, inherit, flags, env, cur_dir, startup_info, info);
	TRACE("Leave CreateProcessW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateSemaphoreA(SECURITY_ATTRIBUTES* sa, LONG initial, LONG max, LPCSTR name) /* ../dlls/kernel32/sync.c:222 */
{
	HANDLE return_value;
	TRACE("Enter CreateSemaphoreA\n");
	return_value = pCreateSemaphoreA(sa, initial, max, name);
	TRACE("Leave CreateSemaphoreA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateSemaphoreExA(SECURITY_ATTRIBUTES* sa, LONG initial, LONG max, LPCSTR name, DWORD flags, DWORD access) /* ../dlls/kernel32/sync.c:231 */
{
	HANDLE return_value;
	TRACE("Enter CreateSemaphoreExA\n");
	return_value = pCreateSemaphoreExA(sa, initial, max, name, flags, access);
	TRACE("Leave CreateSemaphoreExA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateSocketHandle(void) /* ../dlls/kernel32/process.c:3374 */
{
	HANDLE return_value;
	TRACE("Enter CreateSocketHandle\n");
	return_value = pCreateSocketHandle();
	TRACE("Leave CreateSocketHandle\n");
	return return_value;
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

WINAPI BOOLEAN wine32b_kernel32_CreateSymbolicLinkA(LPCSTR link, LPCSTR target, DWORD flags) /* ../dlls/kernel32/path.c:1946 */
{
	BOOLEAN return_value;
	TRACE("Enter CreateSymbolicLinkA\n");
	return_value = pCreateSymbolicLinkA(link, target, flags);
	TRACE("Leave CreateSymbolicLinkA\n");
	return return_value;
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

WINAPI BOOLEAN wine32b_kernel32_CreateSymbolicLinkW(LPCWSTR link, LPCWSTR target, DWORD flags) /* ../dlls/kernel32/path.c:1937 */
{
	BOOLEAN return_value;
	TRACE("Enter CreateSymbolicLinkW\n");
	return_value = pCreateSymbolicLinkW(link, target, flags);
	TRACE("Leave CreateSymbolicLinkW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_CreateTapePartition(HANDLE device, DWORD method, DWORD count, DWORD size) /* ../dlls/kernel32/tape.c:96 */
{
	DWORD return_value;
	TRACE("Enter CreateTapePartition\n");
	return_value = pCreateTapePartition(device, method, count, size);
	TRACE("Leave CreateTapePartition\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateToolhelp32Snapshot(DWORD flags, DWORD process) /* ../dlls/kernel32/toolhelp.c:293 */
{
	HANDLE return_value;
	TRACE("Enter CreateToolhelp32Snapshot\n");
	return_value = pCreateToolhelp32Snapshot(flags, process);
	TRACE("Leave CreateToolhelp32Snapshot\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateUmsCompletionList(PUMS_COMPLETION_LIST* list) /* ../dlls/kernel32/process.c:4126 */
{
	BOOL return_value;
	TRACE("Enter CreateUmsCompletionList\n");
	return_value = pCreateUmsCompletionList(list);
	TRACE("Leave CreateUmsCompletionList\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_CreateUmsThreadContext(PUMS_CONTEXT* ctx) /* ../dlls/kernel32/process.c:4136 */
{
	BOOL return_value;
	TRACE("Enter CreateUmsThreadContext\n");
	return_value = pCreateUmsThreadContext(ctx);
	TRACE("Leave CreateUmsThreadContext\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateWaitableTimerA(SECURITY_ATTRIBUTES* sa, BOOL manual, LPCSTR name) /* ../dlls/kernel32/sync.c:414 */
{
	HANDLE return_value;
	TRACE("Enter CreateWaitableTimerA\n");
	return_value = pCreateWaitableTimerA(sa, manual, name);
	TRACE("Leave CreateWaitableTimerA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_CreateWaitableTimerExA(SECURITY_ATTRIBUTES* sa, LPCSTR name, DWORD flags, DWORD access) /* ../dlls/kernel32/sync.c:424 */
{
	HANDLE return_value;
	TRACE("Enter CreateWaitableTimerExA\n");
	return_value = pCreateWaitableTimerExA(sa, name, flags, access);
	TRACE("Leave CreateWaitableTimerExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DebugBreakProcess(HANDLE process) /* ../dlls/kernel32/debugger.c:49 */
{
	BOOL return_value;
	TRACE("Enter DebugBreakProcess\n");
	return_value = pDebugBreakProcess(process);
	TRACE("Leave DebugBreakProcess\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DebugSetProcessKillOnExit(BOOL kill) /* ../dlls/kernel32/debugger.c:73 */
{
	BOOL return_value;
	TRACE("Enter DebugSetProcessKillOnExit\n");
	return_value = pDebugSetProcessKillOnExit(kill);
	TRACE("Leave DebugSetProcessKillOnExit\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DefineDosDeviceA(DWORD flags, LPCSTR devname, LPCSTR targetpath) /* ../dlls/kernel32/volume.c:1210 */
{
	BOOL return_value;
	TRACE("Enter DefineDosDeviceA\n");
	return_value = pDefineDosDeviceA(flags, devname, targetpath);
	TRACE("Leave DefineDosDeviceA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DefineDosDeviceW(DWORD flags, LPCWSTR devname, LPCWSTR targetpath) /* ../dlls/kernel32/volume.c:1137 */
{
	BOOL return_value;
	TRACE("Enter DefineDosDeviceW\n");
	return_value = pDefineDosDeviceW(flags, devname, targetpath);
	TRACE("Leave DefineDosDeviceW\n");
	return return_value;
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

WINAPI FARPROC wine32b_kernel32_DelayLoadFailureHook(LPCSTR name, LPCSTR function) /* ../dlls/kernel32/module.c:1024 */
{
	FARPROC return_value;
	TRACE("Enter DelayLoadFailureHook\n");
	return_value = pDelayLoadFailureHook(name, function);
	return_value = wine_make_thunk_function_alloc(return_value);
	TRACE("Leave DelayLoadFailureHook\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_DeleteAtom(ATOM atom) /* ../dlls/kernel32/atom.c:255 */
{
	ATOM return_value;
	TRACE("Enter DeleteAtom\n");
	return_value = pDeleteAtom(atom);
	TRACE("Leave DeleteAtom\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeleteTimerQueue(HANDLE TimerQueue) /* ../dlls/kernel32/sync.c:460 */
{
	BOOL return_value;
	TRACE("Enter DeleteTimerQueue\n");
	return_value = pDeleteTimerQueue(TimerQueue);
	TRACE("Leave DeleteTimerQueue\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeleteUmsCompletionList(PUMS_COMPLETION_LIST list) /* ../dlls/kernel32/process.c:4146 */
{
	BOOL return_value;
	TRACE("Enter DeleteUmsCompletionList\n");
	return_value = pDeleteUmsCompletionList(list);
	TRACE("Leave DeleteUmsCompletionList\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeleteUmsThreadContext(PUMS_CONTEXT ctx) /* ../dlls/kernel32/process.c:4156 */
{
	BOOL return_value;
	TRACE("Enter DeleteUmsThreadContext\n");
	return_value = pDeleteUmsThreadContext(ctx);
	TRACE("Leave DeleteUmsThreadContext\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeleteVolumeMountPointA(LPCSTR mountpoint) /* ../dlls/kernel32/volume.c:2126 */
{
	BOOL return_value;
	TRACE("Enter DeleteVolumeMountPointA\n");
	return_value = pDeleteVolumeMountPointA(mountpoint);
	TRACE("Leave DeleteVolumeMountPointA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeleteVolumeMountPointW(LPCWSTR mountpoint) /* ../dlls/kernel32/volume.c:2135 */
{
	BOOL return_value;
	TRACE("Enter DeleteVolumeMountPointW\n");
	return_value = pDeleteVolumeMountPointW(mountpoint);
	TRACE("Leave DeleteVolumeMountPointW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DequeueUmsCompletionListItems(void* list, DWORD timeout, PUMS_CONTEXT* ctx) /* ../dlls/kernel32/process.c:4166 */
{
	BOOL return_value;
	TRACE("Enter DequeueUmsCompletionListItems\n");
	return_value = pDequeueUmsCompletionListItems(list, timeout, ctx);
	TRACE("Leave DequeueUmsCompletionListItems\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DeviceIoControl(HANDLE hDevice, DWORD dwIoControlCode, LPVOID lpvInBuffer, DWORD cbInBuffer, LPVOID lpvOutBuffer, DWORD cbOutBuffer, LPDWORD lpcbBytesReturned, LPOVERLAPPED lpOverlapped) /* ../dlls/kernel32/file.c:1096 */
{
	BOOL return_value;
	TRACE("Enter DeviceIoControl\n");
	return_value = pDeviceIoControl(hDevice, dwIoControlCode, lpvInBuffer, cbInBuffer, lpvOutBuffer, cbOutBuffer, lpcbBytesReturned, lpOverlapped);
	TRACE("Leave DeviceIoControl\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DnsHostnameToComputerNameA(LPCSTR hostname, LPSTR computername, LPDWORD size) /* ../dlls/kernel32/computername.c:679 */
{
	BOOL return_value;
	TRACE("Enter DnsHostnameToComputerNameA\n");
	return_value = pDnsHostnameToComputerNameA(hostname, computername, size);
	TRACE("Leave DnsHostnameToComputerNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DnsHostnameToComputerNameW(LPCWSTR hostname, LPWSTR computername, LPDWORD size) /* ../dlls/kernel32/computername.c:707 */
{
	BOOL return_value;
	TRACE("Enter DnsHostnameToComputerNameW\n");
	return_value = pDnsHostnameToComputerNameW(hostname, computername, size);
	TRACE("Leave DnsHostnameToComputerNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DosDateTimeToFileTime(WORD fatdate, WORD fattime, LPFILETIME ft) /* ../dlls/kernel32/time.c:1358 */
{
	BOOL return_value;
	TRACE("Enter DosDateTimeToFileTime\n");
	return_value = pDosDateTimeToFileTime(fatdate, fattime, ft);
	TRACE("Leave DosDateTimeToFileTime\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_DuplicateConsoleHandle(HANDLE handle, DWORD access, BOOL inherit, DWORD options) /* ../dlls/kernel32/console.c:274 */
{
	HANDLE return_value;
	TRACE("Enter DuplicateConsoleHandle\n");
	return_value = pDuplicateConsoleHandle(handle, access, inherit, options);
	TRACE("Leave DuplicateConsoleHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_DuplicateHandle(HANDLE source_process, HANDLE source, HANDLE dest_process, HANDLE* dest, DWORD access, BOOL inherit, DWORD options) /* ../dlls/kernel32/process.c:3310 */
{
	BOOL return_value;
	TRACE("Enter DuplicateHandle\n");
	return_value = pDuplicateHandle(source_process, source, dest_process, dest, access, inherit, options);
	TRACE("Leave DuplicateHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EndUpdateResourceA(HANDLE hUpdate, BOOL fDiscard) /* ../dlls/kernel32/resource.c:1280 */
{
	BOOL return_value;
	TRACE("Enter EndUpdateResourceA\n");
	return_value = pEndUpdateResourceA(hUpdate, fDiscard);
	TRACE("Leave EndUpdateResourceA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EndUpdateResourceW(HANDLE hUpdate, BOOL fDiscard) /* ../dlls/kernel32/resource.c:1254 */
{
	BOOL return_value;
	TRACE("Enter EndUpdateResourceW\n");
	return_value = pEndUpdateResourceW(hUpdate, fDiscard);
	TRACE("Leave EndUpdateResourceW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnterUmsSchedulingMode(UMS_SCHEDULER_STARTUP_INFO* info) /* ../dlls/kernel32/process.c:4176 */
{
	BOOL return_value;
	TRACE("Enter EnterUmsSchedulingMode\n");
	return_value = pEnterUmsSchedulingMode(info);
	TRACE("Leave EnterUmsSchedulingMode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumCalendarInfoA(CALINFO_ENUMPROCA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype) /* ../dlls/kernel32/lcformat.c:2230 */
{
	BOOL return_value;
	TRACE("Enter EnumCalendarInfoA\n");
	return_value = pEnumCalendarInfoA(calinfoproc, locale, calendar, caltype);
	TRACE("Leave EnumCalendarInfoA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExA(CALINFO_ENUMPROCEXA calinfoproc, LCID locale, CALID calendar, CALTYPE caltype) /* ../dlls/kernel32/lcformat.c:2270 */
{
	BOOL return_value;
	TRACE("Enter EnumCalendarInfoExA\n");
	return_value = pEnumCalendarInfoExA(calinfoproc, locale, calendar, caltype);
	TRACE("Leave EnumCalendarInfoExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExEx(CALINFO_ENUMPROCEXEX calinfoproc, LPCWSTR locale, CALID calendar, LPCWSTR reserved, CALTYPE caltype, LPARAM lParam) /* ../dlls/kernel32/lcformat.c:2310 */
{
	BOOL return_value;
	TRACE("Enter EnumCalendarInfoExEx\n");
	return_value = pEnumCalendarInfoExEx(calinfoproc, locale, calendar, reserved, caltype, lParam);
	TRACE("Leave EnumCalendarInfoExEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumCalendarInfoExW(CALINFO_ENUMPROCEXW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype) /* ../dlls/kernel32/lcformat.c:2290 */
{
	BOOL return_value;
	TRACE("Enter EnumCalendarInfoExW\n");
	return_value = pEnumCalendarInfoExW(calinfoproc, locale, calendar, caltype);
	TRACE("Leave EnumCalendarInfoExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumCalendarInfoW(CALINFO_ENUMPROCW calinfoproc, LCID locale, CALID calendar, CALTYPE caltype) /* ../dlls/kernel32/lcformat.c:2250 */
{
	BOOL return_value;
	TRACE("Enter EnumCalendarInfoW\n");
	return_value = pEnumCalendarInfoW(calinfoproc, locale, calendar, caltype);
	TRACE("Leave EnumCalendarInfoW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumDateFormatsA(DATEFMT_ENUMPROCA proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:1910 */
{
	BOOL return_value;
	TRACE("Enter EnumDateFormatsA\n");
	return_value = pEnumDateFormatsA(proc, lcid, flags);
	TRACE("Leave EnumDateFormatsA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumDateFormatsExA(DATEFMT_ENUMPROCEXA proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:1875 */
{
	BOOL return_value;
	TRACE("Enter EnumDateFormatsExA\n");
	return_value = pEnumDateFormatsExA(proc, lcid, flags);
	TRACE("Leave EnumDateFormatsExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumDateFormatsExEx(DATEFMT_ENUMPROCEXEX proc, WCHAR* locale, DWORD flags, LPARAM lParam) /* ../dlls/kernel32/lcformat.c:1942 */
{
	BOOL return_value;
	TRACE("Enter EnumDateFormatsExEx\n");
	return_value = pEnumDateFormatsExEx(proc, locale, flags, lParam);
	TRACE("Leave EnumDateFormatsExEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumDateFormatsExW(DATEFMT_ENUMPROCEXW proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:1891 */
{
	BOOL return_value;
	TRACE("Enter EnumDateFormatsExW\n");
	return_value = pEnumDateFormatsExW(proc, lcid, flags);
	TRACE("Leave EnumDateFormatsExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumDateFormatsW(DATEFMT_ENUMPROCW proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:1926 */
{
	BOOL return_value;
	TRACE("Enter EnumDateFormatsW\n");
	return_value = pEnumDateFormatsW(proc, lcid, flags);
	TRACE("Leave EnumDateFormatsW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumLanguageGroupLocalesA(LANGGROUPLOCALE_ENUMPROCA pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4553 */
{
	BOOL return_value;
	TRACE("Enter EnumLanguageGroupLocalesA\n");
	return_value = pEnumLanguageGroupLocalesA(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
	TRACE("Leave EnumLanguageGroupLocalesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumLanguageGroupLocalesW(LANGGROUPLOCALE_ENUMPROCW pLangGrpLcEnumProc, LGRPID lgrpid, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4574 */
{
	BOOL return_value;
	TRACE("Enter EnumLanguageGroupLocalesW\n");
	return_value = pEnumLanguageGroupLocalesW(pLangGrpLcEnumProc, lgrpid, dwFlags, lParam);
	TRACE("Leave EnumLanguageGroupLocalesW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumResourceLanguagesA(HMODULE hmod, LPCSTR type, LPCSTR name, ENUMRESLANGPROCA lpfun, LONG_PTR lparam) /* ../dlls/kernel32/resource.c:139 */
{
	BOOL return_value;
	TRACE("Enter EnumResourceLanguagesA\n");
	return_value = pEnumResourceLanguagesA(hmod, type, name, lpfun, lparam);
	TRACE("Leave EnumResourceLanguagesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumResourceLanguagesW(HMODULE hmod, LPCWSTR type, LPCWSTR name, ENUMRESLANGPROCW lpfun, LONG_PTR lparam) /* ../dlls/kernel32/resource.c:149 */
{
	BOOL return_value;
	TRACE("Enter EnumResourceLanguagesW\n");
	return_value = pEnumResourceLanguagesW(hmod, type, name, lpfun, lparam);
	TRACE("Leave EnumResourceLanguagesW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumResourceNamesA(HMODULE hmod, LPCSTR type, ENUMRESNAMEPROCA lpfun, LONG_PTR lparam) /* ../dlls/kernel32/resource.c:130 */
{
	BOOL return_value;
	TRACE("Enter EnumResourceNamesA\n");
	return_value = pEnumResourceNamesA(hmod, type, lpfun, lparam);
	TRACE("Leave EnumResourceNamesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumResourceTypesA(HMODULE hmod, ENUMRESTYPEPROCA lpfun, LONG_PTR lparam) /* ../dlls/kernel32/resource.c:112 */
{
	BOOL return_value;
	TRACE("Enter EnumResourceTypesA\n");
	return_value = pEnumResourceTypesA(hmod, lpfun, lparam);
	TRACE("Leave EnumResourceTypesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumResourceTypesW(HMODULE hmod, ENUMRESTYPEPROCW lpfun, LONG_PTR lparam) /* ../dlls/kernel32/resource.c:121 */
{
	BOOL return_value;
	TRACE("Enter EnumResourceTypesW\n");
	return_value = pEnumResourceTypesW(hmod, lpfun, lparam);
	TRACE("Leave EnumResourceTypesW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemCodePagesA(CODEPAGE_ENUMPROCA lpfnCodePageEnum, DWORD flags) /* ../dlls/kernel32/locale.c:2262 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemCodePagesA\n");
	return_value = pEnumSystemCodePagesA(lpfnCodePageEnum, flags);
	TRACE("Leave EnumSystemCodePagesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemCodePagesW(CODEPAGE_ENUMPROCW lpfnCodePageEnum, DWORD flags) /* ../dlls/kernel32/locale.c:2283 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemCodePagesW\n");
	return_value = pEnumSystemCodePagesW(lpfnCodePageEnum, flags);
	TRACE("Leave EnumSystemCodePagesW\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_EnumSystemFirmwareTables(DWORD provider, void* buffer, DWORD size) /* ../dlls/kernel32/cpu.c:328 */
{
	UINT return_value;
	TRACE("Enter EnumSystemFirmwareTables\n");
	return_value = pEnumSystemFirmwareTables(provider, buffer, size);
	TRACE("Leave EnumSystemFirmwareTables\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemGeoID(GEOCLASS geoclass, GEOID parent, GEO_ENUMPROC enumproc) /* ../dlls/kernel32/locale.c:5228 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemGeoID\n");
	return_value = pEnumSystemGeoID(geoclass, parent, enumproc);
	TRACE("Leave EnumSystemGeoID\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4354 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemLanguageGroupsA\n");
	return_value = pEnumSystemLanguageGroupsA(pLangGrpEnumProc, dwFlags, lParam);
	TRACE("Leave EnumSystemLanguageGroupsA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW pLangGrpEnumProc, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4374 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemLanguageGroupsW\n");
	return_value = pEnumSystemLanguageGroupsW(pLangGrpEnumProc, dwFlags, lParam);
	TRACE("Leave EnumSystemLanguageGroupsW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemLocalesA(LOCALE_ENUMPROCA lpfnLocaleEnum, DWORD dwFlags) /* ../dlls/kernel32/locale.c:2976 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemLocalesA\n");
	return_value = pEnumSystemLocalesA(lpfnLocaleEnum, dwFlags);
	TRACE("Leave EnumSystemLocalesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemLocalesEx(LOCALE_ENUMPROCEX proc, DWORD flags, LPARAM lparam, LPVOID reserved) /* ../dlls/kernel32/locale.c:3031 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemLocalesEx\n");
	return_value = pEnumSystemLocalesEx(proc, flags, lparam, reserved);
	TRACE("Leave EnumSystemLocalesEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumSystemLocalesW(LOCALE_ENUMPROCW lpfnLocaleEnum, DWORD dwFlags) /* ../dlls/kernel32/locale.c:2991 */
{
	BOOL return_value;
	TRACE("Enter EnumSystemLocalesW\n");
	return_value = pEnumSystemLocalesW(lpfnLocaleEnum, dwFlags);
	TRACE("Leave EnumSystemLocalesW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumTimeFormatsA(TIMEFMT_ENUMPROCA proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:2025 */
{
	BOOL return_value;
	TRACE("Enter EnumTimeFormatsA\n");
	return_value = pEnumTimeFormatsA(proc, lcid, flags);
	TRACE("Leave EnumTimeFormatsA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumTimeFormatsEx(TIMEFMT_ENUMPROCEX proc, WCHAR* locale, DWORD flags, LPARAM lParam) /* ../dlls/kernel32/lcformat.c:2064 */
{
	BOOL return_value;
	TRACE("Enter EnumTimeFormatsEx\n");
	return_value = pEnumTimeFormatsEx(proc, locale, flags, lParam);
	TRACE("Leave EnumTimeFormatsEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumTimeFormatsW(TIMEFMT_ENUMPROCW proc, LCID lcid, DWORD flags) /* ../dlls/kernel32/lcformat.c:2048 */
{
	BOOL return_value;
	TRACE("Enter EnumTimeFormatsW\n");
	return_value = pEnumTimeFormatsW(proc, lcid, flags);
	TRACE("Leave EnumTimeFormatsW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumUILanguagesA(UILANGUAGE_ENUMPROCA pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4718 */
{
	BOOL return_value;
	TRACE("Enter EnumUILanguagesA\n");
	return_value = pEnumUILanguagesA(pUILangEnumProc, dwFlags, lParam);
	TRACE("Leave EnumUILanguagesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_EnumUILanguagesW(UILANGUAGE_ENUMPROCW pUILangEnumProc, DWORD dwFlags, LONG_PTR lParam) /* ../dlls/kernel32/locale.c:4746 */
{
	BOOL return_value;
	TRACE("Enter EnumUILanguagesW\n");
	return_value = pEnumUILanguagesW(pUILangEnumProc, dwFlags, lParam);
	TRACE("Leave EnumUILanguagesW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_EraseTape(HANDLE device, DWORD type, BOOL immediate) /* ../dlls/kernel32/tape.c:121 */
{
	DWORD return_value;
	TRACE("Enter EraseTape\n");
	return_value = pEraseTape(device, type, immediate);
	TRACE("Leave EraseTape\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ExecuteUmsThread(PUMS_CONTEXT ctx) /* ../dlls/kernel32/process.c:4186 */
{
	BOOL return_value;
	TRACE("Enter ExecuteUmsThread\n");
	return_value = pExecuteUmsThread(ctx);
	TRACE("Leave ExecuteUmsThread\n");
	return return_value;
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

WINAPI void wine32b_kernel32_ExitProcess(DWORD status) /* ../dlls/kernel32/process.c:3158 */
{
	TRACE("Enter ExitProcess\n");
	pExitProcess(status);
	TRACE("Leave ExitProcess\n");
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

WINAPI void wine32b_kernel32_ExpungeConsoleCommandHistoryA(LPCSTR unknown) /* ../dlls/kernel32/console.c:1588 */
{
	TRACE("Enter ExpungeConsoleCommandHistoryA\n");
	pExpungeConsoleCommandHistoryA(unknown);
	TRACE("Leave ExpungeConsoleCommandHistoryA\n");
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

WINAPI void wine32b_kernel32_ExpungeConsoleCommandHistoryW(LPCWSTR unknown) /* ../dlls/kernel32/console.c:1594 */
{
	TRACE("Enter ExpungeConsoleCommandHistoryW\n");
	pExpungeConsoleCommandHistoryW(unknown);
	TRACE("Leave ExpungeConsoleCommandHistoryW\n");
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

WINAPI void wine32b_kernel32_FatalExit(int code) /* ../dlls/kernel32/process.c:3198 */
{
	TRACE("Enter FatalExit\n");
	pFatalExit(code);
	TRACE("Leave FatalExit\n");
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

WINAPI BOOL wine32b_kernel32_FileTimeToDosDateTime(FILETIME* ft, LPWORD fatdate, LPWORD fattime) /* ../dlls/kernel32/time.c:1388 */
{
	BOOL return_value;
	TRACE("Enter FileTimeToDosDateTime\n");
	return_value = pFileTimeToDosDateTime(ft, fatdate, fattime);
	TRACE("Leave FileTimeToDosDateTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FileTimeToLocalFileTime(FILETIME* utcft, LPFILETIME localft) /* ../dlls/kernel32/time.c:1196 */
{
	BOOL return_value;
	TRACE("Enter FileTimeToLocalFileTime\n");
	return_value = pFileTimeToLocalFileTime(utcft, localft);
	TRACE("Leave FileTimeToLocalFileTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FileTimeToSystemTime(FILETIME* ft, LPSYSTEMTIME syst) /* ../dlls/kernel32/time.c:1216 */
{
	BOOL return_value;
	TRACE("Enter FileTimeToSystemTime\n");
	return_value = pFileTimeToSystemTime(ft, syst);
	TRACE("Leave FileTimeToSystemTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindActCtxSectionStringA(DWORD dwFlags, GUID* lpExtGuid, ULONG ulId, LPCSTR lpSearchStr, PACTCTX_SECTION_KEYED_DATA pInfo) /* ../dlls/kernel32/actctx.c:117 */
{
	BOOL return_value;
	TRACE("Enter FindActCtxSectionStringA\n");
	return_value = pFindActCtxSectionStringA(dwFlags, lpExtGuid, ulId, lpSearchStr, pInfo);
	TRACE("Leave FindActCtxSectionStringA\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_FindAtomA(LPCSTR str) /* ../dlls/kernel32/atom.c:315 */
{
	ATOM return_value;
	TRACE("Enter FindAtomA\n");
	return_value = pFindAtomA(str);
	TRACE("Leave FindAtomA\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_FindAtomW(LPCWSTR str) /* ../dlls/kernel32/atom.c:368 */
{
	ATOM return_value;
	TRACE("Enter FindAtomW\n");
	return_value = pFindAtomW(str);
	TRACE("Leave FindAtomW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindClose(HANDLE handle) /* ../dlls/kernel32/file.c:943 */
{
	BOOL return_value;
	TRACE("Enter FindClose\n");
	return_value = pFindClose(handle);
	TRACE("Leave FindClose\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstFileA(LPCSTR lpFileName, WIN32_FIND_DATAA* lpFindData) /* ../dlls/kernel32/file.c:988 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstFileA\n");
	return_value = pFindFirstFileA(lpFileName, lpFindData);
	TRACE("Leave FindFirstFileA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstFileExA(LPCSTR lpFileName, FINDEX_INFO_LEVELS fInfoLevelId, LPVOID lpFindFileData, FINDEX_SEARCH_OPS fSearchOp, LPVOID lpSearchFilter, DWORD dwAdditionalFlags) /* ../dlls/kernel32/file.c:997 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstFileExA\n");
	return_value = pFindFirstFileExA(lpFileName, fInfoLevelId, lpFindFileData, fSearchOp, lpSearchFilter, dwAdditionalFlags);
	TRACE("Leave FindFirstFileExA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstFileExW(LPCWSTR filename, FINDEX_INFO_LEVELS level, LPVOID data, FINDEX_SEARCH_OPS search_op, LPVOID filter, DWORD flags) /* ../dlls/kernel32/file.c:656 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstFileExW\n");
	return_value = pFindFirstFileExW(filename, level, data, search_op, filter, flags);
	TRACE("Leave FindFirstFileExW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstFileW(LPCWSTR lpFileName, WIN32_FIND_DATAW* lpFindData) /* ../dlls/kernel32/file.c:1028 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstFileW\n");
	return_value = pFindFirstFileW(lpFileName, lpFindData);
	TRACE("Leave FindFirstFileW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstStreamW(LPCWSTR filename, STREAM_INFO_LEVELS infolevel, void* data, DWORD flags) /* ../dlls/kernel32/file.c:1058 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstStreamW\n");
	return_value = pFindFirstStreamW(filename, infolevel, data, flags);
	TRACE("Leave FindFirstStreamW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstVolumeA(LPSTR volume, DWORD len) /* ../dlls/kernel32/volume.c:1977 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstVolumeA\n");
	return_value = pFindFirstVolumeA(volume, len);
	TRACE("Leave FindFirstVolumeA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstVolumeMountPointA(LPCSTR root, LPSTR mount_point, DWORD len) /* ../dlls/kernel32/volume.c:2097 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstVolumeMountPointA\n");
	return_value = pFindFirstVolumeMountPointA(root, mount_point, len);
	TRACE("Leave FindFirstVolumeMountPointA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstVolumeMountPointW(LPCWSTR root, LPWSTR mount_point, DWORD len) /* ../dlls/kernel32/volume.c:2107 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstVolumeMountPointW\n");
	return_value = pFindFirstVolumeMountPointW(root, mount_point, len);
	TRACE("Leave FindFirstVolumeMountPointW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_FindFirstVolumeW(LPWSTR volume, DWORD len) /* ../dlls/kernel32/volume.c:1997 */
{
	HANDLE return_value;
	TRACE("Enter FindFirstVolumeW\n");
	return_value = pFindFirstVolumeW(volume, len);
	TRACE("Leave FindFirstVolumeW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_FindNLSStringEx(WCHAR* localename, DWORD flags, WCHAR* src, INT src_size, WCHAR* value, INT value_size, INT* found, NLSVERSIONINFO* version_info, void* reserved, LPARAM sort_handle) /* ../dlls/kernel32/locale.c:5910 */
{
	INT return_value;
	TRACE("Enter FindNLSStringEx\n");
	return_value = pFindNLSStringEx(localename, flags, src, src_size, value, value_size, found, version_info, reserved, sort_handle);
	TRACE("Leave FindNLSStringEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindNextFileA(HANDLE handle, WIN32_FIND_DATAA* data) /* ../dlls/kernel32/file.c:1038 */
{
	BOOL return_value;
	TRACE("Enter FindNextFileA\n");
	return_value = pFindNextFileA(handle, data);
	TRACE("Leave FindNextFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindNextFileW(HANDLE handle, WIN32_FIND_DATAW* data) /* ../dlls/kernel32/file.c:837 */
{
	BOOL return_value;
	TRACE("Enter FindNextFileW\n");
	return_value = pFindNextFileW(handle, data);
	TRACE("Leave FindNextFileW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindNextStreamW(HANDLE handle, void* data) /* ../dlls/kernel32/file.c:1069 */
{
	BOOL return_value;
	TRACE("Enter FindNextStreamW\n");
	return_value = pFindNextStreamW(handle, data);
	TRACE("Leave FindNextStreamW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindNextVolumeA(HANDLE handle, LPSTR volume, DWORD len) /* ../dlls/kernel32/volume.c:2042 */
{
	BOOL return_value;
	TRACE("Enter FindNextVolumeA\n");
	return_value = pFindNextVolumeA(handle, volume, len);
	TRACE("Leave FindNextVolumeA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindNextVolumeW(HANDLE handle, LPWSTR volume, DWORD len) /* ../dlls/kernel32/volume.c:2058 */
{
	BOOL return_value;
	TRACE("Enter FindNextVolumeW\n");
	return_value = pFindNextVolumeW(handle, volume, len);
	TRACE("Leave FindNextVolumeW\n");
	return return_value;
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

WINAPI HRSRC wine32b_kernel32_FindResourceA(HMODULE hModule, LPCSTR name, LPCSTR type) /* ../dlls/kernel32/resource.c:103 */
{
	HRSRC return_value;
	TRACE("Enter FindResourceA\n");
	return_value = pFindResourceA(hModule, name, type);
	TRACE("Leave FindResourceA\n");
	return return_value;
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

WINAPI HRSRC wine32b_kernel32_FindResourceExA(HMODULE module, LPCSTR type, LPCSTR name, WORD lang) /* ../dlls/kernel32/resource.c:69 */
{
	HRSRC return_value;
	TRACE("Enter FindResourceExA\n");
	return_value = pFindResourceExA(module, type, name, lang);
	TRACE("Leave FindResourceExA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_FindStringOrdinal(DWORD flag, WCHAR* src, INT src_size, WCHAR* val, INT val_size, BOOL ignore_case) /* ../dlls/kernel32/locale.c:5961 */
{
	INT return_value;
	TRACE("Enter FindStringOrdinal\n");
	return_value = pFindStringOrdinal(flag, src, src_size, val, val_size, ignore_case);
	TRACE("Leave FindStringOrdinal\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindVolumeClose(HANDLE handle) /* ../dlls/kernel32/volume.c:2089 */
{
	BOOL return_value;
	TRACE("Enter FindVolumeClose\n");
	return_value = pFindVolumeClose(handle);
	TRACE("Leave FindVolumeClose\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FindVolumeMountPointClose(HANDLE h) /* ../dlls/kernel32/volume.c:2117 */
{
	BOOL return_value;
	TRACE("Enter FindVolumeMountPointClose\n");
	return_value = pFindVolumeMountPointClose(h);
	TRACE("Leave FindVolumeMountPointClose\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FlushConsoleInputBuffer(HANDLE handle) /* ../dlls/kernel32/console.c:464 */
{
	BOOL return_value;
	TRACE("Enter FlushConsoleInputBuffer\n");
	return_value = pFlushConsoleInputBuffer(handle);
	TRACE("Leave FlushConsoleInputBuffer\n");
	return return_value;
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

WINAPI void wine32b_kernel32_FlushProcessWriteBuffers(void) /* ../dlls/kernel32/process.c:4105 */
{
	TRACE("Enter FlushProcessWriteBuffers\n");
	pFlushProcessWriteBuffers();
	TRACE("Leave FlushProcessWriteBuffers\n");
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

WINAPI INT wine32b_kernel32_FoldStringA(DWORD dwFlags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen) /* ../dlls/kernel32/locale.c:3814 */
{
	INT return_value;
	TRACE("Enter FoldStringA\n");
	return_value = pFoldStringA(dwFlags, src, srclen, dst, dstlen);
	TRACE("Leave FoldStringA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_FoldStringW(DWORD dwFlags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen) /* ../dlls/kernel32/locale.c:3872 */
{
	INT return_value;
	TRACE("Enter FoldStringW\n");
	return_value = pFoldStringW(dwFlags, src, srclen, dst, dstlen);
	TRACE("Leave FoldStringW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_FormatMessageA(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPSTR lpBuffer, DWORD nSize, __builtin_ms_va_list* args) /* ../dlls/kernel32/format_msg.c:460 */
{
	DWORD return_value;
	TRACE("Enter FormatMessageA\n");
	return_value = pFormatMessageA(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
	TRACE("Leave FormatMessageA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_FormatMessageW(DWORD dwFlags, LPCVOID lpSource, DWORD dwMessageId, DWORD dwLanguageId, LPWSTR lpBuffer, DWORD nSize, __builtin_ms_va_list* args) /* ../dlls/kernel32/format_msg.c:560 */
{
	DWORD return_value;
	TRACE("Enter FormatMessageW\n");
	return_value = pFormatMessageW(dwFlags, lpSource, dwMessageId, dwLanguageId, lpBuffer, nSize, args);
	TRACE("Leave FormatMessageW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FreeConsole(void) /* ../dlls/kernel32/console.c:540 */
{
	BOOL return_value;
	TRACE("Enter FreeConsole\n");
	return_value = pFreeConsole();
	TRACE("Leave FreeConsole\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_FreeLibrary(HINSTANCE hLibModule) /* ../dlls/kernel32/module.c:887 */
{
	BOOL return_value;
	TRACE("Enter FreeLibrary\n");
	return_value = pFreeLibrary(hLibModule);
	TRACE("Leave FreeLibrary\n");
	return return_value;
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

WINAPI void wine32b_kernel32_FreeLibraryAndExitThread(HINSTANCE hLibModule, DWORD dwExitCode) /* ../dlls/kernel32/thread.c:40 */
{
	TRACE("Enter FreeLibraryAndExitThread\n");
	pFreeLibraryAndExitThread(hLibModule, dwExitCode);
	TRACE("Leave FreeLibraryAndExitThread\n");
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

WINAPI BOOL wine32b_kernel32_FreeUserPhysicalPages(HANDLE process, ULONG_PTR* pages, ULONG_PTR* userarray) /* ../dlls/kernel32/heap.c:936 */
{
	BOOL return_value;
	TRACE("Enter FreeUserPhysicalPages\n");
	return_value = pFreeUserPhysicalPages(process, pages, userarray);
	TRACE("Leave FreeUserPhysicalPages\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetACP(void) /* ../dlls/kernel32/locale.c:2009 */
{
	UINT return_value;
	TRACE("Enter GetACP\n");
	return_value = pGetACP();
	TRACE("Leave GetACP\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetActiveProcessorCount(WORD group) /* ../dlls/kernel32/cpu.c:257 */
{
	DWORD return_value;
	TRACE("Enter GetActiveProcessorCount\n");
	return_value = pGetActiveProcessorCount(group);
	TRACE("Leave GetActiveProcessorCount\n");
	return return_value;
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

WINAPI WORD wine32b_kernel32_GetActiveProcessorGroupCount(void) /* ../dlls/kernel32/cpu.c:248 */
{
	WORD return_value;
	TRACE("Enter GetActiveProcessorGroupCount\n");
	return_value = pGetActiveProcessorGroupCount();
	TRACE("Leave GetActiveProcessorGroupCount\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_GetApplicationRestartSettings(HANDLE process, WCHAR* cmdline, DWORD* size, DWORD* flags) /* ../dlls/kernel32/process.c:3966 */
{
	HRESULT return_value;
	TRACE("Enter GetApplicationRestartSettings\n");
	return_value = pGetApplicationRestartSettings(process, cmdline, size, flags);
	TRACE("Leave GetApplicationRestartSettings\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetAtomNameA(ATOM atom, LPSTR buffer, INT count) /* ../dlls/kernel32/atom.c:432 */
{
	UINT return_value;
	TRACE("Enter GetAtomNameA\n");
	return_value = pGetAtomNameA(atom, buffer, count);
	TRACE("Leave GetAtomNameA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetAtomNameW(ATOM atom, LPWSTR buffer, INT count) /* ../dlls/kernel32/atom.c:502 */
{
	UINT return_value;
	TRACE("Enter GetAtomNameW\n");
	return_value = pGetAtomNameW(atom, buffer, count);
	TRACE("Leave GetAtomNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetBinaryTypeA(LPCSTR lpApplicationName, LPDWORD lpBinaryType) /* ../dlls/kernel32/module.c:356 */
{
	BOOL return_value;
	TRACE("Enter GetBinaryTypeA\n");
	return_value = pGetBinaryTypeA(lpApplicationName, lpBinaryType);
	TRACE("Leave GetBinaryTypeA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetBinaryTypeW(LPCWSTR name, LPDWORD type) /* ../dlls/kernel32/module.c:270 */
{
	BOOL return_value;
	TRACE("Enter GetBinaryTypeW\n");
	return_value = pGetBinaryTypeW(name, type);
	TRACE("Leave GetBinaryTypeW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetCPInfo(UINT codepage, LPCPINFO cpinfo) /* ../dlls/kernel32/locale.c:2132 */
{
	BOOL return_value;
	TRACE("Enter GetCPInfo\n");
	return_value = pGetCPInfo(codepage, cpinfo);
	TRACE("Leave GetCPInfo\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetCPInfoExA(UINT codepage, DWORD dwFlags, LPCPINFOEXA cpinfo) /* ../dlls/kernel32/locale.c:2190 */
{
	BOOL return_value;
	TRACE("Enter GetCPInfoExA\n");
	return_value = pGetCPInfoExA(codepage, dwFlags, cpinfo);
	TRACE("Leave GetCPInfoExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetCPInfoExW(UINT codepage, DWORD dwFlags, LPCPINFOEXW cpinfo) /* ../dlls/kernel32/locale.c:2208 */
{
	BOOL return_value;
	TRACE("Enter GetCPInfoExW\n");
	return_value = pGetCPInfoExW(codepage, dwFlags, cpinfo);
	TRACE("Leave GetCPInfoExW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetCalendarInfoA(LCID lcid, CALID Calendar, CALTYPE CalType, LPSTR lpCalData, int cchData, LPDWORD lpValue) /* ../dlls/kernel32/time.c:910 */
{
	INT return_value;
	TRACE("Enter GetCalendarInfoA\n");
	return_value = pGetCalendarInfoA(lcid, Calendar, CalType, lpCalData, cchData, lpValue);
	TRACE("Leave GetCalendarInfoA\n");
	return return_value;
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

WINAPI int wine32b_kernel32_GetCalendarInfoEx(LPCWSTR locale, CALID calendar, LPCWSTR lpReserved, CALTYPE caltype, LPWSTR data, int len, DWORD* value) /* ../dlls/kernel32/time.c:1138 */
{
	int return_value;
	TRACE("Enter GetCalendarInfoEx\n");
	return_value = pGetCalendarInfoEx(locale, calendar, lpReserved, caltype, data, len, value);
	TRACE("Leave GetCalendarInfoEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetCalendarInfoW(LCID Locale, CALID Calendar, CALTYPE CalType, LPWSTR lpCalData, int cchData, LPDWORD lpValue) /* ../dlls/kernel32/time.c:941 */
{
	INT return_value;
	TRACE("Enter GetCalendarInfoW\n");
	return_value = pGetCalendarInfoW(Locale, Calendar, CalType, lpCalData, cchData, lpValue);
	TRACE("Leave GetCalendarInfoW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetComputerNameA(LPSTR name, LPDWORD size) /* ../dlls/kernel32/computername.c:382 */
{
	BOOL return_value;
	TRACE("Enter GetComputerNameA\n");
	return_value = pGetComputerNameA(name, size);
	TRACE("Leave GetComputerNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetComputerNameExA(COMPUTER_NAME_FORMAT type, LPSTR name, LPDWORD size) /* ../dlls/kernel32/computername.c:421 */
{
	BOOL return_value;
	TRACE("Enter GetComputerNameExA\n");
	return_value = pGetComputerNameExA(type, name, size);
	TRACE("Leave GetComputerNameExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetComputerNameExW(COMPUTER_NAME_FORMAT type, LPWSTR name, LPDWORD size) /* ../dlls/kernel32/computername.c:477 */
{
	BOOL return_value;
	TRACE("Enter GetComputerNameExW\n");
	return_value = pGetComputerNameExW(type, name, size);
	TRACE("Leave GetComputerNameExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetComputerNameW(LPWSTR name, LPDWORD size) /* ../dlls/kernel32/computername.c:313 */
{
	BOOL return_value;
	TRACE("Enter GetComputerNameW\n");
	return_value = pGetComputerNameW(name, size);
	TRACE("Leave GetComputerNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleAliasExesLengthA(void) /* ../dlls/kernel32/console.c:1574 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleAliasExesLengthA\n");
	return_value = pGetConsoleAliasExesLengthA();
	TRACE("Leave GetConsoleAliasExesLengthA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleAliasExesLengthW(void) /* ../dlls/kernel32/console.c:1581 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleAliasExesLengthW\n");
	return_value = pGetConsoleAliasExesLengthW();
	TRACE("Leave GetConsoleAliasExesLengthW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleAliasW(LPWSTR lpSource, LPWSTR lpTargetBuffer, DWORD TargetBufferLength, LPWSTR lpExename) /* ../dlls/kernel32/console.c:1408 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleAliasW\n");
	return_value = pGetConsoleAliasW(lpSource, lpTargetBuffer, TargetBufferLength, lpExename);
	TRACE("Leave GetConsoleAliasW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleAliasesLengthA(LPSTR unknown) /* ../dlls/kernel32/console.c:1560 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleAliasesLengthA\n");
	return_value = pGetConsoleAliasesLengthA(unknown);
	TRACE("Leave GetConsoleAliasesLengthA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleAliasesLengthW(LPWSTR unknown) /* ../dlls/kernel32/console.c:1567 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleAliasesLengthW\n");
	return_value = pGetConsoleAliasesLengthW(unknown);
	TRACE("Leave GetConsoleAliasesLengthW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryA(DWORD unknown1, DWORD unknown2, DWORD unknown3) /* ../dlls/kernel32/console.c:1526 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleCommandHistoryA\n");
	return_value = pGetConsoleCommandHistoryA(unknown1, unknown2, unknown3);
	TRACE("Leave GetConsoleCommandHistoryA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryLengthA(LPCSTR unknown) /* ../dlls/kernel32/console.c:1544 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleCommandHistoryLengthA\n");
	return_value = pGetConsoleCommandHistoryLengthA(unknown);
	TRACE("Leave GetConsoleCommandHistoryLengthA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryLengthW(LPCWSTR unknown) /* ../dlls/kernel32/console.c:1553 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleCommandHistoryLengthW\n");
	return_value = pGetConsoleCommandHistoryLengthW(unknown);
	TRACE("Leave GetConsoleCommandHistoryLengthW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleCommandHistoryW(DWORD unknown1, DWORD unknown2, DWORD unknown3) /* ../dlls/kernel32/console.c:1535 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleCommandHistoryW\n");
	return_value = pGetConsoleCommandHistoryW(unknown1, unknown2, unknown3);
	TRACE("Leave GetConsoleCommandHistoryW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetConsoleDisplayMode(LPDWORD lpModeFlags) /* ../dlls/kernel32/console.c:1283 */
{
	BOOL return_value;
	TRACE("Enter GetConsoleDisplayMode\n");
	return_value = pGetConsoleDisplayMode(lpModeFlags);
	TRACE("Leave GetConsoleDisplayMode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetConsoleFontInfo(HANDLE hConsole, BOOL maximize, DWORD numfonts, CONSOLE_FONT_INFO* info) /* ../dlls/kernel32/console.c:1711 */
{
	BOOL return_value;
	TRACE("Enter GetConsoleFontInfo\n");
	return_value = pGetConsoleFontInfo(hConsole, maximize, numfonts, info);
	TRACE("Leave GetConsoleFontInfo\n");
	return return_value;
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

WINAPI COORD wine32b_kernel32_GetConsoleFontSize(HANDLE hConsole, DWORD index) /* ../dlls/kernel32/console.c:1705 */
{
	COORD return_value;
	TRACE("Enter GetConsoleFontSize\n");
	return_value = pGetConsoleFontSize(hConsole, index);
	TRACE("Leave GetConsoleFontSize\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_GetConsoleInputWaitHandle(void) /* ../dlls/kernel32/console.c:306 */
{
	HANDLE return_value;
	TRACE("Enter GetConsoleInputWaitHandle\n");
	return_value = pGetConsoleInputWaitHandle();
	TRACE("Leave GetConsoleInputWaitHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetConsoleKeyboardLayoutNameA(LPSTR layoutName) /* ../dlls/kernel32/console.c:495 */
{
	BOOL return_value;
	TRACE("Enter GetConsoleKeyboardLayoutNameA\n");
	return_value = pGetConsoleKeyboardLayoutNameA(layoutName);
	TRACE("Leave GetConsoleKeyboardLayoutNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetConsoleKeyboardLayoutNameW(LPWSTR layoutName) /* ../dlls/kernel32/console.c:504 */
{
	BOOL return_value;
	TRACE("Enter GetConsoleKeyboardLayoutNameW\n");
	return_value = pGetConsoleKeyboardLayoutNameW(layoutName);
	TRACE("Leave GetConsoleKeyboardLayoutNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleProcessList(LPDWORD processlist, DWORD processcount) /* ../dlls/kernel32/console.c:1419 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleProcessList\n");
	return_value = pGetConsoleProcessList(processlist, processcount);
	TRACE("Leave GetConsoleProcessList\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetConsoleTitleA(LPSTR title, DWORD size) /* ../dlls/kernel32/console.c:517 */
{
	DWORD return_value;
	TRACE("Enter GetConsoleTitleA\n");
	return_value = pGetConsoleTitleA(title, size);
	TRACE("Leave GetConsoleTitleA\n");
	return return_value;
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

WINAPI HWND wine32b_kernel32_GetConsoleWindow(void) /* ../dlls/kernel32/console.c:179 */
{
	HWND return_value;
	TRACE("Enter GetConsoleWindow\n");
	return_value = pGetConsoleWindow();
	TRACE("Leave GetConsoleWindow\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetCurrencyFormatA(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, CURRENCYFMTA* lpFormat, LPSTR lpCurrencyStr, int cchOut) /* ../dlls/kernel32/lcformat.c:1393 */
{
	INT return_value;
	TRACE("Enter GetCurrencyFormatA\n");
	return_value = pGetCurrencyFormatA(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
	TRACE("Leave GetCurrencyFormatA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetCurrencyFormatEx(LPCWSTR localename, DWORD flags, LPCWSTR value, CURRENCYFMTW* format, LPWSTR str, int len) /* ../dlls/kernel32/lcformat.c:1762 */
{
	INT return_value;
	TRACE("Enter GetCurrencyFormatEx\n");
	return_value = pGetCurrencyFormatEx(localename, flags, value, format, str, len);
	TRACE("Leave GetCurrencyFormatEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetCurrencyFormatW(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, CURRENCYFMTW* lpFormat, LPWSTR lpCurrencyStr, int cchOut) /* ../dlls/kernel32/lcformat.c:1475 */
{
	INT return_value;
	TRACE("Enter GetCurrencyFormatW\n");
	return_value = pGetCurrencyFormatW(lcid, dwFlags, lpszValue, lpFormat, lpCurrencyStr, cchOut);
	TRACE("Leave GetCurrencyFormatW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetCurrentConsoleFont(HANDLE hConsole, BOOL maxwindow, LPCONSOLE_FONT_INFO fontinfo) /* ../dlls/kernel32/console.c:1642 */
{
	BOOL return_value;
	TRACE("Enter GetCurrentConsoleFont\n");
	return_value = pGetCurrentConsoleFont(hConsole, maxwindow, fontinfo);
	TRACE("Leave GetCurrentConsoleFont\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetCurrentDirectoryA(UINT buflen, LPSTR buf) /* ../dlls/kernel32/path.c:1701 */
{
	UINT return_value;
	TRACE("Enter GetCurrentDirectoryA\n");
	return_value = pGetCurrentDirectoryA(buflen, buf);
	TRACE("Leave GetCurrentDirectoryA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetCurrentDirectoryW(UINT buflen, LPWSTR buf) /* ../dlls/kernel32/path.c:1692 */
{
	UINT return_value;
	TRACE("Enter GetCurrentDirectoryW\n");
	return_value = pGetCurrentDirectoryW(buflen, buf);
	TRACE("Leave GetCurrentDirectoryW\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32_GetCurrentPackageFamilyName(UINT32* length, PWSTR name) /* ../dlls/kernel32/version.c:140 */
{
	LONG return_value;
	TRACE("Enter GetCurrentPackageFamilyName\n");
	return_value = pGetCurrentPackageFamilyName(length, name);
	TRACE("Leave GetCurrentPackageFamilyName\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32_GetCurrentPackageFullName(UINT32* length, PWSTR name) /* ../dlls/kernel32/version.c:149 */
{
	LONG return_value;
	TRACE("Enter GetCurrentPackageFullName\n");
	return_value = pGetCurrentPackageFullName(length, name);
	TRACE("Leave GetCurrentPackageFullName\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32_GetCurrentPackageId(UINT32* len, BYTE* buffer) /* ../dlls/kernel32/version.c:131 */
{
	LONG return_value;
	TRACE("Enter GetCurrentPackageId\n");
	return_value = pGetCurrentPackageId(len, buffer);
	TRACE("Leave GetCurrentPackageId\n");
	return return_value;
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

WINAPI PUMS_CONTEXT wine32b_kernel32_GetCurrentUmsThread(void) /* ../dlls/kernel32/process.c:4196 */
{
	PUMS_CONTEXT return_value;
	TRACE("Enter GetCurrentUmsThread\n");
	return_value = pGetCurrentUmsThread();
	TRACE("Leave GetCurrentUmsThread\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetDateFormatA(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpDateStr, INT cchOut) /* ../dlls/kernel32/lcformat.c:839 */
{
	INT return_value;
	TRACE("Enter GetDateFormatA\n");
	return_value = pGetDateFormatA(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
	TRACE("Leave GetDateFormatA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetDateFormatEx(LPCWSTR localename, DWORD flags, SYSTEMTIME* date, LPCWSTR format, LPWSTR outbuf, INT bufsize, LPCWSTR calendar) /* ../dlls/kernel32/lcformat.c:870 */
{
	INT return_value;
	TRACE("Enter GetDateFormatEx\n");
	return_value = pGetDateFormatEx(localename, flags, date, format, outbuf, bufsize, calendar);
	TRACE("Leave GetDateFormatEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetDateFormatW(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCWSTR lpFormat, LPWSTR lpDateStr, INT cchOut) /* ../dlls/kernel32/lcformat.c:894 */
{
	INT return_value;
	TRACE("Enter GetDateFormatW\n");
	return_value = pGetDateFormatW(lcid, dwFlags, lpTime, lpFormat, lpDateStr, cchOut);
	TRACE("Leave GetDateFormatW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDaylightFlag(void) /* ../dlls/kernel32/time.c:1346 */
{
	BOOL return_value;
	TRACE("Enter GetDaylightFlag\n");
	return_value = pGetDaylightFlag();
	TRACE("Leave GetDaylightFlag\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDefaultCommConfigA(LPCSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize) /* ../dlls/kernel32/comm.c:730 */
{
	BOOL return_value;
	TRACE("Enter GetDefaultCommConfigA\n");
	return_value = pGetDefaultCommConfigA(lpszName, lpCC, lpdwSize);
	TRACE("Leave GetDefaultCommConfigA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDefaultCommConfigW(LPCWSTR lpszName, LPCOMMCONFIG lpCC, LPDWORD lpdwSize) /* ../dlls/kernel32/comm.c:694 */
{
	BOOL return_value;
	TRACE("Enter GetDefaultCommConfigW\n");
	return_value = pGetDefaultCommConfigW(lpszName, lpCC, lpdwSize);
	TRACE("Leave GetDefaultCommConfigW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDevicePowerState(HANDLE hDevice, BOOL* pfOn) /* ../dlls/kernel32/powermgnt.c:37 */
{
	BOOL return_value;
	TRACE("Enter GetDevicePowerState\n");
	return_value = pGetDevicePowerState(hDevice, pfOn);
	TRACE("Leave GetDevicePowerState\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceA(LPCSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters) /* ../dlls/kernel32/volume.c:1625 */
{
	BOOL return_value;
	TRACE("Enter GetDiskFreeSpaceA\n");
	return_value = pGetDiskFreeSpaceA(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
	TRACE("Leave GetDiskFreeSpaceA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceExA(LPCSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree) /* ../dlls/kernel32/volume.c:1559 */
{
	BOOL return_value;
	TRACE("Enter GetDiskFreeSpaceExA\n");
	return_value = pGetDiskFreeSpaceExA(root, avail, total, totalfree);
	TRACE("Leave GetDiskFreeSpaceExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceExW(LPCWSTR root, PULARGE_INTEGER avail, PULARGE_INTEGER total, PULARGE_INTEGER totalfree) /* ../dlls/kernel32/volume.c:1524 */
{
	BOOL return_value;
	TRACE("Enter GetDiskFreeSpaceExW\n");
	return_value = pGetDiskFreeSpaceExW(root, avail, total, totalfree);
	TRACE("Leave GetDiskFreeSpaceExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetDiskFreeSpaceW(LPCWSTR root, LPDWORD cluster_sectors, LPDWORD sector_bytes, LPDWORD free_clusters, LPDWORD total_clusters) /* ../dlls/kernel32/volume.c:1572 */
{
	BOOL return_value;
	TRACE("Enter GetDiskFreeSpaceW\n");
	return_value = pGetDiskFreeSpaceW(root, cluster_sectors, sector_bytes, free_clusters, total_clusters);
	TRACE("Leave GetDiskFreeSpaceW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetDllDirectoryA(DWORD buf_len, LPSTR buffer) /* ../dlls/kernel32/module.c:83 */
{
	DWORD return_value;
	TRACE("Enter GetDllDirectoryA\n");
	return_value = pGetDllDirectoryA(buf_len, buffer);
	TRACE("Leave GetDllDirectoryA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetDllDirectoryW(DWORD buf_len, LPWSTR buffer) /* ../dlls/kernel32/module.c:107 */
{
	DWORD return_value;
	TRACE("Enter GetDllDirectoryW\n");
	return_value = pGetDllDirectoryW(buf_len, buffer);
	TRACE("Leave GetDllDirectoryW\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetDriveTypeA(LPCSTR root) /* ../dlls/kernel32/volume.c:1503 */
{
	UINT return_value;
	TRACE("Enter GetDriveTypeA\n");
	return_value = pGetDriveTypeA(root);
	TRACE("Leave GetDriveTypeA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetDriveTypeW(LPCWSTR root) /* ../dlls/kernel32/volume.c:1451 */
{
	UINT return_value;
	TRACE("Enter GetDriveTypeW\n");
	return_value = pGetDriveTypeW(root);
	TRACE("Leave GetDriveTypeW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetDynamicTimeZoneInformation(DYNAMIC_TIME_ZONE_INFORMATION* tzinfo) /* ../dlls/kernel32/time.c:1496 */
{
	DWORD return_value;
	TRACE("Enter GetDynamicTimeZoneInformation\n");
	return_value = pGetDynamicTimeZoneInformation(tzinfo);
	TRACE("Leave GetDynamicTimeZoneInformation\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetDynamicTimeZoneInformationEffectiveYears(DYNAMIC_TIME_ZONE_INFORMATION* tzinfo, DWORD* first_year, DWORD* last_year) /* ../dlls/kernel32/time.c:1521 */
{
	DWORD return_value;
	TRACE("Enter GetDynamicTimeZoneInformationEffectiveYears\n");
	return_value = pGetDynamicTimeZoneInformationEffectiveYears(tzinfo, first_year, last_year);
	TRACE("Leave GetDynamicTimeZoneInformationEffectiveYears\n");
	return return_value;
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

WINAPI DWORD64 wine32b_kernel32_GetEnabledXStateFeatures(void) /* ../dlls/kernel32/cpu.c:287 */
{
	DWORD64 return_value;
	TRACE("Enter GetEnabledXStateFeatures\n");
	return_value = pGetEnabledXStateFeatures();
	TRACE("Leave GetEnabledXStateFeatures\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetExitCodeProcess(HANDLE hProcess, LPDWORD lpExitCode) /* ../dlls/kernel32/process.c:3178 */
{
	BOOL return_value;
	TRACE("Enter GetExitCodeProcess\n");
	return_value = pGetExitCodeProcess(hProcess, lpExitCode);
	TRACE("Leave GetExitCodeProcess\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetExpandedNameA(LPSTR in, LPSTR out) /* ../dlls/kernel32/lzexpand.c:240 */
{
	INT return_value;
	TRACE("Enter GetExpandedNameA\n");
	return_value = pGetExpandedNameA(in, out);
	TRACE("Leave GetExpandedNameA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetExpandedNameW(LPWSTR in, LPWSTR out) /* ../dlls/kernel32/lzexpand.c:310 */
{
	INT return_value;
	TRACE("Enter GetExpandedNameW\n");
	return_value = pGetExpandedNameW(in, out);
	TRACE("Leave GetExpandedNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetFileMUIInfo(DWORD flags, PCWSTR path, FILEMUIINFO* info, DWORD* size) /* ../dlls/kernel32/locale.c:5886 */
{
	BOOL return_value;
	TRACE("Enter GetFileMUIInfo\n");
	return_value = pGetFileMUIInfo(flags, path, info, size);
	TRACE("Leave GetFileMUIInfo\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetFileMUIPath(DWORD flags, PCWSTR filepath, PWSTR language, PULONG languagelen, PWSTR muipath, PULONG muipathlen, PULONGLONG enumerator) /* ../dlls/kernel32/locale.c:5871 */
{
	BOOL return_value;
	TRACE("Enter GetFileMUIPath\n");
	return_value = pGetFileMUIPath(flags, filepath, language, languagelen, muipath, muipathlen, enumerator);
	TRACE("Leave GetFileMUIPath\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFinalPathNameByHandleA(HANDLE file, LPSTR path, DWORD charcount, DWORD flags) /* ../dlls/kernel32/file.c:1494 */
{
	DWORD return_value;
	TRACE("Enter GetFinalPathNameByHandleA\n");
	return_value = pGetFinalPathNameByHandleA(file, path, charcount, flags);
	TRACE("Leave GetFinalPathNameByHandleA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFinalPathNameByHandleW(HANDLE file, LPWSTR path, DWORD charcount, DWORD flags) /* ../dlls/kernel32/file.c:1341 */
{
	DWORD return_value;
	TRACE("Enter GetFinalPathNameByHandleW\n");
	return_value = pGetFinalPathNameByHandleW(file, path, charcount, flags);
	TRACE("Leave GetFinalPathNameByHandleW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFirmwareEnvironmentVariableA(LPCSTR name, LPCSTR guid, PVOID buffer, DWORD size) /* ../dlls/kernel32/environ.c:100 */
{
	DWORD return_value;
	TRACE("Enter GetFirmwareEnvironmentVariableA\n");
	return_value = pGetFirmwareEnvironmentVariableA(name, guid, buffer, size);
	TRACE("Leave GetFirmwareEnvironmentVariableA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFirmwareEnvironmentVariableW(LPCWSTR name, LPCWSTR guid, PVOID buffer, DWORD size) /* ../dlls/kernel32/environ.c:110 */
{
	DWORD return_value;
	TRACE("Enter GetFirmwareEnvironmentVariableW\n");
	return_value = pGetFirmwareEnvironmentVariableW(name, guid, buffer, size);
	TRACE("Leave GetFirmwareEnvironmentVariableW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFullPathNameA(LPCSTR name, DWORD len, LPSTR buffer, LPSTR* lastpart) /* ../dlls/kernel32/path.c:252 */
{
	DWORD return_value;
	TRACE("Enter GetFullPathNameA\n");
	return_value = pGetFullPathNameA(name, len, buffer, lastpart);
	TRACE("Leave GetFullPathNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetFullPathNameW(LPCWSTR name, DWORD len, LPWSTR buffer, LPWSTR* lastpart) /* ../dlls/kernel32/path.c:241 */
{
	DWORD return_value;
	TRACE("Enter GetFullPathNameW\n");
	return_value = pGetFullPathNameW(name, len, buffer, lastpart);
	TRACE("Leave GetFullPathNameW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetGeoInfoA(GEOID geoid, GEOTYPE geotype, LPSTR data, int data_len, LANGID lang) /* ../dlls/kernel32/locale.c:5184 */
{
	INT return_value;
	TRACE("Enter GetGeoInfoA\n");
	return_value = pGetGeoInfoA(geoid, geotype, data, data_len, lang);
	TRACE("Leave GetGeoInfoA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetGeoInfoW(GEOID geoid, GEOTYPE geotype, LPWSTR data, int data_len, LANGID lang) /* ../dlls/kernel32/locale.c:5117 */
{
	INT return_value;
	TRACE("Enter GetGeoInfoW\n");
	return_value = pGetGeoInfoW(geoid, geotype, data, data_len, lang);
	TRACE("Leave GetGeoInfoW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetHandleContext(HANDLE hnd) /* ../dlls/kernel32/process.c:3362 */
{
	DWORD return_value;
	TRACE("Enter GetHandleContext\n");
	return_value = pGetHandleContext(hnd);
	TRACE("Leave GetHandleContext\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetHandleInformation(HANDLE handle, LPDWORD flags) /* ../dlls/kernel32/process.c:3262 */
{
	BOOL return_value;
	TRACE("Enter GetHandleInformation\n");
	return_value = pGetHandleInformation(handle, flags);
	TRACE("Leave GetHandleInformation\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_GetLargePageMinimum(void) /* ../dlls/kernel32/cpu.c:236 */
{
	SIZE_T return_value;
	TRACE("Enter GetLargePageMinimum\n");
	return_value = pGetLargePageMinimum();
	TRACE("Leave GetLargePageMinimum\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetLocalTime(LPSYSTEMTIME systime) /* ../dlls/kernel32/time.c:1300 */
{
	TRACE("Enter GetLocalTime\n");
	pGetLocalTime(systime);
	TRACE("Leave GetLocalTime\n");
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

WINAPI INT wine32b_kernel32_GetLocaleInfoA(LCID lcid, LCTYPE lctype, LPSTR buffer, INT len) /* ../dlls/kernel32/locale.c:1612 */
{
	INT return_value;
	TRACE("Enter GetLocaleInfoA\n");
	return_value = pGetLocaleInfoA(lcid, lctype, buffer, len);
	TRACE("Leave GetLocaleInfoA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetLocaleInfoEx(LPCWSTR locale, LCTYPE info, LPWSTR buffer, INT len) /* ../dlls/kernel32/locale.c:1824 */
{
	INT return_value;
	TRACE("Enter GetLocaleInfoEx\n");
	return_value = pGetLocaleInfoEx(locale, info, buffer, len);
	TRACE("Leave GetLocaleInfoEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetLocaleInfoW(LCID lcid, LCTYPE lctype, LPWSTR buffer, INT len) /* ../dlls/kernel32/locale.c:1678 */
{
	INT return_value;
	TRACE("Enter GetLocaleInfoW\n");
	return_value = pGetLocaleInfoW(lcid, lctype, buffer, len);
	TRACE("Leave GetLocaleInfoW\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetLogicalDriveStringsA(UINT len, LPSTR buffer) /* ../dlls/kernel32/volume.c:1384 */
{
	UINT return_value;
	TRACE("Enter GetLogicalDriveStringsA\n");
	return_value = pGetLogicalDriveStringsA(len, buffer);
	TRACE("Leave GetLogicalDriveStringsA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetLogicalDriveStringsW(UINT len, LPWSTR buffer) /* ../dlls/kernel32/volume.c:1410 */
{
	UINT return_value;
	TRACE("Enter GetLogicalDriveStringsW\n");
	return_value = pGetLogicalDriveStringsW(len, buffer);
	TRACE("Leave GetLogicalDriveStringsW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetLogicalDrives(void) /* ../dlls/kernel32/volume.c:1346 */
{
	DWORD return_value;
	TRACE("Enter GetLogicalDrives\n");
	return_value = pGetLogicalDrives();
	TRACE("Leave GetLogicalDrives\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION buffer, PDWORD pBufLen) /* ../dlls/kernel32/process.c:3819 */
{
	BOOL return_value;
	TRACE("Enter GetLogicalProcessorInformation\n");
	return_value = pGetLogicalProcessorInformation(buffer, pBufLen);
	TRACE("Leave GetLogicalProcessorInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetLogicalProcessorInformationEx(LOGICAL_PROCESSOR_RELATIONSHIP relationship, SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX* buffer, DWORD* len) /* ../dlls/kernel32/process.c:3849 */
{
	BOOL return_value;
	TRACE("Enter GetLogicalProcessorInformationEx\n");
	return_value = pGetLogicalProcessorInformationEx(relationship, buffer, len);
	TRACE("Leave GetLogicalProcessorInformationEx\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetLongPathNameA(LPCSTR shortpath, LPSTR longpath, DWORD longlen) /* ../dlls/kernel32/path.c:405 */
{
	DWORD return_value;
	TRACE("Enter GetLongPathNameA\n");
	return_value = pGetLongPathNameA(shortpath, longpath, longlen);
	TRACE("Leave GetLongPathNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetLongPathNameW(LPCWSTR shortpath, LPWSTR longpath, DWORD longlen) /* ../dlls/kernel32/path.c:289 */
{
	DWORD return_value;
	TRACE("Enter GetLongPathNameW\n");
	return_value = pGetLongPathNameW(shortpath, longpath, longlen);
	TRACE("Leave GetLongPathNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetMailslotInfo(HANDLE hMailslot, LPDWORD lpMaxMessageSize, LPDWORD lpNextSize, LPDWORD lpMessageCount, LPDWORD lpReadTimeout) /* ../dlls/kernel32/sync.c:923 */
{
	BOOL return_value;
	TRACE("Enter GetMailslotInfo\n");
	return_value = pGetMailslotInfo(hMailslot, lpMaxMessageSize, lpNextSize, lpMessageCount, lpReadTimeout);
	TRACE("Leave GetMailslotInfo\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetMaximumProcessorCount(WORD group) /* ../dlls/kernel32/cpu.c:272 */
{
	DWORD return_value;
	TRACE("Enter GetMaximumProcessorCount\n");
	return_value = pGetMaximumProcessorCount(group);
	TRACE("Leave GetMaximumProcessorCount\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeClientProcessId(HANDLE pipe, ULONG* id) /* ../dlls/kernel32/sync.c:566 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeClientProcessId\n");
	return_value = pGetNamedPipeClientProcessId(pipe, id);
	TRACE("Leave GetNamedPipeClientProcessId\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeClientSessionId(HANDLE pipe, ULONG* id) /* ../dlls/kernel32/sync.c:606 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeClientSessionId\n");
	return_value = pGetNamedPipeClientSessionId(pipe, id);
	TRACE("Leave GetNamedPipeClientSessionId\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeHandleStateA(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPSTR lpUsername, DWORD nUsernameMaxSize) /* ../dlls/kernel32/sync.c:630 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeHandleStateA\n");
	return_value = pGetNamedPipeHandleStateA(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
	TRACE("Leave GetNamedPipeHandleStateA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeHandleStateW(HANDLE hNamedPipe, LPDWORD lpState, LPDWORD lpCurInstances, LPDWORD lpMaxCollectionCount, LPDWORD lpCollectDataTimeout, LPWSTR lpUsername, DWORD nUsernameMaxSize) /* ../dlls/kernel32/sync.c:656 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeHandleStateW\n");
	return_value = pGetNamedPipeHandleStateW(hNamedPipe, lpState, lpCurInstances, lpMaxCollectionCount, lpCollectDataTimeout, lpUsername, nUsernameMaxSize);
	TRACE("Leave GetNamedPipeHandleStateW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeServerProcessId(HANDLE pipe, ULONG* id) /* ../dlls/kernel32/sync.c:586 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeServerProcessId\n");
	return_value = pGetNamedPipeServerProcessId(pipe, id);
	TRACE("Leave GetNamedPipeServerProcessId\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNamedPipeServerSessionId(HANDLE pipe, ULONG* id) /* ../dlls/kernel32/sync.c:618 */
{
	BOOL return_value;
	TRACE("Enter GetNamedPipeServerSessionId\n");
	return_value = pGetNamedPipeServerSessionId(pipe, id);
	TRACE("Leave GetNamedPipeServerSessionId\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetNativeSystemInfo(LPSYSTEM_INFO si) /* ../dlls/kernel32/cpu.c:129 */
{
	TRACE("Enter GetNativeSystemInfo\n");
	pGetNativeSystemInfo(si);
	TRACE("Leave GetNativeSystemInfo\n");
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

WINAPI PUMS_CONTEXT wine32b_kernel32_GetNextUmsListItem(PUMS_CONTEXT ctx) /* ../dlls/kernel32/process.c:4206 */
{
	PUMS_CONTEXT return_value;
	TRACE("Enter GetNextUmsListItem\n");
	return_value = pGetNextUmsListItem(ctx);
	TRACE("Leave GetNextUmsListItem\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaAvailableMemoryNode(UCHAR node, PULONGLONG available_bytes) /* ../dlls/kernel32/process.c:4005 */
{
	BOOL return_value;
	TRACE("Enter GetNumaAvailableMemoryNode\n");
	return_value = pGetNumaAvailableMemoryNode(node, available_bytes);
	TRACE("Leave GetNumaAvailableMemoryNode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaAvailableMemoryNodeEx(USHORT node, PULONGLONG available_bytes) /* ../dlls/kernel32/process.c:4015 */
{
	BOOL return_value;
	TRACE("Enter GetNumaAvailableMemoryNodeEx\n");
	return_value = pGetNumaAvailableMemoryNodeEx(node, available_bytes);
	TRACE("Leave GetNumaAvailableMemoryNodeEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaHighestNodeNumber(PULONG highestnode) /* ../dlls/kernel32/process.c:3975 */
{
	BOOL return_value;
	TRACE("Enter GetNumaHighestNodeNumber\n");
	return_value = pGetNumaHighestNodeNumber(highestnode);
	TRACE("Leave GetNumaHighestNodeNumber\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaNodeProcessorMask(UCHAR node, PULONGLONG mask) /* ../dlls/kernel32/process.c:3985 */
{
	BOOL return_value;
	TRACE("Enter GetNumaNodeProcessorMask\n");
	return_value = pGetNumaNodeProcessorMask(node, mask);
	TRACE("Leave GetNumaNodeProcessorMask\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaNodeProcessorMaskEx(USHORT node, PGROUP_AFFINITY mask) /* ../dlls/kernel32/process.c:3995 */
{
	BOOL return_value;
	TRACE("Enter GetNumaNodeProcessorMaskEx\n");
	return_value = pGetNumaNodeProcessorMaskEx(node, mask);
	TRACE("Leave GetNumaNodeProcessorMaskEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaProcessorNode(UCHAR processor, PUCHAR node) /* ../dlls/kernel32/process.c:4025 */
{
	BOOL return_value;
	TRACE("Enter GetNumaProcessorNode\n");
	return_value = pGetNumaProcessorNode(processor, node);
	TRACE("Leave GetNumaProcessorNode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaProcessorNodeEx(PPROCESSOR_NUMBER processor, PUSHORT node_number) /* ../dlls/kernel32/process.c:4046 */
{
	BOOL return_value;
	TRACE("Enter GetNumaProcessorNodeEx\n");
	return_value = pGetNumaProcessorNodeEx(processor, node_number);
	TRACE("Leave GetNumaProcessorNodeEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaProximityNode(ULONG proximity_id, PUCHAR node_number) /* ../dlls/kernel32/process.c:4055 */
{
	BOOL return_value;
	TRACE("Enter GetNumaProximityNode\n");
	return_value = pGetNumaProximityNode(proximity_id, node_number);
	TRACE("Leave GetNumaProximityNode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumaProximityNodeEx(ULONG proximity_id, PUSHORT node_number) /* ../dlls/kernel32/process.c:4064 */
{
	BOOL return_value;
	TRACE("Enter GetNumaProximityNodeEx\n");
	return_value = pGetNumaProximityNodeEx(proximity_id, node_number);
	TRACE("Leave GetNumaProximityNodeEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetNumberFormatA(LCID lcid, DWORD dwFlags, LPCSTR lpszValue, NUMBERFMTA* lpFormat, LPSTR lpNumberStr, int cchOut) /* ../dlls/kernel32/lcformat.c:1029 */
{
	INT return_value;
	TRACE("Enter GetNumberFormatA\n");
	return_value = pGetNumberFormatA(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
	TRACE("Leave GetNumberFormatA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetNumberFormatEx(LPCWSTR name, DWORD flags, LPCWSTR value, NUMBERFMTW* format, LPWSTR number, int numout) /* ../dlls/kernel32/lcformat.c:1350 */
{
	INT return_value;
	TRACE("Enter GetNumberFormatEx\n");
	return_value = pGetNumberFormatEx(name, flags, value, format, number, numout);
	TRACE("Leave GetNumberFormatEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetNumberFormatW(LCID lcid, DWORD dwFlags, LPCWSTR lpszValue, NUMBERFMTW* lpFormat, LPWSTR lpNumberStr, int cchOut) /* ../dlls/kernel32/lcformat.c:1111 */
{
	INT return_value;
	TRACE("Enter GetNumberFormatW\n");
	return_value = pGetNumberFormatW(lcid, dwFlags, lpszValue, lpFormat, lpNumberStr, cchOut);
	TRACE("Leave GetNumberFormatW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetNumberOfConsoleFonts(void) /* ../dlls/kernel32/console.c:1622 */
{
	DWORD return_value;
	TRACE("Enter GetNumberOfConsoleFonts\n");
	return_value = pGetNumberOfConsoleFonts();
	TRACE("Leave GetNumberOfConsoleFonts\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetNumberOfConsoleMouseButtons(LPDWORD nrofbuttons) /* ../dlls/kernel32/console.c:832 */
{
	BOOL return_value;
	TRACE("Enter GetNumberOfConsoleMouseButtons\n");
	return_value = pGetNumberOfConsoleMouseButtons(nrofbuttons);
	TRACE("Leave GetNumberOfConsoleMouseButtons\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetOEMCP(void) /* ../dlls/kernel32/locale.c:2048 */
{
	UINT return_value;
	TRACE("Enter GetOEMCP\n");
	return_value = pGetOEMCP();
	TRACE("Leave GetOEMCP\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32_GetPackageFullName(HANDLE process, UINT32* length, PWSTR name) /* ../dlls/kernel32/version.c:158 */
{
	LONG return_value;
	TRACE("Enter GetPackageFullName\n");
	return_value = pGetPackageFullName(process, length, name);
	TRACE("Leave GetPackageFullName\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetPhysicallyInstalledSystemMemory(ULONGLONG* total_memory) /* ../dlls/kernel32/heap.c:897 */
{
	BOOL return_value;
	TRACE("Enter GetPhysicallyInstalledSystemMemory\n");
	return_value = pGetPhysicallyInstalledSystemMemory(total_memory);
	TRACE("Leave GetPhysicallyInstalledSystemMemory\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetPrivateProfileIntA(LPCSTR section, LPCSTR entry, INT def_val, LPCSTR filename) /* ../dlls/kernel32/profile.c:1254 */
{
	UINT return_value;
	TRACE("Enter GetPrivateProfileIntA\n");
	return_value = pGetPrivateProfileIntA(section, entry, def_val, filename);
	TRACE("Leave GetPrivateProfileIntA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetPrivateProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1226 */
{
	UINT return_value;
	TRACE("Enter GetPrivateProfileIntW\n");
	return_value = pGetPrivateProfileIntW(section, entry, def_val, filename);
	TRACE("Leave GetPrivateProfileIntW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetPrivateProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len, LPCSTR filename) /* ../dlls/kernel32/profile.c:1302 */
{
	INT return_value;
	TRACE("Enter GetPrivateProfileSectionA\n");
	return_value = pGetPrivateProfileSectionA(section, buffer, len, filename);
	TRACE("Leave GetPrivateProfileSectionA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetPrivateProfileSectionNamesA(LPSTR buffer, DWORD size, LPCSTR filename) /* ../dlls/kernel32/profile.c:1572 */
{
	DWORD return_value;
	TRACE("Enter GetPrivateProfileSectionNamesA\n");
	return_value = pGetPrivateProfileSectionNamesA(buffer, size, filename);
	TRACE("Leave GetPrivateProfileSectionNamesA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetPrivateProfileSectionNamesW(LPWSTR buffer, DWORD size, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1553 */
{
	DWORD return_value;
	TRACE("Enter GetPrivateProfileSectionNamesW\n");
	return_value = pGetPrivateProfileSectionNamesW(buffer, size, filename);
	TRACE("Leave GetPrivateProfileSectionNamesW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetPrivateProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1276 */
{
	INT return_value;
	TRACE("Enter GetPrivateProfileSectionW\n");
	return_value = pGetPrivateProfileSectionW(section, buffer, len, filename);
	TRACE("Leave GetPrivateProfileSectionW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetPrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len, LPCSTR filename) /* ../dlls/kernel32/profile.c:1144 */
{
	INT return_value;
	TRACE("Enter GetPrivateProfileStringA\n");
	return_value = pGetPrivateProfileStringA(section, entry, def_val, buffer, len, filename);
	TRACE("Leave GetPrivateProfileStringA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetPrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1088 */
{
	INT return_value;
	TRACE("Enter GetPrivateProfileStringW\n");
	return_value = pGetPrivateProfileStringW(section, entry, def_val, buffer, len, filename);
	TRACE("Leave GetPrivateProfileStringW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetPrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buffer, UINT len, LPCSTR filename) /* ../dlls/kernel32/profile.c:1681 */
{
	BOOL return_value;
	TRACE("Enter GetPrivateProfileStructA\n");
	return_value = pGetPrivateProfileStructA(section, key, buffer, len, filename);
	TRACE("Leave GetPrivateProfileStructA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetPrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT len, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1608 */
{
	BOOL return_value;
	TRACE("Enter GetPrivateProfileStructW\n");
	return_value = pGetPrivateProfileStructW(section, key, buf, len, filename);
	TRACE("Leave GetPrivateProfileStructW\n");
	return return_value;
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

WINAPI FARPROC wine32b_kernel32_GetProcAddress(HMODULE hModule, LPCSTR function) /* ../dlls/kernel32/module.c:1016 */
{
	FARPROC return_value;
	TRACE("Enter GetProcAddress\n");
	return_value = pGetProcAddress(hModule, function);
	return_value = wine_make_thunk_function_alloc(return_value);
	TRACE("Leave GetProcAddress\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessAffinityMask(HANDLE hProcess, PDWORD_PTR process_mask, PDWORD_PTR system_mask) /* ../dlls/kernel32/process.c:3404 */
{
	BOOL return_value;
	TRACE("Enter GetProcessAffinityMask\n");
	return_value = pGetProcessAffinityMask(hProcess, process_mask, system_mask);
	TRACE("Leave GetProcessAffinityMask\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessDEPPolicy(HANDLE process, LPDWORD flags, PBOOL permanent) /* ../dlls/kernel32/process.c:4073 */
{
	BOOL return_value;
	TRACE("Enter GetProcessDEPPolicy\n");
	return_value = pGetProcessDEPPolicy(process, flags, permanent);
	TRACE("Leave GetProcessDEPPolicy\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetProcessFlags(DWORD processid) /* ../dlls/kernel32/process.c:3208 */
{
	DWORD return_value;
	TRACE("Enter GetProcessFlags\n");
	return_value = pGetProcessFlags(processid);
	TRACE("Leave GetProcessFlags\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessIoCounters(HANDLE hProcess, PIO_COUNTERS ioc) /* ../dlls/kernel32/process.c:3521 */
{
	BOOL return_value;
	TRACE("Enter GetProcessIoCounters\n");
	return_value = pGetProcessIoCounters(hProcess, ioc);
	TRACE("Leave GetProcessIoCounters\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessPreferredUILanguages(DWORD flags, ULONG* count, WCHAR* buf, ULONG* size) /* ../dlls/kernel32/locale.c:1291 */
{
	BOOL return_value;
	TRACE("Enter GetProcessPreferredUILanguages\n");
	return_value = pGetProcessPreferredUILanguages(flags, count, buf, size);
	TRACE("Leave GetProcessPreferredUILanguages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessTimes(HANDLE hprocess, LPFILETIME lpCreationTime, LPFILETIME lpExitTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime) /* ../dlls/kernel32/time.c:890 */
{
	BOOL return_value;
	TRACE("Enter GetProcessTimes\n");
	return_value = pGetProcessTimes(hprocess, lpCreationTime, lpExitTime, lpKernelTime, lpUserTime);
	TRACE("Leave GetProcessTimes\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetProcessVersion(DWORD pid) /* ../dlls/kernel32/process.c:3430 */
{
	DWORD return_value;
	TRACE("Enter GetProcessVersion\n");
	return_value = pGetProcessVersion(pid);
	TRACE("Leave GetProcessVersion\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProcessWorkingSetSize(HANDLE process, SIZE_T* minset, SIZE_T* maxset) /* ../dlls/kernel32/process.c:3512 */
{
	BOOL return_value;
	TRACE("Enter GetProcessWorkingSetSize\n");
	return_value = pGetProcessWorkingSetSize(process, minset, maxset);
	TRACE("Leave GetProcessWorkingSetSize\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetProductInfo(DWORD dwOSMajorVersion, DWORD dwOSMinorVersion, DWORD dwSpMajorVersion, DWORD dwSpMinorVersion, PDWORD pdwReturnedProductType) /* ../dlls/kernel32/version.c:121 */
{
	BOOL return_value;
	TRACE("Enter GetProductInfo\n");
	return_value = pGetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
	TRACE("Leave GetProductInfo\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetProfileIntA(LPCSTR section, LPCSTR entry, INT def_val) /* ../dlls/kernel32/profile.c:1072 */
{
	UINT return_value;
	TRACE("Enter GetProfileIntA\n");
	return_value = pGetProfileIntA(section, entry, def_val);
	TRACE("Leave GetProfileIntA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetProfileIntW(LPCWSTR section, LPCWSTR entry, INT def_val) /* ../dlls/kernel32/profile.c:1080 */
{
	UINT return_value;
	TRACE("Enter GetProfileIntW\n");
	return_value = pGetProfileIntW(section, entry, def_val);
	TRACE("Leave GetProfileIntW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetProfileSectionA(LPCSTR section, LPSTR buffer, DWORD len) /* ../dlls/kernel32/profile.c:1348 */
{
	INT return_value;
	TRACE("Enter GetProfileSectionA\n");
	return_value = pGetProfileSectionA(section, buffer, len);
	TRACE("Leave GetProfileSectionA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetProfileSectionW(LPCWSTR section, LPWSTR buffer, DWORD len) /* ../dlls/kernel32/profile.c:1356 */
{
	INT return_value;
	TRACE("Enter GetProfileSectionW\n");
	return_value = pGetProfileSectionW(section, buffer, len);
	TRACE("Leave GetProfileSectionW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR def_val, LPSTR buffer, UINT len) /* ../dlls/kernel32/profile.c:1187 */
{
	INT return_value;
	TRACE("Enter GetProfileStringA\n");
	return_value = pGetProfileStringA(section, entry, def_val, buffer, len);
	TRACE("Leave GetProfileStringA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR def_val, LPWSTR buffer, UINT len) /* ../dlls/kernel32/profile.c:1197 */
{
	INT return_value;
	TRACE("Enter GetProfileStringW\n");
	return_value = pGetProfileStringW(section, entry, def_val, buffer, len);
	TRACE("Leave GetProfileStringW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetShortPathNameA(LPCSTR longpath, LPSTR shortpath, DWORD shortlen) /* ../dlls/kernel32/path.c:574 */
{
	DWORD return_value;
	TRACE("Enter GetShortPathNameA\n");
	return_value = pGetShortPathNameA(longpath, shortpath, shortlen);
	TRACE("Leave GetShortPathNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetShortPathNameW(LPCWSTR longpath, LPWSTR shortpath, DWORD shortlen) /* ../dlls/kernel32/path.c:447 */
{
	DWORD return_value;
	TRACE("Enter GetShortPathNameW\n");
	return_value = pGetShortPathNameW(longpath, shortpath, shortlen);
	TRACE("Leave GetShortPathNameW\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetStartupInfoA(LPSTARTUPINFOA info) /* ../dlls/kernel32/environ.c:54 */
{
	TRACE("Enter GetStartupInfoA\n");
	pGetStartupInfoA(info);
	TRACE("Leave GetStartupInfoA\n");
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

WINAPI BOOL wine32b_kernel32_GetStringTypeA(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype) /* ../dlls/kernel32/locale.c:3181 */
{
	BOOL return_value;
	TRACE("Enter GetStringTypeA\n");
	return_value = pGetStringTypeA(locale, type, src, count, chartype);
	TRACE("Leave GetStringTypeA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetStringTypeExA(LCID locale, DWORD type, LPCSTR src, INT count, LPWORD chartype) /* ../dlls/kernel32/locale.c:3228 */
{
	BOOL return_value;
	TRACE("Enter GetStringTypeExA\n");
	return_value = pGetStringTypeExA(locale, type, src, count, chartype);
	TRACE("Leave GetStringTypeExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetStringTypeExW(LCID locale, DWORD type, LPCWSTR src, INT count, LPWORD chartype) /* ../dlls/kernel32/locale.c:3157 */
{
	BOOL return_value;
	TRACE("Enter GetStringTypeExW\n");
	return_value = pGetStringTypeExW(locale, type, src, count, chartype);
	TRACE("Leave GetStringTypeExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetStringTypeW(DWORD type, LPCWSTR src, INT count, LPWORD chartype) /* ../dlls/kernel32/locale.c:3087 */
{
	BOOL return_value;
	TRACE("Enter GetStringTypeW\n");
	return_value = pGetStringTypeW(type, src, count, chartype);
	TRACE("Leave GetStringTypeW\n");
	return return_value;
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

WINAPI DEP_SYSTEM_POLICY_TYPE wine32b_kernel32_GetSystemDEPPolicy(void) /* ../dlls/kernel32/process.c:3918 */
{
	DEP_SYSTEM_POLICY_TYPE return_value;
	TRACE("Enter GetSystemDEPPolicy\n");
	return_value = pGetSystemDEPPolicy();
	TRACE("Leave GetSystemDEPPolicy\n");
	return return_value;
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

WINAPI LCID wine32b_kernel32_GetSystemDefaultLCID(void) /* ../dlls/kernel32/locale.c:1226 */
{
	LCID return_value;
	TRACE("Enter GetSystemDefaultLCID\n");
	return_value = pGetSystemDefaultLCID();
	TRACE("Leave GetSystemDefaultLCID\n");
	return return_value;
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

WINAPI LANGID wine32b_kernel32_GetSystemDefaultLangID(void) /* ../dlls/kernel32/locale.c:1190 */
{
	LANGID return_value;
	TRACE("Enter GetSystemDefaultLangID\n");
	return_value = pGetSystemDefaultLangID();
	TRACE("Leave GetSystemDefaultLangID\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetSystemDefaultLocaleName(LPWSTR localename, INT len) /* ../dlls/kernel32/locale.c:1236 */
{
	INT return_value;
	TRACE("Enter GetSystemDefaultLocaleName\n");
	return_value = pGetSystemDefaultLocaleName(localename, len);
	TRACE("Leave GetSystemDefaultLocaleName\n");
	return return_value;
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

WINAPI LANGID wine32b_kernel32_GetSystemDefaultUILanguage(void) /* ../dlls/kernel32/locale.c:1405 */
{
	LANGID return_value;
	TRACE("Enter GetSystemDefaultUILanguage\n");
	return_value = pGetSystemDefaultUILanguage();
	TRACE("Leave GetSystemDefaultUILanguage\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetSystemDirectoryA(LPSTR path, UINT count) /* ../dlls/kernel32/path.c:1782 */
{
	UINT return_value;
	TRACE("Enter GetSystemDirectoryA\n");
	return_value = pGetSystemDirectoryA(path, count);
	TRACE("Leave GetSystemDirectoryA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetSystemDirectoryW(LPWSTR path, UINT count) /* ../dlls/kernel32/path.c:1765 */
{
	UINT return_value;
	TRACE("Enter GetSystemDirectoryW\n");
	return_value = pGetSystemDirectoryW(path, count);
	TRACE("Leave GetSystemDirectoryW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetSystemFileCacheSize(PSIZE_T mincache, PSIZE_T maxcache, PDWORD flags) /* ../dlls/kernel32/heap.c:915 */
{
	BOOL return_value;
	TRACE("Enter GetSystemFileCacheSize\n");
	return_value = pGetSystemFileCacheSize(mincache, maxcache, flags);
	TRACE("Leave GetSystemFileCacheSize\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetSystemFirmwareTable(DWORD provider, DWORD id, void* buffer, DWORD size) /* ../dlls/kernel32/cpu.c:296 */
{
	UINT return_value;
	TRACE("Enter GetSystemFirmwareTable\n");
	return_value = pGetSystemFirmwareTable(provider, id, buffer, size);
	TRACE("Leave GetSystemFirmwareTable\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetSystemInfo(LPSYSTEM_INFO si) /* ../dlls/kernel32/cpu.c:57 */
{
	TRACE("Enter GetSystemInfo\n");
	pGetSystemInfo(si);
	TRACE("Leave GetSystemInfo\n");
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

WINAPI BOOL wine32b_kernel32_GetSystemPowerStatus(LPSYSTEM_POWER_STATUS ps) /* ../dlls/kernel32/powermgnt.c:46 */
{
	BOOL return_value;
	TRACE("Enter GetSystemPowerStatus\n");
	return_value = pGetSystemPowerStatus(ps);
	TRACE("Leave GetSystemPowerStatus\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetSystemPreferredUILanguages(DWORD flags, ULONG* count, WCHAR* buffer, ULONG* size) /* ../dlls/kernel32/locale.c:1300 */
{
	BOOL return_value;
	TRACE("Enter GetSystemPreferredUILanguages\n");
	return_value = pGetSystemPreferredUILanguages(flags, count, buffer, size);
	TRACE("Leave GetSystemPreferredUILanguages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetSystemRegistryQuota(PDWORD pdwQuotaAllowed, PDWORD pdwQuotaUsed) /* ../dlls/kernel32/kernel_main.c:184 */
{
	BOOL return_value;
	TRACE("Enter GetSystemRegistryQuota\n");
	return_value = pGetSystemRegistryQuota(pdwQuotaAllowed, pdwQuotaUsed);
	TRACE("Leave GetSystemRegistryQuota\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetSystemTime(LPSYSTEMTIME systime) /* ../dlls/kernel32/time.c:1323 */
{
	TRACE("Enter GetSystemTime\n");
	pGetSystemTime(systime);
	TRACE("Leave GetSystemTime\n");
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

WINAPI BOOL wine32b_kernel32_GetSystemTimeAdjustment(PDWORD lpTimeAdjustment, PDWORD lpTimeIncrement, PBOOL lpTimeAdjustmentDisabled) /* ../dlls/kernel32/time.c:566 */
{
	BOOL return_value;
	TRACE("Enter GetSystemTimeAdjustment\n");
	return_value = pGetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled);
	TRACE("Leave GetSystemTimeAdjustment\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GetSystemTimePreciseAsFileTime(FILETIME* time) /* ../dlls/kernel32/time.c:798 */
{
	TRACE("Enter GetSystemTimePreciseAsFileTime\n");
	pGetSystemTimePreciseAsFileTime(time);
	TRACE("Leave GetSystemTimePreciseAsFileTime\n");
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

WINAPI BOOL wine32b_kernel32_GetSystemTimes(LPFILETIME lpIdleTime, LPFILETIME lpKernelTime, LPFILETIME lpUserTime) /* ../dlls/kernel32/time.c:1428 */
{
	BOOL return_value;
	TRACE("Enter GetSystemTimes\n");
	return_value = pGetSystemTimes(lpIdleTime, lpKernelTime, lpUserTime);
	TRACE("Leave GetSystemTimes\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetSystemWow64DirectoryA(LPSTR path, UINT count) /* ../dlls/kernel32/path.c:1819 */
{
	UINT return_value;
	TRACE("Enter GetSystemWow64DirectoryA\n");
	return_value = pGetSystemWow64DirectoryA(path, count);
	TRACE("Leave GetSystemWow64DirectoryA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetSystemWow64DirectoryW(LPWSTR path, UINT count) /* ../dlls/kernel32/path.c:1795 */
{
	UINT return_value;
	TRACE("Enter GetSystemWow64DirectoryW\n");
	return_value = pGetSystemWow64DirectoryW(path, count);
	TRACE("Leave GetSystemWow64DirectoryW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTapeParameters(HANDLE device, DWORD operation, LPDWORD size, LPVOID info) /* ../dlls/kernel32/tape.c:144 */
{
	DWORD return_value;
	TRACE("Enter GetTapeParameters\n");
	return_value = pGetTapeParameters(device, operation, size, info);
	TRACE("Leave GetTapeParameters\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTapePosition(HANDLE device, DWORD type, LPDWORD partition, LPDWORD offset_low, LPDWORD offset_high) /* ../dlls/kernel32/tape.c:175 */
{
	DWORD return_value;
	TRACE("Enter GetTapePosition\n");
	return_value = pGetTapePosition(device, type, partition, offset_low, offset_high);
	TRACE("Leave GetTapePosition\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTapeStatus(HANDLE device) /* ../dlls/kernel32/tape.c:208 */
{
	DWORD return_value;
	TRACE("Enter GetTapeStatus\n");
	return_value = pGetTapeStatus(device);
	TRACE("Leave GetTapeStatus\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetTempFileNameA(LPCSTR path, LPCSTR prefix, UINT unique, LPSTR buffer) /* ../dlls/kernel32/path.c:682 */
{
	UINT return_value;
	TRACE("Enter GetTempFileNameA\n");
	return_value = pGetTempFileNameA(path, prefix, unique, buffer);
	TRACE("Leave GetTempFileNameA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GetTempFileNameW(LPCWSTR path, LPCWSTR prefix, UINT unique, LPWSTR buffer) /* ../dlls/kernel32/path.c:701 */
{
	UINT return_value;
	TRACE("Enter GetTempFileNameW\n");
	return_value = pGetTempFileNameW(path, prefix, unique, buffer);
	TRACE("Leave GetTempFileNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTempPathA(DWORD count, LPSTR path) /* ../dlls/kernel32/path.c:599 */
{
	DWORD return_value;
	TRACE("Enter GetTempPathA\n");
	return_value = pGetTempPathA(count, path);
	TRACE("Leave GetTempPathA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTempPathW(DWORD count, LPWSTR path) /* ../dlls/kernel32/path.c:621 */
{
	DWORD return_value;
	TRACE("Enter GetTempPathW\n");
	return_value = pGetTempPathW(count, path);
	TRACE("Leave GetTempPathW\n");
	return return_value;
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

WINAPI LCID wine32b_kernel32_GetThreadLocale(void) /* ../dlls/kernel32/locale.c:2793 */
{
	LCID return_value;
	TRACE("Enter GetThreadLocale\n");
	return_value = pGetThreadLocale();
	TRACE("Leave GetThreadLocale\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetThreadPreferredUILanguages(DWORD flags, ULONG* count, WCHAR* buf, ULONG* size) /* ../dlls/kernel32/locale.c:1342 */
{
	BOOL return_value;
	TRACE("Enter GetThreadPreferredUILanguages\n");
	return_value = pGetThreadPreferredUILanguages(flags, count, buf, size);
	TRACE("Leave GetThreadPreferredUILanguages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetThreadSelectorEntry(HANDLE hthread, DWORD sel, LPLDT_ENTRY ldtent) /* ../dlls/kernel32/thread.c:110 */
{
	BOOL return_value;
	TRACE("Enter GetThreadSelectorEntry\n");
	return_value = pGetThreadSelectorEntry(hthread, sel, ldtent);
	TRACE("Leave GetThreadSelectorEntry\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTickCount(void) /* ../dlls/kernel32/time.c:1584 */
{
	DWORD return_value;
	TRACE("Enter GetTickCount\n");
	return_value = pGetTickCount();
	TRACE("Leave GetTickCount\n");
	return return_value;
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

WINAPI ULONGLONG wine32b_kernel32_GetTickCount64(void) /* ../dlls/kernel32/time.c:1565 */
{
	ULONGLONG return_value;
	TRACE("Enter GetTickCount64\n");
	return_value = pGetTickCount64();
	TRACE("Leave GetTickCount64\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetTimeFormatA(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCSTR lpFormat, LPSTR lpTimeStr, INT cchOut) /* ../dlls/kernel32/lcformat.c:945 */
{
	INT return_value;
	TRACE("Enter GetTimeFormatA\n");
	return_value = pGetTimeFormatA(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
	TRACE("Leave GetTimeFormatA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetTimeFormatEx(LPCWSTR localename, DWORD flags, SYSTEMTIME* time, LPCWSTR format, LPWSTR outbuf, INT bufsize) /* ../dlls/kernel32/lcformat.c:975 */
{
	INT return_value;
	TRACE("Enter GetTimeFormatEx\n");
	return_value = pGetTimeFormatEx(localename, flags, time, format, outbuf, bufsize);
	TRACE("Leave GetTimeFormatEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetTimeFormatW(LCID lcid, DWORD dwFlags, SYSTEMTIME* lpTime, LPCWSTR lpFormat, LPWSTR lpTimeStr, INT cchOut) /* ../dlls/kernel32/lcformat.c:992 */
{
	INT return_value;
	TRACE("Enter GetTimeFormatW\n");
	return_value = pGetTimeFormatW(lcid, dwFlags, lpTime, lpFormat, lpTimeStr, cchOut);
	TRACE("Leave GetTimeFormatW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetTimeZoneInformation(LPTIME_ZONE_INFORMATION ret) /* ../dlls/kernel32/time.c:638 */
{
	DWORD return_value;
	TRACE("Enter GetTimeZoneInformation\n");
	return_value = pGetTimeZoneInformation(ret);
	TRACE("Leave GetTimeZoneInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetTimeZoneInformationForYear(USHORT wYear, PDYNAMIC_TIME_ZONE_INFORMATION pdtzi, LPTIME_ZONE_INFORMATION ptzi) /* ../dlls/kernel32/time.c:652 */
{
	BOOL return_value;
	TRACE("Enter GetTimeZoneInformationForYear\n");
	return_value = pGetTimeZoneInformationForYear(wYear, pdtzi, ptzi);
	TRACE("Leave GetTimeZoneInformationForYear\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetUmsCompletionListEvent(PUMS_COMPLETION_LIST list, HANDLE* event) /* ../dlls/kernel32/process.c:4216 */
{
	BOOL return_value;
	TRACE("Enter GetUmsCompletionListEvent\n");
	return_value = pGetUmsCompletionListEvent(list, event);
	TRACE("Leave GetUmsCompletionListEvent\n");
	return return_value;
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

WINAPI LCID wine32b_kernel32_GetUserDefaultLCID(void) /* ../dlls/kernel32/locale.c:1207 */
{
	LCID return_value;
	TRACE("Enter GetUserDefaultLCID\n");
	return_value = pGetUserDefaultLCID();
	TRACE("Leave GetUserDefaultLCID\n");
	return return_value;
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

WINAPI LANGID wine32b_kernel32_GetUserDefaultLangID(void) /* ../dlls/kernel32/locale.c:1173 */
{
	LANGID return_value;
	TRACE("Enter GetUserDefaultLangID\n");
	return_value = pGetUserDefaultLangID();
	TRACE("Leave GetUserDefaultLangID\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_GetUserDefaultLocaleName(LPWSTR localename, int buffersize) /* ../dlls/kernel32/locale.c:5263 */
{
	INT return_value;
	TRACE("Enter GetUserDefaultLocaleName\n");
	return_value = pGetUserDefaultLocaleName(localename, buffersize);
	TRACE("Leave GetUserDefaultLocaleName\n");
	return return_value;
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

WINAPI LANGID wine32b_kernel32_GetUserDefaultUILanguage(void) /* ../dlls/kernel32/locale.c:1385 */
{
	LANGID return_value;
	TRACE("Enter GetUserDefaultUILanguage\n");
	return_value = pGetUserDefaultUILanguage();
	TRACE("Leave GetUserDefaultUILanguage\n");
	return return_value;
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

WINAPI GEOID wine32b_kernel32_GetUserGeoID(GEOCLASS GeoClass) /* ../dlls/kernel32/locale.c:4611 */
{
	GEOID return_value;
	TRACE("Enter GetUserGeoID\n");
	return_value = pGetUserGeoID(GeoClass);
	TRACE("Leave GetUserGeoID\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetUserPreferredUILanguages(DWORD flags, ULONG* count, WCHAR* buffer, ULONG* size) /* ../dlls/kernel32/locale.c:1351 */
{
	BOOL return_value;
	TRACE("Enter GetUserPreferredUILanguages\n");
	return_value = pGetUserPreferredUILanguages(flags, count, buffer, size);
	TRACE("Leave GetUserPreferredUILanguages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumeInformationA(LPCSTR root, LPSTR label, DWORD label_len, DWORD* serial, DWORD* filename_len, DWORD* flags, LPSTR fsname, DWORD fsname_len) /* ../dlls/kernel32/volume.c:841 */
{
	BOOL return_value;
	TRACE("Enter GetVolumeInformationA\n");
	return_value = pGetVolumeInformationA(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
	TRACE("Leave GetVolumeInformationA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumeInformationByHandleW(HANDLE handle, WCHAR* volnamebuf, DWORD volnamesize, DWORD* volserial, DWORD* maxlength, DWORD* flags, WCHAR* fsnamebuf, DWORD fsnamesize) /* ../dlls/kernel32/volume.c:2164 */
{
	BOOL return_value;
	TRACE("Enter GetVolumeInformationByHandleW\n");
	return_value = pGetVolumeInformationByHandleW(handle, volnamebuf, volnamesize, volserial, maxlength, flags, fsnamebuf, fsnamesize);
	TRACE("Leave GetVolumeInformationByHandleW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumeInformationW(LPCWSTR root, LPWSTR label, DWORD label_len, DWORD* serial, DWORD* filename_len, DWORD* flags, LPWSTR fsname, DWORD fsname_len) /* ../dlls/kernel32/volume.c:686 */
{
	BOOL return_value;
	TRACE("Enter GetVolumeInformationW\n");
	return_value = pGetVolumeInformationW(root, label, label_len, serial, filename_len, flags, fsname, fsname_len);
	TRACE("Leave GetVolumeInformationW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumeNameForVolumeMountPointA(LPCSTR path, LPSTR volume, DWORD size) /* ../dlls/kernel32/volume.c:981 */
{
	BOOL return_value;
	TRACE("Enter GetVolumeNameForVolumeMountPointA\n");
	return_value = pGetVolumeNameForVolumeMountPointA(path, volume, size);
	TRACE("Leave GetVolumeNameForVolumeMountPointA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumeNameForVolumeMountPointW(LPCWSTR path, LPWSTR volume, DWORD size) /* ../dlls/kernel32/volume.c:1002 */
{
	BOOL return_value;
	TRACE("Enter GetVolumeNameForVolumeMountPointW\n");
	return_value = pGetVolumeNameForVolumeMountPointW(path, volume, size);
	TRACE("Leave GetVolumeNameForVolumeMountPointW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumePathNameA(LPCSTR filename, LPSTR volumepathname, DWORD buflen) /* ../dlls/kernel32/volume.c:1638 */
{
	BOOL return_value;
	TRACE("Enter GetVolumePathNameA\n");
	return_value = pGetVolumePathNameA(filename, volumepathname, buflen);
	TRACE("Leave GetVolumePathNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumePathNameW(LPCWSTR filename, LPWSTR volumepathname, DWORD buflen) /* ../dlls/kernel32/volume.c:1666 */
{
	BOOL return_value;
	TRACE("Enter GetVolumePathNameW\n");
	return_value = pGetVolumePathNameW(filename, volumepathname, buflen);
	TRACE("Leave GetVolumePathNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumePathNamesForVolumeNameA(LPCSTR volumename, LPSTR volumepathname, DWORD buflen, PDWORD returnlen) /* ../dlls/kernel32/volume.c:1809 */
{
	BOOL return_value;
	TRACE("Enter GetVolumePathNamesForVolumeNameA\n");
	return_value = pGetVolumePathNamesForVolumeNameA(volumename, volumepathname, buflen, returnlen);
	TRACE("Leave GetVolumePathNamesForVolumeNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GetVolumePathNamesForVolumeNameW(LPCWSTR volumename, LPWSTR volumepathname, DWORD buflen, PDWORD returnlen) /* ../dlls/kernel32/volume.c:1863 */
{
	BOOL return_value;
	TRACE("Enter GetVolumePathNamesForVolumeNameW\n");
	return_value = pGetVolumePathNamesForVolumeNameW(volumename, volumepathname, buflen, returnlen);
	TRACE("Leave GetVolumePathNamesForVolumeNameW\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_GlobalAddAtomA(LPCSTR str) /* ../dlls/kernel32/atom.c:111 */
{
	ATOM return_value;
	TRACE("Enter GlobalAddAtomA\n");
	return_value = pGlobalAddAtomA(str);
	TRACE("Leave GlobalAddAtomA\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_GlobalAddAtomW(LPCWSTR str) /* ../dlls/kernel32/atom.c:182 */
{
	ATOM return_value;
	TRACE("Enter GlobalAddAtomW\n");
	return_value = pGlobalAddAtomW(str);
	TRACE("Leave GlobalAddAtomW\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_GlobalCompact(DWORD minfree) /* ../dlls/kernel32/heap.c:509 */
{
	SIZE_T return_value;
	TRACE("Enter GlobalCompact\n");
	return_value = pGlobalCompact(minfree);
	TRACE("Leave GlobalCompact\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_GlobalDeleteAtom(ATOM atom) /* ../dlls/kernel32/atom.c:230 */
{
	ATOM return_value;
	TRACE("Enter GlobalDeleteAtom\n");
	return_value = pGlobalDeleteAtom(atom);
	TRACE("Leave GlobalDeleteAtom\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_GlobalFindAtomA(LPCSTR str) /* ../dlls/kernel32/atom.c:283 */
{
	ATOM return_value;
	TRACE("Enter GlobalFindAtomA\n");
	return_value = pGlobalFindAtomA(str);
	TRACE("Leave GlobalFindAtomA\n");
	return return_value;
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

WINAPI ATOM wine32b_kernel32_GlobalFindAtomW(LPCWSTR str) /* ../dlls/kernel32/atom.c:346 */
{
	ATOM return_value;
	TRACE("Enter GlobalFindAtomW\n");
	return_value = pGlobalFindAtomW(str);
	TRACE("Leave GlobalFindAtomW\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GlobalFix(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:447 */
{
	TRACE("Enter GlobalFix\n");
	pGlobalFix(hmem);
	TRACE("Leave GlobalFix\n");
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

WINAPI UINT wine32b_kernel32_GlobalFlags(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:475 */
{
	UINT return_value;
	TRACE("Enter GlobalFlags\n");
	return_value = pGlobalFlags(hmem);
	TRACE("Leave GlobalFlags\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GlobalGetAtomNameA(ATOM atom, LPSTR buffer, INT count) /* ../dlls/kernel32/atom.c:396 */
{
	UINT return_value;
	TRACE("Enter GlobalGetAtomNameA\n");
	return_value = pGlobalGetAtomNameA(atom, buffer, count);
	TRACE("Leave GlobalGetAtomNameA\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_GlobalGetAtomNameW(ATOM atom, LPWSTR buffer, INT count) /* ../dlls/kernel32/atom.c:464 */
{
	UINT return_value;
	TRACE("Enter GlobalGetAtomNameW\n");
	return_value = pGlobalGetAtomNameW(atom, buffer, count);
	TRACE("Leave GlobalGetAtomNameW\n");
	return return_value;
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

WINAPI HGLOBAL wine32b_kernel32_GlobalHandle(LPCVOID pmem) /* ../dlls/kernel32/heap.c:293 */
{
	HGLOBAL return_value;
	TRACE("Enter GlobalHandle\n");
	return_value = pGlobalHandle(pmem);
	TRACE("Leave GlobalHandle\n");
	return return_value;
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

WINAPI LPVOID wine32b_kernel32_GlobalLock(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:255 */
{
	LPVOID return_value;
	TRACE("Enter GlobalLock\n");
	return_value = pGlobalLock(hmem);
	TRACE("Leave GlobalLock\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer) /* ../dlls/kernel32/heap.c:822 */
{
	TRACE("Enter GlobalMemoryStatus\n");
	pGlobalMemoryStatus(lpBuffer);
	TRACE("Leave GlobalMemoryStatus\n");
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

WINAPI BOOL wine32b_kernel32_GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpmemex) /* ../dlls/kernel32/heap.c:601 */
{
	BOOL return_value;
	TRACE("Enter GlobalMemoryStatusEx\n");
	return_value = pGlobalMemoryStatusEx(lpmemex);
	TRACE("Leave GlobalMemoryStatusEx\n");
	return return_value;
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

WINAPI HGLOBAL wine32b_kernel32_GlobalReAlloc(HGLOBAL hmem, SIZE_T size, UINT flags) /* ../dlls/kernel32/heap.c:355 */
{
	HGLOBAL return_value;
	TRACE("Enter GlobalReAlloc\n");
	return_value = pGlobalReAlloc(hmem, size, flags);
	TRACE("Leave GlobalReAlloc\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_GlobalSize(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:377 */
{
	SIZE_T return_value;
	TRACE("Enter GlobalSize\n");
	return_value = pGlobalSize(hmem);
	TRACE("Leave GlobalSize\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_GlobalUnWire(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:438 */
{
	BOOL return_value;
	TRACE("Enter GlobalUnWire\n");
	return_value = pGlobalUnWire(hmem);
	TRACE("Leave GlobalUnWire\n");
	return return_value;
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

WINAPI void wine32b_kernel32_GlobalUnfix(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:456 */
{
	TRACE("Enter GlobalUnfix\n");
	pGlobalUnfix(hmem);
	TRACE("Leave GlobalUnfix\n");
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

WINAPI BOOL wine32b_kernel32_GlobalUnlock(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:277 */
{
	BOOL return_value;
	TRACE("Enter GlobalUnlock\n");
	return_value = pGlobalUnlock(hmem);
	TRACE("Leave GlobalUnlock\n");
	return return_value;
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

WINAPI LPVOID wine32b_kernel32_GlobalWire(HGLOBAL hmem) /* ../dlls/kernel32/heap.c:429 */
{
	LPVOID return_value;
	TRACE("Enter GlobalWire\n");
	return_value = pGlobalWire(hmem);
	TRACE("Leave GlobalWire\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Heap32ListFirst(HANDLE hSnapshot, LPHEAPLIST32 lphl) /* ../dlls/kernel32/toolhelp.c:600 */
{
	BOOL return_value;
	TRACE("Enter Heap32ListFirst\n");
	return_value = pHeap32ListFirst(hSnapshot, lphl);
	TRACE("Leave Heap32ListFirst\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_HeapCreate(DWORD flags, SIZE_T initialSize, SIZE_T maxSize) /* ../dlls/kernel32/heap.c:130 */
{
	HANDLE return_value;
	TRACE("Enter HeapCreate\n");
	return_value = pHeapCreate(flags, initialSize, maxSize);
	TRACE("Leave HeapCreate\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_HeapDestroy(HANDLE heap) /* ../dlls/kernel32/heap.c:161 */
{
	BOOL return_value;
	TRACE("Enter HeapDestroy\n");
	return_value = pHeapDestroy(heap);
	TRACE("Leave HeapDestroy\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_HeapFree(HANDLE heap, DWORD flags, LPVOID ptr) /* ../dlls/kernel32/heap.c:187 */
{
	BOOL return_value;
	TRACE("Enter HeapFree\n");
	return_value = pHeapFree(heap, flags, ptr);
	TRACE("Leave HeapFree\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_IdnToAscii(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpASCIICharStr, INT cchASCIIChar) /* ../dlls/kernel32/locale.c:5366 */
{
	INT return_value;
	TRACE("Enter IdnToAscii\n");
	return_value = pIdnToAscii(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpASCIICharStr, cchASCIIChar);
	TRACE("Leave IdnToAscii\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_IdnToNameprepUnicode(DWORD dwFlags, LPCWSTR lpUnicodeCharStr, INT cchUnicodeChar, LPWSTR lpNameprepCharStr, INT cchNameprepChar) /* ../dlls/kernel32/locale.c:5504 */
{
	INT return_value;
	TRACE("Enter IdnToNameprepUnicode\n");
	return_value = pIdnToNameprepUnicode(dwFlags, lpUnicodeCharStr, cchUnicodeChar, lpNameprepCharStr, cchNameprepChar);
	TRACE("Leave IdnToNameprepUnicode\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_IdnToUnicode(DWORD dwFlags, LPCWSTR lpASCIICharStr, INT cchASCIIChar, LPWSTR lpUnicodeCharStr, INT cchUnicodeChar) /* ../dlls/kernel32/locale.c:5716 */
{
	INT return_value;
	TRACE("Enter IdnToUnicode\n");
	return_value = pIdnToUnicode(dwFlags, lpASCIICharStr, cchASCIIChar, lpUnicodeCharStr, cchUnicodeChar);
	TRACE("Leave IdnToUnicode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_InitAtomTable(DWORD entries) /* ../dlls/kernel32/atom.c:79 */
{
	BOOL return_value;
	TRACE("Enter InitAtomTable\n");
	return_value = pInitAtomTable(entries);
	TRACE("Leave InitAtomTable\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_InvalidateNLSCache(void) /* ../dlls/kernel32/locale.c:4602 */
{
	BOOL return_value;
	TRACE("Enter InvalidateNLSCache\n");
	return_value = pInvalidateNLSCache();
	TRACE("Leave InvalidateNLSCache\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadCodePtr(FARPROC ptr) /* ../dlls/kernel32/virtual.c:183 */
{
	BOOL return_value;
	TRACE("Enter IsBadCodePtr\n");
	return_value = pIsBadCodePtr(ptr);
	TRACE("Leave IsBadCodePtr\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadHugeReadPtr(LPCVOID ptr, UINT_PTR size) /* ../dlls/kernel32/virtual.c:146 */
{
	BOOL return_value;
	TRACE("Enter IsBadHugeReadPtr\n");
	return_value = pIsBadHugeReadPtr(ptr, size);
	TRACE("Leave IsBadHugeReadPtr\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadHugeWritePtr(LPVOID ptr, UINT_PTR size) /* ../dlls/kernel32/virtual.c:165 */
{
	BOOL return_value;
	TRACE("Enter IsBadHugeWritePtr\n");
	return_value = pIsBadHugeWritePtr(ptr, size);
	TRACE("Leave IsBadHugeWritePtr\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadReadPtr(LPCVOID ptr, UINT_PTR size) /* ../dlls/kernel32/virtual.c:63 */
{
	BOOL return_value;
	TRACE("Enter IsBadReadPtr\n");
	return_value = pIsBadReadPtr(ptr, size);
	TRACE("Leave IsBadReadPtr\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadStringPtrA(LPCSTR str, UINT_PTR max) /* ../dlls/kernel32/virtual.c:202 */
{
	BOOL return_value;
	TRACE("Enter IsBadStringPtrA\n");
	return_value = pIsBadStringPtrA(str, max);
	TRACE("Leave IsBadStringPtrA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadStringPtrW(LPCWSTR str, UINT_PTR max) /* ../dlls/kernel32/virtual.c:226 */
{
	BOOL return_value;
	TRACE("Enter IsBadStringPtrW\n");
	return_value = pIsBadStringPtrW(str, max);
	TRACE("Leave IsBadStringPtrW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsBadWritePtr(LPVOID ptr, UINT_PTR size) /* ../dlls/kernel32/virtual.c:105 */
{
	BOOL return_value;
	TRACE("Enter IsBadWritePtr\n");
	return_value = pIsBadWritePtr(ptr, size);
	TRACE("Leave IsBadWritePtr\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsDBCSLeadByte(BYTE testchar) /* ../dlls/kernel32/locale.c:2112 */
{
	BOOL return_value;
	TRACE("Enter IsDBCSLeadByte\n");
	return_value = pIsDBCSLeadByte(testchar);
	TRACE("Leave IsDBCSLeadByte\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsDBCSLeadByteEx(UINT codepage, BYTE testchar) /* ../dlls/kernel32/locale.c:2092 */
{
	BOOL return_value;
	TRACE("Enter IsDBCSLeadByteEx\n");
	return_value = pIsDBCSLeadByteEx(codepage, testchar);
	TRACE("Leave IsDBCSLeadByteEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsNormalizedString(NORM_FORM NormForm, LPCWSTR lpString, INT cwLength) /* ../dlls/kernel32/locale.c:5333 */
{
	BOOL return_value;
	TRACE("Enter IsNormalizedString\n");
	return_value = pIsNormalizedString(NormForm, lpString, cwLength);
	TRACE("Leave IsNormalizedString\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsProcessInJob(HANDLE process, HANDLE job, PBOOL result) /* ../dlls/kernel32/sync.c:388 */
{
	BOOL return_value;
	TRACE("Enter IsProcessInJob\n");
	return_value = pIsProcessInJob(process, job, result);
	TRACE("Leave IsProcessInJob\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsProcessorFeaturePresent(DWORD feature) /* ../dlls/kernel32/cpu.c:157 */
{
	BOOL return_value;
	TRACE("Enter IsProcessorFeaturePresent\n");
	return_value = pIsProcessorFeaturePresent(feature);
	TRACE("Leave IsProcessorFeaturePresent\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsSystemResumeAutomatic(void) /* ../dlls/kernel32/powermgnt.c:66 */
{
	BOOL return_value;
	TRACE("Enter IsSystemResumeAutomatic\n");
	return_value = pIsSystemResumeAutomatic();
	TRACE("Leave IsSystemResumeAutomatic\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsValidCodePage(UINT codepage) /* ../dlls/kernel32/locale.c:2067 */
{
	BOOL return_value;
	TRACE("Enter IsValidCodePage\n");
	return_value = pIsValidCodePage(codepage);
	TRACE("Leave IsValidCodePage\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsValidLanguageGroup(LGRPID lgrpid, DWORD dwFlags) /* ../dlls/kernel32/locale.c:4402 */
{
	BOOL return_value;
	TRACE("Enter IsValidLanguageGroup\n");
	return_value = pIsValidLanguageGroup(lgrpid, dwFlags);
	TRACE("Leave IsValidLanguageGroup\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsValidLocale(LCID lcid, DWORD flags) /* ../dlls/kernel32/locale.c:2917 */
{
	BOOL return_value;
	TRACE("Enter IsValidLocale\n");
	return_value = pIsValidLocale(lcid, flags);
	TRACE("Leave IsValidLocale\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_IsValidLocaleName(LPCWSTR locale) /* ../dlls/kernel32/locale.c:2927 */
{
	BOOL return_value;
	TRACE("Enter IsValidLocaleName\n");
	return_value = pIsValidLocaleName(locale);
	TRACE("Leave IsValidLocaleName\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EmptyWorkingSet(HANDLE hProcess) /* ../dlls/kernel32/process.c:3503 */
{
	BOOL return_value;
	TRACE("Enter K32EmptyWorkingSet\n");
	return_value = pK32EmptyWorkingSet(hProcess);
	TRACE("Leave K32EmptyWorkingSet\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumDeviceDrivers(void** image_base, DWORD cb, DWORD* needed) /* ../dlls/kernel32/file.c:1276 */
{
	BOOL return_value;
	TRACE("Enter K32EnumDeviceDrivers\n");
	return_value = pK32EnumDeviceDrivers(image_base, cb, needed);
	TRACE("Leave K32EnumDeviceDrivers\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumPageFilesA(PENUM_PAGE_FILE_CALLBACKA callback, LPVOID context) /* ../dlls/kernel32/virtual.c:273 */
{
	BOOL return_value;
	TRACE("Enter K32EnumPageFilesA\n");
	return_value = pK32EnumPageFilesA(callback, context);
	TRACE("Leave K32EnumPageFilesA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumPageFilesW(PENUM_PAGE_FILE_CALLBACKW callback, LPVOID context) /* ../dlls/kernel32/virtual.c:282 */
{
	BOOL return_value;
	TRACE("Enter K32EnumPageFilesW\n");
	return_value = pK32EnumPageFilesW(callback, context);
	TRACE("Leave K32EnumPageFilesW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumProcessModules(HANDLE process, HMODULE* lphModule, DWORD cb, DWORD* needed) /* ../dlls/kernel32/module.c:1228 */
{
	BOOL return_value;
	TRACE("Enter K32EnumProcessModules\n");
	return_value = pK32EnumProcessModules(process, lphModule, cb, needed);
	TRACE("Leave K32EnumProcessModules\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumProcessModulesEx(HANDLE process, HMODULE* lphModule, DWORD cb, DWORD* needed, DWORD filter) /* ../dlls/kernel32/module.c:1273 */
{
	BOOL return_value;
	TRACE("Enter K32EnumProcessModulesEx\n");
	return_value = pK32EnumProcessModulesEx(process, lphModule, cb, needed, filter);
	TRACE("Leave K32EnumProcessModulesEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32EnumProcesses(DWORD* lpdwProcessIDs, DWORD cb, DWORD* lpcbUsed) /* ../dlls/kernel32/process.c:3653 */
{
	BOOL return_value;
	TRACE("Enter K32EnumProcesses\n");
	return_value = pK32EnumProcesses(lpdwProcessIDs, cb, lpcbUsed);
	TRACE("Leave K32EnumProcesses\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverBaseNameA(void* image_base, LPSTR base_name, DWORD size) /* ../dlls/kernel32/file.c:1289 */
{
	DWORD return_value;
	TRACE("Enter K32GetDeviceDriverBaseNameA\n");
	return_value = pK32GetDeviceDriverBaseNameA(image_base, base_name, size);
	TRACE("Leave K32GetDeviceDriverBaseNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverBaseNameW(void* image_base, LPWSTR base_name, DWORD size) /* ../dlls/kernel32/file.c:1302 */
{
	DWORD return_value;
	TRACE("Enter K32GetDeviceDriverBaseNameW\n");
	return_value = pK32GetDeviceDriverBaseNameW(image_base, base_name, size);
	TRACE("Leave K32GetDeviceDriverBaseNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverFileNameA(void* image_base, LPSTR file_name, DWORD size) /* ../dlls/kernel32/file.c:1315 */
{
	DWORD return_value;
	TRACE("Enter K32GetDeviceDriverFileNameA\n");
	return_value = pK32GetDeviceDriverFileNameA(image_base, file_name, size);
	TRACE("Leave K32GetDeviceDriverFileNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetDeviceDriverFileNameW(void* image_base, LPWSTR file_name, DWORD size) /* ../dlls/kernel32/file.c:1328 */
{
	DWORD return_value;
	TRACE("Enter K32GetDeviceDriverFileNameW\n");
	return_value = pK32GetDeviceDriverFileNameW(image_base, file_name, size);
	TRACE("Leave K32GetDeviceDriverFileNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetMappedFileNameA(HANDLE process, LPVOID lpv, LPSTR file_name, DWORD size) /* ../dlls/kernel32/virtual.c:247 */
{
	DWORD return_value;
	TRACE("Enter K32GetMappedFileNameA\n");
	return_value = pK32GetMappedFileNameA(process, lpv, file_name, size);
	TRACE("Leave K32GetMappedFileNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetMappedFileNameW(HANDLE process, LPVOID lpv, LPWSTR file_name, DWORD size) /* ../dlls/kernel32/virtual.c:260 */
{
	DWORD return_value;
	TRACE("Enter K32GetMappedFileNameW\n");
	return_value = pK32GetMappedFileNameW(process, lpv, file_name, size);
	TRACE("Leave K32GetMappedFileNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetModuleBaseNameA(HANDLE process, HMODULE module, LPSTR base_name, DWORD size) /* ../dlls/kernel32/module.c:1323 */
{
	DWORD return_value;
	TRACE("Enter K32GetModuleBaseNameA\n");
	return_value = pK32GetModuleBaseNameA(process, module, base_name, size);
	TRACE("Leave K32GetModuleBaseNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetModuleBaseNameW(HANDLE process, HMODULE module, LPWSTR base_name, DWORD size) /* ../dlls/kernel32/module.c:1284 */
{
	DWORD return_value;
	TRACE("Enter K32GetModuleBaseNameW\n");
	return_value = pK32GetModuleBaseNameW(process, module, base_name, size);
	TRACE("Leave K32GetModuleBaseNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetModuleFileNameExA(HANDLE process, HMODULE module, LPSTR file_name, DWORD size) /* ../dlls/kernel32/module.c:1403 */
{
	DWORD return_value;
	TRACE("Enter K32GetModuleFileNameExA\n");
	return_value = pK32GetModuleFileNameExA(process, module, file_name, size);
	TRACE("Leave K32GetModuleFileNameExA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetModuleFileNameExW(HANDLE process, HMODULE module, LPWSTR file_name, DWORD size) /* ../dlls/kernel32/module.c:1353 */
{
	DWORD return_value;
	TRACE("Enter K32GetModuleFileNameExW\n");
	return_value = pK32GetModuleFileNameExW(process, module, file_name, size);
	TRACE("Leave K32GetModuleFileNameExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32GetModuleInformation(HANDLE process, HMODULE module, MODULEINFO* modinfo, DWORD cb) /* ../dlls/kernel32/module.c:1448 */
{
	BOOL return_value;
	TRACE("Enter K32GetModuleInformation\n");
	return_value = pK32GetModuleInformation(process, module, modinfo, cb);
	TRACE("Leave K32GetModuleInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32GetPerformanceInfo(PPERFORMANCE_INFORMATION info, DWORD size) /* ../dlls/kernel32/cpu.c:165 */
{
	BOOL return_value;
	TRACE("Enter K32GetPerformanceInfo\n");
	return_value = pK32GetPerformanceInfo(info, size);
	TRACE("Leave K32GetPerformanceInfo\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetProcessImageFileNameA(HANDLE process, LPSTR file, DWORD size) /* ../dlls/kernel32/process.c:3637 */
{
	DWORD return_value;
	TRACE("Enter K32GetProcessImageFileNameA\n");
	return_value = pK32GetProcessImageFileNameA(process, file, size);
	TRACE("Leave K32GetProcessImageFileNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_K32GetProcessImageFileNameW(HANDLE process, LPWSTR file, DWORD size) /* ../dlls/kernel32/process.c:3645 */
{
	DWORD return_value;
	TRACE("Enter K32GetProcessImageFileNameW\n");
	return_value = pK32GetProcessImageFileNameW(process, file, size);
	TRACE("Leave K32GetProcessImageFileNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32GetProcessMemoryInfo(HANDLE process, PPROCESS_MEMORY_COUNTERS pmc, DWORD cb) /* ../dlls/kernel32/process.c:3738 */
{
	BOOL return_value;
	TRACE("Enter K32GetProcessMemoryInfo\n");
	return_value = pK32GetProcessMemoryInfo(process, pmc, cb);
	TRACE("Leave K32GetProcessMemoryInfo\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32GetWsChanges(HANDLE process, PPSAPI_WS_WATCH_INFORMATION watchinfo, DWORD size) /* ../dlls/kernel32/virtual.c:291 */
{
	BOOL return_value;
	TRACE("Enter K32GetWsChanges\n");
	return_value = pK32GetWsChanges(process, watchinfo, size);
	TRACE("Leave K32GetWsChanges\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32GetWsChangesEx(HANDLE process, PSAPI_WS_WATCH_INFORMATION_EX* watchinfoex, DWORD* size) /* ../dlls/kernel32/virtual.c:310 */
{
	BOOL return_value;
	TRACE("Enter K32GetWsChangesEx\n");
	return_value = pK32GetWsChangesEx(process, watchinfoex, size);
	TRACE("Leave K32GetWsChangesEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32InitializeProcessForWsWatch(HANDLE process) /* ../dlls/kernel32/virtual.c:321 */
{
	BOOL return_value;
	TRACE("Enter K32InitializeProcessForWsWatch\n");
	return_value = pK32InitializeProcessForWsWatch(process);
	TRACE("Leave K32InitializeProcessForWsWatch\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32QueryWorkingSet(HANDLE process, LPVOID buffer, DWORD size) /* ../dlls/kernel32/process.c:3697 */
{
	BOOL return_value;
	TRACE("Enter K32QueryWorkingSet\n");
	return_value = pK32QueryWorkingSet(process, buffer, size);
	TRACE("Leave K32QueryWorkingSet\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_K32QueryWorkingSetEx(HANDLE process, LPVOID buffer, DWORD size) /* ../dlls/kernel32/process.c:3716 */
{
	BOOL return_value;
	TRACE("Enter K32QueryWorkingSetEx\n");
	return_value = pK32QueryWorkingSetEx(process, buffer, size);
	TRACE("Leave K32QueryWorkingSetEx\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_GetCurrentProcess(void) /* ../dlls/kernel32/process.c:3811 */
{
	HANDLE return_value;
	TRACE("Enter GetCurrentProcess\n");
	return_value = pGetCurrentProcess();
	TRACE("Leave GetCurrentProcess\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetCurrentProcessId(void) /* ../dlls/kernel32/thread.c:146 */
{
	DWORD return_value;
	TRACE("Enter GetCurrentProcessId\n");
	return_value = pGetCurrentProcessId();
	TRACE("Leave GetCurrentProcessId\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_GetCurrentThread(void) /* ../dlls/kernel32/thread.c:133 */
{
	HANDLE return_value;
	TRACE("Enter GetCurrentThread\n");
	return_value = pGetCurrentThread();
	TRACE("Leave GetCurrentThread\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_GetCurrentThreadId(void) /* ../dlls/kernel32/thread.c:159 */
{
	DWORD return_value;
	TRACE("Enter GetCurrentThreadId\n");
	return_value = pGetCurrentThreadId();
	TRACE("Leave GetCurrentThreadId\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LCIDToLocaleName(LCID lcid, LPWSTR name, INT count, DWORD flags) /* ../dlls/kernel32/locale.c:1450 */
{
	INT return_value;
	TRACE("Enter LCIDToLocaleName\n");
	return_value = pLCIDToLocaleName(lcid, name, count, flags);
	TRACE("Leave LCIDToLocaleName\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LCMapStringA(LCID lcid, DWORD flags, LPCSTR src, INT srclen, LPSTR dst, INT dstlen) /* ../dlls/kernel32/locale.c:3724 */
{
	INT return_value;
	TRACE("Enter LCMapStringA\n");
	return_value = pLCMapStringA(lcid, flags, src, srclen, dst, dstlen);
	TRACE("Leave LCMapStringA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LCMapStringEx(LPCWSTR name, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen, LPNLSVERSIONINFO version, LPVOID reserved, LPARAM lparam) /* ../dlls/kernel32/locale.c:3463 */
{
	INT return_value;
	TRACE("Enter LCMapStringEx\n");
	return_value = pLCMapStringEx(name, flags, src, srclen, dst, dstlen, version, reserved, lparam);
	TRACE("Leave LCMapStringEx\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LCMapStringW(LCID lcid, DWORD flags, LPCWSTR src, INT srclen, LPWSTR dst, INT dstlen) /* ../dlls/kernel32/locale.c:3698 */
{
	INT return_value;
	TRACE("Enter LCMapStringW\n");
	return_value = pLCMapStringW(lcid, flags, src, srclen, dst, dstlen);
	TRACE("Leave LCMapStringW\n");
	return return_value;
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

WINAPI void wine32b_kernel32_LZClose(HFILE fd) /* ../dlls/kernel32/lzexpand.c:579 */
{
	TRACE("Enter LZClose\n");
	pLZClose(fd);
	TRACE("Leave LZClose\n");
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

WINAPI LONG wine32b_kernel32_LZCopy(HFILE src, HFILE dest) /* ../dlls/kernel32/lzexpand.c:455 */
{
	LONG return_value;
	TRACE("Enter LZCopy\n");
	return_value = pLZCopy(src, dest);
	TRACE("Leave LZCopy\n");
	return return_value;
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

WINAPI void wine32b_kernel32_LZDone(void) /* ../dlls/kernel32/lzexpand.c:223 */
{
	TRACE("Enter LZDone\n");
	pLZDone();
	TRACE("Leave LZDone\n");
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

WINAPI HFILE wine32b_kernel32_LZInit(HFILE hfSrc) /* ../dlls/kernel32/lzexpand.c:180 */
{
	HFILE return_value;
	TRACE("Enter LZInit\n");
	return_value = pLZInit(hfSrc);
	TRACE("Leave LZInit\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32_LZOpenFileA(LPSTR fn, LPOFSTRUCT ofs, WORD mode) /* ../dlls/kernel32/lzexpand.c:535 */
{
	HFILE return_value;
	TRACE("Enter LZOpenFileA\n");
	return_value = pLZOpenFileA(fn, ofs, mode);
	TRACE("Leave LZOpenFileA\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32_LZOpenFileW(LPWSTR fn, LPOFSTRUCT ofs, WORD mode) /* ../dlls/kernel32/lzexpand.c:564 */
{
	HFILE return_value;
	TRACE("Enter LZOpenFileW\n");
	return_value = pLZOpenFileW(fn, ofs, mode);
	TRACE("Leave LZOpenFileW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LZRead(HFILE fd, LPSTR vbuf, INT toread) /* ../dlls/kernel32/lzexpand.c:328 */
{
	INT return_value;
	TRACE("Enter LZRead\n");
	return_value = pLZRead(fd, vbuf, toread);
	TRACE("Leave LZRead\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32_LZSeek(HFILE fd, LONG off, INT type) /* ../dlls/kernel32/lzexpand.c:419 */
{
	LONG return_value;
	TRACE("Enter LZSeek\n");
	return_value = pLZSeek(fd, off, type);
	TRACE("Leave LZSeek\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_LZStart(void) /* ../dlls/kernel32/lzexpand.c:162 */
{
	INT return_value;
	TRACE("Enter LZStart\n");
	return_value = pLZStart();
	TRACE("Leave LZStart\n");
	return return_value;
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

WINAPI HMODULE wine32b_kernel32_LoadLibraryA(LPCSTR libname) /* ../dlls/kernel32/module.c:860 */
{
	HMODULE return_value;
	TRACE("Enter LoadLibraryA\n");
	return_value = pLoadLibraryA(libname);
	TRACE("Leave LoadLibraryA\n");
	return return_value;
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

WINAPI HMODULE wine32b_kernel32_LoadLibraryExA(LPCSTR libname, HANDLE hfile, DWORD flags) /* ../dlls/kernel32/module.c:805 */
{
	HMODULE return_value;
	TRACE("Enter LoadLibraryExA\n");
	return_value = pLoadLibraryExA(libname, hfile, flags);
	TRACE("Leave LoadLibraryExA\n");
	return return_value;
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

WINAPI HMODULE wine32b_kernel32_LoadLibraryExW(LPCWSTR libnameW, HANDLE hfile, DWORD flags) /* ../dlls/kernel32/module.c:818 */
{
	HMODULE return_value;
	TRACE("Enter LoadLibraryExW\n");
	return_value = pLoadLibraryExW(libnameW, hfile, flags);
	TRACE("Leave LoadLibraryExW\n");
	return return_value;
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

WINAPI HMODULE wine32b_kernel32_LoadLibraryW(LPCWSTR libnameW) /* ../dlls/kernel32/module.c:870 */
{
	HMODULE return_value;
	TRACE("Enter LoadLibraryW\n");
	return_value = pLoadLibraryW(libnameW);
	TRACE("Leave LoadLibraryW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_LoadModule(LPCSTR name, LPVOID paramBlock) /* ../dlls/kernel32/process.c:3079 */
{
	DWORD return_value;
	TRACE("Enter LoadModule\n");
	return_value = pLoadModule(name, paramBlock);
	TRACE("Leave LoadModule\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_LocalCompact(UINT minfree) /* ../dlls/kernel32/heap.c:518 */
{
	SIZE_T return_value;
	TRACE("Enter LocalCompact\n");
	return_value = pLocalCompact(minfree);
	TRACE("Leave LocalCompact\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_LocalFileTimeToFileTime(FILETIME* localft, LPFILETIME utcft) /* ../dlls/kernel32/time.c:1176 */
{
	BOOL return_value;
	TRACE("Enter LocalFileTimeToFileTime\n");
	return_value = pLocalFileTimeToFileTime(localft, utcft);
	TRACE("Leave LocalFileTimeToFileTime\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_LocalFlags(HLOCAL handle) /* ../dlls/kernel32/heap.c:537 */
{
	UINT return_value;
	TRACE("Enter LocalFlags\n");
	return_value = pLocalFlags(handle);
	TRACE("Leave LocalFlags\n");
	return return_value;
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

WINAPI HLOCAL wine32b_kernel32_LocalHandle(LPCVOID ptr) /* ../dlls/kernel32/heap.c:557 */
{
	HLOCAL return_value;
	TRACE("Enter LocalHandle\n");
	return_value = pLocalHandle(ptr);
	TRACE("Leave LocalHandle\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_LocalShrink(HGLOBAL handle, UINT newsize) /* ../dlls/kernel32/heap.c:567 */
{
	SIZE_T return_value;
	TRACE("Enter LocalShrink\n");
	return_value = pLocalShrink(handle, newsize);
	TRACE("Leave LocalShrink\n");
	return return_value;
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

WINAPI SIZE_T wine32b_kernel32_LocalSize(HLOCAL handle) /* ../dlls/kernel32/heap.c:586 */
{
	SIZE_T return_value;
	TRACE("Enter LocalSize\n");
	return_value = pLocalSize(handle);
	TRACE("Leave LocalSize\n");
	return return_value;
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

WINAPI LCID wine32b_kernel32_LocaleNameToLCID(LPCWSTR name, DWORD flags) /* ../dlls/kernel32/locale.c:1416 */
{
	LCID return_value;
	TRACE("Enter LocaleNameToLCID\n");
	return_value = pLocaleNameToLCID(name, flags);
	TRACE("Leave LocaleNameToLCID\n");
	return return_value;
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

WINAPI void wine32b_kernel32_MakeCriticalSectionGlobal(CRITICAL_SECTION* crit) /* ../dlls/kernel32/sync.c:147 */
{
	TRACE("Enter MakeCriticalSectionGlobal\n");
	pMakeCriticalSectionGlobal(crit);
	TRACE("Leave MakeCriticalSectionGlobal\n");
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

WINAPI BOOL wine32b_kernel32_MapUserPhysicalPages(PVOID addr, ULONG_PTR page_count, PULONG_PTR pages) /* ../dlls/kernel32/heap.c:944 */
{
	BOOL return_value;
	TRACE("Enter MapUserPhysicalPages\n");
	return_value = pMapUserPhysicalPages(addr, page_count, pages);
	TRACE("Leave MapUserPhysicalPages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Module32First(HANDLE hSnapshot, LPMODULEENTRY32 lpme) /* ../dlls/kernel32/toolhelp.c:581 */
{
	BOOL return_value;
	TRACE("Enter Module32First\n");
	return_value = pModule32First(hSnapshot, lpme);
	TRACE("Leave Module32First\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Module32FirstW(HANDLE hSnapshot, LPMODULEENTRY32W lpme) /* ../dlls/kernel32/toolhelp.c:528 */
{
	BOOL return_value;
	TRACE("Enter Module32FirstW\n");
	return_value = pModule32FirstW(hSnapshot, lpme);
	TRACE("Leave Module32FirstW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Module32Next(HANDLE hSnapshot, LPMODULEENTRY32 lpme) /* ../dlls/kernel32/toolhelp.c:591 */
{
	BOOL return_value;
	TRACE("Enter Module32Next\n");
	return_value = pModule32Next(hSnapshot, lpme);
	TRACE("Leave Module32Next\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Module32NextW(HANDLE hSnapshot, LPMODULEENTRY32W lpme) /* ../dlls/kernel32/toolhelp.c:538 */
{
	BOOL return_value;
	TRACE("Enter Module32NextW\n");
	return_value = pModule32NextW(hSnapshot, lpme);
	TRACE("Leave Module32NextW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileA(LPCSTR source, LPCSTR dest) /* ../dlls/kernel32/path.c:1516 */
{
	BOOL return_value;
	TRACE("Enter MoveFileA\n");
	return_value = pMoveFileA(source, dest);
	TRACE("Leave MoveFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileExA(LPCSTR source, LPCSTR dest, DWORD flag) /* ../dlls/kernel32/path.c:1496 */
{
	BOOL return_value;
	TRACE("Enter MoveFileExA\n");
	return_value = pMoveFileExA(source, dest, flag);
	TRACE("Leave MoveFileExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileExW(LPCWSTR source, LPCWSTR dest, DWORD flag) /* ../dlls/kernel32/path.c:1488 */
{
	BOOL return_value;
	TRACE("Enter MoveFileExW\n");
	return_value = pMoveFileExW(source, dest, flag);
	TRACE("Leave MoveFileExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileTransactedA(char* source, char* dest, LPPROGRESS_ROUTINE progress, void* data, DWORD flags, HANDLE handle) /* ../dlls/kernel32/path.c:1289 */
{
	BOOL return_value;
	TRACE("Enter MoveFileTransactedA\n");
	return_value = pMoveFileTransactedA(source, dest, progress, data, flags, handle);
	TRACE("Leave MoveFileTransactedA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileTransactedW(WCHAR* source, WCHAR* dest, LPPROGRESS_ROUTINE progress, void* data, DWORD flags, HANDLE handle) /* ../dlls/kernel32/path.c:1299 */
{
	BOOL return_value;
	TRACE("Enter MoveFileTransactedW\n");
	return_value = pMoveFileTransactedW(source, dest, progress, data, flags, handle);
	TRACE("Leave MoveFileTransactedW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileW(LPCWSTR source, LPCWSTR dest) /* ../dlls/kernel32/path.c:1507 */
{
	BOOL return_value;
	TRACE("Enter MoveFileW\n");
	return_value = pMoveFileW(source, dest);
	TRACE("Leave MoveFileW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileWithProgressA(LPCSTR source, LPCSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag) /* ../dlls/kernel32/path.c:1465 */
{
	BOOL return_value;
	TRACE("Enter MoveFileWithProgressA\n");
	return_value = pMoveFileWithProgressA(source, dest, fnProgress, param, flag);
	TRACE("Leave MoveFileWithProgressA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_MoveFileWithProgressW(LPCWSTR source, LPCWSTR dest, LPPROGRESS_ROUTINE fnProgress, LPVOID param, DWORD flag) /* ../dlls/kernel32/path.c:1309 */
{
	BOOL return_value;
	TRACE("Enter MoveFileWithProgressW\n");
	return_value = pMoveFileWithProgressW(source, dest, fnProgress, param, flag);
	TRACE("Leave MoveFileWithProgressW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_MulDiv(INT nMultiplicand, INT nMultiplier, INT nDivisor) /* ../dlls/kernel32/kernel_main.c:157 */
{
	INT return_value;
	TRACE("Enter MulDiv\n");
	return_value = pMulDiv(nMultiplicand, nMultiplier, nDivisor);
	TRACE("Leave MulDiv\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_MultiByteToWideChar(UINT page, DWORD flags, LPCSTR src, INT srclen, LPWSTR dst, INT dstlen) /* ../dlls/kernel32/locale.c:2454 */
{
	INT return_value;
	TRACE("Enter MultiByteToWideChar\n");
	return_value = pMultiByteToWideChar(page, flags, src, srclen, dst, dstlen);
	TRACE("Leave MultiByteToWideChar\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_NeedCurrentDirectoryForExePathA(LPCSTR name) /* ../dlls/kernel32/path.c:1868 */
{
	BOOL return_value;
	TRACE("Enter NeedCurrentDirectoryForExePathA\n");
	return_value = pNeedCurrentDirectoryForExePathA(name);
	TRACE("Leave NeedCurrentDirectoryForExePathA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_NeedCurrentDirectoryForExePathW(LPCWSTR name) /* ../dlls/kernel32/path.c:1844 */
{
	BOOL return_value;
	TRACE("Enter NeedCurrentDirectoryForExePathW\n");
	return_value = pNeedCurrentDirectoryForExePathW(name);
	TRACE("Leave NeedCurrentDirectoryForExePathW\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_NormalizeString(NORM_FORM form, WCHAR* src, INT src_len, WCHAR* dst, INT dst_len) /* ../dlls/kernel32/locale.c:5276 */
{
	INT return_value;
	TRACE("Enter NormalizeString\n");
	return_value = pNormalizeString(form, src, src_len, dst, dst_len);
	TRACE("Leave NormalizeString\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenConsoleW(LPCWSTR name, DWORD access, BOOL inherit, DWORD creation) /* ../dlls/kernel32/console.c:213 */
{
	HANDLE return_value;
	TRACE("Enter OpenConsoleW\n");
	return_value = pOpenConsoleW(name, access, inherit, creation);
	TRACE("Leave OpenConsoleW\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32_OpenFile(LPCSTR name, OFSTRUCT* ofs, UINT mode) /* ../dlls/kernel32/file.c:1164 */
{
	HFILE return_value;
	TRACE("Enter OpenFile\n");
	return_value = pOpenFile(name, ofs, mode);
	TRACE("Leave OpenFile\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenFileMappingA(DWORD access, BOOL inherit, LPCSTR name) /* ../dlls/kernel32/sync.c:502 */
{
	HANDLE return_value;
	TRACE("Enter OpenFileMappingA\n");
	return_value = pOpenFileMappingA(access, inherit, name);
	TRACE("Leave OpenFileMappingA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenJobObjectA(DWORD access, BOOL inherit, LPCSTR name) /* ../dlls/kernel32/sync.c:330 */
{
	HANDLE return_value;
	TRACE("Enter OpenJobObjectA\n");
	return_value = pOpenJobObjectA(access, inherit, name);
	TRACE("Leave OpenJobObjectA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenJobObjectW(DWORD access, BOOL inherit, LPCWSTR name) /* ../dlls/kernel32/sync.c:309 */
{
	HANDLE return_value;
	TRACE("Enter OpenJobObjectW\n");
	return_value = pOpenJobObjectW(access, inherit, name);
	TRACE("Leave OpenJobObjectW\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenMutexA(DWORD access, BOOL inherit, LPCSTR name) /* ../dlls/kernel32/sync.c:197 */
{
	HANDLE return_value;
	TRACE("Enter OpenMutexA\n");
	return_value = pOpenMutexA(access, inherit, name);
	TRACE("Leave OpenMutexA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_OpenProfileUserMapping(void) /* ../dlls/kernel32/profile.c:1777 */
{
	BOOL return_value;
	TRACE("Enter OpenProfileUserMapping\n");
	return_value = pOpenProfileUserMapping();
	TRACE("Leave OpenProfileUserMapping\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenSemaphoreA(DWORD access, BOOL inherit, LPCSTR name) /* ../dlls/kernel32/sync.c:250 */
{
	HANDLE return_value;
	TRACE("Enter OpenSemaphoreA\n");
	return_value = pOpenSemaphoreA(access, inherit, name);
	TRACE("Leave OpenSemaphoreA\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenVxDHandle(HANDLE hHandleRing3) /* ../dlls/kernel32/file.c:1086 */
{
	HANDLE return_value;
	TRACE("Enter OpenVxDHandle\n");
	return_value = pOpenVxDHandle(hHandleRing3);
	TRACE("Leave OpenVxDHandle\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_OpenWaitableTimerA(DWORD access, BOOL inherit, LPCSTR name) /* ../dlls/kernel32/sync.c:442 */
{
	HANDLE return_value;
	TRACE("Enter OpenWaitableTimerA\n");
	return_value = pOpenWaitableTimerA(access, inherit, name);
	TRACE("Leave OpenWaitableTimerA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_PowerClearRequest(HANDLE request, POWER_REQUEST_TYPE type) /* ../dlls/kernel32/powermgnt.c:167 */
{
	BOOL return_value;
	TRACE("Enter PowerClearRequest\n");
	return_value = pPowerClearRequest(request, type);
	TRACE("Leave PowerClearRequest\n");
	return return_value;
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

WINAPI HANDLE wine32b_kernel32_PowerCreateRequest(REASON_CONTEXT* context) /* ../dlls/kernel32/powermgnt.c:119 */
{
	HANDLE return_value;
	TRACE("Enter PowerCreateRequest\n");
	return_value = pPowerCreateRequest(context);
	TRACE("Leave PowerCreateRequest\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_PowerSetRequest(HANDLE request, POWER_REQUEST_TYPE type) /* ../dlls/kernel32/powermgnt.c:156 */
{
	BOOL return_value;
	TRACE("Enter PowerSetRequest\n");
	return_value = pPowerSetRequest(request, type);
	TRACE("Leave PowerSetRequest\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_PrepareTape(HANDLE device, DWORD operation, BOOL immediate) /* ../dlls/kernel32/tape.c:227 */
{
	DWORD return_value;
	TRACE("Enter PrepareTape\n");
	return_value = pPrepareTape(device, operation, immediate);
	TRACE("Leave PrepareTape\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Process32First(HANDLE hSnapshot, LPPROCESSENTRY32 lppe) /* ../dlls/kernel32/toolhelp.c:456 */
{
	BOOL return_value;
	TRACE("Enter Process32First\n");
	return_value = pProcess32First(hSnapshot, lppe);
	TRACE("Leave Process32First\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Process32FirstW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe) /* ../dlls/kernel32/toolhelp.c:476 */
{
	BOOL return_value;
	TRACE("Enter Process32FirstW\n");
	return_value = pProcess32FirstW(hSnapshot, lppe);
	TRACE("Leave Process32FirstW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Process32Next(HANDLE hSnapshot, LPPROCESSENTRY32 lppe) /* ../dlls/kernel32/toolhelp.c:466 */
{
	BOOL return_value;
	TRACE("Enter Process32Next\n");
	return_value = pProcess32Next(hSnapshot, lppe);
	TRACE("Leave Process32Next\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Process32NextW(HANDLE hSnapshot, LPPROCESSENTRY32W lppe) /* ../dlls/kernel32/toolhelp.c:486 */
{
	BOOL return_value;
	TRACE("Enter Process32NextW\n");
	return_value = pProcess32NextW(hSnapshot, lppe);
	TRACE("Leave Process32NextW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ProcessIdToSessionId(DWORD procid, DWORD* sessionid_ptr) /* ../dlls/kernel32/process.c:3777 */
{
	BOOL return_value;
	TRACE("Enter ProcessIdToSessionId\n");
	return_value = pProcessIdToSessionId(procid, sessionid_ptr);
	TRACE("Leave ProcessIdToSessionId\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_QueryDosDeviceA(LPCSTR devname, LPSTR target, DWORD bufsize) /* ../dlls/kernel32/volume.c:1319 */
{
	DWORD return_value;
	TRACE("Enter QueryDosDeviceA\n");
	return_value = pQueryDosDeviceA(devname, target, bufsize);
	TRACE("Leave QueryDosDeviceA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_QueryDosDeviceW(LPCWSTR devname, LPWSTR target, DWORD bufsize) /* ../dlls/kernel32/volume.c:1228 */
{
	DWORD return_value;
	TRACE("Enter QueryDosDeviceW\n");
	return_value = pQueryDosDeviceW(devname, target, bufsize);
	TRACE("Leave QueryDosDeviceW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryFullProcessImageNameA(HANDLE hProcess, DWORD dwFlags, LPSTR lpExeName, PDWORD pdwSize) /* ../dlls/kernel32/process.c:3534 */
{
	BOOL return_value;
	TRACE("Enter QueryFullProcessImageNameA\n");
	return_value = pQueryFullProcessImageNameA(hProcess, dwFlags, lpExeName, pdwSize);
	TRACE("Leave QueryFullProcessImageNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryFullProcessImageNameW(HANDLE hProcess, DWORD dwFlags, LPWSTR lpExeName, PDWORD pdwSize) /* ../dlls/kernel32/process.c:3555 */
{
	BOOL return_value;
	TRACE("Enter QueryFullProcessImageNameW\n");
	return_value = pQueryFullProcessImageNameW(hProcess, dwFlags, lpExeName, pdwSize);
	TRACE("Leave QueryFullProcessImageNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryInformationJobObject(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len, DWORD* ret_len) /* ../dlls/kernel32/sync.c:357 */
{
	BOOL return_value;
	TRACE("Enter QueryInformationJobObject\n");
	return_value = pQueryInformationJobObject(job, class, info, len, ret_len);
	TRACE("Leave QueryInformationJobObject\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryProcessCycleTime(HANDLE process, PULONG64 cycle) /* ../dlls/kernel32/time.c:1530 */
{
	BOOL return_value;
	TRACE("Enter QueryProcessCycleTime\n");
	return_value = pQueryProcessCycleTime(process, cycle);
	TRACE("Leave QueryProcessCycleTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryThreadCycleTime(HANDLE thread, PULONG64 cycle) /* ../dlls/kernel32/time.c:1542 */
{
	BOOL return_value;
	TRACE("Enter QueryThreadCycleTime\n");
	return_value = pQueryThreadCycleTime(thread, cycle);
	TRACE("Leave QueryThreadCycleTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryUmsThreadInformation(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void* buf, ULONG length, ULONG* ret_length) /* ../dlls/kernel32/process.c:4226 */
{
	BOOL return_value;
	TRACE("Enter QueryUmsThreadInformation\n");
	return_value = pQueryUmsThreadInformation(ctx, class, buf, length, ret_length);
	TRACE("Leave QueryUmsThreadInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_QueryUnbiasedInterruptTime(ULONGLONG* time) /* ../dlls/kernel32/time.c:1554 */
{
	BOOL return_value;
	TRACE("Enter QueryUnbiasedInterruptTime\n");
	return_value = pQueryUnbiasedInterruptTime(time);
	TRACE("Leave QueryUnbiasedInterruptTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ReadConsoleInputW(HANDLE hConsoleInput, PINPUT_RECORD lpBuffer, DWORD nLength, LPDWORD lpNumberOfEventsRead) /* ../dlls/kernel32/console.c:807 */
{
	BOOL return_value;
	TRACE("Enter ReadConsoleInputW\n");
	return_value = pReadConsoleInputW(hConsoleInput, lpBuffer, nLength, lpNumberOfEventsRead);
	TRACE("Leave ReadConsoleInputW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ReadConsoleW(HANDLE hConsoleInput, LPVOID lpBuffer, DWORD nNumberOfCharsToRead, LPDWORD lpNumberOfCharsRead, LPVOID lpReserved) /* ../dlls/kernel32/console.c:732 */
{
	BOOL return_value;
	TRACE("Enter ReadConsoleW\n");
	return_value = pReadConsoleW(hConsoleInput, lpBuffer, nNumberOfCharsToRead, lpNumberOfCharsRead, lpReserved);
	TRACE("Leave ReadConsoleW\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_RegisterApplicationRecoveryCallback(APPLICATION_RECOVERY_CALLBACK callback, PVOID param, DWORD pingint, DWORD flags) /* ../dlls/kernel32/process.c:3956 */
{
	HRESULT return_value;
	TRACE("Enter RegisterApplicationRecoveryCallback\n");
	return_value = pRegisterApplicationRecoveryCallback(callback, param, pingint, flags);
	TRACE("Leave RegisterApplicationRecoveryCallback\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_RegisterApplicationRestart(PCWSTR pwzCommandLine, DWORD dwFlags) /* ../dlls/kernel32/process.c:3897 */
{
	HRESULT return_value;
	TRACE("Enter RegisterApplicationRestart\n");
	return_value = pRegisterApplicationRestart(pwzCommandLine, dwFlags);
	TRACE("Leave RegisterApplicationRestart\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_RegisterServiceProcess(DWORD dwProcessId, DWORD dwType) /* ../dlls/kernel32/process.c:3793 */
{
	DWORD return_value;
	TRACE("Enter RegisterServiceProcess\n");
	return_value = pRegisterServiceProcess(dwProcessId, dwType);
	TRACE("Leave RegisterServiceProcess\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_RegisterWaitForSingleObject(PHANDLE phNewWaitObject, HANDLE hObject, WAITORTIMERCALLBACK Callback, PVOID Context, ULONG dwMilliseconds, ULONG dwFlags) /* ../dlls/kernel32/sync.c:107 */
{
	BOOL return_value;
	TRACE("Enter RegisterWaitForSingleObject\n");
	return_value = pRegisterWaitForSingleObject(phNewWaitObject, hObject, Callback, Context, dwMilliseconds, dwFlags);
	TRACE("Leave RegisterWaitForSingleObject\n");
	return return_value;
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

WINAPI void wine32b_kernel32_ReinitializeCriticalSection(CRITICAL_SECTION* crit) /* ../dlls/kernel32/sync.c:170 */
{
	TRACE("Enter ReinitializeCriticalSection\n");
	pReinitializeCriticalSection(crit);
	TRACE("Leave ReinitializeCriticalSection\n");
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

WINAPI BOOL wine32b_kernel32_RemoveDirectoryA(LPCSTR path) /* ../dlls/kernel32/path.c:1680 */
{
	BOOL return_value;
	TRACE("Enter RemoveDirectoryA\n");
	return_value = pRemoveDirectoryA(path);
	TRACE("Leave RemoveDirectoryA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_RemoveDirectoryW(LPCWSTR path) /* ../dlls/kernel32/path.c:1627 */
{
	BOOL return_value;
	TRACE("Enter RemoveDirectoryW\n");
	return_value = pRemoveDirectoryW(path);
	TRACE("Leave RemoveDirectoryW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_RemoveDllDirectory(DLL_DIRECTORY_COOKIE cookie) /* ../dlls/kernel32/module.c:201 */
{
	BOOL return_value;
	TRACE("Enter RemoveDllDirectory\n");
	return_value = pRemoveDllDirectory(cookie);
	TRACE("Leave RemoveDllDirectory\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ReplaceFileA(LPCSTR lpReplacedFileName, LPCSTR lpReplacementFileName, LPCSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) /* ../dlls/kernel32/file.c:612 */
{
	BOOL return_value;
	TRACE("Enter ReplaceFileA\n");
	return_value = pReplaceFileA(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
	TRACE("Leave ReplaceFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_ReplaceFileW(LPCWSTR lpReplacedFileName, LPCWSTR lpReplacementFileName, LPCWSTR lpBackupFileName, DWORD dwReplaceFlags, LPVOID lpExclude, LPVOID lpReserved) /* ../dlls/kernel32/file.c:425 */
{
	BOOL return_value;
	TRACE("Enter ReplaceFileW\n");
	return_value = pReplaceFileW(lpReplacedFileName, lpReplacementFileName, lpBackupFileName, dwReplaceFlags, lpExclude, lpReserved);
	TRACE("Leave ReplaceFileW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_RequestDeviceWakeup(HANDLE device) /* ../dlls/kernel32/powermgnt.c:84 */
{
	BOOL return_value;
	TRACE("Enter RequestDeviceWakeup\n");
	return_value = pRequestDeviceWakeup(device);
	TRACE("Leave RequestDeviceWakeup\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_RequestWakeupLatency(LATENCY_TIME latency) /* ../dlls/kernel32/powermgnt.c:75 */
{
	BOOL return_value;
	TRACE("Enter RequestWakeupLatency\n");
	return_value = pRequestWakeupLatency(latency);
	TRACE("Leave RequestWakeupLatency\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_ResolveLocaleName(LPCWSTR name, LPWSTR localename, INT len) /* ../dlls/kernel32/locale.c:5898 */
{
	INT return_value;
	TRACE("Enter ResolveLocaleName\n");
	return_value = pResolveLocaleName(name, localename, len);
	TRACE("Leave ResolveLocaleName\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SearchPathA(LPCSTR path, LPCSTR name, LPCSTR ext, DWORD buflen, LPSTR buffer, LPSTR* lastpart) /* ../dlls/kernel32/path.c:1081 */
{
	DWORD return_value;
	TRACE("Enter SearchPathA\n");
	return_value = pSearchPathA(path, name, ext, buflen, buffer, lastpart);
	TRACE("Leave SearchPathA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SearchPathW(LPCWSTR path, LPCWSTR name, LPCWSTR ext, DWORD buflen, LPWSTR buffer, LPWSTR* lastpart) /* ../dlls/kernel32/path.c:950 */
{
	DWORD return_value;
	TRACE("Enter SearchPathW\n");
	return_value = pSearchPathW(path, name, ext, buflen, buffer, lastpart);
	TRACE("Leave SearchPathW\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_SetCPGlobal(UINT acp) /* ../dlls/kernel32/locale.c:2027 */
{
	UINT return_value;
	TRACE("Enter SetCPGlobal\n");
	return_value = pSetCPGlobal(acp);
	TRACE("Leave SetCPGlobal\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_SetCalendarInfoA(LCID Locale, CALID Calendar, CALTYPE CalType, LPCSTR lpCalData) /* ../dlls/kernel32/time.c:1154 */
{
	INT return_value;
	TRACE("Enter SetCalendarInfoA\n");
	return_value = pSetCalendarInfoA(Locale, Calendar, CalType, lpCalData);
	TRACE("Leave SetCalendarInfoA\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_SetCalendarInfoW(LCID Locale, CALID Calendar, CALTYPE CalType, LPCWSTR lpCalData) /* ../dlls/kernel32/time.c:1166 */
{
	INT return_value;
	TRACE("Enter SetCalendarInfoW\n");
	return_value = pSetCalendarInfoW(Locale, Calendar, CalType, lpCalData);
	TRACE("Leave SetCalendarInfoW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetComputerNameA(LPCSTR lpComputerName) /* ../dlls/kernel32/computername.c:628 */
{
	BOOL return_value;
	TRACE("Enter SetComputerNameA\n");
	return_value = pSetComputerNameA(lpComputerName);
	TRACE("Leave SetComputerNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetComputerNameExA(COMPUTER_NAME_FORMAT type, LPCSTR lpComputerName) /* ../dlls/kernel32/computername.c:662 */
{
	BOOL return_value;
	TRACE("Enter SetComputerNameExA\n");
	return_value = pSetComputerNameExA(type, lpComputerName);
	TRACE("Leave SetComputerNameExA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetComputerNameExW(COMPUTER_NAME_FORMAT type, LPCWSTR lpComputerName) /* ../dlls/kernel32/computername.c:644 */
{
	BOOL return_value;
	TRACE("Enter SetComputerNameExW\n");
	return_value = pSetComputerNameExW(type, lpComputerName);
	TRACE("Leave SetComputerNameExW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetComputerNameW(LPCWSTR lpComputerName) /* ../dlls/kernel32/computername.c:560 */
{
	BOOL return_value;
	TRACE("Enter SetComputerNameW\n");
	return_value = pSetComputerNameW(lpComputerName);
	TRACE("Leave SetComputerNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleCtrlHandler(PHANDLER_ROUTINE func, BOOL add) /* ../dlls/kernel32/console.c:878 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleCtrlHandler\n");
	return_value = pSetConsoleCtrlHandler(func, add);
	TRACE("Leave SetConsoleCtrlHandler\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleDisplayMode(HANDLE hConsoleOutput, DWORD dwFlags, COORD* lpNewScreenBufferDimensions) /* ../dlls/kernel32/console.c:1294 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleDisplayMode\n");
	return_value = pSetConsoleDisplayMode(hConsoleOutput, dwFlags, lpNewScreenBufferDimensions);
	TRACE("Leave SetConsoleDisplayMode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleFont(HANDLE hConsole, DWORD index) /* ../dlls/kernel32/console.c:1627 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleFont\n");
	return_value = pSetConsoleFont(hConsole, index);
	TRACE("Leave SetConsoleFont\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleIcon(HICON icon) /* ../dlls/kernel32/console.c:1615 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleIcon\n");
	return_value = pSetConsoleIcon(icon);
	TRACE("Leave SetConsoleIcon\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleKeyShortcuts(BOOL set, BYTE keys, void* a, DWORD b) /* ../dlls/kernel32/console.c:1634 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleKeyShortcuts\n");
	return_value = pSetConsoleKeyShortcuts(set, keys, a, b);
	TRACE("Leave SetConsoleKeyShortcuts\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetConsoleTitleA(LPCSTR title) /* ../dlls/kernel32/console.c:478 */
{
	BOOL return_value;
	TRACE("Enter SetConsoleTitleA\n");
	return_value = pSetConsoleTitleA(title);
	TRACE("Leave SetConsoleTitleA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetCurrentConsoleFontEx(HANDLE hConsole, BOOL maxwindow, CONSOLE_FONT_INFOEX* cfix) /* ../dlls/kernel32/console.c:1718 */
{
	BOOL return_value;
	TRACE("Enter SetCurrentConsoleFontEx\n");
	return_value = pSetCurrentConsoleFontEx(hConsole, maxwindow, cfix);
	TRACE("Leave SetCurrentConsoleFontEx\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetCurrentDirectoryA(LPCSTR dir) /* ../dlls/kernel32/path.c:1746 */
{
	BOOL return_value;
	TRACE("Enter SetCurrentDirectoryA\n");
	return_value = pSetCurrentDirectoryA(dir);
	TRACE("Leave SetCurrentDirectoryA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetCurrentDirectoryW(LPCWSTR dir) /* ../dlls/kernel32/path.c:1731 */
{
	BOOL return_value;
	TRACE("Enter SetCurrentDirectoryW\n");
	return_value = pSetCurrentDirectoryW(dir);
	TRACE("Leave SetCurrentDirectoryW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetDefaultCommConfigA(LPCSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize) /* ../dlls/kernel32/comm.c:664 */
{
	BOOL return_value;
	TRACE("Enter SetDefaultCommConfigA\n");
	return_value = pSetDefaultCommConfigA(lpszDevice, lpCommConfig, dwSize);
	TRACE("Leave SetDefaultCommConfigA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetDefaultCommConfigW(LPCWSTR lpszDevice, LPCOMMCONFIG lpCommConfig, DWORD dwSize) /* ../dlls/kernel32/comm.c:634 */
{
	BOOL return_value;
	TRACE("Enter SetDefaultCommConfigW\n");
	return_value = pSetDefaultCommConfigW(lpszDevice, lpCommConfig, dwSize);
	TRACE("Leave SetDefaultCommConfigW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetDefaultDllDirectories(DWORD flags) /* ../dlls/kernel32/module.c:218 */
{
	BOOL return_value;
	TRACE("Enter SetDefaultDllDirectories\n");
	return_value = pSetDefaultDllDirectories(flags);
	TRACE("Leave SetDefaultDllDirectories\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetDllDirectoryA(LPCSTR dir) /* ../dlls/kernel32/module.c:131 */
{
	BOOL return_value;
	TRACE("Enter SetDllDirectoryA\n");
	return_value = pSetDllDirectoryA(dir);
	TRACE("Leave SetDllDirectoryA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetDllDirectoryW(LPCWSTR dir) /* ../dlls/kernel32/module.c:146 */
{
	BOOL return_value;
	TRACE("Enter SetDllDirectoryW\n");
	return_value = pSetDllDirectoryW(dir);
	TRACE("Leave SetDllDirectoryW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetFileCompletionNotificationModes(HANDLE file, UCHAR flags) /* ../dlls/kernel32/file.c:393 */
{
	BOOL return_value;
	TRACE("Enter SetFileCompletionNotificationModes\n");
	return_value = pSetFileCompletionNotificationModes(file, flags);
	TRACE("Leave SetFileCompletionNotificationModes\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetHandleContext(HANDLE hnd, DWORD context) /* ../dlls/kernel32/process.c:3350 */
{
	BOOL return_value;
	TRACE("Enter SetHandleContext\n");
	return_value = pSetHandleContext(hnd, context);
	TRACE("Leave SetHandleContext\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_SetHandleCount(UINT count) /* ../dlls/kernel32/file.c:410 */
{
	UINT return_value;
	TRACE("Enter SetHandleCount\n");
	return_value = pSetHandleCount(count);
	TRACE("Leave SetHandleCount\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetHandleInformation(HANDLE handle, DWORD mask, DWORD flags) /* ../dlls/kernel32/process.c:3281 */
{
	BOOL return_value;
	TRACE("Enter SetHandleInformation\n");
	return_value = pSetHandleInformation(handle, mask, flags);
	TRACE("Leave SetHandleInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetInformationJobObject(HANDLE job, JOBOBJECTINFOCLASS class, LPVOID info, DWORD len) /* ../dlls/kernel32/sync.c:368 */
{
	BOOL return_value;
	TRACE("Enter SetInformationJobObject\n");
	return_value = pSetInformationJobObject(job, class, info, len);
	TRACE("Leave SetInformationJobObject\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetLocalTime(SYSTEMTIME* systime) /* ../dlls/kernel32/time.c:531 */
{
	BOOL return_value;
	TRACE("Enter SetLocalTime\n");
	return_value = pSetLocalTime(systime);
	TRACE("Leave SetLocalTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetLocaleInfoA(LCID lcid, LCTYPE lctype, LPCSTR data) /* ../dlls/kernel32/locale.c:1878 */
{
	BOOL return_value;
	TRACE("Enter SetLocaleInfoA\n");
	return_value = pSetLocaleInfoA(lcid, lctype, data);
	TRACE("Leave SetLocaleInfoA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetLocaleInfoW(LCID lcid, LCTYPE lctype, LPCWSTR data) /* ../dlls/kernel32/locale.c:1910 */
{
	BOOL return_value;
	TRACE("Enter SetLocaleInfoW\n");
	return_value = pSetLocaleInfoW(lcid, lctype, data);
	TRACE("Leave SetLocaleInfoW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetMailslotInfo(HANDLE hMailslot, DWORD dwReadTimeout) /* ../dlls/kernel32/sync.c:973 */
{
	BOOL return_value;
	TRACE("Enter SetMailslotInfo\n");
	return_value = pSetMailslotInfo(hMailslot, dwReadTimeout);
	TRACE("Leave SetMailslotInfo\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetProcessAffinityMask(HANDLE hProcess, DWORD_PTR affmask) /* ../dlls/kernel32/process.c:3386 */
{
	BOOL return_value;
	TRACE("Enter SetProcessAffinityMask\n");
	return_value = pSetProcessAffinityMask(hProcess, affmask);
	TRACE("Leave SetProcessAffinityMask\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetProcessDEPPolicy(DWORD newDEP) /* ../dlls/kernel32/process.c:3927 */
{
	BOOL return_value;
	TRACE("Enter SetProcessDEPPolicy\n");
	return_value = pSetProcessDEPPolicy(newDEP);
	TRACE("Leave SetProcessDEPPolicy\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetProcessPreferredUILanguages(DWORD flags, PCZZWSTR buffer, PULONG count) /* ../dlls/kernel32/locale.c:1324 */
{
	BOOL return_value;
	TRACE("Enter SetProcessPreferredUILanguages\n");
	return_value = pSetProcessPreferredUILanguages(flags, buffer, count);
	TRACE("Leave SetProcessPreferredUILanguages\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetProcessWorkingSetSize(HANDLE process, SIZE_T minset, SIZE_T maxset) /* ../dlls/kernel32/process.c:3495 */
{
	BOOL return_value;
	TRACE("Enter SetProcessWorkingSetSize\n");
	return_value = pSetProcessWorkingSetSize(process, minset, maxset);
	TRACE("Leave SetProcessWorkingSetSize\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetSearchPathMode(DWORD flags) /* ../dlls/kernel32/path.c:2024 */
{
	BOOL return_value;
	TRACE("Enter SetSearchPathMode\n");
	return_value = pSetSearchPathMode(flags);
	TRACE("Leave SetSearchPathMode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetSystemFileCacheSize(SIZE_T mincache, SIZE_T maxcache, DWORD flags) /* ../dlls/kernel32/heap.c:922 */
{
	BOOL return_value;
	TRACE("Enter SetSystemFileCacheSize\n");
	return_value = pSetSystemFileCacheSize(mincache, maxcache, flags);
	TRACE("Leave SetSystemFileCacheSize\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetSystemPowerState(BOOL suspend_or_hibernate, BOOL force_flag) /* ../dlls/kernel32/powermgnt.c:94 */
{
	BOOL return_value;
	TRACE("Enter SetSystemPowerState\n");
	return_value = pSetSystemPowerState(suspend_or_hibernate, force_flag);
	TRACE("Leave SetSystemPowerState\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetSystemTime(SYSTEMTIME* systime) /* ../dlls/kernel32/time.c:589 */
{
	BOOL return_value;
	TRACE("Enter SetSystemTime\n");
	return_value = pSetSystemTime(systime);
	TRACE("Leave SetSystemTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetSystemTimeAdjustment(DWORD dwTimeAdjustment, BOOL bTimeAdjustmentDisabled) /* ../dlls/kernel32/time.c:617 */
{
	BOOL return_value;
	TRACE("Enter SetSystemTimeAdjustment\n");
	return_value = pSetSystemTimeAdjustment(dwTimeAdjustment, bTimeAdjustmentDisabled);
	TRACE("Leave SetSystemTimeAdjustment\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SetTapeParameters(HANDLE device, DWORD operation, LPVOID info) /* ../dlls/kernel32/tape.c:250 */
{
	DWORD return_value;
	TRACE("Enter SetTapeParameters\n");
	return_value = pSetTapeParameters(device, operation, info);
	TRACE("Leave SetTapeParameters\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SetTapePosition(HANDLE device, DWORD method, DWORD partition, DWORD offset_low, DWORD offset_high, BOOL immediate) /* ../dlls/kernel32/tape.c:282 */
{
	DWORD return_value;
	TRACE("Enter SetTapePosition\n");
	return_value = pSetTapePosition(device, method, partition, offset_low, offset_high, immediate);
	TRACE("Leave SetTapePosition\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SetTermsrvAppInstallMode(BOOL bInstallMode) /* ../dlls/kernel32/version.c:107 */
{
	DWORD return_value;
	TRACE("Enter SetTermsrvAppInstallMode\n");
	return_value = pSetTermsrvAppInstallMode(bInstallMode);
	TRACE("Leave SetTermsrvAppInstallMode\n");
	return return_value;
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

WINAPI DWORD_PTR wine32b_kernel32_SetThreadAffinityMask(HANDLE hThread, DWORD_PTR dwThreadAffinityMask) /* ../dlls/kernel32/thread.c:83 */
{
	DWORD_PTR return_value;
	TRACE("Enter SetThreadAffinityMask\n");
	return_value = pSetThreadAffinityMask(hThread, dwThreadAffinityMask);
	TRACE("Leave SetThreadAffinityMask\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_SetThreadExecutionState(EXECUTION_STATE flags) /* ../dlls/kernel32/powermgnt.c:107 */
{
	DWORD return_value;
	TRACE("Enter SetThreadExecutionState\n");
	return_value = pSetThreadExecutionState(flags);
	TRACE("Leave SetThreadExecutionState\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetThreadLocale(LCID lcid) /* ../dlls/kernel32/locale.c:2812 */
{
	BOOL return_value;
	TRACE("Enter SetThreadLocale\n");
	return_value = pSetThreadLocale(lcid);
	TRACE("Leave SetThreadLocale\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetThreadPreferredUILanguages(DWORD flags, PCZZWSTR buffer, PULONG count) /* ../dlls/kernel32/locale.c:1333 */
{
	BOOL return_value;
	TRACE("Enter SetThreadPreferredUILanguages\n");
	return_value = pSetThreadPreferredUILanguages(flags, buffer, count);
	TRACE("Leave SetThreadPreferredUILanguages\n");
	return return_value;
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

WINAPI LANGID wine32b_kernel32_SetThreadUILanguage(LANGID langid) /* ../dlls/kernel32/locale.c:2846 */
{
	LANGID return_value;
	TRACE("Enter SetThreadUILanguage\n");
	return_value = pSetThreadUILanguage(langid);
	TRACE("Leave SetThreadUILanguage\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetTimeZoneInformation(TIME_ZONE_INFORMATION* tzinfo) /* ../dlls/kernel32/time.c:686 */
{
	BOOL return_value;
	TRACE("Enter SetTimeZoneInformation\n");
	return_value = pSetTimeZoneInformation(tzinfo);
	TRACE("Leave SetTimeZoneInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetUmsThreadInformation(PUMS_CONTEXT ctx, UMS_THREAD_INFO_CLASS class, void* buf, ULONG length) /* ../dlls/kernel32/process.c:4237 */
{
	BOOL return_value;
	TRACE("Enter SetUmsThreadInformation\n");
	return_value = pSetUmsThreadInformation(ctx, class, buf, length);
	TRACE("Leave SetUmsThreadInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetUserGeoID(GEOID GeoID) /* ../dlls/kernel32/locale.c:4648 */
{
	BOOL return_value;
	TRACE("Enter SetUserGeoID\n");
	return_value = pSetUserGeoID(GeoID);
	TRACE("Leave SetUserGeoID\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetVolumeLabelA(LPCSTR root, LPCSTR volname) /* ../dlls/kernel32/volume.c:965 */
{
	BOOL return_value;
	TRACE("Enter SetVolumeLabelA\n");
	return_value = pSetVolumeLabelA(root, volname);
	TRACE("Leave SetVolumeLabelA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetVolumeLabelW(LPCWSTR root, LPCWSTR label) /* ../dlls/kernel32/volume.c:872 */
{
	BOOL return_value;
	TRACE("Enter SetVolumeLabelW\n");
	return_value = pSetVolumeLabelW(root, label);
	TRACE("Leave SetVolumeLabelW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetVolumeMountPointA(LPCSTR path, LPCSTR volume) /* ../dlls/kernel32/volume.c:2144 */
{
	BOOL return_value;
	TRACE("Enter SetVolumeMountPointA\n");
	return_value = pSetVolumeMountPointA(path, volume);
	TRACE("Leave SetVolumeMountPointA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SetVolumeMountPointW(LPCWSTR path, LPCWSTR volume) /* ../dlls/kernel32/volume.c:2154 */
{
	BOOL return_value;
	TRACE("Enter SetVolumeMountPointW\n");
	return_value = pSetVolumeMountPointW(path, volume);
	TRACE("Leave SetVolumeMountPointW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SystemTimeToFileTime(SYSTEMTIME* syst, LPFILETIME ft) /* ../dlls/kernel32/time.c:1239 */
{
	BOOL return_value;
	TRACE("Enter SystemTimeToFileTime\n");
	return_value = pSystemTimeToFileTime(syst, ft);
	TRACE("Leave SystemTimeToFileTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_SystemTimeToTzSpecificLocalTime(TIME_ZONE_INFORMATION* lpTimeZoneInformation, SYSTEMTIME* lpUniversalTime, LPSYSTEMTIME lpLocalTime) /* ../dlls/kernel32/time.c:712 */
{
	BOOL return_value;
	TRACE("Enter SystemTimeToTzSpecificLocalTime\n");
	return_value = pSystemTimeToTzSpecificLocalTime(lpTimeZoneInformation, lpUniversalTime, lpLocalTime);
	TRACE("Leave SystemTimeToTzSpecificLocalTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_TerminateJobObject(HANDLE job, UINT exit_code) /* ../dlls/kernel32/sync.c:347 */
{
	BOOL return_value;
	TRACE("Enter TerminateJobObject\n");
	return_value = pTerminateJobObject(job, exit_code);
	TRACE("Leave TerminateJobObject\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_TermsrvAppInstallMode(void) /* ../dlls/kernel32/version.c:91 */
{
	BOOL return_value;
	TRACE("Enter TermsrvAppInstallMode\n");
	return_value = pTermsrvAppInstallMode();
	TRACE("Leave TermsrvAppInstallMode\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Thread32First(HANDLE hSnapShot, LPTHREADENTRY32 lpte) /* ../dlls/kernel32/toolhelp.c:382 */
{
	BOOL return_value;
	TRACE("Enter Thread32First\n");
	return_value = pThread32First(hSnapShot, lpte);
	TRACE("Leave Thread32First\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Thread32Next(HANDLE hSnapShot, LPTHREADENTRY32 lpte) /* ../dlls/kernel32/toolhelp.c:392 */
{
	BOOL return_value;
	TRACE("Enter Thread32Next\n");
	return_value = pThread32Next(hSnapShot, lpte);
	TRACE("Leave Thread32Next\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Toolhelp32ReadProcessMemory(DWORD pid, void* base, void* buf, SIZE_T len, SIZE_T* r) /* ../dlls/kernel32/toolhelp.c:611 */
{
	BOOL return_value;
	TRACE("Enter Toolhelp32ReadProcessMemory\n");
	return_value = pToolhelp32ReadProcessMemory(pid, base, buf, len, r);
	TRACE("Leave Toolhelp32ReadProcessMemory\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_TzSpecificLocalTimeToSystemTime(TIME_ZONE_INFORMATION* lpTimeZoneInformation, SYSTEMTIME* lpLocalTime, LPSYSTEMTIME lpUniversalTime) /* ../dlls/kernel32/time.c:757 */
{
	BOOL return_value;
	TRACE("Enter TzSpecificLocalTimeToSystemTime\n");
	return_value = pTzSpecificLocalTimeToSystemTime(lpTimeZoneInformation, lpLocalTime, lpUniversalTime);
	TRACE("Leave TzSpecificLocalTimeToSystemTime\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_UmsThreadYield(void* param) /* ../dlls/kernel32/process.c:4248 */
{
	BOOL return_value;
	TRACE("Enter UmsThreadYield\n");
	return_value = pUmsThreadYield(param);
	TRACE("Leave UmsThreadYield\n");
	return return_value;
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

WINAPI void wine32b_kernel32_UninitializeCriticalSection(CRITICAL_SECTION* crit) /* ../dlls/kernel32/sync.c:188 */
{
	TRACE("Enter UninitializeCriticalSection\n");
	pUninitializeCriticalSection(crit);
	TRACE("Leave UninitializeCriticalSection\n");
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

WINAPI HRESULT wine32b_kernel32_UnregisterApplicationRestart(void) /* ../dlls/kernel32/process.c:4116 */
{
	HRESULT return_value;
	TRACE("Enter UnregisterApplicationRestart\n");
	return_value = pUnregisterApplicationRestart();
	TRACE("Leave UnregisterApplicationRestart\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_UnregisterWait(HANDLE WaitHandle) /* ../dlls/kernel32/sync.c:129 */
{
	BOOL return_value;
	TRACE("Enter UnregisterWait\n");
	return_value = pUnregisterWait(WaitHandle);
	TRACE("Leave UnregisterWait\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_UpdateResourceA(HANDLE hUpdate, LPCSTR lpType, LPCSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData) /* ../dlls/kernel32/resource.c:1321 */
{
	BOOL return_value;
	TRACE("Enter UpdateResourceA\n");
	return_value = pUpdateResourceA(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
	TRACE("Leave UpdateResourceA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_UpdateResourceW(HANDLE hUpdate, LPCWSTR lpType, LPCWSTR lpName, WORD wLanguage, LPVOID lpData, DWORD cbData) /* ../dlls/kernel32/resource.c:1289 */
{
	BOOL return_value;
	TRACE("Enter UpdateResourceW\n");
	return_value = pUpdateResourceW(hUpdate, lpType, lpName, wLanguage, lpData, cbData);
	TRACE("Leave UpdateResourceW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_VerLanguageNameA(DWORD wLang, LPSTR szLang, DWORD nSize) /* ../dlls/kernel32/locale.c:3065 */
{
	DWORD return_value;
	TRACE("Enter VerLanguageNameA\n");
	return_value = pVerLanguageNameA(wLang, szLang, nSize);
	TRACE("Leave VerLanguageNameA\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_VerLanguageNameW(DWORD wLang, LPWSTR szLang, DWORD nSize) /* ../dlls/kernel32/locale.c:3076 */
{
	DWORD return_value;
	TRACE("Enter VerLanguageNameW\n");
	return_value = pVerLanguageNameW(wLang, szLang, nSize);
	TRACE("Leave VerLanguageNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_VerifyConsoleIoHandle(HANDLE handle) /* ../dlls/kernel32/console.c:255 */
{
	BOOL return_value;
	TRACE("Enter VerifyConsoleIoHandle\n");
	return_value = pVerifyConsoleIoHandle(handle);
	TRACE("Leave VerifyConsoleIoHandle\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask) /* ../dlls/kernel32/version.c:48 */
{
	BOOL return_value;
	TRACE("Enter VerifyVersionInfoA\n");
	return_value = pVerifyVersionInfoA(lpVersionInfo, dwTypeMask, dwlConditionMask);
	TRACE("Leave VerifyVersionInfoA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInfo, DWORD dwTypeMask, DWORDLONG dwlConditionMask) /* ../dlls/kernel32/version.c:71 */
{
	BOOL return_value;
	TRACE("Enter VerifyVersionInfoW\n");
	return_value = pVerifyVersionInfoW(lpVersionInfo, dwTypeMask, dwlConditionMask);
	TRACE("Leave VerifyVersionInfoW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_WTSGetActiveConsoleSessionId(void) /* ../dlls/kernel32/process.c:3907 */
{
	DWORD return_value;
	TRACE("Enter WTSGetActiveConsoleSessionId\n");
	return_value = pWTSGetActiveConsoleSessionId();
	TRACE("Leave WTSGetActiveConsoleSessionId\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WaitNamedPipeA(LPCSTR name, DWORD nTimeOut) /* ../dlls/kernel32/sync.c:548 */
{
	BOOL return_value;
	TRACE("Enter WaitNamedPipeA\n");
	return_value = pWaitNamedPipeA(name, nTimeOut);
	TRACE("Leave WaitNamedPipeA\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerRegisterFile(PCWSTR file, WER_REGISTER_FILE_TYPE regfiletype, DWORD flags) /* ../dlls/kernel32/wer.c:37 */
{
	HRESULT return_value;
	TRACE("Enter WerRegisterFile\n");
	return_value = pWerRegisterFile(file, regfiletype, flags);
	TRACE("Leave WerRegisterFile\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerRegisterMemoryBlock(void* block, DWORD size) /* ../dlls/kernel32/wer.c:70 */
{
	HRESULT return_value;
	TRACE("Enter WerRegisterMemoryBlock\n");
	return_value = pWerRegisterMemoryBlock(block, size);
	TRACE("Leave WerRegisterMemoryBlock\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerRegisterRuntimeExceptionModule(PCWSTR callbackdll, PVOID context) /* ../dlls/kernel32/wer.c:49 */
{
	HRESULT return_value;
	TRACE("Enter WerRegisterRuntimeExceptionModule\n");
	return_value = pWerRegisterRuntimeExceptionModule(callbackdll, context);
	TRACE("Leave WerRegisterRuntimeExceptionModule\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerSetFlags(DWORD flags) /* ../dlls/kernel32/wer.c:61 */
{
	HRESULT return_value;
	TRACE("Enter WerSetFlags\n");
	return_value = pWerSetFlags(flags);
	TRACE("Leave WerSetFlags\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerUnregisterMemoryBlock(void* block) /* ../dlls/kernel32/wer.c:79 */
{
	HRESULT return_value;
	TRACE("Enter WerUnregisterMemoryBlock\n");
	return_value = pWerUnregisterMemoryBlock(block);
	TRACE("Leave WerUnregisterMemoryBlock\n");
	return return_value;
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

WINAPI HRESULT wine32b_kernel32_WerUnregisterRuntimeExceptionModule(PCWSTR callbackdll, PVOID context) /* ../dlls/kernel32/wer.c:88 */
{
	HRESULT return_value;
	TRACE("Enter WerUnregisterRuntimeExceptionModule\n");
	return_value = pWerUnregisterRuntimeExceptionModule(callbackdll, context);
	TRACE("Leave WerUnregisterRuntimeExceptionModule\n");
	return return_value;
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

WINAPI INT wine32b_kernel32_WideCharToMultiByte(UINT page, DWORD flags, LPCWSTR src, INT srclen, LPSTR dst, INT dstlen, LPCSTR defchar, BOOL* used) /* ../dlls/kernel32/locale.c:2680 */
{
	INT return_value;
	TRACE("Enter WideCharToMultiByte\n");
	return_value = pWideCharToMultiByte(page, flags, src, srclen, dst, dstlen, defchar, used);
	TRACE("Leave WideCharToMultiByte\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32_WinExec(LPCSTR lpCmdLine, UINT nCmdShow) /* ../dlls/kernel32/process.c:3039 */
{
	UINT return_value;
	TRACE("Enter WinExec\n");
	return_value = pWinExec(lpCmdLine, nCmdShow);
	TRACE("Leave WinExec\n");
	return return_value;
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

WINAPI BOOLEAN wine32b_kernel32_Wow64EnableWow64FsRedirection(BOOLEAN enable) /* ../dlls/kernel32/path.c:1833 */
{
	BOOLEAN return_value;
	TRACE("Enter Wow64EnableWow64FsRedirection\n");
	return_value = pWow64EnableWow64FsRedirection(enable);
	TRACE("Leave Wow64EnableWow64FsRedirection\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Wow64GetThreadContext(HANDLE handle, WOW64_CONTEXT* context) /* ../dlls/kernel32/thread.c:66 */
{
	BOOL return_value;
	TRACE("Enter Wow64GetThreadContext\n");
	return_value = pWow64GetThreadContext(handle, context);
	TRACE("Leave Wow64GetThreadContext\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_Wow64SetThreadContext(HANDLE handle, WOW64_CONTEXT* context) /* ../dlls/kernel32/thread.c:50 */
{
	BOOL return_value;
	TRACE("Enter Wow64SetThreadContext\n");
	return_value = pWow64SetThreadContext(handle, context);
	TRACE("Leave Wow64SetThreadContext\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WriteConsoleW(HANDLE hConsoleOutput, LPCVOID lpBuffer, DWORD nNumberOfCharsToWrite, LPDWORD lpNumberOfCharsWritten, LPVOID lpReserved) /* ../dlls/kernel32/console.c:1132 */
{
	BOOL return_value;
	TRACE("Enter WriteConsoleW\n");
	return_value = pWriteConsoleW(hConsoleOutput, lpBuffer, nNumberOfCharsToWrite, lpNumberOfCharsWritten, lpReserved);
	TRACE("Leave WriteConsoleW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileSectionA(LPCSTR section, LPCSTR string, LPCSTR filename) /* ../dlls/kernel32/profile.c:1465 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileSectionA\n");
	return_value = pWritePrivateProfileSectionA(section, string, filename);
	TRACE("Leave WritePrivateProfileSectionA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileSectionW(LPCWSTR section, LPCWSTR string, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1423 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileSectionW\n");
	return_value = pWritePrivateProfileSectionW(section, string, filename);
	TRACE("Leave WritePrivateProfileSectionW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string, LPCSTR filename) /* ../dlls/kernel32/profile.c:1396 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileStringA\n");
	return_value = pWritePrivateProfileStringA(section, entry, string, filename);
	TRACE("Leave WritePrivateProfileStringA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1365 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileStringW\n");
	return_value = pWritePrivateProfileStringW(section, entry, string, filename);
	TRACE("Leave WritePrivateProfileStringW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileStructA(LPCSTR section, LPCSTR key, LPVOID buf, UINT bufsize, LPCSTR filename) /* ../dlls/kernel32/profile.c:1750 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileStructA\n");
	return_value = pWritePrivateProfileStructA(section, key, buf, bufsize, filename);
	TRACE("Leave WritePrivateProfileStructA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WritePrivateProfileStructW(LPCWSTR section, LPCWSTR key, LPVOID buf, UINT bufsize, LPCWSTR filename) /* ../dlls/kernel32/profile.c:1709 */
{
	BOOL return_value;
	TRACE("Enter WritePrivateProfileStructW\n");
	return_value = pWritePrivateProfileStructW(section, key, buf, bufsize, filename);
	TRACE("Leave WritePrivateProfileStructW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WriteProfileSectionA(LPCSTR section, LPCSTR keys_n_values) /* ../dlls/kernel32/profile.c:1501 */
{
	BOOL return_value;
	TRACE("Enter WriteProfileSectionA\n");
	return_value = pWriteProfileSectionA(section, keys_n_values);
	TRACE("Leave WriteProfileSectionA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WriteProfileSectionW(LPCWSTR section, LPCWSTR keys_n_values) /* ../dlls/kernel32/profile.c:1510 */
{
	BOOL return_value;
	TRACE("Enter WriteProfileSectionW\n");
	return_value = pWriteProfileSectionW(section, keys_n_values);
	TRACE("Leave WriteProfileSectionW\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WriteProfileStringA(LPCSTR section, LPCSTR entry, LPCSTR string) /* ../dlls/kernel32/profile.c:1207 */
{
	BOOL return_value;
	TRACE("Enter WriteProfileStringA\n");
	return_value = pWriteProfileStringA(section, entry, string);
	TRACE("Leave WriteProfileStringA\n");
	return return_value;
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

WINAPI BOOL wine32b_kernel32_WriteProfileStringW(LPCWSTR section, LPCWSTR entry, LPCWSTR string) /* ../dlls/kernel32/profile.c:1216 */
{
	BOOL return_value;
	TRACE("Enter WriteProfileStringW\n");
	return_value = pWriteProfileStringW(section, entry, string);
	TRACE("Leave WriteProfileStringW\n");
	return return_value;
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

WINAPI DWORD wine32b_kernel32_WriteTapemark(HANDLE device, DWORD type, DWORD count, BOOL immediate) /* ../dlls/kernel32/tape.c:310 */
{
	DWORD return_value;
	TRACE("Enter WriteTapemark\n");
	return_value = pWriteTapemark(device, type, count, immediate);
	TRACE("Leave WriteTapemark\n");
	return return_value;
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

WINAPI void* wine32b_kernel32___wine_kernel_init(void) /* ../dlls/kernel32/process.c:1390 */
{
	void* return_value;
	TRACE("Enter __wine_kernel_init\n");
	return_value = p__wine_kernel_init();
	TRACE("Leave __wine_kernel_init\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32__hread(HFILE hFile, LPVOID buffer, LONG count) /* ../dlls/kernel32/file.c:287 */
{
	LONG return_value;
	TRACE("Enter _hread\n");
	return_value = p_hread(hFile, buffer, count);
	TRACE("Leave _hread\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32__hwrite(HFILE handle, LPCSTR buffer, LONG count) /* ../dlls/kernel32/file.c:303 */
{
	LONG return_value;
	TRACE("Enter _hwrite\n");
	return_value = p_hwrite(handle, buffer, count);
	TRACE("Leave _hwrite\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32__lclose(HFILE hFile) /* ../dlls/kernel32/file.c:324 */
{
	HFILE return_value;
	TRACE("Enter _lclose\n");
	return_value = p_lclose(hFile);
	TRACE("Leave _lclose\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32__lcreat(LPCSTR path, INT attr) /* ../dlls/kernel32/file.c:334 */
{
	HFILE return_value;
	TRACE("Enter _lcreat\n");
	return_value = p_lcreat(path, attr);
	TRACE("Leave _lcreat\n");
	return return_value;
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

WINAPI LONG wine32b_kernel32__llseek(HFILE hFile, LONG lOffset, INT nOrigin) /* ../dlls/kernel32/file.c:375 */
{
	LONG return_value;
	TRACE("Enter _llseek\n");
	return_value = p_llseek(hFile, lOffset, nOrigin);
	TRACE("Leave _llseek\n");
	return return_value;
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

WINAPI HFILE wine32b_kernel32__lopen(LPCSTR path, INT mode) /* ../dlls/kernel32/file.c:351 */
{
	HFILE return_value;
	TRACE("Enter _lopen\n");
	return_value = p_lopen(path, mode);
	TRACE("Leave _lopen\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32__lread(HFILE handle, LPVOID buffer, UINT count) /* ../dlls/kernel32/file.c:363 */
{
	UINT return_value;
	TRACE("Enter _lread\n");
	return_value = p_lread(handle, buffer, count);
	TRACE("Leave _lread\n");
	return return_value;
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

WINAPI UINT wine32b_kernel32__lwrite(HFILE hFile, LPCSTR buffer, UINT count) /* ../dlls/kernel32/file.c:384 */
{
	UINT return_value;
	TRACE("Enter _lwrite\n");
	return_value = p_lwrite(hFile, buffer, count);
	TRACE("Leave _lwrite\n");
	return return_value;
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

WINAPI LPSTR wine32b_kernel32_lstrcatA(LPSTR dst, LPCSTR src) /* ../dlls/kernel32/string.c:41 */
{
	LPSTR return_value;
	TRACE("Enter lstrcatA\n");
	return_value = plstrcatA(dst, src);
	TRACE("Leave lstrcatA\n");
	return return_value;
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

WINAPI LPWSTR wine32b_kernel32_lstrcatW(LPWSTR dst, LPCWSTR src) /* ../dlls/kernel32/string.c:60 */
{
	LPWSTR return_value;
	TRACE("Enter lstrcatW\n");
	return_value = plstrcatW(dst, src);
	TRACE("Leave lstrcatW\n");
	return return_value;
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

WINAPI LPSTR wine32b_kernel32_lstrcpyA(LPSTR dst, LPCSTR src) /* ../dlls/kernel32/string.c:80 */
{
	LPSTR return_value;
	TRACE("Enter lstrcpyA\n");
	return_value = plstrcpyA(dst, src);
	TRACE("Leave lstrcpyA\n");
	return return_value;
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

WINAPI LPWSTR wine32b_kernel32_lstrcpyW(LPWSTR dst, LPCWSTR src) /* ../dlls/kernel32/string.c:100 */
{
	LPWSTR return_value;
	TRACE("Enter lstrcpyW\n");
	return_value = plstrcpyW(dst, src);
	TRACE("Leave lstrcpyW\n");
	return return_value;
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

WINAPI WCHAR* wine32b_kernel32_wine_get_dos_file_name(LPCSTR str) /* ../dlls/kernel32/path.c:1907 */
{
	WCHAR* return_value;
	TRACE("Enter wine_get_dos_file_name\n");
	return_value = pwine_get_dos_file_name(str);
	TRACE("Leave wine_get_dos_file_name\n");
	return return_value;
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

WINAPI char* wine32b_kernel32_wine_get_unix_file_name(LPCWSTR dosW) /* ../dlls/kernel32/path.c:1883 */
{
	char* return_value;
	TRACE("Enter wine_get_unix_file_name\n");
	return_value = pwine_get_unix_file_name(dosW);
	TRACE("Leave wine_get_unix_file_name\n");
	return return_value;
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

static BOOL initialized = FALSE;

void wine_thunk_initialize_kernel32(void)
{
	HMODULE library = GetModuleHandleA("kernel32.dll");	HMODULE library_kernelbase = GetModuleHandleA("kernelbase.dll");
	HMODULE library_ntdll = GetModuleHandleA("ntdll.dll");
	pAddAtomA = (void *)GetProcAddress(library, "AddAtomA");
	pAddAtomW = (void *)GetProcAddress(library, "AddAtomW");
	pAddConsoleAliasA = (void *)GetProcAddress(library, "AddConsoleAliasA");
	pAddConsoleAliasW = (void *)GetProcAddress(library, "AddConsoleAliasW");
	pAddDllDirectory = (void *)GetProcAddress(library, "AddDllDirectory");
	pAllocConsole = (void *)GetProcAddress(library, "AllocConsole");
	pAllocateUserPhysicalPages = (void *)GetProcAddress(library, "AllocateUserPhysicalPages");
	pApplicationRecoveryFinished = (void *)GetProcAddress(library, "ApplicationRecoveryFinished");
	pApplicationRecoveryInProgress = (void *)GetProcAddress(library, "ApplicationRecoveryInProgress");
	pAssignProcessToJobObject = (void *)GetProcAddress(library, "AssignProcessToJobObject");
	pBackupRead = (void *)GetProcAddress(library, "BackupRead");
	pBackupSeek = (void *)GetProcAddress(library, "BackupSeek");
	pBackupWrite = (void *)GetProcAddress(library, "BackupWrite");
	pBaseFlushAppcompatCache = (void *)GetProcAddress(library, "BaseFlushAppcompatCache");
	pBeep = (void *)GetProcAddress(library, "Beep");
	pBeginUpdateResourceA = (void *)GetProcAddress(library, "BeginUpdateResourceA");
	pBeginUpdateResourceW = (void *)GetProcAddress(library, "BeginUpdateResourceW");
	pBindIoCompletionCallback = (void *)GetProcAddress(library, "BindIoCompletionCallback");
	pBuildCommDCBA = (void *)GetProcAddress(library, "BuildCommDCBA");
	pBuildCommDCBAndTimeoutsA = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsA");
	pBuildCommDCBAndTimeoutsW = (void *)GetProcAddress(library, "BuildCommDCBAndTimeoutsW");
	pBuildCommDCBW = (void *)GetProcAddress(library, "BuildCommDCBW");
	pCallNamedPipeA = (void *)GetProcAddress(library, "CallNamedPipeA");
	pCancelTimerQueueTimer = (void *)GetProcAddress(library, "CancelTimerQueueTimer");
	pCheckNameLegalDOS8Dot3A = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3A");
	pCheckNameLegalDOS8Dot3W = (void *)GetProcAddress(library, "CheckNameLegalDOS8Dot3W");
	pCloseConsoleHandle = (void *)GetProcAddress(library, "CloseConsoleHandle");
	pCloseHandle = (void *)GetProcAddress(library, "CloseHandle");
	pCloseProfileUserMapping = (void *)GetProcAddress(library, "CloseProfileUserMapping");
	pCmdBatNotification = (void *)GetProcAddress(library, "CmdBatNotification");
	pCommConfigDialogA = (void *)GetProcAddress(library, "CommConfigDialogA");
	pCommConfigDialogW = (void *)GetProcAddress(library, "CommConfigDialogW");
	pCompareFileTime = (void *)GetProcAddress(library, "CompareFileTime");
	pCompareStringA = (void *)GetProcAddress(library, "CompareStringA");
	pCompareStringEx = (void *)GetProcAddress(library, "CompareStringEx");
	pCompareStringOrdinal = (void *)GetProcAddress(library, "CompareStringOrdinal");
	pCompareStringW = (void *)GetProcAddress(library, "CompareStringW");
	pConvertDefaultLocale = (void *)GetProcAddress(library, "ConvertDefaultLocale");
	pConvertToGlobalHandle = (void *)GetProcAddress(library, "ConvertToGlobalHandle");
	pCopyFileA = (void *)GetProcAddress(library, "CopyFileA");
	pCopyFileExA = (void *)GetProcAddress(library, "CopyFileExA");
	pCopyFileExW = (void *)GetProcAddress(library, "CopyFileExW");
	pCopyFileW = (void *)GetProcAddress(library, "CopyFileW");
	pCreateActCtxA = (void *)GetProcAddress(library, "CreateActCtxA");
	pCreateDirectoryExA = (void *)GetProcAddress(library, "CreateDirectoryExA");
	pCreateFileMappingA = (void *)GetProcAddress(library, "CreateFileMappingA");
	pCreateHardLinkA = (void *)GetProcAddress(library, "CreateHardLinkA");
	pCreateHardLinkTransactedA = (void *)GetProcAddress(library, "CreateHardLinkTransactedA");
	pCreateHardLinkTransactedW = (void *)GetProcAddress(library, "CreateHardLinkTransactedW");
	pCreateHardLinkW = (void *)GetProcAddress(library, "CreateHardLinkW");
	pCreateJobObjectA = (void *)GetProcAddress(library, "CreateJobObjectA");
	pCreateJobObjectW = (void *)GetProcAddress(library, "CreateJobObjectW");
	pCreateMailslotA = (void *)GetProcAddress(library, "CreateMailslotA");
	pCreateMailslotW = (void *)GetProcAddress(library, "CreateMailslotW");
	pCreateNamedPipeA = (void *)GetProcAddress(library, "CreateNamedPipeA");
	pCreatePipe = (void *)GetProcAddress(library, "CreatePipe");
	pCreateProcessA = (void *)GetProcAddress(library, "CreateProcessA");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pCreateProcessInternalA = (void *)GetProcAddress(library, "CreateProcessInternalA");
	pCreateProcessInternalW = (void *)GetProcAddress(library, "CreateProcessInternalW");
	pCreateProcessW = (void *)GetProcAddress(library, "CreateProcessW");
	pCreateSemaphoreA = (void *)GetProcAddress(library, "CreateSemaphoreA");
	pCreateSemaphoreExA = (void *)GetProcAddress(library, "CreateSemaphoreExA");
	pCreateSocketHandle = (void *)GetProcAddress(library, "CreateSocketHandle");
	pCreateSymbolicLinkA = (void *)GetProcAddress(library, "CreateSymbolicLinkA");
	pCreateSymbolicLinkW = (void *)GetProcAddress(library, "CreateSymbolicLinkW");
	pCreateTapePartition = (void *)GetProcAddress(library, "CreateTapePartition");
	pCreateToolhelp32Snapshot = (void *)GetProcAddress(library, "CreateToolhelp32Snapshot");
	pCreateUmsCompletionList = (void *)GetProcAddress(library, "CreateUmsCompletionList");
	pCreateUmsThreadContext = (void *)GetProcAddress(library, "CreateUmsThreadContext");
	pCreateWaitableTimerA = (void *)GetProcAddress(library, "CreateWaitableTimerA");
	pCreateWaitableTimerExA = (void *)GetProcAddress(library, "CreateWaitableTimerExA");
	pDebugBreakProcess = (void *)GetProcAddress(library, "DebugBreakProcess");
	pDebugSetProcessKillOnExit = (void *)GetProcAddress(library, "DebugSetProcessKillOnExit");
	pDefineDosDeviceA = (void *)GetProcAddress(library, "DefineDosDeviceA");
	pDefineDosDeviceW = (void *)GetProcAddress(library, "DefineDosDeviceW");
	pDelayLoadFailureHook = (void *)GetProcAddress(library, "DelayLoadFailureHook");
	pDeleteAtom = (void *)GetProcAddress(library, "DeleteAtom");
	pDeleteTimerQueue = (void *)GetProcAddress(library, "DeleteTimerQueue");
	pDeleteUmsCompletionList = (void *)GetProcAddress(library, "DeleteUmsCompletionList");
	pDeleteUmsThreadContext = (void *)GetProcAddress(library, "DeleteUmsThreadContext");
	pDeleteVolumeMountPointA = (void *)GetProcAddress(library, "DeleteVolumeMountPointA");
	pDeleteVolumeMountPointW = (void *)GetProcAddress(library, "DeleteVolumeMountPointW");
	pDequeueUmsCompletionListItems = (void *)GetProcAddress(library, "DequeueUmsCompletionListItems");
	pDeviceIoControl = (void *)GetProcAddress(library, "DeviceIoControl");
	pDnsHostnameToComputerNameA = (void *)GetProcAddress(library, "DnsHostnameToComputerNameA");
	pDnsHostnameToComputerNameW = (void *)GetProcAddress(library, "DnsHostnameToComputerNameW");
	pDosDateTimeToFileTime = (void *)GetProcAddress(library, "DosDateTimeToFileTime");
	pDuplicateConsoleHandle = (void *)GetProcAddress(library, "DuplicateConsoleHandle");
	pDuplicateHandle = (void *)GetProcAddress(library, "DuplicateHandle");
	pEndUpdateResourceA = (void *)GetProcAddress(library, "EndUpdateResourceA");
	pEndUpdateResourceW = (void *)GetProcAddress(library, "EndUpdateResourceW");
	pEnterUmsSchedulingMode = (void *)GetProcAddress(library, "EnterUmsSchedulingMode");
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
	pEnumResourceLanguagesW = (void *)GetProcAddress(library, "EnumResourceLanguagesW");
	pEnumResourceNamesA = (void *)GetProcAddress(library, "EnumResourceNamesA");
	pEnumResourceTypesA = (void *)GetProcAddress(library, "EnumResourceTypesA");
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
	pEraseTape = (void *)GetProcAddress(library, "EraseTape");
	pExecuteUmsThread = (void *)GetProcAddress(library, "ExecuteUmsThread");
	pExitProcess = (void *)GetProcAddress(library, "ExitProcess");
	pExpungeConsoleCommandHistoryA = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryA");
	pExpungeConsoleCommandHistoryW = (void *)GetProcAddress(library, "ExpungeConsoleCommandHistoryW");
	pFatalExit = (void *)GetProcAddress(library, "FatalExit");
	pFileTimeToDosDateTime = (void *)GetProcAddress(library, "FileTimeToDosDateTime");
	pFileTimeToLocalFileTime = (void *)GetProcAddress(library, "FileTimeToLocalFileTime");
	pFileTimeToSystemTime = (void *)GetProcAddress(library, "FileTimeToSystemTime");
	pFindActCtxSectionStringA = (void *)GetProcAddress(library, "FindActCtxSectionStringA");
	pFindAtomA = (void *)GetProcAddress(library, "FindAtomA");
	pFindAtomW = (void *)GetProcAddress(library, "FindAtomW");
	pFindClose = (void *)GetProcAddress(library, "FindClose");
	pFindFirstFileA = (void *)GetProcAddress(library, "FindFirstFileA");
	pFindFirstFileExA = (void *)GetProcAddress(library, "FindFirstFileExA");
	pFindFirstFileExW = (void *)GetProcAddress(library, "FindFirstFileExW");
	pFindFirstFileW = (void *)GetProcAddress(library, "FindFirstFileW");
	pFindFirstStreamW = (void *)GetProcAddress(library, "FindFirstStreamW");
	pFindFirstVolumeA = (void *)GetProcAddress(library, "FindFirstVolumeA");
	pFindFirstVolumeMountPointA = (void *)GetProcAddress(library, "FindFirstVolumeMountPointA");
	pFindFirstVolumeMountPointW = (void *)GetProcAddress(library, "FindFirstVolumeMountPointW");
	pFindFirstVolumeW = (void *)GetProcAddress(library, "FindFirstVolumeW");
	pFindNLSStringEx = (void *)GetProcAddress(library, "FindNLSStringEx");
	pFindNextFileA = (void *)GetProcAddress(library, "FindNextFileA");
	pFindNextFileW = (void *)GetProcAddress(library, "FindNextFileW");
	pFindNextStreamW = (void *)GetProcAddress(library, "FindNextStreamW");
	pFindNextVolumeA = (void *)GetProcAddress(library, "FindNextVolumeA");
	pFindNextVolumeW = (void *)GetProcAddress(library, "FindNextVolumeW");
	pFindResourceA = (void *)GetProcAddress(library, "FindResourceA");
	pFindResourceExA = (void *)GetProcAddress(library, "FindResourceExA");
	pFindStringOrdinal = (void *)GetProcAddress(library, "FindStringOrdinal");
	pFindVolumeClose = (void *)GetProcAddress(library, "FindVolumeClose");
	pFindVolumeMountPointClose = (void *)GetProcAddress(library, "FindVolumeMountPointClose");
	pFlushConsoleInputBuffer = (void *)GetProcAddress(library, "FlushConsoleInputBuffer");
	pFlushProcessWriteBuffers = (void *)GetProcAddress(library, "FlushProcessWriteBuffers");
	pFoldStringA = (void *)GetProcAddress(library, "FoldStringA");
	pFoldStringW = (void *)GetProcAddress(library, "FoldStringW");
	pFormatMessageA = (void *)GetProcAddress(library, "FormatMessageA");
	pFormatMessageW = (void *)GetProcAddress(library, "FormatMessageW");
	pFreeConsole = (void *)GetProcAddress(library, "FreeConsole");
	pFreeLibrary = (void *)GetProcAddress(library, "FreeLibrary");
	pFreeLibraryAndExitThread = (void *)GetProcAddress(library, "FreeLibraryAndExitThread");
	pFreeUserPhysicalPages = (void *)GetProcAddress(library, "FreeUserPhysicalPages");
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
	pGetCalendarInfoEx = (void *)GetProcAddress(library, "GetCalendarInfoEx");
	pGetCalendarInfoW = (void *)GetProcAddress(library, "GetCalendarInfoW");
	pGetComputerNameA = (void *)GetProcAddress(library, "GetComputerNameA");
	pGetComputerNameExA = (void *)GetProcAddress(library, "GetComputerNameExA");
	pGetComputerNameExW = (void *)GetProcAddress(library, "GetComputerNameExW");
	pGetComputerNameW = (void *)GetProcAddress(library, "GetComputerNameW");
	pGetConsoleAliasExesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthA");
	pGetConsoleAliasExesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasExesLengthW");
	pGetConsoleAliasW = (void *)GetProcAddress(library, "GetConsoleAliasW");
	pGetConsoleAliasesLengthA = (void *)GetProcAddress(library, "GetConsoleAliasesLengthA");
	pGetConsoleAliasesLengthW = (void *)GetProcAddress(library, "GetConsoleAliasesLengthW");
	pGetConsoleCommandHistoryA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryA");
	pGetConsoleCommandHistoryLengthA = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthA");
	pGetConsoleCommandHistoryLengthW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryLengthW");
	pGetConsoleCommandHistoryW = (void *)GetProcAddress(library, "GetConsoleCommandHistoryW");
	pGetConsoleDisplayMode = (void *)GetProcAddress(library, "GetConsoleDisplayMode");
	pGetConsoleFontInfo = (void *)GetProcAddress(library, "GetConsoleFontInfo");
	pGetConsoleFontSize = (void *)GetProcAddress(library, "GetConsoleFontSize");
	pGetConsoleInputWaitHandle = (void *)GetProcAddress(library, "GetConsoleInputWaitHandle");
	pGetConsoleKeyboardLayoutNameA = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameA");
	pGetConsoleKeyboardLayoutNameW = (void *)GetProcAddress(library, "GetConsoleKeyboardLayoutNameW");
	pGetConsoleProcessList = (void *)GetProcAddress(library, "GetConsoleProcessList");
	pGetConsoleTitleA = (void *)GetProcAddress(library, "GetConsoleTitleA");
	pGetConsoleWindow = (void *)GetProcAddress(library, "GetConsoleWindow");
	pGetCurrencyFormatA = (void *)GetProcAddress(library, "GetCurrencyFormatA");
	pGetCurrencyFormatEx = (void *)GetProcAddress(library, "GetCurrencyFormatEx");
	pGetCurrencyFormatW = (void *)GetProcAddress(library, "GetCurrencyFormatW");
	pGetCurrentConsoleFont = (void *)GetProcAddress(library, "GetCurrentConsoleFont");
	pGetCurrentDirectoryA = (void *)GetProcAddress(library, "GetCurrentDirectoryA");
	pGetCurrentDirectoryW = (void *)GetProcAddress(library, "GetCurrentDirectoryW");
	pGetCurrentPackageFamilyName = (void *)GetProcAddress(library, "GetCurrentPackageFamilyName");
	pGetCurrentPackageFullName = (void *)GetProcAddress(library, "GetCurrentPackageFullName");
	pGetCurrentPackageId = (void *)GetProcAddress(library, "GetCurrentPackageId");
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
	pGetExitCodeProcess = (void *)GetProcAddress(library, "GetExitCodeProcess");
	pGetExpandedNameA = (void *)GetProcAddress(library, "GetExpandedNameA");
	pGetExpandedNameW = (void *)GetProcAddress(library, "GetExpandedNameW");
	pGetFileMUIInfo = (void *)GetProcAddress(library, "GetFileMUIInfo");
	pGetFileMUIPath = (void *)GetProcAddress(library, "GetFileMUIPath");
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
	pGetLocalTime = (void *)GetProcAddress(library, "GetLocalTime");
	pGetLocaleInfoA = (void *)GetProcAddress(library, "GetLocaleInfoA");
	pGetLocaleInfoEx = (void *)GetProcAddress(library, "GetLocaleInfoEx");
	pGetLocaleInfoW = (void *)GetProcAddress(library, "GetLocaleInfoW");
	pGetLogicalDriveStringsA = (void *)GetProcAddress(library, "GetLogicalDriveStringsA");
	pGetLogicalDriveStringsW = (void *)GetProcAddress(library, "GetLogicalDriveStringsW");
	pGetLogicalDrives = (void *)GetProcAddress(library, "GetLogicalDrives");
	pGetLogicalProcessorInformation = (void *)GetProcAddress(library, "GetLogicalProcessorInformation");
	pGetLogicalProcessorInformationEx = (void *)GetProcAddress(library, "GetLogicalProcessorInformationEx");
	pGetLongPathNameA = (void *)GetProcAddress(library, "GetLongPathNameA");
	pGetLongPathNameW = (void *)GetProcAddress(library, "GetLongPathNameW");
	pGetMailslotInfo = (void *)GetProcAddress(library, "GetMailslotInfo");
	pGetMaximumProcessorCount = (void *)GetProcAddress(library, "GetMaximumProcessorCount");
	pGetNamedPipeClientProcessId = (void *)GetProcAddress(library, "GetNamedPipeClientProcessId");
	pGetNamedPipeClientSessionId = (void *)GetProcAddress(library, "GetNamedPipeClientSessionId");
	pGetNamedPipeHandleStateA = (void *)GetProcAddress(library, "GetNamedPipeHandleStateA");
	pGetNamedPipeHandleStateW = (void *)GetProcAddress(library, "GetNamedPipeHandleStateW");
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
	pGetNumberOfConsoleMouseButtons = (void *)GetProcAddress(library, "GetNumberOfConsoleMouseButtons");
	pGetOEMCP = (void *)GetProcAddress(library, "GetOEMCP");
	pGetPackageFullName = (void *)GetProcAddress(library, "GetPackageFullName");
	pGetPhysicallyInstalledSystemMemory = (void *)GetProcAddress(library, "GetPhysicallyInstalledSystemMemory");
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
	pGetProcessIoCounters = (void *)GetProcAddress(library, "GetProcessIoCounters");
	pGetProcessPreferredUILanguages = (void *)GetProcAddress(library, "GetProcessPreferredUILanguages");
	pGetProcessTimes = (void *)GetProcAddress(library, "GetProcessTimes");
	pGetProcessVersion = (void *)GetProcAddress(library, "GetProcessVersion");
	pGetProcessWorkingSetSize = (void *)GetProcAddress(library, "GetProcessWorkingSetSize");
	pGetProductInfo = (void *)GetProcAddress(library, "GetProductInfo");
	pGetProfileIntA = (void *)GetProcAddress(library, "GetProfileIntA");
	pGetProfileIntW = (void *)GetProcAddress(library, "GetProfileIntW");
	pGetProfileSectionA = (void *)GetProcAddress(library, "GetProfileSectionA");
	pGetProfileSectionW = (void *)GetProcAddress(library, "GetProfileSectionW");
	pGetProfileStringA = (void *)GetProcAddress(library, "GetProfileStringA");
	pGetProfileStringW = (void *)GetProcAddress(library, "GetProfileStringW");
	pGetShortPathNameA = (void *)GetProcAddress(library, "GetShortPathNameA");
	pGetShortPathNameW = (void *)GetProcAddress(library, "GetShortPathNameW");
	pGetStartupInfoA = (void *)GetProcAddress(library, "GetStartupInfoA");
	pGetStringTypeA = (void *)GetProcAddress(library, "GetStringTypeA");
	pGetStringTypeExA = (void *)GetProcAddress(library, "GetStringTypeExA");
	pGetStringTypeExW = (void *)GetProcAddress(library, "GetStringTypeExW");
	pGetStringTypeW = (void *)GetProcAddress(library, "GetStringTypeW");
	pGetSystemDEPPolicy = (void *)GetProcAddress(library, "GetSystemDEPPolicy");
	pGetSystemDefaultLCID = (void *)GetProcAddress(library, "GetSystemDefaultLCID");
	pGetSystemDefaultLangID = (void *)GetProcAddress(library, "GetSystemDefaultLangID");
	pGetSystemDefaultLocaleName = (void *)GetProcAddress(library, "GetSystemDefaultLocaleName");
	pGetSystemDefaultUILanguage = (void *)GetProcAddress(library, "GetSystemDefaultUILanguage");
	pGetSystemDirectoryA = (void *)GetProcAddress(library, "GetSystemDirectoryA");
	pGetSystemDirectoryW = (void *)GetProcAddress(library, "GetSystemDirectoryW");
	pGetSystemFileCacheSize = (void *)GetProcAddress(library, "GetSystemFileCacheSize");
	pGetSystemFirmwareTable = (void *)GetProcAddress(library, "GetSystemFirmwareTable");
	pGetSystemInfo = (void *)GetProcAddress(library, "GetSystemInfo");
	pGetSystemPowerStatus = (void *)GetProcAddress(library, "GetSystemPowerStatus");
	pGetSystemPreferredUILanguages = (void *)GetProcAddress(library, "GetSystemPreferredUILanguages");
	pGetSystemRegistryQuota = (void *)GetProcAddress(library, "GetSystemRegistryQuota");
	pGetSystemTime = (void *)GetProcAddress(library, "GetSystemTime");
	pGetSystemTimeAdjustment = (void *)GetProcAddress(library, "GetSystemTimeAdjustment");
	pGetSystemTimePreciseAsFileTime = (void *)GetProcAddress(library, "GetSystemTimePreciseAsFileTime");
	pGetSystemTimes = (void *)GetProcAddress(library, "GetSystemTimes");
	pGetSystemWow64DirectoryA = (void *)GetProcAddress(library, "GetSystemWow64DirectoryA");
	pGetSystemWow64DirectoryW = (void *)GetProcAddress(library, "GetSystemWow64DirectoryW");
	pGetTapeParameters = (void *)GetProcAddress(library, "GetTapeParameters");
	pGetTapePosition = (void *)GetProcAddress(library, "GetTapePosition");
	pGetTapeStatus = (void *)GetProcAddress(library, "GetTapeStatus");
	pGetTempFileNameA = (void *)GetProcAddress(library, "GetTempFileNameA");
	pGetTempFileNameW = (void *)GetProcAddress(library, "GetTempFileNameW");
	pGetTempPathA = (void *)GetProcAddress(library, "GetTempPathA");
	pGetTempPathW = (void *)GetProcAddress(library, "GetTempPathW");
	pGetThreadLocale = (void *)GetProcAddress(library, "GetThreadLocale");
	pGetThreadPreferredUILanguages = (void *)GetProcAddress(library, "GetThreadPreferredUILanguages");
	pGetThreadSelectorEntry = (void *)GetProcAddress(library, "GetThreadSelectorEntry");
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
	pGetUserPreferredUILanguages = (void *)GetProcAddress(library, "GetUserPreferredUILanguages");
	pGetVolumeInformationA = (void *)GetProcAddress(library, "GetVolumeInformationA");
	pGetVolumeInformationByHandleW = (void *)GetProcAddress(library, "GetVolumeInformationByHandleW");
	pGetVolumeInformationW = (void *)GetProcAddress(library, "GetVolumeInformationW");
	pGetVolumeNameForVolumeMountPointA = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointA");
	pGetVolumeNameForVolumeMountPointW = (void *)GetProcAddress(library, "GetVolumeNameForVolumeMountPointW");
	pGetVolumePathNameA = (void *)GetProcAddress(library, "GetVolumePathNameA");
	pGetVolumePathNameW = (void *)GetProcAddress(library, "GetVolumePathNameW");
	pGetVolumePathNamesForVolumeNameA = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameA");
	pGetVolumePathNamesForVolumeNameW = (void *)GetProcAddress(library, "GetVolumePathNamesForVolumeNameW");
	pGlobalAddAtomA = (void *)GetProcAddress(library, "GlobalAddAtomA");
	pGlobalAddAtomW = (void *)GetProcAddress(library, "GlobalAddAtomW");
	pGlobalCompact = (void *)GetProcAddress(library, "GlobalCompact");
	pGlobalDeleteAtom = (void *)GetProcAddress(library, "GlobalDeleteAtom");
	pGlobalFindAtomA = (void *)GetProcAddress(library, "GlobalFindAtomA");
	pGlobalFindAtomW = (void *)GetProcAddress(library, "GlobalFindAtomW");
	pGlobalFix = (void *)GetProcAddress(library, "GlobalFix");
	pGlobalFlags = (void *)GetProcAddress(library, "GlobalFlags");
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
	pHeapCreate = (void *)GetProcAddress(library, "HeapCreate");
	pHeapDestroy = (void *)GetProcAddress(library, "HeapDestroy");
	pHeapFree = (void *)GetProcAddress(library, "HeapFree");
	pIdnToAscii = (void *)GetProcAddress(library, "IdnToAscii");
	pIdnToNameprepUnicode = (void *)GetProcAddress(library, "IdnToNameprepUnicode");
	pIdnToUnicode = (void *)GetProcAddress(library, "IdnToUnicode");
	pInitAtomTable = (void *)GetProcAddress(library, "InitAtomTable");
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
	pIsNormalizedString = (void *)GetProcAddress(library, "IsNormalizedString");
	pIsProcessInJob = (void *)GetProcAddress(library, "IsProcessInJob");
	pIsProcessorFeaturePresent = (void *)GetProcAddress(library, "IsProcessorFeaturePresent");
	pIsSystemResumeAutomatic = (void *)GetProcAddress(library, "IsSystemResumeAutomatic");
	pIsValidCodePage = (void *)GetProcAddress(library, "IsValidCodePage");
	pIsValidLanguageGroup = (void *)GetProcAddress(library, "IsValidLanguageGroup");
	pIsValidLocale = (void *)GetProcAddress(library, "IsValidLocale");
	pIsValidLocaleName = (void *)GetProcAddress(library, "IsValidLocaleName");
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
	pGetCurrentProcess = (void *)GetProcAddress(library, "GetCurrentProcess");
	pGetCurrentProcessId = (void *)GetProcAddress(library, "GetCurrentProcessId");
	pGetCurrentThread = (void *)GetProcAddress(library, "GetCurrentThread");
	pGetCurrentThreadId = (void *)GetProcAddress(library, "GetCurrentThreadId");
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
	pLoadLibraryA = (void *)GetProcAddress(library, "LoadLibraryA");
	pLoadLibraryExA = (void *)GetProcAddress(library, "LoadLibraryExA");
	pLoadLibraryExW = (void *)GetProcAddress(library, "LoadLibraryExW");
	pLoadLibraryW = (void *)GetProcAddress(library, "LoadLibraryW");
	pLoadModule = (void *)GetProcAddress(library, "LoadModule");
	pLocalCompact = (void *)GetProcAddress(library, "LocalCompact");
	pLocalFileTimeToFileTime = (void *)GetProcAddress(library, "LocalFileTimeToFileTime");
	pLocalFlags = (void *)GetProcAddress(library, "LocalFlags");
	pLocalHandle = (void *)GetProcAddress(library, "LocalHandle");
	pLocalShrink = (void *)GetProcAddress(library, "LocalShrink");
	pLocalSize = (void *)GetProcAddress(library, "LocalSize");
	pLocaleNameToLCID = (void *)GetProcAddress(library, "LocaleNameToLCID");
	pMakeCriticalSectionGlobal = (void *)GetProcAddress(library, "MakeCriticalSectionGlobal");
	pMapUserPhysicalPages = (void *)GetProcAddress(library, "MapUserPhysicalPages");
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
	pOpenFile = (void *)GetProcAddress(library, "OpenFile");
	pOpenFileMappingA = (void *)GetProcAddress(library, "OpenFileMappingA");
	pOpenJobObjectA = (void *)GetProcAddress(library, "OpenJobObjectA");
	pOpenJobObjectW = (void *)GetProcAddress(library, "OpenJobObjectW");
	pOpenMutexA = (void *)GetProcAddress(library, "OpenMutexA");
	pOpenProfileUserMapping = (void *)GetProcAddress(library, "OpenProfileUserMapping");
	pOpenSemaphoreA = (void *)GetProcAddress(library, "OpenSemaphoreA");
	pOpenVxDHandle = (void *)GetProcAddress(library, "OpenVxDHandle");
	pOpenWaitableTimerA = (void *)GetProcAddress(library, "OpenWaitableTimerA");
	pPowerClearRequest = (void *)GetProcAddress(library, "PowerClearRequest");
	pPowerCreateRequest = (void *)GetProcAddress(library, "PowerCreateRequest");
	pPowerSetRequest = (void *)GetProcAddress(library, "PowerSetRequest");
	pPrepareTape = (void *)GetProcAddress(library, "PrepareTape");
	pProcess32First = (void *)GetProcAddress(library, "Process32First");
	pProcess32FirstW = (void *)GetProcAddress(library, "Process32FirstW");
	pProcess32Next = (void *)GetProcAddress(library, "Process32Next");
	pProcess32NextW = (void *)GetProcAddress(library, "Process32NextW");
	pProcessIdToSessionId = (void *)GetProcAddress(library, "ProcessIdToSessionId");
	pQueryDosDeviceA = (void *)GetProcAddress(library, "QueryDosDeviceA");
	pQueryDosDeviceW = (void *)GetProcAddress(library, "QueryDosDeviceW");
	pQueryFullProcessImageNameA = (void *)GetProcAddress(library, "QueryFullProcessImageNameA");
	pQueryFullProcessImageNameW = (void *)GetProcAddress(library, "QueryFullProcessImageNameW");
	pQueryInformationJobObject = (void *)GetProcAddress(library, "QueryInformationJobObject");
	pQueryProcessCycleTime = (void *)GetProcAddress(library, "QueryProcessCycleTime");
	pQueryThreadCycleTime = (void *)GetProcAddress(library, "QueryThreadCycleTime");
	pQueryUmsThreadInformation = (void *)GetProcAddress(library, "QueryUmsThreadInformation");
	pQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "QueryUnbiasedInterruptTime");
	pReadConsoleInputW = (void *)GetProcAddress(library, "ReadConsoleInputW");
	pReadConsoleW = (void *)GetProcAddress(library, "ReadConsoleW");
	pRegisterApplicationRecoveryCallback = (void *)GetProcAddress(library, "RegisterApplicationRecoveryCallback");
	pRegisterApplicationRestart = (void *)GetProcAddress(library, "RegisterApplicationRestart");
	pRegisterServiceProcess = (void *)GetProcAddress(library, "RegisterServiceProcess");
	pRegisterWaitForSingleObject = (void *)GetProcAddress(library, "RegisterWaitForSingleObject");
	pReinitializeCriticalSection = (void *)GetProcAddress(library, "ReinitializeCriticalSection");
	pRemoveDirectoryA = (void *)GetProcAddress(library, "RemoveDirectoryA");
	pRemoveDirectoryW = (void *)GetProcAddress(library, "RemoveDirectoryW");
	pRemoveDllDirectory = (void *)GetProcAddress(library, "RemoveDllDirectory");
	pReplaceFileA = (void *)GetProcAddress(library, "ReplaceFileA");
	pReplaceFileW = (void *)GetProcAddress(library, "ReplaceFileW");
	pRequestDeviceWakeup = (void *)GetProcAddress(library, "RequestDeviceWakeup");
	pRequestWakeupLatency = (void *)GetProcAddress(library, "RequestWakeupLatency");
	pResolveLocaleName = (void *)GetProcAddress(library, "ResolveLocaleName");
	pSearchPathA = (void *)GetProcAddress(library, "SearchPathA");
	pSearchPathW = (void *)GetProcAddress(library, "SearchPathW");
	pSetCPGlobal = (void *)GetProcAddress(library, "SetCPGlobal");
	pSetCalendarInfoA = (void *)GetProcAddress(library, "SetCalendarInfoA");
	pSetCalendarInfoW = (void *)GetProcAddress(library, "SetCalendarInfoW");
	pSetComputerNameA = (void *)GetProcAddress(library, "SetComputerNameA");
	pSetComputerNameExA = (void *)GetProcAddress(library, "SetComputerNameExA");
	pSetComputerNameExW = (void *)GetProcAddress(library, "SetComputerNameExW");
	pSetComputerNameW = (void *)GetProcAddress(library, "SetComputerNameW");
	pSetConsoleCtrlHandler = (void *)GetProcAddress(library, "SetConsoleCtrlHandler");
	pSetConsoleDisplayMode = (void *)GetProcAddress(library, "SetConsoleDisplayMode");
	pSetConsoleFont = (void *)GetProcAddress(library, "SetConsoleFont");
	pSetConsoleIcon = (void *)GetProcAddress(library, "SetConsoleIcon");
	pSetConsoleKeyShortcuts = (void *)GetProcAddress(library, "SetConsoleKeyShortcuts");
	pSetConsoleTitleA = (void *)GetProcAddress(library, "SetConsoleTitleA");
	pSetCurrentConsoleFontEx = (void *)GetProcAddress(library, "SetCurrentConsoleFontEx");
	pSetCurrentDirectoryA = (void *)GetProcAddress(library, "SetCurrentDirectoryA");
	pSetCurrentDirectoryW = (void *)GetProcAddress(library, "SetCurrentDirectoryW");
	pSetDefaultCommConfigA = (void *)GetProcAddress(library, "SetDefaultCommConfigA");
	pSetDefaultCommConfigW = (void *)GetProcAddress(library, "SetDefaultCommConfigW");
	pSetDefaultDllDirectories = (void *)GetProcAddress(library, "SetDefaultDllDirectories");
	pSetDllDirectoryA = (void *)GetProcAddress(library, "SetDllDirectoryA");
	pSetDllDirectoryW = (void *)GetProcAddress(library, "SetDllDirectoryW");
	pSetFileCompletionNotificationModes = (void *)GetProcAddress(library, "SetFileCompletionNotificationModes");
	pSetHandleContext = (void *)GetProcAddress(library, "SetHandleContext");
	pSetHandleCount = (void *)GetProcAddress(library, "SetHandleCount");
	pSetHandleInformation = (void *)GetProcAddress(library, "SetHandleInformation");
	pSetInformationJobObject = (void *)GetProcAddress(library, "SetInformationJobObject");
	pSetLocalTime = (void *)GetProcAddress(library, "SetLocalTime");
	pSetLocaleInfoA = (void *)GetProcAddress(library, "SetLocaleInfoA");
	pSetLocaleInfoW = (void *)GetProcAddress(library, "SetLocaleInfoW");
	pSetMailslotInfo = (void *)GetProcAddress(library, "SetMailslotInfo");
	pSetProcessAffinityMask = (void *)GetProcAddress(library, "SetProcessAffinityMask");
	pSetProcessDEPPolicy = (void *)GetProcAddress(library, "SetProcessDEPPolicy");
	pSetProcessPreferredUILanguages = (void *)GetProcAddress(library, "SetProcessPreferredUILanguages");
	pSetProcessWorkingSetSize = (void *)GetProcAddress(library, "SetProcessWorkingSetSize");
	pSetSearchPathMode = (void *)GetProcAddress(library, "SetSearchPathMode");
	pSetSystemFileCacheSize = (void *)GetProcAddress(library, "SetSystemFileCacheSize");
	pSetSystemPowerState = (void *)GetProcAddress(library, "SetSystemPowerState");
	pSetSystemTime = (void *)GetProcAddress(library, "SetSystemTime");
	pSetSystemTimeAdjustment = (void *)GetProcAddress(library, "SetSystemTimeAdjustment");
	pSetTapeParameters = (void *)GetProcAddress(library, "SetTapeParameters");
	pSetTapePosition = (void *)GetProcAddress(library, "SetTapePosition");
	pSetTermsrvAppInstallMode = (void *)GetProcAddress(library, "SetTermsrvAppInstallMode");
	pSetThreadAffinityMask = (void *)GetProcAddress(library, "SetThreadAffinityMask");
	pSetThreadExecutionState = (void *)GetProcAddress(library, "SetThreadExecutionState");
	pSetThreadLocale = (void *)GetProcAddress(library, "SetThreadLocale");
	pSetThreadPreferredUILanguages = (void *)GetProcAddress(library, "SetThreadPreferredUILanguages");
	pSetThreadUILanguage = (void *)GetProcAddress(library, "SetThreadUILanguage");
	pSetTimeZoneInformation = (void *)GetProcAddress(library, "SetTimeZoneInformation");
	pSetUmsThreadInformation = (void *)GetProcAddress(library, "SetUmsThreadInformation");
	pSetUserGeoID = (void *)GetProcAddress(library, "SetUserGeoID");
	pSetVolumeLabelA = (void *)GetProcAddress(library, "SetVolumeLabelA");
	pSetVolumeLabelW = (void *)GetProcAddress(library, "SetVolumeLabelW");
	pSetVolumeMountPointA = (void *)GetProcAddress(library, "SetVolumeMountPointA");
	pSetVolumeMountPointW = (void *)GetProcAddress(library, "SetVolumeMountPointW");
	pSystemTimeToFileTime = (void *)GetProcAddress(library, "SystemTimeToFileTime");
	pSystemTimeToTzSpecificLocalTime = (void *)GetProcAddress(library, "SystemTimeToTzSpecificLocalTime");
	pTerminateJobObject = (void *)GetProcAddress(library, "TerminateJobObject");
	pTermsrvAppInstallMode = (void *)GetProcAddress(library, "TermsrvAppInstallMode");
	pThread32First = (void *)GetProcAddress(library, "Thread32First");
	pThread32Next = (void *)GetProcAddress(library, "Thread32Next");
	pToolhelp32ReadProcessMemory = (void *)GetProcAddress(library, "Toolhelp32ReadProcessMemory");
	pTzSpecificLocalTimeToSystemTime = (void *)GetProcAddress(library, "TzSpecificLocalTimeToSystemTime");
	pUmsThreadYield = (void *)GetProcAddress(library, "UmsThreadYield");
	pUninitializeCriticalSection = (void *)GetProcAddress(library, "UninitializeCriticalSection");
	pUnregisterApplicationRestart = (void *)GetProcAddress(library, "UnregisterApplicationRestart");
	pUnregisterWait = (void *)GetProcAddress(library, "UnregisterWait");
	pUpdateResourceA = (void *)GetProcAddress(library, "UpdateResourceA");
	pUpdateResourceW = (void *)GetProcAddress(library, "UpdateResourceW");
	pVerLanguageNameA = (void *)GetProcAddress(library, "VerLanguageNameA");
	pVerLanguageNameW = (void *)GetProcAddress(library, "VerLanguageNameW");
	pVerifyConsoleIoHandle = (void *)GetProcAddress(library, "VerifyConsoleIoHandle");
	pVerifyVersionInfoA = (void *)GetProcAddress(library, "VerifyVersionInfoA");
	pVerifyVersionInfoW = (void *)GetProcAddress(library, "VerifyVersionInfoW");
	pWTSGetActiveConsoleSessionId = (void *)GetProcAddress(library, "WTSGetActiveConsoleSessionId");
	pWaitNamedPipeA = (void *)GetProcAddress(library, "WaitNamedPipeA");
	pWerRegisterFile = (void *)GetProcAddress(library, "WerRegisterFile");
	pWerRegisterMemoryBlock = (void *)GetProcAddress(library, "WerRegisterMemoryBlock");
	pWerRegisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerRegisterRuntimeExceptionModule");
	pWerSetFlags = (void *)GetProcAddress(library, "WerSetFlags");
	pWerUnregisterMemoryBlock = (void *)GetProcAddress(library, "WerUnregisterMemoryBlock");
	pWerUnregisterRuntimeExceptionModule = (void *)GetProcAddress(library, "WerUnregisterRuntimeExceptionModule");
	pWideCharToMultiByte = (void *)GetProcAddress(library, "WideCharToMultiByte");
	pWinExec = (void *)GetProcAddress(library, "WinExec");
	pWow64EnableWow64FsRedirection = (void *)GetProcAddress(library, "Wow64EnableWow64FsRedirection");
	pWow64GetThreadContext = (void *)GetProcAddress(library, "Wow64GetThreadContext");
	pWow64SetThreadContext = (void *)GetProcAddress(library, "Wow64SetThreadContext");
	pWriteConsoleW = (void *)GetProcAddress(library, "WriteConsoleW");
	pWritePrivateProfileSectionA = (void *)GetProcAddress(library, "WritePrivateProfileSectionA");
	pWritePrivateProfileSectionW = (void *)GetProcAddress(library, "WritePrivateProfileSectionW");
	pWritePrivateProfileStringA = (void *)GetProcAddress(library, "WritePrivateProfileStringA");
	pWritePrivateProfileStringW = (void *)GetProcAddress(library, "WritePrivateProfileStringW");
	pWritePrivateProfileStructA = (void *)GetProcAddress(library, "WritePrivateProfileStructA");
	pWritePrivateProfileStructW = (void *)GetProcAddress(library, "WritePrivateProfileStructW");
	pWriteProfileSectionA = (void *)GetProcAddress(library, "WriteProfileSectionA");
	pWriteProfileSectionW = (void *)GetProcAddress(library, "WriteProfileSectionW");
	pWriteProfileStringA = (void *)GetProcAddress(library, "WriteProfileStringA");
	pWriteProfileStringW = (void *)GetProcAddress(library, "WriteProfileStringW");
	pWriteTapemark = (void *)GetProcAddress(library, "WriteTapemark");
	p__wine_kernel_init = (void *)GetProcAddress(library, "__wine_kernel_init");
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
	plstrcpyA = (void *)GetProcAddress(library, "lstrcpyA");
	plstrcpyW = (void *)GetProcAddress(library, "lstrcpyW");
	pAcquireSRWLockExclusive = (void *)GetProcAddress(library, "AcquireSRWLockExclusive");
	pextAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockExclusive");
	pAcquireSRWLockShared = (void *)GetProcAddress(library, "AcquireSRWLockShared");
	pextAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlAcquireSRWLockShared");
	pAddVectoredContinueHandler = (void *)GetProcAddress(library, "AddVectoredContinueHandler");
	pextAddVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredContinueHandler");
	pAddVectoredExceptionHandler = (void *)GetProcAddress(library, "AddVectoredExceptionHandler");
	pextAddVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlAddVectoredExceptionHandler");
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
	pDecodePointer = (void *)GetProcAddress(library, "DecodePointer");
	pextDecodePointer = (void *)GetProcAddress(library_ntdll, "RtlDecodePointer");
	pDecodeSystemPointer = (void *)GetProcAddress(library, "DecodeSystemPointer");
	pextDecodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlDecodeSystemPointer");
	pDeleteCriticalSection = (void *)GetProcAddress(library, "DeleteCriticalSection");
	pextDeleteCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlDeleteCriticalSection");
	pDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library, "DisassociateCurrentThreadFromCallback");
	pextDisassociateCurrentThreadFromCallback = (void *)GetProcAddress(library_ntdll, "TpDisassociateCallback");
	pEncodePointer = (void *)GetProcAddress(library, "EncodePointer");
	pextEncodePointer = (void *)GetProcAddress(library_ntdll, "RtlEncodePointer");
	pEncodeSystemPointer = (void *)GetProcAddress(library, "EncodeSystemPointer");
	pextEncodeSystemPointer = (void *)GetProcAddress(library_ntdll, "RtlEncodeSystemPointer");
	pEnterCriticalSection = (void *)GetProcAddress(library, "EnterCriticalSection");
	pextEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlEnterCriticalSection");
	pExitThread = (void *)GetProcAddress(library, "ExitThread");
	pextExitThread = (void *)GetProcAddress(library_ntdll, "RtlExitUserThread");
	pFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library, "FreeLibraryWhenCallbackReturns");
	pextFreeLibraryWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackUnloadDllOnCompletion");
	pGetCurrentProcessorNumber = (void *)GetProcAddress(library, "GetCurrentProcessorNumber");
	pextGetCurrentProcessorNumber = (void *)GetProcAddress(library_ntdll, "NtGetCurrentProcessorNumber");
	pGetCurrentProcessorNumberEx = (void *)GetProcAddress(library, "GetCurrentProcessorNumberEx");
	pextGetCurrentProcessorNumberEx = (void *)GetProcAddress(library_ntdll, "RtlGetCurrentProcessorNumberEx");
	pGetSystemTimeAsFileTime = (void *)GetProcAddress(library, "GetSystemTimeAsFileTime");
	pextGetSystemTimeAsFileTime = (void *)GetProcAddress(library_ntdll, "NtQuerySystemTime");
	pHeapAlloc = (void *)GetProcAddress(library, "HeapAlloc");
	pextHeapAlloc = (void *)GetProcAddress(library_ntdll, "RtlAllocateHeap");
	pHeapReAlloc = (void *)GetProcAddress(library, "HeapReAlloc");
	pextHeapReAlloc = (void *)GetProcAddress(library_ntdll, "RtlReAllocateHeap");
	pHeapSize = (void *)GetProcAddress(library, "HeapSize");
	pextHeapSize = (void *)GetProcAddress(library_ntdll, "RtlSizeHeap");
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
	pIsThreadpoolTimerSet = (void *)GetProcAddress(library, "IsThreadpoolTimerSet");
	pextIsThreadpoolTimerSet = (void *)GetProcAddress(library_ntdll, "TpIsTimerSet");
	pLeaveCriticalSection = (void *)GetProcAddress(library, "LeaveCriticalSection");
	pextLeaveCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlLeaveCriticalSection");
	pLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library, "LeaveCriticalSectionWhenCallbackReturns");
	pextLeaveCriticalSectionWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackLeaveCriticalSectionOnCompletion");
	pQueryDepthSList = (void *)GetProcAddress(library, "QueryDepthSList");
	pextQueryDepthSList = (void *)GetProcAddress(library_ntdll, "RtlQueryDepthSList");
	pReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseMutexWhenCallbackReturns");
	pextReleaseMutexWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseMutexOnCompletion");
	pReleaseSRWLockExclusive = (void *)GetProcAddress(library, "ReleaseSRWLockExclusive");
	pextReleaseSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockExclusive");
	pReleaseSRWLockShared = (void *)GetProcAddress(library, "ReleaseSRWLockShared");
	pextReleaseSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlReleaseSRWLockShared");
	pReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library, "ReleaseSemaphoreWhenCallbackReturns");
	pextReleaseSemaphoreWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackReleaseSemaphoreOnCompletion");
	pRemoveVectoredContinueHandler = (void *)GetProcAddress(library, "RemoveVectoredContinueHandler");
	pextRemoveVectoredContinueHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredContinueHandler");
	pRemoveVectoredExceptionHandler = (void *)GetProcAddress(library, "RemoveVectoredExceptionHandler");
	pextRemoveVectoredExceptionHandler = (void *)GetProcAddress(library_ntdll, "RtlRemoveVectoredExceptionHandler");
	pResolveDelayLoadedAPI = (void *)GetProcAddress(library, "ResolveDelayLoadedAPI");
	pextResolveDelayLoadedAPI = (void *)GetProcAddress(library_ntdll, "LdrResolveDelayLoadedAPI");
	pRestoreLastError = (void *)GetProcAddress(library, "RestoreLastError");
	pextRestoreLastError = (void *)GetProcAddress(library_ntdll, "RtlRestoreLastWin32Error");
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
	pSetCriticalSectionSpinCount = (void *)GetProcAddress(library, "SetCriticalSectionSpinCount");
	pextSetCriticalSectionSpinCount = (void *)GetProcAddress(library_ntdll, "RtlSetCriticalSectionSpinCount");
	pSetEventWhenCallbackReturns = (void *)GetProcAddress(library, "SetEventWhenCallbackReturns");
	pextSetEventWhenCallbackReturns = (void *)GetProcAddress(library_ntdll, "TpCallbackSetEventOnCompletion");
	pSetThreadpoolThreadMaximum = (void *)GetProcAddress(library, "SetThreadpoolThreadMaximum");
	pextSetThreadpoolThreadMaximum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMaxThreads");
	pSetThreadpoolThreadMinimum = (void *)GetProcAddress(library, "SetThreadpoolThreadMinimum");
	pextSetThreadpoolThreadMinimum = (void *)GetProcAddress(library_ntdll, "TpSetPoolMinThreads");
	pSetThreadpoolTimer = (void *)GetProcAddress(library, "SetThreadpoolTimer");
	pextSetThreadpoolTimer = (void *)GetProcAddress(library_ntdll, "TpSetTimer");
	pSetThreadpoolWait = (void *)GetProcAddress(library, "SetThreadpoolWait");
	pextSetThreadpoolWait = (void *)GetProcAddress(library_ntdll, "TpSetWait");
	pSubmitThreadpoolWork = (void *)GetProcAddress(library, "SubmitThreadpoolWork");
	pextSubmitThreadpoolWork = (void *)GetProcAddress(library_ntdll, "TpPostWork");
	pTryAcquireSRWLockExclusive = (void *)GetProcAddress(library, "TryAcquireSRWLockExclusive");
	pextTryAcquireSRWLockExclusive = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockExclusive");
	pTryAcquireSRWLockShared = (void *)GetProcAddress(library, "TryAcquireSRWLockShared");
	pextTryAcquireSRWLockShared = (void *)GetProcAddress(library_ntdll, "RtlTryAcquireSRWLockShared");
	pTryEnterCriticalSection = (void *)GetProcAddress(library, "TryEnterCriticalSection");
	pextTryEnterCriticalSection = (void *)GetProcAddress(library_ntdll, "RtlTryEnterCriticalSection");
	pVerSetConditionMask = (void *)GetProcAddress(library, "VerSetConditionMask");
	pextVerSetConditionMask = (void *)GetProcAddress(library_ntdll, "VerSetConditionMask");
	pWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolTimerCallbacks");
	pextWaitForThreadpoolTimerCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForTimer");
	pWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWaitCallbacks");
	pextWaitForThreadpoolWaitCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWait");
	pWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library, "WaitForThreadpoolWorkCallbacks");
	pextWaitForThreadpoolWorkCallbacks = (void *)GetProcAddress(library_ntdll, "TpWaitForWork");
	pWakeAllConditionVariable = (void *)GetProcAddress(library, "WakeAllConditionVariable");
	pextWakeAllConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeAllConditionVariable");
	pWakeConditionVariable = (void *)GetProcAddress(library, "WakeConditionVariable");
	pextWakeConditionVariable = (void *)GetProcAddress(library_ntdll, "RtlWakeConditionVariable");
	pwine_get_dos_file_name = (void *)GetProcAddress(library, "wine_get_dos_file_name");
	pwine_get_unix_file_name = (void *)GetProcAddress(library, "wine_get_unix_file_name");
	initialized = TRUE;
}

void* wine_thunk_get_for_kernel32(void *func)
{
	if (!initialized)
		return NULL;

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
	if (func == pAllocConsole)
		return wine32a_kernel32_AllocConsole;
	if (func == pAllocateUserPhysicalPages)
		return wine32a_kernel32_AllocateUserPhysicalPages;
	if (func == pApplicationRecoveryFinished)
		return wine32a_kernel32_ApplicationRecoveryFinished;
	if (func == pApplicationRecoveryInProgress)
		return wine32a_kernel32_ApplicationRecoveryInProgress;
	if (func == pAssignProcessToJobObject)
		return wine32a_kernel32_AssignProcessToJobObject;
	if (func == pBackupRead)
		return wine32a_kernel32_BackupRead;
	if (func == pBackupSeek)
		return wine32a_kernel32_BackupSeek;
	if (func == pBackupWrite)
		return wine32a_kernel32_BackupWrite;
	if (func == pBaseFlushAppcompatCache)
		return wine32a_kernel32_BaseFlushAppcompatCache;
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
	if (func == pCallNamedPipeA)
		return wine32a_kernel32_CallNamedPipeA;
	if (func == pCancelTimerQueueTimer)
		return wine32a_kernel32_CancelTimerQueueTimer;
	if (func == pCheckNameLegalDOS8Dot3A)
		return wine32a_kernel32_CheckNameLegalDOS8Dot3A;
	if (func == pCheckNameLegalDOS8Dot3W)
		return wine32a_kernel32_CheckNameLegalDOS8Dot3W;
	if (func == pCloseConsoleHandle)
		return wine32a_kernel32_CloseConsoleHandle;
	if (func == pCloseHandle)
		return wine32a_kernel32_CloseHandle;
	if (func == pCloseProfileUserMapping)
		return wine32a_kernel32_CloseProfileUserMapping;
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
	if (func == pCompareStringEx)
		return wine32a_kernel32_CompareStringEx;
	if (func == pCompareStringOrdinal)
		return wine32a_kernel32_CompareStringOrdinal;
	if (func == pCompareStringW)
		return wine32a_kernel32_CompareStringW;
	if (func == pConvertDefaultLocale)
		return wine32a_kernel32_ConvertDefaultLocale;
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
	if (func == pCreateDirectoryExA)
		return wine32a_kernel32_CreateDirectoryExA;
	if (func == pCreateFileMappingA)
		return wine32a_kernel32_CreateFileMappingA;
	if (func == pCreateHardLinkA)
		return wine32a_kernel32_CreateHardLinkA;
	if (func == pCreateHardLinkTransactedA)
		return wine32a_kernel32_CreateHardLinkTransactedA;
	if (func == pCreateHardLinkTransactedW)
		return wine32a_kernel32_CreateHardLinkTransactedW;
	if (func == pCreateHardLinkW)
		return wine32a_kernel32_CreateHardLinkW;
	if (func == pCreateJobObjectA)
		return wine32a_kernel32_CreateJobObjectA;
	if (func == pCreateJobObjectW)
		return wine32a_kernel32_CreateJobObjectW;
	if (func == pCreateMailslotA)
		return wine32a_kernel32_CreateMailslotA;
	if (func == pCreateMailslotW)
		return wine32a_kernel32_CreateMailslotW;
	if (func == pCreateNamedPipeA)
		return wine32a_kernel32_CreateNamedPipeA;
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
	if (func == pCreateSemaphoreA)
		return wine32a_kernel32_CreateSemaphoreA;
	if (func == pCreateSemaphoreExA)
		return wine32a_kernel32_CreateSemaphoreExA;
	if (func == pCreateSocketHandle)
		return wine32a_kernel32_CreateSocketHandle;
	if (func == pCreateSymbolicLinkA)
		return wine32a_kernel32_CreateSymbolicLinkA;
	if (func == pCreateSymbolicLinkW)
		return wine32a_kernel32_CreateSymbolicLinkW;
	if (func == pCreateTapePartition)
		return wine32a_kernel32_CreateTapePartition;
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
	if (func == pDebugBreakProcess)
		return wine32a_kernel32_DebugBreakProcess;
	if (func == pDebugSetProcessKillOnExit)
		return wine32a_kernel32_DebugSetProcessKillOnExit;
	if (func == pDefineDosDeviceA)
		return wine32a_kernel32_DefineDosDeviceA;
	if (func == pDefineDosDeviceW)
		return wine32a_kernel32_DefineDosDeviceW;
	if (func == pDelayLoadFailureHook)
		return wine32a_kernel32_DelayLoadFailureHook;
	if (func == pDeleteAtom)
		return wine32a_kernel32_DeleteAtom;
	if (func == pDeleteTimerQueue)
		return wine32a_kernel32_DeleteTimerQueue;
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
	if (func == pEndUpdateResourceA)
		return wine32a_kernel32_EndUpdateResourceA;
	if (func == pEndUpdateResourceW)
		return wine32a_kernel32_EndUpdateResourceW;
	if (func == pEnterUmsSchedulingMode)
		return wine32a_kernel32_EnterUmsSchedulingMode;
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
	if (func == pEnumResourceLanguagesW)
		return wine32a_kernel32_EnumResourceLanguagesW;
	if (func == pEnumResourceNamesA)
		return wine32a_kernel32_EnumResourceNamesA;
	if (func == pEnumResourceTypesA)
		return wine32a_kernel32_EnumResourceTypesA;
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
	if (func == pEraseTape)
		return wine32a_kernel32_EraseTape;
	if (func == pExecuteUmsThread)
		return wine32a_kernel32_ExecuteUmsThread;
	if (func == pExitProcess)
		return wine32a_kernel32_ExitProcess;
	if (func == pExpungeConsoleCommandHistoryA)
		return wine32a_kernel32_ExpungeConsoleCommandHistoryA;
	if (func == pExpungeConsoleCommandHistoryW)
		return wine32a_kernel32_ExpungeConsoleCommandHistoryW;
	if (func == pFatalExit)
		return wine32a_kernel32_FatalExit;
	if (func == pFileTimeToDosDateTime)
		return wine32a_kernel32_FileTimeToDosDateTime;
	if (func == pFileTimeToLocalFileTime)
		return wine32a_kernel32_FileTimeToLocalFileTime;
	if (func == pFileTimeToSystemTime)
		return wine32a_kernel32_FileTimeToSystemTime;
	if (func == pFindActCtxSectionStringA)
		return wine32a_kernel32_FindActCtxSectionStringA;
	if (func == pFindAtomA)
		return wine32a_kernel32_FindAtomA;
	if (func == pFindAtomW)
		return wine32a_kernel32_FindAtomW;
	if (func == pFindClose)
		return wine32a_kernel32_FindClose;
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
	if (func == pFindNLSStringEx)
		return wine32a_kernel32_FindNLSStringEx;
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
	if (func == pFindResourceA)
		return wine32a_kernel32_FindResourceA;
	if (func == pFindResourceExA)
		return wine32a_kernel32_FindResourceExA;
	if (func == pFindStringOrdinal)
		return wine32a_kernel32_FindStringOrdinal;
	if (func == pFindVolumeClose)
		return wine32a_kernel32_FindVolumeClose;
	if (func == pFindVolumeMountPointClose)
		return wine32a_kernel32_FindVolumeMountPointClose;
	if (func == pFlushConsoleInputBuffer)
		return wine32a_kernel32_FlushConsoleInputBuffer;
	if (func == pFlushProcessWriteBuffers)
		return wine32a_kernel32_FlushProcessWriteBuffers;
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
	if (func == pFreeLibrary)
		return wine32a_kernel32_FreeLibrary;
	if (func == pFreeLibraryAndExitThread)
		return wine32a_kernel32_FreeLibraryAndExitThread;
	if (func == pFreeUserPhysicalPages)
		return wine32a_kernel32_FreeUserPhysicalPages;
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
	if (func == pGetCalendarInfoEx)
		return wine32a_kernel32_GetCalendarInfoEx;
	if (func == pGetCalendarInfoW)
		return wine32a_kernel32_GetCalendarInfoW;
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
	if (func == pGetConsoleCommandHistoryA)
		return wine32a_kernel32_GetConsoleCommandHistoryA;
	if (func == pGetConsoleCommandHistoryLengthA)
		return wine32a_kernel32_GetConsoleCommandHistoryLengthA;
	if (func == pGetConsoleCommandHistoryLengthW)
		return wine32a_kernel32_GetConsoleCommandHistoryLengthW;
	if (func == pGetConsoleCommandHistoryW)
		return wine32a_kernel32_GetConsoleCommandHistoryW;
	if (func == pGetConsoleDisplayMode)
		return wine32a_kernel32_GetConsoleDisplayMode;
	if (func == pGetConsoleFontInfo)
		return wine32a_kernel32_GetConsoleFontInfo;
	if (func == pGetConsoleFontSize)
		return wine32a_kernel32_GetConsoleFontSize;
	if (func == pGetConsoleInputWaitHandle)
		return wine32a_kernel32_GetConsoleInputWaitHandle;
	if (func == pGetConsoleKeyboardLayoutNameA)
		return wine32a_kernel32_GetConsoleKeyboardLayoutNameA;
	if (func == pGetConsoleKeyboardLayoutNameW)
		return wine32a_kernel32_GetConsoleKeyboardLayoutNameW;
	if (func == pGetConsoleProcessList)
		return wine32a_kernel32_GetConsoleProcessList;
	if (func == pGetConsoleTitleA)
		return wine32a_kernel32_GetConsoleTitleA;
	if (func == pGetConsoleWindow)
		return wine32a_kernel32_GetConsoleWindow;
	if (func == pGetCurrencyFormatA)
		return wine32a_kernel32_GetCurrencyFormatA;
	if (func == pGetCurrencyFormatEx)
		return wine32a_kernel32_GetCurrencyFormatEx;
	if (func == pGetCurrencyFormatW)
		return wine32a_kernel32_GetCurrencyFormatW;
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
	if (func == pGetExitCodeProcess)
		return wine32a_kernel32_GetExitCodeProcess;
	if (func == pGetExpandedNameA)
		return wine32a_kernel32_GetExpandedNameA;
	if (func == pGetExpandedNameW)
		return wine32a_kernel32_GetExpandedNameW;
	if (func == pGetFileMUIInfo)
		return wine32a_kernel32_GetFileMUIInfo;
	if (func == pGetFileMUIPath)
		return wine32a_kernel32_GetFileMUIPath;
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
	if (func == pGetLocalTime)
		return wine32a_kernel32_GetLocalTime;
	if (func == pGetLocaleInfoA)
		return wine32a_kernel32_GetLocaleInfoA;
	if (func == pGetLocaleInfoEx)
		return wine32a_kernel32_GetLocaleInfoEx;
	if (func == pGetLocaleInfoW)
		return wine32a_kernel32_GetLocaleInfoW;
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
	if (func == pGetNamedPipeClientProcessId)
		return wine32a_kernel32_GetNamedPipeClientProcessId;
	if (func == pGetNamedPipeClientSessionId)
		return wine32a_kernel32_GetNamedPipeClientSessionId;
	if (func == pGetNamedPipeHandleStateA)
		return wine32a_kernel32_GetNamedPipeHandleStateA;
	if (func == pGetNamedPipeHandleStateW)
		return wine32a_kernel32_GetNamedPipeHandleStateW;
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
	if (func == pGetNumberOfConsoleMouseButtons)
		return wine32a_kernel32_GetNumberOfConsoleMouseButtons;
	if (func == pGetOEMCP)
		return wine32a_kernel32_GetOEMCP;
	if (func == pGetPackageFullName)
		return wine32a_kernel32_GetPackageFullName;
	if (func == pGetPhysicallyInstalledSystemMemory)
		return wine32a_kernel32_GetPhysicallyInstalledSystemMemory;
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
	if (func == pGetProcessIoCounters)
		return wine32a_kernel32_GetProcessIoCounters;
	if (func == pGetProcessPreferredUILanguages)
		return wine32a_kernel32_GetProcessPreferredUILanguages;
	if (func == pGetProcessTimes)
		return wine32a_kernel32_GetProcessTimes;
	if (func == pGetProcessVersion)
		return wine32a_kernel32_GetProcessVersion;
	if (func == pGetProcessWorkingSetSize)
		return wine32a_kernel32_GetProcessWorkingSetSize;
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
	if (func == pGetShortPathNameA)
		return wine32a_kernel32_GetShortPathNameA;
	if (func == pGetShortPathNameW)
		return wine32a_kernel32_GetShortPathNameW;
	if (func == pGetStartupInfoA)
		return wine32a_kernel32_GetStartupInfoA;
	if (func == pGetStringTypeA)
		return wine32a_kernel32_GetStringTypeA;
	if (func == pGetStringTypeExA)
		return wine32a_kernel32_GetStringTypeExA;
	if (func == pGetStringTypeExW)
		return wine32a_kernel32_GetStringTypeExW;
	if (func == pGetStringTypeW)
		return wine32a_kernel32_GetStringTypeW;
	if (func == pGetSystemDEPPolicy)
		return wine32a_kernel32_GetSystemDEPPolicy;
	if (func == pGetSystemDefaultLCID)
		return wine32a_kernel32_GetSystemDefaultLCID;
	if (func == pGetSystemDefaultLangID)
		return wine32a_kernel32_GetSystemDefaultLangID;
	if (func == pGetSystemDefaultLocaleName)
		return wine32a_kernel32_GetSystemDefaultLocaleName;
	if (func == pGetSystemDefaultUILanguage)
		return wine32a_kernel32_GetSystemDefaultUILanguage;
	if (func == pGetSystemDirectoryA)
		return wine32a_kernel32_GetSystemDirectoryA;
	if (func == pGetSystemDirectoryW)
		return wine32a_kernel32_GetSystemDirectoryW;
	if (func == pGetSystemFileCacheSize)
		return wine32a_kernel32_GetSystemFileCacheSize;
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
	if (func == pGetSystemTimePreciseAsFileTime)
		return wine32a_kernel32_GetSystemTimePreciseAsFileTime;
	if (func == pGetSystemTimes)
		return wine32a_kernel32_GetSystemTimes;
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
	if (func == pGetThreadLocale)
		return wine32a_kernel32_GetThreadLocale;
	if (func == pGetThreadPreferredUILanguages)
		return wine32a_kernel32_GetThreadPreferredUILanguages;
	if (func == pGetThreadSelectorEntry)
		return wine32a_kernel32_GetThreadSelectorEntry;
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
	if (func == pGetUserPreferredUILanguages)
		return wine32a_kernel32_GetUserPreferredUILanguages;
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
	if (func == pGlobalAddAtomA)
		return wine32a_kernel32_GlobalAddAtomA;
	if (func == pGlobalAddAtomW)
		return wine32a_kernel32_GlobalAddAtomW;
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
	if (func == pHeapCreate)
		return wine32a_kernel32_HeapCreate;
	if (func == pHeapDestroy)
		return wine32a_kernel32_HeapDestroy;
	if (func == pHeapFree)
		return wine32a_kernel32_HeapFree;
	if (func == pIdnToAscii)
		return wine32a_kernel32_IdnToAscii;
	if (func == pIdnToNameprepUnicode)
		return wine32a_kernel32_IdnToNameprepUnicode;
	if (func == pIdnToUnicode)
		return wine32a_kernel32_IdnToUnicode;
	if (func == pInitAtomTable)
		return wine32a_kernel32_InitAtomTable;
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
	if (func == pIsNormalizedString)
		return wine32a_kernel32_IsNormalizedString;
	if (func == pIsProcessInJob)
		return wine32a_kernel32_IsProcessInJob;
	if (func == pIsProcessorFeaturePresent)
		return wine32a_kernel32_IsProcessorFeaturePresent;
	if (func == pIsSystemResumeAutomatic)
		return wine32a_kernel32_IsSystemResumeAutomatic;
	if (func == pIsValidCodePage)
		return wine32a_kernel32_IsValidCodePage;
	if (func == pIsValidLanguageGroup)
		return wine32a_kernel32_IsValidLanguageGroup;
	if (func == pIsValidLocale)
		return wine32a_kernel32_IsValidLocale;
	if (func == pIsValidLocaleName)
		return wine32a_kernel32_IsValidLocaleName;
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
	if (func == pGetCurrentProcess)
		return wine32a_kernel32_GetCurrentProcess;
	if (func == pGetCurrentProcessId)
		return wine32a_kernel32_GetCurrentProcessId;
	if (func == pGetCurrentThread)
		return wine32a_kernel32_GetCurrentThread;
	if (func == pGetCurrentThreadId)
		return wine32a_kernel32_GetCurrentThreadId;
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
	if (func == pLocalCompact)
		return wine32a_kernel32_LocalCompact;
	if (func == pLocalFileTimeToFileTime)
		return wine32a_kernel32_LocalFileTimeToFileTime;
	if (func == pLocalFlags)
		return wine32a_kernel32_LocalFlags;
	if (func == pLocalHandle)
		return wine32a_kernel32_LocalHandle;
	if (func == pLocalShrink)
		return wine32a_kernel32_LocalShrink;
	if (func == pLocalSize)
		return wine32a_kernel32_LocalSize;
	if (func == pLocaleNameToLCID)
		return wine32a_kernel32_LocaleNameToLCID;
	if (func == pMakeCriticalSectionGlobal)
		return wine32a_kernel32_MakeCriticalSectionGlobal;
	if (func == pMapUserPhysicalPages)
		return wine32a_kernel32_MapUserPhysicalPages;
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
	if (func == pOpenFile)
		return wine32a_kernel32_OpenFile;
	if (func == pOpenFileMappingA)
		return wine32a_kernel32_OpenFileMappingA;
	if (func == pOpenJobObjectA)
		return wine32a_kernel32_OpenJobObjectA;
	if (func == pOpenJobObjectW)
		return wine32a_kernel32_OpenJobObjectW;
	if (func == pOpenMutexA)
		return wine32a_kernel32_OpenMutexA;
	if (func == pOpenProfileUserMapping)
		return wine32a_kernel32_OpenProfileUserMapping;
	if (func == pOpenSemaphoreA)
		return wine32a_kernel32_OpenSemaphoreA;
	if (func == pOpenVxDHandle)
		return wine32a_kernel32_OpenVxDHandle;
	if (func == pOpenWaitableTimerA)
		return wine32a_kernel32_OpenWaitableTimerA;
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
	if (func == pQueryProcessCycleTime)
		return wine32a_kernel32_QueryProcessCycleTime;
	if (func == pQueryThreadCycleTime)
		return wine32a_kernel32_QueryThreadCycleTime;
	if (func == pQueryUmsThreadInformation)
		return wine32a_kernel32_QueryUmsThreadInformation;
	if (func == pQueryUnbiasedInterruptTime)
		return wine32a_kernel32_QueryUnbiasedInterruptTime;
	if (func == pReadConsoleInputW)
		return wine32a_kernel32_ReadConsoleInputW;
	if (func == pReadConsoleW)
		return wine32a_kernel32_ReadConsoleW;
	if (func == pRegisterApplicationRecoveryCallback)
		return wine32a_kernel32_RegisterApplicationRecoveryCallback;
	if (func == pRegisterApplicationRestart)
		return wine32a_kernel32_RegisterApplicationRestart;
	if (func == pRegisterServiceProcess)
		return wine32a_kernel32_RegisterServiceProcess;
	if (func == pRegisterWaitForSingleObject)
		return wine32a_kernel32_RegisterWaitForSingleObject;
	if (func == pReinitializeCriticalSection)
		return wine32a_kernel32_ReinitializeCriticalSection;
	if (func == pRemoveDirectoryA)
		return wine32a_kernel32_RemoveDirectoryA;
	if (func == pRemoveDirectoryW)
		return wine32a_kernel32_RemoveDirectoryW;
	if (func == pRemoveDllDirectory)
		return wine32a_kernel32_RemoveDllDirectory;
	if (func == pReplaceFileA)
		return wine32a_kernel32_ReplaceFileA;
	if (func == pReplaceFileW)
		return wine32a_kernel32_ReplaceFileW;
	if (func == pRequestDeviceWakeup)
		return wine32a_kernel32_RequestDeviceWakeup;
	if (func == pRequestWakeupLatency)
		return wine32a_kernel32_RequestWakeupLatency;
	if (func == pResolveLocaleName)
		return wine32a_kernel32_ResolveLocaleName;
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
	if (func == pSetComputerNameA)
		return wine32a_kernel32_SetComputerNameA;
	if (func == pSetComputerNameExA)
		return wine32a_kernel32_SetComputerNameExA;
	if (func == pSetComputerNameExW)
		return wine32a_kernel32_SetComputerNameExW;
	if (func == pSetComputerNameW)
		return wine32a_kernel32_SetComputerNameW;
	if (func == pSetConsoleCtrlHandler)
		return wine32a_kernel32_SetConsoleCtrlHandler;
	if (func == pSetConsoleDisplayMode)
		return wine32a_kernel32_SetConsoleDisplayMode;
	if (func == pSetConsoleFont)
		return wine32a_kernel32_SetConsoleFont;
	if (func == pSetConsoleIcon)
		return wine32a_kernel32_SetConsoleIcon;
	if (func == pSetConsoleKeyShortcuts)
		return wine32a_kernel32_SetConsoleKeyShortcuts;
	if (func == pSetConsoleTitleA)
		return wine32a_kernel32_SetConsoleTitleA;
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
	if (func == pSetFileCompletionNotificationModes)
		return wine32a_kernel32_SetFileCompletionNotificationModes;
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
	if (func == pSetProcessAffinityMask)
		return wine32a_kernel32_SetProcessAffinityMask;
	if (func == pSetProcessDEPPolicy)
		return wine32a_kernel32_SetProcessDEPPolicy;
	if (func == pSetProcessPreferredUILanguages)
		return wine32a_kernel32_SetProcessPreferredUILanguages;
	if (func == pSetProcessWorkingSetSize)
		return wine32a_kernel32_SetProcessWorkingSetSize;
	if (func == pSetSearchPathMode)
		return wine32a_kernel32_SetSearchPathMode;
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
	if (func == pSetThreadExecutionState)
		return wine32a_kernel32_SetThreadExecutionState;
	if (func == pSetThreadLocale)
		return wine32a_kernel32_SetThreadLocale;
	if (func == pSetThreadPreferredUILanguages)
		return wine32a_kernel32_SetThreadPreferredUILanguages;
	if (func == pSetThreadUILanguage)
		return wine32a_kernel32_SetThreadUILanguage;
	if (func == pSetTimeZoneInformation)
		return wine32a_kernel32_SetTimeZoneInformation;
	if (func == pSetUmsThreadInformation)
		return wine32a_kernel32_SetUmsThreadInformation;
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
	if (func == pSystemTimeToFileTime)
		return wine32a_kernel32_SystemTimeToFileTime;
	if (func == pSystemTimeToTzSpecificLocalTime)
		return wine32a_kernel32_SystemTimeToTzSpecificLocalTime;
	if (func == pTerminateJobObject)
		return wine32a_kernel32_TerminateJobObject;
	if (func == pTermsrvAppInstallMode)
		return wine32a_kernel32_TermsrvAppInstallMode;
	if (func == pThread32First)
		return wine32a_kernel32_Thread32First;
	if (func == pThread32Next)
		return wine32a_kernel32_Thread32Next;
	if (func == pToolhelp32ReadProcessMemory)
		return wine32a_kernel32_Toolhelp32ReadProcessMemory;
	if (func == pTzSpecificLocalTimeToSystemTime)
		return wine32a_kernel32_TzSpecificLocalTimeToSystemTime;
	if (func == pUmsThreadYield)
		return wine32a_kernel32_UmsThreadYield;
	if (func == pUninitializeCriticalSection)
		return wine32a_kernel32_UninitializeCriticalSection;
	if (func == pUnregisterApplicationRestart)
		return wine32a_kernel32_UnregisterApplicationRestart;
	if (func == pUnregisterWait)
		return wine32a_kernel32_UnregisterWait;
	if (func == pUpdateResourceA)
		return wine32a_kernel32_UpdateResourceA;
	if (func == pUpdateResourceW)
		return wine32a_kernel32_UpdateResourceW;
	if (func == pVerLanguageNameA)
		return wine32a_kernel32_VerLanguageNameA;
	if (func == pVerLanguageNameW)
		return wine32a_kernel32_VerLanguageNameW;
	if (func == pVerifyConsoleIoHandle)
		return wine32a_kernel32_VerifyConsoleIoHandle;
	if (func == pVerifyVersionInfoA)
		return wine32a_kernel32_VerifyVersionInfoA;
	if (func == pVerifyVersionInfoW)
		return wine32a_kernel32_VerifyVersionInfoW;
	if (func == pWTSGetActiveConsoleSessionId)
		return wine32a_kernel32_WTSGetActiveConsoleSessionId;
	if (func == pWaitNamedPipeA)
		return wine32a_kernel32_WaitNamedPipeA;
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
	if (func == pWow64GetThreadContext)
		return wine32a_kernel32_Wow64GetThreadContext;
	if (func == pWow64SetThreadContext)
		return wine32a_kernel32_Wow64SetThreadContext;
	if (func == pWriteConsoleW)
		return wine32a_kernel32_WriteConsoleW;
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
	if (func == p__wine_kernel_init)
		return wine32a_kernel32___wine_kernel_init;
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
	if (func == plstrcpyA)
		return wine32a_kernel32_lstrcpyA;
	if (func == plstrcpyW)
		return wine32a_kernel32_lstrcpyW;
	if (func == pAcquireSRWLockExclusive && func != pextAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextAcquireSRWLockExclusive);
	if (func == pAcquireSRWLockShared && func != pextAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextAcquireSRWLockShared);
	if (func == pAddVectoredContinueHandler && func != pextAddVectoredContinueHandler)
		return wine_thunk_get_for_any(pextAddVectoredContinueHandler);
	if (func == pAddVectoredExceptionHandler && func != pextAddVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextAddVectoredExceptionHandler);
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
	if (func == pDecodePointer && func != pextDecodePointer)
		return wine_thunk_get_for_any(pextDecodePointer);
	if (func == pDecodeSystemPointer && func != pextDecodeSystemPointer)
		return wine_thunk_get_for_any(pextDecodeSystemPointer);
	if (func == pDeleteCriticalSection && func != pextDeleteCriticalSection)
		return wine_thunk_get_for_any(pextDeleteCriticalSection);
	if (func == pDisassociateCurrentThreadFromCallback && func != pextDisassociateCurrentThreadFromCallback)
		return wine_thunk_get_for_any(pextDisassociateCurrentThreadFromCallback);
	if (func == pEncodePointer && func != pextEncodePointer)
		return wine_thunk_get_for_any(pextEncodePointer);
	if (func == pEncodeSystemPointer && func != pextEncodeSystemPointer)
		return wine_thunk_get_for_any(pextEncodeSystemPointer);
	if (func == pEnterCriticalSection && func != pextEnterCriticalSection)
		return wine_thunk_get_for_any(pextEnterCriticalSection);
	if (func == pExitThread && func != pextExitThread)
		return wine_thunk_get_for_any(pextExitThread);
	if (func == pFreeLibraryWhenCallbackReturns && func != pextFreeLibraryWhenCallbackReturns)
		return wine_thunk_get_for_any(pextFreeLibraryWhenCallbackReturns);
	if (func == pGetCurrentProcessorNumber && func != pextGetCurrentProcessorNumber)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumber);
	if (func == pGetCurrentProcessorNumberEx && func != pextGetCurrentProcessorNumberEx)
		return wine_thunk_get_for_any(pextGetCurrentProcessorNumberEx);
	if (func == pGetSystemTimeAsFileTime && func != pextGetSystemTimeAsFileTime)
		return wine_thunk_get_for_any(pextGetSystemTimeAsFileTime);
	if (func == pHeapAlloc && func != pextHeapAlloc)
		return wine_thunk_get_for_any(pextHeapAlloc);
	if (func == pHeapReAlloc && func != pextHeapReAlloc)
		return wine_thunk_get_for_any(pextHeapReAlloc);
	if (func == pHeapSize && func != pextHeapSize)
		return wine_thunk_get_for_any(pextHeapSize);
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
	if (func == pIsThreadpoolTimerSet && func != pextIsThreadpoolTimerSet)
		return wine_thunk_get_for_any(pextIsThreadpoolTimerSet);
	if (func == pLeaveCriticalSection && func != pextLeaveCriticalSection)
		return wine_thunk_get_for_any(pextLeaveCriticalSection);
	if (func == pLeaveCriticalSectionWhenCallbackReturns && func != pextLeaveCriticalSectionWhenCallbackReturns)
		return wine_thunk_get_for_any(pextLeaveCriticalSectionWhenCallbackReturns);
	if (func == pQueryDepthSList && func != pextQueryDepthSList)
		return wine_thunk_get_for_any(pextQueryDepthSList);
	if (func == pReleaseMutexWhenCallbackReturns && func != pextReleaseMutexWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseMutexWhenCallbackReturns);
	if (func == pReleaseSRWLockExclusive && func != pextReleaseSRWLockExclusive)
		return wine_thunk_get_for_any(pextReleaseSRWLockExclusive);
	if (func == pReleaseSRWLockShared && func != pextReleaseSRWLockShared)
		return wine_thunk_get_for_any(pextReleaseSRWLockShared);
	if (func == pReleaseSemaphoreWhenCallbackReturns && func != pextReleaseSemaphoreWhenCallbackReturns)
		return wine_thunk_get_for_any(pextReleaseSemaphoreWhenCallbackReturns);
	if (func == pRemoveVectoredContinueHandler && func != pextRemoveVectoredContinueHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredContinueHandler);
	if (func == pRemoveVectoredExceptionHandler && func != pextRemoveVectoredExceptionHandler)
		return wine_thunk_get_for_any(pextRemoveVectoredExceptionHandler);
	if (func == pResolveDelayLoadedAPI && func != pextResolveDelayLoadedAPI)
		return wine_thunk_get_for_any(pextResolveDelayLoadedAPI);
	if (func == pRestoreLastError && func != pextRestoreLastError)
		return wine_thunk_get_for_any(pextRestoreLastError);
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
	if (func == pSetCriticalSectionSpinCount && func != pextSetCriticalSectionSpinCount)
		return wine_thunk_get_for_any(pextSetCriticalSectionSpinCount);
	if (func == pSetEventWhenCallbackReturns && func != pextSetEventWhenCallbackReturns)
		return wine_thunk_get_for_any(pextSetEventWhenCallbackReturns);
	if (func == pSetThreadpoolThreadMaximum && func != pextSetThreadpoolThreadMaximum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMaximum);
	if (func == pSetThreadpoolThreadMinimum && func != pextSetThreadpoolThreadMinimum)
		return wine_thunk_get_for_any(pextSetThreadpoolThreadMinimum);
	if (func == pSetThreadpoolTimer && func != pextSetThreadpoolTimer)
		return wine_thunk_get_for_any(pextSetThreadpoolTimer);
	if (func == pSetThreadpoolWait && func != pextSetThreadpoolWait)
		return wine_thunk_get_for_any(pextSetThreadpoolWait);
	if (func == pSubmitThreadpoolWork && func != pextSubmitThreadpoolWork)
		return wine_thunk_get_for_any(pextSubmitThreadpoolWork);
	if (func == pTryAcquireSRWLockExclusive && func != pextTryAcquireSRWLockExclusive)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockExclusive);
	if (func == pTryAcquireSRWLockShared && func != pextTryAcquireSRWLockShared)
		return wine_thunk_get_for_any(pextTryAcquireSRWLockShared);
	if (func == pTryEnterCriticalSection && func != pextTryEnterCriticalSection)
		return wine_thunk_get_for_any(pextTryEnterCriticalSection);
	if (func == pVerSetConditionMask && func != pextVerSetConditionMask)
		return wine_thunk_get_for_any(pextVerSetConditionMask);
	if (func == pWaitForThreadpoolTimerCallbacks && func != pextWaitForThreadpoolTimerCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolTimerCallbacks);
	if (func == pWaitForThreadpoolWaitCallbacks && func != pextWaitForThreadpoolWaitCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWaitCallbacks);
	if (func == pWaitForThreadpoolWorkCallbacks && func != pextWaitForThreadpoolWorkCallbacks)
		return wine_thunk_get_for_any(pextWaitForThreadpoolWorkCallbacks);
	if (func == pWakeAllConditionVariable && func != pextWakeAllConditionVariable)
		return wine_thunk_get_for_any(pextWakeAllConditionVariable);
	if (func == pWakeConditionVariable && func != pextWakeConditionVariable)
		return wine_thunk_get_for_any(pextWakeConditionVariable);
	if (func == pwine_get_dos_file_name)
		return wine32a_kernel32_wine_get_dos_file_name;
	if (func == pwine_get_unix_file_name)
		return wine32a_kernel32_wine_get_unix_file_name;

	return NULL;
}

