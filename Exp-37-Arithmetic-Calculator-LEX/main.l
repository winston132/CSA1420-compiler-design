%{
#include <stdio.h>
#include <stdlib.h>
int op_count = 0;
%}

%%
[0-9]+(\.[0-9]+)?[ \t]*[\+\-\*\/\%][ \t]*[0-9]+(\.[0-9]+)? {
    double op1 = 0, op2 = 0, res = 0;
    char op = 0;
    char *p = yytext;
    op1 = strtod(p, &p);
    while (*p == ' ' || *p == '\t') p++;
    op = *p++;
    op2 = strtod(p, NULL);

    int err = 0;
    switch(op) {
        case '+': res = op1 + op2; break;
        case '-': res = op1 - op2; break;
        case '*': res = op1 * op2; break;
        case '/':
            if (op2 == 0) {
                printf("[DIV BY ZERO] : %s\n", yytext);
                err = 1;
            } else {
                res = op1 / op2;
            }
            break;
        case '%':
            if ((int)op2 == 0) {
                printf("[MOD BY ZERO] : %s\n", yytext);
                err = 1;
            } else {
                res = (int)op1 % (int)op2;
            }
            break;
        default: err = 1; break;
    }
    if (!err) {
        printf("[EVALUATED] %-20s = %.2f\n", yytext, res);
        op_count++;
    }
}

[^\r\n]+ {
    printf("[INVALID EXPR] : %s\n", yytext);
}

[\r\n]+ { /* skip */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=====================================================\n");
    printf("     EXP 37: ARITHMETIC CALCULATOR (LEX)             \n");
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
    printf("Total Operations Evaluated : %d\n", op_count);
    printf("=====================================================\n");
    return 0;
}
