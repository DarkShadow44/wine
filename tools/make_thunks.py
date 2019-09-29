
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



def handle_dll_source(dll_path, source, funcs, ret_definitions):
	path_file = dll_path + "/" + source

	cursor = parse_file(path_file)

	for child in cursor.get_children():
		nodeWrapper = NodeCache(child)
		find_all_definitions(nodeWrapper, ret_definitions, funcs, source)

def handle_dll(name):

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
