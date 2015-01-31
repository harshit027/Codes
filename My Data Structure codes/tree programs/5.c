//binary search tree:HARSHIT

#include<stdio.h>
#include<conio.h>
struct rec
{
long num;
struct rec *left;
struct rec *right;
};
struct rec *tree,*second,*head;
struct rec *insert(struct rec *tree,long num);
struct rec *copy(struct rec *tree);
void inorder(struct rec *tree);
main()
{
int choice;
long digit;
do
{
choice=select();
switch(choice)
{
case 1:puts("Enter integers:To quit enter 0");
	scanf("%ld",&digit);
	while(digit!=0)
	{
	tree=insert(tree,digit);
	scanf("%ld",&digit);
	}continue;
case 2: copy(tree);continue;
case 3: puts("Inorder traversing TREE");
	inorder(tree);continue;
case 4: puts("END");exit(0);
}
}while(choice!=4);
}
int select()
{
int selection;
do
{
puts("Enter 1: Insert a node in the BST");
puts("Enter 2: Copy a tree to another BST");
puts("Enter 3: Display(inorder)the BST");
puts("Enter 4: END");
puts("Enter your choice");
scanf("%d",&selection);
if((selection<1)||(selection>4))
{puts("Wrong choice: Try again");
getchar();
}
}while((selection<1)||(selection>4));
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
if(digit<tree->num)
tree->left=insert(tree->left,digit);
else if(digit>tree->num)
tree->right=insert(tree->right,digit);
else if(digit==tree->num)
{puts("Duplicate nodes: program exited");exit(0);
}
return(tree);
}
struct rec *copy(struct rec *tree)
{
second=(struct rec *)malloc(sizeof(struct rec));
head=second;
if(tree!=NULL)
{
second->num=tree->num;
if(tree->left!=NULL)
{
second->left->num=tree->left->num;
copy(tree->right);
}
if(tree->right!=NULL)
{
second->right->num=tree->num;
copy(tree->left);
}
}
return(head);
}
void inorder(struct rec *tree)
{
if(tree!=NULL)
{
inorder(tree->left);
printf("%12ld\n",tree->num);
inorder(tree->right);
}
}
