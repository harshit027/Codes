/*dynamic implementation of queue and operations on it : HARSHIT*/

#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

typedef struct queue
{
int data;
struct queue *next;
}node;

node *first=NULL,*temp1,*temp2;
/*-------------------------------------------------------------------*/
/*inserts a node in the queue*/
void inserts(int val)
{
puts("\ninserts() called");
temp1=first;
puts("\na node is added in the queue :");
puts("\nenter the value to be stored in the node:");
scanf("%d",&val);
if(first==NULL)
{
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=NULL;
first=temp2;
}
else
{
while(temp1->next!=NULL)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=NULL;
temp1->next=temp2;
}}
/*------------------------------------------------------------*/
/*deletes a node from the queue*/
void deletes()
{
puts("\ndeletes() called :");
int x;
puts("\nif surely want to delete, press 1 else anything to return : ");
scanf("%d",&x);
if(x==1)
{
if(first==NULL)
{
puts("\nqueue is already empty :");
return;
}
else
{
temp1=first;
first=first->next;
printf("\ndeleted element is %d",temp1->data);
temp1->next=NULL;
free(temp1);
}}
else
return;
}
/*-----------------------------------------------------------------*/
/*displays the status of queue*/
void display()
{
puts("\nthe status of the queue is:");
temp1=first;
while(temp1!=NULL)
{
printf("\nloc = %u | data = %d | next = %u",temp1,temp1->data,temp1->next);
temp1=temp1->next;
}}
void main()
{
clrscr();
int a;
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