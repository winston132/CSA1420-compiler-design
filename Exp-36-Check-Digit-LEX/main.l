%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int digit_count = 0;
int non_digit_count = 0;
%}

%%
[^\r\n]+ {
    int is_all_digits = 1;
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (!isdigit((unsigned char)yytext[i])) {
            is_all_digits = 0;
            break;
        }
    }
    if (is_all_digits && strlen(yytext) == 1) {
        printf("[SINGLE DIGIT] : %-12s -> Valid single decimal digit '%s'\n", yytext, yytext);
        digit_count++;
    } else if (is_all_digits) {
        printf("[NUMBER/DIGITS]: %-12s -> Valid sequence of %d digits\n", yytext, (int)strlen(yytext));
        digit_count++;
    } else {
        printf("[NOT A DIGIT]  : %-12s -> Contains non-digit symbols/letters\n", yytext);
        non_digit_count++;
    }
}

[\r\n]+ { /* skip */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=================================================================\n");
    printf("              EXP 36: DIGIT CHECKER (LEX)                        \n");
    printf("=================================================================\n");
    if (argc > 1) {
        FILE *fp = fopen(argv[1], "r");
        if (!fp) {
            printf("Error opening file %s\n", argv[1]);
            return 1;
        }
        yyin = fp;
    }
    yylex();
    printf("\n-----------------------------------------------------------------\n");
    printf("Total Valid Digits/Numbers : %d\n", digit_count);
    printf("Total Non-Digit Tokens     : %d\n", non_digit_count);
    printf("=================================================================\n");
    return 0;
}
