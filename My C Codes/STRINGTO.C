#include<string.h>
#include<conio.h>
#include<stdio.h>
int main()
{
 char str[10];
 int i;
 clrscr();
 printf("\nEnter the string : ");
 scanf("%s",&str);
 for(i=0;i<10;i++)
 printf("\n%s",str[i]);
 getch();
 return 0;
}