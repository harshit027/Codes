//accessing elements by pointers:HARSHIT

#include<stdio.h>
#include<conio.h>
main()
{
int *ptr1,i,a[]={10,20,30,40,50,60};
clrscr();
i=0;
ptr1 = &a[0];
while(i<=5)
{
printf("ADDRESS = %u",ptr1);
printf("\tELEMENT = %d\n",*ptr1);
i++;
ptr1++;
}
getch();
}