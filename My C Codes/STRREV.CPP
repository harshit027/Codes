/*use of strrev() function :HARSHIT */
#include"iostream.h"
#include"conio.h"
#include"string.h"
void main()
{
clrscr();
char source[25];
cout<<"\nenter a string : ";
cin>>source;
cout<<"\n u have entered:"<<source;
strrev(source);
cout<<"\n\nthe reverse of string is :"<<source;
getch();
}


