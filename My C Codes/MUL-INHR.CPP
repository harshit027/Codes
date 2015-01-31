/*demonstration of multiple inheritance :HARSHIT */

#include<iostream.h>
#include<conio.h>

class horse
{
public:
horse()
{
cout<<"\nhorse constructor :";
}
virtual ~horse()
{
cout<<"\nhorse destructor :";
}
virtual void gallop() const
{
cout<<"\ngallop() in 'horse' class";
cout<<"\ngallop......";
}
virtual void whinny() const
{
cout<<"\nwhinny() in 'horse' class ";
cout<<"\nwhinny......";
}
};

class bird
{
public:
bird()
{
cout<<"\nbird constructor :";
}
virtual ~bird()
{
cout<<"\nbird destructor :";
}
virtual  void fly() const
{
cout<<"\nfly in 'bird' class ";
cout<<"\ni can fly ........";
}
virtual void chirp() const
{
cout<<"\nchirp() in 'bird' class";
cout<<"\nchirp.......";
}
};

class pegasus: public horse,public bird
{
public:
pegasus()
{
cout<<"\npegasus constructor :";
}
~pegasus()
{
cout<<"\npegasus destructor :";
}
void chirp() const
{
cout<<"\nchirp() in 'pegasus' class";
cout<<"\nchirp.....whinny.....";
}
void fly() const
{
cout<<"\nfly() in 'pegasus' class";
cout<<"\ngallop.....i can fly.....";
}

void whinny()  const
{
cout<<"\nwhinny in 'pegasus' class ";
cout<<"\nwhinny.......chirp.......";
}
void gallop() const
{
cout<<"\ngallop() in 'pegasus' class " ;
cout<<"\ngallop.......i can fly.....";
}
};

void main()
{
clrscr();
horse *p1horse,*p2horse;
bird *p1bird,*p2bird;
p1horse=new horse;
p1horse->whinny();
p1horse->gallop();
p2horse=new pegasus;
p2horse->gallop();
p2horse->whinny();
p1bird=new bird;
p1bird->fly();
p1bird->chirp();
p2bird=new pegasus;
p2bird->chirp();
p2bird->fly();
delete p1horse;
delete p2horse;
delete p1bird;
delete p2bird;

getch();
}
