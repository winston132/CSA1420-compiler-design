%{
#include <stdio.h>

int cap_count = 0;
%}

%%

[A-Z]+      { 
                printf("[CAPITAL WORD] %-15s (Length: %d)\n", yytext, yyleng); 
                cap_count++; 
            }
[a-zA-Z]+   { /* Ignore */ }
\n          { /* Ignore */ }
.           { /* Ignore */ }

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
    printf("         LEX PROGRAM: IDENTIFY CAPITAL WORDS FROM INPUT               \n");
    printf("======================================================================\n");
    printf("Input File: %s\n\n", fname);
    printf("IDENTIFIED CAPITAL WORDS:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Capital Words Identified: %d\n", cap_count);
    printf("======================================================================\n");
    return 0;
}
