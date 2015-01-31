/*creates a class called bankaccount :HARSHIT*/
#include"iostream.h"
#include"conio.h"
class ba
{

private:
char username[20],toa[20];
int accno,bal,dep,widr;
public:
ba()
{
cout<<"\nconstructor called :";
}
~ba()
{
cout<<"\ndestructor called :";
}
void setname(char name[20])
{
int i;
cout<<"\nenter the name : ";
cin>>name;
for(i=0;i<20;i++)
username[i]=name[i];
}
void settoa(char acc[20])
{
int i;
cout<<"\nenter the type of account : ";
cin>>acc;
for(i=0;i<20;i++)
toa[i]=acc[i];
}
void setacno(int acno)
{
cout<<"\nenter account no. : ";
cin>>acno;
accno=acno;
}
int getacno() const {return accno;}
void setbal(int sbal)
{
cout<<"\nenter initial balance : ";
cin>>sbal;
bal=sbal;
}
int getbal() const {return bal;}
void deposit(int d)
{
cout<<"\nenter the amount to be deposited : ";
cin>>d;
dep=d;
}
int getdep() const{return dep;}
void withdraw(int w)
{
cout<<"\nenter the amount to be withdrawl : ";
cin>>w;
widr=w;
}
int getwidr() const{return widr;}
int display()
{
return bal+dep-widr;
}
};
void main()
{
int a=0,s=0,d=0,w=0,b=0;
char n[20],t[20];
clrscr();
ba newacc;
newacc.setacno(a);
newacc.setbal(s);
newacc.setname(n);
newacc.settoa(t);
newacc.deposit(d);
newacc.withdraw(w);
cout<<"\n\ncustomer personnels : \n\n\n";
cout<<"\nname of customer :"<<n<<"\n";
cout<<"\ntype of account :"<<t<<"\n";
cout<<"\naccount number :"<<newacc.getacno()<<"\n";
cout<<"\ninitial balance :"<<newacc.getbal()<<"\n";
cout<<"\ndeposited amount : "<<newacc.getdep()<<"\n";
cout<<"\nwithdrawl amount : "<<newacc.getwidr()<<"\n";
cout<<"\n\nafter transactions : \n\n";
cout<<"\nname of customer : "<<n<<"\n";
b=newacc.display();
cout<<"\nnet balance in the account = "<<b;
getch();
}




