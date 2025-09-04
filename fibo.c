#include <stdio.h>

int main()
{ 
  int n,f=0,d=1; int s;
  printf("enter the number");
  scanf( "%d" ,& n);
  for(int i=2; i<n;i++)
  {
       s = f+d;
      printf( " %d" , s);
      f=d;
      d=s;
       if(n==s)
  {
      printf("number is present %d", n);
  }
  }
    return 0;
}
