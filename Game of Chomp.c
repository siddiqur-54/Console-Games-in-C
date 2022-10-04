#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void player();
void computer();
void board();
int check();
void submit();
void restore();
void makezero();

int r=10,c=10,a,op,i,j,k,l,t,x,y,n,v;
int arr[10][10];
char p1[20],p2[20];


int main()
{
    restore();
    printf("\tGame of Chomp");
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
            case 1:board();player();break;
            case 2:computer();break;
            case 0:printf("\nThank You....");break;
            default:printf("Invalid option.Try again....");break;
        }
    }
}

void player()
{
    t=1; l=r*c;
    submit();
    do
    {
        board();
        while(1)
        {
            board();
            if(t%2!=0)
            {
                printf("\n%s's turn:",p1);
            }
            else if(t%2==0)
            {
                printf("\n%s's turn:",p2);
            }
            scanf("%d",&n);
            x=(n-1)/r;
            y=(n-1)%c;
            if((n<=l)&&(arr[x][y]!=0))
            {
                break;
            }
        }
        makezero();
        a=check();
        t++;
    }while(a==0);
    board();
    t--;
    if((a==1)&&(t%2==0))
        printf("\n%s Win........",p1);
    else if((a==1)&&(t%2!=0))
        printf("\n%s Win........",p2);
    restore();
}

void computer()
{
    t=1; l=r*c;
    do
    {
        board();
        if(t%2!=0)
        {
            while(1)
            {
                board();
                printf("\nYour turn:");
                scanf("%d",&n);
                x=(n-1)/r;
                y=(n-1)%c;
                if((n<=l)&&(arr[x][y]!=0))
                {
                    break;
                }
            }
            makezero();
        }
        else if(i%2==0)
        {
            printf("\nComputer's turn:");
            while(1)
            {
                srand(time(NULL));
                n=rand()%l+0;
                x=(n-1)/r;
                y=(n-1)%c;
                if(arr[x][y]!=0)
                {
                    break;
                }
            }
        }
        for(i=x;i<r;i++)
        {
            for(j=y;j<c;j++)
            {
                arr[i][j]=0;
            }
        }
        a=check();
        t++;
    }while(a==0);
    board();
    t--;
    if((a==1)&&(t%2==0))
        printf("\nYou Win........");
    else if((a==1)&&(t%2!=0))
        printf("\nComputer Win........");
    restore();
}

int check()
{
    if(arr[r-1][0]==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    printf("\t\t    Game of Chomp\n\n\n\t");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(arr[i][j]<=9)
            {
                printf("0");
            }
            printf("%d  ",arr[i][j]);
        }
        printf("\n\n\t");
    }
}

void restore()
{
    v=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            arr[i][j]=v;
            v++;
        }
    }
}

void makezero()
{
    for(i=x;i<r;i++)
    {
        for(j=y;j<c;j++)
        {
            arr[i][j]=0;
        }
    }
}
