%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_dob = 0;
int invalid_dob = 0;

int is_leap(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void validate_date(int d, int m, int y, const char *orig) {
    int max_d = 31;
    if (y < 1900 || y > 2026) {
        printf("[INVALID DOB] : %-12s -> Year %d out of valid range (1900-2026)\n", orig, y);
        invalid_dob++;
        return;
    }
    if (m < 1 || m > 12) {
        printf("[INVALID DOB] : %-12s -> Month %d is invalid (must be 1-12)\n", orig, m);
        invalid_dob++;
        return;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        max_d = 30;
    } else if (m == 2) {
        max_d = is_leap(y) ? 29 : 28;
    }
    if (d < 1 || d > max_d) {
        printf("[INVALID DOB] : %-12s -> Day %d exceeds month maximum of %d days\n", orig, d, max_d);
        invalid_dob++;
        return;
    }
    printf("[VALID DOB]   : %-12s -> Day:%02d, Month:%02d, Year:%d%s\n",
           orig, d, m, y, (m == 2 && is_leap(y)) ? " (Leap Year)" : "");
    valid_dob++;
}
%}

%%
[0-9]{1,2}[/-][0-9]{1,2}[/-][0-9]{4} {
    int d, m, y;
    if (strchr(yytext, '/')) {
        sscanf(yytext, "%d/%d/%d", &d, &m, &y);
    } else {
        sscanf(yytext, "%d-%d-%d", &d, &m, &y);
    }
    validate_date(d, m, y, yytext);
}

[^\r\n]+ {
    printf("[INVALID DOB] : %-12s -> Malformed date format (expected DD/MM/YYYY)\n", yytext);
    invalid_dob++;
}

[\r\n]+ { /* skip */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=================================================================\n");
    printf("        EXP 35: STUDENT DATE OF BIRTH VALIDATOR (LEX)            \n");
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
    printf("Total Valid DOB Entries   : %d\n", valid_dob);
    printf("Total Invalid DOB Entries : %d\n", invalid_dob);
    printf("=================================================================\n");
    return 0;
}
