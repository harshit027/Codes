/*union of structures :HARSHIT */

#include"stdio.h"
#include"conio.h"

typedef struct employee
{
int id;
char name[20];
float salary;
}e;

typedef struct student
{
int rollno;
char name[20];
float avg;
}s;

typedef union person
{
e e1;
s s1;
}p;

void main()
{
clrscr();
p p1;
puts("\nenter the entries for student :\n");
puts("rollno :");
scanf("%d",&p1.s1.rollno);
puts("name :");
scanf("%s",p1.s1.name);
puts("average :");
scanf("%f",&p1.s1.avg);

puts("\nSTUDENT");
printf("\nrollno  : %d",p1.s1.rollno);
printf("\nname    : %s",p1.s1.name);
printf("\naverage : %f",p1.s1.avg);

puts("\n\nenter the entries for employee :\n");
puts("i-d :");
scanf("%d",&p1.e1.id);
puts("name :");
scanf("%s",p1.e1.name);
puts("salary :");
scanf("%f",&p1.e1.salary);

puts("\nEMPLOYEE");
printf("\nI D    : %d",p1.e1.id);
printf("\nname   : %s",p1.e1.name);
printf("\nsalary : %f",p1.e1.salary);
getch();
}

