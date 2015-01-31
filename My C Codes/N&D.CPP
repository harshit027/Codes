/*demonstrates the use of new and delete operator*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a=5;
int *p1=&a;
int *p2=new int;
*p2=7;
cout<<"\nlocal variable : "<<*p1;
cout<<"\nfreestore variable : "<<*p2;
delete p2;
*p2=9;
cout<<"\nfreestore variable : "<<*p2;
delete p2;
p2=0;
getch();
}



