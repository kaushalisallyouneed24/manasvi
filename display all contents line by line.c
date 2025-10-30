#include <stdio.h>

int main()
{
    FILE *fp;
    char fname[50];
    char line[200];

    printf("Enter the file name: ");
    scanf("%s", fname);

    fp = fopen(fname, "r");

    if (fp == NULL)
    {
        printf("Error! File not found.\n");
        return 0;
    }

    printf("\n--- File Contents (Line by Line) ---\n\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
