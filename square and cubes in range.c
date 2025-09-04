#include <stdio.h>

int main()
{ 
   int x,y; int cb;
   printf("enter the number");
   scanf("%d",& x);
   scanf("%d",& y);
   printf("display the squares and cubes in that range \n  ");
   for(int i=x;i<=y;i++)
   {
       if(i%2==0)
       {
           int sq = i*i;
           printf("square is: %d\n", sq);
       }
       
       else if (i%2==1)
       {
           cb= i*i*i;
           printf("cube is: %d\n",cb);
       }
       
   }
    return 0;
}
