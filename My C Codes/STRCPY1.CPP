/*copy a string to other string :HARSHIT*/
#include"iostream.h"
#include"conio.h"
#include"stdio.h"
void main()
{
clrscr();
int i;
char str[20];
cout<<"\enter a string : ";
gets(str);
cout<<"\n u have entered : "<<str;
i=0;
while(str[i]!='\0')
i++;
cout<<"\n\ncopied string is : "<<str;
getche();
}
