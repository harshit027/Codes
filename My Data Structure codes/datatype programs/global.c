#include<stdio.h>
#include<conio.h>
int i=0;
void main()
{
clrscr();
printf("main's i=%d\n",i);
i++;
vl();
printf("main's i=%d\n",i);
vl();
}
vl()
{
i=100;
printf("vl's=%d\n",i);
i++;
getch();
}
