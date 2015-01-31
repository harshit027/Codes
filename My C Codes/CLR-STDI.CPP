/*clearing the standard input stream : HARSHIT*/

#include"stdio.h"
#include"conio.h"
/*-----------------------------------------------------*/

void clear_stdin()
{
char junk[50];
gets(junk);
}
/*we can also use fflush(stdin) in place of clear_stdin() to clear the
input stream */
/*-------------------------------------------------------*/
void main()
{
clrscr();
int a;
char b[10];
puts("\nentre the age :");
scanf("%d",&a);
clear_stdin();
puts("\nentre the name :");
scanf("%s",b);
printf("\nthe age entered is %d",a);
printf("\nthe name  entered is %s",b);
getch();
}