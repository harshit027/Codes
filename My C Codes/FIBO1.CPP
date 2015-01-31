/*finds the count of fibonacci number :HARSHIT */
#include"iostream.h"
#include"conio.h"
int fib(int n);
void main()
{
int n,ans;
cout<<"\nenter a number : ";
cin>>n;
ans=fib(n);
cout<<ans<<"is the "<<n<<"th fib number";
getch();
clrscr();
}
int fib(int n)
{
if(n<3)
return (1);
else
return(fib(n-2)+fib(n-1));
}



