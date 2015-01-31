#include"iostream.h"
#include"conio.h"
#include"string.h"

void lesserThan(char a1)
{
if(a1=='=')
cout<<" LE ";
else if(a1=='>')
cout<<" NE ";
else
cout<<" LT ";
}

void greaterThan(char a1)
{
if(a1=='=')
cout<<" GE ";
else
cout<<" GT ";
}

void equalTo(char a1)
{
if(a1=='=')
cout<<" EQ ";
else return;
}

void number()
{
cout<<" NUM ";
}
void identifier()
{
cout<<" ID ";
}

void analyzer(char*a)
{
int length=strlen(a);
for(int i=0;i<length;i++)
{
if(a[i]=='<')
lesserThan(a[i+1]);
else if(a[i]=='>')
greaterThan(a[i+1]);
else if(a[i]=='=')
equalTo(a[i+1]);
else if(a[i]>=48&&a[i]<57)
number();
else
identifier();
}
}

void main()
{
clrscr();
char *a;
cout<<"Enter string : ";
cin>>a;
analyzer(a);
getch();
}
