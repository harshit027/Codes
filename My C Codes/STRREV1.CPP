#include"iostream.h"
#include"conio.h"
#include"string.h"


void main()
{
clrscr();
char s1[20],s2[20];
cout<<"\nenter the string s1 :";
cin>>s1;
for(int i=0,j=strlen(s1)-1;s1[i]!='\0';i++,j--)
s2[j]=s1[i];
cout<<"\nthe reversed string is "<<s2;
getch();
}