%{
#include <stdio.h>

int line_number = 1;
%}

%%

.*\n    { printf("%4d | %s", line_number++, yytext); }
.+      { printf("%4d | %s\n", line_number++, yytext); }

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
    printf("         LEX PROGRAM: ADD LINE NUMBERS TO C SOURCE FILE               \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", fname);
    printf("NUMBERED SOURCE CODE:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Lines Displayed: %d\n", line_number - 1);
    printf("======================================================================\n");
    return 0;
}
