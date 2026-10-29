%{
#include <stdio.h>
#include <string.h>
int kw_count = 0;
int id_count = 0;
%}

KEYWORD auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while

%%
{KEYWORD} {
    printf("[KEYWORD]    : %-15s (C Reserved Word)\n", yytext);
    kw_count++;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    printf("[IDENTIFIER] : %-15s (User Defined Identifier)\n", yytext);
    id_count++;
}

[0-9]+(\.[0-9]+)? { /* ignore numeric constants */ }
\"(\\.|[^"\\])*\" { /* ignore string literals */ }
\'(\\.|[^'\\])\'  { /* ignore character literals */ }
"//".*            { /* ignore single-line comments */ }
"/*"([^*]|\*+[^/*])*\*+"/" { /* ignore multi-line comments */ }
[ \t\r\n]+        { /* ignore whitespace */ }
.                 { /* ignore operators & punctuation */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "input.c";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error opening file %s\n", fname);
        return 1;
    }
    printf("=====================================================\n");
    printf("   EXP 32: SEPARATE KEYWORDS & IDENTIFIERS (LEX)     \n");
    printf("=====================================================\n");
    printf("Source File: %s\n\n", fname);
    yyin = fp;
    yylex();
    fclose(fp);
    printf("\n-----------------------------------------------------\n");
    printf("Total Keywords Found    : %d\n", kw_count);
    printf("Total Identifiers Found : %d\n", id_count);
    printf("=====================================================\n");
    return 0;
}
