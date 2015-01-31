/*demonstration of pointer to a functions: HARSHIT*/
#include"stdio.h"
#include"conio.h"

int square(int x)
{
return x*x;
}

int (*p) (int x);
int (*q) (int x);
void main()
{
int x;
clrscr();
p=square;
q=p;
puts("\nenter a number to be squared :");
scanf("%d",&x);
puts("\n\nsquare() called :");
printf("\nthe square of the number is %d ", square(x));
puts("\n\npointer to square() called :");
printf("\nthe square of the number is %d ", p(x));
puts("\n\npointer to a pointer called :");
printf("\nthe square of the number is %d ",q(x));
getch();
}