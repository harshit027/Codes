/*creation of linked list and operations on it :HARSHIT*/

#include"header.h"


typedef struct linkedlist
{
int data;
struct linkedlist *next;
}node;
node *first,*temp1,*temp2;

/*------------------------------------------------*/
/*list of functions :*/
/*-----------------------------------------------*/
void display();
/*creates the linked list*/
void createlist()
{
clrscr();
int val;
puts("\n createfirst() called :");
puts("\nlist is created :");
puts("\nenter the value to be stored in the first node :");
scanf("%d",&val);
first=(node*)malloc(sizeof(node));
first->next=NULL;
first->data=val;
display();
}

/*-----------------------------------------------*/
/*adds a node in the list*/
void addnode()
{
clrscr();
int val;
puts("\naddnode() called :");
puts("\na node is added in the list :");
puts("\nenter the value to be stored : ");
scanf("%d",&val);
temp1=first;
while(temp1->next!=NULL)
temp1=temp1->next;
temp2=(node*)malloc(sizeof(node));
temp2->next=NULL;
temp2->data=val;
temp1->next=temp2;
display();
}

/*---------------------------------------------------*/
/*insert a node at the head*/
void inserthead()
{
clrscr();
int val;
puts("\ninserthead() called :");
puts("\n a new node is inserted at head :");
puts("\nenter the value to be stored in newly added node : ");
scanf("%d",&val);
node *p;
p=(node*)malloc(sizeof(node));
p->data=val;
p->next=first;
first=p;
puts("\nstatus of linklist after the insertion of node : ");
display();
}

/*----------------------------------------------------*/
/*insert a node at tail*/
void inserttail()
{
clrscr();
int val;
puts("\ninserttail() called :");
puts("\na new node is inserted at tail : ");
puts("\nenter the value to be stored in newly added node :");
scanf("%d",&val);
temp1=first;
while(temp1->next!=NULL)
temp1=temp1->next;
node *p;
p=(node*)malloc(sizeof(node));
p->data=val;
p->next=NULL;
temp1->next=p;
puts("\nstatus of linked list after insertion of node :");
display();
}

/*-----------------------------------------------------*/
/*adds a node after a node */
void addafter()
{
clrscr();
int val1,val2;
puts("\naddafter() called :");
node *p;
puts("\nenter the value after which node is to be added :");
scanf("%d",&val1);
printf("\na new node has been added at after %d :",val1);
puts("\nenter the value to be stored in newly added node :");
scanf("%d",&val2);
temp1=first;
while(temp1->data!=val1)
temp1=temp1->next;
p=(node*)malloc(sizeof(node));
p->data=val2;
p->next=temp1->next;
temp1->next=p;
puts("\nstatus of linked list after node is added :");
display();
}

/*---------------------------------------------------*/
/*adds a node before a node */
void addbefore()
{
clrscr();
int val1,val2;
puts("\naddbefore() called :");
node *p;
puts("\nenter the value before which the node is to be added :");
scanf("%d",&val1);
printf("a new node has been added before %d :",val1);
puts("\nenter the value to be stored in newly added node :");
scanf("%d",&val2);
temp1=first;
while(temp1->data!=val1)
{
temp2=temp1;
temp1=temp1->next;
}
p=(node*)malloc(sizeof(node));
p->data=val2;
p->next=temp2->next;
temp2->next=p;
puts("\nstatus of linked list after node is added :");
display();
}

/*-----------------------------------------------*/
/*deletes a node after a node */
void delafter()
{
clrscr();
int val;
puts("\ndelafter() called :");
int x;
node *p;
puts("\nenter the value after which node is to be deleted :");
scanf("%d",&val);
puts("\nif you surely want to delete the node, enter 1, else anything:");
scanf("%d",&x);
if(x==1)
{
printf("\nthe node after %d is deleted :",val);
temp1=first;
while(temp1->data!=val)
temp1=temp1->next;
p=temp1->next;
temp1->next=p->next;
p->next=NULL;
free(p);
display();
}
else
{
display();
return ;
}
}

/*-------------------------------------------------*/
/*deletes a node before a node */
void delbefore()
{
clrscr();
int val;
puts("\ndelbefore() called :");
int x;
puts("\nenter the value before which the node is to be deleted :");
scanf("%d",&val);
puts("\nif you surely want to delete the node, enter 1, else anything:");
scanf("%d",&x);
if(x==1)
{
printf("\nthe node before %d is deleted : ",val);
temp1=first;
while(temp1->next->data!=val)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp1->next;
temp1->next=NULL;
free(temp1);
display();
}
else
{
display();
return ;
}}

/*-------------------------------------------------*/
/*deletes a node from head */
void delhead()
{
clrscr();
puts("\ndelhead() called :");
int x;
puts("\nif you surely want to delete the first node, enter 1, else anything:");
scanf("%d",&x);
if(x==1)
{
if(first==NULL)
puts("\nthe list is already empty :");
else
{
puts("\na node from the head is deleted :");
temp1=first;
temp2=temp1->next;
first=temp2;
temp1->next=NULL;
free(temp1);
display();
}}
else
{
display();
return ;
}}

