//polynomial operation :HARSHIT

#include<stdio.h>
#include<conio.h>
#include<limits.h>
int select();
struct rec
{
float coef;
int exp;
struct rec *next;
};
struct rec *rear;
struct rec *create(struct rec *list);
void *add(struct rec *first,struct rec *second);
struct rec *insert(double coef,int exp,struct rec *rear);
void *display(struct rec *list);
int nodes;
void main()
{
struct rec *first=NULL,*second=NULL;
int choice;
do
{
choice=select();
switch(choice)
{
case 1: first=create(first);continue;
case 2: second=create(second);continue;
case 3: add(first,second);continue;
case 4: puts("END");exit(0);
}
}while(choice!=4);
}
int select()
{
int selection;
do
{
puts("Enter 1: create the first list");
puts("Enter 2: create the second list");
puts("Enter 3: add the two list");
puts("Enter 4: END");
puts("Entr your choice");
scanf("%d",&selection);
}while((selection<1)||(selection>4));
return (selection);
}
struct rec *create(struct rec *x)
{
float coef;
int exp;
int endexp=INT_MAX;
struct rec *element;
puts("Enter coefs &exp:exp in descending order:""to quit enter 0 for exp");
x=(struct rec *)malloc(sizeof(struct rec));
x->next=NULL;
rear=x;
for(;;)
{
puts("Enter coefficient");
element=(struct rec*)malloc(sizeof(struct rec));
scanf("%f",&coef);
element->coef=coef;
if(element->coef==0.0)break;
puts("Enter exponent");
scanf("%d",&exp);
element->exp=exp;
if((element->exp<=0)||(element->exp>=endexp))
{
puts("Invalid exponent");
break;
}
element->next=NULL;
rear->next=element;
rear=element;
}
x=x->next;
return(x);
}
void *add(struct rec *first,struct rec *second)
{
float total;
struct rec *end,*rear,*result;
result=(struct rec *)malloc(sizeof(struct rec));
rear=end;
while((first!=NULL)&&(second!=NULL))
{
if(first->exp==second->exp)
{
if((total=first->exp+second->exp)!=0.0)
rear=insert(total,first->exp,rear);
first=first->next;
second=second->next;
}
else
if(first->exp>second->exp)
{
rear=insert(first->coef,first->exp,rear);
first=first->next;
}else
{
rear=insert(second->coef,second->exp,rear);
second=second->next;
}
}
for(;first;first=first->next)
rear=insert(first->coef,first->exp,rear);
for(;second;second=second->next)
rear=insert(second->coef,second->exp,rear);
rear->next=NULL;
display(end->next);
free(end);
}
void *display(struct rec *head)
{
while(head!=NULL)
{
printf("%2lf",head->coef);
printf("%2d",head->exp);
head=head->next;
}
printf("\n");
}
struct rec *insert(double coef,int exp,struct rec *rear)
{
rear->next=(struct rec *)malloc(sizeof(struct rec));
rear=rear->next;
rear->coef=coef;
rear->exp=exp;
return(rear);
}










