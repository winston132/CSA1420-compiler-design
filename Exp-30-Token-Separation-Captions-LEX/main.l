%{
#include <stdio.h>

int kw_cnt = 0, id_cnt = 0, const_cnt = 0, op_cnt = 0, sym_cnt = 0;
%}

%%

#[ \t]*"include"[ \t]*[<"][^>\n\r"]+[>"] { 
    printf("%-20s : %s\n", "[HEADER DIRECTIVE]", yytext); 
}

"void"|"int"|"char"|"float"|"double"|"return"|"main" {
    printf("%-20s : %s\n", "[KEYWORD / BUILTIN]", yytext);
    kw_cnt++;
}

"printf" {
    printf("%-20s : %s\n", "[STANDARD FUNCTION]", yytext);
    id_cnt++;
}

[0-9]+(\.[0-9]+)? {
    printf("%-20s : %s\n", "[NUMERIC CONSTANT]", yytext);
    const_cnt++;
}

\"[^\n\"]*\" {
    printf("%-20s : %s\n", "[STRING LITERAL]", yytext);
    const_cnt++;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("%-20s : %s\n", "[IDENTIFIER]", yytext);
    id_cnt++;
}

"="|"+"|"-"|"*"|"/" {
    printf("%-20s : %s\n", "[OPERATOR]", yytext);
    op_cnt++;
}

[;(),{}] {
    printf("%-20s : %s\n", "[SPECIAL SYMBOL]", yytext);
    sym_cnt++;
}

\n         { /* Ignore */ }
[ \t]+     { /* Ignore */ }
.          { /* Ignore */ }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("     LEX PROGRAM: C TOKEN SEPARATION WITH CAPTIONS                    \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", fname);
    printf("%-20s : %s\n", "Token Caption", "Lexeme");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("TOKEN SEPARATION SUMMARY:\n");
    printf("  Keywords & Builtins : %d\n", kw_cnt);
    printf("  Identifiers         : %d\n", id_cnt);
    printf("  Constants           : %d\n", const_cnt);
    printf("  Operators           : %d\n", op_cnt);
    printf("  Special Symbols     : %d\n", sym_cnt);
    printf("======================================================================\n");
    return 0;
}
