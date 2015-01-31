/*use of realloc() : HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"malloc.h"
void main()
{
clrscr();
int *p;
int i,n,m;
puts("\nenter the number of values to be stored : ");
scanf("%d",&n);
p=(int*)malloc(sizeof(int)*n);
puts("\nenter the values :");
for(i=0;i<n;i++)
{
scanf("%d",p);
p++;
}
puts("\nthe adress of the values stored is : ");
for(i=0;i<n;i++)
{
printf("\n%d : %d",i+1,p);
p++;
}
puts("\nenter the number of values to be stored more : ");
scanf("%d",&m);
int *q;
q=(int*)realloc(p,n+m);
puts("\menter the values : ");
for(i=n;i<n+m;i++)
{
scanf("%d",q);
q++;
}
puts("\nthe adress of values stored is : ");
for(i=0;i<n+m;i++)
{
printf("\n%d : %d",i+1,q);
q++;
}
getch();
}