#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int w=30,h=15,x,y,go=0,i,j,fx,fy,score=0;
char dir;
void set();
void home();
void input();
void move();

int main()
{
    set();
    while(go!=1)
    {
        home();
        input();
        move();
    }
    printf("\nGame Over.....");
}

void move()
{
    switch(dir)
    {
        case 'l':x--;break;
        case 'r':x++;break;
        case 'u':y--;break;
        case 'd':y++;break;
        default:break;
    }

    if(x<-1)
        go=1;
    if(x==w+1)
        go=1;
    if(y==h+1)
        go=1;
    if(y<-1)
        go=1;
    if((x==fx)&&(y==fy))
    {
        score=score+10;
        srand(time(NULL));
        fx=rand()%w+0;
        fy=rand()%h+0;
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
            case 'm':dir='d';break;
            case 'l':dir='r';break;
            case 'e':go=1;break;
            default:break;
        }
    }
}

void set()
{
    x=w/2;
    y=h/2;
    srand(time(NULL));
    fx=rand()%w+0;
    fy=rand()%h+0;
}

void home()
{
    system("cls");
    printf("Move Up = 'i' and Down = 'm'\n");
    printf("Right = 'l' and Left = 'j'\n");
    printf("Snake = '*' and Food = 'o'\n");
    printf("Avoid Clash with '#'\n\n\n");
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
            if((i==y)&&(j==x))
            {
                printf("*");
            }
            else if((i==fy)&&(j==fx))
            {
                printf("o");
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
