#include <stdio.h>

int main()
{
    FILE *fp;
    char fname[50];
    char ch;
    int count = 0;

    printf("Enter the file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("Error! File not found.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == ' ')
            count++;
    }

    printf("Number of spaces in the file: %d\n", count);

    fclose(fp);
    return 0;
}
