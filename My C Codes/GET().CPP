/*cin.get() , the member function of 'cin' object: HARSHIT */
//using with no parameter

#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
char ch;
cout<<"\nPress ctrl+z to reach end of file !\n";
cout<<"\nEnter any string :\n";
while((ch=cin.get())!=EOF)
{
cout<<"ch :"<<ch<<endl;
}
cout<<"\nDone !\n";
getch();
}