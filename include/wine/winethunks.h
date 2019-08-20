
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

static const unsigned char stub_buffer[] = {
    /* Function address */
    0, 0, 0, 0, 0, 0, 0, 0,
    /* Switch to x64 mode */
    0x6A, 0x33,                   /* push  0x33 */
    0xE8, 0x00, 0x00, 0x00, 0x00, /* call  $ + 5 */
    0x83, 0x04, 0x24, 0x05,       /* add   dword ptr [esp], 5 */
    0xCB,                         /* retf */
    /* Call actual function */
    0xFF, 0x15, 0xE6, 0xFF, 0xFF, 0xFF,
    /* Switch to x86 mode */
    0xE8, 0x00, 0x00, 0x00, 0x00,                   /* call $ + 5 */
    0xC7, 0x44, 0x24, 0x04, 0x23, 0x00, 0x00, 0x00, /* mov  dword [rsp + 4], 0x23 */
    0x83, 0x04, 0x24, 0x0D,                         /* add  dword [rsp], 0x0D */
    0xCB,
    /* Return */
    0xC3
};
const int stub_buffer_addr = 14;

static int get_import_stub_size(void)
{
    return sizeof(stub_buffer);
}

static DWORD create_import_stub(void *address, void *function)
{
    memcpy(address, stub_buffer, sizeof(stub_buffer));
    memcpy(address, &function, sizeof(void *));

    return (DWORD)(ULONGLONG)address + 8;
}


WINAPI DWORD wine_make_thunk_function(void* addr, DWORD func);
