/*passing a pointer to a function as an arg to a function:HARSHIT */

#include"iostream.h"
#include"conio.h"


/*------------------------------------------------------------------*/
typedef void (*FP)();
void one (FP p)
{
cout<<"\none ()";
cout<<"\ntwo() is passed in one() as function pointer (using typedef)";
p();
}
void two()
{
cout<<"\ntwo ()";
}
void using_typedef()
{
FP p;
p=two;
one(p);
}

/*--------------------------------------------------------------------*/

void fname(void (*p)())
{
cout<<"\nfirst name= harshit ";
cout<<"\nlname() passed in fname() s function pointer ";
p();
}
void lname()
{
cout<<"\nlast name= tiwari ";
}

void using_traditional()
{
void (*p)();
p=lname;
fname(p);
}
/*-------------------------------------------------------------------*/
void main()
{
clrscr();
using_typedef();
getch();
}