/*program for calculating the leap year */

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
int b=1600;/*1600 AD was the first leap year according to the calendar*/
int a;

cout<<"\nenter the year (>1600):";
cin>>a;

if((a-b)%4==0)
cout<<"\n"<<a<<" is the leap year :";
else
cout<<"\n"<<a<<" is not the leap year :";
getch();
}