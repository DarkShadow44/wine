#!/usr/bin/env python3

# pprint(dir())
# TODO bitfields, parallelize single source file
# commandline option to limit to source and dll
# refactor and document...

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint
from multiprocessing import Pool
from argparse import ArgumentParser
from enum import Enum
import abc
from collections import OrderedDict

# -------------------- Classes and enums --------------------

class GenericTypeDef(abc.ABC):
	@abc.abstractmethod
	def tostring(self) -> str:
		pass

	@abc.abstractmethod
	def getname(self) -> str:
		pass

	@abc.abstractmethod
	def make_declaration(self) -> str:
		pass

	@abc.abstractmethod
	def make_dependencies(self, dependencies):
		pass

class StructDefEnum(Enum):
	Field = 1
	Struct = 2
	Union = 3
	Enumeration = 4

class StructDef(GenericTypeDef):

	def __init__(self, node):
		self.name = None if node.get_spelling() == "" else node.get_spelling()
		self.type = TypeChain(node, node.get_type())
		self.children = DefinitionCollection()
		if node.get_kind() == CursorKind.STRUCT_DECL:
			self.structType = StructDefEnum.Struct
		if node.get_kind() == CursorKind.UNION_DECL:
			self.structType = StructDefEnum.Union
		if node.get_kind() == CursorKind.FIELD_DECL:
			self.structType = StructDefEnum.Field
		if node.get_kind() == CursorKind.ENUM_DECL:
			self.structType = StructDefEnum.Enumeration
		self.named_type = node.get_type_spelling()
		self.set_name(self.name)
		self.variable = ''
		self.line = node.get_location_line()
		self.file = node.get_location_file()

	def print_struct(self, lines, depth):
		indent = ' ' * 4 * depth

		if self.structType == StructDefEnum.Struct or self.structType == StructDefEnum.Union or self.structType == StructDefEnum.Enumeration:
			lines.append(f'{indent}{self.name} /* {self.file}:{self.line} */')
			lines.append(f'{indent}{{')
			for child in self.children:
				child.print_struct(lines, depth + 1)
			if self.structType == StructDefEnum.Enumeration:
				lines.append(f'    {self.name.replace("enum ", "")}_DUMMY = 0')
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

	def make_declaration(self):
		if self.structType == StructDefEnum.Struct or self.structType == StructDefEnum.Union or self.structType == StructDefEnum.Enumeration:
			return f'{self.name}; /* {self.file}:{self.line} */'
		return None

	def make_dependencies(self, dependencies):
		if self.structType == StructDefEnum.Field:
			self.type.make_dependencies(dependencies)
		else:
			for child in self.children:
				child.make_dependencies(dependencies)

	def resolve_typedef(self, definitions):
		return self.type

	def set_name(self, name):
		if self.structType == StructDefEnum.Struct:
			self.name = name and ('struct ' + name)
		elif self.structType == StructDefEnum.Union:
			self.name = name and ('union ' + name)
		elif self.structType == StructDefEnum.Enumeration:
			self.name = name and ('enum ' + name)
		else:
			self.name = name

class TypeChainEnum(Enum):
	Array = 1
	Normal = 2
	Pointer = 3
	Function = 4


class ParamDef:
	def __init__(self, node):
		self.name = node.get_spelling()
		self.type = TypeChain(None, node.get_type())

	def tostring(self):
		name = f' {self.name}' if self.name != '' else ''
		return self.type.tostring(name)

	def make_dependencies(self, dependencies):
		self.type.make_dependencies(dependencies)

class TypeChain:
	def __init__(self, node, type):
		is_pointer = (type.get_pointee().spelling != '')
		is_array = (type.get_array_size() != -1)
		is_func = ('(*)' in type.spelling)

		func_params = []
		if node:
			for n in node.get_children():
				if n.kind == CursorKind.PARM_DECL:
					func_params.append(ParamDef(NodeCache(n)))

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
			self.normal = type.spelling.replace('const ', '')

	def tostring(self, variable):
		if self.chainType == TypeChainEnum.Pointer:
			variable = f' {variable}' if variable != '' else ''
			return self.subType.tostring('') + f'*{variable}'
		elif self.chainType == TypeChainEnum.Array:
			return self.subType.tostring(variable) + f'[{self.arraySize}]'
		elif self.chainType == TypeChainEnum.Function:
			paramList = [param.tostring() for param in self.params]
			params = ", ".join(paramList) if len(paramList) > 0 else 'void'
			return f'{self.result.tostring("")} (*{variable}) ({params})';
		else:
			variable = f' {variable}' if variable != '' else ''
			return f'{self.normal}{variable}';

	def make_dependencies(self, dependencies):
		if self.chainType == TypeChainEnum.Pointer or self.chainType == TypeChainEnum.Array:
			self.subType.make_dependencies(dependencies)
		elif self.chainType == TypeChainEnum.Function:
			for param in self.params:
				param.make_dependencies(dependencies)
			self.result.make_dependencies(dependencies)
		else:
			dependencies.append(self.normal)

	def is_void(self):
		return (self.chainType == TypeChainEnum.Normal) and (self.normal == 'void')

