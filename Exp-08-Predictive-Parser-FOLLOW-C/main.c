#include <stdio.h>

int main() {
    printf("======================================================================\n");
    printf("          PREDICTIVE PARSER: FOLLOW() SET COMPUTATION                 \n");
    printf("======================================================================\n");
    printf("GIVEN GRAMMAR:\n");
    printf("  S -> AaAb | BbBa\n");
    printf("  A -> e\n");
    printf("  B -> e\n");
    printf("----------------------------------------------------------------------\n");
    printf("FOLLOW() COMPUTATION STEPS:\n");
    printf("  1. S is Start Symbol ==> add '$' to FOLLOW(S).\n");
    printf("     FOLLOW(S) = { $ }\n\n");
    printf("  2. In production S -> AaAb:\n");
    printf("     - First 'A' is followed by terminal 'a' ==> add 'a' to FOLLOW(A).\n");
    printf("     - Second 'A' is followed by terminal 'b' ==> add 'b' to FOLLOW(A).\n");
    printf("     FOLLOW(A) = { a, b }\n\n");
    printf("  3. In production S -> BbBa:\n");
    printf("     - First 'B' is followed by terminal 'b' ==> add 'b' to FOLLOW(B).\n");
    printf("     - Second 'B' is followed by terminal 'a' ==> add 'a' to FOLLOW(B).\n");
    printf("     FOLLOW(B) = { a, b }\n");
    printf("----------------------------------------------------------------------\n");
    printf("RESULTANT FOLLOW SETS:\n");
    printf("  FOLLOW(S) = { $ }\n");
    printf("  FOLLOW(A) = { a, b }\n");
    printf("  FOLLOW(B) = { a, b }\n");
    printf("======================================================================\n");
    return 0;
}
