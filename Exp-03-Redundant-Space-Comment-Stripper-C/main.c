#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "dirty_input.c";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Cannot open %s\n", filename);
        return 1;
    }

    printf("======================================================================\n");
    printf("   LEXICAL ANALYZER: STRIP REDUNDANT SPACES, TABS, NEWLINES, COMMENTS \n");
    printf("======================================================================\n");
    printf("Source File: %s\n\n", filename);
    printf("CLEANED SOURCE CODE OUTPUT:\n");
    printf("----------------------------------------------------------------------\n");

    int ch;
    int prev_space = 0;
    int spaces_removed = 0, comments_removed = 0;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '/') {
            int next = fgetc(fp);
            if (next == '/') {
                comments_removed++;
                while ((ch = fgetc(fp)) != EOF && ch != '\n');
                continue;
            } else if (next == '*') {
                comments_removed++;
                int prev = 0;
                while ((ch = fgetc(fp)) != EOF) {
                    if (prev == '*' && ch == '/') break;
                    prev = ch;
                }
                continue;
            } else {
                ungetc(next, fp);
            }
        }

        if (ch == ' ' || ch == '\t') {
            if (!prev_space) {
                putchar(' ');
                prev_space = 1;
            } else {
                spaces_removed++;
            }
            continue;
        }

        if (ch == '\n') {
            if (!prev_space) {
                putchar('\n');
                prev_space = 1;
            } else {
                spaces_removed++;
            }
            continue;
        }

        prev_space = 0;
        putchar(ch);
    }
    fclose(fp);

    printf("\n----------------------------------------------------------------------\n");
    printf("CLEANUP STATISTICS:\n");
    printf("  Redundant whitespace characters eliminated : %d\n", spaces_removed);
    printf("  Comment blocks eliminated                  : %d\n", comments_removed);
    printf("======================================================================\n");
    return 0;
}