class TypeDef(GenericTypeDef):
	def __init__(self, source, target, line, file):
		self.source = source
		self.target = target
		self.line = line
		self.file = file

	def tostring(self):
		if self.source.chainType == TypeChainEnum.Function:
			return f'typedef {self.source.tostring(self.target)}; /* {self.file}:{self.line} */'
		else:
			return f'typedef {self.source.tostring("")} {self.target}; /* {self.file}:{self.line} */'

	def getname(self):
		return self.target;

	def make_declaration(self):
		return None

	def make_dependencies(self, dependencies):
		self.source.make_dependencies(dependencies)

	def resolve_typedef(self, definitions):
		return definitions.resolve_typedefs(self.source)

class DefinitionCollection:
	def __init__(self):
		self.items = {}
		self.ignored_items = {}
		self.typedef_item = None

	def append_typedef_item(self, node, name):
		if self.typedef_item is not None:
			original_cursor = NodeCache(node.node.underlying_typedef_type.get_declaration())
			if self.typedef_item.line == original_cursor.get_location_line():
				self.typedef_item.name = name
				self.append(original_cursor, self.typedef_item)
			self.typedef_item = None

	def clear_typedef_item(self):
		self.typedef_item = None

	def resolve_typedefs(self, type):
		if type.chainType != TypeChainEnum.Normal:
			return type;
		name = type.normal
		if name in self.items:
			return self.items[name].resolve_typedef(self)
		return type;

	def is_ignored(self, name):
		return name in self.ignored_items;

	def append(self, node, new_definition):
		ignored = False

		# Ignore common definitions
		file = str(node.get_location_file())
		ignored_files = ['/winnt.h', '/windef.h', '/winbase.h', '/excpt.h', '/debug.h', '/guiddef.h', '/wingdi.h', '/winnls.h', '/winuser.h', '/wincon.h', '/winnetwk.h', '/verrsrc.h', '/winreg.h']
		if any(file.endswith(x) for x in ignored_files):
			ignored = True

		if new_definition.getname() is None:
			self.typedef_item = new_definition # Store (anyonymous struct/enum/union) item for following typedef
		else:
			# Only add each definition once
			if new_definition.getname() in self.items:
				return
			if ignored:
				self.ignored_items[new_definition.getname()] = True
			self.items[new_definition.getname()] = new_definition

	def __iter__(self):
		return self.items.values().__iter__()

class DependencyCollection:
	def __init__(self, definitions):
		self.items = []
		self.definitions = definitions
	def append(self, item):
		if not item in self.items:
			self.items.append(item)
			for definition in self.definitions:
				if definition.getname() == item:
					definition.make_dependencies(self)
	def __iter__(self):
		return self.items.__iter__()

class FunctionItem:
	def __init__(self):
		self.name = None
		self.internalname = None
		self.relay = False
		self.relay_dll = None
		self.callingconvention = None
		self.return_type = None
		self.params = None
		self.file = None
		self.line = None
		self.identifier = None

	def parse_from_spec_line(self, line):
		rows = line.split(' ')
		self.temp = line
		self.callingconvention = rows[1]
		parts = line.replace('(', ')').split(')') # 0 - left side of parameters, 1 - parameters, 2 - right side of parameters
		self.internalname = self.name = parts[0].strip().split(' ')[-1]
		self.identifier = self.name
		if len(parts) < 3:
			return
		if parts[2] != "":
			self.internalname = parts[2].strip()
			if '.' in self.internalname:
				nameparts = self.internalname.split('.')
				self.internalname = nameparts[1]
				self.relay_dll = nameparts[0]
				self.relay = True
		else:
			if ' -import' in line:
				self.relay = True
				self.relay_dll = 'kernelbase'

		if ('@' in self.identifier) or ('$' in self.identifier): # C++ name
			self.identifier = self.internalname

	def is_empty(self):
		return self.params == None

	def make_dependencies(self, dependencies):
		if self.return_type is not None:
			self.return_type.make_dependencies(dependencies)
		for param in self.params:
			param.make_dependencies(dependencies)

	def fill(self, node):
		self.params = []
		for child in node.get_children():
			if child.kind == CursorKind.PARM_DECL:
				self.params.append(ParamDef(NodeCache(child)))
		self.return_type = TypeChain(None, node.get_result_type())
		self.line = node.get_location_line()
		self.file = node.get_location_file()

	def get_arguments_decl(self):
		paramList = [param.tostring() for param in self.params]
		params = ", ".join(paramList) if len(paramList) > 0 else 'void'
		return params;

	def get_arguments_calling(self):
		paramList = [param.name for param in self.params]
		params = ", ".join(paramList) if len(paramList) > 0 else ''
		return params;

