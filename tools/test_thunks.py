#!/usr/bin/env python3

# pprint(dir())

import sys
import clang.cindex
from clang.cindex import CursorKind
from pprint import pprint
from multiprocessing import Pool
from dataclasses import dataclass
from enum import Enum


class StructDefEnum(Enum):
	Field = 1
	Struct = 2
	Union = 3

@dataclass
class TypeDef:
    type_from: str
    type_to: str

class TypeChainEnum(Enum):
	Array = 1
	Normal = 2
	Pointer = 3

class TypeChain:
	def __init__(self, type):
		is_pointer = (type.get_pointee().spelling != '')
		is_array = (type.get_array_size() != -1)
		
		if is_pointer:
			self.chainType = TypeChainEnum.Pointer
			self.subType = TypeChain(type.get_pointee())
		elif is_array:
			self.chainType = TypeChainEnum.Array
			self.subType = TypeChain(type.get_array_element_type())
			self.arraySize = type.get_array_size()
		else:
			self.chainType = TypeChainEnum.Normal
			self.normal = type.spelling
	def tostring(self):
		if self.chainType == TypeChainEnum.Pointer:
			return self.subType.tostring() + '*'
		elif self.chainType == TypeChainEnum.Array:
			return self.subType.tostring() + f'[{self.arraySize}]'
		else:
			return self.normal;

class StructDef:
	def __init__(self, node):
		self.name = node.spelling
		self.type = TypeChain(node.type)
		if node.kind == CursorKind.STRUCT_DECL:
			self.structType = StructDefEnum.Struct
		if node.kind == CursorKind.UNION_DECL:
			self.structType = StructDefEnum.Union
		if node.kind == CursorKind.FIELD_DECL:
			self.structType = StructDefEnum.Field
		self.children = []

def find_typerefs(node, ret_nodes, typedefs, structdefs_parent, depth):
	indent = "\t" * depth
	print(f'{indent}{node.kind} - {node.spelling}')
	
	if node.kind == CursorKind.STRUCT_DECL or node.kind == CursorKind.UNION_DECL or node.kind == CursorKind.FIELD_DECL:
		parent = StructDef(node)
		structdefs_parent.append(parent)
		structdefs_parent = parent.children
	
	for c in node.get_children():
		find_typerefs(c, ret_nodes, typedefs, structdefs_parent, depth + 1)

	if node.kind == CursorKind.TYPEDEF_DECL:
		type_to = node.spelling
		type_from = node.underlying_typedef_type.spelling
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

for t in typedefs:
	print(f'From "{t.type_from}" to "{t.type_to}"')

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
		print(f'{indent}}};')
		print('')

	if struct.structType == StructDefEnum.Field:
		print(f'{indent}{struct.type.tostring()} {struct.name};')


for struct in structdefs:
	print_struct(struct, 0)
		
	
	

