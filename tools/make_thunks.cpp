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
    StructDefEnum_SimpleType = 5,
};

typedef struct
{
    std::string name;
    TypeChain* type;
} TypeDefTarget;

typedef struct _StructDef
{
    std::string name;
    TypeChain* type;
    struct _DefinitionCollection* children;
    StructDefEnum structType;
    std::string variable;
    TypeChain* variable_type;
    clang_location location;
    std::vector<TypeDefTarget> typedef_targets;
    BOOL is_anonymous;
} StructDef;


static void trim(std::string& str)
{
    // trim trailing spaces
    size_t endpos = str.find_last_not_of(" \t");
    size_t startpos = str.find_first_not_of(" \t");
    if( std::string::npos != endpos )
    {
        str = str.substr( 0, endpos+1 );
        str = str.substr( startpos );
    }
    else {
        str.erase(std::remove(std::begin(str), std::end(str), ' '), std::end(str));
    }
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

typedef struct _DefinitionCollection
{
    std::map<std::string, StructDef*> items;
    std::vector<StructDef*> items_ordered;
    std::map<std::string, BOOL> ignored_items;
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

static TypeChain* TypeChain_init(CXCursor *node, CXType type, BOOL ignore_normal);
static std::string TypeChain_tostring(TypeChain* self, std::string variable);
static void TypeChain_make_dependencies(TypeChain* self, DependencyCollection *dependencies);

static ParamDef* ParamDef_init(CXCursor node)
{
    ParamDef *self = new ParamDef();
    self->name = clang_str_get(clang_getCursorSpelling(node));
    self->type = TypeChain_init(0, clang_getCursorType(node), 0);
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
static std::string StructDef_getname(StructDef* self);
static void DependencyCollection_append(DependencyCollection* self, std::string item)
{
    if (std::find(self->items.begin(), self->items.end(), item) == self->items.end())
    {
        self->items.push_back(item);
        for (unsigned i = 0; i < self->definitions->items_ordered.size(); i++)
        {
            StructDef *definition = self->definitions->items_ordered[i];
            if (StructDef_getname(definition) == item)
                StructDef_make_dependencies(definition, self);
        }        
    }
}



static TypeChain* TypeChain_init(CXCursor *node, CXType type, BOOL ignore_normal)
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
            for (unsigned i = 0; i < children.size(); i++)
            {
                CXCursorKind kind = clang_getCursorKind(children[i]);
                if (kind == CXCursor_ParmDecl)
                {
                    self->params.push_back(ParamDef_init(children[i]));
                }
            }
        }
        self->chainType = TypeChainEnum_Function;
        self->result = TypeChain_init(0, clang_getResultType(pointee), ignore_normal);
    }
    else if (is_pointer)
    {
        self->chainType = TypeChainEnum_Pointer;
        self->subType = TypeChain_init(0, pointee, ignore_normal);
    }
    else if (is_array)
    {
        self->chainType = TypeChainEnum_Array;
        self->subType = TypeChain_init(0, clang_getArrayElementType(type), ignore_normal);
        self->arraySize = clang_getArraySize(type);
    }
    else
    {
        self->chainType = TypeChainEnum_Normal;
        replaceAll(spelling, "const ", "");
        if (!ignore_normal)
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
            sprintf(buffer, "%s*%s", TypeChain_tostring(self->subType, "").c_str(), variable.c_str());
        else
            sprintf(buffer, "%s* %s", TypeChain_tostring(self->subType, "").c_str(), variable.c_str());
    }
    else if (self->chainType == TypeChainEnum_Array)
    {
        sprintf(buffer, "%s[%d]", TypeChain_tostring(self->subType, variable.c_str()).c_str(), self->arraySize);
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
            for (unsigned i = 0; i < self->params.size(); i++)
            {
                if (i > 0)
                    strcat(buffer, ", ");
                strcat(buffer, ParamDef_tostring(self->params[i]).c_str());
            }
            params = buffer;
        }
        sprintf(buffer, "%s (*%s) (%s)", TypeChain_tostring(self->result, "").c_str(), variable.c_str(), params.c_str());
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
        for (unsigned i = 0; i < self->params.size(); i++)
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

static DefinitionCollection* DefinitionCollection_init(void)
{
        DefinitionCollection* self = new DefinitionCollection();

        return self;
}

static std::string get_anonymous_name(CXCursor cursor)
{
    clang_location location = clang_location_get(clang_getCursorLocation(cursor));
    char new_name[200] = {0};
    sprintf(new_name, "__anonymous_%s_%d", location.file.c_str(), location.line);
    return new_name;
}

static std::string get_cursor_spelling(CXCursor node)
{
    std::string ret = clang_str_get(clang_getCursorSpelling(node));
    CXCursorKind kind = clang_getCursorKind(node);

    if (ret == "")
        return "";

    if (kind == CXCursor_StructDecl)
    {
        return "struct " + ret;
    }
    if (kind == CXCursor_UnionDecl)
    {
        return "union " + ret;
    }
    if (kind == CXCursor_EnumDecl)
    {
        return "enum " + ret;
    }
    return ret;
}

static StructDef* StructDef_init(CXCursor node)
{
    StructDef *self = new StructDef();
    CXCursorKind kind = clang_getCursorKind(node);
    self->location = clang_location_get(clang_getCursorLocation(node));
    self->name = get_cursor_spelling(node);
    self->is_anonymous = 0;
    if (self->name == "")
    {
        self->is_anonymous = 1;
        self->name = get_anonymous_name(node);
    }
    CXType type = clang_getCursorType(node);
    if (kind == CXCursor_TypedefDecl)
    {
        type = clang_getTypedefDeclUnderlyingType(node);
    }
    self->type = TypeChain_init(&node, type, 0);
    self->children = DefinitionCollection_init();
    if (kind == CXCursor_StructDecl)
    {
        self->structType = StructDefEnum_Struct;
    }
    if (kind == CXCursor_UnionDecl)
    {
        self->structType = StructDefEnum_Union;
    }
    if (kind == CXCursor_FieldDecl)
    {
        self->structType = StructDefEnum_Field;
    }
    if (kind == CXCursor_EnumDecl)
    {
        self->structType = StructDefEnum_Enumeration;
    }
    if (kind == CXCursor_TypedefDecl)
    {
        if (type.kind == CXType_Complex) // struct or union
        {

        }
        else
        {
            self->structType = StructDefEnum_SimpleType;
            TypeDefTarget target;
            target.name = self->name;
            target.type = 0;
            self->typedef_targets.push_back(target);
        }
    }
    self->variable_type = 0;
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
        if (self->typedef_targets.size() > 0)
            fprintf(file, "typedef ");
        std::string name = self->name;
        if (self->is_anonymous)
        {
            if (self->structType == StructDefEnum_Struct)
                name = "struct";
            if (self->structType == StructDefEnum_Union)
                name = "union";
        }
        fprintf(file, "%s%s /* %s:%d */\n", indent, name.c_str(), self->location.file.c_str(), self->location.line);
        fprintf(file, "%s{\n", indent);
        for (unsigned i = 0; i < self->children->items_ordered.size(); i++)
            StructDef_print_struct(self->children->items_ordered[i], file, depth + 1);
        if (self->structType == StructDefEnum_Enumeration)
        {
            std::string name = self->name;
            replaceAll(name, "enum ", "");
            fprintf(file, "    %s_DUMMY = 0\n", name.c_str());
        }

        // Last line
        fprintf(file, "%s}", indent);
        if (self->variable != "")
            fprintf(file, "%s", TypeChain_tostring(self->variable_type, self->variable).c_str());
        for (unsigned i = 0; i < self->typedef_targets.size(); i++)
        {
            TypeDefTarget *target = &self->typedef_targets[i];
            if (i > 0)
                fprintf(file, ",");
            fprintf(file, " %s", TypeChain_tostring(target->type, target->name).c_str());
        }
        fprintf(file, ";\n\n");
    }
    
    if (self->structType == StructDefEnum_Field)
        fprintf(file, "%s%s;\n", indent, TypeChain_tostring(self->type, self->name).c_str());

    if (self->structType == StructDefEnum_SimpleType)
    {
        fprintf(file, "typedef %s; /* %s: %d */\n", TypeChain_tostring(self->type, self->name.c_str()).c_str(), self->location.file.c_str(), self->location.line);
    }
}

