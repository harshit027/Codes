/*use of malloc : HARSHIT */
#include"stdio.h"
#include"conio.h"
#include"malloc.h"
void main()
{

clrscr();
int *p;
int i,n;
puts("\nenter the number of integers to be allocated memory : ");
scanf("%d",&n);
p=(int*)malloc(sizeof(int)*n);
puts("\nenter the values : ");
for(i=0;i<n;i++)
{
scanf("%d",p);
p++;
}
puts("\nthe address at which values are stored : ");
for(i=0;i<n;i++)
{
printf("\n %d : %d ",i+1,p);
p++;
}
getch();
}