/*use of callo() :HARSHIT */
#include"stdio.h"
#include"conio.h"
#include"malloc.h"
void main()
{
clrscr();
int *p;
int i,n,a;
p=&a;
puts("\nenter the number of values to be stored : ");
scanf("%d",&n);
p=(int*)calloc(sizeof(int),n);
puts("\nenter the values : ");
for(i=0;i<n;i++)
{
scanf("\n%d",p);
p++;
}
puts("\nthe adress at which value is stored : ");
for(i=0;i<n;i++)
{
printf("\n%d : %d",i+1,p);
p++;
}
getch();
}