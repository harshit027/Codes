/*program for the pallendrom*/

#include"iostream.h"
#include"conio.h"
#include"string.h"
void main()
{
clrscr();
char string[20];
char a[20],b[20];
int k=1,i,j;

cout<<"\nenter the string : ";
cin>>string;

for(i=0;i<=strlen(string);i++)
b[i]=string[i];

strrev(string);

for(i=0;i<=strlen(string);i++)
a[i]=string[i];

for(i=0;i<=strlen(string);i++)
{
if(a[i]!=b[i])
k=0;
}

if(k==1)
cout<<"\n"<<b<<" is a pallendrom !";
else
cout<<"\n"<<b <<" is not a pallendrom !";

getch();
}