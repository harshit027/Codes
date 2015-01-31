/*finds the sum of digits of 5 digit number :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
 long int a,b,c,i,d;
cout<<"\nenter a 5digit number : ";
cin>>a;
for(i=1;i<=5;i++)
{
b=a%10;
cout<<b;
d=a-b;
c=d/10;
a=c;
}
getch();
}




