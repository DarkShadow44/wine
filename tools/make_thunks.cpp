#include <clang-c/Index.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

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

typedef struct _ParamDef
{
	std::string name;
	struct _TypeChain* type;
} ParamDef;

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
	struct _DefinitionCollection* children;
	StructDefEnum structType;
	std::string named_type;
	std::string variable;
	clang_location location;
} StructDef;

typedef struct
{
	TypeChain *source;
	std::string target;
	clang_location location;
} TypeDef;



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
std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
	return elems;
}



typedef struct
{
	BOOL isStruct;
	union
	{
		StructDef* structDef;
		TypeDef* typeDef;
	};
} GenericDef;

typedef struct _DefinitionCollection
{
	std::map<std::string, GenericDef*> items;
	std::map<std::string, BOOL> ignored_items;
	GenericDef* typedef_item;
	struct _DefinitionCollection *children;
} DefinitionCollection;

typedef struct
{
	DefinitionCollection* definitions;
	std::vector<std::string> items;
} DependencyCollection;

typedef struct 
{
	std::vector<ParamDef*> params;
	clang_location location;
	BOOL isEmpty;
	TypeChain *return_type;
	std::string name;
	std::string internalname;
	BOOL relay;
	std::string relay_dll;
	std::string callingconvention;
	std::string identifier;
} FunctionItem;

typedef struct
{
	std::map<std::string, FunctionItem*> items;
} FunctionCollection;

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


static DependencyCollection* DependencyCollection_init(DefinitionCollection* definitions)
{
	DependencyCollection* self = new DependencyCollection();
	self->definitions = definitions;
	return self;
}

static void StructDef_make_dependencies(StructDef *self, DependencyCollection* dependencies);
static void TypeDef_make_dependencies(TypeDef* self, DependencyCollection *dependencies);

static void GenericDef_make_dependencies(GenericDef* self, DependencyCollection *dependencies)
{
	if (self->isStruct)
		StructDef_make_dependencies(self->structDef, dependencies);
	else
		TypeDef_make_dependencies(self->typeDef, dependencies);
}
static std::string GenericDef_getname(GenericDef* self);
static void DependencyCollection_append(DependencyCollection* self, std::string item)
{
	if (std::find(self->items.begin(), self->items.end(), item) != self->items.end())
	{
		self->items.push_back(item);
		for (std::pair<std::string, GenericDef*> element : self->definitions->items)
		{
			GenericDef *definition = element.second;
			if (GenericDef_getname(definition) == item)
				GenericDef_make_dependencies(definition, self);
		}		
	}
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
	if (self->chainType == TypeChainEnum_Pointer || self->chainType == TypeChainEnum_Array)
	{
		TypeChain_make_dependencies(self->subType, dependencies);
	}
	else if (self->chainType == TypeChainEnum_Function)
	{
		for (int i = 0; i < self->params.size(); i++)
			ParamDef_make_dependencies(self->params[i], dependencies);
		TypeChain_make_dependencies(self->result, dependencies);
	}
	else
	{
		DependencyCollection_append(dependencies, self->normal);
	}
}

static BOOL TypeChain_is_void(TypeChain* self)
{
	return (self->chainType == TypeChainEnum_Normal) && (self->normal == "void");
}

static TypeDef* TypeDef_init(TypeChain *source, std::string target, clang_location location)
{
	TypeDef* self = new TypeDef();
	
	self->source = source;
	self->target = target;
	self->location = location;
	
	return self;
}


static void TypeDef_print_struct(TypeDef *self, FILE *file, int depth)
{
	if (self->source->chainType == TypeChainEnum_Function)
		fprintf(file, "typedef %s; /* %s:%d */\n", TypeChain_tostring(self->source, self->target), self->location.file, self->location.line);
	else
		fprintf(file, "typedef %s %s; /* %s:%d */\n", TypeChain_tostring(self->source, ""), self->target.c_str(), self->location.file, self->location.line);
}