static std::string StructDef_getname(StructDef* self)
{
    return self->name;
}


static std::string StructDef_make_declaration(StructDef *self)
{
    char buffer[200] = {0};
    if (self->structType == StructDefEnum_Struct || self->structType == StructDefEnum_Union || self->structType == StructDefEnum_Enumeration)
        sprintf(buffer, "%s; /* %s:%d */", self->name.c_str(), self->location.file.c_str(), self->location.line);
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
        for (unsigned i = 0; i < self->children->items_ordered.size(); i++)
            StructDef_make_dependencies(self->children->items_ordered[i], dependencies);
    }
}

static TypeChain* StructDef_resolve_typedef(StructDef* self, DefinitionCollection* definitions)
{
    return self->type;
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

static void DefinitionCollection_append(DefinitionCollection* self, CXCursor node, StructDef* new_definition)
{
    BOOL ignored = 0;

    // Ignore common definitions
    clang_location location = clang_location_get(clang_getCursorLocation(node));
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
    for (unsigned i = 0; i < sizeof(ignored_files)/sizeof(*ignored_files); i++)
    {
        if (hasEnding(location.file, ignored_files[i]))
            ignored = 1;
    }

    std::string name = StructDef_getname(new_definition);
    if (name != "")
    {
        // Only add each definition once
        if (self->items.count(name) > 0)
            return;
        if (ignored)
            self->ignored_items[name] = 1;
        self->items[name] = new_definition;
        self->items_ordered.push_back(new_definition);
    }
}
    


static BOOL DefinitionCollection_is_ignored(DefinitionCollection* self, std::string name)
{
    return self->ignored_items.count(name) > 0;
}


static TypeChain* DefinitionCollection_resolve_typedefs(DefinitionCollection* self, TypeChain* type)
{
    if (type->chainType != TypeChainEnum_Normal)
        return type;
    std::string name = type->normal;
    if (self->items.count(name) > 0)
        return StructDef_resolve_typedef(self->items[name], self);
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
    for (unsigned i = 0; i < self->params.size(); i++)
        ParamDef_make_dependencies(self->params[i], dependencies);
}


static void FunctionItem_fill(FunctionItem* self, CXCursor node)
{
    self->isEmpty = 0;
    std::vector<CXCursor> children = clang_get_children(node);
    for (unsigned i = 0; i < children.size(); i++)
    {
        CXCursor child = children[i];
        if (clang_getCursorKind(child) == CXCursor_ParmDecl)
            self->params.push_back(ParamDef_init(child));
    }
    self->return_type = TypeChain_init(0, clang_getCursorResultType(node), 0);
    self->location = clang_location_get(clang_getCursorLocation(node));
}

static std::string FunctionItem_get_arguments_decl(FunctionItem* self)
{
    if (self->params.size() == 0)
        return "void";

    char buffer[500] = {0};
    
    for (unsigned i = 0; i < self->params.size(); i++)
    {
        if (i > 0)
            strcat(buffer, ", ");
        strcat(buffer, ParamDef_tostring(self->params[i]).c_str());
    }
    return buffer;
}

static std::string FunctionItem_get_arguments_calling(FunctionItem* self)
{
    if (self->params.size() == 0)
        return "";

    char buffer[500] = {0};
    
    for (unsigned i = 0; i < self->params.size(); i++)
    {
        if (i > 0)
            strcat(buffer, ", ");
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


static void FunctionItem_parse_from_spec_line(FunctionItem* function_item, std::string line)
{
    std::vector<std::string> rows = split(line, ' ');
    function_item->callingconvention = rows[1];
    std::replace(line.begin(), line.end(), '(', ')');
    std::vector<std::string> parts = split(line, ')'); //  0 - left side of parameters, 1 - parameters, 2 - right side of parameters
    
    trim(parts[0]);
    std::vector<std::string> parts_0_split = split(parts[0], ' ');
    function_item->internalname = parts_0_split[parts_0_split.size() - 1];
    function_item->name = function_item->internalname;
    function_item->identifier = function_item->internalname;
    
    if (parts.size() < 3)
        return;
    
    if (parts[2].length() > 0)
    {
        trim(parts[2]);
        function_item->internalname = parts[2];
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
    for (unsigned i = 0; i < lines.size(); i++)
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
    
    for (unsigned i = 0; i < items_temp.size(); i++)
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

    unsigned len_diagnostics = clang_getNumDiagnostics(translationUnit);
    for (unsigned i = 0; i < len_diagnostics; i++)
    {
        CXDiagnostic diagnostic = clang_getDiagnostic(translationUnit, i);
        std::string spelling = clang_str_get(clang_getDiagnosticSpelling(diagnostic));
        clang_location location = clang_location_get(clang_getDiagnosticLocation(diagnostic));

        printf("\t\t%s %s:%d\n", spelling.c_str(), location.file.c_str(), location.line);
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
        trim(str);
        lines.push_back(str);
    }

    BOOL doadd = 0;
    for(unsigned i = 0; i < lines.size(); i++)
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
            trim(file);
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
    fprintf(file, "extern WINAPI void wine32a_%s_%s(void);  /* %s:%d */\n", dllname.c_str(), funcname.c_str(), func->location.file.c_str(), func->location.line);
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
    fprintf(file, "WINAPI %s wine32b_%s_%s(%s) /* %s:%d */\n{\n", TypeChain_tostring(func->return_type, "").c_str(), dllname.c_str(), funcname.c_str(), arguments_decl.c_str(), func->location.file.c_str(), func->location.line);
    if (has_return)
        fprintf(file, "\t%s;\n", return_type.c_str());
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

static void StructDef_set_variable(StructDef* self, CXType variable_type, std::string variable)
{
    self->variable_type = TypeChain_init(0, variable_type, 1);
    self->variable = variable;
}

static CXType resolve_type(CXType type)
{
    CXType pointee = clang_getPointeeType(type);
    BOOL is_pointer = clang_str_get(clang_getTypeSpelling(pointee)) != "";
    if (is_pointer)
        return resolve_type(pointee);
    if (clang_getArraySize(type) != -1)
        return resolve_type(clang_getArrayElementType(type));
    return type;
}

static void TypeChain_fill_typedef_name(TypeChain* self, std::string name)
{
    if (self->chainType == TypeChainEnum_Normal)
    {
        self->normal = name;
    }
    else
    {
        TypeChain_fill_typedef_name(self->subType, name);
    }
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
        CXType type = resolve_type(clang_getCursorType(node));
        CXCursor structCursor = clang_getTypeDeclaration(type);
        // Check if there is a field whichs type is an anonymous struct/union
        if (kind == CXCursor_FieldDecl && (type.kind == CXType_Elaborated))
        {
            std::string struct_name = get_cursor_spelling(structCursor);
            if (struct_name == "")
                struct_name = get_anonymous_name(structCursor);
            for (unsigned i = 0; i < definitions->items_ordered.size(); i++)
            {
                StructDef* child = definitions->items_ordered[i];
                if (child->name == struct_name)
                    StructDef_set_variable(child, clang_getCursorType(node), spelling);
            }
            definitions = DefinitionCollection_init();
        }
        else
        {
            if (!node_is_only_declaration(node))
            {
                StructDef* new_parent = StructDef_init(node);
                DefinitionCollection_append(definitions, node, new_parent);
                definitions = new_parent->children;
            }
        }

        std::vector<CXCursor> children = clang_get_children(node);
        for (unsigned i = 0; i < children.size(); i++)
        {
            find_all_definitions(children[i], definitions, funcs, source);
        }
    }
    else if (kind == CXCursor_TypedefDecl)
    {
        StructDef* type_def = StructDef_init(node);
        std::vector<CXCursor> children = clang_get_children(node);
        BOOL added_child = 0;
        for (unsigned i = 0; i < children.size(); i++)
        {
            CXCursor child = children[i];
            CXCursorKind childkind = clang_getCursorKind(child);
            // Fill in variables only for struct/union
            if (childkind != CXCursor_StructDecl && childkind != CXCursor_UnionDecl)
                continue;
            std::string struct_name = get_cursor_spelling(child);
            if (struct_name == "")
                struct_name = get_anonymous_name(child);

            if (definitions->items.count(struct_name) > 0)
            {
                added_child = 1;
                StructDef *def = definitions->items[struct_name];
                TypeChain* subTypeChain = TypeChain_init(&child, clang_getTypedefDeclUnderlyingType(node), 0);
                TypeChain_fill_typedef_name(subTypeChain, "");
                TypeDefTarget target;
                target.name = spelling;
                target.type = subTypeChain;
                def->typedef_targets.push_back(target);
            }
        }
        if (!added_child)
        {
            DefinitionCollection_append(definitions, node, type_def);
        }
    }
}



static void handle_dll_source(std::string dll_path, std::string source, FunctionCollection* funcs, DefinitionCollection* ret_definitions)
{
    std::string path_file = dll_path + "/" + source;

    CXCursor cursor = parse_file(path_file);

    std::vector<CXCursor> children = clang_get_children(cursor);
    for (unsigned i = 0; i < children.size(); i++)
    {
        find_all_definitions(children[i], ret_definitions, funcs, source);
    }
}

static void handle_dll(const char* name)
{
    char path_dll[255];
    char path_source[255];
    char path_spec[255];
    char path_makefile[255];
    FILE* file_source;

    printf("Started %s\n", name);

    sprintf(path_dll, "../dlls/%s", name);
    sprintf(path_source, "../dlls/winethunks/%s.c", name);
    sprintf(path_spec, "../dlls/%s/%s.spec", name, name);
    sprintf(path_makefile, "../dlls/%s/Makefile.in", name);

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
    for (unsigned i = 0; i < sources.size(); i++)
    {
        std::string source = sources[i];
        //if not source.endswith("version.c"):
        //    continue
        printf("\tAt %s/%s\n", name, source.c_str());
        handle_dll_source(path_dll, source, funcs, definitionCollection);
    }
    
    // Make dependencies
    DependencyCollection* dependencies = DependencyCollection_init(definitionCollection);
    for (std::pair<std::string, FunctionItem*> element : funcs->items)
    {
        FunctionItem* func = element.second;
        if (!FunctionItem_is_empty(func))
            FunctionItem_make_dependencies(func, dependencies);
    }
    std::vector<StructDef*> usedDefinitions;
    
    for (unsigned i = 0; i < definitionCollection->items_ordered.size(); i++)
    {
        StructDef* definition = definitionCollection->items_ordered[i];
        std::string definition_name = StructDef_getname(definition);
        BOOL in_dependencies = std::find(dependencies->items.begin(), dependencies->items.end(), definition_name) != dependencies->items.end();
        if (in_dependencies && !DefinitionCollection_is_ignored(definitionCollection, definition_name))
            usedDefinitions.push_back(definition);
    }

    for (unsigned i = 0; i < usedDefinitions.size(); i++)
    {
        StructDef* definition = usedDefinitions[i];
        std::string declaration = StructDef_make_declaration(definition);
        if (declaration != "")
            fprintf(file_source, "%s\n", declaration.c_str());
    }
    fprintf(file_source, "\n");
    for (unsigned i = 0; i < usedDefinitions.size(); i++)
    {
        StructDef* definition = usedDefinitions[i];
        StructDef_print_struct(definition, file_source, 0);
    }
    
    
    // Make function pointers
    for (std::pair<std::string, FunctionItem*> element : funcs->items)
    {
        FunctionItem* func = element.second;
        if (!FunctionItem_is_empty(func))
        {
            std::string arguments = FunctionItem_get_arguments_decl(func);
            fprintf(file_source, "static WINAPI %s (*p%s)(%s);\n", TypeChain_tostring(func->return_type, "").c_str(), func->identifier.c_str(), arguments.c_str());
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
            fprintf(file_source, "\tp%s = (void *)GetProcAddress(library, \"%s\");\n", func->identifier.c_str(), func->name.c_str());
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
        "kernel32",
        "advapi32",
        "msvcrt",
        "ntdll",
        "kernelbase",
    };

    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        handle_dll(dlls[i]);
    }
    
    FILE* file_shared = fopen("../dlls/winethunks/winethunks_shared.c", "w");
    FILE* file_makefile = fopen("../dlls/winethunks/Makefile.in", "w");
    
    fprintf(file_shared, "#include <windows.h>\n\n");

    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        fprintf(file_shared, "void* wine_thunk_get_for_%s(void *func);\n", dlls[i]);
    }
    fprintf(file_shared, "\n");

    // wine_thunk_get_for_any
    fprintf(file_shared, "WINAPI void *wine_thunk_get_for_any(void *func)\n");
    fprintf(file_shared, "{\n");
    fprintf(file_shared, "\tvoid *ret;\n");
    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        fprintf(file_shared, "\tif ((ret = wine_thunk_get_for_%s(func)) != NULL)\n", dlls[i]);
        fprintf(file_shared, "\t\treturn ret;\n");
    }
    fprintf(file_shared, "\n");
    fprintf(file_shared, "\treturn func;\n");
    fprintf(file_shared, "}\n\n");

    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        fprintf(file_shared, "void* wine_thunk_initialize_%s(void);\n", dlls[i]);
    }
    fprintf(file_shared, "\n");

    // wine_thunk_initialize_dll
    fprintf(file_shared, "WINAPI void wine_thunk_initialize_any(const char *dll)\n");
    fprintf(file_shared, "{\n");
    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        fprintf(file_shared, "\tif (!strcasecmp(\"%s.dll\", dll))\n", dlls[i]);
        fprintf(file_shared, "\t\twine_thunk_initialize_%s();\n", dlls[i]);
    }
    fprintf(file_shared, "}\n");

    // Make makefile
    fprintf(file_makefile, "MODULE    = winethunks.dll\n");
    fprintf(file_makefile, "IMPORTLIB = winethunks\n");
    fprintf(file_makefile, "\n");
    fprintf(file_makefile, "C_SRCS = \\\n");
    for (unsigned i = 0; i < sizeof(dlls)/sizeof(*dlls); i++)
    {
        fprintf(file_makefile, "\t%s.c \\\n", dlls[i]);
    }
    fprintf(file_makefile, "\twinethunks_shared.c \\\n");
    fprintf(file_makefile, "\twinethunks_main.c\n");

    fclose(file_makefile);
    fclose(file_shared);
}

