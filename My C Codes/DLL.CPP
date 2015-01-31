/*creation of doubly linkedlist and operations on it: HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"

/*declaration of the node of the list */

typedef struct doubly_linkedlist
{
int data;
struct doubly_linkedlist *next,*prev;
}node;
node *first,*temp1,*temp2;
/*---------------------------------------------------------*/
/*creates the linked list */

void createlist(int val)
{
puts("\na doubly linklist is created with one node:");
puts("\nenter the value in the first node :");
scanf("%d",&val);
temp1=(node*)malloc(sizeof(node));
temp1->data=val;
temp1->next=NULL;
temp1->prev=NULL;
first=temp1;
}
/*-------------------------------------------------------------*/
/*adds a node in the list*/

void addnode(int val)
{
temp1=first;
puts("\nanode is added in the list :");
puts("\nenter the value in the newly added node :");
scanf("%d",&val);
while(temp1->next!=NULL)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=NULL;
temp2->prev=temp1;
temp1->next=temp2;
}
/*---------------------------------------------------------------*/
/*a node is added in the list at the head */
void inserthead(int val)
{
temp1=first;
puts("\na node is added in the list at the head :");
puts("\nenter the value to be stored in the newly added node :");
scanf("%d",&val);
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=temp1;
temp1->prev=temp2;
temp2->prev=NULL;
first=temp2;
}
/*---------------------------------------------------------------*/
/*adds a new node in the list at the tail*/
void inserttail(int val)
{
puts("\na new node is added in the list at the tail :");
puts("\nenter the value to be stored in the newly added node :");
scanf("%d",&val);
temp1=first;
while(temp1->next!=NULL)
{
temp1=temp1->next;
}
temp2=(node*)malloc(sizeof(node));
temp2->data=val;
temp2->next=NULL;
temp1->next=temp2;
temp2->prev=temp1;
}
/*----------------------------------------------------------------*/
/*deletes anode from the head */
void delhead()
{
puts("\na node is deleted from the head :");
temp1=first;
temp2=temp1->next;
temp2->prev=NULL;
temp1->next=NULL;
first=temp2;
free(temp1);
}
/*---------------------------------------------------------------*/
/*deletes a node from the tail */
void deltail()
{
puts("\na node is deleted form the tail :");
temp1=first;
while(temp1->next!=NULL)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=NULL;
temp1->prev=NULL;
free(temp1);
}
/*---------------------------------------------------------------*/
/*displays the status of list*/

void display()
{
int i=1;
temp1=first;
puts("\nthe status of the linked list is : ");
while(temp1!=NULL)
{
printf("\nnode %d : data = %d | adress of node = %u",i,temp1->data,temp1);
printf("| prev = %u | next = %u  ",temp1->prev,temp1->next);
temp1=temp1->next;
i++;
}
printf("\n\nnumber of nodes are = %d",i-1);
}
/*--------------------------------------------------------*/

void main()
{
clrscr();
int a;
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