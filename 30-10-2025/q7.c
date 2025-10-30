#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[100], word[100], longest[100] = "";
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("File not found");
        return 0;
    }
    while (fscanf(fp, "%s", word) != EOF) {
        if (strlen(word) > strlen(longest))
            strcpy(longest, word);
    }
    fclose(fp);
    printf("Longest word: %s", longest);
    return 0;
}
