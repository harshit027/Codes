//static variable :HARSHIT

#include<stdio.h>
#include<conio.h>
void example();
void main()
{
  int i;
  clrscr();
  for(i=0;i<=3;i++)
  {
     example();
     }
  getch();
}
void example()
 {
   static int x = 10;                          //local static variable
   x = x + 10;
   printf("%d",x);
   }
