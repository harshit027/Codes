/*strcmp function :HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"string.h"

void strcmp1(char s1[],char s2[])
{
int k=1;
if(strlen(s1)!=strlen(s2))
k=0;
for(int i=0;i<strlen(s1);i++)
{
if(s1[i]!=s2[i])
k=0;
}
if(k==1)
cout<<"\nthe strings are equal :";
else
cout<<"\nthe strings are not equal :";
}
void main()
{
clrscr();
char s1[10],s2[10];
cout<<"\nenter string s1 : ";
cin>>s1;
cout<<"\nenter string s2 : ";
cin>>s2;
strcmp1(s1,s2);
getch();
}
