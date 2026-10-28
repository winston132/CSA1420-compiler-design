#include <stdio.h>
#include <string.h>

void validate_operator(const char *op) {
    printf("Token: %-6s -> ", op);
    if (strlen(op) == 1) {
        switch (op[0]) {
            case '+':
                printf("[VALID] Addition Operator (+)\n");
                break;
            case '-':
                printf("[VALID] Subtraction Operator (-)\n");
                break;
            case '*':
                printf("[VALID] Multiplication Operator (*)\n");
                break;
            case '/':
                printf("[VALID] Division Operator (/)\n");
                break;
            default:
                printf("[INVALID] Not a standard basic arithmetic operator\n");
        }
    } else {
        printf("[INVALID] Operator token length > 1 (not a single basic arithmetic operator)\n");
    }
}

int main() {
    printf("======================================================================\n");
    printf("          LEXICAL ANALYZER: ARITHMETIC OPERATOR VALIDATOR             \n");
    printf("======================================================================\n\n");

    const char *test_tokens[] = {
        "+", "-", "*", "/", "%", "++", "+=", "&&", "=", "/", "^", "*"
    };

    int n = sizeof(test_tokens) / sizeof(test_tokens[0]);
    for (int i = 0; i < n; i++) {
        validate_operator(test_tokens[i]);
    }

    printf("\n======================================================================\n");
    return 0;
}
