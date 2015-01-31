/*prints the fibonacci series :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int a,b,c,i,n;
cout<<"\nenter number of terms to be displayed in the series :";
cin>>n;
a=0;
b=1;
cout<<"\n"<<a<<"\n"<<b<<"\n";
for(i=1;i<=n-2;i++)
{
c=a+b;
cout<<c<<"\n";
a=b;
b=c;
}
getch();
}
