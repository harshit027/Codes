/*multiple stacks :HARSHIT*/
#include"stdio.h"
#include"conio.h"

#define size 7

typedef struct mstack
{
int list[size];
int top1,top2;
}s;
int first,last;
/*-----------------------------------------------------------*/
/*sets the tops to null*/
void settop(s *p)
{
puts("\na multiple stack is created :");
p->top1=-1;
p->top2=size;
}

/*------------------------------------------------------------*/
/*checks emptiness of stack with top1*/
int empty1(s *p)
{
if (p->top1==-1)
return 1;
else
return 0;
}
/*-----------------------------------------------------------------*/
/*checks emptiness of stack with top2*/
int empty2(s *p)
{
if(p->top2==size)
return 1;
else
return 0;
}
/*-----------------------------------------------------------------*/
/*checcks whether the stack is full or not*/
int full(s *p)
{
if(p->top1+1==p->top2)
return 1;
else
return 0;
}
/*-----------------------------------------------------*/
/*pushes a value in the stack with top1*/
void push1(s *p,int val)
{
puts("\npush1() called :");
if(full(p)==1)
{
puts("\nthe stack is full now:");
return ;
}
puts("\nenter the value to be pushed in the stack:");
scanf("%d",&val);
p->top1++;
p->list[p->top1]=val;
first=p->top1;
}
/*--------------------------------------------------------*/
void push2(s *p,int val)
{
puts("\npush2() called :");
if(full(p)==1)
{
puts("\nstack is full now:");
return ;
}
puts("\nenter the value to be pushed in the stack :");
scanf("%d",&val);
p->top2--;
p->list[p->top2]=val;
last=p->top2;
}

/*--------------------------------------------------------*/
/*pops a value from the stack with top1:*/
void pop1(s *p)
{
puts("\npop1() called");
int val;
if(empty1(p)==1)
{
puts("\nstack is empty from top1 now:");
return ;
}
val=p->list[p->top1];
p->top1--;
printf("\nthe value popped from the stack is %d",val);
first=p->top1;
}
/*-------------------------------------------------------------*/
void pop2(s *p)
{
int val;
puts("\npop2() called");
if(empty2(p)==1)
{
puts("\nstack is empty from top2 now:");
return ;
}
val=p->list[p->top2];
p->top2++;
printf("\nthe value popped from the stack is %d",val);
last=p->top2;
}
/*--------------------------------------------------------------*/
void display(s *p)
{
puts("\nstatus of stack :");
int i;
puts("\n\nfrom top1 :");
i=first;
while(i!=-1)
{
printf("\naddress = %u and value = %d",&p->list[i],p->list[i]);
i--;
}
puts("\n\nfrom top2 :");
i=last;
while(i!=size)
{
printf("\naddress = %u and value = %d",&p->list[i],p->list[i]);
i++;
}
}
/*----------------------------------------------------------*/
void main()
{
int a;
s s1;
clrscr();
settop(&s1);
push1(&s1,a);
push1(&s1,a);
push1(&s1,a);
push1(&s1,a);
push2(&s1,a);
push2(&s1,a);
push2(&s1,a);
push2(&s1,a);
display(&s1);
pop1(&s1);
pop1(&s1);
pop2(&s1);
pop2(&s1);
display(&s1);
getch();
}
