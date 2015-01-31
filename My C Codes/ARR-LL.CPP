/*array implementation of linked list :HARSHIT*/
#include"stdio.h"
#include"conio.h"
typedef struct list
{
int data,next;
}node;
node n[5];
int s;
/*------------------------------------*/
void createlist()
{
int i;
for(i=0;i<4;i++)
n[i].next=i+1;
n[4].next=-1;
}
/*-------------------------------------*/
int getnode()
{
int p;
if(s==-1)
return 0;
else
p=s;
s=n[s].next;
printf("\nnode %d is created :",p+1);
return p;
}
/*--------------------------------------*/
void freenode(int q)
{
n[q].next=s;
s=q;
printf("\nnode %d is empty now :",q+1);
}
/*---------------------------------------*/
void main()
{
clrscr();
int a,b,c,d;
createlist();
a=getnode();
printf("\nenter the data in node %d :",a+1);
scanf("%d",&n[a].data);
printf("data in node = %d",n[a].data);
b=getnode();
printf("\nenter the data in node %d :",b+1);
scanf("%d",&n[b].data);
printf("\ndata in node = %d",n[b].data);
puts("\nemptying the nodes now :");
freenode(a);
freenode(b);
getch();
}