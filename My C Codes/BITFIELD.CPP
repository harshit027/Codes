/*using the bitfields :HARSHIT*/

#include"iostream.h"
#include"string.h"
#include"conio.h"

enum STATUS{fulltime,parttime};
enum FOODPLAN{onemeal,allmeals,weekends,nomeals};

class student
{
public:
student():
mystatus(fulltime),
myfoodplan(nomeals)
{}

~student(){}
STATUS getstatus();
void setstatus(STATUS);
unsigned getplan()
{
return myfoodplan;
}

void setfoodplan(unsigned plan)
{
myfoodplan=plan;
}
private:

unsigned mystatus : 1;        //bit-fielding
unsigned myfoodplan :2;
};

STATUS student::getstatus()
{
if(mystatus)
return fulltime;
else
return parttime;
}

void student::setstatus(STATUS thestatus)
{
mystatus=thestatus;
}


void main()
{
clrscr();
student jim;
jim.setstatus(parttime);
jim.setfoodplan(allmeals);
if(jim.getstatus())
cout<<"\njim is parttime ";
else
cout<<"\njim is fulltime ";

cout<<"\njim is on the ";
char plan[20];
switch(jim.getplan())
{
case onemeal: strcpy(plan,"onemeal");
break;
case allmeals: strcpy(plan,"allmeals");
break;
case weekends:strcpy(plan,"weekends");
break;
case nomeals:strcpy(plan,"nomeals");
}
cout<<plan<<" foodplan";
getch();
}