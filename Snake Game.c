#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int width=20,height=20,gameover,flag;
int snakeX,snakeY,fruitX,fruitY,score;
int tailX[100],tailY[100];
int prev2X,prev2Y;
int count_tail=0;
void setup()
{
 gameover=0;
 snakeX=width/2;
 snakeY=height/2;
 fruitX:
     {
         fruitX=rand()%20;
     }
 fruitY:
     {
         fruitY=rand()%20;
     }
 if(fruitX==0)
 {
     goto fruitX;
 }
 if(fruitY==0)
 {
     goto fruitY;
 }
 score=0;
}
void draw()
{
 int i,j,k;
 system("cls");
 for(i=0;i<height;i++)
 {
     for(j=0;j<width;j++)
     {
         if(j==0||j==(height-1))
         {
             printf("|");
         }
         if(i==0||i==(width-1))
         {
             printf("_");
         }
         else
         {
             if(i==snakeX&&j==snakeY)
             {
                 printf("O");
             }
             else if(i==fruitX&&j==fruitY)
             {
                 printf("*");
             }
             else
             {
                 int l=0;
                 for(k=0;k<count_tail;k++)
                 {
                     if(i==tailX[k]&&j==tailY[k])
                     {
                         printf("o");
                         l=1;
                     }
                 }
                 if(l==0)
                 {
                      printf(" ");
                 }
             }
         }
     }
      printf("\n");
 }
 printf("SCORE:%d",score);
}
void input()
{
    if(kbhit())
    {
          switch(getchar())
          {
              case 'a':
                 {
                     flag=1;
                     break;
                 }
              case 's':
                {
                    flag=2;
                    break;
                }
              case 'd':
                {
                    flag=3;
                    break;
                }
              case 'w':
                {
                    flag=4;
                    break;
                }
              case 'x':
                {
                    flag=5;
                    break;
                }
          }
    }
}
void logic()
{
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2x;
    int prev2Y;
    int i;
    tailX[0]=snakeX;
    tailY[0]=snakeY;
    for(i=1;i<=100;i++)
    {
        prev2X=tailX[0];
        prev2Y=tailY[0];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }
    switch(flag)
    {
    case 1:
        {
            snakeY--;
            break;
        }
    case 2:
        {
            snakeX++;
            break;
        }
    case 3:
        {
            snakeY++;
            break;
        }
    case 4:
        {
            snakeX--;
            break;
        }
    default:
        {
            break;
        }
    }
    if(snakeX<0||snakeX>width||snakeY<0||snakeY>height)
    {
        gameover=1;
    }
    for(i=0;i<count_tail;i++)
    {
        if(snakeX==tailX[i]&&snakeY==tailY[i])
        {
            gameover=1;
        }
    }
    if(snakeX==fruitX&&snakeY==fruitY)
    {
        fruitXR:
        {
             fruitX=rand()%20;
        }
        if(fruitX==0)
        {
             goto fruitXR;
        }

        fruitYR:
        {
             fruitY=rand()%20;
        }
        if(fruitY==0)
        {
             goto fruitYR;
        }
        score+=10;
        count_tail++;
    }
}
void delay()
{
    long double m,n;
    for(m=0;m<5000;m++)
    {
        for(n=0;n<5000;n++);
    }
}
int main()
{
    char c;
    repeat:
    {

        setup();
        while(gameover!=1)
        {
            draw();
            input();
            logic();
            delay();
        }
        printf("GAME OVER");
        printf("\nPress R to continue");
   }
   if(kbhit())
        {
            switch(getchar())
            {
            case 'r':
                {
                     goto repeat;
                     break;

                }
            }

        }
}
