#include <stdio.h>
int main()
{
    int a[8],i;
    printf("enter the value of array");
    for(i=0;i<8;i++)
    {
        scanf("%d",& a[i]);
    }
    printf("sum of array is :");
    int s=0;
    for(i=0;i<8;i++)
    {
        s=s+a[i];
        
    }
    printf("%d",s);
    
    return 0;
    
    
}
