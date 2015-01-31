/*structure array :HARSHIT*/
#include"stdio.h"
#include"conio.h"
typedef struct data
{
char name[10];
int a;
int b;
}d;
void main()
{
clrscr();
d d1[3];
int i;
puts("\nenter the elements of the structure :");
for(i=0;i<3;i++)
{
printf("\nenter integers for the structure %d : ",i+1);
scanf("%d%d",&d1[i].a,&d1[i].b);
puts("\nenter string : ");
scanf("%s",d1[i].name);
}
puts("\nyou entered the following data : ");
for(i=0;i<3;i++)
{
printf("\n\nstructure %d : \n",i+1);
printf("\nnumbers entered are %d and %d  \nstring entered is %s.",d1[i].a,d1[i].b,d1[i].name);
}
getch();
}