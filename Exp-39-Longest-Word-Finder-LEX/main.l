%{
#include <stdio.h>
#include <string.h>

char longest_word[256] = "";
int max_len = 0;
int word_count = 0;
%}

%%
[a-zA-Z]+ {
    word_count++;
    if (yyleng > max_len) {
        max_len = yyleng;
        strncpy(longest_word, yytext, sizeof(longest_word) - 1);
        longest_word[sizeof(longest_word) - 1] = '\0';
    }
}

[ \t\r\n]+ { /* ignore whitespace */ }
.          { /* ignore digits & punctuation */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    printf("=====================================================\n");
    printf("         EXP 39: LONGEST WORD FINDER (LEX)           \n");
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
    printf("Total Words Processed : %d\n", word_count);
    printf("Longest Word Found    : \"%s\"\n", longest_word);
    printf("Length of Word        : %d characters\n", max_len);
    printf("=====================================================\n");
    return 0;
}
