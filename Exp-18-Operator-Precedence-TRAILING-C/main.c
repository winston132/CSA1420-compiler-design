#include <stdio.h>

int main() {
    printf("======================================================================\n");
    printf("       OPERATOR PRECEDENCE PARSER: TRAILING() SET COMPUTATION         \n");
    printf("======================================================================\n");
    printf("GIVEN GRAMMAR:\n");
    printf("  E -> E + T | T\n");
    printf("  T -> T * F | F\n");
    printf("  F -> ( E ) | id\n");
    printf("----------------------------------------------------------------------\n");
    printf("MATHEMATICAL RULES FOR TRAILING(A):\n");
    printf("  1. If A -> alpha a or A -> alpha a B (B in NT), then a in TRAILING(A).\n");
    printf("  2. If A -> alpha B (B in NT), then TRAILING(B) is in TRAILING(A).\n");
    printf("----------------------------------------------------------------------\n");
    printf("STEP-BY-STEP DERIVATION:\n");
    printf("  1. For non-terminal F:\n");
    printf("     - Production F -> ( E ) : trailing terminal is ')' ==> ')' in TRAILING(F)\n");
    printf("     - Production F -> id    : trailing terminal is 'id' ==> 'id' in TRAILING(F)\n");
    printf("     TRAILING(F) = { ), id }\n\n");
    printf("  2. For non-terminal T:\n");
    printf("     - Production T -> T * F : '*' precedes trailing NT F ==> '*' in TRAILING(T)\n");
    printf("     - Production T -> F     : inherits all of TRAILING(F)\n");
    printf("     TRAILING(T) = { *, ), id }\n\n");
    printf("  3. For non-terminal E:\n");
    printf("     - Production E -> E + T : '+' precedes trailing NT T ==> '+' in TRAILING(E)\n");
    printf("     - Production E -> T     : inherits all of TRAILING(T)\n");
    printf("     TRAILING(E) = { +, *, ), id }\n");
    printf("----------------------------------------------------------------------\n");
    printf("COMPUTED TRAILING SETS:\n");
    printf("  TRAILING(E) = { +, *, ), id }\n");
    printf("  TRAILING(T) = { *, ), id }\n");
    printf("  TRAILING(F) = { ), id }\n");
    printf("======================================================================\n");
    return 0;
}
