/*program for even or odd numbers */

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
int a;
cout<<"\nenter the number :";
cin>>a;
if(a%2==0)
cout<<"\nthe number "<<a<<" is even !";
else
cout<<"\nthe number "<<a<<" is odd !";
getch();
}