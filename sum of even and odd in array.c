#include <stdio.h>

int main() {
    int n, i;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int evenSum = 0, oddSum = 0;
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            evenSum += a[i];
        else
            oddSum += a[i];
    }

    printf("Sum of even numbers = %d\n", evenSum);
    printf("Sum of odd numbers = %d\n", oddSum);

    return 0;
}
