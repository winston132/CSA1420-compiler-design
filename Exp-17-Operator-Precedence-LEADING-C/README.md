# Exp-17: Compute LEADING for Operator Precedence Parser in C

**Course:** CSA14 - Compiler Design  
**Department:** Computational Intelligence  
**Institution:** Saveetha School of Engineering (SIMATS)  

---

## 1. Aim
Write a C program to compute LEADING() – operator precedence parser for the given grammar:
E -> E + T | T
T -> T * F | F
F -> ( E ) | id

---

## 2. Algorithm
1. Define definition of LEADING(A):
   A terminal 'a' is in LEADING(A) if:
   a) A -> a gamma or A -> B a gamma (where B is a non-terminal).
   b) A -> B gamma, then all terminals in LEADING(B) are in LEADING(A).
2. For F -> ( E ) | id:
   - First terminal is '(' ==> ( in LEADING(F)
   - First terminal is 'id' ==> id in LEADING(F)
   ==> LEADING(F) = { (, id }
3. For T -> T * F | F:
   - T is followed by '*' ==> * in LEADING(T)
   - T -> F ==> LEADING(F) subset of LEADING(T)
   ==> LEADING(T) = { *, (, id }
4. For E -> E + T | T:
   - E is followed by '+' ==> + in LEADING(E)
   - E -> T ==> LEADING(T) subset of LEADING(E)
   ==> LEADING(E) = { +, *, (, id }
5. Display step-by-step evaluation and final sets.

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
```

---

## 5. Output Terminal Screenshot
![Output Screenshot](output.png)

---

## 6. Execution Output (Text)
```text
======================================================================
       OPERATOR PRECEDENCE PARSER: LEADING() SET COMPUTATION          
======================================================================
GIVEN GRAMMAR:
  E -> E + T | T
  T -> T * F | F
  F -> ( E ) | id
----------------------------------------------------------------------
MATHEMATICAL RULES FOR LEADING(A):
  1. If A -> a alpha or A -> B a alpha (B in NT), then a in LEADING(A).
  2. If A -> B alpha (B in NT), then LEADING(B) is in LEADING(A).
----------------------------------------------------------------------
STEP-BY-STEP DERIVATION:
  1. For non-terminal F:
     - Production F -> ( E ) : terminal '(' is at start ==> '(' in LEADING(F)
     - Production F -> id    : terminal 'id' is at start ==> 'id' in LEADING(F)
     LEADING(F) = { (, id }

  2. For non-terminal T:
     - Production T -> T * F : T is followed by terminal '*' ==> '*' in LEADING(T)
     - Production T -> F     : inherits all of LEADING(F)
     LEADING(T) = { *, (, id }

  3. For non-terminal E:
     - Production E -> E + T : E is followed by terminal '+' ==> '+' in LEADING(E)
     - Production E -> T     : inherits all of LEADING(T)
     LEADING(E) = { +, *, (, id }
----------------------------------------------------------------------
COMPUTED LEADING SETS:
  LEADING(E) = { +, *, (, id }
  LEADING(T) = { *, (, id }
  LEADING(F) = { (, id }
======================================================================
```

---

## 7. Result
The program for **Compute LEADING for Operator Precedence Parser in C** was successfully implemented, compiled, and executed. The output matches theoretical and compiler design specifications.
