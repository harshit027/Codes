/*demonstration of a structure : HARSHIT */
#include"stdio.h"
#include"conio.h"
typedef struct student
{
char name[10];
int age;
float weight;
}s;
void main()
{
clrscr();
s s1;
puts("\nenter the elements of structure : ");
puts("\nenter name : ");
scanf("%s",s1.name);
puts("\nenter age : ");
scanf("%d",&s1.age);
puts("\nenter weight : ");
scanf("%f",&s1.weight);
puts("\nthe elements of structure are : ");
printf("\nname of student : %s",s1.name);
printf("\nage of student : %d",s1.age);
printf("\nweight of student : %f",s1.weight);
getch();
}
