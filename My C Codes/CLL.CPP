/*creation of circular linked list and operations on it :HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

/*declaration of node of the linklist*/
typedef struct circularlinklist
{
int data;
struct circularlinklist *next;
}node;
node *first,*temp1,*temp2;
/*---------------------------------------------------*/
/*creates the list */
void createlist(int val)
{
puts("\na circular linklist is created :");
puts("\nenter the value to be stored in the first node :");
scanf("%d",&val);
first=(node*)malloc(sizeof(node));
first->data=val;
first->next=first;
}
/*------------------------------------------------------------*/
/*adds a node in the list*/
void addnode(int val)
{
puts("\na node is added in the list :");
puts("\nenter the value to be stored in the node :");
scanf("%d",&val);
temp1=first;
while(temp1->next!=first)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=first;
temp1->next=temp2;
}
/*----------------------------------------------------------------*/
/*adds a new node at the head*/
void inserthead(int val)
{
puts("\na new node is added in the list at the head : ");
puts("\nenter the value to be stored in the node :");
scanf("%d",&val);
while(temp1->next!=first)
temp1=temp1->next;

temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=first;
first=temp2;
temp1->next=first;
}
/*---------------------------------------------------------------*/
/*adds a new node at the tail */
void inserttail(int val)
{
puts("\na new node is added in the list at the tail ");
puts("\nenter the value in the newly added node ;");
scanf("%d",&val);
temp1=first;
while(temp1->next!=first)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=first;
temp1->next=temp2;
}
/*----------------------------------------------------------------*/
/*deletes a node in the list from the head*/
void delhead()
{
temp1=first;
puts("\na node is deleted in the list from the head :");
while(temp1->next!=first)
temp1=temp1->next;
temp1->next=first->next;
temp2=first;
first=temp1->next;
temp2->next=NULL;
free(temp2);
}
/*---------------------------------------------------------------*/
/*deletes a node in the list from the tail*/
void deltail()
{
puts("\na node is deleted in the list from the tail ;");
temp1=first;
while(temp1->next!=first)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=first;
temp1->next=NULL;
free(temp1);
}

/*----------------------------------------------------------------*/
/*displays the status of the list*/
void display()
{
int i=1;
puts("the status of the linklist is :");
temp1=first;
while(temp1->next!=first)
{
printf("\nnode %d : data = %d | address of node = %u |",i,temp1->data,temp1);
printf(" next = %u ",temp1->next);
temp1=temp1->next;
i++;
}
printf("\nnode %d : data = %d | address of node = %u |",i,temp1->data,temp1);
printf(" next = %u ",temp1->next);
printf("\n\nnumber of nodes in the list = %d",i);
}
/*------------------------------------------------*/
/*gets the number of nodes*/
int getnum_nodes()
{
int i=1;
temp1=first;
while(temp1->next!=first)
{
temp1=temp1->next;
i++;
}
return i;
}

/*------------------------------------------------*/
/*swaps the mth and nth node*/
void swapmn(int m, int n)
{
int i;
node *p,*q,*p1,*q1,*p2,*q2;
puts("\nenter the index of nodes to be interchanged except 1st and last:");
scanf("%d%d",&m,&n);
if(m>getnum_nodes()||n>getnum_nodes())
{
puts("\nyou entered invalid indexes");
puts("\nTry next time :");
return;
}
else
{
printf("\nthe nodes %d and %d are interchanged : ",m,n);
temp1=first;
for(i=1;i<m;i++)
{
p=temp1;
temp1=temp1->next;
p1=temp1;
}
temp1=first;
for(i=1;i<n;i++)
{
q=temp1;
temp1=temp1->next;
q1=temp1;
}
p2=p1->next;
q2=q1->next;
p->next=q1;
p1->next=q2;
q->next=p1;
q1->next=p2;
puts("\nstatus of list after swapping :");
}}

/*-----------------------------------------------------------------*/
void main ()
{
int a,b;
clrscr();
createlist(a);
for(int i=0;i<4;i++)
addnode(a);
display();
swapmn(a,b);
display();

getch();
}