static std::string TypeDef_getname(TypeDef*  self)
{
	return self->target;
}

static std::string TypeDef_make_declaration(TypeDef*  self)
{
	return "";
}



	

static void TypeDef_make_dependencies(TypeDef* self, DependencyCollection *dependencies)
{
	TypeChain_make_dependencies(self->source, dependencies);
}

static clang_location GenericDef_get_location(GenericDef* self)
{
	if (self->isStruct)
		return self->structDef->location;
	else
		return self->typeDef->location;
}

static void GenericDef_set_name(GenericDef* self, std::string name)
{
	if (self->isStruct)
		self->structDef->name = name;
}

static TypeChain* DefinitionCollection_resolve_typedefs(DefinitionCollection* self, TypeChain* type);
static TypeChain* TypeDef_resolve_typedef(TypeDef* self, DefinitionCollection* definitions)
{
	return DefinitionCollection_resolve_typedefs(definitions, self->source);
}



static StructDef* StructDef_init(CXCursor node)
{
	StructDef *self = new StructDef();
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
	return self;
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
		for (std::pair<std::string, GenericDef*> element : self->children->items)
			StructDef_print_struct(element.second->structDef, file, depth + 1);
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

static std::string StructDef_getname(StructDef* self)
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
		for (std::pair<std::string, GenericDef*> element : self->children->items)
			StructDef_make_dependencies(element.second->structDef, dependencies);
	}
}

static TypeChain* StructDef_resolve_typedef(StructDef* self, DefinitionCollection* definitions)
{
	return self->type;
}


static GenericDef* GenericDef_init(void* def, BOOL isStruct)
{
	GenericDef* self = new GenericDef();
	self->isStruct = isStruct;
	if (isStruct)
		self->structDef = (StructDef*)def;
	else
		self->typeDef = (TypeDef*)def;
	
	return self;
}

static DefinitionCollection* DefinitionCollection_init(void)
{
	DefinitionCollection* self = new DefinitionCollection();
	
	self->typedef_item = 0;
	
	return self;
}

static std::string GenericDef_getname(GenericDef* self)
{
	if (self->isStruct)
		return StructDef_getname(self->structDef);
	else
		return TypeDef_getname(self->typeDef);
}

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

bool hasStart(std::string mainStr, std::string toMatch)
{
	return mainStr.find(toMatch) == 0;
}

static void DefinitionCollection_append(DefinitionCollection* self, CXCursor node, GenericDef* new_definition)
{
	BOOL ignored = 0;

	// Ignore common definitions
	std::string file = clang_location_get(clang_getCursorLocation(node)).file;
	const char* ignored_files[] = {
		"/winnt.h",
		"/windef.h",
		"/winbase.h",
		"/excpt.h",
		"/debug.h",
		"/guiddef.h",
		"/wingdi.h",
		"/winnls.h",
		"/winuser.h",
		"/wincon.h",
		"/winnetwk.h",
		"/verrsrc.h",
		"/winreg.h"
	};
	for (int i = 0; i < sizeof(ignored_files)/sizeof(*ignored_files); i++)
	{
		if (hasEnding(file, ignored_files[i]))
			ignored = 1;
	}

	std::string name = GenericDef_getname(new_definition);
	if (name == "")
	{
		self->typedef_item = new_definition; // Store (anyonymous struct/enum/union) item for following typedef
	}
	else
	{
		// Only add each definition once
		if (self->items.count(name) > 0)
			return;
		if (ignored)
			self->ignored_items[name] = 1;
		self->items[name] = new_definition;
	}
}
	

static void DefinitionCollection_append_typedef_item(DefinitionCollection* self, CXCursor node, std::string name)
{
	if (self->typedef_item != 0)
	{
		CXCursor original_cursor = clang_getTypeDeclaration(clang_getTypedefDeclUnderlyingType(node));
		clang_location location = GenericDef_get_location(self->typedef_item);
		if (location.line == clang_location_get(clang_getCursorLocation(node)).line)
		{
			GenericDef_set_name(self->typedef_item, name);
			DefinitionCollection_append(self, original_cursor, self->typedef_item);
		}
		self->typedef_item = 0;
	}
}



