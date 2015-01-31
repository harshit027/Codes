/*use of strlen() function :HARSHIT */
#include "iostream.h"
#include"conio.h"
#include"string.h"
void main()
{
clrscr();
int len=0;
char name[50];
cout<<"\nenter the name : ";
cin>>name;
cout<<"\n u have entered : "<<name;
len=strlen(name);
cout<<"\n\nlength of string="<<len;
getch();
}


