//fibonacci series:HARSHIT

#include<stdio.h>
# include<conio.h>
void main()
{
int a[100],i,n;
clrscr();
printf("Enter the no. of elements in the series :\n ");
scanf("%d",&n);
a[0]=0;
a[1]=1;
for(i=2;i<=n-1;i++)
 {
  a[i] = a[i-2] + a[i-1];
 }
printf("Fibonacci Series is : \n");
  for(i=0;i<=n-1;i++)
   {
    printf("%d\n",a[i]);
   }
getch();
}
