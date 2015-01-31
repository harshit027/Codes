/*demonstrates using gets() return value :HARSHIT*/
#include"stdio.h"
#include"conio.h"
char string[20],*p;
void main()
{
clrscr();
puts("\nenter a string : ");
puts("\nenter a blank line when done :");
while(*(p=gets(string))!=NULL)
printf("\nyou entered %s\n",string);
puts("\nthanks!!!");
getch();
}