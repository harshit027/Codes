#include "stdlib.h"
#include"stdio.h"
#include"conio.h"

void main(int argc,char* argv[])
{
clrscr();
int n;
if(argc!=2)
{
puts("\nInvalid arguments passed ,Try again ");
return;
}
n = atoi(argv[1]);
int i=n;
long int fact=1;
while(n>=1)
{
fact=fact*n--;
}
printf("Factorial %d = %ld",i,fact);
getch();
}