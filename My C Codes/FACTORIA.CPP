/*finds factorial of a number :HARSHIT*/
#include<iostream.h>
#include"conio.h"
void main()
{
clrscr();
long long int i,n,fact=1;
cout<<"\nenter the number whose factorial is to be found : ";
cin>>n;
for(i=1;i<=n;i++)
{
fact=fact*i;
}
cout<<"\nfactorial="<<fact;
getch();
}


