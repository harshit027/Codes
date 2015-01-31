/*pointer to an array : HARSHIT */
#include"stdio.h"
#include"conio.h"
void main()
{
clrscr();
int a[5];
int *p;
p=&a[0];
int i;
puts("\nenter the values in the array:");
for(i=0;i<5;i++)
{
scanf("%d",p);
p++;
}
puts("\nThe address of the values are as (given by pointers): ");
for(i=0;i<5;i++)
{
printf("\n%d : %u ",i+1,p);
p++;
}
getch();
}
