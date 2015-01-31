/*pass by value and pointer :HARSHIT */
#include"iostream.h"
#include"conio.h"
int add1(int*a,int*b)
{
return (*a+*b);
}
int add2(int a,int b)
{
return a+b;
}

void main()
{
clrscr();
int a,b;
cout<<"\nenter the values of a and b\n";
cin>>a>>b;
cout<<"\nsum (pass by pointers) = "<<add1(&a,&b);
cout<<"\nsum (pass by value) = "<<add2(a,b);
getch();
}
