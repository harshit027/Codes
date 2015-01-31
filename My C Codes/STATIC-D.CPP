/*demonstration of static data member :HARSHIT*/

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
static int cat_num;
private:
int itsage;
};
int cat::cat_num=0;


void telepathic()/*access static member without object*/
{
cout<<"\nthere are "<<cat::cat_num<<" cats alive :";
}


void main()
{
clrscr();
cat *c1=new cat(2);
cat *c2=new cat(3);
cat *c3=new cat(4);
telepathic();
cout<<"\nthere are "<<cat::cat_num<<" cats in the house ";
cout<<"\nage of c1 cat :"<<c1->getage();
cout<<"\nage of c2 cat :"<<c2->getage();
cout<<"\nage of c3 cat :"<<c3->getage();
delete c1;
telepathic();
delete c2;
telepathic();
cout<<"\nnumber of cats left :"<<cat::cat_num;
getch();
}

