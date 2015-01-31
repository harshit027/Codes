#include<stdio.h>
#include<conio.h>
void main()
{
static int c=5;
printf("c=%d\n",c--);
if(c)
main();
}