static void run_test()
{
    FILE* file_test = fopen("make_thunks.test.out", "w");
    CXCursor cursor = parse_file("make_thunks.test.c");


    FunctionCollection* funcs = FunctionCollection_init();
    DefinitionCollection* definitionCollection = DefinitionCollection_init();

    std::vector<CXCursor> children = clang_get_children(cursor);
    for (unsigned i = 0; i < children.size(); i++)
    {
        find_all_definitions(children[i], definitionCollection, funcs, "make_thunks.test.c");
    }

    for (unsigned i = 0; i < definitionCollection->items_ordered.size(); i++)
    {
        StructDef* definition = definitionCollection->items_ordered[i];
        StructDef_print_struct(definition, file_test, 0);
    }
    fclose(file_test);
}

static void print_help(void)
{
    printf(
        "Usage: ./make_thunks MODE [options]\n"
        "\n"
        "Processing modes Options:\n"
        "-h, --help                      Display this help."
        "-a, --generate-thunks-all       Generate all thunks, including the Makefile and shared components.\n"
        "-u, --update-thunks             Regenerate the thunks for a single dll, without touching the Makefile or shared components.\n"
        "-f, --fixup-sources             Fixup the wine sources to work with wine-pure. All structures need to have a 32bit layout.\n"
        "--test                          Run the tests\n"
        "\n"
        "Options:\n"
        "-t NUMBER, --threads NUMBER     Number of threads to use (default 4). To disable threading, set to 1.\n"

    );
}

