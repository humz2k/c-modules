from pycparser import parse_file, c_generator
from pycparser.c_ast import NodeVisitor
import pycparser
from includes_std import *

class DeclarationExtractor(NodeVisitor):
    def __init__(self):
        self.declarations = []
        self.generator = c_generator.CGenerator()

    def visit_FuncDecl(self, node):
        decl = self.generator.visit(node.type)
        if node.type.declname:
            decl += ' ' + node.type.declname
        self.declarations.append(decl + ';')

    def visit_Decl(self, node):
        if isinstance(node.type, (pycparser.c_ast.Struct, pycparser.c_ast.Union)) and node.name is None:
            # This handles anonymous structs and unions within typedefs
            self.visit(node.type)
        elif node.init is None:  # Filter out variable declarations without initialization (globals)
            decl = self.generator.visit(node)
            self.declarations.append(decl + ';')

    def visit_Struct(self, node):
        if not node.decls:  # Skip forward declarations of structs
            return
        decl = self.generator.visit(node)
        self.declarations.append(decl + ';')

    def visit_Typedef(self, node):
        decl = self.generator.visit(node)
        self.declarations.append(decl + ';')

def extract_declarations(c_file_path):
    ast = parse_file(c_file_path, use_cpp=True, cpp_path='gcc', cpp_args=['-E', r'-Ifake_libc_include'])
    extractor = DeclarationExtractor()
    extractor.visit(ast)
    return extractor.declarations

def write_header_file(declarations, header_file_path):
    out = ""
    for decl in declarations:
        out += decl + "\n"
    out = out.replace(stdlib_h,"#include <stdlib.h>\n#include <stdio.h>\n")
    module_name = header_file_path.split("/")[-1].split(".")[0].strip().replace(" ","_")
    out = "#ifndef _IMPORTED_MODULE_" + str(module_name) + "_\n#define _IMPORTED_MODULE_" + str(module_name) + "_\n" +  out + "\n#endif\n"
    with open(header_file_path, 'w') as header_file:
        header_file.write(out)

c_file_path = 'example.c'  # Path to your .c file
header_file_path = 'example.h'  # Output header file path

declarations = extract_declarations(c_file_path)
write_header_file(declarations, header_file_path)
