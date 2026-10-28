#include <stdio.h>
#include <string.h>
#include <ctype.h>

void check_comment(const char *input) {
    char line[256];
    while (*input && isspace((unsigned char)*input)) input++;
    strncpy(line, input, sizeof(line) - 1);
    line[sizeof(line) - 1] = '\0';

    int len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[--len] = '\0';
    }

    printf("Input Line : \"%s\"\n", line);

    if (len >= 2 && line[0] == '/' && line[1] == '/') {
        printf("Analysis   : [VALID] Single-line comment (begins with //)\n\n");
    } else if (len >= 4 && line[0] == '/' && line[1] == '*') {
        if (strstr(line + 2, "*/") != NULL) {
            printf("Analysis   : [VALID] Multi-line comment (enclosed in /* ... */)\n\n");
        } else {
            printf("Analysis   : [INVALID] Unterminated multi-line comment (missing */)\n\n");
        }
    } else {
        printf("Analysis   : [NOT A COMMENT] Regular C code statement\n\n");
    }
}

int main() {
    printf("======================================================================\n");
    printf("                 C PROGRAM: COMMENT IDENTIFIER                        \n");
    printf("======================================================================\n\n");

    const char *test_cases[] = {
        "// This is a valid single-line comment",
        "/* This is a single-line block comment */",
        "/* Multi-line comment without closing tag",
        "int sum = a + b; // inline comment",
        "float pi = 3.14159;",
        "// Another single-line comment with special symbols: !@#$%^&*()",
        "/* Fully closed comment with code inside: int x = 10; */"
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    for (int i = 0; i < num_tests; i++) {
        printf("Test Case #%d:\n", i + 1);
        check_comment(test_cases[i]);
    }

    printf("======================================================================\n");
    return 0;
}
