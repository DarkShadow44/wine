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
struct _WMIGUIDINFORMATION; /* ../include/wmium.h:67 */

typedef unsigned long ULONG64; /* ../include/basetsd.h:99 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR DWORD_PTR; /* ../include/basetsd.h:121 */

typedef LONG NTSTATUS; /* ../include/winternl.h:38 */

typedef struct _UNICODE_STRING /* ../include/winternl.h:65 */
{
    USHORT Length;
    USHORT MaximumLength;
    PWSTR Buffer;
}  UNICODE_STRING, * PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES /* ../include/winternl.h:1205 */
{
    ULONG Length;
    HANDLE RootDirectory;
    PUNICODE_STRING ObjectName;
    ULONG Attributes;
    PVOID SecurityDescriptor;
    PVOID SecurityQualityOfService;
}  OBJECT_ATTRIBUTES, * POBJECT_ATTRIBUTES;

typedef struct _CREDENTIAL_ATTRIBUTEA /* ../include/wincred.h:47 */
{
    LPSTR Keyword;
    DWORD Flags;
    DWORD ValueSize;
    LPBYTE Value;
}  CREDENTIAL_ATTRIBUTEA, * PCREDENTIAL_ATTRIBUTEA;

typedef struct _CREDENTIAL_ATTRIBUTEW /* ../include/wincred.h:55 */
{
    LPWSTR Keyword;
    DWORD Flags;
    DWORD ValueSize;
    LPBYTE Value;
}  CREDENTIAL_ATTRIBUTEW, * PCREDENTIAL_ATTRIBUTEW;

typedef struct _CREDENTIALA /* ../include/wincred.h:66 */
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
}  CREDENTIALA, * PCREDENTIALA;

typedef struct _CREDENTIALW /* ../include/wincred.h:82 */
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
}  CREDENTIALW, * PCREDENTIALW;

typedef struct _CREDENTIAL_TARGET_INFORMATIONA /* ../include/wincred.h:101 */
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
}  CREDENTIAL_TARGET_INFORMATIONA, * PCREDENTIAL_TARGET_INFORMATIONA;

typedef struct _CREDENTIAL_TARGET_INFORMATIONW /* ../include/wincred.h:115 */
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
}  CREDENTIAL_TARGET_INFORMATIONW, * PCREDENTIAL_TARGET_INFORMATIONW;

typedef enum _CRED_MARSHAL_TYPE /* ../include/wincred.h:153 */
{
    DUMMY29 = 0
}  CRED_MARSHAL_TYPE, * PCRED_MARSHAL_TYPE;

typedef HRESULT (*PCOGETCALLSTATE) (int, PULONG); /* ../include/wct.h:22 */

typedef HRESULT (*PCOGETACTIVATIONSTATE) (GUID, DWORD, DWORD*); /* ../include/wct.h:23 */

typedef UNICODE_STRING LSA_UNICODE_STRING; /* ../include/ntsecapi.h:181 */

typedef UNICODE_STRING* PLSA_UNICODE_STRING; /* ../include/ntsecapi.h:181 */

typedef OBJECT_ATTRIBUTES* PLSA_OBJECT_ATTRIBUTES; /* ../include/ntsecapi.h:183 */

typedef PVOID LSA_HANDLE; /* ../include/ntsecapi.h:185 */

typedef PVOID* PLSA_HANDLE; /* ../include/ntsecapi.h:185 */

typedef ULONG* PLSA_ENUMERATION_HANDLE; /* ../include/ntsecapi.h:186 */

typedef enum /* ../include/ntsecapi.h:189 */
{
    DUMMY30 = 0
}  POLICY_INFORMATION_CLASS, * PPOLICY_INFORMATION_CLASS;

typedef struct /* ../include/ntsecapi.h:267 */
{
    SID_NAME_USE Use;
    LSA_UNICODE_STRING Name;
    LONG DomainIndex;
}  LSA_TRANSLATED_NAME, * PLSA_TRANSLATED_NAME;

typedef struct /* ../include/ntsecapi.h:274 */
{
    LSA_UNICODE_STRING Name;
    PSID Sid;
}  LSA_TRUST_INFORMATION, * PLSA_TRUST_INFORMATION;

typedef struct /* ../include/ntsecapi.h:280 */
{
    ULONG Entries;
    PLSA_TRUST_INFORMATION Domains;
}  LSA_REFERENCED_DOMAIN_LIST, * PLSA_REFERENCED_DOMAIN_LIST;

typedef struct _LSA_TRANSLATED_SID /* ../include/ntsecapi.h:286 */
{
    SID_NAME_USE Use;
    ULONG RelativeId;
    LONG DomainIndex;
}  LSA_TRANSLATED_SID, * PLSA_TRANSLATED_SID;

typedef struct _TRUSTED_DOMAIN_INFORMATION_EX /* ../include/ntsecapi.h:293 */
{
    LSA_UNICODE_STRING Name;
    LSA_UNICODE_STRING FlatName;
    PSID Sid;
    ULONG TrustDirection;
    ULONG TrustType;
    ULONG TrustAttributes;
}  TRUSTED_DOMAIN_INFORMATION_EX, * PTRUSTED_DOMAIN_INFORMATION_EX;

typedef struct _LSA_AUTH_INFORMATION /* ../include/ntsecapi.h:303 */
{
    LARGE_INTEGER LastUpdateTime;
    ULONG AuthType;
    ULONG AuthInfoLength;
    PUCHAR AuthInfo;
}  LSA_AUTH_INFORMATION, * PLSA_AUTH_INFORMATION;

typedef struct _TRUSTED_DOMAIN_AUTH_INFORMATION /* ../include/ntsecapi.h:311 */
{
    ULONG IncomingAuthInfos;
    PLSA_AUTH_INFORMATION IncomingAuthenticationInformation;
    PLSA_AUTH_INFORMATION IncomingPreviousAuthenticationInformation;
    ULONG OutgoingAuthInfos;
    PLSA_AUTH_INFORMATION OutgoingAuthenticationInformation;
    PLSA_AUTH_INFORMATION OutgoingPreviousAuthenticationInformation;
}  TRUSTED_DOMAIN_AUTH_INFORMATION, * PTRUSTED_DOMAIN_AUTH_INFORMATION;

typedef struct _LSA_TRANSLATED_SID2 /* ../include/ntsecapi.h:321 */
{
    SID_NAME_USE Use;
    PSID Sid;
    LONG DomainIndex;
    ULONG Flags;
}  LSA_TRANSLATED_SID2, * PLSA_TRANSLATED_SID2;

typedef enum _TRUSTED_INFORMATION_CLASS /* ../include/ntsecapi.h:329 */
{
    DUMMY31 = 0
}  TRUSTED_INFORMATION_CLASS, * PTRUSTED_INFORMATION_CLASS;

typedef enum _POLICY_NOTIFICATION_INFORMATION_CLASS /* ../include/ntsecapi.h:341 */
{
    DUMMY32 = 0
}  POLICY_NOTIFICATION_INFORMATION_CLASS, * PPOLICY_NOTIFICATION_INFORMATION_CLASS;

typedef struct _AUDIT_POLICY_INFORMATION /* ../include/ntsecapi.h:352 */
{
    GUID AuditSubCategoryGuid;
    ULONG AuditingInformation;
    GUID AuditCategoryGuid;
}  AUDIT_POLICY_INFORMATION, * PAUDIT_POLICY_INFORMATION;

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

typedef struct _WNODE_HEADER /* ../include/wmistr.h:54 */
{
    ULONG BufferSize;
    ULONG ProvicerId;
    union /* ../include/wmistr.h:58 */
    {
        ULONG64 HistoricalContext;
        struct /* ../include/wmistr.h:61 */
        {
            ULONG Version;
            ULONG Linkage;
        };

    };

    union /* ../include/wmistr.h:68 */
    {
        HANDLE KernelHandle;
        LARGE_INTEGER TimeStamp;
    };

    GUID Guid;
    ULONG ClientContext;
    ULONG Flags;
}  WNODE_HEADER, * PWNODE_HEADER;

typedef ULONG64 TRACEHANDLE; /* ../include/evntrace.h:70 */

typedef ULONG64* PTRACEHANDLE; /* ../include/evntrace.h:70 */

typedef struct _EVENT_TRACE_LOGFILEA* PEVENT_TRACE_LOGFILEA; /* ../include/evntrace.h:75 */

typedef struct _EVENT_TRACE_LOGFILEW* PEVENT_TRACE_LOGFILEW; /* ../include/evntrace.h:76 */

typedef ULONG (*PEVENT_TRACE_BUFFER_CALLBACKA) (PEVENT_TRACE_LOGFILEA); /* ../include/evntrace.h:78 */

typedef ULONG (*PEVENT_TRACE_BUFFER_CALLBACKW) (PEVENT_TRACE_LOGFILEW); /* ../include/evntrace.h:79 */

typedef struct _TRACE_GUID_PROPERTIES /* ../include/evntrace.h:89 */
{
    GUID Guid;
    ULONG GuidType;
    ULONG LoggerId;
    ULONG EnableLevel;
    ULONG EnableFlags;
    BOOLEAN IsEnable;
}  TRACE_GUID_PROPERTIES, * PTRACE_GUID_PROPERTIES;

typedef struct _EVENT_TRACE_HEADER /* ../include/evntrace.h:98 */
{
    USHORT Size;
    union /* ../include/evntrace.h:101 */
    {
        USHORT FieldTypeFlags;
        struct /* ../include/evntrace.h:104 */
        {
            UCHAR HeaderType;
            UCHAR MarkerFlags;
        };

    };

    union /* ../include/evntrace.h:110 */
    {
        ULONG Version;
        struct /* ../include/evntrace.h:113 */
        {
            UCHAR Type;
            UCHAR Level;
            USHORT Version;
        } Class;

    };

    ULONG ThreadId;
    ULONG ProcessId;
    LARGE_INTEGER TimeStamp;
    union /* ../include/evntrace.h:123 */
    {
        GUID Guid;
        ULONGLONG GuidPtr;
    };

    union /* ../include/evntrace.h:128 */
    {
        struct /* ../include/evntrace.h:130 */
        {
            ULONG ClientContext;
            ULONG Flags;
        };

        struct /* ../include/evntrace.h:135 */
        {
            ULONG KernelTime;
            ULONG UserTime;
        };

    };

}  EVENT_TRACE_HEADER, * PEVENT_TRACE_HEADER;

typedef struct _EVENT_TRACE /* ../include/evntrace.h:143 */
{
    EVENT_TRACE_HEADER Header;
    ULONG InstanceId;
    ULONG ParentInstanceId;
    GUID ParentGuid;
    PVOID MofData;
    ULONG MofLength;
    ULONG ClientContext;
}  EVENT_TRACE, * PEVENT_TRACE;

typedef void (*PEVENT_CALLBACK) (PEVENT_TRACE); /* ../include/evntrace.h:154 */

typedef struct _TRACE_LOGFILE_HEADER /* ../include/evntrace.h:156 */
{
    ULONG BufferSize;
    union /* ../include/evntrace.h:159 */
    {
        ULONG Version;
        struct /* ../include/evntrace.h:162 */
        {
            UCHAR MajorVersion;
            UCHAR MinorVersion;
            UCHAR SubVersion;
            UCHAR SubMinorVersion;
        } VersionDetail;

    };

    ULONG ProviderVersion;
    ULONG NumberOfProcessors;
    LARGE_INTEGER EndTime;
    ULONG TimerResolution;
    ULONG MaximumFileSize;
    ULONG LogFileMode;
    ULONG BuffersWritten;
    union /* ../include/evntrace.h:177 */
    {
        GUID LogInstanceGuid;
        struct /* ../include/evntrace.h:180 */
        {
            ULONG StartBuffers;
            ULONG PointerSize;
            ULONG EventsLost;
            ULONG CpuSpeedInMHZ;
        };

    };

    LPWSTR LoggerName;
    LPWSTR LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
    LARGE_INTEGER BootTime;
    LARGE_INTEGER PerfFreq;
    LARGE_INTEGER StartTime;
    ULONG ReservedTime;
    ULONG BuffersLost;
}  TRACE_LOGFILE_HEADER, * PTRACE_LOGFILE_HEADER;

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

typedef struct _EVENT_TRACE_PROPERTIES /* ../include/evntrace.h:230 */
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
}  EVENT_TRACE_PROPERTIES, * PEVENT_TRACE_PROPERTIES;

typedef struct _ENABLE_TRACE_PARAMETERS /* ../include/evntrace.h:252 */
{
    ULONG Version;
    ULONG EnableProperty;
    ULONG ControlFlags;
    GUID SourceId;
    struct _EVENT_FILTER_DESCRIPTOR* EnableFilterDesc;
    ULONG FilterDescCount;
}  ENABLE_TRACE_PARAMETERS, * PENABLE_TRACE_PARAMETERS;

typedef enum _TRACE_QUERY_INFO_CLASS /* ../include/evntrace.h:262 */
{
    DUMMY33 = 0
}  TRACE_QUERY_INFO_CLASS,  TRACE_INFO_CLASS;

typedef struct _EVENT_FILTER_DESCRIPTOR /* ../include/evntprov.h:52 */
{
    ULONGLONG Ptr;
    ULONG Size;
    ULONG Type;
}  EVENT_FILTER_DESCRIPTOR, * PEVENT_FILTER_DESCRIPTOR;

typedef struct SAFER_LEVEL_HANDLE__ /* ../include/winsafer.h:31 */
{
    int unused;
} * SAFER_LEVEL_HANDLE;

typedef struct _SAFER_CODE_PROPERTIES_V2 /* ../include/winsafer.h:41 */
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
}  SAFER_CODE_PROPERTIES_V2, * PSAFER_CODE_PROPERTIES_V2;

typedef SAFER_CODE_PROPERTIES_V2 SAFER_CODE_PROPERTIES; /* ../include/winsafer.h:61 */

typedef enum _SAFER_POLICY_INFO_CLASS /* ../include/winsafer.h:75 */
{
    DUMMY34 = 0
}  SAFER_POLICY_INFO_CLASS;

typedef enum _SAFER_OBJECT_INFO_CLASS /* ../include/winsafer.h:83 */
{
    DUMMY35 = 0
}  SAFER_OBJECT_INFO_CLASS;

typedef enum _SE_OBJECT_TYPE /* ../include/accctrl.h:28 */
{
    DUMMY36 = 0
}  SE_OBJECT_TYPE;

typedef enum _TRUSTEE_TYPE /* ../include/accctrl.h:45 */
{
    DUMMY37 = 0
}  TRUSTEE_TYPE;

typedef enum _TRUSTEE_FORM /* ../include/accctrl.h:58 */
{
    DUMMY38 = 0
}  TRUSTEE_FORM;

typedef enum _MULTIPLE_TRUSTEE_OPERATION /* ../include/accctrl.h:67 */
{
    DUMMY39 = 0
}  MULTIPLE_TRUSTEE_OPERATION;

typedef struct _OBJECTS_AND_SID /* ../include/accctrl.h:73 */
{
    DWORD ObjectsPresent;
    GUID ObjectTypeGuid;
    GUID InheritedObjectTypeGuid;
    SID* pSid;
}  OBJECTS_AND_SID, * POBJECTS_AND_SID;

typedef struct _OBJECTS_AND_NAME_A /* ../include/accctrl.h:81 */
{
    DWORD ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    LPSTR ObjectTypeName;
    LPSTR InheritedObjectTypeName;
    LPSTR ptstrName;
}  OBJECTS_AND_NAME_A, * POBJECTS_AND_NAME_A;

typedef struct _OBJECTS_AND_NAME_W /* ../include/accctrl.h:90 */
{
    DWORD ObjectsPresent;
    SE_OBJECT_TYPE ObjectType;
    LPWSTR ObjectTypeName;
    LPWSTR InheritedObjectTypeName;
    LPWSTR ptstrName;
}  OBJECTS_AND_NAME_W, * POBJECTS_AND_NAME_W;

typedef struct _TRUSTEE_A /* ../include/accctrl.h:102 */
{
    struct _TRUSTEE_A* pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    LPSTR ptstrName;
}  TRUSTEE_A, * PTRUSTEE_A,  TRUSTEEA, * PTRUSTEEA;

typedef struct _TRUSTEE_W /* ../include/accctrl.h:111 */
{
    struct _TRUSTEE_W* pMultipleTrustee;
    MULTIPLE_TRUSTEE_OPERATION MultipleTrusteeOperation;
    TRUSTEE_FORM TrusteeForm;
    TRUSTEE_TYPE TrusteeType;
    LPWSTR ptstrName;
}  TRUSTEE_W, * PTRUSTEE_W,  TRUSTEEW, * PTRUSTEEW;

typedef enum _ACCESS_MODE /* ../include/accctrl.h:125 */
{
    DUMMY40 = 0
}  ACCESS_MODE;

typedef struct _EXPLICIT_ACCESS_A /* ../include/accctrl.h:146 */
{
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_A Trustee;
}  EXPLICIT_ACCESS_A, * PEXPLICIT_ACCESS_A,  EXPLICIT_ACCESSA, * PEXPLICIT_ACCESSA;

typedef struct _EXPLICIT_ACCESS_W /* ../include/accctrl.h:154 */
{
    DWORD grfAccessPermissions;
    ACCESS_MODE grfAccessMode;
    DWORD grfInheritance;
    TRUSTEE_W Trustee;
}  EXPLICIT_ACCESS_W, * PEXPLICIT_ACCESS_W,  EXPLICIT_ACCESSW, * PEXPLICIT_ACCESSW;

typedef ULONG ACCESS_RIGHTS; /* ../include/accctrl.h:167 */

typedef ULONG INHERIT_FLAGS; /* ../include/accctrl.h:168 */

typedef struct _ACTRL_ACCESS_ENTRYA /* ../include/accctrl.h:170 */
{
    TRUSTEE_A Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPSTR lpInheritProperty;
}  ACTRL_ACCESS_ENTRYA, * PACTRL_ACCESS_ENTRYA;

typedef struct _ACTRL_ACCESS_ENTRYW /* ../include/accctrl.h:180 */
{
    TRUSTEE_W Trustee;
    ULONG fAccessFlags;
    ACCESS_RIGHTS Access;
    ACCESS_RIGHTS ProvSpecificAccess;
    INHERIT_FLAGS Inheritance;
    LPWSTR lpInheritProperty;
}  ACTRL_ACCESS_ENTRYW, * PACTRL_ACCESS_ENTRYW;

typedef struct _ACTRL_ACCESS_ENTRY_LISTA /* ../include/accctrl.h:194 */
{
    ULONG cEntries;
    ACTRL_ACCESS_ENTRYA* pAccessList;
}  ACTRL_ACCESS_ENTRY_LISTA, * PACTRL_ACCESS_ENTRY_LISTA;

typedef struct _ACTRL_ACCESS_ENTRY_LISTW /* ../include/accctrl.h:200 */
{
    ULONG cEntries;
    ACTRL_ACCESS_ENTRYW* pAccessList;
}  ACTRL_ACCESS_ENTRY_LISTW, * PACTRL_ACCESS_ENTRY_LISTW;

typedef struct _ACTRL_PROPERTY_ENTRYA /* ../include/accctrl.h:209 */
{
    LPSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTA pAccessEntryList;
    ULONG fListFlags;
}  ACTRL_PROPERTY_ENTRYA, * PACTRL_PROPERTY_ENTRYA;

typedef struct _ACTRL_PROPERTY_ENTRYW /* ../include/accctrl.h:216 */
{
    LPWSTR lpProperty;
    PACTRL_ACCESS_ENTRY_LISTW pAccessEntryList;
    ULONG fListFlags;
}  ACTRL_PROPERTY_ENTRYW, * PACTRL_PROPERTY_ENTRYW;

typedef struct _ACTRL_ALISTA /* ../include/accctrl.h:226 */
{
    ULONG cEntries;
    PACTRL_PROPERTY_ENTRYA pPropertyAccessList;
}  ACTRL_ACCESSA, * PACTRL_ACCESSA,  ACTRL_AUDITA, * PACTRL_AUDITA;

typedef struct _ACTRL_ALISTW /* ../include/accctrl.h:232 */
{
    ULONG cEntries;
    PACTRL_PROPERTY_ENTRYW pPropertyAccessList;
}  ACTRL_ACCESSW, * PACTRL_ACCESSW,  ACTRL_AUDITW, * PACTRL_AUDITW;

typedef enum _PROGRESS_INVOKE_SETTING /* ../include/accctrl.h:422 */
{
    DUMMY41 = 0
}  PROG_INVOKE_SETTING, * PPROG_INVOKE_SETTING;

typedef void (*FN_PROGRESS) (LPWSTR, DWORD, PPROG_INVOKE_SETTING, PVOID, BOOL); /* ../include/aclapi.h:29 */

typedef PVOID WMIHANDLE; /* ../include/wmium.h:32 */

typedef PVOID MOFHANDLE; /* ../include/wmium.h:32 */

typedef struct /* ../include/wmium.h:38 */
{
    char* ImagePath;
    char* ResourceName;
    ULONG ResourceSize;
    UCHAR* ResourceBuffer;
}  MOFRESOURCEINFOA, * PMOFRESOURCEINFOA;

typedef struct /* ../include/wmium.h:46 */
{
    WCHAR* ImagePath;
    WCHAR* ResourceName;
    ULONG ResourceSize;
    UCHAR* ResourceBuffer;
}  MOFRESOURCEINFOW, * PMOFRESOURCEINFOW;

typedef struct _WMIGUIDINFORMATION /* ../include/wmium.h:67 */
{
    ULONG Size;
    BOOLEAN IsExpensive;
    BOOLEAN IsEventOnly;
}  WMIGUIDINFORMATION, * PWMIGUIDINFORMATION;

