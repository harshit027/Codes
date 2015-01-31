/*binary search tree : HARSHIT*/

#include"conio.h"
#include"stdlib.h"
#include"stdio.h"


typedef struct tree
{
int data; int sign;
struct tree *left,*right;
}t;

typedef  struct stack
{
t data[10];
int top;
}s;

t *temp1,*temp2,*root;

/*-----------------------------------------------------------------*/
/*creates the root of the binary search tree */

void createroot(int val)
{
puts("\ncreateroot() called : ");
puts("\nbinary search tree is created :");
puts("\nenter the value in the root :");
scanf("%d",&val);
root=(t*)malloc(sizeof(t));
root->data=val;
root->left=root->right=NULL;
}
/*------------------------------------------------------------------*/
/*adds a node in the tree*/
void addnode(int val)
{
t *p;
puts("\naddnode() called:");
puts("\na new node is added in tree");
puts("\nenter the value to be stored in the node:");
scanf("%d",&val);
temp1=root;
while(temp1!=NULL)
{
p=temp1;
if(val<temp1->data)
temp1=temp1->left;
else
temp1=temp1->right;
}
temp2=(t*)malloc(sizeof(t));
temp2->data=val;
temp2->left=temp2->right=NULL;
if(p->data>temp2->data)
p->left=temp2;
else
p->right=temp2;
}
/*------------------------------------------------------------*/
/*displays the status of tree*/
void display()
{
puts("\nthe status of the tree : ");
temp1=root;
printf("\naddress = %u left = %u data = %d right = %u",temp1,temp1->left,temp1->data,temp1->right);
printf("\n\naddress = %u left = %u data = %d right = %u",temp1->left,temp1->left->left,temp1->left->data,temp1->left->right);
printf("\n\naddress = %u left = %u data = %d right = %u",temp1->right,temp1->right->left,temp1->right->data,temp1->right->right);
}


/*---------------------------------------------------------------*/
/*stack accessing functions */
void settop(s *s1)
{
s1->top=-1;
}
int empty(s *p)
{
if(p->top==-1)
return 1;
else
return 0;
}

void push(s *s1,t *t1)
{
s1->top++;
s1->data[s1->top]=*t1;
}

t *pop(s *s1)
{
t *t1;
t1=&s1->data[s1->top];
s1->top--;
return t1;
}


/*-------------------------------------------------------------*/
/*non recursive in order traversal */
void inorder()
{
puts("\ninorder() called :");
puts("\nthe inorder traversal of tree is :\n");
t *p;
s s1;
settop(&s1);
p=root;
do
{
while(p!=NULL)
{
push(&s1,p);
p=p->left;
}
p=pop(&s1);
printf("-> %d ",p->data);
p=p->right;
}while(!empty(&s1)||p!=NULL);
}

/*-----------------------------------------------------------------*/
/*non recursive preorder traversal*/
void preorder()
{
puts("\npreorder() called :");
puts("\nthe preorder traversal of tree is :\n");
t *p;
s s1;
settop(&s1);
p=root;
do
{
while(p!=NULL)
{
printf("-> %d ",p->data);
push(&s1,p);
p=p->left;
}
p=pop(&s1);
p=p->right;
}while(!empty(&s1)||p!=NULL);
}
/*-------------------------------------------------------*/
void main()
{
clrscr();
int a;
createroot(a);
addnode(a);
addnode(a);
display();
preorder();
inorder();
getch();
}
