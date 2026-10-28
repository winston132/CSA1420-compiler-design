#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 256
#define MAX_ID_LEN 31

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

int is_operator_char(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
            c == '=' || c == '<' || c == '>' || c == '!' || c == '&' || c == '|');
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample.c";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("======================================================================\n");
    printf("     LEXICAL ANALYZER IN C (IDENTIFIERS, CONSTANTS, OPERATORS)        \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", filename);
    printf("%-10s %-22s %s\n", "Line No.", "Token Type", "Lexeme");
    printf("----------------------------------------------------------------------\n");

    int ch;
    int line = 1;
    int count_kw = 0, count_id = 0, count_const = 0, count_op = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            line++;
            continue;
        }
        if (isspace(ch)) continue;

        if (ch == '/') {
            int next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                if (ch == '\n') line++;
                continue;
            } else if (next == '*') {
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '\n') line++;
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else {
                ungetc(next, fp);
            }
        }

        if (ch == '#') {
            char buf[256];
            int idx = 0;
            buf[idx++] = ch;
            while ((ch = fgetc(fp)) != EOF && ch != '\n') {
                if (idx < 255) buf[idx++] = ch;
            }
            buf[idx] = '\0';
            printf("%-10d %-22s %s\n", line, "PREPROCESSOR", buf);
            if (ch == '\n') line++;
            continue;
        }

        if (ch == '"') {
            char buf[256];
            int idx = 0;
            buf[idx++] = ch;
            while ((ch = fgetc(fp)) != EOF && ch != '"' && ch != '\n') {
                if (idx < 254) buf[idx++] = ch;
            }
            if (ch == '"') buf[idx++] = ch;
            buf[idx] = '\0';
            printf("%-10d %-22s %s\n", line, "STRING LITERAL", buf);
            count_const++;
            continue;
        }

        if (isalpha(ch) || ch == '_') {
            char buf[MAX_TOKEN_LEN];
            int idx = 0;
            buf[idx++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_')) {
                if (idx < MAX_ID_LEN) buf[idx++] = ch;
            }
            buf[idx] = '\0';
            ungetc(ch, fp);

            if (is_keyword(buf)) {
                printf("%-10d %-22s %s\n", line, "KEYWORD", buf);
                count_kw++;
            } else {
                printf("%-10d %-22s %s\n", line, "IDENTIFIER", buf);
                count_id++;
            }
            continue;
        }

        if (isdigit(ch)) {
            char buf[64];
            int idx = 0;
            buf[idx++] = ch;
            while ((ch = fgetc(fp)) != EOF && (isdigit(ch) || ch == '.')) {
                if (idx < 63) buf[idx++] = ch;
            }
            buf[idx] = '\0';
            ungetc(ch, fp);
            printf("%-10d %-22s %s\n", line, "CONSTANT", buf);
            count_const++;
            continue;
        }

        if (is_operator_char(ch)) {
            char buf[4];
            int idx = 0;
            buf[idx++] = ch;
            int next = fgetc(fp);
            if ((ch == '+' && next == '+') || (ch == '-' && next == '-') ||
                (ch == '=' && next == '=') || (ch == '<' && next == '=') ||
                (ch == '>' && next == '=')) {
                buf[idx++] = next;
            } else {
                ungetc(next, fp);
            }
            buf[idx] = '\0';
            printf("%-10d %-22s %s\n", line, "OPERATOR", buf);
            count_op++;
            continue;
        }

        if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
            char buf[2] = {ch, '\0'};
            printf("%-10d %-22s %s\n", line, "DELIMITER", buf);
            continue;
        }
    }
    fclose(fp);

    printf("----------------------------------------------------------------------\n");
    printf("LEXICAL ANALYSIS SUMMARY:\n");
    printf("  Total Keywords    : %d\n", count_kw);
    printf("  Total Identifiers : %d\n", count_id);
    printf("  Total Constants   : %d\n", count_const);
    printf("  Total Operators   : %d\n", count_op);
    printf("======================================================================\n");
    return 0;
}
