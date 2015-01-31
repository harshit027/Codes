/*array of pointers :HARSHIT*/
#include"stdio.h"
#include"conio.h"
void main()
{
clrscr();
int a[5];
int *p[5];
puts("\nenter the values : ");
for(int i=0;i<5;i++)
{
p[i]=&a[i];
scanf("%d",p[i]);
}
puts("\nthe values you entered are : ");
for(i=0;i<5;i++)
printf("\naddress = %u and value =%d",p[i],*p[i]);
getch();
}