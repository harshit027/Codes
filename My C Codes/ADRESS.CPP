/*finds the address of a variable : HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a=10;
int *p;
int **q;
p=&a;
q=&p;
cout<<"\naddress of a : "<<&a;
cout<<"\nvalue at a = "<<*p;
cout<<"\naddress of pointer to a = "<<&p;
cout<<"\nvalue at p (address of a) = "<<*q;
getch();
}