static BOOL DefinitionCollection_is_ignored(DefinitionCollection* self, std::string name)
{
	return self->ignored_items.count(name) > 0;
}


static void DefinitionCollection_clear_typedef_item(DefinitionCollection* self)
{
	self->typedef_item = 0;
}

static TypeChain* GenericDef_resolve_typedef(GenericDef* self, DefinitionCollection* definitions)
{
	if (self->isStruct)
		return StructDef_resolve_typedef(self->structDef, definitions);
	else
		return TypeDef_resolve_typedef(self->typeDef, definitions);
}



static TypeChain* DefinitionCollection_resolve_typedefs(DefinitionCollection* self, TypeChain* type)
{
	if (type->chainType != TypeChainEnum_Normal)
		return type;
	std::string name = type->normal;
	if (self->items.count(name) > 0)
		return GenericDef_resolve_typedef(self->items[name], self);
	return type;
}


static FunctionItem* FunctionItem_init()
{
	FunctionItem* self = new FunctionItem();
	self->isEmpty = 1;
	self->return_type = 0;
	return self;
}

static BOOL FunctionItem_is_empty(FunctionItem *self)
{
	return self->isEmpty;
}


static void FunctionItem_make_dependencies(FunctionItem* self, DependencyCollection* dependencies)
{
	if (self->return_type != 0)
		TypeChain_make_dependencies(self->return_type, dependencies);
	for (int i = 0; i < self->params.size(); i++)
		ParamDef_make_dependencies(self->params[i], dependencies);
}


static void FunctionItem_fill(FunctionItem* self, CXCursor node)
{
	self->isEmpty = 0;
	std::vector<CXCursor> children = clang_get_children(node);
	for (int i = 0; i < children.size(); i++)
	{
		CXCursor child = children[i];
		if (clang_getCursorKind(child) == CXCursor_ParmDecl)
			self->params.push_back(ParamDef_init(child));
	}
	self->return_type = TypeChain_init(0, clang_getCursorResultType(node));
	self->location = clang_location_get(clang_getCursorLocation(node));
}

static std::string FunctionItem_get_arguments_decl(FunctionItem* self)
{
	if (self->params.size() == 0)
		return "void";

	char buffer[500] = {0};
	
	for (int i = 0; i < self->params.size(); i++)
	{
		if (i > 0)
			strcat(buffer, ",");
		strcat(buffer, ParamDef_tostring(self->params[i]).c_str());
	}
	return buffer;
}

static std::string FunctionItem_get_arguments_calling(FunctionItem* self)
{
	if (self->params.size() == 0)
		return "";

	char buffer[500] = {0};
	
	for (int i = 0; i < self->params.size(); i++)
	{
		if (i > 0)
			strcat(buffer, ",");
		strcat(buffer, self->params[i]->name.c_str());
	}
	return buffer;
}


static FunctionCollection* FunctionCollection_init(void)
{
	return new FunctionCollection();
}


static BOOL FunctionCollection_contains(FunctionCollection* self, std::string name)
{
	return self->items.count(name) > 0;
}


static FunctionItem* FunctionCollection_get_item(FunctionCollection* self, std::string name)
{
	return self->items[name];
}


static void FunctionCollection_dump_items(FunctionCollection* self)
{
	for (std::pair<std::string, FunctionItem*> element : self->items)
	{
		FunctionItem *func = element.second;
		printf("%s - %s(%s) - relay: %d\n", func->callingconvention.c_str(), func->name.c_str(), func->internalname.c_str(), func->relay);
	}
}
static void FunctionItem_parse_from_spec_line(FunctionItem* function_item, std::string line)
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



