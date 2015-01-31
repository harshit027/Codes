/*objects on a free store :HARSHIT*/
#include"iostream.h"
#include"conio.h"
class cat
{
public:
int getage() const{return itsage;}
void setage(int age){itsage=age;}
cat()
{
cout<<"\nconstructor called :\n";
itsage=4;
}
~cat()
{
cout<<"\ndestructor called :\n";
}
private:
int itsage;
};
void main()
{
clrscr();
cat *frisky=new cat;
cout<<"\ncat frisky formed:\n ";
cout<<"\nfrisky is"<<frisky->getage()<<" years old\n";
cat *rags=new cat;
cout<<"\nanother cat rags formed:\n ";
cout<<"\nrags is"<<rags->getage()<<" years old\n";
cout<<"\nnew age is set for rags and frisky :\n";
frisky->setage(5);
rags->setage(7);
cout<<"\nfrisky is now "<<frisky->getage()<<" years old\n";
cout<<"\nrags is now "<<rags->getage()<<" years old\n";
delete rags;
delete frisky;
cout<<"\n rags and frisky are deleted :\n";
rags=0;
frisky=0;
getch();
}


