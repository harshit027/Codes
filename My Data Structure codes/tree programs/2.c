/*searching of tree:HARSHIT*/

#include<stdio.h>
#include"conio.h"
struct rec
{
	long num;
	struct rec *left;
	struct rec *right;
};
struct rec *tree=NULL;
struct rec *tree;
struct rec *delnum(long digit,struct rec *r);
struct rec *insert(struct rec *tree,long num);
struct rec *deletenode(long digit,struct rec *tree);
void search(struct rec *tree,long num);
void preorder(struct rec *tree);
void inorder(struct rec *tree);
void postorder(struct rec *tree);
void main()
{
int choice;
long digit;
int element;
	do
	  {
		choice=select();
		switch(choice)
		 {
		   case 1: puts("Enter integer: To quit enter 0");
			   scanf("%ld",&digit);
			   while(digit!=0)
				{
				   tree=insert(tree,digit);
				   scanf("%ld",&digit);
				}continue;
		   case 2: puts("Enter the number to be search");
			   scanf("%ld",&digit);
			   search(tree,digit);
			   continue;
		   case 3: puts("\npreorder traversing TREE");
			   preorder(tree);continue;
		   case 4: puts("\ninorder traversing TREEE");
			   inorder(tree);continue;
		   case 5: puts("\npostorder traversing TREE");
			   postorder(tree);continue;
		   case 6: puts("Enter element which do you wanbt delete from  the BST");
			    scanf("%ld",&digit);
			   deletenode(digit,tree);continue;
		   case 7: puts("END");exit(0);
		}
	}while(choice!=7);
}
int select()
{
int selection;
	do
	  {
		puts("Enter 1: Insert a node in the BST");
		puts("Enter 2: Search a node in BST");
		puts("Enter 3: Display(preorder)the BST");
		puts("Enter 4: Display(inorder)the BST");
		puts("Enter 5: Display(postorder) the BST");
		puts("Enter 6: Delete the element");
		puts("Enter 7: END");
		puts("Enter your choice");
		scanf("%d",&selection);
		     if((selection<1)||(selection>7))
			{
			  puts("wrong choice:Try again");
			  getch(); }
	   }while((selection<1)||(selection>7));
	   return (selection);
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
     else
	  if(digit>tree->num)
		tree->right=insert(tree->right,digit);
     else if(digit==tree->num)
	    {
	       puts("Duplicate node:program exited");exit(0);
	    }
	    return(tree);
}
struct rec *delnum(long digit,struct rec *r)
{
struct rec *q;
if(r->right!=NULL)delnum(digit,r->right);
else
q->num=r->num;
q=r;
r=r->left;
}
struct rec *deletenode(long digit,struct rec *tree)
{
struct rec *r,*q;
if(tree==NULL)
{
puts("Tree is empty.");
exit(0);
}
if(digit<tree->num)
deletenode(digit,tree->left);
else
if(digit>tree->num)deletenode(digit,tree->right);
q=tree;
if((q->right==NULL)&&(q->left==NULL))
q=NULL;
else
if(q->right==NULL)tree=q->left;else
if(q->left==NULL)tree=tree=q->right;else
delnum(digit,q->left);
free(q);
}
void search(struct rec *tree,long digit)
{
	if(tree==NULL)
	   puts("The number does not exits\n");
   else
	if(digit==tree->num)
	printf("Number=%ld\n" ,digit);
   else
	if(digit<tree->num)
	   search(tree->left,digit);
   else
	  search(tree->right,digit);
}
void preorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		printf("%12ld\n",tree->num);
		preorder(tree->left);
		preorder(tree->right);
	  }
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
void postorder(struct rec *tree)
{
	if(tree!=NULL)
	  {
		postorder(tree->left);
		postorder(tree->right);
		printf("%12ld\n",tree->num);
	  }

}
