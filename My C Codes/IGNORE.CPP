/*cin.ignore(int,char),member function of cin:HARSHIT */

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
char s1[50],s2[50];
cout<<"\nenter the string s1 :";
cin.get(s1,50);
cout<<"\ns1 :"<<s1;
cout<<"\nenter the string s2 :";
cin.getline(s2,50);
cout<<"\ns2 :"<<s2;

cout<<"\nnow try again ! ";
cout<<"\nenter the string s1 :";
cin.get(s1,50);
cout<<"\ns1 :"<<s1;
cin.ignore(50,'\n');
cout<<"\nenter the string s2 :";
cin.getline(s2,50);
cout<<"\ns2 :"<<s2;
getch();
}