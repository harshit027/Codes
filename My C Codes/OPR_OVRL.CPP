/*operator overloading : HARSHIT*/

#include"iostream.h"
#include"conio.h"

/*overloading of a binary operator '+'*/
class counter
{
public:
counter ();
~counter (){};
counter(int initialval);
int getvalue()
{
return itsvalue;
}
void setvalue()
{
int x;
cout<<"\nenter the value (integer) for the object :";
cin>>x;
itsvalue=x;
}
counter operator + (counter &);
private :
int itsvalue;
};
counter ::counter(int initialval)
{
itsvalue=initialval;
}
counter::counter()
{
itsvalue=0;
}
counter counter::operator+(counter &rhs)
{
return counter(itsvalue + rhs.getvalue());
}

/*overaloading of a unary  operator '++' */
class increment
{
public:
increment()
{
cout<<"\nan object of class 'increment' is created : ";
}
~increment()
{
cout<<"\nobject is deleted :";
}
int getvalue()
{
return itsvalue;
}
void setvalue()
{
int x;
cout<<"\nenter the value (integer) for the object :";
cin>>x;
itsvalue=x;
}
void operator++()
{
++itsvalue;
}
private:
int itsvalue;
};
/*overloading assignment operator */
class cat
{
public:
cat(){};
~cat(){};
int getage()
{
return itsage;
}
void setage()
{
int x;
cout<<"\nenter the the age of cat :";
cin>>x;
itsage=x;
}
int getwt()
{
return itswt;
}
void setwt()
{
int x;
cout<<"\nenter the weight of the cat :";
cin>>x;
itswt=x;
}
void operator=(cat &);
private:
int itsage,itswt;
};
void cat::operator=(cat &rhs)
{
itsage=rhs.getage();
itswt=rhs.getwt();
}

void main()
{
clrscr();
cat frisky;
frisky.setage();
frisky.setwt();
cout<<"\nage of the cat 'frisky' is "<<frisky.getage();
cout<<"\nweight of the cat 'frisky' is "<<frisky.getwt();
cat bags;
bags=frisky;
cout<<"\na cat 'bags' is created of 'frisky' :";
cout<<"\nage of the cat 'bags' is "<<bags.getage();
cout<<"\nweight of the cat 'bags' is "<<bags.getwt();

getch();
}