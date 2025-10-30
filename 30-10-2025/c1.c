#include <stdio.h>

int main() {
    FILE *fp;
    int count = 0;

    fp = fopen("count.txt", "r");
    if (fp != NULL) {
        fscanf(fp, "%d", &count);
        fclose(fp);
    }

    count++;

    fp = fopen("count.txt", "w");
    fprintf(fp, "%d", count);
    fclose(fp);

    printf("This is execution number = %d\n", count);
    return 0;
}
