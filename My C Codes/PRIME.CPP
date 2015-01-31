/*program for prime numbers*/

#include"iostream.h"
#include"conio.h"
#include"process.h"

void main()
{
clrscr();
int a,k=0,i;
cout<<"\nenter the number :";
cin>>a;

if(a==2)
k=0;

else
{
for(i=2;i<a;i++)
{
if(a%i==0)
k=1;
}
}
if(k==1)
cout<<"\n"<<a<<" is not a prime number !";
else
cout<<"\n"<<a<<" is a prime number !";
getch();
}
