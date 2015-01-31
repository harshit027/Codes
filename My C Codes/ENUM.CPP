/*demonstration of `enum' data type :HARSHIT*/
#include<iostream.h>
#include<conio.h>

void main()
{
clrscr();
enum days  {sun,mon,tue,wed,thu,fri,sat};
days dayoff;
int x;
cout<<"\nwhat day would you like to off (0-6) :";
cin>>x;
dayoff=days(x);
if(dayoff==sun||dayoff==sat)
cout<<"\nyou are already off :";
else
cout<<"\ni will put it in a vacation day ";
getch();
}