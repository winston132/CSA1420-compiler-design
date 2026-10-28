%{
#include <stdio.h>

int tag_count = 0;
%}

%%

"<"[^>]+">"          { 
                        printf("Tag #%-3d : %-20s (Length: %d)\n", ++tag_count, yytext, yyleng); 
                     }
\n                   { /* Ignore */ }
.                    { /* Ignore text */ }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *fname = (argc > 1) ? argv[1] : "sample.html";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", fname);
        return 1;
    }

    printf("======================================================================\n");
    printf("         LEX PROGRAM: EXTRACT AND PRINT ALL HTML TAGS                 \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", fname);
    printf("DETECTED HTML TAGS:\n");
    printf("----------------------------------------------------------------------\n");

    yyin = fp;
    yylex();
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("Total HTML Tags Found: %d\n", tag_count);
    printf("======================================================================\n");
    return 0;
}
