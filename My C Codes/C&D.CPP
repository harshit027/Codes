/*use of constructor and destructor :HARSHIT */
#include"iostream.h"
#include"conio.h"
class cat
{
public:
cat(int initialage);
~cat();
int getage();
void setage(int age);
void meow();
private:
int itsage;
};
cat::cat(int initialage)
{
cout<<"\cat (int) constructor:";
itsage=initialage;
}
cat::~cat()
{
cout<<"\ncat destructor :";
}
void cat::setage(int age)
{
cout<<"\nset the age of cat : ";
cin>>age;
itsage=age;
}
int cat::getage()
{
return itsage;
}
void cat::meow()
{
cout<<"\n meow \n";
}
void main()
{
int a;
clrscr();
cat*frisky=new cat(5);
frisky->meow();
cout<<"\nfrisky is "<<frisky->getage()<<"yrs old";
frisky->setage(a);
cout<<"\nit is now "<<frisky->getage()<<"yrs old";
frisky->meow();
delete frisky;
getch();
}




