/*opening a file using objects,and its handling :HARSHIT*/

#include"fstream.h"
#include"conio.h"

void main()
{
clrscr();

//writing in the file

char filename[40];  //for file name
char buffer[255];  //for the contents of the file
cout<<"\nFile opened for writing ....";
cout<<"\nFilename : ";
cin>>filename;
ofstream fout(filename);  //file opened for writing
fout<<"This text is written directly to the file ...\n";
cout<<"Enter the contents of the file :"<<endl;
cin.ignore(1,'\n');
cin.getline(buffer,255); //taken input from keyboard
fout<<buffer; //contents copied to the file
fout.close();  //closing the file


//reading from the file

cout<<"\n\nFile opened for reading :";
cout<<"\nFilename : ";
cin>>filename;
ifstream fin(filename);
cout<<"\nhere are the contents fo the file :"<<endl;
char ch;
while(fin.get(ch))
cout<<ch;
fin.close();
getch();
}