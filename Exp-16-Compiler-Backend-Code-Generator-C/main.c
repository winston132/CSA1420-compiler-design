#include <stdio.h>
#include <string.h>

typedef struct {
    char res[16];
    char arg1[16];
    char op;
    char arg2[16];
} TAC;

int main() {
    printf("======================================================================\n");
    printf("          COMPILER BACK-END: TARGET CODE GENERATOR (8086)             \n");
    printf("======================================================================\n\n");

    TAC code[] = {
        {"t1", "a", '+', "b"},
        {"t2", "c", '-', "d"},
        {"t3", "t1", '*', "t2"},
        {"z", "t3", '=', ""}
    };
    int n = sizeof(code) / sizeof(code[0]);

    printf("INTERMEDIATE CODE (THREE ADDRESS STATEMENTS):\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (code[i].op == '=') {
            printf("  %s = %s\n", code[i].res, code[i].arg1);
        } else {
            printf("  %s = %s %c %s\n", code[i].res, code[i].arg1, code[i].op, code[i].arg2);
        }
    }

    printf("\n----------------------------------------------------------------------\n");
    printf("GENERATED TARGET MACHINE CODE (8086 ASSEMBLY):\n");
    printf("----------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("; Target code for statement: ");
        if (code[i].op == '=') {
            printf("%s = %s\n", code[i].res, code[i].arg1);
            printf("  MOV R0, %s\n", code[i].arg1);
            printf("  MOV %s, R0\n\n", code[i].res);
        } else {
            printf("%s = %s %c %s\n", code[i].res, code[i].arg1, code[i].op, code[i].arg2);
            printf("  MOV R0, %s\n", code[i].arg1);
            switch (code[i].op) {
                case '+':
                    printf("  ADD R0, %s\n", code[i].arg2);
                    break;
                case '-':
                    printf("  SUB R0, %s\n", code[i].arg2);
                    break;
                case '*':
                    printf("  MUL R0, %s\n", code[i].arg2);
                    break;
                case '/':
                    printf("  DIV R0, %s\n", code[i].arg2);
                    break;
            }
            printf("  MOV %s, R0\n\n", code[i].res);
        }
    }
    printf("======================================================================\n");
    return 0;
}
