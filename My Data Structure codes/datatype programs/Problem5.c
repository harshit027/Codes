#include<stdio.h>
#include<conio.h>
int power(int,int);
void main()
{
 int n,p,result;
 clrscr();
 printf("Enter the number");
 scanf("%d",&n);
 printf("\nEnter the power to be calculated");
 scanf("%d",&p);
 result=power(n,p);
 printf("The result of %d to power %d is %d",n,p,result);
 getch();
 }
int power(int n,int p)
{
 static int r=1;
 if(p==0)
  {
    return(1);
    }
 else
  {
    r=r*n;
    power(n,p-1);
    }
return(r);
}


