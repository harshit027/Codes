/*cin.peek(), member function of cin :HARSHIT*/

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
char ch;
cout<<"\program looks for '#' and ignores it !";
cout<<"\nenter a phrase ('!' to exit) :";
while(cin.get(ch))
{
if(ch=='!')
return;
if(cin.peek()=='#')
cin.ignore(1,'#');
cout<<ch;
}
getch();
}