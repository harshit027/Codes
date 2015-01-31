//operator overloading (+ and =):HARSHIT

#include"iostream.h"
#include"conio.h"
#include"string.h"

class strings
{
private:
char *s;

public:
strings(char*init)
{
s=init;
}
strings(){};
~strings(){};
void setString(char*);
char* getString();
strings operator+(strings&);
void operator=(strings&);
};

void strings::setString(char*a)
{
s=a;
}
char* strings::getString()
{
return s;
}

void strings::operator=(strings &sref)
{
strcpy(s,sref.getString());
}
strings strings::operator+(strings &sref)
{
strings temp;
char *a1,*a2;
strcpy(a1,s);
strcpy(a2,sref.getString());
temp=strcat(a1,a2);
return temp;
}


void main()
{
clrscr();
strings s1;
strings s2;
strings s3;
strings s4;
s1.setString("Harshit");
s2.setString("Tiwari");
s3=s1+s2;
cout<<"\ns1 = "<<s1.getString();
cout<<"\ns2 = "<<s2.getString();
cout<<"\ns3 (s1+s2) = "<<s3.getString();
s4=s3;
cout<<"\ns4 (=s3) = "<<s4.getString();
getch();
}