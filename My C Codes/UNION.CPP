/*union example :HARSHIT*/

#include"stdio.h"
#include"conio.h"

typedef union entry
{
int a;
char c;
float f;
}e;

void main()
{
clrscr();
e e1; //cannot initialize all the attributes
e1.a=2;
printf("integer : %d",e1.a);
e1.c='a';
printf("\ncharacter : %c",e1.c);
e1.f=3.75;
printf("\nfloat : %f",e1.f);
getch();
}