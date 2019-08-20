#include "windows.h"
#include "wine/asm.h"

extern WINAPI void wine32a_MessageBoxA(void);
__ASM_GLOBAL_FUNC(wine32a_MessageBoxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
"	sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_MessageBoxA") "\n"
"	add $0x100, %rsp \n"
"	pop %rbp \n"
"	movl 0x00(%rsp), %ecx \n"
"	movl 0x04(%rsp), %edx \n"
"	movl 0x08(%rsp), %r8d \n"
"	addq $16, %rsp \n"
"	movl %ecx, 0x00(%rsp) \n"
"	movl %edx, 0x04(%rsp) \n"
"	movl %r8d, 0x08(%rsp) \n"
"	ret \n"
)
