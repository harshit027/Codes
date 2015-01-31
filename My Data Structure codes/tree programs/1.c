/*traversing of tree:HARSHIT*/


#include<stdio.h>
struct rec
{
	long num;
	struct rec *left;
	struct rec *right;
};
struct rec *tree=NULL;
struct rec *insert(struct rec *tree,long num);
void preorder(struct rec *tree);
void inorder(struct rec *tree);
void postorder(struct rec *tree);
int count=1;
main()
{
	int choice;
	long digit;
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
		case 2: puts("\npreorder traversing TREE");
			preorder(tree);continue;
		case 3: puts("\ninorder traversing TREEE");
			inorder(tree);continue;
		case 4: puts("\npostorder traversing TREE");
			postorder(tree);continue;
		case 5: puts("END");exit(0);
		}
	}while(choice!=5);
}
int select()
{
int selection;
	do
	  {
		puts("Enter 1: Insert a node in the BT");
		puts("Enter 2: Display(preorder)the BT");
		puts("Enter 3: Display(inorder)the BT");
		puts("Enter 4: Display(postorder)the BT");
		puts("Enter 5: END");
		puts("Enter your choice");
		scanf("%d",&selection);
		     if((selection<1)||(selection>5))
			{
			  puts("wrong choice:Try again");
			  getch(); }
	   }while((selection<1)||(selection>5));
	   return (selection);
}
struct rec *insert(struct rec *tree,long digit)
{
	if(tree==NULL)
	  {
		tree=(struct rec *)malloc(sizeof(struct rec));
		tree->left=tree->right=NULL;
		tree->num=digit;count++;
	  }
else
	if(count%2==0)
	tree->left=insert(tree->left,digit);
else
	tree->right=insert(tree->right,digit);
	return(tree);
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
