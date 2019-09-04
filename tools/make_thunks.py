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
def make_thunk_callingconvention_32_to_64_a(contents_source, node):
	funcname = node.spelling
	num_params = len(list(node.get_arguments()))
	contents_source.append(f'extern WINAPI void wine32a_{funcname}(void);')
	contents_source.append(f'__ASM_GLOBAL_FUNC(wine32a_{funcname},')
	#Setup own stackframe
	contents_source.append('\t"push %rbp \\n"');
	contents_source.append('\t"mov %rsp, %rbp \\n"');
	# Convert params from 32bit convention to 64bit convention
	if (num_params >= 1):
		contents_source.append('\t"movl 0x14(%rsp), %ecx \\n"');
	if (num_params >= 2):
		contents_source.append('\t"movl 0x18(%rsp), %edx \\n"');
	if (num_params >= 3):
		contents_source.append('\t"movl 0x1C(%rsp), %r8d \\n"');
	if (num_params >= 4):
		contents_source.append('\t"movl 0x20(%rsp), %r9d \\n"');
	# Call actual function, give it a bit space...
	contents_source.append('\t"sub $0x100, %rsp \\n"')
	contents_source.append(f'\t"call " __ASM_NAME("wine32b_{funcname}") "\\n"')
	contents_source.append('\t"add $0x100, %rsp \\n"')
	# Reset own stackframe
	contents_source.append('\t"pop %rbp \\n"')
	# Backup our 2 return addresses
	contents_source.append('\t"movl 0x00(%rsp), %ecx \\n"')
	contents_source.append('\t"movl 0x04(%rsp), %edx \\n"')
	contents_source.append('\t"movl 0x08(%rsp), %r8d \\n"')
	# Clean stack like the caller expects
	contents_source.append(f'\t"addq ${num_params * 4}, %rsp \\n"')
	# Restore our 2 return addresses
	contents_source.append('\t"movl %ecx, 0x00(%rsp) \\n"')
	contents_source.append('\t"movl %edx, 0x04(%rsp) \\n"')
	contents_source.append('\t"movl %r8d, 0x08(%rsp) \\n"')
	# Return
	contents_source.append('\t"ret \\n"')
	contents_source.append(")")
	contents_source.append("")

def get_arguments_decl(node):
	arguments_decl = [f'{arg.type.spelling} {arg.spelling}' for arg in node.get_arguments()]
	if len(arguments_decl) == 0:
		return 'void'
	return ", ".join(arguments_decl)

def make_thunk_callingconvention_32_to_64_b(contents_source, node):
	funcname = node.spelling
	arguments_decl = get_arguments_decl(node)
	arguments_calling = [f'{arg.spelling}' for arg in node.get_arguments()]
	contents_source.append(f'extern WINAPI {node.result_type.spelling} wine32b_{funcname}({arguments_decl})')
	contents_source.append('{')
	contents_source.append(f'\tTRACE("Enter {funcname}\\n");')
	contents_source.append(f'\treturn p{funcname}({", ".join(arguments_calling)});')
	contents_source.append('}')
	contents_source.append("")

def node_is_function_definition(node):
	if not node.kind == CursorKind.FUNCTION_DECL:
		return False

	for c in node.get_children():
		if (c.kind == CursorKind.COMPOUND_STMT):
			return True

	return False

def find_typerefs(node, ret_nodes, funcs, source):
	if (node.location.file is None or not node.location.file.name.endswith(f'/{source}')):
		return
	if node.spelling in funcs:
		if node_is_function_definition(node):
			ret_nodes.append(node)
	for c in node.get_children():
		find_typerefs(c, ret_nodes, funcs, source)

