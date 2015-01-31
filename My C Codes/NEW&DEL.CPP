/*use of new and delete to store variable in afree store */
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a=5;
int *p1=&a;
int *p2=new int;
if(*p2==NULL)
{
cout<<"\nError !no memory in freestore";
}
*p2=7;
cout<<"\nlocal variable : "<<a;
cout<<"\nvalue at pointer p1 : "<<*p1;
cout<<"\nfreestore variable : "<<*p2;
delete p2;
p2=new int;
if(*p2==NULL)
{
cout<<"\nError !no memory in freestore";
}
*p2=9;
cout<<"\nfreestore variable : "<<*p2;
delete p2;
p2=0;
getch();
}



