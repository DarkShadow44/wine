#!/usr/bin/env python3

# pprint(dir())

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint

dll_name = "user32"

dll_path = "../dlls/" + dll_name

path_spec = dll_path + "/" + dll_name + ".spec"
path_makefile = dll_path + "/Makefile.in"

def get_specfile_funcs(path):
	funcs = []
	lines = [line.strip() for line in open(path)]
	for line in lines:
		rows = line.replace("(", " ").split(" ")
		if (line.startswith("#") or line == ""):
			continue;
		if (rows[1] == "stub"):
			funcs.append(rows[2])
		else:
			if (rows[2].startswith("-")):
				funcs.append(rows[3])
			else:
				funcs.append(rows[2])
	return funcs


# Stacklayout in function
# 8 - own stackframe
# 8 - ret to stub
# 4 - ret to calling function
# 4 - param 1
# 4 - param 2
# 4 - param 3
def make_thunk_callingconvention_32_to_64(source, include, funcname, num_params):
	include.append(f'WINAPI void wine32a_{funcname}(void);')
	include.append("")
	source.append(f'extern WINAPI void wine32a_{funcname}(void);')
	source.append(f'__ASM_GLOBAL_FUNC(wine32a_{funcname},')
	#Setup own stackframe
	source.append('\t"push %rbp \\n"');
	source.append('\t"mov %rsp, %rbp \\n"');
	# Convert params from 32bit convention to 64bit convention
	if (num_params >= 1):
		source.append('\t"movl 0x14(%rsp), %ecx \\n"');
	if (num_params >= 2):
		source.append('\t"movl 0x18(%rsp), %edx \\n"');
	if (num_params >= 3):
		source.append('\t"movl 0x1C(%rsp), %r8d \\n"');
	if (num_params >= 4):
		source.append('\t"movl 0x20(%rsp), %r9d \\n"');
	# Call actual function, give it a bit space...
	source.append('"\tsub $0x100, %rsp \\n"')
	source.append(f'\t"call " __ASM_NAME("wine32b_{funcname}") "\\n"')
	source.append('"\tadd $0x100, %rsp \\n"')
	# Reset own stackframe
	source.append('"\tpop %rbp \\n"')
	# Backup our 2 return addresses
	source.append('"\tmovl 0x00(%rsp), %ecx \\n"')
	source.append('"\tmovl 0x04(%rsp), %edx \\n"')
	source.append('"\tmovl 0x08(%rsp), %r8d \\n"')
	# Clean stack like the caller expects
	source.append(f'"\taddq ${num_params * 4}, %rsp \\n"')
	# Restore our 2 return addresses
	source.append('"\tmovl %ecx, 0x00(%rsp) \\n"')
	source.append('"\tmovl %edx, 0x04(%rsp) \\n"')
	source.append('"\tmovl %r8d, 0x08(%rsp) \\n"')
	# Return
	source.append('"\tret \\n"')
	source.append(")")
	source.append("")
	return source



source = []
source.append('#include "windows.h"');
source.append('#include "wine/asm.h"');
source.append("")
include = []
make_thunk_callingconvention_32_to_64(source, include, "MessageBoxA", 4)

file_source = open("../dlls/winethunks/user32.c", 'w')
file_source.write('\n'.join(source))
file_source.close()

file_include = open("../dlls/winethunks/user32.h", 'w')
file_include.write('\n'.join(include))
file_include.close()



path_file = "../dlls/user32/msgbox.c"

funcs = get_specfile_funcs(path_spec)

def find_typerefs(node):
	if (not node.location.file.name.endswith("msgbox.c")):
		return
	if node.spelling in funcs:
		if node.kind == CursorKind.FUNCTION_DECL:
			print(node.displayname + " " + str(node.location.file) + ":" + str(node.location.line) )
	for c in node.get_children():
		find_typerefs(c)

index = clang.cindex.Index.create()
tu = index.parse(path_file,  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.0/include/", "-I../include", "-fdeclspec"])
if len(tu.diagnostics) > 0:
	for diag in tu.diagnostics:
		print(diag.spelling + " " + str(diag.location.file) + ":" + str(diag.location.line))

for c in tu.cursor.get_children():
	find_typerefs(c)
