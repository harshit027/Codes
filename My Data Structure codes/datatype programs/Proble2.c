#include<stdio.h>
#include<conio.h>
int fibnum(int);
void main()
{
 int p,num;
 clrscr();
 printf("Enter the position of element you want from fibonacci series");
 scanf("%d",&p);
 num=fibnum(p);
 printf("The required fibonacci number is%d",num);
 getch();
 }
int fibnum(int p)
{
 if(p==1||p==0)
  {
    return(p);
    }
 else
  {
    return(fibnum(p-1)+fibnum(p-2));
    }
}
