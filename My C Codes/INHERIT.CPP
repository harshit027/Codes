/*inheritance shown by two classes :HARSHIT*/

#include"iostream.h"
#include"conio.h"


class mammal
{
public:
mammal() {cout<<"\nmammal created";}
~mammal() {cout<<"\nmammal deleted ";}
void setage()
{
int x;
cout<<"\nenter the age :";
cin>>x;
itsage=x;
}
int getage()
{
return itsage;
}
protected:
int itsage;
};
class dog : public mammal
{
public:
dog() {cout<<"\ndog created";}
~dog() {cout<<"\ndog deleted ";}
void setweight()
{
int wt;
cout<<"\nenter the weight :";
cin>>wt;
itswt=wt;
}
int getweight()
{
return itswt;
}
protected:
int itswt ;
};
void main()
{
clrscr();
dog pluto;
pluto.setage();
pluto.setweight();
cout<<"\nage of dog 'pluto' is (a fuction in the subclass) "<<pluto.getage();
cout<<"\nweight of dog 'pluto' is (a function in the basecalss) "<<pluto.getweight();
getch();
}

