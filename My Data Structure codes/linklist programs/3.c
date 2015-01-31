linklist handling :HARSHIT

#include<stdio.h>
#include<conio.h>
int select();
struct rec
{
char name[80];
struct rec *next;
};
struct rec *rear;
struct rec *create(struct rec *list);
struct rec *insert1(struct rec *node);
struct rec *insert2(struct rec *node);
struct rec *insert3(struct rec *node);
struct rec *insert4(struct rec *node);
struct rec *delete(struct rec *node);
void *display(struct rec *list);
int nodes;
main()
{
struct rec *first=NULL;
int choice;
clrscr();
do
{
choice=select();
switch(choice)
{
case 1: first=create(first);continue;
case 2: first=insert1(first);continue;
case 3: first=insert2(first);continue;
case 4: first=insert3(first);continue;
case 5: first=insert4(first);continue;
case 6: first=delete(first);continue;
case 7: display(first);continue;
case 8: puts("END");exit(0);
}
}while(choice!=8);
}
int select()
{
int selection;
do
{
puts("Enter 1: create the list");
puts("Enter 2: insert in the beginnig of the list");
puts("Enter 3: insert after a node in the list");
puts("Enter 4: insert before a node in the list");
puts("Enter 5: insert in the end of the list");
puts("Enter 6: delete the list");
puts("Enter 7: display the list");
puts("Enter 8: END");
puts("Enter your choice");
scanf("%d",&selection);
}while(selection<1||selection>8);
return selection;
}
struct rec *create(struct rec *first)
{
struct rec *element;
first=(struct rec*)malloc(sizeof(struct rec));
puts("Enter/name/word/text: To quit enter*");
scanf(" %[^\n]",first->name);
first->next=first;
rear=first;
rear->next=first;for(;;)
{
element=(struct rec*)malloc(sizeof(struct rec));
scanf(" %[^\n]",element->name);
if(strcmp(element->name,"*")==0)break;
element->next=first;
rear->next=element;
rear= element;
}
return(first);
}
struct rec *insert1(struct rec *first)
{
struct rec *node;
node=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name to be inserted");
scanf(" %[^\n]",node->name);
if(first==NULL)
{
node->next=first;
rear=first;
}
else
{
node->next=first;
first=node;
rear->next=first;
}
return(first);
}
struct rec *insert2(struct rec *first)
{
struct rec *current,*prior,*x;
struct rec *node;current=first;
node=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name after which new node to be inserted");
scanf(" %[^\n]\n",node->name);
x=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name to be inserted");
scanf(" %[^\n]",x->name);
while(current!=rear && current!=NULL)
{
if(strcmp(current->name,node->name)==0)
{
x->next=current->next;
current->next=x;
return(first);
}
else current=current->next;
}
if(strcmp(current->name,node->name)==0)
{
x->next=first;
rear->next=x;
rear=x;
return(first);
}
puts("Node does not exist in the list");
return(first);
}
struct rec *insert3(struct rec *first)
{
struct rec *node,*current,*x,*prior;
current=first;
node=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name before which new node to be inserted");
scanf(" %[^\n]",node->name);
x=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name to be inserted");
scanf(" %[^\n]",x->name);
if(strcmp(current->name,node->name)==0)
{
x->next=first;
first=x;
return(first);
}
while(current!=NULL)
{
prior=current;
current=current->next;
if(strcmp(current->name,node->name)==0)
{
x->next=current;
prior->next=x;
return(first);
}
}
puts("Node does not exist in the list");
return(first);
}
struct rec *insert4(struct rec *first)
{
struct rec *element;
element=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name to be inserted at the end of list");
scanf(" %[^\n]",element->name);
element->next=first;
rear->next=element;
rear=element;
return(first);
}
struct rec *delete(struct rec *first)
{
struct rec *current,*prior,*node;
current=first;
node=(struct rec*)malloc(sizeof(struct rec));
puts("Enter node/name to be delete");
scanf(" %[^\n]",node->name);
if(strcmp(current->name,node->name)==0)
{
first=current->next;
rear->next=first;
free(current);
return(first);
}
while(current!=rear && current!=NULL)
{
prior=current;
current=current->next;
if(strcmp(current->name,node->name)==0)
{
prior->next=current->next;
free(current);
return(first);
}
}
if(strcmp(current->name,node->name)==0)
{
prior->next=current->next;
prior->next=first;
rear=prior;
free(current);
return(first);
}
puts("Node does not exist in the list");
return(first);
}
void *display(struct rec *first)
{
int node=0;
do
{
node++;
printf("%s\n",first->name);
first=first->next;
}
while((first!=rear->next)&&(first!=NULL));
printf("Nuber of nodes= %d\n",node);
}

