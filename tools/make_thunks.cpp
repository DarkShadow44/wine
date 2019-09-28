#include <clang-c/Index.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

typedef int BOOL;

typedef struct
{
	unsigned line;
	const char* file;
} clang_location;


static const char* clang_str_get(CXString cx_str)
{
	return clang_getCString(cx_str);
}

static clang_location clang_location_get(CXSourceLocation cx_location)
{
	clang_location location;
	CXFile file;

	clang_getExpansionLocation(cx_location, &file, &location.line, 0, 0);
	location.file = clang_str_get(clang_getFileName(file));
	return location;
}


static CXCursor parse_file(const char *path_file)
{
	CXIndex index = clang_createIndex( 0, 1 );
	CXTranslationUnit translationUnit;
	const char* arguments[] = {
		"-D_WIN32",
		"-D__WINESRC__",
		"-I/usr/lib/clang/8.0.1/include/",
		"-I../include",
		"-I/home/fabian/Programming/Wine/wine64/include/",
		"-fdeclspec",
		"-Wno-pragma-pack"
	};

	translationUnit = clang_parseTranslationUnit(index, path_file, arguments, sizeof(arguments)/sizeof(*arguments), 0, 0, CXTranslationUnit_None);

	int len_diagnostics = clang_getNumDiagnostics(translationUnit);
	for (int i = 0; i < len_diagnostics; i++)
	{
		CXDiagnostic diagnostic = clang_getDiagnostic(translationUnit, i);
		const char* spelling = clang_str_get(clang_getDiagnosticSpelling(diagnostic));
		clang_location location = clang_location_get(clang_getDiagnosticLocation(diagnostic));

		printf("\t\t%s %s:%d\n", spelling, location.file, location.line);
	}

	return clang_getTranslationUnitCursor(translationUnit);
}

CXChildVisitResult functionVisitor(CXCursor cursor, CXCursor parent, CXClientData clientData)
{
	return CXChildVisit_Continue; // CXChildVisit_Recurse
}

struct cmp_str
{
   bool operator()(char const *a, char const *b) const
   {
      return std::strcmp(a, b) < 0;
   }
};


typedef struct 
{
	std::string name;
	std::string internalname;
	BOOL relay;
	std::string relay_dll;
	std::string callingconvention;
	void* return_type;
	void* params;
	std::string file;
	int line;
	std::string identifier;
} function_item_info;

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
	return elems;
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


static void function_item_parse_from_spec_line(function_item_info* function_item, std::string line)
{
	std::vector<std::string> rows = split(line, ' ');
	function_item->callingconvention = rows[1];
	std::replace(line.begin(), line.end(), '(', ')');
	std::vector<std::string> parts = split(line, ')'); //  0 - left side of parameters, 1 - parameters, 2 - right side of parameters
	
	parts[0] = trim(parts[0]);
	std::vector<std::string> parts_0_split = split(parts[0], ' ');
	function_item->internalname = parts_0_split[parts_0_split.size() - 1];
	function_item->name = function_item->internalname;
	function_item->identifier = function_item->internalname;
	
	if (parts.size() < 3)
		return;
	
	if (parts[2].length() > 0)
	{
		function_item->internalname = trim(parts[2]);
		if (function_item->internalname.find(".") != std::string::npos)
		{
			std::vector<std::string> nameparts = split(function_item->internalname, '.');
			function_item->internalname = nameparts[1];
			function_item->relay_dll = nameparts[0];
			function_item->relay = 1;
		}
	}
	else
	{
		if (function_item->internalname.find("-import") != std::string::npos)
		{
			function_item->relay = 1;
			function_item->relay_dll = "kernelbase";
		}
	}
	
	if (function_item->identifier.find("@") != std::string::npos || function_item->identifier.find("$") != std::string::npos) /* C++ Name */
	{
		function_item->identifier = function_item->internalname;
	}
}

static void handle_dll(const char* dll)
{
	char path_source[255];
	char path_spec[255];
	char path_makefile[255];
	FILE* file_source;

	printf("Started %s\n", dll);

	sprintf(path_source, "../dlls/winethunks/%s.c", dll);
	sprintf(path_spec, "../dlls/%s/%s.spec", dll, dll);
	sprintf(path_makefile, "../dlls/%s/makefile.in", dll);

	file_source = fopen(path_source, "w");
	
	fprintf(file_source, "#include \"windows.h\"\n");
	fprintf(file_source, "#include \"wine/asm.h\"\n");
	fprintf(file_source, "#include \"wine/debug.h\"\n");
	fprintf(file_source, "#include \"wine/winethunks.h\"\n");
	fprintf(file_source, "WINE_DEFAULT_DEBUG_CHANNEL(thunks);\n\n");

	std::map<const char*, function_item_info, cmp_str> functions;

	fclose(file_source);
	printf("Finished %s\n", dll);
}

static void handle_all_dlls()
{
	const char* dlls[] = {
		"user32",
	};

	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		handle_dll(dlls[i]);
	}
}

int main()
{
	handle_all_dlls();
	CXCursor cursor = parse_file("");
	
	clang_visitChildren(cursor, functionVisitor, 0);
	
	
	
	return 0;
}
