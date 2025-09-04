#include <stdio.h>

int main()
{ 
  char ch;
  printf("enter the character");
  scanf("%c", & ch);
  if(ch=='A'||ch=='a'||ch=='E'||ch=='e'||ch=='I'||ch=='i'||ch=='O'||ch=='o'||ch=='U'||ch=='u')
  {
      printf("given character is vowel");
      
  }
  else
  {
      printf("given character is consonant");
      
  }

    return 0;
}
