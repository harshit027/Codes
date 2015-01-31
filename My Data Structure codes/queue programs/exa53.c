//circular queue :HARSHIT

#include<stdio.h>
#include<conio.h>
#define MAXSIZE 5
int cq[10];
int front=-1,rear=0;
int choice;
char ch;
void main()
{
clrscr();
do
{


	     printf("--------1.Insert-------\n");
	     printf("------- 2. Delete--------\n");
	     printf("------- 3. Display--------\n");
	     printf("-------4.exit------------\n");
	     printf("Enter your choice\n");
	     scanf("%d",&choice);
switch(choice)
{
case 1 : cqinsert();
break;
case 2 : cqdelete();
break;
case 3 : cqdisplay();
break;
case 4: return;
}
	    fflush(stdin);
	    }
	   while(choice!=4);
		   }
cqinsert()
{
       int num;
       if(front==(rear+1)%MAXSIZE)
	 {
	  printf("Queue is full\n");
	  return;
	 }
else
	   {
	     printf("Enter the element to be inserted\n");
	     scanf("%d",&num);
		if(front==-1)
		     front=rear=0;
		else

		     rear=(rear+1) % MAXSIZE;
		     cq[rear]= num;

	   }
  return;
}
int cqdelete()
{
int num;
       if(front==-1)
	  {
	 .
	     printf("Queue is Empty\n");
	     return;
	  }
  else
       {
	  num=cq[front];
	  printf("Deleted element is =%d\n",cq[front]);

	     if(front==rear)
		 front=rear=-1;
		 else
		   front=(front+1)%MAXSIZE;
       }
	 return(num);

}
 cqdisplay()
{
int i;
if(front==-1)
{
printf("Queue is empty\n");
return;
}
else
{
printf("\nThe status of the queue\n");
for(i=front;i<=rear;i++)
{
printf("%d\n",cq[i]);
}
}
if(front>rear)
{
	for(i=front;i<MAXSIZE;i++)
	{
	printf("%d\n",cq[i]);
	}
	for(i=0;i<=rear;i++)
	{
	printf("%d\n",cq[i]);
	}
}
printf("\n");
}





















































































