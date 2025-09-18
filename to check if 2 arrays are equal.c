#include <stdio.h>

int main() {
    int n, i, same = 1;

    printf("Enter size of arrays: ");
    scanf("%d", &n);

    int a[n], b[n];

    printf("Enter elements of first array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter elements of second array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            same = 0;
            break;
        }
    }

    if(same == 1)
        printf("Arrays are equal\n");
    else
        printf("Arrays are not equal\n");

    return 0;
}
