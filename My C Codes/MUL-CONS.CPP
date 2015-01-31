/*calling multiple constructors with parameters :HARSHIT */


#include"iostream.h"
#include"conio.h"

class horse
{
public :
horse(int height,int weight);
virtual ~horse()
{
cout<<"\nhorse destructor :";
}
virtual void whinny()  const
{
cout<<"\nwhinny.....";
}
virtual int getheight()  const
{
return itsheight;
}
virtual int getweight()   const
{
return itsweight;
}
protected:
int itsheight;
int itsweight;
};

horse::horse(int height,int weight):itsheight(height),itsweight(weight)
{
cout<<"\nhorse constructor :";
}
class bird
{
public:
bird(int feathers,int weight);
virtual ~bird()
{
cout<<"\nbird destructor :";
}
virtual void chirp()  const
{
cout<<"\nchirp...";
}
virtual int getfeathers()   const
{
return itsfeathers;
}
virtual int getweight() const
{
return itsweight;
}
protected:
int itsfeathers,itsweight;
};
bird::bird(int feathers,int weight):itsfeathers(feathers),itsweight(weight)
{
cout<<"\nbird constructor:";
}

class pegasus:public horse,public bird
{
public:
pegasus(int height,int weight,int feathers,int believers);
~pegasus()
{
cout<<"\npegasus destructor :";
}
int getbelievers() const
{
return itsbelievers;
}
protected:
int itsbelievers;
};
pegasus::pegasus(int height,int weight,int feathers,int believers):
horse(height,weight),
bird(feathers,weight),
itsbelievers(believers)
{
cout<<"\npegasus constructor :";
}

void main()
{
clrscr();
pegasus *peg=new pegasus(5,10,15,25);
cout<<"\nheight of pegasus   = "<<peg->getheight();
cout<<"\nweight of pegasus   = "<<peg->horse::getweight();
cout<<"\nfeathers pegasus    = "<<peg->getfeathers();
cout<<"\nbelievers of pegasus= "<<peg->getbelievers();
delete peg;
getch();
}





