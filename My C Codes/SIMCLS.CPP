/*demonstrates a simple class:HARSHIT*/
#include"iostream.h"
#include"conio.h"
class cat
{
public:
meow();
int age;
float weight;
};
void meow()
{
cout<<"\n\nmeow____meow____meow";
}
void main()
{
clrscr();
cat frisky;
meow();
cout<<"\n\nenter the age & weight of frisky : ";
cin>>frisky.age>>frisky.weight;
meow();
cout<<"\n\n\nage of frisky is "<<frisky.age;
cout<<"\n\nweight of frisky is "<<frisky.weight;
meow();
getch();
}


