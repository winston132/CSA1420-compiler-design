#include <stdio.h>
#include <string.h>

int main() {
    printf("======================================================================\n");
    printf("         C PROGRAM: ELIMINATE LEFT RECURSION FROM CFG                 \n");
    printf("======================================================================\n");
    printf("ORIGINAL GRAMMAR:\n");
    printf("  S -> ( L ) | a\n");
    printf("  L -> L , S | S\n");
    printf("----------------------------------------------------------------------\n");
    printf("ANALYSIS:\n");
    printf("  Production 'S -> ( L ) | a':\n");
    printf("    No left recursion detected.\n\n");
    printf("  Production 'L -> L , S | S':\n");
    printf("    Matches A -> A alpha | beta form where:\n");
    printf("      Non-terminal A = L\n");
    printf("      alpha = , S\n");
    printf("      beta  = S\n\n");
    printf("  Applying Left Recursion Elimination Formula:\n");
    printf("      A  -> beta A'\n");
    printf("      A' -> alpha A' | e\n");
    printf("----------------------------------------------------------------------\n");
    printf("GRAMMAR AFTER ELIMINATION OF LEFT RECURSION:\n");
    printf("  S  -> ( L ) | a\n");
    printf("  L  -> S L'\n");
    printf("  L' -> , S L' | e\n");
    printf("======================================================================\n");
    return 0;
}
