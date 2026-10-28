%{
#include <stdio.h>

int valid_count = 0;
int invalid_count = 0;
%}

EMAIL   [a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}

%%

{EMAIL}             { printf("%-30s -> [VALID EMAIL]\n", yytext); valid_count++; }
[a-zA-Z0-9._%+-@]+  { printf("%-30s -> [INVALID EMAIL]\n", yytext); invalid_count++; }
\n                  { /* Ignore */ }
[ \t]+              { /* Ignore */ }
.                   { /* Ignore */ }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "emails.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("         LEX PROGRAM: EMAIL ADDRESS VALIDATOR                         \n");
    printf("======================================================================\n");
    printf("Input File: %s\n\n", fname);
    printf("EMAIL VALIDATION RESULTS:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Valid Emails   : %d\n", valid_count);
    printf("Total Invalid Emails : %d\n", invalid_count);
    printf("======================================================================\n");
    return 0;
}
