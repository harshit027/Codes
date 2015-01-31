//memory spacing for array elements:HARSHIT

#include<stdio.h>
#include<conio.h>

void main()
{
int num[ ]={10,20,30,40,50,60},i;
clrscr();
i=0;
while(i<=5)
{
printf("ADDRESS = %u ",num[i]);
printf("ELEMENT = %d\n ",num[i]);
i++;
}
getch();
}