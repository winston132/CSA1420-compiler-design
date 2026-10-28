#include <stdio.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "input.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("======================================================================\n");
    printf("     LEXICAL ANALYZER: COUNT WHITESPACES AND NEWLINE CHARACTERS       \n");
    printf("======================================================================\n");
    printf("File scanned: %s\n\n", filename);

    int ch;
    int spaces = 0, tabs = 0, newlines = 0, total_chars = 0;

    while ((ch = fgetc(fp)) != EOF) {
        total_chars++;
        if (ch == ' ') spaces++;
        else if (ch == '\t') tabs++;
        else if (ch == '\n') newlines++;
    }
    fclose(fp);

    int total_ws = spaces + tabs + newlines;

    printf("%-30s : %d\n", "Total Characters Scanned", total_chars);
    printf("%-30s : %d\n", "Space Characters (' ')", spaces);
    printf("%-30s : %d\n", "Horizontal Tabs ('\\t')", tabs);
    printf("%-30s : %d\n", "Newline Characters ('\\n')", newlines);
    printf("----------------------------------------------------------------------\n");
    printf("%-30s : %d\n", "TOTAL WHITESPACE CHARACTERS", total_ws);
    printf("======================================================================\n");
    return 0;
}
