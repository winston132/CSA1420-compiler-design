%{
#include <stdio.h>
#include <stdlib.h>
int pos_count = 0;
int neg_count = 0;
int zero_count = 0;
%}

%%
\+?[0-9]+(\.[0-9]+)? {
    double val = atof(yytext);
    if (val == 0.0) {
        printf("[ZERO]     : %-10s\n", yytext);
        zero_count++;
    } else {
        printf("[POSITIVE] : %-10s (Value: +%.2f)\n", yytext, val);
        pos_count++;
    }
}

-[0-9]+(\.[0-9]+)? {
    double val = atof(yytext);
    printf("[NEGATIVE] : %-10s (Value: %.2f)\n", yytext, val);
    neg_count++;
}

[ \t\r\n,]+ { /* ignore whitespace and commas */ }
.           { /* ignore other characters */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=====================================================\n");
    printf("  EXP 33: COUNT POSITIVE & NEGATIVE NUMBERS (LEX)    \n");
    printf("=====================================================\n");
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Error opening file %s\n", argv[1]);
            return 1;
        }
        yyin = fp;
    }
    yylex();
    printf("\n-----------------------------------------------------\n");
    printf("Positive Numbers Count : %d\n", pos_count);
    printf("Negative Numbers Count : %d\n", neg_count);
    printf("Zero Count             : %d\n", zero_count);
    printf("Total Numbers Scanned  : %d\n", pos_count + neg_count + zero_count);
    printf("=====================================================\n");
    return 0;
}
