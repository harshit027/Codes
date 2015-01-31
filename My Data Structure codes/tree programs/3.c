//tree handling :HARSHIT

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
void countnode(struct rec *tree);
void countleave(struct rec *tree);
struct rec *temp;
int node=1,total;
 main()
{
	struct rec *tree=NULL;
	int choice;
	long digit;
	do
	  {
	    choice=select();
	    switch(choice)
		{
		  case 1: puts("Enter integers:To quit enter 0");
			  scanf("%ld",&digit);
			  while(digit!=0)
			       {
				 tree=insert(tree,digit);
				 scanf("%ld",&digit);
				}continue;
		  case 2: countnode(tree);
			  printf("Nuber of nodes=%d\n",node);
			  node=1;continue;
		  case 3: countleave(tree);
			  printf("Nuber of leaves=%d\n",total);
			  total=0;
			  continue;
		  case 4: puts("END");exit(0);
		 }
	  }while(choice!=4);
}
   int select()
      {
       int selection;
       do
	 {
	   puts("Enter 1: Insert a node");
	   puts("Enter 2: Display number of nodes");
	   puts("Enter 3: Display number of leave");
	   puts("Enter 4: End");
	   puts("Enter your choice");
	   scanf("%d",&selection);
	   if((selection<1)||(selection>4))
	     {
	       puts("Wrong choice: Try again");
	       getchar();
	     }
	 }while((selection<1)||(selection>4));
		return selection;
	}
struct rec *insert(struct rec *tree,long digit)
{
  if(tree==NULL)
    {
       tree=(struct rec *)malloc(sizeof(struct rec ));
       tree->left=tree->right=NULL;
       tree->num=digit;
     }
else
   if(digit<tree->num)
      tree->left=insert(tree->left,digit);
else
   if(digit>tree->num)
     tree->right=insert(tree->right,digit);
else
    if(digit==tree->num)
      {
       puts("Duplicates Nodes:Program Exited");
       exit(0);
      }
return(tree);
}
void countnode(struct rec *tree)
{
    if(tree!=NULL)
      {
      if(tree->left!=NULL)
	{
	  node++;
	  countnode(tree->left);
	 }
      if(tree->right!=NULL)
	{
	  node++;
	  countnode(tree->right);
	}
       }
}
void countleave(struct rec *tree)
{
   if(tree!=NULL)
     {
      if((tree->left==NULL)&&(tree->right==NULL))
	 total++;
 else
   countleave(tree->left);
   countleave(tree->right);
     }
}
