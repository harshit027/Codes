//queue handling using linkedlist: HARSHIT


#include<stdio.h>
#include<conio.h>
struct queue
{
int no;
struct queue *next;
}
*start=NULL;
void add();
int del();
void traverse();
void main()
{
int ch;
char choice;
do
{
clrscr();
printf("----1. add\n");
printf("----2. delete\n");
printf("----3. traverse\n");
printf("----4. exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: add();
break;
case 2: printf("the delete element is\n%d",del());
break;
case 3: traverse();
break;
case 4: return;
default : printf("wrong choice\n");
};
fflush(stdin);
scanf("%c",&choice);
}
while(choice!=4);
}
void add()
{
struct queue *p,*temp;
temp=start;
p=(struct queue*)malloc(sizeof(struct queue));
printf("Enter the data");
scanf("%d",&p->no);
p->next=NULL;
if(start==NULL)
{
start=p;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=p;
}
}
int del()
{
struct queue *temp;
int value;
if(start==NULL)
{
printf("queue is empty");
getch();
return(0);
}
else
{
temp=start;
value=temp->no;
start=start->next;
free(temp);
}
return(value);
}
void traverse()
{
struct queue *temp;
temp=start;
while(temp->next!=NULL)
{
printf("no=%d",temp->no);
temp=temp->next;
}
printf("no=%d",temp->no);
getch();
}
