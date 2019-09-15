#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
#include "wine/winethunks.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

struct _UNICODE_STRING; /* ../include/winternl.h:65 */
struct _OBJECT_ATTRIBUTES; /* ../include/winternl.h:1205 */
struct _CREDENTIAL_ATTRIBUTEA; /* ../include/wincred.h:47 */
struct _CREDENTIAL_ATTRIBUTEW; /* ../include/wincred.h:55 */
struct _CREDENTIALA; /* ../include/wincred.h:66 */
struct _CREDENTIALW; /* ../include/wincred.h:82 */
struct _CREDENTIAL_TARGET_INFORMATIONA; /* ../include/wincred.h:101 */
struct _CREDENTIAL_TARGET_INFORMATIONW; /* ../include/wincred.h:115 */
enum _CRED_MARSHAL_TYPE; /* ../include/wincred.h:153 */
enum POLICY_INFORMATION_CLASS; /* ../include/ntsecapi.h:189 */
struct LSA_TRANSLATED_NAME; /* ../include/ntsecapi.h:267 */
struct LSA_TRUST_INFORMATION; /* ../include/ntsecapi.h:274 */
struct LSA_REFERENCED_DOMAIN_LIST; /* ../include/ntsecapi.h:280 */
struct _LSA_TRANSLATED_SID; /* ../include/ntsecapi.h:286 */
struct _TRUSTED_DOMAIN_INFORMATION_EX; /* ../include/ntsecapi.h:293 */
struct _LSA_AUTH_INFORMATION; /* ../include/ntsecapi.h:303 */
struct _TRUSTED_DOMAIN_AUTH_INFORMATION; /* ../include/ntsecapi.h:311 */
struct _LSA_TRANSLATED_SID2; /* ../include/ntsecapi.h:321 */
enum _TRUSTED_INFORMATION_CLASS; /* ../include/ntsecapi.h:329 */
enum _POLICY_NOTIFICATION_INFORMATION_CLASS; /* ../include/ntsecapi.h:341 */
struct _AUDIT_POLICY_INFORMATION; /* ../include/ntsecapi.h:352 */
struct ustring; /* ../dlls/advapi32/crypt.h:94 */
struct _WNODE_HEADER; /* ../include/wmistr.h:54 */
struct _TRACE_GUID_PROPERTIES; /* ../include/evntrace.h:89 */
struct _EVENT_TRACE_HEADER; /* ../include/evntrace.h:98 */
struct _EVENT_TRACE; /* ../include/evntrace.h:143 */
struct _TRACE_LOGFILE_HEADER; /* ../include/evntrace.h:156 */
struct _EVENT_TRACE_LOGFILEW; /* ../include/evntrace.h:198 */
struct _EVENT_TRACE_LOGFILEA; /* ../include/evntrace.h:214 */
struct _EVENT_TRACE_PROPERTIES; /* ../include/evntrace.h:230 */
struct _ENABLE_TRACE_PARAMETERS; /* ../include/evntrace.h:252 */
enum _TRACE_QUERY_INFO_CLASS; /* ../include/evntrace.h:262 */
struct _EVENT_FILTER_DESCRIPTOR; /* ../include/evntprov.h:52 */
struct SAFER_LEVEL_HANDLE__; /* ../include/winsafer.h:31 */
struct _SAFER_CODE_PROPERTIES_V2; /* ../include/winsafer.h:41 */
enum _SAFER_POLICY_INFO_CLASS; /* ../include/winsafer.h:75 */
enum _SAFER_OBJECT_INFO_CLASS; /* ../include/winsafer.h:83 */
enum _SE_OBJECT_TYPE; /* ../include/accctrl.h:28 */
enum _TRUSTEE_TYPE; /* ../include/accctrl.h:45 */
enum _TRUSTEE_FORM; /* ../include/accctrl.h:58 */
enum _MULTIPLE_TRUSTEE_OPERATION; /* ../include/accctrl.h:67 */
struct _OBJECTS_AND_SID; /* ../include/accctrl.h:73 */
struct _OBJECTS_AND_NAME_A; /* ../include/accctrl.h:81 */
struct _OBJECTS_AND_NAME_W; /* ../include/accctrl.h:90 */
struct _TRUSTEE_A; /* ../include/accctrl.h:102 */
struct _TRUSTEE_W; /* ../include/accctrl.h:111 */
enum _ACCESS_MODE; /* ../include/accctrl.h:125 */
struct _EXPLICIT_ACCESS_A; /* ../include/accctrl.h:146 */
struct _EXPLICIT_ACCESS_W; /* ../include/accctrl.h:154 */
struct _ACTRL_ACCESS_ENTRYA; /* ../include/accctrl.h:170 */
struct _ACTRL_ACCESS_ENTRYW; /* ../include/accctrl.h:180 */
struct _ACTRL_ACCESS_ENTRY_LISTA; /* ../include/accctrl.h:194 */
struct _ACTRL_ACCESS_ENTRY_LISTW; /* ../include/accctrl.h:200 */
struct _ACTRL_PROPERTY_ENTRYA; /* ../include/accctrl.h:209 */
struct _ACTRL_PROPERTY_ENTRYW; /* ../include/accctrl.h:216 */
struct _ACTRL_ALISTA; /* ../include/accctrl.h:226 */
struct _ACTRL_ALISTW; /* ../include/accctrl.h:232 */
enum _PROGRESS_INVOKE_SETTING; /* ../include/accctrl.h:422 */
struct MOFRESOURCEINFOA; /* ../include/wmium.h:38 */
struct MOFRESOURCEINFOW; /* ../include/wmium.h:46 */
struct _WMIGUIDINFORMATION; /* ../include/wmium.h:67 */

typedef unsigned long ULONG64; /* ../include/basetsd.h:99 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef LONG NTSTATUS; /* ../include/winternl.h:38 */

struct _UNICODE_STRING /* ../include/winternl.h:65 */
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
};


typedef struct _UNICODE_STRING UNICODE_STRING; /* ../include/winternl.h:69 */

typedef struct _UNICODE_STRING* PUNICODE_STRING; /* ../include/winternl.h:69 */

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

struct _CREDENTIAL_ATTRIBUTEA /* ../include/wincred.h:47 */
{
    LPSTR Keyword;
    DWORD Flags;
    DWORD ValueSize;
    LPBYTE Value;
};


typedef struct _CREDENTIAL_ATTRIBUTEA* PCREDENTIAL_ATTRIBUTEA; /* ../include/wincred.h:53 */

struct _CREDENTIAL_ATTRIBUTEW /* ../include/wincred.h:55 */
{
    LPWSTR Keyword;
    DWORD Flags;
    DWORD ValueSize;
    LPBYTE Value;
};


typedef struct _CREDENTIAL_ATTRIBUTEW* PCREDENTIAL_ATTRIBUTEW; /* ../include/wincred.h:61 */

struct _CREDENTIALA /* ../include/wincred.h:66 */
{
    DWORD Flags;
    DWORD Type;
    LPSTR TargetName;
    LPSTR Comment;
    FILETIME LastWritten;
    DWORD CredentialBlobSize;
    LPBYTE CredentialBlob;
    DWORD Persist;
    DWORD AttributeCount;
    PCREDENTIAL_ATTRIBUTEA Attributes;
    LPSTR TargetAlias;
    LPSTR UserName;
};


typedef struct _CREDENTIALA* PCREDENTIALA; /* ../include/wincred.h:80 */

struct _CREDENTIALW /* ../include/wincred.h:82 */
{
    DWORD Flags;
    DWORD Type;
    LPWSTR TargetName;
    LPWSTR Comment;
    FILETIME LastWritten;
    DWORD CredentialBlobSize;
    LPBYTE CredentialBlob;
    DWORD Persist;
    DWORD AttributeCount;
    PCREDENTIAL_ATTRIBUTEW Attributes;
    LPWSTR TargetAlias;
    LPWSTR UserName;
};


typedef struct _CREDENTIALW* PCREDENTIALW; /* ../include/wincred.h:96 */

struct _CREDENTIAL_TARGET_INFORMATIONA /* ../include/wincred.h:101 */
{
    LPSTR TargetName;
    LPSTR NetbiosServerName;
    LPSTR DnsServerName;
    LPSTR NetbiosDomainName;
    LPSTR DnsDomainName;
    LPSTR DnsTreeName;
    LPSTR PackageName;
    DWORD Flags;
    DWORD CredTypeCount;
    LPDWORD CredTypes;
};


typedef struct _CREDENTIAL_TARGET_INFORMATIONA* PCREDENTIAL_TARGET_INFORMATIONA; /* ../include/wincred.h:113 */

struct _CREDENTIAL_TARGET_INFORMATIONW /* ../include/wincred.h:115 */
{
    LPWSTR TargetName;
    LPWSTR NetbiosServerName;
    LPWSTR DnsServerName;
    LPWSTR NetbiosDomainName;
    LPWSTR DnsDomainName;
    LPWSTR DnsTreeName;
    LPWSTR PackageName;
    DWORD Flags;
    DWORD CredTypeCount;
    LPDWORD CredTypes;
};


typedef struct _CREDENTIAL_TARGET_INFORMATIONW* PCREDENTIAL_TARGET_INFORMATIONW; /* ../include/wincred.h:127 */

enum _CRED_MARSHAL_TYPE /* ../include/wincred.h:153 */
{
    _CRED_MARSHAL_TYPE_DUMMY = 0
};


typedef enum _CRED_MARSHAL_TYPE CRED_MARSHAL_TYPE; /* ../include/wincred.h:158 */

typedef enum _CRED_MARSHAL_TYPE* PCRED_MARSHAL_TYPE; /* ../include/wincred.h:158 */

typedef HRESULT (*PCOGETCALLSTATE) (int, PULONG); /* ../include/wct.h:22 */

typedef HRESULT (*PCOGETACTIVATIONSTATE) (GUID, DWORD, DWORD*); /* ../include/wct.h:23 */

typedef UNICODE_STRING LSA_UNICODE_STRING; /* ../include/ntsecapi.h:181 */

typedef UNICODE_STRING* PLSA_UNICODE_STRING; /* ../include/ntsecapi.h:181 */

typedef OBJECT_ATTRIBUTES* PLSA_OBJECT_ATTRIBUTES; /* ../include/ntsecapi.h:183 */

typedef PVOID LSA_HANDLE; /* ../include/ntsecapi.h:185 */

typedef PVOID* PLSA_HANDLE; /* ../include/ntsecapi.h:185 */

typedef ULONG* PLSA_ENUMERATION_HANDLE; /* ../include/ntsecapi.h:186 */

enum POLICY_INFORMATION_CLASS /* ../include/ntsecapi.h:189 */
{
    POLICY_INFORMATION_CLASS_DUMMY = 0
};


typedef enum POLICY_INFORMATION_CLASS POLICY_INFORMATION_CLASS; /* ../include/ntsecapi.h:203 */

struct LSA_TRANSLATED_NAME /* ../include/ntsecapi.h:267 */
{
    SID_NAME_USE Use;
    LSA_UNICODE_STRING Name;
    LONG DomainIndex;
};


typedef struct LSA_TRANSLATED_NAME LSA_TRANSLATED_NAME; /* ../include/ntsecapi.h:272 */

struct LSA_TRUST_INFORMATION /* ../include/ntsecapi.h:274 */
{
    LSA_UNICODE_STRING Name;
    PSID Sid;
};


typedef struct LSA_TRUST_INFORMATION* PLSA_TRUST_INFORMATION; /* ../include/ntsecapi.h:278 */

struct LSA_REFERENCED_DOMAIN_LIST /* ../include/ntsecapi.h:280 */
{
    ULONG Entries;
    PLSA_TRUST_INFORMATION Domains;
};


typedef struct LSA_REFERENCED_DOMAIN_LIST LSA_REFERENCED_DOMAIN_LIST; /* ../include/ntsecapi.h:284 */

typedef struct LSA_REFERENCED_DOMAIN_LIST* PLSA_REFERENCED_DOMAIN_LIST; /* ../include/ntsecapi.h:284 */

struct _LSA_TRANSLATED_SID /* ../include/ntsecapi.h:286 */
{
    SID_NAME_USE Use;
    ULONG RelativeId;
    LONG DomainIndex;
};


typedef struct _LSA_TRANSLATED_SID* PLSA_TRANSLATED_SID; /* ../include/ntsecapi.h:291 */

struct _TRUSTED_DOMAIN_INFORMATION_EX /* ../include/ntsecapi.h:293 */
{
    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING FlatName;
    PSID Sid;
    ULONG TrustDirection;
    ULONG TrustType;
    ULONG TrustAttributes;
};


typedef struct _TRUSTED_DOMAIN_INFORMATION_EX* PTRUSTED_DOMAIN_INFORMATION_EX; /* ../include/ntsecapi.h:301 */

struct _LSA_AUTH_INFORMATION /* ../include/ntsecapi.h:303 */
{
    LARGE_INTEGER LastUpdateTime;
    ULONG AuthType;
    ULONG AuthInfoLength;
    PUCHAR AuthInfo;
};


typedef struct _LSA_AUTH_INFORMATION* PLSA_AUTH_INFORMATION; /* ../include/ntsecapi.h:309 */

struct _TRUSTED_DOMAIN_AUTH_INFORMATION /* ../include/ntsecapi.h:311 */
{
    ULONG IncomingAuthInfos;
    PLSA_AUTH_INFORMATION IncomingAuthenticationInformation;
    PLSA_AUTH_INFORMATION IncomingPreviousAuthenticationInformation;
    ULONG OutgoingAuthInfos;
    PLSA_AUTH_INFORMATION OutgoingAuthenticationInformation;
    PLSA_AUTH_INFORMATION OutgoingPreviousAuthenticationInformation;
};


typedef struct _TRUSTED_DOMAIN_AUTH_INFORMATION* PTRUSTED_DOMAIN_AUTH_INFORMATION; /* ../include/ntsecapi.h:319 */

struct _LSA_TRANSLATED_SID2 /* ../include/ntsecapi.h:321 */
{
    SID_NAME_USE Use;
    PSID Sid;
    LONG DomainIndex;
    ULONG Flags;
};


typedef struct _LSA_TRANSLATED_SID2* PLSA_TRANSLATED_SID2; /* ../include/ntsecapi.h:327 */

enum _TRUSTED_INFORMATION_CLASS /* ../include/ntsecapi.h:329 */
{
    _TRUSTED_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _TRUSTED_INFORMATION_CLASS TRUSTED_INFORMATION_CLASS; /* ../include/ntsecapi.h:339 */

enum _POLICY_NOTIFICATION_INFORMATION_CLASS /* ../include/ntsecapi.h:341 */
{
    _POLICY_NOTIFICATION_INFORMATION_CLASS_DUMMY = 0
};


typedef enum _POLICY_NOTIFICATION_INFORMATION_CLASS POLICY_NOTIFICATION_INFORMATION_CLASS; /* ../include/ntsecapi.h:350 */

struct _AUDIT_POLICY_INFORMATION /* ../include/ntsecapi.h:352 */
{
    GUID AuditSubCategoryGuid;
    ULONG AuditingInformation;
    GUID AuditCategoryGuid;
};


typedef struct _AUDIT_POLICY_INFORMATION AUDIT_POLICY_INFORMATION; /* ../include/ntsecapi.h:357 */

typedef unsigned int ALG_ID; /* ../include/wincrypt.h:38 */

typedef ULONG_PTR HCRYPTPROV; /* ../include/wincrypt.h:39 */

typedef ULONG_PTR HCRYPTKEY; /* ../include/wincrypt.h:42 */

typedef ULONG_PTR HCRYPTHASH; /* ../include/wincrypt.h:43 */

struct ustring /* ../dlls/advapi32/crypt.h:94 */
{
    DWORD Length;
    DWORD MaximumLength;
    unsigned char* Buffer;
};


struct _WNODE_HEADER /* ../include/wmistr.h:54 */
{
    ULONG BufferSize;
    ULONG ProvicerId;
    GUID Guid;
    ULONG ClientContext;
    ULONG Flags;
};


typedef struct _WNODE_HEADER WNODE_HEADER; /* ../include/wmistr.h:76 */

typedef ULONG64 TRACEHANDLE; /* ../include/evntrace.h:70 */

typedef ULONG64* PTRACEHANDLE; /* ../include/evntrace.h:70 */

typedef struct _EVENT_TRACE_LOGFILEA* PEVENT_TRACE_LOGFILEA; /* ../include/evntrace.h:75 */

typedef struct _EVENT_TRACE_LOGFILEW* PEVENT_TRACE_LOGFILEW; /* ../include/evntrace.h:76 */

typedef ULONG (*PEVENT_TRACE_BUFFER_CALLBACKA) (PEVENT_TRACE_LOGFILEA); /* ../include/evntrace.h:78 */

typedef ULONG (*PEVENT_TRACE_BUFFER_CALLBACKW) (PEVENT_TRACE_LOGFILEW); /* ../include/evntrace.h:79 */

struct _TRACE_GUID_PROPERTIES /* ../include/evntrace.h:89 */
{
    GUID Guid;
    ULONG GuidType;
    ULONG LoggerId;
    ULONG EnableLevel;
    ULONG EnableFlags;
    BOOLEAN IsEnable;
};


typedef struct _TRACE_GUID_PROPERTIES* PTRACE_GUID_PROPERTIES; /* ../include/evntrace.h:96 */

struct _EVENT_TRACE_HEADER /* ../include/evntrace.h:98 */
{
    USHORT Size;
    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
};


typedef struct _EVENT_TRACE_HEADER EVENT_TRACE_HEADER; /* ../include/evntrace.h:141 */

struct _EVENT_TRACE /* ../include/evntrace.h:143 */
{
    EVENT_TRACE_HEADER Header;
    ULONG InstanceId;
    ULONG ParentInstanceId;
    GUID ParentGuid;
    PVOID MofData;
    ULONG MofLength;
    ULONG ClientContext;
};


typedef struct _EVENT_TRACE EVENT_TRACE; /* ../include/evntrace.h:152 */

typedef struct _EVENT_TRACE* PEVENT_TRACE; /* ../include/evntrace.h:152 */

typedef void (*PEVENT_CALLBACK) (PEVENT_TRACE); /* ../include/evntrace.h:154 */

struct _TRACE_LOGFILE_HEADER /* ../include/evntrace.h:156 */
{
    ULONG BufferSize;
    ULONG ProviderVersion;
    ULONG NumberOfProcessors;
    LARGE_INTEGER EndTime;
    ULONG TimerResolution;
    ULONG MaximumFileSize;
    ULONG LogFileMode;
    ULONG BuffersWritten;
    LPWSTR LoggerName;
    LPWSTR LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
    LARGE_INTEGER BootTime;
    LARGE_INTEGER PerfFreq;
    LARGE_INTEGER StartTime;
    ULONG ReservedTime;
    ULONG BuffersLost;
};


typedef struct _TRACE_LOGFILE_HEADER TRACE_LOGFILE_HEADER; /* ../include/evntrace.h:196 */

struct _EVENT_TRACE_LOGFILEW /* ../include/evntrace.h:198 */
{
    LPWSTR LogFileName;
    LPWSTR LoggerName;
    LONGLONG CurrentTime;
    ULONG LogFileMode;
    EVENT_TRACE CurrentEvent;
    TRACE_LOGFILE_HEADER LogfileHeader;
    PEVENT_TRACE_BUFFER_CALLBACKW BufferCallback;
    ULONG BufferSize;
    ULONG Filled;
    ULONG EventsLost;
    PEVENT_CALLBACK EventCallback;
    PVOID Context;
};


struct _EVENT_TRACE_LOGFILEA /* ../include/evntrace.h:214 */
{
    LPSTR LogFileName;
    LPSTR LoggerName;
    LONGLONG CurrentTime;
    ULONG LogFileMode;
    EVENT_TRACE CurrentEvent;
    TRACE_LOGFILE_HEADER LogfileHeader;
    PEVENT_TRACE_BUFFER_CALLBACKA BufferCallback;
    ULONG BufferSize;
    ULONG Filled;
    ULONG EventsLost;
    PEVENT_CALLBACK EventCallback;
    PVOID Context;
};


struct _EVENT_TRACE_PROPERTIES /* ../include/evntrace.h:230 */
{
    WNODE_HEADER Wnode;
    ULONG BufferSize;
    ULONG MinimumBuffers;
    ULONG MaximumBuffers;
    ULONG MaximumFileSize;
    ULONG LogFileMode;
    ULONG FlushTimer;
    ULONG EnableFlags;
    LONG AgeLimit;
    ULONG NumberOfBuffers;
    ULONG FreeBuffers;
    ULONG EventsLost;
    ULONG BuffersWritten;
    ULONG LogBuffersLost;
    ULONG RealTimeBuffersLost;
    HANDLE LoggerThreadId;
    ULONG LogFileNameOffset;
    ULONG LoggerNameOffset;
};


typedef struct _EVENT_TRACE_PROPERTIES* PEVENT_TRACE_PROPERTIES; /* ../include/evntrace.h:250 */

struct _ENABLE_TRACE_PARAMETERS /* ../include/evntrace.h:252 */
{
    ULONG Version;
    ULONG EnableProperty;
    ULONG ControlFlags;
    GUID SourceId;
    struct _EVENT_FILTER_DESCRIPTOR* EnableFilterDesc;
    ULONG FilterDescCount;
};


typedef struct _ENABLE_TRACE_PARAMETERS* PENABLE_TRACE_PARAMETERS; /* ../include/evntrace.h:260 */

enum _TRACE_QUERY_INFO_CLASS /* ../include/evntrace.h:262 */
{
    _TRACE_QUERY_INFO_CLASS_DUMMY = 0
};


typedef enum _TRACE_QUERY_INFO_CLASS TRACE_INFO_CLASS; /* ../include/evntrace.h:285 */

struct _EVENT_FILTER_DESCRIPTOR /* ../include/evntprov.h:52 */
{
    ULONGLONG Ptr;
    ULONG Size;
    ULONG Type;
};


typedef struct _EVENT_FILTER_DESCRIPTOR* PEVENT_FILTER_DESCRIPTOR; /* ../include/evntprov.h:58 */

struct SAFER_LEVEL_HANDLE__ /* ../include/winsafer.h:31 */
{
    int unused;
};


typedef struct SAFER_LEVEL_HANDLE__* SAFER_LEVEL_HANDLE; /* ../include/winsafer.h:31 */

struct _SAFER_CODE_PROPERTIES_V2 /* ../include/winsafer.h:41 */
{
    DWORD cbSize;
    DWORD dwCheckFlags;
    LPCWSTR ImagePath;
    HANDLE hImageFileHandle;
    DWORD UrlZoneId;
    BYTE ImageHash[64];
    DWORD dwImageHashSize;
    LARGE_INTEGER ImageSize;
    ALG_ID HashAlgorithm;
    LPBYTE pByteBlock;
    HWND hWndParent;
    DWORD dwWVTUIChoice;
    LPCWSTR PackageMoniker;
    LPCWSTR PackagePublisher;
    LPCWSTR PackageName;
    ULONG64 PackageVersion;
    BOOL PackageIsFramework;
};


typedef struct _SAFER_CODE_PROPERTIES_V2 SAFER_CODE_PROPERTIES_V2; /* ../include/winsafer.h:59 */

typedef SAFER_CODE_PROPERTIES_V2 SAFER_CODE_PROPERTIES; /* ../include/winsafer.h:61 */

enum _SAFER_POLICY_INFO_CLASS /* ../include/winsafer.h:75 */
{
    _SAFER_POLICY_INFO_CLASS_DUMMY = 0
};


typedef enum _SAFER_POLICY_INFO_CLASS SAFER_POLICY_INFO_CLASS; /* ../include/winsafer.h:81 */

enum _SAFER_OBJECT_INFO_CLASS /* ../include/winsafer.h:83 */
{
    _SAFER_OBJECT_INFO_CLASS_DUMMY = 0
};


typedef enum _SAFER_OBJECT_INFO_CLASS SAFER_OBJECT_INFO_CLASS; /* ../include/winsafer.h:100 */

enum _SE_OBJECT_TYPE /* ../include/accctrl.h:28 */
{
    _SE_OBJECT_TYPE_DUMMY = 0
};


typedef enum _SE_OBJECT_TYPE SE_OBJECT_TYPE; /* ../include/accctrl.h:43 */

enum _TRUSTEE_TYPE /* ../include/accctrl.h:45 */
{
    _TRUSTEE_TYPE_DUMMY = 0
};


typedef enum _TRUSTEE_TYPE TRUSTEE_TYPE; /* ../include/accctrl.h:56 */

enum _TRUSTEE_FORM /* ../include/accctrl.h:58 */
{
    _TRUSTEE_FORM_DUMMY = 0
};


typedef enum _TRUSTEE_FORM TRUSTEE_FORM; /* ../include/accctrl.h:65 */

enum _MULTIPLE_TRUSTEE_OPERATION /* ../include/accctrl.h:67 */
{
    _MULTIPLE_TRUSTEE_OPERATION_DUMMY = 0
};


typedef enum _MULTIPLE_TRUSTEE_OPERATION MULTIPLE_TRUSTEE_OPERATION; /* ../include/accctrl.h:71 */

struct _OBJECTS_AND_SID /* ../include/accctrl.h:73 */
{
    DWORD ObjectsPresent;
    GUID ObjectTypeGuid;
    GUID InheritedObjectTypeGuid;
    SID* pSid;
};


typedef struct _OBJECTS_AND_SID* POBJECTS_AND_SID; /* ../include/accctrl.h:79 */

struct _OBJECTS_AND_NAME_A /* ../include/accctrl.h:81 */
{
    DWORD ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    LPSTR ObjectTypeName;
    LPSTR InheritedObjectTypeName;
    LPSTR ptstrName;
};


typedef struct _OBJECTS_AND_NAME_A* POBJECTS_AND_NAME_A; /* ../include/accctrl.h:88 */

struct _OBJECTS_AND_NAME_W /* ../include/accctrl.h:90 */
{
    DWORD ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    LPWSTR ObjectTypeName;
    LPWSTR InheritedObjectTypeName;
    LPWSTR ptstrName;
};


typedef struct _OBJECTS_AND_NAME_W* POBJECTS_AND_NAME_W; /* ../include/accctrl.h:97 */

struct _TRUSTEE_A /* ../include/accctrl.h:102 */
{
    struct _TRUSTEE_A* pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    LPSTR ptstrName;
};


typedef struct _TRUSTEE_A TRUSTEE_A; /* ../include/accctrl.h:109 */

typedef struct _TRUSTEE_A TRUSTEEA; /* ../include/accctrl.h:109 */

typedef struct _TRUSTEE_A* PTRUSTEEA; /* ../include/accctrl.h:109 */

struct _TRUSTEE_W /* ../include/accctrl.h:111 */
{
    struct _TRUSTEE_W* pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    LPWSTR ptstrName;
};


typedef struct _TRUSTEE_W TRUSTEE_W; /* ../include/accctrl.h:118 */

typedef struct _TRUSTEE_W TRUSTEEW; /* ../include/accctrl.h:118 */

typedef struct _TRUSTEE_W* PTRUSTEEW; /* ../include/accctrl.h:118 */

enum _ACCESS_MODE /* ../include/accctrl.h:125 */
{
    _ACCESS_MODE_DUMMY = 0
};


typedef enum _ACCESS_MODE ACCESS_MODE; /* ../include/accctrl.h:134 */

struct _EXPLICIT_ACCESS_A /* ../include/accctrl.h:146 */
{
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_A Trustee;
};


typedef struct _EXPLICIT_ACCESS_A EXPLICIT_ACCESSA; /* ../include/accctrl.h:152 */

typedef struct _EXPLICIT_ACCESS_A* PEXPLICIT_ACCESSA; /* ../include/accctrl.h:152 */

struct _EXPLICIT_ACCESS_W /* ../include/accctrl.h:154 */
{
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_W Trustee;
};


typedef struct _EXPLICIT_ACCESS_W EXPLICIT_ACCESSW; /* ../include/accctrl.h:160 */

typedef struct _EXPLICIT_ACCESS_W* PEXPLICIT_ACCESSW; /* ../include/accctrl.h:160 */

typedef ULONG ACCESS_RIGHTS; /* ../include/accctrl.h:167 */

typedef ULONG INHERIT_FLAGS; /* ../include/accctrl.h:168 */

struct _ACTRL_ACCESS_ENTRYA /* ../include/accctrl.h:170 */
{
    TRUSTEE_A Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPSTR lpInheritProperty;
};


typedef struct _ACTRL_ACCESS_ENTRYA ACTRL_ACCESS_ENTRYA; /* ../include/accctrl.h:178 */

struct _ACTRL_ACCESS_ENTRYW /* ../include/accctrl.h:180 */
{
    TRUSTEE_W Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPWSTR lpInheritProperty;
};


typedef struct _ACTRL_ACCESS_ENTRYW ACTRL_ACCESS_ENTRYW; /* ../include/accctrl.h:188 */

struct _ACTRL_ACCESS_ENTRY_LISTA /* ../include/accctrl.h:194 */
{
    ULONG cEntries;
    ACTRL_ACCESS_ENTRYA* pAccessList;
};


typedef struct _ACTRL_ACCESS_ENTRY_LISTA* PACTRL_ACCESS_ENTRY_LISTA; /* ../include/accctrl.h:198 */

struct _ACTRL_ACCESS_ENTRY_LISTW /* ../include/accctrl.h:200 */
{
    ULONG cEntries;
    ACTRL_ACCESS_ENTRYW* pAccessList;
};


typedef struct _ACTRL_ACCESS_ENTRY_LISTW* PACTRL_ACCESS_ENTRY_LISTW; /* ../include/accctrl.h:204 */

struct _ACTRL_PROPERTY_ENTRYA /* ../include/accctrl.h:209 */
{
    LPSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTA pAccessEntryList;
    ULONG fListFlags;
};


typedef struct _ACTRL_PROPERTY_ENTRYA* PACTRL_PROPERTY_ENTRYA; /* ../include/accctrl.h:214 */

struct _ACTRL_PROPERTY_ENTRYW /* ../include/accctrl.h:216 */
{
    LPWSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTW pAccessEntryList;
    ULONG fListFlags;
};


typedef struct _ACTRL_PROPERTY_ENTRYW* PACTRL_PROPERTY_ENTRYW; /* ../include/accctrl.h:221 */

struct _ACTRL_ALISTA /* ../include/accctrl.h:226 */
{
    ULONG cEntries;
    PACTRL_PROPERTY_ENTRYA pPropertyAccessList;
};


typedef struct _ACTRL_ALISTA* PACTRL_ACCESSA; /* ../include/accctrl.h:230 */

typedef struct _ACTRL_ALISTA* PACTRL_AUDITA; /* ../include/accctrl.h:230 */

struct _ACTRL_ALISTW /* ../include/accctrl.h:232 */
{
    ULONG cEntries;
    PACTRL_PROPERTY_ENTRYW pPropertyAccessList;
};


typedef struct _ACTRL_ALISTW* PACTRL_ACCESSW; /* ../include/accctrl.h:236 */

typedef struct _ACTRL_ALISTW* PACTRL_AUDITW; /* ../include/accctrl.h:236 */

enum _PROGRESS_INVOKE_SETTING /* ../include/accctrl.h:422 */
{
    _PROGRESS_INVOKE_SETTING_DUMMY = 0
};


typedef enum _PROGRESS_INVOKE_SETTING PROG_INVOKE_SETTING; /* ../include/accctrl.h:428 */

typedef enum _PROGRESS_INVOKE_SETTING* PPROG_INVOKE_SETTING; /* ../include/accctrl.h:428 */

typedef void (*FN_PROGRESS) (LPWSTR, DWORD, PPROG_INVOKE_SETTING, PVOID, BOOL); /* ../include/aclapi.h:29 */

typedef PVOID WMIHANDLE; /* ../include/wmium.h:32 */

typedef PVOID MOFHANDLE; /* ../include/wmium.h:32 */

struct MOFRESOURCEINFOA /* ../include/wmium.h:38 */
{
    char* ImagePath;
    char* ResourceName;
    ULONG ResourceSize;
    UCHAR* ResourceBuffer;
};


typedef struct MOFRESOURCEINFOA MOFRESOURCEINFOA; /* ../include/wmium.h:44 */

struct MOFRESOURCEINFOW /* ../include/wmium.h:46 */
{
    WCHAR* ImagePath;
    WCHAR* ResourceName;
    ULONG ResourceSize;
    UCHAR* ResourceBuffer;
};


typedef struct MOFRESOURCEINFOW MOFRESOURCEINFOW; /* ../include/wmium.h:52 */

struct _WMIGUIDINFORMATION /* ../include/wmium.h:67 */
{
    ULONG Size;
    BOOLEAN IsExpensive;
    BOOLEAN IsEventOnly;
};


typedef struct _WMIGUIDINFORMATION WMIGUIDINFORMATION; /* ../include/wmium.h:72 */

static void* pA_SHAFinal;
static void* pextA_SHAFinal;
static void* pA_SHAInit;
static void* pextA_SHAInit;
static void* pA_SHAUpdate;
static void* pextA_SHAUpdate;
static WINAPI BOOL (*pAbortSystemShutdownA)(LPSTR  lpMachineName);
static WINAPI BOOL (*pAbortSystemShutdownW)(LPWSTR  lpMachineName);
static void* pAccessCheck;
static void* pextAccessCheck;
static WINAPI BOOL (*pAccessCheckAndAuditAlarmA)(LPCSTR  Subsystem, LPVOID  HandleId, LPSTR  ObjectTypeName, LPSTR  ObjectName, PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  DesiredAccess, PGENERIC_MAPPING  GenericMapping, BOOL  ObjectCreation, LPDWORD  GrantedAccess, LPBOOL  AccessStatus, LPBOOL  pfGenerateOnClose);
static void* pAccessCheckAndAuditAlarmW;
static void* pextAccessCheckAndAuditAlarmW;
static void* pAccessCheckByType;
static void* pextAccessCheckByType;
static void* pAddAccessAllowedAce;
static void* pextAddAccessAllowedAce;
static void* pAddAccessAllowedAceEx;
static void* pextAddAccessAllowedAceEx;
static void* pAddAccessAllowedObjectAce;
static void* pextAddAccessAllowedObjectAce;
static void* pAddAccessDeniedAce;
static void* pextAddAccessDeniedAce;
static void* pAddAccessDeniedAceEx;
static void* pextAddAccessDeniedAceEx;
static void* pAddAccessDeniedObjectAce;
static void* pextAddAccessDeniedObjectAce;
static void* pAddAce;
static void* pextAddAce;
static void* pAddAuditAccessAce;
static void* pextAddAuditAccessAce;
static void* pAddAuditAccessAceEx;
static void* pextAddAuditAccessAceEx;
static void* pAddAuditAccessObjectAce;
static void* pextAddAuditAccessObjectAce;
static void* pAddMandatoryAce;
static void* pextAddMandatoryAce;
static void* pAdjustTokenGroups;
static void* pextAdjustTokenGroups;
static void* pAdjustTokenPrivileges;
static void* pextAdjustTokenPrivileges;
static void* pAllocateAndInitializeSid;
static void* pextAllocateAndInitializeSid;
static void* pAllocateLocallyUniqueId;
static void* pextAllocateLocallyUniqueId;
static void* pAreAllAccessesGranted;
static void* pextAreAllAccessesGranted;
static void* pAreAnyAccessesGranted;
static void* pextAreAnyAccessesGranted;
static WINAPI BOOLEAN (*pAuditQuerySystemPolicy)(GUID*  guids, ULONG  count, AUDIT_POLICY_INFORMATION**  policy);
static WINAPI BOOL (*pBackupEventLogA)(HANDLE  hEventLog, LPCSTR  lpBackupFileName);
static WINAPI BOOL (*pBackupEventLogW)(HANDLE  hEventLog, LPCWSTR  lpBackupFileName);
static WINAPI void (*pBuildExplicitAccessWithNameA)(PEXPLICIT_ACCESSA  pExplicitAccess, LPSTR  pTrusteeName, DWORD  AccessPermissions, ACCESS_MODE  AccessMode, DWORD  Inheritance);
static WINAPI void (*pBuildExplicitAccessWithNameW)(PEXPLICIT_ACCESSW  pExplicitAccess, LPWSTR  pTrusteeName, DWORD  AccessPermissions, ACCESS_MODE  AccessMode, DWORD  Inheritance);
static WINAPI DWORD (*pBuildSecurityDescriptorA)(PTRUSTEEA  pOwner, PTRUSTEEA  pGroup, ULONG  cCountOfAccessEntries, PEXPLICIT_ACCESSA  pListOfAccessEntries, ULONG  cCountOfAuditEntries, PEXPLICIT_ACCESSA  pListofAuditEntries, PSECURITY_DESCRIPTOR  pOldSD, PULONG  lpdwBufferLength, PSECURITY_DESCRIPTOR*  pNewSD);
static WINAPI DWORD (*pBuildSecurityDescriptorW)(PTRUSTEEW  pOwner, PTRUSTEEW  pGroup, ULONG  cCountOfAccessEntries, PEXPLICIT_ACCESSW  pListOfAccessEntries, ULONG  cCountOfAuditEntries, PEXPLICIT_ACCESSW  pListOfAuditEntries, PSECURITY_DESCRIPTOR  pOldSD, PULONG  lpdwBufferLength, PSECURITY_DESCRIPTOR*  pNewSD);
static WINAPI void (*pBuildTrusteeWithNameA)(PTRUSTEEA  pTrustee, LPSTR  name);
static WINAPI void (*pBuildTrusteeWithNameW)(PTRUSTEEW  pTrustee, LPWSTR  name);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameA)(PTRUSTEEA  pTrustee, POBJECTS_AND_NAME_A  pObjName, SE_OBJECT_TYPE  ObjectType, LPSTR  ObjectTypeName, LPSTR  InheritedObjectTypeName, LPSTR  Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameW)(PTRUSTEEW  pTrustee, POBJECTS_AND_NAME_W  pObjName, SE_OBJECT_TYPE  ObjectType, LPWSTR  ObjectTypeName, LPWSTR  InheritedObjectTypeName, LPWSTR  Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidA)(PTRUSTEEA  pTrustee, POBJECTS_AND_SID  pObjSid, GUID*  pObjectGuid, GUID*  pInheritedObjectGuid, PSID  pSid);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidW)(PTRUSTEEW  pTrustee, POBJECTS_AND_SID  pObjSid, GUID*  pObjectGuid, GUID*  pInheritedObjectGuid, PSID  pSid);
static WINAPI void (*pBuildTrusteeWithSidA)(PTRUSTEEA  pTrustee, PSID  pSid);
static WINAPI void (*pBuildTrusteeWithSidW)(PTRUSTEEW  pTrustee, PSID  pSid);
static void* pCheckTokenMembership;
static void* pextCheckTokenMembership;
static WINAPI BOOL (*pClearEventLogA)(HANDLE  hEventLog, LPCSTR  lpBackupFileName);
static WINAPI BOOL (*pClearEventLogW)(HANDLE  hEventLog, LPCWSTR  lpBackupFileName);
static WINAPI void (*pCloseEncryptedFileRaw)(PVOID  context);
static WINAPI BOOL (*pCloseEventLog)(HANDLE  hEventLog);
static WINAPI ULONG (*pCloseTrace)(TRACEHANDLE  handle);
static WINAPI DWORD (*pCommandLineFromMsiDescriptor)(WCHAR*  szDescriptor, WCHAR*  szCommandLine, DWORD*  pcchCommandLine);
static WINAPI ULONG (*pControlTraceA)(TRACEHANDLE  hSession, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties, ULONG  control);
static WINAPI ULONG (*pControlTraceW)(TRACEHANDLE  hSession, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties, ULONG  control);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorA)(PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  SDRevision, SECURITY_INFORMATION  Information, LPSTR*  OutputString, PULONG  OutputLen);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorW)(PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  SDRevision, SECURITY_INFORMATION  RequestedInformation, LPWSTR*  OutputString, PULONG  OutputLen);
static WINAPI BOOL (*pConvertSidToStringSidA)(PSID  pSid, LPSTR*  pstr);
static WINAPI BOOL (*pConvertSidToStringSidW)(PSID  pSid, LPWSTR*  pstr);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorA)(LPCSTR  StringSecurityDescriptor, DWORD  StringSDRevision, PSECURITY_DESCRIPTOR*  SecurityDescriptor, PULONG  SecurityDescriptorSize);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorW)(LPCWSTR  StringSecurityDescriptor, DWORD  StringSDRevision, PSECURITY_DESCRIPTOR*  SecurityDescriptor, PULONG  SecurityDescriptorSize);
static WINAPI BOOL (*pConvertStringSidToSidA)(LPCSTR  StringSid, PSID*  Sid);
static WINAPI BOOL (*pConvertStringSidToSidW)(LPCWSTR  StringSid, PSID*  Sid);
static void* pConvertToAutoInheritPrivateObjectSecurity;
static void* pextConvertToAutoInheritPrivateObjectSecurity;
static void* pCopySid;
static void* pextCopySid;
static void* pCreatePrivateObjectSecurity;
static void* pextCreatePrivateObjectSecurity;
static void* pCreatePrivateObjectSecurityEx;
static void* pextCreatePrivateObjectSecurityEx;
static void* pCreatePrivateObjectSecurityWithMultipleInheritance;
static void* pextCreatePrivateObjectSecurityWithMultipleInheritance;
static void* pCreateProcessAsUserA;
static void* pextCreateProcessAsUserA;
static void* pCreateProcessAsUserW;
static void* pextCreateProcessAsUserW;
static WINAPI BOOL (*pCreateProcessWithLogonW)(LPCWSTR  lpUsername, LPCWSTR  lpDomain, LPCWSTR  lpPassword, DWORD  dwLogonFlags, LPCWSTR  lpApplicationName, LPWSTR  lpCommandLine, DWORD  dwCreationFlags, LPVOID  lpEnvironment, LPCWSTR  lpCurrentDirectory, LPSTARTUPINFOW  lpStartupInfo, LPPROCESS_INFORMATION  lpProcessInformation);
static WINAPI BOOL (*pCreateProcessWithTokenW)(HANDLE  token, DWORD  logon_flags, LPCWSTR  application_name, LPWSTR  command_line, DWORD  creation_flags, void*  environment, LPCWSTR  current_directory, STARTUPINFOW*  startup_info, PROCESS_INFORMATION*  process_information);
static void* pCreateRestrictedToken;
static void* pextCreateRestrictedToken;
static void* pCreateWellKnownSid;
static void* pextCreateWellKnownSid;
static WINAPI BOOL (*pCredDeleteA)(LPCSTR  TargetName, DWORD  Type, DWORD  Flags);
static WINAPI BOOL (*pCredDeleteW)(LPCWSTR  TargetName, DWORD  Type, DWORD  Flags);
static WINAPI BOOL (*pCredEnumerateA)(LPCSTR  Filter, DWORD  Flags, DWORD*  Count, PCREDENTIALA**  Credentials);
static WINAPI BOOL (*pCredEnumerateW)(LPCWSTR  Filter, DWORD  Flags, DWORD*  Count, PCREDENTIALW**  Credentials);
static WINAPI void (*pCredFree)(PVOID  Buffer);
static WINAPI BOOL (*pCredGetSessionTypes)(DWORD  persistCount, LPDWORD  persists);
static WINAPI BOOL (*pCredIsMarshaledCredentialA)(LPCSTR  name);
static WINAPI BOOL (*pCredIsMarshaledCredentialW)(LPCWSTR  name);
static WINAPI BOOL (*pCredMarshalCredentialA)(CRED_MARSHAL_TYPE  type, PVOID  cred, LPSTR*  out);
static WINAPI BOOL (*pCredMarshalCredentialW)(CRED_MARSHAL_TYPE  type, PVOID  cred, LPWSTR*  out);
static WINAPI BOOL (*pCredReadA)(LPCSTR  TargetName, DWORD  Type, DWORD  Flags, PCREDENTIALA*  Credential);
static WINAPI BOOL (*pCredReadDomainCredentialsA)(PCREDENTIAL_TARGET_INFORMATIONA  TargetInformation, DWORD  Flags, DWORD*  Size, PCREDENTIALA**  Credentials);
static WINAPI BOOL (*pCredReadDomainCredentialsW)(PCREDENTIAL_TARGET_INFORMATIONW  TargetInformation, DWORD  Flags, DWORD*  Size, PCREDENTIALW**  Credentials);
static WINAPI BOOL (*pCredReadW)(LPCWSTR  TargetName, DWORD  Type, DWORD  Flags, PCREDENTIALW*  Credential);
static WINAPI BOOL (*pCredUnmarshalCredentialA)(LPCSTR  cred, PCRED_MARSHAL_TYPE  type, PVOID*  out);
static WINAPI BOOL (*pCredUnmarshalCredentialW)(LPCWSTR  cred, PCRED_MARSHAL_TYPE  type, PVOID*  out);
static WINAPI BOOL (*pCredWriteA)(PCREDENTIALA  Credential, DWORD  Flags);
static WINAPI BOOL (*pCredWriteW)(PCREDENTIALW  Credential, DWORD  Flags);
static WINAPI BOOL (*pCryptAcquireContextA)(HCRYPTPROV*  phProv, LPCSTR  pszContainer, LPCSTR  pszProvider, DWORD  dwProvType, DWORD  dwFlags);
static WINAPI BOOL (*pCryptAcquireContextW)(HCRYPTPROV*  phProv, LPCWSTR  pszContainer, LPCWSTR  pszProvider, DWORD  dwProvType, DWORD  dwFlags);
static WINAPI BOOL (*pCryptContextAddRef)(HCRYPTPROV  hProv, DWORD*  pdwReserved, DWORD  dwFlags);
static WINAPI BOOL (*pCryptCreateHash)(HCRYPTPROV  hProv, ALG_ID  Algid, HCRYPTKEY  hKey, DWORD  dwFlags, HCRYPTHASH*  phHash);
static WINAPI BOOL (*pCryptDecrypt)(HCRYPTKEY  hKey, HCRYPTHASH  hHash, BOOL  Final, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen);
static WINAPI BOOL (*pCryptDeriveKey)(HCRYPTPROV  hProv, ALG_ID  Algid, HCRYPTHASH  hBaseData, DWORD  dwFlags, HCRYPTKEY*  phKey);
static WINAPI BOOL (*pCryptDestroyHash)(HCRYPTHASH  hHash);
static WINAPI BOOL (*pCryptDestroyKey)(HCRYPTKEY  hKey);
static WINAPI BOOL (*pCryptDuplicateHash)(HCRYPTHASH  hHash, DWORD*  pdwReserved, DWORD  dwFlags, HCRYPTHASH*  phHash);
static WINAPI BOOL (*pCryptDuplicateKey)(HCRYPTKEY  hKey, DWORD*  pdwReserved, DWORD  dwFlags, HCRYPTKEY*  phKey);
static WINAPI BOOL (*pCryptEncrypt)(HCRYPTKEY  hKey, HCRYPTHASH  hHash, BOOL  Final, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwBufLen);
static WINAPI BOOL (*pCryptEnumProviderTypesA)(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPSTR  pszTypeName, DWORD*  pcbTypeName);
static WINAPI BOOL (*pCryptEnumProviderTypesW)(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPWSTR  pszTypeName, DWORD*  pcbTypeName);
static WINAPI BOOL (*pCryptEnumProvidersA)(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPSTR  pszProvName, DWORD*  pcbProvName);
static WINAPI BOOL (*pCryptEnumProvidersW)(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPWSTR  pszProvName, DWORD*  pcbProvName);
static WINAPI BOOL (*pCryptExportKey)(HCRYPTKEY  hKey, HCRYPTKEY  hExpKey, DWORD  dwBlobType, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen);
static WINAPI BOOL (*pCryptGenKey)(HCRYPTPROV  hProv, ALG_ID  Algid, DWORD  dwFlags, HCRYPTKEY*  phKey);
static WINAPI BOOL (*pCryptGenRandom)(HCRYPTPROV  hProv, DWORD  dwLen, BYTE*  pbBuffer);
static WINAPI BOOL (*pCryptGetDefaultProviderA)(DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags, LPSTR  pszProvName, DWORD*  pcbProvName);
static WINAPI BOOL (*pCryptGetDefaultProviderW)(DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags, LPWSTR  pszProvName, DWORD*  pcbProvName);
static WINAPI BOOL (*pCryptGetHashParam)(HCRYPTHASH  hHash, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags);
static WINAPI BOOL (*pCryptGetKeyParam)(HCRYPTKEY  hKey, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags);
static WINAPI BOOL (*pCryptGetProvParam)(HCRYPTPROV  hProv, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags);
static WINAPI BOOL (*pCryptGetUserKey)(HCRYPTPROV  hProv, DWORD  dwKeySpec, HCRYPTKEY*  phUserKey);
static WINAPI BOOL (*pCryptHashData)(HCRYPTHASH  hHash, BYTE*  pbData, DWORD  dwDataLen, DWORD  dwFlags);
static WINAPI BOOL (*pCryptHashSessionKey)(HCRYPTHASH  hHash, HCRYPTKEY  hKey, DWORD  dwFlags);
static WINAPI BOOL (*pCryptImportKey)(HCRYPTPROV  hProv, BYTE*  pbData, DWORD  dwDataLen, HCRYPTKEY  hPubKey, DWORD  dwFlags, HCRYPTKEY*  phKey);
static WINAPI BOOL (*pCryptReleaseContext)(HCRYPTPROV  hProv, ULONG_PTR  dwFlags);
static WINAPI BOOL (*pCryptSetHashParam)(HCRYPTHASH  hHash, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags);
static WINAPI BOOL (*pCryptSetKeyParam)(HCRYPTKEY  hKey, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags);
static WINAPI BOOL (*pCryptSetProvParam)(HCRYPTPROV  hProv, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags);
static WINAPI BOOL (*pCryptSetProviderA)(LPCSTR  pszProvName, DWORD  dwProvType);
static WINAPI BOOL (*pCryptSetProviderExA)(LPCSTR  pszProvName, DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags);
static WINAPI BOOL (*pCryptSetProviderExW)(LPCWSTR  pszProvName, DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags);
static WINAPI BOOL (*pCryptSetProviderW)(LPCWSTR  pszProvName, DWORD  dwProvType);
static WINAPI BOOL (*pCryptSignHashA)(HCRYPTHASH  hHash, DWORD  dwKeySpec, LPCSTR  sDescription, DWORD  dwFlags, BYTE*  pbSignature, DWORD*  pdwSigLen);
static WINAPI BOOL (*pCryptSignHashW)(HCRYPTHASH  hHash, DWORD  dwKeySpec, LPCWSTR  sDescription, DWORD  dwFlags, BYTE*  pbSignature, DWORD*  pdwSigLen);
static WINAPI BOOL (*pCryptVerifySignatureA)(HCRYPTHASH  hHash, BYTE*  pbSignature, DWORD  dwSigLen, HCRYPTKEY  hPubKey, LPCSTR  sDescription, DWORD  dwFlags);
static WINAPI BOOL (*pCryptVerifySignatureW)(HCRYPTHASH  hHash, BYTE*  pbSignature, DWORD  dwSigLen, HCRYPTKEY  hPubKey, LPCWSTR  sDescription, DWORD  dwFlags);
static WINAPI BOOL (*pDecryptFileA)(LPCSTR  lpFileName, DWORD  dwReserved);
static WINAPI BOOL (*pDecryptFileW)(LPCWSTR  lpFileName, DWORD  dwReserved);
static void* pDeleteAce;
static void* pextDeleteAce;
static WINAPI BOOL (*pDeregisterEventSource)(HANDLE  hEventLog);
static void* pDestroyPrivateObjectSecurity;
static void* pextDestroyPrivateObjectSecurity;
static void* pDuplicateToken;
static void* pextDuplicateToken;
static void* pDuplicateTokenEx;
static void* pextDuplicateTokenEx;
static WINAPI ULONG (*pEnableTrace)(ULONG  enable, ULONG  flag, ULONG  level, LPCGUID  guid, TRACEHANDLE  hSession);
static WINAPI ULONG (*pEnableTraceEx)(LPCGUID  provider, LPCGUID  source, TRACEHANDLE  hSession, ULONG  enable, UCHAR  level, ULONGLONG  anykeyword, ULONGLONG  allkeyword, ULONG  enableprop, PEVENT_FILTER_DESCRIPTOR  filterdesc);
static WINAPI ULONG (*pEnableTraceEx2)(TRACEHANDLE  handle, LPCGUID  provider, ULONG  control, UCHAR  level, ULONGLONG  match_any, ULONGLONG  match_all, ULONG  timeout, PENABLE_TRACE_PARAMETERS  params);
static WINAPI BOOL (*pEncryptFileA)(LPCSTR  lpFileName);
static WINAPI BOOL (*pEncryptFileW)(LPCWSTR  lpFileName);
static void* pEnumDynamicTimeZoneInformation;
static void* pextEnumDynamicTimeZoneInformation;
static WINAPI ULONG (*pEnumerateTraceGuids)(PTRACE_GUID_PROPERTIES*  propertiesarray, ULONG  arraycount, PULONG  guidcount);
static void* pEqualPrefixSid;
static void* pextEqualPrefixSid;
static void* pEqualSid;
static void* pextEqualSid;
static void* pEtwEventActivityIdControl;
static void* pextEtwEventActivityIdControl;
static void* pEtwEventEnabled;
static void* pextEtwEventEnabled;
static void* pEtwEventProviderEnabled;
static void* pextEtwEventProviderEnabled;
static void* pEtwEventRegister;
static void* pextEtwEventRegister;
static void* pEtwEventSetInformation;
static void* pextEtwEventSetInformation;
static void* pEtwEventUnregister;
static void* pextEtwEventUnregister;
static void* pEtwEventWrite;
static void* pextEtwEventWrite;
static void* pEtwEventWriteString;
static void* pextEtwEventWriteString;
static void* pEtwEventWriteTransfer;
static void* pextEtwEventWriteTransfer;
static WINAPI BOOL (*pFileEncryptionStatusA)(LPCSTR  lpFileName, LPDWORD  lpStatus);
static WINAPI BOOL (*pFileEncryptionStatusW)(LPCWSTR  lpFileName, LPDWORD  lpStatus);
static void* pFindFirstFreeAce;
static void* pextFindFirstFreeAce;
static WINAPI ULONG (*pFlushTraceA)(TRACEHANDLE  hSession, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties);
static WINAPI ULONG (*pFlushTraceW)(TRACEHANDLE  hSession, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties);
static void* pFreeSid;
static void* pextFreeSid;
static void* pGetAce;
static void* pextGetAce;
static void* pGetAclInformation;
static void* pextGetAclInformation;
static WINAPI DWORD (*pGetAuditedPermissionsFromAclA)(PACL  pacl, PTRUSTEEA  pTrustee, PACCESS_MASK  pSuccessfulAuditedRights, PACCESS_MASK  pFailedAuditRights);
static WINAPI DWORD (*pGetAuditedPermissionsFromAclW)(PACL  pacl, PTRUSTEEW  pTrustee, PACCESS_MASK  pSuccessfulAuditedRights, PACCESS_MASK  pFailedAuditRights);
static WINAPI BOOL (*pGetCurrentHwProfileA)(LPHW_PROFILE_INFOA  pInfo);
static WINAPI BOOL (*pGetCurrentHwProfileW)(LPHW_PROFILE_INFOW  pInfo);
static void* pGetDynamicTimeZoneInformationEffectiveYears;
static void* pextGetDynamicTimeZoneInformationEffectiveYears;
static WINAPI DWORD (*pGetEffectiveRightsFromAclA)(PACL  pacl, PTRUSTEEA  pTrustee, PACCESS_MASK  pAccessRights);
static WINAPI DWORD (*pGetEffectiveRightsFromAclW)(PACL  pacl, PTRUSTEEW  pTrustee, PACCESS_MASK  pAccessRights);
static WINAPI BOOL (*pGetEventLogInformation)(HANDLE  hEventLog, DWORD  dwInfoLevel, LPVOID  lpBuffer, DWORD  cbBufSize, LPDWORD  pcbBytesNeeded);
static WINAPI DWORD (*pGetExplicitEntriesFromAclA)(PACL  pacl, PULONG  pcCountOfExplicitEntries, PEXPLICIT_ACCESSA*  pListOfExplicitEntries);
static WINAPI DWORD (*pGetExplicitEntriesFromAclW)(PACL  pacl, PULONG  count, PEXPLICIT_ACCESSW*  list);
static WINAPI BOOL (*pGetFileSecurityA)(LPCSTR  lpFileName, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, DWORD  nLength, LPDWORD  lpnLengthNeeded);
static void* pGetFileSecurityW;
static void* pextGetFileSecurityW;
static void* pGetKernelObjectSecurity;
static void* pextGetKernelObjectSecurity;
static void* pGetLengthSid;
static void* pextGetLengthSid;
static WINAPI DWORD (*pGetNamedSecurityInfoA)(LPSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID*  ppsidOwner, PSID*  ppsidGroup, PACL*  ppDacl, PACL*  ppSacl, PSECURITY_DESCRIPTOR*  ppSecurityDescriptor);
static WINAPI DWORD (*pGetNamedSecurityInfoExA)(LPCSTR  object, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, LPCSTR  provider, LPCSTR  property, PACTRL_ACCESSA*  access_list, PACTRL_AUDITA*  audit_list, LPSTR*  owner, LPSTR*  group);
static WINAPI DWORD (*pGetNamedSecurityInfoExW)(LPCWSTR  object, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, LPCWSTR  provider, LPCWSTR  property, PACTRL_ACCESSW*  access_list, PACTRL_AUDITW*  audit_list, LPWSTR*  owner, LPWSTR*  group);
static WINAPI DWORD (*pGetNamedSecurityInfoW)(LPWSTR  name, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, PSID*  owner, PSID*  group, PACL*  dacl, PACL*  sacl, PSECURITY_DESCRIPTOR*  descriptor);
static WINAPI BOOL (*pGetNumberOfEventLogRecords)(HANDLE  hEventLog, PDWORD  NumberOfRecords);
static WINAPI BOOL (*pGetOldestEventLogRecord)(HANDLE  hEventLog, PDWORD  OldestRecord);
static void* pGetPrivateObjectSecurity;
static void* pextGetPrivateObjectSecurity;
static void* pGetSecurityDescriptorControl;
static void* pextGetSecurityDescriptorControl;
static void* pGetSecurityDescriptorDacl;
static void* pextGetSecurityDescriptorDacl;
static void* pGetSecurityDescriptorGroup;
static void* pextGetSecurityDescriptorGroup;
static void* pGetSecurityDescriptorLength;
static void* pextGetSecurityDescriptorLength;
static void* pGetSecurityDescriptorOwner;
static void* pextGetSecurityDescriptorOwner;
static void* pGetSecurityDescriptorSacl;
static void* pextGetSecurityDescriptorSacl;
static WINAPI DWORD (*pGetSecurityInfo)(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID*  ppsidOwner, PSID*  ppsidGroup, PACL*  ppDacl, PACL*  ppSacl, PSECURITY_DESCRIPTOR*  ppSecurityDescriptor);
static WINAPI DWORD (*pGetSecurityInfoExA)(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, LPCSTR  lpProvider, LPCSTR  lpProperty, PACTRL_ACCESSA*  ppAccessList, PACTRL_AUDITA*  ppAuditList, LPSTR*  lppOwner, LPSTR*  lppGroup);
static WINAPI DWORD (*pGetSecurityInfoExW)(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, LPCWSTR  lpProvider, LPCWSTR  lpProperty, PACTRL_ACCESSW*  ppAccessList, PACTRL_AUDITW*  ppAuditList, LPWSTR*  lppOwner, LPWSTR*  lppGroup);
static void* pGetSidIdentifierAuthority;
static void* pextGetSidIdentifierAuthority;
static void* pGetSidLengthRequired;
static void* pextGetSidLengthRequired;
static void* pGetSidSubAuthority;
static void* pextGetSidSubAuthority;
static void* pGetSidSubAuthorityCount;
static void* pextGetSidSubAuthorityCount;
static void* pGetTokenInformation;
static void* pextGetTokenInformation;
static void* pEtwGetTraceEnableFlags;
static void* pextEtwGetTraceEnableFlags;
static void* pEtwGetTraceEnableLevel;
static void* pextEtwGetTraceEnableLevel;
static void* pEtwGetTraceLoggerHandle;
static void* pextEtwGetTraceLoggerHandle;
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormA)(PTRUSTEEA  pTrustee);
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormW)(PTRUSTEEW  pTrustee);
static WINAPI LPSTR (*pGetTrusteeNameA)(PTRUSTEEA  pTrustee);
static WINAPI LPWSTR (*pGetTrusteeNameW)(PTRUSTEEW  pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeA)(PTRUSTEEA  pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeW)(PTRUSTEEW  pTrustee);
static WINAPI BOOL (*pGetUserNameA)(LPSTR  lpszName, LPDWORD  lpSize);
static WINAPI BOOL (*pGetUserNameW)(LPWSTR  lpszName, LPDWORD  lpSize);
static void* pGetWindowsAccountDomainSid;
static void* pextGetWindowsAccountDomainSid;
static void* pImpersonateAnonymousToken;
static void* pextImpersonateAnonymousToken;
static void* pImpersonateLoggedOnUser;
static void* pextImpersonateLoggedOnUser;
static void* pImpersonateNamedPipeClient;
static void* pextImpersonateNamedPipeClient;
static void* pImpersonateSelf;
static void* pextImpersonateSelf;
static void* pInitializeAcl;
static void* pextInitializeAcl;
static void* pInitializeSecurityDescriptor;
static void* pextInitializeSecurityDescriptor;
static void* pInitializeSid;
static void* pextInitializeSid;
static WINAPI DWORD (*pInitiateShutdownA)(char*  name, char*  message, DWORD  seconds, DWORD  flags, DWORD  reason);
static WINAPI DWORD (*pInitiateShutdownW)(WCHAR*  name, WCHAR*  message, DWORD  seconds, DWORD  flags, DWORD  reason);
static WINAPI BOOL (*pInitiateSystemShutdownA)(LPSTR  lpMachineName, LPSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown);
static WINAPI BOOL (*pInitiateSystemShutdownExA)(LPSTR  lpMachineName, LPSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown, DWORD  dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownExW)(LPWSTR  lpMachineName, LPWSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown, DWORD  dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownW)(LPWSTR  lpMachineName, LPWSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown);
static WINAPI BOOL (*pIsTextUnicode)(LPCVOID  buf, INT  len, LPINT  flags);
static void* pIsTokenRestricted;
static void* pextIsTokenRestricted;
static void* pIsValidAcl;
static void* pextIsValidAcl;
static void* pIsValidSecurityDescriptor;
static void* pextIsValidSecurityDescriptor;
static void* pIsValidSid;
static void* pextIsValidSid;
static void* pIsWellKnownSid;
static void* pextIsWellKnownSid;
static WINAPI BOOL (*pLogonUserA)(LPCSTR  lpszUsername, LPCSTR  lpszDomain, LPCSTR  lpszPassword, DWORD  dwLogonType, DWORD  dwLogonProvider, PHANDLE  phToken);
static WINAPI BOOL (*pLogonUserW)(LPCWSTR  lpszUsername, LPCWSTR  lpszDomain, LPCWSTR  lpszPassword, DWORD  dwLogonType, DWORD  dwLogonProvider, PHANDLE  phToken);
static WINAPI BOOL (*pLookupAccountNameA)(LPCSTR  system, LPCSTR  account, PSID  sid, LPDWORD  cbSid, LPSTR  ReferencedDomainName, LPDWORD  cbReferencedDomainName, PSID_NAME_USE  name_use);
static WINAPI BOOL (*pLookupAccountNameW)(LPCWSTR  lpSystemName, LPCWSTR  lpAccountName, PSID  Sid, LPDWORD  cbSid, LPWSTR  ReferencedDomainName, LPDWORD  cchReferencedDomainName, PSID_NAME_USE  peUse);
static WINAPI BOOL (*pLookupAccountSidA)(LPCSTR  system, PSID  sid, LPSTR  account, LPDWORD  accountSize, LPSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use);
static WINAPI BOOL (*pLookupAccountSidLocalA)(PSID  sid, LPSTR  account, LPDWORD  accountSize, LPSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use);
static WINAPI BOOL (*pLookupAccountSidLocalW)(PSID  sid, LPWSTR  account, LPDWORD  accountSize, LPWSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use);
static WINAPI BOOL (*pLookupAccountSidW)(LPCWSTR  system, PSID  sid, LPWSTR  account, LPDWORD  accountSize, LPWSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameA)(LPCSTR  lpSystemName, LPCSTR  lpName, LPSTR  lpDisplayName, LPDWORD  cchDisplayName, LPDWORD  lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameW)(LPCWSTR  lpSystemName, LPCWSTR  lpName, LPWSTR  lpDisplayName, LPDWORD  cchDisplayName, LPDWORD  lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeNameA)(LPCSTR  lpSystemName, PLUID  lpLuid, LPSTR  lpName, LPDWORD  cchName);
static WINAPI BOOL (*pLookupPrivilegeNameW)(LPCWSTR  lpSystemName, PLUID  lpLuid, LPWSTR  lpName, LPDWORD  cchName);
static WINAPI BOOL (*pLookupPrivilegeValueA)(LPCSTR  lpSystemName, LPCSTR  lpName, PLUID  lpLuid);
static WINAPI BOOL (*pLookupPrivilegeValueW)(LPCWSTR  lpSystemName, LPCWSTR  lpName, PLUID  lpLuid);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsA)(TRUSTEEA*  owner, TRUSTEEA*  group, ULONG*  access_count, EXPLICIT_ACCESSA*  access_list, ULONG*  audit_count, EXPLICIT_ACCESSA*  audit_list, SECURITY_DESCRIPTOR*  descriptor);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsW)(TRUSTEEW*  owner, TRUSTEEW*  group, ULONG*  access_count, EXPLICIT_ACCESSW*  access_list, ULONG*  audit_count, EXPLICIT_ACCESSW*  audit_list, SECURITY_DESCRIPTOR*  descriptor);
static WINAPI NTSTATUS (*pLsaAddAccountRights)(LSA_HANDLE  policy, PSID  sid, PLSA_UNICODE_STRING  rights, ULONG  count);
static WINAPI NTSTATUS (*pLsaClose)(LSA_HANDLE  ObjectHandle);
static WINAPI NTSTATUS (*pLsaCreateTrustedDomainEx)(LSA_HANDLE  policy, PTRUSTED_DOMAIN_INFORMATION_EX  domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION  auth_info, ACCESS_MASK  access, PLSA_HANDLE  domain);
static WINAPI NTSTATUS (*pLsaDeleteTrustedDomain)(LSA_HANDLE  policy, PSID  sid);
static WINAPI NTSTATUS (*pLsaEnumerateAccountRights)(LSA_HANDLE  policy, PSID  sid, PLSA_UNICODE_STRING*  rights, PULONG  count);
static WINAPI NTSTATUS (*pLsaEnumerateAccountsWithUserRight)(LSA_HANDLE  policy, PLSA_UNICODE_STRING  rights, PVOID*  buffer, PULONG  count);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomains)(LSA_HANDLE  PolicyHandle, PLSA_ENUMERATION_HANDLE  EnumerationContext, PVOID*  Buffer, ULONG  PreferredMaximumLength, PULONG  CountReturned);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomainsEx)(LSA_HANDLE  policy, PLSA_ENUMERATION_HANDLE  context, PVOID*  buffer, ULONG  length, PULONG  count);
static WINAPI NTSTATUS (*pLsaFreeMemory)(PVOID  Buffer);
static WINAPI NTSTATUS (*pLsaLookupNames)(LSA_HANDLE  PolicyHandle, ULONG  Count, PLSA_UNICODE_STRING  Names, PLSA_REFERENCED_DOMAIN_LIST*  ReferencedDomains, PLSA_TRANSLATED_SID*  Sids);
static WINAPI NTSTATUS (*pLsaLookupNames2)(LSA_HANDLE  policy, ULONG  flags, ULONG  count, PLSA_UNICODE_STRING  names, PLSA_REFERENCED_DOMAIN_LIST*  domains, PLSA_TRANSLATED_SID2*  sids);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeDisplayName)(LSA_HANDLE  handle, LSA_UNICODE_STRING*  name, LSA_UNICODE_STRING**  display_name, SHORT*  language);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeName)(LSA_HANDLE  handle, LUID*  luid, LSA_UNICODE_STRING**  name);
static WINAPI NTSTATUS (*pLsaLookupSids)(LSA_HANDLE  PolicyHandle, ULONG  Count, PSID*  Sids, LSA_REFERENCED_DOMAIN_LIST**  ReferencedDomains, LSA_TRANSLATED_NAME**  Names);
static WINAPI ULONG (*pLsaNtStatusToWinError)(NTSTATUS  Status);
static WINAPI NTSTATUS (*pLsaOpenPolicy)(PLSA_UNICODE_STRING  SystemName, PLSA_OBJECT_ATTRIBUTES  ObjectAttributes, ACCESS_MASK  DesiredAccess, PLSA_HANDLE  PolicyHandle);
static WINAPI NTSTATUS (*pLsaOpenTrustedDomainByName)(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, ACCESS_MASK  access, PLSA_HANDLE  handle);
static WINAPI NTSTATUS (*pLsaQueryInformationPolicy)(LSA_HANDLE  PolicyHandle, POLICY_INFORMATION_CLASS  InformationClass, PVOID*  Buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfo)(LSA_HANDLE  policy, PSID  sid, TRUSTED_INFORMATION_CLASS  class, PVOID*  buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfoByName)(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, TRUSTED_INFORMATION_CLASS  class, PVOID*  buffer);
static WINAPI NTSTATUS (*pLsaRegisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS  class, HANDLE  event);
static WINAPI NTSTATUS (*pLsaRemoveAccountRights)(LSA_HANDLE  policy, PSID  sid, BOOLEAN  all, PLSA_UNICODE_STRING  rights, ULONG  count);
static WINAPI NTSTATUS (*pLsaRetrievePrivateData)(LSA_HANDLE  PolicyHandle, PLSA_UNICODE_STRING  KeyName, PLSA_UNICODE_STRING*  PrivateData);
static WINAPI NTSTATUS (*pLsaSetInformationPolicy)(LSA_HANDLE  PolicyHandle, POLICY_INFORMATION_CLASS  InformationClass, PVOID  Buffer);
static WINAPI NTSTATUS (*pLsaSetSecret)(LSA_HANDLE  SecretHandle, PLSA_UNICODE_STRING  EncryptedCurrentValue, PLSA_UNICODE_STRING  EncryptedOldValue);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInfoByName)(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, TRUSTED_INFORMATION_CLASS  class, PVOID  buffer);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInformation)(LSA_HANDLE  policy, PSID  sid, TRUSTED_INFORMATION_CLASS  class, PVOID  buffer);
static WINAPI NTSTATUS (*pLsaStorePrivateData)(LSA_HANDLE  PolicyHandle, PLSA_UNICODE_STRING  KeyName, PLSA_UNICODE_STRING  PrivateData);
static WINAPI NTSTATUS (*pLsaUnregisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS  class, HANDLE  event);
static void* pMD4Final;
static void* pextMD4Final;
static void* pMD4Init;
static void* pextMD4Init;
static void* pMD4Update;
static void* pextMD4Update;
static void* pMD5Final;
static void* pextMD5Final;
static void* pMD5Init;
static void* pextMD5Init;
static void* pMD5Update;
static void* pextMD5Update;
static void* pMakeAbsoluteSD;
static void* pextMakeAbsoluteSD;
static void* pMakeSelfRelativeSD;
static void* pextMakeSelfRelativeSD;
static void* pMapGenericMask;
static void* pextMapGenericMask;
static WINAPI BOOL (*pNotifyBootConfigStatus)(BOOL  x1);
static WINAPI BOOL (*pNotifyChangeEventLog)(HANDLE  hEventLog, HANDLE  hEvent);
static WINAPI BOOL (*pObjectCloseAuditAlarmA)(LPCSTR  SubsystemName, LPVOID  HandleId, BOOL  GenerateOnClose);
static void* pObjectCloseAuditAlarmW;
static void* pextObjectCloseAuditAlarmW;
static void* pObjectDeleteAuditAlarmW;
static void* pextObjectDeleteAuditAlarmW;
static WINAPI BOOL (*pObjectOpenAuditAlarmA)(LPCSTR  SubsystemName, LPVOID  HandleId, LPSTR  ObjectTypeName, LPSTR  ObjectName, PSECURITY_DESCRIPTOR  pSecurityDescriptor, HANDLE  ClientToken, DWORD  DesiredAccess, DWORD  GrantedAccess, PPRIVILEGE_SET  Privileges, BOOL  ObjectCreation, BOOL  AccessGranted, LPBOOL  GenerateOnClose);
static void* pObjectOpenAuditAlarmW;
static void* pextObjectOpenAuditAlarmW;
static WINAPI BOOL (*pObjectPrivilegeAuditAlarmA)(LPCSTR  SubsystemName, LPVOID  HandleId, HANDLE  ClientToken, DWORD  DesiredAccess, PPRIVILEGE_SET  Privileges, BOOL  AccessGranted);
static void* pObjectPrivilegeAuditAlarmW;
static void* pextObjectPrivilegeAuditAlarmW;
static WINAPI HANDLE (*pOpenBackupEventLogA)(LPCSTR  lpUNCServerName, LPCSTR  lpFileName);
static WINAPI HANDLE (*pOpenBackupEventLogW)(LPCWSTR  lpUNCServerName, LPCWSTR  lpFileName);
static WINAPI DWORD (*pOpenEncryptedFileRawA)(LPCSTR  filename, ULONG  flags, PVOID*  context);
static WINAPI DWORD (*pOpenEncryptedFileRawW)(LPCWSTR  filename, ULONG  flags, PVOID*  context);
static WINAPI HANDLE (*pOpenEventLogA)(LPCSTR  uncname, LPCSTR  source);
static WINAPI HANDLE (*pOpenEventLogW)(LPCWSTR  uncname, LPCWSTR  source);
static void* pOpenProcessToken;
static void* pextOpenProcessToken;
static void* pOpenThreadToken;
static void* pextOpenThreadToken;
static WINAPI TRACEHANDLE (*pOpenTraceA)(PEVENT_TRACE_LOGFILEA  logfile);
static WINAPI TRACEHANDLE (*pOpenTraceW)(PEVENT_TRACE_LOGFILEW  logfile);
static void* pPerfCreateInstance;
static void* pextPerfCreateInstance;
static void* pPerfDeleteInstance;
static void* pextPerfDeleteInstance;
static void* pPerfSetCounterRefValue;
static void* pextPerfSetCounterRefValue;
static void* pPerfSetCounterSetInfo;
static void* pextPerfSetCounterSetInfo;
static void* pPerfStartProvider;
static void* pextPerfStartProvider;
static void* pPerfStartProviderEx;
static void* pextPerfStartProviderEx;
static void* pPerfStopProvider;
static void* pextPerfStopProvider;
static void* pPrivilegeCheck;
static void* pextPrivilegeCheck;
static WINAPI BOOL (*pPrivilegedServiceAuditAlarmA)(LPCSTR  SubsystemName, LPCSTR  ServiceName, HANDLE  ClientToken, PPRIVILEGE_SET  Privileges, BOOL  AccessGranted);
static void* pPrivilegedServiceAuditAlarmW;
static void* pextPrivilegedServiceAuditAlarmW;
static WINAPI ULONG (*pProcessTrace)(PTRACEHANDLE  HandleArray, ULONG  HandleCount, LPFILETIME  StartTime, LPFILETIME  EndTime);
static WINAPI ULONG (*pQueryAllTracesA)(PEVENT_TRACE_PROPERTIES*  parray, ULONG  arraycount, PULONG  psessioncount);
static WINAPI ULONG (*pQueryAllTracesW)(PEVENT_TRACE_PROPERTIES*  parray, ULONG  arraycount, PULONG  psessioncount);
static WINAPI ULONG (*pQueryTraceW)(TRACEHANDLE  handle, LPCWSTR  sessionname, PEVENT_TRACE_PROPERTIES  properties);
static WINAPI BOOL (*pQueryWindows31FilesMigration)(DWORD  x1);
static WINAPI DWORD (*pReadEncryptedFileRaw)(PFE_EXPORT_FUNC  export, PVOID  callback, PVOID  context);
static WINAPI BOOL (*pReadEventLogA)(HANDLE  hEventLog, DWORD  dwReadFlags, DWORD  dwRecordOffset, LPVOID  lpBuffer, DWORD  nNumberOfBytesToRead, DWORD*  pnBytesRead, DWORD*  pnMinNumberOfBytesNeeded);
static WINAPI BOOL (*pReadEventLogW)(HANDLE  hEventLog, DWORD  dwReadFlags, DWORD  dwRecordOffset, LPVOID  lpBuffer, DWORD  nNumberOfBytesToRead, DWORD*  pnBytesRead, DWORD*  pnMinNumberOfBytesNeeded);
static void* pRegCloseKey;
static void* pextRegCloseKey;
static WINAPI LSTATUS (*pRegConnectRegistryA)(LPCSTR  machine, HKEY  hkey, PHKEY  reskey);
static WINAPI LSTATUS (*pRegConnectRegistryW)(LPCWSTR  lpMachineName, HKEY  hKey, PHKEY  phkResult);
static WINAPI LSTATUS (*pRegCopyTreeA)(HKEY  hsrc, char*  subkey, HKEY  hdst);
static void* pRegCopyTreeW;
static void* pextRegCopyTreeW;
static WINAPI LSTATUS (*pRegCreateKeyA)(HKEY  hkey, LPCSTR  lpSubKey, PHKEY  phkResult);
static void* pRegCreateKeyExA;
static void* pextRegCreateKeyExA;
static void* pRegCreateKeyExW;
static void* pextRegCreateKeyExW;
static WINAPI LSTATUS (*pRegCreateKeyTransactedA)(HKEY  hkey, LPCSTR  name, DWORD  reserved, LPSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos, HANDLE  transaction, PVOID  reserved2);
static WINAPI LSTATUS (*pRegCreateKeyTransactedW)(HKEY  hkey, LPCWSTR  name, DWORD  reserved, LPWSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos, HANDLE  transaction, PVOID  reserved2);
static WINAPI LSTATUS (*pRegCreateKeyW)(HKEY  hkey, LPCWSTR  lpSubKey, PHKEY  phkResult);
static WINAPI LSTATUS (*pRegDeleteKeyA)(HKEY  hkey, LPCSTR  name);
static void* pRegDeleteKeyExA;
static void* pextRegDeleteKeyExA;
static void* pRegDeleteKeyExW;
static void* pextRegDeleteKeyExW;
static void* pRegDeleteKeyValueA;
static void* pextRegDeleteKeyValueA;
static void* pRegDeleteKeyValueW;
static void* pextRegDeleteKeyValueW;
static WINAPI LSTATUS (*pRegDeleteKeyW)(HKEY  hkey, LPCWSTR  name);
static void* pRegDeleteTreeA;
static void* pextRegDeleteTreeA;
static void* pRegDeleteTreeW;
static void* pextRegDeleteTreeW;
static void* pRegDeleteValueA;
static void* pextRegDeleteValueA;
static void* pRegDeleteValueW;
static void* pextRegDeleteValueW;
static WINAPI LSTATUS (*pRegDisablePredefinedCache)(void);
static WINAPI LONG (*pRegDisableReflectionKey)(HKEY  base);
static WINAPI LSTATUS (*pRegEnumKeyA)(HKEY  hkey, DWORD  index, LPSTR  name, DWORD  name_len);
static void* pRegEnumKeyExA;
static void* pextRegEnumKeyExA;
static void* pRegEnumKeyExW;
static void* pextRegEnumKeyExW;
static WINAPI LSTATUS (*pRegEnumKeyW)(HKEY  hkey, DWORD  index, LPWSTR  name, DWORD  name_len);
static void* pRegEnumValueA;
static void* pextRegEnumValueA;
static void* pRegEnumValueW;
static void* pextRegEnumValueW;
static void* pRegFlushKey;
static void* pextRegFlushKey;
static void* pRegGetKeySecurity;
static void* pextRegGetKeySecurity;
static void* pRegGetValueA;
static void* pextRegGetValueA;
static void* pRegGetValueW;
static void* pextRegGetValueW;
static void* pRegLoadAppKeyA;
static void* pextRegLoadAppKeyA;
static void* pRegLoadAppKeyW;
static void* pextRegLoadAppKeyW;
static void* pRegLoadKeyA;
static void* pextRegLoadKeyA;
static void* pRegLoadKeyW;
static void* pextRegLoadKeyW;
static void* pRegLoadMUIStringA;
static void* pextRegLoadMUIStringA;
static void* pRegLoadMUIStringW;
static void* pextRegLoadMUIStringW;
static void* pRegNotifyChangeKeyValue;
static void* pextRegNotifyChangeKeyValue;
static void* pRegOpenCurrentUser;
static void* pextRegOpenCurrentUser;
static WINAPI LSTATUS (*pRegOpenKeyA)(HKEY  hkey, LPCSTR  name, PHKEY  retkey);
static void* pRegOpenKeyExA;
static void* pextRegOpenKeyExA;
static void* pRegOpenKeyExW;
static void* pextRegOpenKeyExW;
static WINAPI LSTATUS (*pRegOpenKeyW)(HKEY  hkey, LPCWSTR  name, PHKEY  retkey);
static void* pRegOpenUserClassesRoot;
static void* pextRegOpenUserClassesRoot;
static WINAPI LSTATUS (*pRegOverridePredefKey)(HKEY  hkey, HKEY  override);
static void* pRegQueryInfoKeyA;
static void* pextRegQueryInfoKeyA;
static void* pRegQueryInfoKeyW;
static void* pextRegQueryInfoKeyW;
static WINAPI LSTATUS (*pRegQueryMultipleValuesA)(HKEY  hkey, PVALENTA  val_list, DWORD  num_vals, LPSTR  lpValueBuf, LPDWORD  ldwTotsize);
static WINAPI LSTATUS (*pRegQueryMultipleValuesW)(HKEY  hkey, PVALENTW  val_list, DWORD  num_vals, LPWSTR  lpValueBuf, LPDWORD  ldwTotsize);
static WINAPI LONG (*pRegQueryReflectionKey)(HKEY  hkey, BOOL*  is_reflection_disabled);
static WINAPI LSTATUS (*pRegQueryValueA)(HKEY  hkey, LPCSTR  name, LPSTR  data, LPLONG  count);
static void* pRegQueryValueExA;
static void* pextRegQueryValueExA;
static void* pRegQueryValueExW;
static void* pextRegQueryValueExW;
static WINAPI LSTATUS (*pRegQueryValueW)(HKEY  hkey, LPCWSTR  name, LPWSTR  data, LPLONG  count);
static WINAPI LSTATUS (*pRegReplaceKeyA)(HKEY  hkey, LPCSTR  lpSubKey, LPCSTR  lpNewFile, LPCSTR  lpOldFile);
static WINAPI LSTATUS (*pRegReplaceKeyW)(HKEY  hkey, LPCWSTR  lpSubKey, LPCWSTR  lpNewFile, LPCWSTR  lpOldFile);
static void* pRegRestoreKeyA;
static void* pextRegRestoreKeyA;
static void* pRegRestoreKeyW;
static void* pextRegRestoreKeyW;
static WINAPI LSTATUS (*pRegSaveKeyA)(HKEY  hkey, LPCSTR  file, LPSECURITY_ATTRIBUTES  sa);
static void* pRegSaveKeyExA;
static void* pextRegSaveKeyExA;
static void* pRegSaveKeyExW;
static void* pextRegSaveKeyExW;
static WINAPI LSTATUS (*pRegSaveKeyW)(HKEY  hkey, LPCWSTR  file, LPSECURITY_ATTRIBUTES  sa);
static void* pRegSetKeySecurity;
static void* pextRegSetKeySecurity;
static void* pRegSetKeyValueA;
static void* pextRegSetKeyValueA;
static void* pRegSetKeyValueW;
static void* pextRegSetKeyValueW;
static WINAPI LSTATUS (*pRegSetValueA)(HKEY  hkey, LPCSTR  subkey, DWORD  type, LPCSTR  data, DWORD  count);
static void* pRegSetValueExA;
static void* pextRegSetValueExA;
static void* pRegSetValueExW;
static void* pextRegSetValueExW;
static WINAPI LSTATUS (*pRegSetValueW)(HKEY  hkey, LPCWSTR  subkey, DWORD  type, LPCWSTR  data, DWORD  count);
static void* pRegUnLoadKeyA;
static void* pextRegUnLoadKeyA;
static void* pRegUnLoadKeyW;
static void* pextRegUnLoadKeyW;
static WINAPI HANDLE (*pRegisterEventSourceA)(LPCSTR  lpUNCServerName, LPCSTR  lpSourceName);
static WINAPI HANDLE (*pRegisterEventSourceW)(LPCWSTR  lpUNCServerName, LPCWSTR  lpSourceName);
static void* pEtwRegisterTraceGuidsA;
static void* pextEtwRegisterTraceGuidsA;
static void* pEtwRegisterTraceGuidsW;
static void* pextEtwRegisterTraceGuidsW;
static WINAPI void (*pRegisterWaitChainCOMCallback)(PCOGETCALLSTATE  call_state_cb, PCOGETACTIVATIONSTATE  activation_state_cb);
static WINAPI BOOL (*pReportEventA)(HANDLE  hEventLog, WORD  wType, WORD  wCategory, DWORD  dwEventID, PSID  lpUserSid, WORD  wNumStrings, DWORD  dwDataSize, LPCSTR*  lpStrings, LPVOID  lpRawData);
static WINAPI BOOL (*pReportEventW)(HANDLE  hEventLog, WORD  wType, WORD  wCategory, DWORD  dwEventID, PSID  lpUserSid, WORD  wNumStrings, DWORD  dwDataSize, LPCWSTR*  lpStrings, LPVOID  lpRawData);
static void* pRevertToSelf;
static void* pextRevertToSelf;
static WINAPI BOOL (*pSaferCloseLevel)(SAFER_LEVEL_HANDLE  handle);
static WINAPI BOOL (*pSaferComputeTokenFromLevel)(SAFER_LEVEL_HANDLE  handle, HANDLE  token, PHANDLE  access_token, DWORD  flags, LPVOID  reserved);
static WINAPI BOOL (*pSaferCreateLevel)(DWORD  ScopeId, DWORD  LevelId, DWORD  OpenFlags, SAFER_LEVEL_HANDLE*  LevelHandle, LPVOID  lpReserved);
static WINAPI BOOL (*pSaferGetPolicyInformation)(DWORD  scope, SAFER_POLICY_INFO_CLASS  class, DWORD  size, PVOID  buffer, PDWORD  required, LPVOID  lpReserved);
static WINAPI BOOL (*pSaferIdentifyLevel)(DWORD  count, SAFER_CODE_PROPERTIES*  properties, SAFER_LEVEL_HANDLE*  handle, void*  reserved);
static WINAPI BOOL (*pSaferSetLevelInformation)(SAFER_LEVEL_HANDLE  handle, SAFER_OBJECT_INFO_CLASS  infotype, LPVOID  buffer, DWORD  size);
static void* pSetAclInformation;
static void* pextSetAclInformation;
static WINAPI DWORD (*pSetEntriesInAclA)(ULONG  count, PEXPLICIT_ACCESSA  pEntries, PACL  OldAcl, PACL*  NewAcl);
static WINAPI DWORD (*pSetEntriesInAclW)(ULONG  count, PEXPLICIT_ACCESSW  pEntries, PACL  OldAcl, PACL*  NewAcl);
static WINAPI BOOL (*pSetFileSecurityA)(LPCSTR  lpFileName, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor);
static void* pSetFileSecurityW;
static void* pextSetFileSecurityW;
static void* pSetKernelObjectSecurity;
static void* pextSetKernelObjectSecurity;
static WINAPI DWORD (*pSetNamedSecurityInfoA)(LPSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl);
static WINAPI DWORD (*pSetNamedSecurityInfoW)(LPWSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl);
static void* pSetPrivateObjectSecurity;
static void* pextSetPrivateObjectSecurity;
static void* pSetSecurityDescriptorControl;
static void* pextSetSecurityDescriptorControl;
static void* pSetSecurityDescriptorDacl;
static void* pextSetSecurityDescriptorDacl;
static void* pSetSecurityDescriptorGroup;
static void* pextSetSecurityDescriptorGroup;
static void* pSetSecurityDescriptorOwner;
static void* pextSetSecurityDescriptorOwner;
static void* pSetSecurityDescriptorSacl;
static void* pextSetSecurityDescriptorSacl;
static WINAPI DWORD (*pSetSecurityInfo)(HANDLE  handle, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl);
static void* pSetThreadToken;
static void* pextSetThreadToken;
static void* pSetTokenInformation;
static void* pextSetTokenInformation;
static WINAPI ULONG (*pStartTraceA)(PTRACEHANDLE  pSessionHandle, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties);
static WINAPI ULONG (*pStartTraceW)(PTRACEHANDLE  pSessionHandle, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties);
static WINAPI ULONG (*pStopTraceA)(TRACEHANDLE  session, LPCSTR  session_name, PEVENT_TRACE_PROPERTIES  properties);
static WINAPI ULONG (*pStopTraceW)(TRACEHANDLE  session, LPCWSTR  session_name, PEVENT_TRACE_PROPERTIES  properties);
static WINAPI BOOL (*pSynchronizeWindows31FilesAndWindowsNTRegistry)(DWORD  x1, DWORD  x2, DWORD  x3, DWORD  x4);
static WINAPI NTSTATUS (*pSystemFunction001)(BYTE*  data, BYTE*  key, LPBYTE  output);
static WINAPI NTSTATUS (*pSystemFunction002)(BYTE*  data, BYTE*  key, LPBYTE  output);
static WINAPI NTSTATUS (*pSystemFunction003)(BYTE*  key, LPBYTE  output);
static WINAPI NTSTATUS (*pSystemFunction004)(struct ustring*  in, struct ustring*  key, struct ustring*  out);
static WINAPI NTSTATUS (*pSystemFunction005)(struct ustring*  in, struct ustring*  key, struct ustring*  out);
static WINAPI NTSTATUS (*pSystemFunction006)(LPCSTR  password, LPSTR  hash);
static WINAPI NTSTATUS (*pSystemFunction007)(UNICODE_STRING*  string, LPBYTE  hash);
static WINAPI NTSTATUS (*pSystemFunction008)(BYTE*  challenge, BYTE*  hash, LPBYTE  response);
static WINAPI NTSTATUS (*pSystemFunction009)(BYTE*  challenge, BYTE*  hash, LPBYTE  response);
static WINAPI NTSTATUS (*pSystemFunction010)(LPVOID  unknown, BYTE*  data, LPBYTE  hash);
static WINAPI NTSTATUS (*pSystemFunction012)(BYTE*  in, BYTE*  key, LPBYTE  out);
static WINAPI NTSTATUS (*pSystemFunction013)(BYTE*  in, BYTE*  key, LPBYTE  out);
static WINAPI NTSTATUS (*pSystemFunction024)(BYTE*  in, BYTE*  key, LPBYTE  out);
static WINAPI NTSTATUS (*pSystemFunction025)(BYTE*  in, BYTE*  key, LPBYTE  out);
static WINAPI BOOL (*pSystemFunction030)(LPCVOID  b1, LPCVOID  b2);
static WINAPI NTSTATUS (*pSystemFunction032)(struct ustring*  data, struct ustring*  key);
static WINAPI BOOL (*pSystemFunction035)(LPCSTR  lpszDllFilePath);
static void* pEtwLogTraceEvent;
static void* pextEtwLogTraceEvent;
static void* pEtwTraceMessage;
static void* pextEtwTraceMessage;
static void* pEtwTraceMessageVa;
static void* pextEtwTraceMessageVa;
static WINAPI ULONG (*pTraceSetInformation)(TRACEHANDLE  handle, TRACE_INFO_CLASS  infoclass, void*  info, ULONG  len);
static WINAPI DWORD (*pTreeResetNamedSecurityInfoW)(LPWSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  pOwner, PSID  pGroup, PACL  pDacl, PACL  pSacl, BOOL  KeepExplicit, FN_PROGRESS  fnProgress, PROG_INVOKE_SETTING  ProgressInvokeSetting, PVOID  Args);
static void* pEtwUnregisterTraceGuids;
static void* pextEtwUnregisterTraceGuids;
static WINAPI ULONG (*pWmiExecuteMethodA)(WMIHANDLE  handle, char*  name, ULONG  method, ULONG  inputsize, void*  inputbuffer, ULONG*  outputsize, void*  outputbuffer);
static WINAPI ULONG (*pWmiExecuteMethodW)(WMIHANDLE  handle, WCHAR*  name, ULONG  method, ULONG  inputsize, void*  inputbuffer, ULONG*  outputsize, void*  outputbuffer);
static WINAPI void (*pWmiFreeBuffer)(void*  buffer);
static WINAPI ULONG (*pWmiMofEnumerateResourcesA)(MOFHANDLE  handle, ULONG*  count, MOFRESOURCEINFOA**  resource);
static WINAPI ULONG (*pWmiMofEnumerateResourcesW)(MOFHANDLE  handle, ULONG*  count, MOFRESOURCEINFOW**  resource);
static WINAPI ULONG (*pWmiNotificationRegistrationA)(GUID*  guid, BOOLEAN  enable, void*  info, ULONG_PTR  context, ULONG  flags);
static WINAPI ULONG (*pWmiNotificationRegistrationW)(GUID*  guid, BOOLEAN  enable, void*  info, ULONG_PTR  context, ULONG  flags);
static WINAPI ULONG (*pWmiOpenBlock)(GUID*  guid, ULONG  access, WMIHANDLE*  handle);
static WINAPI ULONG (*pWmiQueryAllDataA)(WMIHANDLE  handle, ULONG*  size, void*  buffer);
static WINAPI ULONG (*pWmiQueryAllDataW)(WMIHANDLE  handle, ULONG*  size, void*  buffer);
static WINAPI ULONG (*pWmiQueryGuidInformation)(WMIHANDLE  handle, WMIGUIDINFORMATION*  info);
static WINAPI ULONG (*pWmiSetSingleInstanceA)(WMIHANDLE  handle, char*  name, ULONG  reserved, ULONG  size, void*  buffer);
static WINAPI ULONG (*pWmiSetSingleInstanceW)(WMIHANDLE  handle, WCHAR*  name, ULONG  reserved, ULONG  size, void*  buffer);
static WINAPI ULONG (*pWmiSetSingleItemA)(WMIHANDLE  handle, char*  name, ULONG  id, ULONG  reserved, ULONG  size, void*  buffer);
static WINAPI ULONG (*pWmiSetSingleItemW)(WMIHANDLE  handle, WCHAR*  name, ULONG  id, ULONG  reserved, ULONG  size, void*  buffer);
static WINAPI DWORD (*pWriteEncryptedFileRaw)(PFE_IMPORT_FUNC  import, PVOID  callback, PVOID  context);

extern WINAPI BOOL wine32b_advapi32_AbortSystemShutdownA(LPSTR  lpMachineName) /* ../dlls/advapi32/advapi.c:189 */
{
	TRACE("Enter AbortSystemShutdownA\n");
	return pAbortSystemShutdownA(lpMachineName);
}

extern WINAPI void wine32a_advapi32_AbortSystemShutdownA(void);  /* ../dlls/advapi32/advapi.c:189 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_AbortSystemShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_AbortSystemShutdownA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_AbortSystemShutdownW(LPWSTR  lpMachineName) /* ../dlls/advapi32/advapi.c:200 */
{
	TRACE("Enter AbortSystemShutdownW\n");
	return pAbortSystemShutdownW(lpMachineName);
}

extern WINAPI void wine32a_advapi32_AbortSystemShutdownW(void);  /* ../dlls/advapi32/advapi.c:200 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_AbortSystemShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_AbortSystemShutdownW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_AccessCheckAndAuditAlarmA(LPCSTR  Subsystem, LPVOID  HandleId, LPSTR  ObjectTypeName, LPSTR  ObjectName, PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  DesiredAccess, PGENERIC_MAPPING  GenericMapping, BOOL  ObjectCreation, LPDWORD  GrantedAccess, LPBOOL  AccessStatus, LPBOOL  pfGenerateOnClose) /* ../dlls/advapi32/security.c:1712 */
{
	TRACE("Enter AccessCheckAndAuditAlarmA\n");
	return pAccessCheckAndAuditAlarmA(Subsystem, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose);
}

extern WINAPI void wine32a_advapi32_AccessCheckAndAuditAlarmA(void);  /* ../dlls/advapi32/security.c:1712 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_AccessCheckAndAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_AccessCheckAndAuditAlarmA") "\n"
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

extern WINAPI BOOLEAN wine32b_advapi32_AuditQuerySystemPolicy(GUID*  guids, ULONG  count, AUDIT_POLICY_INFORMATION**  policy) /* ../dlls/advapi32/lsa.c:1080 */
{
	TRACE("Enter AuditQuerySystemPolicy\n");
	return pAuditQuerySystemPolicy(guids, count, policy);
}

extern WINAPI void wine32a_advapi32_AuditQuerySystemPolicy(void);  /* ../dlls/advapi32/lsa.c:1080 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_AuditQuerySystemPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_AuditQuerySystemPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_BackupEventLogA(HANDLE  hEventLog, LPCSTR  lpBackupFileName) /* ../dlls/advapi32/eventlog.c:55 */
{
	TRACE("Enter BackupEventLogA\n");
	return pBackupEventLogA(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_advapi32_BackupEventLogA(void);  /* ../dlls/advapi32/eventlog.c:55 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BackupEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BackupEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_BackupEventLogW(HANDLE  hEventLog, LPCWSTR  lpBackupFileName) /* ../dlls/advapi32/eventlog.c:72 */
{
	TRACE("Enter BackupEventLogW\n");
	return pBackupEventLogW(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_advapi32_BackupEventLogW(void);  /* ../dlls/advapi32/eventlog.c:72 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BackupEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BackupEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildExplicitAccessWithNameA(PEXPLICIT_ACCESSA  pExplicitAccess, LPSTR  pTrusteeName, DWORD  AccessPermissions, ACCESS_MODE  AccessMode, DWORD  Inheritance) /* ../dlls/advapi32/security.c:1897 */
{
	TRACE("Enter BuildExplicitAccessWithNameA\n");
	return pBuildExplicitAccessWithNameA(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
}

extern WINAPI void wine32a_advapi32_BuildExplicitAccessWithNameA(void);  /* ../dlls/advapi32/security.c:1897 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildExplicitAccessWithNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildExplicitAccessWithNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildExplicitAccessWithNameW(PEXPLICIT_ACCESSW  pExplicitAccess, LPWSTR  pTrusteeName, DWORD  AccessPermissions, ACCESS_MODE  AccessMode, DWORD  Inheritance) /* ../dlls/advapi32/security.c:1918 */
{
	TRACE("Enter BuildExplicitAccessWithNameW\n");
	return pBuildExplicitAccessWithNameW(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
}

extern WINAPI void wine32a_advapi32_BuildExplicitAccessWithNameW(void);  /* ../dlls/advapi32/security.c:1918 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildExplicitAccessWithNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildExplicitAccessWithNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_BuildSecurityDescriptorA(PTRUSTEEA  pOwner, PTRUSTEEA  pGroup, ULONG  cCountOfAccessEntries, PEXPLICIT_ACCESSA  pListOfAccessEntries, ULONG  cCountOfAuditEntries, PEXPLICIT_ACCESSA  pListofAuditEntries, PSECURITY_DESCRIPTOR  pOldSD, PULONG  lpdwBufferLength, PSECURITY_DESCRIPTOR*  pNewSD) /* ../dlls/advapi32/security.c:540 */
{
	TRACE("Enter BuildSecurityDescriptorA\n");
	return pBuildSecurityDescriptorA(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListofAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
}

extern WINAPI void wine32a_advapi32_BuildSecurityDescriptorA(void);  /* ../dlls/advapi32/security.c:540 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildSecurityDescriptorA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_BuildSecurityDescriptorW(PTRUSTEEW  pOwner, PTRUSTEEW  pGroup, ULONG  cCountOfAccessEntries, PEXPLICIT_ACCESSW  pListOfAccessEntries, ULONG  cCountOfAuditEntries, PEXPLICIT_ACCESSW  pListOfAuditEntries, PSECURITY_DESCRIPTOR  pOldSD, PULONG  lpdwBufferLength, PSECURITY_DESCRIPTOR*  pNewSD) /* ../dlls/advapi32/security.c:563 */
{
	TRACE("Enter BuildSecurityDescriptorW\n");
	return pBuildSecurityDescriptorW(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListOfAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
}

extern WINAPI void wine32a_advapi32_BuildSecurityDescriptorW(void);  /* ../dlls/advapi32/security.c:563 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildSecurityDescriptorW") "\n"
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

extern WINAPI void wine32b_advapi32_BuildTrusteeWithNameA(PTRUSTEEA  pTrustee, LPSTR  name) /* ../dlls/advapi32/security.c:2127 */
{
	TRACE("Enter BuildTrusteeWithNameA\n");
	return pBuildTrusteeWithNameA(pTrustee, name);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithNameA(void);  /* ../dlls/advapi32/security.c:2127 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildTrusteeWithNameW(PTRUSTEEW  pTrustee, LPWSTR  name) /* ../dlls/advapi32/security.c:2141 */
{
	TRACE("Enter BuildTrusteeWithNameW\n");
	return pBuildTrusteeWithNameW(pTrustee, name);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithNameW(void);  /* ../dlls/advapi32/security.c:2141 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndNameA(PTRUSTEEA  pTrustee, POBJECTS_AND_NAME_A  pObjName, SE_OBJECT_TYPE  ObjectType, LPSTR  ObjectTypeName, LPSTR  InheritedObjectTypeName, LPSTR  Name) /* ../dlls/advapi32/security.c:1939 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameA\n");
	return pBuildTrusteeWithObjectsAndNameA(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithObjectsAndNameA(void);  /* ../dlls/advapi32/security.c:1939 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithObjectsAndNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithObjectsAndNameA") "\n"
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

extern WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndNameW(PTRUSTEEW  pTrustee, POBJECTS_AND_NAME_W  pObjName, SE_OBJECT_TYPE  ObjectType, LPWSTR  ObjectTypeName, LPWSTR  InheritedObjectTypeName, LPWSTR  Name) /* ../dlls/advapi32/security.c:1975 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameW\n");
	return pBuildTrusteeWithObjectsAndNameW(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithObjectsAndNameW(void);  /* ../dlls/advapi32/security.c:1975 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithObjectsAndNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithObjectsAndNameW") "\n"
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

extern WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndSidA(PTRUSTEEA  pTrustee, POBJECTS_AND_SID  pObjSid, GUID*  pObjectGuid, GUID*  pInheritedObjectGuid, PSID  pSid) /* ../dlls/advapi32/security.c:2011 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidA\n");
	return pBuildTrusteeWithObjectsAndSidA(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithObjectsAndSidA(void);  /* ../dlls/advapi32/security.c:2011 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithObjectsAndSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithObjectsAndSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndSidW(PTRUSTEEW  pTrustee, POBJECTS_AND_SID  pObjSid, GUID*  pObjectGuid, GUID*  pInheritedObjectGuid, PSID  pSid) /* ../dlls/advapi32/security.c:2055 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidW\n");
	return pBuildTrusteeWithObjectsAndSidW(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithObjectsAndSidW(void);  /* ../dlls/advapi32/security.c:2055 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithObjectsAndSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithObjectsAndSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildTrusteeWithSidA(PTRUSTEEA  pTrustee, PSID  pSid) /* ../dlls/advapi32/security.c:2099 */
{
	TRACE("Enter BuildTrusteeWithSidA\n");
	return pBuildTrusteeWithSidA(pTrustee, pSid);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithSidA(void);  /* ../dlls/advapi32/security.c:2099 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_BuildTrusteeWithSidW(PTRUSTEEW  pTrustee, PSID  pSid) /* ../dlls/advapi32/security.c:2113 */
{
	TRACE("Enter BuildTrusteeWithSidW\n");
	return pBuildTrusteeWithSidW(pTrustee, pSid);
}

extern WINAPI void wine32a_advapi32_BuildTrusteeWithSidW(void);  /* ../dlls/advapi32/security.c:2113 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_BuildTrusteeWithSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_BuildTrusteeWithSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ClearEventLogA(HANDLE  hEventLog, LPCSTR  lpBackupFileName) /* ../dlls/advapi32/eventlog.c:112 */
{
	TRACE("Enter ClearEventLogA\n");
	return pClearEventLogA(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_advapi32_ClearEventLogA(void);  /* ../dlls/advapi32/eventlog.c:112 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ClearEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ClearEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ClearEventLogW(HANDLE  hEventLog, LPCWSTR  lpBackupFileName) /* ../dlls/advapi32/eventlog.c:129 */
{
	TRACE("Enter ClearEventLogW\n");
	return pClearEventLogW(hEventLog, lpBackupFileName);
}

extern WINAPI void wine32a_advapi32_ClearEventLogW(void);  /* ../dlls/advapi32/eventlog.c:129 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ClearEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ClearEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_CloseEncryptedFileRaw(PVOID  context) /* ../dlls/advapi32/crypt.c:345 */
{
	TRACE("Enter CloseEncryptedFileRaw\n");
	return pCloseEncryptedFileRaw(context);
}

extern WINAPI void wine32a_advapi32_CloseEncryptedFileRaw(void);  /* ../dlls/advapi32/crypt.c:345 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CloseEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CloseEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CloseEventLog(HANDLE  hEventLog) /* ../dlls/advapi32/eventlog.c:154 */
{
	TRACE("Enter CloseEventLog\n");
	return pCloseEventLog(hEventLog);
}

extern WINAPI void wine32a_advapi32_CloseEventLog(void);  /* ../dlls/advapi32/eventlog.c:154 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CloseEventLog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CloseEventLog") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_CloseTrace(TRACEHANDLE  handle) /* ../dlls/advapi32/eventlog.c:825 */
{
	TRACE("Enter CloseTrace\n");
	return pCloseTrace(handle);
}

extern WINAPI void wine32a_advapi32_CloseTrace(void);  /* ../dlls/advapi32/eventlog.c:825 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CloseTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CloseTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_CommandLineFromMsiDescriptor(WCHAR*  szDescriptor, WCHAR*  szCommandLine, DWORD*  pcchCommandLine) /* ../dlls/advapi32/advapi.c:323 */
{
	TRACE("Enter CommandLineFromMsiDescriptor\n");
	return pCommandLineFromMsiDescriptor(szDescriptor, szCommandLine, pcchCommandLine);
}

extern WINAPI void wine32a_advapi32_CommandLineFromMsiDescriptor(void);  /* ../dlls/advapi32/advapi.c:323 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CommandLineFromMsiDescriptor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CommandLineFromMsiDescriptor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_ControlTraceA(TRACEHANDLE  hSession, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties, ULONG  control) /* ../dlls/advapi32/eventlog.c:185 */
{
	TRACE("Enter ControlTraceA\n");
	return pControlTraceA(hSession, SessionName, Properties, control);
}

extern WINAPI void wine32a_advapi32_ControlTraceA(void);  /* ../dlls/advapi32/eventlog.c:185 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ControlTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ControlTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_ControlTraceW(TRACEHANDLE  hSession, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties, ULONG  control) /* ../dlls/advapi32/eventlog.c:173 */
{
	TRACE("Enter ControlTraceW\n");
	return pControlTraceW(hSession, SessionName, Properties, control);
}

extern WINAPI void wine32a_advapi32_ControlTraceW(void);  /* ../dlls/advapi32/eventlog.c:173 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ControlTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ControlTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA(PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  SDRevision, SECURITY_INFORMATION  Information, LPSTR*  OutputString, PULONG  OutputLen) /* ../dlls/advapi32/security.c:3754 */
{
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorA\n");
	return pConvertSecurityDescriptorToStringSecurityDescriptorA(SecurityDescriptor, SDRevision, Information, OutputString, OutputLen);
}

extern WINAPI void wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA(void);  /* ../dlls/advapi32/security.c:3754 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW(PSECURITY_DESCRIPTOR  SecurityDescriptor, DWORD  SDRevision, SECURITY_INFORMATION  RequestedInformation, LPWSTR*  OutputString, PULONG  OutputLen) /* ../dlls/advapi32/security.c:3695 */
{
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorW\n");
	return pConvertSecurityDescriptorToStringSecurityDescriptorW(SecurityDescriptor, SDRevision, RequestedInformation, OutputString, OutputLen);
}

extern WINAPI void wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW(void);  /* ../dlls/advapi32/security.c:3695 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertSidToStringSidA(PSID  pSid, LPSTR*  pstr) /* ../dlls/advapi32/security.c:3856 */
{
	TRACE("Enter ConvertSidToStringSidA\n");
	return pConvertSidToStringSidA(pSid, pstr);
}

extern WINAPI void wine32a_advapi32_ConvertSidToStringSidA(void);  /* ../dlls/advapi32/security.c:3856 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertSidToStringSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertSidToStringSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertSidToStringSidW(PSID  pSid, LPWSTR*  pstr) /* ../dlls/advapi32/security.c:3835 */
{
	TRACE("Enter ConvertSidToStringSidW\n");
	return pConvertSidToStringSidW(pSid, pstr);
}

extern WINAPI void wine32a_advapi32_ConvertSidToStringSidW(void);  /* ../dlls/advapi32/security.c:3835 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertSidToStringSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertSidToStringSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA(LPCSTR  StringSecurityDescriptor, DWORD  StringSDRevision, PSECURITY_DESCRIPTOR*  SecurityDescriptor, PULONG  SecurityDescriptorSize) /* ../dlls/advapi32/security.c:3293 */
{
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorA\n");
	return pConvertStringSecurityDescriptorToSecurityDescriptorA(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
}

extern WINAPI void wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA(void);  /* ../dlls/advapi32/security.c:3293 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW(LPCWSTR  StringSecurityDescriptor, DWORD  StringSDRevision, PSECURITY_DESCRIPTOR*  SecurityDescriptor, PULONG  SecurityDescriptorSize) /* ../dlls/advapi32/security.c:3320 */
{
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorW\n");
	return pConvertStringSecurityDescriptorToSecurityDescriptorW(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
}

extern WINAPI void wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW(void);  /* ../dlls/advapi32/security.c:3320 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertStringSidToSidA(LPCSTR  StringSid, PSID*  Sid) /* ../dlls/advapi32/security.c:3807 */
{
	TRACE("Enter ConvertStringSidToSidA\n");
	return pConvertStringSidToSidA(StringSid, Sid);
}

extern WINAPI void wine32a_advapi32_ConvertStringSidToSidA(void);  /* ../dlls/advapi32/security.c:3807 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertStringSidToSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertStringSidToSidA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ConvertStringSidToSidW(LPCWSTR  StringSid, PSID*  Sid) /* ../dlls/advapi32/security.c:3783 */
{
	TRACE("Enter ConvertStringSidToSidW\n");
	return pConvertStringSidToSidW(StringSid, Sid);
}

extern WINAPI void wine32a_advapi32_ConvertStringSidToSidW(void);  /* ../dlls/advapi32/security.c:3783 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ConvertStringSidToSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ConvertStringSidToSidW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CreateProcessWithLogonW(LPCWSTR  lpUsername, LPCWSTR  lpDomain, LPCWSTR  lpPassword, DWORD  dwLogonFlags, LPCWSTR  lpApplicationName, LPWSTR  lpCommandLine, DWORD  dwCreationFlags, LPVOID  lpEnvironment, LPCWSTR  lpCurrentDirectory, LPSTARTUPINFOW  lpStartupInfo, LPPROCESS_INFORMATION  lpProcessInformation) /* ../dlls/advapi32/security.c:3880 */
{
	TRACE("Enter CreateProcessWithLogonW\n");
	return pCreateProcessWithLogonW(lpUsername, lpDomain, lpPassword, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
}

extern WINAPI void wine32a_advapi32_CreateProcessWithLogonW(void);  /* ../dlls/advapi32/security.c:3880 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CreateProcessWithLogonW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CreateProcessWithLogonW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CreateProcessWithTokenW(HANDLE  token, DWORD  logon_flags, LPCWSTR  application_name, LPWSTR  command_line, DWORD  creation_flags, void*  environment, LPCWSTR  current_directory, STARTUPINFOW*  startup_info, PROCESS_INFORMATION*  process_information) /* ../dlls/advapi32/security.c:3892 */
{
	TRACE("Enter CreateProcessWithTokenW\n");
	return pCreateProcessWithTokenW(token, logon_flags, application_name, command_line, creation_flags, environment, current_directory, startup_info, process_information);
}

extern WINAPI void wine32a_advapi32_CreateProcessWithTokenW(void);  /* ../dlls/advapi32/security.c:3892 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CreateProcessWithTokenW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CreateProcessWithTokenW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CredDeleteA(LPCSTR  TargetName, DWORD  Type, DWORD  Flags) /* ../dlls/advapi32/cred.c:1077 */
{
	TRACE("Enter CredDeleteA\n");
	return pCredDeleteA(TargetName, Type, Flags);
}

extern WINAPI void wine32a_advapi32_CredDeleteA(void);  /* ../dlls/advapi32/cred.c:1077 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredDeleteA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredDeleteA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredDeleteW(LPCWSTR  TargetName, DWORD  Type, DWORD  Flags) /* ../dlls/advapi32/cred.c:1110 */
{
	TRACE("Enter CredDeleteW\n");
	return pCredDeleteW(TargetName, Type, Flags);
}

extern WINAPI void wine32a_advapi32_CredDeleteW(void);  /* ../dlls/advapi32/cred.c:1110 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredDeleteW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredDeleteW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredEnumerateA(LPCSTR  Filter, DWORD  Flags, DWORD*  Count, PCREDENTIALA**  Credentials) /* ../dlls/advapi32/cred.c:1171 */
{
	TRACE("Enter CredEnumerateA\n");
	return pCredEnumerateA(Filter, Flags, Count, Credentials);
}

extern WINAPI void wine32a_advapi32_CredEnumerateA(void);  /* ../dlls/advapi32/cred.c:1171 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredEnumerateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredEnumerateA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredEnumerateW(LPCWSTR  Filter, DWORD  Flags, DWORD*  Count, PCREDENTIALW**  Credentials) /* ../dlls/advapi32/cred.c:1234 */
{
	TRACE("Enter CredEnumerateW\n");
	return pCredEnumerateW(Filter, Flags, Count, Credentials);
}

extern WINAPI void wine32a_advapi32_CredEnumerateW(void);  /* ../dlls/advapi32/cred.c:1234 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredEnumerateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredEnumerateW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_CredFree(PVOID  Buffer) /* ../dlls/advapi32/cred.c:1340 */
{
	TRACE("Enter CredFree\n");
	return pCredFree(Buffer);
}

extern WINAPI void wine32a_advapi32_CredFree(void);  /* ../dlls/advapi32/cred.c:1340 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredFree,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredFree") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredGetSessionTypes(DWORD  persistCount, LPDWORD  persists) /* ../dlls/advapi32/cred.c:1865 */
{
	TRACE("Enter CredGetSessionTypes\n");
	return pCredGetSessionTypes(persistCount, persists);
}

extern WINAPI void wine32a_advapi32_CredGetSessionTypes(void);  /* ../dlls/advapi32/cred.c:1865 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredGetSessionTypes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredGetSessionTypes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredIsMarshaledCredentialA(LPCSTR  name) /* ../dlls/advapi32/cred.c:2180 */
{
	TRACE("Enter CredIsMarshaledCredentialA\n");
	return pCredIsMarshaledCredentialA(name);
}

extern WINAPI void wine32a_advapi32_CredIsMarshaledCredentialA(void);  /* ../dlls/advapi32/cred.c:2180 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredIsMarshaledCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredIsMarshaledCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredIsMarshaledCredentialW(LPCWSTR  name) /* ../dlls/advapi32/cred.c:2146 */
{
	TRACE("Enter CredIsMarshaledCredentialW\n");
	return pCredIsMarshaledCredentialW(name);
}

extern WINAPI void wine32a_advapi32_CredIsMarshaledCredentialW(void);  /* ../dlls/advapi32/cred.c:2146 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredIsMarshaledCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredIsMarshaledCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredMarshalCredentialA(CRED_MARSHAL_TYPE  type, PVOID  cred, LPSTR*  out) /* ../dlls/advapi32/cred.c:1885 */
{
	TRACE("Enter CredMarshalCredentialA\n");
	return pCredMarshalCredentialA(type, cred, out);
}

extern WINAPI void wine32a_advapi32_CredMarshalCredentialA(void);  /* ../dlls/advapi32/cred.c:1885 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredMarshalCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredMarshalCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredMarshalCredentialW(CRED_MARSHAL_TYPE  type, PVOID  cred, LPWSTR*  out) /* ../dlls/advapi32/cred.c:1938 */
{
	TRACE("Enter CredMarshalCredentialW\n");
	return pCredMarshalCredentialW(type, cred, out);
}

extern WINAPI void wine32a_advapi32_CredMarshalCredentialW(void);  /* ../dlls/advapi32/cred.c:1938 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredMarshalCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredMarshalCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredReadA(LPCSTR  TargetName, DWORD  Type, DWORD  Flags, PCREDENTIALA*  Credential) /* ../dlls/advapi32/cred.c:1348 */
{
	TRACE("Enter CredReadA\n");
	return pCredReadA(TargetName, Type, Flags, Credential);
}

extern WINAPI void wine32a_advapi32_CredReadA(void);  /* ../dlls/advapi32/cred.c:1348 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredReadA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredReadA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredReadDomainCredentialsA(PCREDENTIAL_TARGET_INFORMATIONA  TargetInformation, DWORD  Flags, DWORD*  Size, PCREDENTIALA**  Credentials) /* ../dlls/advapi32/cred.c:1553 */
{
	TRACE("Enter CredReadDomainCredentialsA\n");
	return pCredReadDomainCredentialsA(TargetInformation, Flags, Size, Credentials);
}

extern WINAPI void wine32a_advapi32_CredReadDomainCredentialsA(void);  /* ../dlls/advapi32/cred.c:1553 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredReadDomainCredentialsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredReadDomainCredentialsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredReadDomainCredentialsW(PCREDENTIAL_TARGET_INFORMATIONW  TargetInformation, DWORD  Flags, DWORD*  Size, PCREDENTIALW**  Credentials) /* ../dlls/advapi32/cred.c:1699 */
{
	TRACE("Enter CredReadDomainCredentialsW\n");
	return pCredReadDomainCredentialsW(TargetInformation, Flags, Size, Credentials);
}

extern WINAPI void wine32a_advapi32_CredReadDomainCredentialsW(void);  /* ../dlls/advapi32/cred.c:1699 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredReadDomainCredentialsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredReadDomainCredentialsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredReadW(LPCWSTR  TargetName, DWORD  Type, DWORD  Flags, PCREDENTIALW*  Credential) /* ../dlls/advapi32/cred.c:1395 */
{
	TRACE("Enter CredReadW\n");
	return pCredReadW(TargetName, Type, Flags, Credential);
}

extern WINAPI void wine32a_advapi32_CredReadW(void);  /* ../dlls/advapi32/cred.c:1395 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredReadW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredReadW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredUnmarshalCredentialA(LPCSTR  cred, PCRED_MARSHAL_TYPE  type, PVOID*  out) /* ../dlls/advapi32/cred.c:1994 */
{
	TRACE("Enter CredUnmarshalCredentialA\n");
	return pCredUnmarshalCredentialA(cred, type, out);
}

extern WINAPI void wine32a_advapi32_CredUnmarshalCredentialA(void);  /* ../dlls/advapi32/cred.c:1994 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredUnmarshalCredentialA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredUnmarshalCredentialA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredUnmarshalCredentialW(LPCWSTR  cred, PCRED_MARSHAL_TYPE  type, PVOID*  out) /* ../dlls/advapi32/cred.c:2068 */
{
	TRACE("Enter CredUnmarshalCredentialW\n");
	return pCredUnmarshalCredentialW(cred, type, out);
}

extern WINAPI void wine32a_advapi32_CredUnmarshalCredentialW(void);  /* ../dlls/advapi32/cred.c:2068 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredUnmarshalCredentialW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredUnmarshalCredentialW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredWriteA(PCREDENTIALA  Credential, DWORD  Flags) /* ../dlls/advapi32/cred.c:1720 */
{
	TRACE("Enter CredWriteA\n");
	return pCredWriteA(Credential, Flags);
}

extern WINAPI void wine32a_advapi32_CredWriteA(void);  /* ../dlls/advapi32/cred.c:1720 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredWriteA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredWriteA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CredWriteW(PCREDENTIALW  Credential, DWORD  Flags) /* ../dlls/advapi32/cred.c:1754 */
{
	TRACE("Enter CredWriteW\n");
	return pCredWriteW(Credential, Flags);
}

extern WINAPI void wine32a_advapi32_CredWriteW(void);  /* ../dlls/advapi32/cred.c:1754 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CredWriteW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CredWriteW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptAcquireContextA(HCRYPTPROV*  phProv, LPCSTR  pszContainer, LPCSTR  pszProvider, DWORD  dwProvType, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:577 */
{
	TRACE("Enter CryptAcquireContextA\n");
	return pCryptAcquireContextA(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptAcquireContextA(void);  /* ../dlls/advapi32/crypt.c:577 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptAcquireContextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptAcquireContextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptAcquireContextW(HCRYPTPROV*  phProv, LPCWSTR  pszContainer, LPCWSTR  pszProvider, DWORD  dwProvType, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:365 */
{
	TRACE("Enter CryptAcquireContextW\n");
	return pCryptAcquireContextW(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptAcquireContextW(void);  /* ../dlls/advapi32/crypt.c:365 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptAcquireContextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptAcquireContextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptContextAddRef(HCRYPTPROV  hProv, DWORD*  pdwReserved, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:621 */
{
	TRACE("Enter CryptContextAddRef\n");
	return pCryptContextAddRef(hProv, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptContextAddRef(void);  /* ../dlls/advapi32/crypt.c:621 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptContextAddRef,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptContextAddRef") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptCreateHash(HCRYPTPROV  hProv, ALG_ID  Algid, HCRYPTKEY  hKey, DWORD  dwFlags, HCRYPTHASH*  phHash) /* ../dlls/advapi32/crypt.c:749 */
{
	TRACE("Enter CryptCreateHash\n");
	return pCryptCreateHash(hProv, Algid, hKey, dwFlags, phHash);
}

extern WINAPI void wine32a_advapi32_CryptCreateHash(void);  /* ../dlls/advapi32/crypt.c:749 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptCreateHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptCreateHash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptDecrypt(HCRYPTKEY  hKey, HCRYPTHASH  hHash, BOOL  Final, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen) /* ../dlls/advapi32/crypt.c:809 */
{
	TRACE("Enter CryptDecrypt\n");
	return pCryptDecrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen);
}

extern WINAPI void wine32a_advapi32_CryptDecrypt(void);  /* ../dlls/advapi32/crypt.c:809 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDecrypt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDecrypt") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptDeriveKey(HCRYPTPROV  hProv, ALG_ID  Algid, HCRYPTHASH  hBaseData, DWORD  dwFlags, HCRYPTKEY*  phKey) /* ../dlls/advapi32/crypt.c:847 */
{
	TRACE("Enter CryptDeriveKey\n");
	return pCryptDeriveKey(hProv, Algid, hBaseData, dwFlags, phKey);
}

extern WINAPI void wine32a_advapi32_CryptDeriveKey(void);  /* ../dlls/advapi32/crypt.c:847 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDeriveKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDeriveKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptDestroyHash(HCRYPTHASH  hHash) /* ../dlls/advapi32/crypt.c:899 */
{
	TRACE("Enter CryptDestroyHash\n");
	return pCryptDestroyHash(hHash);
}

extern WINAPI void wine32a_advapi32_CryptDestroyHash(void);  /* ../dlls/advapi32/crypt.c:899 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDestroyHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDestroyHash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptDestroyKey(HCRYPTKEY  hKey) /* ../dlls/advapi32/crypt.c:939 */
{
	TRACE("Enter CryptDestroyKey\n");
	return pCryptDestroyKey(hKey);
}

extern WINAPI void wine32a_advapi32_CryptDestroyKey(void);  /* ../dlls/advapi32/crypt.c:939 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDestroyKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDestroyKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptDuplicateHash(HCRYPTHASH  hHash, DWORD*  pdwReserved, DWORD  dwFlags, HCRYPTHASH*  phHash) /* ../dlls/advapi32/crypt.c:982 */
{
	TRACE("Enter CryptDuplicateHash\n");
	return pCryptDuplicateHash(hHash, pdwReserved, dwFlags, phHash);
}

extern WINAPI void wine32a_advapi32_CryptDuplicateHash(void);  /* ../dlls/advapi32/crypt.c:982 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDuplicateHash,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDuplicateHash") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptDuplicateKey(HCRYPTKEY  hKey, DWORD*  pdwReserved, DWORD  dwFlags, HCRYPTKEY*  phKey) /* ../dlls/advapi32/crypt.c:1038 */
{
	TRACE("Enter CryptDuplicateKey\n");
	return pCryptDuplicateKey(hKey, pdwReserved, dwFlags, phKey);
}

extern WINAPI void wine32a_advapi32_CryptDuplicateKey(void);  /* ../dlls/advapi32/crypt.c:1038 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptDuplicateKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptDuplicateKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptEncrypt(HCRYPTKEY  hKey, HCRYPTHASH  hHash, BOOL  Final, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwBufLen) /* ../dlls/advapi32/crypt.c:1102 */
{
	TRACE("Enter CryptEncrypt\n");
	return pCryptEncrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen);
}

extern WINAPI void wine32a_advapi32_CryptEncrypt(void);  /* ../dlls/advapi32/crypt.c:1102 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptEncrypt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptEncrypt") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptEnumProviderTypesA(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPSTR  pszTypeName, DWORD*  pcbTypeName) /* ../dlls/advapi32/crypt.c:1371 */
{
	TRACE("Enter CryptEnumProviderTypesA\n");
	return pCryptEnumProviderTypesA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
}

extern WINAPI void wine32a_advapi32_CryptEnumProviderTypesA(void);  /* ../dlls/advapi32/crypt.c:1371 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptEnumProviderTypesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptEnumProviderTypesA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptEnumProviderTypesW(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPWSTR  pszTypeName, DWORD*  pcbTypeName) /* ../dlls/advapi32/crypt.c:1292 */
{
	TRACE("Enter CryptEnumProviderTypesW\n");
	return pCryptEnumProviderTypesW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
}

extern WINAPI void wine32a_advapi32_CryptEnumProviderTypesW(void);  /* ../dlls/advapi32/crypt.c:1292 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptEnumProviderTypesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptEnumProviderTypesW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptEnumProvidersA(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPSTR  pszProvName, DWORD*  pcbProvName) /* ../dlls/advapi32/crypt.c:1237 */
{
	TRACE("Enter CryptEnumProvidersA\n");
	return pCryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_advapi32_CryptEnumProvidersA(void);  /* ../dlls/advapi32/crypt.c:1237 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptEnumProvidersA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptEnumProvidersA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptEnumProvidersW(DWORD  dwIndex, DWORD*  pdwReserved, DWORD  dwFlags, DWORD*  pdwProvType, LPWSTR  pszProvName, DWORD*  pcbProvName) /* ../dlls/advapi32/crypt.c:1145 */
{
	TRACE("Enter CryptEnumProvidersW\n");
	return pCryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_advapi32_CryptEnumProvidersW(void);  /* ../dlls/advapi32/crypt.c:1145 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptEnumProvidersW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptEnumProvidersW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptExportKey(HCRYPTKEY  hKey, HCRYPTKEY  hExpKey, DWORD  dwBlobType, DWORD  dwFlags, BYTE*  pbData, DWORD*  pdwDataLen) /* ../dlls/advapi32/crypt.c:1425 */
{
	TRACE("Enter CryptExportKey\n");
	return pCryptExportKey(hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen);
}

extern WINAPI void wine32a_advapi32_CryptExportKey(void);  /* ../dlls/advapi32/crypt.c:1425 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptExportKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptExportKey") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptGenKey(HCRYPTPROV  hProv, ALG_ID  Algid, DWORD  dwFlags, HCRYPTKEY*  phKey) /* ../dlls/advapi32/crypt.c:1460 */
{
	TRACE("Enter CryptGenKey\n");
	return pCryptGenKey(hProv, Algid, dwFlags, phKey);
}

extern WINAPI void wine32a_advapi32_CryptGenKey(void);  /* ../dlls/advapi32/crypt.c:1460 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGenKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGenKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGenRandom(HCRYPTPROV  hProv, DWORD  dwLen, BYTE*  pbBuffer) /* ../dlls/advapi32/crypt.c:709 */
{
	TRACE("Enter CryptGenRandom\n");
	return pCryptGenRandom(hProv, dwLen, pbBuffer);
}

extern WINAPI void wine32a_advapi32_CryptGenRandom(void);  /* ../dlls/advapi32/crypt.c:709 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGenRandom,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGenRandom") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetDefaultProviderA(DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags, LPSTR  pszProvName, DWORD*  pcbProvName) /* ../dlls/advapi32/crypt.c:1569 */
{
	TRACE("Enter CryptGetDefaultProviderA\n");
	return pCryptGetDefaultProviderA(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_advapi32_CryptGetDefaultProviderA(void);  /* ../dlls/advapi32/crypt.c:1569 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetDefaultProviderA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetDefaultProviderA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetDefaultProviderW(DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags, LPWSTR  pszProvName, DWORD*  pcbProvName) /* ../dlls/advapi32/crypt.c:1512 */
{
	TRACE("Enter CryptGetDefaultProviderW\n");
	return pCryptGetDefaultProviderW(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
}

extern WINAPI void wine32a_advapi32_CryptGetDefaultProviderW(void);  /* ../dlls/advapi32/crypt.c:1512 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetDefaultProviderW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetDefaultProviderW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetHashParam(HCRYPTHASH  hHash, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1619 */
{
	TRACE("Enter CryptGetHashParam\n");
	return pCryptGetHashParam(hHash, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptGetHashParam(void);  /* ../dlls/advapi32/crypt.c:1619 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetHashParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetHashParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetKeyParam(HCRYPTKEY  hKey, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1658 */
{
	TRACE("Enter CryptGetKeyParam\n");
	return pCryptGetKeyParam(hKey, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptGetKeyParam(void);  /* ../dlls/advapi32/crypt.c:1658 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetKeyParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetKeyParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetProvParam(HCRYPTPROV  hProv, DWORD  dwParam, BYTE*  pbData, DWORD*  pdwDataLen, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1697 */
{
	TRACE("Enter CryptGetProvParam\n");
	return pCryptGetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptGetProvParam(void);  /* ../dlls/advapi32/crypt.c:1697 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetProvParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetProvParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptGetUserKey(HCRYPTPROV  hProv, DWORD  dwKeySpec, HCRYPTKEY*  phUserKey) /* ../dlls/advapi32/crypt.c:1727 */
{
	TRACE("Enter CryptGetUserKey\n");
	return pCryptGetUserKey(hProv, dwKeySpec, phUserKey);
}

extern WINAPI void wine32a_advapi32_CryptGetUserKey(void);  /* ../dlls/advapi32/crypt.c:1727 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptGetUserKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptGetUserKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptHashData(HCRYPTHASH  hHash, BYTE*  pbData, DWORD  dwDataLen, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1780 */
{
	TRACE("Enter CryptHashData\n");
	return pCryptHashData(hHash, pbData, dwDataLen, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptHashData(void);  /* ../dlls/advapi32/crypt.c:1780 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptHashData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptHashData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptHashSessionKey(HCRYPTHASH  hHash, HCRYPTKEY  hKey, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1817 */
{
	TRACE("Enter CryptHashSessionKey\n");
	return pCryptHashSessionKey(hHash, hKey, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptHashSessionKey(void);  /* ../dlls/advapi32/crypt.c:1817 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptHashSessionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptHashSessionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptImportKey(HCRYPTPROV  hProv, BYTE*  pbData, DWORD  dwDataLen, HCRYPTKEY  hPubKey, DWORD  dwFlags, HCRYPTKEY*  phKey) /* ../dlls/advapi32/crypt.c:1859 */
{
	TRACE("Enter CryptImportKey\n");
	return pCryptImportKey(hProv, pbData, dwDataLen, hPubKey, dwFlags, phKey);
}

extern WINAPI void wine32a_advapi32_CryptImportKey(void);  /* ../dlls/advapi32/crypt.c:1859 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptImportKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptImportKey") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptReleaseContext(HCRYPTPROV  hProv, ULONG_PTR  dwFlags) /* ../dlls/advapi32/crypt.c:656 */
{
	TRACE("Enter CryptReleaseContext\n");
	return pCryptReleaseContext(hProv, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptReleaseContext(void);  /* ../dlls/advapi32/crypt.c:656 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptReleaseContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptReleaseContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetHashParam(HCRYPTHASH  hHash, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:1979 */
{
	TRACE("Enter CryptSetHashParam\n");
	return pCryptSetHashParam(hHash, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptSetHashParam(void);  /* ../dlls/advapi32/crypt.c:1979 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetHashParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetHashParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetKeyParam(HCRYPTKEY  hKey, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2013 */
{
	TRACE("Enter CryptSetKeyParam\n");
	return pCryptSetKeyParam(hKey, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptSetKeyParam(void);  /* ../dlls/advapi32/crypt.c:2013 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetKeyParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetKeyParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetProvParam(HCRYPTPROV  hProv, DWORD  dwParam, BYTE*  pbData, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2188 */
{
	TRACE("Enter CryptSetProvParam\n");
	return pCryptSetProvParam(hProv, dwParam, pbData, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptSetProvParam(void);  /* ../dlls/advapi32/crypt.c:2188 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetProvParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetProvParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetProviderA(LPCSTR  pszProvName, DWORD  dwProvType) /* ../dlls/advapi32/crypt.c:2045 */
{
	TRACE("Enter CryptSetProviderA\n");
	return pCryptSetProviderA(pszProvName, dwProvType);
}

extern WINAPI void wine32a_advapi32_CryptSetProviderA(void);  /* ../dlls/advapi32/crypt.c:2045 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetProviderA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetProviderA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetProviderExA(LPCSTR  pszProvName, DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2158 */
{
	TRACE("Enter CryptSetProviderExA\n");
	return pCryptSetProviderExA(pszProvName, dwProvType, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptSetProviderExA(void);  /* ../dlls/advapi32/crypt.c:2158 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetProviderExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetProviderExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetProviderExW(LPCWSTR  pszProvName, DWORD  dwProvType, DWORD*  pdwReserved, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2077 */
{
	TRACE("Enter CryptSetProviderExW\n");
	return pCryptSetProviderExW(pszProvName, dwProvType, pdwReserved, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptSetProviderExW(void);  /* ../dlls/advapi32/crypt.c:2077 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetProviderExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetProviderExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSetProviderW(LPCWSTR  pszProvName, DWORD  dwProvType) /* ../dlls/advapi32/crypt.c:2056 */
{
	TRACE("Enter CryptSetProviderW\n");
	return pCryptSetProviderW(pszProvName, dwProvType);
}

extern WINAPI void wine32a_advapi32_CryptSetProviderW(void);  /* ../dlls/advapi32/crypt.c:2056 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSetProviderW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSetProviderW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_CryptSignHashA(HCRYPTHASH  hHash, DWORD  dwKeySpec, LPCSTR  sDescription, DWORD  dwFlags, BYTE*  pbSignature, DWORD*  pdwSigLen) /* ../dlls/advapi32/crypt.c:1948 */
{
	TRACE("Enter CryptSignHashA\n");
	return pCryptSignHashA(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
}

extern WINAPI void wine32a_advapi32_CryptSignHashA(void);  /* ../dlls/advapi32/crypt.c:1948 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSignHashA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSignHashA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptSignHashW(HCRYPTHASH  hHash, DWORD  dwKeySpec, LPCWSTR  sDescription, DWORD  dwFlags, BYTE*  pbSignature, DWORD*  pdwSigLen) /* ../dlls/advapi32/crypt.c:1917 */
{
	TRACE("Enter CryptSignHashW\n");
	return pCryptSignHashW(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
}

extern WINAPI void wine32a_advapi32_CryptSignHashW(void);  /* ../dlls/advapi32/crypt.c:1917 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptSignHashW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptSignHashW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptVerifySignatureA(HCRYPTHASH  hHash, BYTE*  pbSignature, DWORD  dwSigLen, HCRYPTKEY  hPubKey, LPCSTR  sDescription, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2275 */
{
	TRACE("Enter CryptVerifySignatureA\n");
	return pCryptVerifySignatureA(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptVerifySignatureA(void);  /* ../dlls/advapi32/crypt.c:2275 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptVerifySignatureA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptVerifySignatureA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_CryptVerifySignatureW(HCRYPTHASH  hHash, BYTE*  pbSignature, DWORD  dwSigLen, HCRYPTKEY  hPubKey, LPCWSTR  sDescription, DWORD  dwFlags) /* ../dlls/advapi32/crypt.c:2247 */
{
	TRACE("Enter CryptVerifySignatureW\n");
	return pCryptVerifySignatureW(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
}

extern WINAPI void wine32a_advapi32_CryptVerifySignatureW(void);  /* ../dlls/advapi32/crypt.c:2247 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_CryptVerifySignatureW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_CryptVerifySignatureW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_DecryptFileA(LPCSTR  lpFileName, DWORD  dwReserved) /* ../dlls/advapi32/security.c:4191 */
{
	TRACE("Enter DecryptFileA\n");
	return pDecryptFileA(lpFileName, dwReserved);
}

extern WINAPI void wine32a_advapi32_DecryptFileA(void);  /* ../dlls/advapi32/security.c:4191 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_DecryptFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_DecryptFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_DecryptFileW(LPCWSTR  lpFileName, DWORD  dwReserved) /* ../dlls/advapi32/security.c:4182 */
{
	TRACE("Enter DecryptFileW\n");
	return pDecryptFileW(lpFileName, dwReserved);
}

extern WINAPI void wine32a_advapi32_DecryptFileW(void);  /* ../dlls/advapi32/security.c:4182 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_DecryptFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_DecryptFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_DeregisterEventSource(HANDLE  hEventLog) /* ../dlls/advapi32/eventlog.c:220 */
{
	TRACE("Enter DeregisterEventSource\n");
	return pDeregisterEventSource(hEventLog);
}

extern WINAPI void wine32a_advapi32_DeregisterEventSource(void);  /* ../dlls/advapi32/eventlog.c:220 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_DeregisterEventSource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_DeregisterEventSource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_EnableTrace(ULONG  enable, ULONG  flag, ULONG  level, LPCGUID  guid, TRACEHANDLE  hSession) /* ../dlls/advapi32/eventlog.c:258 */
{
	TRACE("Enter EnableTrace\n");
	return pEnableTrace(enable, flag, level, guid, hSession);
}

extern WINAPI void wine32a_advapi32_EnableTrace(void);  /* ../dlls/advapi32/eventlog.c:258 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EnableTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EnableTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_EnableTraceEx(LPCGUID  provider, LPCGUID  source, TRACEHANDLE  hSession, ULONG  enable, UCHAR  level, ULONGLONG  anykeyword, ULONGLONG  allkeyword, ULONG  enableprop, PEVENT_FILTER_DESCRIPTOR  filterdesc) /* ../dlls/advapi32/eventlog.c:229 */
{
	TRACE("Enter EnableTraceEx\n");
	return pEnableTraceEx(provider, source, hSession, enable, level, anykeyword, allkeyword, enableprop, filterdesc);
}

extern WINAPI void wine32a_advapi32_EnableTraceEx(void);  /* ../dlls/advapi32/eventlog.c:229 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EnableTraceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EnableTraceEx") "\n"
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

extern WINAPI ULONG wine32b_advapi32_EnableTraceEx2(TRACEHANDLE  handle, LPCGUID  provider, ULONG  control, UCHAR  level, ULONGLONG  match_any, ULONGLONG  match_all, ULONG  timeout, PENABLE_TRACE_PARAMETERS  params) /* ../dlls/advapi32/eventlog.c:244 */
{
	TRACE("Enter EnableTraceEx2\n");
	return pEnableTraceEx2(handle, provider, control, level, match_any, match_all, timeout, params);
}

extern WINAPI void wine32a_advapi32_EnableTraceEx2(void);  /* ../dlls/advapi32/eventlog.c:244 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EnableTraceEx2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EnableTraceEx2") "\n"
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

extern WINAPI BOOL wine32b_advapi32_EncryptFileA(LPCSTR  lpFileName) /* ../dlls/advapi32/security.c:4209 */
{
	TRACE("Enter EncryptFileA\n");
	return pEncryptFileA(lpFileName);
}

extern WINAPI void wine32a_advapi32_EncryptFileA(void);  /* ../dlls/advapi32/security.c:4209 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EncryptFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EncryptFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_EncryptFileW(LPCWSTR  lpFileName) /* ../dlls/advapi32/security.c:4200 */
{
	TRACE("Enter EncryptFileW\n");
	return pEncryptFileW(lpFileName);
}

extern WINAPI void wine32a_advapi32_EncryptFileW(void);  /* ../dlls/advapi32/security.c:4200 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EncryptFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EncryptFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_EnumerateTraceGuids(PTRACE_GUID_PROPERTIES*  propertiesarray, ULONG  arraycount, PULONG  guidcount) /* ../dlls/advapi32/eventlog.c:834 */
{
	TRACE("Enter EnumerateTraceGuids\n");
	return pEnumerateTraceGuids(propertiesarray, arraycount, guidcount);
}

extern WINAPI void wine32a_advapi32_EnumerateTraceGuids(void);  /* ../dlls/advapi32/eventlog.c:834 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_EnumerateTraceGuids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_EnumerateTraceGuids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_FileEncryptionStatusA(LPCSTR  lpFileName, LPDWORD  lpStatus) /* ../dlls/advapi32/security.c:4230 */
{
	TRACE("Enter FileEncryptionStatusA\n");
	return pFileEncryptionStatusA(lpFileName, lpStatus);
}

extern WINAPI void wine32a_advapi32_FileEncryptionStatusA(void);  /* ../dlls/advapi32/security.c:4230 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_FileEncryptionStatusA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_FileEncryptionStatusA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_FileEncryptionStatusW(LPCWSTR  lpFileName, LPDWORD  lpStatus) /* ../dlls/advapi32/security.c:4218 */
{
	TRACE("Enter FileEncryptionStatusW\n");
	return pFileEncryptionStatusW(lpFileName, lpStatus);
}

extern WINAPI void wine32a_advapi32_FileEncryptionStatusW(void);  /* ../dlls/advapi32/security.c:4218 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_FileEncryptionStatusW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_FileEncryptionStatusW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_FlushTraceA(TRACEHANDLE  hSession, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties) /* ../dlls/advapi32/eventlog.c:194 */
{
	TRACE("Enter FlushTraceA\n");
	return pFlushTraceA(hSession, SessionName, Properties);
}

extern WINAPI void wine32a_advapi32_FlushTraceA(void);  /* ../dlls/advapi32/eventlog.c:194 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_FlushTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_FlushTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_FlushTraceW(TRACEHANDLE  hSession, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties) /* ../dlls/advapi32/eventlog.c:202 */
{
	TRACE("Enter FlushTraceW\n");
	return pFlushTraceW(hSession, SessionName, Properties);
}

extern WINAPI void wine32a_advapi32_FlushTraceW(void);  /* ../dlls/advapi32/eventlog.c:202 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_FlushTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_FlushTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetAuditedPermissionsFromAclA(PACL  pacl, PTRUSTEEA  pTrustee, PACCESS_MASK  pSuccessfulAuditedRights, PACCESS_MASK  pFailedAuditRights) /* ../dlls/advapi32/security.c:2796 */
{
	TRACE("Enter GetAuditedPermissionsFromAclA\n");
	return pGetAuditedPermissionsFromAclA(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
}

extern WINAPI void wine32a_advapi32_GetAuditedPermissionsFromAclA(void);  /* ../dlls/advapi32/security.c:2796 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetAuditedPermissionsFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetAuditedPermissionsFromAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetAuditedPermissionsFromAclW(PACL  pacl, PTRUSTEEW  pTrustee, PACCESS_MASK  pSuccessfulAuditedRights, PACCESS_MASK  pFailedAuditRights) /* ../dlls/advapi32/security.c:2807 */
{
	TRACE("Enter GetAuditedPermissionsFromAclW\n");
	return pGetAuditedPermissionsFromAclW(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
}

extern WINAPI void wine32a_advapi32_GetAuditedPermissionsFromAclW(void);  /* ../dlls/advapi32/security.c:2807 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetAuditedPermissionsFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetAuditedPermissionsFromAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetCurrentHwProfileA(LPHW_PROFILE_INFOA  pInfo) /* ../dlls/advapi32/advapi.c:134 */
{
	TRACE("Enter GetCurrentHwProfileA\n");
	return pGetCurrentHwProfileA(pInfo);
}

extern WINAPI void wine32a_advapi32_GetCurrentHwProfileA(void);  /* ../dlls/advapi32/advapi.c:134 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetCurrentHwProfileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetCurrentHwProfileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetCurrentHwProfileW(LPHW_PROFILE_INFOW  pInfo) /* ../dlls/advapi32/advapi.c:148 */
{
	TRACE("Enter GetCurrentHwProfileW\n");
	return pGetCurrentHwProfileW(pInfo);
}

extern WINAPI void wine32a_advapi32_GetCurrentHwProfileW(void);  /* ../dlls/advapi32/advapi.c:148 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetCurrentHwProfileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetCurrentHwProfileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetEffectiveRightsFromAclA(PACL  pacl, PTRUSTEEA  pTrustee, PACCESS_MASK  pAccessRights) /* ../dlls/advapi32/security.c:499 */
{
	TRACE("Enter GetEffectiveRightsFromAclA\n");
	return pGetEffectiveRightsFromAclA(pacl, pTrustee, pAccessRights);
}

extern WINAPI void wine32a_advapi32_GetEffectiveRightsFromAclA(void);  /* ../dlls/advapi32/security.c:499 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetEffectiveRightsFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetEffectiveRightsFromAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetEffectiveRightsFromAclW(PACL  pacl, PTRUSTEEW  pTrustee, PACCESS_MASK  pAccessRights) /* ../dlls/advapi32/security.c:508 */
{
	TRACE("Enter GetEffectiveRightsFromAclW\n");
	return pGetEffectiveRightsFromAclW(pacl, pTrustee, pAccessRights);
}

extern WINAPI void wine32a_advapi32_GetEffectiveRightsFromAclW(void);  /* ../dlls/advapi32/security.c:508 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetEffectiveRightsFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetEffectiveRightsFromAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetEventLogInformation(HANDLE  hEventLog, DWORD  dwInfoLevel, LPVOID  lpBuffer, DWORD  cbBufSize, LPDWORD  pcbBytesNeeded) /* ../dlls/advapi32/eventlog.c:283 */
{
	TRACE("Enter GetEventLogInformation\n");
	return pGetEventLogInformation(hEventLog, dwInfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded);
}

extern WINAPI void wine32a_advapi32_GetEventLogInformation(void);  /* ../dlls/advapi32/eventlog.c:283 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetEventLogInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetEventLogInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetExplicitEntriesFromAclA(PACL  pacl, PULONG  pcCountOfExplicitEntries, PEXPLICIT_ACCESSA*  pListOfExplicitEntries) /* ../dlls/advapi32/security.c:2700 */
{
	TRACE("Enter GetExplicitEntriesFromAclA\n");
	return pGetExplicitEntriesFromAclA(pacl, pcCountOfExplicitEntries, pListOfExplicitEntries);
}

extern WINAPI void wine32a_advapi32_GetExplicitEntriesFromAclA(void);  /* ../dlls/advapi32/security.c:2700 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetExplicitEntriesFromAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetExplicitEntriesFromAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetExplicitEntriesFromAclW(PACL  pacl, PULONG  count, PEXPLICIT_ACCESSW*  list) /* ../dlls/advapi32/security.c:2710 */
{
	TRACE("Enter GetExplicitEntriesFromAclW\n");
	return pGetExplicitEntriesFromAclW(pacl, count, list);
}

extern WINAPI void wine32a_advapi32_GetExplicitEntriesFromAclW(void);  /* ../dlls/advapi32/security.c:2710 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetExplicitEntriesFromAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetExplicitEntriesFromAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetFileSecurityA(LPCSTR  lpFileName, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor, DWORD  nLength, LPDWORD  lpnLengthNeeded) /* ../dlls/advapi32/security.c:1011 */
{
	TRACE("Enter GetFileSecurityA\n");
	return pGetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded);
}

extern WINAPI void wine32a_advapi32_GetFileSecurityA(void);  /* ../dlls/advapi32/security.c:1011 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetFileSecurityA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetFileSecurityA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoA(LPSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID*  ppsidOwner, PSID*  ppsidGroup, PACL*  ppDacl, PACL*  ppSacl, PSECURITY_DESCRIPTOR*  ppSecurityDescriptor) /* ../dlls/advapi32/security.c:4070 */
{
	TRACE("Enter GetNamedSecurityInfoA\n");
	return pGetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
}

extern WINAPI void wine32a_advapi32_GetNamedSecurityInfoA(void);  /* ../dlls/advapi32/security.c:4070 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetNamedSecurityInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetNamedSecurityInfoA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoExA(LPCSTR  object, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, LPCSTR  provider, LPCSTR  property, PACTRL_ACCESSA*  access_list, PACTRL_AUDITA*  audit_list, LPSTR*  owner, LPSTR*  group) /* ../dlls/advapi32/security.c:4170 */
{
	TRACE("Enter GetNamedSecurityInfoExA\n");
	return pGetNamedSecurityInfoExA(object, type, info, provider, property, access_list, audit_list, owner, group);
}

extern WINAPI void wine32a_advapi32_GetNamedSecurityInfoExA(void);  /* ../dlls/advapi32/security.c:4170 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetNamedSecurityInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetNamedSecurityInfoExA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoExW(LPCWSTR  object, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, LPCWSTR  provider, LPCWSTR  property, PACTRL_ACCESSW*  access_list, PACTRL_AUDITW*  audit_list, LPWSTR*  owner, LPWSTR*  group) /* ../dlls/advapi32/security.c:4158 */
{
	TRACE("Enter GetNamedSecurityInfoExW\n");
	return pGetNamedSecurityInfoExW(object, type, info, provider, property, access_list, audit_list, owner, group);
}

extern WINAPI void wine32a_advapi32_GetNamedSecurityInfoExW(void);  /* ../dlls/advapi32/security.c:4158 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetNamedSecurityInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetNamedSecurityInfoExW") "\n"
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

extern WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoW(LPWSTR  name, SE_OBJECT_TYPE  type, SECURITY_INFORMATION  info, PSID*  owner, PSID*  group, PACL*  dacl, PACL*  sacl, PSECURITY_DESCRIPTOR*  descriptor) /* ../dlls/advapi32/security.c:4093 */
{
	TRACE("Enter GetNamedSecurityInfoW\n");
	return pGetNamedSecurityInfoW(name, type, info, owner, group, dacl, sacl, descriptor);
}

extern WINAPI void wine32a_advapi32_GetNamedSecurityInfoW(void);  /* ../dlls/advapi32/security.c:4093 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetNamedSecurityInfoW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_GetNumberOfEventLogRecords(HANDLE  hEventLog, PDWORD  NumberOfRecords) /* ../dlls/advapi32/eventlog.c:338 */
{
	TRACE("Enter GetNumberOfEventLogRecords\n");
	return pGetNumberOfEventLogRecords(hEventLog, NumberOfRecords);
}

extern WINAPI void wine32a_advapi32_GetNumberOfEventLogRecords(void);  /* ../dlls/advapi32/eventlog.c:338 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetNumberOfEventLogRecords,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetNumberOfEventLogRecords") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetOldestEventLogRecord(HANDLE  hEventLog, PDWORD  OldestRecord) /* ../dlls/advapi32/eventlog.c:373 */
{
	TRACE("Enter GetOldestEventLogRecord\n");
	return pGetOldestEventLogRecord(hEventLog, OldestRecord);
}

extern WINAPI void wine32a_advapi32_GetOldestEventLogRecord(void);  /* ../dlls/advapi32/eventlog.c:373 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetOldestEventLogRecord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetOldestEventLogRecord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_GetSecurityInfo(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID*  ppsidOwner, PSID*  ppsidGroup, PACL*  ppDacl, PACL*  ppSacl, PSECURITY_DESCRIPTOR*  ppSecurityDescriptor) /* ../dlls/advapi32/security.c:1781 */
{
	TRACE("Enter GetSecurityInfo\n");
	return pGetSecurityInfo(hObject, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
}

extern WINAPI void wine32a_advapi32_GetSecurityInfo(void);  /* ../dlls/advapi32/security.c:1781 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetSecurityInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetSecurityInfo") "\n"
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

extern WINAPI DWORD wine32b_advapi32_GetSecurityInfoExA(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, LPCSTR  lpProvider, LPCSTR  lpProperty, PACTRL_ACCESSA*  ppAccessList, PACTRL_AUDITA*  ppAuditList, LPSTR*  lppOwner, LPSTR*  lppGroup) /* ../dlls/advapi32/security.c:1869 */
{
	TRACE("Enter GetSecurityInfoExA\n");
	return pGetSecurityInfoExA(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
}

extern WINAPI void wine32a_advapi32_GetSecurityInfoExA(void);  /* ../dlls/advapi32/security.c:1869 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetSecurityInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetSecurityInfoExA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_GetSecurityInfoExW(HANDLE  hObject, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, LPCWSTR  lpProvider, LPCWSTR  lpProperty, PACTRL_ACCESSW*  ppAccessList, PACTRL_AUDITW*  ppAuditList, LPWSTR*  lppOwner, LPWSTR*  lppGroup) /* ../dlls/advapi32/security.c:1883 */
{
	TRACE("Enter GetSecurityInfoExW\n");
	return pGetSecurityInfoExW(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
}

extern WINAPI void wine32a_advapi32_GetSecurityInfoExW(void);  /* ../dlls/advapi32/security.c:1883 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetSecurityInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetSecurityInfoExW") "\n"
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

extern WINAPI TRUSTEE_FORM wine32b_advapi32_GetTrusteeFormA(PTRUSTEEA  pTrustee) /* ../dlls/advapi32/security.c:2155 */
{
	TRACE("Enter GetTrusteeFormA\n");
	return pGetTrusteeFormA(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeFormA(void);  /* ../dlls/advapi32/security.c:2155 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeFormA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeFormA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_FORM wine32b_advapi32_GetTrusteeFormW(PTRUSTEEW  pTrustee) /* ../dlls/advapi32/security.c:2168 */
{
	TRACE("Enter GetTrusteeFormW\n");
	return pGetTrusteeFormW(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeFormW(void);  /* ../dlls/advapi32/security.c:2168 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeFormW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeFormW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_advapi32_GetTrusteeNameA(PTRUSTEEA  pTrustee) /* ../dlls/advapi32/security.c:2181 */
{
	TRACE("Enter GetTrusteeNameA\n");
	return pGetTrusteeNameA(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeNameA(void);  /* ../dlls/advapi32/security.c:2181 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_advapi32_GetTrusteeNameW(PTRUSTEEW  pTrustee) /* ../dlls/advapi32/security.c:2194 */
{
	TRACE("Enter GetTrusteeNameW\n");
	return pGetTrusteeNameW(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeNameW(void);  /* ../dlls/advapi32/security.c:2194 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_TYPE wine32b_advapi32_GetTrusteeTypeA(PTRUSTEEA  pTrustee) /* ../dlls/advapi32/security.c:2207 */
{
	TRACE("Enter GetTrusteeTypeA\n");
	return pGetTrusteeTypeA(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeTypeA(void);  /* ../dlls/advapi32/security.c:2207 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeTypeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeTypeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRUSTEE_TYPE wine32b_advapi32_GetTrusteeTypeW(PTRUSTEEW  pTrustee) /* ../dlls/advapi32/security.c:2220 */
{
	TRACE("Enter GetTrusteeTypeW\n");
	return pGetTrusteeTypeW(pTrustee);
}

extern WINAPI void wine32a_advapi32_GetTrusteeTypeW(void);  /* ../dlls/advapi32/security.c:2220 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetTrusteeTypeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetTrusteeTypeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetUserNameA(LPSTR  lpszName, LPDWORD  lpSize) /* ../dlls/advapi32/advapi.c:57 */
{
	TRACE("Enter GetUserNameA\n");
	return pGetUserNameA(lpszName, lpSize);
}

extern WINAPI void wine32a_advapi32_GetUserNameA(void);  /* ../dlls/advapi32/advapi.c:57 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetUserNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetUserNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_GetUserNameW(LPWSTR  lpszName, LPDWORD  lpSize) /* ../dlls/advapi32/advapi.c:85 */
{
	TRACE("Enter GetUserNameW\n");
	return pGetUserNameW(lpszName, lpSize);
}

extern WINAPI void wine32a_advapi32_GetUserNameW(void);  /* ../dlls/advapi32/advapi.c:85 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_GetUserNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_GetUserNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_InitiateShutdownA(char*  name, char*  message, DWORD  seconds, DWORD  flags, DWORD  reason) /* ../dlls/advapi32/advapi.c:274 */
{
	TRACE("Enter InitiateShutdownA\n");
	return pInitiateShutdownA(name, message, seconds, flags, reason);
}

extern WINAPI void wine32a_advapi32_InitiateShutdownA(void);  /* ../dlls/advapi32/advapi.c:274 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateShutdownA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_InitiateShutdownW(WCHAR*  name, WCHAR*  message, DWORD  seconds, DWORD  flags, DWORD  reason) /* ../dlls/advapi32/advapi.c:283 */
{
	TRACE("Enter InitiateShutdownW\n");
	return pInitiateShutdownW(name, message, seconds, flags, reason);
}

extern WINAPI void wine32a_advapi32_InitiateShutdownW(void);  /* ../dlls/advapi32/advapi.c:283 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateShutdownW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownA(LPSTR  lpMachineName, LPSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown) /* ../dlls/advapi32/advapi.c:255 */
{
	TRACE("Enter InitiateSystemShutdownA\n");
	return pInitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
}

extern WINAPI void wine32a_advapi32_InitiateSystemShutdownA(void);  /* ../dlls/advapi32/advapi.c:255 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateSystemShutdownA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateSystemShutdownA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownExA(LPSTR  lpMachineName, LPSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown, DWORD  dwReason) /* ../dlls/advapi32/advapi.c:230 */
{
	TRACE("Enter InitiateSystemShutdownExA\n");
	return pInitiateSystemShutdownExA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
}

extern WINAPI void wine32a_advapi32_InitiateSystemShutdownExA(void);  /* ../dlls/advapi32/advapi.c:230 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateSystemShutdownExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateSystemShutdownExA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownExW(LPWSTR  lpMachineName, LPWSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown, DWORD  dwReason) /* ../dlls/advapi32/advapi.c:245 */
{
	TRACE("Enter InitiateSystemShutdownExW\n");
	return pInitiateSystemShutdownExW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
}

extern WINAPI void wine32a_advapi32_InitiateSystemShutdownExW(void);  /* ../dlls/advapi32/advapi.c:245 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateSystemShutdownExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateSystemShutdownExW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownW(LPWSTR  lpMachineName, LPWSTR  lpMessage, DWORD  dwTimeout, BOOL  bForceAppsClosed, BOOL  bRebootAfterShutdown) /* ../dlls/advapi32/advapi.c:263 */
{
	TRACE("Enter InitiateSystemShutdownW\n");
	return pInitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
}

extern WINAPI void wine32a_advapi32_InitiateSystemShutdownW(void);  /* ../dlls/advapi32/advapi.c:263 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_InitiateSystemShutdownW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_InitiateSystemShutdownW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_IsTextUnicode(LPCVOID  buf, INT  len, LPINT  flags) /* ../dlls/advapi32/advapi.c:168 */
{
	TRACE("Enter IsTextUnicode\n");
	return pIsTextUnicode(buf, len, flags);
}

extern WINAPI void wine32a_advapi32_IsTextUnicode(void);  /* ../dlls/advapi32/advapi.c:168 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_IsTextUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_IsTextUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LogonUserA(LPCSTR  lpszUsername, LPCSTR  lpszDomain, LPCSTR  lpszPassword, DWORD  dwLogonType, DWORD  dwLogonProvider, PHANDLE  phToken) /* ../dlls/advapi32/advapi.c:289 */
{
	TRACE("Enter LogonUserA\n");
	return pLogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
}

extern WINAPI void wine32a_advapi32_LogonUserA(void);  /* ../dlls/advapi32/advapi.c:289 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LogonUserA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LogonUserA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LogonUserW(LPCWSTR  lpszUsername, LPCWSTR  lpszDomain, LPCWSTR  lpszPassword, DWORD  dwLogonType, DWORD  dwLogonProvider, PHANDLE  phToken) /* ../dlls/advapi32/advapi.c:311 */
{
	TRACE("Enter LogonUserW\n");
	return pLogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
}

extern WINAPI void wine32a_advapi32_LogonUserW(void);  /* ../dlls/advapi32/advapi.c:311 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LogonUserW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LogonUserW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountNameA(LPCSTR  system, LPCSTR  account, PSID  sid, LPDWORD  cbSid, LPSTR  ReferencedDomainName, LPDWORD  cbReferencedDomainName, PSID_NAME_USE  name_use) /* ../dlls/advapi32/security.c:1356 */
{
	TRACE("Enter LookupAccountNameA\n");
	return pLookupAccountNameA(system, account, sid, cbSid, ReferencedDomainName, cbReferencedDomainName, name_use);
}

extern WINAPI void wine32a_advapi32_LookupAccountNameA(void);  /* ../dlls/advapi32/security.c:1356 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountNameA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountNameW(LPCWSTR  lpSystemName, LPCWSTR  lpAccountName, PSID  Sid, LPDWORD  cbSid, LPWSTR  ReferencedDomainName, LPDWORD  cchReferencedDomainName, PSID_NAME_USE  peUse) /* ../dlls/advapi32/security.c:1669 */
{
	TRACE("Enter LookupAccountNameW\n");
	return pLookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cchReferencedDomainName, peUse);
}

extern WINAPI void wine32a_advapi32_LookupAccountNameW(void);  /* ../dlls/advapi32/security.c:1669 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountNameW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountSidA(LPCSTR  system, PSID  sid, LPSTR  account, LPDWORD  accountSize, LPSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use) /* ../dlls/advapi32/security.c:1031 */
{
	TRACE("Enter LookupAccountSidA\n");
	return pLookupAccountSidA(system, sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_advapi32_LookupAccountSidA(void);  /* ../dlls/advapi32/security.c:1031 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountSidA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountSidA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountSidLocalA(PSID  sid, LPSTR  account, LPDWORD  accountSize, LPSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use) /* ../dlls/advapi32/security.c:1088 */
{
	TRACE("Enter LookupAccountSidLocalA\n");
	return pLookupAccountSidLocalA(sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_advapi32_LookupAccountSidLocalA(void);  /* ../dlls/advapi32/security.c:1088 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountSidLocalA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountSidLocalA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountSidLocalW(PSID  sid, LPWSTR  account, LPDWORD  accountSize, LPWSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use) /* ../dlls/advapi32/security.c:1279 */
{
	TRACE("Enter LookupAccountSidLocalW\n");
	return pLookupAccountSidLocalW(sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_advapi32_LookupAccountSidLocalW(void);  /* ../dlls/advapi32/security.c:1279 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountSidLocalW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountSidLocalW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupAccountSidW(LPCWSTR  system, PSID  sid, LPWSTR  account, LPDWORD  accountSize, LPWSTR  domain, LPDWORD  domainSize, PSID_NAME_USE  name_use) /* ../dlls/advapi32/security.c:1113 */
{
	TRACE("Enter LookupAccountSidW\n");
	return pLookupAccountSidW(system, sid, account, accountSize, domain, domainSize, name_use);
}

extern WINAPI void wine32a_advapi32_LookupAccountSidW(void);  /* ../dlls/advapi32/security.c:1113 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupAccountSidW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupAccountSidW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeDisplayNameA(LPCSTR  lpSystemName, LPCSTR  lpName, LPSTR  lpDisplayName, LPDWORD  cchDisplayName, LPDWORD  lpLanguageId) /* ../dlls/advapi32/security.c:858 */
{
	TRACE("Enter LookupPrivilegeDisplayNameA\n");
	return pLookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeDisplayNameA(void);  /* ../dlls/advapi32/security.c:858 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeDisplayNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeDisplayNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeDisplayNameW(LPCWSTR  lpSystemName, LPCWSTR  lpName, LPWSTR  lpDisplayName, LPDWORD  cchDisplayName, LPDWORD  lpLanguageId) /* ../dlls/advapi32/security.c:867 */
{
	TRACE("Enter LookupPrivilegeDisplayNameW\n");
	return pLookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeDisplayNameW(void);  /* ../dlls/advapi32/security.c:867 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeDisplayNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeDisplayNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeNameA(LPCSTR  lpSystemName, PLUID  lpLuid, LPSTR  lpName, LPDWORD  cchName) /* ../dlls/advapi32/security.c:882 */
{
	TRACE("Enter LookupPrivilegeNameA\n");
	return pLookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cchName);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeNameA(void);  /* ../dlls/advapi32/security.c:882 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeNameW(LPCWSTR  lpSystemName, PLUID  lpLuid, LPWSTR  lpName, LPDWORD  cchName) /* ../dlls/advapi32/security.c:956 */
{
	TRACE("Enter LookupPrivilegeNameW\n");
	return pLookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cchName);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeNameW(void);  /* ../dlls/advapi32/security.c:956 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeValueA(LPCSTR  lpSystemName, LPCSTR  lpName, PLUID  lpLuid) /* ../dlls/advapi32/security.c:844 */
{
	TRACE("Enter LookupPrivilegeValueA\n");
	return pLookupPrivilegeValueA(lpSystemName, lpName, lpLuid);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeValueA(void);  /* ../dlls/advapi32/security.c:844 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_LookupPrivilegeValueW(LPCWSTR  lpSystemName, LPCWSTR  lpName, PLUID  lpLuid) /* ../dlls/advapi32/security.c:797 */
{
	TRACE("Enter LookupPrivilegeValueW\n");
	return pLookupPrivilegeValueW(lpSystemName, lpName, lpLuid);
}

extern WINAPI void wine32a_advapi32_LookupPrivilegeValueW(void);  /* ../dlls/advapi32/security.c:797 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupPrivilegeValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupPrivilegeValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_LookupSecurityDescriptorPartsA(TRUSTEEA*  owner, TRUSTEEA*  group, ULONG*  access_count, EXPLICIT_ACCESSA*  access_list, ULONG*  audit_count, EXPLICIT_ACCESSA*  audit_list, SECURITY_DESCRIPTOR*  descriptor) /* ../dlls/advapi32/security.c:4510 */
{
	TRACE("Enter LookupSecurityDescriptorPartsA\n");
	return pLookupSecurityDescriptorPartsA(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
}

extern WINAPI void wine32a_advapi32_LookupSecurityDescriptorPartsA(void);  /* ../dlls/advapi32/security.c:4510 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupSecurityDescriptorPartsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupSecurityDescriptorPartsA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_LookupSecurityDescriptorPartsW(TRUSTEEW*  owner, TRUSTEEW*  group, ULONG*  access_count, EXPLICIT_ACCESSW*  access_list, ULONG*  audit_count, EXPLICIT_ACCESSW*  audit_list, SECURITY_DESCRIPTOR*  descriptor) /* ../dlls/advapi32/security.c:4522 */
{
	TRACE("Enter LookupSecurityDescriptorPartsW\n");
	return pLookupSecurityDescriptorPartsW(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
}

extern WINAPI void wine32a_advapi32_LookupSecurityDescriptorPartsW(void);  /* ../dlls/advapi32/security.c:4522 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LookupSecurityDescriptorPartsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LookupSecurityDescriptorPartsW") "\n"
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

extern WINAPI NTSTATUS wine32b_advapi32_LsaAddAccountRights(LSA_HANDLE  policy, PSID  sid, PLSA_UNICODE_STRING  rights, ULONG  count) /* ../dlls/advapi32/lsa.c:120 */
{
	TRACE("Enter LsaAddAccountRights\n");
	return pLsaAddAccountRights(policy, sid, rights, count);
}

extern WINAPI void wine32a_advapi32_LsaAddAccountRights(void);  /* ../dlls/advapi32/lsa.c:120 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaAddAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaAddAccountRights") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaClose(LSA_HANDLE  ObjectHandle) /* ../dlls/advapi32/lsa.c:142 */
{
	TRACE("Enter LsaClose\n");
	return pLsaClose(ObjectHandle);
}

extern WINAPI void wine32a_advapi32_LsaClose(void);  /* ../dlls/advapi32/lsa.c:142 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaClose,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaClose") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaCreateTrustedDomainEx(LSA_HANDLE  policy, PTRUSTED_DOMAIN_INFORMATION_EX  domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION  auth_info, ACCESS_MASK  access, PLSA_HANDLE  domain) /* ../dlls/advapi32/lsa.c:152 */
{
	TRACE("Enter LsaCreateTrustedDomainEx\n");
	return pLsaCreateTrustedDomainEx(policy, domain_info, auth_info, access, domain);
}

extern WINAPI void wine32a_advapi32_LsaCreateTrustedDomainEx(void);  /* ../dlls/advapi32/lsa.c:152 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaCreateTrustedDomainEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaCreateTrustedDomainEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaDeleteTrustedDomain(LSA_HANDLE  policy, PSID  sid) /* ../dlls/advapi32/lsa.c:168 */
{
	TRACE("Enter LsaDeleteTrustedDomain\n");
	return pLsaDeleteTrustedDomain(policy, sid);
}

extern WINAPI void wine32a_advapi32_LsaDeleteTrustedDomain(void);  /* ../dlls/advapi32/lsa.c:168 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaDeleteTrustedDomain,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaDeleteTrustedDomain") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateAccountRights(LSA_HANDLE  policy, PSID  sid, PLSA_UNICODE_STRING*  rights, PULONG  count) /* ../dlls/advapi32/lsa.c:178 */
{
	TRACE("Enter LsaEnumerateAccountRights\n");
	return pLsaEnumerateAccountRights(policy, sid, rights, count);
}

extern WINAPI void wine32a_advapi32_LsaEnumerateAccountRights(void);  /* ../dlls/advapi32/lsa.c:178 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaEnumerateAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaEnumerateAccountRights") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateAccountsWithUserRight(LSA_HANDLE  policy, PLSA_UNICODE_STRING  rights, PVOID*  buffer, PULONG  count) /* ../dlls/advapi32/lsa.c:194 */
{
	TRACE("Enter LsaEnumerateAccountsWithUserRight\n");
	return pLsaEnumerateAccountsWithUserRight(policy, rights, buffer, count);
}

extern WINAPI void wine32a_advapi32_LsaEnumerateAccountsWithUserRight(void);  /* ../dlls/advapi32/lsa.c:194 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaEnumerateAccountsWithUserRight,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaEnumerateAccountsWithUserRight") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateTrustedDomains(LSA_HANDLE  PolicyHandle, PLSA_ENUMERATION_HANDLE  EnumerationContext, PVOID*  Buffer, ULONG  PreferredMaximumLength, PULONG  CountReturned) /* ../dlls/advapi32/lsa.c:226 */
{
	TRACE("Enter LsaEnumerateTrustedDomains\n");
	return pLsaEnumerateTrustedDomains(PolicyHandle, EnumerationContext, Buffer, PreferredMaximumLength, CountReturned);
}

extern WINAPI void wine32a_advapi32_LsaEnumerateTrustedDomains(void);  /* ../dlls/advapi32/lsa.c:226 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaEnumerateTrustedDomains,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaEnumerateTrustedDomains") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateTrustedDomainsEx(LSA_HANDLE  policy, PLSA_ENUMERATION_HANDLE  context, PVOID*  buffer, ULONG  length, PULONG  count) /* ../dlls/advapi32/lsa.c:244 */
{
	TRACE("Enter LsaEnumerateTrustedDomainsEx\n");
	return pLsaEnumerateTrustedDomainsEx(policy, context, buffer, length, count);
}

extern WINAPI void wine32a_advapi32_LsaEnumerateTrustedDomainsEx(void);  /* ../dlls/advapi32/lsa.c:244 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaEnumerateTrustedDomainsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaEnumerateTrustedDomainsEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaFreeMemory(PVOID  Buffer) /* ../dlls/advapi32/lsa.c:269 */
{
	TRACE("Enter LsaFreeMemory\n");
	return pLsaFreeMemory(Buffer);
}

extern WINAPI void wine32a_advapi32_LsaFreeMemory(void);  /* ../dlls/advapi32/lsa.c:269 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaFreeMemory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaFreeMemory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaLookupNames(LSA_HANDLE  PolicyHandle, ULONG  Count, PLSA_UNICODE_STRING  Names, PLSA_REFERENCED_DOMAIN_LIST*  ReferencedDomains, PLSA_TRANSLATED_SID*  Sids) /* ../dlls/advapi32/lsa.c:294 */
{
	TRACE("Enter LsaLookupNames\n");
	return pLsaLookupNames(PolicyHandle, Count, Names, ReferencedDomains, Sids);
}

extern WINAPI void wine32a_advapi32_LsaLookupNames(void);  /* ../dlls/advapi32/lsa.c:294 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaLookupNames,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaLookupNames") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaLookupNames2(LSA_HANDLE  policy, ULONG  flags, ULONG  count, PLSA_UNICODE_STRING  names, PLSA_REFERENCED_DOMAIN_LIST*  domains, PLSA_TRANSLATED_SID2*  sids) /* ../dlls/advapi32/lsa.c:373 */
{
	TRACE("Enter LsaLookupNames2\n");
	return pLsaLookupNames2(policy, flags, count, names, domains, sids);
}

extern WINAPI void wine32a_advapi32_LsaLookupNames2(void);  /* ../dlls/advapi32/lsa.c:373 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaLookupNames2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaLookupNames2") "\n"
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

extern WINAPI NTSTATUS wine32b_advapi32_LsaLookupPrivilegeDisplayName(LSA_HANDLE  handle, LSA_UNICODE_STRING*  name, LSA_UNICODE_STRING**  display_name, SHORT*  language) /* ../dlls/advapi32/lsa.c:1068 */
{
	TRACE("Enter LsaLookupPrivilegeDisplayName\n");
	return pLsaLookupPrivilegeDisplayName(handle, name, display_name, language);
}

extern WINAPI void wine32a_advapi32_LsaLookupPrivilegeDisplayName(void);  /* ../dlls/advapi32/lsa.c:1068 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaLookupPrivilegeDisplayName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaLookupPrivilegeDisplayName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaLookupPrivilegeName(LSA_HANDLE  handle, LUID*  luid, LSA_UNICODE_STRING**  name) /* ../dlls/advapi32/lsa.c:1035 */
{
	TRACE("Enter LsaLookupPrivilegeName\n");
	return pLsaLookupPrivilegeName(handle, luid, name);
}

extern WINAPI void wine32a_advapi32_LsaLookupPrivilegeName(void);  /* ../dlls/advapi32/lsa.c:1035 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaLookupPrivilegeName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaLookupPrivilegeName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaLookupSids(LSA_HANDLE  PolicyHandle, ULONG  Count, PSID*  Sids, LSA_REFERENCED_DOMAIN_LIST**  ReferencedDomains, LSA_TRANSLATED_NAME**  Names) /* ../dlls/advapi32/lsa.c:476 */
{
	TRACE("Enter LsaLookupSids\n");
	return pLsaLookupSids(PolicyHandle, Count, Sids, ReferencedDomains, Names);
}

extern WINAPI void wine32a_advapi32_LsaLookupSids(void);  /* ../dlls/advapi32/lsa.c:476 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaLookupSids,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaLookupSids") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_LsaNtStatusToWinError(NTSTATUS  Status) /* ../dlls/advapi32/lsa.c:628 */
{
	TRACE("Enter LsaNtStatusToWinError\n");
	return pLsaNtStatusToWinError(Status);
}

extern WINAPI void wine32a_advapi32_LsaNtStatusToWinError(void);  /* ../dlls/advapi32/lsa.c:628 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaNtStatusToWinError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaNtStatusToWinError") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaOpenPolicy(PLSA_UNICODE_STRING  SystemName, PLSA_OBJECT_ATTRIBUTES  ObjectAttributes, ACCESS_MASK  DesiredAccess, PLSA_HANDLE  PolicyHandle) /* ../dlls/advapi32/lsa.c:651 */
{
	TRACE("Enter LsaOpenPolicy\n");
	return pLsaOpenPolicy(SystemName, ObjectAttributes, DesiredAccess, PolicyHandle);
}

extern WINAPI void wine32a_advapi32_LsaOpenPolicy(void);  /* ../dlls/advapi32/lsa.c:651 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaOpenPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaOpenPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaOpenTrustedDomainByName(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, ACCESS_MASK  access, PLSA_HANDLE  handle) /* ../dlls/advapi32/lsa.c:673 */
{
	TRACE("Enter LsaOpenTrustedDomainByName\n");
	return pLsaOpenTrustedDomainByName(policy, name, access, handle);
}

extern WINAPI void wine32a_advapi32_LsaOpenTrustedDomainByName(void);  /* ../dlls/advapi32/lsa.c:673 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaOpenTrustedDomainByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaOpenTrustedDomainByName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaQueryInformationPolicy(LSA_HANDLE  PolicyHandle, POLICY_INFORMATION_CLASS  InformationClass, PVOID*  Buffer) /* ../dlls/advapi32/lsa.c:697 */
{
	TRACE("Enter LsaQueryInformationPolicy\n");
	return pLsaQueryInformationPolicy(PolicyHandle, InformationClass, Buffer);
}

extern WINAPI void wine32a_advapi32_LsaQueryInformationPolicy(void);  /* ../dlls/advapi32/lsa.c:697 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaQueryInformationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaQueryInformationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaQueryTrustedDomainInfo(LSA_HANDLE  policy, PSID  sid, TRUSTED_INFORMATION_CLASS  class, PVOID*  buffer) /* ../dlls/advapi32/lsa.c:846 */
{
	TRACE("Enter LsaQueryTrustedDomainInfo\n");
	return pLsaQueryTrustedDomainInfo(policy, sid, class, buffer);
}

extern WINAPI void wine32a_advapi32_LsaQueryTrustedDomainInfo(void);  /* ../dlls/advapi32/lsa.c:846 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaQueryTrustedDomainInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaQueryTrustedDomainInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaQueryTrustedDomainInfoByName(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, TRUSTED_INFORMATION_CLASS  class, PVOID*  buffer) /* ../dlls/advapi32/lsa.c:860 */
{
	TRACE("Enter LsaQueryTrustedDomainInfoByName\n");
	return pLsaQueryTrustedDomainInfoByName(policy, name, class, buffer);
}

extern WINAPI void wine32a_advapi32_LsaQueryTrustedDomainInfoByName(void);  /* ../dlls/advapi32/lsa.c:860 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaQueryTrustedDomainInfoByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaQueryTrustedDomainInfoByName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaRegisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS  class, HANDLE  event) /* ../dlls/advapi32/lsa.c:874 */
{
	TRACE("Enter LsaRegisterPolicyChangeNotification\n");
	return pLsaRegisterPolicyChangeNotification(class, event);
}

extern WINAPI void wine32a_advapi32_LsaRegisterPolicyChangeNotification(void);  /* ../dlls/advapi32/lsa.c:874 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaRegisterPolicyChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaRegisterPolicyChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaRemoveAccountRights(LSA_HANDLE  policy, PSID  sid, BOOLEAN  all, PLSA_UNICODE_STRING  rights, ULONG  count) /* ../dlls/advapi32/lsa.c:886 */
{
	TRACE("Enter LsaRemoveAccountRights\n");
	return pLsaRemoveAccountRights(policy, sid, all, rights, count);
}

extern WINAPI void wine32a_advapi32_LsaRemoveAccountRights(void);  /* ../dlls/advapi32/lsa.c:886 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaRemoveAccountRights,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaRemoveAccountRights") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaRetrievePrivateData(LSA_HANDLE  PolicyHandle, PLSA_UNICODE_STRING  KeyName, PLSA_UNICODE_STRING*  PrivateData) /* ../dlls/advapi32/lsa.c:911 */
{
	TRACE("Enter LsaRetrievePrivateData\n");
	return pLsaRetrievePrivateData(PolicyHandle, KeyName, PrivateData);
}

extern WINAPI void wine32a_advapi32_LsaRetrievePrivateData(void);  /* ../dlls/advapi32/lsa.c:911 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaRetrievePrivateData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaRetrievePrivateData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaSetInformationPolicy(LSA_HANDLE  PolicyHandle, POLICY_INFORMATION_CLASS  InformationClass, PVOID  Buffer) /* ../dlls/advapi32/lsa.c:934 */
{
	TRACE("Enter LsaSetInformationPolicy\n");
	return pLsaSetInformationPolicy(PolicyHandle, InformationClass, Buffer);
}

extern WINAPI void wine32a_advapi32_LsaSetInformationPolicy(void);  /* ../dlls/advapi32/lsa.c:934 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaSetInformationPolicy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaSetInformationPolicy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaSetSecret(LSA_HANDLE  SecretHandle, PLSA_UNICODE_STRING  EncryptedCurrentValue, PLSA_UNICODE_STRING  EncryptedOldValue) /* ../dlls/advapi32/lsa.c:958 */
{
	TRACE("Enter LsaSetSecret\n");
	return pLsaSetSecret(SecretHandle, EncryptedCurrentValue, EncryptedOldValue);
}

extern WINAPI void wine32a_advapi32_LsaSetSecret(void);  /* ../dlls/advapi32/lsa.c:958 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaSetSecret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaSetSecret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaSetTrustedDomainInfoByName(LSA_HANDLE  policy, PLSA_UNICODE_STRING  name, TRUSTED_INFORMATION_CLASS  class, PVOID  buffer) /* ../dlls/advapi32/lsa.c:972 */
{
	TRACE("Enter LsaSetTrustedDomainInfoByName\n");
	return pLsaSetTrustedDomainInfoByName(policy, name, class, buffer);
}

extern WINAPI void wine32a_advapi32_LsaSetTrustedDomainInfoByName(void);  /* ../dlls/advapi32/lsa.c:972 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaSetTrustedDomainInfoByName,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaSetTrustedDomainInfoByName") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaSetTrustedDomainInformation(LSA_HANDLE  policy, PSID  sid, TRUSTED_INFORMATION_CLASS  class, PVOID  buffer) /* ../dlls/advapi32/lsa.c:986 */
{
	TRACE("Enter LsaSetTrustedDomainInformation\n");
	return pLsaSetTrustedDomainInformation(policy, sid, class, buffer);
}

extern WINAPI void wine32a_advapi32_LsaSetTrustedDomainInformation(void);  /* ../dlls/advapi32/lsa.c:986 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaSetTrustedDomainInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaSetTrustedDomainInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaStorePrivateData(LSA_HANDLE  PolicyHandle, PLSA_UNICODE_STRING  KeyName, PLSA_UNICODE_STRING  PrivateData) /* ../dlls/advapi32/lsa.c:1010 */
{
	TRACE("Enter LsaStorePrivateData\n");
	return pLsaStorePrivateData(PolicyHandle, KeyName, PrivateData);
}

extern WINAPI void wine32a_advapi32_LsaStorePrivateData(void);  /* ../dlls/advapi32/lsa.c:1010 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaStorePrivateData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaStorePrivateData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_LsaUnregisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS  class, HANDLE  event) /* ../dlls/advapi32/lsa.c:1023 */
{
	TRACE("Enter LsaUnregisterPolicyChangeNotification\n");
	return pLsaUnregisterPolicyChangeNotification(class, event);
}

extern WINAPI void wine32a_advapi32_LsaUnregisterPolicyChangeNotification(void);  /* ../dlls/advapi32/lsa.c:1023 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_LsaUnregisterPolicyChangeNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_LsaUnregisterPolicyChangeNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_NotifyBootConfigStatus(BOOL  x1) /* ../dlls/advapi32/security.c:1346 */
{
	TRACE("Enter NotifyBootConfigStatus\n");
	return pNotifyBootConfigStatus(x1);
}

extern WINAPI void wine32a_advapi32_NotifyBootConfigStatus(void);  /* ../dlls/advapi32/security.c:1346 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_NotifyBootConfigStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_NotifyBootConfigStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_NotifyChangeEventLog(HANDLE  hEventLog, HANDLE  hEvent) /* ../dlls/advapi32/eventlog.c:408 */
{
	TRACE("Enter NotifyChangeEventLog\n");
	return pNotifyChangeEventLog(hEventLog, hEvent);
}

extern WINAPI void wine32a_advapi32_NotifyChangeEventLog(void);  /* ../dlls/advapi32/eventlog.c:408 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_NotifyChangeEventLog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_NotifyChangeEventLog") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ObjectCloseAuditAlarmA(LPCSTR  SubsystemName, LPVOID  HandleId, BOOL  GenerateOnClose) /* ../dlls/advapi32/security.c:1724 */
{
	TRACE("Enter ObjectCloseAuditAlarmA\n");
	return pObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose);
}

extern WINAPI void wine32a_advapi32_ObjectCloseAuditAlarmA(void);  /* ../dlls/advapi32/security.c:1724 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ObjectCloseAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ObjectCloseAuditAlarmA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ObjectOpenAuditAlarmA(LPCSTR  SubsystemName, LPVOID  HandleId, LPSTR  ObjectTypeName, LPSTR  ObjectName, PSECURITY_DESCRIPTOR  pSecurityDescriptor, HANDLE  ClientToken, DWORD  DesiredAccess, DWORD  GrantedAccess, PPRIVILEGE_SET  Privileges, BOOL  ObjectCreation, BOOL  AccessGranted, LPBOOL  GenerateOnClose) /* ../dlls/advapi32/security.c:1731 */
{
	TRACE("Enter ObjectOpenAuditAlarmA\n");
	return pObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose);
}

extern WINAPI void wine32a_advapi32_ObjectOpenAuditAlarmA(void);  /* ../dlls/advapi32/security.c:1731 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ObjectOpenAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ObjectOpenAuditAlarmA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_ObjectPrivilegeAuditAlarmA(LPCSTR  SubsystemName, LPVOID  HandleId, HANDLE  ClientToken, DWORD  DesiredAccess, PPRIVILEGE_SET  Privileges, BOOL  AccessGranted) /* ../dlls/advapi32/security.c:1744 */
{
	TRACE("Enter ObjectPrivilegeAuditAlarmA\n");
	return pObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted);
}

extern WINAPI void wine32a_advapi32_ObjectPrivilegeAuditAlarmA(void);  /* ../dlls/advapi32/security.c:1744 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ObjectPrivilegeAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ObjectPrivilegeAuditAlarmA") "\n"
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

extern WINAPI HANDLE wine32b_advapi32_OpenBackupEventLogA(LPCSTR  lpUNCServerName, LPCSTR  lpFileName) /* ../dlls/advapi32/eventlog.c:428 */
{
	TRACE("Enter OpenBackupEventLogA\n");
	return pOpenBackupEventLogA(lpUNCServerName, lpFileName);
}

extern WINAPI void wine32a_advapi32_OpenBackupEventLogA(void);  /* ../dlls/advapi32/eventlog.c:428 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenBackupEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenBackupEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_advapi32_OpenBackupEventLogW(LPCWSTR  lpUNCServerName, LPCWSTR  lpFileName) /* ../dlls/advapi32/eventlog.c:447 */
{
	TRACE("Enter OpenBackupEventLogW\n");
	return pOpenBackupEventLogW(lpUNCServerName, lpFileName);
}

extern WINAPI void wine32a_advapi32_OpenBackupEventLogW(void);  /* ../dlls/advapi32/eventlog.c:447 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenBackupEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenBackupEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_OpenEncryptedFileRawA(LPCSTR  filename, ULONG  flags, PVOID*  context) /* ../dlls/advapi32/crypt.c:2296 */
{
	TRACE("Enter OpenEncryptedFileRawA\n");
	return pOpenEncryptedFileRawA(filename, flags, context);
}

extern WINAPI void wine32a_advapi32_OpenEncryptedFileRawA(void);  /* ../dlls/advapi32/crypt.c:2296 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenEncryptedFileRawA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenEncryptedFileRawA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_OpenEncryptedFileRawW(LPCWSTR  filename, ULONG  flags, PVOID*  context) /* ../dlls/advapi32/crypt.c:2315 */
{
	TRACE("Enter OpenEncryptedFileRawW\n");
	return pOpenEncryptedFileRawW(filename, flags, context);
}

extern WINAPI void wine32a_advapi32_OpenEncryptedFileRawW(void);  /* ../dlls/advapi32/crypt.c:2315 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenEncryptedFileRawW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenEncryptedFileRawW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_advapi32_OpenEventLogA(LPCSTR  uncname, LPCSTR  source) /* ../dlls/advapi32/eventlog.c:487 */
{
	TRACE("Enter OpenEventLogA\n");
	return pOpenEventLogA(uncname, source);
}

extern WINAPI void wine32a_advapi32_OpenEventLogA(void);  /* ../dlls/advapi32/eventlog.c:487 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenEventLogA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_advapi32_OpenEventLogW(LPCWSTR  uncname, LPCWSTR  source) /* ../dlls/advapi32/eventlog.c:506 */
{
	TRACE("Enter OpenEventLogW\n");
	return pOpenEventLogW(uncname, source);
}

extern WINAPI void wine32a_advapi32_OpenEventLogW(void);  /* ../dlls/advapi32/eventlog.c:506 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenEventLogW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRACEHANDLE wine32b_advapi32_OpenTraceA(PEVENT_TRACE_LOGFILEA  logfile) /* ../dlls/advapi32/eventlog.c:792 */
{
	TRACE("Enter OpenTraceA\n");
	return pOpenTraceA(logfile);
}

extern WINAPI void wine32a_advapi32_OpenTraceA(void);  /* ../dlls/advapi32/eventlog.c:792 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI TRACEHANDLE wine32b_advapi32_OpenTraceW(PEVENT_TRACE_LOGFILEW  logfile) /* ../dlls/advapi32/eventlog.c:804 */
{
	TRACE("Enter OpenTraceW\n");
	return pOpenTraceW(logfile);
}

extern WINAPI void wine32a_advapi32_OpenTraceW(void);  /* ../dlls/advapi32/eventlog.c:804 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_OpenTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_OpenTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_PrivilegedServiceAuditAlarmA(LPCSTR  SubsystemName, LPCSTR  ServiceName, HANDLE  ClientToken, PPRIVILEGE_SET  Privileges, BOOL  AccessGranted) /* ../dlls/advapi32/security.c:1753 */
{
	TRACE("Enter PrivilegedServiceAuditAlarmA\n");
	return pPrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted);
}

extern WINAPI void wine32a_advapi32_PrivilegedServiceAuditAlarmA(void);  /* ../dlls/advapi32/security.c:1753 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_PrivilegedServiceAuditAlarmA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_PrivilegedServiceAuditAlarmA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_ProcessTrace(PTRACEHANDLE  HandleArray, ULONG  HandleCount, LPFILETIME  StartTime, LPFILETIME  EndTime) /* ../dlls/advapi32/eventlog.c:816 */
{
	TRACE("Enter ProcessTrace\n");
	return pProcessTrace(HandleArray, HandleCount, StartTime, EndTime);
}

extern WINAPI void wine32a_advapi32_ProcessTrace(void);  /* ../dlls/advapi32/eventlog.c:816 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ProcessTrace,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ProcessTrace") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_QueryAllTracesA(PEVENT_TRACE_PROPERTIES*  parray, ULONG  arraycount, PULONG  psessioncount) /* ../dlls/advapi32/eventlog.c:545 */
{
	TRACE("Enter QueryAllTracesA\n");
	return pQueryAllTracesA(parray, arraycount, psessioncount);
}

extern WINAPI void wine32a_advapi32_QueryAllTracesA(void);  /* ../dlls/advapi32/eventlog.c:545 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_QueryAllTracesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_QueryAllTracesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_QueryAllTracesW(PEVENT_TRACE_PROPERTIES*  parray, ULONG  arraycount, PULONG  psessioncount) /* ../dlls/advapi32/eventlog.c:532 */
{
	TRACE("Enter QueryAllTracesW\n");
	return pQueryAllTracesW(parray, arraycount, psessioncount);
}

extern WINAPI void wine32a_advapi32_QueryAllTracesW(void);  /* ../dlls/advapi32/eventlog.c:532 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_QueryAllTracesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_QueryAllTracesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_QueryTraceW(TRACEHANDLE  handle, LPCWSTR  sessionname, PEVENT_TRACE_PROPERTIES  properties) /* ../dlls/advapi32/eventlog.c:783 */
{
	TRACE("Enter QueryTraceW\n");
	return pQueryTraceW(handle, sessionname, properties);
}

extern WINAPI void wine32a_advapi32_QueryTraceW(void);  /* ../dlls/advapi32/eventlog.c:783 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_QueryTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_QueryTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_QueryWindows31FilesMigration(DWORD  x1) /* ../dlls/advapi32/security.c:1316 */
{
	TRACE("Enter QueryWindows31FilesMigration\n");
	return pQueryWindows31FilesMigration(x1);
}

extern WINAPI void wine32a_advapi32_QueryWindows31FilesMigration(void);  /* ../dlls/advapi32/security.c:1316 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_QueryWindows31FilesMigration,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_QueryWindows31FilesMigration") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_ReadEncryptedFileRaw(PFE_EXPORT_FUNC  export, PVOID  callback, PVOID  context) /* ../dlls/advapi32/crypt.c:2334 */
{
	TRACE("Enter ReadEncryptedFileRaw\n");
	return pReadEncryptedFileRaw(export, callback, context);
}

extern WINAPI void wine32a_advapi32_ReadEncryptedFileRaw(void);  /* ../dlls/advapi32/crypt.c:2334 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ReadEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ReadEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ReadEventLogA(HANDLE  hEventLog, DWORD  dwReadFlags, DWORD  dwRecordOffset, LPVOID  lpBuffer, DWORD  nNumberOfBytesToRead, DWORD*  pnBytesRead, DWORD*  pnMinNumberOfBytesNeeded) /* ../dlls/advapi32/eventlog.c:572 */
{
	TRACE("Enter ReadEventLogA\n");
	return pReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
}

extern WINAPI void wine32a_advapi32_ReadEventLogA(void);  /* ../dlls/advapi32/eventlog.c:572 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ReadEventLogA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ReadEventLogA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_ReadEventLogW(HANDLE  hEventLog, DWORD  dwReadFlags, DWORD  dwRecordOffset, LPVOID  lpBuffer, DWORD  nNumberOfBytesToRead, DWORD*  pnBytesRead, DWORD*  pnMinNumberOfBytesNeeded) /* ../dlls/advapi32/eventlog.c:587 */
{
	TRACE("Enter ReadEventLogW\n");
	return pReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
}

extern WINAPI void wine32a_advapi32_ReadEventLogW(void);  /* ../dlls/advapi32/eventlog.c:587 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ReadEventLogW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ReadEventLogW") "\n"
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

extern WINAPI LSTATUS wine32b_advapi32_RegConnectRegistryA(LPCSTR  machine, HKEY  hkey, PHKEY  reskey) /* ../dlls/advapi32/registry.c:588 */
{
	TRACE("Enter RegConnectRegistryA\n");
	return pRegConnectRegistryA(machine, hkey, reskey);
}

extern WINAPI void wine32a_advapi32_RegConnectRegistryA(void);  /* ../dlls/advapi32/registry.c:588 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegConnectRegistryA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegConnectRegistryA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegConnectRegistryW(LPCWSTR  lpMachineName, HKEY  hKey, PHKEY  phkResult) /* ../dlls/advapi32/registry.c:548 */
{
	TRACE("Enter RegConnectRegistryW\n");
	return pRegConnectRegistryW(lpMachineName, hKey, phkResult);
}

extern WINAPI void wine32a_advapi32_RegConnectRegistryW(void);  /* ../dlls/advapi32/registry.c:548 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegConnectRegistryW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegConnectRegistryW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegCopyTreeA(HKEY  hsrc, char*  subkey, HKEY  hdst) /* ../dlls/advapi32/registry.c:625 */
{
	TRACE("Enter RegCopyTreeA\n");
	return pRegCopyTreeA(hsrc, subkey, hdst);
}

extern WINAPI void wine32a_advapi32_RegCopyTreeA(void);  /* ../dlls/advapi32/registry.c:625 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegCopyTreeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegCopyTreeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegCreateKeyA(HKEY  hkey, LPCSTR  lpSubKey, PHKEY  phkResult) /* ../dlls/advapi32/registry.c:84 */
{
	TRACE("Enter RegCreateKeyA\n");
	return pRegCreateKeyA(hkey, lpSubKey, phkResult);
}

extern WINAPI void wine32a_advapi32_RegCreateKeyA(void);  /* ../dlls/advapi32/registry.c:84 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegCreateKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegCreateKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegCreateKeyTransactedA(HKEY  hkey, LPCSTR  name, DWORD  reserved, LPSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos, HANDLE  transaction, PVOID  reserved2) /* ../dlls/advapi32/registry.c:107 */
{
	TRACE("Enter RegCreateKeyTransactedA\n");
	return pRegCreateKeyTransactedA(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
}

extern WINAPI void wine32a_advapi32_RegCreateKeyTransactedA(void);  /* ../dlls/advapi32/registry.c:107 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegCreateKeyTransactedA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegCreateKeyTransactedA") "\n"
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

extern WINAPI LSTATUS wine32b_advapi32_RegCreateKeyTransactedW(HKEY  hkey, LPCWSTR  name, DWORD  reserved, LPWSTR  class, DWORD  options, REGSAM  access, SECURITY_ATTRIBUTES*  sa, PHKEY  retkey, LPDWORD  dispos, HANDLE  transaction, PVOID  reserved2) /* ../dlls/advapi32/registry.c:94 */
{
	TRACE("Enter RegCreateKeyTransactedW\n");
	return pRegCreateKeyTransactedW(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
}

extern WINAPI void wine32a_advapi32_RegCreateKeyTransactedW(void);  /* ../dlls/advapi32/registry.c:94 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegCreateKeyTransactedW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegCreateKeyTransactedW") "\n"
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

extern WINAPI LSTATUS wine32b_advapi32_RegCreateKeyW(HKEY  hkey, LPCWSTR  lpSubKey, PHKEY  phkResult) /* ../dlls/advapi32/registry.c:72 */
{
	TRACE("Enter RegCreateKeyW\n");
	return pRegCreateKeyW(hkey, lpSubKey, phkResult);
}

extern WINAPI void wine32a_advapi32_RegCreateKeyW(void);  /* ../dlls/advapi32/registry.c:72 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegCreateKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegCreateKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegDeleteKeyA(HKEY  hkey, LPCSTR  name) /* ../dlls/advapi32/registry.c:340 */
{
	TRACE("Enter RegDeleteKeyA\n");
	return pRegDeleteKeyA(hkey, name);
}

extern WINAPI void wine32a_advapi32_RegDeleteKeyA(void);  /* ../dlls/advapi32/registry.c:340 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegDeleteKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegDeleteKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegDeleteKeyW(HKEY  hkey, LPCWSTR  name) /* ../dlls/advapi32/registry.c:316 */
{
	TRACE("Enter RegDeleteKeyW\n");
	return pRegDeleteKeyW(hkey, name);
}

extern WINAPI void wine32a_advapi32_RegDeleteKeyW(void);  /* ../dlls/advapi32/registry.c:316 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegDeleteKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegDeleteKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegDisablePredefinedCache(void) /* ../dlls/advapi32/registry.c:615 */
{
	TRACE("Enter RegDisablePredefinedCache\n");
	return pRegDisablePredefinedCache();
}

extern WINAPI void wine32a_advapi32_RegDisablePredefinedCache(void);  /* ../dlls/advapi32/registry.c:615 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegDisablePredefinedCache,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegDisablePredefinedCache") "\n"
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

extern WINAPI LONG wine32b_advapi32_RegDisableReflectionKey(HKEY  base) /* ../dlls/advapi32/registry.c:642 */
{
	TRACE("Enter RegDisableReflectionKey\n");
	return pRegDisableReflectionKey(base);
}

extern WINAPI void wine32a_advapi32_RegDisableReflectionKey(void);  /* ../dlls/advapi32/registry.c:642 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegDisableReflectionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegDisableReflectionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegEnumKeyA(HKEY  hkey, DWORD  index, LPSTR  name, DWORD  name_len) /* ../dlls/advapi32/registry.c:191 */
{
	TRACE("Enter RegEnumKeyA\n");
	return pRegEnumKeyA(hkey, index, name, name_len);
}

extern WINAPI void wine32a_advapi32_RegEnumKeyA(void);  /* ../dlls/advapi32/registry.c:191 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegEnumKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegEnumKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegEnumKeyW(HKEY  hkey, DWORD  index, LPWSTR  name, DWORD  name_len) /* ../dlls/advapi32/registry.c:180 */
{
	TRACE("Enter RegEnumKeyW\n");
	return pRegEnumKeyW(hkey, index, name, name_len);
}

extern WINAPI void wine32a_advapi32_RegEnumKeyW(void);  /* ../dlls/advapi32/registry.c:180 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegEnumKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegEnumKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegOpenKeyA(HKEY  hkey, LPCSTR  name, PHKEY  retkey) /* ../dlls/advapi32/registry.c:150 */
{
	TRACE("Enter RegOpenKeyA\n");
	return pRegOpenKeyA(hkey, name, retkey);
}

extern WINAPI void wine32a_advapi32_RegOpenKeyA(void);  /* ../dlls/advapi32/registry.c:150 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegOpenKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegOpenKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegOpenKeyW(HKEY  hkey, LPCWSTR  name, PHKEY  retkey) /* ../dlls/advapi32/registry.c:122 */
{
	TRACE("Enter RegOpenKeyW\n");
	return pRegOpenKeyW(hkey, name, retkey);
}

extern WINAPI void wine32a_advapi32_RegOpenKeyW(void);  /* ../dlls/advapi32/registry.c:122 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegOpenKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegOpenKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegOverridePredefKey(HKEY  hkey, HKEY  override) /* ../dlls/advapi32/registry.c:52 */
{
	TRACE("Enter RegOverridePredefKey\n");
	return pRegOverridePredefKey(hkey, override);
}

extern WINAPI void wine32a_advapi32_RegOverridePredefKey(void);  /* ../dlls/advapi32/registry.c:52 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegOverridePredefKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegOverridePredefKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegQueryMultipleValuesA(HKEY  hkey, PVALENTA  val_list, DWORD  num_vals, LPSTR  lpValueBuf, LPDWORD  ldwTotsize) /* ../dlls/advapi32/registry.c:214 */
{
	TRACE("Enter RegQueryMultipleValuesA\n");
	return pRegQueryMultipleValuesA(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
}

extern WINAPI void wine32a_advapi32_RegQueryMultipleValuesA(void);  /* ../dlls/advapi32/registry.c:214 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegQueryMultipleValuesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegQueryMultipleValuesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegQueryMultipleValuesW(HKEY  hkey, PVALENTW  val_list, DWORD  num_vals, LPWSTR  lpValueBuf, LPDWORD  ldwTotsize) /* ../dlls/advapi32/registry.c:260 */
{
	TRACE("Enter RegQueryMultipleValuesW\n");
	return pRegQueryMultipleValuesW(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
}

extern WINAPI void wine32a_advapi32_RegQueryMultipleValuesW(void);  /* ../dlls/advapi32/registry.c:260 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegQueryMultipleValuesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegQueryMultipleValuesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_advapi32_RegQueryReflectionKey(HKEY  hkey, BOOL*  is_reflection_disabled) /* ../dlls/advapi32/registry.c:303 */
{
	TRACE("Enter RegQueryReflectionKey\n");
	return pRegQueryReflectionKey(hkey, is_reflection_disabled);
}

extern WINAPI void wine32a_advapi32_RegQueryReflectionKey(void);  /* ../dlls/advapi32/registry.c:303 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegQueryReflectionKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegQueryReflectionKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegQueryValueA(HKEY  hkey, LPCSTR  name, LPSTR  data, LPLONG  count) /* ../dlls/advapi32/registry.c:431 */
{
	TRACE("Enter RegQueryValueA\n");
	return pRegQueryValueA(hkey, name, data, count);
}

extern WINAPI void wine32a_advapi32_RegQueryValueA(void);  /* ../dlls/advapi32/registry.c:431 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegQueryValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegQueryValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegQueryValueW(HKEY  hkey, LPCWSTR  name, LPWSTR  data, LPLONG  count) /* ../dlls/advapi32/registry.c:402 */
{
	TRACE("Enter RegQueryValueW\n");
	return pRegQueryValueW(hkey, name, data, count);
}

extern WINAPI void wine32a_advapi32_RegQueryValueW(void);  /* ../dlls/advapi32/registry.c:402 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegQueryValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegQueryValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegReplaceKeyA(HKEY  hkey, LPCSTR  lpSubKey, LPCSTR  lpNewFile, LPCSTR  lpOldFile) /* ../dlls/advapi32/registry.c:515 */
{
	TRACE("Enter RegReplaceKeyA\n");
	return pRegReplaceKeyA(hkey, lpSubKey, lpNewFile, lpOldFile);
}

extern WINAPI void wine32a_advapi32_RegReplaceKeyA(void);  /* ../dlls/advapi32/registry.c:515 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegReplaceKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegReplaceKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegReplaceKeyW(HKEY  hkey, LPCWSTR  lpSubKey, LPCWSTR  lpNewFile, LPCWSTR  lpOldFile) /* ../dlls/advapi32/registry.c:501 */
{
	TRACE("Enter RegReplaceKeyW\n");
	return pRegReplaceKeyW(hkey, lpSubKey, lpNewFile, lpOldFile);
}

extern WINAPI void wine32a_advapi32_RegReplaceKeyW(void);  /* ../dlls/advapi32/registry.c:501 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegReplaceKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegReplaceKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegSaveKeyA(HKEY  hkey, LPCSTR  file, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/advapi32/registry.c:480 */
{
	TRACE("Enter RegSaveKeyA\n");
	return pRegSaveKeyA(hkey, file, sa);
}

extern WINAPI void wine32a_advapi32_RegSaveKeyA(void);  /* ../dlls/advapi32/registry.c:480 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegSaveKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegSaveKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegSaveKeyW(HKEY  hkey, LPCWSTR  file, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/advapi32/registry.c:469 */
{
	TRACE("Enter RegSaveKeyW\n");
	return pRegSaveKeyW(hkey, file, sa);
}

extern WINAPI void wine32a_advapi32_RegSaveKeyW(void);  /* ../dlls/advapi32/registry.c:469 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegSaveKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegSaveKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegSetValueA(HKEY  hkey, LPCSTR  subkey, DWORD  type, LPCSTR  data, DWORD  count) /* ../dlls/advapi32/registry.c:376 */
{
	TRACE("Enter RegSetValueA\n");
	return pRegSetValueA(hkey, subkey, type, data, count);
}

extern WINAPI void wine32a_advapi32_RegSetValueA(void);  /* ../dlls/advapi32/registry.c:376 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegSetValueA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegSetValueA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LSTATUS wine32b_advapi32_RegSetValueW(HKEY  hkey, LPCWSTR  subkey, DWORD  type, LPCWSTR  data, DWORD  count) /* ../dlls/advapi32/registry.c:362 */
{
	TRACE("Enter RegSetValueW\n");
	return pRegSetValueW(hkey, subkey, type, data, count);
}

extern WINAPI void wine32a_advapi32_RegSetValueW(void);  /* ../dlls/advapi32/registry.c:362 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegSetValueW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegSetValueW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_advapi32_RegisterEventSourceA(LPCSTR  lpUNCServerName, LPCSTR  lpSourceName) /* ../dlls/advapi32/eventlog.c:611 */
{
	TRACE("Enter RegisterEventSourceA\n");
	return pRegisterEventSourceA(lpUNCServerName, lpSourceName);
}

extern WINAPI void wine32a_advapi32_RegisterEventSourceA(void);  /* ../dlls/advapi32/eventlog.c:611 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegisterEventSourceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegisterEventSourceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_advapi32_RegisterEventSourceW(LPCWSTR  lpUNCServerName, LPCWSTR  lpSourceName) /* ../dlls/advapi32/eventlog.c:632 */
{
	TRACE("Enter RegisterEventSourceW\n");
	return pRegisterEventSourceW(lpUNCServerName, lpSourceName);
}

extern WINAPI void wine32a_advapi32_RegisterEventSourceW(void);  /* ../dlls/advapi32/eventlog.c:632 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegisterEventSourceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegisterEventSourceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_advapi32_RegisterWaitChainCOMCallback(PCOGETCALLSTATE  call_state_cb, PCOGETACTIVATIONSTATE  activation_state_cb) /* ../dlls/advapi32/advapi.c:347 */
{
	TRACE("Enter RegisterWaitChainCOMCallback\n");
	return pRegisterWaitChainCOMCallback(call_state_cb, activation_state_cb);
}

extern WINAPI void wine32a_advapi32_RegisterWaitChainCOMCallback(void);  /* ../dlls/advapi32/advapi.c:347 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_RegisterWaitChainCOMCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_RegisterWaitChainCOMCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_ReportEventA(HANDLE  hEventLog, WORD  wType, WORD  wCategory, DWORD  dwEventID, PSID  lpUserSid, WORD  wNumStrings, DWORD  dwDataSize, LPCSTR*  lpStrings, LPVOID  lpRawData) /* ../dlls/advapi32/eventlog.c:663 */
{
	TRACE("Enter ReportEventA\n");
	return pReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
}

extern WINAPI void wine32a_advapi32_ReportEventA(void);  /* ../dlls/advapi32/eventlog.c:663 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ReportEventA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ReportEventA") "\n"
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

extern WINAPI BOOL wine32b_advapi32_ReportEventW(HANDLE  hEventLog, WORD  wType, WORD  wCategory, DWORD  dwEventID, PSID  lpUserSid, WORD  wNumStrings, DWORD  dwDataSize, LPCWSTR*  lpStrings, LPVOID  lpRawData) /* ../dlls/advapi32/eventlog.c:696 */
{
	TRACE("Enter ReportEventW\n");
	return pReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
}

extern WINAPI void wine32a_advapi32_ReportEventW(void);  /* ../dlls/advapi32/eventlog.c:696 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_ReportEventW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_ReportEventW") "\n"
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

extern WINAPI BOOL wine32b_advapi32_SaferCloseLevel(SAFER_LEVEL_HANDLE  handle) /* ../dlls/advapi32/security.c:4454 */
{
	TRACE("Enter SaferCloseLevel\n");
	return pSaferCloseLevel(handle);
}

extern WINAPI void wine32a_advapi32_SaferCloseLevel(void);  /* ../dlls/advapi32/security.c:4454 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferCloseLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferCloseLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SaferComputeTokenFromLevel(SAFER_LEVEL_HANDLE  handle, HANDLE  token, PHANDLE  access_token, DWORD  flags, LPVOID  reserved) /* ../dlls/advapi32/security.c:4442 */
{
	TRACE("Enter SaferComputeTokenFromLevel\n");
	return pSaferComputeTokenFromLevel(handle, token, access_token, flags, reserved);
}

extern WINAPI void wine32a_advapi32_SaferComputeTokenFromLevel(void);  /* ../dlls/advapi32/security.c:4442 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferComputeTokenFromLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferComputeTokenFromLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SaferCreateLevel(DWORD  ScopeId, DWORD  LevelId, DWORD  OpenFlags, SAFER_LEVEL_HANDLE*  LevelHandle, LPVOID  lpReserved) /* ../dlls/advapi32/security.c:4430 */
{
	TRACE("Enter SaferCreateLevel\n");
	return pSaferCreateLevel(ScopeId, LevelId, OpenFlags, LevelHandle, lpReserved);
}

extern WINAPI void wine32a_advapi32_SaferCreateLevel(void);  /* ../dlls/advapi32/security.c:4430 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferCreateLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferCreateLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SaferGetPolicyInformation(DWORD  scope, SAFER_POLICY_INFO_CLASS  class, DWORD  size, PVOID  buffer, PDWORD  required, LPVOID  lpReserved) /* ../dlls/advapi32/security.c:4479 */
{
	TRACE("Enter SaferGetPolicyInformation\n");
	return pSaferGetPolicyInformation(scope, class, size, buffer, required, lpReserved);
}

extern WINAPI void wine32a_advapi32_SaferGetPolicyInformation(void);  /* ../dlls/advapi32/security.c:4479 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferGetPolicyInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferGetPolicyInformation") "\n"
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

extern WINAPI BOOL wine32b_advapi32_SaferIdentifyLevel(DWORD  count, SAFER_CODE_PROPERTIES*  properties, SAFER_LEVEL_HANDLE*  handle, void*  reserved) /* ../dlls/advapi32/security.c:4489 */
{
	TRACE("Enter SaferIdentifyLevel\n");
	return pSaferIdentifyLevel(count, properties, handle, reserved);
}

extern WINAPI void wine32a_advapi32_SaferIdentifyLevel(void);  /* ../dlls/advapi32/security.c:4489 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferIdentifyLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferIdentifyLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SaferSetLevelInformation(SAFER_LEVEL_HANDLE  handle, SAFER_OBJECT_INFO_CLASS  infotype, LPVOID  buffer, DWORD  size) /* ../dlls/advapi32/security.c:4500 */
{
	TRACE("Enter SaferSetLevelInformation\n");
	return pSaferSetLevelInformation(handle, infotype, buffer, size);
}

extern WINAPI void wine32a_advapi32_SaferSetLevelInformation(void);  /* ../dlls/advapi32/security.c:4500 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SaferSetLevelInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SaferSetLevelInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_SetEntriesInAclA(ULONG  count, PEXPLICIT_ACCESSA  pEntries, PACL  OldAcl, PACL*  NewAcl) /* ../dlls/advapi32/security.c:2349 */
{
	TRACE("Enter SetEntriesInAclA\n");
	return pSetEntriesInAclA(count, pEntries, OldAcl, NewAcl);
}

extern WINAPI void wine32a_advapi32_SetEntriesInAclA(void);  /* ../dlls/advapi32/security.c:2349 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetEntriesInAclA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetEntriesInAclA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_SetEntriesInAclW(ULONG  count, PEXPLICIT_ACCESSW  pEntries, PACL  OldAcl, PACL*  NewAcl) /* ../dlls/advapi32/security.c:2407 */
{
	TRACE("Enter SetEntriesInAclW\n");
	return pSetEntriesInAclW(count, pEntries, OldAcl, NewAcl);
}

extern WINAPI void wine32a_advapi32_SetEntriesInAclW(void);  /* ../dlls/advapi32/security.c:2407 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetEntriesInAclW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetEntriesInAclW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SetFileSecurityA(LPCSTR  lpFileName, SECURITY_INFORMATION  RequestedInformation, PSECURITY_DESCRIPTOR  pSecurityDescriptor) /* ../dlls/advapi32/security.c:1295 */
{
	TRACE("Enter SetFileSecurityA\n");
	return pSetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor);
}

extern WINAPI void wine32a_advapi32_SetFileSecurityA(void);  /* ../dlls/advapi32/security.c:1295 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetFileSecurityA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetFileSecurityA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_SetNamedSecurityInfoA(LPSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl) /* ../dlls/advapi32/security.c:2623 */
{
	TRACE("Enter SetNamedSecurityInfoA\n");
	return pSetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_advapi32_SetNamedSecurityInfoA(void);  /* ../dlls/advapi32/security.c:2623 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetNamedSecurityInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetNamedSecurityInfoA") "\n"
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

extern WINAPI DWORD wine32b_advapi32_SetNamedSecurityInfoW(LPWSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl) /* ../dlls/advapi32/security.c:2645 */
{
	TRACE("Enter SetNamedSecurityInfoW\n");
	return pSetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_advapi32_SetNamedSecurityInfoW(void);  /* ../dlls/advapi32/security.c:2645 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetNamedSecurityInfoW") "\n"
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

extern WINAPI DWORD wine32b_advapi32_SetSecurityInfo(HANDLE  handle, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  psidOwner, PSID  psidGroup, PACL  pDacl, PACL  pSacl) /* ../dlls/advapi32/security.c:4300 */
{
	TRACE("Enter SetSecurityInfo\n");
	return pSetSecurityInfo(handle, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
}

extern WINAPI void wine32a_advapi32_SetSecurityInfo(void);  /* ../dlls/advapi32/security.c:4300 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SetSecurityInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SetSecurityInfo") "\n"
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

extern WINAPI ULONG wine32b_advapi32_StartTraceA(PTRACEHANDLE  pSessionHandle, LPCSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties) /* ../dlls/advapi32/eventlog.c:749 */
{
	TRACE("Enter StartTraceA\n");
	return pStartTraceA(pSessionHandle, SessionName, Properties);
}

extern WINAPI void wine32a_advapi32_StartTraceA(void);  /* ../dlls/advapi32/eventlog.c:749 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_StartTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_StartTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_StartTraceW(PTRACEHANDLE  pSessionHandle, LPCWSTR  SessionName, PEVENT_TRACE_PROPERTIES  Properties) /* ../dlls/advapi32/eventlog.c:736 */
{
	TRACE("Enter StartTraceW\n");
	return pStartTraceW(pSessionHandle, SessionName, Properties);
}

extern WINAPI void wine32a_advapi32_StartTraceW(void);  /* ../dlls/advapi32/eventlog.c:736 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_StartTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_StartTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_StopTraceA(TRACEHANDLE  session, LPCSTR  session_name, PEVENT_TRACE_PROPERTIES  properties) /* ../dlls/advapi32/eventlog.c:774 */
{
	TRACE("Enter StopTraceA\n");
	return pStopTraceA(session, session_name, properties);
}

extern WINAPI void wine32a_advapi32_StopTraceA(void);  /* ../dlls/advapi32/eventlog.c:774 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_StopTraceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_StopTraceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_StopTraceW(TRACEHANDLE  session, LPCWSTR  session_name, PEVENT_TRACE_PROPERTIES  properties) /* ../dlls/advapi32/eventlog.c:762 */
{
	TRACE("Enter StopTraceW\n");
	return pStopTraceW(session, session_name, properties);
}

extern WINAPI void wine32a_advapi32_StopTraceW(void);  /* ../dlls/advapi32/eventlog.c:762 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_StopTraceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_StopTraceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry(DWORD  x1, DWORD  x2, DWORD  x3, DWORD  x4) /* ../dlls/advapi32/security.c:1332 */
{
	TRACE("Enter SynchronizeWindows31FilesAndWindowsNTRegistry\n");
	return pSynchronizeWindows31FilesAndWindowsNTRegistry(x1, x2, x3, x4);
}

extern WINAPI void wine32a_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry(void);  /* ../dlls/advapi32/security.c:1332 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction001(BYTE*  data, BYTE*  key, LPBYTE  output) /* ../dlls/advapi32/crypt_lmhash.c:116 */
{
	TRACE("Enter SystemFunction001\n");
	return pSystemFunction001(data, key, output);
}

extern WINAPI void wine32a_advapi32_SystemFunction001(void);  /* ../dlls/advapi32/crypt_lmhash.c:116 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction001,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction001") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction002(BYTE*  data, BYTE*  key, LPBYTE  output) /* ../dlls/advapi32/crypt_lmhash.c:139 */
{
	TRACE("Enter SystemFunction002\n");
	return pSystemFunction002(data, key, output);
}

extern WINAPI void wine32a_advapi32_SystemFunction002(void);  /* ../dlls/advapi32/crypt_lmhash.c:139 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction002,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction002") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction003(BYTE*  key, LPBYTE  output) /* ../dlls/advapi32/crypt_lmhash.c:161 */
{
	TRACE("Enter SystemFunction003\n");
	return pSystemFunction003(key, output);
}

extern WINAPI void wine32a_advapi32_SystemFunction003(void);  /* ../dlls/advapi32/crypt_lmhash.c:161 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction003,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction003") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction004(struct ustring*  in, struct ustring*  key, struct ustring*  out) /* ../dlls/advapi32/crypt_lmhash.c:188 */
{
	TRACE("Enter SystemFunction004\n");
	return pSystemFunction004(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction004(void);  /* ../dlls/advapi32/crypt_lmhash.c:188 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction004,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction004") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction005(struct ustring*  in, struct ustring*  key, struct ustring*  out) /* ../dlls/advapi32/crypt_lmhash.c:247 */
{
	TRACE("Enter SystemFunction005\n");
	return pSystemFunction005(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction005(void);  /* ../dlls/advapi32/crypt_lmhash.c:247 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction005,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction005") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction006(LPCSTR  password, LPSTR  hash) /* ../dlls/advapi32/crypt_lmhash.c:49 */
{
	TRACE("Enter SystemFunction006\n");
	return pSystemFunction006(password, hash);
}

extern WINAPI void wine32a_advapi32_SystemFunction006(void);  /* ../dlls/advapi32/crypt_lmhash.c:49 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction006,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction006") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction007(UNICODE_STRING*  string, LPBYTE  hash) /* ../dlls/advapi32/crypt.c:2354 */
{
	TRACE("Enter SystemFunction007\n");
	return pSystemFunction007(string, hash);
}

extern WINAPI void wine32a_advapi32_SystemFunction007(void);  /* ../dlls/advapi32/crypt.c:2354 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction007,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction007") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction008(BYTE*  challenge, BYTE*  hash, LPBYTE  response) /* ../dlls/advapi32/crypt_lmhash.c:74 */
{
	TRACE("Enter SystemFunction008\n");
	return pSystemFunction008(challenge, hash, response);
}

extern WINAPI void wine32a_advapi32_SystemFunction008(void);  /* ../dlls/advapi32/crypt_lmhash.c:74 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction008,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction008") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction009(BYTE*  challenge, BYTE*  hash, LPBYTE  response) /* ../dlls/advapi32/crypt_lmhash.c:96 */
{
	TRACE("Enter SystemFunction009\n");
	return pSystemFunction009(challenge, hash, response);
}

extern WINAPI void wine32a_advapi32_SystemFunction009(void);  /* ../dlls/advapi32/crypt_lmhash.c:96 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction009,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction009") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction010(LPVOID  unknown, BYTE*  data, LPBYTE  hash) /* ../dlls/advapi32/crypt.c:2382 */
{
	TRACE("Enter SystemFunction010\n");
	return pSystemFunction010(unknown, data, hash);
}

extern WINAPI void wine32a_advapi32_SystemFunction010(void);  /* ../dlls/advapi32/crypt.c:2382 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction010,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction010") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction012(BYTE*  in, BYTE*  key, LPBYTE  out) /* ../dlls/advapi32/crypt_lmhash.c:311 */
{
	TRACE("Enter SystemFunction012\n");
	return pSystemFunction012(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction012(void);  /* ../dlls/advapi32/crypt_lmhash.c:311 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction012,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction012") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction013(BYTE*  in, BYTE*  key, LPBYTE  out) /* ../dlls/advapi32/crypt_lmhash.c:340 */
{
	TRACE("Enter SystemFunction013\n");
	return pSystemFunction013(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction013(void);  /* ../dlls/advapi32/crypt_lmhash.c:340 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction013,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction013") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction024(BYTE*  in, BYTE*  key, LPBYTE  out) /* ../dlls/advapi32/crypt_lmhash.c:363 */
{
	TRACE("Enter SystemFunction024\n");
	return pSystemFunction024(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction024(void);  /* ../dlls/advapi32/crypt_lmhash.c:363 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction024,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction024") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction025(BYTE*  in, BYTE*  key, LPBYTE  out) /* ../dlls/advapi32/crypt_lmhash.c:391 */
{
	TRACE("Enter SystemFunction025\n");
	return pSystemFunction025(in, key, out);
}

extern WINAPI void wine32a_advapi32_SystemFunction025(void);  /* ../dlls/advapi32/crypt_lmhash.c:391 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction025,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction025") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SystemFunction030(LPCVOID  b1, LPCVOID  b2) /* ../dlls/advapi32/crypt.c:2406 */
{
	TRACE("Enter SystemFunction030\n");
	return pSystemFunction030(b1, b2);
}

extern WINAPI void wine32a_advapi32_SystemFunction030(void);  /* ../dlls/advapi32/crypt.c:2406 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction030,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction030") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI NTSTATUS wine32b_advapi32_SystemFunction032(struct ustring*  data, struct ustring*  key) /* ../dlls/advapi32/crypt_arc4.c:97 */
{
	TRACE("Enter SystemFunction032\n");
	return pSystemFunction032(data, key);
}

extern WINAPI void wine32a_advapi32_SystemFunction032(void);  /* ../dlls/advapi32/crypt_arc4.c:97 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction032,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction032") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_advapi32_SystemFunction035(LPCSTR  lpszDllFilePath) /* ../dlls/advapi32/crypt.c:2420 */
{
	TRACE("Enter SystemFunction035\n");
	return pSystemFunction035(lpszDllFilePath);
}

extern WINAPI void wine32a_advapi32_SystemFunction035(void);  /* ../dlls/advapi32/crypt.c:2420 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_SystemFunction035,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_SystemFunction035") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_TraceSetInformation(TRACEHANDLE  handle, TRACE_INFO_CLASS  infoclass, void*  info, ULONG  len) /* ../dlls/advapi32/eventlog.c:844 */
{
	TRACE("Enter TraceSetInformation\n");
	return pTraceSetInformation(handle, infoclass, info, len);
}

extern WINAPI void wine32a_advapi32_TraceSetInformation(void);  /* ../dlls/advapi32/eventlog.c:844 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_TraceSetInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_TraceSetInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_advapi32_TreeResetNamedSecurityInfoW(LPWSTR  pObjectName, SE_OBJECT_TYPE  ObjectType, SECURITY_INFORMATION  SecurityInfo, PSID  pOwner, PSID  pGroup, PACL  pDacl, PACL  pSacl, BOOL  KeepExplicit, FN_PROGRESS  fnProgress, PROG_INVOKE_SETTING  ProgressInvokeSetting, PVOID  Args) /* ../dlls/advapi32/security.c:4463 */
{
	TRACE("Enter TreeResetNamedSecurityInfoW\n");
	return pTreeResetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, KeepExplicit, fnProgress, ProgressInvokeSetting, Args);
}

extern WINAPI void wine32a_advapi32_TreeResetNamedSecurityInfoW(void);  /* ../dlls/advapi32/security.c:4463 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_TreeResetNamedSecurityInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_TreeResetNamedSecurityInfoW") "\n"
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

extern WINAPI ULONG wine32b_advapi32_WmiExecuteMethodA(WMIHANDLE  handle, char*  name, ULONG  method, ULONG  inputsize, void*  inputbuffer, ULONG*  outputsize, void*  outputbuffer) /* ../dlls/advapi32/wmi.c:42 */
{
	TRACE("Enter WmiExecuteMethodA\n");
	return pWmiExecuteMethodA(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
}

extern WINAPI void wine32a_advapi32_WmiExecuteMethodA(void);  /* ../dlls/advapi32/wmi.c:42 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiExecuteMethodA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiExecuteMethodA") "\n"
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

extern WINAPI ULONG wine32b_advapi32_WmiExecuteMethodW(WMIHANDLE  handle, WCHAR*  name, ULONG  method, ULONG  inputsize, void*  inputbuffer, ULONG*  outputsize, void*  outputbuffer) /* ../dlls/advapi32/wmi.c:53 */
{
	TRACE("Enter WmiExecuteMethodW\n");
	return pWmiExecuteMethodW(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
}

extern WINAPI void wine32a_advapi32_WmiExecuteMethodW(void);  /* ../dlls/advapi32/wmi.c:53 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiExecuteMethodW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiExecuteMethodW") "\n"
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

extern WINAPI void wine32b_advapi32_WmiFreeBuffer(void*  buffer) /* ../dlls/advapi32/wmi.c:64 */
{
	TRACE("Enter WmiFreeBuffer\n");
	return pWmiFreeBuffer(buffer);
}

extern WINAPI void wine32a_advapi32_WmiFreeBuffer(void);  /* ../dlls/advapi32/wmi.c:64 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiFreeBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiFreeBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiMofEnumerateResourcesA(MOFHANDLE  handle, ULONG*  count, MOFRESOURCEINFOA**  resource) /* ../dlls/advapi32/wmi.c:72 */
{
	TRACE("Enter WmiMofEnumerateResourcesA\n");
	return pWmiMofEnumerateResourcesA(handle, count, resource);
}

extern WINAPI void wine32a_advapi32_WmiMofEnumerateResourcesA(void);  /* ../dlls/advapi32/wmi.c:72 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiMofEnumerateResourcesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiMofEnumerateResourcesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiMofEnumerateResourcesW(MOFHANDLE  handle, ULONG*  count, MOFRESOURCEINFOW**  resource) /* ../dlls/advapi32/wmi.c:81 */
{
	TRACE("Enter WmiMofEnumerateResourcesW\n");
	return pWmiMofEnumerateResourcesW(handle, count, resource);
}

extern WINAPI void wine32a_advapi32_WmiMofEnumerateResourcesW(void);  /* ../dlls/advapi32/wmi.c:81 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiMofEnumerateResourcesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiMofEnumerateResourcesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiNotificationRegistrationA(GUID*  guid, BOOLEAN  enable, void*  info, ULONG_PTR  context, ULONG  flags) /* ../dlls/advapi32/wmi.c:90 */
{
	TRACE("Enter WmiNotificationRegistrationA\n");
	return pWmiNotificationRegistrationA(guid, enable, info, context, flags);
}

extern WINAPI void wine32a_advapi32_WmiNotificationRegistrationA(void);  /* ../dlls/advapi32/wmi.c:90 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiNotificationRegistrationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiNotificationRegistrationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiNotificationRegistrationW(GUID*  guid, BOOLEAN  enable, void*  info, ULONG_PTR  context, ULONG  flags) /* ../dlls/advapi32/wmi.c:100 */
{
	TRACE("Enter WmiNotificationRegistrationW\n");
	return pWmiNotificationRegistrationW(guid, enable, info, context, flags);
}

extern WINAPI void wine32a_advapi32_WmiNotificationRegistrationW(void);  /* ../dlls/advapi32/wmi.c:100 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiNotificationRegistrationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiNotificationRegistrationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiOpenBlock(GUID*  guid, ULONG  access, WMIHANDLE*  handle) /* ../dlls/advapi32/wmi.c:110 */
{
	TRACE("Enter WmiOpenBlock\n");
	return pWmiOpenBlock(guid, access, handle);
}

extern WINAPI void wine32a_advapi32_WmiOpenBlock(void);  /* ../dlls/advapi32/wmi.c:110 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiOpenBlock,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiOpenBlock") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiQueryAllDataA(WMIHANDLE  handle, ULONG*  size, void*  buffer) /* ../dlls/advapi32/wmi.c:119 */
{
	TRACE("Enter WmiQueryAllDataA\n");
	return pWmiQueryAllDataA(handle, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiQueryAllDataA(void);  /* ../dlls/advapi32/wmi.c:119 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiQueryAllDataA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiQueryAllDataA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiQueryAllDataW(WMIHANDLE  handle, ULONG*  size, void*  buffer) /* ../dlls/advapi32/wmi.c:128 */
{
	TRACE("Enter WmiQueryAllDataW\n");
	return pWmiQueryAllDataW(handle, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiQueryAllDataW(void);  /* ../dlls/advapi32/wmi.c:128 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiQueryAllDataW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiQueryAllDataW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiQueryGuidInformation(WMIHANDLE  handle, WMIGUIDINFORMATION*  info) /* ../dlls/advapi32/wmi.c:137 */
{
	TRACE("Enter WmiQueryGuidInformation\n");
	return pWmiQueryGuidInformation(handle, info);
}

extern WINAPI void wine32a_advapi32_WmiQueryGuidInformation(void);  /* ../dlls/advapi32/wmi.c:137 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiQueryGuidInformation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiQueryGuidInformation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiSetSingleInstanceA(WMIHANDLE  handle, char*  name, ULONG  reserved, ULONG  size, void*  buffer) /* ../dlls/advapi32/wmi.c:146 */
{
	TRACE("Enter WmiSetSingleInstanceA\n");
	return pWmiSetSingleInstanceA(handle, name, reserved, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiSetSingleInstanceA(void);  /* ../dlls/advapi32/wmi.c:146 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiSetSingleInstanceA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiSetSingleInstanceA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiSetSingleInstanceW(WMIHANDLE  handle, WCHAR*  name, ULONG  reserved, ULONG  size, void*  buffer) /* ../dlls/advapi32/wmi.c:156 */
{
	TRACE("Enter WmiSetSingleInstanceW\n");
	return pWmiSetSingleInstanceW(handle, name, reserved, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiSetSingleInstanceW(void);  /* ../dlls/advapi32/wmi.c:156 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiSetSingleInstanceW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiSetSingleInstanceW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG wine32b_advapi32_WmiSetSingleItemA(WMIHANDLE  handle, char*  name, ULONG  id, ULONG  reserved, ULONG  size, void*  buffer) /* ../dlls/advapi32/wmi.c:166 */
{
	TRACE("Enter WmiSetSingleItemA\n");
	return pWmiSetSingleItemA(handle, name, id, reserved, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiSetSingleItemA(void);  /* ../dlls/advapi32/wmi.c:166 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiSetSingleItemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiSetSingleItemA") "\n"
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

extern WINAPI ULONG wine32b_advapi32_WmiSetSingleItemW(WMIHANDLE  handle, WCHAR*  name, ULONG  id, ULONG  reserved, ULONG  size, void*  buffer) /* ../dlls/advapi32/wmi.c:176 */
{
	TRACE("Enter WmiSetSingleItemW\n");
	return pWmiSetSingleItemW(handle, name, id, reserved, size, buffer);
}

extern WINAPI void wine32a_advapi32_WmiSetSingleItemW(void);  /* ../dlls/advapi32/wmi.c:176 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WmiSetSingleItemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WmiSetSingleItemW") "\n"
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

extern WINAPI DWORD wine32b_advapi32_WriteEncryptedFileRaw(PFE_IMPORT_FUNC  import, PVOID  callback, PVOID  context) /* ../dlls/advapi32/crypt.c:2534 */
{
	TRACE("Enter WriteEncryptedFileRaw\n");
	return pWriteEncryptedFileRaw(import, callback, context);
}

extern WINAPI void wine32a_advapi32_WriteEncryptedFileRaw(void);  /* ../dlls/advapi32/crypt.c:2534 */
__ASM_GLOBAL_FUNC(wine32a_advapi32_WriteEncryptedFileRaw,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_advapi32_WriteEncryptedFileRaw") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static BOOL initialized = FALSE;

void wine_thunk_initialize_advapi32(void)
{
	HMODULE library = LoadLibraryA("advapi32.dll");
	HMODULE library_ntdll = LoadLibraryA("ntdll.dll");
	HMODULE library_kernelbase = LoadLibraryA("kernelbase.dll");
	HMODULE library_kernel32 = LoadLibraryA("kernel32.dll");
	pA_SHAFinal = (void *)GetProcAddress(library, "A_SHAFinal");
	pextA_SHAFinal = (void *)GetProcAddress(library_ntdll, "A_SHAFinal");
	pA_SHAInit = (void *)GetProcAddress(library, "A_SHAInit");
	pextA_SHAInit = (void *)GetProcAddress(library_ntdll, "A_SHAInit");
	pA_SHAUpdate = (void *)GetProcAddress(library, "A_SHAUpdate");
	pextA_SHAUpdate = (void *)GetProcAddress(library_ntdll, "A_SHAUpdate");
	pAbortSystemShutdownA = (void *)GetProcAddress(library, "AbortSystemShutdownA");
	pAbortSystemShutdownW = (void *)GetProcAddress(library, "AbortSystemShutdownW");
	pAccessCheck = (void *)GetProcAddress(library, "AccessCheck");
	pextAccessCheck = (void *)GetProcAddress(library_kernelbase, "AccessCheck");
	pAccessCheckAndAuditAlarmA = (void *)GetProcAddress(library, "AccessCheckAndAuditAlarmA");
	pAccessCheckAndAuditAlarmW = (void *)GetProcAddress(library, "AccessCheckAndAuditAlarmW");
	pextAccessCheckAndAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "AccessCheckAndAuditAlarmW");
	pAccessCheckByType = (void *)GetProcAddress(library, "AccessCheckByType");
	pextAccessCheckByType = (void *)GetProcAddress(library_kernelbase, "AccessCheckByType");
	pAddAccessAllowedAce = (void *)GetProcAddress(library, "AddAccessAllowedAce");
	pextAddAccessAllowedAce = (void *)GetProcAddress(library_kernelbase, "AddAccessAllowedAce");
	pAddAccessAllowedAceEx = (void *)GetProcAddress(library, "AddAccessAllowedAceEx");
	pextAddAccessAllowedAceEx = (void *)GetProcAddress(library_kernelbase, "AddAccessAllowedAceEx");
	pAddAccessAllowedObjectAce = (void *)GetProcAddress(library, "AddAccessAllowedObjectAce");
	pextAddAccessAllowedObjectAce = (void *)GetProcAddress(library_kernelbase, "AddAccessAllowedObjectAce");
	pAddAccessDeniedAce = (void *)GetProcAddress(library, "AddAccessDeniedAce");
	pextAddAccessDeniedAce = (void *)GetProcAddress(library_kernelbase, "AddAccessDeniedAce");
	pAddAccessDeniedAceEx = (void *)GetProcAddress(library, "AddAccessDeniedAceEx");
	pextAddAccessDeniedAceEx = (void *)GetProcAddress(library_kernelbase, "AddAccessDeniedAceEx");
	pAddAccessDeniedObjectAce = (void *)GetProcAddress(library, "AddAccessDeniedObjectAce");
	pextAddAccessDeniedObjectAce = (void *)GetProcAddress(library_kernelbase, "AddAccessDeniedObjectAce");
	pAddAce = (void *)GetProcAddress(library, "AddAce");
	pextAddAce = (void *)GetProcAddress(library_kernelbase, "AddAce");
	pAddAuditAccessAce = (void *)GetProcAddress(library, "AddAuditAccessAce");
	pextAddAuditAccessAce = (void *)GetProcAddress(library_kernelbase, "AddAuditAccessAce");
	pAddAuditAccessAceEx = (void *)GetProcAddress(library, "AddAuditAccessAceEx");
	pextAddAuditAccessAceEx = (void *)GetProcAddress(library_kernelbase, "AddAuditAccessAceEx");
	pAddAuditAccessObjectAce = (void *)GetProcAddress(library, "AddAuditAccessObjectAce");
	pextAddAuditAccessObjectAce = (void *)GetProcAddress(library_kernelbase, "AddAuditAccessObjectAce");
	pAddMandatoryAce = (void *)GetProcAddress(library, "AddMandatoryAce");
	pextAddMandatoryAce = (void *)GetProcAddress(library_kernelbase, "AddMandatoryAce");
	pAdjustTokenGroups = (void *)GetProcAddress(library, "AdjustTokenGroups");
	pextAdjustTokenGroups = (void *)GetProcAddress(library_kernelbase, "AdjustTokenGroups");
	pAdjustTokenPrivileges = (void *)GetProcAddress(library, "AdjustTokenPrivileges");
	pextAdjustTokenPrivileges = (void *)GetProcAddress(library_kernelbase, "AdjustTokenPrivileges");
	pAllocateAndInitializeSid = (void *)GetProcAddress(library, "AllocateAndInitializeSid");
	pextAllocateAndInitializeSid = (void *)GetProcAddress(library_kernelbase, "AllocateAndInitializeSid");
	pAllocateLocallyUniqueId = (void *)GetProcAddress(library, "AllocateLocallyUniqueId");
	pextAllocateLocallyUniqueId = (void *)GetProcAddress(library_kernelbase, "AllocateLocallyUniqueId");
	pAreAllAccessesGranted = (void *)GetProcAddress(library, "AreAllAccessesGranted");
	pextAreAllAccessesGranted = (void *)GetProcAddress(library_kernelbase, "AreAllAccessesGranted");
	pAreAnyAccessesGranted = (void *)GetProcAddress(library, "AreAnyAccessesGranted");
	pextAreAnyAccessesGranted = (void *)GetProcAddress(library_kernelbase, "AreAnyAccessesGranted");
	pAuditQuerySystemPolicy = (void *)GetProcAddress(library, "AuditQuerySystemPolicy");
	pBackupEventLogA = (void *)GetProcAddress(library, "BackupEventLogA");
	pBackupEventLogW = (void *)GetProcAddress(library, "BackupEventLogW");
	pBuildExplicitAccessWithNameA = (void *)GetProcAddress(library, "BuildExplicitAccessWithNameA");
	pBuildExplicitAccessWithNameW = (void *)GetProcAddress(library, "BuildExplicitAccessWithNameW");
	pBuildSecurityDescriptorA = (void *)GetProcAddress(library, "BuildSecurityDescriptorA");
	pBuildSecurityDescriptorW = (void *)GetProcAddress(library, "BuildSecurityDescriptorW");
	pBuildTrusteeWithNameA = (void *)GetProcAddress(library, "BuildTrusteeWithNameA");
	pBuildTrusteeWithNameW = (void *)GetProcAddress(library, "BuildTrusteeWithNameW");
	pBuildTrusteeWithObjectsAndNameA = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndNameA");
	pBuildTrusteeWithObjectsAndNameW = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndNameW");
	pBuildTrusteeWithObjectsAndSidA = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndSidA");
	pBuildTrusteeWithObjectsAndSidW = (void *)GetProcAddress(library, "BuildTrusteeWithObjectsAndSidW");
	pBuildTrusteeWithSidA = (void *)GetProcAddress(library, "BuildTrusteeWithSidA");
	pBuildTrusteeWithSidW = (void *)GetProcAddress(library, "BuildTrusteeWithSidW");
	pCheckTokenMembership = (void *)GetProcAddress(library, "CheckTokenMembership");
	pextCheckTokenMembership = (void *)GetProcAddress(library_kernelbase, "CheckTokenMembership");
	pClearEventLogA = (void *)GetProcAddress(library, "ClearEventLogA");
	pClearEventLogW = (void *)GetProcAddress(library, "ClearEventLogW");
	pCloseEncryptedFileRaw = (void *)GetProcAddress(library, "CloseEncryptedFileRaw");
	pCloseEventLog = (void *)GetProcAddress(library, "CloseEventLog");
	pCloseTrace = (void *)GetProcAddress(library, "CloseTrace");
	pCommandLineFromMsiDescriptor = (void *)GetProcAddress(library, "CommandLineFromMsiDescriptor");
	pControlTraceA = (void *)GetProcAddress(library, "ControlTraceA");
	pControlTraceW = (void *)GetProcAddress(library, "ControlTraceW");
	pConvertSecurityDescriptorToStringSecurityDescriptorA = (void *)GetProcAddress(library, "ConvertSecurityDescriptorToStringSecurityDescriptorA");
	pConvertSecurityDescriptorToStringSecurityDescriptorW = (void *)GetProcAddress(library, "ConvertSecurityDescriptorToStringSecurityDescriptorW");
	pConvertSidToStringSidA = (void *)GetProcAddress(library, "ConvertSidToStringSidA");
	pConvertSidToStringSidW = (void *)GetProcAddress(library, "ConvertSidToStringSidW");
	pConvertStringSecurityDescriptorToSecurityDescriptorA = (void *)GetProcAddress(library, "ConvertStringSecurityDescriptorToSecurityDescriptorA");
	pConvertStringSecurityDescriptorToSecurityDescriptorW = (void *)GetProcAddress(library, "ConvertStringSecurityDescriptorToSecurityDescriptorW");
	pConvertStringSidToSidA = (void *)GetProcAddress(library, "ConvertStringSidToSidA");
	pConvertStringSidToSidW = (void *)GetProcAddress(library, "ConvertStringSidToSidW");
	pConvertToAutoInheritPrivateObjectSecurity = (void *)GetProcAddress(library, "ConvertToAutoInheritPrivateObjectSecurity");
	pextConvertToAutoInheritPrivateObjectSecurity = (void *)GetProcAddress(library_kernelbase, "ConvertToAutoInheritPrivateObjectSecurity");
	pCopySid = (void *)GetProcAddress(library, "CopySid");
	pextCopySid = (void *)GetProcAddress(library_kernelbase, "CopySid");
	pCreatePrivateObjectSecurity = (void *)GetProcAddress(library, "CreatePrivateObjectSecurity");
	pextCreatePrivateObjectSecurity = (void *)GetProcAddress(library_kernelbase, "CreatePrivateObjectSecurity");
	pCreatePrivateObjectSecurityEx = (void *)GetProcAddress(library, "CreatePrivateObjectSecurityEx");
	pextCreatePrivateObjectSecurityEx = (void *)GetProcAddress(library_kernelbase, "CreatePrivateObjectSecurityEx");
	pCreatePrivateObjectSecurityWithMultipleInheritance = (void *)GetProcAddress(library, "CreatePrivateObjectSecurityWithMultipleInheritance");
	pextCreatePrivateObjectSecurityWithMultipleInheritance = (void *)GetProcAddress(library_kernelbase, "CreatePrivateObjectSecurityWithMultipleInheritance");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pextCreateProcessAsUserA = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pextCreateProcessAsUserW = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserW");
	pCreateProcessWithLogonW = (void *)GetProcAddress(library, "CreateProcessWithLogonW");
	pCreateProcessWithTokenW = (void *)GetProcAddress(library, "CreateProcessWithTokenW");
	pCreateRestrictedToken = (void *)GetProcAddress(library, "CreateRestrictedToken");
	pextCreateRestrictedToken = (void *)GetProcAddress(library_kernelbase, "CreateRestrictedToken");
	pCreateWellKnownSid = (void *)GetProcAddress(library, "CreateWellKnownSid");
	pextCreateWellKnownSid = (void *)GetProcAddress(library_kernelbase, "CreateWellKnownSid");
	pCredDeleteA = (void *)GetProcAddress(library, "CredDeleteA");
	pCredDeleteW = (void *)GetProcAddress(library, "CredDeleteW");
	pCredEnumerateA = (void *)GetProcAddress(library, "CredEnumerateA");
	pCredEnumerateW = (void *)GetProcAddress(library, "CredEnumerateW");
	pCredFree = (void *)GetProcAddress(library, "CredFree");
	pCredGetSessionTypes = (void *)GetProcAddress(library, "CredGetSessionTypes");
	pCredIsMarshaledCredentialA = (void *)GetProcAddress(library, "CredIsMarshaledCredentialA");
	pCredIsMarshaledCredentialW = (void *)GetProcAddress(library, "CredIsMarshaledCredentialW");
	pCredMarshalCredentialA = (void *)GetProcAddress(library, "CredMarshalCredentialA");
	pCredMarshalCredentialW = (void *)GetProcAddress(library, "CredMarshalCredentialW");
	pCredReadA = (void *)GetProcAddress(library, "CredReadA");
	pCredReadDomainCredentialsA = (void *)GetProcAddress(library, "CredReadDomainCredentialsA");
	pCredReadDomainCredentialsW = (void *)GetProcAddress(library, "CredReadDomainCredentialsW");
	pCredReadW = (void *)GetProcAddress(library, "CredReadW");
	pCredUnmarshalCredentialA = (void *)GetProcAddress(library, "CredUnmarshalCredentialA");
	pCredUnmarshalCredentialW = (void *)GetProcAddress(library, "CredUnmarshalCredentialW");
	pCredWriteA = (void *)GetProcAddress(library, "CredWriteA");
	pCredWriteW = (void *)GetProcAddress(library, "CredWriteW");
	pCryptAcquireContextA = (void *)GetProcAddress(library, "CryptAcquireContextA");
	pCryptAcquireContextW = (void *)GetProcAddress(library, "CryptAcquireContextW");
	pCryptContextAddRef = (void *)GetProcAddress(library, "CryptContextAddRef");
	pCryptCreateHash = (void *)GetProcAddress(library, "CryptCreateHash");
	pCryptDecrypt = (void *)GetProcAddress(library, "CryptDecrypt");
	pCryptDeriveKey = (void *)GetProcAddress(library, "CryptDeriveKey");
	pCryptDestroyHash = (void *)GetProcAddress(library, "CryptDestroyHash");
	pCryptDestroyKey = (void *)GetProcAddress(library, "CryptDestroyKey");
	pCryptDuplicateHash = (void *)GetProcAddress(library, "CryptDuplicateHash");
	pCryptDuplicateKey = (void *)GetProcAddress(library, "CryptDuplicateKey");
	pCryptEncrypt = (void *)GetProcAddress(library, "CryptEncrypt");
	pCryptEnumProviderTypesA = (void *)GetProcAddress(library, "CryptEnumProviderTypesA");
	pCryptEnumProviderTypesW = (void *)GetProcAddress(library, "CryptEnumProviderTypesW");
	pCryptEnumProvidersA = (void *)GetProcAddress(library, "CryptEnumProvidersA");
	pCryptEnumProvidersW = (void *)GetProcAddress(library, "CryptEnumProvidersW");
	pCryptExportKey = (void *)GetProcAddress(library, "CryptExportKey");
	pCryptGenKey = (void *)GetProcAddress(library, "CryptGenKey");
	pCryptGenRandom = (void *)GetProcAddress(library, "CryptGenRandom");
	pCryptGetDefaultProviderA = (void *)GetProcAddress(library, "CryptGetDefaultProviderA");
	pCryptGetDefaultProviderW = (void *)GetProcAddress(library, "CryptGetDefaultProviderW");
	pCryptGetHashParam = (void *)GetProcAddress(library, "CryptGetHashParam");
	pCryptGetKeyParam = (void *)GetProcAddress(library, "CryptGetKeyParam");
	pCryptGetProvParam = (void *)GetProcAddress(library, "CryptGetProvParam");
	pCryptGetUserKey = (void *)GetProcAddress(library, "CryptGetUserKey");
	pCryptHashData = (void *)GetProcAddress(library, "CryptHashData");
	pCryptHashSessionKey = (void *)GetProcAddress(library, "CryptHashSessionKey");
	pCryptImportKey = (void *)GetProcAddress(library, "CryptImportKey");
	pCryptReleaseContext = (void *)GetProcAddress(library, "CryptReleaseContext");
	pCryptSetHashParam = (void *)GetProcAddress(library, "CryptSetHashParam");
	pCryptSetKeyParam = (void *)GetProcAddress(library, "CryptSetKeyParam");
	pCryptSetProvParam = (void *)GetProcAddress(library, "CryptSetProvParam");
	pCryptSetProviderA = (void *)GetProcAddress(library, "CryptSetProviderA");
	pCryptSetProviderExA = (void *)GetProcAddress(library, "CryptSetProviderExA");
	pCryptSetProviderExW = (void *)GetProcAddress(library, "CryptSetProviderExW");
	pCryptSetProviderW = (void *)GetProcAddress(library, "CryptSetProviderW");
	pCryptSignHashA = (void *)GetProcAddress(library, "CryptSignHashA");
	pCryptSignHashW = (void *)GetProcAddress(library, "CryptSignHashW");
	pCryptVerifySignatureA = (void *)GetProcAddress(library, "CryptVerifySignatureA");
	pCryptVerifySignatureW = (void *)GetProcAddress(library, "CryptVerifySignatureW");
	pDecryptFileA = (void *)GetProcAddress(library, "DecryptFileA");
	pDecryptFileW = (void *)GetProcAddress(library, "DecryptFileW");
	pDeleteAce = (void *)GetProcAddress(library, "DeleteAce");
	pextDeleteAce = (void *)GetProcAddress(library_kernelbase, "DeleteAce");
	pDeregisterEventSource = (void *)GetProcAddress(library, "DeregisterEventSource");
	pDestroyPrivateObjectSecurity = (void *)GetProcAddress(library, "DestroyPrivateObjectSecurity");
	pextDestroyPrivateObjectSecurity = (void *)GetProcAddress(library_kernelbase, "DestroyPrivateObjectSecurity");
	pDuplicateToken = (void *)GetProcAddress(library, "DuplicateToken");
	pextDuplicateToken = (void *)GetProcAddress(library_kernelbase, "DuplicateToken");
	pDuplicateTokenEx = (void *)GetProcAddress(library, "DuplicateTokenEx");
	pextDuplicateTokenEx = (void *)GetProcAddress(library_kernelbase, "DuplicateTokenEx");
	pEnableTrace = (void *)GetProcAddress(library, "EnableTrace");
	pEnableTraceEx = (void *)GetProcAddress(library, "EnableTraceEx");
	pEnableTraceEx2 = (void *)GetProcAddress(library, "EnableTraceEx2");
	pEncryptFileA = (void *)GetProcAddress(library, "EncryptFileA");
	pEncryptFileW = (void *)GetProcAddress(library, "EncryptFileW");
	pEnumDynamicTimeZoneInformation = (void *)GetProcAddress(library, "EnumDynamicTimeZoneInformation");
	pextEnumDynamicTimeZoneInformation = (void *)GetProcAddress(library_kernelbase, "EnumDynamicTimeZoneInformation");
	pEnumerateTraceGuids = (void *)GetProcAddress(library, "EnumerateTraceGuids");
	pEqualPrefixSid = (void *)GetProcAddress(library, "EqualPrefixSid");
	pextEqualPrefixSid = (void *)GetProcAddress(library_kernelbase, "EqualPrefixSid");
	pEqualSid = (void *)GetProcAddress(library, "EqualSid");
	pextEqualSid = (void *)GetProcAddress(library_kernelbase, "EqualSid");
	pEtwEventActivityIdControl = (void *)GetProcAddress(library, "EtwEventActivityIdControl");
	pextEtwEventActivityIdControl = (void *)GetProcAddress(library_ntdll, "EtwEventActivityIdControl");
	pEtwEventEnabled = (void *)GetProcAddress(library, "EtwEventEnabled");
	pextEtwEventEnabled = (void *)GetProcAddress(library_ntdll, "EtwEventEnabled");
	pEtwEventProviderEnabled = (void *)GetProcAddress(library, "EtwEventProviderEnabled");
	pextEtwEventProviderEnabled = (void *)GetProcAddress(library_ntdll, "EtwEventProviderEnabled");
	pEtwEventRegister = (void *)GetProcAddress(library, "EtwEventRegister");
	pextEtwEventRegister = (void *)GetProcAddress(library_ntdll, "EtwEventRegister");
	pEtwEventSetInformation = (void *)GetProcAddress(library, "EtwEventSetInformation");
	pextEtwEventSetInformation = (void *)GetProcAddress(library_ntdll, "EtwEventSetInformation");
	pEtwEventUnregister = (void *)GetProcAddress(library, "EtwEventUnregister");
	pextEtwEventUnregister = (void *)GetProcAddress(library_ntdll, "EtwEventUnregister");
	pEtwEventWrite = (void *)GetProcAddress(library, "EtwEventWrite");
	pextEtwEventWrite = (void *)GetProcAddress(library_ntdll, "EtwEventWrite");
	pEtwEventWriteString = (void *)GetProcAddress(library, "EtwEventWriteString");
	pextEtwEventWriteString = (void *)GetProcAddress(library_ntdll, "EtwEventWriteString");
	pEtwEventWriteTransfer = (void *)GetProcAddress(library, "EtwEventWriteTransfer");
	pextEtwEventWriteTransfer = (void *)GetProcAddress(library_ntdll, "EtwEventWriteTransfer");
	pFileEncryptionStatusA = (void *)GetProcAddress(library, "FileEncryptionStatusA");
	pFileEncryptionStatusW = (void *)GetProcAddress(library, "FileEncryptionStatusW");
	pFindFirstFreeAce = (void *)GetProcAddress(library, "FindFirstFreeAce");
	pextFindFirstFreeAce = (void *)GetProcAddress(library_kernelbase, "FindFirstFreeAce");
	pFlushTraceA = (void *)GetProcAddress(library, "FlushTraceA");
	pFlushTraceW = (void *)GetProcAddress(library, "FlushTraceW");
	pFreeSid = (void *)GetProcAddress(library, "FreeSid");
	pextFreeSid = (void *)GetProcAddress(library_kernelbase, "FreeSid");
	pGetAce = (void *)GetProcAddress(library, "GetAce");
	pextGetAce = (void *)GetProcAddress(library_kernelbase, "GetAce");
	pGetAclInformation = (void *)GetProcAddress(library, "GetAclInformation");
	pextGetAclInformation = (void *)GetProcAddress(library_kernelbase, "GetAclInformation");
	pGetAuditedPermissionsFromAclA = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclA");
	pGetAuditedPermissionsFromAclW = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclW");
	pGetCurrentHwProfileA = (void *)GetProcAddress(library, "GetCurrentHwProfileA");
	pGetCurrentHwProfileW = (void *)GetProcAddress(library, "GetCurrentHwProfileW");
	pGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformationEffectiveYears");
	pextGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library_kernel32, "GetDynamicTimeZoneInformationEffectiveYears");
	pGetEffectiveRightsFromAclA = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclA");
	pGetEffectiveRightsFromAclW = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclW");
	pGetEventLogInformation = (void *)GetProcAddress(library, "GetEventLogInformation");
	pGetExplicitEntriesFromAclA = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclA");
	pGetExplicitEntriesFromAclW = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclW");
	pGetFileSecurityA = (void *)GetProcAddress(library, "GetFileSecurityA");
	pGetFileSecurityW = (void *)GetProcAddress(library, "GetFileSecurityW");
	pextGetFileSecurityW = (void *)GetProcAddress(library_kernelbase, "GetFileSecurityW");
	pGetKernelObjectSecurity = (void *)GetProcAddress(library, "GetKernelObjectSecurity");
	pextGetKernelObjectSecurity = (void *)GetProcAddress(library_kernelbase, "GetKernelObjectSecurity");
	pGetLengthSid = (void *)GetProcAddress(library, "GetLengthSid");
	pextGetLengthSid = (void *)GetProcAddress(library_kernelbase, "GetLengthSid");
	pGetNamedSecurityInfoA = (void *)GetProcAddress(library, "GetNamedSecurityInfoA");
	pGetNamedSecurityInfoExA = (void *)GetProcAddress(library, "GetNamedSecurityInfoExA");
	pGetNamedSecurityInfoExW = (void *)GetProcAddress(library, "GetNamedSecurityInfoExW");
	pGetNamedSecurityInfoW = (void *)GetProcAddress(library, "GetNamedSecurityInfoW");
	pGetNumberOfEventLogRecords = (void *)GetProcAddress(library, "GetNumberOfEventLogRecords");
	pGetOldestEventLogRecord = (void *)GetProcAddress(library, "GetOldestEventLogRecord");
	pGetPrivateObjectSecurity = (void *)GetProcAddress(library, "GetPrivateObjectSecurity");
	pextGetPrivateObjectSecurity = (void *)GetProcAddress(library_kernelbase, "GetPrivateObjectSecurity");
	pGetSecurityDescriptorControl = (void *)GetProcAddress(library, "GetSecurityDescriptorControl");
	pextGetSecurityDescriptorControl = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorControl");
	pGetSecurityDescriptorDacl = (void *)GetProcAddress(library, "GetSecurityDescriptorDacl");
	pextGetSecurityDescriptorDacl = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorDacl");
	pGetSecurityDescriptorGroup = (void *)GetProcAddress(library, "GetSecurityDescriptorGroup");
	pextGetSecurityDescriptorGroup = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorGroup");
	pGetSecurityDescriptorLength = (void *)GetProcAddress(library, "GetSecurityDescriptorLength");
	pextGetSecurityDescriptorLength = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorLength");
	pGetSecurityDescriptorOwner = (void *)GetProcAddress(library, "GetSecurityDescriptorOwner");
	pextGetSecurityDescriptorOwner = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorOwner");
	pGetSecurityDescriptorSacl = (void *)GetProcAddress(library, "GetSecurityDescriptorSacl");
	pextGetSecurityDescriptorSacl = (void *)GetProcAddress(library_kernelbase, "GetSecurityDescriptorSacl");
	pGetSecurityInfo = (void *)GetProcAddress(library, "GetSecurityInfo");
	pGetSecurityInfoExA = (void *)GetProcAddress(library, "GetSecurityInfoExA");
	pGetSecurityInfoExW = (void *)GetProcAddress(library, "GetSecurityInfoExW");
	pGetSidIdentifierAuthority = (void *)GetProcAddress(library, "GetSidIdentifierAuthority");
	pextGetSidIdentifierAuthority = (void *)GetProcAddress(library_kernelbase, "GetSidIdentifierAuthority");
	pGetSidLengthRequired = (void *)GetProcAddress(library, "GetSidLengthRequired");
	pextGetSidLengthRequired = (void *)GetProcAddress(library_kernelbase, "GetSidLengthRequired");
	pGetSidSubAuthority = (void *)GetProcAddress(library, "GetSidSubAuthority");
	pextGetSidSubAuthority = (void *)GetProcAddress(library_kernelbase, "GetSidSubAuthority");
	pGetSidSubAuthorityCount = (void *)GetProcAddress(library, "GetSidSubAuthorityCount");
	pextGetSidSubAuthorityCount = (void *)GetProcAddress(library_kernelbase, "GetSidSubAuthorityCount");
	pGetTokenInformation = (void *)GetProcAddress(library, "GetTokenInformation");
	pextGetTokenInformation = (void *)GetProcAddress(library_kernelbase, "GetTokenInformation");
	pEtwGetTraceEnableFlags = (void *)GetProcAddress(library, "EtwGetTraceEnableFlags");
	pextEtwGetTraceEnableFlags = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableFlags");
	pEtwGetTraceEnableLevel = (void *)GetProcAddress(library, "EtwGetTraceEnableLevel");
	pextEtwGetTraceEnableLevel = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableLevel");
	pEtwGetTraceLoggerHandle = (void *)GetProcAddress(library, "EtwGetTraceLoggerHandle");
	pextEtwGetTraceLoggerHandle = (void *)GetProcAddress(library_ntdll, "EtwGetTraceLoggerHandle");
	pGetTrusteeFormA = (void *)GetProcAddress(library, "GetTrusteeFormA");
	pGetTrusteeFormW = (void *)GetProcAddress(library, "GetTrusteeFormW");
	pGetTrusteeNameA = (void *)GetProcAddress(library, "GetTrusteeNameA");
	pGetTrusteeNameW = (void *)GetProcAddress(library, "GetTrusteeNameW");
	pGetTrusteeTypeA = (void *)GetProcAddress(library, "GetTrusteeTypeA");
	pGetTrusteeTypeW = (void *)GetProcAddress(library, "GetTrusteeTypeW");
	pGetUserNameA = (void *)GetProcAddress(library, "GetUserNameA");
	pGetUserNameW = (void *)GetProcAddress(library, "GetUserNameW");
	pGetWindowsAccountDomainSid = (void *)GetProcAddress(library, "GetWindowsAccountDomainSid");
	pextGetWindowsAccountDomainSid = (void *)GetProcAddress(library_kernelbase, "GetWindowsAccountDomainSid");
	pImpersonateAnonymousToken = (void *)GetProcAddress(library, "ImpersonateAnonymousToken");
	pextImpersonateAnonymousToken = (void *)GetProcAddress(library_kernelbase, "ImpersonateAnonymousToken");
	pImpersonateLoggedOnUser = (void *)GetProcAddress(library, "ImpersonateLoggedOnUser");
	pextImpersonateLoggedOnUser = (void *)GetProcAddress(library_kernelbase, "ImpersonateLoggedOnUser");
	pImpersonateNamedPipeClient = (void *)GetProcAddress(library, "ImpersonateNamedPipeClient");
	pextImpersonateNamedPipeClient = (void *)GetProcAddress(library_kernelbase, "ImpersonateNamedPipeClient");
	pImpersonateSelf = (void *)GetProcAddress(library, "ImpersonateSelf");
	pextImpersonateSelf = (void *)GetProcAddress(library_kernelbase, "ImpersonateSelf");
	pInitializeAcl = (void *)GetProcAddress(library, "InitializeAcl");
	pextInitializeAcl = (void *)GetProcAddress(library_kernelbase, "InitializeAcl");
	pInitializeSecurityDescriptor = (void *)GetProcAddress(library, "InitializeSecurityDescriptor");
	pextInitializeSecurityDescriptor = (void *)GetProcAddress(library_kernelbase, "InitializeSecurityDescriptor");
	pInitializeSid = (void *)GetProcAddress(library, "InitializeSid");
	pextInitializeSid = (void *)GetProcAddress(library_kernelbase, "InitializeSid");
	pInitiateShutdownA = (void *)GetProcAddress(library, "InitiateShutdownA");
	pInitiateShutdownW = (void *)GetProcAddress(library, "InitiateShutdownW");
	pInitiateSystemShutdownA = (void *)GetProcAddress(library, "InitiateSystemShutdownA");
	pInitiateSystemShutdownExA = (void *)GetProcAddress(library, "InitiateSystemShutdownExA");
	pInitiateSystemShutdownExW = (void *)GetProcAddress(library, "InitiateSystemShutdownExW");
	pInitiateSystemShutdownW = (void *)GetProcAddress(library, "InitiateSystemShutdownW");
	pIsTextUnicode = (void *)GetProcAddress(library, "IsTextUnicode");
	pIsTokenRestricted = (void *)GetProcAddress(library, "IsTokenRestricted");
	pextIsTokenRestricted = (void *)GetProcAddress(library_kernelbase, "IsTokenRestricted");
	pIsValidAcl = (void *)GetProcAddress(library, "IsValidAcl");
	pextIsValidAcl = (void *)GetProcAddress(library_kernelbase, "IsValidAcl");
	pIsValidSecurityDescriptor = (void *)GetProcAddress(library, "IsValidSecurityDescriptor");
	pextIsValidSecurityDescriptor = (void *)GetProcAddress(library_kernelbase, "IsValidSecurityDescriptor");
	pIsValidSid = (void *)GetProcAddress(library, "IsValidSid");
	pextIsValidSid = (void *)GetProcAddress(library_kernelbase, "IsValidSid");
	pIsWellKnownSid = (void *)GetProcAddress(library, "IsWellKnownSid");
	pextIsWellKnownSid = (void *)GetProcAddress(library_kernelbase, "IsWellKnownSid");
	pLogonUserA = (void *)GetProcAddress(library, "LogonUserA");
	pLogonUserW = (void *)GetProcAddress(library, "LogonUserW");
	pLookupAccountNameA = (void *)GetProcAddress(library, "LookupAccountNameA");
	pLookupAccountNameW = (void *)GetProcAddress(library, "LookupAccountNameW");
	pLookupAccountSidA = (void *)GetProcAddress(library, "LookupAccountSidA");
	pLookupAccountSidLocalA = (void *)GetProcAddress(library, "LookupAccountSidLocalA");
	pLookupAccountSidLocalW = (void *)GetProcAddress(library, "LookupAccountSidLocalW");
	pLookupAccountSidW = (void *)GetProcAddress(library, "LookupAccountSidW");
	pLookupPrivilegeDisplayNameA = (void *)GetProcAddress(library, "LookupPrivilegeDisplayNameA");
	pLookupPrivilegeDisplayNameW = (void *)GetProcAddress(library, "LookupPrivilegeDisplayNameW");
	pLookupPrivilegeNameA = (void *)GetProcAddress(library, "LookupPrivilegeNameA");
	pLookupPrivilegeNameW = (void *)GetProcAddress(library, "LookupPrivilegeNameW");
	pLookupPrivilegeValueA = (void *)GetProcAddress(library, "LookupPrivilegeValueA");
	pLookupPrivilegeValueW = (void *)GetProcAddress(library, "LookupPrivilegeValueW");
	pLookupSecurityDescriptorPartsA = (void *)GetProcAddress(library, "LookupSecurityDescriptorPartsA");
	pLookupSecurityDescriptorPartsW = (void *)GetProcAddress(library, "LookupSecurityDescriptorPartsW");
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
	pLsaLookupPrivilegeDisplayName = (void *)GetProcAddress(library, "LsaLookupPrivilegeDisplayName");
	pLsaLookupPrivilegeName = (void *)GetProcAddress(library, "LsaLookupPrivilegeName");
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
	pMD4Final = (void *)GetProcAddress(library, "MD4Final");
	pextMD4Final = (void *)GetProcAddress(library_ntdll, "MD4Final");
	pMD4Init = (void *)GetProcAddress(library, "MD4Init");
	pextMD4Init = (void *)GetProcAddress(library_ntdll, "MD4Init");
	pMD4Update = (void *)GetProcAddress(library, "MD4Update");
	pextMD4Update = (void *)GetProcAddress(library_ntdll, "MD4Update");
	pMD5Final = (void *)GetProcAddress(library, "MD5Final");
	pextMD5Final = (void *)GetProcAddress(library_ntdll, "MD5Final");
	pMD5Init = (void *)GetProcAddress(library, "MD5Init");
	pextMD5Init = (void *)GetProcAddress(library_ntdll, "MD5Init");
	pMD5Update = (void *)GetProcAddress(library, "MD5Update");
	pextMD5Update = (void *)GetProcAddress(library_ntdll, "MD5Update");
	pMakeAbsoluteSD = (void *)GetProcAddress(library, "MakeAbsoluteSD");
	pextMakeAbsoluteSD = (void *)GetProcAddress(library_kernelbase, "MakeAbsoluteSD");
	pMakeSelfRelativeSD = (void *)GetProcAddress(library, "MakeSelfRelativeSD");
	pextMakeSelfRelativeSD = (void *)GetProcAddress(library_kernelbase, "MakeSelfRelativeSD");
	pMapGenericMask = (void *)GetProcAddress(library, "MapGenericMask");
	pextMapGenericMask = (void *)GetProcAddress(library_kernelbase, "MapGenericMask");
	pNotifyBootConfigStatus = (void *)GetProcAddress(library, "NotifyBootConfigStatus");
	pNotifyChangeEventLog = (void *)GetProcAddress(library, "NotifyChangeEventLog");
	pObjectCloseAuditAlarmA = (void *)GetProcAddress(library, "ObjectCloseAuditAlarmA");
	pObjectCloseAuditAlarmW = (void *)GetProcAddress(library, "ObjectCloseAuditAlarmW");
	pextObjectCloseAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "ObjectCloseAuditAlarmW");
	pObjectDeleteAuditAlarmW = (void *)GetProcAddress(library, "ObjectDeleteAuditAlarmW");
	pextObjectDeleteAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "ObjectDeleteAuditAlarmW");
	pObjectOpenAuditAlarmA = (void *)GetProcAddress(library, "ObjectOpenAuditAlarmA");
	pObjectOpenAuditAlarmW = (void *)GetProcAddress(library, "ObjectOpenAuditAlarmW");
	pextObjectOpenAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "ObjectOpenAuditAlarmW");
	pObjectPrivilegeAuditAlarmA = (void *)GetProcAddress(library, "ObjectPrivilegeAuditAlarmA");
	pObjectPrivilegeAuditAlarmW = (void *)GetProcAddress(library, "ObjectPrivilegeAuditAlarmW");
	pextObjectPrivilegeAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "ObjectPrivilegeAuditAlarmW");
	pOpenBackupEventLogA = (void *)GetProcAddress(library, "OpenBackupEventLogA");
	pOpenBackupEventLogW = (void *)GetProcAddress(library, "OpenBackupEventLogW");
	pOpenEncryptedFileRawA = (void *)GetProcAddress(library, "OpenEncryptedFileRawA");
	pOpenEncryptedFileRawW = (void *)GetProcAddress(library, "OpenEncryptedFileRawW");
	pOpenEventLogA = (void *)GetProcAddress(library, "OpenEventLogA");
	pOpenEventLogW = (void *)GetProcAddress(library, "OpenEventLogW");
	pOpenProcessToken = (void *)GetProcAddress(library, "OpenProcessToken");
	pextOpenProcessToken = (void *)GetProcAddress(library_kernelbase, "OpenProcessToken");
	pOpenThreadToken = (void *)GetProcAddress(library, "OpenThreadToken");
	pextOpenThreadToken = (void *)GetProcAddress(library_kernelbase, "OpenThreadToken");
	pOpenTraceA = (void *)GetProcAddress(library, "OpenTraceA");
	pOpenTraceW = (void *)GetProcAddress(library, "OpenTraceW");
	pPerfCreateInstance = (void *)GetProcAddress(library, "PerfCreateInstance");
	pextPerfCreateInstance = (void *)GetProcAddress(library_kernelbase, "PerfCreateInstance");
	pPerfDeleteInstance = (void *)GetProcAddress(library, "PerfDeleteInstance");
	pextPerfDeleteInstance = (void *)GetProcAddress(library_kernelbase, "PerfDeleteInstance");
	pPerfSetCounterRefValue = (void *)GetProcAddress(library, "PerfSetCounterRefValue");
	pextPerfSetCounterRefValue = (void *)GetProcAddress(library_kernelbase, "PerfSetCounterRefValue");
	pPerfSetCounterSetInfo = (void *)GetProcAddress(library, "PerfSetCounterSetInfo");
	pextPerfSetCounterSetInfo = (void *)GetProcAddress(library_kernelbase, "PerfSetCounterSetInfo");
	pPerfStartProvider = (void *)GetProcAddress(library, "PerfStartProvider");
	pextPerfStartProvider = (void *)GetProcAddress(library_kernelbase, "PerfStartProvider");
	pPerfStartProviderEx = (void *)GetProcAddress(library, "PerfStartProviderEx");
	pextPerfStartProviderEx = (void *)GetProcAddress(library_kernelbase, "PerfStartProviderEx");
	pPerfStopProvider = (void *)GetProcAddress(library, "PerfStopProvider");
	pextPerfStopProvider = (void *)GetProcAddress(library_kernelbase, "PerfStopProvider");
	pPrivilegeCheck = (void *)GetProcAddress(library, "PrivilegeCheck");
	pextPrivilegeCheck = (void *)GetProcAddress(library_kernelbase, "PrivilegeCheck");
	pPrivilegedServiceAuditAlarmA = (void *)GetProcAddress(library, "PrivilegedServiceAuditAlarmA");
	pPrivilegedServiceAuditAlarmW = (void *)GetProcAddress(library, "PrivilegedServiceAuditAlarmW");
	pextPrivilegedServiceAuditAlarmW = (void *)GetProcAddress(library_kernelbase, "PrivilegedServiceAuditAlarmW");
	pProcessTrace = (void *)GetProcAddress(library, "ProcessTrace");
	pQueryAllTracesA = (void *)GetProcAddress(library, "QueryAllTracesA");
	pQueryAllTracesW = (void *)GetProcAddress(library, "QueryAllTracesW");
	pQueryTraceW = (void *)GetProcAddress(library, "QueryTraceW");
	pQueryWindows31FilesMigration = (void *)GetProcAddress(library, "QueryWindows31FilesMigration");
	pReadEncryptedFileRaw = (void *)GetProcAddress(library, "ReadEncryptedFileRaw");
	pReadEventLogA = (void *)GetProcAddress(library, "ReadEventLogA");
	pReadEventLogW = (void *)GetProcAddress(library, "ReadEventLogW");
	pRegCloseKey = (void *)GetProcAddress(library, "RegCloseKey");
	pextRegCloseKey = (void *)GetProcAddress(library_kernelbase, "RegCloseKey");
	pRegConnectRegistryA = (void *)GetProcAddress(library, "RegConnectRegistryA");
	pRegConnectRegistryW = (void *)GetProcAddress(library, "RegConnectRegistryW");
	pRegCopyTreeA = (void *)GetProcAddress(library, "RegCopyTreeA");
	pRegCopyTreeW = (void *)GetProcAddress(library, "RegCopyTreeW");
	pextRegCopyTreeW = (void *)GetProcAddress(library_kernelbase, "RegCopyTreeW");
	pRegCreateKeyA = (void *)GetProcAddress(library, "RegCreateKeyA");
	pRegCreateKeyExA = (void *)GetProcAddress(library, "RegCreateKeyExA");
	pextRegCreateKeyExA = (void *)GetProcAddress(library_kernelbase, "RegCreateKeyExA");
	pRegCreateKeyExW = (void *)GetProcAddress(library, "RegCreateKeyExW");
	pextRegCreateKeyExW = (void *)GetProcAddress(library_kernelbase, "RegCreateKeyExW");
	pRegCreateKeyTransactedA = (void *)GetProcAddress(library, "RegCreateKeyTransactedA");
	pRegCreateKeyTransactedW = (void *)GetProcAddress(library, "RegCreateKeyTransactedW");
	pRegCreateKeyW = (void *)GetProcAddress(library, "RegCreateKeyW");
	pRegDeleteKeyA = (void *)GetProcAddress(library, "RegDeleteKeyA");
	pRegDeleteKeyExA = (void *)GetProcAddress(library, "RegDeleteKeyExA");
	pextRegDeleteKeyExA = (void *)GetProcAddress(library_kernelbase, "RegDeleteKeyExA");
	pRegDeleteKeyExW = (void *)GetProcAddress(library, "RegDeleteKeyExW");
	pextRegDeleteKeyExW = (void *)GetProcAddress(library_kernelbase, "RegDeleteKeyExW");
	pRegDeleteKeyValueA = (void *)GetProcAddress(library, "RegDeleteKeyValueA");
	pextRegDeleteKeyValueA = (void *)GetProcAddress(library_kernelbase, "RegDeleteKeyValueA");
	pRegDeleteKeyValueW = (void *)GetProcAddress(library, "RegDeleteKeyValueW");
	pextRegDeleteKeyValueW = (void *)GetProcAddress(library_kernelbase, "RegDeleteKeyValueW");
	pRegDeleteKeyW = (void *)GetProcAddress(library, "RegDeleteKeyW");
	pRegDeleteTreeA = (void *)GetProcAddress(library, "RegDeleteTreeA");
	pextRegDeleteTreeA = (void *)GetProcAddress(library_kernelbase, "RegDeleteTreeA");
	pRegDeleteTreeW = (void *)GetProcAddress(library, "RegDeleteTreeW");
	pextRegDeleteTreeW = (void *)GetProcAddress(library_kernelbase, "RegDeleteTreeW");
	pRegDeleteValueA = (void *)GetProcAddress(library, "RegDeleteValueA");
	pextRegDeleteValueA = (void *)GetProcAddress(library_kernelbase, "RegDeleteValueA");
	pRegDeleteValueW = (void *)GetProcAddress(library, "RegDeleteValueW");
	pextRegDeleteValueW = (void *)GetProcAddress(library_kernelbase, "RegDeleteValueW");
	pRegDisablePredefinedCache = (void *)GetProcAddress(library, "RegDisablePredefinedCache");
	pRegDisableReflectionKey = (void *)GetProcAddress(library, "RegDisableReflectionKey");
	pRegEnumKeyA = (void *)GetProcAddress(library, "RegEnumKeyA");
	pRegEnumKeyExA = (void *)GetProcAddress(library, "RegEnumKeyExA");
	pextRegEnumKeyExA = (void *)GetProcAddress(library_kernelbase, "RegEnumKeyExA");
	pRegEnumKeyExW = (void *)GetProcAddress(library, "RegEnumKeyExW");
	pextRegEnumKeyExW = (void *)GetProcAddress(library_kernelbase, "RegEnumKeyExW");
	pRegEnumKeyW = (void *)GetProcAddress(library, "RegEnumKeyW");
	pRegEnumValueA = (void *)GetProcAddress(library, "RegEnumValueA");
	pextRegEnumValueA = (void *)GetProcAddress(library_kernelbase, "RegEnumValueA");
	pRegEnumValueW = (void *)GetProcAddress(library, "RegEnumValueW");
	pextRegEnumValueW = (void *)GetProcAddress(library_kernelbase, "RegEnumValueW");
	pRegFlushKey = (void *)GetProcAddress(library, "RegFlushKey");
	pextRegFlushKey = (void *)GetProcAddress(library_kernelbase, "RegFlushKey");
	pRegGetKeySecurity = (void *)GetProcAddress(library, "RegGetKeySecurity");
	pextRegGetKeySecurity = (void *)GetProcAddress(library_kernelbase, "RegGetKeySecurity");
	pRegGetValueA = (void *)GetProcAddress(library, "RegGetValueA");
	pextRegGetValueA = (void *)GetProcAddress(library_kernelbase, "RegGetValueA");
	pRegGetValueW = (void *)GetProcAddress(library, "RegGetValueW");
	pextRegGetValueW = (void *)GetProcAddress(library_kernelbase, "RegGetValueW");
	pRegLoadAppKeyA = (void *)GetProcAddress(library, "RegLoadAppKeyA");
	pextRegLoadAppKeyA = (void *)GetProcAddress(library_kernelbase, "RegLoadAppKeyA");
	pRegLoadAppKeyW = (void *)GetProcAddress(library, "RegLoadAppKeyW");
	pextRegLoadAppKeyW = (void *)GetProcAddress(library_kernelbase, "RegLoadAppKeyW");
	pRegLoadKeyA = (void *)GetProcAddress(library, "RegLoadKeyA");
	pextRegLoadKeyA = (void *)GetProcAddress(library_kernelbase, "RegLoadKeyA");
	pRegLoadKeyW = (void *)GetProcAddress(library, "RegLoadKeyW");
	pextRegLoadKeyW = (void *)GetProcAddress(library_kernelbase, "RegLoadKeyW");
	pRegLoadMUIStringA = (void *)GetProcAddress(library, "RegLoadMUIStringA");
	pextRegLoadMUIStringA = (void *)GetProcAddress(library_kernelbase, "RegLoadMUIStringA");
	pRegLoadMUIStringW = (void *)GetProcAddress(library, "RegLoadMUIStringW");
	pextRegLoadMUIStringW = (void *)GetProcAddress(library_kernelbase, "RegLoadMUIStringW");
	pRegNotifyChangeKeyValue = (void *)GetProcAddress(library, "RegNotifyChangeKeyValue");
	pextRegNotifyChangeKeyValue = (void *)GetProcAddress(library_kernelbase, "RegNotifyChangeKeyValue");
	pRegOpenCurrentUser = (void *)GetProcAddress(library, "RegOpenCurrentUser");
	pextRegOpenCurrentUser = (void *)GetProcAddress(library_kernelbase, "RegOpenCurrentUser");
	pRegOpenKeyA = (void *)GetProcAddress(library, "RegOpenKeyA");
	pRegOpenKeyExA = (void *)GetProcAddress(library, "RegOpenKeyExA");
	pextRegOpenKeyExA = (void *)GetProcAddress(library_kernelbase, "RegOpenKeyExA");
	pRegOpenKeyExW = (void *)GetProcAddress(library, "RegOpenKeyExW");
	pextRegOpenKeyExW = (void *)GetProcAddress(library_kernelbase, "RegOpenKeyExW");
	pRegOpenKeyW = (void *)GetProcAddress(library, "RegOpenKeyW");
	pRegOpenUserClassesRoot = (void *)GetProcAddress(library, "RegOpenUserClassesRoot");
	pextRegOpenUserClassesRoot = (void *)GetProcAddress(library_kernelbase, "RegOpenUserClassesRoot");
	pRegOverridePredefKey = (void *)GetProcAddress(library, "RegOverridePredefKey");
	pRegQueryInfoKeyA = (void *)GetProcAddress(library, "RegQueryInfoKeyA");
	pextRegQueryInfoKeyA = (void *)GetProcAddress(library_kernelbase, "RegQueryInfoKeyA");
	pRegQueryInfoKeyW = (void *)GetProcAddress(library, "RegQueryInfoKeyW");
	pextRegQueryInfoKeyW = (void *)GetProcAddress(library_kernelbase, "RegQueryInfoKeyW");
	pRegQueryMultipleValuesA = (void *)GetProcAddress(library, "RegQueryMultipleValuesA");
	pRegQueryMultipleValuesW = (void *)GetProcAddress(library, "RegQueryMultipleValuesW");
	pRegQueryReflectionKey = (void *)GetProcAddress(library, "RegQueryReflectionKey");
	pRegQueryValueA = (void *)GetProcAddress(library, "RegQueryValueA");
	pRegQueryValueExA = (void *)GetProcAddress(library, "RegQueryValueExA");
	pextRegQueryValueExA = (void *)GetProcAddress(library_kernelbase, "RegQueryValueExA");
	pRegQueryValueExW = (void *)GetProcAddress(library, "RegQueryValueExW");
	pextRegQueryValueExW = (void *)GetProcAddress(library_kernelbase, "RegQueryValueExW");
	pRegQueryValueW = (void *)GetProcAddress(library, "RegQueryValueW");
	pRegReplaceKeyA = (void *)GetProcAddress(library, "RegReplaceKeyA");
	pRegReplaceKeyW = (void *)GetProcAddress(library, "RegReplaceKeyW");
	pRegRestoreKeyA = (void *)GetProcAddress(library, "RegRestoreKeyA");
	pextRegRestoreKeyA = (void *)GetProcAddress(library_kernelbase, "RegRestoreKeyA");
	pRegRestoreKeyW = (void *)GetProcAddress(library, "RegRestoreKeyW");
	pextRegRestoreKeyW = (void *)GetProcAddress(library_kernelbase, "RegRestoreKeyW");
	pRegSaveKeyA = (void *)GetProcAddress(library, "RegSaveKeyA");
	pRegSaveKeyExA = (void *)GetProcAddress(library, "RegSaveKeyExA");
	pextRegSaveKeyExA = (void *)GetProcAddress(library_kernelbase, "RegSaveKeyExA");
	pRegSaveKeyExW = (void *)GetProcAddress(library, "RegSaveKeyExW");
	pextRegSaveKeyExW = (void *)GetProcAddress(library_kernelbase, "RegSaveKeyExW");
	pRegSaveKeyW = (void *)GetProcAddress(library, "RegSaveKeyW");
	pRegSetKeySecurity = (void *)GetProcAddress(library, "RegSetKeySecurity");
	pextRegSetKeySecurity = (void *)GetProcAddress(library_kernelbase, "RegSetKeySecurity");
	pRegSetKeyValueA = (void *)GetProcAddress(library, "RegSetKeyValueA");
	pextRegSetKeyValueA = (void *)GetProcAddress(library_kernelbase, "RegSetKeyValueA");
	pRegSetKeyValueW = (void *)GetProcAddress(library, "RegSetKeyValueW");
	pextRegSetKeyValueW = (void *)GetProcAddress(library_kernelbase, "RegSetKeyValueW");
	pRegSetValueA = (void *)GetProcAddress(library, "RegSetValueA");
	pRegSetValueExA = (void *)GetProcAddress(library, "RegSetValueExA");
	pextRegSetValueExA = (void *)GetProcAddress(library_kernelbase, "RegSetValueExA");
	pRegSetValueExW = (void *)GetProcAddress(library, "RegSetValueExW");
	pextRegSetValueExW = (void *)GetProcAddress(library_kernelbase, "RegSetValueExW");
	pRegSetValueW = (void *)GetProcAddress(library, "RegSetValueW");
	pRegUnLoadKeyA = (void *)GetProcAddress(library, "RegUnLoadKeyA");
	pextRegUnLoadKeyA = (void *)GetProcAddress(library_kernelbase, "RegUnLoadKeyA");
	pRegUnLoadKeyW = (void *)GetProcAddress(library, "RegUnLoadKeyW");
	pextRegUnLoadKeyW = (void *)GetProcAddress(library_kernelbase, "RegUnLoadKeyW");
	pRegisterEventSourceA = (void *)GetProcAddress(library, "RegisterEventSourceA");
	pRegisterEventSourceW = (void *)GetProcAddress(library, "RegisterEventSourceW");
	pEtwRegisterTraceGuidsA = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsA");
	pextEtwRegisterTraceGuidsA = (void *)GetProcAddress(library_ntdll, "EtwRegisterTraceGuidsA");
	pEtwRegisterTraceGuidsW = (void *)GetProcAddress(library, "EtwRegisterTraceGuidsW");
	pextEtwRegisterTraceGuidsW = (void *)GetProcAddress(library_ntdll, "EtwRegisterTraceGuidsW");
	pRegisterWaitChainCOMCallback = (void *)GetProcAddress(library, "RegisterWaitChainCOMCallback");
	pReportEventA = (void *)GetProcAddress(library, "ReportEventA");
	pReportEventW = (void *)GetProcAddress(library, "ReportEventW");
	pRevertToSelf = (void *)GetProcAddress(library, "RevertToSelf");
	pextRevertToSelf = (void *)GetProcAddress(library_kernelbase, "RevertToSelf");
	pSaferCloseLevel = (void *)GetProcAddress(library, "SaferCloseLevel");
	pSaferComputeTokenFromLevel = (void *)GetProcAddress(library, "SaferComputeTokenFromLevel");
	pSaferCreateLevel = (void *)GetProcAddress(library, "SaferCreateLevel");
	pSaferGetPolicyInformation = (void *)GetProcAddress(library, "SaferGetPolicyInformation");
	pSaferIdentifyLevel = (void *)GetProcAddress(library, "SaferIdentifyLevel");
	pSaferSetLevelInformation = (void *)GetProcAddress(library, "SaferSetLevelInformation");
	pSetAclInformation = (void *)GetProcAddress(library, "SetAclInformation");
	pextSetAclInformation = (void *)GetProcAddress(library_kernelbase, "SetAclInformation");
	pSetEntriesInAclA = (void *)GetProcAddress(library, "SetEntriesInAclA");
	pSetEntriesInAclW = (void *)GetProcAddress(library, "SetEntriesInAclW");
	pSetFileSecurityA = (void *)GetProcAddress(library, "SetFileSecurityA");
	pSetFileSecurityW = (void *)GetProcAddress(library, "SetFileSecurityW");
	pextSetFileSecurityW = (void *)GetProcAddress(library_kernelbase, "SetFileSecurityW");
	pSetKernelObjectSecurity = (void *)GetProcAddress(library, "SetKernelObjectSecurity");
	pextSetKernelObjectSecurity = (void *)GetProcAddress(library_kernelbase, "SetKernelObjectSecurity");
	pSetNamedSecurityInfoA = (void *)GetProcAddress(library, "SetNamedSecurityInfoA");
	pSetNamedSecurityInfoW = (void *)GetProcAddress(library, "SetNamedSecurityInfoW");
	pSetPrivateObjectSecurity = (void *)GetProcAddress(library, "SetPrivateObjectSecurity");
	pextSetPrivateObjectSecurity = (void *)GetProcAddress(library_kernelbase, "SetPrivateObjectSecurity");
	pSetSecurityDescriptorControl = (void *)GetProcAddress(library, "SetSecurityDescriptorControl");
	pextSetSecurityDescriptorControl = (void *)GetProcAddress(library_kernelbase, "SetSecurityDescriptorControl");
	pSetSecurityDescriptorDacl = (void *)GetProcAddress(library, "SetSecurityDescriptorDacl");
	pextSetSecurityDescriptorDacl = (void *)GetProcAddress(library_kernelbase, "SetSecurityDescriptorDacl");
	pSetSecurityDescriptorGroup = (void *)GetProcAddress(library, "SetSecurityDescriptorGroup");
	pextSetSecurityDescriptorGroup = (void *)GetProcAddress(library_kernelbase, "SetSecurityDescriptorGroup");
	pSetSecurityDescriptorOwner = (void *)GetProcAddress(library, "SetSecurityDescriptorOwner");
	pextSetSecurityDescriptorOwner = (void *)GetProcAddress(library_kernelbase, "SetSecurityDescriptorOwner");
	pSetSecurityDescriptorSacl = (void *)GetProcAddress(library, "SetSecurityDescriptorSacl");
	pextSetSecurityDescriptorSacl = (void *)GetProcAddress(library_kernelbase, "SetSecurityDescriptorSacl");
	pSetSecurityInfo = (void *)GetProcAddress(library, "SetSecurityInfo");
	pSetThreadToken = (void *)GetProcAddress(library, "SetThreadToken");
	pextSetThreadToken = (void *)GetProcAddress(library_kernelbase, "SetThreadToken");
	pSetTokenInformation = (void *)GetProcAddress(library, "SetTokenInformation");
	pextSetTokenInformation = (void *)GetProcAddress(library_kernelbase, "SetTokenInformation");
	pStartTraceA = (void *)GetProcAddress(library, "StartTraceA");
	pStartTraceW = (void *)GetProcAddress(library, "StartTraceW");
	pStopTraceA = (void *)GetProcAddress(library, "StopTraceA");
	pStopTraceW = (void *)GetProcAddress(library, "StopTraceW");
	pSynchronizeWindows31FilesAndWindowsNTRegistry = (void *)GetProcAddress(library, "SynchronizeWindows31FilesAndWindowsNTRegistry");
	pSystemFunction001 = (void *)GetProcAddress(library, "SystemFunction001");
	pSystemFunction002 = (void *)GetProcAddress(library, "SystemFunction002");
	pSystemFunction003 = (void *)GetProcAddress(library, "SystemFunction003");
	pSystemFunction004 = (void *)GetProcAddress(library, "SystemFunction004");
	pSystemFunction005 = (void *)GetProcAddress(library, "SystemFunction005");
	pSystemFunction006 = (void *)GetProcAddress(library, "SystemFunction006");
	pSystemFunction007 = (void *)GetProcAddress(library, "SystemFunction007");
	pSystemFunction008 = (void *)GetProcAddress(library, "SystemFunction008");
	pSystemFunction009 = (void *)GetProcAddress(library, "SystemFunction009");
	pSystemFunction010 = (void *)GetProcAddress(library, "SystemFunction010");
	pSystemFunction012 = (void *)GetProcAddress(library, "SystemFunction012");
	pSystemFunction013 = (void *)GetProcAddress(library, "SystemFunction013");
	pSystemFunction024 = (void *)GetProcAddress(library, "SystemFunction024");
	pSystemFunction025 = (void *)GetProcAddress(library, "SystemFunction025");
	pSystemFunction030 = (void *)GetProcAddress(library, "SystemFunction030");
	pSystemFunction032 = (void *)GetProcAddress(library, "SystemFunction032");
	pSystemFunction035 = (void *)GetProcAddress(library, "SystemFunction035");
	pEtwLogTraceEvent = (void *)GetProcAddress(library, "EtwLogTraceEvent");
	pextEtwLogTraceEvent = (void *)GetProcAddress(library_ntdll, "EtwLogTraceEvent");
	pEtwTraceMessage = (void *)GetProcAddress(library, "EtwTraceMessage");
	pextEtwTraceMessage = (void *)GetProcAddress(library_ntdll, "EtwTraceMessage");
	pEtwTraceMessageVa = (void *)GetProcAddress(library, "EtwTraceMessageVa");
	pextEtwTraceMessageVa = (void *)GetProcAddress(library_ntdll, "EtwTraceMessageVa");
	pTraceSetInformation = (void *)GetProcAddress(library, "TraceSetInformation");
	pTreeResetNamedSecurityInfoW = (void *)GetProcAddress(library, "TreeResetNamedSecurityInfoW");
	pEtwUnregisterTraceGuids = (void *)GetProcAddress(library, "EtwUnregisterTraceGuids");
	pextEtwUnregisterTraceGuids = (void *)GetProcAddress(library_ntdll, "EtwUnregisterTraceGuids");
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
	pWriteEncryptedFileRaw = (void *)GetProcAddress(library, "WriteEncryptedFileRaw");
	initialized = TRUE;
}

void* wine_thunk_get_for_advapi32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pA_SHAFinal && func != pextA_SHAFinal)
		return wine_thunk_get_for_any(pextA_SHAFinal);
	if (func == pA_SHAInit && func != pextA_SHAInit)
		return wine_thunk_get_for_any(pextA_SHAInit);
	if (func == pA_SHAUpdate && func != pextA_SHAUpdate)
		return wine_thunk_get_for_any(pextA_SHAUpdate);
	if (func == pAbortSystemShutdownA)
		return wine32a_advapi32_AbortSystemShutdownA;
	if (func == pAbortSystemShutdownW)
		return wine32a_advapi32_AbortSystemShutdownW;
	if (func == pAccessCheck && func != pextAccessCheck)
		return wine_thunk_get_for_any(pextAccessCheck);
	if (func == pAccessCheckAndAuditAlarmA)
		return wine32a_advapi32_AccessCheckAndAuditAlarmA;
	if (func == pAccessCheckAndAuditAlarmW && func != pextAccessCheckAndAuditAlarmW)
		return wine_thunk_get_for_any(pextAccessCheckAndAuditAlarmW);
	if (func == pAccessCheckByType && func != pextAccessCheckByType)
		return wine_thunk_get_for_any(pextAccessCheckByType);
	if (func == pAddAccessAllowedAce && func != pextAddAccessAllowedAce)
		return wine_thunk_get_for_any(pextAddAccessAllowedAce);
	if (func == pAddAccessAllowedAceEx && func != pextAddAccessAllowedAceEx)
		return wine_thunk_get_for_any(pextAddAccessAllowedAceEx);
	if (func == pAddAccessAllowedObjectAce && func != pextAddAccessAllowedObjectAce)
		return wine_thunk_get_for_any(pextAddAccessAllowedObjectAce);
	if (func == pAddAccessDeniedAce && func != pextAddAccessDeniedAce)
		return wine_thunk_get_for_any(pextAddAccessDeniedAce);
	if (func == pAddAccessDeniedAceEx && func != pextAddAccessDeniedAceEx)
		return wine_thunk_get_for_any(pextAddAccessDeniedAceEx);
	if (func == pAddAccessDeniedObjectAce && func != pextAddAccessDeniedObjectAce)
		return wine_thunk_get_for_any(pextAddAccessDeniedObjectAce);
	if (func == pAddAce && func != pextAddAce)
		return wine_thunk_get_for_any(pextAddAce);
	if (func == pAddAuditAccessAce && func != pextAddAuditAccessAce)
		return wine_thunk_get_for_any(pextAddAuditAccessAce);
	if (func == pAddAuditAccessAceEx && func != pextAddAuditAccessAceEx)
		return wine_thunk_get_for_any(pextAddAuditAccessAceEx);
	if (func == pAddAuditAccessObjectAce && func != pextAddAuditAccessObjectAce)
		return wine_thunk_get_for_any(pextAddAuditAccessObjectAce);
	if (func == pAddMandatoryAce && func != pextAddMandatoryAce)
		return wine_thunk_get_for_any(pextAddMandatoryAce);
	if (func == pAdjustTokenGroups && func != pextAdjustTokenGroups)
		return wine_thunk_get_for_any(pextAdjustTokenGroups);
	if (func == pAdjustTokenPrivileges && func != pextAdjustTokenPrivileges)
		return wine_thunk_get_for_any(pextAdjustTokenPrivileges);
	if (func == pAllocateAndInitializeSid && func != pextAllocateAndInitializeSid)
		return wine_thunk_get_for_any(pextAllocateAndInitializeSid);
	if (func == pAllocateLocallyUniqueId && func != pextAllocateLocallyUniqueId)
		return wine_thunk_get_for_any(pextAllocateLocallyUniqueId);
	if (func == pAreAllAccessesGranted && func != pextAreAllAccessesGranted)
		return wine_thunk_get_for_any(pextAreAllAccessesGranted);
	if (func == pAreAnyAccessesGranted && func != pextAreAnyAccessesGranted)
		return wine_thunk_get_for_any(pextAreAnyAccessesGranted);
	if (func == pAuditQuerySystemPolicy)
		return wine32a_advapi32_AuditQuerySystemPolicy;
	if (func == pBackupEventLogA)
		return wine32a_advapi32_BackupEventLogA;
	if (func == pBackupEventLogW)
		return wine32a_advapi32_BackupEventLogW;
	if (func == pBuildExplicitAccessWithNameA)
		return wine32a_advapi32_BuildExplicitAccessWithNameA;
	if (func == pBuildExplicitAccessWithNameW)
		return wine32a_advapi32_BuildExplicitAccessWithNameW;
	if (func == pBuildSecurityDescriptorA)
		return wine32a_advapi32_BuildSecurityDescriptorA;
	if (func == pBuildSecurityDescriptorW)
		return wine32a_advapi32_BuildSecurityDescriptorW;
	if (func == pBuildTrusteeWithNameA)
		return wine32a_advapi32_BuildTrusteeWithNameA;
	if (func == pBuildTrusteeWithNameW)
		return wine32a_advapi32_BuildTrusteeWithNameW;
	if (func == pBuildTrusteeWithObjectsAndNameA)
		return wine32a_advapi32_BuildTrusteeWithObjectsAndNameA;
	if (func == pBuildTrusteeWithObjectsAndNameW)
		return wine32a_advapi32_BuildTrusteeWithObjectsAndNameW;
	if (func == pBuildTrusteeWithObjectsAndSidA)
		return wine32a_advapi32_BuildTrusteeWithObjectsAndSidA;
	if (func == pBuildTrusteeWithObjectsAndSidW)
		return wine32a_advapi32_BuildTrusteeWithObjectsAndSidW;
	if (func == pBuildTrusteeWithSidA)
		return wine32a_advapi32_BuildTrusteeWithSidA;
	if (func == pBuildTrusteeWithSidW)
		return wine32a_advapi32_BuildTrusteeWithSidW;
	if (func == pCheckTokenMembership && func != pextCheckTokenMembership)
		return wine_thunk_get_for_any(pextCheckTokenMembership);
	if (func == pClearEventLogA)
		return wine32a_advapi32_ClearEventLogA;
	if (func == pClearEventLogW)
		return wine32a_advapi32_ClearEventLogW;
	if (func == pCloseEncryptedFileRaw)
		return wine32a_advapi32_CloseEncryptedFileRaw;
	if (func == pCloseEventLog)
		return wine32a_advapi32_CloseEventLog;
	if (func == pCloseTrace)
		return wine32a_advapi32_CloseTrace;
	if (func == pCommandLineFromMsiDescriptor)
		return wine32a_advapi32_CommandLineFromMsiDescriptor;
	if (func == pControlTraceA)
		return wine32a_advapi32_ControlTraceA;
	if (func == pControlTraceW)
		return wine32a_advapi32_ControlTraceW;
	if (func == pConvertSecurityDescriptorToStringSecurityDescriptorA)
		return wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA;
	if (func == pConvertSecurityDescriptorToStringSecurityDescriptorW)
		return wine32a_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW;
	if (func == pConvertSidToStringSidA)
		return wine32a_advapi32_ConvertSidToStringSidA;
	if (func == pConvertSidToStringSidW)
		return wine32a_advapi32_ConvertSidToStringSidW;
	if (func == pConvertStringSecurityDescriptorToSecurityDescriptorA)
		return wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA;
	if (func == pConvertStringSecurityDescriptorToSecurityDescriptorW)
		return wine32a_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW;
	if (func == pConvertStringSidToSidA)
		return wine32a_advapi32_ConvertStringSidToSidA;
	if (func == pConvertStringSidToSidW)
		return wine32a_advapi32_ConvertStringSidToSidW;
	if (func == pConvertToAutoInheritPrivateObjectSecurity && func != pextConvertToAutoInheritPrivateObjectSecurity)
		return wine_thunk_get_for_any(pextConvertToAutoInheritPrivateObjectSecurity);
	if (func == pCopySid && func != pextCopySid)
		return wine_thunk_get_for_any(pextCopySid);
	if (func == pCreatePrivateObjectSecurity && func != pextCreatePrivateObjectSecurity)
		return wine_thunk_get_for_any(pextCreatePrivateObjectSecurity);
	if (func == pCreatePrivateObjectSecurityEx && func != pextCreatePrivateObjectSecurityEx)
		return wine_thunk_get_for_any(pextCreatePrivateObjectSecurityEx);
	if (func == pCreatePrivateObjectSecurityWithMultipleInheritance && func != pextCreatePrivateObjectSecurityWithMultipleInheritance)
		return wine_thunk_get_for_any(pextCreatePrivateObjectSecurityWithMultipleInheritance);
	if (func == pCreateProcessAsUserA && func != pextCreateProcessAsUserA)
		return wine_thunk_get_for_any(pextCreateProcessAsUserA);
	if (func == pCreateProcessAsUserW && func != pextCreateProcessAsUserW)
		return wine_thunk_get_for_any(pextCreateProcessAsUserW);
	if (func == pCreateProcessWithLogonW)
		return wine32a_advapi32_CreateProcessWithLogonW;
	if (func == pCreateProcessWithTokenW)
		return wine32a_advapi32_CreateProcessWithTokenW;
	if (func == pCreateRestrictedToken && func != pextCreateRestrictedToken)
		return wine_thunk_get_for_any(pextCreateRestrictedToken);
	if (func == pCreateWellKnownSid && func != pextCreateWellKnownSid)
		return wine_thunk_get_for_any(pextCreateWellKnownSid);
	if (func == pCredDeleteA)
		return wine32a_advapi32_CredDeleteA;
	if (func == pCredDeleteW)
		return wine32a_advapi32_CredDeleteW;
	if (func == pCredEnumerateA)
		return wine32a_advapi32_CredEnumerateA;
	if (func == pCredEnumerateW)
		return wine32a_advapi32_CredEnumerateW;
	if (func == pCredFree)
		return wine32a_advapi32_CredFree;
	if (func == pCredGetSessionTypes)
		return wine32a_advapi32_CredGetSessionTypes;
	if (func == pCredIsMarshaledCredentialA)
		return wine32a_advapi32_CredIsMarshaledCredentialA;
	if (func == pCredIsMarshaledCredentialW)
		return wine32a_advapi32_CredIsMarshaledCredentialW;
	if (func == pCredMarshalCredentialA)
		return wine32a_advapi32_CredMarshalCredentialA;
	if (func == pCredMarshalCredentialW)
		return wine32a_advapi32_CredMarshalCredentialW;
	if (func == pCredReadA)
		return wine32a_advapi32_CredReadA;
	if (func == pCredReadDomainCredentialsA)
		return wine32a_advapi32_CredReadDomainCredentialsA;
	if (func == pCredReadDomainCredentialsW)
		return wine32a_advapi32_CredReadDomainCredentialsW;
	if (func == pCredReadW)
		return wine32a_advapi32_CredReadW;
	if (func == pCredUnmarshalCredentialA)
		return wine32a_advapi32_CredUnmarshalCredentialA;
	if (func == pCredUnmarshalCredentialW)
		return wine32a_advapi32_CredUnmarshalCredentialW;
	if (func == pCredWriteA)
		return wine32a_advapi32_CredWriteA;
	if (func == pCredWriteW)
		return wine32a_advapi32_CredWriteW;
	if (func == pCryptAcquireContextA)
		return wine32a_advapi32_CryptAcquireContextA;
	if (func == pCryptAcquireContextW)
		return wine32a_advapi32_CryptAcquireContextW;
	if (func == pCryptContextAddRef)
		return wine32a_advapi32_CryptContextAddRef;
	if (func == pCryptCreateHash)
		return wine32a_advapi32_CryptCreateHash;
	if (func == pCryptDecrypt)
		return wine32a_advapi32_CryptDecrypt;
	if (func == pCryptDeriveKey)
		return wine32a_advapi32_CryptDeriveKey;
	if (func == pCryptDestroyHash)
		return wine32a_advapi32_CryptDestroyHash;
	if (func == pCryptDestroyKey)
		return wine32a_advapi32_CryptDestroyKey;
	if (func == pCryptDuplicateHash)
		return wine32a_advapi32_CryptDuplicateHash;
	if (func == pCryptDuplicateKey)
		return wine32a_advapi32_CryptDuplicateKey;
	if (func == pCryptEncrypt)
		return wine32a_advapi32_CryptEncrypt;
	if (func == pCryptEnumProviderTypesA)
		return wine32a_advapi32_CryptEnumProviderTypesA;
	if (func == pCryptEnumProviderTypesW)
		return wine32a_advapi32_CryptEnumProviderTypesW;
	if (func == pCryptEnumProvidersA)
		return wine32a_advapi32_CryptEnumProvidersA;
	if (func == pCryptEnumProvidersW)
		return wine32a_advapi32_CryptEnumProvidersW;
	if (func == pCryptExportKey)
		return wine32a_advapi32_CryptExportKey;
	if (func == pCryptGenKey)
		return wine32a_advapi32_CryptGenKey;
	if (func == pCryptGenRandom)
		return wine32a_advapi32_CryptGenRandom;
	if (func == pCryptGetDefaultProviderA)
		return wine32a_advapi32_CryptGetDefaultProviderA;
	if (func == pCryptGetDefaultProviderW)
		return wine32a_advapi32_CryptGetDefaultProviderW;
	if (func == pCryptGetHashParam)
		return wine32a_advapi32_CryptGetHashParam;
	if (func == pCryptGetKeyParam)
		return wine32a_advapi32_CryptGetKeyParam;
	if (func == pCryptGetProvParam)
		return wine32a_advapi32_CryptGetProvParam;
	if (func == pCryptGetUserKey)
		return wine32a_advapi32_CryptGetUserKey;
	if (func == pCryptHashData)
		return wine32a_advapi32_CryptHashData;
	if (func == pCryptHashSessionKey)
		return wine32a_advapi32_CryptHashSessionKey;
	if (func == pCryptImportKey)
		return wine32a_advapi32_CryptImportKey;
	if (func == pCryptReleaseContext)
		return wine32a_advapi32_CryptReleaseContext;
	if (func == pCryptSetHashParam)
		return wine32a_advapi32_CryptSetHashParam;
	if (func == pCryptSetKeyParam)
		return wine32a_advapi32_CryptSetKeyParam;
	if (func == pCryptSetProvParam)
		return wine32a_advapi32_CryptSetProvParam;
	if (func == pCryptSetProviderA)
		return wine32a_advapi32_CryptSetProviderA;
	if (func == pCryptSetProviderExA)
		return wine32a_advapi32_CryptSetProviderExA;
	if (func == pCryptSetProviderExW)
		return wine32a_advapi32_CryptSetProviderExW;
	if (func == pCryptSetProviderW)
		return wine32a_advapi32_CryptSetProviderW;
	if (func == pCryptSignHashA)
		return wine32a_advapi32_CryptSignHashA;
	if (func == pCryptSignHashW)
		return wine32a_advapi32_CryptSignHashW;
	if (func == pCryptVerifySignatureA)
		return wine32a_advapi32_CryptVerifySignatureA;
	if (func == pCryptVerifySignatureW)
		return wine32a_advapi32_CryptVerifySignatureW;
	if (func == pDecryptFileA)
		return wine32a_advapi32_DecryptFileA;
	if (func == pDecryptFileW)
		return wine32a_advapi32_DecryptFileW;
	if (func == pDeleteAce && func != pextDeleteAce)
		return wine_thunk_get_for_any(pextDeleteAce);
	if (func == pDeregisterEventSource)
		return wine32a_advapi32_DeregisterEventSource;
	if (func == pDestroyPrivateObjectSecurity && func != pextDestroyPrivateObjectSecurity)
		return wine_thunk_get_for_any(pextDestroyPrivateObjectSecurity);
	if (func == pDuplicateToken && func != pextDuplicateToken)
		return wine_thunk_get_for_any(pextDuplicateToken);
	if (func == pDuplicateTokenEx && func != pextDuplicateTokenEx)
		return wine_thunk_get_for_any(pextDuplicateTokenEx);
	if (func == pEnableTrace)
		return wine32a_advapi32_EnableTrace;
	if (func == pEnableTraceEx)
		return wine32a_advapi32_EnableTraceEx;
	if (func == pEnableTraceEx2)
		return wine32a_advapi32_EnableTraceEx2;
	if (func == pEncryptFileA)
		return wine32a_advapi32_EncryptFileA;
	if (func == pEncryptFileW)
		return wine32a_advapi32_EncryptFileW;
	if (func == pEnumDynamicTimeZoneInformation && func != pextEnumDynamicTimeZoneInformation)
		return wine_thunk_get_for_any(pextEnumDynamicTimeZoneInformation);
	if (func == pEnumerateTraceGuids)
		return wine32a_advapi32_EnumerateTraceGuids;
	if (func == pEqualPrefixSid && func != pextEqualPrefixSid)
		return wine_thunk_get_for_any(pextEqualPrefixSid);
	if (func == pEqualSid && func != pextEqualSid)
		return wine_thunk_get_for_any(pextEqualSid);
	if (func == pEtwEventActivityIdControl && func != pextEtwEventActivityIdControl)
		return wine_thunk_get_for_any(pextEtwEventActivityIdControl);
	if (func == pEtwEventEnabled && func != pextEtwEventEnabled)
		return wine_thunk_get_for_any(pextEtwEventEnabled);
	if (func == pEtwEventProviderEnabled && func != pextEtwEventProviderEnabled)
		return wine_thunk_get_for_any(pextEtwEventProviderEnabled);
	if (func == pEtwEventRegister && func != pextEtwEventRegister)
		return wine_thunk_get_for_any(pextEtwEventRegister);
	if (func == pEtwEventSetInformation && func != pextEtwEventSetInformation)
		return wine_thunk_get_for_any(pextEtwEventSetInformation);
	if (func == pEtwEventUnregister && func != pextEtwEventUnregister)
		return wine_thunk_get_for_any(pextEtwEventUnregister);
	if (func == pEtwEventWrite && func != pextEtwEventWrite)
		return wine_thunk_get_for_any(pextEtwEventWrite);
	if (func == pEtwEventWriteString && func != pextEtwEventWriteString)
		return wine_thunk_get_for_any(pextEtwEventWriteString);
	if (func == pEtwEventWriteTransfer && func != pextEtwEventWriteTransfer)
		return wine_thunk_get_for_any(pextEtwEventWriteTransfer);
	if (func == pFileEncryptionStatusA)
		return wine32a_advapi32_FileEncryptionStatusA;
	if (func == pFileEncryptionStatusW)
		return wine32a_advapi32_FileEncryptionStatusW;
	if (func == pFindFirstFreeAce && func != pextFindFirstFreeAce)
		return wine_thunk_get_for_any(pextFindFirstFreeAce);
	if (func == pFlushTraceA)
		return wine32a_advapi32_FlushTraceA;
	if (func == pFlushTraceW)
		return wine32a_advapi32_FlushTraceW;
	if (func == pFreeSid && func != pextFreeSid)
		return wine_thunk_get_for_any(pextFreeSid);
	if (func == pGetAce && func != pextGetAce)
		return wine_thunk_get_for_any(pextGetAce);
	if (func == pGetAclInformation && func != pextGetAclInformation)
		return wine_thunk_get_for_any(pextGetAclInformation);
	if (func == pGetAuditedPermissionsFromAclA)
		return wine32a_advapi32_GetAuditedPermissionsFromAclA;
	if (func == pGetAuditedPermissionsFromAclW)
		return wine32a_advapi32_GetAuditedPermissionsFromAclW;
	if (func == pGetCurrentHwProfileA)
		return wine32a_advapi32_GetCurrentHwProfileA;
	if (func == pGetCurrentHwProfileW)
		return wine32a_advapi32_GetCurrentHwProfileW;
	if (func == pGetDynamicTimeZoneInformationEffectiveYears && func != pextGetDynamicTimeZoneInformationEffectiveYears)
		return wine_thunk_get_for_any(pextGetDynamicTimeZoneInformationEffectiveYears);
	if (func == pGetEffectiveRightsFromAclA)
		return wine32a_advapi32_GetEffectiveRightsFromAclA;
	if (func == pGetEffectiveRightsFromAclW)
		return wine32a_advapi32_GetEffectiveRightsFromAclW;
	if (func == pGetEventLogInformation)
		return wine32a_advapi32_GetEventLogInformation;
	if (func == pGetExplicitEntriesFromAclA)
		return wine32a_advapi32_GetExplicitEntriesFromAclA;
	if (func == pGetExplicitEntriesFromAclW)
		return wine32a_advapi32_GetExplicitEntriesFromAclW;
	if (func == pGetFileSecurityA)
		return wine32a_advapi32_GetFileSecurityA;
	if (func == pGetFileSecurityW && func != pextGetFileSecurityW)
		return wine_thunk_get_for_any(pextGetFileSecurityW);
	if (func == pGetKernelObjectSecurity && func != pextGetKernelObjectSecurity)
		return wine_thunk_get_for_any(pextGetKernelObjectSecurity);
	if (func == pGetLengthSid && func != pextGetLengthSid)
		return wine_thunk_get_for_any(pextGetLengthSid);
	if (func == pGetNamedSecurityInfoA)
		return wine32a_advapi32_GetNamedSecurityInfoA;
	if (func == pGetNamedSecurityInfoExA)
		return wine32a_advapi32_GetNamedSecurityInfoExA;
	if (func == pGetNamedSecurityInfoExW)
		return wine32a_advapi32_GetNamedSecurityInfoExW;
	if (func == pGetNamedSecurityInfoW)
		return wine32a_advapi32_GetNamedSecurityInfoW;
	if (func == pGetNumberOfEventLogRecords)
		return wine32a_advapi32_GetNumberOfEventLogRecords;
	if (func == pGetOldestEventLogRecord)
		return wine32a_advapi32_GetOldestEventLogRecord;
	if (func == pGetPrivateObjectSecurity && func != pextGetPrivateObjectSecurity)
		return wine_thunk_get_for_any(pextGetPrivateObjectSecurity);
	if (func == pGetSecurityDescriptorControl && func != pextGetSecurityDescriptorControl)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorControl);
	if (func == pGetSecurityDescriptorDacl && func != pextGetSecurityDescriptorDacl)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorDacl);
	if (func == pGetSecurityDescriptorGroup && func != pextGetSecurityDescriptorGroup)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorGroup);
	if (func == pGetSecurityDescriptorLength && func != pextGetSecurityDescriptorLength)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorLength);
	if (func == pGetSecurityDescriptorOwner && func != pextGetSecurityDescriptorOwner)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorOwner);
	if (func == pGetSecurityDescriptorSacl && func != pextGetSecurityDescriptorSacl)
		return wine_thunk_get_for_any(pextGetSecurityDescriptorSacl);
	if (func == pGetSecurityInfo)
		return wine32a_advapi32_GetSecurityInfo;
	if (func == pGetSecurityInfoExA)
		return wine32a_advapi32_GetSecurityInfoExA;
	if (func == pGetSecurityInfoExW)
		return wine32a_advapi32_GetSecurityInfoExW;
	if (func == pGetSidIdentifierAuthority && func != pextGetSidIdentifierAuthority)
		return wine_thunk_get_for_any(pextGetSidIdentifierAuthority);
	if (func == pGetSidLengthRequired && func != pextGetSidLengthRequired)
		return wine_thunk_get_for_any(pextGetSidLengthRequired);
	if (func == pGetSidSubAuthority && func != pextGetSidSubAuthority)
		return wine_thunk_get_for_any(pextGetSidSubAuthority);
	if (func == pGetSidSubAuthorityCount && func != pextGetSidSubAuthorityCount)
		return wine_thunk_get_for_any(pextGetSidSubAuthorityCount);
	if (func == pGetTokenInformation && func != pextGetTokenInformation)
		return wine_thunk_get_for_any(pextGetTokenInformation);
	if (func == pEtwGetTraceEnableFlags && func != pextEtwGetTraceEnableFlags)
		return wine_thunk_get_for_any(pextEtwGetTraceEnableFlags);
	if (func == pEtwGetTraceEnableLevel && func != pextEtwGetTraceEnableLevel)
		return wine_thunk_get_for_any(pextEtwGetTraceEnableLevel);
	if (func == pEtwGetTraceLoggerHandle && func != pextEtwGetTraceLoggerHandle)
		return wine_thunk_get_for_any(pextEtwGetTraceLoggerHandle);
	if (func == pGetTrusteeFormA)
		return wine32a_advapi32_GetTrusteeFormA;
	if (func == pGetTrusteeFormW)
		return wine32a_advapi32_GetTrusteeFormW;
	if (func == pGetTrusteeNameA)
		return wine32a_advapi32_GetTrusteeNameA;
	if (func == pGetTrusteeNameW)
		return wine32a_advapi32_GetTrusteeNameW;
	if (func == pGetTrusteeTypeA)
		return wine32a_advapi32_GetTrusteeTypeA;
	if (func == pGetTrusteeTypeW)
		return wine32a_advapi32_GetTrusteeTypeW;
	if (func == pGetUserNameA)
		return wine32a_advapi32_GetUserNameA;
	if (func == pGetUserNameW)
		return wine32a_advapi32_GetUserNameW;
	if (func == pGetWindowsAccountDomainSid && func != pextGetWindowsAccountDomainSid)
		return wine_thunk_get_for_any(pextGetWindowsAccountDomainSid);
	if (func == pImpersonateAnonymousToken && func != pextImpersonateAnonymousToken)
		return wine_thunk_get_for_any(pextImpersonateAnonymousToken);
	if (func == pImpersonateLoggedOnUser && func != pextImpersonateLoggedOnUser)
		return wine_thunk_get_for_any(pextImpersonateLoggedOnUser);
	if (func == pImpersonateNamedPipeClient && func != pextImpersonateNamedPipeClient)
		return wine_thunk_get_for_any(pextImpersonateNamedPipeClient);
	if (func == pImpersonateSelf && func != pextImpersonateSelf)
		return wine_thunk_get_for_any(pextImpersonateSelf);
	if (func == pInitializeAcl && func != pextInitializeAcl)
		return wine_thunk_get_for_any(pextInitializeAcl);
	if (func == pInitializeSecurityDescriptor && func != pextInitializeSecurityDescriptor)
		return wine_thunk_get_for_any(pextInitializeSecurityDescriptor);
	if (func == pInitializeSid && func != pextInitializeSid)
		return wine_thunk_get_for_any(pextInitializeSid);
	if (func == pInitiateShutdownA)
		return wine32a_advapi32_InitiateShutdownA;
	if (func == pInitiateShutdownW)
		return wine32a_advapi32_InitiateShutdownW;
	if (func == pInitiateSystemShutdownA)
		return wine32a_advapi32_InitiateSystemShutdownA;
	if (func == pInitiateSystemShutdownExA)
		return wine32a_advapi32_InitiateSystemShutdownExA;
	if (func == pInitiateSystemShutdownExW)
		return wine32a_advapi32_InitiateSystemShutdownExW;
	if (func == pInitiateSystemShutdownW)
		return wine32a_advapi32_InitiateSystemShutdownW;
	if (func == pIsTextUnicode)
		return wine32a_advapi32_IsTextUnicode;
	if (func == pIsTokenRestricted && func != pextIsTokenRestricted)
		return wine_thunk_get_for_any(pextIsTokenRestricted);
	if (func == pIsValidAcl && func != pextIsValidAcl)
		return wine_thunk_get_for_any(pextIsValidAcl);
	if (func == pIsValidSecurityDescriptor && func != pextIsValidSecurityDescriptor)
		return wine_thunk_get_for_any(pextIsValidSecurityDescriptor);
	if (func == pIsValidSid && func != pextIsValidSid)
		return wine_thunk_get_for_any(pextIsValidSid);
	if (func == pIsWellKnownSid && func != pextIsWellKnownSid)
		return wine_thunk_get_for_any(pextIsWellKnownSid);
	if (func == pLogonUserA)
		return wine32a_advapi32_LogonUserA;
	if (func == pLogonUserW)
		return wine32a_advapi32_LogonUserW;
	if (func == pLookupAccountNameA)
		return wine32a_advapi32_LookupAccountNameA;
	if (func == pLookupAccountNameW)
		return wine32a_advapi32_LookupAccountNameW;
	if (func == pLookupAccountSidA)
		return wine32a_advapi32_LookupAccountSidA;
	if (func == pLookupAccountSidLocalA)
		return wine32a_advapi32_LookupAccountSidLocalA;
	if (func == pLookupAccountSidLocalW)
		return wine32a_advapi32_LookupAccountSidLocalW;
	if (func == pLookupAccountSidW)
		return wine32a_advapi32_LookupAccountSidW;
	if (func == pLookupPrivilegeDisplayNameA)
		return wine32a_advapi32_LookupPrivilegeDisplayNameA;
	if (func == pLookupPrivilegeDisplayNameW)
		return wine32a_advapi32_LookupPrivilegeDisplayNameW;
	if (func == pLookupPrivilegeNameA)
		return wine32a_advapi32_LookupPrivilegeNameA;
	if (func == pLookupPrivilegeNameW)
		return wine32a_advapi32_LookupPrivilegeNameW;
	if (func == pLookupPrivilegeValueA)
		return wine32a_advapi32_LookupPrivilegeValueA;
	if (func == pLookupPrivilegeValueW)
		return wine32a_advapi32_LookupPrivilegeValueW;
	if (func == pLookupSecurityDescriptorPartsA)
		return wine32a_advapi32_LookupSecurityDescriptorPartsA;
	if (func == pLookupSecurityDescriptorPartsW)
		return wine32a_advapi32_LookupSecurityDescriptorPartsW;
	if (func == pLsaAddAccountRights)
		return wine32a_advapi32_LsaAddAccountRights;
	if (func == pLsaClose)
		return wine32a_advapi32_LsaClose;
	if (func == pLsaCreateTrustedDomainEx)
		return wine32a_advapi32_LsaCreateTrustedDomainEx;
	if (func == pLsaDeleteTrustedDomain)
		return wine32a_advapi32_LsaDeleteTrustedDomain;
	if (func == pLsaEnumerateAccountRights)
		return wine32a_advapi32_LsaEnumerateAccountRights;
	if (func == pLsaEnumerateAccountsWithUserRight)
		return wine32a_advapi32_LsaEnumerateAccountsWithUserRight;
	if (func == pLsaEnumerateTrustedDomains)
		return wine32a_advapi32_LsaEnumerateTrustedDomains;
	if (func == pLsaEnumerateTrustedDomainsEx)
		return wine32a_advapi32_LsaEnumerateTrustedDomainsEx;
	if (func == pLsaFreeMemory)
		return wine32a_advapi32_LsaFreeMemory;
	if (func == pLsaLookupNames)
		return wine32a_advapi32_LsaLookupNames;
	if (func == pLsaLookupNames2)
		return wine32a_advapi32_LsaLookupNames2;
	if (func == pLsaLookupPrivilegeDisplayName)
		return wine32a_advapi32_LsaLookupPrivilegeDisplayName;
	if (func == pLsaLookupPrivilegeName)
		return wine32a_advapi32_LsaLookupPrivilegeName;
	if (func == pLsaLookupSids)
		return wine32a_advapi32_LsaLookupSids;
	if (func == pLsaNtStatusToWinError)
		return wine32a_advapi32_LsaNtStatusToWinError;
	if (func == pLsaOpenPolicy)
		return wine32a_advapi32_LsaOpenPolicy;
	if (func == pLsaOpenTrustedDomainByName)
		return wine32a_advapi32_LsaOpenTrustedDomainByName;
	if (func == pLsaQueryInformationPolicy)
		return wine32a_advapi32_LsaQueryInformationPolicy;
	if (func == pLsaQueryTrustedDomainInfo)
		return wine32a_advapi32_LsaQueryTrustedDomainInfo;
	if (func == pLsaQueryTrustedDomainInfoByName)
		return wine32a_advapi32_LsaQueryTrustedDomainInfoByName;
	if (func == pLsaRegisterPolicyChangeNotification)
		return wine32a_advapi32_LsaRegisterPolicyChangeNotification;
	if (func == pLsaRemoveAccountRights)
		return wine32a_advapi32_LsaRemoveAccountRights;
	if (func == pLsaRetrievePrivateData)
		return wine32a_advapi32_LsaRetrievePrivateData;
	if (func == pLsaSetInformationPolicy)
		return wine32a_advapi32_LsaSetInformationPolicy;
	if (func == pLsaSetSecret)
		return wine32a_advapi32_LsaSetSecret;
	if (func == pLsaSetTrustedDomainInfoByName)
		return wine32a_advapi32_LsaSetTrustedDomainInfoByName;
	if (func == pLsaSetTrustedDomainInformation)
		return wine32a_advapi32_LsaSetTrustedDomainInformation;
	if (func == pLsaStorePrivateData)
		return wine32a_advapi32_LsaStorePrivateData;
	if (func == pLsaUnregisterPolicyChangeNotification)
		return wine32a_advapi32_LsaUnregisterPolicyChangeNotification;
	if (func == pMD4Final && func != pextMD4Final)
		return wine_thunk_get_for_any(pextMD4Final);
	if (func == pMD4Init && func != pextMD4Init)
		return wine_thunk_get_for_any(pextMD4Init);
	if (func == pMD4Update && func != pextMD4Update)
		return wine_thunk_get_for_any(pextMD4Update);
	if (func == pMD5Final && func != pextMD5Final)
		return wine_thunk_get_for_any(pextMD5Final);
	if (func == pMD5Init && func != pextMD5Init)
		return wine_thunk_get_for_any(pextMD5Init);
	if (func == pMD5Update && func != pextMD5Update)
		return wine_thunk_get_for_any(pextMD5Update);
	if (func == pMakeAbsoluteSD && func != pextMakeAbsoluteSD)
		return wine_thunk_get_for_any(pextMakeAbsoluteSD);
	if (func == pMakeSelfRelativeSD && func != pextMakeSelfRelativeSD)
		return wine_thunk_get_for_any(pextMakeSelfRelativeSD);
	if (func == pMapGenericMask && func != pextMapGenericMask)
		return wine_thunk_get_for_any(pextMapGenericMask);
	if (func == pNotifyBootConfigStatus)
		return wine32a_advapi32_NotifyBootConfigStatus;
	if (func == pNotifyChangeEventLog)
		return wine32a_advapi32_NotifyChangeEventLog;
	if (func == pObjectCloseAuditAlarmA)
		return wine32a_advapi32_ObjectCloseAuditAlarmA;
	if (func == pObjectCloseAuditAlarmW && func != pextObjectCloseAuditAlarmW)
		return wine_thunk_get_for_any(pextObjectCloseAuditAlarmW);
	if (func == pObjectDeleteAuditAlarmW && func != pextObjectDeleteAuditAlarmW)
		return wine_thunk_get_for_any(pextObjectDeleteAuditAlarmW);
	if (func == pObjectOpenAuditAlarmA)
		return wine32a_advapi32_ObjectOpenAuditAlarmA;
	if (func == pObjectOpenAuditAlarmW && func != pextObjectOpenAuditAlarmW)
		return wine_thunk_get_for_any(pextObjectOpenAuditAlarmW);
	if (func == pObjectPrivilegeAuditAlarmA)
		return wine32a_advapi32_ObjectPrivilegeAuditAlarmA;
	if (func == pObjectPrivilegeAuditAlarmW && func != pextObjectPrivilegeAuditAlarmW)
		return wine_thunk_get_for_any(pextObjectPrivilegeAuditAlarmW);
	if (func == pOpenBackupEventLogA)
		return wine32a_advapi32_OpenBackupEventLogA;
	if (func == pOpenBackupEventLogW)
		return wine32a_advapi32_OpenBackupEventLogW;
	if (func == pOpenEncryptedFileRawA)
		return wine32a_advapi32_OpenEncryptedFileRawA;
	if (func == pOpenEncryptedFileRawW)
		return wine32a_advapi32_OpenEncryptedFileRawW;
	if (func == pOpenEventLogA)
		return wine32a_advapi32_OpenEventLogA;
	if (func == pOpenEventLogW)
		return wine32a_advapi32_OpenEventLogW;
	if (func == pOpenProcessToken && func != pextOpenProcessToken)
		return wine_thunk_get_for_any(pextOpenProcessToken);
	if (func == pOpenThreadToken && func != pextOpenThreadToken)
		return wine_thunk_get_for_any(pextOpenThreadToken);
	if (func == pOpenTraceA)
		return wine32a_advapi32_OpenTraceA;
	if (func == pOpenTraceW)
		return wine32a_advapi32_OpenTraceW;
	if (func == pPerfCreateInstance && func != pextPerfCreateInstance)
		return wine_thunk_get_for_any(pextPerfCreateInstance);
	if (func == pPerfDeleteInstance && func != pextPerfDeleteInstance)
		return wine_thunk_get_for_any(pextPerfDeleteInstance);
	if (func == pPerfSetCounterRefValue && func != pextPerfSetCounterRefValue)
		return wine_thunk_get_for_any(pextPerfSetCounterRefValue);
	if (func == pPerfSetCounterSetInfo && func != pextPerfSetCounterSetInfo)
		return wine_thunk_get_for_any(pextPerfSetCounterSetInfo);
	if (func == pPerfStartProvider && func != pextPerfStartProvider)
		return wine_thunk_get_for_any(pextPerfStartProvider);
	if (func == pPerfStartProviderEx && func != pextPerfStartProviderEx)
		return wine_thunk_get_for_any(pextPerfStartProviderEx);
	if (func == pPerfStopProvider && func != pextPerfStopProvider)
		return wine_thunk_get_for_any(pextPerfStopProvider);
	if (func == pPrivilegeCheck && func != pextPrivilegeCheck)
		return wine_thunk_get_for_any(pextPrivilegeCheck);
	if (func == pPrivilegedServiceAuditAlarmA)
		return wine32a_advapi32_PrivilegedServiceAuditAlarmA;
	if (func == pPrivilegedServiceAuditAlarmW && func != pextPrivilegedServiceAuditAlarmW)
		return wine_thunk_get_for_any(pextPrivilegedServiceAuditAlarmW);
	if (func == pProcessTrace)
		return wine32a_advapi32_ProcessTrace;
	if (func == pQueryAllTracesA)
		return wine32a_advapi32_QueryAllTracesA;
	if (func == pQueryAllTracesW)
		return wine32a_advapi32_QueryAllTracesW;
	if (func == pQueryTraceW)
		return wine32a_advapi32_QueryTraceW;
	if (func == pQueryWindows31FilesMigration)
		return wine32a_advapi32_QueryWindows31FilesMigration;
	if (func == pReadEncryptedFileRaw)
		return wine32a_advapi32_ReadEncryptedFileRaw;
	if (func == pReadEventLogA)
		return wine32a_advapi32_ReadEventLogA;
	if (func == pReadEventLogW)
		return wine32a_advapi32_ReadEventLogW;
	if (func == pRegCloseKey && func != pextRegCloseKey)
		return wine_thunk_get_for_any(pextRegCloseKey);
	if (func == pRegConnectRegistryA)
		return wine32a_advapi32_RegConnectRegistryA;
	if (func == pRegConnectRegistryW)
		return wine32a_advapi32_RegConnectRegistryW;
	if (func == pRegCopyTreeA)
		return wine32a_advapi32_RegCopyTreeA;
	if (func == pRegCopyTreeW && func != pextRegCopyTreeW)
		return wine_thunk_get_for_any(pextRegCopyTreeW);
	if (func == pRegCreateKeyA)
		return wine32a_advapi32_RegCreateKeyA;
	if (func == pRegCreateKeyExA && func != pextRegCreateKeyExA)
		return wine_thunk_get_for_any(pextRegCreateKeyExA);
	if (func == pRegCreateKeyExW && func != pextRegCreateKeyExW)
		return wine_thunk_get_for_any(pextRegCreateKeyExW);
	if (func == pRegCreateKeyTransactedA)
		return wine32a_advapi32_RegCreateKeyTransactedA;
	if (func == pRegCreateKeyTransactedW)
		return wine32a_advapi32_RegCreateKeyTransactedW;
	if (func == pRegCreateKeyW)
		return wine32a_advapi32_RegCreateKeyW;
	if (func == pRegDeleteKeyA)
		return wine32a_advapi32_RegDeleteKeyA;
	if (func == pRegDeleteKeyExA && func != pextRegDeleteKeyExA)
		return wine_thunk_get_for_any(pextRegDeleteKeyExA);
	if (func == pRegDeleteKeyExW && func != pextRegDeleteKeyExW)
		return wine_thunk_get_for_any(pextRegDeleteKeyExW);
	if (func == pRegDeleteKeyValueA && func != pextRegDeleteKeyValueA)
		return wine_thunk_get_for_any(pextRegDeleteKeyValueA);
	if (func == pRegDeleteKeyValueW && func != pextRegDeleteKeyValueW)
		return wine_thunk_get_for_any(pextRegDeleteKeyValueW);
	if (func == pRegDeleteKeyW)
		return wine32a_advapi32_RegDeleteKeyW;
	if (func == pRegDeleteTreeA && func != pextRegDeleteTreeA)
		return wine_thunk_get_for_any(pextRegDeleteTreeA);
	if (func == pRegDeleteTreeW && func != pextRegDeleteTreeW)
		return wine_thunk_get_for_any(pextRegDeleteTreeW);
	if (func == pRegDeleteValueA && func != pextRegDeleteValueA)
		return wine_thunk_get_for_any(pextRegDeleteValueA);
	if (func == pRegDeleteValueW && func != pextRegDeleteValueW)
		return wine_thunk_get_for_any(pextRegDeleteValueW);
	if (func == pRegDisablePredefinedCache)
		return wine32a_advapi32_RegDisablePredefinedCache;
	if (func == pRegDisableReflectionKey)
		return wine32a_advapi32_RegDisableReflectionKey;
	if (func == pRegEnumKeyA)
		return wine32a_advapi32_RegEnumKeyA;
	if (func == pRegEnumKeyExA && func != pextRegEnumKeyExA)
		return wine_thunk_get_for_any(pextRegEnumKeyExA);
	if (func == pRegEnumKeyExW && func != pextRegEnumKeyExW)
		return wine_thunk_get_for_any(pextRegEnumKeyExW);
	if (func == pRegEnumKeyW)
		return wine32a_advapi32_RegEnumKeyW;
	if (func == pRegEnumValueA && func != pextRegEnumValueA)
		return wine_thunk_get_for_any(pextRegEnumValueA);
	if (func == pRegEnumValueW && func != pextRegEnumValueW)
		return wine_thunk_get_for_any(pextRegEnumValueW);
	if (func == pRegFlushKey && func != pextRegFlushKey)
		return wine_thunk_get_for_any(pextRegFlushKey);
	if (func == pRegGetKeySecurity && func != pextRegGetKeySecurity)
		return wine_thunk_get_for_any(pextRegGetKeySecurity);
	if (func == pRegGetValueA && func != pextRegGetValueA)
		return wine_thunk_get_for_any(pextRegGetValueA);
	if (func == pRegGetValueW && func != pextRegGetValueW)
		return wine_thunk_get_for_any(pextRegGetValueW);
	if (func == pRegLoadAppKeyA && func != pextRegLoadAppKeyA)
		return wine_thunk_get_for_any(pextRegLoadAppKeyA);
	if (func == pRegLoadAppKeyW && func != pextRegLoadAppKeyW)
		return wine_thunk_get_for_any(pextRegLoadAppKeyW);
	if (func == pRegLoadKeyA && func != pextRegLoadKeyA)
		return wine_thunk_get_for_any(pextRegLoadKeyA);
	if (func == pRegLoadKeyW && func != pextRegLoadKeyW)
		return wine_thunk_get_for_any(pextRegLoadKeyW);
	if (func == pRegLoadMUIStringA && func != pextRegLoadMUIStringA)
		return wine_thunk_get_for_any(pextRegLoadMUIStringA);
	if (func == pRegLoadMUIStringW && func != pextRegLoadMUIStringW)
		return wine_thunk_get_for_any(pextRegLoadMUIStringW);
	if (func == pRegNotifyChangeKeyValue && func != pextRegNotifyChangeKeyValue)
		return wine_thunk_get_for_any(pextRegNotifyChangeKeyValue);
	if (func == pRegOpenCurrentUser && func != pextRegOpenCurrentUser)
		return wine_thunk_get_for_any(pextRegOpenCurrentUser);
	if (func == pRegOpenKeyA)
		return wine32a_advapi32_RegOpenKeyA;
	if (func == pRegOpenKeyExA && func != pextRegOpenKeyExA)
		return wine_thunk_get_for_any(pextRegOpenKeyExA);
	if (func == pRegOpenKeyExW && func != pextRegOpenKeyExW)
		return wine_thunk_get_for_any(pextRegOpenKeyExW);
	if (func == pRegOpenKeyW)
		return wine32a_advapi32_RegOpenKeyW;
	if (func == pRegOpenUserClassesRoot && func != pextRegOpenUserClassesRoot)
		return wine_thunk_get_for_any(pextRegOpenUserClassesRoot);
	if (func == pRegOverridePredefKey)
		return wine32a_advapi32_RegOverridePredefKey;
	if (func == pRegQueryInfoKeyA && func != pextRegQueryInfoKeyA)
		return wine_thunk_get_for_any(pextRegQueryInfoKeyA);
	if (func == pRegQueryInfoKeyW && func != pextRegQueryInfoKeyW)
		return wine_thunk_get_for_any(pextRegQueryInfoKeyW);
	if (func == pRegQueryMultipleValuesA)
		return wine32a_advapi32_RegQueryMultipleValuesA;
	if (func == pRegQueryMultipleValuesW)
		return wine32a_advapi32_RegQueryMultipleValuesW;
	if (func == pRegQueryReflectionKey)
		return wine32a_advapi32_RegQueryReflectionKey;
	if (func == pRegQueryValueA)
		return wine32a_advapi32_RegQueryValueA;
	if (func == pRegQueryValueExA && func != pextRegQueryValueExA)
		return wine_thunk_get_for_any(pextRegQueryValueExA);
	if (func == pRegQueryValueExW && func != pextRegQueryValueExW)
		return wine_thunk_get_for_any(pextRegQueryValueExW);
	if (func == pRegQueryValueW)
		return wine32a_advapi32_RegQueryValueW;
	if (func == pRegReplaceKeyA)
		return wine32a_advapi32_RegReplaceKeyA;
	if (func == pRegReplaceKeyW)
		return wine32a_advapi32_RegReplaceKeyW;
	if (func == pRegRestoreKeyA && func != pextRegRestoreKeyA)
		return wine_thunk_get_for_any(pextRegRestoreKeyA);
	if (func == pRegRestoreKeyW && func != pextRegRestoreKeyW)
		return wine_thunk_get_for_any(pextRegRestoreKeyW);
	if (func == pRegSaveKeyA)
		return wine32a_advapi32_RegSaveKeyA;
	if (func == pRegSaveKeyExA && func != pextRegSaveKeyExA)
		return wine_thunk_get_for_any(pextRegSaveKeyExA);
	if (func == pRegSaveKeyExW && func != pextRegSaveKeyExW)
		return wine_thunk_get_for_any(pextRegSaveKeyExW);
	if (func == pRegSaveKeyW)
		return wine32a_advapi32_RegSaveKeyW;
	if (func == pRegSetKeySecurity && func != pextRegSetKeySecurity)
		return wine_thunk_get_for_any(pextRegSetKeySecurity);
	if (func == pRegSetKeyValueA && func != pextRegSetKeyValueA)
		return wine_thunk_get_for_any(pextRegSetKeyValueA);
	if (func == pRegSetKeyValueW && func != pextRegSetKeyValueW)
		return wine_thunk_get_for_any(pextRegSetKeyValueW);
	if (func == pRegSetValueA)
		return wine32a_advapi32_RegSetValueA;
	if (func == pRegSetValueExA && func != pextRegSetValueExA)
		return wine_thunk_get_for_any(pextRegSetValueExA);
	if (func == pRegSetValueExW && func != pextRegSetValueExW)
		return wine_thunk_get_for_any(pextRegSetValueExW);
	if (func == pRegSetValueW)
		return wine32a_advapi32_RegSetValueW;
	if (func == pRegUnLoadKeyA && func != pextRegUnLoadKeyA)
		return wine_thunk_get_for_any(pextRegUnLoadKeyA);
	if (func == pRegUnLoadKeyW && func != pextRegUnLoadKeyW)
		return wine_thunk_get_for_any(pextRegUnLoadKeyW);
	if (func == pRegisterEventSourceA)
		return wine32a_advapi32_RegisterEventSourceA;
	if (func == pRegisterEventSourceW)
		return wine32a_advapi32_RegisterEventSourceW;
	if (func == pEtwRegisterTraceGuidsA && func != pextEtwRegisterTraceGuidsA)
		return wine_thunk_get_for_any(pextEtwRegisterTraceGuidsA);
	if (func == pEtwRegisterTraceGuidsW && func != pextEtwRegisterTraceGuidsW)
		return wine_thunk_get_for_any(pextEtwRegisterTraceGuidsW);
	if (func == pRegisterWaitChainCOMCallback)
		return wine32a_advapi32_RegisterWaitChainCOMCallback;
	if (func == pReportEventA)
		return wine32a_advapi32_ReportEventA;
	if (func == pReportEventW)
		return wine32a_advapi32_ReportEventW;
	if (func == pRevertToSelf && func != pextRevertToSelf)
		return wine_thunk_get_for_any(pextRevertToSelf);
	if (func == pSaferCloseLevel)
		return wine32a_advapi32_SaferCloseLevel;
	if (func == pSaferComputeTokenFromLevel)
		return wine32a_advapi32_SaferComputeTokenFromLevel;
	if (func == pSaferCreateLevel)
		return wine32a_advapi32_SaferCreateLevel;
	if (func == pSaferGetPolicyInformation)
		return wine32a_advapi32_SaferGetPolicyInformation;
	if (func == pSaferIdentifyLevel)
		return wine32a_advapi32_SaferIdentifyLevel;
	if (func == pSaferSetLevelInformation)
		return wine32a_advapi32_SaferSetLevelInformation;
	if (func == pSetAclInformation && func != pextSetAclInformation)
		return wine_thunk_get_for_any(pextSetAclInformation);
	if (func == pSetEntriesInAclA)
		return wine32a_advapi32_SetEntriesInAclA;
	if (func == pSetEntriesInAclW)
		return wine32a_advapi32_SetEntriesInAclW;
	if (func == pSetFileSecurityA)
		return wine32a_advapi32_SetFileSecurityA;
	if (func == pSetFileSecurityW && func != pextSetFileSecurityW)
		return wine_thunk_get_for_any(pextSetFileSecurityW);
	if (func == pSetKernelObjectSecurity && func != pextSetKernelObjectSecurity)
		return wine_thunk_get_for_any(pextSetKernelObjectSecurity);
	if (func == pSetNamedSecurityInfoA)
		return wine32a_advapi32_SetNamedSecurityInfoA;
	if (func == pSetNamedSecurityInfoW)
		return wine32a_advapi32_SetNamedSecurityInfoW;
	if (func == pSetPrivateObjectSecurity && func != pextSetPrivateObjectSecurity)
		return wine_thunk_get_for_any(pextSetPrivateObjectSecurity);
	if (func == pSetSecurityDescriptorControl && func != pextSetSecurityDescriptorControl)
		return wine_thunk_get_for_any(pextSetSecurityDescriptorControl);
	if (func == pSetSecurityDescriptorDacl && func != pextSetSecurityDescriptorDacl)
		return wine_thunk_get_for_any(pextSetSecurityDescriptorDacl);
	if (func == pSetSecurityDescriptorGroup && func != pextSetSecurityDescriptorGroup)
		return wine_thunk_get_for_any(pextSetSecurityDescriptorGroup);
	if (func == pSetSecurityDescriptorOwner && func != pextSetSecurityDescriptorOwner)
		return wine_thunk_get_for_any(pextSetSecurityDescriptorOwner);
	if (func == pSetSecurityDescriptorSacl && func != pextSetSecurityDescriptorSacl)
		return wine_thunk_get_for_any(pextSetSecurityDescriptorSacl);
	if (func == pSetSecurityInfo)
		return wine32a_advapi32_SetSecurityInfo;
	if (func == pSetThreadToken && func != pextSetThreadToken)
		return wine_thunk_get_for_any(pextSetThreadToken);
	if (func == pSetTokenInformation && func != pextSetTokenInformation)
		return wine_thunk_get_for_any(pextSetTokenInformation);
	if (func == pStartTraceA)
		return wine32a_advapi32_StartTraceA;
	if (func == pStartTraceW)
		return wine32a_advapi32_StartTraceW;
	if (func == pStopTraceA)
		return wine32a_advapi32_StopTraceA;
	if (func == pStopTraceW)
		return wine32a_advapi32_StopTraceW;
	if (func == pSynchronizeWindows31FilesAndWindowsNTRegistry)
		return wine32a_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry;
	if (func == pSystemFunction001)
		return wine32a_advapi32_SystemFunction001;
	if (func == pSystemFunction002)
		return wine32a_advapi32_SystemFunction002;
	if (func == pSystemFunction003)
		return wine32a_advapi32_SystemFunction003;
	if (func == pSystemFunction004)
		return wine32a_advapi32_SystemFunction004;
	if (func == pSystemFunction005)
		return wine32a_advapi32_SystemFunction005;
	if (func == pSystemFunction006)
		return wine32a_advapi32_SystemFunction006;
	if (func == pSystemFunction007)
		return wine32a_advapi32_SystemFunction007;
	if (func == pSystemFunction008)
		return wine32a_advapi32_SystemFunction008;
	if (func == pSystemFunction009)
		return wine32a_advapi32_SystemFunction009;
	if (func == pSystemFunction010)
		return wine32a_advapi32_SystemFunction010;
	if (func == pSystemFunction012)
		return wine32a_advapi32_SystemFunction012;
	if (func == pSystemFunction013)
		return wine32a_advapi32_SystemFunction013;
	if (func == pSystemFunction024)
		return wine32a_advapi32_SystemFunction024;
	if (func == pSystemFunction025)
		return wine32a_advapi32_SystemFunction025;
	if (func == pSystemFunction030)
		return wine32a_advapi32_SystemFunction030;
	if (func == pSystemFunction032)
		return wine32a_advapi32_SystemFunction032;
	if (func == pSystemFunction035)
		return wine32a_advapi32_SystemFunction035;
	if (func == pEtwLogTraceEvent && func != pextEtwLogTraceEvent)
		return wine_thunk_get_for_any(pextEtwLogTraceEvent);
	if (func == pEtwTraceMessage && func != pextEtwTraceMessage)
		return wine_thunk_get_for_any(pextEtwTraceMessage);
	if (func == pEtwTraceMessageVa && func != pextEtwTraceMessageVa)
		return wine_thunk_get_for_any(pextEtwTraceMessageVa);
	if (func == pTraceSetInformation)
		return wine32a_advapi32_TraceSetInformation;
	if (func == pTreeResetNamedSecurityInfoW)
		return wine32a_advapi32_TreeResetNamedSecurityInfoW;
	if (func == pEtwUnregisterTraceGuids && func != pextEtwUnregisterTraceGuids)
		return wine_thunk_get_for_any(pextEtwUnregisterTraceGuids);
	if (func == pWmiExecuteMethodA)
		return wine32a_advapi32_WmiExecuteMethodA;
	if (func == pWmiExecuteMethodW)
		return wine32a_advapi32_WmiExecuteMethodW;
	if (func == pWmiFreeBuffer)
		return wine32a_advapi32_WmiFreeBuffer;
	if (func == pWmiMofEnumerateResourcesA)
		return wine32a_advapi32_WmiMofEnumerateResourcesA;
	if (func == pWmiMofEnumerateResourcesW)
		return wine32a_advapi32_WmiMofEnumerateResourcesW;
	if (func == pWmiNotificationRegistrationA)
		return wine32a_advapi32_WmiNotificationRegistrationA;
	if (func == pWmiNotificationRegistrationW)
		return wine32a_advapi32_WmiNotificationRegistrationW;
	if (func == pWmiOpenBlock)
		return wine32a_advapi32_WmiOpenBlock;
	if (func == pWmiQueryAllDataA)
		return wine32a_advapi32_WmiQueryAllDataA;
	if (func == pWmiQueryAllDataW)
		return wine32a_advapi32_WmiQueryAllDataW;
	if (func == pWmiQueryGuidInformation)
		return wine32a_advapi32_WmiQueryGuidInformation;
	if (func == pWmiSetSingleInstanceA)
		return wine32a_advapi32_WmiSetSingleInstanceA;
	if (func == pWmiSetSingleInstanceW)
		return wine32a_advapi32_WmiSetSingleInstanceW;
	if (func == pWmiSetSingleItemA)
		return wine32a_advapi32_WmiSetSingleItemA;
	if (func == pWmiSetSingleItemW)
		return wine32a_advapi32_WmiSetSingleItemW;
	if (func == pWriteEncryptedFileRaw)
		return wine32a_advapi32_WriteEncryptedFileRaw;

	return NULL;
}
