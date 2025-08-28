#include <stdio.h>
int main()
{
int i;int s=0; int cnt=0;
for(i=10;i<=70;i++)
{
    if(i%2==1)
    { 
        cnt=cnt+1;
        if(cnt<=12)
        {
            s=s+i;
        }
    
    }
    
}
printf("sum of first 12 odd number is %d",s);


    return 0;
}
