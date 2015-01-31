/*demonstrates operator overloading: HARSHIT */
#include"iostream.h"
#include"conio.h"
class counter
{
private:
int itsval;
public:
counter()
{
cout<<"\ncounter created : ";
}
~counter() {}
void set(int val){itsval=val;}
int get() const {return itsval;}
void operator ++() {++itsval;}
};
void main()
{
clrscr();
counter i;
i.set(9);
cout<<"\ni = "<<i.get();
++i;
cout <<"\ni = "<<i.get();
getch();
}


