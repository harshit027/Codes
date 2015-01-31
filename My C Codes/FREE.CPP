/*use of free() :HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"malloc.h"
void main()
{
clrscr();
int *p;
int i,n;
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
puts("\n calling the free function to free the memory : ");
for(i=0;i<n;i++)
{
free(p);
p++;
}
puts("\nmemory is free now : ");
getch();
}