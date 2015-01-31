#include"iostream.h"
#include"conio.h"

const int defaultsize=10;

class animal
{
public:
//cons & dest
animal();
animal(int);
~animal(){}

//accessors

int getwt() const
{
return itswt;
}
void display() const
{
cout<<itswt;
}
private:
int itswt;
};

animal::animal(int wt):
itswt(wt){}

animal::animal():
itswt(0){}

//------------------------------------------------------

template <class T>
class array
{
public:
//cons & dest

array(int itssize=defaultsize);
array(const array&rhs);
~array()
{
delete [] ptype;
}

//operators
array& operator=(const array&);

T& operator[] (int offset)
{
return ptype[offset];
}
const T& operator[] (int offset) const
{
return ptype[offset];
}

//accessors
int getsize() const
{
return itssize;
}

private:
T *ptype;
int itssize;
};


template <class T>
array<T>::array(int size=defaultsize):
itssize(size)
{
ptype=new T[size];
for(int i=0;i<size;i++)
ptype[i]=0;
}

//copy constructor
template <class T>
array<T>::array( const array & rhs)
{
itssize=rhs.getsize();
ptype=new T[itsize];
for(int i=0;i<itssize;i++)
ptype[i]=rhs[i];
}

//operator=
template <class T>
array<T>& array<T>:: operator=(const array &rhs)
{
if(this==&rhs)
return *this;
delete[] ptype;
itssize=rhs.getsize();
ptype=new T[itssize];
for(int i=0;i<itssize;i++)
ptype[i]=rhs[i];
return *this;
}

//driver program

void main()
{

clrscr();
array<int> thearray;
array<animal> thezoo;
animal *panimal;

for(int i=0;i<thearray.getsize();i++)
{
thearray[i]=i*2;
panimal=new animal((i*3));
thezoo[i]=*panimal;
delete panimal;
}

for(int j=0;j<thearray.getsize();j++)
{
cout<<"thearray["<<j<<"] ;\t";
cout<<thearray[j]"\t\t";
cout<<"thezoo["<<j<<"] :\t";
thezoo[j].display();
cout<<endl;
}

for(int k=0;k<thearray.getsize();k++)
delete &thezoo[k];

getch();

}
