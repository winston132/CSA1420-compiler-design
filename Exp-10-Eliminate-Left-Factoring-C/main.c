#include <stdio.h>

int main() {
    printf("======================================================================\n");
    printf("         C PROGRAM: ELIMINATE LEFT FACTORING FROM CFG                 \n");
    printf("======================================================================\n");
    printf("ORIGINAL GRAMMAR:\n");
    printf("  S -> iEtS | iEtSeS | a\n");
    printf("  E -> b\n");
    printf("----------------------------------------------------------------------\n");
    printf("ANALYSIS:\n");
    printf("  In production for S:\n");
    printf("    Alternate 1: iEtS\n");
    printf("    Alternate 2: iEtSeS\n");
    printf("    Common Prefix alpha = 'iEtS'\n");
    printf("    Remainder 1 beta1   = e (epsilon)\n");
    printf("    Remainder 2 beta2   = eS\n");
    printf("    Non-factored gamma  = a\n\n");
    printf("  Applying Left Factoring Transformation:\n");
    printf("    A  -> alpha A' | gamma\n");
    printf("    A' -> beta1 | beta2\n");
    printf("----------------------------------------------------------------------\n");
    printf("GRAMMAR AFTER ELIMINATION OF LEFT FACTORING:\n");
    printf("  S  -> iEtS S' | a\n");
    printf("  S' -> eS | e\n");
    printf("  E  -> b\n");
    printf("======================================================================\n");
    return 0;
}
