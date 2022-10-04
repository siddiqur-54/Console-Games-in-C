#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void set();
void draw();
void input();
void run();

int w=18,h=14,i,j,k,x,y,go=0,cx1,cy1,cx2,cy2,score=0,fx,fy;
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
    cy1++;
    cy2--;
    if(cy1==h-1)
    {
        cy1=0;
    }
    if(cy2==0)
    {
        cy2=h-1;
    }
    if(((cx1==x)&&(cy1==y))||((cx2==x)&&(cy2==y)))
    {
        go=1;
    }
    switch(dir)
    {
        case 'u':y--;break;
        case 'l':x--;break;
        case 'd':y++;break;
        case 'r':x++;break;
        case 's':go=1;printf("\nThank you....");break;
        default:break;
    }
    if(x<0)
        x=w-1;
    if(x==w)
        x=0;
    if(y==h)
        y=0;
    if(y<0)
        y=h-1;
    if((x==fx)&&(y==fy))
    {
        score=score+10;
        srand(time(NULL));
        fx=rand()%w+0;
        fy=rand()%h+0;
        while((fx==cx1)||(fx==cx2))
        {
            fx=rand()%w+0;
        }
    }

}

void input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'i':dir='u';break;
            case 'j':dir='l';break;
            case 'l':dir='r';break;
            case 'm':dir='d';break;
            case 'e':dir='s';break;
            default:break;
        }
    }
}

void draw()
{
    system("cls");
    printf("Move Up = 'i' and Down = 'm'\n");
    printf("Right = 'l' and Left = 'j'\n");
    printf("Snake = 'o' and Food = 'F'\n");
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
                printf("o");
            }
            else if((i==cy1)&&(j==cx1))
            {
                printf("x");
            }
            else if((i==cy2)&&(j==cx2))
            {
                printf("x");
            }
            else if((i==fy)&&(j==fx))
            {
                printf("F");
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
    y=h/2;
    cx1=4;
    cy1=0;
    cx2=10;
    cy2=h-1;
    fx=5;
    fy=5;
}
