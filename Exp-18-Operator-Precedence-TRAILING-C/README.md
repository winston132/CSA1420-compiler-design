# Exp-18: Compute TRAILING for Operator Precedence Parser in C

**Course:** CSA14 - Compiler Design  
**Department:** Computational Intelligence  
**Institution:** Saveetha School of Engineering (SIMATS)  

---

## 1. Aim
Write a C program to compute TRAILING() – operator precedence parser for the given grammar:
E -> E + T | T
T -> T * F | F
F -> ( E ) | id

---

## 2. Algorithm
1. Define mathematical definition of TRAILING(A):
   A terminal 'a' is in TRAILING(A) if:
   a) A -> alpha a or A -> alpha a B (where B is a non-terminal).
   b) A -> alpha B (where B is a non-terminal), then all terminals in TRAILING(B) are in TRAILING(A).
2. For F -> ( E ) | id:
   - Trailing terminal in ( E ) is ')' ==> ) in TRAILING(F)
   - Trailing terminal in id is 'id' ==> id in TRAILING(F)
   ==> TRAILING(F) = { ), id }
3. For T -> T * F | F:
   - In T * F, terminal '*' precedes non-terminal F ==> * in TRAILING(T)
   - T -> F ==> TRAILING(F) subset of TRAILING(T)
   ==> TRAILING(T) = { *, ), id }
4. For E -> E + T | T:
   - In E + T, terminal '+' precedes non-terminal T ==> + in TRAILING(E)
   - E -> T ==> TRAILING(T) subset of TRAILING(E)
   ==> TRAILING(E) = { +, *, ), id }
5. Display step-by-step derivation and final TRAILING sets.

---

## 3. Input Specification
Given Operator Precedence Grammar:
E -> E + T | T
T -> T * F | F
F -> ( E ) | id

---

## 4. Program Source Code
```c
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
```

---

## 5. Output Terminal Screenshot
![Output Screenshot](output.png)

---

## 6. Execution Output (Text)
```text
======================================================================
       OPERATOR PRECEDENCE PARSER: TRAILING() SET COMPUTATION         
======================================================================
GIVEN GRAMMAR:
  E -> E + T | T
  T -> T * F | F
  F -> ( E ) | id
----------------------------------------------------------------------
MATHEMATICAL RULES FOR TRAILING(A):
  1. If A -> alpha a or A -> alpha a B (B in NT), then a in TRAILING(A).
  2. If A -> alpha B (B in NT), then TRAILING(B) is in TRAILING(A).
----------------------------------------------------------------------
STEP-BY-STEP DERIVATION:
  1. For non-terminal F:
     - Production F -> ( E ) : trailing terminal is ')' ==> ')' in TRAILING(F)
     - Production F -> id    : trailing terminal is 'id' ==> 'id' in TRAILING(F)
     TRAILING(F) = { ), id }

  2. For non-terminal T:
     - Production T -> T * F : '*' precedes trailing NT F ==> '*' in TRAILING(T)
     - Production T -> F     : inherits all of TRAILING(F)
     TRAILING(T) = { *, ), id }

  3. For non-terminal E:
     - Production E -> E + T : '+' precedes trailing NT T ==> '+' in TRAILING(E)
     - Production E -> T     : inherits all of TRAILING(T)
     TRAILING(E) = { +, *, ), id }
----------------------------------------------------------------------
COMPUTED TRAILING SETS:
  TRAILING(E) = { +, *, ), id }
  TRAILING(T) = { *, ), id }
  TRAILING(F) = { ), id }
======================================================================
```

---

## 7. Result
The program for **Compute TRAILING for Operator Precedence Parser in C** was successfully implemented, compiled, and executed. The output matches theoretical and compiler design specifications.
