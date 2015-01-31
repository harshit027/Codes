#include<stdio.h>
#include<conio.h>
int table(int, int);
void main()
{
int i,n;
clrscr();
printf("Enter any integer");
scanf("%d",&n);
for(i=1;i<=10;i++)
printf("%d x %d = %d \n",n,i,table(n,i));
getch();
}
int table(int n, int i)
{
 if(i==1)
  {
    return(n);
    }
 else
  {
    return(table(n,i-1)+n);
    }
}
