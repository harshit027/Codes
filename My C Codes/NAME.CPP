/*prints the name you store in a string:HARSHIT*/
#include"iostream.h"
#include"conio.h"
void main()
{
clrscr();
int n,i;
char name[20][20];
cout<<"\n enter the number of names to be entered : ";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"\nenter the name of student : ";
cin>>name[i];
cout<<"\nname of student:"<<name[i];
}
getch();
}