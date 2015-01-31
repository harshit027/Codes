/*use of strcpy() function :HARSHIT*/
#include"iostream.h"
#include"conio.h"
#include"string.h"
void main()
{
clrscr();
char string[20],target[20];
cout<<"\nenter a string : ";
cin>>string;
cout<<"\nu have entered : "<<string;
strcpy(target,string);
cout<<"\n\ncopied string is : "<<target;
getch();
}