class FunctionCollection:
	def __init__(self):
		self.items = {}

	def contains(self, name):
		return name in self.items

	def get_item(self, name):
		return self.items[name]

	def load_from_specfile(self, path):
		lines = [line.strip() for line in open(path)]
		items_temp = []
		for line in lines:
			if (line.startswith("#") or line == ""):
				continue
			if (' -private' in line):
				continue
			item = FunctionItem()
			item.parse_from_spec_line(line)
			items_temp.append(item)
		all_names = [item.name for item in items_temp]
		for item in items_temp:
			is_in_names = (item.internalname != item.name) and (item.internalname in all_names)
			if item.relay or is_in_names: # A relay might have the same item.internalname as an already existing function
				self.items['relay_' + item.name] = item
			else:
				self.items[item.internalname] = item

	def dump_items(self):
		for item in self.items.values():
			print(f'{item.callingconvention} - {item.name}({item.internalname}) - relay: {item.relay}')

	def __iter__(self):
		return self.items.values().__iter__()

class NodeCache:
	def __init__(self, node):
		self.node = node;
		self.kind = node.kind
		self.has_spelling = False
		self.has_file = False
		self.has_file_name = False
		self.has_type = False
		self.has_type_spelling = False
		self.has_location = False
		self.has_location_file = False
		self.has_location_line = False
		self.has_result_type = False

	def get_spelling(self):
		if not self.has_spelling:
			self.has_spelling = True
			self.spelling = self.node.spelling
		return self.spelling

	def get_kind(self):
		return self.kind;

	def get_type(self):
		if not self.has_type:
			self.has_type = True
			self.type = self.node.type
		return self.type

	def get_type_spelling(self):
		if not self.has_type_spelling:
			self.has_type_spelling = True
			type = self.get_type()
			self.type_spelling = type.spelling
		return self.type_spelling

	def get_children(self):
		return self.node.get_children()

	def get_location(self):
		if not self.has_location:
			self.has_location = True
			self.location = self.node.location
		return self.location

	def get_location_file(self):
		if not self.has_location_file:
			self.has_location_file = True
			location = self.get_location()
			self.location_file = location.file.name
		return self.location_file

	def get_location_line(self):
		if not self.has_location_line:
			self.has_location_line = True
			location = self.get_location()
			self.location_line = location.line
		return self.location_line

	def get_result_type(self):
		if not self.has_result_type:
			self.has_result_type = True
			self.result_type = self.node.result_type
		return self.result_type


# -------------------- Helper functions --------------------

# Get all the sources inside a Makefile.in TODO: need parent sources
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
def make_thunk_callingconvention_32_to_64_a(contents_source, dllname, func):
	funcname = func.identifier
	num_params = len(func.params)
	contents_source.append(f'extern WINAPI void wine32a_{dllname}_{funcname}(void);  /* {func.file}:{func.line} */')
	contents_source.append(f'__ASM_GLOBAL_FUNC(wine32a_{dllname}_{funcname},')
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
	contents_source.append(f'\t"call " __ASM_NAME("wine32b_{dllname}_{funcname}") "\\n"')
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

def make_thunk_callingconvention_32_to_64_b(contents_source, dllname, func, definitions):
	funcname = func.identifier
	arguments_decl = func.get_arguments_decl()
	arguments_calling = func.get_arguments_calling()
	return_type = func.return_type.tostring('return_value')
	has_return = not func.return_type.is_void()
	return_base_type = definitions.resolve_typedefs(func.return_type)
	contents_source.append(f'WINAPI {func.return_type.tostring("")} wine32b_{dllname}_{funcname}({arguments_decl}) /* {func.file}:{func.line} */')
	contents_source.append('{')
	if has_return:
		contents_source.append(f'\t{return_type};');
	contents_source.append(f'\tTRACE("Enter {funcname}\\n");')
	if has_return:
		contents_source.append(f'\treturn_value = p{funcname}({arguments_calling});')
	else:
		contents_source.append(f'\tp{funcname}({arguments_calling});')
	if (return_base_type.chainType == TypeChainEnum.Function):
		contents_source.append('\treturn_value = wine_make_thunk_function_alloc(return_value);')
	contents_source.append(f'\tTRACE("Leave {funcname}\\n");')
	if has_return:
		contents_source.append('\treturn return_value;')
	contents_source.append('}')
	contents_source.append("")

