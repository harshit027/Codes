/*void pointer example :HARSHIT*/

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
int a=10;
float b=5;
char c='a';
void *p;
p=&a;
cout<<a<<" "<<p;
p=&b;
cout<<"\n"<<b<<" "<<p;
p=&a;
cout<<"\n"<<c<<" "<<p;
getch();
}