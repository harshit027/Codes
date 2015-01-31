/*cin.get(char &,int offset),member function of cin:HARSHIT*/
//three parameters passed
//pointer,offset,termination character


#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
char s[40];
cout<<"\ncin.get(char &,int offset)";
cout<<"\nenter any string ('x' is the termination character):";
cin.get(s,40,'x');
cout<<"\nentered string is :"<<s;
getch();
}