/*copy constructor :HARSHIT*/

#include"iostream.h"
#include"conio.h"

class cat
{
private:
int *itsage;
public:
cat()
{
itsage=new int;
*itsage=5;
}
cat(const cat &rhs)
{
itsage=new int;
*itsage=rhs.getage();
}
~cat()
{
delete itsage;
itsage=0;
}
void setage(int age){*itsage=age;}
int getage() const {return *itsage;}
};
void main()
{
clrscr();
cat frisky;
cout<<"\nfrisky age is : "<<frisky.getage();
frisky.setage(6);
cout<<"\nfrisky is set to: "<<frisky.getage();
cat boots(frisky);
cout<<"\na new cat 'boots' is created by 'frisky :";
cout<<"\nboots age is: "<<boots.getage();
frisky.setage(7);
cout<<"\nfrisky is now : "<<frisky.getage();
getch();
}


