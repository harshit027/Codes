/*function converting temp unit :HARSHIT*/
#include"iostream.h"
#include"conio.h"
float convert(float f);
void main()
{
clrscr();
float f,c;
cout<<"\nenter temp in fer : ";
cin>>f;
c=convert(f);
cout<<"\ntemp in cel : "<<c;
getch();
}
float convert(float fer)
{
float cel;
cel=(fer-32)*5/9;
return cel;
}


