#!/usr/bin/env python3

# pprint(dir())

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint
from multiprocessing import Pool
from argparse import ArgumentParser
from enum import Enum
import abc

# -------------------- Classes and enums --------------------

class GenericTypeDef(abc.ABC):
	@abc.abstractmethod
	def tostring(self) -> str:
		pass

	@abc.abstractmethod
	def getname(self) -> str:
		pass

class StructDefEnum(Enum):
	Field = 1
	Struct = 2
	Union = 3
	Enumeration = 4

class StructDef(GenericTypeDef):
	def __init__(self, node):
		self.name = node.spelling
		self.type = TypeChain(node, node.type)
		if node.kind == CursorKind.STRUCT_DECL:
			self.structType = StructDefEnum.Struct
		if node.kind == CursorKind.UNION_DECL:
			self.structType = StructDefEnum.Union
		if node.kind == CursorKind.FIELD_DECL:
			self.structType = StructDefEnum.Field
		if node.kind == CursorKind.ENUM_DECL:
			self.structType = StructDefEnum.Enumeration
		self.children = []
		self.named_type = node.type.spelling
		self.variable = ''

	def print_struct(self, lines, depth):
		indent = ' ' * 4 * depth

		type = 'error'
		if self.structType == StructDefEnum.Struct:
			type = 'struct'
		if self.structType == StructDefEnum.Union:
			type  = 'union'
		if self.structType == StructDefEnum.Enumeration:
			type  = 'enum'

		if self.structType == StructDefEnum.Struct or self.structType == StructDefEnum.Union or self.structType == StructDefEnum.Enumeration:
			lines.append(f'{indent}{type} {self.name}')
			lines.append(f'{indent}{{')
			for child in self.children:
				child.print_struct(lines, depth + 1)
			lines.append(f'{indent}}}{self.variable};')
			lines.append('')

		if self.structType == StructDefEnum.Field:
			lines.append(f'{indent}{self.type.tostring(self.name)};')

	def tostring(self):
		lines = []
		self.print_struct(lines, 0)
		return '\n'.join(lines);

	def getname(self):
		return self.name;

class TypeChainEnum(Enum):
	Array = 1
	Normal = 2
	Pointer = 3
	Function = 4

class TypeChain:
	def __init__(self, node, type):
		is_pointer = (type.get_pointee().spelling != '')
		is_array = (type.get_array_size() != -1)
		is_func = ('(*)' in type.spelling)

		func_params = []
		if node:
			for n in node.get_children():
				if n.kind == CursorKind.PARM_DECL:
					func_params.append(TypeChain(None, n.type))

		if is_func:
			self.chainType = TypeChainEnum.Function
			self.params = func_params
			self.result = TypeChain(None, type.get_pointee().get_result())
		elif is_pointer:
			self.chainType = TypeChainEnum.Pointer
			self.subType = TypeChain(None, type.get_pointee())
		elif is_array:
			self.chainType = TypeChainEnum.Array
			self.subType = TypeChain(None, type.get_array_element_type())
			self.arraySize = type.get_array_size()
		else:
			self.chainType = TypeChainEnum.Normal
			self.normal = type.spelling

	def tostring(self, variable):
		if self.chainType == TypeChainEnum.Pointer:
			variable = f' {variable}' if variable != '' else ''
			return self.subType.tostring('') + f'*{variable}'
		elif self.chainType == TypeChainEnum.Array:
			return self.subType.tostring(variable) + f'[{self.arraySize}]'
		elif self.chainType == TypeChainEnum.Function:
			paramList = [param.tostring('') for param in self.params]
			params = ", ".join(paramList) if len(paramList) > 0 else 'void'
			return f'{self.result.tostring("")} (*{variable}) ({params})';
		else:
			variable = f' {variable}' if variable != '' else ''
			return f'{self.normal}{variable}';

class TypeDef(GenericTypeDef):
	def __init__(self, source, target):
		self.source = source
		self.target = target

	def tostring(self):
		if self.source.chainType == TypeChainEnum.Function:
			return f'typedef {self.source.tostring(self.target)};'
		else:
			return f'typedef {self.source.tostring("")} {self.target};'

	def getname(self):
		return 'typedef' + self.target;


# -------------------- Helper functions --------------------

# Get all the functions inside a .spec file
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

# Get all the sources inside a Makefile.in
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

def find_all_functions(node, ret_nodes, funcs, source):
	if (node.location.file is None or not node.location.file.name.endswith(f'/{source}')):
		return
	if node.spelling in funcs:
		if node_is_function_definition(node):
			ret_nodes.append(node)
	for c in node.get_children():
		find_all_functions(c, ret_nodes, funcs, source)

def append_definition_if_not_exists(definitions, node, new_definition):
	if new_definition.getname() == "":
		return
	# Fields must always be added
	if node.kind != CursorKind.FIELD_DECL:
		# Only add each definition once
		if any(x.getname() == new_definition.getname() for x in definitions):
			return

		# Ignore common definitions
		file = str(node.location.file)
		ignored_files = ['/winnt.h', '/windef.h', '/winbase.h']
		if any(file.endswith(x) for x in ignored_files):
			return
	definitions.append(new_definition)

