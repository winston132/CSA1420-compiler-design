%{
#include <stdio.h>

int const_count = 0;
%}

%%

[0-9]+\.[0-9]+        { printf("Floating-Point Constant : %s\n", yytext); const_count++; }
[0-9]+                { printf("Integer Constant        : %s\n", yytext); const_count++; }
\"[^\n\"]*\"          { printf("String Literal Constant : %s\n", yytext); const_count++; }
\'[^\n\']\'           { printf("Character Constant      : %s\n", yytext); const_count++; }

#[ \t]*include[^\n]*  { /* Ignore */ }
#[ \t]*define[ \t]+[A-Za-z_][A-Za-z0-9_]*[ \t]+ { /* skip */ }

"//".*                { /* Ignore */ }
[ \t\n\r]+            { /* Ignore */ }
.                     { /* Ignore */ }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error opening %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("         LEX PROGRAM: EXTRACT AND PRINT ALL CONSTANTS                 \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", fname);
    printf("DETECTED CONSTANTS:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Constants Detected: %d\n", const_count);
    printf("======================================================================\n");
    return 0;
}
