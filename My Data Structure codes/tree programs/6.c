#include<stdio.h>
#include<conio.h>
struct rec
{
long num;
struct rec *left;
struct rec *right;
};
struct rec *tree=NULL;
struct rec *insert(struct rec *tree,long num);
void depth(struct rec *tree);
struct rec *temp;
int count=1,total1,total2,dep;
void main()
{
struct rec *tree=NULL;
int choice;
long digit;
do
{
choice=select();
switch(choice)
{
case 1: puts("Enter integers: To quit enter0");
	scanf("%ld",&digit);
	while(digit!=0)
	{
	tree=insert(tree,digit);
	scanf("%ld",&digit);
	}continue;
case 2: depth(tree);
	if(total1>total2)
	  {
	    dep=total1-1;
	    printf("Depth=%d\n",dep);
	  }
	  else
	  dep=total2-1;
	  printf("Depth=%d\n",dep);
	  total1=total2=dep=0;
	  continue;
case 3: puts("END");exit(0);
}
}while(choice!=3);
}
int select()
{
int selection;
do
{
puts("Enter 1: Insert a node");
puts("Enter 2: Display depth");
puts("Enter 3: END");
puts("Eter your choice");
scanf("%d",&selection);
if((selection<1)||(selection>3))
{
puts("Wrong choice: Try again");
getchar();
}
}while((selection<1)||(selection>3));
return selection;
}
struct rec *insert(struct rec *tree,long digit)
{
if(tree==NULL)
{
tree=(struct rec *)malloc(sizeof(struct rec));
tree->left=tree->right=NULL;
tree->num=digit;
}
else
if(count%2==0)
tree->left=insert(tree->left,digit);
else
tree->right=insert(tree->right,digit);
return(tree);
}
void depth(struct rec *tree)
{
if(tree!=NULL)
{
if(tree->left!=NULL)
{
total1++;
depth(tree->left);
}
if(tree->right!=NULL)
{
total2++;
depth(tree->right);
}
}
}
