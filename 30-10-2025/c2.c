#include <stdio.h>

int main() {
    FILE *source, *target;
    char ch;
    char src[100], dest[100];

    printf("Enter source file name: ");
    scanf("%s", src);

    printf("Enter destination file name: ");
    scanf("%s", dest);

    source = fopen(src, "r");
    if (source == NULL) {
        printf("Cannot open source file.\n");
        return 0;
    }

    target = fopen(dest, "w");
    if (target == NULL) {
        printf("Cannot open destination file.\n");
        fclose(source);
        return 0;
    }

    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);

    printf("File copied successfully.\n");

    fclose(source);
    fclose(target);
    return 0;
}
