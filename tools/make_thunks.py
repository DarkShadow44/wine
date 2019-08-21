#!/usr/bin/env python3

# pprint(dir())

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint

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

def get_makefile_sources(path):
	sources = []
	lines = [line.strip() for line in open(path)]
	doadd = False
	for line in lines:
		if line.startswith("C_SRCS"):
			line = line.split("=")[1]
			doadd = True
		if doadd:
			file = line.split("\\")[0].strip()
			if len(file) > 0:
				sources.append(file)
			if not line.endswith("\\"):
				doadd = False
	return sources

# Stacklayout in function
# 8 - own stackframe
# 8 - ret to stub
# 4 - ret to calling function
# 4 - param 1
# 4 - param 2
# ...
def make_thunk_callingconvention_32_to_64_a(source, include, node):
	funcname = node.spelling
	num_params = len(list(node.get_arguments()))
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
	source.append('\t"sub $0x100, %rsp \\n"')
	source.append(f'\t"call " __ASM_NAME("wine32b_{funcname}") "\\n"')
	source.append('\t"add $0x100, %rsp \\n"')
	# Reset own stackframe
	source.append('\t"pop %rbp \\n"')
	# Backup our 2 return addresses
	source.append('\t"movl 0x00(%rsp), %ecx \\n"')
	source.append('\t"movl 0x04(%rsp), %edx \\n"')
	source.append('\t"movl 0x08(%rsp), %r8d \\n"')
	# Clean stack like the caller expects
	source.append(f'\t"addq ${num_params * 4}, %rsp \\n"')
	# Restore our 2 return addresses
	source.append('\t"movl %ecx, 0x00(%rsp) \\n"')
	source.append('\t"movl %edx, 0x04(%rsp) \\n"')
	source.append('\t"movl %r8d, 0x08(%rsp) \\n"')
	# Return
	source.append('\t"ret \\n"')
	source.append(")")
	source.append("")
	return source

def make_thunk_callingconvention_32_to_64_b(source, include, node):
	funcname = node.spelling
	arguments_decl = [f'{arg.type.spelling} {arg.spelling}' for arg in node.get_arguments()]
	arguments_calling = [f'{arg.spelling}' for arg in node.get_arguments()]
	source.append(f'extern WINAPI {node.result_type.spelling} wine32b_{funcname}({", ".join(arguments_decl)})')
	source.append('{')
	source.append(f'\treturn p{funcname}({", ".join(arguments_calling)});')
	source.append('}')
	source.append("")

def find_typerefs(node, ret_nodes, funcs, source):
	if (node.location.file is None or not node.location.file.name.endswith(source)):
		return
	if node.spelling in funcs:
		if node.kind == CursorKind.FUNCTION_DECL:
			ret_nodes.append(node)
	for c in node.get_children():
		find_typerefs(c, ret_nodes, funcs, source)

def handle_dll_source(dll_path, source, funcs, contents_source, contents_include, ret_func_pointers):
	path_file = dll_path + "/" + source

	index = clang.cindex.Index.create()
	tu = index.parse(path_file,  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.0/include/", "-I../include", "-fdeclspec"])
	if len(tu.diagnostics) > 0:
		for diag in tu.diagnostics:
			print(diag.spelling + " " + str(diag.location.file) + ":" + str(diag.location.line))

	nodes = []
	for c in tu.cursor.get_children():
		find_typerefs(c, nodes, funcs, source)

	# Make function pointers
	for node in nodes:
		arguments = [f'{arg.type.spelling}' for arg in node.get_arguments()]
		contents_source.append(f'static WINAPI {node.result_type.spelling} (*p{node.spelling})({", ".join(arguments)});')
		ret_func_pointers.append(node.spelling)
	contents_source.append("")

	for node in nodes:
		print(node.displayname + " " + str(node.location.file) + ":" + str(node.location.line) )
		make_thunk_callingconvention_32_to_64_b(contents_source, contents_include, node)
		make_thunk_callingconvention_32_to_64_a(contents_source, contents_include, node)

def handle_dll(name):
	dll_path = "../dlls/" + name
	path_spec = f'{dll_path}/{name}.spec'
	path_makefile = dll_path + "/Makefile.in"

	contents_source = []
	contents_source.append('#include "windows.h"');
	contents_source.append('#include "wine/asm.h"');
	contents_source.append("")
	contents_include = []

	funcs = get_specfile_funcs(path_spec)
	sources = get_makefile_sources(path_makefile)

	ret_func_pointers = []
	for source in sources:
		if not source.endswith("msgbox.c"):
			continue
		handle_dll_source(dll_path, source, funcs, contents_source, contents_include, ret_func_pointers)

		# Make init function
	contents_source.append(f'void init_{name}(void)')
	contents_source.append('{')
	contents_source.append(f'\tHMODULE library = LoadLibraryA("{name}.dll");')
	for func in ret_func_pointers:
		contents_source.append(f'\tp{func} = (void *)GetProcAddress(library, "{func}");')
	contents_source.append('}')
	contents_source.append("")

	file_source = open(f'../dlls/winethunks/{name}.c', 'w')
	file_source.write('\n'.join(contents_source))
	file_source.close()

	file_include = open(f'../dlls/winethunks/{name}.h', 'w')
	file_include.write('\n'.join(contents_include))
	file_include.close()


handle_dll("user32")
