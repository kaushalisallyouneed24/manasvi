#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    char ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("\nFile contents:\n\n");
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    fclose(fp);
    return 0;
}
