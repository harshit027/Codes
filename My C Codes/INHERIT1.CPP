#include"iostream.h"
#include"conio.h"

class BaseString
{
private:
char *s;
public:
void setString(char *);
char * getString();
BaseString(char*);
BaseString(){};
};
BaseString::BaseString(char*init)
{
s=init;
}
void BaseString::setString(char*temp)
{
s=temp;
}
char* BaseString::getString()
{
return s;
}

class DerivedString :public BaseString
{
private:
char *s1;
public:
DerivedString(){};
};

void main()
{
clrscr();
DerivedString s;
s.setString("TestString");
cout<<s.getString();
getch();
}