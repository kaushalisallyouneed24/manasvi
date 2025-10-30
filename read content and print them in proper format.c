#include <stdio.h>

int main()
{
    FILE *fp;
    char fname[50];
    char ch;

    printf("Enter the file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("Error! File not found.\n");
        return 0;
    }

    printf("\n--- File Contents ---\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(fp);
    return 0;
}
