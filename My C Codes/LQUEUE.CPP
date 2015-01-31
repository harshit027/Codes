/*static implementation of queues and operation os it :HARSHIT*/

#include"stdio.h"
#include"conio.h"

#define size 5

int queue[size];
int f=-1,r=-1;
/*------------------------------------------------------------*/
/*inserts an element in the queue*/
void inserts(int val)
{
puts("\ninserts() called :");
if(r>size-2)
{
puts("\nqueue is full, no further insertion is allowed:");
return;
}
else
{
r=r+1;
puts("\nenter the value to be stored in the next locaion of queue:");
scanf("%d",&val);
queue[r]=val;
}}

/*-------------------------------------------------------------*/
/*deletes an element from the queue*/
void deletes()
{
int i=0,x;
puts("\ndeletes() called : ");
puts("\nif surely want to delete, press 1, else anything to return :");
scanf("%d",&x);
if(x==1)
{
if(r<0)
{
puts("\nqueue is already empty :");
return;
}
else
{
printf("\ndeleted element = %d",queue[i]);
while(i<r)
{
queue[i]=queue[i+1];
i++;
}
queue[r]=NULL;
r--;
}}
else
return;
}
/*-----------------------------------------------------------*/
/*displays the status of queue */
void display()
{
int i;
puts("\nthe status of the queue is : ");
for(i=0;i<=r;i++)
printf("\n%d : %d",&queue[i],queue[i]);
}
/*----------------------------------------------------------------*/
void main()
{
clrscr();
int a;
inserts(a);
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
deletes();
display();
deletes();
getch();
}