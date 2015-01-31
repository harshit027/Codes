//pallendrom for integerS :HARSHIT

#include<stdio.h>
#include<conio.h>
void main ( )
{
int a[10], num, i=0, result=0, n;
clrscr();
printf("enter the number");
scanf("%d",&n);
num = n;
while (num!=0)
  {
result=result*10;
a[i]=num%10;
num=num/10;
result=result+a[i];
 i++;
}
if (result == n)
 printf("The number is pallandrome");
getch( );
}
