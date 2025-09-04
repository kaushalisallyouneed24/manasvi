#include <stdio.h>

int main()
{ 
  int n ,m; int i;
  printf("enter the number");
  scanf("%d",& n);
  scanf("%d",&m);
  printf("prime number are");
  for( i= n;i<=m;i++)
  {
      if(i%2==1)
       printf("prime number are%d\n", i);
  
  }
    return 0;
}