def node_is_only_declaration(node):
	definition = node.node.get_definition();
	if definition is None:
		return True;
	return node.node != definition;

def find_all_definitions(node, definitions, funcs, source):
	if node.get_kind() == CursorKind.FUNCTION_DECL and funcs.contains(node.get_spelling()):
		if (not node.get_location_file().endswith(f'/{source}')):
			return
		if not node_is_only_declaration(node):
			func = funcs.get_item(node.get_spelling())
			func.fill(node)

	if node.get_kind() == CursorKind.STRUCT_DECL or node.get_kind() == CursorKind.UNION_DECL or node.get_kind() == CursorKind.FIELD_DECL or node.get_kind() == CursorKind.ENUM_DECL:
		# Check if there is a field whichs type is an anyonymous struct/union
		if ('anonymous union' in node.get_type_spelling()) or ('anonymous struct' in node.get_type_spelling()):
			for child in definitions:
				if child.named_type == node.get_type().get_named_type().spelling:
					child.variable = ' ' + node.get_spelling()
			definitions = DefinitionCollection()
		else:
			if not node_is_only_declaration(node):
				new_parent = StructDef(node)
				definitions.append(node, new_parent)
				definitions = new_parent.children

		for child in node.get_children():
			find_all_definitions(NodeCache(child), definitions, funcs, source)
	elif node.get_kind() == CursorKind.TYPEDEF_DECL:
		type_to = node.get_spelling()
		type_from = TypeChain(node, node.node.underlying_typedef_type)
		# Fix anonymous struct/enum/union typedef
		definitions.append_typedef_item(node, type_from.tostring(""))
		definition = TypeDef(type_from, type_to, node.get_location_line(), node.get_location_file())
		definitions.append(node, definition)
	else:
		definitions.clear_typedef_item()


