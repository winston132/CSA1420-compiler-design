%{
#include <stdio.h>
#include <string.h>

int valid_count = 0;
int invalid_count = 0;

int is_valid_url(const char *s) {
    if (strncmp(s, "http://", 7) != 0 &&
        strncmp(s, "https://", 8) != 0 &&
        strncmp(s, "ftp://", 6) != 0) {
        return 0;
    }
    const char *domain = strstr(s, "://") + 3;
    if (strlen(domain) < 4) return 0;
    if (*domain == '/' || *domain == '.') return 0;
    const char *dot = strchr(domain, '.');
    if (!dot || *(dot + 1) == '\0' || *(dot + 1) == '.') return 0;
    return 1;
}
%}

%%
[^\r\n]+ {
    if (is_valid_url(yytext)) {
        printf("[VALID URL]   : %s\n", yytext);
        valid_count++;
    } else {
        printf("[INVALID URL] : %s\n", yytext);
        invalid_count++;
    }
}

[\r\n]+ { /* skip blank lines */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=====================================================\n");
    printf("      EXP 34: URL VALIDATION SYSTEM (LEX)            \n");
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
    printf("Total Valid URLs   : %d\n", valid_count);
    printf("Total Invalid URLs : %d\n", invalid_count);
    printf("=====================================================\n");
    return 0;
}
