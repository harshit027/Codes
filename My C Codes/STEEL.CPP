/*use of if-else statement :HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int h,t;
float c;
cout<<"\nenter hardness,carbon content and tensile strength of steel = ";
cin>>h>>c>>t;
cout<<"hardness:"<<h<<" carbon content:"<<c<<" tensile strength:"<<t;
if(h>50&&c<0.7&&t>5600)
cout<<"\ngrade of steel : 10";
else
{
if(h>50&&c<0.7)
cout<<"\ngrade of steel : 9";
else
{
if(c<0.7&&t>5600)
cout<<"\ngrade of steel : 8";
else
{
if(h>50&&t>5600)
cout<<"\ngrade of steel : 7";
else
{
if(h>50||c<0.7||t>5600)
cout<<"\ngrade of steel : 6";
else
cout<<"\ngrade of steel : 5";
}}}}
getch();
}


