#include<stdio.h>
#include<conio.h>
int prime(int);
void main()
{
 int n,f=0;
 clrscr();
 printf("\nEnter the number");
 scanf("%d",&n);
 if(n==2)
  {
   printf("The number is prime");
   }
 else if(n<2)
  {
   printf("The smallest prime number is 2");
   }
 else
  {
   f=prime(n);
   if(f)
    {
     printf("Number is prime");
     }
   else
    printf("Not prime");
   }
getch();
 }

int prime(int a)
{
 static int d=2,flag=1;
 if(d==a)
  {
     return(0);
    }
 else
  {
    if(a%d==0)
      {
	flag=0;
	d++;
	}
    else
     {
      d++;
      flag=1;
      prime(a);
      }
   }
return(flag);
}



