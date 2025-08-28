#include <stdio.h>
int main()
{
    int gross,loan,ICD,basic;
    printf("compute the total gross");
    scanf("%d",&gross);
    scanf("%d",&loan);
    scanf("%d",&ICD);
    scanf("%d",&basic);
    int HRA= (30*basic)/100;
    int DA= (20*basic)/100;
    int ISE=7000;
    gross= HRA+DA+ISE;
    loan=14000;
    int LR=gross-loan;
    ICD=(10*basic)/100;
    ICD=gross-ICD;
    printf("actual salary of user is %d\n",gross);
    return 0;
} \\actual salary of customer
