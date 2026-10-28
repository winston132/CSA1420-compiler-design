%{
#include <stdio.h>

int comment_count = 0;
%}

%%

"//".*                  { 
                            comment_count++; 
                        }

"/*"([^*]|\*+[^*/])*\*+"/" { 
                            comment_count++; 
                        }

.                       { fputc(yytext[0], yyout); }
\n                      { fputc('\n', yyout); }

%%

int yywrap(void) {
    return 1;
}

int main(int argc, char **argv) {
    const char *in_name = (argc > 1) ? argv[1] : "input.c";
    const char *out_name = (argc > 2) ? argv[2] : "output.c";

    FILE *fin = fopen(in_name, "r");
    if (!fin) {
        printf("Error opening %s\n", in_name);
        return 1;
    }

    FILE *fout = fopen(out_name, "w");
    if (!fout) {
        printf("Error opening %s\n", out_name);
        fclose(fin);
        return 1;
    }

    printf("======================================================================\n");
    printf("   LEX PROGRAM: COUNT AND ELIMINATE COMMENTS IN C PROGRAM             \n");
    printf("======================================================================\n");
    printf("Input File  : %s\n", in_name);
    printf("Output File : %s\n\n", out_name);

    yyin = fin;
    yyout = fout;
    yylex();

    fclose(fin);
    fclose(fout);

    printf("----------------------------------------------------------------------\n");
    printf("Total Comment Blocks Eliminated : %d\n", comment_count);
    printf("Successfully wrote clean C source code to '%s'\n", out_name);
    printf("======================================================================\n");
    return 0;
}
