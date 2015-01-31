/*determines whether the character is small,capital or symbol:HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
char i;
cout<<"\nenter a character ! "<<"\n";
cin>>i;
if(i>=65&&i<=90)
cout<<"\ncharacter is a capital letter";
if(i>=97&&i<=122)
cout<<"\ncharacter is a small letter";
if(i>=48&&i<=57)
cout<<"\ncharacter is a number";
getch();
}


