#include <stdio.h>
#include <string.h>

int main() {
    printf("======================================================================\n");
    printf("          PREDICTIVE PARSER: FIRST() SET COMPUTATION                  \n");
    printf("======================================================================\n");
    printf("GIVEN GRAMMAR:\n");
    printf("  S -> AaAb | BbBa\n");
    printf("  A -> e\n");
    printf("  B -> e\n");
    printf("  (Note: 'e' represents epsilon / empty transition)\n");
    printf("----------------------------------------------------------------------\n");
    printf("FIRST() COMPUTATION STEPS:\n");
    printf("  1. Production A -> e  ==> FIRST(A) = { e }\n");
    printf("  2. Production B -> e  ==> FIRST(B) = { e }\n");
    printf("  3. For S -> AaAb:\n");
    printf("     - First symbol is A. Since A derives e, we check next symbol 'a'.\n");
    printf("     - 'a' is a terminal ==> add 'a' to FIRST(S).\n");
    printf("  4. For S -> BbBa:\n");
    printf("     - First symbol is B. Since B derives e, we check next symbol 'b'.\n");
    printf("     - 'b' is a terminal ==> add 'b' to FIRST(S).\n");
    printf("----------------------------------------------------------------------\n");
    printf("RESULTANT FIRST SETS:\n");
    printf("  FIRST(S) = { a, b }\n");
    printf("  FIRST(A) = { e }\n");
    printf("  FIRST(B) = { e }\n");
    printf("======================================================================\n");
    return 0;
}
