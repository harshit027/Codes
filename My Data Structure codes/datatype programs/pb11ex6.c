//use of register and auto keywords :HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
auto int i=10;
register int j= 20;
printf("main i and j are %d%d\n",i,j);
change();
printf("main's i and j are %d%d",i,j);
getch();
}
change()
{
auto int i=100;
register int j=200;
printf("change i and j are %d%d\n",i,j);
}
