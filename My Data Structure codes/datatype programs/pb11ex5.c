#include<stdio.h>
#include<conio.h>
int j;
void main()
{
int i,k;
clrscr();
for(i=1;i<=3;i++)
{
k=increment();
printf("k=%d\n",k);
}
}
increment()
{
j++;
return(j);
}