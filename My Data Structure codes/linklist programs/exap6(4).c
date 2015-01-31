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

void dele_beg(void)
{
NODE *ptr;
if(start==(NODE *)NULL)
return;
else
{
ptr=start;
start=(start)->next;
free(ptr);
}
}
void dele_end(NODE *start)
{
NODE *ptr,*loc;
if(start==(NODE *)NULL)
return;
else if((start)->next==(NODE *)NULL)
{
ptr=start;
start=(NODE *)NULL;
free(ptr);
}
else
{
loc=start;
ptr=(start)->next;
while(ptr->next!=(NODE *)NULL)
{
loc=ptr;
ptr=ptr->next;
}
loc->next=(NODE *)NULL;
free(ptr);
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
dele_spe(NODE *start)
{
NODE *ptr,*loc;
int temp;
printf("\nEnter the which element do you want to delete\n");
scanf("%d",&temp);
ptr=start;
if(start==NULL)
{
printf("Empty list\n");
return;
}
else
{
loc=ptr;
while(ptr!=NULL)
{
if(ptr->info==temp)
{
loc->next=ptr->next;
free(ptr);
return;
}
loc=ptr;
ptr=ptr->next;
}
}
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
printf("5. delete from the begin\n");
printf("6. delete from the last\n");
printf("7. delete the element from the specific position\n");
printf("8. exit\n");
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
case 5: printf("Delete the item\n");
	dele_beg();
	break;
case 6: printf("Delete the element\n");
	dele_end(start);
	break;
case 7: printf("Delete the element");
	dele_spe(start);
	break;
case 8: return;
}
fflush(stdin);
printf("do your want continous\n");
scanf("%c",&ch);
}while((ch='y')||(ch='y'));
getch();
}












