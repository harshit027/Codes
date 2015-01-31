//circular linklist:HARSHIT

#include<stdio.h>
#include<conio.h>
struct node
{
int info;
struct node *left,*right;
};
typedef struct node NODE;
NODE *head;
insert_cir(NODE *head)
{
NODE *ptr,*temp;
int item;
ptr=(NODE *)malloc(sizeof(NODE));
printf("Enter the no\n");
scanf("%d",&item);
ptr->info=item;
temp=head->right;
head->right=ptr;
ptr->left=head;
ptr->right=temp;
temp->left=ptr;
return (head);
}
insert_cir_end(NODE *head)
{
NODE *ptr,*temp;
int item;
ptr=(NODE *)malloc(sizeof(NODE));
printf("Enter the no\n");
scanf("%d",&item);
ptr->info=item;
temp=head->left;
temp=head->left;
temp->right=ptr;
ptr->left=temp;
ptr->right=head;
head->left=ptr;
return (head);
}
dele_beg(NODE *head)
{
NODE *temp;
if(head->right==head)
{
printf("Empty list\n");
return;
}
else
{
temp=head->right;
printf("deleted element is =%d\n",temp->info);
head->right=temp->right;
temp->right->left=head;
free(temp);
return (head);
}
}
dele_end(NODE *head)
{
NODE *temp;
if(head->right==head)
{
printf("empty list\n");
return;
}
else
{
temp=head->left;
printf("deleted elementis =%d\n",temp->info);
head->left=temp->left;
free(temp);
return (head);
}
}
void main()
{
int left,right,choice;
clrscr();
do
{
printf("Enter 1: insert at the begining of the link list\n");
printf("Enter 2: insert at the end of the link list\n");
printf("Enter 3: delete at the begining of the link list\n");
printf("Enter 4: delete at the end of the link list\n");
printf("Enter 5: end\n");
printf("Enter your choice\n" );
scanf("%d",&choice);
switch(choice)
{
case 1: insert_cir(head);
	break;
case 2: insert_cir_end(head);
	break;
case 3: dele_beg(head);
	break;
case 4: dele_end(head);
	break;
case 5: return;
}
}while(choice!=5);
getch();
}