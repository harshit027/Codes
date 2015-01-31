/*using member functions with and without parameters:HARSHIT*/
#include"iostream.h"
#include"conio.h"
class rect
{
private:
int itslength,itsbreadth;
public:
rect(int l,int b)
{
itslength=l;
itsbreadth=b;
}
~rect(){}
void draw()
{
draw(itslength,itsbreadth);
}
void draw(int l,int b)
{
int i,j;
for(i=0;i<l;i++)
{
for(j=0;j<b;j++)
cout<<"*";
cout<<"\n";
}}
};
void main()
{
clrscr();
rect r(10,2);
cout<<"\ndraw without parameters :\n";
r.draw();
cout<<"\ndraw with parameters :\n";
r.draw(5,4);
getch();
}
