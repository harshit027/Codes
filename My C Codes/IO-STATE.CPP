/*cout.setf(ios::flagnames) , member fun of cout:HARSHIT*/
//manipulators and stateflags


#include"iostream.h"
#include"iomanip.h"
#include"conio.h"

void main()
{
clrscr();
const int a=225;
cout<<"number "<<a<<endl;
cout<<"number "<<hex<<a<<endl;
cout.setf(ios::showbase);
cout<<"number "<<setw(10)<<hex<<a<<endl;
cout<<"number "<<setw(10)<<oct<<a<<endl;
cout<<"number ";
cout.width(10);
cout.setf(ios::internal);
cout<<hex<<a<<endl;
cout<<"number ";
cout.width(10);
cout.setf(ios::internal);
cout<<oct<<a<<endl;
cout.setf(ios::showpos);
cout<<"number "<<dec<<a<<endl;
getch();
}