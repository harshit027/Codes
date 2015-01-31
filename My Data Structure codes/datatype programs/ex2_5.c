//sum of first n natural numbers:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int x,y;
printf("Enter any positve int number");
scanf("%d",&y);
printf("The sum of first%d integers=%d\n",y,sum(y));
}
int sum(int y)
{
if(y==0)
return 0;
else
return(y+sum(y-1));
}