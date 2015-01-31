#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
 int n,result;
 clrscr();
 printf("Enter the number");
 scanf("%d",&n);
 result=fact(n);
 printf("\n The factorial of %d is %d",n,result);
 getch();
 }
int fact(int x)
{
 int f;
 if(x==1)
  {
    return(x);
    }
 else
  {
    return(x*fact(x-1));
   }
}
