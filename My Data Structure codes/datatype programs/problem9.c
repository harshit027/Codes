#include<stdio.h>
#include<conio.h>
#include<process.h>
int recbicoff(int, int);
void main()
{
int n,r,ncr;
clrscr();
printf("Enter values of n and r");
scanf("%d%d",&n,&r);
ncr=recbicoff(n,r);
printf("Binomial cofficient of %dc%d is = %d",n,r,ncr);
getch();
}
int recbicoff(int x, int y)
{
 if(y>x)
   {
     printf("The value of n can't be less than r");
     getch();
     exit(1);
     }
 if(y==0||y==x)    /* Terminating condition*/
  {
    return(1);
    }
 else
  {
   return(recbicoff(x-1,y-1)+recbicoff(x-1,y));
   }
}
