/*demonstration of virtual function : HARSHIT*/

#include<iostream.h>
#include<conio.h>

class mammal
{
public:
mammal() {};
~mammal() {};
virtual void move () const
{
cout<<"\nmove() in base class";
cout<<"\nmammal move one step :";
}
virtual void speak() const
{
cout<<"\nspeak() in base class";
cout<<"\nmammal speaks :";
}
};
class dog :public mammal
{
public:
void move() const
{
cout<<"\nmove() in derived class ";
cout<<"\ndog moves 5 steps : ";
}
void speak() const
{
cout<<"\nspeak() in derived class ";
cout<<"\nwoof...woof...woof ";
}
};
void main()
{
clrscr();
//mammal *pdog=new dog;
//pdog->move();
//pdog->speak();
dog d1;
d1.move();
d1.speak();
getch();
}
