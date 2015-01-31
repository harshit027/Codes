/*showing the containment by delegation or reproducing interface
between two classes :HARSHIT */


#include"iostream.h"
#include"conio.h"

//ADT for car and airpalne
class part
{
public:
part():itspartno(1) {}
part(int partno):itspartno(partno) {}
virtual  ~part(){}
int getpartno() const
{
return itspartno;
}
virtual void display() const=0;
private:
int itspartno;
};
void part::display()const
{
cout<<"\nPart number = "<<itspartno;
};
//--------------car--------------
class car :public part
{
public:
car():itsmodelyr(94){}
car(int modelyr,int partno);
virtual void display() const
{
part::display();
cout<<"\nmodelyear = "<<itsmodelyr;
}
private:
int itsmodelyr;
};

car::car(int modelyr,int partno):
itsmodelyr(modelyr),
part(partno)
{}
//-------------airplane-------------
class airplane :public part
{
public:
airplane():itsengineno(1){};
airplane(int engineno,int partno);
virtual void display() const
{
part::display();
cout<<"\nEngine number = "<<itsengineno;
}
private:
int itsengineno;
};
airplane::airplane(int engineno,int partno):
itsengineno(engineno),
part(partno)
{}

//----------------partnode----------------
class partnode
{
public:
partnode(part *);
~partnode();
void setnext(partnode* node)
{
itsnext=node;
}
partnode* getnext()const;
part*getpart()const;

private:
partnode *itsnext;
part *itspart;
};

partnode::partnode(part *ppart):
itspart(ppart),
itsnext(0)
{}

partnode::~partnode()
{
delete itsnext;
itsnext=0;
delete itspart;
itspart=0;
}
partnode * partnode::getnext() const
{
return itsnext;
}

part * partnode::getpart() const
{
if(itspart)
return itspart;
else
return NULL;
}

//--------------partlist---------------
class partlist
{
public:
partlist();
~partlist();
void iterate(void (part::*f)()const)const;
part* find(int &position,int partno) const;
part* getfirst()const;
void insert(part*);
part* operator[](int) const;
int getcount() const
{
return itscount;
}

static partlist& getglobalpartlist()
{
return globalpartlist;
}
private:
partnode *phead;
int itscount;
static partlist globalpartlist;
};

partlist partlist ::globalpartlist;

partlist::partlist():
phead(0),
itscount(0)
{}

partlist::~partlist()
{
delete phead;
phead=0;
}

void partlist::iterate(void (part::*func)()const)const
{
if(!phead)
return;
partnode *pnode=phead;
do
(pnode->getpart()->*func)();
while(pnode==pnode->getnext());
}

part* partlist::find(int &position,int partno) const
{
partnode *pnode;
for(pnode=phead,position=0;pnode!=NULL;pnode=pnode->getnext(),position++)
{
if(pnode->getpart()->getpartno()==partno)
break;
}
if(pnode==NULL)
return NULL;
else
return pnode->getpart();
}

part* partlist::getfirst()const
{
if(phead)
return phead->getpart();
else
return NULL;
}

void partlist::insert(part *ppart)
{
partnode *pnode=new partnode(ppart);
partnode *pcurrent=phead;
partnode *pnext=0;

int New=pnode->getpart()->getpartno();
int next=0;
itscount++;

//if there is no part in the list
if(!phead)
{
phead=pnode;
return ;
}

//if this part is smaller than the head then this one is the new head
if(phead->getpart()->getpartno() > New)
{
pnode->setnext(phead);
phead=pnode;
return;
}

for(;;)
{
//if there is no end part,then append this new one
if(!pcurrent->getnext())
{
pcurrent->setnext(pnode);
return;
}

//if it falls in between the two parts
pnext=pcurrent->getnext();
next=pnext->getpart()->getpartno();
if(next>New)
{
pcurrent->setnext(pnode);
pnode->setnext(pnext);
return;
}
pcurrent=pnext;
}
}

part* partlist::operator [] (int offset) const
{
partnode *pnode=phead;
if(!phead)
return NULL;
if(offset>itscount)
return NULL;
for(int i=0;i<offset;i++)
pnode=pnode->getnext();
return pnode->getpart();
}

//-------------------partscatalog--------------
class partscatalog
{
public:
void insert(part*);
int exists (int partno);
part*get(int partno);
operator +(const partscatalog&);
private:
partlist thepartlist;
};

void partscatalog::insert(part*newpart)
{
int partno=newpart->getpartno();
int offset;

if(!thepartlist.find(offset,partno))
thepartlist.insert(newpart);
else
{
cout<<"\n"<<partno<<" was the ";
switch(offset)
{
case 0:cout<<"first ";break;
case 1:cout<<"second ";break;
case 2:cout<<"third ";break;
default:cout<<offset+1<<"th";
}
cout<<" entry.Rejected";
}
}

int partscatalog:: exists(int partno)
{
int offset;
thepartlist.find(offset,partno);
return offset;
}
part* partscatalog::get(int partno)
{
int offset;
part *thepart=thepartlist.find(offset,partno);
return thepart;
}
//----------------main()------------------------
void main()
{
clrscr();
partscatalog pc;
part *p=0;
int value,choice,partnumber;

while(1)
{
cout<<"\n0:quit  1:car  2:airplane :";
cin>>choice;
if(!choice)
break;

cout<<"\nenter the part number ?";
cin>>partnumber;
if(choice==1)
{
cout<<"\nenter the model year ?";
cin>>value;
p=new car(value,partnumber);
}
else
{
cout<<"\nenter the engine number ?";
cin>>value;
p=new airplane(value,partnumber);
}
pc.insert(p);
}
getch();
}