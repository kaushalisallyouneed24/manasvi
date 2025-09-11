#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the values in array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int max = a[0], min = a[0]; 

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }

    printf("Max element%d\n", max);
    printf("Min element%d\n", min);

    return 0;
}

