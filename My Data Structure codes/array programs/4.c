//delete a desired element in array:HARSHIT

#include<stdio.h>
#include<conio.h>
int i,n;
main()
{
int a[100],pos;
void delete(int a[],int,int);
clrscr();
printf("How many elements in the array\n");
scanf("%d",&n);
printf("Enter the element of the array\n");
for(i=0;i<=n-1;i++)
scanf("%d",&a[i]);
printf("On which postion element do you want delete\n");
scanf("%d",&pos);
delete(a,pos,n);
getch();
}
void delete(int a[],int pos,int n)
{
int j,item;
item=a[pos];
for(j=pos;j<=n-1;j++)
{
a[j]=a[j+1];
}
n=n-1;
for(i=0;i<=n-1;i++)
printf("%d\n",a[i]);
}

