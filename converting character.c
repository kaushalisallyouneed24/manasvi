#include <stdio.h>
int main()
{ char ch;
printf("converting the character");
scanf("%c",& ch);
if ((ch>='A')&&(ch<='Z'))
{
    ch=ch+32;
    printf("character is %c\n", ch);
}
else if((ch>='a')&&(ch<='z'))
{
    ch=ch-32;
    printf("character is %c\n", ch);
}
return 0;
}
