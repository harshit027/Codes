/*wrapping around of the datatype values:HARSHIT*/

#include"iostream.h"
#include"conio.h"
typedef unsigned short int USHORT;
void main()
{
clrscr();
USHORT a;
a=65535;
cout<<"a = "<<a<<"\n";
a++;
cout<<"a++ = "<<a<<"\n";
a++;
cout<<"a++ = "<<a<<"\n";
getch();
}


