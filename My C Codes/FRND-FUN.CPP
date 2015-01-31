/*friend function :HARSHIT */

#include"iostream.h"
#include"conio.h"

class a
{
public:
a(int num):itsnum(num){};
~a(){};
int getnum()
{
return itsnum;
}
void setnum(int num)
{
itsnum=num;
}
friend void hello();
private:
int itsnum;
};
void hello()
{
cout<<"\nhello !";
}


void main()
{
clrscr();
a a1(2);
cout<<"\na1 initialized by "<<a1.getnum();
a1.setnum(5);
cout<<"\nthe number a1 is set to "<<a1.getnum();
hello();
getch();
}