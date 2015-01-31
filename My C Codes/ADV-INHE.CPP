/*shows the container and containing class :HARSHIT*/

#include"iostream.h"
#include"conio.h"
#include"string.h"

class string
{
public:
//constructors for string
string();
string(const char *const);
string(const string&);
~string();

//overloaded operators
char& operator [](int offset);
char operator [](int offset) const;
string operator +(const string&);
void operator +=(const string &);
string& operator =(const string&);
//general accesors
int getlen() const
{
return itslen ;
}
const char * getstring() const
{
return itsstring;
}

private:
string(int);
char *itsstring;
unsigned short itslen;
};

//default constructor creates a string of zero length
string::string()
{
itsstring=new char[1];
itsstring[0]='\0';
itslen=0;
cout<<"\ndefault constructor (string):";
}
//private constructor used by class methods for
//creating new array of required size
string::string (int len)
{
itsstring=new char[len+1];
for(int i=0;i<=len+1;i++)
itsstring[i]='\0';
itslen=len;
cout<<"\nprivate string (int) constructor :";
}
//constructor converts an array into string
string::string(const char *const cstring)
{
itslen=strlen(cstring);
itsstring=new char[itslen+1];
for(int i=0;i<itslen;i++)
itsstring[i]=cstring[i];
itsstring[itslen]='\0';
cout<<"\nstring(const char *const) constructor :";
}

//copy constructor

string::string(const string &rhs)
{
itslen=rhs.getlen();
itsstring=new char[itslen+1];
for(int i=0;i<itslen;i++)
itsstring[i]=rhs[i];
itsstring[itslen]='\0';
cout<<"\nstring(const string&) cnstructor :";
}
//default destructor
string::~string()
{
delete [] itsstring;
itslen=0;
cout<<"\ndefault destructor (string):";
}

//non const offset operator,returns refrence to the
//character so that it can be changed

char & string::operator[](int offset)
{
//cout<<"\noperator [] (int) ";
if(offset>itslen)
return itsstring[itslen-1];
else
return itsstring[offset];
}
//returns refrence to const objects ( i.e copy constructors)

char string::operator [](int offset) const
{
//cout<<"\noperator [] (int) const ";
if(offset>itslen)
return itsstring[itslen-1];
else
return itsstring[offset];
}

//frees the existing memory , and copies the string

string & string::operator =(const string &rhs)
{
//cout<<"\noperator =(const string &)";
if(this==&rhs)
return *this;
delete [] itsstring;
itslen=rhs.getlen();
itsstring =new char[itslen+1];
for(int i=0;i<itslen;i++)
itsstring[i]=rhs[i];
itsstring[itslen]='\0';
return *this;
}

//creates a new string by adding a string to rhs
string string::operator +(const string &rhs)
{
//cout<<"\noperator +(const string &)";
int totallen=itslen+rhs.getlen();
string temp(totallen);
for(int i=0;i<itslen;i++)
temp[i]=itsstring[i];
for(int j;j<rhs.getlen();i++,j++)
temp[i]=rhs[j];
temp[totallen]='\0';
return temp;
}

//simply changes the current string
void string::operator +=(const string &rhs)
{
//cout<<"\noperator +=(const string&)";
int totallen=itslen +rhs.getlen();
string temp(totallen);
for(int i=0;i<itslen;i++)
temp[i]=itsstring[i];
for(int j=0;j<rhs.getlen();i++,j++)
temp[j]=rhs[i-itslen];
temp[totallen]='\0';
*this=temp;
}

/*----------------------------------------------------------------------*/

class employee
{
public:
//constructors
employee();
employee(char*,char*,char*,int);
~employee();
employee(const employee&);

//overloaded operator
employee & operator =(const employee &);

//accesors  get()

string getfname() const
{
return itsfirstname;
}
string getlname() const
{
return itslastname;
}
string getaddress() const
{
return itsaddress;
}
int getsalary() const
{
return itssal;
}
//accesors set()

void setfname(const string &fname)
{
itsfirstname=fname;
}
void setlname(const string &lname)
{
itslastname=lname;
}
void setaddress(const string &address)
{
itsaddress=address;
}
void setsalary(int sal)
{
itssal=sal;
}
private:
string itsfirstname;
string itslastname;
string itsaddress;
int itssal;
};

employee:: employee() :
itsfirstname(""),
itslastname(""),
itsaddress(""),
itssal(0)
{
cout<<"\ndefault constructor (employee):";
}

employee::employee(char*firstname,char*lastname,char*address,int sal):
itsfirstname(firstname),
itslastname(lastname),
itsaddress(address),
itssal(sal)
{
cout<<"\ninitialized constructor (employee):";
}

employee::employee(const employee &rhs):
itsfirstname(rhs.getfname()),
itslastname(rhs.getlname()),
itsaddress(rhs.getaddress()),
itssal(rhs.getsalary())
{
cout<<"\ncopy constructor(employee):";
}
employee::~employee()
{
cout<<"\ndefault destructor (employee):";
}

employee &employee:: operator =(const employee &rhs)
{
if(this==&rhs)
{
return *this;
}
//cout<<"\noperator = (const employee &)";
itsfirstname=rhs.getfname();
itslastname=rhs.getlname();
itsaddress=rhs.getaddress();
itssal=rhs.getsalary();

return *this;
}
/*-------------------------------------------------------------------*/
void main()
{
clrscr();
employee *e1=new employee;
cout<<"\ncreating e1 .....\n";
e1->setfname("john");
e1->setlname("players");
e1->setaddress("1123 Parkstreet Newyork");
e1->setsalary(500);
cout<<"\nfirst name   : "<<e1->getfname().getstring();
cout<<"\nlast name    : "<<e1->getlname().getstring();
cout<<"\naddress      : " <<e1->getaddress().getstring();
cout<<"\nsalary       : "<<e1->getsalary();
delete e1;
getch();
}
