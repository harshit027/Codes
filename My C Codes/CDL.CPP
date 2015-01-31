/*creation of circular doubly linked list :HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

typedef struct cir_doubly
{
int data;
struct cir_doubly *next,*prev;
}node;
node *first,*temp1,*temp2;
/*---------------------------------------------------------------*/
/*creates a circular doubly linked list */
void createlist(int val)
{
puts("\na circular-doubly linklist is created :");
puts("\nenter the value to be stored in the first node :");
scanf("%d",&val);
first=(node*)malloc(sizeof(node));
first->data=val;
first->next=first;
first->prev=first;
}
/*------------------------------------------------------------------*/
/*adds a node in the list */
void addnode(int val)
{
puts("\naddnode() called :");
puts("\na new node is added in the list:");
puts("\nenter the value to be stored in the newly added node : ");
scanf("%d",&val);
temp1=first;
while(temp1->next!=first)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=temp1->next;
temp2->prev=temp1;
temp1->next=temp2;
temp2->next->prev=temp2;
}
/*------------------------------------------------------------------------*/
/*adds a new node in the list at the head */
void inserthead(int val)
{
puts("\ninserthead() called :");
node *temp;
puts("\na node is added in the list at the head :");
puts("\nenter the value to be stored in the node :");
scanf("%d",&val);
temp1=first;
temp=first;
while(temp->next!=first)
temp=temp->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=temp1;
temp2->prev=temp1->prev;
temp1->prev=temp2;
temp->next=temp2;
first=temp2;
}
/*--------------------------------------------------------------------*/
/*adds a new node in the list at the tail*/
void inserttail(int val)
{
puts("\ninserttail() called :");
temp1=first;
puts("\na new node is added in the list at the tail :");
puts("\nenter the value to be stored in the newly added node :");
scanf("%d",&val);
while(temp1->next!=first)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->prev=temp1;
temp2->next=temp1->next;
temp1->next=temp2;
}
/*-------------------------------------------------------------------*/
/*deletes a node in the list form the head */
void delhead()
{
puts("\ndelhead() called :");
char x;
puts("\ndo you want to delete the node y/n : ");
scanf("%c",&x);
if (x=='y')
{
puts("\na node is deleted in the list from the head :");
temp1=first;
temp2=first;
while(temp1->next!=first)
temp1=temp1->next;
temp2->next->prev=temp2->prev;
temp1->next=temp2->next;
first=temp2->next;
temp2->next=NULL;
temp2->prev=NULL;
free(temp2);
}
else
return;
}
/*--------------------------------------------------------------------*/
/*deletes a node in the list from the tail*/
void deltail()
{
char x;  node* temp;
puts("\ndeltail() called :");
puts("\ndo you want to delete the node y/n : ");
scanf("%c",&x);
if(x=='y')
{
puts("\na node is deleted in the list from the tail :");
temp1=first;
temp=first;
while(temp1->next!=first)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp1->next;
temp->prev=temp2;
temp1->next=temp1->prev=NULL;
free(temp1);
}
else
return;
}
/*--------------------------------------------------------------------*/
/*displays the status of list*/
void display()
{
puts("\nthe status of list is : ");
temp1=first;
int i=1;
while(temp1->next!=first)
{
printf("\nnode %d : data = %d | address of node = %u | ",i,temp1->data,temp1);
printf("prev = %u | next = %u ",temp1->prev,temp1->next);
temp1=temp1->next;
i++;
}
printf("\nnode %d : data = %d | address of node = %u | ",i,temp1->data,temp1);
printf("prev = %u | next = %u ",temp1->prev,temp1->next);
printf("\n\nnumber of nodes in the list = %d",i);
}

/*-------------------------------------------------------------------*/
void main()
{
int a;
clrscr();
createlist(a);
addnode(a);
addnode(a);
addnode(a);
display();
inserthead(a);
display();
inserttail(a);
display();
delhead();
display();
deltail();
display();
getch();
}