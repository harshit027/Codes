/*use of strcat() function :HARSHIT*/
#include "iostream.h"
#include"conio.h"
#include"string.h"
void main()
{
clrscr();
char name1[10],name2[10];
cout<<"\nenter the name1 : ";
cin>>name1;
cout<<"\nenter the name2 : ";
cin>>name2;
cout<<"\n u have entered stirngs: "<<name1<<" and "<<name2;
strcat(name1,name2);
cout<<"\n\nconcatanated string is : "<<name1;
getch();
}


