#include<stdio.h>
#include<conio.h>
void pseries(int);
void main()
{
 int limit;
 clrscr();
 printf("\nEnter the number");
 scanf("%d",&limit);
 printf("\n 2");
 pseries(limit-1);
 getch();
 }

void pseries(int a)
{
 static int n=3;
 int i,flag=0;
 if(a==0)
  {
    printf("\nThe series ends here");
    }
 else
  {
    for(i=2;i<=n-1;i++)
     {
       if(n%i!=0)
	 {
	   flag=1;
	   }
	else
	{
	  flag=0;
	  break;
	  }
	}
     if(flag)
      {
       printf("\n %d",n);
       n++;
       pseries(a-1);
       }
     else
      {
       n++;
       pseries(a);
       }
 }
}




