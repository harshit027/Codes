//linklist handling :HARSHIT

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
int info;
struct node *next;
};
typedef struct node NODE;
NODE *start;
void createmptylist(NODE **start)
{
*start=(NODE *)NULL;
}
void traversinorder(NODE *start)
{
while(start != (NODE *) NULL)
{
printf("%d\n",start->info);
start=start->next;
}
}
void insertatbegin(int item)
{
NODE *ptr;
ptr=(NODE *)malloc(sizeof(NODE));
ptr->info=item;
if(start==(NODE *)NULL)
ptr->next=(NODE *)NULL;
else
ptr->next=start;
start=ptr;
}
void insert_at_end(int item)
{
NODE *ptr,*loc;
ptr=(NODE *)malloc(sizeof(NODE));
ptr->info=item;
ptr->next=(NODE *)NULL;
if(start==(NODE*)NULL)
start=ptr;
else
{
loc=start;
while(loc->next!=(NODE *)NULL)
loc=loc->next;
loc->next=ptr;
}
}
void insert_spe(NODE *start,int item)
{
NODE *ptr,*loc;
int temp,k;
for(k=0,loc=start;k<temp;k++)
{
loc=loc->next;
if(loc==NULL)
{
printf("node in the list at less than one\n");
return;
}
}
ptr=(NODE *)malloc(sizeof(NODE));
ptr->info=item;
ptr->next=loc->next;;
loc->next=ptr;
}
void main()
{
int choice,item,after;
char ch;
clrscr();
createmptylist(start);
do
{
printf("1.Insert element at begin \n");
printf("2. insert element at end positon\n");
printf("3. insert specific the position\n");
printf("4.travers the list in order\n");
printf("5. exit\n");
printf("enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("Enter the item\n");
	scanf("%d",&item);
	insertatbegin(item);
	break;
case 2:  printf("Enter the item\n");
	scanf("%d",&item);
	insert_at_end(item);
	break;
case 3: printf("Enter the item\n");
	scanf("%d",&item);
	insert_spe(start,item);
	break;
case 4: printf("\ntravers the list\n");
	traversinorder(start);
	break;
case 5: return;
}
fflush(stdin);
printf("do your want continous\n");
scanf("%c",&ch);
}while((ch='y')||(ch='y'));
getch();
}