def find_all_definitions(node, structdefs_parent, typedef_name):
	if node.kind == CursorKind.STRUCT_DECL or node.kind == CursorKind.UNION_DECL or node.kind == CursorKind.FIELD_DECL or node.kind == CursorKind.ENUM_DECL:
		# Check if there is a field whichs type is an anyonymous struct/union
		if ('anonymous union' in node.type.spelling) or ('anonymous struct' in node.type.spelling):
			for child in structdefs_parent:
				if child.named_type == node.type.get_named_type().spelling:
					child.variable = ' ' + node.spelling
			structdefs_parent = []
		else:
			new_parent = StructDef(node)
			if typedef_name is not None:
				new_parent.name = typedef_name
			append_definition_if_not_exists(structdefs_parent, node, new_parent)
			structdefs_parent = new_parent.children

		for c in node.get_children():
			find_all_definitions(c, structdefs_parent, None)

	if node.kind == CursorKind.TYPEDEF_DECL:
		type_to = node.spelling
		type_from = TypeChain(node, node.underlying_typedef_type)
		for c in node.get_children():
			find_all_definitions(c, structdefs_parent, node.spelling)
		append_definition_if_not_exists(structdefs_parent, node, TypeDef(type_from, type_to))


def parse_file(path_file):
	index = clang.cindex.Index.create()
	tu = index.parse(path_file,  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.1/include/", "-I../include", "-I/home/fabian/Programming/Wine/wine64/include/", "-fdeclspec", "-Wno-pragma-pack"])
	if len(tu.diagnostics) > 0:
		for diag in tu.diagnostics:
			print(diag.spelling + " " + str(diag.location.file) + ":" + str(diag.location.line))
	return tu.cursor

def handle_dll_source(dll_path, source, funcs, contents_source, ret_func_pointers, ret_definitions):
	path_file = dll_path + "/" + source

	cursor = parse_file(path_file)

	nodes = []
	for child in cursor.get_children():
		find_all_functions(child, nodes, funcs, source)
		find_all_definitions(child, ret_definitions, None)

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
	contents_source.append('#include "wine/asm.h"');
	contents_source.append('#include "wine/debug.h"')
	contents_source.append('WINE_DEFAULT_DEBUG_CHANNEL(thunks);')
	contents_source.append("")

	funcs = get_specfile_funcs(path_spec)
	sources = get_makefile_sources(path_makefile)

	contents_dlls = []
	ret_func_pointers = []
	definitions = []
	for source in sources:
		if not source.endswith("menu.c") and not source.endswith("text.c"):
			continue
		handle_dll_source(dll_path, source, funcs, contents_dlls, ret_func_pointers, definitions)

	# Make definitions
	for definition in definitions:
		contents_source.append(definition.tostring())
		contents_source.append("")

	# Add thunks
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

def handle_all_dlls(threads):
	dlls = []
	dlls.append("user32")
	#dlls.append("kernel32")
	#dlls.append("advapi32")
	#dlls.append("msvcrt")
	#dlls.append("ntdll")

	if threads > 1:
		pool = Pool(threads)
		pool.map(handle_dll, dlls)
	else:
		for dll in dlls:
			handle_dll(dll)

	contents_shared = []
	contents_shared.append('#include <windows.h>')
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

def dump_definitions(path_file):
	cursor = parse_file(path_file)

	definitions = []
	for child in cursor.get_children():
		find_all_definitions(child, definitions, None)

	for definition in definitions:
		print(definition.tostring())


# -------------------- Entry point --------------------

parser = ArgumentParser()
parser.add_argument('--fixup-sources', dest='fixup_sources', action='store_true', default=False, help='Fixup the wine sources to work with wine-pure. All structures need to have a 32bit layout.')
parser.add_argument('--generate-thunks-all', dest='generate_thunks_all', action='store_true', default=False, help='Generate all thunks, including the Makefile and shared components.')
parser.add_argument('--update-thunks', dest='update_thunks', metavar='DLLNAME', help='Regenerate the thunks for a single dll, without touching the Makefile or shared components.')
parser.add_argument('--threads', dest='threads', metavar='NUMBER', default='4', type=int, help='Number of threads to use. To disable threading set to 1.')
parser.add_argument('--dump-definitions', dest='dump_definitions', metavar='FILE_PATH', default=None, help='DEBUG ONLY: Dumps all definitions read from a file.')

args = parser.parse_args()

if not args.fixup_sources and not args.generate_thunks_all and not args.update_thunks and args.dump_definitions == None:
	print('Please select an option. See -h for help.')
	exit()

if args.generate_thunks_all:
	handle_all_dlls(args.threads)

if not args.dump_definitions is None:
	dump_definitions(args.dump_definitions)
