/*array implementation of stacks  :HARSHIT*/
#include"stdio.h"
#include"conio.h"

#define size 5

typedef struct stack
{
int list[size];
int top;
}s;

int first=0; s *p1;

/*-----------------------------------------------------------*/

void settop(s *p)
{
p->top=-1;
puts("\na stack is created :");
}
/*--------------------------------------------------------------------*/
/*checks whether stack is empty or not */
int empty(s *p)
{
if(p->top==-1)
return 1;
else
return 0;
}
/*---------------------------------------------------------------*/
/*checks whether the stack is full or not*/
int full(s *p)
{
if (p->top==size-1)
return 1;
else
return 0;
}
/*----------------------------------------------------------------------*/
/*pushes a value in the stack*/
void push(s *p,int val)
{
if(full(p)==1)
{
puts("\nstack is full now:");
return ;
}
puts("\nenter the value to be stored in the stack :");
scanf("%d",&val);
p->top++;
p->list[p->top]=val;
first=p->top;
}
/*---------------------------------------------------------------------*/
/*pops a value from the stack*/
void pop(s *p)
{
puts("\n\na value is popped from the stack :");
int val;
if(empty(p)==1)
{
puts("\nstack is empty now :");
return;
}
val=p->list[p->top];
p->top--;
first=p->top;
printf("\nthe value popped from the stack is : %d ",val);
}
/*-----------------------------------------------------------------*/
/*gives the top char of stack*/
void gettop(s *p)
{
printf("\n\nthe value at the top of stack = %d",p->list[first]);
}


/*-----------------------------------------------------------------------*/
/*displays the status of the stack*/
void display(s *p)
{
puts("\n\nthe status of stack is :");
int i,j=0;
i=first;
while(i!=-1)
{
printf("\naddress = %u and value = %d",&p->list[i],p->list[i]);
i--;j++;
}
printf("\n\nnumber of elements = %d",j);
}
/*--------------------------------------------------------------*/
void main()
{
int a;
s s1;
clrscr();
settop(&s1);
push(&s1,a);
push(&s1,a);
push(&s1,a);
push(&s1,a);
push(&s1,a);
display(&s1);
pop(&s1);
pop(&s1);
pop(&s1);
display(&s1);
push(&s1,a);
gettop(&s1);
display(&s1);
getch();
}