static WINAPI BOOL (*pAbortSystemShutdownA)(LPSTR lpMachineName);
static WINAPI BOOL (*pAbortSystemShutdownW)(LPWSTR lpMachineName);
static WINAPI BOOL (*pAccessCheckAndAuditAlarmA)(LPCSTR Subsystem, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose);
static WINAPI BOOLEAN (*pAuditQuerySystemPolicy)(GUID* guids, ULONG count, AUDIT_POLICY_INFORMATION** policy);
static WINAPI BOOL (*pBackupEventLogA)(HANDLE hEventLog, LPCSTR lpBackupFileName);
static WINAPI BOOL (*pBackupEventLogW)(HANDLE hEventLog, LPCWSTR lpBackupFileName);
static WINAPI void (*pBuildExplicitAccessWithNameA)(PEXPLICIT_ACCESSA pExplicitAccess, LPSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance);
static WINAPI void (*pBuildExplicitAccessWithNameW)(PEXPLICIT_ACCESSW pExplicitAccess, LPWSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance);
static WINAPI DWORD (*pBuildSecurityDescriptorA)(PTRUSTEEA pOwner, PTRUSTEEA pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSA pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSA pListofAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR* pNewSD);
static WINAPI DWORD (*pBuildSecurityDescriptorW)(PTRUSTEEW pOwner, PTRUSTEEW pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSW pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSW pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR* pNewSD);
static WINAPI void (*pBuildTrusteeWithNameA)(PTRUSTEEA pTrustee, LPSTR name);
static WINAPI void (*pBuildTrusteeWithNameW)(PTRUSTEEW pTrustee, LPWSTR name);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameA)(PTRUSTEEA pTrustee, POBJECTS_AND_NAME_A pObjName, SE_OBJECT_TYPE ObjectType, LPSTR ObjectTypeName, LPSTR InheritedObjectTypeName, LPSTR Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndNameW)(PTRUSTEEW pTrustee, POBJECTS_AND_NAME_W pObjName, SE_OBJECT_TYPE ObjectType, LPWSTR ObjectTypeName, LPWSTR InheritedObjectTypeName, LPWSTR Name);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidA)(PTRUSTEEA pTrustee, POBJECTS_AND_SID pObjSid, GUID* pObjectGuid, GUID* pInheritedObjectGuid, PSID pSid);
static WINAPI void (*pBuildTrusteeWithObjectsAndSidW)(PTRUSTEEW pTrustee, POBJECTS_AND_SID pObjSid, GUID* pObjectGuid, GUID* pInheritedObjectGuid, PSID pSid);
static WINAPI void (*pBuildTrusteeWithSidA)(PTRUSTEEA pTrustee, PSID pSid);
static WINAPI void (*pBuildTrusteeWithSidW)(PTRUSTEEW pTrustee, PSID pSid);
static WINAPI BOOL (*pClearEventLogA)(HANDLE hEventLog, LPCSTR lpBackupFileName);
static WINAPI BOOL (*pClearEventLogW)(HANDLE hEventLog, LPCWSTR lpBackupFileName);
static WINAPI void (*pCloseEncryptedFileRaw)(PVOID context);
static WINAPI BOOL (*pCloseEventLog)(HANDLE hEventLog);
static WINAPI ULONG (*pCloseTrace)(TRACEHANDLE handle);
static WINAPI DWORD (*pCommandLineFromMsiDescriptor)(WCHAR* szDescriptor, WCHAR* szCommandLine, DWORD* pcchCommandLine);
static WINAPI ULONG (*pControlTraceA)(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control);
static WINAPI ULONG (*pControlTraceW)(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorA)(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION Information, LPSTR* OutputString, PULONG OutputLen);
static WINAPI BOOL (*pConvertSecurityDescriptorToStringSecurityDescriptorW)(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION RequestedInformation, LPWSTR* OutputString, PULONG OutputLen);
static WINAPI BOOL (*pConvertSidToStringSidA)(PSID pSid, LPSTR* pstr);
static WINAPI BOOL (*pConvertSidToStringSidW)(PSID pSid, LPWSTR* pstr);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorA)(LPCSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR* SecurityDescriptor, PULONG SecurityDescriptorSize);
static WINAPI BOOL (*pConvertStringSecurityDescriptorToSecurityDescriptorW)(LPCWSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR* SecurityDescriptor, PULONG SecurityDescriptorSize);
static WINAPI BOOL (*pConvertStringSidToSidA)(LPCSTR StringSid, PSID* Sid);
static WINAPI BOOL (*pConvertStringSidToSidW)(LPCWSTR StringSid, PSID* Sid);
static WINAPI BOOL (*pCreateProcessWithLogonW)(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation);
static WINAPI BOOL (*pCreateProcessWithTokenW)(HANDLE token, DWORD logon_flags, LPCWSTR application_name, LPWSTR command_line, DWORD creation_flags, void* environment, LPCWSTR current_directory, STARTUPINFOW* startup_info, PROCESS_INFORMATION* process_information);
static WINAPI BOOL (*pCredDeleteA)(LPCSTR TargetName, DWORD Type, DWORD Flags);
static WINAPI BOOL (*pCredDeleteW)(LPCWSTR TargetName, DWORD Type, DWORD Flags);
static WINAPI BOOL (*pCredEnumerateA)(LPCSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIALA** Credentials);
static WINAPI BOOL (*pCredEnumerateW)(LPCWSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIALW** Credentials);
static WINAPI void (*pCredFree)(PVOID Buffer);
static WINAPI BOOL (*pCredGetSessionTypes)(DWORD persistCount, LPDWORD persists);
static WINAPI BOOL (*pCredIsMarshaledCredentialA)(LPCSTR name);
static WINAPI BOOL (*pCredIsMarshaledCredentialW)(LPCWSTR name);
static WINAPI BOOL (*pCredMarshalCredentialA)(CRED_MARSHAL_TYPE type, PVOID cred, LPSTR* out);
static WINAPI BOOL (*pCredMarshalCredentialW)(CRED_MARSHAL_TYPE type, PVOID cred, LPWSTR* out);
static WINAPI BOOL (*pCredReadA)(LPCSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALA* Credential);
static WINAPI BOOL (*pCredReadDomainCredentialsA)(PCREDENTIAL_TARGET_INFORMATIONA TargetInformation, DWORD Flags, DWORD* Size, PCREDENTIALA** Credentials);
static WINAPI BOOL (*pCredReadDomainCredentialsW)(PCREDENTIAL_TARGET_INFORMATIONW TargetInformation, DWORD Flags, DWORD* Size, PCREDENTIALW** Credentials);
static WINAPI BOOL (*pCredReadW)(LPCWSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALW* Credential);
static WINAPI BOOL (*pCredUnmarshalCredentialA)(LPCSTR cred, PCRED_MARSHAL_TYPE type, PVOID* out);
static WINAPI BOOL (*pCredUnmarshalCredentialW)(LPCWSTR cred, PCRED_MARSHAL_TYPE type, PVOID* out);
static WINAPI BOOL (*pCredWriteA)(PCREDENTIALA Credential, DWORD Flags);
static WINAPI BOOL (*pCredWriteW)(PCREDENTIALW Credential, DWORD Flags);
static WINAPI BOOL (*pCryptAcquireContextA)(HCRYPTPROV* phProv, LPCSTR pszContainer, LPCSTR pszProvider, DWORD dwProvType, DWORD dwFlags);
static WINAPI BOOL (*pCryptAcquireContextW)(HCRYPTPROV* phProv, LPCWSTR pszContainer, LPCWSTR pszProvider, DWORD dwProvType, DWORD dwFlags);
static WINAPI BOOL (*pCryptContextAddRef)(HCRYPTPROV hProv, DWORD* pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptCreateHash)(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH* phHash);
static WINAPI BOOL (*pCryptDecrypt)(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen);
static WINAPI BOOL (*pCryptDeriveKey)(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY* phKey);
static WINAPI BOOL (*pCryptDestroyHash)(HCRYPTHASH hHash);
static WINAPI BOOL (*pCryptDestroyKey)(HCRYPTKEY hKey);
static WINAPI BOOL (*pCryptDuplicateHash)(HCRYPTHASH hHash, DWORD* pdwReserved, DWORD dwFlags, HCRYPTHASH* phHash);
static WINAPI BOOL (*pCryptDuplicateKey)(HCRYPTKEY hKey, DWORD* pdwReserved, DWORD dwFlags, HCRYPTKEY* phKey);
static WINAPI BOOL (*pCryptEncrypt)(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen, DWORD dwBufLen);
static WINAPI BOOL (*pCryptEnumProviderTypesA)(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPSTR pszTypeName, DWORD* pcbTypeName);
static WINAPI BOOL (*pCryptEnumProviderTypesW)(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPWSTR pszTypeName, DWORD* pcbTypeName);
static WINAPI BOOL (*pCryptEnumProvidersA)(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPSTR pszProvName, DWORD* pcbProvName);
static WINAPI BOOL (*pCryptEnumProvidersW)(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPWSTR pszProvName, DWORD* pcbProvName);
static WINAPI BOOL (*pCryptExportKey)(HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen);
static WINAPI BOOL (*pCryptGenKey)(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY* phKey);
static WINAPI BOOL (*pCryptGenRandom)(HCRYPTPROV hProv, DWORD dwLen, BYTE* pbBuffer);
static WINAPI BOOL (*pCryptGetDefaultProviderA)(DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags, LPSTR pszProvName, DWORD* pcbProvName);
static WINAPI BOOL (*pCryptGetDefaultProviderW)(DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD* pcbProvName);
static WINAPI BOOL (*pCryptGetHashParam)(HCRYPTHASH hHash, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetKeyParam)(HCRYPTKEY hKey, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetProvParam)(HCRYPTPROV hProv, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptGetUserKey)(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY* phUserKey);
static WINAPI BOOL (*pCryptHashData)(HCRYPTHASH hHash, BYTE* pbData, DWORD dwDataLen, DWORD dwFlags);
static WINAPI BOOL (*pCryptHashSessionKey)(HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags);
static WINAPI BOOL (*pCryptImportKey)(HCRYPTPROV hProv, BYTE* pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY* phKey);
static WINAPI BOOL (*pCryptReleaseContext)(HCRYPTPROV hProv, ULONG_PTR dwFlags);
static WINAPI BOOL (*pCryptSetHashParam)(HCRYPTHASH hHash, DWORD dwParam, BYTE* pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetKeyParam)(HCRYPTKEY hKey, DWORD dwParam, BYTE* pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProvParam)(HCRYPTPROV hProv, DWORD dwParam, BYTE* pbData, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProviderA)(LPCSTR pszProvName, DWORD dwProvType);
static WINAPI BOOL (*pCryptSetProviderExA)(LPCSTR pszProvName, DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProviderExW)(LPCWSTR pszProvName, DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags);
static WINAPI BOOL (*pCryptSetProviderW)(LPCWSTR pszProvName, DWORD dwProvType);
static WINAPI BOOL (*pCryptSignHashA)(HCRYPTHASH hHash, DWORD dwKeySpec, LPCSTR sDescription, DWORD dwFlags, BYTE* pbSignature, DWORD* pdwSigLen);
static WINAPI BOOL (*pCryptSignHashW)(HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE* pbSignature, DWORD* pdwSigLen);
static WINAPI BOOL (*pCryptVerifySignatureA)(HCRYPTHASH hHash, BYTE* pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR sDescription, DWORD dwFlags);
static WINAPI BOOL (*pCryptVerifySignatureW)(HCRYPTHASH hHash, BYTE* pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags);
static WINAPI BOOL (*pDecryptFileA)(LPCSTR lpFileName, DWORD dwReserved);
static WINAPI BOOL (*pDecryptFileW)(LPCWSTR lpFileName, DWORD dwReserved);
static WINAPI BOOL (*pDeregisterEventSource)(HANDLE hEventLog);
static WINAPI ULONG (*pEnableTrace)(ULONG enable, ULONG flag, ULONG level, LPCGUID guid, TRACEHANDLE hSession);
static WINAPI ULONG (*pEnableTraceEx)(LPCGUID provider, LPCGUID source, TRACEHANDLE hSession, ULONG enable, UCHAR level, ULONGLONG anykeyword, ULONGLONG allkeyword, ULONG enableprop, PEVENT_FILTER_DESCRIPTOR filterdesc);
static WINAPI ULONG (*pEnableTraceEx2)(TRACEHANDLE handle, LPCGUID provider, ULONG control, UCHAR level, ULONGLONG match_any, ULONGLONG match_all, ULONG timeout, PENABLE_TRACE_PARAMETERS params);
static WINAPI BOOL (*pEncryptFileA)(LPCSTR lpFileName);
static WINAPI BOOL (*pEncryptFileW)(LPCWSTR lpFileName);
static WINAPI ULONG (*pEnumerateTraceGuids)(PTRACE_GUID_PROPERTIES* propertiesarray, ULONG arraycount, PULONG guidcount);
static WINAPI BOOL (*pFileEncryptionStatusA)(LPCSTR lpFileName, LPDWORD lpStatus);
static WINAPI BOOL (*pFileEncryptionStatusW)(LPCWSTR lpFileName, LPDWORD lpStatus);
static WINAPI ULONG (*pFlushTraceA)(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pFlushTraceW)(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI DWORD (*pGetAuditedPermissionsFromAclA)(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights);
static WINAPI DWORD (*pGetAuditedPermissionsFromAclW)(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights);
static WINAPI BOOL (*pGetCurrentHwProfileA)(LPHW_PROFILE_INFOA pInfo);
static WINAPI BOOL (*pGetCurrentHwProfileW)(LPHW_PROFILE_INFOW pInfo);
static WINAPI DWORD (*pGetEffectiveRightsFromAclA)(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pAccessRights);
static WINAPI DWORD (*pGetEffectiveRightsFromAclW)(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pAccessRights);
static WINAPI BOOL (*pGetEventLogInformation)(HANDLE hEventLog, DWORD dwInfoLevel, LPVOID lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded);
static WINAPI DWORD (*pGetExplicitEntriesFromAclA)(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESSA* pListOfExplicitEntries);
static WINAPI DWORD (*pGetExplicitEntriesFromAclW)(PACL pacl, PULONG count, PEXPLICIT_ACCESSW* list);
static WINAPI BOOL (*pGetFileSecurityA)(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded);
static WINAPI DWORD (*pGetNamedSecurityInfoA)(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID* ppsidOwner, PSID* ppsidGroup, PACL* ppDacl, PACL* ppSacl, PSECURITY_DESCRIPTOR* ppSecurityDescriptor);
static WINAPI DWORD (*pGetNamedSecurityInfoExA)(LPCSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCSTR provider, LPCSTR property, PACTRL_ACCESSA* access_list, PACTRL_AUDITA* audit_list, LPSTR* owner, LPSTR* group);
static WINAPI DWORD (*pGetNamedSecurityInfoExW)(LPCWSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCWSTR provider, LPCWSTR property, PACTRL_ACCESSW* access_list, PACTRL_AUDITW* audit_list, LPWSTR* owner, LPWSTR* group);
static WINAPI DWORD (*pGetNamedSecurityInfoW)(LPWSTR name, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, PSID* owner, PSID* group, PACL* dacl, PACL* sacl, PSECURITY_DESCRIPTOR* descriptor);
static WINAPI BOOL (*pGetNumberOfEventLogRecords)(HANDLE hEventLog, PDWORD NumberOfRecords);
static WINAPI BOOL (*pGetOldestEventLogRecord)(HANDLE hEventLog, PDWORD OldestRecord);
static WINAPI DWORD (*pGetSecurityInfo)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID* ppsidOwner, PSID* ppsidGroup, PACL* ppDacl, PACL* ppSacl, PSECURITY_DESCRIPTOR* ppSecurityDescriptor);
static WINAPI DWORD (*pGetSecurityInfoExA)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCSTR lpProvider, LPCSTR lpProperty, PACTRL_ACCESSA* ppAccessList, PACTRL_AUDITA* ppAuditList, LPSTR* lppOwner, LPSTR* lppGroup);
static WINAPI DWORD (*pGetSecurityInfoExW)(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCWSTR lpProvider, LPCWSTR lpProperty, PACTRL_ACCESSW* ppAccessList, PACTRL_AUDITW* ppAuditList, LPWSTR* lppOwner, LPWSTR* lppGroup);
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormA)(PTRUSTEEA pTrustee);
static WINAPI TRUSTEE_FORM (*pGetTrusteeFormW)(PTRUSTEEW pTrustee);
static WINAPI LPSTR (*pGetTrusteeNameA)(PTRUSTEEA pTrustee);
static WINAPI LPWSTR (*pGetTrusteeNameW)(PTRUSTEEW pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeA)(PTRUSTEEA pTrustee);
static WINAPI TRUSTEE_TYPE (*pGetTrusteeTypeW)(PTRUSTEEW pTrustee);
static WINAPI BOOL (*pGetUserNameA)(LPSTR lpszName, LPDWORD lpSize);
static WINAPI BOOL (*pGetUserNameW)(LPWSTR lpszName, LPDWORD lpSize);
static WINAPI DWORD (*pInitiateShutdownA)(char* name, char* message, DWORD seconds, DWORD flags, DWORD reason);
static WINAPI DWORD (*pInitiateShutdownW)(WCHAR* name, WCHAR* message, DWORD seconds, DWORD flags, DWORD reason);
static WINAPI BOOL (*pInitiateSystemShutdownA)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
static WINAPI BOOL (*pInitiateSystemShutdownExA)(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownExW)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason);
static WINAPI BOOL (*pInitiateSystemShutdownW)(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown);
static WINAPI BOOL (*pIsTextUnicode)(LPCVOID buf, INT len, LPINT flags);
static WINAPI BOOL (*pLogonUserA)(LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken);
static WINAPI BOOL (*pLogonUserW)(LPCWSTR lpszUsername, LPCWSTR lpszDomain, LPCWSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken);
static WINAPI BOOL (*pLookupAccountNameA)(LPCSTR system, LPCSTR account, PSID sid, LPDWORD cbSid, LPSTR ReferencedDomainName, LPDWORD cbReferencedDomainName, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountNameW)(LPCWSTR lpSystemName, LPCWSTR lpAccountName, PSID Sid, LPDWORD cbSid, LPWSTR ReferencedDomainName, LPDWORD cchReferencedDomainName, PSID_NAME_USE peUse);
static WINAPI BOOL (*pLookupAccountSidA)(LPCSTR system, PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidLocalA)(PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidLocalW)(PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupAccountSidW)(LPCWSTR system, PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameA)(LPCSTR lpSystemName, LPCSTR lpName, LPSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeDisplayNameW)(LPCWSTR lpSystemName, LPCWSTR lpName, LPWSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId);
static WINAPI BOOL (*pLookupPrivilegeNameA)(LPCSTR lpSystemName, PLUID lpLuid, LPSTR lpName, LPDWORD cchName);
static WINAPI BOOL (*pLookupPrivilegeNameW)(LPCWSTR lpSystemName, PLUID lpLuid, LPWSTR lpName, LPDWORD cchName);
static WINAPI BOOL (*pLookupPrivilegeValueA)(LPCSTR lpSystemName, LPCSTR lpName, PLUID lpLuid);
static WINAPI BOOL (*pLookupPrivilegeValueW)(LPCWSTR lpSystemName, LPCWSTR lpName, PLUID lpLuid);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsA)(TRUSTEEA* owner, TRUSTEEA* group, ULONG* access_count, EXPLICIT_ACCESSA* access_list, ULONG* audit_count, EXPLICIT_ACCESSA* audit_list, SECURITY_DESCRIPTOR* descriptor);
static WINAPI DWORD (*pLookupSecurityDescriptorPartsW)(TRUSTEEW* owner, TRUSTEEW* group, ULONG* access_count, EXPLICIT_ACCESSW* access_list, ULONG* audit_count, EXPLICIT_ACCESSW* audit_list, SECURITY_DESCRIPTOR* descriptor);
static WINAPI NTSTATUS (*pLsaAddAccountRights)(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING rights, ULONG count);
static WINAPI NTSTATUS (*pLsaClose)(LSA_HANDLE ObjectHandle);
static WINAPI NTSTATUS (*pLsaCreateTrustedDomainEx)(LSA_HANDLE policy, PTRUSTED_DOMAIN_INFORMATION_EX domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION auth_info, ACCESS_MASK access, PLSA_HANDLE domain);
static WINAPI NTSTATUS (*pLsaDeleteTrustedDomain)(LSA_HANDLE policy, PSID sid);
static WINAPI NTSTATUS (*pLsaEnumerateAccountRights)(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING* rights, PULONG count);
static WINAPI NTSTATUS (*pLsaEnumerateAccountsWithUserRight)(LSA_HANDLE policy, PLSA_UNICODE_STRING rights, PVOID* buffer, PULONG count);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomains)(LSA_HANDLE PolicyHandle, PLSA_ENUMERATION_HANDLE EnumerationContext, PVOID* Buffer, ULONG PreferredMaximumLength, PULONG CountReturned);
static WINAPI NTSTATUS (*pLsaEnumerateTrustedDomainsEx)(LSA_HANDLE policy, PLSA_ENUMERATION_HANDLE context, PVOID* buffer, ULONG length, PULONG count);
static WINAPI NTSTATUS (*pLsaFreeMemory)(PVOID Buffer);
static WINAPI NTSTATUS (*pLsaLookupNames)(LSA_HANDLE PolicyHandle, ULONG Count, PLSA_UNICODE_STRING Names, PLSA_REFERENCED_DOMAIN_LIST* ReferencedDomains, PLSA_TRANSLATED_SID* Sids);
static WINAPI NTSTATUS (*pLsaLookupNames2)(LSA_HANDLE policy, ULONG flags, ULONG count, PLSA_UNICODE_STRING names, PLSA_REFERENCED_DOMAIN_LIST* domains, PLSA_TRANSLATED_SID2* sids);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeDisplayName)(LSA_HANDLE handle, LSA_UNICODE_STRING* name, LSA_UNICODE_STRING** display_name, SHORT* language);
static WINAPI NTSTATUS (*pLsaLookupPrivilegeName)(LSA_HANDLE handle, LUID* luid, LSA_UNICODE_STRING** name);
static WINAPI NTSTATUS (*pLsaLookupSids)(LSA_HANDLE PolicyHandle, ULONG Count, PSID* Sids, LSA_REFERENCED_DOMAIN_LIST** ReferencedDomains, LSA_TRANSLATED_NAME** Names);
static WINAPI ULONG (*pLsaNtStatusToWinError)(NTSTATUS Status);
static WINAPI NTSTATUS (*pLsaOpenPolicy)(PLSA_UNICODE_STRING SystemName, PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle);
static WINAPI NTSTATUS (*pLsaOpenTrustedDomainByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, ACCESS_MASK access, PLSA_HANDLE handle);
static WINAPI NTSTATUS (*pLsaQueryInformationPolicy)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID* Buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfo)(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID* buffer);
static WINAPI NTSTATUS (*pLsaQueryTrustedDomainInfoByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID* buffer);
static WINAPI NTSTATUS (*pLsaRegisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event);
static WINAPI NTSTATUS (*pLsaRemoveAccountRights)(LSA_HANDLE policy, PSID sid, BOOLEAN all, PLSA_UNICODE_STRING rights, ULONG count);
static WINAPI NTSTATUS (*pLsaRetrievePrivateData)(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING* PrivateData);
static WINAPI NTSTATUS (*pLsaSetInformationPolicy)(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID Buffer);
static WINAPI NTSTATUS (*pLsaSetSecret)(LSA_HANDLE SecretHandle, PLSA_UNICODE_STRING EncryptedCurrentValue, PLSA_UNICODE_STRING EncryptedOldValue);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInfoByName)(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID buffer);
static WINAPI NTSTATUS (*pLsaSetTrustedDomainInformation)(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID buffer);
static WINAPI NTSTATUS (*pLsaStorePrivateData)(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING PrivateData);
static WINAPI NTSTATUS (*pLsaUnregisterPolicyChangeNotification)(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event);
static WINAPI BOOL (*pNotifyBootConfigStatus)(BOOL x1);
static WINAPI BOOL (*pNotifyChangeEventLog)(HANDLE hEventLog, HANDLE hEvent);
static WINAPI BOOL (*pObjectCloseAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose);
static WINAPI BOOL (*pObjectOpenAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose);
static WINAPI BOOL (*pObjectPrivilegeAuditAlarmA)(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted);
static WINAPI HANDLE (*pOpenBackupEventLogA)(LPCSTR lpUNCServerName, LPCSTR lpFileName);
static WINAPI HANDLE (*pOpenBackupEventLogW)(LPCWSTR lpUNCServerName, LPCWSTR lpFileName);
static WINAPI DWORD (*pOpenEncryptedFileRawA)(LPCSTR filename, ULONG flags, PVOID* context);
static WINAPI DWORD (*pOpenEncryptedFileRawW)(LPCWSTR filename, ULONG flags, PVOID* context);
static WINAPI HANDLE (*pOpenEventLogA)(LPCSTR uncname, LPCSTR source);
static WINAPI HANDLE (*pOpenEventLogW)(LPCWSTR uncname, LPCWSTR source);
static WINAPI TRACEHANDLE (*pOpenTraceA)(PEVENT_TRACE_LOGFILEA logfile);
static WINAPI TRACEHANDLE (*pOpenTraceW)(PEVENT_TRACE_LOGFILEW logfile);
static WINAPI BOOL (*pPrivilegedServiceAuditAlarmA)(LPCSTR SubsystemName, LPCSTR ServiceName, HANDLE ClientToken, PPRIVILEGE_SET Privileges, BOOL AccessGranted);
static WINAPI ULONG (*pProcessTrace)(PTRACEHANDLE HandleArray, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime);
static WINAPI ULONG (*pQueryAllTracesA)(PEVENT_TRACE_PROPERTIES* parray, ULONG arraycount, PULONG psessioncount);
static WINAPI ULONG (*pQueryAllTracesW)(PEVENT_TRACE_PROPERTIES* parray, ULONG arraycount, PULONG psessioncount);
static WINAPI ULONG (*pQueryTraceW)(TRACEHANDLE handle, LPCWSTR sessionname, PEVENT_TRACE_PROPERTIES properties);
static WINAPI BOOL (*pQueryWindows31FilesMigration)(DWORD x1);
static WINAPI DWORD (*pReadEncryptedFileRaw)(PFE_EXPORT_FUNC export, PVOID callback, PVOID context);
static WINAPI BOOL (*pReadEventLogA)(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD* pnBytesRead, DWORD* pnMinNumberOfBytesNeeded);
static WINAPI BOOL (*pReadEventLogW)(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD* pnBytesRead, DWORD* pnMinNumberOfBytesNeeded);
static WINAPI LSTATUS (*pRegConnectRegistryA)(LPCSTR machine, HKEY hkey, PHKEY reskey);
static WINAPI LSTATUS (*pRegConnectRegistryW)(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegCopyTreeA)(HKEY hsrc, char* subkey, HKEY hdst);
static WINAPI LSTATUS (*pRegCreateKeyA)(HKEY hkey, LPCSTR lpSubKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegCreateKeyTransactedA)(HKEY hkey, LPCSTR name, DWORD reserved, LPSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES* sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2);
static WINAPI LSTATUS (*pRegCreateKeyTransactedW)(HKEY hkey, LPCWSTR name, DWORD reserved, LPWSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES* sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2);
static WINAPI LSTATUS (*pRegCreateKeyW)(HKEY hkey, LPCWSTR lpSubKey, PHKEY phkResult);
static WINAPI LSTATUS (*pRegDeleteKeyA)(HKEY hkey, LPCSTR name);
static WINAPI LSTATUS (*pRegDeleteKeyW)(HKEY hkey, LPCWSTR name);
static WINAPI LSTATUS (*pRegDisablePredefinedCache)(void);
static WINAPI LONG (*pRegDisableReflectionKey)(HKEY base);
static WINAPI LSTATUS (*pRegEnumKeyA)(HKEY hkey, DWORD index, LPSTR name, DWORD name_len);
static WINAPI LSTATUS (*pRegEnumKeyW)(HKEY hkey, DWORD index, LPWSTR name, DWORD name_len);
static WINAPI LSTATUS (*pRegOpenKeyA)(HKEY hkey, LPCSTR name, PHKEY retkey);
static WINAPI LSTATUS (*pRegOpenKeyW)(HKEY hkey, LPCWSTR name, PHKEY retkey);
static WINAPI LSTATUS (*pRegOverridePredefKey)(HKEY hkey, HKEY override);
static WINAPI LSTATUS (*pRegQueryMultipleValuesA)(HKEY hkey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize);
static WINAPI LSTATUS (*pRegQueryMultipleValuesW)(HKEY hkey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize);
static WINAPI LONG (*pRegQueryReflectionKey)(HKEY hkey, BOOL* is_reflection_disabled);
static WINAPI LSTATUS (*pRegQueryValueA)(HKEY hkey, LPCSTR name, LPSTR data, LPLONG count);
static WINAPI LSTATUS (*pRegQueryValueW)(HKEY hkey, LPCWSTR name, LPWSTR data, LPLONG count);
static WINAPI LSTATUS (*pRegReplaceKeyA)(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile);
static WINAPI LSTATUS (*pRegReplaceKeyW)(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile);
static WINAPI LSTATUS (*pRegSaveKeyA)(HKEY hkey, LPCSTR file, LPSECURITY_ATTRIBUTES sa);
static WINAPI LSTATUS (*pRegSaveKeyW)(HKEY hkey, LPCWSTR file, LPSECURITY_ATTRIBUTES sa);
static WINAPI LSTATUS (*pRegSetValueA)(HKEY hkey, LPCSTR subkey, DWORD type, LPCSTR data, DWORD count);
static WINAPI LSTATUS (*pRegSetValueW)(HKEY hkey, LPCWSTR subkey, DWORD type, LPCWSTR data, DWORD count);
static WINAPI HANDLE (*pRegisterEventSourceA)(LPCSTR lpUNCServerName, LPCSTR lpSourceName);
static WINAPI HANDLE (*pRegisterEventSourceW)(LPCWSTR lpUNCServerName, LPCWSTR lpSourceName);
static WINAPI void (*pRegisterWaitChainCOMCallback)(PCOGETCALLSTATE call_state_cb, PCOGETACTIVATIONSTATE activation_state_cb);
static WINAPI BOOL (*pReportEventA)(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCSTR* lpStrings, LPVOID lpRawData);
static WINAPI BOOL (*pReportEventW)(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCWSTR* lpStrings, LPVOID lpRawData);
static WINAPI BOOL (*pSaferCloseLevel)(SAFER_LEVEL_HANDLE handle);
static WINAPI BOOL (*pSaferComputeTokenFromLevel)(SAFER_LEVEL_HANDLE handle, HANDLE token, PHANDLE access_token, DWORD flags, LPVOID reserved);
static WINAPI BOOL (*pSaferCreateLevel)(DWORD ScopeId, DWORD LevelId, DWORD OpenFlags, SAFER_LEVEL_HANDLE* LevelHandle, LPVOID lpReserved);
static WINAPI BOOL (*pSaferGetPolicyInformation)(DWORD scope, SAFER_POLICY_INFO_CLASS class, DWORD size, PVOID buffer, PDWORD required, LPVOID lpReserved);
static WINAPI BOOL (*pSaferIdentifyLevel)(DWORD count, SAFER_CODE_PROPERTIES* properties, SAFER_LEVEL_HANDLE* handle, void* reserved);
static WINAPI BOOL (*pSaferSetLevelInformation)(SAFER_LEVEL_HANDLE handle, SAFER_OBJECT_INFO_CLASS infotype, LPVOID buffer, DWORD size);
static WINAPI DWORD (*pSetEntriesInAclA)(ULONG count, PEXPLICIT_ACCESSA pEntries, PACL OldAcl, PACL* NewAcl);
static WINAPI DWORD (*pSetEntriesInAclW)(ULONG count, PEXPLICIT_ACCESSW pEntries, PACL OldAcl, PACL* NewAcl);
static WINAPI BOOL (*pSetFileSecurityA)(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor);
static WINAPI DWORD (*pSetNamedSecurityInfoA)(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI DWORD (*pSetNamedSecurityInfoW)(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI DWORD (*pSetSecurityInfo)(HANDLE handle, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl);
static WINAPI ULONG (*pStartTraceA)(PTRACEHANDLE pSessionHandle, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pStartTraceW)(PTRACEHANDLE pSessionHandle, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties);
static WINAPI ULONG (*pStopTraceA)(TRACEHANDLE session, LPCSTR session_name, PEVENT_TRACE_PROPERTIES properties);
static WINAPI ULONG (*pStopTraceW)(TRACEHANDLE session, LPCWSTR session_name, PEVENT_TRACE_PROPERTIES properties);
static WINAPI BOOL (*pSynchronizeWindows31FilesAndWindowsNTRegistry)(DWORD x1, DWORD x2, DWORD x3, DWORD x4);
static WINAPI NTSTATUS (*pSystemFunction001)(BYTE* data, BYTE* key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction002)(BYTE* data, BYTE* key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction003)(BYTE* key, LPBYTE output);
static WINAPI NTSTATUS (*pSystemFunction004)(struct ustring* in, struct ustring* key, struct ustring* out);
static WINAPI NTSTATUS (*pSystemFunction005)(struct ustring* in, struct ustring* key, struct ustring* out);
static WINAPI NTSTATUS (*pSystemFunction006)(LPCSTR password, LPSTR hash);
static WINAPI NTSTATUS (*pSystemFunction007)(UNICODE_STRING* string, LPBYTE hash);
static WINAPI NTSTATUS (*pSystemFunction008)(BYTE* challenge, BYTE* hash, LPBYTE response);
static WINAPI NTSTATUS (*pSystemFunction009)(BYTE* challenge, BYTE* hash, LPBYTE response);
static WINAPI NTSTATUS (*pSystemFunction010)(LPVOID unknown, BYTE* data, LPBYTE hash);
static WINAPI NTSTATUS (*pSystemFunction012)(BYTE* in, BYTE* key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction013)(BYTE* in, BYTE* key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction024)(BYTE* in, BYTE* key, LPBYTE out);
static WINAPI NTSTATUS (*pSystemFunction025)(BYTE* in, BYTE* key, LPBYTE out);
static WINAPI BOOL (*pSystemFunction030)(LPCVOID b1, LPCVOID b2);
static WINAPI NTSTATUS (*pSystemFunction032)(struct ustring* data, struct ustring* key);
static WINAPI BOOL (*pSystemFunction035)(LPCSTR lpszDllFilePath);
static WINAPI ULONG (*pTraceSetInformation)(TRACEHANDLE handle, TRACE_INFO_CLASS infoclass, void* info, ULONG len);
static WINAPI DWORD (*pTreeResetNamedSecurityInfoW)(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args);
static WINAPI ULONG (*pWmiExecuteMethodA)(WMIHANDLE handle, char* name, ULONG method, ULONG inputsize, void* inputbuffer, ULONG* outputsize, void* outputbuffer);
static WINAPI ULONG (*pWmiExecuteMethodW)(WMIHANDLE handle, WCHAR* name, ULONG method, ULONG inputsize, void* inputbuffer, ULONG* outputsize, void* outputbuffer);
static WINAPI void (*pWmiFreeBuffer)(void* buffer);
static WINAPI ULONG (*pWmiMofEnumerateResourcesA)(MOFHANDLE handle, ULONG* count, MOFRESOURCEINFOA** resource);
static WINAPI ULONG (*pWmiMofEnumerateResourcesW)(MOFHANDLE handle, ULONG* count, MOFRESOURCEINFOW** resource);
static WINAPI ULONG (*pWmiNotificationRegistrationA)(GUID* guid, BOOLEAN enable, void* info, ULONG_PTR context, ULONG flags);
static WINAPI ULONG (*pWmiNotificationRegistrationW)(GUID* guid, BOOLEAN enable, void* info, ULONG_PTR context, ULONG flags);
static WINAPI ULONG (*pWmiOpenBlock)(GUID* guid, ULONG access, WMIHANDLE* handle);
static WINAPI ULONG (*pWmiQueryAllDataA)(WMIHANDLE handle, ULONG* size, void* buffer);
static WINAPI ULONG (*pWmiQueryAllDataW)(WMIHANDLE handle, ULONG* size, void* buffer);
static WINAPI ULONG (*pWmiQueryGuidInformation)(WMIHANDLE handle, WMIGUIDINFORMATION* info);
static WINAPI ULONG (*pWmiSetSingleInstanceA)(WMIHANDLE handle, char* name, ULONG reserved, ULONG size, void* buffer);
static WINAPI ULONG (*pWmiSetSingleInstanceW)(WMIHANDLE handle, WCHAR* name, ULONG reserved, ULONG size, void* buffer);
static WINAPI ULONG (*pWmiSetSingleItemA)(WMIHANDLE handle, char* name, ULONG id, ULONG reserved, ULONG size, void* buffer);
static WINAPI ULONG (*pWmiSetSingleItemW)(WMIHANDLE handle, WCHAR* name, ULONG id, ULONG reserved, ULONG size, void* buffer);
static WINAPI DWORD (*pWriteEncryptedFileRaw)(PFE_IMPORT_FUNC import, PVOID callback, PVOID context);
static void* pA_SHAFinal;
static void* pextA_SHAFinal;
static void* pA_SHAInit;
static void* pextA_SHAInit;
static void* pA_SHAUpdate;
static void* pextA_SHAUpdate;
static void* pCreateProcessAsUserA;
static void* pextCreateProcessAsUserA;
static void* pCreateProcessAsUserW;
static void* pextCreateProcessAsUserW;
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
static void* pGetDynamicTimeZoneInformationEffectiveYears;
static void* pextGetDynamicTimeZoneInformationEffectiveYears;
static void* pGetTraceEnableFlags;
static void* pextGetTraceEnableFlags;
static void* pGetTraceEnableLevel;
static void* pextGetTraceEnableLevel;
static void* pGetTraceLoggerHandle;
static void* pextGetTraceLoggerHandle;
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
static void* pRegisterTraceGuidsA;
static void* pextRegisterTraceGuidsA;
static void* pRegisterTraceGuidsW;
static void* pextRegisterTraceGuidsW;
static void* pTraceEvent;
static void* pextTraceEvent;
static void* pTraceMessage;
static void* pextTraceMessage;
static void* pTraceMessageVa;
static void* pextTraceMessageVa;
static void* pUnregisterTraceGuids;
static void* pextUnregisterTraceGuids;

WINAPI BOOL wine32b_advapi32_AbortSystemShutdownA(LPSTR lpMachineName) /* ../dlls/advapi32/advapi.c:189 */
{
	BOOL return_value;
	TRACE("Enter AbortSystemShutdownA\n");
	return_value = pAbortSystemShutdownA(lpMachineName);
	TRACE("Leave AbortSystemShutdownA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_AbortSystemShutdownW(LPWSTR lpMachineName) /* ../dlls/advapi32/advapi.c:200 */
{
	BOOL return_value;
	TRACE("Enter AbortSystemShutdownW\n");
	return_value = pAbortSystemShutdownW(lpMachineName);
	TRACE("Leave AbortSystemShutdownW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_AccessCheckAndAuditAlarmA(LPCSTR Subsystem, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD DesiredAccess, PGENERIC_MAPPING GenericMapping, BOOL ObjectCreation, LPDWORD GrantedAccess, LPBOOL AccessStatus, LPBOOL pfGenerateOnClose) /* ../dlls/advapi32/security.c:1712 */
{
	BOOL return_value;
	TRACE("Enter AccessCheckAndAuditAlarmA\n");
	return_value = pAccessCheckAndAuditAlarmA(Subsystem, HandleId, ObjectTypeName, ObjectName, SecurityDescriptor, DesiredAccess, GenericMapping, ObjectCreation, GrantedAccess, AccessStatus, pfGenerateOnClose);
	TRACE("Leave AccessCheckAndAuditAlarmA\n");
	return return_value;
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

WINAPI BOOLEAN wine32b_advapi32_AuditQuerySystemPolicy(GUID* guids, ULONG count, AUDIT_POLICY_INFORMATION** policy) /* ../dlls/advapi32/lsa.c:1080 */
{
	BOOLEAN return_value;
	TRACE("Enter AuditQuerySystemPolicy\n");
	return_value = pAuditQuerySystemPolicy(guids, count, policy);
	TRACE("Leave AuditQuerySystemPolicy\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_BackupEventLogA(HANDLE hEventLog, LPCSTR lpBackupFileName) /* ../dlls/advapi32/eventlog.c:55 */
{
	BOOL return_value;
	TRACE("Enter BackupEventLogA\n");
	return_value = pBackupEventLogA(hEventLog, lpBackupFileName);
	TRACE("Leave BackupEventLogA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_BackupEventLogW(HANDLE hEventLog, LPCWSTR lpBackupFileName) /* ../dlls/advapi32/eventlog.c:72 */
{
	BOOL return_value;
	TRACE("Enter BackupEventLogW\n");
	return_value = pBackupEventLogW(hEventLog, lpBackupFileName);
	TRACE("Leave BackupEventLogW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_BuildExplicitAccessWithNameA(PEXPLICIT_ACCESSA pExplicitAccess, LPSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance) /* ../dlls/advapi32/security.c:1897 */
{
	TRACE("Enter BuildExplicitAccessWithNameA\n");
	pBuildExplicitAccessWithNameA(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
	TRACE("Leave BuildExplicitAccessWithNameA\n");
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

WINAPI void wine32b_advapi32_BuildExplicitAccessWithNameW(PEXPLICIT_ACCESSW pExplicitAccess, LPWSTR pTrusteeName, DWORD AccessPermissions, ACCESS_MODE AccessMode, DWORD Inheritance) /* ../dlls/advapi32/security.c:1918 */
{
	TRACE("Enter BuildExplicitAccessWithNameW\n");
	pBuildExplicitAccessWithNameW(pExplicitAccess, pTrusteeName, AccessPermissions, AccessMode, Inheritance);
	TRACE("Leave BuildExplicitAccessWithNameW\n");
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

WINAPI DWORD wine32b_advapi32_BuildSecurityDescriptorA(PTRUSTEEA pOwner, PTRUSTEEA pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSA pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSA pListofAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR* pNewSD) /* ../dlls/advapi32/security.c:540 */
{
	DWORD return_value;
	TRACE("Enter BuildSecurityDescriptorA\n");
	return_value = pBuildSecurityDescriptorA(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListofAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
	TRACE("Leave BuildSecurityDescriptorA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_BuildSecurityDescriptorW(PTRUSTEEW pOwner, PTRUSTEEW pGroup, ULONG cCountOfAccessEntries, PEXPLICIT_ACCESSW pListOfAccessEntries, ULONG cCountOfAuditEntries, PEXPLICIT_ACCESSW pListOfAuditEntries, PSECURITY_DESCRIPTOR pOldSD, PULONG lpdwBufferLength, PSECURITY_DESCRIPTOR* pNewSD) /* ../dlls/advapi32/security.c:563 */
{
	DWORD return_value;
	TRACE("Enter BuildSecurityDescriptorW\n");
	return_value = pBuildSecurityDescriptorW(pOwner, pGroup, cCountOfAccessEntries, pListOfAccessEntries, cCountOfAuditEntries, pListOfAuditEntries, pOldSD, lpdwBufferLength, pNewSD);
	TRACE("Leave BuildSecurityDescriptorW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_BuildTrusteeWithNameA(PTRUSTEEA pTrustee, LPSTR name) /* ../dlls/advapi32/security.c:2127 */
{
	TRACE("Enter BuildTrusteeWithNameA\n");
	pBuildTrusteeWithNameA(pTrustee, name);
	TRACE("Leave BuildTrusteeWithNameA\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithNameW(PTRUSTEEW pTrustee, LPWSTR name) /* ../dlls/advapi32/security.c:2141 */
{
	TRACE("Enter BuildTrusteeWithNameW\n");
	pBuildTrusteeWithNameW(pTrustee, name);
	TRACE("Leave BuildTrusteeWithNameW\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndNameA(PTRUSTEEA pTrustee, POBJECTS_AND_NAME_A pObjName, SE_OBJECT_TYPE ObjectType, LPSTR ObjectTypeName, LPSTR InheritedObjectTypeName, LPSTR Name) /* ../dlls/advapi32/security.c:1939 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameA\n");
	pBuildTrusteeWithObjectsAndNameA(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
	TRACE("Leave BuildTrusteeWithObjectsAndNameA\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndNameW(PTRUSTEEW pTrustee, POBJECTS_AND_NAME_W pObjName, SE_OBJECT_TYPE ObjectType, LPWSTR ObjectTypeName, LPWSTR InheritedObjectTypeName, LPWSTR Name) /* ../dlls/advapi32/security.c:1975 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndNameW\n");
	pBuildTrusteeWithObjectsAndNameW(pTrustee, pObjName, ObjectType, ObjectTypeName, InheritedObjectTypeName, Name);
	TRACE("Leave BuildTrusteeWithObjectsAndNameW\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndSidA(PTRUSTEEA pTrustee, POBJECTS_AND_SID pObjSid, GUID* pObjectGuid, GUID* pInheritedObjectGuid, PSID pSid) /* ../dlls/advapi32/security.c:2011 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidA\n");
	pBuildTrusteeWithObjectsAndSidA(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
	TRACE("Leave BuildTrusteeWithObjectsAndSidA\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithObjectsAndSidW(PTRUSTEEW pTrustee, POBJECTS_AND_SID pObjSid, GUID* pObjectGuid, GUID* pInheritedObjectGuid, PSID pSid) /* ../dlls/advapi32/security.c:2055 */
{
	TRACE("Enter BuildTrusteeWithObjectsAndSidW\n");
	pBuildTrusteeWithObjectsAndSidW(pTrustee, pObjSid, pObjectGuid, pInheritedObjectGuid, pSid);
	TRACE("Leave BuildTrusteeWithObjectsAndSidW\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithSidA(PTRUSTEEA pTrustee, PSID pSid) /* ../dlls/advapi32/security.c:2099 */
{
	TRACE("Enter BuildTrusteeWithSidA\n");
	pBuildTrusteeWithSidA(pTrustee, pSid);
	TRACE("Leave BuildTrusteeWithSidA\n");
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

WINAPI void wine32b_advapi32_BuildTrusteeWithSidW(PTRUSTEEW pTrustee, PSID pSid) /* ../dlls/advapi32/security.c:2113 */
{
	TRACE("Enter BuildTrusteeWithSidW\n");
	pBuildTrusteeWithSidW(pTrustee, pSid);
	TRACE("Leave BuildTrusteeWithSidW\n");
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

WINAPI BOOL wine32b_advapi32_ClearEventLogA(HANDLE hEventLog, LPCSTR lpBackupFileName) /* ../dlls/advapi32/eventlog.c:112 */
{
	BOOL return_value;
	TRACE("Enter ClearEventLogA\n");
	return_value = pClearEventLogA(hEventLog, lpBackupFileName);
	TRACE("Leave ClearEventLogA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ClearEventLogW(HANDLE hEventLog, LPCWSTR lpBackupFileName) /* ../dlls/advapi32/eventlog.c:129 */
{
	BOOL return_value;
	TRACE("Enter ClearEventLogW\n");
	return_value = pClearEventLogW(hEventLog, lpBackupFileName);
	TRACE("Leave ClearEventLogW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_CloseEncryptedFileRaw(PVOID context) /* ../dlls/advapi32/crypt.c:345 */
{
	TRACE("Enter CloseEncryptedFileRaw\n");
	pCloseEncryptedFileRaw(context);
	TRACE("Leave CloseEncryptedFileRaw\n");
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

WINAPI BOOL wine32b_advapi32_CloseEventLog(HANDLE hEventLog) /* ../dlls/advapi32/eventlog.c:154 */
{
	BOOL return_value;
	TRACE("Enter CloseEventLog\n");
	return_value = pCloseEventLog(hEventLog);
	TRACE("Leave CloseEventLog\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_CloseTrace(TRACEHANDLE handle) /* ../dlls/advapi32/eventlog.c:825 */
{
	ULONG return_value;
	TRACE("Enter CloseTrace\n");
	return_value = pCloseTrace(handle);
	TRACE("Leave CloseTrace\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_CommandLineFromMsiDescriptor(WCHAR* szDescriptor, WCHAR* szCommandLine, DWORD* pcchCommandLine) /* ../dlls/advapi32/advapi.c:323 */
{
	DWORD return_value;
	TRACE("Enter CommandLineFromMsiDescriptor\n");
	return_value = pCommandLineFromMsiDescriptor(szDescriptor, szCommandLine, pcchCommandLine);
	TRACE("Leave CommandLineFromMsiDescriptor\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_ControlTraceA(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control) /* ../dlls/advapi32/eventlog.c:185 */
{
	ULONG return_value;
	TRACE("Enter ControlTraceA\n");
	return_value = pControlTraceA(hSession, SessionName, Properties, control);
	TRACE("Leave ControlTraceA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_ControlTraceW(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties, ULONG control) /* ../dlls/advapi32/eventlog.c:173 */
{
	ULONG return_value;
	TRACE("Enter ControlTraceW\n");
	return_value = pControlTraceW(hSession, SessionName, Properties, control);
	TRACE("Leave ControlTraceW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorA(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION Information, LPSTR* OutputString, PULONG OutputLen) /* ../dlls/advapi32/security.c:3754 */
{
	BOOL return_value;
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorA\n");
	return_value = pConvertSecurityDescriptorToStringSecurityDescriptorA(SecurityDescriptor, SDRevision, Information, OutputString, OutputLen);
	TRACE("Leave ConvertSecurityDescriptorToStringSecurityDescriptorA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertSecurityDescriptorToStringSecurityDescriptorW(PSECURITY_DESCRIPTOR SecurityDescriptor, DWORD SDRevision, SECURITY_INFORMATION RequestedInformation, LPWSTR* OutputString, PULONG OutputLen) /* ../dlls/advapi32/security.c:3695 */
{
	BOOL return_value;
	TRACE("Enter ConvertSecurityDescriptorToStringSecurityDescriptorW\n");
	return_value = pConvertSecurityDescriptorToStringSecurityDescriptorW(SecurityDescriptor, SDRevision, RequestedInformation, OutputString, OutputLen);
	TRACE("Leave ConvertSecurityDescriptorToStringSecurityDescriptorW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertSidToStringSidA(PSID pSid, LPSTR* pstr) /* ../dlls/advapi32/security.c:3856 */
{
	BOOL return_value;
	TRACE("Enter ConvertSidToStringSidA\n");
	return_value = pConvertSidToStringSidA(pSid, pstr);
	TRACE("Leave ConvertSidToStringSidA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertSidToStringSidW(PSID pSid, LPWSTR* pstr) /* ../dlls/advapi32/security.c:3835 */
{
	BOOL return_value;
	TRACE("Enter ConvertSidToStringSidW\n");
	return_value = pConvertSidToStringSidW(pSid, pstr);
	TRACE("Leave ConvertSidToStringSidW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorA(LPCSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR* SecurityDescriptor, PULONG SecurityDescriptorSize) /* ../dlls/advapi32/security.c:3293 */
{
	BOOL return_value;
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorA\n");
	return_value = pConvertStringSecurityDescriptorToSecurityDescriptorA(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
	TRACE("Leave ConvertStringSecurityDescriptorToSecurityDescriptorA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertStringSecurityDescriptorToSecurityDescriptorW(LPCWSTR StringSecurityDescriptor, DWORD StringSDRevision, PSECURITY_DESCRIPTOR* SecurityDescriptor, PULONG SecurityDescriptorSize) /* ../dlls/advapi32/security.c:3320 */
{
	BOOL return_value;
	TRACE("Enter ConvertStringSecurityDescriptorToSecurityDescriptorW\n");
	return_value = pConvertStringSecurityDescriptorToSecurityDescriptorW(StringSecurityDescriptor, StringSDRevision, SecurityDescriptor, SecurityDescriptorSize);
	TRACE("Leave ConvertStringSecurityDescriptorToSecurityDescriptorW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertStringSidToSidA(LPCSTR StringSid, PSID* Sid) /* ../dlls/advapi32/security.c:3807 */
{
	BOOL return_value;
	TRACE("Enter ConvertStringSidToSidA\n");
	return_value = pConvertStringSidToSidA(StringSid, Sid);
	TRACE("Leave ConvertStringSidToSidA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ConvertStringSidToSidW(LPCWSTR StringSid, PSID* Sid) /* ../dlls/advapi32/security.c:3783 */
{
	BOOL return_value;
	TRACE("Enter ConvertStringSidToSidW\n");
	return_value = pConvertStringSidToSidW(StringSid, Sid);
	TRACE("Leave ConvertStringSidToSidW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CreateProcessWithLogonW(LPCWSTR lpUsername, LPCWSTR lpDomain, LPCWSTR lpPassword, DWORD dwLogonFlags, LPCWSTR lpApplicationName, LPWSTR lpCommandLine, DWORD dwCreationFlags, LPVOID lpEnvironment, LPCWSTR lpCurrentDirectory, LPSTARTUPINFOW lpStartupInfo, LPPROCESS_INFORMATION lpProcessInformation) /* ../dlls/advapi32/security.c:3880 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessWithLogonW\n");
	return_value = pCreateProcessWithLogonW(lpUsername, lpDomain, lpPassword, dwLogonFlags, lpApplicationName, lpCommandLine, dwCreationFlags, lpEnvironment, lpCurrentDirectory, lpStartupInfo, lpProcessInformation);
	TRACE("Leave CreateProcessWithLogonW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CreateProcessWithTokenW(HANDLE token, DWORD logon_flags, LPCWSTR application_name, LPWSTR command_line, DWORD creation_flags, void* environment, LPCWSTR current_directory, STARTUPINFOW* startup_info, PROCESS_INFORMATION* process_information) /* ../dlls/advapi32/security.c:3892 */
{
	BOOL return_value;
	TRACE("Enter CreateProcessWithTokenW\n");
	return_value = pCreateProcessWithTokenW(token, logon_flags, application_name, command_line, creation_flags, environment, current_directory, startup_info, process_information);
	TRACE("Leave CreateProcessWithTokenW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredDeleteA(LPCSTR TargetName, DWORD Type, DWORD Flags) /* ../dlls/advapi32/cred.c:1077 */
{
	BOOL return_value;
	TRACE("Enter CredDeleteA\n");
	return_value = pCredDeleteA(TargetName, Type, Flags);
	TRACE("Leave CredDeleteA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredDeleteW(LPCWSTR TargetName, DWORD Type, DWORD Flags) /* ../dlls/advapi32/cred.c:1110 */
{
	BOOL return_value;
	TRACE("Enter CredDeleteW\n");
	return_value = pCredDeleteW(TargetName, Type, Flags);
	TRACE("Leave CredDeleteW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredEnumerateA(LPCSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIALA** Credentials) /* ../dlls/advapi32/cred.c:1171 */
{
	BOOL return_value;
	TRACE("Enter CredEnumerateA\n");
	return_value = pCredEnumerateA(Filter, Flags, Count, Credentials);
	TRACE("Leave CredEnumerateA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredEnumerateW(LPCWSTR Filter, DWORD Flags, DWORD* Count, PCREDENTIALW** Credentials) /* ../dlls/advapi32/cred.c:1234 */
{
	BOOL return_value;
	TRACE("Enter CredEnumerateW\n");
	return_value = pCredEnumerateW(Filter, Flags, Count, Credentials);
	TRACE("Leave CredEnumerateW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_CredFree(PVOID Buffer) /* ../dlls/advapi32/cred.c:1340 */
{
	TRACE("Enter CredFree\n");
	pCredFree(Buffer);
	TRACE("Leave CredFree\n");
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

WINAPI BOOL wine32b_advapi32_CredGetSessionTypes(DWORD persistCount, LPDWORD persists) /* ../dlls/advapi32/cred.c:1865 */
{
	BOOL return_value;
	TRACE("Enter CredGetSessionTypes\n");
	return_value = pCredGetSessionTypes(persistCount, persists);
	TRACE("Leave CredGetSessionTypes\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredIsMarshaledCredentialA(LPCSTR name) /* ../dlls/advapi32/cred.c:2180 */
{
	BOOL return_value;
	TRACE("Enter CredIsMarshaledCredentialA\n");
	return_value = pCredIsMarshaledCredentialA(name);
	TRACE("Leave CredIsMarshaledCredentialA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredIsMarshaledCredentialW(LPCWSTR name) /* ../dlls/advapi32/cred.c:2146 */
{
	BOOL return_value;
	TRACE("Enter CredIsMarshaledCredentialW\n");
	return_value = pCredIsMarshaledCredentialW(name);
	TRACE("Leave CredIsMarshaledCredentialW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredMarshalCredentialA(CRED_MARSHAL_TYPE type, PVOID cred, LPSTR* out) /* ../dlls/advapi32/cred.c:1885 */
{
	BOOL return_value;
	TRACE("Enter CredMarshalCredentialA\n");
	return_value = pCredMarshalCredentialA(type, cred, out);
	TRACE("Leave CredMarshalCredentialA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredMarshalCredentialW(CRED_MARSHAL_TYPE type, PVOID cred, LPWSTR* out) /* ../dlls/advapi32/cred.c:1938 */
{
	BOOL return_value;
	TRACE("Enter CredMarshalCredentialW\n");
	return_value = pCredMarshalCredentialW(type, cred, out);
	TRACE("Leave CredMarshalCredentialW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredReadA(LPCSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALA* Credential) /* ../dlls/advapi32/cred.c:1348 */
{
	BOOL return_value;
	TRACE("Enter CredReadA\n");
	return_value = pCredReadA(TargetName, Type, Flags, Credential);
	TRACE("Leave CredReadA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredReadDomainCredentialsA(PCREDENTIAL_TARGET_INFORMATIONA TargetInformation, DWORD Flags, DWORD* Size, PCREDENTIALA** Credentials) /* ../dlls/advapi32/cred.c:1553 */
{
	BOOL return_value;
	TRACE("Enter CredReadDomainCredentialsA\n");
	return_value = pCredReadDomainCredentialsA(TargetInformation, Flags, Size, Credentials);
	TRACE("Leave CredReadDomainCredentialsA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredReadDomainCredentialsW(PCREDENTIAL_TARGET_INFORMATIONW TargetInformation, DWORD Flags, DWORD* Size, PCREDENTIALW** Credentials) /* ../dlls/advapi32/cred.c:1699 */
{
	BOOL return_value;
	TRACE("Enter CredReadDomainCredentialsW\n");
	return_value = pCredReadDomainCredentialsW(TargetInformation, Flags, Size, Credentials);
	TRACE("Leave CredReadDomainCredentialsW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredReadW(LPCWSTR TargetName, DWORD Type, DWORD Flags, PCREDENTIALW* Credential) /* ../dlls/advapi32/cred.c:1395 */
{
	BOOL return_value;
	TRACE("Enter CredReadW\n");
	return_value = pCredReadW(TargetName, Type, Flags, Credential);
	TRACE("Leave CredReadW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredUnmarshalCredentialA(LPCSTR cred, PCRED_MARSHAL_TYPE type, PVOID* out) /* ../dlls/advapi32/cred.c:1994 */
{
	BOOL return_value;
	TRACE("Enter CredUnmarshalCredentialA\n");
	return_value = pCredUnmarshalCredentialA(cred, type, out);
	TRACE("Leave CredUnmarshalCredentialA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredUnmarshalCredentialW(LPCWSTR cred, PCRED_MARSHAL_TYPE type, PVOID* out) /* ../dlls/advapi32/cred.c:2068 */
{
	BOOL return_value;
	TRACE("Enter CredUnmarshalCredentialW\n");
	return_value = pCredUnmarshalCredentialW(cred, type, out);
	TRACE("Leave CredUnmarshalCredentialW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredWriteA(PCREDENTIALA Credential, DWORD Flags) /* ../dlls/advapi32/cred.c:1720 */
{
	BOOL return_value;
	TRACE("Enter CredWriteA\n");
	return_value = pCredWriteA(Credential, Flags);
	TRACE("Leave CredWriteA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CredWriteW(PCREDENTIALW Credential, DWORD Flags) /* ../dlls/advapi32/cred.c:1754 */
{
	BOOL return_value;
	TRACE("Enter CredWriteW\n");
	return_value = pCredWriteW(Credential, Flags);
	TRACE("Leave CredWriteW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptAcquireContextA(HCRYPTPROV* phProv, LPCSTR pszContainer, LPCSTR pszProvider, DWORD dwProvType, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:577 */
{
	BOOL return_value;
	TRACE("Enter CryptAcquireContextA\n");
	return_value = pCryptAcquireContextA(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
	TRACE("Leave CryptAcquireContextA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptAcquireContextW(HCRYPTPROV* phProv, LPCWSTR pszContainer, LPCWSTR pszProvider, DWORD dwProvType, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:365 */
{
	BOOL return_value;
	TRACE("Enter CryptAcquireContextW\n");
	return_value = pCryptAcquireContextW(phProv, pszContainer, pszProvider, dwProvType, dwFlags);
	TRACE("Leave CryptAcquireContextW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptContextAddRef(HCRYPTPROV hProv, DWORD* pdwReserved, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:621 */
{
	BOOL return_value;
	TRACE("Enter CryptContextAddRef\n");
	return_value = pCryptContextAddRef(hProv, pdwReserved, dwFlags);
	TRACE("Leave CryptContextAddRef\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptCreateHash(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH* phHash) /* ../dlls/advapi32/crypt.c:749 */
{
	BOOL return_value;
	TRACE("Enter CryptCreateHash\n");
	return_value = pCryptCreateHash(hProv, Algid, hKey, dwFlags, phHash);
	TRACE("Leave CryptCreateHash\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDecrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen) /* ../dlls/advapi32/crypt.c:809 */
{
	BOOL return_value;
	TRACE("Enter CryptDecrypt\n");
	return_value = pCryptDecrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen);
	TRACE("Leave CryptDecrypt\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDeriveKey(HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY* phKey) /* ../dlls/advapi32/crypt.c:847 */
{
	BOOL return_value;
	TRACE("Enter CryptDeriveKey\n");
	return_value = pCryptDeriveKey(hProv, Algid, hBaseData, dwFlags, phKey);
	TRACE("Leave CryptDeriveKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDestroyHash(HCRYPTHASH hHash) /* ../dlls/advapi32/crypt.c:899 */
{
	BOOL return_value;
	TRACE("Enter CryptDestroyHash\n");
	return_value = pCryptDestroyHash(hHash);
	TRACE("Leave CryptDestroyHash\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDestroyKey(HCRYPTKEY hKey) /* ../dlls/advapi32/crypt.c:939 */
{
	BOOL return_value;
	TRACE("Enter CryptDestroyKey\n");
	return_value = pCryptDestroyKey(hKey);
	TRACE("Leave CryptDestroyKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDuplicateHash(HCRYPTHASH hHash, DWORD* pdwReserved, DWORD dwFlags, HCRYPTHASH* phHash) /* ../dlls/advapi32/crypt.c:982 */
{
	BOOL return_value;
	TRACE("Enter CryptDuplicateHash\n");
	return_value = pCryptDuplicateHash(hHash, pdwReserved, dwFlags, phHash);
	TRACE("Leave CryptDuplicateHash\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptDuplicateKey(HCRYPTKEY hKey, DWORD* pdwReserved, DWORD dwFlags, HCRYPTKEY* phKey) /* ../dlls/advapi32/crypt.c:1038 */
{
	BOOL return_value;
	TRACE("Enter CryptDuplicateKey\n");
	return_value = pCryptDuplicateKey(hKey, pdwReserved, dwFlags, phKey);
	TRACE("Leave CryptDuplicateKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptEncrypt(HCRYPTKEY hKey, HCRYPTHASH hHash, BOOL Final, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen, DWORD dwBufLen) /* ../dlls/advapi32/crypt.c:1102 */
{
	BOOL return_value;
	TRACE("Enter CryptEncrypt\n");
	return_value = pCryptEncrypt(hKey, hHash, Final, dwFlags, pbData, pdwDataLen, dwBufLen);
	TRACE("Leave CryptEncrypt\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptEnumProviderTypesA(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPSTR pszTypeName, DWORD* pcbTypeName) /* ../dlls/advapi32/crypt.c:1371 */
{
	BOOL return_value;
	TRACE("Enter CryptEnumProviderTypesA\n");
	return_value = pCryptEnumProviderTypesA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
	TRACE("Leave CryptEnumProviderTypesA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptEnumProviderTypesW(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPWSTR pszTypeName, DWORD* pcbTypeName) /* ../dlls/advapi32/crypt.c:1292 */
{
	BOOL return_value;
	TRACE("Enter CryptEnumProviderTypesW\n");
	return_value = pCryptEnumProviderTypesW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszTypeName, pcbTypeName);
	TRACE("Leave CryptEnumProviderTypesW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptEnumProvidersA(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPSTR pszProvName, DWORD* pcbProvName) /* ../dlls/advapi32/crypt.c:1237 */
{
	BOOL return_value;
	TRACE("Enter CryptEnumProvidersA\n");
	return_value = pCryptEnumProvidersA(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
	TRACE("Leave CryptEnumProvidersA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptEnumProvidersW(DWORD dwIndex, DWORD* pdwReserved, DWORD dwFlags, DWORD* pdwProvType, LPWSTR pszProvName, DWORD* pcbProvName) /* ../dlls/advapi32/crypt.c:1145 */
{
	BOOL return_value;
	TRACE("Enter CryptEnumProvidersW\n");
	return_value = pCryptEnumProvidersW(dwIndex, pdwReserved, dwFlags, pdwProvType, pszProvName, pcbProvName);
	TRACE("Leave CryptEnumProvidersW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptExportKey(HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE* pbData, DWORD* pdwDataLen) /* ../dlls/advapi32/crypt.c:1425 */
{
	BOOL return_value;
	TRACE("Enter CryptExportKey\n");
	return_value = pCryptExportKey(hKey, hExpKey, dwBlobType, dwFlags, pbData, pdwDataLen);
	TRACE("Leave CryptExportKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGenKey(HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY* phKey) /* ../dlls/advapi32/crypt.c:1460 */
{
	BOOL return_value;
	TRACE("Enter CryptGenKey\n");
	return_value = pCryptGenKey(hProv, Algid, dwFlags, phKey);
	TRACE("Leave CryptGenKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGenRandom(HCRYPTPROV hProv, DWORD dwLen, BYTE* pbBuffer) /* ../dlls/advapi32/crypt.c:709 */
{
	BOOL return_value;
	TRACE("Enter CryptGenRandom\n");
	return_value = pCryptGenRandom(hProv, dwLen, pbBuffer);
	TRACE("Leave CryptGenRandom\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetDefaultProviderA(DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags, LPSTR pszProvName, DWORD* pcbProvName) /* ../dlls/advapi32/crypt.c:1569 */
{
	BOOL return_value;
	TRACE("Enter CryptGetDefaultProviderA\n");
	return_value = pCryptGetDefaultProviderA(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
	TRACE("Leave CryptGetDefaultProviderA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetDefaultProviderW(DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD* pcbProvName) /* ../dlls/advapi32/crypt.c:1512 */
{
	BOOL return_value;
	TRACE("Enter CryptGetDefaultProviderW\n");
	return_value = pCryptGetDefaultProviderW(dwProvType, pdwReserved, dwFlags, pszProvName, pcbProvName);
	TRACE("Leave CryptGetDefaultProviderW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1619 */
{
	BOOL return_value;
	TRACE("Enter CryptGetHashParam\n");
	return_value = pCryptGetHashParam(hHash, dwParam, pbData, pdwDataLen, dwFlags);
	TRACE("Leave CryptGetHashParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetKeyParam(HCRYPTKEY hKey, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1658 */
{
	BOOL return_value;
	TRACE("Enter CryptGetKeyParam\n");
	return_value = pCryptGetKeyParam(hKey, dwParam, pbData, pdwDataLen, dwFlags);
	TRACE("Leave CryptGetKeyParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetProvParam(HCRYPTPROV hProv, DWORD dwParam, BYTE* pbData, DWORD* pdwDataLen, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1697 */
{
	BOOL return_value;
	TRACE("Enter CryptGetProvParam\n");
	return_value = pCryptGetProvParam(hProv, dwParam, pbData, pdwDataLen, dwFlags);
	TRACE("Leave CryptGetProvParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptGetUserKey(HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY* phUserKey) /* ../dlls/advapi32/crypt.c:1727 */
{
	BOOL return_value;
	TRACE("Enter CryptGetUserKey\n");
	return_value = pCryptGetUserKey(hProv, dwKeySpec, phUserKey);
	TRACE("Leave CryptGetUserKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptHashData(HCRYPTHASH hHash, BYTE* pbData, DWORD dwDataLen, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1780 */
{
	BOOL return_value;
	TRACE("Enter CryptHashData\n");
	return_value = pCryptHashData(hHash, pbData, dwDataLen, dwFlags);
	TRACE("Leave CryptHashData\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptHashSessionKey(HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1817 */
{
	BOOL return_value;
	TRACE("Enter CryptHashSessionKey\n");
	return_value = pCryptHashSessionKey(hHash, hKey, dwFlags);
	TRACE("Leave CryptHashSessionKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptImportKey(HCRYPTPROV hProv, BYTE* pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY* phKey) /* ../dlls/advapi32/crypt.c:1859 */
{
	BOOL return_value;
	TRACE("Enter CryptImportKey\n");
	return_value = pCryptImportKey(hProv, pbData, dwDataLen, hPubKey, dwFlags, phKey);
	TRACE("Leave CryptImportKey\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptReleaseContext(HCRYPTPROV hProv, ULONG_PTR dwFlags) /* ../dlls/advapi32/crypt.c:656 */
{
	BOOL return_value;
	TRACE("Enter CryptReleaseContext\n");
	return_value = pCryptReleaseContext(hProv, dwFlags);
	TRACE("Leave CryptReleaseContext\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetHashParam(HCRYPTHASH hHash, DWORD dwParam, BYTE* pbData, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:1979 */
{
	BOOL return_value;
	TRACE("Enter CryptSetHashParam\n");
	return_value = pCryptSetHashParam(hHash, dwParam, pbData, dwFlags);
	TRACE("Leave CryptSetHashParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetKeyParam(HCRYPTKEY hKey, DWORD dwParam, BYTE* pbData, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2013 */
{
	BOOL return_value;
	TRACE("Enter CryptSetKeyParam\n");
	return_value = pCryptSetKeyParam(hKey, dwParam, pbData, dwFlags);
	TRACE("Leave CryptSetKeyParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetProvParam(HCRYPTPROV hProv, DWORD dwParam, BYTE* pbData, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2188 */
{
	BOOL return_value;
	TRACE("Enter CryptSetProvParam\n");
	return_value = pCryptSetProvParam(hProv, dwParam, pbData, dwFlags);
	TRACE("Leave CryptSetProvParam\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetProviderA(LPCSTR pszProvName, DWORD dwProvType) /* ../dlls/advapi32/crypt.c:2045 */
{
	BOOL return_value;
	TRACE("Enter CryptSetProviderA\n");
	return_value = pCryptSetProviderA(pszProvName, dwProvType);
	TRACE("Leave CryptSetProviderA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetProviderExA(LPCSTR pszProvName, DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2158 */
{
	BOOL return_value;
	TRACE("Enter CryptSetProviderExA\n");
	return_value = pCryptSetProviderExA(pszProvName, dwProvType, pdwReserved, dwFlags);
	TRACE("Leave CryptSetProviderExA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetProviderExW(LPCWSTR pszProvName, DWORD dwProvType, DWORD* pdwReserved, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2077 */
{
	BOOL return_value;
	TRACE("Enter CryptSetProviderExW\n");
	return_value = pCryptSetProviderExW(pszProvName, dwProvType, pdwReserved, dwFlags);
	TRACE("Leave CryptSetProviderExW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSetProviderW(LPCWSTR pszProvName, DWORD dwProvType) /* ../dlls/advapi32/crypt.c:2056 */
{
	BOOL return_value;
	TRACE("Enter CryptSetProviderW\n");
	return_value = pCryptSetProviderW(pszProvName, dwProvType);
	TRACE("Leave CryptSetProviderW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSignHashA(HCRYPTHASH hHash, DWORD dwKeySpec, LPCSTR sDescription, DWORD dwFlags, BYTE* pbSignature, DWORD* pdwSigLen) /* ../dlls/advapi32/crypt.c:1948 */
{
	BOOL return_value;
	TRACE("Enter CryptSignHashA\n");
	return_value = pCryptSignHashA(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
	TRACE("Leave CryptSignHashA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptSignHashW(HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR sDescription, DWORD dwFlags, BYTE* pbSignature, DWORD* pdwSigLen) /* ../dlls/advapi32/crypt.c:1917 */
{
	BOOL return_value;
	TRACE("Enter CryptSignHashW\n");
	return_value = pCryptSignHashW(hHash, dwKeySpec, sDescription, dwFlags, pbSignature, pdwSigLen);
	TRACE("Leave CryptSignHashW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptVerifySignatureA(HCRYPTHASH hHash, BYTE* pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR sDescription, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2275 */
{
	BOOL return_value;
	TRACE("Enter CryptVerifySignatureA\n");
	return_value = pCryptVerifySignatureA(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
	TRACE("Leave CryptVerifySignatureA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_CryptVerifySignatureW(HCRYPTHASH hHash, BYTE* pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR sDescription, DWORD dwFlags) /* ../dlls/advapi32/crypt.c:2247 */
{
	BOOL return_value;
	TRACE("Enter CryptVerifySignatureW\n");
	return_value = pCryptVerifySignatureW(hHash, pbSignature, dwSigLen, hPubKey, sDescription, dwFlags);
	TRACE("Leave CryptVerifySignatureW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_DecryptFileA(LPCSTR lpFileName, DWORD dwReserved) /* ../dlls/advapi32/security.c:4191 */
{
	BOOL return_value;
	TRACE("Enter DecryptFileA\n");
	return_value = pDecryptFileA(lpFileName, dwReserved);
	TRACE("Leave DecryptFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_DecryptFileW(LPCWSTR lpFileName, DWORD dwReserved) /* ../dlls/advapi32/security.c:4182 */
{
	BOOL return_value;
	TRACE("Enter DecryptFileW\n");
	return_value = pDecryptFileW(lpFileName, dwReserved);
	TRACE("Leave DecryptFileW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_DeregisterEventSource(HANDLE hEventLog) /* ../dlls/advapi32/eventlog.c:220 */
{
	BOOL return_value;
	TRACE("Enter DeregisterEventSource\n");
	return_value = pDeregisterEventSource(hEventLog);
	TRACE("Leave DeregisterEventSource\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_EnableTrace(ULONG enable, ULONG flag, ULONG level, LPCGUID guid, TRACEHANDLE hSession) /* ../dlls/advapi32/eventlog.c:258 */
{
	ULONG return_value;
	TRACE("Enter EnableTrace\n");
	return_value = pEnableTrace(enable, flag, level, guid, hSession);
	TRACE("Leave EnableTrace\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_EnableTraceEx(LPCGUID provider, LPCGUID source, TRACEHANDLE hSession, ULONG enable, UCHAR level, ULONGLONG anykeyword, ULONGLONG allkeyword, ULONG enableprop, PEVENT_FILTER_DESCRIPTOR filterdesc) /* ../dlls/advapi32/eventlog.c:229 */
{
	ULONG return_value;
	TRACE("Enter EnableTraceEx\n");
	return_value = pEnableTraceEx(provider, source, hSession, enable, level, anykeyword, allkeyword, enableprop, filterdesc);
	TRACE("Leave EnableTraceEx\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_EnableTraceEx2(TRACEHANDLE handle, LPCGUID provider, ULONG control, UCHAR level, ULONGLONG match_any, ULONGLONG match_all, ULONG timeout, PENABLE_TRACE_PARAMETERS params) /* ../dlls/advapi32/eventlog.c:244 */
{
	ULONG return_value;
	TRACE("Enter EnableTraceEx2\n");
	return_value = pEnableTraceEx2(handle, provider, control, level, match_any, match_all, timeout, params);
	TRACE("Leave EnableTraceEx2\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_EncryptFileA(LPCSTR lpFileName) /* ../dlls/advapi32/security.c:4209 */
{
	BOOL return_value;
	TRACE("Enter EncryptFileA\n");
	return_value = pEncryptFileA(lpFileName);
	TRACE("Leave EncryptFileA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_EncryptFileW(LPCWSTR lpFileName) /* ../dlls/advapi32/security.c:4200 */
{
	BOOL return_value;
	TRACE("Enter EncryptFileW\n");
	return_value = pEncryptFileW(lpFileName);
	TRACE("Leave EncryptFileW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_EnumerateTraceGuids(PTRACE_GUID_PROPERTIES* propertiesarray, ULONG arraycount, PULONG guidcount) /* ../dlls/advapi32/eventlog.c:834 */
{
	ULONG return_value;
	TRACE("Enter EnumerateTraceGuids\n");
	return_value = pEnumerateTraceGuids(propertiesarray, arraycount, guidcount);
	TRACE("Leave EnumerateTraceGuids\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_FileEncryptionStatusA(LPCSTR lpFileName, LPDWORD lpStatus) /* ../dlls/advapi32/security.c:4230 */
{
	BOOL return_value;
	TRACE("Enter FileEncryptionStatusA\n");
	return_value = pFileEncryptionStatusA(lpFileName, lpStatus);
	TRACE("Leave FileEncryptionStatusA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_FileEncryptionStatusW(LPCWSTR lpFileName, LPDWORD lpStatus) /* ../dlls/advapi32/security.c:4218 */
{
	BOOL return_value;
	TRACE("Enter FileEncryptionStatusW\n");
	return_value = pFileEncryptionStatusW(lpFileName, lpStatus);
	TRACE("Leave FileEncryptionStatusW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_FlushTraceA(TRACEHANDLE hSession, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties) /* ../dlls/advapi32/eventlog.c:194 */
{
	ULONG return_value;
	TRACE("Enter FlushTraceA\n");
	return_value = pFlushTraceA(hSession, SessionName, Properties);
	TRACE("Leave FlushTraceA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_FlushTraceW(TRACEHANDLE hSession, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties) /* ../dlls/advapi32/eventlog.c:202 */
{
	ULONG return_value;
	TRACE("Enter FlushTraceW\n");
	return_value = pFlushTraceW(hSession, SessionName, Properties);
	TRACE("Leave FlushTraceW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetAuditedPermissionsFromAclA(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights) /* ../dlls/advapi32/security.c:2796 */
{
	DWORD return_value;
	TRACE("Enter GetAuditedPermissionsFromAclA\n");
	return_value = pGetAuditedPermissionsFromAclA(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
	TRACE("Leave GetAuditedPermissionsFromAclA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetAuditedPermissionsFromAclW(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pSuccessfulAuditedRights, PACCESS_MASK pFailedAuditRights) /* ../dlls/advapi32/security.c:2807 */
{
	DWORD return_value;
	TRACE("Enter GetAuditedPermissionsFromAclW\n");
	return_value = pGetAuditedPermissionsFromAclW(pacl, pTrustee, pSuccessfulAuditedRights, pFailedAuditRights);
	TRACE("Leave GetAuditedPermissionsFromAclW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetCurrentHwProfileA(LPHW_PROFILE_INFOA pInfo) /* ../dlls/advapi32/advapi.c:134 */
{
	BOOL return_value;
	TRACE("Enter GetCurrentHwProfileA\n");
	return_value = pGetCurrentHwProfileA(pInfo);
	TRACE("Leave GetCurrentHwProfileA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetCurrentHwProfileW(LPHW_PROFILE_INFOW pInfo) /* ../dlls/advapi32/advapi.c:148 */
{
	BOOL return_value;
	TRACE("Enter GetCurrentHwProfileW\n");
	return_value = pGetCurrentHwProfileW(pInfo);
	TRACE("Leave GetCurrentHwProfileW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetEffectiveRightsFromAclA(PACL pacl, PTRUSTEEA pTrustee, PACCESS_MASK pAccessRights) /* ../dlls/advapi32/security.c:499 */
{
	DWORD return_value;
	TRACE("Enter GetEffectiveRightsFromAclA\n");
	return_value = pGetEffectiveRightsFromAclA(pacl, pTrustee, pAccessRights);
	TRACE("Leave GetEffectiveRightsFromAclA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetEffectiveRightsFromAclW(PACL pacl, PTRUSTEEW pTrustee, PACCESS_MASK pAccessRights) /* ../dlls/advapi32/security.c:508 */
{
	DWORD return_value;
	TRACE("Enter GetEffectiveRightsFromAclW\n");
	return_value = pGetEffectiveRightsFromAclW(pacl, pTrustee, pAccessRights);
	TRACE("Leave GetEffectiveRightsFromAclW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetEventLogInformation(HANDLE hEventLog, DWORD dwInfoLevel, LPVOID lpBuffer, DWORD cbBufSize, LPDWORD pcbBytesNeeded) /* ../dlls/advapi32/eventlog.c:283 */
{
	BOOL return_value;
	TRACE("Enter GetEventLogInformation\n");
	return_value = pGetEventLogInformation(hEventLog, dwInfoLevel, lpBuffer, cbBufSize, pcbBytesNeeded);
	TRACE("Leave GetEventLogInformation\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetExplicitEntriesFromAclA(PACL pacl, PULONG pcCountOfExplicitEntries, PEXPLICIT_ACCESSA* pListOfExplicitEntries) /* ../dlls/advapi32/security.c:2700 */
{
	DWORD return_value;
	TRACE("Enter GetExplicitEntriesFromAclA\n");
	return_value = pGetExplicitEntriesFromAclA(pacl, pcCountOfExplicitEntries, pListOfExplicitEntries);
	TRACE("Leave GetExplicitEntriesFromAclA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetExplicitEntriesFromAclW(PACL pacl, PULONG count, PEXPLICIT_ACCESSW* list) /* ../dlls/advapi32/security.c:2710 */
{
	DWORD return_value;
	TRACE("Enter GetExplicitEntriesFromAclW\n");
	return_value = pGetExplicitEntriesFromAclW(pacl, count, list);
	TRACE("Leave GetExplicitEntriesFromAclW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetFileSecurityA(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, DWORD nLength, LPDWORD lpnLengthNeeded) /* ../dlls/advapi32/security.c:1011 */
{
	BOOL return_value;
	TRACE("Enter GetFileSecurityA\n");
	return_value = pGetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor, nLength, lpnLengthNeeded);
	TRACE("Leave GetFileSecurityA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoA(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID* ppsidOwner, PSID* ppsidGroup, PACL* ppDacl, PACL* ppSacl, PSECURITY_DESCRIPTOR* ppSecurityDescriptor) /* ../dlls/advapi32/security.c:4070 */
{
	DWORD return_value;
	TRACE("Enter GetNamedSecurityInfoA\n");
	return_value = pGetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
	TRACE("Leave GetNamedSecurityInfoA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoExA(LPCSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCSTR provider, LPCSTR property, PACTRL_ACCESSA* access_list, PACTRL_AUDITA* audit_list, LPSTR* owner, LPSTR* group) /* ../dlls/advapi32/security.c:4170 */
{
	DWORD return_value;
	TRACE("Enter GetNamedSecurityInfoExA\n");
	return_value = pGetNamedSecurityInfoExA(object, type, info, provider, property, access_list, audit_list, owner, group);
	TRACE("Leave GetNamedSecurityInfoExA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoExW(LPCWSTR object, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, LPCWSTR provider, LPCWSTR property, PACTRL_ACCESSW* access_list, PACTRL_AUDITW* audit_list, LPWSTR* owner, LPWSTR* group) /* ../dlls/advapi32/security.c:4158 */
{
	DWORD return_value;
	TRACE("Enter GetNamedSecurityInfoExW\n");
	return_value = pGetNamedSecurityInfoExW(object, type, info, provider, property, access_list, audit_list, owner, group);
	TRACE("Leave GetNamedSecurityInfoExW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetNamedSecurityInfoW(LPWSTR name, SE_OBJECT_TYPE type, SECURITY_INFORMATION info, PSID* owner, PSID* group, PACL* dacl, PACL* sacl, PSECURITY_DESCRIPTOR* descriptor) /* ../dlls/advapi32/security.c:4093 */
{
	DWORD return_value;
	TRACE("Enter GetNamedSecurityInfoW\n");
	return_value = pGetNamedSecurityInfoW(name, type, info, owner, group, dacl, sacl, descriptor);
	TRACE("Leave GetNamedSecurityInfoW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetNumberOfEventLogRecords(HANDLE hEventLog, PDWORD NumberOfRecords) /* ../dlls/advapi32/eventlog.c:338 */
{
	BOOL return_value;
	TRACE("Enter GetNumberOfEventLogRecords\n");
	return_value = pGetNumberOfEventLogRecords(hEventLog, NumberOfRecords);
	TRACE("Leave GetNumberOfEventLogRecords\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetOldestEventLogRecord(HANDLE hEventLog, PDWORD OldestRecord) /* ../dlls/advapi32/eventlog.c:373 */
{
	BOOL return_value;
	TRACE("Enter GetOldestEventLogRecord\n");
	return_value = pGetOldestEventLogRecord(hEventLog, OldestRecord);
	TRACE("Leave GetOldestEventLogRecord\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetSecurityInfo(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID* ppsidOwner, PSID* ppsidGroup, PACL* ppDacl, PACL* ppSacl, PSECURITY_DESCRIPTOR* ppSecurityDescriptor) /* ../dlls/advapi32/security.c:1781 */
{
	DWORD return_value;
	TRACE("Enter GetSecurityInfo\n");
	return_value = pGetSecurityInfo(hObject, ObjectType, SecurityInfo, ppsidOwner, ppsidGroup, ppDacl, ppSacl, ppSecurityDescriptor);
	TRACE("Leave GetSecurityInfo\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetSecurityInfoExA(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCSTR lpProvider, LPCSTR lpProperty, PACTRL_ACCESSA* ppAccessList, PACTRL_AUDITA* ppAuditList, LPSTR* lppOwner, LPSTR* lppGroup) /* ../dlls/advapi32/security.c:1869 */
{
	DWORD return_value;
	TRACE("Enter GetSecurityInfoExA\n");
	return_value = pGetSecurityInfoExA(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
	TRACE("Leave GetSecurityInfoExA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_GetSecurityInfoExW(HANDLE hObject, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, LPCWSTR lpProvider, LPCWSTR lpProperty, PACTRL_ACCESSW* ppAccessList, PACTRL_AUDITW* ppAuditList, LPWSTR* lppOwner, LPWSTR* lppGroup) /* ../dlls/advapi32/security.c:1883 */
{
	DWORD return_value;
	TRACE("Enter GetSecurityInfoExW\n");
	return_value = pGetSecurityInfoExW(hObject, ObjectType, SecurityInfo, lpProvider, lpProperty, ppAccessList, ppAuditList, lppOwner, lppGroup);
	TRACE("Leave GetSecurityInfoExW\n");
	return return_value;
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

WINAPI TRUSTEE_FORM wine32b_advapi32_GetTrusteeFormA(PTRUSTEEA pTrustee) /* ../dlls/advapi32/security.c:2155 */
{
	TRUSTEE_FORM return_value;
	TRACE("Enter GetTrusteeFormA\n");
	return_value = pGetTrusteeFormA(pTrustee);
	TRACE("Leave GetTrusteeFormA\n");
	return return_value;
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

WINAPI TRUSTEE_FORM wine32b_advapi32_GetTrusteeFormW(PTRUSTEEW pTrustee) /* ../dlls/advapi32/security.c:2168 */
{
	TRUSTEE_FORM return_value;
	TRACE("Enter GetTrusteeFormW\n");
	return_value = pGetTrusteeFormW(pTrustee);
	TRACE("Leave GetTrusteeFormW\n");
	return return_value;
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

WINAPI LPSTR wine32b_advapi32_GetTrusteeNameA(PTRUSTEEA pTrustee) /* ../dlls/advapi32/security.c:2181 */
{
	LPSTR return_value;
	TRACE("Enter GetTrusteeNameA\n");
	return_value = pGetTrusteeNameA(pTrustee);
	TRACE("Leave GetTrusteeNameA\n");
	return return_value;
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

WINAPI LPWSTR wine32b_advapi32_GetTrusteeNameW(PTRUSTEEW pTrustee) /* ../dlls/advapi32/security.c:2194 */
{
	LPWSTR return_value;
	TRACE("Enter GetTrusteeNameW\n");
	return_value = pGetTrusteeNameW(pTrustee);
	TRACE("Leave GetTrusteeNameW\n");
	return return_value;
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

WINAPI TRUSTEE_TYPE wine32b_advapi32_GetTrusteeTypeA(PTRUSTEEA pTrustee) /* ../dlls/advapi32/security.c:2207 */
{
	TRUSTEE_TYPE return_value;
	TRACE("Enter GetTrusteeTypeA\n");
	return_value = pGetTrusteeTypeA(pTrustee);
	TRACE("Leave GetTrusteeTypeA\n");
	return return_value;
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

WINAPI TRUSTEE_TYPE wine32b_advapi32_GetTrusteeTypeW(PTRUSTEEW pTrustee) /* ../dlls/advapi32/security.c:2220 */
{
	TRUSTEE_TYPE return_value;
	TRACE("Enter GetTrusteeTypeW\n");
	return_value = pGetTrusteeTypeW(pTrustee);
	TRACE("Leave GetTrusteeTypeW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetUserNameA(LPSTR lpszName, LPDWORD lpSize) /* ../dlls/advapi32/advapi.c:57 */
{
	BOOL return_value;
	TRACE("Enter GetUserNameA\n");
	return_value = pGetUserNameA(lpszName, lpSize);
	TRACE("Leave GetUserNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_GetUserNameW(LPWSTR lpszName, LPDWORD lpSize) /* ../dlls/advapi32/advapi.c:85 */
{
	BOOL return_value;
	TRACE("Enter GetUserNameW\n");
	return_value = pGetUserNameW(lpszName, lpSize);
	TRACE("Leave GetUserNameW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_InitiateShutdownA(char* name, char* message, DWORD seconds, DWORD flags, DWORD reason) /* ../dlls/advapi32/advapi.c:274 */
{
	DWORD return_value;
	TRACE("Enter InitiateShutdownA\n");
	return_value = pInitiateShutdownA(name, message, seconds, flags, reason);
	TRACE("Leave InitiateShutdownA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_InitiateShutdownW(WCHAR* name, WCHAR* message, DWORD seconds, DWORD flags, DWORD reason) /* ../dlls/advapi32/advapi.c:283 */
{
	DWORD return_value;
	TRACE("Enter InitiateShutdownW\n");
	return_value = pInitiateShutdownW(name, message, seconds, flags, reason);
	TRACE("Leave InitiateShutdownW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown) /* ../dlls/advapi32/advapi.c:255 */
{
	BOOL return_value;
	TRACE("Enter InitiateSystemShutdownA\n");
	return_value = pInitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	TRACE("Leave InitiateSystemShutdownA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownExA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason) /* ../dlls/advapi32/advapi.c:230 */
{
	BOOL return_value;
	TRACE("Enter InitiateSystemShutdownExA\n");
	return_value = pInitiateSystemShutdownExA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	TRACE("Leave InitiateSystemShutdownExA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownExW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason) /* ../dlls/advapi32/advapi.c:245 */
{
	BOOL return_value;
	TRACE("Enter InitiateSystemShutdownExW\n");
	return_value = pInitiateSystemShutdownExW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	TRACE("Leave InitiateSystemShutdownExW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_InitiateSystemShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown) /* ../dlls/advapi32/advapi.c:263 */
{
	BOOL return_value;
	TRACE("Enter InitiateSystemShutdownW\n");
	return_value = pInitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	TRACE("Leave InitiateSystemShutdownW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_IsTextUnicode(LPCVOID buf, INT len, LPINT flags) /* ../dlls/advapi32/advapi.c:168 */
{
	BOOL return_value;
	TRACE("Enter IsTextUnicode\n");
	return_value = pIsTextUnicode(buf, len, flags);
	TRACE("Leave IsTextUnicode\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LogonUserA(LPCSTR lpszUsername, LPCSTR lpszDomain, LPCSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken) /* ../dlls/advapi32/advapi.c:289 */
{
	BOOL return_value;
	TRACE("Enter LogonUserA\n");
	return_value = pLogonUserA(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
	TRACE("Leave LogonUserA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LogonUserW(LPCWSTR lpszUsername, LPCWSTR lpszDomain, LPCWSTR lpszPassword, DWORD dwLogonType, DWORD dwLogonProvider, PHANDLE phToken) /* ../dlls/advapi32/advapi.c:311 */
{
	BOOL return_value;
	TRACE("Enter LogonUserW\n");
	return_value = pLogonUserW(lpszUsername, lpszDomain, lpszPassword, dwLogonType, dwLogonProvider, phToken);
	TRACE("Leave LogonUserW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountNameA(LPCSTR system, LPCSTR account, PSID sid, LPDWORD cbSid, LPSTR ReferencedDomainName, LPDWORD cbReferencedDomainName, PSID_NAME_USE name_use) /* ../dlls/advapi32/security.c:1356 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountNameA\n");
	return_value = pLookupAccountNameA(system, account, sid, cbSid, ReferencedDomainName, cbReferencedDomainName, name_use);
	TRACE("Leave LookupAccountNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountNameW(LPCWSTR lpSystemName, LPCWSTR lpAccountName, PSID Sid, LPDWORD cbSid, LPWSTR ReferencedDomainName, LPDWORD cchReferencedDomainName, PSID_NAME_USE peUse) /* ../dlls/advapi32/security.c:1669 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountNameW\n");
	return_value = pLookupAccountNameW(lpSystemName, lpAccountName, Sid, cbSid, ReferencedDomainName, cchReferencedDomainName, peUse);
	TRACE("Leave LookupAccountNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountSidA(LPCSTR system, PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use) /* ../dlls/advapi32/security.c:1031 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountSidA\n");
	return_value = pLookupAccountSidA(system, sid, account, accountSize, domain, domainSize, name_use);
	TRACE("Leave LookupAccountSidA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountSidLocalA(PSID sid, LPSTR account, LPDWORD accountSize, LPSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use) /* ../dlls/advapi32/security.c:1088 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountSidLocalA\n");
	return_value = pLookupAccountSidLocalA(sid, account, accountSize, domain, domainSize, name_use);
	TRACE("Leave LookupAccountSidLocalA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountSidLocalW(PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use) /* ../dlls/advapi32/security.c:1279 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountSidLocalW\n");
	return_value = pLookupAccountSidLocalW(sid, account, accountSize, domain, domainSize, name_use);
	TRACE("Leave LookupAccountSidLocalW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupAccountSidW(LPCWSTR system, PSID sid, LPWSTR account, LPDWORD accountSize, LPWSTR domain, LPDWORD domainSize, PSID_NAME_USE name_use) /* ../dlls/advapi32/security.c:1113 */
{
	BOOL return_value;
	TRACE("Enter LookupAccountSidW\n");
	return_value = pLookupAccountSidW(system, sid, account, accountSize, domain, domainSize, name_use);
	TRACE("Leave LookupAccountSidW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeDisplayNameA(LPCSTR lpSystemName, LPCSTR lpName, LPSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId) /* ../dlls/advapi32/security.c:858 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeDisplayNameA\n");
	return_value = pLookupPrivilegeDisplayNameA(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
	TRACE("Leave LookupPrivilegeDisplayNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName, LPCWSTR lpName, LPWSTR lpDisplayName, LPDWORD cchDisplayName, LPDWORD lpLanguageId) /* ../dlls/advapi32/security.c:867 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeDisplayNameW\n");
	return_value = pLookupPrivilegeDisplayNameW(lpSystemName, lpName, lpDisplayName, cchDisplayName, lpLanguageId);
	TRACE("Leave LookupPrivilegeDisplayNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeNameA(LPCSTR lpSystemName, PLUID lpLuid, LPSTR lpName, LPDWORD cchName) /* ../dlls/advapi32/security.c:882 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeNameA\n");
	return_value = pLookupPrivilegeNameA(lpSystemName, lpLuid, lpName, cchName);
	TRACE("Leave LookupPrivilegeNameA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeNameW(LPCWSTR lpSystemName, PLUID lpLuid, LPWSTR lpName, LPDWORD cchName) /* ../dlls/advapi32/security.c:956 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeNameW\n");
	return_value = pLookupPrivilegeNameW(lpSystemName, lpLuid, lpName, cchName);
	TRACE("Leave LookupPrivilegeNameW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeValueA(LPCSTR lpSystemName, LPCSTR lpName, PLUID lpLuid) /* ../dlls/advapi32/security.c:844 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeValueA\n");
	return_value = pLookupPrivilegeValueA(lpSystemName, lpName, lpLuid);
	TRACE("Leave LookupPrivilegeValueA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_LookupPrivilegeValueW(LPCWSTR lpSystemName, LPCWSTR lpName, PLUID lpLuid) /* ../dlls/advapi32/security.c:797 */
{
	BOOL return_value;
	TRACE("Enter LookupPrivilegeValueW\n");
	return_value = pLookupPrivilegeValueW(lpSystemName, lpName, lpLuid);
	TRACE("Leave LookupPrivilegeValueW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_LookupSecurityDescriptorPartsA(TRUSTEEA* owner, TRUSTEEA* group, ULONG* access_count, EXPLICIT_ACCESSA* access_list, ULONG* audit_count, EXPLICIT_ACCESSA* audit_list, SECURITY_DESCRIPTOR* descriptor) /* ../dlls/advapi32/security.c:4510 */
{
	DWORD return_value;
	TRACE("Enter LookupSecurityDescriptorPartsA\n");
	return_value = pLookupSecurityDescriptorPartsA(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
	TRACE("Leave LookupSecurityDescriptorPartsA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_LookupSecurityDescriptorPartsW(TRUSTEEW* owner, TRUSTEEW* group, ULONG* access_count, EXPLICIT_ACCESSW* access_list, ULONG* audit_count, EXPLICIT_ACCESSW* audit_list, SECURITY_DESCRIPTOR* descriptor) /* ../dlls/advapi32/security.c:4522 */
{
	DWORD return_value;
	TRACE("Enter LookupSecurityDescriptorPartsW\n");
	return_value = pLookupSecurityDescriptorPartsW(owner, group, access_count, access_list, audit_count, audit_list, descriptor);
	TRACE("Leave LookupSecurityDescriptorPartsW\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaAddAccountRights(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING rights, ULONG count) /* ../dlls/advapi32/lsa.c:120 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaAddAccountRights\n");
	return_value = pLsaAddAccountRights(policy, sid, rights, count);
	TRACE("Leave LsaAddAccountRights\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaClose(LSA_HANDLE ObjectHandle) /* ../dlls/advapi32/lsa.c:142 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaClose\n");
	return_value = pLsaClose(ObjectHandle);
	TRACE("Leave LsaClose\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaCreateTrustedDomainEx(LSA_HANDLE policy, PTRUSTED_DOMAIN_INFORMATION_EX domain_info, PTRUSTED_DOMAIN_AUTH_INFORMATION auth_info, ACCESS_MASK access, PLSA_HANDLE domain) /* ../dlls/advapi32/lsa.c:152 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaCreateTrustedDomainEx\n");
	return_value = pLsaCreateTrustedDomainEx(policy, domain_info, auth_info, access, domain);
	TRACE("Leave LsaCreateTrustedDomainEx\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaDeleteTrustedDomain(LSA_HANDLE policy, PSID sid) /* ../dlls/advapi32/lsa.c:168 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaDeleteTrustedDomain\n");
	return_value = pLsaDeleteTrustedDomain(policy, sid);
	TRACE("Leave LsaDeleteTrustedDomain\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateAccountRights(LSA_HANDLE policy, PSID sid, PLSA_UNICODE_STRING* rights, PULONG count) /* ../dlls/advapi32/lsa.c:178 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaEnumerateAccountRights\n");
	return_value = pLsaEnumerateAccountRights(policy, sid, rights, count);
	TRACE("Leave LsaEnumerateAccountRights\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateAccountsWithUserRight(LSA_HANDLE policy, PLSA_UNICODE_STRING rights, PVOID* buffer, PULONG count) /* ../dlls/advapi32/lsa.c:194 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaEnumerateAccountsWithUserRight\n");
	return_value = pLsaEnumerateAccountsWithUserRight(policy, rights, buffer, count);
	TRACE("Leave LsaEnumerateAccountsWithUserRight\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateTrustedDomains(LSA_HANDLE PolicyHandle, PLSA_ENUMERATION_HANDLE EnumerationContext, PVOID* Buffer, ULONG PreferredMaximumLength, PULONG CountReturned) /* ../dlls/advapi32/lsa.c:226 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaEnumerateTrustedDomains\n");
	return_value = pLsaEnumerateTrustedDomains(PolicyHandle, EnumerationContext, Buffer, PreferredMaximumLength, CountReturned);
	TRACE("Leave LsaEnumerateTrustedDomains\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaEnumerateTrustedDomainsEx(LSA_HANDLE policy, PLSA_ENUMERATION_HANDLE context, PVOID* buffer, ULONG length, PULONG count) /* ../dlls/advapi32/lsa.c:244 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaEnumerateTrustedDomainsEx\n");
	return_value = pLsaEnumerateTrustedDomainsEx(policy, context, buffer, length, count);
	TRACE("Leave LsaEnumerateTrustedDomainsEx\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaFreeMemory(PVOID Buffer) /* ../dlls/advapi32/lsa.c:269 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaFreeMemory\n");
	return_value = pLsaFreeMemory(Buffer);
	TRACE("Leave LsaFreeMemory\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaLookupNames(LSA_HANDLE PolicyHandle, ULONG Count, PLSA_UNICODE_STRING Names, PLSA_REFERENCED_DOMAIN_LIST* ReferencedDomains, PLSA_TRANSLATED_SID* Sids) /* ../dlls/advapi32/lsa.c:294 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaLookupNames\n");
	return_value = pLsaLookupNames(PolicyHandle, Count, Names, ReferencedDomains, Sids);
	TRACE("Leave LsaLookupNames\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaLookupNames2(LSA_HANDLE policy, ULONG flags, ULONG count, PLSA_UNICODE_STRING names, PLSA_REFERENCED_DOMAIN_LIST* domains, PLSA_TRANSLATED_SID2* sids) /* ../dlls/advapi32/lsa.c:373 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaLookupNames2\n");
	return_value = pLsaLookupNames2(policy, flags, count, names, domains, sids);
	TRACE("Leave LsaLookupNames2\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaLookupPrivilegeDisplayName(LSA_HANDLE handle, LSA_UNICODE_STRING* name, LSA_UNICODE_STRING** display_name, SHORT* language) /* ../dlls/advapi32/lsa.c:1068 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaLookupPrivilegeDisplayName\n");
	return_value = pLsaLookupPrivilegeDisplayName(handle, name, display_name, language);
	TRACE("Leave LsaLookupPrivilegeDisplayName\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaLookupPrivilegeName(LSA_HANDLE handle, LUID* luid, LSA_UNICODE_STRING** name) /* ../dlls/advapi32/lsa.c:1035 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaLookupPrivilegeName\n");
	return_value = pLsaLookupPrivilegeName(handle, luid, name);
	TRACE("Leave LsaLookupPrivilegeName\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaLookupSids(LSA_HANDLE PolicyHandle, ULONG Count, PSID* Sids, LSA_REFERENCED_DOMAIN_LIST** ReferencedDomains, LSA_TRANSLATED_NAME** Names) /* ../dlls/advapi32/lsa.c:476 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaLookupSids\n");
	return_value = pLsaLookupSids(PolicyHandle, Count, Sids, ReferencedDomains, Names);
	TRACE("Leave LsaLookupSids\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_LsaNtStatusToWinError(NTSTATUS Status) /* ../dlls/advapi32/lsa.c:628 */
{
	ULONG return_value;
	TRACE("Enter LsaNtStatusToWinError\n");
	return_value = pLsaNtStatusToWinError(Status);
	TRACE("Leave LsaNtStatusToWinError\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaOpenPolicy(PLSA_UNICODE_STRING SystemName, PLSA_OBJECT_ATTRIBUTES ObjectAttributes, ACCESS_MASK DesiredAccess, PLSA_HANDLE PolicyHandle) /* ../dlls/advapi32/lsa.c:651 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaOpenPolicy\n");
	return_value = pLsaOpenPolicy(SystemName, ObjectAttributes, DesiredAccess, PolicyHandle);
	TRACE("Leave LsaOpenPolicy\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaOpenTrustedDomainByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, ACCESS_MASK access, PLSA_HANDLE handle) /* ../dlls/advapi32/lsa.c:673 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaOpenTrustedDomainByName\n");
	return_value = pLsaOpenTrustedDomainByName(policy, name, access, handle);
	TRACE("Leave LsaOpenTrustedDomainByName\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaQueryInformationPolicy(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID* Buffer) /* ../dlls/advapi32/lsa.c:697 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaQueryInformationPolicy\n");
	return_value = pLsaQueryInformationPolicy(PolicyHandle, InformationClass, Buffer);
	TRACE("Leave LsaQueryInformationPolicy\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaQueryTrustedDomainInfo(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID* buffer) /* ../dlls/advapi32/lsa.c:846 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaQueryTrustedDomainInfo\n");
	return_value = pLsaQueryTrustedDomainInfo(policy, sid, class, buffer);
	TRACE("Leave LsaQueryTrustedDomainInfo\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaQueryTrustedDomainInfoByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID* buffer) /* ../dlls/advapi32/lsa.c:860 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaQueryTrustedDomainInfoByName\n");
	return_value = pLsaQueryTrustedDomainInfoByName(policy, name, class, buffer);
	TRACE("Leave LsaQueryTrustedDomainInfoByName\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaRegisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event) /* ../dlls/advapi32/lsa.c:874 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaRegisterPolicyChangeNotification\n");
	return_value = pLsaRegisterPolicyChangeNotification(class, event);
	TRACE("Leave LsaRegisterPolicyChangeNotification\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaRemoveAccountRights(LSA_HANDLE policy, PSID sid, BOOLEAN all, PLSA_UNICODE_STRING rights, ULONG count) /* ../dlls/advapi32/lsa.c:886 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaRemoveAccountRights\n");
	return_value = pLsaRemoveAccountRights(policy, sid, all, rights, count);
	TRACE("Leave LsaRemoveAccountRights\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaRetrievePrivateData(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING* PrivateData) /* ../dlls/advapi32/lsa.c:911 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaRetrievePrivateData\n");
	return_value = pLsaRetrievePrivateData(PolicyHandle, KeyName, PrivateData);
	TRACE("Leave LsaRetrievePrivateData\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaSetInformationPolicy(LSA_HANDLE PolicyHandle, POLICY_INFORMATION_CLASS InformationClass, PVOID Buffer) /* ../dlls/advapi32/lsa.c:934 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaSetInformationPolicy\n");
	return_value = pLsaSetInformationPolicy(PolicyHandle, InformationClass, Buffer);
	TRACE("Leave LsaSetInformationPolicy\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaSetSecret(LSA_HANDLE SecretHandle, PLSA_UNICODE_STRING EncryptedCurrentValue, PLSA_UNICODE_STRING EncryptedOldValue) /* ../dlls/advapi32/lsa.c:958 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaSetSecret\n");
	return_value = pLsaSetSecret(SecretHandle, EncryptedCurrentValue, EncryptedOldValue);
	TRACE("Leave LsaSetSecret\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaSetTrustedDomainInfoByName(LSA_HANDLE policy, PLSA_UNICODE_STRING name, TRUSTED_INFORMATION_CLASS class, PVOID buffer) /* ../dlls/advapi32/lsa.c:972 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaSetTrustedDomainInfoByName\n");
	return_value = pLsaSetTrustedDomainInfoByName(policy, name, class, buffer);
	TRACE("Leave LsaSetTrustedDomainInfoByName\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaSetTrustedDomainInformation(LSA_HANDLE policy, PSID sid, TRUSTED_INFORMATION_CLASS class, PVOID buffer) /* ../dlls/advapi32/lsa.c:986 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaSetTrustedDomainInformation\n");
	return_value = pLsaSetTrustedDomainInformation(policy, sid, class, buffer);
	TRACE("Leave LsaSetTrustedDomainInformation\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaStorePrivateData(LSA_HANDLE PolicyHandle, PLSA_UNICODE_STRING KeyName, PLSA_UNICODE_STRING PrivateData) /* ../dlls/advapi32/lsa.c:1010 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaStorePrivateData\n");
	return_value = pLsaStorePrivateData(PolicyHandle, KeyName, PrivateData);
	TRACE("Leave LsaStorePrivateData\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_LsaUnregisterPolicyChangeNotification(POLICY_NOTIFICATION_INFORMATION_CLASS class, HANDLE event) /* ../dlls/advapi32/lsa.c:1023 */
{
	NTSTATUS return_value;
	TRACE("Enter LsaUnregisterPolicyChangeNotification\n");
	return_value = pLsaUnregisterPolicyChangeNotification(class, event);
	TRACE("Leave LsaUnregisterPolicyChangeNotification\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_NotifyBootConfigStatus(BOOL x1) /* ../dlls/advapi32/security.c:1346 */
{
	BOOL return_value;
	TRACE("Enter NotifyBootConfigStatus\n");
	return_value = pNotifyBootConfigStatus(x1);
	TRACE("Leave NotifyBootConfigStatus\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_NotifyChangeEventLog(HANDLE hEventLog, HANDLE hEvent) /* ../dlls/advapi32/eventlog.c:408 */
{
	BOOL return_value;
	TRACE("Enter NotifyChangeEventLog\n");
	return_value = pNotifyChangeEventLog(hEventLog, hEvent);
	TRACE("Leave NotifyChangeEventLog\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ObjectCloseAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, BOOL GenerateOnClose) /* ../dlls/advapi32/security.c:1724 */
{
	BOOL return_value;
	TRACE("Enter ObjectCloseAuditAlarmA\n");
	return_value = pObjectCloseAuditAlarmA(SubsystemName, HandleId, GenerateOnClose);
	TRACE("Leave ObjectCloseAuditAlarmA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ObjectOpenAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, LPSTR ObjectTypeName, LPSTR ObjectName, PSECURITY_DESCRIPTOR pSecurityDescriptor, HANDLE ClientToken, DWORD DesiredAccess, DWORD GrantedAccess, PPRIVILEGE_SET Privileges, BOOL ObjectCreation, BOOL AccessGranted, LPBOOL GenerateOnClose) /* ../dlls/advapi32/security.c:1731 */
{
	BOOL return_value;
	TRACE("Enter ObjectOpenAuditAlarmA\n");
	return_value = pObjectOpenAuditAlarmA(SubsystemName, HandleId, ObjectTypeName, ObjectName, pSecurityDescriptor, ClientToken, DesiredAccess, GrantedAccess, Privileges, ObjectCreation, AccessGranted, GenerateOnClose);
	TRACE("Leave ObjectOpenAuditAlarmA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName, LPVOID HandleId, HANDLE ClientToken, DWORD DesiredAccess, PPRIVILEGE_SET Privileges, BOOL AccessGranted) /* ../dlls/advapi32/security.c:1744 */
{
	BOOL return_value;
	TRACE("Enter ObjectPrivilegeAuditAlarmA\n");
	return_value = pObjectPrivilegeAuditAlarmA(SubsystemName, HandleId, ClientToken, DesiredAccess, Privileges, AccessGranted);
	TRACE("Leave ObjectPrivilegeAuditAlarmA\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_OpenBackupEventLogA(LPCSTR lpUNCServerName, LPCSTR lpFileName) /* ../dlls/advapi32/eventlog.c:428 */
{
	HANDLE return_value;
	TRACE("Enter OpenBackupEventLogA\n");
	return_value = pOpenBackupEventLogA(lpUNCServerName, lpFileName);
	TRACE("Leave OpenBackupEventLogA\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_OpenBackupEventLogW(LPCWSTR lpUNCServerName, LPCWSTR lpFileName) /* ../dlls/advapi32/eventlog.c:447 */
{
	HANDLE return_value;
	TRACE("Enter OpenBackupEventLogW\n");
	return_value = pOpenBackupEventLogW(lpUNCServerName, lpFileName);
	TRACE("Leave OpenBackupEventLogW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_OpenEncryptedFileRawA(LPCSTR filename, ULONG flags, PVOID* context) /* ../dlls/advapi32/crypt.c:2296 */
{
	DWORD return_value;
	TRACE("Enter OpenEncryptedFileRawA\n");
	return_value = pOpenEncryptedFileRawA(filename, flags, context);
	TRACE("Leave OpenEncryptedFileRawA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_OpenEncryptedFileRawW(LPCWSTR filename, ULONG flags, PVOID* context) /* ../dlls/advapi32/crypt.c:2315 */
{
	DWORD return_value;
	TRACE("Enter OpenEncryptedFileRawW\n");
	return_value = pOpenEncryptedFileRawW(filename, flags, context);
	TRACE("Leave OpenEncryptedFileRawW\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_OpenEventLogA(LPCSTR uncname, LPCSTR source) /* ../dlls/advapi32/eventlog.c:487 */
{
	HANDLE return_value;
	TRACE("Enter OpenEventLogA\n");
	return_value = pOpenEventLogA(uncname, source);
	TRACE("Leave OpenEventLogA\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_OpenEventLogW(LPCWSTR uncname, LPCWSTR source) /* ../dlls/advapi32/eventlog.c:506 */
{
	HANDLE return_value;
	TRACE("Enter OpenEventLogW\n");
	return_value = pOpenEventLogW(uncname, source);
	TRACE("Leave OpenEventLogW\n");
	return return_value;
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

WINAPI TRACEHANDLE wine32b_advapi32_OpenTraceA(PEVENT_TRACE_LOGFILEA logfile) /* ../dlls/advapi32/eventlog.c:792 */
{
	TRACEHANDLE return_value;
	TRACE("Enter OpenTraceA\n");
	return_value = pOpenTraceA(logfile);
	TRACE("Leave OpenTraceA\n");
	return return_value;
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

WINAPI TRACEHANDLE wine32b_advapi32_OpenTraceW(PEVENT_TRACE_LOGFILEW logfile) /* ../dlls/advapi32/eventlog.c:804 */
{
	TRACEHANDLE return_value;
	TRACE("Enter OpenTraceW\n");
	return_value = pOpenTraceW(logfile);
	TRACE("Leave OpenTraceW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName, LPCSTR ServiceName, HANDLE ClientToken, PPRIVILEGE_SET Privileges, BOOL AccessGranted) /* ../dlls/advapi32/security.c:1753 */
{
	BOOL return_value;
	TRACE("Enter PrivilegedServiceAuditAlarmA\n");
	return_value = pPrivilegedServiceAuditAlarmA(SubsystemName, ServiceName, ClientToken, Privileges, AccessGranted);
	TRACE("Leave PrivilegedServiceAuditAlarmA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_ProcessTrace(PTRACEHANDLE HandleArray, ULONG HandleCount, LPFILETIME StartTime, LPFILETIME EndTime) /* ../dlls/advapi32/eventlog.c:816 */
{
	ULONG return_value;
	TRACE("Enter ProcessTrace\n");
	return_value = pProcessTrace(HandleArray, HandleCount, StartTime, EndTime);
	TRACE("Leave ProcessTrace\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_QueryAllTracesA(PEVENT_TRACE_PROPERTIES* parray, ULONG arraycount, PULONG psessioncount) /* ../dlls/advapi32/eventlog.c:545 */
{
	ULONG return_value;
	TRACE("Enter QueryAllTracesA\n");
	return_value = pQueryAllTracesA(parray, arraycount, psessioncount);
	TRACE("Leave QueryAllTracesA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_QueryAllTracesW(PEVENT_TRACE_PROPERTIES* parray, ULONG arraycount, PULONG psessioncount) /* ../dlls/advapi32/eventlog.c:532 */
{
	ULONG return_value;
	TRACE("Enter QueryAllTracesW\n");
	return_value = pQueryAllTracesW(parray, arraycount, psessioncount);
	TRACE("Leave QueryAllTracesW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_QueryTraceW(TRACEHANDLE handle, LPCWSTR sessionname, PEVENT_TRACE_PROPERTIES properties) /* ../dlls/advapi32/eventlog.c:783 */
{
	ULONG return_value;
	TRACE("Enter QueryTraceW\n");
	return_value = pQueryTraceW(handle, sessionname, properties);
	TRACE("Leave QueryTraceW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_QueryWindows31FilesMigration(DWORD x1) /* ../dlls/advapi32/security.c:1316 */
{
	BOOL return_value;
	TRACE("Enter QueryWindows31FilesMigration\n");
	return_value = pQueryWindows31FilesMigration(x1);
	TRACE("Leave QueryWindows31FilesMigration\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_ReadEncryptedFileRaw(PFE_EXPORT_FUNC export, PVOID callback, PVOID context) /* ../dlls/advapi32/crypt.c:2334 */
{
	DWORD return_value;
	TRACE("Enter ReadEncryptedFileRaw\n");
	return_value = pReadEncryptedFileRaw(export, callback, context);
	TRACE("Leave ReadEncryptedFileRaw\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ReadEventLogA(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD* pnBytesRead, DWORD* pnMinNumberOfBytesNeeded) /* ../dlls/advapi32/eventlog.c:572 */
{
	BOOL return_value;
	TRACE("Enter ReadEventLogA\n");
	return_value = pReadEventLogA(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
	TRACE("Leave ReadEventLogA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ReadEventLogW(HANDLE hEventLog, DWORD dwReadFlags, DWORD dwRecordOffset, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, DWORD* pnBytesRead, DWORD* pnMinNumberOfBytesNeeded) /* ../dlls/advapi32/eventlog.c:587 */
{
	BOOL return_value;
	TRACE("Enter ReadEventLogW\n");
	return_value = pReadEventLogW(hEventLog, dwReadFlags, dwRecordOffset, lpBuffer, nNumberOfBytesToRead, pnBytesRead, pnMinNumberOfBytesNeeded);
	TRACE("Leave ReadEventLogW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegConnectRegistryA(LPCSTR machine, HKEY hkey, PHKEY reskey) /* ../dlls/advapi32/registry.c:588 */
{
	LSTATUS return_value;
	TRACE("Enter RegConnectRegistryA\n");
	return_value = pRegConnectRegistryA(machine, hkey, reskey);
	TRACE("Leave RegConnectRegistryA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult) /* ../dlls/advapi32/registry.c:548 */
{
	LSTATUS return_value;
	TRACE("Enter RegConnectRegistryW\n");
	return_value = pRegConnectRegistryW(lpMachineName, hKey, phkResult);
	TRACE("Leave RegConnectRegistryW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegCopyTreeA(HKEY hsrc, char* subkey, HKEY hdst) /* ../dlls/advapi32/registry.c:625 */
{
	LSTATUS return_value;
	TRACE("Enter RegCopyTreeA\n");
	return_value = pRegCopyTreeA(hsrc, subkey, hdst);
	TRACE("Leave RegCopyTreeA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegCreateKeyA(HKEY hkey, LPCSTR lpSubKey, PHKEY phkResult) /* ../dlls/advapi32/registry.c:84 */
{
	LSTATUS return_value;
	TRACE("Enter RegCreateKeyA\n");
	return_value = pRegCreateKeyA(hkey, lpSubKey, phkResult);
	TRACE("Leave RegCreateKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegCreateKeyTransactedA(HKEY hkey, LPCSTR name, DWORD reserved, LPSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES* sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2) /* ../dlls/advapi32/registry.c:107 */
{
	LSTATUS return_value;
	TRACE("Enter RegCreateKeyTransactedA\n");
	return_value = pRegCreateKeyTransactedA(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
	TRACE("Leave RegCreateKeyTransactedA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegCreateKeyTransactedW(HKEY hkey, LPCWSTR name, DWORD reserved, LPWSTR class, DWORD options, REGSAM access, SECURITY_ATTRIBUTES* sa, PHKEY retkey, LPDWORD dispos, HANDLE transaction, PVOID reserved2) /* ../dlls/advapi32/registry.c:94 */
{
	LSTATUS return_value;
	TRACE("Enter RegCreateKeyTransactedW\n");
	return_value = pRegCreateKeyTransactedW(hkey, name, reserved, class, options, access, sa, retkey, dispos, transaction, reserved2);
	TRACE("Leave RegCreateKeyTransactedW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegCreateKeyW(HKEY hkey, LPCWSTR lpSubKey, PHKEY phkResult) /* ../dlls/advapi32/registry.c:72 */
{
	LSTATUS return_value;
	TRACE("Enter RegCreateKeyW\n");
	return_value = pRegCreateKeyW(hkey, lpSubKey, phkResult);
	TRACE("Leave RegCreateKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegDeleteKeyA(HKEY hkey, LPCSTR name) /* ../dlls/advapi32/registry.c:340 */
{
	LSTATUS return_value;
	TRACE("Enter RegDeleteKeyA\n");
	return_value = pRegDeleteKeyA(hkey, name);
	TRACE("Leave RegDeleteKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegDeleteKeyW(HKEY hkey, LPCWSTR name) /* ../dlls/advapi32/registry.c:316 */
{
	LSTATUS return_value;
	TRACE("Enter RegDeleteKeyW\n");
	return_value = pRegDeleteKeyW(hkey, name);
	TRACE("Leave RegDeleteKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegDisablePredefinedCache(void) /* ../dlls/advapi32/registry.c:615 */
{
	LSTATUS return_value;
	TRACE("Enter RegDisablePredefinedCache\n");
	return_value = pRegDisablePredefinedCache();
	TRACE("Leave RegDisablePredefinedCache\n");
	return return_value;
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

WINAPI LONG wine32b_advapi32_RegDisableReflectionKey(HKEY base) /* ../dlls/advapi32/registry.c:642 */
{
	LONG return_value;
	TRACE("Enter RegDisableReflectionKey\n");
	return_value = pRegDisableReflectionKey(base);
	TRACE("Leave RegDisableReflectionKey\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegEnumKeyA(HKEY hkey, DWORD index, LPSTR name, DWORD name_len) /* ../dlls/advapi32/registry.c:191 */
{
	LSTATUS return_value;
	TRACE("Enter RegEnumKeyA\n");
	return_value = pRegEnumKeyA(hkey, index, name, name_len);
	TRACE("Leave RegEnumKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegEnumKeyW(HKEY hkey, DWORD index, LPWSTR name, DWORD name_len) /* ../dlls/advapi32/registry.c:180 */
{
	LSTATUS return_value;
	TRACE("Enter RegEnumKeyW\n");
	return_value = pRegEnumKeyW(hkey, index, name, name_len);
	TRACE("Leave RegEnumKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegOpenKeyA(HKEY hkey, LPCSTR name, PHKEY retkey) /* ../dlls/advapi32/registry.c:150 */
{
	LSTATUS return_value;
	TRACE("Enter RegOpenKeyA\n");
	return_value = pRegOpenKeyA(hkey, name, retkey);
	TRACE("Leave RegOpenKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegOpenKeyW(HKEY hkey, LPCWSTR name, PHKEY retkey) /* ../dlls/advapi32/registry.c:122 */
{
	LSTATUS return_value;
	TRACE("Enter RegOpenKeyW\n");
	return_value = pRegOpenKeyW(hkey, name, retkey);
	TRACE("Leave RegOpenKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegOverridePredefKey(HKEY hkey, HKEY override) /* ../dlls/advapi32/registry.c:52 */
{
	LSTATUS return_value;
	TRACE("Enter RegOverridePredefKey\n");
	return_value = pRegOverridePredefKey(hkey, override);
	TRACE("Leave RegOverridePredefKey\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegQueryMultipleValuesA(HKEY hkey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize) /* ../dlls/advapi32/registry.c:214 */
{
	LSTATUS return_value;
	TRACE("Enter RegQueryMultipleValuesA\n");
	return_value = pRegQueryMultipleValuesA(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
	TRACE("Leave RegQueryMultipleValuesA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegQueryMultipleValuesW(HKEY hkey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize) /* ../dlls/advapi32/registry.c:260 */
{
	LSTATUS return_value;
	TRACE("Enter RegQueryMultipleValuesW\n");
	return_value = pRegQueryMultipleValuesW(hkey, val_list, num_vals, lpValueBuf, ldwTotsize);
	TRACE("Leave RegQueryMultipleValuesW\n");
	return return_value;
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

WINAPI LONG wine32b_advapi32_RegQueryReflectionKey(HKEY hkey, BOOL* is_reflection_disabled) /* ../dlls/advapi32/registry.c:303 */
{
	LONG return_value;
	TRACE("Enter RegQueryReflectionKey\n");
	return_value = pRegQueryReflectionKey(hkey, is_reflection_disabled);
	TRACE("Leave RegQueryReflectionKey\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegQueryValueA(HKEY hkey, LPCSTR name, LPSTR data, LPLONG count) /* ../dlls/advapi32/registry.c:431 */
{
	LSTATUS return_value;
	TRACE("Enter RegQueryValueA\n");
	return_value = pRegQueryValueA(hkey, name, data, count);
	TRACE("Leave RegQueryValueA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegQueryValueW(HKEY hkey, LPCWSTR name, LPWSTR data, LPLONG count) /* ../dlls/advapi32/registry.c:402 */
{
	LSTATUS return_value;
	TRACE("Enter RegQueryValueW\n");
	return_value = pRegQueryValueW(hkey, name, data, count);
	TRACE("Leave RegQueryValueW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegReplaceKeyA(HKEY hkey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile) /* ../dlls/advapi32/registry.c:515 */
{
	LSTATUS return_value;
	TRACE("Enter RegReplaceKeyA\n");
	return_value = pRegReplaceKeyA(hkey, lpSubKey, lpNewFile, lpOldFile);
	TRACE("Leave RegReplaceKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegReplaceKeyW(HKEY hkey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile) /* ../dlls/advapi32/registry.c:501 */
{
	LSTATUS return_value;
	TRACE("Enter RegReplaceKeyW\n");
	return_value = pRegReplaceKeyW(hkey, lpSubKey, lpNewFile, lpOldFile);
	TRACE("Leave RegReplaceKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegSaveKeyA(HKEY hkey, LPCSTR file, LPSECURITY_ATTRIBUTES sa) /* ../dlls/advapi32/registry.c:480 */
{
	LSTATUS return_value;
	TRACE("Enter RegSaveKeyA\n");
	return_value = pRegSaveKeyA(hkey, file, sa);
	TRACE("Leave RegSaveKeyA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegSaveKeyW(HKEY hkey, LPCWSTR file, LPSECURITY_ATTRIBUTES sa) /* ../dlls/advapi32/registry.c:469 */
{
	LSTATUS return_value;
	TRACE("Enter RegSaveKeyW\n");
	return_value = pRegSaveKeyW(hkey, file, sa);
	TRACE("Leave RegSaveKeyW\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegSetValueA(HKEY hkey, LPCSTR subkey, DWORD type, LPCSTR data, DWORD count) /* ../dlls/advapi32/registry.c:376 */
{
	LSTATUS return_value;
	TRACE("Enter RegSetValueA\n");
	return_value = pRegSetValueA(hkey, subkey, type, data, count);
	TRACE("Leave RegSetValueA\n");
	return return_value;
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

WINAPI LSTATUS wine32b_advapi32_RegSetValueW(HKEY hkey, LPCWSTR subkey, DWORD type, LPCWSTR data, DWORD count) /* ../dlls/advapi32/registry.c:362 */
{
	LSTATUS return_value;
	TRACE("Enter RegSetValueW\n");
	return_value = pRegSetValueW(hkey, subkey, type, data, count);
	TRACE("Leave RegSetValueW\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_RegisterEventSourceA(LPCSTR lpUNCServerName, LPCSTR lpSourceName) /* ../dlls/advapi32/eventlog.c:611 */
{
	HANDLE return_value;
	TRACE("Enter RegisterEventSourceA\n");
	return_value = pRegisterEventSourceA(lpUNCServerName, lpSourceName);
	TRACE("Leave RegisterEventSourceA\n");
	return return_value;
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

WINAPI HANDLE wine32b_advapi32_RegisterEventSourceW(LPCWSTR lpUNCServerName, LPCWSTR lpSourceName) /* ../dlls/advapi32/eventlog.c:632 */
{
	HANDLE return_value;
	TRACE("Enter RegisterEventSourceW\n");
	return_value = pRegisterEventSourceW(lpUNCServerName, lpSourceName);
	TRACE("Leave RegisterEventSourceW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_RegisterWaitChainCOMCallback(PCOGETCALLSTATE call_state_cb, PCOGETACTIVATIONSTATE activation_state_cb) /* ../dlls/advapi32/advapi.c:347 */
{
	TRACE("Enter RegisterWaitChainCOMCallback\n");
	pRegisterWaitChainCOMCallback(call_state_cb, activation_state_cb);
	TRACE("Leave RegisterWaitChainCOMCallback\n");
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

WINAPI BOOL wine32b_advapi32_ReportEventA(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCSTR* lpStrings, LPVOID lpRawData) /* ../dlls/advapi32/eventlog.c:663 */
{
	BOOL return_value;
	TRACE("Enter ReportEventA\n");
	return_value = pReportEventA(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
	TRACE("Leave ReportEventA\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_ReportEventW(HANDLE hEventLog, WORD wType, WORD wCategory, DWORD dwEventID, PSID lpUserSid, WORD wNumStrings, DWORD dwDataSize, LPCWSTR* lpStrings, LPVOID lpRawData) /* ../dlls/advapi32/eventlog.c:696 */
{
	BOOL return_value;
	TRACE("Enter ReportEventW\n");
	return_value = pReportEventW(hEventLog, wType, wCategory, dwEventID, lpUserSid, wNumStrings, dwDataSize, lpStrings, lpRawData);
	TRACE("Leave ReportEventW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferCloseLevel(SAFER_LEVEL_HANDLE handle) /* ../dlls/advapi32/security.c:4454 */
{
	BOOL return_value;
	TRACE("Enter SaferCloseLevel\n");
	return_value = pSaferCloseLevel(handle);
	TRACE("Leave SaferCloseLevel\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferComputeTokenFromLevel(SAFER_LEVEL_HANDLE handle, HANDLE token, PHANDLE access_token, DWORD flags, LPVOID reserved) /* ../dlls/advapi32/security.c:4442 */
{
	BOOL return_value;
	TRACE("Enter SaferComputeTokenFromLevel\n");
	return_value = pSaferComputeTokenFromLevel(handle, token, access_token, flags, reserved);
	TRACE("Leave SaferComputeTokenFromLevel\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferCreateLevel(DWORD ScopeId, DWORD LevelId, DWORD OpenFlags, SAFER_LEVEL_HANDLE* LevelHandle, LPVOID lpReserved) /* ../dlls/advapi32/security.c:4430 */
{
	BOOL return_value;
	TRACE("Enter SaferCreateLevel\n");
	return_value = pSaferCreateLevel(ScopeId, LevelId, OpenFlags, LevelHandle, lpReserved);
	TRACE("Leave SaferCreateLevel\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferGetPolicyInformation(DWORD scope, SAFER_POLICY_INFO_CLASS class, DWORD size, PVOID buffer, PDWORD required, LPVOID lpReserved) /* ../dlls/advapi32/security.c:4479 */
{
	BOOL return_value;
	TRACE("Enter SaferGetPolicyInformation\n");
	return_value = pSaferGetPolicyInformation(scope, class, size, buffer, required, lpReserved);
	TRACE("Leave SaferGetPolicyInformation\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferIdentifyLevel(DWORD count, SAFER_CODE_PROPERTIES* properties, SAFER_LEVEL_HANDLE* handle, void* reserved) /* ../dlls/advapi32/security.c:4489 */
{
	BOOL return_value;
	TRACE("Enter SaferIdentifyLevel\n");
	return_value = pSaferIdentifyLevel(count, properties, handle, reserved);
	TRACE("Leave SaferIdentifyLevel\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SaferSetLevelInformation(SAFER_LEVEL_HANDLE handle, SAFER_OBJECT_INFO_CLASS infotype, LPVOID buffer, DWORD size) /* ../dlls/advapi32/security.c:4500 */
{
	BOOL return_value;
	TRACE("Enter SaferSetLevelInformation\n");
	return_value = pSaferSetLevelInformation(handle, infotype, buffer, size);
	TRACE("Leave SaferSetLevelInformation\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_SetEntriesInAclA(ULONG count, PEXPLICIT_ACCESSA pEntries, PACL OldAcl, PACL* NewAcl) /* ../dlls/advapi32/security.c:2349 */
{
	DWORD return_value;
	TRACE("Enter SetEntriesInAclA\n");
	return_value = pSetEntriesInAclA(count, pEntries, OldAcl, NewAcl);
	TRACE("Leave SetEntriesInAclA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_SetEntriesInAclW(ULONG count, PEXPLICIT_ACCESSW pEntries, PACL OldAcl, PACL* NewAcl) /* ../dlls/advapi32/security.c:2407 */
{
	DWORD return_value;
	TRACE("Enter SetEntriesInAclW\n");
	return_value = pSetEntriesInAclW(count, pEntries, OldAcl, NewAcl);
	TRACE("Leave SetEntriesInAclW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SetFileSecurityA(LPCSTR lpFileName, SECURITY_INFORMATION RequestedInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor) /* ../dlls/advapi32/security.c:1295 */
{
	BOOL return_value;
	TRACE("Enter SetFileSecurityA\n");
	return_value = pSetFileSecurityA(lpFileName, RequestedInformation, pSecurityDescriptor);
	TRACE("Leave SetFileSecurityA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_SetNamedSecurityInfoA(LPSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl) /* ../dlls/advapi32/security.c:2623 */
{
	DWORD return_value;
	TRACE("Enter SetNamedSecurityInfoA\n");
	return_value = pSetNamedSecurityInfoA(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
	TRACE("Leave SetNamedSecurityInfoA\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_SetNamedSecurityInfoW(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl) /* ../dlls/advapi32/security.c:2645 */
{
	DWORD return_value;
	TRACE("Enter SetNamedSecurityInfoW\n");
	return_value = pSetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
	TRACE("Leave SetNamedSecurityInfoW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_SetSecurityInfo(HANDLE handle, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID psidOwner, PSID psidGroup, PACL pDacl, PACL pSacl) /* ../dlls/advapi32/security.c:4300 */
{
	DWORD return_value;
	TRACE("Enter SetSecurityInfo\n");
	return_value = pSetSecurityInfo(handle, ObjectType, SecurityInfo, psidOwner, psidGroup, pDacl, pSacl);
	TRACE("Leave SetSecurityInfo\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_StartTraceA(PTRACEHANDLE pSessionHandle, LPCSTR SessionName, PEVENT_TRACE_PROPERTIES Properties) /* ../dlls/advapi32/eventlog.c:749 */
{
	ULONG return_value;
	TRACE("Enter StartTraceA\n");
	return_value = pStartTraceA(pSessionHandle, SessionName, Properties);
	TRACE("Leave StartTraceA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_StartTraceW(PTRACEHANDLE pSessionHandle, LPCWSTR SessionName, PEVENT_TRACE_PROPERTIES Properties) /* ../dlls/advapi32/eventlog.c:736 */
{
	ULONG return_value;
	TRACE("Enter StartTraceW\n");
	return_value = pStartTraceW(pSessionHandle, SessionName, Properties);
	TRACE("Leave StartTraceW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_StopTraceA(TRACEHANDLE session, LPCSTR session_name, PEVENT_TRACE_PROPERTIES properties) /* ../dlls/advapi32/eventlog.c:774 */
{
	ULONG return_value;
	TRACE("Enter StopTraceA\n");
	return_value = pStopTraceA(session, session_name, properties);
	TRACE("Leave StopTraceA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_StopTraceW(TRACEHANDLE session, LPCWSTR session_name, PEVENT_TRACE_PROPERTIES properties) /* ../dlls/advapi32/eventlog.c:762 */
{
	ULONG return_value;
	TRACE("Enter StopTraceW\n");
	return_value = pStopTraceW(session, session_name, properties);
	TRACE("Leave StopTraceW\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SynchronizeWindows31FilesAndWindowsNTRegistry(DWORD x1, DWORD x2, DWORD x3, DWORD x4) /* ../dlls/advapi32/security.c:1332 */
{
	BOOL return_value;
	TRACE("Enter SynchronizeWindows31FilesAndWindowsNTRegistry\n");
	return_value = pSynchronizeWindows31FilesAndWindowsNTRegistry(x1, x2, x3, x4);
	TRACE("Leave SynchronizeWindows31FilesAndWindowsNTRegistry\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction001(BYTE* data, BYTE* key, LPBYTE output) /* ../dlls/advapi32/crypt_lmhash.c:116 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction001\n");
	return_value = pSystemFunction001(data, key, output);
	TRACE("Leave SystemFunction001\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction002(BYTE* data, BYTE* key, LPBYTE output) /* ../dlls/advapi32/crypt_lmhash.c:139 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction002\n");
	return_value = pSystemFunction002(data, key, output);
	TRACE("Leave SystemFunction002\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction003(BYTE* key, LPBYTE output) /* ../dlls/advapi32/crypt_lmhash.c:161 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction003\n");
	return_value = pSystemFunction003(key, output);
	TRACE("Leave SystemFunction003\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction004(struct ustring* in, struct ustring* key, struct ustring* out) /* ../dlls/advapi32/crypt_lmhash.c:188 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction004\n");
	return_value = pSystemFunction004(in, key, out);
	TRACE("Leave SystemFunction004\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction005(struct ustring* in, struct ustring* key, struct ustring* out) /* ../dlls/advapi32/crypt_lmhash.c:247 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction005\n");
	return_value = pSystemFunction005(in, key, out);
	TRACE("Leave SystemFunction005\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction006(LPCSTR password, LPSTR hash) /* ../dlls/advapi32/crypt_lmhash.c:49 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction006\n");
	return_value = pSystemFunction006(password, hash);
	TRACE("Leave SystemFunction006\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction007(UNICODE_STRING* string, LPBYTE hash) /* ../dlls/advapi32/crypt.c:2354 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction007\n");
	return_value = pSystemFunction007(string, hash);
	TRACE("Leave SystemFunction007\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction008(BYTE* challenge, BYTE* hash, LPBYTE response) /* ../dlls/advapi32/crypt_lmhash.c:74 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction008\n");
	return_value = pSystemFunction008(challenge, hash, response);
	TRACE("Leave SystemFunction008\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction009(BYTE* challenge, BYTE* hash, LPBYTE response) /* ../dlls/advapi32/crypt_lmhash.c:96 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction009\n");
	return_value = pSystemFunction009(challenge, hash, response);
	TRACE("Leave SystemFunction009\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction010(LPVOID unknown, BYTE* data, LPBYTE hash) /* ../dlls/advapi32/crypt.c:2382 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction010\n");
	return_value = pSystemFunction010(unknown, data, hash);
	TRACE("Leave SystemFunction010\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction012(BYTE* in, BYTE* key, LPBYTE out) /* ../dlls/advapi32/crypt_lmhash.c:311 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction012\n");
	return_value = pSystemFunction012(in, key, out);
	TRACE("Leave SystemFunction012\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction013(BYTE* in, BYTE* key, LPBYTE out) /* ../dlls/advapi32/crypt_lmhash.c:340 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction013\n");
	return_value = pSystemFunction013(in, key, out);
	TRACE("Leave SystemFunction013\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction024(BYTE* in, BYTE* key, LPBYTE out) /* ../dlls/advapi32/crypt_lmhash.c:363 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction024\n");
	return_value = pSystemFunction024(in, key, out);
	TRACE("Leave SystemFunction024\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction025(BYTE* in, BYTE* key, LPBYTE out) /* ../dlls/advapi32/crypt_lmhash.c:391 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction025\n");
	return_value = pSystemFunction025(in, key, out);
	TRACE("Leave SystemFunction025\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SystemFunction030(LPCVOID b1, LPCVOID b2) /* ../dlls/advapi32/crypt.c:2406 */
{
	BOOL return_value;
	TRACE("Enter SystemFunction030\n");
	return_value = pSystemFunction030(b1, b2);
	TRACE("Leave SystemFunction030\n");
	return return_value;
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

WINAPI NTSTATUS wine32b_advapi32_SystemFunction032(struct ustring* data, struct ustring* key) /* ../dlls/advapi32/crypt_arc4.c:97 */
{
	NTSTATUS return_value;
	TRACE("Enter SystemFunction032\n");
	return_value = pSystemFunction032(data, key);
	TRACE("Leave SystemFunction032\n");
	return return_value;
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

WINAPI BOOL wine32b_advapi32_SystemFunction035(LPCSTR lpszDllFilePath) /* ../dlls/advapi32/crypt.c:2420 */
{
	BOOL return_value;
	TRACE("Enter SystemFunction035\n");
	return_value = pSystemFunction035(lpszDllFilePath);
	TRACE("Leave SystemFunction035\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_TraceSetInformation(TRACEHANDLE handle, TRACE_INFO_CLASS infoclass, void* info, ULONG len) /* ../dlls/advapi32/eventlog.c:844 */
{
	ULONG return_value;
	TRACE("Enter TraceSetInformation\n");
	return_value = pTraceSetInformation(handle, infoclass, info, len);
	TRACE("Leave TraceSetInformation\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_TreeResetNamedSecurityInfoW(LPWSTR pObjectName, SE_OBJECT_TYPE ObjectType, SECURITY_INFORMATION SecurityInfo, PSID pOwner, PSID pGroup, PACL pDacl, PACL pSacl, BOOL KeepExplicit, FN_PROGRESS fnProgress, PROG_INVOKE_SETTING ProgressInvokeSetting, PVOID Args) /* ../dlls/advapi32/security.c:4463 */
{
	DWORD return_value;
	TRACE("Enter TreeResetNamedSecurityInfoW\n");
	return_value = pTreeResetNamedSecurityInfoW(pObjectName, ObjectType, SecurityInfo, pOwner, pGroup, pDacl, pSacl, KeepExplicit, fnProgress, ProgressInvokeSetting, Args);
	TRACE("Leave TreeResetNamedSecurityInfoW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiExecuteMethodA(WMIHANDLE handle, char* name, ULONG method, ULONG inputsize, void* inputbuffer, ULONG* outputsize, void* outputbuffer) /* ../dlls/advapi32/wmi.c:42 */
{
	ULONG return_value;
	TRACE("Enter WmiExecuteMethodA\n");
	return_value = pWmiExecuteMethodA(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
	TRACE("Leave WmiExecuteMethodA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiExecuteMethodW(WMIHANDLE handle, WCHAR* name, ULONG method, ULONG inputsize, void* inputbuffer, ULONG* outputsize, void* outputbuffer) /* ../dlls/advapi32/wmi.c:53 */
{
	ULONG return_value;
	TRACE("Enter WmiExecuteMethodW\n");
	return_value = pWmiExecuteMethodW(handle, name, method, inputsize, inputbuffer, outputsize, outputbuffer);
	TRACE("Leave WmiExecuteMethodW\n");
	return return_value;
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

WINAPI void wine32b_advapi32_WmiFreeBuffer(void* buffer) /* ../dlls/advapi32/wmi.c:64 */
{
	TRACE("Enter WmiFreeBuffer\n");
	pWmiFreeBuffer(buffer);
	TRACE("Leave WmiFreeBuffer\n");
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

WINAPI ULONG wine32b_advapi32_WmiMofEnumerateResourcesA(MOFHANDLE handle, ULONG* count, MOFRESOURCEINFOA** resource) /* ../dlls/advapi32/wmi.c:72 */
{
	ULONG return_value;
	TRACE("Enter WmiMofEnumerateResourcesA\n");
	return_value = pWmiMofEnumerateResourcesA(handle, count, resource);
	TRACE("Leave WmiMofEnumerateResourcesA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiMofEnumerateResourcesW(MOFHANDLE handle, ULONG* count, MOFRESOURCEINFOW** resource) /* ../dlls/advapi32/wmi.c:81 */
{
	ULONG return_value;
	TRACE("Enter WmiMofEnumerateResourcesW\n");
	return_value = pWmiMofEnumerateResourcesW(handle, count, resource);
	TRACE("Leave WmiMofEnumerateResourcesW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiNotificationRegistrationA(GUID* guid, BOOLEAN enable, void* info, ULONG_PTR context, ULONG flags) /* ../dlls/advapi32/wmi.c:90 */
{
	ULONG return_value;
	TRACE("Enter WmiNotificationRegistrationA\n");
	return_value = pWmiNotificationRegistrationA(guid, enable, info, context, flags);
	TRACE("Leave WmiNotificationRegistrationA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiNotificationRegistrationW(GUID* guid, BOOLEAN enable, void* info, ULONG_PTR context, ULONG flags) /* ../dlls/advapi32/wmi.c:100 */
{
	ULONG return_value;
	TRACE("Enter WmiNotificationRegistrationW\n");
	return_value = pWmiNotificationRegistrationW(guid, enable, info, context, flags);
	TRACE("Leave WmiNotificationRegistrationW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiOpenBlock(GUID* guid, ULONG access, WMIHANDLE* handle) /* ../dlls/advapi32/wmi.c:110 */
{
	ULONG return_value;
	TRACE("Enter WmiOpenBlock\n");
	return_value = pWmiOpenBlock(guid, access, handle);
	TRACE("Leave WmiOpenBlock\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiQueryAllDataA(WMIHANDLE handle, ULONG* size, void* buffer) /* ../dlls/advapi32/wmi.c:119 */
{
	ULONG return_value;
	TRACE("Enter WmiQueryAllDataA\n");
	return_value = pWmiQueryAllDataA(handle, size, buffer);
	TRACE("Leave WmiQueryAllDataA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiQueryAllDataW(WMIHANDLE handle, ULONG* size, void* buffer) /* ../dlls/advapi32/wmi.c:128 */
{
	ULONG return_value;
	TRACE("Enter WmiQueryAllDataW\n");
	return_value = pWmiQueryAllDataW(handle, size, buffer);
	TRACE("Leave WmiQueryAllDataW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiQueryGuidInformation(WMIHANDLE handle, WMIGUIDINFORMATION* info) /* ../dlls/advapi32/wmi.c:137 */
{
	ULONG return_value;
	TRACE("Enter WmiQueryGuidInformation\n");
	return_value = pWmiQueryGuidInformation(handle, info);
	TRACE("Leave WmiQueryGuidInformation\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiSetSingleInstanceA(WMIHANDLE handle, char* name, ULONG reserved, ULONG size, void* buffer) /* ../dlls/advapi32/wmi.c:146 */
{
	ULONG return_value;
	TRACE("Enter WmiSetSingleInstanceA\n");
	return_value = pWmiSetSingleInstanceA(handle, name, reserved, size, buffer);
	TRACE("Leave WmiSetSingleInstanceA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiSetSingleInstanceW(WMIHANDLE handle, WCHAR* name, ULONG reserved, ULONG size, void* buffer) /* ../dlls/advapi32/wmi.c:156 */
{
	ULONG return_value;
	TRACE("Enter WmiSetSingleInstanceW\n");
	return_value = pWmiSetSingleInstanceW(handle, name, reserved, size, buffer);
	TRACE("Leave WmiSetSingleInstanceW\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiSetSingleItemA(WMIHANDLE handle, char* name, ULONG id, ULONG reserved, ULONG size, void* buffer) /* ../dlls/advapi32/wmi.c:166 */
{
	ULONG return_value;
	TRACE("Enter WmiSetSingleItemA\n");
	return_value = pWmiSetSingleItemA(handle, name, id, reserved, size, buffer);
	TRACE("Leave WmiSetSingleItemA\n");
	return return_value;
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

WINAPI ULONG wine32b_advapi32_WmiSetSingleItemW(WMIHANDLE handle, WCHAR* name, ULONG id, ULONG reserved, ULONG size, void* buffer) /* ../dlls/advapi32/wmi.c:176 */
{
	ULONG return_value;
	TRACE("Enter WmiSetSingleItemW\n");
	return_value = pWmiSetSingleItemW(handle, name, id, reserved, size, buffer);
	TRACE("Leave WmiSetSingleItemW\n");
	return return_value;
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

WINAPI DWORD wine32b_advapi32_WriteEncryptedFileRaw(PFE_IMPORT_FUNC import, PVOID callback, PVOID context) /* ../dlls/advapi32/crypt.c:2534 */
{
	DWORD return_value;
	TRACE("Enter WriteEncryptedFileRaw\n");
	return_value = pWriteEncryptedFileRaw(import, callback, context);
	TRACE("Leave WriteEncryptedFileRaw\n");
	return return_value;
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
	HMODULE library = GetModuleHandleA("advapi32.dll");	HMODULE library_kernel32 = GetModuleHandleA("kernel32.dll");
	HMODULE library_ntdll = GetModuleHandleA("ntdll.dll");
	pAbortSystemShutdownA = (void *)GetProcAddress(library, "AbortSystemShutdownA");
	pAbortSystemShutdownW = (void *)GetProcAddress(library, "AbortSystemShutdownW");
	pAccessCheckAndAuditAlarmA = (void *)GetProcAddress(library, "AccessCheckAndAuditAlarmA");
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
	pCreateProcessWithLogonW = (void *)GetProcAddress(library, "CreateProcessWithLogonW");
	pCreateProcessWithTokenW = (void *)GetProcAddress(library, "CreateProcessWithTokenW");
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
	pDeregisterEventSource = (void *)GetProcAddress(library, "DeregisterEventSource");
	pEnableTrace = (void *)GetProcAddress(library, "EnableTrace");
	pEnableTraceEx = (void *)GetProcAddress(library, "EnableTraceEx");
	pEnableTraceEx2 = (void *)GetProcAddress(library, "EnableTraceEx2");
	pEncryptFileA = (void *)GetProcAddress(library, "EncryptFileA");
	pEncryptFileW = (void *)GetProcAddress(library, "EncryptFileW");
	pEnumerateTraceGuids = (void *)GetProcAddress(library, "EnumerateTraceGuids");
	pFileEncryptionStatusA = (void *)GetProcAddress(library, "FileEncryptionStatusA");
	pFileEncryptionStatusW = (void *)GetProcAddress(library, "FileEncryptionStatusW");
	pFlushTraceA = (void *)GetProcAddress(library, "FlushTraceA");
	pFlushTraceW = (void *)GetProcAddress(library, "FlushTraceW");
	pGetAuditedPermissionsFromAclA = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclA");
	pGetAuditedPermissionsFromAclW = (void *)GetProcAddress(library, "GetAuditedPermissionsFromAclW");
	pGetCurrentHwProfileA = (void *)GetProcAddress(library, "GetCurrentHwProfileA");
	pGetCurrentHwProfileW = (void *)GetProcAddress(library, "GetCurrentHwProfileW");
	pGetEffectiveRightsFromAclA = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclA");
	pGetEffectiveRightsFromAclW = (void *)GetProcAddress(library, "GetEffectiveRightsFromAclW");
	pGetEventLogInformation = (void *)GetProcAddress(library, "GetEventLogInformation");
	pGetExplicitEntriesFromAclA = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclA");
	pGetExplicitEntriesFromAclW = (void *)GetProcAddress(library, "GetExplicitEntriesFromAclW");
	pGetFileSecurityA = (void *)GetProcAddress(library, "GetFileSecurityA");
	pGetNamedSecurityInfoA = (void *)GetProcAddress(library, "GetNamedSecurityInfoA");
	pGetNamedSecurityInfoExA = (void *)GetProcAddress(library, "GetNamedSecurityInfoExA");
	pGetNamedSecurityInfoExW = (void *)GetProcAddress(library, "GetNamedSecurityInfoExW");
	pGetNamedSecurityInfoW = (void *)GetProcAddress(library, "GetNamedSecurityInfoW");
	pGetNumberOfEventLogRecords = (void *)GetProcAddress(library, "GetNumberOfEventLogRecords");
	pGetOldestEventLogRecord = (void *)GetProcAddress(library, "GetOldestEventLogRecord");
	pGetSecurityInfo = (void *)GetProcAddress(library, "GetSecurityInfo");
	pGetSecurityInfoExA = (void *)GetProcAddress(library, "GetSecurityInfoExA");
	pGetSecurityInfoExW = (void *)GetProcAddress(library, "GetSecurityInfoExW");
	pGetTrusteeFormA = (void *)GetProcAddress(library, "GetTrusteeFormA");
	pGetTrusteeFormW = (void *)GetProcAddress(library, "GetTrusteeFormW");
	pGetTrusteeNameA = (void *)GetProcAddress(library, "GetTrusteeNameA");
	pGetTrusteeNameW = (void *)GetProcAddress(library, "GetTrusteeNameW");
	pGetTrusteeTypeA = (void *)GetProcAddress(library, "GetTrusteeTypeA");
	pGetTrusteeTypeW = (void *)GetProcAddress(library, "GetTrusteeTypeW");
	pGetUserNameA = (void *)GetProcAddress(library, "GetUserNameA");
	pGetUserNameW = (void *)GetProcAddress(library, "GetUserNameW");
	pInitiateShutdownA = (void *)GetProcAddress(library, "InitiateShutdownA");
	pInitiateShutdownW = (void *)GetProcAddress(library, "InitiateShutdownW");
	pInitiateSystemShutdownA = (void *)GetProcAddress(library, "InitiateSystemShutdownA");
	pInitiateSystemShutdownExA = (void *)GetProcAddress(library, "InitiateSystemShutdownExA");
	pInitiateSystemShutdownExW = (void *)GetProcAddress(library, "InitiateSystemShutdownExW");
	pInitiateSystemShutdownW = (void *)GetProcAddress(library, "InitiateSystemShutdownW");
	pIsTextUnicode = (void *)GetProcAddress(library, "IsTextUnicode");
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
	pNotifyBootConfigStatus = (void *)GetProcAddress(library, "NotifyBootConfigStatus");
	pNotifyChangeEventLog = (void *)GetProcAddress(library, "NotifyChangeEventLog");
	pObjectCloseAuditAlarmA = (void *)GetProcAddress(library, "ObjectCloseAuditAlarmA");
	pObjectOpenAuditAlarmA = (void *)GetProcAddress(library, "ObjectOpenAuditAlarmA");
	pObjectPrivilegeAuditAlarmA = (void *)GetProcAddress(library, "ObjectPrivilegeAuditAlarmA");
	pOpenBackupEventLogA = (void *)GetProcAddress(library, "OpenBackupEventLogA");
	pOpenBackupEventLogW = (void *)GetProcAddress(library, "OpenBackupEventLogW");
	pOpenEncryptedFileRawA = (void *)GetProcAddress(library, "OpenEncryptedFileRawA");
	pOpenEncryptedFileRawW = (void *)GetProcAddress(library, "OpenEncryptedFileRawW");
	pOpenEventLogA = (void *)GetProcAddress(library, "OpenEventLogA");
	pOpenEventLogW = (void *)GetProcAddress(library, "OpenEventLogW");
	pOpenTraceA = (void *)GetProcAddress(library, "OpenTraceA");
	pOpenTraceW = (void *)GetProcAddress(library, "OpenTraceW");
	pPrivilegedServiceAuditAlarmA = (void *)GetProcAddress(library, "PrivilegedServiceAuditAlarmA");
	pProcessTrace = (void *)GetProcAddress(library, "ProcessTrace");
	pQueryAllTracesA = (void *)GetProcAddress(library, "QueryAllTracesA");
	pQueryAllTracesW = (void *)GetProcAddress(library, "QueryAllTracesW");
	pQueryTraceW = (void *)GetProcAddress(library, "QueryTraceW");
	pQueryWindows31FilesMigration = (void *)GetProcAddress(library, "QueryWindows31FilesMigration");
	pReadEncryptedFileRaw = (void *)GetProcAddress(library, "ReadEncryptedFileRaw");
	pReadEventLogA = (void *)GetProcAddress(library, "ReadEventLogA");
	pReadEventLogW = (void *)GetProcAddress(library, "ReadEventLogW");
	pRegConnectRegistryA = (void *)GetProcAddress(library, "RegConnectRegistryA");
	pRegConnectRegistryW = (void *)GetProcAddress(library, "RegConnectRegistryW");
	pRegCopyTreeA = (void *)GetProcAddress(library, "RegCopyTreeA");
	pRegCreateKeyA = (void *)GetProcAddress(library, "RegCreateKeyA");
	pRegCreateKeyTransactedA = (void *)GetProcAddress(library, "RegCreateKeyTransactedA");
	pRegCreateKeyTransactedW = (void *)GetProcAddress(library, "RegCreateKeyTransactedW");
	pRegCreateKeyW = (void *)GetProcAddress(library, "RegCreateKeyW");
	pRegDeleteKeyA = (void *)GetProcAddress(library, "RegDeleteKeyA");
	pRegDeleteKeyW = (void *)GetProcAddress(library, "RegDeleteKeyW");
	pRegDisablePredefinedCache = (void *)GetProcAddress(library, "RegDisablePredefinedCache");
	pRegDisableReflectionKey = (void *)GetProcAddress(library, "RegDisableReflectionKey");
	pRegEnumKeyA = (void *)GetProcAddress(library, "RegEnumKeyA");
	pRegEnumKeyW = (void *)GetProcAddress(library, "RegEnumKeyW");
	pRegOpenKeyA = (void *)GetProcAddress(library, "RegOpenKeyA");
	pRegOpenKeyW = (void *)GetProcAddress(library, "RegOpenKeyW");
	pRegOverridePredefKey = (void *)GetProcAddress(library, "RegOverridePredefKey");
	pRegQueryMultipleValuesA = (void *)GetProcAddress(library, "RegQueryMultipleValuesA");
	pRegQueryMultipleValuesW = (void *)GetProcAddress(library, "RegQueryMultipleValuesW");
	pRegQueryReflectionKey = (void *)GetProcAddress(library, "RegQueryReflectionKey");
	pRegQueryValueA = (void *)GetProcAddress(library, "RegQueryValueA");
	pRegQueryValueW = (void *)GetProcAddress(library, "RegQueryValueW");
	pRegReplaceKeyA = (void *)GetProcAddress(library, "RegReplaceKeyA");
	pRegReplaceKeyW = (void *)GetProcAddress(library, "RegReplaceKeyW");
	pRegSaveKeyA = (void *)GetProcAddress(library, "RegSaveKeyA");
	pRegSaveKeyW = (void *)GetProcAddress(library, "RegSaveKeyW");
	pRegSetValueA = (void *)GetProcAddress(library, "RegSetValueA");
	pRegSetValueW = (void *)GetProcAddress(library, "RegSetValueW");
	pRegisterEventSourceA = (void *)GetProcAddress(library, "RegisterEventSourceA");
	pRegisterEventSourceW = (void *)GetProcAddress(library, "RegisterEventSourceW");
	pRegisterWaitChainCOMCallback = (void *)GetProcAddress(library, "RegisterWaitChainCOMCallback");
	pReportEventA = (void *)GetProcAddress(library, "ReportEventA");
	pReportEventW = (void *)GetProcAddress(library, "ReportEventW");
	pSaferCloseLevel = (void *)GetProcAddress(library, "SaferCloseLevel");
	pSaferComputeTokenFromLevel = (void *)GetProcAddress(library, "SaferComputeTokenFromLevel");
	pSaferCreateLevel = (void *)GetProcAddress(library, "SaferCreateLevel");
	pSaferGetPolicyInformation = (void *)GetProcAddress(library, "SaferGetPolicyInformation");
	pSaferIdentifyLevel = (void *)GetProcAddress(library, "SaferIdentifyLevel");
	pSaferSetLevelInformation = (void *)GetProcAddress(library, "SaferSetLevelInformation");
	pSetEntriesInAclA = (void *)GetProcAddress(library, "SetEntriesInAclA");
	pSetEntriesInAclW = (void *)GetProcAddress(library, "SetEntriesInAclW");
	pSetFileSecurityA = (void *)GetProcAddress(library, "SetFileSecurityA");
	pSetNamedSecurityInfoA = (void *)GetProcAddress(library, "SetNamedSecurityInfoA");
	pSetNamedSecurityInfoW = (void *)GetProcAddress(library, "SetNamedSecurityInfoW");
	pSetSecurityInfo = (void *)GetProcAddress(library, "SetSecurityInfo");
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
	pTraceSetInformation = (void *)GetProcAddress(library, "TraceSetInformation");
	pTreeResetNamedSecurityInfoW = (void *)GetProcAddress(library, "TreeResetNamedSecurityInfoW");
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
	pA_SHAFinal = (void *)GetProcAddress(library, "A_SHAFinal");
	pextA_SHAFinal = (void *)GetProcAddress(library_ntdll, "A_SHAFinal");
	pA_SHAInit = (void *)GetProcAddress(library, "A_SHAInit");
	pextA_SHAInit = (void *)GetProcAddress(library_ntdll, "A_SHAInit");
	pA_SHAUpdate = (void *)GetProcAddress(library, "A_SHAUpdate");
	pextA_SHAUpdate = (void *)GetProcAddress(library_ntdll, "A_SHAUpdate");
	pCreateProcessAsUserA = (void *)GetProcAddress(library, "CreateProcessAsUserA");
	pextCreateProcessAsUserA = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserA");
	pCreateProcessAsUserW = (void *)GetProcAddress(library, "CreateProcessAsUserW");
	pextCreateProcessAsUserW = (void *)GetProcAddress(library_kernel32, "CreateProcessAsUserW");
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
	pGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library, "GetDynamicTimeZoneInformationEffectiveYears");
	pextGetDynamicTimeZoneInformationEffectiveYears = (void *)GetProcAddress(library_kernel32, "GetDynamicTimeZoneInformationEffectiveYears");
	pGetTraceEnableFlags = (void *)GetProcAddress(library, "GetTraceEnableFlags");
	pextGetTraceEnableFlags = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableFlags");
	pGetTraceEnableLevel = (void *)GetProcAddress(library, "GetTraceEnableLevel");
	pextGetTraceEnableLevel = (void *)GetProcAddress(library_ntdll, "EtwGetTraceEnableLevel");
	pGetTraceLoggerHandle = (void *)GetProcAddress(library, "GetTraceLoggerHandle");
	pextGetTraceLoggerHandle = (void *)GetProcAddress(library_ntdll, "EtwGetTraceLoggerHandle");
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
	pRegisterTraceGuidsA = (void *)GetProcAddress(library, "RegisterTraceGuidsA");
	pextRegisterTraceGuidsA = (void *)GetProcAddress(library_ntdll, "EtwRegisterTraceGuidsA");
	pRegisterTraceGuidsW = (void *)GetProcAddress(library, "RegisterTraceGuidsW");
	pextRegisterTraceGuidsW = (void *)GetProcAddress(library_ntdll, "EtwRegisterTraceGuidsW");
	pTraceEvent = (void *)GetProcAddress(library, "TraceEvent");
	pextTraceEvent = (void *)GetProcAddress(library_ntdll, "EtwLogTraceEvent");
	pTraceMessage = (void *)GetProcAddress(library, "TraceMessage");
	pextTraceMessage = (void *)GetProcAddress(library_ntdll, "EtwTraceMessage");
	pTraceMessageVa = (void *)GetProcAddress(library, "TraceMessageVa");
	pextTraceMessageVa = (void *)GetProcAddress(library_ntdll, "EtwTraceMessageVa");
	pUnregisterTraceGuids = (void *)GetProcAddress(library, "UnregisterTraceGuids");
	pextUnregisterTraceGuids = (void *)GetProcAddress(library_ntdll, "EtwUnregisterTraceGuids");
	initialized = TRUE;
}

void* wine_thunk_get_for_advapi32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pAbortSystemShutdownA)
		return wine32a_advapi32_AbortSystemShutdownA;
	if (func == pAbortSystemShutdownW)
		return wine32a_advapi32_AbortSystemShutdownW;
	if (func == pAccessCheckAndAuditAlarmA)
		return wine32a_advapi32_AccessCheckAndAuditAlarmA;
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
	if (func == pCreateProcessWithLogonW)
		return wine32a_advapi32_CreateProcessWithLogonW;
	if (func == pCreateProcessWithTokenW)
		return wine32a_advapi32_CreateProcessWithTokenW;
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
	if (func == pDeregisterEventSource)
		return wine32a_advapi32_DeregisterEventSource;
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
	if (func == pEnumerateTraceGuids)
		return wine32a_advapi32_EnumerateTraceGuids;
	if (func == pFileEncryptionStatusA)
		return wine32a_advapi32_FileEncryptionStatusA;
	if (func == pFileEncryptionStatusW)
		return wine32a_advapi32_FileEncryptionStatusW;
	if (func == pFlushTraceA)
		return wine32a_advapi32_FlushTraceA;
	if (func == pFlushTraceW)
		return wine32a_advapi32_FlushTraceW;
	if (func == pGetAuditedPermissionsFromAclA)
		return wine32a_advapi32_GetAuditedPermissionsFromAclA;
	if (func == pGetAuditedPermissionsFromAclW)
		return wine32a_advapi32_GetAuditedPermissionsFromAclW;
	if (func == pGetCurrentHwProfileA)
		return wine32a_advapi32_GetCurrentHwProfileA;
	if (func == pGetCurrentHwProfileW)
		return wine32a_advapi32_GetCurrentHwProfileW;
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
	if (func == pGetSecurityInfo)
		return wine32a_advapi32_GetSecurityInfo;
	if (func == pGetSecurityInfoExA)
		return wine32a_advapi32_GetSecurityInfoExA;
	if (func == pGetSecurityInfoExW)
		return wine32a_advapi32_GetSecurityInfoExW;
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
	if (func == pNotifyBootConfigStatus)
		return wine32a_advapi32_NotifyBootConfigStatus;
	if (func == pNotifyChangeEventLog)
		return wine32a_advapi32_NotifyChangeEventLog;
	if (func == pObjectCloseAuditAlarmA)
		return wine32a_advapi32_ObjectCloseAuditAlarmA;
	if (func == pObjectOpenAuditAlarmA)
		return wine32a_advapi32_ObjectOpenAuditAlarmA;
	if (func == pObjectPrivilegeAuditAlarmA)
		return wine32a_advapi32_ObjectPrivilegeAuditAlarmA;
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
	if (func == pOpenTraceA)
		return wine32a_advapi32_OpenTraceA;
	if (func == pOpenTraceW)
		return wine32a_advapi32_OpenTraceW;
	if (func == pPrivilegedServiceAuditAlarmA)
		return wine32a_advapi32_PrivilegedServiceAuditAlarmA;
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
	if (func == pRegConnectRegistryA)
		return wine32a_advapi32_RegConnectRegistryA;
	if (func == pRegConnectRegistryW)
		return wine32a_advapi32_RegConnectRegistryW;
	if (func == pRegCopyTreeA)
		return wine32a_advapi32_RegCopyTreeA;
	if (func == pRegCreateKeyA)
		return wine32a_advapi32_RegCreateKeyA;
	if (func == pRegCreateKeyTransactedA)
		return wine32a_advapi32_RegCreateKeyTransactedA;
	if (func == pRegCreateKeyTransactedW)
		return wine32a_advapi32_RegCreateKeyTransactedW;
	if (func == pRegCreateKeyW)
		return wine32a_advapi32_RegCreateKeyW;
	if (func == pRegDeleteKeyA)
		return wine32a_advapi32_RegDeleteKeyA;
	if (func == pRegDeleteKeyW)
		return wine32a_advapi32_RegDeleteKeyW;
	if (func == pRegDisablePredefinedCache)
		return wine32a_advapi32_RegDisablePredefinedCache;
	if (func == pRegDisableReflectionKey)
		return wine32a_advapi32_RegDisableReflectionKey;
	if (func == pRegEnumKeyA)
		return wine32a_advapi32_RegEnumKeyA;
	if (func == pRegEnumKeyW)
		return wine32a_advapi32_RegEnumKeyW;
	if (func == pRegOpenKeyA)
		return wine32a_advapi32_RegOpenKeyA;
	if (func == pRegOpenKeyW)
		return wine32a_advapi32_RegOpenKeyW;
	if (func == pRegOverridePredefKey)
		return wine32a_advapi32_RegOverridePredefKey;
	if (func == pRegQueryMultipleValuesA)
		return wine32a_advapi32_RegQueryMultipleValuesA;
	if (func == pRegQueryMultipleValuesW)
		return wine32a_advapi32_RegQueryMultipleValuesW;
	if (func == pRegQueryReflectionKey)
		return wine32a_advapi32_RegQueryReflectionKey;
	if (func == pRegQueryValueA)
		return wine32a_advapi32_RegQueryValueA;
	if (func == pRegQueryValueW)
		return wine32a_advapi32_RegQueryValueW;
	if (func == pRegReplaceKeyA)
		return wine32a_advapi32_RegReplaceKeyA;
	if (func == pRegReplaceKeyW)
		return wine32a_advapi32_RegReplaceKeyW;
	if (func == pRegSaveKeyA)
		return wine32a_advapi32_RegSaveKeyA;
	if (func == pRegSaveKeyW)
		return wine32a_advapi32_RegSaveKeyW;
	if (func == pRegSetValueA)
		return wine32a_advapi32_RegSetValueA;
	if (func == pRegSetValueW)
		return wine32a_advapi32_RegSetValueW;
	if (func == pRegisterEventSourceA)
		return wine32a_advapi32_RegisterEventSourceA;
	if (func == pRegisterEventSourceW)
		return wine32a_advapi32_RegisterEventSourceW;
	if (func == pRegisterWaitChainCOMCallback)
		return wine32a_advapi32_RegisterWaitChainCOMCallback;
	if (func == pReportEventA)
		return wine32a_advapi32_ReportEventA;
	if (func == pReportEventW)
		return wine32a_advapi32_ReportEventW;
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
	if (func == pSetEntriesInAclA)
		return wine32a_advapi32_SetEntriesInAclA;
	if (func == pSetEntriesInAclW)
		return wine32a_advapi32_SetEntriesInAclW;
	if (func == pSetFileSecurityA)
		return wine32a_advapi32_SetFileSecurityA;
	if (func == pSetNamedSecurityInfoA)
		return wine32a_advapi32_SetNamedSecurityInfoA;
	if (func == pSetNamedSecurityInfoW)
		return wine32a_advapi32_SetNamedSecurityInfoW;
	if (func == pSetSecurityInfo)
		return wine32a_advapi32_SetSecurityInfo;
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
	if (func == pTraceSetInformation)
		return wine32a_advapi32_TraceSetInformation;
	if (func == pTreeResetNamedSecurityInfoW)
		return wine32a_advapi32_TreeResetNamedSecurityInfoW;
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
	if (func == pA_SHAFinal && func != pextA_SHAFinal)
		return wine_thunk_get_for_any(pextA_SHAFinal);
	if (func == pA_SHAInit && func != pextA_SHAInit)
		return wine_thunk_get_for_any(pextA_SHAInit);
	if (func == pA_SHAUpdate && func != pextA_SHAUpdate)
		return wine_thunk_get_for_any(pextA_SHAUpdate);
	if (func == pCreateProcessAsUserA && func != pextCreateProcessAsUserA)
		return wine_thunk_get_for_any(pextCreateProcessAsUserA);
	if (func == pCreateProcessAsUserW && func != pextCreateProcessAsUserW)
		return wine_thunk_get_for_any(pextCreateProcessAsUserW);
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
	if (func == pGetDynamicTimeZoneInformationEffectiveYears && func != pextGetDynamicTimeZoneInformationEffectiveYears)
		return wine_thunk_get_for_any(pextGetDynamicTimeZoneInformationEffectiveYears);
	if (func == pGetTraceEnableFlags && func != pextGetTraceEnableFlags)
		return wine_thunk_get_for_any(pextGetTraceEnableFlags);
	if (func == pGetTraceEnableLevel && func != pextGetTraceEnableLevel)
		return wine_thunk_get_for_any(pextGetTraceEnableLevel);
	if (func == pGetTraceLoggerHandle && func != pextGetTraceLoggerHandle)
		return wine_thunk_get_for_any(pextGetTraceLoggerHandle);
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
	if (func == pRegisterTraceGuidsA && func != pextRegisterTraceGuidsA)
		return wine_thunk_get_for_any(pextRegisterTraceGuidsA);
	if (func == pRegisterTraceGuidsW && func != pextRegisterTraceGuidsW)
		return wine_thunk_get_for_any(pextRegisterTraceGuidsW);
	if (func == pTraceEvent && func != pextTraceEvent)
		return wine_thunk_get_for_any(pextTraceEvent);
	if (func == pTraceMessage && func != pextTraceMessage)
		return wine_thunk_get_for_any(pextTraceMessage);
	if (func == pTraceMessageVa && func != pextTraceMessageVa)
		return wine_thunk_get_for_any(pextTraceMessageVa);
	if (func == pUnregisterTraceGuids && func != pextUnregisterTraceGuids)
		return wine_thunk_get_for_any(pextUnregisterTraceGuids);

	return NULL;
}

