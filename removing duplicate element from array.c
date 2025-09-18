// Online C compiler to run C program online
#include <stdio.h>

int main(){
    int a[10],i,j;
    printf("enter the array values\n");
    for(i=0;i<10;i++)
    {
        scanf("%d",& a[i]);
    }
    printf("non duplicate elements\n");
    for(i=0;i<10;i++)
    { int duplicate=0;
        for(j=i+1;j<10;j++)
        {
            if(a[i]==a[j])
            {
                duplicate=1;
                break;
            }
        }
    if(!duplicate)
    {
        printf(" %d",a[i]);
    }
}
 return 0;
}
 
