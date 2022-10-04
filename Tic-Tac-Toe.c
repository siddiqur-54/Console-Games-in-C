#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void player();
void computer();
void board();
int check();
void submit();

int i,j,op,a,n,k,l,m,arr[9],flag;
char b[10]={'0','1','2','3','4','5','6','7','8','9'};
char mark,p1[20],p2[20];


int main()
{
    printf("\tTic Tac Toe");
    op=1;
    while(op!=0)
    {
        printf("\n\n1.VS Player");
        printf("\n2.VS Computer");
        printf("\n0.Exit Game");
        printf("\nChoose your option:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:player();break;
            case 2:computer();break;
            case 0:printf("\nThank You....");break;
            default:printf("Invalid option.Try again....");break;
        }
    }
}

void player()
{
    i=1;
    submit();
    do
    {
        while(1)
        {
            board();
            printf("\n\n\t%s(X)------------------%s(O)",p1,p2);
            if(i%2!=0)
            {
                printf("\n%s's turn:",p1);
                mark='X';
            }
            else if(i%2==0)
            {
                printf("\n%s's turn:",p2);
                mark='O';
            }
            scanf("%d",&n);
            if((n>=0)&&(n<=9)&&(b[n]!='O')&&(b[n]!='X'))
            {
                break;
            }
        }
        for(j=1;j<10;j++)
        {
            if(n==j)
            {
                b[j]=mark;
                break;
            }
        }
        a=check();
        i++;
    }while(a==0);
    board();
    i--;
    if((a==1)&&(i%2!=0))
        printf("\n%s Win........",p1);
    else if((a==1)&&(i%2==0))
        printf("\n%s Win........",p2);
    else
        printf("\nGame Draw......");
    b[1]='1';b[2]='2';b[3]='3';b[4]='4';b[5]='5';
    b[6]='6';b[7]='7';b[8]='8';b[9]='9';
}

void computer()
{
    i=1; k=0;
    do
    {
        if(i%2!=0)
        {
            while(1)
            {
                board();
                printf("\n\n\tYou(X)-----------------Computer(O)");
                printf("\nYour turn:");
                mark='X';
                scanf("%d",&n);
                if((n>=0)&&(n<=9)&&(b[n]!='O')&&(b[n]!='X'))
                {
                    break;
                }
            }
            arr[k]=n;
        }
        else if(i%2==0)
        {
            l=0;
            board();
            printf("\n\n\tYou(X)-----------------Computer(O)");
            printf("\nComputer's turn:");
            mark='O';
            while(l==0)
            {
                flag=0;
                srand(time(NULL));
                n = rand()%9+0;
                for(m=0;m<9;m++)
                {
                    if(n==arr[m])
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    l=0;
                else
                {
                    l=1;
                    arr[k]=n;
                }
            }
        }
        for(j=1;j<10;j++)
        {
            if(n==j)
            {
                b[j]=mark;
                break;
            }
        }
        a=check();
        i++; k++;
    }while(a==0);
    i--;
    board();
    if((a==1)&&(i%2!=0))
            printf("\nYou Win........");
    else if((a==1)&&(i%2==0))
            printf("\nComputer Win........");
    else
            printf("\nGame Draw......");
    b[1]='1';b[2]='2';b[3]='3';b[4]='4';b[5]='5';
    b[6]='6';b[7]='7';b[8]='8';b[9]='9';
}

int check()
{
    if((b[1]==b[2])&&(b[2]==b[3]))
        return 1;
    else if((b[4]==b[5])&&(b[5]==b[6]))
        return 1;
    else if((b[7]==b[8])&&(b[8]==b[9]))
        return 1;
    else if((b[1]==b[4])&&(b[4]==b[7]))
        return 1;
    else if((b[2]==b[5])&&(b[5]==b[8]))
        return 1;
    else if((b[3]==b[6])&&(b[6]==b[9]))
        return 1;
    else if((b[1]==b[5])&&(b[5]==b[9]))
        return 1;
    else if((b[3]==b[5])&&(b[5]==b[7]))
        return 1;
    else if((b[1]!='1')&&(b[2]!='2')&&(b[3]!='3')&&(b[4]!='4')
            &&(b[5]!='5')&&(b[6]!='6')&&(b[7]!='7')&&(b[8]!='8')&&(b[9]!='9'))
        return 2;
    else
        return 0;
}

void submit()
{
    printf("\nSubmit player 1 name:");
    scanf("%s",p1);
    printf("Submit player 2 name:");
    scanf("%s",p2);
}

void board()
{
    system("cls");
    printf("\t\t Tic Tac Toe");
    printf("\n\n\t\t  %c | %c | %c",b[1],b[2],b[3]);
    printf("\n\t\t- - - - - - -");
    printf("\n\t\t  %c | %c | %c",b[4],b[5],b[6]);
    printf("\n\t\t- - - - - - -");
    printf("\n\t\t  %c | %c | %c",b[7],b[8],b[9]);
}