static void FunctionCollection_load_from_specfile(FunctionCollection* self, std::string path)
{
	std::vector<std::string> lines;
	std::ifstream file(path);
    std::string str; 
    while (std::getline(file, str))
    {
        trim(str);
		lines.push_back(str);
    }
	
	std::vector<FunctionItem*> items_temp;
	std::vector<std::string> all_names;
	for (int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		if (line == "" || line[0] == '#')
			continue;
		if (line.find(" -private") != std::string::npos)
			continue;
		FunctionItem* item = FunctionItem_init();
		FunctionItem_parse_from_spec_line(item, line);
		items_temp.push_back(item);
		all_names.push_back(item->name);
	}
	
	for (int i = 0; i < items_temp.size(); i++)
	{
		FunctionItem* item = items_temp[i];
		BOOL is_in_names = (item->internalname != item->name)  &&  (std::find(all_names.begin(), all_names.end(), item->internalname) != all_names.end());
		if (item->relay || is_in_names) // A relay might have the same item.internalname as an already existing function
			self->items["relay_" + item->name] = item;
		else
			self->items[item->internalname] = item;
	}
}



static CXCursor parse_file(std::string path_file)
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

	translationUnit = clang_parseTranslationUnit(index, path_file.c_str(), arguments, sizeof(arguments)/sizeof(*arguments), 0, 0, CXTranslationUnit_None);

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




/* Helper functions */

// Get all the sources inside a Makefile.in TODO: need parent sources
std::vector<std::string> get_makefile_sources(std::string path)
{
	std::vector<std::string> sources;
	std::vector<std::string> lines;
	std::ifstream filex(path);
    std::string str; 
    while (std::getline(filex, str))
    {
        str = trim(str);
		lines.push_back(str);
    }

	BOOL doadd = 0;
	for(int i = 0; i < lines.size(); i++)
	{
		std::string line = lines[i];
		if (hasStart(line, "C_SRCS"))
		{
			std::vector<std::string> splits = split(line, '=');
			line = splits[1];
			doadd = 1;
		}
		if (doadd)
		{
			std::string file;
			std::vector<std::string> splits = split(line, '\\');
			file = splits[0];
			file = trim(file);
			if (file != "")
				sources.push_back(file);
			if (!hasEnding(line, "\\"))
				doadd = 0;
		}
	}
	return sources;
}

// Stacklayout in function
// 8 - own stackframe
// 8 - ret to stub
// 4 - ret to calling function
// 4 - param 1
// 4 - param 2
// ...
static void make_thunk_callingconvention_32_to_64_a(FILE* file, std::string dllname, FunctionItem* func)
{
	std::string funcname = func->identifier;
	int num_params = func->params.size();
	fprintf(file, "extern WINAPI void wine32a_%s_%s(void);  /* %s:%d */\n", dllname.c_str(), funcname.c_str(), func->location.file, func->location.line);
	fprintf(file, "__ASM_GLOBAL_FUNC(wine32a_%s_%s,\n\n", dllname.c_str(), funcname.c_str());
	//Setup own stackframe
	fprintf(file, "\t\"push %%rbp \\n\"\n");
	fprintf(file, "\t\"mov %%rsp, %%rbp \\n\"\n");
	// Convert params from 32bit convention to 64bit convention
	if (num_params >= 1)
		fprintf(file, "\t\"movl 0x14(%%rsp), %%ecx \\n\"\n");
	if (num_params >= 2)
		fprintf(file, "\t\"movl 0x18(%%rsp), %%edx \\n\"\n");
	if (num_params >= 3)
		fprintf(file, "\t\"movl 0x1C(%%rsp), %%r8d \\n\"\n");
	if (num_params >= 4)
		fprintf(file, "\t\"movl 0x20(%%rsp), %%r9d \\n\"\n");
	// Call actual function, give it a bit space...
	fprintf(file, "\t\"sub $0x100, %%rsp \\n\"\n");
	fprintf(file, "\t\"call \" __ASM_NAME(\"wine32b_%s_%s\") \"\\n\"\n", dllname.c_str(), funcname.c_str());
	fprintf(file, "\t\"add $0x100, %%rsp \\n\"\n"),
	// Reset own stackframe
	fprintf(file, "\t\"pop %%rbp \\n\"\n");
	// Backup our 2 return addresses
	fprintf(file, "\t\"movl 0x00(%%rsp), %%ecx \\n\"\n");
	fprintf(file, "\t\"movl 0x04(%%rsp), %%edx \\n\"\n");
	fprintf(file, "\t\"movl 0x08(%%rsp), %%r8d \\n\"\n");
	// Clean stack like the caller expects
	fprintf(file, "\t\"addq $%d, %%rsp \\n\"\n", num_params * 4);
	// Restore our 2 return addresses
	fprintf(file, "\t\"movl %%ecx, 0x00(%%rsp) \\n\"\n");
	fprintf(file, "\t\"movl %%edx, 0x04(%%rsp) \\n\"\n");
	fprintf(file, "\t\"movl %%r8d, 0x08(%%rsp) \\n\"\n");
	// Return
	fprintf(file, "\t\"ret \\n\"\n)\n\n");
}


