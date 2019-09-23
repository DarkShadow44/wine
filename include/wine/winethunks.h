WINAPI void* wine_make_thunk_function(void* addr, void *func, const char *hint);
WINAPI void wine_thunk_initialize_any(const char *dll);
WINAPI void *wine_thunk_get_for_any(void *func);
WINAPI int get_import_stub_size(void);
WINAPI void* create_import_stub(void *address, void *function);
WINAPI void* wine_make_thunk_function_alloc(void *func);

#define ASM_SWITCH_x86_to_x64() \
    ".byte 0x6A, 0x33\n"                   /* push  0x33 */ \
    ".byte 0xE8, 0x00, 0x00, 0x00, 0x00\n" /* call  $ + 5 */ \
    ".byte 0x83, 0x04, 0x24, 0x05\n"       /* add   dword ptr [esp], 5 */ \
    ".byte 0xCB\n"                         /* retf */


#define ASM_SWITCH_x64_to_x86() \
    ".byte 0xE8, 0x00, 0x00, 0x00, 0x00\n"                   /* call $ + 5 */ \
    ".byte 0xC7, 0x44, 0x24, 0x04, 0x23, 0x00, 0x00, 0x00\n" /* mov  dword [rsp + 4], 0x23 */ \
    ".byte 0x83, 0x04, 0x24, 0x0D\n"                         /* add  dword [rsp], 0x0D */ \
    ".byte 0xCB\n"                                           /* retf */


#ifdef __MINGW32__
#include <_mingw.h>
#endif
#undef __ptr32
#undef __ptr64
