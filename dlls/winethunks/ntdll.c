#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
#include "wine/winethunks.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

struct iovec; /* /usr/include/bits/types/struct_iovec.h:26 */
enum _EVENT_TYPE; /* ../include/ntdef.h:26 */
enum _TIMER_TYPE; /* ../include/ntdef.h:31 */
struct _STRING; /* ../include/winternl.h:48 */
struct _UNICODE_STRING; /* ../include/winternl.h:65 */
struct _RTL_SYSTEM_TIME; /* ../include/winternl.h:97 */
struct _RTL_TIME_ZONE_INFORMATION; /* ../include/winternl.h:108 */
struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION; /* ../include/winternl.h:118 */
struct _CLIENT_ID; /* ../include/winternl.h:131 */
struct _CURDIR; /* ../include/winternl.h:137 */
struct RTL_DRIVE_LETTER_CURDIR; /* ../include/winternl.h:143 */
struct _RTL_RELATIVE_NAME; /* ../include/winternl.h:151 */
struct tagRTL_BITMAP; /* ../include/winternl.h:158 */
struct tagRTL_BITMAP_RUN; /* ../include/winternl.h:165 */
struct _RTL_USER_PROCESS_PARAMETERS; /* ../include/winternl.h:172 */
struct _PEB_LDR_DATA; /* ../include/winternl.h:207 */
struct _TEB_ACTIVE_FRAME_CONTEXT; /* ../include/winternl.h:240 */
struct _TEB_ACTIVE_FRAME; /* ../include/winternl.h:252 */
struct _PEB; /* ../include/winternl.h:271 */
enum _FILE_INFORMATION_CLASS; /* ../include/winternl.h:424 */
struct _FILE_BASIC_INFORMATION; /* ../include/winternl.h:590 */
struct _FILE_NETWORK_OPEN_INFORMATION; /* ../include/winternl.h:673 */
enum _FSINFOCLASS; /* ../include/winternl.h:793 */
enum _KEY_INFORMATION_CLASS; /* ../include/winternl.h:805 */
enum _KEY_VALUE_INFORMATION_CLASS; /* ../include/winternl.h:817 */
enum _OBJECT_INFORMATION_CLASS; /* ../include/winternl.h:825 */
enum _PROCESSINFOCLASS; /* ../include/winternl.h:833 */
enum _SECTION_INHERIT; /* ../include/winternl.h:885 */
enum _SYSTEM_INFORMATION_CLASS; /* ../include/winternl.h:890 */
enum _THREADINFOCLASS; /* ../include/winternl.h:976 */
enum _MEMORY_INFORMATION_CLASS; /* ../include/winternl.h:1041 */
enum _MUTANT_INFORMATION_CLASS; /* ../include/winternl.h:1053 */
enum _TIMER_INFORMATION_CLASS; /* ../include/winternl.h:1064 */
enum DOS_PATHNAME_TYPE; /* ../include/winternl.h:1077 */
struct _IO_STATUS_BLOCK; /* ../include/winternl.h:1111 */
struct _OBJECT_ATTRIBUTES; /* ../include/winternl.h:1205 */
struct _RTL_HEAP_DEFINITION; /* ../include/winternl.h:1272 */
struct _RTL_RWLOCK; /* ../include/winternl.h:1278 */
struct _TIME_FIELDS; /* ../include/winternl.h:1604 */
struct _LDR_RESOURCE_INFO; /* ../include/winternl.h:1623 */
struct _DEBUG_BUFFER; /* ../include/winternl.h:1633 */
enum _ATOM_INFORMATION_CLASS; /* ../include/winternl.h:1716 */
struct _RTL_HANDLE; /* ../include/winternl.h:1729 */
struct _RTL_HANDLE_TABLE; /* ../include/winternl.h:1735 */
struct _RTL_QUERY_REGISTRY_TABLE; /* ../include/winternl.h:1948 */
struct _KEY_MULTIPLE_VALUE_INFORMATION; /* ../include/winternl.h:1959 */
enum _EVENT_INFORMATION_CLASS; /* ../include/winternl.h:1971 */
enum _SEMAPHORE_INFORMATION_CLASS; /* ../include/winternl.h:1980 */
enum _SECTION_INFORMATION_CLASS; /* ../include/winternl.h:1989 */
struct _SECTION_IMAGE_INFORMATION; /* ../include/winternl.h:2001 */
struct _LPC_SECTION_WRITE; /* ../include/winternl.h:2032 */
struct _LPC_SECTION_READ; /* ../include/winternl.h:2041 */
struct _LPC_MESSAGE; /* ../include/winternl.h:2047 */
struct _RTL_USER_PROCESS_INFORMATION; /* ../include/winternl.h:2058 */
enum _SHUTDOWN_ACTION; /* ../include/winternl.h:2067 */
struct _COUNTED_REASON_CONTEXT; /* ../include/winternl.h:2073 */
enum _KPROFILE_SOURCE; /* ../include/winternl.h:2090 */
struct _DIRECTORY_BASIC_INFORMATION; /* ../include/winternl.h:2118 */
struct _INITIAL_TEB; /* ../include/winternl.h:2123 */
enum _IO_COMPLETION_INFORMATION_CLASS; /* ../include/winternl.h:2135 */
struct _FILE_IO_COMPLETION_INFORMATION; /* ../include/winternl.h:2148 */
enum _HARDERROR_RESPONSE_OPTION; /* ../include/winternl.h:2154 */
enum _HARDERROR_RESPONSE; /* ../include/winternl.h:2164 */
enum _SYSDBG_COMMAND; /* ../include/winternl.h:2176 */
struct _LDR_MODULE; /* ../include/winternl.h:2205 */
struct _LDR_DLL_LOADED_NOTIFICATION_DATA; /* ../include/winternl.h:2224 */
struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA; /* ../include/winternl.h:2233 */
union _LDR_DLL_NOTIFICATION_DATA; /* ../include/winternl.h:2242 */
struct _SYSTEM_MODULE; /* ../include/winternl.h:2272 */
struct _SYSTEM_MODULE_INFORMATION; /* ../include/winternl.h:2286 */
struct cp_info; /* ../include/wine/unicode.h:47 */
struct sbcs_table; /* ../include/wine/unicode.h:56 */
struct dbcs_table; /* ../include/wine/unicode.h:65 */
union cptable; /* ../include/wine/unicode.h:75 */
struct SHA_CTX; /* ../dlls/ntdll/crypt.c:29 */
struct MD4_CTX; /* ../dlls/ntdll/crypt.c:222 */
struct MD5_CTX; /* ../dlls/ntdll/crypt.c:464 */
struct msghdr; /* /usr/include/bits/socket.h:257 */
struct _RTL_BALANCED_LINKS; /* ../include/ddk/ntddk.h:143 */
enum _RTL_GENERIC_COMPARE_RESULTS; /* ../include/ddk/ntddk.h:154 */
struct _RTL_AVL_TABLE; /* ../include/ddk/ntddk.h:166 */
struct _DELAYLOAD_PROC_DESCRIPTOR; /* ../include/delayloadhandler.h:28 */
struct _DELAYLOAD_INFO; /* ../include/delayloadhandler.h:37 */
struct _RTL_UNLOAD_EVENT_TRACE; /* ../dlls/ntdll/loader.c:166 */
enum WMIDPREQUESTCODE; /* ../include/wmistr.h:40 */
struct _TRACE_GUID_REGISTRATION; /* ../include/evntrace.h:83 */
struct _EVENT_TRACE_HEADER; /* ../include/evntrace.h:98 */
struct _EVENT_DATA_DESCRIPTOR; /* ../include/evntprov.h:31 */
struct _EVENT_DESCRIPTOR; /* ../include/evntprov.h:38 */
struct _EVENT_FILTER_DESCRIPTOR; /* ../include/evntprov.h:52 */
enum _EVENT_INFO_CLASS; /* ../include/evntprov.h:62 */
struct WS_in_addr; /* ../include/inaddr.h:29 */
struct WS_in6_addr; /* ../include/in6addr.h:28 */

typedef long __ssize_t; /* /usr/include/bits/types.h:193 */

typedef unsigned int __socklen_t; /* /usr/include/bits/types.h:209 */

typedef unsigned long size_t; /* /usr/lib/clang/8.0.1/include/stddef.h:62 */

struct iovec /* /usr/include/bits/types/struct_iovec.h:26 */
{
    void* iov_base;
    size_t iov_len;
};


typedef __ssize_t ssize_t; /* /usr/include/sys/types.h:108 */

typedef __socklen_t socklen_t; /* /usr/include/unistd.h:274 */

enum _EVENT_TYPE /* ../include/ntdef.h:26 */
{
    _EVENT_TYPE_DUMMY = 0
};


typedef enum _EVENT_TYPE EVENT_TYPE; /* ../include/ntdef.h:29 */

enum _TIMER_TYPE /* ../include/ntdef.h:31 */
{
    _TIMER_TYPE_DUMMY = 0
};


typedef enum _TIMER_TYPE TIMER_TYPE; /* ../include/ntdef.h:34 */

typedef unsigned long ULONG64; /* ../include/basetsd.h:99 */

typedef long INT_PTR; /* ../include/basetsd.h:117 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef unsigned long* PULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR SIZE_T; /* ../include/basetsd.h:264 */

typedef ULONG_PTR* PSIZE_T; /* ../include/basetsd.h:264 */

typedef LONG NTSTATUS; /* ../include/winternl.h:38 */

typedef char* PCSZ; /* ../include/winternl.h:41 */

typedef short CSHORT; /* ../include/winternl.h:43 */

struct _STRING /* ../include/winternl.h:48 */
{
    USHORT Length;
    USHORT MaximumLength;
    PCHAR Buffer;
};


typedef struct _STRING STRING; /* ../include/winternl.h:52 */

typedef struct _STRING* PSTRING; /* ../include/winternl.h:52 */

typedef STRING ANSI_STRING; /* ../include/winternl.h:55 */

typedef PSTRING PANSI_STRING; /* ../include/winternl.h:56 */

typedef STRING* PCANSI_STRING; /* ../include/winternl.h:57 */

typedef STRING OEM_STRING; /* ../include/winternl.h:59 */

struct _UNICODE_STRING /* ../include/winternl.h:65 */
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
};


typedef struct _UNICODE_STRING UNICODE_STRING; /* ../include/winternl.h:69 */

typedef struct _UNICODE_STRING* PUNICODE_STRING; /* ../include/winternl.h:69 */

typedef UNICODE_STRING* PCUNICODE_STRING; /* ../include/winternl.h:72 */

struct _RTL_SYSTEM_TIME /* ../include/winternl.h:97 */
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};


typedef struct _RTL_SYSTEM_TIME RTL_SYSTEM_TIME; /* ../include/winternl.h:106 */

struct _RTL_TIME_ZONE_INFORMATION /* ../include/winternl.h:108 */
{
    LONG Bias;
    WCHAR StandardName[32];
    RTL_SYSTEM_TIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    RTL_SYSTEM_TIME DaylightDate;
    LONG DaylightBias;
};


typedef struct _RTL_TIME_ZONE_INFORMATION RTL_TIME_ZONE_INFORMATION; /* ../include/winternl.h:116 */

struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION /* ../include/winternl.h:118 */
{
    LONG Bias;
    WCHAR StandardName[32];
    RTL_SYSTEM_TIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    RTL_SYSTEM_TIME DaylightDate;
    LONG DaylightBias;
    WCHAR TimeZoneKeyName[128];
    BOOLEAN DynamicDaylightTimeDisabled;
};


typedef struct _RTL_TIME_DYNAMIC_ZONE_INFORMATION RTL_DYNAMIC_TIME_ZONE_INFORMATION; /* ../include/winternl.h:129 */

struct _CLIENT_ID /* ../include/winternl.h:131 */
{
    HANDLE UniqueProcess;
    HANDLE UniqueThread;
};


typedef struct _CLIENT_ID CLIENT_ID; /* ../include/winternl.h:135 */

struct _CURDIR /* ../include/winternl.h:137 */
{
    UNICODE_STRING DosPath;
    PVOID Handle;
};


typedef struct _CURDIR CURDIR; /* ../include/winternl.h:141 */

struct RTL_DRIVE_LETTER_CURDIR /* ../include/winternl.h:143 */
{
    USHORT Flags;
    USHORT Length;
    ULONG TimeStamp;
    UNICODE_STRING DosPath;
};


typedef struct RTL_DRIVE_LETTER_CURDIR RTL_DRIVE_LETTER_CURDIR; /* ../include/winternl.h:149 */

struct _RTL_RELATIVE_NAME /* ../include/winternl.h:151 */
{
    UNICODE_STRING RelativeName;
    HANDLE ContainerDirectory;
    void* CurDirRef;
};


typedef struct _RTL_RELATIVE_NAME RTL_RELATIVE_NAME; /* ../include/winternl.h:156 */

struct tagRTL_BITMAP /* ../include/winternl.h:158 */
{
    ULONG SizeOfBitMap;
    PULONG Buffer;
};


typedef struct tagRTL_BITMAP RTL_BITMAP; /* ../include/winternl.h:161 */

typedef struct tagRTL_BITMAP* PRTL_BITMAP; /* ../include/winternl.h:161 */

typedef RTL_BITMAP* PCRTL_BITMAP; /* ../include/winternl.h:163 */

struct tagRTL_BITMAP_RUN /* ../include/winternl.h:165 */
{
    ULONG StartingIndex;
    ULONG NumberOfBits;
};


typedef struct tagRTL_BITMAP_RUN* PRTL_BITMAP_RUN; /* ../include/winternl.h:168 */

struct _RTL_USER_PROCESS_PARAMETERS /* ../include/winternl.h:172 */
{
    ULONG AllocationSize;
    ULONG Size;
    ULONG Flags;
    ULONG DebugFlags;
    HANDLE ConsoleHandle;
    ULONG ConsoleFlags;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
    CURDIR CurrentDirectory;
    UNICODE_STRING DllPath;
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    PWSTR Environment;
    ULONG dwX;
    ULONG dwY;
    ULONG dwXSize;
    ULONG dwYSize;
    ULONG dwXCountChars;
    ULONG dwYCountChars;
    ULONG dwFillAttribute;
    ULONG dwFlags;
    ULONG wShowWindow;
    UNICODE_STRING WindowTitle;
    UNICODE_STRING Desktop;
    UNICODE_STRING ShellInfo;
    UNICODE_STRING RuntimeInfo;
    RTL_DRIVE_LETTER_CURDIR DLCurrentDirectory[32];
};


typedef struct _RTL_USER_PROCESS_PARAMETERS RTL_USER_PROCESS_PARAMETERS; /* ../include/winternl.h:202 */

typedef struct _RTL_USER_PROCESS_PARAMETERS* PRTL_USER_PROCESS_PARAMETERS; /* ../include/winternl.h:202 */

struct _PEB_LDR_DATA /* ../include/winternl.h:207 */
{
    ULONG Length;
    BOOLEAN Initialized;
    PVOID SsHandle;
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    PVOID EntryInProgress;
};


typedef struct _PEB_LDR_DATA* PPEB_LDR_DATA; /* ../include/winternl.h:216 */

struct _TEB_ACTIVE_FRAME_CONTEXT /* ../include/winternl.h:240 */
{
    ULONG Flags;
    char* FrameName;
};


typedef struct _TEB_ACTIVE_FRAME_CONTEXT TEB_ACTIVE_FRAME_CONTEXT; /* ../include/winternl.h:244 */

struct _TEB_ACTIVE_FRAME /* ../include/winternl.h:252 */
{
    ULONG Flags;
    struct _TEB_ACTIVE_FRAME* Previous;
    TEB_ACTIVE_FRAME_CONTEXT* Context;
};


typedef struct _TEB_ACTIVE_FRAME TEB_ACTIVE_FRAME; /* ../include/winternl.h:257 */

struct _PEB /* ../include/winternl.h:271 */
{
    BOOLEAN InheritedAddressSpace;
    BOOLEAN ReadImageFileExecOptions;
    BOOLEAN BeingDebugged;
    BOOLEAN SpareBool;
    HANDLE Mutant;
    HMODULE ImageBaseAddress;
    PPEB_LDR_DATA LdrData;
    RTL_USER_PROCESS_PARAMETERS* ProcessParameters;
    PVOID SubSystemData;
    HANDLE ProcessHeap;
    PRTL_CRITICAL_SECTION FastPebLock;
    PVOID FastPebLockRoutine;
    PVOID FastPebUnlockRoutine;
    ULONG EnvironmentUpdateCount;
    PVOID KernelCallbackTable;
    ULONG Reserved[2];
    PVOID FreeList;
    ULONG TlsExpansionCounter;
    PRTL_BITMAP TlsBitmap;
    ULONG TlsBitmapBits[2];
    PVOID ReadOnlySharedMemoryBase;
    PVOID ReadOnlySharedMemoryHeap;
    PVOID* ReadOnlyStaticServerData;
    PVOID AnsiCodePageData;
    PVOID OemCodePageData;
    PVOID UnicodeCaseTableData;
    ULONG NumberOfProcessors;
    ULONG NtGlobalFlag;
    LARGE_INTEGER CriticalSectionTimeout;
    SIZE_T HeapSegmentReserve;
    SIZE_T HeapSegmentCommit;
    SIZE_T HeapDeCommitTotalFreeThreshold;
    SIZE_T HeapDeCommitFreeBlockThreshold;
    ULONG NumberOfHeaps;
    ULONG MaximumNumberOfHeaps;
    PVOID* ProcessHeaps;
    PVOID GdiSharedHandleTable;
    PVOID ProcessStarterHelper;
    PVOID GdiDCAttributeList;
    PVOID LoaderLock;
    ULONG OSMajorVersion;
    ULONG OSMinorVersion;
    ULONG OSBuildNumber;
    ULONG OSPlatformId;
    ULONG ImageSubSystem;
    ULONG ImageSubSystemMajorVersion;
    ULONG ImageSubSystemMinorVersion;
    ULONG ImageProcessAffinityMask;
    HANDLE GdiHandleBuffer[28];
    ULONG unknown[6];
    PVOID PostProcessInitRoutine;
    PRTL_BITMAP TlsExpansionBitmap;
    ULONG TlsExpansionBitmapBits[32];
    ULONG SessionId;
    ULARGE_INTEGER AppCompatFlags;
    ULARGE_INTEGER AppCompatFlagsUser;
    PVOID ShimData;
    PVOID AppCompatInfo;
    UNICODE_STRING CSDVersion;
    PVOID ActivationContextData;
    PVOID ProcessAssemblyStorageMap;
    PVOID SystemDefaultActivationData;
    PVOID SystemAssemblyStorageMap;
    SIZE_T MinimumStackCommit;
    PVOID* FlsCallback;
    LIST_ENTRY FlsListHead;
    PRTL_BITMAP FlsBitmap;
    ULONG FlsBitmapBits[4];
};


typedef struct _PEB PEB; /* ../include/winternl.h:341 */

enum _FILE_INFORMATION_CLASS /* ../include/winternl.h:424 */
{
    _FILE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _FILE_INFORMATION_CLASS FILE_INFORMATION_CLASS; /* ../include/winternl.h:489 */

struct _FILE_BASIC_INFORMATION /* ../include/winternl.h:590 */
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    ULONG FileAttributes;
};


typedef struct _FILE_BASIC_INFORMATION FILE_BASIC_INFORMATION; /* ../include/winternl.h:596 */

struct _FILE_NETWORK_OPEN_INFORMATION /* ../include/winternl.h:673 */
{
    LARGE_INTEGER CreationTime;
    LARGE_INTEGER LastAccessTime;
    LARGE_INTEGER LastWriteTime;
    LARGE_INTEGER ChangeTime;
    LARGE_INTEGER AllocationSize;
    LARGE_INTEGER EndOfFile;
    ULONG FileAttributes;
};


typedef struct _FILE_NETWORK_OPEN_INFORMATION FILE_NETWORK_OPEN_INFORMATION; /* ../include/winternl.h:681 */

enum _FSINFOCLASS /* ../include/winternl.h:793 */
{
    _FSINFOCLASS_DUMMY = 0
};


typedef enum _FSINFOCLASS FS_INFORMATION_CLASS; /* ../include/winternl.h:803 */

enum _KEY_INFORMATION_CLASS /* ../include/winternl.h:805 */
{
    _KEY_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _KEY_INFORMATION_CLASS KEY_INFORMATION_CLASS; /* ../include/winternl.h:815 */

enum _KEY_VALUE_INFORMATION_CLASS /* ../include/winternl.h:817 */
{
    _KEY_VALUE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _KEY_VALUE_INFORMATION_CLASS KEY_VALUE_INFORMATION_CLASS; /* ../include/winternl.h:823 */

enum _OBJECT_INFORMATION_CLASS /* ../include/winternl.h:825 */
{
    _OBJECT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _OBJECT_INFORMATION_CLASS OBJECT_INFORMATION_CLASS; /* ../include/winternl.h:831 */

enum _PROCESSINFOCLASS /* ../include/winternl.h:833 */
{
    _PROCESSINFOCLASS_DUMMY = 0
};


typedef enum _PROCESSINFOCLASS PROCESSINFOCLASS; /* ../include/winternl.h:878 */

enum _SECTION_INHERIT /* ../include/winternl.h:885 */
{
    _SECTION_INHERIT_DUMMY = 0
};


typedef enum _SECTION_INHERIT SECTION_INHERIT; /* ../include/winternl.h:888 */

enum _SYSTEM_INFORMATION_CLASS /* ../include/winternl.h:890 */
{
    _SYSTEM_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SYSTEM_INFORMATION_CLASS SYSTEM_INFORMATION_CLASS; /* ../include/winternl.h:974 */

enum _THREADINFOCLASS /* ../include/winternl.h:976 */
{
    _THREADINFOCLASS_DUMMY = 0
};


typedef enum _THREADINFOCLASS THREADINFOCLASS; /* ../include/winternl.h:1012 */

enum _MEMORY_INFORMATION_CLASS /* ../include/winternl.h:1041 */
{
    _MEMORY_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _MEMORY_INFORMATION_CLASS MEMORY_INFORMATION_CLASS; /* ../include/winternl.h:1046 */

enum _MUTANT_INFORMATION_CLASS /* ../include/winternl.h:1053 */
{
    _MUTANT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _MUTANT_INFORMATION_CLASS MUTANT_INFORMATION_CLASS; /* ../include/winternl.h:1056 */

enum _TIMER_INFORMATION_CLASS /* ../include/winternl.h:1064 */
{
    _TIMER_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _TIMER_INFORMATION_CLASS TIMER_INFORMATION_CLASS; /* ../include/winternl.h:1067 */

enum DOS_PATHNAME_TYPE /* ../include/winternl.h:1077 */
{
    DOS_PATHNAME_TYPE_DUMMY = 0
};


typedef enum DOS_PATHNAME_TYPE DOS_PATHNAME_TYPE; /* ../include/winternl.h:1087 */

struct _IO_STATUS_BLOCK /* ../include/winternl.h:1111 */
{
    ULONG_PTR Information;
};


typedef struct _IO_STATUS_BLOCK IO_STATUS_BLOCK; /* ../include/winternl.h:1118 */

typedef struct _IO_STATUS_BLOCK* PIO_STATUS_BLOCK; /* ../include/winternl.h:1118 */

typedef void (*PIO_APC_ROUTINE) (PVOID, PIO_STATUS_BLOCK, ULONG); /* ../include/winternl.h:1120 */

struct _OBJECT_ATTRIBUTES /* ../include/winternl.h:1205 */
{
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;
    PVOID SecurityQualityOfService;
};


typedef struct _OBJECT_ATTRIBUTES OBJECT_ATTRIBUTES; /* ../include/winternl.h:1212 */

typedef struct _OBJECT_ATTRIBUTES* POBJECT_ATTRIBUTES; /* ../include/winternl.h:1212 */

struct _RTL_HEAP_DEFINITION /* ../include/winternl.h:1272 */
{
    ULONG Length;
    ULONG Unknown[11];
};


typedef struct _RTL_HEAP_DEFINITION* PRTL_HEAP_DEFINITION; /* ../include/winternl.h:1276 */

struct _RTL_RWLOCK /* ../include/winternl.h:1278 */
{
    RTL_CRITICAL_SECTION rtlCS;
    HANDLE hSharedReleaseSemaphore;
    UINT uSharedWaiters;
    HANDLE hExclusiveReleaseSemaphore;
    UINT uExclusiveWaiters;
    INT iNumberActive;
    HANDLE hOwningThreadId;
    DWORD dwTimeoutBoost;
    PVOID pDebugInfo;
};


typedef struct _RTL_RWLOCK* LPRTL_RWLOCK; /* ../include/winternl.h:1291 */

struct _TIME_FIELDS /* ../include/winternl.h:1604 */
{
    CSHORT Year;
    CSHORT Month;
    CSHORT Day;
    CSHORT Hour;
    CSHORT Minute;
    CSHORT Second;
    CSHORT Milliseconds;
    CSHORT Weekday;
};


typedef struct _TIME_FIELDS* PTIME_FIELDS; /* ../include/winternl.h:1613 */

struct _LDR_RESOURCE_INFO /* ../include/winternl.h:1623 */
{
    ULONG_PTR Type;
    ULONG_PTR Name;
    ULONG Language;
};


typedef struct _LDR_RESOURCE_INFO LDR_RESOURCE_INFO; /* ../include/winternl.h:1628 */

struct _DEBUG_BUFFER /* ../include/winternl.h:1633 */
{
    HANDLE SectionHandle;
    PVOID SectionBase;
    PVOID RemoteSectionBase;
    ULONG SectionBaseDelta;
    HANDLE EventPairHandle;
    ULONG Unknown[2];
    HANDLE RemoteThreadHandle;
    ULONG InfoClassMask;
    ULONG SizeOfInfo;
    ULONG AllocatedSize;
    ULONG SectionSize;
    PVOID ModuleInformation;
    PVOID BackTraceInformation;
    PVOID HeapInformation;
    PVOID LockInformation;
    PVOID Reserved[8];
};


typedef struct _DEBUG_BUFFER* PDEBUG_BUFFER; /* ../include/winternl.h:1650 */

typedef unsigned short RTL_ATOM; /* ../include/winternl.h:1708 */

typedef struct atom_table* RTL_ATOM_TABLE; /* ../include/winternl.h:1714 */

enum _ATOM_INFORMATION_CLASS /* ../include/winternl.h:1716 */
{
    _ATOM_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _ATOM_INFORMATION_CLASS ATOM_INFORMATION_CLASS; /* ../include/winternl.h:1719 */

struct _RTL_HANDLE /* ../include/winternl.h:1729 */
{
    struct _RTL_HANDLE* Next;
};


typedef struct _RTL_HANDLE RTL_HANDLE; /* ../include/winternl.h:1732 */

struct _RTL_HANDLE_TABLE /* ../include/winternl.h:1735 */
{
    ULONG MaxHandleCount;
    ULONG HandleSize;
    ULONG Unused[2];
    PVOID NextFree;
    PVOID FirstHandle;
    PVOID ReservedMemory;
    PVOID MaxHandle;
};


typedef struct _RTL_HANDLE_TABLE RTL_HANDLE_TABLE; /* ../include/winternl.h:1744 */

typedef void (*PNTAPCFUNC) (ULONG_PTR, ULONG_PTR, ULONG_PTR); /* ../include/winternl.h:1842 */

typedef void (*PRTL_THREAD_START_ROUTINE) (LPVOID); /* ../include/winternl.h:1843 */

typedef DWORD (*PRTL_WORK_ITEM_ROUTINE) (LPVOID); /* ../include/winternl.h:1844 */

typedef void (*RTL_WAITORTIMERCALLBACKFUNC) (PVOID, BOOLEAN); /* ../include/winternl.h:1845 */

typedef NTSTATUS (*PRTL_QUERY_REGISTRY_ROUTINE) (PCWSTR  ValueName, ULONG  ValueType, PVOID  ValueData, ULONG  ValueLength, PVOID  Context, PVOID  EntryContext); /* ../include/winternl.h:1941 */

struct _RTL_QUERY_REGISTRY_TABLE /* ../include/winternl.h:1948 */
{
    PRTL_QUERY_REGISTRY_ROUTINE QueryRoutine;
    ULONG Flags;
    PWSTR Name;
    PVOID EntryContext;
    ULONG DefaultType;
    PVOID DefaultData;
    ULONG DefaultLength;
};


typedef struct _RTL_QUERY_REGISTRY_TABLE* PRTL_QUERY_REGISTRY_TABLE; /* ../include/winternl.h:1957 */

struct _KEY_MULTIPLE_VALUE_INFORMATION /* ../include/winternl.h:1959 */
{
    PUNICODE_STRING ValueName;
    ULONG DataLength;
    ULONG DataOffset;
    ULONG Type;
};


typedef struct _KEY_MULTIPLE_VALUE_INFORMATION* PKEY_MULTIPLE_VALUE_INFORMATION; /* ../include/winternl.h:1965 */

typedef void (*PRTL_OVERLAPPED_COMPLETION_ROUTINE) (DWORD, DWORD, LPVOID); /* ../include/winternl.h:1967 */

typedef void (*PTIMER_APC_ROUTINE) (PVOID, ULONG, LONG); /* ../include/winternl.h:1969 */

enum _EVENT_INFORMATION_CLASS /* ../include/winternl.h:1971 */
{
    _EVENT_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _EVENT_INFORMATION_CLASS EVENT_INFORMATION_CLASS; /* ../include/winternl.h:1973 */

enum _SEMAPHORE_INFORMATION_CLASS /* ../include/winternl.h:1980 */
{
    _SEMAPHORE_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SEMAPHORE_INFORMATION_CLASS SEMAPHORE_INFORMATION_CLASS; /* ../include/winternl.h:1982 */

enum _SECTION_INFORMATION_CLASS /* ../include/winternl.h:1989 */
{
    _SECTION_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _SECTION_INFORMATION_CLASS SECTION_INFORMATION_CLASS; /* ../include/winternl.h:1993 */

struct _SECTION_IMAGE_INFORMATION /* ../include/winternl.h:2001 */
{
    PVOID TransferAddress;
    ULONG ZeroBits;
    SIZE_T MaximumStackSize;
    SIZE_T CommittedStackSize;
    ULONG SubSystemType;
    WORD SubsystemVersionLow;
    WORD SubsystemVersionHigh;
    ULONG GpValue;
    USHORT ImageCharacteristics;
    USHORT DllCharacteristics;
    USHORT Machine;
    BOOLEAN ImageContainsCode;
    ULONG LoaderFlags;
    ULONG ImageFileSize;
    ULONG CheckSum;
};


typedef struct _SECTION_IMAGE_INFORMATION SECTION_IMAGE_INFORMATION; /* ../include/winternl.h:2030 */

struct _LPC_SECTION_WRITE /* ../include/winternl.h:2032 */
{
    ULONG Length;
    HANDLE SectionHandle;
    ULONG SectionOffset;
    ULONG ViewSize;
    PVOID ViewBase;
    PVOID TargetViewBase;
};


typedef struct _LPC_SECTION_WRITE* PLPC_SECTION_WRITE; /* ../include/winternl.h:2039 */

struct _LPC_SECTION_READ /* ../include/winternl.h:2041 */
{
    ULONG Length;
    ULONG ViewSize;
    PVOID ViewBase;
};


typedef struct _LPC_SECTION_READ* PLPC_SECTION_READ; /* ../include/winternl.h:2045 */

struct _LPC_MESSAGE /* ../include/winternl.h:2047 */
{
    USHORT DataSize;
    USHORT MessageSize;
    USHORT MessageType;
    USHORT VirtualRangesOffset;
    CLIENT_ID ClientId;
    ULONG_PTR MessageId;
    ULONG_PTR SectionSize;
    UCHAR Data[1];
};


typedef struct _LPC_MESSAGE* PLPC_MESSAGE; /* ../include/winternl.h:2056 */

struct _RTL_USER_PROCESS_INFORMATION /* ../include/winternl.h:2058 */
{
    ULONG Length;
    HANDLE Process;
    HANDLE Thread;
    CLIENT_ID ClientId;
    SECTION_IMAGE_INFORMATION ImageInformation;
};


typedef struct _RTL_USER_PROCESS_INFORMATION RTL_USER_PROCESS_INFORMATION; /* ../include/winternl.h:2065 */

enum _SHUTDOWN_ACTION /* ../include/winternl.h:2067 */
{
    _SHUTDOWN_ACTION_DUMMY = 0
};


typedef enum _SHUTDOWN_ACTION SHUTDOWN_ACTION; /* ../include/winternl.h:2071 */

struct _COUNTED_REASON_CONTEXT /* ../include/winternl.h:2073 */
{
    ULONG Version;
    ULONG Flags;
};


typedef struct _COUNTED_REASON_CONTEXT COUNTED_REASON_CONTEXT; /* ../include/winternl.h:2088 */

enum _KPROFILE_SOURCE /* ../include/winternl.h:2090 */
{
    _KPROFILE_SOURCE_DUMMY = 0
};


typedef enum _KPROFILE_SOURCE KPROFILE_SOURCE; /* ../include/winternl.h:2116 */

struct _DIRECTORY_BASIC_INFORMATION /* ../include/winternl.h:2118 */
{
    UNICODE_STRING ObjectName;
    UNICODE_STRING ObjectTypeName;
};


typedef struct _DIRECTORY_BASIC_INFORMATION* PDIRECTORY_BASIC_INFORMATION; /* ../include/winternl.h:2121 */

struct _INITIAL_TEB /* ../include/winternl.h:2123 */
{
    void* OldStackBase;
    void* OldStackLimit;
    void* StackBase;
    void* StackLimit;
    void* DeallocationStack;
};


typedef struct _INITIAL_TEB INITIAL_TEB; /* ../include/winternl.h:2129 */

enum _IO_COMPLETION_INFORMATION_CLASS /* ../include/winternl.h:2135 */
{
    _IO_COMPLETION_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _IO_COMPLETION_INFORMATION_CLASS IO_COMPLETION_INFORMATION_CLASS; /* ../include/winternl.h:2137 */

struct _FILE_IO_COMPLETION_INFORMATION /* ../include/winternl.h:2148 */
{
    ULONG_PTR CompletionKey;
    ULONG_PTR CompletionValue;
    IO_STATUS_BLOCK IoStatusBlock;
};


typedef struct _FILE_IO_COMPLETION_INFORMATION FILE_IO_COMPLETION_INFORMATION; /* ../include/winternl.h:2152 */

enum _HARDERROR_RESPONSE_OPTION /* ../include/winternl.h:2154 */
{
    _HARDERROR_RESPONSE_OPTION_DUMMY = 0
};


typedef enum _HARDERROR_RESPONSE_OPTION HARDERROR_RESPONSE_OPTION; /* ../include/winternl.h:2162 */

enum _HARDERROR_RESPONSE /* ../include/winternl.h:2164 */
{
    _HARDERROR_RESPONSE_DUMMY = 0
};


typedef enum _HARDERROR_RESPONSE* PHARDERROR_RESPONSE; /* ../include/winternl.h:2174 */

enum _SYSDBG_COMMAND /* ../include/winternl.h:2176 */
{
    _SYSDBG_COMMAND_DUMMY = 0
};


typedef enum _SYSDBG_COMMAND SYSDBG_COMMAND; /* ../include/winternl.h:2197 */

struct _LDR_MODULE /* ../include/winternl.h:2205 */
{
    LIST_ENTRY InLoadOrderModuleList;
    LIST_ENTRY InMemoryOrderModuleList;
    LIST_ENTRY InInitializationOrderModuleList;
    void* BaseAddress;
    void* EntryPoint;
    ULONG SizeOfImage;
    UNICODE_STRING FullDllName;
    UNICODE_STRING BaseDllName;
    ULONG Flags;
    SHORT LoadCount;
    SHORT TlsIndex;
    HANDLE SectionHandle;
    ULONG CheckSum;
    ULONG TimeDateStamp;
    HANDLE ActivationContext;
};


typedef struct _LDR_MODULE LDR_MODULE; /* ../include/winternl.h:2222 */

typedef struct _LDR_MODULE* PLDR_MODULE; /* ../include/winternl.h:2222 */

struct _LDR_DLL_LOADED_NOTIFICATION_DATA /* ../include/winternl.h:2224 */
{
    ULONG Flags;
    UNICODE_STRING* FullDllName;
    UNICODE_STRING* BaseDllName;
    void* DllBase;
    ULONG SizeOfImage;
};


typedef struct _LDR_DLL_LOADED_NOTIFICATION_DATA LDR_DLL_LOADED_NOTIFICATION_DATA; /* ../include/winternl.h:2231 */

struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA /* ../include/winternl.h:2233 */
{
    ULONG Flags;
    UNICODE_STRING* FullDllName;
    UNICODE_STRING* BaseDllName;
    void* DllBase;
    ULONG SizeOfImage;
};


typedef struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA LDR_DLL_UNLOADED_NOTIFICATION_DATA; /* ../include/winternl.h:2240 */

union _LDR_DLL_NOTIFICATION_DATA /* ../include/winternl.h:2242 */
{
    LDR_DLL_LOADED_NOTIFICATION_DATA Loaded;
    LDR_DLL_UNLOADED_NOTIFICATION_DATA Unloaded;
};


typedef union _LDR_DLL_NOTIFICATION_DATA LDR_DLL_NOTIFICATION_DATA; /* ../include/winternl.h:2246 */

typedef void (*PLDR_DLL_NOTIFICATION_FUNCTION) (ULONG, LDR_DLL_NOTIFICATION_DATA*, void*); /* ../include/winternl.h:2248 */

struct _SYSTEM_MODULE /* ../include/winternl.h:2272 */
{
    PVOID Reserved1;
    PVOID Reserved2;
    PVOID ImageBaseAddress;
    ULONG ImageSize;
    ULONG Flags;
    WORD Id;
    WORD Rank;
    WORD Unknown;
    WORD NameOffset;
    BYTE Name[256];
};


typedef struct _SYSTEM_MODULE SYSTEM_MODULE; /* ../include/winternl.h:2284 */

struct _SYSTEM_MODULE_INFORMATION /* ../include/winternl.h:2286 */
{
    ULONG ModulesCount;
    SYSTEM_MODULE Modules[1];
};


typedef struct _SYSTEM_MODULE_INFORMATION* PSYSTEM_MODULE_INFORMATION; /* ../include/winternl.h:2290 */

typedef LONG (*PRTL_EXCEPTION_FILTER) (PEXCEPTION_POINTERS); /* ../include/winternl.h:2299 */

struct cp_info /* ../include/wine/unicode.h:47 */
{
    unsigned int codepage;
    unsigned int char_size;
    WCHAR def_char;
    WCHAR def_unicode_char;
    char* name;
};


struct sbcs_table /* ../include/wine/unicode.h:56 */
{
    struct cp_info info;
    WCHAR* cp2uni;
    WCHAR* cp2uni_glyphs;
    unsigned char* uni2cp_low;
    unsigned short* uni2cp_high;
};


struct dbcs_table /* ../include/wine/unicode.h:65 */
{
    struct cp_info info;
    WCHAR* cp2uni;
    unsigned char* cp2uni_leadbytes;
    unsigned short* uni2cp_low;
    unsigned short* uni2cp_high;
    unsigned char lead_bytes[12];
};


union cptable /* ../include/wine/unicode.h:75 */
{
    struct cp_info info;
    struct sbcs_table sbcs;
    struct dbcs_table dbcs;
};


struct SHA_CTX /* ../dlls/ntdll/crypt.c:29 */
{
    ULONG Unknown[6];
    ULONG State[5];
    ULONG Count[2];
    UCHAR Buffer[64];
};


typedef struct SHA_CTX* PSHA_CTX; /* ../dlls/ntdll/crypt.c:34 */

struct MD4_CTX /* ../dlls/ntdll/crypt.c:222 */
{
    unsigned int buf[4];
    unsigned int i[2];
    unsigned char in[64];
    unsigned char digest[16];
};


typedef struct MD4_CTX MD4_CTX; /* ../dlls/ntdll/crypt.c:228 */

struct MD5_CTX /* ../dlls/ntdll/crypt.c:464 */
{
    unsigned int i[2];
    unsigned int buf[4];
    unsigned char in[64];
    unsigned char digest[16];
};


typedef struct MD5_CTX MD5_CTX; /* ../dlls/ntdll/crypt.c:470 */

struct msghdr /* /usr/include/bits/socket.h:257 */
{
    void* msg_name;
    socklen_t msg_namelen;
    struct iovec* msg_iov;
    size_t msg_iovlen;
    void* msg_control;
    size_t msg_controllen;
    int msg_flags;
};


struct _RTL_BALANCED_LINKS /* ../include/ddk/ntddk.h:143 */
{
    struct _RTL_BALANCED_LINKS* Parent;
    struct _RTL_BALANCED_LINKS* LeftChild;
    struct _RTL_BALANCED_LINKS* RightChild;
    CHAR Balance;
    UCHAR Reserved[3];
};


typedef struct _RTL_BALANCED_LINKS RTL_BALANCED_LINKS; /* ../include/ddk/ntddk.h:149 */

typedef RTL_BALANCED_LINKS* PRTL_BALANCED_LINKS; /* ../include/ddk/ntddk.h:150 */

enum _RTL_GENERIC_COMPARE_RESULTS /* ../include/ddk/ntddk.h:154 */
{
    _RTL_GENERIC_COMPARE_RESULTS_DUMMY = 0
};


typedef enum _RTL_GENERIC_COMPARE_RESULTS RTL_GENERIC_COMPARE_RESULTS; /* ../include/ddk/ntddk.h:158 */

typedef RTL_GENERIC_COMPARE_RESULTS (*PRTL_AVL_COMPARE_ROUTINE) (struct _RTL_AVL_TABLE*, void*, void*); /* ../include/ddk/ntddk.h:160 */

typedef void (*PRTL_AVL_ALLOCATE_ROUTINE) (struct _RTL_AVL_TABLE*, LONG); /* ../include/ddk/ntddk.h:162 */

typedef void (*PRTL_AVL_FREE_ROUTINE) (struct _RTL_AVL_TABLE*, void*  buffer); /* ../include/ddk/ntddk.h:164 */

struct _RTL_AVL_TABLE /* ../include/ddk/ntddk.h:166 */
{
    RTL_BALANCED_LINKS BalancedRoot;
    void* OrderedPointer;
    ULONG WhichOrderedElement;
    ULONG NumberGenericTableElements;
    ULONG DepthOfTree;
    PRTL_BALANCED_LINKS RestartKey;
    ULONG DeleteCount;
    PRTL_AVL_COMPARE_ROUTINE CompareRoutine;
    PRTL_AVL_ALLOCATE_ROUTINE AllocateRoutine;
    PRTL_AVL_FREE_ROUTINE FreeRoutine;
    void* TableContext;
};


typedef struct _RTL_AVL_TABLE* PRTL_AVL_TABLE; /* ../include/ddk/ntddk.h:178 */

struct _DELAYLOAD_PROC_DESCRIPTOR /* ../include/delayloadhandler.h:28 */
{
    ULONG ImportDescribedByName;
};


typedef struct _DELAYLOAD_PROC_DESCRIPTOR DELAYLOAD_PROC_DESCRIPTOR; /* ../include/delayloadhandler.h:35 */

struct _DELAYLOAD_INFO /* ../include/delayloadhandler.h:37 */
{
    ULONG Size;
    PCIMAGE_DELAYLOAD_DESCRIPTOR DelayloadDescriptor;
    PIMAGE_THUNK_DATA ThunkAddress;
    LPCSTR TargetDllName;
    DELAYLOAD_PROC_DESCRIPTOR TargetApiDescriptor;
    PVOID TargetModuleBase;
    PVOID Unused;
    ULONG LastError;
};


typedef struct _DELAYLOAD_INFO* PDELAYLOAD_INFO; /* ../include/delayloadhandler.h:47 */

typedef PVOID (*PDELAYLOAD_FAILURE_DLL_CALLBACK) (ULONG, PDELAYLOAD_INFO); /* ../include/delayloadhandler.h:49 */

typedef PVOID (*PDELAYLOAD_FAILURE_SYSTEM_ROUTINE) (LPCSTR, LPCSTR); /* ../include/delayloadhandler.h:50 */

typedef void (*LDRENUMPROC) (LDR_MODULE*, void*, BOOLEAN*); /* ../dlls/ntdll/loader.c:66 */

struct _RTL_UNLOAD_EVENT_TRACE /* ../dlls/ntdll/loader.c:166 */
{
    void* BaseAddress;
    SIZE_T SizeOfImage;
    ULONG Sequence;
    ULONG TimeDateStamp;
    ULONG CheckSum;
    WCHAR ImageName[32];
};


typedef struct _RTL_UNLOAD_EVENT_TRACE RTL_UNLOAD_EVENT_TRACE; /* ../dlls/ntdll/loader.c:174 */

enum WMIDPREQUESTCODE /* ../include/wmistr.h:40 */
{
    WMIDPREQUESTCODE_DUMMY = 0
};


typedef enum WMIDPREQUESTCODE WMIDPREQUESTCODE; /* ../include/wmistr.h:52 */

typedef ULONG64 TRACEHANDLE; /* ../include/evntrace.h:70 */

typedef ULONG (*WMIDPREQUEST) (WMIDPREQUESTCODE, PVOID, ULONG*, PVOID); /* ../include/evntrace.h:81 */

struct _TRACE_GUID_REGISTRATION /* ../include/evntrace.h:83 */
{
    LPCGUID Guid;
    HANDLE RegHandle;
};


typedef struct _TRACE_GUID_REGISTRATION TRACE_GUID_REGISTRATION; /* ../include/evntrace.h:87 */

struct _EVENT_TRACE_HEADER /* ../include/evntrace.h:98 */
{
    USHORT Size;
    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
};


typedef struct _EVENT_TRACE_HEADER* PEVENT_TRACE_HEADER; /* ../include/evntrace.h:141 */

typedef ULONGLONG REGHANDLE; /* ../include/evntprov.h:29 */

typedef ULONGLONG* PREGHANDLE; /* ../include/evntprov.h:29 */

struct _EVENT_DATA_DESCRIPTOR /* ../include/evntprov.h:31 */
{
    ULONGLONG Ptr;
    ULONG Size;
    ULONG Reserved;
};


typedef struct _EVENT_DATA_DESCRIPTOR EVENT_DATA_DESCRIPTOR; /* ../include/evntprov.h:36 */

typedef struct _EVENT_DATA_DESCRIPTOR* PEVENT_DATA_DESCRIPTOR; /* ../include/evntprov.h:36 */

struct _EVENT_DESCRIPTOR /* ../include/evntprov.h:38 */
{
    USHORT Id;
    UCHAR Version;
    UCHAR Channel;
    UCHAR Level;
    UCHAR Opcode;
    USHORT Task;
    ULONGLONG Keyword;
};


typedef struct _EVENT_DESCRIPTOR EVENT_DESCRIPTOR; /* ../include/evntprov.h:47 */

typedef EVENT_DESCRIPTOR* PCEVENT_DESCRIPTOR; /* ../include/evntprov.h:50 */

struct _EVENT_FILTER_DESCRIPTOR /* ../include/evntprov.h:52 */
{
    ULONGLONG Ptr;
    ULONG Size;
    ULONG Type;
};


typedef struct _EVENT_FILTER_DESCRIPTOR* PEVENT_FILTER_DESCRIPTOR; /* ../include/evntprov.h:58 */

typedef void (*PENABLECALLBACK) (LPCGUID, ULONG, UCHAR, ULONGLONG, ULONGLONG, PEVENT_FILTER_DESCRIPTOR, PVOID); /* ../include/evntprov.h:60 */

enum _EVENT_INFO_CLASS /* ../include/evntprov.h:62 */
{
    _EVENT_INFO_CLASS_DUMMY = 0
};


typedef enum _EVENT_INFO_CLASS EVENT_INFO_CLASS; /* ../include/evntprov.h:68 */

struct WS_in_addr /* ../include/inaddr.h:29 */
{
};


typedef struct WS_in_addr IN_ADDR; /* ../include/inaddr.h:40 */

struct WS_in6_addr /* ../include/in6addr.h:28 */
{
};


typedef struct WS_in6_addr IN6_ADDR; /* ../include/in6addr.h:33 */

typedef int (*wine_signal_handler) (unsigned int  sig); /* ../dlls/ntdll/signal_x86_64.c:298 */

static WINAPI void (*pA_SHAFinal)(PSHA_CTX  Context, PULONG  Result);
static WINAPI void (*pA_SHAInit)(PSHA_CTX  Context);
static WINAPI void (*pA_SHAUpdate)(PSHA_CTX  Context, unsigned char*  Buffer, UINT  BufferSize);
static WINAPI BOOL (*pApiSetQueryApiSetPresence)(UNICODE_STRING*  namespace, BOOLEAN*  present);
static WINAPI NTSTATUS (*pDbgPrint)(LPCSTR  fmt);
static WINAPI NTSTATUS (*pDbgPrintEx)(ULONG  iComponentId, ULONG  Level, LPCSTR  fmt);
static WINAPI NTSTATUS (*pDbgUiIssueRemoteBreakin)(HANDLE  process);
static WINAPI void (*pDbgUiRemoteBreakin)(void*  arg);
static WINAPI ULONG (*pEtwEventActivityIdControl)(ULONG  code, GUID*  guid);
static WINAPI BOOLEAN (*pEtwEventEnabled)(REGHANDLE  handle, EVENT_DESCRIPTOR*  descriptor);
static WINAPI BOOLEAN (*pEtwEventProviderEnabled)(REGHANDLE  handle, UCHAR  level, ULONGLONG  keyword);
static WINAPI ULONG (*pEtwEventRegister)(LPCGUID  provider, PENABLECALLBACK  callback, PVOID  context, PREGHANDLE  handle);
static WINAPI ULONG (*pEtwEventSetInformation)(REGHANDLE  handle, EVENT_INFO_CLASS  class, void*  info, ULONG  length);
static WINAPI ULONG (*pEtwEventUnregister)(REGHANDLE  handle);
static WINAPI ULONG (*pEtwEventWrite)(REGHANDLE  handle, EVENT_DESCRIPTOR*  descriptor, ULONG  count, EVENT_DATA_DESCRIPTOR*  data);
static WINAPI ULONG (*pEtwEventWriteString)(REGHANDLE  handle, UCHAR  level, ULONGLONG  keyword, PCWSTR  string);
static WINAPI ULONG (*pEtwEventWriteTransfer)(REGHANDLE  handle, PCEVENT_DESCRIPTOR  descriptor, LPCGUID  activity, LPCGUID  related, ULONG  count, PEVENT_DATA_DESCRIPTOR  data);
static WINAPI ULONG (*pEtwGetTraceEnableFlags)(TRACEHANDLE  handle);
static WINAPI UCHAR (*pEtwGetTraceEnableLevel)(TRACEHANDLE  handle);
static WINAPI TRACEHANDLE (*pEtwGetTraceLoggerHandle)(PVOID  buf);
static WINAPI ULONG (*pEtwLogTraceEvent)(TRACEHANDLE  SessionHandle, PEVENT_TRACE_HEADER  EventTrace);
static WINAPI ULONG (*pEtwRegisterTraceGuidsA)(WMIDPREQUEST  RequestAddress, void*  RequestContext, GUID*  ControlGuid, ULONG  GuidCount, TRACE_GUID_REGISTRATION*  TraceGuidReg, char*  MofImagePath, char*  MofResourceName, TRACEHANDLE*  RegistrationHandle);
static WINAPI ULONG (*pEtwRegisterTraceGuidsW)(WMIDPREQUEST  RequestAddress, void*  RequestContext, GUID*  ControlGuid, ULONG  GuidCount, TRACE_GUID_REGISTRATION*  TraceGuidReg, WCHAR*  MofImagePath, WCHAR*  MofResourceName, TRACEHANDLE*  RegistrationHandle);
static WINAPI ULONG (*pEtwTraceMessage)(TRACEHANDLE  handle, ULONG  flags, LPGUID  guid, USHORT  number);
static WINAPI ULONG (*pEtwTraceMessageVa)(TRACEHANDLE  handle, ULONG  flags, LPGUID  guid, USHORT  number, __builtin_ms_va_list  args);
static WINAPI ULONG (*pEtwUnregisterTraceGuids)(TRACEHANDLE  RegistrationHandle);
static WINAPI NTSTATUS (*pLdrAccessResource)(HMODULE  hmod, IMAGE_RESOURCE_DATA_ENTRY*  entry, void**  ptr, ULONG*  size);
static WINAPI NTSTATUS (*pLdrAddRefDll)(ULONG  flags, HMODULE  module);
static WINAPI NTSTATUS (*pLdrDisableThreadCalloutsForDll)(HMODULE  hModule);
static WINAPI NTSTATUS (*pLdrEnumerateLoadedModules)(void*  unknown, LDRENUMPROC  callback, void*  context);
static WINAPI NTSTATUS (*pLdrFindEntryForAddress)(void*  addr, PLDR_MODULE*  pmod);
static WINAPI NTSTATUS (*pLdrFindResourceDirectory_U)(HMODULE  hmod, LDR_RESOURCE_INFO*  info, ULONG  level, IMAGE_RESOURCE_DIRECTORY**  dir);
static WINAPI NTSTATUS (*pLdrFindResource_U)(HMODULE  hmod, LDR_RESOURCE_INFO*  info, ULONG  level, IMAGE_RESOURCE_DATA_ENTRY**  entry);
static WINAPI NTSTATUS (*pLdrGetDllHandle)(LPCWSTR  load_path, ULONG  flags, UNICODE_STRING*  name, HMODULE*  base);
static WINAPI NTSTATUS (*pLdrGetProcedureAddress)(HMODULE  module, ANSI_STRING*  name, ULONG  ord, PVOID*  address);
static WINAPI void (*pLdrInitializeThunk)(CONTEXT*  context, void**  entry, ULONG_PTR  unknown3, ULONG_PTR  unknown4);
static WINAPI NTSTATUS (*pLdrLoadDll)(LPCWSTR  path_name, DWORD  flags, UNICODE_STRING*  libname, HMODULE*  hModule);
static WINAPI NTSTATUS (*pLdrLockLoaderLock)(ULONG  flags, ULONG*  result, ULONG_PTR*  magic);
static WINAPI IMAGE_BASE_RELOCATION* (*pLdrProcessRelocationBlock)(void*  page, UINT  count, USHORT*  relocs, INT_PTR  delta);
static WINAPI NTSTATUS (*pLdrQueryImageFileExecutionOptions)(UNICODE_STRING*  key, LPCWSTR  value, ULONG  type, void*  data, ULONG  in_size, ULONG*  out_size);
static WINAPI NTSTATUS (*pLdrQueryProcessModuleInformation)(PSYSTEM_MODULE_INFORMATION  smi, ULONG  buf_size, ULONG*  req_size);
static WINAPI NTSTATUS (*pLdrRegisterDllNotification)(ULONG  flags, PLDR_DLL_NOTIFICATION_FUNCTION  callback, void*  context, void**  cookie);
static WINAPI void* (*pLdrResolveDelayLoadedAPI)(void*  base, IMAGE_DELAYLOAD_DESCRIPTOR*  desc, PDELAYLOAD_FAILURE_DLL_CALLBACK  dllhook, PDELAYLOAD_FAILURE_SYSTEM_ROUTINE  syshook, IMAGE_THUNK_DATA*  addr, ULONG  flags);
static WINAPI void (*pLdrShutdownProcess)(void);
static WINAPI void (*pLdrShutdownThread)(void);
static WINAPI NTSTATUS (*pLdrUnloadDll)(HMODULE  hModule);
static WINAPI NTSTATUS (*pLdrUnlockLoaderLock)(ULONG  flags, ULONG_PTR  magic);
static WINAPI NTSTATUS (*pLdrUnregisterDllNotification)(void*  cookie);
static WINAPI void (*pMD4Final)(MD4_CTX*  ctx);
static WINAPI void (*pMD4Init)(MD4_CTX*  ctx);
static WINAPI void (*pMD4Update)(MD4_CTX*  ctx, unsigned char*  buf, unsigned int  len);
static WINAPI void (*pMD5Final)(MD5_CTX*  ctx);
static WINAPI void (*pMD5Init)(MD5_CTX*  ctx);
static WINAPI void (*pMD5Update)(MD5_CTX*  ctx, unsigned char*  buf, unsigned int  len);
static WINAPI NTSTATUS (*pNtAcceptConnectPort)(PHANDLE  PortHandle, ULONG  PortIdentifier, PLPC_MESSAGE  pLpcMessage, BOOLEAN  Accept, PLPC_SECTION_WRITE  WriteSection, PLPC_SECTION_READ  ReadSection);
static WINAPI NTSTATUS (*pNtAccessCheck)(PSECURITY_DESCRIPTOR  SecurityDescriptor, HANDLE  ClientToken, ACCESS_MASK  DesiredAccess, PGENERIC_MAPPING  GenericMapping, PPRIVILEGE_SET  PrivilegeSet, PULONG  ReturnLength, PULONG  GrantedAccess, NTSTATUS*  AccessStatus);
static WINAPI NTSTATUS (*pNtAccessCheckAndAuditAlarm)(PUNICODE_STRING  SubsystemName, HANDLE  HandleId, PUNICODE_STRING  ObjectTypeName, PUNICODE_STRING  ObjectName, PSECURITY_DESCRIPTOR  SecurityDescriptor, ACCESS_MASK  DesiredAccess, PGENERIC_MAPPING  GenericMapping, BOOLEAN  ObjectCreation, PACCESS_MASK  GrantedAccess, PBOOLEAN  AccessStatus, PBOOLEAN  GenerateOnClose);
static WINAPI NTSTATUS (*pNtAddAtom)(WCHAR*  name, ULONG  length, RTL_ATOM*  atom);
static WINAPI NTSTATUS (*pNtAdjustGroupsToken)(HANDLE  TokenHandle, BOOLEAN  ResetToDefault, PTOKEN_GROUPS  NewState, ULONG  BufferLength, PTOKEN_GROUPS  PreviousState, PULONG  ReturnLength);
static WINAPI NTSTATUS (*pNtAdjustPrivilegesToken)(HANDLE  TokenHandle, BOOLEAN  DisableAllPrivileges, PTOKEN_PRIVILEGES  NewState, DWORD  BufferLength, PTOKEN_PRIVILEGES  PreviousState, PDWORD  ReturnLength);
static WINAPI NTSTATUS (*pNtAlertResumeThread)(HANDLE  handle, PULONG  count);
static WINAPI NTSTATUS (*pNtAlertThread)(HANDLE  handle);
static WINAPI NTSTATUS (*pNtAllocateLocallyUniqueId)(PLUID  Luid);
static WINAPI NTSTATUS (*pNtAllocateUuids)(ULARGE_INTEGER*  time, ULONG*  delta, ULONG*  sequence, UCHAR*  seed);
static WINAPI NTSTATUS (*pNtAllocateVirtualMemory)(HANDLE  process, PVOID*  ret, ULONG_PTR  zero_bits, SIZE_T*  size_ptr, ULONG  type, ULONG  protect);
static WINAPI NTSTATUS (*pNtAreMappedFilesTheSame)(PVOID  addr1, PVOID  addr2);
static WINAPI NTSTATUS (*pNtAssignProcessToJobObject)(HANDLE  job, HANDLE  process);
static WINAPI NTSTATUS (*pNtCancelIoFile)(HANDLE  hFile, PIO_STATUS_BLOCK  io_status);
static WINAPI NTSTATUS (*pNtCancelIoFileEx)(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PIO_STATUS_BLOCK  io_status);
static WINAPI NTSTATUS (*pNtCancelTimer)(HANDLE  handle, BOOLEAN*  state);
static WINAPI NTSTATUS (*pNtClearEvent)(HANDLE  handle);
static WINAPI NTSTATUS (*pNtClearPowerRequest)(HANDLE  handle, POWER_REQUEST_TYPE  type);
static WINAPI NTSTATUS (*pNtClose)(HANDLE  Handle);
static WINAPI NTSTATUS (*pNtCompleteConnectPort)(HANDLE  PortHandle);
static WINAPI NTSTATUS (*pNtConnectPort)(PHANDLE  PortHandle, PUNICODE_STRING  PortName, PSECURITY_QUALITY_OF_SERVICE  SecurityQos, PLPC_SECTION_WRITE  WriteSection, PLPC_SECTION_READ  ReadSection, PULONG  MaximumMessageLength, PVOID  ConnectInfo, PULONG  pConnectInfoLength);
static WINAPI NTSTATUS (*pNtCreateDirectoryObject)(PHANDLE  DirectoryHandle, ACCESS_MASK  DesiredAccess, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtCreateEvent)(PHANDLE  EventHandle, ACCESS_MASK  DesiredAccess, OBJECT_ATTRIBUTES*  attr, EVENT_TYPE  type, BOOLEAN  InitialState);
static WINAPI NTSTATUS (*pNtCreateFile)(PHANDLE  handle, ACCESS_MASK  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  io, PLARGE_INTEGER  alloc_size, ULONG  attributes, ULONG  sharing, ULONG  disposition, ULONG  options, PVOID  ea_buffer, ULONG  ea_length);
static WINAPI NTSTATUS (*pNtCreateIoCompletion)(PHANDLE  CompletionPort, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  attr, ULONG  NumberOfConcurrentThreads);
static WINAPI NTSTATUS (*pNtCreateJobObject)(PHANDLE  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtCreateKey)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, PULONG  dispos);
static WINAPI NTSTATUS (*pNtCreateKeyTransacted)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, HANDLE  transacted, ULONG*  dispos);
static WINAPI NTSTATUS (*pNtCreateKeyedEvent)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  flags);
static WINAPI NTSTATUS (*pNtCreateLowBoxToken)(HANDLE*  token_handle, HANDLE  existing_token_handle, ACCESS_MASK  desired_access, OBJECT_ATTRIBUTES*  object_attributes, SID*  package_sid, ULONG  capability_count, SID_AND_ATTRIBUTES*  capabilities, ULONG  handle_count, HANDLE*  handle);
static WINAPI NTSTATUS (*pNtCreateMailslotFile)(PHANDLE  pHandle, ULONG  DesiredAccess, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CreateOptions, ULONG  MailslotQuota, ULONG  MaxMessageSize, PLARGE_INTEGER  TimeOut);
static WINAPI NTSTATUS (*pNtCreateMutant)(HANDLE*  MutantHandle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, BOOLEAN  InitialOwner);
static WINAPI NTSTATUS (*pNtCreateNamedPipeFile)(PHANDLE  handle, ULONG  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  iosb, ULONG  sharing, ULONG  dispo, ULONG  options, ULONG  pipe_type, ULONG  read_mode, ULONG  completion_mode, ULONG  max_inst, ULONG  inbound_quota, ULONG  outbound_quota, PLARGE_INTEGER  timeout);
static WINAPI NTSTATUS (*pNtCreatePagingFile)(PUNICODE_STRING  PageFileName, PLARGE_INTEGER  MinimumSize, PLARGE_INTEGER  MaximumSize, PLARGE_INTEGER  ActualSize);
static WINAPI NTSTATUS (*pNtCreatePort)(PHANDLE  PortHandle, POBJECT_ATTRIBUTES  ObjectAttributes, ULONG  MaxConnectInfoLength, ULONG  MaxDataLength, PULONG  reserved);
static WINAPI NTSTATUS (*pNtCreatePowerRequest)(HANDLE*  handle, COUNTED_REASON_CONTEXT*  context);
static WINAPI NTSTATUS (*pNtCreateSection)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, LARGE_INTEGER*  size, ULONG  protect, ULONG  sec_flags, HANDLE  file);
static WINAPI NTSTATUS (*pNtCreateSemaphore)(PHANDLE  SemaphoreHandle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, LONG  InitialCount, LONG  MaximumCount);
static WINAPI NTSTATUS (*pNtCreateSymbolicLinkObject)(PHANDLE  SymbolicLinkHandle, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  attr, PUNICODE_STRING  TargetName);
static WINAPI NTSTATUS (*pNtCreateThreadEx)(HANDLE*  handle_ptr, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, HANDLE  process, LPTHREAD_START_ROUTINE  start, void*  param, ULONG  flags, ULONG  zero_bits, ULONG  stack_commit, ULONG  stack_reserve, void*  attribute_list);
static WINAPI NTSTATUS (*pNtCreateTimer)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, TIMER_TYPE  timer_type);
static WINAPI NTSTATUS (*pNtDelayExecution)(BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtDeleteAtom)(RTL_ATOM  atom);
static WINAPI NTSTATUS (*pNtDeleteFile)(POBJECT_ATTRIBUTES  ObjectAttributes);
static WINAPI NTSTATUS (*pNtDeleteKey)(HANDLE  hkey);
static WINAPI NTSTATUS (*pNtDeleteValueKey)(HANDLE  hkey, UNICODE_STRING*  name);
static WINAPI NTSTATUS (*pNtDeviceIoControlFile)(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, PVOID  apc_context, PIO_STATUS_BLOCK  io, ULONG  code, PVOID  in_buffer, ULONG  in_size, PVOID  out_buffer, ULONG  out_size);
static WINAPI NTSTATUS (*pNtDisplayString)(PUNICODE_STRING  string);
static WINAPI NTSTATUS (*pNtDuplicateObject)(HANDLE  source_process, HANDLE  source, HANDLE  dest_process, PHANDLE  dest, ACCESS_MASK  access, ULONG  attributes, ULONG  options);
static WINAPI NTSTATUS (*pNtDuplicateToken)(HANDLE  ExistingToken, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  ObjectAttributes, SECURITY_IMPERSONATION_LEVEL  ImpersonationLevel, TOKEN_TYPE  TokenType, PHANDLE  NewToken);
static WINAPI NTSTATUS (*pNtEnumerateKey)(HANDLE  handle, ULONG  index, KEY_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len);
static WINAPI NTSTATUS (*pNtEnumerateValueKey)(HANDLE  handle, ULONG  index, KEY_VALUE_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len);
static WINAPI NTSTATUS (*pNtFindAtom)(WCHAR*  name, ULONG  length, RTL_ATOM*  atom);
static WINAPI NTSTATUS (*pNtFlushBuffersFile)(HANDLE  hFile, IO_STATUS_BLOCK*  io);
static WINAPI NTSTATUS (*pNtFlushInstructionCache)(HANDLE  handle, void*  addr, SIZE_T  size);
static WINAPI NTSTATUS (*pNtFlushKey)(HANDLE  key);
static WINAPI NTSTATUS (*pNtFlushVirtualMemory)(HANDLE  process, LPCVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  unknown);
static WINAPI NTSTATUS (*pNtFreeVirtualMemory)(HANDLE  process, PVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  type);
static WINAPI NTSTATUS (*pNtFsControlFile)(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, PVOID  apc_context, PIO_STATUS_BLOCK  io, ULONG  code, PVOID  in_buffer, ULONG  in_size, PVOID  out_buffer, ULONG  out_size);
static WINAPI NTSTATUS (*pNtGetContextThread)(HANDLE  handle, CONTEXT*  context);
static WINAPI ULONG (*pNtGetCurrentProcessorNumber)(void);
static WINAPI ULONG (*pNtGetTickCount)(void);
static WINAPI NTSTATUS (*pNtGetWriteWatch)(HANDLE  process, ULONG  flags, PVOID  base, SIZE_T  size, PVOID*  addresses, ULONG_PTR*  count, ULONG*  granularity);
static WINAPI NTSTATUS (*pNtImpersonateAnonymousToken)(HANDLE  thread);
static WINAPI NTSTATUS (*pNtInitiatePowerAction)(POWER_ACTION  SystemAction, SYSTEM_POWER_STATE  MinSystemState, ULONG  Flags, BOOLEAN  Asynchronous);
static WINAPI NTSTATUS (*pNtIsProcessInJob)(HANDLE  process, HANDLE  job);
static WINAPI NTSTATUS (*pNtListenPort)(HANDLE  PortHandle, PLPC_MESSAGE  pLpcMessage);
static WINAPI NTSTATUS (*pNtLoadDriver)(UNICODE_STRING*  DriverServiceName);
static WINAPI NTSTATUS (*pNtLoadKey2)(OBJECT_ATTRIBUTES*  attr, OBJECT_ATTRIBUTES*  file, ULONG  flags);
static WINAPI NTSTATUS (*pNtLoadKey)(OBJECT_ATTRIBUTES*  attr, OBJECT_ATTRIBUTES*  file);
static WINAPI NTSTATUS (*pNtLockFile)(HANDLE  hFile, HANDLE  lock_granted_event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, PLARGE_INTEGER  offset, PLARGE_INTEGER  count, ULONG*  key, BOOLEAN  dont_wait, BOOLEAN  exclusive);
static WINAPI NTSTATUS (*pNtLockVirtualMemory)(HANDLE  process, PVOID*  addr, SIZE_T*  size, ULONG  unknown);
static WINAPI NTSTATUS (*pNtMakeTemporaryObject)(HANDLE  Handle);
static WINAPI NTSTATUS (*pNtMapViewOfSection)(HANDLE  handle, HANDLE  process, PVOID*  addr_ptr, ULONG_PTR  zero_bits, SIZE_T  commit_size, LARGE_INTEGER*  offset_ptr, SIZE_T*  size_ptr, SECTION_INHERIT  inherit, ULONG  alloc_type, ULONG  protect);
static WINAPI NTSTATUS (*pNtNotifyChangeDirectoryFile)(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_context, PIO_STATUS_BLOCK  iosb, void*  buffer, ULONG  buffer_size, ULONG  filter, BOOLEAN  subtree);
static WINAPI NTSTATUS (*pNtNotifyChangeKey)(HANDLE  KeyHandle, HANDLE  Event, PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CompletionFilter, BOOLEAN  WatchSubtree, PVOID  ChangeBuffer, ULONG  Length, BOOLEAN  Asynchronous);
static WINAPI NTSTATUS (*pNtNotifyChangeMultipleKeys)(HANDLE  KeyHandle, ULONG  Count, OBJECT_ATTRIBUTES*  SubordinateObjects, HANDLE  Event, PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CompletionFilter, BOOLEAN  WatchSubtree, PVOID  ChangeBuffer, ULONG  Length, BOOLEAN  Asynchronous);
static WINAPI NTSTATUS (*pNtOpenDirectoryObject)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenEvent)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenFile)(PHANDLE  handle, ACCESS_MASK  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  io, ULONG  sharing, ULONG  options);
static WINAPI NTSTATUS (*pNtOpenIoCompletion)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenJobObject)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenKey)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenKeyEx)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  options);
static WINAPI NTSTATUS (*pNtOpenKeyTransacted)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, HANDLE  transaction);
static WINAPI NTSTATUS (*pNtOpenKeyTransactedEx)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  options, HANDLE  transaction);
static WINAPI NTSTATUS (*pNtOpenKeyedEvent)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenMutant)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenProcess)(PHANDLE  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, CLIENT_ID*  cid);
static WINAPI NTSTATUS (*pNtOpenProcessToken)(HANDLE  ProcessHandle, DWORD  DesiredAccess, HANDLE*  TokenHandle);
static WINAPI NTSTATUS (*pNtOpenProcessTokenEx)(HANDLE  process, DWORD  access, DWORD  attributes, HANDLE*  handle);
static WINAPI NTSTATUS (*pNtOpenSection)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenSemaphore)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenSymbolicLinkObject)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtOpenThread)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, CLIENT_ID*  id);
static WINAPI NTSTATUS (*pNtOpenThreadToken)(HANDLE  ThreadHandle, DWORD  DesiredAccess, BOOLEAN  OpenAsSelf, HANDLE*  TokenHandle);
static WINAPI NTSTATUS (*pNtOpenThreadTokenEx)(HANDLE  thread, DWORD  access, BOOLEAN  as_self, DWORD  attributes, HANDLE*  handle);
static WINAPI NTSTATUS (*pNtOpenTimer)(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pNtPowerInformation)(POWER_INFORMATION_LEVEL  InformationLevel, PVOID  lpInputBuffer, ULONG  nInputBufferSize, PVOID  lpOutputBuffer, ULONG  nOutputBufferSize);
static WINAPI NTSTATUS (*pNtPrivilegeCheck)(HANDLE  ClientToken, PPRIVILEGE_SET  RequiredPrivileges, PBOOLEAN  Result);
static WINAPI NTSTATUS (*pNtProtectVirtualMemory)(HANDLE  process, PVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  new_prot, ULONG*  old_prot);
static WINAPI NTSTATUS (*pNtPulseEvent)(HANDLE  handle, LONG*  prev_state);
static WINAPI NTSTATUS (*pNtQueryAttributesFile)(OBJECT_ATTRIBUTES*  attr, FILE_BASIC_INFORMATION*  info);
static WINAPI NTSTATUS (*pNtQueryDefaultLocale)(BOOLEAN  user, LCID*  lcid);
static WINAPI NTSTATUS (*pNtQueryDefaultUILanguage)(LANGID*  lang);
static WINAPI NTSTATUS (*pNtQueryDirectoryFile)(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc_routine, PVOID  apc_context, PIO_STATUS_BLOCK  io, PVOID  buffer, ULONG  length, FILE_INFORMATION_CLASS  info_class, BOOLEAN  single_entry, PUNICODE_STRING  mask, BOOLEAN  restart_scan);
static WINAPI NTSTATUS (*pNtQueryDirectoryObject)(HANDLE  handle, PDIRECTORY_BASIC_INFORMATION  buffer, ULONG  size, BOOLEAN  single_entry, BOOLEAN  restart, PULONG  context, PULONG  ret_size);
static WINAPI NTSTATUS (*pNtQueryEaFile)(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PVOID  buffer, ULONG  length, BOOLEAN  single_entry, PVOID  ea_list, ULONG  ea_list_len, PULONG  ea_index, BOOLEAN  restart);
static WINAPI NTSTATUS (*pNtQueryEvent)(HANDLE  handle, EVENT_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len);
static WINAPI NTSTATUS (*pNtQueryFullAttributesFile)(OBJECT_ATTRIBUTES*  attr, FILE_NETWORK_OPEN_INFORMATION*  info);
static WINAPI NTSTATUS (*pNtQueryInformationAtom)(RTL_ATOM  atom, ATOM_INFORMATION_CLASS  class, PVOID  ptr, ULONG  size, PULONG  psize);
static WINAPI NTSTATUS (*pNtQueryInformationFile)(HANDLE  hFile, PIO_STATUS_BLOCK  io, PVOID  ptr, LONG  len, FILE_INFORMATION_CLASS  class);
static WINAPI NTSTATUS (*pNtQueryInformationJobObject)(HANDLE  handle, JOBOBJECTINFOCLASS  class, PVOID  info, ULONG  len, PULONG  ret_len);
static WINAPI NTSTATUS (*pNtQueryInformationProcess)(HANDLE  ProcessHandle, PROCESSINFOCLASS  ProcessInformationClass, PVOID  ProcessInformation, ULONG  ProcessInformationLength, PULONG  ReturnLength);
static WINAPI NTSTATUS (*pNtQueryInformationThread)(HANDLE  handle, THREADINFOCLASS  class, void*  data, ULONG  length, ULONG*  ret_len);
static WINAPI NTSTATUS (*pNtQueryInformationToken)(HANDLE  token, TOKEN_INFORMATION_CLASS  tokeninfoclass, PVOID  tokeninfo, ULONG  tokeninfolength, PULONG  retlen);
static WINAPI NTSTATUS (*pNtQueryInstallUILanguage)(LANGID*  lang);
static WINAPI NTSTATUS (*pNtQueryIoCompletion)(HANDLE  CompletionPort, IO_COMPLETION_INFORMATION_CLASS  InformationClass, PVOID  CompletionInformation, ULONG  BufferLength, PULONG  RequiredLength);
static WINAPI NTSTATUS (*pNtQueryKey)(HANDLE  handle, KEY_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len);
static WINAPI NTSTATUS (*pNtQueryLicenseValue)(UNICODE_STRING*  name, ULONG*  result_type, PVOID  data, ULONG  length, ULONG*  result_len);
static WINAPI NTSTATUS (*pNtQueryMultipleValueKey)(HANDLE  KeyHandle, PKEY_MULTIPLE_VALUE_INFORMATION  ListOfValuesToQuery, ULONG  NumberOfItems, PVOID  MultipleValueInformation, ULONG  Length, PULONG  ReturnLength);
static WINAPI NTSTATUS (*pNtQueryMutant)(HANDLE  handle, MUTANT_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len);
static WINAPI NTSTATUS (*pNtQueryObject)(HANDLE  handle, OBJECT_INFORMATION_CLASS  info_class, PVOID  ptr, ULONG  len, PULONG  used_len);
static WINAPI NTSTATUS (*pNtQueryPerformanceCounter)(LARGE_INTEGER*  counter, LARGE_INTEGER*  frequency);
static WINAPI NTSTATUS (*pNtQuerySection)(HANDLE  handle, SECTION_INFORMATION_CLASS  class, void*  ptr, SIZE_T  size, SIZE_T*  ret_size);
static WINAPI NTSTATUS (*pNtQuerySecurityObject)(HANDLE  Object, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, ULONG  Length, PULONG  ResultLength);
static WINAPI NTSTATUS (*pNtQuerySemaphore)(HANDLE  handle, SEMAPHORE_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len);
static WINAPI NTSTATUS (*pNtQuerySymbolicLinkObject)(HANDLE  handle, PUNICODE_STRING  target, PULONG  length);
static WINAPI NTSTATUS (*pNtQuerySystemEnvironmentValue)(PUNICODE_STRING  VariableName, PWCHAR  Value, ULONG  ValueBufferLength, PULONG  RequiredLength);
static WINAPI NTSTATUS (*pNtQuerySystemEnvironmentValueEx)(PUNICODE_STRING  name, LPGUID  vendor, PVOID  value, PULONG  retlength, PULONG  attrib);
static WINAPI NTSTATUS (*pNtQuerySystemInformation)(SYSTEM_INFORMATION_CLASS  SystemInformationClass, PVOID  SystemInformation, ULONG  Length, PULONG  ResultLength);
static WINAPI NTSTATUS (*pNtQuerySystemInformationEx)(SYSTEM_INFORMATION_CLASS  SystemInformationClass, void*  Query, ULONG  QueryLength, void*  SystemInformation, ULONG  Length, ULONG*  ResultLength);
static WINAPI NTSTATUS (*pNtQuerySystemTime)(LARGE_INTEGER*  time);
static WINAPI NTSTATUS (*pNtQueryTimer)(HANDLE  TimerHandle, TIMER_INFORMATION_CLASS  TimerInformationClass, PVOID  TimerInformation, ULONG  Length, PULONG  ReturnLength);
static WINAPI NTSTATUS (*pNtQueryTimerResolution)(ULONG*  min_resolution, ULONG*  max_resolution, ULONG*  current_resolution);
static WINAPI NTSTATUS (*pNtQueryValueKey)(HANDLE  handle, UNICODE_STRING*  name, KEY_VALUE_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len);
static WINAPI NTSTATUS (*pNtQueryVirtualMemory)(HANDLE  process, LPCVOID  addr, MEMORY_INFORMATION_CLASS  info_class, PVOID  buffer, SIZE_T  len, SIZE_T*  res_len);
static WINAPI NTSTATUS (*pNtQueryVolumeInformationFile)(HANDLE  handle, PIO_STATUS_BLOCK  io, PVOID  buffer, ULONG  length, FS_INFORMATION_CLASS  info_class);
static WINAPI NTSTATUS (*pNtQueueApcThread)(HANDLE  handle, PNTAPCFUNC  func, ULONG_PTR  arg1, ULONG_PTR  arg2, ULONG_PTR  arg3);
static WINAPI NTSTATUS (*pNtRaiseException)(EXCEPTION_RECORD*  rec, CONTEXT*  context, BOOL  first_chance);
static WINAPI NTSTATUS (*pNtRaiseHardError)(NTSTATUS  ErrorStatus, ULONG  NumberOfParameters, PUNICODE_STRING  UnicodeStringParameterMask, PVOID*  Parameters, HARDERROR_RESPONSE_OPTION  ResponseOption, PHARDERROR_RESPONSE  Response);
static WINAPI NTSTATUS (*pNtReadFile)(HANDLE  hFile, HANDLE  hEvent, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, void*  buffer, ULONG  length, PLARGE_INTEGER  offset, PULONG  key);
static WINAPI NTSTATUS (*pNtReadFileScatter)(HANDLE  file, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, FILE_SEGMENT_ELEMENT*  segments, ULONG  length, PLARGE_INTEGER  offset, PULONG  key);
static WINAPI NTSTATUS (*pNtReadVirtualMemory)(HANDLE  process, void*  addr, void*  buffer, SIZE_T  size, SIZE_T*  bytes_read);
static WINAPI NTSTATUS (*pNtRegisterThreadTerminatePort)(HANDLE  PortHandle);
static WINAPI NTSTATUS (*pNtReleaseKeyedEvent)(HANDLE  handle, void*  key, BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtReleaseMutant)(HANDLE  handle, PLONG  prev_count);
static WINAPI NTSTATUS (*pNtReleaseSemaphore)(HANDLE  handle, ULONG  count, PULONG  previous);
static WINAPI NTSTATUS (*pNtRemoveIoCompletion)(HANDLE  CompletionPort, PULONG_PTR  CompletionKey, PULONG_PTR  CompletionValue, PIO_STATUS_BLOCK  iosb, PLARGE_INTEGER  WaitTime);
static WINAPI NTSTATUS (*pNtRemoveIoCompletionEx)(HANDLE  port, FILE_IO_COMPLETION_INFORMATION*  info, ULONG  count, ULONG*  written, LARGE_INTEGER*  timeout, BOOLEAN  alertable);
static WINAPI NTSTATUS (*pNtRenameKey)(HANDLE  handle, UNICODE_STRING*  name);
static WINAPI NTSTATUS (*pNtReplaceKey)(POBJECT_ATTRIBUTES  ObjectAttributes, HANDLE  Key, POBJECT_ATTRIBUTES  ReplacedObjectAttributes);
static WINAPI NTSTATUS (*pNtReplyWaitReceivePort)(HANDLE  PortHandle, PULONG  PortIdentifier, PLPC_MESSAGE  ReplyMessage, PLPC_MESSAGE  Message);
static WINAPI NTSTATUS (*pNtRequestWaitReplyPort)(HANDLE  PortHandle, PLPC_MESSAGE  pLpcMessageIn, PLPC_MESSAGE  pLpcMessageOut);
static WINAPI NTSTATUS (*pNtResetEvent)(HANDLE  handle, LONG*  prev_state);
static WINAPI NTSTATUS (*pNtResetWriteWatch)(HANDLE  process, PVOID  base, SIZE_T  size);
static WINAPI NTSTATUS (*pNtRestoreKey)(HANDLE  KeyHandle, HANDLE  FileHandle, ULONG  RestoreFlags);
static WINAPI NTSTATUS (*pNtResumeProcess)(HANDLE  handle);
static WINAPI NTSTATUS (*pNtResumeThread)(HANDLE  handle, PULONG  count);
static WINAPI NTSTATUS (*pNtSaveKey)(HANDLE  KeyHandle, HANDLE  FileHandle);
static WINAPI NTSTATUS (*pNtSecureConnectPort)(PHANDLE  PortHandle, PUNICODE_STRING  PortName, PSECURITY_QUALITY_OF_SERVICE  SecurityQos, PLPC_SECTION_WRITE  WriteSection, PSID  pSid, PLPC_SECTION_READ  ReadSection, PULONG  MaximumMessageLength, PVOID  ConnectInfo, PULONG  pConnectInfoLength);
static WINAPI NTSTATUS (*pNtSetContextThread)(HANDLE  handle, CONTEXT*  context);
static WINAPI NTSTATUS (*pNtSetDefaultLocale)(BOOLEAN  user, LCID  lcid);
static WINAPI NTSTATUS (*pNtSetDefaultUILanguage)(LANGID  lang);
static WINAPI NTSTATUS (*pNtSetEaFile)(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PVOID  buffer, ULONG  length);
static WINAPI NTSTATUS (*pNtSetEvent)(HANDLE  handle, LONG*  prev_state);
static WINAPI NTSTATUS (*pNtSetInformationFile)(HANDLE  handle, PIO_STATUS_BLOCK  io, PVOID  ptr, ULONG  len, FILE_INFORMATION_CLASS  class);
static WINAPI NTSTATUS (*pNtSetInformationJobObject)(HANDLE  handle, JOBOBJECTINFOCLASS  class, PVOID  info, ULONG  len);
static WINAPI NTSTATUS (*pNtSetInformationKey)(HANDLE  KeyHandle, int  KeyInformationClass, PVOID  KeyInformation, ULONG  KeyInformationLength);
static WINAPI NTSTATUS (*pNtSetInformationObject)(HANDLE  handle, OBJECT_INFORMATION_CLASS  info_class, PVOID  ptr, ULONG  len);
static WINAPI NTSTATUS (*pNtSetInformationProcess)(HANDLE  ProcessHandle, PROCESSINFOCLASS  ProcessInformationClass, PVOID  ProcessInformation, ULONG  ProcessInformationLength);
static WINAPI NTSTATUS (*pNtSetInformationThread)(HANDLE  handle, THREADINFOCLASS  class, LPCVOID  data, ULONG  length);
static WINAPI NTSTATUS (*pNtSetInformationToken)(HANDLE  TokenHandle, TOKEN_INFORMATION_CLASS  TokenInformationClass, PVOID  TokenInformation, ULONG  TokenInformationLength);
static WINAPI NTSTATUS (*pNtSetIntervalProfile)(ULONG  Interval, KPROFILE_SOURCE  Source);
static WINAPI NTSTATUS (*pNtSetIoCompletion)(HANDLE  CompletionPort, ULONG_PTR  CompletionKey, ULONG_PTR  CompletionValue, NTSTATUS  Status, SIZE_T  NumberOfBytesTransferred);
static WINAPI NTSTATUS (*pNtSetLdtEntries)(ULONG  selector1, ULONG  entry1_low, ULONG  entry1_high, ULONG  selector2, ULONG  entry2_low, ULONG  entry2_high);
static WINAPI NTSTATUS (*pNtSetPowerRequest)(HANDLE  handle, POWER_REQUEST_TYPE  type);
static WINAPI NTSTATUS (*pNtSetSecurityObject)(HANDLE  Handle, SECURITY_INFORMATION  SecurityInformation, PSECURITY_DESCRIPTOR  SecurityDescriptor);
static WINAPI NTSTATUS (*pNtSetSystemInformation)(SYSTEM_INFORMATION_CLASS  SystemInformationClass, PVOID  SystemInformation, ULONG  Length);
static WINAPI NTSTATUS (*pNtSetSystemTime)(LARGE_INTEGER*  NewTime, LARGE_INTEGER*  OldTime);
static WINAPI NTSTATUS (*pNtSetThreadExecutionState)(EXECUTION_STATE  new_state, EXECUTION_STATE*  old_state);
static WINAPI NTSTATUS (*pNtSetTimer)(HANDLE  handle, LARGE_INTEGER*  when, PTIMER_APC_ROUTINE  callback, PVOID  callback_arg, BOOLEAN  resume, ULONG  period, PBOOLEAN  state);
static WINAPI NTSTATUS (*pNtSetTimerResolution)(ULONG  resolution, BOOLEAN  set_resolution, ULONG*  current_resolution);
static WINAPI NTSTATUS (*pNtSetValueKey)(HANDLE  hkey, UNICODE_STRING*  name, ULONG  TitleIndex, ULONG  type, void*  data, ULONG  count);
static WINAPI NTSTATUS (*pNtSetVolumeInformationFile)(HANDLE  FileHandle, PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FsInformation, ULONG  Length, FS_INFORMATION_CLASS  FsInformationClass);
static WINAPI NTSTATUS (*pNtShutdownSystem)(SHUTDOWN_ACTION  Action);
static WINAPI NTSTATUS (*pNtSignalAndWaitForSingleObject)(HANDLE  hSignalObject, HANDLE  hWaitObject, BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtSuspendProcess)(HANDLE  handle);
static WINAPI NTSTATUS (*pNtSuspendThread)(HANDLE  handle, PULONG  count);
static WINAPI NTSTATUS (*pNtSystemDebugControl)(SYSDBG_COMMAND  command, PVOID  inbuffer, ULONG  inbuflength, PVOID  outbuffer, ULONG  outbuflength, PULONG  retlength);
static WINAPI NTSTATUS (*pNtTerminateJobObject)(HANDLE  handle, NTSTATUS  status);
static WINAPI NTSTATUS (*pNtTerminateProcess)(HANDLE  handle, LONG  exit_code);
static WINAPI NTSTATUS (*pNtTerminateThread)(HANDLE  handle, LONG  exit_code);
static WINAPI NTSTATUS (*pNtUnloadDriver)(UNICODE_STRING*  DriverServiceName);
static WINAPI NTSTATUS (*pNtUnloadKey)(POBJECT_ATTRIBUTES  attr);
static WINAPI NTSTATUS (*pNtUnlockFile)(HANDLE  hFile, PIO_STATUS_BLOCK  io_status, PLARGE_INTEGER  offset, PLARGE_INTEGER  count, PULONG  key);
static WINAPI NTSTATUS (*pNtUnlockVirtualMemory)(HANDLE  process, PVOID*  addr, SIZE_T*  size, ULONG  unknown);
static WINAPI NTSTATUS (*pNtUnmapViewOfSection)(HANDLE  process, PVOID  addr);
static WINAPI NTSTATUS (*pNtWaitForKeyedEvent)(HANDLE  handle, void*  key, BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtWaitForMultipleObjects)(DWORD  count, HANDLE*  handles, BOOLEAN  wait_any, BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtWaitForSingleObject)(HANDLE  handle, BOOLEAN  alertable, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pNtWriteFile)(HANDLE  hFile, HANDLE  hEvent, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, void*  buffer, ULONG  length, PLARGE_INTEGER  offset, PULONG  key);
static WINAPI NTSTATUS (*pNtWriteFileGather)(HANDLE  file, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, FILE_SEGMENT_ELEMENT*  segments, ULONG  length, PLARGE_INTEGER  offset, PULONG  key);
static WINAPI NTSTATUS (*pNtWriteVirtualMemory)(HANDLE  process, void*  addr, void*  buffer, SIZE_T  size, SIZE_T*  bytes_written);
static WINAPI NTSTATUS (*pNtYieldExecution)(void);
static WINAPI NTSTATUS (*pRtlAbsoluteToSelfRelativeSD)(PSECURITY_DESCRIPTOR  AbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR  SelfRelativeSecurityDescriptor, PULONG  BufferLength);
static WINAPI void (*pRtlAcquirePebLock)(void);
static WINAPI BYTE (*pRtlAcquireResourceExclusive)(LPRTL_RWLOCK  rwl, BYTE  fWait);
static WINAPI BYTE (*pRtlAcquireResourceShared)(LPRTL_RWLOCK  rwl, BYTE  fWait);
static WINAPI void (*pRtlAcquireSRWLockExclusive)(RTL_SRWLOCK*  lock);
static WINAPI void (*pRtlAcquireSRWLockShared)(RTL_SRWLOCK*  lock);
static WINAPI NTSTATUS (*pRtlActivateActivationContext)(ULONG  unknown, HANDLE  handle, PULONG_PTR  cookie);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  AccessMask, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedAceEx)(PACL  pAcl, DWORD  dwAceRevision, DWORD  AceFlags, DWORD  AccessMask, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAccessAllowedObjectAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  AccessMask, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedAceEx)(PACL  pAcl, DWORD  dwAceRevision, DWORD  AceFlags, DWORD  AccessMask, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAccessDeniedObjectAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid);
static WINAPI NTSTATUS (*pRtlAddAce)(PACL  acl, DWORD  rev, DWORD  xnrofaces, PACE_HEADER  acestart, DWORD  acelen);
static WINAPI NTSTATUS (*pRtlAddAtomToAtomTable)(RTL_ATOM_TABLE  table, WCHAR*  name, RTL_ATOM*  atom);
static WINAPI NTSTATUS (*pRtlAddAuditAccessAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAccessMask, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddAuditAccessAceEx)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddAuditAccessObjectAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure);
static WINAPI NTSTATUS (*pRtlAddMandatoryAce)(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwMandatoryFlags, DWORD  dwAceType, PSID  pSid);
static WINAPI BOOLEAN (*pRtlAddFunctionTable)(RUNTIME_FUNCTION*  table, DWORD  count, ULONG_PTR  addr);
static WINAPI DWORD (*pRtlAddGrowableFunctionTable)(void**  table, RUNTIME_FUNCTION*  functions, DWORD  count, DWORD  max_count, ULONG_PTR  base, ULONG_PTR  end);
static WINAPI void (*pRtlAddRefActivationContext)(HANDLE  handle);
static WINAPI PVOID (*pRtlAddVectoredContinueHandler)(ULONG  first, PVECTORED_EXCEPTION_HANDLER  func);
static WINAPI PVOID (*pRtlAddVectoredExceptionHandler)(ULONG  first, PVECTORED_EXCEPTION_HANDLER  func);
static WINAPI NTSTATUS (*pRtlAdjustPrivilege)(ULONG  Privilege, BOOLEAN  Enable, BOOLEAN  CurrentThread, PBOOLEAN  Enabled);
static WINAPI NTSTATUS (*pRtlAllocateAndInitializeSid)(PSID_IDENTIFIER_AUTHORITY  pIdentifierAuthority, BYTE  nSubAuthorityCount, DWORD  nSubAuthority0, DWORD  nSubAuthority1, DWORD  nSubAuthority2, DWORD  nSubAuthority3, DWORD  nSubAuthority4, DWORD  nSubAuthority5, DWORD  nSubAuthority6, DWORD  nSubAuthority7, PSID*  pSid);
static WINAPI RTL_HANDLE* (*pRtlAllocateHandle)(RTL_HANDLE_TABLE*  HandleTable, ULONG*  HandleIndex);
static WINAPI PVOID (*pRtlAllocateHeap)(HANDLE  heap, ULONG  flags, SIZE_T  size);
static WINAPI WCHAR (*pRtlAnsiCharToUnicodeChar)(LPSTR*  ansi);
static WINAPI DWORD (*pRtlAnsiStringToUnicodeSize)(STRING*  str);
static WINAPI NTSTATUS (*pRtlAnsiStringToUnicodeString)(PUNICODE_STRING  uni, PCANSI_STRING  ansi, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlAppendAsciizToString)(STRING*  dest, LPCSTR  src);
static WINAPI NTSTATUS (*pRtlAppendStringToString)(STRING*  dest, STRING*  src);
static WINAPI NTSTATUS (*pRtlAppendUnicodeStringToString)(UNICODE_STRING*  dest, UNICODE_STRING*  src);
static WINAPI NTSTATUS (*pRtlAppendUnicodeToString)(UNICODE_STRING*  dest, LPCWSTR  src);
static WINAPI BOOLEAN (*pRtlAreAllAccessesGranted)(ACCESS_MASK  GrantedAccess, ACCESS_MASK  DesiredAccess);
static WINAPI BOOLEAN (*pRtlAreAnyAccessesGranted)(ACCESS_MASK  GrantedAccess, ACCESS_MASK  DesiredAccess);
static WINAPI BOOLEAN (*pRtlAreBitsClear)(PCRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount);
static WINAPI BOOLEAN (*pRtlAreBitsSet)(PCRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount);
static WINAPI void (*pRtlAssert)(void*  assertion, void*  filename, ULONG  linenumber, char*  message);
static WINAPI USHORT (*pRtlCaptureStackBackTrace)(ULONG  skip, ULONG  count, PVOID*  buffer, ULONG*  hash);
static WINAPI NTSTATUS (*pRtlCharToInteger)(PCSZ  str, ULONG  base, ULONG*  value);
static WINAPI NTSTATUS (*pRtlCheckRegistryKey)(ULONG  RelativeTo, PWSTR  Path);
static WINAPI void (*pRtlClearAllBits)(PRTL_BITMAP  lpBits);
static WINAPI void (*pRtlClearBits)(PRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount);
static WINAPI ULONG (*pRtlCompactHeap)(HANDLE  heap, ULONG  flags);
static WINAPI SIZE_T (*pRtlCompareMemory)(void*  Source1, void*  Source2, SIZE_T  Length);
static WINAPI SIZE_T (*pRtlCompareMemoryUlong)(ULONG*  Source1, SIZE_T  Length, ULONG  dwVal);
static WINAPI LONG (*pRtlCompareString)(STRING*  s1, STRING*  s2, BOOLEAN  CaseInsensitive);
static WINAPI LONG (*pRtlCompareUnicodeString)(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  CaseInsensitive);
static WINAPI LONG (*pRtlCompareUnicodeStrings)(WCHAR*  s1, SIZE_T  len1, WCHAR*  s2, SIZE_T  len2, BOOLEAN  case_insensitive);
static WINAPI NTSTATUS (*pRtlCompressBuffer)(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, ULONG  chunk_size, PULONG  final_size, PVOID  workspace);
static WINAPI DWORD (*pRtlComputeCrc32)(DWORD  dwInitial, BYTE*  pData, INT  iLen);
static WINAPI NTSTATUS (*pRtlConvertSidToUnicodeString)(PUNICODE_STRING  String, PSID  pSid, BOOLEAN  AllocateString);
static WINAPI BOOL (*pRtlConvertToAutoInheritSecurityObject)(PSECURITY_DESCRIPTOR  pdesc, PSECURITY_DESCRIPTOR  cdesc, PSECURITY_DESCRIPTOR*  ndesc, GUID*  objtype, BOOL  isdir, PGENERIC_MAPPING  genmap);
static WINAPI void (*pRtlCopyLuid)(PLUID  LuidDest, LUID*  LuidSrc);
static WINAPI void (*pRtlCopyLuidAndAttributesArray)(ULONG  Count, LUID_AND_ATTRIBUTES*  Src, PLUID_AND_ATTRIBUTES  Dest);
static WINAPI void (*pRtlCopyMemory)(void*  dest, void*  src, SIZE_T  len);
static WINAPI NTSTATUS (*pRtlCopySecurityDescriptor)(PSECURITY_DESCRIPTOR  pSourceSD, PSECURITY_DESCRIPTOR  pDestinationSD);
static WINAPI BOOLEAN (*pRtlCopySid)(DWORD  nDestinationSidLength, PSID  pDestinationSid, PSID  pSourceSid);
static WINAPI void (*pRtlCopyString)(STRING*  dst, STRING*  src);
static WINAPI void (*pRtlCopyUnicodeString)(UNICODE_STRING*  dst, UNICODE_STRING*  src);
static WINAPI NTSTATUS (*pRtlCreateAcl)(PACL  acl, DWORD  size, DWORD  rev);
static WINAPI NTSTATUS (*pRtlCreateActivationContext)(HANDLE*  handle, void*  ptr);
static WINAPI NTSTATUS (*pRtlCreateAtomTable)(ULONG  size, RTL_ATOM_TABLE*  table);
static WINAPI NTSTATUS (*pRtlCreateEnvironment)(BOOLEAN  inherit, PWSTR*  env);
static WINAPI HANDLE (*pRtlCreateHeap)(ULONG  flags, PVOID  addr, SIZE_T  totalSize, SIZE_T  commitSize, PVOID  unknown, PRTL_HEAP_DEFINITION  definition);
static WINAPI NTSTATUS (*pRtlCreateProcessParameters)(RTL_USER_PROCESS_PARAMETERS**  result, UNICODE_STRING*  image, UNICODE_STRING*  dllpath, UNICODE_STRING*  curdir, UNICODE_STRING*  cmdline, PWSTR  env, UNICODE_STRING*  title, UNICODE_STRING*  desktop, UNICODE_STRING*  shellinfo, UNICODE_STRING*  runtime);
static WINAPI NTSTATUS (*pRtlCreateProcessParametersEx)(RTL_USER_PROCESS_PARAMETERS**  result, UNICODE_STRING*  ImagePathName, UNICODE_STRING*  DllPath, UNICODE_STRING*  CurrentDirectoryName, UNICODE_STRING*  CommandLine, PWSTR  Environment, UNICODE_STRING*  WindowTitle, UNICODE_STRING*  Desktop, UNICODE_STRING*  ShellInfo, UNICODE_STRING*  RuntimeInfo, ULONG  flags);
static WINAPI PDEBUG_BUFFER (*pRtlCreateQueryDebugBuffer)(ULONG  iSize, BOOLEAN  iEventPair);
static WINAPI NTSTATUS (*pRtlCreateRegistryKey)(ULONG  RelativeTo, PWSTR  path);
static WINAPI NTSTATUS (*pRtlCreateSecurityDescriptor)(PSECURITY_DESCRIPTOR  lpsd, DWORD  rev);
static WINAPI NTSTATUS (*pRtlCreateTimer)(PHANDLE  NewTimer, HANDLE  TimerQueue, RTL_WAITORTIMERCALLBACKFUNC  Callback, PVOID  Parameter, DWORD  DueTime, DWORD  Period, ULONG  Flags);
static WINAPI NTSTATUS (*pRtlCreateTimerQueue)(PHANDLE  NewTimerQueue);
static WINAPI BOOLEAN (*pRtlCreateUnicodeString)(PUNICODE_STRING  target, LPCWSTR  src);
static WINAPI BOOLEAN (*pRtlCreateUnicodeStringFromAsciiz)(PUNICODE_STRING  target, LPCSTR  src);
static WINAPI NTSTATUS (*pRtlCreateUserProcess)(UNICODE_STRING*  path, ULONG  attributes, RTL_USER_PROCESS_PARAMETERS*  params, SECURITY_DESCRIPTOR*  process_descr, SECURITY_DESCRIPTOR*  thread_descr, HANDLE  parent, BOOLEAN  inherit, HANDLE  debug, HANDLE  exception, RTL_USER_PROCESS_INFORMATION*  info);
static WINAPI NTSTATUS (*pRtlCreateUserStack)(SIZE_T  commit, SIZE_T  reserve, ULONG  zero_bits, SIZE_T  commit_align, SIZE_T  reserve_align, INITIAL_TEB*  stack);
static WINAPI NTSTATUS (*pRtlCreateUserThread)(HANDLE  process, SECURITY_DESCRIPTOR*  descr, BOOLEAN  suspended, PVOID  stack_addr, SIZE_T  stack_reserve, SIZE_T  stack_commit, PRTL_THREAD_START_ROUTINE  start, void*  param, HANDLE*  handle_ptr, CLIENT_ID*  id);
static WINAPI PRTL_USER_PROCESS_PARAMETERS (*pRtlDeNormalizeProcessParams)(RTL_USER_PROCESS_PARAMETERS*  params);
static WINAPI void (*pRtlDeactivateActivationContext)(ULONG  flags, ULONG_PTR  cookie);
static WINAPI PVOID (*pRtlDecodePointer)(PVOID  ptr);
static WINAPI NTSTATUS (*pRtlDecompressBuffer)(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, PULONG  final_size);
static WINAPI NTSTATUS (*pRtlDecompressFragment)(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, ULONG  offset, PULONG  final_size, PVOID  workspace);
static WINAPI NTSTATUS (*pRtlDeleteAce)(PACL  pAcl, DWORD  dwAceIndex);
static WINAPI NTSTATUS (*pRtlDeleteAtomFromAtomTable)(RTL_ATOM_TABLE  table, RTL_ATOM  atom);
static WINAPI NTSTATUS (*pRtlDeleteCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI void (*pRtlDeleteGrowableFunctionTable)(void*  table);
static WINAPI BOOLEAN (*pRtlDeleteFunctionTable)(RUNTIME_FUNCTION*  table);
static WINAPI NTSTATUS (*pRtlDeleteRegistryValue)(ULONG  RelativeTo, PCWSTR  Path, PCWSTR  ValueName);
static WINAPI void (*pRtlDeleteResource)(LPRTL_RWLOCK  rwl);
static WINAPI NTSTATUS (*pRtlDeleteSecurityObject)(PSECURITY_DESCRIPTOR*  ObjectDescriptor);
static WINAPI NTSTATUS (*pRtlDeleteTimer)(HANDLE  TimerQueue, HANDLE  Timer, HANDLE  CompletionEvent);
static WINAPI NTSTATUS (*pRtlDeleteTimerQueueEx)(HANDLE  TimerQueue, HANDLE  CompletionEvent);
static WINAPI NTSTATUS (*pRtlDeregisterWait)(HANDLE  WaitHandle);
static WINAPI NTSTATUS (*pRtlDeregisterWaitEx)(HANDLE  WaitHandle, HANDLE  CompletionEvent);
static WINAPI NTSTATUS (*pRtlDestroyAtomTable)(RTL_ATOM_TABLE  table);
static WINAPI NTSTATUS (*pRtlDestroyEnvironment)(PWSTR  env);
static WINAPI NTSTATUS (*pRtlDestroyHandleTable)(RTL_HANDLE_TABLE*  HandleTable);
static WINAPI HANDLE (*pRtlDestroyHeap)(HANDLE  heap);
static WINAPI void (*pRtlDestroyProcessParameters)(RTL_USER_PROCESS_PARAMETERS*  params);
static WINAPI NTSTATUS (*pRtlDestroyQueryDebugBuffer)(PDEBUG_BUFFER  iBuf);
static WINAPI DOS_PATHNAME_TYPE (*pRtlDetermineDosPathNameType_U)(PCWSTR  path);
static WINAPI BOOLEAN (*pRtlDllShutdownInProgress)(void);
static WINAPI BOOLEAN (*pRtlDoesFileExists_U)(LPCWSTR  file_name);
static WINAPI BOOLEAN (*pRtlDosPathNameToNtPathName_U)(PCWSTR  dos_path, PUNICODE_STRING  ntpath, PWSTR*  file_part, CURDIR*  cd);
static WINAPI NTSTATUS (*pRtlDosPathNameToNtPathName_U_WithStatus)(WCHAR*  dos_path, UNICODE_STRING*  ntpath, WCHAR**  file_part, CURDIR*  cd);
static WINAPI NTSTATUS (*pRtlDosPathNameToRelativeNtPathName_U_WithStatus)(WCHAR*  dos_path, UNICODE_STRING*  ntpath, WCHAR**  file_part, RTL_RELATIVE_NAME*  relative);
static WINAPI ULONG (*pRtlDosSearchPath_U)(LPCWSTR  paths, LPCWSTR  search, LPCWSTR  ext, ULONG  buffer_size, LPWSTR  buffer, LPWSTR*  file_part);
static WINAPI WCHAR (*pRtlDowncaseUnicodeChar)(WCHAR  wch);
static WINAPI NTSTATUS (*pRtlDowncaseUnicodeString)(UNICODE_STRING*  dest, UNICODE_STRING*  src, BOOLEAN  doalloc);
static WINAPI void (*pRtlDumpResource)(LPRTL_RWLOCK  rwl);
static WINAPI NTSTATUS (*pRtlDuplicateUnicodeString)(int  add_nul, UNICODE_STRING*  source, UNICODE_STRING*  destination);
static WINAPI NTSTATUS (*pRtlEmptyAtomTable)(RTL_ATOM_TABLE  table, BOOLEAN  delete_pinned);
static WINAPI PVOID (*pRtlEncodePointer)(PVOID  ptr);
static WINAPI NTSTATUS (*pRtlEnterCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI PVOID (*pRtlEnumerateGenericTableWithoutSplaying)(PVOID  pTable, PVOID*  RestartKey);
static WINAPI NTSTATUS (*pRtlEqualComputerName)(UNICODE_STRING*  left, UNICODE_STRING*  right);
static WINAPI NTSTATUS (*pRtlEqualDomainName)(UNICODE_STRING*  left, UNICODE_STRING*  right);
static WINAPI BOOLEAN (*pRtlEqualLuid)(LUID*  Luid1, LUID*  Luid2);
static WINAPI BOOL (*pRtlEqualPrefixSid)(PSID  pSid1, PSID  pSid2);
static WINAPI BOOL (*pRtlEqualSid)(PSID  pSid1, PSID  pSid2);
static WINAPI BOOLEAN (*pRtlEqualString)(STRING*  s1, STRING*  s2, BOOLEAN  CaseInsensitive);
static WINAPI BOOLEAN (*pRtlEqualUnicodeString)(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  CaseInsensitive);
static WINAPI void (*pRtlEraseUnicodeString)(UNICODE_STRING*  str);
static WINAPI void (*pRtlExitUserProcess)(DWORD  status);
static WINAPI void (*pRtlExitUserThread)(ULONG  status);
static WINAPI NTSTATUS (*pRtlExpandEnvironmentStrings)(WCHAR*  renv, WCHAR*  src, SIZE_T  src_len, WCHAR*  dst, SIZE_T  count, SIZE_T*  plen);
static WINAPI NTSTATUS (*pRtlExpandEnvironmentStrings_U)(WCHAR*  env, UNICODE_STRING*  src, UNICODE_STRING*  dst, ULONG*  plen);
static WINAPI void (*pRtlFillMemory)(void*  Destination, SIZE_T  Length, BYTE  Fill);
static WINAPI void (*pRtlFillMemoryUlong)(ULONG*  lpDest, ULONG  ulCount, ULONG  ulValue);
static WINAPI NTSTATUS (*pRtlFindActivationContextSectionGuid)(ULONG  flags, GUID*  extguid, ULONG  section_kind, GUID*  guid, void*  ptr);
static WINAPI NTSTATUS (*pRtlFindActivationContextSectionString)(ULONG  flags, GUID*  guid, ULONG  section_kind, UNICODE_STRING*  section_name, PVOID  ptr);
static WINAPI NTSTATUS (*pRtlFindCharInUnicodeString)(int  flags, UNICODE_STRING*  main_str, UNICODE_STRING*  search_chars, USHORT*  pos);
static WINAPI ULONG (*pRtlFindClearBits)(PCRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint);
static WINAPI ULONG (*pRtlFindClearBitsAndSet)(PRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint);
static WINAPI ULONG (*pRtlFindClearRuns)(PCRTL_BITMAP  lpBits, PRTL_BITMAP_RUN  lpSeries, ULONG  ulCount, BOOLEAN  bLongest);
static WINAPI ULONG (*pRtlFindLastBackwardRunClear)(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos);
static WINAPI ULONG (*pRtlFindLastBackwardRunSet)(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos);
static WINAPI CCHAR (*pRtlFindLeastSignificantBit)(ULONGLONG  ulLong);
static WINAPI ULONG (*pRtlFindLongestRunClear)(PCRTL_BITMAP  lpBits, PULONG  pulStart);
static WINAPI ULONG (*pRtlFindLongestRunSet)(PCRTL_BITMAP  lpBits, PULONG  pulStart);
static WINAPI NTSTATUS (*pRtlFindMessage)(HMODULE  hmod, ULONG  type, ULONG  lang, ULONG  msg_id, MESSAGE_RESOURCE_ENTRY**  ret);
static WINAPI CCHAR (*pRtlFindMostSignificantBit)(ULONGLONG  ulLong);
static WINAPI ULONG (*pRtlFindNextForwardRunClear)(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos);
static WINAPI ULONG (*pRtlFindNextForwardRunSet)(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos);
static WINAPI ULONG (*pRtlFindSetBits)(PCRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint);
static WINAPI ULONG (*pRtlFindSetBitsAndClear)(PRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint);
static WINAPI ULONG (*pRtlFindSetRuns)(PCRTL_BITMAP  lpBits, PRTL_BITMAP_RUN  lpSeries, ULONG  ulCount, BOOLEAN  bLongest);
static WINAPI PSLIST_ENTRY (*pRtlFirstEntrySList)(SLIST_HEADER*  list);
static WINAPI BOOLEAN (*pRtlFirstFreeAce)(PACL  acl, PACE_HEADER*  x);
static WINAPI NTSTATUS (*pRtlFormatCurrentUserKeyPath)(PUNICODE_STRING  KeyPath);
static WINAPI NTSTATUS (*pRtlFormatMessage)(LPWSTR  Message, UCHAR  MaxWidth, BOOLEAN  IgnoreInserts, BOOLEAN  Ansi, BOOLEAN  ArgumentIsArray, __builtin_ms_va_list*  Arguments, LPWSTR  Buffer, ULONG  BufferSize);
static WINAPI void (*pRtlFreeAnsiString)(PSTRING  str);
static WINAPI BOOLEAN (*pRtlFreeHandle)(RTL_HANDLE_TABLE*  HandleTable, RTL_HANDLE*  Handle);
static WINAPI BOOLEAN (*pRtlFreeHeap)(HANDLE  heap, ULONG  flags, void*  ptr);
static WINAPI void (*pRtlFreeOemString)(PSTRING  str);
static WINAPI DWORD (*pRtlFreeSid)(PSID  pSid);
static WINAPI void (*pRtlFreeThreadActivationContextStack)(void);
static WINAPI void (*pRtlFreeUnicodeString)(PUNICODE_STRING  str);
static WINAPI void (*pRtlFreeUserStack)(void*  stack);
static WINAPI NTSTATUS (*pRtlGUIDFromString)(PUNICODE_STRING  str, GUID*  guid);
static WINAPI NTSTATUS (*pRtlGetAce)(PACL  pAcl, DWORD  dwAceIndex, LPVOID*  pAce);
static WINAPI NTSTATUS (*pRtlGetActiveActivationContext)(HANDLE*  handle);
static WINAPI NTSTATUS (*pRtlGetCompressionWorkSpaceSize)(USHORT  format, PULONG  compress_workspace, PULONG  decompress_workspace);
static WINAPI NTSTATUS (*pRtlGetControlSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSECURITY_DESCRIPTOR_CONTROL  pControl, LPDWORD  lpdwRevision);
static WINAPI ULONG (*pRtlGetCurrentDirectory_U)(ULONG  buflen, LPWSTR  buf);
static WINAPI PEB* (*pRtlGetCurrentPeb)(void);
static WINAPI void (*pRtlGetCurrentProcessorNumberEx)(PROCESSOR_NUMBER*  processor);
static WINAPI HANDLE (*pRtlGetCurrentTransaction)(void);
static WINAPI NTSTATUS (*pRtlGetDaclSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PBOOLEAN  lpbDaclPresent, PACL*  pDacl, PBOOLEAN  lpbDaclDefaulted);
static WINAPI TEB_ACTIVE_FRAME* (*pRtlGetFrame)(void);
static WINAPI ULONG (*pRtlGetFullPathName_U)(WCHAR*  name, ULONG  size, WCHAR*  buffer, WCHAR**  file_part);
static WINAPI NTSTATUS (*pRtlGetGroupSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID*  Group, PBOOLEAN  GroupDefaulted);
static WINAPI NTSTATUS (*pRtlGetLastNtStatus)(void);
static WINAPI DWORD (*pRtlGetLastWin32Error)(void);
static WINAPI DWORD (*pRtlGetLongestNtPathLength)(void);
static WINAPI ULONG (*pRtlGetNtGlobalFlags)(void);
static WINAPI BOOLEAN (*pRtlGetNtProductType)(LPDWORD  type);
static WINAPI void (*pRtlGetNtVersionNumbers)(LPDWORD  major, LPDWORD  minor, LPDWORD  build);
static WINAPI NTSTATUS (*pRtlGetOwnerSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID*  Owner, PBOOLEAN  OwnerDefaulted);
static WINAPI BOOLEAN (*pRtlGetProductInfo)(DWORD  dwOSMajorVersion, DWORD  dwOSMinorVersion, DWORD  dwSpMajorVersion, DWORD  dwSpMinorVersion, PDWORD  pdwReturnedProductType);
static WINAPI ULONG (*pRtlGetProcessHeaps)(ULONG  count, HANDLE*  heaps);
static WINAPI NTSTATUS (*pRtlGetSaclSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PBOOLEAN  lpbSaclPresent, PACL*  pSacl, PBOOLEAN  lpbSaclDefaulted);
static WINAPI LONGLONG (*pRtlGetSystemTimePrecise)(void);
static WINAPI DWORD (*pRtlGetThreadErrorMode)(void);
static WINAPI RTL_UNLOAD_EVENT_TRACE* (*pRtlGetUnloadEventTrace)(void);
static WINAPI void (*pRtlGetUnloadEventTraceEx)(ULONG**  size, ULONG**  count, void**  trace);
static WINAPI NTSTATUS (*pRtlGetVersion)(RTL_OSVERSIONINFOEXW*  info);
static WINAPI void (*pRtlGrowFunctionTable)(void*  table, DWORD  count);
static WINAPI NTSTATUS (*pRtlHashUnicodeString)(PCUNICODE_STRING  string, BOOLEAN  case_insensitive, ULONG  alg, ULONG*  hash);
static WINAPI PSID_IDENTIFIER_AUTHORITY (*pRtlIdentifierAuthoritySid)(PSID  pSid);
static WINAPI PVOID (*pRtlImageDirectoryEntryToData)(HMODULE  module, BOOL  image, WORD  dir, ULONG*  size);
static WINAPI PIMAGE_NT_HEADERS (*pRtlImageNtHeader)(HMODULE  hModule);
static WINAPI PIMAGE_SECTION_HEADER (*pRtlImageRvaToSection)(IMAGE_NT_HEADERS*  nt, HMODULE  module, DWORD  rva);
static WINAPI PVOID (*pRtlImageRvaToVa)(IMAGE_NT_HEADERS*  nt, HMODULE  module, DWORD  rva, IMAGE_SECTION_HEADER**  section);
static WINAPI NTSTATUS (*pRtlImpersonateSelf)(SECURITY_IMPERSONATION_LEVEL  ImpersonationLevel);
static WINAPI void (*pRtlInitAnsiString)(PANSI_STRING  target, PCSZ  source);
static WINAPI NTSTATUS (*pRtlInitAnsiStringEx)(PANSI_STRING  target, PCSZ  source);
static WINAPI void (*pRtlInitString)(PSTRING  target, PCSZ  source);
static WINAPI void (*pRtlInitUnicodeString)(PUNICODE_STRING  target, PCWSTR  source);
static WINAPI NTSTATUS (*pRtlInitUnicodeStringEx)(PUNICODE_STRING  target, PCWSTR  source);
static WINAPI void (*pRtlInitializeBitMap)(PRTL_BITMAP  lpBits, PULONG  lpBuff, ULONG  ulSize);
static WINAPI void (*pRtlInitializeConditionVariable)(RTL_CONDITION_VARIABLE*  variable);
static WINAPI NTSTATUS (*pRtlInitializeCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI NTSTATUS (*pRtlInitializeCriticalSectionAndSpinCount)(RTL_CRITICAL_SECTION*  crit, ULONG  spincount);
static WINAPI NTSTATUS (*pRtlInitializeCriticalSectionEx)(RTL_CRITICAL_SECTION*  crit, ULONG  spincount, ULONG  flags);
static WINAPI PVOID (*pRtlInitializeGenericTable)(PVOID  pTable, PVOID  arg2, PVOID  arg3, PVOID  arg4, PVOID  arg5);
static WINAPI void (*pRtlInitializeGenericTableAvl)(PRTL_AVL_TABLE  table, PRTL_AVL_COMPARE_ROUTINE  compare, PRTL_AVL_ALLOCATE_ROUTINE  allocate, PRTL_AVL_FREE_ROUTINE  free, void*  context);
static WINAPI void (*pRtlInitializeHandleTable)(ULONG  MaxHandleCount, ULONG  HandleSize, RTL_HANDLE_TABLE*  HandleTable);
static WINAPI void (*pRtlInitializeResource)(LPRTL_RWLOCK  rwl);
static WINAPI void (*pRtlInitializeSListHead)(PSLIST_HEADER  list);
static WINAPI void (*pRtlInitializeSRWLock)(RTL_SRWLOCK*  lock);
static WINAPI BOOL (*pRtlInitializeSid)(PSID  pSid, PSID_IDENTIFIER_AUTHORITY  pIdentifierAuthority, BYTE  nSubAuthorityCount);
static WINAPI void (*pRtlInsertElementGenericTableAvl)(PRTL_AVL_TABLE  table, void*  buffer, ULONG  size, BOOL*  element);
static WINAPI BOOLEAN (*pRtlInstallFunctionTableCallback)(ULONG_PTR  table, ULONG_PTR  base, DWORD  length, PGET_RUNTIME_FUNCTION_CALLBACK  callback, PVOID  context, PCWSTR  dll);
static WINAPI NTSTATUS (*pRtlInt64ToUnicodeString)(ULONGLONG  value, ULONG  base, UNICODE_STRING*  str);
static WINAPI NTSTATUS (*pRtlIntegerToChar)(ULONG  value, ULONG  base, ULONG  length, PCHAR  str);
static WINAPI NTSTATUS (*pRtlIntegerToUnicodeString)(ULONG  value, ULONG  base, UNICODE_STRING*  str);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedFlushSList)(PSLIST_HEADER  list);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPopEntrySList)(PSLIST_HEADER  list);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushEntrySList)(PSLIST_HEADER  list, PSLIST_ENTRY  entry);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushListSList)(PSLIST_HEADER  list, PSLIST_ENTRY  first, PSLIST_ENTRY  last, ULONG  count);
static WINAPI PSLIST_ENTRY (*pRtlInterlockedPushListSListEx)(PSLIST_HEADER  list, PSLIST_ENTRY  first, PSLIST_ENTRY  last, ULONG  count);
static WINAPI CHAR* (*pRtlIpv4AddressToStringA)(IN_ADDR*  pin, LPSTR  buffer);
static WINAPI NTSTATUS (*pRtlIpv4AddressToStringExA)(IN_ADDR*  pin, USHORT  port, LPSTR  buffer, PULONG  psize);
static WINAPI NTSTATUS (*pRtlIpv4AddressToStringExW)(IN_ADDR*  pin, USHORT  port, LPWSTR  buffer, PULONG  psize);
static WINAPI WCHAR* (*pRtlIpv4AddressToStringW)(IN_ADDR*  pin, LPWSTR  buffer);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressA)(char*  str, BOOLEAN  strict, char**  terminator, IN_ADDR*  address);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressExA)(char*  str, BOOLEAN  strict, IN_ADDR*  address, USHORT*  port);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressExW)(WCHAR*  str, BOOLEAN  strict, IN_ADDR*  address, USHORT*  port);
static WINAPI NTSTATUS (*pRtlIpv4StringToAddressW)(WCHAR*  str, BOOLEAN  strict, WCHAR**  terminator, IN_ADDR*  address);
static WINAPI NTSTATUS (*pRtlIpv6StringToAddressExW)(WCHAR*  str, IN6_ADDR*  address, ULONG*  scope, USHORT*  port);
static WINAPI BOOLEAN (*pRtlIsActivationContextActive)(HANDLE  handle);
static WINAPI BOOL (*pRtlIsCriticalSectionLocked)(RTL_CRITICAL_SECTION*  crit);
static WINAPI BOOL (*pRtlIsCriticalSectionLockedByThread)(RTL_CRITICAL_SECTION*  crit);
static WINAPI ULONG (*pRtlIsDosDeviceName_U)(PCWSTR  dos_name);
static WINAPI BOOLEAN (*pRtlIsNameLegalDOS8Dot3)(UNICODE_STRING*  unicode, OEM_STRING*  oem, BOOLEAN*  spaces);
static WINAPI BOOLEAN (*pRtlIsProcessorFeaturePresent)(UINT  feature);
static WINAPI BOOLEAN (*pRtlIsTextUnicode)(LPCVOID  buf, INT  len, INT*  pf);
static WINAPI BOOLEAN (*pRtlIsValidHandle)(RTL_HANDLE_TABLE*  HandleTable, RTL_HANDLE*  Handle);
static WINAPI BOOLEAN (*pRtlIsValidIndexHandle)(RTL_HANDLE_TABLE*  HandleTable, ULONG  Index, RTL_HANDLE**  ValidHandle);
static WINAPI NTSTATUS (*pRtlLargeIntegerToChar)(ULONGLONG*  value_ptr, ULONG  base, ULONG  length, PCHAR  str);
static WINAPI NTSTATUS (*pRtlLeaveCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI DWORD (*pRtlLengthRequiredSid)(DWORD  nrofsubauths);
static WINAPI ULONG (*pRtlLengthSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor);
static WINAPI DWORD (*pRtlLengthSid)(PSID  pSid);
static WINAPI NTSTATUS (*pRtlLocalTimeToSystemTime)(LARGE_INTEGER*  LocalTime, PLARGE_INTEGER  SystemTime);
static WINAPI BOOLEAN (*pRtlLockHeap)(HANDLE  heap);
static WINAPI NTSTATUS (*pRtlLookupAtomInAtomTable)(RTL_ATOM_TABLE  table, WCHAR*  name, RTL_ATOM*  atom);
static WINAPI PRUNTIME_FUNCTION (*pRtlLookupFunctionEntry)(ULONG_PTR  pc, ULONG_PTR*  base, UNWIND_HISTORY_TABLE*  table);
static WINAPI NTSTATUS (*pRtlMakeSelfRelativeSD)(PSECURITY_DESCRIPTOR  pAbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR  pSelfRelativeSecurityDescriptor, LPDWORD  lpdwBufferLength);
static WINAPI void (*pRtlMapGenericMask)(PACCESS_MASK  AccessMask, GENERIC_MAPPING*  GenericMapping);
static WINAPI void (*pRtlMoveMemory)(void*  Destination, void*  Source, SIZE_T  Length);
static WINAPI NTSTATUS (*pRtlMultiByteToUnicodeN)(LPWSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlMultiByteToUnicodeSize)(DWORD*  size, LPCSTR  str, UINT  len);
static WINAPI NTSTATUS (*pRtlNewSecurityObject)(PSECURITY_DESCRIPTOR  ParentDescriptor, PSECURITY_DESCRIPTOR  CreatorDescriptor, PSECURITY_DESCRIPTOR*  NewDescriptor, BOOLEAN  IsDirectoryObject, HANDLE  Token, PGENERIC_MAPPING  GenericMapping);
static WINAPI PRTL_USER_PROCESS_PARAMETERS (*pRtlNormalizeProcessParams)(RTL_USER_PROCESS_PARAMETERS*  params);
static WINAPI ULONG (*pRtlNtStatusToDosError)(NTSTATUS  status);
static WINAPI ULONG (*pRtlNtStatusToDosErrorNoTeb)(NTSTATUS  status);
static WINAPI ULONG (*pRtlNumberGenericTableElements)(PVOID  pTable);
static WINAPI ULONG (*pRtlNumberOfClearBits)(PCRTL_BITMAP  lpBits);
static WINAPI ULONG (*pRtlNumberOfSetBits)(PCRTL_BITMAP  lpBits);
static WINAPI UINT (*pRtlOemStringToUnicodeSize)(STRING*  str);
static WINAPI NTSTATUS (*pRtlOemStringToUnicodeString)(UNICODE_STRING*  uni, STRING*  oem, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlOemToUnicodeN)(LPWSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlOpenCurrentUser)(ACCESS_MASK  DesiredAccess, PHANDLE  KeyHandle);
static WINAPI PVOID (*pRtlPcToFileHeader)(PVOID  pc, PVOID*  address);
static WINAPI NTSTATUS (*pRtlPinAtomInAtomTable)(RTL_ATOM_TABLE  table, RTL_ATOM  atom);
static WINAPI void (*pRtlPopFrame)(TEB_ACTIVE_FRAME*  frame);
static WINAPI BOOLEAN (*pRtlPrefixString)(STRING*  s1, STRING*  s2, BOOLEAN  ignore_case);
static WINAPI BOOLEAN (*pRtlPrefixUnicodeString)(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  ignore_case);
static WINAPI void (*pRtlPushFrame)(TEB_ACTIVE_FRAME*  frame);
static WINAPI NTSTATUS (*pRtlQueryActivationContextApplicationSettings)(DWORD  flags, HANDLE  handle, WCHAR*  ns, WCHAR*  settings, WCHAR*  buffer, SIZE_T  size, SIZE_T*  written);
static WINAPI NTSTATUS (*pRtlQueryAtomInAtomTable)(RTL_ATOM_TABLE  table, RTL_ATOM  atom, ULONG*  ref, ULONG*  pin, WCHAR*  name, ULONG*  len);
static WINAPI WORD (*pRtlQueryDepthSList)(PSLIST_HEADER  list);
static WINAPI NTSTATUS (*pRtlQueryDynamicTimeZoneInformation)(RTL_DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo);
static WINAPI NTSTATUS (*pRtlQueryEnvironmentVariable_U)(PWSTR  env, PUNICODE_STRING  name, PUNICODE_STRING  value);
static WINAPI NTSTATUS (*pRtlQueryHeapInformation)(HANDLE  heap, HEAP_INFORMATION_CLASS  info_class, PVOID  info, SIZE_T  size_in, PSIZE_T  size_out);
static WINAPI NTSTATUS (*pRtlQueryInformationAcl)(PACL  pAcl, LPVOID  pAclInformation, DWORD  nAclInformationLength, ACL_INFORMATION_CLASS  dwAclInformationClass);
static WINAPI NTSTATUS (*pRtlQueryInformationActivationContext)(ULONG  flags, HANDLE  handle, PVOID  subinst, ULONG  class, PVOID  buffer, SIZE_T  bufsize, SIZE_T*  retlen);
static WINAPI NTSTATUS (*pRtlQueryPackageIdentity)(HANDLE  token, WCHAR*  fullname, SIZE_T*  fullname_size, WCHAR*  appid, SIZE_T*  appid_size, BOOLEAN*  packaged);
static WINAPI BOOL (*pRtlQueryPerformanceCounter)(LARGE_INTEGER*  counter);
static WINAPI BOOL (*pRtlQueryPerformanceFrequency)(LARGE_INTEGER*  frequency);
static WINAPI NTSTATUS (*pRtlQueryProcessDebugInformation)(ULONG  iProcessId, ULONG  iDebugInfoMask, PDEBUG_BUFFER  iBuf);
static WINAPI NTSTATUS (*pRtlQueryRegistryValues)(ULONG  RelativeTo, PCWSTR  Path, PRTL_QUERY_REGISTRY_TABLE  QueryTable, PVOID  Context, PVOID  Environment);
static WINAPI NTSTATUS (*pRtlQueryTimeZoneInformation)(RTL_TIME_ZONE_INFORMATION*  ret);
static WINAPI NTSTATUS (*pRtlQueryUnbiasedInterruptTime)(ULONGLONG*  time);
static WINAPI NTSTATUS (*pRtlQueueWorkItem)(PRTL_WORK_ITEM_ROUTINE  function, PVOID  context, ULONG  flags);
static WINAPI void (*pRtlRaiseStatus)(NTSTATUS  status);
static WINAPI ULONG (*pRtlRandom)(PULONG  seed);
static WINAPI ULONG (*pRtlRandomEx)(ULONG*  seed);
static WINAPI PVOID (*pRtlReAllocateHeap)(HANDLE  heap, ULONG  flags, PVOID  ptr, SIZE_T  size);
static WINAPI NTSTATUS (*pRtlRegisterWait)(PHANDLE  NewWaitObject, HANDLE  Object, RTL_WAITORTIMERCALLBACKFUNC  Callback, PVOID  Context, ULONG  Milliseconds, ULONG  Flags);
static WINAPI void (*pRtlReleaseActivationContext)(HANDLE  handle);
static WINAPI void (*pRtlReleasePebLock)(void);
static WINAPI void (*pRtlReleaseRelativeName)(RTL_RELATIVE_NAME*  relative);
static WINAPI void (*pRtlReleaseResource)(LPRTL_RWLOCK  rwl);
static WINAPI void (*pRtlReleaseSRWLockExclusive)(RTL_SRWLOCK*  lock);
static WINAPI void (*pRtlReleaseSRWLockShared)(RTL_SRWLOCK*  lock);
static WINAPI ULONG (*pRtlRemoveVectoredContinueHandler)(PVOID  handler);
static WINAPI ULONG (*pRtlRemoveVectoredExceptionHandler)(PVOID  handler);
static WINAPI void (*pRtlRestoreContext)(CONTEXT*  context, EXCEPTION_RECORD*  rec);
static WINAPI DWORD (*pRtlRunOnceBeginInitialize)(RTL_RUN_ONCE*  once, ULONG  flags, void**  context);
static WINAPI DWORD (*pRtlRunOnceComplete)(RTL_RUN_ONCE*  once, ULONG  flags, void*  context);
static WINAPI DWORD (*pRtlRunOnceExecuteOnce)(RTL_RUN_ONCE*  once, PRTL_RUN_ONCE_INIT_FN  func, void*  param, void**  context);
static WINAPI void (*pRtlRunOnceInitialize)(RTL_RUN_ONCE*  once);
static WINAPI void (*pRtlSecondsSince1970ToTime)(DWORD  Seconds, LARGE_INTEGER*  Time);
static WINAPI void (*pRtlSecondsSince1980ToTime)(DWORD  Seconds, LARGE_INTEGER*  Time);
static WINAPI NTSTATUS (*pRtlSelfRelativeToAbsoluteSD)(PSECURITY_DESCRIPTOR  pSelfRelativeSecurityDescriptor, PSECURITY_DESCRIPTOR  pAbsoluteSecurityDescriptor, LPDWORD  lpdwAbsoluteSecurityDescriptorSize, PACL  pDacl, LPDWORD  lpdwDaclSize, PACL  pSacl, LPDWORD  lpdwSaclSize, PSID  pOwner, LPDWORD  lpdwOwnerSize, PSID  pPrimaryGroup, LPDWORD  lpdwPrimaryGroupSize);
static WINAPI void (*pRtlSetAllBits)(PRTL_BITMAP  lpBits);
static WINAPI void (*pRtlSetBits)(PRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount);
static WINAPI NTSTATUS (*pRtlSetControlSecurityDescriptor)(PSECURITY_DESCRIPTOR  SecurityDescriptor, SECURITY_DESCRIPTOR_CONTROL  ControlBitsOfInterest, SECURITY_DESCRIPTOR_CONTROL  ControlBitsToSet);
static WINAPI ULONG (*pRtlSetCriticalSectionSpinCount)(RTL_CRITICAL_SECTION*  crit, ULONG  spincount);
static WINAPI NTSTATUS (*pRtlSetCurrentDirectory_U)(UNICODE_STRING*  dir);
static WINAPI void (*pRtlSetCurrentEnvironment)(PWSTR  new_env, PWSTR*  old_env);
static WINAPI BOOL (*pRtlSetCurrentTransaction)(HANDLE  new_transaction);
static WINAPI NTSTATUS (*pRtlSetDaclSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, BOOLEAN  daclpresent, PACL  dacl, BOOLEAN  dacldefaulted);
static WINAPI NTSTATUS (*pRtlSetEnvironmentVariable)(PWSTR*  penv, PUNICODE_STRING  name, PUNICODE_STRING  value);
static WINAPI NTSTATUS (*pRtlSetGroupSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID  group, BOOLEAN  groupdefaulted);
static WINAPI NTSTATUS (*pRtlSetHeapInformation)(HANDLE  heap, HEAP_INFORMATION_CLASS  info_class, PVOID  info, SIZE_T  size);
static WINAPI NTSTATUS (*pRtlSetIoCompletionCallback)(HANDLE  FileHandle, PRTL_OVERLAPPED_COMPLETION_ROUTINE  Function, ULONG  Flags);
static WINAPI void (*pRtlSetLastWin32Error)(DWORD  err);
static WINAPI void (*pRtlSetLastWin32ErrorAndNtStatusFromNtStatus)(NTSTATUS  status);
static WINAPI NTSTATUS (*pRtlSetOwnerSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID  owner, BOOLEAN  ownerdefaulted);
static WINAPI NTSTATUS (*pRtlSetSaclSecurityDescriptor)(PSECURITY_DESCRIPTOR  pSecurityDescriptor, BOOLEAN  saclpresent, PACL  sacl, BOOLEAN  sacldefaulted);
static WINAPI NTSTATUS (*pRtlSetThreadErrorMode)(DWORD  mode, LPDWORD  oldmode);
static WINAPI NTSTATUS (*pRtlSetTimeZoneInformation)(RTL_TIME_ZONE_INFORMATION*  tzinfo);
static WINAPI void (*pRtlSetUnhandledExceptionFilter)(PRTL_EXCEPTION_FILTER  filter);
static WINAPI SIZE_T (*pRtlSizeHeap)(HANDLE  heap, ULONG  flags, void*  ptr);
static WINAPI NTSTATUS (*pRtlSleepConditionVariableCS)(RTL_CONDITION_VARIABLE*  variable, RTL_CRITICAL_SECTION*  crit, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pRtlSleepConditionVariableSRW)(RTL_CONDITION_VARIABLE*  variable, RTL_SRWLOCK*  lock, LARGE_INTEGER*  timeout, ULONG  flags);
static WINAPI NTSTATUS (*pRtlStringFromGUID)(GUID*  guid, UNICODE_STRING*  str);
static WINAPI LPBYTE (*pRtlSubAuthorityCountSid)(PSID  pSid);
static WINAPI LPDWORD (*pRtlSubAuthoritySid)(PSID  pSid, DWORD  nSubAuthority);
static WINAPI NTSTATUS (*pRtlSystemTimeToLocalTime)(LARGE_INTEGER*  SystemTime, PLARGE_INTEGER  LocalTime);
static WINAPI BOOLEAN (*pRtlTimeFieldsToTime)(PTIME_FIELDS  tfTimeFields, PLARGE_INTEGER  Time);
static WINAPI void (*pRtlTimeToElapsedTimeFields)(LARGE_INTEGER*  Time, PTIME_FIELDS  TimeFields);
static WINAPI BOOLEAN (*pRtlTimeToSecondsSince1970)(LARGE_INTEGER*  Time, LPDWORD  Seconds);
static WINAPI BOOLEAN (*pRtlTimeToSecondsSince1980)(LARGE_INTEGER*  Time, LPDWORD  Seconds);
static WINAPI void (*pRtlTimeToTimeFields)(LARGE_INTEGER*  liTime, PTIME_FIELDS  TimeFields);
static WINAPI BOOLEAN (*pRtlTryAcquireSRWLockExclusive)(RTL_SRWLOCK*  lock);
static WINAPI BOOLEAN (*pRtlTryAcquireSRWLockShared)(RTL_SRWLOCK*  lock);
static WINAPI BOOL (*pRtlTryEnterCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI ULONGLONG (*pRtlUlonglongByteSwap)(ULONGLONG  i);
static WINAPI DWORD (*pRtlUnicodeStringToAnsiSize)(UNICODE_STRING*  str);
static WINAPI NTSTATUS (*pRtlUnicodeStringToAnsiString)(STRING*  ansi, UNICODE_STRING*  uni, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUnicodeStringToInteger)(UNICODE_STRING*  str, ULONG  base, ULONG*  value);
static WINAPI DWORD (*pRtlUnicodeStringToOemSize)(UNICODE_STRING*  str);
static WINAPI NTSTATUS (*pRtlUnicodeStringToOemString)(STRING*  oem, UNICODE_STRING*  uni, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUnicodeToMultiByteN)(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlUnicodeToMultiByteSize)(PULONG  size, LPCWSTR  str, ULONG  len);
static WINAPI NTSTATUS (*pRtlUnicodeToOemN)(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlUnicodeToUTF8N)(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen);
static WINAPI ULONG (*pRtlUniform)(PULONG  seed);
static WINAPI BOOLEAN (*pRtlUnlockHeap)(HANDLE  heap);
static WINAPI void (*pRtlUnwind)(void*  frame, void*  target_ip, EXCEPTION_RECORD*  rec, void*  retval);
static WINAPI void (*pRtlUnwindEx)(PVOID  end_frame, PVOID  target_ip, EXCEPTION_RECORD*  rec, PVOID  retval, CONTEXT*  context, UNWIND_HISTORY_TABLE*  table);
static WINAPI WCHAR (*pRtlUpcaseUnicodeChar)(WCHAR  wch);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeString)(UNICODE_STRING*  dest, UNICODE_STRING*  src, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToAnsiString)(STRING*  dst, UNICODE_STRING*  src, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToCountedOemString)(STRING*  oem, UNICODE_STRING*  uni, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeStringToOemString)(STRING*  dst, UNICODE_STRING*  src, BOOLEAN  doalloc);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeToMultiByteN)(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlUpcaseUnicodeToOemN)(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen);
static WINAPI NTSTATUS (*pRtlUpdateTimer)(HANDLE  TimerQueue, HANDLE  Timer, DWORD  DueTime, DWORD  Period);
static WINAPI CHAR (*pRtlUpperChar)(CHAR  ch);
static WINAPI void (*pRtlUpperString)(STRING*  dst, STRING*  src);
static WINAPI BOOLEAN (*pRtlValidAcl)(PACL  pAcl);
static WINAPI BOOLEAN (*pRtlValidRelativeSecurityDescriptor)(PSECURITY_DESCRIPTOR  descriptor, ULONG  length, SECURITY_INFORMATION  info);
static WINAPI NTSTATUS (*pRtlValidSecurityDescriptor)(PSECURITY_DESCRIPTOR  SecurityDescriptor);
static WINAPI BOOLEAN (*pRtlValidSid)(PSID  pSid);
static WINAPI BOOLEAN (*pRtlValidateHeap)(HANDLE  heap, ULONG  flags, LPCVOID  ptr);
static WINAPI NTSTATUS (*pRtlVerifyVersionInfo)(RTL_OSVERSIONINFOEXW*  info, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask);
static WINAPI PVOID (*pRtlVirtualUnwind)(ULONG  type, ULONG64  base, ULONG64  pc, RUNTIME_FUNCTION*  function, CONTEXT*  context, PVOID*  data, ULONG64*  frame_ret, KNONVOLATILE_CONTEXT_POINTERS*  ctx_ptr);
static WINAPI NTSTATUS (*pRtlWaitOnAddress)(void*  addr, void*  cmp, SIZE_T  size, LARGE_INTEGER*  timeout);
static WINAPI void (*pRtlWakeAddressAll)(void*  addr);
static WINAPI void (*pRtlWakeAddressSingle)(void*  addr);
static WINAPI void (*pRtlWakeAllConditionVariable)(RTL_CONDITION_VARIABLE*  variable);
static WINAPI void (*pRtlWakeConditionVariable)(RTL_CONDITION_VARIABLE*  variable);
static WINAPI NTSTATUS (*pRtlWalkHeap)(HANDLE  heap, PVOID  entry_ptr);
static WINAPI NTSTATUS (*pRtlWow64EnableFsRedirection)(BOOLEAN  enable);
static WINAPI NTSTATUS (*pRtlWow64EnableFsRedirectionEx)(ULONG  disable, ULONG*  old_value);
static WINAPI NTSTATUS (*pRtlWow64GetThreadContext)(HANDLE  handle, WOW64_CONTEXT*  context);
static WINAPI NTSTATUS (*pRtlWow64SetThreadContext)(HANDLE  handle, WOW64_CONTEXT*  context);
static WINAPI NTSTATUS (*pRtlWriteRegistryValue)(ULONG  RelativeTo, PCWSTR  path, PCWSTR  name, ULONG  type, PVOID  data, ULONG  length);
static WINAPI void (*pRtlZeroMemory)(void*  Destination, SIZE_T  Length);
static WINAPI NTSTATUS (*pRtlZombifyActivationContext)(HANDLE  handle);
static WINAPI NTSTATUS (*pRtlpNtCreateKey)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, PULONG  dispos);
static WINAPI NTSTATUS (*pRtlpNtEnumerateSubKey)(HANDLE  handle, UNICODE_STRING*  out, ULONG  index);
static WINAPI NTSTATUS (*pRtlpNtMakeTemporaryKey)(HANDLE  hkey);
static WINAPI NTSTATUS (*pRtlpNtOpenKey)(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr);
static WINAPI NTSTATUS (*pRtlpNtQueryValueKey)(HANDLE  handle, ULONG*  result_type, PBYTE  dest, DWORD*  result_len, void*  unknown);
static WINAPI NTSTATUS (*pRtlpNtSetValueKey)(HANDLE  hkey, ULONG  type, void*  data, ULONG  count);
static WINAPI NTSTATUS (*pRtlpUnWaitCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI NTSTATUS (*pRtlpWaitForCriticalSection)(RTL_CRITICAL_SECTION*  crit);
static WINAPI NTSTATUS (*pTpAllocCleanupGroup)(TP_CLEANUP_GROUP**  out);
static WINAPI NTSTATUS (*pTpAllocPool)(TP_POOL**  out, PVOID  reserved);
static WINAPI NTSTATUS (*pTpAllocTimer)(TP_TIMER**  out, PTP_TIMER_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI NTSTATUS (*pTpAllocWait)(TP_WAIT**  out, PTP_WAIT_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI NTSTATUS (*pTpAllocWork)(TP_WORK**  out, PTP_WORK_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI void (*pTpCallbackLeaveCriticalSectionOnCompletion)(TP_CALLBACK_INSTANCE*  instance, CRITICAL_SECTION*  crit);
static WINAPI NTSTATUS (*pTpCallbackMayRunLong)(TP_CALLBACK_INSTANCE*  instance);
static WINAPI void (*pTpCallbackReleaseMutexOnCompletion)(TP_CALLBACK_INSTANCE*  instance, HANDLE  mutex);
static WINAPI void (*pTpCallbackReleaseSemaphoreOnCompletion)(TP_CALLBACK_INSTANCE*  instance, HANDLE  semaphore, DWORD  count);
static WINAPI void (*pTpCallbackSetEventOnCompletion)(TP_CALLBACK_INSTANCE*  instance, HANDLE  event);
static WINAPI void (*pTpCallbackUnloadDllOnCompletion)(TP_CALLBACK_INSTANCE*  instance, HMODULE  module);
static WINAPI void (*pTpDisassociateCallback)(TP_CALLBACK_INSTANCE*  instance);
static WINAPI BOOL (*pTpIsTimerSet)(TP_TIMER*  timer);
static WINAPI void (*pTpPostWork)(TP_WORK*  work);
static WINAPI void (*pTpReleaseCleanupGroup)(TP_CLEANUP_GROUP*  group);
static WINAPI void (*pTpReleaseCleanupGroupMembers)(TP_CLEANUP_GROUP*  group, BOOL  cancel_pending, PVOID  userdata);
static WINAPI void (*pTpReleasePool)(TP_POOL*  pool);
static WINAPI void (*pTpReleaseTimer)(TP_TIMER*  timer);
static WINAPI void (*pTpReleaseWait)(TP_WAIT*  wait);
static WINAPI void (*pTpReleaseWork)(TP_WORK*  work);
static WINAPI void (*pTpSetPoolMaxThreads)(TP_POOL*  pool, DWORD  maximum);
static WINAPI BOOL (*pTpSetPoolMinThreads)(TP_POOL*  pool, DWORD  minimum);
static WINAPI void (*pTpSetTimer)(TP_TIMER*  timer, LARGE_INTEGER*  timeout, LONG  period, LONG  window_length);
static WINAPI void (*pTpSetWait)(TP_WAIT*  wait, HANDLE  handle, LARGE_INTEGER*  timeout);
static WINAPI NTSTATUS (*pTpSimpleTryPost)(PTP_SIMPLE_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment);
static WINAPI void (*pTpWaitForTimer)(TP_TIMER*  timer, BOOL  cancel_pending);
static WINAPI void (*pTpWaitForWait)(TP_WAIT*  wait, BOOL  cancel_pending);
static WINAPI void (*pTpWaitForWork)(TP_WORK*  work, BOOL  cancel_pending);
static WINAPI ULONGLONG (*pVerSetConditionMask)(ULONGLONG  dwlConditionMask, DWORD  dwTypeBitMask, BYTE  dwConditionMask);
static WINAPI NTSTATUS (*pWinSqmEndSession)(HANDLE  session);
static WINAPI void (*pWinSqmIncrementDWORD)(DWORD  unk1, DWORD  unk2, DWORD  unk3);
static WINAPI BOOL (*pWinSqmIsOptedIn)(void);
static WINAPI void (*pWinSqmSetDWORD)(HANDLE  session, DWORD  datapoint_id, DWORD  datapoint_value);
static WINAPI HANDLE (*pWinSqmStartSession)(GUID*  sessionguid, DWORD  sessionid, DWORD  unknown1);
static WINAPI EXCEPTION_DISPOSITION (*p__C_specific_handler)(EXCEPTION_RECORD*  rec, void*  frame, CONTEXT*  context, struct _DISPATCHER_CONTEXT*  dispatch);
static WINAPI int (*p__isascii)(int  c);
static WINAPI int (*p__iscsym)(int  c);
static WINAPI int (*p__iscsymf)(int  c);
static WINAPI int (*p__toascii)(int  c);
static WINAPI LONGLONG (*p_atoi64)(char*  str);
static WINAPI char* (*p_i64toa)(LONGLONG  value, char*  str, int  radix);
static WINAPI LPWSTR (*p_i64tow)(LONGLONG  value, LPWSTR  str, INT  radix);
static WINAPI char* (*p_itoa)(int  value, char*  str, int  radix);
static WINAPI LPWSTR (*p_itow)(int  value, LPWSTR  str, INT  radix);
static WINAPI void* (*p_lfind)(void*  key, void*  base, unsigned int*  nmemb, size_t  size, int (* compar) (void));
static WINAPI void (*p_local_unwind)(void*  frame, void*  target_ip);
static WINAPI char* (*p_ltoa)(LONG  value, char*  str, int  radix);
static WINAPI LPWSTR (*p_ltow)(LONG  value, LPWSTR  str, INT  radix);
static WINAPI void* (*p_memccpy)(void*  dst, void*  src, int  c, size_t  n);
static WINAPI INT (*p_memicmp)(LPCSTR  s1, LPCSTR  s2, DWORD  len);
static WINAPI int (*p_snprintf)(char*  str, SIZE_T  len, char*  format);
static WINAPI int (*p_snprintf_s)(char*  str, SIZE_T  size, SIZE_T  len, char*  format);
static WINAPI int (*p_snwprintf)(WCHAR*  str, SIZE_T  len, WCHAR*  format);
static WINAPI void (*p_splitpath)(char*  inpath, char*  drv, char*  dir, char*  fname, char*  ext);
static WINAPI int (*p_stricmp)(LPCSTR  str1, LPCSTR  str2);
static WINAPI LPSTR (*p_strlwr)(LPSTR  str);
static WINAPI int (*p_strnicmp)(LPCSTR  str1, LPCSTR  str2, size_t  n);
static WINAPI LPSTR (*p_strupr)(LPSTR  str);
static WINAPI int (*p_tolower)(int  c);
static WINAPI int (*p_toupper)(int  c);
static WINAPI char* (*p_ui64toa)(ULONGLONG  value, char*  str, int  radix);
static WINAPI LPWSTR (*p_ui64tow)(ULONGLONG  value, LPWSTR  str, INT  radix);
static WINAPI char* (*p_ultoa)(ULONG  value, char*  str, int  radix);
static WINAPI LPWSTR (*p_ultow)(ULONG  value, LPWSTR  str, INT  radix);
static WINAPI int (*p_vsnprintf)(char*  str, SIZE_T  len, char*  format, __builtin_ms_va_list  args);
static WINAPI int (*p_vsnprintf_s)(char*  str, SIZE_T  size, SIZE_T  len, char*  format, __builtin_ms_va_list  args);
static WINAPI int (*p_vsnwprintf)(WCHAR*  str, SIZE_T  len, WCHAR*  format, __builtin_ms_va_list  args);
static WINAPI INT (*p_wcsicmp)(LPCWSTR  str1, LPCWSTR  str2);
static WINAPI LPWSTR (*p_wcslwr)(LPWSTR  str);
static WINAPI INT (*p_wcsnicmp)(LPCWSTR  str1, LPCWSTR  str2, INT  n);
static WINAPI LPWSTR (*p_wcsupr)(LPWSTR  str);
static WINAPI int (*p_wtoi)(LPCWSTR  str);
static WINAPI LONGLONG (*p_wtoi64)(LPCWSTR  str);
static WINAPI LONG (*p_wtol)(LPCWSTR  str);
static WINAPI int (*pabs)(int  i);
static WINAPI double (*patan)(double  d);
static WINAPI int (*patoi)(char*  nptr);
static WINAPI LONG (*patol)(char*  nptr);
static WINAPI void* (*pbsearch)(void*  key, void*  base, size_t  nmemb, size_t  size, int (* compar) (void));
static WINAPI double (*pceil)(double  d);
static WINAPI double (*pcos)(double  d);
static WINAPI double (*pfabs)(double  d);
static WINAPI double (*pfloor)(double  d);
static WINAPI int (*pisalnum)(int  c);
static WINAPI int (*pisalpha)(int  c);
static WINAPI int (*piscntrl)(int  c);
static WINAPI int (*pisdigit)(int  c);
static WINAPI int (*pisgraph)(int  c);
static WINAPI int (*pislower)(int  c);
static WINAPI int (*pisprint)(int  c);
static WINAPI int (*pispunct)(int  c);
static WINAPI int (*pisspace)(int  c);
static WINAPI int (*pisupper)(int  c);
static WINAPI INT (*piswalpha)(WCHAR  wc);
static WINAPI INT (*piswctype)(WCHAR  wc, WCHAR  wct);
static WINAPI INT (*piswdigit)(WCHAR  wc);
static WINAPI INT (*piswlower)(WCHAR  wc);
static WINAPI INT (*piswspace)(WCHAR  wc);
static WINAPI INT (*piswxdigit)(WCHAR  wc);
static WINAPI int (*pisxdigit)(int  c);
static WINAPI LONG (*plabs)(LONG  i);
static WINAPI double (*plog)(double  d);
static WINAPI INT (*pmbstowcs)(LPWSTR  dst, LPCSTR  src, INT  n);
static WINAPI void* (*pmemchr)(void*  ptr, int  c, size_t  n);
static WINAPI int (*pmemcmp)(void*  ptr1, void*  ptr2, size_t  n);
static WINAPI void* (*pmemcpy)(void*  dst, void*  src, size_t  n);
static WINAPI void* (*pmemmove)(void*  dst, void*  src, size_t  n);
static WINAPI void* (*pmemset)(void*  dst, int  c, size_t  n);
static WINAPI double (*ppow)(double  x, double  y);
static WINAPI void (*pqsort)(void*  base, size_t  nmemb, size_t  size, int (* compar) (void));
static WINAPI double (*psin)(double  d);
static WINAPI int (*psprintf)(char*  str, char*  format);
static WINAPI double (*psqrt)(double  d);
static WINAPI int (*psscanf)(char*  str, char*  format);
static WINAPI char* (*pstrcat)(char*  dst, char*  src);
static WINAPI char* (*pstrchr)(char*  str, int  c);
static WINAPI int (*pstrcmp)(char*  str1, char*  str2);
static WINAPI char* (*pstrcpy)(char*  dst, char*  src);
static WINAPI size_t (*pstrcspn)(char*  str, char*  reject);
static WINAPI size_t (*pstrlen)(char*  str);
static WINAPI char* (*pstrncat)(char*  dst, char*  src, size_t  len);
static WINAPI int (*pstrncmp)(char*  str1, char*  str2, size_t  len);
static WINAPI char* (*pstrncpy)(char*  dst, char*  src, size_t  len);
static WINAPI size_t (*pstrnlen)(char*  str, size_t  len);
static WINAPI char* (*pstrpbrk)(char*  str, char*  accept);
static WINAPI char* (*pstrrchr)(char*  str, int  c);
static WINAPI size_t (*pstrspn)(char*  str, char*  accept);
static WINAPI char* (*pstrstr)(char*  haystack, char*  needle);
static WINAPI LONG (*pstrtol)(char*  nptr, char**  endptr, int  base);
static WINAPI ULONG (*pstrtoul)(char*  nptr, char**  endptr, int  base);
static WINAPI int (*pswprintf)(WCHAR*  str, WCHAR*  format);
static WINAPI double (*ptan)(double  d);
static WINAPI int (*ptolower)(int  c);
static WINAPI int (*ptoupper)(int  c);
static WINAPI WCHAR (*ptowlower)(WCHAR  ch);
static WINAPI WCHAR (*ptowupper)(WCHAR  ch);
static WINAPI NTSTATUS (*pvDbgPrintEx)(ULONG  id, ULONG  level, LPCSTR  fmt, __builtin_ms_va_list  args);
static WINAPI NTSTATUS (*pvDbgPrintExWithPrefix)(LPCSTR  prefix, ULONG  id, ULONG  level, LPCSTR  fmt, __builtin_ms_va_list  args);
static WINAPI int (*pvsprintf)(char*  str, char*  format, __builtin_ms_va_list  args);
static WINAPI LPWSTR (*pwcscat)(LPWSTR  dst, LPCWSTR  src);
static WINAPI LPWSTR (*pwcschr)(LPCWSTR  str, WCHAR  ch);
static WINAPI INT (*pwcscmp)(LPCWSTR  str1, LPCWSTR  str2);
static WINAPI LPWSTR (*pwcscpy)(LPWSTR  dst, LPCWSTR  src);
static WINAPI INT (*pwcscspn)(LPCWSTR  str, LPCWSTR  reject);
static WINAPI INT (*pwcslen)(LPCWSTR  str);
static WINAPI LPWSTR (*pwcsncat)(LPWSTR  s1, LPCWSTR  s2, INT  n);
static WINAPI INT (*pwcsncmp)(LPCWSTR  str1, LPCWSTR  str2, INT  n);
static WINAPI LPWSTR (*pwcsncpy)(LPWSTR  s1, LPCWSTR  s2, INT  n);
static WINAPI LPWSTR (*pwcspbrk)(LPCWSTR  str, LPCWSTR  accept);
static WINAPI LPWSTR (*pwcsrchr)(LPWSTR  str, WCHAR  ch);
static WINAPI INT (*pwcsspn)(LPCWSTR  str, LPCWSTR  accept);
static WINAPI LPWSTR (*pwcsstr)(LPCWSTR  str, LPCWSTR  sub);
static WINAPI LPWSTR (*pwcstok)(LPWSTR  str, LPCWSTR  delim);
static WINAPI LONG (*pwcstol)(LPCWSTR  s, LPWSTR*  end, INT  base);
static WINAPI INT (*pwcstombs)(LPSTR  dst, LPCWSTR  src, INT  n);
static WINAPI ULONG (*pwcstoul)(LPCWSTR  s, LPWSTR*  end, INT  base);
static WINAPI unsigned int (*pwine_server_call)(void*  req_ptr);
static WINAPI int (*pwine_server_fd_to_handle)(int  fd, unsigned int  access, unsigned int  attributes, HANDLE*  handle);
static WINAPI int (*pwine_server_handle_to_fd)(HANDLE  handle, unsigned int  access, int*  unix_fd, unsigned int*  options);
static WINAPI void (*pwine_server_release_fd)(HANDLE  handle, int  unix_fd);
static WINAPI void (*pwine_server_send_fd)(int  fd);
static WINAPI HANDLE (*p__wine_make_process_system)(void);
static WINAPI unsigned char (*p__wine_dbg_get_channel_flags)(struct __wine_debug_channel*  channel);
static WINAPI int (*p__wine_dbg_header)(enum __wine_debug_class  cls, struct __wine_debug_channel*  channel, char*  function);
static WINAPI int (*p__wine_dbg_output)(char*  str);
static WINAPI char* (*p__wine_dbg_strdup)(char*  str);
static WINAPI ssize_t (*p__wine_locked_recvmsg)(int  fd, struct msghdr*  hdr, int  flags);
static WINAPI char* (*pwine_get_version)(void);
static WINAPI char* (*pwine_get_build_id)(void);
static WINAPI void (*pwine_get_host_version)(char**  sysname, char**  release);
static WINAPI void (*p__wine_init_codepages)(union cptable*  ansi, union cptable*  oem, union cptable*  ucp);
static WINAPI int (*p__wine_set_signal_handler)(unsigned int  sig, wine_signal_handler  wsh);
static WINAPI NTSTATUS (*pwine_nt_to_unix_file_name)(UNICODE_STRING*  nameW, ANSI_STRING*  unix_name_ret, UINT  disposition, BOOLEAN  check_case);
static WINAPI NTSTATUS (*pwine_unix_to_nt_file_name)(ANSI_STRING*  name, UNICODE_STRING*  nt);

WINAPI void wine32b_ntdll_A_SHAFinal(PSHA_CTX  Context, PULONG  Result) /* ../dlls/ntdll/crypt.c:180 */
{
	TRACE("Enter A_SHAFinal\n");
	pA_SHAFinal(Context, Result);
	TRACE("Leave A_SHAFinal\n");
}

extern WINAPI void wine32a_ntdll_A_SHAFinal(void);  /* ../dlls/ntdll/crypt.c:180 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_A_SHAFinal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_A_SHAFinal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_A_SHAInit(PSHA_CTX  Context) /* ../dlls/ntdll/crypt.c:113 */
{
	TRACE("Enter A_SHAInit\n");
	pA_SHAInit(Context);
	TRACE("Leave A_SHAInit\n");
}

extern WINAPI void wine32a_ntdll_A_SHAInit(void);  /* ../dlls/ntdll/crypt.c:113 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_A_SHAInit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_A_SHAInit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_A_SHAUpdate(PSHA_CTX  Context, unsigned char*  Buffer, UINT  BufferSize) /* ../dlls/ntdll/crypt.c:138 */
{
	TRACE("Enter A_SHAUpdate\n");
	pA_SHAUpdate(Context, Buffer, BufferSize);
	TRACE("Leave A_SHAUpdate\n");
}

extern WINAPI void wine32a_ntdll_A_SHAUpdate(void);  /* ../dlls/ntdll/crypt.c:138 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_A_SHAUpdate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_A_SHAUpdate") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_ApiSetQueryApiSetPresence(UNICODE_STRING*  namespace, BOOLEAN*  present) /* ../dlls/ntdll/misc.c:612 */
{
	BOOL return_value;
	TRACE("Enter ApiSetQueryApiSetPresence\n");
	return_value = pApiSetQueryApiSetPresence(namespace, present);
	TRACE("Leave ApiSetQueryApiSetPresence\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_ApiSetQueryApiSetPresence(void);  /* ../dlls/ntdll/misc.c:612 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_ApiSetQueryApiSetPresence,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_ApiSetQueryApiSetPresence") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_DbgPrint(LPCSTR  fmt) /* ../dlls/ntdll/rtl.c:303 */
{
	NTSTATUS return_value;
	TRACE("Enter DbgPrint\n");
	return_value = pDbgPrint(fmt);
	TRACE("Leave DbgPrint\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_DbgPrint(void);  /* ../dlls/ntdll/rtl.c:303 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_DbgPrint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_DbgPrint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_DbgPrintEx(ULONG  iComponentId, ULONG  Level, LPCSTR  fmt) /* ../dlls/ntdll/rtl.c:321 */
{
	NTSTATUS return_value;
	TRACE("Enter DbgPrintEx\n");
	return_value = pDbgPrintEx(iComponentId, Level, fmt);
	TRACE("Leave DbgPrintEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_DbgPrintEx(void);  /* ../dlls/ntdll/rtl.c:321 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_DbgPrintEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_DbgPrintEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_DbgUiIssueRemoteBreakin(HANDLE  process) /* ../dlls/ntdll/process.c:1382 */
{
	NTSTATUS return_value;
	TRACE("Enter DbgUiIssueRemoteBreakin\n");
	return_value = pDbgUiIssueRemoteBreakin(process);
	TRACE("Leave DbgUiIssueRemoteBreakin\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_DbgUiIssueRemoteBreakin(void);  /* ../dlls/ntdll/process.c:1382 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_DbgUiIssueRemoteBreakin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_DbgUiIssueRemoteBreakin") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_DbgUiRemoteBreakin(void*  arg) /* ../dlls/ntdll/process.c:1372 */
{
	TRACE("Enter DbgUiRemoteBreakin\n");
	pDbgUiRemoteBreakin(arg);
	TRACE("Leave DbgUiRemoteBreakin\n");
}

extern WINAPI void wine32a_ntdll_DbgUiRemoteBreakin(void);  /* ../dlls/ntdll/process.c:1372 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_DbgUiRemoteBreakin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_DbgUiRemoteBreakin") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventActivityIdControl(ULONG  code, GUID*  guid) /* ../dlls/ntdll/misc.c:381 */
{
	ULONG return_value;
	TRACE("Enter EtwEventActivityIdControl\n");
	return_value = pEtwEventActivityIdControl(code, guid);
	TRACE("Leave EtwEventActivityIdControl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventActivityIdControl(void);  /* ../dlls/ntdll/misc.c:381 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventActivityIdControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventActivityIdControl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_EtwEventEnabled(REGHANDLE  handle, EVENT_DESCRIPTOR*  descriptor) /* ../dlls/ntdll/misc.c:521 */
{
	BOOLEAN return_value;
	TRACE("Enter EtwEventEnabled\n");
	return_value = pEtwEventEnabled(handle, descriptor);
	TRACE("Leave EtwEventEnabled\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventEnabled(void);  /* ../dlls/ntdll/misc.c:521 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_EtwEventProviderEnabled(REGHANDLE  handle, UCHAR  level, ULONGLONG  keyword) /* ../dlls/ntdll/misc.c:392 */
{
	BOOLEAN return_value;
	TRACE("Enter EtwEventProviderEnabled\n");
	return_value = pEtwEventProviderEnabled(handle, level, keyword);
	TRACE("Leave EtwEventProviderEnabled\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventProviderEnabled(void);  /* ../dlls/ntdll/misc.c:392 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventProviderEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventProviderEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventRegister(LPCGUID  provider, PENABLECALLBACK  callback, PVOID  context, PREGHANDLE  handle) /* ../dlls/ntdll/misc.c:401 */
{
	ULONG return_value;
	TRACE("Enter EtwEventRegister\n");
	return_value = pEtwEventRegister(provider, callback, context, handle);
	TRACE("Leave EtwEventRegister\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventRegister(void);  /* ../dlls/ntdll/misc.c:401 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventRegister,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventRegister") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventSetInformation(REGHANDLE  handle, EVENT_INFO_CLASS  class, void*  info, ULONG  length) /* ../dlls/ntdll/misc.c:422 */
{
	ULONG return_value;
	TRACE("Enter EtwEventSetInformation\n");
	return_value = pEtwEventSetInformation(handle, class, info, length);
	TRACE("Leave EtwEventSetInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventSetInformation(void);  /* ../dlls/ntdll/misc.c:422 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventSetInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventSetInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventUnregister(REGHANDLE  handle) /* ../dlls/ntdll/misc.c:413 */
{
	ULONG return_value;
	TRACE("Enter EtwEventUnregister\n");
	return_value = pEtwEventUnregister(handle);
	TRACE("Leave EtwEventUnregister\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventUnregister(void);  /* ../dlls/ntdll/misc.c:413 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventUnregister,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventUnregister") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventWrite(REGHANDLE  handle, EVENT_DESCRIPTOR*  descriptor, ULONG  count, EVENT_DATA_DESCRIPTOR*  data) /* ../dlls/ntdll/misc.c:530 */
{
	ULONG return_value;
	TRACE("Enter EtwEventWrite\n");
	return_value = pEtwEventWrite(handle, descriptor, count, data);
	TRACE("Leave EtwEventWrite\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventWrite(void);  /* ../dlls/ntdll/misc.c:530 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventWrite,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventWrite") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventWriteString(REGHANDLE  handle, UCHAR  level, ULONGLONG  keyword, PCWSTR  string) /* ../dlls/ntdll/misc.c:432 */
{
	ULONG return_value;
	TRACE("Enter EtwEventWriteString\n");
	return_value = pEtwEventWriteString(handle, level, keyword, string);
	TRACE("Leave EtwEventWriteString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventWriteString(void);  /* ../dlls/ntdll/misc.c:432 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventWriteString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventWriteString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwEventWriteTransfer(REGHANDLE  handle, PCEVENT_DESCRIPTOR  descriptor, LPCGUID  activity, LPCGUID  related, ULONG  count, PEVENT_DATA_DESCRIPTOR  data) /* ../dlls/ntdll/misc.c:442 */
{
	ULONG return_value;
	TRACE("Enter EtwEventWriteTransfer\n");
	return_value = pEtwEventWriteTransfer(handle, descriptor, activity, related, count, data);
	TRACE("Leave EtwEventWriteTransfer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwEventWriteTransfer(void);  /* ../dlls/ntdll/misc.c:442 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwEventWriteTransfer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwEventWriteTransfer") "\n"
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

WINAPI ULONG wine32b_ntdll_EtwGetTraceEnableFlags(TRACEHANDLE  handle) /* ../dlls/ntdll/misc.c:540 */
{
	ULONG return_value;
	TRACE("Enter EtwGetTraceEnableFlags\n");
	return_value = pEtwGetTraceEnableFlags(handle);
	TRACE("Leave EtwGetTraceEnableFlags\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwGetTraceEnableFlags(void);  /* ../dlls/ntdll/misc.c:540 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwGetTraceEnableFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwGetTraceEnableFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI UCHAR wine32b_ntdll_EtwGetTraceEnableLevel(TRACEHANDLE  handle) /* ../dlls/ntdll/misc.c:549 */
{
	UCHAR return_value;
	TRACE("Enter EtwGetTraceEnableLevel\n");
	return_value = pEtwGetTraceEnableLevel(handle);
	TRACE("Leave EtwGetTraceEnableLevel\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwGetTraceEnableLevel(void);  /* ../dlls/ntdll/misc.c:549 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwGetTraceEnableLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwGetTraceEnableLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI TRACEHANDLE wine32b_ntdll_EtwGetTraceLoggerHandle(PVOID  buf) /* ../dlls/ntdll/misc.c:558 */
{
	TRACEHANDLE return_value;
	TRACE("Enter EtwGetTraceLoggerHandle\n");
	return_value = pEtwGetTraceLoggerHandle(buf);
	TRACE("Leave EtwGetTraceLoggerHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwGetTraceLoggerHandle(void);  /* ../dlls/ntdll/misc.c:558 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwGetTraceLoggerHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwGetTraceLoggerHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwLogTraceEvent(TRACEHANDLE  SessionHandle, PEVENT_TRACE_HEADER  EventTrace) /* ../dlls/ntdll/misc.c:567 */
{
	ULONG return_value;
	TRACE("Enter EtwLogTraceEvent\n");
	return_value = pEtwLogTraceEvent(SessionHandle, EventTrace);
	TRACE("Leave EtwLogTraceEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwLogTraceEvent(void);  /* ../dlls/ntdll/misc.c:567 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwLogTraceEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwLogTraceEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwRegisterTraceGuidsA(WMIDPREQUEST  RequestAddress, void*  RequestContext, GUID*  ControlGuid, ULONG  GuidCount, TRACE_GUID_REGISTRATION*  TraceGuidReg, char*  MofImagePath, char*  MofResourceName, TRACEHANDLE*  RegistrationHandle) /* ../dlls/ntdll/misc.c:495 */
{
	ULONG return_value;
	TRACE("Enter EtwRegisterTraceGuidsA\n");
	return_value = pEtwRegisterTraceGuidsA(RequestAddress, RequestContext, ControlGuid, GuidCount, TraceGuidReg, MofImagePath, MofResourceName, RegistrationHandle);
	TRACE("Leave EtwRegisterTraceGuidsA\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwRegisterTraceGuidsA(void);  /* ../dlls/ntdll/misc.c:495 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwRegisterTraceGuidsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwRegisterTraceGuidsA") "\n"
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

WINAPI ULONG wine32b_ntdll_EtwRegisterTraceGuidsW(WMIDPREQUEST  RequestAddress, void*  RequestContext, GUID*  ControlGuid, ULONG  GuidCount, TRACE_GUID_REGISTRATION*  TraceGuidReg, WCHAR*  MofImagePath, WCHAR*  MofResourceName, TRACEHANDLE*  RegistrationHandle) /* ../dlls/ntdll/misc.c:470 */
{
	ULONG return_value;
	TRACE("Enter EtwRegisterTraceGuidsW\n");
	return_value = pEtwRegisterTraceGuidsW(RequestAddress, RequestContext, ControlGuid, GuidCount, TraceGuidReg, MofImagePath, MofResourceName, RegistrationHandle);
	TRACE("Leave EtwRegisterTraceGuidsW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwRegisterTraceGuidsW(void);  /* ../dlls/ntdll/misc.c:470 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwRegisterTraceGuidsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwRegisterTraceGuidsW") "\n"
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

WINAPI ULONG wine32b_ntdll_EtwTraceMessage(TRACEHANDLE  handle, ULONG  flags, LPGUID  guid, USHORT  number) /* ../dlls/ntdll/misc.c:586 */
{
	ULONG return_value;
	TRACE("Enter EtwTraceMessage\n");
	return_value = pEtwTraceMessage(handle, flags, guid, number);
	TRACE("Leave EtwTraceMessage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwTraceMessage(void);  /* ../dlls/ntdll/misc.c:586 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwTraceMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwTraceMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwTraceMessageVa(TRACEHANDLE  handle, ULONG  flags, LPGUID  guid, USHORT  number, __builtin_ms_va_list  args) /* ../dlls/ntdll/misc.c:576 */
{
	ULONG return_value;
	TRACE("Enter EtwTraceMessageVa\n");
	return_value = pEtwTraceMessageVa(handle, flags, guid, number, args);
	TRACE("Leave EtwTraceMessageVa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwTraceMessageVa(void);  /* ../dlls/ntdll/misc.c:576 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwTraceMessageVa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwTraceMessageVa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_EtwUnregisterTraceGuids(TRACEHANDLE  RegistrationHandle) /* ../dlls/ntdll/misc.c:509 */
{
	ULONG return_value;
	TRACE("Enter EtwUnregisterTraceGuids\n");
	return_value = pEtwUnregisterTraceGuids(RegistrationHandle);
	TRACE("Leave EtwUnregisterTraceGuids\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_EtwUnregisterTraceGuids(void);  /* ../dlls/ntdll/misc.c:509 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_EtwUnregisterTraceGuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_EtwUnregisterTraceGuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrAccessResource(HMODULE  hmod, IMAGE_RESOURCE_DATA_ENTRY*  entry, void**  ptr, ULONG*  size) /* ../dlls/ntdll/resource.c:378 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrAccessResource\n");
	return_value = pLdrAccessResource(hmod, entry, ptr, size);
	TRACE("Leave LdrAccessResource\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrAccessResource(void);  /* ../dlls/ntdll/resource.c:378 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrAccessResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrAccessResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrAddRefDll(ULONG  flags, HMODULE  module) /* ../dlls/ntdll/loader.c:3163 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrAddRefDll\n");
	return_value = pLdrAddRefDll(flags, module);
	TRACE("Leave LdrAddRefDll\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrAddRefDll(void);  /* ../dlls/ntdll/loader.c:3163 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrAddRefDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrAddRefDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrDisableThreadCalloutsForDll(HMODULE  hModule) /* ../dlls/ntdll/loader.c:1688 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrDisableThreadCalloutsForDll\n");
	return_value = pLdrDisableThreadCalloutsForDll(hModule);
	TRACE("Leave LdrDisableThreadCalloutsForDll\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrDisableThreadCalloutsForDll(void);  /* ../dlls/ntdll/loader.c:1688 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrDisableThreadCalloutsForDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrDisableThreadCalloutsForDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrEnumerateLoadedModules(void*  unknown, LDRENUMPROC  callback, void*  context) /* ../dlls/ntdll/loader.c:1733 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrEnumerateLoadedModules\n");
	return_value = pLdrEnumerateLoadedModules(unknown, callback, context);
	TRACE("Leave LdrEnumerateLoadedModules\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrEnumerateLoadedModules(void);  /* ../dlls/ntdll/loader.c:1733 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrEnumerateLoadedModules,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrEnumerateLoadedModules") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrFindEntryForAddress(void*  addr, PLDR_MODULE*  pmod) /* ../dlls/ntdll/loader.c:1711 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrFindEntryForAddress\n");
	return_value = pLdrFindEntryForAddress(addr, pmod);
	TRACE("Leave LdrFindEntryForAddress\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrFindEntryForAddress(void);  /* ../dlls/ntdll/loader.c:1711 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrFindEntryForAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrFindEntryForAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrFindResourceDirectory_U(HMODULE  hmod, LDR_RESOURCE_INFO*  info, ULONG  level, IMAGE_RESOURCE_DIRECTORY**  dir) /* ../dlls/ntdll/resource.c:263 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrFindResourceDirectory_U\n");
	return_value = pLdrFindResourceDirectory_U(hmod, info, level, dir);
	TRACE("Leave LdrFindResourceDirectory_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrFindResourceDirectory_U(void);  /* ../dlls/ntdll/resource.c:263 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrFindResourceDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrFindResourceDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrFindResource_U(HMODULE  hmod, LDR_RESOURCE_INFO*  info, ULONG  level, IMAGE_RESOURCE_DATA_ENTRY**  entry) /* ../dlls/ntdll/resource.c:291 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrFindResource_U\n");
	return_value = pLdrFindResource_U(hmod, info, level, entry);
	TRACE("Leave LdrFindResource_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrFindResource_U(void);  /* ../dlls/ntdll/resource.c:291 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrFindResource_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrFindResource_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrGetDllHandle(LPCWSTR  load_path, ULONG  flags, UNICODE_STRING*  name, HMODULE*  base) /* ../dlls/ntdll/loader.c:3131 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrGetDllHandle\n");
	return_value = pLdrGetDllHandle(load_path, flags, name, base);
	TRACE("Leave LdrGetDllHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrGetDllHandle(void);  /* ../dlls/ntdll/loader.c:3131 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrGetDllHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrGetDllHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrGetProcedureAddress(HMODULE  module, ANSI_STRING*  name, ULONG  ord, PVOID*  address) /* ../dlls/ntdll/loader.c:1858 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrGetProcedureAddress\n");
	return_value = pLdrGetProcedureAddress(module, name, ord, address);
	TRACE("Leave LdrGetProcedureAddress\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrGetProcedureAddress(void);  /* ../dlls/ntdll/loader.c:1858 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrGetProcedureAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrGetProcedureAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_LdrInitializeThunk(CONTEXT*  context, void**  entry, ULONG_PTR  unknown3, ULONG_PTR  unknown4) /* ../dlls/ntdll/loader.c:3755 */
{
	TRACE("Enter LdrInitializeThunk\n");
	pLdrInitializeThunk(context, entry, unknown3, unknown4);
	TRACE("Leave LdrInitializeThunk\n");
}

extern WINAPI void wine32a_ntdll_LdrInitializeThunk(void);  /* ../dlls/ntdll/loader.c:3755 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrInitializeThunk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrInitializeThunk") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrLoadDll(LPCWSTR  path_name, DWORD  flags, UNICODE_STRING*  libname, HMODULE*  hModule) /* ../dlls/ntdll/loader.c:3101 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrLoadDll\n");
	return_value = pLdrLoadDll(path_name, flags, libname, hModule);
	TRACE("Leave LdrLoadDll\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrLoadDll(void);  /* ../dlls/ntdll/loader.c:3101 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrLoadDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrLoadDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrLockLoaderLock(ULONG  flags, ULONG*  result, ULONG_PTR*  magic) /* ../dlls/ntdll/loader.c:1812 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrLockLoaderLock\n");
	return_value = pLdrLockLoaderLock(flags, result, magic);
	TRACE("Leave LdrLockLoaderLock\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrLockLoaderLock(void);  /* ../dlls/ntdll/loader.c:1812 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrLockLoaderLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrLockLoaderLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI IMAGE_BASE_RELOCATION* wine32b_ntdll_LdrProcessRelocationBlock(void*  page, UINT  count, USHORT*  relocs, INT_PTR  delta) /* ../dlls/ntdll/loader.c:3192 */
{
	IMAGE_BASE_RELOCATION* return_value;
	TRACE("Enter LdrProcessRelocationBlock\n");
	return_value = pLdrProcessRelocationBlock(page, count, relocs, delta);
	TRACE("Leave LdrProcessRelocationBlock\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrProcessRelocationBlock(void);  /* ../dlls/ntdll/loader.c:3192 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrProcessRelocationBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrProcessRelocationBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrQueryImageFileExecutionOptions(UNICODE_STRING*  key, LPCWSTR  value, ULONG  type, void*  data, ULONG  in_size, ULONG*  out_size) /* ../dlls/ntdll/loader.c:3371 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrQueryImageFileExecutionOptions\n");
	return_value = pLdrQueryImageFileExecutionOptions(key, value, type, data, in_size, out_size);
	TRACE("Leave LdrQueryImageFileExecutionOptions\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrQueryImageFileExecutionOptions(void);  /* ../dlls/ntdll/loader.c:3371 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrQueryImageFileExecutionOptions,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrQueryImageFileExecutionOptions") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_LdrQueryProcessModuleInformation(PSYSTEM_MODULE_INFORMATION  smi, ULONG  buf_size, ULONG*  req_size) /* ../dlls/ntdll/loader.c:3269 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrQueryProcessModuleInformation\n");
	return_value = pLdrQueryProcessModuleInformation(smi, buf_size, req_size);
	TRACE("Leave LdrQueryProcessModuleInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrQueryProcessModuleInformation(void);  /* ../dlls/ntdll/loader.c:3269 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrQueryProcessModuleInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrQueryProcessModuleInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrRegisterDllNotification(ULONG  flags, PLDR_DLL_NOTIFICATION_FUNCTION  callback, void*  context, void**  cookie) /* ../dlls/ntdll/loader.c:1761 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrRegisterDllNotification\n");
	return_value = pLdrRegisterDllNotification(flags, callback, context, cookie);
	TRACE("Leave LdrRegisterDllNotification\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrRegisterDllNotification(void);  /* ../dlls/ntdll/loader.c:1761 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrRegisterDllNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrRegisterDllNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_LdrResolveDelayLoadedAPI(void*  base, IMAGE_DELAYLOAD_DESCRIPTOR*  desc, PDELAYLOAD_FAILURE_DLL_CALLBACK  dllhook, PDELAYLOAD_FAILURE_SYSTEM_ROUTINE  syshook, IMAGE_THUNK_DATA*  addr, ULONG  flags) /* ../dlls/ntdll/loader.c:3430 */
{
	void* return_value;
	TRACE("Enter LdrResolveDelayLoadedAPI\n");
	return_value = pLdrResolveDelayLoadedAPI(base, desc, dllhook, syshook, addr, flags);
	TRACE("Leave LdrResolveDelayLoadedAPI\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrResolveDelayLoadedAPI(void);  /* ../dlls/ntdll/loader.c:3430 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrResolveDelayLoadedAPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrResolveDelayLoadedAPI") "\n"
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

WINAPI void wine32b_ntdll_LdrShutdownProcess(void) /* ../dlls/ntdll/loader.c:3510 */
{
	TRACE("Enter LdrShutdownProcess\n");
	pLdrShutdownProcess();
	TRACE("Leave LdrShutdownProcess\n");
}

extern WINAPI void wine32a_ntdll_LdrShutdownProcess(void);  /* ../dlls/ntdll/loader.c:3510 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrShutdownProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrShutdownProcess") "\n"
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

WINAPI void wine32b_ntdll_LdrShutdownThread(void) /* ../dlls/ntdll/loader.c:3535 */
{
	TRACE("Enter LdrShutdownThread\n");
	pLdrShutdownThread();
	TRACE("Leave LdrShutdownThread\n");
}

extern WINAPI void wine32a_ntdll_LdrShutdownThread(void);  /* ../dlls/ntdll/loader.c:3535 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrShutdownThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrShutdownThread") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_LdrUnloadDll(HMODULE  hModule) /* ../dlls/ntdll/loader.c:3684 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrUnloadDll\n");
	return_value = pLdrUnloadDll(hModule);
	TRACE("Leave LdrUnloadDll\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrUnloadDll(void);  /* ../dlls/ntdll/loader.c:3684 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrUnloadDll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrUnloadDll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrUnlockLoaderLock(ULONG  flags, ULONG_PTR  magic) /* ../dlls/ntdll/loader.c:1844 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrUnlockLoaderLock\n");
	return_value = pLdrUnlockLoaderLock(flags, magic);
	TRACE("Leave LdrUnlockLoaderLock\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrUnlockLoaderLock(void);  /* ../dlls/ntdll/loader.c:1844 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrUnlockLoaderLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrUnlockLoaderLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_LdrUnregisterDllNotification(void*  cookie) /* ../dlls/ntdll/loader.c:1790 */
{
	NTSTATUS return_value;
	TRACE("Enter LdrUnregisterDllNotification\n");
	return_value = pLdrUnregisterDllNotification(cookie);
	TRACE("Leave LdrUnregisterDllNotification\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_LdrUnregisterDllNotification(void);  /* ../dlls/ntdll/loader.c:1790 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_LdrUnregisterDllNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_LdrUnregisterDllNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD4Final(MD4_CTX*  ctx) /* ../dlls/ntdll/crypt.c:407 */
{
	TRACE("Enter MD4Final\n");
	pMD4Final(ctx);
	TRACE("Leave MD4Final\n");
}

extern WINAPI void wine32a_ntdll_MD4Final(void);  /* ../dlls/ntdll/crypt.c:407 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD4Final,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD4Final") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD4Init(MD4_CTX*  ctx) /* ../dlls/ntdll/crypt.c:335 */
{
	TRACE("Enter MD4Init\n");
	pMD4Init(ctx);
	TRACE("Leave MD4Init\n");
}

extern WINAPI void wine32a_ntdll_MD4Init(void);  /* ../dlls/ntdll/crypt.c:335 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD4Init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD4Init") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD4Update(MD4_CTX*  ctx, unsigned char*  buf, unsigned int  len) /* ../dlls/ntdll/crypt.c:351 */
{
	TRACE("Enter MD4Update\n");
	pMD4Update(ctx, buf, len);
	TRACE("Leave MD4Update\n");
}

extern WINAPI void wine32a_ntdll_MD4Update(void);  /* ../dlls/ntdll/crypt.c:351 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD4Update,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD4Update") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD5Final(MD5_CTX*  ctx) /* ../dlls/ntdll/crypt.c:648 */
{
	TRACE("Enter MD5Final\n");
	pMD5Final(ctx);
	TRACE("Leave MD5Final\n");
}

extern WINAPI void wine32a_ntdll_MD5Final(void);  /* ../dlls/ntdll/crypt.c:648 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD5Final,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD5Final") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD5Init(MD5_CTX*  ctx) /* ../dlls/ntdll/crypt.c:576 */
{
	TRACE("Enter MD5Init\n");
	pMD5Init(ctx);
	TRACE("Leave MD5Init\n");
}

extern WINAPI void wine32a_ntdll_MD5Init(void);  /* ../dlls/ntdll/crypt.c:576 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD5Init,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD5Init") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_MD5Update(MD5_CTX*  ctx, unsigned char*  buf, unsigned int  len) /* ../dlls/ntdll/crypt.c:592 */
{
	TRACE("Enter MD5Update\n");
	pMD5Update(ctx, buf, len);
	TRACE("Leave MD5Update\n");
}

extern WINAPI void wine32a_ntdll_MD5Update(void);  /* ../dlls/ntdll/crypt.c:592 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_MD5Update,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_MD5Update") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAcceptConnectPort(PHANDLE  PortHandle, ULONG  PortIdentifier, PLPC_MESSAGE  pLpcMessage, BOOLEAN  Accept, PLPC_SECTION_WRITE  WriteSection, PLPC_SECTION_READ  ReadSection) /* ../dlls/ntdll/nt.c:841 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAcceptConnectPort\n");
	return_value = pNtAcceptConnectPort(PortHandle, PortIdentifier, pLpcMessage, Accept, WriteSection, ReadSection);
	TRACE("Leave NtAcceptConnectPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAcceptConnectPort(void);  /* ../dlls/ntdll/nt.c:841 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAcceptConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAcceptConnectPort") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAccessCheck(PSECURITY_DESCRIPTOR  SecurityDescriptor, HANDLE  ClientToken, ACCESS_MASK  DesiredAccess, PGENERIC_MAPPING  GenericMapping, PPRIVILEGE_SET  PrivilegeSet, PULONG  ReturnLength, PULONG  GrantedAccess, NTSTATUS*  AccessStatus) /* ../dlls/ntdll/sec.c:1652 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAccessCheck\n");
	return_value = pNtAccessCheck(SecurityDescriptor, ClientToken, DesiredAccess, GenericMapping, PrivilegeSet, ReturnLength, GrantedAccess, AccessStatus);
	TRACE("Leave NtAccessCheck\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAccessCheck(void);  /* ../dlls/ntdll/sec.c:1652 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAccessCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAccessCheck") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAccessCheckAndAuditAlarm(PUNICODE_STRING  SubsystemName, HANDLE  HandleId, PUNICODE_STRING  ObjectTypeName, PUNICODE_STRING  ObjectName, PSECURITY_DESCRIPTOR  SecurityDescriptor, ACCESS_MASK  DesiredAccess, PGENERIC_MAPPING  GenericMapping, BOOLEAN  ObjectCreation, PACCESS_MASK  GrantedAccess, PBOOLEAN  AccessStatus, PBOOLEAN  GenerateOnClose) /* ../dlls/ntdll/nt.c:3401 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAccessCheckAndAuditAlarm\n");
	return_value = pNtAccessCheckAndAuditAlarm(SubsystemName, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, GenerateOnClose);
	TRACE("Leave NtAccessCheckAndAuditAlarm\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAccessCheckAndAuditAlarm(void);  /* ../dlls/ntdll/nt.c:3401 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAccessCheckAndAuditAlarm,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAccessCheckAndAuditAlarm") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAddAtom(WCHAR*  name, ULONG  length, RTL_ATOM*  atom) /* ../dlls/ntdll/atom.c:314 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAddAtom\n");
	return_value = pNtAddAtom(name, length, atom);
	TRACE("Leave NtAddAtom\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAddAtom(void);  /* ../dlls/ntdll/atom.c:314 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAddAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAddAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAdjustGroupsToken(HANDLE  TokenHandle, BOOLEAN  ResetToDefault, PTOKEN_GROUPS  NewState, ULONG  BufferLength, PTOKEN_GROUPS  PreviousState, PULONG  ReturnLength) /* ../dlls/ntdll/nt.c:725 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAdjustGroupsToken\n");
	return_value = pNtAdjustGroupsToken(TokenHandle, ResetToDefault, NewState, BufferLength, PreviousState, ReturnLength);
	TRACE("Leave NtAdjustGroupsToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAdjustGroupsToken(void);  /* ../dlls/ntdll/nt.c:725 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAdjustGroupsToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAdjustGroupsToken") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAdjustPrivilegesToken(HANDLE  TokenHandle, BOOLEAN  DisableAllPrivileges, PTOKEN_PRIVILEGES  NewState, DWORD  BufferLength, PTOKEN_PRIVILEGES  PreviousState, PDWORD  ReturnLength) /* ../dlls/ntdll/nt.c:264 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAdjustPrivilegesToken\n");
	return_value = pNtAdjustPrivilegesToken(TokenHandle, DisableAllPrivileges, NewState, BufferLength, PreviousState, ReturnLength);
	TRACE("Leave NtAdjustPrivilegesToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAdjustPrivilegesToken(void);  /* ../dlls/ntdll/nt.c:264 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAdjustPrivilegesToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAdjustPrivilegesToken") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAlertResumeThread(HANDLE  handle, PULONG  count) /* ../dlls/ntdll/thread.c:634 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAlertResumeThread\n");
	return_value = pNtAlertResumeThread(handle, count);
	TRACE("Leave NtAlertResumeThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAlertResumeThread(void);  /* ../dlls/ntdll/thread.c:634 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAlertResumeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAlertResumeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAlertThread(HANDLE  handle) /* ../dlls/ntdll/thread.c:645 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAlertThread\n");
	return_value = pNtAlertThread(handle);
	TRACE("Leave NtAlertThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAlertThread(void);  /* ../dlls/ntdll/thread.c:645 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAlertThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAlertThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAllocateLocallyUniqueId(PLUID  Luid) /* ../dlls/ntdll/nt.c:3343 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAllocateLocallyUniqueId\n");
	return_value = pNtAllocateLocallyUniqueId(Luid);
	TRACE("Leave NtAllocateLocallyUniqueId\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAllocateLocallyUniqueId(void);  /* ../dlls/ntdll/nt.c:3343 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAllocateLocallyUniqueId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAllocateLocallyUniqueId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAllocateUuids(ULARGE_INTEGER*  time, ULONG*  delta, ULONG*  sequence, UCHAR*  seed) /* ../dlls/ntdll/om.c:714 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAllocateUuids\n");
	return_value = pNtAllocateUuids(time, delta, sequence, seed);
	TRACE("Leave NtAllocateUuids\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAllocateUuids(void);  /* ../dlls/ntdll/om.c:714 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAllocateUuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAllocateUuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAllocateVirtualMemory(HANDLE  process, PVOID*  ret, ULONG_PTR  zero_bits, SIZE_T*  size_ptr, ULONG  type, ULONG  protect) /* ../dlls/ntdll/virtual.c:2551 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAllocateVirtualMemory\n");
	return_value = pNtAllocateVirtualMemory(process, ret, zero_bits, size_ptr, type, protect);
	TRACE("Leave NtAllocateVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAllocateVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:2551 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAllocateVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAllocateVirtualMemory") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtAreMappedFilesTheSame(PVOID  addr1, PVOID  addr2) /* ../dlls/ntdll/virtual.c:3577 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAreMappedFilesTheSame\n");
	return_value = pNtAreMappedFilesTheSame(addr1, addr2);
	TRACE("Leave NtAreMappedFilesTheSame\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAreMappedFilesTheSame(void);  /* ../dlls/ntdll/virtual.c:3577 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAreMappedFilesTheSame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAreMappedFilesTheSame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtAssignProcessToJobObject(HANDLE  job, HANDLE  process) /* ../dlls/ntdll/sync.c:847 */
{
	NTSTATUS return_value;
	TRACE("Enter NtAssignProcessToJobObject\n");
	return_value = pNtAssignProcessToJobObject(job, process);
	TRACE("Leave NtAssignProcessToJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtAssignProcessToJobObject(void);  /* ../dlls/ntdll/sync.c:847 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtAssignProcessToJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtAssignProcessToJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCancelIoFile(HANDLE  hFile, PIO_STATUS_BLOCK  io_status) /* ../dlls/ntdll/file.c:3557 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCancelIoFile\n");
	return_value = pNtCancelIoFile(hFile, io_status);
	TRACE("Leave NtCancelIoFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCancelIoFile(void);  /* ../dlls/ntdll/file.c:3557 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCancelIoFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCancelIoFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCancelIoFileEx(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PIO_STATUS_BLOCK  io_status) /* ../dlls/ntdll/file.c:3536 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCancelIoFileEx\n");
	return_value = pNtCancelIoFileEx(hFile, iosb, io_status);
	TRACE("Leave NtCancelIoFileEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCancelIoFileEx(void);  /* ../dlls/ntdll/file.c:3536 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCancelIoFileEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCancelIoFileEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCancelTimer(HANDLE  handle, BOOLEAN*  state) /* ../dlls/ntdll/sync.c:963 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCancelTimer\n");
	return_value = pNtCancelTimer(handle, state);
	TRACE("Leave NtCancelTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCancelTimer(void);  /* ../dlls/ntdll/sync.c:963 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCancelTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCancelTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtClearEvent(HANDLE  handle) /* ../dlls/ntdll/sync.c:443 */
{
	NTSTATUS return_value;
	TRACE("Enter NtClearEvent\n");
	return_value = pNtClearEvent(handle);
	TRACE("Leave NtClearEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtClearEvent(void);  /* ../dlls/ntdll/sync.c:443 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtClearEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtClearEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtClearPowerRequest(HANDLE  handle, POWER_REQUEST_TYPE  type) /* ../dlls/ntdll/nt.c:3104 */
{
	NTSTATUS return_value;
	TRACE("Enter NtClearPowerRequest\n");
	return_value = pNtClearPowerRequest(handle, type);
	TRACE("Leave NtClearPowerRequest\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtClearPowerRequest(void);  /* ../dlls/ntdll/nt.c:3104 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtClearPowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtClearPowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtClose(HANDLE  Handle) /* ../dlls/ntdll/om.c:431 */
{
	NTSTATUS return_value;
	TRACE("Enter NtClose\n");
	return_value = pNtClose(Handle);
	TRACE("Leave NtClose\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtClose(void);  /* ../dlls/ntdll/om.c:431 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCompleteConnectPort(HANDLE  PortHandle) /* ../dlls/ntdll/nt.c:858 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCompleteConnectPort\n");
	return_value = pNtCompleteConnectPort(PortHandle);
	TRACE("Leave NtCompleteConnectPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCompleteConnectPort(void);  /* ../dlls/ntdll/nt.c:858 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCompleteConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCompleteConnectPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtConnectPort(PHANDLE  PortHandle, PUNICODE_STRING  PortName, PSECURITY_QUALITY_OF_SERVICE  SecurityQos, PLPC_SECTION_WRITE  WriteSection, PLPC_SECTION_READ  ReadSection, PULONG  MaximumMessageLength, PVOID  ConnectInfo, PULONG  pConnectInfoLength) /* ../dlls/ntdll/nt.c:786 */
{
	NTSTATUS return_value;
	TRACE("Enter NtConnectPort\n");
	return_value = pNtConnectPort(PortHandle, PortName, SecurityQos, WriteSection, ReadSection, MaximumMessageLength, ConnectInfo, pConnectInfoLength);
	TRACE("Leave NtConnectPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtConnectPort(void);  /* ../dlls/ntdll/nt.c:786 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtConnectPort") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateDirectoryObject(PHANDLE  DirectoryHandle, ACCESS_MASK  DesiredAccess, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/om.c:493 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateDirectoryObject\n");
	return_value = pNtCreateDirectoryObject(DirectoryHandle, DesiredAccess, attr);
	TRACE("Leave NtCreateDirectoryObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateDirectoryObject(void);  /* ../dlls/ntdll/om.c:493 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateDirectoryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateEvent(PHANDLE  EventHandle, ACCESS_MASK  DesiredAccess, OBJECT_ATTRIBUTES*  attr, EVENT_TYPE  type, BOOLEAN  InitialState) /* ../dlls/ntdll/sync.c:353 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateEvent\n");
	return_value = pNtCreateEvent(EventHandle, DesiredAccess, attr, type, InitialState);
	TRACE("Leave NtCreateEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateEvent(void);  /* ../dlls/ntdll/sync.c:353 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateFile(PHANDLE  handle, ACCESS_MASK  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  io, PLARGE_INTEGER  alloc_size, ULONG  attributes, ULONG  sharing, ULONG  disposition, ULONG  options, PVOID  ea_buffer, ULONG  ea_length) /* ../dlls/ntdll/file.c:336 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateFile\n");
	return_value = pNtCreateFile(handle, access, attr, io, alloc_size, attributes, sharing, disposition, options, ea_buffer, ea_length);
	TRACE("Leave NtCreateFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateFile(void);  /* ../dlls/ntdll/file.c:336 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateIoCompletion(PHANDLE  CompletionPort, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  attr, ULONG  NumberOfConcurrentThreads) /* ../dlls/ntdll/sync.c:1284 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateIoCompletion\n");
	return_value = pNtCreateIoCompletion(CompletionPort, DesiredAccess, attr, NumberOfConcurrentThreads);
	TRACE("Leave NtCreateIoCompletion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateIoCompletion(void);  /* ../dlls/ntdll/sync.c:1284 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateJobObject(PHANDLE  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:624 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateJobObject\n");
	return_value = pNtCreateJobObject(handle, access, attr);
	TRACE("Leave NtCreateJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateJobObject(void);  /* ../dlls/ntdll/sync.c:624 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateKey(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, PULONG  dispos) /* ../dlls/ntdll/reg.c:52 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateKey\n");
	return_value = pNtCreateKey(retkey, access, attr, TitleIndex, class, options, dispos);
	TRACE("Leave NtCreateKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateKey(void);  /* ../dlls/ntdll/reg.c:52 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateKeyTransacted(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, HANDLE  transacted, ULONG*  dispos) /* ../dlls/ntdll/reg.c:85 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateKeyTransacted\n");
	return_value = pNtCreateKeyTransacted(retkey, access, attr, TitleIndex, class, options, transacted, dispos);
	TRACE("Leave NtCreateKeyTransacted\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateKeyTransacted(void);  /* ../dlls/ntdll/reg.c:85 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateKeyTransacted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateKeyTransacted") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateKeyedEvent(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  flags) /* ../dlls/ntdll/sync.c:1190 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateKeyedEvent\n");
	return_value = pNtCreateKeyedEvent(handle, access, attr, flags);
	TRACE("Leave NtCreateKeyedEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateKeyedEvent(void);  /* ../dlls/ntdll/sync.c:1190 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateLowBoxToken(HANDLE*  token_handle, HANDLE  existing_token_handle, ACCESS_MASK  desired_access, OBJECT_ATTRIBUTES*  object_attributes, SID*  package_sid, ULONG  capability_count, SID_AND_ATTRIBUTES*  capabilities, ULONG  handle_count, HANDLE*  handle) /* ../dlls/ntdll/misc.c:597 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateLowBoxToken\n");
	return_value = pNtCreateLowBoxToken(token_handle, existing_token_handle, desired_access, object_attributes, package_sid, capability_count, capabilities, handle_count, handle);
	TRACE("Leave NtCreateLowBoxToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateLowBoxToken(void);  /* ../dlls/ntdll/misc.c:597 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateLowBoxToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateLowBoxToken") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateMailslotFile(PHANDLE  pHandle, ULONG  DesiredAccess, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CreateOptions, ULONG  MailslotQuota, ULONG  MaxMessageSize, PLARGE_INTEGER  TimeOut) /* ../dlls/ntdll/file.c:3590 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateMailslotFile\n");
	return_value = pNtCreateMailslotFile(pHandle, DesiredAccess, attr, IoStatusBlock, CreateOptions, MailslotQuota, MaxMessageSize, TimeOut);
	TRACE("Leave NtCreateMailslotFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateMailslotFile(void);  /* ../dlls/ntdll/file.c:3590 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateMailslotFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateMailslotFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateMutant(HANDLE*  MutantHandle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, BOOLEAN  InitialOwner) /* ../dlls/ntdll/sync.c:512 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateMutant\n");
	return_value = pNtCreateMutant(MutantHandle, access, attr, InitialOwner);
	TRACE("Leave NtCreateMutant\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateMutant(void);  /* ../dlls/ntdll/sync.c:512 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateNamedPipeFile(PHANDLE  handle, ULONG  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  iosb, ULONG  sharing, ULONG  dispo, ULONG  options, ULONG  pipe_type, ULONG  read_mode, ULONG  completion_mode, ULONG  max_inst, ULONG  inbound_quota, ULONG  outbound_quota, PLARGE_INTEGER  timeout) /* ../dlls/ntdll/file.c:3463 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateNamedPipeFile\n");
	return_value = pNtCreateNamedPipeFile(handle, access, attr, iosb, sharing, dispo, options, pipe_type, read_mode, completion_mode, max_inst, inbound_quota, outbound_quota, timeout);
	TRACE("Leave NtCreateNamedPipeFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateNamedPipeFile(void);  /* ../dlls/ntdll/file.c:3463 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateNamedPipeFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateNamedPipeFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreatePagingFile(PUNICODE_STRING  PageFileName, PLARGE_INTEGER  MinimumSize, PLARGE_INTEGER  MaximumSize, PLARGE_INTEGER  ActualSize) /* ../dlls/ntdll/nt.c:3018 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreatePagingFile\n");
	return_value = pNtCreatePagingFile(PageFileName, MinimumSize, MaximumSize, ActualSize);
	TRACE("Leave NtCreatePagingFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreatePagingFile(void);  /* ../dlls/ntdll/nt.c:3018 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreatePagingFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreatePagingFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreatePort(PHANDLE  PortHandle, POBJECT_ATTRIBUTES  ObjectAttributes, ULONG  MaxConnectInfoLength, ULONG  MaxDataLength, PULONG  reserved) /* ../dlls/ntdll/nt.c:774 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreatePort\n");
	return_value = pNtCreatePort(PortHandle, ObjectAttributes, MaxConnectInfoLength, MaxDataLength, reserved);
	TRACE("Leave NtCreatePort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreatePort(void);  /* ../dlls/ntdll/nt.c:774 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreatePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreatePort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreatePowerRequest(HANDLE*  handle, COUNTED_REASON_CONTEXT*  context) /* ../dlls/ntdll/nt.c:3082 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreatePowerRequest\n");
	return_value = pNtCreatePowerRequest(handle, context);
	TRACE("Leave NtCreatePowerRequest\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreatePowerRequest(void);  /* ../dlls/ntdll/nt.c:3082 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreatePowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreatePowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateSection(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, LARGE_INTEGER*  size, ULONG  protect, ULONG  sec_flags, HANDLE  file) /* ../dlls/ntdll/virtual.c:3121 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateSection\n");
	return_value = pNtCreateSection(handle, access, attr, size, protect, sec_flags, file);
	TRACE("Leave NtCreateSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateSection(void);  /* ../dlls/ntdll/virtual.c:3121 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateSection") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateSemaphore(PHANDLE  SemaphoreHandle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, LONG  InitialCount, LONG  MaximumCount) /* ../dlls/ntdll/sync.c:239 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateSemaphore\n");
	return_value = pNtCreateSemaphore(SemaphoreHandle, access, attr, InitialCount, MaximumCount);
	TRACE("Leave NtCreateSemaphore\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateSemaphore(void);  /* ../dlls/ntdll/sync.c:239 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateSymbolicLinkObject(PHANDLE  SymbolicLinkHandle, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  attr, PUNICODE_STRING  TargetName) /* ../dlls/ntdll/om.c:642 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateSymbolicLinkObject\n");
	return_value = pNtCreateSymbolicLinkObject(SymbolicLinkHandle, DesiredAccess, attr, TargetName);
	TRACE("Leave NtCreateSymbolicLinkObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateSymbolicLinkObject(void);  /* ../dlls/ntdll/om.c:642 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateSymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateSymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtCreateThreadEx(HANDLE*  handle_ptr, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, HANDLE  process, LPTHREAD_START_ROUTINE  start, void*  param, ULONG  flags, ULONG  zero_bits, ULONG  stack_commit, ULONG  stack_reserve, void*  attribute_list) /* ../dlls/ntdll/thread.c:383 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateThreadEx\n");
	return_value = pNtCreateThreadEx(handle_ptr, access, attr, process, start, param, flags, zero_bits, stack_commit, stack_reserve, attribute_list);
	TRACE("Leave NtCreateThreadEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateThreadEx(void);  /* ../dlls/ntdll/thread.c:383 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateThreadEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateThreadEx") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtCreateTimer(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, TIMER_TYPE  timer_type) /* ../dlls/ntdll/sync.c:872 */
{
	NTSTATUS return_value;
	TRACE("Enter NtCreateTimer\n");
	return_value = pNtCreateTimer(handle, access, attr, timer_type);
	TRACE("Leave NtCreateTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtCreateTimer(void);  /* ../dlls/ntdll/sync.c:872 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtCreateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtCreateTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDelayExecution(BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1147 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDelayExecution\n");
	return_value = pNtDelayExecution(alertable, timeout);
	TRACE("Leave NtDelayExecution\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDelayExecution(void);  /* ../dlls/ntdll/sync.c:1147 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDelayExecution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDelayExecution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDeleteAtom(RTL_ATOM  atom) /* ../dlls/ntdll/atom.c:338 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDeleteAtom\n");
	return_value = pNtDeleteAtom(atom);
	TRACE("Leave NtDeleteAtom\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDeleteAtom(void);  /* ../dlls/ntdll/atom.c:338 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDeleteAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDeleteAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDeleteFile(POBJECT_ATTRIBUTES  ObjectAttributes) /* ../dlls/ntdll/file.c:3516 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDeleteFile\n");
	return_value = pNtDeleteFile(ObjectAttributes);
	TRACE("Leave NtDeleteFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDeleteFile(void);  /* ../dlls/ntdll/file.c:3516 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDeleteFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDeleteFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDeleteKey(HANDLE  hkey) /* ../dlls/ntdll/reg.c:198 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDeleteKey\n");
	return_value = pNtDeleteKey(hkey);
	TRACE("Leave NtDeleteKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDeleteKey(void);  /* ../dlls/ntdll/reg.c:198 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDeleteKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDeleteKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDeleteValueKey(HANDLE  hkey, UNICODE_STRING*  name) /* ../dlls/ntdll/reg.c:227 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDeleteValueKey\n");
	return_value = pNtDeleteValueKey(hkey, name);
	TRACE("Leave NtDeleteValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDeleteValueKey(void);  /* ../dlls/ntdll/reg.c:227 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDeleteValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDeleteValueKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDeviceIoControlFile(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, PVOID  apc_context, PIO_STATUS_BLOCK  io, ULONG  code, PVOID  in_buffer, ULONG  in_size, PVOID  out_buffer, ULONG  out_size) /* ../dlls/ntdll/file.c:1600 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDeviceIoControlFile\n");
	return_value = pNtDeviceIoControlFile(handle, event, apc, apc_context, io, code, in_buffer, in_size, out_buffer, out_size);
	TRACE("Leave NtDeviceIoControlFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDeviceIoControlFile(void);  /* ../dlls/ntdll/file.c:1600 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDeviceIoControlFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDeviceIoControlFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtDisplayString(PUNICODE_STRING  string) /* ../dlls/ntdll/nt.c:3033 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDisplayString\n");
	return_value = pNtDisplayString(string);
	TRACE("Leave NtDisplayString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDisplayString(void);  /* ../dlls/ntdll/nt.c:3033 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDisplayString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDisplayString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtDuplicateObject(HANDLE  source_process, HANDLE  source, HANDLE  dest_process, PHANDLE  dest, ACCESS_MASK  access, ULONG  attributes, ULONG  options) /* ../dlls/ntdll/om.c:350 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDuplicateObject\n");
	return_value = pNtDuplicateObject(source_process, source, dest_process, dest, access, attributes, options);
	TRACE("Leave NtDuplicateObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDuplicateObject(void);  /* ../dlls/ntdll/om.c:350 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDuplicateObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDuplicateObject") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtDuplicateToken(HANDLE  ExistingToken, ACCESS_MASK  DesiredAccess, POBJECT_ATTRIBUTES  ObjectAttributes, SECURITY_IMPERSONATION_LEVEL  ImpersonationLevel, TOKEN_TYPE  TokenType, PHANDLE  NewToken) /* ../dlls/ntdll/nt.c:139 */
{
	NTSTATUS return_value;
	TRACE("Enter NtDuplicateToken\n");
	return_value = pNtDuplicateToken(ExistingToken, DesiredAccess, ObjectAttributes, ImpersonationLevel, TokenType, NewToken);
	TRACE("Leave NtDuplicateToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtDuplicateToken(void);  /* ../dlls/ntdll/nt.c:139 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtDuplicateToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtDuplicateToken") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtEnumerateKey(HANDLE  handle, ULONG  index, KEY_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len) /* ../dlls/ntdll/reg.c:371 */
{
	NTSTATUS return_value;
	TRACE("Enter NtEnumerateKey\n");
	return_value = pNtEnumerateKey(handle, index, info_class, info, length, result_len);
	TRACE("Leave NtEnumerateKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtEnumerateKey(void);  /* ../dlls/ntdll/reg.c:371 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtEnumerateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtEnumerateKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtEnumerateValueKey(HANDLE  handle, ULONG  index, KEY_VALUE_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len) /* ../dlls/ntdll/reg.c:485 */
{
	NTSTATUS return_value;
	TRACE("Enter NtEnumerateValueKey\n");
	return_value = pNtEnumerateValueKey(handle, index, info_class, info, length, result_len);
	TRACE("Leave NtEnumerateValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtEnumerateValueKey(void);  /* ../dlls/ntdll/reg.c:485 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtEnumerateValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtEnumerateValueKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtFindAtom(WCHAR*  name, ULONG  length, RTL_ATOM*  atom) /* ../dlls/ntdll/atom.c:355 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFindAtom\n");
	return_value = pNtFindAtom(name, length, atom);
	TRACE("Leave NtFindAtom\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFindAtom(void);  /* ../dlls/ntdll/atom.c:355 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFindAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFindAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFlushBuffersFile(HANDLE  hFile, IO_STATUS_BLOCK*  io) /* ../dlls/ntdll/file.c:3307 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFlushBuffersFile\n");
	return_value = pNtFlushBuffersFile(hFile, io);
	TRACE("Leave NtFlushBuffersFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFlushBuffersFile(void);  /* ../dlls/ntdll/file.c:3307 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFlushBuffersFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFlushBuffersFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFlushInstructionCache(HANDLE  handle, void*  addr, SIZE_T  size) /* ../dlls/ntdll/process.c:718 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFlushInstructionCache\n");
	return_value = pNtFlushInstructionCache(handle, addr, size);
	TRACE("Leave NtFlushInstructionCache\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFlushInstructionCache(void);  /* ../dlls/ntdll/process.c:718 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFlushInstructionCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFlushInstructionCache") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFlushKey(HANDLE  key) /* ../dlls/ntdll/reg.c:635 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFlushKey\n");
	return_value = pNtFlushKey(key);
	TRACE("Leave NtFlushKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFlushKey(void);  /* ../dlls/ntdll/reg.c:635 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFlushKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFlushKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFlushVirtualMemory(HANDLE  process, LPCVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  unknown) /* ../dlls/ntdll/virtual.c:3395 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFlushVirtualMemory\n");
	return_value = pNtFlushVirtualMemory(process, addr_ptr, size_ptr, unknown);
	TRACE("Leave NtFlushVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFlushVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:3395 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFlushVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFlushVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFreeVirtualMemory(HANDLE  process, PVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  type) /* ../dlls/ntdll/virtual.c:2703 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFreeVirtualMemory\n");
	return_value = pNtFreeVirtualMemory(process, addr_ptr, size_ptr, type);
	TRACE("Leave NtFreeVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFreeVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:2703 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFreeVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFreeVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtFsControlFile(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, PVOID  apc_context, PIO_STATUS_BLOCK  io, ULONG  code, PVOID  in_buffer, ULONG  in_size, PVOID  out_buffer, ULONG  out_size) /* ../dlls/ntdll/file.c:1664 */
{
	NTSTATUS return_value;
	TRACE("Enter NtFsControlFile\n");
	return_value = pNtFsControlFile(handle, event, apc, apc_context, io, code, in_buffer, in_size, out_buffer, out_size);
	TRACE("Leave NtFsControlFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtFsControlFile(void);  /* ../dlls/ntdll/file.c:1664 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtFsControlFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtFsControlFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtGetContextThread(HANDLE  handle, CONTEXT*  context) /* ../dlls/ntdll/signal_x86_64.c:2201 */
{
	NTSTATUS return_value;
	TRACE("Enter NtGetContextThread\n");
	return_value = pNtGetContextThread(handle, context);
	TRACE("Leave NtGetContextThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtGetContextThread(void);  /* ../dlls/ntdll/signal_x86_64.c:2201 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtGetContextThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtGetContextThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_NtGetCurrentProcessorNumber(void) /* ../dlls/ntdll/thread.c:1246 */
{
	ULONG return_value;
	TRACE("Enter NtGetCurrentProcessorNumber\n");
	return_value = pNtGetCurrentProcessorNumber();
	TRACE("Leave NtGetCurrentProcessorNumber\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtGetCurrentProcessorNumber(void);  /* ../dlls/ntdll/thread.c:1246 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtGetCurrentProcessorNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtGetCurrentProcessorNumber") "\n"
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

WINAPI ULONG wine32b_ntdll_NtGetTickCount(void) /* ../dlls/ntdll/time.c:577 */
{
	ULONG return_value;
	TRACE("Enter NtGetTickCount\n");
	return_value = pNtGetTickCount();
	TRACE("Leave NtGetTickCount\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtGetTickCount(void);  /* ../dlls/ntdll/time.c:577 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtGetTickCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtGetTickCount") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtGetWriteWatch(HANDLE  process, ULONG  flags, PVOID  base, SIZE_T  size, PVOID*  addresses, ULONG_PTR*  count, ULONG*  granularity) /* ../dlls/ntdll/virtual.c:3443 */
{
	NTSTATUS return_value;
	TRACE("Enter NtGetWriteWatch\n");
	return_value = pNtGetWriteWatch(process, flags, base, size, addresses, count, granularity);
	TRACE("Leave NtGetWriteWatch\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtGetWriteWatch(void);  /* ../dlls/ntdll/virtual.c:3443 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtGetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtGetWriteWatch") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtImpersonateAnonymousToken(HANDLE  thread) /* ../dlls/ntdll/sec.c:1618 */
{
	NTSTATUS return_value;
	TRACE("Enter NtImpersonateAnonymousToken\n");
	return_value = pNtImpersonateAnonymousToken(thread);
	TRACE("Leave NtImpersonateAnonymousToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtImpersonateAnonymousToken(void);  /* ../dlls/ntdll/sec.c:1618 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtImpersonateAnonymousToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtImpersonateAnonymousToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtInitiatePowerAction(POWER_ACTION  SystemAction, SYSTEM_POWER_STATE  MinSystemState, ULONG  Flags, BOOLEAN  Asynchronous) /* ../dlls/ntdll/nt.c:3050 */
{
	NTSTATUS return_value;
	TRACE("Enter NtInitiatePowerAction\n");
	return_value = pNtInitiatePowerAction(SystemAction, MinSystemState, Flags, Asynchronous);
	TRACE("Leave NtInitiatePowerAction\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtInitiatePowerAction(void);  /* ../dlls/ntdll/nt.c:3050 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtInitiatePowerAction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtInitiatePowerAction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtIsProcessInJob(HANDLE  process, HANDLE  job) /* ../dlls/ntdll/sync.c:826 */
{
	NTSTATUS return_value;
	TRACE("Enter NtIsProcessInJob\n");
	return_value = pNtIsProcessInJob(process, job);
	TRACE("Leave NtIsProcessInJob\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtIsProcessInJob(void);  /* ../dlls/ntdll/sync.c:826 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtIsProcessInJob,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtIsProcessInJob") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtListenPort(HANDLE  PortHandle, PLPC_MESSAGE  pLpcMessage) /* ../dlls/ntdll/nt.c:831 */
{
	NTSTATUS return_value;
	TRACE("Enter NtListenPort\n");
	return_value = pNtListenPort(PortHandle, pLpcMessage);
	TRACE("Leave NtListenPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtListenPort(void);  /* ../dlls/ntdll/nt.c:831 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtListenPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtListenPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtLoadDriver(UNICODE_STRING*  DriverServiceName) /* ../dlls/ntdll/loader.c:3972 */
{
	NTSTATUS return_value;
	TRACE("Enter NtLoadDriver\n");
	return_value = pNtLoadDriver(DriverServiceName);
	TRACE("Leave NtLoadDriver\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtLoadDriver(void);  /* ../dlls/ntdll/loader.c:3972 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtLoadDriver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtLoadDriver") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtLoadKey2(OBJECT_ATTRIBUTES*  attr, OBJECT_ATTRIBUTES*  file, ULONG  flags) /* ../dlls/ntdll/reg.c:688 */
{
	NTSTATUS return_value;
	TRACE("Enter NtLoadKey2\n");
	return_value = pNtLoadKey2(attr, file, flags);
	TRACE("Leave NtLoadKey2\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtLoadKey2(void);  /* ../dlls/ntdll/reg.c:688 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtLoadKey2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtLoadKey2") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtLoadKey(OBJECT_ATTRIBUTES*  attr, OBJECT_ATTRIBUTES*  file) /* ../dlls/ntdll/reg.c:655 */
{
	NTSTATUS return_value;
	TRACE("Enter NtLoadKey\n");
	return_value = pNtLoadKey(attr, file);
	TRACE("Leave NtLoadKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtLoadKey(void);  /* ../dlls/ntdll/reg.c:655 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtLoadKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtLoadKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtLockFile(HANDLE  hFile, HANDLE  lock_granted_event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, PLARGE_INTEGER  offset, PLARGE_INTEGER  count, ULONG*  key, BOOLEAN  dont_wait, BOOLEAN  exclusive) /* ../dlls/ntdll/file.c:3360 */
{
	NTSTATUS return_value;
	TRACE("Enter NtLockFile\n");
	return_value = pNtLockFile(hFile, lock_granted_event, apc, apc_user, io_status, offset, count, key, dont_wait, exclusive);
	TRACE("Leave NtLockFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtLockFile(void);  /* ../dlls/ntdll/file.c:3360 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtLockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtLockFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtLockVirtualMemory(HANDLE  process, PVOID*  addr, SIZE_T*  size, ULONG  unknown) /* ../dlls/ntdll/virtual.c:3047 */
{
	NTSTATUS return_value;
	TRACE("Enter NtLockVirtualMemory\n");
	return_value = pNtLockVirtualMemory(process, addr, size, unknown);
	TRACE("Leave NtLockVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtLockVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:3047 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtLockVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtLockVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtMakeTemporaryObject(HANDLE  Handle) /* ../dlls/ntdll/om.c:733 */
{
	NTSTATUS return_value;
	TRACE("Enter NtMakeTemporaryObject\n");
	return_value = pNtMakeTemporaryObject(Handle);
	TRACE("Leave NtMakeTemporaryObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtMakeTemporaryObject(void);  /* ../dlls/ntdll/om.c:733 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtMakeTemporaryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtMakeTemporaryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtMapViewOfSection(HANDLE  handle, HANDLE  process, PVOID*  addr_ptr, ULONG_PTR  zero_bits, SIZE_T  commit_size, LARGE_INTEGER*  offset_ptr, SIZE_T*  size_ptr, SECTION_INHERIT  inherit, ULONG  alloc_type, ULONG  protect) /* ../dlls/ntdll/virtual.c:3183 */
{
	NTSTATUS return_value;
	TRACE("Enter NtMapViewOfSection\n");
	return_value = pNtMapViewOfSection(handle, process, addr_ptr, zero_bits, commit_size, offset_ptr, size_ptr, inherit, alloc_type, protect);
	TRACE("Leave NtMapViewOfSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtMapViewOfSection(void);  /* ../dlls/ntdll/virtual.c:3183 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtMapViewOfSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtMapViewOfSection") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtNotifyChangeDirectoryFile(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_context, PIO_STATUS_BLOCK  iosb, void*  buffer, ULONG  buffer_size, ULONG  filter, BOOLEAN  subtree) /* ../dlls/ntdll/file.c:1833 */
{
	NTSTATUS return_value;
	TRACE("Enter NtNotifyChangeDirectoryFile\n");
	return_value = pNtNotifyChangeDirectoryFile(handle, event, apc, apc_context, iosb, buffer, buffer_size, filter, subtree);
	TRACE("Leave NtNotifyChangeDirectoryFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtNotifyChangeDirectoryFile(void);  /* ../dlls/ntdll/file.c:1833 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtNotifyChangeDirectoryFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtNotifyChangeDirectoryFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtNotifyChangeKey(HANDLE  KeyHandle, HANDLE  Event, PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CompletionFilter, BOOLEAN  WatchSubtree, PVOID  ChangeBuffer, ULONG  Length, BOOLEAN  Asynchronous) /* ../dlls/ntdll/reg.c:754 */
{
	NTSTATUS return_value;
	TRACE("Enter NtNotifyChangeKey\n");
	return_value = pNtNotifyChangeKey(KeyHandle, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchSubtree, ChangeBuffer, Length, Asynchronous);
	TRACE("Leave NtNotifyChangeKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtNotifyChangeKey(void);  /* ../dlls/ntdll/reg.c:754 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtNotifyChangeKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtNotifyChangeKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtNotifyChangeMultipleKeys(HANDLE  KeyHandle, ULONG  Count, OBJECT_ATTRIBUTES*  SubordinateObjects, HANDLE  Event, PIO_APC_ROUTINE  ApcRoutine, PVOID  ApcContext, PIO_STATUS_BLOCK  IoStatusBlock, ULONG  CompletionFilter, BOOLEAN  WatchSubtree, PVOID  ChangeBuffer, ULONG  Length, BOOLEAN  Asynchronous) /* ../dlls/ntdll/reg.c:698 */
{
	NTSTATUS return_value;
	TRACE("Enter NtNotifyChangeMultipleKeys\n");
	return_value = pNtNotifyChangeMultipleKeys(KeyHandle, Count, SubordinateObjects, Event, ApcRoutine, ApcContext, IoStatusBlock, CompletionFilter, WatchSubtree, ChangeBuffer, Length, Asynchronous);
	TRACE("Leave NtNotifyChangeMultipleKeys\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtNotifyChangeMultipleKeys(void);  /* ../dlls/ntdll/reg.c:698 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtNotifyChangeMultipleKeys,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtNotifyChangeMultipleKeys") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtOpenDirectoryObject(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/om.c:455 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenDirectoryObject\n");
	return_value = pNtOpenDirectoryObject(handle, access, attr);
	TRACE("Leave NtOpenDirectoryObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenDirectoryObject(void);  /* ../dlls/ntdll/om.c:455 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenDirectoryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenEvent(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:381 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenEvent\n");
	return_value = pNtOpenEvent(handle, access, attr);
	TRACE("Leave NtOpenEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenEvent(void);  /* ../dlls/ntdll/sync.c:381 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenFile(PHANDLE  handle, ACCESS_MASK  access, POBJECT_ATTRIBUTES  attr, PIO_STATUS_BLOCK  io, ULONG  sharing, ULONG  options) /* ../dlls/ntdll/file.c:304 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenFile\n");
	return_value = pNtOpenFile(handle, access, attr, io, sharing, options);
	TRACE("Leave NtOpenFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenFile(void);  /* ../dlls/ntdll/file.c:304 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtOpenIoCompletion(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:1453 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenIoCompletion\n");
	return_value = pNtOpenIoCompletion(handle, access, attr);
	TRACE("Leave NtOpenIoCompletion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenIoCompletion(void);  /* ../dlls/ntdll/sync.c:1453 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenJobObject(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:649 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenJobObject\n");
	return_value = pNtOpenJobObject(handle, access, attr);
	TRACE("Leave NtOpenJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenJobObject(void);  /* ../dlls/ntdll/sync.c:649 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenKey(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/reg.c:164 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenKey\n");
	return_value = pNtOpenKey(retkey, access, attr);
	TRACE("Leave NtOpenKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenKey(void);  /* ../dlls/ntdll/reg.c:164 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenKeyEx(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  options) /* ../dlls/ntdll/reg.c:151 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenKeyEx\n");
	return_value = pNtOpenKeyEx(retkey, access, attr, options);
	TRACE("Leave NtOpenKeyEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenKeyEx(void);  /* ../dlls/ntdll/reg.c:151 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenKeyEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenKeyEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenKeyTransacted(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, HANDLE  transaction) /* ../dlls/ntdll/reg.c:176 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenKeyTransacted\n");
	return_value = pNtOpenKeyTransacted(retkey, access, attr, transaction);
	TRACE("Leave NtOpenKeyTransacted\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenKeyTransacted(void);  /* ../dlls/ntdll/reg.c:176 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenKeyTransacted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenKeyTransacted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenKeyTransactedEx(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  options, HANDLE  transaction) /* ../dlls/ntdll/reg.c:169 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenKeyTransactedEx\n");
	return_value = pNtOpenKeyTransactedEx(retkey, access, attr, options, transaction);
	TRACE("Leave NtOpenKeyTransactedEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenKeyTransactedEx(void);  /* ../dlls/ntdll/reg.c:169 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenKeyTransactedEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenKeyTransactedEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenKeyedEvent(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:1215 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenKeyedEvent\n");
	return_value = pNtOpenKeyedEvent(handle, access, attr);
	TRACE("Leave NtOpenKeyedEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenKeyedEvent(void);  /* ../dlls/ntdll/sync.c:1215 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenMutant(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:541 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenMutant\n");
	return_value = pNtOpenMutant(handle, access, attr);
	TRACE("Leave NtOpenMutant\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenMutant(void);  /* ../dlls/ntdll/sync.c:541 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenProcess(PHANDLE  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, CLIENT_ID*  cid) /* ../dlls/ntdll/process.c:743 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenProcess\n");
	return_value = pNtOpenProcess(handle, access, attr, cid);
	TRACE("Leave NtOpenProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenProcess(void);  /* ../dlls/ntdll/process.c:743 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenProcessToken(HANDLE  ProcessHandle, DWORD  DesiredAccess, HANDLE*  TokenHandle) /* ../dlls/ntdll/nt.c:187 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenProcessToken\n");
	return_value = pNtOpenProcessToken(ProcessHandle, DesiredAccess, TokenHandle);
	TRACE("Leave NtOpenProcessToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenProcessToken(void);  /* ../dlls/ntdll/nt.c:187 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenProcessToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenProcessToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenProcessTokenEx(HANDLE  process, DWORD  access, DWORD  attributes, HANDLE*  handle) /* ../dlls/ntdll/nt.c:199 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenProcessTokenEx\n");
	return_value = pNtOpenProcessTokenEx(process, access, attributes, handle);
	TRACE("Leave NtOpenProcessTokenEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenProcessTokenEx(void);  /* ../dlls/ntdll/nt.c:199 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenProcessTokenEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenProcessTokenEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenSection(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/virtual.c:3158 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenSection\n");
	return_value = pNtOpenSection(handle, access, attr);
	TRACE("Leave NtOpenSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenSection(void);  /* ../dlls/ntdll/virtual.c:3158 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenSemaphore(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:272 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenSemaphore\n");
	return_value = pNtOpenSemaphore(handle, access, attr);
	TRACE("Leave NtOpenSemaphore\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenSemaphore(void);  /* ../dlls/ntdll/sync.c:272 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenSymbolicLinkObject(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/om.c:602 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenSymbolicLinkObject\n");
	return_value = pNtOpenSymbolicLinkObject(handle, access, attr);
	TRACE("Leave NtOpenSymbolicLinkObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenSymbolicLinkObject(void);  /* ../dlls/ntdll/om.c:602 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenSymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenSymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenThread(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, CLIENT_ID*  id) /* ../dlls/ntdll/thread.c:570 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenThread\n");
	return_value = pNtOpenThread(handle, access, attr, id);
	TRACE("Leave NtOpenThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenThread(void);  /* ../dlls/ntdll/thread.c:570 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenThreadToken(HANDLE  ThreadHandle, DWORD  DesiredAccess, BOOLEAN  OpenAsSelf, HANDLE*  TokenHandle) /* ../dlls/ntdll/nt.c:223 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenThreadToken\n");
	return_value = pNtOpenThreadToken(ThreadHandle, DesiredAccess, OpenAsSelf, TokenHandle);
	TRACE("Leave NtOpenThreadToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenThreadToken(void);  /* ../dlls/ntdll/nt.c:223 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenThreadToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenThreadToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenThreadTokenEx(HANDLE  thread, DWORD  access, BOOLEAN  as_self, DWORD  attributes, HANDLE*  handle) /* ../dlls/ntdll/nt.c:236 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenThreadTokenEx\n");
	return_value = pNtOpenThreadTokenEx(thread, access, as_self, attributes, handle);
	TRACE("Leave NtOpenThreadTokenEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenThreadTokenEx(void);  /* ../dlls/ntdll/nt.c:236 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenThreadTokenEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenThreadTokenEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtOpenTimer(HANDLE*  handle, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/sync.c:905 */
{
	NTSTATUS return_value;
	TRACE("Enter NtOpenTimer\n");
	return_value = pNtOpenTimer(handle, access, attr);
	TRACE("Leave NtOpenTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtOpenTimer(void);  /* ../dlls/ntdll/sync.c:905 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtOpenTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtOpenTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtPowerInformation(POWER_INFORMATION_LEVEL  InformationLevel, PVOID  lpInputBuffer, ULONG  nInputBufferSize, PVOID  lpOutputBuffer, ULONG  nOutputBufferSize) /* ../dlls/ntdll/nt.c:3144 */
{
	NTSTATUS return_value;
	TRACE("Enter NtPowerInformation\n");
	return_value = pNtPowerInformation(InformationLevel, lpInputBuffer, nInputBufferSize, lpOutputBuffer, nOutputBufferSize);
	TRACE("Leave NtPowerInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtPowerInformation(void);  /* ../dlls/ntdll/nt.c:3144 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtPowerInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtPowerInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtPrivilegeCheck(HANDLE  ClientToken, PPRIVILEGE_SET  RequiredPrivileges, PBOOLEAN  Result) /* ../dlls/ntdll/nt.c:742 */
{
	NTSTATUS return_value;
	TRACE("Enter NtPrivilegeCheck\n");
	return_value = pNtPrivilegeCheck(ClientToken, RequiredPrivileges, Result);
	TRACE("Leave NtPrivilegeCheck\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtPrivilegeCheck(void);  /* ../dlls/ntdll/nt.c:742 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtPrivilegeCheck,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtPrivilegeCheck") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtProtectVirtualMemory(HANDLE  process, PVOID*  addr_ptr, SIZE_T*  size_ptr, ULONG  new_prot, ULONG*  old_prot) /* ../dlls/ntdll/virtual.c:2786 */
{
	NTSTATUS return_value;
	TRACE("Enter NtProtectVirtualMemory\n");
	return_value = pNtProtectVirtualMemory(process, addr_ptr, size_ptr, new_prot, old_prot);
	TRACE("Leave NtProtectVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtProtectVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:2786 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtProtectVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtProtectVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtPulseEvent(HANDLE  handle, LONG*  prev_state) /* ../dlls/ntdll/sync.c:454 */
{
	NTSTATUS return_value;
	TRACE("Enter NtPulseEvent\n");
	return_value = pNtPulseEvent(handle, prev_state);
	TRACE("Leave NtPulseEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtPulseEvent(void);  /* ../dlls/ntdll/sync.c:454 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtPulseEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtPulseEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryAttributesFile(OBJECT_ATTRIBUTES*  attr, FILE_BASIC_INFORMATION*  info) /* ../dlls/ntdll/file.c:2877 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryAttributesFile\n");
	return_value = pNtQueryAttributesFile(attr, info);
	TRACE("Leave NtQueryAttributesFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryAttributesFile(void);  /* ../dlls/ntdll/file.c:2877 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryAttributesFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryAttributesFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryDefaultLocale(BOOLEAN  user, LCID*  lcid) /* ../dlls/ntdll/resource.c:458 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryDefaultLocale\n");
	return_value = pNtQueryDefaultLocale(user, lcid);
	TRACE("Leave NtQueryDefaultLocale\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryDefaultLocale(void);  /* ../dlls/ntdll/resource.c:458 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryDefaultUILanguage(LANGID*  lang) /* ../dlls/ntdll/resource.c:483 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryDefaultUILanguage\n");
	return_value = pNtQueryDefaultUILanguage(lang);
	TRACE("Leave NtQueryDefaultUILanguage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryDefaultUILanguage(void);  /* ../dlls/ntdll/resource.c:483 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryDefaultUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryDirectoryFile(HANDLE  handle, HANDLE  event, PIO_APC_ROUTINE  apc_routine, PVOID  apc_context, PIO_STATUS_BLOCK  io, PVOID  buffer, ULONG  length, FILE_INFORMATION_CLASS  info_class, BOOLEAN  single_entry, PUNICODE_STRING  mask, BOOLEAN  restart_scan) /* ../dlls/ntdll/directory.c:1943 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryDirectoryFile\n");
	return_value = pNtQueryDirectoryFile(handle, event, apc_routine, apc_context, io, buffer, length, info_class, single_entry, mask, restart_scan);
	TRACE("Leave NtQueryDirectoryFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryDirectoryFile(void);  /* ../dlls/ntdll/directory.c:1943 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryDirectoryFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryDirectoryFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryDirectoryObject(HANDLE  handle, PDIRECTORY_BASIC_INFORMATION  buffer, ULONG  size, BOOLEAN  single_entry, BOOLEAN  restart, PULONG  context, PULONG  ret_size) /* ../dlls/ntdll/om.c:537 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryDirectoryObject\n");
	return_value = pNtQueryDirectoryObject(handle, buffer, size, single_entry, restart, context, ret_size);
	TRACE("Leave NtQueryDirectoryObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryDirectoryObject(void);  /* ../dlls/ntdll/om.c:537 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryDirectoryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryDirectoryObject") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryEaFile(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PVOID  buffer, ULONG  length, BOOLEAN  single_entry, PVOID  ea_list, ULONG  ea_list_len, PULONG  ea_index, BOOLEAN  restart) /* ../dlls/ntdll/file.c:3261 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryEaFile\n");
	return_value = pNtQueryEaFile(hFile, iosb, buffer, length, single_entry, ea_list, ea_list_len, ea_index, restart);
	TRACE("Leave NtQueryEaFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryEaFile(void);  /* ../dlls/ntdll/file.c:3261 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryEaFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryEaFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryEvent(HANDLE  handle, EVENT_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len) /* ../dlls/ntdll/sync.c:472 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryEvent\n");
	return_value = pNtQueryEvent(handle, class, info, len, ret_len);
	TRACE("Leave NtQueryEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryEvent(void);  /* ../dlls/ntdll/sync.c:472 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryFullAttributesFile(OBJECT_ATTRIBUTES*  attr, FILE_NETWORK_OPEN_INFORMATION*  info) /* ../dlls/ntdll/file.c:2833 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryFullAttributesFile\n");
	return_value = pNtQueryFullAttributesFile(attr, info);
	TRACE("Leave NtQueryFullAttributesFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryFullAttributesFile(void);  /* ../dlls/ntdll/file.c:2833 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryFullAttributesFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryFullAttributesFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationAtom(RTL_ATOM  atom, ATOM_INFORMATION_CLASS  class, PVOID  ptr, ULONG  size, PULONG  psize) /* ../dlls/ntdll/atom.c:379 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationAtom\n");
	return_value = pNtQueryInformationAtom(atom, class, ptr, size, psize);
	TRACE("Leave NtQueryInformationAtom\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationAtom(void);  /* ../dlls/ntdll/atom.c:379 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationAtom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationAtom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationFile(HANDLE  hFile, PIO_STATUS_BLOCK  io, PVOID  ptr, LONG  len, FILE_INFORMATION_CLASS  class) /* ../dlls/ntdll/file.c:2216 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationFile\n");
	return_value = pNtQueryInformationFile(hFile, io, ptr, len, class);
	TRACE("Leave NtQueryInformationFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationFile(void);  /* ../dlls/ntdll/file.c:2216 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationJobObject(HANDLE  handle, JOBOBJECTINFOCLASS  class, PVOID  info, ULONG  len, PULONG  ret_len) /* ../dlls/ntdll/sync.c:694 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationJobObject\n");
	return_value = pNtQueryInformationJobObject(handle, class, info, len, ret_len);
	TRACE("Leave NtQueryInformationJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationJobObject(void);  /* ../dlls/ntdll/sync.c:694 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationProcess(HANDLE  ProcessHandle, PROCESSINFOCLASS  ProcessInformationClass, PVOID  ProcessInformation, ULONG  ProcessInformationLength, PULONG  ReturnLength) /* ../dlls/ntdll/process.c:198 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationProcess\n");
	return_value = pNtQueryInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength, ReturnLength);
	TRACE("Leave NtQueryInformationProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationProcess(void);  /* ../dlls/ntdll/process.c:198 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationThread(HANDLE  handle, THREADINFOCLASS  class, void*  data, ULONG  length, ULONG*  ret_len) /* ../dlls/ntdll/thread.c:826 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationThread\n");
	return_value = pNtQueryInformationThread(handle, class, data, length, ret_len);
	TRACE("Leave NtQueryInformationThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationThread(void);  /* ../dlls/ntdll/thread.c:826 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInformationToken(HANDLE  token, TOKEN_INFORMATION_CLASS  tokeninfoclass, PVOID  tokeninfo, ULONG  tokeninfolength, PULONG  retlen) /* ../dlls/ntdll/nt.c:312 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInformationToken\n");
	return_value = pNtQueryInformationToken(token, tokeninfoclass, tokeninfo, tokeninfolength, retlen);
	TRACE("Leave NtQueryInformationToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInformationToken(void);  /* ../dlls/ntdll/nt.c:312 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInformationToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInformationToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryInstallUILanguage(LANGID*  lang) /* ../dlls/ntdll/resource.c:503 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryInstallUILanguage\n");
	return_value = pNtQueryInstallUILanguage(lang);
	TRACE("Leave NtQueryInstallUILanguage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryInstallUILanguage(void);  /* ../dlls/ntdll/resource.c:503 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryInstallUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryInstallUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryIoCompletion(HANDLE  CompletionPort, IO_COMPLETION_INFORMATION_CLASS  InformationClass, PVOID  CompletionInformation, ULONG  BufferLength, PULONG  RequiredLength) /* ../dlls/ntdll/sync.c:1488 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryIoCompletion\n");
	return_value = pNtQueryIoCompletion(CompletionPort, InformationClass, CompletionInformation, BufferLength, RequiredLength);
	TRACE("Leave NtQueryIoCompletion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryIoCompletion(void);  /* ../dlls/ntdll/sync.c:1488 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryKey(HANDLE  handle, KEY_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len) /* ../dlls/ntdll/reg.c:430 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryKey\n");
	return_value = pNtQueryKey(handle, info_class, info, length, result_len);
	TRACE("Leave NtQueryKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryKey(void);  /* ../dlls/ntdll/reg.c:430 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryLicenseValue(UNICODE_STRING*  name, ULONG*  result_type, PVOID  data, ULONG  length, ULONG*  result_len) /* ../dlls/ntdll/reg.c:1544 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryLicenseValue\n");
	return_value = pNtQueryLicenseValue(name, result_type, data, length, result_len);
	TRACE("Leave NtQueryLicenseValue\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryLicenseValue(void);  /* ../dlls/ntdll/reg.c:1544 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryLicenseValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryLicenseValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryMultipleValueKey(HANDLE  KeyHandle, PKEY_MULTIPLE_VALUE_INFORMATION  ListOfValuesToQuery, ULONG  NumberOfItems, PVOID  MultipleValueInformation, ULONG  Length, PULONG  ReturnLength) /* ../dlls/ntdll/reg.c:776 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryMultipleValueKey\n");
	return_value = pNtQueryMultipleValueKey(KeyHandle, ListOfValuesToQuery, NumberOfItems, MultipleValueInformation, Length, ReturnLength);
	TRACE("Leave NtQueryMultipleValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryMultipleValueKey(void);  /* ../dlls/ntdll/reg.c:776 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryMultipleValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryMultipleValueKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryMutant(HANDLE  handle, MUTANT_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len) /* ../dlls/ntdll/sync.c:583 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryMutant\n");
	return_value = pNtQueryMutant(handle, class, info, len, ret_len);
	TRACE("Leave NtQueryMutant\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryMutant(void);  /* ../dlls/ntdll/sync.c:583 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryObject(HANDLE  handle, OBJECT_INFORMATION_CLASS  info_class, PVOID  ptr, ULONG  len, PULONG  used_len) /* ../dlls/ntdll/om.c:51 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryObject\n");
	return_value = pNtQueryObject(handle, info_class, ptr, len, used_len);
	TRACE("Leave NtQueryObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryObject(void);  /* ../dlls/ntdll/om.c:51 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryPerformanceCounter(LARGE_INTEGER*  counter, LARGE_INTEGER*  frequency) /* ../dlls/ntdll/time.c:539 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryPerformanceCounter\n");
	return_value = pNtQueryPerformanceCounter(counter, frequency);
	TRACE("Leave NtQueryPerformanceCounter\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryPerformanceCounter(void);  /* ../dlls/ntdll/time.c:539 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryPerformanceCounter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryPerformanceCounter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySection(HANDLE  handle, SECTION_INFORMATION_CLASS  class, void*  ptr, SIZE_T  size, SIZE_T*  ret_size) /* ../dlls/ntdll/virtual.c:3341 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySection\n");
	return_value = pNtQuerySection(handle, class, ptr, size, ret_size);
	TRACE("Leave NtQuerySection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySection(void);  /* ../dlls/ntdll/virtual.c:3341 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySecurityObject(HANDLE  Object, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, ULONG  Length, PULONG  ResultLength) /* ../dlls/ntdll/om.c:265 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySecurityObject\n");
	return_value = pNtQuerySecurityObject(Object, RequestedInformation, pSecurityDescriptor, Length, ResultLength);
	TRACE("Leave NtQuerySecurityObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySecurityObject(void);  /* ../dlls/ntdll/om.c:265 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySecurityObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySemaphore(HANDLE  handle, SEMAPHORE_INFORMATION_CLASS  class, void*  info, ULONG  len, ULONG*  ret_len) /* ../dlls/ntdll/sync.c:295 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySemaphore\n");
	return_value = pNtQuerySemaphore(handle, class, info, len, ret_len);
	TRACE("Leave NtQuerySemaphore\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySemaphore(void);  /* ../dlls/ntdll/sync.c:295 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySymbolicLinkObject(HANDLE  handle, PUNICODE_STRING  target, PULONG  length) /* ../dlls/ntdll/om.c:686 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySymbolicLinkObject\n");
	return_value = pNtQuerySymbolicLinkObject(handle, target, length);
	TRACE("Leave NtQuerySymbolicLinkObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySymbolicLinkObject(void);  /* ../dlls/ntdll/om.c:686 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySymbolicLinkObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySymbolicLinkObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySystemEnvironmentValue(PUNICODE_STRING  VariableName, PWCHAR  Value, ULONG  ValueBufferLength, PULONG  RequiredLength) /* ../dlls/ntdll/env.c:54 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySystemEnvironmentValue\n");
	return_value = pNtQuerySystemEnvironmentValue(VariableName, Value, ValueBufferLength, RequiredLength);
	TRACE("Leave NtQuerySystemEnvironmentValue\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySystemEnvironmentValue(void);  /* ../dlls/ntdll/env.c:54 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySystemEnvironmentValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySystemEnvironmentValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySystemEnvironmentValueEx(PUNICODE_STRING  name, LPGUID  vendor, PVOID  value, PULONG  retlength, PULONG  attrib) /* ../dlls/ntdll/env.c:66 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySystemEnvironmentValueEx\n");
	return_value = pNtQuerySystemEnvironmentValueEx(name, vendor, value, retlength, attrib);
	TRACE("Leave NtQuerySystemEnvironmentValueEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySystemEnvironmentValueEx(void);  /* ../dlls/ntdll/env.c:66 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySystemEnvironmentValueEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySystemEnvironmentValueEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySystemInformation(SYSTEM_INFORMATION_CLASS  SystemInformationClass, PVOID  SystemInformation, ULONG  Length, PULONG  ResultLength) /* ../dlls/ntdll/nt.c:2377 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySystemInformation\n");
	return_value = pNtQuerySystemInformation(SystemInformationClass, SystemInformation, Length, ResultLength);
	TRACE("Leave NtQuerySystemInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySystemInformation(void);  /* ../dlls/ntdll/nt.c:2377 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySystemInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySystemInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQuerySystemInformationEx(SYSTEM_INFORMATION_CLASS  SystemInformationClass, void*  Query, ULONG  QueryLength, void*  SystemInformation, ULONG  Length, ULONG*  ResultLength) /* ../dlls/ntdll/nt.c:2940 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySystemInformationEx\n");
	return_value = pNtQuerySystemInformationEx(SystemInformationClass, Query, QueryLength, SystemInformation, Length, ResultLength);
	TRACE("Leave NtQuerySystemInformationEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySystemInformationEx(void);  /* ../dlls/ntdll/nt.c:2940 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySystemInformationEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySystemInformationEx") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQuerySystemTime(LARGE_INTEGER*  time) /* ../dlls/ntdll/time.c:467 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQuerySystemTime\n");
	return_value = pNtQuerySystemTime(time);
	TRACE("Leave NtQuerySystemTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQuerySystemTime(void);  /* ../dlls/ntdll/time.c:467 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQuerySystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQuerySystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryTimer(HANDLE  TimerHandle, TIMER_INFORMATION_CLASS  TimerInformationClass, PVOID  TimerInformation, ULONG  Length, PULONG  ReturnLength) /* ../dlls/ntdll/sync.c:997 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryTimer\n");
	return_value = pNtQueryTimer(TimerHandle, TimerInformationClass, TimerInformation, Length, ReturnLength);
	TRACE("Leave NtQueryTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryTimer(void);  /* ../dlls/ntdll/sync.c:997 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryTimerResolution(ULONG*  min_resolution, ULONG*  max_resolution, ULONG*  current_resolution) /* ../dlls/ntdll/sync.c:1048 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryTimerResolution\n");
	return_value = pNtQueryTimerResolution(min_resolution, max_resolution, current_resolution);
	TRACE("Leave NtQueryTimerResolution\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryTimerResolution(void);  /* ../dlls/ntdll/sync.c:1048 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryTimerResolution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryTimerResolution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueryValueKey(HANDLE  handle, UNICODE_STRING*  name, KEY_VALUE_INFORMATION_CLASS  info_class, void*  info, DWORD  length, DWORD*  result_len) /* ../dlls/ntdll/reg.c:533 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryValueKey\n");
	return_value = pNtQueryValueKey(handle, name, info_class, info, length, result_len);
	TRACE("Leave NtQueryValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryValueKey(void);  /* ../dlls/ntdll/reg.c:533 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryValueKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryVirtualMemory(HANDLE  process, LPCVOID  addr, MEMORY_INFORMATION_CLASS  info_class, PVOID  buffer, SIZE_T  len, SIZE_T*  res_len) /* ../dlls/ntdll/virtual.c:2904 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryVirtualMemory\n");
	return_value = pNtQueryVirtualMemory(process, addr, info_class, buffer, len, res_len);
	TRACE("Leave NtQueryVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:2904 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryVirtualMemory") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtQueryVolumeInformationFile(HANDLE  handle, PIO_STATUS_BLOCK  io, PVOID  buffer, ULONG  length, FS_INFORMATION_CLASS  info_class) /* ../dlls/ntdll/file.c:3100 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueryVolumeInformationFile\n");
	return_value = pNtQueryVolumeInformationFile(handle, io, buffer, length, info_class);
	TRACE("Leave NtQueryVolumeInformationFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueryVolumeInformationFile(void);  /* ../dlls/ntdll/file.c:3100 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueryVolumeInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueryVolumeInformationFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtQueueApcThread(HANDLE  handle, PNTAPCFUNC  func, ULONG_PTR  arg1, ULONG_PTR  arg2, ULONG_PTR  arg3) /* ../dlls/ntdll/thread.c:678 */
{
	NTSTATUS return_value;
	TRACE("Enter NtQueueApcThread\n");
	return_value = pNtQueueApcThread(handle, func, arg1, arg2, arg3);
	TRACE("Leave NtQueueApcThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtQueueApcThread(void);  /* ../dlls/ntdll/thread.c:678 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtQueueApcThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtQueueApcThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRaiseException(EXCEPTION_RECORD*  rec, CONTEXT*  context, BOOL  first_chance) /* ../dlls/ntdll/signal_x86_64.c:2650 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRaiseException\n");
	return_value = pNtRaiseException(rec, context, first_chance);
	TRACE("Leave NtRaiseException\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRaiseException(void);  /* ../dlls/ntdll/signal_x86_64.c:2650 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRaiseException,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRaiseException") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRaiseHardError(NTSTATUS  ErrorStatus, ULONG  NumberOfParameters, PUNICODE_STRING  UnicodeStringParameterMask, PVOID*  Parameters, HARDERROR_RESPONSE_OPTION  ResponseOption, PHARDERROR_RESPONSE  Response) /* ../dlls/ntdll/error.c:135 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRaiseHardError\n");
	return_value = pNtRaiseHardError(ErrorStatus, NumberOfParameters, UnicodeStringParameterMask, Parameters, ResponseOption, Response);
	TRACE("Leave NtRaiseHardError\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRaiseHardError(void);  /* ../dlls/ntdll/error.c:135 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRaiseHardError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRaiseHardError") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtReadFile(HANDLE  hFile, HANDLE  hEvent, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, void*  buffer, ULONG  length, PLARGE_INTEGER  offset, PULONG  key) /* ../dlls/ntdll/file.c:822 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReadFile\n");
	return_value = pNtReadFile(hFile, hEvent, apc, apc_user, io_status, buffer, length, offset, key);
	TRACE("Leave NtReadFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReadFile(void);  /* ../dlls/ntdll/file.c:822 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReadFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReadFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtReadFileScatter(HANDLE  file, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, FILE_SEGMENT_ELEMENT*  segments, ULONG  length, PLARGE_INTEGER  offset, PULONG  key) /* ../dlls/ntdll/file.c:1024 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReadFileScatter\n");
	return_value = pNtReadFileScatter(file, event, apc, apc_user, io_status, segments, length, offset, key);
	TRACE("Leave NtReadFileScatter\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReadFileScatter(void);  /* ../dlls/ntdll/file.c:1024 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReadFileScatter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReadFileScatter") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtReadVirtualMemory(HANDLE  process, void*  addr, void*  buffer, SIZE_T  size, SIZE_T*  bytes_read) /* ../dlls/ntdll/virtual.c:3517 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReadVirtualMemory\n");
	return_value = pNtReadVirtualMemory(process, addr, buffer, size, bytes_read);
	TRACE("Leave NtReadVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReadVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:3517 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReadVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReadVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRegisterThreadTerminatePort(HANDLE  PortHandle) /* ../dlls/ntdll/nt.c:868 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRegisterThreadTerminatePort\n");
	return_value = pNtRegisterThreadTerminatePort(PortHandle);
	TRACE("Leave NtRegisterThreadTerminatePort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRegisterThreadTerminatePort(void);  /* ../dlls/ntdll/nt.c:868 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRegisterThreadTerminatePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRegisterThreadTerminatePort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtReleaseKeyedEvent(HANDLE  handle, void*  key, BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1256 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReleaseKeyedEvent\n");
	return_value = pNtReleaseKeyedEvent(handle, key, alertable, timeout);
	TRACE("Leave NtReleaseKeyedEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReleaseKeyedEvent(void);  /* ../dlls/ntdll/sync.c:1256 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReleaseKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReleaseKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtReleaseMutant(HANDLE  handle, PLONG  prev_count) /* ../dlls/ntdll/sync.c:565 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReleaseMutant\n");
	return_value = pNtReleaseMutant(handle, prev_count);
	TRACE("Leave NtReleaseMutant\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReleaseMutant(void);  /* ../dlls/ntdll/sync.c:565 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReleaseMutant,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReleaseMutant") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtReleaseSemaphore(HANDLE  handle, ULONG  count, PULONG  previous) /* ../dlls/ntdll/sync.c:329 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReleaseSemaphore\n");
	return_value = pNtReleaseSemaphore(handle, count, previous);
	TRACE("Leave NtReleaseSemaphore\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReleaseSemaphore(void);  /* ../dlls/ntdll/sync.c:329 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReleaseSemaphore,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReleaseSemaphore") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRemoveIoCompletion(HANDLE  CompletionPort, PULONG_PTR  CompletionKey, PULONG_PTR  CompletionValue, PIO_STATUS_BLOCK  iosb, PLARGE_INTEGER  WaitTime) /* ../dlls/ntdll/sync.c:1361 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRemoveIoCompletion\n");
	return_value = pNtRemoveIoCompletion(CompletionPort, CompletionKey, CompletionValue, iosb, WaitTime);
	TRACE("Leave NtRemoveIoCompletion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRemoveIoCompletion(void);  /* ../dlls/ntdll/sync.c:1361 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRemoveIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRemoveIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRemoveIoCompletionEx(HANDLE  port, FILE_IO_COMPLETION_INFORMATION*  info, ULONG  count, ULONG*  written, LARGE_INTEGER*  timeout, BOOLEAN  alertable) /* ../dlls/ntdll/sync.c:1396 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRemoveIoCompletionEx\n");
	return_value = pNtRemoveIoCompletionEx(port, info, count, written, timeout, alertable);
	TRACE("Leave NtRemoveIoCompletionEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRemoveIoCompletionEx(void);  /* ../dlls/ntdll/sync.c:1396 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRemoveIoCompletionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRemoveIoCompletionEx") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtRenameKey(HANDLE  handle, UNICODE_STRING*  name) /* ../dlls/ntdll/reg.c:94 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRenameKey\n");
	return_value = pNtRenameKey(handle, name);
	TRACE("Leave NtRenameKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRenameKey(void);  /* ../dlls/ntdll/reg.c:94 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRenameKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRenameKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtReplaceKey(POBJECT_ATTRIBUTES  ObjectAttributes, HANDLE  Key, POBJECT_ATTRIBUTES  ReplacedObjectAttributes) /* ../dlls/ntdll/reg.c:794 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReplaceKey\n");
	return_value = pNtReplaceKey(ObjectAttributes, Key, ReplacedObjectAttributes);
	TRACE("Leave NtReplaceKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReplaceKey(void);  /* ../dlls/ntdll/reg.c:794 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReplaceKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReplaceKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtReplyWaitReceivePort(HANDLE  PortHandle, PULONG  PortIdentifier, PLPC_MESSAGE  ReplyMessage, PLPC_MESSAGE  Message) /* ../dlls/ntdll/nt.c:905 */
{
	NTSTATUS return_value;
	TRACE("Enter NtReplyWaitReceivePort\n");
	return_value = pNtReplyWaitReceivePort(PortHandle, PortIdentifier, ReplyMessage, Message);
	TRACE("Leave NtReplyWaitReceivePort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtReplyWaitReceivePort(void);  /* ../dlls/ntdll/nt.c:905 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtReplyWaitReceivePort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtReplyWaitReceivePort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRequestWaitReplyPort(HANDLE  PortHandle, PLPC_MESSAGE  pLpcMessageIn, PLPC_MESSAGE  pLpcMessageOut) /* ../dlls/ntdll/nt.c:878 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRequestWaitReplyPort\n");
	return_value = pNtRequestWaitReplyPort(PortHandle, pLpcMessageIn, pLpcMessageOut);
	TRACE("Leave NtRequestWaitReplyPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRequestWaitReplyPort(void);  /* ../dlls/ntdll/nt.c:878 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRequestWaitReplyPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRequestWaitReplyPort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtResetEvent(HANDLE  handle, LONG*  prev_state) /* ../dlls/ntdll/sync.c:423 */
{
	NTSTATUS return_value;
	TRACE("Enter NtResetEvent\n");
	return_value = pNtResetEvent(handle, prev_state);
	TRACE("Leave NtResetEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtResetEvent(void);  /* ../dlls/ntdll/sync.c:423 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtResetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtResetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtResetWriteWatch(HANDLE  process, PVOID  base, SIZE_T  size) /* ../dlls/ntdll/virtual.c:3489 */
{
	NTSTATUS return_value;
	TRACE("Enter NtResetWriteWatch\n");
	return_value = pNtResetWriteWatch(process, base, size);
	TRACE("Leave NtResetWriteWatch\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtResetWriteWatch(void);  /* ../dlls/ntdll/virtual.c:3489 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtResetWriteWatch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtResetWriteWatch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtRestoreKey(HANDLE  KeyHandle, HANDLE  FileHandle, ULONG  RestoreFlags) /* ../dlls/ntdll/reg.c:807 */
{
	NTSTATUS return_value;
	TRACE("Enter NtRestoreKey\n");
	return_value = pNtRestoreKey(KeyHandle, FileHandle, RestoreFlags);
	TRACE("Leave NtRestoreKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtRestoreKey(void);  /* ../dlls/ntdll/reg.c:807 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtRestoreKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtRestoreKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtResumeProcess(HANDLE  handle) /* ../dlls/ntdll/process.c:764 */
{
	NTSTATUS return_value;
	TRACE("Enter NtResumeProcess\n");
	return_value = pNtResumeProcess(handle);
	TRACE("Leave NtResumeProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtResumeProcess(void);  /* ../dlls/ntdll/process.c:764 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtResumeProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtResumeProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtResumeThread(HANDLE  handle, PULONG  count) /* ../dlls/ntdll/thread.c:613 */
{
	NTSTATUS return_value;
	TRACE("Enter NtResumeThread\n");
	return_value = pNtResumeThread(handle, count);
	TRACE("Leave NtResumeThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtResumeThread(void);  /* ../dlls/ntdll/thread.c:613 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtResumeThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtResumeThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSaveKey(HANDLE  KeyHandle, HANDLE  FileHandle) /* ../dlls/ntdll/reg.c:820 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSaveKey\n");
	return_value = pNtSaveKey(KeyHandle, FileHandle);
	TRACE("Leave NtSaveKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSaveKey(void);  /* ../dlls/ntdll/reg.c:820 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSaveKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSaveKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSecureConnectPort(PHANDLE  PortHandle, PUNICODE_STRING  PortName, PSECURITY_QUALITY_OF_SERVICE  SecurityQos, PLPC_SECTION_WRITE  WriteSection, PSID  pSid, PLPC_SECTION_READ  ReadSection, PULONG  MaximumMessageLength, PVOID  ConnectInfo, PULONG  pConnectInfoLength) /* ../dlls/ntdll/nt.c:809 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSecureConnectPort\n");
	return_value = pNtSecureConnectPort(PortHandle, PortName, SecurityQos, WriteSection, pSid, ReadSection, MaximumMessageLength, ConnectInfo, pConnectInfoLength);
	TRACE("Leave NtSecureConnectPort\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSecureConnectPort(void);  /* ../dlls/ntdll/nt.c:809 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSecureConnectPort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSecureConnectPort") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtSetContextThread(HANDLE  handle, CONTEXT*  context) /* ../dlls/ntdll/signal_x86_64.c:2172 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetContextThread\n");
	return_value = pNtSetContextThread(handle, context);
	TRACE("Leave NtSetContextThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetContextThread(void);  /* ../dlls/ntdll/signal_x86_64.c:2172 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetContextThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetContextThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetDefaultLocale(BOOLEAN  user, LCID  lcid) /* ../dlls/ntdll/resource.c:468 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetDefaultLocale\n");
	return_value = pNtSetDefaultLocale(user, lcid);
	TRACE("Leave NtSetDefaultLocale\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetDefaultLocale(void);  /* ../dlls/ntdll/resource.c:468 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetDefaultLocale,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetDefaultLocale") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetDefaultUILanguage(LANGID  lang) /* ../dlls/ntdll/resource.c:493 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetDefaultUILanguage\n");
	return_value = pNtSetDefaultUILanguage(lang);
	TRACE("Leave NtSetDefaultUILanguage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetDefaultUILanguage(void);  /* ../dlls/ntdll/resource.c:493 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetDefaultUILanguage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetDefaultUILanguage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetEaFile(HANDLE  hFile, PIO_STATUS_BLOCK  iosb, PVOID  buffer, ULONG  length) /* ../dlls/ntdll/file.c:3287 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetEaFile\n");
	return_value = pNtSetEaFile(hFile, iosb, buffer, length);
	TRACE("Leave NtSetEaFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetEaFile(void);  /* ../dlls/ntdll/file.c:3287 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetEaFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetEaFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetEvent(HANDLE  handle, LONG*  prev_state) /* ../dlls/ntdll/sync.c:406 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetEvent\n");
	return_value = pNtSetEvent(handle, prev_state);
	TRACE("Leave NtSetEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetEvent(void);  /* ../dlls/ntdll/sync.c:406 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationFile(HANDLE  handle, PIO_STATUS_BLOCK  io, PVOID  ptr, ULONG  len, FILE_INFORMATION_CLASS  class) /* ../dlls/ntdll/file.c:2501 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationFile\n");
	return_value = pNtSetInformationFile(handle, io, ptr, len, class);
	TRACE("Leave NtSetInformationFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationFile(void);  /* ../dlls/ntdll/file.c:2501 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationJobObject(HANDLE  handle, JOBOBJECTINFOCLASS  class, PVOID  info, ULONG  len) /* ../dlls/ntdll/sync.c:761 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationJobObject\n");
	return_value = pNtSetInformationJobObject(handle, class, info, len);
	TRACE("Leave NtSetInformationJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationJobObject(void);  /* ../dlls/ntdll/sync.c:761 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationKey(HANDLE  KeyHandle, int  KeyInformationClass, PVOID  KeyInformation, ULONG  KeyInformationLength) /* ../dlls/ntdll/reg.c:840 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationKey\n");
	return_value = pNtSetInformationKey(KeyHandle, KeyInformationClass, KeyInformation, KeyInformationLength);
	TRACE("Leave NtSetInformationKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationKey(void);  /* ../dlls/ntdll/reg.c:840 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationObject(HANDLE  handle, OBJECT_INFORMATION_CLASS  info_class, PVOID  ptr, ULONG  len) /* ../dlls/ntdll/om.c:222 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationObject\n");
	return_value = pNtSetInformationObject(handle, info_class, ptr, len);
	TRACE("Leave NtSetInformationObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationObject(void);  /* ../dlls/ntdll/om.c:222 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationProcess(HANDLE  ProcessHandle, PROCESSINFOCLASS  ProcessInformationClass, PVOID  ProcessInformation, ULONG  ProcessInformationLength) /* ../dlls/ntdll/process.c:628 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationProcess\n");
	return_value = pNtSetInformationProcess(ProcessHandle, ProcessInformationClass, ProcessInformation, ProcessInformationLength);
	TRACE("Leave NtSetInformationProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationProcess(void);  /* ../dlls/ntdll/process.c:628 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationThread(HANDLE  handle, THREADINFOCLASS  class, LPCVOID  data, ULONG  length) /* ../dlls/ntdll/thread.c:1088 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationThread\n");
	return_value = pNtSetInformationThread(handle, class, data, length);
	TRACE("Leave NtSetInformationThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationThread(void);  /* ../dlls/ntdll/thread.c:1088 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetInformationToken(HANDLE  TokenHandle, TOKEN_INFORMATION_CLASS  TokenInformationClass, PVOID  TokenInformation, ULONG  TokenInformationLength) /* ../dlls/ntdll/nt.c:657 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetInformationToken\n");
	return_value = pNtSetInformationToken(TokenHandle, TokenInformationClass, TokenInformation, TokenInformationLength);
	TRACE("Leave NtSetInformationToken\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetInformationToken(void);  /* ../dlls/ntdll/nt.c:657 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetInformationToken,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetInformationToken") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetIntervalProfile(ULONG  Interval, KPROFILE_SOURCE  Source) /* ../dlls/ntdll/nt.c:923 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetIntervalProfile\n");
	return_value = pNtSetIntervalProfile(Interval, Source);
	TRACE("Leave NtSetIntervalProfile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetIntervalProfile(void);  /* ../dlls/ntdll/nt.c:923 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetIntervalProfile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetIntervalProfile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetIoCompletion(HANDLE  CompletionPort, ULONG_PTR  CompletionKey, ULONG_PTR  CompletionValue, NTSTATUS  Status, SIZE_T  NumberOfBytesTransferred) /* ../dlls/ntdll/sync.c:1325 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetIoCompletion\n");
	return_value = pNtSetIoCompletion(CompletionPort, CompletionKey, CompletionValue, Status, NumberOfBytesTransferred);
	TRACE("Leave NtSetIoCompletion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetIoCompletion(void);  /* ../dlls/ntdll/sync.c:1325 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetIoCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetIoCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetLdtEntries(ULONG  selector1, ULONG  entry1_low, ULONG  entry1_high, ULONG  selector2, ULONG  entry2_low, ULONG  entry2_high) /* ../dlls/ntdll/nt.c:3429 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetLdtEntries\n");
	return_value = pNtSetLdtEntries(selector1, entry1_low, entry1_high, selector2, entry2_low, entry2_high);
	TRACE("Leave NtSetLdtEntries\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetLdtEntries(void);  /* ../dlls/ntdll/nt.c:3429 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetLdtEntries,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetLdtEntries") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtSetPowerRequest(HANDLE  handle, POWER_REQUEST_TYPE  type) /* ../dlls/ntdll/nt.c:3093 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetPowerRequest\n");
	return_value = pNtSetPowerRequest(handle, type);
	TRACE("Leave NtSetPowerRequest\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetPowerRequest(void);  /* ../dlls/ntdll/nt.c:3093 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetPowerRequest,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetPowerRequest") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetSecurityObject(HANDLE  Handle, SECURITY_INFORMATION  SecurityInformation, PSECURITY_DESCRIPTOR  SecurityDescriptor) /* ../dlls/ntdll/sec.c:1740 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetSecurityObject\n");
	return_value = pNtSetSecurityObject(Handle, SecurityInformation, SecurityDescriptor);
	TRACE("Leave NtSetSecurityObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetSecurityObject(void);  /* ../dlls/ntdll/sec.c:1740 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetSecurityObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetSystemInformation(SYSTEM_INFORMATION_CLASS  SystemInformationClass, PVOID  SystemInformation, ULONG  Length) /* ../dlls/ntdll/nt.c:3008 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetSystemInformation\n");
	return_value = pNtSetSystemInformation(SystemInformationClass, SystemInformation, Length);
	TRACE("Leave NtSetSystemInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetSystemInformation(void);  /* ../dlls/ntdll/nt.c:3008 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetSystemInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetSystemInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetSystemTime(LARGE_INTEGER*  NewTime, LARGE_INTEGER*  OldTime) /* ../dlls/ntdll/time.c:1074 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetSystemTime\n");
	return_value = pNtSetSystemTime(NewTime, OldTime);
	TRACE("Leave NtSetSystemTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetSystemTime(void);  /* ../dlls/ntdll/time.c:1074 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetThreadExecutionState(EXECUTION_STATE  new_state, EXECUTION_STATE*  old_state) /* ../dlls/ntdll/nt.c:3065 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetThreadExecutionState\n");
	return_value = pNtSetThreadExecutionState(new_state, old_state);
	TRACE("Leave NtSetThreadExecutionState\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetThreadExecutionState(void);  /* ../dlls/ntdll/nt.c:3065 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetThreadExecutionState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetThreadExecutionState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetTimer(HANDLE  handle, LARGE_INTEGER*  when, PTIMER_APC_ROUTINE  callback, PVOID  callback_arg, BOOLEAN  resume, ULONG  period, PBOOLEAN  state) /* ../dlls/ntdll/sync.c:929 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetTimer\n");
	return_value = pNtSetTimer(handle, when, callback, callback_arg, resume, period, state);
	TRACE("Leave NtSetTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetTimer(void);  /* ../dlls/ntdll/sync.c:929 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetTimer") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtSetTimerResolution(ULONG  resolution, BOOLEAN  set_resolution, ULONG*  current_resolution) /* ../dlls/ntdll/sync.c:1061 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetTimerResolution\n");
	return_value = pNtSetTimerResolution(resolution, set_resolution, current_resolution);
	TRACE("Leave NtSetTimerResolution\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetTimerResolution(void);  /* ../dlls/ntdll/sync.c:1061 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetTimerResolution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetTimerResolution") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSetValueKey(HANDLE  hkey, UNICODE_STRING*  name, ULONG  TitleIndex, ULONG  type, void*  data, ULONG  count) /* ../dlls/ntdll/reg.c:860 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetValueKey\n");
	return_value = pNtSetValueKey(hkey, name, TitleIndex, type, data, count);
	TRACE("Leave NtSetValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetValueKey(void);  /* ../dlls/ntdll/reg.c:860 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetValueKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtSetVolumeInformationFile(HANDLE  FileHandle, PIO_STATUS_BLOCK  IoStatusBlock, PVOID  FsInformation, ULONG  Length, FS_INFORMATION_CLASS  FsInformationClass) /* ../dlls/ntdll/file.c:1886 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSetVolumeInformationFile\n");
	return_value = pNtSetVolumeInformationFile(FileHandle, IoStatusBlock, FsInformation, Length, FsInformationClass);
	TRACE("Leave NtSetVolumeInformationFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSetVolumeInformationFile(void);  /* ../dlls/ntdll/file.c:1886 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSetVolumeInformationFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSetVolumeInformationFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtShutdownSystem(SHUTDOWN_ACTION  Action) /* ../dlls/ntdll/nt.c:3334 */
{
	NTSTATUS return_value;
	TRACE("Enter NtShutdownSystem\n");
	return_value = pNtShutdownSystem(Action);
	TRACE("Leave NtShutdownSystem\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtShutdownSystem(void);  /* ../dlls/ntdll/nt.c:3334 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtShutdownSystem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtShutdownSystem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSignalAndWaitForSingleObject(HANDLE  hSignalObject, HANDLE  hWaitObject, BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1114 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSignalAndWaitForSingleObject\n");
	return_value = pNtSignalAndWaitForSingleObject(hSignalObject, hWaitObject, alertable, timeout);
	TRACE("Leave NtSignalAndWaitForSingleObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSignalAndWaitForSingleObject(void);  /* ../dlls/ntdll/sync.c:1114 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSignalAndWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSignalAndWaitForSingleObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSuspendProcess(HANDLE  handle) /* ../dlls/ntdll/process.c:782 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSuspendProcess\n");
	return_value = pNtSuspendProcess(handle);
	TRACE("Leave NtSuspendProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSuspendProcess(void);  /* ../dlls/ntdll/process.c:782 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSuspendProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSuspendProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSuspendThread(HANDLE  handle, PULONG  count) /* ../dlls/ntdll/thread.c:592 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSuspendThread\n");
	return_value = pNtSuspendThread(handle, count);
	TRACE("Leave NtSuspendThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSuspendThread(void);  /* ../dlls/ntdll/thread.c:592 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSuspendThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSuspendThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtSystemDebugControl(SYSDBG_COMMAND  command, PVOID  inbuffer, ULONG  inbuflength, PVOID  outbuffer, ULONG  outbuflength, PULONG  retlength) /* ../dlls/ntdll/nt.c:3417 */
{
	NTSTATUS return_value;
	TRACE("Enter NtSystemDebugControl\n");
	return_value = pNtSystemDebugControl(command, inbuffer, inbuflength, outbuffer, outbuflength, retlength);
	TRACE("Leave NtSystemDebugControl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtSystemDebugControl(void);  /* ../dlls/ntdll/nt.c:3417 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtSystemDebugControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtSystemDebugControl") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtTerminateJobObject(HANDLE  handle, NTSTATUS  status) /* ../dlls/ntdll/sync.c:673 */
{
	NTSTATUS return_value;
	TRACE("Enter NtTerminateJobObject\n");
	return_value = pNtTerminateJobObject(handle, status);
	TRACE("Leave NtTerminateJobObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtTerminateJobObject(void);  /* ../dlls/ntdll/sync.c:673 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtTerminateJobObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtTerminateJobObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtTerminateProcess(HANDLE  handle, LONG  exit_code) /* ../dlls/ntdll/process.c:79 */
{
	NTSTATUS return_value;
	TRACE("Enter NtTerminateProcess\n");
	return_value = pNtTerminateProcess(handle, exit_code);
	TRACE("Leave NtTerminateProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtTerminateProcess(void);  /* ../dlls/ntdll/process.c:79 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtTerminateProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtTerminateProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtTerminateThread(HANDLE  handle, LONG  exit_code) /* ../dlls/ntdll/thread.c:656 */
{
	NTSTATUS return_value;
	TRACE("Enter NtTerminateThread\n");
	return_value = pNtTerminateThread(handle, exit_code);
	TRACE("Leave NtTerminateThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtTerminateThread(void);  /* ../dlls/ntdll/thread.c:656 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtTerminateThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtTerminateThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtUnloadDriver(UNICODE_STRING*  DriverServiceName) /* ../dlls/ntdll/loader.c:3983 */
{
	NTSTATUS return_value;
	TRACE("Enter NtUnloadDriver\n");
	return_value = pNtUnloadDriver(DriverServiceName);
	TRACE("Leave NtUnloadDriver\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtUnloadDriver(void);  /* ../dlls/ntdll/loader.c:3983 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtUnloadDriver,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtUnloadDriver") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtUnloadKey(POBJECT_ATTRIBUTES  attr) /* ../dlls/ntdll/reg.c:899 */
{
	NTSTATUS return_value;
	TRACE("Enter NtUnloadKey\n");
	return_value = pNtUnloadKey(attr);
	TRACE("Leave NtUnloadKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtUnloadKey(void);  /* ../dlls/ntdll/reg.c:899 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtUnloadKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtUnloadKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtUnlockFile(HANDLE  hFile, PIO_STATUS_BLOCK  io_status, PLARGE_INTEGER  offset, PLARGE_INTEGER  count, PULONG  key) /* ../dlls/ntdll/file.c:3432 */
{
	NTSTATUS return_value;
	TRACE("Enter NtUnlockFile\n");
	return_value = pNtUnlockFile(hFile, io_status, offset, count, key);
	TRACE("Leave NtUnlockFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtUnlockFile(void);  /* ../dlls/ntdll/file.c:3432 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtUnlockFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtUnlockFile") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtUnlockVirtualMemory(HANDLE  process, PVOID*  addr, SIZE_T*  size, ULONG  unknown) /* ../dlls/ntdll/virtual.c:3084 */
{
	NTSTATUS return_value;
	TRACE("Enter NtUnlockVirtualMemory\n");
	return_value = pNtUnlockVirtualMemory(process, addr, size, unknown);
	TRACE("Leave NtUnlockVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtUnlockVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:3084 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtUnlockVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtUnlockVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtUnmapViewOfSection(HANDLE  process, PVOID  addr) /* ../dlls/ntdll/virtual.c:3259 */
{
	NTSTATUS return_value;
	TRACE("Enter NtUnmapViewOfSection\n");
	return_value = pNtUnmapViewOfSection(process, addr);
	TRACE("Leave NtUnmapViewOfSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtUnmapViewOfSection(void);  /* ../dlls/ntdll/virtual.c:3259 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtUnmapViewOfSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtUnmapViewOfSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtWaitForKeyedEvent(HANDLE  handle, void*  key, BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1238 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWaitForKeyedEvent\n");
	return_value = pNtWaitForKeyedEvent(handle, key, alertable, timeout);
	TRACE("Leave NtWaitForKeyedEvent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWaitForKeyedEvent(void);  /* ../dlls/ntdll/sync.c:1238 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWaitForKeyedEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWaitForKeyedEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtWaitForMultipleObjects(DWORD  count, HANDLE*  handles, BOOLEAN  wait_any, BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1094 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWaitForMultipleObjects\n");
	return_value = pNtWaitForMultipleObjects(count, handles, wait_any, alertable, timeout);
	TRACE("Leave NtWaitForMultipleObjects\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWaitForMultipleObjects(void);  /* ../dlls/ntdll/sync.c:1094 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWaitForMultipleObjects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWaitForMultipleObjects") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtWaitForSingleObject(HANDLE  handle, BOOLEAN  alertable, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:1105 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWaitForSingleObject\n");
	return_value = pNtWaitForSingleObject(handle, alertable, timeout);
	TRACE("Leave NtWaitForSingleObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWaitForSingleObject(void);  /* ../dlls/ntdll/sync.c:1105 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWaitForSingleObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWaitForSingleObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtWriteFile(HANDLE  hFile, HANDLE  hEvent, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, void*  buffer, ULONG  length, PLARGE_INTEGER  offset, PULONG  key) /* ../dlls/ntdll/file.c:1189 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWriteFile\n");
	return_value = pNtWriteFile(hFile, hEvent, apc, apc_user, io_status, buffer, length, offset, key);
	TRACE("Leave NtWriteFile\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWriteFile(void);  /* ../dlls/ntdll/file.c:1189 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWriteFile,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWriteFile") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtWriteFileGather(HANDLE  file, HANDLE  event, PIO_APC_ROUTINE  apc, void*  apc_user, PIO_STATUS_BLOCK  io_status, FILE_SEGMENT_ELEMENT*  segments, ULONG  length, PLARGE_INTEGER  offset, PULONG  key) /* ../dlls/ntdll/file.c:1419 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWriteFileGather\n");
	return_value = pNtWriteFileGather(file, event, apc, apc_user, io_status, segments, length, offset, key);
	TRACE("Leave NtWriteFileGather\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWriteFileGather(void);  /* ../dlls/ntdll/file.c:1419 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWriteFileGather,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWriteFileGather") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_NtWriteVirtualMemory(HANDLE  process, void*  addr, void*  buffer, SIZE_T  size, SIZE_T*  bytes_written) /* ../dlls/ntdll/virtual.c:3547 */
{
	NTSTATUS return_value;
	TRACE("Enter NtWriteVirtualMemory\n");
	return_value = pNtWriteVirtualMemory(process, addr, buffer, size, bytes_written);
	TRACE("Leave NtWriteVirtualMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtWriteVirtualMemory(void);  /* ../dlls/ntdll/virtual.c:3547 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtWriteVirtualMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtWriteVirtualMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_NtYieldExecution(void) /* ../dlls/ntdll/sync.c:1133 */
{
	NTSTATUS return_value;
	TRACE("Enter NtYieldExecution\n");
	return_value = pNtYieldExecution();
	TRACE("Leave NtYieldExecution\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_NtYieldExecution(void);  /* ../dlls/ntdll/sync.c:1133 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_NtYieldExecution,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_NtYieldExecution") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAbsoluteToSelfRelativeSD(PSECURITY_DESCRIPTOR  AbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR  SelfRelativeSecurityDescriptor, PULONG  BufferLength) /* ../dlls/ntdll/sec.c:1095 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAbsoluteToSelfRelativeSD\n");
	return_value = pRtlAbsoluteToSelfRelativeSD(AbsoluteSecurityDescriptor, SelfRelativeSecurityDescriptor, BufferLength);
	TRACE("Leave RtlAbsoluteToSelfRelativeSD\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAbsoluteToSelfRelativeSD(void);  /* ../dlls/ntdll/sec.c:1095 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAbsoluteToSelfRelativeSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAbsoluteToSelfRelativeSD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlAcquirePebLock(void) /* ../dlls/ntdll/rtl.c:363 */
{
	TRACE("Enter RtlAcquirePebLock\n");
	pRtlAcquirePebLock();
	TRACE("Leave RtlAcquirePebLock\n");
}

extern WINAPI void wine32a_ntdll_RtlAcquirePebLock(void);  /* ../dlls/ntdll/rtl.c:363 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAcquirePebLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAcquirePebLock") "\n"
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

WINAPI BYTE wine32b_ntdll_RtlAcquireResourceExclusive(LPRTL_RWLOCK  rwl, BYTE  fWait) /* ../dlls/ntdll/rtl.c:153 */
{
	BYTE return_value;
	TRACE("Enter RtlAcquireResourceExclusive\n");
	return_value = pRtlAcquireResourceExclusive(rwl, fWait);
	TRACE("Leave RtlAcquireResourceExclusive\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAcquireResourceExclusive(void);  /* ../dlls/ntdll/rtl.c:153 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAcquireResourceExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAcquireResourceExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BYTE wine32b_ntdll_RtlAcquireResourceShared(LPRTL_RWLOCK  rwl, BYTE  fWait) /* ../dlls/ntdll/rtl.c:201 */
{
	BYTE return_value;
	TRACE("Enter RtlAcquireResourceShared\n");
	return_value = pRtlAcquireResourceShared(rwl, fWait);
	TRACE("Leave RtlAcquireResourceShared\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAcquireResourceShared(void);  /* ../dlls/ntdll/rtl.c:201 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAcquireResourceShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAcquireResourceShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlAcquireSRWLockExclusive(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2070 */
{
	TRACE("Enter RtlAcquireSRWLockExclusive\n");
	pRtlAcquireSRWLockExclusive(lock);
	TRACE("Leave RtlAcquireSRWLockExclusive\n");
}

extern WINAPI void wine32a_ntdll_RtlAcquireSRWLockExclusive(void);  /* ../dlls/ntdll/sync.c:2070 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAcquireSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAcquireSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlAcquireSRWLockShared(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2086 */
{
	TRACE("Enter RtlAcquireSRWLockShared\n");
	pRtlAcquireSRWLockShared(lock);
	TRACE("Leave RtlAcquireSRWLockShared\n");
}

extern WINAPI void wine32a_ntdll_RtlAcquireSRWLockShared(void);  /* ../dlls/ntdll/sync.c:2086 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAcquireSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAcquireSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlActivateActivationContext(ULONG  unknown, HANDLE  handle, PULONG_PTR  cookie) /* ../dlls/ntdll/actctx.c:5124 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlActivateActivationContext\n");
	return_value = pRtlActivateActivationContext(unknown, handle, cookie);
	TRACE("Leave RtlActivateActivationContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlActivateActivationContext(void);  /* ../dlls/ntdll/actctx.c:5124 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlActivateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlActivateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessAllowedAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  AccessMask, PSID  pSid) /* ../dlls/ntdll/sec.c:1236 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessAllowedAce\n");
	return_value = pRtlAddAccessAllowedAce(pAcl, dwAceRevision, AccessMask, pSid);
	TRACE("Leave RtlAddAccessAllowedAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessAllowedAce(void);  /* ../dlls/ntdll/sec.c:1236 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessAllowedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessAllowedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessAllowedAceEx(PACL  pAcl, DWORD  dwAceRevision, DWORD  AceFlags, DWORD  AccessMask, PSID  pSid) /* ../dlls/ntdll/sec.c:1248 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessAllowedAceEx\n");
	return_value = pRtlAddAccessAllowedAceEx(pAcl, dwAceRevision, AceFlags, AccessMask, pSid);
	TRACE("Leave RtlAddAccessAllowedAceEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessAllowedAceEx(void);  /* ../dlls/ntdll/sec.c:1248 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessAllowedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessAllowedAceEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessAllowedObjectAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid) /* ../dlls/ntdll/sec.c:1264 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessAllowedObjectAce\n");
	return_value = pRtlAddAccessAllowedObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid);
	TRACE("Leave RtlAddAccessAllowedObjectAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessAllowedObjectAce(void);  /* ../dlls/ntdll/sec.c:1264 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessAllowedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessAllowedObjectAce") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessDeniedAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  AccessMask, PSID  pSid) /* ../dlls/ntdll/sec.c:1281 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessDeniedAce\n");
	return_value = pRtlAddAccessDeniedAce(pAcl, dwAceRevision, AccessMask, pSid);
	TRACE("Leave RtlAddAccessDeniedAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessDeniedAce(void);  /* ../dlls/ntdll/sec.c:1281 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessDeniedAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessDeniedAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessDeniedAceEx(PACL  pAcl, DWORD  dwAceRevision, DWORD  AceFlags, DWORD  AccessMask, PSID  pSid) /* ../dlls/ntdll/sec.c:1293 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessDeniedAceEx\n");
	return_value = pRtlAddAccessDeniedAceEx(pAcl, dwAceRevision, AceFlags, AccessMask, pSid);
	TRACE("Leave RtlAddAccessDeniedAceEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessDeniedAceEx(void);  /* ../dlls/ntdll/sec.c:1293 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessDeniedAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessDeniedAceEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAccessDeniedObjectAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid) /* ../dlls/ntdll/sec.c:1309 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAccessDeniedObjectAce\n");
	return_value = pRtlAddAccessDeniedObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid);
	TRACE("Leave RtlAddAccessDeniedObjectAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAccessDeniedObjectAce(void);  /* ../dlls/ntdll/sec.c:1309 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAccessDeniedObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAccessDeniedObjectAce") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAddAce(PACL  acl, DWORD  rev, DWORD  xnrofaces, PACE_HEADER  acestart, DWORD  acelen) /* ../dlls/ntdll/sec.c:1169 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAce\n");
	return_value = pRtlAddAce(acl, rev, xnrofaces, acestart, acelen);
	TRACE("Leave RtlAddAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAce(void);  /* ../dlls/ntdll/sec.c:1169 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAtomToAtomTable(RTL_ATOM_TABLE  table, WCHAR*  name, RTL_ATOM*  atom) /* ../dlls/ntdll/atom.c:208 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAtomToAtomTable\n");
	return_value = pRtlAddAtomToAtomTable(table, name, atom);
	TRACE("Leave RtlAddAtomToAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAtomToAtomTable(void);  /* ../dlls/ntdll/atom.c:208 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAtomToAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAtomToAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAddAuditAccessAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAccessMask, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure) /* ../dlls/ntdll/sec.c:1351 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAuditAccessAce\n");
	return_value = pRtlAddAuditAccessAce(pAcl, dwAceRevision, dwAccessMask, pSid, bAuditSuccess, bAuditFailure);
	TRACE("Leave RtlAddAuditAccessAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAuditAccessAce(void);  /* ../dlls/ntdll/sec.c:1351 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAuditAccessAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAuditAccessAce") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAddAuditAccessAceEx(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure) /* ../dlls/ntdll/sec.c:1326 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAuditAccessAceEx\n");
	return_value = pRtlAddAuditAccessAceEx(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pSid, bAuditSuccess, bAuditFailure);
	TRACE("Leave RtlAddAuditAccessAceEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAuditAccessAceEx(void);  /* ../dlls/ntdll/sec.c:1326 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAuditAccessAceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAuditAccessAceEx") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAddAuditAccessObjectAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwAccessMask, GUID*  pObjectTypeGuid, GUID*  pInheritedObjectTypeGuid, PSID  pSid, BOOL  bAuditSuccess, BOOL  bAuditFailure) /* ../dlls/ntdll/sec.c:1365 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddAuditAccessObjectAce\n");
	return_value = pRtlAddAuditAccessObjectAce(pAcl, dwAceRevision, dwAceFlags, dwAccessMask, pObjectTypeGuid, pInheritedObjectTypeGuid, pSid, bAuditSuccess, bAuditFailure);
	TRACE("Leave RtlAddAuditAccessObjectAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddAuditAccessObjectAce(void);  /* ../dlls/ntdll/sec.c:1365 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddAuditAccessObjectAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddAuditAccessObjectAce") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlAddMandatoryAce(PACL  pAcl, DWORD  dwAceRevision, DWORD  dwAceFlags, DWORD  dwMandatoryFlags, DWORD  dwAceType, PSID  pSid) /* ../dlls/ntdll/sec.c:1384 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAddMandatoryAce\n");
	return_value = pRtlAddMandatoryAce(pAcl, dwAceRevision, dwAceFlags, dwMandatoryFlags, dwAceType, pSid);
	TRACE("Leave RtlAddMandatoryAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddMandatoryAce(void);  /* ../dlls/ntdll/sec.c:1384 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddMandatoryAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddMandatoryAce") "\n"
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

WINAPI BOOLEAN wine32b_ntdll_RtlAddFunctionTable(RUNTIME_FUNCTION*  table, DWORD  count, ULONG_PTR  addr) /* ../dlls/ntdll/exception.c:398 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlAddFunctionTable\n");
	return_value = pRtlAddFunctionTable(table, count, addr);
	TRACE("Leave RtlAddFunctionTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddFunctionTable(void);  /* ../dlls/ntdll/exception.c:398 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlAddGrowableFunctionTable(void**  table, RUNTIME_FUNCTION*  functions, DWORD  count, DWORD  max_count, ULONG_PTR  base, ULONG_PTR  end) /* ../dlls/ntdll/exception.c:465 */
{
	DWORD return_value;
	TRACE("Enter RtlAddGrowableFunctionTable\n");
	return_value = pRtlAddGrowableFunctionTable(table, functions, count, max_count, base, end);
	TRACE("Leave RtlAddGrowableFunctionTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddGrowableFunctionTable(void);  /* ../dlls/ntdll/exception.c:465 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddGrowableFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddGrowableFunctionTable") "\n"
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

WINAPI void wine32b_ntdll_RtlAddRefActivationContext(HANDLE  handle) /* ../dlls/ntdll/actctx.c:5092 */
{
	TRACE("Enter RtlAddRefActivationContext\n");
	pRtlAddRefActivationContext(handle);
	TRACE("Leave RtlAddRefActivationContext\n");
}

extern WINAPI void wine32a_ntdll_RtlAddRefActivationContext(void);  /* ../dlls/ntdll/actctx.c:5092 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddRefActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddRefActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlAddVectoredContinueHandler(ULONG  first, PVECTORED_EXCEPTION_HANDLER  func) /* ../dlls/ntdll/exception.c:280 */
{
	PVOID return_value;
	TRACE("Enter RtlAddVectoredContinueHandler\n");
	return_value = pRtlAddVectoredContinueHandler(first, func);
	TRACE("Leave RtlAddVectoredContinueHandler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddVectoredContinueHandler(void);  /* ../dlls/ntdll/exception.c:280 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddVectoredContinueHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddVectoredContinueHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlAddVectoredExceptionHandler(ULONG  first, PVECTORED_EXCEPTION_HANDLER  func) /* ../dlls/ntdll/exception.c:298 */
{
	PVOID return_value;
	TRACE("Enter RtlAddVectoredExceptionHandler\n");
	return_value = pRtlAddVectoredExceptionHandler(first, func);
	TRACE("Leave RtlAddVectoredExceptionHandler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAddVectoredExceptionHandler(void);  /* ../dlls/ntdll/exception.c:298 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAddVectoredExceptionHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAddVectoredExceptionHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAdjustPrivilege(ULONG  Privilege, BOOLEAN  Enable, BOOLEAN  CurrentThread, PBOOLEAN  Enabled) /* ../dlls/ntdll/sec.c:1494 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAdjustPrivilege\n");
	return_value = pRtlAdjustPrivilege(Privilege, Enable, CurrentThread, Enabled);
	TRACE("Leave RtlAdjustPrivilege\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAdjustPrivilege(void);  /* ../dlls/ntdll/sec.c:1494 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAdjustPrivilege,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAdjustPrivilege") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY  pIdentifierAuthority, BYTE  nSubAuthorityCount, DWORD  nSubAuthority0, DWORD  nSubAuthority1, DWORD  nSubAuthority2, DWORD  nSubAuthority3, DWORD  nSubAuthority4, DWORD  nSubAuthority5, DWORD  nSubAuthority6, DWORD  nSubAuthority7, PSID*  pSid) /* ../dlls/ntdll/sec.c:136 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAllocateAndInitializeSid\n");
	return_value = pRtlAllocateAndInitializeSid(pIdentifierAuthority, nSubAuthorityCount, nSubAuthority0, nSubAuthority1, nSubAuthority2, nSubAuthority3, nSubAuthority4, nSubAuthority5, nSubAuthority6, nSubAuthority7, pSid);
	TRACE("Leave RtlAllocateAndInitializeSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAllocateAndInitializeSid(void);  /* ../dlls/ntdll/sec.c:136 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAllocateAndInitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAllocateAndInitializeSid") "\n"
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

WINAPI RTL_HANDLE* wine32b_ntdll_RtlAllocateHandle(RTL_HANDLE_TABLE*  HandleTable, ULONG*  HandleIndex) /* ../dlls/ntdll/handletable.c:202 */
{
	RTL_HANDLE* return_value;
	TRACE("Enter RtlAllocateHandle\n");
	return_value = pRtlAllocateHandle(HandleTable, HandleIndex);
	TRACE("Leave RtlAllocateHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAllocateHandle(void);  /* ../dlls/ntdll/handletable.c:202 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAllocateHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAllocateHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlAllocateHeap(HANDLE  heap, ULONG  flags, SIZE_T  size) /* ../dlls/ntdll/heap.c:1664 */
{
	PVOID return_value;
	TRACE("Enter RtlAllocateHeap\n");
	return_value = pRtlAllocateHeap(heap, flags, size);
	TRACE("Leave RtlAllocateHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAllocateHeap(void);  /* ../dlls/ntdll/heap.c:1664 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAllocateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAllocateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI WCHAR wine32b_ntdll_RtlAnsiCharToUnicodeChar(LPSTR*  ansi) /* ../dlls/ntdll/rtlstr.c:651 */
{
	WCHAR return_value;
	TRACE("Enter RtlAnsiCharToUnicodeChar\n");
	return_value = pRtlAnsiCharToUnicodeChar(ansi);
	TRACE("Leave RtlAnsiCharToUnicodeChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAnsiCharToUnicodeChar(void);  /* ../dlls/ntdll/rtlstr.c:651 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAnsiCharToUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAnsiCharToUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlAnsiStringToUnicodeSize(STRING*  str) /* ../dlls/ntdll/rtlstr.c:1311 */
{
	DWORD return_value;
	TRACE("Enter RtlAnsiStringToUnicodeSize\n");
	return_value = pRtlAnsiStringToUnicodeSize(str);
	TRACE("Leave RtlAnsiStringToUnicodeSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAnsiStringToUnicodeSize(void);  /* ../dlls/ntdll/rtlstr.c:1311 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAnsiStringToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAnsiStringToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAnsiStringToUnicodeString(PUNICODE_STRING  uni, PCANSI_STRING  ansi, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:685 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAnsiStringToUnicodeString\n");
	return_value = pRtlAnsiStringToUnicodeString(uni, ansi, doalloc);
	TRACE("Leave RtlAnsiStringToUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAnsiStringToUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:685 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAnsiStringToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAnsiStringToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAppendAsciizToString(STRING*  dest, LPCSTR  src) /* ../dlls/ntdll/rtlstr.c:1417 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAppendAsciizToString\n");
	return_value = pRtlAppendAsciizToString(dest, src);
	TRACE("Leave RtlAppendAsciizToString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAppendAsciizToString(void);  /* ../dlls/ntdll/rtlstr.c:1417 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAppendAsciizToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAppendAsciizToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAppendStringToString(STRING*  dest, STRING*  src) /* ../dlls/ntdll/rtlstr.c:1447 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAppendStringToString\n");
	return_value = pRtlAppendStringToString(dest, src);
	TRACE("Leave RtlAppendStringToString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAppendStringToString(void);  /* ../dlls/ntdll/rtlstr.c:1447 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAppendStringToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAppendStringToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAppendUnicodeStringToString(UNICODE_STRING*  dest, UNICODE_STRING*  src) /* ../dlls/ntdll/rtlstr.c:1521 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAppendUnicodeStringToString\n");
	return_value = pRtlAppendUnicodeStringToString(dest, src);
	TRACE("Leave RtlAppendUnicodeStringToString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAppendUnicodeStringToString(void);  /* ../dlls/ntdll/rtlstr.c:1521 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAppendUnicodeStringToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAppendUnicodeStringToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlAppendUnicodeToString(UNICODE_STRING*  dest, LPCWSTR  src) /* ../dlls/ntdll/rtlstr.c:1482 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlAppendUnicodeToString\n");
	return_value = pRtlAppendUnicodeToString(dest, src);
	TRACE("Leave RtlAppendUnicodeToString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAppendUnicodeToString(void);  /* ../dlls/ntdll/rtlstr.c:1482 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAppendUnicodeToString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAppendUnicodeToString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlAreAllAccessesGranted(ACCESS_MASK  GrantedAccess, ACCESS_MASK  DesiredAccess) /* ../dlls/ntdll/rtl.c:763 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlAreAllAccessesGranted\n");
	return_value = pRtlAreAllAccessesGranted(GrantedAccess, DesiredAccess);
	TRACE("Leave RtlAreAllAccessesGranted\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAreAllAccessesGranted(void);  /* ../dlls/ntdll/rtl.c:763 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAreAllAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAreAllAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlAreAnyAccessesGranted(ACCESS_MASK  GrantedAccess, ACCESS_MASK  DesiredAccess) /* ../dlls/ntdll/rtl.c:784 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlAreAnyAccessesGranted\n");
	return_value = pRtlAreAnyAccessesGranted(GrantedAccess, DesiredAccess);
	TRACE("Leave RtlAreAnyAccessesGranted\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAreAnyAccessesGranted(void);  /* ../dlls/ntdll/rtl.c:784 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAreAnyAccessesGranted,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAreAnyAccessesGranted") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlAreBitsClear(PCRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount) /* ../dlls/ntdll/rtlbitmap.c:325 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlAreBitsClear\n");
	return_value = pRtlAreBitsClear(lpBits, ulStart, ulCount);
	TRACE("Leave RtlAreBitsClear\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAreBitsClear(void);  /* ../dlls/ntdll/rtlbitmap.c:325 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAreBitsClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAreBitsClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlAreBitsSet(PCRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount) /* ../dlls/ntdll/rtlbitmap.c:252 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlAreBitsSet\n");
	return_value = pRtlAreBitsSet(lpBits, ulStart, ulCount);
	TRACE("Leave RtlAreBitsSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlAreBitsSet(void);  /* ../dlls/ntdll/rtlbitmap.c:252 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAreBitsSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAreBitsSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlAssert(void*  assertion, void*  filename, ULONG  linenumber, char*  message) /* ../dlls/ntdll/rtl.c:549 */
{
	TRACE("Enter RtlAssert\n");
	pRtlAssert(assertion, filename, linenumber, message);
	TRACE("Leave RtlAssert\n");
}

extern WINAPI void wine32a_ntdll_RtlAssert(void);  /* ../dlls/ntdll/rtl.c:549 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlAssert,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlAssert") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI USHORT wine32b_ntdll_RtlCaptureStackBackTrace(ULONG  skip, ULONG  count, PVOID*  buffer, ULONG*  hash) /* ../dlls/ntdll/signal_x86_64.c:4123 */
{
	USHORT return_value;
	TRACE("Enter RtlCaptureStackBackTrace\n");
	return_value = pRtlCaptureStackBackTrace(skip, count, buffer, hash);
	TRACE("Leave RtlCaptureStackBackTrace\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCaptureStackBackTrace(void);  /* ../dlls/ntdll/signal_x86_64.c:4123 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCaptureStackBackTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCaptureStackBackTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCharToInteger(PCSZ  str, ULONG  base, ULONG*  value) /* ../dlls/ntdll/rtlstr.c:1759 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCharToInteger\n");
	return_value = pRtlCharToInteger(str, base, value);
	TRACE("Leave RtlCharToInteger\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCharToInteger(void);  /* ../dlls/ntdll/rtlstr.c:1759 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCharToInteger,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCharToInteger") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCheckRegistryKey(ULONG  RelativeTo, PWSTR  Path) /* ../dlls/ntdll/reg.c:1407 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCheckRegistryKey\n");
	return_value = pRtlCheckRegistryKey(RelativeTo, Path);
	TRACE("Leave RtlCheckRegistryKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCheckRegistryKey(void);  /* ../dlls/ntdll/reg.c:1407 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCheckRegistryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCheckRegistryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlClearAllBits(PRTL_BITMAP  lpBits) /* ../dlls/ntdll/rtlbitmap.c:110 */
{
	TRACE("Enter RtlClearAllBits\n");
	pRtlClearAllBits(lpBits);
	TRACE("Leave RtlClearAllBits\n");
}

extern WINAPI void wine32a_ntdll_RtlClearAllBits(void);  /* ../dlls/ntdll/rtlbitmap.c:110 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlClearAllBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlClearAllBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlClearBits(PRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount) /* ../dlls/ntdll/rtlbitmap.c:190 */
{
	TRACE("Enter RtlClearBits\n");
	pRtlClearBits(lpBits, ulStart, ulCount);
	TRACE("Leave RtlClearBits\n");
}

extern WINAPI void wine32a_ntdll_RtlClearBits(void);  /* ../dlls/ntdll/rtlbitmap.c:190 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlCompactHeap(HANDLE  heap, ULONG  flags) /* ../dlls/ntdll/heap.c:1957 */
{
	ULONG return_value;
	TRACE("Enter RtlCompactHeap\n");
	return_value = pRtlCompactHeap(heap, flags);
	TRACE("Leave RtlCompactHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompactHeap(void);  /* ../dlls/ntdll/heap.c:1957 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompactHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompactHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI SIZE_T wine32b_ntdll_RtlCompareMemory(void*  Source1, void*  Source2, SIZE_T  Length) /* ../dlls/ntdll/rtl.c:502 */
{
	SIZE_T return_value;
	TRACE("Enter RtlCompareMemory\n");
	return_value = pRtlCompareMemory(Source1, Source2, Length);
	TRACE("Leave RtlCompareMemory\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompareMemory(void);  /* ../dlls/ntdll/rtl.c:502 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompareMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompareMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI SIZE_T wine32b_ntdll_RtlCompareMemoryUlong(ULONG*  Source1, SIZE_T  Length, ULONG  dwVal) /* ../dlls/ntdll/rtl.c:522 */
{
	SIZE_T return_value;
	TRACE("Enter RtlCompareMemoryUlong\n");
	return_value = pRtlCompareMemoryUlong(Source1, Length, dwVal);
	TRACE("Leave RtlCompareMemoryUlong\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompareMemoryUlong(void);  /* ../dlls/ntdll/rtl.c:522 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompareMemoryUlong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompareMemoryUlong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_RtlCompareString(STRING*  s1, STRING*  s2, BOOLEAN  CaseInsensitive) /* ../dlls/ntdll/rtlstr.c:433 */
{
	LONG return_value;
	TRACE("Enter RtlCompareString\n");
	return_value = pRtlCompareString(s1, s2, CaseInsensitive);
	TRACE("Leave RtlCompareString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompareString(void);  /* ../dlls/ntdll/rtlstr.c:433 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompareString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompareString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_RtlCompareUnicodeString(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  CaseInsensitive) /* ../dlls/ntdll/rtlstr.c:481 */
{
	LONG return_value;
	TRACE("Enter RtlCompareUnicodeString\n");
	return_value = pRtlCompareUnicodeString(s1, s2, CaseInsensitive);
	TRACE("Leave RtlCompareUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompareUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:481 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompareUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompareUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_RtlCompareUnicodeStrings(WCHAR*  s1, SIZE_T  len1, WCHAR*  s2, SIZE_T  len2, BOOLEAN  case_insensitive) /* ../dlls/ntdll/rtlstr.c:459 */
{
	LONG return_value;
	TRACE("Enter RtlCompareUnicodeStrings\n");
	return_value = pRtlCompareUnicodeStrings(s1, len1, s2, len2, case_insensitive);
	TRACE("Leave RtlCompareUnicodeStrings\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompareUnicodeStrings(void);  /* ../dlls/ntdll/rtlstr.c:459 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompareUnicodeStrings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompareUnicodeStrings") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCompressBuffer(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, ULONG  chunk_size, PULONG  final_size, PVOID  workspace) /* ../dlls/ntdll/rtl.c:1493 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCompressBuffer\n");
	return_value = pRtlCompressBuffer(format, uncompressed, uncompressed_size, compressed, compressed_size, chunk_size, final_size, workspace);
	TRACE("Leave RtlCompressBuffer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCompressBuffer(void);  /* ../dlls/ntdll/rtl.c:1493 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCompressBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCompressBuffer") "\n"
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

WINAPI DWORD wine32b_ntdll_RtlComputeCrc32(DWORD  dwInitial, BYTE*  pData, INT  iLen) /* ../dlls/ntdll/rtl.c:590 */
{
	DWORD return_value;
	TRACE("Enter RtlComputeCrc32\n");
	return_value = pRtlComputeCrc32(dwInitial, pData, iLen);
	TRACE("Leave RtlComputeCrc32\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlComputeCrc32(void);  /* ../dlls/ntdll/rtl.c:590 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlComputeCrc32,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlComputeCrc32") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlConvertSidToUnicodeString(PUNICODE_STRING  String, PSID  pSid, BOOLEAN  AllocateString) /* ../dlls/ntdll/sec.c:1819 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlConvertSidToUnicodeString\n");
	return_value = pRtlConvertSidToUnicodeString(String, pSid, AllocateString);
	TRACE("Leave RtlConvertSidToUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlConvertSidToUnicodeString(void);  /* ../dlls/ntdll/sec.c:1819 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlConvertSidToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlConvertSidToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlConvertToAutoInheritSecurityObject(PSECURITY_DESCRIPTOR  pdesc, PSECURITY_DESCRIPTOR  cdesc, PSECURITY_DESCRIPTOR*  ndesc, GUID*  objtype, BOOL  isdir, PGENERIC_MAPPING  genmap) /* ../dlls/ntdll/sec.c:1913 */
{
	BOOL return_value;
	TRACE("Enter RtlConvertToAutoInheritSecurityObject\n");
	return_value = pRtlConvertToAutoInheritSecurityObject(pdesc, cdesc, ndesc, objtype, isdir, genmap);
	TRACE("Leave RtlConvertToAutoInheritSecurityObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlConvertToAutoInheritSecurityObject(void);  /* ../dlls/ntdll/sec.c:1913 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlConvertToAutoInheritSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlConvertToAutoInheritSecurityObject") "\n"
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

WINAPI void wine32b_ntdll_RtlCopyLuid(PLUID  LuidDest, LUID*  LuidSrc) /* ../dlls/ntdll/rtl.c:836 */
{
	TRACE("Enter RtlCopyLuid\n");
	pRtlCopyLuid(LuidDest, LuidSrc);
	TRACE("Leave RtlCopyLuid\n");
}

extern WINAPI void wine32a_ntdll_RtlCopyLuid(void);  /* ../dlls/ntdll/rtl.c:836 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopyLuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopyLuid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlCopyLuidAndAttributesArray(ULONG  Count, LUID_AND_ATTRIBUTES*  Src, PLUID_AND_ATTRIBUTES  Dest) /* ../dlls/ntdll/rtl.c:877 */
{
	TRACE("Enter RtlCopyLuidAndAttributesArray\n");
	pRtlCopyLuidAndAttributesArray(Count, Src, Dest);
	TRACE("Leave RtlCopyLuidAndAttributesArray\n");
}

extern WINAPI void wine32a_ntdll_RtlCopyLuidAndAttributesArray(void);  /* ../dlls/ntdll/rtl.c:877 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopyLuidAndAttributesArray,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopyLuidAndAttributesArray") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlCopyMemory(void*  dest, void*  src, SIZE_T  len) /* ../dlls/ntdll/rtl.c:533 */
{
	TRACE("Enter RtlCopyMemory\n");
	pRtlCopyMemory(dest, src, len);
	TRACE("Leave RtlCopyMemory\n");
}

extern WINAPI void wine32a_ntdll_RtlCopyMemory(void);  /* ../dlls/ntdll/rtl.c:533 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopyMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopyMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCopySecurityDescriptor(PSECURITY_DESCRIPTOR  pSourceSD, PSECURITY_DESCRIPTOR  pDestinationSD) /* ../dlls/ntdll/sec.c:459 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCopySecurityDescriptor\n");
	return_value = pRtlCopySecurityDescriptor(pSourceSD, pDestinationSD);
	TRACE("Leave RtlCopySecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCopySecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:459 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopySecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopySecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlCopySid(DWORD  nDestinationSidLength, PSID  pDestinationSid, PSID  pSourceSid) /* ../dlls/ntdll/sec.c:372 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlCopySid\n");
	return_value = pRtlCopySid(nDestinationSidLength, pDestinationSid, pSourceSid);
	TRACE("Leave RtlCopySid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCopySid(void);  /* ../dlls/ntdll/sec.c:372 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlCopyString(STRING*  dst, STRING*  src) /* ../dlls/ntdll/rtlstr.c:193 */
{
	TRACE("Enter RtlCopyString\n");
	pRtlCopyString(dst, src);
	TRACE("Leave RtlCopyString\n");
}

extern WINAPI void wine32a_ntdll_RtlCopyString(void);  /* ../dlls/ntdll/rtlstr.c:193 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopyString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopyString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlCopyUnicodeString(UNICODE_STRING*  dst, UNICODE_STRING*  src) /* ../dlls/ntdll/rtlstr.c:335 */
{
	TRACE("Enter RtlCopyUnicodeString\n");
	pRtlCopyUnicodeString(dst, src);
	TRACE("Leave RtlCopyUnicodeString\n");
}

extern WINAPI void wine32a_ntdll_RtlCopyUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:335 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCopyUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCopyUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateAcl(PACL  acl, DWORD  size, DWORD  rev) /* ../dlls/ntdll/sec.c:1123 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateAcl\n");
	return_value = pRtlCreateAcl(acl, size, rev);
	TRACE("Leave RtlCreateAcl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateAcl(void);  /* ../dlls/ntdll/sec.c:1123 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateActivationContext(HANDLE*  handle, void*  ptr) /* ../dlls/ntdll/actctx.c:4953 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateActivationContext\n");
	return_value = pRtlCreateActivationContext(handle, ptr);
	TRACE("Leave RtlCreateActivationContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateActivationContext(void);  /* ../dlls/ntdll/actctx.c:4953 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateAtomTable(ULONG  size, RTL_ATOM_TABLE*  table) /* ../dlls/ntdll/atom.c:174 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateAtomTable\n");
	return_value = pRtlCreateAtomTable(size, table);
	TRACE("Leave RtlCreateAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateAtomTable(void);  /* ../dlls/ntdll/atom.c:174 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateEnvironment(BOOLEAN  inherit, PWSTR*  env) /* ../dlls/ntdll/env.c:76 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateEnvironment\n");
	return_value = pRtlCreateEnvironment(inherit, env);
	TRACE("Leave RtlCreateEnvironment\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateEnvironment(void);  /* ../dlls/ntdll/env.c:76 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI HANDLE wine32b_ntdll_RtlCreateHeap(ULONG  flags, PVOID  addr, SIZE_T  totalSize, SIZE_T  commitSize, PVOID  unknown, PRTL_HEAP_DEFINITION  definition) /* ../dlls/ntdll/heap.c:1549 */
{
	HANDLE return_value;
	TRACE("Enter RtlCreateHeap\n");
	return_value = pRtlCreateHeap(flags, addr, totalSize, commitSize, unknown, definition);
	TRACE("Leave RtlCreateHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateHeap(void);  /* ../dlls/ntdll/heap.c:1549 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateHeap") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlCreateProcessParameters(RTL_USER_PROCESS_PARAMETERS**  result, UNICODE_STRING*  image, UNICODE_STRING*  dllpath, UNICODE_STRING*  curdir, UNICODE_STRING*  cmdline, PWSTR  env, UNICODE_STRING*  title, UNICODE_STRING*  desktop, UNICODE_STRING*  shellinfo, UNICODE_STRING*  runtime) /* ../dlls/ntdll/env.c:514 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateProcessParameters\n");
	return_value = pRtlCreateProcessParameters(result, image, dllpath, curdir, cmdline, env, title, desktop, shellinfo, runtime);
	TRACE("Leave RtlCreateProcessParameters\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateProcessParameters(void);  /* ../dlls/ntdll/env.c:514 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateProcessParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateProcessParameters") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlCreateProcessParametersEx(RTL_USER_PROCESS_PARAMETERS**  result, UNICODE_STRING*  ImagePathName, UNICODE_STRING*  DllPath, UNICODE_STRING*  CurrentDirectoryName, UNICODE_STRING*  CommandLine, PWSTR  Environment, UNICODE_STRING*  WindowTitle, UNICODE_STRING*  Desktop, UNICODE_STRING*  ShellInfo, UNICODE_STRING*  RuntimeInfo, ULONG  flags) /* ../dlls/ntdll/env.c:432 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateProcessParametersEx\n");
	return_value = pRtlCreateProcessParametersEx(result, ImagePathName, DllPath, CurrentDirectoryName, CommandLine, Environment, WindowTitle, Desktop, ShellInfo, RuntimeInfo, flags);
	TRACE("Leave RtlCreateProcessParametersEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateProcessParametersEx(void);  /* ../dlls/ntdll/env.c:432 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateProcessParametersEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateProcessParametersEx") "\n"
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

WINAPI PDEBUG_BUFFER wine32b_ntdll_RtlCreateQueryDebugBuffer(ULONG  iSize, BOOLEAN  iEventPair) /* ../dlls/ntdll/debugbuffer.c:92 */
{
	PDEBUG_BUFFER return_value;
	TRACE("Enter RtlCreateQueryDebugBuffer\n");
	return_value = pRtlCreateQueryDebugBuffer(iSize, iEventPair);
	TRACE("Leave RtlCreateQueryDebugBuffer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateQueryDebugBuffer(void);  /* ../dlls/ntdll/debugbuffer.c:92 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateQueryDebugBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateQueryDebugBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateRegistryKey(ULONG  RelativeTo, PWSTR  path) /* ../dlls/ntdll/reg.c:1439 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateRegistryKey\n");
	return_value = pRtlCreateRegistryKey(RelativeTo, path);
	TRACE("Leave RtlCreateRegistryKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateRegistryKey(void);  /* ../dlls/ntdll/reg.c:1439 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateRegistryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateRegistryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateSecurityDescriptor(PSECURITY_DESCRIPTOR  lpsd, DWORD  rev) /* ../dlls/ntdll/sec.c:435 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateSecurityDescriptor\n");
	return_value = pRtlCreateSecurityDescriptor(lpsd, rev);
	TRACE("Leave RtlCreateSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:435 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateTimer(PHANDLE  NewTimer, HANDLE  TimerQueue, RTL_WAITORTIMERCALLBACKFUNC  Callback, PVOID  Parameter, DWORD  DueTime, DWORD  Period, ULONG  Flags) /* ../dlls/ntdll/threadpool.c:1072 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateTimer\n");
	return_value = pRtlCreateTimer(NewTimer, TimerQueue, Callback, Parameter, DueTime, Period, Flags);
	TRACE("Leave RtlCreateTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateTimer(void);  /* ../dlls/ntdll/threadpool.c:1072 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateTimer") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlCreateTimerQueue(PHANDLE  NewTimerQueue) /* ../dlls/ntdll/threadpool.c:932 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateTimerQueue\n");
	return_value = pRtlCreateTimerQueue(NewTimerQueue);
	TRACE("Leave RtlCreateTimerQueue\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateTimerQueue(void);  /* ../dlls/ntdll/threadpool.c:932 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateTimerQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateTimerQueue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlCreateUnicodeString(PUNICODE_STRING  target, LPCWSTR  src) /* ../dlls/ntdll/rtlstr.c:280 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlCreateUnicodeString\n");
	return_value = pRtlCreateUnicodeString(target, src);
	TRACE("Leave RtlCreateUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:280 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlCreateUnicodeStringFromAsciiz(PUNICODE_STRING  target, LPCSTR  src) /* ../dlls/ntdll/rtlstr.c:300 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlCreateUnicodeStringFromAsciiz\n");
	return_value = pRtlCreateUnicodeStringFromAsciiz(target, src);
	TRACE("Leave RtlCreateUnicodeStringFromAsciiz\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateUnicodeStringFromAsciiz(void);  /* ../dlls/ntdll/rtlstr.c:300 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateUnicodeStringFromAsciiz,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateUnicodeStringFromAsciiz") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlCreateUserProcess(UNICODE_STRING*  path, ULONG  attributes, RTL_USER_PROCESS_PARAMETERS*  params, SECURITY_DESCRIPTOR*  process_descr, SECURITY_DESCRIPTOR*  thread_descr, HANDLE  parent, BOOLEAN  inherit, HANDLE  debug, HANDLE  exception, RTL_USER_PROCESS_INFORMATION*  info) /* ../dlls/ntdll/process.c:1212 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateUserProcess\n");
	return_value = pRtlCreateUserProcess(path, attributes, params, process_descr, thread_descr, parent, inherit, debug, exception, info);
	TRACE("Leave RtlCreateUserProcess\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateUserProcess(void);  /* ../dlls/ntdll/process.c:1212 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateUserProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateUserProcess") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlCreateUserStack(SIZE_T  commit, SIZE_T  reserve, ULONG  zero_bits, SIZE_T  commit_align, SIZE_T  reserve_align, INITIAL_TEB*  stack) /* ../dlls/ntdll/virtual.c:2050 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateUserStack\n");
	return_value = pRtlCreateUserStack(commit, reserve, zero_bits, commit_align, reserve_align, stack);
	TRACE("Leave RtlCreateUserStack\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateUserStack(void);  /* ../dlls/ntdll/virtual.c:2050 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateUserStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateUserStack") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlCreateUserThread(HANDLE  process, SECURITY_DESCRIPTOR*  descr, BOOLEAN  suspended, PVOID  stack_addr, SIZE_T  stack_reserve, SIZE_T  stack_commit, PRTL_THREAD_START_ROUTINE  start, void*  param, HANDLE*  handle_ptr, CLIENT_ID*  id) /* ../dlls/ntdll/thread.c:400 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlCreateUserThread\n");
	return_value = pRtlCreateUserThread(process, descr, suspended, stack_addr, stack_reserve, stack_commit, start, param, handle_ptr, id);
	TRACE("Leave RtlCreateUserThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlCreateUserThread(void);  /* ../dlls/ntdll/thread.c:400 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlCreateUserThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlCreateUserThread") "\n"
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

WINAPI PRTL_USER_PROCESS_PARAMETERS wine32b_ntdll_RtlDeNormalizeProcessParams(RTL_USER_PROCESS_PARAMETERS*  params) /* ../dlls/ntdll/env.c:393 */
{
	PRTL_USER_PROCESS_PARAMETERS return_value;
	TRACE("Enter RtlDeNormalizeProcessParams\n");
	return_value = pRtlDeNormalizeProcessParams(params);
	TRACE("Leave RtlDeNormalizeProcessParams\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeNormalizeProcessParams(void);  /* ../dlls/ntdll/env.c:393 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeNormalizeProcessParams,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeNormalizeProcessParams") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlDeactivateActivationContext(ULONG  flags, ULONG_PTR  cookie) /* ../dlls/ntdll/actctx.c:5146 */
{
	TRACE("Enter RtlDeactivateActivationContext\n");
	pRtlDeactivateActivationContext(flags, cookie);
	TRACE("Leave RtlDeactivateActivationContext\n");
}

extern WINAPI void wine32a_ntdll_RtlDeactivateActivationContext(void);  /* ../dlls/ntdll/actctx.c:5146 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeactivateActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeactivateActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlDecodePointer(PVOID  ptr) /* ../dlls/ntdll/rtl.c:1235 */
{
	PVOID return_value;
	TRACE("Enter RtlDecodePointer\n");
	return_value = pRtlDecodePointer(ptr);
	TRACE("Leave RtlDecodePointer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDecodePointer(void);  /* ../dlls/ntdll/rtl.c:1235 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDecodePointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDecodePointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDecompressBuffer(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, PULONG  final_size) /* ../dlls/ntdll/rtl.c:1723 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDecompressBuffer\n");
	return_value = pRtlDecompressBuffer(format, uncompressed, uncompressed_size, compressed, compressed_size, final_size);
	TRACE("Leave RtlDecompressBuffer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDecompressBuffer(void);  /* ../dlls/ntdll/rtl.c:1723 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDecompressBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDecompressBuffer") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlDecompressFragment(USHORT  format, PUCHAR  uncompressed, ULONG  uncompressed_size, PUCHAR  compressed, ULONG  compressed_size, ULONG  offset, PULONG  final_size, PVOID  workspace) /* ../dlls/ntdll/rtl.c:1696 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDecompressFragment\n");
	return_value = pRtlDecompressFragment(format, uncompressed, uncompressed_size, compressed, compressed_size, offset, final_size, workspace);
	TRACE("Leave RtlDecompressFragment\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDecompressFragment(void);  /* ../dlls/ntdll/rtl.c:1696 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDecompressFragment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDecompressFragment") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteAce(PACL  pAcl, DWORD  dwAceIndex) /* ../dlls/ntdll/sec.c:1200 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteAce\n");
	return_value = pRtlDeleteAce(pAcl, dwAceIndex);
	TRACE("Leave RtlDeleteAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteAce(void);  /* ../dlls/ntdll/sec.c:1200 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteAtomFromAtomTable(RTL_ATOM_TABLE  table, RTL_ATOM  atom) /* ../dlls/ntdll/atom.c:82 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteAtomFromAtomTable\n");
	return_value = pRtlDeleteAtomFromAtomTable(table, atom);
	TRACE("Leave RtlDeleteAtomFromAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteAtomFromAtomTable(void);  /* ../dlls/ntdll/atom.c:82 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteAtomFromAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteAtomFromAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:402 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteCriticalSection\n");
	return_value = pRtlDeleteCriticalSection(crit);
	TRACE("Leave RtlDeleteCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteCriticalSection(void);  /* ../dlls/ntdll/critsection.c:402 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlDeleteGrowableFunctionTable(void*  table) /* ../dlls/ntdll/exception.c:520 */
{
	TRACE("Enter RtlDeleteGrowableFunctionTable\n");
	pRtlDeleteGrowableFunctionTable(table);
	TRACE("Leave RtlDeleteGrowableFunctionTable\n");
}

extern WINAPI void wine32a_ntdll_RtlDeleteGrowableFunctionTable(void);  /* ../dlls/ntdll/exception.c:520 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteGrowableFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteGrowableFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlDeleteFunctionTable(RUNTIME_FUNCTION*  table) /* ../dlls/ntdll/exception.c:545 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlDeleteFunctionTable\n");
	return_value = pRtlDeleteFunctionTable(table);
	TRACE("Leave RtlDeleteFunctionTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteFunctionTable(void);  /* ../dlls/ntdll/exception.c:545 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteRegistryValue(ULONG  RelativeTo, PCWSTR  Path, PCWSTR  ValueName) /* ../dlls/ntdll/reg.c:1475 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteRegistryValue\n");
	return_value = pRtlDeleteRegistryValue(RelativeTo, Path, ValueName);
	TRACE("Leave RtlDeleteRegistryValue\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteRegistryValue(void);  /* ../dlls/ntdll/reg.c:1475 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteRegistryValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteRegistryValue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlDeleteResource(LPRTL_RWLOCK  rwl) /* ../dlls/ntdll/rtl.c:131 */
{
	TRACE("Enter RtlDeleteResource\n");
	pRtlDeleteResource(rwl);
	TRACE("Leave RtlDeleteResource\n");
}

extern WINAPI void wine32a_ntdll_RtlDeleteResource(void);  /* ../dlls/ntdll/rtl.c:131 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteSecurityObject(PSECURITY_DESCRIPTOR*  ObjectDescriptor) /* ../dlls/ntdll/rtl.c:396 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteSecurityObject\n");
	return_value = pRtlDeleteSecurityObject(ObjectDescriptor);
	TRACE("Leave RtlDeleteSecurityObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteSecurityObject(void);  /* ../dlls/ntdll/rtl.c:396 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteSecurityObject") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteTimer(HANDLE  TimerQueue, HANDLE  Timer, HANDLE  CompletionEvent) /* ../dlls/ntdll/threadpool.c:1167 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteTimer\n");
	return_value = pRtlDeleteTimer(TimerQueue, Timer, CompletionEvent);
	TRACE("Leave RtlDeleteTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteTimer(void);  /* ../dlls/ntdll/threadpool.c:1167 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeleteTimerQueueEx(HANDLE  TimerQueue, HANDLE  CompletionEvent) /* ../dlls/ntdll/threadpool.c:978 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeleteTimerQueueEx\n");
	return_value = pRtlDeleteTimerQueueEx(TimerQueue, CompletionEvent);
	TRACE("Leave RtlDeleteTimerQueueEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeleteTimerQueueEx(void);  /* ../dlls/ntdll/threadpool.c:978 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeleteTimerQueueEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeleteTimerQueueEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeregisterWait(HANDLE  WaitHandle) /* ../dlls/ntdll/threadpool.c:706 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeregisterWait\n");
	return_value = pRtlDeregisterWait(WaitHandle);
	TRACE("Leave RtlDeregisterWait\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeregisterWait(void);  /* ../dlls/ntdll/threadpool.c:706 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeregisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeregisterWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDeregisterWaitEx(HANDLE  WaitHandle, HANDLE  CompletionEvent) /* ../dlls/ntdll/threadpool.c:642 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDeregisterWaitEx\n");
	return_value = pRtlDeregisterWaitEx(WaitHandle, CompletionEvent);
	TRACE("Leave RtlDeregisterWaitEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDeregisterWaitEx(void);  /* ../dlls/ntdll/threadpool.c:642 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDeregisterWaitEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDeregisterWaitEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDestroyAtomTable(RTL_ATOM_TABLE  table) /* ../dlls/ntdll/atom.c:199 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDestroyAtomTable\n");
	return_value = pRtlDestroyAtomTable(table);
	TRACE("Leave RtlDestroyAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDestroyAtomTable(void);  /* ../dlls/ntdll/atom.c:199 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDestroyEnvironment(PWSTR  env) /* ../dlls/ntdll/env.c:98 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDestroyEnvironment\n");
	return_value = pRtlDestroyEnvironment(env);
	TRACE("Leave RtlDestroyEnvironment\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDestroyEnvironment(void);  /* ../dlls/ntdll/env.c:98 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDestroyHandleTable(RTL_HANDLE_TABLE*  HandleTable) /* ../dlls/ntdll/handletable.c:77 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDestroyHandleTable\n");
	return_value = pRtlDestroyHandleTable(HandleTable);
	TRACE("Leave RtlDestroyHandleTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDestroyHandleTable(void);  /* ../dlls/ntdll/handletable.c:77 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyHandleTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyHandleTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI HANDLE wine32b_ntdll_RtlDestroyHeap(HANDLE  heap) /* ../dlls/ntdll/heap.c:1596 */
{
	HANDLE return_value;
	TRACE("Enter RtlDestroyHeap\n");
	return_value = pRtlDestroyHeap(heap);
	TRACE("Leave RtlDestroyHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDestroyHeap(void);  /* ../dlls/ntdll/heap.c:1596 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlDestroyProcessParameters(RTL_USER_PROCESS_PARAMETERS*  params) /* ../dlls/ntdll/env.c:533 */
{
	TRACE("Enter RtlDestroyProcessParameters\n");
	pRtlDestroyProcessParameters(params);
	TRACE("Leave RtlDestroyProcessParameters\n");
}

extern WINAPI void wine32a_ntdll_RtlDestroyProcessParameters(void);  /* ../dlls/ntdll/env.c:533 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyProcessParameters,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyProcessParameters") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDestroyQueryDebugBuffer(PDEBUG_BUFFER  iBuf) /* ../dlls/ntdll/debugbuffer.c:105 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDestroyQueryDebugBuffer\n");
	return_value = pRtlDestroyQueryDebugBuffer(iBuf);
	TRACE("Leave RtlDestroyQueryDebugBuffer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDestroyQueryDebugBuffer(void);  /* ../dlls/ntdll/debugbuffer.c:105 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDestroyQueryDebugBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDestroyQueryDebugBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DOS_PATHNAME_TYPE wine32b_ntdll_RtlDetermineDosPathNameType_U(PCWSTR  path) /* ../dlls/ntdll/path.c:242 */
{
	DOS_PATHNAME_TYPE return_value;
	TRACE("Enter RtlDetermineDosPathNameType_U\n");
	return_value = pRtlDetermineDosPathNameType_U(path);
	TRACE("Leave RtlDetermineDosPathNameType_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDetermineDosPathNameType_U(void);  /* ../dlls/ntdll/path.c:242 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDetermineDosPathNameType_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDetermineDosPathNameType_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlDllShutdownInProgress(void) /* ../dlls/ntdll/loader.c:3422 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlDllShutdownInProgress\n");
	return_value = pRtlDllShutdownInProgress();
	TRACE("Leave RtlDllShutdownInProgress\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDllShutdownInProgress(void);  /* ../dlls/ntdll/loader.c:3422 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDllShutdownInProgress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDllShutdownInProgress") "\n"
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

WINAPI BOOLEAN wine32b_ntdll_RtlDoesFileExists_U(LPCWSTR  file_name) /* ../dlls/ntdll/directory.c:2905 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlDoesFileExists_U\n");
	return_value = pRtlDoesFileExists_U(file_name);
	TRACE("Leave RtlDoesFileExists_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDoesFileExists_U(void);  /* ../dlls/ntdll/directory.c:2905 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDoesFileExists_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDoesFileExists_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlDosPathNameToNtPathName_U(PCWSTR  dos_path, PUNICODE_STRING  ntpath, PWSTR*  file_part, CURDIR*  cd) /* ../dlls/ntdll/path.c:433 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlDosPathNameToNtPathName_U\n");
	return_value = pRtlDosPathNameToNtPathName_U(dos_path, ntpath, file_part, cd);
	TRACE("Leave RtlDosPathNameToNtPathName_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDosPathNameToNtPathName_U(void);  /* ../dlls/ntdll/path.c:433 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDosPathNameToNtPathName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDosPathNameToNtPathName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDosPathNameToNtPathName_U_WithStatus(WCHAR*  dos_path, UNICODE_STRING*  ntpath, WCHAR**  file_part, CURDIR*  cd) /* ../dlls/ntdll/path.c:340 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDosPathNameToNtPathName_U_WithStatus\n");
	return_value = pRtlDosPathNameToNtPathName_U_WithStatus(dos_path, ntpath, file_part, cd);
	TRACE("Leave RtlDosPathNameToNtPathName_U_WithStatus\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDosPathNameToNtPathName_U_WithStatus(void);  /* ../dlls/ntdll/path.c:340 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDosPathNameToNtPathName_U_WithStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDosPathNameToNtPathName_U_WithStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDosPathNameToRelativeNtPathName_U_WithStatus(WCHAR*  dos_path, UNICODE_STRING*  ntpath, WCHAR**  file_part, RTL_RELATIVE_NAME*  relative) /* ../dlls/ntdll/path.c:446 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDosPathNameToRelativeNtPathName_U_WithStatus\n");
	return_value = pRtlDosPathNameToRelativeNtPathName_U_WithStatus(dos_path, ntpath, file_part, relative);
	TRACE("Leave RtlDosPathNameToRelativeNtPathName_U_WithStatus\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDosPathNameToRelativeNtPathName_U_WithStatus(void);  /* ../dlls/ntdll/path.c:446 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDosPathNameToRelativeNtPathName_U_WithStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDosPathNameToRelativeNtPathName_U_WithStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlDosSearchPath_U(LPCWSTR  paths, LPCWSTR  search, LPCWSTR  ext, ULONG  buffer_size, LPWSTR  buffer, LPWSTR*  file_part) /* ../dlls/ntdll/path.c:480 */
{
	ULONG return_value;
	TRACE("Enter RtlDosSearchPath_U\n");
	return_value = pRtlDosSearchPath_U(paths, search, ext, buffer_size, buffer, file_part);
	TRACE("Leave RtlDosSearchPath_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDosSearchPath_U(void);  /* ../dlls/ntdll/path.c:480 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDosSearchPath_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDosSearchPath_U") "\n"
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

WINAPI WCHAR wine32b_ntdll_RtlDowncaseUnicodeChar(WCHAR  wch) /* ../dlls/ntdll/rtlstr.c:1031 */
{
	WCHAR return_value;
	TRACE("Enter RtlDowncaseUnicodeChar\n");
	return_value = pRtlDowncaseUnicodeChar(wch);
	TRACE("Leave RtlDowncaseUnicodeChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDowncaseUnicodeChar(void);  /* ../dlls/ntdll/rtlstr.c:1031 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDowncaseUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDowncaseUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDowncaseUnicodeString(UNICODE_STRING*  dest, UNICODE_STRING*  src, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:1095 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDowncaseUnicodeString\n");
	return_value = pRtlDowncaseUnicodeString(dest, src, doalloc);
	TRACE("Leave RtlDowncaseUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDowncaseUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:1095 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDowncaseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDowncaseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlDumpResource(LPRTL_RWLOCK  rwl) /* ../dlls/ntdll/rtl.c:285 */
{
	TRACE("Enter RtlDumpResource\n");
	pRtlDumpResource(rwl);
	TRACE("Leave RtlDumpResource\n");
}

extern WINAPI void wine32a_ntdll_RtlDumpResource(void);  /* ../dlls/ntdll/rtl.c:285 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDumpResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDumpResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlDuplicateUnicodeString(int  add_nul, UNICODE_STRING*  source, UNICODE_STRING*  destination) /* ../dlls/ntdll/rtlstr.c:367 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlDuplicateUnicodeString\n");
	return_value = pRtlDuplicateUnicodeString(add_nul, source, destination);
	TRACE("Leave RtlDuplicateUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlDuplicateUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:367 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlDuplicateUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlDuplicateUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlEmptyAtomTable(RTL_ATOM_TABLE  table, BOOLEAN  delete_pinned) /* ../dlls/ntdll/atom.c:267 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlEmptyAtomTable\n");
	return_value = pRtlEmptyAtomTable(table, delete_pinned);
	TRACE("Leave RtlEmptyAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEmptyAtomTable(void);  /* ../dlls/ntdll/atom.c:267 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEmptyAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEmptyAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlEncodePointer(PVOID  ptr) /* ../dlls/ntdll/rtl.c:1229 */
{
	PVOID return_value;
	TRACE("Enter RtlEncodePointer\n");
	return_value = pRtlEncodePointer(ptr);
	TRACE("Leave RtlEncodePointer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEncodePointer(void);  /* ../dlls/ntdll/rtl.c:1229 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEncodePointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEncodePointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlEnterCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:556 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlEnterCriticalSection\n");
	return_value = pRtlEnterCriticalSection(crit);
	TRACE("Leave RtlEnterCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEnterCriticalSection(void);  /* ../dlls/ntdll/critsection.c:556 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEnterCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEnterCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlEnumerateGenericTableWithoutSplaying(PVOID  pTable, PVOID*  RestartKey) /* ../dlls/ntdll/rtl.c:414 */
{
	PVOID return_value;
	TRACE("Enter RtlEnumerateGenericTableWithoutSplaying\n");
	return_value = pRtlEnumerateGenericTableWithoutSplaying(pTable, RestartKey);
	TRACE("Leave RtlEnumerateGenericTableWithoutSplaying\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEnumerateGenericTableWithoutSplaying(void);  /* ../dlls/ntdll/rtl.c:414 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEnumerateGenericTableWithoutSplaying,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEnumerateGenericTableWithoutSplaying") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlEqualComputerName(UNICODE_STRING*  left, UNICODE_STRING*  right) /* ../dlls/ntdll/rtlstr.c:595 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlEqualComputerName\n");
	return_value = pRtlEqualComputerName(left, right);
	TRACE("Leave RtlEqualComputerName\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualComputerName(void);  /* ../dlls/ntdll/rtlstr.c:595 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualComputerName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualComputerName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlEqualDomainName(UNICODE_STRING*  left, UNICODE_STRING*  right) /* ../dlls/ntdll/rtlstr.c:629 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlEqualDomainName\n");
	return_value = pRtlEqualDomainName(left, right);
	TRACE("Leave RtlEqualDomainName\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualDomainName(void);  /* ../dlls/ntdll/rtlstr.c:629 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualDomainName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualDomainName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlEqualLuid(LUID*  Luid1, LUID*  Luid2) /* ../dlls/ntdll/rtl.c:855 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlEqualLuid\n");
	return_value = pRtlEqualLuid(Luid1, Luid2);
	TRACE("Leave RtlEqualLuid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualLuid(void);  /* ../dlls/ntdll/rtl.c:855 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualLuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualLuid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlEqualPrefixSid(PSID  pSid1, PSID  pSid2) /* ../dlls/ntdll/sec.c:217 */
{
	BOOL return_value;
	TRACE("Enter RtlEqualPrefixSid\n");
	return_value = pRtlEqualPrefixSid(pSid1, pSid2);
	TRACE("Leave RtlEqualPrefixSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualPrefixSid(void);  /* ../dlls/ntdll/sec.c:217 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualPrefixSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualPrefixSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlEqualSid(PSID  pSid1, PSID  pSid2) /* ../dlls/ntdll/sec.c:200 */
{
	BOOL return_value;
	TRACE("Enter RtlEqualSid\n");
	return_value = pRtlEqualSid(pSid1, pSid2);
	TRACE("Leave RtlEqualSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualSid(void);  /* ../dlls/ntdll/sec.c:200 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlEqualString(STRING*  s1, STRING*  s2, BOOLEAN  CaseInsensitive) /* ../dlls/ntdll/rtlstr.c:502 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlEqualString\n");
	return_value = pRtlEqualString(s1, s2, CaseInsensitive);
	TRACE("Leave RtlEqualString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualString(void);  /* ../dlls/ntdll/rtlstr.c:502 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlEqualUnicodeString(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  CaseInsensitive) /* ../dlls/ntdll/rtlstr.c:514 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlEqualUnicodeString\n");
	return_value = pRtlEqualUnicodeString(s1, s2, CaseInsensitive);
	TRACE("Leave RtlEqualUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlEqualUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:514 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEqualUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEqualUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlEraseUnicodeString(UNICODE_STRING*  str) /* ../dlls/ntdll/rtlstr.c:415 */
{
	TRACE("Enter RtlEraseUnicodeString\n");
	pRtlEraseUnicodeString(str);
	TRACE("Leave RtlEraseUnicodeString\n");
}

extern WINAPI void wine32a_ntdll_RtlEraseUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:415 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlEraseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlEraseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlExitUserProcess(DWORD  status) /* ../dlls/ntdll/loader.c:3521 */
{
	TRACE("Enter RtlExitUserProcess\n");
	pRtlExitUserProcess(status);
	TRACE("Leave RtlExitUserProcess\n");
}

extern WINAPI void wine32a_ntdll_RtlExitUserProcess(void);  /* ../dlls/ntdll/loader.c:3521 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlExitUserProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlExitUserProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlExitUserThread(ULONG  status) /* ../dlls/ntdll/thread.c:315 */
{
	TRACE("Enter RtlExitUserThread\n");
	pRtlExitUserThread(status);
	TRACE("Leave RtlExitUserThread\n");
}

extern WINAPI void wine32a_ntdll_RtlExitUserThread(void);  /* ../dlls/ntdll/thread.c:315 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlExitUserThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlExitUserThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlExpandEnvironmentStrings(WCHAR*  renv, WCHAR*  src, SIZE_T  src_len, WCHAR*  dst, SIZE_T  count, SIZE_T*  plen) /* ../dlls/ntdll/env.c:274 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlExpandEnvironmentStrings\n");
	return_value = pRtlExpandEnvironmentStrings(renv, src, src_len, dst, count, plen);
	TRACE("Leave RtlExpandEnvironmentStrings\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlExpandEnvironmentStrings(void);  /* ../dlls/ntdll/env.c:274 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlExpandEnvironmentStrings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlExpandEnvironmentStrings") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlExpandEnvironmentStrings_U(WCHAR*  env, UNICODE_STRING*  src, UNICODE_STRING*  dst, ULONG*  plen) /* ../dlls/ntdll/env.c:345 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlExpandEnvironmentStrings_U\n");
	return_value = pRtlExpandEnvironmentStrings_U(env, src, dst, plen);
	TRACE("Leave RtlExpandEnvironmentStrings_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlExpandEnvironmentStrings_U(void);  /* ../dlls/ntdll/env.c:345 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlExpandEnvironmentStrings_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlExpandEnvironmentStrings_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlFillMemory(void*  Destination, SIZE_T  Length, BYTE  Fill) /* ../dlls/ntdll/rtl.c:465 */
{
	TRACE("Enter RtlFillMemory\n");
	pRtlFillMemory(Destination, Length, Fill);
	TRACE("Leave RtlFillMemory\n");
}

extern WINAPI void wine32a_ntdll_RtlFillMemory(void);  /* ../dlls/ntdll/rtl.c:465 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFillMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFillMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlFillMemoryUlong(ULONG*  lpDest, ULONG  ulCount, ULONG  ulValue) /* ../dlls/ntdll/rtl.c:568 */
{
	TRACE("Enter RtlFillMemoryUlong\n");
	pRtlFillMemoryUlong(lpDest, ulCount, ulValue);
	TRACE("Leave RtlFillMemoryUlong\n");
}

extern WINAPI void wine32a_ntdll_RtlFillMemoryUlong(void);  /* ../dlls/ntdll/rtl.c:568 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFillMemoryUlong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFillMemoryUlong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFindActivationContextSectionGuid(ULONG  flags, GUID*  extguid, ULONG  section_kind, GUID*  guid, void*  ptr) /* ../dlls/ntdll/actctx.c:5529 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFindActivationContextSectionGuid\n");
	return_value = pRtlFindActivationContextSectionGuid(flags, extguid, section_kind, guid, ptr);
	TRACE("Leave RtlFindActivationContextSectionGuid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindActivationContextSectionGuid(void);  /* ../dlls/ntdll/actctx.c:5529 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindActivationContextSectionGuid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindActivationContextSectionGuid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFindActivationContextSectionString(ULONG  flags, GUID*  guid, ULONG  section_kind, UNICODE_STRING*  section_name, PVOID  ptr) /* ../dlls/ntdll/actctx.c:5485 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFindActivationContextSectionString\n");
	return_value = pRtlFindActivationContextSectionString(flags, guid, section_kind, section_name, ptr);
	TRACE("Leave RtlFindActivationContextSectionString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindActivationContextSectionString(void);  /* ../dlls/ntdll/actctx.c:5485 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindActivationContextSectionString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindActivationContextSectionString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFindCharInUnicodeString(int  flags, UNICODE_STRING*  main_str, UNICODE_STRING*  search_chars, USHORT*  pos) /* ../dlls/ntdll/rtlstr.c:1549 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFindCharInUnicodeString\n");
	return_value = pRtlFindCharInUnicodeString(flags, main_str, search_chars, pos);
	TRACE("Leave RtlFindCharInUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindCharInUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:1549 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindCharInUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindCharInUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindClearBits(PCRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint) /* ../dlls/ntdll/rtlbitmap.c:441 */
{
	ULONG return_value;
	TRACE("Enter RtlFindClearBits\n");
	return_value = pRtlFindClearBits(lpBits, ulCount, ulHint);
	TRACE("Leave RtlFindClearBits\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindClearBits(void);  /* ../dlls/ntdll/rtlbitmap.c:441 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindClearBitsAndSet(PRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint) /* ../dlls/ntdll/rtlbitmap.c:513 */
{
	ULONG return_value;
	TRACE("Enter RtlFindClearBitsAndSet\n");
	return_value = pRtlFindClearBitsAndSet(lpBits, ulCount, ulHint);
	TRACE("Leave RtlFindClearBitsAndSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindClearBitsAndSet(void);  /* ../dlls/ntdll/rtlbitmap.c:513 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindClearBitsAndSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindClearBitsAndSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindClearRuns(PCRTL_BITMAP  lpBits, PRTL_BITMAP_RUN  lpSeries, ULONG  ulCount, BOOLEAN  bLongest) /* ../dlls/ntdll/rtlbitmap.c:1055 */
{
	ULONG return_value;
	TRACE("Enter RtlFindClearRuns\n");
	return_value = pRtlFindClearRuns(lpBits, lpSeries, ulCount, bLongest);
	TRACE("Leave RtlFindClearRuns\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindClearRuns(void);  /* ../dlls/ntdll/rtlbitmap.c:1055 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindClearRuns,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindClearRuns") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindLastBackwardRunClear(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos) /* ../dlls/ntdll/rtlbitmap.c:956 */
{
	ULONG return_value;
	TRACE("Enter RtlFindLastBackwardRunClear\n");
	return_value = pRtlFindLastBackwardRunClear(lpBits, ulStart, lpPos);
	TRACE("Leave RtlFindLastBackwardRunClear\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindLastBackwardRunClear(void);  /* ../dlls/ntdll/rtlbitmap.c:956 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindLastBackwardRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindLastBackwardRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindLastBackwardRunSet(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos) /* ../dlls/ntdll/rtlbitmap.c:935 */
{
	ULONG return_value;
	TRACE("Enter RtlFindLastBackwardRunSet\n");
	return_value = pRtlFindLastBackwardRunSet(lpBits, ulStart, lpPos);
	TRACE("Leave RtlFindLastBackwardRunSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindLastBackwardRunSet(void);  /* ../dlls/ntdll/rtlbitmap.c:935 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindLastBackwardRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindLastBackwardRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI CCHAR wine32b_ntdll_RtlFindLeastSignificantBit(ULONGLONG  ulLong) /* ../dlls/ntdll/rtlbitmap.c:632 */
{
	CCHAR return_value;
	TRACE("Enter RtlFindLeastSignificantBit\n");
	return_value = pRtlFindLeastSignificantBit(ulLong);
	TRACE("Leave RtlFindLeastSignificantBit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindLeastSignificantBit(void);  /* ../dlls/ntdll/rtlbitmap.c:632 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindLeastSignificantBit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindLeastSignificantBit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindLongestRunClear(PCRTL_BITMAP  lpBits, PULONG  pulStart) /* ../dlls/ntdll/rtlbitmap.c:1102 */
{
	ULONG return_value;
	TRACE("Enter RtlFindLongestRunClear\n");
	return_value = pRtlFindLongestRunClear(lpBits, pulStart);
	TRACE("Leave RtlFindLongestRunClear\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindLongestRunClear(void);  /* ../dlls/ntdll/rtlbitmap.c:1102 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindLongestRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindLongestRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindLongestRunSet(PCRTL_BITMAP  lpBits, PULONG  pulStart) /* ../dlls/ntdll/rtlbitmap.c:1075 */
{
	ULONG return_value;
	TRACE("Enter RtlFindLongestRunSet\n");
	return_value = pRtlFindLongestRunSet(lpBits, pulStart);
	TRACE("Leave RtlFindLongestRunSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindLongestRunSet(void);  /* ../dlls/ntdll/rtlbitmap.c:1075 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindLongestRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindLongestRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFindMessage(HMODULE  hmod, ULONG  type, ULONG  lang, ULONG  msg_id, MESSAGE_RESOURCE_ENTRY**  ret) /* ../dlls/ntdll/resource.c:388 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFindMessage\n");
	return_value = pRtlFindMessage(hmod, type, lang, msg_id, ret);
	TRACE("Leave RtlFindMessage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindMessage(void);  /* ../dlls/ntdll/resource.c:388 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI CCHAR wine32b_ntdll_RtlFindMostSignificantBit(ULONGLONG  ulLong) /* ../dlls/ntdll/rtlbitmap.c:596 */
{
	CCHAR return_value;
	TRACE("Enter RtlFindMostSignificantBit\n");
	return_value = pRtlFindMostSignificantBit(ulLong);
	TRACE("Leave RtlFindMostSignificantBit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindMostSignificantBit(void);  /* ../dlls/ntdll/rtlbitmap.c:596 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindMostSignificantBit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindMostSignificantBit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindNextForwardRunClear(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos) /* ../dlls/ntdll/rtlbitmap.c:908 */
{
	ULONG return_value;
	TRACE("Enter RtlFindNextForwardRunClear\n");
	return_value = pRtlFindNextForwardRunClear(lpBits, ulStart, lpPos);
	TRACE("Leave RtlFindNextForwardRunClear\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindNextForwardRunClear(void);  /* ../dlls/ntdll/rtlbitmap.c:908 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindNextForwardRunClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindNextForwardRunClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindNextForwardRunSet(PCRTL_BITMAP  lpBits, ULONG  ulStart, PULONG  lpPos) /* ../dlls/ntdll/rtlbitmap.c:881 */
{
	ULONG return_value;
	TRACE("Enter RtlFindNextForwardRunSet\n");
	return_value = pRtlFindNextForwardRunSet(lpBits, ulStart, lpPos);
	TRACE("Leave RtlFindNextForwardRunSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindNextForwardRunSet(void);  /* ../dlls/ntdll/rtlbitmap.c:881 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindNextForwardRunSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindNextForwardRunSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindSetBits(PCRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint) /* ../dlls/ntdll/rtlbitmap.c:394 */
{
	ULONG return_value;
	TRACE("Enter RtlFindSetBits\n");
	return_value = pRtlFindSetBits(lpBits, ulCount, ulHint);
	TRACE("Leave RtlFindSetBits\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindSetBits(void);  /* ../dlls/ntdll/rtlbitmap.c:394 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindSetBitsAndClear(PRTL_BITMAP  lpBits, ULONG  ulCount, ULONG  ulHint) /* ../dlls/ntdll/rtlbitmap.c:488 */
{
	ULONG return_value;
	TRACE("Enter RtlFindSetBitsAndClear\n");
	return_value = pRtlFindSetBitsAndClear(lpBits, ulCount, ulHint);
	TRACE("Leave RtlFindSetBitsAndClear\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindSetBitsAndClear(void);  /* ../dlls/ntdll/rtlbitmap.c:488 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindSetBitsAndClear,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindSetBitsAndClear") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlFindSetRuns(PCRTL_BITMAP  lpBits, PRTL_BITMAP_RUN  lpSeries, ULONG  ulCount, BOOLEAN  bLongest) /* ../dlls/ntdll/rtlbitmap.c:1033 */
{
	ULONG return_value;
	TRACE("Enter RtlFindSetRuns\n");
	return_value = pRtlFindSetRuns(lpBits, lpSeries, ulCount, bLongest);
	TRACE("Leave RtlFindSetRuns\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFindSetRuns(void);  /* ../dlls/ntdll/rtlbitmap.c:1033 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFindSetRuns,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFindSetRuns") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlFirstEntrySList(SLIST_HEADER*  list) /* ../dlls/ntdll/rtl.c:1269 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlFirstEntrySList\n");
	return_value = pRtlFirstEntrySList(list);
	TRACE("Leave RtlFirstEntrySList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFirstEntrySList(void);  /* ../dlls/ntdll/rtl.c:1269 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFirstEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFirstEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlFirstFreeAce(PACL  acl, PACE_HEADER*  x) /* ../dlls/ntdll/sec.c:1146 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlFirstFreeAce\n");
	return_value = pRtlFirstFreeAce(acl, x);
	TRACE("Leave RtlFirstFreeAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFirstFreeAce(void);  /* ../dlls/ntdll/sec.c:1146 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFirstFreeAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFirstFreeAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFormatCurrentUserKeyPath(PUNICODE_STRING  KeyPath) /* ../dlls/ntdll/reg.c:919 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFormatCurrentUserKeyPath\n");
	return_value = pRtlFormatCurrentUserKeyPath(KeyPath);
	TRACE("Leave RtlFormatCurrentUserKeyPath\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFormatCurrentUserKeyPath(void);  /* ../dlls/ntdll/reg.c:919 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFormatCurrentUserKeyPath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFormatCurrentUserKeyPath") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlFormatMessage(LPWSTR  Message, UCHAR  MaxWidth, BOOLEAN  IgnoreInserts, BOOLEAN  Ansi, BOOLEAN  ArgumentIsArray, __builtin_ms_va_list*  Arguments, LPWSTR  Buffer, ULONG  BufferSize) /* ../dlls/ntdll/resource.c:443 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlFormatMessage\n");
	return_value = pRtlFormatMessage(Message, MaxWidth, IgnoreInserts, Ansi, ArgumentIsArray, Arguments, Buffer, BufferSize);
	TRACE("Leave RtlFormatMessage\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFormatMessage(void);  /* ../dlls/ntdll/resource.c:443 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFormatMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFormatMessage") "\n"
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

WINAPI void wine32b_ntdll_RtlFreeAnsiString(PSTRING  str) /* ../dlls/ntdll/rtlstr.c:171 */
{
	TRACE("Enter RtlFreeAnsiString\n");
	pRtlFreeAnsiString(str);
	TRACE("Leave RtlFreeAnsiString\n");
}

extern WINAPI void wine32a_ntdll_RtlFreeAnsiString(void);  /* ../dlls/ntdll/rtlstr.c:171 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlFreeHandle(RTL_HANDLE_TABLE*  HandleTable, RTL_HANDLE*  Handle) /* ../dlls/ntdll/handletable.c:236 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlFreeHandle\n");
	return_value = pRtlFreeHandle(HandleTable, Handle);
	TRACE("Leave RtlFreeHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFreeHandle(void);  /* ../dlls/ntdll/handletable.c:236 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlFreeHeap(HANDLE  heap, ULONG  flags, void*  ptr) /* ../dlls/ntdll/heap.c:1749 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlFreeHeap\n");
	return_value = pRtlFreeHeap(heap, flags, ptr);
	TRACE("Leave RtlFreeHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFreeHeap(void);  /* ../dlls/ntdll/heap.c:1749 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlFreeOemString(PSTRING  str) /* ../dlls/ntdll/rtlstr.c:184 */
{
	TRACE("Enter RtlFreeOemString\n");
	pRtlFreeOemString(str);
	TRACE("Leave RtlFreeOemString\n");
}

extern WINAPI void wine32a_ntdll_RtlFreeOemString(void);  /* ../dlls/ntdll/rtlstr.c:184 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlFreeSid(PSID  pSid) /* ../dlls/ntdll/sec.c:243 */
{
	DWORD return_value;
	TRACE("Enter RtlFreeSid\n");
	return_value = pRtlFreeSid(pSid);
	TRACE("Leave RtlFreeSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlFreeSid(void);  /* ../dlls/ntdll/sec.c:243 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlFreeThreadActivationContextStack(void) /* ../dlls/ntdll/actctx.c:5179 */
{
	TRACE("Enter RtlFreeThreadActivationContextStack\n");
	pRtlFreeThreadActivationContextStack();
	TRACE("Leave RtlFreeThreadActivationContextStack\n");
}

extern WINAPI void wine32a_ntdll_RtlFreeThreadActivationContextStack(void);  /* ../dlls/ntdll/actctx.c:5179 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeThreadActivationContextStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeThreadActivationContextStack") "\n"
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

WINAPI void wine32b_ntdll_RtlFreeUnicodeString(PUNICODE_STRING  str) /* ../dlls/ntdll/rtlstr.c:317 */
{
	TRACE("Enter RtlFreeUnicodeString\n");
	pRtlFreeUnicodeString(str);
	TRACE("Leave RtlFreeUnicodeString\n");
}

extern WINAPI void wine32a_ntdll_RtlFreeUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:317 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlFreeUserStack(void*  stack) /* ../dlls/ntdll/virtual.c:2075 */
{
	TRACE("Enter RtlFreeUserStack\n");
	pRtlFreeUserStack(stack);
	TRACE("Leave RtlFreeUserStack\n");
}

extern WINAPI void wine32a_ntdll_RtlFreeUserStack(void);  /* ../dlls/ntdll/virtual.c:2075 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlFreeUserStack,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlFreeUserStack") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGUIDFromString(PUNICODE_STRING  str, GUID*  guid) /* ../dlls/ntdll/rtlstr.c:2067 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGUIDFromString\n");
	return_value = pRtlGUIDFromString(str, guid);
	TRACE("Leave RtlGUIDFromString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGUIDFromString(void);  /* ../dlls/ntdll/rtlstr.c:2067 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGUIDFromString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGUIDFromString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetAce(PACL  pAcl, DWORD  dwAceIndex, LPVOID*  pAce) /* ../dlls/ntdll/sec.c:1452 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetAce\n");
	return_value = pRtlGetAce(pAcl, dwAceIndex, pAce);
	TRACE("Leave RtlGetAce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetAce(void);  /* ../dlls/ntdll/sec.c:1452 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetAce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetAce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetActiveActivationContext(HANDLE*  handle) /* ../dlls/ntdll/actctx.c:5198 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetActiveActivationContext\n");
	return_value = pRtlGetActiveActivationContext(handle);
	TRACE("Leave RtlGetActiveActivationContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetActiveActivationContext(void);  /* ../dlls/ntdll/actctx.c:5198 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetActiveActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetActiveActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetCompressionWorkSpaceSize(USHORT  format, PULONG  compress_workspace, PULONG  decompress_workspace) /* ../dlls/ntdll/rtl.c:1431 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetCompressionWorkSpaceSize\n");
	return_value = pRtlGetCompressionWorkSpaceSize(format, compress_workspace, decompress_workspace);
	TRACE("Leave RtlGetCompressionWorkSpaceSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetCompressionWorkSpaceSize(void);  /* ../dlls/ntdll/rtl.c:1431 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetCompressionWorkSpaceSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetCompressionWorkSpaceSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetControlSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSECURITY_DESCRIPTOR_CONTROL  pControl, LPDWORD  lpdwRevision) /* ../dlls/ntdll/sec.c:1043 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetControlSecurityDescriptor\n");
	return_value = pRtlGetControlSecurityDescriptor(pSecurityDescriptor, pControl, lpdwRevision);
	TRACE("Leave RtlGetControlSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetControlSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:1043 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetControlSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetControlSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlGetCurrentDirectory_U(ULONG  buflen, LPWSTR  buf) /* ../dlls/ntdll/path.c:957 */
{
	ULONG return_value;
	TRACE("Enter RtlGetCurrentDirectory_U\n");
	return_value = pRtlGetCurrentDirectory_U(buflen, buf);
	TRACE("Leave RtlGetCurrentDirectory_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetCurrentDirectory_U(void);  /* ../dlls/ntdll/path.c:957 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetCurrentDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetCurrentDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PEB* wine32b_ntdll_RtlGetCurrentPeb(void) /* ../dlls/ntdll/process.c:99 */
{
	PEB* return_value;
	TRACE("Enter RtlGetCurrentPeb\n");
	return_value = pRtlGetCurrentPeb();
	TRACE("Leave RtlGetCurrentPeb\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetCurrentPeb(void);  /* ../dlls/ntdll/process.c:99 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetCurrentPeb,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetCurrentPeb") "\n"
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

WINAPI void wine32b_ntdll_RtlGetCurrentProcessorNumberEx(PROCESSOR_NUMBER*  processor) /* ../dlls/ntdll/rtl.c:1795 */
{
	TRACE("Enter RtlGetCurrentProcessorNumberEx\n");
	pRtlGetCurrentProcessorNumberEx(processor);
	TRACE("Leave RtlGetCurrentProcessorNumberEx\n");
}

extern WINAPI void wine32a_ntdll_RtlGetCurrentProcessorNumberEx(void);  /* ../dlls/ntdll/rtl.c:1795 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetCurrentProcessorNumberEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetCurrentProcessorNumberEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI HANDLE wine32b_ntdll_RtlGetCurrentTransaction(void) /* ../dlls/ntdll/rtl.c:1777 */
{
	HANDLE return_value;
	TRACE("Enter RtlGetCurrentTransaction\n");
	return_value = pRtlGetCurrentTransaction();
	TRACE("Leave RtlGetCurrentTransaction\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetCurrentTransaction(void);  /* ../dlls/ntdll/rtl.c:1777 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetCurrentTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetCurrentTransaction") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlGetDaclSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PBOOLEAN  lpbDaclPresent, PACL*  pDacl, PBOOLEAN  lpbDaclDefaulted) /* ../dlls/ntdll/sec.c:606 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetDaclSecurityDescriptor\n");
	return_value = pRtlGetDaclSecurityDescriptor(pSecurityDescriptor, lpbDaclPresent, pDacl, lpbDaclDefaulted);
	TRACE("Leave RtlGetDaclSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetDaclSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:606 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetDaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetDaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI TEB_ACTIVE_FRAME* wine32b_ntdll_RtlGetFrame(void) /* ../dlls/ntdll/thread.c:723 */
{
	TEB_ACTIVE_FRAME* return_value;
	TRACE("Enter RtlGetFrame\n");
	return_value = pRtlGetFrame();
	TRACE("Leave RtlGetFrame\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetFrame(void);  /* ../dlls/ntdll/thread.c:723 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetFrame") "\n"
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

WINAPI ULONG wine32b_ntdll_RtlGetFullPathName_U(WCHAR*  name, ULONG  size, WCHAR*  buffer, WCHAR**  file_part) /* ../dlls/ntdll/path.c:818 */
{
	ULONG return_value;
	TRACE("Enter RtlGetFullPathName_U\n");
	return_value = pRtlGetFullPathName_U(name, size, buffer, file_part);
	TRACE("Leave RtlGetFullPathName_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetFullPathName_U(void);  /* ../dlls/ntdll/path.c:818 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetFullPathName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetFullPathName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetGroupSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID*  Group, PBOOLEAN  GroupDefaulted) /* ../dlls/ntdll/sec.c:814 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetGroupSecurityDescriptor\n");
	return_value = pRtlGetGroupSecurityDescriptor(pSecurityDescriptor, Group, GroupDefaulted);
	TRACE("Leave RtlGetGroupSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetGroupSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:814 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetGroupSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetGroupSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetLastNtStatus(void) /* ../dlls/ntdll/error.c:111 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetLastNtStatus\n");
	return_value = pRtlGetLastNtStatus();
	TRACE("Leave RtlGetLastNtStatus\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetLastNtStatus(void);  /* ../dlls/ntdll/error.c:111 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetLastNtStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetLastNtStatus") "\n"
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

WINAPI DWORD wine32b_ntdll_RtlGetLastWin32Error(void) /* ../dlls/ntdll/error.c:127 */
{
	DWORD return_value;
	TRACE("Enter RtlGetLastWin32Error\n");
	return_value = pRtlGetLastWin32Error();
	TRACE("Leave RtlGetLastWin32Error\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetLastWin32Error(void);  /* ../dlls/ntdll/error.c:127 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetLastWin32Error,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetLastWin32Error") "\n"
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

WINAPI DWORD wine32b_ntdll_RtlGetLongestNtPathLength(void) /* ../dlls/ntdll/path.c:878 */
{
	DWORD return_value;
	TRACE("Enter RtlGetLongestNtPathLength\n");
	return_value = pRtlGetLongestNtPathLength();
	TRACE("Leave RtlGetLongestNtPathLength\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetLongestNtPathLength(void);  /* ../dlls/ntdll/path.c:878 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetLongestNtPathLength,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetLongestNtPathLength") "\n"
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

WINAPI ULONG wine32b_ntdll_RtlGetNtGlobalFlags(void) /* ../dlls/ntdll/thread.c:559 */
{
	ULONG return_value;
	TRACE("Enter RtlGetNtGlobalFlags\n");
	return_value = pRtlGetNtGlobalFlags();
	TRACE("Leave RtlGetNtGlobalFlags\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetNtGlobalFlags(void);  /* ../dlls/ntdll/thread.c:559 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetNtGlobalFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetNtGlobalFlags") "\n"
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

WINAPI BOOLEAN wine32b_ntdll_RtlGetNtProductType(LPDWORD  type) /* ../dlls/ntdll/version.c:654 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlGetNtProductType\n");
	return_value = pRtlGetNtProductType(type);
	TRACE("Leave RtlGetNtProductType\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetNtProductType(void);  /* ../dlls/ntdll/version.c:654 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetNtProductType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetNtProductType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlGetNtVersionNumbers(LPDWORD  major, LPDWORD  minor, LPDWORD  build) /* ../dlls/ntdll/version.c:642 */
{
	TRACE("Enter RtlGetNtVersionNumbers\n");
	pRtlGetNtVersionNumbers(major, minor, build);
	TRACE("Leave RtlGetNtVersionNumbers\n");
}

extern WINAPI void wine32a_ntdll_RtlGetNtVersionNumbers(void);  /* ../dlls/ntdll/version.c:642 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetNtVersionNumbers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetNtVersionNumbers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetOwnerSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID*  Owner, PBOOLEAN  OwnerDefaulted) /* ../dlls/ntdll/sec.c:738 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetOwnerSecurityDescriptor\n");
	return_value = pRtlGetOwnerSecurityDescriptor(pSecurityDescriptor, Owner, OwnerDefaulted);
	TRACE("Leave RtlGetOwnerSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetOwnerSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:738 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetOwnerSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetOwnerSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlGetProductInfo(DWORD  dwOSMajorVersion, DWORD  dwOSMinorVersion, DWORD  dwSpMajorVersion, DWORD  dwSpMinorVersion, PDWORD  pdwReturnedProductType) /* ../dlls/ntdll/version.c:582 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlGetProductInfo\n");
	return_value = pRtlGetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
	TRACE("Leave RtlGetProductInfo\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetProductInfo(void);  /* ../dlls/ntdll/version.c:582 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetProductInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetProductInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlGetProcessHeaps(ULONG  count, HANDLE*  heaps) /* ../dlls/ntdll/heap.c:2225 */
{
	ULONG return_value;
	TRACE("Enter RtlGetProcessHeaps\n");
	return_value = pRtlGetProcessHeaps(count, heaps);
	TRACE("Leave RtlGetProcessHeaps\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetProcessHeaps(void);  /* ../dlls/ntdll/heap.c:2225 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetProcessHeaps,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetProcessHeaps") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetSaclSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PBOOLEAN  lpbSaclPresent, PACL*  pSacl, PBOOLEAN  lpbSaclDefaulted) /* ../dlls/ntdll/sec.c:678 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetSaclSecurityDescriptor\n");
	return_value = pRtlGetSaclSecurityDescriptor(pSecurityDescriptor, lpbSaclPresent, pSacl, lpbSaclDefaulted);
	TRACE("Leave RtlGetSaclSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetSaclSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:678 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetSaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetSaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONGLONG wine32b_ntdll_RtlGetSystemTimePrecise(void) /* ../dlls/ntdll/time.c:511 */
{
	LONGLONG return_value;
	TRACE("Enter RtlGetSystemTimePrecise\n");
	return_value = pRtlGetSystemTimePrecise();
	TRACE("Leave RtlGetSystemTimePrecise\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetSystemTimePrecise(void);  /* ../dlls/ntdll/time.c:511 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetSystemTimePrecise,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetSystemTimePrecise") "\n"
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

WINAPI DWORD wine32b_ntdll_RtlGetThreadErrorMode(void) /* ../dlls/ntdll/rtl.c:1769 */
{
	DWORD return_value;
	TRACE("Enter RtlGetThreadErrorMode\n");
	return_value = pRtlGetThreadErrorMode();
	TRACE("Leave RtlGetThreadErrorMode\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetThreadErrorMode(void);  /* ../dlls/ntdll/rtl.c:1769 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetThreadErrorMode") "\n"
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

WINAPI RTL_UNLOAD_EVENT_TRACE* wine32b_ntdll_RtlGetUnloadEventTrace(void) /* ../dlls/ntdll/loader.c:198 */
{
	RTL_UNLOAD_EVENT_TRACE* return_value;
	TRACE("Enter RtlGetUnloadEventTrace\n");
	return_value = pRtlGetUnloadEventTrace();
	TRACE("Leave RtlGetUnloadEventTrace\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetUnloadEventTrace(void);  /* ../dlls/ntdll/loader.c:198 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetUnloadEventTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetUnloadEventTrace") "\n"
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

WINAPI void wine32b_ntdll_RtlGetUnloadEventTraceEx(ULONG**  size, ULONG**  count, void**  trace) /* ../dlls/ntdll/loader.c:206 */
{
	TRACE("Enter RtlGetUnloadEventTraceEx\n");
	pRtlGetUnloadEventTraceEx(size, count, trace);
	TRACE("Leave RtlGetUnloadEventTraceEx\n");
}

extern WINAPI void wine32a_ntdll_RtlGetUnloadEventTraceEx(void);  /* ../dlls/ntdll/loader.c:206 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetUnloadEventTraceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetUnloadEventTraceEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlGetVersion(RTL_OSVERSIONINFOEXW*  info) /* ../dlls/ntdll/version.c:608 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlGetVersion\n");
	return_value = pRtlGetVersion(info);
	TRACE("Leave RtlGetVersion\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlGetVersion(void);  /* ../dlls/ntdll/version.c:608 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGetVersion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGetVersion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlGrowFunctionTable(void*  table, DWORD  count) /* ../dlls/ntdll/exception.c:497 */
{
	TRACE("Enter RtlGrowFunctionTable\n");
	pRtlGrowFunctionTable(table, count);
	TRACE("Leave RtlGrowFunctionTable\n");
}

extern WINAPI void wine32a_ntdll_RtlGrowFunctionTable(void);  /* ../dlls/ntdll/exception.c:497 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlGrowFunctionTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlGrowFunctionTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlHashUnicodeString(PCUNICODE_STRING  string, BOOLEAN  case_insensitive, ULONG  alg, ULONG*  hash) /* ../dlls/ntdll/rtlstr.c:2186 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlHashUnicodeString\n");
	return_value = pRtlHashUnicodeString(string, case_insensitive, alg, hash);
	TRACE("Leave RtlHashUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlHashUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:2186 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlHashUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlHashUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSID_IDENTIFIER_AUTHORITY wine32b_ntdll_RtlIdentifierAuthoritySid(PSID  pSid) /* ../dlls/ntdll/sec.c:348 */
{
	PSID_IDENTIFIER_AUTHORITY return_value;
	TRACE("Enter RtlIdentifierAuthoritySid\n");
	return_value = pRtlIdentifierAuthoritySid(pSid);
	TRACE("Leave RtlIdentifierAuthoritySid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIdentifierAuthoritySid(void);  /* ../dlls/ntdll/sec.c:348 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIdentifierAuthoritySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIdentifierAuthoritySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlImageDirectoryEntryToData(HMODULE  module, BOOL  image, WORD  dir, ULONG*  size) /* ../dlls/ntdll/loader.c:3878 */
{
	PVOID return_value;
	TRACE("Enter RtlImageDirectoryEntryToData\n");
	return_value = pRtlImageDirectoryEntryToData(module, image, dir, size);
	TRACE("Leave RtlImageDirectoryEntryToData\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlImageDirectoryEntryToData(void);  /* ../dlls/ntdll/loader.c:3878 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlImageDirectoryEntryToData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlImageDirectoryEntryToData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PIMAGE_NT_HEADERS wine32b_ntdll_RtlImageNtHeader(HMODULE  hModule) /* ../dlls/ntdll/loader.c:3725 */
{
	PIMAGE_NT_HEADERS return_value;
	TRACE("Enter RtlImageNtHeader\n");
	return_value = pRtlImageNtHeader(hModule);
	TRACE("Leave RtlImageNtHeader\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlImageNtHeader(void);  /* ../dlls/ntdll/loader.c:3725 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlImageNtHeader,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlImageNtHeader") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PIMAGE_SECTION_HEADER wine32b_ntdll_RtlImageRvaToSection(IMAGE_NT_HEADERS*  nt, HMODULE  module, DWORD  rva) /* ../dlls/ntdll/loader.c:3914 */
{
	PIMAGE_SECTION_HEADER return_value;
	TRACE("Enter RtlImageRvaToSection\n");
	return_value = pRtlImageRvaToSection(nt, module, rva);
	TRACE("Leave RtlImageRvaToSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlImageRvaToSection(void);  /* ../dlls/ntdll/loader.c:3914 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlImageRvaToSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlImageRvaToSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlImageRvaToVa(IMAGE_NT_HEADERS*  nt, HMODULE  module, DWORD  rva, IMAGE_SECTION_HEADER**  section) /* ../dlls/ntdll/loader.c:3934 */
{
	PVOID return_value;
	TRACE("Enter RtlImageRvaToVa\n");
	return_value = pRtlImageRvaToVa(nt, module, rva, section);
	TRACE("Leave RtlImageRvaToVa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlImageRvaToVa(void);  /* ../dlls/ntdll/loader.c:3934 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlImageRvaToVa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlImageRvaToVa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlImpersonateSelf(SECURITY_IMPERSONATION_LEVEL  ImpersonationLevel) /* ../dlls/ntdll/sec.c:1575 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlImpersonateSelf\n");
	return_value = pRtlImpersonateSelf(ImpersonationLevel);
	TRACE("Leave RtlImpersonateSelf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlImpersonateSelf(void);  /* ../dlls/ntdll/sec.c:1575 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlImpersonateSelf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlImpersonateSelf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitAnsiString(PANSI_STRING  target, PCSZ  source) /* ../dlls/ntdll/rtlstr.c:101 */
{
	TRACE("Enter RtlInitAnsiString\n");
	pRtlInitAnsiString(target, source);
	TRACE("Leave RtlInitAnsiString\n");
}

extern WINAPI void wine32a_ntdll_RtlInitAnsiString(void);  /* ../dlls/ntdll/rtlstr.c:101 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlInitAnsiStringEx(PANSI_STRING  target, PCSZ  source) /* ../dlls/ntdll/rtlstr.c:126 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInitAnsiStringEx\n");
	return_value = pRtlInitAnsiStringEx(target, source);
	TRACE("Leave RtlInitAnsiStringEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitAnsiStringEx(void);  /* ../dlls/ntdll/rtlstr.c:126 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitAnsiStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitAnsiStringEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitString(PSTRING  target, PCSZ  source) /* ../dlls/ntdll/rtlstr.c:160 */
{
	TRACE("Enter RtlInitString\n");
	pRtlInitString(target, source);
	TRACE("Leave RtlInitString\n");
}

extern WINAPI void wine32a_ntdll_RtlInitString(void);  /* ../dlls/ntdll/rtlstr.c:160 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitUnicodeString(PUNICODE_STRING  target, PCWSTR  source) /* ../dlls/ntdll/rtlstr.c:218 */
{
	TRACE("Enter RtlInitUnicodeString\n");
	pRtlInitUnicodeString(target, source);
	TRACE("Leave RtlInitUnicodeString\n");
}

extern WINAPI void wine32a_ntdll_RtlInitUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:218 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlInitUnicodeStringEx(PUNICODE_STRING  target, PCWSTR  source) /* ../dlls/ntdll/rtlstr.c:248 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInitUnicodeStringEx\n");
	return_value = pRtlInitUnicodeStringEx(target, source);
	TRACE("Leave RtlInitUnicodeStringEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitUnicodeStringEx(void);  /* ../dlls/ntdll/rtlstr.c:248 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitUnicodeStringEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitUnicodeStringEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeBitMap(PRTL_BITMAP  lpBits, PULONG  lpBuff, ULONG  ulSize) /* ../dlls/ntdll/rtlbitmap.c:75 */
{
	TRACE("Enter RtlInitializeBitMap\n");
	pRtlInitializeBitMap(lpBits, lpBuff, ulSize);
	TRACE("Leave RtlInitializeBitMap\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeBitMap(void);  /* ../dlls/ntdll/rtlbitmap.c:75 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeBitMap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeBitMap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeConditionVariable(RTL_CONDITION_VARIABLE*  variable) /* ../dlls/ntdll/sync.c:2233 */
{
	TRACE("Enter RtlInitializeConditionVariable\n");
	pRtlInitializeConditionVariable(variable);
	TRACE("Leave RtlInitializeConditionVariable\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeConditionVariable(void);  /* ../dlls/ntdll/sync.c:2233 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlInitializeCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:267 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInitializeCriticalSection\n");
	return_value = pRtlInitializeCriticalSection(crit);
	TRACE("Leave RtlInitializeCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitializeCriticalSection(void);  /* ../dlls/ntdll/critsection.c:267 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlInitializeCriticalSectionAndSpinCount(RTL_CRITICAL_SECTION*  crit, ULONG  spincount) /* ../dlls/ntdll/critsection.c:293 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInitializeCriticalSectionAndSpinCount\n");
	return_value = pRtlInitializeCriticalSectionAndSpinCount(crit, spincount);
	TRACE("Leave RtlInitializeCriticalSectionAndSpinCount\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitializeCriticalSectionAndSpinCount(void);  /* ../dlls/ntdll/critsection.c:293 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeCriticalSectionAndSpinCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeCriticalSectionAndSpinCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlInitializeCriticalSectionEx(RTL_CRITICAL_SECTION*  crit, ULONG  spincount, ULONG  flags) /* ../dlls/ntdll/critsection.c:319 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInitializeCriticalSectionEx\n");
	return_value = pRtlInitializeCriticalSectionEx(crit, spincount, flags);
	TRACE("Leave RtlInitializeCriticalSectionEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitializeCriticalSectionEx(void);  /* ../dlls/ntdll/critsection.c:319 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeCriticalSectionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeCriticalSectionEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlInitializeGenericTable(PVOID  pTable, PVOID  arg2, PVOID  arg3, PVOID  arg4, PVOID  arg5) /* ../dlls/ntdll/rtl.c:405 */
{
	PVOID return_value;
	TRACE("Enter RtlInitializeGenericTable\n");
	return_value = pRtlInitializeGenericTable(pTable, arg2, arg3, arg4, arg5);
	TRACE("Leave RtlInitializeGenericTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitializeGenericTable(void);  /* ../dlls/ntdll/rtl.c:405 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeGenericTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeGenericTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeGenericTableAvl(PRTL_AVL_TABLE  table, PRTL_AVL_COMPARE_ROUTINE  compare, PRTL_AVL_ALLOCATE_ROUTINE  allocate, PRTL_AVL_FREE_ROUTINE  free, void*  context) /* ../dlls/ntdll/rtl.c:1806 */
{
	TRACE("Enter RtlInitializeGenericTableAvl\n");
	pRtlInitializeGenericTableAvl(table, compare, allocate, free, context);
	TRACE("Leave RtlInitializeGenericTableAvl\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeGenericTableAvl(void);  /* ../dlls/ntdll/rtl.c:1806 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeGenericTableAvl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeGenericTableAvl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeHandleTable(ULONG  MaxHandleCount, ULONG  HandleSize, RTL_HANDLE_TABLE*  HandleTable) /* ../dlls/ntdll/handletable.c:48 */
{
	TRACE("Enter RtlInitializeHandleTable\n");
	pRtlInitializeHandleTable(MaxHandleCount, HandleSize, HandleTable);
	TRACE("Leave RtlInitializeHandleTable\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeHandleTable(void);  /* ../dlls/ntdll/handletable.c:48 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeHandleTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeHandleTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeResource(LPRTL_RWLOCK  rwl) /* ../dlls/ntdll/rtl.c:111 */
{
	TRACE("Enter RtlInitializeResource\n");
	pRtlInitializeResource(rwl);
	TRACE("Leave RtlInitializeResource\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeResource(void);  /* ../dlls/ntdll/rtl.c:111 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeSListHead(PSLIST_HEADER  list) /* ../dlls/ntdll/rtl.c:1244 */
{
	TRACE("Enter RtlInitializeSListHead\n");
	pRtlInitializeSListHead(list);
	TRACE("Leave RtlInitializeSListHead\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeSListHead(void);  /* ../dlls/ntdll/rtl.c:1244 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeSListHead,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeSListHead") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInitializeSRWLock(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2057 */
{
	TRACE("Enter RtlInitializeSRWLock\n");
	pRtlInitializeSRWLock(lock);
	TRACE("Leave RtlInitializeSRWLock\n");
}

extern WINAPI void wine32a_ntdll_RtlInitializeSRWLock(void);  /* ../dlls/ntdll/sync.c:2057 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeSRWLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeSRWLock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlInitializeSid(PSID  pSid, PSID_IDENTIFIER_AUTHORITY  pIdentifierAuthority, BYTE  nSubAuthorityCount) /* ../dlls/ntdll/sec.c:298 */
{
	BOOL return_value;
	TRACE("Enter RtlInitializeSid\n");
	return_value = pRtlInitializeSid(pSid, pIdentifierAuthority, nSubAuthorityCount);
	TRACE("Leave RtlInitializeSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInitializeSid(void);  /* ../dlls/ntdll/sec.c:298 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInitializeSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInitializeSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlInsertElementGenericTableAvl(PRTL_AVL_TABLE  table, void*  buffer, ULONG  size, BOOL*  element) /* ../dlls/ntdll/rtl.c:1815 */
{
	TRACE("Enter RtlInsertElementGenericTableAvl\n");
	pRtlInsertElementGenericTableAvl(table, buffer, size, element);
	TRACE("Leave RtlInsertElementGenericTableAvl\n");
}

extern WINAPI void wine32a_ntdll_RtlInsertElementGenericTableAvl(void);  /* ../dlls/ntdll/rtl.c:1815 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInsertElementGenericTableAvl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInsertElementGenericTableAvl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlInstallFunctionTableCallback(ULONG_PTR  table, ULONG_PTR  base, DWORD  length, PGET_RUNTIME_FUNCTION_CALLBACK  callback, PVOID  context, PCWSTR  dll) /* ../dlls/ntdll/exception.c:428 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlInstallFunctionTableCallback\n");
	return_value = pRtlInstallFunctionTableCallback(table, base, length, callback, context, dll);
	TRACE("Leave RtlInstallFunctionTableCallback\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInstallFunctionTableCallback(void);  /* ../dlls/ntdll/exception.c:428 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInstallFunctionTableCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInstallFunctionTableCallback") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlInt64ToUnicodeString(ULONGLONG  value, ULONG  base, UNICODE_STRING*  str) /* ../dlls/ntdll/large_int.c:484 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlInt64ToUnicodeString\n");
	return_value = pRtlInt64ToUnicodeString(value, base, str);
	TRACE("Leave RtlInt64ToUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInt64ToUnicodeString(void);  /* ../dlls/ntdll/large_int.c:484 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInt64ToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInt64ToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIntegerToChar(ULONG  value, ULONG  base, ULONG  length, PCHAR  str) /* ../dlls/ntdll/rtlstr.c:1844 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIntegerToChar\n");
	return_value = pRtlIntegerToChar(value, base, length, str);
	TRACE("Leave RtlIntegerToChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIntegerToChar(void);  /* ../dlls/ntdll/rtlstr.c:1844 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIntegerToChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIntegerToChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIntegerToUnicodeString(ULONG  value, ULONG  base, UNICODE_STRING*  str) /* ../dlls/ntdll/rtlstr.c:2012 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIntegerToUnicodeString\n");
	return_value = pRtlIntegerToUnicodeString(value, base, str);
	TRACE("Leave RtlIntegerToUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIntegerToUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:2012 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIntegerToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIntegerToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlInterlockedFlushSList(PSLIST_HEADER  list) /* ../dlls/ntdll/rtl.c:1281 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlInterlockedFlushSList\n");
	return_value = pRtlInterlockedFlushSList(list);
	TRACE("Leave RtlInterlockedFlushSList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInterlockedFlushSList(void);  /* ../dlls/ntdll/rtl.c:1281 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInterlockedFlushSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInterlockedFlushSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlInterlockedPopEntrySList(PSLIST_HEADER  list) /* ../dlls/ntdll/rtl.c:1342 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlInterlockedPopEntrySList\n");
	return_value = pRtlInterlockedPopEntrySList(list);
	TRACE("Leave RtlInterlockedPopEntrySList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInterlockedPopEntrySList(void);  /* ../dlls/ntdll/rtl.c:1342 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInterlockedPopEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInterlockedPopEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlInterlockedPushEntrySList(PSLIST_HEADER  list, PSLIST_ENTRY  entry) /* ../dlls/ntdll/rtl.c:1311 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlInterlockedPushEntrySList\n");
	return_value = pRtlInterlockedPushEntrySList(list, entry);
	TRACE("Leave RtlInterlockedPushEntrySList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInterlockedPushEntrySList(void);  /* ../dlls/ntdll/rtl.c:1311 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInterlockedPushEntrySList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInterlockedPushEntrySList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlInterlockedPushListSList(PSLIST_HEADER  list, PSLIST_ENTRY  first, PSLIST_ENTRY  last, ULONG  count) /* ../dlls/ntdll/rtl.c:1422 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlInterlockedPushListSList\n");
	return_value = pRtlInterlockedPushListSList(list, first, last, count);
	TRACE("Leave RtlInterlockedPushListSList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInterlockedPushListSList(void);  /* ../dlls/ntdll/rtl.c:1422 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInterlockedPushListSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInterlockedPushListSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PSLIST_ENTRY wine32b_ntdll_RtlInterlockedPushListSListEx(PSLIST_HEADER  list, PSLIST_ENTRY  first, PSLIST_ENTRY  last, ULONG  count) /* ../dlls/ntdll/rtl.c:1389 */
{
	PSLIST_ENTRY return_value;
	TRACE("Enter RtlInterlockedPushListSListEx\n");
	return_value = pRtlInterlockedPushListSListEx(list, first, last, count);
	TRACE("Leave RtlInterlockedPushListSListEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlInterlockedPushListSListEx(void);  /* ../dlls/ntdll/rtl.c:1389 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlInterlockedPushListSListEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlInterlockedPushListSListEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI CHAR* wine32b_ntdll_RtlIpv4AddressToStringA(IN_ADDR*  pin, LPSTR  buffer) /* ../dlls/ntdll/rtl.c:1191 */
{
	CHAR* return_value;
	TRACE("Enter RtlIpv4AddressToStringA\n");
	return_value = pRtlIpv4AddressToStringA(pin, buffer);
	TRACE("Leave RtlIpv4AddressToStringA\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4AddressToStringA(void);  /* ../dlls/ntdll/rtl.c:1191 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4AddressToStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4AddressToStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4AddressToStringExA(IN_ADDR*  pin, USHORT  port, LPSTR  buffer, PULONG  psize) /* ../dlls/ntdll/rtl.c:1137 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4AddressToStringExA\n");
	return_value = pRtlIpv4AddressToStringExA(pin, port, buffer, psize);
	TRACE("Leave RtlIpv4AddressToStringExA\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4AddressToStringExA(void);  /* ../dlls/ntdll/rtl.c:1137 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4AddressToStringExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4AddressToStringExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4AddressToStringExW(IN_ADDR*  pin, USHORT  port, LPWSTR  buffer, PULONG  psize) /* ../dlls/ntdll/rtl.c:1102 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4AddressToStringExW\n");
	return_value = pRtlIpv4AddressToStringExW(pin, port, buffer, psize);
	TRACE("Leave RtlIpv4AddressToStringExW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4AddressToStringExW(void);  /* ../dlls/ntdll/rtl.c:1102 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4AddressToStringExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4AddressToStringExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI WCHAR* wine32b_ntdll_RtlIpv4AddressToStringW(IN_ADDR*  pin, LPWSTR  buffer) /* ../dlls/ntdll/rtl.c:1176 */
{
	WCHAR* return_value;
	TRACE("Enter RtlIpv4AddressToStringW\n");
	return_value = pRtlIpv4AddressToStringW(pin, buffer);
	TRACE("Leave RtlIpv4AddressToStringW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4AddressToStringW(void);  /* ../dlls/ntdll/rtl.c:1176 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4AddressToStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4AddressToStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4StringToAddressA(char*  str, BOOLEAN  strict, char**  terminator, IN_ADDR*  address) /* ../dlls/ntdll/rtl.c:1062 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4StringToAddressA\n");
	return_value = pRtlIpv4StringToAddressA(str, strict, terminator, address);
	TRACE("Leave RtlIpv4StringToAddressA\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4StringToAddressA(void);  /* ../dlls/ntdll/rtl.c:1062 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4StringToAddressA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4StringToAddressA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4StringToAddressExA(char*  str, BOOLEAN  strict, IN_ADDR*  address, USHORT*  port) /* ../dlls/ntdll/rtl.c:1045 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4StringToAddressExA\n");
	return_value = pRtlIpv4StringToAddressExA(str, strict, address, port);
	TRACE("Leave RtlIpv4StringToAddressExA\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4StringToAddressExA(void);  /* ../dlls/ntdll/rtl.c:1045 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4StringToAddressExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4StringToAddressExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4StringToAddressExW(WCHAR*  str, BOOLEAN  strict, IN_ADDR*  address, USHORT*  port) /* ../dlls/ntdll/rtl.c:1026 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4StringToAddressExW\n");
	return_value = pRtlIpv4StringToAddressExW(str, strict, address, port);
	TRACE("Leave RtlIpv4StringToAddressExW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4StringToAddressExW(void);  /* ../dlls/ntdll/rtl.c:1026 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4StringToAddressExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4StringToAddressExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv4StringToAddressW(WCHAR*  str, BOOLEAN  strict, WCHAR**  terminator, IN_ADDR*  address) /* ../dlls/ntdll/rtl.c:1036 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv4StringToAddressW\n");
	return_value = pRtlIpv4StringToAddressW(str, strict, terminator, address);
	TRACE("Leave RtlIpv4StringToAddressW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv4StringToAddressW(void);  /* ../dlls/ntdll/rtl.c:1036 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv4StringToAddressW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv4StringToAddressW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlIpv6StringToAddressExW(WCHAR*  str, IN6_ADDR*  address, ULONG*  scope, USHORT*  port) /* ../dlls/ntdll/rtl.c:1080 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlIpv6StringToAddressExW\n");
	return_value = pRtlIpv6StringToAddressExW(str, address, scope, port);
	TRACE("Leave RtlIpv6StringToAddressExW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIpv6StringToAddressExW(void);  /* ../dlls/ntdll/rtl.c:1080 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIpv6StringToAddressExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIpv6StringToAddressExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsActivationContextActive(HANDLE  handle) /* ../dlls/ntdll/actctx.c:5215 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsActivationContextActive\n");
	return_value = pRtlIsActivationContextActive(handle);
	TRACE("Leave RtlIsActivationContextActive\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsActivationContextActive(void);  /* ../dlls/ntdll/actctx.c:5215 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsActivationContextActive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsActivationContextActive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlIsCriticalSectionLocked(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:641 */
{
	BOOL return_value;
	TRACE("Enter RtlIsCriticalSectionLocked\n");
	return_value = pRtlIsCriticalSectionLocked(crit);
	TRACE("Leave RtlIsCriticalSectionLocked\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsCriticalSectionLocked(void);  /* ../dlls/ntdll/critsection.c:641 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsCriticalSectionLocked,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsCriticalSectionLocked") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlIsCriticalSectionLockedByThread(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:659 */
{
	BOOL return_value;
	TRACE("Enter RtlIsCriticalSectionLockedByThread\n");
	return_value = pRtlIsCriticalSectionLockedByThread(crit);
	TRACE("Leave RtlIsCriticalSectionLockedByThread\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsCriticalSectionLockedByThread(void);  /* ../dlls/ntdll/critsection.c:659 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsCriticalSectionLockedByThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsCriticalSectionLockedByThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlIsDosDeviceName_U(PCWSTR  dos_name) /* ../dlls/ntdll/path.c:269 */
{
	ULONG return_value;
	TRACE("Enter RtlIsDosDeviceName_U\n");
	return_value = pRtlIsDosDeviceName_U(dos_name);
	TRACE("Leave RtlIsDosDeviceName_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsDosDeviceName_U(void);  /* ../dlls/ntdll/path.c:269 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsDosDeviceName_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsDosDeviceName_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsNameLegalDOS8Dot3(UNICODE_STRING*  unicode, OEM_STRING*  oem, BOOLEAN*  spaces) /* ../dlls/ntdll/path.c:890 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsNameLegalDOS8Dot3\n");
	return_value = pRtlIsNameLegalDOS8Dot3(unicode, oem, spaces);
	TRACE("Leave RtlIsNameLegalDOS8Dot3\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsNameLegalDOS8Dot3(void);  /* ../dlls/ntdll/path.c:890 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsNameLegalDOS8Dot3,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsNameLegalDOS8Dot3") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsProcessorFeaturePresent(UINT  feature) /* ../dlls/ntdll/nt.c:2353 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsProcessorFeaturePresent\n");
	return_value = pRtlIsProcessorFeaturePresent(feature);
	TRACE("Leave RtlIsProcessorFeaturePresent\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsProcessorFeaturePresent(void);  /* ../dlls/ntdll/nt.c:2353 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsProcessorFeaturePresent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsProcessorFeaturePresent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsTextUnicode(LPCVOID  buf, INT  len, INT*  pf) /* ../dlls/ntdll/rtlstr.c:1635 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsTextUnicode\n");
	return_value = pRtlIsTextUnicode(buf, len, pf);
	TRACE("Leave RtlIsTextUnicode\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsTextUnicode(void);  /* ../dlls/ntdll/rtlstr.c:1635 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsTextUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsTextUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsValidHandle(RTL_HANDLE_TABLE*  HandleTable, RTL_HANDLE*  Handle) /* ../dlls/ntdll/handletable.c:262 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsValidHandle\n");
	return_value = pRtlIsValidHandle(HandleTable, Handle);
	TRACE("Leave RtlIsValidHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsValidHandle(void);  /* ../dlls/ntdll/handletable.c:262 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsValidHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsValidHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlIsValidIndexHandle(RTL_HANDLE_TABLE*  HandleTable, ULONG  Index, RTL_HANDLE**  ValidHandle) /* ../dlls/ntdll/handletable.c:291 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlIsValidIndexHandle\n");
	return_value = pRtlIsValidIndexHandle(HandleTable, Index, ValidHandle);
	TRACE("Leave RtlIsValidIndexHandle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlIsValidIndexHandle(void);  /* ../dlls/ntdll/handletable.c:291 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlIsValidIndexHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlIsValidIndexHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlLargeIntegerToChar(ULONGLONG*  value_ptr, ULONG  base, ULONG  length, PCHAR  str) /* ../dlls/ntdll/large_int.c:413 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlLargeIntegerToChar\n");
	return_value = pRtlLargeIntegerToChar(value_ptr, base, length, str);
	TRACE("Leave RtlLargeIntegerToChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLargeIntegerToChar(void);  /* ../dlls/ntdll/large_int.c:413 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLargeIntegerToChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLargeIntegerToChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlLeaveCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:683 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlLeaveCriticalSection\n");
	return_value = pRtlLeaveCriticalSection(crit);
	TRACE("Leave RtlLeaveCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLeaveCriticalSection(void);  /* ../dlls/ntdll/critsection.c:683 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLeaveCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLeaveCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlLengthRequiredSid(DWORD  nrofsubauths) /* ../dlls/ntdll/sec.c:261 */
{
	DWORD return_value;
	TRACE("Enter RtlLengthRequiredSid\n");
	return_value = pRtlLengthRequiredSid(nrofsubauths);
	TRACE("Leave RtlLengthRequiredSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLengthRequiredSid(void);  /* ../dlls/ntdll/sec.c:261 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLengthRequiredSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLengthRequiredSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlLengthSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor) /* ../dlls/ntdll/sec.c:571 */
{
	ULONG return_value;
	TRACE("Enter RtlLengthSecurityDescriptor\n");
	return_value = pRtlLengthSecurityDescriptor(pSecurityDescriptor);
	TRACE("Leave RtlLengthSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLengthSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:571 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLengthSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLengthSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlLengthSid(PSID  pSid) /* ../dlls/ntdll/sec.c:277 */
{
	DWORD return_value;
	TRACE("Enter RtlLengthSid\n");
	return_value = pRtlLengthSid(pSid);
	TRACE("Leave RtlLengthSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLengthSid(void);  /* ../dlls/ntdll/sec.c:277 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLengthSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLengthSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlLocalTimeToSystemTime(LARGE_INTEGER*  LocalTime, PLARGE_INTEGER  SystemTime) /* ../dlls/ntdll/time.c:308 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlLocalTimeToSystemTime\n");
	return_value = pRtlLocalTimeToSystemTime(LocalTime, SystemTime);
	TRACE("Leave RtlLocalTimeToSystemTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLocalTimeToSystemTime(void);  /* ../dlls/ntdll/time.c:308 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLocalTimeToSystemTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLocalTimeToSystemTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlLockHeap(HANDLE  heap) /* ../dlls/ntdll/heap.c:1977 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlLockHeap\n");
	return_value = pRtlLockHeap(heap);
	TRACE("Leave RtlLockHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLockHeap(void);  /* ../dlls/ntdll/heap.c:1977 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLockHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLockHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlLookupAtomInAtomTable(RTL_ATOM_TABLE  table, WCHAR*  name, RTL_ATOM*  atom) /* ../dlls/ntdll/atom.c:238 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlLookupAtomInAtomTable\n");
	return_value = pRtlLookupAtomInAtomTable(table, name, atom);
	TRACE("Leave RtlLookupAtomInAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLookupAtomInAtomTable(void);  /* ../dlls/ntdll/atom.c:238 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLookupAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLookupAtomInAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PRUNTIME_FUNCTION wine32b_ntdll_RtlLookupFunctionEntry(ULONG_PTR  pc, ULONG_PTR*  base, UNWIND_HISTORY_TABLE*  table) /* ../dlls/ntdll/exception.c:652 */
{
	PRUNTIME_FUNCTION return_value;
	TRACE("Enter RtlLookupFunctionEntry\n");
	return_value = pRtlLookupFunctionEntry(pc, base, table);
	TRACE("Leave RtlLookupFunctionEntry\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlLookupFunctionEntry(void);  /* ../dlls/ntdll/exception.c:652 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlLookupFunctionEntry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlLookupFunctionEntry") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlMakeSelfRelativeSD(PSECURITY_DESCRIPTOR  pAbsoluteSecurityDescriptor, PSECURITY_DESCRIPTOR  pSelfRelativeSecurityDescriptor, LPDWORD  lpdwBufferLength) /* ../dlls/ntdll/sec.c:844 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlMakeSelfRelativeSD\n");
	return_value = pRtlMakeSelfRelativeSD(pAbsoluteSecurityDescriptor, pSelfRelativeSecurityDescriptor, lpdwBufferLength);
	TRACE("Leave RtlMakeSelfRelativeSD\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlMakeSelfRelativeSD(void);  /* ../dlls/ntdll/sec.c:844 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlMakeSelfRelativeSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlMakeSelfRelativeSD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlMapGenericMask(PACCESS_MASK  AccessMask, GENERIC_MAPPING*  GenericMapping) /* ../dlls/ntdll/rtl.c:800 */
{
	TRACE("Enter RtlMapGenericMask\n");
	pRtlMapGenericMask(AccessMask, GenericMapping);
	TRACE("Leave RtlMapGenericMask\n");
}

extern WINAPI void wine32a_ntdll_RtlMapGenericMask(void);  /* ../dlls/ntdll/rtl.c:800 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlMapGenericMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlMapGenericMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlMoveMemory(void*  Destination, void*  Source, SIZE_T  Length) /* ../dlls/ntdll/rtl.c:446 */
{
	TRACE("Enter RtlMoveMemory\n");
	pRtlMoveMemory(Destination, Source, Length);
	TRACE("Leave RtlMoveMemory\n");
}

extern WINAPI void wine32a_ntdll_RtlMoveMemory(void);  /* ../dlls/ntdll/rtl.c:446 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlMoveMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlMoveMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlMultiByteToUnicodeN(LPWSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:844 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlMultiByteToUnicodeN\n");
	return_value = pRtlMultiByteToUnicodeN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlMultiByteToUnicodeN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlMultiByteToUnicodeN(void);  /* ../dlls/ntdll/rtlstr.c:844 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlMultiByteToUnicodeN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlMultiByteToUnicodeN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlMultiByteToUnicodeSize(DWORD*  size, LPCSTR  str, UINT  len) /* ../dlls/ntdll/rtlstr.c:1333 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlMultiByteToUnicodeSize\n");
	return_value = pRtlMultiByteToUnicodeSize(size, str, len);
	TRACE("Leave RtlMultiByteToUnicodeSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlMultiByteToUnicodeSize(void);  /* ../dlls/ntdll/rtlstr.c:1333 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlMultiByteToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlMultiByteToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlNewSecurityObject(PSECURITY_DESCRIPTOR  ParentDescriptor, PSECURITY_DESCRIPTOR  CreatorDescriptor, PSECURITY_DESCRIPTOR*  NewDescriptor, BOOLEAN  IsDirectoryObject, HANDLE  Token, PGENERIC_MAPPING  GenericMapping) /* ../dlls/ntdll/rtl.c:380 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlNewSecurityObject\n");
	return_value = pRtlNewSecurityObject(ParentDescriptor, CreatorDescriptor, NewDescriptor, IsDirectoryObject, Token, GenericMapping);
	TRACE("Leave RtlNewSecurityObject\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNewSecurityObject(void);  /* ../dlls/ntdll/rtl.c:380 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNewSecurityObject,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNewSecurityObject") "\n"
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

WINAPI PRTL_USER_PROCESS_PARAMETERS wine32b_ntdll_RtlNormalizeProcessParams(RTL_USER_PROCESS_PARAMETERS*  params) /* ../dlls/ntdll/env.c:367 */
{
	PRTL_USER_PROCESS_PARAMETERS return_value;
	TRACE("Enter RtlNormalizeProcessParams\n");
	return_value = pRtlNormalizeProcessParams(params);
	TRACE("Leave RtlNormalizeProcessParams\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNormalizeProcessParams(void);  /* ../dlls/ntdll/env.c:367 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNormalizeProcessParams,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNormalizeProcessParams") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlNtStatusToDosError(NTSTATUS  status) /* ../dlls/ntdll/error.c:100 */
{
	ULONG return_value;
	TRACE("Enter RtlNtStatusToDosError\n");
	return_value = pRtlNtStatusToDosError(status);
	TRACE("Leave RtlNtStatusToDosError\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNtStatusToDosError(void);  /* ../dlls/ntdll/error.c:100 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNtStatusToDosError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNtStatusToDosError") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlNtStatusToDosErrorNoTeb(NTSTATUS  status) /* ../dlls/ntdll/error.c:57 */
{
	ULONG return_value;
	TRACE("Enter RtlNtStatusToDosErrorNoTeb\n");
	return_value = pRtlNtStatusToDosErrorNoTeb(status);
	TRACE("Leave RtlNtStatusToDosErrorNoTeb\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNtStatusToDosErrorNoTeb(void);  /* ../dlls/ntdll/error.c:57 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNtStatusToDosErrorNoTeb,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNtStatusToDosErrorNoTeb") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlNumberGenericTableElements(PVOID  pTable) /* ../dlls/ntdll/rtl.c:426 */
{
	ULONG return_value;
	TRACE("Enter RtlNumberGenericTableElements\n");
	return_value = pRtlNumberGenericTableElements(pTable);
	TRACE("Leave RtlNumberGenericTableElements\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNumberGenericTableElements(void);  /* ../dlls/ntdll/rtl.c:426 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNumberGenericTableElements,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNumberGenericTableElements") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlNumberOfClearBits(PCRTL_BITMAP  lpBits) /* ../dlls/ntdll/rtlbitmap.c:579 */
{
	ULONG return_value;
	TRACE("Enter RtlNumberOfClearBits\n");
	return_value = pRtlNumberOfClearBits(lpBits);
	TRACE("Leave RtlNumberOfClearBits\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNumberOfClearBits(void);  /* ../dlls/ntdll/rtlbitmap.c:579 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNumberOfClearBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNumberOfClearBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlNumberOfSetBits(PCRTL_BITMAP  lpBits) /* ../dlls/ntdll/rtlbitmap.c:536 */
{
	ULONG return_value;
	TRACE("Enter RtlNumberOfSetBits\n");
	return_value = pRtlNumberOfSetBits(lpBits);
	TRACE("Leave RtlNumberOfSetBits\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlNumberOfSetBits(void);  /* ../dlls/ntdll/rtlbitmap.c:536 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlNumberOfSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlNumberOfSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI UINT wine32b_ntdll_RtlOemStringToUnicodeSize(STRING*  str) /* ../dlls/ntdll/rtlstr.c:1291 */
{
	UINT return_value;
	TRACE("Enter RtlOemStringToUnicodeSize\n");
	return_value = pRtlOemStringToUnicodeSize(str);
	TRACE("Leave RtlOemStringToUnicodeSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlOemStringToUnicodeSize(void);  /* ../dlls/ntdll/rtlstr.c:1291 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlOemStringToUnicodeSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlOemStringToUnicodeSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlOemStringToUnicodeString(UNICODE_STRING*  uni, STRING*  oem, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:722 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlOemStringToUnicodeString\n");
	return_value = pRtlOemStringToUnicodeString(uni, oem, doalloc);
	TRACE("Leave RtlOemStringToUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlOemStringToUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:722 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlOemStringToUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlOemStringToUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlOemToUnicodeN(LPWSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:863 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlOemToUnicodeN\n");
	return_value = pRtlOemToUnicodeN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlOemToUnicodeN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlOemToUnicodeN(void);  /* ../dlls/ntdll/rtlstr.c:863 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlOemToUnicodeN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlOemToUnicodeN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlOpenCurrentUser(ACCESS_MASK  DesiredAccess, PHANDLE  KeyHandle) /* ../dlls/ntdll/reg.c:960 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlOpenCurrentUser\n");
	return_value = pRtlOpenCurrentUser(DesiredAccess, KeyHandle);
	TRACE("Leave RtlOpenCurrentUser\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlOpenCurrentUser(void);  /* ../dlls/ntdll/reg.c:960 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlOpenCurrentUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlOpenCurrentUser") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlPcToFileHeader(PVOID  pc, PVOID*  address) /* ../dlls/ntdll/loader.c:3955 */
{
	PVOID return_value;
	TRACE("Enter RtlPcToFileHeader\n");
	return_value = pRtlPcToFileHeader(pc, address);
	TRACE("Leave RtlPcToFileHeader\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlPcToFileHeader(void);  /* ../dlls/ntdll/loader.c:3955 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPcToFileHeader,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPcToFileHeader") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlPinAtomInAtomTable(RTL_ATOM_TABLE  table, RTL_ATOM  atom) /* ../dlls/ntdll/atom.c:288 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlPinAtomInAtomTable\n");
	return_value = pRtlPinAtomInAtomTable(table, atom);
	TRACE("Leave RtlPinAtomInAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlPinAtomInAtomTable(void);  /* ../dlls/ntdll/atom.c:288 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPinAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPinAtomInAtomTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlPopFrame(TEB_ACTIVE_FRAME*  frame) /* ../dlls/ntdll/thread.c:714 */
{
	TRACE("Enter RtlPopFrame\n");
	pRtlPopFrame(frame);
	TRACE("Leave RtlPopFrame\n");
}

extern WINAPI void wine32a_ntdll_RtlPopFrame(void);  /* ../dlls/ntdll/thread.c:714 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPopFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPopFrame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlPrefixString(STRING*  s1, STRING*  s2, BOOLEAN  ignore_case) /* ../dlls/ntdll/rtlstr.c:535 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlPrefixString\n");
	return_value = pRtlPrefixString(s1, s2, ignore_case);
	TRACE("Leave RtlPrefixString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlPrefixString(void);  /* ../dlls/ntdll/rtlstr.c:535 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPrefixString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPrefixString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlPrefixUnicodeString(UNICODE_STRING*  s1, UNICODE_STRING*  s2, BOOLEAN  ignore_case) /* ../dlls/ntdll/rtlstr.c:559 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlPrefixUnicodeString\n");
	return_value = pRtlPrefixUnicodeString(s1, s2, ignore_case);
	TRACE("Leave RtlPrefixUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlPrefixUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:559 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPrefixUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPrefixUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlPushFrame(TEB_ACTIVE_FRAME*  frame) /* ../dlls/ntdll/thread.c:704 */
{
	TRACE("Enter RtlPushFrame\n");
	pRtlPushFrame(frame);
	TRACE("Leave RtlPushFrame\n");
}

extern WINAPI void wine32a_ntdll_RtlPushFrame(void);  /* ../dlls/ntdll/thread.c:704 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlPushFrame,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlPushFrame") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryActivationContextApplicationSettings(DWORD  flags, HANDLE  handle, WCHAR*  ns, WCHAR*  settings, WCHAR*  buffer, SIZE_T  size, SIZE_T*  written) /* ../dlls/ntdll/actctx.c:5568 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryActivationContextApplicationSettings\n");
	return_value = pRtlQueryActivationContextApplicationSettings(flags, handle, ns, settings, buffer, size, written);
	TRACE("Leave RtlQueryActivationContextApplicationSettings\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryActivationContextApplicationSettings(void);  /* ../dlls/ntdll/actctx.c:5568 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryActivationContextApplicationSettings,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryActivationContextApplicationSettings") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlQueryAtomInAtomTable(RTL_ATOM_TABLE  table, RTL_ATOM  atom, ULONG*  ref, ULONG*  pin, WCHAR*  name, ULONG*  len) /* ../dlls/ntdll/atom.c:123 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryAtomInAtomTable\n");
	return_value = pRtlQueryAtomInAtomTable(table, atom, ref, pin, name, len);
	TRACE("Leave RtlQueryAtomInAtomTable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryAtomInAtomTable(void);  /* ../dlls/ntdll/atom.c:123 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryAtomInAtomTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryAtomInAtomTable") "\n"
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

WINAPI WORD wine32b_ntdll_RtlQueryDepthSList(PSLIST_HEADER  list) /* ../dlls/ntdll/rtl.c:1257 */
{
	WORD return_value;
	TRACE("Enter RtlQueryDepthSList\n");
	return_value = pRtlQueryDepthSList(list);
	TRACE("Leave RtlQueryDepthSList\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryDepthSList(void);  /* ../dlls/ntdll/rtl.c:1257 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryDepthSList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryDepthSList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryDynamicTimeZoneInformation(RTL_DYNAMIC_TIME_ZONE_INFORMATION*  tzinfo) /* ../dlls/ntdll/time.c:1035 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryDynamicTimeZoneInformation\n");
	return_value = pRtlQueryDynamicTimeZoneInformation(tzinfo);
	TRACE("Leave RtlQueryDynamicTimeZoneInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryDynamicTimeZoneInformation(void);  /* ../dlls/ntdll/time.c:1035 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryDynamicTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryDynamicTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryEnvironmentVariable_U(PWSTR  env, PUNICODE_STRING  name, PUNICODE_STRING  value) /* ../dlls/ntdll/env.c:128 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryEnvironmentVariable_U\n");
	return_value = pRtlQueryEnvironmentVariable_U(env, name, value);
	TRACE("Leave RtlQueryEnvironmentVariable_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryEnvironmentVariable_U(void);  /* ../dlls/ntdll/env.c:128 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryEnvironmentVariable_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryEnvironmentVariable_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryHeapInformation(HANDLE  heap, HEAP_INFORMATION_CLASS  info_class, PVOID  info, SIZE_T  size_in, PSIZE_T  size_out) /* ../dlls/ntdll/heap.c:2245 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryHeapInformation\n");
	return_value = pRtlQueryHeapInformation(heap, info_class, info, size_in, size_out);
	TRACE("Leave RtlQueryHeapInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryHeapInformation(void);  /* ../dlls/ntdll/heap.c:2245 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryHeapInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryHeapInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryInformationAcl(PACL  pAcl, LPVOID  pAclInformation, DWORD  nAclInformationLength, ACL_INFORMATION_CLASS  dwAclInformationClass) /* ../dlls/ntdll/sec.c:1857 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryInformationAcl\n");
	return_value = pRtlQueryInformationAcl(pAcl, pAclInformation, nAclInformationLength, dwAclInformationClass);
	TRACE("Leave RtlQueryInformationAcl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryInformationAcl(void);  /* ../dlls/ntdll/sec.c:1857 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryInformationAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryInformationAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryInformationActivationContext(ULONG  flags, HANDLE  handle, PVOID  subinst, ULONG  class, PVOID  buffer, SIZE_T  bufsize, SIZE_T*  retlen) /* ../dlls/ntdll/actctx.c:5231 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryInformationActivationContext\n");
	return_value = pRtlQueryInformationActivationContext(flags, handle, subinst, class, buffer, bufsize, retlen);
	TRACE("Leave RtlQueryInformationActivationContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryInformationActivationContext(void);  /* ../dlls/ntdll/actctx.c:5231 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryInformationActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryInformationActivationContext") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlQueryPackageIdentity(HANDLE  token, WCHAR*  fullname, SIZE_T*  fullname_size, WCHAR*  appid, SIZE_T*  appid_size, BOOLEAN*  packaged) /* ../dlls/ntdll/rtl.c:1823 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryPackageIdentity\n");
	return_value = pRtlQueryPackageIdentity(token, fullname, fullname_size, appid, appid_size, packaged);
	TRACE("Leave RtlQueryPackageIdentity\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryPackageIdentity(void);  /* ../dlls/ntdll/rtl.c:1823 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryPackageIdentity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryPackageIdentity") "\n"
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

WINAPI BOOL wine32b_ntdll_RtlQueryPerformanceCounter(LARGE_INTEGER*  counter) /* ../dlls/ntdll/time.c:558 */
{
	BOOL return_value;
	TRACE("Enter RtlQueryPerformanceCounter\n");
	return_value = pRtlQueryPerformanceCounter(counter);
	TRACE("Leave RtlQueryPerformanceCounter\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryPerformanceCounter(void);  /* ../dlls/ntdll/time.c:558 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryPerformanceCounter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryPerformanceCounter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlQueryPerformanceFrequency(LARGE_INTEGER*  frequency) /* ../dlls/ntdll/time.c:567 */
{
	BOOL return_value;
	TRACE("Enter RtlQueryPerformanceFrequency\n");
	return_value = pRtlQueryPerformanceFrequency(frequency);
	TRACE("Leave RtlQueryPerformanceFrequency\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryPerformanceFrequency(void);  /* ../dlls/ntdll/time.c:567 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryPerformanceFrequency,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryPerformanceFrequency") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryProcessDebugInformation(ULONG  iProcessId, ULONG  iDebugInfoMask, PDEBUG_BUFFER  iBuf) /* ../dlls/ntdll/debugbuffer.c:118 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryProcessDebugInformation\n");
	return_value = pRtlQueryProcessDebugInformation(iProcessId, iDebugInfoMask, iBuf);
	TRACE("Leave RtlQueryProcessDebugInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryProcessDebugInformation(void);  /* ../dlls/ntdll/debugbuffer.c:118 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryProcessDebugInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryProcessDebugInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryRegistryValues(ULONG  RelativeTo, PCWSTR  Path, PRTL_QUERY_REGISTRY_TABLE  QueryTable, PVOID  Context, PVOID  Environment) /* ../dlls/ntdll/reg.c:1233 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryRegistryValues\n");
	return_value = pRtlQueryRegistryValues(RelativeTo, Path, QueryTable, Context, Environment);
	TRACE("Leave RtlQueryRegistryValues\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryRegistryValues(void);  /* ../dlls/ntdll/reg.c:1233 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryRegistryValues,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryRegistryValues") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryTimeZoneInformation(RTL_TIME_ZONE_INFORMATION*  ret) /* ../dlls/ntdll/time.c:1014 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryTimeZoneInformation\n");
	return_value = pRtlQueryTimeZoneInformation(ret);
	TRACE("Leave RtlQueryTimeZoneInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryTimeZoneInformation(void);  /* ../dlls/ntdll/time.c:1014 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueryUnbiasedInterruptTime(ULONGLONG*  time) /* ../dlls/ntdll/time.c:1120 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueryUnbiasedInterruptTime\n");
	return_value = pRtlQueryUnbiasedInterruptTime(time);
	TRACE("Leave RtlQueryUnbiasedInterruptTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueryUnbiasedInterruptTime(void);  /* ../dlls/ntdll/time.c:1120 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueryUnbiasedInterruptTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueryUnbiasedInterruptTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlQueueWorkItem(PRTL_WORK_ITEM_ROUTINE  function, PVOID  context, ULONG  flags) /* ../dlls/ntdll/threadpool.c:377 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlQueueWorkItem\n");
	return_value = pRtlQueueWorkItem(function, context, flags);
	TRACE("Leave RtlQueueWorkItem\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlQueueWorkItem(void);  /* ../dlls/ntdll/threadpool.c:377 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlQueueWorkItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlQueueWorkItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlRaiseStatus(NTSTATUS  status) /* ../dlls/ntdll/exception.c:271 */
{
	TRACE("Enter RtlRaiseStatus\n");
	pRtlRaiseStatus(status);
	TRACE("Leave RtlRaiseStatus\n");
}

extern WINAPI void wine32a_ntdll_RtlRaiseStatus(void);  /* ../dlls/ntdll/exception.c:271 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRaiseStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRaiseStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlRandom(PULONG  seed) /* ../dlls/ntdll/rtl.c:713 */
{
	ULONG return_value;
	TRACE("Enter RtlRandom\n");
	return_value = pRtlRandom(seed);
	TRACE("Leave RtlRandom\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRandom(void);  /* ../dlls/ntdll/rtl.c:713 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRandom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRandom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlRandomEx(ULONG*  seed) /* ../dlls/ntdll/rtl.c:748 */
{
	ULONG return_value;
	TRACE("Enter RtlRandomEx\n");
	return_value = pRtlRandomEx(seed);
	TRACE("Leave RtlRandomEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRandomEx(void);  /* ../dlls/ntdll/rtl.c:748 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRandomEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRandomEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlReAllocateHeap(HANDLE  heap, ULONG  flags, PVOID  ptr, SIZE_T  size) /* ../dlls/ntdll/heap.c:1809 */
{
	PVOID return_value;
	TRACE("Enter RtlReAllocateHeap\n");
	return_value = pRtlReAllocateHeap(heap, flags, ptr, size);
	TRACE("Leave RtlReAllocateHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlReAllocateHeap(void);  /* ../dlls/ntdll/heap.c:1809 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReAllocateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReAllocateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlRegisterWait(PHANDLE  NewWaitObject, HANDLE  Object, RTL_WAITORTIMERCALLBACKFUNC  Callback, PVOID  Context, ULONG  Milliseconds, ULONG  Flags) /* ../dlls/ntdll/threadpool.c:587 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlRegisterWait\n");
	return_value = pRtlRegisterWait(NewWaitObject, Object, Callback, Context, Milliseconds, Flags);
	TRACE("Leave RtlRegisterWait\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRegisterWait(void);  /* ../dlls/ntdll/threadpool.c:587 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRegisterWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRegisterWait") "\n"
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

WINAPI void wine32b_ntdll_RtlReleaseActivationContext(HANDLE  handle) /* ../dlls/ntdll/actctx.c:5103 */
{
	TRACE("Enter RtlReleaseActivationContext\n");
	pRtlReleaseActivationContext(handle);
	TRACE("Leave RtlReleaseActivationContext\n");
}

extern WINAPI void wine32a_ntdll_RtlReleaseActivationContext(void);  /* ../dlls/ntdll/actctx.c:5103 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleaseActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleaseActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlReleasePebLock(void) /* ../dlls/ntdll/rtl.c:371 */
{
	TRACE("Enter RtlReleasePebLock\n");
	pRtlReleasePebLock();
	TRACE("Leave RtlReleasePebLock\n");
}

extern WINAPI void wine32a_ntdll_RtlReleasePebLock(void);  /* ../dlls/ntdll/rtl.c:371 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleasePebLock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleasePebLock") "\n"
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

WINAPI void wine32b_ntdll_RtlReleaseRelativeName(RTL_RELATIVE_NAME*  relative) /* ../dlls/ntdll/path.c:465 */
{
	TRACE("Enter RtlReleaseRelativeName\n");
	pRtlReleaseRelativeName(relative);
	TRACE("Leave RtlReleaseRelativeName\n");
}

extern WINAPI void wine32a_ntdll_RtlReleaseRelativeName(void);  /* ../dlls/ntdll/path.c:465 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleaseRelativeName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleaseRelativeName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlReleaseResource(LPRTL_RWLOCK  rwl) /* ../dlls/ntdll/rtl.c:243 */
{
	TRACE("Enter RtlReleaseResource\n");
	pRtlReleaseResource(rwl);
	TRACE("Leave RtlReleaseResource\n");
}

extern WINAPI void wine32a_ntdll_RtlReleaseResource(void);  /* ../dlls/ntdll/rtl.c:243 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleaseResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleaseResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlReleaseSRWLockExclusive(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2121 */
{
	TRACE("Enter RtlReleaseSRWLockExclusive\n");
	pRtlReleaseSRWLockExclusive(lock);
	TRACE("Leave RtlReleaseSRWLockExclusive\n");
}

extern WINAPI void wine32a_ntdll_RtlReleaseSRWLockExclusive(void);  /* ../dlls/ntdll/sync.c:2121 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleaseSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleaseSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlReleaseSRWLockShared(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2133 */
{
	TRACE("Enter RtlReleaseSRWLockShared\n");
	pRtlReleaseSRWLockShared(lock);
	TRACE("Leave RtlReleaseSRWLockShared\n");
}

extern WINAPI void wine32a_ntdll_RtlReleaseSRWLockShared(void);  /* ../dlls/ntdll/sync.c:2133 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlReleaseSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlReleaseSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlRemoveVectoredContinueHandler(PVOID  handler) /* ../dlls/ntdll/exception.c:289 */
{
	ULONG return_value;
	TRACE("Enter RtlRemoveVectoredContinueHandler\n");
	return_value = pRtlRemoveVectoredContinueHandler(handler);
	TRACE("Leave RtlRemoveVectoredContinueHandler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRemoveVectoredContinueHandler(void);  /* ../dlls/ntdll/exception.c:289 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRemoveVectoredContinueHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRemoveVectoredContinueHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlRemoveVectoredExceptionHandler(PVOID  handler) /* ../dlls/ntdll/exception.c:307 */
{
	ULONG return_value;
	TRACE("Enter RtlRemoveVectoredExceptionHandler\n");
	return_value = pRtlRemoveVectoredExceptionHandler(handler);
	TRACE("Leave RtlRemoveVectoredExceptionHandler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRemoveVectoredExceptionHandler(void);  /* ../dlls/ntdll/exception.c:307 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRemoveVectoredExceptionHandler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRemoveVectoredExceptionHandler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlRestoreContext(CONTEXT*  context, EXCEPTION_RECORD*  rec) /* ../dlls/ntdll/signal_x86_64.c:3800 */
{
	TRACE("Enter RtlRestoreContext\n");
	pRtlRestoreContext(context, rec);
	TRACE("Leave RtlRestoreContext\n");
}

extern WINAPI void wine32a_ntdll_RtlRestoreContext(void);  /* ../dlls/ntdll/signal_x86_64.c:3800 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRestoreContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRestoreContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlRunOnceBeginInitialize(RTL_RUN_ONCE*  once, ULONG  flags, void**  context) /* ../dlls/ntdll/sync.c:1554 */
{
	DWORD return_value;
	TRACE("Enter RtlRunOnceBeginInitialize\n");
	return_value = pRtlRunOnceBeginInitialize(once, flags, context);
	TRACE("Leave RtlRunOnceBeginInitialize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRunOnceBeginInitialize(void);  /* ../dlls/ntdll/sync.c:1554 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRunOnceBeginInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRunOnceBeginInitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlRunOnceComplete(RTL_RUN_ONCE*  once, ULONG  flags, void*  context) /* ../dlls/ntdll/sync.c:1600 */
{
	DWORD return_value;
	TRACE("Enter RtlRunOnceComplete\n");
	return_value = pRtlRunOnceComplete(once, flags, context);
	TRACE("Leave RtlRunOnceComplete\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRunOnceComplete(void);  /* ../dlls/ntdll/sync.c:1600 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRunOnceComplete,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRunOnceComplete") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlRunOnceExecuteOnce(RTL_RUN_ONCE*  once, PRTL_RUN_ONCE_INIT_FN  func, void*  param, void**  context) /* ../dlls/ntdll/sync.c:1642 */
{
	DWORD return_value;
	TRACE("Enter RtlRunOnceExecuteOnce\n");
	return_value = pRtlRunOnceExecuteOnce(once, func, param, context);
	TRACE("Leave RtlRunOnceExecuteOnce\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlRunOnceExecuteOnce(void);  /* ../dlls/ntdll/sync.c:1642 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRunOnceExecuteOnce,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRunOnceExecuteOnce") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlRunOnceInitialize(RTL_RUN_ONCE*  once) /* ../dlls/ntdll/sync.c:1546 */
{
	TRACE("Enter RtlRunOnceInitialize\n");
	pRtlRunOnceInitialize(once);
	TRACE("Leave RtlRunOnceInitialize\n");
}

extern WINAPI void wine32a_ntdll_RtlRunOnceInitialize(void);  /* ../dlls/ntdll/sync.c:1546 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlRunOnceInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlRunOnceInitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSecondsSince1970ToTime(DWORD  Seconds, LARGE_INTEGER*  Time) /* ../dlls/ntdll/time.c:399 */
{
	TRACE("Enter RtlSecondsSince1970ToTime\n");
	pRtlSecondsSince1970ToTime(Seconds, Time);
	TRACE("Leave RtlSecondsSince1970ToTime\n");
}

extern WINAPI void wine32a_ntdll_RtlSecondsSince1970ToTime(void);  /* ../dlls/ntdll/time.c:399 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSecondsSince1970ToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSecondsSince1970ToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSecondsSince1980ToTime(DWORD  Seconds, LARGE_INTEGER*  Time) /* ../dlls/ntdll/time.c:416 */
{
	TRACE("Enter RtlSecondsSince1980ToTime\n");
	pRtlSecondsSince1980ToTime(Seconds, Time);
	TRACE("Leave RtlSecondsSince1980ToTime\n");
}

extern WINAPI void wine32a_ntdll_RtlSecondsSince1980ToTime(void);  /* ../dlls/ntdll/time.c:416 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSecondsSince1980ToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSecondsSince1980ToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSelfRelativeToAbsoluteSD(PSECURITY_DESCRIPTOR  pSelfRelativeSecurityDescriptor, PSECURITY_DESCRIPTOR  pAbsoluteSecurityDescriptor, LPDWORD  lpdwAbsoluteSecurityDescriptorSize, PACL  pDacl, LPDWORD  lpdwDaclSize, PACL  pSacl, LPDWORD  lpdwSaclSize, PSID  pOwner, LPDWORD  lpdwOwnerSize, PSID  pPrimaryGroup, LPDWORD  lpdwPrimaryGroupSize) /* ../dlls/ntdll/sec.c:936 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSelfRelativeToAbsoluteSD\n");
	return_value = pRtlSelfRelativeToAbsoluteSD(pSelfRelativeSecurityDescriptor, pAbsoluteSecurityDescriptor, lpdwAbsoluteSecurityDescriptorSize, pDacl, lpdwDaclSize, pSacl, lpdwSaclSize, pOwner, lpdwOwnerSize, pPrimaryGroup, lpdwPrimaryGroupSize);
	TRACE("Leave RtlSelfRelativeToAbsoluteSD\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSelfRelativeToAbsoluteSD(void);  /* ../dlls/ntdll/sec.c:936 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSelfRelativeToAbsoluteSD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSelfRelativeToAbsoluteSD") "\n"
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

WINAPI void wine32b_ntdll_RtlSetAllBits(PRTL_BITMAP  lpBits) /* ../dlls/ntdll/rtlbitmap.c:93 */
{
	TRACE("Enter RtlSetAllBits\n");
	pRtlSetAllBits(lpBits);
	TRACE("Leave RtlSetAllBits\n");
}

extern WINAPI void wine32a_ntdll_RtlSetAllBits(void);  /* ../dlls/ntdll/rtlbitmap.c:93 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetAllBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetAllBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSetBits(PRTL_BITMAP  lpBits, ULONG  ulStart, ULONG  ulCount) /* ../dlls/ntdll/rtlbitmap.c:129 */
{
	TRACE("Enter RtlSetBits\n");
	pRtlSetBits(lpBits, ulStart, ulCount);
	TRACE("Leave RtlSetBits\n");
}

extern WINAPI void wine32a_ntdll_RtlSetBits(void);  /* ../dlls/ntdll/rtlbitmap.c:129 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetBits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetBits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetControlSecurityDescriptor(PSECURITY_DESCRIPTOR  SecurityDescriptor, SECURITY_DESCRIPTOR_CONTROL  ControlBitsOfInterest, SECURITY_DESCRIPTOR_CONTROL  ControlBitsToSet) /* ../dlls/ntdll/sec.c:1065 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetControlSecurityDescriptor\n");
	return_value = pRtlSetControlSecurityDescriptor(SecurityDescriptor, ControlBitsOfInterest, ControlBitsToSet);
	TRACE("Leave RtlSetControlSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetControlSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:1065 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetControlSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetControlSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlSetCriticalSectionSpinCount(RTL_CRITICAL_SECTION*  crit, ULONG  spincount) /* ../dlls/ntdll/critsection.c:377 */
{
	ULONG return_value;
	TRACE("Enter RtlSetCriticalSectionSpinCount\n");
	return_value = pRtlSetCriticalSectionSpinCount(crit, spincount);
	TRACE("Leave RtlSetCriticalSectionSpinCount\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetCriticalSectionSpinCount(void);  /* ../dlls/ntdll/critsection.c:377 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetCriticalSectionSpinCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetCriticalSectionSpinCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetCurrentDirectory_U(UNICODE_STRING*  dir) /* ../dlls/ntdll/path.c:994 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetCurrentDirectory_U\n");
	return_value = pRtlSetCurrentDirectory_U(dir);
	TRACE("Leave RtlSetCurrentDirectory_U\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetCurrentDirectory_U(void);  /* ../dlls/ntdll/path.c:994 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetCurrentDirectory_U,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetCurrentDirectory_U") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSetCurrentEnvironment(PWSTR  new_env, PWSTR*  old_env) /* ../dlls/ntdll/env.c:171 */
{
	TRACE("Enter RtlSetCurrentEnvironment\n");
	pRtlSetCurrentEnvironment(new_env, old_env);
	TRACE("Leave RtlSetCurrentEnvironment\n");
}

extern WINAPI void wine32a_ntdll_RtlSetCurrentEnvironment(void);  /* ../dlls/ntdll/env.c:171 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetCurrentEnvironment,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetCurrentEnvironment") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlSetCurrentTransaction(HANDLE  new_transaction) /* ../dlls/ntdll/rtl.c:1786 */
{
	BOOL return_value;
	TRACE("Enter RtlSetCurrentTransaction\n");
	return_value = pRtlSetCurrentTransaction(new_transaction);
	TRACE("Leave RtlSetCurrentTransaction\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetCurrentTransaction(void);  /* ../dlls/ntdll/rtl.c:1786 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetCurrentTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetCurrentTransaction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetDaclSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, BOOLEAN  daclpresent, PACL  dacl, BOOLEAN  dacldefaulted) /* ../dlls/ntdll/sec.c:644 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetDaclSecurityDescriptor\n");
	return_value = pRtlSetDaclSecurityDescriptor(pSecurityDescriptor, daclpresent, dacl, dacldefaulted);
	TRACE("Leave RtlSetDaclSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetDaclSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:644 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetDaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetDaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetEnvironmentVariable(PWSTR*  penv, PUNICODE_STRING  name, PUNICODE_STRING  value) /* ../dlls/ntdll/env.c:187 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetEnvironmentVariable\n");
	return_value = pRtlSetEnvironmentVariable(penv, name, value);
	TRACE("Leave RtlSetEnvironmentVariable\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetEnvironmentVariable(void);  /* ../dlls/ntdll/env.c:187 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetEnvironmentVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetEnvironmentVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetGroupSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID  group, BOOLEAN  groupdefaulted) /* ../dlls/ntdll/sec.c:791 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetGroupSecurityDescriptor\n");
	return_value = pRtlSetGroupSecurityDescriptor(pSecurityDescriptor, group, groupdefaulted);
	TRACE("Leave RtlSetGroupSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetGroupSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:791 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetGroupSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetGroupSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetHeapInformation(HANDLE  heap, HEAP_INFORMATION_CLASS  info_class, PVOID  info, SIZE_T  size) /* ../dlls/ntdll/heap.c:2268 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetHeapInformation\n");
	return_value = pRtlSetHeapInformation(heap, info_class, info, size);
	TRACE("Leave RtlSetHeapInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetHeapInformation(void);  /* ../dlls/ntdll/heap.c:2268 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetHeapInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetHeapInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetIoCompletionCallback(HANDLE  FileHandle, PRTL_OVERLAPPED_COMPLETION_ROUTINE  Function, ULONG  Flags) /* ../dlls/ntdll/threadpool.c:451 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetIoCompletionCallback\n");
	return_value = pRtlSetIoCompletionCallback(FileHandle, Function, Flags);
	TRACE("Leave RtlSetIoCompletionCallback\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetIoCompletionCallback(void);  /* ../dlls/ntdll/threadpool.c:451 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetIoCompletionCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetIoCompletionCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSetLastWin32Error(DWORD  err) /* ../dlls/ntdll/error.c:155 */
{
	TRACE("Enter RtlSetLastWin32Error\n");
	pRtlSetLastWin32Error(err);
	TRACE("Leave RtlSetLastWin32Error\n");
}

extern WINAPI void wine32a_ntdll_RtlSetLastWin32Error(void);  /* ../dlls/ntdll/error.c:155 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetLastWin32Error,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetLastWin32Error") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSetLastWin32ErrorAndNtStatusFromNtStatus(NTSTATUS  status) /* ../dlls/ntdll/error.c:171 */
{
	TRACE("Enter RtlSetLastWin32ErrorAndNtStatusFromNtStatus\n");
	pRtlSetLastWin32ErrorAndNtStatusFromNtStatus(status);
	TRACE("Leave RtlSetLastWin32ErrorAndNtStatusFromNtStatus\n");
}

extern WINAPI void wine32a_ntdll_RtlSetLastWin32ErrorAndNtStatusFromNtStatus(void);  /* ../dlls/ntdll/error.c:171 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetLastWin32ErrorAndNtStatusFromNtStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetLastWin32ErrorAndNtStatusFromNtStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetOwnerSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, PSID  owner, BOOLEAN  ownerdefaulted) /* ../dlls/ntdll/sec.c:768 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetOwnerSecurityDescriptor\n");
	return_value = pRtlSetOwnerSecurityDescriptor(pSecurityDescriptor, owner, ownerdefaulted);
	TRACE("Leave RtlSetOwnerSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetOwnerSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:768 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetOwnerSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetOwnerSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetSaclSecurityDescriptor(PSECURITY_DESCRIPTOR  pSecurityDescriptor, BOOLEAN  saclpresent, PACL  sacl, BOOLEAN  sacldefaulted) /* ../dlls/ntdll/sec.c:710 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetSaclSecurityDescriptor\n");
	return_value = pRtlSetSaclSecurityDescriptor(pSecurityDescriptor, saclpresent, sacl, sacldefaulted);
	TRACE("Leave RtlSetSaclSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetSaclSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:710 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetSaclSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetSaclSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetThreadErrorMode(DWORD  mode, LPDWORD  oldmode) /* ../dlls/ntdll/rtl.c:1746 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetThreadErrorMode\n");
	return_value = pRtlSetThreadErrorMode(mode, oldmode);
	TRACE("Leave RtlSetThreadErrorMode\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetThreadErrorMode(void);  /* ../dlls/ntdll/rtl.c:1746 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetThreadErrorMode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetThreadErrorMode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSetTimeZoneInformation(RTL_TIME_ZONE_INFORMATION*  tzinfo) /* ../dlls/ntdll/time.c:1055 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSetTimeZoneInformation\n");
	return_value = pRtlSetTimeZoneInformation(tzinfo);
	TRACE("Leave RtlSetTimeZoneInformation\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSetTimeZoneInformation(void);  /* ../dlls/ntdll/time.c:1055 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetTimeZoneInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetTimeZoneInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlSetUnhandledExceptionFilter(PRTL_EXCEPTION_FILTER  filter) /* ../dlls/ntdll/exception.c:316 */
{
	TRACE("Enter RtlSetUnhandledExceptionFilter\n");
	pRtlSetUnhandledExceptionFilter(filter);
	TRACE("Leave RtlSetUnhandledExceptionFilter\n");
}

extern WINAPI void wine32a_ntdll_RtlSetUnhandledExceptionFilter(void);  /* ../dlls/ntdll/exception.c:316 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSetUnhandledExceptionFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSetUnhandledExceptionFilter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI SIZE_T wine32b_ntdll_RtlSizeHeap(HANDLE  heap, ULONG  flags, void*  ptr) /* ../dlls/ntdll/heap.c:2024 */
{
	SIZE_T return_value;
	TRACE("Enter RtlSizeHeap\n");
	return_value = pRtlSizeHeap(heap, flags, ptr);
	TRACE("Leave RtlSizeHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSizeHeap(void);  /* ../dlls/ntdll/heap.c:2024 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSizeHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSizeHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSleepConditionVariableCS(RTL_CONDITION_VARIABLE*  variable, RTL_CRITICAL_SECTION*  crit, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:2287 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSleepConditionVariableCS\n");
	return_value = pRtlSleepConditionVariableCS(variable, crit, timeout);
	TRACE("Leave RtlSleepConditionVariableCS\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSleepConditionVariableCS(void);  /* ../dlls/ntdll/sync.c:2287 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSleepConditionVariableCS,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSleepConditionVariableCS") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSleepConditionVariableSRW(RTL_CONDITION_VARIABLE*  variable, RTL_SRWLOCK*  lock, LARGE_INTEGER*  timeout, ULONG  flags) /* ../dlls/ntdll/sync.c:2322 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSleepConditionVariableSRW\n");
	return_value = pRtlSleepConditionVariableSRW(variable, lock, timeout, flags);
	TRACE("Leave RtlSleepConditionVariableSRW\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSleepConditionVariableSRW(void);  /* ../dlls/ntdll/sync.c:2322 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSleepConditionVariableSRW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSleepConditionVariableSRW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlStringFromGUID(GUID*  guid, UNICODE_STRING*  str) /* ../dlls/ntdll/rtlstr.c:2159 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlStringFromGUID\n");
	return_value = pRtlStringFromGUID(guid, str);
	TRACE("Leave RtlStringFromGUID\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlStringFromGUID(void);  /* ../dlls/ntdll/rtlstr.c:2159 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlStringFromGUID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlStringFromGUID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPBYTE wine32b_ntdll_RtlSubAuthorityCountSid(PSID  pSid) /* ../dlls/ntdll/sec.c:364 */
{
	LPBYTE return_value;
	TRACE("Enter RtlSubAuthorityCountSid\n");
	return_value = pRtlSubAuthorityCountSid(pSid);
	TRACE("Leave RtlSubAuthorityCountSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSubAuthorityCountSid(void);  /* ../dlls/ntdll/sec.c:364 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSubAuthorityCountSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSubAuthorityCountSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPDWORD wine32b_ntdll_RtlSubAuthoritySid(PSID  pSid, DWORD  nSubAuthority) /* ../dlls/ntdll/sec.c:332 */
{
	LPDWORD return_value;
	TRACE("Enter RtlSubAuthoritySid\n");
	return_value = pRtlSubAuthoritySid(pSid, nSubAuthority);
	TRACE("Leave RtlSubAuthoritySid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSubAuthoritySid(void);  /* ../dlls/ntdll/sec.c:332 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSubAuthoritySid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSubAuthoritySid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlSystemTimeToLocalTime(LARGE_INTEGER*  SystemTime, PLARGE_INTEGER  LocalTime) /* ../dlls/ntdll/time.c:333 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlSystemTimeToLocalTime\n");
	return_value = pRtlSystemTimeToLocalTime(SystemTime, LocalTime);
	TRACE("Leave RtlSystemTimeToLocalTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlSystemTimeToLocalTime(void);  /* ../dlls/ntdll/time.c:333 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlSystemTimeToLocalTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlSystemTimeToLocalTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlTimeFieldsToTime(PTIME_FIELDS  tfTimeFields, PLARGE_INTEGER  Time) /* ../dlls/ntdll/time.c:207 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlTimeFieldsToTime\n");
	return_value = pRtlTimeFieldsToTime(tfTimeFields, Time);
	TRACE("Leave RtlTimeFieldsToTime\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTimeFieldsToTime(void);  /* ../dlls/ntdll/time.c:207 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTimeFieldsToTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTimeFieldsToTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlTimeToElapsedTimeFields(LARGE_INTEGER*  Time, PTIME_FIELDS  TimeFields) /* ../dlls/ntdll/time.c:433 */
{
	TRACE("Enter RtlTimeToElapsedTimeFields\n");
	pRtlTimeToElapsedTimeFields(Time, TimeFields);
	TRACE("Leave RtlTimeToElapsedTimeFields\n");
}

extern WINAPI void wine32a_ntdll_RtlTimeToElapsedTimeFields(void);  /* ../dlls/ntdll/time.c:433 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTimeToElapsedTimeFields,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTimeToElapsedTimeFields") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlTimeToSecondsSince1970(LARGE_INTEGER*  Time, LPDWORD  Seconds) /* ../dlls/ntdll/time.c:358 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlTimeToSecondsSince1970\n");
	return_value = pRtlTimeToSecondsSince1970(Time, Seconds);
	TRACE("Leave RtlTimeToSecondsSince1970\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTimeToSecondsSince1970(void);  /* ../dlls/ntdll/time.c:358 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTimeToSecondsSince1970,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTimeToSecondsSince1970") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlTimeToSecondsSince1980(LARGE_INTEGER*  Time, LPDWORD  Seconds) /* ../dlls/ntdll/time.c:379 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlTimeToSecondsSince1980\n");
	return_value = pRtlTimeToSecondsSince1980(Time, Seconds);
	TRACE("Leave RtlTimeToSecondsSince1980\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTimeToSecondsSince1980(void);  /* ../dlls/ntdll/time.c:379 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTimeToSecondsSince1980,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTimeToSecondsSince1980") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlTimeToTimeFields(LARGE_INTEGER*  liTime, PTIME_FIELDS  TimeFields) /* ../dlls/ntdll/time.c:141 */
{
	TRACE("Enter RtlTimeToTimeFields\n");
	pRtlTimeToTimeFields(liTime, TimeFields);
	TRACE("Leave RtlTimeToTimeFields\n");
}

extern WINAPI void wine32a_ntdll_RtlTimeToTimeFields(void);  /* ../dlls/ntdll/time.c:141 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTimeToTimeFields,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTimeToTimeFields") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlTryAcquireSRWLockExclusive(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2149 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlTryAcquireSRWLockExclusive\n");
	return_value = pRtlTryAcquireSRWLockExclusive(lock);
	TRACE("Leave RtlTryAcquireSRWLockExclusive\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTryAcquireSRWLockExclusive(void);  /* ../dlls/ntdll/sync.c:2149 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTryAcquireSRWLockExclusive,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTryAcquireSRWLockExclusive") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlTryAcquireSRWLockShared(RTL_SRWLOCK*  lock) /* ../dlls/ntdll/sync.c:2163 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlTryAcquireSRWLockShared\n");
	return_value = pRtlTryAcquireSRWLockShared(lock);
	TRACE("Leave RtlTryAcquireSRWLockShared\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTryAcquireSRWLockShared(void);  /* ../dlls/ntdll/sync.c:2163 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTryAcquireSRWLockShared,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTryAcquireSRWLockShared") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_RtlTryEnterCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:610 */
{
	BOOL return_value;
	TRACE("Enter RtlTryEnterCriticalSection\n");
	return_value = pRtlTryEnterCriticalSection(crit);
	TRACE("Leave RtlTryEnterCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlTryEnterCriticalSection(void);  /* ../dlls/ntdll/critsection.c:610 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlTryEnterCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlTryEnterCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONGLONG wine32b_ntdll_RtlUlonglongByteSwap(ULONGLONG  i) /* ../dlls/ntdll/rtl.c:617 */
{
	ULONGLONG return_value;
	TRACE("Enter RtlUlonglongByteSwap\n");
	return_value = pRtlUlonglongByteSwap(i);
	TRACE("Leave RtlUlonglongByteSwap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUlonglongByteSwap(void);  /* ../dlls/ntdll/rtl.c:617 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUlonglongByteSwap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUlonglongByteSwap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlUnicodeStringToAnsiSize(UNICODE_STRING*  str) /* ../dlls/ntdll/rtlstr.c:1374 */
{
	DWORD return_value;
	TRACE("Enter RtlUnicodeStringToAnsiSize\n");
	return_value = pRtlUnicodeStringToAnsiSize(str);
	TRACE("Leave RtlUnicodeStringToAnsiSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeStringToAnsiSize(void);  /* ../dlls/ntdll/rtlstr.c:1374 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeStringToAnsiSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeStringToAnsiSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeStringToAnsiString(STRING*  ansi, UNICODE_STRING*  uni, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:759 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeStringToAnsiString\n");
	return_value = pRtlUnicodeStringToAnsiString(ansi, uni, doalloc);
	TRACE("Leave RtlUnicodeStringToAnsiString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeStringToAnsiString(void);  /* ../dlls/ntdll/rtlstr.c:759 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeStringToAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeStringToAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeStringToInteger(UNICODE_STRING*  str, ULONG  base, ULONG*  value) /* ../dlls/ntdll/rtlstr.c:1911 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeStringToInteger\n");
	return_value = pRtlUnicodeStringToInteger(str, base, value);
	TRACE("Leave RtlUnicodeStringToInteger\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeStringToInteger(void);  /* ../dlls/ntdll/rtlstr.c:1911 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeStringToInteger,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeStringToInteger") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI DWORD wine32b_ntdll_RtlUnicodeStringToOemSize(UNICODE_STRING*  str) /* ../dlls/ntdll/rtlstr.c:1395 */
{
	DWORD return_value;
	TRACE("Enter RtlUnicodeStringToOemSize\n");
	return_value = pRtlUnicodeStringToOemSize(str);
	TRACE("Leave RtlUnicodeStringToOemSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeStringToOemSize(void);  /* ../dlls/ntdll/rtlstr.c:1395 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeStringToOemSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeStringToOemSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeStringToOemString(STRING*  oem, UNICODE_STRING*  uni, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:806 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeStringToOemString\n");
	return_value = pRtlUnicodeStringToOemString(oem, uni, doalloc);
	TRACE("Leave RtlUnicodeStringToOemString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeStringToOemString(void);  /* ../dlls/ntdll/rtlstr.c:806 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeStringToOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeStringToOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeToMultiByteN(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:881 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeToMultiByteN\n");
	return_value = pRtlUnicodeToMultiByteN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlUnicodeToMultiByteN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeToMultiByteN(void);  /* ../dlls/ntdll/rtlstr.c:881 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeToMultiByteN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeToMultiByteN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeToMultiByteSize(PULONG  size, LPCWSTR  str, ULONG  len) /* ../dlls/ntdll/rtlstr.c:1354 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeToMultiByteSize\n");
	return_value = pRtlUnicodeToMultiByteSize(size, str, len);
	TRACE("Leave RtlUnicodeToMultiByteSize\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeToMultiByteSize(void);  /* ../dlls/ntdll/rtlstr.c:1354 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeToMultiByteSize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeToMultiByteSize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeToOemN(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:900 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeToOemN\n");
	return_value = pRtlUnicodeToOemN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlUnicodeToOemN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeToOemN(void);  /* ../dlls/ntdll/rtlstr.c:900 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeToOemN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeToOemN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUnicodeToUTF8N(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:919 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUnicodeToUTF8N\n");
	return_value = pRtlUnicodeToUTF8N(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlUnicodeToUTF8N\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnicodeToUTF8N(void);  /* ../dlls/ntdll/rtlstr.c:919 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnicodeToUTF8N,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnicodeToUTF8N") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_RtlUniform(PULONG  seed) /* ../dlls/ntdll/rtl.c:678 */
{
	ULONG return_value;
	TRACE("Enter RtlUniform\n");
	return_value = pRtlUniform(seed);
	TRACE("Leave RtlUniform\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUniform(void);  /* ../dlls/ntdll/rtl.c:678 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUniform,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUniform") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlUnlockHeap(HANDLE  heap) /* ../dlls/ntdll/heap.c:1998 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlUnlockHeap\n");
	return_value = pRtlUnlockHeap(heap);
	TRACE("Leave RtlUnlockHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUnlockHeap(void);  /* ../dlls/ntdll/heap.c:1998 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnlockHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnlockHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlUnwind(void*  frame, void*  target_ip, EXCEPTION_RECORD*  rec, void*  retval) /* ../dlls/ntdll/signal_x86_64.c:3982 */
{
	TRACE("Enter RtlUnwind\n");
	pRtlUnwind(frame, target_ip, rec, retval);
	TRACE("Leave RtlUnwind\n");
}

extern WINAPI void wine32a_ntdll_RtlUnwind(void);  /* ../dlls/ntdll/signal_x86_64.c:3982 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnwind") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlUnwindEx(PVOID  end_frame, PVOID  target_ip, EXCEPTION_RECORD*  rec, PVOID  retval, CONTEXT*  context, UNWIND_HISTORY_TABLE*  table) /* ../dlls/ntdll/signal_x86_64.c:3850 */
{
	TRACE("Enter RtlUnwindEx\n");
	pRtlUnwindEx(end_frame, target_ip, rec, retval, context, table);
	TRACE("Leave RtlUnwindEx\n");
}

extern WINAPI void wine32a_ntdll_RtlUnwindEx(void);  /* ../dlls/ntdll/signal_x86_64.c:3850 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUnwindEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUnwindEx") "\n"
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

WINAPI WCHAR wine32b_ntdll_RtlUpcaseUnicodeChar(WCHAR  wch) /* ../dlls/ntdll/rtlstr.c:1014 */
{
	WCHAR return_value;
	TRACE("Enter RtlUpcaseUnicodeChar\n");
	return_value = pRtlUpcaseUnicodeChar(wch);
	TRACE("Leave RtlUpcaseUnicodeChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeChar(void);  /* ../dlls/ntdll/rtlstr.c:1014 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeString(UNICODE_STRING*  dest, UNICODE_STRING*  src, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:1056 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeString\n");
	return_value = pRtlUpcaseUnicodeString(dest, src, doalloc);
	TRACE("Leave RtlUpcaseUnicodeString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeString(void);  /* ../dlls/ntdll/rtlstr.c:1056 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeStringToAnsiString(STRING*  dst, UNICODE_STRING*  src, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:1131 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeStringToAnsiString\n");
	return_value = pRtlUpcaseUnicodeStringToAnsiString(dst, src, doalloc);
	TRACE("Leave RtlUpcaseUnicodeStringToAnsiString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeStringToAnsiString(void);  /* ../dlls/ntdll/rtlstr.c:1131 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeStringToAnsiString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeStringToAnsiString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeStringToCountedOemString(STRING*  oem, UNICODE_STRING*  uni, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:1187 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeStringToCountedOemString\n");
	return_value = pRtlUpcaseUnicodeStringToCountedOemString(oem, uni, doalloc);
	TRACE("Leave RtlUpcaseUnicodeStringToCountedOemString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeStringToCountedOemString(void);  /* ../dlls/ntdll/rtlstr.c:1187 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeStringToCountedOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeStringToCountedOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeStringToOemString(STRING*  dst, UNICODE_STRING*  src, BOOLEAN  doalloc) /* ../dlls/ntdll/rtlstr.c:1159 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeStringToOemString\n");
	return_value = pRtlUpcaseUnicodeStringToOemString(dst, src, doalloc);
	TRACE("Leave RtlUpcaseUnicodeStringToOemString\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeStringToOemString(void);  /* ../dlls/ntdll/rtlstr.c:1159 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeStringToOemString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeStringToOemString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeToMultiByteN(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:1235 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeToMultiByteN\n");
	return_value = pRtlUpcaseUnicodeToMultiByteN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlUpcaseUnicodeToMultiByteN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeToMultiByteN(void);  /* ../dlls/ntdll/rtlstr.c:1235 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeToMultiByteN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeToMultiByteN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpcaseUnicodeToOemN(LPSTR  dst, DWORD  dstlen, LPDWORD  reslen, LPCWSTR  src, DWORD  srclen) /* ../dlls/ntdll/rtlstr.c:1258 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpcaseUnicodeToOemN\n");
	return_value = pRtlUpcaseUnicodeToOemN(dst, dstlen, reslen, src, srclen);
	TRACE("Leave RtlUpcaseUnicodeToOemN\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpcaseUnicodeToOemN(void);  /* ../dlls/ntdll/rtlstr.c:1258 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpcaseUnicodeToOemN,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpcaseUnicodeToOemN") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlUpdateTimer(HANDLE  TimerQueue, HANDLE  Timer, DWORD  DueTime, DWORD  Period) /* ../dlls/ntdll/threadpool.c:1131 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlUpdateTimer\n");
	return_value = pRtlUpdateTimer(TimerQueue, Timer, DueTime, Period);
	TRACE("Leave RtlUpdateTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpdateTimer(void);  /* ../dlls/ntdll/threadpool.c:1131 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpdateTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpdateTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI CHAR wine32b_ntdll_RtlUpperChar(CHAR  ch) /* ../dlls/ntdll/rtlstr.c:965 */
{
	CHAR return_value;
	TRACE("Enter RtlUpperChar\n");
	return_value = pRtlUpperChar(ch);
	TRACE("Leave RtlUpperChar\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlUpperChar(void);  /* ../dlls/ntdll/rtlstr.c:965 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpperChar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpperChar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlUpperString(STRING*  dst, STRING*  src) /* ../dlls/ntdll/rtlstr.c:994 */
{
	TRACE("Enter RtlUpperString\n");
	pRtlUpperString(dst, src);
	TRACE("Leave RtlUpperString\n");
}

extern WINAPI void wine32a_ntdll_RtlUpperString(void);  /* ../dlls/ntdll/rtlstr.c:994 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlUpperString,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlUpperString") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlValidAcl(PACL  pAcl) /* ../dlls/ntdll/sec.c:1411 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlValidAcl\n");
	return_value = pRtlValidAcl(pAcl);
	TRACE("Leave RtlValidAcl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlValidAcl(void);  /* ../dlls/ntdll/sec.c:1411 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlValidAcl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlValidAcl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlValidRelativeSecurityDescriptor(PSECURITY_DESCRIPTOR  descriptor, ULONG  length, SECURITY_INFORMATION  info) /* ../dlls/ntdll/sec.c:561 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlValidRelativeSecurityDescriptor\n");
	return_value = pRtlValidRelativeSecurityDescriptor(descriptor, length, info);
	TRACE("Leave RtlValidRelativeSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlValidRelativeSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:561 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlValidRelativeSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlValidRelativeSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlValidSecurityDescriptor(PSECURITY_DESCRIPTOR  SecurityDescriptor) /* ../dlls/ntdll/sec.c:547 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlValidSecurityDescriptor\n");
	return_value = pRtlValidSecurityDescriptor(SecurityDescriptor);
	TRACE("Leave RtlValidSecurityDescriptor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlValidSecurityDescriptor(void);  /* ../dlls/ntdll/sec.c:547 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlValidSecurityDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlValidSecurityDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlValidSid(PSID  pSid) /* ../dlls/ntdll/sec.c:396 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlValidSid\n");
	return_value = pRtlValidSid(pSid);
	TRACE("Leave RtlValidSid\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlValidSid(void);  /* ../dlls/ntdll/sec.c:396 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlValidSid,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlValidSid") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOLEAN wine32b_ntdll_RtlValidateHeap(HANDLE  heap, ULONG  flags, LPCVOID  ptr) /* ../dlls/ntdll/heap.c:2076 */
{
	BOOLEAN return_value;
	TRACE("Enter RtlValidateHeap\n");
	return_value = pRtlValidateHeap(heap, flags, ptr);
	TRACE("Leave RtlValidateHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlValidateHeap(void);  /* ../dlls/ntdll/heap.c:2076 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlValidateHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlValidateHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlVerifyVersionInfo(RTL_OSVERSIONINFOEXW*  info, DWORD  dwTypeMask, DWORDLONG  dwlConditionMask) /* ../dlls/ntdll/version.c:716 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlVerifyVersionInfo\n");
	return_value = pRtlVerifyVersionInfo(info, dwTypeMask, dwlConditionMask);
	TRACE("Leave RtlVerifyVersionInfo\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlVerifyVersionInfo(void);  /* ../dlls/ntdll/version.c:716 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlVerifyVersionInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlVerifyVersionInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI PVOID wine32b_ntdll_RtlVirtualUnwind(ULONG  type, ULONG64  base, ULONG64  pc, RUNTIME_FUNCTION*  function, CONTEXT*  context, PVOID*  data, ULONG64*  frame_ret, KNONVOLATILE_CONTEXT_POINTERS*  ctx_ptr) /* ../dlls/ntdll/signal_x86_64.c:3534 */
{
	PVOID return_value;
	TRACE("Enter RtlVirtualUnwind\n");
	return_value = pRtlVirtualUnwind(type, base, pc, function, context, data, frame_ret, ctx_ptr);
	TRACE("Leave RtlVirtualUnwind\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlVirtualUnwind(void);  /* ../dlls/ntdll/signal_x86_64.c:3534 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlVirtualUnwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlVirtualUnwind") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlWaitOnAddress(void*  addr, void*  cmp, SIZE_T  size, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/sync.c:2449 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWaitOnAddress\n");
	return_value = pRtlWaitOnAddress(addr, cmp, size, timeout);
	TRACE("Leave RtlWaitOnAddress\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWaitOnAddress(void);  /* ../dlls/ntdll/sync.c:2449 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWaitOnAddress,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWaitOnAddress") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlWakeAddressAll(void*  addr) /* ../dlls/ntdll/sync.c:2519 */
{
	TRACE("Enter RtlWakeAddressAll\n");
	pRtlWakeAddressAll(addr);
	TRACE("Leave RtlWakeAddressAll\n");
}

extern WINAPI void wine32a_ntdll_RtlWakeAddressAll(void);  /* ../dlls/ntdll/sync.c:2519 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWakeAddressAll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWakeAddressAll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlWakeAddressSingle(void*  addr) /* ../dlls/ntdll/sync.c:2532 */
{
	TRACE("Enter RtlWakeAddressSingle\n");
	pRtlWakeAddressSingle(addr);
	TRACE("Leave RtlWakeAddressSingle\n");
}

extern WINAPI void wine32a_ntdll_RtlWakeAddressSingle(void);  /* ../dlls/ntdll/sync.c:2532 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWakeAddressSingle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWakeAddressSingle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlWakeAllConditionVariable(RTL_CONDITION_VARIABLE*  variable) /* ../dlls/ntdll/sync.c:2265 */
{
	TRACE("Enter RtlWakeAllConditionVariable\n");
	pRtlWakeAllConditionVariable(variable);
	TRACE("Leave RtlWakeAllConditionVariable\n");
}

extern WINAPI void wine32a_ntdll_RtlWakeAllConditionVariable(void);  /* ../dlls/ntdll/sync.c:2265 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWakeAllConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWakeAllConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_RtlWakeConditionVariable(RTL_CONDITION_VARIABLE*  variable) /* ../dlls/ntdll/sync.c:2253 */
{
	TRACE("Enter RtlWakeConditionVariable\n");
	pRtlWakeConditionVariable(variable);
	TRACE("Leave RtlWakeConditionVariable\n");
}

extern WINAPI void wine32a_ntdll_RtlWakeConditionVariable(void);  /* ../dlls/ntdll/sync.c:2253 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWakeConditionVariable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWakeConditionVariable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWalkHeap(HANDLE  heap, PVOID  entry_ptr) /* ../dlls/ntdll/heap.c:2091 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWalkHeap\n");
	return_value = pRtlWalkHeap(heap, entry_ptr);
	TRACE("Leave RtlWalkHeap\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWalkHeap(void);  /* ../dlls/ntdll/heap.c:2091 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWalkHeap,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWalkHeap") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWow64EnableFsRedirection(BOOLEAN  enable) /* ../dlls/ntdll/directory.c:2872 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWow64EnableFsRedirection\n");
	return_value = pRtlWow64EnableFsRedirection(enable);
	TRACE("Leave RtlWow64EnableFsRedirection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWow64EnableFsRedirection(void);  /* ../dlls/ntdll/directory.c:2872 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWow64EnableFsRedirection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWow64EnableFsRedirection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWow64EnableFsRedirectionEx(ULONG  disable, ULONG*  old_value) /* ../dlls/ntdll/directory.c:2883 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWow64EnableFsRedirectionEx\n");
	return_value = pRtlWow64EnableFsRedirectionEx(disable, old_value);
	TRACE("Leave RtlWow64EnableFsRedirectionEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWow64EnableFsRedirectionEx(void);  /* ../dlls/ntdll/directory.c:2883 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWow64EnableFsRedirectionEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWow64EnableFsRedirectionEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWow64GetThreadContext(HANDLE  handle, WOW64_CONTEXT*  context) /* ../dlls/ntdll/signal_x86_64.c:2404 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWow64GetThreadContext\n");
	return_value = pRtlWow64GetThreadContext(handle, context);
	TRACE("Leave RtlWow64GetThreadContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWow64GetThreadContext(void);  /* ../dlls/ntdll/signal_x86_64.c:2404 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWow64GetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWow64GetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWow64SetThreadContext(HANDLE  handle, WOW64_CONTEXT*  context) /* ../dlls/ntdll/signal_x86_64.c:2420 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWow64SetThreadContext\n");
	return_value = pRtlWow64SetThreadContext(handle, context);
	TRACE("Leave RtlWow64SetThreadContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWow64SetThreadContext(void);  /* ../dlls/ntdll/signal_x86_64.c:2420 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWow64SetThreadContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWow64SetThreadContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlWriteRegistryValue(ULONG  RelativeTo, PCWSTR  path, PCWSTR  name, ULONG  type, PVOID  data, ULONG  length) /* ../dlls/ntdll/reg.c:1512 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlWriteRegistryValue\n");
	return_value = pRtlWriteRegistryValue(RelativeTo, path, name, type, data, length);
	TRACE("Leave RtlWriteRegistryValue\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlWriteRegistryValue(void);  /* ../dlls/ntdll/reg.c:1512 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlWriteRegistryValue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlWriteRegistryValue") "\n"
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

WINAPI void wine32b_ntdll_RtlZeroMemory(void*  Destination, SIZE_T  Length) /* ../dlls/ntdll/rtl.c:483 */
{
	TRACE("Enter RtlZeroMemory\n");
	pRtlZeroMemory(Destination, Length);
	TRACE("Leave RtlZeroMemory\n");
}

extern WINAPI void wine32a_ntdll_RtlZeroMemory(void);  /* ../dlls/ntdll/rtl.c:483 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlZeroMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlZeroMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlZombifyActivationContext(HANDLE  handle) /* ../dlls/ntdll/actctx.c:5115 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlZombifyActivationContext\n");
	return_value = pRtlZombifyActivationContext(handle);
	TRACE("Leave RtlZombifyActivationContext\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlZombifyActivationContext(void);  /* ../dlls/ntdll/actctx.c:5115 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlZombifyActivationContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlZombifyActivationContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpNtCreateKey(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr, ULONG  TitleIndex, UNICODE_STRING*  class, ULONG  options, PULONG  dispos) /* ../dlls/ntdll/reg.c:105 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtCreateKey\n");
	return_value = pRtlpNtCreateKey(retkey, access, attr, TitleIndex, class, options, dispos);
	TRACE("Leave RtlpNtCreateKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtCreateKey(void);  /* ../dlls/ntdll/reg.c:105 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtCreateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtCreateKey") "\n"
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

WINAPI NTSTATUS wine32b_ntdll_RtlpNtEnumerateSubKey(HANDLE  handle, UNICODE_STRING*  out, ULONG  index) /* ../dlls/ntdll/reg.c:384 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtEnumerateSubKey\n");
	return_value = pRtlpNtEnumerateSubKey(handle, out, index);
	TRACE("Leave RtlpNtEnumerateSubKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtEnumerateSubKey(void);  /* ../dlls/ntdll/reg.c:384 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtEnumerateSubKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtEnumerateSubKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpNtMakeTemporaryKey(HANDLE  hkey) /* ../dlls/ntdll/reg.c:218 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtMakeTemporaryKey\n");
	return_value = pRtlpNtMakeTemporaryKey(hkey);
	TRACE("Leave RtlpNtMakeTemporaryKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtMakeTemporaryKey(void);  /* ../dlls/ntdll/reg.c:218 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtMakeTemporaryKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtMakeTemporaryKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpNtOpenKey(PHANDLE  retkey, ACCESS_MASK  access, OBJECT_ATTRIBUTES*  attr) /* ../dlls/ntdll/reg.c:187 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtOpenKey\n");
	return_value = pRtlpNtOpenKey(retkey, access, attr);
	TRACE("Leave RtlpNtOpenKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtOpenKey(void);  /* ../dlls/ntdll/reg.c:187 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtOpenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtOpenKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpNtQueryValueKey(HANDLE  handle, ULONG*  result_type, PBYTE  dest, DWORD*  result_len, void*  unknown) /* ../dlls/ntdll/reg.c:599 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtQueryValueKey\n");
	return_value = pRtlpNtQueryValueKey(handle, result_type, dest, result_len, unknown);
	TRACE("Leave RtlpNtQueryValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtQueryValueKey(void);  /* ../dlls/ntdll/reg.c:599 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtQueryValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtQueryValueKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpNtSetValueKey(HANDLE  hkey, ULONG  type, void*  data, ULONG  count) /* ../dlls/ntdll/reg.c:886 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpNtSetValueKey\n");
	return_value = pRtlpNtSetValueKey(hkey, type, data, count);
	TRACE("Leave RtlpNtSetValueKey\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpNtSetValueKey(void);  /* ../dlls/ntdll/reg.c:886 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpNtSetValueKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpNtSetValueKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpUnWaitCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:524 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpUnWaitCriticalSection\n");
	return_value = pRtlpUnWaitCriticalSection(crit);
	TRACE("Leave RtlpUnWaitCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpUnWaitCriticalSection(void);  /* ../dlls/ntdll/critsection.c:524 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpUnWaitCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpUnWaitCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_RtlpWaitForCriticalSection(RTL_CRITICAL_SECTION*  crit) /* ../dlls/ntdll/critsection.c:444 */
{
	NTSTATUS return_value;
	TRACE("Enter RtlpWaitForCriticalSection\n");
	return_value = pRtlpWaitForCriticalSection(crit);
	TRACE("Leave RtlpWaitForCriticalSection\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_RtlpWaitForCriticalSection(void);  /* ../dlls/ntdll/critsection.c:444 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_RtlpWaitForCriticalSection,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_RtlpWaitForCriticalSection") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpAllocCleanupGroup(TP_CLEANUP_GROUP**  out) /* ../dlls/ntdll/threadpool.c:2301 */
{
	NTSTATUS return_value;
	TRACE("Enter TpAllocCleanupGroup\n");
	return_value = pTpAllocCleanupGroup(out);
	TRACE("Leave TpAllocCleanupGroup\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpAllocCleanupGroup(void);  /* ../dlls/ntdll/threadpool.c:2301 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpAllocCleanupGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpAllocCleanupGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpAllocPool(TP_POOL**  out, PVOID  reserved) /* ../dlls/ntdll/threadpool.c:2311 */
{
	NTSTATUS return_value;
	TRACE("Enter TpAllocPool\n");
	return_value = pTpAllocPool(out, reserved);
	TRACE("Leave TpAllocPool\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpAllocPool(void);  /* ../dlls/ntdll/threadpool.c:2311 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpAllocPool,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpAllocPool") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpAllocTimer(TP_TIMER**  out, PTP_TIMER_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/ntdll/threadpool.c:2324 */
{
	NTSTATUS return_value;
	TRACE("Enter TpAllocTimer\n");
	return_value = pTpAllocTimer(out, callback, userdata, environment);
	TRACE("Leave TpAllocTimer\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpAllocTimer(void);  /* ../dlls/ntdll/threadpool.c:2324 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpAllocTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpAllocTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpAllocWait(TP_WAIT**  out, PTP_WAIT_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/ntdll/threadpool.c:2364 */
{
	NTSTATUS return_value;
	TRACE("Enter TpAllocWait\n");
	return_value = pTpAllocWait(out, callback, userdata, environment);
	TRACE("Leave TpAllocWait\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpAllocWait(void);  /* ../dlls/ntdll/threadpool.c:2364 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpAllocWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpAllocWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpAllocWork(TP_WORK**  out, PTP_WORK_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/ntdll/threadpool.c:2404 */
{
	NTSTATUS return_value;
	TRACE("Enter TpAllocWork\n");
	return_value = pTpAllocWork(out, callback, userdata, environment);
	TRACE("Leave TpAllocWork\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpAllocWork(void);  /* ../dlls/ntdll/threadpool.c:2404 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpAllocWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpAllocWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpCallbackLeaveCriticalSectionOnCompletion(TP_CALLBACK_INSTANCE*  instance, CRITICAL_SECTION*  crit) /* ../dlls/ntdll/threadpool.c:2435 */
{
	TRACE("Enter TpCallbackLeaveCriticalSectionOnCompletion\n");
	pTpCallbackLeaveCriticalSectionOnCompletion(instance, crit);
	TRACE("Leave TpCallbackLeaveCriticalSectionOnCompletion\n");
}

extern WINAPI void wine32a_ntdll_TpCallbackLeaveCriticalSectionOnCompletion(void);  /* ../dlls/ntdll/threadpool.c:2435 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackLeaveCriticalSectionOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackLeaveCriticalSectionOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpCallbackMayRunLong(TP_CALLBACK_INSTANCE*  instance) /* ../dlls/ntdll/threadpool.c:2448 */
{
	NTSTATUS return_value;
	TRACE("Enter TpCallbackMayRunLong\n");
	return_value = pTpCallbackMayRunLong(instance);
	TRACE("Leave TpCallbackMayRunLong\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpCallbackMayRunLong(void);  /* ../dlls/ntdll/threadpool.c:2448 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackMayRunLong,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackMayRunLong") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpCallbackReleaseMutexOnCompletion(TP_CALLBACK_INSTANCE*  instance, HANDLE  mutex) /* ../dlls/ntdll/threadpool.c:2490 */
{
	TRACE("Enter TpCallbackReleaseMutexOnCompletion\n");
	pTpCallbackReleaseMutexOnCompletion(instance, mutex);
	TRACE("Leave TpCallbackReleaseMutexOnCompletion\n");
}

extern WINAPI void wine32a_ntdll_TpCallbackReleaseMutexOnCompletion(void);  /* ../dlls/ntdll/threadpool.c:2490 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackReleaseMutexOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackReleaseMutexOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpCallbackReleaseSemaphoreOnCompletion(TP_CALLBACK_INSTANCE*  instance, HANDLE  semaphore, DWORD  count) /* ../dlls/ntdll/threadpool.c:2503 */
{
	TRACE("Enter TpCallbackReleaseSemaphoreOnCompletion\n");
	pTpCallbackReleaseSemaphoreOnCompletion(instance, semaphore, count);
	TRACE("Leave TpCallbackReleaseSemaphoreOnCompletion\n");
}

extern WINAPI void wine32a_ntdll_TpCallbackReleaseSemaphoreOnCompletion(void);  /* ../dlls/ntdll/threadpool.c:2503 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackReleaseSemaphoreOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackReleaseSemaphoreOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpCallbackSetEventOnCompletion(TP_CALLBACK_INSTANCE*  instance, HANDLE  event) /* ../dlls/ntdll/threadpool.c:2519 */
{
	TRACE("Enter TpCallbackSetEventOnCompletion\n");
	pTpCallbackSetEventOnCompletion(instance, event);
	TRACE("Leave TpCallbackSetEventOnCompletion\n");
}

extern WINAPI void wine32a_ntdll_TpCallbackSetEventOnCompletion(void);  /* ../dlls/ntdll/threadpool.c:2519 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackSetEventOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackSetEventOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpCallbackUnloadDllOnCompletion(TP_CALLBACK_INSTANCE*  instance, HMODULE  module) /* ../dlls/ntdll/threadpool.c:2532 */
{
	TRACE("Enter TpCallbackUnloadDllOnCompletion\n");
	pTpCallbackUnloadDllOnCompletion(instance, module);
	TRACE("Leave TpCallbackUnloadDllOnCompletion\n");
}

extern WINAPI void wine32a_ntdll_TpCallbackUnloadDllOnCompletion(void);  /* ../dlls/ntdll/threadpool.c:2532 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpCallbackUnloadDllOnCompletion,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpCallbackUnloadDllOnCompletion") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpDisassociateCallback(TP_CALLBACK_INSTANCE*  instance) /* ../dlls/ntdll/threadpool.c:2545 */
{
	TRACE("Enter TpDisassociateCallback\n");
	pTpDisassociateCallback(instance);
	TRACE("Leave TpDisassociateCallback\n");
}

extern WINAPI void wine32a_ntdll_TpDisassociateCallback(void);  /* ../dlls/ntdll/threadpool.c:2545 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpDisassociateCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpDisassociateCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_TpIsTimerSet(TP_TIMER*  timer) /* ../dlls/ntdll/threadpool.c:2576 */
{
	BOOL return_value;
	TRACE("Enter TpIsTimerSet\n");
	return_value = pTpIsTimerSet(timer);
	TRACE("Leave TpIsTimerSet\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpIsTimerSet(void);  /* ../dlls/ntdll/threadpool.c:2576 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpIsTimerSet,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpIsTimerSet") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpPostWork(TP_WORK*  work) /* ../dlls/ntdll/threadpool.c:2588 */
{
	TRACE("Enter TpPostWork\n");
	pTpPostWork(work);
	TRACE("Leave TpPostWork\n");
}

extern WINAPI void wine32a_ntdll_TpPostWork(void);  /* ../dlls/ntdll/threadpool.c:2588 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpPostWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpPostWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleaseCleanupGroup(TP_CLEANUP_GROUP*  group) /* ../dlls/ntdll/threadpool.c:2600 */
{
	TRACE("Enter TpReleaseCleanupGroup\n");
	pTpReleaseCleanupGroup(group);
	TRACE("Leave TpReleaseCleanupGroup\n");
}

extern WINAPI void wine32a_ntdll_TpReleaseCleanupGroup(void);  /* ../dlls/ntdll/threadpool.c:2600 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleaseCleanupGroup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleaseCleanupGroup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleaseCleanupGroupMembers(TP_CLEANUP_GROUP*  group, BOOL  cancel_pending, PVOID  userdata) /* ../dlls/ntdll/threadpool.c:2613 */
{
	TRACE("Enter TpReleaseCleanupGroupMembers\n");
	pTpReleaseCleanupGroupMembers(group, cancel_pending, userdata);
	TRACE("Leave TpReleaseCleanupGroupMembers\n");
}

extern WINAPI void wine32a_ntdll_TpReleaseCleanupGroupMembers(void);  /* ../dlls/ntdll/threadpool.c:2613 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleaseCleanupGroupMembers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleaseCleanupGroupMembers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleasePool(TP_POOL*  pool) /* ../dlls/ntdll/threadpool.c:2686 */
{
	TRACE("Enter TpReleasePool\n");
	pTpReleasePool(pool);
	TRACE("Leave TpReleasePool\n");
}

extern WINAPI void wine32a_ntdll_TpReleasePool(void);  /* ../dlls/ntdll/threadpool.c:2686 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleasePool,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleasePool") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleaseTimer(TP_TIMER*  timer) /* ../dlls/ntdll/threadpool.c:2699 */
{
	TRACE("Enter TpReleaseTimer\n");
	pTpReleaseTimer(timer);
	TRACE("Leave TpReleaseTimer\n");
}

extern WINAPI void wine32a_ntdll_TpReleaseTimer(void);  /* ../dlls/ntdll/threadpool.c:2699 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleaseTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleaseTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleaseWait(TP_WAIT*  wait) /* ../dlls/ntdll/threadpool.c:2713 */
{
	TRACE("Enter TpReleaseWait\n");
	pTpReleaseWait(wait);
	TRACE("Leave TpReleaseWait\n");
}

extern WINAPI void wine32a_ntdll_TpReleaseWait(void);  /* ../dlls/ntdll/threadpool.c:2713 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleaseWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleaseWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpReleaseWork(TP_WORK*  work) /* ../dlls/ntdll/threadpool.c:2727 */
{
	TRACE("Enter TpReleaseWork\n");
	pTpReleaseWork(work);
	TRACE("Leave TpReleaseWork\n");
}

extern WINAPI void wine32a_ntdll_TpReleaseWork(void);  /* ../dlls/ntdll/threadpool.c:2727 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpReleaseWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpReleaseWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpSetPoolMaxThreads(TP_POOL*  pool, DWORD  maximum) /* ../dlls/ntdll/threadpool.c:2741 */
{
	TRACE("Enter TpSetPoolMaxThreads\n");
	pTpSetPoolMaxThreads(pool, maximum);
	TRACE("Leave TpSetPoolMaxThreads\n");
}

extern WINAPI void wine32a_ntdll_TpSetPoolMaxThreads(void);  /* ../dlls/ntdll/threadpool.c:2741 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpSetPoolMaxThreads,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpSetPoolMaxThreads") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_TpSetPoolMinThreads(TP_POOL*  pool, DWORD  minimum) /* ../dlls/ntdll/threadpool.c:2756 */
{
	BOOL return_value;
	TRACE("Enter TpSetPoolMinThreads\n");
	return_value = pTpSetPoolMinThreads(pool, minimum);
	TRACE("Leave TpSetPoolMinThreads\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpSetPoolMinThreads(void);  /* ../dlls/ntdll/threadpool.c:2756 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpSetPoolMinThreads,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpSetPoolMinThreads") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpSetTimer(TP_TIMER*  timer, LARGE_INTEGER*  timeout, LONG  period, LONG  window_length) /* ../dlls/ntdll/threadpool.c:2785 */
{
	TRACE("Enter TpSetTimer\n");
	pTpSetTimer(timer, timeout, period, window_length);
	TRACE("Leave TpSetTimer\n");
}

extern WINAPI void wine32a_ntdll_TpSetTimer(void);  /* ../dlls/ntdll/threadpool.c:2785 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpSetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpSetTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpSetWait(TP_WAIT*  wait, HANDLE  handle, LARGE_INTEGER*  timeout) /* ../dlls/ntdll/threadpool.c:2863 */
{
	TRACE("Enter TpSetWait\n");
	pTpSetWait(wait, handle, timeout);
	TRACE("Leave TpSetWait\n");
}

extern WINAPI void wine32a_ntdll_TpSetWait(void);  /* ../dlls/ntdll/threadpool.c:2863 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpSetWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpSetWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_TpSimpleTryPost(PTP_SIMPLE_CALLBACK  callback, PVOID  userdata, TP_CALLBACK_ENVIRON*  environment) /* ../dlls/ntdll/threadpool.c:2924 */
{
	NTSTATUS return_value;
	TRACE("Enter TpSimpleTryPost\n");
	return_value = pTpSimpleTryPost(callback, userdata, environment);
	TRACE("Leave TpSimpleTryPost\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_TpSimpleTryPost(void);  /* ../dlls/ntdll/threadpool.c:2924 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpSimpleTryPost,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpSimpleTryPost") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpWaitForTimer(TP_TIMER*  timer, BOOL  cancel_pending) /* ../dlls/ntdll/threadpool.c:2954 */
{
	TRACE("Enter TpWaitForTimer\n");
	pTpWaitForTimer(timer, cancel_pending);
	TRACE("Leave TpWaitForTimer\n");
}

extern WINAPI void wine32a_ntdll_TpWaitForTimer(void);  /* ../dlls/ntdll/threadpool.c:2954 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpWaitForTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpWaitForTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpWaitForWait(TP_WAIT*  wait, BOOL  cancel_pending) /* ../dlls/ntdll/threadpool.c:2968 */
{
	TRACE("Enter TpWaitForWait\n");
	pTpWaitForWait(wait, cancel_pending);
	TRACE("Leave TpWaitForWait\n");
}

extern WINAPI void wine32a_ntdll_TpWaitForWait(void);  /* ../dlls/ntdll/threadpool.c:2968 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpWaitForWait,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpWaitForWait") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_TpWaitForWork(TP_WORK*  work, BOOL  cancel_pending) /* ../dlls/ntdll/threadpool.c:2982 */
{
	TRACE("Enter TpWaitForWork\n");
	pTpWaitForWork(work, cancel_pending);
	TRACE("Leave TpWaitForWork\n");
}

extern WINAPI void wine32a_ntdll_TpWaitForWork(void);  /* ../dlls/ntdll/threadpool.c:2982 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_TpWaitForWork,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_TpWaitForWork") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONGLONG wine32b_ntdll_VerSetConditionMask(ULONGLONG  dwlConditionMask, DWORD  dwTypeBitMask, BYTE  dwConditionMask) /* ../dlls/ntdll/nt.c:3369 */
{
	ULONGLONG return_value;
	TRACE("Enter VerSetConditionMask\n");
	return_value = pVerSetConditionMask(dwlConditionMask, dwTypeBitMask, dwConditionMask);
	TRACE("Leave VerSetConditionMask\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_VerSetConditionMask(void);  /* ../dlls/ntdll/nt.c:3369 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_VerSetConditionMask,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_VerSetConditionMask") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_WinSqmEndSession(HANDLE  session) /* ../dlls/ntdll/misc.c:338 */
{
	NTSTATUS return_value;
	TRACE("Enter WinSqmEndSession\n");
	return_value = pWinSqmEndSession(session);
	TRACE("Leave WinSqmEndSession\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_WinSqmEndSession(void);  /* ../dlls/ntdll/misc.c:338 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_WinSqmEndSession,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_WinSqmEndSession") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_WinSqmIncrementDWORD(DWORD  unk1, DWORD  unk2, DWORD  unk3) /* ../dlls/ntdll/misc.c:347 */
{
	TRACE("Enter WinSqmIncrementDWORD\n");
	pWinSqmIncrementDWORD(unk1, unk2, unk3);
	TRACE("Leave WinSqmIncrementDWORD\n");
}

extern WINAPI void wine32a_ntdll_WinSqmIncrementDWORD(void);  /* ../dlls/ntdll/misc.c:347 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_WinSqmIncrementDWORD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_WinSqmIncrementDWORD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI BOOL wine32b_ntdll_WinSqmIsOptedIn(void) /* ../dlls/ntdll/misc.c:355 */
{
	BOOL return_value;
	TRACE("Enter WinSqmIsOptedIn\n");
	return_value = pWinSqmIsOptedIn();
	TRACE("Leave WinSqmIsOptedIn\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_WinSqmIsOptedIn(void);  /* ../dlls/ntdll/misc.c:355 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_WinSqmIsOptedIn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_WinSqmIsOptedIn") "\n"
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

WINAPI void wine32b_ntdll_WinSqmSetDWORD(HANDLE  session, DWORD  datapoint_id, DWORD  datapoint_value) /* ../dlls/ntdll/misc.c:373 */
{
	TRACE("Enter WinSqmSetDWORD\n");
	pWinSqmSetDWORD(session, datapoint_id, datapoint_value);
	TRACE("Leave WinSqmSetDWORD\n");
}

extern WINAPI void wine32a_ntdll_WinSqmSetDWORD(void);  /* ../dlls/ntdll/misc.c:373 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_WinSqmSetDWORD,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_WinSqmSetDWORD") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI HANDLE wine32b_ntdll_WinSqmStartSession(GUID*  sessionguid, DWORD  sessionid, DWORD  unknown1) /* ../dlls/ntdll/misc.c:364 */
{
	HANDLE return_value;
	TRACE("Enter WinSqmStartSession\n");
	return_value = pWinSqmStartSession(sessionguid, sessionid, unknown1);
	TRACE("Leave WinSqmStartSession\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_WinSqmStartSession(void);  /* ../dlls/ntdll/misc.c:364 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_WinSqmStartSession,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_WinSqmStartSession") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI EXCEPTION_DISPOSITION wine32b_ntdll___C_specific_handler(EXCEPTION_RECORD*  rec, void*  frame, CONTEXT*  context, struct _DISPATCHER_CONTEXT*  dispatch) /* ../dlls/ntdll/signal_x86_64.c:4001 */
{
	EXCEPTION_DISPOSITION return_value;
	TRACE("Enter __C_specific_handler\n");
	return_value = p__C_specific_handler(rec, frame, context, dispatch);
	TRACE("Leave __C_specific_handler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___C_specific_handler(void);  /* ../dlls/ntdll/signal_x86_64.c:4001 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___C_specific_handler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___C_specific_handler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___isascii(int  c) /* ../dlls/ntdll/string.c:455 */
{
	int return_value;
	TRACE("Enter __isascii\n");
	return_value = p__isascii(c);
	TRACE("Leave __isascii\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___isascii(void);  /* ../dlls/ntdll/string.c:455 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___isascii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___isascii") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___iscsym(int  c) /* ../dlls/ntdll/string.c:473 */
{
	int return_value;
	TRACE("Enter __iscsym\n");
	return_value = p__iscsym(c);
	TRACE("Leave __iscsym\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___iscsym(void);  /* ../dlls/ntdll/string.c:473 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___iscsym,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___iscsym") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___iscsymf(int  c) /* ../dlls/ntdll/string.c:482 */
{
	int return_value;
	TRACE("Enter __iscsymf\n");
	return_value = p__iscsymf(c);
	TRACE("Leave __iscsymf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___iscsymf(void);  /* ../dlls/ntdll/string.c:482 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___iscsymf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___iscsymf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___toascii(int  c) /* ../dlls/ntdll/string.c:464 */
{
	int return_value;
	TRACE("Enter __toascii\n");
	return_value = p__toascii(c);
	TRACE("Leave __toascii\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___toascii(void);  /* ../dlls/ntdll/string.c:464 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___toascii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___toascii") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONGLONG wine32b_ntdll__atoi64(char*  str) /* ../dlls/ntdll/string.c:769 */
{
	LONGLONG return_value;
	TRACE("Enter _atoi64\n");
	return_value = p_atoi64(str);
	TRACE("Leave _atoi64\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__atoi64(void);  /* ../dlls/ntdll/string.c:769 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__atoi64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__atoi64") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll__i64toa(LONGLONG  value, char*  str, int  radix) /* ../dlls/ntdll/string.c:710 */
{
	char* return_value;
	TRACE("Enter _i64toa\n");
	return_value = p_i64toa(value, str, radix);
	TRACE("Leave _i64toa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__i64toa(void);  /* ../dlls/ntdll/string.c:710 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__i64toa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__i64toa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__i64tow(LONGLONG  value, LPWSTR  str, INT  radix) /* ../dlls/ntdll/wcstring.c:581 */
{
	LPWSTR return_value;
	TRACE("Enter _i64tow\n");
	return_value = p_i64tow(value, str, radix);
	TRACE("Leave _i64tow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__i64tow(void);  /* ../dlls/ntdll/wcstring.c:581 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__i64tow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__i64tow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll__itoa(int  value, char*  str, int  radix) /* ../dlls/ntdll/string.c:636 */
{
	char* return_value;
	TRACE("Enter _itoa\n");
	return_value = p_itoa(value, str, radix);
	TRACE("Leave _itoa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__itoa(void);  /* ../dlls/ntdll/string.c:636 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__itoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__itoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__itow(int  value, LPWSTR  str, INT  radix) /* ../dlls/ntdll/wcstring.c:500 */
{
	LPWSTR return_value;
	TRACE("Enter _itow\n");
	return_value = p_itow(value, str, radix);
	TRACE("Leave _itow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__itow(void);  /* ../dlls/ntdll/wcstring.c:500 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__itow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__itow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll__lfind(void*  key, void*  base, unsigned int*  nmemb, size_t  size, int (* compar) (void)) /* ../dlls/ntdll/misc.c:324 */
{
	void* return_value;
	TRACE("Enter _lfind\n");
	return_value = p_lfind(key, base, nmemb, size, compar);
	TRACE("Leave _lfind\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__lfind(void);  /* ../dlls/ntdll/misc.c:324 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__lfind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__lfind") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll__local_unwind(void*  frame, void*  target_ip) /* ../dlls/ntdll/signal_x86_64.c:3992 */
{
	TRACE("Enter _local_unwind\n");
	p_local_unwind(frame, target_ip);
	TRACE("Leave _local_unwind\n");
}

extern WINAPI void wine32a_ntdll__local_unwind(void);  /* ../dlls/ntdll/signal_x86_64.c:3992 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__local_unwind,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__local_unwind") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll__ltoa(LONG  value, char*  str, int  radix) /* ../dlls/ntdll/string.c:580 */
{
	char* return_value;
	TRACE("Enter _ltoa\n");
	return_value = p_ltoa(value, str, radix);
	TRACE("Leave _ltoa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ltoa(void);  /* ../dlls/ntdll/string.c:580 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ltoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ltoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__ltow(LONG  value, LPWSTR  str, INT  radix) /* ../dlls/ntdll/wcstring.c:438 */
{
	LPWSTR return_value;
	TRACE("Enter _ltow\n");
	return_value = p_ltow(value, str, radix);
	TRACE("Leave _ltow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ltow(void);  /* ../dlls/ntdll/wcstring.c:438 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ltow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ltow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll__memccpy(void*  dst, void*  src, int  c, size_t  n) /* ../dlls/ntdll/string.c:214 */
{
	void* return_value;
	TRACE("Enter _memccpy\n");
	return_value = p_memccpy(dst, src, c, n);
	TRACE("Leave _memccpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__memccpy(void);  /* ../dlls/ntdll/string.c:214 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__memccpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__memccpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll__memicmp(LPCSTR  s1, LPCSTR  s2, DWORD  len) /* ../dlls/ntdll/string.c:247 */
{
	INT return_value;
	TRACE("Enter _memicmp\n");
	return_value = p_memicmp(s1, s2, len);
	TRACE("Leave _memicmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__memicmp(void);  /* ../dlls/ntdll/string.c:247 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__memicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__memicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__snprintf(char*  str, SIZE_T  len, char*  format) /* ../dlls/ntdll/printf.c:740 */
{
	int return_value;
	TRACE("Enter _snprintf\n");
	return_value = p_snprintf(str, len, format);
	TRACE("Leave _snprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__snprintf(void);  /* ../dlls/ntdll/printf.c:740 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__snprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__snprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__snprintf_s(char*  str, SIZE_T  size, SIZE_T  len, char*  format) /* ../dlls/ntdll/printf.c:800 */
{
	int return_value;
	TRACE("Enter _snprintf_s\n");
	return_value = p_snprintf_s(str, size, len, format);
	TRACE("Leave _snprintf_s\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__snprintf_s(void);  /* ../dlls/ntdll/printf.c:800 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__snprintf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__snprintf_s") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__snwprintf(WCHAR*  str, SIZE_T  len, WCHAR*  format) /* ../dlls/ntdll/printf.c:755 */
{
	int return_value;
	TRACE("Enter _snwprintf\n");
	return_value = p_snwprintf(str, len, format);
	TRACE("Leave _snwprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__snwprintf(void);  /* ../dlls/ntdll/printf.c:755 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__snwprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__snwprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll__splitpath(char*  inpath, char*  drv, char*  dir, char*  fname, char*  ext) /* ../dlls/ntdll/string.c:1426 */
{
	TRACE("Enter _splitpath\n");
	p_splitpath(inpath, drv, dir, fname, ext);
	TRACE("Leave _splitpath\n");
}

extern WINAPI void wine32a_ntdll__splitpath(void);  /* ../dlls/ntdll/string.c:1426 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__splitpath,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__splitpath") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__stricmp(LPCSTR  str1, LPCSTR  str2) /* ../dlls/ntdll/string.c:288 */
{
	int return_value;
	TRACE("Enter _stricmp\n");
	return_value = p_stricmp(str1, str2);
	TRACE("Leave _stricmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__stricmp(void);  /* ../dlls/ntdll/string.c:288 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__stricmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__stricmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPSTR wine32b_ntdll__strlwr(LPSTR  str) /* ../dlls/ntdll/string.c:326 */
{
	LPSTR return_value;
	TRACE("Enter _strlwr\n");
	return_value = p_strlwr(str);
	TRACE("Leave _strlwr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__strlwr(void);  /* ../dlls/ntdll/string.c:326 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__strlwr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__strlwr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__strnicmp(LPCSTR  str1, LPCSTR  str2, size_t  n) /* ../dlls/ntdll/string.c:263 */
{
	int return_value;
	TRACE("Enter _strnicmp\n");
	return_value = p_strnicmp(str1, str2, n);
	TRACE("Leave _strnicmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__strnicmp(void);  /* ../dlls/ntdll/string.c:263 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__strnicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__strnicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPSTR wine32b_ntdll__strupr(LPSTR  str) /* ../dlls/ntdll/string.c:306 */
{
	LPSTR return_value;
	TRACE("Enter _strupr\n");
	return_value = p_strupr(str);
	TRACE("Leave _strupr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__strupr(void);  /* ../dlls/ntdll/string.c:306 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__strupr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__strupr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__tolower(int  c) /* ../dlls/ntdll/string.c:500 */
{
	int return_value;
	TRACE("Enter _tolower\n");
	return_value = p_tolower(c);
	TRACE("Leave _tolower\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__tolower(void);  /* ../dlls/ntdll/string.c:500 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__tolower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__tolower") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__toupper(int  c) /* ../dlls/ntdll/string.c:491 */
{
	int return_value;
	TRACE("Enter _toupper\n");
	return_value = p_toupper(c);
	TRACE("Leave _toupper\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__toupper(void);  /* ../dlls/ntdll/string.c:491 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__toupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__toupper") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll__ui64toa(ULONGLONG  value, char*  str, int  radix) /* ../dlls/ntdll/string.c:659 */
{
	char* return_value;
	TRACE("Enter _ui64toa\n");
	return_value = p_ui64toa(value, str, radix);
	TRACE("Leave _ui64toa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ui64toa(void);  /* ../dlls/ntdll/string.c:659 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ui64toa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ui64toa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__ui64tow(ULONGLONG  value, LPWSTR  str, INT  radix) /* ../dlls/ntdll/wcstring.c:528 */
{
	LPWSTR return_value;
	TRACE("Enter _ui64tow\n");
	return_value = p_ui64tow(value, str, radix);
	TRACE("Leave _ui64tow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ui64tow(void);  /* ../dlls/ntdll/wcstring.c:528 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ui64tow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ui64tow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll__ultoa(ULONG  value, char*  str, int  radix) /* ../dlls/ntdll/string.c:538 */
{
	char* return_value;
	TRACE("Enter _ultoa\n");
	return_value = p_ultoa(value, str, radix);
	TRACE("Leave _ultoa\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ultoa(void);  /* ../dlls/ntdll/string.c:538 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ultoa,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ultoa") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__ultow(ULONG  value, LPWSTR  str, INT  radix) /* ../dlls/ntdll/wcstring.c:394 */
{
	LPWSTR return_value;
	TRACE("Enter _ultow\n");
	return_value = p_ultow(value, str, radix);
	TRACE("Leave _ultow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__ultow(void);  /* ../dlls/ntdll/wcstring.c:394 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__ultow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__ultow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__vsnprintf(char*  str, SIZE_T  len, char*  format, __builtin_ms_va_list  args) /* ../dlls/ntdll/printf.c:693 */
{
	int return_value;
	TRACE("Enter _vsnprintf\n");
	return_value = p_vsnprintf(str, len, format, args);
	TRACE("Leave _vsnprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__vsnprintf(void);  /* ../dlls/ntdll/printf.c:693 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__vsnprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__vsnprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__vsnprintf_s(char*  str, SIZE_T  size, SIZE_T  len, char*  format, __builtin_ms_va_list  args) /* ../dlls/ntdll/printf.c:770 */
{
	int return_value;
	TRACE("Enter _vsnprintf_s\n");
	return_value = p_vsnprintf_s(str, size, len, format, args);
	TRACE("Leave _vsnprintf_s\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__vsnprintf_s(void);  /* ../dlls/ntdll/printf.c:770 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__vsnprintf_s,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__vsnprintf_s") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__vsnwprintf(WCHAR*  str, SIZE_T  len, WCHAR*  format, __builtin_ms_va_list  args) /* ../dlls/ntdll/printf.c:721 */
{
	int return_value;
	TRACE("Enter _vsnwprintf\n");
	return_value = p_vsnwprintf(str, len, format, args);
	TRACE("Leave _vsnwprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__vsnwprintf(void);  /* ../dlls/ntdll/printf.c:721 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__vsnwprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__vsnwprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll__wcsicmp(LPCWSTR  str1, LPCWSTR  str2) /* ../dlls/ntdll/wcstring.c:39 */
{
	INT return_value;
	TRACE("Enter _wcsicmp\n");
	return_value = p_wcsicmp(str1, str2);
	TRACE("Leave _wcsicmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wcsicmp(void);  /* ../dlls/ntdll/wcstring.c:39 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wcsicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wcsicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__wcslwr(LPWSTR  str) /* ../dlls/ntdll/wcstring.c:48 */
{
	LPWSTR return_value;
	TRACE("Enter _wcslwr\n");
	return_value = p_wcslwr(str);
	TRACE("Leave _wcslwr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wcslwr(void);  /* ../dlls/ntdll/wcstring.c:48 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wcslwr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wcslwr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll__wcsnicmp(LPCWSTR  str1, LPCWSTR  str2, INT  n) /* ../dlls/ntdll/wcstring.c:57 */
{
	INT return_value;
	TRACE("Enter _wcsnicmp\n");
	return_value = p_wcsnicmp(str1, str2, n);
	TRACE("Leave _wcsnicmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wcsnicmp(void);  /* ../dlls/ntdll/wcstring.c:57 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wcsnicmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wcsnicmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll__wcsupr(LPWSTR  str) /* ../dlls/ntdll/wcstring.c:66 */
{
	LPWSTR return_value;
	TRACE("Enter _wcsupr\n");
	return_value = p_wcsupr(str);
	TRACE("Leave _wcsupr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wcsupr(void);  /* ../dlls/ntdll/wcstring.c:66 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wcsupr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wcsupr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll__wtoi(LPCWSTR  str) /* ../dlls/ntdll/wcstring.c:681 */
{
	int return_value;
	TRACE("Enter _wtoi\n");
	return_value = p_wtoi(str);
	TRACE("Leave _wtoi\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wtoi(void);  /* ../dlls/ntdll/wcstring.c:681 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wtoi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wtoi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONGLONG wine32b_ntdll__wtoi64(LPCWSTR  str) /* ../dlls/ntdll/wcstring.c:703 */
{
	LONGLONG return_value;
	TRACE("Enter _wtoi64\n");
	return_value = p_wtoi64(str);
	TRACE("Leave _wtoi64\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wtoi64(void);  /* ../dlls/ntdll/wcstring.c:703 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wtoi64,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wtoi64") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll__wtol(LPCWSTR  str) /* ../dlls/ntdll/wcstring.c:640 */
{
	LONG return_value;
	TRACE("Enter _wtol\n");
	return_value = p_wtol(str);
	TRACE("Leave _wtol\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll__wtol(void);  /* ../dlls/ntdll/wcstring.c:640 */
__ASM_GLOBAL_FUNC(wine32a_ntdll__wtol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll__wtol") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_abs(int  i) /* ../dlls/ntdll/misc.c:96 */
{
	int return_value;
	TRACE("Enter abs\n");
	return_value = pabs(i);
	TRACE("Leave abs\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_abs(void);  /* ../dlls/ntdll/misc.c:96 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_abs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_abs") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_atan(double  d) /* ../dlls/ntdll/misc.c:112 */
{
	double return_value;
	TRACE("Enter atan\n");
	return_value = patan(d);
	TRACE("Leave atan\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_atan(void);  /* ../dlls/ntdll/misc.c:112 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_atan,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_atan") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_atoi(char*  nptr) /* ../dlls/ntdll/string.c:797 */
{
	int return_value;
	TRACE("Enter atoi\n");
	return_value = patoi(nptr);
	TRACE("Leave atoi\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_atoi(void);  /* ../dlls/ntdll/string.c:797 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_atoi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_atoi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_atol(char*  nptr) /* ../dlls/ntdll/string.c:806 */
{
	LONG return_value;
	TRACE("Enter atol\n");
	return_value = patol(nptr);
	TRACE("Leave atol\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_atol(void);  /* ../dlls/ntdll/string.c:806 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_atol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_atol") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_bsearch(void*  key, void*  base, size_t  nmemb, size_t  size, int (* compar) (void)) /* ../dlls/ntdll/misc.c:300 */
{
	void* return_value;
	TRACE("Enter bsearch\n");
	return_value = pbsearch(key, base, nmemb, size, compar);
	TRACE("Leave bsearch\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_bsearch(void);  /* ../dlls/ntdll/misc.c:300 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_bsearch,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_bsearch") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_ceil(double  d) /* ../dlls/ntdll/misc.c:120 */
{
	double return_value;
	TRACE("Enter ceil\n");
	return_value = pceil(d);
	TRACE("Leave ceil\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_ceil(void);  /* ../dlls/ntdll/misc.c:120 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_ceil,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_ceil") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_cos(double  d) /* ../dlls/ntdll/misc.c:128 */
{
	double return_value;
	TRACE("Enter cos\n");
	return_value = pcos(d);
	TRACE("Leave cos\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_cos(void);  /* ../dlls/ntdll/misc.c:128 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_cos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_cos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_fabs(double  d) /* ../dlls/ntdll/misc.c:136 */
{
	double return_value;
	TRACE("Enter fabs\n");
	return_value = pfabs(d);
	TRACE("Leave fabs\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_fabs(void);  /* ../dlls/ntdll/misc.c:136 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_fabs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_fabs") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_floor(double  d) /* ../dlls/ntdll/misc.c:144 */
{
	double return_value;
	TRACE("Enter floor\n");
	return_value = pfloor(d);
	TRACE("Leave floor\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_floor(void);  /* ../dlls/ntdll/misc.c:144 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_floor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_floor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isalnum(int  c) /* ../dlls/ntdll/string.c:356 */
{
	int return_value;
	TRACE("Enter isalnum\n");
	return_value = pisalnum(c);
	TRACE("Leave isalnum\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isalnum(void);  /* ../dlls/ntdll/string.c:356 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isalnum,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isalnum") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isalpha(int  c) /* ../dlls/ntdll/string.c:365 */
{
	int return_value;
	TRACE("Enter isalpha\n");
	return_value = pisalpha(c);
	TRACE("Leave isalpha\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isalpha(void);  /* ../dlls/ntdll/string.c:365 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isalpha,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isalpha") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_iscntrl(int  c) /* ../dlls/ntdll/string.c:374 */
{
	int return_value;
	TRACE("Enter iscntrl\n");
	return_value = piscntrl(c);
	TRACE("Leave iscntrl\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iscntrl(void);  /* ../dlls/ntdll/string.c:374 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iscntrl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iscntrl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isdigit(int  c) /* ../dlls/ntdll/string.c:383 */
{
	int return_value;
	TRACE("Enter isdigit\n");
	return_value = pisdigit(c);
	TRACE("Leave isdigit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isdigit(void);  /* ../dlls/ntdll/string.c:383 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isdigit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isdigit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isgraph(int  c) /* ../dlls/ntdll/string.c:392 */
{
	int return_value;
	TRACE("Enter isgraph\n");
	return_value = pisgraph(c);
	TRACE("Leave isgraph\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isgraph(void);  /* ../dlls/ntdll/string.c:392 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isgraph,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isgraph") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_islower(int  c) /* ../dlls/ntdll/string.c:401 */
{
	int return_value;
	TRACE("Enter islower\n");
	return_value = pislower(c);
	TRACE("Leave islower\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_islower(void);  /* ../dlls/ntdll/string.c:401 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_islower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_islower") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isprint(int  c) /* ../dlls/ntdll/string.c:410 */
{
	int return_value;
	TRACE("Enter isprint\n");
	return_value = pisprint(c);
	TRACE("Leave isprint\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isprint(void);  /* ../dlls/ntdll/string.c:410 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isprint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isprint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_ispunct(int  c) /* ../dlls/ntdll/string.c:419 */
{
	int return_value;
	TRACE("Enter ispunct\n");
	return_value = pispunct(c);
	TRACE("Leave ispunct\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_ispunct(void);  /* ../dlls/ntdll/string.c:419 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_ispunct,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_ispunct") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isspace(int  c) /* ../dlls/ntdll/string.c:428 */
{
	int return_value;
	TRACE("Enter isspace\n");
	return_value = pisspace(c);
	TRACE("Leave isspace\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isspace(void);  /* ../dlls/ntdll/string.c:428 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isspace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isspace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isupper(int  c) /* ../dlls/ntdll/string.c:437 */
{
	int return_value;
	TRACE("Enter isupper\n");
	return_value = pisupper(c);
	TRACE("Leave isupper\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isupper(void);  /* ../dlls/ntdll/string.c:437 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isupper") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswalpha(WCHAR  wc) /* ../dlls/ntdll/wcstring.c:314 */
{
	INT return_value;
	TRACE("Enter iswalpha\n");
	return_value = piswalpha(wc);
	TRACE("Leave iswalpha\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswalpha(void);  /* ../dlls/ntdll/wcstring.c:314 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswalpha,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswalpha") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswctype(WCHAR  wc, WCHAR  wct) /* ../dlls/ntdll/wcstring.c:299 */
{
	INT return_value;
	TRACE("Enter iswctype\n");
	return_value = piswctype(wc, wct);
	TRACE("Leave iswctype\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswctype(void);  /* ../dlls/ntdll/wcstring.c:299 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswctype,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswctype") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswdigit(WCHAR  wc) /* ../dlls/ntdll/wcstring.c:329 */
{
	INT return_value;
	TRACE("Enter iswdigit\n");
	return_value = piswdigit(wc);
	TRACE("Leave iswdigit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswdigit(void);  /* ../dlls/ntdll/wcstring.c:329 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswdigit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswdigit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswlower(WCHAR  wc) /* ../dlls/ntdll/wcstring.c:344 */
{
	INT return_value;
	TRACE("Enter iswlower\n");
	return_value = piswlower(wc);
	TRACE("Leave iswlower\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswlower(void);  /* ../dlls/ntdll/wcstring.c:344 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswlower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswlower") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswspace(WCHAR  wc) /* ../dlls/ntdll/wcstring.c:359 */
{
	INT return_value;
	TRACE("Enter iswspace\n");
	return_value = piswspace(wc);
	TRACE("Leave iswspace\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswspace(void);  /* ../dlls/ntdll/wcstring.c:359 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswspace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswspace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_iswxdigit(WCHAR  wc) /* ../dlls/ntdll/wcstring.c:374 */
{
	INT return_value;
	TRACE("Enter iswxdigit\n");
	return_value = piswxdigit(wc);
	TRACE("Leave iswxdigit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_iswxdigit(void);  /* ../dlls/ntdll/wcstring.c:374 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_iswxdigit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_iswxdigit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_isxdigit(int  c) /* ../dlls/ntdll/string.c:446 */
{
	int return_value;
	TRACE("Enter isxdigit\n");
	return_value = pisxdigit(c);
	TRACE("Leave isxdigit\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_isxdigit(void);  /* ../dlls/ntdll/string.c:446 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_isxdigit,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_isxdigit") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_labs(LONG  i) /* ../dlls/ntdll/misc.c:104 */
{
	LONG return_value;
	TRACE("Enter labs\n");
	return_value = plabs(i);
	TRACE("Leave labs\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_labs(void);  /* ../dlls/ntdll/misc.c:104 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_labs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_labs") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_log(double  d) /* ../dlls/ntdll/misc.c:152 */
{
	double return_value;
	TRACE("Enter log\n");
	return_value = plog(d);
	TRACE("Leave log\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_log(void);  /* ../dlls/ntdll/misc.c:152 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_log,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_log") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_mbstowcs(LPWSTR  dst, LPCSTR  src, INT  n) /* ../dlls/ntdll/wcstring.c:260 */
{
	INT return_value;
	TRACE("Enter mbstowcs\n");
	return_value = pmbstowcs(dst, src, n);
	TRACE("Leave mbstowcs\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_mbstowcs(void);  /* ../dlls/ntdll/wcstring.c:260 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_mbstowcs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_mbstowcs") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_memchr(void*  ptr, int  c, size_t  n) /* ../dlls/ntdll/string.c:40 */
{
	void* return_value;
	TRACE("Enter memchr\n");
	return_value = pmemchr(ptr, c, n);
	TRACE("Leave memchr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_memchr(void);  /* ../dlls/ntdll/string.c:40 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_memchr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_memchr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_memcmp(void*  ptr1, void*  ptr2, size_t  n) /* ../dlls/ntdll/string.c:49 */
{
	int return_value;
	TRACE("Enter memcmp\n");
	return_value = pmemcmp(ptr1, ptr2, n);
	TRACE("Leave memcmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_memcmp(void);  /* ../dlls/ntdll/string.c:49 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_memcmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_memcmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_memcpy(void*  dst, void*  src, size_t  n) /* ../dlls/ntdll/string.c:61 */
{
	void* return_value;
	TRACE("Enter memcpy\n");
	return_value = pmemcpy(dst, src, n);
	TRACE("Leave memcpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_memcpy(void);  /* ../dlls/ntdll/string.c:61 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_memcpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_memcpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_memmove(void*  dst, void*  src, size_t  n) /* ../dlls/ntdll/string.c:70 */
{
	void* return_value;
	TRACE("Enter memmove\n");
	return_value = pmemmove(dst, src, n);
	TRACE("Leave memmove\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_memmove(void);  /* ../dlls/ntdll/string.c:70 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_memmove,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_memmove") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void* wine32b_ntdll_memset(void*  dst, int  c, size_t  n) /* ../dlls/ntdll/string.c:79 */
{
	void* return_value;
	TRACE("Enter memset\n");
	return_value = pmemset(dst, c, n);
	TRACE("Leave memset\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_memset(void);  /* ../dlls/ntdll/string.c:79 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_memset,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_memset") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_pow(double  x, double  y) /* ../dlls/ntdll/misc.c:160 */
{
	double return_value;
	TRACE("Enter pow\n");
	return_value = ppow(x, y);
	TRACE("Leave pow\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_pow(void);  /* ../dlls/ntdll/misc.c:160 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_pow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_pow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_qsort(void*  base, size_t  nmemb, size_t  size, int (* compar) (void)) /* ../dlls/ntdll/misc.c:286 */
{
	TRACE("Enter qsort\n");
	pqsort(base, nmemb, size, compar);
	TRACE("Leave qsort\n");
}

extern WINAPI void wine32a_ntdll_qsort(void);  /* ../dlls/ntdll/misc.c:286 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_qsort,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_qsort") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_sin(double  d) /* ../dlls/ntdll/misc.c:168 */
{
	double return_value;
	TRACE("Enter sin\n");
	return_value = psin(d);
	TRACE("Leave sin\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_sin(void);  /* ../dlls/ntdll/misc.c:168 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_sin,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_sin") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_sprintf(char*  str, char*  format) /* ../dlls/ntdll/printf.c:824 */
{
	int return_value;
	TRACE("Enter sprintf\n");
	return_value = psprintf(str, format);
	TRACE("Leave sprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_sprintf(void);  /* ../dlls/ntdll/printf.c:824 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_sprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_sprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_sqrt(double  d) /* ../dlls/ntdll/misc.c:176 */
{
	double return_value;
	TRACE("Enter sqrt\n");
	return_value = psqrt(d);
	TRACE("Leave sqrt\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_sqrt(void);  /* ../dlls/ntdll/misc.c:176 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_sqrt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_sqrt") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_sscanf(char*  str, char*  format) /* ../dlls/ntdll/string.c:1400 */
{
	int return_value;
	TRACE("Enter sscanf\n");
	return_value = psscanf(str, format);
	TRACE("Leave sscanf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_sscanf(void);  /* ../dlls/ntdll/string.c:1400 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_sscanf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_sscanf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strcat(char*  dst, char*  src) /* ../dlls/ntdll/string.c:88 */
{
	char* return_value;
	TRACE("Enter strcat\n");
	return_value = pstrcat(dst, src);
	TRACE("Leave strcat\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strcat(void);  /* ../dlls/ntdll/string.c:88 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strcat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strcat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strchr(char*  str, int  c) /* ../dlls/ntdll/string.c:97 */
{
	char* return_value;
	TRACE("Enter strchr\n");
	return_value = pstrchr(str, c);
	TRACE("Leave strchr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strchr(void);  /* ../dlls/ntdll/string.c:97 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strchr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strchr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_strcmp(char*  str1, char*  str2) /* ../dlls/ntdll/string.c:106 */
{
	int return_value;
	TRACE("Enter strcmp\n");
	return_value = pstrcmp(str1, str2);
	TRACE("Leave strcmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strcmp(void);  /* ../dlls/ntdll/string.c:106 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strcmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strcmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strcpy(char*  dst, char*  src) /* ../dlls/ntdll/string.c:115 */
{
	char* return_value;
	TRACE("Enter strcpy\n");
	return_value = pstrcpy(dst, src);
	TRACE("Leave strcpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strcpy(void);  /* ../dlls/ntdll/string.c:115 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strcpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strcpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI size_t wine32b_ntdll_strcspn(char*  str, char*  reject) /* ../dlls/ntdll/string.c:124 */
{
	size_t return_value;
	TRACE("Enter strcspn\n");
	return_value = pstrcspn(str, reject);
	TRACE("Leave strcspn\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strcspn(void);  /* ../dlls/ntdll/string.c:124 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strcspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strcspn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI size_t wine32b_ntdll_strlen(char*  str) /* ../dlls/ntdll/string.c:133 */
{
	size_t return_value;
	TRACE("Enter strlen\n");
	return_value = pstrlen(str);
	TRACE("Leave strlen\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strlen(void);  /* ../dlls/ntdll/string.c:133 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strlen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strlen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strncat(char*  dst, char*  src, size_t  len) /* ../dlls/ntdll/string.c:142 */
{
	char* return_value;
	TRACE("Enter strncat\n");
	return_value = pstrncat(dst, src, len);
	TRACE("Leave strncat\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strncat(void);  /* ../dlls/ntdll/string.c:142 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strncat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strncat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_strncmp(char*  str1, char*  str2, size_t  len) /* ../dlls/ntdll/string.c:151 */
{
	int return_value;
	TRACE("Enter strncmp\n");
	return_value = pstrncmp(str1, str2, len);
	TRACE("Leave strncmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strncmp(void);  /* ../dlls/ntdll/string.c:151 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strncmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strncmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strncpy(char*  dst, char*  src, size_t  len) /* ../dlls/ntdll/string.c:160 */
{
	char* return_value;
	TRACE("Enter strncpy\n");
	return_value = pstrncpy(dst, src, len);
	TRACE("Leave strncpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strncpy(void);  /* ../dlls/ntdll/string.c:160 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strncpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strncpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI size_t wine32b_ntdll_strnlen(char*  str, size_t  len) /* ../dlls/ntdll/string.c:169 */
{
	size_t return_value;
	TRACE("Enter strnlen\n");
	return_value = pstrnlen(str, len);
	TRACE("Leave strnlen\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strnlen(void);  /* ../dlls/ntdll/string.c:169 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strnlen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strnlen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strpbrk(char*  str, char*  accept) /* ../dlls/ntdll/string.c:178 */
{
	char* return_value;
	TRACE("Enter strpbrk\n");
	return_value = pstrpbrk(str, accept);
	TRACE("Leave strpbrk\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strpbrk(void);  /* ../dlls/ntdll/string.c:178 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strpbrk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strpbrk") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strrchr(char*  str, int  c) /* ../dlls/ntdll/string.c:187 */
{
	char* return_value;
	TRACE("Enter strrchr\n");
	return_value = pstrrchr(str, c);
	TRACE("Leave strrchr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strrchr(void);  /* ../dlls/ntdll/string.c:187 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strrchr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strrchr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI size_t wine32b_ntdll_strspn(char*  str, char*  accept) /* ../dlls/ntdll/string.c:196 */
{
	size_t return_value;
	TRACE("Enter strspn\n");
	return_value = pstrspn(str, accept);
	TRACE("Leave strspn\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strspn(void);  /* ../dlls/ntdll/string.c:196 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strspn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_strstr(char*  haystack, char*  needle) /* ../dlls/ntdll/string.c:205 */
{
	char* return_value;
	TRACE("Enter strstr\n");
	return_value = pstrstr(haystack, needle);
	TRACE("Leave strstr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strstr(void);  /* ../dlls/ntdll/string.c:205 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strstr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strstr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_strtol(char*  nptr, char**  endptr, int  base) /* ../dlls/ntdll/string.c:509 */
{
	LONG return_value;
	TRACE("Enter strtol\n");
	return_value = pstrtol(nptr, endptr, base);
	TRACE("Leave strtol\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strtol(void);  /* ../dlls/ntdll/string.c:509 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strtol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strtol") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_strtoul(char*  nptr, char**  endptr, int  base) /* ../dlls/ntdll/string.c:518 */
{
	ULONG return_value;
	TRACE("Enter strtoul\n");
	return_value = pstrtoul(nptr, endptr, base);
	TRACE("Leave strtoul\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_strtoul(void);  /* ../dlls/ntdll/string.c:518 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_strtoul,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_strtoul") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_swprintf(WCHAR*  str, WCHAR*  format) /* ../dlls/ntdll/printf.c:839 */
{
	int return_value;
	TRACE("Enter swprintf\n");
	return_value = pswprintf(str, format);
	TRACE("Leave swprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_swprintf(void);  /* ../dlls/ntdll/printf.c:839 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_swprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_swprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI double wine32b_ntdll_tan(double  d) /* ../dlls/ntdll/misc.c:184 */
{
	double return_value;
	TRACE("Enter tan\n");
	return_value = ptan(d);
	TRACE("Leave tan\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_tan(void);  /* ../dlls/ntdll/misc.c:184 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_tan,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_tan") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_tolower(int  c) /* ../dlls/ntdll/string.c:223 */
{
	int return_value;
	TRACE("Enter tolower\n");
	return_value = ptolower(c);
	TRACE("Leave tolower\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_tolower(void);  /* ../dlls/ntdll/string.c:223 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_tolower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_tolower") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_toupper(int  c) /* ../dlls/ntdll/string.c:337 */
{
	int return_value;
	TRACE("Enter toupper\n");
	return_value = ptoupper(c);
	TRACE("Leave toupper\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_toupper(void);  /* ../dlls/ntdll/string.c:337 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_toupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_toupper") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI WCHAR wine32b_ntdll_towlower(WCHAR  ch) /* ../dlls/ntdll/wcstring.c:75 */
{
	WCHAR return_value;
	TRACE("Enter towlower\n");
	return_value = ptowlower(ch);
	TRACE("Leave towlower\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_towlower(void);  /* ../dlls/ntdll/wcstring.c:75 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_towlower,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_towlower") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI WCHAR wine32b_ntdll_towupper(WCHAR  ch) /* ../dlls/ntdll/wcstring.c:84 */
{
	WCHAR return_value;
	TRACE("Enter towupper\n");
	return_value = ptowupper(ch);
	TRACE("Leave towupper\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_towupper(void);  /* ../dlls/ntdll/wcstring.c:84 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_towupper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_towupper") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_vDbgPrintEx(ULONG  id, ULONG  level, LPCSTR  fmt, __builtin_ms_va_list  args) /* ../dlls/ntdll/rtl.c:335 */
{
	NTSTATUS return_value;
	TRACE("Enter vDbgPrintEx\n");
	return_value = pvDbgPrintEx(id, level, fmt, args);
	TRACE("Leave vDbgPrintEx\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_vDbgPrintEx(void);  /* ../dlls/ntdll/rtl.c:335 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_vDbgPrintEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_vDbgPrintEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_vDbgPrintExWithPrefix(LPCSTR  prefix, ULONG  id, ULONG  level, LPCSTR  fmt, __builtin_ms_va_list  args) /* ../dlls/ntdll/rtl.c:343 */
{
	NTSTATUS return_value;
	TRACE("Enter vDbgPrintExWithPrefix\n");
	return_value = pvDbgPrintExWithPrefix(prefix, id, level, fmt, args);
	TRACE("Leave vDbgPrintExWithPrefix\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_vDbgPrintExWithPrefix(void);  /* ../dlls/ntdll/rtl.c:343 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_vDbgPrintExWithPrefix,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_vDbgPrintExWithPrefix") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_vsprintf(char*  str, char*  format, __builtin_ms_va_list  args) /* ../dlls/ntdll/printf.c:815 */
{
	int return_value;
	TRACE("Enter vsprintf\n");
	return_value = pvsprintf(str, format, args);
	TRACE("Leave vsprintf\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_vsprintf(void);  /* ../dlls/ntdll/printf.c:815 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_vsprintf,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_vsprintf") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcscat(LPWSTR  dst, LPCWSTR  src) /* ../dlls/ntdll/wcstring.c:93 */
{
	LPWSTR return_value;
	TRACE("Enter wcscat\n");
	return_value = pwcscat(dst, src);
	TRACE("Leave wcscat\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcscat(void);  /* ../dlls/ntdll/wcstring.c:93 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcscat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcscat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcschr(LPCWSTR  str, WCHAR  ch) /* ../dlls/ntdll/wcstring.c:102 */
{
	LPWSTR return_value;
	TRACE("Enter wcschr\n");
	return_value = pwcschr(str, ch);
	TRACE("Leave wcschr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcschr(void);  /* ../dlls/ntdll/wcstring.c:102 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcschr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcschr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcscmp(LPCWSTR  str1, LPCWSTR  str2) /* ../dlls/ntdll/wcstring.c:111 */
{
	INT return_value;
	TRACE("Enter wcscmp\n");
	return_value = pwcscmp(str1, str2);
	TRACE("Leave wcscmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcscmp(void);  /* ../dlls/ntdll/wcstring.c:111 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcscmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcscmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcscpy(LPWSTR  dst, LPCWSTR  src) /* ../dlls/ntdll/wcstring.c:120 */
{
	LPWSTR return_value;
	TRACE("Enter wcscpy\n");
	return_value = pwcscpy(dst, src);
	TRACE("Leave wcscpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcscpy(void);  /* ../dlls/ntdll/wcstring.c:120 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcscpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcscpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcscspn(LPCWSTR  str, LPCWSTR  reject) /* ../dlls/ntdll/wcstring.c:129 */
{
	INT return_value;
	TRACE("Enter wcscspn\n");
	return_value = pwcscspn(str, reject);
	TRACE("Leave wcscspn\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcscspn(void);  /* ../dlls/ntdll/wcstring.c:129 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcscspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcscspn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcslen(LPCWSTR  str) /* ../dlls/ntdll/wcstring.c:138 */
{
	INT return_value;
	TRACE("Enter wcslen\n");
	return_value = pwcslen(str);
	TRACE("Leave wcslen\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcslen(void);  /* ../dlls/ntdll/wcstring.c:138 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcslen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcslen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcsncat(LPWSTR  s1, LPCWSTR  s2, INT  n) /* ../dlls/ntdll/wcstring.c:147 */
{
	LPWSTR return_value;
	TRACE("Enter wcsncat\n");
	return_value = pwcsncat(s1, s2, n);
	TRACE("Leave wcsncat\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsncat(void);  /* ../dlls/ntdll/wcstring.c:147 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsncat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsncat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcsncmp(LPCWSTR  str1, LPCWSTR  str2, INT  n) /* ../dlls/ntdll/wcstring.c:160 */
{
	INT return_value;
	TRACE("Enter wcsncmp\n");
	return_value = pwcsncmp(str1, str2, n);
	TRACE("Leave wcsncmp\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsncmp(void);  /* ../dlls/ntdll/wcstring.c:160 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsncmp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsncmp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcsncpy(LPWSTR  s1, LPCWSTR  s2, INT  n) /* ../dlls/ntdll/wcstring.c:169 */
{
	LPWSTR return_value;
	TRACE("Enter wcsncpy\n");
	return_value = pwcsncpy(s1, s2, n);
	TRACE("Leave wcsncpy\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsncpy(void);  /* ../dlls/ntdll/wcstring.c:169 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsncpy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsncpy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcspbrk(LPCWSTR  str, LPCWSTR  accept) /* ../dlls/ntdll/wcstring.c:181 */
{
	LPWSTR return_value;
	TRACE("Enter wcspbrk\n");
	return_value = pwcspbrk(str, accept);
	TRACE("Leave wcspbrk\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcspbrk(void);  /* ../dlls/ntdll/wcstring.c:181 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcspbrk,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcspbrk") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcsrchr(LPWSTR  str, WCHAR  ch) /* ../dlls/ntdll/wcstring.c:190 */
{
	LPWSTR return_value;
	TRACE("Enter wcsrchr\n");
	return_value = pwcsrchr(str, ch);
	TRACE("Leave wcsrchr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsrchr(void);  /* ../dlls/ntdll/wcstring.c:190 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsrchr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsrchr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcsspn(LPCWSTR  str, LPCWSTR  accept) /* ../dlls/ntdll/wcstring.c:199 */
{
	INT return_value;
	TRACE("Enter wcsspn\n");
	return_value = pwcsspn(str, accept);
	TRACE("Leave wcsspn\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsspn(void);  /* ../dlls/ntdll/wcstring.c:199 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsspn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsspn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcsstr(LPCWSTR  str, LPCWSTR  sub) /* ../dlls/ntdll/wcstring.c:208 */
{
	LPWSTR return_value;
	TRACE("Enter wcsstr\n");
	return_value = pwcsstr(str, sub);
	TRACE("Leave wcsstr\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcsstr(void);  /* ../dlls/ntdll/wcstring.c:208 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcsstr,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcsstr") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LPWSTR wine32b_ntdll_wcstok(LPWSTR  str, LPCWSTR  delim) /* ../dlls/ntdll/wcstring.c:217 */
{
	LPWSTR return_value;
	TRACE("Enter wcstok\n");
	return_value = pwcstok(str, delim);
	TRACE("Leave wcstok\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcstok(void);  /* ../dlls/ntdll/wcstring.c:217 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcstok,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcstok") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI LONG wine32b_ntdll_wcstol(LPCWSTR  s, LPWSTR*  end, INT  base) /* ../dlls/ntdll/wcstring.c:281 */
{
	LONG return_value;
	TRACE("Enter wcstol\n");
	return_value = pwcstol(s, end, base);
	TRACE("Leave wcstol\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcstol(void);  /* ../dlls/ntdll/wcstring.c:281 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcstol,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcstol") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI INT wine32b_ntdll_wcstombs(LPSTR  dst, LPCWSTR  src, INT  n) /* ../dlls/ntdll/wcstring.c:238 */
{
	INT return_value;
	TRACE("Enter wcstombs\n");
	return_value = pwcstombs(dst, src, n);
	TRACE("Leave wcstombs\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcstombs(void);  /* ../dlls/ntdll/wcstring.c:238 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcstombs,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcstombs") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ULONG wine32b_ntdll_wcstoul(LPCWSTR  s, LPWSTR*  end, INT  base) /* ../dlls/ntdll/wcstring.c:290 */
{
	ULONG return_value;
	TRACE("Enter wcstoul\n");
	return_value = pwcstoul(s, end, base);
	TRACE("Leave wcstoul\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wcstoul(void);  /* ../dlls/ntdll/wcstring.c:290 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wcstoul,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wcstoul") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI unsigned int wine32b_ntdll_wine_server_call(void*  req_ptr) /* ../dlls/ntdll/server.c:315 */
{
	unsigned int return_value;
	TRACE("Enter wine_server_call\n");
	return_value = pwine_server_call(req_ptr);
	TRACE("Leave wine_server_call\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_server_call(void);  /* ../dlls/ntdll/server.c:315 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_server_call,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_server_call") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_wine_server_fd_to_handle(int  fd, unsigned int  access, unsigned int  attributes, HANDLE*  handle) /* ../dlls/ntdll/server.c:1006 */
{
	int return_value;
	TRACE("Enter wine_server_fd_to_handle\n");
	return_value = pwine_server_fd_to_handle(fd, access, attributes, handle);
	TRACE("Leave wine_server_fd_to_handle\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_server_fd_to_handle(void);  /* ../dlls/ntdll/server.c:1006 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_server_fd_to_handle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_server_fd_to_handle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll_wine_server_handle_to_fd(HANDLE  handle, unsigned int  access, int*  unix_fd, unsigned int*  options) /* ../dlls/ntdll/server.c:1039 */
{
	int return_value;
	TRACE("Enter wine_server_handle_to_fd\n");
	return_value = pwine_server_handle_to_fd(handle, access, unix_fd, options);
	TRACE("Leave wine_server_handle_to_fd\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_server_handle_to_fd(void);  /* ../dlls/ntdll/server.c:1039 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_server_handle_to_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_server_handle_to_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_wine_server_release_fd(HANDLE  handle, int  unix_fd) /* ../dlls/ntdll/server.c:1064 */
{
	TRACE("Enter wine_server_release_fd\n");
	pwine_server_release_fd(handle, unix_fd);
	TRACE("Leave wine_server_release_fd\n");
}

extern WINAPI void wine32a_ntdll_wine_server_release_fd(void);  /* ../dlls/ntdll/server.c:1064 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_server_release_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_server_release_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll_wine_server_send_fd(int  fd) /* ../dlls/ntdll/server.c:710 */
{
	TRACE("Enter wine_server_send_fd\n");
	pwine_server_send_fd(fd);
	TRACE("Leave wine_server_send_fd\n");
}

extern WINAPI void wine32a_ntdll_wine_server_send_fd(void);  /* ../dlls/ntdll/server.c:710 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_server_send_fd,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_server_send_fd") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI HANDLE wine32b_ntdll___wine_make_process_system(void) /* ../dlls/ntdll/process.c:110 */
{
	HANDLE return_value;
	TRACE("Enter __wine_make_process_system\n");
	return_value = p__wine_make_process_system();
	TRACE("Leave __wine_make_process_system\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_make_process_system(void);  /* ../dlls/ntdll/process.c:110 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_make_process_system,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_make_process_system") "\n"
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

WINAPI unsigned char wine32b_ntdll___wine_dbg_get_channel_flags(struct __wine_debug_channel*  channel) /* ../dlls/ntdll/debugtools.c:194 */
{
	unsigned char return_value;
	TRACE("Enter __wine_dbg_get_channel_flags\n");
	return_value = p__wine_dbg_get_channel_flags(channel);
	TRACE("Leave __wine_dbg_get_channel_flags\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_dbg_get_channel_flags(void);  /* ../dlls/ntdll/debugtools.c:194 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_dbg_get_channel_flags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_dbg_get_channel_flags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___wine_dbg_header(enum __wine_debug_class  cls, struct __wine_debug_channel*  channel, char*  function) /* ../dlls/ntdll/debugtools.c:253 */
{
	int return_value;
	TRACE("Enter __wine_dbg_header\n");
	return_value = p__wine_dbg_header(cls, channel, function);
	TRACE("Leave __wine_dbg_header\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_dbg_header(void);  /* ../dlls/ntdll/debugtools.c:253 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_dbg_header,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_dbg_header") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___wine_dbg_output(char*  str) /* ../dlls/ntdll/debugtools.c:233 */
{
	int return_value;
	TRACE("Enter __wine_dbg_output\n");
	return_value = p__wine_dbg_output(str);
	TRACE("Leave __wine_dbg_output\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_dbg_output(void);  /* ../dlls/ntdll/debugtools.c:233 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_dbg_output,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_dbg_output") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll___wine_dbg_strdup(char*  str) /* ../dlls/ntdll/debugtools.c:218 */
{
	char* return_value;
	TRACE("Enter __wine_dbg_strdup\n");
	return_value = p__wine_dbg_strdup(str);
	TRACE("Leave __wine_dbg_strdup\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_dbg_strdup(void);  /* ../dlls/ntdll/debugtools.c:218 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_dbg_strdup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_dbg_strdup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI ssize_t wine32b_ntdll___wine_locked_recvmsg(int  fd, struct msghdr*  hdr, int  flags) /* ../dlls/ntdll/virtual.c:2223 */
{
	ssize_t return_value;
	TRACE("Enter __wine_locked_recvmsg\n");
	return_value = p__wine_locked_recvmsg(fd, hdr, flags);
	TRACE("Leave __wine_locked_recvmsg\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_locked_recvmsg(void);  /* ../dlls/ntdll/virtual.c:2223 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_locked_recvmsg,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_locked_recvmsg") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI char* wine32b_ntdll_wine_get_version(void) /* ../dlls/ntdll/misc.c:58 */
{
	char* return_value;
	TRACE("Enter wine_get_version\n");
	return_value = pwine_get_version();
	TRACE("Leave wine_get_version\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_get_version(void);  /* ../dlls/ntdll/misc.c:58 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_get_version,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_get_version") "\n"
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

WINAPI char* wine32b_ntdll_wine_get_build_id(void) /* ../dlls/ntdll/misc.c:66 */
{
	char* return_value;
	TRACE("Enter wine_get_build_id\n");
	return_value = pwine_get_build_id();
	TRACE("Leave wine_get_build_id\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_get_build_id(void);  /* ../dlls/ntdll/misc.c:66 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_get_build_id,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_get_build_id") "\n"
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

WINAPI void wine32b_ntdll_wine_get_host_version(char**  sysname, char**  release) /* ../dlls/ntdll/misc.c:74 */
{
	TRACE("Enter wine_get_host_version\n");
	pwine_get_host_version(sysname, release);
	TRACE("Leave wine_get_host_version\n");
}

extern WINAPI void wine32a_ntdll_wine_get_host_version(void);  /* ../dlls/ntdll/misc.c:74 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_get_host_version,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_get_host_version") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI void wine32b_ntdll___wine_init_codepages(union cptable*  ansi, union cptable*  oem, union cptable*  ucp) /* ../dlls/ntdll/rtlstr.c:59 */
{
	TRACE("Enter __wine_init_codepages\n");
	p__wine_init_codepages(ansi, oem, ucp);
	TRACE("Leave __wine_init_codepages\n");
}

extern WINAPI void wine32a_ntdll___wine_init_codepages(void);  /* ../dlls/ntdll/rtlstr.c:59 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_init_codepages,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_init_codepages") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI int wine32b_ntdll___wine_set_signal_handler(unsigned int  sig, wine_signal_handler  wsh) /* ../dlls/ntdll/signal_x86_64.c:3151 */
{
	int return_value;
	TRACE("Enter __wine_set_signal_handler\n");
	return_value = p__wine_set_signal_handler(sig, wsh);
	TRACE("Leave __wine_set_signal_handler\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll___wine_set_signal_handler(void);  /* ../dlls/ntdll/signal_x86_64.c:3151 */
__ASM_GLOBAL_FUNC(wine32a_ntdll___wine_set_signal_handler,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll___wine_set_signal_handler") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_wine_nt_to_unix_file_name(UNICODE_STRING*  nameW, ANSI_STRING*  unix_name_ret, UINT  disposition, BOOLEAN  check_case) /* ../dlls/ntdll/directory.c:2756 */
{
	NTSTATUS return_value;
	TRACE("Enter wine_nt_to_unix_file_name\n");
	return_value = pwine_nt_to_unix_file_name(nameW, unix_name_ret, disposition, check_case);
	TRACE("Leave wine_nt_to_unix_file_name\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_nt_to_unix_file_name(void);  /* ../dlls/ntdll/directory.c:2756 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_nt_to_unix_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_nt_to_unix_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

WINAPI NTSTATUS wine32b_ntdll_wine_unix_to_nt_file_name(ANSI_STRING*  name, UNICODE_STRING*  nt) /* ../dlls/ntdll/path.c:1075 */
{
	NTSTATUS return_value;
	TRACE("Enter wine_unix_to_nt_file_name\n");
	return_value = pwine_unix_to_nt_file_name(name, nt);
	TRACE("Leave wine_unix_to_nt_file_name\n");
	return return_value;
}

extern WINAPI void wine32a_ntdll_wine_unix_to_nt_file_name(void);  /* ../dlls/ntdll/path.c:1075 */
__ASM_GLOBAL_FUNC(wine32a_ntdll_wine_unix_to_nt_file_name,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_ntdll_wine_unix_to_nt_file_name") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
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

void wine_thunk_initialize_ntdll(void)
{
	HMODULE library = GetModuleHandleA("ntdll.dll");
	pA_SHAFinal = (void *)GetProcAddress(library, "A_SHAFinal");
	pA_SHAInit = (void *)GetProcAddress(library, "A_SHAInit");
	pA_SHAUpdate = (void *)GetProcAddress(library, "A_SHAUpdate");
	pApiSetQueryApiSetPresence = (void *)GetProcAddress(library, "ApiSetQueryApiSetPresence");
	pDbgPrint = (void *)GetProcAddress(library, "DbgPrint");
	pDbgPrintEx = (void *)GetProcAddress(library, "DbgPrintEx");
	pDbgUiIssueRemoteBreakin = (void *)GetProcAddress(library, "DbgUiIssueRemoteBreakin");
	pDbgUiRemoteBreakin = (void *)GetProcAddress(library, "DbgUiRemoteBreakin");
	pEtwEventActivityIdControl = (void *)GetProcAddress(library, "EtwEventActivityIdControl");
	pEtwEventEnabled = (void *)GetProcAddress(library, "EtwEventEnabled");
	pEtwEventProviderEnabled = (void *)GetProcAddress(library, "EtwEventProviderEnabled");
	pEtwEventRegister = (void *)GetProcAddress(library, "EtwEventRegister");
	pEtwEventSetInformation = (void *)GetProcAddress(library, "EtwEventSetInformation");
	pEtwEventUnregister = (void *)GetProcAddress(library, "EtwEventUnregister");
	pEtwEventWrite = (void *)GetProcAddress(library, "EtwEventWrite");
	pEtwEventWriteString = (void *)GetProcAddress(library, "EtwEventWriteString");
	pEtwEventWriteTransfer = (void *)GetProcAddress(library, "EtwEventWriteTransfer");
	pEtwGetTraceEnableFlags = (void *)GetProcAddress(library, "EtwGetTraceEnableFlags");
	pEtwGetTraceEnableLevel = (void *)GetProcAddress(library, "EtwGetTraceEnableLevel");
	pEtwGetTraceLoggerHandle = (void *)GetProcAddress(library, "EtwGetTraceLoggerHandle");
	pEtwLogTraceEvent = (void *)GetProcAddress(library, "EtwLogTraceEvent");
	pEtwRegisterTraceGuidsA = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsA");
	pEtwRegisterTraceGuidsW = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsW");
	pEtwTraceMessage = (void *)GetProcAddress(library, "EtwTraceMessage");
	pEtwTraceMessageVa = (void *)GetProcAddress(library, "EtwTraceMessageVa");
	pEtwUnregisterTraceGuids = (void *)GetProcAddress(library, "EtwUnregisterTraceGuids");
	pLdrAccessResource = (void *)GetProcAddress(library, "LdrAccessResource");
	pLdrAddRefDll = (void *)GetProcAddress(library, "LdrAddRefDll");
	pLdrDisableThreadCalloutsForDll = (void *)GetProcAddress(library, "LdrDisableThreadCalloutsForDll");
	pLdrEnumerateLoadedModules = (void *)GetProcAddress(library, "LdrEnumerateLoadedModules");
	pLdrFindEntryForAddress = (void *)GetProcAddress(library, "LdrFindEntryForAddress");
	pLdrFindResourceDirectory_U = (void *)GetProcAddress(library, "LdrFindResourceDirectory_U");
	pLdrFindResource_U = (void *)GetProcAddress(library, "LdrFindResource_U");
	pLdrGetDllHandle = (void *)GetProcAddress(library, "LdrGetDllHandle");
	pLdrGetProcedureAddress = (void *)GetProcAddress(library, "LdrGetProcedureAddress");
	pLdrInitializeThunk = (void *)GetProcAddress(library, "LdrInitializeThunk");
	pLdrLoadDll = (void *)GetProcAddress(library, "LdrLoadDll");
	pLdrLockLoaderLock = (void *)GetProcAddress(library, "LdrLockLoaderLock");
	pLdrProcessRelocationBlock = (void *)GetProcAddress(library, "LdrProcessRelocationBlock");
	pLdrQueryImageFileExecutionOptions = (void *)GetProcAddress(library, "LdrQueryImageFileExecutionOptions");
	pLdrQueryProcessModuleInformation = (void *)GetProcAddress(library, "LdrQueryProcessModuleInformation");
	pLdrRegisterDllNotification = (void *)GetProcAddress(library, "LdrRegisterDllNotification");
	pLdrResolveDelayLoadedAPI = (void *)GetProcAddress(library, "LdrResolveDelayLoadedAPI");
	pLdrShutdownProcess = (void *)GetProcAddress(library, "LdrShutdownProcess");
	pLdrShutdownThread = (void *)GetProcAddress(library, "LdrShutdownThread");
	pLdrUnloadDll = (void *)GetProcAddress(library, "LdrUnloadDll");
	pLdrUnlockLoaderLock = (void *)GetProcAddress(library, "LdrUnlockLoaderLock");
	pLdrUnregisterDllNotification = (void *)GetProcAddress(library, "LdrUnregisterDllNotification");
	pMD4Final = (void *)GetProcAddress(library, "MD4Final");
	pMD4Init = (void *)GetProcAddress(library, "MD4Init");
	pMD4Update = (void *)GetProcAddress(library, "MD4Update");
	pMD5Final = (void *)GetProcAddress(library, "MD5Final");
	pMD5Init = (void *)GetProcAddress(library, "MD5Init");
	pMD5Update = (void *)GetProcAddress(library, "MD5Update");
	pNtAcceptConnectPort = (void *)GetProcAddress(library, "NtAcceptConnectPort");
	pNtAccessCheck = (void *)GetProcAddress(library, "NtAccessCheck");
	pNtAccessCheckAndAuditAlarm = (void *)GetProcAddress(library, "NtAccessCheckAndAuditAlarm");
	pNtAddAtom = (void *)GetProcAddress(library, "NtAddAtom");
	pNtAdjustGroupsToken = (void *)GetProcAddress(library, "NtAdjustGroupsToken");
	pNtAdjustPrivilegesToken = (void *)GetProcAddress(library, "NtAdjustPrivilegesToken");
	pNtAlertResumeThread = (void *)GetProcAddress(library, "NtAlertResumeThread");
	pNtAlertThread = (void *)GetProcAddress(library, "NtAlertThread");
	pNtAllocateLocallyUniqueId = (void *)GetProcAddress(library, "NtAllocateLocallyUniqueId");
	pNtAllocateUuids = (void *)GetProcAddress(library, "NtAllocateUuids");
	pNtAllocateVirtualMemory = (void *)GetProcAddress(library, "NtAllocateVirtualMemory");
	pNtAreMappedFilesTheSame = (void *)GetProcAddress(library, "NtAreMappedFilesTheSame");
	pNtAssignProcessToJobObject = (void *)GetProcAddress(library, "NtAssignProcessToJobObject");
	pNtCancelIoFile = (void *)GetProcAddress(library, "NtCancelIoFile");
	pNtCancelIoFileEx = (void *)GetProcAddress(library, "NtCancelIoFileEx");
	pNtCancelTimer = (void *)GetProcAddress(library, "NtCancelTimer");
	pNtClearEvent = (void *)GetProcAddress(library, "NtClearEvent");
	pNtClearPowerRequest = (void *)GetProcAddress(library, "NtClearPowerRequest");
	pNtClose = (void *)GetProcAddress(library, "NtClose");
	pNtCompleteConnectPort = (void *)GetProcAddress(library, "NtCompleteConnectPort");
	pNtConnectPort = (void *)GetProcAddress(library, "NtConnectPort");
	pNtCreateDirectoryObject = (void *)GetProcAddress(library, "NtCreateDirectoryObject");
	pNtCreateEvent = (void *)GetProcAddress(library, "NtCreateEvent");
	pNtCreateFile = (void *)GetProcAddress(library, "NtCreateFile");
	pNtCreateIoCompletion = (void *)GetProcAddress(library, "NtCreateIoCompletion");
	pNtCreateJobObject = (void *)GetProcAddress(library, "NtCreateJobObject");
	pNtCreateKey = (void *)GetProcAddress(library, "NtCreateKey");
	pNtCreateKeyTransacted = (void *)GetProcAddress(library, "NtCreateKeyTransacted");
	pNtCreateKeyedEvent = (void *)GetProcAddress(library, "NtCreateKeyedEvent");
	pNtCreateLowBoxToken = (void *)GetProcAddress(library, "NtCreateLowBoxToken");
	pNtCreateMailslotFile = (void *)GetProcAddress(library, "NtCreateMailslotFile");
	pNtCreateMutant = (void *)GetProcAddress(library, "NtCreateMutant");
	pNtCreateNamedPipeFile = (void *)GetProcAddress(library, "NtCreateNamedPipeFile");
	pNtCreatePagingFile = (void *)GetProcAddress(library, "NtCreatePagingFile");
	pNtCreatePort = (void *)GetProcAddress(library, "NtCreatePort");
	pNtCreatePowerRequest = (void *)GetProcAddress(library, "NtCreatePowerRequest");
	pNtCreateSection = (void *)GetProcAddress(library, "NtCreateSection");
	pNtCreateSemaphore = (void *)GetProcAddress(library, "NtCreateSemaphore");
	pNtCreateSymbolicLinkObject = (void *)GetProcAddress(library, "NtCreateSymbolicLinkObject");
	pNtCreateThreadEx = (void *)GetProcAddress(library, "NtCreateThreadEx");
	pNtCreateTimer = (void *)GetProcAddress(library, "NtCreateTimer");
	pNtDelayExecution = (void *)GetProcAddress(library, "NtDelayExecution");
	pNtDeleteAtom = (void *)GetProcAddress(library, "NtDeleteAtom");
	pNtDeleteFile = (void *)GetProcAddress(library, "NtDeleteFile");
	pNtDeleteKey = (void *)GetProcAddress(library, "NtDeleteKey");
	pNtDeleteValueKey = (void *)GetProcAddress(library, "NtDeleteValueKey");
	pNtDeviceIoControlFile = (void *)GetProcAddress(library, "NtDeviceIoControlFile");
	pNtDisplayString = (void *)GetProcAddress(library, "NtDisplayString");
	pNtDuplicateObject = (void *)GetProcAddress(library, "NtDuplicateObject");
	pNtDuplicateToken = (void *)GetProcAddress(library, "NtDuplicateToken");
	pNtEnumerateKey = (void *)GetProcAddress(library, "NtEnumerateKey");
	pNtEnumerateValueKey = (void *)GetProcAddress(library, "NtEnumerateValueKey");
	pNtFindAtom = (void *)GetProcAddress(library, "NtFindAtom");
	pNtFlushBuffersFile = (void *)GetProcAddress(library, "NtFlushBuffersFile");
	pNtFlushInstructionCache = (void *)GetProcAddress(library, "NtFlushInstructionCache");
	pNtFlushKey = (void *)GetProcAddress(library, "NtFlushKey");
	pNtFlushVirtualMemory = (void *)GetProcAddress(library, "NtFlushVirtualMemory");
	pNtFreeVirtualMemory = (void *)GetProcAddress(library, "NtFreeVirtualMemory");
	pNtFsControlFile = (void *)GetProcAddress(library, "NtFsControlFile");
	pNtGetContextThread = (void *)GetProcAddress(library, "NtGetContextThread");
	pNtGetCurrentProcessorNumber = (void *)GetProcAddress(library, "NtGetCurrentProcessorNumber");
	pNtGetTickCount = (void *)GetProcAddress(library, "NtGetTickCount");
	pNtGetWriteWatch = (void *)GetProcAddress(library, "NtGetWriteWatch");
	pNtImpersonateAnonymousToken = (void *)GetProcAddress(library, "NtImpersonateAnonymousToken");
	pNtInitiatePowerAction = (void *)GetProcAddress(library, "NtInitiatePowerAction");
	pNtIsProcessInJob = (void *)GetProcAddress(library, "NtIsProcessInJob");
	pNtListenPort = (void *)GetProcAddress(library, "NtListenPort");
	pNtLoadDriver = (void *)GetProcAddress(library, "NtLoadDriver");
	pNtLoadKey2 = (void *)GetProcAddress(library, "NtLoadKey2");
	pNtLoadKey = (void *)GetProcAddress(library, "NtLoadKey");
	pNtLockFile = (void *)GetProcAddress(library, "NtLockFile");
	pNtLockVirtualMemory = (void *)GetProcAddress(library, "NtLockVirtualMemory");
	pNtMakeTemporaryObject = (void *)GetProcAddress(library, "NtMakeTemporaryObject");
	pNtMapViewOfSection = (void *)GetProcAddress(library, "NtMapViewOfSection");
	pNtNotifyChangeDirectoryFile = (void *)GetProcAddress(library, "NtNotifyChangeDirectoryFile");
	pNtNotifyChangeKey = (void *)GetProcAddress(library, "NtNotifyChangeKey");
	pNtNotifyChangeMultipleKeys = (void *)GetProcAddress(library, "NtNotifyChangeMultipleKeys");
	pNtOpenDirectoryObject = (void *)GetProcAddress(library, "NtOpenDirectoryObject");
	pNtOpenEvent = (void *)GetProcAddress(library, "NtOpenEvent");
	pNtOpenFile = (void *)GetProcAddress(library, "NtOpenFile");
	pNtOpenIoCompletion = (void *)GetProcAddress(library, "NtOpenIoCompletion");
	pNtOpenJobObject = (void *)GetProcAddress(library, "NtOpenJobObject");
	pNtOpenKey = (void *)GetProcAddress(library, "NtOpenKey");
	pNtOpenKeyEx = (void *)GetProcAddress(library, "NtOpenKeyEx");
	pNtOpenKeyTransacted = (void *)GetProcAddress(library, "NtOpenKeyTransacted");
	pNtOpenKeyTransactedEx = (void *)GetProcAddress(library, "NtOpenKeyTransactedEx");
	pNtOpenKeyedEvent = (void *)GetProcAddress(library, "NtOpenKeyedEvent");
	pNtOpenMutant = (void *)GetProcAddress(library, "NtOpenMutant");
	pNtOpenProcess = (void *)GetProcAddress(library, "NtOpenProcess");
	pNtOpenProcessToken = (void *)GetProcAddress(library, "NtOpenProcessToken");
	pNtOpenProcessTokenEx = (void *)GetProcAddress(library, "NtOpenProcessTokenEx");
	pNtOpenSection = (void *)GetProcAddress(library, "NtOpenSection");
	pNtOpenSemaphore = (void *)GetProcAddress(library, "NtOpenSemaphore");
	pNtOpenSymbolicLinkObject = (void *)GetProcAddress(library, "NtOpenSymbolicLinkObject");
	pNtOpenThread = (void *)GetProcAddress(library, "NtOpenThread");
	pNtOpenThreadToken = (void *)GetProcAddress(library, "NtOpenThreadToken");
	pNtOpenThreadTokenEx = (void *)GetProcAddress(library, "NtOpenThreadTokenEx");
	pNtOpenTimer = (void *)GetProcAddress(library, "NtOpenTimer");
	pNtPowerInformation = (void *)GetProcAddress(library, "NtPowerInformation");
	pNtPrivilegeCheck = (void *)GetProcAddress(library, "NtPrivilegeCheck");
	pNtProtectVirtualMemory = (void *)GetProcAddress(library, "NtProtectVirtualMemory");
	pNtPulseEvent = (void *)GetProcAddress(library, "NtPulseEvent");
	pNtQueryAttributesFile = (void *)GetProcAddress(library, "NtQueryAttributesFile");
	pNtQueryDefaultLocale = (void *)GetProcAddress(library, "NtQueryDefaultLocale");
	pNtQueryDefaultUILanguage = (void *)GetProcAddress(library, "NtQueryDefaultUILanguage");
	pNtQueryDirectoryFile = (void *)GetProcAddress(library, "NtQueryDirectoryFile");
	pNtQueryDirectoryObject = (void *)GetProcAddress(library, "NtQueryDirectoryObject");
	pNtQueryEaFile = (void *)GetProcAddress(library, "NtQueryEaFile");
	pNtQueryEvent = (void *)GetProcAddress(library, "NtQueryEvent");
	pNtQueryFullAttributesFile = (void *)GetProcAddress(library, "NtQueryFullAttributesFile");
	pNtQueryInformationAtom = (void *)GetProcAddress(library, "NtQueryInformationAtom");
	pNtQueryInformationFile = (void *)GetProcAddress(library, "NtQueryInformationFile");
	pNtQueryInformationJobObject = (void *)GetProcAddress(library, "NtQueryInformationJobObject");
	pNtQueryInformationProcess = (void *)GetProcAddress(library, "NtQueryInformationProcess");
	pNtQueryInformationThread = (void *)GetProcAddress(library, "NtQueryInformationThread");
	pNtQueryInformationToken = (void *)GetProcAddress(library, "NtQueryInformationToken");
	pNtQueryInstallUILanguage = (void *)GetProcAddress(library, "NtQueryInstallUILanguage");
	pNtQueryIoCompletion = (void *)GetProcAddress(library, "NtQueryIoCompletion");
	pNtQueryKey = (void *)GetProcAddress(library, "NtQueryKey");
	pNtQueryLicenseValue = (void *)GetProcAddress(library, "NtQueryLicenseValue");
	pNtQueryMultipleValueKey = (void *)GetProcAddress(library, "NtQueryMultipleValueKey");
	pNtQueryMutant = (void *)GetProcAddress(library, "NtQueryMutant");
	pNtQueryObject = (void *)GetProcAddress(library, "NtQueryObject");
	pNtQueryPerformanceCounter = (void *)GetProcAddress(library, "NtQueryPerformanceCounter");
	pNtQuerySection = (void *)GetProcAddress(library, "NtQuerySection");
	pNtQuerySecurityObject = (void *)GetProcAddress(library, "NtQuerySecurityObject");
	pNtQuerySemaphore = (void *)GetProcAddress(library, "NtQuerySemaphore");
	pNtQuerySymbolicLinkObject = (void *)GetProcAddress(library, "NtQuerySymbolicLinkObject");
	pNtQuerySystemEnvironmentValue = (void *)GetProcAddress(library, "NtQuerySystemEnvironmentValue");
	pNtQuerySystemEnvironmentValueEx = (void *)GetProcAddress(library, "NtQuerySystemEnvironmentValueEx");
	pNtQuerySystemInformation = (void *)GetProcAddress(library, "NtQuerySystemInformation");
	pNtQuerySystemInformationEx = (void *)GetProcAddress(library, "NtQuerySystemInformationEx");
	pNtQuerySystemTime = (void *)GetProcAddress(library, "NtQuerySystemTime");
	pNtQueryTimer = (void *)GetProcAddress(library, "NtQueryTimer");
	pNtQueryTimerResolution = (void *)GetProcAddress(library, "NtQueryTimerResolution");
	pNtQueryValueKey = (void *)GetProcAddress(library, "NtQueryValueKey");
	pNtQueryVirtualMemory = (void *)GetProcAddress(library, "NtQueryVirtualMemory");
	pNtQueryVolumeInformationFile = (void *)GetProcAddress(library, "NtQueryVolumeInformationFile");
	pNtQueueApcThread = (void *)GetProcAddress(library, "NtQueueApcThread");
	pNtRaiseException = (void *)GetProcAddress(library, "NtRaiseException");
	pNtRaiseHardError = (void *)GetProcAddress(library, "NtRaiseHardError");
	pNtReadFile = (void *)GetProcAddress(library, "NtReadFile");
	pNtReadFileScatter = (void *)GetProcAddress(library, "NtReadFileScatter");
	pNtReadVirtualMemory = (void *)GetProcAddress(library, "NtReadVirtualMemory");
	pNtRegisterThreadTerminatePort = (void *)GetProcAddress(library, "NtRegisterThreadTerminatePort");
	pNtReleaseKeyedEvent = (void *)GetProcAddress(library, "NtReleaseKeyedEvent");
	pNtReleaseMutant = (void *)GetProcAddress(library, "NtReleaseMutant");
	pNtReleaseSemaphore = (void *)GetProcAddress(library, "NtReleaseSemaphore");
	pNtRemoveIoCompletion = (void *)GetProcAddress(library, "NtRemoveIoCompletion");
	pNtRemoveIoCompletionEx = (void *)GetProcAddress(library, "NtRemoveIoCompletionEx");
	pNtRenameKey = (void *)GetProcAddress(library, "NtRenameKey");
	pNtReplaceKey = (void *)GetProcAddress(library, "NtReplaceKey");
	pNtReplyWaitReceivePort = (void *)GetProcAddress(library, "NtReplyWaitReceivePort");
	pNtRequestWaitReplyPort = (void *)GetProcAddress(library, "NtRequestWaitReplyPort");
	pNtResetEvent = (void *)GetProcAddress(library, "NtResetEvent");
	pNtResetWriteWatch = (void *)GetProcAddress(library, "NtResetWriteWatch");
	pNtRestoreKey = (void *)GetProcAddress(library, "NtRestoreKey");
	pNtResumeProcess = (void *)GetProcAddress(library, "NtResumeProcess");
	pNtResumeThread = (void *)GetProcAddress(library, "NtResumeThread");
	pNtSaveKey = (void *)GetProcAddress(library, "NtSaveKey");
	pNtSecureConnectPort = (void *)GetProcAddress(library, "NtSecureConnectPort");
	pNtSetContextThread = (void *)GetProcAddress(library, "NtSetContextThread");
	pNtSetDefaultLocale = (void *)GetProcAddress(library, "NtSetDefaultLocale");
	pNtSetDefaultUILanguage = (void *)GetProcAddress(library, "NtSetDefaultUILanguage");
	pNtSetEaFile = (void *)GetProcAddress(library, "NtSetEaFile");
	pNtSetEvent = (void *)GetProcAddress(library, "NtSetEvent");
	pNtSetInformationFile = (void *)GetProcAddress(library, "NtSetInformationFile");
	pNtSetInformationJobObject = (void *)GetProcAddress(library, "NtSetInformationJobObject");
	pNtSetInformationKey = (void *)GetProcAddress(library, "NtSetInformationKey");
	pNtSetInformationObject = (void *)GetProcAddress(library, "NtSetInformationObject");
	pNtSetInformationProcess = (void *)GetProcAddress(library, "NtSetInformationProcess");
	pNtSetInformationThread = (void *)GetProcAddress(library, "NtSetInformationThread");
	pNtSetInformationToken = (void *)GetProcAddress(library, "NtSetInformationToken");
	pNtSetIntervalProfile = (void *)GetProcAddress(library, "NtSetIntervalProfile");
	pNtSetIoCompletion = (void *)GetProcAddress(library, "NtSetIoCompletion");
	pNtSetLdtEntries = (void *)GetProcAddress(library, "NtSetLdtEntries");
	pNtSetPowerRequest = (void *)GetProcAddress(library, "NtSetPowerRequest");
	pNtSetSecurityObject = (void *)GetProcAddress(library, "NtSetSecurityObject");
	pNtSetSystemInformation = (void *)GetProcAddress(library, "NtSetSystemInformation");
	pNtSetSystemTime = (void *)GetProcAddress(library, "NtSetSystemTime");
	pNtSetThreadExecutionState = (void *)GetProcAddress(library, "NtSetThreadExecutionState");
	pNtSetTimer = (void *)GetProcAddress(library, "NtSetTimer");
	pNtSetTimerResolution = (void *)GetProcAddress(library, "NtSetTimerResolution");
	pNtSetValueKey = (void *)GetProcAddress(library, "NtSetValueKey");
	pNtSetVolumeInformationFile = (void *)GetProcAddress(library, "NtSetVolumeInformationFile");
	pNtShutdownSystem = (void *)GetProcAddress(library, "NtShutdownSystem");
	pNtSignalAndWaitForSingleObject = (void *)GetProcAddress(library, "NtSignalAndWaitForSingleObject");
	pNtSuspendProcess = (void *)GetProcAddress(library, "NtSuspendProcess");
	pNtSuspendThread = (void *)GetProcAddress(library, "NtSuspendThread");
	pNtSystemDebugControl = (void *)GetProcAddress(library, "NtSystemDebugControl");
	pNtTerminateJobObject = (void *)GetProcAddress(library, "NtTerminateJobObject");
	pNtTerminateProcess = (void *)GetProcAddress(library, "NtTerminateProcess");
	pNtTerminateThread = (void *)GetProcAddress(library, "NtTerminateThread");
	pNtUnloadDriver = (void *)GetProcAddress(library, "NtUnloadDriver");
	pNtUnloadKey = (void *)GetProcAddress(library, "NtUnloadKey");
	pNtUnlockFile = (void *)GetProcAddress(library, "NtUnlockFile");
	pNtUnlockVirtualMemory = (void *)GetProcAddress(library, "NtUnlockVirtualMemory");
	pNtUnmapViewOfSection = (void *)GetProcAddress(library, "NtUnmapViewOfSection");
	pNtWaitForKeyedEvent = (void *)GetProcAddress(library, "NtWaitForKeyedEvent");
	pNtWaitForMultipleObjects = (void *)GetProcAddress(library, "NtWaitForMultipleObjects");
	pNtWaitForSingleObject = (void *)GetProcAddress(library, "NtWaitForSingleObject");
	pNtWriteFile = (void *)GetProcAddress(library, "NtWriteFile");
	pNtWriteFileGather = (void *)GetProcAddress(library, "NtWriteFileGather");
	pNtWriteVirtualMemory = (void *)GetProcAddress(library, "NtWriteVirtualMemory");
	pNtYieldExecution = (void *)GetProcAddress(library, "NtYieldExecution");
	pRtlAbsoluteToSelfRelativeSD = (void *)GetProcAddress(library, "RtlAbsoluteToSelfRelativeSD");
	pRtlAcquirePebLock = (void *)GetProcAddress(library, "RtlAcquirePebLock");
	pRtlAcquireResourceExclusive = (void *)GetProcAddress(library, "RtlAcquireResourceExclusive");
	pRtlAcquireResourceShared = (void *)GetProcAddress(library, "RtlAcquireResourceShared");
	pRtlAcquireSRWLockExclusive = (void *)GetProcAddress(library, "RtlAcquireSRWLockExclusive");
	pRtlAcquireSRWLockShared = (void *)GetProcAddress(library, "RtlAcquireSRWLockShared");
	pRtlActivateActivationContext = (void *)GetProcAddress(library, "RtlActivateActivationContext");
	pRtlAddAccessAllowedAce = (void *)GetProcAddress(library, "RtlAddAccessAllowedAce");
	pRtlAddAccessAllowedAceEx = (void *)GetProcAddress(library, "RtlAddAccessAllowedAceEx");
	pRtlAddAccessAllowedObjectAce = (void *)GetProcAddress(library, "RtlAddAccessAllowedObjectAce");
	pRtlAddAccessDeniedAce = (void *)GetProcAddress(library, "RtlAddAccessDeniedAce");
	pRtlAddAccessDeniedAceEx = (void *)GetProcAddress(library, "RtlAddAccessDeniedAceEx");
	pRtlAddAccessDeniedObjectAce = (void *)GetProcAddress(library, "RtlAddAccessDeniedObjectAce");
	pRtlAddAce = (void *)GetProcAddress(library, "RtlAddAce");
	pRtlAddAtomToAtomTable = (void *)GetProcAddress(library, "RtlAddAtomToAtomTable");
	pRtlAddAuditAccessAce = (void *)GetProcAddress(library, "RtlAddAuditAccessAce");
	pRtlAddAuditAccessAceEx = (void *)GetProcAddress(library, "RtlAddAuditAccessAceEx");
	pRtlAddAuditAccessObjectAce = (void *)GetProcAddress(library, "RtlAddAuditAccessObjectAce");
	pRtlAddMandatoryAce = (void *)GetProcAddress(library, "RtlAddMandatoryAce");
	pRtlAddFunctionTable = (void *)GetProcAddress(library, "RtlAddFunctionTable");
	pRtlAddGrowableFunctionTable = (void *)GetProcAddress(library, "RtlAddGrowableFunctionTable");
	pRtlAddRefActivationContext = (void *)GetProcAddress(library, "RtlAddRefActivationContext");
	pRtlAddVectoredContinueHandler = (void *)GetProcAddress(library, "RtlAddVectoredContinueHandler");
	pRtlAddVectoredExceptionHandler = (void *)GetProcAddress(library, "RtlAddVectoredExceptionHandler");
	pRtlAdjustPrivilege = (void *)GetProcAddress(library, "RtlAdjustPrivilege");
	pRtlAllocateAndInitializeSid = (void *)GetProcAddress(library, "RtlAllocateAndInitializeSid");
	pRtlAllocateHandle = (void *)GetProcAddress(library, "RtlAllocateHandle");
	pRtlAllocateHeap = (void *)GetProcAddress(library, "RtlAllocateHeap");
	pRtlAnsiCharToUnicodeChar = (void *)GetProcAddress(library, "RtlAnsiCharToUnicodeChar");
	pRtlAnsiStringToUnicodeSize = (void *)GetProcAddress(library, "RtlAnsiStringToUnicodeSize");
	pRtlAnsiStringToUnicodeString = (void *)GetProcAddress(library, "RtlAnsiStringToUnicodeString");
	pRtlAppendAsciizToString = (void *)GetProcAddress(library, "RtlAppendAsciizToString");
	pRtlAppendStringToString = (void *)GetProcAddress(library, "RtlAppendStringToString");
	pRtlAppendUnicodeStringToString = (void *)GetProcAddress(library, "RtlAppendUnicodeStringToString");
	pRtlAppendUnicodeToString = (void *)GetProcAddress(library, "RtlAppendUnicodeToString");
	pRtlAreAllAccessesGranted = (void *)GetProcAddress(library, "RtlAreAllAccessesGranted");
	pRtlAreAnyAccessesGranted = (void *)GetProcAddress(library, "RtlAreAnyAccessesGranted");
	pRtlAreBitsClear = (void *)GetProcAddress(library, "RtlAreBitsClear");
	pRtlAreBitsSet = (void *)GetProcAddress(library, "RtlAreBitsSet");
	pRtlAssert = (void *)GetProcAddress(library, "RtlAssert");
	pRtlCaptureStackBackTrace = (void *)GetProcAddress(library, "RtlCaptureStackBackTrace");
	pRtlCharToInteger = (void *)GetProcAddress(library, "RtlCharToInteger");
	pRtlCheckRegistryKey = (void *)GetProcAddress(library, "RtlCheckRegistryKey");
	pRtlClearAllBits = (void *)GetProcAddress(library, "RtlClearAllBits");
	pRtlClearBits = (void *)GetProcAddress(library, "RtlClearBits");
	pRtlCompactHeap = (void *)GetProcAddress(library, "RtlCompactHeap");
	pRtlCompareMemory = (void *)GetProcAddress(library, "RtlCompareMemory");
	pRtlCompareMemoryUlong = (void *)GetProcAddress(library, "RtlCompareMemoryUlong");
	pRtlCompareString = (void *)GetProcAddress(library, "RtlCompareString");
	pRtlCompareUnicodeString = (void *)GetProcAddress(library, "RtlCompareUnicodeString");
	pRtlCompareUnicodeStrings = (void *)GetProcAddress(library, "RtlCompareUnicodeStrings");
	pRtlCompressBuffer = (void *)GetProcAddress(library, "RtlCompressBuffer");
	pRtlComputeCrc32 = (void *)GetProcAddress(library, "RtlComputeCrc32");
	pRtlConvertSidToUnicodeString = (void *)GetProcAddress(library, "RtlConvertSidToUnicodeString");
	pRtlConvertToAutoInheritSecurityObject = (void *)GetProcAddress(library, "RtlConvertToAutoInheritSecurityObject");
	pRtlCopyLuid = (void *)GetProcAddress(library, "RtlCopyLuid");
	pRtlCopyLuidAndAttributesArray = (void *)GetProcAddress(library, "RtlCopyLuidAndAttributesArray");
	pRtlCopyMemory = (void *)GetProcAddress(library, "RtlCopyMemory");
	pRtlCopySecurityDescriptor = (void *)GetProcAddress(library, "RtlCopySecurityDescriptor");
	pRtlCopySid = (void *)GetProcAddress(library, "RtlCopySid");
	pRtlCopyString = (void *)GetProcAddress(library, "RtlCopyString");
	pRtlCopyUnicodeString = (void *)GetProcAddress(library, "RtlCopyUnicodeString");
	pRtlCreateAcl = (void *)GetProcAddress(library, "RtlCreateAcl");
	pRtlCreateActivationContext = (void *)GetProcAddress(library, "RtlCreateActivationContext");
	pRtlCreateAtomTable = (void *)GetProcAddress(library, "RtlCreateAtomTable");
	pRtlCreateEnvironment = (void *)GetProcAddress(library, "RtlCreateEnvironment");
	pRtlCreateHeap = (void *)GetProcAddress(library, "RtlCreateHeap");
	pRtlCreateProcessParameters = (void *)GetProcAddress(library, "RtlCreateProcessParameters");
	pRtlCreateProcessParametersEx = (void *)GetProcAddress(library, "RtlCreateProcessParametersEx");
	pRtlCreateQueryDebugBuffer = (void *)GetProcAddress(library, "RtlCreateQueryDebugBuffer");
	pRtlCreateRegistryKey = (void *)GetProcAddress(library, "RtlCreateRegistryKey");
	pRtlCreateSecurityDescriptor = (void *)GetProcAddress(library, "RtlCreateSecurityDescriptor");
	pRtlCreateTimer = (void *)GetProcAddress(library, "RtlCreateTimer");
	pRtlCreateTimerQueue = (void *)GetProcAddress(library, "RtlCreateTimerQueue");
	pRtlCreateUnicodeString = (void *)GetProcAddress(library, "RtlCreateUnicodeString");
	pRtlCreateUnicodeStringFromAsciiz = (void *)GetProcAddress(library, "RtlCreateUnicodeStringFromAsciiz");
	pRtlCreateUserProcess = (void *)GetProcAddress(library, "RtlCreateUserProcess");
	pRtlCreateUserStack = (void *)GetProcAddress(library, "RtlCreateUserStack");
	pRtlCreateUserThread = (void *)GetProcAddress(library, "RtlCreateUserThread");
	pRtlDeNormalizeProcessParams = (void *)GetProcAddress(library, "RtlDeNormalizeProcessParams");
	pRtlDeactivateActivationContext = (void *)GetProcAddress(library, "RtlDeactivateActivationContext");
	pRtlDecodePointer = (void *)GetProcAddress(library, "RtlDecodePointer");
	pRtlDecompressBuffer = (void *)GetProcAddress(library, "RtlDecompressBuffer");
	pRtlDecompressFragment = (void *)GetProcAddress(library, "RtlDecompressFragment");
	pRtlDeleteAce = (void *)GetProcAddress(library, "RtlDeleteAce");
	pRtlDeleteAtomFromAtomTable = (void *)GetProcAddress(library, "RtlDeleteAtomFromAtomTable");
	pRtlDeleteCriticalSection = (void *)GetProcAddress(library, "RtlDeleteCriticalSection");
	pRtlDeleteGrowableFunctionTable = (void *)GetProcAddress(library, "RtlDeleteGrowableFunctionTable");
	pRtlDeleteFunctionTable = (void *)GetProcAddress(library, "RtlDeleteFunctionTable");
	pRtlDeleteRegistryValue = (void *)GetProcAddress(library, "RtlDeleteRegistryValue");
	pRtlDeleteResource = (void *)GetProcAddress(library, "RtlDeleteResource");
	pRtlDeleteSecurityObject = (void *)GetProcAddress(library, "RtlDeleteSecurityObject");
	pRtlDeleteTimer = (void *)GetProcAddress(library, "RtlDeleteTimer");
	pRtlDeleteTimerQueueEx = (void *)GetProcAddress(library, "RtlDeleteTimerQueueEx");
	pRtlDeregisterWait = (void *)GetProcAddress(library, "RtlDeregisterWait");
	pRtlDeregisterWaitEx = (void *)GetProcAddress(library, "RtlDeregisterWaitEx");
	pRtlDestroyAtomTable = (void *)GetProcAddress(library, "RtlDestroyAtomTable");
	pRtlDestroyEnvironment = (void *)GetProcAddress(library, "RtlDestroyEnvironment");
	pRtlDestroyHandleTable = (void *)GetProcAddress(library, "RtlDestroyHandleTable");
	pRtlDestroyHeap = (void *)GetProcAddress(library, "RtlDestroyHeap");
	pRtlDestroyProcessParameters = (void *)GetProcAddress(library, "RtlDestroyProcessParameters");
	pRtlDestroyQueryDebugBuffer = (void *)GetProcAddress(library, "RtlDestroyQueryDebugBuffer");
	pRtlDetermineDosPathNameType_U = (void *)GetProcAddress(library, "RtlDetermineDosPathNameType_U");
	pRtlDllShutdownInProgress = (void *)GetProcAddress(library, "RtlDllShutdownInProgress");
	pRtlDoesFileExists_U = (void *)GetProcAddress(library, "RtlDoesFileExists_U");
	pRtlDosPathNameToNtPathName_U = (void *)GetProcAddress(library, "RtlDosPathNameToNtPathName_U");
	pRtlDosPathNameToNtPathName_U_WithStatus = (void *)GetProcAddress(library, "RtlDosPathNameToNtPathName_U_WithStatus");
	pRtlDosPathNameToRelativeNtPathName_U_WithStatus = (void *)GetProcAddress(library, "RtlDosPathNameToRelativeNtPathName_U_WithStatus");
	pRtlDosSearchPath_U = (void *)GetProcAddress(library, "RtlDosSearchPath_U");
	pRtlDowncaseUnicodeChar = (void *)GetProcAddress(library, "RtlDowncaseUnicodeChar");
	pRtlDowncaseUnicodeString = (void *)GetProcAddress(library, "RtlDowncaseUnicodeString");
	pRtlDumpResource = (void *)GetProcAddress(library, "RtlDumpResource");
	pRtlDuplicateUnicodeString = (void *)GetProcAddress(library, "RtlDuplicateUnicodeString");
	pRtlEmptyAtomTable = (void *)GetProcAddress(library, "RtlEmptyAtomTable");
	pRtlEncodePointer = (void *)GetProcAddress(library, "RtlEncodePointer");
	pRtlEnterCriticalSection = (void *)GetProcAddress(library, "RtlEnterCriticalSection");
	pRtlEnumerateGenericTableWithoutSplaying = (void *)GetProcAddress(library, "RtlEnumerateGenericTableWithoutSplaying");
	pRtlEqualComputerName = (void *)GetProcAddress(library, "RtlEqualComputerName");
	pRtlEqualDomainName = (void *)GetProcAddress(library, "RtlEqualDomainName");
	pRtlEqualLuid = (void *)GetProcAddress(library, "RtlEqualLuid");
	pRtlEqualPrefixSid = (void *)GetProcAddress(library, "RtlEqualPrefixSid");
	pRtlEqualSid = (void *)GetProcAddress(library, "RtlEqualSid");
	pRtlEqualString = (void *)GetProcAddress(library, "RtlEqualString");
	pRtlEqualUnicodeString = (void *)GetProcAddress(library, "RtlEqualUnicodeString");
	pRtlEraseUnicodeString = (void *)GetProcAddress(library, "RtlEraseUnicodeString");
	pRtlExitUserProcess = (void *)GetProcAddress(library, "RtlExitUserProcess");
	pRtlExitUserThread = (void *)GetProcAddress(library, "RtlExitUserThread");
	pRtlExpandEnvironmentStrings = (void *)GetProcAddress(library, "RtlExpandEnvironmentStrings");
	pRtlExpandEnvironmentStrings_U = (void *)GetProcAddress(library, "RtlExpandEnvironmentStrings_U");
	pRtlFillMemory = (void *)GetProcAddress(library, "RtlFillMemory");
	pRtlFillMemoryUlong = (void *)GetProcAddress(library, "RtlFillMemoryUlong");
	pRtlFindActivationContextSectionGuid = (void *)GetProcAddress(library, "RtlFindActivationContextSectionGuid");
	pRtlFindActivationContextSectionString = (void *)GetProcAddress(library, "RtlFindActivationContextSectionString");
	pRtlFindCharInUnicodeString = (void *)GetProcAddress(library, "RtlFindCharInUnicodeString");
	pRtlFindClearBits = (void *)GetProcAddress(library, "RtlFindClearBits");
	pRtlFindClearBitsAndSet = (void *)GetProcAddress(library, "RtlFindClearBitsAndSet");
	pRtlFindClearRuns = (void *)GetProcAddress(library, "RtlFindClearRuns");
	pRtlFindLastBackwardRunClear = (void *)GetProcAddress(library, "RtlFindLastBackwardRunClear");
	pRtlFindLastBackwardRunSet = (void *)GetProcAddress(library, "RtlFindLastBackwardRunSet");
	pRtlFindLeastSignificantBit = (void *)GetProcAddress(library, "RtlFindLeastSignificantBit");
	pRtlFindLongestRunClear = (void *)GetProcAddress(library, "RtlFindLongestRunClear");
	pRtlFindLongestRunSet = (void *)GetProcAddress(library, "RtlFindLongestRunSet");
	pRtlFindMessage = (void *)GetProcAddress(library, "RtlFindMessage");
	pRtlFindMostSignificantBit = (void *)GetProcAddress(library, "RtlFindMostSignificantBit");
	pRtlFindNextForwardRunClear = (void *)GetProcAddress(library, "RtlFindNextForwardRunClear");
	pRtlFindNextForwardRunSet = (void *)GetProcAddress(library, "RtlFindNextForwardRunSet");
	pRtlFindSetBits = (void *)GetProcAddress(library, "RtlFindSetBits");
	pRtlFindSetBitsAndClear = (void *)GetProcAddress(library, "RtlFindSetBitsAndClear");
	pRtlFindSetRuns = (void *)GetProcAddress(library, "RtlFindSetRuns");
	pRtlFirstEntrySList = (void *)GetProcAddress(library, "RtlFirstEntrySList");
	pRtlFirstFreeAce = (void *)GetProcAddress(library, "RtlFirstFreeAce");
	pRtlFormatCurrentUserKeyPath = (void *)GetProcAddress(library, "RtlFormatCurrentUserKeyPath");
	pRtlFormatMessage = (void *)GetProcAddress(library, "RtlFormatMessage");
	pRtlFreeAnsiString = (void *)GetProcAddress(library, "RtlFreeAnsiString");
	pRtlFreeHandle = (void *)GetProcAddress(library, "RtlFreeHandle");
	pRtlFreeHeap = (void *)GetProcAddress(library, "RtlFreeHeap");
	pRtlFreeOemString = (void *)GetProcAddress(library, "RtlFreeOemString");
	pRtlFreeSid = (void *)GetProcAddress(library, "RtlFreeSid");
	pRtlFreeThreadActivationContextStack = (void *)GetProcAddress(library, "RtlFreeThreadActivationContextStack");
	pRtlFreeUnicodeString = (void *)GetProcAddress(library, "RtlFreeUnicodeString");
	pRtlFreeUserStack = (void *)GetProcAddress(library, "RtlFreeUserStack");
	pRtlGUIDFromString = (void *)GetProcAddress(library, "RtlGUIDFromString");
	pRtlGetAce = (void *)GetProcAddress(library, "RtlGetAce");
	pRtlGetActiveActivationContext = (void *)GetProcAddress(library, "RtlGetActiveActivationContext");
	pRtlGetCompressionWorkSpaceSize = (void *)GetProcAddress(library, "RtlGetCompressionWorkSpaceSize");
	pRtlGetControlSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetControlSecurityDescriptor");
	pRtlGetCurrentDirectory_U = (void *)GetProcAddress(library, "RtlGetCurrentDirectory_U");
	pRtlGetCurrentPeb = (void *)GetProcAddress(library, "RtlGetCurrentPeb");
	pRtlGetCurrentProcessorNumberEx = (void *)GetProcAddress(library, "RtlGetCurrentProcessorNumberEx");
	pRtlGetCurrentTransaction = (void *)GetProcAddress(library, "RtlGetCurrentTransaction");
	pRtlGetDaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetDaclSecurityDescriptor");
	pRtlGetFrame = (void *)GetProcAddress(library, "RtlGetFrame");
	pRtlGetFullPathName_U = (void *)GetProcAddress(library, "RtlGetFullPathName_U");
	pRtlGetGroupSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetGroupSecurityDescriptor");
	pRtlGetLastNtStatus = (void *)GetProcAddress(library, "RtlGetLastNtStatus");
	pRtlGetLastWin32Error = (void *)GetProcAddress(library, "RtlGetLastWin32Error");
	pRtlGetLongestNtPathLength = (void *)GetProcAddress(library, "RtlGetLongestNtPathLength");
	pRtlGetNtGlobalFlags = (void *)GetProcAddress(library, "RtlGetNtGlobalFlags");
	pRtlGetNtProductType = (void *)GetProcAddress(library, "RtlGetNtProductType");
	pRtlGetNtVersionNumbers = (void *)GetProcAddress(library, "RtlGetNtVersionNumbers");
	pRtlGetOwnerSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetOwnerSecurityDescriptor");
	pRtlGetProductInfo = (void *)GetProcAddress(library, "RtlGetProductInfo");
	pRtlGetProcessHeaps = (void *)GetProcAddress(library, "RtlGetProcessHeaps");
	pRtlGetSaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlGetSaclSecurityDescriptor");
	pRtlGetSystemTimePrecise = (void *)GetProcAddress(library, "RtlGetSystemTimePrecise");
	pRtlGetThreadErrorMode = (void *)GetProcAddress(library, "RtlGetThreadErrorMode");
	pRtlGetUnloadEventTrace = (void *)GetProcAddress(library, "RtlGetUnloadEventTrace");
	pRtlGetUnloadEventTraceEx = (void *)GetProcAddress(library, "RtlGetUnloadEventTraceEx");
	pRtlGetVersion = (void *)GetProcAddress(library, "RtlGetVersion");
	pRtlGrowFunctionTable = (void *)GetProcAddress(library, "RtlGrowFunctionTable");
	pRtlHashUnicodeString = (void *)GetProcAddress(library, "RtlHashUnicodeString");
	pRtlIdentifierAuthoritySid = (void *)GetProcAddress(library, "RtlIdentifierAuthoritySid");
	pRtlImageDirectoryEntryToData = (void *)GetProcAddress(library, "RtlImageDirectoryEntryToData");
	pRtlImageNtHeader = (void *)GetProcAddress(library, "RtlImageNtHeader");
	pRtlImageRvaToSection = (void *)GetProcAddress(library, "RtlImageRvaToSection");
	pRtlImageRvaToVa = (void *)GetProcAddress(library, "RtlImageRvaToVa");
	pRtlImpersonateSelf = (void *)GetProcAddress(library, "RtlImpersonateSelf");
	pRtlInitAnsiString = (void *)GetProcAddress(library, "RtlInitAnsiString");
	pRtlInitAnsiStringEx = (void *)GetProcAddress(library, "RtlInitAnsiStringEx");
	pRtlInitString = (void *)GetProcAddress(library, "RtlInitString");
	pRtlInitUnicodeString = (void *)GetProcAddress(library, "RtlInitUnicodeString");
	pRtlInitUnicodeStringEx = (void *)GetProcAddress(library, "RtlInitUnicodeStringEx");
	pRtlInitializeBitMap = (void *)GetProcAddress(library, "RtlInitializeBitMap");
	pRtlInitializeConditionVariable = (void *)GetProcAddress(library, "RtlInitializeConditionVariable");
	pRtlInitializeCriticalSection = (void *)GetProcAddress(library, "RtlInitializeCriticalSection");
	pRtlInitializeCriticalSectionAndSpinCount = (void *)GetProcAddress(library, "RtlInitializeCriticalSectionAndSpinCount");
	pRtlInitializeCriticalSectionEx = (void *)GetProcAddress(library, "RtlInitializeCriticalSectionEx");
	pRtlInitializeGenericTable = (void *)GetProcAddress(library, "RtlInitializeGenericTable");
	pRtlInitializeGenericTableAvl = (void *)GetProcAddress(library, "RtlInitializeGenericTableAvl");
	pRtlInitializeHandleTable = (void *)GetProcAddress(library, "RtlInitializeHandleTable");
	pRtlInitializeResource = (void *)GetProcAddress(library, "RtlInitializeResource");
	pRtlInitializeSListHead = (void *)GetProcAddress(library, "RtlInitializeSListHead");
	pRtlInitializeSRWLock = (void *)GetProcAddress(library, "RtlInitializeSRWLock");
	pRtlInitializeSid = (void *)GetProcAddress(library, "RtlInitializeSid");
	pRtlInsertElementGenericTableAvl = (void *)GetProcAddress(library, "RtlInsertElementGenericTableAvl");
	pRtlInstallFunctionTableCallback = (void *)GetProcAddress(library, "RtlInstallFunctionTableCallback");
	pRtlInt64ToUnicodeString = (void *)GetProcAddress(library, "RtlInt64ToUnicodeString");
	pRtlIntegerToChar = (void *)GetProcAddress(library, "RtlIntegerToChar");
	pRtlIntegerToUnicodeString = (void *)GetProcAddress(library, "RtlIntegerToUnicodeString");
	pRtlInterlockedFlushSList = (void *)GetProcAddress(library, "RtlInterlockedFlushSList");
	pRtlInterlockedPopEntrySList = (void *)GetProcAddress(library, "RtlInterlockedPopEntrySList");
	pRtlInterlockedPushEntrySList = (void *)GetProcAddress(library, "RtlInterlockedPushEntrySList");
	pRtlInterlockedPushListSList = (void *)GetProcAddress(library, "RtlInterlockedPushListSList");
	pRtlInterlockedPushListSListEx = (void *)GetProcAddress(library, "RtlInterlockedPushListSListEx");
	pRtlIpv4AddressToStringA = (void *)GetProcAddress(library, "RtlIpv4AddressToStringA");
	pRtlIpv4AddressToStringExA = (void *)GetProcAddress(library, "RtlIpv4AddressToStringExA");
	pRtlIpv4AddressToStringExW = (void *)GetProcAddress(library, "RtlIpv4AddressToStringExW");
	pRtlIpv4AddressToStringW = (void *)GetProcAddress(library, "RtlIpv4AddressToStringW");
	pRtlIpv4StringToAddressA = (void *)GetProcAddress(library, "RtlIpv4StringToAddressA");
	pRtlIpv4StringToAddressExA = (void *)GetProcAddress(library, "RtlIpv4StringToAddressExA");
	pRtlIpv4StringToAddressExW = (void *)GetProcAddress(library, "RtlIpv4StringToAddressExW");
	pRtlIpv4StringToAddressW = (void *)GetProcAddress(library, "RtlIpv4StringToAddressW");
	pRtlIpv6StringToAddressExW = (void *)GetProcAddress(library, "RtlIpv6StringToAddressExW");
	pRtlIsActivationContextActive = (void *)GetProcAddress(library, "RtlIsActivationContextActive");
	pRtlIsCriticalSectionLocked = (void *)GetProcAddress(library, "RtlIsCriticalSectionLocked");
	pRtlIsCriticalSectionLockedByThread = (void *)GetProcAddress(library, "RtlIsCriticalSectionLockedByThread");
	pRtlIsDosDeviceName_U = (void *)GetProcAddress(library, "RtlIsDosDeviceName_U");
	pRtlIsNameLegalDOS8Dot3 = (void *)GetProcAddress(library, "RtlIsNameLegalDOS8Dot3");
	pRtlIsProcessorFeaturePresent = (void *)GetProcAddress(library, "RtlIsProcessorFeaturePresent");
	pRtlIsTextUnicode = (void *)GetProcAddress(library, "RtlIsTextUnicode");
	pRtlIsValidHandle = (void *)GetProcAddress(library, "RtlIsValidHandle");
	pRtlIsValidIndexHandle = (void *)GetProcAddress(library, "RtlIsValidIndexHandle");
	pRtlLargeIntegerToChar = (void *)GetProcAddress(library, "RtlLargeIntegerToChar");
	pRtlLeaveCriticalSection = (void *)GetProcAddress(library, "RtlLeaveCriticalSection");
	pRtlLengthRequiredSid = (void *)GetProcAddress(library, "RtlLengthRequiredSid");
	pRtlLengthSecurityDescriptor = (void *)GetProcAddress(library, "RtlLengthSecurityDescriptor");
	pRtlLengthSid = (void *)GetProcAddress(library, "RtlLengthSid");
	pRtlLocalTimeToSystemTime = (void *)GetProcAddress(library, "RtlLocalTimeToSystemTime");
	pRtlLockHeap = (void *)GetProcAddress(library, "RtlLockHeap");
	pRtlLookupAtomInAtomTable = (void *)GetProcAddress(library, "RtlLookupAtomInAtomTable");
	pRtlLookupFunctionEntry = (void *)GetProcAddress(library, "RtlLookupFunctionEntry");
	pRtlMakeSelfRelativeSD = (void *)GetProcAddress(library, "RtlMakeSelfRelativeSD");
	pRtlMapGenericMask = (void *)GetProcAddress(library, "RtlMapGenericMask");
	pRtlMoveMemory = (void *)GetProcAddress(library, "RtlMoveMemory");
	pRtlMultiByteToUnicodeN = (void *)GetProcAddress(library, "RtlMultiByteToUnicodeN");
	pRtlMultiByteToUnicodeSize = (void *)GetProcAddress(library, "RtlMultiByteToUnicodeSize");
	pRtlNewSecurityObject = (void *)GetProcAddress(library, "RtlNewSecurityObject");
	pRtlNormalizeProcessParams = (void *)GetProcAddress(library, "RtlNormalizeProcessParams");
	pRtlNtStatusToDosError = (void *)GetProcAddress(library, "RtlNtStatusToDosError");
	pRtlNtStatusToDosErrorNoTeb = (void *)GetProcAddress(library, "RtlNtStatusToDosErrorNoTeb");
	pRtlNumberGenericTableElements = (void *)GetProcAddress(library, "RtlNumberGenericTableElements");
	pRtlNumberOfClearBits = (void *)GetProcAddress(library, "RtlNumberOfClearBits");
	pRtlNumberOfSetBits = (void *)GetProcAddress(library, "RtlNumberOfSetBits");
	pRtlOemStringToUnicodeSize = (void *)GetProcAddress(library, "RtlOemStringToUnicodeSize");
	pRtlOemStringToUnicodeString = (void *)GetProcAddress(library, "RtlOemStringToUnicodeString");
	pRtlOemToUnicodeN = (void *)GetProcAddress(library, "RtlOemToUnicodeN");
	pRtlOpenCurrentUser = (void *)GetProcAddress(library, "RtlOpenCurrentUser");
	pRtlPcToFileHeader = (void *)GetProcAddress(library, "RtlPcToFileHeader");
	pRtlPinAtomInAtomTable = (void *)GetProcAddress(library, "RtlPinAtomInAtomTable");
	pRtlPopFrame = (void *)GetProcAddress(library, "RtlPopFrame");
	pRtlPrefixString = (void *)GetProcAddress(library, "RtlPrefixString");
	pRtlPrefixUnicodeString = (void *)GetProcAddress(library, "RtlPrefixUnicodeString");
	pRtlPushFrame = (void *)GetProcAddress(library, "RtlPushFrame");
	pRtlQueryActivationContextApplicationSettings = (void *)GetProcAddress(library, "RtlQueryActivationContextApplicationSettings");
	pRtlQueryAtomInAtomTable = (void *)GetProcAddress(library, "RtlQueryAtomInAtomTable");
	pRtlQueryDepthSList = (void *)GetProcAddress(library, "RtlQueryDepthSList");
	pRtlQueryDynamicTimeZoneInformation = (void *)GetProcAddress(library, "RtlQueryDynamicTimeZoneInformation");
	pRtlQueryEnvironmentVariable_U = (void *)GetProcAddress(library, "RtlQueryEnvironmentVariable_U");
	pRtlQueryHeapInformation = (void *)GetProcAddress(library, "RtlQueryHeapInformation");
	pRtlQueryInformationAcl = (void *)GetProcAddress(library, "RtlQueryInformationAcl");
	pRtlQueryInformationActivationContext = (void *)GetProcAddress(library, "RtlQueryInformationActivationContext");
	pRtlQueryPackageIdentity = (void *)GetProcAddress(library, "RtlQueryPackageIdentity");
	pRtlQueryPerformanceCounter = (void *)GetProcAddress(library, "RtlQueryPerformanceCounter");
	pRtlQueryPerformanceFrequency = (void *)GetProcAddress(library, "RtlQueryPerformanceFrequency");
	pRtlQueryProcessDebugInformation = (void *)GetProcAddress(library, "RtlQueryProcessDebugInformation");
	pRtlQueryRegistryValues = (void *)GetProcAddress(library, "RtlQueryRegistryValues");
	pRtlQueryTimeZoneInformation = (void *)GetProcAddress(library, "RtlQueryTimeZoneInformation");
	pRtlQueryUnbiasedInterruptTime = (void *)GetProcAddress(library, "RtlQueryUnbiasedInterruptTime");
	pRtlQueueWorkItem = (void *)GetProcAddress(library, "RtlQueueWorkItem");
	pRtlRaiseStatus = (void *)GetProcAddress(library, "RtlRaiseStatus");
	pRtlRandom = (void *)GetProcAddress(library, "RtlRandom");
	pRtlRandomEx = (void *)GetProcAddress(library, "RtlRandomEx");
	pRtlReAllocateHeap = (void *)GetProcAddress(library, "RtlReAllocateHeap");
	pRtlRegisterWait = (void *)GetProcAddress(library, "RtlRegisterWait");
	pRtlReleaseActivationContext = (void *)GetProcAddress(library, "RtlReleaseActivationContext");
	pRtlReleasePebLock = (void *)GetProcAddress(library, "RtlReleasePebLock");
	pRtlReleaseRelativeName = (void *)GetProcAddress(library, "RtlReleaseRelativeName");
	pRtlReleaseResource = (void *)GetProcAddress(library, "RtlReleaseResource");
	pRtlReleaseSRWLockExclusive = (void *)GetProcAddress(library, "RtlReleaseSRWLockExclusive");
	pRtlReleaseSRWLockShared = (void *)GetProcAddress(library, "RtlReleaseSRWLockShared");
	pRtlRemoveVectoredContinueHandler = (void *)GetProcAddress(library, "RtlRemoveVectoredContinueHandler");
	pRtlRemoveVectoredExceptionHandler = (void *)GetProcAddress(library, "RtlRemoveVectoredExceptionHandler");
	pRtlRestoreContext = (void *)GetProcAddress(library, "RtlRestoreContext");
	pRtlRunOnceBeginInitialize = (void *)GetProcAddress(library, "RtlRunOnceBeginInitialize");
	pRtlRunOnceComplete = (void *)GetProcAddress(library, "RtlRunOnceComplete");
	pRtlRunOnceExecuteOnce = (void *)GetProcAddress(library, "RtlRunOnceExecuteOnce");
	pRtlRunOnceInitialize = (void *)GetProcAddress(library, "RtlRunOnceInitialize");
	pRtlSecondsSince1970ToTime = (void *)GetProcAddress(library, "RtlSecondsSince1970ToTime");
	pRtlSecondsSince1980ToTime = (void *)GetProcAddress(library, "RtlSecondsSince1980ToTime");
	pRtlSelfRelativeToAbsoluteSD = (void *)GetProcAddress(library, "RtlSelfRelativeToAbsoluteSD");
	pRtlSetAllBits = (void *)GetProcAddress(library, "RtlSetAllBits");
	pRtlSetBits = (void *)GetProcAddress(library, "RtlSetBits");
	pRtlSetControlSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetControlSecurityDescriptor");
	pRtlSetCriticalSectionSpinCount = (void *)GetProcAddress(library, "RtlSetCriticalSectionSpinCount");
	pRtlSetCurrentDirectory_U = (void *)GetProcAddress(library, "RtlSetCurrentDirectory_U");
	pRtlSetCurrentEnvironment = (void *)GetProcAddress(library, "RtlSetCurrentEnvironment");
	pRtlSetCurrentTransaction = (void *)GetProcAddress(library, "RtlSetCurrentTransaction");
	pRtlSetDaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetDaclSecurityDescriptor");
	pRtlSetEnvironmentVariable = (void *)GetProcAddress(library, "RtlSetEnvironmentVariable");
	pRtlSetGroupSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetGroupSecurityDescriptor");
	pRtlSetHeapInformation = (void *)GetProcAddress(library, "RtlSetHeapInformation");
	pRtlSetIoCompletionCallback = (void *)GetProcAddress(library, "RtlSetIoCompletionCallback");
	pRtlSetLastWin32Error = (void *)GetProcAddress(library, "RtlSetLastWin32Error");
	pRtlSetLastWin32ErrorAndNtStatusFromNtStatus = (void *)GetProcAddress(library, "RtlSetLastWin32ErrorAndNtStatusFromNtStatus");
	pRtlSetOwnerSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetOwnerSecurityDescriptor");
	pRtlSetSaclSecurityDescriptor = (void *)GetProcAddress(library, "RtlSetSaclSecurityDescriptor");
	pRtlSetThreadErrorMode = (void *)GetProcAddress(library, "RtlSetThreadErrorMode");
	pRtlSetTimeZoneInformation = (void *)GetProcAddress(library, "RtlSetTimeZoneInformation");
	pRtlSetUnhandledExceptionFilter = (void *)GetProcAddress(library, "RtlSetUnhandledExceptionFilter");
	pRtlSizeHeap = (void *)GetProcAddress(library, "RtlSizeHeap");
	pRtlSleepConditionVariableCS = (void *)GetProcAddress(library, "RtlSleepConditionVariableCS");
	pRtlSleepConditionVariableSRW = (void *)GetProcAddress(library, "RtlSleepConditionVariableSRW");
	pRtlStringFromGUID = (void *)GetProcAddress(library, "RtlStringFromGUID");
	pRtlSubAuthorityCountSid = (void *)GetProcAddress(library, "RtlSubAuthorityCountSid");
	pRtlSubAuthoritySid = (void *)GetProcAddress(library, "RtlSubAuthoritySid");
	pRtlSystemTimeToLocalTime = (void *)GetProcAddress(library, "RtlSystemTimeToLocalTime");
	pRtlTimeFieldsToTime = (void *)GetProcAddress(library, "RtlTimeFieldsToTime");
	pRtlTimeToElapsedTimeFields = (void *)GetProcAddress(library, "RtlTimeToElapsedTimeFields");
	pRtlTimeToSecondsSince1970 = (void *)GetProcAddress(library, "RtlTimeToSecondsSince1970");
	pRtlTimeToSecondsSince1980 = (void *)GetProcAddress(library, "RtlTimeToSecondsSince1980");
	pRtlTimeToTimeFields = (void *)GetProcAddress(library, "RtlTimeToTimeFields");
	pRtlTryAcquireSRWLockExclusive = (void *)GetProcAddress(library, "RtlTryAcquireSRWLockExclusive");
	pRtlTryAcquireSRWLockShared = (void *)GetProcAddress(library, "RtlTryAcquireSRWLockShared");
	pRtlTryEnterCriticalSection = (void *)GetProcAddress(library, "RtlTryEnterCriticalSection");
	pRtlUlonglongByteSwap = (void *)GetProcAddress(library, "RtlUlonglongByteSwap");
	pRtlUnicodeStringToAnsiSize = (void *)GetProcAddress(library, "RtlUnicodeStringToAnsiSize");
	pRtlUnicodeStringToAnsiString = (void *)GetProcAddress(library, "RtlUnicodeStringToAnsiString");
	pRtlUnicodeStringToInteger = (void *)GetProcAddress(library, "RtlUnicodeStringToInteger");
	pRtlUnicodeStringToOemSize = (void *)GetProcAddress(library, "RtlUnicodeStringToOemSize");
	pRtlUnicodeStringToOemString = (void *)GetProcAddress(library, "RtlUnicodeStringToOemString");
	pRtlUnicodeToMultiByteN = (void *)GetProcAddress(library, "RtlUnicodeToMultiByteN");
	pRtlUnicodeToMultiByteSize = (void *)GetProcAddress(library, "RtlUnicodeToMultiByteSize");
	pRtlUnicodeToOemN = (void *)GetProcAddress(library, "RtlUnicodeToOemN");
	pRtlUnicodeToUTF8N = (void *)GetProcAddress(library, "RtlUnicodeToUTF8N");
	pRtlUniform = (void *)GetProcAddress(library, "RtlUniform");
	pRtlUnlockHeap = (void *)GetProcAddress(library, "RtlUnlockHeap");
	pRtlUnwind = (void *)GetProcAddress(library, "RtlUnwind");
	pRtlUnwindEx = (void *)GetProcAddress(library, "RtlUnwindEx");
	pRtlUpcaseUnicodeChar = (void *)GetProcAddress(library, "RtlUpcaseUnicodeChar");
	pRtlUpcaseUnicodeString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeString");
	pRtlUpcaseUnicodeStringToAnsiString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToAnsiString");
	pRtlUpcaseUnicodeStringToCountedOemString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToCountedOemString");
	pRtlUpcaseUnicodeStringToOemString = (void *)GetProcAddress(library, "RtlUpcaseUnicodeStringToOemString");
	pRtlUpcaseUnicodeToMultiByteN = (void *)GetProcAddress(library, "RtlUpcaseUnicodeToMultiByteN");
	pRtlUpcaseUnicodeToOemN = (void *)GetProcAddress(library, "RtlUpcaseUnicodeToOemN");
	pRtlUpdateTimer = (void *)GetProcAddress(library, "RtlUpdateTimer");
	pRtlUpperChar = (void *)GetProcAddress(library, "RtlUpperChar");
	pRtlUpperString = (void *)GetProcAddress(library, "RtlUpperString");
	pRtlValidAcl = (void *)GetProcAddress(library, "RtlValidAcl");
	pRtlValidRelativeSecurityDescriptor = (void *)GetProcAddress(library, "RtlValidRelativeSecurityDescriptor");
	pRtlValidSecurityDescriptor = (void *)GetProcAddress(library, "RtlValidSecurityDescriptor");
	pRtlValidSid = (void *)GetProcAddress(library, "RtlValidSid");
	pRtlValidateHeap = (void *)GetProcAddress(library, "RtlValidateHeap");
	pRtlVerifyVersionInfo = (void *)GetProcAddress(library, "RtlVerifyVersionInfo");
	pRtlVirtualUnwind = (void *)GetProcAddress(library, "RtlVirtualUnwind");
	pRtlWaitOnAddress = (void *)GetProcAddress(library, "RtlWaitOnAddress");
	pRtlWakeAddressAll = (void *)GetProcAddress(library, "RtlWakeAddressAll");
	pRtlWakeAddressSingle = (void *)GetProcAddress(library, "RtlWakeAddressSingle");
	pRtlWakeAllConditionVariable = (void *)GetProcAddress(library, "RtlWakeAllConditionVariable");
	pRtlWakeConditionVariable = (void *)GetProcAddress(library, "RtlWakeConditionVariable");
	pRtlWalkHeap = (void *)GetProcAddress(library, "RtlWalkHeap");
	pRtlWow64EnableFsRedirection = (void *)GetProcAddress(library, "RtlWow64EnableFsRedirection");
	pRtlWow64EnableFsRedirectionEx = (void *)GetProcAddress(library, "RtlWow64EnableFsRedirectionEx");
	pRtlWow64GetThreadContext = (void *)GetProcAddress(library, "RtlWow64GetThreadContext");
	pRtlWow64SetThreadContext = (void *)GetProcAddress(library, "RtlWow64SetThreadContext");
	pRtlWriteRegistryValue = (void *)GetProcAddress(library, "RtlWriteRegistryValue");
	pRtlZeroMemory = (void *)GetProcAddress(library, "RtlZeroMemory");
	pRtlZombifyActivationContext = (void *)GetProcAddress(library, "RtlZombifyActivationContext");
	pRtlpNtCreateKey = (void *)GetProcAddress(library, "RtlpNtCreateKey");
	pRtlpNtEnumerateSubKey = (void *)GetProcAddress(library, "RtlpNtEnumerateSubKey");
	pRtlpNtMakeTemporaryKey = (void *)GetProcAddress(library, "RtlpNtMakeTemporaryKey");
	pRtlpNtOpenKey = (void *)GetProcAddress(library, "RtlpNtOpenKey");
	pRtlpNtQueryValueKey = (void *)GetProcAddress(library, "RtlpNtQueryValueKey");
	pRtlpNtSetValueKey = (void *)GetProcAddress(library, "RtlpNtSetValueKey");
	pRtlpUnWaitCriticalSection = (void *)GetProcAddress(library, "RtlpUnWaitCriticalSection");
	pRtlpWaitForCriticalSection = (void *)GetProcAddress(library, "RtlpWaitForCriticalSection");
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
	pVerSetConditionMask = (void *)GetProcAddress(library, "VerSetConditionMask");
	pWinSqmEndSession = (void *)GetProcAddress(library, "WinSqmEndSession");
	pWinSqmIncrementDWORD = (void *)GetProcAddress(library, "WinSqmIncrementDWORD");
	pWinSqmIsOptedIn = (void *)GetProcAddress(library, "WinSqmIsOptedIn");
	pWinSqmSetDWORD = (void *)GetProcAddress(library, "WinSqmSetDWORD");
	pWinSqmStartSession = (void *)GetProcAddress(library, "WinSqmStartSession");
	p__C_specific_handler = (void *)GetProcAddress(library, "__C_specific_handler");
	p__isascii = (void *)GetProcAddress(library, "__isascii");
	p__iscsym = (void *)GetProcAddress(library, "__iscsym");
	p__iscsymf = (void *)GetProcAddress(library, "__iscsymf");
	p__toascii = (void *)GetProcAddress(library, "__toascii");
	p_atoi64 = (void *)GetProcAddress(library, "_atoi64");
	p_i64toa = (void *)GetProcAddress(library, "_i64toa");
	p_i64tow = (void *)GetProcAddress(library, "_i64tow");
	p_itoa = (void *)GetProcAddress(library, "_itoa");
	p_itow = (void *)GetProcAddress(library, "_itow");
	p_lfind = (void *)GetProcAddress(library, "_lfind");
	p_local_unwind = (void *)GetProcAddress(library, "_local_unwind");
	p_ltoa = (void *)GetProcAddress(library, "_ltoa");
	p_ltow = (void *)GetProcAddress(library, "_ltow");
	p_memccpy = (void *)GetProcAddress(library, "_memccpy");
	p_memicmp = (void *)GetProcAddress(library, "_memicmp");
	p_snprintf = (void *)GetProcAddress(library, "_snprintf");
	p_snprintf_s = (void *)GetProcAddress(library, "_snprintf_s");
	p_snwprintf = (void *)GetProcAddress(library, "_snwprintf");
	p_splitpath = (void *)GetProcAddress(library, "_splitpath");
	p_stricmp = (void *)GetProcAddress(library, "_stricmp");
	p_strlwr = (void *)GetProcAddress(library, "_strlwr");
	p_strnicmp = (void *)GetProcAddress(library, "_strnicmp");
	p_strupr = (void *)GetProcAddress(library, "_strupr");
	p_tolower = (void *)GetProcAddress(library, "_tolower");
	p_toupper = (void *)GetProcAddress(library, "_toupper");
	p_ui64toa = (void *)GetProcAddress(library, "_ui64toa");
	p_ui64tow = (void *)GetProcAddress(library, "_ui64tow");
	p_ultoa = (void *)GetProcAddress(library, "_ultoa");
	p_ultow = (void *)GetProcAddress(library, "_ultow");
	p_vsnprintf = (void *)GetProcAddress(library, "_vsnprintf");
	p_vsnprintf_s = (void *)GetProcAddress(library, "_vsnprintf_s");
	p_vsnwprintf = (void *)GetProcAddress(library, "_vsnwprintf");
	p_wcsicmp = (void *)GetProcAddress(library, "_wcsicmp");
	p_wcslwr = (void *)GetProcAddress(library, "_wcslwr");
	p_wcsnicmp = (void *)GetProcAddress(library, "_wcsnicmp");
	p_wcsupr = (void *)GetProcAddress(library, "_wcsupr");
	p_wtoi = (void *)GetProcAddress(library, "_wtoi");
	p_wtoi64 = (void *)GetProcAddress(library, "_wtoi64");
	p_wtol = (void *)GetProcAddress(library, "_wtol");
	pabs = (void *)GetProcAddress(library, "abs");
	patan = (void *)GetProcAddress(library, "atan");
	patoi = (void *)GetProcAddress(library, "atoi");
	patol = (void *)GetProcAddress(library, "atol");
	pbsearch = (void *)GetProcAddress(library, "bsearch");
	pceil = (void *)GetProcAddress(library, "ceil");
	pcos = (void *)GetProcAddress(library, "cos");
	pfabs = (void *)GetProcAddress(library, "fabs");
	pfloor = (void *)GetProcAddress(library, "floor");
	pisalnum = (void *)GetProcAddress(library, "isalnum");
	pisalpha = (void *)GetProcAddress(library, "isalpha");
	piscntrl = (void *)GetProcAddress(library, "iscntrl");
	pisdigit = (void *)GetProcAddress(library, "isdigit");
	pisgraph = (void *)GetProcAddress(library, "isgraph");
	pislower = (void *)GetProcAddress(library, "islower");
	pisprint = (void *)GetProcAddress(library, "isprint");
	pispunct = (void *)GetProcAddress(library, "ispunct");
	pisspace = (void *)GetProcAddress(library, "isspace");
	pisupper = (void *)GetProcAddress(library, "isupper");
	piswalpha = (void *)GetProcAddress(library, "iswalpha");
	piswctype = (void *)GetProcAddress(library, "iswctype");
	piswdigit = (void *)GetProcAddress(library, "iswdigit");
	piswlower = (void *)GetProcAddress(library, "iswlower");
	piswspace = (void *)GetProcAddress(library, "iswspace");
	piswxdigit = (void *)GetProcAddress(library, "iswxdigit");
	pisxdigit = (void *)GetProcAddress(library, "isxdigit");
	plabs = (void *)GetProcAddress(library, "labs");
	plog = (void *)GetProcAddress(library, "log");
	pmbstowcs = (void *)GetProcAddress(library, "mbstowcs");
	pmemchr = (void *)GetProcAddress(library, "memchr");
	pmemcmp = (void *)GetProcAddress(library, "memcmp");
	pmemcpy = (void *)GetProcAddress(library, "memcpy");
	pmemmove = (void *)GetProcAddress(library, "memmove");
	pmemset = (void *)GetProcAddress(library, "memset");
	ppow = (void *)GetProcAddress(library, "pow");
	pqsort = (void *)GetProcAddress(library, "qsort");
	psin = (void *)GetProcAddress(library, "sin");
	psprintf = (void *)GetProcAddress(library, "sprintf");
	psqrt = (void *)GetProcAddress(library, "sqrt");
	psscanf = (void *)GetProcAddress(library, "sscanf");
	pstrcat = (void *)GetProcAddress(library, "strcat");
	pstrchr = (void *)GetProcAddress(library, "strchr");
	pstrcmp = (void *)GetProcAddress(library, "strcmp");
	pstrcpy = (void *)GetProcAddress(library, "strcpy");
	pstrcspn = (void *)GetProcAddress(library, "strcspn");
	pstrlen = (void *)GetProcAddress(library, "strlen");
	pstrncat = (void *)GetProcAddress(library, "strncat");
	pstrncmp = (void *)GetProcAddress(library, "strncmp");
	pstrncpy = (void *)GetProcAddress(library, "strncpy");
	pstrnlen = (void *)GetProcAddress(library, "strnlen");
	pstrpbrk = (void *)GetProcAddress(library, "strpbrk");
	pstrrchr = (void *)GetProcAddress(library, "strrchr");
	pstrspn = (void *)GetProcAddress(library, "strspn");
	pstrstr = (void *)GetProcAddress(library, "strstr");
	pstrtol = (void *)GetProcAddress(library, "strtol");
	pstrtoul = (void *)GetProcAddress(library, "strtoul");
	pswprintf = (void *)GetProcAddress(library, "swprintf");
	ptan = (void *)GetProcAddress(library, "tan");
	ptolower = (void *)GetProcAddress(library, "tolower");
	ptoupper = (void *)GetProcAddress(library, "toupper");
	ptowlower = (void *)GetProcAddress(library, "towlower");
	ptowupper = (void *)GetProcAddress(library, "towupper");
	pvDbgPrintEx = (void *)GetProcAddress(library, "vDbgPrintEx");
	pvDbgPrintExWithPrefix = (void *)GetProcAddress(library, "vDbgPrintExWithPrefix");
	pvsprintf = (void *)GetProcAddress(library, "vsprintf");
	pwcscat = (void *)GetProcAddress(library, "wcscat");
	pwcschr = (void *)GetProcAddress(library, "wcschr");
	pwcscmp = (void *)GetProcAddress(library, "wcscmp");
	pwcscpy = (void *)GetProcAddress(library, "wcscpy");
	pwcscspn = (void *)GetProcAddress(library, "wcscspn");
	pwcslen = (void *)GetProcAddress(library, "wcslen");
	pwcsncat = (void *)GetProcAddress(library, "wcsncat");
	pwcsncmp = (void *)GetProcAddress(library, "wcsncmp");
	pwcsncpy = (void *)GetProcAddress(library, "wcsncpy");
	pwcspbrk = (void *)GetProcAddress(library, "wcspbrk");
	pwcsrchr = (void *)GetProcAddress(library, "wcsrchr");
	pwcsspn = (void *)GetProcAddress(library, "wcsspn");
	pwcsstr = (void *)GetProcAddress(library, "wcsstr");
	pwcstok = (void *)GetProcAddress(library, "wcstok");
	pwcstol = (void *)GetProcAddress(library, "wcstol");
	pwcstombs = (void *)GetProcAddress(library, "wcstombs");
	pwcstoul = (void *)GetProcAddress(library, "wcstoul");
	pwine_server_call = (void *)GetProcAddress(library, "wine_server_call");
	pwine_server_fd_to_handle = (void *)GetProcAddress(library, "wine_server_fd_to_handle");
	pwine_server_handle_to_fd = (void *)GetProcAddress(library, "wine_server_handle_to_fd");
	pwine_server_release_fd = (void *)GetProcAddress(library, "wine_server_release_fd");
	pwine_server_send_fd = (void *)GetProcAddress(library, "wine_server_send_fd");
	p__wine_make_process_system = (void *)GetProcAddress(library, "__wine_make_process_system");
	p__wine_dbg_get_channel_flags = (void *)GetProcAddress(library, "__wine_dbg_get_channel_flags");
	p__wine_dbg_header = (void *)GetProcAddress(library, "__wine_dbg_header");
	p__wine_dbg_output = (void *)GetProcAddress(library, "__wine_dbg_output");
	p__wine_dbg_strdup = (void *)GetProcAddress(library, "__wine_dbg_strdup");
	p__wine_locked_recvmsg = (void *)GetProcAddress(library, "__wine_locked_recvmsg");
	pwine_get_version = (void *)GetProcAddress(library, "wine_get_version");
	pwine_get_build_id = (void *)GetProcAddress(library, "wine_get_build_id");
	pwine_get_host_version = (void *)GetProcAddress(library, "wine_get_host_version");
	p__wine_init_codepages = (void *)GetProcAddress(library, "__wine_init_codepages");
	p__wine_set_signal_handler = (void *)GetProcAddress(library, "__wine_set_signal_handler");
	pwine_nt_to_unix_file_name = (void *)GetProcAddress(library, "wine_nt_to_unix_file_name");
	pwine_unix_to_nt_file_name = (void *)GetProcAddress(library, "wine_unix_to_nt_file_name");
	initialized = TRUE;
}

void* wine_thunk_get_for_ntdll(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pA_SHAFinal)
		return wine32a_ntdll_A_SHAFinal;
	if (func == pA_SHAInit)
		return wine32a_ntdll_A_SHAInit;
	if (func == pA_SHAUpdate)
		return wine32a_ntdll_A_SHAUpdate;
	if (func == pApiSetQueryApiSetPresence)
		return wine32a_ntdll_ApiSetQueryApiSetPresence;
	if (func == pDbgPrint)
		return wine32a_ntdll_DbgPrint;
	if (func == pDbgPrintEx)
		return wine32a_ntdll_DbgPrintEx;
	if (func == pDbgUiIssueRemoteBreakin)
		return wine32a_ntdll_DbgUiIssueRemoteBreakin;
	if (func == pDbgUiRemoteBreakin)
		return wine32a_ntdll_DbgUiRemoteBreakin;
	if (func == pEtwEventActivityIdControl)
		return wine32a_ntdll_EtwEventActivityIdControl;
	if (func == pEtwEventEnabled)
		return wine32a_ntdll_EtwEventEnabled;
	if (func == pEtwEventProviderEnabled)
		return wine32a_ntdll_EtwEventProviderEnabled;
	if (func == pEtwEventRegister)
		return wine32a_ntdll_EtwEventRegister;
	if (func == pEtwEventSetInformation)
		return wine32a_ntdll_EtwEventSetInformation;
	if (func == pEtwEventUnregister)
		return wine32a_ntdll_EtwEventUnregister;
	if (func == pEtwEventWrite)
		return wine32a_ntdll_EtwEventWrite;
	if (func == pEtwEventWriteString)
		return wine32a_ntdll_EtwEventWriteString;
	if (func == pEtwEventWriteTransfer)
		return wine32a_ntdll_EtwEventWriteTransfer;
	if (func == pEtwGetTraceEnableFlags)
		return wine32a_ntdll_EtwGetTraceEnableFlags;
	if (func == pEtwGetTraceEnableLevel)
		return wine32a_ntdll_EtwGetTraceEnableLevel;
	if (func == pEtwGetTraceLoggerHandle)
		return wine32a_ntdll_EtwGetTraceLoggerHandle;
	if (func == pEtwLogTraceEvent)
		return wine32a_ntdll_EtwLogTraceEvent;
	if (func == pEtwRegisterTraceGuidsA)
		return wine32a_ntdll_EtwRegisterTraceGuidsA;
	if (func == pEtwRegisterTraceGuidsW)
		return wine32a_ntdll_EtwRegisterTraceGuidsW;
	if (func == pEtwTraceMessage)
		return wine32a_ntdll_EtwTraceMessage;
	if (func == pEtwTraceMessageVa)
		return wine32a_ntdll_EtwTraceMessageVa;
	if (func == pEtwUnregisterTraceGuids)
		return wine32a_ntdll_EtwUnregisterTraceGuids;
	if (func == pLdrAccessResource)
		return wine32a_ntdll_LdrAccessResource;
	if (func == pLdrAddRefDll)
		return wine32a_ntdll_LdrAddRefDll;
	if (func == pLdrDisableThreadCalloutsForDll)
		return wine32a_ntdll_LdrDisableThreadCalloutsForDll;
	if (func == pLdrEnumerateLoadedModules)
		return wine32a_ntdll_LdrEnumerateLoadedModules;
	if (func == pLdrFindEntryForAddress)
		return wine32a_ntdll_LdrFindEntryForAddress;
	if (func == pLdrFindResourceDirectory_U)
		return wine32a_ntdll_LdrFindResourceDirectory_U;
	if (func == pLdrFindResource_U)
		return wine32a_ntdll_LdrFindResource_U;
	if (func == pLdrGetDllHandle)
		return wine32a_ntdll_LdrGetDllHandle;
	if (func == pLdrGetProcedureAddress)
		return wine32a_ntdll_LdrGetProcedureAddress;
	if (func == pLdrInitializeThunk)
		return wine32a_ntdll_LdrInitializeThunk;
	if (func == pLdrLoadDll)
		return wine32a_ntdll_LdrLoadDll;
	if (func == pLdrLockLoaderLock)
		return wine32a_ntdll_LdrLockLoaderLock;
	if (func == pLdrProcessRelocationBlock)
		return wine32a_ntdll_LdrProcessRelocationBlock;
	if (func == pLdrQueryImageFileExecutionOptions)
		return wine32a_ntdll_LdrQueryImageFileExecutionOptions;
	if (func == pLdrQueryProcessModuleInformation)
		return wine32a_ntdll_LdrQueryProcessModuleInformation;
	if (func == pLdrRegisterDllNotification)
		return wine32a_ntdll_LdrRegisterDllNotification;
	if (func == pLdrResolveDelayLoadedAPI)
		return wine32a_ntdll_LdrResolveDelayLoadedAPI;
	if (func == pLdrShutdownProcess)
		return wine32a_ntdll_LdrShutdownProcess;
	if (func == pLdrShutdownThread)
		return wine32a_ntdll_LdrShutdownThread;
	if (func == pLdrUnloadDll)
		return wine32a_ntdll_LdrUnloadDll;
	if (func == pLdrUnlockLoaderLock)
		return wine32a_ntdll_LdrUnlockLoaderLock;
	if (func == pLdrUnregisterDllNotification)
		return wine32a_ntdll_LdrUnregisterDllNotification;
	if (func == pMD4Final)
		return wine32a_ntdll_MD4Final;
	if (func == pMD4Init)
		return wine32a_ntdll_MD4Init;
	if (func == pMD4Update)
		return wine32a_ntdll_MD4Update;
	if (func == pMD5Final)
		return wine32a_ntdll_MD5Final;
	if (func == pMD5Init)
		return wine32a_ntdll_MD5Init;
	if (func == pMD5Update)
		return wine32a_ntdll_MD5Update;
	if (func == pNtAcceptConnectPort)
		return wine32a_ntdll_NtAcceptConnectPort;
	if (func == pNtAccessCheck)
		return wine32a_ntdll_NtAccessCheck;
	if (func == pNtAccessCheckAndAuditAlarm)
		return wine32a_ntdll_NtAccessCheckAndAuditAlarm;
	if (func == pNtAddAtom)
		return wine32a_ntdll_NtAddAtom;
	if (func == pNtAdjustGroupsToken)
		return wine32a_ntdll_NtAdjustGroupsToken;
	if (func == pNtAdjustPrivilegesToken)
		return wine32a_ntdll_NtAdjustPrivilegesToken;
	if (func == pNtAlertResumeThread)
		return wine32a_ntdll_NtAlertResumeThread;
	if (func == pNtAlertThread)
		return wine32a_ntdll_NtAlertThread;
	if (func == pNtAllocateLocallyUniqueId)
		return wine32a_ntdll_NtAllocateLocallyUniqueId;
	if (func == pNtAllocateUuids)
		return wine32a_ntdll_NtAllocateUuids;
	if (func == pNtAllocateVirtualMemory)
		return wine32a_ntdll_NtAllocateVirtualMemory;
	if (func == pNtAreMappedFilesTheSame)
		return wine32a_ntdll_NtAreMappedFilesTheSame;
	if (func == pNtAssignProcessToJobObject)
		return wine32a_ntdll_NtAssignProcessToJobObject;
	if (func == pNtCancelIoFile)
		return wine32a_ntdll_NtCancelIoFile;
	if (func == pNtCancelIoFileEx)
		return wine32a_ntdll_NtCancelIoFileEx;
	if (func == pNtCancelTimer)
		return wine32a_ntdll_NtCancelTimer;
	if (func == pNtClearEvent)
		return wine32a_ntdll_NtClearEvent;
	if (func == pNtClearPowerRequest)
		return wine32a_ntdll_NtClearPowerRequest;
	if (func == pNtClose)
		return wine32a_ntdll_NtClose;
	if (func == pNtCompleteConnectPort)
		return wine32a_ntdll_NtCompleteConnectPort;
	if (func == pNtConnectPort)
		return wine32a_ntdll_NtConnectPort;
	if (func == pNtCreateDirectoryObject)
		return wine32a_ntdll_NtCreateDirectoryObject;
	if (func == pNtCreateEvent)
		return wine32a_ntdll_NtCreateEvent;
	if (func == pNtCreateFile)
		return wine32a_ntdll_NtCreateFile;
	if (func == pNtCreateIoCompletion)
		return wine32a_ntdll_NtCreateIoCompletion;
	if (func == pNtCreateJobObject)
		return wine32a_ntdll_NtCreateJobObject;
	if (func == pNtCreateKey)
		return wine32a_ntdll_NtCreateKey;
	if (func == pNtCreateKeyTransacted)
		return wine32a_ntdll_NtCreateKeyTransacted;
	if (func == pNtCreateKeyedEvent)
		return wine32a_ntdll_NtCreateKeyedEvent;
	if (func == pNtCreateLowBoxToken)
		return wine32a_ntdll_NtCreateLowBoxToken;
	if (func == pNtCreateMailslotFile)
		return wine32a_ntdll_NtCreateMailslotFile;
	if (func == pNtCreateMutant)
		return wine32a_ntdll_NtCreateMutant;
	if (func == pNtCreateNamedPipeFile)
		return wine32a_ntdll_NtCreateNamedPipeFile;
	if (func == pNtCreatePagingFile)
		return wine32a_ntdll_NtCreatePagingFile;
	if (func == pNtCreatePort)
		return wine32a_ntdll_NtCreatePort;
	if (func == pNtCreatePowerRequest)
		return wine32a_ntdll_NtCreatePowerRequest;
	if (func == pNtCreateSection)
		return wine32a_ntdll_NtCreateSection;
	if (func == pNtCreateSemaphore)
		return wine32a_ntdll_NtCreateSemaphore;
	if (func == pNtCreateSymbolicLinkObject)
		return wine32a_ntdll_NtCreateSymbolicLinkObject;
	if (func == pNtCreateThreadEx)
		return wine32a_ntdll_NtCreateThreadEx;
	if (func == pNtCreateTimer)
		return wine32a_ntdll_NtCreateTimer;
	if (func == pNtDelayExecution)
		return wine32a_ntdll_NtDelayExecution;
	if (func == pNtDeleteAtom)
		return wine32a_ntdll_NtDeleteAtom;
	if (func == pNtDeleteFile)
		return wine32a_ntdll_NtDeleteFile;
	if (func == pNtDeleteKey)
		return wine32a_ntdll_NtDeleteKey;
	if (func == pNtDeleteValueKey)
		return wine32a_ntdll_NtDeleteValueKey;
	if (func == pNtDeviceIoControlFile)
		return wine32a_ntdll_NtDeviceIoControlFile;
	if (func == pNtDisplayString)
		return wine32a_ntdll_NtDisplayString;
	if (func == pNtDuplicateObject)
		return wine32a_ntdll_NtDuplicateObject;
	if (func == pNtDuplicateToken)
		return wine32a_ntdll_NtDuplicateToken;
	if (func == pNtEnumerateKey)
		return wine32a_ntdll_NtEnumerateKey;
	if (func == pNtEnumerateValueKey)
		return wine32a_ntdll_NtEnumerateValueKey;
	if (func == pNtFindAtom)
		return wine32a_ntdll_NtFindAtom;
	if (func == pNtFlushBuffersFile)
		return wine32a_ntdll_NtFlushBuffersFile;
	if (func == pNtFlushInstructionCache)
		return wine32a_ntdll_NtFlushInstructionCache;
	if (func == pNtFlushKey)
		return wine32a_ntdll_NtFlushKey;
	if (func == pNtFlushVirtualMemory)
		return wine32a_ntdll_NtFlushVirtualMemory;
	if (func == pNtFreeVirtualMemory)
		return wine32a_ntdll_NtFreeVirtualMemory;
	if (func == pNtFsControlFile)
		return wine32a_ntdll_NtFsControlFile;
	if (func == pNtGetContextThread)
		return wine32a_ntdll_NtGetContextThread;
	if (func == pNtGetCurrentProcessorNumber)
		return wine32a_ntdll_NtGetCurrentProcessorNumber;
	if (func == pNtGetTickCount)
		return wine32a_ntdll_NtGetTickCount;
	if (func == pNtGetWriteWatch)
		return wine32a_ntdll_NtGetWriteWatch;
	if (func == pNtImpersonateAnonymousToken)
		return wine32a_ntdll_NtImpersonateAnonymousToken;
	if (func == pNtInitiatePowerAction)
		return wine32a_ntdll_NtInitiatePowerAction;
	if (func == pNtIsProcessInJob)
		return wine32a_ntdll_NtIsProcessInJob;
	if (func == pNtListenPort)
		return wine32a_ntdll_NtListenPort;
	if (func == pNtLoadDriver)
		return wine32a_ntdll_NtLoadDriver;
	if (func == pNtLoadKey2)
		return wine32a_ntdll_NtLoadKey2;
	if (func == pNtLoadKey)
		return wine32a_ntdll_NtLoadKey;
	if (func == pNtLockFile)
		return wine32a_ntdll_NtLockFile;
	if (func == pNtLockVirtualMemory)
		return wine32a_ntdll_NtLockVirtualMemory;
	if (func == pNtMakeTemporaryObject)
		return wine32a_ntdll_NtMakeTemporaryObject;
	if (func == pNtMapViewOfSection)
		return wine32a_ntdll_NtMapViewOfSection;
	if (func == pNtNotifyChangeDirectoryFile)
		return wine32a_ntdll_NtNotifyChangeDirectoryFile;
	if (func == pNtNotifyChangeKey)
		return wine32a_ntdll_NtNotifyChangeKey;
	if (func == pNtNotifyChangeMultipleKeys)
		return wine32a_ntdll_NtNotifyChangeMultipleKeys;
	if (func == pNtOpenDirectoryObject)
		return wine32a_ntdll_NtOpenDirectoryObject;
	if (func == pNtOpenEvent)
		return wine32a_ntdll_NtOpenEvent;
	if (func == pNtOpenFile)
		return wine32a_ntdll_NtOpenFile;
	if (func == pNtOpenIoCompletion)
		return wine32a_ntdll_NtOpenIoCompletion;
	if (func == pNtOpenJobObject)
		return wine32a_ntdll_NtOpenJobObject;
	if (func == pNtOpenKey)
		return wine32a_ntdll_NtOpenKey;
	if (func == pNtOpenKeyEx)
		return wine32a_ntdll_NtOpenKeyEx;
	if (func == pNtOpenKeyTransacted)
		return wine32a_ntdll_NtOpenKeyTransacted;
	if (func == pNtOpenKeyTransactedEx)
		return wine32a_ntdll_NtOpenKeyTransactedEx;
	if (func == pNtOpenKeyedEvent)
		return wine32a_ntdll_NtOpenKeyedEvent;
	if (func == pNtOpenMutant)
		return wine32a_ntdll_NtOpenMutant;
	if (func == pNtOpenProcess)
		return wine32a_ntdll_NtOpenProcess;
	if (func == pNtOpenProcessToken)
		return wine32a_ntdll_NtOpenProcessToken;
	if (func == pNtOpenProcessTokenEx)
		return wine32a_ntdll_NtOpenProcessTokenEx;
	if (func == pNtOpenSection)
		return wine32a_ntdll_NtOpenSection;
	if (func == pNtOpenSemaphore)
		return wine32a_ntdll_NtOpenSemaphore;
	if (func == pNtOpenSymbolicLinkObject)
		return wine32a_ntdll_NtOpenSymbolicLinkObject;
	if (func == pNtOpenThread)
		return wine32a_ntdll_NtOpenThread;
	if (func == pNtOpenThreadToken)
		return wine32a_ntdll_NtOpenThreadToken;
	if (func == pNtOpenThreadTokenEx)
		return wine32a_ntdll_NtOpenThreadTokenEx;
	if (func == pNtOpenTimer)
		return wine32a_ntdll_NtOpenTimer;
	if (func == pNtPowerInformation)
		return wine32a_ntdll_NtPowerInformation;
	if (func == pNtPrivilegeCheck)
		return wine32a_ntdll_NtPrivilegeCheck;
	if (func == pNtProtectVirtualMemory)
		return wine32a_ntdll_NtProtectVirtualMemory;
	if (func == pNtPulseEvent)
		return wine32a_ntdll_NtPulseEvent;
	if (func == pNtQueryAttributesFile)
		return wine32a_ntdll_NtQueryAttributesFile;
	if (func == pNtQueryDefaultLocale)
		return wine32a_ntdll_NtQueryDefaultLocale;
	if (func == pNtQueryDefaultUILanguage)
		return wine32a_ntdll_NtQueryDefaultUILanguage;
	if (func == pNtQueryDirectoryFile)
		return wine32a_ntdll_NtQueryDirectoryFile;
	if (func == pNtQueryDirectoryObject)
		return wine32a_ntdll_NtQueryDirectoryObject;
	if (func == pNtQueryEaFile)
		return wine32a_ntdll_NtQueryEaFile;
	if (func == pNtQueryEvent)
		return wine32a_ntdll_NtQueryEvent;
	if (func == pNtQueryFullAttributesFile)
		return wine32a_ntdll_NtQueryFullAttributesFile;
	if (func == pNtQueryInformationAtom)
		return wine32a_ntdll_NtQueryInformationAtom;
	if (func == pNtQueryInformationFile)
		return wine32a_ntdll_NtQueryInformationFile;
	if (func == pNtQueryInformationJobObject)
		return wine32a_ntdll_NtQueryInformationJobObject;
	if (func == pNtQueryInformationProcess)
		return wine32a_ntdll_NtQueryInformationProcess;
	if (func == pNtQueryInformationThread)
		return wine32a_ntdll_NtQueryInformationThread;
	if (func == pNtQueryInformationToken)
		return wine32a_ntdll_NtQueryInformationToken;
	if (func == pNtQueryInstallUILanguage)
		return wine32a_ntdll_NtQueryInstallUILanguage;
	if (func == pNtQueryIoCompletion)
		return wine32a_ntdll_NtQueryIoCompletion;
	if (func == pNtQueryKey)
		return wine32a_ntdll_NtQueryKey;
	if (func == pNtQueryLicenseValue)
		return wine32a_ntdll_NtQueryLicenseValue;
	if (func == pNtQueryMultipleValueKey)
		return wine32a_ntdll_NtQueryMultipleValueKey;
	if (func == pNtQueryMutant)
		return wine32a_ntdll_NtQueryMutant;
	if (func == pNtQueryObject)
		return wine32a_ntdll_NtQueryObject;
	if (func == pNtQueryPerformanceCounter)
		return wine32a_ntdll_NtQueryPerformanceCounter;
	if (func == pNtQuerySection)
		return wine32a_ntdll_NtQuerySection;
	if (func == pNtQuerySecurityObject)
		return wine32a_ntdll_NtQuerySecurityObject;
	if (func == pNtQuerySemaphore)
		return wine32a_ntdll_NtQuerySemaphore;
	if (func == pNtQuerySymbolicLinkObject)
		return wine32a_ntdll_NtQuerySymbolicLinkObject;
	if (func == pNtQuerySystemEnvironmentValue)
		return wine32a_ntdll_NtQuerySystemEnvironmentValue;
	if (func == pNtQuerySystemEnvironmentValueEx)
		return wine32a_ntdll_NtQuerySystemEnvironmentValueEx;
	if (func == pNtQuerySystemInformation)
		return wine32a_ntdll_NtQuerySystemInformation;
	if (func == pNtQuerySystemInformationEx)
		return wine32a_ntdll_NtQuerySystemInformationEx;
	if (func == pNtQuerySystemTime)
		return wine32a_ntdll_NtQuerySystemTime;
	if (func == pNtQueryTimer)
		return wine32a_ntdll_NtQueryTimer;
	if (func == pNtQueryTimerResolution)
		return wine32a_ntdll_NtQueryTimerResolution;
	if (func == pNtQueryValueKey)
		return wine32a_ntdll_NtQueryValueKey;
	if (func == pNtQueryVirtualMemory)
		return wine32a_ntdll_NtQueryVirtualMemory;
	if (func == pNtQueryVolumeInformationFile)
		return wine32a_ntdll_NtQueryVolumeInformationFile;
	if (func == pNtQueueApcThread)
		return wine32a_ntdll_NtQueueApcThread;
	if (func == pNtRaiseException)
		return wine32a_ntdll_NtRaiseException;
	if (func == pNtRaiseHardError)
		return wine32a_ntdll_NtRaiseHardError;
	if (func == pNtReadFile)
		return wine32a_ntdll_NtReadFile;
	if (func == pNtReadFileScatter)
		return wine32a_ntdll_NtReadFileScatter;
	if (func == pNtReadVirtualMemory)
		return wine32a_ntdll_NtReadVirtualMemory;
	if (func == pNtRegisterThreadTerminatePort)
		return wine32a_ntdll_NtRegisterThreadTerminatePort;
	if (func == pNtReleaseKeyedEvent)
		return wine32a_ntdll_NtReleaseKeyedEvent;
	if (func == pNtReleaseMutant)
		return wine32a_ntdll_NtReleaseMutant;
	if (func == pNtReleaseSemaphore)
		return wine32a_ntdll_NtReleaseSemaphore;
	if (func == pNtRemoveIoCompletion)
		return wine32a_ntdll_NtRemoveIoCompletion;
	if (func == pNtRemoveIoCompletionEx)
		return wine32a_ntdll_NtRemoveIoCompletionEx;
	if (func == pNtRenameKey)
		return wine32a_ntdll_NtRenameKey;
	if (func == pNtReplaceKey)
		return wine32a_ntdll_NtReplaceKey;
	if (func == pNtReplyWaitReceivePort)
		return wine32a_ntdll_NtReplyWaitReceivePort;
	if (func == pNtRequestWaitReplyPort)
		return wine32a_ntdll_NtRequestWaitReplyPort;
	if (func == pNtResetEvent)
		return wine32a_ntdll_NtResetEvent;
	if (func == pNtResetWriteWatch)
		return wine32a_ntdll_NtResetWriteWatch;
	if (func == pNtRestoreKey)
		return wine32a_ntdll_NtRestoreKey;
	if (func == pNtResumeProcess)
		return wine32a_ntdll_NtResumeProcess;
	if (func == pNtResumeThread)
		return wine32a_ntdll_NtResumeThread;
	if (func == pNtSaveKey)
		return wine32a_ntdll_NtSaveKey;
	if (func == pNtSecureConnectPort)
		return wine32a_ntdll_NtSecureConnectPort;
	if (func == pNtSetContextThread)
		return wine32a_ntdll_NtSetContextThread;
	if (func == pNtSetDefaultLocale)
		return wine32a_ntdll_NtSetDefaultLocale;
	if (func == pNtSetDefaultUILanguage)
		return wine32a_ntdll_NtSetDefaultUILanguage;
	if (func == pNtSetEaFile)
		return wine32a_ntdll_NtSetEaFile;
	if (func == pNtSetEvent)
		return wine32a_ntdll_NtSetEvent;
	if (func == pNtSetInformationFile)
		return wine32a_ntdll_NtSetInformationFile;
	if (func == pNtSetInformationJobObject)
		return wine32a_ntdll_NtSetInformationJobObject;
	if (func == pNtSetInformationKey)
		return wine32a_ntdll_NtSetInformationKey;
	if (func == pNtSetInformationObject)
		return wine32a_ntdll_NtSetInformationObject;
	if (func == pNtSetInformationProcess)
		return wine32a_ntdll_NtSetInformationProcess;
	if (func == pNtSetInformationThread)
		return wine32a_ntdll_NtSetInformationThread;
	if (func == pNtSetInformationToken)
		return wine32a_ntdll_NtSetInformationToken;
	if (func == pNtSetIntervalProfile)
		return wine32a_ntdll_NtSetIntervalProfile;
	if (func == pNtSetIoCompletion)
		return wine32a_ntdll_NtSetIoCompletion;
	if (func == pNtSetLdtEntries)
		return wine32a_ntdll_NtSetLdtEntries;
	if (func == pNtSetPowerRequest)
		return wine32a_ntdll_NtSetPowerRequest;
	if (func == pNtSetSecurityObject)
		return wine32a_ntdll_NtSetSecurityObject;
	if (func == pNtSetSystemInformation)
		return wine32a_ntdll_NtSetSystemInformation;
	if (func == pNtSetSystemTime)
		return wine32a_ntdll_NtSetSystemTime;
	if (func == pNtSetThreadExecutionState)
		return wine32a_ntdll_NtSetThreadExecutionState;
	if (func == pNtSetTimer)
		return wine32a_ntdll_NtSetTimer;
	if (func == pNtSetTimerResolution)
		return wine32a_ntdll_NtSetTimerResolution;
	if (func == pNtSetValueKey)
		return wine32a_ntdll_NtSetValueKey;
	if (func == pNtSetVolumeInformationFile)
		return wine32a_ntdll_NtSetVolumeInformationFile;
	if (func == pNtShutdownSystem)
		return wine32a_ntdll_NtShutdownSystem;
	if (func == pNtSignalAndWaitForSingleObject)
		return wine32a_ntdll_NtSignalAndWaitForSingleObject;
	if (func == pNtSuspendProcess)
		return wine32a_ntdll_NtSuspendProcess;
	if (func == pNtSuspendThread)
		return wine32a_ntdll_NtSuspendThread;
	if (func == pNtSystemDebugControl)
		return wine32a_ntdll_NtSystemDebugControl;
	if (func == pNtTerminateJobObject)
		return wine32a_ntdll_NtTerminateJobObject;
	if (func == pNtTerminateProcess)
		return wine32a_ntdll_NtTerminateProcess;
	if (func == pNtTerminateThread)
		return wine32a_ntdll_NtTerminateThread;
	if (func == pNtUnloadDriver)
		return wine32a_ntdll_NtUnloadDriver;
	if (func == pNtUnloadKey)
		return wine32a_ntdll_NtUnloadKey;
	if (func == pNtUnlockFile)
		return wine32a_ntdll_NtUnlockFile;
	if (func == pNtUnlockVirtualMemory)
		return wine32a_ntdll_NtUnlockVirtualMemory;
	if (func == pNtUnmapViewOfSection)
		return wine32a_ntdll_NtUnmapViewOfSection;
	if (func == pNtWaitForKeyedEvent)
		return wine32a_ntdll_NtWaitForKeyedEvent;
	if (func == pNtWaitForMultipleObjects)
		return wine32a_ntdll_NtWaitForMultipleObjects;
	if (func == pNtWaitForSingleObject)
		return wine32a_ntdll_NtWaitForSingleObject;
	if (func == pNtWriteFile)
		return wine32a_ntdll_NtWriteFile;
	if (func == pNtWriteFileGather)
		return wine32a_ntdll_NtWriteFileGather;
	if (func == pNtWriteVirtualMemory)
		return wine32a_ntdll_NtWriteVirtualMemory;
	if (func == pNtYieldExecution)
		return wine32a_ntdll_NtYieldExecution;
	if (func == pRtlAbsoluteToSelfRelativeSD)
		return wine32a_ntdll_RtlAbsoluteToSelfRelativeSD;
	if (func == pRtlAcquirePebLock)
		return wine32a_ntdll_RtlAcquirePebLock;
	if (func == pRtlAcquireResourceExclusive)
		return wine32a_ntdll_RtlAcquireResourceExclusive;
	if (func == pRtlAcquireResourceShared)
		return wine32a_ntdll_RtlAcquireResourceShared;
	if (func == pRtlAcquireSRWLockExclusive)
		return wine32a_ntdll_RtlAcquireSRWLockExclusive;
	if (func == pRtlAcquireSRWLockShared)
		return wine32a_ntdll_RtlAcquireSRWLockShared;
	if (func == pRtlActivateActivationContext)
		return wine32a_ntdll_RtlActivateActivationContext;
	if (func == pRtlAddAccessAllowedAce)
		return wine32a_ntdll_RtlAddAccessAllowedAce;
	if (func == pRtlAddAccessAllowedAceEx)
		return wine32a_ntdll_RtlAddAccessAllowedAceEx;
	if (func == pRtlAddAccessAllowedObjectAce)
		return wine32a_ntdll_RtlAddAccessAllowedObjectAce;
	if (func == pRtlAddAccessDeniedAce)
		return wine32a_ntdll_RtlAddAccessDeniedAce;
	if (func == pRtlAddAccessDeniedAceEx)
		return wine32a_ntdll_RtlAddAccessDeniedAceEx;
	if (func == pRtlAddAccessDeniedObjectAce)
		return wine32a_ntdll_RtlAddAccessDeniedObjectAce;
	if (func == pRtlAddAce)
		return wine32a_ntdll_RtlAddAce;
	if (func == pRtlAddAtomToAtomTable)
		return wine32a_ntdll_RtlAddAtomToAtomTable;
	if (func == pRtlAddAuditAccessAce)
		return wine32a_ntdll_RtlAddAuditAccessAce;
	if (func == pRtlAddAuditAccessAceEx)
		return wine32a_ntdll_RtlAddAuditAccessAceEx;
	if (func == pRtlAddAuditAccessObjectAce)
		return wine32a_ntdll_RtlAddAuditAccessObjectAce;
	if (func == pRtlAddMandatoryAce)
		return wine32a_ntdll_RtlAddMandatoryAce;
	if (func == pRtlAddFunctionTable)
		return wine32a_ntdll_RtlAddFunctionTable;
	if (func == pRtlAddGrowableFunctionTable)
		return wine32a_ntdll_RtlAddGrowableFunctionTable;
	if (func == pRtlAddRefActivationContext)
		return wine32a_ntdll_RtlAddRefActivationContext;
	if (func == pRtlAddVectoredContinueHandler)
		return wine32a_ntdll_RtlAddVectoredContinueHandler;
	if (func == pRtlAddVectoredExceptionHandler)
		return wine32a_ntdll_RtlAddVectoredExceptionHandler;
	if (func == pRtlAdjustPrivilege)
		return wine32a_ntdll_RtlAdjustPrivilege;
	if (func == pRtlAllocateAndInitializeSid)
		return wine32a_ntdll_RtlAllocateAndInitializeSid;
	if (func == pRtlAllocateHandle)
		return wine32a_ntdll_RtlAllocateHandle;
	if (func == pRtlAllocateHeap)
		return wine32a_ntdll_RtlAllocateHeap;
	if (func == pRtlAnsiCharToUnicodeChar)
		return wine32a_ntdll_RtlAnsiCharToUnicodeChar;
	if (func == pRtlAnsiStringToUnicodeSize)
		return wine32a_ntdll_RtlAnsiStringToUnicodeSize;
	if (func == pRtlAnsiStringToUnicodeString)
		return wine32a_ntdll_RtlAnsiStringToUnicodeString;
	if (func == pRtlAppendAsciizToString)
		return wine32a_ntdll_RtlAppendAsciizToString;
	if (func == pRtlAppendStringToString)
		return wine32a_ntdll_RtlAppendStringToString;
	if (func == pRtlAppendUnicodeStringToString)
		return wine32a_ntdll_RtlAppendUnicodeStringToString;
	if (func == pRtlAppendUnicodeToString)
		return wine32a_ntdll_RtlAppendUnicodeToString;
	if (func == pRtlAreAllAccessesGranted)
		return wine32a_ntdll_RtlAreAllAccessesGranted;
	if (func == pRtlAreAnyAccessesGranted)
		return wine32a_ntdll_RtlAreAnyAccessesGranted;
	if (func == pRtlAreBitsClear)
		return wine32a_ntdll_RtlAreBitsClear;
	if (func == pRtlAreBitsSet)
		return wine32a_ntdll_RtlAreBitsSet;
	if (func == pRtlAssert)
		return wine32a_ntdll_RtlAssert;
	if (func == pRtlCaptureStackBackTrace)
		return wine32a_ntdll_RtlCaptureStackBackTrace;
	if (func == pRtlCharToInteger)
		return wine32a_ntdll_RtlCharToInteger;
	if (func == pRtlCheckRegistryKey)
		return wine32a_ntdll_RtlCheckRegistryKey;
	if (func == pRtlClearAllBits)
		return wine32a_ntdll_RtlClearAllBits;
	if (func == pRtlClearBits)
		return wine32a_ntdll_RtlClearBits;
	if (func == pRtlCompactHeap)
		return wine32a_ntdll_RtlCompactHeap;
	if (func == pRtlCompareMemory)
		return wine32a_ntdll_RtlCompareMemory;
	if (func == pRtlCompareMemoryUlong)
		return wine32a_ntdll_RtlCompareMemoryUlong;
	if (func == pRtlCompareString)
		return wine32a_ntdll_RtlCompareString;
	if (func == pRtlCompareUnicodeString)
		return wine32a_ntdll_RtlCompareUnicodeString;
	if (func == pRtlCompareUnicodeStrings)
		return wine32a_ntdll_RtlCompareUnicodeStrings;
	if (func == pRtlCompressBuffer)
		return wine32a_ntdll_RtlCompressBuffer;
	if (func == pRtlComputeCrc32)
		return wine32a_ntdll_RtlComputeCrc32;
	if (func == pRtlConvertSidToUnicodeString)
		return wine32a_ntdll_RtlConvertSidToUnicodeString;
	if (func == pRtlConvertToAutoInheritSecurityObject)
		return wine32a_ntdll_RtlConvertToAutoInheritSecurityObject;
	if (func == pRtlCopyLuid)
		return wine32a_ntdll_RtlCopyLuid;
	if (func == pRtlCopyLuidAndAttributesArray)
		return wine32a_ntdll_RtlCopyLuidAndAttributesArray;
	if (func == pRtlCopyMemory)
		return wine32a_ntdll_RtlCopyMemory;
	if (func == pRtlCopySecurityDescriptor)
		return wine32a_ntdll_RtlCopySecurityDescriptor;
	if (func == pRtlCopySid)
		return wine32a_ntdll_RtlCopySid;
	if (func == pRtlCopyString)
		return wine32a_ntdll_RtlCopyString;
	if (func == pRtlCopyUnicodeString)
		return wine32a_ntdll_RtlCopyUnicodeString;
	if (func == pRtlCreateAcl)
		return wine32a_ntdll_RtlCreateAcl;
	if (func == pRtlCreateActivationContext)
		return wine32a_ntdll_RtlCreateActivationContext;
	if (func == pRtlCreateAtomTable)
		return wine32a_ntdll_RtlCreateAtomTable;
	if (func == pRtlCreateEnvironment)
		return wine32a_ntdll_RtlCreateEnvironment;
	if (func == pRtlCreateHeap)
		return wine32a_ntdll_RtlCreateHeap;
	if (func == pRtlCreateProcessParameters)
		return wine32a_ntdll_RtlCreateProcessParameters;
	if (func == pRtlCreateProcessParametersEx)
		return wine32a_ntdll_RtlCreateProcessParametersEx;
	if (func == pRtlCreateQueryDebugBuffer)
		return wine32a_ntdll_RtlCreateQueryDebugBuffer;
	if (func == pRtlCreateRegistryKey)
		return wine32a_ntdll_RtlCreateRegistryKey;
	if (func == pRtlCreateSecurityDescriptor)
		return wine32a_ntdll_RtlCreateSecurityDescriptor;
	if (func == pRtlCreateTimer)
		return wine32a_ntdll_RtlCreateTimer;
	if (func == pRtlCreateTimerQueue)
		return wine32a_ntdll_RtlCreateTimerQueue;
	if (func == pRtlCreateUnicodeString)
		return wine32a_ntdll_RtlCreateUnicodeString;
	if (func == pRtlCreateUnicodeStringFromAsciiz)
		return wine32a_ntdll_RtlCreateUnicodeStringFromAsciiz;
	if (func == pRtlCreateUserProcess)
		return wine32a_ntdll_RtlCreateUserProcess;
	if (func == pRtlCreateUserStack)
		return wine32a_ntdll_RtlCreateUserStack;
	if (func == pRtlCreateUserThread)
		return wine32a_ntdll_RtlCreateUserThread;
	if (func == pRtlDeNormalizeProcessParams)
		return wine32a_ntdll_RtlDeNormalizeProcessParams;
	if (func == pRtlDeactivateActivationContext)
		return wine32a_ntdll_RtlDeactivateActivationContext;
	if (func == pRtlDecodePointer)
		return wine32a_ntdll_RtlDecodePointer;
	if (func == pRtlDecompressBuffer)
		return wine32a_ntdll_RtlDecompressBuffer;
	if (func == pRtlDecompressFragment)
		return wine32a_ntdll_RtlDecompressFragment;
	if (func == pRtlDeleteAce)
		return wine32a_ntdll_RtlDeleteAce;
	if (func == pRtlDeleteAtomFromAtomTable)
		return wine32a_ntdll_RtlDeleteAtomFromAtomTable;
	if (func == pRtlDeleteCriticalSection)
		return wine32a_ntdll_RtlDeleteCriticalSection;
	if (func == pRtlDeleteGrowableFunctionTable)
		return wine32a_ntdll_RtlDeleteGrowableFunctionTable;
	if (func == pRtlDeleteFunctionTable)
		return wine32a_ntdll_RtlDeleteFunctionTable;
	if (func == pRtlDeleteRegistryValue)
		return wine32a_ntdll_RtlDeleteRegistryValue;
	if (func == pRtlDeleteResource)
		return wine32a_ntdll_RtlDeleteResource;
	if (func == pRtlDeleteSecurityObject)
		return wine32a_ntdll_RtlDeleteSecurityObject;
	if (func == pRtlDeleteTimer)
		return wine32a_ntdll_RtlDeleteTimer;
	if (func == pRtlDeleteTimerQueueEx)
		return wine32a_ntdll_RtlDeleteTimerQueueEx;
	if (func == pRtlDeregisterWait)
		return wine32a_ntdll_RtlDeregisterWait;
	if (func == pRtlDeregisterWaitEx)
		return wine32a_ntdll_RtlDeregisterWaitEx;
	if (func == pRtlDestroyAtomTable)
		return wine32a_ntdll_RtlDestroyAtomTable;
	if (func == pRtlDestroyEnvironment)
		return wine32a_ntdll_RtlDestroyEnvironment;
	if (func == pRtlDestroyHandleTable)
		return wine32a_ntdll_RtlDestroyHandleTable;
	if (func == pRtlDestroyHeap)
		return wine32a_ntdll_RtlDestroyHeap;
	if (func == pRtlDestroyProcessParameters)
		return wine32a_ntdll_RtlDestroyProcessParameters;
	if (func == pRtlDestroyQueryDebugBuffer)
		return wine32a_ntdll_RtlDestroyQueryDebugBuffer;
	if (func == pRtlDetermineDosPathNameType_U)
		return wine32a_ntdll_RtlDetermineDosPathNameType_U;
	if (func == pRtlDllShutdownInProgress)
		return wine32a_ntdll_RtlDllShutdownInProgress;
	if (func == pRtlDoesFileExists_U)
		return wine32a_ntdll_RtlDoesFileExists_U;
	if (func == pRtlDosPathNameToNtPathName_U)
		return wine32a_ntdll_RtlDosPathNameToNtPathName_U;
	if (func == pRtlDosPathNameToNtPathName_U_WithStatus)
		return wine32a_ntdll_RtlDosPathNameToNtPathName_U_WithStatus;
	if (func == pRtlDosPathNameToRelativeNtPathName_U_WithStatus)
		return wine32a_ntdll_RtlDosPathNameToRelativeNtPathName_U_WithStatus;
	if (func == pRtlDosSearchPath_U)
		return wine32a_ntdll_RtlDosSearchPath_U;
	if (func == pRtlDowncaseUnicodeChar)
		return wine32a_ntdll_RtlDowncaseUnicodeChar;
	if (func == pRtlDowncaseUnicodeString)
		return wine32a_ntdll_RtlDowncaseUnicodeString;
	if (func == pRtlDumpResource)
		return wine32a_ntdll_RtlDumpResource;
	if (func == pRtlDuplicateUnicodeString)
		return wine32a_ntdll_RtlDuplicateUnicodeString;
	if (func == pRtlEmptyAtomTable)
		return wine32a_ntdll_RtlEmptyAtomTable;
	if (func == pRtlEncodePointer)
		return wine32a_ntdll_RtlEncodePointer;
	if (func == pRtlEnterCriticalSection)
		return wine32a_ntdll_RtlEnterCriticalSection;
	if (func == pRtlEnumerateGenericTableWithoutSplaying)
		return wine32a_ntdll_RtlEnumerateGenericTableWithoutSplaying;
	if (func == pRtlEqualComputerName)
		return wine32a_ntdll_RtlEqualComputerName;
	if (func == pRtlEqualDomainName)
		return wine32a_ntdll_RtlEqualDomainName;
	if (func == pRtlEqualLuid)
		return wine32a_ntdll_RtlEqualLuid;
	if (func == pRtlEqualPrefixSid)
		return wine32a_ntdll_RtlEqualPrefixSid;
	if (func == pRtlEqualSid)
		return wine32a_ntdll_RtlEqualSid;
	if (func == pRtlEqualString)
		return wine32a_ntdll_RtlEqualString;
	if (func == pRtlEqualUnicodeString)
		return wine32a_ntdll_RtlEqualUnicodeString;
	if (func == pRtlEraseUnicodeString)
		return wine32a_ntdll_RtlEraseUnicodeString;
	if (func == pRtlExitUserProcess)
		return wine32a_ntdll_RtlExitUserProcess;
	if (func == pRtlExitUserThread)
		return wine32a_ntdll_RtlExitUserThread;
	if (func == pRtlExpandEnvironmentStrings)
		return wine32a_ntdll_RtlExpandEnvironmentStrings;
	if (func == pRtlExpandEnvironmentStrings_U)
		return wine32a_ntdll_RtlExpandEnvironmentStrings_U;
	if (func == pRtlFillMemory)
		return wine32a_ntdll_RtlFillMemory;
	if (func == pRtlFillMemoryUlong)
		return wine32a_ntdll_RtlFillMemoryUlong;
	if (func == pRtlFindActivationContextSectionGuid)
		return wine32a_ntdll_RtlFindActivationContextSectionGuid;
	if (func == pRtlFindActivationContextSectionString)
		return wine32a_ntdll_RtlFindActivationContextSectionString;
	if (func == pRtlFindCharInUnicodeString)
		return wine32a_ntdll_RtlFindCharInUnicodeString;
	if (func == pRtlFindClearBits)
		return wine32a_ntdll_RtlFindClearBits;
	if (func == pRtlFindClearBitsAndSet)
		return wine32a_ntdll_RtlFindClearBitsAndSet;
	if (func == pRtlFindClearRuns)
		return wine32a_ntdll_RtlFindClearRuns;
	if (func == pRtlFindLastBackwardRunClear)
		return wine32a_ntdll_RtlFindLastBackwardRunClear;
	if (func == pRtlFindLastBackwardRunSet)
		return wine32a_ntdll_RtlFindLastBackwardRunSet;
	if (func == pRtlFindLeastSignificantBit)
		return wine32a_ntdll_RtlFindLeastSignificantBit;
	if (func == pRtlFindLongestRunClear)
		return wine32a_ntdll_RtlFindLongestRunClear;
	if (func == pRtlFindLongestRunSet)
		return wine32a_ntdll_RtlFindLongestRunSet;
	if (func == pRtlFindMessage)
		return wine32a_ntdll_RtlFindMessage;
	if (func == pRtlFindMostSignificantBit)
		return wine32a_ntdll_RtlFindMostSignificantBit;
	if (func == pRtlFindNextForwardRunClear)
		return wine32a_ntdll_RtlFindNextForwardRunClear;
	if (func == pRtlFindNextForwardRunSet)
		return wine32a_ntdll_RtlFindNextForwardRunSet;
	if (func == pRtlFindSetBits)
		return wine32a_ntdll_RtlFindSetBits;
	if (func == pRtlFindSetBitsAndClear)
		return wine32a_ntdll_RtlFindSetBitsAndClear;
	if (func == pRtlFindSetRuns)
		return wine32a_ntdll_RtlFindSetRuns;
	if (func == pRtlFirstEntrySList)
		return wine32a_ntdll_RtlFirstEntrySList;
	if (func == pRtlFirstFreeAce)
		return wine32a_ntdll_RtlFirstFreeAce;
	if (func == pRtlFormatCurrentUserKeyPath)
		return wine32a_ntdll_RtlFormatCurrentUserKeyPath;
	if (func == pRtlFormatMessage)
		return wine32a_ntdll_RtlFormatMessage;
	if (func == pRtlFreeAnsiString)
		return wine32a_ntdll_RtlFreeAnsiString;
	if (func == pRtlFreeHandle)
		return wine32a_ntdll_RtlFreeHandle;
	if (func == pRtlFreeHeap)
		return wine32a_ntdll_RtlFreeHeap;
	if (func == pRtlFreeOemString)
		return wine32a_ntdll_RtlFreeOemString;
	if (func == pRtlFreeSid)
		return wine32a_ntdll_RtlFreeSid;
	if (func == pRtlFreeThreadActivationContextStack)
		return wine32a_ntdll_RtlFreeThreadActivationContextStack;
	if (func == pRtlFreeUnicodeString)
		return wine32a_ntdll_RtlFreeUnicodeString;
	if (func == pRtlFreeUserStack)
		return wine32a_ntdll_RtlFreeUserStack;
	if (func == pRtlGUIDFromString)
		return wine32a_ntdll_RtlGUIDFromString;
	if (func == pRtlGetAce)
		return wine32a_ntdll_RtlGetAce;
	if (func == pRtlGetActiveActivationContext)
		return wine32a_ntdll_RtlGetActiveActivationContext;
	if (func == pRtlGetCompressionWorkSpaceSize)
		return wine32a_ntdll_RtlGetCompressionWorkSpaceSize;
	if (func == pRtlGetControlSecurityDescriptor)
		return wine32a_ntdll_RtlGetControlSecurityDescriptor;
	if (func == pRtlGetCurrentDirectory_U)
		return wine32a_ntdll_RtlGetCurrentDirectory_U;
	if (func == pRtlGetCurrentPeb)
		return wine32a_ntdll_RtlGetCurrentPeb;
	if (func == pRtlGetCurrentProcessorNumberEx)
		return wine32a_ntdll_RtlGetCurrentProcessorNumberEx;
	if (func == pRtlGetCurrentTransaction)
		return wine32a_ntdll_RtlGetCurrentTransaction;
	if (func == pRtlGetDaclSecurityDescriptor)
		return wine32a_ntdll_RtlGetDaclSecurityDescriptor;
	if (func == pRtlGetFrame)
		return wine32a_ntdll_RtlGetFrame;
	if (func == pRtlGetFullPathName_U)
		return wine32a_ntdll_RtlGetFullPathName_U;
	if (func == pRtlGetGroupSecurityDescriptor)
		return wine32a_ntdll_RtlGetGroupSecurityDescriptor;
	if (func == pRtlGetLastNtStatus)
		return wine32a_ntdll_RtlGetLastNtStatus;
	if (func == pRtlGetLastWin32Error)
		return wine32a_ntdll_RtlGetLastWin32Error;
	if (func == pRtlGetLongestNtPathLength)
		return wine32a_ntdll_RtlGetLongestNtPathLength;
	if (func == pRtlGetNtGlobalFlags)
		return wine32a_ntdll_RtlGetNtGlobalFlags;
	if (func == pRtlGetNtProductType)
		return wine32a_ntdll_RtlGetNtProductType;
	if (func == pRtlGetNtVersionNumbers)
		return wine32a_ntdll_RtlGetNtVersionNumbers;
	if (func == pRtlGetOwnerSecurityDescriptor)
		return wine32a_ntdll_RtlGetOwnerSecurityDescriptor;
	if (func == pRtlGetProductInfo)
		return wine32a_ntdll_RtlGetProductInfo;
	if (func == pRtlGetProcessHeaps)
		return wine32a_ntdll_RtlGetProcessHeaps;
	if (func == pRtlGetSaclSecurityDescriptor)
		return wine32a_ntdll_RtlGetSaclSecurityDescriptor;
	if (func == pRtlGetSystemTimePrecise)
		return wine32a_ntdll_RtlGetSystemTimePrecise;
	if (func == pRtlGetThreadErrorMode)
		return wine32a_ntdll_RtlGetThreadErrorMode;
	if (func == pRtlGetUnloadEventTrace)
		return wine32a_ntdll_RtlGetUnloadEventTrace;
	if (func == pRtlGetUnloadEventTraceEx)
		return wine32a_ntdll_RtlGetUnloadEventTraceEx;
	if (func == pRtlGetVersion)
		return wine32a_ntdll_RtlGetVersion;
	if (func == pRtlGrowFunctionTable)
		return wine32a_ntdll_RtlGrowFunctionTable;
	if (func == pRtlHashUnicodeString)
		return wine32a_ntdll_RtlHashUnicodeString;
	if (func == pRtlIdentifierAuthoritySid)
		return wine32a_ntdll_RtlIdentifierAuthoritySid;
	if (func == pRtlImageDirectoryEntryToData)
		return wine32a_ntdll_RtlImageDirectoryEntryToData;
	if (func == pRtlImageNtHeader)
		return wine32a_ntdll_RtlImageNtHeader;
	if (func == pRtlImageRvaToSection)
		return wine32a_ntdll_RtlImageRvaToSection;
	if (func == pRtlImageRvaToVa)
		return wine32a_ntdll_RtlImageRvaToVa;
	if (func == pRtlImpersonateSelf)
		return wine32a_ntdll_RtlImpersonateSelf;
	if (func == pRtlInitAnsiString)
		return wine32a_ntdll_RtlInitAnsiString;
	if (func == pRtlInitAnsiStringEx)
		return wine32a_ntdll_RtlInitAnsiStringEx;
	if (func == pRtlInitString)
		return wine32a_ntdll_RtlInitString;
	if (func == pRtlInitUnicodeString)
		return wine32a_ntdll_RtlInitUnicodeString;
	if (func == pRtlInitUnicodeStringEx)
		return wine32a_ntdll_RtlInitUnicodeStringEx;
	if (func == pRtlInitializeBitMap)
		return wine32a_ntdll_RtlInitializeBitMap;
	if (func == pRtlInitializeConditionVariable)
		return wine32a_ntdll_RtlInitializeConditionVariable;
	if (func == pRtlInitializeCriticalSection)
		return wine32a_ntdll_RtlInitializeCriticalSection;
	if (func == pRtlInitializeCriticalSectionAndSpinCount)
		return wine32a_ntdll_RtlInitializeCriticalSectionAndSpinCount;
	if (func == pRtlInitializeCriticalSectionEx)
		return wine32a_ntdll_RtlInitializeCriticalSectionEx;
	if (func == pRtlInitializeGenericTable)
		return wine32a_ntdll_RtlInitializeGenericTable;
	if (func == pRtlInitializeGenericTableAvl)
		return wine32a_ntdll_RtlInitializeGenericTableAvl;
	if (func == pRtlInitializeHandleTable)
		return wine32a_ntdll_RtlInitializeHandleTable;
	if (func == pRtlInitializeResource)
		return wine32a_ntdll_RtlInitializeResource;
	if (func == pRtlInitializeSListHead)
		return wine32a_ntdll_RtlInitializeSListHead;
	if (func == pRtlInitializeSRWLock)
		return wine32a_ntdll_RtlInitializeSRWLock;
	if (func == pRtlInitializeSid)
		return wine32a_ntdll_RtlInitializeSid;
	if (func == pRtlInsertElementGenericTableAvl)
		return wine32a_ntdll_RtlInsertElementGenericTableAvl;
	if (func == pRtlInstallFunctionTableCallback)
		return wine32a_ntdll_RtlInstallFunctionTableCallback;
	if (func == pRtlInt64ToUnicodeString)
		return wine32a_ntdll_RtlInt64ToUnicodeString;
	if (func == pRtlIntegerToChar)
		return wine32a_ntdll_RtlIntegerToChar;
	if (func == pRtlIntegerToUnicodeString)
		return wine32a_ntdll_RtlIntegerToUnicodeString;
	if (func == pRtlInterlockedFlushSList)
		return wine32a_ntdll_RtlInterlockedFlushSList;
	if (func == pRtlInterlockedPopEntrySList)
		return wine32a_ntdll_RtlInterlockedPopEntrySList;
	if (func == pRtlInterlockedPushEntrySList)
		return wine32a_ntdll_RtlInterlockedPushEntrySList;
	if (func == pRtlInterlockedPushListSList)
		return wine32a_ntdll_RtlInterlockedPushListSList;
	if (func == pRtlInterlockedPushListSListEx)
		return wine32a_ntdll_RtlInterlockedPushListSListEx;
	if (func == pRtlIpv4AddressToStringA)
		return wine32a_ntdll_RtlIpv4AddressToStringA;
	if (func == pRtlIpv4AddressToStringExA)
		return wine32a_ntdll_RtlIpv4AddressToStringExA;
	if (func == pRtlIpv4AddressToStringExW)
		return wine32a_ntdll_RtlIpv4AddressToStringExW;
	if (func == pRtlIpv4AddressToStringW)
		return wine32a_ntdll_RtlIpv4AddressToStringW;
	if (func == pRtlIpv4StringToAddressA)
		return wine32a_ntdll_RtlIpv4StringToAddressA;
	if (func == pRtlIpv4StringToAddressExA)
		return wine32a_ntdll_RtlIpv4StringToAddressExA;
	if (func == pRtlIpv4StringToAddressExW)
		return wine32a_ntdll_RtlIpv4StringToAddressExW;
	if (func == pRtlIpv4StringToAddressW)
		return wine32a_ntdll_RtlIpv4StringToAddressW;
	if (func == pRtlIpv6StringToAddressExW)
		return wine32a_ntdll_RtlIpv6StringToAddressExW;
	if (func == pRtlIsActivationContextActive)
		return wine32a_ntdll_RtlIsActivationContextActive;
	if (func == pRtlIsCriticalSectionLocked)
		return wine32a_ntdll_RtlIsCriticalSectionLocked;
	if (func == pRtlIsCriticalSectionLockedByThread)
		return wine32a_ntdll_RtlIsCriticalSectionLockedByThread;
	if (func == pRtlIsDosDeviceName_U)
		return wine32a_ntdll_RtlIsDosDeviceName_U;
	if (func == pRtlIsNameLegalDOS8Dot3)
		return wine32a_ntdll_RtlIsNameLegalDOS8Dot3;
	if (func == pRtlIsProcessorFeaturePresent)
		return wine32a_ntdll_RtlIsProcessorFeaturePresent;
	if (func == pRtlIsTextUnicode)
		return wine32a_ntdll_RtlIsTextUnicode;
	if (func == pRtlIsValidHandle)
		return wine32a_ntdll_RtlIsValidHandle;
	if (func == pRtlIsValidIndexHandle)
		return wine32a_ntdll_RtlIsValidIndexHandle;
	if (func == pRtlLargeIntegerToChar)
		return wine32a_ntdll_RtlLargeIntegerToChar;
	if (func == pRtlLeaveCriticalSection)
		return wine32a_ntdll_RtlLeaveCriticalSection;
	if (func == pRtlLengthRequiredSid)
		return wine32a_ntdll_RtlLengthRequiredSid;
	if (func == pRtlLengthSecurityDescriptor)
		return wine32a_ntdll_RtlLengthSecurityDescriptor;
	if (func == pRtlLengthSid)
		return wine32a_ntdll_RtlLengthSid;
	if (func == pRtlLocalTimeToSystemTime)
		return wine32a_ntdll_RtlLocalTimeToSystemTime;
	if (func == pRtlLockHeap)
		return wine32a_ntdll_RtlLockHeap;
	if (func == pRtlLookupAtomInAtomTable)
		return wine32a_ntdll_RtlLookupAtomInAtomTable;
	if (func == pRtlLookupFunctionEntry)
		return wine32a_ntdll_RtlLookupFunctionEntry;
	if (func == pRtlMakeSelfRelativeSD)
		return wine32a_ntdll_RtlMakeSelfRelativeSD;
	if (func == pRtlMapGenericMask)
		return wine32a_ntdll_RtlMapGenericMask;
	if (func == pRtlMoveMemory)
		return wine32a_ntdll_RtlMoveMemory;
	if (func == pRtlMultiByteToUnicodeN)
		return wine32a_ntdll_RtlMultiByteToUnicodeN;
	if (func == pRtlMultiByteToUnicodeSize)
		return wine32a_ntdll_RtlMultiByteToUnicodeSize;
	if (func == pRtlNewSecurityObject)
		return wine32a_ntdll_RtlNewSecurityObject;
	if (func == pRtlNormalizeProcessParams)
		return wine32a_ntdll_RtlNormalizeProcessParams;
	if (func == pRtlNtStatusToDosError)
		return wine32a_ntdll_RtlNtStatusToDosError;
	if (func == pRtlNtStatusToDosErrorNoTeb)
		return wine32a_ntdll_RtlNtStatusToDosErrorNoTeb;
	if (func == pRtlNumberGenericTableElements)
		return wine32a_ntdll_RtlNumberGenericTableElements;
	if (func == pRtlNumberOfClearBits)
		return wine32a_ntdll_RtlNumberOfClearBits;
	if (func == pRtlNumberOfSetBits)
		return wine32a_ntdll_RtlNumberOfSetBits;
	if (func == pRtlOemStringToUnicodeSize)
		return wine32a_ntdll_RtlOemStringToUnicodeSize;
	if (func == pRtlOemStringToUnicodeString)
		return wine32a_ntdll_RtlOemStringToUnicodeString;
	if (func == pRtlOemToUnicodeN)
		return wine32a_ntdll_RtlOemToUnicodeN;
	if (func == pRtlOpenCurrentUser)
		return wine32a_ntdll_RtlOpenCurrentUser;
	if (func == pRtlPcToFileHeader)
		return wine32a_ntdll_RtlPcToFileHeader;
	if (func == pRtlPinAtomInAtomTable)
		return wine32a_ntdll_RtlPinAtomInAtomTable;
	if (func == pRtlPopFrame)
		return wine32a_ntdll_RtlPopFrame;
	if (func == pRtlPrefixString)
		return wine32a_ntdll_RtlPrefixString;
	if (func == pRtlPrefixUnicodeString)
		return wine32a_ntdll_RtlPrefixUnicodeString;
	if (func == pRtlPushFrame)
		return wine32a_ntdll_RtlPushFrame;
	if (func == pRtlQueryActivationContextApplicationSettings)
		return wine32a_ntdll_RtlQueryActivationContextApplicationSettings;
	if (func == pRtlQueryAtomInAtomTable)
		return wine32a_ntdll_RtlQueryAtomInAtomTable;
	if (func == pRtlQueryDepthSList)
		return wine32a_ntdll_RtlQueryDepthSList;
	if (func == pRtlQueryDynamicTimeZoneInformation)
		return wine32a_ntdll_RtlQueryDynamicTimeZoneInformation;
	if (func == pRtlQueryEnvironmentVariable_U)
		return wine32a_ntdll_RtlQueryEnvironmentVariable_U;
	if (func == pRtlQueryHeapInformation)
		return wine32a_ntdll_RtlQueryHeapInformation;
	if (func == pRtlQueryInformationAcl)
		return wine32a_ntdll_RtlQueryInformationAcl;
	if (func == pRtlQueryInformationActivationContext)
		return wine32a_ntdll_RtlQueryInformationActivationContext;
	if (func == pRtlQueryPackageIdentity)
		return wine32a_ntdll_RtlQueryPackageIdentity;
	if (func == pRtlQueryPerformanceCounter)
		return wine32a_ntdll_RtlQueryPerformanceCounter;
	if (func == pRtlQueryPerformanceFrequency)
		return wine32a_ntdll_RtlQueryPerformanceFrequency;
	if (func == pRtlQueryProcessDebugInformation)
		return wine32a_ntdll_RtlQueryProcessDebugInformation;
	if (func == pRtlQueryRegistryValues)
		return wine32a_ntdll_RtlQueryRegistryValues;
	if (func == pRtlQueryTimeZoneInformation)
		return wine32a_ntdll_RtlQueryTimeZoneInformation;
	if (func == pRtlQueryUnbiasedInterruptTime)
		return wine32a_ntdll_RtlQueryUnbiasedInterruptTime;
	if (func == pRtlQueueWorkItem)
		return wine32a_ntdll_RtlQueueWorkItem;
	if (func == pRtlRaiseStatus)
		return wine32a_ntdll_RtlRaiseStatus;
	if (func == pRtlRandom)
		return wine32a_ntdll_RtlRandom;
	if (func == pRtlRandomEx)
		return wine32a_ntdll_RtlRandomEx;
	if (func == pRtlReAllocateHeap)
		return wine32a_ntdll_RtlReAllocateHeap;
	if (func == pRtlRegisterWait)
		return wine32a_ntdll_RtlRegisterWait;
	if (func == pRtlReleaseActivationContext)
		return wine32a_ntdll_RtlReleaseActivationContext;
	if (func == pRtlReleasePebLock)
		return wine32a_ntdll_RtlReleasePebLock;
	if (func == pRtlReleaseRelativeName)
		return wine32a_ntdll_RtlReleaseRelativeName;
	if (func == pRtlReleaseResource)
		return wine32a_ntdll_RtlReleaseResource;
	if (func == pRtlReleaseSRWLockExclusive)
		return wine32a_ntdll_RtlReleaseSRWLockExclusive;
	if (func == pRtlReleaseSRWLockShared)
		return wine32a_ntdll_RtlReleaseSRWLockShared;
	if (func == pRtlRemoveVectoredContinueHandler)
		return wine32a_ntdll_RtlRemoveVectoredContinueHandler;
	if (func == pRtlRemoveVectoredExceptionHandler)
		return wine32a_ntdll_RtlRemoveVectoredExceptionHandler;
	if (func == pRtlRestoreContext)
		return wine32a_ntdll_RtlRestoreContext;
	if (func == pRtlRunOnceBeginInitialize)
		return wine32a_ntdll_RtlRunOnceBeginInitialize;
	if (func == pRtlRunOnceComplete)
		return wine32a_ntdll_RtlRunOnceComplete;
	if (func == pRtlRunOnceExecuteOnce)
		return wine32a_ntdll_RtlRunOnceExecuteOnce;
	if (func == pRtlRunOnceInitialize)
		return wine32a_ntdll_RtlRunOnceInitialize;
	if (func == pRtlSecondsSince1970ToTime)
		return wine32a_ntdll_RtlSecondsSince1970ToTime;
	if (func == pRtlSecondsSince1980ToTime)
		return wine32a_ntdll_RtlSecondsSince1980ToTime;
	if (func == pRtlSelfRelativeToAbsoluteSD)
		return wine32a_ntdll_RtlSelfRelativeToAbsoluteSD;
	if (func == pRtlSetAllBits)
		return wine32a_ntdll_RtlSetAllBits;
	if (func == pRtlSetBits)
		return wine32a_ntdll_RtlSetBits;
	if (func == pRtlSetControlSecurityDescriptor)
		return wine32a_ntdll_RtlSetControlSecurityDescriptor;
	if (func == pRtlSetCriticalSectionSpinCount)
		return wine32a_ntdll_RtlSetCriticalSectionSpinCount;
	if (func == pRtlSetCurrentDirectory_U)
		return wine32a_ntdll_RtlSetCurrentDirectory_U;
	if (func == pRtlSetCurrentEnvironment)
		return wine32a_ntdll_RtlSetCurrentEnvironment;
	if (func == pRtlSetCurrentTransaction)
		return wine32a_ntdll_RtlSetCurrentTransaction;
	if (func == pRtlSetDaclSecurityDescriptor)
		return wine32a_ntdll_RtlSetDaclSecurityDescriptor;
	if (func == pRtlSetEnvironmentVariable)
		return wine32a_ntdll_RtlSetEnvironmentVariable;
	if (func == pRtlSetGroupSecurityDescriptor)
		return wine32a_ntdll_RtlSetGroupSecurityDescriptor;
	if (func == pRtlSetHeapInformation)
		return wine32a_ntdll_RtlSetHeapInformation;
	if (func == pRtlSetIoCompletionCallback)
		return wine32a_ntdll_RtlSetIoCompletionCallback;
	if (func == pRtlSetLastWin32Error)
		return wine32a_ntdll_RtlSetLastWin32Error;
	if (func == pRtlSetLastWin32ErrorAndNtStatusFromNtStatus)
		return wine32a_ntdll_RtlSetLastWin32ErrorAndNtStatusFromNtStatus;
	if (func == pRtlSetOwnerSecurityDescriptor)
		return wine32a_ntdll_RtlSetOwnerSecurityDescriptor;
	if (func == pRtlSetSaclSecurityDescriptor)
		return wine32a_ntdll_RtlSetSaclSecurityDescriptor;
	if (func == pRtlSetThreadErrorMode)
		return wine32a_ntdll_RtlSetThreadErrorMode;
	if (func == pRtlSetTimeZoneInformation)
		return wine32a_ntdll_RtlSetTimeZoneInformation;
	if (func == pRtlSetUnhandledExceptionFilter)
		return wine32a_ntdll_RtlSetUnhandledExceptionFilter;
	if (func == pRtlSizeHeap)
		return wine32a_ntdll_RtlSizeHeap;
	if (func == pRtlSleepConditionVariableCS)
		return wine32a_ntdll_RtlSleepConditionVariableCS;
	if (func == pRtlSleepConditionVariableSRW)
		return wine32a_ntdll_RtlSleepConditionVariableSRW;
	if (func == pRtlStringFromGUID)
		return wine32a_ntdll_RtlStringFromGUID;
	if (func == pRtlSubAuthorityCountSid)
		return wine32a_ntdll_RtlSubAuthorityCountSid;
	if (func == pRtlSubAuthoritySid)
		return wine32a_ntdll_RtlSubAuthoritySid;
	if (func == pRtlSystemTimeToLocalTime)
		return wine32a_ntdll_RtlSystemTimeToLocalTime;
	if (func == pRtlTimeFieldsToTime)
		return wine32a_ntdll_RtlTimeFieldsToTime;
	if (func == pRtlTimeToElapsedTimeFields)
		return wine32a_ntdll_RtlTimeToElapsedTimeFields;
	if (func == pRtlTimeToSecondsSince1970)
		return wine32a_ntdll_RtlTimeToSecondsSince1970;
	if (func == pRtlTimeToSecondsSince1980)
		return wine32a_ntdll_RtlTimeToSecondsSince1980;
	if (func == pRtlTimeToTimeFields)
		return wine32a_ntdll_RtlTimeToTimeFields;
	if (func == pRtlTryAcquireSRWLockExclusive)
		return wine32a_ntdll_RtlTryAcquireSRWLockExclusive;
	if (func == pRtlTryAcquireSRWLockShared)
		return wine32a_ntdll_RtlTryAcquireSRWLockShared;
	if (func == pRtlTryEnterCriticalSection)
		return wine32a_ntdll_RtlTryEnterCriticalSection;
	if (func == pRtlUlonglongByteSwap)
		return wine32a_ntdll_RtlUlonglongByteSwap;
	if (func == pRtlUnicodeStringToAnsiSize)
		return wine32a_ntdll_RtlUnicodeStringToAnsiSize;
	if (func == pRtlUnicodeStringToAnsiString)
		return wine32a_ntdll_RtlUnicodeStringToAnsiString;
	if (func == pRtlUnicodeStringToInteger)
		return wine32a_ntdll_RtlUnicodeStringToInteger;
	if (func == pRtlUnicodeStringToOemSize)
		return wine32a_ntdll_RtlUnicodeStringToOemSize;
	if (func == pRtlUnicodeStringToOemString)
		return wine32a_ntdll_RtlUnicodeStringToOemString;
	if (func == pRtlUnicodeToMultiByteN)
		return wine32a_ntdll_RtlUnicodeToMultiByteN;
	if (func == pRtlUnicodeToMultiByteSize)
		return wine32a_ntdll_RtlUnicodeToMultiByteSize;
	if (func == pRtlUnicodeToOemN)
		return wine32a_ntdll_RtlUnicodeToOemN;
	if (func == pRtlUnicodeToUTF8N)
		return wine32a_ntdll_RtlUnicodeToUTF8N;
	if (func == pRtlUniform)
		return wine32a_ntdll_RtlUniform;
	if (func == pRtlUnlockHeap)
		return wine32a_ntdll_RtlUnlockHeap;
	if (func == pRtlUnwind)
		return wine32a_ntdll_RtlUnwind;
	if (func == pRtlUnwindEx)
		return wine32a_ntdll_RtlUnwindEx;
	if (func == pRtlUpcaseUnicodeChar)
		return wine32a_ntdll_RtlUpcaseUnicodeChar;
	if (func == pRtlUpcaseUnicodeString)
		return wine32a_ntdll_RtlUpcaseUnicodeString;
	if (func == pRtlUpcaseUnicodeStringToAnsiString)
		return wine32a_ntdll_RtlUpcaseUnicodeStringToAnsiString;
	if (func == pRtlUpcaseUnicodeStringToCountedOemString)
		return wine32a_ntdll_RtlUpcaseUnicodeStringToCountedOemString;
	if (func == pRtlUpcaseUnicodeStringToOemString)
		return wine32a_ntdll_RtlUpcaseUnicodeStringToOemString;
	if (func == pRtlUpcaseUnicodeToMultiByteN)
		return wine32a_ntdll_RtlUpcaseUnicodeToMultiByteN;
	if (func == pRtlUpcaseUnicodeToOemN)
		return wine32a_ntdll_RtlUpcaseUnicodeToOemN;
	if (func == pRtlUpdateTimer)
		return wine32a_ntdll_RtlUpdateTimer;
	if (func == pRtlUpperChar)
		return wine32a_ntdll_RtlUpperChar;
	if (func == pRtlUpperString)
		return wine32a_ntdll_RtlUpperString;
	if (func == pRtlValidAcl)
		return wine32a_ntdll_RtlValidAcl;
	if (func == pRtlValidRelativeSecurityDescriptor)
		return wine32a_ntdll_RtlValidRelativeSecurityDescriptor;
	if (func == pRtlValidSecurityDescriptor)
		return wine32a_ntdll_RtlValidSecurityDescriptor;
	if (func == pRtlValidSid)
		return wine32a_ntdll_RtlValidSid;
	if (func == pRtlValidateHeap)
		return wine32a_ntdll_RtlValidateHeap;
	if (func == pRtlVerifyVersionInfo)
		return wine32a_ntdll_RtlVerifyVersionInfo;
	if (func == pRtlVirtualUnwind)
		return wine32a_ntdll_RtlVirtualUnwind;
	if (func == pRtlWaitOnAddress)
		return wine32a_ntdll_RtlWaitOnAddress;
	if (func == pRtlWakeAddressAll)
		return wine32a_ntdll_RtlWakeAddressAll;
	if (func == pRtlWakeAddressSingle)
		return wine32a_ntdll_RtlWakeAddressSingle;
	if (func == pRtlWakeAllConditionVariable)
		return wine32a_ntdll_RtlWakeAllConditionVariable;
	if (func == pRtlWakeConditionVariable)
		return wine32a_ntdll_RtlWakeConditionVariable;
	if (func == pRtlWalkHeap)
		return wine32a_ntdll_RtlWalkHeap;
	if (func == pRtlWow64EnableFsRedirection)
		return wine32a_ntdll_RtlWow64EnableFsRedirection;
	if (func == pRtlWow64EnableFsRedirectionEx)
		return wine32a_ntdll_RtlWow64EnableFsRedirectionEx;
	if (func == pRtlWow64GetThreadContext)
		return wine32a_ntdll_RtlWow64GetThreadContext;
	if (func == pRtlWow64SetThreadContext)
		return wine32a_ntdll_RtlWow64SetThreadContext;
	if (func == pRtlWriteRegistryValue)
		return wine32a_ntdll_RtlWriteRegistryValue;
	if (func == pRtlZeroMemory)
		return wine32a_ntdll_RtlZeroMemory;
	if (func == pRtlZombifyActivationContext)
		return wine32a_ntdll_RtlZombifyActivationContext;
	if (func == pRtlpNtCreateKey)
		return wine32a_ntdll_RtlpNtCreateKey;
	if (func == pRtlpNtEnumerateSubKey)
		return wine32a_ntdll_RtlpNtEnumerateSubKey;
	if (func == pRtlpNtMakeTemporaryKey)
		return wine32a_ntdll_RtlpNtMakeTemporaryKey;
	if (func == pRtlpNtOpenKey)
		return wine32a_ntdll_RtlpNtOpenKey;
	if (func == pRtlpNtQueryValueKey)
		return wine32a_ntdll_RtlpNtQueryValueKey;
	if (func == pRtlpNtSetValueKey)
		return wine32a_ntdll_RtlpNtSetValueKey;
	if (func == pRtlpUnWaitCriticalSection)
		return wine32a_ntdll_RtlpUnWaitCriticalSection;
	if (func == pRtlpWaitForCriticalSection)
		return wine32a_ntdll_RtlpWaitForCriticalSection;
	if (func == pTpAllocCleanupGroup)
		return wine32a_ntdll_TpAllocCleanupGroup;
	if (func == pTpAllocPool)
		return wine32a_ntdll_TpAllocPool;
	if (func == pTpAllocTimer)
		return wine32a_ntdll_TpAllocTimer;
	if (func == pTpAllocWait)
		return wine32a_ntdll_TpAllocWait;
	if (func == pTpAllocWork)
		return wine32a_ntdll_TpAllocWork;
	if (func == pTpCallbackLeaveCriticalSectionOnCompletion)
		return wine32a_ntdll_TpCallbackLeaveCriticalSectionOnCompletion;
	if (func == pTpCallbackMayRunLong)
		return wine32a_ntdll_TpCallbackMayRunLong;
	if (func == pTpCallbackReleaseMutexOnCompletion)
		return wine32a_ntdll_TpCallbackReleaseMutexOnCompletion;
	if (func == pTpCallbackReleaseSemaphoreOnCompletion)
		return wine32a_ntdll_TpCallbackReleaseSemaphoreOnCompletion;
	if (func == pTpCallbackSetEventOnCompletion)
		return wine32a_ntdll_TpCallbackSetEventOnCompletion;
	if (func == pTpCallbackUnloadDllOnCompletion)
		return wine32a_ntdll_TpCallbackUnloadDllOnCompletion;
	if (func == pTpDisassociateCallback)
		return wine32a_ntdll_TpDisassociateCallback;
	if (func == pTpIsTimerSet)
		return wine32a_ntdll_TpIsTimerSet;
	if (func == pTpPostWork)
		return wine32a_ntdll_TpPostWork;
	if (func == pTpReleaseCleanupGroup)
		return wine32a_ntdll_TpReleaseCleanupGroup;
	if (func == pTpReleaseCleanupGroupMembers)
		return wine32a_ntdll_TpReleaseCleanupGroupMembers;
	if (func == pTpReleasePool)
		return wine32a_ntdll_TpReleasePool;
	if (func == pTpReleaseTimer)
		return wine32a_ntdll_TpReleaseTimer;
	if (func == pTpReleaseWait)
		return wine32a_ntdll_TpReleaseWait;
	if (func == pTpReleaseWork)
		return wine32a_ntdll_TpReleaseWork;
	if (func == pTpSetPoolMaxThreads)
		return wine32a_ntdll_TpSetPoolMaxThreads;
	if (func == pTpSetPoolMinThreads)
		return wine32a_ntdll_TpSetPoolMinThreads;
	if (func == pTpSetTimer)
		return wine32a_ntdll_TpSetTimer;
	if (func == pTpSetWait)
		return wine32a_ntdll_TpSetWait;
	if (func == pTpSimpleTryPost)
		return wine32a_ntdll_TpSimpleTryPost;
	if (func == pTpWaitForTimer)
		return wine32a_ntdll_TpWaitForTimer;
	if (func == pTpWaitForWait)
		return wine32a_ntdll_TpWaitForWait;
	if (func == pTpWaitForWork)
		return wine32a_ntdll_TpWaitForWork;
	if (func == pVerSetConditionMask)
		return wine32a_ntdll_VerSetConditionMask;
	if (func == pWinSqmEndSession)
		return wine32a_ntdll_WinSqmEndSession;
	if (func == pWinSqmIncrementDWORD)
		return wine32a_ntdll_WinSqmIncrementDWORD;
	if (func == pWinSqmIsOptedIn)
		return wine32a_ntdll_WinSqmIsOptedIn;
	if (func == pWinSqmSetDWORD)
		return wine32a_ntdll_WinSqmSetDWORD;
	if (func == pWinSqmStartSession)
		return wine32a_ntdll_WinSqmStartSession;
	if (func == p__C_specific_handler)
		return wine32a_ntdll___C_specific_handler;
	if (func == p__isascii)
		return wine32a_ntdll___isascii;
	if (func == p__iscsym)
		return wine32a_ntdll___iscsym;
	if (func == p__iscsymf)
		return wine32a_ntdll___iscsymf;
	if (func == p__toascii)
		return wine32a_ntdll___toascii;
	if (func == p_atoi64)
		return wine32a_ntdll__atoi64;
	if (func == p_i64toa)
		return wine32a_ntdll__i64toa;
	if (func == p_i64tow)
		return wine32a_ntdll__i64tow;
	if (func == p_itoa)
		return wine32a_ntdll__itoa;
	if (func == p_itow)
		return wine32a_ntdll__itow;
	if (func == p_lfind)
		return wine32a_ntdll__lfind;
	if (func == p_local_unwind)
		return wine32a_ntdll__local_unwind;
	if (func == p_ltoa)
		return wine32a_ntdll__ltoa;
	if (func == p_ltow)
		return wine32a_ntdll__ltow;
	if (func == p_memccpy)
		return wine32a_ntdll__memccpy;
	if (func == p_memicmp)
		return wine32a_ntdll__memicmp;
	if (func == p_snprintf)
		return wine32a_ntdll__snprintf;
	if (func == p_snprintf_s)
		return wine32a_ntdll__snprintf_s;
	if (func == p_snwprintf)
		return wine32a_ntdll__snwprintf;
	if (func == p_splitpath)
		return wine32a_ntdll__splitpath;
	if (func == p_stricmp)
		return wine32a_ntdll__stricmp;
	if (func == p_strlwr)
		return wine32a_ntdll__strlwr;
	if (func == p_strnicmp)
		return wine32a_ntdll__strnicmp;
	if (func == p_strupr)
		return wine32a_ntdll__strupr;
	if (func == p_tolower)
		return wine32a_ntdll__tolower;
	if (func == p_toupper)
		return wine32a_ntdll__toupper;
	if (func == p_ui64toa)
		return wine32a_ntdll__ui64toa;
	if (func == p_ui64tow)
		return wine32a_ntdll__ui64tow;
	if (func == p_ultoa)
		return wine32a_ntdll__ultoa;
	if (func == p_ultow)
		return wine32a_ntdll__ultow;
	if (func == p_vsnprintf)
		return wine32a_ntdll__vsnprintf;
	if (func == p_vsnprintf_s)
		return wine32a_ntdll__vsnprintf_s;
	if (func == p_vsnwprintf)
		return wine32a_ntdll__vsnwprintf;
	if (func == p_wcsicmp)
		return wine32a_ntdll__wcsicmp;
	if (func == p_wcslwr)
		return wine32a_ntdll__wcslwr;
	if (func == p_wcsnicmp)
		return wine32a_ntdll__wcsnicmp;
	if (func == p_wcsupr)
		return wine32a_ntdll__wcsupr;
	if (func == p_wtoi)
		return wine32a_ntdll__wtoi;
	if (func == p_wtoi64)
		return wine32a_ntdll__wtoi64;
	if (func == p_wtol)
		return wine32a_ntdll__wtol;
	if (func == pabs)
		return wine32a_ntdll_abs;
	if (func == patan)
		return wine32a_ntdll_atan;
	if (func == patoi)
		return wine32a_ntdll_atoi;
	if (func == patol)
		return wine32a_ntdll_atol;
	if (func == pbsearch)
		return wine32a_ntdll_bsearch;
	if (func == pceil)
		return wine32a_ntdll_ceil;
	if (func == pcos)
		return wine32a_ntdll_cos;
	if (func == pfabs)
		return wine32a_ntdll_fabs;
	if (func == pfloor)
		return wine32a_ntdll_floor;
	if (func == pisalnum)
		return wine32a_ntdll_isalnum;
	if (func == pisalpha)
		return wine32a_ntdll_isalpha;
	if (func == piscntrl)
		return wine32a_ntdll_iscntrl;
	if (func == pisdigit)
		return wine32a_ntdll_isdigit;
	if (func == pisgraph)
		return wine32a_ntdll_isgraph;
	if (func == pislower)
		return wine32a_ntdll_islower;
	if (func == pisprint)
		return wine32a_ntdll_isprint;
	if (func == pispunct)
		return wine32a_ntdll_ispunct;
	if (func == pisspace)
		return wine32a_ntdll_isspace;
	if (func == pisupper)
		return wine32a_ntdll_isupper;
	if (func == piswalpha)
		return wine32a_ntdll_iswalpha;
	if (func == piswctype)
		return wine32a_ntdll_iswctype;
	if (func == piswdigit)
		return wine32a_ntdll_iswdigit;
	if (func == piswlower)
		return wine32a_ntdll_iswlower;
	if (func == piswspace)
		return wine32a_ntdll_iswspace;
	if (func == piswxdigit)
		return wine32a_ntdll_iswxdigit;
	if (func == pisxdigit)
		return wine32a_ntdll_isxdigit;
	if (func == plabs)
		return wine32a_ntdll_labs;
	if (func == plog)
		return wine32a_ntdll_log;
	if (func == pmbstowcs)
		return wine32a_ntdll_mbstowcs;
	if (func == pmemchr)
		return wine32a_ntdll_memchr;
	if (func == pmemcmp)
		return wine32a_ntdll_memcmp;
	if (func == pmemcpy)
		return wine32a_ntdll_memcpy;
	if (func == pmemmove)
		return wine32a_ntdll_memmove;
	if (func == pmemset)
		return wine32a_ntdll_memset;
	if (func == ppow)
		return wine32a_ntdll_pow;
	if (func == pqsort)
		return wine32a_ntdll_qsort;
	if (func == psin)
		return wine32a_ntdll_sin;
	if (func == psprintf)
		return wine32a_ntdll_sprintf;
	if (func == psqrt)
		return wine32a_ntdll_sqrt;
	if (func == psscanf)
		return wine32a_ntdll_sscanf;
	if (func == pstrcat)
		return wine32a_ntdll_strcat;
	if (func == pstrchr)
		return wine32a_ntdll_strchr;
	if (func == pstrcmp)
		return wine32a_ntdll_strcmp;
	if (func == pstrcpy)
		return wine32a_ntdll_strcpy;
	if (func == pstrcspn)
		return wine32a_ntdll_strcspn;
	if (func == pstrlen)
		return wine32a_ntdll_strlen;
	if (func == pstrncat)
		return wine32a_ntdll_strncat;
	if (func == pstrncmp)
		return wine32a_ntdll_strncmp;
	if (func == pstrncpy)
		return wine32a_ntdll_strncpy;
	if (func == pstrnlen)
		return wine32a_ntdll_strnlen;
	if (func == pstrpbrk)
		return wine32a_ntdll_strpbrk;
	if (func == pstrrchr)
		return wine32a_ntdll_strrchr;
	if (func == pstrspn)
		return wine32a_ntdll_strspn;
	if (func == pstrstr)
		return wine32a_ntdll_strstr;
	if (func == pstrtol)
		return wine32a_ntdll_strtol;
	if (func == pstrtoul)
		return wine32a_ntdll_strtoul;
	if (func == pswprintf)
		return wine32a_ntdll_swprintf;
	if (func == ptan)
		return wine32a_ntdll_tan;
	if (func == ptolower)
		return wine32a_ntdll_tolower;
	if (func == ptoupper)
		return wine32a_ntdll_toupper;
	if (func == ptowlower)
		return wine32a_ntdll_towlower;
	if (func == ptowupper)
		return wine32a_ntdll_towupper;
	if (func == pvDbgPrintEx)
		return wine32a_ntdll_vDbgPrintEx;
	if (func == pvDbgPrintExWithPrefix)
		return wine32a_ntdll_vDbgPrintExWithPrefix;
	if (func == pvsprintf)
		return wine32a_ntdll_vsprintf;
	if (func == pwcscat)
		return wine32a_ntdll_wcscat;
	if (func == pwcschr)
		return wine32a_ntdll_wcschr;
	if (func == pwcscmp)
		return wine32a_ntdll_wcscmp;
	if (func == pwcscpy)
		return wine32a_ntdll_wcscpy;
	if (func == pwcscspn)
		return wine32a_ntdll_wcscspn;
	if (func == pwcslen)
		return wine32a_ntdll_wcslen;
	if (func == pwcsncat)
		return wine32a_ntdll_wcsncat;
	if (func == pwcsncmp)
		return wine32a_ntdll_wcsncmp;
	if (func == pwcsncpy)
		return wine32a_ntdll_wcsncpy;
	if (func == pwcspbrk)
		return wine32a_ntdll_wcspbrk;
	if (func == pwcsrchr)
		return wine32a_ntdll_wcsrchr;
	if (func == pwcsspn)
		return wine32a_ntdll_wcsspn;
	if (func == pwcsstr)
		return wine32a_ntdll_wcsstr;
	if (func == pwcstok)
		return wine32a_ntdll_wcstok;
	if (func == pwcstol)
		return wine32a_ntdll_wcstol;
	if (func == pwcstombs)
		return wine32a_ntdll_wcstombs;
	if (func == pwcstoul)
		return wine32a_ntdll_wcstoul;
	if (func == pwine_server_call)
		return wine32a_ntdll_wine_server_call;
	if (func == pwine_server_fd_to_handle)
		return wine32a_ntdll_wine_server_fd_to_handle;
	if (func == pwine_server_handle_to_fd)
		return wine32a_ntdll_wine_server_handle_to_fd;
	if (func == pwine_server_release_fd)
		return wine32a_ntdll_wine_server_release_fd;
	if (func == pwine_server_send_fd)
		return wine32a_ntdll_wine_server_send_fd;
	if (func == p__wine_make_process_system)
		return wine32a_ntdll___wine_make_process_system;
	if (func == p__wine_dbg_get_channel_flags)
		return wine32a_ntdll___wine_dbg_get_channel_flags;
	if (func == p__wine_dbg_header)
		return wine32a_ntdll___wine_dbg_header;
	if (func == p__wine_dbg_output)
		return wine32a_ntdll___wine_dbg_output;
	if (func == p__wine_dbg_strdup)
		return wine32a_ntdll___wine_dbg_strdup;
	if (func == p__wine_locked_recvmsg)
		return wine32a_ntdll___wine_locked_recvmsg;
	if (func == pwine_get_version)
		return wine32a_ntdll_wine_get_version;
	if (func == pwine_get_build_id)
		return wine32a_ntdll_wine_get_build_id;
	if (func == pwine_get_host_version)
		return wine32a_ntdll_wine_get_host_version;
	if (func == p__wine_init_codepages)
		return wine32a_ntdll___wine_init_codepages;
	if (func == p__wine_set_signal_handler)
		return wine32a_ntdll___wine_set_signal_handler;
	if (func == pwine_nt_to_unix_file_name)
		return wine32a_ntdll_wine_nt_to_unix_file_name;
	if (func == pwine_unix_to_nt_file_name)
		return wine32a_ntdll_wine_unix_to_nt_file_name;

	return NULL;
}
