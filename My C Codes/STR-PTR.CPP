/*demonstration of structure pointer :HARSHIT*/
#include"stdio.h"
#include"conio.h"
typedef struct data
{
clrscr();
int a;
int b;
}d;
void main()
{
d d1;
d *p;
p=&d1;
puts("\nenter the values of a and b: ");
scanf("%d%d",&p->a,&p->b);
printf("\nyou entered the values  a = %d and b = %d ",p->a,p->b);
getch();
}