/*-----------------------------------------------*/
/*deletes a node from tail*/
void deltail()
{
clrscr();
puts("\deltail() called :");
int x;
puts("\nif you surely want to delete the last node, enter 1, else anything:");
scanf("%d",&x);
if(x==1)
{
if(first==NULL)
puts("\nthe list is already empty :");
else
{
puts("\na node is deleted from the tail :");
temp1=first;
while(temp1->next!=NULL)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=NULL;
temp1=NULL;
free(temp1);
display();
}}
else
{
display();
return ;
}}

/*-------------------------------------------------*/
/*swaps the last and second last node */
void swaplasttwo()

{
clrscr();
puts("\nswaplasttwo() called :");
puts("\nthe last and second last nodes are swapped :");
temp1=first;
while(temp1->next->next!=NULL)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp1->next;
temp1->next->next=temp1;
temp1->next=NULL;
puts("\nstatus of the list after swapping :");
display();
}

/*------------------------------------------------*/
/*adds the data in all the nodes in the list */
void adddata()
{
clrscr();
puts("\nadddata() called :");
temp1=first;
while(temp1!=NULL)
{
temp1->next->data=temp1->data+temp1->next->data;
temp1=temp1->next;
}
printf("\nthe sum of data of nodes = %d",temp1->next->data);
}

/*------------------------------------------------*/
/*swaps the mth and nth node*/
void swapmn()
{
clrscr();
int m,n;
puts("\nswapmn() called :");
int i;
node *p,*q,*p1,*q1,*p2,*q2;
puts("\nenter the index of nodes to be interchanged :");
puts("NOTE : not for consecutive indexes !");
scanf("%d%d",&m,&n);
printf("\nthe nodes %d and %d are interchanged : ",m,n);
temp1=first;
for(i=1;i<m;i++)
{
p=temp1;
temp1=temp1->next;
p1=temp1;
}
temp1=first;
for(i=1;i<n;i++)
{
q=temp1;
temp1=temp1->next;
q1=temp1;
}
p2=p1->next;
q2=q1->next;
p->next=q1;
p1->next=q2;
q->next=p1;
q1->next=p2;
puts("\nstatus of list after swapping :");
display();
}

/*-------------------------------------------------------------*/
/*adds a node after a node w.r.t index */
void addafteri()
{
clrscr();
int val,m;
node *p;
puts("enter the index after which the node is to be added :");
scanf("%d",&m);
printf("\na node is added after %d :",m);
temp1=first;
for(int i=1;i<m;i++)
{
temp1=temp1->next;
}
p=(node*)malloc(sizeof(node));
puts("\nenter the value ot be stored in the new node :");
scanf("%d",&val);
p->data=val;
p->next=temp1->next;
temp1->next=p;
display();
}
/*---------------------------------------------------------------*/
/*adds a node before any node*/
void addbeforei()
{
clrscr();
int val,m;
node *p;
puts("enter the index before which the node is to be added :");
scanf("%d",&m);
printf("\na node is added before %d :",m);
temp1=first;
for(int i=1;i<m-1;i++)
{
temp1=temp1->next;
}
p=(node*)malloc(sizeof(node));
puts("\nenter the value ot be stored in the new node :");
scanf("%d",&val);
p->data=val;
p->next=temp1->next;
temp1->next=p;
display();
}

/*-----------------------------------------------*/
/*displays the status of list */
void display()
{
clrscr();
int i=1;
temp1=first;
puts("\nthe entered linked list is : \n");
puts("\n====================================");
while(temp1!=NULL)

{
printf("\n node %d : data = %d",i,temp1->data);
printf(" and link = %d",temp1->next);
temp1=temp1->next;
i++;
}
puts("\n\n------------------------------------");
printf("\nnumber of nodes : %d",i-1);
puts("\n====================================");
}
/*-------------------------------------------------------------------*/

void menu()
{
clrscr();
setbkcolor(1);
int i;char choice;
puts("============================MENU=========================");
puts("1 : Createlist           \t2 : Addnode              ");
puts("3 : Inserthead           \t4 : Inserttail           ");
puts("5 : Addafter value       \t6 : Addbefore value      ");
puts("7 : Delete after value   \t8 : Delete before value  ");
puts("9 : Delete head          \t10: Delete tail          ");
puts("11: Swaplasttwo          \t12: Swapmn               ");
puts("13: Add data             \t14: Addafter node        ");
puts("15: Addbefore node       \t16: Display              ");
puts("17: Exit                 \t                         ");
puts("=========================================================\n");
puts("\n\nenter a choice from the menu (1-17) : ");
scanf("%d",&i);
switch(i)
{
case 1: createlist();
break;
case 2: addnode();
break;
case 3: inserthead();
break;
case 4: inserttail();
break;
case 5: addafter();
break;
case 6: addbefore();
break;
case 7: delafter();
break;
case 8: delbefore();
break;
case 9: delhead();
break;
case 10:deltail();
break;
case 11:swaplasttwo();
break;
case 12:swapmn();
break;
case 13:adddata();
break;
case 14:addafteri();
break;
case 15:addbeforei();
break;
case 16:display();
break;
case 17:puts("\nThankyou !\nPrepared by Harshit Tiwari !");
return;
}
puts("\nstill want to continue (y or n) :");
cin>>choice;
if(choice=='y')
menu();
if(choice=='n')
{
puts("\nThankyou !\nPrepared by Harshit Tiwari !");
return;
}}


/*---------------------------------------------------*/
void main()
{
int driver,mode;
driver=DETECT;
initgraph(&driver,&mode,"");
clrscr();
menu();
getch();
closegraph();
}
/*---------------------------------------------------*/

