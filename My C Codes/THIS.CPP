/*use of this pointer :HARSHIT */
#include"iostream.h"
#include"conio.h"
class counter
{
private:
int itsval;
public:
counter(int val)
{
cout<<"\ncounter created:";
itsval=val;
}
~counter(){}
int get(){return  itsval;}
const counter & operator++()
{
++itsval;
return *this;
}
};
void main()
{
clrscr();
counter i(3);
cout<<"\ni="<<i.get();
++i;
cout<<"\ni="<<i.get();
counter a=++i;
cout<<"\na="<<a.get();
cout<<"\ni="<<i.get();
getch();
}


