/*finds the table of input number :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void table(int a)
{
int i;
cout<<"\nenter the number whose table is to be found out:";
cin>>a;
cout<<"\nthe table of "<< a <<":\n";
for(i=1;i<=10;i++)
{
cout<<"\n"<<a<<" * "<<i<<" = "<<a*i;
}
}
void main()
{
clrscr();
int x;
table(x);
getch();
}