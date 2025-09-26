#include <stdio.h>
#define max 5
int top = -1;
int st[max];
void push(int n)
{
    if (top==max-1)
    printf("overflow");
    else
    {
        top++;
        st[top]=n;
    }
}
void pop()
{
    if(top==-1)
    printf("underflow");
    else
    {
        int p =st[top];
        top--;
        printf("deleted is=%d",p);
    }
}
void display()
{
    if(top==-1)
    printf("underflow");
    else
    {
        for(int i=top;i>=0;i--)
        printf("%d",st[i]);
    }
}
int main()
{
    int x,ch;
    do
    {
        printf("1-push\n2-pop\n3-display\n4-exit\n");
        printf("enter choice");
        scanf("%d",& ch);
        switch(ch)
        {
            case 1: printf("enter");
            scanf("%d", &x);
            push(x);
            break;
            case 2: pop();
            break;
            case 3: display();
            break;
            default: printf("invalid");
        }
    } while((ch>=1)&&(ch<=3));
    
    return 0;
}
        
