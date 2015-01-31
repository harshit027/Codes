//bubble sort :HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int a[100],n,k,i,j,temp;
clrscr();
printf("How many elements\n");
scanf("%d",&n);
printf("Enter the element of array");
for(i=0;i<=n-1;i++)
{
scanf("%d",&a[i]);
}
for(k=1;k<=n-1;k++)
{
temp=a[k];
j=k-1;
while((temp<a[j])&&(j>=0))
{
a[j+1]=a[j];
j=j-1;
}
a[j+1]=temp;
}
printf("Element of array after sorting\n");
for(i=0;i<=n-1;i++)
{
printf("%d\n",a[i]);
}
getch();
}
