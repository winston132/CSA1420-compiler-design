%{
#include <stdio.h>

int valid_mob = 0;
int invalid_mob = 0;
%}

MOBILE_VALID   [6-9][0-9]{9}
INVALID_TOKEN  [a-zA-Z0-9]+

%%

^{MOBILE_VALID}$    { printf("%-16s -> [VALID] 10-Digit Mobile Number (Starts with %c)\n", yytext, yytext[0]); valid_mob++; }
^{INVALID_TOKEN}$   { printf("%-16s -> [INVALID] Incorrect digit count or starting digit\n", yytext); invalid_mob++; }
\n                  { /* Ignore */ }
[ \t]+              { /* Ignore */ }
.                   { /* Ignore */ }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "numbers.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("     LEX PROGRAM: EMPLOYEE MOBILE NUMBER VALIDATOR                    \n");
    printf("======================================================================\n");
    printf("Verification Log: %s\n\n", fname);
    printf("VALIDATION STATUS:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total Valid Mobile Numbers   : %d\n", valid_mob);
    printf("Total Invalid Mobile Numbers : %d\n", invalid_mob);
    printf("======================================================================\n");
    return 0;
}
