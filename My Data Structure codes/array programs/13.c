//string initializtion and accessing :HARSHIT

#include<stdio.h>
#include<conio.h>
main()
{
char *ptr1[3];
clrscr();
ptr1[0]="Hello !";
ptr1[1]="How are ";
ptr1[2]="you";
printf("%s %s %s",ptr1[0],ptr1[1],ptr1[2]);
getch();
}