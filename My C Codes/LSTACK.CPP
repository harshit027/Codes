/*dynamic implementation of stack:HARSHIT*/
#include"stdio.h"
#include"stdlib.h"
#include"conio.h"

typedef struct lstack
{
int data;
struct lstack *next;
}s;
s *top,*temp1,*temp2;
/*------------------------------------------------------------------*/
/*sets top ptr to NULL*/
void settop()
{
puts("\na dynamically accessed stack is created :");
top=NULL;
}
/*----------------------------------------------------------------*/
/*pushes a value in the stack*/
void push(int val)
{
puts("\n\npush called :");
puts("\na new node is added in the stack :");
puts("\nenter the value to be stored in the node :");
scanf("%d",&val);
temp1=(lstack*)malloc(sizeof(lstack));
temp1->data=val;
temp1->next=top;
top=temp1;
}

/*------------------------------------------------------------------*/
/*pops an element from the stack*/
void pop()
{
puts("\n\npop() called :");
int val;
if(top==NULL)
{
puts("\nstack is empty now :");
return;
}

temp1=top;
top=top->next;
val=temp1->data;
printf("\nthe value popped from stack is %d",val);
temp1->next=NULL;
free(temp1);
}
/*----------------------------------------------------------------*/
/*displays the status of stack*/
void display()
{
int i=0;
puts("\nthe  status of stack is :");
temp1=top;
while(temp1!=NULL)
{
printf("\naddress = %u and value = %d",temp1,temp1->data);
temp1=temp1->next;
i++;
}
printf("\nnumber of nodes = %d",i);
}
/*------------------------------------------------------------------------*/
void main()
{
int a;
clrscr();
settop();
push(a);
push(a);
push(a);
push(a);
display();
pop();
pop();
display();
getch();
}