#include"stdio.h"
#include"conio.h"
#include"string.h"

void main()
{
char *str1,*str2,*str3;
str1="India is my";
str2="11yrtnuoc";
str3="Gujarat";
strncat(str1,strrev(str2),strlen(str3));
puts(str1);
getch();
}