/*cin.getline(char*,int,char) ,member function of cin object :HARSHIT*/

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
char s1[20],s2[20];
cout<<"\nenter the string s1 (enter key is the termination char):";
cin.getline(s1,20);
cout<<"\nenter the string s2 :";
cin.getline(s2,20);
cout<<"\ns1 :"<<s1;
cout<<"\ns2 :"<<s2;
getch();
}
