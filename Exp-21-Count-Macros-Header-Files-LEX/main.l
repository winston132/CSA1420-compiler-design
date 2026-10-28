%{
#include <stdio.h>

int macro_count = 0;
int header_count = 0;
%}

%%

#[ \t]*"define"[ \t]+[^\n\r]+        { 
                                        printf("Macro Defined     : %s\n", yytext); 
                                        macro_count++; 
                                    }

#[ \t]*"include"[ \t]*[<"][^>\n\r"]+[>"] { 
                                        printf("Header File Found : %s\n", yytext); 
                                        header_count++; 
                                    }

"//".*                              { /* Ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/"          { /* Ignore multi-line comments */ }

\n                                  { /* Ignore */ }
[ \t]+                              { /* Ignore */ }
.                                   { /* Ignore */ }

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
    printf("   LEX PROGRAM: COUNT MACROS DEFINED & HEADER FILES INCLUDED          \n");
    printf("======================================================================\n");
    printf("Scanning file: %s\n\n", fname);

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Macros Defined        : %d\n", macro_count);
    printf("Total Header Files Included : %d\n", header_count);
    printf("======================================================================\n");
    return 0;
}
