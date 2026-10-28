%{
#include <stdio.h>
#include <stdlib.h>

int char_count = 0;
int word_count = 0;
int line_count = 0;
%}

%%

\n              { line_count++; char_count++; }
[^ \t\n\r]+    { word_count++; char_count += yyleng; }
.               { char_count++; }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("   LEX PROGRAM: COUNT CHARACTERS, WORDS, AND LINES IN C FILE          \n");
    printf("======================================================================\n");
    printf("Scanning file: %s\n\n", fname);

    yyin = fp;
    yylex();
    fclose(fp);

    printf("%-30s : %d\n", "Total Characters (Bytes)", char_count);
    printf("%-30s : %d\n", "Total Words Counted", word_count);
    printf("%-30s : %d\n", "Total Lines Counted", line_count);
    printf("======================================================================\n");
    return 0;
}
