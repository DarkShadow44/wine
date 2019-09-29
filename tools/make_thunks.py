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