def parse_file(path_file):
	index = clang.cindex.Index.create()
	tu = index.parse(path_file,  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.1/include/", "-I../include", "-I/home/fabian/Programming/Wine/wine64/include/", "-fdeclspec", "-Wno-pragma-pack"])
	if len(tu.diagnostics) > 0:
		for diag in tu.diagnostics:
			print(f'\t\t{diag.spelling}  {diag.location.file.name}:{diag.location.line}')
	return tu.cursor

def handle_dll_source(dll_path, source, funcs, ret_definitions):
	path_file = dll_path + "/" + source

	cursor = parse_file(path_file)

	for child in cursor.get_children():
		nodeWrapper = NodeCache(child)
		find_all_definitions(nodeWrapper, ret_definitions, funcs, source)

def handle_dll(name):
	print(f'Started {name}')
	dll_path = "../dlls/" + name
	path_spec = f'{dll_path}/{name}.spec'
	path_makefile = dll_path + "/Makefile.in"

	contents_source = []
	contents_source.append('#include "windows.h"');
	contents_source.append('#include "wine/asm.h"');
	contents_source.append('#include "wine/debug.h"')
	contents_source.append('#include "wine/winethunks.h"')
	contents_source.append('WINE_DEFAULT_DEBUG_CHANNEL(thunks);')
	contents_source.append("")

	funcs = FunctionCollection()
	funcs.load_from_specfile(path_spec)
	sources = get_makefile_sources(path_makefile)

	# Read files
	definitionCollection = DefinitionCollection()
	for source in sources:
		#if not source.endswith("version.c"):
		#	continue
		print(f'\tAt {name}/{source}')
		handle_dll_source(dll_path, source, funcs, definitionCollection)

	# Make dependencies
	dependencies = DependencyCollection(definitionCollection)
	for func in funcs:
		if not func.is_empty():
			func.make_dependencies(dependencies)
	usedDefinitions = [definition for definition in definitionCollection if ((definition.getname() in dependencies) and (not definitionCollection.is_ignored(definition.getname())))]
	for definition in usedDefinitions:
		declaration = definition.make_declaration()
		if declaration is not None:
			contents_source.append(declaration)
	contents_source.append("")
	for definition in usedDefinitions:
		contents_source.append(definition.tostring())
		contents_source.append("")

	# Make function pointers
	for func in funcs:
		if not func.is_empty():
			arguments = func.get_arguments_decl()
			contents_source.append(f'static WINAPI {func.return_type.tostring("")} (*p{func.identifier})({arguments});')
		if func.relay:
			contents_source.append(f'static void* p{func.identifier};')
			contents_source.append(f'static void* pext{func.identifier};')
	contents_source.append("")

	# Add thunks
	for func in funcs:
		if not func.is_empty():
			# print(node.displayname + " " + str(node.location.file) + ":" + str(node.location.line) )
			make_thunk_callingconvention_32_to_64_b(contents_source, name, func, definitionCollection)
			make_thunk_callingconvention_32_to_64_a(contents_source, name, func)

	# Make init function
	contents_source.append('static BOOL initialized = FALSE;')
	contents_source.append("")
	contents_source.append(f'void wine_thunk_initialize_{name}(void)')
	contents_source.append('{')
	contents_source.append(f'\tHMODULE library = GetModuleHandleA("{name}.dll");')
	libs = list(OrderedDict.fromkeys([func.relay_dll for func in funcs if func.relay]))
	for lib in libs:
		contents_source.append(f'\tHMODULE library_{lib} = GetModuleHandleA("{lib}.dll");')
	for func in funcs:
		if not func.is_empty():
			contents_source.append(f'\tp{func.identifier} = (void *)GetProcAddress(library, "{func.name}");')
		if func.relay:
			contents_source.append(f'\tp{func.identifier} = (void *)GetProcAddress(library, "{func.name}");')
			contents_source.append(f'\tpext{func.identifier} = (void *)GetProcAddress(library_{func.relay_dll}, "{func.internalname}");')
	contents_source.append('\tinitialized = TRUE;')
	contents_source.append('}')
	contents_source.append("")

	# Make get function
	contents_source.append(f'void* wine_thunk_get_for_{name}(void *func)')
	contents_source.append('{')
	contents_source.append('\tif (!initialized)')
	contents_source.append('\t\treturn NULL;')
	contents_source.append("")
	for func in funcs:
		if not func.is_empty():
			contents_source.append(f'\tif (func == p{func.identifier})')
			contents_source.append(f'\t\treturn wine32a_{name}_{func.identifier};')
		if func.relay:
			contents_source.append(f'\tif (func == p{func.identifier} && func != pext{func.identifier})')
			contents_source.append(f'\t\treturn wine_thunk_get_for_any(pext{func.identifier});')
	contents_source.append("")
	contents_source.append('\treturn NULL;')
	contents_source.append('}')
	contents_source.append("")

	file_source = open(f'../dlls/winethunks/{name}.c', 'w')
	file_source.write('\n'.join(contents_source))
	file_source.close()
	print(f'Finished {name}')

def handle_all_dlls(threads):
	dlls = []
	dlls.append("user32")
	#dlls.append("kernel32")
	#dlls.append("advapi32")
	#dlls.append("msvcrt")
	#dlls.append("ntdll")
	#dlls.append("kernelbase")

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

	definitions = DefinitionCollection()
	for child in cursor.get_children():
		find_all_definitions(child, definitions)

	for definition in definitions:
		print(definition.tostring())


# -------------------- Entry point --------------------

parser = ArgumentParser()
parser.add_argument('-f', '--fixup-sources', dest='fixup_sources', action='store_true', default=False, help='Fixup the wine sources to work with wine-pure. All structures need to have a 32bit layout.')
parser.add_argument('-a', '--generate-thunks-all', dest='generate_thunks_all', action='store_true', default=False, help='Generate all thunks, including the Makefile and shared components.')
parser.add_argument('-u', '--update-thunks', dest='update_thunks', metavar='DLLNAME', help='Regenerate the thunks for a single dll, without touching the Makefile or shared components.')
parser.add_argument('-t', '--threads', dest='threads', metavar='NUMBER', default='4', type=int, help='Number of threads to use. To disable threading set to 1.')
parser.add_argument('--dump-definitions', dest='dump_definitions', metavar='FILE_PATH', default=None, help='DEBUG ONLY: Dumps all definitions read from a file.')

args = parser.parse_args()

if not args.fixup_sources and not args.generate_thunks_all and not args.update_thunks and args.dump_definitions == None:
	print('Please select an option. See -h for help.')
	exit()

if args.generate_thunks_all:
	handle_all_dlls(args.threads)

if not args.dump_definitions is None:
	dump_definitions(args.dump_definitions)
