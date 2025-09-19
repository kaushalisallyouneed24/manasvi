#include <stdio.h>

int main() {
    int r, c, i, j;

    // Ask user for size
    printf("Enter number of rows: ");
    scanf("%d", &r);
    printf("Enter number of columns: ");
    scanf("%d", &c);

    int a[r][c], t[c][r];  // original and transpose

    // Input array
    printf("Enter elements of the array:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    // Print original array
    printf("\nOriginal array:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Find transpose
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            t[j][i] = a[i][j];
        }
    }

    // Print transpose
    printf("\nTranspose of array:\n");
    for(i=0; i<c; i++){
        for(j=0; j<r; j++){
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