static void make_thunk_callingconvention_32_to_64_b(FILE* file, std::string dllname, FunctionItem* func, DefinitionCollection* definitions)
{
	std::string funcname = func->identifier;
	std::string arguments_decl = FunctionItem_get_arguments_decl(func);
	std::string arguments_calling = FunctionItem_get_arguments_calling(func);
	std::string return_type = TypeChain_tostring(func->return_type, "return_value");
	BOOL has_return = !TypeChain_is_void(func->return_type);
	TypeChain* return_base_type = DefinitionCollection_resolve_typedefs(definitions, func->return_type);
	fprintf(file, "WINAPI %s wine32b_%s_%s(%s) /* %s:%d */\n{\n", TypeChain_tostring(func->return_type, ""), dllname.c_str(), funcname.c_str(), arguments_decl.c_str(), func->location.file, func->location.line);
	if (has_return)
		fprintf(file, "\t%s;", return_type.c_str());
	fprintf(file, "\tTRACE(\"Enter %s\\n\");\n", funcname.c_str());
	if (has_return)
		fprintf(file, "\treturn_value = p%s(%s);\n", funcname.c_str(), arguments_calling.c_str());
	else
		fprintf(file, "\tp%s(%s);\n", funcname.c_str(), arguments_calling.c_str());
	if (return_base_type->chainType == TypeChainEnum_Function)
		fprintf(file, "\treturn_value = wine_make_thunk_function_alloc(return_value);\n");
	fprintf(file, "\tTRACE(\"Leave %s\\n\");\n", funcname.c_str());
	if (has_return)
		fprintf(file, "\treturn return_value;\n");
	fprintf(file, "}\n\n");
}

BOOL node_is_only_declaration(CXCursor node)
{
	CXCursor definition = clang_getCursorDefinition(node);
	return !clang_equalCursors(node, definition);
}

static std::string GenericDef_get_named_type(GenericDef* self)
{
	if (self->isStruct)
		return self->structDef->named_type;
	else
		return "";
}

static void GenericDef_set_variable(GenericDef* self, std::string variable)
{
	if (self->isStruct)
		self->structDef->variable = variable;;
}

