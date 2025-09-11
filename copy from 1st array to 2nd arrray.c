#include <stdio.h>
int main()
{
    int n;int i;
    printf("enter the nth size of array");
    scanf("%d",& n);
    int a[n]; int b[n];
    printf("enter the value in array");
    for(i=0;i<n;i++)
    {
        scanf("%d",& a[i]);
    }
    printf("copying the first array  elements to second array\n");
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    printf("copy elements in array b is:");
    for(i=0;i<n;i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
    
}