def handle_dll_source(dll_path, source, funcs, contents_source, ret_func_pointers, ret_headers):
	path_file = dll_path + "/" + source

	index = clang.cindex.Index.create()
	tu = index.parse(path_file,  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.1/include/", "-I../include", "-I/home/fabian/Programming/Wine/wine64/include/", "-fdeclspec", "-Wno-pragma-pack"])
	if len(tu.diagnostics) > 0:
		for diag in tu.diagnostics:
			print(diag.spelling + " " + str(diag.location.file) + ":" + str(diag.location.line))

	nodes = []
	for c in tu.cursor.get_children():
		find_typerefs(c, nodes, funcs, source)

	for include in tu.get_includes():
		if include.source.name.endswith(f'/{source}') and not include.include.name.startswith('/'):
			include_path = f'../{include.include}';
			if not include_path in ret_headers:
				ret_headers.append(include_path)

	# Make function pointers
	for node in nodes:
		arguments = get_arguments_decl(node)
		contents_source.append(f'static WINAPI {node.result_type.spelling} (*p{node.spelling})({arguments});')
		ret_func_pointers.append(node.spelling)
	contents_source.append("")

	for node in nodes:
		print(node.displayname + " " + str(node.location.file) + ":" + str(node.location.line) )
		make_thunk_callingconvention_32_to_64_b(contents_source, node)
		make_thunk_callingconvention_32_to_64_a(contents_source, node)

def handle_dll(name):
	dll_path = "../dlls/" + name
	path_spec = f'{dll_path}/{name}.spec'
	path_makefile = dll_path + "/Makefile.in"

	contents_source = []
	contents_source.append('#define WIN32_NO_STATUS')
	contents_source.append('#include "ntstatus.h"');
	contents_source.append('#include "windows.h"');
	contents_source.append('#include "wine/asm.h"');
	contents_source.append('#include "wine/debug.h"')
	contents_source.append('WINE_DEFAULT_DEBUG_CHANNEL(thunks);')
	contents_source.append("")

	funcs = get_specfile_funcs(path_spec)
	sources = get_makefile_sources(path_makefile)

	contents_dlls = []
	ret_func_pointers = []
	ret_headers = []
	for source in sources:
		#if not source.endswith("menu.c"):
		#	continue
		handle_dll_source(dll_path, source, funcs, contents_dlls, ret_func_pointers, ret_headers)

	# Make includes
	for header in ret_headers:
		if not header.endswith('wine/port.h'):
			contents_source.append(f'#include "{header}"')
	contents_source.append("")

	for line in contents_dlls:
		contents_source.append(line)

	# Make init function
	contents_source.append('static BOOL initialized = FALSE;')
	contents_source.append("")
	contents_source.append(f'void wine_thunk_initialize_{name}(void)')
	contents_source.append('{')
	contents_source.append(f'\tHMODULE library = LoadLibraryA("{name}.dll");')
	for func in ret_func_pointers:
		contents_source.append(f'\tp{func} = (void *)GetProcAddress(library, "{func}");')
	contents_source.append('\tinitialized = TRUE;')
	contents_source.append('}')
	contents_source.append("")

	# Make get function
	contents_source.append(f'void* wine_thunk_get_for_{name}(void *func)')
	contents_source.append('{')
	contents_source.append('\tif (!initialized)')
	contents_source.append('\t\treturn NULL;')
	contents_source.append("")
	for func in ret_func_pointers:
		contents_source.append(f'\tif (func == p{func})')
		contents_source.append(f'\t\treturn wine32a_{func};')
	contents_source.append("")
	contents_source.append('\treturn NULL;')
	contents_source.append('}')
	contents_source.append("")

	file_source = open(f'../dlls/winethunks/{name}.c', 'w')
	file_source.write('\n'.join(contents_source))
	file_source.close()

def handle_all_dlls():
	dlls = []
	dlls.append("user32")
	dlls.append("kernel32")

	for dll in dlls:
		handle_dll(dll)

	contents_shared = []
	contents_shared.append('#include <windows.h>')
	contents_shared.append('#include "wine/debug.h"')
	contents_shared.append('WINE_DEFAULT_DEBUG_CHANNEL(thunks);')
	contents_shared.append("")

	for dll in dlls:
		contents_shared.append(f'void* wine_thunk_get_for_{dll}(void *func);')
	contents_shared.append("")

	# wine_thunk_get_for_any
	contents_shared.append('WINAPI void *wine_thunk_get_for_any(void *func)')
	contents_shared.append('{')
	contents_shared.append('\tvoid *ret;')
	for dll in dlls:
		contents_shared.append(f'\tif ((ret = wine_thunk_get_for_{dll}(func)) != NULL)')
		contents_shared.append(f'\t\treturn ret;')
	contents_shared.append("")
	contents_shared.append('\tERR("Missing thunk!\\n");')
	contents_shared.append('\treturn func;')
	contents_shared.append('}')
	contents_shared.append("")

	for dll in dlls:
		contents_shared.append(f'void* wine_thunk_initialize_{dll}(void);')
	contents_shared.append("")

	# wine_thunk_initialize_dll
	contents_shared.append('WINAPI void wine_thunk_initialize_any(const char *dll)')
	contents_shared.append('{')
	for dll in dlls:
		contents_shared.append(f'\tif (!strcasecmp("{dll}.dll", dll))')
		contents_shared.append(f'\t\twine_thunk_initialize_{dll}();')
	contents_shared.append("")
	contents_shared.append('}')
	contents_shared.append("")

	file_source = open(f'../dlls/winethunks/winethunks_shared.c', 'w')
	file_source.write('\n'.join(contents_shared))
	file_source.close()

	# Make makefile
	contents_makefile = [];
	contents_makefile.append('MODULE    = winethunks.dll')
	contents_makefile.append('IMPORTLIB = winethunks')
	contents_makefile.append('')
	contents_makefile.append('C_SRCS = \\')
	for dll in dlls:
		contents_makefile.append(f'\t{dll}.c \\')
	contents_makefile.append('\twinethunks_shared.c \\')
	contents_makefile.append('\twinethunks_main.c')
	contents_makefile.append('')

	file_makefile = open(f'../dlls/winethunks/Makefile.in', 'w')
	file_makefile.write('\n'.join(contents_makefile))
	file_makefile.close()


handle_all_dlls()
