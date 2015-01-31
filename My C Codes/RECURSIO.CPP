/*recursion demonstration :HARSHIT*/
#include"stdio.h"
#include"conio.h"
int fact(int a)
{
if(a==1)
return 1;
else
{
a=a*fact(a-1);
return a;
}
}
void main()
{
clrscr();
int x;
puts("\nenter any integer : ");
scanf("%d",&x);
printf("\nthe factorial of %d is : %d",x,fact(x));
getch();
}

