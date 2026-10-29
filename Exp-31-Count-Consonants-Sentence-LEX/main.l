%{
#include <stdio.h>
#include <ctype.h>
int cons_count = 0;
int vowel_count = 0;
%}

%%
[aeiouAEIOU] {
    vowel_count++;
}

[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z] {
    printf("  Found Consonant : '%c'\n", yytext[0]);
    cons_count++;
}

[0-9]+ { /* ignore digits */ }

[ \t\r\n]+ { /* ignore whitespace */ }

. { /* ignore punctuation */ }
%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "sentence.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }
    printf("=====================================================\n");
    printf("   EXP 31: CONSONANT IDENTIFIER & COUNTER (LEX)      \n");
    printf("=====================================================\n");
    printf("Input Sentence File: %s\n\n", fname);
    yyin = fp;
    yylex();
    fclose(fp);
    printf("\n-----------------------------------------------------\n");
    printf("Total Consonants Found : %d\n", cons_count);
    printf("Total Vowels Found     : %d\n", vowel_count);
    printf("=====================================================\n");
    return 0;
}
