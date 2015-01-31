#include<stdio.h>
#include<conio.h>
void fseries(int);
void main()
{
 int limit,f0=1,f1=1;
 clrscr();
 printf("Enter the limit of fibonacci series");
 scanf("%d",&limit);
 if(limit>2)
  {
    printf("%d\n%d",f0,f1);
    fseries(limit-2);
    }
 else if(limit==2)
  {
   printf("\n %d \n %d",f0,f1);
   }
 else if(limit==1)
  printf("%d",f1);
 else
  printf("Series not posible");
 getch();
 }
void fseries(int p)
{
 int fib;
 static int f0=1,f1=1;
 if(p==0)
  {
    printf("\nThe series ends here");
    }
 else
  {
    fib=f0+f1;
    f0=f1;
    f1=fib;
    printf("\n%d",fib);
    fseries(p-1);
    }
}
