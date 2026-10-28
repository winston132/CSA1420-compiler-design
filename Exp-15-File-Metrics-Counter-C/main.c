#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "sample_text.txt";
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("======================================================================\n");
    printf("   LEXICAL ANALYZER IN C: COUNT CHARACTERS, WORDS, AND LINES          \n");
    printf("======================================================================\n");
    printf("Target File: %s\n\n", filename);

    int ch;
    int chars = 0, words = 0, lines = 0;
    int in_word = 0;
    int last_char = 0;

    while ((ch = fgetc(fp)) != EOF) {
        chars++;
        if (ch == '\n') lines++;

        if (isspace(ch)) {
            in_word = 0;
        } else {
            if (!in_word) {
                words++;
                in_word = 1;
            }
        }
        last_char = ch;
    }
    fclose(fp);

    if (chars > 0 && last_char != '\n') lines++;

    printf("%-30s : %d\n", "Total Characters (Bytes)", chars);
    printf("%-30s : %d\n", "Total Words Counted", words);
    printf("%-30s : %d\n", "Total Lines Counted", lines);
    printf("======================================================================\n");
    return 0;
}
