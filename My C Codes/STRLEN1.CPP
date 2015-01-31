/finds the length of string :HARSHIT*/
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
i=0;
while(str[i]!='\0')
i++;
cout<<"\nthe length of string : "<<i;
getch();
}
