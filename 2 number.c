#include <stdio.h>
int main()
{
    int a = 81;
    int b = 82;
    printf("evaluate the number");
    if(a>b)
    {
        if(a%2==0)
        {
            printf("number is even and greater than b%d",a);
        }
        a=a-b;
    }
        else
        {
            printf("not");
        }
    if(b>a)
    {
        if(b%2==0)    
        {
            printf("number is even and greater than a%d",b);
        }
        b=b-a;
    }
    else
    {
        printf("not");
    }
 printf("Final values a = %d, b = %d\n", a, b);
    return 0;
}
