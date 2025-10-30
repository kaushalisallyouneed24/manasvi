#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    int count = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ')
            count++;
    }

    printf("Number of spaces in the file: %d\n", count);

    fclose(fp);
    return 0;
}
