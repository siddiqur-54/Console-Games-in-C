#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void name();
void calculate();
void again();

char p1[20],p2[20];
int op,love; op=1;

int main()
{
    while(op==1)
    {
        printf("\tLove Calculator\n");
        name();
        calculate();
        again();
    }
}

void name()
{
    printf("\nEnter Your Name: ");
    scanf("%s",p1);
    printf("Enter Your Crush Name: ");
    scanf("%s",p2);
}

void calculate()
{
    srand(time(NULL));
    love=rand()%100+0;
    printf("\n%s Loves %s Almost = %d Percent",p2,p1,love);
}

void again()
{
    while(op!=0)
    {
        printf("\n\n1.Play Again");
        printf("\n0.Exit Game");
        printf("\nChoose your option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:system("cls"); return; break;
            case 0:printf("\nThank You....");break;
            default:printf("Invalid option.Try again....");break;
        }
    }
}
