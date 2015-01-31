/*use of malloc(),prints alphabets :HARSHIT*/
#include"stdio.h"
#include"conio.h"
#include"stdlib.h"
void main()
{
clrscr();
char *ptr,*p,i;
ptr=(char*)malloc(sizeof(char)*30);
p=ptr;
for(i=97;i<123;i++)
*p++=i;
*p='\0';
printf("\n%s\n",ptr);
puts(ptr);
getch();
}