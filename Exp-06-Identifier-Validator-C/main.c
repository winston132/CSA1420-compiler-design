#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const char *KEYWORDS[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
static const int NUM_KEYWORDS = 32;

int is_keyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, KEYWORDS[i]) == 0) return 1;
    }
    return 0;
}

void validate_identifier(const char *id) {
    printf("Identifier: %-18s -> ", id);

    int len = strlen(id);
    if (len == 0) {
        printf("[INVALID] Identifier cannot be empty\n");
        return;
    }
    if (len > 31) {
        printf("[INVALID] Exceeds maximum length of 31 characters\n");
        return;
    }
    if (is_keyword(id)) {
        printf("[INVALID] Cannot be a reserved keyword\n");
        return;
    }
    if (!isalpha(id[0]) && id[0] != '_') {
        printf("[INVALID] First character must be a letter or underscore\n");
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!isalnum(id[i]) && id[i] != '_') {
            printf("[INVALID] Contains illegal character '%c'\n", id[i]);
            return;
        }
    }
    printf("[VALID] Conforms to standard identifier rules\n");
}

int main() {
    printf("======================================================================\n");
    printf("            LEXICAL ANALYZER: IDENTIFIER VALIDATOR IN C               \n");
    printf("======================================================================\n\n");

    const char *test_ids[] = {
        "count",
        "_tempValue",
        "num1",
        "2ndNumber",
        "sum_of_digits",
        "float",
        "my-var",
        "valid_identifier_for_c_program",
        "this_is_an_extremely_long_identifier_exceeding_thirty_one_characters"
    };

    int n = sizeof(test_ids) / sizeof(test_ids[0]);
    for (int i = 0; i < n; i++) {
        validate_identifier(test_ids[i]);
    }

    printf("\n======================================================================\n");
    return 0;
}
