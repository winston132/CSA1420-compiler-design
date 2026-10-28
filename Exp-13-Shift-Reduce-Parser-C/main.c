#include <stdio.h>
#include <string.h>

char stack[64];
int top = -1;

void push(char c) {
    stack[++top] = c;
    stack[top + 1] = '\0';
}

void pop(int n) {
    top -= n;
    stack[top + 1] = '\0';
}

int check_reduce() {
    // E -> id (represented by 'i')
    if (top >= 0 && stack[top] == 'i') {
        pop(1);
        push('E');
        printf("%-20s %-20s %s\n", stack, "", "REDUCE: E -> id");
        return 1;
    }
    // E -> E + E
    if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '+' && stack[top] == 'E') {
        pop(3);
        push('E');
        printf("%-20s %-20s %s\n", stack, "", "REDUCE: E -> E + E");
        return 1;
    }
    // E -> E * E
    if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '*' && stack[top] == 'E') {
        pop(3);
        push('E');
        printf("%-20s %-20s %s\n", stack, "", "REDUCE: E -> E * E");
        return 1;
    }
    // E -> ( E )
    if (top >= 2 && stack[top - 2] == '(' && stack[top - 1] == 'E' && stack[top] == ')') {
        pop(3);
        push('E');
        printf("%-20s %-20s %s\n", stack, "", "REDUCE: E -> ( E )");
        return 1;
    }
    return 0;
}

void parse(const char *input_str) {
    char input[64];
    strcpy(input, input_str);
    int in_idx = 0;
    top = -1;
    push('$');

    printf("Parsing Input: %s\n", input_str);
    printf("%-20s %-20s %s\n", "Stack", "Input Buffer", "Action");
    printf("----------------------------------------------------------------------\n");

    while (1) {
        // Repeated reductions if possible
        while (check_reduce());

        // Check acceptance
        if (top == 1 && stack[0] == '$' && stack[1] == 'E' && input[in_idx] == '$') {
            printf("%-20s %-20s %s\n", stack, &input[in_idx], "[ACCEPTED] String satisfies the Grammar!");
            break;
        }

        // Shift next character
        if (input[in_idx] != '$') {
            char next_sym = input[in_idx++];
            push(next_sym);
            char action_buf[32];
            sprintf(action_buf, "SHIFT: '%c'", next_sym);
            printf("%-20s %-20s %s\n", stack, &input[in_idx], action_buf);
        } else {
            // Cannot shift and cannot reduce
            printf("%-20s %-20s %s\n", stack, &input[in_idx], "[REJECTED] Syntax Error: String violates grammar!");
            break;
        }
    }
    printf("\n");
}

int main() {
    printf("======================================================================\n");
    printf("      C PROGRAM: BOTTOM-UP SHIFT-REDUCE PARSER / GRAMMAR CHECKER      \n");
    printf("======================================================================\n");
    printf("GRAMMAR RULES:\n");
    printf("  E -> E + E\n");
    printf("  E -> E * E\n");
    printf("  E -> ( E )\n");
    printf("  E -> id (represented by 'i')\n");
    printf("----------------------------------------------------------------------\n\n");

    parse("i+i*i$");
    parse("i*i$");

    printf("======================================================================\n");
    return 0;
}
