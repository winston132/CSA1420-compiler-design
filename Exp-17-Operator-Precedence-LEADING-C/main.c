#include <stdio.h>

int main() {
    printf("======================================================================\n");
    printf("       OPERATOR PRECEDENCE PARSER: LEADING() SET COMPUTATION          \n");
    printf("======================================================================\n");
    printf("GIVEN GRAMMAR:\n");
    printf("  E -> E + T | T\n");
    printf("  T -> T * F | F\n");
    printf("  F -> ( E ) | id\n");
    printf("----------------------------------------------------------------------\n");
    printf("MATHEMATICAL RULES FOR LEADING(A):\n");
    printf("  1. If A -> a alpha or A -> B a alpha (B in NT), then a in LEADING(A).\n");
    printf("  2. If A -> B alpha (B in NT), then LEADING(B) is in LEADING(A).\n");
    printf("----------------------------------------------------------------------\n");
    printf("STEP-BY-STEP DERIVATION:\n");
    printf("  1. For non-terminal F:\n");
    printf("     - Production F -> ( E ) : terminal '(' is at start ==> '(' in LEADING(F)\n");
    printf("     - Production F -> id    : terminal 'id' is at start ==> 'id' in LEADING(F)\n");
    printf("     LEADING(F) = { (, id }\n\n");
    printf("  2. For non-terminal T:\n");
    printf("     - Production T -> T * F : T is followed by terminal '*' ==> '*' in LEADING(T)\n");
    printf("     - Production T -> F     : inherits all of LEADING(F)\n");
    printf("     LEADING(T) = { *, (, id }\n\n");
    printf("  3. For non-terminal E:\n");
    printf("     - Production E -> E + T : E is followed by terminal '+' ==> '+' in LEADING(E)\n");
    printf("     - Production E -> T     : inherits all of LEADING(T)\n");
    printf("     LEADING(E) = { +, *, (, id }\n");
    printf("----------------------------------------------------------------------\n");
    printf("COMPUTED LEADING SETS:\n");
    printf("  LEADING(E) = { +, *, (, id }\n");
    printf("  LEADING(T) = { *, (, id }\n");
    printf("  LEADING(F) = { (, id }\n");
    printf("======================================================================\n");
    return 0;
}
