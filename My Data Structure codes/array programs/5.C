//traversing an array:HARSHIT

#include<stdio.h>
#include<conio.h>
void main()
{
int n,x,i,a[100];
clrscr();
printf("Enter the length of the array");
scanf("%d",&n);
   for(i=0;i<=n;i++)
      scanf("%d",&a[i]);
printf("Traversing of the array\n");
  for(i=0;i<=n;i++)
     printf("%d\n",a[i]);
getch();
}
