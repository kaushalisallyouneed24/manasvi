#include <stdio.h>
int main() 
{
    int n; int i;
    printf("enter the number");
    scanf("%d",& n);
    int A[n];
    printf("enter the size of array");
    for(i=0;i<n-1;i++)
    {
        scanf("%d ",& A[i]);
    }
    printf("displaying array in reverse: ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ", A[i]);
    }
    return 0;
}
