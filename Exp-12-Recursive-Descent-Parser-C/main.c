#include <stdio.h>
#include <string.h>

const char *cursor;
int error_flag = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

void match(char expected) {
    if (*cursor == expected) {
        cursor++;
    } else {
        error_flag = 1;
    }
}

void E() {
    if (error_flag) return;
    T();
    Eprime();
}

void Eprime() {
    if (error_flag) return;
    if (*cursor == '+') {
        match('+');
        T();
        Eprime();
    }
    // Epsilon transition -> return
}

void T() {
    if (error_flag) return;
    F();
    Tprime();
}

void Tprime() {
    if (error_flag) return;
    if (*cursor == '*') {
        match('*');
        F();
        Tprime();
    }
    // Epsilon transition -> return
}

void F() {
    if (error_flag) return;
    if (*cursor == '(') {
        match('(');
        E();
        match(')');
    } else if (*cursor == 'i') {
        // 'i' represents 'id'
        match('i');
    } else {
        error_flag = 1;
    }
}

void test_string(const char *str) {
    cursor = str;
    error_flag = 0;
    printf("Input Expression : %s\n", str);
    E();
    if (!error_flag && *cursor == '$') {
        printf("Parsing Result   : [SUCCESS] String is ACCEPTED by Grammar\n\n");
    } else {
        printf("Parsing Result   : [ERROR] Syntax Error! String is REJECTED by Grammar\n\n");
    }
}

int main() {
    printf("======================================================================\n");
    printf("         C PROGRAM: RECURSIVE DESCENT PARSER                          \n");
    printf("======================================================================\n");
    printf("GRAMMAR SPECIFICATION:\n");
    printf("  E  -> T E'\n");
    printf("  E' -> + T E' | e\n");
    printf("  T  -> F T'\n");
    printf("  T' -> * F T' | e\n");
    printf("  F  -> ( E ) | id (represented by 'i')\n");
    printf("----------------------------------------------------------------------\n\n");

    const char *test_cases[] = {
        "i+i*i$",
        "(i+i)*i$",
        "i*i+i$",
        "i+*i$",
        "(i+i$",
        "i$"
    };

    int n = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < n; i++) {
        printf("Test Case #%d:\n", i + 1);
        test_string(test_cases[i]);
    }

    printf("======================================================================\n");
    return 0;
}
