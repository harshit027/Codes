/*prints the prime numbers between two limits : HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"process.h"

void main()
{
clrscr();
int a,b,k=0,j,i;
cout<<"\nenter the limits :";
cin>>a>>b;
cout<<"\nthe prime numbers between "<<a<<" and "<<b<<" are...";
for(j=a;j<=b;j++)
{
k=0;
if(j==2)
k=0;

else
{
for(i=2;i<j;i++)
{
if(j%i==0)
k=1;
}
}
if(k==0)
cout<<"\n"<<j;
}
getch();
}
