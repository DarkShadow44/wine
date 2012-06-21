/*
 * Copyright 2010 Piotr Caban for CodeWeavers
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "stdlib.h"
#include "windef.h"

typedef unsigned char MSVCP_bool;
typedef SIZE_T MSVCP_size_t;
typedef SSIZE_T streamoff;
typedef SSIZE_T streamsize;

void __cdecl _invalid_parameter(const wchar_t*, const wchar_t*,
        const wchar_t*, unsigned int, uintptr_t);
BOOL __cdecl __uncaught_exception(void);

extern void* (__cdecl *MSVCRT_operator_new)(MSVCP_size_t);
extern void (__cdecl *MSVCRT_operator_delete)(void*);
extern void* (__cdecl *MSVCRT_set_new_handler)(void*);

/* Copied from dlls/msvcrt/cpp.c */
#ifdef __i386__  /* thiscall functions are i386-specific */

#define THISCALL(func) __thiscall_ ## func
#define THISCALL_NAME(func) __ASM_NAME("__thiscall_" #func)
#define __thiscall __stdcall
#define DEFINE_THISCALL_WRAPPER(func,args) \
    extern void THISCALL(func)(void); \
    __ASM_GLOBAL_FUNC(__thiscall_ ## func, \
                      "popl %eax\n\t" \
                      "pushl %ecx\n\t" \
                      "pushl %eax\n\t" \
                      "jmp " __ASM_NAME(#func) __ASM_STDCALL(args) )
#else /* __i386__ */

#define THISCALL(func) func
#define THISCALL_NAME(func) __ASM_NAME(#func)
#define __thiscall __cdecl
#define DEFINE_THISCALL_WRAPPER(func,args) /* nothing */

#endif /* __i386__ */

#ifdef _WIN64

#define VTABLE_ADD_FUNC(name) "\t.quad " THISCALL_NAME(name) "\n"

#define __ASM_VTABLE(name,funcs) \
    __asm__(".data\n" \
            "\t.align 8\n" \
            "\t.quad " __ASM_NAME(#name "_rtti") "\n" \
            "\t.globl " __ASM_NAME("MSVCP_" #name "_vtable") "\n" \
            __ASM_NAME("MSVCP_" #name "_vtable") ":\n" \
            "\t.quad " THISCALL_NAME(MSVCP_ ## name ## _vector_dtor) "\n" \
            funcs "\n\t.text")

#else

#define VTABLE_ADD_FUNC(name) "\t.long " THISCALL_NAME(name) "\n"

#define __ASM_VTABLE(name,funcs) \
    __asm__(".data\n" \
            "\t.align 4\n" \
            "\t.long " __ASM_NAME(#name "_rtti") "\n" \
            "\t.globl " __ASM_NAME("MSVCP_" #name "_vtable") "\n" \
            __ASM_NAME("MSVCP_" #name "_vtable") ":\n" \
            "\t.long " THISCALL_NAME(MSVCP_ ## name ## _vector_dtor) "\n" \
            funcs "\n\t.text")

#endif /* _WIN64 */

#define DEFINE_RTTI_DATA(name, off, base_classes, cl1, cl2, cl3, cl4, cl5, cl6, cl7, cl8, cl9, mangled_name) \
static const type_info name ## _type_info = { \
    &MSVCP_type_info_vtable, \
    NULL, \
    mangled_name \
}; \
\
static const rtti_base_descriptor name ## _rtti_base_descriptor = { \
    &name ##_type_info, \
    base_classes, \
    { 0, -1, 0}, \
    64 \
}; \
\
static const rtti_base_array name ## _rtti_base_array = { \
    { \
        &name ## _rtti_base_descriptor, \
        cl1, \
        cl2, \
        cl3, \
        cl4, \
        cl5, \
        cl6, \
        cl7, \
        cl8, \
        cl9, \
    } \
}; \
\
static const rtti_object_hierarchy name ## _hierarchy = { \
    0, \
    0, \
    base_classes+1, \
    &name ## _rtti_base_array \
}; \
\
const rtti_object_locator name ## _rtti = { \
    0, \
    off, \
    0, \
    &name ## _type_info, \
    &name ## _hierarchy \
}

#define DEFINE_RTTI_DATA0(name, off, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, mangled_name)
#define DEFINE_RTTI_DATA1(name, off, cl1, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 1, cl1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, mangled_name)
#define DEFINE_RTTI_DATA2(name, off, cl1, cl2, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 2, cl1, cl2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, mangled_name)
#define DEFINE_RTTI_DATA3(name, off, cl1, cl2, cl3, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 3, cl1, cl2, cl3, NULL, NULL, NULL, NULL, NULL, NULL, mangled_name)
#define DEFINE_RTTI_DATA4(name, off, cl1, cl2, cl3, cl4, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 4, cl1, cl2, cl3, cl4, NULL, NULL, NULL, NULL, NULL, mangled_name)
#define DEFINE_RTTI_DATA8(name, off, cl1, cl2, cl3, cl4, cl5, cl6, cl7, cl8, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 8, cl1, cl2, cl3, cl4, cl5, cl6, cl7, cl8, NULL, mangled_name)
#define DEFINE_RTTI_DATA9(name, off, cl1, cl2, cl3, cl4, cl5, cl6, cl7, cl8, cl9, mangled_name) \
    DEFINE_RTTI_DATA(name, off, 9, cl1, cl2, cl3, cl4, cl5, cl6, cl7, cl8, cl9, mangled_name)

#ifdef __i386__

#define CALL_VTBL_FUNC(this, off, ret, type, args) ((ret (WINAPI*)type)&vtbl_wrapper_##off)args

extern void *vtbl_wrapper_0;
extern void *vtbl_wrapper_4;
extern void *vtbl_wrapper_8;
extern void *vtbl_wrapper_12;
extern void *vtbl_wrapper_16;
extern void *vtbl_wrapper_20;
extern void *vtbl_wrapper_24;
extern void *vtbl_wrapper_28;
extern void *vtbl_wrapper_32;
extern void *vtbl_wrapper_36;
extern void *vtbl_wrapper_40;
extern void *vtbl_wrapper_44;
extern void *vtbl_wrapper_48;
extern void *vtbl_wrapper_52;
extern void *vtbl_wrapper_56;
extern void *vtbl_wrapper_60;

#else

#define CALL_VTBL_FUNC(this, off, ret, type, args) ((ret (__cdecl***)type)this)[0][off/4]args

#endif

/* exception object */
typedef void (*vtable_ptr)(void);
typedef struct __exception
{
    const vtable_ptr *vtable;
    char             *name;    /* Name of this exception, always a new copy for each object */
    int               do_free; /* Whether to free 'name' in our dtor */
} exception;

/* Internal: throws selected exception */
typedef enum __exception_type {
    EXCEPTION_RERAISE,
    EXCEPTION,
    EXCEPTION_BAD_ALLOC,
    EXCEPTION_LOGIC_ERROR,
    EXCEPTION_LENGTH_ERROR,
    EXCEPTION_OUT_OF_RANGE,
    EXCEPTION_INVALID_ARGUMENT,
    EXCEPTION_RUNTIME_ERROR,
    EXCEPTION_FAILURE,
} exception_type;
void throw_exception(exception_type, const char *);

/* rtti */
typedef struct __type_info
{
    const vtable_ptr *vtable;
    char              *name;         /* Unmangled name, allocated lazily */
    char               mangled[128]; /* Variable length, but we declare it large enough for static RTTI */
} type_info;

extern const vtable_ptr MSVCP_type_info_vtable;

/* offsets for computing the this pointer */
typedef struct
{
    int         this_offset;   /* offset of base class this pointer from start of object */
    int         vbase_descr;   /* offset of virtual base class descriptor */
    int         vbase_offset;  /* offset of this pointer offset in virtual base class descriptor */
} this_ptr_offsets;

typedef struct _rtti_base_descriptor
{
    const type_info *type_descriptor;
    int num_base_classes;
    this_ptr_offsets offsets;    /* offsets for computing the this pointer */
    unsigned int attributes;
} rtti_base_descriptor;

typedef struct _rtti_base_array
{
    const rtti_base_descriptor *bases[10]; /* First element is the class itself */
} rtti_base_array;

typedef struct _rtti_object_hierarchy
{
    unsigned int signature;
    unsigned int attributes;
    int array_len; /* Size of the array pointed to by 'base_classes' */
    const rtti_base_array *base_classes;
} rtti_object_hierarchy;

typedef struct _rtti_object_locator
{
    unsigned int signature;
    int base_class_offset;
    unsigned int flags;
    const type_info *type_descriptor;
    const rtti_object_hierarchy *type_hierarchy;
} rtti_object_locator;

/* basic_string<char, char_traits<char>, allocator<char>> */
#define BUF_SIZE_CHAR 16
typedef struct _basic_string_char
{
    void *allocator;
    union {
        char buf[BUF_SIZE_CHAR];
        char *ptr;
    } data;
    MSVCP_size_t size;
    MSVCP_size_t res;
} basic_string_char;

basic_string_char* __stdcall MSVCP_basic_string_char_ctor_cstr(basic_string_char*, const char*);
basic_string_char* __stdcall MSVCP_basic_string_char_copy_ctor(basic_string_char*, const basic_string_char*);
void __stdcall MSVCP_basic_string_char_dtor(basic_string_char*);
const char* __stdcall MSVCP_basic_string_char_c_str(const basic_string_char*);
void __thiscall MSVCP_basic_string_char_clear(basic_string_char*);
basic_string_char* __thiscall MSVCP_basic_string_char_append_ch(basic_string_char*, char);
MSVCP_size_t __thiscall MSVCP_basic_string_char_length(const basic_string_char*);

#define BUF_SIZE_WCHAR 8
typedef struct _basic_string_wchar
{
    void *allocator;
    union {
        wchar_t buf[BUF_SIZE_WCHAR];
        wchar_t *ptr;
    } data;
    MSVCP_size_t size;
    MSVCP_size_t res;
} basic_string_wchar;

basic_string_wchar* __stdcall MSVCP_basic_string_wchar_ctor_cstr(basic_string_wchar*, const wchar_t*);

char* __stdcall MSVCP_allocator_char_allocate(void*, MSVCP_size_t);
void __stdcall MSVCP_allocator_char_deallocate(void*, char*, MSVCP_size_t);
MSVCP_size_t __stdcall MSVCP_allocator_char_max_size(void*);
wchar_t* __stdcall MSVCP_allocator_wchar_allocate(void*, MSVCP_size_t);
void __stdcall MSVCP_allocator_wchar_deallocate(void*, wchar_t*, MSVCP_size_t);
MSVCP_size_t __stdcall MSVCP_allocator_wchar_max_size(void*);

/* class locale::facet */
typedef struct {
    const vtable_ptr *vtable;
    MSVCP_size_t refs;
} locale_facet;

typedef enum {
    CODECVT_ok      = 0,
    CODECVT_partial = 1,
    CODECVT_error   = 2,
    CODECVT_noconv  = 3
} codecvt_base_result;

typedef struct {
    LCID handle;
    unsigned page;
    const short *table;
    int delfl;
} _Ctypevec;

/* class codecvt_base */
typedef struct {
    locale_facet facet;
} codecvt_base;

/* class codecvt<char> */
typedef struct {
    codecvt_base base;
} codecvt_char;

MSVCP_bool __thiscall codecvt_base_always_noconv(const codecvt_base*);
int __thiscall codecvt_char_unshift(const codecvt_char*, int*, char*, char*, char**);
int __thiscall codecvt_char_out(const codecvt_char*, int*, const char*,
        const char*, const char**, char*, char*, char**);
int __thiscall codecvt_char_in(const codecvt_char*, int*, const char*,
        const char*, const char**, char*, char*, char**);
int __thiscall codecvt_base_max_length(const codecvt_base*);

typedef struct {
    LCID handle;
    unsigned page;
} _Cvtvec;

/* class codecvt<wchar> */
typedef struct {
    codecvt_base base;
    _Cvtvec cvt;
} codecvt_wchar;

/* class ctype_base */
typedef struct {
    locale_facet facet;
} ctype_base;

/* class ctype<char> */
typedef struct {
    ctype_base base;
    _Ctypevec ctype;
} ctype_char;

MSVCP_bool __thiscall ctype_char_is_ch(const ctype_char*, short, char);
char __thiscall ctype_char_narrow_ch(const ctype_char*, char, char);
char __thiscall ctype_char_widen_ch(const ctype_char*, char);

/* class ctype<wchar> */
typedef struct {
    ctype_base base;
    _Ctypevec ctype;
    _Cvtvec cvt;
} ctype_wchar;

char __thiscall ctype_wchar_narrow_ch(const ctype_wchar*, wchar_t, char);
wchar_t __thiscall ctype_wchar_widen_ch(const ctype_wchar*, char);

/* class locale */
typedef struct
{
    struct _locale__Locimp *ptr;
} locale;

locale* __thiscall locale_ctor(locale*);
locale* __thiscall locale_copy_ctor(locale*, const locale*);
locale* __thiscall locale_operator_assign(locale*, const locale*);
void __thiscall locale_dtor(locale*);
void free_locale(void);
codecvt_char* codecvt_char_use_facet(const locale*);
codecvt_char* codecvt_char_use_facet(const locale*);
ctype_char* ctype_char_use_facet(const locale*);
ctype_wchar* ctype_wchar_use_facet(const locale*);

/* class _Lockit */
typedef struct {
    int locktype;
} _Lockit;

#define _LOCK_LOCALE 0
#define _LOCK_MALLOC 1
#define _LOCK_STREAM 2
#define _LOCK_DEBUG 3
#define _MAX_LOCK 4

void init_lockit(void);
void free_lockit(void);
_Lockit* __thiscall _Lockit_ctor_locktype(_Lockit*, int);
void __thiscall _Lockit_dtor(_Lockit*);

/* class mutex */
typedef struct {
        void *mutex;
} mutex;

mutex* __thiscall mutex_ctor(mutex*);
void __thiscall mutex_dtor(mutex*);
void __thiscall mutex_lock(mutex*);
void __thiscall mutex_unlock(mutex*);

typedef enum {
    FMTFLAG_skipws      = 0x0001,
    FMTFLAG_unitbuf     = 0x0002,
    FMTFLAG_uppercase   = 0x0004,
    FMTFLAG_showbase    = 0x0008,
    FMTFLAG_showpoint   = 0x0010,
    FMTFLAG_showpos     = 0x0020,
    FMTFLAG_left        = 0x0040,
    FMTFLAG_right       = 0x0080,
    FMTFLAG_internal    = 0x0100,
    FMTFLAG_dec         = 0x0200,
    FMTFLAG_oct         = 0x0400,
    FMTFLAG_hex         = 0x0800,
    FMTFLAG_scientific  = 0x1000,
    FMTFLAG_fixed       = 0x2000,
    FMTFLAG_hexfloat    = 0x3000,
    FMTFLAG_boolalpha   = 0x4000,
    FMTFLAG_stdio       = 0x8000,
    FMTFLAG_adjustfield = FMTFLAG_left|FMTFLAG_right|FMTFLAG_internal,
    FMTFLAG_basefield   = FMTFLAG_dec|FMTFLAG_oct|FMTFLAG_hex,
    FMTFLAG_floadfield  = FMTFLAG_scientific|FMTFLAG_fixed,
    FMTFLAG_mask        = 0xffff
} IOSB_fmtflags;

typedef enum {
    OPENMODE_in         = 0x01,
    OPENMODE_out        = 0x02,
    OPENMODE_ate        = 0x04,
    OPENMODE_app        = 0x08,
    OPENMODE_trunc      = 0x10,
    OPENMODE__Nocreate  = 0x40,
    OPENMODE__Noreplace = 0x80,
    OPENMODE_binary     = 0x20,
    OPENMODE_mask       = 0xff
} IOSB_openmode;

typedef enum {
    SEEKDIR_beg  = 0x1,
    SEEKDIR_cur  = 0x2,
    SEEKDIR_end  = 0x3,
    SEEKDIR_mask = 0x3
} IOSB_seekdir;

typedef enum {
    IOSTATE_goodbit   = 0x00,
    IOSTATE_eofbit    = 0x01,
    IOSTATE_failbit   = 0x02,
    IOSTATE_badbit    = 0x04,
    IOSTATE__Hardfail = 0x10,
    IOSTATE_mask      = 0x17
} IOSB_iostate;

typedef struct _iosarray {
    struct _iosarray *next;
    int index;
    int long_val;
    void *ptr_val;
} IOS_BASE_iosarray;

typedef enum {
    EVENT_erase_event,
    EVENT_imbue_event,
    EVENT_copyfmt_event
} IOS_BASE_event;

struct _ios_base;
typedef void (CDECL *IOS_BASE_event_callback)(IOS_BASE_event, struct _ios_base*, int);
typedef struct _fnarray {
    struct _fnarray *next;
    int index;
    IOS_BASE_event_callback event_handler;
} IOS_BASE_fnarray;

/* class ios_base */
typedef struct _ios_base {
    const vtable_ptr *vtable;
    MSVCP_size_t stdstr;
    IOSB_iostate state;
    IOSB_iostate except;
    IOSB_fmtflags fmtfl;
    streamsize prec;
    streamsize wide;
    IOS_BASE_iosarray *arr;
    IOS_BASE_fnarray *calls;
    locale *loc;
} ios_base;

void init_io(void);
void free_io(void);
