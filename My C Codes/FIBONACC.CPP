/*fuction calculates the fibonacci series :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
int a,b,c,i,n;
cout<<"\nenter";
cin>>n;
a=0;
b=1;
for(i=1;i<=n;i++)
{
c=a+b;
cout<<c<<"\n";
a=b;
b=c;
}
getch();
}
