/*demonstration of abstract data types :HARSHIT */

#include"iostream.h"
#include"conio.h"


class shape
{
public:
shape(){cout<<"\nshape constructor :";}
~shape(){cout<<"\nshape destructor :";}
virtual int get_area(){return -1;}
virtual int get_pmt(){return -1;}
private:

};

class circle : public shape
{
public:
circle(int radius):itsradius(radius)
{
cout<<"\ncircle constructor :";
}
~circle()
{
cout<<"\ncircle destructor :";
}
int get_area()
{
return 3*itsradius*itsradius;
}
int get_pmt()
{
return 2*3*itsradius;
}
int getradius()
{
return itsradius;
}
void setradius(int radius)
{
itsradius=radius;
}
private:
int itsradius;
};
void main()

{
clrscr();
shape *sp=new circle(5);
cout<<"\nthe area of the circle :"<<sp->get_area();
cout<<"\nthe perimeter of the circle :"<<sp->get_pmt();
delete sp;
getch();
}

