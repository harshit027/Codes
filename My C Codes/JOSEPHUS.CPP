/*solution to josephus problem: HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"

typedef struct soldier_list
{
char name[10];
int num;
struct soldier_list *next;
}soldier;
/*pointers declared of type soldier_list*/
soldier *first,*temp1,*temp2;
/*----------------------------------------------------------------------*/
/*creates a circular linklist*/
void createlist(int x,char n[])
{
puts("\n a circular list is created,enter the data in the first node :");
puts("\nentre the name of the soldier :");
scanf("%s",n);
puts("\nenter the index number of the soldier:");
scanf("%d",&x);
first=(soldier*)malloc(sizeof(soldier));
strcpy(first->name,n);
first->num=x;
first->next=first;
}
/*------------------------------------------------------------*/
/*adds a node in the list*/
void addnode(int x, char n[])
{
temp1=first;
puts("\na node is added in the list :");
puts("\nenter the name of soldier :");
scanf("%s",n);
puts("\nenter the index number of the soldier :");
scanf("%d",&x);
while(temp1->next!=first)
temp1=temp1->next;
temp2=(soldier*)malloc(sizeof(soldier));
strcpy(temp2->name,n);
temp2->num=x;
temp1->next=temp2;
temp2->next=first;
}
/*-------------------------------------------------------------*/
/*josephus problem's solution*/
int count()
{
int c=1;
temp1=first;
while(temp1->next!=first)
{
temp1=temp1->next;
c++;
}
return c;
}

void  josephus()
{
char name[10];
int number,n,i;
puts("\nenter the name of the soldier to be chosen :");
scanf("%s",name);
puts("\nenter the number of counts :");
scanf("%d",&number);
n=count();
temp1=first;
while(strcmp(temp1->name,name)!=0)
temp1=temp1->next;
while(n>1)
{
i=1;
while(i<number-1)
{
temp1=temp1->next;
i++;
}
temp2=temp1->next;
temp1->next=temp2->next;
temp2->next=NULL;
free(temp2);
temp1=temp1->next;
n--;
}
puts("\nthe soldier who will escape is : " );
printf("\n%u  %d : name of soldier  %s",temp1,temp1->num,temp1->name);
}

/*----------------------------------------------*/
/*displays the list of soldiers */
void display()
{
int i=1;
temp1=first;
puts("\nthe list you entered is :");
while(temp1->next!=first)
{
printf("\n%u  %d : name of soldier = %s ",temp1,temp1->num,temp1->name);
printf("  ,next = %u",temp1->next);
temp1=temp1->next;
i++;
}
printf("\n%u  %d : name of soldier = %s ",temp1,temp1->num,temp1->name);
printf("  ,next = %u",temp1->next);
printf("\nnumber of soldiers : %d",i);
}

/*-------------------------------------------------------------------*/
void main()
{
int a,i; char n[10];
clrscr();
createlist(a,n);
for(i=1;i<10;i++)
addnode(a,n);
display();
josephus();
getch();
}