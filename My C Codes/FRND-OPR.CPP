/*friend operator overloading :HARSHIT*/


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
friend string operator+(const string&,const string&);
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
//cout<<"\ndefault constructor (string):";
}


//private constructor used by class methods for
//creating new array of required size
string::string (int len)
{
itsstring=new char[len+1];
for(int i=0;i<=len+1;i++)
itsstring[i]='\0';
itslen=len;
//cout<<"\nprivate string (int) constructor :";
}


//constructor converts an array into string
string::string(const char *const cstring)
{
itslen=strlen(cstring);
itsstring=new char[itslen+1];
for(int i=0;i<itslen;i++)
itsstring[i]=cstring[i];
itsstring[itslen]='\0';
//cout<<"\nstring(const char *const) constructor :";
}


//copy constructor
string::string(const string &rhs)
{
itslen=rhs.getlen();
itsstring=new char[itslen+1];
for(int i=0;i<itslen;i++)
itsstring[i]=rhs[i];
itsstring[itslen]='\0';
//cout<<"\nstring(const string&) cnstructor :";
}

//default destructor
string::~string()
{
delete [] itsstring;
itslen=0;
//cout<<"\ndefault destructor (string):";
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


//creates a new string by adding current string to rhs
string string::operator +(const string &rhs)
{
//cout<<"\noperator +(const string &)";
int totallen=itslen + rhs.getlen();
string temp(totallen);
for(int i=0;i<itslen;i++)
temp[i]=itsstring[i];
for(int j;j<rhs.getlen();j++,i++)
temp[i]=rhs[j];
temp[totallen]='\0';
return temp;
}


//creates a new string by adding one string to another
//friendly operator
string operator +(const string &lhs,const string &rhs)
{
int totallen=lhs.getlen()+rhs.getlen();
string temp(totallen);
for(int i=0;i<lhs.getlen();i++)
temp[i]=lhs[i];
for(int j=0;j<rhs.getlen();j++,i++)
temp[i]=rhs[j];
temp[totallen]='\0';
return temp;
}

void main()
{
clrscr();
string s1("string one ");
string s2("string two ");
char *c={"C string "};
string s3,s4,s5;

cout<<"\ns1 :"<<s1.getstring();
cout<<"\ns2 :"<<s2.getstring();
cout<<"\nc  :"<<c;
s3=s1+s2;
s4=c+s1;
s5=s1+c;
cout<<"\ns3 :"<<s3.getstring();
cout<<"\ns4 :"<<s4.getstring();
cout<<"\ns5 :"<<s5.getstring();
getch();
}