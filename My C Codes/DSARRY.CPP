/*array as data structure :HARSHIT*/

#include"stdio.h"
#include"conio.h"
void main()
{
int i,a[5],index,x;
clrscr();
printf("\nenter the elements  of array : ");
for(i=0;i<4;i++)
scanf("%d",&a[i]);
printf("\nthe entered array is : ");
for(i=0;i<4;i++)
printf("\t%d",a[i]);
printf("\nenter the index at which value is to be inserted : ");
scanf("%d",&index);
for(i=4;i>index;i--)
a[i]=a[i-1];
printf("\nenter the new value : ");
scanf("%d",&x);
a[index]=x;
printf("\nthe new array is : ");
for(i=0;i<5;i++)
printf("\t%d",a[i]);
printf("\nenter the index at which the value is to be deleted : ");
scanf("%d",&index);
for(i=index;i<5;i++)
a[i]=a[i+1];
a[4]=NULL;
printf("\nthe new array is : ");
for(i=0;i<5;i++)
printf("\t%d",a[i]);
getch();
}


