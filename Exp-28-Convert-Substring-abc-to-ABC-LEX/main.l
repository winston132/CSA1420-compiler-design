%{
#include <stdio.h>

int replace_count = 0;
%}

%%

"abc"   { printf("ABC"); replace_count++; }
.       { putchar(yytext[0]); }
\n      { putchar('\n'); }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "input.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("     LEX PROGRAM: CONVERT SUBSTRING 'abc' TO 'ABC'                    \n");
    printf("======================================================================\n");
    printf("Input File: %s\n\n", fname);
    printf("TRANSFORMED STRING OUTPUT:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("\n----------------------------------------------------------------------\n");
    printf("Total 'abc' Substrings Converted to 'ABC': %d\n", replace_count);
    printf("======================================================================\n");
    return 0;
}
