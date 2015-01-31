//achieved polymorphism using fun pointer and void pointer:HARSHIT

#include"stdio.h"
#include"conio.h"

void use_int(void *);
void use_float(void *);
void get_func(void (*)(void *),void*);

void main()
{
clrscr();
int i=20;
float f=20.5;
char ch;
void *p;
puts("\nPrint in float(f) or integer(i) :");
scanf("%c",&ch);
if(ch=='i')
{
p=&i;
get_func(use_int,p);
}
else
{
p=&f;
get_func(use_float,p);
}
getch();
}

void use_int(void *p)
{
int a;
a=*(int*)p;
printf("\nThe value of integer is %d",a);
}

void use_float(void *p)
{
float *b;
b=(float*)p;
printf("\nThe value of float number is %f",*b);
}

void get_func(void (*f)(void*),void*p)
{
f(p);
}