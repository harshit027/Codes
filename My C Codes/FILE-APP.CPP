/*appending at the end of file : HARSHIT*/

#include"fstream.h"
#include"conio.h"

void main()
{
clrscr();
char filename[20];
char buffer[255];

//file opened for reading
cout<<"\nOpening the file for reading ...";
cout<<"\nFilename : ";
cin>>filename;

ifstream fin(filename);

if(fin)   //file already exists
{
cout<<"\nCurrent file contents :\n";
char ch;
while(fin.get(ch))
cout<<ch;
}
fin.close();

//opening file for appending
cout<<"\nAppending in a file ...";
cout<<"\nFilename : ";
cin>>filename;
cout<<"\nOpening "<<filename<<" in append mode ...";
ofstream fout(filename,ios::app); //in append mode

if(!fout)
{
cout<<"\nUnable to open "<<filename<<" in append mode ...";
return;
}

cout<<"\nEnter the contents in the to be added in the file:\n";
cin.ignore(1,'\n');
cin.getline(buffer,255);
fout<<buffer;
fout.close();

//again opening the file
cout<<"\nReading from the file ...";
cout<<"\nFilename : ";
cin>>filename;
cout<<"\nOpening "<<filename<<" for reading ...";
fin.open(filename);
if(!fin)
{
cout<<"\nUnable to open "<<filename<<" for reading ....";
return ;
}
cout<<"\nThe contents of file are :\n";
char ch;
while(fin.get(ch))
cout<<ch;
fin.close();
getch();

}
