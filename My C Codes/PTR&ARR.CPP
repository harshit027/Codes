/*name of array is the pointer to the first element's address : HARSHIT*/
#include"stdio.h"
#include"conio.h"
void main()
{
clrscr();
int a[10];
printf("\nthe adress of 1st element of array : %u",a);
printf("\n\nthe adress of first element of array : %u",&a[0]);
getch();
}