static void find_all_definitions(CXCursor node, DefinitionCollection* definitions, FunctionCollection* funcs, std::string source)
{
	CXCursorKind kind = clang_getCursorKind(node);
	std::string spelling = clang_str_get(clang_getCursorSpelling(node));
	clang_location location = clang_location_get(clang_getCursorLocation(node));
	std::string type_spelling = clang_str_get(clang_getTypeSpelling(clang_getCursorType(node)));
	if (kind == CXCursor_FunctionDecl && FunctionCollection_contains(funcs, spelling))
	{
		char buffer[200];
		sprintf(buffer, "/%s", source.c_str());
		if (!hasEnding(location.file, buffer))
			return;
		if (!node_is_only_declaration(node))
		{
			FunctionItem* func = FunctionCollection_get_item(funcs, spelling);
			FunctionItem_fill(func, node);
		}
	}

	if (kind == CXCursor_StructDecl || kind == CXCursor_UnionDecl || kind == CXCursor_FieldDecl || kind == CXCursor_EnumDecl)
	{
		// Check if there is a field whichs type is an anyonymous struct/union
		if (type_spelling.find("anonymous union") != std::string::npos || type_spelling.find("anonymous struct") != std::string::npos)
		{
			std::string named_type = clang_str_get(clang_getTypeSpelling(clang_Type_getNamedType(clang_getCursorType(node))));
			for (std::pair<std::string, GenericDef*> element : definitions->items)
			{
				GenericDef* child = element.second;
				if (GenericDef_get_named_type(child) == named_type)
					GenericDef_set_variable(child, " " + spelling);
			}
			definitions = DefinitionCollection_init();
		}
		else
		{
			if (!node_is_only_declaration(node))
			{
				GenericDef* new_parent = GenericDef_init(StructDef_init(node), 1);
				DefinitionCollection_append(definitions, node, new_parent);
				definitions = new_parent->structDef->children;
			}
		}

		std::vector<CXCursor> children = clang_get_children(node);
		for(int i = 0; i < children.size(); i++)
		{
			find_all_definitions(children[i], definitions, funcs, source);
		}
	}
	else if (kind == CXCursor_TypedefDecl)
	{
		TypeChain* type_from = TypeChain_init(&node, clang_getTypedefDeclUnderlyingType(node));
		// Fix anonymous struct/enum/union typedef
		DefinitionCollection_append_typedef_item(definitions, node, TypeChain_tostring(type_from, ""));
		GenericDef* definition = GenericDef_init(TypeDef_init(type_from, spelling, location), 0);
		DefinitionCollection_append(definitions, node, definition);
	}
	else
	{
		DefinitionCollection_clear_typedef_item(definitions);
	}
}



static void handle_dll_source(std::string dll_path, std::string source, FunctionCollection* funcs, DefinitionCollection* ret_definitions)
{
	std::string path_file = dll_path + "/" + source;

	CXCursor cursor = parse_file(path_file);

	std::vector<CXCursor> children = clang_get_children(cursor);
	for (int i = 0; i < children.size(); i++)
	{
		find_all_definitions(children[i], ret_definitions, funcs, source);
	}
}

static std::string GenericDef_make_declaration(GenericDef* self)
{
	if (self->isStruct)
		return StructDef_make_declaration(self->structDef);
	else
		return TypeDef_make_declaration(self->typeDef);
}


static void GenericDef_print_struct(GenericDef* self, FILE *file, int depth)
{
	if (self->isStruct)
		StructDef_print_struct(self->structDef, file, depth);
	else
		TypeDef_print_struct(self->typeDef, file, depth);
}


