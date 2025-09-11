#include <stdio.h>
int main()
{
    int n;int i; int j;
    printf("enter the nth size of array");
    scanf("%d",& n);
    int a[n]; 
    printf("enter the value in array");
    for(i=0;i<n;i++)
    {
        scanf("%d",& a[i]);
    }
    printf("finding duplicate in array");
    int c=0;
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
        {
         if(a[i]==a[j])
        {
        printf("duplicate found%d",a[i]);
        c++;
        break;
        }
    }
    if(c==0)
    {
    printf("no duplicate element");
    }
    else
    {
        printf("total no of duplicate%d",c);
    }
  
return 0;
}
}
