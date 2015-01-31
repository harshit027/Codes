/*demonstration of 'goto' statement:HARSHIT */
#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int i=0;
loop:
i++;
cout<<"\n "<<i;
if(i<5)
goto loop;
cout<<"\ncount completed !";
getch();
}