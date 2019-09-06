#!/usr/bin/env python3

# pprint(dir())

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint
from multiprocessing import Pool
from enum import Enum


class StructDefEnum(Enum):
	Field = 1
	Struct = 2
	Union = 3

class TypeDef:
	def __init__(self, source, target):
		self.source = source
		self.target = target

	def tostring(self):
		if t.source.chainType == TypeChainEnum.Function:
			return f'typedef {t.source.tostring(t.target)};'
		else:
			return f'typedef {t.source.tostring("")} {t.target};'

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

class StructDef:
	def __init__(self, node):
		self.name = node.spelling
		self.type = TypeChain(node, node.type)
		if node.kind == CursorKind.STRUCT_DECL:
			self.structType = StructDefEnum.Struct
		if node.kind == CursorKind.UNION_DECL:
			self.structType = StructDefEnum.Union
		if node.kind == CursorKind.FIELD_DECL:
			self.structType = StructDefEnum.Field
		self.children = []
		self.named_type = node.type.spelling
		self.variable = ''

def find_typerefs(node, ret_nodes, typedefs, structdefs_parent, depth):
	indent = "\t" * depth
	print(f'{indent}{node.kind} - {node.spelling}')
	
	if node.kind == CursorKind.STRUCT_DECL or node.kind == CursorKind.UNION_DECL or node.kind == CursorKind.FIELD_DECL:
		if ('anonymous union' in node.type.spelling) or ('anonymous struct' in node.type.spelling):
			for child in structdefs_parent:
				if child.named_type == node.type.get_named_type().spelling:
					child.variable = ' ' + node.spelling
			structdefs_parent = []
		else:
			parent = StructDef(node)
			structdefs_parent.append(parent)
			structdefs_parent = parent.children
	
	for c in node.get_children():
		find_typerefs(c, ret_nodes, typedefs, structdefs_parent, depth + 1)

	if node.kind == CursorKind.TYPEDEF_DECL:
		type_to = node.spelling
		type_from = TypeChain(node, node.underlying_typedef_type)
		typedefs.append(TypeDef(type_from, type_to))
		
index = clang.cindex.Index.create()
tu = index.parse("test.c",  ["-D_WIN32", "-D__WINESRC__", "-I/usr/lib/clang/8.0.1/include/", "-I../include", "-I/home/fabian/Programming/Wine/wine64/include/", "-fdeclspec", "-Wno-pragma-pack"])
if len(tu.diagnostics) > 0:
	for diag in tu.diagnostics:
		print(diag.spelling + " " + str(diag.location.file) + ":" + str(diag.location.line))

nodes = []
structdefs = []
typedefs = []
for c in tu.cursor.get_children():
	find_typerefs(c, nodes, typedefs, structdefs, 0)

print('')
print('########## OUTPUT ##########')
print('')

for t in typedefs:
	print(t.tostring())

def print_struct(struct, depth):
	indent = "\t" * depth
	
	type = 'error'
	if struct.structType == StructDefEnum.Struct:
		type = 'struct'
	if struct.structType == StructDefEnum.Union:
		type  = 'union'

	if struct.structType == StructDefEnum.Struct or struct.structType == StructDefEnum.Union:
		print(f'{indent}{type} {struct.name}')
		print(f'{indent}{{')
		for child in struct.children:
			print_struct(child, depth + 1)
		print(f'{indent}}}{struct.variable};')
		print('')

	if struct.structType == StructDefEnum.Field:
		print(f'{indent}{struct.type.tostring(struct.name)};')


for struct in structdefs:
	print_struct(struct, 0)
		
	
	

