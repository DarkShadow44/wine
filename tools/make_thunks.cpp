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
	std::string file;
} clang_location;

static const std::string clang_str_get(CXString cx_str)
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

CXChildVisitResult functionVisitor(CXCursor cursor, CXCursor parent, CXClientData clientData)
{
	std::vector<CXCursor>* children = (std::vector<CXCursor>*)clientData;
	children->push_back(cursor);
	return CXChildVisit_Continue;
}

std::vector<CXCursor> clang_get_children(CXCursor cursor)
{
	std::vector<CXCursor> children;
	clang_visitChildren(cursor, functionVisitor, (CXClientData)&children);
	return children;
}



void replaceAll( std::string &s, const std::string &search, const std::string &replace ) {
    for( size_t pos = 0; ; pos += replace.length() ) {
        pos = s.find( search, pos );
        if( pos == std::string::npos ) break;
        s.erase( pos, search.length() );
        s.insert( pos, replace );
    }
}




enum TypeChainEnum
{
	TypeChainEnum_Array = 1,
	TypeChainEnum_Normal = 2,
	TypeChainEnum_Pointer = 3,
	TypeChainEnum_Function = 4,
};


typedef struct _TypeChain
{
	TypeChainEnum chainType;
	std::vector<struct _ParamDef*> params;
	struct _TypeChain* result;
	struct _TypeChain* subType;
	int arraySize;
	std::string normal;
} TypeChain;




enum StructDefEnum
{
	StructDefEnum_Field = 1,
	StructDefEnum_Struct = 2,
	StructDefEnum_Union = 3,
	StructDefEnum_Enumeration = 4,
};


typedef struct _StructDef
{
	std::string name;
	TypeChain* type;
	std::vector<struct _StructDef*> children;
	StructDefEnum structType;
	std::string named_type;
	std::string variable;
	clang_location location;
} StructDef;

typedef struct _ParamDef
{
	std::string name;
	TypeChain* type;
} ParamDef;

typedef struct
{
} DependencyCollection;

typedef struct
{
} DefinitionCollection;

static TypeChain* TypeChain_init(CXCursor *node, CXType type);
static std::string TypeChain_tostring(TypeChain* self, std::string variable);
static void TypeChain_make_dependencies(TypeChain* self, DependencyCollection *dependencies);

static ParamDef* ParamDef_init(CXCursor node)
{
	ParamDef *self = new ParamDef();
	self->name = clang_str_get(clang_getCursorSpelling(node));
	self->type = TypeChain_init(0, clang_getCursorType(node));
	return self;
}

static std::string ParamDef_tostring(ParamDef* self)
{
	return TypeChain_tostring(self->type, self->name);
}

static void ParamDef_make_dependencies(ParamDef* self, DependencyCollection *dependencies)
{
	TypeChain_make_dependencies(self->type, dependencies);
}



static TypeChain* TypeChain_init(CXCursor *node, CXType type)
{
	TypeChain* self = new TypeChain();
	CXType pointee = clang_getPointeeType(type);
	BOOL is_pointer = clang_str_get(clang_getTypeSpelling(pointee)) != "";
	BOOL is_array = clang_getArraySize(type) != -1; 
	std::string spelling = clang_str_get(clang_getTypeSpelling(type));
	BOOL is_func = spelling.find("(*)") != std::string::npos;

	if (is_func)
	{
		if (node)
		{
			std::vector<CXCursor> children = clang_get_children(*node);
			for (int i = 0; i < children.size(); i++)
			{
				CXCursorKind kind = clang_getCursorKind(*node);
				if (kind == CXCursor_FieldDecl)
				{
					self->params.push_back(ParamDef_init(children[i]));
				}
			}
		}
		self->chainType = TypeChainEnum_Function;
		self->result = TypeChain_init(0, clang_getResultType(pointee));
	}
	else if (is_pointer)
	{
		self->chainType = TypeChainEnum_Pointer;
		self->subType = TypeChain_init(0, pointee);
	}
	else if (is_array)
	{
		self->chainType = TypeChainEnum_Array;
		self->subType = TypeChain_init(0, clang_getArrayElementType(type));
		self->arraySize = clang_getArraySize(type);
	}
	else
	{
		self->chainType = TypeChainEnum_Normal;
		replaceAll(spelling, "const ", "");
		self->normal = spelling;
	}
	return self;
}

