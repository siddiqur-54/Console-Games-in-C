#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void set();
void draw();
void input();
void run();

int w=24,h=14,i,j,k,x,y,go=0,cx,cy,cx1,cy1,cx2,cy2,score=0;
char dir;

int main()
{
    set();
    while(go!=1)
    {
        draw();
        run();
        input();
    }
    printf("\nGame Over.....");
}

void run()
{
    cy++;
    cy1++;
    cy2++;
    if(cy==h-1)
    {
        cy=0;
        srand(time(NULL));
        cx=rand()%w+0;
        score=score+5;
    }
    if(cy1==h-1)
    {
        cy1=0;
        srand(time(NULL));
        cx1=rand()%w+0;
        while(cx1==cx)
        {
            cx1=rand()%w+0;
        }
        score=score+5;
    }
    if(cy2==h-1)
    {
        cy2=0;
        srand(time(NULL));
        cx2=rand()%w+0;
        while((cx2==cx1)||(cx2==cx))
        {
            cx2=rand()%w+0;
        }
        score=score+5;
    }
    if(((cx==x)&&(cy==y))||((cx1==x)&&(cy1==y))||((cx2==x)&&(cy2==y)))
    {
        go=1;
    }
}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'i':y--;break;
            case 'j':x--;break;
            case 'l':x++;break;
            case 'm':y++;break;
            case 'e':go=1;break;
            default:break;
        }
    }

    if(x<0)
        go=1;
    if(x==w)
        go=1;
    if(y<0)
        go=1;
    if(y==h)
        go=1;
}

void draw()
{
    system("cls");
    printf("Move Up = 'i' and Down = 'm'\n");
    printf("Right = 'l' and Left = 'j'\n");
    printf("Car = '*' and Traffic = 'x'\n");
    printf("Avoid Clash with 'x'\n\n\n");
    for(i=0;i<w+2;i++)
    {
        printf("#");
    }
    printf("\n");
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(j==0)
            {
                printf("#");
            }
            if((j==x)&&(i==y))
            {
                printf("*");
            }
            else if((i==cy)&&(j==cx))
            {
                printf("x");
            }
            else if((i==cy1)&&(j==cx1))
            {
                printf("x");
            }
            else if((i==cy2)&&(j==cx2))
            {
                printf("x");
            }
            else
                printf(" ");
            if(j==w-1)
                printf("#");
        }
        printf("\n");
    }
    for(i=0;i<w+2;i++)
    {
        printf("#");
    }
    printf("\nScore = %d",score);
}

void set()
{
    x=w/2;
    y=h-2;
    cx=3;
    cy=0;
    cx1=9;
    cy1=0;
    cy2=0;
    cx2=6;
}