int main (int argc, const char*argv[])
{
    int i;
    BOOL opt_a = 0, opt_u = 0, opt_f = 0, opt_test = 0;
    int num_modes = 0;
    int opt_t = 4;

    for (i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "--test"))
        {
            opt_test = 1;
        }
        else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            print_help();
            return 0;
        }
        else if (!strcmp(argv[i], "-a") || !strcmp(argv[i], "--generate-thunks-all"))
        {
            opt_a = 1;
        }
        else if (!strcmp(argv[i], "-u") || !strcmp(argv[i], "--update-thunks"))
        {
            opt_u = 1;
        }
        else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--fixup-sources"))
        {
            opt_f = 1;
        }
        else if (!strcmp(argv[i], "-t") || !strcmp(argv[i], "--threads"))
        {
            i++;
            if (i >= argc)
            {
                printf("Missing parameter to -t\n");
                return -1;
            }
            opt_t = atoi(argv[i]);
            if (opt_t < 1)
            {
                printf("Please set threads to use to a number > 0\n");
                return -1;
            }
        }
        else
        {
            printf("Unknown option %s\n", argv[i]);
            return -1;
        }
    }

    if (opt_a)
        num_modes++;
    if (opt_f)
        num_modes++;
    if (opt_u)
        num_modes++;
    if (opt_test)
        num_modes++;

    if (num_modes != 1)
    {
        printf("Please select exactly one processing mode. See -h for help.\n");
        return -1;
    }

    if (opt_a)
    {
        handle_all_dlls();
    }

    if (opt_test)
    {
        run_test();
    }

    return 0;
}
