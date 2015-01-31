//external variable :HARSHIT

#include<stdio.h>
#include<conio.h>
void extfun();
int num;
void main()
{
  extern int num;
			//External variable declaration
  clrscr();
  num=10;
  printf("%d\n",num);
  getch();
  }
void extfun()
 {
   extern int num;                               //External variable declaration
   num = num + 50;
   printf("%d",num);
   } 
