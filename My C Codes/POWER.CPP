/*function calulates power :HARSHIT*/
#include"iostream.h"
#include"conio.h"
int power(int x,int y)
{
int z=1,i;
for(i=1;i<=y;i++)
z=z*x;
return z;
}
void main()
{
clrscr();
int a,b,c=1;
cout<<"\n\n enter the number & power : ";
cin>>a>>b;
cout<<"\nnumber : "<<a<<" power : "<<b;
c=power(a,b);
cout<<"\n\n answer : "<<c;
getch();
}



