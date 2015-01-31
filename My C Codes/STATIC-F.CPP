/*demonstration of static member functions :HARSHIT*/

#include"iostream.h"
#include"conio.h"

class cat
{
public:
cat(int age):itsage(age)
{
cout<<"\na cat created  :";
cat_num++;
}
~cat()
{
cout<<"\na cat deleted :";
cat_num--;
}
int getage()
{
return itsage;
}
void setage(int age)
{
itsage=age;
}
static int getcat_num()
{
return cat_num;
}
static int cat_num;

private:
int itsage;
};
int cat::cat_num=0;


void telepathic()/*access static member without object*/
{
cout<<"\nthere are "<<cat::getcat_num()<<" cats alive :";
}


void main()
{
clrscr();
cat *c1=new cat(2);
cat *c2=new cat(3);
cat *c3=new cat(4);
cat c4(5);
telepathic();
cout<<"\nthere are "<<cat::getcat_num()<<" cats in the house( access by class): ";
cout<<"\nage of c1 cat :"<<c1->getage();
cout<<"\nage of c2 cat :"<<c2->getage();
cout<<"\nage of c3 cat :"<<c3->getage();
cout<<"\nthere are "<<c4.getcat_num()<<" cats in the house (access by object):";
delete c1;
telepathic();
delete c2;
telepathic();
cout<<"\nnumber of cats left :"<<cat::getcat_num()<<" (access by external function) ";
getch();
}

