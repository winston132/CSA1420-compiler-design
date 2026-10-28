#include <stdio.h>
#include <string.h>

typedef struct {
    char op[4];
    char arg1[16];
    char arg2[16];
    char res[16];
} Quadruple;

Quadruple quads[32];
int quad_count = 0;
int temp_idx = 1;

void generate_3ac_simple(const char *target, const char *arg1, char op1, const char *arg2, char op2, const char *arg3) {
    char t1[16], t2[16];
    sprintf(t1, "t%d", temp_idx++);
    sprintf(t2, "t%d", temp_idx++);

    printf("Input Statement: %s = %s %c %s %c %s\n\n", target, arg1, op1, arg2, op2, arg3);
    printf("Generated Three Address Code Statements:\n");

    // Higher precedence check
    if (op2 == '*' || op2 == '/') {
        printf("  %s = %s %c %s\n", t1, arg2, op2, arg3);
        printf("  %s = %s %c %s\n", t2, arg1, op1, t1);
        printf("  %s = %s\n", target, t2);

        sprintf(quads[quad_count++].op, "%c", op2);
        strcpy(quads[quad_count-1].arg1, arg2);
        strcpy(quads[quad_count-1].arg2, arg3);
        strcpy(quads[quad_count-1].res, t1);

        sprintf(quads[quad_count++].op, "%c", op1);
        strcpy(quads[quad_count-1].arg1, arg1);
        strcpy(quads[quad_count-1].arg2, t1);
        strcpy(quads[quad_count-1].res, t2);

        strcpy(quads[quad_count++].op, "=");
        strcpy(quads[quad_count-1].arg1, t2);
        strcpy(quads[quad_count-1].arg2, "-");
        strcpy(quads[quad_count-1].res, target);
    } else {
        printf("  %s = %s %c %s\n", t1, arg1, op1, arg2);
        printf("  %s = %s %c %s\n", t2, t1, op2, arg3);
        printf("  %s = %s\n", target, t2);

        sprintf(quads[quad_count++].op, "%c", op1);
        strcpy(quads[quad_count-1].arg1, arg1);
        strcpy(quads[quad_count-1].arg2, arg2);
        strcpy(quads[quad_count-1].res, t1);

        sprintf(quads[quad_count++].op, "%c", op2);
        strcpy(quads[quad_count-1].arg1, t1);
        strcpy(quads[quad_count-1].arg2, arg3);
        strcpy(quads[quad_count-1].res, t2);

        strcpy(quads[quad_count++].op, "=");
        strcpy(quads[quad_count-1].arg1, t2);
        strcpy(quads[quad_count-1].arg2, "-");
        strcpy(quads[quad_count-1].res, target);
    }
}

int main() {
    printf("======================================================================\n");
    printf("     C PROGRAM: THREE ADDRESS CODE (3AC) & QUADRUPLE GENERATOR        \n");
    printf("======================================================================\n\n");

    generate_3ac_simple("a", "b", '+', "c", '*', "d");

    printf("\n----------------------------------------------------------------------\n");
    printf("QUADRUPLE REPRESENTATION TABLE:\n");
    printf("----------------------------------------------------------------------\n");
    printf("%-8s %-10s %-12s %-12s %-10s\n", "Index", "Operator", "Argument 1", "Argument 2", "Result");
    printf("----------------------------------------------------------------------\n");
    for (int i = 0; i < quad_count; i++) {
        printf("(%-6d) %-10s %-12s %-12s %-10s\n", i, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].res);
    }
    printf("======================================================================\n");
    return 0;
}