static void handle_dll(const char* name)
{
	char path_source[255];
	char path_spec[255];
	char path_makefile[255];
	FILE* file_source;

	printf("Started %s\n", name);

	sprintf(path_source, "../dlls/winethunks/%s.c", name);
	sprintf(path_spec, "../dlls/%s/%s.spec", name, name);
	sprintf(path_makefile, "../dlls/%s/makefile.in", name);

	file_source = fopen(path_source, "w");
	
	fprintf(file_source, "#include \"windows.h\"\n");
	fprintf(file_source, "#include \"wine/asm.h\"\n");
	fprintf(file_source, "#include \"wine/debug.h\"\n");
	fprintf(file_source, "#include \"wine/winethunks.h\"\n");
	fprintf(file_source, "WINE_DEFAULT_DEBUG_CHANNEL(thunks);\n\n");
	
	
	
	FunctionCollection* funcs = FunctionCollection_init();
	FunctionCollection_load_from_specfile(funcs, path_spec);
	std::vector<std::string> sources = get_makefile_sources(path_makefile);

	// Read files
	DefinitionCollection* definitionCollection = DefinitionCollection_init();
	for (int i = 0; i < sources.size(); i++)
	{
		std::string source = sources[i];
		//if not source.endswith("version.c"):
		//	continue
		printf("\tAt %s/%s", name, source.c_str());
		handle_dll_source(path_source, source, funcs, definitionCollection);
	}
	
	// Make dependencies
	DependencyCollection* dependencies = DependencyCollection_init(definitionCollection);
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (!FunctionItem_is_empty(func))
			FunctionItem_make_dependencies(func, dependencies);
	}
	std::vector<GenericDef*> usedDefinitions;
	
	for (std::pair<std::string, GenericDef*> element : definitionCollection->items)
	{
		GenericDef* definition = element.second;
		std::string definition_name = GenericDef_getname(definition);
		BOOL in_dependencies = std::find(dependencies->items.begin(), dependencies->items.end(), definition_name) != dependencies->items.end();
		if (in_dependencies && !DefinitionCollection_is_ignored(definitionCollection, definition_name))
			usedDefinitions.push_back(definition);
	}

	for (int i = 0; i < usedDefinitions.size(); i++)
	{
		GenericDef* definition = usedDefinitions[i];
		std::string declaration = GenericDef_make_declaration(definition);
		if (declaration != "")
			fprintf(file_source, "%s\n", declaration.c_str());
	}
	fprintf(file_source, "\n");
	for (int i = 0; i < usedDefinitions.size(); i++)
	{
		GenericDef* definition = usedDefinitions[i];
		GenericDef_print_struct(definition, file_source, 0);
	}
	
	
	// Make function pointers
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (!FunctionItem_is_empty(func))
		{
			std::string arguments = FunctionItem_get_arguments_decl(func);
			fprintf(file_source, "static WINAPI %s (*p%s)(%s);\n", TypeChain_tostring(func->return_type, ""), func->identifier, arguments);
		}
		if (func->relay)
		{
			fprintf(file_source, "static void* p%s;\n", func->identifier.c_str());
			fprintf(file_source, "static void* pext%s;\n", func->identifier.c_str());
		}
	}
	fprintf(file_source, "\n");
	
	// Add thunks
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (!FunctionItem_is_empty(func))
		{
			make_thunk_callingconvention_32_to_64_b(file_source, name, func, definitionCollection);
			make_thunk_callingconvention_32_to_64_a(file_source, name, func);
		}
	}
	
	// Make init function
	fprintf(file_source, "static BOOL initialized = FALSE;\n\n");
	fprintf(file_source, "void wine_thunk_initialize_%s(void)\n", name);
	fprintf(file_source, "{\n");
	fprintf(file_source, "\tHMODULE library = GetModuleHandleA(\"%s.dll\");", name);
	
	std::map<std::string, BOOL> libs;
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (func->relay && libs.count(func->relay_dll) == 0)
			libs[func->relay_dll] = 1;
	}
	for (std::pair<std::string, BOOL> element : libs)
	{
		std::string lib = element.first;
		fprintf(file_source, "\tHMODULE library_%s = GetModuleHandleA(\"%s.dll\");\n", lib.c_str(), lib.c_str());
	}
	   
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (!FunctionItem_is_empty(func))
		{
			fprintf(file_source, "\tp%s = (void *)GetProcAddress(library, \"{func.name}\");\n", func->identifier, func->name);
		}
		if (func->relay)
		{
			fprintf(file_source, "\tp%s = (void *)GetProcAddress(library, \"%s\");\n", func->identifier.c_str(), func->name.c_str());
			fprintf(file_source, "\tpext%s = (void *)GetProcAddress(library_%s, \"%s\");\n", func->identifier.c_str(), func->relay_dll.c_str(), func->internalname.c_str());
		}
	}
	fprintf(file_source, "\tinitialized = TRUE;\n");
	fprintf(file_source, "}\n\n");

	// Make get function
	fprintf(file_source, "void* wine_thunk_get_for_%s(void *func)\n", name);
	fprintf(file_source, "{\n");
	fprintf(file_source, "\tif (!initialized)\n");
	fprintf(file_source, "\t\treturn NULL;\n\n");
	for (std::pair<std::string, FunctionItem*> element : funcs->items)
	{
		FunctionItem* func = element.second;
		if (!FunctionItem_is_empty(func))
		{
			fprintf(file_source, "\tif (func == p%s)\n", func->identifier.c_str());
			fprintf(file_source, "\t\treturn wine32a_%s_%s;\n", name, func->identifier.c_str());
		}
		if (func->relay)
		{
			fprintf(file_source, "\tif (func == p%s && func != pext%s)\n", func->identifier.c_str(), func->identifier.c_str());
			fprintf(file_source, "\t\treturn wine_thunk_get_for_any(pext%s);\n", func->identifier.c_str());
		}
	}
	fprintf(file_source, "\n");
	fprintf(file_source, "\treturn NULL;\n");
	fprintf(file_source, "}\n\n");

	fclose(file_source);
	printf("Finished %s\n", name);
}

