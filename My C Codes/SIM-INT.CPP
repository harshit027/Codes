/*code for simple interest*/

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
float si=0,p,r,t;
cout<<"\nenter the principle amount (rupees) : ";
cin>>p;
cout<<"\nenter the rate of interest (%age) : ";
cin>>r;
cout<<"\nenter the time period (years): ";
cin>>t;

si=(p*r*t)/100;
cout<<"\nsimple interest = "<<si;
getch();
}