static std::string TypeChain_tostring(TypeChain* self, std::string variable)
{
	char buffer[500] = {0};
	if (self->chainType == TypeChainEnum_Pointer)
	{
		if (variable == "")
			sprintf(buffer, "%s*%s", TypeChain_tostring(self->subType, ""), variable.c_str());
		else
			sprintf(buffer, "%s* %s", TypeChain_tostring(self->subType, ""), variable.c_str());
	}
	else if (self->chainType == TypeChainEnum_Array)
	{
		sprintf(buffer, "%s[%d]", TypeChain_tostring(self->subType, variable.c_str()), self->arraySize);
	}
	else if (self->chainType == TypeChainEnum_Function)
	{
		std::string params;
		if (self->params.size() == 0)
		{
			params = "void";
		}
		else
		{
			for (int i = 0; i < self->params.size(); i++)
			{
				if (i > 0)
					strcat(buffer, ",");
				strcat(buffer, ParamDef_tostring(self->params[i]).c_str());
			}
			params = buffer;
		}
		sprintf(buffer, "%s (*%s) (%s)", TypeChain_tostring(self->result, ""), variable, params.c_str());
	}
	else
	{
		if (variable == "")
			sprintf(buffer, "%s%s", self->normal.c_str(), variable.c_str());
		else
			sprintf(buffer, "%s %s", self->normal.c_str(), variable.c_str());
	}
	return buffer;
}

static void TypeChain_make_dependencies(TypeChain* self, DependencyCollection *dependencies)
{
}




static void StructDef_init(StructDef *self, CXCursor node)
{
	self->name = clang_str_get(clang_getCursorSpelling(node)); // TODO check is None
	CXType type = clang_getCursorType(node);
	self->type = TypeChain_init(&node, type);
	CXCursorKind kind = clang_getCursorKind(node);
	if (kind == CXCursor_StructDecl)
	{
		self->structType = StructDefEnum_Struct;
		self->name += "struct " + self->name;
	}
	if (kind == CXCursor_UnionDecl)
	{
		self->structType = StructDefEnum_Union;
		self->name += "union " + self->name;
	}
	if (kind == CXCursor_FieldDecl)
	{
		self->structType = StructDefEnum_Field;
	}
	if (kind == CXCursor_EnumDecl)
	{
		self->structType = StructDefEnum_Enumeration;
		self->name += "enum " + self->name;
	}
	self->named_type = clang_str_get(clang_getTypeSpelling(type));
	self->variable = "";
	self->location = clang_location_get(clang_getCursorLocation(node));
}


static void StructDef_print_struct(StructDef *self, FILE *file, int depth)
{
	char indent[200] = {0};
	for (int i = 0; i < depth; i++)
	{
		strcat(indent, "    ");
	}

	if (self->structType == StructDefEnum_Struct || self->structType == StructDefEnum_Union || self->structType == StructDefEnum_Enumeration)
	{
		fprintf(file, "%s%s /* %s:%s*/\n", indent, self->name, self->location.file, self->location.line);
		fprintf(file, "%s{\n", indent);
		for (int i = 0; i < self->children.size(); i++)
			StructDef_print_struct(self->children[i], file, depth + 1);
		if (self->structType == StructDefEnum_Enumeration)
		{
			std::string name = self->name;
			replaceAll(name, "enum ", "");
			fprintf(file, "    %s_DUMMY = 0", name);
		}
		fprintf(file, "%s}%s;\n\n", indent, self->variable.c_str());
	}
	
	if (self->structType == StructDefEnum_Field)
		fprintf(file, "%s%s;\n", indent, TypeChain_tostring(self->type, self->name));
}

static std::string StructDef_getname(StructDef *self)
{
	return self->name;
}


static std::string StructDef_make_declaration(StructDef *self)
{
	char buffer[200] = {0};
	if (self->structType == StructDefEnum_Struct || self->structType == StructDefEnum_Union || self->structType == StructDefEnum_Enumeration)
		sprintf(buffer, "%s; /* %s:%d */", self->name, self->location.file, self->location.line);
	return buffer;
}



static void StructDef_make_dependencies(StructDef *self, DependencyCollection* dependencies)
{
	if (self->structType == StructDefEnum_Field)
	{
		TypeChain_make_dependencies(self->type, dependencies);
	}
	else
	{
		for (int i = 0; i < self->children.size(); i++)
			StructDef_make_dependencies(self->children[i], dependencies);
	}
}

static TypeChain* StructDef_resolve_typedef(StructDef* self, DefinitionCollection* definitions)
{
	return self->type;
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
		std::string spelling = clang_str_get(clang_getDiagnosticSpelling(diagnostic));
		clang_location location = clang_location_get(clang_getDiagnosticLocation(diagnostic));

		printf("\t\t%s %s:%d\n", spelling.c_str(), location.file, location.line);
	}

	return clang_getTranslationUnitCursor(translationUnit);
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
