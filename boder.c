#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,height=20,width=20;
    for(i=0;i<height;i++)
    {
        for(j=0;j<width;j++)
        {
            if(i==0||i==height-1||j==0||j==width-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
    }
}
