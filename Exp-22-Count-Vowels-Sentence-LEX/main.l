%{
#include <stdio.h>

int v_a = 0, v_e = 0, v_i = 0, v_o = 0, v_u = 0;
int total_vowels = 0;
%}

%%

[aA]    { v_a++; total_vowels++; }
[eE]    { v_e++; total_vowels++; }
[iI]    { v_i++; total_vowels++; }
[oO]    { v_o++; total_vowels++; }
[uU]    { v_u++; total_vowels++; }
\n      { /* ignore */ }
.       { /* ignore consonants, digits, and symbols */ }

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

    printf("======================================================================\n");
    printf("        LEX PROGRAM: COUNT NUMBER OF VOWELS IN A SENTENCE             \n");
    printf("======================================================================\n");
    printf("Input Sentence File: %s\n", fname);
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("VOWEL FREQUENCY BREAKDOWN:\n");
    printf("  Vowel 'A' / 'a' : %d\n", v_a);
    printf("  Vowel 'E' / 'e' : %d\n", v_e);
    printf("  Vowel 'I' / 'i' : %d\n", v_i);
    printf("  Vowel 'O' / 'o' : %d\n", v_o);
    printf("  Vowel 'U' / 'u' : %d\n", v_u);
    printf("----------------------------------------------------------------------\n");
    printf("TOTAL NUMBER OF VOWELS IDENTIFIED: %d\n", total_vowels);
    printf("======================================================================\n");
    return 0;
}
