#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    int ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    ch = fgetc(fp);
    if (ch == EOF)
        printf("The file is empty.\n");
    else
        printf("The file contains some text.\n");

    fclose(fp);
    return 0;
}
