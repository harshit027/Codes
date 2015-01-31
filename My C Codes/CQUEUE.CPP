/*circular queue implementation and operations on it: HARSHIT*/

#include"stdio.h"
#include"conio.h"

#define size 5

int cqueue[size];
int f=0,r=0;
/*-----------------------------------------------------------------------*/
/*inserts an element in the queue */
void inserts(int val)
{
puts("\ninserts() called:");
if(f==(r+1)%size)
{
puts("\nqueue is full, no further insertion is possible :");
return;
}
else
{
puts("\nenter the value to be stored in the queue :");
scanf("%d",&val);
cqueue[r]=val;
r=(r+1)%size;
}}
/*------------------------------------------------------------------------*/
/*deletes an element from the queue*/
void deletes()
{
int val;
puts("\ndeletes() called :");
if(f==-1)
{
puts("\nqueue is already empty :");
return;
}
else
{
val=cqueue[f];
printf("\ndeleted element is %d ",val);
if(f==r)
f=r=-1;
else
f=(f+1)%size;
}
}
/*--------------------------------------------------------------------*/
/*displays the status of the queue*/
void display()
{
int i;
puts("\nthe status of the queue is :");
for(i=f;i<=r;i++)
printf("\n%u : %d",&cqueue[i],cqueue[i]);
if(f>r)
{
for(i=f;i<size;i++)
printf("\n%u : %d",&cqueue[i],cqueue);
for(i=0;i<=r;i++)
printf("\n%u : %d",&cqueue[i],cqueue[i]);
}
}
/*-----------------------------------------------------------------------*/
void main()
{
int a;
clrscr();
inserts(a);
inserts(a);
inserts(a);
inserts(a);
inserts(a);
inserts(a);
display();
deletes();
display();
deletes();
display();
deletes();
display();
inserts(a);
inserts(a);
display();
getch();
}