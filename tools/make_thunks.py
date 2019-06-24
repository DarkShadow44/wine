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
