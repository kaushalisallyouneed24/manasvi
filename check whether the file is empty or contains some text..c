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

    ch = fgetc(fp);

    if (ch == EOF)
    {
        printf("The file is empty.\n");
    }
    else
    {
        printf("The file contains some text.\n");
    }

    fclose(fp);
    return 0;
}
