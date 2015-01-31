/*cin.putback(char),member function of cin:HARSHIT*/

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
char ch;
cout<<"\nthe program inserts '$' in place of '#' in the stream :";
cout<<"\nenter a phrase ('!' to exit the loop):\n";
while(cin.get(ch))
{
if(ch=='!')
return;
if(ch=='#')
cin.putback('$');
else
cout<<ch;
}
getch();
}