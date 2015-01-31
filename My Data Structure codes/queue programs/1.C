//queue handling using array: HARSHIT

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
int front=-1, rear=-1,choice;
int q[10];
void main()
{
clrscr();
do
{
printf("\n1-->insert\n");
printf("2-->delete\n");
printf("3-->display\n");
printf("4-->exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:qinsert();
      break;
case 2:qdelete();
       break;
case 3:qdisplay();
       break;
case 4:return;
}
}
while(choice!=4);
}
 qinsert()
{
int num;
if(rear==(MAXSIZE-1))
{
printf("queue is full\n");
return;
}
else
{
printf("enter no\n");
scanf("%d",&num);
rear=rear+1;
q[rear]=num;
if(front==-1)
{
 front++;
 }
 }
 return;
 }
qdelete()
{
int num;
if(front==-1)
{
printf("queue empty\n");
return;
}
else
{
if(front==rear)
front=rear=-1;
else
{
num=q[front];
printf("deleted item=%d",q[front]);
front++;
}
}
return(num);
}
qdisplay()
{
int i;
if(front==-1)
{
printf("queue empty\n");
return;
}
else
{
printf("\nThe status of the queu\n");
for(i=front;i<=rear;i++)
{
printf("%d\n",q[i]);
}
}
printf("\n");
}
