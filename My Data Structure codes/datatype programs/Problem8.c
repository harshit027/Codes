#include<stdio.h>
#include<conio.h>
int recgcd(int, int);
void main()
{
int a,b,gcd;
clrscr();
printf("Enter two numbers");
scanf("%d%d",&a,&b);
gcd=recgcd(a,b);
printf("G.C.D of %d and %d is = %d",a,b,gcd);
getch();
}
int recgcd(int x, int y)
{
 int r;
 if(y==0)
  {
    return(x);
    }
 else
  {
   r=x%y;
   return(recgcd(y,r));
   }
}
