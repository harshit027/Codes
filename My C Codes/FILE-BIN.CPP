/*writing and reading in binary mode ,storing a class in the file :
HARSHIT*/

#include"fstream.h"
#include"conio.h"

class animal
{
public:
animal(int age,int wt):itsage(age),itswt(wt)
{};
~animal(){};
int getage() { return itsage; }
int getwt() { return itswt; }

void setage(int age) { itsage=age ;}
void setwt(int wt) {itswt=wt;}
private:
int itsage,itswt;
};

void main()
{
clrscr();
char filename[20];
char buffer[255];
cout<<"\nOpening the file for writing the class :";
cout<<"\nFilename : ";
cin>>filename;
ofstream fout(filename,ios::binary);
if(!fout)
{
cout<<"\nunable to open the file "<<filename<<" for writing ";
return;
}

animal bear1(10,5);      //two instances created
animal bear2(20,10);
fout.write((char*) &bear1,sizeof bear1);    //written in the file
fout.write((char*) &bear2,sizeof bear2);
fout.close();
cout<<"\n\nOpening the file for reading the class :";
cout<<"\nFilename : ";
cin>>filename;
ifstream fin(filename,ios::binary);
if(!fin)
{
cout<<"\nunable to open the file "<<filename<<" for reading ";
return;
}
cout<<"\nThe contents of file are :\n";
fin.read((char*) &bear1,sizeof bear1);            //reading from file
cout<<"\nbear1 weight = "<<bear1.getwt()<<" kgs";
cout<<"\nbear1 age    = "<<bear1.getage()<<" years ";
fin.read((char*) &bear2,sizeof bear2);
cout<<"\nbear2 weight = "<<bear2.getwt()<<" kgs";
cout<<"\nbear2 age    = "<<bear2.getage()<<" years ";
getch();
fin.close();
}
