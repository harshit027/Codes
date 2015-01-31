//linked list handling:HARSHIT

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void main()
{
struct node
{
int num;
struct node *ptr;
};
typedef struct node NODE;
NODE *head, *first, *temp;
int count=0;
int choice=1;
first=NULL;
while(choice)
{
	head=(NODE *)malloc(sizeof(NODE));
	printf("Enter the data item\n");
	scanf("%d",&head->num);
	  if(first!=NULL)
		{
		  temp->ptr=head;
		  temp=head;
		}
else
		{
		  first=temp=head;
		}
fflush(stdin);
printf("Do you want to continue(type 0 or 1)?\n");
scanf("%d",&choice);
}

temp->ptr=NULL;
temp=first;
printf("Status of the linked list is\n");
while(temp!=NULL)
	{
		printf("%d",temp->num);
		count++;
		temp=temp->ptr;
	}
printf("NULL");
printf("NO of nodes in the list =%d\n",count);
getch();
}