static void handle_all_dlls()
{
	const char* dlls[] = {
		"user32",
	};
	
	/*	dlls.append("user32")
	#dlls.append("kernel32")
	#dlls.append("advapi32")
	#dlls.append("msvcrt")
	#dlls.append("ntdll")
	#dlls.append("kernelbase")*/

	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		handle_dll(dlls[i]);
	}
	
	FILE* file_shared = fopen("../dlls/winethunks/winethunks_shared.c", "w");
	FILE* file_makefile = fopen("../dlls/winethunks/Makefile.in", "w");
	
	fprintf(file_shared, "#include <windows.h>'\n\n");

	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		fprintf(file_shared, "void* wine_thunk_get_for_%s(void *func);\n", dlls[i]);
	}
	fprintf(file_shared, "\n");

	// wine_thunk_get_for_any
	fprintf(file_shared, "WINAPI void *wine_thunk_get_for_any(void *func)\n");
	fprintf(file_shared, "{\n");
	fprintf(file_shared, "\tvoid *ret;\n");
	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		fprintf(file_shared, "\tif ((ret = wine_thunk_get_for_%s(func)) != NULL)\n", dlls[i]);
		fprintf(file_shared, "\t\treturn ret;\n");
	}
	fprintf(file_shared, "\n");
	fprintf(file_shared, "\treturn func;");
	fprintf(file_shared, "}\n\n");

	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		fprintf(file_shared, "void* wine_thunk_initialize_%s(void);\n", dlls[i]);
	}
	fprintf(file_shared, "\n");

	// wine_thunk_initialize_dll
	fprintf(file_shared, "WINAPI void wine_thunk_initialize_any(const char *dll)\n");
	fprintf(file_shared, "{\n");
	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		fprintf(file_shared, "\tif (!strcasecmp(\"%s.dll\", dll))\n", dlls[i]);
		fprintf(file_shared, "\t\twine_thunk_initialize_%s();\n", dlls[i]);
	}
	fprintf(file_shared, "}\n");

	// Make makefile
	fprintf(file_shared, "MODULE    = winethunks.dll\n");
	fprintf(file_shared, "IMPORTLIB = winethunks\n");
	fprintf(file_shared, "\n");
	fprintf(file_shared, "C_SRCS = \\\n");
	for (int i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
	{
		fprintf(file_shared, "\t%s.c \\\n", dlls[i]);
	}
	fprintf(file_shared, "\twinethunks_shared.c \\\n");
	fprintf(file_shared, "\twinethunks_main.c\n");
	fprintf(file_shared, "\n");

	fclose(file_makefile);
	fclose(file_shared);
}

int main()
{
	handle_all_dlls();
	return 0;
}
